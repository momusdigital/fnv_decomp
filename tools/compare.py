#!/usr/bin/env python3
import re
"""Compare x86 COFF functions to the user's PE, including relocation targets.

Manifest: {"symbols": {"decorated": "0xaddress"}, "functions": [
 {"address": "0x004739b0", "symbol": "?name@@...", "size": 93,
  "fold_aliases": ["other decorated name"]}]}.
A folded alias may share a section/offset and original address; it never
licenses a call to a different original address. Reports may contain bytes
of your executable: keep them private and never commit them.
"""
import argparse
import json
import struct
from pathlib import Path
from function_spans import FunctionSpans, SIZE_BASIS


def number(value):
    return int(value, 0) if isinstance(value, str) else value


class Coff:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        machine, count, _, symptr, symcount, opts, _ = struct.unpack_from('<HHIIIHH', self.data)
        if machine != 0x14c or opts:
            raise ValueError('expected i386 COFF object, not an executable or bigobj')
        self.sections = [None]
        for i in range(count):
            row = struct.unpack_from('<8sIIIIIIHHI', self.data, 20 + i * 40)
            name, _, _, length, raw, relptr, _, relcount, _, flags = row
            if flags & 0x1000000:
                raise ValueError('extended COFF relocation counts are unsupported')
            self.sections.append(dict(name=name.rstrip(b'\0').decode(),
                data=bytes(length) if raw == 0 and flags & 0x80 else self.data[raw:raw + length], flags=flags,
                relocs=[struct.unpack_from('<IIH', self.data, relptr + n * 10)
                        for n in range(relcount)]))
        strptr = symptr + symcount * 18
        strlen, = struct.unpack_from('<I', self.data, strptr)
        strings = self.data[strptr:strptr + strlen]
        self.symbols = {}
        self.by_name = {}
        i = 0
        while i < symcount:
            rawname, value, section, typ, storage, aux = struct.unpack_from('<8sIhHBB', self.data, symptr + i * 18)
            if rawname[:4] == b'\0' * 4:
                offset, = struct.unpack_from('<I', rawname, 4)
                name = strings[offset:].split(b'\0', 1)[0].decode()
            else:
                name = rawname.rstrip(b'\0').decode()
            symbol = dict(name=name, value=value, section=section, type=typ, storage=storage)
            self.symbols[i] = symbol
            self.by_name.setdefault(name, []).append(symbol)
            i += 1 + aux

    def named(self, name):
        candidates = [s for s in self.by_name.get(name, []) if s['section'] > 0]
        if len(candidates) != 1:
            raise ValueError('expected one defined symbol: ' + name)
        return candidates[0]


class Pe:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        pe, = struct.unpack_from('<I', self.data, 0x3c)
        if self.data[pe:pe+4] != b'PE\0\0':
            raise ValueError('expected PE executable')
        machine, count, _, _, _, opts, _ = struct.unpack_from('<HHIIIHH', self.data, pe+4)
        if machine != 0x14c:
            raise ValueError('expected i386 executable')
        optional = pe + 24
        magic, = struct.unpack_from('<H', self.data, optional)
        if magic != 0x10b:
            raise ValueError('expected PE32')
        self.base, = struct.unpack_from('<I', self.data, optional+28)
        self.sections = []
        self.names = []
        for i in range(count):
            name, virtual_size, rva, raw_size, raw, _, _, _, _, _ = struct.unpack_from('<8sIIIIIIHHI', self.data, optional+opts+i*40)
            self.sections.append((rva, virtual_size, raw_size, raw))
            self.names.append(name.rstrip(b'\0').decode(errors='replace'))

    def tls_start(self):
        """Virtual address of the .tls section (the TLS template), or None."""
        for (rva, _, _, _), name in zip(self.sections, self.names):
            if name == '.tls':
                return self.base + rva
        return None

    def secrel(self, address):
        """Section-relative offset of a thread-local variable (IMAGE_REL_I386_SECREL). Only .tls targets are accepted:
        in code, SECREL appears only in thread-local accesses (mov reg, [tls block + SECREL(var)])."""
        start = self.tls_start()
        for (rva, virtual_size, _, _), name in zip(self.sections, self.names):
            if self.base + rva <= address < self.base + rva + max(virtual_size, 1):
                if name != '.tls':
                    raise ValueError('SECREL target is not thread-local (section %s)' % name)
                return address - start
        raise ValueError('SECREL target outside the image')

    def read(self, address, size):
        rva = address - self.base
        for start, _, rawsize, offset in self.sections:
            if start <= rva and rva + size <= start + rawsize:
                return self.data[offset+rva-start:offset+rva-start+size]
        raise ValueError('original range not backed by PE file bytes')


# Literals: floating-point constants (__real@, __xmm@: the name spells the bytes) and string literals (??_C@, $SG).
LITERAL = re.compile(r'^(\$SG\d+$|\?\?_C@|__real@[0-9a-f]+$|__xmm@[0-9a-f]+$)')
# RTTI type descriptors: a class written as a struct (or in another namespace) changes only their name
RTTI_NAME = re.compile(r'^\?\?_R0')


def own_data(coff, symbol):
    """(bytes, masked offsets) that the object gives a data symbol, or None when it gives none (code, an external,
    uninitialized data). A floating-point literal is the bytes its name spells; a string literal runs through its
    terminator; any other symbol runs to the next symbol in its section, without trailing zero bytes (alignment
    padding, or where the next object starts: the object does not say how long a variable is). Relocated fields are
    masked: they hold link-time addresses, not the unit's data."""
    name = symbol['name']
    if name.startswith(('__real@', '__xmm@')):
        return bytes.fromhex(name.split('@', 1)[1])[::-1], set()
    if symbol['section'] <= 0:
        return None
    sec = coff.sections[symbol['section']]
    if sec['flags'] & 0x20000020 or sec['flags'] & 0x80:   # code, or uninitialized data
        return None
    start = symbol['value']
    starts = coff.__dict__.setdefault('_starts', {})
    if symbol['section'] not in starts:
        starts[symbol['section']] = sorted({s['value'] for s in coff.symbols.values() if s['section'] == symbol['section']})
    later = [v for v in starts[symbol['section']] if v > start]
    end = later[0] if later else len(sec['data'])
    mask = {o - start + i for o, _, _ in sec['relocs'] if start <= o < end for i in range(4)}
    data = bytes(0 if i in mask else b for i, b in enumerate(sec['data'][start:end]))
    if LITERAL.match(name):   # a string: its characters and one terminator (two bytes for a wide ??_C@_1 literal)
        core = data.rstrip(b'\0')
        width = 2 if name.startswith('??_C@_1') else 1
        core += b'\0' * (len(core) % width)
        return core + b'\0' * width, set()
    data = data.rstrip(b'\0')
    return data, {i for i in mask if i < len(data)}


def data_differs(pe, own, at):
    """Bytes of `own` (from own_data) that the game does not hold at `at`; None when the range is not in the file."""
    data, mask = own
    try:
        original = pe.read(at, len(data))
    except ValueError:
        return None
    return [i for i in range(len(data)) if i not in mask and data[i] != original[i]]


def compare(coff, pe, manifest, spans=None):
    if spans is not None:
        for spec in manifest['functions']:
            canonical = spans.size(number(spec['address']))
            if number(spec['size']) != canonical:
                raise ValueError('Manifest span differs from canonical span at %s: %s vs %s' %
                                 (spec['address'], spec['size'], canonical))
    mappings = {k: number(v) for k, v in manifest.get('symbols', {}).items()}
    placements = {}
    functions = manifest['functions']
    for spec in functions:
        address = number(spec['address'])
        for name in [spec['symbol']] + spec.get('fold_aliases', []):
            if name in mappings and mappings[name] != address:
                raise ValueError('conflicting fold address for ' + name)
            mappings[name] = address
            symbol = coff.named(name)
            key = (symbol['section'], symbol['value'])
            if key in placements and placements[key] != (address, number(spec['size'])):
                raise ValueError('one object entry mapped to different original addresses')
            placements[key] = (address, number(spec['size']))

    def resolve(symbol, addend):
        if symbol['name'] in mappings:
            return mappings[symbol['name']] + addend
        if symbol['section'] > 0:
            # Section/local-label relocations resolve only inside a known
            # annotated function extent, never by unbounded nearest entry.
            point = symbol['value'] + addend
            candidates = [(value, address) for (section, value), (address, size) in placements.items()
                          if section == symbol['section'] and value <= point < value + size]
            if len(candidates) == 1:
                value, address = candidates[0]
                return address + point - value
        if symbol['section'] == -1:
            return symbol['value'] + addend
        raise ValueError('unresolved original symbol: ' + symbol['name'])

    reports = []
    for spec in functions:
        address, size = number(spec['address']), number(spec['size'])
        symbol = coff.named(spec['symbol'])
        section = coff.sections[symbol['section']]
        start = symbol['value']
        compiled = section['data'][start:start+size]
        original = pe.read(address, size)
        errors, relocation_reports, mask, warnings = [], [], set(), []
        # /Gy gives each function its own code COMDAT. For other objects, bound
        # it by the next function or section end, so trailing bytes cannot pass.
        # Catch funclets (__catch$...) sit inside the original function's span: they do not end the function.
        next_entries = [s['value'] for s in coff.symbols.values()
                        if s['section'] == symbol['section'] and s['type'] & 0x20
                        and s['value'] > start and not s['name'].startswith('__catch$')]
        end = min(next_entries) if next_entries else len(section['data'])
        actual_size = end - start
        # Compiler/linker INT3 padding is outside the annotated function.
        tail = section['data'][start+size:end]
        if actual_size < size or any(b not in (0xcc, 0x90) for b in tail):
            errors.append('compiled function extent differs: %d vs %d' % (actual_size, size))
        for offset, index, kind in section['relocs']:
            if not start <= offset < start+size:
                continue
            relative = offset-start
            record = dict(offset=relative, kind=kind)
            relocation_reports.append(record)
            try:
                if relative+4 > size:
                    raise ValueError('relocation crosses function end')
                target_symbol = coff.symbols[index]
                name = target_symbol['name']
                record['symbol'] = name
                own = own_data(coff, target_symbol)
                # A literal is placed by its bytes, never by a binding: the game keeps a copy of each value somewhere,
                # and which copy is the linker's choice. Its bytes must be what the game holds where the original
                # refers, so a literal written with another value never matches, whatever build/units.json says.
                by_content = own is not None and LITERAL.match(name) is not None
                addend, = struct.unpack_from('<I', compiled, relative)
                if kind == 0x14: # IMAGE_REL_I386_REL32
                    used, = struct.unpack_from('<i', compiled, relative)
                    displacement, = struct.unpack_from('<i', original, relative)
                    observed = (address + relative + 4 + displacement) & 0xffffffff
                elif kind == 0x06: # IMAGE_REL_I386_DIR32
                    used = addend
                    observed, = struct.unpack_from('<I', original, relative)
                elif kind == 0x07: # IMAGE_REL_I386_DIR32NB
                    used = addend
                    observed = (struct.unpack_from('<I', original, relative)[0] + pe.base) & 0xffffffff
                elif kind == 0x0B: # IMAGE_REL_I386_SECREL: thread-local variable offset inside .tls
                    used = addend
                    observed, = struct.unpack_from('<I', original, relative)
                else:
                    raise ValueError('unsupported relocation kind %d' % kind)
                if kind == 0x0B:
                    expected = pe.secrel(resolve(target_symbol, addend)) & 0xffffffff
                elif by_content:
                    expected = observed
                    record['by_content'] = True
                else:
                    expected = resolve(target_symbol, used) & 0xffffffff
                record.update(expected='0x%08x' % expected, observed='0x%08x' % observed)
                if expected != observed:
                    raise ValueError('original relocation target differs at +0x%x (%s): yours resolves to 0x%08x, original 0x%08x'
                                     % (relative, target_symbol['name'], expected, observed))
                if own is not None and kind != 0x0B:
                    # data the unit defines itself (a literal, a global's initializer, an RTTI descriptor): the game
                    # must hold the same bytes where the original refers
                    at = (observed - used) & 0xffffffff
                    bad = data_differs(pe, own, at)
                    if bad is None or bad:
                        what = ('%s %s at 0x%08x: the game holds other bytes there%s'
                                % ('literal' if by_content else 'data', name, at,
                                   '' if bad is None else ' (%d of %d bytes differ)' % (len(bad), len(own[0]))))
                        if RTTI_NAME.match(name):
                            warnings.append(what)   # a type's class-key or namespace: reported, not yet counted
                        else:
                            raise ValueError(what)
                mask.update(range(relative, relative+4))
                record['match'] = True
            except (ValueError, KeyError, struct.error) as error:
                record['match'] = False
                record['error'] = str(error)
                errors.append(str(error))
        diffs = [dict(offset=i, compiled=compiled[i], original=original[i])
                 for i in range(min(len(compiled), size))
                 if i not in mask and compiled[i] != original[i]]
        if len(compiled) != size:
            errors.append('compiled section shorter than original function')
        reports.append(dict(address='0x%08x' % address, symbol=spec['symbol'],
            size=size, compiled_extent=actual_size, verdict='match' if not errors and not diffs else 'wip',
            errors=errors, byte_differences=diffs, relocations=relocation_reports,
            fold_aliases=spec.get('fold_aliases', []), warnings=warnings))
    return reports


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--obj', required=True)
    parser.add_argument('--exe', required=True)
    parser.add_argument('--manifest', required=True)
    parser.add_argument('--report')
    parser.add_argument('--function-index', default=None,
                        help='address-sorted original entries used to enforce charter 3.2 spans')
    parser.add_argument('--summary', action='store_true', help='omit byte values; safe to retain in git')
    args = parser.parse_args()
    pe = Pe(args.exe)
    spans = FunctionSpans.from_index(pe, args.function_index) if args.function_index else None
    reports = compare(Coff(args.obj), pe, json.loads(Path(args.manifest).read_text()), spans)
    if args.summary:
        for report in reports:
            report['mismatch_offsets'] = [d['offset'] for d in report.pop('byte_differences')]
    output = json.dumps({'size_basis': SIZE_BASIS, 'functions': reports}, indent=2) + '\n'
    if args.report:
        Path(args.report).write_text(output)
    print(output, end='')
    return 0 if all(r['verdict'] == 'match' for r in reports) else 1


if __name__ == '__main__':
    raise SystemExit(main())

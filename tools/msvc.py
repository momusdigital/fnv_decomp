# (test only, not to be merged)
#!/usr/bin/env python3
"""Run one of the Microsoft Visual C++ compilers this project is built with.

usage: python3 tools/msvc.py [--compiler sp1|rtm|vc8] [--tool cl|link|dumpbin|undname] <MSVC arguments>

Compilers (see README.md for where each comes from; the files are Microsoft's and are not in this repository):
  sp1  Visual C++ 2008 SP1 (15.00.30729.01), the default       FNV_MSVC9_ROOT
  rtm  Visual C++ 2008 RTM (15.00.21022.08)                    FNV_MSVC9_RTM_ROOT
  vc8  Visual C++ 2005 SP1 (14.00.50727.762)                   FNV_MSVC8_ROOT
Each root is a folder holding VC/ (bin, include, lib) and SDK/ (Include, Lib).

On Windows the compiler runs directly. Elsewhere it runs under Wine, in the prefix FNV_MSVC9_PREFIX (FNV_MSVC8_PREFIX
for vc8 if set), created on first use. Absolute paths in the arguments are converted to Wine paths.
"""
import argparse
import os
from pathlib import Path
import subprocess
import sys
import tempfile

ROOTS = {'sp1': 'FNV_MSVC9_ROOT', 'rtm': 'FNV_MSVC9_RTM_ROOT', 'vc8': 'FNV_MSVC8_ROOT'}
WINDOWS = os.name == 'nt'


def compiler_root(name):
    variable = ROOTS[name]
    if not os.environ.get(variable):
        raise SystemExit('msvc.py: set %s to the folder holding VC/ and SDK/ for compiler %s' % (variable, name))
    root = Path(os.environ[variable])
    if not (root / 'VC/bin/cl.exe').exists():
        raise SystemExit('msvc.py: %s=%s has no VC/bin/cl.exe' % (variable, root))
    return root


def windows_path(path):
    return 'Z:' + str(Path(path).resolve()).replace('/', '\\')


def run(tool, compiler, arguments):
    root = compiler_root(compiler)
    if WINDOWS:
        env = os.environ.copy()
        env.update(INCLUDE=';'.join(str(p) for p in [root / 'VC/include', root / 'SDK/Include']),
                   LIB=';'.join(str(p) for p in [root / 'VC/lib', root / 'SDK/Lib']),
                   PATH=str(root / 'VC/bin') + os.pathsep + env.get('PATH', ''))
        return subprocess.run([str(root / 'VC/bin' / (tool + '.exe'))] + arguments, env=env,
                              stdin=subprocess.DEVNULL).returncode
    prefix = os.environ.get('FNV_MSVC8_PREFIX') if compiler == 'vc8' else None
    prefix = prefix or os.environ.get('FNV_MSVC9_PREFIX')
    if not prefix:
        raise SystemExit('msvc.py: set FNV_MSVC9_PREFIX to a folder for the Wine prefix (created on first use)')
    env = os.environ.copy()
    env.update(WINEPREFIX=str(Path(prefix).resolve()), WINEDEBUG='-all', WINEPATH=windows_path(root / 'VC/bin'),
               INCLUDE=';'.join(windows_path(p) for p in [root / 'VC/include', root / 'SDK/Include']),
               LIB=';'.join(windows_path(p) for p in [root / 'VC/lib', root / 'SDK/Lib']))
    converted = []
    for arg in arguments:
        for option in ['/LIBPATH:', '/OUT:', '/Fo', '/Fe', '/I']:
            if arg.lower().startswith(option.lower()) and arg[len(option):].startswith('/'):
                converted.append(arg[:len(option)] + windows_path(arg[len(option):]))
                break
        else:
            converted.append(windows_path(arg) if Path(arg).is_absolute() and Path(arg).exists() else arg)
    # Start the Wine server detached from our output first: its background services inherit the starting process's
    # descriptors and would otherwise keep a caller's pipe open forever.
    quiet = dict(env=env, stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    if subprocess.run(['wineserver', '-p'], **quiet).returncode == 2:
        subprocess.run(['wine', 'cmd', '/c', 'exit'], start_new_session=True, **quiet)
        subprocess.run(['wineserver', '-p'], **quiet)
    with tempfile.TemporaryFile() as output:
        code = subprocess.run(['wine', str(root / 'VC/bin' / (tool + '.exe'))] + converted, env=env,
                              stdin=subprocess.DEVNULL, stdout=output, stderr=subprocess.STDOUT).returncode
        output.seek(0)
        sys.stdout.buffer.write(output.read())
        sys.stdout.flush()
    return code


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--tool', default='cl', choices=['cl', 'link', 'dumpbin', 'undname'])
    parser.add_argument('--compiler', default='sp1', choices=sorted(ROOTS))
    options, arguments = parser.parse_known_args()
    raise SystemExit(run(options.tool, options.compiler, arguments))

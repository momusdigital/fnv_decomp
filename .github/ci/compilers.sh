#!/bin/bash
# Download one of the Microsoft compilers from Microsoft and unpack it for tools/msvc.py, as README.md describes under
# "Compilers without Windows". Each download is checked against its SHA-256 first.
#
# usage: compilers.sh sp1|rtm|vc8 DEST     -> DEST/<name>/VC; sp1 also gets DEST/sp1/SDK, which rtm and vc8 reuse
#        compilers.sh --digest DIR          -> one SHA-256 over every file under DIR (paths and contents)
set -euo pipefail
digest() { (cd "$1" && find . -type f -print0 | LC_ALL=C sort -z | xargs -0 sha256sum) | sha256sum | cut -c1-64; }
if [ "$1" = --digest ]; then digest "$2"; exit; fi
name=$1; dest=$(realpath -m "$2"); R="$dest/$name"
work=$(mktemp -d); trap 'rm -rf "$work"' EXIT
# Ubuntu's 7-Zip (the 7zip package, tested); GitHub's runners also carry another build earlier on PATH. The download
# keeps its .iso name: 7-Zip then reads the UDF file system, with the long names the steps below use.
SEVENZIP=$(command -v /usr/bin/7z || command -v 7z)
7z() { "$SEVENZIP" "$@"; }
fetch() {
  curl -fsSL --retry 5 --retry-delay 10 -o "$work/dl.iso" "$1"
  echo "$2  $work/dl.iso" | sha256sum -c --quiet
}
vc9() {   # an Express ISO -> VC/, and SDK/ with "sdk"
  7z x -y -o"$work/tc" "$work/dl.iso" VCExpress >/dev/null
  cabextract -q -d "$work/tc/ixp" "$work/tc/VCExpress/Ixpvc.exe"
  (cd "$work/tc/ixp" && msiextract -C ../vcx vs_setup.msi >/dev/null)
  V="$work/tc/vcx/Program Files/Microsoft Visual Studio 9.0"; mkdir -p "$R"
  cp -r "$V/VC:Vc7" "$R/VC"
  for f in mspdb80.dll msobj80.dll mspdbcore.dll mspdbsrv.exe; do find "$V/Common7" -iname "$f" -exec cp {} "$R/VC/bin/" \; ; done
  if [ "${1:-}" = sdk ]; then
    cabextract -q -d "$work/tc/sdkx" "$work/tc/VCExpress/WCU/WinSDK/WinSDK_Build.exe"
    (cd "$work/tc/sdkx" && msiextract -C ../sdko VistaClientHeadersLibs-x86.msi >/dev/null)
    S="$work/tc/sdko/SOURCEDIR/Program Files/Microsoft SDKs:./Windows:./v6.0A:."; mkdir -p "$R/SDK"
    cp -r "$S/Include" "$R/SDK/Include"; cp -r "$S/Lib" "$R/SDK/Lib"
  fi
}
case $name in
  sp1)
    fetch https://download.microsoft.com/download/E/8/E/E8EEB394-7F42-4963-A2D8-29559B738298/VS2008ExpressWithSP1ENUX1504728.iso \
      6d3b5eedfa461969c5d645871b53002d162a2e238486900d2fdf71774d53fb91
    vc9 sdk;;
  rtm)
    fetch https://download.microsoft.com/download/8/B/5/8B5804AD-4990-40D0-A6AA-CE894CBBB3DC/VS2008ExpressENUX1397868.iso \
      632318ef0df5bad58fcb99852bd251243610e7a4d84213c45b4f693605a13ead
    vc9;;
  vc8)
    fetch https://download.microsoft.com/download/4/2/6/42684501-9ec5-43dd-9dfe-c8c9dfa6a66f/6.1.6000.16384.10.WindowsSDK_Vista_Feb2007Update_rtm.DVD.Rel.iso \
      f544c8ec782921a64ffed4b41206aa3d6e16d0cf47c78a5bc26308ae0c2251ea
    7z x -y -o"$work/tc" "$work/dl.iso" "Setup/WinSDKCompiler*" "Setup/WinSDK-WinSDK_BIN_VC8_Runtime_X86_CRT-common.0.cab" >/dev/null
    (cd "$work/tc/Setup" && msiextract -C ../vcx WinSDKCompiler-x86.msi >/dev/null)
    V="$work/tc/vcx/SOURCEDIR/Program Files/Microsoft SDKs:./Windows:./v6.0:./VC"; mkdir -p "$R/VC"
    cp -r "$V/Bin" "$R/VC/bin"; cp -r "$V/INCLUDE" "$R/VC/include"; cp -r "$V/LIB" "$R/VC/lib"
    7z x -y -o"$work/tc/crt" "$work/tc/Setup/WinSDK-WinSDK_BIN_VC8_Runtime_X86_CRT-common.0.cab" >/dev/null
    A="$R/VC/bin/Microsoft.VC80.CRT"; mkdir -p "$A"
    for d in msvcr80 msvcp80 msvcm80; do cp "$work"/tc/crt/nosxs_$d.dll.* "$A/$d.dll"; done
    printf '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>\n<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">\n<assemblyIdentity type="win32" name="Microsoft.VC80.CRT" version="8.0.50608.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3b"/>\n<file name="msvcr80.dll"/><file name="msvcp80.dll"/><file name="msvcm80.dll"/>\n</assembly>\n' > "$A/Microsoft.VC80.CRT.manifest";;
  *) echo "usage: compilers.sh sp1|rtm|vc8 DEST"; exit 2;;
esac
echo "$name: $(digest "$R")"

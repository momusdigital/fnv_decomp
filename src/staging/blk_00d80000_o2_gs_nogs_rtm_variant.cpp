// src/staging/blk_00d80000_o2_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include <stdlib.h>

// src/staging/blk_00d80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010cc4f4;
void __cdecl finishLoadedObject_hkpSimulation(int* p);
struct FUN_00d85300_Stub {
    void FUN_00d85300(int*);
};
struct FUN_00d85a20_Stub : FUN_00d85300_Stub {
    int* CopyStateFrom(int* p);
};
extern char DAT_01267e30;
class FNVDispatchNode {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual unsigned int v08();

    FNVDispatchNode* Resolve();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FNVDispatchNode* m_18;
};
char* GetDispatchTarget(FNVDispatchNode* pNode);
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};
AllocHolder* __cdecl FUN_00c85750() throw();
void __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int size);
struct FUN_00d85360_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;

    FUN_00d85360_cls* FUN_00d54290();
};
FUN_00d85360_cls* __cdecl FUN_00d85360(int pSource);
struct S_00d85af0_Base {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    void FUN_00d85300(const S_00d85af0_Base* o);
};
struct S_00d85af0_V3 { float x, y, z; };
struct S_00d85af0_Cls : S_00d85af0_Base {
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    S_00d85af0_V3 unkb4;
    S_00d85af0_Cls* AssignFrom(const S_00d85af0_Cls* o);
};
struct CpuOpaque;
extern CpuOpaque DAT_01269514;
CpuOpaque* __cdecl FUN_00d9f6c0();
extern int DAT_010cc4f4;
unsigned int __cdecl FUN_00d9f6e0();
// Havok object clone: allocate a default instance and copy the payload (everything after the header).
struct D85660Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D85660MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D85660Allocator* m_pStreamAllocator;

    D85660Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D85660MemoryRouter& __cdecl D85660GetMemoryRouter() throw();
void __cdecl D85660MemCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();
class D85660Object {
public:
    D85660Object() throw();
    virtual ~D85660Object();

    static void* operator new(unsigned int nbytes) throw()
    {
        D85660Object* p = static_cast<D85660Object*>(D85660GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int m_iData010;
    int m_iData014;
    int m_iData018;
    int m_iData01C;
    int m_iData020;
    int m_iData024;
    int m_iData028;
    int m_iData02C;
    int m_iData030;
    int m_iData034;
    int m_iData038;
    int m_iData03C;
    int m_iData040;
    int m_iData044;
    int m_iData048;
    int m_iData04C;
    int m_iData050;
    int m_iData054;
    int m_iData058;
    int m_iData05C;
    int m_iData060;
    int m_iData064;
    int m_iData068;
    int m_iData06C;
    int m_iData070;
    int m_iData074;
    int m_iData078;
    int m_iData07C;
    int m_iData080;
    int m_iData084;
    int m_iData088;
    int m_iData08C;
    int m_iData090;
    int m_iData094;
    int m_iData098;
    int m_iData09C;
};
D85660Object* __cdecl FUN_00d85660(const D85660Object* pkSource);
extern int DAT_010d3838;
struct FUN_00d86260_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86260_Class(float a, float b, float c);
};
struct NiBinaryStream {
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T>
    __forceinline void Read(T& val) throw() {
        unsigned int uiComponentSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &val, sizeof(T), &uiComponentSize, 1);
    }
};
struct NiStream {
    int s_000, s_001, s_002, s_003, s_004, s_005, s_006, s_007, s_008, s_009, s_010, s_011, s_012, s_013, s_014, s_015, s_016, s_017, s_018, s_019, s_020, s_021, s_022, s_023, s_024, s_025, s_026, s_027, s_028, s_029, s_030, s_031, s_032, s_033, s_034, s_035, s_036, s_037, s_038, s_039, s_040, s_041, s_042, s_043, s_044, s_045, s_046, s_047, s_048, s_049, s_050, s_051, s_052, s_053, s_054, s_055, s_056, s_057, s_058, s_059, s_060, s_061, s_062, s_063, s_064, s_065, s_066, s_067, s_068, s_069, s_070, s_071, s_072, s_073, s_074, s_075, s_076, s_077, s_078, s_079, s_080, s_081, s_082, s_083, s_084, s_085, s_086, s_087, s_088, s_089, s_090, s_091, s_092, s_093, s_094, s_095, s_096, s_097, s_098, s_099, s_100, s_101, s_102, s_103, s_104, s_105, s_106, s_107, s_108, s_109, s_110, s_111, s_112, s_113, s_114, s_115, s_116, s_117, s_118, s_119, s_120, s_121, s_122, s_123, s_124, s_125, s_126, s_127, s_128, s_129, s_130, s_131, s_132, s_133, s_134, s_135, s_136, s_137, s_138, s_139, s_140, s_141, s_142, s_143, s_144, s_145, s_146;
    NiBinaryStream* m_pkIStream;

    template <typename T>
    __forceinline void BinaryRead(T& val) throw() {
        m_pkIStream->Read(val);
    }
};
struct Struct40 {
    int m_00, m_04, m_08, m_0c;
    int m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c;
};
struct TargetData {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
    char unk20;
    char unk21;
    short unk22;
    int unk24, unk28, unk2c;
    Struct40 unk30;
    Struct40 unk70;
};
struct FUN_00d53200_class {
    int unk00;
    void FUN_00c8a230(NiStream&) throw();
};
struct Derived_00d53200 : public FUN_00d53200_class {
    TargetData* unk04;
    void ReadFromStream(NiStream& stream);
};
struct BinaryReader {
    void* vtable;
    unsigned int currentPosition;
    unsigned int reserved08;
    unsigned int (__cdecl *Read)(BinaryReader* stream, void* dst, unsigned int bytes, unsigned int* componentBytes, unsigned int components);

    unsigned int BinaryRead(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        unsigned int readBytes = Read(this,destination,bytes,&componentSize,1);
        currentPosition += readBytes;
        return readBytes;
    }
};
struct DataStream {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    BinaryReader* input;
};
struct Record {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int header;
    unsigned int flag;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int data30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int words40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int words70;
};
void __stdcall FUN_00c8a280(DataStream* stream);
struct DataOwner {
    unsigned int unknown00;
    Record* record;
    void ReadRecord(DataStream* stream);
};
inline int countBitsSetD866(unsigned int n)
{
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0f0f0f0f) + (n & 0x0f0f0f0f);
    n = ((n >> 8) & 0x000f000f) + (n & 0x000f000f);
    return (n & 0xff) + (n >> 16);
}
int __cdecl CountBitsInWords(const unsigned int* puiWords, int iNumWords);
int __cdecl FUN_00cb0fd0(const char*, const char*, unsigned int);
const char* __cdecl FUN_00cb1150(const char*, int);
const char* __cdecl FUN_00cb1140(const char*, int);
struct TypeEntry {
    const char* name;
    int unk04;
    int unk08;
};
extern TypeEntry DAT_011b6ab4[];
extern TypeEntry DAT_011b6c4c[];
struct StringBuf {
    char* m_kStringBuffer;
    int m_fRestLength;
    int m_iCapacityState;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;

    void FUN_00d61a50(const char* s);
    void FUN_00d61fc0(int from, int len);
    int FUN_00d616e0(const char* other);
    void FUN_00cbbd40();
};
int __cdecl GetTypeCode(const char* typeName);
struct B { char pad[0x12]; unsigned short w12; };
struct S {
    unsigned int m0;
    B* m4;
    void SetValueAndPtr(unsigned int a, B* b);
};
struct D871A0Buffer {
    void append(const void* p, int a, int b);
};
struct FUN_00d871c0_class {
    FUN_00d871c0_class* Append(FUN_00d871c0_class* a, int b, const void* p);
};
struct TargetClass {
    void* Append(int a, int b, int c);
};
struct MemberClass {
    int FUN_00d86910();
};
struct FUN_00d87380_Class {
    int unk00;
    MemberClass* unk04;

    TargetClass* CallTargetMethod(TargetClass* target, int arg2);
};
struct FUN_00d86910_Obj {
    int __thiscall FUN_00d86910();
};
struct FUN_00d873b0_Obj {
    void __thiscall FUN_00d873b0(int a, int b);
};
struct FUN_00d873f0_Holder {
    int unk00;
    FUN_00d86910_Obj* unk04;
    FUN_00d873b0_Obj* __thiscall FUN_00d873f0(FUN_00d873b0_Obj* a);
};
class hkSetD874 {
public:
    int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00d87410() const;
};
struct FUN_00d87910_cls {
    int m_00;

    FUN_00d87910_cls* FUN_00d87910();
};
extern "C" unsigned int (__stdcall *DAT_00fdf1d0)();
unsigned __int64 __cdecl FUN_00d87a40();
void __cdecl FUN_00d87920();
void __cdecl FUN_00d87a70();
struct FUN_00d87a80_Stub {
    void* FUN_00d87a80(int);
};
void __cdecl FUN_00d87a90();
extern int DAT_010d3cc0;
D85660Object* __cdecl CreateD85660Object();
class FUN_00d88050 {
public:
    FUN_00d88050();

    bool m_bModifierActive;
    int m_iValue;
    bool m_bValueAt0C;
};
void __cdecl FUN_00d88060();
struct AllocIfaceFree : AllocIface
{
    virtual void Free(void* block, unsigned int size);
};
extern void* DAT_012691fc;
void __cdecl FreeGlobalBlock();
struct FUN_00d880d0 {
    unsigned char m_kPointB;
    int m_i;
    void M_00d880d0();
};
void __cdecl FUN_00d880e0();
struct FUN_00d880f0_Class {
    int unk00;
    int unk04;
    unsigned char unk08;

    void FUN_00d880f0(unsigned char val);
};
struct DispatchTarget {
    virtual void Event0();
    virtual void Event1();
    virtual void Event2();
    virtual void Event3();
    virtual void Event4();
    virtual void Event5();
    virtual void Event6();
    virtual void Dispatch(int argument);
};
void __cdecl InvokeDispatch(void* context, DispatchTarget** target, void* reserved, int argument);
class hkTargetD922B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void process(void* a, void* b, void* c, void* d);
};
void __cdecl FUN_00d92200(void* pvContext, hkTargetD922B** ppkTarget, void* a, void* b, void* c, void* pvUnused, void* d);
class hkStatisticsCollectorD922 {
public:
    virtual ~hkStatisticsCollectorD922();
    virtual void V1();
    virtual void V2();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass);
};
struct hkpAgentEntryD922 {
    void* m_pCollisionAgent;
};
void __cdecl AddChildAgent2ToCollector(void* pvContext, const hkpAgentEntryD922* pkEntry, void* pvUnused, hkStatisticsCollectorD922* pkCollector);
class FUN_00d92250_obj {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int iValue);
};
struct FUN_00d92250_holder {
    FUN_00d92250_obj* m_object;
};
void __cdecl CallObjectVirtual(void* pvUnused, FUN_00d92250_holder* pkHolder, int iValue);
struct FUN_00d92270_Dispatch
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual int v10(float a, float b, int c) = 0;
};
int DispatchVirtualCall(int aiUnused, FUN_00d92270_Dispatch** a2, float afArg1, float afArg2, int aiArg3);
class hkTargetD92A {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void process(void* pvData);
};
void __cdecl FUN_00d922a0(void* pvContext, hkTargetD92A** ppkTarget, void* pvData);
class hkTargetD922 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void process(void* pvData);
};
void __cdecl FUN_00d922c0(void* pvContext, hkTargetD922** ppkTarget, void* pvData);
struct FUN_00d922e0_Iface {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void* unk34(int arg);
};
void* __cdecl CallIfaceMethod(int unused, FUN_00d922e0_Iface** p, int arg);
struct FUN_00d92380_obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b, int c, int d);
};
struct FUN_00d92380_vec {
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00d92380_holder {
    FUN_00d92380_obj* m0;
    int m4;
    int m8;
    int mc;
    int m10;
};
int* __cdecl CallVirtualWithVectorArgs(FUN_00d92380_vec* pVec, int u1, FUN_00d92380_holder* pHolder, int u2, int arg);
struct FUN_00d93310_cls {
    int m_00;
    int m_04;
    int m_08;

    FUN_00d93310_cls* FUN_00d93310();
};
extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
    extern unsigned int DAT_0126835c;
    void __cdecl FUN_00d89f80(void* p, int a2, int a3, int a4, bool* pb);
}
struct StringCursor {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};
struct TargetObj {
    int dummy;
};
struct SubObj {
    int unk_000; int unk_004; int unk_008; int unk_00c; int unk_010; int unk_014; int unk_018; int unk_01c;
    int unk_020; int unk_024; int unk_028; int unk_02c; int unk_030; int unk_034; int unk_038; int unk_03c;
    int unk_040; int unk_044; int unk_048; int unk_04c; int unk_050; int unk_054; int unk_058; int unk_05c;
    int unk_060; int unk_064; int unk_068; int unk_06c; int unk_070; int unk_074; int unk_078; int unk_07c;
    int unk_080; int unk_084; int unk_088; int unk_08c; int unk_090; int unk_094; int unk_098; int unk_09c;
    int unk_0a0; int unk_0a4; int unk_0a8; int unk_0ac; int unk_0b0; int unk_0b4; int unk_0b8; int unk_0bc;
    int unk_0c0; int unk_0c4; int unk_0c8; int unk_0cc; int unk_0d0; int unk_0d4; int unk_0d8; int unk_0dc;
    int unk_0e0; int unk_0e4; int unk_0e8; int unk_0ec; int unk_0f0; int unk_0f4; int unk_0f8; int unk_0fc;
    int unk_100; int unk_104; int unk_108; int unk_10c; int unk_110; int unk_114; int unk_118; int unk_11c;
    int unk_120; int unk_124; int unk_128; int unk_12c; int unk_130; int unk_134; int unk_138; int unk_13c;
    int unk_140; int unk_144; int unk_148; int unk_14c; int unk_150; int unk_154; int unk_158; int unk_15c;
    int unk_160; int unk_164; int unk_168; int unk_16c; int unk_170; int unk_174; int unk_178; int unk_17c;
    int unk_180; int unk_184; int unk_188; int unk_18c; int unk_190; int unk_194; int unk_198; int unk_19c;
    int unk_1a0; int unk_1a4; int unk_1a8; int unk_1ac; int unk_1b0; int unk_1b4; int unk_1b8; int unk_1bc;
    int unk_1c0; int unk_1c4; int unk_1c8; int unk_1cc; int unk_1d0; int unk_1d4; int unk_1d8; int unk_1dc;
    TargetObj unk1e0;
};
struct Arg0 {
    SubObj* m_pSub;
};
struct Arg2 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    int unk24;
    int unk28;
    char unk2c;
};
struct Arg1 {
    void ProcessCallback(Arg2* a1, Arg2* a2, int a3);
};
void LogIntegrateVelocity(Arg0* a1, Arg1* a2, Arg2* a3);
extern "C" char str_010d4030[];
void __cdecl FUN_00d61d00(unsigned int* result, char* text, double d0,
                          int value0, double d1, int value1, double d2);
unsigned int __cdecl FUN_00d97640(float* values, unsigned int* result, signed char value);
void __cdecl FUN_00d61d00(...);
struct FUN_00d97680_Vec {
    float x;
    float y;
    float z;
    float w;
};
int __cdecl FormatVec4(FUN_00d97680_Vec* v, int* dst, char acSeparator);
struct hkRecordD983 {
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;

    hkRecordD983()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
struct FUN_00d98390 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkRecordD983 m_records[4];

    FUN_00d98390();
};
void __cdecl FUN_00d98630(void*, void*, void*, void*);
void* __cdecl FUN_00d99540(void* a1, void* a2, void* a3, void* a4);
struct FNV_00d99f50_Entry { void* value; void* payload; };
struct FNV_00d99f50_Result {
    unsigned char flag;
    FNV_00d99f50_Result() {}
    ~FNV_00d99f50_Result() {}
};
extern "C" void __cdecl FUN_00d98ca0(unsigned char* scratch, const FNV_00d99f50_Entry* entry, void* context, void* left, void* right);
FNV_00d99f50_Result __cdecl FUN_00d99f50(int count, const FNV_00d99f50_Entry* const* entries, void* context, void* left, void* right);
struct FUN_00d9a4a0_Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct FUN_00d9a4a0_Float {
    float unk00;
    float unk04;
};
struct FUN_00d9a4a0_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d9a4a0_Float* unk10;

    void __thiscall InvokeCallback(int a1);
};
float __fastcall FUN_00d9a4a0( FUN_00d9a4a0_Obj* self, int unused, FUN_00d9a4a0_Param* param);
struct IdxStand_ {
    char* m_iWordAt00;
    void* FUN_00d9a4c0(int idx);
};
struct FUN_00d9a4d0_Class {
    int unk00;

    int __thiscall GetEntryOffset(unsigned short value);
};
struct FnvCpu_FUN_00d9f6b0_CpuInterface {
    virtual void Invoke(int value);
};
void __cdecl cleanupLoadedObject_hkpSimulation(FnvCpu_FUN_00d9f6b0_CpuInterface* object);
extern char DAT_0102e388;
struct FUN_00d9fb30_Stub {
    void FUN_00d9fb30();
};
void __stdcall FUN_00d9fb40(unsigned char* output, int unused1);
void __stdcall FUN_00d9fca0(int);
void __stdcall FUN_00d9fcb0(int, int, int);
void __stdcall FUN_00d9fcc0(int);
void __stdcall FUN_00d9fcd0(int);
void __stdcall FUN_00d9fce0(int);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D85TlsFn)(unsigned long);
extern D85TlsFn DAT_00fdf044;
struct D85Ctn {
    void** entries;
    unsigned short count;
};
struct D85Ev {
    unsigned int tag;
    unsigned int time;
    int unk08;
};
struct D85Prof {
    int unk00;
    D85Ev* head;
    int unk08;
    D85Ev* end;
};
struct D85A0 {
    int unk00;
    unsigned int unk04;
};
struct D85Msg {
    D85A0* p;
};
struct D85Node5 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(D85Msg m);
};
static __declspec(noinline) D85Ctn* FUN_00d85d40(D85Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
void __cdecl FUN_00d85fa0(D85Msg a);
struct NiBinaryStreamD861 {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamD861* pkStream, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
struct NiStreamD861 {
    char unk000[0x24c];
    NiBinaryStreamD861* m_pBackingStream;
};
template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStreamD861& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct DataD861 {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};
void __cdecl FUN_00d86100(NiStreamD861& kStream, DataD861* pkData);
struct NiBinaryStreamD8616 {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamD8616* pkStream, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamD8616* pkStream, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
struct NiStreamD8616 {
    char unk000[0x24c];
    NiBinaryStreamD8616* m_pBackingStream;
    NiBinaryStreamD8616* m_pUnderlyingStream;
};
template <class T>
inline void NiStreamLoadBinaryD8616(NiBinaryStreamD8616& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}
struct DataD8616 {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};
void __cdecl FUN_00d86160(NiStreamD8616& kStream, DataD8616* pkData);
extern int DAT_010d3838;
struct FUN_00d86220_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86220_Class();
};
extern __declspec(thread) unsigned int tlsArr[0xb0];
class AutoMemContext {
public:
    unsigned int m_saved;

    AutoMemContext()
    {
        m_saved = tlsArr[0xaf];
        tlsArr[0xaf] = 0x10;
    }
    ~AutoMemContext() { tlsArr[0xaf] = m_saved; }
};
void __cdecl FUN_00c9eae0(void* p);
struct FUN_00dee750 {
    void* m_vptr;
    unsigned short m_usMemorySizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;

    static void* operator new(unsigned int sz)
    {
        AllocHolder* holder = FUN_00c85750();
        AllocIface* alloc = holder->m_pAllocator;
        void* p = alloc->Alloc(sz);
        ((FUN_00dee750*)p)->m_usMemorySizeAndFlags = (unsigned short)sz;
        return p;
    }
    static void operator delete(void* p) { FUN_00c9eae0(p); }

    FUN_00dee750();
};
struct FUN_00d86470_cls {
    int unk00;
    FUN_00dee750* m_04;

    unsigned int CreateData();
};
class hkBitFieldD867 {
public:
    unsigned int* m_auiBitFieldWords;
    int m_numWords;
    int m_iCapacityState;
    int m_iNumBits;

    void FUN_00d867e0(int value);
};
struct Cls00d86950 {
    int unk00;
    int unk04;
    int unk08;
    int GetUnk08();
};
struct S_00d87a60 {
    int m_uiFilterValue;
    int GetValue();
};
extern void* DAT_012691fc;
void* __cdecl FUN_00d880a0();
class FUN_00d88100_Class {
public:
    bool m_bTriggered;
    char unk01;
    char unk02;
    char unk03;
    int m_iArrayLength;
    bool m_bEnableState;
    bool m_abFlags[3];

    bool FUN_00d88100(int iIndex);
};
struct S00d881a0_Leaf {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int m78;
};
struct S00d881a0_Mid {
    int unk00;
    int unk04;
    S00d881a0_Leaf* m08;
};
struct S00d881a0_Obj {
    S00d881a0_Mid* m00;
};
int __cdecl FUN_00d29bf0(void* a0, void* a1, void* a2, void* a3, void* a4, int a5);
void __cdecl FUN_00d1a330(int a0, void* a1, void* a2);
static int FUN_00d881a0(void* p, void* ecxv, char* eaxv, S00d881a0_Obj* esi, void* edi);
int S00d881a0_Wrap(void* p);
static unsigned char* S00d96870_outp;
static void FUN_00d96870(unsigned char* self, int* src, unsigned char* out);
void __fastcall S00d96870_Entry(unsigned char* self, int* src);
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
struct D99FC0Quad { int a; int b; int c; int d; };
struct D99FC0Object {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    D99FC0Quad q30;
    __m128 v40;
};
void __cdecl IntersectTree(int a1, int a2, int a3, float* a4, int* a5,
                          int a6, int a7, float a8, float a9, float a10, int a11);
void __cdecl ComputeAndDispatchDelta(D99FC0Object* obj, int a2, int a3, float a4, float a5, float a6, int a7);
struct FUN_00d9a410_Target {
    virtual void v00();
    virtual char* v01(char* buffer, int* a, int* b);
};
struct FUN_00d9a410_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
typedef void (__cdecl *FUN_00d9a410_Callback)(int*, int*, void*, int, int);
struct FUN_00d9a410_Entry {
    FUN_00d9a410_Callback fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct FUN_00d9a410_Stub {
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a410_Target* unk0c;
    int unk10;
    int unk14;
    int* unk18;
    int unk1c;
    unsigned char* unk20;

    void __thiscall InvokeCallback(int* param);
};
struct ArgD9A4 {
    int unk00, unk04, unk08, unk0C;
};
struct InnerD9A4 {
    int unk00;
    float m_fValue;
};
class PrimaryD9A4 {
public:
    virtual ~PrimaryD9A4();
};
class SecondaryD9A4 {
public:
    virtual float FUN_00d9a480(ArgD9A4* pkArg) = 0;
};
class ObjD9A4 : public PrimaryD9A4, public SecondaryD9A4 {
public:
    int unk08;
    int unk0C;
    InnerD9A4* m_pkInner;

    void InvokeCallback(int iValue);
    virtual float FUN_00d9a480(ArgD9A4* pkArg);
};
struct __declspec(align(16)) FUN_00d9a4e0_Obj {
    __m128 unk00;
    __m128 unk10;
    int unk20;
    unsigned short unk24;
    unsigned short unk26;
    FUN_00d9a4e0_Obj* CopyFrom(const FUN_00d9a4e0_Obj* o);
};
namespace sd84c50 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType() const;
};

struct BoolResult {
    bool m_bValue;

    BoolResult(bool bValue) : m_bValue(bValue) {}
};

// @fnv 0x00d84c50
BoolResult FUN_00d84c50(const Shape* pkShape)
{
    switch (pkShape->GetType())
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
        return BoolResult(true);
    default:
        return BoolResult(false);
    }
}

}
extern char DAT_01267e30;
class ShapeD84D {
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual int getType();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShapeD84D* m_pkChild;

    ShapeD84D* FUN_00cdf6d0();
};
void* __cdecl GetShapeData(ShapeD84D* pkShape);
// pivot vector lives first in each 0x40-byte atom
struct PivotAtom {
    __m128 m_kPivotVector;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};
// view of the derived-class atom chain at data+0x50
struct AtomChain {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    PivotAtom m_kBridgeAtoms[2];
};
// hkpConstraintData stand-in (base class stays 4-aligned)
struct PivotCData {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();

    PivotCData* FUN_00cdf6c0();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    PivotCData* m_wrapped;
};
void __cdecl SetPivotAtom(PivotCData* data, const __m128* pivot, int pivotIndex);
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D90TlsFn)(unsigned long);
extern D90TlsFn DAT_00fdf044;
struct D90Ctn {
    void** entries;
    unsigned short count;
};
struct D90Owner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    D90Ctn m_kListeners;
};
struct D90Ev {
    unsigned int tag;
    unsigned int time;
    int unk08;
};
struct D90Prof {
    int unk00;
    D90Ev* head;
    int unk08;
    D90Ev* end;
};
struct D90Node {
    virtual void v00();
    virtual void v01(D90Owner* pOwner);
    virtual void v02();
    virtual void v03(D90Owner* pOwner);
};
static __declspec(noinline) D90Ctn* FUN_00d85d40(D90Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
D90Ctn* __cdecl FUN_00d85d90(D90Owner* pOwner);
struct hkTimerCommand {
    const char* m_pCommandName;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
static __forceinline void hkTimer(const char* name, volatile unsigned int& t)
{
    StringCursor* s = (StringCursor*)TlsGetValue(DAT_0126835c);
    if (s->m_cur < s->m_kRayEnd) {
        hkTimerCommand* c = (hkTimerCommand*)s->m_cur;
        c->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        c->m_ticks = t;
        s->m_cur = (char*)(c + 1);
    }
}
template <class T>
struct ResizableArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++) {
            m_data[i] = m_data[i + 1];
        }
    }
};
struct hkpConstraintInstance;
struct hkpConstraintListener {
    virtual ~hkpConstraintListener();
    virtual void ConstraintAddedCallback(hkpConstraintInstance* constraint);
    virtual void ConstraintRemovedCallback(hkpConstraintInstance* constraint);
};
struct hkpConstraintInstance {
    char pad[0x20];
    ResizableArray<hkpConstraintListener*> m_kListeners;
};
static void FUN_00d85d40(ResizableArray<hkpConstraintListener*>& cleanupArray)
{
    for (int i = cleanupArray.GetLogicalSize() - 1; i >= 0; i--) {
        if (cleanupArray[i] == 0) {
            cleanupArray.removeAtAndCopy(i);
        }
    }
}
void __cdecl NotifyConstraintRemoved(hkpConstraintInstance* constraint);
void __cdecl FUN_00c908c0(AllocIface& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T>
class hkArrayD868 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(AllocIface& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n) {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill)
    {
        AllocIface* a; AllocHolder* h; h = FUN_00c85750(); a=h->m_pAllocator; reserve(*a,n);
        int i = n - m_iElementCount;
        T* p = m_data + m_iElementCount;
        while (i-- > 0)
            *p++ = fill;
        m_iElementCount = n;
    }
};
class hkBitFieldD868 {
public:
    hkArrayD868<unsigned int> m_auiBitFieldWords;
    int m_iNumBits;

    void FUN_00d867e0(int iValue) throw();
    void Resize(int iNumBits, int iInitialValue);
};
extern const char DAT_010d3aa0[];
extern const char DAT_010d3a90[];
int __cdecl FUN_00cb0fd0(const char*, const char*, int) throw();
int __cdecl FUN_00cb10d0(const char*) throw();
const char* __cdecl FUN_00cb1140(const char*, int) throw();
int __cdecl CallWithZeroMiddleArg(const char*, int) throw();
int __cdecl GetTypeCode(const char*) throw();
struct HkTempAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReturnMemory(void*, int) throw();
};
struct HkBytes16 {
    int a;
    int b;
    int c;
    int d;
};
struct HkBytes64 {
    HkBytes16 a;
    HkBytes16 b;
    HkBytes16 c;
    HkBytes16 d;
};
struct HkBytes128 {
    HkBytes64 a;
    HkBytes64 b;
};
struct HkInplaceChars {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkBytes128 m_kStorage;
};
struct FUN_00d61b10 {
    HkInplaceChars m_kStringBuffer;

    FUN_00d61b10(const char*, int) throw();
    ~FUN_00d61b10() throw() {
        AllocHolder* router = FUN_00c85750();
        int cap = m_kStringBuffer.m_iCapacityState;
        HkTempAllocator* allocator = reinterpret_cast<HkTempAllocator*>(router->unk0c);
        m_kStringBuffer.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            allocator->ReturnMemory(m_kStringBuffer.m_data, cap & 0x3fffffff);
        m_kStringBuffer.m_iCapacityState = int(0x80000000u);
        m_kStringBuffer.m_data = 0;
    }
};
int __cdecl GetTypeCodeFromString(const char* name) throw();
struct FUN_00d87180_cls : S {
    FUN_00d87180_cls* FUN_00d87180(unsigned int a, B* b);
};
class OwnerD87A {
public:
    unsigned __int64 GetCurrentValue() const;
    int unk00;
    int unk04;
    unsigned __int64 m_uiCurrentValue;
};
__declspec(noinline) extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size)
{
    unsigned char* p = (unsigned char*)destination;
    for (unsigned int i = 0; i < size; ++i)
        p[i] = (unsigned char)value;
    return destination;
}
struct MonitorBuffer {
    void* m_ppVirtualMethodTable;
    int m_uiItemCount;
    char m_bSlotEnabled;
    char m_buffer[50];
    void FUN_00d880b0();
};
struct hkStepInfoD881;
struct hkpSolverInfoD881;
struct hkpConstraintQueryInD881;
struct BufferStateD881 {
    char* m_pRayStart;
    char* m_kRayEnd;
    char* m_pTileTemplate;
    char* m_pValues;
};
struct hkpConstraintSolverResourcesD881 {
    hkStepInfoD881* m_pStepInfo;
    hkpSolverInfoD881* m_pSolverInfo;
    hkpConstraintQueryInD881* m_pConstraintQueryIn;
    char* m_pVelocityAccumulatorA;
    char* m_pVelocityAccumulatorB;
    char* m_pVelocityAccumulatorC;
    char* m_pBufferA;
    char* m_pBufferB;
    BufferStateD881 m_akBufferStates[3];
};
static inline char* alignDownD881(char* p) { return (char*)((unsigned int)p & ~15); }
void __cdecl InitializeConstraintSolverResources(hkStepInfoD881* pkStepInfo, hkpSolverInfoD881* pkSolverInfo, hkpConstraintQueryInD881* pkQueryIn, char* pcBuffer, int iBufferSize, hkpConstraintSolverResourcesD881* pkOut);
void __cdecl FUN_00d892e0();
class hkpShapeD923 {
public:
    virtual ~hkpShapeD923();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};
struct hkpCdBodyD923 {
    const hkpShapeD923* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD923* m_parent;
};
class hkpContactMgrD923;
class hkpCollisionAgentD923;
struct hkpCollisionInputD923;
typedef hkpCollisionAgentD923* (__cdecl *CreateFuncD923)(
    const hkpCdBodyD923&, const hkpCdBodyD923&,
    const hkpCollisionInputD923&, hkpContactMgrD923*);
struct AgentFuncsD923 {
    CreateFuncD923 m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    void* m_bIsFlipped;
};
struct hkpCollisionDispatcherD923 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    AgentFuncsD923 m_agent2Funcs[1];
    CreateFuncD923 findCreateFunc(const hkpCdBodyD923& bodyA, const hkpCdBodyD923& bodyB, const hkpCollisionInputD923& input) const;
};
struct hkpCollisionInputD923 {
    hkpCollisionDispatcherD923* m_pCollisionDispatcher;
    int unk04, unk08, unk0C, unk10;
    int m_bCreatePredictiveAgents;
};
struct hkpAgent3InputD923 {
    const hkpCdBodyD923* m_pBodyA;
    const hkpCdBodyD923* m_pBodyB;
    const void* m_pAdditionalCollidableBody;
    const hkpCollisionInputD923* m_pRayCastInput;
    hkpContactMgrD923* m_pContactManager;
};
struct hkpAgentEntryD923 {
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
};
struct hkpAgentDataD923;
inline CreateFuncD923 hkpCollisionDispatcherD923::findCreateFunc(const hkpCdBodyD923& bodyA, const hkpCdBodyD923& bodyB, const hkpCollisionInputD923& input) const
{
    int typeA = bodyA.m_pCollisionShape->m_type;
    int typeB = bodyB.m_pCollisionShape->m_type;
    const unsigned char* table = input.m_bCreatePredictiveAgents ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
    unsigned char agentType = table[typeA * 32 + typeB];
    return m_agent2Funcs[agentType].m_pCreateFunc;
}
hkpAgentDataD923* __cdecl CreateAgent(const hkpAgent3InputD923& input, hkpAgentEntryD923* entry, hkpAgentDataD923* freeMemory);
struct CleanupAllocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* object, unsigned int size);
    virtual void unk0C();
    virtual void unk10(void* object, unsigned int size);
};
struct CleanupRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CleanupAllocator* m_pThreadAllocator;
    int unk14;
    CleanupAllocator* m_allocator2;
};
struct CleanupObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    void* unk50;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5A;
    void* unk5C;
    int unk60;
    int unk64;
    void* unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;

};
static void FUN_00d93ab0(CleanupObject* self);
CleanupObject* volatile cleanupInput;
void CleanupEntry();
extern "C" void _ReadWriteBarrier(void);
extern "C" {
    unsigned __int64 __rdtsc(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
}
extern unsigned int DAT_0126835c;
extern "C" char str_010cc5c4[];
extern "C" char str_010d3e98[];
extern "C" char str_01076f38[];
void __cdecl FUN_00d89ed0(void* p, int a, int b);
struct S00d944d0_Stream {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};
struct S00d944d0_Ent16 {
    char* m_name;
    unsigned int m_ts;
    int unk08;
    char* m_ucOperationType;
};
struct S00d944d0_Ent12 {
    char* m_name;
    unsigned int m_ts;
    int unk08;
};
struct S00d944d0_Sub {
    int unk00;
};
struct S00d944d0_Obj {
    S00d944d0_Sub* m_sub;
};
struct S00d944d0_Arg2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    int m_24;
};
struct S00d944d0_Arg1 {
    void ProcessCallback(S00d944d0_Arg2* a1, S00d944d0_Arg2* a2, int a3);
};
void __cdecl FUN_00d944d0(S00d944d0_Obj* a1, S00d944d0_Arg1* a2, S00d944d0_Arg2* a3);
extern char DAT_010cc5c4[];
extern char DAT_010d3eb8[];
extern char DAT_01076f38[];
struct ProfilerLongRecord {
    char* name;
    unsigned int time;
    unsigned int unk08;
    char* secondaryName;
};
struct ProfilerShortRecord {
    char* name;
    unsigned int time;
    unsigned int unk08;
};
struct SolverTarget {
    int unk00, unk04, unk08, unk0c, unk10;
};
struct SolverObject {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    SolverTarget* target;
};
void __cdecl FUN_00df0680(TargetObj*, int, int, int);
void __cdecl FUN_00d94730(Arg0* world, Arg1* context, SolverObject* object);
struct StructItem {
    short* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short pad16;
    unsigned short unk18;
    unsigned short unk1A;
};
struct StructA {
    StructItem* items;
    int count;
    int unk08;
    int* ptrC;
    int unk10;
    int unk14;
    char unk18;
};
struct StructB {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};
extern double DAT_010c9300;
struct LocalFlag { unsigned char value; };
void __cdecl FUN_00d72190(short* a1, StructB* a2, LocalFlag a3, int** a4);
void __cdecl FUN_00d6f460(short* a1, unsigned short a2, StructB* a3, int** a4);
static void WriteItems(StructA* a, StructB* b);
extern "C" StructA* input_a();
extern "C" StructB* input_b();
void invoke_match();
struct d94eb0_cls { unsigned char b; };
extern "C" d94eb0_cls* d94eb0_target(void);
static void FUN_00d94eb0(d94eb0_cls* dst);
void d94eb0_caller(void);
template <typename ENUM, typename STORAGE> struct hkEnum {
    STORAGE m_kStorage;
    __forceinline hkEnum(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
};
enum JobCategory { HK_JOB_TYPE_DYNAMICS = 0 };
enum JobSpuType { HK_JOB_SPU_TYPE_INVALID, HK_JOB_SPU_TYPE_ENABLED, HK_JOB_SPU_TYPE_DISABLED };
struct JobDescriptor {
    unsigned char m_ucSubType;
    hkEnum<JobCategory, unsigned char> m_eJobType;
    hkEnum<JobSpuType, unsigned char> m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    __forceinline JobDescriptor(JobCategory jobType, unsigned int subType, unsigned short size, JobSpuType spuType)
        : m_ucSubType((unsigned char)subType), m_eJobType(jobType), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};
struct hkpTaskHeader {
    int unk00;
    int m_iJobId;
};
struct DynamicsJob : public JobDescriptor {
    int unk08;
    int unk0c;
    unsigned short m_usValueAtOffset10;
    int m_taskHeader14;
    int m_mtThreadStructure18;
    int m_unk1c;
    hkpTaskHeader* m_kHeader;
    __forceinline DynamicsJob(unsigned int subType, unsigned short size, const DynamicsJob& src)
        : JobDescriptor(HK_JOB_TYPE_DYNAMICS, subType, size, HK_JOB_SPU_TYPE_DISABLED)
    {
        m_usValueAtOffset10 = src.m_usValueAtOffset10;
        m_taskHeader14 = src.m_taskHeader14;
        m_mtThreadStructure18 = src.m_mtThreadStructure18;
        m_unk1c = src.m_unk1c;
    }
};
struct DynamicsJobSubtype14 : public DynamicsJob {
    __forceinline DynamicsJobSubtype14(const DynamicsJob& job)
        : DynamicsJob(14, 0x30, job)
    {
        m_usValueAtOffset10 = job.m_usValueAtOffset10;
        m_kHeader = job.m_kHeader;
    }
};
inline void* operator new(unsigned int, void* where) throw() { return where; }
struct JobRecord {
    int m_iFirstValue;
    int unk04;
    int unk08;
    int unk0c;
    DynamicsJob m_kJob;
};
int __cdecl TryCreateSubtype14Job(void* queue, void* data, const DynamicsJob& job, JobRecord& newJobCreated);
struct __declspec(align(16)) S00d96970_Local {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned short unk04;
    short unk06;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct S00d96970_Target {
    void __thiscall InsertItemAndNotify(int value, S00d96970_Local* local, int flag);
};
struct S00d96970_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;
};
static void FUN_00d96970(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value);
void S00d96970_Entry(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value);
extern float DAT_01017b78;
extern float DAT_01012068;
extern float DAT_01050cb0;
extern double DAT_01011588;
extern double DAT_01035718;
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
__forceinline unsigned int roundLane(const float& value)
{
    float copy = value;
    return fnv_FloatToInt(copy);
}
float FUN_00d974f0();
extern const __m128 DAT_011b6de0;
__m128 __cdecl FUN_00d98620();
struct ListenerArray {
    void** m_ppItems;
    unsigned short m_wCount;
};
static void FUN_00d85d40(ListenerArray* pArr);
struct ListenerOwner {
    int unk00;
    ListenerArray m_kNode;
};
void CallCompact(ListenerOwner* o);
#include <stdarg.h>
namespace sd85040 {

struct __declspec(align(16)) FourFloatVector {
    __m128 m_vComponents;
};

struct __declspec(align(16)) Transform {
    FourFloatVector m_aRotation[3];
    FourFloatVector m_kTranslation;

    void FUN_00c6cd60(const Transform& kOther);
};

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType() const;
};

struct ContainerShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Shape* m_pkChild;
};

struct ListShape : Shape {
    Shape* FUN_00cdf6c0();
};

struct VertexShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    FourFloatVector m_akVertices[1];
};

struct TransformShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    Transform m_akTransforms[1];
};

// @fnv 0x00d85040
void FUN_00d85040(Shape* pkShape, const Transform& kTransform, int iIndex)
{
    for (;;)
    {
        switch (pkShape->GetType())
        {
        case 12:
            pkShape = ((ContainerShape*)pkShape)->m_pkChild;
            break;
        case 13:
            pkShape = ((ListShape*)pkShape)->FUN_00cdf6c0();
            break;
        case 1:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 2:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 6:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 7:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 14:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 9:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 0:
            ((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents = kTransform.m_kTranslation.m_vComponents;
            return;
        case 8:
            ((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents = kTransform.m_kTranslation.m_vComponents;
            return;
        case 15:
            ((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents = kTransform.m_kTranslation.m_vComponents;
            return;
        default:
            return;
        }
    }
}

}
struct hkBool_d86 {
    char m_cBooleanValue;
    hkBool_d86(bool b) { m_cBooleanValue = (char)b; }
};
struct HasFlag_d86 {
    char pad[0x10];
    unsigned short m_flags;
    hkBool_d86 HasFlag() const;
};
struct D94Rec16 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
    const char* name2;
};
struct D94Rec12 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
};
struct D94Tls {
    int unk00;
    D94Rec16* pCur;
    int unk08;
    D94Rec16* pEnd;
};
extern unsigned int DAT_0126835c;
typedef void* (__stdcall *D94TlsGetFn)(unsigned long);
extern D94TlsGetFn DAT_00fdf044;
extern const char str_010d3ef4[];
void __cdecl FUN_00d29830(char* p, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
struct D94Sub {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int m30;
};
struct D94Body {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    D94Sub* m18;
    int u1c;
    int* p20;
    unsigned short us24;
    unsigned short us26;
};
struct D94Obj {
    int ProcessCallback(D94Body* a, D94Body* b, int c);
};
int __cdecl FUN_00d94df0(char* a1, D94Obj* a2, D94Body* a3);
#include <string.h>
struct S00d967a0_Obj {
    void** vptr;
};
struct S00d967a0_Rec {
    unsigned char m00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m10;
    unsigned short unk12;
    int m14;
    unsigned int unk18;
    S00d967a0_Obj* m1C;
    unsigned int unk20;
    unsigned short m24;
    unsigned short unk26;
    unsigned short m28;
    unsigned short m2A;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m40;
    unsigned short m44;
};
static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (--numQuads > 0);
}
static __forceinline int split13(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m24++;
    src->m28 = (unsigned short)(a - c);
    src->m40 += c;
    dst->m44 = 0x200;
    dst->m28 = c;
    return 1;
}
static __forceinline int split15(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m28 = (unsigned short)(a - c);
    src->m24++;
    dst->m28 = c;
    return 1;
}
int SplitRecord(int a1, int a2, S00d967a0_Rec* src, S00d967a0_Rec* dst);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);
struct D986Result {
    char value;
    D986Result(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};
D986Result __cdecl FUN_00d98630(const __m128* src, const __m128* dst, int mask);
// Real body is 0xd96600..0xd9679f (0x1A0). 0xd967a0 is a second function the claim swallowed.
struct D96600Link {
    D96600Link* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1c;
};
struct D96600Table {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int* table;
};
struct D96600Blob {
    unsigned char type;
    unsigned char unk01;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short word10;
    unsigned short unk12;
    int field14;
    D96600Link* unk18;
    D96600Table** ppHolder;
    union {
        int count20;
        unsigned int offset20;
        D96600Link* node20;
    };
    union {
        unsigned int limit24;
        struct {
            unsigned short word24;
            unsigned short word26;
        };
    };
    int unk28;
    D96600Link* node2c;
    int unk30;
    unsigned short word34;
    unsigned short word36;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;

    int FUN_00df2640(int** slot, D96600Blob* dst);
};
static __forceinline int popPart(D96600Blob* src, D96600Blob* dst)
{
    D96600Table* holder = *src->ppHolder;
    int** slot = &holder->table;
    dst->field14 = holder->table[dst->word10];

    switch (src->type) {
    case 0: {
        int n = src->count20;
        if (n <= 1)
            return 0;
        src->word10++;
        src->count20 = n - 1;
        dst->count20 = 1;
        return 1;
    }
    case 1: {
        unsigned short step = 0x80;
        if (src->word26 <= step)
            return 0;
        src->word26 = (unsigned short)(src->word26 - step);
        src->word24 = (unsigned short)(src->word24 + step);
        dst->word26 = step;
        return step - 0x7f;
    }
    case 4:
    case 10:
        if (src->node20->next == 0)
            return 0;
        src->node20 = src->node20->next;
        return 1;
    case 12:
        return src->FUN_00df2640(slot, dst);
    case 11: {
        unsigned short step = 0x80;
        if (src->word34 > step) {
            src->word34 = (unsigned short)(src->word34 - step);
            src->word36 = (unsigned short)(src->word36 + step);
            dst->word34 = step;
            return step - 0x7f;
        }
        if (src->count20 == 0)
            return 0;
        src->type = 0x0a;
        return 1;
    }
    case 7:
    case 9: {
        unsigned int next = src->offset20 + 0x4000;
        if (next >= src->limit24)
            return 0;
        src->offset20 = next;
        dst->limit24 = next;
        return 1;
    }
    case 8:
        if (src->node2c->flag1c != 0)
            return 0;
        src->node2c = src->node2c->next;
        return 1;
    case 3:
    case 6:
    case 14:
        *dst = *src;
        return 0;
    case 2:
    case 5:
    case 13:
        return 0;
    default:
        return 0;
    }

}
int __cdecl PopPart(int callbackCtx, int callbackIndex, D96600Blob* src, D96600Blob* dst);
union __declspec(intrin_type) __declspec(align(16)) __m128i { unsigned __int64 q[2]; };
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_or_ps(__m128, __m128);
__m128 _mm_cmpeq_ps(__m128, __m128);
__m128 _mm_cmplt_ps(__m128, __m128);
__m128 _mm_cmple_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_max_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, int);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_setzero_ps();

__m128 _mm_load_ss(const float*);
__m128 _mm_set_ps1(float);
int _mm_movemask_ps(__m128);
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_srli_epi32(__m128i, int);
__m128i _mm_slli_epi32(__m128i, int);
__m128 _mm_cvtepi32_ps(__m128i);
}
__forceinline __m128 TreeSplat(float value) {
    __m128 scalar = _mm_load_ss(&value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
struct __declspec(align(16)) TreeVector {
    float x, y, z, w;
    __m128 simdValue() const { return *reinterpret_cast<const __m128*>(this); }
    float operator[](unsigned int axis) const { return (&x)[axis]; }
};
struct TreeNode {
    int flags;
    unsigned int bounds;
};
struct __declspec(align(16)) QuantizedBounds {
    unsigned short minX, minY, minZ, idLow;
    unsigned short maxX, maxY, maxZ, idHigh;
};
union TreeLeafId {
    unsigned int value;
    struct { unsigned short low, high; };
};
struct TreeCollector {
    virtual void unused();
    virtual void AddHit(unsigned char* state, unsigned int id);
    virtual void begin(unsigned char* state);
    virtual float earlyOut();
};
extern unsigned int DAT_010c92e0[4];
extern const double DAT_010217d0;
extern const __m128 DAT_011b6de0;
extern __m128 DAT_010c7170;
extern const float DAT_010cd644 = 1.0000000272564224e16f;
extern const float DAT_0104e148 = -3.402820018375656e38f;
extern const float DAT_0104da48 = 3.402820018375656e38f;
float __cdecl FUN_00c98210(float a, float b);
float __cdecl FUN_00c9e0f0(float a, float b);
template<class T> struct TreeRef { T* p; TreeRef(T* q):p(q){} operator T*()const{return p;} T* operator->()const{return p;} };
__forceinline const QuantizedBounds* projectAt(const TreeNode& node, const QuantizedBounds* leaves, unsigned int index) { return leaves + (node.flags & 0x7fffffff) + index; }
struct BoundPair { __m128 minimum, maximum; void set(float a, float b) { minimum = _mm_set_ps1(a); maximum = _mm_set_ps1(b); } };
void __cdecl IntersectTree(void* tree, const TreeNode* node, const QuantizedBounds* leaves, const TreeVector* scale, const TreeVector* offset, const TreeVector* origin, const TreeVector* direction, float intervalMin, float intervalMax, float fractionScale, TreeCollector* collector);
extern char str_010cc5c4[];
extern char str_010d3ec8[];
extern char DAT_01076f38[];
struct S00d94a80_Ctx {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct __declspec(align(16)) S00d94a80_Local {
    S00d94a80_Ctx head;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    char* unk94;
};
void __cdecl FUN_00d6f460(char* atom, int count, S00d94a80_Local* ctx, int** cursor);
struct S00d94a80_Bool {
    bool m_cBooleanValue;
    S00d94a80_Bool(bool v) { m_cBooleanValue = v; }
};
void __cdecl FUN_00d72190(char* atom, S00d94a80_Local* ctx, S00d94a80_Bool bCopy, int** cursor);
inline S00d94a80_Bool S00d94a80_True() { S00d94a80_Bool r(true); return r; }
struct S00d94a80_A0 {
    SubObj* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    S00d94a80_Ctx m_ctx;
};
struct S00d94a80_Rec {
    char* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1a;
};
struct S00d94a80_Desc {
    int unk00;
    int unk04;
    char* end;
    int* c0;
    char* mon;
    int count;
    S00d94a80_Rec records[1];
};
struct S00d94a80_A2 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    S00d94a80_Desc* unk20;
    int unk24;
    unsigned char unk28;
};
struct ArgHandle {
    Arg2* p;
    ArgHandle(Arg2* q):p(q) {}
};
struct S00d94a80_TimerCmd {
    const char* m_name;
    unsigned int m_uiStartTicks;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};
static __forceinline void S00d94a80_Process(Arg0* a1, Arg2* p)
{
    S00d94a80_Desc* desc = ((S00d94a80_A2*)p)->unk20;
    S00d94a80_Local base;
    base.head = ((S00d94a80_A0*)a1)->m_ctx;
    S00d94a80_Rec* rec = desc->records;
    char* mon = desc->mon;
    int count = desc->count;
    char* end = desc->end;
    int* c0 = desc->c0;
    base.unk94 = mon;
    bool flag = ((S00d94a80_A2*)p)->unk28 != 0 && desc->unk00 != 0;
    _ReadWriteBarrier();

    
    int* cursor = c0;
    if (count > 0) {
    int remaining = count;
    do {
        S00d94a80_Rec* r = rec++;
        base.head.unk38 = r->unk0c;
        base.head.unk3c = r->unk10;
        base.head.unk30 = (unsigned int)(end + r->unk18 * 128);
        base.head.unk34 = (unsigned int)(end + r->unk1a * 128);
        base.head.unk6c = r->unk18;
        base.head.unk70 = r->unk1a;
        base.head.unk60 = r->unk04;
        base.head.unk64 = r->unk08;
        base.head.unk74 = r->unk08;
        unsigned int w14 = r->unk14;
        char* atom = r->unk00;
        if (*(unsigned short*)atom == 0x16) {
            S00d94a80_Bool b(true);
            FUN_00d72190(atom, &base, b, &cursor);
        } else {
            FUN_00d6f460(atom, w14, &base, &cursor);
        }
    } while (--remaining);
    }

    int* c = cursor;
    if (!flag) {
        *c = 0;
    } else {
        int remain = (int)(base.unk94 - (char*)c);
        if (remain > 0) {
            *(float*)c += 1.1920928955078125e-07;
            c[1] = remain;
            *(unsigned char*)c = 2;
        }
    }

}
void __cdecl FUN_00d94a80(Arg0* a1, Arg1* a2, Arg2* a3);
extern const float g_011c5874_arg1;
extern const float runtimeFloatSettingDefault262;
extern double DAT_01035718;
union F128U
{
    __m128 v;
    unsigned u[4];
};
static const F128U V4C = { { 196608.0f, 196608.0f, 196608.0f, 196608.0f } };
float FUN_00d97440();
extern "C" void _mm_store_ps(float* p, __m128 a);
extern int DAT_010d37e4;
struct FUN_00d84bd0
{
    unsigned int m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;
    unsigned int unk0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    volatile float m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    volatile float m_34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    volatile float m_48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    volatile float m_60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    volatile float m_74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    volatile float m_88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    volatile unsigned short m_a0;
    volatile unsigned char m_a2;

    FUN_00d84bd0();
};

extern "C" __m128 _mm_rsqrt_ps(__m128);
extern "C" __m128 DAT_010c71c0;
extern "C" __m128 DAT_010c71d0;
extern "C" __m128 DAT_01268460[];

namespace RayBundleTraversal {

class PacketScalar {
    __m128 value;
public:
    PacketScalar(float f) { value = _mm_load_ss(&f); }
    PacketScalar(const __m128& v) : value(v) {}
    __forceinline __m128 spread() const { return _mm_shuffle_ps(value,value,0); }
};
class PacketVector;
class PacketMask {
    __m128 value;
    friend class PacketVector;
public:
    enum Bits { All=15 };
    __forceinline void combine(const PacketMask& a,const PacketMask& b) { value=_mm_and_ps(a.value,b.value); }
    __forceinline void choose(const PacketMask& a,const PacketMask& b,const PacketMask& c) {
        value=_mm_or_ps(_mm_and_ps(c.value,b.value),_mm_andnot_ps(c.value,a.value));
    }
    __forceinline void load(Bits bits) { value=DAT_01268460[bits]; }
    __forceinline int any(Bits bits) const { return _mm_movemask_ps(value)&bits; }
    __forceinline int any() const { return _mm_movemask_ps(value); }
    __forceinline int bits() const { return _mm_movemask_ps(value); }
};
inline __m128 packetReciprocal(__m128 x) {
    __m128 r=_mm_rcp_ps(x);
    return _mm_sub_ps(_mm_add_ps(r,r),_mm_mul_ps(_mm_mul_ps(r,x),r));
}
inline __m128 packetInverseRoot(__m128 x) {
    __m128 r=_mm_rsqrt_ps(x);
    __m128 h=_mm_mul_ps(DAT_010c71d0,r);
    __m128 product=_mm_mul_ps(_mm_mul_ps(x,r),r);
    return _mm_mul_ps(h,_mm_sub_ps(DAT_010c71c0,product));
}
class PacketVector {
    __m128 value;
public:
    operator __m128() const { return value; }
    inline __m128& raw() { return value; }
    inline const __m128& raw() const { return value; }
    __forceinline void operator=(const PacketVector& x) { value=x.value; }
    __forceinline void operator=(const __m128& x) { raw()=x; }
    __forceinline float& operator()(int axis) { return reinterpret_cast<float*>(&value)[axis]; }
    __forceinline const float& operator()(int axis) const { return reinterpret_cast<const float*>(&value)[axis]; }
    __forceinline void fill(float x) { value=_mm_set_ps1(x); }
    __forceinline void clear() { value=_mm_setzero_ps(); }
    __forceinline void difference(const PacketVector& a,const PacketVector& b) { value=_mm_sub_ps(a.value,b.value); }
    __forceinline void product(const PacketVector& a,const PacketVector& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void product(const PacketScalar& a,const PacketVector& b) { value=_mm_mul_ps(a.spread(),b.value); }
    __forceinline void accumulate(const PacketVector& a,const PacketVector& b) { value=_mm_add_ps(value,_mm_mul_ps(a.value,b.value)); }
    __forceinline void multiply(const PacketVector& a) { value=_mm_mul_ps(value,a.value); }
    __forceinline void subtract(const PacketVector& a) { value=_mm_sub_ps(value,a.value); }
    __forceinline void add(const PacketVector& a) { value=_mm_add_ps(value,a.value); }
    __forceinline void affine(const PacketVector& a,const PacketVector& b,const PacketVector& c) { value=_mm_add_ps(a.value,_mm_mul_ps(b.value,c.value)); }
    __forceinline void inverse(const PacketVector& a) { value=packetReciprocal(a.value); }
    __forceinline void inverseRoot(const PacketVector& a) { value=packetInverseRoot(a.value); }
    __forceinline void minimum(const PacketVector& a,const PacketVector& b) { value=_mm_min_ps(a.raw(),b.raw()); }
    __forceinline void maximum(const PacketVector& a,const PacketVector& b) { value=_mm_max_ps(a.raw(),b.raw()); }
    __forceinline void choose(const PacketVector& a,const PacketVector& b,const PacketMask& m) {
        value=_mm_or_ps(_mm_and_ps(m.value,b.value),_mm_andnot_ps(m.value,a.value));
    }
    __forceinline PacketMask equal(const PacketVector& a) const { PacketMask m; m.value=_mm_cmpeq_ps(value,a.value); return m; }
    __forceinline PacketMask less(const PacketVector& a) const { PacketMask m; m.value=_mm_cmplt_ps(value,a.value); return m; }
    __forceinline PacketMask lessEqual(const PacketVector& a) const { PacketMask m; m.value=_mm_cmple_ps(value,a.value); return m; }
    __forceinline PacketMask greaterEqual(const PacketVector& a) const { return a.lessEqual(*this); }
    __forceinline void broadcast(const PacketVector& a,int axis) {
        switch(axis) {
            case 0: value=_mm_shuffle_ps(a.value,a.value,0); break;
            case 1: value=_mm_shuffle_ps(a.value,a.value,0x55); break;
            case 2: value=_mm_shuffle_ps(a.value,a.value,0xaa); break;
            default: value=_mm_shuffle_ps(a.value,a.value,0xff); break;
        }
    }
    static __forceinline const PacketVector& zero() { return reinterpret_cast<const PacketVector&>(::DAT_01267e30); }
};
struct PacketRays { PacketVector m_vec[3]; };
template<class T> class PacketField {
    T value;
public:
    __forceinline PacketField() {}
    __forceinline PacketField(T x) : value(x) {}
    __forceinline void operator=(T x) { value=x; }
    __forceinline T get() const { return value; }
    __forceinline T operator->() const { return value; }
    __forceinline operator T() const { return get(); }
};
class PacketNode {
    struct Pair3Pool { __declspec(align(8)) int tag; unsigned int count; };
    struct Branch { int offset; unsigned short minimum,maximum; };
    union { Pair3Pool leaf; Branch branch; } data;
public:
    __forceinline PacketNode() { data.leaf.tag=0x7fffffff; data.leaf.count=0; }
    __forceinline ~PacketNode() {}
    __forceinline int leafBits() const { return ~(data.leaf.tag>>31); }
    __forceinline int emptyBits() const { return ~(data.leaf.tag^0x7fffffff); }
    __forceinline int axis() const { return data.branch.offset&3; }
    __forceinline unsigned short lower() const { return data.branch.minimum; }
    __forceinline unsigned short upper() const { return data.branch.maximum; }
    __forceinline unsigned int primitive() const { return data.leaf.tag&0x7fffffff; }
    __forceinline unsigned int count() const { return data.leaf.count; }
    __forceinline PacketNode* left() const { return reinterpret_cast<PacketNode*>(reinterpret_cast<unsigned int>(this)+(data.branch.offset&0x7ffffffc)); }
    __forceinline PacketNode* right() const { return left()+1; }
};
struct PacketLeaf {
    __declspec(align(16)) unsigned short minimum[3];
    unsigned short keyLow;
    unsigned short maximum[3];
    unsigned short keyHigh;
    void operator=(const PacketLeaf& a) { *reinterpret_cast<__m128*>(this)=*reinterpret_cast<const __m128*>(&a); }
    __forceinline unsigned long key() const {
        union { unsigned long word; unsigned short halves[2]; } result;
        result.halves[0]=keyLow; result.halves[1]=keyHigh;
        return result.word;
    }
};
template<class T> struct PacketArray {
    PacketField<T*> data;
    PacketField<int> size,capacity;
    __forceinline T* begin() const { return data; }
};
struct PacketBox { PacketVector minimum,maximum; };
class PacketTree {
public:
    __declspec(align(16)) PacketArray<PacketNode> nodes;
    int m_iNumNodes;
    int primitiveCount,regularCount,emptyCount;
    PacketArray<PacketLeaf> projected;
    PacketBox bounds;
    __forceinline const PacketNode* root() const { return nodes.begin(); }
    __forceinline const PacketLeaf* entries() const { return projected.begin(); }
    __forceinline const PacketBox& box() const { return bounds; }
};
struct PacketState {
    PacketField<const PacketNode*> node;
    PacketVector nearValue,farValue;
    PacketMask active;
    void assign(const PacketNode* n,const PacketVector& low,const PacketVector& high,PacketMask& mask) {
        node=n; nearValue=low; farValue=high; active=mask;
    }
};
class PacketCollector {
public:
    virtual ~PacketCollector() {}
    virtual void hit(unsigned long key,const PacketMask& mask)=0;
    virtual void fractions(PacketVector& value) const=0;
};
class PacketResult {
    char value;
public:
    inline PacketResult() {}
    inline PacketResult(bool b) { value=static_cast<char>(b); }
    inline operator bool() const { return value!=0; }
};
inline const PacketNode* readPacketNode(const PacketNode* n,PacketResult wait=true) { return n; }
__forceinline const PacketNode* packetLeft(const PacketNode& cached,const PacketNode* n) { return n->left(); }
__forceinline const PacketNode* packetRight(const PacketNode& cached,const PacketNode* n) { return n->right(); }
__forceinline const PacketLeaf* packetEntry(const PacketNode& n,const PacketLeaf* data,int index=0) {
    int first=(int)n.primitive();
    const PacketLeaf* p=data+first+index;
    return p;
}
class PacketIntegers {
    __m128i value;
public:
    inline void clear() { value=_mm_setzero_si128(); }
    inline void lowWords(const PacketIntegers& a,const PacketIntegers& b) { value=_mm_unpacklo_epi16(a.value,b.value); }
    inline void highWords(const PacketIntegers& a,const PacketIntegers& b) { value=_mm_unpackhi_epi16(a.value,b.value); }
    inline void floats(PacketVector& output) const {
        const __m128 factor={1.0e16f,1.0e16f,1.0e16f,1.0e16f};
        __m128i source=value;
        __m128i high=_mm_srli_epi32(source,16);
        __m128i low=_mm_srli_epi32(_mm_slli_epi32(source,16),16);
        __m128 upper=_mm_mul_ps(_mm_cvtepi32_ps(high),factor);
        __m128 lower=_mm_cvtepi32_ps(low);
        output.raw()=_mm_add_ps(upper,lower);
    }
};
__forceinline void packetUnpack(const PacketLeaf* leaf,PacketVector& low,PacketVector& high) {
    PacketIntegers packed=*reinterpret_cast<const PacketIntegers*>(leaf);
    PacketIntegers zero; zero.clear();
    PacketIntegers a,b; a.lowWords(packed,zero); b.highWords(packed,zero);
    a.floats(low); b.floats(high);
}
__forceinline __m128 packetQuantizer() {
    return ::DAT_011b6de0;
}
__forceinline void packetBounds(const PacketLeaf* leaf,PacketVector* __restrict out,const PacketVector& origin,const PacketVector& extent) {
    PacketVector scale; scale.raw()=packetQuantizer(); scale.multiply(extent);
    PacketVector low,high; packetUnpack(leaf,low,high);
    low.affine(origin,scale,low); high.affine(origin,scale,high);
    out[0].broadcast(low,0); out[1].broadcast(high,0);
    out[2].broadcast(low,1); out[3].broadcast(high,1);
    out[4].broadcast(low,2); out[5].broadcast(high,2);
}
__forceinline PacketMask packetSlabs(const PacketRays& start,const PacketRays& inverse,const PacketVector& lowInput,const PacketVector& highInput,const PacketVector* bounds) {
    PacketVector low=lowInput,high=highInput;
    PacketMask valid; valid.load(PacketMask::All);
    for(int axis=0;axis<3;++axis) {
        PacketVector a,b; a=*bounds++; b=*bounds++;
        PacketVector entry,exit,ta,tb;
        ta.difference(a,start.m_vec[axis]); tb.difference(b,start.m_vec[axis]);
        ta.multiply(inverse.m_vec[axis]); tb.multiply(inverse.m_vec[axis]);
        PacketVector zero; zero.clear();
        PacketMask positive=inverse.m_vec[axis].greaterEqual(zero);
        PacketMask flat=inverse.m_vec[axis].equal(zero);
        PacketMask inside=start.m_vec[axis].lessEqual(b);
        inside.combine(inside,start.m_vec[axis].greaterEqual(a));
        PacketMask accepted; accepted.choose(valid,inside,flat);
        valid.combine(valid,accepted);
        entry.choose(tb,ta,positive); exit.choose(ta,tb,positive);
        entry.choose(entry,low,flat); exit.choose(exit,high,flat);
        low.maximum(entry,low); high.minimum(exit,high);
    }
    PacketMask result=low.less(high); result.combine(result,valid); return result;
}

static __forceinline float decodeSplit(unsigned short value, float origin, float extent)
{
    return value / 65535.0 * extent + origin;
}
// @fnv 0x00d99570
extern "C" PacketResult __cdecl FUN_00d99570(const PacketTree* tree,
    const PacketRays& start, const PacketRays& finish,
    PacketCollector* collector, PacketMask::Bits lanes)
{
    const PacketNode* root = tree->root();
    const PacketLeaf* leaves = tree->entries();
    const PacketVector origin = tree->box().minimum;
    PacketVector extent; extent.difference(tree->box().maximum, tree->box().minimum);
    int capacity = tree->m_iNumNodes > 0 ? tree->m_iNumNodes : 128;
    const PacketNode* node = root;
    __declspec(align(16)) PacketNode cached = *readPacketNode(root);
    ::AllocHolder* arena = ::FUN_00c85750();
    PacketState* base = reinterpret_cast<PacketState*>(arena->unk00);
    arena->unk00 += (capacity * sizeof(PacketState) + 127) & ~127;
    PacketState* stack = base;
    const PacketRays& from = start;
    PacketVector zero = PacketVector::zero();
    PacketMask active; active.load(lanes);
    PacketRays direction;
    direction.m_vec[0].difference(finish.m_vec[0],start.m_vec[0]);
    direction.m_vec[1].difference(finish.m_vec[1],start.m_vec[1]);
    direction.m_vec[2].difference(finish.m_vec[2],start.m_vec[2]);
    PacketVector squared;
    squared.product(direction.m_vec[0],direction.m_vec[0]);
    squared.accumulate(direction.m_vec[1],direction.m_vec[1]);
    squared.accumulate(direction.m_vec[2],direction.m_vec[2]);
    PacketVector inverseLength; inverseLength.inverseRoot(squared);
    PacketVector length; length.inverse(inverseLength);
    direction.m_vec[0].multiply(inverseLength);
    direction.m_vec[1].multiply(inverseLength);
    direction.m_vec[2].multiply(inverseLength);
    PacketVector nearValue; nearValue.clear();
    PacketVector farValue = length;
    __m128 fraction = {1.0f/65535.0f,1.0f/65535.0f,1.0f/65535.0f,1.0f/65535.0f};
    PacketVector fractionVector; fractionVector.raw() = fraction;
    PacketRays inverse, coefficientA, coefficientB;
    for (int axis=0; axis<3; ++axis) {
        PacketVector one; one.raw() = ::DAT_010c7170;
        PacketMask flat = direction.m_vec[axis].equal(zero);
        PacketVector safe; safe.choose(direction.m_vec[axis],one,flat);
        PacketVector inverseSafe; inverseSafe.inverse(safe);
        PacketVector masked; masked.choose(inverseSafe,zero,flat);
        inverse.m_vec[axis] = masked;
        PacketVector scaled; scaled.product(extent(axis),masked);
        scaled.multiply(fractionVector);
        coefficientA.m_vec[axis] = scaled;
        PacketVector shifted; shifted.fill(origin(axis));
        shifted.subtract(from.m_vec[axis]);
        shifted.multiply(masked);
        coefficientB.m_vec[axis] = shifted;
    }
    PacketVector fractions; fractions.fill(1.0f);
    PacketVector clipped; clipped.product(fractions,length);
    PacketVector effectiveFar; effectiveFar.minimum(clipped,farValue);
    for (;;) {
        while (~cached.leafBits()) {
            const PacketNode* left = packetLeft(cached,node);
            const PacketNode* right = packetRight(cached,node);
            int axis = cached.axis();
            if (direction.m_vec[axis].equal(zero).any(static_cast<PacketMask::Bits>(active.bits()))) {
                float splitLow = decodeSplit(cached.lower(),origin(axis),extent(axis));
                float splitHigh = decodeSplit(cached.upper(),origin(axis),extent(axis));
                PacketVector low,high; low.fill(splitLow); high.fill(splitHigh);
                float tolerance = 0.00001f;
                PacketVector epsilon; epsilon.fill(tolerance);
                low.subtract(epsilon); high.add(epsilon);
                PacketMask insideLeft = from.m_vec[axis].lessEqual(high);
                PacketMask insideRight = from.m_vec[axis].greaterEqual(low);
                PacketMask wantLeft,wantRight;
                wantLeft.combine(insideLeft,active); wantRight.combine(insideRight,active);
                int l = wantLeft.any(); int r = wantRight.any();
                if (l && r) {
                    node = left;
                    stack->assign(right,nearValue,farValue,wantRight);
                    ++stack;
                    active = wantLeft;
                } else if (l || r) {
                    node = l ? left : right;
                } else goto pop;
                cached = *readPacketNode(node);
                continue;
            } else {
                PacketVector low, high;
                low.fill(float(cached.lower())); high.fill(float(cached.upper()));
                PacketVector tLow,tHigh;
                tLow.affine(coefficientB.m_vec[axis],coefficientA.m_vec[axis],low);
                tHigh.affine(coefficientB.m_vec[axis],coefficientA.m_vec[axis],high);
                PacketMask positive = direction.m_vec[axis].greaterEqual(zero);
                positive.combine(positive,active);
                const PacketNode* first; const PacketNode* second;
                if (positive.any()) { first=left; second=right; }
                else { first=right; second=left; }
                PacketVector entry,exit;
                entry.choose(tHigh,tLow,positive); exit.choose(tLow,tHigh,positive);
                PacketMask exitPastNear = exit.greaterEqual(nearValue);
                PacketMask entryBeforeFar = entry.lessEqual(effectiveFar);
                PacketMask wantFirst,wantSecond;
                wantFirst.combine(active,exitPastNear); wantSecond.combine(active,entryBeforeFar);
                int f=wantFirst.any(), s=wantSecond.any();
                int both=f && s;
                if (both) {
                    PacketVector nextNear; nextNear.maximum(nearValue,entry);
                    stack->assign(second,nextNear,farValue,wantSecond);
                    ++stack;
                    node=first;
                    farValue.minimum(exit,farValue);
                    active=wantFirst;
                    PacketVector distance; distance.product(fractions,length);
                    effectiveFar.minimum(distance,farValue);
                } else if(f) node=first;
                else node=second;
                cached=*readPacketNode(node);
            }
        }
        if (~cached.emptyBits()) {
            int count=cached.count();
            for(int index=0;index<count;++index) {
                const PacketLeaf* leaf=packetEntry(cached,leaves,index);
                unsigned long key=leaf->key();
                PacketVector bounds[6];
                packetBounds(leaf,bounds,origin,extent);
                PacketMask hit=packetSlabs(from,inverse,nearValue,effectiveFar,bounds);
                hit.combine(hit,active);
                if(hit.any()) {
                    collector->hit(key,hit);
                    collector->fractions(fractions);
                }
            }
        }
    pop:
        if(stack==base) break;
        --stack;
        node=stack->node;
        cached=*readPacketNode(node);
        nearValue=stack->nearValue; farValue=stack->farValue; active=stack->active;
        PacketVector distance; distance.product(fractions,length);
        effectiveFar.minimum(distance,farValue);
        active.combine(nearValue.less(effectiveFar),active);
        if(!active.any()) goto pop;
    }
    ::FUN_00c85750()->unk00=reinterpret_cast<int>(base);
    return true;
}

}

namespace linear_cast_d9a2a0 {
using ::__m128;
struct ContextArg { int* value; };
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);

extern "C" __m128 DAT_010ec7f0;

struct SimdReal
{
    __m128 m_vValue;
    SimdReal() {}
    SimdReal(float v) { m_vValue = _mm_load_ss(&v); }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};


struct Vec4
{
    __m128 m_vComponents;

    Vec4& operator=(const Vec4& v) { m_vComponents = v.m_vComponents; return *this; }
    void setSub4(const Vec4& a, const Vec4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void setAdd4(const Vec4& a, const Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    SimdReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        SimdReal s;
        s.m_vValue = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2)));
        return s;
    }
    void setInterpolate4(const Vec4& a, const Vec4& b, const SimdReal& t)
    {
        __m128 tt = _mm_shuffle_ps(t.m_vValue, t.m_vValue, 0);
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, tt), a.m_vComponents), _mm_mul_ps(b.m_vComponents, tt));
    }
    void setMul4(const SimdReal& r, const Vec4& a)
    {
        __m128 rr = _mm_shuffle_ps(r.m_vValue, r.m_vValue, 0);
        m_vComponents = _mm_mul_ps(rr, a.m_vComponents);
    }
};

struct TargetNode {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Vec4 m_pos;
};

struct Segment {
    Vec4 m_kRayStart;
    Vec4 m_kRayEnd;
};

struct Spline3 {
    Vec4 m_mid;
    Vec4 m_ctrl;
    Vec4 m_tangent;
};

struct PathIface {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getSegment(TargetNode* node, float t, Segment* out);
    int unk04;
    int unk08;
    int unk0C;
};

struct Param2 {
    PathIface* m_path;
    int unk04;
    TargetNode* m_node;
};

struct Param3 {
    Vec4 m_pos;
    float m_f10;
    float m_f14;
};

struct Embedded5 {
    int unk00;
    int unk04;
    union {
        int unk08;
        float m_fScalar;
    };
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m20;
    __m128 m30;
    __m128 m40;
};

extern "C" int __cdecl FUN_00d1c2b0(int a1, Segment* seg, Spline3* spl, ContextArg a4, float a5, int a6, int a7);

struct PathBuilder {
    int unk00;
    int unk04;
    Param3* m_p3;
    int m_p4;
    volatile int m_p7;
    int m_p8;
    Param2* m_p2;
    int unk1C;
    Embedded5 m_usTrailingValue;
    Vec4 m_diff;
    float m_f80;
    float m_f84;
    int m_p6;

    int FUN_00d9a2a0(int a1, Param2* a2, Param3* a3, int a4, Embedded5* a5, int a6, int a7, volatile int a8);
};
// @fnv 0x00d9a2a0
int PathBuilder::FUN_00d9a2a0(int a1, Param2* a2, Param3* a3, int a4, Embedded5* a5, int a6, int a7, volatile int a8) {
    m_p7 = a7;
    m_p8 = a8;
    m_p2 = a2;
    m_p4 = a4;
    m_p3 = a3;
    unk1C = a2->m_path->unk0C;
    m_usTrailingValue.unk00 = a5->unk00;
    m_usTrailingValue.unk04 = a5->unk04;
    m_usTrailingValue.unk08 = a5->unk08;
    m_usTrailingValue.unk0C = a5->unk0C;
    m_usTrailingValue.unk10 = a5->unk10;
    m_usTrailingValue.unk14 = a5->unk14;
    m_usTrailingValue.m20 = a5->m20;
    m_usTrailingValue.m30 = a5->m30;
    m_usTrailingValue.m40 = a5->m40;
    m_p6 = a6;

    float t = a3->m_f14;
    Vec4 diff;
    diff.setSub4(a3->m_pos, a2->m_node->m_pos);
    m_diff = diff;
    m_f84 = diff.length3();
    m_usTrailingValue.m_fScalar = t;
    Segment seg;
    a2->m_path->getSegment(a2->m_node, a3->m_f14, &seg);
    Spline3 spl;
    SimdReal half(0.5f);
    spl.m_mid.setInterpolate4(seg.m_kRayStart, seg.m_kRayEnd, half);
    spl.m_ctrl.setAdd4(spl.m_mid, diff);
    Vec4 d;
    d.setSub4(seg.m_kRayEnd, seg.m_kRayStart);
    spl.m_tangent.setMul4(SimdReal(0.5f), d);
    m_f80 = a3->m_f10;
    ContextArg context = { &unk04 };
    return FUN_00d1c2b0(a1, &seg, &spl, context, a3->m_f10, 0, 0);
}

}

extern "C" __m128 DAT_01017d10;

struct RoundedValue {float value;RoundedValue(float x):value(x){} operator float() const{return value;} bool above(float epsilon)const{return epsilon<value;} };
struct Point {
    union { __m128 value; float lane[4]; };
    float& at(int index) { return lane[index]; }
    float at(int index) const { return lane[index]; }
    void add(const Point& a,const Point& b) { value = ::_mm_add_ps(a.value,b.value); }
    void difference(const Point& a,const Point& b) { value = ::_mm_sub_ps(a.value,b.value); }
    void absolute() { value = ::_mm_and_ps(value,DAT_01017d10); }
    void scale(float scale) {
        __m128 factor = ::_mm_load_ss(&scale);
        value = ::_mm_mul_ps(::_mm_shuffle_ps(factor,factor,0),value);
    }
};
inline __m128 scalar(float f);
struct Bounds {
    Point lower,upper;
    void center(Point& result) const {Point sum;sum.add(lower,upper);result.value=::_mm_mul_ps(::_mm_shuffle_ps(scalar(0.5f),scalar(0.5f),0),sum.value);}
    void empty() { lower.value=::_mm_set_ps1(3.402820018375656e38f); upper.value=::_mm_set_ps1(-3.402820018375656e38f); }
    void include(const Point& p) { lower.value=::_mm_min_ps(lower.value,p.value); upper.value=::_mm_max_ps(upper.value,p.value); }
};
struct IndexList { int* data; int size; int capacity; int& operator[](int n) {return data[n];} };
inline void exchangeValues(int& a,int& b) {int t=a;a=b;b=t;}
inline __m128 scalar(float f) {return ::_mm_load_ss(&f);}


inline void centerSwap(Point& result,const Bounds& b) {__m128 sum=::_mm_add_ps(b.lower.value,b.upper.value);__m128 factor=scalar(0.5f);factor=::_mm_shuffle_ps(factor,factor,0);result.value=::_mm_mul_ps(factor,sum);}

// @fnv 0x00d9a520
extern "C" void __cdecl FUN_00d9a520(const Bounds* bounds,const Bounds* prims,IndexList* indices,int start,int count,Bounds* left,Bounds* right,int* leftCount,int* rightCount)
{
    static const float emptyMinimum = 3.402820018375656e38f;
    static const float emptyMaximum = -3.402820018375656e38f;
    __m128 lo=::_mm_set_ps1(emptyMinimum);
    __m128 hi=::_mm_set_ps1(emptyMaximum);
    left->lower.value=lo; left->upper.value=hi;
    right->lower.value=lo; right->upper.value=hi;
    Point sum,extent;
    sum.add(bounds->lower,bounds->upper);
    extent.difference(bounds->upper,bounds->lower);
    extent.absolute();
    int axis;
    if (extent.at(0)<extent.at(1)) axis=extent.at(1)<extent.at(2)?2:1;
    else axis=extent.at(0)<extent.at(2)?2:0;
    float mid=sum.at(axis)*0.5f;
    int cursor;
    float spanMax=bounds->upper.at(axis)-mid;RoundedValue spanMin(mid-bounds->lower.at(axis));
    if (spanMax>2.384185791015625e-07f && spanMin>2.384185791015625e-07f) {
        int lo=start;
        int hi=start+count-1;
        do {
            Point leftCenter,rightCenter;
            prims[(*indices)[lo]].center(leftCenter);
            while (leftCenter.at(axis)<=mid) {
                left->include(leftCenter);
                ++lo;
                prims[(*indices)[lo]].center(leftCenter);
            }
            prims[(*indices)[hi]].center(rightCenter);
            while (rightCenter.at(axis)>mid) {
                right->include(rightCenter);
                --hi;
                prims[(*indices)[hi]].center(rightCenter);
            }
            if(lo>=hi)break;
            exchangeValues((*indices)[lo],(*indices)[hi]);
            centerSwap(leftCenter,prims[(*indices)[lo]]);
            prims[(*indices)[hi]].center(rightCenter);
            left->include(leftCenter);
            right->include(rightCenter);
            --hi;++lo;
        } while(lo<=hi);
        cursor=lo;
    } else {
        cursor=start+(count>>1);
        left->lower.value=bounds->lower.value;left->upper.value=bounds->upper.value;
        right->lower.value=bounds->lower.value;right->upper.value=bounds->upper.value;
    }
    int taken=cursor-start;
    *leftCount=taken;
    *rightCount=count-taken;
}

static const float partitionLowLimit=3.402820018375656e38f;
static const float partitionHighLimit=-3.402820018375656e38f;
extern "C" __m128 _mm_setr_ps(float,float,float,float);
struct __declspec(align(16)) PartitionVector {
    union { __m128 value; struct { float x,y,z,w; }; };
    void operator=(const PartitionVector& rhs) { value = rhs.value; }
    void set(__m128 v) { value = v; }
    __m128 get() const { return value; }
    const float& component(int axis) const { return (&x)[axis]; }
    void setAdd4(const PartitionVector& a, const PartitionVector& b) { set(::_mm_add_ps(a.get(),b.get())); }
    void setSub4(const PartitionVector& a, const PartitionVector& b) { set(::_mm_sub_ps(a.get(),b.get())); }
    void setAbs4(const PartitionVector& a) { set(::_mm_and_ps(a.get(), DAT_01017d10)); }
    void add4(const PartitionVector& b) { set(::_mm_add_ps(get(),b.get())); }
    void mul4(const __m128& a) { set(::_mm_mul_ps(get(),::_mm_shuffle_ps(a,a,0))); }
    void set(float a, float b, float c, float d) { set(_mm_setr_ps(a,b,c,d)); }
};
struct PartitionBounds {
    PartitionVector minimum;
    PartitionVector maximum;
};
struct PartitionQuantizedBounds {
    unsigned short minX, minY, minZ;
    unsigned short maxX, maxY, maxZ;
};
struct PartitionIndices { unsigned short* data; };
struct PartitionScalar { __m128 value;
    __forceinline PartitionScalar(float f) { value = ::_mm_load_ss(&f); }
};
__forceinline void partitionCenter(const PartitionQuantizedBounds& bounds, PartitionVector& center) {
    center.set(float(bounds.minX),float(bounds.minY),float(bounds.minZ),0.0f);
    PartitionVector other;
    other.set(float(bounds.maxX),float(bounds.maxY),float(bounds.maxZ),0.0f);
    center.add4(other);
    center.mul4(PartitionScalar(0.5f).value);
}
__forceinline void partitionInclude(PartitionBounds& bounds, __m128 point)
{
    bounds.minimum.set(::_mm_min_ps(bounds.minimum.get(), point));
    bounds.maximum.set(::_mm_max_ps(bounds.maximum.get(), point));
}
__forceinline void partitionSwap(unsigned short& a, unsigned short& b) {
    unsigned short saved = a;
    a = b;
    b = saved;
}
__forceinline void partitionLeftCenter(const PartitionQuantizedBounds& bounds, PartitionVector& center) {
    float v3 = float(bounds.minX);
    float v4 = float(bounds.minY);
    float v5 = float(bounds.minZ);
    float v0 = float(bounds.maxX);
    float v1 = float(bounds.maxY);
    float v2 = float(bounds.maxZ);
    center.set(v0,v1,v2,0.0f);
    PartitionVector other;
    other.set(v3,v4,v5,0.0f);
    center.add4(other);
    center.mul4(PartitionScalar(0.5f).value);
}
__forceinline void scanPartitionLeft(const PartitionQuantizedBounds* items, PartitionIndices& indices,
    int& left, PartitionVector& leftCenter, int axis, float split, PartitionBounds& leftBounds) {
    while (true) {
        partitionLeftCenter(items[indices.data[left]],leftCenter);
        if (leftCenter.component(axis) <= split) {
            ++left;
            partitionInclude(leftBounds, leftCenter.get());
        } else break;
    }
}
// @fnv 0x00d9a850
extern "C" void __cdecl FUN_00d9a850(const PartitionBounds& bounds, const PartitionQuantizedBounds* items,
    PartitionIndices& indices, unsigned short start, int count,
    PartitionBounds& leftBounds, PartitionBounds& rightBounds, int& leftCount, int& rightCount)
{
    __m128 low=::_mm_set_ps1(partitionLowLimit);
    __m128 high=::_mm_set_ps1(partitionHighLimit);
    leftBounds.minimum.set(low);
    leftBounds.maximum.set(high);
    rightBounds.minimum.set(low);
    rightBounds.maximum.set(high);
    int axis;
    float split;
    {
    PartitionVector sum;
    sum.setAdd4(bounds.minimum,bounds.maximum);
    PartitionVector extent;
    extent.setSub4(bounds.maximum,bounds.minimum);
    extent.setAbs4(extent);
    axis = extent.component(0) < extent.component(1)
        ? (extent.component(1) < extent.component(2) ? 2 : 1)
        : (extent.component(0) < extent.component(2) ? 2 : 0);
    split = float(sum.component(axis) * 0.5);
    }
    int left;
    if (float(bounds.maximum.component(axis) - split) > 2.384185791015625e-7f &&
        float(split - bounds.minimum.component(axis)) > 2.384185791015625e-7f) {
        try {
        left = start;
        int right = start + count - 1;
        do {
            PartitionVector leftCenter, rightCenter;
            scanPartitionLeft(items,indices,left,leftCenter,axis,split,leftBounds);
            while (true) {
                partitionCenter(items[indices.data[right]],rightCenter);
                if (rightCenter.component(axis) > split) {
                    --right;
                    partitionInclude(rightBounds, rightCenter.get());
                } else break;
            }
            if (left >= right) break;
            partitionSwap(indices.data[left], indices.data[right]);
            
            partitionCenter(items[indices.data[left]],leftCenter);
            partitionCenter(items[indices.data[right]],rightCenter);
            partitionInclude(leftBounds, leftCenter.get());
            partitionInclude(rightBounds, rightCenter.get());
            ++left;
            --right;
        } while (left <= right);
        } catch (...) { throw; }
    } else {
        left = start + (count >> 1);
        leftBounds = bounds;
        rightBounds = bounds;
    }
    leftCount = left - start;
    rightCount = count - leftCount;
}

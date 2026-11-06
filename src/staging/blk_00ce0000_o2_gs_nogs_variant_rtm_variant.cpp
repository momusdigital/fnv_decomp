// src/staging/blk_00ce0000_o2_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ce0000_o2_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00ce0000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00ce0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010cc164;
void __cdecl FUN_00d86220();
struct FUN_00cf45d0_class {
    int vtable;
    FUN_00cf45d0_class();
};
struct hkReferencedObject {
    void RetainReference();
};
struct FUN_00cf4ca0_class {
    int m_auiShapeKeys[6];
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    void FUN_00cf4ca0();
};
struct FUN_00d06d50_cls {
    int __thiscall FindClass(int);
};
extern "C" void __cdecl FUN_00cf6920(int, int, int);
void __cdecl FUN_00cf6950(int a, int b);
struct FUN_00cf86f0_class {
    int IsFieldEqual();
};
unsigned short FUN_00cfcb80(unsigned short a, unsigned short b);
extern int DAT_010cb864;
struct FUN_00ce4ae0_cls {
    int __thiscall FUN_00ce4ae0(int);
    void __thiscall FUN_00ce5310();
};
struct FUN_00ce4a20_cls {
    int m_kPointA;
    short m_kPointB;
    short m_iThirdValue;
    int m_iFourthElementInteger;
    int __thiscall FUN_00ce4a20(int a);
};
extern int DAT_0102e378;
void __cdecl finishLoadedObject_hkReferencedObject(int* a);
struct FUN_00cf69c0_class {
    int m_kPointA;
    int m_auiShapeKeys;
    int m_kPointB;
    int __thiscall FUN_00cf69c0(int a);
};
int __cdecl FUN_00cb0fa0(int a, int b);
struct FUN_00cf86e0_class {
    void FUN_00cf86e0(float f);
};
extern int DAT_010cc2e0;
struct FUN_00cf4820_class {
    int* vtbl;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00cf4820_class();
};
extern int DAT_0102e388;
struct FUN_00cf86d0_cls {
    void FUN_00cf86d0();
};
// FUN_00ce29e0: member function that (re)initialises the object.
//   - installs the base vtable pointer at [this],
//   - calls the constructor of the sub-object living at this+0x10,
//   - then installs the vtable pointer of the derived class at [this].
extern int DAT_010cb864;
extern int DAT_0102e388;
// Sub-object at +0x10; FUN_00ce5370 is the game's constructor for it.
struct FUN_00ce5370_cls {
    void FUN_00ce5370();
};
struct FUN_00ce29e0_cls {
    int* m_pVTable;          // +0x00
    int unk04;               // +0x04
    int unk08;               // +0x08
    int unk0C;               // +0x0C
    FUN_00ce5370_cls m_sub;  // +0x10
    void FUN_00ce29e0();
};
struct FnvSpawnedObject;
struct FnvProbe {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char* Match(FnvSpawnedObject** ref);
    unsigned char* Check(FnvSpawnedObject** ref);
};
struct FnvSpawnedObject {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FnvProbe m_10;
    FnvProbe m_20;
    unsigned char* Check(FnvSpawnedObject** ref);
};
bool __cdecl FUN_00ce2a00(int unused, FnvSpawnedObject* obj);
void __cdecl FUN_00ce2ca0(int a1, int a2, int* a3, int a4);
void __cdecl FUN_00ce2cf0(int param_1, int param_2, int param_3);
void __cdecl FUN_00ce3090(int a1, int a2, int a3, int a4, int a5, int a6);
void __cdecl FUN_00ce4330(int a1, int a2, int a3, int a4);
struct FnvKeyRec {
    unsigned short m_iOwnerObjectOffset;
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
};
struct FUN_00ce5480_cls {
    int unk00;
    int unk04;
    FnvKeyRec* m_pRecords;
    int m_uiItemCount;
};
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pBox);
void __cdecl FUN_00d86160(void* stream, void* self);
struct DragBinaryStreamView {
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int (__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes, unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};
struct DragStreamView {
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};
struct FUN_00cf4490_cls {
    char unk00[0x14];
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    void FUN_00cf4490(void* stream);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268740;
CpuOpaque* __cdecl FUN_00cf45f0();
struct PacketSerializer {
    int metadata, bytesWritten, reserved;
    typedef int (__cdecl *Fn)(PacketSerializer*, const void*, int, int*, int);
    Fn write;
};
struct SerializedObject { int base00,base04,base08,base0C,base10,word14,word18;void __thiscall SerializeToStream(int source); };
extern "C" void __cdecl FUN_00d86160(int,SerializedObject*);
// Save a Havok-wrapped object: write its type id, then let a type-specific saver write the rest.
extern __declspec(thread) int g_iCF4BC0AllocTag;
struct CF4BC0AllocTagScope {
    int m_iSaved;

    CF4BC0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCF4BC0AllocTag;
        g_iCF4BC0AllocTag = aiAllocationTag;
    }
    ~CF4BC0AllocTagScope() { g_iCF4BC0AllocTag = m_iSaved; }
};
class CF4BC0BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CF4BC0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CF4BC0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CF4BC0Stream {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CF4BC0BinaryStream* m_pBackingStream;
};
template <class T>
inline void CF4BC0BinaryStreamSave(CF4BC0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T>
inline void CF4BC0SaveBinary(CF4BC0Stream& kStream, const T& value)
{
    CF4BC0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class CF4BC0Object {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual unsigned int GetSaveType();
};
class CF4BC0Saver {
public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void SaveBinary(CF4BC0Stream& kStream);

    void SetObject(CF4BC0Object* pkObject);
};
CF4BC0Saver* __cdecl CF4BC0CreateSaver(unsigned int uiType);
void __cdecl FUN_00cf4bc0(CF4BC0Stream& kStream, CF4BC0Object* pkObject);
extern int DAT_010cc2fc;
extern int DAT_0102e388;
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
AudioHolder* __cdecl FUN_00c85750() throw();
struct SubObject_b3813 {
    int unk00;
    void Release();
};
struct FUN_00cf4eb0_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    SubObject_b3813 m_sub;

    FUN_00cf4eb0_cls* Destroy(unsigned char acFlags);
};
struct S_00cf4f00 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    short unk24;
    unsigned short m_uiItemCount;
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
    unsigned int m_bits[1];
    void __thiscall ClearBit(unsigned int idx);
};
struct FUN_00cf4f30_class {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20;
    short unk24; unsigned short counter;
    int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C;
    unsigned int bits[8];
    void SetBit(unsigned int index);
};
struct FUN_00cf4f70_src
{
    int* m_00;
    int m_04;
};
int __cdecl CountBitsInWords(int* data, int count);
class FUN_00cf4f70_cls
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    int unk20;
    unsigned short unk24;
    unsigned short m_26;
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
    int m_50;

    void InitFromSource(FUN_00cf4f70_src* src);
};
struct FUN_00cf6980_class {
    virtual void cleanupLoadedObject_hkReferencedObject(int);
};
void __cdecl cleanupLoadedObject_hkReferencedObject(FUN_00cf6980_class* object);
extern int DAT_01268748;
int* __cdecl FUN_00cf6990();
extern int DAT_0102e378;
int* __cdecl FUN_00cf69b0();
extern int DAT_01268794;
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(int value);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(int value);
struct S_00cf6b50_Foo {
    int m_iWordAt00;
    short m_iWordAt04;
    unsigned short m_6;

    void __thiscall UpdateState(int a);
};
struct FUN_00cf6d50_cls {
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void FUN_00cf6d50();
};
struct FUN_00cf6f80_cls {
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    unsigned __int64 FUN_00cf6f80();
};
// FUN_00cf8710 : thiscall member returning a bool.
//
// Original shape (24 bytes):
//   fld  dword ptr [ecx+0x18]
//   fld  dword ptr [ecx+0x14]
//   fucompp
//   fnstsw ax
//   test ah,0x44
//   jp   <not equal>
//   mov  eax,1
//   ret
//   <not equal>: xor eax,eax ; ret
//
// i.e. a plain float equality test between the two float members at +0x14 and
// +0x18 of the object, with the +0x18 member loaded first.
struct FUN_00cf8710_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_14;
    float m_18;

    bool FUN_00cf8710();
};
class MemoryManager {
public:
    void* Allocate(unsigned int size);
};
extern MemoryManager _g_memoryManager;
class CF4840Saver {
public:
    void* operator new(unsigned int size) { return _g_memoryManager.Allocate(size); }
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Saver00 : CF4840Saver { Saver00() throw(); };
struct Saver01 : CF4840Saver { Saver01() throw(); };
struct Saver02 : CF4840Saver { Saver02() throw(); };
struct Saver03 : CF4840Saver { Saver03() throw(); };
struct Saver06 : CF4840Saver { Saver06() throw(); };
struct Saver07 : CF4840Saver { Saver07() throw(); };
struct Saver08 : CF4840Saver { Saver08() throw(); };
struct Saver09 : CF4840Saver { Saver09() throw(); };
struct Saver10 : CF4840Saver { Saver10() throw(); };
struct Saver12 : CF4840Saver { Saver12() throw(); };
struct Saver13 : CF4840Saver { Saver13() throw(); };
CF4840Saver* __cdecl CreateSaver(unsigned int uiType);
// Build the Havok object for a serialized node: find its creator, run it, keep the result and delete the creator.
extern __declspec(thread) int g_iF4A30AllocTag;
struct F4A30AllocTagScope {
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iF4A30AllocTag;
        g_iF4A30AllocTag = aiAllocationTag;
    }
    ~F4A30AllocTagScope() { g_iF4A30AllocTag = m_iSaved; }
};
class F4A30Result {
public:
    void RetainReference();
};
class F4A30Node {
public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual int GetTypeID();
};
class F4A30Creator {
public:
    virtual ~F4A30Creator();
    virtual void Create(int iFlags, void* pvContext);

    void Init(F4A30Node* pkNode);

    F4A30Result* m_pkResult;
};
F4A30Creator* __cdecl F4A30FindCreator(int iTypeID);
F4A30Result* CreateF4A30Result(F4A30Node* pkNode, void* pvContext);
void __cdecl FUN_00ce51f0();
void __cdecl FUN_00ce5300();
class FUN_00ce5360_This {
public:
// @fnv 0x00ce5360
    virtual ~FUN_00ce5360_This() {}
    unsigned int FUN_00ce5360(unsigned int arg);
};
unsigned int FUN_00ce5360_This::FUN_00ce5360(unsigned int arg) {
    return reinterpret_cast<unsigned int>(this);
}
class FUN_00ce9800_obj {
public:
    virtual ~FUN_00ce9800_obj();
};
void __cdecl DeleteObjectIfNotNull(FUN_00ce9800_obj* pkObject);
struct FUN_00ce9820_vt {
    virtual void FUN_00ce9820_v0(int a);
    virtual void FUN_00ce9820_v1(int a);
};
void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* p);
struct Stream;
typedef int (*StreamIOFunc)(Stream* stream, void* data, int size, int* count, int flag);
struct Stream {
    int unk00;
    int pos;
    int unk08;
    StreamIOFunc io;
};
struct StreamOwner {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    Stream* stream;
};
struct Record {
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
};
static inline void WriteData(Stream* s, void* data, int size)
{
    int count = size;
    s->pos += s->io(s, data, size, &count, 1);
}
void FUN_00cf09a0(StreamOwner* owner, Record* rec);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct ArrayData {
    unsigned int* m_data;
    int m_iElementCount;
};
// @fnv 0x00cf0e90
extern "C" unsigned int __cdecl SaveUIntArray(CF4BC0Stream& kStream, const ArrayData& kArray)
{
    unsigned int count = kArray.m_iElementCount;
    CF4BC0SaveBinary(kStream, count);

    unsigned int totalSize = count * sizeof(unsigned int);
    int i = 0;
    if ((int)count > 0) {
        do {
            unsigned int val = kArray.m_data[i];
            if ((unsigned char)kStream.unk1E4 != 1) {
                val = _byteswap_ulong(val);
            }
            CF4BC0SaveBinary(kStream, val);
            ++i;
        } while (i < (int)count);
    }

    return totalSize;
}
extern int DAT_010cc064;
struct FUN_00cdf560 {
    int m0;
    int m4;
    int m8;
    FUN_00cdf560(float);
};
struct FUN_00cf4190 : FUN_00cdf560 {
    FUN_00cf4190();
};
extern int DAT_01268730;
int* FUN_00cf41b0();
extern "C" void __cdecl FUN_00d86100(void* view, void* object);
struct BinaryStream {
    void* vtable;
    unsigned int absolutePosition;
    unsigned int (__cdecl *read)(BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest) {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, sizeof(T), &byteCount, 1);
    }
};
struct StreamView {
    BinaryStream* stream() {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct SerializedRecord {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int m_14, m_18, m_1c, m_20;
    void FUN_00cf41c0(StreamView* view);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268738;
CpuOpaque* __cdecl FUN_00cf43f0();
class NiBinaryStreamCF46 {
public:
    typedef unsigned int (*WriteFn)(NiBinaryStreamCF46* pkThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T>
inline void NiStreamSaveBinaryCF46(NiBinaryStreamCF46& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}
struct hkArchiveCF46 {
    int unk000[0x93];
    NiBinaryStreamCF46* m_stream;
};
void __cdecl FUN_00d86100(hkArchiveCF46* ar, void* obj);
class hkObjCF46 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_kPointA;
    int m_kPointB;

    void SaveToArchive(hkArchiveCF46* ar);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
unsigned int __cdecl FUN_00d87a40() throw();
struct hkCriticalSectionCF6B {
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6B {
    hkCriticalSectionCF6B* m_kCriticalSection;
    hkCriticalSectionLockCF6B(hkCriticalSectionCF6B* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6B() { LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection); }
};
struct hkMultiThreadCheckCF6B {
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const { return ((m_usMarkedForWrite >> 15) & 1) == 0; }

    void MarkForRead();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
unsigned int __cdecl FUN_00d87a40() throw();
struct hkCriticalSectionCF61 {
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF61 {
    hkCriticalSectionCF61* m_kCriticalSection;
    hkCriticalSectionLockCF61(hkCriticalSectionCF61* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF61() { LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection); }
};
struct hkMultiThreadCheckCF61 {
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const { return ((m_usMarkedForWrite >> 15) & 1) == 0; }

    bool IsCurrentThreadOwner();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
struct hkCriticalSectionCF6C {
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6C {
    hkCriticalSectionCF6C* m_kCriticalSection;
    hkCriticalSectionLockCF6C(hkCriticalSectionCF6C* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6C() { LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection); }
};
struct hkMultiThreadCheckCF6C {
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const { return ((m_usMarkedForWrite >> 15) & 1) == 0; }

    void FUN_00cf6c60();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
struct hkCriticalSectionCF6D {
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6D {
    hkCriticalSectionCF6D* m_kCriticalSection;
    hkCriticalSectionLockCF6D(hkCriticalSectionCF6D* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6D() { LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection); }
};
struct hkMultiThreadCheckCF6D {
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const { return ((m_usMarkedForWrite >> 15) & 1) == 0; }

    void FUN_00cf6cb0();
};
struct hkMultiThreadCheckCF6E {
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const { return ((m_usMarkedForWrite >> 15) & 1) == 0; }

    void ResetThreadCheck();
};
struct CC9F10Shape {
    void FUN_00c90510();
};
struct FUN_00cf7490_class {
    void FUN_00cf7490();
};
void __cdecl FUN_00c905b0(void);
void __cdecl FUN_00cf74a0(void);
struct hkOwnerCF74;
struct hkEntryCF74 {
    hkOwnerCF74* m_pOwnerObject;
    int unk04;
    unsigned int m_08;
};
struct hkOwnerCF74 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0;
    unsigned int m_d4;
};
int __cdecl FUN_00cf74b0(const hkEntryCF74& a, const hkEntryCF74& b);
struct hkBoolCF74 {
    char m_cBooleanValue;
    hkBoolCF74() {}
    hkBoolCF74(bool b) { m_cBooleanValue = (char)b; }
};
struct hkQualityCF74 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_priority;
};
struct hkEntityCF74 {
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    hkQualityCF74* m_quality;
};
struct hkPairCF74 {
    int unk00;
    hkEntityCF74* m_kPointA;
    hkEntityCF74* m_kPointB;
};
hkBoolCF74 __cdecl LessThanPairPriority(const hkPairCF74& x, const hkPairCF74& y);
void* __cdecl FUN_00cfb050(void* pvUnused, bool* pbOut, void* pvResult);
void FUN_00cfb060();
int __cdecl FUN_00cfb070(int a, int b, int c);
void __stdcall FUN_00cfc580(int, int, int, int, int);
extern int DAT_0102e388;
struct FUN_00cfc590_class {
    int* vtable;

    void __thiscall FUN_00cfc590();
};
extern int DAT_010cc86c;
struct S_00cfc5a0 {
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short unkA8;
    unsigned short unkAA;
};
struct FUN_00cfc5a0 {
    int* vtbl;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    S_00cfc5a0* unk10;
    S_00cfc5a0* unk14;
    unsigned short unk18;

    FUN_00cfc5a0(int a1, S_00cfc5a0* a2, S_00cfc5a0* a3);
};
void FUN_00cfdb40();
// Per-thread profiler ring: TlsGetValue(index) -> buffer with head@+4 / end@+0xc,
// 0xc-byte events {tag, timestamp, pad}.
struct CE0020Event {
    const char* m_pTag;
    unsigned int m_uiEventId;
    int m_unk08;
};
struct CE0020Buffer {
    int m_unk00;
    CE0020Event* m_pHead;
    int m_unk08;
    CE0020Event* m_pRecordEnd;
};
extern unsigned int DAT_0126835c;
extern char DAT_010cb81c[];
extern char DAT_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
__forceinline void CE0020TimerMark(const char* pTag)
{
    CE0020Buffer* pBuffer = (CE0020Buffer*)TlsGetValue(DAT_0126835c);
    CE0020Event* pEvent = pBuffer->m_pHead;
    if (pEvent < pBuffer->m_pRecordEnd)
    {
        pEvent->m_pTag = pTag;
        _ReadWriteBarrier();
        volatile unsigned int uiStamp = (unsigned int)__rdtsc();
        pEvent->m_uiEventId = uiStamp;
        pBuffer->m_pHead = pEvent + 1;
    }
}
// 4-byte flags struct passed by value (bool first member).
class CE0020Flag {
public:
    bool m_bEnableState;
    unsigned char m_unk01;
    unsigned char m_unk02;
    unsigned char m_unk03;
};
class CE0020ZeroInfo {
public:
    int m_unk00;
    int m_iArrayLength;
};
class CE0020Holder {
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Fill(CE0020Flag kFlags, CE0020ZeroInfo* pInfo);
};
class CE0020Arrays {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    float* m_pFloats;
};
class CE0020Target {
public:
    int unk00, unk04, unk08;
    CE0020Holder* m_pHolder;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    CE0020Arrays* m_pArrayData;
};
class CE0020Subject {
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void EnableConstraints();
};
void __cdecl FUN_00d27690(CE0020Target* pTarget, CE0020Subject* pSubject, int iType);
void __cdecl EnableConstraintsAndZeroArrays(CE0020Target* pTarget, CE0020Subject* pSubject);
void __cdecl FUN_00ce2d10();
void __cdecl FUN_00ce2f30();
struct NiBinaryStreamCF42 {
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamCF42* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
        unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
        unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T>
inline void NiStreamLoadBinaryCF42(NiBinaryStreamCF42& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
struct NiStreamCF42 {
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C;
    NiBinaryStreamCF42* m_pUnderlyingStream;

    NiBinaryStreamCF42* GetIstr() { return m_pUnderlyingStream; }
};
class SerializableCF42;
void __cdecl FUN_00d86160(NiStreamCF42& kStream, SerializableCF42* pkObject);
class SerializableCF42 {
public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned int m_uiValue1C;
    unsigned int m_uiValue20;

    void FUN_00cf4260(NiStreamCF42& kStream);
};
// bhkVelocityConstraintMotor ctor (hkpVelocityConstraintMotor chain):
// vptr(0), memSizeAndFlags(4), referenceCount(6), motor type(8), min/max force, tau, damping, velocity-clamp bool.
const void* DAT_010cc0ec[];
extern "C" void _ReadWriteBarrier();
struct hkBoolC43 {
    char v;
};
class FUN_00cf43b0 {
public:
    const void** m_vftable;              // 0x00
    unsigned short m_usMemSizeAndFlags;    // 0x04
    unsigned short m_sReferenceCount;     // 0x06
    unsigned char m_motorType;           // 0x08
    char unk09;
    char unk0A;
    char unk0B;
    float m_fMinForce;                    // 0x0c
    float m_fMaxForce;                    // 0x10
    float m_fTau;                         // 0x14
    float m_fMotorDamping;                     // 0x18
    char m_useVelocityClamp;             // 0x1c

    FUN_00cf43b0();
};
struct NiBinaryStreamCF44 {
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamCF44* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
        unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
        unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T>
inline void NiStreamLoadBinaryCF44(NiBinaryStreamCF44& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
struct NiStreamCF44 {
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248;
    NiBinaryStreamCF44* m_pUnderlyingStream;

    NiBinaryStreamCF44* GetIstr() { return m_pUnderlyingStream; }
};
class SerializableCF44;
void __cdecl FUN_00d86100(NiStreamCF44& kStream, SerializableCF44* pkObject);
class SerializableCF44 {
public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned char m_ucValue1C;

    void FUN_00cf4400(NiStreamCF44& kStream);
};
struct CF4BC0StreamInput {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248;
    CF4BC0BinaryStream* m_pUnderlyingStream;
    CF4BC0BinaryStream* m_pBackingStream;
};
class CF4BC0BinaryStreamIn {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(CF4BC0BinaryStreamIn*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Load(T* value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, value, sizeof(T), &uiSize, 1);
    }
};
class CF4BC0SaverLoader {
public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void LoadBinary(CF4BC0Stream& kStream);
    virtual void SaveBinary(CF4BC0Stream& kStream);
    hkReferencedObject* m_pPointer;
};
struct TagState { int oldTag; int newTag; };
__forceinline TagState GetTag(int tag) { TagState state={g_iCF4BC0AllocTag,tag}; return state; }
struct AllocScope { int saved; AllocScope(TagState t):saved(t.oldTag){g_iCF4BC0AllocTag=t.newTag;} ~AllocScope(){g_iCF4BC0AllocTag=saved;} };
hkReferencedObject* __cdecl FUN_00cf4af0(CF4BC0Stream& kStream);
void FUN_00cf6d10();
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class hkRefObjCF70 : public hkBaseObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpBroadPhaseListener {
public:
    virtual ~hkpBroadPhaseListener() {}
    virtual void AddCollisionPair(void* pair) = 0;
    virtual void RemoveCollisionPair(void* pair) = 0;
};
class ListenerCF70 : public hkRefObjCF70, public hkpBroadPhaseListener {
public:
    virtual void AddCollisionPair(void* pair);
    virtual void RemoveCollisionPair(void* pair);
};
class FUN_00cf7060 {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    ListenerCF70 m_kListener;

    ~FUN_00cf7060();
};
#include <xmmintrin.h>
extern const __m128 DAT_010c71c0;
extern const __m128 DAT_010c71d0;
struct SimdReal {
    __m128 m_vValue;
    __forceinline SimdReal(__m128 r) : m_vValue(r) {}
    __forceinline operator __m128() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
};
struct FourFloatVector {
    __m128 m_vComponents;

    __forceinline SimdReal lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        return SimdReal(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s));
    }
    __forceinline void setXYZ_W(__m128 xyz, __m128 w)
    {
        m_vComponents = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, w), 0xc4);
    }
    __forceinline void setSqrtInverse4(const FourFloatVector& v)
    {
        __m128 e = _mm_rsqrt_ps(v.m_vComponents);
        __m128 he = _mm_mul_ps(DAT_010c71d0, e);
        __m128 ree = _mm_mul_ps(_mm_mul_ps(e, v.m_vComponents), e);
        m_vComponents = _mm_mul_ps(_mm_sub_ps(DAT_010c71c0, ree), he);
    }
};
static void FUN_00ce2a50(FourFloatVector* a, FourFloatVector* b);
void CallerX(FourFloatVector* a, FourFloatVector* b);
struct SubMatrix {
    __m128 m_row[4];
    void FUN_00cb2d90(const float* pQuat);
};
struct TransformOwner {
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    SubMatrix m_matrix;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    __m128 m_vec140;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    __m128 m_quat170;
};
extern "C" TransformOwner* cf8b60_self(void);
extern "C" __m128* cf8b60_quat(void);
static void FUN_00cf8b60(TransformOwner* self, __m128* pQuat);
void cf8b60_caller(void);
struct ResultByte { char value; __forceinline ResultByte(bool b) : value(b) {} };
struct ScalarValue {
    __m128 packed;
    __forceinline ScalarValue(__m128 x) : packed(x) {}
    __forceinline operator float() const { float f; _mm_store_ss(&f,packed); return f; }
};
struct VectorValue {
    __m128 packed;
    __forceinline void subtract(const VectorValue& a,const VectorValue& b) { packed=_mm_sub_ps(a.packed,b.packed); }
    __forceinline void cross(const VectorValue& a,const VectorValue& b) {
        packed=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.packed,a.packed,201),_mm_shuffle_ps(b.packed,b.packed,210)),_mm_mul_ps(_mm_shuffle_ps(a.packed,a.packed,210),_mm_shuffle_ps(b.packed,b.packed,201)));
    }
    __forceinline ScalarValue dot(const VectorValue& b) const {
        __m128 products=_mm_mul_ps(packed,b.packed);
        __m128 first=_mm_add_ss(_mm_shuffle_ps(products,products,85),products);
        return ScalarValue(_mm_add_ss(_mm_shuffle_ps(products,products,170),first));
    }
};
extern double DAT_01032980;
ResultByte FUN_00ceb6f0(float& outT,float& outU,float& outV,const VectorValue& position,const VectorValue& direction,const VectorValue& a,const VectorValue& b,const VectorValue& c,bool cull);

extern float DAT_01011d78;
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c71c0;
extern const __m128 DAT_010c71d0;

struct BoolX {
    char value;
    __forceinline BoolX(bool b) throw() : value((char)b) {}
    __forceinline operator bool() const throw() { return value != 0; }
};
class ScalarX {
    union { __m128 value; float lane[4]; };
public:
    ScalarX() {}
    ScalarX(const ScalarX& a) : value(a.value) {}
    void operator=(const ScalarX& a) { value=a.value; }
    ScalarX(float x) { value=_mm_load_ss(&x); }
    ScalarX(const __m128& x) : value(x) {}
    __forceinline __m128 splat() const { return _mm_shuffle_ps(value,value,0); }
    __forceinline const __m128& quad() const { return value; }
};
inline ScalarX __cdecl operator+(const ScalarX& a,const ScalarX& b) { return _mm_add_ss(a.quad(),b.quad()); }
struct RotationX;
class VectorX {
    union { __m128 value; float lane[4]; };
public:
    __forceinline VectorX() {}
    __forceinline VectorX(const VectorX& a) : value(a.value) {}
    __forceinline __m128& quad() { return value; }
    __forceinline const __m128& quad() const { return value; }
    operator __m128() const { return value; }
    __forceinline void operator=(const VectorX& x) throw() { value=x.value; }
    __forceinline void zero() throw() { value=_mm_setzero_ps(); }
    __forceinline void add(const VectorX& x) throw() { value=_mm_add_ps(value,x.value); }
    __forceinline void multiply(const VectorX& x) throw() { value=_mm_mul_ps(value,x.value); }
    __forceinline void multiply(const ScalarX& x) throw() { value=_mm_mul_ps(x.splat(),value); }
    __forceinline void setProduct(const ScalarX& s, const VectorX& x) throw() { value=_mm_mul_ps(s.splat(),x.value); }
    __forceinline ScalarX dot(const VectorX& x) const throw() {
        __m128 squares = _mm_mul_ps(value,x.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(squares,squares,0x55),squares);
        return _mm_add_ss(_mm_shuffle_ps(squares,squares,0xaa),xy);
    }
    __forceinline ScalarX length() const throw() { return _mm_sqrt_ss(dot(*this).quad()); }
    __forceinline void sumProduct(const VectorX& a,const VectorX& b,const VectorX& c) { value=_mm_add_ps(a.value,_mm_mul_ps(b.value,c.value)); }
    __forceinline void product(const VectorX& a,const VectorX& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void accumulateProduct(const VectorX& a,const VectorX& b) { value=_mm_add_ps(value,_mm_mul_ps(a.value,b.value)); }
    __forceinline void sum(const VectorX& a,const VectorX& b) { value=_mm_add_ps(a.value,b.value); }
    __forceinline void broadcast(const VectorX& a,int lane) { if(lane==0) value=_mm_shuffle_ps(a.value,a.value,0); else if(lane==1) value=_mm_shuffle_ps(a.value,a.value,0x55); else if(lane==2) value=_mm_shuffle_ps(a.value,a.value,0xaa); else if(lane==3) value=_mm_shuffle_ps(a.value,a.value,0xff); }
    __forceinline void broadcast(int lane) { if(lane==0) value=_mm_shuffle_ps(value,value,0); else if(lane==1) value=_mm_shuffle_ps(value,value,0x55); else if(lane==2) value=_mm_shuffle_ps(value,value,0xaa); else if(lane==3) value=_mm_shuffle_ps(value,value,0xff); }
    __forceinline void cross(const VectorX& a,const VectorX& b) {
        __m128 lhs=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        __m128 rhs=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(lhs,rhs);
    }
    __forceinline ScalarX element(int lane) const {
        if(lane==0) return _mm_shuffle_ps(value,value,0);
        if(lane==1) return _mm_shuffle_ps(value,value,0x55);
        if(lane==2) return _mm_shuffle_ps(value,value,0xaa);
        return _mm_shuffle_ps(value,value,0xff);
    }
    __forceinline void fill(const ScalarX& x) { value=x.splat(); }
    __forceinline void accumulateProduct(const ScalarX& s,const VectorX& x) { value=_mm_add_ps(value,_mm_mul_ps(s.splat(),x.value)); }
    __forceinline void subtractProduct(const ScalarX& s,const VectorX& x) { value=_mm_sub_ps(value,_mm_mul_ps(s.splat(),x.value)); }
    __forceinline void subtract(const VectorX& x) { value=_mm_sub_ps(value,x.value); }
    __forceinline void pack(const VectorX& xyz,const VectorX& w) { value=_mm_shuffle_ps(xyz.value,_mm_unpackhi_ps(xyz.value,w.value),0xc4); }
    __forceinline ScalarX dot4(const VectorX& x) const {
        __m128 p=_mm_mul_ps(value,x.value);
        __m128 s=_mm_add_ps(_mm_shuffle_ps(p,p,0x4e),p);
        return _mm_add_ps(s,_mm_shuffle_ps(s,s,0xb1));
    }
    __forceinline void rotate(const RotationX& q,const VectorX& dir);

};
struct RotationX {
    VectorX vec;
    RotationX() {}
    RotationX(const RotationX& a) { vec=a.vec; }
    void operator=(const RotationX& a) { vec=a.vec; }
    void flipped(const VectorX&);
    __forceinline const VectorX& imag() const { return vec; }
    void FUN_00cd9d10(const VectorX&, const VectorX&) throw();
    void FUN_00c74ac0(const RotationX&, const RotationX&) throw();
    void FUN_00ce0ca0(const RotationX&) throw();
    void FUN_00c66320(const RotationX&, const RotationX&) throw();
};
__forceinline void VectorX::rotate(const RotationX& q,const VectorX& dir) {
    VectorX half; half.quad()=DAT_010c71e0;
    VectorX w; w.broadcast(q.vec,3);
    VectorX coeff; coeff.sumProduct(half,w,w);
    VectorX result; result.product(dir,coeff);
    VectorX projection; projection.quad()=q.imag().dot(dir).quad();
    projection.broadcast(0);
    result.accumulateProduct(projection,q.imag());
    VectorX perpendicular; perpendicular.cross(q.imag(),dir);
    result.accumulateProduct(w,perpendicular);
    sum(result,result);
}
static __forceinline __m128 reciprocalRootX(__m128 a) {
    __m128 r=_mm_rsqrt_ps(a);
    return _mm_mul_ps(_mm_mul_ps(_mm_set1_ps(0.5f),r),_mm_sub_ps(_mm_set1_ps(3.0f),_mm_mul_ps(_mm_mul_ps(r,a),r)));
}
__declspec(noinline) void RotationX::FUN_00cd9d10(const VectorX& from,const VectorX& to) throw() {
    __m128 dp=from.dot(to).splat();
    __m128 nearOne=_mm_set1_ps(1.0f-1e-5f);
    __m128 nearNegative=_mm_set1_ps(-(1.0f-1e-3f));
    if(_mm_movemask_ps(_mm_cmpgt_ps(dp,nearOne))) {
        vec.quad()=_mm_set_ps(1.0f,0.0f,0.0f,0.0f);
    } else if(_mm_movemask_ps(_mm_cmplt_ps(dp,_mm_sub_ps(_mm_setzero_ps(),nearOne)))) {
        flipped(from);
    } else {
        __m128 half=_mm_set1_ps(0.5f);
        __m128 c=_mm_add_ps(half,_mm_mul_ps(half,dp));
        __m128 inv=reciprocalRootX(c);
        VectorX perpendicular; perpendicular.cross(from,to);
        __m128 amount=_mm_mul_ps(half,inv);
        if(_mm_movemask_ps(_mm_cmplt_ps(dp,nearNegative))) {
            __m128 sineSquared=_mm_sub_ps(c,dp);
            __m128 lengthSquared=perpendicular.dot(perpendicular).quad();
            __m128 lenInv=_mm_rsqrt_ss(lengthSquared);
            lenInv=_mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f),lenInv),_mm_sub_ss(_mm_set_ss(3.0f),_mm_mul_ss(_mm_mul_ss(lengthSquared,lenInv),lenInv)));
            lenInv=_mm_andnot_ps(_mm_cmpeq_ss(lengthSquared,_mm_setzero_ps()),lenInv);
            amount=_mm_mul_ps(reciprocalRootX(sineSquared),sineSquared);
            amount=_mm_mul_ps(_mm_shuffle_ps(lenInv,lenInv,0),amount);
        }
        perpendicular.quad()=_mm_mul_ps(perpendicular.quad(),amount);
        __m128 real=_mm_mul_ps(c,inv);
        vec.quad()=_mm_shuffle_ps(perpendicular.quad(),_mm_unpackhi_ps(perpendicular.quad(),real),0xc4);
    }
}
inline void RotationX::FUN_00c66320(const RotationX& a,const RotationX& b) throw() {
    VectorX result; result.cross(a.imag(),b.imag());
    result.accumulateProduct(a.vec.element(3),b.imag());
    result.accumulateProduct(b.vec.element(3),a.imag());
    VectorX d; d.fill(a.vec.dot(b.vec));
    VectorX real; real.product(a.vec,b.vec); real.subtract(d);
    vec.pack(result,real);
}
inline void RotationX::FUN_00ce0ca0(const RotationX& b) throw() {
    VectorX result; result.cross(imag(),b.imag());
    result.accumulateProduct(vec.element(3),b.imag());
    result.accumulateProduct(b.vec.element(3),imag());
    VectorX d; d.fill(imag().dot(b.imag()));
    VectorX real; real.product(vec,b.vec); real.subtract(d);
    vec.pack(result,real);
}
inline void RotationX::FUN_00c74ac0(const RotationX& a,const RotationX& b) throw() {
    VectorX result; result.cross(b.imag(),a.imag());
    result.subtractProduct(a.vec.element(3),b.imag());
    result.accumulateProduct(b.vec.element(3),a.imag());
    VectorX real; real.fill(a.vec.dot4(b.vec));
    vec.pack(result,real);
}
struct PoseX { VectorX translation; RotationX rotation; VectorX scale;
    __forceinline const VectorX& position() const { return translation; }
    __forceinline const RotationX& orient() const { return rotation; }
    __forceinline const VectorX& sizing() const { return scale; }
};

template<class T> struct ArrayBaseX {
    T* data; int size, capacity;
    __forceinline int count() const throw() { return size; }
    __forceinline T* begin() throw() { return data; }
    __forceinline const T* begin() const throw() { return data; }
    __forceinline const T& operator[](int n) const throw() { return data[n]; }
};
template<class T> struct ArrayX : ArrayBaseX<T> {};
template<class T> struct RefX {
    T* pointer;
    __forceinline T* operator->() const throw() { return pointer; }
};
struct BoneX;
struct SkeletonX {
    int unk00, unk04;
    const char* name;
    ArrayX<short> parents;
    ArrayX<BoneX> bones;
    ArrayX<PoseX> reference;
};
struct RecordX { short a,b; PoseX offset; };
struct LinkX { short a,b,c,d; PoseX root,end; };
struct MapperX {
    int unk00,unk04,unk08,unk0c;
    RefX<const SkeletonX> first,second;
    ArrayX<RecordX> records;
    ArrayX<LinkX> links;
    ArrayX<short> unmapped;
    PoseX motion;
    BoolX keepLocal;
    int property;
    void __cdecl FUN_00ce3090(const PoseX*, PoseX*, const short*, const short*, bool) const;
};
extern void __cdecl FUN_00ce2f30(const PoseX*, const PoseX*, const short*, int, PoseX*) throw();
extern void __cdecl FUN_00ce2f40(const PoseX*, const PoseX*, const short*, int, PoseX*) throw();
extern void __cdecl FUN_00ce2ca0(int, PoseX&, const PoseX&, const PoseX&) throw();

struct ClockEventX { const char* tag; unsigned stamp; int unused; };
struct ClockListX : ClockEventX { const char* split; };
struct ClockX {
    int unk00; char* current; int unk08; char* end;
    __forceinline void mark(const char* tag) throw() {
        if (current<end) {
            ClockEventX* event=(ClockEventX*)current;
            event->tag=tag;
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            current=(char*)(event+1);
        }
    }
    __forceinline void begin(const char* tag,const char* split) throw() {
        if (current<end) {
            ClockListX* event=(ClockListX*)current;
            event->tag=tag; event->split=split;
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            current=(char*)(event+1);
        }
    }
    static __forceinline ClockX& instance() throw() { return *(ClockX*)TlsGetValue(DAT_0126835c); }
};
template<class T> class StoredX {
    T value;
public:
    __forceinline StoredX() throw() {}
    __forceinline StoredX(T v) throw() : value(v) {}
    __forceinline void operator=(T v) throw() { value=v; }
    __forceinline operator T() const throw() { return value; }
    __forceinline T get() const throw() { return value; }
};
template<class T> __forceinline T* stackAllocateX(int n) {
    T** top=(T**)FUN_00c85750();
    T* result=*top;
    *top=(T*)((char*)result+((n*int(sizeof(T))+127)&~127));
    return result;
}
template<class T> struct BufferX {
    StoredX<T*> data;
    int debugSize;
    __forceinline BufferX(int n) throw() { data=stackAllocateX<T>(n); }
    __forceinline T* begin() throw() { return data; }
    __forceinline ~BufferX() throw() { *(T**)FUN_00c85750()=data.get(); }
};
static __declspec(noinline) void FUN_00ce2a50(VectorX& a,VectorX& b) throw() {
    VectorX al; al.quad()=a.dot(a).splat();
    VectorX bl; bl.quad()=b.dot(b).splat();
    VectorX packed;
    packed.quad()=_mm_shuffle_ps(al.quad(),_mm_unpackhi_ps(al.quad(),bl.quad()),0xc4);
    __m128 root=_mm_rsqrt_ps(packed.quad());
    __m128 correction=_mm_mul_ps(_mm_mul_ps(root,packed.quad()),root);
    __m128 inverse=_mm_mul_ps(_mm_mul_ps(DAT_010c71d0,root),_mm_sub_ps(DAT_010c71c0,correction));
    a.multiply(ScalarX(_mm_shuffle_ps(inverse,inverse,0)));
    b.multiply(ScalarX(_mm_shuffle_ps(inverse,inverse,0xff)));
}

// @fnv 0x00ce3090
void __cdecl MapperX::FUN_00ce3090(const PoseX* original,PoseX* output,const short* mapA,const short* mapB,bool additive) const {
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockListX* event=(ClockListX*)timer.current;
            event->tag="LtMapPoseLocalSpace";
            event->split="Stinit";
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="StsimpleMappings";
            
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    const BoolX sparse=mapA&&mapB;
    BufferX<PoseX> scratch(first->bones.count());
    if (additive) FUN_00ce2f30(original,first->reference.begin(),mapA,first->bones.count(),scratch.begin());
    const PoseX* input=additive?scratch.begin():original;
    {
        const int total=records.count();
        for(int i=0;i<total;++i) {
            _mm_prefetch((const char*)&records[i]+128,_MM_HINT_NTA);
            const RecordX& r=records[i];
            int a=r.a,b=r.b;
            if(sparse) { a=mapA[a]; if(a<0) continue; b=mapB[b]; }
            FUN_00ce2ca0(property,output[b],r.offset,input[a]);
            _mm_prefetch((const char*)&input[a]+128,_MM_HINT_NTA);
            _mm_prefetch((const char*)&output[b]+128,_MM_HINT_NTA);
        }
    }
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="StchainMappings";
            
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
    {
        const int total=links.count();
        for(int i=0;i<total;++i) {
            const LinkX& r=links[i];
            VectorX posA,posB;
            posA.zero(); posB.zero();
            ScalarX length=0.0f;
            bool valid=true;
            for(short bone=r.b;bone>r.a;bone=first->parents[bone]) {
                short track=sparse?mapA[bone]:bone;
                if(track<0) { valid=false; break; }
                const PoseX& t=input[track];
                VectorX prev(posA);
                posA.rotate(t.orient(),prev);
                posA.add(t.position());
                length=length+t.position().length();
            }
            if(sparse) { valid=valid&&mapA[r.a]>=0; if(!valid) continue; }
            VectorX scale; scale.setProduct(length,r.end.sizing());
            for(short bone=r.d;bone>r.c;bone=second->parents[bone]) {
                short track=sparse?mapB[bone]:bone;
                PoseX& t=output[track];
                t.translation.multiply(scale);
                VectorX prev(posB);
                posB.rotate(t.orient(),prev);
                posB.add(t.position());
            }
            int a=r.a,c=r.c,b=r.b,d=r.d;
            if(sparse) { a=mapA[a];c=mapB[c];b=mapA[b];d=mapB[d]; }
            FUN_00ce2ca0(property,output[c],r.root,input[a]);
            FUN_00ce2a50(posA,posB);
            RotationX shortest; shortest.FUN_00cd9d10(posB,posA);
            RotationX offset; offset.vec=r.end.translation;
            RotationX applied; applied.FUN_00c74ac0(shortest,offset);
            output[c].rotation.FUN_00ce0ca0(applied);
            output[d].rotation.FUN_00c66320(r.end.rotation,input[b].rotation);
        }
    }
    if(additive) FUN_00ce2f40(output,second->reference.begin(),mapB,second->bones.count(),output);
    {
        ClockX& timer=ClockX::instance();
        if(timer.current<timer.end) {
            ClockEventX* event=(ClockEventX*)timer.current;
            event->tag="lt";
            
            unsigned ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->stamp=ticks;
            timer.current=(char*)(event+1);
        }
    }
}

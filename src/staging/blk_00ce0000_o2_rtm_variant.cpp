// src/staging/blk_00ce0000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ce0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010cc164;
void __cdecl FUN_00d86220();
struct FUN_00cf45d0_class
{
    int vtable;
    FUN_00cf45d0_class();
};
struct hkReferencedObject
{
    void RetainReference();
};
struct FUN_00cf4ca0_class
{
    int m_auiShapeKeys[6];
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    void FUN_00cf4ca0();
};
struct FUN_00d06d50_cls
{
    int __thiscall FindClass(int);
};
extern "C" void __cdecl FUN_00cf6920(int, int, int);
void __cdecl FUN_00cf6950(int a, int apObject);
struct FUN_00cf86f0_class
{
    int IsFieldEqual();
};
unsigned short FUN_00cfcb80(unsigned short a, unsigned short b);
extern int DAT_010cb864;
struct FUN_00ce4ae0_cls
{
    int __thiscall FUN_00ce4ae0(int);
    void __thiscall FUN_00ce5310();
};
struct FUN_00ce4a20_cls
{
    int m_kPointA;
    short m_kPointB;
    short m_iThirdValue;
    int m_iFourthElementInteger;
    int __thiscall FUN_00ce4a20(int a);
};
extern int DAT_0102e378;
void __cdecl finishLoadedObject_hkReferencedObject(int* a);
struct FUN_00cf69c0_class
{
    int m_kPointA;
    int m_auiShapeKeys;
    int m_kPointB;
    int __thiscall FUN_00cf69c0(int a);
};
int __cdecl FUN_00cb0fa0(int a, int b);
struct FUN_00cf86e0_class
{
    void FUN_00cf86e0(float f);
};
extern int DAT_010cc2e0;
struct FUN_00cf4820_class
{
    int* vtbl;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00cf4820_class();
};
extern int DAT_0102e388;
struct FUN_00cf86d0_cls
{
    void FUN_00cf86d0();
};
// FUN_00ce29e0: member function that (re)initialises the object.
//   - installs the base vtable pointer at [this],
//   - calls the constructor of the sub-object living at this+0x10,
//   - then installs the vtable pointer of the derived class at [this].
extern int DAT_010cb864;
extern int DAT_0102e388;
// Sub-object at +0x10; FUN_00ce5370 is the game's constructor for it.
struct FUN_00ce5370_cls
{
    void FUN_00ce5370();
};
struct FUN_00ce29e0_cls
{
    int* m_pVTable;          // +0x00
    int unk04;               // +0x04
    int unk08;               // +0x08
    int unk0C;               // +0x0C
    FUN_00ce5370_cls m_sub;  // +0x10
    void FUN_00ce29e0();
};
struct FnvSpawnedObject;
struct FnvProbe
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char* Match(FnvSpawnedObject** ref);
    unsigned char* Check(FnvSpawnedObject** ref);
};
struct FnvSpawnedObject
{
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
void __cdecl FUN_00ce2cf0(int pObject, int param_2, int param_3);
void __cdecl FUN_00ce3090(int a1, int a2, int a3, int a4, int a5, int a6);
void __cdecl FUN_00ce4330(int a1, int a2, int a3, int a4);
struct FnvKeyRec
{
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
struct FUN_00ce5480_cls
{
    int unk00;
    int unk04;
    FnvKeyRec* m_pRecords;
    int m_uiItemCount;
};
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pKeyBox);
void __cdecl FUN_00d86160(void* stream, void* self);
struct DragBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};
struct DragStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};
struct FUN_00cf4490_cls
{
    char unk00[0x14];
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    void FUN_00cf4490(void* stream);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268740;
CpuOpaque* __cdecl FUN_00cf45f0();
struct PacketSerializer
{
    int metadata, bytesWritten, reserved;
    typedef int(__cdecl* Fn)(PacketSerializer*, const void*, int, int*, int);
    Fn write;
};
struct SerializedObject
{
    int base00, base04, base08, base0C, base10, word14, word18;
    void __thiscall SerializeToStream(int source);
};
extern "C" void __cdecl FUN_00d86160(int, SerializedObject*);
// Save a Havok-wrapped object: write its type id, then let a type-specific saver write the rest.
extern __declspec(thread) int g_iCF4BC0AllocTag;
struct CF4BC0AllocTagScope
{
    int m_iSaved;

    CF4BC0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCF4BC0AllocTag;
        g_iCF4BC0AllocTag = aiAllocationTag;
    }
    ~CF4BC0AllocTagScope()
    {
        g_iCF4BC0AllocTag = m_iSaved;
    }
};
class CF4BC0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CF4BC0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CF4BC0Stream
{
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
template <class T> inline void CF4BC0SaveBinary(CF4BC0Stream& kStream, const T& value)
{
    CF4BC0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class CF4BC0Object
{
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
class CF4BC0Saver
{
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
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
AudioHolder* __cdecl FUN_00c85750() throw();
struct SubObject_b3813
{
    int unk00;
    void Release();
};
struct FUN_00cf4eb0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    SubObject_b3813 m_sub;

    FUN_00cf4eb0_cls* Destroy(unsigned char acFlags);
};
struct S_00cf4f00
{
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
struct FUN_00cf4f30_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    short unk24;
    unsigned short counter;
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
struct FUN_00cf6980_class
{
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
struct S_00cf6b50_Foo
{
    int m_iWordAt00;
    short m_iWordAt04;
    unsigned short m_6;

    void __thiscall UpdateState(int a);
};
struct FUN_00cf6d50_cls
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void FUN_00cf6d50();
};
struct FUN_00cf6f80_cls
{
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
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager _g_memoryManager;
class CF4840Saver
{
  public:
    void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Saver00 : CF4840Saver
{
    Saver00() throw();
};
struct Saver01 : CF4840Saver
{
    Saver01() throw();
};
struct Saver02 : CF4840Saver
{
    Saver02() throw();
};
struct Saver03 : CF4840Saver
{
    Saver03() throw();
};
struct Saver06 : CF4840Saver
{
    Saver06() throw();
};
struct Saver07 : CF4840Saver
{
    Saver07() throw();
};
struct Saver08 : CF4840Saver
{
    Saver08() throw();
};
struct Saver09 : CF4840Saver
{
    Saver09() throw();
};
struct Saver10 : CF4840Saver
{
    Saver10() throw();
};
struct Saver12 : CF4840Saver
{
    Saver12() throw();
};
struct Saver13 : CF4840Saver
{
    Saver13() throw();
};
CF4840Saver* __cdecl CreateSaver(unsigned int uiType);
// Build the Havok object for a serialized node: find its creator, run it, keep the result and delete the creator.
extern __declspec(thread) int g_iF4A30AllocTag;
struct F4A30AllocTagScope
{
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iF4A30AllocTag;
        g_iF4A30AllocTag = aiAllocationTag;
    }
    ~F4A30AllocTagScope()
    {
        g_iF4A30AllocTag = m_iSaved;
    }
};
class F4A30Result
{
  public:
    void RetainReference();
};
class F4A30Node
{
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
class F4A30Creator
{
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
class FUN_00ce5360_This
{
  public:
// @fnv 0x00ce5360
    virtual ~FUN_00ce5360_This()
    {}
    unsigned int FUN_00ce5360(unsigned int arg);
};
unsigned int FUN_00ce5360_This::FUN_00ce5360(unsigned int arg)
{
    return reinterpret_cast<unsigned int>(this);
}
class FUN_00ce9800_obj
{
  public:
    virtual ~FUN_00ce9800_obj();
};
void __cdecl DeleteObjectIfNotNull(FUN_00ce9800_obj* pkObject);
struct FUN_00ce9820_vt
{
    virtual void FUN_00ce9820_v0(int a);
    virtual void FUN_00ce9820_v1(int a);
};
void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* pObject);
struct Stream;
typedef int (*StreamIOFunc)(Stream* stream, void* data, int size, int* count, int flag);
struct Stream
{
    int unk00;
    int pos;
    int unk08;
    StreamIOFunc io;
};
struct StreamOwner
{
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
struct Record
{
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
struct ArrayData
{
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
    if ((int)count > 0)
    {
        do
        {
            unsigned int val = kArray.m_data[i];
            if ((unsigned char)kStream.unk1E4 != 1)
            {
                val = _byteswap_ulong(val);
            }
            CF4BC0SaveBinary(kStream, val);
            ++i;
        } while (i < (int)count);
    }

    return totalSize;
}
extern int DAT_010cc064;
struct FUN_00cdf560
{
    int m0;
    int m4;
    int m8;
    FUN_00cdf560(float);
};
struct FUN_00cf4190 : FUN_00cdf560
{
    FUN_00cf4190();
};
extern int DAT_01268730;
int* FUN_00cf41b0();
extern "C" void __cdecl FUN_00d86100(void* view, void* object);
struct BinaryStream
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, sizeof(T), &byteCount, 1);
    }
};
struct StreamView
{
    BinaryStream* stream()
    {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct SerializedRecord
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int m_14, m_18, m_1c, m_20;
    void FUN_00cf41c0(StreamView* view);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268738;
CpuOpaque* __cdecl FUN_00cf43f0();
class NiBinaryStreamCF46
{
  public:
    typedef unsigned int (*WriteFn)(NiBinaryStreamCF46* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T> inline void NiStreamSaveBinaryCF46(NiBinaryStreamCF46& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}
struct hkArchiveCF46
{
    int unk000[0x93];
    NiBinaryStreamCF46* m_stream;
};
void __cdecl FUN_00d86100(hkArchiveCF46* ar, void* obj);
class hkObjCF46
{
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
struct hkCriticalSectionCF6B
{
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6B
{
    hkCriticalSectionCF6B* m_kCriticalSection;
    hkCriticalSectionLockCF6B(hkCriticalSectionCF6B* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6B()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};
struct hkMultiThreadCheckCF6B
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void MarkForRead();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
unsigned int __cdecl FUN_00d87a40() throw();
struct hkCriticalSectionCF61
{
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF61
{
    hkCriticalSectionCF61* m_kCriticalSection;
    hkCriticalSectionLockCF61(hkCriticalSectionCF61* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF61()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};
struct hkMultiThreadCheckCF61
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    bool IsCurrentThreadOwner();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
struct hkCriticalSectionCF6C
{
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6C
{
    hkCriticalSectionCF6C* m_kCriticalSection;
    hkCriticalSectionLockCF6C(hkCriticalSectionCF6C* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6C()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};
struct hkMultiThreadCheckCF6C
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6c60();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
struct hkCriticalSectionCF6D
{
    int m_kCriticalSection;
};
struct hkCriticalSectionLockCF6D
{
    hkCriticalSectionCF6D* m_kCriticalSection;
    hkCriticalSectionLockCF6D(hkCriticalSectionCF6D* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6D()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};
struct hkMultiThreadCheckCF6D
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6cb0();
};
struct hkMultiThreadCheckCF6E
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void ResetThreadCheck();
};
struct CC9F10Shape
{
    void FUN_00c90510();
};
struct FUN_00cf7490_class
{
    void FUN_00cf7490();
};
void __cdecl FUN_00c905b0(void);
void __cdecl FUN_00cf74a0(void);
struct hkOwnerCF74;
struct hkEntryCF74
{
    hkOwnerCF74* m_pOwnerObject;
    int unk04;
    unsigned int m_08;
};
struct hkOwnerCF74
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0;
    unsigned int m_d4;
};
int __cdecl FUN_00cf74b0(const hkEntryCF74& aEntryA, const hkEntryCF74& aEntryB);
struct hkBoolCF74
{
    char m_cBooleanValue;
    hkBoolCF74()
    {}
    hkBoolCF74(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct hkQualityCF74
{
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
struct hkEntityCF74
{
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
struct hkPairCF74
{
    int unk00;
    hkEntityCF74* m_kPointA;
    hkEntityCF74* m_kPointB;
};
hkBoolCF74 __cdecl LessThanPairPriority(const hkPairCF74& aPairA, const hkPairCF74& aPairB);
void* __cdecl FUN_00cfb050(void* pvUnused, bool* pbOut, void* pvResult);
void FUN_00cfb060();
int __cdecl FUN_00cfb070(int a, int b, int c);
void __stdcall FUN_00cfc580(int, int, int, int, int);
extern int DAT_0102e388;
struct FUN_00cfc590_class
{
    int* vtable;

    void __thiscall FUN_00cfc590();
};
extern int DAT_010cc86c;
struct S_00cfc5a0
{
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
struct FUN_00cfc5a0
{
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
struct CE0020Event
{
    const char* m_pTag;
    unsigned int m_uiEventId;
    int m_unk08;
};
struct CE0020Buffer
{
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
class CE0020Flag
{
  public:
    bool m_bEnableState;
    unsigned char m_unk01;
    unsigned char m_unk02;
    unsigned char m_unk03;
};
class CE0020ZeroInfo
{
  public:
    int m_unk00;
    int m_iArrayLength;
};
class CE0020Holder
{
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
class CE0020Arrays
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    float* m_pFloats;
};
class CE0020Target
{
  public:
    int unk00, unk04, unk08;
    CE0020Holder* m_pHolder;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    CE0020Arrays* m_pArrayData;
};
class CE0020Subject
{
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
struct NiBinaryStreamCF42
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF42* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void NiStreamLoadBinaryCF42(NiBinaryStreamCF42& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
struct NiStreamCF42
{
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

    NiBinaryStreamCF42* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};
class SerializableCF42;
void __cdecl FUN_00d86160(NiStreamCF42& kStream, SerializableCF42* pkObject);
class SerializableCF42
{
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
struct hkBoolC43
{
    char v;
};
class FUN_00cf43b0
{
  public:
    const void** m_vftable;              // 0x00
    unsigned short m_usMemSizeAndFlags;  // 0x04
    unsigned short m_sReferenceCount;    // 0x06
    unsigned char m_motorType;           // 0x08
    char unk09;
    char unk0A;
    char unk0B;
    float m_fMinForce;        // 0x0c
    float m_fMaxForce;        // 0x10
    float m_fTau;             // 0x14
    float m_fMotorDamping;    // 0x18
    char m_useVelocityClamp;  // 0x1c

    FUN_00cf43b0();
};
struct NiBinaryStreamCF44
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF44* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void NiStreamLoadBinaryCF44(NiBinaryStreamCF44& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
struct NiStreamCF44
{
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

    NiBinaryStreamCF44* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};
class SerializableCF44;
void __cdecl FUN_00d86100(NiStreamCF44& kStream, SerializableCF44* pkObject);
class SerializableCF44
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned char m_ucValue1C;

    void FUN_00cf4400(NiStreamCF44& kStream);
};
struct CF4BC0StreamInput
{
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
    CF4BC0BinaryStream* m_pUnderlyingStream;
    CF4BC0BinaryStream* m_pBackingStream;
};
class CF4BC0BinaryStreamIn
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStreamIn*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Load(T* value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, value, sizeof(T), &uiSize, 1);
    }
};
class CF4BC0SaverLoader
{
  public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void LoadBinary(CF4BC0Stream& kStream);
    virtual void SaveBinary(CF4BC0Stream& kStream);
    hkReferencedObject* m_pPointer;
};
struct TagState
{
    int oldTag;
    int newTag;
};
__forceinline TagState GetTag(int tag)
{
    TagState state = {g_iCF4BC0AllocTag, tag};
    return state;
}
struct AllocScope
{
    int saved;
    AllocScope(TagState t) : saved(t.oldTag)
    {
        g_iCF4BC0AllocTag = t.newTag;
    }
    ~AllocScope()
    {
        g_iCF4BC0AllocTag = saved;
    }
};
hkReferencedObject* __cdecl FUN_00cf4af0(CF4BC0Stream& kStream);
void FUN_00cf6d10();
class hkBaseObject
{
  public:
    virtual ~hkBaseObject()
    {}
};
class hkRefObjCF70 : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpBroadPhaseListener
{
  public:
    virtual ~hkpBroadPhaseListener()
    {}
    virtual void AddCollisionPair(void* pair) = 0;
    virtual void RemoveCollisionPair(void* pair) = 0;
};
class ListenerCF70 : public hkRefObjCF70, public hkpBroadPhaseListener
{
  public:
    virtual void AddCollisionPair(void* pair);
    virtual void RemoveCollisionPair(void* pair);
};
class FUN_00cf7060
{
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
extern const __m128 g_vectorConstantQuaternionIdentity;
struct __declspec(align(16)) CE5430Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void SetAllComponents(float f)
    {
        m_vComponents = _mm_set_ps1(f);
    }
};
struct __declspec(align(16)) CE5430Quaternion
{
    __m128 m_vec;

    void setIdentity()
    {
        m_vec = g_vectorConstantQuaternionIdentity;
    }
};
struct __declspec(align(16)) CE5430QsTransform
{
    CE5430Vector4 m_vTranslation;
    CE5430Quaternion m_rotation;
    CE5430Vector4 m_vScale;

    void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.SetAllComponents(1.0f);
    }
};
struct __declspec(align(16)) CE5430Pose
{
    short m_sIndex0;
    short m_sIndex1;
    short m_sIndex2;
    short m_sIndex3;
    int unk08;
    int unk0C;
    CE5430QsTransform m_kTransform0;
    CE5430QsTransform m_kTransform1;

    void SetIdentity();
};
struct __declspec(align(16)) hkVector4CE98
{
    __m128 m_vComponents;

    void operator=(const hkVector4CE98& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct hkElementCE98
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    hkVector4CE98 m_vector;
};
void __cdecl CopyVectors(hkElementCE98* pkDst, const hkElementCE98* pkSrc, int iCount);
struct FUN_00cf0820
{
    float field00;
    float field04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    FUN_00cf0820(const FUN_00cf0820& input);
};
extern __declspec(align(16)) float DAT_01017d10[4];
extern float DAT_01017d00;
struct FUN_00cf08c0_VectorArray
{
    float* values;
    int count;
};
bool __cdecl FUN_00cf08c0(const FUN_00cf08c0_VectorArray* left, const FUN_00cf08c0_VectorArray* right);
struct BinaryStreamCF0
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStreamCF0*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest, unsigned int uiBytes)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, uiBytes, &byteCount, 1);
    }
};
struct StreamViewCF0
{
    BinaryStreamCF0* stream()
    {
        return *reinterpret_cast<BinaryStreamCF0**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct hkVector4CF0
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};
struct hkMatrixCF0
{
    hkVector4CF0 m_kColumn0;
    hkVector4CF0 m_kColumn1;
    hkVector4CF0 m_kColumn2;
};
void __cdecl FUN_00cf0b00(StreamViewCF0* pkView, hkMatrixCF0* pkDest);
struct S00cf0cf0_Stream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnWrite)(S00cf0cf0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
};
struct S00cf0cf0_Arr
{
    __m128* data;
    unsigned int count;
};
struct S00cf0cf0_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    S00cf0cf0_Stream* m_pBinaryStream;
};
static unsigned int S00cf0cf0_SaveRaw(S00cf0cf0_Stream* s, const void* p, unsigned int n, unsigned int elemSize)
{
    unsigned int uiSize = elemSize;
    return s->m_pfnWrite(s, p, n * elemSize, &uiSize, 1);
}
int __cdecl FUN_00cf0cf0(S00cf0cf0_Obj* self, S00cf0cf0_Arr* arr);
struct TargetType
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 unk10;
    void* unk20;
    unsigned int unk24;
};
unsigned int FUN_00cf0dc0(CF4BC0Stream& stream, TargetType* obj);
const char* __cdecl GetConstraintTypeName(int eType);
void __stdcall FUN_00cf6d00(int);
extern void* DAT_010c63bc;
extern void* DAT_010cc4e0;
extern void* DAT_010cc4d0;
struct NodeBaseA
{
    void* m_vtbl;
    unsigned short m_04;
    unsigned short m_06;
    NodeBaseA()
    {
        m_06 = 1;
    }
};
struct NodeBaseB
{
    void* m_vtbl;
    NodeBaseB()
    {
        m_vtbl = &DAT_010c63bc;
    }
};
struct NodeObj : NodeBaseA, NodeBaseB
{
    NodeObj()
    {
        NodeBaseA::m_vtbl = &DAT_010cc4e0;
        NodeBaseB::m_vtbl = &DAT_010cc4d0;
    }
};
struct FUN_00cf6f90
{
    NodeBaseB* m_apSlots[8][8];
    NodeObj m_kDefault;
    FUN_00cf6f90();
};
void __stdcall FUN_00cf8810(int a);
extern char DAT_010cc688[];
struct VecCFAD
{
    union
    {
        __m128 v;
        float f[4];
    };
};
struct InputCFAD
{
    VecCFAD vec;
    int unk10, unk14, unk18, unk1C;
    unsigned char enabled;
};
struct DescCFAD
{
    VecCFAD vec;
    void* data;
    void* extra;
    unsigned int size;
    unsigned int flags;
};
struct ContextCFAD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
};
struct TargetCFAD;
struct SelfCFAD;
struct TargetCFAD
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C(DescCFAD*, SelfCFAD*, int);
};
struct SelfCFAD
{
    void* unk00;
    InputCFAD* input;
    void* extra;
    unsigned int flags;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* context;
    void FUN_00cfad60(TargetCFAD*, InputCFAD*, void*, ContextCFAD*, unsigned int, unsigned int);
};
struct Cfd50Range
{
    int m_00;
    int* m_04;
    int m_08;
};
static int FUN_00cfdb50(Cfd50Range* a);
extern "C" Cfd50Range* Cfd50Get(void);
extern "C" int Cfd50Sink(int);
void Cfd50Caller(void);
struct CE1700World
{
    void FUN_00c97e80(char* result, void* object);
    void RemoveEntities(void* owner, int flags);
};
struct CE1700Node
{
    int unk00;
    int unk04;
    CE1700World* world;
};
struct CE1700Owner
{
    int unk00;
    int unk04;
    CE1700Node** owner;
    int flags;
    int unk10;
    void** objects;
    int count;
    int FUN_00ce1700();
};
struct Slot_cfdb70
{
    void* m_p;
    int m_04;
};
struct Node_cfdb70
{
    char pad[0x50];
    Slot_cfdb70* m_slots;
};
struct Edge_cfdb70
{
    void* m_vtbl;
    unsigned short m_idxA;
    unsigned short m_idxB;
    int m_08;
    int m_0c;
    Node_cfdb70* m_kPointA;
    Node_cfdb70* m_kPointB;
};
static void LinkEdge(Edge_cfdb70* e);
void zz_probe_cfdb70(Edge_cfdb70* e);
struct BlockArr_cfd
{
    unsigned* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned operator[](int i) const
    {
        return m_data[i];
    }
    const unsigned& at(int i) const
    {
        return m_data[i];
    }
};
struct BlockList_cfd
{
    unsigned m_lastSize;
    BlockArr_cfd m_kBlocks;
};
bool __cdecl IsAddressInBlock(const BlockList_cfd* list, unsigned addr);
inline AudioAllocator& heap_cfde()
{
    return *FUN_00c85750()->m_pAllocator;
}
extern "C" void __cdecl FUN_00c909d0(AudioAllocator* alloc, void* array, int elemSize, void* storage, int capacity);
struct BlockArr_cfde
{
    char*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_kStorage[1];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void OptimizeCapacity(int numFreeElemsLeft)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            unsigned c = m_iElementCount + numFreeElemsLeft - 1;
            c |= c >> 16;
            c |= c >> 8;
            c |= c >> 4;
            c |= c >> 2;
            c |= c >> 1;
            int newCap = c + 1;
            if (newCap < 1)
            {
                AudioHolder* h = FUN_00c85750();
                FUN_00c909d0(h->m_pAllocator, this, sizeof(char*), m_kStorage, 1);
            }
            else if (newCap < getCapacity())
            {
                AudioAllocator& a = heap_cfde();
                FUN_00c909d0(&a, this, sizeof(char*), 0, newCap);
            }
        }
    }
};
struct BlockStack_cfde
{
    int m_uiBufferCapacity;
    BlockArr_cfde m_kBlocks;
};
static void FUN_00cfdeb0(BlockStack_cfde* s);
void zz_probe_cfdeb0(BlockStack_cfde* s);
// Havok: build index maps for a selection and propagate it through records and links (hkArray<hkInt16> maps).
typedef short hkInt16;
typedef unsigned short hkUint16;
struct hkBoolX
{
    char m_cBooleanValue;
    hkBoolX() throw()
    {}
    hkBoolX(bool b) throw()
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(T* p, int numElem) throw()
    {
        ReturnMemory(p, numElem * int(sizeof(T)));
    }
};
struct hkMemoryRouterX
{
    int m_pad00, m_pad04, m_pad08, m_pad0c;
    hkMemoryAllocator* m_pStreamAllocator;
    static hkMemoryRouterX& GetMonitorStream() throw();
    __forceinline hkMemoryAllocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct hkArrayUtilX
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& a, void* array, int reqElements, int sizeElem) throw();
    static void __cdecl GrowArray(hkMemoryAllocator& a, void* array, int sizeElem) throw();
    template <typename T> static __forceinline void construct(T* p, int n, const T& t) throw()
    {
        for (int i = 0; i < n; ++i)
            p[i] = t;
    }
};
template <typename T> struct hkArrayX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArrayX() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~hkArrayX() throw()
    {
        _clearAndDeallocate(hkMemoryRouterX::GetMonitorStream().heap());
    }

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtilX::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        const int numToFill = n - m_iElementCount;
        T* dst = m_data + m_iElementCount;
        for (int i = 0; i < numToFill; ++i)
            dst[i] = fill;
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize(hkMemoryRouterX::GetMonitorStream().heap(), n, fill);
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, int t) throw()
    {
        if (m_iElementCount == getCapacity())
            hkArrayUtilX::GrowArray(alloc, this, sizeof(T));
        T value = (T)t;
        hkArrayUtilX::construct(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }
    __forceinline void AddBack(int t) throw()
    {
        _pushBack(hkMemoryRouterX::GetMonitorStream().heap(), t);
    }
};
struct IndexSource
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int m_iStridedVertexCount;
};
struct SelRecord
{
    hkInt16 m_vFrom;
    hkUint16 m_vTo;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct SelLink
{
    hkUint16 m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
hkBoolX __cdecl WalkChainUntilLimit(const IndexSource* src, int a, int b, hkArrayX<hkInt16>& out) throw();
struct Selection
{
    int unk00, unk04, unk08, unk0c;
    hkArrayX<hkInt16> m_ppIndices;
};
struct SelectionMapper
{
    int unk00, unk04, unk08, unk0c;
    IndexSource* m_pObservedSource;
    IndexSource* m_target;
    SelRecord* m_records;
    int m_numRecords;
    int unk20;
    SelLink* m_ppLinks;
    int m_numLinks;
    void MapSelection(const Selection& sel, hkArrayX<hkInt16>& sourceMap, hkArrayX<hkInt16>& targetMap,
                      hkArrayX<hkInt16>& output);
};
#include <xmmintrin.h>
#include <xmmintrin.h>
extern "C" bool __cdecl FUN_00ce2a00(int mappingType, const FnvSpawnedObject* transform);
struct FUN_00cb1600
{
    void* vtable;
    void* writer;
    int flags;
    FUN_00cb1600(char*, int) throw();
    void __thiscall FUN_00cc00e0() throw();
    FUN_00cb1600& __thiscall FUN_00cc01c0(const char*) throw();
    FUN_00cb1600& __thiscall WriteName(const void*) throw();
};
struct CEError
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void report(int, unsigned int, const char*, const char*, int) throw();
};
extern int DAT_01268360;
extern const char DAT_010cba14, DAT_010cb9f8, DAT_010cb9d8, DAT_010cb9c4;
extern const char DAT_010cb9b0, DAT_010cb98c, DAT_010cb964, DAT_010cb8d0;
struct CEBoneName
{
    void* name;
    int flags;
};
struct CESkeleton
{
    int unk00;
    int unk04;
    int unk08;
    short* parents;
    int unk10;
    int unk14;
    CEBoneName* names;
    int count;
};
struct CESingle
{
    short source, target;
    int unk04, unk08, unk0c;
    FnvSpawnedObject transform;
};
struct CERange
{
    short startA, endA, startB, endB;
    int unk08, unk0c;
    FnvSpawnedObject transformA;
    FnvSpawnedObject transformB;
};
struct CEMap
{
    CESkeleton* a;
    CESkeleton* b;
    CESingle* singles;
    int singleCount;
    int unk10;
    CERange* ranges;
    int rangeCount;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int checker;
};
struct CEAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void free(void*, int) throw();
};
struct CECountArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int* m_pStackAllocation;
};
void __cdecl FUN_00ce43e0(CEMap* map);
extern __m128 DAT_010c71b0;
extern float DAT_01012068;
struct MapperInitialization
{
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
    unsigned char unk60;
    void __thiscall FUN_00ce5310();
};

#include <xmmintrin.h>

struct ElemA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
struct ElemB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v0;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    __m128 m_v1;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct ScaleObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ElemA* m_pA;
    int m_nCallbackId;
    int unk20;
    ElemB* m_pB;
    int m_nB;
};

// @fnv 0x00ce54c0
void __cdecl FUN_00ce54c0(ScaleObj* obj, float scale)
{
    for (int i = 0; i < obj->m_nCallbackId; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pA[i].m_v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pA[i].m_v);
    }
    for (int i = 0; i < obj->m_nB; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pB[i].m_v0 = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pB[i].m_v0);
        __m128 t = _mm_load_ss(&scale);
        obj->m_pB[i].m_v1 = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), obj->m_pB[i].m_v1);
    }
}

extern "C" void _ReadWriteBarrier();

struct ScalarValue
{
    __m128 v;
    ScalarValue(__m128 x) : v(x)
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(v, v, 0);
    }
};
struct __declspec(align(16)) VectorValue
{
    __m128 v;
    void apply(const ScalarValue& s)
    {
        v = _mm_mul_ps(s.splat(), v);
    }
};
struct QsTransform
{
    VectorValue m_vTranslation;
    __m128 m_rotation;
    VectorValue m_vScale;
};

extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;

extern const __m128 DAT_010c71c0;
extern const __m128 DAT_010c71d0;

static __forceinline float LengthSquared4(__m128 v, float& out)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    __m128 s1 = _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
    _mm_store_ss(&out, s1);
    return out;
}

static __forceinline __m128 LengthSquared4v(__m128 v)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    return _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
}

static __forceinline void Normalize4(QsTransform* p)
{
    float dots[4];
    __declspec(align(16)) float len2[4];
    len2[0] = LengthSquared4(p[0].m_rotation, dots[0]);
    len2[1] = LengthSquared4(p[1].m_rotation, dots[1]);
    len2[2] = LengthSquared4(p[2].m_rotation, dots[2]);
    len2[3] = LengthSquared4(p[3].m_rotation, dots[3]);
    _ReadWriteBarrier();
    __m128 x = _mm_load_ps(len2);
    __m128 y0 = _mm_rsqrt_ps(x);
    __m128 ree = _mm_mul_ps(_mm_mul_ps(y0, x), y0);
    __m128 t = _mm_sub_ps(DAT_010c71c0, ree);
    y0 = _mm_mul_ps(y0, DAT_010c71d0);
    __m128 inv = _mm_mul_ps(t, y0);
    __m128 s0 = _mm_shuffle_ps(inv, inv, 0);
    p[0].m_rotation = _mm_mul_ps(s0, p[0].m_rotation);
    __m128 s1 = _mm_shuffle_ps(inv, inv, 0x55);
    s1 = _mm_shuffle_ps(s1, s1, 0);
    p[1].m_rotation = _mm_mul_ps(s1, p[1].m_rotation);
    __m128 s2 = _mm_shuffle_ps(inv, inv, 0xAA);
    s2 = _mm_shuffle_ps(s2, s2, 0);
    __m128 s3 = _mm_shuffle_ps(inv, inv, 0xFF);
    p[2].m_rotation = _mm_mul_ps(s2, p[2].m_rotation);
    _ReadWriteBarrier();
    s3 = _mm_shuffle_ps(s3, s3, 0);
    p[3].m_rotation = _mm_mul_ps(s3, p[3].m_rotation);
}

// @fnv 0x00ce4e20
void __cdecl FUN_00ce4e20(QsTransform* xforms, const float* volatile weights, unsigned int count)
{
    unsigned int i = 0;
    if (count > 0)
    {
        const float* input = weights;
        __m128 one = _mm_load_ss(&DAT_01012068);
        QsTransform* scaled = xforms;
        do
        {
            ScalarValue inv(_mm_div_ss(_mm_load_ss(&one.m128_f32[0]), _mm_load_ss(input + i)));
            scaled->m_vTranslation.apply(inv);
            scaled->m_vScale.apply(inv);
            ++i;
            ++scaled;
        } while (i < count);
    }

    unsigned int n4 = count >> 2;
    QsTransform* batch = xforms;
    if (n4 > 0)
    {
        do
        {
            Normalize4(batch);
            batch += 4;
        } while (--n4);
    }

    unsigned int rem = count & 3;
    if (rem > 0)
    {
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 half = _mm_set_ss(DAT_01016248);
        unsigned int n = rem;
        do
        {
            __m128 v = batch->m_rotation;
            __m128 len2 = LengthSquared4v(v);
            __m128 y0 = _mm_rsqrt_ss(len2);
            __m128 ree = _mm_mul_ss(_mm_mul_ss(len2, y0), y0);
            __m128 refined = _mm_mul_ss(_mm_mul_ss(half, y0), _mm_sub_ss(three, ree));
            __m128 factor = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), refined);
            factor = _mm_shuffle_ps(factor, factor, 0);
            batch->m_rotation = _mm_mul_ps(factor, v);
            ++batch;
        } while (--n);
    }
}

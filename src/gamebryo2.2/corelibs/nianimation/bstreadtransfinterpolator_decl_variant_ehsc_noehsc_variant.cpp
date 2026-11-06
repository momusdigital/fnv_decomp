
// src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator_decl_variant_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00a43690: the skeleton of src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp
// with declarations corrected to what the original code does (unit: struct BSTreadTransfInterpolator { ~BSTreadTransfInterpo -> ). Move the function to its real unit once
// that unit declares it this way.
// src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00a43560_shell
{
    unsigned char m_auiShapeKeys[0x20];
    void* m_ptr_20;
    int __thiscall GetKeyCount(short arg);
};
struct FUN_00a43580_shell
{
    void* __thiscall FUN_00a43580(unsigned short flag);
};
struct FUN_00a435a0_shell
{
    void* FUN_00a435a0(short arg1);
};
extern "C" void __cdecl __Dummy_00b6fef0(void* ptr, unsigned int flags);
struct FUN_00a435c0_shell
{
    unsigned char m_auiShapeKeys[0x20];
    void* m_ptr_20;
    char __thiscall FUN_00a435c0(short arg);
};
struct TrackFlags
{
    unsigned char value;
};
struct SampleTrack
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int count;
    float* times;
    float* values;
    TrackFlags flags;
};
float __cdecl InterpolateKey(float, float*, float*, unsigned int, unsigned int*, TrackFlags);
struct FUN_00a434b0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    float previousTime;
    unsigned int unk0c;
    unsigned int unk10;
    float previousValue;
    float valueDelta;
    unsigned int sampleIndex;
    SampleTrack* track;
    bool __thiscall UpdateSampleValue(float time, int, int);
};
struct FUN_00a435e0_shell
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(int arg);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;

    bool __thiscall GetChannelPosed(int arg);
};
inline void FUN_00a435e0_shell::v01()
{}
inline void FUN_00a435e0_shell::v02()
{}
inline void FUN_00a435e0_shell::v03()
{}
inline void FUN_00a435e0_shell::v04()
{}
inline void FUN_00a435e0_shell::v05()
{}
inline void FUN_00a435e0_shell::v06()
{}
inline void FUN_00a435e0_shell::v07()
{}
inline void FUN_00a435e0_shell::v08()
{}
inline void FUN_00a435e0_shell::v09()
{}
inline void FUN_00a435e0_shell::v0a()
{}
inline void FUN_00a435e0_shell::v0b()
{}
inline void FUN_00a435e0_shell::v0c()
{}
inline void FUN_00a435e0_shell::v0d()
{}
inline void FUN_00a435e0_shell::v0e()
{}
inline void FUN_00a435e0_shell::v0f()
{}
inline void FUN_00a435e0_shell::v10()
{}
inline void FUN_00a435e0_shell::v11()
{}
inline void FUN_00a435e0_shell::v12()
{}
inline void FUN_00a435e0_shell::v13()
{}
inline void FUN_00a435e0_shell::v14()
{}
inline void FUN_00a435e0_shell::v15()
{}
inline void FUN_00a435e0_shell::v16()
{}
inline void FUN_00a435e0_shell::v17()
{}
inline void FUN_00a435e0_shell::v18()
{}
inline void FUN_00a435e0_shell::v19()
{}
inline void FUN_00a435e0_shell::v1a()
{}
inline void FUN_00a435e0_shell::v1b()
{}
inline void FUN_00a435e0_shell::v1c()
{}
inline void FUN_00a435e0_shell::v1d()
{}
inline void FUN_00a435e0_shell::v1e()
{}
inline void FUN_00a435e0_shell::v1f()
{}
inline void FUN_00a435e0_shell::v20()
{}
inline void FUN_00a435e0_shell::v21()
{}
inline void FUN_00a435e0_shell::v22()
{}
inline void FUN_00a435e0_shell::v23()
{}
inline void FUN_00a435e0_shell::v24()
{}
inline void FUN_00a435e0_shell::v25()
{}
inline void FUN_00a435e0_shell::v26()
{}
inline void FUN_00a435e0_shell::v27()
{}
inline void FUN_00a435e0_shell::v28()
{}
inline void FUN_00a435e0_shell::v29()
{}
inline void FUN_00a435e0_shell::v2a()
{}
inline void FUN_00a435e0_shell::v2b()
{}
inline void FUN_00a435e0_shell::v2c()
{}
inline void FUN_00a435e0_shell::v2d()
{}
inline void FUN_00a435e0_shell::v2e()
{}
inline void FUN_00a435e0_shell::v2f()
{}
inline void FUN_00a435e0_shell::v30()
{}
inline void FUN_00a435e0_shell::v31()
{}
inline void FUN_00a435e0_shell::v32()
{}
inline void FUN_00a435e0_shell::v33()
{}
inline void FUN_00a435e0_shell::v34()
{}
inline void FUN_00a435e0_shell::v35()
{}
inline void FUN_00a435e0_shell::v36()
{}
inline void FUN_00a435e0_shell::v37()
{}
inline void FUN_00a435e0_shell::v38(int)
{}
bool FUN_00a435e0_shell::GetChannelPosed(int arg)
{
    if (unk20 != 0)
    {
        v38(arg);
    }
    return false;
}
class A43600BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A43600BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A43600BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class A43600Object;
class A43600Stream
{
  public:
    void SerializeString(void* pkString);
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
    virtual void SaveLinkID(A43600Object* pkObject);
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
    A43600BinaryStream* m_pBackingStream;
};
template <class T>
inline void A43600BinaryStreamSave(A43600BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void A43600SaveBinary(A43600Stream& kStream, const T& value)
{
    A43600BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class A43600Color
{
  public:
    float r;
    float g;
    float b;
    float a;

    void SaveBinary(A43600Stream& kStream);
};
struct A43600Entry
{
    A43600Color m_kColor0;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    A43600Color m_kColor1;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    void* m_kName;
};
class A43600Base
{
  public:
    void SaveBinaryBase(A43600Stream& kStream);
};
class A43600Controller : public A43600Base
{
  public:
    void FUN_00a43600(A43600Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    A43600Entry* m_pkEntryArray;
    unsigned int m_uiNumEntries;
    int unk14;
    int unk18;
    int unk1C;
    A43600Object* m_pkTarget;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern const char* DAT_0109b220;
struct FixedStringHeader
{
    volatile long references;
    unsigned int unk04;
};
struct NiFixedString
{
    const char* value;
    static FixedStringHeader* Header(const char* text)
    {
        return reinterpret_cast<FixedStringHeader*>(const_cast<char*>(text)) - 1;
    }
    ~NiFixedString()
    {
        if (value != DAT_0109b220)
            InterlockedDecrement(&Header(value)->references);
    }
    NiFixedString& operator=(const NiFixedString& other)
    {
        if (value != other.value)
        {
            const char* next = other.value;
            if (next != DAT_0109b220)
                InterlockedIncrement(&Header(next)->references);
            if (value != DAT_0109b220)
                InterlockedDecrement(&Header(value)->references);
            value = next;
        }
        return *this;
    }
};
struct MemoryManager
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
struct NiQuatTransform
{
    float x, y, z;
    float qx, qy, qz, qw;
    float scale;
};
struct TreadTransformEntry
{
    NiQuatTransform first;
    NiQuatTransform second;
    NiFixedString name;
    TreadTransformEntry();
    static void* operator new[](unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long references;
    void DecRefCount()
    {
        if (InterlockedDecrement(&references) == 0)
            DeleteThis();
    }
};
class NiObject : public NiRefObject
{
};
class NiInterpolator : public NiObject
{
  public:
    float lastTime;
    void FUN_00aa0ab0(NiInterpolator*, void*);
};
template <class T> struct NiPointer
{
    T* object;
    NiPointer& operator=(const NiPointer& other)
    {
        if (object != other.object)
        {
            if (object)
                object->DecRefCount();
            object = other.object;
            if (object)
                InterlockedIncrement(&object->references);
        }
        return *this;
    }
};
class BSTreadTransfInterpolator : public NiInterpolator
{
  public:
    TreadTransformEntry* entries;
    unsigned int count;
    float firstValue;
    float secondValue;
    unsigned int unk1c;
    NiPointer<NiObject> reference;
    void FUN_00a43690(BSTreadTransfInterpolator*, void*);
};
// @fnv 0x00a43690
void BSTreadTransfInterpolator::FUN_00a43690(BSTreadTransfInterpolator* destination, void* context)
{
    FUN_00aa0ab0(destination, context);
    delete[] destination->entries;
    destination->count = count;
    destination->entries = new TreadTransformEntry[count];
    for (unsigned int i = 0; i < count; i++)
    {
        destination->entries[i].name = entries[i].name;
        destination->entries[i].first = entries[i].first;
        destination->entries[i].second = entries[i].second;
    }
    destination->reference = reference;
    destination->firstValue = firstValue;
    destination->secondValue = secondValue;
}

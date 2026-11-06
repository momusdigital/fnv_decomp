
// src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_011f3f90;
void* __cdecl FUN_00a4be10();
struct NiLookAtInterpolator
{
    virtual ~NiLookAtInterpolator();
    void* __thiscall FUN_00a4c5c0(unsigned int flags);
};
extern "C" void __cdecl FUN_00a4be20();
extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);
class NiAVObject;
struct NiFixedString
{
    void* p;
};
struct NiAVObjectPalette
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34();
    virtual NiAVObject* FindAVObject(NiFixedString&);
};
struct Holder_00a4b8d0
{
    bool ResolveTargetObject(NiAVObjectPalette* pkPalette);
};
struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93060
{
    bool GetAt(char const*, ShaderBufferRecord*&);
};
struct CloningProcess
{
    NiTStringPointerMap_00e93060* m_pCloneMap;
};
struct NiObject
{
    virtual void ProcessClone(CloningProcess&);
};
struct Host_00a4bb80
{
    void __thiscall FUN_00a4bb80(CloningProcess&);
};
struct NiStream
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void Register(void*);
};
struct ObjType
{
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual void G3();
    virtual void G4();
    virtual void G5();
    virtual void G6();
    virtual void G7();
    virtual void G8();
    virtual void G9();
    virtual void G10();
    virtual void G11();
    virtual void G12();
    virtual void G13();
    virtual void G14();
    virtual void G15();
    virtual void G16();
    virtual void G17();
    virtual void G18();
    virtual void G19();
    virtual void G20();
    virtual bool RegisterStreamables(NiStream*);
};
struct BaseInterp
{
    bool __thiscall FUN_00a81fe0(NiStream*);
};
struct MyInterp
{
    bool __thiscall FUN_00a4bbe0(NiStream*);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void* __thiscall FUN_00a4bcf0(unsigned int a, unsigned int b, unsigned int c);
};
void* __cdecl FUN_00a4c5a0();
struct FUN_00a4b900_V
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
};
struct FUN_00a4b900_Holder
{
    void Collapse();
};
struct FakeInterp
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void SetActiveTimeRange(float, float);
};
struct Holder
{
    void __thiscall FUN_00a4b9f0(float m_fStartTime, float m_fMaximumDistance);
};
extern "C" const float g_01098b04;
extern "C" const float g_01015f5c;
extern "C" const double g_010231b0;
extern "C" const double g_010241b0;
struct FUN_00a4b930_item
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void GetRange(float* pMin, float* pMax);
};
struct FUN_00a4b930_cls
{
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
    FUN_00a4b930_item* m_pItems[3];

    void __thiscall GetItemsRange(float* pStart, float* pEnd);
};
extern "C" void* g_0109b220;
extern "C" void* g_011f49e0;
void* __cdecl FUN_00a5b690(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* pTarget);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* pTarget);
struct RegObj
{
    int m_i00;
    int m_i04;
    void* m_08;
};
struct FUN_00a4bae0_cls
{
    int m_i00;
    int m_i01;
    int m_i02;
    int m_i03;
    RegObj* m_pReg;
    void* m_hCur;
    bool FUN_00a4bae0();
};
class A4BC40Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual bool IsEqual(A4BC40Object* pkObject);
};
struct A4BC40Transform
{
    bool operator==(const A4BC40Transform& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class A4BC40Base : public A4BC40Object
{
  public:
    bool BaseIsEqual(A4BC40Object* pkObject);

    int unk04;
    int unk08;
};
class A4BC40Data : public A4BC40Base
{
  public:
    unsigned short m_usFlags;
    unsigned short unk0E;
    A4BC40Object* m_pkRotation;
    int unk14;
    A4BC40Transform m_kTransform;
    A4BC40Object* m_ppKeyData[3];

    bool FUN_00a4bc40(A4BC40Object* pkObject);
};
struct Builder
{
    void FUN_00a4c4b0(BSFadeNode*, unsigned int);
    BSFadeNode* CreateFadeNode(unsigned int);
};
struct Arg_b9286
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m08;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
    void __thiscall FUN_0096ad30(unsigned int n);
    void __thiscall FUN_0096ae90(unsigned int n, void** out);
};
struct Holder_b9286
{
    void __thiscall FUN_00a38cb0(Arg_b9286* a);
};
struct Obj_b9286
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Visit(Arg_b9286* a);
};
extern "C" void* g_011f3f90;
extern "C" void* __cdecl FUN_00a7d330(void* p);
extern "C" void* __cdecl FUN_00a7d5a0(const char* s, void* p);
struct FUN_00a4c780_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    Obj_b9286* m38;
    Obj_b9286* m3c;
    Obj_b9286* m40;

    void __thiscall FUN_00a570b0(Arg_b9286* a);

    void FUN_00a4c780(Arg_b9286* a);
};
// LoadBinary: base interpolator data, flags, the linked object, the name, the transform and three linked interpolators.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class C630RefObject
{
  public:
    virtual void Unk00();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }

    long m_lRefCount;
};
template <class T> class C630Pointer
{
  public:
    C630Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* m_pObject;
};
class C630BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C630BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void C630LoadBinary(C630BinaryStream& kStream, T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&rValue, sizeof(T), &uiSize, 1);
}
class C630FixedString
{
  public:
    const char* m_pcHandle;
};
class C630Stream
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
    unsigned int m_uiFileVersion;
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
    C630BinaryStream* m_pUnderlyingStream;

    void* DeserializeObject();
    void ReadFixedString(C630FixedString& kString);
    void ReadStringTableEntry(C630FixedString& kString);
};
class C630Transform
{
  public:
    void LoadBinary(C630Stream& kStream);

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
};
class C630Interpolator
{
  public:
    void LoadBinary(C630Stream& kStream);
};
class C630Blend : public C630Interpolator
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0E;
    void* m_pkTarget;
    C630FixedString m_kName;
    C630Transform m_kTransform;
    C630Pointer<C630RefObject> m_akReferencedObjects[3];

    void FUN_00a4c630(C630Stream& kStream);
};
struct BinaryOutput341
{
    void* state;
    unsigned int position;
    void* read;
    unsigned int(__cdecl* write)(BinaryOutput341*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Write(const void* data, unsigned int length, unsigned int* sizes, unsigned int count)
    {
        unsigned int bytes = write(this, data, length, sizes, count);
        position += bytes;
        return bytes;
    }
};
template <class T> inline void SaveBinary341(BinaryOutput341& output, const T& value)
{
    unsigned int size = sizeof(T);
    output.Write(&value, sizeof(T), &size, 1);
}
struct Stream341
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SaveLink(void*);
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
    BinaryOutput341* output;
    void WriteObjectLink(const void* name);
};
struct Transform341
{
    float translationX, translationY, translationZ;
    float rotationW, rotationX, rotationY, rotationZ;
    float scale;
    void FUN_00a38b60(Stream341*);
};
struct Interpolator341
{
    virtual ~Interpolator341();
    unsigned int referenceCount;
    float lastTime;
    void FUN_00a724d0(Stream341*);
};
struct LookAt341 : Interpolator341
{
    unsigned short flags, unk0e;
    void* target;
    const char* targetName;
    Transform341 transform;
    void* interpolators[3];
    void SaveToStream(Stream341* stream);
};

extern "C" char* g_NullStringHandle_0109b220;
extern "C" char* g_StaticFixedString_011f49e0;

class LAFixedString
{
  public:
    ~LAFixedString()
    {
        DecRefCount(m_kHandle);
    }
    LAFixedString& operator=(const LAFixedString& kString)
    {
        char* h = kString.m_kHandle;
        if (m_kHandle != h)
        {
            IncRefCount(h);
            DecRefCount(m_kHandle);
            m_kHandle = h;
        }
        return *this;
    }
    static void IncRefCount(char* h)
    {
        if (h == g_NullStringHandle_0109b220)
            return;
        InterlockedIncrement((long volatile*)(h - 8));
    }
    static void DecRefCount(char* h)
    {
        if (h == g_NullStringHandle_0109b220)
            return;
        InterlockedDecrement((long volatile*)(h - 8));
    }
    char* m_kHandle;
};

class LARefObject
{
  public:
    virtual ~LARefObject();
    virtual void DeleteThis();
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
    long m_lRefCount;
};

template <class T> class LAPointer
{
  public:
    ~LAPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

class NiInterpolator : public LARefObject
{
  public:
    virtual ~NiInterpolator();
    int unk08;
    int unk0C;
    int unk10;
};

class NiLookAtInterpolatorX : public NiInterpolator
{
  public:
    virtual ~NiLookAtInterpolatorX();
    LAFixedString m_kTargetNodeName;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    LAPointer<NiInterpolator> m_akReferencedObjects[3];
};

// @fnv 0x00a4be20
NiLookAtInterpolatorX::~NiLookAtInterpolatorX()
{
    m_kTargetNodeName = *(LAFixedString*)&g_StaticFixedString_011f49e0;
}

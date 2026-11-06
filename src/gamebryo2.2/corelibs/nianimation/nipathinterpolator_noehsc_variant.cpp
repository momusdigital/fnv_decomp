
// src/gamebryo2.2/corelibs/nianimation/nipathinterpolator_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_011f3f68;
void* __cdecl FUN_00a3dab0();
struct FUN_00a3dae0_shell
{
    void* __thiscall GetKeyCount(short idx);
};
struct FUN_00a3db10_shell
{
    int __thiscall GetValueByIndex(short arg);
};
struct FUN_00a3db40_shell
{
    int __thiscall FUN_00a3db40(short arg);
};
struct FUN_00a3db70_shell
{
    char __thiscall FUN_00a3db70(unsigned short arg);
};
extern "C" void* g_011f3e48;
void* __cdecl FUN_00a3dde0();
struct FloatDataHelper
{
    void __thiscall FUN_00a3cc40(float m_fStartTime, float m_fMaximumDistance);
};
struct NiPathInterpolator
{
    void* m_pPathInterp;
    void __thiscall FUN_00a3dc50(float m_fStartTime, float m_fMaximumDistance);
};
int __stdcall GetChannelIndex(unsigned short usChannel);
extern "C" void __cdecl FUN_00a48fb0();
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00a3dac0_shell
{
    void* __thiscall DestroyIfOdd(short idx);
};
struct FUN_00a3ddf0_shell
{
    void* __thiscall FUN_00a3ddf0(void* pData, int i1, int i2, float fTime);
};
extern void* DAT_011f3ca8[];
void __cdecl FUN_00a3dd40();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00a3e980_shell
{
    void* __thiscall Destroy(unsigned int flags);
};
struct StrArr
{
    void* m_pData;
    int _04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _0C;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
struct FUN_00a3cbf0_shell
{
    void __thiscall GetViewerStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
extern const char* _g_011f3e48;
struct TargetHolder : FUN_00a3cbf0_shell
{
    void __thiscall AppendString(StrArr*);
};
class CloningProcess
{
  public:
    void* m_pCloneMap;
};
struct NiObject
{
    virtual void __thiscall _v00();
    virtual void __thiscall _v01();
    virtual void __thiscall _v02();
    virtual void __thiscall _v03();
    virtual void __thiscall _v04();
    virtual void __thiscall _v05();
    virtual void __thiscall _v06();
    virtual void __thiscall _v07();
    virtual void __thiscall _v08();
    virtual void __thiscall _v09();
    virtual void __thiscall _v10();
    virtual void __thiscall _v11();
    virtual void __thiscall _v12();
    virtual void __thiscall _v13();
    virtual void __thiscall _v14();
    virtual void __thiscall _v15();
    virtual void __thiscall _v16();
    virtual void __thiscall _v17();
    virtual void __thiscall _v18();
    virtual void __thiscall _v19();
    virtual void __thiscall _v20();
    virtual void __thiscall _v21();
    virtual void __thiscall _v22();
    virtual void __thiscall _v23();
    virtual void __thiscall _v24();
    virtual void __thiscall _v25();
    virtual void __thiscall ProcessClone(CloningProcess&);
};
struct PathPtr
{
    NiObject* m_pObject;
};
struct PctPtr
{
    NiObject* m_pObject;
};
struct FUN_00a3dc80_shell
{
    char _pad[0x18];
    PathPtr m_pPathObject;
    PctPtr m_pPathInterp;
    void __thiscall FUN_00a3dc80(CloningProcess&);
};
struct HC1Base
{
    bool __thiscall FUN_00aa0ad0(void*);
};
struct FUN_00a3dcc0_Reg
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual bool RegisterStreamables(void*);
};
struct FUN_00a3dcc0_cls
{
    char _pad[0x18];
    FUN_00a3dcc0_Reg* m_path;
    FUN_00a3dcc0_Reg* m_pct;
    bool __thiscall FUN_00a3dcc0(void*);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a3f060_shell
{
    void* __thiscall FUN_00a3f060(short, short);
};
void* __cdecl CreateA51BF0Base();
extern float DAT_01097170;
extern float DAT_01015f5c;
extern double DAT_010231b0;
extern double DAT_010241b0;
struct FUN_00a3dba0_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}
    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}
    virtual void vfB0()
    {}
    virtual void vfB4()
    {}
    virtual void vfB8()
    {}
    virtual void vfBC()
    {}

    virtual void __thiscall GetRange(float* fTargetUpperBound, float* fMinimumInputValue);

    virtual void vfC4()
    {}
    virtual void vfC8()
    {}
    virtual void vfCC()
    {}
    virtual void vfD0()
    {}
    virtual void vfD4()
    {}
    virtual void vfD8()
    {}
    virtual void vfDC()
    {}

    float* __thiscall FUN_00a3ca80(int index, int mode);
    float* __thiscall FUN_00a3ca80(int index);
};
struct FUN_00a3dba0_Class1 : FUN_00a3dba0_Class
{
    virtual unsigned int __thiscall vfE0(unsigned int index);
};
struct FUN_00a3dba0_Class2 : FUN_00a3dba0_Class
{
    virtual unsigned int __thiscall vfE0(unsigned int index, unsigned int mode);
};
struct Stream
{
    unsigned int flags, bytesRead;
    int(__cdecl* readProc)(Stream*, void*, unsigned int, unsigned int*, int);
    __forceinline int Read(void* dst, unsigned int count)
    {
        unsigned int actual = count;
        return readProc(this, dst, count, &actual, 1);
    }
};
struct Source
{
    Stream* stream()
    {
        return *reinterpret_cast<Stream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
    void __thiscall FUN_00a645b0();
};
void __stdcall FUN_00aa0ac0(Source*);
struct PathData
{
    unsigned int unk00, unk04, unk08;
    unsigned short channel, unk0e;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int value28, value2c;
    unsigned short channel30, unk32;
    unsigned int unk34, value38;
    void __thiscall ReadFromStream(Source*);
};
struct FNV_WriteStream;
typedef int(__cdecl* FNV_WriteFn)(FNV_WriteStream* stream, void* data, int size, int* written, int flag);
struct FNV_NiStreamPad
{
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
};
struct FNV_NiStream
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12(int value);
    FNV_NiStreamPad pad;
    FNV_WriteStream* m_pWriter;
};
struct FNV_WriteStream
{
    int unk00;
    int m_uiItemCount;
    void* unk08;
    FNV_WriteFn m_pfn;
};
struct FNV_Writer
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float unk24;
    int unk28;
    int unk2c;
    unsigned short unk30;
    unsigned short unk32;
    float unk34;
    int unk38;
    void __thiscall FUN_00a95ca0(FNV_NiStream* pStream);
    void __thiscall WriteToStream(FNV_NiStream* pStream);
};
static __forceinline void FNV_WriteField(FNV_WriteStream* pWriter, void* pData, int nSize)
{
    int n = nSize;
    int r = pWriter->m_pfn(pWriter, pData, n, &n, 1);
    pWriter->m_uiItemCount += r;
}
__declspec(dllimport) long __stdcall InterlockedIncrement(long* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long* p);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl NiMalloc(unsigned int);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class NiObj2 : public NiRefObject
{
  public:
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
    virtual NiObj2* CreateSharedClone(CloningProcess& kCloning);
};
class NiPosData : public NiObj2
{
  public:
    unsigned int m_uiNumKeys;
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    NiPointer& operator=(T* pObject)
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
};
class NiInterpolatorBase : public NiObj2
{
  public:
    void CopyMemberData(NiInterpolatorBase* pDest, CloningProcess& kCloning);
    float m_fLastTime;
    unsigned short m_uiObjectFlags;
    void SetBit(bool bVal, unsigned short uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    bool GetBit(unsigned short uMask) const
    {
        return (m_uiObjectFlags & uMask) != 0;
    }
};
class NiPathInterp : public NiInterpolatorBase
{
  public:
    int unk10;
    int unk14;
    NiPointer<NiPosData> m_pPathObject;
    NiPointer<NiPosData> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    short unk32;
    int unk34;
    int m_iPathPointCount;

    float CalcTotalLength();
    void SetConstVelocity(bool b)
    {
        SetBit(b, 0x10);
        if (b && GetBit(1))
        {
            m_fTotalPathLength = CalcTotalLength();
            SetBit(false, 1);
        }
    }
    void FUN_00a3f2f0(NiPathInterp* pDest, CloningProcess& kCloning);
};
class NiObjectA3F
{
  public:
    NiObjectA3F(void* pvFirst, void* pvSecond) throw();
    virtual ~NiObjectA3F();

    static void* operator new(unsigned int uiSize);

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
};
class NiCloningProcessA3F;
class NiOwnerA3F
{
  public:
    void CopyMemberData(NiObjectA3F* pkDest, NiCloningProcessA3F& kCloning);
    NiObjectA3F* CloneObject(NiCloningProcessA3F& kCloning);
};
struct MyPosKey
{
    float m_fTime;
};
struct MyPosData : public NiPosData
{
    MyPosKey* m_pKeyArray;
    int unk10;
    unsigned char m_ucKeyDataSize;
};
static __forceinline MyPosKey* GetKey(MyPosKey* pkKeys, unsigned int uiIndex, unsigned char ucKeySize)
{
    return (MyPosKey*)((const char*)pkKeys + uiIndex * ucKeySize);
}
struct PathInterpExt : public NiPathInterp
{
    void __thiscall FUN_00a3ea60(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime);
    void FindKeyPair(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime);
};
static const float kNegMax = -3.402823466e+38f;
class NiPoint3
{
  public:
    float x, y, z;
};
class NiQuaternion
{
  public:
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};
extern const NiPoint3 DAT_011a9424;
extern NiQuaternion DAT_011f4208;
class NiFloatData : public NiObj2
{
};
template <class T> class NiPtrAB
{
  public:
    NiPtrAB(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    T* m_pObject;
};
class NiKeyBasedInterpolator
{
  public:
    NiKeyBasedInterpolator();
    virtual void v00();
    long m_uiRefCount;
    float m_fLastTime;
    unsigned short m_uiObjectFlags;
};
class FUN_00a3f060 : public NiKeyBasedInterpolator
{
  public:
    FUN_00a3f060(NiPosData* pkPathData, NiFloatData* pkPctData);
    unsigned int m_uiPathKeyCount;
    unsigned int m_uiPercentKeyCount;
    NiPtrAB<NiPosData> m_pPathObject;
    NiPtrAB<NiFloatData> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    float m_fPathLength;
    int m_iPathPointCount;
    NiQuaternion m_kRotationMatrix;
    NiPoint3 m_kPathOffset;
    float m_fLast;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

class NiRefObjectE6F0
{
  public:
    virtual ~NiRefObjectE6F0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerE6F0
{
  public:
    NiPointerE6F0(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerE6F0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerE6F0& operator=(const NiPointerE6F0& ptr)
    {
        T* pObject = ptr.m_pObject;
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

class InterpolatorE6F0 : public NiRefObjectE6F0
{
  public:
    void GetControllerSequence(float fA, float fB, NiPointerE6F0<InterpolatorE6F0>& spOut);
};

class ControllerE6F0
{
  public:
    ControllerE6F0* FUN_00a3e6f0(float fA, float fB);
    ControllerE6F0* CreateCopy(float fA, float fB);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iFadeIndex;
    int unk18;
    NiPointerE6F0<InterpolatorE6F0> m_spInterp;
};

// @fnv 0x00a3e6f0
ControllerE6F0* ControllerE6F0::FUN_00a3e6f0(float fA, float fB)
{
    ControllerE6F0* pkCopy = CreateCopy(fA, fB);
    if (m_spInterp.m_pObject)
    {
        NiPointerE6F0<InterpolatorE6F0> spInterp;
        m_spInterp.m_pObject->GetControllerSequence(fA, fB, spInterp);
        pkCopy->m_spInterp = spInterp;
        pkCopy->m_iFadeIndex = 0;
    }
    return pkCopy;
}

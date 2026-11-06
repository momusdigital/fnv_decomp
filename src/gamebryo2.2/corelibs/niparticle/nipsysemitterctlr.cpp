// gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp: NiPSysEmitterCtlr, NiBoolData, ThisStruct, Host and more (39 functions)

#include "nipsysemitterctlr_types_NiPSysEmitterCtlr.h"
#include "nipsysemitterctlr_types_NiStream.h"
#include "nipsysemitterctlr_external.h"
#include <new>

// @fnv 0x00c1bdf0
void NiPSysEmitterCtlr::LoadBinary(NiStream& stream)
{
    NiPSysModifierCtlr::LoadBinary(stream);
    stream.ResetStreamState();
}

// Calls the base ProcessClone, then clones the interpolator stored in the member if it is non-null.
// @fnv 0x00c1bdc0
void NiPSysEmitterCtlr::ProcessClone(CloningProcess& process)
{
    NiPSysModifierCtlr::ProcessClone(process);
    NiInterpolator* interpolator = m_spVisibilityInterpolator.m_pObject;
    if (interpolator)
        interpolator->ProcessClone(process);
}

// @fnv 0x00c1bd30
void NiPSysEmitterCtlr::CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& arProcess)
{
    NiPSysModifierCtlr::CopyMemberData(destination, arProcess);

    NiInterpolator* source = m_spVisibilityInterpolator.m_pObject;
    if (source)
    {
        NiInterpolator* cloned = static_cast<NiInterpolator*>(source->Clone(arProcess));

        NiInterpolator* oldInterpolator = destination->m_spVisibilityInterpolator.m_pObject;
        if (oldInterpolator != cloned)
        {
            if (oldInterpolator)
                oldInterpolator->DecRefCount();
            destination->m_spVisibilityInterpolator.m_pObject = cloned;
            if (cloned)
                cloned->IncRefCount();
        }
    }

    if ((destination->m_uiObjectFlags & 0x6) == 0 && destination->m_fPhase == 0.0f)
        destination->m_fPhase = GetRandomNumber() / DAT_01029790 * DAT_01017a40;
}

// @fnv 0x00c1c0e0
void NiPSysEmitterCtlr::LinkObject(NiStream& stream)
{
    NiPSysModifierCtlr::LinkObject(stream);

    if (stream.m_uiNifVersion < 0x0a010068)
    {
        NiObject* data = stream.GetLoadedObject();
        if (!data)
            return;

        data->IncRefCount();

        NiFloatInterpolator* floatMemory = static_cast<NiFloatInterpolator*>(NiPSysEmitterCtlr::operator new(0x18));
        NiFloatInterpolator* floatInterpolator;
        if (floatMemory)
            floatInterpolator = new (floatMemory) NiFloatInterpolator(0);
        else
            floatInterpolator = 0;

        unsigned int* fields = reinterpret_cast<unsigned int*>(data);
        floatInterpolator->SetAnimationKeys(reinterpret_cast<void*>(fields[3]), fields[2], fields[4]);
        fields[2] = 0;
        fields[3] = 0;
        fields[4] = 0;
        reinterpret_cast<unsigned char*>(data)[0x14] = 0;
        SetInterpolator(floatInterpolator, 0);

        NiBoolInterpolator* boolMemory = static_cast<NiBoolInterpolator*>(NiPSysEmitterCtlr::operator new(0x18));
        NiBoolInterpolator* boolInterpolator;
        if (boolMemory)
            boolInterpolator = reinterpret_cast<NiBoolInterpController*>(boolMemory)->LinkObject(0);
        else
            boolInterpolator = 0;

        boolInterpolator->SetAnimationKeys(reinterpret_cast<void*>(fields[7]), fields[8], fields[6]);
        fields[6] = 0;
        fields[7] = 0;
        reinterpret_cast<unsigned char*>(data)[0x24] = 0;
        SetInterpolator(boolInterpolator, 1);
        data->DecRefCount();
        return;
    }

    if ((m_uiObjectFlags & 0x6) == 0 && m_fPhase == 0.0f)
        m_fPhase = GetRandomNumber() / DAT_01029790 * DAT_01017a40;

    NiInterpolator* active = static_cast<NiInterpolator*>(stream.GetLoadedObject());
    NiInterpolator* old = m_spVisibilityInterpolator.m_pObject;
    if (old != active)
    {
        if (old)
            old->DecRefCount();
        m_spVisibilityInterpolator.m_pObject = active;
        if (active)
            active->IncRefCount();
    }
}

struct NiSingleInterpControllerBase
{
    char pad[0x30];
    NiSingleInterpControllerBase() throw();
    virtual void f();
};
struct FUN_00a38e00 : NiSingleInterpControllerBase
{
    int m34;
    FUN_00a38e00();
};
// @fnv 0x00a38e00
FUN_00a38e00::FUN_00a38e00()
{
    m34 = 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4054;
// Returns the address of the global object g_011f4054.
// @fnv 0x00a537e0
void* __cdecl FUN_00a537e0()
{
    return &g_011f4054;
}

struct NiTimeControllerStop
{
    void ResetTiming();
};
struct FUN_00c1ba30 : NiTimeControllerStop
{
    char pad[0x48 - 1];
    float m48;
};
// @fnv 0x00c1ba30
void __fastcall FUN_00c1ba30(FUN_00c1ba30* self, int unused)
{
    self->m48 = DAT_01015f5c;
    self->ResetTiming();
}

extern const char* const g_01203340_arg1;
// @fnv 0x00c1c2f0
const char* const* __cdecl FUN_00c1c2f0()
{
    return &g_01203340_arg1;
}

extern int DAT_011ae754;
extern int DAT_011ae758;

// @fnv 0x00c1ba50
const char* const* __stdcall FUN_00c1ba50(unsigned short usIndex)
{
    if (usIndex == 0)
        return reinterpret_cast<const char* const*>(DAT_011ae754);
    int r = (usIndex != 1) - 1;
    r = r & DAT_011ae758;
    return reinterpret_cast<const char* const*>(r);
}

struct NiPSysEmitterCtlr_shell : NiPSysEmitterCtlr
{
    void FUN_00c1bcc0(NiInterpolator* pkInterpolator, unsigned short usIndex);
};

// Stores pkInterpolator into the interpolator slot at offset 0x34 (ref-counted) when usIndex is 0, or at offset 0x40 when usIndex is 1.
// @fnv 0x00c1bcc0
void NiPSysEmitterCtlr_shell::FUN_00c1bcc0(NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    if (usIndex == 0)
    {
        char* p = (char*)this + 0x34;
        NiPointer<NiInterpolator>* pInterpolatorPtr = (NiPointer<NiInterpolator>*)p;
        if (pInterpolatorPtr->m_pObject != pkInterpolator)
        {
            if (pInterpolatorPtr->m_pObject)
                pInterpolatorPtr->m_pObject->DecRefCount();
            pInterpolatorPtr->m_pObject = pkInterpolator;
            if (pInterpolatorPtr->m_pObject)
                pInterpolatorPtr->m_pObject->IncRefCount();
        }
    }
    else if (usIndex == 1)
    {
        char* p = (char*)this + 0x40;
        NiPointer<NiInterpolator>* pInterpolatorPtr = (NiPointer<NiInterpolator>*)p;
        *pInterpolatorPtr = pkInterpolator;
    }
}

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_0109a1d4;
void __cdecl _delete(void*, unsigned int);
struct NiBoolData
{
    char _0[12];
    void* m_pKeyArray;
    void* Destroy(unsigned int);
};
// @fnv 0x00a53a10
void* NiBoolData::Destroy(unsigned int auiFlags)
{
    void* keys = m_pKeyArray;
    *(void**)this = (void*)&DAT_0109a1d4;
    if (keys)
        g_memoryManager.Deallocate((char*)keys - 4);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x18);
    return this;
}

extern "C" int __cdecl NiStricmp(const char*, const char*);
extern const unsigned short DAT_NiInterpController_INVALID_INDEX;
// Compares pcID against two strings and returns 0, 1, or DAT_NiInterpController_INVALID_INDEX when neither matches.
// @fnv 0x00c1ba80
unsigned short __stdcall GetInterpControllerIndex(const char* pcControllerID)
{
    if (NiStricmp(pcControllerID, (const char*)DAT_011ae754) == 0)
        return 0;
    if (NiStricmp(pcControllerID, (const char*)DAT_011ae758) == 0)
        return 1;
    return DAT_NiInterpController_INVALID_INDEX;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct S1
{
    void* FUN_00a3c390(float);
};
struct S2
{
    void* FUN_00a532d0(int);
};
// @fnv 0x00c1bad0
NiInterpolator* __stdcall CreateInterpolatorByIndex(unsigned short usInterpolatorIndex)
{
    if (usInterpolatorIndex == 0)
    {
        void* p = BSFadeNode::operator new(0x18);
        if (!p)
            return 0;
        return (NiInterpolator*)((S1*)p)->FUN_00a3c390(0.0f);
    }
    if (usInterpolatorIndex == 1)
    {
        void* p = BSFadeNode::operator new(0x18);
        if (!p)
            return 0;
        return (NiInterpolator*)((S2*)p)->FUN_00a532d0(0);
    }
    return 0;
}

struct FUN_00c1bb90_Inner
{
    char pad[0x14];
    float v;
};
struct S_00c1bb90
{
    float GetValueForIndex(unsigned char);
};
// Returns the cached float at offset 0x20 when the flag at 0xE is 1 and a matches the byte at 0xF, otherwise the float from the array at 0x14 indexed by a.
// @fnv 0x00c1bb90
float S_00c1bb90::GetValueForIndex(unsigned char a)
{
    if (*(unsigned char*)((char*)this + 0xE) == 1 && a == *(unsigned char*)((char*)this + 0xF))
        return *(float*)((char*)this + 0x20);
    return ((FUN_00c1bb90_Inner*)*(char**)((char*)this + 0x14))[a].v;
}

struct ThisStruct
{
    NiInterpolator* GetInterpolatorByIndex(unsigned short usIndex);
};
// Returns the NiInterpolator pointer stored at offset 0x34 for index 0, at 0x40 for index 1, otherwise null.
// @fnv 0x00c1bc90
NiInterpolator* ThisStruct::GetInterpolatorByIndex(unsigned short usIndex)
{
    if (usIndex == 0)
        return *(NiInterpolator**)((char*)this + 0x34);
    if (usIndex == 1)
        return *(NiInterpolator**)((char*)this + 0x40);
    return 0;
}

bool __stdcall FUN_00a57780(NiStream& kStream);
struct FakeInterp00c1be10
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
    virtual void RegisterStreamables(NiStream& kStream);
};
struct FUN_00c1be10_shell : NiPSysEmitterCtlr
{
    bool RegisterEmitterInterpolatorStreamables(NiStream& kStream);
};
// Calls FUN_00a57780, then if the interpolator at offset 0x40 is non-null, registers its streamables with kStream; returns true.
// @fnv 0x00c1be10
bool FUN_00c1be10_shell::RegisterEmitterInterpolatorStreamables(NiStream& kStream)
{
    if (!FUN_00a57780(kStream))
        return false;
    NiInterpolator* pkEmitter = *(NiInterpolator**)((char*)this + 0x40);
    if (pkEmitter)
        ((FakeInterp00c1be10*)pkEmitter)->RegisterStreamables(kStream);
    return true;
}

struct BaseHack
{
    void FUN_00a57130(NiStream&);
};
struct FakeStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(void*);
};
struct S_00c1be40
{
    void FUN_00c1be40(NiStream&);
};
// @fnv 0x00c1be40
void S_00c1be40::FUN_00c1be40(NiStream& kStream)
{
    ((BaseHack*)this)->FUN_00a57130(kStream);
    ((FakeStream&)kStream).f12(*(void**)((char*)this + 0x40));
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
struct S_00c1beb0
{
    float* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    void SetEmitterArrayCapacity(unsigned int);
};
// Reallocates m_pBase to hold uiNewMax floats, copies the existing m_uiSize elements, frees the old buffer and updates m_uiMaxSize.
// @fnv 0x00c1beb0
void S_00c1beb0::SetEmitterArrayCapacity(unsigned int uiNewCapacity)
{
    if (uiNewCapacity == m_uiMaxSize)
        return;
    float* pfNewData;
    if (uiNewCapacity > 0)
    {
        pfNewData = (float*)_NiMalloc(uiNewCapacity * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pfNewData[i] = m_pBase[i];
    }
    else
    {
        pfNewData = 0;
    }
    _NiFreeAlias(m_pBase);
    m_pBase = pfNewData;
    m_uiMaxSize = uiNewCapacity;
}

struct A00c1bff0
{
    bool FUN_00a38df0();
};
struct B00c1bff0
{
    void* FUN_00c1b0f0(void*);
};
struct M00c1bff0
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};
extern int g_01202500_arg1;
struct H00c1bff0
{
    char _a[0x2c];
    B00c1bff0* _b;
    char _c[8];
    int _d;
    bool FUN_00c1bff0();
};
// Checks FUN_00a38df0, resolves a modifier via _b->FUN_00c1b0f0(&_d), then scans its RTTI chain for g_01202500_arg1 and returns whether it is found.
// @fnv 0x00c1bff0
bool H00c1bff0::FUN_00c1bff0()
{
    if (!((A00c1bff0*)this)->FUN_00a38df0())
        return false;
    M00c1bff0* pkModifier = (M00c1bff0*)_b->FUN_00c1b0f0(&_d);
    if (!pkModifier)
        return false;
    void* pRttiEntry = pkModifier->v2();
    for (; pRttiEntry; pRttiEntry = *(void**)((char*)pRttiEntry + 4))
    {
        if (pRttiEntry == (void*)&g_01202500_arg1)
            return true;
    }
    return false;
}

struct S240
{
    float* m0;
    unsigned int m4;
    unsigned int m8;
    void SetEmitterArrayCapacity(unsigned int);
    void PushBack(float const&);
};
// Grows the buffer via SetEmitterArrayCapacity when full, then stores x at m0[m8] and increments m8.
// @fnv 0x00c1c240
void S240::PushBack(float const& afValue)
{
    if (m8 == m4)
    {
        unsigned int n = m4 > 0 ? m4 + m4 : 1;
        SetEmitterArrayCapacity(n);
    }
    m0[m8++] = afValue;
}

void __cdecl _NiFreeAlias(void*);
struct S_00c1c300
{
    void FUN_00c1c300();
    void FUN_00c312a0();
};
// Frees the pointer at offset 0x50, decrements the ref count of the interpolator at offset 0x40, then calls FUN_00c312a0.
// @fnv 0x00c1c300
void S_00c1c300::FUN_00c1c300()
{
    _NiFreeAlias(*(void**)((char*)this + 0x50));
    NiInterpolator* p = *(NiInterpolator**)((char*)this + 0x40);
    if (p)
        p->DecRefCount();
    FUN_00c312a0();
}

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
struct Host
{
    void FUN_00c312a0();
    void* ReleaseAndMaybeDelete(unsigned int);
};
// Frees the pointer at offset 0x50, decrements the ref count of the object at 0x40, calls FUN_00c312a0, and deletes this if flag bit 0 is set.
// @fnv 0x00c1c340
void* Host::ReleaseAndMaybeDelete(unsigned int flag)
{
    _NiFreeAlias(*(void**)((char*)this + 0x50));
    NiObject* pk = *(NiObject**)((char*)this + 0x40);
    if (pk)
        pk->DecRefCount();
    this->FUN_00c312a0();
    if (flag & 1)
        _delete(this, 0x5c);
    return this;
}

namespace fnv_00c2b7d0 {
struct RTTI_00c2b7d0
{
    int _0;
    RTTI_00c2b7d0* m_pkBase;
};
extern RTTI_00c2b7d0 g_01202500_arg1;
struct S_00c31530
{
    bool IsTargetParticleSystem(void* pkTarget);
};
struct S_00c1b0f0
{
    void* FUN_00c1b0f0(void* p);
};
struct Mod_00c2b7d0
{
    virtual void _v0();
    virtual void _v1();
    virtual RTTI_00c2b7d0* _v2();
};
struct Holder00c2b7d0
{
    bool FUN_00c2b7d0(void* pkTarget);
};
// Checks the target via IsTargetParticleSystem, resolves a modifier from this+0x38, then walks its RTTI base chain looking for g_01202500_arg1.
// @fnv 0x00c2b7d0
bool Holder00c2b7d0::FUN_00c2b7d0(void* pkTarget)
{
    void* pkModifier;
    if (!((S_00c31530*)this)->IsTargetParticleSystem(pkTarget))
        return false;
    pkModifier = ((S_00c1b0f0*)pkTarget)->FUN_00c1b0f0((void*)((char*)this + 0x38));
    if (!pkModifier)
        return false;
    RTTI_00c2b7d0* pkRTTI = ((Mod_00c2b7d0*)pkModifier)->_v2();
    if (!pkRTTI)
        return false;
    for (; pkRTTI; pkRTTI = pkRTTI->m_pkBase)
    {
        if (pkRTTI == &g_01202500_arg1)
            return true;
    }
    return false;
}
}  // namespace fnv_00c2b7d0

struct CallBase
{
    void FUN_00a38e90(float m_fStartTime, float m_fMaximumDistance);
};
struct InterpDummy
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
    virtual void v49(float m_fStartTime, float m_fMaximumDistance);
};
struct MyCtlr
{
    void FUN_00c1bbc0(float m_fStartTime, float m_fMaximumDistance);
};
// @fnv 0x00c1bbc0
void MyCtlr::FUN_00c1bbc0(float afValue1, float afValue2)
{
    ((CallBase*)this)->FUN_00a38e90(afValue1, afValue2);
    InterpDummy* pk = *(InterpDummy**)((char*)this + 0x40);
    if (pk)
        pk->v49(afValue1, afValue2);
}

struct NiBlendInterpolator;
struct FUN_00a40520
{
    FUN_00a40520(bool, float, unsigned char);
};
struct FUN_00a40520_shell
{
    NiBlendInterpolator* FUN_00a40520(bool, float, unsigned char);
};
struct FUN_00a56560_shell
{
    NiBlendInterpolator* ConstructBlendInterpolator(bool, float, unsigned char);
};
// Allocates a 0x34-byte NiBlendInterpolator and constructs variant 0 or 1 based on usIndex, returning null otherwise.
// @fnv 0x00c1bb20
NiBlendInterpolator* __stdcall FUN_00c1bb20(unsigned short usVariant, bool bAccumulateAnimations,
                                            bool bManagerControlled, float fWeightThreshold, unsigned char ucArraySize)
{
    if (usVariant == 0)
    {
        void* p = BSFadeNode::operator new(0x34);
        if (p)
            return reinterpret_cast<FUN_00a40520_shell*>(p)->FUN_00a40520(bAccumulateAnimations, fWeightThreshold,
                                                                          ucArraySize);
    }
    else if (usVariant == 1)
    {
        void* p = BSFadeNode::operator new(0x34);
        if (p)
            return reinterpret_cast<FUN_00a56560_shell*>(p)->ConstructBlendInterpolator(bAccumulateAnimations,
                                                                                        fWeightThreshold, ucArraySize);
    }
    return 0;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

char* __cdecl _FUN_00a7d330(char*);
void __stdcall AppendModifierInfo(StrArr*);

struct FUN_00c1ce70_shell : NiPSysEmitterCtlr
{
    void FUN_00c1ce70(StrArr* pkStrings);
};

// @fnv 0x00c1ce70
void FUN_00c1ce70_shell::FUN_00c1ce70(StrArr* pkStrings)
{
    AppendModifierInfo(pkStrings);
    char* pcString = _FUN_00a7d330((char*)g_01203340_arg1);
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 8);
    if (uiIndex >= uiSize)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiGrow + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcString);
    NiInterpolator* pkInterp = *(NiInterpolator**)((char*)this + 0x40);
    if (pkInterp)
    {
        void** vtbl = *(void***)pkInterp;
        void(__thiscall * fn)(NiInterpolator*, StrArr*) = (void(__thiscall*)(NiInterpolator*, StrArr*))vtbl[0x60 / 4];
        fn(pkInterp, pkStrings);
    }
}

extern int DAT_0109a864;

struct S_00a56be0
{
    void* unk00;
    int unk04;
    volatile int unk08;
    volatile int unk0c;
    volatile int unk10;

    void FUN_00a5d3a0();
    S_00a56be0* Initialize();
};

// @fnv 0x00a56be0
S_00a56be0* S_00a56be0::Initialize()
{
    this->FUN_00a5d3a0();

    unk08 = 0;
    unk00 = &DAT_0109a864;
    unk0c = 0;
    unk10 = 0;

    return this;
}

struct CBaseA
{
    virtual void v0();
    int m4;
    CBaseA() throw();
};

struct CChildA;

struct CPtrA
{
    CChildA* m_p;
    void operator=(CChildA* p);
};

struct CChildA : CBaseA
{
    int m8;
    int mc;
    int m10;
    unsigned char m14;
    CChildA()
    {
        m8 = 0;
        mc = 0;
        m10 = 0;
        m14 = 0;
    }
    static void* operator new(unsigned int size);
    void M(unsigned int a, unsigned int b, unsigned int c);
};

struct CClsA
{
    char pad[0x10];
    CPtrA m_ptr;
    int m14;
    void FUN_00c1bf10(unsigned int a, unsigned int b, unsigned int c);
};

// Ensures m_ptr holds a CChildA, calls M(a, c, b) and clears m14 when c > 0, otherwise calls M(0, 0, 0) if m_ptr is set.
// @fnv 0x00c1bf10
void CClsA::FUN_00c1bf10(unsigned int auiFirst, unsigned int auiThird, unsigned int auiSecond)
{
    if (auiSecond > 0)
    {
        if (!m_ptr.m_p)
            m_ptr = new CChildA;
        m_ptr.m_p->M(auiFirst, auiSecond, auiThird);
        m14 = 0;
    }
    else
    {
        if (m_ptr.m_p)
            m_ptr.m_p->M(0, 0, 0);
    }
}

struct C1BF90Entry
{
    int unk00;
    int unk04;
};

struct C1BF90Result
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
    int unk10;
    C1BF90Entry* unk14;
    int unk18;
    unsigned char FindHighestWeightIndex();
};

struct C1BF90Target
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual int vf54();
    C1BF90Result* FUN_00653290(const void* objectType);
};

struct C1BF90Base
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
};

struct C1BF90Owner : C1BF90Base
{
    C1BF90Target* unk40;
    int GetObjectValueByKey();
};

extern unsigned char DAT_01096968;
extern GlobalObjectO2_00a7b610 DAT_011f407c;

// Returns vf54() if nonzero; otherwise looks up an object by DAT_011f407c and returns a value indexed by its key, or 0.
// @fnv 0x00c1bf90
int __thiscall C1BF90Owner::GetObjectValueByKey()
{
    int iVf54Result = this->unk40->vf54();
    if (iVf54Result == 0)
    {
        if (this->unk40 != 0)
        {
            C1BF90Result* pResult = this->unk40->FUN_00653290(&DAT_011f407c);
            if (pResult != 0)
            {
                unsigned char key = pResult->FindHighestWeightIndex();
                if (key != DAT_01096968)
                {
                    if (pResult->unk0E == 1 && key == pResult->unk0F)
                        return pResult->unk18;

                    return pResult->unk14[key * 3].unk00;
                }
            }
        }
        return 0;
    }

    return iVf54Result;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern char* g_pcC1C280NullString;

char* __cdecl FUN_00a5b690(const char* pcString);

static const float NI_INFINITY = 3.402823466e+38f;
static const float INVALID_FLOAT = -NI_INFINITY;

class BC1C280FixedString
{
  public:
    BC1C280FixedString(const char* pcString) throw()
    {
        if (pcString == 0)
            m_kHandle = g_pcC1C280NullString;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }
    ~BC1C280FixedString() throw()
    {
        if (m_kHandle != g_pcC1C280NullString)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }

    char* m_kHandle;
};

class BC1C280Base
{
  public:
    BC1C280Base(const BC1C280FixedString& kName) throw();
    virtual ~BC1C280Base();

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
};

struct BC1C280Tracker
{
    BC1C280Tracker() : m_pkTarget(0), m_uiCount(0), m_fLastValue(INVALID_FLOAT), m_bModifierActive(false)
    {}

    void* m_pkTarget;
    unsigned int m_uiCount;
    float m_fLastValue;
    bool m_bModifierActive;
};

struct BC1C280Links
{
    BC1C280Links() : m_pkFirst(0), m_pkSecond(0), m_pkThird(0)
    {}

    void* m_pkFirst;
    void* m_pkSecond;
    void* m_pkThird;
};

class FUN_00c1c280_cls : public BC1C280Base
{
  public:
    FUN_00c1c280_cls(const char* pcName) throw();
    virtual ~FUN_00c1c280_cls();

    BC1C280Tracker m_kTracker;
    BC1C280Links m_kLinks;
};

// Constructs the object by forwarding pcName to the BC1C280Base base-class constructor.
// @fnv 0x00c1c280
FUN_00c1c280_cls::FUN_00c1c280_cls(const char* pcName) throw() : BC1C280Base(pcName)
{}

class NiInterpolatorC1B
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void GetInterpolatorTimeRange(float* pfBegin, float* pfEnd);
};

template <class T> class NiPointerC1B
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class NiTimeControllerC1B
{
  public:
    enum
    {
        MANAGERCONTROLLED_MASK = 0x0020,
        MANAGERCONTROLLED_POS = 5
    };

    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return (bool)(GetField(MANAGERCONTROLLED_MASK, MANAGERCONTROLLED_POS) & 1);
    }
    void UpdateKeyTimeRange();

    void* m_ppVirtualMethodTable;
    int unk04;
    unsigned short m_uiObjectFlags;
    short unk0A;
    int unk0C;
    int unk10;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    NiPointerC1B<NiInterpolatorC1B> m_spFirst;
    int unk38;
    int unk3C;
    NiPointerC1B<NiInterpolatorC1B> m_spSecond;
};

// @fnv 0x00c1bc10
void NiTimeControllerC1B::UpdateKeyTimeRange()
{
    if (GetManagerControlled())
        return;
    m_spFirst->GetInterpolatorTimeRange(&m_fLoKeyTime, &m_fHiKeyTime);
    float fBegin;
    float fSecondEnd;
    m_spSecond->GetInterpolatorTimeRange(&fBegin, &fSecondEnd);
    if (fBegin < m_fLoKeyTime)
        m_fLoKeyTime = fBegin;
    if (fSecondEnd > m_fHiKeyTime)
        m_fHiKeyTime = fSecondEnd;
}

namespace fnv_00c1be60 {
class NiObjectC1B
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual bool IsEqual(NiObjectC1B* pkObject);
};

template <class T> class NiPointerC1B
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!=(T* pObject) const
    {
        return m_pObject != pObject;
    }

    T* m_pObject;
};

class NiBaseC1B : public NiObjectC1B
{
  public:
    bool BaseIsEqual(NiObjectC1B* pkObject);

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
    NiPointerC1B<NiObjectC1B> m_spTransformData;

    bool FUN_00c1be60(NiObjectC1B* pkObject);
};

// @fnv 0x00c1be60
bool NiBaseC1B::FUN_00c1be60(NiObjectC1B* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    NiBaseC1B* pkOther = (NiBaseC1B*)pkObject;
    if ((!pkOther->m_spTransformData && m_spTransformData) || (pkOther->m_spTransformData && !m_spTransformData))
        return false;
    if (pkOther->m_spTransformData && !pkOther->m_spTransformData->IsEqual(m_spTransformData))
        return false;
    return true;
}
}  // namespace fnv_00c1be60

struct EmitterStandIn
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
    virtual void UpdateEmitter(float fTime, unsigned short uiNumParticles, const float* afAges);
};
extern unsigned short DAT_011ae75c;
struct AgeSet : NiTPrimitiveSet_float_
{
    void Add(const float& fValue)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            ((S_00c1beb0*)this)->SetEmitterArrayCapacity(m_uiElementCount > 0 ? 2 * m_uiElementCount : 1);
        m_pBase[m_uiAllocatedCapacity++] = fValue;
    }
};
struct EmitCtlr : NiPSysEmitterCtlr
{
    void EmitParticlesInInterval(float fTime, float fCurTime, float fLastTime, float fEmitStart, float fEmitStop,
                                 float fEmissionRate);
};
// @fnv 0x00c1c3c0
void EmitCtlr::EmitParticlesInInterval(float fTime, float fCurTime, float fLastTime, float fEmitStart, float fEmitStop,
                                       float fEmissionRate)
{
    if (fEmissionRate > 0.0f && fEmitStart < fEmitStop && fEmitStart < fCurTime && fLastTime < fEmitStop)
    {
        float fDuration = ((fCurTime <= fEmitStop) ? fCurTime - fEmitStart : fEmitStop - fEmitStart);
        float fStart = 0.0f;
        if (fEmitStart <= fLastTime)
            fStart = fLastTime - fEmitStart;
        unsigned short usFirst = (unsigned short)(fStart * fEmissionRate);
        unsigned int uiElementCount = (unsigned short)((unsigned short)(fDuration * fEmissionRate) - usFirst);
        if ((unsigned short)uiElementCount > (unsigned short)DAT_011ae75c)
            uiElementCount = DAT_011ae75c;
        float fInvBirthRate = 1.0f / fEmissionRate;
        m_kBirthRateKeys.m_uiAllocatedCapacity = 0;
        for (unsigned short us = 0; us < (unsigned short)uiElementCount; us++)
        {
            float m_fFirstFloatValue = fDuration - (++usFirst) * fInvBirthRate;
            ((AgeSet&)m_kBirthRateKeys).Add(m_fFirstFloatValue);
        }
        ((EmitterStandIn*)m_pkTargetModifier)->UpdateEmitter(fTime, uiElementCount, m_kBirthRateKeys.m_pBase);
    }
}

struct Entry_a36
{
    int unk;
    int unkCur;
    float weight;
    int unk0C;
    int uNewnk;
    int uTmpnk;
};

namespace nsa {
struct FUN_00a368f0_cls
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned char unk0C;
    unsigned char count;
    unsigned char fixed;
    unsigned char fixedIndex;
    int uNewnk;
    Entry_a36* entries;
    unsigned char FindHighestWeightIndex();
};
}

// Returns fixedIndex if fixed is 1, otherwise scans entries for the highest weight and returns its index, or 0xff if none exceed zero.
// @fnv 0x00a368f0
unsigned char nsa::FUN_00a368f0_cls::FindHighestWeightIndex()
{
    if (fixed == 1)
        return fixedIndex;
    float fBestWeight = 0.0f;
    unsigned char bestIndex = 0xff;
    for (unsigned char i = 0; i < count; i++)
    {
        if (entries[i].weight > fBestWeight)
        {
            fBestWeight = entries[i].weight;
            bestIndex = i;
        }
    }
    if (bestIndex == 0xff)
        return 0xff;
    return bestIndex;
}

extern char DAT_011f3738;
extern char DAT_011f3e58;
extern char DAT_011f404c;

struct C040Node
{
    void* m_pData;
    C040Node* m_pNext;
};

struct C040Owner
{
    virtual void v0();
    virtual void v1();
    virtual C040Node* v2();
};

unsigned char __cdecl FUN_0043b300(void* a, void* b);

__forceinline bool C040Has(C040Owner* o, void* p)
{
    for (C040Node* n = o->v2(); n; n = n->m_pNext)
        if (n == p)
            return true;
    return false;
}

// Checks whether obj contains one of the global nodes for the given type (0 or 1), or for type 1 whether FUN_0043b300 matches DAT_011f407c.
// @fnv 0x00c1c040
bool __stdcall FUN_00c1c040(C040Owner* pOwner, unsigned short type)
{
    if (type == 0)
    {
        if (pOwner && (C040Has(pOwner, &DAT_011f3738) || C040Has(pOwner, &DAT_011f3e58)))
            return true;
    }
    else if (type == 1)
    {
        if (pOwner && C040Has(pOwner, &DAT_011f404c))
            return true;
        if (FUN_0043b300(&DAT_011f407c, pOwner))
            return true;
    }
    return false;
}

static const float kNegInfinity = -3.402823466e+38f;
struct EmitCtlrBase
{
    EmitCtlrBase() throw();
    virtual void v00();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct ParticleAgeSet
{
    float* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    ParticleAgeSet() : m_pBase(0), m_uiElementCount(0), m_uiAllocatedCapacity(0)
    {}
};

struct FUN_00c1c390 : EmitCtlrBase
{
    NiPointer<NiInterpolator> m_spVisibilityInterpolator;
    NiInterpolator* m_pEmitterActiveInterpolator;
    float m_fScaledLastTime;
    bool m_bIsInitialized;
    ParticleAgeSet m_kBirthRateKeys;
    FUN_00c1c390();
};

// @fnv 0x00c1c390
FUN_00c1c390::FUN_00c1c390() : m_fScaledLastTime(kNegInfinity), m_bIsInitialized(false)
{}

class CloningProcessC1C5;

class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int n);
};

class FUN_00c31260
{
  public:
    FUN_00c31260() throw();
    virtual ~FUN_00c31260() throw();
    int unk04[15];
};

namespace c1c5 {
const float DAT_01015f5c = -3.402823466e+38f;
}

template <class T> class NiPointerC1C5
{
  public:
    NiPointerC1C5() : m_pObject(0)
    {}
    T* m_pObject;
};

class NiPSysEmitterCtlrC1C5 : public FUN_00c31260
{
  public:
    NiPSysEmitterCtlrC1C5() throw() : m_fLastTime(c1c5::DAT_01015f5c), m_bIsInitialized(false)
    {}
    virtual ~NiPSysEmitterCtlrC1C5() throw();

    static void* operator new(unsigned int n)
    {
        return TESObjectDoorController::operator new(n);
    }

    NiPointerC1C5<void> m_spVisibilityInterpolator;
    float m_fParticlesToEmit;
    float m_fLastTime;
    bool m_bIsInitialized;
    struct RequestArray
    {
        RequestArray() : m_pBase(0), m_uiSize(0), m_uiMaxSize(0)
        {}
        void* m_pBase;
        unsigned int m_uiSize;
        unsigned int m_uiMaxSize;
    } m_kRequests;

    void FUN_00c1bd30(NiPSysEmitterCtlrC1C5* pkDest, CloningProcessC1C5& kCloning);
    NiPSysEmitterCtlrC1C5* FUN_00c1c570(CloningProcessC1C5& kCloning);
};

// Allocates a new NiPSysEmitterCtlrC1C5, calls FUN_00c1bd30 with it and kCloning, then returns it.
// @fnv 0x00c1c570
NiPSysEmitterCtlrC1C5* NiPSysEmitterCtlrC1C5::FUN_00c1c570(CloningProcessC1C5& kCloning)
{
    NiPSysEmitterCtlrC1C5* pkClone = new NiPSysEmitterCtlrC1C5;
    FUN_00c1bd30(pkClone, kCloning);
    return pkClone;
}

// Allocates and returns a new NiPSysEmitterCtlrC1C5 object on the heap.
// @fnv 0x00c1c5e0
NiPSysEmitterCtlrC1C5* __cdecl CreateNiPSysEmitterCtlrC1C5()
{
    return new NiPSysEmitterCtlrC1C5;
}

struct ActiveKey
{
    float time;
    bool value;
    ActiveKey* At(unsigned int i, unsigned char stride)
    {
        return (ActiveKey*)((char*)this + i * stride);
    }
};
struct C630Interp
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual bool Value(float time, NiObjectNET* target, float& out);
    virtual bool Active(float time, NiObjectNET* target, bool& out);
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual bool Posed(unsigned short channel);
    __declspec(noalias) ActiveKey* FUN_00a52d20(unsigned int&, unsigned int&, unsigned char&);
    __declspec(noalias) ActiveKey* FUN_00533000(unsigned int&, unsigned int&, unsigned char&);
};
struct C630Blend
{
    void UpdateNormalizedWeights();
    unsigned char FindHighestWeightIndex();
    float GetValueForIndex(unsigned char);
};
struct C630Modifier
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    float span;
};
struct C630Target
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0;
    float offset;
};
extern float DAT_01015f5c;
extern const float DAT_01096324;
extern double DAT_010241b0;
extern double DAT_01011588;
extern GlobalObjectO2_00a7b610 DAT_011f407c;
extern char DAT_011f3e58;
extern "C" bool __cdecl InterpolateBooleanKey(float, ActiveKey*, unsigned int, unsigned int, unsigned int&,
                                              unsigned char);
struct C630Ctlr
{
    int unk00, unk04;
    unsigned short m_uiObjectFlags, unk0a;
    int unk0c, unk10;
    float m_fLoKeyTime, m_fHiKeyTime;
    int unk1c;
    float m_fLastTime;
    int unk24;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    int unk30;
    NiPointer<NiInterpolator> m_spControllerInterpolator;
    int unk38;
    NiPSysModifier* m_pkTargetModifier;
    NiPointer<NiInterpolator> m_spVisibilityInterpolator;
    NiInterpolator* m_pEmitterActiveInterpolator;
    float m_fScaledLastTime;
    bool m_bIsInitialized;
    void EmitParticlesInInterval(float a, float b, float c, float d, float e, float f);

    bool FUN_00a36250(float);
    C630Interp* GetObjectValueByKey();
    C630Interp* FUN_00639b60();
    bool Manager() const
    {
        return (bool)(((m_uiObjectFlags & 0x20) >> 5) & 1);
    }
    void FUN_00c1c630(float* time);
};
// Updates the particle controller time and emits particles over the active intervals between the old and new times using the rate interpolator.
// @fnv 0x00c1c630
void C630Ctlr::FUN_00c1c630(float* time)
{
    if (m_fLastTime > *time)
        m_fScaledLastTime = DAT_01015f5c;
    if (!m_pkTarget || !m_pkTargetModifier)
        return;
    if (Manager())
        m_fControllerTime = DAT_01096324;
    if (m_fLastTime != DAT_010241b0 && !(m_uiObjectFlags & 6) &&
        *time - m_fLastTime > ((C630Modifier*)m_pkTargetModifier)->span)
        m_fLastTime = *time;
    if (FUN_00a36250(*time))
        return;
    if (!m_spVisibilityInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject)
        return;
    float activeBlendTime = DAT_01015f5c;
    if (FUN_0043b300(&DAT_011f407c, m_spVisibilityInterpolator))
    {
        C630Blend* blend = (C630Blend*)m_spVisibilityInterpolator.m_pObject;
        blend->UpdateNormalizedWeights();
        unsigned char index = blend->FindHighestWeightIndex();
        if (index != DAT_01096968)
            activeBlendTime = blend->GetValueForIndex(index);
    }
    C630Interp* emitterActive = GetObjectValueByKey();
    bool activeTimeSet = activeBlendTime != DAT_010241b0;
    float birthRateTime = DAT_01015f5c;
    if (FUN_0043b300(&DAT_011f3e58, m_spControllerInterpolator))
    {
        C630Blend* blend = (C630Blend*)m_spControllerInterpolator.m_pObject;
        blend->UpdateNormalizedWeights();
        unsigned char index = blend->FindHighestWeightIndex();
        if (index != DAT_01096968)
            birthRateTime = blend->GetValueForIndex(index);
    }
    C630Interp* rateInterp = FUN_00639b60();
    bool rateTimeSet = birthRateTime != DAT_010241b0;
    if (!emitterActive || !rateInterp)
        return;
    float newTime = m_fControllerTime;
    if (activeTimeSet || rateTimeSet)
        newTime = birthRateTime;
    if (Manager() && m_pEmitterActiveInterpolator != (NiInterpolator*)rateInterp)
    {
        m_fScaledLastTime = newTime;
        emitterActive->Active(newTime, m_pkTarget, m_bIsInitialized);
        m_pEmitterActiveInterpolator = (NiInterpolator*)rateInterp;
        return;
    }
    m_pEmitterActiveInterpolator = (NiInterpolator*)rateInterp;
    unsigned int activeCount, activeType;
    unsigned char boolKeySize;
    ActiveKey* emitterKeys = emitterActive->FUN_00a52d20(activeCount, activeType, boolKeySize);
    if (!activeCount && !emitterActive->Posed(0))
        return;
    if (emitterActive->Posed(0))
    {
        bool activeInterp;
        emitterActive->Active(0.0f, m_pkTarget, activeInterp);
        if (activeInterp == 0)
            return;
        float oldTime = m_fScaledLastTime;
        float offset = ((C630Target*)m_pkTarget)->offset;
        m_fScaledLastTime = newTime;
        float rateValue;
        if (rateInterp->Posed(0))
        {
            float deltaTime;
            deltaTime = newTime - oldTime;
            if (newTime < oldTime)
            {
                oldTime = 0.0f;
                deltaTime = newTime;
            }
            if (!rateInterp->Value(0.0f, m_pkTarget, rateValue))
                return;
            EmitParticlesInInterval(deltaTime + offset, newTime, oldTime, 0.0f, newTime, rateValue);
            return;
        }
        unsigned int rateCount, rateType;
        unsigned char ucRateSize;
        ActiveKey* birthKeys = rateInterp->FUN_00533000(rateCount, rateType, ucRateSize);
        float rateBegin = birthKeys->time;
        float rateEnd = birthKeys->At(rateCount - 1, ucRateSize)->time;
        float deltaTime = 0.0f;
        if (oldTime > newTime)
        {
            double dDelta = rateEnd - oldTime;
            rateInterp->Value((float)(dDelta * DAT_01011588 + oldTime), m_pkTarget, rateValue);
            deltaTime = (float)dDelta;
            EmitParticlesInInterval(offset + deltaTime, rateEnd, oldTime, rateBegin, rateEnd, rateValue);
            oldTime = birthKeys->time;
        }
        double dDelta = newTime - oldTime;
        rateInterp->Value((float)(dDelta * DAT_01011588 + oldTime), m_pkTarget, rateValue);
        EmitParticlesInInterval((float)(offset + dDelta + deltaTime), newTime, oldTime, rateBegin, newTime, rateValue);
        return;
    }
    unsigned int uiLastIndex = 0;
    bool bActive;
    bActive = InterpolateBooleanKey(newTime, emitterKeys, activeType, activeCount, uiLastIndex, boolKeySize);
    if (m_fScaledLastTime == DAT_010241b0)
    {
        m_bIsInitialized = bActive;
        m_fScaledLastTime = newTime;
        return;
    }
    float oldTime = m_fScaledLastTime;
    bool bLastActive = m_bIsInitialized;
    m_bIsInitialized = bActive;
    m_fScaledLastTime = newTime;
    bool stopLoop = false;
    long iLoop = 0;
    while (!stopLoop && iLoop < 20)
    {
        bool isWrapped = false;
        if (oldTime > newTime)
            isWrapped = true;
        unsigned long beginIndex;
        if (bLastActive)
        {
            for (beginIndex = activeCount; beginIndex > 0; --beginIndex)
            {
                ActiveKey* pkActiveKey = emitterKeys->At(beginIndex - 1, boolKeySize);
                if (pkActiveKey->time <= oldTime && !pkActiveKey->value)
                    break;
            }
        }
        else
        {
            for (beginIndex = 0; beginIndex < activeCount; ++beginIndex)
            {
                ActiveKey* pkActiveKey;
                pkActiveKey = emitterKeys->At(beginIndex, boolKeySize);
                if (pkActiveKey->time > oldTime && (isWrapped || pkActiveKey->time <= newTime) && pkActiveKey->value)
                    break;
            }
            if (beginIndex == activeCount)
            {
                if (!isWrapped)
                    break;
                for (beginIndex = 0; beginIndex < activeCount; ++beginIndex)
                {
                    ActiveKey* pkActiveKey = emitterKeys->At(beginIndex, boolKeySize);
                    if (newTime > pkActiveKey->time && pkActiveKey->value)
                        break;
                }
                if (beginIndex == activeCount)
                    break;
            }
        }
        unsigned long uiEnd;
        for (uiEnd = beginIndex; uiEnd < activeCount; ++uiEnd)
        {
            if (!emitterKeys->At(uiEnd, boolKeySize)->value)
                break;
        }
        if (uiEnd == activeCount)
            --uiEnd;
        ActiveKey* pkBegin = emitterKeys->At(beginIndex, boolKeySize);
        ActiveKey* pkEnd = emitterKeys->At(uiEnd, boolKeySize);
        float fCurrentEnd, intervalStart, birthBegin, birthEnd;
        float rateValue;
        if (isWrapped)
        {
            if (oldTime < pkEnd->time)
            {
                fCurrentEnd = emitterKeys->At(activeCount - 1, boolKeySize)->time;
                intervalStart = oldTime;
                birthBegin = pkBegin->time;
                birthEnd = pkEnd->time;
                float fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
                rateInterp->Value(fSampleTime, m_pkTarget, rateValue);
            }
            else
            {
                fCurrentEnd = newTime;
                intervalStart = emitterKeys->time;
                birthBegin = pkBegin->time;
                if (pkEnd->time < newTime)
                    birthEnd = pkEnd->time;
                else
                    birthEnd = newTime;
                float fSampleTime;
                fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
                rateInterp->Value(fSampleTime, m_pkTarget, rateValue);
            }
        }
        else if (pkEnd->time < newTime)
        {
            fCurrentEnd = pkEnd->time;
            intervalStart = oldTime;
            birthBegin = pkBegin->time;
            birthEnd = pkEnd->time;
            float fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
            rateInterp->Value(fSampleTime, m_pkTarget, rateValue);
        }
        else
        {
            fCurrentEnd = newTime;
            intervalStart = oldTime;
            birthBegin = pkBegin->time;
            birthEnd = pkEnd->time;
            rateInterp->Value(newTime, m_pkTarget, rateValue);
        }
        float offset = ((C630Target*)m_pkTarget)->offset;
        if (isWrapped)
            offset = (m_fHiKeyTime - m_fLoKeyTime) + offset;
        EmitParticlesInInterval(offset + newTime - oldTime, fCurrentEnd, intervalStart, birthBegin, birthEnd,
                                rateValue);
        if (pkEnd->time < newTime)
        {
            oldTime = fCurrentEnd;
            bLastActive =
                InterpolateBooleanKey(oldTime, emitterKeys, activeType, activeCount, uiLastIndex, boolKeySize);
        }
        else
        {
            stopLoop = true;
        }
        ++iLoop;
    }
}

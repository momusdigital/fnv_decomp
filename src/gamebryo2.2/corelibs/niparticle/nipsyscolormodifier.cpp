// gamebryo2.2/corelibs/niparticle/nipsyscolormodifier.cpp: NiPSysColorModifier, Host, NiPSysColorModifierLocal (9 functions)

#include "NiPSysColorModifier.h"

// @fnv 0x00C2CF90
void NiPSysColorModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    kStream.ResetStreamState();
}

extern "C" void* g_01202778;

// @fnv 0x00c2d170
void* __cdecl FUN_00c2d170()
{
    return &g_01202778;
}

struct Fake00c2d0d0
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual unsigned char Foo(void*) = 0;
};
struct FUN_00c2d0d0_Class : NiPSysColorModifier
{
    bool FUN_00c2d0d0(NiObject* pkObject);
};
// @fnv 0x00c2d0d0
bool FUN_00c2d0d0_Class::FUN_00c2d0d0(NiObject* pkObject)
{
    NiPSysColorModifier* pkDest;
    Fake00c2d0d0* pSrc;
    void* pDst;
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;
    pkDest = (NiPSysColorModifier*)pkObject;
    pSrc = *(Fake00c2d0d0**)((char*)this + 0x18);
    pDst = *(void**)((char*)pkDest + 0x18);
    return pSrc->Foo(pDst);
}

struct Holder31750
{
    void __thiscall FUN_00c31750();
};
void __cdecl _delete(void*, unsigned int);
struct Host
{
    char _pad[0x18];
    NiObject* m_at18;
    void* __thiscall Destroy(unsigned int);
};
// Releases m_at18, calls FUN_00c31750, and deletes this with size 0x24 when f has bit 0 set; returns this.
// @fnv 0x00c2d1f0
void* __thiscall Host::Destroy(unsigned int auiFlags)
{
    if (m_at18)
        m_at18->DecRefCount();
    ((Holder31750*)this)->FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x24);
    return this;
}

struct C8C330Source : public NiObject
{
};

struct C8C330Node
{
    C8C330Source* __thiscall FUN_00a63430();
};

struct FUN_00c2d1c0_Class : NiPSysColorModifier
{
    void SetColorData(NiObject* pkObject);
    void FUN_00c2d1c0(NiStream& kStream);
};

// @fnv 0x00c2d1c0
void FUN_00c2d1c0_Class::FUN_00c2d1c0(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    SetColorData(reinterpret_cast<C8C330Node*>(&kStream)->FUN_00a63430());
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

char* _FUN_00a7d330(void*);

struct Base00c319e0
{
    void FUN_00c319e0(StrArr*);
};

extern void* _g_01202778;

struct FUN_00c2d2a0_Class : NiPSysColorModifier
{
    void GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00c2d2a0
void FUN_00c2d2a0_Class::GetViewerStrings(StrArr* pkStrings)
{
    ((Base00c319e0*)this)->FUN_00c319e0(pkStrings);
    char* str = _FUN_00a7d330(_g_01202778);
    unsigned int idx = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int size = *(unsigned short*)((char*)pkStrings + 8);
    if (idx >= size)
    {
        unsigned int grow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(grow + idx);
    }
    pkStrings->SetAt(idx, str);
    NiObject* obj = *(NiObject**)((char*)this + 0x18);
    void** vt = *(void***)obj;
    void(__thiscall * fn)(NiObject*, StrArr*) = (void(__thiscall*)(NiObject*, StrArr*))vt[0x60 / 4];
    fn(obj, pkStrings);
}

// Colour key block referenced by a particle-system colour modifier.
// Only the fields that the modifier touches are modelled here.
class NiColorData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;     // number of colour keys               (0x08)
    char* m_pKeyTimes;            // raw key block, key time comes first (0x0C)
    float m_fTimeSpan;            //                                    (0x10)
    unsigned char m_ucKeyStride;  // bytes between two colour keys      (0x14)
};

// The colour modifier itself; the class of the pack header already carries
// the colour data pointer (0x18) and the two key time bounds (0x1C/0x20).
class NiPSysColorModifierLocal : public NiPSysColorModifier
{
  public:
    void SetColorData(NiColorData* pkColorData);
};

// Replaces the stored color data with pkColorData, updating reference counts and recomputing the low and high key times from its key times.
// @fnv 0x00c2d100
void NiPSysColorModifierLocal::SetColorData(NiColorData* pkColorData)
{
    if (m_spColorData.m_pObject != pkColorData)
    {
        NiColorData* pOldColorData = m_spColorData.m_pObject;
        if (pOldColorData != 0)
        {
            pOldColorData->DecRefCount();
        }

        m_spColorData.m_pObject = pkColorData;
        if (pkColorData != 0)
        {
            pkColorData->IncRefCount();
        }
    }

    m_fLoKeyTime = 0.0f;
    m_fHiKeyTime = 0.0f;

    NiColorData* pColorData = m_spColorData.m_pObject;
    if (pColorData != 0)
    {
        unsigned int uiNumKeys = pColorData->m_uiNumKeys;
        unsigned char ucKeyStride = pColorData->m_ucKeyStride;
        char* pKeyTimeArray = pColorData->m_pKeyTimes;
        if (uiNumKeys != 0)
        {
            m_fLoKeyTime = *(float*)pKeyTimeArray;
            unsigned int uiLastKeyOffset = (uiNumKeys - 1) * ucKeyStride;
            m_fHiKeyTime = *(float*)(pKeyTimeArray + uiLastKeyOffset);
        }
    }
}

struct Ctor00c2d240
{
    void Ctor();
};
struct HostLike
{
    void SetColorData(void*);
};

struct S00c2d240
{
    void FUN_00c31780(void*, int);
    void* CreateAndInit(int arg);
};

extern "C" void* __cdecl Alloc00c2d240(unsigned int);

// @fnv 0x00c2d240
void* S00c2d240::CreateAndInit(int arg)
{
    void* pObject = Alloc00c2d240(0x24);
    if (pObject)
    {
        ((Ctor00c2d240*)pObject)->Ctor();
        *(void**)pObject = (void*)0x010bffe4;
        *(volatile int*)((char*)pObject + 0x18) = 0;
        *(volatile float*)((char*)pObject + 0x1c) = 0.0f;
        *(volatile float*)((char*)pObject + 0x20) = 0.0f;
    }
    else
    {
        pObject = 0;
    }
    this->FUN_00c31780(pObject, arg);
    void* tmp = *(void**)((char*)this + 0x18);
    ((HostLike*)pObject)->SetColorData(tmp);
    return pObject;
}

struct ColorDataStandIn
{
    virtual ~ColorDataStandIn();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        NiAtomicIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicSubtract(m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class SmartPtrStandIn
{
  public:
    SmartPtrStandIn(T* pObject = (T*)0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SmartPtrStandIn()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

struct PSysModifierBase
{
    PSysModifierBase() throw();
    virtual ~PSysModifierBase();
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiUpdateOrder;
    void* m_pkTarget;
    bool m_bModifierActive;
};

struct PSysColorModifierStandIn : PSysModifierBase
{
    static void* __cdecl operator new(unsigned int uiSize);
    PSysColorModifierStandIn() throw() : m_spColorData(0), m_fLoKeyTime(0.0f), m_fHiKeyTime(0.0f)
    {}
    virtual ~PSysColorModifierStandIn();
    SmartPtrStandIn<ColorDataStandIn> m_spColorData;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
};

// Allocates and returns a new PSysColorModifierStandIn instance.
// @fnv 0x00c2d180
void* __cdecl CreateColorModifier()
{
    return new PSysColorModifierStandIn;
}

struct FnvColorAView
{
    float r;
    float g;
    float b;
    float a;
};

struct PInfo
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    unsigned int unk18;
};

struct PData
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    FnvColorAView* m_pkParticleColors;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned short m_usActive;
    unsigned short unk52;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5a;
    unsigned short unk5c;
    unsigned short unk5e;
    unsigned short unk60;
    unsigned short unk62;
    unsigned short unk64;
    unsigned short unk66;
    unsigned short unk68;
    unsigned short unk6a;
    unsigned short unk6c;
    unsigned short unk6e;
    PInfo* m_pkInfo;
};

struct ColorDataView
{
    void* vtable;
    unsigned int refCount;
    unsigned int m_uiNumKeys;
    char* m_pkKeyTimes;
    unsigned int m_eTypeBits;
    unsigned char m_ucSize;
};

void __cdecl InterpolateColor(FnvColorAView* out, float t, char* keys, unsigned int typeBits, unsigned int n,
                              unsigned int* idx, unsigned char stride);

inline float Mx(float a, float b)
{
    return (a > b) ? a : b;
}
inline float Mn(float a, float b)
{
    return (a < b) ? a : b;
}

struct FUN_00c2cfb0_Class : NiPSysColorModifier
{
    void UpdateColor(float fTime, NiPSysData* pkData);
};

// For each active particle, computes a clamped time from PInfo values and samples the color key data to update the particle color array.
// @fnv 0x00c2cfb0
void FUN_00c2cfb0_Class::UpdateColor(float fTime, NiPSysData* pkData)
{
    PData* d = (PData*)pkData;
    FnvColorAView* pParticleColors = d->m_pkParticleColors;
    PInfo* pParticleInfo = d->m_pkInfo;
    if (!pParticleColors)
        return;

    unsigned short usActiveCount = d->m_usActive;
    ColorDataView* pColorData = (ColorDataView*)(void*)m_spColorData.m_pObject;
    unsigned int idx = 0;
    unsigned int n = pColorData->m_uiNumKeys;
    unsigned int uiTypeBits = pColorData->m_eTypeBits;
    unsigned char ucStride = pColorData->m_ucSize;
    char* keys = pColorData->m_pkKeyTimes;

    for (unsigned short iIndex = 0; iIndex < usActiveCount; iIndex++)
    {
        FnvColorAView& r = pParticleColors[iIndex];
        float t = pParticleInfo[iIndex].m_fXValue / pParticleInfo[iIndex].m_fYValue;
        t = Mx(t, m_fLoKeyTime);
        t = Mn(t, m_fHiKeyTime);

        FnvColorAView cColor;
        idx = 0;
        InterpolateColor(&cColor, t, keys, uiTypeBits, n, &idx, ucStride);
        r = cColor;
    }
}

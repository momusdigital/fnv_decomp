
// src/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3ec8;

// @fnv 0x00a42e80
void* __cdecl FUN_00a42e80()
{
    return &g_011f3ec8;
}

struct NiFloatInterpController
{
    void Init();
};

struct BSFadeNode
{
    static void* operator new(unsigned int);
};

extern int DAT_0109780c;

// @fnv 0x00a42ee0
void* __cdecl FUN_00a42ee0()
{
    void* p = BSFadeNode::operator new(0x38);
    if (p)
    {
        NiFloatInterpController* pController = static_cast<NiFloatInterpController*>(p);
        pController->Init();
        *reinterpret_cast<int**>(pController) = &DAT_0109780c;
        return pController;
    }
    return 0;
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
struct NiObjectNET
{
    virtual ~NiObjectNET();
    virtual void _u1();
    virtual const NiRTTI* GetRTTI();
};
extern const char* const g_011f5e6c_arg1;
// Walks pkTarget's NiRTTI chain and returns true if any entry matches g_011f5e6c_arg1, false otherwise or when pkTarget is null.
// @fnv 0x00a42d90
bool __stdcall InterpTargetIsCorrectType(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    const NiRTTI* pkRTTI = pkTarget->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (const NiRTTI*)&g_011f5e6c_arg1)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

void __stdcall FUN_00a576c0(StrArr*);
char* __cdecl _FUN_00a7d330(void*);

// @fnv 0x00a42f10
void __stdcall FUN_00a42f10(StrArr* pkStrings)
{
    FUN_00a576c0(pkStrings);
    char* pcString = _FUN_00a7d330(g_011f3ec8);
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 8);
    if (uiIndex >= uiSize)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiGrow + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcString);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class A42D00Stream
{
  public:
    void* GetLoadedObject();

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
};

class A42D00Interpolator
{
  public:
    A42D00Interpolator(void* pkData) throw();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    virtual void vfn00();
    virtual void DeleteThis() throw();
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
    virtual void Collapse();

    long m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class A42D00InterpPtr
{
  public:
    A42D00InterpPtr& operator=(A42D00Interpolator* pObject) throw()
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
    A42D00Interpolator* operator->() const
    {
        return m_pObject;
    }

    A42D00Interpolator* m_pObject;
};

class A42D00Controller
{
  public:
    void LinkObjectBase(A42D00Stream& kStream);
    void LinkInterpolator(A42D00Stream& kStream);

    void* m_ppVirtualMethodTable;
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
    A42D00InterpPtr m_spControllerInterpolator;
};

// Links the object base from the stream and, for older file versions, creates an interpolator from the stream data and collapses it.
// @fnv 0x00a42d00
void A42D00Controller::LinkInterpolator(A42D00Stream& kStream)
{
    LinkObjectBase(kStream);
    if (kStream.m_uiFileVersion < 0x0A010068)
    {
        void* pkData = kStream.GetLoadedObject();
        m_spControllerInterpolator = new A42D00Interpolator(pkData);
        m_spControllerInterpolator->Collapse();
    }
}

struct NiStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
};

struct Base840
{
    void FUN_00a57c00(NiStream& kStream);
    void FUN_00a44ce0(NiStream& kStream);
};

// @fnv 0x00a44ce0
void Base840::FUN_00a44ce0(NiStream& kStream)
{
    FUN_00a57c00(kStream);
}

extern const float DAT_01096324;

struct NiUpdateDataA42D
{
    float m_fTime;
    int unk04;
    bool m_bUnk08;
};

class NiFrustumA42D
{
  public:
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

class NiAVObjectA42D
{
  public:
    virtual void vfn_00();
    void FUN_00a6faf0(const NiFrustumA42D& kFrustum);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90;
    int unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    int unkC4, unkC8, unkCC, unkD0, unkD4, unkD8;
    NiFrustumA42D m_kViewFrustum;
};

class NiFloatInterpolatorA42D
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual bool Update(float fTime, NiAVObjectA42D* pkInterpTarget, float& fValue);
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual bool AlwaysUpdate() const;
};

class NiCameraControllerA42D
{
  public:
    virtual void vfn_00();
    bool FUN_00a36250(float fTime);
    void FUN_00a42dc0(NiUpdateDataA42D& kUpdateData);

    bool GetManagerControlled() const
    {
        return (bool)((m_uiObjectFlags >> 5) & 1);
    }

    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    unsigned short unk0A;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiAVObjectA42D* m_pkTarget;
    void* m_spNextController;
    NiFloatInterpolatorA42D* m_spControllerInterpolator;
};

// Updates the camera controller time and, if not skipped, applies the interpolator's value to the target's view frustum bounds.
// @fnv 0x00a42dc0
void NiCameraControllerA42D::FUN_00a42dc0(NiUpdateDataA42D& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (FUN_00a36250(kUpdateData.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        float fValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, fValue))
        {
            NiAVObjectA42D* pkCamera = m_pkTarget;
            NiFrustumA42D kFrustum = pkCamera->m_kViewFrustum;
            kFrustum.m_fLeftBound = -fValue;
            kFrustum.m_fRightBound = fValue;
            kFrustum.m_fTopBound = fValue * 0.75;
            kFrustum.m_fBottomBound = fValue * -0.75;
            pkCamera->FUN_00a6faf0(kFrustum);
        }
    }
}

class CloningProcessObjA42E;

class FUN_00a57640
{
  public:
    FUN_00a57640() throw();
    virtual ~FUN_00a57640() throw();
    int unk04[13];
};

class ObjA42E : public FUN_00a57640
{
  public:
    ObjA42E() throw()
    {}
    virtual ~ObjA42E() throw();

    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }

    void FUN_00a57620(ObjA42E* dest, CloningProcessObjA42E& cloning);
    ObjA42E* CreateClone(CloningProcessObjA42E& cloning);
};

// Allocates an ObjA42E, calls FUN_00a57620 with it and cloning, and returns the new object.
// @fnv 0x00a42e90
ObjA42E* ObjA42E::CreateClone(CloningProcessObjA42E& cloning)
{
    ObjA42E* p = new ObjA42E;
    FUN_00a57620(p, cloning);
    return p;
}

extern void FUN_00a57c10();

// @fnv 0x00a44cf0
void FUN_00a44cf0()
{
    FUN_00a57c10();
}

#include <math.h>
struct NiCamera
{
    float _pad_0[0x38];
    float m_fFieldOfView;
};

struct BSFrustumFOVController : NiFloatInterpController
{
    void GetFieldOfView(float& fValue);
};

// Reads the camera's field-of-view angle and writes its arctangent doubled into fValue.
// @fnv 0x00a42cd0
void BSFrustumFOVController::GetFieldOfView(float& afOutValue)
{
    NiCamera* pCamera = *(NiCamera**)((char*)this + 0x2c);
    float v = pCamera->m_fFieldOfView;
    afOutValue = atan(v) * 2.0f;
}

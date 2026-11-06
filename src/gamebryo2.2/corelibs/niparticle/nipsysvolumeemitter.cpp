// gamebryo2.2/corelibs/niparticle/nipsysvolumeemitter.cpp: NiPSysVolumeEmitter (10 functions)

#include "nipsysvolumeemitter_match_types.h"

// @fnv 0x00c31b20
void NiPSysVolumeEmitter::LoadBinary(NiStream& stream)
{
    NiPSysEmitter::LoadBinary(stream);
    stream.ResetStreamState();
}

// @fnv 0x00c31b40
void NiPSysVolumeEmitter::LinkObject(NiStream& stream)
{
    NiPSysEmitter::LinkObject(stream);
    m_pkEmitterObject = (NiAVObject*)stream.GetLoadedObject();
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00c31c90_shell : public NiPSysVolumeEmitter
{
    void FUN_00c31c90(CloningProcess*);
};

class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};

struct NiPSysModifier_Fake : public NiPSysModifier
{
    void ProcessClone(CloningProcess&);
};

static inline void CallBaseProcessClone(NiPSysModifier* pThis, CloningProcess& kCloning)
{
    void (NiPSysModifier::*fn)(CloningProcess&) =
        (void(NiPSysModifier::*)(CloningProcess&)) & NiPSysModifier_Fake::ProcessClone;
    (pThis->*fn)(kCloning);
}

// @fnv 0x00c31c90
void FUN_00c31c90_shell::FUN_00c31c90(CloningProcess* kCloning)
{
    CallBaseProcessClone(this, *kCloning);
    NiObject* pkClone = 0;
    ((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)
        ->GetAt((const char*)this, (ShaderBufferRecord*&)pkClone);
    NiPSysVolumeEmitter* pkDest = (NiPSysVolumeEmitter*)pkClone;
    if (m_pkEmitterObject)
    {
        if (((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)
                ->GetAt((const char*)m_pkEmitterObject, (ShaderBufferRecord*&)pkClone))
        {
            pkDest->m_pkEmitterObject = (NiAVObject*)pkClone;
        }
        else
        {
            pkDest->m_pkEmitterObject = m_pkEmitterObject;
        }
    }
}

struct BSPSysArrayEmitter;
struct NiAVObject;
struct CloningProcess;
struct NiTransform;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00c31cf0_shell : public NiPSysVolumeEmitter
{
    void ComputeEmitterInitialPositionAndVelocity(NiPoint3*, NiPoint3*);
};

struct NiTransform
{
    int m_data[13];
    void CalculateInverse(NiTransform&);
    NiTransform operator*(NiTransform const&) const;
    void ResetToIdentity(void);
};

typedef void(__thiscall* ComputeVolumeInitialPositionAndVelocity_t)(void*, NiTransform&, NiPoint3*, NiPoint3*);

// Builds the emitter-to-PSys transform from the emitter and target transforms (or identity) and calls the volume emitter's virtual compute function with it.
// @fnv 0x00c31cf0
void FUN_00c31cf0_shell::ComputeEmitterInitialPositionAndVelocity(NiPoint3* kPosition, NiPoint3* kMotionVelocity)
{
    if (m_pkEmitterObject)
    {
        NiTransform kEmitter = *(NiTransform*)((char*)m_pkEmitterObject + 0x68);
        NiTransform kPSys = *(NiTransform*)((char*)m_pkTarget + 0x68);
        NiTransform kInvPSys;
        kPSys.CalculateInverse(kInvPSys);
        NiTransform kEmitterToPSys = kInvPSys * kEmitter;
        ((ComputeVolumeInitialPositionAndVelocity_t)(*(int**)this)[0xb0 / 4])(this, kEmitterToPSys, kPosition,
                                                                              kMotionVelocity);
    }
    else
    {
        NiTransform kEmitterToPSys;
        kEmitterToPSys.ResetToIdentity();
        ((ComputeVolumeInitialPositionAndVelocity_t)(*(int**)this)[0xb0 / 4])(this, kEmitterToPSys, kPosition,
                                                                              kMotionVelocity);
    }
}

extern char const* const g_01202508_arg1;

// @fnv 0x00c31bc0
char const* const* __cdecl FUN_00c31bc0()
{
    return &g_01202508_arg1;
}

void __cdecl FUN_00c31750(void);

extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00c31c70_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x00c31c70
void* __thiscall FUN_00c31c70_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x58);
    return this;
}

struct FakeStream_00c31b60
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
    virtual void At30(void*);
};
struct Stub_00c31b60
{
    char _pad[0x54];
    void* m_obj;
    void FUN_00c22530(void* s);
    void FUN_00c31b60(void* s);
};
// Calls FUN_00c22530 on s, then invokes the virtual At30 on s passing m_obj.
// @fnv 0x00c31b60
void Stub_00c31b60::FUN_00c31b60(void* s)
{
    FUN_00c22530(s);
    ((FakeStream_00c31b60*)s)->At30(m_obj);
}

struct FUN_00c31b80_This
{
    char _pad[0x54];
    void* m_pkEmitterObject;
    bool Equals(void* pkObject);
    bool FUN_00c31b80(void* pkObject);
};
// @fnv 0x00c31b80
bool FUN_00c31b80_This::FUN_00c31b80(void* pkObject)
{
    FUN_00c31b80_This* pkDest = (FUN_00c31b80_This*)pkObject;
    if (!Equals(pkObject))
        return false;
    if (m_pkEmitterObject)
    {
        if (!pkDest->m_pkEmitterObject)
            return false;
    }
    if (!m_pkEmitterObject)
    {
        if (pkDest->m_pkEmitterObject)
            return false;
    }
    return true;
}

struct NameArray_b9457
{
    char unk00[8];
    unsigned short m_usMax;
    unsigned short m_usNum;
    char unk0c[2];
    unsigned short m_usGrow;
    void Resize(unsigned int newSize);
    void SetAt(unsigned int index, void* item);
};

struct NameHolder_b9457
{
    char unk00[8];
    void* m_pIntegerData;
};

extern void* DAT_012027d8;
void* __cdecl FUN_00a7d330(void* p);
void* __cdecl FUN_00a7d5e0(const char* fmt, void* arg);

struct FUN_00c31db0_cls
{
    char unk00[0x54];
    NameHolder_b9457* m_pHolder;
    void GetViewerStrings(NameArray_b9457* arr);
    void FUN_00c31db0(NameArray_b9457* arr);
};

// @fnv 0x00c31db0
void FUN_00c31db0_cls::FUN_00c31db0(NameArray_b9457* arr)
{
    GetViewerStrings(arr);
    void* name = FUN_00a7d330(DAT_012027d8);
    unsigned int uiIndex = arr->m_usNum;
    if (uiIndex >= arr->m_usMax)
    {
        arr->Resize(uiIndex + arr->m_usGrow);
    }
    arr->SetAt(uiIndex, &name);
    if (m_pHolder != 0)
    {
        void* holderVal = m_pHolder->m_pIntegerData;
        name = FUN_00a7d5e0("Emitter Object", holderVal);
        uiIndex = arr->m_usNum;
        if (uiIndex >= arr->m_usMax)
        {
            arr->Resize(uiIndex + arr->m_usGrow);
        }
        arr->SetAt(uiIndex, &name);
    }
}

struct FUN_00c31bd0_base
{
    FUN_00c31bd0_base(const char* pcName, unsigned int uiOrder, float fSpeed, float fSpeedVar, float fDeclination,
                      float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar, RgbaColor kInitialColor,
                      float fInitialRadius, float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~FUN_00c31bd0_base();
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
    float m_fEmissionSpeed;
    float m_fSpeedVariation;
    float m_fEmissionDeclination;
    float m_fDeclinationVariation;
    float m_fEmissionPlanarAngle;
    float m_fPlanarAngleVariation;
    RgbaColor m_kParticleColor;
    float m_fEmissionRadius;
    float m_fRadiusVariation;
    float m_fYValue;
    float m_fLifeSpanVariation;
    float m_fScale;
};

struct FUN_00c31bd0 : FUN_00c31bd0_base
{
    FUN_00c31bd0(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed, float fSpeedVar, float fDeclination,
                 float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar, RgbaColor kInitialColor,
                 float fInitialRadius, float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~FUN_00c31bd0();
    NiAVObject* m_pkEmitterObject;
};

FUN_00c31bd0::FUN_00c31bd0(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed, float fSpeedVar,
                           float fDeclination, float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar,
                           RgbaColor kInitialColor, float fInitialRadius, float fLifeSpan, float fLifeSpanVar,
                           float fRadiusVar)
    // Constructs a particle system modifier by delegating to the base class and storing the emitter object pointer.
// @fnv 0x00c31bd0
    : FUN_00c31bd0_base(pcName, 1000, fSpeed, fSpeedVar, fDeclination, fDeclinationVar, fPlanarAngle, fPlanarAngleVar,
                        kInitialColor, fInitialRadius, fLifeSpan, fLifeSpanVar, fRadiusVar)
{
    m_pkEmitterObject = pkEmitterObj;
}

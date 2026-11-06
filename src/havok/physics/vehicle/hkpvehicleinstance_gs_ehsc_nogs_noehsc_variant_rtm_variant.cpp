// src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/hkpvehicleinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleInstance.h"
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
void* FUN_00c85750() throw();
struct VUC_Mon
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};
struct VUC_Timer
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
struct VUC_StepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
struct VUC_RealArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct VUC_WheelParams
{
    float m_fSphereRadius;
    float m_fViscosityFriction;
    float m_fMaxFriction;
    float m_fSlipAngle;
    float m_fSlipVelocity;
    float m_fMaxContactBodyAcceleration;
    float m_fForceFeedbackMultiplier;
    float m_fMaxFrictionForce;
    float m_fFrictionEqualizer;
    signed char m_iAxle;
};
struct VUC_WPArray
{
    VUC_WheelParams* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const VUC_WheelParams& operator[](int i) const
    {
        return m_data[i];
    }
};
struct __declspec(align(16)) VUC_Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct VUC_Data
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VUC_Vector4 m_kGravity;
    signed char m_iWheelCount;
    VUC_Vector4 m_kChassisOrientation[3];
    float m_fChassisMass;
    float m_fTorqueMax;
    float m_fTorqueMin;
    float m_fTorqueFactor;
    float m_fTorquePitchFactor;
    float m_fTorqueRollFactor;
    float m_fTorqueYawFactor;
    float m_fExtraTorqueFactor;
    float m_fChassisUnitInertiaRoll;
    float m_fChassisUnitInertiaPitch;
    float m_fChassisUnitInertiaYaw;
    VUC_WPArray m_kWheelParams;
};
struct VUC_Filtered
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct VUC_Transmission
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    int m_iGearCount;
    int m_iGearCapacity;
};
struct FUN_00e39400
{
    VUC_RealArray m_kFirstRealArray;
    VUC_RealArray m_kSecondRealArray;
    float m_unk18;
    FUN_00e39400()
    {
        m_kFirstRealArray.m_data = 0;
        m_kFirstRealArray.m_iElementCount = 0;
        m_kFirstRealArray.m_iCapacityState = 0x80000000;
        m_kSecondRealArray.m_data = 0;
        m_kSecondRealArray.m_iElementCount = 0;
        m_kSecondRealArray.m_iCapacityState = 0x80000000;
    }
    ~FUN_00e39400() throw();
};
struct VUC_Instance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VUC_Data* m_data;
    void FUN_00e37aa0(float dt, void* det) throw();
    void FUN_00e36f60(float dt, VUC_Filtered& f) throw();
    void UpdateSteering(float dt, const VUC_Filtered& f) throw();
    void FUN_00e36fa0(float dt, VUC_Transmission& t) throw();
    void FUN_00e37020(float dt, const VUC_Filtered& f, VUC_Transmission& t) throw();
    void UpdateVehicleState(float dt, const VUC_Filtered& f, FUN_00e39400& b) throw();
    void NotifyListener(float dt, void* det, VUC_RealArray& s) throw();
    void FUN_00e37080(float dt, void* aero) throw();
    void UpdateVehicleComponents(const VUC_StepInfo& stepInfo, void* det, void* aero,
                                 VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel);
};
struct VUC_World
{
    void FUN_00c914d0(void* entity, int flag);
};
struct VUC_VehicleTarget
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void addToWorld(void* world) = 0;
};
struct VUC_VehicleInstance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    void* m_data;
    unsigned char m_auiShapeKeys[0x1c];
    VUC_VehicleTarget* m_target;

    void addToWorld(void* world);
};
struct VUC_DeltaTime
{
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
void __cdecl FUN_00e59a40(void* a, void* b, void* c, void* d);
struct FUN_00e38080StandIn
{
    unsigned char m_unknown00[0x1c];
    unsigned char* m_data;
    unsigned char m_unknown20[0x34];
    void* m_object54;

    void FUN_00e38080(const VUC_StepInfo& stepInfo, void* arg2);
};
struct DDCC60World
{
    void removeReference();
};
struct VUC_Allocator
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void* ptr, unsigned int size);
};
struct VUC_Router
{
    char m_auiShapeKeys[0x10];
    VUC_Allocator* m_pThreadAllocator;
};
extern int DAT_010df34c;
VUC_Router* _D1A0E0GetMemoryRouter();
void __fastcall FUN_00d2b2b0(void*);
struct FUN_00e38bf0
{
    void* m_vtbl;
    char m_uiStandInValue[0x18];

    DDCC60World* m_ref1c;
    DDCC60World* m_ref20;
    DDCC60World* m_ref24;
    DDCC60World* m_ref28;
    DDCC60World* m_ref2c;
    DDCC60World* m_ref30;
    DDCC60World* m_ref34;
    DDCC60World* m_ref38;
    DDCC60World* m_ref3c;
    DDCC60World* m_ref40;
    DDCC60World* m_ref44;

    void* m_data48;
    int m_size4c;
    int m_capacity50;

    char m_iValueAfterStandIn[0x48];

    DDCC60World* m_ref9c;
    void* m_dataa0;
    int m_sizea4;
    int m_capacitya8;

    char m_pAuxiliaryObject[0x14];

    void* m_datac0;
    int m_sizec4;
    int m_capacityc8;

    FUN_00e38bf0();
    ~FUN_00e38bf0();
};
struct FnvCpu_FUN_00e36f50_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00e36f50_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    FnvCpu_FUN_00e36f50_CpuInterface* target;
    void FUN_00e36f50(int arg0);
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    float value;
    float FUN_00e370a0();
};
struct Filtered
{
    float a, b, c, d;
};
struct Transmission
{
    float engineRpm;
    float mainTorque;
    float* wheels;
    int reversing;
    int gear;
};
struct Pair
{
    float m_kPointA;
    float m_kPointB;
};
struct Instance;
struct Target
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(float dt, Instance* inst, const Filtered* f, Transmission* t, Pair* out);
};
struct Instance
{
    void* m_vtbl;
    char m_auiShapeKeys[0x24];
    Target* m_target;
    char m_pAuxiliaryObject[0xb4 - 0x2c];
    float m_b4;
    float m_b8;
    void FUN_00e37020(float dt, const Filtered& f, Transmission& t) throw();
};
class hkListenerE371
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void notify(float f, void* pvSource, void* a, void* b);
};
class hkObjE371
{
  public:
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
    hkListenerE371* m_kListener;

    void NotifyListener(float f, void* a, void** pb);
};
struct hkBoolE379
{
    char m_cBooleanValue;
    hkBoolE379(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
class hkpWorldE379;
class hkpEntityE379
{
  public:
    int m_00;
    int m_04;
    hkpWorldE379* m_pOwningWorld;

    hkpWorldE379* getWorld() const
    {
        return m_pOwningWorld;
    }
};
class hkpWorldE379
{
  public:
    hkBoolE379 ProcessTarget(hkpEntityE379* pkEntity);
};
class hkActionE379
{
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
};
class FUN_00e37910_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    hkpEntityE379* m_pEntity;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    hkActionE379* m_pAction;

    void FUN_00e37910();
};
void __cdecl FUN_00c908c0(VUC_Allocator* allocator, VUC_RealArray* array, int capacity, int stride);
struct VUC_BrakingStrategy
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void calculate(float dt, VUC_Instance* vehicle, const VUC_Filtered& input, FUN_00e39400& output);
};
struct hkAllocatorE38D
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};
struct hkMemoryRouterE38D
{
    void* m_apvUnk00[4];
    hkAllocatorE38D* m_pkHeap;
    hkAllocatorE38D& heap()
    {
        return *m_pkHeap;
    }
};
void __cdecl FUN_00c908c0(hkAllocatorE38D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <typename T> struct hkArrayE38D
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE38D() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayE38D() throw()
    {
        hkAllocatorE38D& kAlloc = ((hkMemoryRouterE38D*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkAllocatorE38D& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(((hkMemoryRouterE38D*)FUN_00c85750())->heap(), n);
        m_iElementCount = n;
    }
};
struct hkpVehicleSteeringAnglesOutputE38D
{
    hkReal m_fMainSteeringAngle;
    hkArrayE38D<hkReal> m_kWheelSteeringAngles;
};
struct hkpFilteredDriverInputOutputE38D;
class hkpVehicleSteering
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void CalcSteering(const hkReal fMoveElapsedTime, const hkpVehicleInstance* pkVehicle,
                              const hkpFilteredDriverInputOutputE38D& kFilteredInfo,
                              hkpVehicleSteeringAnglesOutputE38D& kSteeringOutput) throw();
};
class hkpVehicleInstanceE38D : public hkpVehicleInstance
{
  public:
    void UpdateSteering(hkReal fMoveElapsedTime, const hkpFilteredDriverInputOutputE38D& kFilteredInfo) throw();
};
struct VUC_InplaceRealArray16 : VUC_RealArray
{
    float m_kStorage[16];
};
struct VUC_AeroOutput
{
    VUC_Vector4 m_kForce;
    VUC_Vector4 m_kTorque;
};
static inline void VUC_ReleaseArray(VUC_RealArray& a)
{
    VUC_Router* router = (VUC_Router*)FUN_00c85750();
    VUC_Allocator* allocator = router->m_pThreadAllocator;
    a.m_iElementCount = 0;
    if ((a.m_iCapacityState & 0x80000000) == 0)
        allocator->free(a.m_data, (a.m_iCapacityState & 0x3fffffff) * sizeof(float));
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
}
struct VUC_StepLocals
{
    VUC_AeroOutput aerodynamicsInfo;
    VUC_InplaceRealArray16 suspensionForceAtWheel;
};
struct VUC_StepInstance : VUC_Instance
{
    void FUN_00e385e0(const VUC_StepInfo& stepInfo, const VUC_AeroOutput& aero,
                      const VUC_RealArray& suspensionForceAtWheel,
                      const VUC_RealArray& totalLinearForceAtWheel) throw();
    void FUN_00e39030(const VUC_StepInfo& stepInfo, void* det);
};
void* FUN_00c85750() throw();
struct VehicleStepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
struct __declspec(align(16)) VehicleVector4
{
    float x, y, z, w;
};
struct VehicleData
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VehicleVector4 m_kGravity;
    signed char m_iWheelCount;
};
struct VehicleScratchAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void free(void* memory, unsigned int bytes);
};
struct VehicleMemoryRouter
{
    char* m_stackTop;
    void* m_stackEnd;
    void* m_stackCapacity;
    void* m_heapFallback;
    VehicleScratchAllocator* m_pThreadAllocator;
};
struct VehicleWheelCollide
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void CollideWheels(float deltaTime, void* vehicle, void* scratch);
};
struct VehicleInstance
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VehicleData* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    VehicleWheelCollide* m_pWheelCollide;
    void FUN_00e37940();
    void FUN_00e39030(const VehicleStepInfo* stepInfo, void* scratch);
    void FUN_00e39190(const VehicleStepInfo* stepInfo);
};
class hkMemoryAllocatorE392
{
  public:
    virtual ~hkMemoryAllocatorE392() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterE392
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE392* m_pStreamAllocator;
    hkMemoryAllocatorE392& heap()
    {
        return *m_pStreamAllocator;
    }
};
class hkRefObjectE392
{
  public:
    virtual ~hkRefObjectE392() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90510() throw();
};
class hkShapeE392;
struct hkInputInfoE392
{
    const hkShapeE392* m_pCollisionShape;
};
struct hkInputE392
{
    const hkInputInfoE392* m_info;
};
struct hkAgentDataE392
{
    int unk00;
    int unk04;
    unsigned char m_sState;
};
class hkAgentFactoryE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual hkAgentDataE392* createAgent(const hkShapeE392* pkShape, int iFlags) throw();
};
class hkClonableE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual hkClonableE392* clone() throw();
};
class hkSourceE392;
class FUN_00e38b20
{
  public:
    virtual ~FUN_00e38b20() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_08;
    int m_0c;
    int unk10;
    int unk14;
    const hkShapeE392* m_pCollisionShape;
    hkRefObjectE392* m_1c;
    hkRefObjectE392* m_20;
    hkRefObjectE392* m_24;
    hkRefObjectE392* m_28;
    hkRefObjectE392* m_2c;
    hkRefObjectE392* m_30;
    hkRefObjectE392* m_34;
    hkRefObjectE392* m_38;
    hkAgentDataE392* m_pCollisionAgent;
    hkRefObjectE392* m_40;
    hkRefObjectE392* m_44;
    char unk48[0x54];
    hkClonableE392* m_9c;
    char unkA0[0x34];

    void* operator new(unsigned int nbytes)
    {
        FUN_00e38b20* b = static_cast<FUN_00e38b20*>(
            static_cast<hkMemoryRouterE392*>(FUN_00c85750())->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00e38b20(const hkShapeE392* pkShape) throw();
    void FUN_00e39480(const hkSourceE392* pkOther) throw();
};
typedef char fnv_check_e39210[(sizeof(FUN_00e38b20) == 0xd4) ? 1 : -1];
class hkSourceE392
{
  public:
    char unk00[0x3c];
    hkAgentFactoryE392* m_factory;
    hkRefObjectE392* m_40;
    char unk44[0x58];
    hkClonableE392* m_9c;

    FUN_00e38b20* FUN_00e39210(const hkInputE392* pkInput, int iFlags) throw();
};
void __cdecl FUN_00e39190();
void __cdecl applyAction();
struct VUC_TransmissionTarget10
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void addToWorld(float dt, void* instance, void* transmission) = 0;
};
struct VUC_Transmission8
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    signed char m_iGearCount;
    signed char m_iGearCapacity;
    signed char m_gear2;
    signed char m_gear3;
    float m_extra;
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
struct Q_e380c0_Vec
{
    __m128 q;
};
struct Q_e380c0_Sub
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
    virtual void v40(const Q_e380c0_Vec* p);
    virtual void v44(const Q_e380c0_Vec* p);
    __m128 c0;
    __m128 c1;
    __m128 c2;
};
struct Q_e380c0_A
{
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
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    int uc0;
    int uc4;
    int uc8;
    int ucc;
    int ud0;
    int ud4;
    int ud8;
    int udc;
    Q_e380c0_Sub sub;
};
struct Q_e380c0_cls
{
    int u00, u04, u08, u0c, u10, u14;
    Q_e380c0_A* a;
    void FUN_00e380c0(const Q_e380c0_Vec* in);
};
struct FUN_00e39300_class
{
    __m128 unk00;
    __m128 unk10;
    float unk20;
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
    __m128 unk50;
    __m128 unk60;
    float unk70;
    __m128 unk80;
    __m128 unk90;
    __m128 unka0;
    __m128 unkb0;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;
    float unkd4;
    FUN_00e39300_class& FUN_00e39300(const FUN_00e39300_class* src);
};
inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
class hkMemoryAllocatorE39
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterE39
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE39* m_pStreamAllocator;
    hkMemoryAllocatorE39& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE39& __cdecl GetMemoryRouterE39() throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorE39& kAlloc, void* pArray, int iNumElements, int iSizeElem);
template <class T> __forceinline void destructE39(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}
template <class T> __forceinline void copyE39(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> __forceinline void constructWithArrayE39(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        ::new (static_cast<void*>(pDst + i)) T(pSrc[i]);
}
template <class T> class hkClassArrayE39
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorE39& kAlloc, int n)
    {
        if (getCapacity() < n)
        {
            int iCap2 = 2 * getCapacity();
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline hkClassArrayE39& operator=(const hkClassArrayE39& a)
    {
        hkMemoryAllocatorE39& kAlloc = GetMemoryRouterE39().heap();
        const int iOldSize = m_iElementCount;
        const int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        reserve(kAlloc, iNewSize);
        destructE39(m_data + iNewSize, iOldSize - iNewSize);
        copyE39(m_data, a.m_data, iCopiedSize);
        constructWithArrayE39(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> class hkPodArrayE39
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkPodArrayE39& operator=(const hkPodArrayE39& a)
    {
        hkMemoryAllocatorE39& kAlloc = GetMemoryRouterE39().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        copyE39(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkStringPtrE39
{
    hkStringPtrE39& operator=(const hkStringPtrE39& kOther);
    const char* m_pcText;
};
struct WheelE39
{
    WheelE39& operator=(const WheelE39& kOther);
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8C;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9C;
    int m_iA0;
    int m_iA4;
    int m_iA8;
    int m_iAC;
    int m_iB0;
    int m_iB4;
    int m_iB8;
    int m_iBC;
    int m_iC0;
    int m_iC4;
    int m_iC8;
    int m_iCC;
    int m_iD0;
    int m_iD4;
    int m_iD8;
    int m_iDC;
};
struct Block48E39
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
};
class hkReferencedObjectE39
{
  public:
    virtual ~hkReferencedObjectE39();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class VehicleDataE39 : public hkReferencedObjectE39
{
  public:
    VehicleDataE39& FUN_00e39480(const VehicleDataE39& kOther);
    int m_i08;
    int m_i0C;
    int m_i10;
    hkStringPtrE39 m_kName;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    hkClassArrayE39<WheelE39> m_akWheels;
    Block48E39 m_kBlock54;
    int m_i9C;
    hkPodArrayE39<char> m_acFlags;
    float m_fAC;
    bool m_bB0;
    float m_fB4;
    float m_fB8;
    float m_fBC;
    hkPodArrayE39<float> m_afValues;
    bool m_bCC;
    bool m_bCD;
    bool m_bCE;
    float m_fD0;
};

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_load_ss(float const* _A);
extern "C" __m128 _mm_rcp_ps(__m128 _A);
extern "C" __m128 _mm_set_ps1(float _A);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_unpackhi_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_xor_ps(__m128 _A, __m128 _B);
#include <math.h>
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

class S00e384e0_hkQuaternionE38;

class S00e384e0_hkVector4E38
{
  public:
    __m128 m_vComponents;

    __forceinline S00e384e0_hkVector4E38& operator=(const S00e384e0_hkVector4E38& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const S00e384e0_hkVector4E38& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const S00e384e0_hkVector4E38& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const S00e384e0_hkVector4E38& v1, const S00e384e0_hkVector4E38& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const S00e384e0_hkVector4E38& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const S00e384e0_hkVector4E38& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const S00e384e0_hkQuaternionE38& q, const S00e384e0_hkVector4E38& dir);
    void setRotatedInverseDir(const S00e384e0_hkQuaternionE38& q, const S00e384e0_hkVector4E38& dir);
};

class S00e384e0_hkQuaternionE38
{
  public:
    S00e384e0_hkVector4E38 m_vec;

    __declspec(noinline) void SetAxisAngle(const S00e384e0_hkVector4E38& kAxis, float fAngleDifference)
    {
        float fHalf = (float)(fAngleDifference * 0.5);
        float fSin = (float)sin(fHalf);
        m_vec.m_vComponents = _mm_mul_ps(_mm_set_ps1(fSin), kAxis.m_vComponents);
        m_vec.m_vComponents.m128_f32[3] = (float)cos(fHalf);
    }

    __forceinline void SetConjugate(const S00e384e0_hkQuaternionE38& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const S00e384e0_hkQuaternionE38& q0, const S00e384e0_hkQuaternionE38& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 aw = _mm_shuffle_ps(a, a, 0xff);
        __m128 bw = _mm_shuffle_ps(b, b, 0xff);
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

__forceinline void S00e384e0_hkVector4E38::SetRotatedDirection(const S00e384e0_hkQuaternionE38& quat,
                                                               const S00e384e0_hkVector4E38& direction)
{
    S00e384e0_hkVector4E38 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    S00e384e0_hkVector4E38 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    S00e384e0_hkVector4E38 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    S00e384e0_hkVector4E38 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void S00e384e0_hkVector4E38::setRotatedInverseDir(const S00e384e0_hkQuaternionE38& quat,
                                                                const S00e384e0_hkVector4E38& direction)
{
    S00e384e0_hkVector4E38 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    S00e384e0_hkVector4E38 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    S00e384e0_hkVector4E38 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    S00e384e0_hkVector4E38 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

extern const double DAT_01012060;

struct S00e384e0_hkTransformE38
{
    S00e384e0_hkVector4E38 m_kColumn0;
    S00e384e0_hkVector4E38 m_kColumn1;
    S00e384e0_hkVector4E38 m_kColumn2;
    S00e384e0_hkVector4E38 m_vTranslation;
};

__forceinline void setTransformedPosE38(S00e384e0_hkVector4E38& kOut, const S00e384e0_hkTransformE38& kTransform,
                                        const S00e384e0_hkVector4E38& kPos)
{
    __m128 x = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0x00);
    __m128 y = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0x55);
    __m128 z = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0xaa);
    __m128 xy = _mm_add_ps(_mm_mul_ps(y, kTransform.m_kColumn1.m_vComponents),
                           _mm_mul_ps(x, kTransform.m_kColumn0.m_vComponents));
    __m128 zt = _mm_add_ps(_mm_mul_ps(z, kTransform.m_kColumn2.m_vComponents), kTransform.m_vTranslation.m_vComponents);
    kOut.m_vComponents = _mm_add_ps(xy, zt);
}

struct S00e384e0_ChassisE38
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    S00e384e0_hkTransformE38 m_kMotionTransform;
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
    S00e384e0_hkQuaternionE38 m_rotation;
};

struct S00e384e0_HardPointE38
{
    S00e384e0_hkVector4E38 m_vContactPosition;
    S00e384e0_hkVector4E38 unk10;
    S00e384e0_hkVector4E38 unk20;
};

struct S00e384e0_VehicleDataE38
{
    int unk00;
    int unk04;
    S00e384e0_HardPointE38* m_kWheelParams;
};

struct S00e384e0_WheelInfoE38
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    float m_fContactFriction;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    S00e384e0_hkVector4E38 m_suspensionDirection;
    S00e384e0_hkVector4E38 m_spinAxis;
    S00e384e0_hkVector4E38 unka0;
    S00e384e0_hkQuaternionE38 m_steeringOrientation;
    unsigned int unkc0;
    float m_fSpinAngle;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
};

class S00e384e0_WheelCollectorE38
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    S00e384e0_WheelInfoE38* m_kWheelInfoArray;

    void calcCurrentPositionAndRotation(const S00e384e0_ChassisE38* pkChassis, const S00e384e0_VehicleDataE38* pkData, int iWheel,
                      S00e384e0_hkVector4E38& kPosOut, S00e384e0_hkQuaternionE38& kRotOut);
};

// @fnv 0x00e384e0
void S00e384e0_WheelCollectorE38::calcCurrentPositionAndRotation(const S00e384e0_ChassisE38* pkChassis,
                                               const S00e384e0_VehicleDataE38* pkData, int iWheel,
                                               S00e384e0_hkVector4E38& kPosOut, S00e384e0_hkQuaternionE38& kRotOut)
{
    const S00e384e0_WheelInfoE38& kWheel = m_kWheelInfoArray[iWheel];

    S00e384e0_hkQuaternionE38 kSpin;
    kSpin.SetAxisAngle(kWheel.m_spinAxis, -kWheel.m_fSpinAngle);
    S00e384e0_hkQuaternionE38 kSteer;
    kSteer.SetProduct(pkChassis->m_rotation, kWheel.m_steeringOrientation);
    kRotOut.SetProduct(kSteer, kSpin);

    float fLen = kWheel.m_fContactFriction;
    float fSuspension = (fLen < DAT_01012060) ? 0.0f : fLen;

    setTransformedPosE38(kPosOut, pkChassis->m_kMotionTransform, pkData->m_kWheelParams[iWheel].m_vContactPosition);
    __m128 s = _mm_load_ss(&fSuspension);
    kPosOut.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), kWheel.m_suspensionDirection.m_vComponents),
                                       kPosOut.m_vComponents);
}

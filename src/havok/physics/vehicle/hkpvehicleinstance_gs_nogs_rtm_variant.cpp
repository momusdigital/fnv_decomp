// src/havok/physics/vehicle/hkpvehicleinstance_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicleinstance.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


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
extern "C" void _mm_store_ps(float*, __m128);
extern const __m128 DAT_01267e30;
extern const __m128 DAT_010c7190;
extern const __m128 DAT_010c71b0;
extern const float DAT_01012068;
extern const float DAT_01011d78;
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_setzero_ps();
union VecInit
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    } f;
};
struct WheelInit
{
    VecInit m00;
    VecInit m10;
    float m20;
    int m24;
    int m28;
    float m2c, m30, m34, m38, m3c, m40, m44, m48, m4c;
    VecInit m50;
    VecInit m60;
    float m70, m74, m78, m7c;
    VecInit m80;
    VecInit m90;
    VecInit ma0;
    VecInit mb0;
    float mc0, mc4, mc8, mcc, md0, md4;
    void FUN_00e370b0();
};
struct FnvVehicleState
{
    unsigned char active;
    unsigned int flags04;
    float scalar08;
    float scalar0c;
    __m128 vectors10;
    __m128 vectors20;
    __m128 vectors30;
    __m128 vectors40;
    __m128 vectors50;
    __m128 vectors60;
    __m128 vectors70;
};
void __stdcall FUN_00e37160(int, FnvVehicleState* state);
struct FUN_00e39400_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VUC_Allocator* m_pThreadAllocator;
};
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);
extern const __m128 DAT_010c44d0;
struct VehFr_Vector4
{

    __m128 m_vComponents;

    void SetAllComponents(float a)

    {

        m_vComponents = _mm_set_ps1(a);
    }
};
struct VehFr_Accumulator
{

    int m_type;

    int unk04;

    int unk08;

    int unk0C;

    VehFr_Vector4 m_vLinearVelocity;

    VehFr_Vector4 m_vAngularVelocity;

    VehFr_Vector4 m_vInverseInertiaAndMass;

    VehFr_Vector4 m_vCenterOfMass;

    VehFr_Vector4 m_coreFromWorld0;

    VehFr_Vector4 m_coreFromWorld1;

    VehFr_Vector4 m_coreFromWorld2;
};
struct VehFr_AxleParams
{

    VehFr_Vector4 m_kFirstVector;

    VehFr_Vector4 m_kSecondAxleVector;

    VehFr_Vector4 m_kThirdVector;

    VehFr_Accumulator* m_pFirstPointer;

    VehFr_Accumulator* m_pSecondPointer;

    float m_fFirstScalar;

    float m_fSecondScalar;

    float m_fThirdValue;

    float m_fFourthValue;

    float m_fFifthScalar;

    float m_fSixthValue;

    unsigned char m_ucValue;
};
struct VehFr_FrictionParams
{

    VehFr_AxleParams m_akAxleParams[2];
};
struct VehFr_Motion
{

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void SetTranslationalVelocity(const VehFr_Vector4& v);

    virtual void SetRotationalVelocity(const VehFr_Vector4& v);
};
struct VehFr_MotionBody : VehFr_Motion
{

    int unk04;

    unsigned char m_type;
};
struct VehFr_MotionData
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
    int unkCC;

    VehFr_Vector4 m_kTranslationalVelocity;

    VehFr_Vector4 m_kAngularVelocity;
};
struct VehFr_Entity
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;

    VehFr_Motion m_pMotionState;

    int unkE4;

    unsigned char m_bFlag;

    unsigned char unkE9;

    unsigned char unkEA;

    unsigned char unkEB;

    int unkEC;
};
struct VehFr_Ground
{

    VehFr_Entity* m_apEntities[2];
};
struct VehFr_Data
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

    int m_iWheelCount;
};
struct VehFr_Vehicle
{

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    VehFr_Data* m_data;

    void FUN_00e38140(float dt, VehFr_FrictionParams& params, VehFr_Ground& ground);
};
extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" float _mm_cvtss_f32(__m128 _A);
extern "C" __m128 _mm_sqrt_ss(__m128 _A);
struct S00e37880_Vec
{
    __m128 m_vComponents;

    __m128 squared() const
    {
        return _mm_mul_ps(m_vComponents, m_vComponents);
    }
};
struct S00e37880_Data
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    S00e37880_Vec m_vec;
};
struct S00e37880_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00e37880_Data* m_data;

    float calcMPH();
};
extern double DAT_01017b70;
extern double DAT_01012640;
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" float _mm_cvtss_f32(__m128);
struct SpeedVectorE378
{
    __m128 m_vComponents;
    float length3() const
    {
        __m128 squares = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(squares, squares, 0x55);
        __m128 z = _mm_shuffle_ps(squares, squares, 0xaa);
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_add_ss(z, _mm_add_ss(y, squares))));
    }
};
struct SpeedBodyE378
{
    unsigned int unk000;
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
    SpeedVectorE378 m_kTranslationalVelocity;
    const SpeedVectorE378& linearVelocity() const
    {
        return m_kTranslationalVelocity;
    }
};
struct VehicleSpeedE378 : hkpVehicleInstance
{
    float FUN_00e37820();
};
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" float _mm_cvtss_f32(__m128);
struct S00e375a0_AxleData
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
};
struct __declspec(align(16)) FourFloatVector
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        __m128 m_vComponents;
    };
    __forceinline __m128 length3() const
    {
        __m128 v2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 v1 = _mm_shuffle_ps(v2, v2, 0x55);
        __m128 v0 = _mm_shuffle_ps(v2, v2, 0xaa);
        v1 = _mm_add_ss(v1, v2);
        v0 = _mm_add_ss(v0, v1);
        return _mm_sqrt_ss(v0);
    }
    __forceinline float getW() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        return w;
    }
};
class S00e375a0_hkpRigidBody
{
  public:
    int unk000;
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
    FourFloatVector m_kInertiaAndMassInv;
    FourFloatVector m_kTranslationalVelocity;
};
class hkpVehicleInstanceWheelInfo
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S00e375a0_hkpRigidBody* m_pUserData;
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
};
class S00e375a0_VehicleInstance : public VUC_Instance
{
  public:
    int unk_veh20;
    int unk_veh24;
    int unk_veh28;
    int unk_veh2c;
    int unk_veh30;
    int unk_veh34;
    int unk_veh38;
    int unk_veh3c;
    int unk_veh40;
    int unk_veh44;
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;

    void FUN_00e371d0(float deltaTime, int wheelIndex, float suspensionForce) throw();
    void FUN_00e37350(int wheelIndex, float totalLinearForce, float suspensionForce, float linearVelocity,
                      S00e375a0_AxleData* axleData) throw();
    void FUN_00e375a0(float deltaTime, VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel,
                      S00e375a0_hkpRigidBody* maxMassBodyPerAxle[2], S00e375a0_AxleData* axleData);
};
struct VUC_DriverInputStandIn
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void UpdateDriverInput(float dt, VUC_Instance* instance, unsigned int deviceStatus, VUC_Filtered& f);
};
struct VehicleAeroDispatch
{
    virtual void slot00() throw() = 0;
    virtual void slot04() throw() = 0;
    virtual void slot08() throw() = 0;
    virtual void calculate(float deltaTime, const hkpVehicleInstance* vehicle, void* output) throw() = 0;
};
class VehicleAeroInstance : public hkpVehicleInstance
{
  public:
    void FUN_00e37080(float deltaTime, void* output) throw();
};

namespace WheelUpdateBuild {
typedef ::__m128 WheelUpdateSimd;
using ::VUC_Vector4;
using ::VUC_Data;
using ::hkpVehicleInstance;
using ::DAT_01011d78;

extern "C" WheelUpdateSimd _mm_set_ss(float);
extern "C" WheelUpdateSimd _mm_load_ss(const float*);
extern "C" WheelUpdateSimd _mm_rsqrt_ss(WheelUpdateSimd);
extern "C" WheelUpdateSimd _mm_cmpeq_ss(WheelUpdateSimd, WheelUpdateSimd);
extern "C" WheelUpdateSimd _mm_mul_ss(WheelUpdateSimd, WheelUpdateSimd);
extern "C" WheelUpdateSimd _mm_sub_ss(WheelUpdateSimd, WheelUpdateSimd);
extern "C" WheelUpdateSimd _mm_andnot_ps(WheelUpdateSimd, WheelUpdateSimd);

struct __declspec(align(16)) WheelUpdateTransform
{
    VUC_Vector4 m_kColumn0;
    VUC_Vector4 m_kColumn1;
    VUC_Vector4 m_kColumn2;
};

struct __declspec(align(16)) WheelUpdateVector
{
    float x, y, z, w;
    void FUN_00c7f700(WheelUpdateTransform* rot, WheelUpdateVector* dir) throw();
};

class WheelUpdateEntity
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    unsigned int m_ulUserData;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    WheelUpdateTransform m_rotation;
};

struct __declspec(align(16)) WheelUpdateSuspWheel
{
    VUC_Vector4 m_vHardpointChassisSpace;
    VUC_Vector4 m_vDirectionChassisSpace;
    float m_fRestLength;
};

class WheelUpdateSuspension
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    WheelUpdateSuspWheel* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct __declspec(align(16)) WheelUpdateContactPair
{
    VUC_Vector4 m_contactPos;
    VUC_Vector4 m_contactNormal;
    void operator=(const WheelUpdateContactPair& rhs)
    {
        *(WheelUpdateSimd*)&m_contactPos = *(WheelUpdateSimd*)&rhs.m_contactPos;
        *(WheelUpdateSimd*)&m_contactNormal = *(WheelUpdateSimd*)&rhs.m_contactNormal;
    }
};

struct __declspec(align(16)) WheelUpdateCdWheel
{
    WheelUpdateContactPair m_kPoint;
    float m_fSuspensionLength;
    void* m_pUserData;
    unsigned int m_uiContactShapeKeys[8];
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
};

class WheelUpdateWheel
{
  public:
    WheelUpdateContactPair m_kPoint;
    float m_fSuspensionLength;
    void* m_pUserData;
    unsigned int m_uiContactShapeKeys[8];
    VUC_Vector4 m_vContactPointVelocity;
    VUC_Vector4 m_vContactNormal;
    float m_fContactFriction;
    VUC_Vector4 m_vHardPointWs;
    VUC_Vector4 m_vRayEndPointWs;
    WheelUpdateVector m_vSuspensionDirectionWs;
    VUC_Vector4 m_qSteeringOrientation;
    float m_fValueAtOffsetC0;
    float m_fSpinAngle;
    float m_fSkidEnergyDensity;
    float m_fSideForce;
    float m_fSuspensionForce;
    float m_fForwardForce;
};

extern float DAT_01017718;
extern float DAT_01016248;
extern VUC_Vector4 DAT_010c71e0;

}

// @fnv 0x00e37aa0
void VUC_Instance::FUN_00e37aa0(float dt, void* det) throw()
{
    using namespace WheelUpdateBuild;
    hkpVehicleInstance* self = (hkpVehicleInstance*)this;
    WheelUpdateTransform* chassisRot = &((WheelUpdateEntity*)self->m_pEntity)->m_rotation;
    int i = 0;
    if (i < ((VUC_Data*)self->m_data)->m_iWheelCount)
    {
        WheelUpdateSimd zero128 = _mm_set_ss(DAT_01011d78);
        WheelUpdateSimd three128 = _mm_set_ss(DAT_01017718);
        WheelUpdateSimd half128 = _mm_set_ss(DAT_01016248);
        WheelUpdateCdWheel* cdInfo = (WheelUpdateCdWheel*)det;
        int ci = 0;
        do
        {
            int fi = i;
            WheelUpdateCdWheel* cd = &cdInfo[i];
            WheelUpdateWheel* wheel = &((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[i];
            ((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[i].m_fContactFriction = cd->m_fContactFriction;
            ((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[i].m_kPoint = cd->m_kPoint;
            ((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[fi].m_fSuspensionLength = cd->m_fSuspensionLength;
            ((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[fi].m_pUserData = cd->m_pUserData;
            for (int j = -1; j < 7; ++j)
                ((WheelUpdateWheel*)self->m_kWheelInfoArray.m_data)[i].m_uiContactShapeKeys[j + 1] =
                    cdInfo[ci].m_uiContactShapeKeys[j + 1];

            float half = self->m_kWheelSteeringAngles.m_data[i] * 0.5;
            WheelUpdateSimd h = _mm_load_ss(&half);
            WheelUpdateSimd hb = ::_mm_shuffle_ps(h, h, 0);
            WheelUpdateSimd axis =
                *(WheelUpdateSimd*)&((WheelUpdateSuspension*)self->m_pSuspension)->m_data[i].m_vDirectionChassisSpace;
            VUC_Vector4 qv;
            *(WheelUpdateSimd*)&qv = ::_mm_mul_ps(hb, axis);
            qv.w = 1.0f;
            WheelUpdateSimd q = *(WheelUpdateSimd*)&qv;
            WheelUpdateSimd sq = ::_mm_mul_ps(q, q);
            WheelUpdateSimd sum = ::_mm_add_ps(::_mm_shuffle_ps(sq, sq, 0x4e), sq);
            WheelUpdateSimd lenSq = ::_mm_add_ps(::_mm_shuffle_ps(sum, sum, 0xb1), sum);
            WheelUpdateSimd r = _mm_rsqrt_ss(lenSq);
            WheelUpdateSimd mask = _mm_cmpeq_ss(lenSq, zero128);
            WheelUpdateSimd newton = _mm_mul_ss(lenSq, r);
            newton = _mm_mul_ss(newton, r);
            newton = _mm_sub_ss(three128, newton);
            WheelUpdateSimd inv = _mm_mul_ss(half128, r);
            inv = _mm_mul_ss(inv, newton);
            inv = _mm_andnot_ps(mask, inv);
            q = ::_mm_mul_ps(q, ::_mm_shuffle_ps(inv, inv, 0));
            *(WheelUpdateSimd*)&wheel->m_qSteeringOrientation = q;
            *(WheelUpdateSimd*)&wheel->m_vRayEndPointWs =
                *(WheelUpdateSimd*)&((VUC_Data*)self->m_data)->m_kChassisOrientation[2];
            ::_ReadWriteBarrier();
            WheelUpdateSimd qq = *(WheelUpdateSimd*)&wheel->m_qSteeringOrientation;
            WheelUpdateSimd v = *(WheelUpdateSimd*)&wheel->m_vRayEndPointWs;
            WheelUpdateSimd w = ::_mm_shuffle_ps(qq, qq, 0xff);
            WheelUpdateSimd prod = ::_mm_mul_ps(v, qq);
            WheelUpdateSimd y = ::_mm_shuffle_ps(prod, prod, 0x55);
            WheelUpdateSimd xy = ::_mm_add_ss(y, prod);
            WheelUpdateSimd z = ::_mm_shuffle_ps(prod, prod, 0xaa);
            WheelUpdateSimd dot = ::_mm_add_ss(z, xy);
            WheelUpdateSimd cross =
                ::_mm_sub_ps(::_mm_mul_ps(::_mm_shuffle_ps(v, v, 0xd2), ::_mm_shuffle_ps(qq, qq, 0xc9)),
                             ::_mm_mul_ps(::_mm_shuffle_ps(v, v, 0xc9), ::_mm_shuffle_ps(qq, qq, 0xd2)));
            cross = ::_mm_mul_ps(cross, w);
            WheelUpdateSimd ww = ::_mm_mul_ps(w, w);
            ww = ::_mm_add_ps(ww, *(WheelUpdateSimd*)&DAT_010c71e0);
            ww = ::_mm_mul_ps(ww, v);
            WheelUpdateSimd term = ::_mm_add_ps(ww, ::_mm_mul_ps(::_mm_shuffle_ps(dot, dot, 0), qq));
            WheelUpdateSimd result = ::_mm_add_ps(cross, term);
            result = ::_mm_add_ps(result, result);
            WheelUpdateVector spin;
            *(WheelUpdateSimd*)&spin = result;
            wheel->m_vSuspensionDirectionWs.FUN_00c7f700(chassisRot, &spin);
            ++ci;
            ++i;
        } while (i < ((VUC_Data*)self->m_data)->m_iWheelCount);
    }
}

namespace AxleGroundBuild {
typedef ::__m128 AxleQuad;
using ::hkVector4;
using ::hkRotation;
using ::hkpVehicleInstance;
using ::_mm_add_ps;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_setzero_ps;
using ::_mm_add_ss;
using ::_mm_sub_ps;
using ::_mm_store_ss;

extern "C"
{
    AxleQuad _mm_sub_ss(AxleQuad, AxleQuad);
    AxleQuad _mm_mul_ss(AxleQuad, AxleQuad);
    AxleQuad _mm_rsqrt_ss(AxleQuad);
    AxleQuad _mm_cmpeq_ss(AxleQuad, AxleQuad);
    AxleQuad _mm_andnot_ps(AxleQuad, AxleQuad);
    AxleQuad _mm_set_ss(float);
}

struct Accumulator
{
    char m_noHit;
    char unk01;
    char unk02;
    char unk03;
    int unk04;
    float m_fHitFraction;
    int unk0C;
    hkVector4 m_vContactPoint;
    hkVector4 m_contactNormal;
    hkVector4 m_vec30;
    hkVector4 m_vec40;
    hkRotation m_rotation;

    void FUN_00d72030(const Accumulator& other);
};

class AxleParams
{
  public:
    hkVector4 unk00;
    hkVector4 m_rayDirWs;
    hkVector4 m_wheelDirWs;
    Accumulator* m_contactBody1;
    Accumulator* m_contactBody2;
    int unk38;
    int unk3C;
    hkVector4 unk40;
    hkVector4 unk50;
};

extern "C" AxleQuad _mm_load_ss(const float*);
struct VelocityVector
{
    AxleQuad q;
    void setSub4(const AxleQuad& a, const AxleQuad& b)
    {
        q = _mm_sub_ps(a, b);
    }
    void mul4(float s)
    {
        AxleQuad t = _mm_load_ss(&s);
        t = _mm_shuffle_ps(t, t, 0);
        q = _mm_mul_ps(q, t);
    }
    void setMul4(float r, const AxleQuad& a)
    {
        AxleQuad t = _mm_load_ss(&r);
        t = _mm_shuffle_ps(t, t, 0);
        q = _mm_mul_ps(t, a);
    }
};

struct GroundMotion
{
    float getInvDeltaTime() const
    {
        return m_float6C;
    }
    int unk00;
    int unk04;
    unsigned char m_bFlag;
    char unk09;
    char unk0A;
    char unk0B;
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
    AxleQuad unk50;
    union
    {
        AxleQuad unk60;
        struct
        {
            float unk60_x, unk60_y, unk60_z;
            float m_float6C;
        };
    };
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
    AxleQuad unkA0;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    AxleQuad unkC0;
};

struct GroundBody
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    GroundMotion m_pMotionState;
};

class AxleDataView
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
    float m_fChassisUnitInertiaYaw;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int m_iWheelCount;
};

extern "C" void __cdecl FUN_00d29830(void* arg1, GroundMotion** motions, int numMotions, int offset,
                                     Accumulator* accumOut);

class Vehicle : public hkpVehicleInstance
{
  public:
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f(GroundBody* body, Accumulator* contact);

    void FUN_00e37d60(void* arg1, GroundBody** arg2, Accumulator* arg3, Accumulator* arg4, AxleParams* arg5);
};

__forceinline void normalizeDirection(hkVector4& v)
{
    AxleQuad v_in = *(AxleQuad*)&v;
    AxleQuad sq = _mm_mul_ps(v_in, v_in);
    AxleQuad y2 = _mm_shuffle_ps(sq, sq, 0x55);
    AxleQuad xy2 = _mm_add_ss(y2, sq);
    AxleQuad z2 = _mm_shuffle_ps(sq, sq, 0xaa);
    AxleQuad lenSq = _mm_add_ss(z2, xy2);
    AxleQuad approx = _mm_rsqrt_ss(lenSq);
    AxleQuad muls = _mm_mul_ss(_mm_mul_ss(lenSq, approx), approx);
    AxleQuad isZero = _mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f));
    AxleQuad factor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), approx), _mm_sub_ss(_mm_set_ss(3.0f), muls));
    AxleQuad invLen = _mm_andnot_ps(isZero, factor);
    AxleQuad invLen4 = _mm_shuffle_ps(invLen, invLen, 0);
    *(AxleQuad*)&v = _mm_mul_ps(v_in, invLen4);
}

__forceinline float inverseMass(const AxleQuad& v)
{
    float res;
    AxleQuad w = _mm_shuffle_ps(v, v, 0xff);
    _mm_store_ss(&res, w);
    return res;
}

__forceinline void rotateDirection(hkVector4& out, const hkRotation& a, const AxleQuad& b)
{
    AxleQuad v1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), *(AxleQuad*)&a.m_kColumn1);
    AxleQuad v0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0), *(AxleQuad*)&a.m_kColumn0);
    v1 = _mm_add_ps(v1, v0);
    AxleQuad v2 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), *(AxleQuad*)&a.m_kColumn2);
    v1 = _mm_add_ps(v1, v2);
    *(AxleQuad*)&out = v1;
}

// @fnv 0x00e37d60
void Vehicle::FUN_00e37d60(void* arg1, GroundBody** arg2, Accumulator* arg3, Accumulator* arg4, AxleParams* arg5)
{
    int i = 0;
    if (reinterpret_cast<AxleDataView*>(m_data)->m_iWheelCount <= 0)
        return;

    Accumulator* out2 = arg4;
    Accumulator* out1 = arg3;
    AxleParams* wheelInfo = arg5;

    do
    {
        normalizeDirection(wheelInfo->m_rayDirWs);
        normalizeDirection(wheelInfo->m_wheelDirWs);

        GroundBody* body = arg2[i];
        wheelInfo->m_contactBody1 = out1;
        wheelInfo->m_contactBody2 = out1;
        if (!body)
        {
            out1->m_fHitFraction = 0.0f;
            out1->m_noHit = 1;
            AxleQuad zero = _mm_setzero_ps();
            *(AxleQuad*)&out1->m_vec30 = zero;
            *(AxleQuad*)&out1->m_vContactPoint = zero;
            *(AxleQuad*)&out1->m_contactNormal = zero;
            *(AxleQuad*)&out1->m_vec40 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn0 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn1 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn2 = zero;
        }
        else if (body->m_pMotionState.m_bFlag == 5)
        {
            vslot0f(body, out1);
        }
        else if (i > 0 && body == arg2[0])
        {
            wheelInfo->m_contactBody1 = arg5[0].m_contactBody1;
            wheelInfo->m_contactBody2 = arg5[0].m_contactBody2;
        }
        else
        {
            GroundMotion* motion = &body->m_pMotionState;
            FUN_00d29830(arg1, &motion, 1, 0, out1);

            float invMass1 = inverseMass(reinterpret_cast<GroundBody*>(m_pEntity)->m_pMotionState.unkC0);
            float invMass2 = inverseMass(motion->unkC0);
            float maxRatio = reinterpret_cast<AxleDataView*>(m_data)->m_fChassisUnitInertiaYaw;

            if (invMass1 * maxRatio < invMass2)
            {
                float ratio = invMass1 / invMass2;
                ratio *= maxRatio;
                ((VelocityVector*)&out1->m_vec30)->mul4(ratio);
            }

            VelocityVector linVel;
            linVel.setSub4(motion->unk60, motion->unk50);
            linVel.mul4(motion->getInvDeltaTime());
            VelocityVector angVel;
            angVel.setMul4(motion->getInvDeltaTime(), motion->unkA0);

            out2->FUN_00d72030(*out1);
            wheelInfo->m_contactBody2 = out2;

            rotateDirection(out2->m_contactNormal, out1->m_rotation, angVel.q);
            *(AxleQuad*)&out2->m_vContactPoint = linVel.q;
        }

        ++i;
        ++wheelInfo;
        ++out1;
        ++out2;
    } while (i < reinterpret_cast<AxleDataView*>(m_data)->m_iWheelCount);
}

}

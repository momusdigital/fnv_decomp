// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleLinearCastWheelCollide.h"
struct LCHitObj
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_fHitDistance;
};
struct LCHit
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    LCHitObj* m_obj;
    int m_2c;
    int m_valid;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
};
struct LCWheelCollideStandIn
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
    virtual void v30();
    virtual int getNumHits(int);
    LCHitObj* FUN_00e36250(int iWheel, LCHit* pHits);
};
struct FUN_00e363a0_Wheel
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
};
struct FUN_00e363a0_StandIn : LCWheelCollideStandIn
{
    unsigned int FUN_00e363a0(unsigned char wheelIndex);
};
struct FUN_00c936a0_host
{
    void* FUN_00c936a0(void*);
};
struct COMBaseInterface : public FUN_00c936a0_host
{
};
struct FUN_00e36870_host
{
    void FUN_00e36870(COMBaseInterface*);
};
struct FUN_00e368a0_Class
{
    void FUN_00e368a0();
};
struct FUN_00c92c70_Class
{
    void FUN_00c92c70(void*);
};
struct FUN_00e368d0_Target
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
    void* m_2c;
};
struct FUN_00e368d0_Elem
{
    FUN_00e368d0_Target* m_00;
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
};
struct FUN_00e368d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    FUN_00e368d0_Elem* m_10;
    int m_14;

    void SetTargetArg(void* arg);
};
void __cdecl FUN_00e36900();
void __cdecl FUN_00e36aa0();
inline hkBaseObject::~hkBaseObject()
{}
struct FUN_00d1df70
{
    virtual void v00() throw();
    void removeReference() throw();
};
struct DummyBase1
{
    int a, b;
};
struct hkpPhantomOverlapListener
{
    int dummy;
};
struct FUN_00e360f0 : public DummyBase1, public hkpPhantomOverlapListener
{
    int d;
    ~FUN_00e360f0() throw();
};
class hkpPhantom : public FUN_00d1df70
{
  public:
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void FUN_00d07c80(hkpPhantomOverlapListener*) throw();
};
struct WheelState
{
    hkpPhantom* m_pPhantom;
    FUN_00d1df70* m_pCollisionShape;
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
struct HavokMemoryRouter
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void deallocate(void* p, int numBytes) throw();
};
struct HavokAllocatorContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HavokMemoryRouter* m_router;
};
extern "C" HavokAllocatorContext* __cdecl FUN_00c85750() throw();
struct WheelStatesArray
{
    WheelState* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    inline ~WheelStatesArray() throw()
    {
        HavokAllocatorContext* mem = FUN_00c85750();
        HavokMemoryRouter* router = mem->m_router;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            router->deallocate(this->m_data, (cap & 0x3fffffff) * sizeof(WheelState));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};
class FUN_00e36b80 : public hkpVehicleWheelCollide
{
  public:
    int m_uiWheelCount;
    WheelStatesArray m_kWheelStates;
    FUN_00e360f0 m_kRejectChassisListener;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;

    virtual ~FUN_00e36b80() throw();
};
struct LCWheelData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char unk20;
};
struct LCVehicleCtx
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    LCWheelData* unk1c;
};
__declspec(align(16)) struct LCWheelCastOut
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    unsigned int u20, u24, u28, u2c, u30, u34, u38, u3c;
    unsigned int u40, u44, u48, u4c, u50, u54, u58, u5c;
    unsigned int u60, u64, u68, u6c;
};
struct LCWheelResult
{
    unsigned int r00, r04, r08, r0c, r10, r14, r18, r1c;
    unsigned int r20, r24, r28, r2c, r30, r34, r38, r3c;
    unsigned int r40, r44, r48, r4c, r50, r54, r58, r5c;
};
class LCLinearCastCollide
{
  public:
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
    virtual void wheelUpdate(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelResult* results);
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual char* castQuery(char* found, LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelCastOut* out);
    virtual void applyHit(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelCastOut* out, LCWheelResult* results);
    virtual void noHit(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelResult* results);

    void UpdateAllWheels(int unkArg, LCVehicleCtx* vehicle, LCWheelResult* results);
};
template <class T> struct hkArrayE363
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct hkpWheelStateE363
{
    unsigned int unk00, unk04, unk08, unk0C;
};
class hkBaseObjectE363
{
  public:
    virtual ~hkBaseObjectE363() throw();
};
class hkReferencedObjectE363 : public hkBaseObjectE363
{
  public:
    virtual ~hkReferencedObjectE363() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpVehicleLinearCastWheelCollideE363 : public hkReferencedObjectE363
{
  public:
    virtual ~hkpVehicleLinearCastWheelCollideE363() throw();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual int getNumHits(unsigned char ucWheel) const;

    int GetTotalHits() const;

    unsigned char m_bWheelCollisionEnabled;
    unsigned char m_type;
    unsigned int unk0C;
    hkArrayE363<hkpWheelStateE363> m_kWheelStates;
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern const __m128 DAT_010c44d0;
struct hkVector4E366
{
    __m128 m_vComponents;

    hkVector4E366()
    {}
    hkVector4E366(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setNeg4(const hkVector4E366& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    void setXYZ(const hkVector4E366& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};
struct hkpVehicleSuspensionWheelParamsE366
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};
struct hkpVehicleSuspensionE366
{
    unsigned int unk00, unk04;
    hkpVehicleSuspensionWheelParamsE366* m_kWheelParams;
};
struct hkpVehicleWheelInfoE366
{
    hkVector4E366 m_vContactPoint[6];
    hkVector4E366 m_vContactPointVelocity;
    hkVector4E366 m_vContactNormal;
    hkVector4E366 m_vHardPointWs;
    hkVector4E366 m_spinAxisCs;
    hkVector4E366 m_vSuspensionDirectionWs;
    hkVector4E366 m_steeringOrientationCs[2];
    hkVector4E366 unkD0;
};
struct hkpVehicleInstanceE366
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30;
    hkpVehicleSuspensionE366* m_pSuspension;
    unsigned int unk38, unk3C, unk40, unk44;
    hkpVehicleWheelInfoE366* m_kWheelInfoArray;
};
struct hkContactPointE366
{
    hkVector4E366 m_vContactPosition;
    hkVector4E366 m_vSeparatingNormal;
};
struct CollisionDetectionWheelOutputE366
{
    hkContactPointE366 m_vContactPoint;
    float m_fSuspensionLength;
    unsigned int m_uiContactShapeKeys;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
};
struct hkpVehicleRayCastWheelCollideE366
{
    static void __stdcall RayCastWheelCollide(const hkpVehicleInstanceE366* pkVehicle, unsigned char ucWheelNum,
                                              CollisionDetectionWheelOutputE366& kCdInfo);
};
struct __declspec(align(16)) FUN_00e36900_V
{
    union
    {
        __m128 vec;
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00c7f690(void* ws, void* result);
    void FUN_00c7f640(void* ws, void* src);
};
class FUN_00e36900_Wrap : public hkpVehicleLinearCastWheelCollide
{
  public:
    void FUN_00e36900(int unused, unsigned char wheelIndex, FUN_00e36900_V* result);
};
__declspec(align(16)) struct hkAabb_36950
{
    float m_minX;
    float m_minY;
    float m_minZ;
    float m_maxX;
    float m_maxY;
    float m_maxZ;
};
struct FUN_00cf24a0_host_36950
{
    void FUN_00cf24a0(hkAabb_36950*);
};
struct FUN_00e36950_WheelState_36950
{
    FUN_00cf24a0_host_36950* m_object;
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
};
struct FUN_00e36950_host_36950
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e36950_WheelState_36950* unk10;
    int unk14;

    void UpdateWheelAabb(unsigned char wheelIndex);
    void FUN_00e367d0(unsigned char wheelIndex, unsigned char stateIndex);
    void FUN_00e36700(unsigned char wheelIndex, unsigned char stateIndex, hkAabb_36950* aabb);
};
extern hkReal DAT_0104da48;
extern hkReal DAT_0104da4c;
extern hkUint8 DAT_010c476c;
struct __declspec(align(16)) LCAVec4
{
    hkReal v[4];
};
struct __declspec(align(16)) hkpVehicleLinearCastWheelCollideWheelState
{
    void* m_pCollisionShape;
    hkUint32 m_04;
    hkUint32 m_08;
    hkUint32 m_0c;
    LCAVec4 m_pos;
    LCAVec4 m_20;
    LCAVec4 m_30;
    LCAVec4 m_40;
    LCAVec4 m_vContactPosition;
};
struct __declspec(align(16)) LCCastInput
{
    LCAVec4 m_vTo;
    volatile hkReal m_10;
    volatile hkReal m_14;
    hkUint32 m_18;
    hkUint32 m_1c;
    const hkUint8* m_20;
    hkReal m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkReal m_4c;
    hkInt32 m_50;
    hkUint32 m_54;
    hkUint32 m_58;
    hkUint32 m_5c;
    hkUint32 m_60;
    hkUint32 m_64;
    hkUint32 m_68;
    hkUint32 m_6c;
    hkUint32 m_70;
    hkUint32 m_74;
    hkUint32 m_78;
    hkUint32 m_7c;
    hkUint32 m_80;
    hkUint32 m_84;
    hkUint32 m_88;
    hkUint32 m_8c;
    hkUint32 m_90;
    hkUint32 m_94;
    hkUint32 m_98;
    hkUint32 m_9c;
};
struct FUN_00e369d0_Result
{
    void FUN_00cd2d80(hkUint32 a, const void* b, hkInt32 c);
    hkUint32 m_00;
    hkUint32 m_04;
    hkUint32 m_08;
    hkUint32 m_0c;
    hkUint32 m_10;
    hkUint32 m_14;
    hkUint32 m_18;
    hkUint32 m_uiCollisionFilterData;
    hkUint32 m_20;
    hkUint32 m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkUint32 m_4c;
};
struct FUN_00cf2880_Shape
{
    hkUint32 linearCast(FUN_00e369d0_Result* result, LCCastInput* input, const hkUint8** filter, hkInt32 maskAll);
};
struct FUN_006212c0_Context
{
    void FUN_006212c0(void* data);
};
struct FUN_00e369d0_Class : public hkpVehicleLinearCastWheelCollide
{
  public:
    void CastWheel(int hitOut, hkUint32 b, hkUint8 wheelIndex, int context);
};
class hkMemoryAllocatorE36;
struct hkMemoryRouterE36
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorE36* m_pTemp;
    hkMemoryAllocatorE36* m_pStreamAllocator;
    hkMemoryAllocatorE36& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterE36 {
extern "C" hkMemoryRouterE36& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorE36& alloc, void* array, int numElem, int sizeElem) throw();
class hkReferencedObjectE36
{
  public:
    void FUN_00c90510() throw();
};
template <class T> class hkArrayE36
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(hkMemoryAllocatorE36& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newCap = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterE36::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
struct WheelStateE36
{
    int unk00;
    hkReferencedObjectE36* m_pPhantom;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
};
struct hkpVehicleDataE36
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned char m_iWheelCount;
};
struct hkpVehicleInstanceE36
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    hkpVehicleDataE36* m_data;
};
class hkpVehicleRayCastWheelCollideE36
{
  public:
    int unk00, unk04, unk08, unk0C;
    hkArrayE36<WheelStateE36> m_kWheelStates;

    void SetWheelPhantoms(const hkpVehicleInstanceE36* vehicle, const hkArrayE36<hkReferencedObjectE36*>& phantoms);
};
struct hkAllocatorE36C
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterE36C
{
    void* m_apvUnk00[4];
    hkAllocatorE36C* m_pkHeap;
    hkAllocatorE36C& heap()
    {
        return *m_pkHeap;
    }
};
namespace fnvc_adapt {
extern "C" hkMemoryRouterE36C& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkAllocatorE36C& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <typename T> struct hkArrayE36C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorE36C& kAlloc, int n)
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
        GrowArrayCapacity(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
class hkReferencedObjectE36C
{
  public:
    virtual ~hkReferencedObjectE36C() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpPhantomOverlapListenerE36C
{
  public:
    virtual ~hkpPhantomOverlapListenerE36C() throw();
};
class hkpCollidableE36C;
class hkpRigidBodyE36C
{
  public:
    char m_acUnk00[0x10];
    char m_kCollidable[0x10];

    const hkpCollidableE36C* getCollidable() const
    {
        return (const hkpCollidableE36C*)m_kCollidable;
    }
};
struct __declspec(align(16)) hkVector4E36C
{
    float x, y, z, w;
};
struct hkAabbE36C
{
    hkVector4E36C m_kMinimumCorner;
    hkVector4E36C m_kMaximumCorner;
};
class hkpPhantomE36C : public hkReferencedObjectE36C
{
  public:
    void FUN_00d07de0(hkpPhantomOverlapListenerE36C* pkListener) throw();
};
class FUN_00cf2cb0 : public hkpPhantomE36C
{
  public:
    static __forceinline void* operator new(unsigned int, void* pvMem) throw()
    {
        return pvMem;
    }
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkReferencedObjectE36C* p =
            (hkReferencedObjectE36C*)fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf2cb0(const hkAabbE36C& kAabb, hkUint32 uiCollisionFilterInfo) throw();

    char m_acUnk08[0xd8];
};
class hkpShapeE36C : public hkReferencedObjectE36C
{
};
class hkpRejectChassisListenerE36C : public hkReferencedObjectE36C, public hkpPhantomOverlapListenerE36C
{
  public:
    const hkpCollidableE36C* m_pChassisCollidable;
};
struct hkpVehicleLinearCastWheelCollideWheelStateE36C
{
    hkpPhantomE36C* m_pPhantom;
    hkpShapeE36C* m_pCollisionShape;
    char m_acUnk08[0x58];
};
struct hkpVehicleDataWheelComponentParamsE36C
{
    hkReal m_fSphereRadius;
    hkReal m_fViscosityFriction;
    hkReal m_fMaxFriction;
    hkReal m_fSlipAngle;
    hkReal m_fSlipVelocity;
    hkReal m_fMaxContactBodyAcceleration;
    hkReal m_fForceFeedbackMultiplier;
    hkReal m_fMaxFrictionForce;
    hkReal m_fFrictionEqualizer;
    hkInt8 m_iAxle;
};
struct hkpVehicleDataE36C
{
    char m_acUnk00[0x20];
    hkUint8 m_iWheelCount;
    char m_acUnk21[0x6b];
    hkArrayE36C<hkpVehicleDataWheelComponentParamsE36C> m_kWheelParams;
};
struct hkpVehicleInstanceE36C
{
    char m_acUnk00[0x18];
    hkpRigidBodyE36C* m_pChassisCollidable;
    hkpVehicleDataE36C* m_data;

    hkpRigidBodyE36C* getChassis() const
    {
        return m_pChassisCollidable;
    }
};
class hkpVehicleLinearCastWheelCollideE36C : public hkReferencedObjectE36C
{
  public:
    hkBool m_bWheelCollisionEnabled;
    hkUint8 m_type;
    hkUint32 m_uiWheelCount;
    hkArrayE36C<hkpVehicleLinearCastWheelCollideWheelStateE36C> m_kWheelStates;
    hkpRejectChassisListenerE36C m_kRejectChassisListener;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fMaxExtraPenetrationAgainstFixed;

    hkpShapeE36C* FUN_00e36120(hkReal m_fGlyphWidthInPixels, hkReal fRadius) throw();
    void FUN_00e36700(const hkpVehicleInstanceE36C* pkVehicle, hkUint8 ucWheelNum, hkAabbE36C& kAabbOut) throw();
    void FUN_00e367d0(const hkpVehicleInstanceE36C* pkVehicle, hkUint8 ucWheelNum) throw();
    void InitializeWheelCollisions(const hkpVehicleInstanceE36C* pkVehicle) throw();
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);
struct FUN_00ca0c40_host
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
    float m_fSlipAngle;  // at 0x90
    void FUN_00ca0c40(const hkVector4& point, hkVector4& velOut);
};
struct CollidableStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;  // at 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_cBroadPhaseType;  // at 0x18
    char unk19;
    char unk1a;
    char unk1b;
};
struct HitStandIn
{
    __m128 m_vContactPoint;
    union
    {
        __m128 m_contactNormal;
        struct
        {
            float m_nx;
            float m_ny;
            float m_nz;
            float m_fHitDistance;
        };
    };
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
    CollidableStandIn* m_kCollidable;  // at 0x48
    unsigned int m_uiCollisionShapeKey;           // at 0x4c
};
struct WheelCollideOutputStandIn
{
    __m128 m_vContactPoint;
    __m128 m_contactNormal;
    float m_fSlipAngle;
    FUN_00ca0c40_host* m_pUserData;
    unsigned int m_uiCollisionShapeKey;
    int m_hardpointIndex;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    float m_suspensionLength;
    float m_suspensionClosingVelocity;
    float m_invSuspensionClosingVelocity;
};
struct WheelSuspensionInfoStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_fRestLength;  // at 0x20
    int unk24;
    int unk28;
    int unk2c;  // sizeof = 0x30
};
struct SuspensionStandIn
{
    int unk00;
    int unk04;
    WheelSuspensionInfoStandIn* m_wheelData;  // at 0x08
};
struct WheelStateStandIn
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
    __m128 m_dir;  // at 0x80
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
    int unkdc;  // sizeof = 0xe0
};
struct VehicleDataStandIn
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
    float m_pFreeList;  // at 0x84
};
struct VehicleInstanceStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00ca0c40_host* m_pChassisCollidable;  // at 0x18
    VehicleDataStandIn* m_data;               // at 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    SuspensionStandIn* m_pSuspension;  // at 0x34
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    WheelStateStandIn* m_kWheelStates;  // at 0x48
};
extern "C" void _ReadWriteBarrier(void);
inline float dot3(__m128 a, __m128 b)
{
    __m128 mul = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 sum = _mm_add_ss(y, mul);
    sum = _mm_add_ss(z, sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}
void __stdcall FUN_00e36510(VehicleInstanceStandIn* vehicle, unsigned char wheelIndex, HitStandIn* hit,
                            WheelCollideOutputStandIn* out);

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);

namespace WheelStateUpdate {

struct __declspec(align(16)) LcQuat
{
    float x, y, z, w;
    void FUN_00c66320(const void* a, const void* b);
};

struct LcRotation
{
    __m128 m_kColumn0, m_kColumn1, m_kColumn2;
    void FUN_00cb2d90(void* q);
};

struct LcTransform
{
    LcRotation m_rotation;
    __m128 m_vTranslation;
};

struct LcWheelInfo
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
    __m128 m_vContactPointVelocity;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    __m128 m_vHardPointWs;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    LcQuat m_steeringOrientation;
    __m128 unkC0;
    __m128 unkD0;
};

struct LcWheelState
{
    void* m_pPhantom;
    void* m_pCollisionShape;
    int unk08;
    int unk0C;
    LcTransform m_kMotionTransform;
    __m128 m_vTo;
};

struct LcSuspensionWheel
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fRestLength;
    int unk24;
    int unk28;
    int unk2C;
};

struct LcSuspension
{
    int unk00;
    int unk04;
    LcSuspensionWheel* m_kWheelParams;
};

struct LcChassis
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    LcQuat m_rotation;
};

struct LcVehicle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LcChassis* m_pChassisCollidable;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    LcSuspension* m_pSuspension;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    LcWheelInfo* m_kWheelInfoArray;
};

struct WheelCollide
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LcWheelState* m_kWheelStates;
    void FUN_00e367d0(LcVehicle* vehicle, unsigned char wheelNum);
};

static inline __m128 splat(const float& r)
{
    __m128 q = _mm_load_ss((const float*)&r);
    return _mm_shuffle_ps(q, q, 0);
}

// @fnv 0x00e367d0
void WheelCollide::FUN_00e367d0(LcVehicle* vehicle, unsigned char wheelNum)
{
    LcWheelInfo& wheelInfo = vehicle->m_kWheelInfoArray[wheelNum];
    LcWheelState& wheelState = m_kWheelStates[wheelNum];

    LcQuat rotation;
    rotation.FUN_00c66320(&vehicle->m_pChassisCollidable->m_rotation, &wheelInfo.m_steeringOrientation);

    LcTransform& transform = wheelState.m_kMotionTransform;
    transform.m_rotation.FUN_00cb2d90(&rotation);
    transform.m_vTranslation = wheelInfo.m_vContactPointVelocity;

    __m128 length = splat(vehicle->m_pSuspension->m_kWheelParams[wheelNum].m_fRestLength);
    wheelState.m_vTo = _mm_add_ps(_mm_mul_ps(length, wheelInfo.m_vHardPointWs), wheelInfo.m_vContactPointVelocity);
}

}

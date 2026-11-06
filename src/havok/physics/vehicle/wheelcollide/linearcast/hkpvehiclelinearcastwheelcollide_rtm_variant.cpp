// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


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
class hkBaseObjE36B
{
  public:
    virtual ~hkBaseObjE36B() throw();
};
class hkRefObjE36B : public hkBaseObjE36B
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjE36B() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjE36B() throw();
};
class hkIfaceE36B
{
  public:
    hkIfaceE36B() throw()
    {}
    virtual ~hkIfaceE36B() throw();
};
template <class T> class hkArrayE36B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE36B() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class hkToleranceE36B : public hkRefObjE36B, public hkIfaceE36B
{
  public:
    int unk0C;
    float m_tolerance0;
    float m_tolerance1;

    hkToleranceE36B() throw()
    {}
    virtual ~hkToleranceE36B() throw();
};
class FUN_00e36b20 : public hkRefObjE36B
{
  public:
    unsigned char m_08;
    unsigned char m_09;
    int unk0C;
    hkArrayE36B<void*> m_ppData;
    hkToleranceE36B m_fScalar;

    FUN_00e36b20() throw();
    virtual ~FUN_00e36b20() throw();
};
extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
extern const float g_fZeroE36120;
extern const __m128 g_kSignMaskE36120;
struct __declspec(align(16)) Vector4E36120
{
    float x;
    float y;
    float z;
    float w;
    __m128& Vector4f()
    {
        return *reinterpret_cast<__m128*>(this);
    }
    const __m128& Vector4f() const
    {
        return *reinterpret_cast<const __m128*>(this);
    }
    void set(float fX, float fY, float fZ, float fW)
    {
        Vector4f() = _mm_setr_ps(fX, fY, fZ, fW);
    }
    void setNeg4(const Vector4E36120& v)
    {
        Vector4f() = _mm_xor_ps(g_kSignMaskE36120, v.Vector4f());
    }
};
struct MemoryE36120
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct ContextE36120
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemoryE36120* m_pkMemory;
};
ContextE36120* GetContextE36120();
struct ShapeE36120
{
    static void* operator new(unsigned int nbytes) throw()
    {
        ContextE36120* pkContext = GetContextE36120();
        ShapeE36120* pkShape = static_cast<ShapeE36120*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSize;
    unsigned short m_usRefCount;
};
struct CapsuleE36120 : public ShapeE36120
{
    CapsuleE36120(const Vector4E36120& kA, const Vector4E36120& kB, float fRadius, float fExtra) throw();
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
ShapeE36120* __stdcall FUN_00e36120(float m_fGlyphExtent, float fRadius);
inline void* operator new(unsigned int, void* pvMem) throw()
{
    return pvMem;
}
struct __declspec(align(16)) hkVector4E363
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
    void operator=(const hkVector4E363& v)
    {
        getQuad() = v.getQuad();
    }
};
struct hkTransformE363
{
    hkVector4E363 m_kColumn0;
    hkVector4E363 m_kColumn1;
    hkVector4E363 m_kColumn2;
    hkVector4E363 m_vTranslation;
    const hkVector4E363& getTranslation() const
    {
        return m_vTranslation;
    }
};
struct hkpShapeE363;
struct hkpCollidableE363;
class hkpAabbPhantomE363 : public hkpPhantom
{
  public:
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void V9() throw();
    virtual void RemoveOverlappingBody() throw();
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
    hkArrayE363<hkpCollidableE363*> m_ppOverlappingCollidables;
};
struct FUN_00d01a60
{
    int m_minX;
    int m_minY;
    int m_minZ;
    unsigned char m_expansionMinX;
    unsigned char m_expansionMinY;
    unsigned char m_expansionMinZ;
    unsigned char m_ucExpansionShift;
    int m_maxX;
    int m_maxY;
    int m_maxZ;
    unsigned char m_expansionMaxX;
    unsigned char m_expansionMaxY;
    unsigned char m_expansionMaxZ;
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;

    FUN_00d01a60() throw();
};
struct hkpTypedBroadPhaseHandleE363
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;

    __forceinline hkpTypedBroadPhaseHandleE363(int iType)
    {
        m_iOwnerObjectOffset = 0;
        m_type = (char)iType;
        m_uiCollisionFilterData = 0;
        m_ucObjectQualityType = (char)0xff;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (char)((unsigned long)pvOwner - (unsigned long)this);
    }
};
struct hkpCollidableE363
{
    const hkpShapeE363* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCollidableE363* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleE363 m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;

    __forceinline hkpCollidableE363(const hkpShapeE363* pkShape, const hkTransformE363* pkTransform, int iType = 0)
        : m_pCollisionShape(pkShape), m_uiCollisionShapeKey(0xffffffff), m_pMotionState(pkTransform), m_parent(0),
          m_iOwnerOffset(0), m_kBroadPhaseHandle(iType)
    {
        m_fAllowedPenetrationDepth = -1.0f;
        m_kBroadPhaseHandle.SetOwnerPointer(this);
        m_uiForceCollideOntoPpu = 0;
        m_uiShapeSizeOnSpu = 0;
    }
};
struct hkpRootCdPointE363
{
    hkVector4E363 m_vContactPosition;
    hkVector4E363 m_vHitNormal;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};
struct hkpPairLinearCastCommandE363
{
    hkVector4E363 m_vFrom;
    hkVector4E363 m_vTo;
    const hkpCollidableE363* m_pCollidableA;
    const hkpCollidableE363* m_pCollidableB;
    hkpRootCdPointE363* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    hkpRootCdPointE363* m_pStartPointResultBuffer;
    int m_iStartPointResultCount;
    int m_iStartPointResultCapacity;
};
struct hkpVehicleLinearCastWheelCollideWheelStateE363
{
    hkpAabbPhantomE363* m_pPhantom;
    const hkpShapeE363* m_pCollisionShape;
    int m_08;
    int m_0c;
    hkTransformE363 m_kMotionTransform;
    hkVector4E363 m_vTo;
};
struct hkpVehicleInstanceE363;
struct hkpCollisionFilterE363;
class LinearCastCommandBuilder : public hkpVehicleLinearCastWheelCollideE363
{
  public:
    int FUN_00e363d0(const hkpVehicleInstanceE363* pkVehicle, const hkpCollisionFilterE363* pkFilter,
                     hkpCollidableE363* pkCollidableStorage, hkpPairLinearCastCommandE363* pkCommandStorage,
                     hkpRootCdPointE363* pkOutputStorage) const throw();
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elementSize);
class WheelPhantomCollector : public hkpVehicleLinearCastWheelCollideE36C
{
  public:
    void FUN_00e36ab0(hkArray<hkpPhantomE36C*>* output);
};

void __cdecl FUN_00d26230(int transform, int extents, int center, float tolerance, int output);

struct E367_Vehicle : hkpVehicleInstanceE36C
{
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    hkpVehicleSuspensionE366* m_pSuspension;
};

class E367_Class : public hkpVehicleLinearCastWheelCollide
{
  public:
    void __thiscall FUN_00e36700(const E367_Vehicle* vehicle, unsigned char wheelIndex, hkAabbE36C& output);
};

// @fnv 0x00e36700
void __thiscall E367_Class::FUN_00e36700(const E367_Vehicle* vehicle, unsigned char wheelIndex, hkAabbE36C& output)
{
    int index = wheelIndex;
    const hkpVehicleDataWheelComponentParamsE36C* wheel = vehicle->m_data->m_kWheelParams.m_data + index;
    const hkpVehicleSuspensionWheelParamsE366* suspension = vehicle->m_pSuspension->m_kWheelParams + index;

    double zero = 0.0;
    float halfHeight = static_cast<float>((suspension->m_fRestLength + wheel->m_fSphereRadius) * 0.5);
    float halfWidth = static_cast<float>(0.5 * wheel->m_fMaxFriction);
    Vector4E36120 extents;
    extents.set(wheel->m_fSphereRadius, halfHeight, halfWidth, 0.0f);
    Vector4E36120 center;
    center.set(0.0f, -halfHeight, 0.0f, 0.0f);

    int transform = reinterpret_cast<int>(&m_kWheelStates.m_data[index].m_pos);
    FUN_00d26230(transform, reinterpret_cast<int>(&extents), reinterpret_cast<int>(&center), zero,
                 reinterpret_cast<int>(&output));
}

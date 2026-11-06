// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleRayCastWheelCollide.h"
struct FUN_00e41f10
{
    void SetUserInfo(int a);
};
struct FUN_00c936a0_host
{
    void* FUN_00c936a0(void* phantom);
};
struct FUN_00e41ef0_self
{
    void* addToWorld(void* world);
};
struct __declspec(align(16)) hkAabb
{
    float m_data[8];
};
struct FUN_00cf24a0_host
{
    void FUN_00cf24a0(hkAabb* aabb);
};
struct FUN_00e41e70_host
{
    virtual void FUN_00e41000() = 0;
    virtual void FUN_00e41004() = 0;
    virtual void FUN_00e41008() = 0;
    virtual void FUN_00e4100c() = 0;
    virtual void FUN_00e41010() = 0;
    virtual void FUN_00e41014() = 0;
    virtual void FUN_00e41018() = 0;
    virtual void FUN_00e4101c() = 0;
    virtual void FUN_00e41020() = 0;
    virtual void FUN_00e41024() = 0;
    virtual void FUN_00e41028() = 0;
    virtual void FUN_00e4102c() = 0;
    virtual void FUN_00e41030() = 0;
    virtual void FUN_00e41034(unsigned int shape, hkAabb* aabb) = 0;

    void* m_reserved[3];
    FUN_00cf24a0_host* m_pPhantom;

    void updateBeforeCollisionDetection(unsigned int shape);
};
struct FUN_00c92c70_host
{
    void FUN_00c92c70(void* phantom);
};
struct FUN_00e41f00_self
{
    void removeFromWorld();
};
extern int DAT_010e5ae4;
extern int DAT_0102e388;
struct FUN_00e41fc0_phantom
{
    void __thiscall FUN_00d07c80(void* arg);
    void __thiscall FUN_00c905b0();
};
struct FUN_00e41fc0_listener
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    void __thiscall FUN_00e360f0();
};
class FUN_00e41fc0_host
{
  public:
    // Empty virtual destructor for the host class.
// @fnv 0x00e41fc0
    virtual ~FUN_00e41fc0_host()
    {}
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e41fc0_phantom* unk10;
    FUN_00e41fc0_listener unk14;

    void FUN_00e41fc0();
};
void FUN_00e41fc0_host::FUN_00e41fc0()
{
    FUN_00e41fc0_phantom* phantom = this->unk10;
    *(int**)this = &DAT_010e5ae4;

    if (phantom)
    {
        if (this->unk14.unk0C)
        {
            void* listener = (char*)this + 0x14;
            void* arg;

            if (listener)
            {
                arg = (char*)this + 0x1c;
            }
            else
            {
                arg = 0;
            }

            phantom->FUN_00d07c80(arg);
        }

        this->unk10->FUN_00c905b0();
    }

    this->unk14.FUN_00e360f0();
    *(int**)this = &DAT_0102e388;
}
class hkMemoryAllocatorXe42610;
struct hkMemoryRouterXe42610
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe42610* m_pStreamAllocator;
    hkMemoryAllocatorXe42610& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXe42610& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <class T> __forceinline void constructWithCopyXe42610(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> class hkArrayXe42610
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorXe42610& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyXe42610(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
class hkObjXe42610
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_uiFilterValue;

    void AppendPointer(hkArrayXe42610<void*>& kArray);
};
struct S00e41f30_arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_00c85750_vt
{
    virtual void vf00();
    virtual void* vf04(unsigned int size);
};
struct FUN_00c85750_obj
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
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

    void* __thiscall FUN_00cf2cb0(void* aabb, unsigned int filter);
    void __thiscall FUN_00d07de0(void* value);
};
struct FUN_00c85750_host
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c85750_vt* unk10;
};
struct S00e41f30_listener
{
    int unk00;
    int unk04;
    void* unk08;
};
struct S00e41f30_impl
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34(unsigned int shape, hkAabb* aabb);

    int unk04;
    int unk08;
    unsigned int m_uiWheelCount;
    hkpAabbPhantom* m_pPhantom;
    S00e41f30_listener m_kChassisRejectionListener;
    int unk20;

    void __thiscall CreateWheelPhantom(S00e41f30_arg* arg);
};
namespace fnvc_adapt {
FUN_00c85750_host* __cdecl FUN_00c85750();
}
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern const __m128 DAT_010c44d0;
struct hkVector4E423
{
    __m128 m_vComponents;

    hkVector4E423()
    {}
    hkVector4E423(const hkVector4E423& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4E423& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setNeg4(const hkVector4E423& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    void setXYZ(const hkVector4E423& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};
struct hkpVehicleSuspensionWheelParamsE423
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};
struct hkpVehicleSuspensionE423
{
    unsigned int unk00, unk04;
    hkpVehicleSuspensionWheelParamsE423* m_kWheelParams;
};
struct hkpVehicleWheelInfoE423
{
    hkVector4E423 m_vContactPoint[6];
    hkVector4E423 m_vContactPointVelocity;
    hkVector4E423 m_vContactNormal;
    hkVector4E423 m_vHardPointWs;
    hkVector4E423 m_spinAxisCs;
    hkVector4E423 m_vSuspensionDirectionWs;
    hkVector4E423 m_steeringOrientationCs[2];
    hkVector4E423 unkD0;
};
struct hkpVehicleInstanceE423
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30;
    hkpVehicleSuspensionE423* m_pSuspension;
    unsigned int unk38, unk3C, unk40, unk44;
    hkpVehicleWheelInfoE423* m_kWheelInfoArray;
};
struct hkContactPointE423
{
    hkVector4E423 m_vContactPosition;
    hkVector4E423 m_vSeparatingNormal;
};
struct CollisionDetectionWheelOutputE423
{
    hkContactPointE423 m_vContactPoint;
    float m_fSuspensionLength;
    unsigned int m_uiContactShapeKeys;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
};
struct hkpVehicleRayCastWheelCollideE423
{
    static void __stdcall RayCastWheelCollide(const hkpVehicleInstanceE423* pkVehicle, unsigned char ucWheelNum,
                                              CollisionDetectionWheelOutputE423& kCdInfo);
};
class hkReferencedObjectE42
{
  public:
    hkReferencedObjectE42()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectE42()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpPhantomOverlapListenerE42
{
  public:
    virtual ~hkpPhantomOverlapListenerE42()
    {}
    virtual void PhantomOverlapCallback(void* event) = 0;
};
class hkpRejectChassisListenerE42 : public hkReferencedObjectE42, public hkpPhantomOverlapListenerE42
{
  public:
    hkpRejectChassisListenerE42()
    {}
    virtual ~hkpRejectChassisListenerE42();
    virtual void PhantomOverlapCallback(void* event);
    void* m_pChassisCollidable;
};
class hkpVehicleWheelCollideE42 : public hkReferencedObjectE42
{
  public:
    virtual ~hkpVehicleWheelCollideE42()
    {}
    bool m_bWheelCollisionEnabled;
    unsigned char m_type;
};
class FUN_00e42550 : public hkpVehicleWheelCollideE42
{
  public:
    FUN_00e42550();
    virtual ~FUN_00e42550();
    unsigned int m_uiWheelCount;
    void* m_pPhantom;
    hkpRejectChassisListenerE42 m_kRejectChassisListener;
};
class hkpAabbPhantom
{
  public:
    void __thiscall FUN_00cf26b0(void* input, void* output);
};
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
struct __declspec(align(16)) FUN_00e41eb0_Input
{
    Vec4 m_vFrom;
    Vec4 m_vTo;
    unsigned char m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};
struct FUN_00e41eb0_Host : public hkpVehicleRayCastWheelCollide
{
    void __thiscall castSingleWheel(const void* source, void* output);
};
struct hkpVehicleDataE420
{
    char unk00[0x20];
    unsigned char m_iWheelCount;
};
struct hkpWheelInfoE420
{
    int unk[0x38];
};
struct hkpVehicleInstanceE420
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    hkpVehicleDataE420* m_data;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    hkpWheelInfoE420* m_kWheelInfoArray;
};
struct CollisionDetectionWheelOutputE420
{
    int unk[0x18];
};
struct __declspec(align(16)) hkpShapeRayCastOutputE420
{
    float m_vHitNormal[4];
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_auiShapeKeys[2];
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44, unk48, unk4c;

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = -1;
        m_uiShapeKeyIndex = 0;
    }
};
struct hkpWorldRayCastOutputE420 : public hkpShapeRayCastOutputE420
{
    const void* m_pRootCollidable;

    hkpWorldRayCastOutputE420()
    {
        reset();
    }
    void reset()
    {
        hkpShapeRayCastOutputE420::reset();
        m_pRootCollidable = 0;
    }
    bool DidHit() const
    {
        return m_pRootCollidable != 0;
    }
};
struct S00e420c0_Self
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void InitializeWheelCollisionOutput(const hkpVehicleInstanceE420* vehicle, unsigned char wheelIndex,
                                                CollisionDetectionWheelOutputE420& cdInfo);
    virtual void vf30();
    virtual void vf34();
    virtual void CastWheelRay(const hkpWheelInfoE420& wheelInfo, hkpWorldRayCastOutputE420& output);
    virtual void ProcessWheelRayCastResult(const hkpVehicleInstanceE420* vehicle, unsigned char wheelIndex,
                                           const hkpWorldRayCastOutputE420& output,
                                           CollisionDetectionWheelOutputE420& cdInfo);
    virtual void FinalizeWheelCollisionOutput(const hkpVehicleInstanceE420* vehicle, unsigned char wheelIndex,
                                              CollisionDetectionWheelOutputE420& cdInfo);

    void collideWheels(float deltaTime, const hkpVehicleInstanceE420* vehicle,
                      CollisionDetectionWheelOutputE420* cdInfoOut);
};
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
struct FUN_00e42010_counts
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    char unk20;
};
struct __declspec(align(16)) FUN_00e42010_item
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    hkAabb m_kBounds;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAc;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBc;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCc;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDc;
};
struct FUN_00e42010_self
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    FUN_00e42010_counts* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    FUN_00e42010_item* unk48;
};
void __stdcall calcWheelsAABB(FUN_00e42010_self* self, hkAabb* aabb);
struct S00e42460_Vec4
{
    __m128 m_vComponents;
};
class hkpCollidable;
class hkpCollidableCollidableFilter
{
  public:
    virtual ~hkpCollidableCollidableFilter();
};
class hkpShapeCollectionFilter
{
  public:
    virtual ~hkpShapeCollectionFilter();
};
class hkpRayShapeCollectionFilter
{
  public:
    virtual ~hkpRayShapeCollectionFilter();
};
class hkpRayCollidableFilter
{
  public:
    virtual ~hkpRayCollidableFilter();
};
class hkpCollisionFilter : public hkReferencedObject,
                           public hkpCollidableCollidableFilter,
                           public hkpShapeCollectionFilter,
                           public hkpRayShapeCollectionFilter,
                           public hkpRayCollidableFilter
{
  public:
    hkUint32 m_prepad0;
    hkUint32 m_prepad1;
    hkUint32 m_type;
};
class hkpAabbPhantomQ : public hkReferencedObject
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void RemoveOverlappingBody();

    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkArray<hkpCollidable*> m_ppOverlappingCollidables;
};
struct S00e42460_VehicleData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkInt8 m_iWheelCount;
};
struct S00e42460_WheelInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    S00e42460_Vec4 m_vContactPointVelocity;
    S00e42460_Vec4 m_vContactNormal;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
};
struct S00e42460_VehicleInstance
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    S00e42460_VehicleData* m_data;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    hkArray<S00e42460_WheelInfo> m_kWheelInfoArray;
};
struct S00e42460_RayInput
{
    S00e42460_Vec4 m_vFrom;
    S00e42460_Vec4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const hkpRayShapeCollectionFilter* m_pRayShapeCollectionFilter;
    hkUlong m_ulUserData;
    int unk2c;
};
struct S00e42460_WorldRayCastOutput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
};
struct S00e42460_RayCastCommand
{
    S00e42460_RayInput m_kRayCastQuery;
    hkUint32 m_uiCollisionFilterInfo;
    hkInt32 m_iCommandParameter;
    hkpCollidable* const* m_kCollidables;
    int m_iCollidableCount;
    S00e42460_WorldRayCastOutput* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    hkBool m_bResultFlag;
};
class S00e42460_RayCastWheelCollide : public hkpVehicleRayCastWheelCollide
{
  public:
    int buildRayCastCommands(const S00e42460_VehicleInstance* vehicle, const hkpCollisionFilter* collisionFilter,
                     hkInt32 filterSize, S00e42460_RayCastCommand* commandStorage,
                     S00e42460_WorldRayCastOutput* outputStorage) const;
};

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_load_ps(float const*);
    __m128 _mm_load_ss(float const*);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ps(float*, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
}
struct Tab34
{
    int p00;
    int p04;
    float* f08;
};
struct VSub
{
    int p00;
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
    int p6c;
    int p70;
    int p74;
    int p78;
    int p7c;
    int p80;
    float f84;
    int p88;
    float* f8c;
};
struct VecWork
{
    __m128 m_vComponents;
    VecWork()
    {}
    VecWork(const VecWork& b)
    {
        m_vComponents = b.m_vComponents;
    }
    void operator=(const VecWork& b)
    {
        m_vComponents = b.m_vComponents;
    }
    void sub(const VecWork& a, const VecWork& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void cross(const VecWork& a, const VecWork& b)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
    }
    void add(const VecWork& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, b.m_vComponents);
    }
};
struct CenterTrack
{
    VecWork center0, center1, orient0, orient1, localCenter;
};
struct MotionStateData
{
    VecWork transform0, transform1, transform2, transform3;
    CenterTrack track;
    VecWork unk90, unkA0, unkB0;
    __forceinline const CenterTrack& trackData() const
    {
        return track;
    }
};
struct MotionData
{
    VecWork unk00;
    MotionStateData state;
    VecWork linearVelocity, angularVelocity;
    __forceinline const VecWork& worldCenter() const
    {
        return state.trackData().center1;
    }
    __forceinline const MotionStateData* stateData() const
    {
        return &state;
    }
};
struct IntegerTriple
{
    __m128 unk00, unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    float friction;
    float unk94, unk98, unk9C;
    __m128 unkA0, unkB0, unkC0, unkD0;
    MotionData motion;
};
struct VObj
{
    int p00;
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    IntegerTriple* f18;
    VSub* f1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    Tab34* f34;
    int p38;
    int p3c;
    int p40;
    int p44;
    hkpVehicleWheelInfoE423* f48;
};
struct Node50
{
    int p00;
    int p04;
    int p08;
    int p0c;
    signed char c10;
    char p11;
    char p12;
    char p13;
    int p14;
    char c18;
};
struct Src
{
    __m128 v0;
    float f10;
    float f14;
    float f18;
    float f1c;
    unsigned int shapeKeys[8];
    int p40;
    int p44;
    int p48;
    int p4c;
    Node50* f50;
};
struct Dst
{
    __m128 v0;
    union
    {
        __m128 v1;
        struct
        {
            float normalX, normalY, normalZ, distance;
        };
    };
    float f20;
    IntegerTriple* f24;
    unsigned int shapeKeys[8];
    float f48;
    float f4c;
    float f50;
};

__forceinline void CrossP(__m128& out, const __m128& angular, const __m128& offset)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(angular, angular, 0xC9), _mm_shuffle_ps(offset, offset, 0xD2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(angular, angular, 0xD2), _mm_shuffle_ps(offset, offset, 0xC9));
    out = _mm_sub_ps(first, second);
}
__forceinline void PointVelocity(const MotionData& motion, const VecWork& point, VecWork& out)
{
    VecWork offset;
    offset.sub(point, motion.worldCenter());
    const VecWork& angular = motion.angularVelocity;
    out.cross(angular, offset);
    out.add(motion.linearVelocity);
}
// @fnv 0x00e42190
void __stdcall getCollisionOutputFromCastResult(VObj* a, unsigned char idx, Src* src, Dst* dst)
{
    float* table = a->f34->f08;
    float slotA = table[idx * 12 + 8];
    hkpVehicleWheelInfoE423* E2 = a->f48 + idx;

    __m128 srcV = _mm_load_ps((float*)&src->v0);
    __m128 oldV = _mm_load_ps((float*)&dst->v1);
    __m128 t = _mm_unpackhi_ps(srcV, oldV);
    __m128 r = _mm_shuffle_ps(srcV, t, 0xC4);
    _mm_store_ps((float*)&dst->v1, r);
    for (int key = 0; key < 8; ++key)
        dst->shapeKeys[key] = src->shapeKeys[key];
    Node50* np = src->f50;
    IntegerTriple* link = (np->c18 == 1) ? (IntegerTriple*)((char*)np + np->c10) : 0;
    dst->f24 = link;
    float g = a->f1c->f8c[idx * 10];
    float slotB = g;
    slotB = (g + slotA) * src->f10;
    float length = slotB - g;
    dst->f48 = length;
    __m128 bc0 = _mm_load_ss(&slotB);
    __m128 bc = _mm_shuffle_ps(bc0, bc0, 0);
    __m128 e80 = E2->m_vHardPointWs.m_vComponents;
    __m128 p = _mm_mul_ps(bc, e80);
    __m128 e50 = E2->m_vContactPoint[5].m_vComponents;
    p = _mm_add_ps(p, e50);
    _mm_store_ps((float*)&dst->v0, p);
    dst->distance = length;
    __m128 v1n = _mm_load_ps((float*)&dst->v1);
    dst->f20 = dst->f24->friction;
    __m128 e80b = E2->m_vHardPointWs.m_vComponents;
    __m128 prod = _mm_mul_ps(v1n, e80b);
    __m128 h1 = _mm_shuffle_ps(prod, prod, 0x55);
    h1 = _mm_add_ss(h1, prod);
    __m128 h2 = _mm_shuffle_ps(prod, prod, 0xAA);
    h2 = _mm_add_ss(h2, h1);
    float sum;
    _mm_store_ss(&sum, h2);
    if (sum < -a->f1c->f84)
    {
        IntegerTriple* W = a->f18;
        VecWork d0;
        d0.m_vComponents = dst->v0;
        VecWork yVec;
        PointVelocity(W->motion, d0, yVec);
        VecWork xVec;
        PointVelocity(link->motion, d0, xVec);
        __m128 y0 = yVec.m_vComponents, x6 = xVec.m_vComponents;
        float inv = (float)(-1.0 / sum);
        y0 = _mm_sub_ps(y0, x6);
        y0 = _mm_mul_ps(y0, v1n);
        __m128 s1 = _mm_shuffle_ps(y0, y0, 0x55);
        s1 = _mm_add_ss(s1, y0);
        __m128 s2 = _mm_shuffle_ps(y0, y0, 0xAA);
        s2 = _mm_add_ss(s2, s1);
        float sum2;
        _mm_store_ss(&sum2, s2);
        dst->f4c = sum2 * inv;
        dst->f50 = inv;
    }
    else
    {
        dst->f4c = 0.0f;
        dst->f50 = 1.0f / a->f1c->f84;
    }
}

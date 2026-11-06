
// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleRayCastWheelCollide.h"

struct FUN_00e41f10
{
    void SetUserInfo(int a);
};
// @fnv 0x00e41f10
void FUN_00e41f10::SetUserInfo(int aiValue)
{
    *(int*)((char*)this + 0xc) = aiValue;
    int* p = *(int**)((char*)this + 0x10);
    if (p)
        p[0x2c / 4] = aiValue;
}

struct FUN_00c936a0_host
{
    void* FUN_00c936a0(void* phantom);
};

struct FUN_00e41ef0_self
{
    void* addToWorld(void* world);
};

// @fnv 0x00e41ef0
void* FUN_00e41ef0_self::addToWorld(void* world)
{
    return ((FUN_00c936a0_host*)world)->FUN_00c936a0(*(void**)((char*)this + 0x10));
}

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

// @fnv 0x00e41e70
void FUN_00e41e70_host::updateBeforeCollisionDetection(unsigned int shape)
{
    hkAabb aabb;
    this->FUN_00e41034(shape, &aabb);
    this->m_pPhantom->FUN_00cf24a0(&aabb);
}

struct FUN_00c92c70_host
{
    void FUN_00c92c70(void* phantom);
};
struct FUN_00e41f00_self
{
    void removeFromWorld();
};
// @fnv 0x00e41f00
void FUN_00e41f00_self::removeFromWorld()
{
    void* p = *(void**)((char*)this + 0x10);
    ((FUN_00c92c70_host*)*(void**)((char*)p + 8))->FUN_00c92c70(p);
}

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

// @fnv 0x00e42610
void hkObjXe42610::AppendPointer(hkArrayXe42610<void*>& kArray)
{
    void* pPointer = m_uiFilterValue;
    kArray.AddBack(pPointer);
}

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

// @fnv 0x00e41f30
void S00e41f30_impl::CreateWheelPhantom(S00e41f30_arg* arg)
{
    hkAabb aabb;

    this->vf34(reinterpret_cast<unsigned int>(arg), &aabb);

    FUN_00c85750_host* host = fnvc_adapt::FUN_00c85750();

    FUN_00c85750_obj* allocated = reinterpret_cast<FUN_00c85750_obj*>(host->unk10->vf04(0xe0));

    allocated->unk04 = 0xe0;

    FUN_00c85750_obj* pPhantom =
        reinterpret_cast<FUN_00c85750_obj*>(allocated->FUN_00cf2cb0(&aabb, this->m_uiWheelCount));

    this->m_pPhantom = reinterpret_cast<hkpAabbPhantom*>(pPhantom);

    this->unk20 = arg->unk18 + 0x10;

    S00e41f30_listener* l = &this->m_kChassisRejectionListener;
    void* v = l ? &this->m_kChassisRejectionListener.unk08 : 0;
    pPhantom->FUN_00d07de0(v);
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

// Copies contact point velocity, writes negated hard point components to the separating normal, and stores the wheel rest length.
// @fnv 0x00e423d0
void __stdcall hkpVehicleRayCastWheelCollideE423::RayCastWheelCollide(const hkpVehicleInstanceE423* pkVehicle,
                                                                      unsigned char ucWheelNum,
                                                                      CollisionDetectionWheelOutputE423& kCdInfo)
{
    const float fRestLength = pkVehicle->m_pSuspension->m_kWheelParams[ucWheelNum].m_fRestLength;
    const hkpVehicleWheelInfoE423& kWheel = pkVehicle->m_kWheelInfoArray[ucWheelNum];
    kCdInfo.m_uiContactShapeKeys = 0;
    kCdInfo.m_fContactFriction = fRestLength;
    kCdInfo.m_fValueAtOffset4C = 0.0f;
    kCdInfo.m_vContactPoint.m_vContactPosition = kWheel.m_vContactPointVelocity;
    hkVector4E423 kNormal;
    kNormal.setNeg4(kWheel.m_vHardPointWs);
    kCdInfo.m_vContactPoint.m_vSeparatingNormal.setXYZ(kNormal);
    kCdInfo.m_fSuspensionLength = 0.0f;
    kCdInfo.m_fValueAtOffset50 = 1.0f;
    kCdInfo.m_vContactPoint.m_vSeparatingNormal(3) = fRestLength;
}

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
// Constructs a vehicle wheel collide object, initializing wheel count to 0, phantom to null, collision disabled, and type to 1.
// @fnv 0x00e42550
FUN_00e42550::FUN_00e42550() : m_uiWheelCount(0), m_pPhantom(0)
{
    m_bWheelCollisionEnabled = false;
    m_type = 1;
}

namespace fnv_00e42590 {
class hkMemoryAllocatorE42
{
  public:
    virtual ~hkMemoryAllocatorE42() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE42
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE42* m_pStreamAllocator;

    hkMemoryAllocatorE42& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE42 {
extern "C" hkMemoryRouterE42& __cdecl FUN_00c85750() throw();
}

class hkpEntityListenerE42
{
  public:
    virtual void EntityAddedCallback();
};

class hkpEntityE42
{
  public:
    void FUN_00c90510() throw();
    void FUN_00d07c80(hkpEntityListenerE42* listener) throw();
    void FUN_00d07de0(hkpEntityListenerE42* listener) throw();
};

class hkpActionListenerE42
{
  public:
    virtual void ActionRemovedCallback();
    int unk04;
};

class hkpListenerSetE42 : public hkpActionListenerE42, public hkpEntityListenerE42
{
};

struct hkpSimulationIslandE42
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_data;
};

struct hkEntityArrayE42
{
    hkpEntityE42** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00e42550
{
  public:
    virtual ~FUN_00e42550();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int m_ulUserData;
    hkpEntityE42* m_pEntity;
    hkpListenerSetE42 m_kListeners;
    int* m_pCurrentSimulationIsland;

    static void* operator new(unsigned int nbytes)
    {
        FUN_00e42550* b = static_cast<FUN_00e42550*>(hkRouterE42::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    FUN_00e42550() throw();
    FUN_00e42550* Clone(hkpSimulationIslandE42* island, const hkEntityArrayE42& entities);
};

// Creates a new FUN_00e42550 on entities[0], registers its listener set via FUN_00d07de0, sets its island pointer from island, and copies m_ulUserData.
// @fnv 0x00e42590
FUN_00e42550* FUN_00e42550::Clone(hkpSimulationIslandE42* island, const hkEntityArrayE42& entities)
{
    FUN_00e42550* clone = new FUN_00e42550();
    clone->m_pEntity = entities.m_data[0];
    clone->m_pEntity->FUN_00c90510();
    clone->m_pEntity->FUN_00d07c80(&m_kListeners);
    clone->m_pEntity->FUN_00d07de0(&clone->m_kListeners);
    clone->m_pCurrentSimulationIsland = &island->m_data;
    clone->m_ulUserData = m_ulUserData;
    return clone;
}
}  // namespace fnv_00e42590

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

// Builds an input from vectors at source offsets 0x50 and 0x60 (filter info = m_uiWheelCount) and passes it with output to m_pPhantom's FUN_00cf26b0.
// @fnv 0x00e41eb0
void __thiscall FUN_00e41eb0_Host::castSingleWheel(const void* source, void* output)
{
    FUN_00e41eb0_Input input;
    *(__m128*)&input.m_vFrom = *(__m128*)((const char*)source + 0x50);
    *(__m128*)&input.m_vTo = *(__m128*)((const char*)source + 0x60);
    input.m_uiFilterInfo = m_uiWheelCount;
    input.m_bEnableShapeCollectionFilter = 1;
    m_pPhantom->FUN_00cf26b0(&input, output);
}

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

// Iterates over vehicle wheels, casts a ray for each, and processes or finalizes the collision output based on whether the ray hit.
// @fnv 0x00e420c0
void S00e420c0_Self::collideWheels(float deltaTime, const hkpVehicleInstanceE420* vehicle,
                                  CollisionDetectionWheelOutputE420* cdInfoOut)
{
    const unsigned char numWheels = vehicle->m_data->m_iWheelCount;
    for (unsigned char w_it = 0; w_it < numWheels; ++w_it)
    {
        const hkpWheelInfoE420& wheel_info = vehicle->m_kWheelInfoArray[w_it];
        CollisionDetectionWheelOutputE420& cd_wheelInfo = cdInfoOut[w_it];
        hkpWorldRayCastOutputE420 raycastOutput;
        CastWheelRay(wheel_info, raycastOutput);
        if (raycastOutput.DidHit())
        {
            ProcessWheelRayCastResult(vehicle, w_it, raycastOutput, cd_wheelInfo);
        }
        else
        {
            FinalizeWheelCollisionOutput(vehicle, w_it, cd_wheelInfo);
        }
        InitializeWheelCollisionOutput(vehicle, w_it, cd_wheelInfo);
    }
}

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

// Computes the min/max AABB from the m_kBounds of all items in the self->unk48 array, storing the result into aabb.
// @fnv 0x00e42010
void __stdcall calcWheelsAABB(FUN_00e42010_self* self, hkAabb* aabb)
{
    _mm_store_ps(&aabb->m_data[0], _mm_min_ps(_mm_load_ps(&self->unk48[0].m_kBounds.m_data[0]),
                                              _mm_load_ps(&self->unk48[0].m_kBounds.m_data[4])));
    _mm_store_ps(&aabb->m_data[4], _mm_max_ps(_mm_load_ps(&self->unk48[0].m_kBounds.m_data[0]),
                                              _mm_load_ps(&self->unk48[0].m_kBounds.m_data[4])));
    for (int i = 1; i < self->unk1c->unk20; i++)
    {
        FUN_00e42010_item* b = &self->unk48[i];
        __m128 vMin = _mm_min_ps(_mm_load_ps(&aabb->m_data[0]), _mm_load_ps(&b->m_kBounds.m_data[4]));
        _mm_store_ps(&aabb->m_data[0], vMin);
        vMin = _mm_min_ps(vMin, _mm_load_ps(&b->m_kBounds.m_data[0]));
        _mm_store_ps(&aabb->m_data[0], vMin);
        __m128 vMax = _mm_max_ps(_mm_load_ps(&aabb->m_data[4]), _mm_load_ps(&b->m_kBounds.m_data[4]));
        _mm_store_ps(&aabb->m_data[4], vMax);
        vMax = _mm_max_ps(vMax, _mm_load_ps(&b->m_kBounds.m_data[0]));
        _mm_store_ps(&aabb->m_data[4], vMax);
    }
}

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

// Sets up one ray-cast command per wheel from the vehicle instance and returns the wheel count, or 0 when no collidables overlap.
// @fnv 0x00e42460
int S00e42460_RayCastWheelCollide::buildRayCastCommands(const S00e42460_VehicleInstance* vehicle,
                                                const hkpCollisionFilter* collisionFilter, hkInt32 filterSize,
                                                S00e42460_RayCastCommand* commandStorage,
                                                S00e42460_WorldRayCastOutput* outputStorage) const
{
    ((hkpAabbPhantomQ*)m_pPhantom)->RemoveOverlappingBody();

    const int numCollidables = ((hkpAabbPhantomQ*)m_pPhantom)->m_ppOverlappingCollidables.m_iElementCount;
    if (numCollidables > 0)
    {
        const hkInt8 numWheels = vehicle->m_data->m_iWheelCount;
        if (numWheels > 0)
        {
            int i = 0;
            int count = (hkUint8)numWheels;
            do
            {
                S00e42460_RayCastCommand& command = *commandStorage;
                const S00e42460_WheelInfo& wheelInfo = vehicle->m_kWheelInfoArray.m_data[i];

                command.m_kRayCastQuery.m_vFrom.m_vComponents = wheelInfo.m_vContactPointVelocity.m_vComponents;
                command.m_kRayCastQuery.m_vTo.m_vComponents = wheelInfo.m_vContactNormal.m_vComponents;
                command.m_kRayCastQuery.m_uiFilterInfo = m_uiWheelCount;
                command.m_kRayCastQuery.m_pRayShapeCollectionFilter = collisionFilter;
                command.m_uiCollisionFilterInfo = collisionFilter->m_type;
                command.m_iCommandParameter = filterSize;
                command.m_bResultFlag = false;
                command.m_kCollidables = ((hkpAabbPhantomQ*)m_pPhantom)->m_ppOverlappingCollidables.m_data;
                command.m_pResultBuffer = outputStorage;
                command.m_iCollidableCount = numCollidables;
                command.m_iResultCount = 1;
                command.m_iResultCapacity = 0;
                ++i;
                ++commandStorage;
                ++outputStorage;
            } while (--count != 0);
        }
        return numWheels;
    }
    return 0;
}

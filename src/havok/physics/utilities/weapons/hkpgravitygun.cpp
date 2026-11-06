
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGravityGun.h"

struct FUN_00e45fb0_class
{
    void FUN_00e45e60(int);
    void FUN_00e45fb0(int, int, int);
};

// @fnv 0x00e45fb0
void FUN_00e45fb0_class::FUN_00e45fb0(int, int, int)
{
    if (*(int*)((char*)this + 0x24) != 0)
        FUN_00e45e60(0);
}

struct DDCC60World
{
    void removeReference();
};

struct FUN_00e45fc0_class
{
    unsigned char m_unknown[0x20];
    DDCC60World** m_kExternalLinks;
    int m_sReferenceCount;

    void RemoveAllReferences(int);
};

// @fnv 0x00e45fc0
void FUN_00e45fc0_class::RemoveAllReferences(int)
{
    int i = 0;
    if (m_sReferenceCount > 0)
    {
        do
        {
            m_kExternalLinks[i]->removeReference();
            ++i;
        } while (i < m_sReferenceCount);
    }
    m_sReferenceCount = 0;
}

struct hkFinishLoadedObjectFlagE463
{
    int m_bFinishing;
};

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE463() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e466a0();

    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE463<void*> m_kListeners;
};

class hkpRigidBodyE463;

class FUN_00e46300 : public FUN_00e466a0
{
  public:
    hkArrayE463<hkpRigidBodyE463*> m_kPickedBodies;

    FUN_00e46300(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e46300();
};

// @fnv 0x00e46300
FUN_00e46300::FUN_00e46300(hkFinishLoadedObjectFlagE463 flag) : FUN_00e466a0(flag)
{
    if (flag.m_bFinishing)
        m_type = 3;
}

namespace fnv_00e46340 {
class hkMemoryAllocatorE463
{
  public:
    virtual ~hkMemoryAllocatorE463() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE463
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE463* m_pStreamAllocator;
    hkMemoryAllocatorE463& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE463& __cdecl FUN_00c85750();

template <class T> __forceinline void destructE463(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE463() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructE463(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorE463& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectE463
{
  public:
    virtual ~hkReferencedObjectE463() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectE463*>(p)->m_usMemSizeAndFlags);
    }
};

class FUN_00e466e0 : public hkReferencedObjectE463
{
  public:
    int m_08;
    FUN_00cb0c00_class m_name;
    int m_10;
    hkArrayE463<FUN_00d1df70*> m_children;

    virtual ~FUN_00e466e0() throw();
};

class hkDerivedE463 : public FUN_00e466e0
{
  public:
    hkArrayE463<int> m_iSlotIds;

    hkDerivedE463* DestroyAndFree(unsigned int uiFlags) throw();
};

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00e46340
hkDerivedE463* hkDerivedE463::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->hkDerivedE463::~hkDerivedE463();
    if (uiFlags & 1)
        hkDerivedE463::operator delete(this);
    return this;
}
}  // namespace fnv_00e46340

extern "C" double __cdecl fabs(double);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

namespace MathUtilities {
inline hkReal fabs(hkReal r)
{
    return static_cast<hkReal>(::fabs(r));
}
}

struct GGVector4
{
    __m128 m_vComponents;

    void operator=(const GGVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    hkReal& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void SetTransformedPosition(const struct GGTransform& t, const GGVector4& v);
};

struct GGMotion
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    GGVector4 m_vCenterOfMass0;
    GGVector4 m_vCenterOfMass1;
    hkReal GetMassValue() const;
};

struct GGCollidable
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    int ca0;
    int ca4;
    int ca8;
    int cac;
    int cb0;
    int cb4;
    int cb8;
    int cbc;
    int cc0;
    int cc4;
    int cc8;
    int ccc;
};

struct GGRigidBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    GGCollidable m_kCollidable;
    GGMotion m_pMotionState;

    const GGVector4& getCenterOfMassInWorld() const
    {
        return m_pMotionState.m_vCenterOfMass1;
    }
    const GGCollidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    hkReal GetMassValue() const
    {
        return m_pMotionState.GetMassValue();
    }
};

struct GGEntityArray
{
    GGRigidBody** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGSimulationIsland
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
    GGEntityArray m_kActorEntries;
};

struct GGIslandArray
{
    GGSimulationIsland** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGWorldRayCastInput
{
    GGVector4 m_vFrom;
    GGVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    hkUint32 m_uiFilterInfo;
    GGWorldRayCastInput() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct GGRayHitCollector
{
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo) = 0;
    hkReal m_fEarlyOutHitFraction;

    GGRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
    }
};

struct GGShapeRayCastCollectorOutput
{
    GGVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18;
    int unk1c;

    GGShapeRayCastCollectorOutput()
    {
        reset();
    }
    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
    }
};

struct GGShapeRayCastOutput : GGShapeRayCastCollectorOutput
{
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;

    GGShapeRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        GGShapeRayCastCollectorOutput::reset();
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct GGWorldRayCastOutput : GGShapeRayCastOutput
{
    const GGCollidable* m_pRootCollidable;

    GGWorldRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        m_pRootCollidable = 0;
        GGShapeRayCastOutput::reset();
    }
};

struct GGClosestRayHitCollector : GGRayHitCollector
{
    GGWorldRayCastOutput m_kClosestHit;

    GGClosestRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_kClosestHit.reset();
        GGRayHitCollector::reset();
    }
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo);
};

struct GGWorld
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
    GGIslandArray m_kActiveSimulationIslands;
    GGIslandArray m_kInactiveSimulationIslands;

    void RayCast(const GGWorldRayCastInput& input, GGRayHitCollector& collector) const;
};

struct GGTransform
{
    GGVector4 m_kColumn0, m_kColumn1, m_kColumn2;
    GGVector4 m_vTranslation;
};

struct GravityGun : hkpGravityGun
{
    bool isGrabbed(const GGRigidBody* body) const
    {
        for (int i = 0; i < m_kPickedBodies.m_iElementCount; i++)
        {
            if (m_kPickedBodies.m_data[i] == body)
            {
                return true;
            }
        }
        return false;
    }

    GGRigidBody* FUN_00e45a60(const GGTransform& viewTransform, const GGRigidBody* characterBody, const GGWorld* world);
};

// Finds the best rigid body to grab by scoring candidates in active and inactive islands, then ray-casting to verify line of sight.
// @fnv 0x00e45a60
GGRigidBody* GravityGun::FUN_00e45a60(const GGTransform& viewTransform, const GGRigidBody* characterBody,
                                      const GGWorld* world)
{
    GGRigidBody* pickedBody = 0;
    hkReal bestValue = 0.35f;

    const GGIslandArray* islands = &world->m_kActiveSimulationIslands;
    for (int iIslandSet = 0; iIslandSet < 2; iIslandSet++)
    {
        for (int i = 0; i < islands->m_iElementCount; i++)
        {
            GGSimulationIsland* island = islands->m_data[i];
            for (int e = 0; e < island->m_kActorEntries.m_iElementCount; e++)
            {
                GGRigidBody* body = island->m_kActorEntries.m_data[e];
                const GGVector4& vCenterOfMass = body->getCenterOfMassInWorld();

                GGVector4 posInView;
                posInView.SetTransformedPosition(viewTransform, vCenterOfMass);

                hkReal x = posInView(0);
                if (x < 0.1f || x > m_fMaxPickDistance || body == characterBody)
                {
                    continue;
                }

                hkReal value = MathUtilities::fabs(posInView(2)) + MathUtilities::fabs(posInView(1));
                value = value / (x + 1.0);

                if (body->GetMassValue() > m_fMaxPickMass)
                {
                    value += 0.1f;
                }

                if (value > bestValue)
                {
                    continue;
                }

                if (isGrabbed(body))
                {
                    continue;
                }

                {
                    GGClosestRayHitCollector collector;
                    GGWorldRayCastInput input;
                    input.m_vFrom = viewTransform.m_vTranslation;
                    input.m_vTo = vCenterOfMass;

                    world->RayCast(input, collector);

                    if (collector.m_kClosestHit.m_pRootCollidable == 0 ||
                        collector.m_kClosestHit.m_pRootCollidable == body->getCollidable())
                    {
                        bestValue = value;
                        pickedBody = body;
                    }
                }
            }
        }
        islands = &world->m_kInactiveSimulationIslands;
    }
    return pickedBody;
}

struct DDCC60World;

struct __declspec(align(16)) MyVec
{
    float x, y, z, w;
};

struct GunArg3
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc;
    int unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c;
    MyVec unk120;
};

struct GunTransform
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    MyVec m_vTranslation;
};

struct GunListener
{
    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func4();
    virtual void gunAction(const MyVec& from, const MyVec* to = 0);
};

struct hkpGravityGunEx : public hkpGravityGun
{
    void FUN_00e45ee0(GunTransform* a4, GunArg3* a3, DDCC60World* world);
    void FUN_00e46080(GunTransform* a4, GunArg3* a3, DDCC60World* world);
    void FUN_00e45fb0(GunTransform* a4, GunArg3* a3, DDCC60World* world);
    void FUN_00e45c90(hkReal dt, GunTransform* a4, GunArg3* a3);

    void stepGun(hkReal dt, DDCC60World* world, GunArg3* a3, GunTransform* a4, bool b1, bool b2);
};

// Dispatches a gun action to listeners based on b1/b2 and picked-body capacity, then calls FUN_00e45c90 with dt, a4, a3.
// @fnv 0x00e46140
void hkpGravityGunEx::stepGun(hkReal dt, DDCC60World* world, GunArg3* a3, GunTransform* apGunTransform, bool b1,
                                   bool b2)
{
    MyVec v1;
    MyVec v2;

    if (b1)
    {
        FUN_00e45ee0(apGunTransform, a3, world);
        *(__m128*)&v1 = *(__m128*)&a3->unk120;
        for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        {
            ((GunListener*)m_kListeners.m_data[i])->gunAction(v1, 0);
        }
    }
    else if (b2)
    {
        if (m_kPickedBodies.m_iElementCount != m_iMaxPickedBodies)
        {
            FUN_00e46080(apGunTransform, a3, world);
            *(__m128*)&v2 = *(__m128*)&apGunTransform->m_vTranslation;
            *(__m128*)&v1 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, &v1);
            }
        }
        else
        {
            FUN_00e45fb0(apGunTransform, a3, world);
            *(__m128*)&v2 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, 0);
            }
        }
    }

    FUN_00e45c90(dt, apGunTransform, a3);
}

extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" void _mm_store_ss(float* _V, __m128 _A);
class hkMemoryAllocatorE460;

struct hkMemoryRouterE460
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE460* m_pStreamAllocator;
};

namespace hkRouterE460 {
extern "C" hkMemoryRouterE460& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE460
{
    char m_cBooleanValue;
    hkBoolE460()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE460(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE460
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE460& router = hkRouterE460::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE460<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkSimdRealE460
{
    __m128 m_vValue;
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4E460
{
    __m128 m_vComponents;
    hkSimdRealE460 getW() const
    {
        hkSimdRealE460 r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
};

class hkEntityE460
{
  public:
    int unk00[104];
    hkVector4E460 m_vec1a0;

    void FUN_00c90510();
    void FUN_00ca88e0(float f);
};

class hkWorldE460
{
  public:
    int unk00[8];
    hkArrayE460<hkEntityE460*> m_kActorEntries;

    void FUN_00e46000(hkEntityE460* e);
};

// Calls e->FUN_00c90510, appends e to m_kActorEntries, then calls e->FUN_00ca88e0 with the w component of m_vec1a0 times 100.
// @fnv 0x00e46000
void hkWorldE460::FUN_00e46000(hkEntityE460* apEntity)
{
    apEntity->FUN_00c90510();
    m_kActorEntries.AddBack(apEntity);
    float w = apEntity->m_vec1a0.getW();
    float f = (float)(w * 100.0);
    apEntity->FUN_00ca88e0(f);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

class hkStringPtrE462
{
  public:
    char* m_pcText;
    void FUN_00cb0c10(const char* pcString) throw();
    void operator=(const char* pcString)
    {
        FUN_00cb0c10(pcString);
    }
};

template <class T> class hkArrayE462
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE462() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct __declspec(align(16)) hkVector4E462
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

class hkpFirstPersonGunListenerE462;
class hkpRigidBodyE462;

class FUN_00e46660
{
  public:
    virtual ~FUN_00e46660() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    hkStringPtrE462 m_name;
    unsigned char m_uiKeyboardKey;
    hkArrayE462<hkpFirstPersonGunListenerE462*> m_kListeners;

    FUN_00e46660() throw();
};

class FUN_00e46260 : public FUN_00e46660
{
  public:
    hkArrayE462<hkpRigidBodyE462*> m_kPickedBodies;
    int m_iMaxPickedBodies;
    float m_fMaxPickMass;
    float m_fMaxPickDistance;
    float m_fPickAngle;
    float m_fHoldDistance;
    hkVector4E462 m_kGrabPosition;
    hkVector4E462 m_kTargetPosition;

    FUN_00e46260() throw();
    virtual ~FUN_00e46260() throw();
};

// Constructs a GravityGun object, initializing pick limits, grab and target positions, and setting the type and name fields.
// @fnv 0x00e46260
FUN_00e46260::FUN_00e46260() throw()
    : m_iMaxPickedBodies(10), m_fMaxPickMass(200.0f), m_fMaxPickDistance(50.0f), m_fPickAngle(100.0f),
      m_fHoldDistance(50.0f)
{
    m_type = 3;
    m_name = "GravityGun";
    m_kGrabPosition.set(2.5f, 0.6f, 0.0f);
    m_kTargetPosition.set(0.0f, 1.0f, 0.0f);
}

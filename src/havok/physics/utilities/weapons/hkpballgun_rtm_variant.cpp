
// src/havok/physics/utilities/weapons/hkpballgun_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpballgun.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/weapons/hkpballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpBallGun.h"
struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
struct hkBoolE46E
{
    char m_cBooleanValue;
    hkBoolE46E(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
class hkpWorldE46E;
class hkpRigidBodyE46E : public FUN_00d1df70
{
  public:
    int m_00;
    int m_04;
    hkpWorldE46E* m_pOwningWorld;

    hkpWorldE46E* getWorld() const
    {
        return m_pOwningWorld;
    }
};
class hkpWorldE46E
{
  public:
    hkBoolE46E ProcessTarget(hkpRigidBodyE46E* pkEntity) throw();
};
template <class T> class hkQueueE46E
{
  public:
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    bool isEmpty() const
    {
        return m_iNodeCount == 0;
    }
    void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        m_pFirstNode++;
        if (m_pFirstNode == m_pRayCursor)
            m_pFirstNode = 0;
        m_iNodeCount--;
    }
};
template <class T> class hkArrayE46E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};
class hkpFirstPersonGunListenerE46E
{
  public:
    virtual ~hkpFirstPersonGunListenerE46E() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void bulletDeletedCallback(hkpRigidBodyE46E* pkBullet) throw();
};
class hkpFirstPersonGunE46E
{
  public:
    virtual ~hkpFirstPersonGunE46E() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE46E<hkpFirstPersonGunListenerE46E*> m_kListeners;
};
class hkpBallGunE46E : public hkpFirstPersonGunE46E
{
  public:
    hkReal m_fBulletRadius;
    hkReal m_fBulletVelocity;
    hkReal m_fBulletMass;
    hkReal m_fBulletSpread;
    hkInt32 m_iBulletBatchCount;
    int m_34;
    int m_38;
    int m_3c;
    hkReal m_kBulletDirection[4];
    hkQueueE46E<hkpRigidBodyE46E*>* m_pBulletQueue;

    void reset(hkpWorldE46E* pkWorld) throw();
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps();
static const float DAT_0101df44 = 0.2f;
static const float DAT_0104ef80 = 40.0f;
static const float DAT_0101b268 = 50.0f;
struct hkVector4E46F
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};
struct hkMemoryAllocatorE46F
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};
struct hkMemoryRouterE46F
{
    unsigned int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE46F* m_pStreamAllocator;

    hkMemoryAllocatorE46F& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE46F* __cdecl FUN_00c85750();
struct FUN_00cb0c10
{
    void operator=(const char* pcString);

    const char* m_pcText;
};
struct FUN_00e46e80
{
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
    }

    FUN_00e46e80() throw();

    void FUN_00e45460(int iCapacity);

    void* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;
};
class FUN_00e46660
{
  public:
    FUN_00e46660() throw();
    virtual ~FUN_00e46660() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    FUN_00cb0c10 m_name;
    unsigned char m_uiKeyboardKey;
    void** m_kListeners;
    int m_listenersSize;
    int m_listenersCapacityAndFlags;
};
class FUN_00e46f90 : public FUN_00e46660
{
  public:
    FUN_00e46f90(int iNumBullets) throw();
    virtual ~FUN_00e46f90() throw();

    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    hkVector4E46F m_kBulletDirection;
    FUN_00e46e80* m_pBulletQueue;
    unsigned int unk54, unk58, unk5C;
};

extern "C"
{

    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ss(float const*);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct hkQuadVector4
{
    __m128 m_vComponents;

    __forceinline hkQuadVector4()
    {}
    __forceinline hkQuadVector4(const hkQuadVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkQuadVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setAdd4(const hkQuadVector4& a, const hkQuadVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkReal& r, const hkQuadVector4& a)
    {
        __m128 t = _mm_load_ss(&r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), a.m_vComponents);
    }
    __forceinline void setAddMul4(const hkQuadVector4& a, const hkQuadVector4& b, hkReal r)
    {
        __m128 t = _mm_load_ss(&r);
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), b.m_vComponents), a.m_vComponents);
    }
};

struct hkpBallGunSweepOutput
{
    hkQuadVector4 m_vContactPosition;
    hkQuadVector4 m_vHitNormal;
    hkQuadVector4 m_unk20;
};

struct hkQuadTransform
{
    hkQuadVector4 m_kColumn0;
    hkQuadVector4 m_kColumn1;
    hkQuadVector4 m_kColumn2;
    hkQuadVector4 m_vTranslation;
};

class hkBoolResult
{
  public:
    hkBoolResult()
    {}
    char m_cBooleanValue;
};

struct hkpShapeBase : public hkReferencedObject
{
    void FUN_00c905b0();

    __forceinline void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        return b;
    }
    __forceinline void operator delete(void*)
    {}
};

struct FUN_00cd8160 : public hkpShapeBase
{
    FUN_00cd8160(hkReal radius) throw();
    hkUint32 unk08, unk0C, unk10, unk14, unk18, unk1C;
};

struct FUN_00cf5ea0
{
    FUN_00cf5ea0() throw();

    hkUint32 m_uiCollisionFilterData;
    hkpShapeBase* m_pCollisionShape;
    hkUint32 m_unk08;
    hkUint32 m_unk0C;
    hkQuadVector4 m_vContactPosition;
    hkQuadVector4 m_rotation;
    hkQuadVector4 m_kTranslationalVelocity;
    hkQuadVector4 m_kAngularVelocity;
    hkQuadVector4 m_inertiaTensor0;
    hkQuadVector4 m_inertiaTensor1;
    hkQuadVector4 m_inertiaTensor2;
    hkQuadVector4 m_kCenterOfMass1;
    hkReal m_fViscosityFriction;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    hkReal m_fSlipAngle;
    hkReal m_fElasticity;
    hkReal m_fSurfaceFriction;
    hkReal m_fRestitution;
    hkReal m_unkAC;
    hkReal m_fAllowedPenetrationDepth;
    hkUint8 m_bFlag;
    hkUint8 m_unkB5;
    hkUint8 m_unkB6;
    hkUint8 m_iAutoRemoveLevel;
    hkUint32 m_unkB8;
    hkUint32 m_unkBC;
};

struct FUN_00ca8c90 : public hkpShapeBase
{
    FUN_00ca8c90(const FUN_00cf5ea0& info) throw();
    void* m_pOwningWorld;
    hkUint32 unk0C;
    hkUint32 unk10;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    hkUint32 unk20;
    hkUint32 unk24;
    hkUint32 unk28;
    hkUint32 unk2C;
    hkUint32 unk30;
    hkUint32 unk34;
    hkUint32 unk38;
    hkUint32 unk3C;
    hkUint32 unk40;
    hkUint32 unk44;
    hkUint32 unk48;
    hkUint32 unk4C;
    hkUint32 unk50;
    hkUint32 unk54;
    hkUint32 unk58;
    hkUint32 unk5C;
    hkUint32 unk60;
    hkUint32 unk64;
    hkUint32 unk68;
    hkUint32 unk6C;
    hkUint32 unk70;
    hkUint32 unk74;
    hkUint32 unk78;
    hkUint32 unk7C;
    hkUint32 unk80;
    hkUint32 unk84;
    hkUint32 unk88;
    hkUint32 unk8C;
    hkUint32 unk90;
    hkUint32 unk94;
    hkUint32 unk98;
    hkReal m_fBulletSpread;
    hkUint32 unk0A0;
    hkUint32 unk0A4;
    hkUint32 unk0A8;
    hkUint32 unk0AC;
    hkUint32 unk0B0;
    hkUint32 unk0B4;
    hkUint32 unk0B8;
    hkUint32 unk0BC;
    hkUint32 unk0C0;
    hkUint32 unk0C4;
    hkUint32 unk0C8;
    hkUint32 unk0CC;
    hkUint32 unk0D0;
    hkUint32 unk0D4;
    hkUint32 unk0D8;
    hkUint32 unk0DC;
    hkUint32 unk0E0;
    hkUint32 unk0E4;
    hkUint32 unk0E8;
    hkUint32 unk0EC;
    hkUint32 unk0F0;
    hkUint32 unk0F4;
    hkUint32 unk0F8;
    hkUint32 unk0FC;
    hkUint32 unk100;
    hkUint32 unk104;
    hkUint32 unk108;
    hkUint32 unk10C;
    hkUint32 unk110;
    hkUint32 unk114;
    hkUint32 unk118;
    hkUint32 unk11C;
    hkUint32 unk120;
    hkUint32 unk124;
    hkUint32 unk128;
    hkUint32 unk12C;
    hkUint32 unk130;
    hkUint32 unk134;
    hkUint32 unk138;
    hkUint32 unk13C;
    hkUint32 unk140;
    hkUint32 unk144;
    hkUint32 unk148;
    hkUint32 unk14C;
    hkUint32 unk150;
    hkUint32 unk154;
    hkUint32 unk158;
    hkUint32 unk15C;
    hkUint32 unk160;
    hkUint32 unk164;
    hkUint32 unk168;
    hkUint32 unk16C;
    hkUint32 unk170;
    hkUint32 unk174;
    hkUint32 unk178;
    hkUint32 unk17C;
    hkUint32 unk180;
    hkUint32 unk184;
    hkUint32 unk188;
    hkUint32 unk18C;
    hkUint32 unk190;
    hkUint32 unk194;
    hkUint32 unk198;
    hkUint32 unk19C;
    hkUint32 unk1A0;
    hkUint32 unk1A4;
    hkUint32 unk1A8;
    hkUint32 unk1AC;
    hkUint32 unk1B0;
    hkUint32 unk1B4;
    hkUint32 unk1B8;
    hkUint32 unk1BC;
    hkUint32 unk1C0;
    hkUint32 unk1C4;
    hkUint32 unk1C8;
    hkUint32 unk1CC;
    hkUint32 unk1D0;
    hkUint32 unk1D4;
    hkUint32 unk1D8;
    hkUint32 unk1DC;
    hkUint32 unk1E0;
    hkUint32 unk1E4;
    hkUint32 unk1E8;
    hkUint32 unk1EC;
    hkUint32 unk1F0;
    hkUint32 unk1F4;
    hkUint32 unk1F8;
    hkUint32 unk1FC;
    hkUint32 unk200;
    hkUint32 unk204;
    hkUint32 unk208;
    hkUint32 unk20C;
    hkUint32 unk210;
    hkUint32 unk214;
    hkUint32 unk218;
    hkUint32 unk21C;
};

struct hkpBallGunListener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void bulletCreatedCallback(FUN_00ca8c90* bullet);
    virtual void bulletDeletedCallback(FUN_00ca8c90* bullet);
    virtual void gunFiredCallback(const hkQuadVector4* from, const hkQuadVector4* to);
};

struct hkpWorld
{
    hkUint32 unk00, unk04, unk08, unk0C;
    hkQuadVector4 m_kGravity;

    void* FUN_00c914d0(FUN_00ca8c90* entity, int activation);
    hkBoolResult ProcessTarget(FUN_00ca8c90* entity);
};

template <typename T> struct CapacityGrowingArray
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void FUN_00e45460(int n);

    __forceinline int GetLogicalSize() const
    {
        return m_iNodeCount;
    }

    __forceinline void increaseCapacity()
    {
        if (m_pRayCursor == 0)
        {
            FUN_00e45460(8);
        }
        else
        {
            FUN_00e45460(m_pRayCursor * 2);
        }
    }

    __forceinline void enqueue(const T& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
        {
            increaseCapacity();
        }
        if (m_pTail == m_pRayCursor)
        {
            m_pTail = 0;
        }
        m_data[m_pTail++] = element;
        m_iNodeCount++;
    }

    __forceinline void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        if (++m_pFirstNode == m_pRayCursor)
        {
            m_pFirstNode = 0;
        }
        m_iNodeCount--;
    }
};

void FUN_00cf07a0(const hkpShapeBase* shape, hkReal mass, FUN_00cf5ea0& out);
int FUN_00e464e0(hkpWorld* world, const hkQuadVector4& start, hkReal radius, const hkQuadVector4& end,
                 hkpBallGunSweepOutput& output);
void FUN_00e463d0(const hkQuadVector4& position, const hkQuadVector4& target, const hkQuadVector4& gravity,
                  hkReal speed, hkQuadVector4& velocityOut);

struct hkpBallGunEx : public hkpBallGun
{
    void fireGun(hkpWorld* world, const hkQuadTransform& viewTransform);
};

// @fnv 0x00e470d0
void hkpBallGunEx::fireGun(hkpWorld* world, const hkQuadTransform& viewTransform)
{
    hkQuadVector4 forward = viewTransform.m_kColumn0;
    hkQuadVector4 eye = viewTransform.m_vTranslation;
    hkQuadVector4 start;
    start.setAdd4(eye, forward);
    hkQuadVector4 end;
    end.setAddMul4(start, forward, 200.0f);

    FUN_00cf5ea0 ci;
    ci.m_pCollisionShape = new FUN_00cd8160(m_fBulletRadius);
    ci.m_fViscosityFriction = m_fBulletMass;
    ci.m_fAllowedPenetrationDepth = 0.01f;
    ci.m_fSurfaceFriction = 0.2f;
    ci.m_iAutoRemoveLevel = 6;
    ci.m_bFlag = 2;
    ci.m_fElasticity = 1.0f;
    FUN_00cf07a0(ci.m_pCollisionShape, m_fBulletMass * 2.0f, ci);
    ci.m_fViscosityFriction = m_fBulletMass;
    ci.m_fLinearDamping = 0.0f;
    ci.m_fAngularDamping = 0.4f;
    ci.m_vContactPosition.setAdd4(start, *reinterpret_cast<const hkQuadVector4*>(&m_kBulletDirection));

    hkpBallGunSweepOutput output;
    if (!FUN_00e464e0(world, start, m_fBulletRadius, end, output))
    {
        FUN_00e463d0(ci.m_vContactPosition, output.m_vContactPosition, world->m_kGravity, m_fBulletVelocity,
                     ci.m_kTranslationalVelocity);
    }
    else
    {
        ci.m_kTranslationalVelocity.setMul4(m_fBulletVelocity, forward);
    }

    hkQuadVector4 target = output.m_vContactPosition;
    int i;
    for (i = 0; i < m_kListeners.m_iElementCount; i++)
    {
        static_cast<hkpBallGunListener*>(m_kListeners.m_data[i])->gunFiredCallback(&eye, &target);
    }

    FUN_00ca8c90* bullet = new FUN_00ca8c90(ci);
    ci.m_pCollisionShape->FUN_00c905b0();
    bullet->m_fBulletSpread = m_fBulletSpread;

    for (i = 0; i < m_kListeners.m_iElementCount; i++)
    {
        static_cast<hkpBallGunListener*>(m_kListeners.m_data[i])->bulletCreatedCallback(bullet);
    }

    world->FUN_00c914d0(bullet, 1);

    CapacityGrowingArray<FUN_00ca8c90*>* addedBodies =
        static_cast<CapacityGrowingArray<FUN_00ca8c90*>*>(m_pBulletQueue);
    addedBodies->enqueue(bullet);

    if (static_cast<CapacityGrowingArray<FUN_00ca8c90*>*>(m_pBulletQueue)->GetLogicalSize() > m_iBulletBatchCount)
    {
        FUN_00ca8c90* rb;
        static_cast<CapacityGrowingArray<FUN_00ca8c90*>*>(m_pBulletQueue)->dequeue(rb);
        for (i = m_kListeners.m_iElementCount - 1; i >= 0; i--)
        {
            static_cast<hkpBallGunListener*>(m_kListeners.m_data[i])->bulletDeletedCallback(rb);
        }
        if (rb->m_pOwningWorld)
        {
            world->ProcessTarget(rb);
        }
        rb->FUN_00c905b0();
    }
}

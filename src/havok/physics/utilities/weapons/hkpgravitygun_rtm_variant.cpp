// src/havok/physics/utilities/weapons/hkpgravitygun_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpgravitygun.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpGravityGun.h"
struct FUN_00e45fb0_class
{
    void FUN_00e45e60(int);
    void FUN_00e45fb0(int, int, int);
};
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

extern double DAT_01012070;
extern "C" void _ReadWriteBarrier();
extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
    void _mm_store_ps(float*, __m128);
}
#pragma intrinsic(_mm_load_ss, _mm_load_ps, _mm_shuffle_ps, _mm_mul_ps, _mm_store_ss, _mm_store_ps)

struct UnkCall
{
    void FUN_00c9c1d0();
};

struct TargetBody
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
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C(hkVector4*);
};

struct Target : public UnkCall
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

    TargetBody body;

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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;

    hkVector4 unk1A0;
};

struct GravityGunQ
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
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    hkVector4 unk44;
    hkVector4 unk54;

    Target* FUN_00e45a60(hkVector4*, int, int);
    void FUN_00e46000(Target*);
};

struct ImpulseVector : hkVector4
{
    __forceinline void mul(float factor)
    {
        hkVector4& out = *this;
        __m128 scalar = _mm_load_ss(&factor);
        __m128 vector = _mm_load_ps((const float*)&out);
        __m128 broadcast = _mm_shuffle_ps(scalar, scalar, 0);
        _mm_store_ps((float*)&out, _mm_mul_ps(broadcast, vector));
    }
};

// @fnv 0x00e46080
void hkpGravityGunEx::FUN_00e46080(GunTransform* a4, GunArg3* a3, DDCC60World* world)
{
    hkVector4* direction = (hkVector4*)a4;
    int argC = (int)a3;
    int arg10 = (int)world;
    GravityGunQ* gq = (GravityGunQ*)this;
    Target* target = gq->FUN_00e45a60(direction, argC, arg10);

    if (target != 0)
    {
        __m128 massVector = _mm_load_ps((const float*)&target->unk1A0);
        massVector = _mm_shuffle_ps(massVector, massVector, 0xff);

        float mass;
        _mm_store_ss(&mass, massVector);

        if (!(gq->unk30 * mass < DAT_01012070))
        {
            if (gq->unk24 < gq->unk2C)
            {
                gq->FUN_00e46000(target);
                return;
            }
        }

        ImpulseVector impulse;
        _mm_store_ps((float*)&impulse, _mm_load_ps((const float*)direction));
        impulse.mul(-gq->unk38);
        target->FUN_00c9c1d0();
        target->body.vf4C(&impulse);
    }
}

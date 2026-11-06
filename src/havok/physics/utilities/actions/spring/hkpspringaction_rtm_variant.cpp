
// src/havok/physics/utilities/actions/spring/hkpspringaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/spring/hkpspringaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSpringAction.h"
extern int g_unk01269168;
int* __cdecl FUN_00cf4ef0();
void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);
struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};
struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};
struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};
struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};
struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};
struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};
class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};
struct FUN_00cf4d80
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
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
struct hkSimdRealD4D3
{
    __m128 m_vValue;

    hkSimdRealD4D3(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct hkTransformD4D3;
struct hkVector4D4D3
{
    __m128 m_vComponents;

    void FUN_00c7f690(const hkTransformD4D3& kT, const hkVector4D4D3& kV);
    void setSub4(const hkVector4D4D3& a, const hkVector4D4D3& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D3 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};
struct hkTransformD4D3
{
    hkVector4D4D3 m_rotation[3];
    hkVector4D4D3 m_vTranslation;
};
struct hkpEntityD4D3
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D3 m_kMotionTransform;
};
class hkBaseObjectD4D3
{
  public:
    virtual ~hkBaseObjectD4D3() throw();
};
class hkpStiffSpringWrapperD4D3 : public hkBaseObjectD4D3
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D3* m_pEntityA;
    hkpEntityD4D3* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D3 m_kPivotInA;
    hkVector4D4D3 m_kPivotInB;
    float m_fSpringRestLength;
};

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_load_ps1(const float*);
extern const float DAT_01017d00;
struct __declspec(align(16)) SpringVector
{
    __m128 q;
    __m128 get() const
    {
        return q;
    }
    void set(__m128 v)
    {
        q = v;
    }
    void __thiscall FUN_00c7f640(const void* transform, const hkVector4* local);
};
struct SpringMotion
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void apply(float dt, const hkVector4* force, const SpringVector* point);
};
class hkpEntity
{
  public:
    unsigned unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    SpringMotion motion;
    unsigned unkE4, unkE8, unkEC;
    hkTransform transform;
    void __thiscall FUN_00ca0c40(const SpringVector* point, SpringVector* velocity);
    void __thiscall FUN_00c9c1d0();
    void ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point)
    {
        FUN_00c9c1d0();
        motion.apply(dt, &force, &point);
    }
};
struct SpringStep
{
    float unk00, unk04, deltaTime;
};
struct SpringAction : hkpSpringAction
{
    void __thiscall applyAction(const SpringStep& step);
};
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    return z;
}
static float SpringLength3(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(dot3(v, v)));
    return r;
}
static float SpringDot3(__m128 a, __m128 b)
{
    float r;
    _mm_store_ss(&r, dot3(a, b));
    return r;
}
extern "C" __m128 _mm_set_ss(float);
static __m128 SpringSplat(float v)
{
    __m128 s = _mm_set_ss(v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" __m128 _mm_load_ss(const float*);
static __m128 SpringSplatRef(const float& v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" __m128 _mm_set_ps1(float);
static __m128 SpringSplatMem(float v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
static __m128 broadcast(float v)
{
    return _mm_load_ps1(&v);
}
// @fnv 0x00d4d530
void SpringAction::applyAction(const SpringStep& step)
{
    hkpEntity* a = m_pEntityA;
    hkpEntity* b = m_pEntityB;
    SpringVector pointA, pointB, direction, velocityA, velocityB;
    pointA.FUN_00c7f640(&a->transform, &m_kPositionA);
    pointB.FUN_00c7f640(&b->transform, &m_kPositionB);
    float tolerance = DAT_01017d00;
    __m128 displacement = _mm_sub_ps(pointB.get(), pointA.get());
    float length = SpringLength3(displacement);
    if (tolerance > length)
        return;
    direction.set(_mm_mul_ps(broadcast(1.0f / length), displacement));
    if (!m_bSpringEnabled && length < m_fRestLength)
        return;
    if (!m_bElastic && length > m_fRestLength)
        return;
    a->FUN_00ca0c40(&pointA, &velocityA);
    b->FUN_00ca0c40(&pointB, &velocityB);
    float force = (length - m_fRestLength) * m_fSpringStrength +
                  m_fMotorDamping * SpringDot3(_mm_sub_ps(velocityB.get(), velocityA.get()), direction.get());
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(-force), direction.get()));
    b->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointB);
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(force), direction.get()));
    a->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointA);
}

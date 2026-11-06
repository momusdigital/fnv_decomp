
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSphereMotion.h"
struct hkVector4D12
{
    float x, y, z, w;
};
struct hkMatrix3D12
{
    hkVector4D12 m_kColumn0;
    hkVector4D12 m_kColumn1;
    hkVector4D12 m_kColumn2;
};
template <class T> inline T hkMax2D12(T x, T y)
{
    return x > y ? x : y;
}
class hkpSphereMotionD12
{
  public:
    virtual ~hkpSphereMotionD12();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D12 m_kMotionState[11];
    hkVector4D12 m_kInertiaAndMassInv;

    void FUN_00d1e290(const hkMatrix3D12& inertia);
};
class hkpSphereMotion_L : public hkpMotion
{
  public:
    void SetInertiaAndMassInv(const float* param_2);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
struct hkVector4D1E41
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E41& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};
class hkBaseObjectD1E41
{
  public:
    virtual ~hkBaseObjectD1E41() throw();
};
class hkReferencedObjectD1E41 : public hkBaseObjectD1E41
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpSphereMotionD1E41 : public hkReferencedObjectD1E41
{
  public:
    void ApplyImpulse(const hkVector4D1E41& kImpulse, const hkVector4D1E41& kPos);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E41 m_motionState0[5];
    hkVector4D1E41 m_kCenterOfMass1;
    hkVector4D1E41 m_motionState1[5];
    hkVector4D1E41 m_kInertiaAndMassInv;
    hkVector4D1E41 m_kTranslationalVelocity;
    hkVector4D1E41 m_kAngularVelocity;
};
class hkVector4D1E4
{
  public:
    __m128 m_vComponents;
    void setMul4(const hkVector4D1E4& a, const hkVector4D1E4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};
class hkpSphereMotionD1E4
{
  public:
    virtual ~hkpSphereMotionD1E4();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_deactivationNumInactiveFrames0;
    unsigned short m_deactivationNumInactiveFrames1;
    unsigned short m_pad0e;
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
    hkVector4D1E4 m_kInertiaAndMassInv;
    hkVector4D1E4 m_kTranslationalVelocity;
    hkVector4D1E4 m_kAngularVelocity;
    const hkVector4D1E4& AddAngularImpulse(const hkVector4D1E4& imp);
};

extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_load_ps(const float*);
struct ScalarE4
{
    __m128 value;
    ScalarE4(float f) : value(_mm_load_ss(&f))
    {}
    ScalarE4(const __m128& v) : value(v)
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct VectorE4
{
    __m128 value;
    void scale(const ScalarE4& s, const VectorE4& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    void add(const VectorE4& v)
    {
        value = _mm_add_ps(value, v.value);
    }
};
struct SphereE4 : hkpSphereMotion
{
    void applyForce(float dt, const VectorE4& force);
    void impulse(const VectorE4& v)
    {
        VectorE4 change;
        __m128 mass = _mm_load_ps(&m_kInertiaAndMassInv.x);
        change.scale(ScalarE4(_mm_shuffle_ps(mass, mass, 255)), v);
        ((VectorE4&)m_kTranslationalVelocity).add(change);
    }
};
// @fnv 0x00d1e4d0
void SphereE4::applyForce(float dt, const VectorE4& force)
{
    VectorE4 v;
    ScalarE4 time(dt);
    _ReadWriteBarrier();
    v.scale(time, force);
    _ReadWriteBarrier();
    impulse(v);
}

extern "C" __m128 _mm_load_ss(const float* p);

struct FUN_00d1e520_cls
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void Dispatch(const __m128& t, int b);
    void applyForce(float f, const __m128* a, int b);
};

// @fnv 0x00d1e520
void FUN_00d1e520_cls::applyForce(float f, const __m128* a, int b)
{
    __m128 s = _mm_load_ss(&f);
    __m128 bc = _mm_shuffle_ps(s, s, 0);
    __m128 t = _mm_mul_ps(bc, *a);
    Dispatch(t, b);
}

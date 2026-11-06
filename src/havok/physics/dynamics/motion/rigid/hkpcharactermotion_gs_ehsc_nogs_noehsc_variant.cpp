
// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpcharactermotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpCharacterMotion.h"
struct hkVector4D1E
{
    float x, y, z, w;
};
struct hkMatrix3D1E
{
    hkVector4D1E m_kColumn0;
    hkVector4D1E m_kColumn1;
    hkVector4D1E m_kColumn2;
};
template <class T> inline T hkMax2D1E(T x, T y)
{
    return x > y ? x : y;
}
class hkpCharacterMotionD1E
{
  public:
    virtual ~hkpCharacterMotionD1E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E m_kMotionState[11];
    hkVector4D1E m_kInertiaAndMassInv;

    void SetInertiaAndMassInv(const hkMatrix3D1E& inertia);
};
struct FUN_00d1edd0_stub
{
    void SetMinOfThree(const float* src);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps();
struct hkVector4D1EE
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};
struct hkMatrix3D1EE
{
    hkVector4D1EE m_kColumn0;
    hkVector4D1EE m_kColumn1;
    hkVector4D1EE m_kColumn2;

    float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setDiagonal(float m00, float m11, float m22)
    {
        setZero();
        (*this)(0, 0) = m00;
        (*this)(1, 1) = m11;
        (*this)(2, 2) = m22;
    }
};
class hkBaseObjectD1EE
{
  public:
    virtual ~hkBaseObjectD1EE() throw();
};
class hkReferencedObjectD1EE : public hkBaseObjectD1EE
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpSphereMotionD1EE : public hkReferencedObjectD1EE
{
  public:
    void getInertiaInvLocal(hkMatrix3D1EE& kInertiaInv) const;

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1EE m_kMotionState[11];
    hkVector4D1EE m_kInertiaAndMassInv;
};

extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    float _mm_cvtss_f32(__m128);
}

struct S00d1f050_Obj : hkpCharacterMotion
{
    void getProjectedPointVelocity(const hkVector4* pos, const hkVector4* normal, float* out_vel, float* out_inv_mass) const;
};

// @fnv 0x00d1f050
void S00d1f050_Obj::getProjectedPointVelocity(const hkVector4* pos, const hkVector4* normal, float* out_vel,
                                 float* out_inv_mass) const
{
    __m128 com = _mm_load_ps((const float*)&m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    __m128 arm = _mm_sub_ps(_mm_load_ps((const float*)pos), com);
    __m128 n = _mm_load_ps((const float*)normal);
    __m128 lin = _mm_mul_ps(_mm_load_ps((const float*)&m_kTranslationalVelocity), n);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(n, n, 0xc9), _mm_shuffle_ps(arm, arm, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(n, n, 0xd2), _mm_shuffle_ps(arm, arm, 0xc9)));
    __m128 ang = _mm_mul_ps(_mm_load_ps((const float*)&m_kAngularVelocity), cross);
    __m128 a1 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0x55), ang);
    __m128 a2 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0xaa), a1);
    __m128 l1 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0x55), lin);
    __m128 l2 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0xaa), l1);
    __m128 sum = _mm_add_ss(a2, l2);
    float fv = _mm_cvtss_f32(sum);
    *out_vel = fv;
    *out_inv_mass = m_kInertiaAndMassInv.w;
}

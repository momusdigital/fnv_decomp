
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

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
extern "C" __m128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float*, __m128);
extern double DAT_010c9300;
extern float DAT_0104da4c;
struct FUN_00d1e1d0_cls : hkpSphereMotion
{
    void getInertiaLocal(int out);
};
extern "C" __m128 _mm_setzero_ps();
class SphereInverseWorld : public hkpSphereMotion
{
  public:
    void getInertiaInvWorld(hkMatrix3* out) const;
};
extern "C" __m128 _mm_setzero_ps();
struct TestMotion : public hkpSphereMotion
{
    void getInertiaInvLocal(hkMatrix3& inertiaInvOut);
};

extern "C" __m128 _mm_load_ss(const float* p);

struct hkSimdRealD1E5
{
    __m128 m_vValue;

    hkSimdRealD1E5(const float& f) : m_vValue(_mm_shuffle_ps(_mm_load_ss(&f), _mm_load_ss(&f), 0))
    {}
};

struct hkVector4D1E5
{
    __m128 m_vComponents;

    void setMul4(const hkSimdRealD1E5& s, const hkVector4D1E5& b)
    {
        m_vComponents = _mm_mul_ps(s.m_vValue, b.m_vComponents);
    }
};

class hkpMotionD1E5
{
  public:
    virtual ~hkpMotionD1E5() throw();
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
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void SetCollisionShape(const hkVector4D1E5& kImpulse);

    void FUN_00d1e560(float fMoveElapsedTime, const hkVector4D1E5& kForce);
};

// @fnv 0x00d1e560
void hkpMotionD1E5::FUN_00d1e560(float fMoveElapsedTime, const hkVector4D1E5& kForce)
{
    hkVector4D1E5 kImpulse;
    kImpulse.setMul4(fMoveElapsedTime, kForce);
    SetCollisionShape(kImpulse);
}

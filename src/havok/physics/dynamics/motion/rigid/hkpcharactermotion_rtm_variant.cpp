
// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

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
struct __declspec(align(16)) FUN_00d1ecc0_Matrix
{
    float m_Values[12];
};
struct FUN_00d1ecc0_Class
{
    unsigned char m_Padding[0xc0];
    float m_InertiaLocal;

    void getInertiaLocal(FUN_00d1ecc0_Matrix& inertia) const;
};
struct FUN_00d1ed00_t
{
    void GetInverseDiagonal(float* out);
};
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
struct hkSimdRealX
{
    __m128 m_vValue;
    hkSimdRealX(__m128 r) : m_vValue(r)
    {}
};
struct hkVector4X
{
    __m128 m_vComponents;

    hkSimdRealX getW() const
    {
        return hkSimdRealX(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
    }
    void addMul4(const hkSimdRealX& s, const hkVector4X& v)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), v.m_vComponents));
    }
    void setSub4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4X& v1, const hkVector4X& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    void setMul4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4X& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};
class hkpSphereMotionX
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4X m_kMotionTransform[4];
    hkVector4X m_vCenterOfMass0;
    hkVector4X m_vCenterOfMass1;
    hkVector4X m_rest[5];
    hkVector4X m_kInertiaAndMassInv;
    hkVector4X m_kTranslationalVelocity;
    hkVector4X m_kAngularVelocity;

    void applyPointImpulse(const hkVector4X& imp, const hkVector4X& p);
};
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
union Vector
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };
};
union Scalar
{
    __m128 quad;
    float real;
};
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_set_ps(float, float, float, float);
struct Simd
{
    __m128 quad;
};
union Vec
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };

    __forceinline void mulFloat(float s)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), quad);
    }
    __forceinline void setFloat(float s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), v.quad);
    }
    __forceinline void mulSimd(const Simd& s)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), quad);
    }
    __forceinline void setSimd(const Simd& s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad);
    }
    __forceinline void add(const Vec& v)
    {
        quad = _mm_add_ps(v.quad, quad);
    }
    __forceinline void addMul(const Simd& s, const Vec& v)
    {
        quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad), quad);
    }
    __forceinline Simd getW() const
    {
        Simd r;
        r.quad = _mm_shuffle_ps(quad, quad, 255);
        return r;
    }
};
class Motion
{
    hkVector4 m_00, m_10, m_20, m_30, m_40, m_50, m_60, m_70, m_80, m_90, m_a0, m_b0;
    Vec mass, velocity;

  public:
    void applyForce(float s, const Vec& force);
};

extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

class FUN_00d1efd0_cls
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20(hkVector4& out, int arg3);
    void applyForce(float s, const hkVector4& v, int arg3);
};

// @fnv 0x00d1efd0
void FUN_00d1efd0_cls::applyForce(float s, const hkVector4& v, int arg3)
{
    __declspec(align(16)) hkVector4 t;
    __m128 x = _mm_load_ss(&s);
    __m128 k = _mm_shuffle_ps(x, x, 0);
    __m128 r = _mm_mul_ps(k, _mm_load_ps(&v.x));
    _mm_store_ps(&t.x, r);
    this->v20(t, arg3);
}

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
class hkStatisticsCollector;
class CharacterTorqueMotion : public hkpCharacterMotion
{
  public:
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const;
    virtual void SetBodyMass(float);
    virtual void SetMassInv(float);
    virtual void GetInverseScaleMatrix(hkMatrix3&) const;
    virtual void GetInertiaLocal(hkMatrix3&) const;
    virtual void SetInertiaLocal(const hkMatrix3&);
    virtual void SetInertiaInvLocal(const hkMatrix3&);
    virtual void GetInertiaInvLocal(hkMatrix3&) const;
    virtual void GetLocalInverseInertia(hkMatrix3&) const;
    virtual void SetCenterOfMassInLocal(const hkVector4&);
    virtual void SetWorldPosition(const hkVector4&);
    virtual void SetBodyOrientation(const hkQuaternion&);
    virtual void SetPositionAndRotation(const hkVector4&, const hkQuaternion&);
    virtual void SetGeometryTransform(const hkTransform&);
    virtual void SetTranslationalVelocity(const hkVector4&);
    virtual void SetRotationalVelocity(const hkVector4&);
    virtual void GetProjectedPointVelocity(const hkVector4&, const hkVector4&, float&, float&) const;
    virtual void SetCollisionShape(const hkVector4&);
    virtual void ApplyImpulseAtPoint(const hkVector4&, const hkVector4&);
    virtual void ApplyAngularImpulseToBodies(const hkVector4&);
    void FUN_00d1f010(float step, const hkVector4& torque);
};
// @fnv 0x00d1f010
void CharacterTorqueMotion::FUN_00d1f010(float step, const hkVector4& torque)
{
    __declspec(align(16)) hkVector4 angularStep;
    __m128 scalar = _mm_load_ss(&step);
    __m128 scale = _mm_shuffle_ps(scalar, scalar, 0);
    _mm_store_ps(&angularStep.x, _mm_mul_ps(scale, _mm_load_ps(&torque.x)));
    ApplyAngularImpulseToBodies(angularStep);
}

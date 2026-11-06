
// src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpboxmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBoxMotion.h"

struct FUN_00d1e670_StandIn
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4(float) = 0;

    void setMass(float);
};

// @fnv 0x00d1e670
void FUN_00d1e670_StandIn::setMass(float value)
{
    f4(1.0f / value);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

struct Cls_00d1e7b0
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
    float m_c0;
    float m_c4;
    float m_c8;
    void WriteDiagonal(float* pOut);
};

// Zeroes 12 floats at pOut, then stores m_c0, m_c4 and m_c8 at pOut[0], pOut[5] and pOut[10].
// @fnv 0x00d1e7b0
void Cls_00d1e7b0::WriteDiagonal(float* pOut)
{
    float fDiag0 = m_c0;
    float fDiag1 = m_c4;
    float fDiag2 = m_c8;
    __m128 z = _mm_setzero_ps();
    ((__m128*)pOut)[0] = z;
    ((__m128*)pOut)[1] = z;
    ((__m128*)pOut)[2] = z;
    pOut[0] = fDiag0;
    pOut[5] = fDiag1;
    pOut[10] = fDiag2;
}

namespace fnv_00d1e810 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);

struct hkVector4D1E8
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
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

struct hkMatrix3D1E8
{
    hkVector4D1E8 m_kColumn0;
    hkVector4D1E8 m_kColumn1;
    hkVector4D1E8 m_kColumn2;

    const float& operator()(int r, int c) const
    {
        return (&m_kColumn0)[c](r);
    }
};

class hkBaseObjectD1E8
{
  public:
    virtual ~hkBaseObjectD1E8() throw();
};

class hkReferencedObjectD1E8 : public hkBaseObjectD1E8
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1E8 : public hkReferencedObjectD1E8
{
  public:
    void SetInertiaAndMassInv(const hkMatrix3D1E8& kInertiaInv);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E8 m_kMotionState[11];
    hkVector4D1E8 m_kInertiaAndMassInv;
};

// Stores the diagonal elements of kInertiaInv into m_kInertiaAndMassInv, preserving the fourth component.
// @fnv 0x00d1e810
void hkpSphereMotionD1E8::SetInertiaAndMassInv(const hkMatrix3D1E8& kInertiaInv)
{
    m_kInertiaAndMassInv.set(kInertiaInv(0, 0), kInertiaInv(1, 1), kInertiaInv(2, 2), m_kInertiaAndMassInv(3));
}
}  // namespace fnv_00d1e810

namespace fnv_00d1eba0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

class VectorComponentValue
{
  public:
    __m128 m_vValue;
    __forceinline VectorComponentValue()
    {}
    __forceinline VectorComponentValue(__m128 v) : m_vValue(v)
    {}
    __forceinline VectorComponentValue operator+(const VectorComponentValue& r) const
    {
        return VectorComponentValue(_mm_add_ss(m_vValue, r.m_vValue));
    }
    __forceinline operator hkReal() const
    {
        hkReal f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

class hkVector4A
{
  public:
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4A& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4A& a, const hkVector4A& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4A& a, const hkVector4A& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void setCross(const hkVector4A& v1, const hkVector4A& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline VectorComponentValue dot3(const hkVector4A& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return VectorComponentValue(_mm_add_ss(z, xySum));
    }

    __forceinline void _setRotatedInverseDir(const hkRotation& rotIn, const hkVector4A& b)
    {
        const hkVector4A* r = reinterpret_cast<const hkVector4A*>(&rotIn);
        __m128 c0 = r[0].m_vComponents;
        __m128 c1 = r[1].m_vComponents;
        __m128 c2 = r[2].m_vComponents;
        {
            __m128 tmp = _mm_unpacklo_ps(c0, c1);
            __m128 ctmp = _mm_unpackhi_ps(c0, c1);
            c0 = _mm_movelh_ps(tmp, c2);
            tmp = _mm_movehl_ps(c0, tmp);
            c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
            c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
        }
        const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        const __m128 r1 = _mm_mul_ps(b1, c1);
        const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        const __m128 r0 = _mm_mul_ps(b0, c0);
        const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        const __m128 r2 = _mm_mul_ps(c2, b2);
        m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
    }
};

__forceinline const hkVector4A& V(const hkVector4& v)
{
    return *reinterpret_cast<const hkVector4A*>(&v);
}

struct Cls_00d1eba0 : public hkpBoxMotion
{
    void GetVelocityAndInvVirtualMass(const hkVector4& p, const hkVector4& normal, hkReal& velOut,
                                      hkReal& invVirtMassOut) const;
};

// Computes the contact velocity and inverse virtual mass at point p with normal for a box motion body.
// @fnv 0x00d1eba0
void Cls_00d1eba0::GetVelocityAndInvVirtualMass(const hkVector4& p, const hkVector4& normal, hkReal& velOut,
                                                hkReal& invVirtMassOut) const
{
    hkVector4A arm;
    {
        hkVector4A relPos;
        relPos.setSub4(V(p), V(m_kMotionState.m_kSweptTransform.m_vCenterOfMass1));
        arm.setCross(relPos, V(normal));
    }
    velOut = V(m_kAngularVelocity).dot3(arm) + V(m_kTranslationalVelocity).dot3(V(normal));

    hkVector4A armLocal;
    armLocal._setRotatedInverseDir(m_kMotionState.m_kMotionTransform.m_rotation, arm);
    hkVector4A r;
    r.setMul4(V(m_kInertiaAndMassInv), armLocal);
    invVirtMassOut = m_kInertiaAndMassInv.w + r.dot3(armLocal);
}
}  // namespace fnv_00d1eba0

extern "C" __m128 _mm_max_ps(__m128, __m128);
extern __m128 DAT_010c7200;
struct V4
{
    __m128 q;
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
};
struct Mat3
{
    V4 c0, c1, c2;
    void FUN_00cd5880(const void* rot);
    float& operator()(int r, int c)
    {
        return (&c0)[c].q.m128_f32[r];
    }
    void setZero()
    {
        V4 z;
        z.setZero4();
        c0.q = z.q;
        c1.q = z.q;
        c2.q = z.q;
    }
    void setDiagonal(float a, float b, float c)
    {
        setZero();
        (*this)(0, 0) = a;
        (*this)(1, 1) = b;
        (*this)(2, 2) = c;
    }
};
struct BoxMotion
{
    int unk00, unk04, unk08, unk0C;
    hkTransform m_kMotionTransform;
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
    V4 m_kInertiaAndMassInv;
    void FUN_00d1e8c0(Mat3& out);
    void GetInverseScaleMatrix(Mat3& out)
    {
        V4 inv;
        inv.q = _mm_max_ps(m_kInertiaAndMassInv.q, DAT_010c7200);
        out.setDiagonal(1.0f / inv(0), 1.0f / inv(1), 1.0f / inv(2));
    }
};
// Writes the reciprocals of the clamped m_kInertiaAndMassInv x, y, z as a diagonal into out, then calls out.FUN_00cd5880 with m_kMotionTransform.
// @fnv 0x00d1e8c0
void BoxMotion::FUN_00d1e8c0(Mat3& out)
{
    V4 inv;
    inv.q = _mm_max_ps(m_kInertiaAndMassInv.q, DAT_010c7200);
    out.setDiagonal(1.0f / inv(0), 1.0f / inv(1), 1.0f / inv(2));
    out.FUN_00cd5880(&m_kMotionTransform);
}

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
}

typedef __m128 hkSimd;

struct hkVec4Q
{
    __m128 m_vComponents;

    __forceinline hkSimd getSimdAt(int) const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void addMul4(hkSimd r, const hkVec4Q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents));
    }
    __forceinline void setSub4(const hkVec4Q& a, const hkVec4Q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setCross(const hkVec4Q& v1, const hkVec4Q& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setMul4(const hkVec4Q& a, const hkVec4Q& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVec4Q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void _setRotatedDir(const struct hkMat3Q& r, const hkVec4Q& b);
    void _setRotatedInverseDir(const struct hkMat3Q& r, const hkVec4Q& b);
};

struct hkMat3Q
{
    hkVec4Q m_kColumn0, m_kColumn1, m_kColumn2;
};

__forceinline void hkVec4Q::_setRotatedDir(const hkMat3Q& r, const hkVec4Q& b)
{
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVec4Q::_setRotatedInverseDir(const hkMat3Q& r, const hkVec4Q& b)
{
    __m128 c0 = r.m_kColumn0.m_vComponents;
    __m128 c1 = r.m_kColumn1.m_vComponents;
    __m128 c2 = r.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = ctmp;

    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct hkpMotionB
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    hkMat3Q m_rotation;      // 0x10
    hkVec4Q m_vTranslation;  // 0x40
    hkVec4Q m_com0;          // 0x50
    hkVec4Q m_com1;          // 0x60
    hkVec4Q unk70;
    hkVec4Q unk80;
    hkVec4Q unk90;
    hkVec4Q unka0;
    hkVec4Q unkb0;
    hkVec4Q m_kInertiaAndMassInv;      // 0xc0
    hkVec4Q m_kTranslationalVelocity;  // 0xd0
    hkVec4Q m_kAngularVelocity;        // 0xe0

    void applyPointImpulse(const hkVec4Q& imp, const hkVec4Q& p);
};

// Adds translational and angular velocity changes to the rigid body from an impulse imp applied at point p.
// @fnv 0x00d1e9f0
void hkpMotionB::applyPointImpulse(const hkVec4Q& imp, const hkVec4Q& p)
{
    m_kTranslationalVelocity.addMul4(m_kInertiaAndMassInv.getSimdAt(3), imp);

    hkVec4Q relPos;
    relPos.setSub4(p, m_com1);
    hkVec4Q crossWs;
    crossWs.setCross(relPos, imp);
    hkVec4Q crossLs;
    crossLs._setRotatedInverseDir(m_rotation, crossWs);
    hkVec4Q deltaVelLs;
    deltaVelLs.setMul4(m_kInertiaAndMassInv, crossLs);
    hkVec4Q deltaVelWs;
    deltaVelWs._setRotatedDir(m_rotation, deltaVelLs);
    m_kAngularVelocity.add4(deltaVelWs);
}

extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" void _ReadWriteBarrier(void);
extern "C" __m128 _mm_load_ps(const float*);
struct Mat
{
    __m128 c0, c1, c2;
};
struct Vec
{
    __m128 q;
};
struct Motion
{
    void applyAngularImpulse(const Vec& impulse);
};
// Transforms impulse through the rotation matrix, scales by inverse inertia, and accumulates into the angular velocity at offset 0xe0.
// @fnv 0x00d1eaf0
void Motion::applyAngularImpulse(const Vec& impulse)
{
    const Mat& r = *(const Mat*)((char*)this + 0x10);
    __m128 a = r.c0, b = r.c1, c = r.c2;
    __m128 tmp = _mm_unpacklo_ps(a, b);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(tmp, c);
    tmp = _mm_movehl_ps(a, tmp);
    b = _mm_shuffle_ps(tmp, c, 0xd4);
    c = ctmp;
    __m128 vResult;
    vResult = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(impulse.q, impulse.q, 0x00), a),
                                    _mm_mul_ps(_mm_shuffle_ps(impulse.q, impulse.q, 0x55), b)),
                         _mm_mul_ps(_mm_shuffle_ps(impulse.q, impulse.q, 0xaa), c));
    vResult = _mm_mul_ps(vResult, ((const Vec*)((char*)this + 0xc0))->q);
    vResult = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0x00), _mm_load_ps((const float*)((char*)this + 0x10))),
                   _mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0x55), _mm_load_ps((const float*)((char*)this + 0x20)))),
        _mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0xaa), _mm_load_ps((const float*)((char*)this + 0x30))));
    __m128& acc = ((Vec*)((char*)this + 0xe0))->q;
    acc = _mm_add_ps(acc, vResult);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern const char DAT_010c6dc4[];
extern const float DAT_01012068;

struct FUN_00c86530_Obj
{
    virtual ~FUN_00c86530_Obj();
    FUN_00c86530_Obj(int a1, int a2, int a3);
};

struct S00d1e690_cls : hkpMotion
{
    S00d1e690_cls* FUN_00d1e690(int a1, int a2);
};

// Constructs the object in place via FUN_00c86530_Obj, sets m_kInertiaAndMassInv to DAT_01012068, and assigns m_type to 3.
// @fnv 0x00d1e690
S00d1e690_cls* S00d1e690_cls::FUN_00d1e690(int a1, int a2)
{
    __assume(this != 0);
    new (this) FUN_00c86530_Obj(a1, a2, 0);
    *(__m128*)&m_kInertiaAndMassInv = _mm_setr_ps(DAT_01012068, DAT_01012068, DAT_01012068, DAT_01012068);
    *(const char**)this = DAT_010c6dc4;
    m_type = 3;
    return this;
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

struct S00d1e750_cls : hkpMotion
{
    const hkMatrix3& FUN_00d1e750(const hkMatrix3& inertia);
};

// Stores the reciprocals of the diagonal entries of inertia into m_kInertiaAndMassInv and returns the inertia matrix.
// @fnv 0x00d1e750
const hkMatrix3& S00d1e750_cls::FUN_00d1e750(const hkMatrix3& inertia)
{

    float f[3];
    f[0] = 1.0f / inertia.m_kColumn0.x;
    f[1] = 1.0f / inertia.m_kColumn1.y;
    f[2] = 1.0f / inertia.m_kColumn2.z;
    *(__m128*)&m_kInertiaAndMassInv = _mm_setr_ps(f[0], f[1], f[2], m_kInertiaAndMassInv.w);
    return inertia;
}

extern "C" void _ReadWriteBarrier(void);

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern const float DAT_0104da4c;

struct hkVector4D1E6F
{
    __m128 m_vComponents;

    hkVector4D1E6F()
    {}
    hkVector4D1E6F(const hkVector4D1E6F& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D1E6F& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setMax4(const hkVector4D1E6F& a, const hkVector4D1E6F& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }
    static hkVector4D1E6F all(const float& f)
    {
        hkVector4D1E6F v;
        v.SetAllComponents(f);
        return v;
    }
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

struct hkMatrix3D1E6F
{
    hkVector4D1E6F m_kColumn0;
    hkVector4D1E6F m_kColumn1;
    hkVector4D1E6F m_kColumn2;

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

class hkBaseObjectD1E6F
{
  public:
    virtual ~hkBaseObjectD1E6F() throw();
};

class hkReferencedObjectD1E6F : public hkBaseObjectD1E6F
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1E6F : public hkReferencedObjectD1E6F
{
  public:
    void getInertiaLocal(hkMatrix3D1E6F& kInertiaInv) const;

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E6F m_kMotionState[11];
    hkVector4D1E6F m_kInertiaAndMassInv;
};

// Clamps m_kInertiaAndMassInv components to a minimum, then writes their reciprocals to the diagonal of kInertiaInv.
// @fnv 0x00d1e6f0
void hkpSphereMotionD1E6F::getInertiaLocal(hkMatrix3D1E6F& kInertiaInv) const
{
    __declspec(align(16)) float afInertia[4];
    __m128 m = m_kInertiaAndMassInv.m_vComponents;
    _ReadWriteBarrier();
    _mm_store_ps(afInertia, _mm_max_ps(_mm_load_ps1(&DAT_0104da4c), m));
    kInertiaInv.setDiagonal(1.0f / afInertia[0], 1.0f / afInertia[1], 1.0f / afInertia[2]);
}

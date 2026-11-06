
// src/havok/physics/dynamics/motion/rigid/hkpboxmotion_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

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
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct S00d1e750_cls : hkpMotion
{
    const hkMatrix3& FUN_00d1e750(const hkMatrix3& inertia);
};
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

extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

class FUN_00d1e970_cls
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

// @fnv 0x00d1e970
void FUN_00d1e970_cls::applyForce(float s, const hkVector4& v, int arg3)
{
    __declspec(align(16)) hkVector4 t;
    __m128 x = _mm_load_ss(&s);
    __m128 k = _mm_shuffle_ps(x, x, 0);
    __m128 r = _mm_mul_ps(k, _mm_load_ps(&v.x));
    _mm_store_ps(&t.x, r);
    this->v20(t, arg3);
}

extern "C" __m128 _mm_load_ss(const float*);

struct FUN_00d1e9b0_cls
{
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
    virtual void v20();
    virtual void v21(float* pOut);
    void FUN_00d1e9b0(float f, float* v);
};

// @fnv 0x00d1e9b0
void FUN_00d1e9b0_cls::FUN_00d1e9b0(float f, float* v)
{
    __declspec(align(16)) float out[4];
    float* pOut = out;
    __m128 splat = _mm_shuffle_ps(_mm_load_ss(&f), _mm_load_ss(&f), 0);
    __m128 vec = _mm_load_ps(v);
    *(__m128*)pOut = _mm_mul_ps(splat, vec);
    v21(pOut);
}

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_mul_ps(__m128, __m128);
}
}

extern "C" void _ReadWriteBarrier();
class BoxMotionCandidate : public hkpBoxMotion
{
  public:
    void applyForce(float amount, const hkVector4* direction);
};
// @fnv 0x00d1e920
void BoxMotionCandidate::applyForce(float amount, const hkVector4* direction)
{
    N::__m128 a = N::_mm_load_ss(&amount);
    a = N::_mm_shuffle_ps(a, a, 0);
    _ReadWriteBarrier();
    N::__m128 d = N::_mm_load_ps(&direction->x);
    N::__m128 p = N::_mm_mul_ps(a, d);
    _ReadWriteBarrier();
    N::__m128 m = *(const N::__m128*)&m_kInertiaAndMassInv;
    N::__m128 w = N::_mm_shuffle_ps(m, m, 255);
    N::__m128 b = N::_mm_shuffle_ps(w, w, 0);
    N::__m128 r = N::_mm_mul_ps(b, p);
    N::__m128 v = *(const N::__m128*)&m_kTranslationalVelocity;
    r = N::_mm_add_ps(r, v);
    *(N::__m128*)&m_kTranslationalVelocity = r;
}

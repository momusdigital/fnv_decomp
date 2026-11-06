
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e41080_Obj
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

    float __thiscall GetUnk30();
};

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);

template <class T, class U> __forceinline void fnv_vstore(T& d, U v)
{
    *(volatile T*)&d = (T)v;
}

struct __declspec(align(16)) Projection363_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char flag10;
    unsigned char flag11;
    unsigned char flag12;
    unsigned char flag13;
    int unk14;
    int unk18;
    int unk1C;
    __m128 vec20;
    __m128 vec30;
};

struct Projection363_Input
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Projection363_Helper
{
    __m128 rotation;
    int FUN_00cb2ca0(void* p, Vec4* f2, float* f1);
};

__forceinline __m128 Dot363(const __m128& a, const __m128& b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 p = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 q = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), p);
    return _mm_shuffle_ps(q, q, 0);
}
__forceinline __m128 Project363(const __m128& v, const __m128& axis)
{
    return _mm_mul_ps(Dot363(v, axis), axis);
}
__forceinline __m128 Cross363(const __m128& v1, const __m128& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
struct OutVec
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const __m128& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v);
    }
};

struct Motion363
{
    __m128 vector;
    Projection363_Helper angular;
};

// @fnv 0x00e41220
void FUN_00e41220(Projection363_Owner* a, Motion363* __restrict b, Projection363_Input* c, OutVec* out)
{
    __m128 A = a->vec20;
    const __m128& v = b->vector;
    __m128 T2 = Project363(v, A);
    __m128 T4 = Project363(v, (Cross363(a->vec20, a->vec30)));
    __m128 T1 = Project363(v, a->vec30);
    out->setZero4();
    if (a->flag11 != 0)
    {
        out->add4(T1);
    }
    if (a->flag10 != 0)
    {
        out->add4(T2);
    }
    if (a->flag12 != 0)
    {
        out->add4(T4);
    }
    if (a->flag13 != 0)
    {
        float f1;
        Vec4 f2;
        Projection363_Helper* h = &b->angular;
        h->FUN_00cb2ca0(&a->vec20, &f2, &f1);
        float target = c->unk0C;
        const double PI = 3.14159265358979323846f;
        const double TWO_PI = 6.28318530717958647692f;
        while (f1 - target > PI)
        {
            f1 -= TWO_PI;
        }
        while (f1 - target < -PI)
        {
            f1 += TWO_PI;
        }
        out->m_vComponents.m128_f32[3] = f1;
    }
    else
    {
        out->m_vComponents.m128_f32[3] = 0.0f;
    }
}

struct VectorComponentValue
{
    __m128 value;
    VectorComponentValue(const __m128& v) : value(v)
    {}
    const __m128& getQuad() const
    {
        return value;
    }
};
struct hkQuaternion;
struct hkVector4
{
    __m128 v;
    hkVector4()
    {}
    hkVector4(const hkVector4& a) : v(a.v)
    {}
    void operator=(const hkVector4& a)
    {
        v = a.v;
    }
    __m128& getQuad()
    {
        return v;
    }
    const __m128& getQuad() const
    {
        return v;
    }
    operator __m128() const
    {
        return v;
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_add_ps(a.v, b.v);
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    void setMul4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_mul_ps(a.v, b.v);
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c)
    {
        v = _mm_add_ps(a.v, _mm_mul_ps(b.v, c.v));
    }
    void addMul4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_add_ps(v, _mm_mul_ps(a.v, b.v));
    }
    void add4(const hkVector4& a)
    {
        v = _mm_add_ps(v, a.v);
    }
    void sub4(const hkVector4& a)
    {
        v = _mm_sub_ps(v, a.v);
    }
    void SetAllComponents(float a)
    {
        v = _mm_set1_ps(a);
    }
    void SetAllComponents(const VectorComponentValue& a)
    {
        v = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
    }
    void broadcast(int i)
    {
        if (i == 0)
            v = _mm_shuffle_ps(v, v, 0);
        else if (i == 1)
            v = _mm_shuffle_ps(v, v, 0x55);
        else if (i == 2)
            v = _mm_shuffle_ps(v, v, 0xaa);
        else if (i == 3)
            v = _mm_shuffle_ps(v, v, 0xff);
    }
    void setBroadcast(const hkVector4& a, int i)
    {
        if (i == 0)
            v = _mm_shuffle_ps(a.v, a.v, 0);
        else if (i == 1)
            v = _mm_shuffle_ps(a.v, a.v, 0x55);
        else if (i == 2)
            v = _mm_shuffle_ps(a.v, a.v, 0xaa);
        else if (i == 3)
            v = _mm_shuffle_ps(a.v, a.v, 0xff);
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 prod = _mm_mul_ps(v, a.v);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
    }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));
        v = _mm_sub_ps(first, second);
    }
    void setXYZW(const hkVector4& a, const hkVector4& b)
    {
        __m128 high = _mm_unpackhi_ps(a.v, b.v);
        v = _mm_shuffle_ps(a.v, high, 0xc4);
    }
    void setReciprocal3(const hkVector4& a);
    void setXYZ0(const hkVector4& a);
    void setNeg4(const hkVector4& a);
    void setNeg3(const hkVector4& a);
    __forceinline void SetRotatedDirection(const hkQuaternion& q, const hkVector4& direction);
    __forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& direction);
};
extern const hkVector4 DAT_010c71e0, DAT_010c7170;
extern const hkVector4 DAT_010c4c10, DAT_010c4c00, DAT_010c44d0;
inline __m128 reciprocal(__m128 x)
{
    __m128 r = _mm_rcp_ps(x);
    return _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, x), r));
}
inline void hkVector4::setReciprocal3(const hkVector4& a)
{
    hkVector4 one;
    one.getQuad() = DAT_010c7170.getQuad();
    hkVector4 joined;
    joined.setXYZW(a, one);
    v = reciprocal(joined.v);
}
inline void hkVector4::setXYZ0(const hkVector4& a)
{
    v = _mm_and_ps(a, DAT_010c4c10.v);
}
inline void hkVector4::setNeg4(const hkVector4& a)
{
    v = _mm_xor_ps(a.v, DAT_010c44d0.v);
}
inline void hkVector4::setNeg3(const hkVector4& a)
{
    v = _mm_xor_ps(a.v, DAT_010c4c00.v);
}
struct hkQuaternion
{
    hkVector4 m_vec;
    const hkVector4& getImag() const
    {
        return m_vec;
    }
    void SetConjugate(const hkQuaternion& q)
    {
        m_vec.setNeg3(q.getImag());
    }
    void FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b);
};
inline void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVector4 imaginary;
    imaginary.setCross(a.getImag(), b.getImag());
    hkVector4 aw;
    aw.setBroadcast(a.m_vec, 3);
    hkVector4 bw;
    bw.setBroadcast(b.m_vec, 3);
    imaginary.addMul4(aw, b.getImag());
    imaginary.addMul4(bw, a.getImag());
    hkVector4 dot;
    dot.SetAllComponents(a.m_vec.dot3(b.m_vec));
    hkVector4 product;
    product.setMul4(a.m_vec, b.m_vec);
    product.sub4(dot);
    m_vec.setXYZW(imaginary, product);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0.getQuad();
    hkVector4 real;
    real.setBroadcast(q.m_vec, 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(q.getImag(), direction);
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0.getQuad();
    hkVector4 real;
    real.setBroadcast(q.m_vec, 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(direction, q.getImag());
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
struct hkTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
    __forceinline hkTransform()
    {}
    __forceinline void SetConjugate(const hkTransform& a)
    {
        m_vTranslation.setRotatedInverseDir(a.m_rotation, a.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(a.m_rotation);
        hkVector4 scale;
        scale.setReciprocal3(a.m_vScale);
        m_vScale.setXYZ0(scale);
    }
    __forceinline void SetProduct(const hkTransform& a, const hkTransform& b)
    {
        hkVector4 shift;
        shift.SetRotatedDirection(a.m_rotation, b.m_vTranslation);
        m_vTranslation.setAdd4(a.m_vTranslation, shift);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.setMul4(a.m_vScale, b.m_vScale);
    }
    __forceinline void SetMulInverse(const hkTransform& a, const hkTransform& b)
    {
        hkTransform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};
struct AnimatedFrame
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void EvaluateTransform(float time, hkTransform& out) const;
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float m_fAnimationDuration;
    void getDeltaReferenceFrame(float time, float nextTime, int loops, hkTransform& output) const;
};
// @fnv 0x00e413d0
void AnimatedFrame::getDeltaReferenceFrame(float time, float nextTime, int loops, hkTransform& output) const
{
    hkTransform start;
    EvaluateTransform(time, start);
    hkTransform next;
    EvaluateTransform(nextTime, next);
    if (loops != 0)
    {
        hkTransform cycle;
        EvaluateTransform(m_fAnimationDuration, cycle);
        const unsigned count = loops < 0 ? -loops : loops;
        for (unsigned i = 0; i < count; ++i)
        {
            if (loops < 0)
            {
                hkTransform temp;
                temp.SetMulInverse(cycle, next);
                next = temp;
            }
            else
            {
                hkTransform temp;
                temp.SetProduct(cycle, next);
                next = temp;
            }
        }
    }
    output.SetMulInverse(start, next);
    output.m_vScale.SetAllComponents(1.0f);
}

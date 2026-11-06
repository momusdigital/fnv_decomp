// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
void FUN_00e41220(Projection363_Owner* a, Motion363* __restrict b, Projection363_Input* c, OutVec* out);
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

extern __m128 DAT_010ec7f0;

struct __declspec(align(16)) S00e41100_Vec4
{
    float m_v[4];
    __m128 getQuad() const
    {
        return _mm_load_ps(m_v);
    }
    void setQuad(__m128 q)
    {
        _mm_store_ps(m_v, q);
    }
};

struct S00e41100_Quat
{
    S00e41100_Vec4 m_vec;
    void FUN_00cb2450(const S00e41100_Vec4& axis, float angle);
};

struct S00e41100_hkQsTransform
{
    S00e41100_Vec4 m_vTranslation;
    S00e41100_Quat m_rotation;
    S00e41100_Vec4 m_vScale;
};

struct S00e41100_LinearKeyTrack
{
    virtual ~S00e41100_LinearKeyTrack();
    S00e41100_Vec4 m_kAxisEndPoints;
    S00e41100_Vec4 m_unk20;
    float m_fAnimationDuration;
    S00e41100_Vec4* m_keys;
    int m_numKeys;
    int m_iCapacityState;

    void getReferenceFrame(float time, S00e41100_hkQsTransform& out);
};

// @fnv 0x00e41100
void S00e41100_LinearKeyTrack::getReferenceFrame(float time, S00e41100_hkQsTransform& out)
{
    int last = m_numKeys - 1;
    float dt = m_fAnimationDuration / last;
    __m128 v;
    if (time >= m_fAnimationDuration)
    {
        v = m_keys[m_numKeys - 1].getQuad();
    }
    else if (time < 0.0f)
    {
        v = m_keys[0].getQuad();
    }
    else
    {
        int i = (int)(time / dt);
        if (i == last)
        {
            i--;
        }
        float f = time / dt - i;
        S00e41100_Vec4 a = m_keys[i];
        S00e41100_Vec4 b = m_keys[i + 1];
        __m128 t = _mm_load_ss(&f);
        t = _mm_shuffle_ps(t, t, 0);
        v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), a.getQuad()), _mm_mul_ps(b.getQuad(), t));
    }
    out.m_vTranslation.setQuad(v);
    out.m_rotation.FUN_00cb2450(m_kAxisEndPoints, v.m128_f32[3]);
    out.m_vScale.setQuad(_mm_set_ps1(1.0f));
}

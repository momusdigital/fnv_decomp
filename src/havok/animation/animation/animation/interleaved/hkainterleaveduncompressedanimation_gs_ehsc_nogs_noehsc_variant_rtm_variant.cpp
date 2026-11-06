// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaInterleavedUncompressedAnimation.h"
struct FUN_00e3f950_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int getNumDataChunks(int a, int b);
};
struct FUN_00e3f970_class
{
    int getMaxSizeOfCombinedDataChunks();
};
struct FUN_00e3f990_class
{
    int GetRatio();
};
struct FUN_00e3f920_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FUN_00e3f920(float, int, int, int);
};
#include <xmmintrin.h>
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
class hkQuaternionE40;
class hkVector4E40
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4E40& operator=(const hkVector4E40& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4E40& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4E40& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4E40& v1, const hkVector4E40& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4E40& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4E40& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionE40& q, const hkVector4E40& dir);
    void setRotatedInverseDir(const hkQuaternionE40& q, const hkVector4E40& dir);
};
class hkQuaternionE40
{
  public:
    hkVector4E40 m_vec;

    __forceinline void SetConjugate(const hkQuaternionE40& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionE40& q0, const hkQuaternionE40& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};
__forceinline void hkVector4E40::SetRotatedDirection(const hkQuaternionE40& quat, const hkVector4E40& direction)
{
    hkVector4E40 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4E40 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4E40 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4E40 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}
__forceinline void hkVector4E40::setRotatedInverseDir(const hkQuaternionE40& quat, const hkVector4E40& direction)
{
    hkVector4E40 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4E40 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4E40 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4E40 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}
class hkQsTransformE40
{
  public:
    hkVector4E40 m_vTranslation;
    hkQuaternionE40 m_rotation;
    hkVector4E40 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformE40& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4E40 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformE40& t1, const hkQsTransformE40& t2)
    {
        hkVector4E40 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};
class FUN_00e401d0Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iNumTracks;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    hkQsTransformE40* m_pkTransforms;
    int m_iNumTransforms;

    void FUN_00e401d0(int iTrack, const hkQsTransformE40& kTransform);
};

extern const __m128 DAT_010c7160;
extern const __m128 DAT_010ec7f0;

class S00e3f9b0_SimdReal
{
  public:
    S00e3f9b0_SimdReal(const __m128& x) : m_vValue(x)
    {}
    S00e3f9b0_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    S00e3f9b0_SimdReal()
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

inline S00e3f9b0_SimdReal operator-(const S00e3f9b0_SimdReal& r)
{
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}

class S00e3f9b0_Vec4
{
  public:
    __forceinline S00e3f9b0_Vec4()
    {}
    __forceinline S00e3f9b0_Vec4(const S00e3f9b0_Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00e3f9b0_Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setMul4(const S00e3f9b0_SimdReal& r, const S00e3f9b0_Vec4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    __forceinline void addMul4(const S00e3f9b0_SimdReal& r, const S00e3f9b0_Vec4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline void setInterpolate4(const S00e3f9b0_Vec4& v0, const S00e3f9b0_Vec4& v1, const S00e3f9b0_SimdReal& _t)
    {
        __m128 t = _t.broadcast();
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(v1.m_vComponents, t));
    }
    inline S00e3f9b0_SimdReal dot4(const S00e3f9b0_Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
        __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    __m128 m_vComponents;
};

class S00e3f9b0_Quat
{
  public:
    inline S00e3f9b0_Quat()
    {}
    inline void operator=(const S00e3f9b0_Quat& q)
    {
        m_vec = q.m_vec;
    }
    void FUN_005611c0();
    S00e3f9b0_Vec4 m_vec;
};

class S00e3f9b0_QsT
{
  public:
    __forceinline S00e3f9b0_QsT(const S00e3f9b0_QsT& t)
    {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
    __forceinline void setInterpolate4(const S00e3f9b0_QsT& a, const S00e3f9b0_QsT& b, const S00e3f9b0_SimdReal& t)
    {
        const __m128 ts = t.broadcast();
        m_vScale.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ts), a.m_vScale.m_vComponents),
                                            _mm_mul_ps(ts, b.m_vScale.m_vComponents));
        m_vTranslation.setInterpolate4(a.m_vTranslation, b.m_vTranslation, t);

        const float oneMinusT = 1.0f - float(t);

        const float signedT = (a.m_rotation.m_vec.dot4(b.m_rotation.m_vec) < 0.0f) ? -t : t;

        S00e3f9b0_Quat out;
        S00e3f9b0_Vec4 v;
        v.setMul4(S00e3f9b0_SimdReal(signedT), b.m_rotation.m_vec);
        v.addMul4(S00e3f9b0_SimdReal(oneMinusT), a.m_rotation.m_vec);
        out.m_vec = v;
        out.FUN_005611c0();

        m_rotation = out;
    }
    S00e3f9b0_Vec4 m_vTranslation;
    S00e3f9b0_Quat m_rotation;
    S00e3f9b0_Vec4 m_vScale;
};

struct S00e3f9b0_Anim : public hkaInterleavedUncompressedAnimation
{
    void FUN_00e2f7c0(float time, int& frame, float& delta) const;
    void sampleIndividualTransformTracks(float time, const short* tracks, unsigned int numTracks, S00e3f9b0_QsT* transformsOut) const;
};

// @fnv 0x00e3f9b0
void S00e3f9b0_Anim::sampleIndividualTransformTracks(float time, const short* tracks, unsigned int numTracks,
                                  S00e3f9b0_QsT* transformsOut) const
{
    int frame;
    float delta;
    FUN_00e2f7c0(time, frame, delta);

    for (unsigned int i = 0; i < numTracks; ++i)
    {
        const short track = tracks[i];
        if (track < 0 || track >= m_iNumTransformTracks)
        {
            continue;
        }
        const S00e3f9b0_QsT* base = (const S00e3f9b0_QsT*)m_kTransforms.m_data + m_iNumTransformTracks * frame;
        S00e3f9b0_QsT a = base[track];
        S00e3f9b0_QsT b = base[track + m_iNumTransformTracks];
        transformsOut[i].setInterpolate4(a, b, delta);
    }
}

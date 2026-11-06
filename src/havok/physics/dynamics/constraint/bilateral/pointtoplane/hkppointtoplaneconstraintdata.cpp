
// src/havok/physics/dynamics/constraint/bilateral/pointtoplane/hkppointtoplaneconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtoplane/hkppointtoplaneconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPointToPlaneConstraintData.h"

// Sets b[0] and b[1] to 8 and 1 when a is nonzero, otherwise to 0 and 0.
// @fnv 0x00d84780
void __stdcall getRuntimeInfo(unsigned char a, int* pData)
{
    if (a)
    {
        pData[1] = 1;
        pData[0] = 8;
    }
    else
    {
        pData[1] = 0;
        pData[0] = 0;
    }
}

extern "C" void* __cdecl FUN_00d21a60(void*, int, int);

struct FUN_00d84760
{
    void* PopulateInfo(int a);
};

// @fnv 0x00d84760
void* FUN_00d84760::PopulateInfo(int a)
{
    return FUN_00d21a60((char*)this + 0x10, 0x94, a);
}

// @fnv 0x00d847b0
int __cdecl FUN_00d847b0()
{
    return 14;
}

struct ValidationResult
{
    unsigned char value;
    ValidationResult(bool result) : value(result)
    {}
};
struct Transform
{
    ValidationResult IsTransformValid(float tolerance);
};
struct FUN_00d84b70
{
    ValidationResult CheckValid();
};
// Returns true if the Transform at offset 0x20 and the one at offset 0x60 both pass a 0.001 tolerance validation.
// @fnv 0x00d84b70
ValidationResult FUN_00d84b70::CheckValid()
{
    Transform* pFirstTransform = (Transform*)((char*)this + 0x20);
    Transform* pSecondTransform = (Transform*)((char*)this + 0x60);
    return pFirstTransform->IsTransformValid(0.001f).value && pSecondTransform->IsTransformValid(0.001f).value;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d847c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Vec_d849a0
{
    __m128 q;
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
    __forceinline void normalize3()
    {
        __m128 v = q;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
        __m128 t = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e));
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), t);
        r = _mm_andnot_ps(mask, r);
        q = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v);
    }
    void setCross(const Vec_d849a0& a, const Vec_d849a0& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

static inline float Abs_d849a0(float r)
{
    return (float)fabs(r);
}

static __forceinline void Perp_d849a0(const Vec_d849a0& vectorIn, Vec_d849a0& biVectorOut)
{
    int minIdx = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = Abs_d849a0(vectorIn(0));
    float a1 = Abs_d849a0(vectorIn(1));
    float a2 = Abs_d849a0(vectorIn(2));
    if (a1 < a0)
    {
        ok1 = 0;
        minIdx = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ok2 = minIdx;
        minIdx = 2;
    }
    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

struct Rot_d849a0
{
    Vec_d849a0 col0;
    Vec_d849a0 col1;
    Vec_d849a0 col2;
    Vec_d849a0& getColumn(int i)
    {
        return (&col0)[i];
    }
};

struct Out_d847c0 : public Vec_d849a0
{
    void setRotatedInverseDir(const Rot_d849a0& r, const Vec_d849a0& v);
};

struct Trans_d847c0
{
    Rot_d849a0 m_rotation;
    Vec_d849a0 m_vTranslation;
};

struct Pos_d847c0 : public Vec_d849a0
{
    void SetTransformedPosition(const Trans_d847c0& t, const Vec_d849a0& v);
};

struct PointToPlane_d847c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec_d849a0 m_20;
    Vec_d849a0 m_30;
    Vec_d849a0 m_40;
    Pos_d847c0 m_50;
    Rot_d849a0 m_60;
    Pos_d847c0 m_90;
    unsigned short unkA0;
    unsigned char m_a2;
    void SetFromTransforms(const Trans_d847c0& bodyA, const Trans_d847c0& bodyB, const Vec_d849a0& pivot,
                           const Vec_d849a0& normal);
};

// Stores pivot transformed by each body into m_50 and m_90, resets m_20/m_30/m_40 to unit axes, and builds m_60 from normal and bodyB's rotation.
// @fnv 0x00d847c0
void PointToPlane_d847c0::SetFromTransforms(const Trans_d847c0& bodyA, const Trans_d847c0& bodyB,
                                            const Vec_d849a0& pivot, const Vec_d849a0& normal)
{
    m_50.SetTransformedPosition(bodyA, pivot);
    m_90.SetTransformedPosition(bodyB, pivot);
    m_20.setZero4();
    m_30.setZero4();
    m_40.setZero4();
    m_20(0) = 1.0f;
    m_30(1) = 1.0f;
    m_40(2) = 1.0f;

    Rot_d849a0& rot = m_60;
    int n = m_a2;
    static_cast<Out_d847c0&>(rot.getColumn(n)).setRotatedInverseDir(bodyB.m_rotation, normal);
    int i1 = (n + 1) % 3;

    Perp_d849a0(rot.getColumn(n), rot.getColumn(i1));
    rot.getColumn(i1).normalize3();

    rot.getColumn((n + 2) % 3).setCross(rot.getColumn(n), rot.getColumn(i1));
}
}  // namespace fnv_00d847c0

namespace fnv_00d849a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Vec_d849a0
{
    __m128 q;
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
    __forceinline void normalize3()
    {
        __m128 v = q;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
        __m128 t = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e));
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), t);
        r = _mm_andnot_ps(mask, r);
        q = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v);
    }
    void setCross(const Vec_d849a0& a, const Vec_d849a0& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

static inline float Abs_d849a0(float r)
{
    return (float)fabs(r);
}

static __forceinline void Perp_d849a0(const Vec_d849a0& vectorIn, Vec_d849a0& biVectorOut)
{
    int minIdx = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = Abs_d849a0(vectorIn(0));
    float a1 = Abs_d849a0(vectorIn(1));
    float a2 = Abs_d849a0(vectorIn(2));
    if (a1 < a0)
    {
        ok1 = 0;
        minIdx = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ok2 = minIdx;
        minIdx = 2;
    }
    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

struct Rot_d849a0
{
    Vec_d849a0 col0;
    Vec_d849a0 col1;
    Vec_d849a0 col2;
    Vec_d849a0& getColumn(int i)
    {
        return (&col0)[i];
    }
};

struct Cls_d849a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec_d849a0 m_20;
    Vec_d849a0 m_30;
    Vec_d849a0 m_40;
    Vec_d849a0 m_50;
    Rot_d849a0 m_60;
    Vec_d849a0 m_90;
    unsigned short unkA0;
    unsigned char m_a2;
    void SetBasis(const Vec_d849a0& a1, const Vec_d849a0& a2, const Vec_d849a0& a3);
};

// Stores a1 and a2 into m_50 and m_90, initializes m_20, m_30, m_40 to the identity basis, and builds the m_60 rotation from a3 and m_a2.
// @fnv 0x00d849a0
void Cls_d849a0::SetBasis(const Vec_d849a0& a1, const Vec_d849a0& a2, const Vec_d849a0& a3)
{
    m_50.q = a1.q;
    m_90.q = a2.q;
    m_20.setZero4();
    m_30.setZero4();
    m_40.setZero4();
    m_20(0) = 1.0f;
    m_30(1) = 1.0f;
    m_40(2) = 1.0f;

    Rot_d849a0& rot = m_60;
    int n = m_a2;
    rot.getColumn(n).q = a3.q;
    int i1 = (n + 1) % 3;

    Perp_d849a0(rot.getColumn(n), rot.getColumn(i1));
    rot.getColumn(i1).normalize3();

    int i2 = (n + 2) % 3;
    rot.getColumn(i2).setCross(rot.getColumn(n), rot.getColumn(i1));
}
}  // namespace fnv_00d849a0


// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCapsuleShape.h"

extern char const* const g_01268970_arg1;
void __cdecl FUN_00c90360(char const* const* arg1, char const* const* arg2);

// @fnv 0x00d22360
void __cdecl FUN_00d22360(char const* const* arg1, char const* const* arg2)
{
    FUN_00c90360(arg1, &g_01268970_arg1);
}

// @fnv 0x00d22350
int __cdecl FUN_00d22350()
{
    return 2;
}

// @fnv 0x00d22d60
int __stdcall FUN_00d22d60(int a, int b)
{
    return 0x40;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 v);

class FUN_00d223f0_cls
{
  public:
    void GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out);
};

// @fnv 0x00d223f0
void FUN_00d223f0_cls::GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out)
{
    int iRemaining = count - 1;
    if (iRemaining < 0)
    {
        return;
    }
    hkVector4* pOut = out;
    unsigned short const* p = indices;
    do
    {
        unsigned int uiIndex = *p;
        __m128 v = _mm_load_ps(reinterpret_cast<float const*>(reinterpret_cast<char*>(this) + uiIndex + 0x20));
        _mm_store_ps(reinterpret_cast<float*>(pOut), v);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pOut) + 0xc) = uiIndex | 0x3f000000;
        pOut++;
        p++;
        iRemaining--;
    } while (iRemaining >= 0);
}

struct __declspec(align(16)) hkVector4D224
{
    __m128 m_vComponents;

    hkVector4D224()
    {}
    hkVector4D224(const hkVector4D224& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class FUN_00d22480_cls
{
  public:
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
    hkVector4D224 m_vector;

    hkVector4D224 FUN_00d22480() const;
};

// @fnv 0x00d22480
hkVector4D224 FUN_00d22480_cls::FUN_00d22480() const
{
    return m_vector;
}

struct FUN_00d224a0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 unk20;
    __m128 unk30;

    void __thiscall getCollisionSpheresImpl(__m128* result);
};

// @fnv 0x00d224a0
void __thiscall FUN_00d224a0_Data::getCollisionSpheresImpl(__m128* result)
{
    result[0] = unk20;
    result[1] = unk30;
}

extern int DAT_010ce25c;
union __declspec(align(16)) AlignedHKVector4
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    };
};
struct FUN_00d22590_Class : hkpCapsuleShape
{
    FUN_00d22590_Class* __thiscall FUN_00d22590(const AlignedHKVector4& first, const AlignedHKVector4& second,
                                                float radius);
};
// Initializes a capsule shape from two points and a radius, storing the radius in both endpoints' w components and setting the type to 5.
// @fnv 0x00d22590
FUN_00d22590_Class* __thiscall FUN_00d22590_Class::FUN_00d22590(const AlignedHKVector4& first,
                                                                const AlignedHKVector4& second, float radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_type = 5;
    *reinterpret_cast<void**>(this) = &DAT_010ce25c;
    reinterpret_cast<AlignedHKVector4*>(&m_kVertexA)->simd = first.simd;
    reinterpret_cast<AlignedHKVector4*>(&m_kVertexB)->simd = second.simd;
    *reinterpret_cast<volatile float*>(&m_kVertexA.w) = radius;
    *reinterpret_cast<volatile float*>(&m_kVertexB.w) = radius;
    return this;
}

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};
struct ClosestLineResult
{
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
void __cdecl FUN_00d231b0(const Point4& a, const Point4& b, const Point4& c, const Point4& d, ClosestLineResult* out);
// Calls FUN_00d231b0 to compute the closest points between two lines and writes the points, fractions and distance to the output pointers.
// @fnv 0x00d22700
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart,
                                  const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB,
                                  Point4* pointA, Point4* pointB)
{
    ClosestLineResult result;
    FUN_00d231b0(aLineAStart, aLineAEnd, aLineBStart, aLineBEnd, &result);
    *reinterpret_cast<__m128*>(pointA) = *reinterpret_cast<const __m128*>(&result.pointA);
    *reinterpret_cast<__m128*>(pointB) = *reinterpret_cast<const __m128*>(&result.pointB);
    *pfFractionA = result.fractionA;
    *pfFractionB = result.fractionB;
    *pfDistance = result.distance;
}

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern float DAT_01016248;

class Aabb_d22440
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_kMin;
    __m128 m_kMax;

    void __thiscall FUN_00d22440(__m128* pkCenter) const;
};

// Stores (m_kMax + m_kMin) scaled by the float at DAT_01016248 into pkCenter.
// @fnv 0x00d22440
void __thiscall Aabb_d22440::FUN_00d22440(__m128* pkCenter) const
{
    __m128 sum = _mm_add_ps(m_kMax, m_kMin);
    *pkCenter = sum;
    __m128 kHalf = _mm_load_ss(&DAT_01016248);
    kHalf = _mm_shuffle_ps(kHalf, kHalf, 0);
    *pkCenter = _mm_mul_ps(kHalf, sum);
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

// Projects a point onto a line segment defined by two endpoints, clamping the result to the segment bounds and writing it to out.
// @fnv 0x00d224c0
void __cdecl FUN_00d224c0(float* apPoint, float* apStart, float* apEnd, float* out)
{
    __m128 vStart = _mm_load_ps(apStart);
    __m128 vEnd = _mm_load_ps(apEnd);
    __m128 vPoint = _mm_load_ps(apPoint);

    __m128 xmm2 = vStart;
    __m128 xmm3 = vEnd;
    __m128 xmm4 = vPoint;

    __m128 xmm1 = _mm_sub_ps(xmm3, xmm2);
    __m128 xmm0 = _mm_sub_ps(xmm2, xmm4);

    xmm0 = _mm_mul_ps(xmm0, xmm1);

    __m128 temp4 = xmm0;
    temp4 = _mm_shuffle_ps(temp4, xmm0, 0x55);
    temp4 = _mm_add_ss(temp4, xmm0);

    __m128 temp5 = xmm0;
    temp5 = _mm_shuffle_ps(temp5, xmm0, 0xaa);
    temp5 = _mm_add_ss(temp5, temp4);

    float negDot;
    float lenSq;

    _mm_store_ss(&negDot, temp5);
    negDot = -negDot;

    __m128 l0 = _mm_mul_ps(xmm1, xmm1);
    __m128 ls1 = _mm_shuffle_ps(l0, l0, 0x55);
    ls1 = _mm_add_ss(ls1, l0);
    __m128 ls2 = _mm_shuffle_ps(l0, l0, 0xaa);
    ls2 = _mm_add_ss(ls2, ls1);

    _mm_store_ss(&lenSq, ls2);

    if (negDot <= 0.0f)
    {
        _mm_store_ps(out, vStart);
        return;
    }

    if (lenSq <= negDot)
    {
        _mm_store_ps(out, vEnd);
        return;
    }

    negDot /= lenSq;

    __m128 tVec = _mm_load_ss(&negDot);
    __m128 tBroadcast = _mm_shuffle_ps(tVec, tVec, 0);
    __m128 scaledDiff = _mm_mul_ps(xmm1, tBroadcast);
    __m128 result = _mm_add_ps(vStart, scaledDiff);

    _mm_store_ps(out, result);
}

struct hkSimdRealD223
{
    __m128 m_vValue;

    hkSimdRealD223(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4D223
{
    __m128 m_vComponents;

    hkVector4D223()
    {}
    hkVector4D223(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4D223& a, const hkVector4D223& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD223 dot3(const hkVector4D223& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void setInt24W(int i)
    {
        reinterpret_cast<int*>(&m_vComponents)[3] = i | 0x3f000000;
    }
};

class hkBaseObjectD223
{
  public:
    virtual ~hkBaseObjectD223() throw();
};

class hkReferencedObjectD223 : public hkBaseObjectD223
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpCapsuleShapeD223 : public hkReferencedObjectD223
{
  public:
    void getSupportingVertexImpl(const hkVector4D223& kDirection, hkVector4D223& kSupportingVertexOut) const;

    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    unsigned int unk14, unk18, unk1C;
    hkVector4D223 m_kVertexA;
    hkVector4D223 m_kVertexB;
};

// Picks vertex A or B by the sign of (B - A) dot kDirection, writes it to kSupportingVertexOut, and stores the vertex id (0 or 16) in W.
// @fnv 0x00d22370
void hkpCapsuleShapeD223::getSupportingVertexImpl(const hkVector4D223& kDirection, hkVector4D223& kSupportingVertexOut) const
{
    hkVector4D223 kDelta;
    kDelta.setSub4(m_kVertexB, m_kVertexA);
    const float fDot = kDelta.dot3(kDirection);
    int iVertexId;
    if (fDot < 0.0f)
    {
        kSupportingVertexOut = m_kVertexA;
        iVertexId = 0;
    }
    else
    {
        kSupportingVertexOut = m_kVertexB;
        iVertexId = sizeof(hkVector4D223);
    }
    kSupportingVertexOut.setInt24W(iVertexId);
}

extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);

struct hkTransformq;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(hkReal x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn);
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

union hkVector4U
{
    hkVector4 m_vec;
    __m128 m_vComponents;
};

struct hkTransformU
{
    hkVector4U m_kColumn0;
    hkVector4U m_kColumn1;
    hkVector4U m_kColumn2;
    hkVector4U m_vTranslation;

    __forceinline void set(const hkTransform& t)
    {
        m_kColumn0.m_vec = t.m_rotation.m_kColumn0;
        m_kColumn1.m_vec = t.m_rotation.m_kColumn1;
        m_kColumn2.m_vec = t.m_rotation.m_kColumn2;
        m_vTranslation.m_vec = t.m_vTranslation;
    }
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn)
{
    const __m128 b = bIn.m_vComponents;
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(a.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(a.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, a.m_vTranslation.m_vComponents));
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors,
                                            hkVector4q* vectorsOut)
{
    hkVector4U c0;
    c0.m_vec = t.m_rotation.m_kColumn0;
    hkVector4U c1;
    c1.m_vec = t.m_rotation.m_kColumn1;
    hkVector4U c2;
    c2.m_vec = t.m_rotation.m_kColumn2;
    hkVector4U trans;
    trans.m_vec = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        const __m128 b = vectorsIn[i].m_vComponents;
        const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
        const __m128 r0 = _mm_mul_ps(c0.m_vComponents, b0);
        const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
        const __m128 r1 = _mm_mul_ps(c1.m_vComponents, b1);
        const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
        const __m128 r2 = _mm_mul_ps(c2.m_vComponents, b2);
        vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, trans.m_vComponents));
    } while (--i >= 0);
}

class hkpCapsuleShapeAabb : public hkpCapsuleShape
{
  public:
    void FUN_00d225e0(const hkTransform& localToWorld, hkReal tolerance, hkAabbq& out) const;
};

// Computes the world-space AABB of the capsule by transforming its two vertices and expanding by the sphere radius plus tolerance.
// @fnv 0x00d225e0
void hkpCapsuleShapeAabb::FUN_00d225e0(const hkTransform& localToWorld, hkReal tolerance, hkAabbq& out) const
{
    hkVector4q tol4;
    tol4.SetAllComponents(m_fSphereRadius + tolerance);

    hkVector4q obj[2];
    hkTransformPoints(localToWorld, reinterpret_cast<const hkVector4q*>(&m_kVertexA), 2, &obj[0]);

    out.m_kMinimumCorner.setMin4(obj[0], obj[1]);
    out.m_kMinimumCorner.sub4(tol4);
    out.m_kMaximumCorner.setMax4(obj[0], obj[1]);
    out.m_kMaximumCorner.add4(tol4);
}

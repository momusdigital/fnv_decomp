
// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/sphere/hkpsphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSphereShape.h"
extern char const* const g_01268970_arg1;
void __cdecl FUN_00c90360(char const* const*, char const* const*);
void __cdecl FUN_00cd8040(char const* const* a1, char const* const* a2);
extern int DAT_010cb5ac;
struct FUN_00cd8160
{
    FUN_00cd8160(float radius);
};
int __cdecl FUN_00cd8050();
int __stdcall FUN_00cd87f0(int a1, int a2);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
struct Shape_00cd8100
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_fSphereRadius;
};
struct Vec_00cd8100
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    __m128 m_pos;
};
struct Aabb_00cd8100
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};
struct Shape_00cd8100_cls
{
    void GetAabb(const Vec_00cd8100* t, float tol, Aabb_00cd8100* out);
    Shape_00cd8100 self;
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;
struct hkMonitorStreamCD81
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pRayCursor;
};
struct hkTimerCommandCD81
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    int unk08;
};
extern const char DAT_010cb5f4[];
extern const char DAT_010c41f8[];
void* __cdecl FUN_00cd85c0(void* pvResult, float fValue, int a, int b);
class HostCD81
{
  public:
    int unk00, unk04, unk08, unk0C;
    float m_fValue;
    void* RecordTimerCommands(void* pvResult, int a, int b);
};
extern "C" __m128 _mm_set_ps(float, float, float, float);
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_cmple_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_or_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_rsqrt_ps(__m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" int _mm_movemask_ps(__m128);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
class RayMask
{
    __m128 bits;
    friend class RayVector;

  public:
    enum Component
    {
        X = 1,
        Y = 2,
        Z = 4,
        W = 8
    };
    static const Component components[4];
    __forceinline void intersect(const RayMask& a, const RayMask& b)
    {
        bits = _mm_and_ps(a.bits, b.bits);
    }
    __forceinline int any(Component lane) const
    {
        return _mm_movemask_ps(bits) & lane;
    }
};
const RayMask::Component RayMask::components[4] = {RayMask::X, RayMask::Y, RayMask::Z, RayMask::W};
static const __m128 signVector = {{-0.0f, -0.0f, -0.0f, -0.0f}};
static const __m128 tripleVector = {{3.0f, 3.0f, 3.0f, 3.0f}};
static const __m128 halfVector = {{0.5f, 0.5f, 0.5f, 0.5f}};
extern __m128 kOne;
static __forceinline __m128 reciprocalVector(__m128 value)
{
    __m128 estimate = _mm_rcp_ps(value);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, value), estimate));
}
class RayVector
{
    __m128 value;

  public:
    __forceinline RayVector()
    {}
    __forceinline RayVector(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline RayVector(const __m128& other)
    {
        value = other;
    }
    __forceinline void operator=(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline __m128& quad()
    {
        return value;
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline operator __m128() const
    {
        return value;
    }
    __forceinline float& operator()(int lane)
    {
        return ((float*)&value)[lane];
    }
    __forceinline void splat(float number)
    {
        value = _mm_set_ps1(number);
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void product(const RayVector& a, const RayVector& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void accumulate(const RayVector& a, const RayVector& b)
    {
        value = _mm_add_ps(value, _mm_mul_ps(a.value, b.value));
    }
    __forceinline void difference(const RayVector& a, const RayVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void multiply(const RayVector& rhs)
    {
        value = _mm_mul_ps(value, rhs.value);
    }
    __forceinline void add(const RayVector& rhs)
    {
        value = _mm_add_ps(value, rhs.value);
    }
    __forceinline void subtract(const RayVector& rhs)
    {
        value = _mm_sub_ps(value, rhs.value);
    }
    __forceinline void negate(const RayVector& rhs)
    {
        value = _mm_xor_ps(rhs.value, signVector);
    }
    __forceinline void reciprocal(const RayVector& rhs)
    {
        value = reciprocalVector(rhs.value);
    }
    __forceinline void choose(const RayVector& a, const RayVector& b, const RayMask& mask)
    {
        value = _mm_or_ps(_mm_and_ps(mask.bits, b.value), _mm_andnot_ps(mask.bits, a.value));
    }
    __forceinline RayMask greater(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(rhs.value, value);
        return result;
    }
    __forceinline RayMask less(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(value, rhs.value);
        return result;
    }
    __forceinline RayMask atLeast(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmple_ps(rhs.value, value);
        return result;
    }
};
struct RayQuerySet
{
    RayVector m_vFrom[3], m_vTo[3];
    unsigned filter;
    const void* collectionFilter;
};
struct RayHitBase
{
    RayVector m_vHitNormal;
    float m_fHitFraction;
    int unk14, unk18, unk1c;
};
struct RayHit : RayHitBase
{
    unsigned m_uiShapeKeys[8];

  private:
    int m_uiShapeKeyIndex;

  public:
    __forceinline void setKey(unsigned key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};
struct RayHits
{
    RayHit m_akRayOutputs[4];
};
static __forceinline void transposeVectors(__m128& r0, __m128& r1, __m128& r2, __m128& r3)
{
    __m128 t0 = _mm_shuffle_ps(r0, r1, 0x44);
    __m128 t2 = _mm_shuffle_ps(r0, r1, 0xee);
    __m128 t1 = _mm_shuffle_ps(r2, r3, 0x44);
    __m128 t3 = _mm_shuffle_ps(r2, r3, 0xee);
    r0 = _mm_shuffle_ps(t0, t1, 0x88);
    r1 = _mm_shuffle_ps(t0, t1, 0xdd);
    r2 = _mm_shuffle_ps(t2, t3, 0x88);
    r3 = _mm_shuffle_ps(t2, t3, 0xdd);
}
struct ProbeRecord
{
    const char* tag;
    unsigned time, highTime;
};
struct ProbeStream
{
    int reserved;
    char* current;
    int reserved2;
    char* end;
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct ProbeSphere : hkpSphereShape
{
    RayMask FUN_00cd8220(const RayQuerySet&, RayHits&, const RayMask&) const;
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, __m128);
void __stdcall FUN_00cd8060(int direction, float* vertexOut);
extern "C" void __movsd(unsigned long*, const unsigned long*, unsigned long);
void __stdcall FUN_00cd8080(int a0, __int64 packed);
extern "C" __m128 _mm_setzero_ps(void);
struct __declspec(align(16)) CentreVectorCD80
{
    __m128 m_vComponents;

    void zero()
    {
        m_vComponents = _mm_setzero_ps();
    }
};
CentreVectorCD80 __stdcall FUN_00cd80c0();
struct FUN_00cd8140_Result
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};
struct FUN_00cd8140_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;

    void getCollisionSpheresImpl(FUN_00cd8140_Result* result);
};
void __stdcall FUN_00cd80e0(float* output);

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_load_ss(const float*);
#include <math.h>

struct FnvBool
{
    FnvBool(bool v)
    {
        m = (char)v;
    }
    char m;
};

struct RayIn
{
    __m128 m_vFrom;
    __m128 m_vTo;
};

extern const __m128 DAT_010ec7f0;

static __forceinline float dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xAA), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

static __forceinline __m128 lerp(__m128 a, __m128 b, const float& t)
{
    __m128 scalar = _mm_load_ss(&t);
    __m128 ts = _mm_shuffle_ps(scalar, scalar, 0);
    __m128 one = DAT_010ec7f0;
    return _mm_add_ps(_mm_mul_ps(a, _mm_sub_ps(one, ts)), _mm_mul_ps(b, ts));
}

// @fnv 0x00cd85c0
FnvBool __cdecl FUN_00cd85c0(float radius, const RayIn& input, RayHit& results)
{
    float extra, p2, gap, disc, negative, root, nearDist;
    __m128 point;
    float radiusSq = radius * radius;
    __m128 dir = _mm_sub_ps(input.m_vTo, input.m_vFrom);
    float b = dot3(input.m_vFrom, dir);
    if (b >= 0.0f)
        goto miss;

    const float& a = dot3(dir, dir);
    if (b * b > (float)(radiusSq * a * 100.0))
    {
        if (!(a < radiusSq))
        {
            extra = -b;
            float closestFraction = extra / a;
            point = lerp(input.m_vFrom, input.m_vTo, closestFraction);
            b = 0.0f;
        }
        else
            goto miss;
    }
    else
    {
        point = input.m_vFrom;
        extra = 0.0f;
    }

    p2 = dot3(point, point);
    gap = p2 - radiusSq;
    disc = b * b - a * gap;
    if (disc <= 0.0f)
        goto miss;

    negative = -b;
    root = sqrtf(disc);
    nearDist = negative - root;
    extra = nearDist + extra;

    if (extra >= (float)(a * results.m_fHitFraction))
        goto miss;
    if (extra < 0.0f)
    {
    miss:
        return false;
    }
    {
        extra = extra / a;
        results.m_fHitFraction = extra;
        __m128 hit = lerp(input.m_vFrom, input.m_vTo, extra);
        float invRadius = 1.0f / radius;
        results.m_vHitNormal = RayVector(hit);
        __m128 invScalar = _mm_load_ss(&invRadius);
        results.m_vHitNormal = RayVector(_mm_mul_ps(_mm_shuffle_ps(invScalar, invScalar, 0), hit));
        results.setKey(0xffffffff);
        return true;
    }
}

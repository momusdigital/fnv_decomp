
// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/sphere/hkpsphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSphereShape.h"

extern char const* const g_01268970_arg1;
void __cdecl FUN_00c90360(char const* const*, char const* const*);

// @fnv 0x00cd8040
void __cdecl FUN_00cd8040(char const* const* a1, char const* const* a2)
{
    FUN_00c90360(a1, &g_01268970_arg1);
}

extern int DAT_010cb5ac;

struct FUN_00cd8160
{
    FUN_00cd8160(float radius);
};

// @fnv 0x00cd8160
FUN_00cd8160::FUN_00cd8160(float radius)
{
    *(float*)((char*)this + 0x10) = radius;
    *(unsigned short*)((char*)this + 6) = 1;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 1;
    *(int*)this = (int)&DAT_010cb5ac;
}

// @fnv 0x00cd8050
int __cdecl FUN_00cd8050()
{
    return 1;
}

// @fnv 0x00cd87f0
int __stdcall FUN_00cd87f0(int a1, int a2)
{
    return 0x20;
}

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

// Computes the axis-aligned bounding box of a sphere by expanding its position by the radius plus a tolerance.
// @fnv 0x00cd8100
void Shape_00cd8100_cls::GetAabb(const Vec_00cd8100* t, float afTolerance, Aabb_00cd8100* apAabb)
{
    float r = self.m_fSphereRadius + afTolerance;
    __m128 s = _mm_load_ps1(&r);
    apAabb->m_kMinimumCorner = _mm_sub_ps(t->m_pos, s);
    apAabb->m_kMaximumCorner = _mm_add_ps(t->m_pos, s);
}

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

// Writes start and end timer commands to the TLS monitor stream around a call to FUN_00cd85c0, then returns pvResult.
// @fnv 0x00cd8190
void* HostCD81::RecordTimerCommands(void* pvResult, int a, int b)
{
    hkMonitorStreamCD81* pkStream = (hkMonitorStreamCD81*)TlsGetValue(DAT_0126835c);
    char* end = pkStream->m_kRayEnd;
    if (end < pkStream->m_pRayCursor)
    {
        hkTimerCommandCD81* pkCmd = (hkTimerCommandCD81*)end;
        pkCmd->m_pCommandName = DAT_010cb5f4;
        _ReadWriteBarrier();
        volatile unsigned int t0 = (unsigned int)__rdtsc();
        pkCmd->m_uiStartTicks = t0;
        end += sizeof(hkTimerCommandCD81);
        pkStream->m_kRayEnd = end;
    }
    FUN_00cd85c0(pvResult, m_fValue, a, b);
    pkStream = (hkMonitorStreamCD81*)TlsGetValue(DAT_0126835c);
    char* end2 = pkStream->m_kRayEnd;
    if (end2 < pkStream->m_pRayCursor)
    {
        hkTimerCommandCD81* pkCmd = (hkTimerCommandCD81*)end2;
        pkCmd->m_pCommandName = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int t1 = (unsigned int)__rdtsc();
        pkCmd->m_uiStartTicks = t1;
        end2 += sizeof(hkTimerCommandCD81);
        pkStream->m_kRayEnd = end2;
    }
    return pvResult;
}

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
// Performs a vectorized ray-sphere intersection test, writing hit fractions and normals into hits and returning the active RayMask.
// @fnv 0x00cd8220
RayMask ProbeSphere::FUN_00cd8220(const RayQuerySet& ray, RayHits& hits, const RayMask& enabled) const
{
    ProbeStream* s = (ProbeStream*)TlsGetValue(DAT_0126835c);
    char* pCurrent = s->current;
    if (pCurrent < s->end)
    {
        unsigned ticks;
        ((ProbeRecord*)pCurrent)->tag = (char*)&ticks;
        ((ProbeRecord*)pCurrent)->tag = "TtrcSphereBundle";
        _ReadWriteBarrier();
        ticks = (unsigned)__rdtsc();
        _ReadWriteBarrier();
        ((ProbeRecord*)pCurrent)->time = ticks;
        s->current = pCurrent + 12;
    }
    RayMask active = enabled;
    RayVector radius, radiusSquared;
    radius.splat(m_fSphereRadius);
    radiusSquared.product(radius, radius);
    __m128 hundredValues = {100.0f, 100.0f, 100.0f, 100.0f};
    RayVector hundred;
    hundred.quad() = hundredValues;
    RayVector quadratic, linear;
    {
        RayVector dx, dy, dz;
        dx.difference(ray.m_vTo[0], ray.m_vFrom[0]);
        quadratic.product(dx, dx);
        linear.product(ray.m_vFrom[0], dx);
        dy.difference(ray.m_vTo[1], ray.m_vFrom[1]);
        quadratic.accumulate(dy, dy);
        linear.accumulate(ray.m_vFrom[1], dy);
        dz.difference(ray.m_vTo[2], ray.m_vFrom[2]);
        quadratic.accumulate(dz, dz);
        linear.accumulate(ray.m_vFrom[2], dz);
    }
    RayVector scaled, linearSquared;
    scaled.product(quadratic, radiusSquared);
    scaled.multiply(hundred);
    linearSquared.product(linear, linear);
    RayMask farCheck = linearSquared.greater(scaled);
    RayVector zero;
    zero.zero();
    RayVector shift;
    shift.choose(zero, linear, farCheck);
    shift.negate(shift);
    linear.choose(linear, zero, farCheck);
    linearSquared.choose(linearSquared, zero, farCheck);
    RayVector reciprocal, middle, one, remaining;
    reciprocal.reciprocal(quadratic);
    middle.product(shift, reciprocal);
    one.quad() = kOne;
    remaining.difference(one, middle);
    RayVector c;
    c.zero();
    {
        RayVector midpoint[3];
        for (int axis = 0; axis < 3; ++axis)
        {
            midpoint[axis].product(ray.m_vFrom[axis], remaining);
            midpoint[axis].accumulate(ray.m_vTo[axis], middle);
            c.accumulate(midpoint[axis], midpoint[axis]);
        }
    }
    c.subtract(radiusSquared);
    RayVector det;
    det.negate(quadratic);
    det.multiply(c);
    det.add(linearSquared);
    RayMask infiniteHit = det.greater(zero);
    active.intersect(active, infiniteHit);
    RayVector root;
    __m128 approx = _mm_rsqrt_ps(det);
    __m128 three = tripleVector, half = halfVector;
    root.quad() = _mm_mul_ps(
        _mm_mul_ps(_mm_sub_ps(three, _mm_mul_ps(_mm_mul_ps(det, approx), approx)), _mm_mul_ps(approx, half)), det);
    root.choose(zero, root, infiniteHit);
    RayVector fraction = shift;
    fraction.subtract(linear);
    fraction.subtract(root);
    RayVector limits;
    limits.set(hits.m_akRayOutputs[0].m_fHitFraction, hits.m_akRayOutputs[1].m_fHitFraction,
               hits.m_akRayOutputs[2].m_fHitFraction, hits.m_akRayOutputs[3].m_fHitFraction);
    fraction.multiply(reciprocal);
    RayMask below = fraction.less(limits);
    RayMask positive = fraction.atLeast(zero);
    active.intersect(active, below);
    active.intersect(active, positive);
    RayVector invRadius, oneMinusFraction;
    invRadius.reciprocal(radius);
    oneMinusFraction.difference(one, fraction);
    RayVector normals[4];
    for (int axis = 0; axis < 3; ++axis)
    {
        normals[axis].product(ray.m_vFrom[axis], oneMinusFraction);
        normals[axis].accumulate(ray.m_vTo[axis], fraction);
        normals[axis].multiply(invRadius);
    }
    normals[3].zero();
    transposeVectors(normals[0].quad(), normals[1].quad(), normals[2].quad(), normals[3].quad());
    for (int lane = 0; lane < 4; ++lane)
    {
        if (active.any(RayMask::components[lane]))
        {
            hits.m_akRayOutputs[lane].m_fHitFraction = fraction(lane);
            hits.m_akRayOutputs[lane].m_vHitNormal = normals[lane];
            hits.m_akRayOutputs[lane].setKey(~0u);
        }
    }
    s = (ProbeStream*)TlsGetValue(DAT_0126835c);
    pCurrent = s->current;
    if (pCurrent < s->end)
    {
        unsigned ticks;
        ((ProbeRecord*)pCurrent)->tag = (char*)&ticks;
        ((ProbeRecord*)pCurrent)->tag = "Et";
        _ReadWriteBarrier();
        ticks = (unsigned)__rdtsc();
        _ReadWriteBarrier();
        ((ProbeRecord*)pCurrent)->time = ticks;
        s->current = pCurrent + 12;
    }
    return active;
}

extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, __m128);

// @fnv 0x00cd8060
void __stdcall FUN_00cd8060(int direction, float* vertexOut)
{
    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(vertexOut, zero);
}

extern "C" void __movsd(unsigned long*, const unsigned long*, unsigned long);

// Unpacks a count and destination pointer from packed, zeroes four floats at dst, then copies them forward over the following (count-1)*4 floats.
// @fnv 0x00cd8080
void __stdcall FUN_00cd8080(int aUnused, __int64 packed)
{
    union
    {
        __int64 v;
        struct
        {
            int count;
            float* dst;
        } s;
    } u;
    u.v = packed;
    int c = u.s.count;
    c += -1;
    if (c >= 0)
    {
        unsigned long n = ((unsigned long)c & 0xfffffff) * 4;
        __m128 z = _mm_setzero_ps();
        *(__m128*)u.s.dst = z;
        __movsd((unsigned long*)(u.s.dst + 4), (const unsigned long*)u.s.dst, n);
    }
}

extern "C" __m128 _mm_setzero_ps(void);

struct __declspec(align(16)) CentreVectorCD80
{
    __m128 m_vComponents;

    void zero()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

// @fnv 0x00cd80c0
CentreVectorCD80 __stdcall FUN_00cd80c0()
{
    CentreVectorCD80 result;
    result.zero();
    return result;
}

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

// @fnv 0x00cd8140
void FUN_00cd8140_Obj::getCollisionSpheresImpl(FUN_00cd8140_Result* result)
{
    _mm_store_ps(reinterpret_cast<float*>(result), _mm_setzero_ps());
    result->unk0C = unk10;
}

// @fnv 0x00cd80e0
void __stdcall FUN_00cd80e0(float* output)
{
    *reinterpret_cast<__m128*>(output) = _mm_setzero_ps();
}

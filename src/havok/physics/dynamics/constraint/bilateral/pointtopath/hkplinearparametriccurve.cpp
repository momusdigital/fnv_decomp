
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpLinearParametricCurve.h"

struct FUN_00e47c20_s
{
    double FUN_00e47c20() const;
};

// @fnv 0x00e47c20
double FUN_00e47c20_s::FUN_00e47c20() const
{
    return static_cast<double>(static_cast<int>(*(const int*)((const char*)this + 0x24)) - 1);
}

struct Vec : public hkVector4
{
    void FUN_00c7f640(void const*, hkVector4 const&);
};

struct FUN_00e47e50_class
{
    unsigned char m_ucUnknownByte[0x20];
    Vec* m_pPoints;
    int m_iPointCount;

    void transformPoints(void const*);
};

// Applies FUN_00c7f640 to each of the m_iPointCount points in m_pPoints, passing data and the point itself.
// @fnv 0x00e47e50
void FUN_00e47e50_class::transformPoints(void const* data)
{
    int pointCount = m_iPointCount;
    for (int i = 0; i < pointCount; ++i)
        m_pPoints[i].FUN_00c7f640(data, m_pPoints[i]);
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    float value;
    void FUN_00e47430(float input);
};
// @fnv 0x00e47430
void CpuObject::FUN_00e47430(float input)
{
    value = input;
}

struct FnvCpu_FUN_00e47400_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    unsigned char* FUN_00e47400(unsigned char* output);
};
// @fnv 0x00e47400
unsigned char* FnvCpu_FUN_00e47400_CpuObject::FUN_00e47400(unsigned char* output)
{
    *output = value;
    return output;
}

// Returns the constant float value 0.0f.
// @fnv 0x00e47410
float __cdecl GetZeroFloat()
{
    return 0.0f;
}

class CurveSmoothingGetter : public hkpParametricCurve
{
  public:
    float m_fSmoothingValue;
    float FUN_00e47420() const;
};

// @fnv 0x00e47420
float CurveSmoothingGetter::FUN_00e47420() const
{
    return m_fSmoothingValue;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

extern const __m128 DAT_010ec7f0;

int __cdecl FUN_00cbfef0(float f);

struct hkSimdRealE474
{
    __m128 m_vValue;

    hkSimdRealE474(const float& f)
    {
        m_vValue = _mm_load_ps1(&f);
    }
};

struct hkVector4E474
{
    __m128 m_vComponents;

    void operator=(const hkVector4E474& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setInterpolate4(const hkVector4E474& a, const hkVector4E474& b, const hkSimdRealE474& t)
    {
        const __m128 kOneMinusT = _mm_sub_ps(DAT_010ec7f0, t.m_vValue);
        m_vComponents = _mm_add_ps(_mm_mul_ps(kOneMinusT, a.m_vComponents), _mm_mul_ps(b.m_vComponents, t.m_vValue));
    }
};

template <class T> struct hkArrayE474
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectE474
{
  public:
    virtual ~hkBaseObjectE474() throw();
};

class hkpLinearParametricCurveE474 : public hkBaseObjectE474
{
  public:
    virtual ~hkpLinearParametricCurveE474() throw();

    void getPoint(float t, hkVector4E474& kPointOut) const;

    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkArrayE474<hkVector4E474> m_kPoints;
};

// Selects a point from m_kPoints using t, interpolates with the next point when available, and writes the result to kPointOut.
// @fnv 0x00e47440
void hkpLinearParametricCurveE474::getPoint(float afParam, hkVector4E474& kPointOut) const
{
    const int i = (afParam < 0.0f) ? 0 : FUN_00cbfef0(afParam);
    const float fFrac = afParam - i;
    const int iNextIndex = i + 1;
    if (iNextIndex < m_kPoints.GetLogicalSize())
    {
        kPointOut.setInterpolate4(m_kPoints[i], m_kPoints[iNextIndex], fFrac);
    }
    else
    {
        kPointOut = m_kPoints[i];
    }
}

namespace fnv_00e474e0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" void _mm_store_ss(float*, __m128);
extern int __cdecl FUN_00cbfef0(float f);

extern const __m128 DAT_010ec7f0;

struct Vec_e474e0
{
    __m128 m_vComponents;
    void setSub4(const Vec_e474e0& a, const Vec_e474e0& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMul4(const Vec_e474e0& a, const Vec_e474e0& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setInterpolate4(const Vec_e474e0& a, const Vec_e474e0& b, float t)
    {
        __m128 tt = _mm_set_ps1(t);
        m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, tt), a.m_vComponents), _mm_mul_ps(b.m_vComponents, tt));
    }
    __forceinline float dot3(const Vec_e474e0& b) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
        __m128 y = _mm_shuffle_ps(x2, x2, 0x55);
        __m128 xy = _mm_add_ss(y, x2);
        __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        __m128 r = _mm_add_ss(z, xy);
        float f;
        _mm_store_ss(&f, r);
        return f;
    }
    float lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void normalize3()
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(x2, x2, 0x55);
        __m128 xy = _mm_add_ss(y, x2);
        __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        __m128 len = _mm_add_ss(z, xy);
        __m128 e = _mm_rsqrt_ss(len);
        __m128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
        __m128 ree = _mm_mul_ss(_mm_mul_ss(len, e), e);
        __m128 r =
            _mm_andnot_ps(_mm_cmpeq_ss(len, _mm_set_ss(0.0f)), _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ree)));
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct Arr_e474e0
{
    Vec_e474e0* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Vec_e474e0& operator[](int i)
    {
        return m_data[i];
    }
    const Vec_e474e0& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct Curve_e474e0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float FindNearestPoint(float t, const Vec_e474e0& nearPoint, Vec_e474e0& pointOnCurve);
    int m_iObjectReferenceCount;
    float m_fSmoothingValue;
    bool m_bClosedLoop;
    char unk0d;
    char unk0e;
    char unk0f;
    hkVector4 m_dirNotParallel;
    Arr_e474e0 m_kPoints;
};

// Clamps t, walks the point array to find the segment nearest to nearPoint, interpolates pointOnCurve, and adjusts for closed loops.
// @fnv 0x00e474e0
float Curve_e474e0::FindNearestPoint(float t, const Vec_e474e0& nearPoint, Vec_e474e0& pointOnCurve)
{
    if (t < 0.0f)
    {
        t = 0.0f;
    }
    int ia = FUN_00cbfef0(t);
    int ib = ia + 1;
    if (ib >= m_kPoints.GetLogicalSize())
    {
        ib = m_kPoints.GetLogicalSize() - 1;
        ia = ib - 1;
    }

    float fraction = 0.0f;
    while (1)
    {
        Vec_e474e0 dir;
        dir.setSub4(m_kPoints[ib], m_kPoints[ia]);
        Vec_e474e0 a;
        a.setSub4(nearPoint, m_kPoints[ia]);
        fraction = a.dot3(dir) / dir.lengthSquared3();
        if (fraction < 0.0f)
        {
            if (ia == 0)
            {
                break;
            }
            ia--;
            ib--;
            continue;
        }
        Vec_e474e0 b;
        b.setSub4(nearPoint, m_kPoints[ib]);
        int ic = ib + 1;
        if (!(b.dot3(dir) <= 0.0f) && ic < m_kPoints.GetLogicalSize())
        {
            Vec_e474e0 dir1;
            dir1.setSub4(m_kPoints[ic], m_kPoints[ib]);
            if (dir1.dot3(b) > 0.0f)
            {
                ia++;
                ib++;
                continue;
            }
            dir.normalize3();
            dir1.normalize3();
            float fDot0 = dir.dot3(b);
            float fDot1 = dir1.dot3(b);
            if (-fDot1 > fDot0)
            {
                fraction = 0.99f;
            }
            else
            {
                fraction = 0.01f;
                ia++;
                ib++;
            }
        }
        break;
    }

    pointOnCurve.setInterpolate4(m_kPoints[ia], m_kPoints[ib], fraction);
    float result = (float)ia + fraction;
    if (m_bClosedLoop)
    {
        float end = (float)(m_kPoints.GetLogicalSize() - 1);
        if (result < 0.25f)
        {
            result = FindNearestPoint(end - (1.0f - result), nearPoint, pointOnCurve);
        }
        else if (result > end - 0.25)
        {
            result = FindNearestPoint(1.0f - (end - result), nearPoint, pointOnCurve);
        }
    }
    return result;
}
}  // namespace fnv_00e474e0

namespace fnv_00e478d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;
};

extern __m128 DAT_010ec7f0;

int __cdecl FUN_00cbfef0(hkReal r);

static __forceinline void hkSetSub4(hkVector4q& out, const hkVector4q& a, const hkVector4q& b)
{
    out.m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

static __forceinline void hkNormalize3(hkVector4q& v)
{
    __m128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkSetInterpolate4(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1, hkReal t)
{
    __m128 tt = _mm_set_ps1(t);
    __m128 s = _mm_sub_ps(DAT_010ec7f0, tt);
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(v1.m_vComponents, tt), _mm_mul_ps(s, v0.m_vComponents));
}

struct LinearCurveT : public hkpLinearParametricCurve
{
    __forceinline const hkVector4q& P(int i) const
    {
        return reinterpret_cast<const hkVector4q*>(m_kPoints.m_data)[i];
    }
    void GetTangent(hkReal t, hkVector4& tangentOut) const;
};

// Computes the smoothed tangent at parameter t by interpolating between adjacent segment directions and writing the result to tangentOut.
// @fnv 0x00e478d0
void LinearCurveT::GetTangent(hkReal t, hkVector4& tangentOut) const
{
    hkReal smooth = m_fSmoothingValue;
    hkReal invSmooth = 1.0f / smooth;

    int ia = FUN_00cbfef0(t);
    int ib = ia + 1;
    if (ib >= m_kPoints.m_iElementCount)
    {
        ib = m_kPoints.m_iElementCount - 1;
        ia = ib - 1;
    }
    else if (ia < 0)
    {
        ia = 0;
        ib = 1;
    }

    hkVector4q& tangent = reinterpret_cast<hkVector4q&>(tangentOut);

    hkReal dist = t - ia;
    hkSetSub4(tangent, P(ib), P(ia));
    hkNormalize3(tangent);

    if (dist < smooth && ia > 0)
    {
        ia--;
        ib--;
        hkVector4q prev;
        hkSetSub4(prev, P(ib), P(ia));
        hkNormalize3(prev);
        hkReal f = (smooth - dist) * 0.5 * invSmooth;
        hkSetInterpolate4(tangent, tangent, prev, f);
        hkNormalize3(tangent);
    }

    dist = ib - t;
    if (dist < smooth && ib < m_kPoints.m_iElementCount - 1)
    {
        hkVector4q next;
        hkSetSub4(next, P(ib + 1), P(ia + 1));
        hkNormalize3(next);
        hkReal f = (smooth - dist) * 0.5 * invSmooth;
        hkSetInterpolate4(tangent, tangent, next, f);
        hkNormalize3(tangent);
    }
}
}  // namespace fnv_00e478d0

int __cdecl FUN_00cbfef0(float f);

class FUN_00e47c30_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_uiArrayCount;
    int unk28;
    float* m_iSlotIds;

    float GetInterpolatedValue(float t) const;
};

// Linearly interpolates, or extrapolates past the ends, between entries of m_iSlotIds at t using the index from FUN_00cbfef0.
// @fnv 0x00e47c30
float FUN_00e47c30_cls::GetInterpolatedValue(float t) const
{
    int i = FUN_00cbfef0(t);
    float fInterval;
    if (i >= m_uiArrayCount - 1)
    {
        i = m_uiArrayCount - 1;
        fInterval = m_iSlotIds[i] - m_iSlotIds[i - 1];
    }
    else
    {
        if (i < 0)
            i = 0;
        fInterval = m_iSlotIds[i + 1] - m_iSlotIds[i];
    }
    return (t - i) * fInterval + m_iSlotIds[i];
}

struct MemoryManager
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* allocateChunk(int* reqBytes);
    virtual void deallocateChunk(void* p, int nbytes);
};

struct ThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryManager* m_pMemoryAllocator;
};

void* FUN_00c85750();

struct CurveHelper : public hkpLinearParametricCurve
{
    void CopyPoints(hkArray<hkVector4>& out) const;
};

// Copies m_kPoints into out, growing out's buffer via the thread memory manager if its capacity is too small.
// @fnv 0x00e47fa0
void CurveHelper::CopyPoints(hkArray<hkVector4>& out) const
{
    MemoryManager* mgr = ((ThreadMemory*)FUN_00c85750())->m_pMemoryAllocator;
    int cap = out.m_iCapacityState & 0x3fffffff;
    if (cap < this->m_kPoints.m_iElementCount)
    {
        if ((out.m_iCapacityState & 0x80000000) == 0)
        {
            mgr->deallocateChunk(out.m_data, cap * sizeof(hkVector4));
        }
        int reqBytes = this->m_kPoints.m_iElementCount * sizeof(hkVector4);
        out.m_data = (hkVector4*)mgr->allocateChunk(&reqBytes);
        out.m_iCapacityState = reqBytes / 16;
    }
    int count = this->m_kPoints.m_iElementCount;
    out.m_iElementCount = count;
    __m128* dst = (__m128*)out.m_data;
    const __m128* src = (const __m128*)this->m_kPoints.m_data;
    for (int i = 0; i < count; ++i)
    {
        dst[i] = src[i];
    }
}

namespace fnv_00e48030 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

static const float DAT_01011d78 = 0.0f;
static const float DAT_01012068 = 1.0f;

extern "C" __m128 _mm_setr_ps(float fA, float fB, float fC, float fD);

struct hkVector4E48
{
    __m128 m_vComponents;

    void set(float fA, float fB, float fC, float fD)
    {
        m_vComponents = _mm_setr_ps(fA, fB, fC, fD);
    }
};

class hkBoolE48
{
  public:
    hkBoolE48(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

template <class T> struct hkArrayE48
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE48() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectE48
{
  public:
    virtual ~hkBaseObjectE48() throw();
};

class hkReferencedObjectE48 : public hkBaseObjectE48
{
  public:
    hkReferencedObjectE48() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE48() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e48030 : public hkReferencedObjectE48
{
  public:
    FUN_00e48030() throw();
    virtual ~FUN_00e48030() throw();

    float m_fSmoothingValue;
    hkBoolE48 m_bClosedLoop;
    hkVector4E48 m_kVector4;
    hkArrayE48<hkVector4E48> m_kPoints;
    hkArrayE48<float> m_fClosestPointDistanceSquared;
    unsigned int unk38, unk3C;
};

// Constructs the object, initializing m_fSmoothingValue to 0.01f, m_bClosedLoop to false, and m_kVector4 to (0, 1, 0, 0).
// @fnv 0x00e48030
FUN_00e48030::FUN_00e48030() throw() : m_fSmoothingValue(0.01f), m_bClosedLoop(false)
{
    m_kVector4.set(DAT_01011d78, DAT_01012068, DAT_01011d78, DAT_01011d78);
}
}  // namespace fnv_00e48030

extern "C" __m128 _mm_load_ps(const float*);

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern float DAT_01011d78;
struct Allocator
{
    virtual void dummy0();
    virtual void* allocateChunk(int size);
    virtual void dummy2();
    virtual void* allocate(int* reqSize);
    virtual void deallocate(void* ptr, int size);
};
struct CurveThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pThreadAllocator;
};
extern "C" void* __fastcall FUN_00e48030(void* p);
class ScalarLane
{
    __m128 value;

  public:
    inline ScalarLane(const __m128& v) : value(v)
    {}
    inline operator float() const
    {
        float component;
        _mm_store_ss(&component, value);
        return component;
    }
};
class QuadView
{
    __m128 value;

  public:
    __forceinline ScalarLane lane(int i) const
    {
        switch (i)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 85);
        case 2:
            return _mm_shuffle_ps(value, value, 170);
        default:
            return _mm_shuffle_ps(value, value, 255);
        }
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        value = _mm_setr_ps(a, b, c, d);
    }
};

struct LinearParametricCurve : public hkReferencedObject
{
    float m_fSmoothingValue;
    char m_bClosedLoop;
    QuadView m_kVector4;
    hkArray<hkVector4> m_kPoints;
    hkArray<float> m_fClosestPointDistanceSquared;
    LinearParametricCurve* FUN_00e48090();
    void FUN_00e47e80(const hkVector4*);
};
static __forceinline LinearParametricCurve* createCurve()
{
    CurveThreadMemory* memory = (CurveThreadMemory*)FUN_00c85750();
    void* chunk = memory->m_pThreadAllocator->allocateChunk(0x40);
    ((hkReferencedObject*)chunk)->m_usMemSizeAndFlags = 0x40;
    return (LinearParametricCurve*)FUN_00e48030(chunk);
}
template <class T> static __forceinline void arrCopy_e48090(T* dst, int start, const T* src, int n)
{
    for (; start < n; ++start)
    {
        dst[start] = src[start];
    }
}
template <class T>
static __forceinline void copyFromArray_e48090(hkArray<T>& self, Allocator* alloc, const hkArray<T>& a)
{
    if ((self.m_iCapacityState & 0x3fffffff) < a.m_iElementCount)
    {
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc->deallocate(self.m_data, (self.m_iCapacityState & 0x3fffffff) * int(sizeof(T)));
        }
        int numBytes = a.m_iElementCount * int(sizeof(T));
        self.m_data = (T*)alloc->allocate(&numBytes);
        self.m_iCapacityState = numBytes / int(sizeof(T));
    }
    self.m_iElementCount = a.m_iElementCount;
    arrCopy_e48090(self.m_data, 0, a.m_data, self.m_iElementCount);
}
// @fnv 0x00e48090
LinearParametricCurve* LinearParametricCurve::FUN_00e48090()
{
    LinearParametricCurve* clone = createCurve();
    int numPoints = this->m_kPoints.m_iElementCount;
    if (0 < numPoints)
    {
        for (int i = 0; i < numPoints; ++i)
        {
            clone->FUN_00e47e80(&this->m_kPoints.m_data[i]);
        }
    }
    clone->m_bClosedLoop = this->m_bClosedLoop;
    clone->m_kVector4.set(m_kVector4.lane(0), m_kVector4.lane(1), m_kVector4.lane(2), 0.0f);
    copyFromArray_e48090(clone->m_fClosestPointDistanceSquared,
                         ((CurveThreadMemory*)FUN_00c85750())->m_pThreadAllocator,
                         this->m_fClosestPointDistanceSquared);
    clone->m_fSmoothingValue = this->m_fSmoothingValue;
    return clone;
}

#include <math.h>
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

extern hkVector4q DAT_01268380;

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline hkReal hkDot3(const hkVector4q& a, const hkVector4q& b)
{
    __m128 x2 = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    __m128 xyz = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
    hkReal r;
    _mm_store_ss(&r, xyz);
    return r;
}

static __forceinline void hkNormalize3(hkVector4q& v)
{
    __m128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4q& in, hkVector4q& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct LinearCurve : public hkpLinearParametricCurve
{
    virtual void GetBoxVector(hkReal t, hkVector4& pointOnCurve) const;
    virtual void setStart(const hkVector4& start);
    virtual void setEnd(const hkVector4& end);
    virtual hkReal GetStreamStart() const;
    virtual void GetTangentAt(hkReal t, hkVector4& tangent) const;

    void getBinormal(hkReal t, hkVector4& up) const;
};

// Computes a normalized up vector for the curve at t by crossing or perpendicularizing the tangent against m_kVector4.
// @fnv 0x00e47cb0
void LinearCurve::getBinormal(hkReal t, hkVector4& up) const
{
    hkVector4q tangent;
    GetTangentAt(t, tangent.m_vec);

    hkVector4q& out = reinterpret_cast<hkVector4q&>(up);
    if (hkDot3(DAT_01268380, tangent) < (double)0.98f)
    {
        hkSetCross(out, tangent, reinterpret_cast<const hkVector4q&>(m_kVector4));
    }
    else
    {
        hkCalculatePerpendicularVector(tangent, out);
    }
    hkNormalize3(out);
}

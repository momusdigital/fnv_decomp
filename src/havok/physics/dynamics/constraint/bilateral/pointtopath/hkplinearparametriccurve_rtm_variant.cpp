// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpLinearParametricCurve.h"
struct FUN_00e47c20_s
{
    double FUN_00e47c20() const;
};
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
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    float value;
    void FUN_00e47430(float input);
};
struct FnvCpu_FUN_00e47400_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    unsigned char* FUN_00e47400(unsigned char* output);
};
float __cdecl GetZeroFloat();
class CurveSmoothingGetter : public hkpParametricCurve
{
  public:
    float m_fSmoothingValue;
    float FUN_00e47420() const;
};
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

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_load_ss(float const*);

void __cdecl ResizeAudioStream(void* pvAllocator, void* apvArray, int iElemSize);

struct S00e47e80_hkMemoryRouterE47E
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_pStreamAllocator;
};

struct __declspec(align(16)) hkVector4E47E
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
    void operator=(const hkVector4E47E& v)
    {
        getQuad() = v.getQuad();
    }
};

template <class T> struct S00e47e80_hkArrayE47E
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }

    __forceinline T* _pushBack(void* pvAllocator, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(pvAllocator, this, sizeof(T));
        T* p = &m_data[m_iElementCount];
        *p = t;
        m_iElementCount++;
        return p;
    }
    __forceinline T* AddBack(const T& t)
    {
        S00e47e80_hkMemoryRouterE47E* pkRouter = (S00e47e80_hkMemoryRouterE47E*)FUN_00c85750();
        return _pushBack(pkRouter->m_pStreamAllocator, t);
    }
};

class S00e47e80_hkpLinearParametricCurveE47E
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    float m_fSmoothingValue;
    char m_bClosedLoop;
    hkVector4E47E m_kVector4;
    S00e47e80_hkArrayE47E<hkVector4E47E> m_kPoints;
    S00e47e80_hkArrayE47E<float> m_fClosestPointDistanceSquared;

    float* FUN_00e47e80(const hkVector4E47E& kPoint) throw();
};

// @fnv 0x00e47e80
float* S00e47e80_hkpLinearParametricCurveE47E::FUN_00e47e80(const hkVector4E47E& kPoint) throw()
{
    m_kPoints.AddBack(kPoint);
    if (m_kPoints.GetLogicalSize() == 1)
        return m_fClosestPointDistanceSquared.AddBack(0.0f);

    hkVector4E47E kPrev = m_kPoints[m_kPoints.GetLogicalSize() - 2];
    __m128 kDiff = _mm_sub_ps(kPoint.getQuad(), kPrev.getQuad());
    __m128 kSq = _mm_mul_ps(kDiff, kDiff);
    __m128 kSum = _mm_add_ss(_mm_shuffle_ps(kSq, kSq, 0xaa), _mm_add_ss(_mm_shuffle_ps(kSq, kSq, 0x55), kSq));
    __m128 kLen =
        _mm_add_ss(_mm_sqrt_ss(kSum),
                   _mm_load_ss(&m_fClosestPointDistanceSquared[m_fClosestPointDistanceSquared.GetLogicalSize() - 1]));
    float fDist;
    _mm_store_ss(&fDist, kLen);
    return m_fClosestPointDistanceSquared.AddBack(fDist);
}

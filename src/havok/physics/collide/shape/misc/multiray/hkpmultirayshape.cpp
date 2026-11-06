
// src/havok/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMultiRayShape.h"

// castRayImpl: stores zero byte through first stdcall argument and returns it.

// @fnv 0x00e3c610
unsigned char* __stdcall castRayImpl(unsigned char* out, int a1, int a2)
{
    *out = 0;
    return out;
}

// @fnv 0x00e3c600
void __stdcall FUN_00e3c600(int a1, int a2, int a3)
{}

class hkClassE3C6;

extern const hkClassE3C6 DAT_01268910;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayE3C6
{
  public:
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
};

class hkStatisticsCollectorE3C6
{
  public:
    virtual ~hkStatisticsCollectorE3C6() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayE3C6<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

struct hkVector4E3C6
{
    float x, y, z, w;
};

struct hkRayE3C6
{
    hkVector4E3C6 m_vFrom;
    hkVector4E3C6 m_vTo;
};

class hkpShapeE3C6
{
  public:
    void FUN_00c90360(hkStatisticsCollectorE3C6* pkCollector, const hkClassE3C6* pkClass) const throw();
};

class hkObjE3C6 : public hkpShapeE3C6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArrayE3C6<hkRayE3C6> m_kRays;

    void AddRaysToStatistics(hkStatisticsCollectorE3C6* pkCollector, const hkClassE3C6* pkClass) const throw();
};

// Adds the Rays array to the statistics collector, then reports the base shape's statistics with the class descriptor.
// @fnv 0x00e3c620
void hkObjE3C6::AddRaysToStatistics(hkStatisticsCollectorE3C6* pkCollector, const hkClassE3C6* pkClass) const throw()
{
    pkCollector->addArray("Rays", m_kRays);
    FUN_00c90360(pkCollector, &DAT_01268910);
}

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
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}

extern float DAT_0104da48;
extern float DAT_0104e148;

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" NineIntegerRecord* FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int reqCapacity, int elemSize);

union hkQuadVector
{
    hkVector4 v;
    __m128 q;
};

struct __declspec(align(16)) hkWorldRay
{
    __m128 m_kRayStart;
    __m128 m_kRayEnd;
};

struct hkWorldRayArray
{
    hkWorldRay* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(hkWorldRay));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(FUN_00c85750()->heap(), n);
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(hkWorldRay));
    }
};

struct hkInplaceWorldRayArray : hkWorldRayArray
{
    hkWorldRay m_kStorage[16];
    __forceinline hkInplaceWorldRayArray()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000010;
    }
};

static __forceinline __m128 loadQuad(const hkVector4& v)
{
    hkQuadVector u;
    u.v = v;
    return u.q;
}

static __forceinline void TransformPointArray(const hkTransform& t, const __m128* vectorsIn, int numVectors,
                                              __m128* vectorsOut)
{
    hkQuadVector c0;
    c0.v = t.m_rotation.m_kColumn0;
    const __m128 q0 = c0.q;
    const __m128 q1 = loadQuad(t.m_rotation.m_kColumn1);
    const __m128 q2 = loadQuad(t.m_rotation.m_kColumn2);
    const __m128 RunFourthVirtual = loadQuad(t.m_vTranslation);
    int i = numVectors - 1;
    do
    {
        __m128 b = vectorsIn[i];
        __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
        __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
        __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
        __m128 r0 = _mm_mul_ps(b0, q0);
        __m128 r1 = _mm_mul_ps(b1, q1);
        __m128 r2 = _mm_mul_ps(b2, q2);
        vectorsOut[i] = _mm_add_ps(_mm_add_ps(r1, r0), _mm_add_ps(r2, RunFourthVirtual));
        i--;
    } while (i >= 0);
}

struct hkAabbQ
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

class hkpMultiRayShapeImpl : public hkpMultiRayShape
{
  public:
    void FUN_00e3c800(const hkTransform& localToWorld, hkReal tolerance, hkAabbQ& out) const;
};

// Transforms the shape's rays into world space and computes their combined axis-aligned bounding box into out.
// @fnv 0x00e3c800
void hkpMultiRayShapeImpl::FUN_00e3c800(const hkTransform& localToWorld, hkReal tolerance, hkAabbQ& out) const
{
    hkInplaceWorldRayArray worldRays;
    worldRays.SetSizeAndGrow(m_kRays.m_iElementCount);
    TransformPointArray(localToWorld, reinterpret_cast<const __m128*>(m_kRays.m_data), m_kRays.m_iElementCount * 2,
                        &worldRays.m_data[0].m_kRayStart);

    __m128 mn = _mm_set_ps1(DAT_0104da48);
    __m128 mx = _mm_set_ps1(DAT_0104e148);
    const hkWorldRay* ray = worldRays.m_data;
    for (int i = 0; i < worldRays.m_iElementCount; i++, ray++)
    {
        mn = _mm_min_ps(mn, ray->m_kRayEnd);
        mx = _mm_max_ps(mx, ray->m_kRayEnd);
        mn = _mm_min_ps(mn, ray->m_kRayStart);
        mx = _mm_max_ps(mx, ray->m_kRayStart);
    }
    out.m_kMinimumCorner = mn;
    out.m_kMaximumCorner = mx;
    worldRays._clearAndDeallocate(FUN_00c85750()->heap());
}

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_load_ps1(float const*);
    void _mm_store_ss(float*, __m128);
}
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* array, int numElem, int sizeElem);
struct RayStandIn
{
    __m128 m_kRayStart;
    __m128 m_kRayEnd;
};

struct RayArrayStandIn
{
    RayStandIn* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    RayArrayStandIn() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(RayStandIn));
        }
    }
    RayStandIn* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    RayStandIn* expandBy(int n)
    {
        return _expandBy(FUN_00c85750()->heap(), n);
    }
};

struct RefObjStandIn
{
    virtual ~RefObjStandIn();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    RefObjStandIn() : m_sReferenceCount(1)
    {}
};

struct ShapeStandIn : RefObjStandIn
{
    unsigned long m_ulUserData;
    unsigned int m_type;
    ShapeStandIn(unsigned int type) : m_ulUserData(0), m_type(type)
    {}
};

static inline __m128 dot3(__m128 a)
{
    __m128 x2 = _mm_mul_ps(a, a);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
}

struct FUN_00e3c680 : ShapeStandIn
{
    RayArrayStandIn m_kRays;
    float m_fRayRadius;
    FUN_00e3c680(const RayStandIn* rays, int nRays, float rayPenetrationDistance);
    virtual ~FUN_00e3c680();
};

// Copies rays, computes their length, normalizes the direction, and extends the end by m_fRayRadius.
// @fnv 0x00e3c680
FUN_00e3c680::FUN_00e3c680(const RayStandIn* rays, int nRays, float rayPenetrationDistance) : ShapeStandIn(0x18)
{
    m_fRayRadius = rayPenetrationDistance;
    RayStandIn* ray = m_kRays.expandBy(nRays);
    for (int i = nRays - 1; i >= 0; i--)
    {
        ray->m_kRayStart = rays->m_kRayStart;
        ray->m_kRayEnd = rays->m_kRayEnd;
        __m128 vec = _mm_sub_ps(ray->m_kRayEnd, ray->m_kRayStart);
        {
            float len;
            _mm_store_ss(&len, _mm_sqrt_ss(dot3(vec)));
            ray->m_kRayStart.m128_f32[3] = len;
        }
        {
            __m128 len2 = dot3(vec);
            __m128 e = _mm_rsqrt_ss(len2);
            __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                                  _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
            r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
            vec = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), vec);
        }
        __m128 dd = _mm_load_ps1(&m_fRayRadius);
        ray->m_kRayEnd = _mm_add_ps(_mm_mul_ps(vec, dd), ray->m_kRayEnd);
        ray++;
        rays++;
    }
}

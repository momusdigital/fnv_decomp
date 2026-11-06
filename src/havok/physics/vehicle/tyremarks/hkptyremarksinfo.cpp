
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTyremarksInfo.h"

class hkClassE39E;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayE39E
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

class hkStatisticsCollectorE39E
{
  public:
    virtual ~hkStatisticsCollectorE39E() throw();
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

    template <class T> void addArray(const char* pcName, const hkArrayE39E<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

struct hkVector4E39E
{
    float x, y, z, w;
};

struct hkRayE39E
{
    hkVector4E39E m_vFrom;
    hkVector4E39E m_vTo;
};

class hkPointSetE39E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArrayE39E<hkRayE39E> m_kPoints;
};

class hkObjE39E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArrayE39E<hkPointSetE39E*> m_kPointSets;

    void calcContentStatistics(hkStatisticsCollectorE39E* pkCollector, const hkClassE39E* pkClass) const throw();
};

// For each point set in the array, adds its ray array to the statistics collector under the name "Points".
// @fnv 0x00e39ee0
void hkObjE39E::calcContentStatistics(hkStatisticsCollectorE39E* pkCollector, const hkClassE39E* pkClass) const throw()
{
    for (int i = 0; i < m_kPointSets.GetLogicalSize(); i++)
        pkCollector->addArray("Points", m_kPointSets.m_data[i]->m_kPoints);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct __declspec(align(16)) hkVector4E39F
{
    __m128 m_vComponents;

    void operator=(const hkVector4E39F& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkSampleE39F
{
    hkVector4E39F m_vContactPosition;
    hkVector4E39F m_fVelocity;

    float FUN_00e39e80() const;
};

__declspec(noinline) float hkSampleE39F::FUN_00e39e80() const
{
    return m_fVelocity.m_vComponents.m128_f32[3];
}

class hkSampleRingE39F
{
  public:
    int unk00;
    int unk04;
    int m_pFirstNode;
    int m_pRayCursor;
    hkSampleE39F* m_samples;

    void FUN_00e39f50(const hkSampleE39F& sample);
};

// Copies sample into the slot at m_pFirstNode and advances it with wraparound, unless the sample and the previous slot both give 0 from FUN_00e39e80.
// @fnv 0x00e39f50
void hkSampleRingE39F::FUN_00e39f50(const hkSampleE39F& sample)
{
    if (sample.FUN_00e39e80() == 0.0f && m_samples[(m_pFirstNode + m_pRayCursor - 1) % m_pRayCursor].FUN_00e39e80() == 0.0f)
        return;
    hkSampleE39F& dst = m_samples[m_pFirstNode];
    dst.m_vContactPosition = sample.m_vContactPosition;
    dst.m_fVelocity = sample.m_fVelocity;
    m_pFirstNode = (m_pFirstNode + 1) % m_pRayCursor;
}

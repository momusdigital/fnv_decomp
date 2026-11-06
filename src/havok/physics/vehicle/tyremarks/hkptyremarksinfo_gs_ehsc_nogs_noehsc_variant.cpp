
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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

#include <xmmintrin.h>
struct __declspec(align(16)) hkpTyremarkV
{
    float m_uiX, m_uiY, m_uiZ, m_w;
};

struct __declspec(align(16)) hkpTyremark
{
    hkpTyremarkV m_kPointA, m_kPointB;
};

class hkpTyremarksWheel
{
  public:
    int unk00;
    int unk04;
    int m_iMaxNumTyremarks;
    int m_numTyremarks;
    hkpTyremark* m_data;
    hkpTyremark* __thiscall ComputeIndex(int index);
};

__declspec(noinline) hkpTyremark* __thiscall hkpTyremarksWheel::ComputeIndex(int index)
{
    return &m_data[(m_iMaxNumTyremarks + index) % m_numTyremarks];
}

struct hkArrayWheel
{
    hkpTyremarksWheel** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S00e39e90_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArrayWheel m_kTyremarksWheels;

    void __thiscall FUN_00e39e90(int arg1, int wheelIndex, hkpTyremark* out);
};

// @fnv 0x00e39e90
void __thiscall S00e39e90_Info::FUN_00e39e90(int arg1, int wheelIndex, hkpTyremark* out)
{
    hkpTyremarksWheel* wheel = m_kTyremarksWheels.m_data[wheelIndex];
    int n = wheel->m_numTyremarks;
    int i = 0;

    if (n > 0)
    {
        hkpTyremark* dst = out;

        do
        {
            hkpTyremark* src = wheel->ComputeIndex(i);
            _mm_store_ps(&dst->m_kPointA.m_uiX, _mm_load_ps(&src->m_kPointA.m_uiX));
            _mm_store_ps(&dst->m_kPointB.m_uiX, _mm_load_ps(&src->m_kPointB.m_uiX));
            i++;
            dst++;
        } while (i < n);
    }
}

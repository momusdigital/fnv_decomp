
// src/havok/physics/collide/shape/compound/collection/list/hkplistshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/list/hkplistshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpListShape.h"

struct hkPListShape
{
    void __thiscall SetChildShape(int index, void* shape);
};
// @fnv 0x00cf50a0
void __thiscall hkPListShape::SetChildShape(int index, void* shape)
{
    *(void**)((char*)*(int*)((char*)this + 0x18) + (index << 4) + 4) = shape;
}

struct FUN_00cf5070_class
{
    void* GetShapeAt(int index, void* buffer);
};

// @fnv 0x00cf5070
void* FUN_00cf5070_class::GetShapeAt(int index, void* buffer)
{
    void** shapes = *(void***)((char*)this + 8);
    return *(void**)((char*)shapes + (index << 4));
}

struct hkPListShape2
{
    int __thiscall GetElementAt(int index);
};

// @fnv 0x00cf5080
int hkPListShape2::GetElementAt(int index)
{
    return *(int*)(*(int*)((char*)this + 8) + (index << 4) + 4);
}

struct S_00cf5880
{
    int unk0;
    void FindNextEnabledChild(int a);
    void FUN_00cf5880();
};
// @fnv 0x00cf5880
void S_00cf5880::FUN_00cf5880()
{
    FindNextEnabledChild(-1);
}

struct __declspec(align(16)) BufAligned32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00cf4fb0_Obj
{
    void FUN_00cf4fb0(void* a1);
};

struct FUN_00cf5420_class
{
    void FUN_00cf5420();
};

// @fnv 0x00cf5420
void FUN_00cf5420_class::FUN_00cf5420()
{
    BufAligned32 bufAligned;
    FUN_00cf4fb0_Obj* obj = (FUN_00cf4fb0_Obj*)this;
    obj->FUN_00cf4fb0(&bufAligned);
}

class hkClassCF54;

extern const hkClassCF54 DAT_01269198;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayCF54
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

class hkStatisticsCollectorCF54
{
  public:
    virtual ~hkStatisticsCollectorCF54() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayCF54<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

struct hkChildInfoCF54
{
    const void* m_pCollisionShape;
    int m_04;
    int m_08;
    int m_0c;
};

class hkpShapeCF54
{
  public:
    void FUN_00d213e0(hkStatisticsCollectorCF54* pkCollector, const hkClassCF54* pkClass) const throw();
};

class hkObjCF54 : public hkpShapeCF54
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkArrayCF54<hkChildInfoCF54> m_kChildInfoList;

    void AddChildObjectsToCollector(hkStatisticsCollectorCF54* pkCollector, const hkClassCF54* pkClass) const throw();
};

// @fnv 0x00cf5440
void hkObjCF54::AddChildObjectsToCollector(hkStatisticsCollectorCF54* pkCollector, const hkClassCF54* pkClass) const
    throw()
{
    pkCollector->addArray("ChildPtrs", m_kChildInfoList);
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
        pkCollector->addChildObject("Child", m_kChildInfoList.m_data[i].m_pCollisionShape, 0);
    FUN_00d213e0(pkCollector, &DAT_01269198);
}

struct hkFinishFlagCF56
{
    int m_bFinishing;
};

class hkLevel0CF56
{
  public:
    virtual ~hkLevel0CF56() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int m_type;

    hkLevel0CF56(hkFinishFlagCF56 flag)
    {
        if (flag.m_bFinishing)
            m_type = 0;
    }
};

class hkIfaceCF56
{
  public:
    virtual void i0() = 0;
    char unk14;
    char m_15;
};

class hkLevel1CF56 : public hkLevel0CF56, public hkIfaceCF56
{
  public:
    hkLevel1CF56(hkFinishFlagCF56 flag) : hkLevel0CF56(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_15 = 3;
        }
    }
};

class FUN_00cf56f0 : public hkLevel1CF56
{
  public:
    FUN_00cf56f0(hkFinishFlagCF56 flag) throw();
    virtual ~FUN_00cf56f0() throw();
    virtual void i0();
};

// @fnv 0x00cf56f0
FUN_00cf56f0::FUN_00cf56f0(hkFinishFlagCF56 aFinishFlag) throw() : hkLevel1CF56(aFinishFlag)
{
    if (aFinishFlag.m_bFinishing)
    {
        m_type = 9;
        m_15 = 0;
    }
}

struct hkListShapeCF58
{
    int unk00;
    int unk04;
    void* m_kChildInfoList;
    int m_childInfoSize;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned int m_uiChildEnabledFlags[8];

    unsigned int isChildEnabled(unsigned int index) const
    {
        if (index < 256)
            return m_uiChildEnabledFlags[index >> 5] & (1 << (index & 31));
        return 1;
    }

    int FindNextEnabledChild(int oldKey) const;
};

// Scans child indices after oldKey up to m_childInfoSize and returns the first enabled one, or -1 if none.
// @fnv 0x00cf5840
int hkListShapeCF58::FindNextEnabledChild(int oldKey) const
{
    for (int i = oldKey + 1; i < m_childInfoSize; i++)
    {
        if (isChildEnabled(i))
            return i;
    }
    return -1;
}

struct FnvCpu_FUN_00cf5890_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cf5890_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cf5890_CpuAllocator* allocator;
};
FnvCpu_FUN_00cf5890_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00cf5890_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cf5750();
    FnvCpu_FUN_00cf5890_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00cf5750, then if flags has bit 0 set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00cf5890
FnvCpu_FUN_00cf5890_CpuObject* FnvCpu_FUN_00cf5890_CpuObject::Destroy(unsigned int flags)
{
    FUN_00cf5750();
    if (flags & 1)
    {
        FnvCpu_FUN_00cf5890_CpuAllocatorHolder* pAllocatorHolder = FUN_00c85750();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

class hkMemoryAllocatorCF56;

struct hkMemoryRouterCF56
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorCF56* m_pStreamAllocator;
    hkMemoryAllocatorCF56& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterCF56& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorCF56& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayCF56
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayCF56() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorCF56& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
};

struct hkVector4CF56
{
    float x, y, z, w;
};

class ShapeBaseCF56
{
  public:
    virtual void vfn_00();
    int unk04, unk08, unk0C;
};

class ListenerBaseCF56
{
  public:
    virtual void vfn_10();
    int unk14;
};

class FUN_00d21410 : public ShapeBaseCF56, public ListenerBaseCF56
{
  public:
    FUN_00d21410(int iType, int iFlags) throw();
};

class FUN_00cf5640 : public FUN_00d21410
{
  public:
    hkArrayCF56<hkVector4CF56> m_kPoints;
    short m_flags24;
    short m_flags26;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int m_aiIds[8];

    FUN_00cf5640(int iA, int iB, int iC) throw();
    void FUN_00cf54d0(int iA, int iB, int iZero, int iC) throw();
};

// Constructs a shape by reserving 4 points, calling FUN_00cf54d0 with iA, iB, 0, iC, and initializing m_aiIds to -1 and flags to 0.
// @fnv 0x00cf5640
FUN_00cf5640::FUN_00cf5640(int iA, int iB, int iC) throw() : FUN_00d21410(9, 0)
{
    m_kPoints.reserve(4);
    FUN_00cf54d0(iA, iB, 0, iC);
    for (int i = 0; i < 8; i++)
        m_aiIds[i] = -1;
    m_flags26 = 0;
    m_flags24 = 0;
}

struct Stream_cf50c0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int CalcSizeForSpu(const bool& input, int iSize) const;
};
struct Entry_cf50c0
{
    const Stream_cf50c0* m_pCollisionShape;
    int m_uiFilterInfo;
    int m_iShapeKey;
    int m_iChildShapeCount;
};
template <class T> struct ArrCF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
struct ListShapeCF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ArrCF<Entry_cf50c0> m_kChildInfoList;
    int calcSizeForSpu(const bool& input, int spuBufferSizeLeft);
};
// @fnv 0x00cf50c0
int ListShapeCF::calcSizeForSpu(const bool& input, int spuBufferSizeLeft)
{
    if (input && m_kChildInfoList.GetLogicalSize() > 252)
        return -1;
    if (m_kChildInfoList.GetLogicalSize() >= 4095)
        return -1;
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
    {
        m_kChildInfoList[i].m_iShapeKey = m_kChildInfoList[i].m_pCollisionShape->CalcSizeForSpu(input, 256);
        m_kChildInfoList[i].m_iChildShapeCount = m_kChildInfoList.GetLogicalSize();
        if (m_kChildInfoList[i].m_iShapeKey == -1)
            return -1;
    }
    return 0x70;
}

struct ShapeAlloc;
struct ShapeRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ShapeAlloc* m_pStreamAllocator;
    ShapeAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(void* allocator, void* array, int capacity, int elementSize);
void __cdecl FUN_00c90670(void* data, int count, int elementSize);

struct ListShapeCF54 : public hkpListShape
{
    void FUN_00cf5420();
    void FUN_00cf54d0(int* shapes, int count, int* shapeData, int flag);
};

// Copies shape and filter data into m_kChildInfoList, growing capacity as needed, then calls FUN_00cf5420.
// @fnv 0x00cf54d0
void ListShapeCF54::FUN_00cf54d0(int* shapes, int count, int* shapeData, int flag)
{
    hkArray<hkpListShapeChildInfo>& children = m_kChildInfoList;
    ShapeAlloc& heap = reinterpret_cast<ShapeRouter*>(FUN_00c85750())->heap();
    int capacity = children.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        int increasedCapacity = capacity * 2;
        if (count >= increasedCapacity)
            increasedCapacity = count;
        FUN_00c908c0(&heap, &children, increasedCapacity, 16);
    }
    children.m_iElementCount = count;
    if (count > 0)
    {
        int* current = shapes;
        int offset = 0;
        volatile int difference = (int)shapeData - (int)shapes;
        int remaining = count;
        do
        {
            int shape = *current;
            if (shape)
            {
                *(int*)((char*)children.m_data + offset) = shape;
                int filter = shapeData ? *(int*)((char*)current + difference) : 0;
                *(int*)((char*)children.m_data + offset + 4) = filter;
                *(int*)((char*)this->m_kChildInfoList.m_data + offset + 12) = count;
                *(int*)((char*)this->m_kChildInfoList.m_data + offset + 8) = 0;
            }
            ++current;
            offset += 16;
        } while (--remaining);
    }
    if (flag == 1)
        FUN_00c90670(children.m_data, this->m_kChildInfoList.m_iElementCount, 16);
    FUN_00cf5420();
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
    __m128 _mm_load_ps1(const float* p);
    __m128 _mm_set1_ps(float a);
    __m128 _mm_set_ps1(float a);
    __m128 _mm_xor_ps(__m128 a, __m128 b);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
}

struct hkVector4q
{
    __m128 m_vComponents;

    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(const float& x)
    {
        m_vComponents = _mm_load_ps1(&x);
    }
    __forceinline void setNeg4(const hkVector4q& v);
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline int compareLessThanEqual4(const hkVector4q& v) const
    {
        return _mm_movemask_ps(_mm_cmple_ps(m_vComponents, v.m_vComponents));
    }
};

extern const hkVector4q DAT_01267e30;  // HK_QUADREAL_MINUS1
extern const float DAT_010cc3b0;       // HK_REAL_MAX
extern const hkVector4q DAT_010c44d0;  // sign mask

__forceinline void hkVector4q::setNeg4(const hkVector4q& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0.m_vComponents);
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

class hkpShapeq
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const hkTransform& localToWorld, float tolerance, hkAabbq& out) const;
};

struct hkpListShapeChildInfoq
{
    hkpShapeq* m_pCollisionShape;
    unsigned int m_uiCollisionFilterData;
    int m_iShapeKey;
    int m_iChildShapeCount;
};

class hkpListShapeq
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_usMemSizeAndFlags;
    unsigned int m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    unsigned int unk14;
    hkArray<hkpListShapeChildInfoq> m_kChildInfoList;
    unsigned short m_flags;
    unsigned short m_usNumDisabledChildren;
    unsigned int unk28;
    unsigned int unk2C;
    hkVector4q m_kAabbHalfExtents;
    hkVector4q m_kAabbCenter;

    void FUN_00cf5420();
    void FUN_00cf5590(const hkTransform& localToWorld, float tolerance, hkAabbq& out);
};

// Computes the combined AABB of all child shapes by querying each child's AABB and merging the min and max corners.
// @fnv 0x00cf5590
void hkpListShapeq::FUN_00cf5590(const hkTransform& localToWorld, float tolerance, hkAabbq& out)
{
    if (m_kAabbHalfExtents.compareLessThanEqual4(DAT_01267e30) == 15)
    {
        FUN_00cf5420();
    }

    out.m_kMinimumCorner.m_vComponents = _mm_set_ps1(1.70141001e+38f);
    out.m_kMaximumCorner.setNeg4(out.m_kMinimumCorner);

    for (int i = 0; i < m_kChildInfoList.m_iElementCount; i++)
    {
        hkAabbq childAabb;
        const hkpShapeq* childShape = m_kChildInfoList.m_data[i].m_pCollisionShape;
        childShape->getAabb(localToWorld, tolerance, childAabb);
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, childAabb.m_kMinimumCorner);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, childAabb.m_kMaximumCorner);
    }
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <string.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010cc398[];
extern const char str_010c41f8[];

struct S00cf5140_Bool
{
    char m_cBooleanValue;
    S00cf5140_Bool()
    {}
    S00cf5140_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S00cf5140_Input
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
    const struct S00cf5140_Filter* m_pRayShapeCollectionFilter;
};

struct S00cf5140_Output
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

struct S00cf5140_Container
{
    int unk00;
};

struct S00cf5140_Filter
{
    virtual S00cf5140_Bool IsCollisionEnabled(const S00cf5140_Input& aInput, const hkpShape& shape,
                                              const S00cf5140_Container& container, unsigned int aKey) const;
};

struct S00cf5140_ShapeIface
{
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual S00cf5140_Bool RayCast(const S00cf5140_Input& input, S00cf5140_Output& output) const;
};

class hkpListShapeChildInfo
{
  public:
    const S00cf5140_ShapeIface* m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0c;
};

struct S00cf5140_Stream
{
    int unk0;
    char* m_curr;
    int unk8;
    char* m_kRayEnd;

    void timerBegin(const char* name)
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = name;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0)
                memmove(&tb, &tb, 4);
            p += 12;
            m_curr = p;
        }
    }

    void timerEnd()
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0)
                memmove(&te, &te, 4);
            p += 12;
            m_curr = p;
        }
    }
};

struct S00cf5140_Obj : public hkpListShape
{
    unsigned int isChildEnabled(unsigned int i) const
    {
        if (i < 0x100)
        {
            return m_uiChildEnabledFlags[i >> 5] & (1 << (i & 0x1f));
        }
        return 1;
    }

    S00cf5140_Bool castRayImpl(const S00cf5140_Input& input, S00cf5140_Output& results) const;
};

// Performs a ray cast against all enabled child shapes of this list shape, recording the hit child index in the output and returning whether any child was hit.
// @fnv 0x00cf5140
S00cf5140_Bool S00cf5140_Obj::castRayImpl(const S00cf5140_Input& input, S00cf5140_Output& results) const
{
    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerBegin(str_010cc398);

    results.m_uiShapeKeyIndex++;
    int hitChild = -1;

    if (!input.m_pRayShapeCollectionFilter)
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                const S00cf5140_ShapeIface* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                S00cf5140_Bool hit = child->RayCast(input, results);
                if (hit)
                {
                    hitChild = i;
                }
            }
        }
    }
    else
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(
                        input, *this, *reinterpret_cast<const S00cf5140_Container*>(&pad10), i))
                {
                    const S00cf5140_ShapeIface* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                    S00cf5140_Bool hit = child->RayCast(input, results);
                    if (hit)
                    {
                        hitChild = i;
                    }
                }
            }
        }
    }

    results.m_uiShapeKeyIndex--;
    if (hitChild != -1)
    {
        results.m_uiShapeKeys[results.m_uiShapeKeyIndex] = hitChild;
    }

    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerEnd();
    return hitChild != -1;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00cf5820();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00cf5820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf5820
    virtual void FUN_00cf5820();
};

Derived::Derived()
{}

namespace fnv_00cf5750 {
class hkMemoryAllocatorCF5
{
  public:
    virtual ~hkMemoryAllocatorCF5();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterCF5
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorCF5* m_pTemp;
    hkMemoryAllocatorCF5* m_pStreamAllocator;
    hkMemoryAllocatorCF5& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterCF5* __cdecl FUN_00c85750() throw();

struct hkRefCF5
{
    void FUN_00c905b0() throw();
};

template <class T> class hkArrayCF5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~hkArrayCF5() throw()
    {
        hkMemoryAllocatorCF5& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectCF5
{
  public:
    virtual ~hkBaseObjectCF5()
    {}
};

class hkReferencedObjectCF5 : public hkBaseObjectCF5
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeCF5 : public hkReferencedObjectCF5
{
  public:
    unsigned int m_ulUserData;
    int m_type;
};

class hkpShapeContainerCF5
{
  public:
    virtual ~hkpShapeContainerCF5()
    {}
};

class hkpShapeCollectionCF5 : public hkpShapeCF5, public hkpShapeContainerCF5
{
  public:
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpListShapeChildInfoCF5
{
    hkRefCF5* m_pCollisionShape;
    unsigned int m_uiCollisionFilterData;
    int m_iShapeKey;
    int m_iChildShapeCount;
};

class FUN_00cf5750 : public hkpShapeCollectionCF5
{
  public:
    hkArrayCF5<hkpListShapeChildInfoCF5> m_kChildInfoList;

    virtual ~FUN_00cf5750();
};

// Destructor that calls FUN_00c905b0 on each child's m_pCollisionShape in m_kChildInfoList.
// @fnv 0x00cf5750
FUN_00cf5750::~FUN_00cf5750()
{
    for (int i = 0; i < m_kChildInfoList.m_iElementCount; i++)
    {
        hkpListShapeChildInfoCF5& info = m_kChildInfoList[i];
        info.m_pCollisionShape->FUN_00c905b0();
    }
}
}  // namespace fnv_00cf5750

struct hkpRayHitCollector;

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_kMotionState;
    const hkpCdBody* m_parent;
};

struct S00cf52c0_ShapeIface : public S00cf5140_ShapeIface
{
    virtual void castRayWithCollector(const S00cf5140_Input& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const;
};

struct S00cf52c0_Obj : public S00cf5140_Obj
{
    void castRayWithCollectorImpl(const S00cf5140_Input& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Iterates enabled children, optionally filtering via m_pRayShapeCollectionFilter, and casts a ray on each child's collision shape into the collector.
// @fnv 0x00cf52c0
void S00cf52c0_Obj::castRayWithCollectorImpl(const S00cf5140_Input& input, const hkpCdBody& cdBody,
                                 hkpRayHitCollector& collector) const
{
    hkpCdBody child;
    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerBegin("TtrcList");

    if (!input.m_pRayShapeCollectionFilter)
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                child.m_pCollisionShape =
                    reinterpret_cast<const hkpShape*>(m_kChildInfoList.m_data[i].m_pCollisionShape);
                child.m_parent = &cdBody;
                child.m_kMotionState = cdBody.m_kMotionState;
                child.m_uiCollisionShapeKey = i;
                reinterpret_cast<const S00cf52c0_ShapeIface*>(child.m_pCollisionShape)
                    ->castRayWithCollector(input, child, collector);
            }
        }
    }
    else
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                if (input.m_pRayShapeCollectionFilter
                        ->IsCollisionEnabled(input, *this, *reinterpret_cast<const S00cf5140_Container*>(&pad10), i)
                        .m_cBooleanValue)
                {
                    child.m_pCollisionShape =
                        reinterpret_cast<const hkpShape*>(m_kChildInfoList.m_data[i].m_pCollisionShape);
                    child.m_parent = &cdBody;
                    child.m_kMotionState = cdBody.m_kMotionState;
                    child.m_uiCollisionShapeKey = i;
                    reinterpret_cast<const S00cf52c0_ShapeIface*>(child.m_pCollisionShape)
                        ->castRayWithCollector(input, child, collector);
                }
            }
        }
    }

    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerEnd();
}

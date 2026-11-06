
// src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpaabbphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpAabbPhantom.h"

// @fnv 0x00cf2460
int __cdecl FUN_00cf2460()
{
    return 0;
}

struct hkBoolXcf24d0
{
    char m_cBooleanValue;
    hkBoolXcf24d0(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

template <class T> class hkArrayXcf24d0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkObjXcf24d0
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    hkArrayXcf24d0<void*> m_items;

    hkBoolXcf24d0 ContainsItem(void* pv) const;
};

// Searches m_items for pv and returns true if found, otherwise false.
// @fnv 0x00cf24d0
hkBoolXcf24d0 hkObjXcf24d0::ContainsItem(void* apItem) const
{
    for (int i = 0; i < m_items.m_iElementCount; i++)
    {
        if (m_items.m_data[i] == apItem)
            return true;
    }
    return false;
}

struct PresentFlag
{
    bool value;
    PresentFlag(bool v) : value(v)
    {}
    PresentFlag(const PresentFlag& v) : value(v.value)
    {}
};
struct FUN_00cf2a60_t : hkpAabbPhantom
{
    void NotifyAll(hkpCollidable* collidable, PresentFlag wasPresent);
    void removeOverlappingCollidable(hkpCollidable* collidable);
};
// Searches the phantom's collidable list for the given collidable, notifies via NotifyAll whether it was present, and removes it by swapping in the last entry.
// @fnv 0x00cf2a60
void FUN_00cf2a60_t::removeOverlappingCollidable(hkpCollidable* collidable)
{
    int index;
    int count = m_ppOverlappingCollidables.m_iElementCount;
    int i = 0;
    if (count > 0)
    {
        void** ppEntry = m_ppOverlappingCollidables.m_data;
        do
        {
            if (*ppEntry == collidable)
            {
                index = i;
                goto search_done;
            }
            ++i;
            ++ppEntry;
        } while (i < count);
    }
    index = -1;
search_done:
    NotifyAll(collidable, PresentFlag(index >= 0));
    if (index >= 0)
    {
        --m_ppOverlappingCollidables.m_iElementCount;
        int lastIndex = m_ppOverlappingCollidables.m_iElementCount;
        if (lastIndex != index)
            m_ppOverlappingCollidables.m_data[index] = m_ppOverlappingCollidables.m_data[lastIndex];
        m_bOrderDirty = 1;
    }
}

class hkClassCF2A;

extern const hkClassCF2A DAT_0126902c;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayCF2A
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

class hkStatisticsCollectorCF2A
{
  public:
    virtual ~hkStatisticsCollectorCF2A() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayCF2A<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int iAllocated = FUN_00d06f80(kArray.m_data, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkpCollidableCF2A;

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];

    void WritePhantomLists(hkStatisticsCollectorCF2A* pkCollector, const hkClassCF2A* pkClass) const throw();
};

struct hkVector4CF2A
{
    hkReal x, y, z, w;
};

struct hkAabbCF2A
{
    hkVector4CF2A m_kMinimumCorner;
    hkVector4CF2A m_kMaximumCorner;
};

class hkpAabbPhantomCF2A : public FUN_00d08130
{
  public:
    hkAabbCF2A m_kBounds;
    hkArrayCF2A<hkpCollidableCF2A*> m_ppOverlappingCollidables;
    char m_padDC[0x4];

    void AddToStatisticsCollector(hkStatisticsCollectorCF2A* pkCollector, const hkClassCF2A* pkClass) const throw();
};

// Adds the collidable pointer array and the base class data to the statistics collector.
// @fnv 0x00cf2ae0
void hkpAabbPhantomCF2A::AddToStatisticsCollector(hkStatisticsCollectorCF2A* pkCollector,
                                                  const hkClassCF2A* pkClass) const throw()
{
    pkCollector->addArray("OvrlpCollPtr", m_ppOverlappingCollidables);
    WritePhantomLists(pkCollector, &DAT_0126902c);
}

class hkMemoryAllocatorCF2C;

struct hkMemoryRouterCF2C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2C* m_pStreamAllocator;
    hkMemoryAllocatorCF2C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2C& __cdecl FUN_00c85750() throw();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyCF2C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayCF2C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorCF2C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyCF2C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkPhantomCF2C
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    hkArrayCF2C<void*> m_overlaps;
    bool m_dirty;

    int FUN_00ca94c0(void* p);
    void AddOverlap(void* p);
};

// @fnv 0x00cf2b50
void hkPhantomCF2C::AddOverlap(void* pOverlap)
{
    if (FUN_00ca94c0(pOverlap) == 0)
    {
        m_overlaps.AddBack(pOverlap);
        m_dirty = true;
    }
}

struct hkLessCF2B
{
};

void __cdecl QuickSortShapeDetails(void** pArr, int iStart, int iEnd, hkLessCF2B kCmp);

inline void quickSortCF2B(void** pArr, int iSize, hkLessCF2B kCmp)
{
    if (iSize > 1)
        QuickSortShapeDetails(pArr, 0, iSize - 1, kCmp);
}

struct hkObjCF2B
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    void** m_d0;
    int m_d4;
    int m_d8;
    char m_dc;
    void SortIfDirty();
};

// If the dirty flag m_dc is set, sorts the m_d0 array of m_d4 elements with quickSortCF2B and clears m_dc.
// @fnv 0x00cf2bb0
void hkObjCF2B::SortIfDirty()
{
    if (m_dc)
    {
        quickSortCF2B(m_d0, m_d4, hkLessCF2B());
        m_dc = 0;
    }
}

namespace fnv_00cf2bf0 {
class hkMemoryAllocatorCF2B
{
  public:
    virtual ~hkMemoryAllocatorCF2B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterCF2B
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2B* m_pStreamAllocator;
    hkMemoryAllocatorCF2B& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2B& __cdecl FUN_00c85750();

template <class T> __forceinline void destructCF2B(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayCF2B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ~hkArrayCF2B()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructCF2B(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorCF2B& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkpCollidableCF2B;

struct hkVector4CF2B
{
    hkReal x, y, z, w;
};

struct hkAabbCF2B
{
    hkVector4CF2B m_kMinimumCorner;
    hkVector4CF2B m_kMaximumCorner;
};

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];
};

class FUN_00cf2bf0 : public FUN_00d08130
{
  public:
    hkAabbCF2B m_kBounds;
    hkArrayCF2B<hkpCollidableCF2B*> m_ppOverlappingCollidables;
    char m_padDC[0x4];

    virtual ~FUN_00cf2bf0() throw();
};

typedef char fnv_check_cf2bf0[(sizeof(FUN_00cf2bf0) == 0xe0) ? 1 : -1];

// @fnv 0x00cf2bf0
FUN_00cf2bf0::~FUN_00cf2bf0() throw()
{}
}  // namespace fnv_00cf2bf0

namespace fnv_00cf2c50 {
class hkMemoryAllocatorCF2C
{
  public:
    virtual ~hkMemoryAllocatorCF2C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF2C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2C* m_pStreamAllocator;
    hkMemoryAllocatorCF2C& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCF2C {
extern "C" hkMemoryRouterCF2C& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayCF2C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorCF2C& kAlloc = hkRouterCF2C::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkPhantomCF2C
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    hkArrayCF2C<void*> m_overlaps;

    void FreeListenerArrays();
    void ClearOverlapsIfEmpty();
};

// If the overlaps array is empty, frees it via the heap allocator, then calls FreeListenerArrays.
// @fnv 0x00cf2c50
void hkPhantomCF2C::ClearOverlapsIfEmpty()
{
    if (m_overlaps.m_iElementCount == 0)
        m_overlaps.ClearAndRelease();
    FreeListenerArrays();
}
}  // namespace fnv_00cf2c50

namespace fnv_00cf2d50 {
class hkMemoryAllocatorCF2D
{
  public:
    virtual ~hkMemoryAllocatorCF2D() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> T* _bufAlloc(int& iReqNumInOut)
    {
        int n = iReqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        iReqNumInOut = n / (int)sizeof(T);
        return (T*)p;
    }
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterCF2D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2D* m_pStreamAllocator;
    hkMemoryAllocatorCF2D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2D& __cdecl FUN_00c85750();

template <class T> __forceinline void copyCF2D(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayCF2D
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

    __forceinline void operator=(const hkArrayCF2D& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorCF2D& kAlloc, const hkArrayCF2D& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyCF2D(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4CF2D
{
    hkReal x, y, z, w;
};

struct hkAabbCF2D
{
    hkVector4CF2D m_kMinimumCorner;
    hkVector4CF2D m_kMaximumCorner;
};

class hkpShapeCF2D;
class hkpPhantomOverlapListenerCF2D;
class hkpPhantomListenerCF2D;

struct hkpCollidableCF2D
{
    const hkpShapeCF2D* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeCF2D* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectCF2D
{
  public:
    virtual ~hkpWorldObjectCF2D() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableCF2D m_kCollidable;

    const hkpCollidableCF2D* getCollidable() const
    {
        return &m_kCollidable;
    }
    void CopyEntriesFrom(const hkpWorldObjectCF2D* pkOtherObj) throw();
};

class FUN_00cf2cb0 : public hkpWorldObjectCF2D
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObjectCF2D* p = (hkpWorldObjectCF2D*)FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayCF2D<hkpPhantomOverlapListenerCF2D*> m_kPhantomOverlapListeners;
    hkArrayCF2D<hkpPhantomListenerCF2D*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkAabbCF2D m_kBounds;
    char m_padD0[0x10];

    FUN_00cf2cb0(const hkAabbCF2D& kAabb, hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectCF2D* clone() const throw();
};

typedef char fnv_check_cf2d50[(sizeof(FUN_00cf2cb0) == 0xe0) ? 1 : -1];

// @fnv 0x00cf2d50
hkpWorldObjectCF2D* FUN_00cf2cb0::clone() const throw()
{
    FUN_00cf2cb0* pkPhantom = new FUN_00cf2cb0(m_kBounds, getCollidable()->GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    pkPhantom->CopyEntriesFrom(this);
    return pkPhantom;
}
}  // namespace fnv_00cf2d50

namespace fnv_00cf2f60 {
class hkMemoryAllocatorCF2F
{
  public:
    virtual ~hkMemoryAllocatorCF2F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF2F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2F* m_pStreamAllocator;
    hkMemoryAllocatorCF2F& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2F& __cdecl FUN_00c85750();

class FUN_00cf2bf0
{
  public:
    virtual ~FUN_00cf2bf0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00cf2bf0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cf2bf0* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00cf2f60
FUN_00cf2bf0* FUN_00cf2bf0::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->FUN_00cf2bf0::~FUN_00cf2bf0();
    if (uiFlags & 1)
        FUN_00cf2bf0::operator delete(this);
    return this;
}
}  // namespace fnv_00cf2f60

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;

struct StringCursor
{
    void* m_kRayStart;
    char* m_commandPtr;
    void* m_auiShapeKeys;
    char* m_endPtr;
};

struct DummyBool
{
    char m_cBooleanValue;
};

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    char m_pad21;
    char m_pad22;
    char m_pad23;
    hkUint32 m_uiFilterInfo;
};

struct __declspec(align(16)) ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct DummyNormal : public hkVector4
{
    void FUN_00c7f700(const void* rot, const void* dir);
};

struct DummyCollidable;

struct WorldRayCastOutput
{
    DummyNormal m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_uiShapeKeyIndex;
    int m_pad1c;
    hkUint32 m_shapeKeys0;
    hkUint32 m_shapeKeys1;
    hkUint32 m_shapeKeys2;
    hkUint32 m_shapeKeys3;
    hkUint32 m_shapeKeys4;
    hkUint32 m_shapeKeys5;
    hkUint32 m_shapeKeys6;
    hkUint32 m_shapeKeys7;
    hkUint32 m_shapeKeys8;
    hkUint32 m_shapeKeys9;
    hkUint32 m_shapeKeys10;
    hkUint32 m_shapeKeys11;
    const DummyCollidable* m_pRootCollidable;
};

struct DummyShape
{
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7() = 0;
    virtual DummyBool RayCast(const ShapeRayCastQuery& input, WorldRayCastOutput& output) const = 0;
};

struct DummyCollidable
{
    DummyShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    DummyCollidable* m_parent;
};

struct DummyWorld
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    char* m_pCollisionFilter;
};

static inline void setRotatedInverseDir(hkVector4& out, const hkRotation& r, const __m128& b)
{
    __m128 c0 = *(const __m128*)&r.m_kColumn0;
    __m128 c1 = *(const __m128*)&r.m_kColumn1;
    __m128 c2 = *(const __m128*)&r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    __m128 r2 = _mm_mul_ps(c2, b2);
    *(__m128*)&out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

static inline void SetTransformedPosition(hkVector4& out, const hkTransform* t, const hkVector4& in)
{
    __m128 d = _mm_sub_ps(*(const __m128*)&in, *(const __m128*)&t->m_vTranslation);
    setRotatedInverseDir(out, t->m_rotation, d);
}

class Phantom_00cf26b0 : public hkpAabbPhantom
{
  public:
    void FUN_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const;
};

// Performs a ray cast against overlapping collidables, transforming ray endpoints into local space and recording the hit root collidable.
// @fnv 0x00cf26b0
void Phantom_00cf26b0::FUN_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const
{
    StringCursor* pTlsCursor = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* cmd = pTlsCursor->m_commandPtr;
    if (cmd < pTlsCursor->m_endPtr)
    {
        *(const char**)cmd = "TtrcPhantom";
        _ReadWriteBarrier();
        volatile hkUint32 time = (hkUint32)__rdtsc();
        *(hkUint32*)(cmd + 4) = time;
        cmd += 12;
        pTlsCursor->m_commandPtr = cmd;
    }

    ShapeRayCastQuery shapeQuery;
    shapeQuery.m_pRayShapeCollectionFilter = 0;
    shapeQuery.m_uiFilterInfo = input.m_uiFilterInfo;
    if (input.m_bEnableShapeCollectionFilter)
    {
        char* filter = ((DummyWorld*)m_pOwningWorld)->m_pCollisionFilter;
        shapeQuery.m_pRayShapeCollectionFilter = filter ? filter + 0x10 : 0;
    }
    else
    {
        shapeQuery.m_pRayShapeCollectionFilter = 0;
    }

    const DummyCollidable* const* ppCollidables = (const DummyCollidable* const*)m_ppOverlappingCollidables.m_data;
    for (int i = m_ppOverlappingCollidables.m_iElementCount - 1; i >= 0; i--)
    {
        DummyShape* shape = (*ppCollidables)->m_pCollisionShape;
        if (shape)
        {
            const hkTransform* pMotionState = (*ppCollidables)->m_pMotionState;
            SetTransformedPosition(shapeQuery.m_vFrom, pMotionState, input.m_vFrom);
            SetTransformedPosition(shapeQuery.m_vTo, pMotionState, input.m_vTo);
            DummyBool hit = shape->RayCast(shapeQuery, output);
            if (hit.m_cBooleanValue)
            {
                output.m_pRootCollidable = *ppCollidables;
            }
        }
        ppCollidables++;
    }

    if (output.m_pRootCollidable)
    {
        output.m_vHitNormal.FUN_00c7f700(output.m_pRootCollidable->m_pMotionState, &output.m_vHitNormal);
    }

    StringCursor* hit = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* cmd2 = hit->m_commandPtr;
    if (cmd2 < hit->m_endPtr)
    {
        *(const char**)cmd2 = "Et";
        _ReadWriteBarrier();
        volatile hkUint32 time2 = (hkUint32)__rdtsc();
        *(hkUint32*)(cmd2 + 4) = time2;
        cmd2 += 12;
        hit->m_commandPtr = cmd2;
    }
}

struct FnvCpu_FUN_00cf2470_CpuData0
{
    __m128 field00;
    __m128 field10;
};
struct FnvCpu_FUN_00cf2470_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    __m128 fieldb0;
    __m128 fieldc0;
    void FUN_00cf2470(FnvCpu_FUN_00cf2470_CpuData0* input0);
};
// @fnv 0x00cf2470
void FnvCpu_FUN_00cf2470_CpuObject::FUN_00cf2470(FnvCpu_FUN_00cf2470_CpuData0* input0)
{
    input0->field00 = this->fieldb0;
    input0->field10 = this->fieldc0;
}

struct PhantomBounds
{
    void __thiscall FUN_00d07ec0(hkAabb* bounds);
    void __thiscall FUN_00cf24a0(const hkAabb& source);
};
// Copies the minimum and maximum corners from source into the embedded hkAabb at offset 0xb0, then calls FUN_00d07ec0 on it.
// @fnv 0x00cf24a0
void PhantomBounds::FUN_00cf24a0(const hkAabb& source)
{
    hkAabb* target = reinterpret_cast<hkAabb*>(reinterpret_cast<char*>(this) + 0xb0);
    _mm_store_ps(&target->m_kMinimumCorner.x, _mm_load_ps(&source.m_kMinimumCorner.x));
    _mm_store_ps(&target->m_kMaximumCorner.x, _mm_load_ps(&source.m_kMaximumCorner.x));
    FUN_00d07ec0(target);
}

template <class T> struct Array_cf2c
{
    Array_cf2c() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct Vector4_cf2c
{
    __m128 m_vComponents;
    Vector4_cf2c& operator=(const Vector4_cf2c& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct Aabb_cf2c
{
    Vector4_cf2c m_kMinimumCorner;
    Vector4_cf2c m_kMaximumCorner;
};

struct BroadPhaseHandle_cf2c
{
    unsigned int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    unsigned short m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};

struct Collidable_cf2c
{
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    BroadPhaseHandle_cf2c m_kBroadPhaseHandle;
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (char)((unsigned int)pvOwner - (unsigned int)this);
    }
};

class WorldObject_cf2c
{
  public:
    WorldObject_cf2c(const void* pkShape, int eType) throw();
    virtual ~WorldObject_cf2c() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    unsigned int m_ulUserData;
    Collidable_cf2c m_kCollidable;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
};

class Phantom_cf2c : public WorldObject_cf2c
{
  public:
    Phantom_cf2c(const void* pkShape) throw() : WorldObject_cf2c(pkShape, 2)
    {
        m_kCollidable.SetOwnerPointer(this);
    }
    Array_cf2c<void*> m_kPhantomOverlapListeners;
    Array_cf2c<void*> m_kPhantomListeners;
    int unkA4, unkA8, unkAC;
};

class FUN_00cf2cb0 : public Phantom_cf2c
{
  public:
    FUN_00cf2cb0(const Aabb_cf2c& kAabb, unsigned int uiCollisionFilterInfo) throw();
    virtual ~FUN_00cf2cb0() throw();
    Aabb_cf2c m_kBounds;
    Array_cf2c<void*> m_ppOverlappingCollidables;
    bool m_bOrderDirty;
};

// Constructs the Phantom base with a null shape, clears m_bOrderDirty, copies kAabb into m_kBounds and stores the collision filter data.
// @fnv 0x00cf2cb0
FUN_00cf2cb0::FUN_00cf2cb0(const Aabb_cf2c& kAabb, unsigned int uiCollisionFilterInfo) throw() : Phantom_cf2c(0)
{
    m_bOrderDirty = false;
    m_kBounds = kAabb;
    m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = uiCollisionFilterInfo;
}

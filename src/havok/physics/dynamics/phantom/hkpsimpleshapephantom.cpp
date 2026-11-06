
// src/havok/physics/dynamics/phantom/hkpsimpleshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpsimpleshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSimpleShapePhantom.h"

struct FUN_00d1f9c0_Memory
{
    virtual void FUN_00d1f9c0_a();
    virtual void FUN_00d1f9c0_b();
    virtual void FUN_00d1f9c0_free(void* object, unsigned short size);
};

struct FUN_00d1f9c0_Router
{
    unsigned char pad[0x10];
    FUN_00d1f9c0_Memory* memory;
};

FUN_00d1f9c0_Router* _D1A0E0GetMemoryRouter();

struct FUN_00d1f9c0_StandIn
{
    void* vtable;
    unsigned short size;

    void FUN_00d1f780();
    void* FUN_00d1f9c0(unsigned int flags);
};

// Calls FUN_00d1f780, then if flags has bit 1 set frees this through the memory router's free with this->size, and returns this.
// @fnv 0x00d1f9c0
void* FUN_00d1f9c0_StandIn::FUN_00d1f9c0(unsigned int flags)
{
    this->FUN_00d1f780();

    if (flags & 1)
    {
        FUN_00d1f9c0_Router* router = _D1A0E0GetMemoryRouter();
        FUN_00d1f9c0_Memory* memory = router->memory;
        unsigned short size = this->size;
        memory->FUN_00d1f9c0_free(this, size);
    }

    return this;
}

// @fnv 0x00d1f220
int FUN_00d1f220()
{
    return 1;
}

struct ShapeDetail
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int key;
};
typedef __declspec(align(16)) ShapeDetail* AlignedShapePtr;
struct DetailLess
{
    bool operator()(ShapeDetail* const& a, ShapeDetail* const& b) const
    {
        return a->key < b->key;
    }
};
// Sorts the range [lo, hi] of a ShapeDetail pointer array in place by key using a quicksort partition loop and recursion.
// @fnv 0x00cf2ed0
void __cdecl QuickSortShapeDetails(ShapeDetail** apItems, int lo, int hi, DetailLess aComparator)
{
    for (;;)
    {
        int i = lo;
        int iRight = hi;
        AlignedShapePtr pivot = apItems[(lo + hi) >> 1];
        do
        {
            while (aComparator(apItems[i], pivot))
                ++i;
            while (aComparator(pivot, apItems[iRight]))
                --iRight;
            if (iRight >= i)
            {
                if (iRight != i)
                {
                    ShapeDetail* pTemp = apItems[iRight];
                    apItems[iRight] = apItems[i];
                    apItems[i] = pTemp;
                }
                --iRight;
                ++i;
            }
        } while (i <= iRight);
        if (lo < iRight)
            QuickSortShapeDetails(apItems, lo, iRight, aComparator);
        if (i >= hi)
            break;
        lo = i;
    }
}

struct hkBoolXd1f230
{
    char m_cBooleanValue;
    hkBoolXd1f230(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

template <class T> class hkArrayXd1f230
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkObjXd1f230
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
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArrayXd1f230<void*> m_items;

    hkBoolXd1f230 Contains(void* pv) const;
};

// Returns true if the pointer pv is found in the m_items array, otherwise false.
// @fnv 0x00d1f230
hkBoolXd1f230 hkObjXd1f230::Contains(void* apItem) const
{
    for (int i = 0; i < m_items.m_iElementCount; i++)
    {
        if (m_items.m_data[i] == apItem)
            return true;
    }
    return false;
}

struct hkBoolD1F5
{
    char m_cBooleanValue;
    hkBoolD1F5(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkpShapeD1F5;

struct hkpCollidableD1F5
{
    const hkpShapeD1F5* m_pCollisionShape;

    const hkpShapeD1F5* getShape() const
    {
        return m_pCollisionShape;
    }
};

template <class T> class hkArrayD1F5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct hkpSimpleShapePhantomCollisionDetailD1F5
{
    hkpCollidableD1F5* m_kCollidable;
};

class FUN_00ca9520_class : public hkpShapePhantom
{
  public:
    void NotifyAll(hkpCollidableD1F5* pkCollidable, hkBoolD1F5 bCollidableWasAdded) throw();
};

class hkpSimpleShapePhantomD1F5 : public FUN_00ca9520_class
{
  public:
    hkArrayD1F5<hkpSimpleShapePhantomCollisionDetailD1F5> m_kCollisionDetails;
    hkBoolD1F5 m_bOrderDirty;

    void removeOverlappingCollidable(hkpCollidableD1F5* pkCollidable) throw();
};

// @fnv 0x00d1f5a0
void hkpSimpleShapePhantomD1F5::removeOverlappingCollidable(hkpCollidableD1F5* pkCollidable) throw()
{
    if (pkCollidable->getShape() != 0)
    {
        for (int i = m_kCollisionDetails.GetLogicalSize() - 1; i >= 0; i--)
        {
            if (m_kCollisionDetails[i].m_kCollidable == pkCollidable)
            {
                NotifyAll(pkCollidable, true);
                m_kCollisionDetails.removeAt(i);
                m_bOrderDirty = true;
                return;
            }
        }
        NotifyAll(pkCollidable, false);
    }
}

class hkClassD1F6;

extern const hkClassD1F6 DAT_0126902c;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayD1F6
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

class hkStatisticsCollectorD1F6
{
  public:
    virtual ~hkStatisticsCollectorD1F6() throw();
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

    template <class T> void addArray(const char* pcName, const hkArrayD1F6<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkOverlapD1F6;

class hkpShapeD1F6
{
  public:
    void WritePhantomLists(hkStatisticsCollectorD1F6* pkCollector, const hkClassD1F6* pkClass) const throw();
};

class hkObjD1F6 : public hkpShapeD1F6
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
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArrayD1F6<hkOverlapD1F6*> m_overlaps;

    void CollectStatistics(hkStatisticsCollectorD1F6* pkCollector, const hkClassD1F6* pkClass) const throw();
};

// Calls the base shape's statistics collector with DAT_0126902c, then adds the m_overlaps array to pkCollector as "OverlapPtr".
// @fnv 0x00d1f620
void hkObjD1F6::CollectStatistics(hkStatisticsCollectorD1F6* pkCollector, const hkClassD1F6* pkClass) const throw()
{
    WritePhantomLists(pkCollector, &DAT_0126902c);
    pkCollector->addArray("OverlapPtr", m_overlaps);
}

struct CollisionMemoryRouter
{
    int unk00, unk04, unk08, unk0c;
    void* allocator;
};
extern "C" int __stdcall FUN_00ca94c0(void* object);
extern "C" CollisionMemoryRouter* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);

struct FUN_00d1f690_Member : hkpSimpleShapePhantom
{
    void AddCollisionDetail(void* object);
};

// If the object's first pointer is non-null and FUN_00ca94c0 returns 0, appends the object to the collision detail array, growing it when full, and sets a flag.
// @fnv 0x00d1f690
void FUN_00d1f690_Member::AddCollisionDetail(void* object)
{
    if (*reinterpret_cast<void**>(object) != 0)
    {
        if (FUN_00ca94c0(object) == 0)
        {
            hkArray<hkpSimpleShapePhantomCollisionDetail>* details = &m_kCollisionDetails;
            CollisionMemoryRouter* router = FUN_00c85750();
            if (details->m_iElementCount == (details->m_iCapacityState & 0x3fffffff))
            {
                ResizeAudioStream(router->allocator, details, 4);
            }
            void** slot = reinterpret_cast<void**>(details->m_data) + details->m_iElementCount;
            ++details->m_iElementCount;
            *slot = object;
            m_bOrderDirty = 1;
        }
    }
}

namespace fnv_00d1f6f0 {
struct hkLessD1F6
{
};

void __cdecl QuickSortShapeDetails(void** pArr, int iStart, int iEnd, hkLessD1F6 kCmp);

inline void quickSortD1F6(void** pArr, int iSize, hkLessD1F6 kCmp)
{
    if (iSize > 1)
        QuickSortShapeDetails(pArr, 0, iSize - 1, kCmp);
}

struct hkObjD1F6
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    void** m_160;
    int m_164;
    int m_168;
    char m_16c;
    void SortAndClearFlag();
};

// If m_16c is set, sorts the m_160 array of m_164 elements with quickSortD1F6 and clears m_16c.
// @fnv 0x00d1f6f0
void hkObjD1F6::SortAndClearFlag()
{
    if (m_16c)
    {
        quickSortD1F6(m_160, m_164, hkLessD1F6());
        m_16c = 0;
    }
}
}  // namespace fnv_00d1f6f0

namespace fnv_00d1f7e0 {
class hkMemoryAllocatorD1F7
{
  public:
    virtual ~hkMemoryAllocatorD1F7() throw();
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

struct hkMemoryRouterD1F7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD1F7* m_pStreamAllocator;
    hkMemoryAllocatorD1F7& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD1F7& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD1F7(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayD1F7
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

    __forceinline void operator=(const hkArrayD1F7& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorD1F7& kAlloc, const hkArrayD1F7& a)
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
        copyD1F7(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4D1F7
{
    hkReal x, y, z, w;
};

struct hkTransformD1F7
{
    hkVector4D1F7 m_kColumn0;
    hkVector4D1F7 m_kColumn1;
    hkVector4D1F7 m_kColumn2;
    hkVector4D1F7 m_vTranslation;
};

class hkpShapeD1F7;
class hkpPhantomOverlapListenerD1F7;
class hkpPhantomListenerD1F7;

struct hkpCollidableD1F7
{
    const hkpShapeD1F7* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeD1F7* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectD1F7
{
  public:
    virtual ~hkpWorldObjectD1F7() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableD1F7 m_kCollidable;

    const hkpCollidableD1F7* getCollidable() const
    {
        return &m_kCollidable;
    }
    void CopyEntriesFrom(const hkpWorldObjectD1F7* pkOtherObj) throw();
};

class FUN_00d1f730 : public hkpWorldObjectD1F7
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObjectD1F7* p = (hkpWorldObjectD1F7*)FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayD1F7<hkpPhantomOverlapListenerD1F7*> m_kPhantomOverlapListeners;
    hkArrayD1F7<hkpPhantomListenerD1F7*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkTransformD1F7 m_kMotionTransform;
    char m_padF0[0x80];

    const hkTransformD1F7& getTransform() const
    {
        return m_kMotionTransform;
    }

    FUN_00d1f730(const hkpShapeD1F7* pkShape, const hkTransformD1F7& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectD1F7* ClonePhantom() const throw();
};

typedef char fnv_check_d1f7e0[(sizeof(FUN_00d1f730) == 0x170) ? 1 : -1];

// @fnv 0x00d1f7e0
hkpWorldObjectD1F7* FUN_00d1f730::ClonePhantom() const throw()
{
    const hkpCollidableD1F7* pkCollidable = getCollidable();
    FUN_00d1f730* pkPhantom =
        new FUN_00d1f730(pkCollidable->getShape(), getTransform(), pkCollidable->GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    pkPhantom->CopyEntriesFrom(this);
    return pkPhantom;
}
}  // namespace fnv_00d1f7e0

struct hkpShapeD1F
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int m_type;
};
struct hkpCdBodyD1F
{
    const hkpShapeD1F* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD1F* m_parent;
};
struct hkpCollisionInputD1F;
template <class T> class hkArrayD1F
{
  public:
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
typedef void(__cdecl* AgentFuncD1F)(const hkpCdBodyD1F& bodyA, const hkpCdBodyD1F& bodyB,
                                    const hkpCollisionInputD1F& input, void* collector);
struct AgentFuncsD1F
{
    AgentFuncD1F m_func;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct hkpCollisionDispatcherD1F
{
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
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agentTypes[32][32];
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    AgentFuncsD1F m_agentFuncs[32];
};
struct hkpCollisionInputD1F
{
    hkpCollisionDispatcherD1F* m_pCollisionDispatcher;
};
struct WorldD1F
{
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
    hkpCollisionInputD1F* m_pCollisionInput;
};
class PhantomD1F
{
  public:
    int unk000;
    int unk004;
    WorldD1F* m_pOwningWorld;
    int unk00C;
    hkpCdBodyD1F m_kCollisionBody;
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
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArrayD1F<hkpCdBodyD1F*> m_overlaps;
    void DispatchOverlaps(void* collector, const hkpCollisionInputD1F* input);
};
// @fnv 0x00d1f4a0
void PhantomD1F::DispatchOverlaps(void* collector, const hkpCollisionInputD1F* apCollisionInput)
{
    if (!apCollisionInput)
        apCollisionInput = m_pOwningWorld->m_pCollisionInput;
    hkpCollisionDispatcherD1F* dispatcher = apCollisionInput->m_pCollisionDispatcher;
    for (int i = m_overlaps.GetLogicalSize() - 1; i >= 0; i--)
    {
        hkpCdBodyD1F*& pOtherBody = m_overlaps[i];
        AgentFuncD1F pAgentFunc =
            dispatcher
                ->m_agentFuncs[dispatcher->m_agentTypes[m_kCollisionBody.m_pCollisionShape->m_type]
                                                       [pOtherBody->m_pCollisionShape->m_type]]
                .m_func;
        pAgentFunc(m_kCollisionBody, *pOtherBody, *apCollisionInput, collector);
    }
}

class hkpShape : public hkReferencedObject
{
  public:
    hkUlong m_ulUserData;
    int m_type;
};
class hkpSimpleShapePhantomCollisionDetail
{
  public:
    hkpCollidable* m_kCollidable;
};
struct FUN_00d1f520_Input;
struct FUN_00d1f520_Collector
{
    int unk00;
    hkBool m_fHitDistance;
};
typedef void(__cdecl* FUN_00d1f520_GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b,
                                                        const FUN_00d1f520_Input& input,
                                                        FUN_00d1f520_Collector& collector);
struct FUN_00d1f520_AgentFuncs
{
    void* m_pCreateFunc;
    FUN_00d1f520_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};
struct FUN_00d1f520_Dispatcher
{
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
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    hkUint8 m_agent2TypeMap[32][32];
    hkUint8 m_agent3TypeMap[32][32];
    FUN_00d1f520_AgentFuncs m_agent2Funcs[1];
};
struct FUN_00d1f520_Input
{
    FUN_00d1f520_Dispatcher* m_pCollisionDispatcher;
};
struct FUN_00d1f520_World
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
    FUN_00d1f520_Input* m_pCollisionInput;
};
struct FUN_00d1f520_Phantom : public hkpSimpleShapePhantom
{
    void QueryPenetrations(FUN_00d1f520_Collector& collector, const FUN_00d1f520_Input* input);
};
// Iterates collision details and calls the dispatcher's agent2 penetration query function, breaking early when the collector reports a hit distance.
// @fnv 0x00d1f520
void FUN_00d1f520_Phantom::QueryPenetrations(FUN_00d1f520_Collector& collector, const FUN_00d1f520_Input* input)
{
    if (!input)
        input = static_cast<FUN_00d1f520_World*>(m_pOwningWorld)->m_pCollisionInput;
    FUN_00d1f520_Dispatcher* d = input->m_pCollisionDispatcher;
    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; i--)
    {
        hkpSimpleShapePhantomCollisionDetail* pDetail = m_kCollisionDetails.m_data + i;
        int ta = m_kCollidable.m_pCollisionShape->m_type;
        d->m_agent2Funcs[d->m_agent2TypeMap[ta][pDetail->m_kCollidable->m_pCollisionShape->m_type]]
            .m_pQueryPenetrationsFunc(m_kCollidable, *pDetail->m_kCollidable, *input, collector);
        if (collector.m_fHitDistance)
            break;
    }
}

#include <xmmintrin.h>
struct FUN_00d1f450_Obj
{
    void setPositionAndLinearCast(int* a, int b, int c, int d);
    void setTransformAndLinearCast(int* source, int a, int b, int c);
};

// Copies 12 floats from source to this at float index 0x2C using SSE, then calls setPositionAndLinearCast with source plus 0x30 bytes and a, b, c.
// @fnv 0x00d1f450
void FUN_00d1f450_Obj::setTransformAndLinearCast(int* source, int a, int b, int c)
{
    float* destination = reinterpret_cast<float*>(this) + 0x2C;
    float* vectors = reinterpret_cast<float*>(source);

    _mm_store_ps(destination + 0, _mm_load_ps(vectors + 0));
    _mm_store_ps(destination + 4, _mm_load_ps(vectors + 4));
    _mm_store_ps(destination + 8, _mm_load_ps(vectors + 8));

    this->setPositionAndLinearCast(reinterpret_cast<int*>(reinterpret_cast<char*>(source) + 0x30), a, b, c);
}

namespace fnv_00d1f960 {
// @fnv 0x00d1f960
struct Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void*, unsigned);
};
struct Router
{
    void* a;
    void* b;
    void* c;
    void* d;
    Alloc* heap;
    Alloc& getHeap()
    {
        return *heap;
    }
};
Router* FUN_00c85750();
struct C : hkpSimpleShapePhantom
{
    void FUN_00d1f960();
    void FUN_00c9e820();
};
void C::FUN_00d1f960()
{
    if (m_kCollisionDetails.m_iElementCount == 0)
    {
        Alloc& allocator = FUN_00c85750()->getHeap();
        int flags = m_kCollisionDetails.m_iCapacityState;
        m_kCollisionDetails.m_iElementCount = 0;
        if ((flags & 0x80000000) == 0)
        {
            allocator.ReturnMemory(m_kCollisionDetails.m_data, (flags & 0x3fffffff) * 4);
        }
        m_kCollisionDetails.m_data = 0;
        m_kCollisionDetails.m_iCapacityState = 0x80000000;
    }
    FUN_00c9e820();
}
}  // namespace fnv_00d1f960

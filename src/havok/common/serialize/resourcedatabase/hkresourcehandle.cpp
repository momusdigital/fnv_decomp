
// src/havok/common/serialize/resourcedatabase/hkresourcehandle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resourcedatabase/hkresourcehandle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkResourceHandle.h"

struct FUN_00e2df60_class
{
    int __thiscall FUN_00e2df60(int);
};

// @fnv 0x00e2df60
int __thiscall FUN_00e2df60_class::FUN_00e2df60(int)
{
    return *(int*)((char*)this + 8) & 0xfffffffe;
}

extern int DAT_010eb19c;
void __cdecl Deallocate(void*);
struct FUN_00e2def0_class
{
    void* m_p;
    int __thiscall InitAndMaybeFree(int flags);
};
// @fnv 0x00e2def0
int __thiscall FUN_00e2def0_class::InitAndMaybeFree(int flags)
{
    m_p = &DAT_010eb19c;
    if (flags & 1)
        Deallocate(this);
    return (int)this;
}

struct FUN_00e2df40_class
{
    const char* __thiscall FUN_00e2df40(int);
};

// @fnv 0x00e2df40
const char* __thiscall FUN_00e2df40_class::FUN_00e2df40(int)
{
    int v = *(const int*)(this + 0xc) & 0xfffffffe;
    return v ? reinterpret_cast<const char*>(v) : "null";
}

struct D481D0RefVariant
{
    const void* GetVariantValue() const;
};
// @fnv 0x00e2df20
const void* __fastcall getClass(char* self, int)
{
    return reinterpret_cast<D481D0RefVariant*>(self + 8)->GetVariantValue();
}

namespace fnv_00e2df30 {
struct D481D0ReferencedObject;
struct D481D0Class;
struct D481D0RefVariant
{
    void set(D481D0ReferencedObject*, D481D0Class const*);
};

struct FUN_00e2df30_class
{
    void setObject(D481D0ReferencedObject* obj, D481D0Class const* cls);
};

// @fnv 0x00e2df30
void FUN_00e2df30_class::setObject(D481D0ReferencedObject* obj, D481D0Class const* cls)
{
    ((D481D0RefVariant*)((char*)this + 8))->set(obj, cls);
}
}  // namespace fnv_00e2df30

struct FUN_00d479e0_class
{
    void* GetValue(void const*, int);
};

struct FUN_00e2df80_obj
{
    virtual int FUN_00e2df80_v00();
    virtual int FUN_00e2df80_v04();
    virtual int FUN_00e2df80_v08();
    virtual int FUN_00e2df80_v0c();
    virtual int FUN_00e2df80_v10();
    virtual int FUN_00e2df80_v14();
    virtual int FUN_00e2df80_v18();
    virtual int FUN_00e2df80_v1c();
};

struct FUN_00e2df80_class
{
    int __thiscall FUN_00e2df80(void* a, int* out);
};

// Clears *out, looks up an object via the helper at this+4, and if found stores its v1c() result in *out and returns its v18() result.
// @fnv 0x00e2df80
int __thiscall FUN_00e2df80_class::FUN_00e2df80(void* apKey, int* piOut)
{
    if (piOut)
        *piOut = 0;
    FUN_00e2df80_obj* obj = (FUN_00e2df80_obj*)((FUN_00d479e0_class*)((char*)this + 4))->GetValue(apKey, 0);
    if (!obj)
        return 0;
    if (piOut)
        *piOut = obj->FUN_00e2df80_v1c();
    return obj->FUN_00e2df80_v18();
}

extern int DAT_010eb288;
struct FUN_00cb0a70
{
    void m(int);
};
struct FUN_00e2ea20_class
{
    int m_p;
    int m_kPointA;
    int m_kPointB;
    FUN_00cb0a70 m_h;
    FUN_00e2ea20_class* FUN_00e2ea20(int a);
};
// @fnv 0x00e2ea20
FUN_00e2ea20_class* FUN_00e2ea20_class::FUN_00e2ea20(int aiValue)
{
    m_p = (int)&DAT_010eb288;
    m_h.m(aiValue);
    return this;
}

struct S_00e028e0_Base
{
    ~S_00e028e0_Base();
};

struct FUN_00e2f1e0_class
{
    void* m_p;
    S_00e028e0_Base m_base;
    void* __thiscall Destroy(int flags);
};

// @fnv 0x00e2f1e0
void* __thiscall FUN_00e2f1e0_class::Destroy(int flags)
{
    m_base.~S_00e028e0_Base();
    m_p = &DAT_010eb19c;
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00e2ea40_class
{
    virtual void FUN_00e2ea40();
};

struct FUN_00e2f210_manager
{
    virtual void unused();
    virtual void unused2();
    virtual void __thiscall release(void* resource, unsigned short handle);
};

struct FUN_00e2f210_router
{
    void* vftable;
    unsigned char padding[0x0c];
    FUN_00e2f210_manager* manager;
};

FUN_00e2f210_router* _D1A0E0GetMemoryRouter();

struct FUN_00e2f210_class : public FUN_00e2ea40_class
{
    unsigned short m_handle;
    void* __thiscall FUN_00e2f210(unsigned int flags);
};

// Runs the base constructor, and if flags has bit 0 set, releases m_handle through the memory router's manager, then returns this.
// @fnv 0x00e2f210
void* FUN_00e2f210_class::FUN_00e2f210(unsigned int flags)
{
    FUN_00e2ea40_class::FUN_00e2ea40();

    if (flags & 1)
    {
        FUN_00e2f210_router* router = _D1A0E0GetMemoryRouter();
        router->manager->release(this, m_handle);
    }

    return this;
}

namespace fnv_00e2f240 {
struct FUN_00e2ec00_class
{
    void ClearItems();
};

struct FUN_00e2f240_manager_class
{
    virtual void FUN_00e2f240_virtual_0();
    virtual void FUN_00e2f240_virtual_1();
    virtual void __thiscall FUN_00e2f240_free(void*, unsigned short);
};

struct FUN_00e2f240_router_class
{
    unsigned char m_auiShapeKeys[0x10];
    FUN_00e2f240_manager_class* m_manager;
};

FUN_00e2f240_router_class* _D1A0E0GetMemoryRouter();

struct FUN_00e2f240_class : public FUN_00e2ec00_class
{
    unsigned char m_auiShapeKeys[4];
    unsigned short m_iElementCount;

    void* __thiscall FUN_00e2f240(int flags);
};

// @fnv 0x00e2f240
void* FUN_00e2f240_class::FUN_00e2f240(int flags)
{
    this->ClearItems();

    if (flags & 1)
    {
        FUN_00e2f240_router_class* router = _D1A0E0GetMemoryRouter();
        router->m_manager->FUN_00e2f240_free(this, m_iElementCount);
    }

    return this;
}
}  // namespace fnv_00e2f240

struct FUN_00e2df50_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int getObject();
};

// @fnv 0x00e2df50
int FUN_00e2df50_Obj::getObject()
{
    return unk08;
}

struct FnvCpu_FUN_00e2df70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    int value;
    int FUN_00e2df70();
};
// @fnv 0x00e2df70
int FnvCpu_FUN_00e2df70_CpuObject::FUN_00e2df70()
{
    return value;
}

struct FNVEntry
{
    int unk00;
    int unk04;
    unsigned int taggedType;
};
int __cdecl FUN_00cb0fa0(const void* filter, const void* tagged);
struct FNVEntryCollection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FNVEntry** items;
    int count;

    FNVEntry* __thiscall FUN_00e2dfd0(const void* filter, FNVEntry* previous);
};
// @fnv 0x00e2dfd0
FNVEntry* __thiscall FNVEntryCollection::FUN_00e2dfd0(const void* filter, FNVEntry* previous)
{
    int index = 0;
    FNVEntry** ppSlot = 0;
    while (previous && index < count && (ppSlot = &items[index++], *ppSlot != previous))
    {
    }

    for (int next = index; next < count; ++next)
    {
        FNVEntry* item = items[next];
        if (!filter || !FUN_00cb0fa0(filter, reinterpret_cast<const void*>(item->taggedType & ~1u)))
        {
            return item;
        }
    }
    return 0;
}

struct Entry
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1c();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2c();
    virtual void m30();
    virtual void process(int);
};
struct MemoryManager
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void freeBlock(void*, int);
};
struct MemoryRouter
{
    void* vt;
    int unk04;
    int unk08;
    int unk0c;
    MemoryManager* manager;
};
struct EntryArray
{
    Entry** data;
    int size;
    int capacityAndFlags;
};
void __stdcall FUN_00e2e2e0(EntryArray*);
MemoryRouter* __cdecl FUN_00c85750();
// @fnv 0x00e2e960
void __stdcall FUN_00e2e960(int aiValue)
{
    EntryArray a;
    a.data = 0;
    a.size = 0;
    a.capacityAndFlags = 0x80000000;
    FUN_00e2e2e0(&a);
    for (int i = 0; i < a.size; ++i)
        a.data[i]->process(aiValue);
    MemoryRouter* pRouter = FUN_00c85750();
    int cap = a.capacityAndFlags;
    {
        MemoryManager* m = pRouter->manager;
        a.size = 0;
        if (!(cap & 0x80000000))
            m->freeBlock(a.data, (cap & 0x3fffffff) * 4);
    }
}

namespace fnv_00e2ec00 {
extern "C" int DAT_010eb2c4;
extern "C" int DAT_0102e388;
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct MemoryAllocator
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Free(void* address, unsigned int bytes);
};
struct MemoryRouter
{
    int m_00, m_04, m_08, m_0c;
    MemoryAllocator* m_pThreadAllocator;
};
void* FUN_00c85750() throw();
struct HandleState
{
    int m_uiFilterValue;
    void FUN_00cb0c00();
};
struct AnimationResource
{
    int* m_ppVirtualMethodTable;
    int m_04;
    HandleState m_handle;
    int m_0c;
    FUN_00c905b0_Class** m_firstItems;
    int m_firstCount;
    int m_firstCapacity;
    FUN_00c905b0_Class** m_secondItems;
    int m_secondCount;
    int m_secondCapacity;
    void ClearItems();
};
// @fnv 0x00e2ec00
void AnimationResource::ClearItems()
{
    m_ppVirtualMethodTable = &DAT_010eb2c4;
    MemoryRouter* router = reinterpret_cast<MemoryRouter*>(FUN_00c85750());
    int count = m_secondCount;
    MemoryAllocator* allocator = router->m_pThreadAllocator;
    FUN_00c905b0_Class** items = m_secondItems;
    int i = 0;
    while (i < count)
    {
        FUN_00c905b0_Class* pItem = items[i];
        if (pItem)
            pItem->FUN_00c905b0();
        items[i] = 0;
        ++i;
    }
    m_secondCount = 0;
    int capacity = m_secondCapacity;
    if ((capacity & 0x80000000) == 0)
        allocator->Free(m_secondItems, (capacity & 0x3fffffff) * sizeof(FUN_00c905b0_Class*));
    m_secondItems = 0;
    m_secondCapacity = 0x80000000;
    router = reinterpret_cast<MemoryRouter*>(FUN_00c85750());
    int iFirstCount = m_firstCount;
    allocator = router->m_pThreadAllocator;
    FUN_00c905b0_Class** pFirstItems = m_firstItems;
    i = 0;
    while (i < iFirstCount)
    {
        FUN_00c905b0_Class* pItem = pFirstItems[i];
        if (pItem)
            pItem->FUN_00c905b0();
        pFirstItems[i] = 0;
        ++i;
    }
    m_firstCount = 0;
    int iFirstCapacity = m_firstCapacity;
    if ((iFirstCapacity & 0x80000000) == 0)
        allocator->Free(m_firstItems, (iFirstCapacity & 0x3fffffff) * sizeof(FUN_00c905b0_Class*));
    m_firstItems = 0;
    m_firstCapacity = 0x80000000;
    m_handle.FUN_00cb0c00();
    m_ppVirtualMethodTable = &DAT_0102e388;
}
}  // namespace fnv_00e2ec00

namespace fnv_00e2f090 {
struct hkAllocatorE2F0
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE2F0
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    hkAllocatorE2F0* m_pkTemp;
    hkAllocatorE2F0* m_pkHeap;
    hkAllocatorE2F0& temp()
    {
        return *m_pkTemp;
    }
    hkAllocatorE2F0& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterE2F0* __cdecl FUN_00c85750() throw();

void __cdecl FUN_00c908c0(hkAllocatorE2F0& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE2F0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE2F0() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayE2F0() throw()
    {
        hkAllocatorE2F0& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

template <typename T, int N> struct hkInplaceArrayE2F0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[N / 4];

    hkInplaceArrayE2F0() : m_data((T*)m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}
    ~hkInplaceArrayE2F0() throw()
    {
        hkAllocatorE2F0& kAlloc = FUN_00c85750()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorE2F0& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(FUN_00c85750()->temp(), n);
        m_iElementCount = n;
    }
};

class hkStringBufE2F0
{
  public:
    hkInplaceArrayE2F0<char, 128> m_kStringBuffer;

    hkStringBufE2F0()
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    void setEmpty()
    {
        m_kStringBuffer[0] = 0;
    }
};

class hkNamedTypeE2F0
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual const char* getName(hkStringBufE2F0& kBuf) const throw();
};

class hkTypeSourceE2F0
{
  public:
    void FUN_00e2e2e0(hkArrayE2F0<hkNamedTypeE2F0*>& kTypesOut) const throw();
};

struct hkBoolE2F0
{
    char m_cBooleanValue;
    hkBoolE2F0(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d87790
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;

    FUN_00d87790(hkBoolE2F0 bIsValid) throw();
    void FUN_00d874d0(const char* pcKey, const void* pvValue) throw();
};

template <typename V> class hkStringMapE2F0
{
  public:
    FUN_00d87790 m_map;

    hkStringMapE2F0(hkBoolE2F0 bIsValid = false) : m_map(bIsValid)
    {}
    void insert(const char* pcKey, V val)
    {
        m_map.FUN_00d874d0(pcKey, val);
    }
};

class FUN_00e2f090
{
  public:
    hkStringMapE2F0<hkNamedTypeE2F0*> m_typeFromName;

    FUN_00e2f090(const hkTypeSourceE2F0* pkSource) throw();
    virtual void V0() throw();
};

// Collects the named types from pkSource and inserts each type into m_typeFromName keyed by its name.
// @fnv 0x00e2f090
FUN_00e2f090::FUN_00e2f090(const hkTypeSourceE2F0* pkSource) throw()
{
    hkArrayE2F0<hkNamedTypeE2F0*> kTypes;
    pkSource->FUN_00e2e2e0(kTypes);
    for (int i = 0; i < kTypes.GetLogicalSize(); i++)
    {
        hkNamedTypeE2F0* pkType = kTypes[i];
        hkStringBufE2F0 kBuf;
        kBuf.setEmpty();
        m_typeFromName.insert(pkType->getName(kBuf), pkType);
    }
}
}  // namespace fnv_00e2f090

class hkMemoryAllocatorE2E2;

struct hkMemoryRouterE2E2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE2E2* m_pStreamAllocator;
};

namespace hkRouterE2E2 {
extern "C" hkMemoryRouterE2E2& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE2E2
{
    char m_cBooleanValue;
    hkBoolE2E2()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE2E2(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE2E2
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE2E2& router = hkRouterE2E2::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE2E2<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

class hkNodeE2E2
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual hkNodeE2E2* vfn_20(int a, int b, hkNodeE2E2* prev);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual hkNodeE2E2* vfn_34(int a, hkNodeE2E2* prev);

    void FUN_00e2e2e0(hkArrayE2E2<hkNodeE2E2*>& out);
};

// Recursively visits nodes returned by vfn_34 and appends nodes returned by vfn_20 to out.
// @fnv 0x00e2e2e0
void hkNodeE2E2::FUN_00e2e2e0(hkArrayE2E2<hkNodeE2E2*>& apOutNodes)
{
    for (hkNodeE2E2* child = vfn_34(0, 0); child; child = vfn_34(0, child))
        child->FUN_00e2e2e0(apOutNodes);
    for (hkNodeE2E2* item = vfn_20(0, 0, 0); item; item = vfn_20(0, 0, item))
        apOutNodes.AddBack(item);
}

class hkMemoryAllocatorE2E3;

struct hkMemoryRouterE2E3
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE2E3* m_pStreamAllocator;
};

namespace hkRouterE2E3 {
extern "C" hkMemoryRouterE2E3& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE2E3
{
    char m_cBooleanValue;
    hkBoolE2E3()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE2E3(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE2E3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE2E3& router = hkRouterE2E3::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE2E3<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

class hkNodeE2E3
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual hkNodeE2E3* vfn_20(int a, int b, hkNodeE2E3* prev);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual hkNodeE2E3* vfn_34(int a, hkNodeE2E3* prev);

    void FUN_00e2e380(hkArrayE2E3<hkNodeE2E3*>& out);
};

// Appends this node to out, then recursively appends all descendant child nodes via vfn_34.
// @fnv 0x00e2e380
void hkNodeE2E3::FUN_00e2e380(hkArrayE2E3<hkNodeE2E3*>& out)
{
    out.AddBack(this);
    for (hkNodeE2E3* child = vfn_34(0, 0); child; child = vfn_34(0, child))
        child->FUN_00e2e380(out);
}

struct S00e2e3f0_Pair
{
    int m_kPointA;
    int m_kPointB;
};

struct S00e2e3f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00e2e3f0_Pair* m_aiIndexedValues;
    int m_uiItemCount;
    void clearExternalLinks();
};

extern "C" __declspec(noinline) void __fastcall FUN_00cb0c00(void* self)
{
    Deallocate(self);
}

// @fnv 0x00e2e3f0
void S00e2e3f0_Obj::clearExternalLinks()
{
    S00e2e3f0_Pair* p = m_aiIndexedValues;
    int n = m_uiItemCount;
    for (int i = 0; i < n; i++)
    {
        FUN_00cb0c00(&p[i].m_kPointB);
        FUN_00cb0c00(&p[i].m_kPointA);
    }
    m_uiItemCount = 0;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl FUN_00cb0fa0(const char*, const char*);
struct String839
{
    unsigned int tagged;
    void FUN_00cb0c00();
    const char* text() const
    {
        return reinterpret_cast<const char*>(tagged & ~1u);
    }
};
struct Pair839
{
    String839 name, value;
};
__forceinline void CopyWords839(void* destination, const void* source, int words)
{
    const unsigned char* in = static_cast<const unsigned char*>(source);
    unsigned char* out = static_cast<unsigned char*>(destination);
    int i = 0;
    do
    {
        memcpy(out + i * 4, in + i * 4, 4);
        ++i;
    } while (i < words);
}
struct Container839
{
    int unk00, unk04, unk08, unk0C;
    Pair839* pairs;
    int size, capacity;
    void removeExternalLink(const char*);
};
// Finds the pair whose name matches name, destroys its strings, decrements size, and copies the last pair into its slot when needed.
// @fnv 0x00e2e430
void Container839::removeExternalLink(const char* name)
{
    for (int i = 0; i < size; ++i)
    {
        if (FUN_00cb0fa0(pairs[i].name.text(), name) == 0)
        {
            Pair839* found = &pairs[i];
            found->value.FUN_00cb0c00();
            found->name.FUN_00cb0c00();
            --size;
            if (size != i)
                CopyWords839(&pairs[i], &pairs[size], sizeof(Pair839) / 4);
            return;
        }
    }
}

struct FUN_00c90510_Class
{
    void FUN_00c90510();
};
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct C
{
    int a, b, c, d;
    void** items;
    int count;
    void RemoveItem(void* item);
};
// Calls FUN_00c90510 on item and searches items; then calls FUN_00c905b0 on item, and if found releases the slot, decrements count, and copies later entries down.
// @fnv 0x00e2e670
void C::RemoveItem(void* item)
{
    if (item)
        reinterpret_cast<FUN_00c90510_Class*>(item)->FUN_00c90510();
    int index;
    int i = 0;
    if (count > 0)
    {
        void** p = items;
        do
        {
            if (*p == item)
            {
                index = i;
                goto found;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    index = -1;
found:
    if (item)
        reinterpret_cast<FUN_00c905b0_Class*>(item)->FUN_00c905b0();
    if (index > -1)
    {
        void** target = items + index;
        if (*target)
            reinterpret_cast<FUN_00c905b0_Class*>(*target)->FUN_00c905b0();
        *target = 0;
        --count;
        int bytes = (count - index) * 4;
        char* dst = reinterpret_cast<char*>(items + index);
        char* src = reinterpret_cast<char*>(items + index + 1);
        for (int k = 0; k < bytes; k += 4)
            *reinterpret_cast<void**>(dst + k) = *reinterpret_cast<void**>(src + k);
    }
}

struct ReferencedE2E710
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
template <class T> struct RefPtrE2E710
{
    RefPtrE2E710(T* e) throw() : m_pRetainedObject(e)
    {
        if (e)
            e->FUN_00c90510();
    }
    ~RefPtrE2E710() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};
template <class T> struct ArrayE2E710
{
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i].m_pRetainedObject == t.m_pRetainedObject)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_data[index].~T();
        m_iElementCount--;
        if (m_iElementCount != index)
            *reinterpret_cast<int*>(m_data + index) = *reinterpret_cast<int*>(m_data + m_iElementCount);
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct WorldE2E710
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ArrayE2E710<RefPtrE2E710<ReferencedE2E710> > m_kThirdFollowingStreamField;
    void RemoveObject(ReferencedE2E710* pkObject);
};

// Finds pkObject in m_kThirdFollowingStreamField and removes it from the array if found.
// @fnv 0x00e2e710
void WorldE2E710::RemoveObject(ReferencedE2E710* pkObject)
{
    int iIndex = m_kThirdFollowingStreamField.indexOf(pkObject);
    if (iIndex > -1)
        m_kThirdFollowingStreamField.removeAt(iIndex);
}

struct FUN_00cb0a60_target
{
    void __thiscall FUN_00cb0a60();
};

struct FUN_00e2e9e0_class
{
    void* m_class;
    unsigned short unk04;
    volatile unsigned short m_handle;
    volatile int m_iObjectReferenceCount;
    FUN_00cb0a60_target m_target;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_flags;

    void* __thiscall Ctor();
};

extern int DAT_010eb288;

// Initializes the object handle, class pointer, reference count, target, and flags, then returns this.
// @fnv 0x00e2e9e0
void* __thiscall FUN_00e2e9e0_class::Ctor()
{
    m_handle = 1;
    m_class = &DAT_010eb288;
    m_iObjectReferenceCount = 0;
    m_target.FUN_00cb0a60();
    m_uiStandInValue = 0;
    m_iValueAfterStandIn = 0;
    m_flags = 0x80000000;
    return this;
}

struct ReferencedE2EB70
{
    ReferencedE2EB70() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedE2EB70() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct NameE2EB70
{
    NameE2EB70(const char* pcName) throw();
    const char* m_pcName;
};
template <class T> struct ArrayE2EB70
{
    ArrayE2EB70() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FUN_00e2eb70 : public ReferencedE2EB70
{
    FUN_00e2eb70(const char* pcName) throw();
    virtual ~FUN_00e2eb70() throw();
    NameE2EB70 m_kName;
    int m_iValue;
    ArrayE2EB70<int> m_kFirst;
    ArrayE2EB70<int> m_kSecond;
};

// Constructs the object, storing pcName in m_kName and initialising m_iValue to 0.
// @fnv 0x00e2eb70
FUN_00e2eb70::FUN_00e2eb70(const char* pcName) throw() : m_kName(pcName), m_iValue(0)
{}

extern int DAT_010eb2c4;

struct Item_e2ebc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct F_e2ebc0
{
    int v;
};

struct FUN_00cb0a70_Class
{
    void FUN_00cb0a70(int);
};

struct FUN_00e2ebc0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Item_e2ebc0** items;
    int itemCount;
    FUN_00e2ebc0_class* Init(F_e2ebc0 flags);
};

// Initializes the object by setting unk00 to DAT_010eb2c4, calling FUN_00cb0a70 with flags.v, and back-linking items when flags.v is set.
// @fnv 0x00e2ebc0
FUN_00e2ebc0_class* FUN_00e2ebc0_class::Init(F_e2ebc0 flags)
{
    unk00 = (int)&DAT_010eb2c4;
    ((FUN_00cb0a70_Class*)((char*)this + 8))->FUN_00cb0a70(flags.v);
    if (flags.v)
    {
        for (int i = 0; i < itemCount; ++i)
            items[i]->unk0c = (int)this;
    }
    return this;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct Heap_e2ef
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
struct Router_e2ef
{
    int unk00, unk04, unk08, unk0C;
    Heap_e2ef* m_pStreamAllocator;
    Heap_e2ef& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_e2ef& __cdecl FUN_00c85750() throw();
};
struct RouterPtr_e2ef
{
    int unk00, unk04, unk08, unk0C;
    void* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement) throw();

struct Container_e2ef;

struct Resource_e2ef
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    Container_e2ef* m_parent;
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
    static void* operator new(unsigned int nbytes) throw()
    {
        Resource_e2ef* p = (Resource_e2ef*)Router_e2ef::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Resource_e2ef* FUN_00e2eb70(const char* name) throw();
    int unk10, unk14, unk18, unk1C, unk20, unk24;
};

template <class T> struct hkRefPtr_e2ef
{
    T* m_pRetainedObject;
    hkRefPtr_e2ef(T* p) throw() : m_pRetainedObject(p)
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c90510();
    }
    hkRefPtr_e2ef(const hkRefPtr_e2ef& o) throw()
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~hkRefPtr_e2ef() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
};

template <class T> struct hkArray_e2ef
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const T& t) throw()
    {
        RouterPtr_e2ef* router = (RouterPtr_e2ef*)FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};

struct Container_e2ef
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual Resource_e2ef* findResource(const char* name, int flags);
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    hkArray_e2ef<hkRefPtr_e2ef<Resource_e2ef> > m_kResources;
    Resource_e2ef* createContainer(const char* name);
};

// Looks up a resource by name, and if missing, allocates one via FUN_00e2eb70, adds it to m_kResources, sets m_parent, and returns it.
// @fnv 0x00e2efe0
Resource_e2ef* Container_e2ef::createContainer(const char* name)
{
    Resource_e2ef* found = findResource(name, 0);
    if (found)
        return found;
    Resource_e2ef* resource = ((Resource_e2ef*)Resource_e2ef::operator new(sizeof(Resource_e2ef)))->FUN_00e2eb70(name);
    m_kResources.AddBack(hkRefPtr_e2ef<Resource_e2ef>(resource));
    resource->m_parent = this;
    resource->FUN_00c905b0();
    return resource;
}

namespace fnv_00e2ea40 {
class hkMemoryAllocatorE2EA
{
  public:
    virtual ~hkMemoryAllocatorE2EA() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE2EA
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE2EA* m_pStreamAllocator;

    hkMemoryAllocatorE2EA& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterE2EA& __cdecl FUN_00c85750() throw();
}

namespace FUN_00cb0c00 {
class hkStringPtr
{
  public:
    ~hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace hkE2EA {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};

template <class T> class ReferenceCountedPointer
{
  public:
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

template <class T> __forceinline void destruct(T* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i].~T();
}

template <class T> class hkArray
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~hkArray() throw()
    {
        hkMemoryAllocatorE2EA& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
}

namespace hkE2EA {
struct ExternalLink
{
    FUN_00cb0c00::hkStringPtr m_kLinkName;
    FUN_00cb0c00::hkStringPtr m_kClassName;
};
}

namespace FUN_00e2ea40 {
class hkMemoryResourceHandle : public hkE2EA::hkReferencedObject
{
  public:
    virtual ~hkMemoryResourceHandle();

    hkE2EA::ReferenceCountedPointer<hkE2EA::hkReferencedObject> m_pReferencedResource;
    FUN_00cb0c00::hkStringPtr m_name;
    hkE2EA::hkArray<hkE2EA::ExternalLink> m_kExternalLinks;
};

// Destructor for hkMemoryResourceHandle; body is empty so members are destroyed by their own destructors.
// @fnv 0x00e2ea40
hkMemoryResourceHandle::~hkMemoryResourceHandle()
{}
}
}  // namespace fnv_00e2ea40

namespace fnv_00e2eae0 {
struct FUN_00e2eae0_Result
{
    void __thiscall FUN_00e2eae0(int* param);
};

struct FUN_00e2eae0_class
{
    virtual void* vf00();
    virtual void* vf04();
    virtual void* vf08();
    virtual void* vf0c();
    virtual void* vf10(void* arg);
    virtual void* vf14();
    virtual void* vf18();
    virtual void* vf1c();
    virtual void* vf20();
    virtual FUN_00e2eae0_Result* vf24();
    void __thiscall FUN_00e2eae0(int* param);
};

struct FUN_00cbbd80_Local
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    void __thiscall InitBuffer();
};

struct FUN_00d61df0_Obj
{
    void __thiscall FUN_00d61df0(void* value);
};

struct FUN_00c85750_Object
{
    virtual void* vf00();
    virtual void* vf04();
    virtual void* vf08();
    virtual void* vf0c();
    virtual void vf10(void* arg1, int arg2);
};

struct FUN_00c85750_Owner
{
    void* unk00;
    void* unk04;
    void* unk08;
    FUN_00c85750_Object* unk0c;
};

extern int DAT_01063cbc;

FUN_00c85750_Owner* __cdecl FUN_00c85750();

// Calls vf24 and vf10, sends two values to the object at param, then conditionally calls allocator->vf10.
// @fnv 0x00e2eae0
void __thiscall FUN_00e2eae0_class::FUN_00e2eae0(int* apTarget)
{
    FUN_00e2eae0_Result* result = vf24();
    if (result != 0)
    {
        result->FUN_00e2eae0(apTarget);
    }

    FUN_00cbbd80_Local local;
    local.InitBuffer();

    void* value = vf10(&local);

    FUN_00d61df0_Obj* target = (FUN_00d61df0_Obj*)apTarget;
    target->FUN_00d61df0(&DAT_01063cbc);
    target->FUN_00d61df0(value);

    FUN_00c85750_Object* allocator = FUN_00c85750()->unk0c;
    int handle = local.unk08;
    local.unk04 = 0;
    if ((handle & 0x80000000u) == 0)
    {
        allocator->vf10((void*)local.unk00, handle & 0x3fffffff);
    }
}
}  // namespace fnv_00e2eae0

struct ExternalLinkString
{
    unsigned int tagged;
    ExternalLinkString() throw()
    {
        FUN_00cb0a60();
    }
    void FUN_00cb0a60() throw();
    void FUN_00cb0c10(const char* text) throw();
};

struct ExternalLinkPair
{
    ExternalLinkString memberName;
    ExternalLinkString externalId;
};

extern void __cdecl ResizeAudioStream(MemoryManager*, void*, int);

struct ExternalLinkHandle : hkResourceHandle
{
    void* object;
    hkStringPtr name;
    hkArray<ExternalLinkPair> references;
    void addExternalLink(const char* memberName, const char* externalId);
};

// Appends a new ExternalLinkPair with the given memberName and externalId to the references array, growing capacity if needed.
// @fnv 0x00e2e040
void ExternalLinkHandle::addExternalLink(const char* memberName, const char* externalId)
{
    hkArray<ExternalLinkPair>* links = &references;
    MemoryRouter* router = FUN_00c85750();
    if (links->m_iElementCount == (links->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->manager, links, sizeof(ExternalLinkPair));
    ExternalLinkPair* link = &links->m_data[links->m_iElementCount];
    if (link)
        new (link) ExternalLinkPair();
    link = &links->m_data[links->m_iElementCount];
    links->m_iElementCount++;
    link->memberName.FUN_00cb0c10(memberName);
    link->externalId.FUN_00cb0c10(externalId);
}

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
struct ObjQ_e2e9e0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void FUN_00e2e9e0_v14(void* a);
    virtual void v18();
    virtual void v1c();
    virtual void FUN_00e2e9e0_v20(void* a, void* b);
    unsigned short m_usMemSizeAndFlags;
    void* Ctor();
};
struct ArrQ_e2ed00
{
    ObjQ_e2e9e0** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FUN_00e2ed00_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ArrQ_e2ed00 unk10;
    ObjQ_e2e9e0* createResource(void* p0, void* p1, void* p2);
};
// Allocates an ObjQ_e2e9e0, initializes it with p0, p1, p2, and appends it to the ArrQ_e2ed00 array at unk10.
// @fnv 0x00e2ed00
ObjQ_e2e9e0* FUN_00e2ed00_class::createResource(void* p0, void* apArg1, void* apArg2)
{
    ObjQ_e2e9e0* obj = (ObjQ_e2e9e0*)Router_e2ef::FUN_00c85750().heap().AllocateMemoryBlock(0x1c);
    obj->m_usMemSizeAndFlags = 0x1c;
    obj = (ObjQ_e2e9e0*)obj->Ctor();
    obj->FUN_00e2e9e0_v14(p0);
    obj->FUN_00e2e9e0_v20(apArg1, apArg2);
    ((Resource_e2ef*)obj)->FUN_00c90510();
    ArrQ_e2ed00* arr = &this->unk10;
    Router_e2ef& audio2 = Router_e2ef::FUN_00c85750();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(audio2.m_pStreamAllocator, arr, 4);
    ObjQ_e2e9e0** slot = arr->m_data + arr->m_iElementCount;
    if (slot != 0)
    {
        ((Resource_e2ef*)obj)->FUN_00c90510();
        *slot = obj;
    }
    arr->m_iElementCount++;
    ((Resource_e2ef*)obj)->FUN_00c905b0();
    ((Resource_e2ef*)obj)->FUN_00c905b0();
    return obj;
}

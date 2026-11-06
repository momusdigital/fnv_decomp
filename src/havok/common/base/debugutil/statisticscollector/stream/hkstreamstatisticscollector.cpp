
// src/havok/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/stream/hkstreamstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct VirtualBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void Dispatch();
};
struct FUN_00ddf020_Class
{
    void __thiscall FUN_00ddf020();
};
// @fnv 0x00ddf020
void __thiscall FUN_00ddf020_Class::FUN_00ddf020()
{
    ((VirtualBase*)this)->Dispatch();
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* arr, int capacity, int elemSize);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int n);

struct hkArrayChar
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void setData(const void* src, int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(&alloc, this, n < cap ? cap : n, 1);
        }
        m_iElementCount = n;
    }
};

union Swap16
{
    unsigned short u;
    unsigned char b[2];
};

inline void swap16(unsigned short* p)
{
    Swap16 in, out;
    in.u = *p;
    out.b[0] = in.b[1];
    out.b[1] = in.b[0];
    *p = out.u;
}

struct Record
{
    unsigned char type;
    unsigned char len;
    unsigned short a;
    unsigned short b;
};

struct hkBool
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Obj
{
    int pad[5];
    hkArrayChar m14;
    void SetData(const void* src, int n, hkBool swap);
};

// Copies n bytes from src into m14, then if swap is set byte-swaps the a and b fields of each record in the buffer.
// @fnv 0x00ddf2a0
void Obj::SetData(const void* src, int n, hkBool swap)
{
    m14.setData(src, n);
    FUN_00cb1260(m14.m_data, src, n);
    if (swap)
    {
        for (int i = 0; i < m14.m_iElementCount;)
        {
            Record* pRecord = (Record*)(m14.m_data + i);
            swap16(&pRecord->a);
            swap16(&pRecord->b);
            i += pRecord->len + 6;
        }
    }
}

namespace fnv_00ddfb40 {
struct MemoryAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void Free(void* memory, unsigned int size);
};
struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryAllocator* allocator;
};
extern AllocatorHolder* __cdecl FUN_00c85750();
struct StreamStatisticsCollector
{
    int unk00;
    unsigned short unk04;
    void FUN_00ddf240();
    void* FreeIfFlagged(unsigned int flags);
};
// @fnv 0x00ddfb40
void* StreamStatisticsCollector::FreeIfFlagged(unsigned int flags)
{
    FUN_00ddf240();
    if (flags & 1)
    {
        AllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Free(this, (unsigned int)unk04);
    }
    return this;
}
}  // namespace fnv_00ddfb40

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

// @fnv 0x00ddf370
static __declspec(noinline) int* FUN_00ddf370(hkArrayChar* apArray, int n)
{
    int* pSlot;
    if (apArray->m_iElementCount > 0)
    {
        pSlot = (int*)(apArray->m_data + apArray->m_iElementCount);
    }
    else
    {
        AudioMgr* pAudioMgr = audio();
        if (apArray->m_iElementCount == apArray->getCapacity())
            ResizeAudioStream(pAudioMgr->unk10, apArray, 1);
        pSlot = (int*)(apArray->m_data + apArray->m_iElementCount);
        apArray->m_iElementCount = apArray->m_iElementCount + 1;
        apArray->setData(0, 0);
    }
    apArray->setData(0, n + apArray->m_iElementCount + 6);
    return pSlot;
}

int* __cdecl fnv_caller(hkArrayChar* a, int n)
{
    return FUN_00ddf370(a, n);
}

inline void* operator new(size_t, void* p)
{
    return p;
}
struct MonitorNode;
struct MonitorChildren
{
    MonitorNode** data;
    int size;
    int capacity;
    void Search(void* heap, int index, MonitorNode** value, int count);
    __declspec(noinline) void CallWithFlag(void* heap, int index, MonitorNode** value)
    {
        Search(heap, index, value, 1);
    }
    MonitorNode*& back()
    {
        return data[size - 1];
    }
    void popBack()
    {
        --size;
    }
};
struct MonitorNode
{
    float value0, value1;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count0, count1;
    int unk24, unk28, unk2c;
    MonitorChildren children;
    int unk3c, unk40, unk44, unk48;
    const char* name;
    int unk50, unk54;
    MonitorNode(MonitorNode* parent, const char* label, int type);
};
struct MonitorString
{
    unsigned int tagged;
    void FUN_00cb0b80(const char* s);
    void FUN_00cb0bd0(const MonitorString& s);
    void FUN_00cb0c00();
};
struct MonitorStrings
{
    MonitorString* data;
    int size;
    int capacity;
};
struct NodeAllocator
{
    virtual ~NodeAllocator();
    virtual void* allocate(int bytes);
};
extern "C" int __cdecl FUN_00cb0fa0(const char* a, const char* b);
static __declspec(noinline) MonitorNode* FUN_00ddf070(const char* name, MonitorStrings* strings, MonitorNode* parent,
                                                      int first, int second)
{
    if (!name)
        name = "?";
    if (!second)
        second = first;
    MonitorNode* node = 0;
    for (int i = 0; parent && i < parent->children.size; ++i)
    {
        if (!FUN_00cb0fa0(parent->children.data[i]->name, name))
        {
            node = parent->children.data[i];
            break;
        }
    }
    if (!node)
    {
        if (strings && name)
        {
            MonitorString text;
            text.FUN_00cb0b80(name);
            void* heap = audio()->unk10;
            if (strings->size == (strings->capacity & 0x3fffffff))
                ResizeAudioStream(heap, strings, 4);
            if (&strings->data[strings->size])
                strings->data[strings->size].FUN_00cb0bd0(text);
            ++strings->size;
            text.FUN_00cb0c00();
            name = (const char*)(strings->data[strings->size - 1].tagged & ~1u);
        }
        NodeAllocator* allocator = (NodeAllocator*)audio()->unk10;
        void* storage = allocator->allocate(sizeof(MonitorNode));
        node = storage ? new (storage) MonitorNode(parent, name, 1) : 0;
    }
    ++node->count0;
    node->value0 += (float)first;
    ++node->count1;
    node->value1 += (float)second;
    return node;
}
// @fnv 0x00ddf680
void __cdecl AggregateChildValues(MonitorNode* node, MonitorStrings* strings)
{
    if (!node || !node->children.size)
        return;
    for (int i = 0; i < node->children.size; ++i)
        AggregateChildValues(node->children.data[i], strings);
    if (node->value0 != 0.0f)
    {
        MonitorNode* child = FUN_00ddf070("self", strings, node, (int)node->value0, (int)node->value1);
        if (node->children.back() == child)
        {
            node->children.popBack();
            node->children.CallWithFlag(audio()->unk10, 0, &child);
        }
    }
    node->value0 = 0.0f;
    node->value1 = 0.0f;
    for (int i = 0; i < node->children.size; ++i)
    {
        MonitorNode* child = node->children.data[i];
        node->value0 = child->value0 + node->value0;
        node->value1 = child->value1 + node->value1;
    }
}

class hkMemoryAllocatorDDF9
{
  public:
    virtual ~hkMemoryAllocatorDDF9() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDDF9
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDDF9* m_pStreamAllocator;
    hkMemoryAllocatorDDF9& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDDF9 {
extern "C" hkMemoryRouterDDF9& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDDF9
{
  public:
    hkArrayDDF9() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayDDF9()
    {
        _clearAndDeallocate(hkRouterDDF9::FUN_00c85750().heap());
    }
    void _clearAndDeallocate(hkMemoryAllocatorDDF9& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class ObjDDF9
{
  public:
    ~ObjDDF9() throw()
    {
        ClearItems();
    }
    void ClearItems() throw();
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterDDF9::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
};

void __stdcall FUN_00ddf740(hkArrayDDF9<ObjDDF9*>& kArray, int iParam) throw();

// @fnv 0x00ddf970
void __stdcall ClearAllItems(int iUnused0, int iUnused1)
{
    hkArrayDDF9<ObjDDF9*> kArray;
    FUN_00ddf740(kArray, 0);
    while (kArray.m_iElementCount)
    {
        delete kArray.m_data[kArray.m_iElementCount - 1];
        kArray.m_iElementCount--;
    }
}

extern int DAT_010d8040;

struct SubBase
{
    void FUN_00d06f50(int a1);
};

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0C(int* pValue);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AudioAllocator* m_pAllocator;
};

inline AudioHolder* holderGet()
{
    return (AudioHolder*)FUN_00c85750();
}

struct SpawnedHandle
{
    void* m_ptr;
    int m_uiFilterValue;
    unsigned int m_flags;
    SpawnedHandle()
    {}
    SpawnedHandle(void* p, int v, unsigned int f) : m_ptr(p), m_uiFilterValue(v), m_flags(f)
    {}
    void EnsureCapacity(void* allocator, int zero);
    int getCap() const
    {
        return (int)(m_flags & 0x3fffffff);
    }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorDDF9& alloc = hkRouterDDF9::FUN_00c85750().heap();
        if (getCap() < n)
        {
            int cap = 2 * getCap();
            FUN_00c908c0((hkMemoryAllocator*)&alloc, this, n < cap ? cap : n, 1);
        }
        m_uiFilterValue = n;
    }
};

struct FUN_00ddf170_cls
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedHandle m_14;
    SpawnedHandle m_20;

    FUN_00ddf170_cls* FUN_00ddf170(int a1, int a2);
};

// Calls a base method, sets the vtable, initializes two SpawnedHandle members, and optionally allocates a buffer.
// @fnv 0x00ddf170
FUN_00ddf170_cls* FUN_00ddf170_cls::FUN_00ddf170(int a1, int aiBufferSize)
{
    ((SubBase*)this)->FUN_00d06f50(a1);
    int value = aiBufferSize;
    m_vtbl = (void*)&DAT_010d8040;
    SpawnedHandle* pHandle = &m_14;
    pHandle->m_ptr = 0;
    pHandle->m_uiFilterValue = 0;
    pHandle->m_flags = 0x80000000u;

    hkMemoryAllocatorDDF9& alloc = hkRouterDDF9::FUN_00c85750().heap();
    void* p;
    if (value)
    {
        int sz = value;
        p = alloc.AllocateBufferWithSize(sz);
        value = sz;
    }
    else
    {
        p = 0;
    }
    unsigned int flags = value ? (unsigned int)value : 0x80000000u;
    pHandle->m_uiFilterValue = value;
    pHandle->m_ptr = p;
    pHandle->m_flags = flags;

    SpawnedHandle* pHandle2 = &m_20;
    pHandle2->m_ptr = 0;
    pHandle2->m_uiFilterValue = 0;
    pHandle2->m_flags = 0xffffffffu;
    AudioAllocator* pAudioAllocator = holderGet()->m_pAllocator;
    m_20.EnsureCapacity(pAudioAllocator, 0);

    pHandle->SetSizeAndGrow(0);
    return this;
}

int FUN_00cb10d0(const char* s);

struct StrPacker
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkArrayChar m14;
    void pushDir(const char* str);
};

// Packs a string into m14 with a 0x50 header, length, and padding when capacity allows.
// @fnv 0x00ddf5a0
void StrPacker::pushDir(const char* str)
{
    if (m14.getCapacity() > m14.m_iElementCount + 0x46)
    {
        int count = 0;
        int pad = 0;
        if (str != 0)
        {
            count = FUN_00cb10d0(str) + 1;
            pad = count % 2;
        }
        unsigned char* out = (unsigned char*)FUN_00ddf370(&m14, pad + count);
        out[0] = 0x50;
        out[1] = (unsigned char)count + (unsigned char)pad;
        *(unsigned short*)(out + 2) = 0;
        *(unsigned short*)(out + 4) = 0;
        if (count > 0)
        {
            FUN_00cb1260(out + 6, str, count);
            if (pad != 0)
                out[count + 6] = 0;
        }
    }
}

struct S_00ddeff0_Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int nbytes);
};

struct S_00ddeff0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddeff0_Heap* m_pStreamAllocator;
    static S_00ddeff0_Router* FUN_00c85750();
    S_00ddeff0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct FUN_00ddeff0
{
    int unk4;
    FUN_00ddeff0();
    virtual ~FUN_00ddeff0();
    void operator delete(void* p, unsigned int nbytes)
    {
        if (p)
            S_00ddeff0_Router::FUN_00c85750()->heap().ReleaseBlock(p, nbytes);
    }
    int unk8;
    int unkC;
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
};

// The constructor body is empty.
// @fnv 0x00ddeff0
FUN_00ddeff0::FUN_00ddeff0()
{}

struct FUN_00ddf640_Cls : Obj
{
    unsigned char* popDir();
};
// @fnv 0x00ddf640
unsigned char* FUN_00ddf640_Cls::popDir()
{
    unsigned char* out = (unsigned char*)m14.getCapacity();
    if ((int)out > m14.m_iElementCount + 0x46)
    {
        out = (unsigned char*)FUN_00ddf370(&m14, 0);
        out[0] = 0x70;
        out[1] = 0;
        *(unsigned short*)(out + 2) = 0;
        *(unsigned short*)(out + 4) = 0;
    }
    return out;
}

namespace fnv_00ddf240 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct SpawnedSub
{
    void Attach(AudioAllocator* apAllocator);
    void Reset();
};

struct SpawnedRoot
{
    virtual ~SpawnedRoot() throw();
};

struct FUN_00ddf240_cls : SpawnedRoot
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_pData;
    int m_iUnk18;
    unsigned int m_uiObjectFlags;
    SpawnedSub m_sub;

    virtual ~FUN_00ddf240_cls() throw();
};

// @fnv 0x00ddf240
FUN_00ddf240_cls::~FUN_00ddf240_cls() throw()
{
    SpawnedSub* pSub = &m_sub;
    AudioHolder* pHolder = FUN_00c85750();
    pSub->Attach(pHolder->m_pAllocator);
    pSub->Reset();
    AudioHolder* pHolder2 = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder2->m_pAllocator;
    unsigned int uFlags = m_uiObjectFlags;
    m_iUnk18 = 0;
    if ((uFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (int)(uFlags & 0x3fffffffu));
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
}
}  // namespace fnv_00ddf240

namespace fnv_00ddfa10 {
struct SpawnHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

SpawnHolder* FUN_00c85750();

struct Sub20_cls
{
    int CB1930(int a, int b);
    void CB1870(int a, int b, int c);
};

typedef void(__thiscall* VSlot8)(void* self, void* owner, int r);

struct FUN_00ddfa10_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    unsigned int m_1c;
    Sub20_cls m_20;

    int D06D90(int a);
    void DDF420(int a, int b, int c);
    int D06D50(int a);
    void DDF020();
    void FUN_00ddfa10(int a1, int a2, unsigned char flag);
};

// After capacity and a2 checks, updates m_20 and calls a virtual function from a2; when flag bit 0 is clear, it also calls DDF420 and DDF020.
// @fnv 0x00ddfa10
void FUN_00ddfa10_cls::FUN_00ddfa10(int a1, int a2, unsigned char aiFlags)
{
    int count = (int)(m_1c & 0x3fffffffu);
    if (count <= m_18 + 0x46)
        return;
    if (a2 == 0)
        return;
    Sub20_cls* sub = &m_20;
    if (sub->CB1930(a2, 0))
        return;
    SpawnHolder* holder = FUN_00c85750();
    sub->CB1870(holder->m_10, a2, 1);
    if ((aiFlags & 1) == 0)
    {
        DDF420(a1, a2, D06D90(a2));
        void** pVTable = *(void***)a2;
        int r = D06D50(a2);
        ((VSlot8)pVTable[2])((void*)a2, this, r);
        DDF020();
    }
    else
    {
        void** pVTable = *(void***)a2;
        int r = D06D50(a2);
        ((VSlot8)pVTable[2])((void*)a2, this, r);
    }
}
}  // namespace fnv_00ddfa10

namespace fnv_00ddfab0 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

struct Param1
{
    int FUN_00d470d0();
};

struct Sub20
{
    int LookupHashEntry(int a, int b);
    void FUN_00cb1870(int a, int b, int c);
};

AudioHolder* __cdecl FUN_00c85750() throw();
void __cdecl FUN_00cf6920(int a, void* b, void* c);

struct FUN_00ddfab0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    unsigned int m_1c;
    Sub20 m_20;

    void FUN_00ddf420(int a, int b, int c);
    void FUN_00ddf020();
    void FUN_00ddfab0(Param1* a1, int a2, int a3, int a4);
};

// Checks m_1c, m_18, and a3; updates m_20, then calls FUN_00cf6920 and conditionally calls FUN_00ddf420 and FUN_00ddf020.
// @fnv 0x00ddfab0
void FUN_00ddfab0_cls::FUN_00ddfab0(Param1* a1, int a2, int a3, int aiFlags)
{
    int iMasked = (int)(m_1c & 0x3fffffff);
    int iLimit = m_18 + 0x46;
    if (iMasked <= iLimit)
    {
        return;
    }
    if (a3 == 0)
    {
        return;
    }
    if (m_20.LookupHashEntry(a3, 0) != 0)
    {
        return;
    }
    AudioHolder* holder = FUN_00c85750();
    m_20.FUN_00cb1870(holder->m_10, a3, 1);
    if ((aiFlags & 1) == 0)
    {
        int r = a1->FUN_00d470d0();
        FUN_00ddf420(a2, a3, r);
        FUN_00cf6920(a3, a1, this);
        FUN_00ddf020();
    }
    else
    {
        FUN_00cf6920(a3, a1, this);
    }
}
}  // namespace fnv_00ddfab0

struct AllocIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual unsigned int allocTag(int size, int tag);
};
struct MonitorStream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkArrayChar m_stream;
    void addChunk(int unused, const char* name, int size, int id, int tag);
};
// Writes a record with type 0x43, name, id, and allocator result; returns early when capacity is low or both id and tag are zero.
// @fnv 0x00ddf4d0
void MonitorStream::addChunk(int unused, const char* name, int size, int id, int tag)
{
    if (m_stream.getCapacity() <= m_stream.m_iElementCount + 0x46)
        return;
    if (id == 0 && tag == 0)
        return;
    int len = 0;
    int odd = 0;
    if (name)
    {
        len = FUN_00cb10d0(name) + 1;
        odd = len % 2;
    }
    unsigned char* p = (unsigned char*)FUN_00ddf370(&m_stream, odd + len);
    p[0] = 0x43;
    p[1] = (unsigned char)(len + odd);
    *(unsigned short*)(p + 2) = (unsigned short)id;
    unsigned int r;
    if (!tag)
        r = 0;
    else
        r = ((AllocIface*)audio()->unk10)->allocTag(size, tag);
    *(unsigned short*)(p + 4) = r;
    if (len > 0)
    {
        FUN_00cb1260(p + 6, name, len);
        if (odd)
            p[len + 6] = 0;
    }
}

struct Pkt : Obj
{
    void FUN_00ddf420(const char* str, const void* a2, int a3);
};
// Writes a six-byte header and an optional null-terminated string padded to an even length; stores an allocator result in the header.
// @fnv 0x00ddf420
void Pkt::FUN_00ddf420(const char* str, const void* a2, int a3)
{
    int len = 0;
    int pad = 0;
    if (str != 0)
    {
        len = FUN_00cb10d0(str) + 1;
        pad = len % 2;
    }
    unsigned char* out = (unsigned char*)FUN_00ddf370(&m14, len + pad);
    Record* rec = (Record*)out;
    rec->type = 0x50;
    rec->len = (unsigned char)(len + pad);
    rec->a = (unsigned short)a3;
    int v;
    if (a3 == 0)
        v = 0;
    else
        v = ((AllocIface&)audio()->heap()).allocTag((int)a2, a3);
    rec->b = (unsigned short)v;
    if (len > 0)
    {
        FUN_00cb1260(out + 6, str, len);
        if (pad != 0)
            out[len + 6] = 0;
    }
}

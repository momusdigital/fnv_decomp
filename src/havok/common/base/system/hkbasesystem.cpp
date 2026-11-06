
// src/havok/common/base/system/hkbasesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/hkbasesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned char DAT_01268414;

// @fnv 0x00cbb950
void __cdecl FUN_00cbb950(unsigned char* out)
{
    *out = DAT_01268414;
}

struct FUN_00c903b0_Class
{
    void ReleaseReference();
};
extern int DAT_01268360;
extern int DAT_01268364;
extern unsigned char DAT_01268a44;
extern unsigned char DAT_01268414;
extern int DAT_011b3dec;
extern "C" void __cdecl FUN_00c90410(int);
extern "C" void __cdecl FUN_00cbb990();
extern "C" void __cdecl FUN_00cbbbd0();
// @fnv 0x00cbbcb0
int __cdecl ShutdownIfInitialized()
{
    if (DAT_01268414)
    {
        FUN_00c90410(0);
        FUN_00cbbbd0();
        if (DAT_01268a44 && DAT_011b3dec)
        {
            ((void(__cdecl*)())DAT_011b3dec)();
            DAT_01268a44 = 0;
        }
        if (DAT_01268360)
            ((FUN_00c903b0_Class*)DAT_01268360)->ReleaseReference();
        DAT_01268360 = 0;
        if (DAT_01268364)
            ((FUN_00c903b0_Class*)DAT_01268364)->ReleaseReference();
        DAT_01268364 = 0;
        FUN_00cbb990();
        DAT_01268414 = 0;
    }
    return 0;
}

extern "C" void __cdecl SetThreadLocalValue(void* value);
extern "C" void __cdecl FUN_00cb0db0();

// @fnv 0x00cbb930
int __cdecl FUN_00cbb930(void* value)
{
    SetThreadLocalValue(value);
    FUN_00cb0db0();
    return 0;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
void __cdecl FUN_00cb0df0(void*);
int __cdecl FUN_00c85760();
void __cdecl SetThreadLocalValue(int);

namespace impl {
// @fnv 0x00cbb990
extern "C" int __cdecl FUN_00cbb990()
{
    void* p = TlsGetValue(DAT_0126835c);
    if (p)
        FUN_00cb0df0(p);
    if (FUN_00c85760())
        SetThreadLocalValue(0);
    return 0;
}
}

extern "C" void* DAT_011b3dbc;
typedef void(__cdecl* Callback)(int, int);
// @fnv 0x00cbbd20
void __stdcall InvokeCallback(int first, int second)
{
    ((Callback)DAT_011b3dbc)(first, second);
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
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

struct LocalBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    void InitBuffer();
};

extern "C" int(__cdecl* DAT_011b3dc0)(int, LocalBuf*);

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0();
};

struct ObjA : RefObj
{
    int unk08, unk0c;
    ObjA* OpenFile(int);
};

struct ObjB : RefObj
{
    int pad[5];
    ObjB* FUN_00d27460(ObjA*, int);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @fnv 0x00cbbee0
ObjB* __stdcall FUN_00cbbee0(int a)
{
    LocalBuf localBuf;
    localBuf.InitBuffer();
    ObjA* objA = (ObjA*)hkAlloc(sizeof(ObjA));
    ObjA* src = objA->OpenFile(DAT_011b3dc0(a, &localBuf));
    ObjB* objB = (ObjB*)hkAlloc(sizeof(ObjB));
    ObjB* result = objB->FUN_00d27460(src, 0x1000);
    src->FUN_00c905b0();
    hkMemoryAllocator& alloc = audio()->tempHeap();
    localBuf.m_iElementCount = 0;
    if ((localBuf.m_iCapacityState & 0x80000000) == 0)
        alloc.ReturnMemory(localBuf.m_data, localBuf.m_iCapacityState & 0x3fffffff);
    return result;
}

struct FUN_00cbc810_cls;

struct FUN_00aa4060_cls
{
    void FUN_00aa4060(FUN_00cbc810_cls* node);
};

extern FUN_00aa4060_cls DAT_011f6238;

struct FUN_00cbc810_cls
{
    unsigned int m_key;
    FUN_00cbc810_cls* m_next;

    void FUN_00b4df30();
    void RemoveKey(unsigned int* pKey);
};

// @fnv 0x00cbc810
void FUN_00cbc810_cls::RemoveKey(unsigned int* puiKey)
{
    unsigned int key = *puiKey;
    if (key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* head_next = m_next;
    if (head_next == 0 && m_key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* cur = this;
    FUN_00cbc810_cls* prev = this;
    do
    {
        if (cur->m_key == key)
        {
            goto found;
        }
        prev = cur;
        cur = cur->m_next;
    } while (cur != 0);
    return;

found:
    if (cur == this)
    {
        if (head_next != 0)
        {
            m_next = head_next->m_next;
            m_key = head_next->m_key;
            head_next->m_next = 0;
            head_next->FUN_00b4df30();
            DAT_011f6238.FUN_00aa4060(head_next);
            return;
        }
        m_key = 0;
        return;
    }
    prev->m_next = cur->m_next;
    cur->m_next = 0;
    cur->FUN_00b4df30();
    DAT_011f6238.FUN_00aa4060(cur);
}

extern int DAT_01268790;
void __cdecl ResizeAudioStream(void* allocator, void* array, int itemSize);

struct SoundNode
{
    int unk00;
    int unk04;
    SoundNode* m_next;
    FUN_00c903b0_Class** m_handle;
};

struct PendingArray
{
    SoundNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    SoundNode* m_kStorage[128];
};

// @fnv 0x00cbbbd0
extern "C" void __cdecl FUN_00cbbbd0()
{
    SoundNode* node = (SoundNode*)DAT_01268790;
    PendingArray pendingList;
    pendingList.m_data = pendingList.m_kStorage;
    pendingList.m_iElementCount = 0;
    pendingList.m_iCapacityState = 0x80000080;

    while (node)
    {
        AudioMgr* pAudioMgr = audio();
        if (pendingList.m_iElementCount == (pendingList.m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&pAudioMgr->heap(), &pendingList, 4);
        pendingList.m_data[pendingList.m_iElementCount++] = node;
        node = node->m_next;
    }

    for (int i = pendingList.m_iElementCount - 1; i >= 0; --i)
    {
        FUN_00c903b0_Class* pHandleObj = *pendingList.m_data[i]->m_handle;
        if (pHandleObj)
        {
            pHandleObj->ReleaseReference();
            *pendingList.m_data[i]->m_handle = 0;
        }
    }

    hkMemoryAllocator& heap = audio()->heap();
    pendingList.m_iElementCount = 0;
    if (!(pendingList.m_iCapacityState & 0x80000000))
        heap.ReturnMemory(pendingList.m_data, (pendingList.m_iCapacityState & 0x3fffffff) * 4);
}

extern int DAT_01268790;
struct SpawnedListNode
{
    int m_00;
    int(__cdecl* m_04)();
    SpawnedListNode* m_08;
    int* m_0c;
};

void __cdecl ResizeAudioStream(void* aAlloc, void* aArray, unsigned int aiElemSize);

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(hkMemoryAllocator* alloc, T val)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc, this, sizeof(T));
        }
        m_data[m_iElementCount++] = val;
    }

    void removeAt(int i)
    {
        m_iElementCount--;
        if (m_iElementCount != i)
        {
            m_data[i] = m_data[m_iElementCount];
        }
    }

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

// Walks the chain, calls m_04 for nodes with zero m_0c, and retries deferred nodes until their calls return nonzero.
// @fnv 0x00cbb9f0
void __cdecl FUN_00cbb9f0()
{
    SpawnedListNode** link = (SpawnedListNode**)&DAT_01268790;
    SpawnedListNode* node = *link;

    hkArray<SpawnedListNode*> pendingNodes;
    pendingNodes.m_data = 0;
    pendingNodes.m_iElementCount = 0;
    pendingNodes.m_iCapacityState = 0x80000000;

    while (node != 0)
    {
        if (*node->m_0c == 0 && node->m_04 != 0)
        {
            int r = node->m_04();
            if (r != 0)
            {
                *node->m_0c = r;
                link = &node->m_08;
                node = *link;
                continue;
            }
            else
            {
                pendingNodes.AddBack(audio()->unk0c, node);
                SpawnedListNode* linked = *link;
                node = node->m_08;
                linked->m_08 = 0;
                *link = node;
                continue;
            }
        }
        link = &node->m_08;
        node = *link;
    }

    if (pendingNodes.m_iElementCount != 0)
    {
        do
        {
            for (int i = pendingNodes.m_iElementCount - 1; i >= 0; --i)
            {
                SpawnedListNode* item = pendingNodes.m_data[i];
                int r = item->m_04();
                if (r != 0)
                {
                    *item->m_0c = r;
                    *link = item;
                    link = &item->m_08;
                    if (--pendingNodes.m_iElementCount != i)
                    {
                        pendingNodes.m_data[i] = pendingNodes.m_data[pendingNodes.m_iElementCount];
                    }
                    else
                    {
                        link = &item->m_08;
                    }
                }
            }
        } while (pendingNodes.m_iElementCount != 0);
    }

    pendingNodes.ClearAndRelease(audio()->unk0c);
}

#include <windows.h>
// Queries the system processor count via GetSystemInfo and stores the minimum of that count and 4 into apiOut.
// @fnv 0x00cbb960
void __cdecl GetProcessorCount(int* piProcessorCount)
{
    SYSTEM_INFO kInfo;
    GetSystemInfo(&kInfo);

    int iProcessorCount = (int)kInfo.dwNumberOfProcessors;
    *piProcessorCount = iProcessorCount < 4 ? iProcessorCount : 4;
}

namespace fnv_00cbb9c0 {
struct SpawnedAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};

struct SpawnedHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

SpawnedHolder* __cdecl FUN_00c85750();

struct SpawnedObject
{
    virtual void v00();
    unsigned short m_w04;
    unsigned short m_w06;

    SpawnedObject()
    {}

    static void* operator new(unsigned int, void* apMemory)
    {
        return apMemory;
    }
};

// Allocates 8 bytes through the holder's allocator, sets m_w04 and m_w06, then placement-constructs a SpawnedObject there.
// @fnv 0x00cbb9c0
void __cdecl FUN_00cbb9c0()
{
    SpawnedHolder* pHolder = FUN_00c85750();
    SpawnedAllocator* pAllocator = pHolder->m_pAllocator;
    SpawnedObject* pSpawnedObject = (SpawnedObject*)pAllocator->Alloc(8);
    pSpawnedObject->m_w04 = 8;
    pSpawnedObject->m_w06 = 1;
    new (pSpawnedObject) SpawnedObject();
}
}  // namespace fnv_00cbb9c0

namespace fnv_00cbbb10 {
extern "C" void __cdecl FUN_00cbb930(int value);
extern "C" void __cdecl FUN_00cbb9f0();
extern "C" unsigned char DAT_010c8eb8;
extern int DAT_01268410;

struct FNV_Allocator
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FNV_Allocator* m_pAllocator;
};

struct SpawnedObject8
{
    void* m_vtbl;
    unsigned short m_size04;
    unsigned short m_flags06;
};

struct SpawnedObject28
{
    unsigned int unk00;
    unsigned short m_size04;
    SpawnedObject28* Init(unsigned int a, unsigned int b);
};

struct VirtualIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

AllocHolder* __cdecl FUN_00c85750();

// Allocates and initializes two spawned objects, stores them in global pointers, and sets the initialization flag.
// @fnv 0x00cbbb10
int __cdecl FUN_00cbbb10(int a1, unsigned int auParam1, unsigned int auParam2)
{
    if (DAT_01268414 != 0)
    {
        return 0;
    }
    FUN_00cbb930(a1);
    AllocHolder* holder = FUN_00c85750();
    SpawnedObject8* obj8 = (SpawnedObject8*)holder->m_pAllocator->Alloc(8);
    obj8->m_size04 = 8;
    obj8->m_flags06 = 1;
    obj8->m_vtbl = &DAT_010c8eb8;
    if (DAT_01268364 != 0)
    {
        ((FUN_00c903b0_Class*)DAT_01268364)->ReleaseReference();
    }
    DAT_01268364 = (int)obj8;

    holder = FUN_00c85750();
    SpawnedObject28* obj28 = (SpawnedObject28*)holder->m_pAllocator->Alloc(0x28);
    obj28->m_size04 = 0x28;
    obj28 = obj28->Init(auParam1, auParam2);
    if (DAT_01268360 != 0)
    {
        ((FUN_00c903b0_Class*)DAT_01268360)->ReleaseReference();
    }
    DAT_01268360 = (int)obj28;
    FUN_00cbb9f0();
    ((VirtualIface*)DAT_01268410)->v3();
    DAT_01268414 = 1;
    return 0;
}
}  // namespace fnv_00cbbb10

namespace fnv_00cbbde0 {
struct S_00cbbde0_Allocator
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void vfn8();
    virtual void vfnc();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00cbbde0_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_00cbbde0_Allocator* unkc;
    S_00cbbde0_Allocator* unk10;
    S_00cbbde0_Allocator& temp()
    {
        return *unkc;
    }
    S_00cbbde0_Allocator& heap()
    {
        return *unk10;
    }
};

S_00cbbde0_Router* FUN_00c85750() throw();

struct S_00cbbde0_Bool
{
    char m_cBooleanValue;
    S_00cbbde0_Bool()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00cbbde0_StringBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    // inline storage for 128 chars; declared as ints because the original has no /GS cookie
    unsigned int m_kStorage[32];

    S_00cbbde0_StringBuf() throw();
    ~S_00cbbde0_StringBuf() throw()
    {
        S_00cbbde0_Allocator& a = FUN_00c85750()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(char));
    }
};

struct S_00cbbde0_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00cbbde0_RefObject() throw();
    void* operator new(unsigned int n)
    {
        S_00cbbde0_RefObject* b = static_cast<S_00cbbde0_RefObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*)
    {}
    void FUN_00c905b0() throw();
};

struct S_00cbbde0_Reader : S_00cbbde0_RefObject
{
    virtual void vfn4();
    virtual void vfn8();
    virtual void vfnc();
    virtual void vfn10();
    virtual void vfn14();
    virtual S_00cbbde0_Bool vfn18();
};

struct S_00cbbde0_StdioReader : S_00cbbde0_Reader
{
    int unk8;
    int unkc;
    int unk10;
    S_00cbbde0_StdioReader(const char* name) throw();
};

struct S_00cbbde0_BufferedReader : S_00cbbde0_Reader
{
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S_00cbbde0_BufferedReader(S_00cbbde0_Reader* s, int bufSize) throw();
};

extern const char*(__cdecl* DAT_011b3dc0)(const char* name, S_00cbbde0_StringBuf& buf);

// Creates a StdioReader from the resolved path, wraps it in a 4096-byte BufferedReader when vfn18() is false, and returns the resulting reader.
// @fnv 0x00cbbde0
S_00cbbde0_Reader* __stdcall openReader(const char* name) throw()
{
    S_00cbbde0_StringBuf buf;
    S_00cbbde0_Reader* reader = new S_00cbbde0_StdioReader(DAT_011b3dc0(name, buf));
    if (!reader->vfn18())
    {
        S_00cbbde0_Reader* pBufferedReader = new S_00cbbde0_BufferedReader(reader, 0x1000);
        reader->FUN_00c905b0();
        return pBufferedReader;
    }
    return reader;
}
}  // namespace fnv_00cbbde0

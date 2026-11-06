
// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* DAT_11ac230;
// @fnv 0x00aa1ab0
void __cdecl FUN_00aa1ab0()
{
    ((void (*)())DAT_11ac230)();
}

struct S_00a8d8b0
{
    int _0;
    int pos;
    unsigned int(__cdecl* fn)(S_00a8d8b0*, void*, unsigned int, unsigned int*, unsigned int);
};
// @fnv 0x00a8d8b0
void __cdecl AdvancePosition(S_00a8d8b0* apState, void* b, unsigned int c)
{
    unsigned int tmp = 1;
    apState->pos += apState->fn(apState, b, c, &tmp, 1);
}

struct NiTFixedStringMap_NiAVObject___
{
    void RemoveAll();
};
void _NiFreeAlias(void*);
struct MemoryManager
{
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_01101378;
extern int DAT_01101388;
struct SomeClass
{
    void* FUN_00ee90b0(unsigned int);
};
// @fnv 0x00ee90b0
void* SomeClass::FUN_00ee90b0(unsigned int uiFlags)
{
    *(int*)this = (int)&DAT_01101388;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    *(int*)this = (int)&DAT_01101378;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (uiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

void __cdecl FUN_00ee9a60();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00ee9ca0_shell
{
    void* __thiscall FUN_00ee9ca0(unsigned int flags);
};
// @fnv 0x00ee9ca0
void* __thiscall FUN_00ee9ca0_shell::FUN_00ee9ca0(unsigned int flags)
{
    FUN_00ee9a60();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

namespace fnv_00ee8e70 {
struct NiTFixedStringMap_NiAVObject___
{
    void RemoveAll();
};

struct NiGPUProgramCache
{
    char _pad0[8];
    NiTFixedStringMap_NiAVObject___ m_kObjectMap;
    char _pad1[0x30];
    bool m_bLoadComplete;
    bool FUN_00ee8e70();
};

// @fnv 0x00ee8e70
bool __thiscall NiGPUProgramCache::FUN_00ee8e70()
{
    m_kObjectMap.RemoveAll();
    m_bLoadComplete = false;
    return true;
}
}  // namespace fnv_00ee8e70

namespace fnv_00ee9070 {
extern void* DAT_01101378;
void __cdecl NiFreeAlias(void*);
struct MemoryManager
{
    void* Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct NiTFixedStringMap_NiAVObject___
{
    void RemoveAll();
};
struct FUN_00ee9070_shell : NiTFixedStringMap_NiAVObject___
{
    void* m_p;
    FUN_00ee9070_shell* __thiscall FUN_00ee9070(bool);
};
// Sets the vtable, removes all entries, frees the object at offset 8, and optionally deallocates this instance.
// @fnv 0x00ee9070
FUN_00ee9070_shell* __thiscall FUN_00ee9070_shell::FUN_00ee9070(bool b)
{
    *(void**)this = &DAT_01101378;
    RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
    if (b & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ee9070

struct FUN_00a5e3a0_Helper
{
    void* FUN_00aa3e40(unsigned int);
};
struct NiStandardAllocator
{
    static void* __cdecl operator new(unsigned int);
    virtual void func();
};
void* __cdecl NiStandardAllocator::operator new(unsigned int n)
{
    return ((FUN_00a5e3a0_Helper*)&g_memoryManager)->FUN_00aa3e40(n);
}
struct FUN_00aa2200
{
    NiStandardAllocator* object;
    unsigned char initialized;
    FUN_00aa2200();
};
// Allocates a NiStandardAllocator via operator new and stores it in object, then sets initialized to 1.
// @fnv 0x00aa2200
FUN_00aa2200::FUN_00aa2200()
{
    object = new NiStandardAllocator;
    initialized = 1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* _EmptyFS;

class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString& operator=(const NiFixedString& s)
    {
        if (m_kHandle != s.m_kHandle)
        {
            char* h = s.m_kHandle;
            if (h != _EmptyFS)
                InterlockedIncrement((long*)(h - 8));
            if (m_kHandle != _EmptyFS)
                InterlockedDecrement((long*)(m_kHandle - 8));
            m_kHandle = h;
        }
        return *this;
    }
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiObjPtr
{
  public:
    NiRefObject* m_pObject;
    NiObjPtr& operator=(const NiObjPtr& p)
    {
        if (m_pObject != p.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct MapItem
{
    MapItem* m_pkNext;
    NiFixedString m_key;
    NiObjPtr m_val;
};

class FixedStringMap
{
  public:
    virtual ~FixedStringMap();
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;

    void GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val);
};

// Reads the current item's key and value into key and val, advances pos to the next item or the next non-empty hash bucket, or sets pos to 0 at the end.
// @fnv 0x00ee8f10
void FixedStringMap::GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val)
{
    MapItem* pkItem = pos;
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = (unsigned int)pkItem->m_key.m_kHandle % m_uiHashSize;
    for (++i; i < m_uiHashSize; i++)
    {
        pkItem = m_ppkHashTable[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

bool __cdecl FUN_00aa2cc0(const char*) throw();
bool __cdecl FUN_00aa2d10(char*, unsigned int) throw();
int __cdecl BuildAbsolutePath(char*, unsigned int, const char*, const char*) throw();

struct S_00ee8af0_String : NiFixedString
{
    S_00ee8af0_String() throw()
    {}
    S_00ee8af0_String(const S_00ee8af0_String& s) throw()
    {
        if (s.m_kHandle != _EmptyFS)
            InterlockedIncrement((long*)(s.m_kHandle - 8));
        m_kHandle = s.m_kHandle;
    }
    S_00ee8af0_String(const NiFixedString& s) throw()
    {
        if (s.m_kHandle != _EmptyFS)
            InterlockedIncrement((long*)(s.m_kHandle - 8));
        m_kHandle = s.m_kHandle;
    }
    ~S_00ee8af0_String() throw()
    {
        if (m_kHandle != _EmptyFS)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }
    using NiFixedString::operator=;
    S_00ee8af0_String& operator=(const char* str) throw();
};

struct S_00ee8af0
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1A();
    virtual void vfn1B();
    virtual void vfn1C();
    virtual void vfn1D();
    virtual void vfn1E();
    virtual void vfn1F();
    virtual void vfn20() throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    S_00ee8af0_String m_kString;

    bool SetString(const NiFixedString& s) throw();
};

// @fnv 0x00ee8af0
bool S_00ee8af0::SetString(const NiFixedString& akString) throw()
{
    S_00ee8af0_String kOld = this->m_kString;

    if (akString.m_kHandle != _EmptyFS && FUN_00aa2cc0(akString.m_kHandle))
    {
        char acDir[260];
        if (FUN_00aa2d10(acDir, 260))
        {
            const char* pcHandle = akString.m_kHandle;
            char acFullPath[260];
            if (BuildAbsolutePath(acFullPath, 260, pcHandle, acDir))
            {
                this->m_kString = acFullPath;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        this->m_kString = akString;
    }

    if (kOld.m_kHandle != this->m_kString.m_kHandle)
    {
        this->vfn20();
    }
    return true;
}

// ---------------------------------------------------------------------------
// stand-in for the game's "path" map class.
//
// The class is a FixedStringMap subclass (the map header lives at +0x00:
// vptr / m_uiHashSize / m_ppkHashTable) that keeps three fixed strings
// (+0x18, +0x1c, +0x20) and two flag bytes at +0x39 / +0x3a.
// ---------------------------------------------------------------------------

class FixedPathMap : public FixedStringMap
{
  public:
    int unk0c;
    int unk10;
    int unk14;
    NiFixedString m_18;
    NiFixedString m_1c;
    NiFixedString m_20;
    void* unk24;
    void* unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char m_39;
    unsigned char m_3a;

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void onStringChanged();

    void UpdatePathString();
};

// helpers of the game (declared only)
void __cdecl BuildAbsolutePath(char* buffer, unsigned int size, char* a, char* b);
char* __cdecl FUN_00a5b690(char* str);

// Rebuilds m_20 from m_18 and m_1c via BuildAbsolutePath, or clears it and m_39 when either handle is empty; calls onStringChanged if the handle changed.
// @fnv 0x00ee8c10
void FixedPathMap::UpdatePathString()
{
    if (m_1c.m_kHandle != _EmptyFS && m_18.m_kHandle != _EmptyFS)
    {
        if (m_20.m_kHandle != _EmptyFS)
            InterlockedIncrement((long*)(m_20.m_kHandle - 8));

        char buffer[0x104];
        char* old = m_20.m_kHandle;
        BuildAbsolutePath(buffer, 0x104, m_18.m_kHandle, m_1c.m_kHandle);

        char* rel = m_20.m_kHandle;
        if (rel != buffer)
        {
            m_20.m_kHandle = FUN_00a5b690(buffer);
            if (rel != _EmptyFS)
                InterlockedDecrement((long*)(rel - 8));
        }
        if (old != m_20.m_kHandle)
            onStringChanged();
        if (old != _EmptyFS)
            InterlockedDecrement((long*)(old - 8));
    }
    else
    {
        char* cur = m_20.m_kHandle;
        if (cur != 0)
        {
            m_20.m_kHandle = FUN_00a5b690(0);
            if (cur != _EmptyFS)
                InterlockedDecrement((long*)(cur - 8));
        }
        m_39 = 0;
    }
}

namespace fnv_00ee8e10 {
char* __cdecl FUN_00a5b690(const char* s);
struct S_00ee8e10_Arr
{
    char** data;
    unsigned int count;
    int size;
    void FUN_00ee8e10();
};
// Releases each stored string pointer, decrementing its reference count when non-null and not the empty-string sentinel, then resets size to 0.
// @fnv 0x00ee8e10
void S_00ee8e10_Arr::FUN_00ee8e10()
{
    for (unsigned int i = 0; i < count; i++)
    {
        char*& e = data[i];
        char* h = e;
        if (h)
        {
            e = FUN_00a5b690(0);
            if (h != _EmptyFS)
                InterlockedDecrement((long*)(h - 8));
        }
    }
    size = 0;
}
}  // namespace fnv_00ee8e10

class FUN_00ee8fe0_cls
{
  public:
    NiRefObject** m_ppkTable;
    unsigned int unk04;
    unsigned int m_uiSize;

    void RemoveAt(unsigned int idx);
};

// Removes the element at idx by shifting later slots down with refcount updates, then decrements m_uiSize and releases the last slot.
// @fnv 0x00ee8fe0
void FUN_00ee8fe0_cls::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex < m_uiSize - 1)
    {
        do
        {
            NiRefObject** slot = &m_ppkTable[uiIndex];
            NiRefObject* cur = *slot;
            if (cur != slot[1])
            {
                if (cur)
                {
                    cur->DecRefCount();
                }
                *slot = slot[1];
                if (*slot)
                {
                    (*slot)->IncRefCount();
                }
            }
            uiIndex++;
        } while (uiIndex < m_uiSize - 1);
    }
    m_uiSize--;
    NiRefObject** ppLastSlot = &m_ppkTable[m_uiSize];
    NiRefObject* last = *ppLastSlot;
    if (last)
    {
        last->DecRefCount();
        *ppLastSlot = 0;
    }
}

extern void* DAT_11ac230;
void __cdecl FUN_00aa1ab0();

void __cdecl AdvancePosition(S_00a8d8b0* a, void* b, unsigned int c);

// Reads a length-prefixed string into a2 via self->fn, advances self->pos, and null-terminates the buffer; returns false if a3 is 0 or a2 is null.
// @fnv 0x00ee92d0
bool __stdcall FUN_00ee92d0(S_00a8d8b0* self, unsigned int pBuffer, unsigned int a3)
{
    if (a3 == 0)
        goto fail;
    char* out = (char*)pBuffer;
    if (out != 0)
    {
        unsigned int* pLength = &a3;
        *pLength = 0;
        unsigned int* pReadSize = &pBuffer;
        *pReadSize = 4;
        unsigned int n = self->fn(self, pLength, 4, pReadSize, 1);
        self->pos += (int)n;
        unsigned int v = *pLength;
        if (v == 0)
            goto zero;
        AdvancePosition(self, out, *pLength);
        out[*(volatile unsigned int*)pLength + 1] = 0;
        return true;
    zero:
        *out = (char)v;
        return true;
    }
fail:
    return false;
}

struct S_00ee97e0_Stream
{
    int unk00;
    unsigned int pos;
    int unk08;
    unsigned int(__cdecl* fn)(S_00ee97e0_Stream*, void*, unsigned int, unsigned int*, unsigned int);
};

struct S_00ee97e0_Elem
{
    int* FUN_00a62660();
    int* FUN_00eea4f0();
    int* FUN_00eea500();
    int* FUN_00eea510();
    int* FUN_00eea520();
    int FUN_00be0ad0();
    int FUN_00aa1ac0();
    int FUN_00dbbc00();
    int GetShaderDecl();
};

struct S_00ee97e0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ee97e0_Elem** unk0c;
    int unk10;
    unsigned int unk14;
};

__forceinline void S_00ee97e0_Write(S_00ee97e0_Stream* s, void* data)
{
    unsigned int sz = 4;
    s->pos += s->fn(s, data, 4, &sz, 1);
}

struct S_00ee97e0_Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual bool vf90(S_00ee97e0_Stream* s, int v);
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
    bool WriteToStream(S_00ee97e0_Stream* s, S_00ee97e0_Obj* o, int* v);
    void FUN_00ee9230(S_00ee97e0_Stream* s, int v);
};

// @fnv 0x00ee97e0
bool S_00ee97e0_Cls::WriteToStream(S_00ee97e0_Stream* pStream, S_00ee97e0_Obj* pObj, int* piValue)
{
    S_00ee97e0_Write(pStream, &unk34);
    FUN_00ee9230(pStream, *piValue);
    int f8 = pObj->unk08;
    if (!vf90(pStream, f8))
        return false;
    unsigned int count = pObj->unk14;
    S_00ee97e0_Write(pStream, &count);
    for (unsigned int i = 0; i < count; i++)
    {
        S_00ee97e0_Elem* e = pObj->unk0c[i];
        FUN_00ee9230(pStream, *e->FUN_00a62660());
        FUN_00ee9230(pStream, *e->FUN_00eea4f0());
        FUN_00ee9230(pStream, *e->FUN_00eea500());
        FUN_00ee9230(pStream, *e->FUN_00eea510());
        FUN_00ee9230(pStream, *e->FUN_00eea520());
        int a = e->FUN_00be0ad0();
        S_00ee97e0_Write(pStream, &a);
        int b = e->FUN_00aa1ac0();
        S_00ee97e0_Write(pStream, &b);
        int c = e->FUN_00dbbc00();
        S_00ee97e0_Write(pStream, &c);
        int iValD = e->GetShaderDecl();
        S_00ee97e0_Write(pStream, &iValD);
    }
    return true;
}

// CreateRecordPair - allocate a 12 byte record from the global allocator
// (DAT_011f6238) and clear its two counter fields.  When the allocation
// fails the pointer is replaced by a null pointer which is then written
// through, exactly like the original code does.

struct RecordPair
{
    unsigned int unk00;
    unsigned int m_i04;
    unsigned int m_i08;
};

extern "C" FUN_00a5e3a0_Helper DAT_011f6238;

// @fnv 0x00ee99b0
RecordPair* __cdecl CreateRecordPair()
{
    RecordPair* pRecord = (RecordPair*)DAT_011f6238.FUN_00aa3e40(0xc);
    if (pRecord)
    {
        pRecord->m_i08 = 0;
    }
    else
    {
        pRecord = 0;
    }
    pRecord->m_i04 = 0;
    return pRecord;
}

char* __cdecl FUN_00a5b690(const char*);

struct FixedStringDtor
{
    char* m_kHandle;
    __forceinline FixedStringDtor& operator=(const char* pcString)
    {
        if (m_kHandle)
        {
            char* pcOld = m_kHandle;
            m_kHandle = FUN_00a5b690(pcString);
            if (pcOld != _EmptyFS)
            {
                InterlockedDecrement((long*)(pcOld - 8));
            }
        }
        return *this;
    }
    __forceinline ~FixedStringDtor() throw()
    {
        if (m_kHandle != _EmptyFS)
        {
            InterlockedDecrement((long*)(m_kHandle - 8));
        }
    }
};

struct ObjPtrDtor
{
    NiRefObject* m_pObject;
    __forceinline ObjPtrDtor& operator=(NiRefObject* pNew)
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = pNew;
        }
        return *this;
    }
    __forceinline ~ObjPtrDtor() throw()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct ItemWithDtor
{
    void* m_pkNext;
    FixedStringDtor m_key;
    ObjPtrDtor m_val;

    __forceinline ~ItemWithDtor() throw()
    {}

    void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

// Clears the item's key and value, then deletes the item through its custom operator delete.
// @fnv 0x00ee99d0
void __stdcall ClearAndDeleteItem(ItemWithDtor* pItem)
{
    pItem->m_key = (const char*)0;
    pItem->m_val = (NiRefObject*)0;
    delete pItem;
}

extern long DAT_011f4400;
extern char* DAT_0109b220;

void __cdecl FreeTable(void* p);
void __cdecl FreeBlock(void* p);

struct ReleaseHelper
{
    void Release();
};
struct MapClearHelper
{
    void FUN_00ee8e10();
};

class SpawnedRoot
{
  public:
    virtual ~SpawnedRoot() throw()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};

class SpawnedBase
{
  public:
    virtual ~SpawnedBase() throw()
    {
        reinterpret_cast<ReleaseHelper*>(this)->Release();
        FreeBlock(m_p);
    }
    int unk04;
    void* m_p;
};

class SpawnedObject : public SpawnedBase
{
  public:
    virtual ~SpawnedObject() throw()
    {
        reinterpret_cast<ReleaseHelper*>(this)->Release();
    }
};

class FUN_00ee9a60_cls : public SpawnedRoot
{
  public:
    virtual ~FUN_00ee9a60_cls() throw();
    int unk04;
    SpawnedObject m_sub;
    int unk14;
    NiFixedString m_s0;
    NiFixedString m_s1;
    NiFixedString m_s2;
    NiFixedString m_s3;
    unsigned int m_mapHead;
};

// Destructor: clears the map at m_mapHead, frees its table, then releases the four NiFixedString handles and the base.
// @fnv 0x00ee9a60
FUN_00ee9a60_cls::~FUN_00ee9a60_cls() throw()
{
    reinterpret_cast<MapClearHelper*>(&m_mapHead)->FUN_00ee8e10();
    FreeTable(reinterpret_cast<void*>(m_mapHead));
    if (m_s3.m_kHandle != DAT_0109b220)
        InterlockedDecrement((long*)(m_s3.m_kHandle - 8));
    if (m_s2.m_kHandle != DAT_0109b220)
        InterlockedDecrement((long*)(m_s2.m_kHandle - 8));
    if (m_s1.m_kHandle != DAT_0109b220)
        InterlockedDecrement((long*)(m_s1.m_kHandle - 8));
    if (m_s0.m_kHandle != DAT_0109b220)
        InterlockedDecrement((long*)(m_s0.m_kHandle - 8));
}

namespace fnv_00ee9b10 {
// Reconstruction of LookupAndVisit: a fixed-string-map lookup that walks the
// value object's element array and hands every element to a visitor.
//
// The map lookup (Ee9b10_Map::Lookup) is defined here on purpose: when
// the callee is only declared, MSVC 2008 assumes it can write any memory, so
// the value pointer is reloaded from its stack slot after every call. With the
// body visible, the compiler knows the callee only writes through the
// out-parameter, and the value pointer stays in a callee-saved register.

struct Ee9b10_Value;
struct Ee9b10_Item
{
    int unk00;
};

struct Ee9b10_Map
{
    int unk00;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    bool __declspec(noinline) Lookup(NiFixedString& key, Ee9b10_Value*& val);
};

struct Ee9b10_Visitor
{
    void FUN_00e8ea60(Ee9b10_Item** pItem);
};

struct Ee9b10_Value : public NiRefObject
{
    void* m_pFirst;
    Ee9b10_Item** m_pEntryData;
    int unk10;
    unsigned int m_uiItemCount;
};

struct Ee9b10_Owner
{
    int unk00;
    int unk04;
    Ee9b10_Map m_map;
    void* LookupAndVisit(const char* name, Ee9b10_Visitor* visitor);
};

void* __cdecl FUN_00a5b690(const char* str);

// Hash the key handle, walk the bucket chain and publish the entry that
// matches; the old value is released and the new one referenced, exactly like
// the game's map lookup does.
bool Ee9b10_Map::Lookup(NiFixedString& key, Ee9b10_Value*& val)
{
    MapItem* node = 0;
    if (m_uiHashSize != 0 && m_ppkHashTable != 0)
    {
        unsigned int slot = (unsigned int)((size_t)key.m_kHandle / m_uiHashSize);
        node = m_ppkHashTable[slot];
        while (node != 0)
        {
            if (node->m_key.m_kHandle == key.m_kHandle)
                break;
            node = node->m_pkNext;
        }
    }
    if (node == 0)
        return false;
    NiRefObject* found = node->m_val.m_pObject;
    NiRefObject* old = val;
    if (old != found)
    {
        if (old != 0)
            old->DecRefCount();
        val = (Ee9b10_Value*)found;
        if (found != 0)
            found->IncRefCount();
    }
    return true;
}

// Looks up name in m_map, visits each item with visitor, and returns the value's m_pFirst, releasing the string and value references.
// @fnv 0x00ee9b10
void* Ee9b10_Owner::LookupAndVisit(const char* name, Ee9b10_Visitor* visitor)
{
    char* h;
    if (!name)
        h = _EmptyFS;
    else
        h = (char*)FUN_00a5b690(name);
    NiFixedString key;
    key.m_kHandle = h;
    Ee9b10_Value* val = 0;
    if (m_map.Lookup(key, val))
    {
        for (unsigned int i = 0; i < val->m_uiItemCount; i++)
        {
            visitor->FUN_00e8ea60(&val->m_pEntryData[i]);
        }
        void* pResult = val->m_pFirst;
        val->DecRefCount();
        if (h != _EmptyFS)
            InterlockedDecrement((long*)(h - 8));
        return pResult;
    }
    if (val)
        val->DecRefCount();
    if (h != _EmptyFS)
        InterlockedDecrement((long*)(h - 8));
    return 0;
}
}  // namespace fnv_00ee9b10

namespace fnv_00ee9bf0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long DAT_011f4400;
extern unsigned int DAT_0109b220;
void* __cdecl FUN_00aa1070(unsigned int);
void* __cdecl FUN_00ec61c0(void*, unsigned int, unsigned int);
void* __cdecl FUN_00a63ae0(unsigned int);

struct S_00ee9bf0_Base
{
    int unk04;
    virtual void vf0();
    S_00ee9bf0_Base()
    {
        unk04 = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
};
struct S_00ee9bf0_B
{
    unsigned int unk0c;
    void* unk10;
    unsigned int unk14;
    virtual void vf0();
    __forceinline S_00ee9bf0_B()
    {
        unk0c = 0x25;
        unk14 = 0;
        unk10 = FUN_00aa1070(0x94);
        FUN_00ec61c0(unk10, 0, unk0c * 4);
    }
};
struct S_00ee9bf0_C : S_00ee9bf0_B
{
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    void* unk28;
    unsigned int unk2c;
    unsigned int unk30;
    virtual void vf0();
    __forceinline S_00ee9bf0_C()
    {
        unk18 = DAT_0109b220;
        unk1c = DAT_0109b220;
        unk20 = DAT_0109b220;
        unk24 = DAT_0109b220;
        unk28 = FUN_00a63ae0(0xa);
        unk30 = 0;
        unk2c = 0xa;
    }
};
struct FUN_00ee9bf0 : S_00ee9bf0_Base
{
    S_00ee9bf0_C alloc;
    void* unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    virtual void vf1();
    FUN_00ee9bf0(void* a, unsigned char b, unsigned char c);
};
// @fnv 0x00ee9bf0
FUN_00ee9bf0::FUN_00ee9bf0(void* a, unsigned char b, unsigned char c)
{
    unk34 = a;
    unk38 = b;
    unk39 = 0;
    unk3a = c;
}
}  // namespace fnv_00ee9bf0

extern "C" int __cdecl strcmp(const char*, const char*);
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct KeyObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual unsigned int CountKeys();
    virtual const char* GetKey(unsigned int index);
};

struct KeyEntry
{
    char** FUN_00eea510();
    __forceinline bool CompareKey(const char* key)
    {
        char* hk = *FUN_00eea510();
        if (hk == key)
            return true;
        if (!key || !hk)
            return false;
        return strcmp(hk, key) == 0;
    }
};

struct FUN_00ee90f0_cls
{
    KeyEntry** m_ppEntries;
    unsigned int unk04;
    unsigned int m_uiItemCount;
    void RemoveAt(int index);
};

// Marks entries whose keys appear in a1, then removes every unmarked entry from a2 by index in reverse order and returns true.
// @fnv 0x00ee90f0
bool __stdcall RemoveMissingKeys(KeyObj* apKeyObj, FUN_00ee90f0_cls* apEntryList)
{
    unsigned char flags[0x400];
    unsigned int count = apEntryList->m_uiItemCount;
    FUN_00ec61c0(flags, 0, 0x400);

    for (unsigned int i = 0; i < apKeyObj->CountKeys(); ++i)
    {
        const char* key = apKeyObj->GetKey(i);
        for (unsigned int uiEntryIndex = 0; uiEntryIndex < count; ++uiEntryIndex)
        {
            KeyEntry* e = apEntryList->m_ppEntries[uiEntryIndex];
            if (e && e->CompareKey(key))
            {
                flags[uiEntryIndex] = 1;
                break;
            }
        }
    }

    int iEntryIndex = (int)count - 1;
    if (iEntryIndex >= 0)
    {
        do
        {
            if (flags[iEntryIndex] == 0)
            {
                apEntryList->RemoveAt(iEntryIndex);
            }
        } while (--iEntryIndex >= 0);
    }
    return true;
}

// 0x00ee8a70  unit_e3a382715159.cpp  /MT /O2 /GS /EHsc /Gy
// target: 8D 41 28 C3   lea eax,[ecx+0x28] ; ret   (4 bytes, thiscall getter)
struct C00ee8a70
{
    char pad00[0x28];
    int field28;
    int* FUN_00ee8a70();
};

// @fnv 0x00ee8a70
int* C00ee8a70::FUN_00ee8a70()
{
    return &field28;
}

struct FnvCpu_FUN_00ee8a80_CpuObject
{
    char* FUN_00ee8a80();
};
// @fnv 0x00ee8a80
char* FnvCpu_FUN_00ee8a80_CpuObject::FUN_00ee8a80()
{
    return reinterpret_cast<char*>(this) + 36;
}

struct FnvCpu_FUN_00ee8a90_CpuObject
{
    char* FUN_00ee8a90();
};
// @fnv 0x00ee8a90
char* FnvCpu_FUN_00ee8a90_CpuObject::FUN_00ee8a90()
{
    return reinterpret_cast<char*>(this) + 28;
}

struct FUN_00ee8aa0_shell
{
    char __thiscall FUN_00ee8aa0();
};
// @fnv 0x00ee8aa0
char __thiscall FUN_00ee8aa0_shell::FUN_00ee8aa0()
{
    return *(unsigned char*)((char*)this + 0x39);
}

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };

    virtual ~NiFile();
    virtual bool IsGood();

    static NiFile* GetFile(const char* pcName, OpenMode eMode, unsigned int uiBufferSize);
};

bool FUN_00aa1a30(const char* pcName, int iMode);

class FixedStr
{
  public:
    operator const char*() const
    {
        return m_kHandle;
    }
    char* m_kHandle;
};

class NiFileLoaderW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void Vf30();
    virtual void Vf34();
    virtual void Vf38();
    virtual void Vf3c();
    virtual void Vf40();
    virtual void Vf44();
    virtual void Vf48();
    virtual void Vf4c();
    virtual void Vf50();
    virtual void Vf54();
    virtual void Vf58();
    virtual void Vf5c();
    virtual void Vf60();
    virtual void Vf64();
    virtual void Vf68();
    virtual bool CanCreateDirectory();
    virtual void Vf70();
    virtual void Vf74();
    virtual void Vf78();
    virtual void Vf7c();
    virtual void Vf80();
    virtual void Vf84();
    virtual bool LoadFromFile(NiFile* pkFile, void* pvArg, void* pvArgCur);

    bool FUN_00ee8d60(void* pvArg, void* pvArgCur);
    bool CanOpen()
    {
        if (m_pcFileName.m_kHandle == DAT_0109b220)
            return false;
        if (FUN_00aa1a30(m_pcFileName, 0))
            return true;
        if (FUN_00aa1a30(m_pcFileName, 1) && CanCreateDirectory())
            return true;
        return false;
    }

    char m_pad04[0x1c];
    FixedStr m_pcFileName;
};

// @fnv 0x00ee8d60
bool NiFileLoaderW::FUN_00ee8d60(void* pvArg, void* pvArgCur)
{
    if (!CanOpen())
        return false;

    NiFile* pkFile = NiFile::GetFile(m_pcFileName, NiFile::APPEND_ONLY, 0x8000);
    if (!pkFile)
        return false;
    if (pkFile->IsGood() == true)
    {
        bool bResult = LoadFromFile(pkFile, pvArg, pvArgCur);
        delete pkFile;
        return bResult;
    }
    delete pkFile;
    return false;
}

struct FnvCpu_FUN_00ee8ab0_CpuObject
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned char unk0038;
    unsigned char unk0039;
    unsigned char value;
    unsigned char FUN_00ee8ab0();
};
// @fnv 0x00ee8ab0
unsigned char FnvCpu_FUN_00ee8ab0_CpuObject::FUN_00ee8ab0()
{
    return value;
}

#include <windows.h>
struct RefObject
{
    virtual void V0();
    virtual void Destroy();
    volatile LONG refs;
};
struct Node
{
    Node* next;
    unsigned int key;
    RefObject* value;
};
struct Map
{
    int unk00;
    unsigned int bucketCount;
    Node** buckets;
    bool Lookup(unsigned int*, RefObject**);
};
// Finds the value for key, updates the reference in out with reference-count adjustments, and returns whether the key was found.
// @fnv 0x00ee8e90
bool Map::Lookup(unsigned int* key, RefObject** ppOut)
{
    unsigned int value = *key;
    Node* node = buckets[value % bucketCount];
    while (node && value != node->key)
        node = node->next;
    if (!node)
        return false;
    RefObject* oldValue = *ppOut;
    if (oldValue != node->value)
    {
        if (oldValue && InterlockedDecrement(&oldValue->refs) == 0)
            oldValue->Destroy();
        RefObject* newValue = node->value;
        *ppOut = newValue;
        if (newValue)
            InterlockedIncrement(&newValue->refs);
    }
    return true;
}

struct S_00ee9230_Stream
{
    int unk0;
    unsigned int m_uiPos;
    int unk8;
    unsigned int(__cdecl* m_pfnWrite)(S_00ee9230_Stream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);
};

inline void S_00ee9230_WriteBinary(S_00ee9230_Stream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                   unsigned int uiComponentSize)
{
    pkStream->m_uiPos += pkStream->m_pfnWrite(pkStream, pvBuffer, uiBytes, &uiComponentSize, 1);
}

// Writes a length-prefixed null-terminated string to pkStream, using a zero length when pcString is null.
// @fnv 0x00ee9230
bool __stdcall FUN_00ee9230(S_00ee9230_Stream* pkStream, const char* pcString)
{
    if (pcString == 0)
    {
        int iLength = 0;
        S_00ee9230_WriteBinary(pkStream, &iLength, sizeof(iLength), sizeof(iLength));
    }
    else
    {
        int iLength = (int)strlen(pcString) + 1;
        S_00ee9230_WriteBinary(pkStream, &iLength, sizeof(iLength), sizeof(iLength));
        S_00ee9230_WriteBinary(pkStream, pcString, iLength, 1);
    }
    return true;
}

class NiFileE93
{
  public:
    virtual ~NiFileE93();
    virtual bool IsGood();
    virtual void vf08();
    virtual unsigned int GetPosition();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual unsigned int GetFileSize();
};

extern bool DAT_011c2fdd;
bool __cdecl FUN_00aa1ab0(const char* pcName);
bool __cdecl FUN_00aa1bb0(const char* pcName);
NiFileE93* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
void __cdecl AdvancePosition(NiFileE93* pkFile, char* pcBuffer, unsigned int uiLen);
int __cdecl FUN_00aa1360(const char* pc1, const char* pc2);
void __cdecl InvokeAndAccumulate(NiFileE93* pkFile, bool* pbValue);
void __cdecl FUN_00a575b0(NiFileE93* pkFile, unsigned int* puiValue);

class NiFixedStringE93
{
  public:
    operator const char*() const
    {
        return m_kHandle;
    }
    const char* m_kHandle;
};

class NiGPUProgramCacheE93 : public FixedStringMap
{
  public:
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual const NiFixedStringE93& GetPlatformName();
    virtual void vf58();
    virtual void vf5c();
    virtual const char* GetRendererName();
    virtual const char* GetShaderType();
    virtual void vf68();
    virtual void Clear();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual bool FiveIntegerLoadRecord(NiFileE93* pkFile, bool* pbUpdated);

    bool FUN_00ee92d0(NiFileE93* pkFile, char* pcBuffer, unsigned int uiBufferSize);
    bool LoadCacheFile();

    void* m_pkEntryMap;
    unsigned int m_uiStreamIndex;
    unsigned int m_uiEntryMax;
    unsigned int m_uiGrowBy;
    NiFixedStringE93 m_pcWorkingDir;
    NiFixedStringE93 m_pcCacheFileName;
    unsigned int m_uiMaxSize;
    unsigned int m_uiNextBlockSize;
    unsigned int m_uiValue1;
    unsigned int m_uiBufferSize;
    unsigned int m_uiReserved;
    bool m_bAutoWrite;
    bool m_bLoadComplete;
};

// Loads the GPU program cache file, validates header, version, and identifiers, then reads all records and marks loading complete.
// @fnv 0x00ee9350
bool NiGPUProgramCacheE93::LoadCacheFile()
{
    bool bExists = m_pcWorkingDir != DAT_0109b220 && (FUN_00aa1ab0(m_pcWorkingDir) || FUN_00aa1bb0(m_pcWorkingDir));
    if (!bExists)
        return false;

    if (m_bLoadComplete)
        return true;

    char acBuffer[0x200];
    NiFileE93* pkFile = FUN_00aa1a20(m_pcCacheFileName, 0, 0x8000);
    if (pkFile)
    {
        if (pkFile->IsGood() == true)
        {
            const char* pcHeader = "NiGPUProgram Cache File";
            AdvancePosition(pkFile, acBuffer, strlen(pcHeader) + 1);
            if (FUN_00aa1360(acBuffer, pcHeader) != 0)
            {
                delete pkFile;
                return false;
            }

            bool bLittleEndian;
            InvokeAndAccumulate(pkFile, &bLittleEndian);
            unsigned int uiVersion;
            FUN_00a575b0(pkFile, &uiVersion);
            if (uiVersion < 5)
            {
                delete pkFile;
                if (DAT_011c2fdd)
                    Clear();
                return false;
            }

            FUN_00ee92d0(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetShaderType()) != 0)
            {
                delete pkFile;
                return false;
            }
            FUN_00ee92d0(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetRendererName()) != 0)
            {
                delete pkFile;
                return false;
            }
            FUN_00ee92d0(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetPlatformName()) != 0)
            {
                delete pkFile;
                return false;
            }

            bool bUpdated = false;
            while (pkFile->GetPosition() < pkFile->GetFileSize())
            {
                bool bEntryUpdated = false;
                if (!FiveIntegerLoadRecord(pkFile, &bEntryUpdated))
                {
                    delete pkFile;
                    return false;
                }
                if (bEntryUpdated)
                    bUpdated = true;
            }

            delete pkFile;
            m_bLoadComplete = true;
            if (bUpdated && DAT_011c2fdd)
                Clear();
            return true;
        }
        delete pkFile;
    }
    return false;
}

extern "C" size_t strlen(const char*);
extern char* _EmptyFS;
bool __cdecl FUN_00aa1bb0(const char* h);
void __cdecl FUN_00e984d0(void* s, const char* name, unsigned int len);

struct StreamObj : public NiFile
{
    unsigned int m_pos;
    unsigned int unk08;
    unsigned int(__cdecl* m_fn)(StreamObj*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* pSize, unsigned int c)
    {
        unsigned int r = m_fn(this, (void*)p, n, pSize, c);
        m_pos += r;
        return r;
    }
};
template <class T> inline void S00ee9620_Save(StreamObj& s, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    s.BinaryWrite(p, n * sizeof(T), &uiSize, 1);
}
template <class T> inline void S00ee9620_SaveBinary(StreamObj* s, const T& v)
{
    S00ee9620_Save(*s, &v, 1);
}

struct OwnerMap : public FixedStringMap
{
    MapItem* FUN_00ee8ac0();
    void GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val);
};

__declspec(noinline) void OwnerMap::GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val)
{
    MapItem* item = pos;
    key = item->m_key;
    val = item->m_val;
    if (item->m_pkNext)
    {
        pos = item->m_pkNext;
        return;
    }
    unsigned int bucket = (unsigned int)item->m_key.m_kHandle % m_uiHashSize + 1;
    for (; bucket < m_uiHashSize; ++bucket)
    {
        if (m_ppkHashTable[bucket])
        {
            pos = m_ppkHashTable[bucket];
            return;
        }
    }
    pos = 0;
}

struct PathString
{
    char* handle;
    operator const char*() const
    {
        return handle;
    }
    bool Exists() const
    {
        return handle != _EmptyFS;
    }
};

class GpuCacheWriter
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual unsigned int* v15();
    virtual void v16();
    virtual void v17();
    virtual unsigned int v18();
    virtual unsigned int v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22(StreamObj* s, NiRefObject* val, NiFixedString* key);
    unsigned int unk04;
    OwnerMap m_map;
    unsigned int unk14;
    unsigned int unk18;
    PathString m_1c;
    PathString m_20;

    void FUN_00ee9230(StreamObj* s, unsigned int v);
    __forceinline bool CanSave()
    {
        return m_1c.Exists() && (((bool(__cdecl*)(const char*))FUN_00aa1ab0)(m_1c) || FUN_00aa1bb0(m_1c));
    }
    bool FUN_00ee9620();
};

// Writes the GPU cache file header and all map entries to a stream opened from m_20, returning true on success.
// @fnv 0x00ee9620
bool GpuCacheWriter::FUN_00ee9620()
{
    if (!CanSave())
        return false;
    const char* pcName = m_20;
    StreamObj* s = static_cast<StreamObj*>(NiFile::GetFile(pcName, NiFile::WRITE_ONLY, 0x8000));
    if (s && s->IsGood() == true)
    {
        const char* str = "NiGPUProgram Cache File";
        FUN_00e984d0(s, str, strlen(str) + 1);

        unsigned char bLittleEndian = 1;
        S00ee9620_SaveBinary(s, bLittleEndian);
        unsigned int version = 5;
        S00ee9620_SaveBinary(s, version);

        FUN_00ee9230(s, v19());
        FUN_00ee9230(s, v18());
        FUN_00ee9230(s, *v15());

        MapItem* pItem = m_map.FUN_00ee8ac0();
        while (pItem != 0)
        {
            NiObjPtr val;
            NiFixedString key;
            key.m_kHandle = _EmptyFS;
            val.m_pObject = 0;
            m_map.GetNextEntry(pItem, key, val);
            NiRefObject* object = val.m_pObject;
            v22(s, object, &key);
            if (key.m_kHandle != _EmptyFS)
            {
                InterlockedDecrement((long*)(key.m_kHandle - 8));
            }
            if (object != 0)
            {
                object->DecRefCount();
            }
        }
        delete s;
        return true;
    }
    return false;
}

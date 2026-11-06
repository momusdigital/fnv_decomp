// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern void* DAT_11ac230;
void __cdecl FUN_00aa1ab0();
struct S_00a8d8b0
{
    int _0;
    int pos;
    unsigned int(__cdecl* fn)(S_00a8d8b0*, void*, unsigned int, unsigned int*, unsigned int);
};
void __cdecl AdvancePosition(S_00a8d8b0* apState, void* b, unsigned int c);
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
void __cdecl FUN_00ee9a60();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00ee9ca0_shell
{
    void* __thiscall FUN_00ee9ca0(unsigned int flags);
};
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
class FUN_00ee8fe0_cls
{
  public:
    NiRefObject** m_ppkTable;
    unsigned int unk04;
    unsigned int m_uiSize;

    void RemoveAt(unsigned int idx);
};
extern void* DAT_11ac230;
void __cdecl FUN_00aa1ab0();
void __cdecl AdvancePosition(S_00a8d8b0* a, void* b, unsigned int c);
bool __stdcall FUN_00ee92d0(S_00a8d8b0* self, unsigned int pBuffer, unsigned int a3);
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
    int FUN_00eea530();
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
    void WriteLengthPrefixedString(S_00ee97e0_Stream* s, int v);
};
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
RecordPair* __cdecl CreateRecordPair();
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
void __stdcall ClearAndDeleteItem(ItemWithDtor* pItem);
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
bool __stdcall RemoveMissingKeys(KeyObj* apKeyObj, FUN_00ee90f0_cls* apEntryList);
// 0x00ee8a70  unit_e3a382715159.cpp  /MT /O2 /GS /EHsc /Gy
// target: 8D 41 28 C3   lea eax,[ecx+0x28] ; ret   (4 bytes, thiscall getter)
struct C00ee8a70
{
    char pad00[0x28];
    int field28;
    int* FUN_00ee8a70();
};
struct FnvCpu_FUN_00ee8a80_CpuObject
{
    char* FUN_00ee8a80();
};
struct FnvCpu_FUN_00ee8a90_CpuObject
{
    char* FUN_00ee8a90();
};
struct FUN_00ee8aa0_shell
{
    char __thiscall FUN_00ee8aa0();
};
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
bool __stdcall WriteLengthPrefixedString(S_00ee9230_Stream* pkStream, const char* pcString);
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

    void WriteLengthPrefixedString(StreamObj* s, unsigned int v);
    __forceinline bool CanSave()
    {
        return m_1c.Exists() && (((bool(__cdecl*)(const char*))FUN_00aa1ab0)(m_1c) || FUN_00aa1bb0(m_1c));
    }
    bool FUN_00ee9620();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* s);
};
extern char* _EmptyFS;

struct CacheRefVTable
{
    void(__thiscall* Destroy)(void*);
    void(__thiscall* DeleteThis)(void*);
};
extern const CacheRefVTable DAT_0101dce4;
extern const CacheRefVTable DAT_010f0134;

class RefObjBase
{
  public:
    static void* operator new(unsigned int);
    RefObjBase() throw() : m_vtbl(&DAT_0101dce4), m_uiRefCount(0)
    {
        InterlockedIncrement(&DAT_011f4400);
    }
    void DeleteThis()
    {
        m_vtbl->DeleteThis(this);
    }
    const CacheRefVTable* m_vtbl;
    long m_uiRefCount;
};

struct ShaderPtr
{
    void* m_p;
    ShaderPtr& operator=(void* p);
};

struct ShaderEntry : RefObjBase
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    ShaderEntry() throw();
    void SetName(const FixedStr& s);
    void FUN_00eea650(const FixedStr& s);
    void FUN_00eea690(const FixedStr& s);
    void SetLookAtTargetName(const FixedStr& s);
    void AssignRefCounted(const FixedStr& s);
    void FUN_00eea540(unsigned int v);
    void FUN_00eea550(unsigned int v);
    void FUN_00eea560(unsigned int v);
    void FUN_00eea570(unsigned int v);
};

struct EntrySet
{
    ShaderEntry** m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void Add(ShaderEntry* const& p);
};

struct ShaderGroup : RefObjBase
{
    ShaderPtr m_pGeometryShader;
    EntrySet m_kEntries;
    ShaderGroup() throw()
    {
        m_vtbl = &DAT_010f0134;
        m_pGeometryShader.m_p = 0;
        m_kEntries.m_pBase = 0;
        m_kEntries.m_uiElementCount = 0;
        m_kEntries.m_uiAllocatedCapacity = 0;
    }
};

struct GroupPtrArg
{
    ShaderGroup* m_p;
    GroupPtrArg(ShaderGroup* p) : m_p(p)
    {
        if (m_p)
            InterlockedIncrement(&m_p->m_uiRefCount);
    }
    GroupPtrArg(const GroupPtrArg& o) : m_p(o.m_p)
    {
        if (m_p)
            InterlockedIncrement(&m_p->m_uiRefCount);
    }
};

struct GroupMap
{
    bool GetAt(const FixedStr& key, ShaderGroup*& val);
    void SetAt(const FixedStr& key, GroupPtrArg val);
};

static inline unsigned int ReadRaw(S_00a8d8b0* s, void* dst, unsigned int total, unsigned int elem)
{
    unsigned int sz = elem;
    unsigned int result = s->fn(s, dst, total, &sz, 1);
    s->pos += result;
    return result;
}

static inline void ReleaseStr(FixedStr& s)
{
    if (s.m_kHandle != _EmptyFS)
        InterlockedDecrement((long*)(s.m_kHandle - 8));
}

static __forceinline void ReadStr0(S_00a8d8b0* s, char* buf)
{
    unsigned int len = 0;
    ReadRaw(s, &len, 4, 4);
    if (len == 0)
    {
        buf[0] = 0;
    }
    else
    {
        AdvancePosition(s, buf, len);
        buf[len + 1] = 0;
    }
}
static __forceinline void ReadStr(S_00a8d8b0* s, char* buf)
{
    unsigned int len = 0;
    ReadRaw(s, &len, 4, 4);
    if (len == 0)
    {
        buf[0] = 0;
    }
    else
    {
        ReadRaw(s, buf, len, 1);
        buf[len + 1] = 0;
    }
}

class ShaderLib
{
  public:
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual bool LoadShader(S_00a8d8b0* s, FixedStr& name, void*& out, bool skip);

    int unk04;
    GroupMap m_kObjectGroups;
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
    int m_iSlotCount;

    bool FUN_00ee9cc0(S_00a8d8b0* s, bool& changed);
};

// @fnv 0x00ee9cc0
bool ShaderLib::FUN_00ee9cc0(S_00a8d8b0* s, bool& changed)
{
    char buf[0x200];
    int version;
    ReadRaw(s, &version, 4, 4);
    ReadStr0(s, buf);
    FixedStr name;
    name.m_kHandle = NiGlobalStringTable::AddString(buf);
    bool skip = false;
    if (version != m_iSlotCount)
    {
        changed = true;
        skip = true;
    }
    GroupMap* map;
    {
        ShaderGroup* found = 0;
        map = &m_kObjectGroups;
        if (map->GetAt(name, found))
            skip = true;
        if (found)
        {
            if (InterlockedDecrement(&found->m_uiRefCount) == 0)
                found->DeleteThis();
        }
    }
    ShaderGroup* group = 0;
    if (!skip)
        group = new ShaderGroup;

    void* shader = 0;
    if (!LoadShader(s, name, shader, skip))
    {
        ReleaseStr(name);
        return false;
    }
    if (!skip)
        group->m_pGeometryShader = shader;

    unsigned int count = 0;
    ReadRaw(s, &count, 4, 4);
    for (unsigned int i = 0; i < count; i++)
    {
        if (!skip)
        {
            ShaderEntry* e = new ShaderEntry;
            ReadStr(s, buf);
            FixedStr t1;
            t1.m_kHandle = NiGlobalStringTable::AddString(buf);
            e->SetName(t1);
            ReleaseStr(t1);
            ReadStr(s, buf);
            FixedStr t2;
            t2.m_kHandle = NiGlobalStringTable::AddString(buf);
            e->FUN_00eea650(t2);
            ReleaseStr(t2);
            ReadStr(s, buf);
            FixedStr t3;
            t3.m_kHandle = NiGlobalStringTable::AddString(buf);
            e->FUN_00eea690(t3);
            ReleaseStr(t3);
            ReadStr(s, buf);
            FixedStr t4;
            t4.m_kHandle = NiGlobalStringTable::AddString(buf);
            e->SetLookAtTargetName(t4);
            ReleaseStr(t4);
            ReadStr(s, buf);
            FixedStr t5;
            t5.m_kHandle = NiGlobalStringTable::AddString(buf);
            e->AssignRefCounted(t5);
            ReleaseStr(t5);
            unsigned int v;
            ReadRaw(s, &v, 4, 4);
            e->FUN_00eea540(v);
            ReadRaw(s, &v, 4, 4);
            e->FUN_00eea550(v);
            ReadRaw(s, &v, 4, 4);
            e->FUN_00eea560(v);
            ReadRaw(s, &v, 4, 4);
            e->FUN_00eea570(v);
            {
                ShaderEntry* sp = e;
                if (e)
                    InterlockedIncrement(&e->m_uiRefCount);
                group->m_kEntries.Add(sp);
            }
            if (e)
            {
                if (InterlockedDecrement(&e->m_uiRefCount) == 0)
                    e->DeleteThis();
            }
        }
        else
        {
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            unsigned int v;
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
        }
    }
    if (!skip && group->m_pGeometryShader.m_p)
    {
        map->SetAt(name, group);
    }
    ReleaseStr(name);
    return true;
}

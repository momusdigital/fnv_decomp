// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderfactory.cpp: NiD3DShaderFactory, ShaderFactoryView, TMapHolder, FakeCls and more (46 functions)

#include "nid3dshaderfactory_decls.h"

const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";

// @fnv 0x00e94130
void NiD3DShaderFactory::ShutdownPoint3()
{
    m_ppVirtualMethodTable = 0;
    UpdateShaderMaterialCache(DAT_011f4a64);
    m_shutdown = true;
}

// Allocates a NiD3DShaderFactory, calls Create to store it in DAT_0126fa0c and DAT_011f6044, and reports failure if the factory is null.
// @fnv 0x00e92e60
void NiD3DShaderFactory::InitializePoint3()
{
    if (DAT_0126fa0c == 0)
    {
        NiD3DShaderFactory* factory = static_cast<NiD3DShaderFactory*>(NiMemObject::operator new(0x100));
        NiShaderFactory* result;
        if (factory)
            result = factory->Create();
        else
            result = 0;
        DAT_0126fa0c = result;
        DAT_011f6044 = result;
    }
    if (DAT_011f6044 == 0)
        NiD3DDefaultShader::SetShaderName(kFailedShaderFactoryMessage);
}

// Initializes the shader factory's vtable and state, allocates two string-map storages for shaders and libraries, and returns this.
// @fnv 0x00e92cf0
NiShaderFactory* NiD3DShaderFactory::Create()
{
    FUN_00aa0390();
    m_ppVirtualMethodTable = &kVtbl_NiD3DShaderFactory;
    m_pOwnerShader = 0;
    DAT_00fdf054(m_kShaderMap);

    NiStringMapStorage* shaderMap;
    NiStringMapStorage* shaderStorage =
        static_cast<NiStringMapStorage*>(g_memoryManager.Allocate(sizeof(NiStringMapStorage)));
    if (shaderStorage)
    {
        shaderStorage->m_ppVirtualMethodTable = &DAT_010f0bc0;
        shaderStorage->m_hashSize = 0x3b;
        shaderStorage->m_unused = 0;
        shaderStorage->m_hashTable = NiMalloc(0xec);
        fnv_zlib_memset(shaderStorage->m_hashTable, 0, shaderStorage->m_hashSize * 4);
        shaderStorage->m_sState = true;
        shaderStorage->m_ppVirtualMethodTable = &DAT_010f0c80;
        shaderMap = shaderStorage;
    }
    else
        shaderMap = 0;
    m_pShaderMapStorage = shaderMap;

    NiStringMapStorage* libraryStorage =
        static_cast<NiStringMapStorage*>(g_memoryManager.Allocate(sizeof(NiStringMapStorage)));
    if (libraryStorage)
    {
        libraryStorage->m_ppVirtualMethodTable = &DAT_010f0c20;
        libraryStorage->m_hashSize = 0x25;
        libraryStorage->m_unused = 0;
        libraryStorage->m_hashTable = NiMalloc(0x94);
        fnv_zlib_memset(libraryStorage->m_hashTable, 0, libraryStorage->m_hashSize * 4);
        libraryStorage->m_sState = false;
        libraryStorage->m_ppVirtualMethodTable = &DAT_010f0ca0;
        m_pShaderLibraryStorage = libraryStorage;
        return this;
    }
    m_pShaderLibraryStorage = 0;
    return this;
}

struct FUN_00e91f40_shell : public NiD3DShaderFactory
{
    char* FUN_00e91f40(void**);
};

class NiD3DShaderProgramFactory
{
  public:
    const char* GetNextName(void*&);
};

NiD3DShaderProgramFactory* __cdecl FUN_00e92eb0();

// @fnv 0x00e91f40
char* FUN_00e91f40_shell::FUN_00e91f40(void** kIter)
{
    NiD3DShaderProgramFactory* pkSPFactory = FUN_00e92eb0();
    if (!pkSPFactory)
        return 0;
    return (char*)pkSPFactory->GetNextName(*kIter);
}

namespace fnv_00e91fa0 {
struct FUN_00e91fa0_shell : public NiD3DShaderFactory
{
    void FUN_00e91fa0();
};

void* __cdecl FUN_00e92eb0();
void __fastcall FUN_00e93cc0(void* pThis);

// @fnv 0x00e91fa0
void FUN_00e91fa0_shell::FUN_00e91fa0()
{
    void* pkFactory = FUN_00e92eb0();
    if (pkFactory)
        FUN_00e93cc0(pkFactory);
}
}  // namespace fnv_00e91fa0

struct NiConsoleRendererStub
{
    void UnloadAllShaders();
};
struct FUN_00e91ea0_cls
{
    char pad[0x24];
    NiConsoleRendererStub* renderer;
};
// @fnv 0x00e91ea0
void __fastcall FUN_00e91ea0(FUN_00e91ea0_cls* self, int)
{
    if (self->renderer)
        self->renderer->UnloadAllShaders();
}

// @fnv 0x00e91eb0
unsigned int __stdcall FUN_00e91eb0(unsigned int uiVersion)
{
    return uiVersion & 0xFF;
}

// @fnv 0x00e91ec0
unsigned int __stdcall MakeVersionCode(unsigned int uiMajor, unsigned int uiMinor)
{
    return ((0xFFFFFF00 | uiMajor) << 8) | uiMinor;
}

// @fnv 0x00e91ee0
unsigned int __stdcall FUN_00e91ee0(unsigned int uiVersion)
{
    return (uiVersion >> 8) & 0xFF;
}

// @fnv 0x00e91ef0
unsigned int __stdcall FUN_00e91ef0(unsigned int a, unsigned int b)
{
    return ((0xFFFFFE00 | a) << 8) | b;
}

// @fnv 0x00e91f10
void* __cdecl FUN_00e91f10()
{
    return DAT_0126fa0c;
}

namespace fnv_00e91f20 {
struct FUN_00e91f20_shell : public NiD3DShaderFactory
{
    char* FUN_00e91f20(void**);
};

struct NiD3DShaderProgramFactory
{
    char* FUN_00e92fe0(void**);
};

extern NiD3DShaderProgramFactory* __cdecl FUN_00e92eb0(void);

// @fnv 0x00e91f20
char* FUN_00e91f20_shell::FUN_00e91f20(void** kIter)
{
    NiD3DShaderProgramFactory* pkSPFactory = FUN_00e92eb0();
    if (!pkSPFactory)
        return 0;
    return pkSPFactory->FUN_00e92fe0(kIter);
}
}  // namespace fnv_00e91f20

namespace fnv_00e91f60 {
struct NiD3DShaderProgramFactory
{
    void __thiscall AddDirectory(const char* pacDirectory);
};
NiD3DShaderProgramFactory* __cdecl FUN_00e92eb0(void);

// @fnv 0x00e91f60
void __stdcall FUN_00e91f60(const char* pacDirectory)
{
    NiD3DShaderProgramFactory* pkFactory = FUN_00e92eb0();
    if (pkFactory)
        pkFactory->AddDirectory(pacDirectory);
}
}  // namespace fnv_00e91f60

namespace fnv_00e91f80 {
struct NiD3DShaderProgramFactory
{
    void __thiscall LoadProgramByName(const char*);
};

NiD3DShaderProgramFactory* __cdecl FUN_00e92eb0();

// @fnv 0x00e91f80
void __stdcall FUN_00e91f80(char* pacDirectory)
{
    NiD3DShaderProgramFactory* pkFactory = FUN_00e92eb0();
    if (pkFactory)
        pkFactory->LoadProgramByName(pacDirectory);
}
}  // namespace fnv_00e91f80

// @fnv 0x00e91fc0
const char* __cdecl FUN_00e91fc0()
{
    return "DX9";
}

extern char $SG6379[];
extern int __cdecl NiSprintf(char*, unsigned int, char const*, ...);
extern int _ref_00ec408c;

struct NiTMapBase
{
    bool __thiscall RemoveAt(char const*);
};

struct NiD3DShaderFactory_shell
{
    NiTMapBase* m_pShaderMapStorage;
    void __thiscall FUN_00e923f0(const char* pcName, unsigned int uiImplementation);
};

// Builds a name from pcName and uiImplementation and removes the matching entry from the map at offset 0x28 if present.
// @fnv 0x00e923f0
void __thiscall NiD3DShaderFactory_shell::FUN_00e923f0(const char* pcName, unsigned int uiImplementation)
{
    char acFullName[260];
    if (*(NiTMapBase**)((char*)this + 0x28))
    {
        NiSprintf(acFullName, sizeof(acFullName), "%s%d", pcName, uiImplementation);
        (*(NiTMapBase**)((char*)this + 0x28))->RemoveAt(acFullName);
    }
}

struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00e92460_cls
{
    char pad[0x28];
    NiTMapBaseStub* map;
};
// @fnv 0x00e92460
void __fastcall FUN_00e92460(FUN_00e92460_cls* self, int)
{
    if (self->map)
        self->map->RemoveAll();
}

// @fnv 0x00e92590
unsigned int __stdcall FUN_00e92590(unsigned int auiLeft, unsigned int auiRight)
{
    return auiLeft == auiRight;
}

struct Obj_00e92690
{
    void Destroy();
};
// @fnv 0x00e92690
Obj_00e92690* __fastcall FUN_00e92690(Obj_00e92690* self, int, unsigned int flags)
{
    self->Destroy();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

struct Obj_00e92cd0
{
    void FUN_00e925a0();
};
// Calls the object's cleanup method, frees it via g_memoryManager when flags has bit 0 set, and returns the object pointer.
// @fnv 0x00e92cd0
Obj_00e92cd0* __fastcall FUN_00e92cd0(Obj_00e92cd0* self, int, unsigned int flags)
{
    self->FUN_00e925a0();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

namespace fnv_00e92520 {
void __cdecl NiFreeAlias(void*);

struct NiTMapBaseStub
{
    void RemoveAll();
};

extern void* DAT_010f0bc0;
extern void* DAT_010f0be0;
extern void* DAT_010f0c00;

struct FUN_00e92520_shell
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void** m_items;
    void Destroy();
};

// @fnv 0x00e92520
void FUN_00e92520_shell::Destroy()
{
    m_vtbl = &DAT_010f0c00;
    if (*(char*)(((char*)this) + 0x10))
    {
        for (unsigned int i = 0; i < m_uiItemCount; ++i)
        {
            void* item = m_items[i];
            while (item)
            {
                void* node = item;
                item = *(void**)node;
                NiFreeAlias(*(void**)((char*)node + 4));
            }
        }
    }
    m_vtbl = &DAT_010f0be0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    m_vtbl = &DAT_010f0bc0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    NiFreeAlias(m_items);
}
}  // namespace fnv_00e92520

namespace fnv_00e92610 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
void __cdecl _NiFreeAlias(void*);
struct TMapHolder
{
    void* f0;
    int f4;
    void* f8;
    void* DestroyTMapHolder(unsigned int);
};
// Resets f0 to DAT_010f0bc0, calls RemoveAll, frees f8, and deallocates this when flags has bit 0 set; returns this.
// @fnv 0x00e92610
void* TMapHolder::DestroyTMapHolder(unsigned int flags)
{
    f0 = (void*)&DAT_010f0bc0;
    ((NiTMapBaseStub*)(void*)this)->RemoveAll();
    _NiFreeAlias(f8);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00e92610

namespace fnv_00e92650 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern void* DAT_010f0be0;
void __cdecl _NiFreeAlias(void*);
struct FUN_00e92650_Holder
{
    void* unk0;
    unsigned int unk4;
    void* unk8;
    void* DestroyHolder(unsigned int);
};
// Resets two embedded map bases, frees unk8, and optionally deallocates the object when flags bit 0 is set.
// @fnv 0x00e92650
void* FUN_00e92650_Holder::DestroyHolder(unsigned int flags)
{
    unk0 = &DAT_010f0be0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    unk0 = &DAT_010f0bc0;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(unk8);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00e92650

namespace fnv_00e926b0 {
extern void* DAT_010f0c20;
void NiFreeAlias(void* p);
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00e926b0_shell : NiTMapBaseStub
{
    void* vftable;
    void* a;
    void* field;
    void* FUN_00e926b0(bool flag);
};
// Resets the vftable, removes all entries, frees the field pointer, and optionally deallocates this object.
// @fnv 0x00e926b0
void* FUN_00e926b0_shell::FUN_00e926b0(bool abFree)
{
    vftable = &DAT_010f0c20;
    RemoveAll();
    NiFreeAlias(field);
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00e926b0

namespace fnv_00e926f0 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern int DAT_010f0c40;
void __cdecl _NiFreeAlias(void*);
struct FakeCls
{
    void* vf;
    int f04;
    void* f08;
    void* FUN_00e926f0(unsigned int);
};
// Resets two map bases via RemoveAll, frees f08, and deallocates this when a1 has bit 0 set, returning this.
// @fnv 0x00e926f0
void* FakeCls::FUN_00e926f0(unsigned int auiFlags)
{
    vf = (void*)&DAT_010f0c40;
    ((NiTMapBaseStub*)this)->RemoveAll();
    vf = (void*)&DAT_010f0c20;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(f08);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00e926f0

class NiRTTI;
class NiShader
{
  public:
    class NiShader* DynamicCast(class NiRTTI const*);
};
extern char const* const g_0126f754_arg1;
class NiD3DShaderInterface
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual bool IsDefault();
};
// Casts pkShader to NiD3DShaderInterface and returns whether it is the default shader, or false if the cast fails.
// @fnv 0x00e92730
bool __stdcall IsDefaultShader(class NiShader* pkShader)
{
    if (pkShader)
    {
        NiD3DShaderInterface* pkShaderIf =
            (NiD3DShaderInterface*)pkShader->DynamicCast((NiRTTI const*)&g_0126f754_arg1);
        if (pkShaderIf)
            return pkShaderIf->IsDefault();
    }
    return false;
}

void __cdecl operator delete(void* p, unsigned int);

void __cdecl FUN_00e92dc0();

struct FUN_00e92e30_shell : public NiD3DShaderFactory
{
    void* __thiscall DestroyShaderFactory(unsigned int flags);
};

// Calls FUN_00e92dc0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e92e30
void* __thiscall FUN_00e92e30_shell::DestroyShaderFactory(unsigned int flags)
{
    FUN_00e92dc0();
    if (flags & 1)
        operator delete(this, 0x100);
    return this;
}

struct GraphicsRenderer;
struct FUN_00e91e60_shell : public NiD3DShaderFactory
{
    void FUN_00e91e60(GraphicsRenderer*);
};

struct ShaderConstantInterface
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void SetShaderRenderer(GraphicsRenderer*);
};
struct FakeFactory374
{
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
    virtual void* vf4();
    virtual void* vf5();
    virtual void* vf6();
    virtual void* vf7();
    virtual void* vf8();
    virtual void* vf9();
    virtual void* vf10();
    virtual void* vf11();
    virtual void* vf12();
    virtual void* vf13();
    virtual ShaderConstantInterface* GetVertexShaderConstantInterface();
    virtual ShaderConstantInterface* GetPixelShaderConstantInterface();
};
// @fnv 0x00e91e60
void FUN_00e91e60_shell::FUN_00e91e60(GraphicsRenderer* pkRenderer)
{
    ShaderConstantInterface* pkLibrary;
    if (*(GraphicsRenderer**)((char*)this + 0x24) != pkRenderer)
    {
        *(GraphicsRenderer**)((char*)this + 0x24) = pkRenderer;
        pkLibrary = ((FakeFactory374*)this)->GetVertexShaderConstantInterface();
        if (pkLibrary)
        {
            do
            {
                pkLibrary->SetShaderRenderer(pkRenderer);
                pkLibrary = ((FakeFactory374*)this)->GetPixelShaderConstantInterface();
            } while (pkLibrary);
        }
    }
}

namespace fnv_00e921d0 {
int __cdecl NiSprintf(char* buf, int size, const char* fmt, ...);
struct NiShader
{
    int m_iRefCount;
};
struct NiTStringPointerMap_00e93020
{
    bool GetAt(const char* key, NiShader** out);
};
struct FUN_00e921d0_shell
{
    char* m_pShaderMapStorage;
    NiShader* GetShaderByNameAndImplementation(const char* pcName, unsigned int uiImplementation);
};
// Builds a name from pcName and uiImplementation, looks it up in the shader map at this+0x28, and returns the found NiShader or null.
// @fnv 0x00e921d0
NiShader* FUN_00e921d0_shell::GetShaderByNameAndImplementation(const char* pcName, unsigned int uiImplementation)
{
    if (!*(NiTStringPointerMap_00e93020**)((char*)this + 0x28))
        return 0;
    NiShader* pkShader = 0;
    char acFullName[260];
    NiSprintf(acFullName, 260, "%s%d", pcName, uiImplementation);
    return (*(NiTStringPointerMap_00e93020**)((char*)this + 0x28))->GetAt(acFullName, &pkShader) ? pkShader : 0;
}
}  // namespace fnv_00e921d0

namespace fnv_00e929c0 {
// Stand-ins for types not declared in this unit
struct NiFixedString
{
    const char* m_pcString;  // +0x00
};

struct NiShader
{
    NiFixedString const& GetFilename() const;
};

struct NiTStringTemplateMap
{
    void SetAt(char const*, NiShader*);
};

int NiSprintf(char*, int, const char*, ...);

extern const char $SG6456[];
extern unsigned int _data_011c16bc;
void _ref_00ec408c(unsigned int);

struct FUN_00e929c0_shell
{
    void RegisterShaderImplementation(NiShader* pkShader, unsigned int uiImplementation);
};

// Builds a name from the shader filename and implementation index, then stores the shader in the map at this+0x28 if both exist.
// @fnv 0x00e929c0
void FUN_00e929c0_shell::RegisterShaderImplementation(NiShader* pkShader, unsigned int uiImplementation)
{
    char acFullName[260];

    if (pkShader)
    {
        NiSprintf(acFullName, 260, $SG6456, pkShader->GetFilename().m_pcString, uiImplementation);

        NiTStringTemplateMap* pkMap = *(NiTStringTemplateMap**)((char*)this + 0x28);
        if (pkMap)
            pkMap->SetAt(acFullName, pkShader);
    }
}
}  // namespace fnv_00e929c0

struct Ent00b57f20
{
    void* m_p0;
    int m_04;
    int m_08;
};
struct Tbl00b57f20
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void** m_aiIndexedValues;
    void AdvanceToNextEntry(Ent00b57f20** pp, int* o1, int* o2);
};
typedef unsigned int(__thiscall* VF00b57f20)(void*, int);
// @fnv 0x00b57f20
void Tbl00b57f20::AdvanceToNextEntry(Ent00b57f20** ppEntry, int* piFirst, int* piSecond)
{
    Ent00b57f20* a = *ppEntry;
    *piFirst = a->m_04;
    *piSecond = a->m_08;
    void* pNext = a->m_p0;
    if (pNext)
    {
        *ppEntry = (Ent00b57f20*)pNext;
        return;
    }
    void** pVtbl = *(void***)this;
    unsigned int i = ((VF00b57f20)(pVtbl[1]))(this, a->m_04);
    i = i + 1;
    while (i < m_uiItemCount)
    {
        void* p = m_aiIndexedValues[i];
        if (p)
        {
            *ppEntry = (Ent00b57f20*)p;
            return;
        }
        i++;
    }
    *ppEntry = 0;
}

struct MapValueObject
{
    virtual void vf0();
    virtual void vf1();
    volatile long m_iObjectReferenceCount;
};

struct MapItemNode
{
    MapItemNode* m_pkNext;
    unsigned int m_key;
    MapValueObject* m_val;
};

struct FUN_00e6e630_cls
{
    virtual void vf0();
    virtual unsigned int HashKey(unsigned int key);
    unsigned int m_uiHashSize;
    MapItemNode** m_ppkHashTable;
    void AdvanceIterator(MapItemNode** pos, unsigned int* key, MapValueObject** val);
};

// Advances the hash-map iterator to the next node, copying its key and ref-counting the value, or clears the iterator when no further node exists.
// @fnv 0x00e6e630
void FUN_00e6e630_cls::AdvanceIterator(MapItemNode** apIter, unsigned int* key, MapValueObject** val)
{
    MapItemNode* pNode = *apIter;
    *key = pNode->m_key;
    MapValueObject* pOldValue = *val;
    if (pOldValue != pNode->m_val)
    {
        if (pOldValue != 0)
        {
            if (InterlockedDecrement(&pOldValue->m_iObjectReferenceCount) == 0)
            {
                pOldValue->vf1();
            }
        }
        *val = pNode->m_val;
        if (*val != 0)
        {
            InterlockedIncrement(&(*val)->m_iObjectReferenceCount);
        }
    }
    if (pNode->m_pkNext != 0)
    {
        *apIter = pNode->m_pkNext;
        return;
    }
    unsigned int uiIndex = HashKey(pNode->m_key) + 1;
    if (uiIndex >= m_uiHashSize)
    {
        *apIter = 0;
        return;
    }
    MapItemNode** p = m_ppkHashTable + uiIndex;
    do
    {
        pNode = *p;
        if (pNode != 0)
        {
            *apIter = pNode;
            return;
        }
        ++uiIndex;
        ++p;
    } while (uiIndex < m_uiHashSize);
    *apIter = 0;
}

extern "C" void(__stdcall* fnv_EnterCriticalSection)(void* pkSection);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void* pkSection);

struct E92270CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class E92270Program
{
  public:
    unsigned int GetID();
};

class E92270Entry
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual bool Matches(const char* pcName, unsigned int uiID);
};

class E92270Library
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual E92270Program* FindProgram(const char* pcName, unsigned int uiID);
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual E92270Entry* GetFirstEntry();
    virtual E92270Entry* GetNextEntry();

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
    E92270CriticalSection m_kCriticalSection;

    bool HasEntry(const char* pcName, unsigned int uiID);
};

// Checks pcName is non-empty and resolves a program by name/ID, then scans the library's entries under the critical section for a matching entry.
// @fnv 0x00e92270
bool E92270Library::HasEntry(const char* pcName, unsigned int uiID)
{
    if (!pcName || !*pcName)
        return false;

    if (!FindProgram(pcName, uiID))
    {
        E92270Program* pkProgram = FindProgram(pcName, 0xffffffff);
        if (!pkProgram || pkProgram->GetID() != uiID)
            return false;
    }

    fnv_EnterCriticalSection(&m_kCriticalSection);
    E92270Entry* pkEntry = GetFirstEntry();
    bool bFound = false;
    while (pkEntry)
    {
        if (pkEntry->Matches(pcName, uiID))
        {
            bFound = true;
            break;
        }
        pkEntry = GetNextEntry();
    }
    fnv_LeaveCriticalSection(&m_kCriticalSection);
    return bFound;
}

struct ShaderLibrary
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool IsDefault();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void ReleaseResources();

    void FUN_00e818d0(void* renderer);
};
struct LibraryMap
{
    void* vtable;
    unsigned int count;
    ShaderLibrary** entries;
    __forceinline ShaderLibrary* GetFirst(unsigned int n) const
    {
        unsigned int i = 0;
        if (i < n)
        {
            ShaderLibrary** data = entries;
            ShaderLibrary** scan = data;
            do
            {
                if (*scan)
                    return data[i];
                ++i;
                ++scan;
            } while (i < n);
        }
        return 0;
    }
    void AdvanceToNextEntry(ShaderLibrary** current, void** position, ShaderLibrary** result);
};
struct ShaderRenderer
{
    void FUN_00e752b0(ShaderLibrary* library);
};
struct ShaderFactoryShell : NiD3DShaderFactory
{
    void FUN_00e92470();
};
// Iterates the shader library map and, for each non-default shader, releases its resources and notifies the renderer.
// @fnv 0x00e92470
void ShaderFactoryShell::FUN_00e92470()
{
    if (m_pOwnerShader && m_pShaderMapStorage)
    {
        LibraryMap* map = static_cast<LibraryMap*>(m_pShaderMapStorage);
        unsigned int size = map->count;
        ShaderLibrary* volatile pCurrentShader = 0;
        ShaderLibrary* current = map->GetFirst(size);
        void* position;
        while (current)
        {
            static_cast<LibraryMap*>(m_pShaderMapStorage)
                ->AdvanceToNextEntry(&current, &position, const_cast<ShaderLibrary**>(&pCurrentShader));
            ShaderLibrary* activeShader = pCurrentShader;
            if (activeShader)
            {
                ShaderLibrary& library = *activeShader;
                if (!library.IsDefault())
                {
                    library.FUN_00e818d0(m_pOwnerShader);
                    library.ReleaseResources();
                    static_cast<ShaderRenderer*>(m_pOwnerShader)->FUN_00e752b0(&library);
                }
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl strcpy_s(char* pcDest, unsigned int uiSize, const char* pcSrc);

void* __cdecl NiMalloc(unsigned int uiSize);

class BE92910RefObject
{
  public:
    virtual ~BE92910RefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }

    long m_lRefCount;
};

template <class T> class BE92910Pointer
{
  public:
    BE92910Pointer(const BE92910Pointer& kOther);
    ~BE92910Pointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    BE92910Pointer& operator=(const BE92910Pointer& kOther)
    {
        if (m_pObject != kOther.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kOther.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* m_pObject;
};

struct BE92910Entry
{
    int unk00;
    const char* m_pcName;
    BE92910Pointer<BE92910RefObject> m_pReferencedObject;
};

class FUN_00e92910_cls
{
  public:
    void SetEntryNameAndObject(BE92910Entry* pkEntry, const char* pcName,
                               BE92910Pointer<BE92910RefObject> spRetainedObject) throw();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool m_bCopyStrings;
};

// @fnv 0x00e92910
void FUN_00e92910_cls::SetEntryNameAndObject(BE92910Entry* pkEntry, const char* pcName,
                                             BE92910Pointer<BE92910RefObject> spRetainedObject) throw()
{
    if (m_bCopyStrings)
    {
        unsigned int uiLen = strlen(pcName) + 1;
        char* pcCopy = (char*)NiMalloc(uiLen);
        pkEntry->m_pcName = pcCopy;
        strcpy_s(pcCopy, uiLen, pcName);
    }
    else
    {
        pkEntry->m_pcName = pcName;
    }
    pkEntry->m_pReferencedObject = spRetainedObject;
}

struct ShaderLibrary_92c40
{
    const char* FUN_00d47a30();
};
struct ReferenceObject_92c40
{
    virtual void Reserved();
    virtual void Release();
    volatile long referenceCount;
};
struct LibraryMap_92c40
{
    void FUN_00e91fd0(const char*);
    void AdvanceIterator(void**, void**, ReferenceObject_92c40**);
    void FUN_00b601a0();
};
struct FUN_00e92c40_shell : NiD3DShaderFactory
{
    ShaderLibrary_92c40* FUN_00e92b50();
    void FUN_00e92c40();
};
// @fnv 0x00e92c40
void FUN_00e92c40_shell::FUN_00e92c40()
{
    if (!m_pShaderLibraryStorage)
        return;
    ShaderLibrary_92c40* current = FUN_00e92b50();
    if (current)
    {
        do
        {
            ((LibraryMap_92c40*)m_pShaderLibraryStorage)->FUN_00e91fd0(current->FUN_00d47a30());
            if (!m_pShaderLibraryStorage || !m_pShaderLibraryIterator)
                break;
            ReferenceObject_92c40* next = 0;
            void* scratch;
            ((LibraryMap_92c40*)m_pShaderLibraryStorage)->AdvanceIterator(&m_pShaderLibraryIterator, &scratch, &next);
            ReferenceObject_92c40* savedNext = *(ReferenceObject_92c40* volatile*)&next;
            if (savedNext && InterlockedDecrement(&savedNext->referenceCount) == 0)
                savedNext->Release();
            current = (ShaderLibrary_92c40*)savedNext;
        } while (current);
    }
    ((LibraryMap_92c40*)m_pShaderLibraryStorage)->FUN_00b601a0();
}

struct ShaderMap
{
    virtual void Dispose(unsigned int flags);
    void FUN_00b601a0();
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* criticalSection);

struct ShaderFactoryShutdown : NiD3DShaderFactory
{
    void FUN_00e92c40();
    void FUN_00aa05a0();
    void FUN_00e92dc0();
};

// @fnv 0x00e92dc0
void ShaderFactoryShutdown::FUN_00e92dc0()
{
    ShaderMap* shaderMap = static_cast<ShaderMap*>(m_pShaderMapStorage);
    m_ppVirtualMethodTable = &kVtbl_NiD3DShaderFactory;
    if (shaderMap)
        shaderMap->FUN_00b601a0();

    FUN_00e92c40();

    if (m_pShaderMapStorage)
        static_cast<ShaderMap*>(m_pShaderMapStorage)->Dispose(1);
    if (m_pShaderLibraryStorage)
        static_cast<ShaderMap*>(m_pShaderLibraryStorage)->Dispose(1);

    m_pShaderMapStorage = 0;
    m_pShaderLibraryStorage = 0;
    m_pOwnerShader = 0;
    DeleteCriticalSection(m_kShaderMap);
    FUN_00aa05a0();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00d47a30_class
{
    void* m_ppVirtualMethodTable;
    long m_iObjectReferenceCount;
    void* FUN_00d47a30();
};
struct ShaderObjRef_e92a40
{
    FUN_00d47a30_class* m_p;
    ShaderObjRef_e92a40(FUN_00d47a30_class* p)
    {
        m_p = p;
        InterlockedIncrement(&p->m_iObjectReferenceCount);
    }
    ShaderObjRef_e92a40(const ShaderObjRef_e92a40& o)
    {
        m_p = o.m_p;
        InterlockedIncrement(&m_p->m_iObjectReferenceCount);
    }
};
struct FUN_00e927f0_class
{
    void FUN_00e927f0(void* a, ShaderObjRef_e92a40 b);
};
struct ShaderFactory_e92a40 : NiD3DShaderFactory
{
    void FUN_00e92a40(FUN_00d47a30_class* p);
};
// @fnv 0x00e92a40
void ShaderFactory_e92a40::FUN_00e92a40(FUN_00d47a30_class* p)
{
    if (p)
    {
        reinterpret_cast<FUN_00e927f0_class*>(m_pShaderLibraryStorage)->FUN_00e927f0(p->FUN_00d47a30(), p);
    }
}

struct ShaderMapNode305
{
    ShaderMapNode305* next;
    const char* key;
    void* value;
};
extern "C" void __cdecl FUN_00aa10f0(void*);
class MapBase305
{
  public:
    virtual ~MapBase305()
    {
        RemoveAll();
        FUN_00aa10f0(buckets);
    }
    virtual void Hash();
    virtual void Equal();
    virtual void SetValue();
    virtual void ClearValue(ShaderMapNode305* item);
    virtual void* NewItem() = 0;
    virtual void DeleteItem(ShaderMapNode305*) = 0;
    unsigned int hashSize;
    ShaderMapNode305** buckets;
    unsigned int count;
    void RemoveAll() throw();
};
class PointerMap305 : public MapBase305
{
  public:
    virtual ~PointerMap305()
    {
        RemoveAll();
    }
    virtual void* NewItem();
    virtual void DeleteItem(ShaderMapNode305*);
};
class FUN_00e925a0 : public PointerMap305
{
  public:
    bool ownsKeys;
    virtual void Hash();
    virtual void Equal();
    virtual void SetValue();
    virtual void ClearValue(ShaderMapNode305* item);
    virtual ~FUN_00e925a0();
};
// @fnv 0x00e925a0
FUN_00e925a0::~FUN_00e925a0()
{
    if (ownsKeys)
    {
        for (unsigned int i = 0; i < hashSize; ++i)
        {
            ShaderMapNode305* item = buckets[i];
            while (item)
            {
                ShaderMapNode305* current = item;
                item = item->next;
                FUN_00aa10f0(const_cast<char*>(current->key));
            }
        }
    }
}

extern "C" void _ReadWriteBarrier();
class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
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
class ObjectMapE92
{
  public:
    bool FUN_00e92760(const char* pcName, ShaderRefObject*& spRetainedObject) throw();
};
class ShaderFactoryView
{
  public:
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
    ObjectMapE92* m_pTaskMap;
    ShaderRefObject* GetShaderRefObject(const char* pcName) throw();
};
// Looks up a ShaderRefObject by name in m_pTaskMap and returns it, releasing the temporary reference in all cases.
// @fnv 0x00e92a70
ShaderRefObject* ShaderFactoryView::GetShaderRefObject(const char* pcName) throw()
{
    ShaderRefObject* spRetainedObject = 0;
    bool found = m_pTaskMap->FUN_00e92760(pcName, spRetainedObject);
    ShaderRefObject* p = spRetainedObject;
    _ReadWriteBarrier();
    if (found)
    {
        if (p && InterlockedDecrement(&p->m_uiRefCount) == 0)
            p->DeleteThis();
        return p;
    }
    if (p && InterlockedDecrement(&p->m_uiRefCount) == 0)
        p->DeleteThis();
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class NiRefObjE92A
{
  public:
    virtual ~NiRefObjE92A();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }

    long m_uiRefCount;
};

template <class T> class NiPointerE92A
{
  public:
    NiPointerE92A(T* p = 0) : m_pObject(p)
    {}
    ~NiPointerE92A()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class NiMapE92A
{
  public:
    __declspec(noalias) bool FUN_00e92760(const char* pcName, NiRefObjE92A*& pkVal) throw();
    __declspec(noalias) bool FUN_00e91fd0(const char* pcName) throw();
};

class OwnerE92A
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    NiMapE92A* m_pTaskMap;

    void FUN_00e92ae0(const char* pcName);
};

// Looks up pcName in m_pTaskMap; if found with refcount 2, removes it and decrements the reference, otherwise just decrements the reference.
// @fnv 0x00e92ae0
void OwnerE92A::FUN_00e92ae0(const char* pcName)
{
    NiRefObjE92A* pkVal = 0;
    bool bFound = m_pTaskMap->FUN_00e92760(pcName, pkVal);
    if (bFound && pkVal->m_uiRefCount == 2)
    {
        m_pTaskMap->FUN_00e91fd0(pcName);
        pkVal->DecRefCount();
        return;
    }
    if (pkVal)
        pkVal->DecRefCount();
}

namespace fnv_00e92b50 {
class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
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
struct ShaderResult
{
    ShaderRefObject* pointer;
};
struct ShaderMapItem
{
    ShaderMapItem* m_pkNext;
    const char* m_key;
    NiPointer<ShaderRefObject> m_val;
};
struct ShaderMapAllocator
{
    unsigned int m_uiCount;
    void* Allocate();
};
class ShaderStringPointerMap
{
  public:
    virtual ~ShaderStringPointerMap();
    virtual unsigned int KeyToHashIndex(const char*) const;
    virtual bool IsKeysEqual(const char*, const char*) const;
    virtual void SetValue(ShaderMapItem*, const char*, NiPointer<ShaderRefObject>);
    unsigned int m_uiHashSize;
    ShaderMapItem** m_ppkHashTable;
    ShaderMapAllocator m_kItemCount;
    bool m_bCopy;
    void AdvanceIterator(void*&, const char*&, ShaderResult&) throw();
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
};

class ShaderFactoryView
{
  public:
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
    void* m_pShaderLibraryIterator;
    ShaderStringPointerMap* m_pShaderLibraryStorage;
    ShaderRefObject* FUN_00e92b50();
};
// Resets the iterator to the first map position, advances it once, releases the returned object's reference, and returns that pointer.
// @fnv 0x00e92b50
ShaderRefObject* ShaderFactoryView::FUN_00e92b50()
{
    ShaderStringPointerMap* map = m_pShaderLibraryStorage;
    if (!map)
        return 0;
    {
        m_pShaderLibraryIterator = map->GetFirstPos();
        if (m_pShaderLibraryIterator)
        {
            const char* key;
            ShaderResult object = {0};
            map->AdvanceIterator(m_pShaderLibraryIterator, key, object);
            ShaderRefObject* result = static_cast<volatile ShaderResult&>(object).pointer;
            if (result != 0)
            {
                if (InterlockedDecrement(&result->m_uiRefCount) == 0)
                    result->DeleteThis();
            }
            return result;
        }
    }
    return 0;
}
}  // namespace fnv_00e92b50

struct S_00e92be0_Callee
{
    void* __thiscall AdvanceIterator(void* key, void** outA, void** outB);
};

struct S_00e92be0_Ref
{
    virtual void f0();
    virtual void f1();
    int unk04;
};

struct S_00e92be0_Factory
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
    S_00e92be0_Callee* unk30;

    S_00e92be0_Ref* FUN_00e92be0();
};

void S_00e92be0_Ref::f0()
{}

void S_00e92be0_Ref::f1()
{}

// Calls unk30->AdvanceIterator to fetch the next S_00e92be0_Ref, decrements its reference count, and returns the object or null.
// @fnv 0x00e92be0
S_00e92be0_Ref* S_00e92be0_Factory::FUN_00e92be0()
{
    S_00e92be0_Callee* callee = unk30;
    if (callee != 0 && unk2c != 0)
    {
        void* pOut = 0;
        void* local4;

        callee->AdvanceIterator(&unk2c, &local4, &pOut);
        S_00e92be0_Ref* object = reinterpret_cast<S_00e92be0_Ref*>(*static_cast<void* volatile*>(&pOut));

        if (object != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&object->unk04)) == 0)
            {
                object->f1();
            }
        }
        return object;
    }
    return 0;
}

struct ShaderRGB
{
    float r, g, b;
};
struct ShaderRGBA
{
    float r, g, b, a;
};
class ShaderMaterialCache;
struct ShaderMaterialSource
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    ShaderRGB diffuse;
    ShaderRGB specular;
    ShaderRGB* specularOverride;
    float glossiness;
    float alpha;
    unsigned int unk40;
    unsigned int revision;
    ShaderMaterialCache* cache;
};
extern ShaderRGB DAT_011f4998;

class ShaderMaterialCache : public NiMemObject
{
  public:
    ShaderRGBA ambient, emissive, diffuse, specular;
    float glossiness;
    unsigned int revision;
    ShaderMaterialCache(ShaderMaterialSource* material) : revision(0)
    {
        CopyColorIfChanged(material);
    }
    __declspec(noinline) bool CopyColorIfChanged(ShaderMaterialSource* material);
};

bool ShaderMaterialCache::CopyColorIfChanged(ShaderMaterialSource* material)
{
    if (revision == material->revision)
        return false;
    revision = material->revision;
    ShaderRGB* spec = material->specularOverride;
    if (!spec)
        spec = &material->specular;
    float alpha = material->alpha;
    specular.r = spec->r;
    specular.g = spec->g;
    specular.b = spec->b;
    specular.a = alpha;
    emissive.r = DAT_011f4998.r;
    emissive.g = DAT_011f4998.g;
    emissive.b = DAT_011f4998.b;
    emissive.a = alpha;
    ambient.r = DAT_011f4998.r;
    ambient.g = DAT_011f4998.g;
    ambient.b = DAT_011f4998.b;
    ambient.a = alpha;
    diffuse.r = material->diffuse.r;
    diffuse.g = material->diffuse.g;
    diffuse.b = material->diffuse.b;
    diffuse.a = alpha;
    glossiness = material->glossiness;
    return true;
}

// Creates or updates the ShaderMaterialCache for the material, copying colors if the revision changed, and sets m_shutdown when state changes.
// @fnv 0x00e940d0
void NiD3DShaderFactory::UpdateShaderMaterialCache(void* parameter)
{
    ShaderMaterialSource* material = (ShaderMaterialSource*)parameter;
    ShaderMaterialCache* object = material->cache;
    if (!object)
    {
        object = new ShaderMaterialCache(material);
        material->cache = object;
        m_shutdown = true;
    }
    if (object->CopyColorIfChanged(material))
        m_shutdown = true;
    if (object != m_ppVirtualMethodTable)
    {
        m_shutdown = true;
        m_ppVirtualMethodTable = object;
    }
}

extern "C" void __cdecl FUN_00aa0020(int, int, const char*, ...);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" char UNK_010f0b84[];
extern "C" char UNK_010f0b20[];
extern "C" char UNK_010f0b54[];

class ShaderLibraryProducer
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual ShaderLibrary* CreateShader(ShaderRenderer*, const char*, unsigned int);
};
class Logger
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Log(int, const char*, int, int, int);
};
extern "C" Logger* DAT_011f6388;

class ShaderFactory
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual ShaderLibrary* AcquireShader(const char*, unsigned int);
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void RegisterShader(ShaderLibrary*, unsigned int);
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual ShaderLibraryProducer* GetVertexShaderConstantInterface();
    virtual ShaderLibraryProducer* GetPixelShaderConstantInterface();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    ShaderRenderer* m_pOwnerShader;
    int m_pShaderMapStorage;
    int m_pShaderLibraryIterator;
    int m_pShaderLibraryStorage;
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
    int m_kShaderMap;

    ShaderLibrary* FUN_00e920a0(const char* pcName, unsigned int uiImplementation, bool bReportFailure);
};
// Acquires a ShaderLibrary by name, creating and registering it via producer interfaces if not already present, and optionally logs a failure.
// @fnv 0x00e920a0
ShaderLibrary* ShaderFactory::FUN_00e920a0(const char* pcName, unsigned int uiImplementation, bool bReportFailure)
{
    if (!m_pOwnerShader)
    {
        if (DAT_011f6388)
            DAT_011f6388->Log(4, UNK_010f0b84, 0, 0, 0);
        return 0;
    }
    if (!pcName || !*pcName)
    {
        FUN_00aa0020(1, 0, UNK_010f0b20);
        return 0;
    }
    ShaderLibrary* pkShader = AcquireShader(pcName, uiImplementation);
    if (!pkShader)
    {
        void* pCriticalSection = &m_kShaderMap;
        EnterCriticalSection(pCriticalSection);
        ShaderLibraryProducer* pkLibrary = GetVertexShaderConstantInterface();
        pkShader = AcquireShader(pcName, uiImplementation);
        if (!pkShader)
        {
            while (pkLibrary)
            {
                pkShader = pkLibrary->CreateShader(m_pOwnerShader, pcName, uiImplementation);
                if (pkShader)
                {
                    RegisterShader(pkShader, uiImplementation);
                    m_pOwnerShader->FUN_00e752b0(pkShader);
                    pkShader->FUN_00e818d0(m_pOwnerShader);
                    break;
                }
                pkLibrary = GetPixelShaderConstantInterface();
            }
        }
        LeaveCriticalSection(pCriticalSection);
    }
    if (bReportFailure && !pkShader)
        FUN_00aa0020(1, 0, UNK_010f0b54, pcName, uiImplementation);
    return pkShader;
}

// Today's tree does not provide the CRITICAL_SECTION typedef (windows.h include is
// dropped when merged); declare the lock functions the way the tree does and use a
// stand-in with the 24-byte x86 CRITICAL_SECTION layout.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FUN_00e92330_critsec
{
    char data[0x18];
};

struct FUN_00e92330_arg
{
    unsigned int* FUN_00a62660();
    unsigned int FUN_00cc0760();
};

struct FUN_00e92330_item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Test(unsigned int p);
};

struct FUN_00e92330_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual FUN_00e92330_item* Match(unsigned int a, unsigned int b);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual FUN_00e92330_item* GetFirst();
    virtual FUN_00e92330_item* GetNext();
    unsigned int unk04[31];
    FUN_00e92330_critsec m_lock;
    bool FUN_00e92330(unsigned int a1);
};

typedef FUN_00e92330_item*(__thiscall* FUN_00e92330_match)(FUN_00e92330_cls*, unsigned int, unsigned int);

// Checks whether the collection contains the item identified by a1, using a virtual Match lookup and a Test predicate under a critical section.
// @fnv 0x00e92330
bool FUN_00e92330_cls::FUN_00e92330(unsigned int apItem)
{
    if (apItem == 0)
    {
        return false;
    }
    unsigned int key = *((FUN_00e92330_arg*)apItem)->FUN_00a62660();
    void** pVTable = *(void***)this;
    void** pMatchSlot = pVTable + 3;
    unsigned int ref = ((FUN_00e92330_arg*)apItem)->FUN_00cc0760();
    FUN_00e92330_item* r = ((FUN_00e92330_match)*pMatchSlot)(this, key, ref);
    if (!(r && (unsigned int)r == apItem))
    {
        unsigned int key2 = *((FUN_00e92330_arg*)apItem)->FUN_00a62660();
        r = ((FUN_00e92330_match)(*(void***)this)[3])(this, key2, 0xffffffff);
        if (!(r && (unsigned int)r == apItem))
        {
            return false;
        }
    }
    EnterCriticalSection(&m_lock);
    FUN_00e92330_item* pItem = GetFirst();
    bool result = false;
    while (pItem)
    {
        if (pItem->Test(apItem))
        {
            result = true;
            break;
        }
        pItem = GetNext();
    }
    LeaveCriticalSection(&m_lock);
    return result;
}

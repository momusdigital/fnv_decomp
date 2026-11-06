// src/havok/common/serialize/util/hkbuiltintyperegistry_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/serialize/util/hkbuiltintyperegistry.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/serialize/util/hkbuiltintyperegistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkbuiltintyperegistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkDefaultBuiltinTypeRegistry
{
    int* v;
    int _pad;
    unsigned short _f;
    void FUN_00d47860();
    hkDefaultBuiltinTypeRegistry* Initialize();
};
extern int DAT_010cf78c;
struct FUN_00d479e0_class
{
    void* __thiscall GetValue(const void* key, const void* def);
    void* __thiscall getTypeInfo(const void* key);
};
struct FUN_00d47a80_class
{
    void* GetValue(void* a, int b);
    void* ForwardToOffsetMember(void* a);
};
struct HashEntryTable
{
    unsigned long FindValueForKey(unsigned long a, unsigned long b);
};
struct hkVtableClassRegistry
{
    unsigned long LookupClassByVtable(const unsigned long* p);
};
struct D481D0Class
{
    const char* getName() const;
};
struct FUN_00d874d0_s
{
    void FUN_00d874d0(const char*, int);
};
struct FUN_00d47aa0_s
{
    int a;
    int b;
    int c;
    void registerClass(int a, const char* name);
};
struct FUN_00d87440_Class
{
    int __thiscall FUN_00d87440(int);
};
struct SlotBitmap
{
    int __thiscall FindNextUsedSlot(int);
};
struct FUN_00d874b0_class
{
    char* __thiscall SetBoolFromThreshold(char*, int);
};
struct FUN_00d87410_Class
{
    int __thiscall FUN_00d87410();
};
struct FUN_00d47ad0_class
{
    void ProcessRegistryEntries(FUN_00d874b0_class* reg);
};
struct MemoryManager
{
    int a, b, c, d;
    void* e;
};
struct MemoryRouter
{
    int f, g, h, i;
    MemoryManager j;
};
extern "C" MemoryRouter* __cdecl D1A0E0GetMemoryRouter();
struct DepthLimit
{
    void FUN_00cb1870(void*, void*, int);
};
struct FUN_00d47c60_class
{
    int x, y;
    DepthLimit z;
    void FUN_00d47c60(void* key, int def);
};
extern int DAT_01269b18;
int __cdecl FUN_00d47a00();
extern int DAT_01269b14;
int __cdecl FUN_00d47a10();
extern int DAT_01269b10;
int FUN_00d47a20();
struct D477C0Input
{
    int unk00, unk04, unk08;
    void* value0c;
};
struct D477C0Source
{
    int FUN_00d46d40();
    int SumLinkedValues();
};
struct D477C0RegistryA
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void registerObject(D477C0Source*, int);
};
struct D477C0RegistryB
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerInput(D477C0Input*);
};
struct D477C0RegistryC
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerLink(void*, D477C0Source*);
};
void __stdcall RegisterInputSource(D477C0Input* input, D477C0Source* source);
struct hkClassD478
{
    const char* m_name;

    const char* getName() const
    {
        return m_name;
    }
};
class hkClassNameRegistryD478
{
  public:
    int m_00;
    int m_04;
    FUN_00d874d0_s m_map;

    void RegisterClass(const hkClassD478* pkClass);
};
struct hkEntryD479
{
    int m_00;
    void(__cdecl* m_func)(void* a, int b);
};
struct hkObjD479
{
    int m_00;
    int m_04;
    FUN_00d47a80_class m_map;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    hkEntryD479* FindEntryAndCall(void* a, void* key);
};
struct FUN_00d47940_Result
{
    int unk00;
    int unk04;
    void(__cdecl* unk08)(int);
};
struct FUN_00d47940_Registry
{
    void* __thiscall GetValue(const void* key, const void* def);
};
struct FUN_00d47940_Obj
{
    int unk00;
    int unk04;
    FUN_00d47940_Registry unk08;
    void* __thiscall cleanupLoadedObject(int param1, int param2);
};
struct FUN_00d87430_Class
{
    int __thiscall GetEntry(int index);
};
struct FUN_00d47970_Class
{
    int unk00;
    int unk04;
    FUN_00d874d0_s m_map08;

    void merge(void* iterator);
};
class hkObjD47A
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void add(const char* pcName, int iFlags);

    void AddNames(const char* const* ppcNames);
};
struct HavokHeap
{
    virtual void reserve();
    virtual void allocate();
    virtual void release(void* memory, unsigned int size);
};
struct HavokRouter
{
    int unk00, unk04, unk08, unk0c;
    HavokHeap* heap;
};
extern "C" HavokRouter* __cdecl FUN_00c85750();
struct EmbeddedRegistry
{
    void FreeBuffer();
    ~EmbeddedRegistry()
    {
        FreeBuffer();
    }
};
struct RegistryBase
{
    virtual ~RegistryBase()
    {}
    unsigned short allocatedSize;
    unsigned short unk06;
    int unk08;
};
struct RegistryImpl : RegistryBase
{
    EmbeddedRegistry embedded;
    RegistryImpl* DestroyRegistry(unsigned int flags);
};
class hkMemoryAllocatorD47B
{
  public:
    virtual ~hkMemoryAllocatorD47B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD47B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD47B* m_pStreamAllocator;
    hkMemoryAllocatorD47B& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD47B {
extern "C" hkMemoryRouterD47B& __cdecl FUN_00c85750() throw();
}
class hkReferencedObjectD47B
{
  public:
    virtual ~hkReferencedObjectD47B() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterD47B::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectD47B*>(p)->m_usMemSizeAndFlags);
    }
};
class hkMemberD47B
{
  public:
    int unk00;
    void FreeBuffer() throw();
};
class hkObjectD47B : public hkReferencedObjectD47B
{
  public:
    hkMemberD47B m_kMemberDescriptor;

    hkObjectD47B* FUN_00d47b70(unsigned int uiFlags) throw();
};
// @fnv 0x00d47860
struct DefaultNameRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void registerName(const void* name);
};
struct RuntimeTypeInfoRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void registerType(void* typeInfo);
};
struct NameRegistryTable
{
    void FUN_00db78a0(void** entries, void* info);
};
extern int DAT_01268b0c;
extern void* DAT_010d5430[];
extern int DAT_010d59b8;
void __cdecl FUN_00d47860()
{
    DefaultNameRegistry* reg = (DefaultNameRegistry*)DAT_01269b14;
    reg->registerName(&DAT_01268b0c);
    RuntimeTypeInfoRegistry* types = (RuntimeTypeInfoRegistry*)DAT_01269b18;
    void** curr = DAT_010d5430;
    while (*curr)
    {
        types->registerType(*curr);
        ++curr;
    }
    ((NameRegistryTable*)DAT_01269b10)->FUN_00db78a0(DAT_010d5430, &DAT_010d59b8);
}

struct FUN_00d47820_allocator
{
    virtual void FUN_00d47820_dummy() = 0;
    virtual void* FUN_00d47820_alloc(unsigned int size)
    {
        return ::operator new(size);
    }
};

struct FUN_00d47820_router
{
    void* vtable;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    FUN_00d47820_allocator* allocator;
};

extern FUN_00d47820_router* _D1A0E0GetMemoryRouter();

// @fnv 0x00d47820
hkDefaultBuiltinTypeRegistry* FUN_00d47820()
{
    if (DAT_01269b10 != 0 && DAT_01269b14 != 0 && DAT_01269b18 != 0)
    {
        FUN_00d47820_router* router = _D1A0E0GetMemoryRouter();
        void* memory = router->allocator->FUN_00d47820_alloc(8);
        hkDefaultBuiltinTypeRegistry* registry = static_cast<hkDefaultBuiltinTypeRegistry*>(memory);
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(registry) + 4) = 8;
        return registry->Initialize();
    }
    return 0;
}

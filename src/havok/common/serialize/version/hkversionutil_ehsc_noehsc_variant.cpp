
// src/havok/common/serialize/version/hkversionutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/version/hkversionutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl VisitObjectList(int, int);
struct FUN_00db7a80_Class
{
    int __pad0;
    int __pad1;
    int __pad2;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void EnsureInitialized();
};
struct MemoryManager
{
    virtual void FUN_00e00000() = 0;
    virtual void FUN_00e00004() = 0;
    virtual void FUN_00e00008(void*, unsigned short) = 0;
};
struct MemoryRouter
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    MemoryManager* m_pMemoryManager;
};
MemoryRouter* _D1A0E0GetMemoryRouter();
struct Object
{
    void FUN_00e03160();
};
struct FUN_00e049d0_Class : Object
{
    unsigned int m_auiShapeKeys;
    unsigned short m_type;

    FUN_00e049d0_Class* FUN_00e049d0(int flags);
};
extern "C" char str_010cf830[];
void* __cdecl FUN_00dc0fb0();
struct FUN_00d86980_Class
{
    int FUN_00d86980();
};
struct FUN_00d871a0
{
    int m_00;
    int m_04;

    FUN_00d871a0(void*, int);
    bool& FUN_00d871e0(bool&);
    void* FUN_00d871f0();
    FUN_00d86980_Class* FUN_00d87370();
};
extern "C" void* __cdecl FUN_00cb1260(void*, const void*, unsigned int);
void __cdecl FUN_00dc0fc0(void* a1, int a2, void* a3, int a4);
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() const throw();
};
class GlobalObjectO2_00d472a0 : public FUN_00d46d40_s
{
  public:
    int m_00;
};
extern GlobalObjectO2_00d472a0 g_01268748;
int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB) throw();
class hkClassMemberDC11
{
  public:
    enum Type
    {
        TYPE_POINTER = 0x14,
        TYPE_ARRAY = 0x16,
        TYPE_STRUCT = 0x19,
        TYPE_SIMPLEARRAY = 0x1a,
        TYPE_VARIANT = 0x1c,
        TYPE_CSTRING = 0x1d,
        TYPE_STRINGPTR = 0x21
    };

    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;

    int FUN_00d86920() const throw();
    const FUN_00d46d40_s& FUN_00d86910() const throw();
};
class hkVersionCheckDC11
{
  public:
    int areMembersCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw();
    int IsMemberCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw();
};
class hkMemoryAllocatorDC12;
struct hkMemoryRouterDC12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC12* m_pStreamAllocator;
    hkMemoryAllocatorDC12& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC12& __cdecl FUN_00c85750();
void __cdecl ProcessObjectArray(void* const* ppvList, int iFlags) throw();
class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        FUN_00a29680();
    }

    void EnsureCapacity(hkMemoryAllocatorDC12& kAlloc, int iNumElems) throw();
    void ProcessArgument(hkMemoryAllocatorDC12& kAlloc) throw();
    void FUN_00a29680() throw();
};
class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        FUN_00dc1670();
    }
    void FUN_00dc1670() throw();
    void FUN_00dc1bb0(void* pvObject, hkPointerMapDC12& kDone, int iFlags) throw();
};
// @fnv 0x00dc1230
extern "C" void __cdecl VisitObjectList(int iList, int iFlags)
{
    void* const* ppvList = reinterpret_cast<void* const*>(iList);
    ProcessObjectArray(ppvList, iFlags);
    hkVisitorDC12 kVisitor;
    hkPointerMapDC12 kDone;
    kDone.EnsureCapacity(FUN_00c85750().heap(), 0);
    for (int i = 0; ppvList[i]; i++)
        kVisitor.FUN_00dc1bb0(ppvList[i], kDone, 1);
    kDone.ProcessArgument(FUN_00c85750().heap());
}
class hkBoolDC10
{
  public:
    hkBoolDC10(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
class FUN_00d27520
{
  public:
    void FUN_00d27520_dtor() throw();
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;
};
class FUN_00d274c0 : public FUN_00d27520
{
  public:
    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBoolDC10 bMemoryIsString) throw();
    int FUN_00d27380(int offset, int whence) throw();
};
struct EntryDC10
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short m_offset;
};
class SetDC10
{
  public:
    int FUN_00d46fe0(int key) throw();
};
class SectionsDC10
{
  public:
    int FUN_00d470d0() throw();
    int FUN_00d46f00() throw();
    EntryDC10* FUN_00d46f20(int i) throw();
    void InvokeTarget(int i, FUN_00d27520* pkWriter) throw();
};
void __cdecl FUN_00dc1070(void* pvBuf, SetDC10* pkSet, SectionsDC10* pkSections);
struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};
struct S00dc15a0_AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    S00dc15a0_Buffer* unk0C;
};
struct S00dc15a0_Params
{
    void* unk00;
    int unk04;
};
struct S00dc15a0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
};
namespace fnvc_adapt {
extern "C" S00dc15a0_AudioSystem* __cdecl FUN_00c85750();
}
extern "C" void __cdecl FUN_00c908c0(S00dc15a0_Buffer* buffer, int** indices, int size, int elementSize);
static __declspec(noinline) int FUN_00dc12c0(S00dc15a0_Params* params, int value, int flags, S00dc15a0_Array* arr)
{
    arr->m_iElementCount = (int)&params + (int)&value + (int)&flags;
    return arr->m_capFlags;
}
int __cdecl FUN_00dc15a0(S00dc15a0_Params* params, int value, int flags);

extern "C" void _ReadWriteBarrier();
struct ByteBuffer
{
    ~ByteBuffer();
    char* data;
    int size;
    int capacity;
};
struct IndexArray
{
    int* data;
    int size;
    int capacity;
};
struct ObjectEntry
{
    void* object;
    int type;
};
struct ObjectArray
{
    ObjectEntry* data;
    int size;
    int capacity;
};
struct OffsetEntry
{
    int offset;
    int type;
};
struct OffsetArray
{
    OffsetEntry* data;
    int size;
    int capacity;
};
struct CopyAllocator
{
    virtual void slot0() = 0;
    virtual char* allocate(int size) = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void release(void* data, int size) = 0;
};
struct CopyRouter
{
    void* field00;
    void* field04;
    void* field08;
    void* field0c;
    CopyAllocator* allocator;
};

struct MapEntry
{
    void* object;
    int offset;
};
struct OffsetMap
{
    void* entries;
    int size;
    int capacity;
    void EnsureCapacity(CopyAllocator*, int);
    void FUN_00cb1870(CopyAllocator*, void*, int);
    void ProcessArgument(CopyAllocator*);
    void FUN_00a29680();
    ~OffsetMap()
    {
        ProcessArgument(((CopyRouter*)&FUN_00c85750())->allocator);
        FUN_00a29680();
    }
};
struct ByteBufferWriter
{
    void* vtable;
    unsigned short flags;
    unsigned short references;
    void* writer;
    void FUN_00cc0630(ByteBuffer*);
    void FUN_00cc00e0();
    ~ByteBufferWriter()
    {
        FUN_00cc00e0();
    }
};
struct CopyOption
{
    int value;
    void FUN_00dc1680(const int*);
};
extern int DAT_011b7b88;
struct Relocation
{
    int offset;
    int target;
};
struct Import
{
    int offset;
    void* name;
    int field08;
    int field0c;
};
struct Relocations
{
    Relocation* local;
    int localCount;
    int localCapacity;
    Import* imports;
    int importCount;
    int importCapacity;
    void* exports;
    int exportCount;
    int exportCapacity;
    void* global;
    int globalCount;
    int globalCapacity;
    void* extra;
    void FUN_00e028e0();
    ~Relocations()
    {
        FUN_00e028e0();
    }
};
struct CopyWriter : Object
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int position;
    int options;
    void FUN_00dc1040(CopyOption*, CopyOption*);
    int FUN_00e04920(void*, int, int, int, Relocations*);
    ~CopyWriter()
    {
        FUN_00e03160();
    }
};
struct CopyListener
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void AddMemoryChunk(char*, int, int) = 0;
    virtual void addImport(void*, char*) = 0;
};

struct ObjectInput
{
    ObjectArray* p;
    ObjectInput(ObjectArray* q) : p(q)
    {}
};
struct OffsetInput
{
    OffsetArray* p;
    OffsetInput(OffsetArray* q) : p(q)
    {}
};
struct ListenerInput
{
    CopyListener* p;
    ListenerInput(CopyListener* q) : p(q)
    {}
};
// @fnv 0x00dc12c0
static __declspec(noinline) char* FUN_00dc12c0(IndexArray* indices, ObjectInput objectInput, OffsetInput offsetInput,
                                               CopyListener* listener)
{
    ByteBuffer buffer;
    buffer.data = 0;
    buffer.size = 0;
    buffer.capacity = (int)0x80000000u;
    ByteBufferWriter stream;
    stream.FUN_00cc0630(&buffer);
    Relocations fixups;
    fixups.local = 0;
    fixups.localCount = 0;
    fixups.localCapacity = (int)0x80000000u;
    fixups.imports = 0;
    fixups.importCount = 0;
    fixups.importCapacity = (int)0x80000000u;
    fixups.exports = 0;
    fixups.exportCount = 0;
    fixups.exportCapacity = (int)0x80000000u;
    fixups.global = 0;
    fixups.globalCount = 0;
    fixups.globalCapacity = (int)0x80000000u;
    fixups.extra = 0;
    OffsetMap map;
    map.entries = 0;
    map.size = 0;
    map.capacity = -1;
    CopyRouter* mapRouter = (CopyRouter*)&FUN_00c85750();
    _ReadWriteBarrier();
    map.EnsureCapacity(mapRouter->allocator, 0);
    int i;
    for (i = 0; i < indices->size; ++i)
    {
        int index = indices->data[i];
        ObjectEntry* object = &objectInput.p->data[index];
        CopyOption first;
        first.FUN_00dc1680(&DAT_011b7b88);
        CopyOption second;
        second.FUN_00dc1680(&DAT_011b7b88);
        CopyWriter writer;
        writer.FUN_00dc1040(&second, &first);
        int type = offsetInput.p->data[index].type;
        offsetInput.p->data[index].offset = buffer.size;
        int entryOffset = buffer.size;
        void* entryObject = object->object;
        CopyRouter* entryRouter = (CopyRouter*)&FUN_00c85750();
        _ReadWriteBarrier();
        map.FUN_00cb1870(entryRouter->allocator, entryObject, entryOffset);
        writer.FUN_00e04920(object->object, object->type, (int)stream.writer, type, &fixups);
    }
    int size = buffer.size;
    if (size)
    {
        CopyRouter* allocationRouter = (CopyRouter*)&FUN_00c85750();
        _ReadWriteBarrier();
        char* result = allocationRouter->allocator->allocate(size);
        listener->AddMemoryChunk(result, buffer.size, 5);
        FUN_00cb1260(result, buffer.data, buffer.size);
        for (i = 0; i < indices->size; ++i)
        {
            offsetInput.p->data[indices->data[i]].offset += (int)result;
        }
        for (i = 0; i < fixups.localCount; ++i)
        {
            Relocation* relocation = &fixups.local[i];
            *reinterpret_cast<char**>(result + relocation->offset) = result + relocation->target;
        }
        for (i = 0; i < fixups.importCount; ++i)
        {
            listener->addImport(fixups.imports[i].name, result + fixups.imports[i].offset);
        }
        return result;
    }
    return 0;
}

extern "C" IndexArray* get_indices();
char* invoke_copy(ObjectInput a, OffsetInput b, ListenerInput c)
{
    return FUN_00dc12c0(get_indices(), a, b, c.p);
}

inline ByteBuffer::~ByteBuffer()
{
    CopyAllocator* allocator = ((CopyRouter*)&FUN_00c85750())->allocator;
    size = 0;
    if ((capacity & (int)0x80000000u) == 0)
        allocator->release(data, capacity & 0x3fffffff);
}


// src/havok/common/serialize/packfile/hkpackfilewriter_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/packfile/hkpackfilewriter.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/packfile/hkpackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Vsnprintf(void*, void*, const char*, int, int, int, const char*);
void __cdecl FUN_00dbda20(void* a, void* b);
struct FUN_00dbdd40_s
{
    int __thiscall GetOrAddString(int a);
};
struct FUN_00d46d40_s
{
    const char* __thiscall FUN_00d46d40();
};
struct FUN_00d874d0_s
{
    void __thiscall FUN_00d874d0(const char*, int);
};
struct FUN_00dbdf30_s
{
    int m_kPointA;
    int m_kPointB;
    void __thiscall setSectionForClass(int a, int b);
};
struct MemoryRouter
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
};
extern "C" MemoryRouter* __cdecl D1A0E0GetMemoryRouter();
struct DepthLimit
{
    void FUN_00cb1870(void*, void*, int);
};
struct FUN_00dbdae0
{
    char m[0x2c];
    DepthLimit m_dl;
    void FUN_00dbdae0_0(void* a, int b);
};
struct FUN_00dbe760_s;
struct FUN_00dbe760_target
{
    virtual void FUN_00dbe760_virtual_0();
    virtual void FUN_00dbe760_virtual_1();
    virtual void FUN_00dbe760_virtual_2(FUN_00dbe760_s*, unsigned short);
};
struct FUN_00dbe760_router
{
    unsigned char m_ucUnknownByte[0x10];
    FUN_00dbe760_target* m_target;
};
FUN_00dbe760_router* _D1A0E0GetMemoryRouter();
struct FUN_00dbc6e0_s
{
    virtual void FUN_00dbdf60();
};
struct FUN_00dbe760_s : public FUN_00dbc6e0_s
{
    unsigned short m_uiFilterValue;

    FUN_00dbe760_s* __thiscall FUN_00dbe760(int a);
};
struct FUN_00cb1930_s
{
    int LookupHashEntry(const void* key, int defaultValue);
};
struct FUN_00c85750_s
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* allocator;
    static FUN_00c85750_s* __cdecl FUN_00c85750();
};
struct TrackedElement
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int state;
    unsigned int unk14;
};
struct FUN_00dbda80_s
{
    void* m00;
    void* m04;
    TrackedElement* entries;
    void* m0c;
    void* m10;
    FUN_00cb1930_s entryIndex;
    unsigned int unk18;
    unsigned int unk1c;
    DepthLimit firstDepth;
    void FUN_00dbda80(void* key, int value);
};
extern int DAT_0102e388;
struct FUN_00dbdb10_buf
{
    int unk00;
    int unk04;
    volatile int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct FUN_00dc1670_Obj
{
    void FUN_00dc1670();
};
struct FUN_00e02bb0_Obj
{
    void FUN_00e02bb0(void* a);
};
struct FUN_00e02ef0_Obj
{
    void FUN_00e02ef0();
};
struct FUN_00e02a80_Obj
{
    void FUN_00e02a80(void* a, void* b, void* c, void* d);
};
struct FUN_00e02c70_Obj
{
    void FUN_00e02c70();
};
void __cdecl FUN_00dbdb10(void* a, void* b, void* c);
extern "C" void __cdecl GetOrAddString(void);
void __cdecl FUN_00dbdef0();
struct DbFirst
{
    char* __thiscall GetLastNodeFlag(void* out);
};
struct DbSecond
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual unsigned int vf10(unsigned int value);
};
static unsigned int FUN_00dbd9f0(DbFirst* first, DbSecond* second, unsigned int arg);
DbFirst* volatile g_dbd_first;
DbSecond* volatile g_dbd_second;
unsigned int volatile g_dbd_arg;
unsigned int volatile g_dbd_sink;
void dbd9f0_probe_caller(void);
class hkMemoryAllocatorDB7;
struct hkMemoryRouterDB7
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDB7* m_pStreamAllocator;
    hkMemoryAllocatorDB7& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDB7& __cdecl GetMemoryRouterDB7() throw();
int __cdecl hkStrCmpDB7(const char* pcA, const char* pcB) throw();
class hkClassDB7
{
  public:
    const char* getName() const throw();
    unsigned int CalculateDatabaseSignature(int iFlags) const throw();
};
struct hkClassEnumDB7
{
    const char* m_name;
};
class hkOstreamDB7
{
  public:
    hkOstreamDB7(void* pvBuffer, int iSize) throw();
    ~hkOstreamDB7() throw();
    hkOstreamDB7& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorDB7
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorDB7* g_pkErrorDB7;
struct hkPointerMapDB7
{
    int FindValueForKey(const void* pvKey, int iDefault) const throw();
    void insert(hkMemoryAllocatorDB7& kAlloc, const void* pvKey, int iValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapDB7
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const throw();
    void insert(const char* pcKey, void* pvValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
class hkPackfileWriterDB7
{
  public:
    int RegisterObject(void* pvObject, const hkClassDB7* pkClass) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkPointerMapDB7 m_kObjectIndexMap;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkStringMapDB7 m_kObjectNameMap;
    hkStringMapDB7 m_kClassLookupMap;
    hkPointerMapDB7 m_kClassMap;
};
template <int SIZE> __forceinline void memCpyOneAlignedXdbdd40(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}
struct hkMemoryRouterXdbdd40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};
namespace hkRouterXdbdd40 {
extern "C" hkMemoryRouterXdbdd40& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);
template <class T> class hkArrayXdbdd40
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXdbdd40& router = hkRouterXdbdd40::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXdbdd40<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};
extern "C" char* __cdecl FUN_00cb1410(const char* str);
class hkStringMapXdbdd40
{
  public:
    int FUN_00d87650(const char* key, int* out);
    void FUN_00d874d0(const char* key, int value);
};
class hkStringPoolXdbdd40
{
  public:
    int unk00[25];
    hkArrayXdbdd40<char*> m_pStringFunctions;
    hkStringMapXdbdd40 m_map;

    int GetOrAddString(const char* str);
};
struct S00dbde40_Base
{
    int __thiscall FUN_00dbddc0(int a, int b, int c);
};
struct S00dbde40_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct S00dbde40_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct S00dbde40_Obj : public S00dbde40_Base
{
    int unk00;
    int unk04;
    S00dbde40_Arr arr;
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

    void __thiscall FUN_00dbde40(int a, int b, int c, int d, int e);
};
void* __cdecl FUN_00c85750(void);
void __cdecl ResizeAudioStream(void* a, void* b, int c);
extern char DAT_0126cae8;
class hkMemoryAllocatorDF6
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterDF6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDF6* m_pStreamAllocator;
    hkMemoryAllocatorDF6& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDF6& __cdecl GetMemoryRouterDF6() throw();
void __cdecl hkDeallocateDF6(hkMemoryAllocatorDF6& kAlloc, void* pvData) throw();
class hkReferencedObjectDF6
{
  public:
    virtual ~hkReferencedObjectDF6() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <typename T> struct hkArrayDF6
{
    ~hkArrayDF6() throw()
    {
        hkMemoryAllocatorDF6& kAlloc = GetMemoryRouterDF6().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkMapDF6
{
    ~hkMapDF6() throw();
    void ClearAndRelease(hkMemoryAllocatorDF6& kAlloc) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkPointerMapDF6
{
    ~hkPointerMapDF6() throw()
    {
        m_map.ClearAndRelease(GetMemoryRouterDF6().heap());
    }
    hkMapDF6 m_map;
};
struct hkStringMapDF6
{
    ~hkStringMapDF6() throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct SectionDF6
{
    int m_aiData00;
    int m_aiData04;
    int m_aiData08;
    int m_aiData0C;
    int m_aiData10;
    int m_aiData14;
};
struct PairDF6
{
    void* m_pvFirst;
    void* m_pvSecond;
};
struct SectionTableDF6
{
    hkArrayDF6<PairDF6> m_entries;
    hkPointerMapDF6 m_uiEdgeIndex;
};
class FUN_00dbdf60 : public hkReferencedObjectDF6
{
  public:
    virtual ~FUN_00dbdf60() throw();
    hkArrayDF6<SectionDF6> m_sections;
    hkPointerMapDF6 m_kObjectNameMap;
    hkPointerMapDF6 m_kObjectIndexMap;
    hkPointerMapDF6 m_kClassMap;
    hkStringMapDF6 m_kClassNameMap;
    hkStringMapDF6 m_classNames;
    hkPointerMapDF6 m_kObjectMap;
    hkArrayDF6<void*> m_pendingObjects;
    hkStringMapDF6 m_kImports;
    hkArrayDF6<PairDF6> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapDF6 m_objectsWritten;
    hkStringMapDF6 m_classesWritten;
    SectionTableDF6 m_kSectionTable;
};
class hkMemoryAllocatorE4D;
struct hkMemoryRouterE4D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE4D* m_pStreamAllocator;
    hkMemoryAllocatorE4D& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE4D& __cdecl GetMemoryRouterE4D() throw();
struct hkContainerHeapAllocatorE4D
{
};
class hkReferencedObjectE4D
{
  public:
    hkReferencedObjectE4D()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectE4D();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <typename T> struct hkArrayE4D
{
    hkArrayE4D() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkPointerMapE4D
{
    hkPointerMapE4D() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        init(GetMemoryRouterE4D().heap(), 0);
    }
    void init(hkMemoryAllocatorE4D& kAlloc, int iNumElements);
    void insert(hkMemoryAllocatorE4D& kAlloc, const void* pvKey, int iValue);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapE4D
{
    hkStringMapE4D(hkContainerHeapAllocatorE4D kAlloc);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct hkPackfileSectionTableE4D
{
    hkPackfileSectionTableE4D();
};
struct hkClassE4D
{
};
extern hkClassE4D g_kClassAE4D;
extern hkClassE4D g_kClassBE4D;
extern hkClassE4D g_kClassCE4D;
class FUN_00dbe4d0 : public hkReferencedObjectE4D
{
  public:
    FUN_00dbe4d0() throw();
    virtual ~FUN_00dbe4d0();
    hkArrayE4D<void*> m_sections;
    hkPointerMapE4D m_kObjectNameMap;
    hkPointerMapE4D m_kObjectIndexMap;
    hkPointerMapE4D m_kClassMap;
    hkStringMapE4D m_kClassNameMap;
    hkStringMapE4D m_classNames;
    hkPointerMapE4D m_kObjectMap;
    hkArrayE4D<void*> m_pendingObjects;
    hkStringMapE4D m_kImports;
    hkArrayE4D<void*> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapE4D m_objectsWritten;
    hkStringMapE4D m_classesWritten;
    hkPackfileSectionTableE4D m_kSectionTable;
};
struct Mgr
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vf5();
};
extern Mgr* DAT_01268b08;
struct Cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vf3(void* a, void* b, void* r, void* c);
    void FUN_00dbda50(void* a, void* b, void* c);
};
struct S00dbddc0_Base
{
    int __thiscall GetOrAddString(int a);
};
struct S00dbddc0_Sub9C
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall LookupHashEntry(int a, int b);
};
struct S00dbddc0_SubA8
{
    int __thiscall GetValue(int a, int b);
};
struct S00dbddc0_Node
{
    int __thiscall FUN_00d46d40();
    S00dbddc0_Node* __thiscall FUN_00d46d50();
};
struct S00dbddc0_cls : public S00dbddc0_Base
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
    S00dbddc0_Sub9C m_sub9c;
    S00dbddc0_SubA8 m_suba8;

    int __thiscall FUN_00dbddc0(int a1, S00dbddc0_Node* a2, int a3);
};

struct TaggedName
{
    const char* tagged;
    const char* text() const
    {
        return (const char*)((unsigned int)tagged & ~1u);
    }
};
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
struct RigidBody
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    int field60, field64, field68, field6c, field70;
    TaggedName name;
};
struct Constraint
{
    int field00, field04, field08, field0c, field10;
    RigidBody* bodyA;
    RigidBody* bodyB;
};
struct Bone
{
    TaggedName name;
    int lockTranslation;
};
struct Skeleton
{
    int field00, field04, field08;
    short* parents;
    int field10, field14;
    Bone* bones;
    int boneCount;
};
struct Allocator
{
    virtual void ReportDiagnostic();
    virtual void* allocate(int) throw();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void deallocate(void*, int) throw();
};
struct StackRouter
{
    void* top;
    int field04, field08, field0c;
    Allocator* heap;
};
inline StackRouter* router()
{
    return (StackRouter*)FUN_00c85750();
}

int __cdecl FUN_00cb0fa0(const char*, const char*) throw();
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    void ClearAndRelease(Allocator& alloc)
    {
        size = 0;
        if ((capacity & (int)0x80000000) == 0)
            alloc.deallocate(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
    ~Array()
    {
        ClearAndRelease(*::router()->heap);
    }
};
template <class T> struct LocalArray : Array<T>
{
    T* initial;
    LocalArray(int count) throw()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
        StackRouter* router = ::router();
        T* allocated = (T*)router->top;
        router->top = (char*)allocated + ((count * sizeof(T) + 127) & ~127);
        data = allocated;
        capacity = count | 0x80000000;
        initial = allocated;
    }
    void clear()
    {
        size = 0;
    }
    T* getInitial() const
    {
        return initial;
    }
    static void resetStack(T* p)
    {
        ::router()->top = p;
    }
    static void resetStackRef(T* const& p)
    {
        ::router()->top = p;
    }
    ~LocalArray() throw()
    {
        if (initial == data)
            clear();
        resetStack(initial);
    }
    void AddBack(T value) throw()
    {
        StackRouter* router = ::router();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router->heap, this, sizeof(T));
        data[size++] = value;
    }
};
struct Message
{
    int field00, field04, field08;
    void __thiscall FUN_00cb1600(char*, int) throw();
    Message* __thiscall FUN_00cc01c0(const char*) throw();
    Message* __thiscall WriteName(const void*) throw();
    void __thiscall FUN_00cc00e0() throw();
    Message(char* buffer, int size) throw()
    {
        FUN_00cb1600(buffer, size);
    }
};
struct ErrorReporter
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void report(int, unsigned int, const char*, const char*, int) throw();
};
extern ErrorReporter* DAT_01268360;
struct Ragdoll
{
    void* vtable;
    unsigned short allocationSize;
    unsigned short references;
    Ragdoll* __thiscall FUN_00ce2510(Array<RigidBody*>*, Array<Constraint*>*, Skeleton*, Array<int>*) throw();
};
// @fnv 0x00cea810
Ragdoll* __cdecl FUN_00cea810(Skeleton* skeleton, const Array<RigidBody*>& bodies,
                              const Array<Constraint*>& constraints)
{
    int count = skeleton->boneCount;
    LocalArray<RigidBody*> matchedBodies(count);
    LocalArray<Constraint*> matchedConstraints(count - 1);
    LocalArray<int> boneToBody(count);
    char buffer[512];
    bool missingName = false;
    for (int i = 0; i < count; ++i)
    {
        Bone& bone = skeleton->bones[i];
        short parent = skeleton->parents[i];
        if (!(bone.name.text()))
        {
            missingName = true;
            break;
        }
        RigidBody* body = 0;
        for (int j = 0; j < bodies.size; ++j)
        {
            RigidBody* candidate = bodies.data[j];
            const char* name = candidate->name.text();
            if (name && FUN_00cb0fa0(name, bone.name.text()) == 0)
            {
                if (!body)
                    body = candidate;
                else
                {
                    Message message(buffer, 512);
                    message.FUN_00cc01c0("Some RBS have duplicated names : ")->FUN_00cc01c0((const char*)name);
                    DAT_01268360->report(1, 0xabba98aa, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x26b);
                    message.FUN_00cc00e0();
                }
            }
        }
        if (!body)
        {
            boneToBody.AddBack(-1);
            continue;
        }
        boneToBody.AddBack(matchedBodies.size);
        matchedBodies.AddBack(body);
        if (parent == -1)
            continue;
        RigidBody* parentBody = matchedBodies.data[boneToBody.data[parent]];
        Constraint* constraint = 0;
        for (int j = 0; j < constraints.size; ++j)
        {
            Constraint* candidate = constraints.data[j];
            RigidBody* a = candidate->bodyA;
            RigidBody* b = candidate->bodyB;
            if (a == body && b == parentBody)
            {
                if (!constraint)
                    constraint = candidate;
                else
                {
                    Message message(buffer, 512);
                    message.FUN_00cc01c0("Found more than one constraint between rigid bodies ")
                        ->FUN_00cc01c0((const char*)(a->name.text()))
                        ->FUN_00cc01c0(" and ")
                        ->FUN_00cc01c0((const char*)(b->name.text()));
                    DAT_01268360->report(1, 0xabba82ff, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x291);
                    message.FUN_00cc00e0();
                }
            }
        }
        if (!constraint)
        {
            Message message(buffer, 512);
            message.FUN_00cc01c0("Couldn't find constraint for bone : ")->WriteName(&bone);
            DAT_01268360->report(1, 0xabba9f9f, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x298);
            message.FUN_00cc00e0();
            return 0;
        }
        matchedConstraints.AddBack(constraint);
    }
    if (missingName)
    {
        {
            Message message(buffer, 512);
            message.FUN_00cc01c0("Some bones have no name - can't create rag doll");
            DAT_01268360->report(1, 0xabbae6a2, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x2a3);
            message.FUN_00cc00e0();
        }
        return 0;
    }
    if (!matchedBodies.size)
    {
        Message message(buffer, 512);
        message.FUN_00cc01c0("Skeleton has no associated rigid bodies - can't create rag doll");
        DAT_01268360->report(1, 0xabbae6e4, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x2aa);
        message.FUN_00cc00e0();
        return 0;
    }
    {
        Ragdoll* result = (Ragdoll*)::router()->heap->allocate(0x30);
        result->allocationSize = 0x30;
        result = result->FUN_00ce2510(&matchedBodies, &matchedConstraints, skeleton, &boneToBody);
        return result;
    }

    return 0;
}


// src/havok/common/serialize/data/native/hkdataobjectnative_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/data/native/hkdataobjectnative.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

void __stdcall FUN_00dbb610(int* p);
struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};
struct FUN_00dbb490_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    hkReferencedObject* m_8;
    void SetReferencedObject(hkReferencedObject* p);
};
struct FUN_00dbbb20_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    void* m_10;
    int __thiscall isValid(int a);
};
struct FUN_00d46f00_Class
{
    int __thiscall FUN_00d46f00();
};
struct FUN_00dbbc50_Class
{
    int __thiscall FUN_00dbbc50(int a);
};
struct FUN_00dbbc60_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int __thiscall FUN_00dbbc60(int a);
};
struct FUN_00d873b0_t
{
    int a;
    int b;
    FUN_00d873b0_t(int x, int y);
};
struct D481D0Class
{
    const char* __thiscall getName();
};
struct FUN_00dbb920_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    const char* __thiscall FUN_00dbb920();
};
struct TypeNode
{
    int FUN_00d46f70();
};
struct FUN_00dbb9d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int getNumDeclaredMembers();
};
struct hkDataArrayNative
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int GetElementAsInt(int index);
};
struct FUN_00dbbd70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    char* m_10;
    int m_14;
    int m_18;
    __int64 __thiscall GetEntry64(int a);
};
struct Shape
{
};
struct Container
{
    Shape const* __thiscall FUN_00d46f80(int) const;
};
struct FUN_00dbbfa0_Class
{
    int m_00;
    int m_04;
    int m_08;
    Container* m_0c;

    void __thiscall GetMemberInfo(Shape const*, int);
    void __thiscall getDeclaredMemberInfo(int, int);
};
struct FUN_00d46f20_Class
{
    int __thiscall FUN_00d46f20(int a, int b);
};
struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46f20_Class* m_0c;

    void SetInvocationResult(int result);
    void InvokeMemberFunction(int a, int b);
};
struct FUN_00dbc640_class;
struct FUN_00dbc640_allocator
{
// @fnv 0x00dbc640
    virtual void FUN_00dbc640_0()
    {}
    virtual void FUN_00dbc640_1()
    {}
    virtual void __thiscall FUN_00dbc640_2(FUN_00dbc640_class* p, unsigned short size);
};
struct FUN_00dbc640_router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0C;
    FUN_00dbc640_allocator* m_10;
};
FUN_00dbc640_router* _D1A0E0GetMemoryRouter();
struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void __thiscall FUN_00dbb3f0();

    FUN_00dbc640_class* __thiscall FUN_00dbc640(int flags);
};
FUN_00dbc640_class* FUN_00dbc640_class::FUN_00dbc640(int flags)
{
    this->FUN_00dbb3f0();

    if (flags & 1)
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        router->m_10->FUN_00dbc640_2(this, this->m_04);
    }

    return this;
}
struct Inner
{
    void Run();
};
struct FUN_00dbb930_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_pInner;
    void FUN_00dbb930();
};
struct FUN_00d47080_Class
{
    void __thiscall FindIndexByName();
};
struct FUN_00dbb9e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d47080_Class* unk0c;

    void __thiscall FUN_00dbb9e0();
};
struct FUN_00dbb9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46f00_Class* m_0C;
    void FUN_00dbb9f0();
};
struct FUN_00dbba00_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int __thiscall FUN_00d47030(int param_1);
    int __thiscall FUN_00dbba00(int param_1);
};
__int64 __stdcall FUN_00dbba40(int);
int __stdcall FUN_00dc9520(unsigned int arg0);
int __stdcall FUN_00dbb120(int arg0);
int __stdcall FUN_00dbb130(int a, int b);
struct FUN_00c90510_Obj : hkReferencedObject
{
    void FUN_00c90510();
};
struct FUN_00d87790_Result
{
    unsigned char value;
};
struct FUN_00d87790_Obj
{
    void __thiscall FUN_00d87790(FUN_00d87790_Result);
};
struct FUN_00dbb360_Global
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual FUN_00c90510_Obj* vf10();
    virtual FUN_00c90510_Obj* vf14();
};
extern FUN_00dbb360_Global* DAT_01268b08;
extern int DAT_010d6518[];
struct FUN_00dbb360_Class
{
    int m_00;
    unsigned short m_04, m_06;
    hkReferencedObject* m_08;
    hkReferencedObject* m_0C;
    FUN_00d87790_Obj m_10;
    int m_14, m_18, m_1C, m_20, m_24;
    FUN_00dbb360_Class* __thiscall Initialize();
};
class hkMemoryAllocatorDBB5
{
  public:
    virtual ~hkMemoryAllocatorDBB5() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBB5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB5* m_pStreamAllocator;

    hkMemoryAllocatorDBB5& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDBB5 {
extern "C" hkMemoryRouterDBB5& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB5
{
  public:
    virtual ~hkRefObjDBB5() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjDBB5() throw()
    {
        m_sReferenceCount = 0;
    }
    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB5* b = static_cast<hkRefObjDBB5*>(hkRouterDBB5::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class hkStringDBB5
{
  public:
    void FUN_00d873b0(const char* name, int len) throw();
    int unk00;
    int unk04;
};
class hkStringFnDBB5
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};
struct hkNameDescDBB5
{
    const char* m_name;
    int m_len;
};
class hkLibDBB5;
class hkResourceDBB5 : public hkRefObjDBB5
{
  public:
    int m_08;

    hkResourceDBB5() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB5() throw();
};
class hkNodeDBB5 : public hkResourceDBB5
{
  public:
    hkStringDBB5 m_name;
    hkLibDBB5* m_pOwnerObject;

    hkNodeDBB5() throw()
    {}
    virtual ~hkNodeDBB5() throw();
};
class hkNodeRefDBB5
{
  public:
    void FUN_00dba760(hkNodeDBB5* node) throw();
    hkNodeDBB5* m_node;
};
class hkLibDBB5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB5* m_pStringFunctions;

    hkNodeRefDBB5 CreateNode(const hkNameDescDBB5& desc);
};
struct hkErrorDBB7
{
    virtual ~hkErrorDBB7();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorDBB7* DAT_01268360;
struct hkOstreamDBB7
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamDBB7& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamDBB7& FUN_00cc0120(const void* pvPointer) throw();
};
struct FUN_00cb1600 : hkOstreamDBB7
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};
struct hkBoolDBB7
{
    char m_bValue;
    hkBoolDBB7() throw()
    {}
};
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};
struct hkClassDBB7 : FUN_00d46d40_s
{
    hkBoolDBB7 GetLastNodeFlag() const throw();
};
class hkVtableClassRegistryDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual hkClassDBB7* GetClassFromVirtualInstance(void* pvObject) throw();
};
class hkDataWorldNativeDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};
class hkDataObjectNativeDBB7
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    hkDataWorldNativeDBB7* m_pkWorld;
    hkVtableClassRegistryDBB7* m_pkVtableRegistry;
    int m_aiUnk10[4];
    void* m_pvObject;
    void* m_pkClass;

    hkDataWorldNativeDBB7* getWorld() const
    {
        return m_pkWorld;
    }
    void SetContents(void* pvObject, hkClassDBB7& kClass);
};
int __cdecl FUN_00cb0fa0(int, int);
struct hkBoolDBB9
{
    char m_cBooleanValue;
    hkBoolDBB9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
class hkNamedNodeDBB9
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual const char* getName() const throw();
    virtual void V3() throw();
    virtual hkNamedNodeDBB9* getNext() const throw();

    hkBoolDBB9 FUN_00dbb970(const hkNamedNodeDBB9* pkNode) const;
};
class hkHalf
{
  public:
    short m_uiFilterValue;
    hkHalf()
    {}
    hkHalf(float f)
    {
        int t = *(int*)&f;
        m_uiFilterValue = (short)(t >> 16);
    }
};
hkHalf __stdcall MakeZeroHalf(int a);
struct FUN_00d871a0_Data
{
    int memberData;
    int key;
    void FUN_00d871a0(void* value, int argument);
    const char* FUN_00d871e0(const int* argument);
};
struct FUN_00dbbae0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int hasMember(int argument);
};
class hkOwnerDBBB;
struct hkRefDBBB
{
    hkOwnerDBBB* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDBBB(hkOwnerDBBB* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};
class hkOwnerDBBB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8(int iKey);

    hkRefDBBB MakeRef(int iKey);
};
struct FUN_00dbbca0_class
{
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18, m_1c;
    float asReal(int index);
};
class hkMemoryAllocatorDBBD
{
  public:
    virtual ~hkMemoryAllocatorDBBD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBBD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDBBD* m_pStreamAllocator;
    hkMemoryAllocatorDBBD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDBBD& __cdecl FUN_00c85750();
struct hkClassMemberTypeDBBD
{
    int unk00;
    int unk04;
    short m_iElementCount;
};
hkClassMemberTypeDBBD* __cdecl FUN_00d868a0(int iType);
struct hkArrayBaseDBBD
{
    void* m_data;
    int m_iElementCount;
};
class FUN_00dbbb90
{
  public:
    virtual ~FUN_00dbbb90() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void* operator new(unsigned int nbytes)
    {
        FUN_00dbbb90* b = static_cast<FUN_00dbbb90*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00dbbb90(int iWorld, void* pvData, int iSize, int iStride, int iType, int m_iMenuId, int iTupleCount) throw();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
class hkDataObjectNativeDBBD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_pOwningWorld;
    char* m_data;
    int unk14;
    int m_iElementIndex;
    int m_type;
    int m_class;
    int unk24;
    int m_iFlags;

    FUN_00dbbb90* GetElement(int iIndex);
};
struct FUN_00d46f20_Map
{
    int* FUN_00d46f20(int iKey);
};
struct FUN_00dbbe30_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d46f20_Map* m_map;

    int GetValueForKey(int iKey);
};
enum hkTypeDBC3
{
    TYPE_POINTER = 0x1d,
    TYPE_FLAGS = 0x21
};
struct hkClassMemberDBC3
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    hkTypeDBC3 getType() const
    {
        return (hkTypeDBC3)m_type;
    }
};
class hkVariantDBC3
{
  public:
    int unk00;
    int unk04;

    hkVariantDBC3(void* obj, void* name) throw()
    {
        FUN_00d871a0(obj, name);
    }
    void FUN_00d871a0(void* obj, void* name) throw();
    hkClassMemberDBC3* FUN_00d87370() throw();
    unsigned int* FUN_00d87220(int i) throw();
    unsigned int* FUN_00d87230(int i) throw();
};
class hkObjDBC3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char m_data[4];

    unsigned int GetMemberValue(void* name);
};
struct FUN_00c85750_Result
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    class FUN_00dba490_heap* m_10;
};
struct FUN_00c85750_Class
{
    int __thiscall FUN_00c85750();
};
class FUN_00dba490_heap
{
  public:
    virtual void h_slot0();
    virtual void h_slot1();
    virtual void h_slot2();
    virtual void h_slot3();
    virtual void h_freeBlock(int param, int size);
};
struct FUN_00dba490_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;

    void FUN_00dba490();
};
class hkMemoryAllocatorDBB6
{
  public:
    virtual ~hkMemoryAllocatorDBB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBB6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB6* m_pStreamAllocator;

    hkMemoryAllocatorDBB6& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDBB6 {
extern "C" hkMemoryRouterDBB6& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB6
{
  public:
    virtual ~hkRefObjDBB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjDBB6() throw()
    {
        m_sReferenceCount = 0;
    }
    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB6* b = static_cast<hkRefObjDBB6*>(hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class hkStringDBB6
{
  public:
    void FUN_00d873d0(const hkStringDBB6& other) throw();
    int unk00;
    int unk04;
};
class hkStringFnDBB6
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};
struct hkNameDescDBB6
{
    const char* m_name;
    int m_len;
};
class hkLibDBB6;
class hkResourceDBB6 : public hkRefObjDBB6
{
  public:
    int m_08;

    hkResourceDBB6() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB6() throw();
};
class hkNodeDBB6 : public hkResourceDBB6
{
  public:
    hkStringDBB6 m_name;
    hkLibDBB6* m_pOwnerObject;

    hkNodeDBB6() throw()
    {}
    virtual ~hkNodeDBB6() throw();
};
class hkNodeRefDBB6
{
  public:
    void FUN_00dba760(hkNodeDBB6* node) throw();
    hkNodeDBB6* m_node;
};
class hkLibDBB6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB6* m_pStringFunctions;

    int unk10[4];
    hkStringDBB6 m_name;

    hkNodeRefDBB6 FUN_00dbb620();
};
float __stdcall FUN_00dbba10(void* pArg);
struct FUN_00d470f0_Obj
{
    unsigned char* __thiscall GetLastNodeFlag(unsigned char* flag);
};
struct HKDBB50Handle
{
    void* m_pObject;
    int m_iClass;
};
struct FUN_00dbba50_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00d470f0_Obj* m_10;

    HKDBB50Handle* __thiscall GetHandle(HKDBB50Handle* __restrict handle);
};
struct FUN_00d871a0
{
    int m_00;
    int m_04;
    FUN_00d871a0(void* pair, int x);
    void* FUN_00d87200();
};
struct FUN_00dbbb60_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void* __thiscall FUN_00dbbb60(int a, int b);
};
struct ComponentDescDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
};
struct StreamDBC5C0;
struct AccessorDBC5C0
{
    AccessorDBC5C0(StreamDBC5C0* pkStream, int iIndex);
    const ComponentDescDBC5C0* GetDesc();
    const float* FUN_00d87250(int iComponent);
    const short* FUN_00d87260(int iComponent);
    int m_iA;
    int m_iB;
};
struct StreamDBC5C0
{
    int unk00;
};
struct VertexDataDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    StreamDBC5C0 m_kVertexStream;
    float GetFloat(int iIndex);
};

extern const char str_010d64dc[];
extern const char str_010d64d0[];
extern const char str_010d64bc[];
extern const char str_010d6394[];
extern char DAT_010d6334[];

struct S00dbb260_Args;
struct S00dbb260_World;

struct S00dbb260_Rec
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46d40_s* unk0C;
};

struct S00dbb260_World
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual S00dbb260_Rec* vf24(const char* name);
};

struct S00dbb260_Args
{
    int objId;
    FUN_00d46d40_s* cls;
};

struct S00dbb260_Sub
{
    int unk00;
    int unk04;
    void __thiscall FUN_00d873d0(S00dbb260_Args* args);
};

struct S00dbb260_Result
{
    int vt;
    unsigned short size;
    unsigned short unk06;
    int unk08;
    S00dbb260_Sub sub;
    S00dbb260_World* world;
};

struct S00dbb260_W : FUN_00cb1600
{
    S00dbb260_W(char* b, int s) : FUN_00cb1600(b, s)
    {}
    S00dbb260_W& FUN_00cc01c0(const char* a, int b, const char* c, const char* d, const char* e);
    S00dbb260_W& FUN_00cc01c0();
    S00dbb260_W& FUN_00cc0120();
};

// @fnv 0x00dbb260
static __declspec(noinline) S00dbb260_Result* FUN_00dbb260(S00dbb260_Args* args, S00dbb260_World* world)
{
    if (!!args->cls)
    {
        S00dbb260_Rec* a;
        a = world->vf24(args->cls->FUN_00d46d40());
        if ((bool)a)
        {
            args->cls = a->unk0C;
        }
        else
        {
            char j[0x200];
            S00dbb260_W writer(j, 0x200);
            writer.FUN_00cc01c0(str_010d64bc, args->objId, str_010d64d0, args->cls->FUN_00d46d40(), str_010d64dc)
                .FUN_00cc0120()
                .FUN_00cc01c0()
                .FUN_00cc01c0()
                .FUN_00cc01c0();
            DAT_01268360->message(1, 0x1800473A, j, str_010d6394, 0x2C7);
            writer.FUN_00cc00e0();
            args->objId = 0;
            args->cls = 0;
        }
    }
    S00dbb260_Result* rec;
    rec = (S00dbb260_Result*)FUN_00c85750().heap().AllocateMemoryBlock(0x18);
    rec->size = 0x18;
    rec->unk06 = 0;
    rec->unk08 = 0;
    rec->vt = (int)DAT_010d6334;
    rec->sub.FUN_00d873d0(args);
    rec->world = world;
    return rec;
}

S00dbb260_Result* S00dbb260_Entry(S00dbb260_Args* a, S00dbb260_World* w)
{
    return FUN_00dbb260(a, w);
}

typedef hkClassDBB7 TypeDBC;
struct PairDBC
{
    void* object;
    TypeDBC* type;
    void FUN_00d873d0(const PairDBC& other);
};
struct ClassLookupDBC
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual TypeDBC* lookup(void* object);
};
struct WorldDBC
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual TypeDBC* find(const char* name);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual WorldDBC* findObjectType(const char* name);
    int unk04;
    int unk08;
    TypeDBC* type;
};
extern const char DAT_010d6394[];
extern const char DAT_010d63bc[];
extern const char DAT_010d63f8[];
extern const char DAT_010d6400[];
extern const char DAT_010d64bc[];
extern const char DAT_010d64d0[];
extern const char DAT_010d64dc[];

struct ResultDBC
{
    void* object;
    TypeDBC* type;
};
static __declspec(noinline) ResultDBC FUN_00dbb140(TypeDBC* type, void* object, ClassLookupDBC* lookup, WorldDBC* world)
{
    ResultDBC result = {0, 0};
    if (type && object)
    {
        if (type->GetLastNodeFlag().m_bValue)
        {
            TypeDBC* actual = lookup->lookup(object);
            TypeDBC* found = actual ? world->find(actual->FUN_00d46d40()) : 0;
            result.type = found;
            result.object = found ? object : 0;
            if (!found)
            {
                char buffer[512];
                FUN_00cb1600 stream(buffer, 512);
                stream.FUN_00cc01c0(DAT_010d63bc)
                    .FUN_00cc01c0(type->FUN_00d46d40())
                    .FUN_00cc01c0(DAT_010d63f8)
                    .FUN_00cc0120(object)
                    .FUN_00cc01c0(DAT_010d6400);
                DAT_01268360->message(1, 0x3476d70f, buffer, DAT_010d6394, 0x37);
                stream.FUN_00cc00e0();
            }
        }
        else
        {
            result.object = object;
            result.type = type;
        }
    }
    return result;
}
class NativeDBC : public hkRefObjDBB6
{
  public:
    int zero;
    PairDBC value;
    WorldDBC* world;
    NativeDBC(const PairDBC& p, WorldDBC* w) : zero(0), world(w)
    {
        value.FUN_00d873d0(p);
    }
};
static __declspec(noinline) NativeDBC* FUN_00dbb260(WorldDBC* world, PairDBC* value)
{
    if (value->type)
    {
        WorldDBC* found = world->findObjectType(value->type->FUN_00d46d40());
        if (found)
            value->type = found->type;
        else
        {
            char buffer[512];
            FUN_00cb1600 stream(buffer, 512);
            stream.FUN_00cc01c0(DAT_010d64bc)
                .FUN_00cc0120(value->object)
                .FUN_00cc01c0(DAT_010d64d0)
                .FUN_00cc01c0(value->type->FUN_00d46d40())
                .FUN_00cc01c0(DAT_010d64dc);
            DAT_01268360->message(1, 0x1800473a, buffer, DAT_010d6394, 0x2c7);
            stream.FUN_00cc00e0();
            value->object = 0;
            value->type = 0;
        }
    }
    return new NativeDBC(*value, world);
}
struct DescriptorDBC
{
    int unk00;
    int unk04;
    WorldDBC* world;
    ClassLookupDBC* lookup;
};
struct ArrayDBC
{
    int unk00;
    int unk04;
    int unk08;
    DescriptorDBC* descriptor;
    char* data;
    int unk14;
    int stride;
    int type;
    TypeDBC* pClassInfo;
    NativeDBC* asObject(int index);
};
// @fnv 0x00dbc000
NativeDBC* ArrayDBC::asObject(int index)
{
    PairDBC value = {0, 0};
    unsigned high = 0;
    switch (type)
    {
    case 20: {
        ResultDBC v = FUN_00dbb140(pClassInfo, *(void**)(data + stride * index), descriptor->lookup, descriptor->world);
        value.object = v.object;
        high = (unsigned)v.type;
        break;
    }
    case 25: {
        ResultDBC v = FUN_00dbb140(pClassInfo, data + stride * index, descriptor->lookup, descriptor->world);
        value.object = v.object;
        high = (unsigned)v.type;
        break;
    }
    case 28:
        value = *(PairDBC*)(stride * index + data);
        high = (unsigned)value.type;
        break;
    default:
        return 0;
    }
    value.type = (TypeDBC*)high;
    if (value.object && value.type)
        return FUN_00dbb260((WorldDBC*)descriptor, &value);
    return 0;
}

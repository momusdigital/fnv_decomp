
// src/staging/blk_00a40000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a40000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __fastcall FUN_00a36890(void*);
extern int DAT_0109750c;
struct FUN_00a409b0_class
{
    void* vtbl;
    FUN_00a409b0_class();
};
void __fastcall FUN_00a36890(void*);
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
void* __cdecl FUN_00a409d0();
float FUN_00a42050(float a, float b, float c);
void __fastcall FUN_00a36890(void*);
extern int DAT_01097904;
struct FUN_00a42f60
{
    void* m_pVTable;
    char m_auiShapeKeys[0x2C];
    float m_f;
    FUN_00a42f60();
};
struct CloningProcess;
struct NiObject
{
    void CopyMembersStream(unsigned int, void*);
};
struct FUN_00a44850_holder : NiObject
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_p;
    float m_f;
    void CopyMembersStreamAndFields(FUN_00a44850_holder* dst, CloningProcess* proc);
};
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct Map_00a4da90
{
    void FUN_00a4d660();
    void* ReleaseIfFlagged(int);
};
void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00a51af0_class
{
    void* __thiscall FUN_00a51af0(unsigned char flags);
};
extern int DAT_0109a264;
extern int DAT_0109a284;
struct NiTMapBaseStub
{
    void RemoveAll();
};
void __cdecl NiFreeAlias(void*);
struct FUN_00a540a0 : NiTMapBaseStub
{
    int vtbl;
    int pad;
    void* p;
    void Init();
};
extern "C" char* __cdecl _strcat_s(char* destination, unsigned int destinationSize, const char* source);
char* __cdecl SafeStrcat(char* destination, unsigned int destinationSize, const char* source);
extern const char* _EmptyFS;
struct FUN_00a57870_Class
{
    int m_iWordAt00;
    const char* m_cByteAtOffset1;
    void ReleaseString();
};
void* __cdecl FUN_00a42f90();
struct FUN_00a4d6d0_class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    unsigned int __thiscall HashStringModulo(const char* s);
};
extern "C" void NiFree(void*);
extern MemoryManager _g_memoryManager;
extern int DAT_01098ec8;
struct FUN_00a4d700_class : NiTMapBaseStub
{
    void* m_pVTable;
    int pad;
    void* m_p;
    void* __thiscall FUN_00a4d700(unsigned char flags);
};
extern int DAT_010997f4;
struct BaseHolder
{
    void FUN_00a57f20(int, int);
};
void* __cdecl FUN_00a50ad0();
void __fastcall _Call_a5d3a0(void*);
extern int DAT_01099e54;
void* __cdecl FUN_00a51e10();
void* __cdecl NiMalloc(unsigned int);
void* __cdecl fnv_zlib_memset(void* dst, void* src, unsigned int size);
struct FUN_00a54060_class : NiTMapBaseStub
{
    int m_vtbl;
    int m_iElementCount;
    void* m_data;
    void* m_p;
    void* InitBuffer(unsigned int size);
};
struct FUN_00a540d0_class : NiTMapBaseStub
{
    int vtbl;
    int pad;
    void* p;
    void* __thiscall FUN_00a540d0(unsigned char flags);
};
extern int DAT_0109a2a4;
extern MemoryManager g_memoryManager;
void __cdecl NiFree(void*);
struct FUN_00a54160_class
{
    void* vtbl;
    void* p;
    void* __thiscall FUN_00a54160(unsigned char flags);
};
void __cdecl FUN_00a57500(NiFixedString*);
void __cdecl FUN_00a76960(void*, void*);
struct NiFixedString
{
    const char* m_kHandle;
};
struct FUN_00a5fba0_class
{
    void __thiscall FUN_00a5fba0(const NiFixedString* kFilename);
};
unsigned int __stdcall FUN_00a5b270(const char* s, unsigned int len);
extern "C" unsigned int __cdecl _strcpy_s(char* dst, unsigned int size, const char* src);
void __cdecl _fnv_StandardizeFilePath(char*);
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
};
void __cdecl FUN_00a57500(NiFixedString* k);
extern int DAT_0109b00c;
struct FUN_004a4650_ListBase
{
    void FUN_004a4650();
};
struct FUN_00a5a390_shell
{
    void FUN_00a5a390();
    void DestroyFogProperty();
};
extern char DAT_010976ec;
struct FUN_00a414c0_class
{
    void* m_pVTable;
    void* m_p;
    FUN_00a414c0_class* __thiscall FUN_00a414c0(unsigned char flags);
};
extern int DAT_010976fc;
struct A51BF0Base
{
    static void* operator new(unsigned int);
};
struct A51BF0
{
    void* vtbl;
    int pad;
    int a;
    int b;
    int c;
    bool d;
    void FUN_00a5d3a0();
};
A51BF0* CreateA51BF0();
float FUN_00a42070(float param_1, float param_2, float param_3, float param_4, float param_5);
struct FUN_00a44f90_class
{
    void* vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    float m_38;
    float m_3c;
    float m_40;
    float m_44;
    char m_48;
    char m_49;
    char m_4a;
    char m_4b;
    FUN_00a44f90_class();
};
extern int DAT_01097f84;
extern int DAT_01098ee8;
void __cdecl _NiFree(void*);
struct FUN_00a4d740_class
{
    void* m_pVTable;
    int m_auiShapeKeys;
    void* m_p;
    void* __thiscall DestroyAndFree(unsigned int flags);
};
struct FUN_00a57890_shell
{
    void* m_iWordAt00;
    const char* m_cByteAtOffset1;
    void __thiscall AssignStringRef(const char** s);
};
extern int DAT_011f4500;
extern int DAT_011f4504;
extern char DAT_011f4580;
struct CRITICAL_SECTION_STUB
{
    int a;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_STUB*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_STUB*);
void __fastcall FUN_00a5f7b0(int param_1);
struct ControllerAllocation
{
    ControllerAllocation* FUN_00a40520(void* target, float value, unsigned int flags);
};
ControllerAllocation* __stdcall FUN_00a411c0(unsigned int ReportDiagnostic, void* target, unsigned int unused2,
                                             float value, unsigned int flags);
struct FUN_00a413d0_pair
{
    unsigned int m_key0;
    unsigned int m_key1;
};
struct FUN_00a413d0_cls
{
    unsigned int m_unk00;
    FUN_00a413d0_pair** m_ppItems;
    unsigned short m_unk08;
    unsigned short m_uiItemCount;
    int FindPairIndex(unsigned int key0, unsigned int key1);
};
class HandlerObject
{
  public:
    virtual void unk00();
    virtual void Handle(void* pArg);
};
struct HandlerEntry
{
    unsigned int m_key;
    HandlerObject* m_pEntryObject;
};
struct HandlerArg
{
    int unk00;
    int unk04;
    unsigned int m_key;
};
class FUN_00a41410_cls
{
  public:
    int unk00;
    HandlerEntry** m_ppEntries;
    unsigned short unk08;
    unsigned short m_uiItemCount;

    void DispatchByKey(HandlerArg* a1);
};
struct S_00a42290_Mem
{
    static void* operator new(unsigned int);
};
struct FUN_00a5d3a0 : S_00a42290_Mem
{
    int unk04;
    FUN_00a5d3a0() throw();
    virtual ~FUN_00a5d3a0() throw();
};
struct S_00a42290_Q : FUN_00a5d3a0
{
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    S_00a42290_Q() throw() : unk08(0), unk0c(0), unk10(0), unk14(false)
    {}
    virtual ~S_00a42290_Q() throw()
    {}
    void FUN_00a3ccb0(void* a, unsigned int b, int c);
};
struct S_00a42290_Ptr
{
    S_00a42290_Q* p;
    S_00a42290_Ptr& FUN_0066b0d0(S_00a42290_Q* q);
};
struct S_00a42290_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00a42290_Ptr m10;
    int unk14;
    void FUN_00a42290(void* a, unsigned int b, int c);
};
class A42380RefObject
{
  public:
    virtual ~A42380RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
class A42380Owner
{
  public:
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
    NiPointer<A42380RefObject> m_spTransformData;

    void FUN_00a42380(A42380RefObject* pkData);
};
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
extern const NiRTTI NiNodeRTTI_a42b70;
extern const NiRTTI CtrlRTTI_A_a42b70;
extern const NiRTTI CtrlRTTI_B_a42b70;
extern const NiRTTI CtrlRTTI_C_a42b70;
struct StubNiObject
{
    virtual void Slot00();
    virtual void Slot01();
    virtual const NiRTTI* GetRTTI() const;
    virtual void* IsSceneNode();
};
struct StubController : StubNiObject
{
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
    StubController* m_pkNext;
};
struct StubAVObject;
struct StubChildArray
{
    void* m_pVTable;
    StubAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};
struct StubAVObject : StubNiObject
{
    int unk04;
    int unk08;
    StubController* m_pControllers;
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
    StubChildArray m_kChildList;
};
static inline bool IsKindOfRTTI(const NiRTTI* pkTarget, const StubNiObject* pkObj)
{
    for (const NiRTTI* r = pkObj->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == pkTarget)
            return true;
    return false;
}
void __cdecl FUN_00a427e0(StubController* p);
void __cdecl CreateInterpolator(StubController* p);
void __cdecl ConvertLegacyController(StubController* p);
void __cdecl FUN_00a42b70(void* pArg, StubAVObject* pkObject);
extern int DAT_011f4304;
struct FUN_00a42c80_virtual
{
    virtual void f00();
    virtual void f01();
    virtual int* f02();
};
void __cdecl FUN_00a42b70(void* a1, void* a2);
void __cdecl FUN_00a42c80(int* param1, FUN_00a42c80_virtual* param2);
struct FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_base();
};
struct FUN_00a42f80_cls : FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_cls();
};
struct FUN_00a44830_base
{
    virtual ~FUN_00a44830_base();
};
struct FUN_00a44830_cls : FUN_00a44830_base
{
    virtual ~FUN_00a44830_cls();
};
extern "C" void _NiFreeAlias(void*);
extern "C" void __cdecl ReleaseObjectArray(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefItem
{
    virtual void unused() throw();
    virtual void Release() throw();
    volatile long count;
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};
struct SP
{
    RefItem* value;
    ~SP() throw()
    {
        if (value)
            value->DecRefCount();
    }
    SP& operator=(RefItem* p) throw()
    {
        if (value)
        {
            value->DecRefCount();
            value = 0;
        }
        return *this;
    }
};
struct RawArray
{
    virtual ~RawArray() throw()
    {
        _NiFreeAlias(data);
    }
    void** data;
    unsigned short maxSize, size, used, grow;
    void* RemoveAt(unsigned i) throw()
    {
        if (i >= size)
            return 0;
        void* p = data[i];
        data[i] = 0;
        if (p)
            --used;
        if (i == (unsigned short)(size - 1))
            --size;
        return p;
    }
};
struct RefArray
{
    virtual ~RefArray() throw()
    {
        ReleaseObjectArray(data);
    }
    SP* data;
    unsigned short maxSize, size, used, grow;
    SP FUN_00a47540(unsigned) throw();
};
struct NiRefObjectStandIn
{
    virtual void unused();
    int count;
    ~NiRefObjectStandIn() throw();
};
struct FUN_00a478f0 : NiRefObjectStandIn
{
    void* raw;
    RawArray rawArray;
    RefArray refArray;
    SP reference;
    virtual void unused();
    ~FUN_00a478f0() throw();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int DAT_0109893c;
struct RefObject
{
    virtual void GetRTTI();
    virtual void DeleteThis();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};
struct RefPointer
{
    RefObject* object;
    void Clear()
    {
        if (object)
        {
            object->DecRefCount();
            object = 0;
        }
    }
    void Release()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ParentData
{
    void* vtable;
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    void FUN_00a6d290();
};
void __cdecl FUN_00aa10f0(void*);
struct FUN_00a49d60 : public ParentData
{
    RefPointer first;
    RefPointer second;
    void* resource;
    ~FUN_00a49d60();
};
struct FUN_00a53c90_Node
{
    FUN_00a53c90_Node* m_pNext;
    unsigned int m_uiKey;
    unsigned char m_ucFlag;
};
class FUN_00a53c90_cls
{
  public:
    virtual void* vSlot0();
    virtual unsigned int vSlot1(unsigned int key);
    unsigned int m_uiCount;
    FUN_00a53c90_Node** m_ppItems;
    void GetNextEntry(FUN_00a53c90_Node** ppCur, unsigned int* pKey, unsigned char* pFlag);
};
extern void* __cdecl FUN_00aa1070(unsigned int size);
struct FUN_00a54110
{
    int* pBuffer;
    unsigned int reservedSize;
    unsigned int size;

    FUN_00a54110(unsigned int count);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObject572
{
  public:
    virtual ~NiRefObject572() throw();
    virtual void DeleteThis() throw();

    void DecRefCount() throw()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointer572
{
  public:
    ~NiPointer572() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
extern const char* g_pcNullString572;
class NiFixedString572
{
  public:
    ~NiFixedString572() throw()
    {
        if (m_kHandle != g_pcNullString572)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    const char* m_kHandle;
};
class NiObjectBase572
{
  public:
    virtual ~NiObjectBase572() throw();

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
};
class FUN_00a572d0 : public NiObjectBase572
{
  public:
    virtual ~FUN_00a572d0() throw();

    NiPointer572<NiRefObject572> m_spFirst;
    NiFixedString572 m_kName;
    NiPointer572<NiRefObject572> m_spSecond;
};
struct FUN_00a57580_cls
{
    int m_iWordAt00;
    int m_uiItemCount;
    int(__cdecl* m_fn)(FUN_00a57580_cls*, int, int, int*, int);
};
int __cdecl InvokeAndAccumulate(FUN_00a57580_cls* p, int v);
struct FUN_00a575b0_Object
{
    void* unk00;
    int unk04;
    int(__cdecl* unk08)(void*, int, int, int*, int);
};
void __cdecl FUN_00a575b0(FUN_00a575b0_Object* object, int value);
struct FUN_00a59c60_target
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
    virtual void v9();
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
};
class FUN_00a59c60_cls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(int a, int b);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00a59c60_target* m_18;
    void FUN_00a59c60(int a1);
};
struct SingletonTarget
{
    void __thiscall FUN_00a5b3c0();
};
extern SingletonTarget* g_011f42c0;
void __cdecl FUN_00a5b460();
extern void __cdecl FUN_00aa10f0(char* psz);
extern int DAT_0102102c;
struct Ent
{
    void* m_f0;
    char* m_str;
    int m_unk8;
    int m_unkC;
};
inline char* GetStr(Ent* e)
{
    return e->m_str;
}
struct CSImpl
{
    void* m_iFourthElementInteger[6];
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CSImpl* pcs);
struct FUN_00a5b470_cls
{
    int m_pad4;
    int m_pad8;
    int m_padC;
    Ent m_entries[0x200];
    char m_gap[0x74];
    CSImpl m_cs;
    void ResetEntries();
};
__declspec(dllimport) void __stdcall InitializeCriticalSection(void* pkSection);
extern int g_iA5B530Default;
struct A5B530Entry
{
    int* m_piSource;
    int m_iValue;
    short m_sA;
    short m_sB;
    short m_sC;
    short m_sCount;

    A5B530Entry()
    {
        m_sA = 0;
        m_sCount = 1;
        m_sB = 0;
        m_sC = 0;
        m_iValue = 0;
        m_piSource = &g_iA5B530Default;
    }
};
struct A5B530CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class FUN_00a5b530
{
  public:
    A5B530Entry m_akEntries[0x201];
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    A5B530CriticalSection m_kLock;

    FUN_00a5b530();
};
class A5B660Heap
{
  public:
    void Deallocate(void* pvMem);
};
class A5B660StringTable
{
  public:
    ~A5B660StringTable();

    static void operator delete(void* pvMem)
    {
        reinterpret_cast<A5B660Heap&>(g_memoryManager).Deallocate(pvMem);
    }

    static A5B660StringTable* ms_pStringTable;

    static void FUN_00a5b660();
};
struct FUN_00a5b870_cls
{
    int unk00;
    unsigned short* m_pData;
    unsigned short unk08;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    void __thiscall SetEntry(unsigned int index, unsigned short* value);
};
struct A5D2C0CloningProcess;
class A5D2C0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
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
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual A5D2C0Object* MakeClone(A5D2C0CloningProcess& kCloning);
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void ProcessClone(A5D2C0CloningProcess& kCloning);

    A5D2C0Object* FUN_00a5d2c0(A5D2C0CloningProcess& kCloning);
};
// NiRefObject
class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    static long ms_lObjectCount;
};
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern int DAT_0109b5ac;
extern int DAT_0101fbd4;
struct NiObjectBase
{
    void __thiscall FUN_00a5aa20();
};
struct ObjectState
{
    void* reference;
    unsigned int count;
    unsigned short first;
    unsigned short second;
    unsigned short third;
    unsigned short enabled;
};
NiObjectBase* __cdecl FUN_00a5f030();
// Constructor of a derived object: base ctor call, then a 16-bit field and the vtable pointer.
extern int DAT_0109b72c;
struct FUN_00a5f1e0_cls
{
    void* m_pVTable;       // +0x00
    int m_i04;             // +0x04
    int m_i08;             // +0x08
    int m_i0C;             // +0x0C
    int m_i10;             // +0x10
    unsigned short m_w14;  // +0x14
    unsigned short m_w16;  // +0x16
    unsigned short m_w18;  // +0x18

    void Init();  // base constructor (external)

    FUN_00a5f1e0_cls();
};
class A5F4D0Property
{
  public:
    A5F4D0Property();
    virtual ~A5F4D0Property();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class FUN_00a5f4d0 : public A5F4D0Property
{
  public:
    unsigned short m_usFlags;

    FUN_00a5f4d0();
    virtual ~FUN_00a5f4d0();
};
struct CountedRef
{
    virtual void Vslot00(int flags);
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern int DAT_0109b9ec;
extern int DAT_0109b944;
extern int DAT_0109b220;
struct FUN_00a5fca0_cls
{
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    CountedRef* m_24;
    int unk28, unk2C;
    int m_30;
    int m_34;
    CountedRef* m_38;
    CountedRef* m_3c;

    void FUN_00a5f800();
    void DestroyFogProperty();
    void FUN_00a5fca0();
};
// Destructor of an owning pointer array: remove and free every element, then the base frees the storage.
class A1450MemoryManager
{
  public:
    void Deallocate(void* pvMem) throw();
};
extern A1450MemoryManager g_kA1450MemoryManager;
void __cdecl A1450NiFree(void* pvMem);
struct A1450Element
{
    int unk00;

    static void operator delete(void* pvMem)
    {
        g_kA1450MemoryManager.Deallocate(pvMem);
    }
};
class A1450Array
{
  public:
    virtual ~A1450Array()
    {
        A1450NiFree(m_pBase);
    }

    A1450Element* RemoveEnd()
    {
        if (m_usSize == 0)
            return 0;
        m_usSize--;
        A1450Element* pkElement = m_pBase[m_usSize];
        m_pBase[m_usSize] = 0;
        if (pkElement)
            m_usESize--;
        return pkElement;
    }

    A1450Element** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class A1450OwnedArray : public A1450Array
{
  public:
    void ClearAndDestroy();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class FUN_00a423f0_cls
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    NiRefObject* m_pObject;

    void FUN_00a423f0(NiRefObject* obj);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern const NiRTTI DAT_011f36ec;
struct ConvertedController;
struct ControllerInterpolator;
struct ControllerHost
{
    ConvertedController* FUN_00a5c570(const NiRTTI*);
    void FUN_00a5c000(ConvertedController*);
    void FUN_00a5c480(StubController*);
};
struct ControllerFields
{
    virtual void Slot00();
    virtual void DeleteThis() throw();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void SetTarget(ControllerHost*);
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Update();
    virtual void Slot48();
    virtual void* GetInterpolator(unsigned int);
    virtual void SetInterpolator(ControllerInterpolator*, unsigned int);
    unsigned int refCount;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float startTime;
    float stopTime;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&refCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement((volatile long*)&refCount))
            DeleteThis();
    }
};
struct ConvertedController : ControllerFields
{
    NiPointer<ConvertedController> next;
    ConvertedController* FUN_00a36560();
};
struct ControllerInterpolator : ControllerFields
{
    unsigned short cycle;
    unsigned short unk32;
    int unk34;
    int data;
    ControllerInterpolator* FUN_00a3f060(void*, void*);
    void UpdateIfFlagged();
    void SetFlag1(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= (unsigned short)~2;
    }
    void SetFlag2(bool value)
    {
        if (value)
            flags |= 4;
        else
            flags &= (unsigned short)~4;
    }
    void SetFlag3(bool value)
    {
        if (value)
            flags |= 8;
        else
            flags &= (unsigned short)~8;
    }
    void SetFlag5(bool value)
    {
        if (value)
            flags |= 32;
        else
            flags &= (unsigned short)~32;
    }
    void SetFlag6(bool value)
    {
        if (value)
            flags |= 64;
        else
            flags &= (unsigned short)~64;
    }
    void SetFlag4(bool value)
    {
        if (value)
            flags |= 16;
        else
            flags &= (unsigned short)~16;
        if (value)
            UpdateIfFlagged();
    }
};
struct LegacyController : StubController
{
    unsigned short flags;
    unsigned short unk36;
    int unk38;
    int unk3c;
    void* firstData;
    void* secondData;
    int unk48;
    int unk4c;
    float startTime;
    float stopTime;
    unsigned short cycle;
    unsigned short unk5a;
    int unk5c;
    int data;
    bool Flag1() const
    {
        return (flags >> 1) & 1;
    }
    bool Flag2() const
    {
        return (flags >> 2) & 1;
    }
    bool Flag3() const
    {
        return (flags >> 3) & 1;
    }
    bool Flag4() const
    {
        return (flags >> 4) & 1;
    }
    bool Flag5() const
    {
        return (flags >> 5) & 1;
    }
    bool Flag6() const
    {
        return (flags >> 6) & 1;
    }
};
void __cdecl CopyControllerSettings(StubController*, ConvertedController*);
void __cdecl ConvertLegacyController(StubController* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RTT
{
    const char* name;
    const RTT* base;
};
extern RTT g_011f3f38, g_011f3f28, g_011f4a38, g_011f36ec;
struct Obj
{
    virtual void slot0() throw();
    virtual void DeleteThis() throw();
    virtual const RTT* GetType() const throw();
    volatile long refs;
    const char* name;
    Obj* controller;
    Obj** extras;
    unsigned short count;
    unsigned short capacity;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Obj* next;
    Obj* Cast(const RTT*) throw();
    bool FUN_00a5bf50(unsigned short) throw();
    void ClearExtraData() throw();
    void Inc() throw()
    {
        InterlockedIncrement(&refs);
    }
    void Dec() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
inline bool IsKind(const RTT* type, const Obj* object) throw()
{
    for (const RTT* r = object->GetType(); r; r = r->base)
        if (r == type)
            return true;
    return false;
}
inline Obj* CastInline(const RTT* type, Obj* object) throw()
{
    if (!object)
        return 0;
    return (int)IsKind(type, object) ? object : 0;
}
struct Ptr
{
    Obj* p;
    Ptr(Obj* q) throw() : p(q)
    {
        if (p)
            p->Inc();
    }
    ~Ptr() throw()
    {
        if (p)
            p->Dec();
    }
    void operator=(Obj* q) throw()
    {
        if (p != q)
        {
            if (p)
                p->Dec();
            p = q;
            if (p)
                p->Inc();
        }
    }
};
struct Result
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
    static void* operator new(unsigned int) throw();
    Result(const char*, int, int) throw();
    void FUN_00a47420(Obj*) throw();
    void AddSeq(void*, Obj*) throw();
};
struct Stream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    Obj** objects;
    unsigned int unk224;
    unsigned int size;
};
Result* __cdecl CreateResultFromStreamObject(Stream* stream, unsigned int index, const char* name);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiGPUProgram
{
  public:
    virtual void f0() throw();
    virtual void DeleteThis() throw();
    volatile long refs;
    void SetString(void*) throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <> class NiPointer<NiGPUProgram>
{
  public:
    NiGPUProgram* ptr;
    NiPointer() : ptr(0)
    {}
    bool operator==(NiGPUProgram* other) const
    {
        return ptr == other;
    }
    __forceinline ~NiPointer() throw()
    {
        if (ptr)
            ptr->DecRefCount();
    }
    NiPointer& operator=(NiGPUProgram* p) throw()
    {
        if (ptr != p)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = p;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
    __declspec(noinline) NiPointer& operator=(NiPointer const& other) throw()
    {
        if (ptr != other.ptr)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = other.ptr;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*) throw();
};
extern unsigned int g_011f3f48;
struct BinaryDataRecord
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int version;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    DynCastHelper** objects;
    unsigned int unk224;
    unsigned int count;
};
NiGPUProgram* CreateResultFromStreamObject(BinaryDataRecord*, unsigned int, void*) throw();
void GetGPUProgram(BinaryDataRecord* stream, unsigned int index, NiPointer<NiGPUProgram>& result, void* extra);
void __cdecl NiFreeA4D(void* pvMem) throw();
struct NiTMapItemA4D
{
    NiTMapItemA4D* m_pkNext;
    const char* m_key;
    void* m_val;
};
class NiTMapBaseA4D
{
  public:
    virtual ~NiTMapBaseA4D() throw()
    {
        RemoveAll();
        NiFreeA4D(m_ppkHashTable);
    }

    void RemoveAll() throw();

    unsigned int m_uiHashSize;
    NiTMapItemA4D** m_ppkHashTable;
    unsigned int m_uiCount;
};
class NiTMapA4D : public NiTMapBaseA4D
{
  public:
    virtual ~NiTMapA4D() throw()
    {
        RemoveAll();
    }
};
class FUN_00a4d660 : public NiTMapA4D
{
  public:
    virtual ~FUN_00a4d660() throw();

    bool m_bCopy;
};
void __cdecl FUN_00a57130(int a1);
void __cdecl FUN_00a41220(int a1);
void __cdecl FUN_00a420e0(float a0, float a1, float* p2, float a3, float a4, float* p5, float a6, float a7, float* p8,
                          float* p9);
struct FUN_00a44840_stub
{
    void* __thiscall CreateClone(unsigned int);
};
namespace a47 {
struct Obj
{
    virtual void v00() throw();
    virtual void DeleteThis() throw();
    volatile long m_lRef;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_lRef);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_lRef))
            DeleteThis();
    }
};
struct Ptr
{
    Obj* m_p;
    Ptr(Obj* p = 0) throw() : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    Ptr(const Ptr& o) throw() : m_p(o.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    Ptr& operator=(Obj* p) throw()
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    operator Obj*() const throw()
    {
        return m_p;
    }
    bool operator!=(const Ptr& o) const throw()
    {
        return m_p != o.m_p;
    }
    bool operator!=(Obj* p) const throw()
    {
        return m_p != p;
    }
    Ptr& operator=(const Ptr& o) throw()
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};
struct Arr
{
    virtual ~Arr() throw();
    Ptr* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    Ptr FUN_00a47540(unsigned int i) throw();
};
// @fnv 0x00a47540
Ptr Arr::FUN_00a47540(unsigned int i) throw()
{
    if (i >= m_usSize)
        return Ptr(0);
    Ptr sp = m_pBase[i];
    m_pBase[i] = Ptr(0);
    if (sp != Ptr(0))
        m_usESize--;
    if (i == (unsigned short)(m_usSize - 1))
        m_usSize--;
    return sp;
}
}

extern "C" void __cdecl FUN_00a39010();
void __cdecl FUN_00a57c00();
struct FUN_00a5d320_Class
{
    void __thiscall FUN_00a5d320(void* arg1, unsigned int arg2);
};
struct FUN_00a5d430_Class
{
    void __thiscall FUN_00a5d430(unsigned int param_1);
};
struct NiVBSet
{
    void Create(unsigned int, unsigned int);
};
struct FUN_00a5d450_class
{
    void CreateVertexBufferSet(unsigned int a, void* b);
};
struct NiObjectGroup;
struct NiBinaryStream
{
    void* m_pStorage;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadGroupId(unsigned int* id)
    {
        unsigned int length = 4;
        m_uiPosition += m_pRead(this, id, 4, &length, 1);
    }
};
struct NiStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int m_uiNifVersion;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    NiBinaryStream* m_pUnderlyingStream;
    NiObjectGroup* GetObjectGroup(unsigned int id);
};
class FUN_00a5d610_Object
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0a();
    virtual void Slot0b();
    virtual void Slot0c();
    virtual void Slot0d();
    virtual void Slot0e();
    virtual void Slot0f();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1a();
    virtual void Slot1b();
    virtual void Slot1c();
    virtual void Slot1d();
    virtual void Slot1e();
    virtual void Slot1f();
    virtual void Slot20();
    virtual void SetGroup(NiObjectGroup* group);
    void ReadGroup(NiStream* stream);
};
extern int g_011f36dc_arg1;
struct BGSCameraPath
{
};
template <class T> class NiTMallocInterface;
template <class T, class Alloc> class NiTArray;
template <> class NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >
{
  public:
    virtual ~NiTArray();
    BGSCameraPath** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int, BGSCameraPath**);
};
template <class T, class Allocator> class NiTPrimitiveArray;
template <> class NiTPrimitiveArray<char*, NiTMallocInterface<char*> >
{
  public:
    virtual ~NiTPrimitiveArray();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
};
struct A5D6E0This : FUN_00a5d3d0
{
    void AppendCameraPathEntries(NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*);
};
extern void* __cdecl FUN_00a7d330(int);
extern void* __cdecl FUN_00a7d5a0(const char*, void*);
extern void* __cdecl FUN_00a7d510(const char*, unsigned int);
extern void __cdecl FUN_00a5c290();
void __cdecl FUN_00a5d7a0();
void __cdecl SaveNiObjectLinks();
void __cdecl FUN_00a5d7b0();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*) throw();
extern "C" void __cdecl _ReadWriteBarrier(void);
class NiRefObjectAAC0
{
  public:
    virtual ~NiRefObjectAAC0() throw();
    virtual void DeleteThis() throw();
    virtual void Slot2() throw();
    virtual void Slot3() throw();
    virtual void Slot4() throw();
    virtual void Slot5() throw();
    virtual void Slot6() throw();
    virtual void Slot7() throw();
    virtual void Slot8() throw();
    virtual void Slot9() throw();
    virtual void Slot10() throw();
    virtual void Slot11() throw();
    virtual void Slot12() throw();
    virtual void Slot13() throw();
    virtual void Slot14() throw();
    virtual void Slot15() throw();
    virtual void Slot16() throw();
    virtual void Slot17() throw();
    virtual void Slot18() throw();
    virtual void Slot19() throw();
    virtual void Slot20() throw();
    virtual void Slot21() throw();
    virtual void Slot22() throw();
    virtual void Slot23() throw();
    virtual void Slot24() throw();
    virtual void Slot25() throw();
    virtual void Slot26() throw();
    virtual void Slot27() throw();
    virtual void Slot28() throw();
    virtual void Slot29() throw();
    virtual void Slot30() throw();
    virtual void Slot31() throw();
    virtual void Slot32() throw();
    virtual void Slot33() throw();
    virtual void Slot34() throw();
    virtual int Type() throw();
    unsigned int m_uiRefCount;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class AnimIdle : public NiRefObjectAAC0
{
};
template <> class NiPointer<AnimIdle>
{
  public:
    AnimIdle* m_pObject;
    NiPointer<AnimIdle>& operator=(AnimIdle* object) throw()
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPointer<AnimIdle>& operator=(const NiPointer<AnimIdle>& other) throw();
};
struct GO633 : public NiPointer<AnimIdle>
{
};
struct NP
{
    AnimIdle* m_pObject;
};
struct S654
{
    NiTListItem<GO633>* m_pkHead;
    NP FUN_0057c5d0(GO633& item) throw();
};
struct ExtraOwner
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
    S654 list;
    void FUN_00a5aac0(int type, NiPointer<AnimIdle>& output);
};
extern int DAT_0101dce4;
extern char DAT_011f4400;
void __cdecl _delete(void*, unsigned int);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);
struct FUN_00a5d4e0
{
    void* m_vtbl;
    void* __thiscall FUN_00a5d4e0_del(unsigned char flags);
};
class CloneMapA5d6
{
  public:
    virtual ~CloneMapA5d6();
};
class CloningProcessA5d6
{
  public:
    CloningProcessA5d6(unsigned int uiHashSize);

    CloneMapA5d6* m_pCloneMap;
    CloneMapA5d6* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
};
class CloneSourceA5d6
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
    virtual CloneSourceA5d6* MakeClone(CloningProcessA5d6& kCloning);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void ProcessClone(CloningProcessA5d6& kCloning);

    CloneSourceA5d6* FUN_00a5d680();
};
extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern char* __cdecl FUN_00a5b690(const char* text);
extern void __cdecl FUN_00a57500(void* fixed);
extern void __cdecl FUN_00a76960(void* fixed, void* out);
extern int DAT_0109b220;
extern unsigned char DAT_011a9594;
extern void(__stdcall* DAT_00fdf1c0)(void*);
extern void(__stdcall* DAT_00fdf1c4)(void*);
struct FnvSourceTexture
{
    virtual void Delete(unsigned char);
    virtual void slot004();
    virtual void slot008();
    virtual void slot012();
    virtual void slot016();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot032();
    virtual void slot036();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot052();
    virtual void slot056();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot072();
    virtual void slot076();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot092();
    virtual void slot096();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot112();
    virtual void slot116();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot132();
    virtual void slot136();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot152();
    virtual void slot156();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual bool IsLoaded();

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    int width;
    int height;
    int depth;
    int unk24;
    int unk28;
    int unk2c;
    char* filename;
    char* normalizedName;
    int unk38;
    int unk3c;
    unsigned char unk40;
    unsigned char flags;
    unsigned short unk42;
    int source;

    FnvSourceTexture* __thiscall FUN_00a5fc10();
};
FnvSourceTexture* __cdecl FUN_00a5fe30(int source, const char* name, const int* size, unsigned char flags);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl NiFreeD510(void* pvMem);

class NiObjectD510
{
  public:
    virtual ~NiObjectD510();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    void FUN_00a5d510(class NiPointerD510& spCopy);
    long m_uiRefCount;
};

class NiPointerD510
{
  public:
    NiPointerD510(NiObjectD510* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerD510()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerD510& operator=(const NiPointerD510& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiObjectD510* m_pObject;
};

class NiStreamD510
{
  public:
    NiStreamD510();
    ~NiStreamD510();
    bool InsertObject(NiObjectD510* pkObject);
    bool Save(char*& pcBuffer, int& iBufferSize);
    bool Load(char* pcBuffer, int iBufferSize);
    NiObjectD510* GetObjectAt(unsigned int i) const
    {
        return m_ppkTopObjects[i];
    }
    int unk000;
    char m_acInputFilePath[0x104];
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    void* m_pTopObjectsVTable;
    NiObjectD510** m_ppkTopObjects;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
};

// @fnv 0x00a5d510
void NiObjectD510::FUN_00a5d510(NiPointerD510& spCopy)
{
    NiStreamD510 kStream;
    kStream.InsertObject(this);
    char* pcBuffer = 0;
    int iBufferSize = 0;
    kStream.Save(pcBuffer, iBufferSize);
    kStream.Load(pcBuffer, iBufferSize);
    NiPointerD510 spRetainedObject = kStream.GetObjectAt(0);
    NiFreeD510(pcBuffer);
    spCopy = spRetainedObject;
}

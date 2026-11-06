
// src/fallout_shared/globalfunc_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout_shared/globalfunc_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/globalfunc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/globalfunc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "globalfunc_decls.h"
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity);
bool UpdateObjectVisibility(NiAVObject* object);
bool RemoveInvalidChildNodes(NiNode* object);
bool HandleUnparentedObjectNode(NiNode* object);
void SetObjectFormID(NiAVObject* object, unsigned int referenceID);
bool IsObjectNetValid(NiObjectNET* object);
float GetAngleFromVector(const NiPoint3& vector);
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown);
LANGUAGE GetConfiguredLanguage();
bool IsSettingEnabled();
extern int DAT_0126f74c;
struct BeamStage
{
    void ApplyPairToState(unsigned int);
};
struct NiD3DPass
{
    bool ApplyRenderStateChanges(bool);
};
struct InBa
{
    char _0[0x1c];
    int f1c;
    char _1[0xF8];
    int f118;
};
struct OutBa
{
    char _0[0xc];
    InBa* fC;
};
void __stdcall FUN_00ba6240(OutBa* a1);
class NiObject;
struct NiStream
{
    NiObject* GetLoadedObject();
};
struct S86870
{
    virtual void d00() = 0;
    virtual void d01() = 0;
    virtual void d02() = 0;
    virtual void d03() = 0;
    virtual void d04() = 0;
    virtual void d05() = 0;
    virtual void d06() = 0;
    virtual void d07() = 0;
    virtual void d08() = 0;
    virtual void d09() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void* GetLink(char* p) = 0;
    void FUN_00c87670(NiStream* s);
    void LinkObject(NiStream* s);
};
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    char _0[8];
    unsigned short m_8;
    unsigned short m_kOutgoingTangent;
    unsigned short m_C;
    unsigned short m_E;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
extern const char* const g_0126811c_arg1;
char* __cdecl _FUN_00a7d330(const char*);
void __stdcall FUN_00c878c0(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
void __stdcall FUN_00c87be0(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* p);
short __cdecl FindIndexByKey(void* apSkeleton, const char* apName, int aiUnk);
struct ArmTarget_S
{
    float fA;
    float fB;
    bool bActive;
};
struct ArmIKData_S
{
    char pad00[0x10];
    int iState;
    ArmTarget_S xTarget;
    char pad[0x30 - 0x20];
};
struct ArmBones_S
{
    unsigned short sUpper;
    unsigned short sFore;
    unsigned short sHand;
    bool IsValid() const
    {
        return sUpper != 0xffff && sFore != 0xffff && sHand != 0xffff;
    }
};
struct SkelHolder_S
{
    char pad[0xc];
    void* pSkeleton;
};
struct FUN_00c75460_S
{
    char pad000[0x42];
    bool bEnabled;
    char pad043[0x1a0 - 0x43];
    ArmIKData_S xArms[2];
    char pad200[0x10];
    ArmBones_S xLeft;
    ArmBones_S xRight;
    char pad21c[0x2a4 - 0x21c];
    SkelHolder_S* pHolder;
    bool FUN_00c75460();
};
void __cdecl FUN_00b97e80(int, int);
void __stdcall FUN_00ba5de0(OutBa* a1, int unused);
struct CallTarget_00ba5320
{
    int FUN_00ba5320();
};
struct SearchObject
{
    int FUN_00ba5ed0(unsigned int arg0);
};
struct S_00c85ef0_Pair
{
    int first;
    int second;
    S_00c85ef0_Pair()
    {}
};
struct S_00c85ef0_Map
{
    S_00c85ef0_Pair FindEntry(int key, int def);
};
struct S_00c85ef0_Ret
{
    __int64 v;
    S_00c85ef0_Ret(__int64 x) : v(x)
    {}
};
S_00c85ef0_Ret FUN_00c85ef0(S_00c85ef0_Map* map, int key);
extern int DAT_01268118;
class FUN_00c86720_base
{
  public:
    virtual void unk00();
    ~FUN_00c86720_base();
    int unk04;
};
class FUN_00c86720 : public FUN_00c86720_base
{
  public:
    virtual ~FUN_00c86720();
    void unk08();
};
struct FUN_00c867d0_out
{
    void* unk00;
    void* unk04;
};
struct FUN_00c867d0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    void* unk18;
};
class FUN_00c867d0_cls
{
  public:
    void* unk00;
    void* unk04;
    FUN_00c867d0_inner* unk08;
    void* FUN_00c879e0(FUN_00c867d0_out* out);
    void FUN_00c867d0(FUN_00c867d0_out* out);
};
struct NiTStringPointerMap_00e93020
{
    bool GetAt(void* key, void*& value) const;
};
struct FUN_00c86800_Link
{
    int unk00;
    void* m04;
};
struct FUN_00c86800_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* key0C;
};
struct FUN_00c86800_Target
{
    int unk00;
    int unk04;
    void* m08;
};
struct FUN_00c86800_Table
{
    NiTStringPointerMap_00e93020* map;
};
struct FUN_00c86800_Class : S86870
{
    void FUN_00c86800(int a1, FUN_00c86800_Table* a2);
    void FUN_00c87600(int a1, FUN_00c86800_Table* a2);
};
struct FUN_00c868f0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_18;
};
class FUN_00c868f0_cls
{
  public:
    int unk00;
    int unk04;
    FUN_00c868f0_inner* m_08;
    bool FUN_00ba87d0(FUN_00c868f0_cls* other);
    unsigned char FUN_00c868f0(FUN_00c868f0_cls* other);
};
extern __declspec(thread) unsigned int threadContext;
inline unsigned int& currentAllocationMode()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&threadContext) + 0x2b4);
}
class ScopedAllocationMode
{
    unsigned int previous;

  public:
    ScopedAllocationMode() : previous(currentAllocationMode())
    {
        currentAllocationMode() = 16;
    }
    ~ScopedAllocationMode()
    {
        currentAllocationMode() = previous;
    }
};
class ObjectCandidate
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual int QueryValue();
    virtual void slot38();
    virtual void slot39();
    virtual void Reset();
    int unk04;
    int activeObject;
    bool FUN_00c86ab0(class Item* item);
    void FUN_00c86940(Item*);
};
class Item
{
  public:
    int unk00;
    int unk04;
    int matchingValue;
    void FUN_00c6b3c0(int);
};
extern __declspec(thread) int g_tlsHeapContext;
int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
char* __cdecl FUN_00a7d5e0(const char* className, const char* name);
struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = g_tlsHeapContext;
        g_tlsHeapContext = ctx;
    }
    ~HeapContextGuard()
    {
        g_tlsHeapContext = saved;
    }
};
extern const char* g_name86b80;
typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > StringArray;
inline void AddString(StringArray* arr, char*& s)
{
    unsigned int idx = arr->m_kOutgoingTangent;
    if (idx >= arr->m_8)
        arr->SetSize(arr->m_E + idx);
    arr->SetAt(idx, s);
}
struct HkObject86b80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pHkObject;
};
struct Wrapper86b80
{
    int unk00;
    int unk04;
    HkObject86b80* m_pObject;

    void FUN_00c87be0(StringArray* arr);
    void FUN_00c86b80(StringArray* arr);
};
extern int DAT_01268124;
class FUN_00c86cb0_base
{
  public:
    virtual void unk00();
    ~FUN_00c86cb0_base();
    int unk04;
};
class FUN_00c86cb0 : public FUN_00c86cb0_base
{
  public:
    virtual ~FUN_00c86cb0();
    void unk08();
};
struct FourFloatVector
{
    float x, y, z, w;
    void __thiscall FUN_004b4db0(const FourFloatVector*);
};
struct InnerData
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FourFloatVector q20;
    FourFloatVector q30;
    float x40, y44, z48, w4c;
};
struct OutputData
{
    unsigned int unk00, unk04, unk08, unk0c;
    FourFloatVector a10;
    FourFloatVector b20;
    float x30, y34, z38, w3c;
};
void __stdcall FUN_00c867d0(OutputData*);
struct FUN_00c86d20_Class
{
    int unk00, unk04;
    InnerData* inner;
    void __thiscall FUN_00c86d20(OutputData* dest);
};
struct FUN_00c871c0_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00c871c0_tls g_tls;
struct FUN_00c871c0_pool
{
    void FUN_00aa4060(int);
};
extern FUN_00c871c0_pool DAT_011f6238;
struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class FUN_00c871c0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    char* m_0c;
    void FUN_00c871c0(bool flag);
};
extern __declspec(thread) int g_iC878C0AllocTag;
struct BC878C0AllocTagScope
{
    int m_iSaved;

    BC878C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC878C0AllocTag;
        g_iC878C0AllocTag = aiAllocationTag;
    }
    ~BC878C0AllocTagScope()
    {
        g_iC878C0AllocTag = m_iSaved;
    }
};
class BC878C0StringArray
{
  public:
    virtual ~BC878C0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
extern const char* g_pcC878C0Name;
char* __cdecl FUN_00a7d330(const char* pcString);
class FUN_00c878c0_cls
{
  public:
    void AddDebugStrings(BC878C0StringArray* pkArray);
    void FUN_00c878c0(BC878C0StringArray* pkArray);
};
extern int DAT_01268154;
struct FUN_00c877b0
{
    virtual ~FUN_00c877b0();
};
struct FUN_00c87970 : FUN_00c877b0
{
    virtual ~FUN_00c87970();
    void FUN_00c876a0();
};
// FUN_00ead0d0 - walks a singly linked list and returns the first node whose
// flag field is set (0 if the list ends or the head pointer is null).
// The original was written as a tail-recursive helper; MSVC's tail-call
// optimisation turns it into the loop that is actually emitted here.
struct FadeNodeEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FadeNodeEntry* m_pNext;  // +0x18
    int m_iFlag;             // +0x1c
};
FadeNodeEntry* __stdcall FUN_00ead0d0(FadeNodeEntry* pHead);
struct InBaFull
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int f1c;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104;
    int f108;
    int f10C;
};
int __cdecl GetTableValue(int);
void __cdecl DevCallbackMode(int, int);
void __cdecl AddToTwoCounters(int, int, int);
void __stdcall FUN_00ba5e60(OutBa* a1);
struct C69EE0Properties
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned int m_uiValue1;
};
extern "C" C69EE0Properties* GetExtraDataChecked(NiAVObject* pkObject);
static inline unsigned int C69EE0IsEnabled(NiAVObject* pkObject)
{
    C69EE0Properties* pkProps = GetExtraDataChecked(pkObject);
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}
extern void (*DAT_011afe8c)(NiCollisionObject*, CollisionObjectCountContext*);
bool FUN_00c69ee0(NiAVObject* pkObject, bool bRecurse, bool bForce);
__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile const*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile const*);
struct StageReturn
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_uiRefCount;
    void ReturnToPool();
    void Release()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};
void __cdecl AssignStageFromPool(StageReturn*&);
struct StageReturnPtr
{
    StageReturn* m_pStage;
    StageReturnPtr() : m_pStage(0)
    {}
    ~StageReturnPtr()
    {
        if (m_pStage)
        {
            m_pStage->Release();
        }
    }
    operator StageReturn*&()
    {
        return m_pStage;
    }
    operator StageReturn*() const
    {
        return m_pStage;
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
        {
            DeleteThis();
        }
    }
};
class NiD3DPixelShader : public NiRefObject
{
};
class NiD3DVertexShader : public NiRefObject
{
};
template <class T> class NiD3DPointer
{
  public:
    T* m_pObject;
    NiD3DPointer(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiD3DPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiD3DPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiD3DPointer& operator=(const NiD3DPointer& r)
    {
        return *this = r.m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};
struct D3DRenderStateGroup
{
    void SetRenderState(unsigned int uiState, unsigned int uiValue, bool bSave);
};
D3DRenderStateGroup* __cdecl FUN_00e7f5d0();
struct NiD3DPass_Standin : NiD3DPass
{
    virtual ~NiD3DPass_Standin();
    int unk04, unk08, unk0C, unk10;
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    int unk1C, unk20, unk24, unk28, unk2C;
    D3DRenderStateGroup* m_spRenderStateGroup;
    int unk34, unk38, unk3C, unk40;
    NiD3DPointer<NiD3DVertexShader> m_spVertexShaderObject;
    int unk48, unk4C, unk50, unk54, unk58;
    NiD3DPointer<NiD3DPixelShader> m_spPixelShaderObject;
    int unk60;
    int m_uiRefCount;

    unsigned int GetStageCount() const
    {
        return m_uiNumberOfStages;
    }

    void FUN_00e802b0(unsigned int, StageReturn*);
    void FUN_00e80190();

    void SetRenderState(unsigned int uiState, unsigned int uiValue, bool bSave)
    {
        if (!m_spRenderStateGroup)
        {
            m_spRenderStateGroup = FUN_00e7f5d0();
        }
        m_spRenderStateGroup->SetRenderState(uiState, uiValue, bSave);
    }
};
void __cdecl ConfigureBeamStage(StageReturn*, int, int, int, int);
struct NiD3DPassPtr
{
    NiD3DPass_Standin* m_pObject;
    NiD3DPassPtr() : m_pObject(0)
    {}
    ~NiD3DPassPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_uiRefCount == 0)
            {
                m_pObject->FUN_00e80190();
            }
        }
    }
    NiD3DPassPtr& operator=(const NiD3DPassPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_uiRefCount == 0)
                {
                    m_pObject->FUN_00e80190();
                }
            }
            m_pObject = ptr.m_pObject;
            if (m_pObject)
            {
                ++m_pObject->m_uiRefCount;
            }
        }
        return *this;
    }
    operator NiD3DPass_Standin*() const
    {
        return m_pObject;
    }
    NiD3DPass_Standin* operator->() const
    {
        return m_pObject;
    }
};
class BeamPassShader
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    NiD3DPassPtr m_spPass0;
    NiD3DPassPtr m_spPass1;
    NiD3DPointer<NiD3DPixelShader> m_spPixelShaderObject;
    NiD3DPointer<NiD3DVertexShader> m_spVertexShaderObject;

    void FUN_00ba59e0();
};
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
struct Vec3
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float coord[3];
    };
};
struct Vec4
{
    float x, y, z, w;
};
struct Transform
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Vec3 unk24;
    float unk30;
    void FUN_004b4880(Transform*);
    Vec3* FUN_00524c40(Vec3*, const Vec3*);
};
struct Update
{
    void FUN_00e6fbb0(Transform*, int);
};
struct Shader
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void apply(void*, void*, int, int, int, void*, int, Transform*, void*, int, int);
};
struct Source
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    void* unk60;
    int unk64;
    int unk68;
    bool unk6c;
    int unk70;
    int unk74;
    int unk78;
    float unk7c;
    int unk80;
    float unk84;
    int unk88;
    float unk8c;
    Vec3 unk90;
    Vec3 unk9c;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Vec3 unkb8;
    Vec4 unkc4;
    Vec4 unkd4;
    Vec4 unke4;
    Vec4 unkf4;
    float unk104;
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
    float unk130;
    float unk134;
    float unk138;
    Vec3 unk13c;
    float unk148;
};
struct Arg
{
    int unk00;
    int unk04;
    int unk08;
    Source* unk0c;
};
struct Extra
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
    int unk34;
};
struct Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    Transform unk68;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Extra* unkb8;
    int unkbc;
};
struct Manager
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    void* unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* unk5c;
};
extern Geom** DAT_011f91e0;
extern int DAT_011f91c0;
extern int DAT_0126f74c;
extern int DAT_012003ec;
extern int DAT_011f4288;
struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Update* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Shader* unk30;
    Shader* unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    void* unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    float unk84;
    float unk88;
    float unk8c;
    float unk90;
    Vec3 unk94;
    int unka0;
    Vec4 unka4;
    Vec3 unkb4;
    float unkc0;
    float unkc4;
    float unkc8;
    int unkcc;
    int unkd0;
    Vec3 unkd4;
    Vec3 unke0;
    Vec3 unkec;
    float unkf8;
    Vec4 unkfc;
    Vec4 unk10c;
    Vec4 unk11c;
    void FUN_00ba5ee0(Arg*);
};
inline int isSource(Source* p)
{
    if (!p)
        return false;
    return p->unk1c == 17;
}
struct C868_L3
{
    int unk00, unk04, unk08;
    void* m_0c;
};
struct C868_L2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    C868_L3* m_18;
};
struct C868_Iface
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30(void* p);
};
extern "C" void _ReadWriteBarrier(void);
class FUN_00c868b0_cls
{
  public:
    int unk00, unk04;
    C868_L2* m_08;
    void SaveSerializeData(C868_Iface* a1);
    void FUN_00c868b0(C868_Iface* a1);
};
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_01268124;
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_0101ffcc;
class bhkRefObject
{
  public:
    bhkRefObject* Initialize();
};
class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};
class RefObjC86D : public TESObjectDoorController
{
  public:
    int* m_vptr;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline RefObjC86D()
    {
        ((bhkRefObject*)this)->Initialize();
        m_vptr = &DAT_0102016c;
        unk0C = 0;
        DAT_01268154++;
        m_vptr = &DAT_0102009c;
        DAT_01268118++;
        m_vptr = &DAT_0101ffcc;
        DAT_01268124++;
    }
};
RefObjC86D* __cdecl CreateObject();
void FUN_00c876f0();
void FUN_00c87700();
void* __cdecl FUN_00aa13e0(unsigned int bytes);
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_0101ffcc;
class AllocatedNode
{
  public:
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;

    static void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    void FUN_00c87c30();

    AllocatedNode()
    {
        FUN_00c87c30();
        vtable = &DAT_0102016c;
        unk0c = 0;
        ++DAT_01268154;
        vtable = &DAT_0102009c;
        ++DAT_01268118;
        vtable = &DAT_0101ffcc;
        ++DAT_01268124;
    }
};
class FUN_00c87010_cls : public FUN_00c86800_Class
{
  public:
    AllocatedNode* CreateClone(FUN_00c86800_Table* p);
};

#include <xmmintrin.h>
class S004b4db0_SimdReal
{
  public:
    operator float() const;  // FUN_004586d0
    __m128 m_vValue;
};

class S004b4db0_Vector4
{
  public:
    S004b4db0_SimdReal getComponent(int i) const;  // FUN_00458700
    __m128 m_vComponents;
};

class S004b4db0_Quaternion
{
  public:
    S004b4db0_Quaternion& FUN_004b4db0(const S004b4db0_Vector4& v);
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

// @fnv 0x004b4db0
S004b4db0_Quaternion& S004b4db0_Quaternion::FUN_004b4db0(const S004b4db0_Vector4& v)
{
    m_fVectorY = v.getComponent(0);
    m_fVectorZ = v.getComponent(1);
    m_fScalarPart = v.getComponent(2);
    m_fVectorX = v.getComponent(3);
    return *this;
}

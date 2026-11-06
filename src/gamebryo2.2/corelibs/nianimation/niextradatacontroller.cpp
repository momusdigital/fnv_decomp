// gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp: NiPSysModifierCtlr, NiExtraDataController, FakeController, TargetController (8 functions)

#include "niextradatacontroller_decls.h"

// @fnv 0x00a571a0
void NiPSysModifierCtlr::LoadBinary(NiStream& stream)
{
    NiSingleInterpController::LoadBinary(stream);
    if (stream.version < 0x14010001)
        stream.ReadFixedString(m_kTargetModifierName);
    else
        stream.ReadStringTableEntry(m_kTargetModifierName);
}

struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream& stream);
};
struct NiObjectNET : NiObject
{
    void RefreshExtraData();
};
struct NiExtraDataController : NiObjectNET
{
    void FUN_00a57400(NiStream& kStream);
};

// @fnv 0x00a57400
void NiExtraDataController::FUN_00a57400(NiStream& kStream)
{
    NiObjectNET::LinkObject(kStream);
    if (*(int*)((char*)this + 0x2C))
        NiObjectNET::RefreshExtraData();
}

struct BaseFake
{
    bool RegisterInterpolatorStreamables(NiStream&);
};
struct StreamVTable
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*);
};
struct FUN_00a57100_Caller
{
    bool FUN_00a57100(NiStream&);
};
// Calls the base RegisterInterpolatorStreamables on kStream; if it succeeds, calls kStream's f8 on this+0x38 and returns true, otherwise false.
// @fnv 0x00a57100
bool FUN_00a57100_Caller::FUN_00a57100(NiStream& kStream)
{
    if (!((BaseFake*)this)->RegisterInterpolatorStreamables(kStream))
        return false;
    ((StreamVTable*)&kStream)->f8((void*)((char*)this + 0x38));
    return true;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NiTimeController : NiObjectNET
{
    virtual void SetTarget(NiObjectNET*);
};
struct FakeController : NiTimeController
{
    void FUN_00a57330(NiObjectNET*);
};
struct RefObj
{
    virtual void f0();
    virtual void DeleteThis();
    long ref;
};
// Releases the object at offset 0x3c, calls NiTimeController::SetTarget, and refreshes extra data if offset 0x2c is set.
// @fnv 0x00a57330
void FakeController::FUN_00a57330(NiObjectNET* pkTarget)
{
    RefObj* p = *(RefObj**)((char*)this + 0x3c);
    if (p)
    {
        if (InterlockedDecrement(&p->ref) == 0)
            p->DeleteThis();
        *(RefObj**)((char*)this + 0x3c) = 0;
    }
    NiTimeController::SetTarget(pkTarget);
    if (*(void**)((char*)this + 0x2c))
        RefreshExtraData();
}

struct StrArr
{
    char m_pad00[8];
    unsigned short m_usCapacity;
    unsigned short m_usSize;
    unsigned short m_pad0c;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

template <class T> struct NiTPrimitiveArray : public StrArr
{
};

extern char const* const g_011f3e6c_arg1;

void __stdcall _FUN_00a390a0(StrArr* array);
void* __cdecl _FUN_00a7d330(void* value);
char* __cdecl FUN_00a7d5e0(char const* lhs, char const* rhs);

struct FUN_00a57420_Shell : public NiExtraDataController
{
    void FUN_00a57420(NiTPrimitiveArray<char*>* strings);
};

// @fnv 0x00a57420
void FUN_00a57420_Shell::FUN_00a57420(NiTPrimitiveArray<char*>* strings)
{
    StrArr* array = strings;

    _FUN_00a390a0(array);

    char* value = static_cast<char*>(_FUN_00a7d330(const_cast<char*>(g_011f3e6c_arg1)));

    unsigned int index = array->m_usSize;
    if (index >= array->m_usCapacity)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);

    char const* pcExtraDataName = *reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x38);
    value = FUN_00a7d5e0("Extra Data Name", pcExtraDataName);

    index = array->m_usSize;
    if (index >= array->m_usCapacity)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);
}

struct FUN_00a57150_cls;

struct FUN_00a57150_obj53
{
    void FUN_00a53c30(void* first, void** ppArg);
};

struct FUN_00a57150_obj66
{
    void FUN_0066b0d0(void* arg);
};

struct FUN_00a57150_cls
{
    char unk00[0x2c];
    unsigned int m_2c;
    char unk30[0x0c];
    void* m_3c;

    void FUN_00a38f50(void* arg);
    void ProcessClone(void* arg);
};

// @fnv 0x00a57150
void FUN_00a57150_cls::ProcessClone(void* arg)
{
    void* src = arg;
    FUN_00a38f50(src);
    FUN_00a57150_obj53* o = (FUN_00a57150_obj53*)*(void**)src;
    o->FUN_00a53c30(this, &arg);
    if (m_2c != 0)
    {
        if (((FUN_00a57150_cls*)arg)->m_2c != 0)
        {
            FUN_00a57150_cls* other = (FUN_00a57150_cls*)arg;
            FUN_00a57150_obj53* o2 = (FUN_00a57150_obj53*)*(void**)src;
            o2->FUN_00a53c30(m_3c, &arg);
            FUN_00a57150_obj66* p = (FUN_00a57150_obj66*)&other->m_3c;
            p->FUN_0066b0d0(arg);
        }
    }
}

struct S_00a571e0_Child
{
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
    virtual bool IsEqual(S_00a571e0_Child* o);
};
struct S_00a571e0_Ptr
{
    S_00a571e0_Child* p;
    operator S_00a571e0_Child*() const
    {
        return p;
    }
    S_00a571e0_Child* operator->() const
    {
        return p;
    }
};
struct S_00a571e0_Base
{
    virtual void v00();
    int unk04;
    bool IsCompatibleWith(S_00a571e0_Base* o);
};
struct S_00a571e0_Cls : S_00a571e0_Base
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S_00a571e0_Ptr unk3c;
    unsigned char IsEquivalent(S_00a571e0_Cls* o);
};
// Compares base fields, the unk3c child pointer (presence and IsEqual), and unk38 against another instance, returning true only if all match.
// @fnv 0x00a571e0
unsigned char S_00a571e0_Cls::IsEquivalent(S_00a571e0_Cls* apOther)
{
    if (!IsCompatibleWith(apOther))
        return false;
    if ((unk3c && !apOther->unk3c) || (!unk3c && apOther->unk3c))
        return false;
    if (unk3c && apOther->unk3c && !unk3c->IsEqual(apOther->unk3c))
        return false;
    return apOther->unk38 == unk38;
}

struct TypeRecord;

struct TargetCandidate
{
    virtual void f0();
    virtual void f1();
    virtual TypeRecord* f2();
    unsigned int unknown04, unknown08, unknown0c;
    void** m_ppItems;
    unsigned short m_usElementCount;
};

struct TypeRecord
{
    void* vtbl;
    TypeRecord* next;
};

void* __fastcall FUN_00a62660(void* item);

extern char g_011f4304;
extern unsigned int g_0109b220;

struct TargetController
{
    unsigned int unknown00, unknown04, unknown08, unknown0c, unknown10, unknown14, unknown18, unknown1c, unknown20,
        unknown24, unknown28, unknown2c, unknown30, unknown34;
    void* m_pFlagTarget;

    bool HasMatchingItem(TargetCandidate* arg);
};

static __forceinline bool HasTargetType(TargetCandidate* arg)
{
    if (arg)
    {
        TypeRecord* node = arg->f2();
        while (node)
        {
            if ((char*)node == &g_011f4304)
                return true;
            node = node->next;
        }
    }
    return false;
}
// @fnv 0x00a57380
bool TargetController::HasMatchingItem(TargetCandidate* pCandidate)
{
    if (!HasTargetType(pCandidate))
        return false;
    if ((unsigned int)m_pFlagTarget == g_0109b220)
        return false;
    for (unsigned int uiIndex = 0; uiIndex < pCandidate->m_usElementCount; ++uiIndex)
    {
        void* pResolved = FUN_00a62660(pCandidate->m_ppItems[(unsigned short)uiIndex]);
        if (*(void**)pResolved == m_pFlagTarget)
            return true;
    }
    return false;
}

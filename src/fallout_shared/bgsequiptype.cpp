// fallout_shared/bgsequiptype.cpp: BGSEquipType, QueryObject (8 functions)

#include "bgsequiptype_decls.h"

// @fnv 0x00479430
BGSEquipType::EQUIP_TYPE BGSEquipType::GetEquipType(TESForm* form)
{
    EQUIP_TYPE result = ET_NONE;
    if (form)
    {
        switch (form->GetFormType())
        {
        case 40:
            result = (EQUIP_TYPE)(int)((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0xc4))->GetNext();
            break;
        case 24:
            result = (EQUIP_TYPE)(int)((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x154))->GetNext();
            break;
        case 26:
            result = (EQUIP_TYPE)(int)((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x14c))->GetNext();
            break;
        case 47:
            result = (EQUIP_TYPE)(int)((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x9c))->GetNext();
            break;
        case 29:
            result = (EQUIP_TYPE)(int)((BSSimpleList<BGSPerkEntry*>*)((char*)form + 0x8c))->GetNext();
            break;
        }
    }
    return result;
}

extern int DAT_0101aa14;
void __fastcall FUN_008c6060(void* pThis);

class BaseFormComponent
{
  public:
    BaseFormComponent();
};

// Initializes the BaseFormComponent base, sets the vtable pointer to DAT_0101aa14, calls FUN_008c6060, and returns pThis.
// @fnv 0x00479320
void* __fastcall FUN_00479320(int* pFormComponent)
{
    ((BaseFormComponent*)pFormComponent)->BaseFormComponent::BaseFormComponent();
    *pFormComponent = (int)&DAT_0101aa14;
    FUN_008c6060(pFormComponent);
    return pFormComponent;
}

extern int DAT_011c4b54[14];

// Returns DAT_011c4b54[a1] when a1 is between 0 and 13, otherwise returns 0.
// @fnv 0x00479510
int __cdecl GetEquipTypeIcon(int aiIndex)
{
    int iValue = 0;
    if (aiIndex > -1 && aiIndex < 14)
    {
        iValue = DAT_011c4b54[aiIndex];
    }
    return iValue;
}

namespace fnv_00479540 {
struct FNStub
{
    const char* __thiscall GetFullName(void);
};

struct BGSMenuIcon
{
    const char* __thiscall GetFullName(void);
};

extern BGSMenuIcon* __cdecl GetEquipTypeIcon(int);
extern const char $SG5812[];

// Looks up the BGSMenuIcon for aeType and returns its full name, or a fallback string when none exists.
// @fnv 0x00479540
const char* __cdecl GetMenuIconName(int aeType)
{
    BGSMenuIcon* picon = GetEquipTypeIcon(aeType);
    if (picon)
        return reinterpret_cast<FNStub*>(picon + 0x18)->GetFullName();
    return $SG5812;
}
}  // namespace fnv_00479540

struct FUN_004029d0_shell
{
    bool FUN_004029d0(int);
};
struct S_004036b0
{
    int FUN_004036b0();
};
struct S_004063e0
{
    float GetTotalCost(int);
};
struct FUN_00403660_shell
{
    float GetValue(int);
};
// @fnv 0x00403660
float FUN_00403660_shell::GetValue(int)
{
    if (((FUN_004029d0_shell*)((char*)this - 0x3c))->FUN_004029d0(1))
    {
        return (float)((S_004036b0*)((char*)this - 0x3c))->FUN_004036b0();
    }
    else
    {
        return ((S_004063e0*)this)->GetTotalCost(0);
    }
}

struct S_0040a0a0_Primary
{
    virtual void vfn_00();
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
};

struct S_0040a0a0_AVOwner
{
    virtual float FUN_0040a0a0(int avCode);
    float GetTotalCost(int a);
};

struct S_0040a0a0_Actor : S_0040a0a0_Primary, S_0040a0a0_AVOwner
{
    bool FUN_00409a30(unsigned int flag);
    int FUN_00586150();
    virtual float FUN_0040a0a0(int avCode);
};

// @fnv 0x0040a0a0
float S_0040a0a0_Actor::FUN_0040a0a0(int avCode)
{
    if (FUN_00409a30(1))
    {
        return FUN_00586150();
    }
    else
    {
        return GetTotalCost(0);
    }
}

extern const char DAT_01183040[];
extern const char DAT_01183290[];
extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);
struct LookupObject
{
    int __thiscall FUN_00726070();
};
struct QueryObject
{
    bool __thiscall CompareComponent(int);
    int __thiscall FUN_00726070();
};
// @fnv 0x004793d0
bool __thiscall QueryObject::CompareComponent(int argument)
{
    void* found = FUN_00ec43fb(argument, 0, DAT_01183040, DAT_01183290, 0);
    if (found == 0)
        return true;
    if (FUN_00726070() != ((LookupObject*)found)->FUN_00726070())
        return true;
    return false;
}

extern const char DAT_01183040[];
extern const char DAT_01183290[];
extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);

struct FUN_00479380_cls
{
    void FUN_006ecd40(int value);
    void SetFromLookup(int a1);
};

// @fnv 0x00479380
void FUN_00479380_cls::SetFromLookup(int a1)
{
    LookupObject* obj = (LookupObject*)FUN_00ec43fb(a1, 0, DAT_01183040, DAT_01183290, 0);
    if (obj == 0)
    {
    }
    else
    {
        this->FUN_006ecd40(obj->FUN_00726070());
    }
}

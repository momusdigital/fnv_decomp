// fallout_shared/tesattributes.cpp: TESAttributes, Thing (11 functions)

#include "tesattributes.h"

// @fnv 0x0047ff70
TESAttributes::TESAttributes()
{
    InitializeComponent();
}

// Sets all seven entries of cAttribute to 5.
// @fnv 0x0047ffc0
void TESAttributes::InitializeComponent()
{
    for (int i = 0; i < 7; ++i)
    {
        cAttribute[i] = 5;
    }
}

struct FUN_00480130_shell : public TESAttributes
{
    unsigned int FUN_00480130(void*);
};

void* __cdecl memcpy(void*, const void*, unsigned int);
unsigned int __fastcall FUN_009d2510(void*);

// Copies 7 bytes from apData into the object at offset 4, then calls FUN_009d2510 on this and returns its result.
// @fnv 0x00480130
unsigned int FUN_00480130_shell::FUN_00480130(void* apData)
{
    memcpy(reinterpret_cast<char*>(this) + 4, apData, 7);
    return FUN_009d2510(this);
}

struct FUN_00480160_shell : public TESAttributes
{
    unsigned char FUN_00480160(int);
};

// @fnv 0x00480160
unsigned char FUN_00480160_shell::FUN_00480160(int aeAttribute)
{
    return reinterpret_cast<unsigned char*>(this)[aeAttribute - 1];
}

extern "C" void* _memcpy(void* dst, const void* src, unsigned int n);
unsigned int __fastcall FUN_009d2510(void* p);

struct FUN_00480100_shell
{
    unsigned int __thiscall FUN_00480100(void* apData);
};

// Copies 7 bytes from this+4 into apData, then returns the result of FUN_009d2510(this).
// @fnv 0x00480100
unsigned int __thiscall FUN_00480100_shell::FUN_00480100(void* apData)
{
    _memcpy(apData, this + 4, 7);
    return FUN_009d2510(this);
}

struct FUN_004801e0_shell
{
    unsigned short m_val;
    unsigned short FUN_004801e0(int param);
};

// @fnv 0x004801e0
unsigned short FUN_004801e0_shell::FUN_004801e0(int param)
{
    unsigned short result = 0;
    if (param & 0)
    {
        result = result + 7;
    }
    return result;
}

struct TESSaveLoadGame
{
    void ReadTypedData(void* aBuffer, unsigned int aSize);
};

TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00480240_shell
{
    void FUN_00480240(unsigned int aFlags, unsigned int aDummy);
};

// @fnv 0x00480240
void __thiscall FUN_00480240_shell::FUN_00480240(unsigned int aFlags, unsigned int aDummy)
{
    if (aFlags & 0)
    {
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 4), 7);
    }
}

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESForm;
struct TESHealthForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00480000_shell : public TESAttributes
{
    void CopyAttributesFromComponent(BaseFormComponent*);
};

struct ActorValue
{
    enum Section
    {
        ATTRIBUTE = 0
    };
    enum Index
    {
        None = 0
    };
};

struct AVH
{
    static ActorValue::Index GetActorValueForSectionIndex(ActorValue::Section, unsigned char);
};

struct TESAttributes_GetAttribute
{
    unsigned char GetAttributeValue(int);
};

// Casts component to TESAttributes and copies its seven attribute values into cAttribute.
// @fnv 0x00480000
void FUN_00480000_shell::CopyAttributesFromComponent(BaseFormComponent* component)
{
    TESAttributes* attributes = dynamic_cast<TESAttributes*>(component);
    if (!attributes)
        return;
    for (int i = 0; i < 7; ++i)
        cAttribute[i] = ((TESAttributes_GetAttribute*)attributes)
                            ->GetAttributeValue((int)AVH::GetActorValueForSectionIndex(ActorValue::ATTRIBUTE, i));
}

namespace fnv_00480070 {
struct ActorValue
{
    enum Index
    {
        ATTRIBUTE
    };
};
struct AVH
{
    static ActorValue::Index GetActorValueForSectionIndex(int, unsigned char);
};
struct FUN_00480070_shell : public TESAttributes
{
    unsigned char GetAttributeValue(int index);
    bool FUN_00480070(BaseFormComponent* component);
};
// Casts component to TESAttributes and returns false only if all seven attribute values match this object's cAttribute entries; returns true otherwise.
// @fnv 0x00480070
bool FUN_00480070_shell::FUN_00480070(BaseFormComponent* component)
{
    TESAttributes* attributes = dynamic_cast<TESAttributes*>(component);
    if (!attributes)
        return true;
    for (int i = 0; i < 7; ++i)
    {
        if (cAttribute[i] !=
            ((FUN_00480070_shell*)attributes)->GetAttributeValue(AVH::GetActorValueForSectionIndex(0, i)))
            return true;
    }
    return false;
}
}  // namespace fnv_00480070

namespace fnv_00480210 {
struct TESSaveLoadGame
{
    void SaveGameDataOLD(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_00480210_This
{
    void FUN_00480210(unsigned int aiFlags);
};
// @fnv 0x00480210
void FUN_00480210_This::FUN_00480210(unsigned int aiFlags)
{
    if (aiFlags & 0)
    {
        g_TESSaveLoadGame->SaveGameDataOLD((void*)((char*)this + 4), 7);
    }
}
}  // namespace fnv_00480210

extern void* PTR_PTR_01186c74;
extern void* PTR_PTR_01183028;
extern "C" void* FUN_00ec43fb(void* self, int a, void* b, void* c, int d);
struct Thing
{
    void SetByte(int offset, char value, unsigned char flag);
};
// Writes value at byte offset offset - 1, then when flag is nonzero calls FUN_00ec43fb and a method on its result.
// @fnv 0x00480180
void Thing::SetByte(int offset, char value, unsigned char flag)
{
    ((char*)this)[offset - 1] = value;
    if (flag != 0)
    {
        void* p = FUN_00ec43fb(this, 0, &PTR_PTR_01186c74, &PTR_PTR_01183028, 0);
        if (p != 0)
        {
            (*(void(__thiscall**)(void*, int))(*(char**)p + 0x48))(p, 4);
        }
    }
}

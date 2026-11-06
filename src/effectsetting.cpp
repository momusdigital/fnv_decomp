// effectsetting.cpp: EffectSetting, EndianSwappableData, EffectSettingList, EffT (41 functions)

#include "effectsetting_decls.h"

// Compares the effect name with name case-insensitively and, if they differ, sets the full name to name.
// @fnv 0x00408570
void EffectSetting::UpdateEffectName(const char* name)
{
    int comparison = GetEffectName().StrCmp(name, true);
    if (comparison)
        SetFullName(name);
}

// @fnv 0x00408880
bool EffectSetting::HasEffectID()
{
    return m_iEffectID > 0;
}

// @fnv 0x004088a0
bool EffectSetting::UsesAssociatedActorValue()
{
    return m_iEffectID < 0;
}

// @fnv 0x00408a20
bool EffectSetting::HasNoAssociatedActorValue()
{
    return m_iActorValue < 0;
}

// Loads an EffectSetting record from a TESFile, dispatching on chunk IDs to read editor ID, name, description, texture, model, data and counter effects.
// @fnv 0x00407ac0
bool EffectSetting::Load(TESFile* file)
{
    if (file->GetTESForm() != 16)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x54444f4d:  // MODT
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:  // DATA
            memset(&data, 0, sizeof(data));
            data.fSpeed = 1.0f;
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            SetFlag(PLAYER_KNOWS, false);
            break;
        case 0x45435345:  // ESCE
        {
            struct CounterEffectReference
            {
                unsigned int formID;
                EffectSetting* effect;
            } counterRef;
            file->GetChunkData(&counterRef.formID);
            if (file->IsEndianConversionRequired())
                BSEndian(&counterRef.formID, EndianSizeTag<4>());
            TESForm::RemapFormIDForFile(counterRef.formID, file);
            counterRef.effect = dynamic_cast<EffectSetting*>(TESForm::GetFormByID(counterRef.formID));
            if (counterRef.effect)
            {
                counterEffects.AddHead(counterRef.effect);
                data.m_sCounterEffectCount = counterEffects.ItemsInList();
            }
            else
                Warning("FORMS: Invalid form ID (%d) for effect setting found while loading counter effects for %s.",
                        counterRef.formID, GetName());
        }
        break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the effect's associated item, light, sounds and shaders by form ID, warns on missing forms, and marks the item initialized.
// @fnv 0x00407e50
void EffectSetting::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;
    if (IsAssociatedFormUsed() && !GetFlag(0x180000))
    {
        unsigned int associatedID = reinterpret_cast<unsigned int>(data.m_pAssociatedForm);
        if (associatedID)
        {
            TESForm::RemapFormIDForFile(associatedID, GetFile(-1));
            data.m_pAssociatedForm = TESForm::GetFormByID(associatedID);
            if (!data.m_pAssociatedForm)
                Warning("MASTERFILE: Could not find associated item (%08X) for Effect '%s' (%08X).", associatedID,
                        GetName(), GetFormID());
        }
    }
    else
        data.m_pAssociatedForm = 0;
    formID = reinterpret_cast<unsigned int>(GetLight());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetLight(dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID)));
        if (!GetLight())
            Warning("MASTERFILE: Could not find light (%08X) for Effect '%s' (%08X).", formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetCastSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetCastSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetCastSound())
            Warning("MASTERFILE: Could not find cast sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetBoltSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetBoltSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetBoltSound())
            Warning("MASTERFILE: Could not find bolt sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetHitSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetHitSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetHitSound())
            Warning("MASTERFILE: Could not find hit sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetAreaSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetAreaSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetAreaSound())
            Warning("MASTERFILE: Could not find area sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetEffectShader());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetEffectShader(dynamic_cast<TESEffectShader*>(TESForm::GetFormByID(formID)));
        if (!GetEffectShader())
            Warning("MASTERFILE: Could not find effect shader (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetEnchantEffectShader());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetEnchantEffectShader(dynamic_cast<TESEffectShader*>(TESForm::GetFormByID(formID)));
        if (!GetEnchantEffectShader())
            Warning("MASTERFILE: Could not find enchant effect shader (%08X) for Effect '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x004088c0
int EffectSetting::FUN_004088c0()
{
    if (m_iActorValue < 0)
        --m_iActorValue;
    else
        ++m_iActorValue;
    return m_iActorValue;
}
// Sets or clears the given EffectFlag bit in data.iFlags according to value.
// @fnv 0x00407e00
void EffectSetting::SetFlag(EffectFlag flag, bool value)
{
    value ? data.iFlags |= flag : data.iFlags &= ~flag;
}
// @fnv 0x00408970
int EffectSetting::QueueAssociatedItem()
{
    if (m_iActorValue > 0)
        Warning("GAME EFFECTS: Trying to Queue up an Effect Associated Item which is already loaded");
    else
        --m_iActorValue;
    return m_iActorValue;
}
// @fnv 0x004089c0
int EffectSetting::NormalizeEffectLoadedCount()
{
    m_iActorValue = (int)FUN_00408820((float)m_iActorValue);
    return m_iActorValue;
}

struct FUN_004077c0_shell : public TESForm
{
    bool FUN_004077c0();
};

// @fnv 0x004077c0
bool FUN_004077c0_shell::FUN_004077c0()
{
    return (*(unsigned int*)((char*)this + 8) & 0x4000) ? true : false;
}

struct FUN_004077e0_shell : public EffectSetting
{
    void* FUN_004077e0();
};

// @fnv 0x004077e0
void* FUN_004077e0_shell::FUN_004077e0()
{
    return reinterpret_cast<char*>(this) + 0xA0;
}

struct FUN_00407820_shell : public EffectSetting
{
    TESEffectShader* FUN_00407820();
};

// @fnv 0x00407820
TESEffectShader* FUN_00407820_shell::FUN_00407820()
{
    return *(TESEffectShader**)((char*)this + 0x78);
}

struct FUN_004078a0_shell : public EffectSetting
{
    void SetEffectID(int);
};

// @fnv 0x004078a0
void FUN_004078a0_shell::SetEffectID(int aeID)
{
    *(int*)((char*)this + 0x98) = aeID;
}

struct FUN_00408680_shell : public EffectSetting
{
    bool HasAllFlags(unsigned int);
};

// @fnv 0x00408680
bool FUN_00408680_shell::HasAllFlags(unsigned int aiFlags)
{
    return (*(unsigned int*)((char*)this + 0x58) & aiFlags) == aiFlags;
}

struct FUN_004086e0_shell : public EffectSetting
{
    int UpdateCounter();
};

// Increments or decrements the counter at offset 0xac depending on its sign, then returns the new value.
// @fnv 0x004086e0
int FUN_004086e0_shell::UpdateCounter()
{
    if (*(int*)((char*)this + 0xac) < 0)
    {
        *(int*)((char*)this + 0xac) -= 1;
    }
    else
    {
        *(int*)((char*)this + 0xac) += 1;
    }
    return *(int*)((char*)this + 0xac);
}

struct FUN_00408790_shell : public EffectSetting
{
    int FUN_00408790();
};

// If the associated-item count at offset 0xac is positive, logs a warning; otherwise decrements it, and returns the count.
// @fnv 0x00408790
int FUN_00408790_shell::FUN_00408790()
{
    if (*(int*)((char*)this + 0xac) > 0)
    {
        Warning("GAME EFFECTS: Trying to Queue up an Effect Associated Item which is already loaded");
    }
    else
    {
        *(int*)((char*)this + 0xac) = *(int*)((char*)this + 0xac) - 1;
    }
    return *(int*)((char*)this + 0xac);
}

namespace std {
float __cdecl abs(float);
}

// @fnv 0x00408820
double FUN_00408820(float fValue)
{
    return std::abs(fValue);
}

double __cdecl _fabs(double);

// @fnv 0x00408860
float FUN_00408860(float afValue)
{
    return (float)_fabs((double)afValue);
}

int __cdecl FUN_00ec6da0(const char*, const char*);

// @fnv 0x00408b20
int __cdecl FUN_00408b20(const char* apString1, const char* apString2)
{
    return FUN_00ec6da0(apString1, apString2);
}

struct FUN_004ee4b0_shell : public EffectSetting
{
    void FUN_004ee4b0(float);
};

// @fnv 0x004ee4b0
void FUN_004ee4b0_shell::FUN_004ee4b0(float afBaseCost)
{
    *(float*)((char*)this + 0x5c) = afBaseCost;
}

struct FUN_00591300_shell : public TESFullName
{
    void FUN_00591300();
};

// @fnv 0x00591300
void FUN_00591300_shell::FUN_00591300()
{
    ((BSStringT<char>*)((char*)this + 4))->BSStringT<char>::~BSStringT<char>();
}

struct FUN_00810570_shell : public EffectSetting
{
    void SetAssociatedActorValue(int);
};

// @fnv 0x00810570
void FUN_00810570_shell::SetAssociatedActorValue(int aeAssociatedActorValue)
{
    *(int*)((char*)this + 0x9c) = aeAssociatedActorValue;
}

struct FUN_00857230_shell : public EffectSetting
{
    void SetSound(TESSound*);
};

// @fnv 0x00857230
void FUN_00857230_shell::SetSound(TESSound* apValue)
{
    *(TESSound**)((char*)this + 0x88) = apValue;
}

struct FUN_008ce390_shell : public EffectSetting
{
    TESSound* FUN_008ce390();
};

// @fnv 0x008ce390
TESSound* FUN_008ce390_shell::FUN_008ce390()
{
    return *(TESSound**)((char*)this + 0x8c);
}

void __cdecl operator delete(void*);
struct S
{
    void FUN_00407230();
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00407200
void* S::DestroyIfFlagged(unsigned int flags)
{
    FUN_00407230();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" short __cdecl FUN_00ec3bda(short);

// Replaces the short value pointed to by p with the result of FUN_00ec3bda applied to it.
// @fnv 0x00407a90
void __cdecl FUN_00407a90(short* psValue)
{
    short* tmp = psValue;
    *tmp = FUN_00ec3bda(*tmp);
}

struct FUN_00408550_Cls
{
    char _pad[0x6C];
    short _v;
    int GetShortValue();
};
// @fnv 0x00408550
int FUN_00408550_Cls::GetShortValue()
{
    return _v;
}

struct S3e60
{
    bool FUN_00403e60(unsigned int);
};
struct S86a0
{
    int GetProjectileType();
};
// @fnv 0x004086a0
int S86a0::GetProjectileType()
{
    return (((S3e60*)this)->FUN_00403e60(0x2000000) ? 2 : 0) + (((S3e60*)this)->FUN_00403e60(0x4000000) ? 1 : 0);
}

struct Unk00408730
{
    int ClampCounterTowardZero();
};
// Steps the int at offset 0xAC one unit toward zero and returns the resulting value.
// @fnv 0x00408730
int Unk00408730::ClampCounterTowardZero()
{
    if (*(int*)((char*)this + 0xAC) < 0)
        *(int*)((char*)this + 0xAC) = *(int*)((char*)this + 0xAC) + 1;
    else if (*(int*)((char*)this + 0xAC) > 0)
        *(int*)((char*)this + 0xAC) = *(int*)((char*)this + 0xAC) - 1;
    return *(int*)((char*)this + 0xAC);
}

struct FUN_004087e0_Shell
{
    int FUN_004087e0();
};
// Converts the int at offset 0xac to float, passes it to FUN_00408820, stores the result back at 0xac and returns it.
// @fnv 0x004087e0
int FUN_004087e0_Shell::FUN_004087e0()
{
    *(int*)((char*)this + 0xac) = (int)FUN_00408820((float)*(int*)((char*)this + 0xac));
    return *(int*)((char*)this + 0xac);
}

struct Holder00408910
{
    char pad[0xA8];
    int valA8;
    int StepTowardZero();
};
// Moves valA8 one step toward zero (increments if negative, decrements if positive) and returns it.
// @fnv 0x00408910
int Holder00408910::StepTowardZero()
{
    if (valA8 < 0)
        valA8++;
    else if (valA8 > 0)
        valA8--;
    return valA8;
}

struct FUN_00408a00_Struct
{
    int _pad[42];
    int _val;
    bool IsPositive();
};
// @fnv 0x00408a00
bool FUN_00408a00_Struct::IsPositive()
{
    return _val > 0;
}

struct Dummy00501c30
{
    bool IsNotOne(const char*);
    bool FUN_00501c30(const char*);
};
// Returns the negation of IsNotOne for the given string argument.
// @fnv 0x00501c30
bool Dummy00501c30::FUN_00501c30(const char* pcString)
{
    return !IsNotOne(pcString);
}

struct S501c60
{
    int CompareString(const char*, int);
    bool IsNotOne(const char*);
};
// Returns true when CompareString called with the string and 1 returns zero.
// @fnv 0x00501c60
bool S501c60::IsNotOne(const char* a)
{
    return !this->CompareString(a, 1);
}

struct Flt
{
    operator unsigned int() const;
};
struct FUN_00501c90_shell : BSStringT<char>
{
    int CompareString(BSStringT<char> const* arString, bool abIgnoreCase);
};
// @fnv 0x00501c90
int FUN_00501c90_shell::CompareString(BSStringT<char> const* apString, bool abIgnoreCase)
{
    return StrCmp((char const*)((Flt const*)apString)->operator unsigned int(), abIgnoreCase);
}

struct TESChallenge
{
    int GetThreshold();
    int GetInterval();
};

struct LowProcess
{
    void SetPackageObjectType(int value);
};

struct TESGrass
{
    float GetLowestAllowedSlope();
};

struct IMH
{
    int FUN_00586150();
};

struct TargetDoorController
{
};

struct MiddleHighProcess
{
    void AddDeferredHideLimb(TargetDoorController* value);
};

struct Date
{
};

struct PlayerQuestData
{
    void SetLogDate(Date* value);
};

struct TES
{
    void* GetLogDate();
};

struct FUN_00407860_class
{
    void FUN_00407860(float value);
};

struct FUN_00407880_Class
{
    void FUN_00407880(float value);
};

struct PathingRequest
{
    float GetCenterRadius();
    void SetCenterRadius(float value);
};

struct S3c60
{
    int GetArchetype();
};

struct FUN_009e3360_Class
{
    void SetMode(unsigned int value);
};

struct TESDataHandler
{
    void* GetBGSRecipeList();
    unsigned int GetNextID();
};

struct DH : public TESDataHandler
{
};

extern DH* g_dataHandler;

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm* value);
};

struct EffectSettingAux
{
    void FUN_004ee4b0(float value);
    void SetAssociatedActorValue(int value);
    void SetEffectID(int value);
    int GetEffectID();
};

struct TESEffectShaderAux
{
    float FUN_00644930();
};

struct FUN_00408600_class
{
    void CopyValuesFromList(void* value);
};

float __fastcall GetField90Float(char* value);

struct FUN_00407600_class : public EffectSetting
{
    void CopyFromEffectSetting(TESForm* apCopy);
};

// Copies fields from an EffectSetting into this object, assigning a new ref ID when this form is non-temporary and has no form ID.
// @fnv 0x00407600
void FUN_00407600_class::CopyFromEffectSetting(TESForm* apCopy)
{
    EffectSetting* psetting = dynamic_cast<EffectSetting*>(apCopy);
    if (!psetting)
        return;

    reinterpret_cast<FUN_005e78f0_t*>(this)->FUN_004851b0(apCopy);
    reinterpret_cast<LowProcess*>(this)->SetPackageObjectType(
        reinterpret_cast<TESChallenge*>(psetting)->GetThreshold());
    reinterpret_cast<EffectSettingAux*>(this)->FUN_004ee4b0(reinterpret_cast<TESGrass*>(psetting)->GetLowestAllowedSlope());
    reinterpret_cast<EffectSettingAux*>(this)->SetAssociatedActorValue(
        reinterpret_cast<IMH*>(psetting)->FUN_00586150());
    reinterpret_cast<MiddleHighProcess*>(this)->AddDeferredHideLimb(
        reinterpret_cast<TargetDoorController*>(reinterpret_cast<EffectSettingAux*>(psetting)->GetEffectID()));
    reinterpret_cast<PlayerQuestData*>(this)->SetLogDate(
        reinterpret_cast<Date*>(reinterpret_cast<TES*>(psetting)->GetLogDate()));
    reinterpret_cast<FUN_00407860_class*>(this)->FUN_00407860(GetField90Float(reinterpret_cast<char*>(psetting)));
    reinterpret_cast<FUN_00407880_Class*>(this)->FUN_00407880(
        reinterpret_cast<TESEffectShaderAux*>(psetting)->FUN_00644930());
    reinterpret_cast<PathingRequest*>(this)->SetCenterRadius(
        reinterpret_cast<PathingRequest*>(psetting)->GetCenterRadius());
    reinterpret_cast<EffectSettingAux*>(this)->SetEffectID(reinterpret_cast<S3c60*>(psetting)->GetArchetype());
    reinterpret_cast<FUN_009e3360_Class*>(this)->SetMode(reinterpret_cast<TESChallenge*>(psetting)->GetInterval());
    SetLight(psetting->GetLight());
    SetEffectShader(psetting->GetEffectShader());
    SetEnchantEffectShader(psetting->GetEnchantEffectShader());
    SetCastSound(psetting->GetCastSound());
    SetBoltSound(psetting->GetBoltSound());
    SetHitSound(psetting->GetHitSound());
    SetAreaSound(psetting->GetAreaSound());
    reinterpret_cast<FUN_00408600_class*>(this)->CopyValuesFromList(
        reinterpret_cast<TESDataHandler*>(psetting)->GetBGSRecipeList());

    if (!IsTemporary() && GetFormID() == 0)
        SetRefID(g_dataHandler->GetNextID(), true);
}

void BSEndian(unsigned int*, EndianSizeTag<2>);

struct EndianSwappableData
{
    void SwapEndianFields();
};

// Byte-swaps the 4-byte fields at offsets 0x00-0x40 and the 2-byte field at 0x14 of this object via BSEndian.
// @fnv 0x004078c0
void EndianSwappableData::SwapEndianFields()
{
    BSEndian((unsigned int*)((unsigned char*)this + 0x00), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x04), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x44), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x08), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x0C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x10), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x14), EndianSizeTag<2>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x18), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x1C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x20), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x24), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x28), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x2C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x30), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x34), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x38), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x3C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x40), EndianSizeTag<4>());
}

struct EffectSettingList : public BSSimpleList<EffectSetting*>
{
    ~EffectSettingList();
};

class FormBase
{
  public:
    virtual ~FormBase();
    virtual void ClearData();
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
};

class FUN_00407230 : public FormBase, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
  public:
    bool(__cdecl* m_pEffectSettingCallback)(EffectSetting*, void*);
    void* m_pPredicateData;
    EffectSetting__EffectSettingData data;
    EffectSettingList counterEffects;
    int m_iActorValue;
    int m_iEffectID;
    ~FUN_00407230();
};

// @fnv 0x00407230
FUN_00407230::~FUN_00407230()
{
    ClearData();
}

EffectSettingList::~EffectSettingList()
{}

struct SubListA0
{
    unsigned int unk00;
    void Reset();
    void AddItem(int* item);
};

struct TESFormLike
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned short m_6c;
    unsigned short unk6E;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    SubListA0 m_a0;
    int* GetVal();
    TESFormLike* Next();
};

// Resets m_a0 and m_6c, then walks the list from arg, adding each non-zero GetVal result to m_a0 and counting them in m_6c.
// @fnv 0x00408600
void FUN_00408600_class::CopyValuesFromList(void* pSourceList)
{
    int val;
    ((TESFormLike*)this)->m_a0.Reset();
    ((TESFormLike*)this)->m_6c = 0;
    for (TESFormLike* cur = (TESFormLike*)pSourceList; cur != 0 && (val = *cur->GetVal()) != 0; cur = cur->Next())
    {
        ((TESFormLike*)this)->m_a0.AddItem(&val);
        ((TESFormLike*)this)->m_6c++;
    }
}

struct ListT
{
    unsigned int* FUN_006815c0();
    ListT* FUN_00726070();
};
struct EffT
{
    char pad00[0xa0];
    ListT m_a0;
    bool FUN_00485270(void* p);
    int FUN_006286d0();
    double FUN_00639b20();
    int FUN_00586150();
    int FUN_005f5f80();
    int FUN_0070ec90();
    int FUN_008d8520();
    int FUN_004fd380();
    int FUN_00407820();
    int FUN_00407840();
    double FUN_009b0bd0();
    int FUN_004fb070();
    int FUN_004fd3c0();
    int FUN_004fd3e0();
    int FUN_008ce390();
    int GetShortValue();
    int FUN_00810fd0();
    bool IsDifferentFrom(void* param);
};
extern int DAT_01183028;
extern int DAT_011837c4;
void* __cdecl FUN_00ec43fb(void* a1, int a2, int* a3, int* a4, int a5);

// @fnv 0x004082f0
bool EffT::IsDifferentFrom(void* pObject)
{
    EffT* other = (EffT*)FUN_00ec43fb(pObject, 0, &DAT_01183028, &DAT_011837c4, 0);
    if (other == 0)
        return 1;
    if (FUN_00485270(pObject))
        return 1;
    if (FUN_006286d0() != other->FUN_006286d0() || !(FUN_00639b20() == other->FUN_00639b20()) ||
        FUN_00586150() != other->FUN_00586150() || FUN_005f5f80() != other->FUN_005f5f80() ||
        FUN_0070ec90() != other->FUN_0070ec90() || FUN_008d8520() != other->FUN_008d8520() ||
        FUN_004fd380() != other->FUN_004fd380() || FUN_00407820() != other->FUN_00407820() ||
        FUN_00407840() != other->FUN_00407840() || !(FUN_009b0bd0() == other->FUN_009b0bd0()) ||
        FUN_004fb070() != other->FUN_004fb070() || FUN_004fd3c0() != other->FUN_004fd3c0() ||
        FUN_004fd3e0() != other->FUN_004fd3e0() || FUN_008ce390() != other->FUN_008ce390() ||
        GetShortValue() != other->GetShortValue() || FUN_00810fd0() != other->FUN_00810fd0())
        return 1;
    ListT* pa4 = &m_a0;
    ListT* pbX = &other->m_a0;
    while (pa4 && pbX)
    {
        unsigned int av = *pa4->FUN_006815c0();
        unsigned int bv5 = *pbX->FUN_006815c0();
        if (av != bv5)
            return 1;
        pa4 = pa4->FUN_00726070();
        pbX = pbX->FUN_00726070();
    }
    return 0;
}

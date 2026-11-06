// fallout_shared/bgsperk.cpp: BGSEntryPointPerkEntry, BGSPerk, BGSAbilityPerkEntry, BGSQuestPerkEntry and more (56 functions)

#include "bgsperk_worker.h"
#include <malloc.h>

// @fnv 0x005e9fb0
unsigned char BGSEntryPointPerkEntry::GetFunction()
{
    return Data.m_ucFunction;
}

// Calls the actor's virtual method at vtable index 0x129, passing this entry point and the apply flag.
// @fnv 0x005eaa50
void BGSEntryPointPerkEntry::ApplyEntryPointEffect(Actor* actor, bool apply)
{
    reinterpret_cast<void(__thiscall*)(Actor*, BGSEntryPointPerkEntry*, bool)>(
        (*reinterpret_cast<void***>(actor))[0x129])(actor, this, apply);
}

// @fnv 0x005ea330
void BGSEntryPointPerkEntry::InitItem(TESForm* form)
{
    unsigned int i;

    for (i = 0; i < Data.m_ucConditionCount; ++i)
        m_pConditions[i].InitItem(form);

    if (m_pFunctionData)
        m_pFunctionData->InitItem(form);
}

// @fnv 0x005ead20
void BGSPerk::InitItem()
{
    struct EntryListLocals
    {
        BGSPerkEntry* entry;
        BSSimpleList<BGSPerkEntry*>* list;
    } locals;

    if (GetInitialized())
        return;

    m_kConditions.InitItem(reinterpret_cast<TESForm*>(this));
    locals.list = &m_kEntryList;
    while (locals.list)
    {
        locals.entry = locals.list->GetItem();
        if (locals.entry)
            locals.entry->InitItem(reinterpret_cast<TESForm*>(this));
        locals.list = locals.list->GetNext();
    }
    SetInitializationState(true);
}

// Iterates the perk entry list and runs each entry whose rank matches rank-1 and whose function type is 2.
// @fnv 0x005eb980
void BGSPerk::ApplyPerkEntries(Actor* actor, unsigned char rank, bool alternate)
{
    struct EntryListLocals
    {
        BGSPerkEntry* entry;
        BSSimpleList<BGSPerkEntry*>* list;
    } locals;

    locals.list = &m_kEntryList;
    while (locals.list)
    {
        locals.entry = locals.list->GetItem();
        if (locals.entry && reinterpret_cast<PatrolActorPackageData*>(locals.entry)->IsPatrolling() + 1 == rank &&
            reinterpret_cast<PerkEntryFunctionType*>(locals.entry)->GetFunctionType() == 2)
        {
            locals.entry->ApplyEntryPointEffect(actor, alternate);
        }
        locals.list = locals.list->GetNext();
    }
}

// @fnv 0x005eada0
bool BGSPerk::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x56)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch ((int)chunk)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 'CSED':
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 'NOCI':
            TESTexture::ReadTextureData(this, file);
            break;
        case 'ADTC':
            m_kConditions.Load(file);
            break;
        case 'EKRP': {
            struct
            {
                struct
                {
                    unsigned char type, rank, priority;
                } data;
                BGSPerkEntry* entry;
                unsigned int size;
            } prkeRecord;
            prkeRecord.size = file->GetChunkSize();
            if (prkeRecord.size != 3)
                return false;
            file->GetChunkData(&prkeRecord.data, prkeRecord.size);
            prkeRecord.entry = CreatePerkEntry(prkeRecord.data.type);
            if (!prkeRecord.entry)
                return false;
            prkeRecord.entry->LoadFromSaveData(&prkeRecord.data);
            if (!prkeRecord.entry->Load(file))
                return false;
            AppendPerkEntry(prkeRecord.entry);
            break;
        }
        case 'ATAD': {
            unsigned int size = file->GetChunkSize();
            if (size != 5)
            {
                if (size == 3)
                {
                    struct
                    {
                        bool trait;
                        unsigned char level;
                        unsigned char ranks;
                    } data;
                    data.trait = false;
                    data.level = 0;
                    data.ranks = 1;
                    file->GetChunkData(&data, 3);
                    Data.m_bTrait = data.trait;
                    Data.cLevel = data.level;
                    Data.m_ucRankCount = data.ranks;
                }
                else if (size == 4)
                {
                    struct
                    {
                        bool trait;
                        unsigned char level;
                        unsigned char ranks;
                        bool playable;
                    } data;
                    data.trait = false;
                    data.level = 0;
                    data.ranks = 1;
                    data.playable = true;
                    file->GetChunkData(&data, 4);
                    Data.m_bTrait = data.trait;
                    Data.cLevel = data.level;
                    Data.m_ucRankCount = data.ranks;
                    Data.bPlayable = data.playable;
                }
                else
                    return false;
            }
            else
                file->GetChunkData(&Data, 5);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005ea790
bool BGSEntryPointPerkEntry::Load(TESFile* file)
{
    unsigned int chunk;
    unsigned char condition = 0;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch ((int)chunk)
        {
        case 'ATAD': {
            unsigned int size = file->GetChunkSize();
            if (size != 3)
                return false;
            file->GetChunkData(&Data, size);
            m_pConditions = new PerkEntryConditionSet[Data.m_ucConditionCount];
            break;
        }
        case 'CKRP':
            file->GetChunkData(&condition, 1);
            break;
        case 'ADTC':
            if (!m_pConditions)
                return false;
            m_pConditions[condition].Load(file);
            break;
        case 'TFPE': {
            unsigned char type = 0;
            unsigned int size = file->GetChunkSize();
            if (size != 1)
                return false;
            file->GetChunkData(&type, 0);
            m_pFunctionData = FUN_005e6280(type);
            if (!m_pFunctionData)
                return false;
            break;
        }
        case 'DFPE':
        case '2FPE':
        case 'RHCS':
        case 'ADCS':
        case 'XTCS':
        case 'ORCS':
        case 'VRCS':
            if (!m_pFunctionData)
            {
                Warning("MASTERFILE: Function data chunk is loading without function data existing on perk entry");
                return false;
            }
            m_pFunctionData->Load(file);
            break;
        case 'FKRP':
            return true;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005ea060
bool BGSEntryPointPerkEntry::CheckConditionFilters(unsigned int count, TESForm** subjects)
{
    if (count != Data.m_ucConditionCount)
    {
        Warning(
            "FORMS: BGSEntryPointPerkEntry::CheckConditionFilters() was called with %i filter forms, but there are %i conditions",
            count, Data.m_ucConditionCount);
        return false;
    }
    unsigned int i;
    TESForm* form;
    for (i = 0; i < count; ++i)
    {
        form = subjects[i];
        TESObjectREFR* reference = 0;
        TESObjectREFR temporary;
        temporary.NotifySaveLoadGameOfFormChange();
        if (form->IsActor_InEditor())
        {
            temporary.ClearReferenceState(static_cast<TESBoundObject*>(form));
            reference = &temporary;
        }
        else if (form->GetIsReference())
            reference = static_cast<TESObjectREFR*>(form);
        if (reference)
        {
            bool result;
            if (!m_pConditions[i].ContainsTrait(reference, 0, result, false))
                return false;
        }
        else
            Warning("DEFAULT: Bad Filter form %08X %s sent to BGSEntryPointPerkEntry::CheckConditionFilters.",
                    reference->GetFormID(), reference->GetName());
    }
    return true;
}

// @fnv 0x005eaab0
BGSPerk::BGSPerk()
{
    SetFormType(kPerk);
    ResetFormData();
}

// Resolves Data.pQuest by form ID and warns if the quest cannot be found, naming the owner object by name or form ID.
// @fnv 0x005e9880
void BGSQuestPerkEntry::InitItem(TESForm* form)
{
    if (Data.pQuest)
    {
        unsigned int id = reinterpret_cast<unsigned int>(Data.pQuest);
        TESForm::RemapFormIDForFile(id, form->GetFile(-1));
        Data.pQuest = dynamic_cast<TESQuest*>(TESForm::GetFormByID(id));
        if (!Data.pQuest)
        {
            if (reinterpret_cast<BGSCameraPath*>(form)->HasNameForWarning())
                Warning("MASTERFILE: Unable to find quest (%08X) on owner object \"%s\".", id, form->GetName());
            else
                Warning("MASTERFILE: Unable to find quest (%08X) on owner object (%08X).", id, form->GetFormID());
        }
    }
}

// Resolves the stored ability form ID against the owner's file and warns if the resulting form is not a SpellItem.
// @fnv 0x005e9c00
void BGSAbilityPerkEntry::InitItem(TESForm* apOwner)
{
    if (m_pSpell)
    {
        unsigned int id = reinterpret_cast<unsigned int>(m_pSpell);
        TESForm::RemapFormIDForFile(id, apOwner->GetFile(-1));
        m_pSpell = dynamic_cast<SpellItem*>(TESForm::GetFormByID(id));
        if (!m_pSpell)
        {
            if (reinterpret_cast<BGSCameraPath*>(apOwner)->HasNameForWarning())
                Warning("MASTERFILE: Unable to find ability (%08X) on owner object \"%s\".", id, apOwner->GetName());
            else
                Warning("MASTERFILE: Unable to find ability (%08X) on owner object (%08X).", id, apOwner->GetFormID());
        }
    }
}

// Reads the DATA chunk (4-byte spell id, endian-swapped if needed) into the perk entry and stops at the PKRF chunk.
// @fnv 0x005e9e20
bool BGSAbilityPerkEntry::Load(TESFile* file)
{
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch ((int)chunk)
        {
        case 'ATAD': {
            unsigned int size = file->GetChunkSize();
            if (size != 4)
                return false;
            unsigned int id = 0;
            file->GetChunkData(&id, 0);
            if (file->IsEndianConversionRequired())
                BSEndian(&id, EndianSizeTag<4>());
            m_pSpell = reinterpret_cast<SpellItem*>(id);
            break;
        }
        case 'FKRP':
            return true;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Reads chunks from the file, loading the 8-byte DATA chunk into Data and converting endianness if required, until the FKRP chunk or end of chunks.
// @fnv 0x005e9b00
bool BGSQuestPerkEntry::Load(TESFile* file)
{
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch ((int)chunk)
        {
        case 'ATAD': {
            unsigned int size = file->GetChunkSize();
            if (size != 8)
                return false;
            file->GetChunkData(&Data, size);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<RegionDataEntry*>(&Data)->Endian();
            break;
        }
        case 'FKRP':
            return true;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005eb460
int ComparePerkEntries(BGSPerkEntry* apEntryA, BGSPerkEntry* apEntryB)
{
    if (reinterpret_cast<PatrolActorPackageData*>(apEntryA)->IsPatrolling() <
        reinterpret_cast<PatrolActorPackageData*>(apEntryB)->IsPatrolling())
        return -1;
    else if (reinterpret_cast<PatrolActorPackageData*>(apEntryA)->IsPatrolling() >
             reinterpret_cast<PatrolActorPackageData*>(apEntryB)->IsPatrolling())
        return 1;
    else if (reinterpret_cast<TESAIForm*>(apEntryA)->FUN_004f6de0() >
             reinterpret_cast<TESAIForm*>(apEntryB)->FUN_004f6de0())
        return -1;
    else if (reinterpret_cast<TESAIForm*>(apEntryA)->FUN_004f6de0() <
             reinterpret_cast<TESAIForm*>(apEntryB)->FUN_004f6de0())
        return 1;
    else if (reinterpret_cast<PerkEntryFunctionType*>(apEntryA)->GetFunctionType() <
             reinterpret_cast<PerkEntryFunctionType*>(apEntryB)->GetFunctionType())
        return -1;
    else if (reinterpret_cast<PerkEntryFunctionType*>(apEntryA)->GetFunctionType() >
             reinterpret_cast<PerkEntryFunctionType*>(apEntryB)->GetFunctionType())
        return 1;
    return 0;
}

// Inserts entry into the perk entry list if it is non-null and not already present, using ComparePerkEntries for ordering.
// @fnv 0x005eb410
bool BGSPerk::AppendPerkEntry(BGSPerkEntry* entry)
{
    if (!entry || m_kEntryList.IsInList(entry))
        return false;
    m_kEntryList.Insert(entry, ComparePerkEntries);
    return true;
}

// @fnv 0x005e9bd0
BGSAbilityPerkEntry* BGSAbilityPerkEntry::Initialize()
{
    reinterpret_cast<BGSIdleMarker*>(this)->FUN_005e9530();
    *reinterpret_cast<unsigned int**>(this) = BGSAbilityPerkEntry_vtable;
    m_pSpell = 0;
    return this;
}

// @fnv 0x005eb680
unsigned int TESConditionItem::FUN_005eb680()
{
    return function;
}

struct RGBColor
{
    void Endian();
    unsigned char m_ucRedValue;
    unsigned char m_ucRank;
    unsigned char m_ucRegionPriority;
};
typedef char _sizecheck_PerkEntrySaveData[sizeof(RGBColor) == 3 ? 1 : -1];
struct FUN_005e96b0_shell : public BGSPerkEntry
{
    void LoadFromSaveData(RGBColor*);
};

// Copies the two bytes from the save data into the perk entry at offsets 4 and 5.
// @fnv 0x005e96b0
void FUN_005e96b0_shell::LoadFromSaveData(RGBColor* apSaveData)
{
    *((unsigned char*)this + 4) = apSaveData->m_ucRank;
    *((unsigned char*)this + 5) = apSaveData->m_ucRegionPriority;
}

struct FUN_005ec040_stand
{
    char flags;
    unsigned char IsFlagSet();
};
// @fnv 0x005ec040
unsigned char FUN_005ec040_stand::IsFlagSet()
{
    return (flags & 1) != 0;
}

struct FUN_005ec060_shell : public TESConditionItem
{
    int GetComparisonCondition();
};

// Extracts bits 5-7 of the first byte of this condition item and returns them as an integer.
// @fnv 0x005ec060
int FUN_005ec060_shell::GetComparisonCondition()
{
    int ival = *(char*)this & 0xe0;
    ival >>= 5;
    return ival;
}

struct FUN_005e95b0_shell : BGSPerkEntry
{
    void __thiscall FUN_005e95b0(BGSPerkEntry* apCopy);
};

// Copies the two BGSPerkEntry fields from apCopy into this entry.
// @fnv 0x005e95b0
void __thiscall FUN_005e95b0_shell::FUN_005e95b0(BGSPerkEntry* apCopy)
{
    this->m_ucRank = apCopy->m_ucRank;
    this->m_ucRegionPriority = apCopy->m_ucRegionPriority;
}

struct FUN_005e95e0_shell : BGSPerkEntry
{
    bool Compare(BGSPerkEntry* apCompare);
};

// @fnv 0x005e95e0
bool FUN_005e95e0_shell::Compare(BGSPerkEntry* apCompare)
{
    if (m_ucRank != apCompare->m_ucRank)
        return true;
    if (m_ucRegionPriority != apCompare->m_ucRegionPriority)
        return true;
    return false;
}

// @fnv 0x005eb7e0
void* __fastcall FUN_005eb7e0(void* this_ptr)
{
    return reinterpret_cast<char*>(this_ptr) + 0x5FC;
}

struct FUN_005e9800 : public BGSPerkEntry
{
    FUN_005e9800();
    TESForm* pQuest;
    char cStage;
};
struct FUN_005e9bd0 : public BGSPerkEntry
{
    FUN_005e9bd0();
    SpellItem* m_pSpell;
};
struct FUN_005e9f60 : public BGSPerkEntry
{
    FUN_005e9f60();
    unsigned char m_ucEntryPoint;
    unsigned char m_ucFunction;
    unsigned char cConditionTabs;
    void* m_pFunctionData;
    void* pConditions;
};
// Allocates and returns a new perk entry object matching the given perk entry type, or null for unknown types.
// @fnv 0x005e96e0
BGSPerkEntry* CreatePerkEntry(int aePerkEntryType)
{
    switch (aePerkEntryType)
    {
    case 0:
        return new FUN_005e9800;
    case 1:
        return new FUN_005e9bd0;
    case 2:
        return new FUN_005e9f60;
    }
    return 0;
}

bool FUN_00401500();
void AppendChunk(unsigned int, void*, unsigned int);
struct QuestStageEntry
{
    TESForm* pQuest;
    char cStage;
};
struct FUN_005e9a70_t : public BGSPerkEntry
{
    void FUN_005e9a70();
    void StartPerkEntry(int);
    void FinishPerkEntry();
    QuestStageEntry Data;
};
// @fnv 0x005e9a70
void FUN_005e9a70_t::FUN_005e9a70()
{
    TESForm* ptempQuest;
    StartPerkEntry(0);
    ptempQuest = Data.pQuest;
    if (Data.pQuest)
        Data.pQuest = (TESForm*)Data.pQuest->GetFormID();
    if (FUN_00401500())
        reinterpret_cast<RegionDataEntry*>(&Data)->Endian();
    AppendChunk(0x41544144, &Data, 8);
    if (FUN_00401500())
        reinterpret_cast<RegionDataEntry*>(&Data)->Endian();
    Data.pQuest = ptempQuest;
    FinishPerkEntry();
}

struct FUN_005ea2c0
{
    ~FUN_005ea2c0();
    void* pConditionList;
};
struct EntryPointFunctionData_t
{
    virtual ~EntryPointFunctionData_t();
};
struct EntryPointData_t
{
    unsigned char m_ucEntryPoint;
    unsigned char m_ucFunction;
    unsigned char cConditionTabs;
};
struct FUN_005ea230_t : public BGSPerkEntry
{
    void ClearEntryPointData();
    EntryPointData_t Data;
    EntryPointFunctionData_t* m_pFunctionData;
    FUN_005ea2c0* m_pConditions;
};
// Deletes the condition list and function data, zeroes the entry point data bytes, and nulls both pointers.
// @fnv 0x005ea230
void FUN_005ea230_t::ClearEntryPointData()
{
    delete[] m_pConditions;
    delete m_pFunctionData;
    Data.m_ucEntryPoint = 0;
    Data.m_ucFunction = 0;
    Data.cConditionTabs = 0;
    m_pConditions = 0;
    m_pFunctionData = 0;
}

// @fnv 0x005eb550
int FUN_005eb550(BGSPerkEntry* apEntryA, BGSPerkEntry* apEntryB)
{
    if (reinterpret_cast<TESAIForm*>(apEntryA)->FUN_004f6de0() > reinterpret_cast<TESAIForm*>(apEntryB)->FUN_004f6de0())
        return -1;
    else if (reinterpret_cast<TESAIForm*>(apEntryA)->FUN_004f6de0() <
             reinterpret_cast<TESAIForm*>(apEntryB)->FUN_004f6de0())
        return 1;
    else if (reinterpret_cast<PatrolActorPackageData*>(apEntryA)->IsPatrolling() <
             reinterpret_cast<PatrolActorPackageData*>(apEntryB)->IsPatrolling())
        return -1;
    else if (reinterpret_cast<PatrolActorPackageData*>(apEntryA)->IsPatrolling() >
             reinterpret_cast<PatrolActorPackageData*>(apEntryB)->IsPatrolling())
        return 1;
    return 0;
}

class TESObjectREFR;
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
struct TESConditionItemHelper
{
    bool ContainsTrait(TESObjectREFR* apSubject, TESObjectREFR* apTarget, bool& abIgnore);
};
struct ConditionList_t
{
    bool FUN_008256d0() const;
    TESConditionItem* const* FUN_006815c0() const;
    const ConditionList_t* FUN_00726070() const;
};
struct Conditions_t
{
    const ConditionList_t* FUN_006815c0();
};
struct FUN_005eb5e0_t
{
    bool CheckPlayerConditions();
};
// If the flag at offset 0x3b is set, walks the condition list and evaluates each item of type 0x46 against the player, returning the last result.
// @fnv 0x005eb5e0
bool FUN_005eb5e0_t::CheckPlayerConditions()
{
    bool bresult;
    const ConditionList_t* pCurrentElementNext;
    bresult = *(reinterpret_cast<bool*>(this) + 0x3b);
    if (bresult)
    {
        pCurrentElementNext = reinterpret_cast<Conditions_t*>(reinterpret_cast<char*>(this) + 0x40)->FUN_006815c0();
        while (bresult && pCurrentElementNext && !pCurrentElementNext->FUN_008256d0())
        {
            TESConditionItem* pConditionItem = *pCurrentElementNext->FUN_006815c0();
            if (pConditionItem && pConditionItem->FUN_005eb680() == 0x46)
            {
                bool bignore;
                bresult = reinterpret_cast<TESConditionItemHelper*>(pConditionItem)
                              ->ContainsTrait(reinterpret_cast<TESObjectREFR*>(g_thePlayer), 0, bignore);
            }
            pCurrentElementNext = pCurrentElementNext->FUN_00726070();
        }
    }
    return bresult;
}

struct FUN_00470440
{
    FUN_00470440(BGSPerkEntry* const& apItem);
    void FUN_005ae3d0(BGSPerkEntry* const& apItem);
    void FUN_007a7eb0(BGSPerkEntry* apNewItem, int(__cdecl* apCompareFn)(BGSPerkEntry*, BGSPerkEntry*));
    BGSPerkEntry* m_item;
    FUN_00470440* m_pkNext;
};
// Inserts apNewItem into the linked list in sorted order using apCompareFn, filling an empty node or allocating a new node as needed.
// @fnv 0x007a7eb0
void FUN_00470440::FUN_007a7eb0(BGSPerkEntry* apNewItem, int(__cdecl* apCompareFn)(BGSPerkEntry*, BGSPerkEntry*))
{
    FUN_00470440* pkPrev;
    bool bdone;
    FUN_00470440* pkCur;
    if (!apNewItem)
        return;
    pkCur = this;
    pkPrev = 0;
    bdone = false;
    while (pkCur && !bdone)
    {
        if (!pkCur->m_item)
        {
            pkCur->m_item = apNewItem;
            bdone = true;
        }
        else if (apCompareFn(apNewItem, pkCur->m_item) <= 0)
        {
            if (!pkPrev)
            {
                FUN_005ae3d0(apNewItem);
            }
            else
            {
                FUN_00470440* pkNew = new FUN_00470440(apNewItem);
                pkPrev->m_pkNext = pkNew;
                pkNew->m_pkNext = pkCur;
            }
            bdone = true;
        }
        else if (!pkCur->m_pkNext)
        {
            FUN_00470440* pkNew = new FUN_00470440(apNewItem);
            pkCur->m_pkNext = pkNew;
            bdone = true;
        }
        pkPrev = pkCur;
        pkCur = pkCur->m_pkNext;
    }
}

void _Deallocate(void*);
struct Stub
{
    void FUN_005e9590();
    void* FUN_005e9560(unsigned int flags);
};
// @fnv 0x005e9560
void* Stub::FUN_005e9560(unsigned int flags)
{
    FUN_005e9590();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_005e9dd0 {
void _FUN_00485910(unsigned int, unsigned int);
struct FUN_005e9a70_t
{
    char _pad[8];
    void StartPerkEntry(int);
    void FinishPerkEntry();
};
struct S5e9dd0 : FUN_005e9a70_t
{
    TESForm* m_pSpell;
    void FUN_005e9dd0();
};
// @fnv 0x005e9dd0
void S5e9dd0::FUN_005e9dd0()
{
    unsigned int iabilityID;
    StartPerkEntry(1);
    if (m_pSpell)
    {
        iabilityID = m_pSpell->GetFormID();
        _FUN_00485910(0x41544144, iabilityID);
    }
    FinishPerkEntry();
}
}  // namespace fnv_005e9dd0

struct FUN_005ea000_holder
{
    void FUN_005ea000();
};
void _Deallocate(void*);
struct FUN_005e9fd0_host : FUN_005ea000_holder
{
    void* FUN_005e9fd0(unsigned int);
};
// @fnv 0x005e9fd0
void* FUN_005e9fd0_host::FUN_005e9fd0(unsigned int flags)
{
    FUN_005ea000();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_005ea000 {
struct FUN_005ea230_t
{
    void ClearEntryPointData();
};
struct FUN_005e9590
{
    virtual ~FUN_005e9590();
};
extern void* kVtbl_BGSEntryPointPerkEntry;
extern int _data_011c16bc;
struct FUN_005ea000 : FUN_005e9590
{
    virtual ~FUN_005ea000();
};
// Destructor that forwards to ClearEntryPointData to tear down the object.
// @fnv 0x005ea000
FUN_005ea000::~FUN_005ea000()
{
    ((FUN_005ea230_t*)this)->ClearEntryPointData();
}
}  // namespace fnv_005ea000

struct FUN_005eaa80_class;
struct ActorDummy_005eaa80
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void d196();
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void d225();
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void d263();
    virtual void d264();
    virtual void d265();
    virtual void d266();
    virtual void d267();
    virtual void d268();
    virtual void d269();
    virtual void d270();
    virtual void d271();
    virtual void d272();
    virtual void d273();
    virtual void d274();
    virtual void d275();
    virtual void d276();
    virtual void d277();
    virtual void d278();
    virtual void d279();
    virtual void d280();
    virtual void d281();
    virtual void d282();
    virtual void d283();
    virtual void d284();
    virtual void d285();
    virtual void d286();
    virtual void d287();
    virtual void d288();
    virtual void d289();
    virtual void d290();
    virtual void d291();
    virtual void d292();
    virtual void d293();
    virtual void d294();
    virtual void d295();
    virtual void d296();
    virtual void d297();
    virtual void Foo(FUN_005eaa80_class*, bool);
};
struct FUN_005eaa80_class
{
    void CallActorFoo(ActorDummy_005eaa80* apActor, bool bAlt);
};
// Calls Foo on apActor, passing this and bAlt.
// @fnv 0x005eaa80
void FUN_005eaa80_class::CallActorFoo(ActorDummy_005eaa80* apActor, bool bAlt)
{
    apActor->Foo(this, bAlt);
}

struct S_5eab80
{
    void FUN_005eabb0();
    void* FUN_005eab80(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_005eabb0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005eab80
void* S_5eab80::FUN_005eab80(unsigned int flags)
{
    FUN_005eabb0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESQuest_Callable
{
    bool IsStageComplete(unsigned char);
};
struct Holder005e9ba0
{
    char pad[8];
    TESQuest* quest;
    unsigned char stage;
    void ApplyPerkEntry(void* apActor, bool bAlt);
};
// @fnv 0x005e9ba0
void Holder005e9ba0::ApplyPerkEntry(void* apActor, bool bAlt)
{
    if (quest)
        ((TESQuest_Callable*)quest)->IsStageComplete(stage);
}

namespace fnv_005e9ee0 {
template <int N> struct VT : VT<N - 1>
{
    virtual void a(int (*)[N]);
    virtual void b(int (*)[N], int);
    virtual void c(int (*)[N], int, int);
    virtual void d(int (*)[N], int, int, int);
    virtual void e(int (*)[N], int, int, int, int);
    virtual void f(int (*)[N], int, int, int, int, int);
    virtual void g(int (*)[N], int, int, int, int, int, int);
    virtual void h(int (*)[N], int, int, int, int, int, int, int);
};
template <> struct VT<0>
{
};
struct Actor : VT<31>
{
    virtual void Target(void*);
    void ConfigureActorState(bool, bool);
};
struct ThisStandIn
{
    char _pad[8];
    void* m_pSpell;
    void ApplyPerkEntry(Actor*, bool);
};
// @fnv 0x005e9ee0
void ThisStandIn::ApplyPerkEntry(Actor* apActor, bool bAlt)
{
    if (m_pSpell != 0)
    {
        apActor->Target(m_pSpell);
        apActor->ConfigureActorState(false, false);
    }
}
}  // namespace fnv_005e9ee0

namespace fnv_005e9f20 {
struct Actor
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
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void Func3E4(void* p);
    void ConfigureActorState(bool, bool);
};
struct HolderEntry
{
    char _pad[8];
    void* m_pSpell;
    void RemovePerkEntry(Actor* apActor, bool bAlt);
};
// @fnv 0x005e9f20
void HolderEntry::RemovePerkEntry(Actor* apActor, bool bAlt)
{
    if (m_pSpell != 0)
    {
        apActor->Func3E4(m_pSpell);
        apActor->ConfigureActorState(false, false);
    }
}
}  // namespace fnv_005e9f20

struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct TESConditionSave
{
    void ProcessItems();
};
struct FUN_00485680
{
    void M();
};
struct _ref_006815c0
{
    virtual void vfn_28();
};
struct FUN_00485990_shell
{
    void AppendChunk(unsigned int, void*, int);
};
struct FUN_005eb0e0_shell
{
    void SaveForm();
};
bool FUN_00401500();
struct FUN_005eb0e0_TESForm
{
    virtual void vfn_28();
    void ClearData();
};
void AppendChunk(unsigned int, void*, int);
// Calls M on several subobjects, clears and serializes the data at offset 0x38, then iterates the perk-entry list calling vfn_28 on each entry.
// @fnv 0x005eb0e0
void FUN_005eb0e0_shell::SaveForm()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    ((FUN_00482cb0_shell*)((char*)this + 0x24))->FUN_00482cb0();
    ((FUN_0048e370_obj*)((char*)this + 0x2c))->FUN_0048e370(0x4e4f4349);
    ((TESConditionSave*)((char*)this + 0x40))->ProcessItems();
    if (FUN_00401500())
        ((FUN_005eb0e0_TESForm*)((char*)this + 0x38))->ClearData();
    AppendChunk(0x41544144, (char*)this + 0x38, 5);
    if (FUN_00401500())
        ((FUN_005eb0e0_TESForm*)((char*)this + 0x38))->ClearData();
    BSSimpleList<BGSPerkEntry*>* pCurrentElementNext = (BSSimpleList<BGSPerkEntry*>*)((char*)this + 0x48);
    while (pCurrentElementNext)
    {
        BGSPerkEntry* pPerkEntry = pCurrentElementNext->GetItem();
        if (pPerkEntry)
            ((TESForm*)pPerkEntry)->vfn_28();
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    ((FUN_00485680*)this)->M();
}

namespace fnv_005e9940 {
void* __cdecl operator new(unsigned int);
extern unsigned int _data_011c16bc;

struct FUN_005e9800
{
    virtual void FUN_005e9800_v0()
    {}
    virtual void FUN_005e9800_v1()
    {}
    virtual void FUN_005e9800_v2()
    {}
    virtual void FUN_005e9800_v3()
    {}
    virtual void FUN_005e9800_v4()
    {}
    virtual void FUN_005e9800_v5()
    {}
    virtual void FUN_005e9800_v6()
    {}
    virtual void FUN_005e9800_v7()
    {}
    virtual void FUN_005e9800_v8(FUN_005e9800*)
    {}

    unsigned int reserved;
    unsigned int data0;
    unsigned char data1;

    FUN_005e9800();
    BGSPerkEntry* Clone();
};

// Allocates a new FUN_005e9800, copies data0 and data1 into it, calls its virtual v8 with this, and returns it as a BGSPerkEntry pointer.
// @fnv 0x005e9940
BGSPerkEntry* FUN_005e9800::Clone()
{
    FUN_005e9800* pduplicate = new FUN_005e9800;
    pduplicate->data0 = data0;
    pduplicate->data1 = data1;
    pduplicate->FUN_005e9800_v8(this);
    return reinterpret_cast<BGSPerkEntry*>(pduplicate);
}
}  // namespace fnv_005e9940

namespace fnv_005ea3a0 {
void* __cdecl operator new(unsigned int);

extern unsigned int _data_011c16bc;

struct CondS
{
    CondS();
};

struct FUN_005e9f60 : BGSPerkEntry
{
    unsigned char Data[4];
    void* m_pFunctionData;
    PerkEntryConditionSet* m_pConditions;

    FUN_005e9f60();
};

struct FUN_00680a70_shell
{
    void CopyConditions(PerkEntryConditionSet*, PerkEntryConditionSet*);
};

struct FUN_005ea3a0_functiondata
{
    virtual void f0();
    virtual void f1();
    virtual void* Duplicate();
};

struct FUN_005ea3a0_copy
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void* CopyFrom(void*);
};

struct FUN_005ea3a0_shell : BGSPerkEntry
{
    unsigned char Data[4];
    void* m_pFunctionData;
    PerkEntryConditionSet* m_pConditions;

    BGSPerkEntry* FUN_005ea3a0();
};

// @fnv 0x005ea3a0
BGSPerkEntry* FUN_005ea3a0_shell::FUN_005ea3a0()
{
    BGSPerkEntry* pduplicate = (BGSPerkEntry*)(void*)new FUN_005e9f60();

    ((FUN_005e9f60*)pduplicate)->Data[0] = Data[0];
    ((FUN_005e9f60*)pduplicate)->Data[1] = Data[1];
    ((FUN_005e9f60*)pduplicate)->Data[2] = Data[2];

    if (m_pFunctionData)
        ((FUN_005e9f60*)pduplicate)->m_pFunctionData =
            reinterpret_cast<FUN_005ea3a0_functiondata*>(m_pFunctionData)->Duplicate();

    if (Data[2])
    {
        ((FUN_005e9f60*)pduplicate)->m_pConditions = new PerkEntryConditionSet[Data[2]];

        for (unsigned int i = 0; i < Data[2]; i++)
        {
            reinterpret_cast<FUN_00680a70_shell*>(((FUN_005e9f60*)pduplicate)->m_pConditions + i)
                ->CopyConditions(m_pConditions + i, 0);
        }
    }

    reinterpret_cast<FUN_005ea3a0_copy*>(pduplicate)->CopyFrom(this);
    pduplicate;

    return pduplicate;
}
}  // namespace fnv_005ea3a0

unsigned int _data_011c16bc;

struct ListX
{
    ~ListX();
};

struct Base5a
{
    virtual ~Base5a();
    unsigned char m_data[0x14];
};

struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned char m_data[8];
};

struct FUN_005eabb0_24
{
    virtual void m_virtualFunction();
    unsigned char m_data[4];
};

struct FUN_005eabb0 : Base5a, FUN_00591300, FUN_005eabb0_24, TESIcon
{
    unsigned char m_ucUnknownByte[8];
    PerkEntryConditionSet m_condition;
    ListX m_kNode;

    void ClearConditions();

    ~FUN_005eabb0();
};

// @fnv 0x005eabb0
FUN_005eabb0::~FUN_005eabb0()
{
    ClearConditions();
}

struct FUN_005a4910_Class
{
    unsigned int GetFieldD68(void) const;
};

extern FUN_005a4910_Class* _g_thePlayer;
void* __fastcall FUN_005eb7e0(void*);

struct FUN_005eb6a0_VTable
{
    virtual void FUN_005eb6a0_00(void) = 0;
    virtual void FUN_005eb6a0_04(void) = 0;
    virtual void FUN_005eb6a0_08(void) = 0;
    virtual void FUN_005eb6a0_0c(void) = 0;
    virtual int FUN_005eb6a0_10(void) = 0;
    virtual void FUN_005eb6a0_14(void) = 0;
    virtual void FUN_005eb6a0_18(void) = 0;
    virtual void FUN_005eb6a0_1c(void) = 0;
    virtual void FUN_005eb6a0_20(void) = 0;
    virtual void FUN_005eb6a0_24(void) = 0;
    virtual void FUN_005eb6a0_28(void) = 0;
    virtual void FUN_005eb6a0_2c(void) = 0;
    virtual void FUN_005eb6a0_30(void*, bool) = 0;
    virtual void FUN_005eb6a0_34(void*, bool) = 0;
};

struct FUN_005eb6a0_Class
{
    char FUN_005eb6a0_pad[0x48];
    BSSimpleList<PatrolActorPackageData> FUN_005eb6a0_list;

    void FUN_005eb6a0(void*, unsigned char, unsigned char, bool);
};

// @fnv 0x005eb6a0
void FUN_005eb6a0_Class::FUN_005eb6a0(void* data, unsigned char value1, unsigned char value2, bool flag)
{
    BSSimpleList<PatrolActorPackageData>* list = &FUN_005eb6a0_list;

    while (list)
    {
        PatrolActorPackageData* item = *reinterpret_cast<PatrolActorPackageData**>(&list->GetItem());

        if (item)
        {
            if (!flag)
            {
                if (item->IsPatrolling() + 1 == value1)
                {
                    reinterpret_cast<FUN_005eb6a0_VTable*>(item)->FUN_005eb6a0_34(data, flag);
                }
                else if (item->IsPatrolling() + 1 == value2)
                {
                    reinterpret_cast<FUN_005eb6a0_VTable*>(item)->FUN_005eb6a0_30(data, flag);
                }
            }
            else
            {
                int count = static_cast<int>(_g_thePlayer->GetFieldD68());

                if (count > 0)
                {
                    BSSimpleList<PatrolActorPackageData>* m_kList =
                        reinterpret_cast<BSSimpleList<PatrolActorPackageData>*>(FUN_005eb7e0(_g_thePlayer));

                    while (m_kList)
                    {
                        PatrolActorPackageData* playerItem =
                            *reinterpret_cast<PatrolActorPackageData**>(&m_kList->GetItem());

                        if (reinterpret_cast<FUN_005eb6a0_VTable*>(item)->FUN_005eb6a0_10() == 2)
                        {
                            reinterpret_cast<FUN_005eb6a0_VTable*>(item)->FUN_005eb6a0_30(_g_thePlayer, flag);
                        }
                        else
                        {
                            reinterpret_cast<FUN_005eb6a0_VTable*>(item)->FUN_005eb6a0_30(playerItem, flag);
                        }

                        m_kList = m_kList->GetNext();
                    }
                }
            }
        }

        list = list->GetNext();
    }
}

namespace fnv_005eb800 {
struct FUN_005a4910_Class
{
    unsigned int GetFieldD68() const;
};

extern FUN_005a4910_Class* _g_thePlayer;
void* __fastcall FUN_005eb7e0(void*);

struct FUN_005eb800_perk_vtable
{
    virtual void* FUN_00() = 0;
    virtual void* FUN_04() = 0;
    virtual void* FUN_08() = 0;
    virtual void* FUN_0C() = 0;
    virtual int FUN_10() = 0;
    virtual void* FUN_14() = 0;
    virtual void* FUN_18() = 0;
    virtual void* FUN_1C() = 0;
    virtual void* FUN_20() = 0;
    virtual void* FUN_24() = 0;
    virtual void* FUN_28() = 0;
    virtual void* FUN_2C() = 0;
    virtual void* FUN_30() = 0;
    virtual void FUN_34(void*, bool) = 0;
};

struct FUN_005eb800_shell
{
    void FUN_005eb800(BGSPerk* perk, bool flag);
};

// @fnv 0x005eb800
void FUN_005eb800_shell::FUN_005eb800(BGSPerk* perk, bool flag)
{
    BSSimpleList<BGSPerk*>* perkList = reinterpret_cast<BSSimpleList<BGSPerk*>*>(reinterpret_cast<char*>(this) + 0x48);

    while (perkList)
    {
        BGSPerk* currentPerk = perkList->GetItem();

        if (currentPerk)
        {
            if (!flag)
            {
                reinterpret_cast<FUN_005eb800_perk_vtable*>(currentPerk)->FUN_34(perk, flag);
            }
            else
            {
                int playerLevel = static_cast<int>(_g_thePlayer->GetFieldD68());

                if (playerLevel > 0)
                {
                    BSSimpleList<BGSPerk*>* playerPerkList =
                        reinterpret_cast<BSSimpleList<BGSPerk*>*>(FUN_005eb7e0(_g_thePlayer));

                    while (playerPerkList)
                    {
                        BGSPerk* playerPerk = playerPerkList->GetItem();

                        if (reinterpret_cast<FUN_005eb800_perk_vtable*>(currentPerk)->FUN_10() == 2)
                        {
                            reinterpret_cast<FUN_005eb800_perk_vtable*>(currentPerk)->FUN_34(_g_thePlayer, flag);
                        }
                        else
                        {
                            reinterpret_cast<FUN_005eb800_perk_vtable*>(currentPerk)->FUN_34(playerPerk, flag);
                        }

                        playerPerkList = playerPerkList->GetNext();
                    }
                }
            }
        }

        perkList = perkList->GetNext();
    }
}
}  // namespace fnv_005eb800

struct NiFixedStr
{
    unsigned short data[2];
    void* value;
};

struct SeqObj
{
    NiFixedStr& GetName();
};

struct Script
{
    static bool __cdecl IsSexConditionFunction(TESObjectREFR* object, void* parameter, void* argument, double& result);
};

struct FUN_00680f70_helper
{
    TESConditionItem* __thiscall GetItemByIndex(int index);
};

struct FUN_005eba00_shell
{
    bool FUN_005eba00(TESObjectREFR* apActionRef);
};

// @fnv 0x005eba00
bool FUN_005eba00_shell::FUN_005eba00(TESObjectREFR* apActionRef)
{
    TESConditionItem* pcurrCondition;
    int iconditionIndex;
    bool bresult;

    bresult = true;
    iconditionIndex = 0;

    pcurrCondition = reinterpret_cast<FUN_00680f70_helper*>(reinterpret_cast<unsigned char*>(this) + 0x40)
                         ->GetItemByIndex(iconditionIndex++);

    while (pcurrCondition != 0)
    {
        if (reinterpret_cast<SeqObj*>(pcurrCondition)->GetName().data[0] == 0x46)
        {
            double freturnVal;

            freturnVal = 0.0;
            Script::IsSexConditionFunction(apActionRef, reinterpret_cast<SeqObj*>(pcurrCondition)->GetName().value, 0,
                                           freturnVal);
            bresult = (freturnVal == 1.0);
        }

        pcurrCondition = reinterpret_cast<FUN_00680f70_helper*>(reinterpret_cast<unsigned char*>(this) + 0x40)
                             ->GetItemByIndex(iconditionIndex++);
    }

    return bresult;
}

struct FUN_005e9590
{
    virtual ~FUN_005e9590();
    void FUN_00483710();
};

// @fnv 0x005e9590
FUN_005e9590::~FUN_005e9590()
{
    FUN_00483710();
}

extern const char DAT_01183028[];
extern const char DAT_011861dc[];

void* __cdecl FUN_00ec43fb(int, unsigned int, const char*, const char*, unsigned int);
void __cdecl FUN_00401460(void*, void*, unsigned int);

struct FUN_005eb1b0_entry
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void* v1c();
};

struct FUN_005eb1b0_cond
{
    unsigned char unk00[8];
    void CopyConditions(void*, int);
};

struct FUN_005eb1b0_node
{
    void*& FUN_006815c0();
    FUN_005eb1b0_node* FUN_00726070();
    void FUN_00905820(void* const& item);
    void* m_item;
    FUN_005eb1b0_node* m_pkNext;
};

struct FUN_005eb1b0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    unsigned char unk04[0x34];
    unsigned char unk38[8];
    FUN_005eb1b0_cond cond40;
    FUN_005eb1b0_node list48;
    void FUN_004851b0(int);
    void FUN_005eb1b0(int a1);
};

// @fnv 0x005eb1b0
void FUN_005eb1b0_cls::FUN_005eb1b0(int a1)
{
    FUN_005eb1b0_cls* _copy;
    FUN_005eb1b0_node* node2;
    FUN_005eb1b0_entry* entry2;
    void* result;

    v18();
    _copy = (FUN_005eb1b0_cls*)FUN_00ec43fb(a1, 0, DAT_01183028, DAT_011861dc, 0);
    if (_copy == 0)
    {
        return;
    }
    FUN_00401460(unk38, _copy->unk38, 5);
    FUN_004851b0(a1);
    cond40.CopyConditions(&_copy->cond40, 0);
    node2 = &_copy->list48;
    while (node2 != 0)
    {
        entry2 = (FUN_005eb1b0_entry*)node2->FUN_006815c0();
        if (entry2 != 0)
        {
            result = entry2->v1c();
            list48.FUN_00905820(result);
        }
        node2 = node2->FUN_00726070();
    }
}

class PerkEntry_t
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
    virtual bool IsDifferent(PerkEntry_t* apOther);
};

template <class T> class PerkList_t
{
  public:
    T m_item;
    PerkList_t<T>* m_pkNext;
    int GetSize();
    T& GetItem();
    PerkList_t<T>* GetNext();
};

class PerkConditions_t
{
  public:
    void* pFirst;
    void* pNext;
    bool IsDifferent(PerkConditions_t* apOther);
};

class PerkCompare_t : public BGSPerk
{
  public:
    bool CompareFullName(TESForm* apForm);
    bool FUN_005eb280(TESForm* apForm);
};

// Compares this perk's playable, id, level, hidden, full name, conditions and entry list against another BGSPerk, returning true if any differ.
// @fnv 0x005eb280
bool PerkCompare_t::FUN_005eb280(TESForm* apForm)
{
    BGSPerk* pOtherPerk = dynamic_cast<BGSPerk*>(apForm);
    if (!pOtherPerk)
        return true;
    if (Data.bPlayable != pOtherPerk->Data.bPlayable || Data.m_bTrait != pOtherPerk->Data.m_bTrait ||
        Data.cLevel != pOtherPerk->Data.cLevel || Data.m_ucRankCount != pOtherPerk->Data.m_ucRankCount ||
        Data.bHidden != pOtherPerk->Data.bHidden)
        return true;
    if (CompareFullName(pOtherPerk))
        return true;
    if (reinterpret_cast<PerkConditions_t*>(&m_kConditions)
            ->IsDifferent(reinterpret_cast<PerkConditions_t*>(&pOtherPerk->m_kConditions)))
        return true;
    if (reinterpret_cast<PerkList_t<PerkEntry_t*>*>(&m_kEntryList)->GetSize() !=
        reinterpret_cast<PerkList_t<PerkEntry_t*>*>(&pOtherPerk->m_kEntryList)->GetSize())
        return true;
    PerkList_t<PerkEntry_t*>* pEntryIter = reinterpret_cast<PerkList_t<PerkEntry_t*>*>(&m_kEntryList);
    PerkList_t<PerkEntry_t*>* pOtherEntryIter = reinterpret_cast<PerkList_t<PerkEntry_t*>*>(&pOtherPerk->m_kEntryList);
    while (pEntryIter)
    {
        PerkEntry_t* pEntry = pEntryIter->GetItem();
        PerkEntry_t* pOtherEntry = pOtherEntryIter->GetItem();
        if ((pEntry && !pOtherEntry) || (!pEntry && pOtherEntry))
            return true;
        if (pEntry && pOtherEntry && pEntry->IsDifferent(pOtherEntry))
            return true;
        pEntryIter = pEntryIter->GetNext();
        pOtherEntryIter = pOtherEntryIter->GetNext();
    }
    return false;
}

// Find the first listed entry whose level is one below the requested level.

class EB900Entry
{
  public:
    unsigned char GetLevel();
};

class EB900Node
{
  public:
    EB900Entry** Item();
    EB900Node* Next();

    EB900Entry* m_item;
    EB900Node* m_pkNext;
};

class EB900Owner
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
    int unk3C;
    int unk40;
    int unk44;
    EB900Node m_kEntries;

    EB900Entry* FindEntryByLevel(unsigned char ucLevel);
};

// Walks the m_kEntries list and returns the first entry whose GetLevel()+1 equals ucLevel, or null if none matches.
// @fnv 0x005eb900
EB900Entry* EB900Owner::FindEntryByLevel(unsigned char ucLevel)
{
    EB900Entry* pkFound = 0;
    for (EB900Node* pkIter = &m_kEntries; !pkFound && pkIter && *pkIter->Item(); pkIter = pkIter->Next())
    {
        if ((*pkIter->Item())->GetLevel() + 1 == ucLevel)
            pkFound = *pkIter->Item();
    }
    return pkFound;
}

struct Perk5e99Stub : BGSQuestPerkEntry
{
    bool IsDifferentFrom(BGSPerkEntry* other);
};
// Returns true if other is not a BGSQuestPerkEntry, differs by base comparison, or has a different quest or stage; otherwise false.
// @fnv 0x005e99f0
bool Perk5e99Stub::IsDifferentFrom(BGSPerkEntry* other)
{
    BGSQuestPerkEntry* other_quest = dynamic_cast<BGSQuestPerkEntry*>(other);
    if (!other_quest)
    {
        return true;
    }
    if (((FUN_005e95e0_shell*)this)->FUN_005e95e0_shell::Compare(other))
    {
        return true;
    }
    if (Data.pQuest != other_quest->Data.pQuest)
    {
        return true;
    }
    if (Data.stage != other_quest->Data.stage)
    {
        return true;
    }
    return false;
}

struct PerkCopy_vt
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void copyFrom(BGSPerkEntry* apCopy);
};

struct FUN_005e9cc0_shell : BGSAbilityPerkEntry
{
    FUN_005e9bd0* FUN_005e9cc0();
};

// @fnv 0x005e9cc0
FUN_005e9bd0* FUN_005e9cc0_shell::FUN_005e9cc0()
{
    FUN_005e9bd0* pNew = new FUN_005e9bd0();
    pNew->m_pSpell = m_pSpell;
    ((PerkCopy_vt*)pNew)->copyFrom(this);
    return pNew;
}

struct ConditionCompare_t
{
    void* pFirst;
    void* pNext;
    bool IsDifferent(ConditionCompare_t* apOther);
};

struct EntryFunctionData_t
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool IsDifferent(EntryFunctionData_t* apOther);
};

struct FUN_005ea560_shell : BGSEntryPointPerkEntry
{
    bool FUN_005ea560(BGSPerkEntry* apCompare);
};

// Compares this entry point perk entry against another BGSEntryPointPerkEntry, returning true if any data, function or condition differs.
// @fnv 0x005ea560
bool FUN_005ea560_shell::FUN_005ea560(BGSPerkEntry* apCompare)
{
    BGSEntryPointPerkEntry* pOtherEntry = dynamic_cast<BGSEntryPointPerkEntry*>(apCompare);
    if (!pOtherEntry)
        return true;
    if (((FUN_005e95e0_shell*)this)->FUN_005e95e0_shell::Compare(apCompare))
        return true;
    if (Data.m_ucEntryPoint != pOtherEntry->Data.m_ucEntryPoint)
        return true;
    if (Data.m_ucFunction != pOtherEntry->Data.m_ucFunction)
        return true;
    if (Data.m_ucConditionCount != pOtherEntry->Data.m_ucConditionCount)
        return true;
    if ((m_pFunctionData && !pOtherEntry->m_pFunctionData) || (!m_pFunctionData && pOtherEntry->m_pFunctionData))
        return true;
    if (m_pFunctionData && pOtherEntry->m_pFunctionData &&
        ((EntryFunctionData_t*)m_pFunctionData)->IsDifferent((EntryFunctionData_t*)pOtherEntry->m_pFunctionData))
        return true;
    for (unsigned int i = 0; i < Data.m_ucConditionCount; i++)
    {
        if (((ConditionCompare_t*)m_pConditions)[i].IsDifferent(&((ConditionCompare_t*)pOtherEntry->m_pConditions)[i]))
            return true;
    }
    return false;
}

void __fastcall FUN_00483710(void* apData);
void FUN_004858f0(unsigned int, unsigned char);

struct FUN_005ea6b0_shell : public BGSEntryPointPerkEntry
{
    void SavePerkEntry();
};

// @fnv 0x005ea6b0
void FUN_005ea6b0_shell::SavePerkEntry()
{
    reinterpret_cast<FUN_005e9a70_t*>(this)->StartPerkEntry(2);
    if (FUN_00401500())
    {
        FUN_00483710(&Data);
    }
    AppendChunk(0x41544144, &Data, 3u);
    if (FUN_00401500())
    {
        FUN_00483710(&Data);
    }
    for (unsigned char i = 0; i < Data.m_ucConditionCount; ++i)
    {
        if (reinterpret_cast<FUN_00680f70_helper*>(&m_pConditions[i])->GetItemByIndex(0))
        {
            FUN_004858f0(0x434b5250, i);
            reinterpret_cast<TESConditionSave*>(&m_pConditions[i])->ProcessItems();
        }
    }
    if (m_pFunctionData)
    {
        m_pFunctionData->Unk_04();
    }
    reinterpret_cast<FUN_005e9a70_t*>(this)->FinishPerkEntry();
}

struct VirtualListItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual ~VirtualListItem();
};
struct ListCleanup
{
    void FUN_00470470();
};
struct ConditionCleanup
{
    void FUN_00680fe0();
};
// Deletes each item returned by the condition list cursor, then calls cleanup routines on the list and m_condition.
// @fnv 0x005eaca0
void FUN_005eabb0::ClearConditions()
{
    const ConditionList_t* cursor = reinterpret_cast<const ConditionList_t*>(&m_kNode);
    while (cursor != 0)
    {
        delete reinterpret_cast<VirtualListItem*>(*cursor->FUN_006815c0());
        cursor = cursor->FUN_00726070();
    }
    reinterpret_cast<ListCleanup*>(&m_kNode)->FUN_00470470();
    reinterpret_cast<ConditionCleanup*>(&m_condition)->FUN_00680fe0();
}

extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl strcat_s(char*, unsigned int, const char*);

struct LocalizedText
{
    const char* FUN_00403df0();
};
extern LocalizedText _data_011d4678;
extern LocalizedText _data_011d3b2c;
extern LocalizedText _data_011d324c;
extern LocalizedText _data_011d40e4;
extern const char _data_01047040[];
extern const char _data_01047038[];
extern const char _data_01047034[];
extern const char _data_01047028[];
extern const char _data_0104701c[];
extern const char _data_01047014[];
extern const char _data_0104700c[];
extern const char _data_01047008[];
extern const char _data_01046ffc[];
extern const char _data_01020770[];
extern const char _data_01012630[];
extern const char _data_01012648[];
extern const char _data_01019f08[];

struct ConditionParameters
{
    int unk00;
    int value;
    unsigned int upperBound;
};
struct FormNameData
{
    const char* FUN_00408da0();
};
struct PerkConditionItem : TESConditionItem
{
    ConditionParameters* FUN_00413f40();
    int GetComparisonCondition();
    unsigned char IsFlagSet();
    float FUN_00681490();
};
struct DescriptionGetter
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual const char* vfn10(int, unsigned int);
    unsigned int descriptionData;
};
const char* __cdecl FUN_0066eb00(int);

struct PerkPrinter : TESForm, TESFullName, DescriptionGetter, TESIcon
{
    PerkData Data;
    PerkEntryConditionSet m_kConditions;
    void BuildDescription(char* output, unsigned int outputSize);
};
// Builds the perk description string from level, condition items and description data into output, bounded by outputSize.
// @fnv 0x005ebac0
void PerkPrinter::BuildDescription(char* output, unsigned int outputSize)
{
    char message[128];
    {
        bool first = false;
        PerkConditionItem* kItem = reinterpret_cast<PerkConditionItem*>(
            reinterpret_cast<FUN_00680f70_helper*>(&m_kConditions)->GetItemByIndex(0));
        if (Data.cLevel > 1)
        {
            sprintf_s(output, outputSize, _data_01047040, _data_011d4678.FUN_00403df0(), _data_011d3b2c.FUN_00403df0(),
                      Data.cLevel);
        }
        else
        {
            sprintf_s(output, outputSize, _data_01047038, _data_011d4678.FUN_00403df0());
            first = true;
        }
        bool foundVal = false;
        int index = 0;
        for (; kItem != 0; index++)
        {
            if (kItem->FUN_005eb680() == 0x1ef)
            {
                ConditionParameters* node = kItem->FUN_00413f40();
                int form = node->value;
                const char* value = _data_01020770;
                int offset = 0;
                switch (kItem->GetComparisonCondition())
                {
                case 0:
                case 1:
                    break;
                case 2:
                    offset = -1;
                    break;
                case 3:
                    break;
                case 4:
                    value = _data_01047034;
                    break;
                case 5:
                    value = _data_01047034;
                    offset = 1;
                    break;
                }
                if (form != 0x17 && FUN_0066eb00(form))
                {
                    if (static_cast<int>(kItem->FUN_00681490()) + offset == 0)
                    {
                        kItem = reinterpret_cast<PerkConditionItem*>(
                            reinterpret_cast<FUN_00680f70_helper*>(&m_kConditions)->GetItemByIndex(++index));
                        continue;
                    }
                    foundVal = true;
                    if (index == 0 && !first)
                    {
                        strcat_s(output, outputSize, _data_01012630);
                    }
                    if (kItem->IsFlagSet() &&
                        reinterpret_cast<FUN_00680f70_helper*>(&m_kConditions)->GetItemByIndex(index + 1))
                    {
                        sprintf_s(message, 128, _data_01047028, FUN_0066eb00(form), value,
                                  (static_cast<int>(kItem->FUN_00681490()) + offset), _data_011d324c.FUN_00403df0());
                    }
                    else if (reinterpret_cast<FUN_00680f70_helper*>(&m_kConditions)->GetItemByIndex(index + 1))
                    {
                        sprintf_s(message, 128, _data_0104701c, FUN_0066eb00(form), value,
                                  (static_cast<int>(kItem->FUN_00681490()) + offset));
                    }
                    else
                    {
                        sprintf_s(message, 128, _data_01047014, FUN_0066eb00(form), value,
                                  (static_cast<int>(kItem->FUN_00681490()) + offset));
                    }
                    strcat_s(output, outputSize, message);
                }
            }
            else if (kItem->FUN_005eb680() == 0x1c1)
            {
                foundVal = true;
                if (index == 0 && !first)
                {
                    strcat_s(output, outputSize, _data_01012630);
                }
                ConditionParameters* dataTmp = kItem->FUN_00413f40();
                int formX = dataTmp->value;
                unsigned int countB = dataTmp->upperBound;
                if (formX && countB > 0)
                {
                    sprintf_s(message, 128, _data_0104700c,
                              reinterpret_cast<FormNameData*>((char*)formX + 0x18)->FUN_00408da0(), countB);
                }
                else if (formX)
                {
                    sprintf_s(message, 128, _data_01019f08,
                              reinterpret_cast<FormNameData*>((char*)formX + 0x18)->FUN_00408da0());
                }
                strcat_s(output, outputSize, message);
            }
            else
            {
                foundVal = true;
                if (index == 0 && !first)
                {
                    strcat_s(output, outputSize, _data_01012630);
                }
            }
            kItem = reinterpret_cast<PerkConditionItem*>(
                reinterpret_cast<FUN_00680f70_helper*>(&m_kConditions)->GetItemByIndex(++index));
        }
        if (!foundVal)
            strcat_s(output, outputSize, _data_01047008);
        strcat_s(output, outputSize, _data_01012648);
        sprintf_s(message, 128, _data_01046ffc, _data_011d40e4.FUN_00403df0(), Data.m_ucRankCount);
        strcat_s(output, outputSize, message);
        strcat_s(output, outputSize, vfn10(0, 0x43534544));
    }
}

struct BGSAbilityPerkEntryCompareShell : BGSAbilityPerkEntry
{
    bool FUN_005e9d60(BGSPerkEntry* apCompare);
};

// Returns true if apCompare is not a BGSAbilityPerkEntry, the base comparison returns true, or the m_pSpell fields differ.
// @fnv 0x005e9d60
bool BGSAbilityPerkEntryCompareShell::FUN_005e9d60(BGSPerkEntry* apCompare)
{
    BGSAbilityPerkEntry* pAbilityPerkEntry = dynamic_cast<BGSAbilityPerkEntry*>(apCompare);
    if (!pAbilityPerkEntry)
        return true;
    if (reinterpret_cast<FUN_005e95e0_shell*>(this)->FUN_005e95e0_shell::Compare(apCompare))
        return true;
    if (m_pSpell != pAbilityPerkEntry->m_pSpell)
        return true;
    return false;
}

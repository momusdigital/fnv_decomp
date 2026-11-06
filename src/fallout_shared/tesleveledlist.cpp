// fallout_shared/tesleveledlist.cpp: TESLeveledList, TESFile, NiRefObject, TmpEndian and more (46 functions)

#include "tesleveledlist_decls.h"

extern "C" double __cdecl floor(double value);
extern "C" int __cdecl _ftol2_sse();

// @fnv 0x00487740
void TESLeveledList::InitializeComponent()
{
    m_pChanceGlobal = 0;
    m_ucChanceNone = 0;
    m_pLevelGlobal = 0;
}

// @fnv 0x00487770
void TESLeveledList::ClearComponent()
{
    InitializeLeveledList();
}

// @fnv 0x00488f10
void TESLeveledList::Revert(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetOldChangeFlags(0x80000000))
        ClearScriptAddedLeveledObjects();
}

// @fnv 0x00487f70
void TESLeveledList::PopulateContainerWithLeveledItems(unsigned short level, unsigned short count,
                                                       TESContainer* container, int mode)
{
    if (level < 1)
        level = 1;
    if (container && count > 0)
    {
        unsigned int selectionLevel = level;
        if ((FUN_004877e0() && mode == 0) || mode > 0)
        {
            struct LevelScan
            {
                unsigned short maxLevel;
                BSSimpleList<BGSPerkEntry*>* node;
            } scan;
            scan.maxLevel = 0;
            scan.node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(
                reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
            while (scan.node && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(scan.node)->IsEmpty())
            {
                unsigned short entryLevel = scan.node->GetItem()->level;
                if (entryLevel > scan.maxLevel)
                    scan.maxLevel = entryLevel;
                scan.node = scan.node->GetNext();
            }
            if (scan.maxLevel < selectionLevel)
                selectionLevel = scan.maxLevel;
        }
        TESContainer selected;
        if (vfn_14())
        {
            for (int i = 0; i < count; ++i)
            {
                struct Selection
                {
                    TESForm* form;
                    unsigned short quantity;
                    ContainerItemExtra* extra;
                } result;
                result.form = 0;
                result.quantity = 0;
                result.extra = 0;
                SelectLeveledObject((unsigned short)selectionLevel, result.form, result.quantity, result.extra, false,
                                    mode);
                if (result.form && result.quantity)
                {
                    TESLeveledList* nested = GetFormAsLeveledList(result.form);
                    if (nested)
                        nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected, mode);
                    else if (result.form->Unk_39())
                    {
                        TESForm* object = result.form;
                        if (object)
                            selected.AddObject(object, result.quantity, result.extra);
                    }
                }
            }
        }
        else
        {
            struct Selection
            {
                TESForm* form;
                unsigned short quantity;
                ContainerItemExtra* extra;
            } result;
            {
                bool useAll;
                result.form = 0;
                result.quantity = 0;
                result.extra = 0;
                if (FUN_004878a0())
                {
                    int roll;
                    {
                        unsigned char chance;
                        useAll = false;
                        chance = vfn_10();
                        roll = DialogueRandom() % 100;
                        if (roll >= chance)
                        {
                            BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(
                                reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
                            while (node && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(node)->IsEmpty())
                            {
                                BGSPerkEntry* entry = node->GetItem();
                                node = node->GetNext();
                                result.form = entry->form;
                                result.quantity = entry->count;
                                result.extra = entry->extra;
                                if (result.form && result.quantity)
                                {
                                    TESLeveledList* nested = GetFormAsLeveledList(result.form);
                                    if (nested)
                                        nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected,
                                                                                  mode);
                                    else if (result.form->Unk_39())
                                    {
                                        TESForm* object = result.form;
                                        if (object)
                                            selected.AddObject(object, result.quantity, result.extra);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    SelectLeveledObject((unsigned short)selectionLevel, result.form, result.quantity, result.extra,
                                        false, mode);
                    if (result.form && result.quantity)
                    {
                        TESLeveledList* nested = GetFormAsLeveledList(result.form);
                        if (nested)
                            nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected, mode);
                        else if (result.form->Unk_39())
                        {
                            TESForm* object = result.form;
                            if (object)
                                selected.AddObject(object, result.quantity, result.extra);
                        }
                    }
                }
                selected.ScaleEntryCounts(count);
            }
        }
        container->MergeContainer(&selected);
    }
}

// Rolls chance and level range over perk entries, picks one entry, optionally recurses into a nested leveled list, and writes form, count and extra.
// @fnv 0x00487d00
void TESLeveledList::SelectLeveledObject(unsigned short level, TESForm*& form, unsigned short& count,
                                         ContainerItemExtra*& extra, bool recurse, int mode)
{
    struct LevelRange
    {
        int lastLevel;
        BSSimpleList<BGSPerkEntry*>* first;
        int minimumLevel;
        unsigned int choices;
    } range;
    bool foundRange;
    {
        form = 0;
        count = 0;
        extra = 0;
        unsigned char chance = vfn_10();
        if (chance > 0)
        {
            int roll = DialogueRandom() % 100;
            if (roll < chance)
                return;
        }
        range.minimumLevel = level;
        if ((FUN_004877e0() && mode == 0) || mode > 0)
        {
            int difference = vfn_18();
            if (difference)
                range.minimumLevel = level - difference;
            else
                range.minimumLevel = -1;
        }
        range.choices = 1;
        range.lastLevel = 0;
        range.first = 0;
        BSSimpleList<BGSPerkEntry*>* node =
            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
        foundRange = false;
        while (node)
        {
            BGSPerkEntry* entry = node->GetItem();
            if (entry)
            {
                int entryLevel = entry->level;
                if (entryLevel > level)
                    break;
                if (entryLevel > range.lastLevel && (range.lastLevel == 0 || !foundRange))
                {
                    if (entryLevel >= range.minimumLevel)
                        foundRange = true;
                    range.choices = 1;
                    range.first = node;
                    range.lastLevel = entryLevel;
                }
                else
                    ++range.choices;
            }
            node = node->GetNext();
        }
        if (range.first)
        {
            struct SelectedForm
            {
                unsigned short count;
                BGSPerkEntry* entry;
                ContainerItemExtra* extra;
                TESForm* form;
            } result;
            {
                unsigned int pick = DialogueRandom() % range.choices;
                node = range.first;
                while (pick)
                {
                    node = node->GetNext();
                    --pick;
                    if (!node)
                        return;
                }
                result.entry = node->GetItem();
                result.form = result.entry->form;
                result.count = result.entry->count;
                result.extra = result.entry->extra;
                {
                    TESLeveledList* nested = GetFormAsLeveledList(result.entry->form);
                    if (nested && recurse)
                    {
                        struct RecursiveForm
                        {
                            ContainerItemExtra* extra;
                            TESForm* form;
                            unsigned short count;
                        } recursive;
                        recursive.form = 0;
                        recursive.count = 0;
                        recursive.extra = 0;
                        nested->SelectLeveledObject(level, recursive.form, recursive.count, recursive.extra, recurse,
                                                    mode);
                        result.form = recursive.form;
                        result.count *= recursive.count;
                        if (recursive.extra)
                            result.extra = recursive.extra;
                    }
                    form = result.form;
                    count = result.count;
                    extra = result.extra;
                }
            }
        }
    }
}

// Resolves each perk entry's form and the chance global against the owner's file, removing and warning about entries that fail to resolve.
// @fnv 0x00488570
void TESLeveledList::InitItem(TESForm* owner)
{
    struct ResolveState
    {
        BGSPerkEntry* entry;
        BSSimpleList<BGSPerkEntry*>* node;
        BSSimpleList<BGSPerkEntry*>* previous;
        TESFile* file;
    } resolveState;
    {
        resolveState.previous = 0;
        resolveState.node =
            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
        resolveState.entry = 0;
        resolveState.file = owner ? owner->GetFile(-1) : 0;
        unsigned int formID, globalID;
        while (resolveState.node && (resolveState.entry = resolveState.node->GetItem()) != 0)
        {
            formID = reinterpret_cast<unsigned int>(resolveState.entry->form);
            TESForm::RemapFormIDForFile(formID, resolveState.file);
            resolveState.entry->form = TESForm::GetFormByID(formID);
            if (!resolveState.entry->form)
            {
                reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(resolveState.node)->RemoveHead();
                struct DeletedEntry
                {
                    BGSPerkEntry* doomed;
                    BGSPerkEntry* object;
                } deletion;
                deletion.doomed = resolveState.entry;
                deletion.object = deletion.doomed;
                deletion.object ? deletion.object->Destroy(1) : 0;
                resolveState.entry = 0;
                if (owner)
                {
                    if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                        Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for owner object \"%s\".",
                                formID, owner->GetEditorID());
                    else
                        Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for owner object (%08X).",
                                formID, owner->GetFormID());
                }
                else
                    Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for unknown owner.", formID);
            }
            else
            {
                resolveState.previous = resolveState.node;
                resolveState.node = resolveState.node->GetNext();
            }
            if (resolveState.entry && resolveState.entry->extra)
                resolveState.entry->extra->InitItem(owner);
        }
        if (m_pLevelGlobal)
        {
            globalID = reinterpret_cast<unsigned int>(m_pLevelGlobal);
            TESForm::RemapFormIDForFile(globalID, resolveState.file);
            m_pLevelGlobal = dynamic_cast<TESGlobal*>(TESForm::GetFormByID(globalID));
            if (!m_pLevelGlobal)
            {
                if (owner)
                {
                    if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                        Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for owner object \"%s\".",
                                globalID, owner->GetEditorID());
                    else
                        Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for owner object (%08X).",
                                globalID, owner->GetFormID());
                }
                else
                    Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for unknown owner.", globalID);
            }
        }
    }
}

// @fnv 0x00488d70
void TESLeveledList::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(0x80000000))
    {
        if (!reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(m_kLeveledObjects)->IsEmpty())
            ClearScriptAddedLeveledObjects();
        unsigned int uiEntryCount = buffer->ReadElementCount();
        for (unsigned int i = 0; i < uiEntryCount; ++i)
        {
            struct SavedForm
            {
                TESForm* form;
                float health;
            } savedItem;
            {
                savedItem.form = 0;
                unsigned short count = 0;
                unsigned short level = 0;
                savedItem.health = 0;
                savedItem.form =
                    TESForm::GetFormByID(reinterpret_cast<BGSLoadGameBuffer*>(buffer)->ReadFormIdentifier());
                buffer->ReadTypedData(&level, 2);
                buffer->ReadTypedData(&count, 2);
                buffer->ReadTypedData(&savedItem.health, 4);
                if (savedItem.form)
                {
                    ContainerItemExtra* extra = 0;
                    if (savedItem.health != -1.0)
                    {
                        extra = new ContainerItemExtra;
                        extra->FUN_0040eb90(savedItem.health);
                    }
                    reinterpret_cast<FileEntryList*>(this)->Copy(buffer->GetForm(), level, count, savedItem.form,
                                                                 extra);
                }
            }
        }
    }
}

// @fnv 0x004726f0
bool TESFile::NextChunk()
{
    struct ChunkPosition
    {
        unsigned int offset, formSize;
    } chunkPos;
    chunkPos.formSize = m_kRecordInfo.length;
    if (IsCurrentFormCompressed())
        chunkPos.formSize = reinterpret_cast<HighProcess*>(this)->GetPostAnimationAction();
    m_uiRecordOffset += m_uiChunkSize + 6;
    if (m_uiRecordOffset >= chunkPos.formSize)
    {
        FUN_004720d0();
        return false;
    }
    chunkPos.offset = m_uiRecordSize + reinterpret_cast<bhkLiquidAction*>(this)->GetInstanceSize() + m_uiRecordOffset;
    if (!IsCurrentFormCompressed())
        m_pFile->vfn_14(chunkPos.offset, DAT_010a2480);
    m_uiCurrentOffset = 0;
    FUN_004720d0();
    GetChunkID();
    return true;
}

// @fnv 0x00487900
void TESLeveledList::InitializeLeveledList()
{
    BSSimpleList<BGSPerkEntry*>* node =
        reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
    while (node)
    {
        BGSPerkEntry* entry = node->GetItem();
        if (entry)
        {
            struct DeletedEntry
            {
                BGSPerkEntry* doomed;
                BGSPerkEntry* object;
            } deletion;
            deletion.doomed = entry;
            deletion.object = deletion.doomed;
            deletion.object ? deletion.object->Destroy(1) : 0;
            reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(node)->RemoveHead();
        }
        else
            node = node->GetNext();
    }
    reinterpret_cast<BSSimpleList<ActorCause*>*>(m_kLeveledObjects)->RemoveAll();
}

// @fnv 0x004877e0
bool TESLeveledList::GetAllBelow()
{
    if (m_ucChanceNone & 1)
        return true;
    else
        return false;
}

// @fnv 0x004878a0
bool TESLeveledList::GetUseAll()
{
    if (m_ucChanceNone & 4)
        return true;
    else
        return false;
}

// @fnv 0x00487f50
unsigned int DialogueRandom()
{
    return MersenneTwister::GetRandomGenerator()->GetRandomUInt();
}

struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESActorBase;
struct TESModel;
struct TESModelTextureSwap;
struct TESFormList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct TESObject : public TESForm
{
    virtual void __vslot_10();
    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm* GetAssociatedWaterForm();
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual void Destroy3DModel(TESObjectREFR*);
    virtual bool HasLoaded3D();
    virtual bool IsModelValid();
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool IsBoundItem(BipedAnim*);
    virtual void Set3D(NiAVObject*, bool);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiAVObject* Create3DForReference(TESObjectREFR*);
    NiAVObject* Get3D();
    virtual unsigned int GetRefCount();
    TESFormList* GetParentList();
    unsigned int GetModelCount();
    virtual bool IsObject();
    virtual char* GetObjectDisplayName();
    void SetParentList(TESFormList*);
    void nod_SetPrev(TESObject*);
    void nod_SetNext(TESObject*);
    TESObject* nod_GetPrev();
    TESObject* nod_GetNext();
    static NiAVObject* FindGeometryByName(NiAVObject*, char*);
    char* GetModelFileName(TESObjectREFR*);
    void BuildModelFileName(TESObjectREFR*, char*);
    void GetLODModelFileName(TESObjectREFR*, char*);
    void GetLODFlatFileName(TESObjectREFR*, char*);
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
typedef char _sizecheck_TESObject[sizeof(TESObject) == 36 ? 1 : -1];
struct TESBoundObject : public TESObject
{
    virtual void __vslot_10();
    virtual NiAVObject* Get3DObject(TESObjectREFR*);
    virtual bool IsBoundItem(char*);
    virtual bool IsBoundObject();
    void SetBoundMinMax(NiAVObject*);
    void CopyBoundData(TESBoundObject*);
    static void CalcBoundingBox(NiAVObject*, NiPoint3*, NiPoint3*, void*, void*, float*);
    static void CalcBoundingBoxRecursive(NiAVObject*, NiPoint3*, NiPoint3*, bool*, bool*, void*, void*, float*);
    struct blob12 GetBoundsMinimum();
    struct blob12 GetBoundsMaximum();
    float GetBoundSize();
    virtual void InitializeBoundData();
    virtual void LoadBoundData(TESFile*);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual bool IsBoundItem();
    virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool GetLODObjectExists(bool);
    void __local_vftable_ctor_closure();
    char TESBoundObjectBounds[12];
};
typedef char _sizecheck_TESBoundObject[sizeof(TESBoundObject) == 48 ? 1 : -1];
struct TESBoundAnimObject : public TESBoundObject
{
    virtual void __vslot_10();
    virtual bool IsBoundAnimObject();
    virtual void Set3D(NiAVObject*, bool);
    virtual bool IsBoundItem(char*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_TESBoundAnimObject[sizeof(TESBoundAnimObject) == 48 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00487790_shell : public TESLeveledList
{
    unsigned char FUN_00487790();
};

// Returns the value of the TESGlobalValueReader at offset 0x10 if present, otherwise the byte at offset 0x0c.
// @fnv 0x00487790
unsigned char FUN_00487790_shell::FUN_00487790()
{
    if (*reinterpret_cast<TESGlobalValueReader* const*>(reinterpret_cast<const char*>(this) + 0x10))
        return static_cast<unsigned char>(
            (*reinterpret_cast<TESGlobalValueReader* const*>(reinterpret_cast<const char*>(this) + 0x10))->GetValue());
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 0x0c);
}

namespace fnv_00487840 {
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESActorBase;
struct TESModel;
struct TESModelTextureSwap;
struct TESFormList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct TESObject : public TESForm
{
    virtual void __vslot_10();
    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm* GetAssociatedWaterForm();
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual void Destroy3DModel(TESObjectREFR*);
    virtual bool HasLoaded3D();
    virtual bool IsModelValid();
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool IsBoundItem(BipedAnim*);
    virtual void Set3D(NiAVObject*, bool);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiAVObject* Create3DForReference(TESObjectREFR*);
    NiAVObject* Get3D();
    virtual unsigned int GetRefCount();
    TESFormList* GetParentList();
    unsigned int GetModelCount();
    virtual bool IsObject();
    virtual char* GetObjectDisplayName();
    void SetParentList(TESFormList*);
    void nod_SetPrev(TESObject*);
    void nod_SetNext(TESObject*);
    TESObject* nod_GetPrev();
    TESObject* nod_GetNext();
    static NiAVObject* FindGeometryByName(NiAVObject*, char*);
    char* GetModelFileName(TESObjectREFR*);
    void BuildModelFileName(TESObjectREFR*, char*);
    void GetLODModelFileName(TESObjectREFR*, char*);
    void GetLODFlatFileName(TESObjectREFR*, char*);
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
typedef char _sizecheck_TESObject[sizeof(TESObject) == 36 ? 1 : -1];
struct TESBoundObject : public TESObject
{
    virtual void __vslot_10();
    virtual NiAVObject* Get3DObject(TESObjectREFR*);
    virtual bool IsBoundItem(char*);
    virtual bool IsBoundObject();
    void SetBoundMinMax(NiAVObject*);
    void CopyBoundData(TESBoundObject*);
    static void CalcBoundingBox(NiAVObject*, NiPoint3*, NiPoint3*, void*, void*, float*);
    static void CalcBoundingBoxRecursive(NiAVObject*, NiPoint3*, NiPoint3*, bool*, bool*, void*, void*, float*);
    struct blob12 GetBoundsMinimum();
    struct blob12 GetBoundsMaximum();
    float GetBoundSize();
    virtual void InitializeBoundData();
    virtual void LoadBoundData(TESFile*);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual bool IsBoundItem();
    virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool GetLODObjectExists(bool);
    void __local_vftable_ctor_closure();
    char TESBoundObjectBounds[12];
};
typedef char _sizecheck_TESBoundObject[sizeof(TESBoundObject) == 48 ? 1 : -1];
struct TESBoundAnimObject : public TESBoundObject
{
    virtual void __vslot_10();
    virtual bool IsBoundAnimObject();
    virtual void Set3D(NiAVObject*, bool);
    virtual bool IsBoundItem(char*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_TESBoundAnimObject[sizeof(TESBoundAnimObject) == 48 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00487840_shell : public TESLeveledList
{
    bool FUN_00487840();
};

// @fnv 0x00487840
bool FUN_00487840_shell::FUN_00487840()
{
    if (*((unsigned char*)this + 0xD) & 2)
        return true;
    else
        return false;
}
}  // namespace fnv_00487840

struct LeveledObject
{
    void* __vecDelDtor(unsigned int);
    TESForm* pForm;
    unsigned short m_sCount;
    unsigned short sLevel;
    ContainerItemExtra* m_pExtraData;
};
typedef char _sizecheck_LEVELED_OBJECT[sizeof(LeveledObject) == 12 ? 1 : -1];
struct FUN_00487ba0_shell : public LeveledObject
{
    void InitLeveledObject();
};

// @fnv 0x00487ba0
LeveledObject* __fastcall InitLeveledObject(LeveledObject* pThis)
{
    pThis->pForm = 0;
    pThis->m_pExtraData = 0;
    pThis->m_sCount = 1;
    pThis->sLevel = 1;
    return pThis;
}

struct FUN_00488350_shell : public TESLeveledList
{
    void AddLeveledItemsToContainer(TESObjectREFR*, TESContainer*);
};

float __cdecl floor(float);

// Reads the reference's level multiplier and all-below flag, computes a level from its level, and adds leveled list items to the container.
// @fnv 0x00488350
void FUN_00488350_shell::AddLeveledItemsToContainer(TESObjectREFR* apRef, TESContainer* apOutCont)
{
    if (!apRef || !apOutCont)
        return;

    float fLevelMult = 1.0f;
    int iallbelowforce = 0;
    apRef->GetExtraData()->GetLeveledItemData(fLevelMult, iallbelowforce);

    unsigned int icalclevel = 1;
    icalclevel = apRef->GetReferenceLevel(true);

    int ilevel = (int)floor(icalclevel * fLevelMult);
    if (ilevel < 1)
        ilevel = 1;

    PopulateContainerWithLeveledItems((unsigned short)ilevel, 1, apOutCont, iallbelowforce);
}

namespace fnv_0050ad90 {
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESActorBase;
struct TESModel;
struct TESModelTextureSwap;
struct TESFormList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct TESObject : public TESForm
{
    virtual void __vslot_10();
    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm* GetAssociatedWaterForm();
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual void Destroy3DModel(TESObjectREFR*);
    virtual bool HasLoaded3D();
    virtual bool IsModelValid();
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool IsBoundItem(BipedAnim*);
    virtual void Set3D(NiAVObject*, bool);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiAVObject* Create3DForReference(TESObjectREFR*);
    NiAVObject* Get3D();
    virtual unsigned int GetRefCount();
    TESFormList* GetParentList();
    unsigned int GetModelCount();
    virtual bool IsObject();
    virtual char* GetObjectDisplayName();
    void SetParentList(TESFormList*);
    void nod_SetPrev(TESObject*);
    void nod_SetNext(TESObject*);
    TESObject* nod_GetPrev();
    TESObject* nod_GetNext();
    static NiAVObject* FindGeometryByName(NiAVObject*, char*);
    char* GetModelFileName(TESObjectREFR*);
    void BuildModelFileName(TESObjectREFR*, char*);
    void GetLODModelFileName(TESObjectREFR*, char*);
    void GetLODFlatFileName(TESObjectREFR*, char*);
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
typedef char _sizecheck_TESObject[sizeof(TESObject) == 36 ? 1 : -1];
struct TESBoundObject : public TESObject
{
    virtual void __vslot_10();
    virtual NiAVObject* Get3DObject(TESObjectREFR*);
    virtual bool IsBoundItem(char*);
    virtual bool IsBoundObject();
    void SetBoundMinMax(NiAVObject*);
    void CopyBoundData(TESBoundObject*);
    static void CalcBoundingBox(NiAVObject*, NiPoint3*, NiPoint3*, void*, void*, float*);
    static void CalcBoundingBoxRecursive(NiAVObject*, NiPoint3*, NiPoint3*, bool*, bool*, void*, void*, float*);
    struct blob12 GetBoundsMinimum();
    struct blob12 GetBoundsMaximum();
    float GetBoundSize();
    virtual void InitializeBoundData();
    virtual void LoadBoundData(TESFile*);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual bool IsBoundItem();
    virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool GetLODObjectExists(bool);
    void __local_vftable_ctor_closure();
    char TESBoundObjectBounds[12];
};
typedef char _sizecheck_TESBoundObject[sizeof(TESBoundObject) == 48 ? 1 : -1];
struct TESBoundAnimObject : public TESBoundObject
{
    virtual void __vslot_10();
    virtual bool IsBoundAnimObject();
    virtual void Set3D(NiAVObject*, bool);
    virtual bool IsBoundItem(char*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_TESBoundAnimObject[sizeof(TESBoundAnimObject) == 48 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0050ad90_shell : public TESLeveledList
{
    int FUN_0050ad90();
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c8e1c;

// @fnv 0x0050ad90
int FUN_0050ad90_shell::FUN_0050ad90()
{
    return *g_011c8e1c.Int();
}
}  // namespace fnv_0050ad90

namespace fnv_0050b370 {
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESActorBase;
struct TESModel;
struct TESModelTextureSwap;
struct TESFormList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct TESObject : public TESForm
{
    virtual void __vslot_10();
    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm* GetAssociatedWaterForm();
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual void Destroy3DModel(TESObjectREFR*);
    virtual bool HasLoaded3D();
    virtual bool IsModelValid();
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool IsBoundItem(BipedAnim*);
    virtual void Set3D(NiAVObject*, bool);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiAVObject* Create3DForReference(TESObjectREFR*);
    NiAVObject* Get3D();
    virtual unsigned int GetRefCount();
    TESFormList* GetParentList();
    unsigned int GetModelCount();
    virtual bool IsObject();
    virtual char* GetObjectDisplayName();
    void SetParentList(TESFormList*);
    void nod_SetPrev(TESObject*);
    void nod_SetNext(TESObject*);
    TESObject* nod_GetPrev();
    TESObject* nod_GetNext();
    static NiAVObject* FindGeometryByName(NiAVObject*, char*);
    char* GetModelFileName(TESObjectREFR*);
    void BuildModelFileName(TESObjectREFR*, char*);
    void GetLODModelFileName(TESObjectREFR*, char*);
    void GetLODFlatFileName(TESObjectREFR*, char*);
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
typedef char _sizecheck_TESObject[sizeof(TESObject) == 36 ? 1 : -1];
struct TESBoundObject : public TESObject
{
    virtual void __vslot_10();
    virtual NiAVObject* Get3DObject(TESObjectREFR*);
    virtual bool IsBoundItem(char*);
    virtual bool IsBoundObject();
    void SetBoundMinMax(NiAVObject*);
    void CopyBoundData(TESBoundObject*);
    static void CalcBoundingBox(NiAVObject*, NiPoint3*, NiPoint3*, void*, void*, float*);
    static void CalcBoundingBoxRecursive(NiAVObject*, NiPoint3*, NiPoint3*, bool*, bool*, void*, void*, float*);
    struct blob12 GetBoundsMinimum();
    struct blob12 GetBoundsMaximum();
    float GetBoundSize();
    virtual void InitializeBoundData();
    virtual void LoadBoundData(TESFile*);
    virtual NiAVObject* Get3DObject(TESObjectREFR*, bool);
    virtual bool IsBoundItem();
    virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool GetLODObjectExists(bool);
    void __local_vftable_ctor_closure();
    char TESBoundObjectBounds[12];
};
typedef char _sizecheck_TESBoundObject[sizeof(TESBoundObject) == 48 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0050b370_shell : public TESLeveledList
{
    int FUN_0050b370();
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c8ed4;

// @fnv 0x0050b370
int FUN_0050b370_shell::FUN_0050b370()
{
    return *g_011c8ed4.Int();
}
}  // namespace fnv_0050b370

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00526ac0_shell : public TESGlobal
{
    float FUN_00526ac0();
};

// @fnv 0x00526ac0
float FUN_00526ac0_shell::FUN_00526ac0()
{
    return *(float*)((char*)this + 0x24);
}

struct FUN_00487800_shell
{
    void SetFlag(bool bFlag);
};

// Sets or clears bit 0 of the byte at offset 0xd of this object according to bFlag.
// @fnv 0x00487800
void FUN_00487800_shell::SetFlag(bool bFlag)
{
    if (bFlag)
        ((unsigned char*)this)[0xd] |= 1;
    else
        ((unsigned char*)this)[0xd] &= 0xfffffffe;
}

struct FUN_00487860_shell
{
    unsigned char m00;
    unsigned char m01;
    unsigned char m02;
    unsigned char m03;
    unsigned char m04;
    unsigned char m05;
    unsigned char m06;
    unsigned char m07;
    unsigned char m08;
    unsigned char m09;
    unsigned char m0a;
    unsigned char m0b;
    unsigned char m0c;
    unsigned char m0d;
    void SetFlag2(bool set);
};

// Sets or clears bit 1 of the byte at offset 0x0d according to the set argument.
// @fnv 0x00487860
void FUN_00487860_shell::SetFlag2(bool set)
{
    if (set)
        m0d |= 2;
    else
        m0d &= ~2;
}

struct FUN_00c611d0_shell
{
    int GetFour();
};

// @fnv 0x00c611d0
int FUN_00c611d0_shell::GetFour()
{
    return 4;
}

struct FUN_00c611e0_shell
{
    int __thiscall FUN_00c611e0(int arg1);
};

// @fnv 0x00c611e0
int __thiscall FUN_00c611e0_shell::FUN_00c611e0(int arg1)
{
    return 0;
}

struct FUN_00c61230_shell
{
    bool FUN_00c61230(int);
};

// @fnv 0x00c61230
bool FUN_00c61230_shell::FUN_00c61230(int)
{
    return false;
}

struct FUN_00c61240_shell
{
    bool __thiscall FUN_00c61240(int);
};

// @fnv 0x00c61240
bool __thiscall FUN_00c61240_shell::FUN_00c61240(int)
{
    return 0;
}

struct FUN_00c61250_shell
{
    void __thiscall FUN_00c61250(int a);
};

// @fnv 0x00c61250
void __thiscall FUN_00c61250_shell::FUN_00c61250(int a)
{}

struct FUN_00c61260_shell
{
    void FUN_00c61260(int a, int b, int c, int d, int e, int f);
};

// @fnv 0x00c61260
void __thiscall FUN_00c61260_shell::FUN_00c61260(int a, int b, int c, int d, int e, int f)
{}

extern "C" void* g_01204398;

struct FUN_00c61270_shell
{
    void* __thiscall FUN_00c61270();
};

// @fnv 0x00c61270
void* __thiscall FUN_00c61270_shell::FUN_00c61270()
{
    return &g_01204398;
}

struct NiRefObject
{
    virtual ~NiRefObject();
    static void* __thiscall FUN_00c61280(NiRefObject* obj, unsigned int flags);
};

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x00c61280
void* __thiscall NiRefObject::FUN_00c61280(NiRefObject* obj, unsigned int flags)
{
    obj->NiRefObject::~NiRefObject();
    if (flags & 1)
        __Dummy_00b6fef0(obj, 0x28);
    return obj;
}

struct FUN_004878c0_shell
{
    void SetFlag4(bool bFlag);
};

// @fnv 0x004878c0
void __thiscall FUN_004878c0_shell::SetFlag4(bool abSet)
{
    if (abSet)
        reinterpret_cast<unsigned char*>(this)[0xd] |= 4;
    else
        reinterpret_cast<unsigned char*>(this)[0xd] &= ~4;
}

extern void __fastcall FUN_00c4f980(void*);
extern int DAT_010c34ac;

struct FUN_00c60d50_shell
{
    int* vtable_ptr;
    FUN_00c60d50_shell();
};

// @fnv 0x00c60d50
FUN_00c60d50_shell::FUN_00c60d50_shell()
{
    FUN_00c4f980(this);
    vtable_ptr = &DAT_010c34ac;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
struct TmpEndian
{
    unsigned short f0;
    int f1;
    unsigned short f2;
    void SwapEndian();
};
// Byte-swaps the three fields f0, f1 and f2 of this struct via BSEndian.
// @fnv 0x00488510
void TmpEndian::SwapEndian()
{
    BSEndian(&f0, EndianSizeTag<2>());
    BSEndian(&f1, EndianSizeTag<2>());
    BSEndian(&f2, EndianSizeTag<2>());
}

class NiStream;
struct FUN_00c4f9f0_shell
{
    char _pad[12];
    void FUN_00c4f9f0(NiStream&);
};
struct NiColor
{
    char _pad[12];
    void LoadBinary(NiStream&);
};
template <typename T> void ReadBinaryValue(NiStream&, T&);
struct FUN_00c60e70_shell : public FUN_00c4f9f0_shell
{
    NiColor c1;
    NiColor c2;
    unsigned int u;
    void FUN_00c60e70(NiStream&);
};
// @fnv 0x00c60e70
void FUN_00c60e70_shell::FUN_00c60e70(NiStream& stream)
{
    FUN_00c4f9f0(stream);
    c1.LoadBinary(stream);
    c2.LoadBinary(stream);
    ReadBinaryValue<unsigned int>(stream, u);
}

struct FUN_00c60ec0_shell
{
    void FUN_00c4fa10(int);
    void FUN_00c60ec0(int a);
};

// @fnv 0x00c60ec0
void FUN_00c60ec0_shell::FUN_00c60ec0(int aiValue)
{
    FUN_00c4fa10(aiValue);
}

struct FUN_00c38020_shell
{
    unsigned char FUN_00c4fa30(int);
    bool FUN_00c60ee0(int);
};
// @fnv 0x00c60ee0
bool FUN_00c38020_shell::FUN_00c60ee0(int a)
{
    if (!FUN_00c4fa30(a))
        return false;
    return true;
}

namespace fnv_00c60f10 {
struct NiColor
{
    void SaveBinary(class NiStream&);
    float r;
    float g;
    float b;
};
struct FUN_00c38050_Holder
{
    void FUN_00c4fa60(class NiStream&);
    unsigned char data[12];
};
void __cdecl CallAnimCallback(class NiStream&, int*);
struct Host : FUN_00c38050_Holder
{
    NiColor c1;
    NiColor c2;
    int f24;
    void FUN_00c60f10(class NiStream&);
};
// @fnv 0x00c60f10
void Host::FUN_00c60f10(class NiStream& s)
{
    FUN_00c38050_Holder::FUN_00c4fa60(s);
    c1.SaveBinary(s);
    c2.SaveBinary(s);
    CallAnimCallback(s, &f24);
}
}  // namespace fnv_00c60f10

namespace fnv_00488c50 {
struct BSFaceGenKeyframe
{
    float GetTime();
};
struct BGSSaveFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue(int, unsigned int);
};
struct LeveledObject
{
    TESForm* pForm;
    int pad0;
    int pad1;
    void* m_pExtraData;
};
struct FUN_00488c50_shell : TESLeveledList
{
    void SaveLeveledListEntries(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00488c50
void FUN_00488c50_shell::SaveLeveledListEntries(BGSSaveFormBuffer* apSaveGameBuffer)
{
    if (apSaveGameBuffer->GetChangeFlags(0x80000000))
    {
        unsigned int isaveGameCount = 0;
        unsigned int isaveGameBufferPos = apSaveGameBuffer->StartVariableSizedValue();
        BSSimpleList<LeveledObject*>* pCurrentElementNext = (BSSimpleList<LeveledObject*>*)((char*)this + 0x14);
        while (pCurrentElementNext)
        {
            LeveledObject* pitem = pCurrentElementNext->GetItem();
            if (pitem)
            {
                apSaveGameBuffer->SerializeFormData(pitem->pForm, 0);
                apSaveGameBuffer->SaveData((char*)pitem + 6, 2, 0);
                apSaveGameBuffer->SaveData((char*)pitem + 4, 2, 0);
                float fhealthPercent = -1.0f;
                if (*(void**)((char*)pitem + 8))
                    fhealthPercent = ((BSFaceGenKeyframe*)*(void**)((char*)pitem + 8))->GetTime();
                apSaveGameBuffer->SaveData(&fhealthPercent, 4, 0);
                isaveGameCount++;
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
        apSaveGameBuffer->SaveVariableSizedValue(isaveGameCount, isaveGameBufferPos);
    }
}
}  // namespace fnv_00488c50

struct Vec3
{
    float x, y, z;
};
struct Shell
{
    void CopyMembersStreamWithField(Shell*, int);
    char pad0c[0xc];
    Vec3 m0c;
    Vec3 m18;
    float m24;
    void FUN_00c60e00(Shell* dest, int a);
};
// Calls CopyMembersStreamWithField on dest, then copies m0c, m18 and m24 from this into dest.
// @fnv 0x00c60e00
void Shell::FUN_00c60e00(Shell* dest, int aiArg)
{
    CopyMembersStreamWithField(dest, aiArg);
    dest->m0c = m0c;
    dest->m18 = m18;
    float f = m24;
    dest->m24 = f;
}

namespace fnv_00c60d70 {
struct A51BF0Base
{
    char padding[4];

    static void* __cdecl operator new(unsigned int size);
};

struct Shell : public A51BF0Base
{
    char padding[36];

    void FUN_00c60e00(Shell* object, int value);
};

struct FUN_00c60d50_shell : public Shell
{
    FUN_00c60d50_shell();
};

struct FUN_00c60d70_shell : public Shell
{
    Shell* FUN_00c60d70(int value);
};

// Allocates a FUN_00c60d50_shell, passes value to FUN_00c60e00 on it, and returns the new shell.
// @fnv 0x00c60d70
Shell* FUN_00c60d70_shell::FUN_00c60d70(int value)
{
    Shell* shell = new FUN_00c60d50_shell;
    FUN_00c60e00(shell, value);
    return shell;
}
}  // namespace fnv_00c60d70

struct ScriptAddedEntries
{
    unsigned char FUN_008256d0();
    BGSPerkEntry*& FUN_006815c0();
    void FUN_0063f7b0();
};
struct CurrentLeveledEntries
{
    void FUN_00905330(BGSPerkEntry* const&);
};
struct FUN_00487980_shell : TESLeveledList
{
    void FUN_00487980();
};

// @fnv 0x00487980
void FUN_00487980_shell::FUN_00487980()
{
    while (!reinterpret_cast<ScriptAddedEntries*>(m_kLeveledObjects)->FUN_008256d0())
    {
        BGSPerkEntry* entryToDestroy = reinterpret_cast<ScriptAddedEntries*>(m_kLeveledObjects)->FUN_006815c0();
        reinterpret_cast<ScriptAddedEntries*>(m_kLeveledObjects)->FUN_0063f7b0();
        reinterpret_cast<CurrentLeveledEntries*>(leveledList)->FUN_00905330(entryToDestroy);

        BGSPerkEntry* item = entryToDestroy;
        BGSPerkEntry* removed = item;
        removed ? removed->Destroy(1) : 0;
    }
}

extern void __cdecl FUN_004858f0(unsigned int, unsigned int);
extern void __cdecl FUN_00485910(unsigned int, unsigned int);
extern void __cdecl AppendChunk(unsigned int, const void*, unsigned int);
extern unsigned char __cdecl FUN_00401500();

struct LevelNode_00488400
{
    LeveledObject** FUN_006815c0();
    LevelNode_00488400* FUN_00726070();
};

struct ExtraSaver_00488400 : ContainerItemExtra
{
    void WriteToChunk();
};

struct FUN_00488400_shell : TESLeveledList
{
    LevelNode_00488400* FUN_00717e50();
    void SaveLeveledList();
};

// @fnv 0x00488400
void FUN_00488400_shell::SaveLeveledList()
{
    FUN_004858f0(0x444c564c, m_pChanceGlobal);
    FUN_004858f0(0x464c564c, m_ucChanceNone);
    if (m_pLevelGlobal)
    {
        unsigned int chanceFormID = m_pLevelGlobal->GetFormID();
        FUN_00485910(0x474c564c, chanceFormID);
    }
    LevelNode_00488400* pEntryNode = FUN_00717e50();
    LeveledObject* entry;
    while (pEntryNode && (entry = *pEntryNode->FUN_006815c0()) != 0)
    {
        TmpEndian levelEntryData;
        levelEntryData.f1 = entry->pForm->GetFormID();
        levelEntryData.f0 = entry->sLevel;
        levelEntryData.f2 = entry->m_sCount;
        if (FUN_00401500())
            levelEntryData.SwapEndian();
        AppendChunk(0x4f4c564c, &levelEntryData, 12);
        if (FUN_00401500())
            levelEntryData.SwapEndian();
        if (entry->m_pExtraData)
            static_cast<ExtraSaver_00488400*>(entry->m_pExtraData)->WriteToChunk();
        pEntryNode = pEntryNode->FUN_00726070();
    }
}

struct NiObject;
struct TCVec3
{
    float x, y, z;
};

struct TCEq
{
    bool FUN_00c4fa80(NiObject* pObject);
};

struct TCColorEq : public TCEq
{
    int unk00;
    int unk04;
    int unk08;
    TCVec3 m0c;
    TCVec3 m18;
    float m24;
    bool FUN_00c60f60(NiObject* pObject);
};

// Calls the base equality check, then compares m0c, m18 and m24 against the same fields of pObject cast to TCColorEq.
// @fnv 0x00c60f60
bool TCColorEq::FUN_00c60f60(NiObject* pObject)
{
    bool bResultTmp = FUN_00c4fa80(pObject);
    if (bResultTmp)
    {
        TCColorEq* pOther = (TCColorEq*)pObject;
        {
            TCVec3* pB = &pOther->m0c;
            TCVec3* pA = &m0c;
            bResultTmp = pA->x == pB->x && pA->y == pB->y && pA->z == pB->z;
        }
        {
            TCVec3* pB3 = &pOther->m18;
            TCVec3* pA9 = &m18;
            bResultTmp &= (bool)(int)(pA9->x == pB3->x && pA9->y == pB3->y && pA9->z == pB3->z);
        }
        {
            float fValue3 = m24;
            bResultTmp &= (fValue3 == pOther->m24);
        }
    }
    return bResultTmp;
}

struct VTarget
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
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual int v8c();
};

struct Struct08
{
    int unk00;
    int unk04;
    int unk08;
    VTarget* unk0c;
};

struct C00c611f0
{
    int FUN_00c611f0(Struct08* arg);
};

// Calls v8c on the VTarget pointer stored in arg->unk0c and returns 0.
// @fnv 0x00c611f0
int C00c611f0::FUN_00c611f0(Struct08* apStruct)
{
    int res;
    VTarget* volatile form = apStruct->unk0c;
    res = form->v8c();
    return 0;
}

struct ListExtra
{
    TESForm* owner;
    unsigned int rank;
    float health;
    bool FUN_0040e9c0();
    bool Compare(ListExtra*);
};
struct LeveledEntry
{
    TESForm* form;
    unsigned short count, level;
    ListExtra* extra;
};
struct ListNode
{
    LeveledEntry* item;
    ListNode* next;
    bool FUN_008256d0();
    ListNode* FUN_00726070();
    LeveledEntry*& FUN_006815c0();
};
// The external leaf consumes the component receiver in ECX and returns its embedded head.
ListNode* __fastcall FUN_00717e50(TESLeveledList*);
class LeveledComparison : public TESLeveledList
{
  public:
    bool FUN_004889d0(BaseFormComponent*);
};
// Compares this leveled list against another, returning true if any property or entry differs.
// @fnv 0x004889d0
bool LeveledComparison::FUN_004889d0(BaseFormComponent* component)
{
    TESLeveledList* pOtherList = dynamic_cast<TESLeveledList*>(component);
    if (!pOtherList)
        return true;
    if (GetAllBelow() != pOtherList->GetAllBelow())
        return true;
    if (vfn_14() != pOtherList->vfn_14())
        return true;
    if (vfn_10() != pOtherList->vfn_10())
        return true;
    if (GetUseAll() != pOtherList->GetUseAll())
        return true;
    if (m_pLevelGlobal != pOtherList->m_pLevelGlobal)
        return true;
    ListNode* first = FUN_00717e50(this);
    ListNode* pSecondNode = FUN_00717e50(pOtherList);
    if (first->FUN_008256d0() != pSecondNode->FUN_008256d0())
        return true;
    if (!first->FUN_008256d0())
    {
        while (first && pSecondNode)
        {
            LeveledEntry* a = first->FUN_006815c0();
            LeveledEntry* b = pSecondNode->FUN_006815c0();
            if (a && b)
            {
                if (a->form != b->form)
                    return true;
                if (a->level != b->level)
                    return true;
                if (a->count != b->count)
                    return true;
                if (a->extra && !b->extra)
                {
                    if (!a->extra->FUN_0040e9c0())
                        return true;
                }
                if (!a->extra && b->extra)
                {
                    if (!b->extra->FUN_0040e9c0())
                        return true;
                }
                if (a->extra && b->extra)
                {
                    if (a->extra->Compare(b->extra))
                        return true;
                }
            }
            first = first->FUN_00726070();
            pSecondNode = pSecondNode->FUN_00726070();
        }
        if (first || pSecondNode)
            return true;
    }
    else
    {
        if (!pSecondNode->FUN_008256d0())
            return true;
    }
    return false;
}

namespace fnv_00c610a0 {
struct BSShaderAccumulator : FUN_00c60d50_shell
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    static void* __cdecl operator new(unsigned int size);
};

// Allocates and returns a new BSShaderAccumulator instance on the heap.
// @fnv 0x00c610a0
FUN_00c60d50_shell* __cdecl FUN_00c610a0(void)
{
    return new BSShaderAccumulator();
}
}  // namespace fnv_00c610a0

extern "C" void* __cdecl FUN_00ec43fb(void* in, int vfDelta, void* srcType, void* targetType, int isReference);
extern char DAT_01183040[]; /* .?AVBaseFormComponent@@ */
extern char DAT_01186c1c[]; /* .?AVTESLeveledList@@ */

class LevObjX
{
  public:
    TESForm* form;
    unsigned short level;
    unsigned short count;
    ContainerItemExtra* extra;
    LevObjX()
    {}
};

class LLNode_cls
{
  public:
    LevObjX** FUN_006815c0();
    LLNode_cls* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(LevObjX*& obj);
    void FUN_00905820(LevObjX*& obj);
};

class CIE_cls : public ContainerItemExtra
{
  public:
    bool FUN_0040e9c0();
    void FUN_0040e980(ContainerItemExtra* src3);
};

class FUN_004887a0_cls : public TESLeveledList
{
  public:
    LLNode_cls* FUN_00717e50();
    void FUN_00487900();
    void FUN_0042e680(unsigned char v);
    void SetFlag(bool v);
    void SetFlag2(bool v);
    void SetFlag4(bool v);
    void FUN_004887a0(void* comp);
};

// Copies the leveled list entries and properties from another TESLeveledList instance into this one.
// @fnv 0x004887a0
void FUN_004887a0_cls::FUN_004887a0(void* apSource)
{
    TESLeveledList* src3 = (TESLeveledList*)FUN_00ec43fb(apSource, 0, &DAT_01183040, &DAT_01186c1c, 0);
    if (src3 == 0)
    {
        return;
    }
    FUN_00487900();
    LLNode_cls* it = static_cast<FUN_004887a0_cls*>(src3)->FUN_00717e50();
    LevObjX* cell5;
    LLNode_cls* dst = FUN_00717e50();
    while (it != 0 && (cell5 = *it->FUN_006815c0()) != 0)
    {
        LevObjX* newObj = new LevObjX();
        newObj->form = cell5->form;
        newObj->count = cell5->count;
        newObj->level = cell5->level;
        if (cell5->extra != 0 && !static_cast<CIE_cls*>(cell5->extra)->FUN_0040e9c0())
        {
            newObj->extra = new ContainerItemExtra();
            static_cast<CIE_cls*>(newObj->extra)->FUN_0040e980(cell5->extra);
        }
        if (FUN_00717e50()->FUN_008256d0())
        {
            dst->FUN_005ae3d0(newObj);
        }
        else
        {
            dst->FUN_00905820(newObj);
            dst = dst->FUN_00726070();
        }
        it = it->FUN_00726070();
    }
    m_pLevelGlobal = src3->m_pLevelGlobal;
    FUN_0042e680(src3->vfn_10());
    SetFlag(src3->FUN_004877e0());
    SetFlag2(src3->vfn_14());
    SetFlag4(src3->FUN_004878a0());
}

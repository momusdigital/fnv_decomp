// fallout_shared/magic/magicitem.cpp: MagicItem, MagicStatus, UnloadMagic, MagicLabel (18 functions)

#include "magicitem_decls.h"

// Looks up the TESForm for auiID and returns it cast to MagicItemForm or MagicItemObject, otherwise null.
// @fnv 0x0040a250
MagicItem* MagicItem::GetMagicItemByID(unsigned int auiID)
{
    MagicItemObject* pObject;
    TESForm* pForm;
    MagicItemForm* pFormItem;
    pForm = TESForm::GetFormByID(auiID);
    if (pForm)
    {
        pFormItem = dynamic_cast<MagicItemForm*>(pForm);
        pObject = dynamic_cast<MagicItemObject*>(pForm);
        if (pFormItem)
            return pFormItem;
        if (pObject)
            return pObject;
    }
    return 0;
}

// Initializes every EffectItem in the list with apForm and counts how many are hostile, storing the count.
// @fnv 0x0040c030
void MagicItem::LoadEffectsFromForm(TESForm* apForm)
{
    EffectItemList* pIter = this;
    m_iEffectCount = 0;
    while (pIter)
    {
        if (EffectItem* pItem = pIter->GetItem())
        {
            pItem->InitItem(apForm);
            if (pItem->IsHostile())
                m_iEffectCount++;
        }
        pIter = (EffectItemList*)pIter->GetNext();
    }
}

// @fnv 0x0040b470
bool MagicItem::IsLoaded()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    if (pSelfEffectSetting && pSelfEffectSetting->GetModelLength() > 0 && !pSelfEffectSetting->IsModelLoaded())
        return false;

    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            EffectItem* pItem = pIter->GetItem();
            EffectSetting* pEffect = pItem ? pItem->GetEffectSetting() : 0;
            if (pEffect && pEffect->IsAssociatedFormUsed() && !pEffect->HasEffectID())
                return false;
            pIter = (EffectItemList*)pIter->GetNext();
        }
    }
    return true;
}

// Scans the effect list for the best non-detrimental effect by range then cost and returns its EffectSetting, or null if none.
// @fnv 0x0040a300
EffectSetting* MagicItem::GetEffectSettingForRange(MagicSystem::Range aeRange)
{
    struct BestEffect
    {
        MagicSystem::Range range;
        EffectItem* item;
        int cost;
    } best;
    EffectItemList* pIter;
    best.item = 0;
    pIter = this;
    if (pIter->IsEmpty())
        return 0;
    best.cost = -1;
    best.range = aeRange;
    while (pIter)
    {
        struct CurrentEffect
        {
            EffectItem* item;
            int cost;
            MagicSystem::Range range;
        } current;
        current.item = pIter->GetItem();
        current.cost = static_cast<int>(current.item->GetCost(0));
        current.range = current.item->GetRange();
        if (!current.item->IsDetrimental() &&
            (current.range > best.range || (current.range == best.range && current.cost > best.cost)))
        {
            best.item = current.item;
            best.cost = current.cost;
            best.range = current.item->GetRange();
        }
        pIter = (EffectItemList*)pIter->GetNext();
    }
    return best.item ? best.item->GetEffectSetting() : 0;
}

// @fnv 0x0040b6b0
bool MagicItem::IsLoading()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    {
        bool m_bHeaderParsed = true;
        if (pSelfEffectSetting && pSelfEffectSetting->GetModelLength() > 0 && !pSelfEffectSetting->IsModelLoaded())
        {
            m_bHeaderParsed = false;
            if (!pSelfEffectSetting->HasNoAssociatedActorValue())
                return false;
        }
        EffectItemList* pIter = this;
        if (!pIter->IsEmpty())
        {
            while (pIter)
            {
                EffectItem* pItem = pIter->GetItem();
                EffectSetting* pEffect = pItem ? pItem->GetEffectSetting() : 0;
                if (pEffect && pEffect->IsAssociatedFormUsed() && !pEffect->HasEffectID())
                {
                    m_bHeaderParsed = false;
                    if (!pEffect->UsesAssociatedActorValue())
                        return false;
                }
                pIter = (EffectItemList*)pIter->GetNext();
            }
        }
        if (m_bHeaderParsed)
            return false;
        return true;
    }
}

// @fnv 0x0040a420
void MagicItem::Preload(bool immediate)
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    bool bProceed = false;
    bool bLoad = false;
    if (immediate || IsLoaded())
    {
        bProceed = true;
        bLoad = true;
    }
    else if (IsLoading())
    {
        bProceed = true;
        bLoad = false;
    }
    if (!bProceed)
    {
        g_modelLoader->QueueMagicEffectModel(this, pSelfEffectSetting, 0);
        return;
    }
    if (pSelfEffectSetting)
    {
        if (bLoad && pSelfEffectSetting->GetModelLength() > 0)
            g_modelLoader->LoadFile(pSelfEffectSetting->GetModelFilePath(), 0, true, false, false, false);
        pSelfEffectSetting->FUN_004088c0();
    }
    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            struct CurrentEffect
            {
                EffectItem* item;
                EffectSetting* effect;
            } current;
            current.item = pIter->GetItem();
            current.effect = current.item->GetEffectSetting();
            if (current.effect->IsAssociatedFormUsed())
            {
                if (bLoad)
                {
                    TESForm* form = current.effect->FUN_005f5f80();
                    if (form && current.effect->FUN_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(form);
                        if (weapon && weapon->model.GetModelLength() > 0)
                            g_modelLoader->LoadFile(weapon->model.GetModelFilePath(), 0, true, false, false, false);
                    }
                    else if (form && current.effect->FUN_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(form);
                        if (armor)
                        {
                            g_modelLoader->LoadFile(armor->biped.GetBipedModel(0), 0, true, false, false, false);
                            g_modelLoader->LoadFile(armor->biped.GetBipedModel(1), 0, true, false, false, false);
                        }
                    }
                    else if (form && current.effect->FUN_00403e60(0x40000))
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(form);
                        if (pNPC)
                        {
                            struct ModelFileIteration
                            {
                                BSSimpleList<const char*>* list;
                                BSSimpleList<const char*>* iter;
                            } modelFiles;
                            modelFiles.list = pNPC->GetModelFiles(true, true);
                            modelFiles.iter = modelFiles.list;
                            while (modelFiles.iter && !modelFiles.iter->IsEmpty())
                            {
                                const char* filename = modelFiles.iter->GetItem();
                                g_modelLoader->LoadFile(filename, 0, true, false, false, false);
                                modelFiles.iter = modelFiles.iter->GetNext();
                            }
                            modelFiles.list->RemoveAll();
                            delete modelFiles.list;
                        }
                        TESCreature* creature = dynamic_cast<TESCreature*>(form);
                        if (creature)
                        {
                            g_modelLoader->LoadFile(creature->model.GetModelFilePath(), 0, true, false, false, false);
                            struct ModelPaths
                            {
                                BSSimpleList<const char*>* node;
                                const char* base;
                                BSSimpleList<const char*>* files;
                                char* slash;
                                const char* filename;
                            } modelPaths;
                            modelPaths.filename = creature->model.GetModelFilePath();
                            modelPaths.files = creature->modelList.FUN_00717e50();
                            char path[260];
                            TaskQueueInterface::CopyStringToBuffer(path, 260, modelPaths.filename);
                            modelPaths.slash = FUN_0040ab30(path, '\\');
                            modelPaths.node = modelPaths.files;
                            while (modelPaths.slash && modelPaths.node)
                            {
                                modelPaths.slash[1] = 0;
                                const char* name = modelPaths.node->GetItem();
                                if (name)
                                {
                                    strcat_s(path, 260, name);
                                    g_modelLoader->LoadFile(path, 0, true, false, false, false);
                                }
                                modelPaths.node = modelPaths.node->GetNext();
                            }
                            modelPaths.base = strrchr(modelPaths.filename, '\\');
                            if (modelPaths.base && !_strnicmp(modelPaths.base + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    g_modelLoader->GetModelFileList(modelPaths.filename, false, false, 0);
                                BSSimpleList<const char*>* node = files;
                                while (node)
                                {
                                    const char* name = node->GetItem();
                                    if (name)
                                        g_modelLoader->LoadKF(name);
                                    delete[] name;
                                    node = node->GetNext();
                                }
                                files->RemoveAll();
                                delete files;
                            }
                            if (creature->animation.HasSpecialAnimations())
                            {
                                modelPaths.slash[1] = 0;
                                strcat_s(path, 260, "SpecialAnims");
                                strcat_s(path, 260, "\\");
                                modelPaths.slash = FUN_0040ab30(path, '\\');
                                BSSimpleList<const char*>* anim = creature->animation.FUN_00717e50();
                                while (anim)
                                {
                                    modelPaths.slash[1] = 0;
                                    const char* name = anim->GetItem();
                                    if (name)
                                    {
                                        strcat_s(path, 260, name);
                                        g_modelLoader->LoadKF(path);
                                    }
                                    anim = anim->GetNext();
                                }
                            }
                        }
                    }
                }
                if (!current.effect->HasEffectID() && !current.effect->UsesAssociatedActorValue() &&
                    current.effect->FUN_00403e60(0x40000))
                    FUN_0040ab50();
                current.effect->UpdateCounter();
            }
            pIter = (EffectItemList*)pIter->GetNext();
        }
    }
}

// @fnv 0x0040ab30
char* FUN_0040ab30(char* pcString, int cChar)
{
    return (char*)strrchr((const char*)pcString, cChar);
}

struct FUN_0040c110_obj
{
    void FUN_0040c130();
};
void __fastcall FUN_0040c130(void*);

struct FUN_0040c110_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void __fastcall FUN_0040c130(FUN_0040c110_ptr::Target*);

// @fnv 0x0040c110
void __fastcall FUN_0040c110(FUN_0040c110_ptr* _this)
{
    if (_this->m_pObject)
        FUN_0040c130(_this->m_pObject);
}

extern int DAT_01202800;

// Returns pThis[1] when pThis is non-null, otherwise resets DAT_01202800 to 0 and returns it.
// @fnv 0x0043d4d0
int& __fastcall FUN_0043d4d0(int* pThis)
{
    return pThis ? pThis[1] : (DAT_01202800 = 0, DAT_01202800);
}

struct FUN_004047f0_arg
{
    const BSStringT<char>* s;
};
const char* __fastcall FUN_00559450(const BSStringT<char>*);
void __fastcall FUN_00403970(BSStringT<char>*);
// @fnv 0x004047f0
BSStringT<char>* __fastcall AssignFromString(BSStringT<char>* this_ptr, FUN_004047f0_arg aStringArg)
{
    FUN_00403970(this_ptr);
    this_ptr->Set(FUN_00559450(aStringArg.s), 0);
    return this_ptr;
}

struct FUN_0040c0e0_arg
{
    const char* s;
};
void __fastcall FUN_00403970(BSStringT<char>*);
// @fnv 0x0040c0e0
BSStringT<char>* __fastcall FUN_0040c0e0(BSStringT<char>* this_ptr, FUN_0040c0e0_arg aCString)
{
    FUN_00403970(this_ptr);
    this_ptr->Set(aCString.s, 0);
    return this_ptr;
}

extern int DAT_011c3438;

// @fnv 0x0040ab50
void FUN_0040ab50()
{
    DAT_011c3438 += 1;
}

struct FUN_0040ab70_shell : public MagicItem
{
    void PreloadModels();
};

void operator delete(void*);
const char* strrchr(const char*, int);

struct FUN_0040b800_shell
{
    void FUN_0040b800(bool);
};

// Preloads the magic item's effect models and, per effect, loads weapon, armor, NPC or creature models and animation files via g_modelLoader.
// @fnv 0x0040ab70
void FUN_0040ab70_shell::PreloadModels()
{
    EffectItemList* pCurrentElementNext;
    EffectSetting* pavEffectSetting = ((MagicItem*)this)->GetEffectSettingForRange(MagicSystem::SELF);

    if (!((MagicItem*)this)->IsLoading())
    {
        ((MagicItem*)this)->Preload(true);
        ((FUN_0040b800_shell*)this)->FUN_0040b800(true);
        return;
    }

    if (pavEffectSetting)
    {
        int icount = 0;
        if (pavEffectSetting->HasNoAssociatedActorValue())
            icount = pavEffectSetting->FUN_004089c0();
        if (pavEffectSetting->GetModelLength() > 0)
        {
            NiPointer<Model> spmodel(0);
            g_modelLoader->FUN_004472a0(pavEffectSetting->GetModelFilePath(), spmodel);
            if (spmodel)
                ((Model*)spmodel)->SetManualRefCount(icount);
        }
    }

    pCurrentElementNext = (MagicItem*)this;
    if (!pCurrentElementNext->IsEmpty())
    {
        while (pCurrentElementNext)
        {
            EffectItem* pitem = pCurrentElementNext->GetItem();
            EffectSetting* pes = pitem->GetEffectSetting();
            TESForm* pform = pes->FUN_005f5f80();
            int icount = 0;
            if (pes->UsesAssociatedActorValue())
                icount = pes->FUN_004087e0();
            if (icount)
            {
                if (pform && pes->FUN_00403e60(0x10000))
                {
                    TESObjectWEAP* pweapon = dynamic_cast<TESObjectWEAP*>(pform);
                    if (pweapon && ((TESModel*)((char*)pweapon + 0x3c))->GetModelLength() > 0)
                    {
                        NiPointer<Model> spmodel(0);
                        g_modelLoader->FUN_004472a0(((TESModel*)((char*)pweapon + 0x3c))->GetModelFilePath(), spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                    }
                }
                else if (pform && pes->FUN_00403e60(0x20000))
                {
                    TESObjectARMO* parmor = dynamic_cast<TESObjectARMO*>(pform);
                    if (parmor)
                    {
                        NiPointer<Model> spmodel(0);
                        g_modelLoader->FUN_004472a0(((TESBipedModelForm*)((char*)parmor + 0x70))->GetBipedModel(0),
                                                    spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                        g_modelLoader->FUN_004472a0(((TESBipedModelForm*)((char*)parmor + 0x70))->GetBipedModel(1),
                                                    spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                    }
                }
                else if (pform && pes->FUN_00403e60(0x40000))
                {
                    TESNPC* pnpc = dynamic_cast<TESNPC*>(pform);
                    if (pnpc)
                    {
                        BSSimpleList<const char*>* modelList = pnpc->GetModelFiles(true, true);
                        BSSimpleList<const char*>* pCurrentElementNext = modelList;
                        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
                        {
                            const char* pfilename = pCurrentElementNext->GetItem();
                            NiPointer<Model> spmodel(0);
                            g_modelLoader->FUN_004472a0(pfilename, spmodel);
                            if (spmodel)
                                ((Model*)spmodel)->SetManualRefCount(icount);
                            pCurrentElementNext = pCurrentElementNext->GetNext();
                        }
                        modelList->RemoveAll();
                        delete modelList;
                    }
                    TESCreature* pcreature = dynamic_cast<TESCreature*>(pform);
                    if (pcreature)
                    {
                        NiPointer<Model> spmodel(0);
                        const char* plastBackSlash;
                        BSSimpleList<const char*>* pfilelist;
                        char* plastSlash;
                        const char* pfilename;
                        g_modelLoader->FUN_004472a0(((TESModel*)((char*)pcreature + 0xdc))->GetModelFilePath(),
                                                    spmodel);
                        if (spmodel)
                        {
                            char path[260];
                            BSSimpleList<const char*>* pcreatureFileList;
                            for (int i = 0; i < icount; i++)
                                ((Model*)spmodel)->FUN_0092c870();
                            pfilename = ((Model*)spmodel)->FUN_00559450();
                            pfilelist = ((TESModelList*)((char*)pcreature + 0x114))->FUN_00717e50();
                            TaskQueueInterface::CopyStringToBuffer(path, 260, pfilename);
                            plastSlash = FUN_0040ab30(path, '\\');
                            pcreatureFileList = pfilelist;
                            while (plastSlash && pcreatureFileList)
                            {
                                plastSlash[1] = 0;
                                const char* pitem = pcreatureFileList->GetItem();
                                if (pitem)
                                {
                                    strcat_s(path, 260, pitem);
                                    NiPointer<Model> spmodel(0);
                                    g_modelLoader->FUN_004472a0(path, spmodel);
                                    if (spmodel)
                                        ((Model*)spmodel)->SetManualRefCount(icount);
                                }
                                pcreatureFileList = pcreatureFileList->GetNext();
                            }
                            plastBackSlash = strrchr(pfilename, '\\');
                            if (plastBackSlash && !_strnicmp(plastBackSlash + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* pkfList =
                                    g_modelLoader->GetModelFileList(pfilename, false, false, 0);
                                {
                                    BSSimpleList<const char*>* pFilenameList = pkfList;
                                    while (pFilenameList)
                                    {
                                        const char* pitem = pFilenameList->GetItem();
                                        if (pitem)
                                        {
                                            for (int i = 0; i < icount; i++)
                                                g_modelLoader->LoadKF(pitem);
                                        }
                                        delete pitem;
                                        pFilenameList = pFilenameList->GetNext();
                                    }
                                }
                                pkfList->RemoveAll();
                                delete pkfList;
                            }
                            if (((TESAnimation*)((char*)pcreature + 0xc4))->HasSpecialAnimations())
                            {
                                plastSlash[1] = 0;
                                strcat_s(path, 260, "SpecialAnims");
                                strcat_s(path, 260, "\\");
                                plastSlash = FUN_0040ab30(path, '\\');
                                BSSimpleList<const char*>* pspecialList =
                                    ((TESAnimation*)((char*)pcreature + 0xc4))->FUN_00717e50();
                                while (pspecialList)
                                {
                                    plastSlash[1] = 0;
                                    const char* pitem = pspecialList->GetItem();
                                    if (pitem)
                                    {
                                        strcat_s(path, 260, pitem);
                                        for (int i = 0; i < icount; i++)
                                            g_modelLoader->LoadKF(path);
                                    }
                                    pspecialList = pspecialList->GetNext();
                                }
                            }
                        }
                    }
                }
            }
            pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
        }
    }
}

extern int DAT_011c3438;

// @fnv 0x0040bed0
void DecrementGlobalCounter()
{
    --DAT_011c3438;
}

struct EffectStatus : EffectSetting
{
    bool IsPositive();
    bool FUN_00408a20();
    bool FUN_00408880();
    bool FUN_004088a0();
};
struct MagicStatus : MagicItem
{
    EffectStatus* FUN_0040a300(int);
    bool IsLoadingOrLoaded();
};
// @fnv 0x0040b580
bool MagicStatus::IsLoadingOrLoaded()
{
    EffectStatus* current = FUN_0040a300(0);
    if (current && current->GetModelLength() > 0 && !current->IsPositive() && !current->FUN_00408a20())
        return false;
    EffectItemList* primary = this;
    if (!primary->IsEmpty())
    {
        while (primary)
        {
            EffectItem* item = primary->GetItem();
            EffectSetting* setting = item ? item->GetEffectSetting() : 0;
            if (setting && setting->IsAssociatedFormUsed() && !((EffectStatus*)setting)->FUN_00408880() &&
                !((EffectStatus*)setting)->FUN_004088a0())
                return false;
            primary = static_cast<EffectItemList*>(primary->GetNext());
        }
    }
    return true;
}

class TESSound
{
  public:
    int Deallocate();
};

struct FUN_0040a1e0_shell : MagicItem
{
    int GetMagicItemFormID();
};

// Casts this MagicItem to MagicItemForm or MagicItemObject and calls TESSound::Deallocate on it, returning 0 if neither cast succeeds.
// @fnv 0x0040a1e0
int FUN_0040a1e0_shell::GetMagicItemFormID()
{
    MagicItemForm* form = dynamic_cast<MagicItemForm*>(static_cast<MagicItem*>(this));
    MagicItemObject* object = dynamic_cast<MagicItemObject*>(static_cast<MagicItem*>(this));
    if (form != 0)
        return reinterpret_cast<TESSound*>(form)->Deallocate();
    else if (object != 0)
        return reinterpret_cast<TESSound*>(object)->Deallocate();
    return 0;
}

struct UnloadEffect : EffectSetting
{
    void StepTowardZero();
    bool IsArchetypeFlagSet();
    void ClampCounterTowardZero();
    bool FUN_00408880();
    bool FUN_004088a0();
};
struct UnloadLoader : ModelLoader
{
    void ReleaseModel(const char*, bool, bool);
    void ReleaseKF(const char*, bool);
};
extern UnloadLoader* DAT_011c3b3c;
int FUN_00406d30(char*, unsigned int, const char*);
struct UnloadMagic : MagicItem
{
    bool IsLoadingOrLoaded();
    bool FUN_0040b6b0();
    UnloadEffect* FUN_0040a300(int);
    void FUN_0040b800(bool);
};
// @fnv 0x0040b800
void UnloadMagic::FUN_0040b800(bool immediate)
{
    if (!IsLoadingOrLoaded())
        return;
    UnloadEffect* primary = FUN_0040a300(0);
    bool queued = false;
    if (FUN_0040b6b0())
        queued = true;
    if (primary && primary->GetModelLength())
    {
        if (!queued)
            DAT_011c3b3c->ReleaseModel(primary->GetModelFilePath(), immediate, true);
        primary->StepTowardZero();
    }
    EffectItemList* effects = this;
    if (!effects->IsEmpty())
    {
        while (effects)
        {
            EffectItem* item = effects->GetItem();
            UnloadEffect* effect = (UnloadEffect*)item->GetEffectSetting();
            if (effect->IsArchetypeFlagSet())
            {
                if (!queued)
                {
                    TESForm* associated = effect->FUN_005f5f80();
                    if (associated && effect->FUN_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(associated);
                        if (weapon && weapon->model.GetModelLength() > 0)
                            DAT_011c3b3c->ReleaseModel(weapon->model.GetModelFilePath(), immediate, true);
                    }
                    else if (associated && effect->FUN_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(associated);
                        if (armor)
                        {
                            DAT_011c3b3c->ReleaseModel(armor->biped.GetBipedModel(0), immediate, true);
                            DAT_011c3b3c->ReleaseModel(armor->biped.GetBipedModel(1), immediate, true);
                        }
                    }
                    else if (associated && effect->FUN_00403e60(0x40000))
                    {
                        TESNPC* npc3 = dynamic_cast<TESNPC*>(associated);
                        if (npc3)
                        {
                            BSSimpleList<const char*>* models71 = npc3->GetModelFiles(true, true);
                            BSSimpleList<const char*>* model15 = models71;
                            while (model15 && !model15->IsEmpty())
                            {
                                const char* path = model15->GetItem();
                                DAT_011c3b3c->ReleaseModel(path, immediate, true);
                                model15 = model15->GetNext();
                            }
                            models71->RemoveAll();
                            delete models71;
                        }
                        TESCreature* creature11 = dynamic_cast<TESCreature*>(associated);
                        if (creature11)
                        {
                            DAT_011c3b3c->ReleaseModel(creature11->model.GetModelFilePath(), immediate, true);
                            const char* modelPath6 = creature11->model.GetModelFilePath();
                            BSSimpleList<const char*>* modelList6 = creature11->modelList.FUN_00717e50();
                            BSSimpleList<const char*>* modelNode29;
                            const char* fileName12;
                            char buffer4[260];
                            FUN_00406d30(buffer4, 260, modelPath6);
                            char* separator10 = FUN_0040ab30(buffer4, '\\');
                            modelNode29 = modelList6;
                            while (separator10 && modelNode29)
                            {
                                separator10[1] = 0;
                                const char* path = modelNode29->GetItem();
                                if (path)
                                {
                                    strcat_s(buffer4, 260, path);
                                    DAT_011c3b3c->ReleaseModel(buffer4, immediate, true);
                                }
                                modelNode29 = modelNode29->GetNext();
                            }
                            fileName12 = strrchr(modelPath6, '\\');
                            if (fileName12 && !_strnicmp(fileName12 + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    DAT_011c3b3c->GetModelFileList(modelPath6, false, false, 0);
                                BSSimpleList<const char*>* file = files;
                                while (file)
                                {
                                    const char* path = file->GetItem();
                                    if (path)
                                        DAT_011c3b3c->ReleaseKF(path, immediate);
                                    delete[] path;
                                    file = file->GetNext();
                                }
                                files->RemoveAll();
                                delete files;
                            }
                            if (creature11->animation.HasSpecialAnimations())
                            {
                                separator10[1] = 0;
                                strcat_s(buffer4, 260, "SpecialAnims");
                                strcat_s(buffer4, 260, "\\");
                                separator10 = FUN_0040ab30(buffer4, '\\');
                                BSSimpleList<const char*>* animation = creature11->animation.FUN_00717e50();
                                while (animation)
                                {
                                    separator10[1] = 0;
                                    const char* path = animation->GetItem();
                                    if (path)
                                    {
                                        strcat_s(buffer4, 260, path);
                                        DAT_011c3b3c->ReleaseKF(buffer4, immediate);
                                    }
                                    animation = animation->GetNext();
                                }
                            }
                        }
                    }
                }
                effect->ClampCounterTowardZero();
                if (!effect->FUN_00408880() && !effect->FUN_004088a0() && effect->FUN_00403e60(0x40000))
                    DecrementGlobalCounter();
            }
            effects = (EffectItemList*)effects->GetNext();
        }
    }
}

struct StringSetting
{
    const char* FUN_00403df0();
};
extern StringSetting DAT_011c34c0;
extern StringSetting DAT_011c348c;
extern StringSetting DAT_011c34a0;
extern StringSetting DAT_011c344c;
extern StringSetting DAT_011c3458;
extern StringSetting DAT_011c34d8;
extern StringSetting DAT_011c3474;
struct FUN_0040c0e0
{
    char* data;
    unsigned short length, capacity;
    FUN_0040c0e0(const char*);
    ~FUN_0040c0e0();
};
typedef struct FUN_0040c0e0 ReturnString;
struct MagicLabel
{
    ReturnString GetNameForType(unsigned int);
};
// Returns a string setting's value chosen by type, falling back to DAT_011c3474 for any other value.
// @fnv 0x0040bef0
ReturnString MagicLabel::GetNameForType(unsigned int type)
{
    switch (type)
    {
    case 1:
        return ReturnString(DAT_011c34c0.FUN_00403df0());
    case 3:
        return ReturnString(DAT_011c348c.FUN_00403df0());
    case 4:
        return ReturnString(DAT_011c34a0.FUN_00403df0());
    case 2:
        return ReturnString(DAT_011c344c.FUN_00403df0());
    case 5:
        return ReturnString(DAT_011c3458.FUN_00403df0());
    case 6:
        return ReturnString(DAT_011c34d8.FUN_00403df0());
    default:
        return ReturnString(DAT_011c3474.FUN_00403df0());
    }
}

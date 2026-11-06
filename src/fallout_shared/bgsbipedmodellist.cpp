// fallout_shared/bgsbipedmodellist.cpp: BGSBipedModelList (8 functions)

#include "bgsbipedmodellist_decls.h"
// Returns the biped model list of a TESForm if it is an NPC or armor, otherwise null.
// @fnv 0x00475020
BGSBipedModelList* BGSBipedModelList::GetBipedModelList(TESForm* form)
{
    BGSBipedModelList* result = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case kNPC: {
            TESNPC* npc = static_cast<TESNPC*>(form);
            result = npc ? &npc->biped : 0;
            break;
        }
        case kArmor: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(form);
            result = armor ? &armor->biped : 0;
            break;
        }
        }
    }
    return result;
}

// Resolves the list form by ID, warns if it is missing or not a BGSListForm, and validates each entry as a biped model.
// @fnv 0x00474da0
void BGSBipedModelList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)list;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        TESForm::RemapFormIDForFile(formID, file);
        list = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formID));
        bool bad;
        if (!list)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning(DAT_0101a5f0, formID, owner->GetName());
                else
                    Warning(DAT_0101a5a0, formID, owner->GetFormID());
            }
            else
                Warning(DAT_0101a558, formID);
        }
        else
        {
            bad = false;
            BSSimpleList<BGSPerkEntry*>* iter = (BSSimpleList<BGSPerkEntry*>*)((BGSCameraPath*)list)->GetConditions();
            TESForm* entry;
            while (iter && !((BSSimpleList<BGSCameraShot*>*)iter)->IsEmpty())
            {
                TESBipedModelForm* model;
                entry = (TESForm*)iter->GetItem();
                model = TESBipedModelForm::GetFormAsBipedModel(entry);
                if (!model)
                {
                    Warning(DAT_0101a4d8, entry->GetName(), entry->GetFormID(), list->GetName(), list->GetFormID(),
                            owner->GetName(), owner->GetFormID());
                    list = 0;
                    break;
                }
                else
                    model->FUN_00480d50(true);
                iter = iter->GetNext();
            }
        }
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct FUN_00474fc0_shell : BGSBipedModelList
{
    bool CompareComponent(BaseFormComponent* apCompareFC);
    BSSimpleList<BGSCameraShot*>* GetNext();
};

extern int DAT_0101a4c4;
void __fastcall FUN_008c6060(void* pThis);

// Initialises the BaseFormComponent at pThis, installs the vtable from DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x00474d10
void* __fastcall FUN_00474d10(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101a4c4;
    FUN_008c6060(pThis);
    return pThis;
}

extern "C" void __cdecl _FUN_00485910(unsigned int, unsigned int);

struct FUN_00474d60_shell
{
    int _pad;
    TESForm* m_pForm;
    void __thiscall FUN_00474d60();
};

// @fnv 0x00474d60
void __thiscall FUN_00474d60_shell::FUN_00474d60()
{
    if (m_pForm)
    {
        unsigned int id = m_pForm->GetFormID();
        _FUN_00485910(0x4c504942, id);
    }
}

void __cdecl _FUN_00485910(unsigned int, unsigned int);
struct FUN_00479350_shell
{
    void FUN_00479350();
};
// @fnv 0x00479350
void FUN_00479350_shell::FUN_00479350()
{
    unsigned int tempint;
    tempint = *(unsigned int*)((char*)this + 4);
    _FUN_00485910(0x50595445, tempint);
}

extern int DAT_0101a4c4;

struct Date
{
    ~Date();
};

struct FUN_00474d40_shell : Date
{
    ~FUN_00474d40_shell();
};

// @fnv 0x00474d40
FUN_00474d40_shell::~FUN_00474d40_shell()
{
    *reinterpret_cast<int**>(this) = &DAT_0101a4c4;
}

// Returns true if apCompareFC is not a BGSBipedModelList or its GetNext differs from this GetNext, otherwise false.
// @fnv 0x00474fc0
bool FUN_00474fc0_shell::CompareComponent(BaseFormComponent* apCompareFC)
{
    BGSBipedModelList* pcomp = dynamic_cast<BGSBipedModelList*>(apCompareFC);
    if (!pcomp)
        return true;
    if (reinterpret_cast<FUN_00474fc0_shell*>(pcomp)->GetNext() != this->GetNext())
        return true;
    return false;
}

struct TESRaceForm
{
    void Initialize(unsigned int);
};

struct FUN_00474f70_shell : BaseFormComponent
{
    void CopyComponent(BaseFormComponent* apCopyFC);
};

// Passes the GetNext() value from apCopyFC to TESRaceForm::Initialize.
// @fnv 0x00474f70
void FUN_00474f70_shell::CopyComponent(BaseFormComponent* apCopyFC)
{
    BGSBipedModelList* pCopyFC = dynamic_cast<BGSBipedModelList*>(apCopyFC);
    if (!pCopyFC)
        return;
    ((TESRaceForm*)this)->Initialize((unsigned int)((BSSimpleList<BGSBipedModelList>*)pCopyFC)->GetNext());
}

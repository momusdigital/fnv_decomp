// fallout_shared/tesimagespacemodifiableform.cpp: TESImageSpaceModifiableForm (5 functions)

#include "tesimagespacemodifiableform_decls.h"

// Resolves the stored form ID to a TESImageSpaceModifier via the owner's file and warns if it cannot be found.
// @fnv 0x00487490
void TESImageSpaceModifiableForm::InitItem(TESForm* owner)
{
    if (m_pImageSpaceModifier)
    {
        unsigned int formID = (unsigned int)m_pImageSpaceModifier;
        if (owner)
            TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
        m_pImageSpaceModifier = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(formID));
        if (!m_pImageSpaceModifier)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object \"%s\".", formID,
                            owner->GetEditorID());
                else
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on unknown owner.", formID);
        }
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent()
    {}
    int __thiscall _ref_00726070();
};
struct FUN_004875c0_shell : BaseFormComponent
{
    bool __thiscall CompareComponent(BaseFormComponent* apCompareFC);
};

extern int DAT_0101cbd8;
void __fastcall FUN_008c6060(void* pThis);

// Initialises the BaseFormComponent base, installs the vtable from DAT_0101cbd8, calls FUN_008c6060, and returns pThis.
// @fnv 0x00487420
void* __fastcall FUN_00487420(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101cbd8;
    FUN_008c6060(pThis);
    return pThis;
}

extern "C" void FUN_00485910(unsigned int, unsigned int);

struct FUN_00487450_shell
{
    int m_auiShapeKeys;
    TESForm* m_field_4;
    void Save();
};

// @fnv 0x00487450
void FUN_00487450_shell::Save()
{
    if (m_field_4)
    {
        unsigned int id = m_field_4->GetFormID();
        FUN_00485910(0x4D414E4D, id);
    }
}

extern int DAT_01186ae8;
extern int DAT_01183040;
extern "C" void* FUN_00ec43fb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

class SpawnedHelper
{
  public:
    void* Get();
};

class FUN_00487570_cls
{
  public:
    void CopyComponent(unsigned int a1);
    void Apply(void* p);
};

// @fnv 0x00487570
void FUN_00487570_cls::CopyComponent(unsigned int a1)
{
    SpawnedHelper* pHelper =
        (SpawnedHelper*)FUN_00ec43fb(a1, 0, (unsigned int)&DAT_01183040, (unsigned int)&DAT_01186ae8, 0);
    if (pHelper == 0)
    {
    }
    else
    {
        this->Apply(pHelper->Get());
    }
}

// Returns true if the cast fails or the two calls to _ref_00726070() return different values.
// @fnv 0x004875c0
bool __thiscall FUN_004875c0_shell::CompareComponent(BaseFormComponent* apCompareFC)
{
    TESImageSpaceModifiableForm* pCompareImageSpaceForm = dynamic_cast<TESImageSpaceModifiableForm*>(apCompareFC);
    if (!pCompareImageSpaceForm)
        return true;
    if (this->_ref_00726070() != reinterpret_cast<BaseFormComponent*>(pCompareImageSpaceForm)->_ref_00726070())
        return true;
    return false;
}

// fallout_shared/bgsrepairitemlist.cpp: BGSRepairItemList, MyHolder, RepairListComparison (6 functions)

#include "bgsrepairitemlist_decls.h"

// Resolves pRepairItemList's form ID to a BGSListForm and warns if the lookup fails, naming the owner when available.
// @fnv 0x0047b8e0
void BGSRepairItemList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pRepairItemList;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        TESForm::RemapFormIDForFile(formID, file);
        pRepairItemList = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formID));
        if (!pRepairItemList)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object \"%s\".", formID,
                            owner->GetEditorID());
                else
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find repair item list (%08X) for unknown owner.", formID);
        }
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent()
    {}
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct Unnamed07
{
    unsigned int _ref_00726070();
};
struct MyHolder
{
    void CopyFrom(BaseFormComponent* apCopyFC);
};

extern int DAT_0101a4c4;
void __fastcall FUN_008c6060(void* pThis);

// @fnv 0x0047b850
void* __fastcall FUN_0047b850(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101a4c4;
    FUN_008c6060(pThis);
    return pThis;
}

namespace fnv_0047b880 {
extern int DAT_0101a4c4;
struct TESFile
{
    void InitializeComponent(void);
};
struct FUN_0047b880
{
    virtual ~FUN_0047b880();
};
// @fnv 0x0047b880
FUN_0047b880::~FUN_0047b880()
{
    reinterpret_cast<TESFile*>(this)->InitializeComponent();
}
}  // namespace fnv_0047b880

void __cdecl FUN_00485910(unsigned int, unsigned int);
struct S0047b8a0
{
    int _00;
    TESForm* _04;
    void FUN_0047b8a0();
};
// @fnv 0x0047b8a0
void S0047b8a0::FUN_0047b8a0()
{
    unsigned int formID;
    if (_04 != 0)
    {
        formID = _04->GetFormID();
        FUN_00485910(0x4C504552, formID);
    }
}

// If apCopyFC is a BGSRepairItemList, passes its accessor's result to this object's TESRaceForm::Initialize.
// @fnv 0x0047b9d0
void MyHolder::CopyFrom(BaseFormComponent* apCopyFC)
{
    BGSRepairItemList* pcopy = dynamic_cast<BGSRepairItemList*>(apCopyFC);
    if (!pcopy)
        return;
    ((TESRaceForm*)this)->Initialize(((Unnamed07*)pcopy)->_ref_00726070());
}

struct RepairListComparison : BGSRepairItemList
{
    bool CompareComponent(BaseFormComponent* component);
};

// Returns true if the component is not a BGSRepairItemList or if its _ref_00726070 differs from this list's _ref_00726070.
// @fnv 0x0047ba20
bool RepairListComparison::CompareComponent(BaseFormComponent* component)
{
    BGSRepairItemList* other = dynamic_cast<BGSRepairItemList*>(component);
    if (!other)
        return true;
    if (reinterpret_cast<Unnamed07*>(other)->_ref_00726070() != reinterpret_cast<Unnamed07*>(this)->_ref_00726070())
        return true;
    return false;
}

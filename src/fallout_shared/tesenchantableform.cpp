// fallout_shared/tesenchantableform.cpp: TESEnchantableForm (7 functions)

#include "tesenchantableform_amount.h"
#include "tesenchantableform_decls.h"

// @fnv 0x004830a0
TESEnchantableForm::TESEnchantableForm()
{
    InitializeComponent();
}

// Resolves the form's enchantment by form ID, warns when it is missing or has an invalid effect trigger, and clears it on failure.
// @fnv 0x00483210
void TESEnchantableForm::InitItem(TESForm* owner)
{
    if (m_pEnchantment)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pEnchantment);
        if (owner)
            TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));

        m_pEnchantment = dynamic_cast<EnchantmentItem*>(GetFormByID(formID));
        if (!m_pEnchantment)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find enchanting (%08X) on unknown owner.", formID);
        }

        if (m_pEnchantment && owner && !m_pEnchantment->FUN_004094f0(owner))
        {
            Warning(
                "MASTERFILE: Enchanting (%08X) '%s' has invalid effect trigger type or effect for object (%08X) '%s'.",
                m_pEnchantment->GetFormID(), m_pEnchantment->GetName(), owner->GetFormID(), owner->GetName());
            m_pEnchantment = 0;
        }
    }
}

// @fnv 0x00483170
void TESEnchantableForm::SetFormEnchantmentAmount(unsigned short amount)
{
    m_usEnchantmentAmount = amount;
}

void __cdecl FUN_00485910(unsigned int a, unsigned int b);
void __cdecl FUN_00485950(unsigned int a, unsigned int b);

struct FUN_0047bd70_shell
{
    void* vtable;
    TESForm* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    void FUN_0047bd70();
};

// @fnv 0x0047bd70
void FUN_0047bd70_shell::FUN_0047bd70()
{
    unsigned int tempint;
    if (m_pEnchantment != 0)
    {
        tempint = m_pEnchantment->GetFormID();
        FUN_00485910(0x4d544945, tempint);
    }
    if (m_usEnchantmentAmount != 0)
    {
        FUN_00485950(0x544d4145, m_usEnchantmentAmount);
    }
}

struct ExplosionEffectSettings;
struct BGSImpactData;
struct BGSImpactDataSet;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct QueuedFile;
struct TESBoundObject;
struct TESImageSpaceModifier;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct FileEntryList;
struct TESWaterForm;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct BGSPreloadable : public BaseFormComponent
{
    virtual void QueueResourceLoad(int, QueuedFile*);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BGSPreloadable[sizeof(BGSPreloadable) == 4 ? 1 : -1];
struct TESImageSpaceModifiableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESImageSpaceModifier* GetFormImageSpaceModifying();
    void SetFormImageSpaceModifying(TESImageSpaceModifier*);
    TESImageSpaceModifier* m_pImageSpaceModifier;
};
typedef char _sizecheck_TESImageSpaceModifiableForm[sizeof(TESImageSpaceModifiableForm) == 8 ? 1 : -1];
struct FUN_004830d0_shell : public TESEnchantableForm
{
    void InitializeDataComponent();
};

// Clears the enchantment form's fields, setting the casting type to 4 and zeroing the other two members.
// @fnv 0x004830d0
void FUN_004830d0_shell::InitializeDataComponent()
{
    m_pEnchantment = 0;
    m_usEnchantmentAmount = 0;
    m_eCastingType = (MagicSystemCastingType)4;
}

struct TESActorBaseData
{
    unsigned short GetFatigue() const;
};

struct TESFormList
{
    void* GetFirst();
};

struct FUN_00483190_shell : public TESEnchantableForm
{
    bool CompareComponent(BaseFormComponent* component);
};

// Compares the enchantable form against component by first entry and fatigue, returning true when they differ or the cast fails.
// @fnv 0x00483190
bool FUN_00483190_shell::CompareComponent(BaseFormComponent* component)
{
    TESEnchantableForm* other = dynamic_cast<TESEnchantableForm*>(component);
    if (!other)
        return true;
    if (reinterpret_cast<TESFormList*>(this)->GetFirst() != reinterpret_cast<TESFormList*>(other)->GetFirst())
        return true;
    if (reinterpret_cast<TESActorBaseData*>(this)->GetFatigue() !=
        reinterpret_cast<TESActorBaseData*>(other)->GetFatigue())
        return true;
    return false;
}

struct Enchantable_483100 : public TESEnchantableForm
{
    virtual int GetCastingType4();
    EnchantmentItem* GetFormEnchantment();
    unsigned short GetFormEnchantmentAmount();
    void SetFormEnchantment(EnchantmentItem*);
    void SetCastingType(int);
    void CopyEnchantmentFrom(BaseFormComponent* apComponent);
};

// Casts apComponent to TESEnchantableForm and copies its enchantment, enchantment amount and casting type onto this form.
// @fnv 0x00483100
void Enchantable_483100::CopyEnchantmentFrom(BaseFormComponent* apComponent)
{
    TESEnchantableForm* pForm = dynamic_cast<TESEnchantableForm*>(apComponent);
    if (!pForm)
        return;
    SetFormEnchantment(((Enchantable_483100*)pForm)->GetFormEnchantment());
    SetFormEnchantmentAmount(((Enchantable_483100*)pForm)->GetFormEnchantmentAmount());
    SetCastingType(((Enchantable_483100*)pForm)->GetCastingType4());
}

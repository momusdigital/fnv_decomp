// fallout_shared/tesattackdamageform.cpp: TESAttackDamageForm, TESCreature (6 functions)

#include "tesattackdamageform_creature_decls.h"

// @fnv 0x0047fdc0
TESAttackDamageForm::TESAttackDamageForm()
{
    InitializeComponent();
}

// @fnv 0x0047fdf0
TESAttackDamageForm::~TESAttackDamageForm()
{
    Free();
}

// @fnv 0x0047ff30
unsigned short TESAttackDamageForm::GetAttackDamage()
{
    return m_usAttackDamage;
}

// The covered address is a secondary-base override on TESCreature. The old
// Several tiny accessors were folded with unrelated canonical methods. Their
// actorData so the calls retain the original non-null subobject adjustment.
// Copies template data from selectedForm or the current template into this creature according to the template use flags, then marks the template as copied.
// @fnv 0x005fb450
void TESCreature::CopyFromTemplateForm(TESActorBase* selectedForm)
{
    if (!reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))
             ->GetCurrentMoveModeType() &&
        !selectedForm)
        return;

    struct TemplateSelection
    {
        unsigned short useFlags;
        TESForm* leveled;
        TESCreature* creature;
    } templateSelection;
    {
        TESCreature defaultCreature;
        defaultCreature.TESCreature::SetCombatStyle(GetDefaultCombatStyle());
        templateSelection.creature = 0;
        if (!IsTemplateLeveled())
            templateSelection.creature =
                (TESCreature*)reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&actorData) -
                                                            offsetof(TESActorBaseData, actorData))
                    ->GetCurrentMoveModeType();
        if (selectedForm && selectedForm->GetFormType() == ENUM_FORM_ID_CREA_ID)
            templateSelection.creature = (TESCreature*)selectedForm;
        if (!templateSelection.creature)
            templateSelection.creature = &defaultCreature;
        else if (reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                               offsetof(TESActorBaseData, actorData))
                     ->GetCurrentMoveModeType() &&
                 !templateSelection.creature->QCopiedTemplate())
            templateSelection.creature->CopyFromTemplateForm(0);

        if (GetTemplateUseFlag(USE_SCRIPT))
            TESScriptableForm::BaseFormRecord((TESScriptableForm*)templateSelection.creature);
        if (GetTemplateUseFlag(USE_INVENTORY))
            TESContainer::BaseFormRecord((TESContainer*)templateSelection.creature);
        if (GetTemplateUseFlag(USE_BASE_DATA))
        {
            TESFullName::BaseFormRecord((TESFullName*)templateSelection.creature);
            struct BaseDataFlags
            {
                int inherited;
                int current;
            } flags;
            flags.current = reinterpret_cast<ActorBaseAttributes*>(
                                reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&actorData) -
                                                                   offsetof(TESActorBaseData, actorData))
                                    ->GetConditions())
                                ->m_uiActorFlags;
            flags.current &= ~0x1070220a;
            flags.inherited =
                reinterpret_cast<ActorBaseAttributes*>(
                    reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                                       offsetof(TESActorBaseData, actorData))
                        ->GetConditions())
                    ->m_uiActorFlags;
            flags.inherited &= 0x1070220a;
            SetFlags(flags.inherited | flags.current);
        }
        if (GetTemplateUseFlag(USE_MODEL))
        {
            TESModel::BaseFormRecord((TESModel*)templateSelection.creature);
            TESModelList::BaseFormRecord((TESModelList*)templateSelection.creature);
            TESAnimation::BaseFormRecord((TESAnimation*)templateSelection.creature);
            SetBodyPartData(templateSelection.creature->GetBodyPartData());
            CopyBoundData(templateSelection.creature);
            SetImpactDataSet(templateSelection.creature->GetImpactDataSet());
            SetBloodImpactMaterial(templateSelection.creature->GetBloodImpactMaterial());
            BGSDestructibleObjectForm::BaseFormRecord((BGSDestructibleObjectForm*)templateSelection.creature);
            struct ModelFlags
            {
                int inherited;
                int mask;
                int current;
            } flags;
            flags.current = reinterpret_cast<ActorBaseAttributes*>(
                                reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&actorData) -
                                                                   offsetof(TESActorBaseData, actorData))
                                    ->GetConditions())
                                ->m_uiActorFlags;
            flags.mask = 0x4b8f8071;
            flags.current &= ~flags.mask;
            flags.inherited =
                reinterpret_cast<ActorBaseAttributes*>(
                    reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                                       offsetof(TESActorBaseData, actorData))
                        ->GetConditions())
                    ->m_uiActorFlags;
            flags.inherited &= flags.mask;
            SetFlags(flags.inherited | flags.current);
            if (templateSelection.creature->GetCreatureSounds())
            {
                CreatureSoundCollection* sounds = GetMutableCreatureSounds();
                sounds->Copy(templateSelection.creature->GetCreatureSounds());
            }
            else
            {
                SetCreatureSoundsFrom(templateSelection.creature->GetSoundCreature());
            }
            m_eSoundLevel = templateSelection.creature->FUN_009c0070();
        }
        if (!m_pCreatureSounds)
        {
            if (templateSelection.creature->GetCreatureSounds())
            {
                CreatureSoundCollection* sounds = GetMutableCreatureSounds();
                sounds->Copy(templateSelection.creature->GetCreatureSounds());
            }
            else
            {
                SetCreatureSoundsFrom(templateSelection.creature->GetSoundCreature());
            }
        }
        if (GetTemplateUseFlag(USE_TRAITS))
        {
            // Folded death-item getter followed by its setter.
            FUN_0050f9a0((TESLevItem*)reinterpret_cast<NiTimeController*>(
                             reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                             offsetof(TESActorBaseData, actorData))
                             ->FUN_00441110());
            reinterpret_cast<TESResponse*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))
                ->SetSpeakerIdle((TESIdleForm*)templateSelection.creature->GetVoiceType());
            SetKarmaValue(templateSelection.creature->GetHealthRegeneration());
            FUN_005fbdb0(templateSelection.creature->FUN_0059f3a0());
            FUN_005f8bd0(templateSelection.creature->GetField158());
            SetCombatStyle(templateSelection.creature->GetCombatStyle());
        }
        if (GetTemplateUseFlag(USE_STATS))
        {
            SetLevel(templateSelection.creature->GetLevel());
            SetMatchesPCLevel(templateSelection.creature->GetMatchesPCLevel());
            SetCalcLevelMin(templateSelection.creature->FUN_0047d390());
            SetCalcLevelMax(templateSelection.creature->FUN_0047d3b0());
            TESAttributes::BaseFormRecord((TESAttributes*)templateSelection.creature);
            TESHealthForm::BaseFormRecord((TESHealthForm*)templateSelection.creature);
            TESAttackDamageForm::BaseFormRecord((TESAttackDamageForm*)templateSelection.creature);
            SetSpeedMult(templateSelection.creature->GetShortAtOffset12());
            SetFatigue(templateSelection.creature->GetFatigue());
            SetByteAt12D(templateSelection.creature->GetCombatSkill());
            SetCreatureType(templateSelection.creature->FUN_005f9ad0());
            FUN_00507780(templateSelection.creature->FUN_00821640());
            SetBoltGrowWidth(templateSelection.creature->FUN_00567470());
            SetBoltSmallWidth(templateSelection.creature->FUN_00821660());
        }
        if (GetTemplateUseFlag(USE_FACTIONS))
            CopyFactionList((TESActorBaseData*)templateSelection.creature);
        if (GetTemplateUseFlag(USE_SPELLS))
        {
            TESSpellList::BaseFormRecord((TESSpellList*)templateSelection.creature);
            BGSTouchSpellForm::BaseFormRecord((BGSTouchSpellForm*)templateSelection.creature);
        }
        if (GetTemplateUseFlag(USE_AI_DATA))
            CopyAISettings((TESAIForm*)templateSelection.creature);
        if (GetTemplateUseFlag(USE_AI_PACKAGES))
            CopyAIPackageList((TESAIForm*)templateSelection.creature);

        templateSelection.useFlags = 0;
        templateSelection.leveled = GetLeveledTemplateInHierarchy(this, templateSelection.useFlags);
        if (templateSelection.leveled)
        {
            reinterpret_cast<TESResponse*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))
                ->GetListenerIdle((TESIdleForm*)templateSelection.leveled);
            SetTemplateUseFlags(templateSelection.useFlags);
        }
        SetCopiedTemplate(true);
    }
}

struct FUN_0047fe10_shell : public TESAttackDamageForm
{
    void InitializeDataComponent();
};

// @fnv 0x0047fe10
void FUN_0047fe10_shell::InitializeDataComponent()
{
    m_usAttackDamage = 0;
}

void __cdecl _Deallocate(void*);
struct Unk_57
{
    void FUN_0057ee10();
    void* FUN_0057ede0(unsigned int);
};
// Calls FUN_0057ee10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0057ede0
void* Unk_57::FUN_0057ede0(unsigned int flags)
{
    FUN_0057ee10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// fallout/magic/concussioneffect.cpp: ConcussionEffect (7 functions)

#include "concussioneffect_decls.h"

const char kConcussionFXCrippleHead[] = "FXCrippleHead";

// @fnv 0x0080bd60
bool ConcussionEffect::IsEffectValid(MagicTarget* target)
{
    Actor* actor = target ? target->GetOwnerActor() : 0;
    if (actor)
    {
        if (!actor->HasHealth(false) && !actor->vfn_2e8())
            return true;
    }
    return false;
}

// @fnv 0x0080bdd0
void ConcussionEffect::Update(float deltaTime)
{
    ((MagicProjectile*)this)->Process(deltaTime);
    m_fPackageValue += deltaTime;
    Actor* actor = ((ActorMover*)this)->GetCurrentMoveModeType()
                       ? ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetOwnerActor()
                       : 0;
    if (actor)
        ApplyConcussion(actor);
}

// @fnv 0x0080bcb0
ActiveEffect* ConcussionEffect::Copy()
{
    ConcussionEffect* copy = new ConcussionEffect(m_pEffectInstance, pSpell, pEffect);
    copy->m_fPackageValue = m_fPackageValue;
    CopyFrom(copy);
    return copy;
}

// @fnv 0x0080be40
void ConcussionEffect::ApplyConcussion(Actor* actor)
{
    if (m_fPackageValue > DAT_011d1ba4.Float()->value)
    {
        m_fPackageValue = 0.0f;
        if (actor->FUN_008be870() == 0.0)
        {
            if (!actor->second.vfn_8(0x48))
            {
                DAT_011dbe50 = true;
                if (actor->IsPlayerRef() && !g_thePlayer->IsSleepingOrResting())
                {
                    ImageSpaceModifierInstanceForm::Trigger(TESImageSpaceModifier::GetConcussionModifier(),
                                                            DAT_011cf834.Float()->value, 0);
                    ((BSAudio*)FUN_00453a70())->GetSoundHandleByEditorID(kConcussionFXCrippleHead, 0x101).Play(false);
                }
                actor->GetProcess()->vfn_44(actor, 0, 2, 1, 0, 1);
                DAT_011dbe50 = false;
            }
        }
    }
}

extern int DAT_01079bdc;
struct FUN_0080bc70_base
{
    FUN_0080bc70_base(MagicCaster*, MagicItem*, EffectItem*);
    char pad[0x48];
};
struct FUN_0080bc70_cls : public FUN_0080bc70_base
{
    float f;
    FUN_0080bc70_cls(MagicCaster* c, MagicItem* s, EffectItem* e);
};
// Initializes the base with the caster, magic item and effect item, sets the vtable pointer and zeroes the float member f.
// @fnv 0x0080bc70
FUN_0080bc70_cls::FUN_0080bc70_cls(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
    : FUN_0080bc70_base(apCaster, apMagicItem, apEffectItem)
{
    *(int**)this = &DAT_01079bdc;
    f = 0.0f;
}

struct TESForm
{
    virtual ~TESForm();
};

TESForm* __cdecl GetFormByID(unsigned int);
extern unsigned char DAT_0118abb1;
extern TESImageSpaceModifier* DAT_011c9704;

// @fnv 0x0080bfa0
TESImageSpaceModifier* __cdecl GetConcussion()
{
    if (!DAT_0118abb1)
        return 0;
    if (!DAT_011c9704)
        DAT_011c9704 = dynamic_cast<TESImageSpaceModifier*>(GetFormByID(0x164));
    return DAT_011c9704;
}

struct FUN_0052d240_shell
{
    void FUN_00483710();
    void FUN_0052d240();
};
// @fnv 0x0052d240
void FUN_0052d240_shell::FUN_0052d240()
{
    FUN_00483710();
}

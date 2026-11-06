
// src/fallout/ai/middlelowprocess_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0092cab0: the skeleton of src/fallout/ai/middlelowprocess.cpp
// with declarations corrected to what the original code does (LowProcess.h: LowProcess += void FUN_0092cab0(Actor* source);; Actor.h: virtual void Unk_10D(void); -> virtual void Unk_10D(int a);; Actor.h: Actor += void EndInterruptPackage(bool a);). Move the function to its real unit once
// that unit declares it this way.

#include "../../../include/layout_support.h"
#include "../../../include/Actor_decl_middlelowprocess.h"
#include "MiddleLowProcess_decl_middlelowprocess.h"

template <class Collection> class SettingT
{
  public:
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting236;
// @fnv 0x0092cab0
void LowProcess::FUN_0092cab0(Actor* source)
{
    int iterations = (int)(*originalRuntimeFloatSetting236.Float() * 2);
    Actor* actor = 0;
    actor = dynamic_cast<Actor*>(pTarget);
    bool bUpdated = false;
    if (!pTarget || actor->GetDisabled() || actor->GetDeleted() || actor->Unk_8B(false))
    {
        source->Unk_10D(0);
        source->EndInterruptPackage(false);
    }
    else if (actor && actor->GetProcess() && actor->GetProcess()->GetProcessLevel() == 2)
    {
        while (iterations)
        {
            if (source->Unk_8B(false))
                break;
            source->Unk_10E();
            actor = dynamic_cast<Actor*>(pTarget);
            if (actor && !actor->Unk_8B(false) && actor->GetProcess()->GetProcessLevel() == 2)
            {
                actor->Unk_10E();
                bUpdated = true;
            }
            iterations--;
        }
        if (bUpdated && actor)
        {
            actor->GetProcess()->ResetPackageState();
            bUpdated = false;
        }
    }
    else
    {
        UpdateActorPackage(source, true, 0x101, false);
    }
}


// src/fallout_shared/tescreature_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005f9b90: the skeleton of src/fallout_shared/tescreature_rtti_variant.cpp
// with declarations corrected to what the original code does (tescreature_decls_rtti_variant.h: BGSBodyPartData* GetBodyPartData(); -> ; tescreature_decls_rtti_variant.h: TESCreature += virtual void C01(); virtual void C02(); virtual void C03(); virtual void C04(); virtual void C05(); virtual void C06(); virtual void C07(); virtual void C08(); virtual void C09). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tescreature_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm). The skeleton of src/fallout_shared/tescreature.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "tescreature_decls_rtti_variant_decl_tescreature_rtti_variant.h"

#include <string.h>
// @fnv 0x005f9b90
bool TESCreature::Compare(TESForm* otherForm)
{
    TESCreature* other = dynamic_cast<TESCreature*>(otherForm);
    if (!other)
        return true;
    if (FUN_00485270(other))
        return true;
    if (memcmp(&dataPadding, other->GetOffset12C(), 4))
        return true;
    if (FUN_005f9ad0() != other->FUN_005f9ad0())
        return true;
    if (FUN_00821640() != other->FUN_00821640())
        return true;
    if (FUN_00567470() != other->FUN_00567470())
        return true;
    if (FUN_00821660() != other->FUN_00821660())
        return true;
    if (GetBloodImpactMaterial() != other->GetBloodImpactMaterial())
        return true;
    if (GetCombatStyle() != other->GetCombatStyle())
        return true;
    if (GetBodyPartData() != other->GetBodyPartData())
        return true;
    if (FUN_009c0070() != other->FUN_009c0070())
        return true;
    if (FUN_00461580(0x100))
    {
        CreatureSoundCollection* sounds = GetCreatureSounds();
        CreatureSoundCollection* otherSounds5 = other->GetCreatureSounds();
        if (sounds)
        {
            if (!otherSounds5)
                return true;
            if (sounds->IsDifferentFrom(otherSounds5))
                return true;
        }
        else if (otherSounds5)
            return true;
    }
    else
    {
        if (GetSoundCreature() != other->GetSoundCreature())
            return true;
    }
    if (GetImpactDataSet() != other->GetImpactDataSet())
        return true;
    if (GetField158() != other->GetField158())
        return true;
    return false;
}

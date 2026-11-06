// fallout_shared/combatformulas.cpp: CombatDamageCalculator, NiCamera (52 functions)

#include "combatformulas_support.h"
class TESObjectWEAP;
class TESAmmo;
class TESAmmoEffect;
#include "combatformulas_camera.h"
#include "combatformulas_dependencies.h"

// @fnv 0x004be0b0
float InventoryStackRecord::GetArmorDamageThreshold(Actor* actor)
{
    float fArmorProtectionValue = -1.0f;
    TESObjectARMO* pArmorForm;
    struct ArmorCondition
    {
        float baseHealth;
        float fraction;
    } condition;
    if (reinterpret_cast<TESForm*>(m_pItemObject)->GetFormType() == 24)
    {
        pArmorForm = reinterpret_cast<TESObjectARMO*>(m_pItemObject);
        condition.baseHealth = TESHealthForm::GetBaseHealth(pArmorForm);
        condition.fraction = condition.baseHealth == 0.0 ? 0.0 : GetConditionPercent(false) / condition.baseHealth;
        fArmorProtectionValue = CombatDamageCalculator::CalculateArmorDamageThreshold(
            (unsigned short)pArmorForm->GetDamageThreshold(), condition.fraction);
    }
    return InventoryStackRecord::GetConditionPercent(fArmorProtectionValue);
}

// @fnv 0x006447f0
float NiCamera::GetMaxFarNearRatio() const
{
    return m_fMaxFarNearRatio;
}

// @fnv 0x00645380
float CombatDamageCalculator::CalculateWeaponDamage(ActorValueOwner* owner, TESObjectWEAP* weapon, float health,
                                                    bool abApplyPerks, InventoryStackRecord* item, bool includeReload,
                                                    bool noJams, int skill, float critChance, float critMult,
                                                    bool sneakAttack, bool specialAttack, TESAmmo* ammoOverride)
{
    if (health <= 0.0)
        return 0.0f;
    // Nested scopes preserve the original MSVC9 stack-local allocation order.
    {
        bool bIsCreature;
        {
            Actor* pActor;
            {
                float fWeaponDamageMultiplier;
                {
                    float fConditionDamageMult;
                    {
                        bool bHasExtendedClip;
                        {
                            int iCondition;
                            {
                                int iClipRounds;
                                {
                                    float m_fClusterOffsetX;
                                    {
                                        bool bHasFireRateMod;
                                        {
                                            float fModBonusDamage;
                                            {
                                                float m_fNextProcedureCheckHour;
                                                {
                                                    float afDamageAmount;
                                                    {
                                                        float fClipDamage;
                                                        {
                                                            float fCritChance;
                                                            {
                                                                bool bHasSplitBeam;
                                                                {
                                                                    float fCritDamage;
                                                                    {
                                                                        float fWeaponDamage;
                                                                        m_fClusterOffsetX = 0.0f;
                                                                        iClipRounds = 1;
                                                                        afDamageAmount = 0.0f;
                                                                        fCritChance = 0.0f;
                                                                        m_fNextProcedureCheckHour = 3.402823466e38f;
                                                                        bIsCreature = false;
                                                                        fWeaponDamage = health;
                                                                        bHasExtendedClip = false;
                                                                        bHasFireRateMod = false;
                                                                        fWeaponDamageMultiplier =
                                                                            weapon ? weapon->GetField14C() : 1.0f;
                                                                        bHasSplitBeam = false;
                                                                        iCondition =
                                                                            (int)InventoryStackRecord::RoundToNearestStep(
                                                                                (float)(fWeaponDamage * 10.0), 1.0f);
                                                                        fModBonusDamage = 0.0f;
                                                                        if (reinterpret_cast<void*>(ammoOverride) ==
                                                                            weapon)
                                                                            ammoOverride = 0;
                                                                        pActor = static_cast<Actor*>(owner);
                                                                        bIsCreature = pActor->Unk_87();
                                                                        if (item)
                                                                        {
                                                                            item->SetEquipmentState(1, fModBonusDamage);
                                                                            bHasExtendedClip =
                                                                                item->SetEquipmentState(2);
                                                                            bHasFireRateMod =
                                                                                item->SetEquipmentState(8);
                                                                            fWeaponDamageMultiplier =
                                                                                CalculateWeaponDamageForActor(
                                                                                    pActor, weapon, false, item);
                                                                            bHasSplitBeam = item->SetEquipmentState(12);
                                                                        }
                                                                        if (weapon)
                                                                        {
                                                                            afDamageAmount = DAT_011ce2c0.Float()->f *
                                                                                             weapon->GetAttackDamage();
                                                                            afDamageAmount += fModBonusDamage;
                                                                            if (bHasSplitBeam)
                                                                                afDamageAmount *= 1.3;
                                                                            TESAmmo* pAmmo =
                                                                                ammoOverride
                                                                                    ? ammoOverride
                                                                                    : weapon->GetCurrentAmmo(0);
                                                                            BSSimpleList<TESAmmoEffect*>* pAmmoEffects =
                                                                                pAmmo
                                                                                    ? reinterpret_cast<BSSimpleList<
                                                                                          TESAmmoEffect*>*>(
                                                                                          reinterpret_cast<
                                                                                              TESAmmoInitCalls*>(pAmmo)
                                                                                              ->FUN_00923000())
                                                                                    : 0;
                                                                            {
                                                                                bool bIsNPC;
                                                                                {
                                                                                    float fCritChanceOverride;
                                                                                    afDamageAmount =
                                                                                        TESAmmoEffect::ApplyAmmoEffects(
                                                                                            AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM,
                                                                                            pAmmoEffects,
                                                                                            afDamageAmount);
                                                                                    if (weapon->GetProjectileData(0) &&
                                                                                        reinterpret_cast<
                                                                                            EffectSetting*>(
                                                                                            weapon->GetProjectileData(
                                                                                                0))
                                                                                            ->GetBoltSound())
                                                                                        afDamageAmount +=
                                                                                            reinterpret_cast<
                                                                                                PathingRequest*>(
                                                                                                reinterpret_cast<
                                                                                                    EffectSetting*>(
                                                                                                    weapon
                                                                                                        ->GetProjectileData(
                                                                                                            0))
                                                                                                    ->GetBoltSound())
                                                                                                ->GetTargetRadius() *
                                                                                            weapon->GetDamageForActor(
                                                                                                bHasSplitBeam, false,
                                                                                                pActor);
                                                                                    switch (weapon->FUN_00446390())
                                                                                    {
                                                                                    case 1:
                                                                                    case 2:
                                                                                    case 13:
                                                                                        break;
                                                                                    case 10:
                                                                                    case 11:
                                                                                        if (weapon->GetProjectileData(
                                                                                                0) &&
                                                                                            reinterpret_cast<
                                                                                                EffectSetting*>(
                                                                                                weapon
                                                                                                    ->GetProjectileData(
                                                                                                        0))
                                                                                                ->GetBoltSound())
                                                                                            afDamageAmount =
                                                                                                DAT_011ce2c0.Float()
                                                                                                    ->f *
                                                                                                reinterpret_cast<
                                                                                                    PathingRequest*>(
                                                                                                    reinterpret_cast<
                                                                                                        EffectSetting*>(
                                                                                                        weapon
                                                                                                            ->GetProjectileData(
                                                                                                                0))
                                                                                                        ->GetBoltSound())
                                                                                                    ->GetTargetRadius();
                                                                                        fWeaponDamage = 1.0f;
                                                                                        iCondition = 10;
                                                                                        break;
                                                                                    case -1:
                                                                                    case 0:
                                                                                        break;
                                                                                    default:
                                                                                        iClipRounds =
                                                                                            weapon->GetClipRounds(
                                                                                                bHasExtendedClip);
                                                                                        break;
                                                                                    }
                                                                                    if (skill == -1)
                                                                                        afDamageAmount *=
                                                                                            DAT_011cece8.Float()->f +
                                                                                            DAT_011cf350.Float()->f *
                                                                                                (owner
                                                                                                     ? owner->GetActorValueFloatByIndex(
                                                                                                           reinterpret_cast<
                                                                                                               MiddleHighProcess*>(
                                                                                                               weapon)
                                                                                                               ->GetWeaponForm()) /
                                                                                                           100.0f
                                                                                                     : 1.0f);
                                                                                    else
                                                                                    {
                                                                                        float fSkill = skill / 100.0;
                                                                                        afDamageAmount *=
                                                                                            DAT_011cece8.Float()->f +
                                                                                            DAT_011cf350.Float()->f *
                                                                                                fSkill;
                                                                                    }
                                                                                    if (abApplyPerks)
                                                                                        ApplyPerkModifiers(
                                                                                            0, pActor,
                                                                                            (weapon
                                                                                                 ? static_cast<
                                                                                                       TESForm*>(weapon)
                                                                                                 : 0),
                                                                                            pActor, &afDamageAmount);
                                                                                    m_fNextProcedureCheckHour =
                                                                                        fWeaponDamageMultiplier;
                                                                                    if (weapon->FUN_00446390() != 10 &&
                                                                                        weapon->FUN_00446390() != 11 &&
                                                                                        weapon->FUN_00446390() != 13)
                                                                                    {
                                                                                        if (noJams)
                                                                                            m_fNextProcedureCheckHour +=
                                                                                                iClipRounds *
                                                                                                GetWeaponConditionDamageMultiplier(
                                                                                                    0) *
                                                                                                weapon->GetField154();
                                                                                        else
                                                                                            m_fNextProcedureCheckHour +=
                                                                                                iClipRounds *
                                                                                                GetWeaponConditionDamageMultiplier(
                                                                                                    iCondition) *
                                                                                                weapon->GetField154();
                                                                                    }
                                                                                    m_fNextProcedureCheckHour =
                                                                                        iClipRounds /
                                                                                        m_fNextProcedureCheckHour;
                                                                                    if ((iClipRounds <=
                                                                                             DAT_011cf888.Int()->i ||
                                                                                         includeReload) &&
                                                                                        weapon->FUN_00446390() != 1 &&
                                                                                        weapon->FUN_00446390() != 2 &&
                                                                                        weapon->FUN_00446390() != 0 &&
                                                                                        weapon->FUN_00446390() != 10 &&
                                                                                        weapon->FUN_00446390() != 13 &&
                                                                                        weapon->FUN_00446390() != 11)
                                                                                        m_fNextProcedureCheckHour +=
                                                                                            weapon->GetField150Float();
                                                                                    bIsNPC = false;
                                                                                    if (pActor !=
                                                                                        reinterpret_cast<Actor*>(
                                                                                            g_thePlayer))
                                                                                        bIsNPC = true;
                                                                                    if (bIsNPC &&
                                                                                        weapon->IsRangedWeapon())
                                                                                    {
                                                                                        if (!weapon
                                                                                                 ->GetIsAutomaticWeapon())
                                                                                        {
                                                                                            float fAttackDelay =
                                                                                                (weapon
                                                                                                     ->GetProjectileData() +
                                                                                                 reinterpret_cast<
                                                                                                     MiddleHighProcess*>(
                                                                                                     weapon)
                                                                                                     ->GetThirdProcessFloat()) /
                                                                                                runtimeInitializationDouble2;
                                                                                            float fShotDelay =
                                                                                                1.0f /
                                                                                                fWeaponDamageMultiplier;
                                                                                            if (fAttackDelay >
                                                                                                fShotDelay)
                                                                                            {
                                                                                                float fExtraDelay =
                                                                                                    fAttackDelay -
                                                                                                    fShotDelay;
                                                                                                m_fNextProcedureCheckHour +=
                                                                                                    iClipRounds *
                                                                                                    fExtraDelay;
                                                                                            }
                                                                                        }
                                                                                        bool bIsBurst =
                                                                                            weapon
                                                                                                ->GetIsAutomaticWeapon() ||
                                                                                            weapon->GetBurstShot();
                                                                                        if (bIsBurst)
                                                                                            m_fNextProcedureCheckHour *=
                                                                                                (DAT_011ceef0.Float()
                                                                                                     ->f +
                                                                                                 DAT_011cf21c.Float()
                                                                                                     ->f) /
                                                                                                DAT_011cf21c.Float()->f;
                                                                                    }
                                                                                    fCritChanceOverride = 0.0f;
                                                                                    if (critChance != 0.0)
                                                                                        fCritChanceOverride =
                                                                                            critChance * 100.0;
                                                                                    fCritChance =
                                                                                        (owner
                                                                                             ? owner
                                                                                                   ->GetCurrentActorValue(
                                                                                                       (ActorValue::
                                                                                                            Index)14)
                                                                                             : fCritChanceOverride) *
                                                                                        1.0 *
                                                                                        reinterpret_cast<Actor*>(weapon)
                                                                                            ->ProcessActorAction();
                                                                                    FUN_005330e0(fCritChance, 0.0f,
                                                                                                 100.0f);
                                                                                    fCritChance *= (double)0.01f;
                                                                                    if (weapon &&
                                                                                        weapon
                                                                                            ->GetIsAutomaticWeapon() &&
                                                                                        fWeaponDamageMultiplier != 0.0)
                                                                                        fCritChance /=
                                                                                            fWeaponDamageMultiplier;
                                                                                }
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            if (bIsCreature)
                                                                                afDamageAmount = pActor->Unk_111();
                                                                            else
                                                                            {
                                                                                afDamageAmount =
                                                                                    DAT_011cf810.Float()->f *
                                                                                    (owner
                                                                                         ? owner->GetCurrentActorValue(
                                                                                               (ActorValue::Index)56)
                                                                                         : 0.0f);
                                                                                afDamageAmount +=
                                                                                    (owner
                                                                                         ? owner->GetActorValueFloatByIndex(
                                                                                               (ActorValue::Index)45) /
                                                                                               100.0
                                                                                         : 0.0) *
                                                                                    DAT_011cf350.Float()->f;
                                                                            }
                                                                            m_fNextProcedureCheckHour =
                                                                                bIsCreature ? DAT_011cf6c0.Float()->f
                                                                                            : DAT_011cfbf0.Float()->f;
                                                                        }
                                                                        fConditionDamageMult =
                                                                            GetWeaponHealthConditionMultiplier(health);
                                                                        afDamageAmount *= fConditionDamageMult;
                                                                        fCritDamage =
                                                                            weapon
                                                                                ? (float)weapon->GetShortAtOffset1C0()
                                                                                : 0.0f;
                                                                        if (critMult != 0.0 && fCritDamage != 0.0)
                                                                            fCritDamage *= critMult;
                                                                        fClipDamage =
                                                                            iClipRounds *
                                                                            ((afDamageAmount +
                                                                              fCritChance * fCritDamage) *
                                                                             ((sneakAttack ? 2.0f : 1.0f) *
                                                                              (specialAttack ? 1.25f : 1.0f)));
                                                                        if (m_fNextProcedureCheckHour != 0.0)
                                                                            m_fClusterOffsetX =
                                                                                fClipDamage / m_fNextProcedureCheckHour;
                                                                        return m_fClusterOffsetX;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x00646800
float CombatDamageCalculator::GetActorValueMultiplier(ActorValueOwner* owner, ActorValue::Index part, bool percentage)
{
    float fWeaponDamage = 1.0f;
    switch (part)
    {
    case (ActorValue::Index)25:
    case (ActorValue::Index)26:
    case (ActorValue::Index)27:
    case (ActorValue::Index)28:
    case (ActorValue::Index)29:
    case (ActorValue::Index)30:
    case (ActorValue::Index)31:
        fWeaponDamage = FUN_0040ebd0(100.0f, owner->GetCurrentActorValue(part));
        if (!percentage)
            fWeaponDamage = fWeaponDamage > 0.0 ? 1.0f : 0.0f;
    }
    return fWeaponDamage;
}

// Computes the min and max of two floats and returns a random float in that range, or the shared value if they are equal.
// @fnv 0x006465f0
float CombatDamageCalculator::GetDamageMultiplier(float afValueA, float afValueB)
{
    struct Bounds
    {
        float maximum;
        float minimum;
    } bounds;
    bounds.minimum = FUN_0040ebd0(afValueA, afValueB);
    bounds.maximum = FUN_00404010(afValueA, afValueB);
    if (bounds.minimum != bounds.maximum)
    {
        return RandomFloat(bounds.minimum, bounds.maximum);
    }
    else
    {
        return bounds.minimum;
    }
}

// Multiplies rating by the condition multiplier from GetArmorConditionFactor and returns the result.
// @fnv 0x00646360
float CombatDamageCalculator::CalculateArmorDamageThreshold(unsigned short rating, float condition)
{
    float fRating = 0.0f;
    float fConditionMult = GetArmorConditionFactor(condition);
    fRating = rating * fConditionMult;
    return fRating;
}

// @fnv 0x005dc980
char __fastcall FUN_005dc980(const char* pThis)
{
    return pThis[0x64];
}

// Maps a weapon health percentage to a damage multiplier: returns 1.0 above 0.75, otherwise scales down by 0.67 per unit below 0.75.
// @fnv 0x00646d00
float __cdecl GetWeaponHealthConditionMultiplier(float fWeapHealthPercent)
{
    if (fWeapHealthPercent > 0.75)
    {
        return 1.0f;
    }
    else
    {
        return 1.0 - (0.75 - fWeapHealthPercent) * 0.6700000166893005;
    }
}

extern double DAT_01011588;

// Returns 1.0 when fArmorHealthPercent exceeds DAT_01011588, otherwise returns 1.0 minus the shortfall from DAT_01011588.
// @fnv 0x00646d40
float GetArmorConditionFactor(float fArmorHealthPercent)
{
    if (fArmorHealthPercent > DAT_01011588)
        return 1.0f;
    else
        return 1.0 - (DAT_01011588 - fArmorHealthPercent) * 1.0;
}

// Clamps the int pointed to by aVal to the range [aMin, aMax], writing the bound back when it is out of range.
// @fnv 0x00647ba0
void __cdecl ClampInt(int* aVal, int aMin, int aMax)
{
    if (*aVal > aMax)
    {
        *aVal = aMax;
    }
    else if (*aVal < aMin)
    {
        *aVal = aMin;
    }
}

struct FUN_00644930_shell
{
    char m_auiShapeKeys[0x94];
    float m_f;
    float __thiscall FUN_00644930();
};

// @fnv 0x00644930
float __thiscall FUN_00644930_shell::FUN_00644930()
{
    return m_f;
}

// @fnv 0x00644970
float __fastcall FUN_00644970(void* p)
{
    return *(float*)((char*)p + 0x104);
}

struct FUN_00644a30_shell
{
    unsigned char __thiscall FUN_00644a30();
};

// @fnv 0x00644a30
unsigned char __thiscall FUN_00644a30_shell::FUN_00644a30()
{
    return *(unsigned char*)((char*)this + 0x58);
}

struct FUN_00644a50_shell
{
    char pad[0xc4];
    float fValue;
    float FUN_00644a50();
};

// @fnv 0x00644a50
float FUN_00644a50_shell::FUN_00644a50()
{
    return fValue;
}

// @fnv 0x00646250
float FUN_00646250(int a, int b)
{
    return (float)b;
}

float FUN_004579e0(float a);
extern double _gModifierZero;

// Returns 0 when 1-b is negative, otherwise returns FUN_004579e0(1-b) multiplied by a.
// @fnv 0x00647960
float FUN_00647960(float a, float b)
{
    float t = 1.0f - b;
    if (t < 0.0f)
        return 0.0f;
    return FUN_004579e0(t) * a;
}

struct FUN_00644950_shell
{
    virtual float FUN_00644950();
};

// @fnv 0x00644950
float FUN_00644950_shell::FUN_00644950()
{
    return *(float*)((char*)this + 0x100);
}

struct FUN_00644cc0_shell
{
    unsigned char GetByteAt59();
};

// @fnv 0x00644cc0
unsigned char FUN_00644cc0_shell::GetByteAt59()
{
    return *(unsigned char*)((char*)this + 0x59);
}

struct FUN_00645320_shell
{
    void SetFlag2(bool flag);
};

// @fnv 0x00645320
void FUN_00645320_shell::SetFlag2(bool abSet)
{
    abSet ? reinterpret_cast<unsigned char*>(this)[0x100] |= 2 : reinterpret_cast<unsigned char*>(this)[0x100] &= ~2;
}

struct FUN_00646230_shell
{
    unsigned char m_auiShapeKeys[0x12c];
    unsigned int m_flags;
    bool IsFlagSet();
};

// @fnv 0x00646230
bool FUN_00646230_shell::IsFlagSet()
{
    return (m_flags & 0x40) ? true : false;
}

struct FUN_00646f50_shell
{
    float GetField124Float();
};

// @fnv 0x00646f50
float FUN_00646f50_shell::GetField124Float()
{
    return *(float*)((char*)this + 0x124);
}

struct FUN_00647790_shell
{
    unsigned int m_flags[0x4B];
    bool IsFlag20Set() const;
};

// @fnv 0x00647790
bool FUN_00647790_shell::IsFlag20Set() const
{
    return (m_flags[0x4B] & 0x20) ? true : false;
}

extern SettingT_GameSettingCollection_* DAT_0119b26c[10];

// Returns the float value of the game setting at index aiCondition if it is in [0,10), otherwise 0.0f.
// @fnv 0x006477b0
float FUN_006477b0(int aiCondition)
{
    float fresult = 0.0f;
    if (aiCondition >= 0 && aiCondition < 10)
    {
        fresult = DAT_0119b26c[aiCondition]->Float()->f;
    }
    return fresult;
}

extern "C"
{
    extern SettingT_GameSettingCollection_* DAT_0119b2bc[10];
}

// Returns the float value of the game setting at index a if a is in [0,10), otherwise 0.0f.
// @fnv 0x006477e0
float __cdecl FUN_006477e0(int aiIndex)
{
    float v = 0.0f;
    if (aiIndex >= 0 && aiIndex < 10)
        v = DAT_0119b2bc[aiIndex]->Float()->f;
    return v;
}

// Returns 1 minus the square of b/a when a is at least b, otherwise 0.
// @fnv 0x00647920
float ComputeSquaredRatioComplement(float a, float b)
{
    float result = 0.0f;
    if (a >= b)
    {
        result = b / a;
        result = result * result;
        result = 1.0f - result;
    }
    return result;
}

float __cdecl FUN_00647960(float, float);

// Computes the damage ratio afActualDamage/afBaseExplosionDamage, returns 0 if it exceeds 1, otherwise passes the radius and ratio to FUN_00647960.
// @fnv 0x006479a0
float __cdecl ComputeExplosionDamageFalloff(float afExplosionRadius, float afBaseExplosionDamage, float afActualDamage)
{
    float fDamageRatio = afActualDamage / afBaseExplosionDamage;
    if (fDamageRatio > 1.0f)
        return 0.0f;
    return FUN_00647960(afExplosionRadius, fDamageRatio);
}

struct S00525ae0
{
    BGSProjectile* GetProjectile(void* arg1);
};
// @fnv 0x00525ae0
BGSProjectile* S00525ae0::GetProjectile(void* pActorOffset)
{
    Actor* actor = pActorOffset ? (Actor*)((char*)pActorOffset - 0xA4) : 0;
    return ((TESObjectWEAP*)this)->GetProjectileData(actor);
}

struct FUN_00646020_shell : TESObjectWEAP
{
    float GetModdedWeaponValue(int, int);
    float FUN_00646020(bool);
};
// @fnv 0x00646020
float FUN_00646020_shell::FUN_00646020(bool bModValue)
{
    if (bModValue)
        return GetModdedWeaponValue(8, 0) + ((float*)this)[76];
    else
        return ((float*)this)[76];
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting508;
// Multiplies a by b, then multiplies the result by the float value of originalRuntimeFloatSetting508.
// @fnv 0x006462e0
float FUN_006462e0(float afValueA, float afValueB)
{
    return (double)(afValueA * afValueB) * originalRuntimeFloatSetting508.Float()->f;
}

extern double DAT_01011588;
float __cdecl FUN_00644ce0(void*, int, float, float, int, int, int, int);
// Stores the result of FUN_00644ce0 into *c and, when b is false, sets *d to *c multiplied by DAT_01011588.
// @fnv 0x00646310
void CalcHandToHandDamage(void* a, bool b, float* pfValue, float* pfScaledValue)
{
    *pfValue = FUN_00644ce0(a, 0, 1.0f, 1.0f, 0, 0, 0, 0);
    if (!b)
        *pfScaledValue = *pfValue * DAT_01011588;
}

void __cdecl ClampInt(int*, int, int);
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting583;
// @fnv 0x00647810
float __cdecl GetWeaponStrengthRequirementModifier(unsigned int uiMinuend, unsigned int uiSubtrahend, unsigned int a3)
{
    int v = 0;
    if (uiSubtrahend <= uiMinuend)
    {
        v = uiMinuend - uiSubtrahend - a3;
    }
    else
    {
        v = 0;
    }
    ClampInt(&v, 0, 10);
    return (double)v * originalRuntimeFloatSetting583.Float()->f;
}

struct FUN_00647730_shell : public TESObjectWEAP
{
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT effect, unsigned char value);
    unsigned char FUN_00647730(unsigned char type);
};

// @fnv 0x00647730
unsigned char FUN_00647730_shell::FUN_00647730(unsigned char type)
{
    if (type)
    {
        return (unsigned char)GetModdedWeaponValue((WEAPON_MOD_EFFECT)13, 0) + *(unsigned char*)((char*)this + 0x11c);
    }
    else
    {
        return *(unsigned char*)((char*)this + 0x11c);
    }
}

struct FUN_004e4620_shell
{
    float FUN_004e4620();
};
bool __fastcall FUN_006450c0(TESObjectWEAP*);
// @fnv 0x00645d00
float __cdecl FUN_00645d00(ActorValueOwner* pActorValueOwner, TESObjectWEAP* weapon, InventoryStackRecord* item)
{
    float frateOfFire = 1.0f;
    Actor* pactor = 0;
    pactor = pActorValueOwner ? (Actor*)((char*)pActorValueOwner - 0xa4) : 0;
    if (FUN_006450c0(weapon))
        frateOfFire = ((FUN_004e4620_shell*)weapon)->FUN_004e4620();
    else
        frateOfFire = CombatDamageCalculator::CalculateWeaponDamageForActor(
            dynamic_cast<TESObjectREFR*>(pActorValueOwner), weapon, true, item);
    bool bUseSplit = false;
    if (item)
        bUseSplit = item->SetEquipmentState(0xc);
    frateOfFire = weapon->GetDamageForActor(bUseSplit, false, pactor) * frateOfFire;
    return frateOfFire;
}

namespace fnv_00645dc0 {
struct TESAnimGroup
{
    static unsigned short __cdecl AnimGroup(int, int, int, bool);
};
struct Animation
{
    unsigned short ResolveAnimGroup(unsigned short, bool);
};
struct HackAnim
{
    TESAnimGroup* FUN_00496500(unsigned short);
};
struct FUN_005f3780_shell
{
    float FUN_005f3780(int);
};
struct FUN_004e4620_shell
{
    float FUN_004e4620();
};
struct FUN_00646020_shell
{
    float FUN_00646020(bool);
};
struct FUN_0051f5f0_shell
{
    unsigned int GetByteAt11D();
};
struct TESCreature
{
    float FUN_00821640();
};
struct TESObjectWEAP_GetReloadAnim
{
    int GetReloadAnim(bool);
};
struct PlayerCharacter
{
    Animation* GetAnimation(bool);
};
extern PlayerCharacter* g_thePlayer;
extern int DAT_0118a838[];
extern double gModifierZero;
int __cdecl GetType(unsigned short);
bool __fastcall FUN_004c0bf0(TESObjectWEAP*);

// Computes a weapon's shots-per-second from its animation group timings, reload time and speed modifiers, folding in reload when requested.
// @fnv 0x00645dc0
float GetWeaponShotsPerSecond(TESObjectREFR* apActorRef, TESObjectWEAP* apWeapon, bool abUseReload, InventoryStackRecord* apItem)
{
    float fweapSPS = 0;
    float fweapReloadTime = 0;
    bool bClipSize = false;
    bool bSpeedMod = false;
    Animation* panim = g_thePlayer->GetAnimation(false);
    if (apItem)
    {
        bClipSize = apItem->SetEquipmentState(2);
        bSpeedMod = apItem->SetEquipmentState(8);
    }
    if (panim && abUseReload)
    {
        int iReloadAnim = ((TESObjectWEAP_GetReloadAnim*)apWeapon)->GetReloadAnim(bClipSize);
        if (iReloadAnim == 0xff)
            iReloadAnim = 0xb1;
        unsigned short sanimGroup =
            TESAnimGroup::AnimGroup(0, DAT_0118a838[apWeapon->FUN_00446390()], iReloadAnim, false);
        sanimGroup = panim->ResolveAnimGroup(sanimGroup, false);
        if (GetType(sanimGroup) == iReloadAnim)
        {
            TESAnimGroup* panimGroup = ((HackAnim*)panim)->FUN_00496500(sanimGroup);
            if (panimGroup)
                fweapReloadTime = ((FUN_005f3780_shell*)panimGroup)->FUN_005f3780(1) *
                                  ((FUN_004e4620_shell*)apWeapon)->FUN_004e4620();
        }
    }
    if (apWeapon->GetIsAutomaticWeapon() || !panim)
    {
        fweapSPS = ((TESCreature*)apWeapon)->FUN_00821640() * ((FUN_00646020_shell*)apWeapon)->FUN_00646020(bSpeedMod);
    }
    else if (panim)
    {
        int eattackAnim = ((FUN_0051f5f0_shell*)apWeapon)->GetByteAt11D();
        if (eattackAnim == 0xff)
            eattackAnim = 0x20;
        unsigned short sanimGroup =
            TESAnimGroup::AnimGroup(0, DAT_0118a838[apWeapon->FUN_00446390()], eattackAnim, false);
        sanimGroup = panim->ResolveAnimGroup(sanimGroup, false);
        if (GetType(sanimGroup) == eattackAnim)
        {
            TESAnimGroup* panimGroup = ((HackAnim*)panim)->FUN_00496500(sanimGroup);
            fweapSPS = 1.0f / ((FUN_005f3780_shell*)panimGroup)->FUN_005f3780(3);
        }
    }
    if (abUseReload && fweapReloadTime > gModifierZero && fweapSPS > gModifierZero)
    {
        int inumRounds = FUN_004c0bf0(apWeapon) ? 1 : apWeapon->GetClipRounds(bClipSize);
        float freloadRounds = fweapReloadTime / inumRounds;
        freloadRounds = 1.0f / fweapSPS + freloadRounds;
        fweapSPS = 1.0f / freloadRounds;
    }
    return ((FUN_004e4620_shell*)apWeapon)->FUN_004e4620() * fweapSPS *
           ((FUN_00646020_shell*)apWeapon)->FUN_00646020(bSpeedMod);
}
}  // namespace fnv_00645dc0

// Returns the average of actor values 27 and 28 for weapon types 0,2,5-9, otherwise actor value 28 alone.
// @fnv 0x00646880
float GetArmCondition(ActorValueOwner* actor, int weaponType)
{
    float result = 1.0f;
    switch (weaponType)
    {
    case 0:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        result = (CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(27), false) +
                  CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(28), false)) /
                 2.0;
        break;
    default:
        result = CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(28), false);
        break;
    }
    return result;
}

extern SettingT_GameSettingCollection_ g_011ce660;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting611;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting612;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting613;

// Computes a damage multiplier from the owner's agility (actor value 10) and the damage value using four game settings, and returns their product.
// @fnv 0x00646580
float FUN_00646580(ActorValueOwner* owner, int damage)
{
    float fmodAgility;
    float fDamageFactor;
    {
        float fagility = owner->GetActorValueFloatByIndex((ActorValue::Index)10) * 10.0;
        fDamageFactor = g_011ce660.Float()->f + originalRuntimeFloatSetting611.Float()->f * fagility;
    }
    {
        fmodAgility = originalRuntimeFloatSetting612.Float()->f + originalRuntimeFloatSetting613.Float()->f * damage;
    }
    return fDamageFactor * fmodAgility;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting760;

struct ArrSI
{
    TESObjectWEAP* GetFlags();
};

struct FUN_00646260Process
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual ArrSI* GetTarget();
};

// @fnv 0x00646260
float FUN_00646260(Actor* apActor)
{
    TESObjectWEAP* pWeap;
    float m_fCriticalHitMultiplier;

    m_fCriticalHitMultiplier = *reinterpret_cast<float*>(originalRuntimeFloatSetting760.Float());
    pWeap = reinterpret_cast<FUN_00646260Process*>(apActor->GetCurrentAIProcess())->GetTarget()->GetFlags();

    if (pWeap && pWeap->GetCurrentAmmo(apActor))
    {
        m_fCriticalHitMultiplier = TESAmmoEffect::ApplyAmmoEffects(
            AMMO_EFFECT_TYPE(4),
            reinterpret_cast<BSSimpleList<TESAmmoEffect*>*>(
                reinterpret_cast<TESAmmoInitCalls*>(pWeap->GetCurrentAmmo(apActor))->FUN_00923000()),
            m_fCriticalHitMultiplier);
    }

    return m_fCriticalHitMultiplier;
}

// Returns true when the weapon's data.eType is 0, 1 or 2, otherwise false.
// @fnv 0x006450c0
bool __fastcall FUN_006450c0(TESObjectWEAP* pWeap)
{
    switch (pWeap->data.eType)
    {
    case 0:
    case 1:
    case 2:
        return true;
    }
    return false;
}

struct DamageAmmo
{
    signed char GetCategory();
};
struct DamageWeapon
{
    bool IsDamageDisabled();
    int GetWeaponType();
    bool IsRangedWeapon();
};
struct CombatActorForm
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual DamageAmmo* GetAmmo();
    int GetFormType();
};
struct AttackOwner
{
    int unk00;
};
struct NPCCombatPrefix
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
};
struct CreatureCombatPrefix
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
};
struct NPCCombatForm : CombatActorForm, NPCCombatPrefix, AttackOwner
{
};
struct CreatureCombatForm : CombatActorForm, CreatureCombatPrefix, AttackOwner
{
    DamageAmmo* GetCreatureAmmo();
};
extern const double DAT_01020758;
extern const double DAT_0102f078;
float __cdecl FUN_00645380(AttackOwner*, DamageWeapon*, float, int, void*, int, int, int, float, float, int, int,
                           void*);
// Computes weapon damage via FUN_00645380 for NPC or creature forms, then scales it by weapon type and ammo category.
// @fnv 0x00646060
float __cdecl ComputeWeaponDamage(CombatActorForm* form, DamageWeapon* weapon, float condition, DamageAmmo* ammo,
                                  void* changes, void* extra)
{
    if (weapon && weapon->IsDamageDisabled())
        return 0.0f;
    float damage3 = 0.0f;
    if (form->GetFormType() == 43 || form->GetFormType() == 42)
    {
        NPCCombatForm* npc = static_cast<NPCCombatForm*>(form);
        damage3 = FUN_00645380(static_cast<AttackOwner*>(npc), weapon, condition, 0, changes, 0, 0, -1, 0.0f, 0.0f, 0,
                               0, extra);
        if (!ammo)
            ammo = npc->GetAmmo();
    }
    else
    {
        CreatureCombatForm* pCreature = static_cast<CreatureCombatForm*>(form);
        damage3 = FUN_00645380(static_cast<AttackOwner*>(pCreature), weapon, condition, 0, changes, 0, 0, -1, 0.0f,
                               0.0f, 0, 0, extra);
        if (!ammo)
            ammo = pCreature->GetCreatureAmmo();
    }
    int weaponType = weapon ? weapon->GetWeaponType() : 6;
    if (weaponType == 3)
        damage3 /= DAT_01020758;
    else if (weaponType == 4)
        damage3 = 0.0f;
    if (ammo)
    {
        signed char cAmmoCategory = ammo->GetCategory();
        if (cAmmoCategory == 1 && weapon && weapon->IsRangedWeapon())
            damage3 /= DAT_0102f078;
        else if (cAmmoCategory == 2 && (!weapon || !weapon->IsRangedWeapon()))
            damage3 /= DAT_0102f078;
    }
    return damage3;
}

extern SettingT_GameSettingCollection_ DAT_011cfd58;
extern SettingT_GameSettingCollection_ DAT_011cf618;
extern SettingT_GameSettingCollection_ DAT_011cf624;
extern SettingT_GameSettingCollection_ DAT_011cfe74;
extern SettingT_GameSettingCollection_ DAT_011cfd04;
extern SettingT_GameSettingCollection_ DAT_011cf724;
extern SettingT_GameSettingCollection_ DAT_011cf950;
extern SettingT_GameSettingCollection_ DAT_011cfb9c;
float __cdecl FUN_00408840(float);

// @fnv 0x006466e0
float __cdecl RemapValueBySettings(float aValue, bool bAlternative)
{
    float fMinimumInputValue = bAlternative ? DAT_011cfd58.Float()->f : DAT_011cf618.Float()->f;
    float lowOutput = bAlternative ? DAT_011cf624.Float()->f : DAT_011cfe74.Float()->f;
    float value = bAlternative ? DAT_011cfd04.Float()->f : DAT_011cf724.Float()->f;
    float fTargetUpperBound = bAlternative ? DAT_011cf950.Float()->f : DAT_011cfb9c.Float()->f;
    float highOutput = FUN_00408840(aValue);
    highOutput = (highOutput - fMinimumInputValue) / (lowOutput - fMinimumInputValue);
    highOutput = FUN_0040ebd0(1.0f, FUN_00404010(highOutput, 0.0f));
    return (fTargetUpperBound - value) * highOutput + value;
}

struct ChanceSetting
{
    int* __thiscall Int();
};
extern ChanceSetting DAT_011ce2fc;
extern ChanceSetting DAT_011cf2ec;
extern const double DAT_01016408;
unsigned int __cdecl FUN_00487f50();
struct ChanceModifier
{
    int __thiscall FUN_008a16b0();
};
// Rolls a random 0-99 value and sets success/critical flags against computed chances, then applies a modifier that can override the outcome.
// @fnv 0x00646e50
void __cdecl RollChanceOutcome(void* unused, ChanceModifier* modifier, int baseChance, int effectChance,
                               int extraChance, bool fixedChance, unsigned char* success, unsigned char* critical)
{
    *success = 0;
    *critical = 0;
    unsigned int normalChance = FUN_00487f50() % 100;
    int intermediateChance;
    if (fixedChance)
    {
        intermediateChance = baseChance + extraChance;
    }
    else
    {
        int criticalBase = extraChance + *DAT_011ce2fc.Int();
        intermediateChance = (int)((double)criticalBase * ((double)baseChance * DAT_01016408));
    }
    int criticalChance = intermediateChance;
    int roll = effectChance + *DAT_011cf2ec.Int();
    if ((int)normalChance < criticalChance)
    {
        *critical = 1;
    }
    else if ((int)normalChance < roll)
    {
        *success = 1;
    }
    if (modifier && (*critical || *success))
    {
        switch (modifier->FUN_008a16b0())
        {
        case 1:
            *critical = 0;
            *success = 1;
            break;
        case 2:
            *critical = 1;
            *success = 0;
            break;
        case 3:
            *critical = 0;
            *success = 0;
            break;
        }
    }
}

extern const double g_d644810Zero;

unsigned int __cdecl C644810Random();

class C644810Actor
{
  public:
    char GetBaseChance();
    float GetLuckBonus();
    float GetSkillBonus();
    float GetBaseModifier();
    float GetScaledModifier();
};

// Computes a success chance from the actor's base chance plus optional luck and skill bonuses and a difficulty modifier, then compares it against a random roll.
// @fnv 0x00644810
bool __cdecl CheckChanceSuccess(C644810Actor* pkActor, float fDifficulty, bool bUseLuck, bool bUseSkill, bool bAutoFail)
{
    if (bAutoFail)
        return false;

    float fChancePercent = pkActor->GetBaseChance();
    if (fChancePercent == g_d644810Zero)
        return false;
    else if (fChancePercent >= 100.0)
        return true;

    float fA = bUseLuck ? pkActor->GetLuckBonus() : 0.0f;
    float fSkillValueBonus = bUseSkill ? pkActor->GetSkillBonus() : 0.0f;
    float fC = pkActor->GetBaseModifier() + (1.0 - fDifficulty) * pkActor->GetScaledModifier();
    fChancePercent = fA + fSkillValueBonus + fC + fChancePercent;

    float fRandom = (float)(C644810Random() % 100);
    return fRandom <= fChancePercent;
}

struct OCSetting
{
    float* Float();
};

struct OCActor
{
    float GetFieldCC();
    float FUN_00453700();
    float GetFirstLightParameter();
    float FUN_00885bd0();
    char GetByteAt59();
};

unsigned int __cdecl OCDialogueRandom();

extern OCSetting g_kOCSettingSkillMult;
extern OCSetting g_kOCSettingBonus;

// Rolls three skill/bonus-weighted random scores and returns an outcome code (0,1,2,4,8) based on comparisons and actor checks.
// @fnv 0x00644a70
unsigned short __cdecl FUN_00644a70(OCActor* apActor, bool abUseSkillB, bool abUseSkillA, float afValueA,
                                    float afValueB, bool abBonus, bool abNoFirst, unsigned short ausFlags)
{
    unsigned short usResult6 = 0;
    usResult6 = 0;

    float fFirst = *g_kOCSettingSkillMult.Float() * (abUseSkillA ? apActor->GetFieldCC() : apActor->FUN_00453700()) *
                   (OCDialogueRandom() % 5 + 1);
    float fSecond = *g_kOCSettingSkillMult.Float() *
                    (abUseSkillB ? apActor->GetFirstLightParameter() : apActor->FUN_00885bd0()) *
                    (OCDialogueRandom() % 5 + 1);
    if ((ausFlags & 2) || abNoFirst)
        fFirst = 0.0f;
    if (ausFlags & 1)
        fSecond = 0.0f;
    float fThird2 =
        *g_kOCSettingSkillMult.Float() * (abBonus ? *g_kOCSettingBonus.Float() : 1.0f) * (OCDialogueRandom() % 5 + 1);

    if ((fFirst >= fSecond && fFirst > fThird2) || afValueA < afValueB * 0.5)
    {
        usResult6 = 2;
    }
    else if (fSecond > fFirst && fSecond > fThird2 && afValueA > afValueB * 1.5)
    {
        usResult6 = 1;
    }
    else
    {
        float fRoll = OCDialogueRandom() % 100;
        if (apActor->GetByteAt59() >= fRoll)
        {
            fRoll = OCDialogueRandom() % 100;
            if (fRoll <= 49.0)
            {
                if (!(ausFlags & 4))
                    usResult6 = 4;
            }
            else
            {
                if (!(ausFlags & 8))
                    usResult6 = 8;
            }
        }
    }
    return usResult6;
}

float FUN_00644ce0(void*, int, float, float, int, int, int, bool);
class PlayerCharacter : public Actor
{
};
struct DamageExtra
{
    bool HasEffect(int);
};
// Computes weapon damage from condition and ammo, applies ammo effects and perk modifiers, and returns the result.
// @fnv 0x006450f0
float GetWeaponDamage(TESObjectWEAP* weapon, float condition, DamageExtra* extra, TESAmmo* specifiedAmmo)
{
    float damage = 0.0f;
    damage = FUN_00645380((AttackOwner*)static_cast<ActorValueOwner*>(g_thePlayer), (DamageWeapon*)weapon, condition, 1,
                          extra, 0, 0, -1, 0.0f, 0.0f, 0, 0, specifiedAmmo);
    if (weapon && weapon->GetIsAutomaticWeapon() && FUN_006450c0(weapon))
    {
        ((FUN_00645320_shell*)weapon)->SetFlag2(false);
        damage = FUN_00644ce0(static_cast<ActorValueOwner*>(g_thePlayer), (int)weapon, condition, 1.0f, 0, 0,
                              (int)extra, specifiedAmmo != 0);
        ((FUN_00645320_shell*)weapon)->SetFlag2(true);
    }
    else
    {
        damage = FUN_00644ce0(static_cast<ActorValueOwner*>(g_thePlayer), (int)weapon, condition, 1.0f, 0, 0,
                              (int)extra, specifiedAmmo != 0);
    }
    TESAmmo* ammo = 0;
    if (weapon)
        ammo = specifiedAmmo ? specifiedAmmo : weapon->GetCurrentAmmo(g_thePlayer);
    if (!ammo)
        ammo = weapon->GetCurrentAmmo(0);
    if (ammo && weapon && (void*)ammo != (void*)weapon)
    {
        BSSimpleList<TESAmmoEffect*>* effects =
            ammo ? (BSSimpleList<TESAmmoEffect*>*)((TESAmmoInitCalls*)ammo)->FUN_00923000() : 0;
        damage = TESAmmoEffect::ApplyAmmoEffects(AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM, effects, damage);
    }
    if (extra && extra->HasEffect(12))
        damage = damage * 1.3;
    ApplyPerkModifiers(0, g_thePlayer, weapon, g_thePlayer, &damage);
    return damage;
}

class TESObjectWEAP646
{
  public:
    int GetWeaponType() const;
    bool GetIsAutomaticWeapon();
    float GetFireRate();
    float GetDamageMult();
};

class ActorValueOwner646
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual float GetActorValue(int iAV);
};

// @fnv 0x00646d80
float __cdecl GetWeaponDPS(ActorValueOwner646* pkOwner, TESObjectWEAP646* pkWeapon)
{
    int iType = pkWeapon ? pkWeapon->GetWeaponType() : -1;
    float fShotRate = 1.0f;
    bool bAuto = false;

    if (pkWeapon && pkWeapon->GetIsAutomaticWeapon())
        fShotRate = pkWeapon->GetFireRate();
    if (fShotRate == 0.0)
        fShotRate = 1.0f;

    float fValue = pkOwner ? pkOwner->GetActorValue(0xe) : 0.0f;
    float fDPS = fValue / fShotRate;
    if (pkWeapon && pkWeapon->GetDamageMult() >= 0.0)
        fDPS *= pkWeapon->GetDamageMult();
    return fDPS;
}

extern SettingT_GameSettingCollection_ DAT_011cf648;
extern SettingT_GameSettingCollection_ DAT_011cf654;
extern SettingT_GameSettingCollection_ DAT_011ce830;
extern SettingT_GameSettingCollection_ DAT_011cedd0;
extern SettingT_GameSettingCollection_ DAT_011cef38;
extern SettingT_GameSettingCollection_ DAT_011ce60c;
extern SettingT_GameSettingCollection_ DAT_011cf008;
extern SettingT_GameSettingCollection_ DAT_011cf068;
extern SettingT_GameSettingCollection_ DAT_011cf7f8;
extern SettingT_GameSettingCollection_ DAT_011ceb8c;
extern const double DAT_01012070;

struct CombatAVOwner : public ActorValueOwner
{
    float FUN_0066ef50(int value);
    int FUN_0066ef20(int value);
};
struct CombatWeapon : public TESObjectWEAP
{
    bool FUN_00646cb0();
    int GetField19C();
    int GetUnk15C();
    int GetField1BC();
};
float __cdecl FUN_00646800(ActorValueOwner* owner, int attribute, int unused);
float __cdecl GetWeaponStrengthRequirementModifier(unsigned int weaponType, unsigned int baseValue, unsigned int perkLevel);
float __cdecl ComputeScaledCount(int weaponCategory, int ownerValue, int mode);

// Computes a weapon damage modifier from actor perks, game settings, weapon type and category values, clamps it to a minimum and returns it.
// @fnv 0x00646910
float __cdecl ComputeWeaponDamageModifier(Actor* actor, TESObjectWEAP* weapon, void* unused, bool bypassDamage,
                                          bool bypassCritical, bool useEnergy, bool useUnarmed)
{
    float damageFactor_2 = 1.0f;
    float modifier4 = 0.0f;
    if (actor == reinterpret_cast<Actor*>(g_thePlayer))
    {
        ApplyPerkModifiers(0x36, reinterpret_cast<Actor*>(g_thePlayer), weapon, &damageFactor_2);
        if (damageFactor_2 < DAT_01012070)
        {
            damageFactor_2 = 1.0f;
        }
    }
    if (!bypassCritical)
        modifier4 += DAT_011cf648.Float()->f;
    if (useEnergy)
        modifier4 += DAT_011cf654.Float()->f / damageFactor_2;
    else if (useUnarmed)
        modifier4 += DAT_011ce830.Float()->f / damageFactor_2;
    if (!bypassDamage)
        modifier4 += DAT_011cedd0.Float()->f;

    float firstB = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x1b, 0);
    float second7 = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x1c, 0);
    float third3 = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x19, 0);
    if (actor->GetActorValue(static_cast<ActorValue::Index>(0x48)) == 0)
    {
        if (firstB == 0.0 && second7 == 0.0)
        {
            if (reinterpret_cast<CombatWeapon*>(weapon)->FUN_00646cb0())
                modifier4 += DAT_011cef38.Float()->f;
            else
                modifier4 += DAT_011ce60c.Float()->f;
        }
        else if (firstB == 0.0 || second7 == 0.0)
        {
            if (reinterpret_cast<CombatWeapon*>(weapon)->FUN_00646cb0())
                modifier4 += DAT_011cf008.Float()->f;
            else if (second7 == 0.0)
                modifier4 += DAT_011cf068.Float()->f;
        }
    }

    int baseValue_ = (unsigned int)(reinterpret_cast<CombatAVOwner*>((char*)actor + 0xa4)->FUN_0066ef50(5));
    float perkValue3 = 0.0f;
    Actor* perkActor = actor;
    ApplyPerkModifiers(0x35, perkActor, weapon, &perkValue3);
    int perkLevelB = (unsigned int)perkValue3;
    int weaponType7 = reinterpret_cast<CombatWeapon*>(weapon)->GetField19C();
    float weaponModifier4 = GetWeaponStrengthRequirementModifier(weaponType7, baseValue_, perkLevelB);
    modifier4 += weaponModifier4;

    int weaponCategoryX = weapon ? reinterpret_cast<CombatWeapon*>(weapon)->GetUnk15C() : 0x2d;
    float categoryValueB = reinterpret_cast<CombatAVOwner*>((char*)actor + 0xa4)->FUN_0066ef20(weaponCategoryX);
    int categoryLevel = (unsigned int)categoryValueB;
    int weaponClass2 = reinterpret_cast<CombatWeapon*>(weapon)->GetField1BC();
    float categoryModifier4 = ComputeScaledCount(weaponClass2, categoryLevel, 0);
    modifier4 += categoryModifier4;

    float multiplier7 = static_cast<float>(1.0 - categoryValueB * DAT_011cf7f8.Float()->f * (double)0.01f);
    modifier4 *= multiplier7;
    if (modifier4 < DAT_011ceb8c.Float()->f)
        modifier4 = DAT_011ceb8c.Float()->f;
    return modifier4;
}

namespace fnv_00647870 {
float FUN_00476b20(float value);
void ClampUInt(unsigned* value, unsigned low, unsigned high);
struct Setting444
{
    float* FUN_00403e20();
};
extern Setting444 originalRuntimeFloatSetting583;
// @fnv 0x00647870
float ComputeScaledCount(unsigned first, unsigned second, unsigned third)
{
    unsigned count = 0;
    float amount_2 = 0.0f;
    if (second <= first)
    {
        amount_2 = static_cast<float>(first - second - third);
        amount_2 = FUN_00476b20(static_cast<float>(amount_2 / 10.0));
        count = static_cast<unsigned>(amount_2);
        ClampUInt(&count, 0, 10);
    }
    return static_cast<float>(static_cast<double>(count) * *originalRuntimeFloatSetting583.FUN_00403e20());
}
}  // namespace fnv_00647870

namespace fnv_00644990 {
struct FUN_006d6d90_shell
{
    float FUN_006d6d90();
};
struct FUN_0099e040_shell
{
    float FUN_0099e040();
};
struct FUN_00644a30_shell
{
    unsigned char FUN_00644a30();
};
struct FUN_00644a50_shell
{
    float FUN_00644a50();
};
struct FUN_009a1260_Class
{
    float GetFloatAt0xC8();
};
struct FUN_006d2c40_s
{
    float GetFieldB4Float();
};
class TESForm6449
{
  public:
    float GetFieldB8Float();
};

// Computes a float from iLevel, fRatio, bFlag, and values returned by calls on pkActor.
// @fnv 0x00644990
float __cdecl FUN_00644990(void* pkActor, int iLevel, float fRatio, bool bFlag)
{
    float fBonus =
        iLevel * ((FUN_006d6d90_shell*)pkActor)->FUN_006d6d90() + ((FUN_0099e040_shell*)pkActor)->FUN_0099e040();
    float fBase =
        (1.0f - fRatio) * ((FUN_006d2c40_s*)pkActor)->GetFieldB4Float() + ((TESForm6449*)pkActor)->GetFieldB8Float();
    float fResult = (char)((FUN_00644a30_shell*)pkActor)->FUN_00644a30() + fBonus + fBase;
    fResult *=
        bFlag ? ((FUN_00644a50_shell*)pkActor)->FUN_00644a50() : ((FUN_009a1260_Class*)pkActor)->GetFloatAt0xC8();
    return fResult;
}
}  // namespace fnv_00644990

extern SettingT_GameSettingCollection_ DAT_011cf044;
extern SettingT_GameSettingCollection_ DAT_011cec88;
extern SettingT_GameSettingCollection_ DAT_011cfdf0;
extern const double DAT_01012060;

// Combines setting values using a1 and a2, then sets the result to zero if it is below a global threshold.
// @fnv 0x00646660
float FUN_00646660(float afLerp, float afScale)
{
    float fScale = afScale;
    float fAdjusted;
    float fResult;

    fAdjusted = DAT_011cf044.Float()->f - fScale * DAT_011cec88.Float()->f;
    fResult = afLerp * fAdjusted + (1.0f - afLerp) * DAT_011cfdf0.Float()->f;
    if (fResult < DAT_01012060)
    {
        fResult = 0.0f;
    }
    return fResult;
}

class TypeCheck646
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    char m_cType;
    bool FUN_00646cb0();
};
// Returns true if m_cType is 2, 5, 6, 8, or 9, otherwise false.
// @fnv 0x00646cb0
bool TypeCheck646::FUN_00646cb0()
{
    switch (m_cType)
    {
    case 2:
    case 5:
    case 6:
    case 8:
    case 9:
        return true;
    }
    return false;
}

class BGSProjectile
{
  public:
    float GetExplosionProximity() const;
};

struct FUN_00452370_shell
{
    bool FUN_00452370() const;
};

struct FUN_00524b80_This
{
    float GetMinSpreadDegrees(bool);
};
struct FUN_0066ef50_Owner
{
    float FUN_0066ef50(int);
};
struct FUN_008d85e0_Weap
{
    int GetUnk15C();
};
char __fastcall FUN_005dc980(const char*);
bool __fastcall FUN_006450c0(TESObjectWEAP*);
bool __fastcall FUN_004c0bf0(TESObjectWEAP*);
bool __fastcall FUN_004c0c60(TESObjectWEAP*);
float __cdecl FUN_0057dd70(float);
float __cdecl GetArmCondition(ActorValueOwner*, int);

struct CombatDebugLog
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Log(int, int, const char*, ...);
};
typedef bool(__thiscall* RefBoolFn)(TESObjectREFR*);

extern SettingT_GameSettingCollection_ DAT_011cfab0;
extern SettingT_GameSettingCollection_ DAT_011cef80;
extern SettingT_GameSettingCollection_ DAT_011ced00;
extern SettingT_GameSettingCollection_ DAT_011cfba8;
extern SettingT_GameSettingCollection_ DAT_011cf068;
extern SettingT_GameSettingCollection_ DAT_011cf528;
extern SettingT_GameSettingCollection_ DAT_011ce99c;
extern SettingT_GameSettingCollection_ DAT_011cf8bc;
extern SettingT_GameSettingCollection_ DAT_011cfe08;
extern SettingT_GameSettingCollection_ DAT_011ceb20;
extern SettingT_GameSettingCollection_ DAT_011ce6fc;
extern SettingT_GameSettingCollection_ DAT_011cfe50;
extern SettingT_GameSettingCollection_ DAT_011cf504;
extern SettingT_GameSettingCollection_ DAT_011cf678;
extern SettingT_GameSettingCollection_ DAT_011cee54;
extern SettingT_GameSettingCollection_ DAT_011ce10c;
extern double DAT_01017a40;
extern const double DAT_01023128;
extern const float DAT_01016410;

// Computes the hit chance for a weapon attack on a target, applying range, spread, ammo, and stealth modifiers, and returns the final probability.
// @fnv 0x00646f70
float __cdecl GetHitChance(ActorValueOwner* m_pkAttacker, TESObjectREFR* pTarget, TESObjectWEAP* pWeapon,
                           void* unused14, void* unused18, float fSpreadBonus, const char* pAmmoName,
                           FUN_00647730_shell* pWeaponMod, float fWeaponDamage, float afDistance, float fWeaponSpread,
                           CombatDebugLog* pLog)
{
    float fFinalVal = 0.0f;
    float fOutOdds = 0.0f;
    bool bDestTarget = pTarget ? (((FUN_00452370_shell*)pTarget)->FUN_00452370() && !pTarget->IsActor()) : false;
    bool bThrown = ((RefBoolFn)(*(void***)pTarget)[0x89])(pTarget);
    ActorValueOwner* pTargetAV = (pTarget && pTarget->IsActor()) ? (ActorValueOwner*)(Actor*)pTarget : 0;
    float fOutAmmoChance = 0.0f;
    if (pAmmoName)
    {
        fOutAmmoChance = (float)(unsigned char)FUN_005dc980(pAmmoName);
    }
    else if (pWeaponMod)
    {
        fOutAmmoChance = (float)pWeaponMod->FUN_00647730(0);
    }
    else
    {
        fOutAmmoChance = 1.0f;
    }
    if (bThrown)
        fOutAmmoChance = 1.0f;
    if (pLog && (bDestTarget || bThrown))
    {
        pLog->Log(1, 3, "%s%s", bDestTarget ? "Destructible Target " : "", bThrown ? "Grenade Target" : "");
    }
    float fCurWeight = FUN_0040ebd0(DAT_011cfab0.Float()->f, 1.0f);
    float fConditionMultVal = fCurWeight * fWeaponDamage + (1.0f - fCurWeight);
    if (pWeapon && !FUN_006450c0(pWeapon))
    {
        if (((S00525ae0*)pWeapon)->GetProjectile(m_pkAttacker) &&
            ((S00525ae0*)pWeapon)->GetProjectile(m_pkAttacker)->GetExplosionProximity() != DAT_01012060)
        {
            if (pLog)
                pLog->Log(1, 3, "Target out of explosion range");
            return 0.0f;
        }
        if (FUN_004c0bf0(pWeapon))
        {
            float fCurMaxRange = ((FUN_00646f50_shell*)pWeapon)->GetField124Float();
            if (fCurMaxRange * DAT_011cef80.Float()->f < afDistance)
            {
                if (pLog)
                    pLog->Log(1, 3, "Target out of thrown weapon range");
                return 0.0f;
            }
            float fModRangeVal = fCurMaxRange * DAT_011ced00.Float()->f;
            float fGap = fModRangeVal - DAT_011cfba8.Float()->f;
            float fFalloff = 1.0f - FUN_00404010(afDistance - DAT_011cfba8.Float()->f, 0.0f) / fGap;
            float fOutArmMult = GetArmCondition(m_pkAttacker, pWeapon ? pWeapon->FUN_00446390() : 0);
            if (fOutArmMult <= DAT_01012060)
            {
                fOutArmMult = 1.0f - DAT_011cf068.Float()->f;
            }
            else
            {
                fOutArmMult = 1.0f;
            }
            float fOutSkill =
                (((FUN_0066ef50_Owner*)m_pkAttacker)->FUN_0066ef50(((FUN_008d85e0_Weap*)pWeapon)->GetUnk15C()) *
                     DAT_011cf528.Float()->f / DAT_01017a40 +
                 (1.0f - DAT_011ce99c.Float()->f)) *
                fOutArmMult;
            fOutOdds = DAT_011cf8bc.Float()->f * (fFalloff + fOutSkill) * DAT_01017a40;
            if (pLog)
            {
                pLog->Log(1, 3, "mod max range: %.2f, range gap: %.2f, range odds: %.2f", (double)fModRangeVal,
                          (double)fGap, (double)fFalloff);
                pLog->Log(1, 3, "arm condition: %.2f, skill calc %.2f, final chance %.2f", (double)fOutArmMult,
                          (double)fOutSkill, (double)fOutOdds);
            }
        }
        else
        {
            if (FUN_004c0c60(pWeapon) && ((FUN_00647790_shell*)pWeapon)->IsFlag20Set() &&
                ((FUN_00646f50_shell*)pWeapon)->GetField124Float() < afDistance)
            {
                return 0.0f;
            }
            float fOutSpreadMult = 1.0f;
            if (FUN_004c0c60(pWeapon))
            {
                fOutSpreadMult = ((FUN_00524b80_This*)pWeapon)->GetMinSpreadDegrees(false) + fSpreadBonus;
            }
            float fOutConeRadius = FUN_0057dd70(fOutSpreadMult * DAT_011cfe08.Float()->f * DAT_01023128) * afDistance;
            float fAreaVal = fOutConeRadius * fOutConeRadius * 3.1415927410125732;
            float fCurTargetArea = fWeaponSpread / 3.0 * fWeaponSpread;
            if (bThrown)
            {
                fCurTargetArea = DAT_011ceb20.Float()->f;
            }
            else
            {
                if (fOutConeRadius * 2.0f < fWeaponSpread)
                {
                    fCurTargetArea = (fOutConeRadius * 2.0f) / fWeaponSpread * fCurTargetArea;
                }
                if (bDestTarget)
                {
                    fCurTargetArea = fCurTargetArea * DAT_011ce6fc.Float()->f;
                }
            }
            float fAreaRatio = 0.0f;
            if (fAreaVal > DAT_01012060)
            {
                fAreaRatio = FUN_0040ebd0(fCurTargetArea / fAreaVal, DAT_011cfe50.Float()->f);
            }
            fOutOdds = DAT_011cf504.Float()->f * fConditionMultVal * fAreaRatio * fOutAmmoChance;
            if (pLog)
            {
                pLog->Log(1, 3, "bound size: %.2f, base chance: %.2f", (double)fWeaponSpread, (double)fOutAmmoChance);
                pLog->Log(1, 3, "spread factor: %.2f, radius %.2f, area %.2f", (double)fOutSpreadMult,
                          (double)fOutConeRadius, (double)fAreaVal);
                pLog->Log(1, 3, "target area: %.2f, range spread: %.2f, final chance: %.2f", (double)fCurTargetArea,
                          (double)fAreaRatio, (double)fOutOdds);
            }
        }
        if (bDestTarget || bThrown)
        {
            fOutOdds = fOutOdds * DAT_01017a40;
            if (fOutOdds > DAT_01012060 && fOutOdds < 1.0)
            {
                fOutOdds = 1.0f;
            }
            if (pLog)
                pLog->Log(1, 3, "destructible/grenade target chance: %.2f", (double)fOutOdds);
        }
    }
    else
    {
        if (afDistance <= DAT_011cf678.Float()->f)
        {
            if (pLog)
                pLog->Log(1, 3, "Melee weapon or unarmed assume 100%");
            fOutOdds = DAT_01016410;
        }
        else
        {
            if (pLog)
                pLog->Log(1, 3, "Melee weapon or unarmed -- out of range");
        }
    }
    if (pTargetAV && (pTargetAV->GetActorValue((ActorValue::Index)0x31) > 0 ||
                      m_pkAttacker->GetActorValue((ActorValue::Index)0x30) > 0))
    {
        if (pLog)
            pLog->Log(1, 3, "Stealth bonus: %f becomes %f", (double)fOutOdds,
                      (double)(fOutOdds * DAT_011cee54.Float()->f));
        float fStealthBonus = 0.0f;
        ApplyPerkModifiers(0x45, (Actor*)g_thePlayer, &fStealthBonus);
        if (fStealthBonus <= DAT_01012060)
        {
            fOutOdds = fOutOdds * DAT_011cee54.Float()->f;
        }
    }
    fFinalVal = FUN_0040ebd0(fOutOdds, DAT_011ce10c.Float()->f);
    return fFinalVal / DAT_01017a40;
}

struct DmgSetting
{
    float* Float();
};

struct DmgAmmo
{
    void* GetEffect();
};

struct DmgFormBase
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
};

struct DmgAttackDamageForm
{
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(DmgAttackDamageForm* apOther);
    virtual bool CompareWithBase(DmgAttackDamageForm* apOther);
    virtual unsigned short GetAttackDamage();

    unsigned short m_usAttackDamage;
};

struct DmgWeapon : DmgFormBase, DmgAttackDamageForm
{
    int GetSkill();
    int GetWeaponType();
    DmgAmmo* GetAmmo(void* apActor);
    unsigned char GetDamageForActor(bool abSplit, bool abUnk, Actor* apActor);
    bool GetIsAutomaticWeapon();
};

struct DmgVATS
{
    bool IsActive();
};

struct DmgTimeGlobal
{
    float GetTimeMult();
};

bool __fastcall DmgIsSkillBased(DmgWeapon* apWeapon);
float __cdecl DmgAmmoEffectMult(void* apEffect);

extern DmgSetting g_kDmgBaseMult;
extern DmgSetting g_kDmgSkillMultA;
extern DmgSetting g_kDmgSkillMultB;
extern DmgSetting g_kDmgConditionBase;
extern DmgSetting g_kDmgConditionMult;
extern Actor* g_pDmgPlayer;
extern DmgVATS g_kDmgVATS;
extern DmgTimeGlobal g_kDmgTimeGlobal;
extern const float g_fDmgDefaultSkill;

// Computes total weapon damage from base, skill, ammo, condition, time and teammate multipliers, returning the final value.
// @fnv 0x00644ce0
float __cdecl FUN_00644ce0(ActorValueOwner* apOwner, DmgWeapon* apWeapon, float afCondition, float afMult, int aiUnused,
                           bool abNoAmmo, InventoryStackRecord* apItem, bool abUseActor)
{
    int iSkillB = apWeapon ? apWeapon->GetSkill() : 0x2d;
    float fBaseDamage4 = *g_kDmgBaseMult.Float() * (apWeapon ? (float)apWeapon->GetAttackDamage() : 1.0f);
    float fBonus6 = 0.0f;
    if (apItem)
        apItem->SetEquipmentState(1, fBonus6);

    if (apWeapon)
    {
        switch (apWeapon->GetWeaponType())
        {
        case 1:
        case 2:
        case 13:
            if (apOwner)
                fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x11);
            break;
        case -1:
        case 0:
            if (apOwner)
                fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x38);
            break;
        }
    }
    else if (apOwner)
    {
        fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x38);
    }

    float fSkillMultA = 1.0f;
    if (apOwner && (!apWeapon || DmgIsSkillBased(apWeapon)))
        fSkillMultA = GetArmCondition(apOwner, apWeapon ? apWeapon->GetWeaponType() : 0) * *g_kDmgSkillMultA.Float() +
                      *g_kDmgSkillMultB.Float();

    float _fSkill = apOwner ? apOwner->GetActorValueFloatByIndex((ActorValue::Index)iSkillB) : g_fDmgDefaultSkill;
    float fSkillDamage5 = fSkillMultA;
    if (apWeapon && apWeapon->GetWeaponType())
        fSkillDamage5 = *g_kDmgConditionBase.Float() + *g_kDmgConditionMult.Float() * (0.01f * _fSkill) * fSkillMultA;
    float kFDamage = fSkillDamage5 * afMult;

    float fAmmoBonus6 = 0.0f;
    if (!abNoAmmo && apWeapon && apWeapon->GetAmmo(abUseActor ? apOwner : 0) &&
        apWeapon->GetAmmo(abUseActor ? apOwner : 0)->GetEffect())
    {
        fAmmoBonus6 = DmgAmmoEffectMult(apWeapon->GetAmmo(abUseActor ? apOwner : 0)->GetEffect()) *
                      apWeapon->GetDamageForActor(apItem ? apItem->SetEquipmentState(0xc) : false, false,
                                                  abUseActor ? dynamic_cast<Actor*>(apOwner) : 0);
    }

    float fTimeMult3 = 1.0f;
    float fHealthMult3 = 1.0f;
    fHealthMult3 = GetWeaponHealthConditionMultiplier(afCondition);
    float fTeammateMult = 1.0f;
    Actor* pActor4 = dynamic_cast<Actor*>(apOwner);
    if (pActor4 && pActor4->IsPlayerTeammate())
    {
        float fPlayerLevel_ = g_pDmgPlayer->GetActorValueFloatByIndex((ActorValue::Index)8);
        fTeammateMult = 1.0 + fPlayerLevel_ * (double)0.05f;
    }
    if (apWeapon && apWeapon->GetIsAutomaticWeapon() && DmgIsSkillBased(apWeapon))
    {
        if (!g_kDmgVATS.IsActive() || pActor4 != g_pDmgPlayer)
            fTimeMult3 = g_kDmgTimeGlobal.GetTimeMult();
    }
    return ((fBaseDamage4 + fAmmoBonus6) * kFDamage + fBonus6) * fHealthMult3 * fTimeMult3 * fTeammateMult;
}

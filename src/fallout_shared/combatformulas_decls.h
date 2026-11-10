#pragma once

class CombatDamageCalculator
{
  public:
    static float CalculateWeaponDamage(ActorValueOwner*, TESObjectWEAP*, float, bool, InventoryStackRecord*, bool, bool, int,
                                       float, float, bool, bool, TESAmmo*);
    static float CalculateWeaponDamageForActor(TESObjectREFR*, TESObjectWEAP*, bool, InventoryStackRecord*);
    static float GetWeaponConditionDamageMultiplier(int);
    static float CombatFormulas_GetBodyPartCondition(ActorValueOwner*, ActorValue::Index, bool);
    static float CombatFormulas_GetRandomBetween(float, float);
    static float CalculateArmorDamageThreshold(unsigned short rating, float condition);
};


// src/fallout_shared/tesnpc_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006047c0: the skeleton of src/fallout_shared/tesnpc.cpp
// with declarations corrected to what the original code does (tesnpc_pc_decls.h: TESNPC += void InitDefaultWorn(TESObjectREFR* pRef, bool b1, bool b2, bool b3, bool b4);). Move the function to its real unit once
// that unit declares it this way.

#include "tesnpc_pc_decls_decl_tesnpc.h"

// @fnv 0x006047c0
void TESNPC::InitDefaultWorn(TESObjectREFR* a2, bool a3, bool a4, bool a5, bool a6)
{
    InventoryChanges* j;
    InventoryStackRecord* item;
    bool bAllowed;
    bAllowed = true;
    if (a6 == 0)
    {
        bAllowed = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    }
    if (a2->IsActor())
    {
        a2->FUN_00571b50();
    }
    j = InventoryChanges::GetOrAddInventoryChanges(a2);
    j->RemoveWornItems(true, a2);
    Actor* pBiped;
    pBiped = (Actor*)a2;
    if (pBiped->GetProcess())
    {
        pBiped->GetProcess()->SetCurrentAmmunition(NULL);
        pBiped->GetProcess()->SetCurrentShield(NULL);
        pBiped->GetProcess()->SetCurrentTorch(NULL);
        pBiped->GetProcess()->SetCurrentArmor(NULL, NULL, false);
    }
    TESBipedModelForm* res = NULL;
    ExtraDataList* pExtra = NULL;
    for (int i = 0; i < 20; i++)
    {
        item = j->FindBestArmor(this, i, true);
        if (item)
        {
            bool val = true;
            TESBoundObject* p;
            p = item->FUN_0044ddc0();
            if ((!res || !res->HasBipedModel(i, false, NULL)) && !a2->FUN_00575400(p))
            {
                if (item->FUN_00559450())
                {
                    pExtra = item->FUN_00559450()->GetItem();
                }
                else
                {
                    pExtra = NULL;
                }
                if (i == 2)
                {
                    res = dynamic_cast<TESBipedModelForm*>(p);
                }
                else
                {
                    TESBipedModelForm* pInv;
                    pInv = TESBipedModelForm::GetFormAsBipedModel(p);
                    if (pInv->HasBipedModel(2, false, NULL))
                    {
                        val = false;
                    }
                }
                if (val)
                {
                    a2->EquipItem(p, 1, pExtra, false);
                }
            }
            delete item;
            item = NULL;
        }
    }
    if (a4 && !a2->HasHealth(false))
    {
        float cnt;
        cnt = 0.0f;
        InventoryStackRecord* pWeaponExtra;
        pWeaponExtra = j->GetBestWeapon(this, &cnt, 6, true);
        if (pWeaponExtra)
        {
            bool pItem = true;
            if (!a2->FUN_00575400(pWeaponExtra->FUN_0044ddc0()))
            {
                ExtraDataList* fWeight;
                fWeight = NULL;
                if (pWeaponExtra->FUN_00559450())
                {
                    fWeight = pWeaponExtra->FUN_00559450()->GetItem();
                    pItem = false;
                }
                else
                {
                    fWeight = NULL;
                }
                TESObjectREFR* bEquipWeapon;
                bEquipWeapon = a2;
                bEquipWeapon->EquipObject(pWeaponExtra->FUN_0044ddc0(), pWeaponExtra->FUN_00726070(), fWeight, true,
                                          false, true);
                if (pItem)
                {
                    delete pWeaponExtra;
                }
            }
            else if (((Actor*)a2)->GetProcess())
            {
                if (pWeaponExtra->FUN_0044ddc0() != ((Actor*)a2)->GetActiveWeapon())
                {
                    ((Actor*)a2)->GetProcess()->SetCurrentArmor(pWeaponExtra, a2->GetNiNode(), false);
                }
            }
        }
    }
    if (a6 == 0)
    {
        g_BGSSaveLoadGame->SetThreadAllowChanges(bAllowed);
    }
    if (pBiped->GetProcess())
    {
        pBiped->UpdateSpells(true);
    }
}


// src/fallout/magic/activeeffect_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00805920: the skeleton of src/fallout/magic/activeeffect.cpp
// with declarations corrected to what the original code does (activeeffect_local.h: virtual void LoadGame(Actor* apActor); -> virtual void @@LGTMP@@;; activeeffect_local.h: virtual void LoadGame(BGSLoadFormBuffer* apBuf -> virtual void LoadGame(Actor* apActor);; activeeffect_local.h: virtual void @@LGTMP@@; -> virtual void LoadGame(BGSLoadFormBuffer* apBuf). Move the function to its real unit once
// that unit declares it this way.

#include "activeeffect_local_decl_activeeffect.h"
class ActiveEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* pBuffer);
};
class MagicCaster
{
  public:
    MagicItem* GetSelectedMagicItem();
    static MagicCaster* GetCasterByHandle(unsigned int id);
};
class MagicTarget
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual bool IsActor();
    char data[12];
    static int CompareActiveEffects(ActiveEffect*, ActiveEffect*);
    static MagicTarget* GetMagicTargetByID(unsigned int id);
};
class MagicItem
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual MagicSystem__SpellType GetSpellType();
    char prefix[8];
    EffectItemList effects;
    static MagicItem* GetMagicItemByID(unsigned int id);
};
class Actor : public ActorPrimary, public MagicTarget, public ActorValueOwner
{
};
class SpellItem : public MagicItem
{
};
class AlchemyItem : public MagicItem
{
  public:
    void* FUN_004030b0();
};
class MagicHitEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void InitLoadGame(BGSLoadFormBuffer* pBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);
};
class ActiveEffectLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
class ActiveEffectInitLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void InitLoadGame(Actor*);
};
void InitLoadGameForEffects(Actor* pActor, BSSimpleList<ActiveEffect*>* pList);

class TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
    void LoadGameDataOLD(void*, unsigned int);
    void FUN_00857aa0(unsigned int*, unsigned int);
    void FUN_00857bd0(unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern const char DAT_010793e0[];
void FNV_Warning(const char*, ...);
// @fnv 0x00805920
ActiveEffect* LoadActiveEffect(BGSLoadFormBuffer* buffer)
{
    unsigned short effectSize = 28;
    unsigned int magicItemID;
    unsigned char recordIndex;
    MagicItem* magicItem;
    if (g_TESSaveLoadGame->FUN_008df040() >= 42)
        g_TESSaveLoadGame->LoadGameDataOLD(&effectSize, 2);
    g_TESSaveLoadGame->FUN_00857aa0(&magicItemID, 4);
    g_TESSaveLoadGame->LoadGameDataOLD(&recordIndex, 1);
    magicItem = MagicItem::GetMagicItemByID(magicItemID);
    if (magicItem)
    {
        EffectItem* effect = magicItem->effects.GetEffectItemAtIndex(recordIndex);
        if (effect)
        {
            ActiveEffect* active = MagicEffectSystem::Activate(0, magicItem, effect, 0);
            active->LoadGame(buffer);
            return active;
        }
    }
    g_TESSaveLoadGame->FUN_00857bd0(effectSize);
    FNV_Warning(DAT_010793e0, magicItemID, recordIndex);
    return 0;
}

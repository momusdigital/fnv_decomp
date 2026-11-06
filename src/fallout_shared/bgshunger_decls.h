// fallout_shared/bgshunger_decls.h: declares HungerStageData, BGSHungerStage, BGSDehydrationStage, SpellItem
#ifndef FNV_BGSHUNGER_DECLS_H
#define FNV_BGSHUNGER_DECLS_H


#include "TESForm.h"

class SpellItem;

// Shared endian helper already bound by the stage loader in canonical source.
class FUN_005a71d0
{
  public:
    unsigned int m_uiStageLevel;
    SpellItem* m_pSpell;
    void FUN_00462230();
};

class HungerStageData
{
  public:
    unsigned int m_uiStageLevel;
    SpellItem* m_pSpell;
};

class BGSHungerStage
{
  public:
    TESForm form;
    FUN_005a71d0 data;
    void ClearData();
    static void ClearStageData(BGSHungerStage*);
    bool Load(TESFile* file);
    void InitItem();
    HungerStageData* FUN_00500940();
};

// These shared stage helpers retain their canonical decorated bindings.
class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int);
    void* FUN_00500940(unsigned int size);
    void LoadData(TESFile* file, void* data);
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem* spell);
};

class SpellItem : public TESForm
{
};
void InsertHungerStage(BGSHungerStage* stage);

FNV_STATIC_ASSERT(sizeof(BGSHungerStage) == 32);
FNV_STATIC_ASSERT(offsetof(BGSHungerStage, data) == 24);

#endif

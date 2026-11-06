// fallout_shared/bgssleepdeprevation.h: declares SpellItem, SpellItemValueEntry, TESFormInitFlag, BGSSleepDeprevationStage, BGSDehydrationStage
#ifndef FNV_BGSSLEEPDEPREVATION_H
#define FNV_BGSSLEEPDEPREVATION_H


#include "TESForm.h"

class SpellItem : public TESForm
{
  public:
    virtual ~SpellItem();
    char _pdbpad_18[28];
    char data_db[16];
};

class SpellItemValueEntry
{
  public:
    unsigned int m_uiSpellValue;
    SpellItem* m_pSpell;
};

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};

class BGSSleepDeprevationStage
{
  public:
    unsigned int formPrefix[5];
    SpellItemValueEntry data;

    static void ClearStageData(BGSSleepDeprevationStage* stage);
    void ClearData();
    void InitItem();
    virtual bool Load(TESFile* file);
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem* sickness);
};

void FUN_00402550(BGSSleepDeprevationStage* stage);

class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
    void LoadData(TESFile* file, void* buffer);
    void* FUN_00500940(unsigned int size);
};

class FUN_005a71d0
{
  public:
    void FUN_00462230();
};

extern "C" unsigned int DAT_011c31b0;
extern "C" BGSSleepDeprevationStage** DAT_011c31b4;

void operator delete(void* pointer);

#endif

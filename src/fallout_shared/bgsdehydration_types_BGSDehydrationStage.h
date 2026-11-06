// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDEHYDRATIONSTAGE_H
#define FNV_BGSDEHYDRATIONSTAGE_H

class SpellItem;
#include "layout_support.h"
#include "TESForm.h"
class BGSDehydrationStage;
class StageRecordData;
#pragma pack(push, 4)
class StageRecordData
{
  public:
    unsigned int m_uiStageIndex;  // +0x0, 4 bytes
    SpellItem* m_pSpell;          // +0x4, 4 bytes
    // void __cdecl StageRecordData::*()
    // void __cdecl StageRecordData::*()
    // void __cdecl StageRecordData::*()
};
class FUN_005a71d0 : public StageRecordData
{
  public:
    FUN_005a71d0();
    void FUN_00462230();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(StageRecordData) == 8);
FNV_STATIC_ASSERT(sizeof(FUN_005a71d0) == 8);
FNV_STATIC_ASSERT(offsetof(StageRecordData, m_uiStageIndex) == 0);
FNV_STATIC_ASSERT(offsetof(StageRecordData, m_pSpell) == 4);
#pragma pack(push, 4)
class BGSDehydrationStage : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    FUN_005a71d0 data;  // +0x18, 8 bytes
    // BGSDehydrationStage
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // bool __cdecl BGSDehydrationStage::*(TESFile*)
    // void __cdecl BGSDehydrationStage::*(TESForm*)
    // bool __cdecl BGSDehydrationStage::*(TESForm*)
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // StageRecordData* __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*()
    // SpellItem* __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(SpellItem*)
    // unsigned int __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(unsigned int)
    // unsigned int __cdecl BGSDehydrationStage::*()
    // BGSDehydrationStage* __cdecl BGSDehydrationStage::*(unsigned int)
    // BGSDehydrationStage* __cdecl BGSDehydrationStage::*(float)
    // BGSDehydrationStage** __cdecl BGSDehydrationStage::*(unsigned int)
    // void __cdecl BGSDehydrationStage::*()
    // void __cdecl BGSDehydrationStage::*(BGSDehydrationStage*)
    // ClearStageData
    // BGSDehydrationStage& __cdecl BGSDehydrationStage::*(const BGSDehydrationStage&)
    // void __cdecl BGSDehydrationStage::*()
    static BGSDehydrationStage* GetStage(unsigned int index);
    static BGSDehydrationStage* FindStage(float level);
    void ClearData();
    static void ClearStageData(BGSDehydrationStage* stage);
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
    BGSDehydrationStage();
    void InitItem();
    bool Load(TESFile* file);
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem* spell);
    void* FUN_00500940(unsigned int size);
    void LoadData(TESFile* file, void* data);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDehydrationStage) == 32);
FNV_STATIC_ASSERT(offsetof(BGSDehydrationStage, data) == 24);
#endif

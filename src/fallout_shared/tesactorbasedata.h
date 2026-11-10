// fallout_shared/tesactorbasedata.h: declares ActorBaseAttributes, TESActorBaseData
#ifndef FNV_TESACTORBASEDATA_H
#define FNV_TESACTORBASEDATA_H


#include "layout_support.h"
#include "BaseFormComponent.h"

class TESLevItem;
class BGSVoiceType;
class TESForm;
class FactionReaction;
class TESActorBase;
class TESObjectREFR;
class Actor;
class TESFaction;

#pragma pack(push, 4)
struct ActorBaseAttributes
{
    int m_uiActorFlags;
    unsigned short m_usField04;
    unsigned short m_usField06;
    short sLevel;
    unsigned short m_usField0A;
    unsigned short m_usField0C;
    unsigned short m_usField0E;
    float m_fField10;
    unsigned short m_usField14;
    short m_usField16;
};

class TESActorBaseData : public BaseFormComponent
{
  public:
    ActorBaseAttributes actorData;
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    BSSimpleList<FactionReaction*> m_pVoiceType;

    bool GetFlag(unsigned int flag) const;

    // BaseFormComponent virtuals:
    // slot 0: Init
    // slot 1: Free
    // slot 2: CopyFromBase
    // slot 3: CompareWithBase

    // slot 4
    virtual void CopyFromTemplateForm(TESActorBase* form);
    // slot 5
    virtual bool GetNoVATSmelee() const;
    // slot 6
    virtual bool GetAllowPCDialogue() const;
    // slot 7
    virtual bool GetAllowPickpocket() const;
    // slot 8
    virtual bool GetIsGhost() const;
    // slot 9
    virtual bool GetIsInvulnerable() const;
    // slot 10
    virtual bool GetNoKnockdowns() const;
    // slot 11
    virtual bool GetCanBeAllRaces() const;
    // slot 12
    virtual bool GetNoHeadTracking() const;
    // slot 13
    virtual bool GetNoPersuasion() const;
    // slot 14
    virtual bool GetNoLeftArm() const;
    // slot 15
    virtual bool GetNoRightArm() const;
    // slot 16
    virtual bool GetNoHead() const;
    // slot 17
    virtual bool GetNoShadow() const;
    // slot 18
    virtual bool GetNoBloodSpray() const;
    // slot 19
    virtual void SetNoBloodSpray(bool value);
    // slot 20
    virtual bool GetNoBloodDecal() const;
    // slot 21
    virtual void SetNoBloodDecal(bool value);
    // slot 22
    virtual unsigned int GetBloodImpactMaterial() const;
    // slot 23
    virtual void SetBloodImpactMaterial(unsigned int material);
    // slot 24
    virtual unsigned short GetFatigue() const;
    // slot 25
    virtual float GetHealthRegeneration() const;
    // slot 26
    virtual BGSVoiceType* GetVoiceType() const;
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(ActorBaseAttributes) == 24);
FNV_STATIC_ASSERT(sizeof(TESActorBaseData) == 52);

// @fnv 0x0047c7d0
bool TESActorBaseData::GetIsGhost() const
{
    return GetFlag(0x20000000);
}

// @fnv 0x0047c7f0
bool TESActorBaseData::GetIsInvulnerable() const
{
    return GetFlag(0x80000000);
}

// @fnv 0x0047c810
bool TESActorBaseData::GetNoKnockdowns() const
{
    return GetFlag(0x400000);
}

// @fnv 0x0047c830
bool TESActorBaseData::GetNoHeadTracking() const
{
    return GetFlag(0x800000);
}

// @fnv 0x0047c860
float TESActorBaseData::GetHealthRegeneration() const
{
    return actorData.m_fField10;
}

// @fnv 0x004a8ae0
unsigned short TESActorBaseData::GetFatigue() const
{
    return actorData.m_usField04;
}

#endif

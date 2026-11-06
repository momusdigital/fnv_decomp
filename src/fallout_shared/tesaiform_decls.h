// fallout_shared/tesaiform_decls.h: declares PackageList, PackedRecordData, TESAIForm, Actor, BGSCameraPath and more

#include "BaseFormComponent.h"
class TESPackage;
class Actor;
class TESActorBase;
template <class T> class BSSimpleList;
class PackageList
{
  public:
    unsigned char data[8];
    void ClearPackageList();
    TESPackage* GetPackageForActor(Actor*);
    void CollectEligiblePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
};
struct PackedRecordData
{
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned char pad[3];
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
class TESAIForm : public BaseFormComponent
{
  public:
    unsigned char aggression, confidence, energy, responsibility, mood, pad[3];
    unsigned int services;
    unsigned char skill, level, assistance;
    bool radius;
    unsigned int distance;
    PackageList packages;
    void FreeDataComponent();
    void BaseFormRecord(BaseFormComponent*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(const TESAIForm*);
    void CopyAIDataFromAIDATA(PackedRecordData*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
    void InitializeComponent();
    unsigned char GetAssistance();
    unsigned char GetResponsibility();
    unsigned char FUN_004f6de0();
    unsigned char GetMood();
    void SetAggression(unsigned char, bool);
    void SetAssistance(unsigned char);
    void SetConfidence(unsigned char, bool);
    void SetEnergy(unsigned char, bool);
    void SetResponsibility(unsigned char, bool);
    void SetAIMood(unsigned char);
    void SetHasAggroRadius(bool);
    void SetAggroRadius(unsigned int);
    void SetServiceFlags(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    void SetTrainingSkillLevel(unsigned char);
    void DispatchToOuter(int);
};
class Actor
{
  public:
    TESActorBase* GetActorBase();
};
class PerkEntryConditionSet;
class BGSCameraPath
{
  public:
    PerkEntryConditionSet* GetConditions();
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    char opaque[16];
};
class GlobalObject_0040e0b0
{
  public:
    char opaque[16];
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting26, originalRuntimeFloatSetting27,
    originalRuntimeFloatSetting28;
extern GlobalObject_0040e0b0 g_011c52e4, g_011c52fc;
extern float DAT_011c52a8, DAT_011c52ac, DAT_011c52b0, DAT_011c52b4, DAT_011c52b8;
extern bool DAT_011c52c0;
class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};
class BSAudio
{
  public:
    bool FUN_005bb4d0();
};
class ActiveEffect
{
  public:
    bool FUN_00705cf0();
    bool GetByteAtOffset17();
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
class TESForm
{
  public:
    unsigned int GetFormID();
};
namespace ActorValue {
enum Index;
bool IsSkill(Index);
}
// fallout_shared/tesnpc_pc_decls_decl_tesnpc.h: declares TESFullNameLoader, TESForm, TESBoundObject, TESObjectREFR, MobileObject and more
#ifndef TESNPC_PC_DECLS_H
#define TESNPC_PC_DECLS_H

// PC call-site declarations for this translation unit.
// Shared classes come from the canonical include/ headers (explicit ../../include/ paths: src/fallout_shared has
// case-insensitive look-alike stubs): layout_support, BaseFormComponent, BaseProcess (all 493 PC virtuals),
// ActorValueOwner, AutoMemContext, SETTING_VALUE, BSAudio, TESFile.
// Unit-local on purpose (canonical headers lack members the matched functions call; listed for the header owner):
//     GetDataSizeAdjustment/ReadTypedData; TESObjectREFR/Actor lack the non-virtual helpers and typed slots used here.
//   NiPointer, BSSimpleArray: out-of-line ctor/operator= calls (canonical versions are inline or have no ctor).
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#include "../../include/layout_support.h"
#undef BSSimpleArray
#undef NiPointer
template <class T> class NiPointer;
#include "../../include/BaseFormComponent.h"
#include "../../include/BaseProcess.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/AutoMemContext.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/BSAudio.h"
#include "../../include/TESFile.h"
class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
class TESObjectWEAP;
class QuestDialogueInfo;
class TESPackage;
class TESTopic;
class ExtraDataList;
class TESObjectARMO;
class TESDialoguePackage;
namespace ActorValue {
enum Section
{
    Attributes = 0,
    Skills = 2
};
Index GetActorValueForSectionIndex(Section, unsigned char);
bool GetFlag(Index, unsigned int);
bool IsSkill(Index);
}
class TESForm;
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool Load(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    ENUM_FORM_ID GetFormType() const;
    bool IsFormInitialized() const;
    TESForm();
    static TESForm* GetFormByID(unsigned int auiFormID);
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    unsigned int GetDataSizeAdjustment();
    void ReadTypedData(TESFile*, void*, unsigned short);
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};

#include "../../include/NiPoint3.h"
class ExtraDismemberedLimbs;
class InventoryStackRecord;
class TESBipedModelForm;
class BSFaceGenAnimationData;
class ActorAnimData;
class NiDefaultAVObjectPalette;
class NiAVObject;
class TESActorBase;
class TESNPC;
class TESRace;
class TESHair;
class TESEyes;
class TESCombatStyle;
class BGSHeadPart;
class BSFaceGenNiNode;
class BipedAnim;
class BaseProcess;
class CombatController;
class TESClass;
class BGSLoadFormBuffer;
class PlayerQuestData;
enum SEX
{
    MALE,
    FEMALE
};
class TESBoundObject : public TESForm
{
  public:
    unsigned char boundData[24];
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160(InventoryStackRecord*, int, bool);
    virtual void vfn_164(int);
    virtual void vfn_168(int);
    virtual void vfn_16c(int);
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual TESObjectREFR* RemoveItem(TESForm*, void*, int, bool, int, Actor*, void*, void*, bool, bool);
    virtual void vfn_180();
    virtual void EquipItem(TESBoundObject*, int, ExtraDataList*, bool);
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual ActorAnimData* GetAnimData();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void SetBipedAnim(BipedAnim*);
    virtual NiPoint3* GetPos();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual int GetSitSleepState();
    virtual bool IsCharacter();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool HasHealth(bool);
    virtual bool GetHasKnockedState();
    virtual bool GetIsParalyzed();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual bool vfn_280(Actor*, int, int, int, int, int, int, int, int);
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void SetExtraRunOncePacks(TESPackage*, unsigned char);
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual Actor* GetCurrentTarget();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool GetIsDying();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual unsigned char IsGuard();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void InitGetUpPackage();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual CombatController* GetCombatController();
    unsigned char refrData[0x68 - 0x18];
    ExtraDataList* GetExtraData();
    const char* GetFullName();
    NiAVObject* Get3DSimple();
    float GetHealth();
    void FUN_00571b50();
    bool FUN_00575400(TESBoundObject*);
    void EquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool, bool);
    void UpdateSpells(bool);
    bool GetIsUnconscious();
    int IsFleeing();
    bool IsBlocking();
    bool IsMovementActive();
    bool SetReferenceHeading(NiPoint3, bool);
    void SetReferenceState(TESTopic*, bool, bool);
    void StopAttack();
    void ClearReferenceState(TESBoundObject*);
    TESBoundObject* GetObjectReference();
    void ForceIdleAnimation();
    void InitializeReference(TESObjectREFR*, TESBoundObject*, int);
};
class MobileObject : public TESObjectREFR
{
  public:
    unsigned char mobileData[32];
    const char* GetFullName();
    bool IsCombatStateActive() const;
};
class MagicCaster
{
  public:
    virtual void vfn_0();
    unsigned char casterData[8];
    void RemoveCastingArt();
};
class Actor : public MobileObject, public MagicCaster
{
  public:
    BaseProcess* GetProcess();
    TESPackage* GetCurrentPackage();
    TESObjectWEAP* GetActiveWeapon();
    bool FUN_00437bd0();
    bool FUN_00437bf0();
    bool IsSneaking();
    bool IsPlayerTeammate();
    bool FUN_00608d80();
    bool IsEssentialActor();
    bool IsInDeadState();
    bool IsWithinRadius(int);
    bool GetGhost();
    bool IsHostileToActor(Actor*, int, int*, bool);
    bool HasEssentialStatus();
    unsigned char actorData[0xac - 0x94];
    BSFaceGenAnimationData* pFaceGenAnimationData;
    unsigned char actorTail[0x20c - 0xb0];
    bool bPreventActivation;
};
class PlayerCharacter : public Actor
{
  public:
    TESActorBase* GetActorBase();
    BipedAnim* GetBipedAnim(bool);
    bool HasCombatState();
};
class TESObjectARMO : public TESBoundObject
{
};
class TESObjectWEAP : public TESBoundObject
{
};
class TESDialoguePackage;
class TESPackage
{
  public:
    virtual ~TESPackage();
    unsigned char packageData[0xa];
    unsigned char m_cEventActionValue;
    unsigned char packageTail[0x8c - 0xf];
    TESTopic* pTopic;
    int GetPackType();
    bool IsMustReachLocation();
    bool IsPackageBlockingGreeting();
    bool RunPackage();
    bool FUN_00441b00();
    bool FUN_006727b0();
    BSSimpleList<Actor*>* FUN_0041d8a0();
};
class TESDialoguePackage : public TESPackage
{
};
class CombatController
{
  public:
    bool GetLoading();
    bool SetActive(Actor*);
};
class ExtraDataList
{
  public:
    ExtraDismemberedLimbs* GetDismemberedLimbs();
    TESPackage* GetPackageOverride();
    Actor* GetTalkingActor();
    void SetPackageOverride(TESPackage*, int, Actor*, bool, bool, bool);
};
class Calendar
{
  public:
    unsigned char GetDayOfMonth();
    float GetGameTime();
};
extern Calendar g_calendar;
class SettingActivationText
{
  public:
    const char* IsContentAvailable();
};
extern SettingActivationText DAT_011d210c, DAT_011d2538, DAT_011d2394, DAT_011cf594;
class ActivationMenuState
{
  public:
    void SetEquipmentState(int, int);
};
extern ActivationMenuState DAT_011f2250;
class DialogueItem
{
  public:
    ~DialogueItem();
    TESTopic* Deallocate();
    bool SelectDefaultResponseList();
    bool NextResponse();
};
class TESTopic
{
  public:
    static TESTopic* GetAudioBackendData(int, int);
    DialogueItem* CreateDialogueItem(Actor*, Actor*, TESTopic*, BSSimpleList<Actor*>*, bool);
    bool IsRemappedRumors() const;
};
BSAudio* GetAudioSystem();
extern PlayerCharacter* g_thePlayer;
bool GetShouldCompanionWheelOpen(Actor*);
void OpenDialogueMenu(int, TESObjectREFR*, TESTopic*, void*, int, bool);
bool ShowMessage(const char*, int, const char*, const char*, float, bool);
int FUN_00702640();
extern "C" int sprintf(char*, const char*, ...);
class ContainerItemExtra
{
  public:
    TESForm* m_pForm;
    int m_cRank;
    float m_fHealth;
    ContainerItemExtra();
    bool Load(TESFile*);
};
struct InventoryItemEntry
{
    int iCount;
    TESForm* pForm;
    ContainerItemExtra* pExtra;
    void FUN_00462230();
};
struct ContainerItem
{
    int iCount;
    unsigned int iFormID;
    void FUN_00462230();
};
extern InventoryItemEntry* DAT_011cb7d8;
struct ActorBaseAttributes
{
    int m_uiActorFlags;
    unsigned short m_usField04, m_usField06, sLevel, m_usField0A, m_usField0C, m_usField0E;
    float m_fField10;
    unsigned short m_usField14, m_usField16;
    void SwapEndianness();
};
struct PackedRecordData
{
    unsigned char m_ucField00, m_ucField01, m_ucField02, m_ucField03;
    unsigned char m_ucField04;
    unsigned int m_uiField08;
    unsigned char m_ucField0C, m_ucField0D, m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
    void SwapEndianFields();
};
struct FactionReaction
{
    TESFaction* pFaction;
    char m_ucRank;
    void Endian();
};
class TESActorBaseData : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual bool vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual unsigned int vfn_58();
    virtual void vfn_5c(unsigned int);
    unsigned short FUN_0047ded0();
    ActorBaseAttributes actorData;
    TESForm* m_pBaseTemplateForm;
    TESForm* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    BSSimpleList<FactionReaction*> m_pVoiceType;
    void UpdateFlagBit(int, bool);
    void SetFactionRank(TESFaction*, char);
    unsigned short GetShortAtOffset12();
    void UpdateFlagBit(int, bool, bool);
    bool GetFlag(unsigned int) const;
};
class TESContainer : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned int count;
    InventoryItemEntry** objects;
    InventoryItemEntry* AddContainerObject(ContainerItem*);
};
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned int pSpell;
    unsigned short usValue, pad;
    void Initialize(unsigned int);
    void FUN_00483170(unsigned short);
};
class TESSpellList : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned char listData[16];
    void FUN_0048d290(unsigned int);
};
class TESAIForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    PackedRecordData m_kAIData;
    unsigned char packages[8];
    void FUN_0047f0b0(PackedRecordData*);
    void FUN_0047f500(unsigned int);
    void SetServiceFlags(unsigned int, bool);
    void FUN_0047ef50(int, bool);
    void FUN_0047ee00(int, bool);
    void FUN_0047eed0(int, bool);
    void FUN_0047ef00(int, bool);
};
class TESHealthForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    int health;
    void FUN_006ecd40(int);
    unsigned int FUN_00726070();
};
class TESAttributes : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned char attributes[8];
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(ActorValue::Index, unsigned char, bool);
};
class TESAnimation : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<const char*> m_kKFFileList;
    void BaseFormRecord(TESAnimation*, TESFile*);
};
class TESFullName : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSStringT<char> m_kName;
    static const char* GetFullName(TESForm*);
    const char* GetFullName();
};

class TESModel : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned char modelData[20];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned int script;
    unsigned char data[4];
    void Initialize(unsigned int);
    void InitItem(TESForm*);
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    void* pData;
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
};
class TESRaceForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    TESRace* m_pRace;
    TESRaceForm();
    TESRace* GetFormRace() const;
    void Initialize(unsigned int);
    void SetFormRace(TESRace*);
};
class TESActorBase : public TESBoundObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual bool vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160(InventoryStackRecord*, int, bool);
    virtual void vfn_164(int);
    virtual void vfn_168(int);
    virtual void vfn_16c(int);
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void EquipItem(TESBoundObject*, int, ExtraDataList*, bool);
    virtual TESCombatStyle* GetCombatStyle();
    virtual void SetCombatStyle(TESCombatStyle*);
    TESActorBase();
    ~TESActorBase();
    void SetEssentialState(bool);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    SEX GetSex();
    void Copy(TESForm*);
    void InitItem();
    TESClass* GetClass();
    bool ShouldUseDefaultAppearance(TESObjectREFR*);
};
struct FaceGenCoordinateValue
{
    float* value;
    unsigned int offset;
    const float* FUN_00629ab0();
};
class FaceGenCoordinateBasis
{
  public:
    FaceGenCoordinateValue FUN_0060b370(unsigned int, unsigned int);
};
template <class T> class FaceGenMatrix : public FaceGenCoordinateBasis
{
  public:
    unsigned char vectorData[24];
    unsigned int m_uiRowCount, m_uiColumnCount;
    FaceGenMatrix();
    ~FaceGenMatrix();
    void SetDimensions(unsigned int, unsigned int);
    void FUN_0060b3b0();
    unsigned int FUN_009611e0();
    unsigned int FUN_00441110();
    FaceGenMatrix& operator=(const FaceGenMatrix&);
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    NiPointer& operator=(NiPointer&);
    operator T*() const;
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    virtual void vfn_0();
    T* pBuffer;
    unsigned int iSize, SimpleArrayStorage;
    BSSimpleArray();
    BSSimpleArray(unsigned int, bool);
    ~BSSimpleArray();
    unsigned int Add(T&);
    unsigned int Find(T&, unsigned int, bool(__cdecl*)(T&, T&));
    void RemoveAt(unsigned int, bool);
    unsigned int GetSize();
};
class NiTexture;
class FaceGenUndo;
class TESRace : public TESForm
{
  public:
    TESHair* FUN_00613870(SEX);
    float GetHeight(SEX);
    float GetWeight(SEX);
    bool BuildFaceGenHead(BSFaceGenNiNode*&, BSFaceGenNiNode*&, TESNPC*, bool, bool, SEX);
    unsigned short FUN_00607350();
    FaceGenMatrix<float> (*GetMeanFaceCoord(SEX))[2];
};
class TESClass : public TESForm
{
  public:
    unsigned char classData[0x38 - 0x18];
    TESAttributes classAttributes;
    bool IsTagSkill(ActorValue::Index);
    unsigned int FUN_006286d0();
};
class TESHair : public TESForm
{
};
class TESEyes : public TESForm
{
};
class BGSHeadPart : public TESForm
{
};
class TESCombatStyle : public TESForm
{
};
struct ActorSkillData
{
    unsigned char skills[14];
    unsigned char skillOffsets[14];
};
struct TESNPCFaceCoordinates
{
    FaceGenMatrix<float> matrices[2][2];
};
class TESNPC : public TESActorBase, public TESRaceForm
{
  public:
    void FUN_006047c0(TESObjectREFR* pRef, bool b1, bool b2, bool b3,
                      bool b4);  // declared for the original code (decl_variants.py) public:
    ActorSkillData data;
    TESClass* m_pClass;
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    FaceGenMatrix<float> (*m_pOffsetFaceCoordinates)[2];
    TESHair* m_pHair;
    float m_fHairLength;
    TESEyes* m_pEyes;
    NiPointer<BSFaceGenNiNode> m_pkPrimaryFaceGenNode, m_pkSecondaryFaceGenNode;
    NiPointer<NiTexture> m_pkFaceGenTexture;
    unsigned short m_usLastRace;
    unsigned short lastRacePadding;
    TESCombatStyle* m_pCombatStyle;
    unsigned int iHairColor;
    BSSimpleList<BGSHeadPart*> m_kHeadPartList;
    int m_eImpactMaterial;
    unsigned int m_ulTopicFlags;
    TESRace* m_pAssignedRace;
    TESNPC* m_pTemplateNPC;
    float m_fGlyphExtent, fWeight;
    BSSimpleArray<FaceGenUndo*, 1024> undoStates;
    TESNPC();
    ~TESNPC();
    bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool Load(TESFile*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void UpdateActorFaceGen(TESObjectREFR*, BipedAnim*, BSFaceGenNiNode*, BSFaceGenNiNode*);
    void UpdateModel3D(TESObjectREFR*, bool, bool, bool, bool);
    void UpdateActorBaseData(bool);
    void RebuildHeadModel(TESObjectREFR*, BipedAnim*, bool);
    void InitItem();
    void AttachHeadParts(TESObjectREFR*, NiNode*);
    void ResetFormData();
    void ClearData();
    void Copy(TESForm*);
    void CopyActorBaseData(TESNPC*);
    void CollectNPCsByRaceAndSex(TESRace*, SEX, BSSimpleArray<TESNPC*, 1024>*);
    float FUN_00602130();
    TESEyes* FUN_00602150();
    unsigned int FUN_004169d0();
    void SetField1F0(TESNPC*);
    BipedAnim* GetBipedAnimationForReference(TESObjectREFR*);
    void UpdateHeadParts(TESObjectREFR*, BipedAnim*);
    bool InitWornObject(TESObjectREFR*, BipedAnim*, TESBoundObject*);
    void GetFaceGenNodes(BSFaceGenNiNode*&, BSFaceGenNiNode*&);
    TESHair* GetHair();
    float GetWeight();
    float GetDefaultHeight();
    void GetFaceGenCoords(FaceGenMatrix<float> (&)[2][2]);
    TESRace* GetRace();
    TESCombatStyle* GetCombatStyle();
    void SetCombatStyle(TESCombatStyle*);
    void SetActorValue(ActorValue::Index, int);
    ActorSkillData* GetTextureManager();
    void UpdateBodyModel(TESObjectREFR*, BipedAnim*);
    BSSimpleList<BGSHeadPart*>* FUN_00602170();
    void SetHair(TESHair*);
    void SetEyes(TESEyes*);
    void FUN_00601c10(float);
    void ResetFaceGen();
    void FUN_005f20a0(unsigned char);
    FaceGenMatrix<float> (*GetOffsetFaceCoord())[2];
};
FNV_STATIC_ASSERT(sizeof(TESActorBase) == 0x10c);
FNV_STATIC_ASSERT(offsetof(TESNPC, m_pClass) == 0x130);
FNV_STATIC_ASSERT(offsetof(TESNPC, m_pHair) == 0x1b8);
FNV_STATIC_ASSERT(offsetof(TESNPC, fWeight) == 0x1f8);
class TESFileChunkData16 : public TESFile
{
  public:
    bool GetChunkData(unsigned short*);
};
class TESFileFormVersion : public TESFile
{
  public:
    unsigned short GetFormVersion();
};
// The shared TESFile declaration lacks these methods, so use a private extension.
class TESNPCFileAccess : public TESFileFormVersion
{
  public:
    unsigned int GetOffset();
    const char* GetFilename();
};

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
template <int N> struct EndianSizeTag
{
};
void BSEndian(float*, EndianSizeTag<4>);
void BSEndian(unsigned short*, EndianSizeTag<2>);
TESForm* GetFormByID(unsigned int);
int Warning(const char*, ...);

class FormChangeMask
{
  public:
    unsigned int flags;
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
    FormChangeMask GetOldChangeFlags(unsigned int);
    FormChangeMask GetChangeFlags(unsigned int);
    void ReadTypedData(void*, unsigned int);
    unsigned int ReadFormIdentifier();
    int ReadElementCount();
    bool FUN_0042ce90();
};

bool FUN_009a3830(BGSHeadPart*&, BGSHeadPart*&);
struct FaceGenCoordinates
{
    FaceGenMatrix<float> values[2][2];
};
class BSFaceGenManager
{
  public:
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static void CopyFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2], bool, bool);
    static void BlendFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2],
                                        FaceGenMatrix<float> (*)[2], bool, float);
    static void InitializeFaceGenCoordinates(FaceGenMatrix<float> (*)[2]);
    static char* BuildFaceGenPartPath(char*, int);
};
class NiUpdateData
{
  public:
    float fTime;
    unsigned int flags;
    bool updateControllers;
    NiUpdateData(float, bool, bool);
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    ThreeByThreeMatrix();
};
extern unsigned char DAT_011a9448;
extern "C" const NiPoint3 NiPoint3_ZERO;
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4(float, bool, bool, bool, bool, bool);
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0(bool);
    virtual void vfn_d4();
    virtual void vfn_d8(bool, bool);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual BSFaceGenAnimationData* GetFaceGenAnimationData();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114(bool);
    virtual void vfn_118();
    virtual void vfn_11c(bool);
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128(NiNode*, bool);
    void FUN_00440460(const NiPoint3&);
    void SetLocalRotation(const ThreeByThreeMatrix&);
    void UpdateSceneObject();
    void Update(const NiUpdateData&);
    void FUN_00450f90(bool);
};
class NiNode : public NiAVObject
{
};
class BSFaceGenNiNode : public NiNode
{
};
class ActorAnimData
{
  public:
    class NiControllerManager* FUN_00496940();
};
class NiControllerManager
{
  public:
    NiControllerManager* GetStringAtOffset();
};
class BSFaceGenAnimationData : public NiAVObject
{
  public:
    void FUN_00607830(float);
    void SetBoneMaxAngle(int, float);
    void SetSlotFloats(int, float, float);
};
struct BIPED_OBJECT_DATA
{
    TESBoundObject* pObject;
    void* pItem;
    NiAVObject* p3D;
    NiNode* pBone;
};
enum BIPED_BONE
{
    BIPED_BONE_HEAD = 0
};
class BipedAnim
{
  public:
    BipedAnim(TESObjectREFR*, bool);
    void AddBipedWeapon(TESObjectWEAP*, unsigned char);
    unsigned char bipedData[0x2b4];
    NiNode* GetBoneNode(BIPED_BONE);
    BIPED_OBJECT_DATA* FUN_00606800();
    void UpdateRaceSex(TESRace*, SEX);
};
void AddObjectToPalette(NiAVObject*, NiDefaultAVObjectPalette*);
void ComputeAngleRange(float*, float*);
void ClampMinMaxFromSetting(float*, float*);
void FUN_00649fe0(float*, float*);
void GetEyeAngleLimits(float*, float*);

class BGSSaveLoadGame
{
  public:
    bool SetThreadAllowChanges(bool);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class InventoryStackRecord
{
  public:
    ~InventoryStackRecord();
    TESBoundObject* FUN_0044ddc0();
    int FUN_00726070();
    BSSimpleList<ExtraDataList*>* FUN_00559450();
    void SetEquipmentState(bool, bool);
};
class InventoryChanges
{
  public:
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    void RemoveWornItems(bool, TESObjectREFR*);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
};
class TESBipedModelForm : public BaseFormComponent
{
  public:
    void SetBipedModel(BipedAnim*, SEX, int);
    bool HasBipedModel(int, bool, void*);
    static TESBipedModelForm* GetFormAsBipedModel(TESForm*);
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
    SETTING_VALUE* Float();
    const char* String();
};
extern SettingT_GameSettingCollection_ DAT_011d0e7c, DAT_011cd6c0;
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting327;
int TruncateFloatToInt(float);
double FUN_00404040(float);
int ComputeIntelligenceResult(int, bool);
void GetSkillAttributeAndBase(ActorValue::Index, int*, float*);
class AIFormulas
{
  public:
    static float CalculateSkillValue(float, float, float);
};
struct NPCDefaultSelection
{
    bool useClassDefaults;
    bool isPlayer;
};
struct DismembermentPart
{
    bool bIsBody, bDismembered;
};
class ExtraDismemberedLimbs
{
  public:
    unsigned char extraData[0x20];
    BSSimpleArray<DismembermentPart*, 1024> parts;
    DismembermentPart* GetInfoAt(unsigned int);
};
bool FUN_004abfa0();
extern BSSimpleList<TESNPC*> DAT_011cb764;
TESCombatStyle* FUN_00505000();
class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
const char* FUN_00605d40(bool);
class TESSaveLoadGame
{
  public:
    bool GetLoading();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
class BGSListForm
{
  public:
    BSSimpleList<TESForm*>* GetList();
};
class BGSBipedModelList
{
  public:
    static BGSBipedModelList* GetBipedModelList(TESForm*);
    BGSListForm* GetList();
};
extern const char* DAT_01188b98[];
class TESHairRaceResult
{
  public:
    float FUN_00604210(SEX);
};
class TESHairCanBeNPCData
{
  public:
    TESHairRaceResult* FUN_004ac110();
};
#endif

// fallout_shared/bgsdestructibleobjectform_decls.h: declares TESModel, TESObjectREFR, HUDMainMenu, BGSDestructibleObjectForm, TESForm and more
#ifndef BGSDESTRUCTIBLEOBJECTFORM_DECLS_H
#define BGSDESTRUCTIBLEOBJECTFORM_DECLS_H


class Actor;
class ExtraDataList;
class TESBoundObject;
class TESForm;
class TESFile;
class TESObjectREFR;

class TESModel
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual const char* GetPath();
};

class TESObjectREFR
{
  public:
    ExtraDataList* GetExtraData();
    TESBoundObject* GetObjectReference();
    TESForm* GetOwner();
    TESModel* GetTESModel();
    const char* GetModelFilePath();
    float GetBoundingRadius();
};

class HUDMainMenu
{
  public:
    static void UpdateTargetActor(Actor* actor);
    char _pdbpad_1[39];
    char pTiles_pad27_pad27_pad27[348];
    void* m_pAdditionalHudTile;
    float m_fMessageDisplayTimer;
    char m_kMessageList[8];
    unsigned int m_uiMessageCount;
    char m_kSubtitleArray[16];
    void* m_pCurrentSubtitle;
    char m_kTargetDisplayData[12];
    void* m_pCrosshairReference;
    int m_iHudValueFirstBeforeMode;
    int m_iHudValueSecondBeforeMode;
    int m_eHudMenuMode;
    char m_kMenuData[52];
    bool m_bHudModeActive;
    char _pdbpad_1fd[3];
    void* m_pHudAnimationSequence;
    bool m_bSequenceActive;
    bool m_bHudAnimationActive;
    char _pdbpad_206[2];
    unsigned int m_uiHudAnimationCounter;
    void* m_pRegionObjectListObj;
    int m_iHudValueFirstAfterUpdateList;
    int m_iHudValueSecondAfterUpdateList;
    int m_iHudValueThirdAfterUpdateList;
    void* m_pTargetActor;
    bool m_bTargetActorVisible;
    char _pdbpad_221[3];
    char m_cBuffer[32];
    unsigned int m_uiHudValueFirstAfterActor;
    unsigned int m_uiHudValueSecondAfterActor;
    int m_iHudValueFirstAfterUnsignedValues;
    int m_iHudValueSecondAfterUnsignedValues;
    bool m_bQuestObjectiveUpdatesEnabled;
    char _pdbpad_255[3];
    char m_kQuestObjectives[8];
    bool m_bQuestObjectiveUpdatePending;
    bool m_bXPUpdatePending;
    char _pdbpad_262[2];
    char m_kXPUpdates[8];
    char m_kRadiationUpdates[8];
    float m_fRadiationUpdateTimer;
};

class QueuedFile;
class DestructibleData;
enum IO_TASK_PRIORITY
{
    kPriority
};
class BGSDestructibleObjectForm
{
  public:
    void* vtable;
    DestructibleData* data;
    void InitItem(TESForm*);
    void QueueResourceLoad(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*);
    static void UpdateDestructionMap();
    static void UpdateTargetHealthBar(TESObjectREFR* reference);
};

enum ENUM_FORM_ID
{
    kNone
};
enum SEX
{
    kMale
};
class TESForm
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void UpdateDestructibleObject(float, bool);
    TESFile* GetFile(int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
    unsigned int GetFormID();
    bool GetDisabled();
    bool IsDeleted() const;
    ENUM_FORM_ID GetFormType() const;
};
class TESBoundObject : public TESForm
{
  public:
    float GetBoundSize();
};
class Actor : public TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    virtual void vfn_134();
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
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
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
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
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
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
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
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
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
    virtual void DamageHealthAndFatigue(float, float, Actor*);
};
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class GlobalObject_0045cfe0
{
};
extern GlobalObject_0045cfe0 g_011c3ea4;
class TESFile;
class BGSReconstructFormsInFileMap;
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, TESFile*&, BGSReconstructFormsInFileMap*&);
};
class GlobalObject_00479190
{
};
extern GlobalObject_00479190 g_011c4104;
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueReferenceFloatTask(TESForm*, float, bool);
};
class ExtraDataList
{
  public:
    TESModel* FUN_0042e250();
    unsigned char GetWeaponModIndex();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    TESModel* GetWeaponModel();
    TESModel* GetModTESModel(unsigned char, bool);
};
class TESActorBase : public TESForm
{
  public:
    SEX GetSex();
    int GetHealth();
};
class TESBipedModelForm
{
  public:
    static TESBipedModelForm* GetFormAsBipedModel(TESForm*);
    TESModel* GetWeaponModel(SEX);
};
extern unsigned char DAT_01183108;
extern unsigned char DAT_011831e8;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
class TESObject;
class TES
{
  public:
    static int GetModelResourceType(TESObject*);
};
class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;
class TESModelTextureSwap
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*);
    void InitItem(TESForm*);
};
class BGSExplosion
{
  public:
    unsigned char base[0x64];
    TESModelTextureSwap model;
};
class BGSDebris
{
  public:
    unsigned char base[0x18];
    TESModelTextureSwap model;
};
struct DestructionStage
{
    unsigned char base[8];
    BGSExplosion* explosion;
    BGSDebris* debris;
    unsigned int count;
    TESModel* model;
};
class DestructibleData
{
  public:
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short pad;
    DestructionStage** stages;
};
class ActorValue
{
  public:
    enum Index
    {
        kAV0
    };
};
class ActorValueOwner
{
  public:
    virtual int GetActorValue(ActorValue::Index);
};
class TESAttributes
{
  public:
    unsigned char GetAttributeValue5();
    unsigned char FUN_005f1210();
    unsigned char GetAttributeValue7();
    unsigned char FUN_005f1250();
    unsigned char FUN_005f1270();
    unsigned char GetAttributeValue10();
    unsigned char FUN_005f12b0();
};
class TESAIForm
{
  public:
    bool GetAssistance();
    bool GetResponsibility();
    bool FUN_004f6de0();
    bool GetMood();
};
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
class TESActorBaseData
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual unsigned short vfn_060();
    virtual float vfn_064();
    unsigned short GetShortAtOffset12();
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
int __cdecl Warning(const char*, ...);
#endif

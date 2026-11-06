// fallout/ai/highprocess_decls.h: declares TESObjectCELL, NiPoint3, HighProcessRawPosition, BSAudio, BaseProcess and more
#ifndef FNV_HIGHPROCESS_DECLS_H
#define FNV_HIGHPROCESS_DECLS_H

class NiControllerManager;
class QuestDialogueInfo;
class TESIdleForm;
class TESObjectWEAP;
class NiAVObject;
class BGSLoadFormBuffer;
#define TESObjectCELL HighProcessSharedCell
#include "layout_support.h"
#undef TESObjectCELL
class TESObjectCELL : public HighProcessSharedCell
{
  public:
    bool IsCellInterior() const;
};
#include "ActorPackageContext.h"
class NiPoint3
{
  public:
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_004a7290() const;
    float x, y, z;
    NiPoint3();
    void Set(float, float, float);
    static const NiPoint3 ZERO;
};
struct HighProcessRawPosition
{
    float x, y, z;
};
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    BSSoundHandle__ASSUMED_STATE eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    bool IsSoundPlaying();
    bool IsPlaying();
    void Stop();
};
class BSAudio
{
  public:
    void PausePlayback();
};
class Animation;
class BSAnimGroupSequence;
class NiBSBoneLODController;
class GlobalObject_0045d260;
class HighProcessDetectionEventView;
class DetectionViewData;
class DetectionEvent;
class ActorGroupState;
class ActorValueStore;
class AnimIdle;
class KFModel;
class LipSyncAnimation;
class MuzzleFlash;
class DetectionEventData;
class TopicInfoRecord;
class ActorPathingMessageQueue;
class PathingRequest;
class NiBillboardNode;
class BSBound;
class ActorSupportClass;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class BooleanFloatQuery;
class FurnitureMark;
class bhkCharacterController;
class bhkSimpleShapePhantom;
class MiddleHighProcess__DeferredHideLimb;
class QueuedFile;
class PaddedFloatRecord;
class TESEffectShader;
class ArrowProjectile;
class ActorCombatGroup;
class BaseProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0(int);
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual DetectionViewData* vfn_f0(Actor*, int, bool, int, int, bool, bool);
    virtual void vfn_f4();
    virtual HighProcessDetectionEventView* vfn_f8(Actor*);
    virtual void vfn_fc();
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
    virtual void vfn_130();
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
    virtual bool vfn_1c4();
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
    virtual void vfn_1f0(Actor*);
    virtual bool vfn_1f4(Actor*, Actor*);
    enum POSTANIM_ACTION
    {
        PostAnimNone = 0
    };
    enum HEAD_TRACK_TYPE
    {
        HeadTrackDefault = 0,
        HeadTrackAction = 1,
        HeadTrackScript = 2,
        HeadTrackCombat = 3,
        HeadTrackDialog = 4,
        HeadTrackProcedure = 5
    };
    enum FADE_STATE
    {
        FadeNone = 0,
        FadeInState = 1,
        FadeOutState = 2,
        FadeTeleportIn = 3,
        FadeTeleportOut = 4,
        FadeDisable = 5,
        FadeDelete = 6,
        FadeMove = 7
    };
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
    virtual void vfn_2c4(Actor*, int);
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
    virtual bool vfn_30c();
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
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual DetectionViewData* GetDetectionState(Actor*, int);
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual Actor* vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual void vfn_610();
    virtual void vfn_614();
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650();
    virtual void vfn_654();
    virtual void vfn_658();
    virtual void vfn_65c();
    virtual void vfn_660();
    virtual void vfn_664();
    virtual void vfn_668();
    virtual void vfn_66c();
    virtual void vfn_670();
    virtual void vfn_674();
    virtual void vfn_678();
    virtual void vfn_67c();
    virtual void vfn_680();
    virtual void vfn_684();
    virtual void vfn_688();
    virtual void vfn_68c();
    virtual void vfn_690();
    virtual void vfn_694();
    virtual void vfn_698();
    virtual void vfn_69c();
    virtual void vfn_6a0();
    virtual void vfn_6a4();
    virtual void vfn_6a8();
    virtual void vfn_6ac();
    virtual void vfn_6b0();
    virtual void vfn_6b4();
    virtual void vfn_6b8();
    virtual void vfn_6bc();
    virtual void vfn_6c0();
    virtual void vfn_6c4();
    virtual void vfn_6c8();
    virtual void vfn_6cc();
    virtual void vfn_6d0();
    virtual void vfn_6d4();
    virtual void vfn_6d8();
    virtual void vfn_6dc();
    virtual void vfn_6e0();
    virtual void vfn_6e4();
    virtual void vfn_6e8();
    virtual void vfn_6ec();
    virtual void vfn_6f0();
    virtual void vfn_6f4();
    virtual void vfn_6f8();
    virtual void vfn_6fc();
    virtual void vfn_700();
    virtual void vfn_704();
    virtual void vfn_708();
    virtual void vfn_70c();
    virtual void vfn_710();
    virtual void vfn_714();
    virtual void vfn_718();
    virtual void vfn_71c();
    virtual void vfn_720();
    virtual void vfn_724();
    virtual void vfn_728();
    virtual void vfn_72c();
    virtual void vfn_730();
    virtual float vfn_734();
};
class ActorValueStore
{
  public:
    unsigned char state[0x268];
    ActorValueStore();
    void ResetCacheValues();
    bool FUN_00900400(ActorValue::Index);
    void SetCachedActorValue(ActorValue::Index, float);
    float GetFloatAt(ActorValue::Index);
    void InvalidateValue(ActorValue::Index);
};
class LipSyncAnimation
{
  public:
    ~LipSyncAnimation();
    static void operator delete(void*);
};
class DialogueItem
{
  public:
    unsigned char state[28];
    DialogueItem();
    ~DialogueItem();
    static void operator delete(void*);
    void LoadDialogueItem(BGSLoadFormBuffer*);
    void RefreshObjectRef(BGSLoadFormBuffer*);
};
class GlobalObject_0040e0b0
{
};
union SETTING_VALUE
{
    float f;
    int i;
};
template <> class SettingT<GameSettingCollection>
{
  public:
    SETTING_VALUE* Float();
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
    SETTING_VALUE* Int();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting175;
class HighProcessDetectionActor
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual DetectionViewData* vfn_f0(Actor*, int, bool, int, int, bool, bool);
    virtual void vfn_f4();
    virtual HighProcessDetectionEventView* vfn_f8(Actor*);
    virtual void vfn_fc();
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
    virtual void vfn_130();
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
    virtual bool vfn_22c(bool);
};
template <> class BSSimpleList<TESForm*>
{
  public:
    TESForm* m_item;
    BSSimpleList* m_pkNext;
    BSSimpleList* GetNext();
    bool IsInList(TESForm*&);
};
template <> class BSSimpleList<TESTopicInfo*>
{
  public:
    TESTopicInfo* m_item;
    BSSimpleList* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    TESTopicInfo*& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
    void AddHead(TESTopicInfo*&);
    void RemoveAll();
    void RemoveHead();
    void SetItem(TESTopicInfo* const&);
    void Remove(TESTopicInfo* const&);
};
class FleePackage;
#include "highprocess_actor.h"
class DoorCell
{
  public:
    TESForm* GetOwner();
};
class TESFaction
{
  public:
    bool FUN_0047d7c0();
};
class EffectSetting
{
  public:
    TESSound* GetAreaSound();
};
class HighProcessCellView
{
  public:
    bool FUN_00544490();
};
class HighProcessPlayerAlpha
{
  public:
    unsigned char state[0xc8];
    float alpha;
};

class HighProcessDetectionEventView
{
  public:
    int type;
    NiPoint3 position;
    int state[2];
    TESObjectREFR* source;
};

class TopicInfoArray
{
  public:
    unsigned int FUN_005be5c0(int);
    Actor* FUN_00968670(unsigned int);
};
class QuestDialogueInfo
{
  public:
    int FindCrime(Actor*, int, int);
    TopicInfoArray* GetInfoArray();
};
class GlobalObject_0096d020
{
};
extern GlobalObject_0096d020 g_011e0e80;
extern GlobalObject_0045d260 g_011e0244;
extern BSSimpleList<TESTopicInfo*> DAT_011e0280;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting87, originalRuntimeFloatSetting103,
    originalRuntimeFloatSetting922;
extern SettingT_GameSettingCollection_ DAT_011cf788;
extern const double DAT_01084d28, runtimeInitializationDouble2;
int FUN_00642bc0(int, bool, float, int, int, bool, bool, bool, int, bool, bool);

class ActiveEffect
{
  public:
    bool FUN_00705cf0();
};
class TESActorBaseData
{
  public:
    bool GetGhostFlag();
    unsigned char state[0x60];
};
class TESActorBase
{
  public:
    unsigned char form[0x30];
    TESActorBaseData data;
    ActiveEffect aggroFlags;
};
class HighProcessCombatSource
{
  public:
    bool FUN_0059f610();
};
class AlchemyItem
{
  public:
    void* FUN_004030b0();
};
class BGSDefaultObjectManager
{
  public:
    static BGSDefaultObjectManager* Instance();
    static TESForm* GetDefaultObjectByIndex(int);
};
double FUN_0047eeb0(unsigned char);
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting106;
extern GlobalObject_0040e0b0 g_011cdf10;
extern SettingT_GameSettingCollection_ DAT_011cf414;

class NiBound
{
  public:
    float FUN_0084d030() const;
};
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8(NiAVObject*);
    NiNode* GetParent();
    const NiBound& GetBoundingVolume() const;
    void* SetTaskFlag(bool);
};
class NiNode : public NiAVObject
{
  public:
    NiAVObject* FUN_0045bc00(unsigned int);
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
    double FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting109;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting108;
class DetectionEventData
{
  public:
    TESObjectREFR* target;
    NiPoint3 position;
};
class ScriptLocals;
class BSPortalGraph;
class TESWorldSpace
{
  public:
    bool FUN_00992530(Actor*, Actor*);
    void FUN_00992480(Actor*, Actor*);
    BSPortalGraph* FUN_006698d0();
};
class TESRecipe
{
  public:
    void SetSkillLevel(int);
};
unsigned int DialogueRandom();
extern const float g_011c72ac_arg1;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting134;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting135;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting136;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting137;

class CombatDamageCalculator
{
  public:
    static double GetDamageMultiplier(float, float);
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting148;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting147;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting138;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting139;
extern unsigned int DAT_011e01e0;
class Script
{
  public:
    char* GetData();
    void Run(TESObjectREFR*, ScriptLocals*, bool, bool);
    static void MoveReferenceToPosition(TESObjectREFR*, TESObjectREFR*, float, float, float);
};
class BGSLoadGameBuffer
{
  public:
    virtual unsigned char GetVersion();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual Actor* GetActor();
    unsigned int ReadFormIdentifier();
    void ReadDataBlock(void*, unsigned int);
};
class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
class CombatTargetTimestamp
{
  public:
    float GetElapsedTime();
    CombatTargetTimestamp(float);
    float fTimeStamp;
    void LoadGame(BGSLoadGameBuffer*);
};
enum DETECTION_LEVEL
{
    DETECTION_LOST = 0,
    DETECTION_UNSEEN = 1,
    DETECTION_NOTICED = 2,
    DETECTION_SEEN = 3
};
class DetectionViewData
{
  public:
    Actor* pActor;
    DETECTION_LEVEL m_eDetectionLevel;
    int iLevel;
    NiPoint3 m_kActorPosition;
    CombatTargetTimestamp m_abyActorState;
    bool b360view, m_bCombatState, m_bHasLineOfSight, m_bIsDetected;
    int m_iDetectionValue;
    DetectionViewData();
    void LoadGame(BGSLoadGameBuffer*);
    void ResolveActorFormId();
};
class DetectionEvent
{
  public:
    unsigned char state[16];
    CombatTargetTimestamp time;
    unsigned char remainder[8];
    DetectionEvent();
    void FUN_008d72e0(BGSLoadFormBuffer*);
    void SetTargetReference(BGSLoadFormBuffer*);
};
class TopicInfoRecord
{
  public:
    unsigned char state[52];
    TopicInfoRecord();
    void FUN_008d7420(BGSLoadFormBuffer*);
    void FUN_008d74a0(BGSLoadFormBuffer*);
};
class BGSSaveLoadGame
{
  public:
    void FUN_0084a810(int, BGSLoadFormBuffer*, int);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
enum FADER_ENUM
{
    FaderDefault = 1
};
class FaderManager
{
  public:
    float GetFadeValue(FADER_ENUM);
};
class Interface;
extern Interface* DAT_011d8804;
class ActorMover
{
  public:
    void RefreshMovementState();
};
class GlobalObject_0045d260
{
};
extern GlobalObject_0045d260 g_011e0246;
extern bool DAT_011f1221;
enum PTYPE
{
    PackageDefault = 0
};
class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
class Calendar
{
  public:
    float GetGameTime();
};
extern Calendar g_calendar;
extern int* DAT_011a3ff0[];
extern const double DAT_010240c0, DAT_0101a6b0;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting246;
extern SettingT_GameSettingCollection_ DAT_011cdd30;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1045;
extern GlobalObject_0040e0b0 g_011d1314;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1046;
float FUN_0040ebd0(float, float);
double FUN_00408820(float);
double FUN_00408860(float);
class AIFormulas
{
  public:
    double CalculateDetectionValue(TESObjectREFR*, bool, bool);
};
class LowProcess
{
  public:
    bool CanProcessActor(Actor*, bool);
};
class TESPackage
{
  public:
    bool IsNotFlag8000000();
    bool IsPackageBlockingGreeting();
    bool IsFlag4Clear();
    int GetProcedureType();
    unsigned char layout00[0x94];
    MobileObject* dialogActor;
    bool FUN_0067a480();
    TESIdleForm* FUN_00546930();
    TESTopic* FUN_00903bb0();
    TESTopic* FUN_00903cd0();
    Script* FUN_00903e20();
    TESIdleForm* FUN_00903de0();
    TESTopic* FUN_00903e00();
    bool FUN_0067efd0();
    bool UsesPackageAnimation();
    NiNode* GetParent();
    PTYPE GetPackType();
    bool FUN_008dade0();
};
class PerkEntryConditionSet
{
  public:
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*);
};
class IdleAnimationManager
{
  public:
    TESIdleForm* FindIdleFormForObject(MobileObject*, TESObjectREFR*);
};
extern IdleAnimationManager* DAT_011cb6a0;
extern BSSimpleArray<unsigned int, 1024> DAT_011f2250;
class AnimIdle
{
  public:
    enum PLAY_TYPE_ENUM
    {
        PlayDefault = 2
    };
};
class Animation
{
  public:
    NiControllerManager* FUN_00496940();
    void SpecialIdleFree(bool, bool);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, AnimIdle::PLAY_TYPE_ENUM);
    bool FUN_00493830();
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdleReady();
    bool IsSpecialIdlePlaying(TESIdleForm*);
};
class DetectionParameters;
enum ACTOR_AGGRESSION
{
    AggressionNone = 0
};
class MiddleLowProcess
{
  public:
    float GetCurrentActorValue(TESActorBase*, ActorValue::Index, Actor*);
    void AlterActorValue(Actor*, ActorValue::Index, float);
};
namespace ActorValue {
bool GetFlag(Index, unsigned int);
}
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
};
class PathingAvoidNodeArray : public NiMemObject
{
  public:
    unsigned int state[6];
    PathingAvoidNodeArray();
    void AppendNode(TopicInfoRecord*);
};
class HighProcessVector : public NiPoint3
{
  public:
    void Subtract(NiPoint3*);
};
class BSFileEntry;
enum ACTOR_SOUND_HANDLE
{
    SoundVoice = 0,
    SoundOther = 1
};
class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
    TESObjectREFR* ResolveLocationReference(Actor*);
    unsigned int FUN_0067f1c0();
};

class TargetDoorController
{
  public:
    ~TargetDoorController();
    static void operator delete(void*);
};
class DecalDataDeleter
{
  public:
    void* DeleteThis(int);
};
class MuzzleFlash
{
  public:
    ~MuzzleFlash();
    static void operator delete(void*);
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting185;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting347;
extern const float runtimeFloatSettingDefault13;
struct PlayerDetectionCounter
{
    unsigned int frame;
    unsigned char flags[4];
};
extern PlayerDetectionCounter DAT_011a3780[];
float FUN_00404040(float);
enum ANIMATION_ACTION
{
    AnimActionNone = -1
};
class BSFaceGenAnimationData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc(float, bool, bool, bool, bool);
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8(bool);
};
class ActorCombatGroup
{
  public:
    int FUN_005a4320();
    bool ContainsActor(Actor*);
    Actor* GetIntAt(int);
};
class ActorGroupState
{
  public:
    ActorGroupState();
    Actor* actor;
    ActorCombatGroup* group;
    bool flag8, flag9, flaga, flagb;
    bool ignoreDefensivePackage, spectator;
    unsigned char padding[2];
    int priority;
};
class FleePackage
{
  public:
    unsigned char state[156];
    FleePackage(Actor*, TESForm*, TESObjectCELL*, int);
    void AddAvoidedReference(Actor*);
};
class BackUpPackage
{
  public:
    void ExecuteBackupPackage(Actor*);
};
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
class NiTexture;
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    NiPointer();
    NiPointer(NiTexture*);
    ~NiPointer();
    NiPointer& operator=(NiTexture*);
};
template <> class NiPointer<KFModel>
{
  public:
    KFModel* m_pObject;
    NiPointer();
    NiPointer(KFModel*);
    ~NiPointer();
    NiPointer& operator=(KFModel*);
};
template <> class NiPointer<ActorPathingMessageQueue>
{
  public:
    ActorPathingMessageQueue* m_pObject;
    NiPointer();
    NiPointer(ActorPathingMessageQueue*);
    ~NiPointer();
    NiPointer& operator=(ActorPathingMessageQueue*);
};

class NiNode;
class NiControllerManager;
class NiControllerManager
{
  public:
    NiControllerManager* GetStringAtOffset();
};
class Biped;
class TESRace
{
  public:
    void ClearFaceGenUndo();
};
class TESNPC
{
  public:
    unsigned char layout00[0x10c];
    BSSimpleList<TESForm*> race;
    void ResetFaceGen();
    void GetFaceGenNodes(unsigned int*, unsigned int*);
    void UpdateActorFaceGen(Actor*, Biped*, unsigned int, unsigned int);
    void RefreshActorAppearance(Actor*);
};
class ExtraRefractionProperty
{
  public:
    unsigned char layout00[12];
    float value;
};
class ShadowSceneNode
{
  public:
    void FUN_00b5b1c0(NiAVObject*);
    void AddObject(NiAVObject*);
};
class NiAdditionalGeometryData
{
  public:
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
class Interface
{
  public:
    static bool IsPipBoyOpen();
};
bool FUN_005b9b00();
void AttachControllerManager(NiAVObject*, NiControllerManager*);
void SetObjectFormID(NiAVObject*, unsigned int);
extern bool DAT_011c5cb4;
class MiddleHighProcess
{
  public:
    ~MiddleHighProcess();
    void ResetCurrentPackage();
    void SetAnimation(Animation*);
    void RefreshActorPackage(Actor*);
    MiddleHighProcess();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual bool vfn_44(Actor*, TESIdleForm*, AnimIdle::PLAY_TYPE_ENUM, bool, bool, bool);
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c(Actor*);
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0(int);
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual DetectionViewData* vfn_f0(Actor*, int, bool, int, int, bool, bool);
    virtual void vfn_f4();
    virtual HighProcessDetectionEventView* vfn_f8(Actor*);
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual bool vfn_11c();
    virtual void vfn_120(bool);
    virtual void vfn_124();
    virtual TESObjectREFR* vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
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
    virtual Animation* GetAnimation();
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
    virtual void vfn_1f0(Actor*);
    virtual bool vfn_1f4(Actor*, Actor*);
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual TESPackage* GetInterruptPackage();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual TESPackage* GetStablePackage();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual int vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual float vfn_264();
    virtual void vfn_268(float);
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual TESPackage* GetCurrentPackage();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4(Actor*, TESTopic*, bool, bool, bool, bool);
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4(Actor*, int);
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
    virtual bool vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual float vfn_334();
    virtual void vfn_338(float);
    virtual void vfn_33c(Actor*, Actor*, int, bool, ActorCombatGroup*, bool, bool, bool, bool, bool, bool, bool, bool);
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
    virtual bool vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual float vfn_39c(TESActorBase*, ActorValue::Index, Actor*);
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
    virtual int vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec(int, int);
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
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual bool vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual unsigned char vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual bool vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual int vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual DetectionViewData* GetDetectionState(Actor*, int);
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual Actor* vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580(bool, bool, bool);
    virtual void vfn_584();
    virtual void vfn_588(bool);
    virtual void vfn_58c();
    virtual void vfn_590(bool);
    virtual bool vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual void vfn_610();
    virtual void vfn_614(unsigned int);
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650();
    virtual void vfn_654();
    virtual void vfn_658();
    virtual void vfn_65c();
    virtual void vfn_660();
    virtual void vfn_664();
    virtual void vfn_668();
    virtual void vfn_66c();
    virtual void vfn_670();
    virtual void vfn_674();
    virtual void vfn_678();
    virtual void vfn_67c();
    virtual void vfn_680();
    virtual void vfn_684();
    virtual void vfn_688();
    virtual void vfn_68c();
    virtual void vfn_690();
    virtual void vfn_694();
    virtual void vfn_698();
    virtual void vfn_69c();
    virtual void vfn_6a0();
    virtual void vfn_6a4();
    virtual void vfn_6a8();
    virtual void vfn_6ac();
    virtual void vfn_6b0();
    virtual void vfn_6b4();
    virtual void vfn_6b8();
    virtual void vfn_6bc();
    virtual void vfn_6c0();
    virtual void ClearMuzzleFlash();
    virtual void vfn_6c8();
    virtual void vfn_6cc();
    virtual void vfn_6d0();
    virtual void vfn_6d4();
    virtual void vfn_6d8();
    virtual void vfn_6dc();
    virtual void vfn_6e0();
    virtual void vfn_6e4();
    virtual void vfn_6e8();
    virtual void vfn_6ec();
    virtual void vfn_6f0();
    virtual void vfn_6f4();
    virtual void vfn_6f8();
    virtual void vfn_6fc();
    virtual void vfn_700();
    virtual void vfn_704();
    virtual void vfn_708();
    virtual void vfn_70c(PlayerCharacter*);
    virtual void vfn_710();
    virtual void vfn_714();
    virtual void vfn_718();
    virtual void vfn_71c();
    virtual void vfn_720();
    virtual void vfn_724();
    virtual void vfn_728();
    virtual void vfn_72c();
    virtual void vfn_730();
    virtual float vfn_734();
    virtual void vfn_738();
    virtual void vfn_73c();
    virtual void vfn_740();
    virtual void vfn_744();
    virtual void vfn_748();
    virtual void vfn_74c();
    virtual void vfn_750();
    virtual void vfn_754();
    virtual void vfn_758();
    virtual void vfn_75c();
    virtual void vfn_760();
    virtual void vfn_764();
    virtual void vfn_768();
    virtual void vfn_76c();
    virtual void vfn_770();
    virtual void vfn_774();
    virtual void vfn_778();
    virtual void vfn_77c();
    virtual void vfn_780();
    virtual void vfn_784();
    virtual void vfn_788();
    virtual void vfn_78c();
    virtual void vfn_790();
    virtual void vfn_794(NiAVObject*);
    virtual void vfn_798();
    virtual void vfn_79c(NiAVObject*);
    virtual void vfn_7a0();
    virtual void vfn_7a4(NiAVObject*);
    virtual void vfn_7a8();
    virtual void vfn_7ac();
    virtual void vfn_7b0();
    virtual void vfn_7b4();
    virtual void vfn_7b8();
    virtual void vfn_7bc();
    virtual void vfn_7c0();
    virtual void vfn_7c4();
    virtual void vfn_7c8();
    virtual void vfn_7cc();
    virtual void vfn_7d0();
    virtual void vfn_7d4();
    virtual void vfn_7d8();
    virtual void vfn_7dc();
    virtual void vfn_7e0();
    virtual void vfn_7e4();
    virtual void vfn_7e8();
    virtual void vfn_7ec();
    virtual void vfn_7f0();
    virtual void vfn_7f4();
    virtual void vfn_7f8();
    virtual void vfn_7fc();
    virtual void vfn_800();
    virtual void vfn_804();
    virtual void vfn_808();
    virtual void vfn_80c();
    virtual void vfn_810();
    virtual void vfn_814();
    virtual void vfn_818();
    virtual void vfn_81c();
    virtual void vfn_820();
    virtual void vfn_824();
    virtual void vfn_828();
    virtual void vfn_82c();
    virtual void vfn_830();
    virtual void vfn_834();
    virtual void vfn_838();
    virtual void vfn_83c();
    virtual void vfn_840();
    virtual void vfn_844();
    virtual void vfn_848();
    virtual void vfn_84c();
    virtual void vfn_850();
    virtual void vfn_854();
    virtual void vfn_858();
    virtual void vfn_85c();
    virtual void vfn_860();
    virtual void vfn_864();
    virtual void vfn_868();
    virtual void vfn_86c();
    virtual void vfn_870();
    ActorPackageContext m_kProcessData;  // +0x4
    unsigned char layoutGap_1c[12];
    int m_eProcessType;  // +0x28
    unsigned char layoutGap_2c[8];
    TESBoundObject* m_pCurrentWeapon;  // +0x34
    unsigned char layoutGap_38[8];
    TESObjectREFR* pTarget;         // +0x40
    TESObjectREFR* m_pReference40;  // +0x44
    TESObjectREFR* m_pReference44;  // +0x48
    unsigned char layoutGap_4c[12];
    int m_iValue58;                                    // +0x58
    BSSimpleList<TESTopicInfo*> ReferenceListNode;     // +0x5c
    TargetDoorController* m_pDetectionData60;              // +0x64
    TargetDoorController* m_pDetectionData64;              // +0x68
    BSSimpleList<TESObjectREFR*> m_kReferenceList68;   // +0x6c
    BSSimpleList<TESTopicInfo*> m_kDetectionDataList;  // +0x74
    BSSimpleList<TESObjectREFR*> m_kReferenceList70;   // +0x7c
    unsigned char layoutGap_84[48];
    int iCurrentProcedure;  // +0xb4
    unsigned char layoutGap_b8[16];
    BSSimpleList<TESObjectREFR*> m_kReferenceList;           // +0xc8
    BSSimpleList<TESObjectREFR*> m_kSecondaryReferenceList;  // +0xd0
    float m_kNinthUnshownMember;                             // +0xd8
    float m_kEighthUnshownMember;                            // +0xdc
    bool m_bPackageStateFlag2;                               // +0xe0
    bool m_bPackageStateFlag;                                // +0xe1
    bool m_bPackageStateFlag3;                               // +0xe2
    bool m_bPackageStateFlag4;                               // +0xe3
    ActorPackageContext PackageReference;                           // +0xe4
    NiPoint3 m_kPackageTargetPosition;                       // +0xfc
    PACKAGE_OBJECT_TYPE m_ePackageObjectType;                // +0x108
    TESIdleForm* m_pPackageIdleForm;                         // +0x10c
    bool m_kSecondUnshownMember;                             // +0x110
    unsigned char layoutGap_111[3];
    InventoryStackRecord* pWeapon;               // +0x114
    InventoryStackRecord* pAmmo;                 // +0x118
    QueuedFile* m_pQueuedWeaponFile;   // +0x11c
    ActorSupportClass* m_pWeaponData;  // +0x120
    bool m_bFirstWeaponFlag;           // +0x124
    bool m_bSecondWeaponFlag;          // +0x125
    bool m_bThirdWeaponFlag;           // +0x126
    bool m_bFourthWeaponFlag;          // +0x127
    bool m_bFifthWeaponFlag;           // +0x128
    bool m_bSixthWeaponFlag;           // +0x129
    bool m_bSeventhWeaponFlag;         // +0x12a
    unsigned char layoutGap_12b[1];
    NiNode* m_pActorNode;         // +0x12c
    NiAVObject* m_pActorObject;   // +0x130
    bool m_bFirstActorFlag;       // +0x134
    bool m_bAdditionalActorFlag;  // +0x135
    unsigned char layoutGap_136[2];
    bhkCharacterController* m_pCharacterController;  // +0x138
    char m_cCharacterControllerState;                // +0x13c
    unsigned char m_ucFurnitureInteractionState;     // +0x13d
    unsigned char layoutGap_13e[2];
    TESObjectREFR* m_pFurnitureReference;    // +0x140
    unsigned char m_ucFurnitureMarkerIndex;  // +0x144
    unsigned char layoutGap_145[3];
    unsigned char FurnitureMarker[16];  // +0x148
    Actor* m_pCombatTarget;             // +0x158
    TESObjectWEAP* m_pEquippedWeapon;   // +0x15c
    MagicItem* m_pFirstMagicItem;       // +0x160
    MagicItem* m_pSecondMagicItem;      // +0x164
    bool m_bWeaponOut;                  // +0x168
    unsigned char layoutGap_169[3];
    TESEffectShader* m_pEffectShader;                 // +0x16c
    float m_fFirstEffectShaderValue;                  // +0x170
    float m_fSecondEffectShaderValue;                 // +0x174
    BSFaceGenAnimationData* m_pFaceGenAnimationData;  // +0x178
    bool m_bFirstFaceGenFlag;                         // +0x17c
    bool m_kSixthUnshownMember;                       // +0x17d
    bool m_bThirdFaceGenFlag;                         // +0x17e
    bool m_kSeventhUnshownMember;                     // +0x17f
    bool m_kFifthUnshownMember;                       // +0x180
    unsigned char layoutGap_181[3];
    unsigned int m_uiAnimationStateFlags;  // +0x184
    bool m_bAiming;                        // +0x188
    bool m_bAimStateFlag;                  // +0x189
    bool m_bCombatStateFlag;               // +0x18a
    bool m_bFourthStateFlag;               // +0x18b
    unsigned char m_ucProcessState;        // +0x18c
    bool m_bEquipStateFlag;                // +0x18d
    unsigned char layoutGap_18e[2];
    int m_iIdleState;                 // +0x190
    TESIdleForm* m_pCurrentIdleForm;  // +0x194
    float m_fIdleAnimationTime;       // +0x198
    bool m_kThirdUnshownMember;       // +0x19c
    bool m_kFourthUnshownMember;      // +0x19d
    unsigned char layoutGap_19e[2];
    LipSyncAnimation* m_pLipSyncAnimation;                                       // +0x1a0
    unsigned int m_uiLipSyncState;                                               // +0x1a4
    int m_iProjectileCount;                                                      // +0x1a8
    BSSimpleList<ArrowProjectile*>* m_pArrowProjectileList;                      // +0x1ac
    BSSimpleList<MiddleHighProcess__DeferredHideLimb*> m_kDeferredHideLimbList;  // +0x1b0
    BSSimpleList<ActiveEffect*>* m_pActiveEffectList;                            // +0x1b8
    MagicTarget* m_pMagicTarget;                                                 // +0x1bc
    Animation* pCurrentAnimation;                                                // +0x1c0
    BSAnimGroupSequence* m_apAnimGroupSequences[3];                              // +0x1c4
    float m_fAnimationTime;                                                      // +0x1d0
    float m_fAnimationSpeed;                                                     // +0x1d4
    unsigned char m_ucAnimationState;                                            // +0x1d8
    bool m_bFirstAnimationFlag;                                                  // +0x1d9
    bool m_bAnimationStateFlag;                                                  // +0x1da
    unsigned char layoutGap_1db[1];
    NiNode* m_apBodyPartNodes[15];                    // +0x1dc
    NiAVObject* m_pFirstAttachedObject;               // +0x218
    NiAVObject* m_pSecondAttachedObject;              // +0x21c
    BSShaderPPLightingProperty* m_pLightingProperty;  // +0x220
    BSBound* m_pBound;                                // +0x224
    bool m_kFieldAfterWeaponFlags;                    // +0x228
    unsigned char layoutGap_229[1];
    short m_sBoundDataValue;                               // +0x22a
    unsigned int m_kEleventhUnshownMember;                 // +0x22c
    BSSimpleList<PaddedFloatRecord*>* m_pkPaddedFloatRecordList;  // +0x230
    float m_kTenthUnshownMember;                           // +0x234
    float m_fFirstFaceGenValue;                            // +0x238
    float m_fSecondFaceGenValue;                           // +0x23c
    BooleanFloatQuery* m_pData;                            // +0x240
    int m_iFaceGenNodeIndex;                               // +0x244
    BSFaceGenNiNode* m_pFirstFaceGenNode;                  // +0x248
    BSFaceGenNiNode* m_pSecondFaceGenNode;                 // +0x24c
    NiAVObject* m_pFaceGenObject;                          // +0x250
    BooleanFloatQuery* m_pAdditionalFaceGenData;           // +0x254
    unsigned int m_uiFaceGenDataFlags;                     // +0x258
    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
};
class HighProcess : public MiddleHighProcess
{
  public:
    BSSimpleList<TESTopicInfo*>* pDetectionEventList;        // +0x25c
    BSSimpleList<TESTopicInfo*>* m_pDetectionEventList;      // +0x260
    BSSimpleList<TESTopicInfo*>* m_pAuxiliaryList;           // +0x264
    BSSimpleList<TESTopicInfo*>* m_pDetectionList;           // +0x268
    BSSimpleList<TESTopicInfo*>* m_pSecondaryDetectionList;  // +0x26c
    bool m_bHasActorGroupState;                              // +0x270
    unsigned char layoutGap_271[3];
    BSSimpleList<TESTopicInfo*> m_kPrimaryDetectionList;    // +0x274
    BSSimpleList<TESTopicInfo*> m_kActorGroupStateList;     // +0x27c
    BSSimpleList<TESTopicInfo*> m_kSecondaryDetectionList;  // +0x284
    BSSimpleList<TESTopicInfo*> m_kActorGroupEntries;       // +0x28c
    float m_fFirstDialogueValue;                            // +0x294
    float m_fSecondDialogueValue;                           // +0x298
    bool m_bDialogueStateEnabled;                           // +0x29c
    bool m_bHasSavedTarget;                                 // +0x29d
    unsigned char layoutGap_29e[2];
    float m_fSavedTargetDistance;             // +0x2a0
    TESObjectREFR* m_pSavedTargetReference;   // +0x2a4
    float m_fFirstReferenceTimer;             // +0x2a8
    TESObjectREFR* m_pTrackedReference;       // +0x2ac
    float m_fAnimationScale;                  // +0x2b0
    float m_fAnimationBlendValue;             // +0x2b4
    float m_fSecondAnimationValue;            // +0x2b8
    float m_fFirstAnimationValue;             // +0x2bc
    short m_sFirstIndex;                      // +0x2c0
    short m_sSecondIndex;                     // +0x2c2
    short m_sThirdIndex;                      // +0x2c4
    bool m_bImpactState;                      // +0x2c6
    bool m_kFirstAdditionalHighProcessField;  // +0x2c7
    float m_fImpactValue;                     // +0x2c8
    NiNode* pNode;                            // +0x2cc
    float m_fImpactForceScale;                // +0x2d0
    float m_fImpactForce;                     // +0x2d4
    float fElapsedAnimationTime;              // +0x2d8
    char m_cDialogueState;                    // +0x2dc
    unsigned char layoutGap_2dd[3];
    float m_fAnimationTimer;                      // +0x2e0
    NiBSBoneLODController* m_pBoneLODController;  // +0x2e4
    int m_iAnimationGroup;                        // +0x2e8
    short m_sAnimationSequenceGroup;              // +0x2ec
    unsigned char layoutGap_2ee[2];
    BSAnimGroupSequence* m_pAnimationSequence;  // +0x2f0
    bool m_bAnimationActive;                    // +0x2f4
    unsigned char layoutGap_2f5[3];
    float m_fSocialTalkDelay;  // +0x2f8
    short m_sAnimationState;   // +0x2fc
    unsigned char layoutGap_2fe[2];
    NiPoint3 m_kSocialTalkPosition;      // +0x300
    TESObjectREFR* m_pSocialTalkTarget;  // +0x30c
    float m_fReferenceTimer;             // +0x310
    SoundPlaybackHandle AudioPlaybackHandle[2];        // +0x314
    bool iProcessIndex;                  // +0x32c
    unsigned char layoutGap_32d[3];
    float m_fFirstProcessValue;   // +0x330
    float m_fSecondProcessValue;  // +0x334
    float m_fAwarenessDelay;      // +0x338
    float m_fAwarenessValue;      // +0x33c
    bool bCanDetectAlert;         // +0x340
    unsigned char layoutGap_341[3];
    float m_fFirstSerializedValue;  // +0x344
    bool m_bAlertState;             // +0x348
    bool bWeaponAlertDrawn;         // +0x349
    unsigned char layoutGap_34a[2];
    float fAwarePlayerTimer;                  // +0x34c
    TESIdleForm* iAnimationStateCode;         // +0x350
    NiPointer<NiTexture> iLocalValue[2];      // +0x354
    NiPointer<KFModel> m_kKeyframeModels[2];  // +0x35c
    bool m_bSpellState;                       // +0x364
    unsigned char layoutGap_365[3];
    DialogueItem* pOwnedObject;        // +0x368
    DIALOGUE_EMOTION m_iProcessState;  // +0x36c
    MobileObject* m_pSavedReference;   // +0x370
    bool m_bSavedReferenceFlag;        // +0x374
    bool m_bDialogueFlag;              // +0x375
    unsigned char layoutGap_376[2];
    float m_fDialogueDelay;                                   // +0x378
    float m_fFirstDialogueParameter;                          // +0x37c
    NiPointer<NiTexture> m_kSixthAdditionalHighProcessField;  // +0x380
    float fCurrentValue;                                      // +0x384
    float m_fSecondDialogueParameter;                         // +0x388
    BSSimpleList<TESTopicInfo*> m_kPrimaryTopicList;          // +0x38c
    BSSimpleList<TESTopicInfo*> m_kSecondaryTopicList;        // +0x394
    int m_iDialogueTopicCount;                                // +0x39c
    bool bStop;                                               // +0x3a0
    unsigned char layoutGap_3a1[3];
    float m_fThirdDialogueParameter;  // +0x3a4
    bool fScale;                      // +0x3a8
    unsigned char layoutGap_3a9[3];
    int m_iFirstSpellIndex;                   // +0x3ac
    int m_iSecondSpellIndex;                  // +0x3b0
    BSSimpleList<SpellItem*>* m_pkSpellList;  // +0x3b4
    char iValue;                              // +0x3b8
    bool iLocalState;                         // +0x3b9
    unsigned char layoutGap_3ba[2];
    float m_fFirstLipSyncParameter;       // +0x3bc
    float m_fSecondLipSyncParameter;      // +0x3c0
    float m_fLipSyncTimer;                // +0x3c4
    float m_fLipSyncValue;                // +0x3c8
    LipSyncAnimation* pLipSyncAnimation;  // +0x3cc
    bool m_bLipSyncEnabled;               // +0x3d0
    bool m_bLipSyncPlaying;               // +0x3d1
    unsigned char layoutGap_3d2[2];
    MuzzleFlash* m_pMuzzleFlash;        // +0x3d4
    unsigned int m_uiMuzzleFlashIndex;  // +0x3d8
    DetectionEvent* m_pDetectionEvent;  // +0x3dc
    bool m_bTrackedReferenceFlag;       // +0x3e0
    unsigned char layoutGap_3e1[3];
    DialogueItem* m_pQueuedDialogueItem;               // +0x3e4
    BaseProcess::FADE_STATE m_iSecondSerializedValue;  // +0x3e8
    float fFadeAlpha;                                  // +0x3ec
    TESObjectREFR* m_pFadeReference;                   // +0x3f0
    DetectionEventData* pDetectionEventData;           // +0x3f4
    TESObjectREFR* m_pRecentReferences[6];             // +0x3f8
    bool m_bReferenceFlags[6];                         // +0x410
    unsigned char layoutGap_416[2];
    float m_fReferencePriority;  // +0x418
    TESObjectREFR* coordinate;   // +0x41c
    bool m_bDetectionFlag;       // +0x420
    unsigned char layoutGap_421[3];
    BaseProcess::POSTANIM_ACTION m_ePendingPostAnimationActions;  // +0x424
    ActorValueStore* m_pRevertibleObject;                         // +0x428
    float m_kSecondAdditionalHighProcessField;                    // +0x42c
    int m_iDialogueState;                                         // +0x430
    NiPointer<NiTexture> m_kNinthAdditionalHighProcessField;      // +0x434
    float m_kThirdAdditionalHighProcessField;                     // +0x438
    float m_fFirstReferenceValue;                                 // +0x43c
    float m_fSecondReferenceValue;                                // +0x440
    bool iCount;                                                  // +0x444
    bool pTargetObject;                                           // +0x445
    unsigned char layoutGap_446[2];
    float m_fDialogueTimer;                          // +0x448
    BSSimpleList<TESTopicInfo*>* m_pkTopicInfoList;  // +0x44c
    float m_fDialogueConditionValue;                           // +0x450
    DialogueItem* m_pCurrentDialogueItem;            // +0x454
    bool bHasSubtitle;                               // +0x458
    bool m_bSubtitleActive;                          // +0x459
    unsigned char layoutGap_45a[2];
    NiPointer<NiTexture> m_kEighthAdditionalHighProcessField;                  // +0x45c
    NiPointer<NiTexture> m_kFifthAdditionalHighProcessField;                   // +0x460
    NiPointer<ActorPathingMessageQueue> m_kSeventhAdditionalHighProcessField;  // +0x464
    NiPointer<ActorPathingMessageQueue> m_kFourthAdditionalHighProcessField;   // +0x468
    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void ClearAndDeleteList();
    bool ClearProcessState(Actor*);
    void ProcessActorWithFlag(Actor*, bool);
    bool FUN_008ff080();
    void FUN_008e5730(Actor*);
    void Update(MobileObject*);
    bool ProcessActivate(Actor*, bool);
    void UpdateActorStateWithOptions(Actor*, bool, bool, int, bool);
    void ProcessDialogueTopic(Actor*, TESTopic*, bool, bool, bool, bool);
    void RunDetection(Actor*, float);
    bool IsActorFriendlyToActor(Actor*, Actor*);
    bool CanDetectTarget(Actor*, Actor*);
    bool ShouldProcessActor(Actor*);
    void ProcessEat(Actor*, TESObjectREFR*);
    void ActorEntity(TESObjectREFR*, Actor*, bool&, DetectionParameters*, ACTOR_AGGRESSION, float, float);
    bool HasGroupEntry(ActorCombatGroup*);
    void ProcessDetectionTarget(Actor*, Actor*);
    HighProcess();
    void RefreshActorState(Actor*);
    bool IsCurrentPackageTarget(Actor*);
    void ProcessActorGroupState(Actor*);
    bool StartIdleAnimation(MobileObject*, TESIdleForm*, AnimIdle::PLAY_TYPE_ENUM, bool, bool, bool);
    void PlayRandomIdle(Actor*);
    bool CanProcessActor(Actor*, bool);
    void UpdateReferenceTime(Actor*, float);
    void SetActorDetectionLevel(Actor*, int);
    DetectionViewData* FindDetectionRecord(Actor*, DETECTION_LEVEL, bool, int, int, bool, bool);
    void OnPackageChanged(Actor*, TESPackage*);
    unsigned int UpdateHighProcessState(Actor*);
    void UpdateActorReferences(Actor*);
    float GetCurrentActorValue(TESActorBase*, ActorValue::Index, Actor*);
    PathingAvoidNodeArray* GetPathingAvoidNodeArray(Actor*);
    void StopActorSound(ACTOR_SOUND_HANDLE);
    void AlterActorValue(Actor*, ActorValue::Index, float);
    void OnPackageStart(Actor*, TESPackage*);
    void OnPackageEnd(Actor*, TESPackage*);
    void RefreshTargetState();
    bool IsTalking(MobileObject*);
    void ProcessActorIdle(Actor*);
    void ResetCurrentPackage();
    void ClearTrackedActorEntries();
    void SetActorDetectionState(Actor*, int, bool);
    DetectionViewData* GetDetectionState(Actor*, int);
    void RestorePreviousReference(bool);
    void ClearCachedTargetReferences(bool);
    void SetCombatActive(bool);
    void ClearDetectionEvents();
    void ClearPackageObjectList();
    void ClearDialogueItems();
    bool HasNoPendingEntriesAndExpired();
    void ClearMuzzleFlash();
    bool IsActorVisibleToActor(Actor*, Actor*, int, bool);
    void ResetTargetReferences();
    TESObjectREFR* GetPrimaryTargetReference();
    void ClearHighProcessState(TESObjectREFR*);
    void SetActorProcessState(TESObjectREFR*);
    void ClearIdleAnimation();
    void SetAnimation(Animation*);
    bool HasNoPendingEntries();
    void SetPreviousReference(TESObjectREFR*);
    int GetActorValue(TESActorBase*, ActorValue::Index, Actor*);
    bool CanUsePlayerAction(Actor*);
    void StopActorMovement(Actor*);
    void SetDiveBreathLevel(float);
    void SetAnimAction(ANIMATION_ACTION, BSAnimGroupSequence*);
    void UpdatePlayerAwarenessTimer();
    void ResetDetectionState();
    void AddPostAnimAction(BaseProcess::POSTANIM_ACTION);
    TESObjectREFR* GetPrimaryTargetReference(BaseProcess::HEAD_TRACK_TYPE);
    ANIMATION_ACTION GetAnimAction();
    BSAnimGroupSequence* GetActorProcessTime();
};
#endif

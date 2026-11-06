// fallout/misc/taskqueueinterface_decls.h: declares NiPoint3, NiAVObject, NiNode, TESForm, TESObjectREFR and more
#ifndef FNV_TASKQUEUEINTERFACE_DECLS_H
#define FNV_TASKQUEUEINTERFACE_DECLS_H

#include "layout_support.h"
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float x, float y, float z);  // @ref 0x00416870 ??0NiPoint3
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 12);
#endif
class BSPackedTask;
class TESObjectWEAP;
class NiUpdateData;
class BooleanFloatQuery;
class DismemberLimbTaskData;
class Date;
class bhkWorld;
class bhkCharacterController;
class CombatThreatRecord;
class ParentSpaceNode;
class SandboxProcedureData;
class TaskQueueParallelWork;
class TaskQueueParallelManager;
class NiAVObject
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void UpdateUpwardPassParent();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    NiNode* GetParent();  // @ref 0x009611e0 GetParent@NiAVObject
    float GetHeadTail();  // @ref 0x0087ce50 GetHeadTail
    void FUN_00401970();  // @ref 0x00401970 FUN_00401970
    void UpdateSceneObject();
    void Update(const NiUpdateData&);  // @ref 0x00a59c60 Update@NiAVObject
};
class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject*, bool);
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void RemoveObject(NiAVObject*);
};
class TESForm
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual bool GetIsReference();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual bool IsActor();
    static TESForm* GetFormByID(unsigned int);
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void DamageObject(float, bool);
    virtual void vfn_0148();
    virtual void vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void vfn_0160();
    virtual void vfn_0164();
    virtual void vfn_0168();
    virtual void vfn_016c();
    virtual void vfn_0170();
    virtual void vfn_0174();
    virtual void vfn_0178();
    virtual void vfn_017c();
    virtual void vfn_0180();
    virtual void vfn_0184();
    virtual void vfn_0188();
    virtual void vfn_018c();
    virtual void vfn_0190();
    virtual void vfn_0194();
    virtual void vfn_0198();
    virtual void vfn_019c();
    virtual void vfn_01a0();
    virtual void vfn_01a4();
    virtual void vfn_01a8();
    virtual void vfn_01ac();
    virtual void vfn_01b0();
    virtual void vfn_01b4();
    virtual void vfn_01b8();
    virtual void vfn_01bc();
    virtual bool Unload3D();
    virtual void AnimateNiNode();
    virtual void vfn_01c8();
    virtual void Set3D(NiNode*, bool);
    virtual void vfn_01d0();
    virtual void vfn_01d4();
    virtual void vfn_01d8();
    virtual void vfn_01dc();
    virtual void vfn_01e0();
    virtual void vfn_01e4();
    virtual void vfn_01e8();
    virtual void vfn_01ec();
    virtual void vfn_01f0();
    virtual void* SetBipedAnim();
    virtual void vfn_01f8();
    virtual void vfn_01fc(bool);
    virtual void vfn_0200();
    virtual void vfn_0204();
    virtual void vfn_0208();
    virtual void vfn_020c();
    virtual void vfn_0210();
    virtual void vfn_0214();
    virtual void vfn_0218();
    virtual void vfn_021c();
    virtual bool IsExplosion();
    virtual void vfn_0224();
    virtual void vfn_0228();
    virtual void vfn_022c();
    virtual void vfn_0230();
    virtual void vfn_0234();
    virtual void vfn_0238();
    virtual void vfn_023c();
    virtual void vfn_0240();
    virtual void vfn_0244();
    virtual void vfn_0248();
    virtual void vfn_024c();
    virtual void vfn_0250();
    virtual void vfn_0254();
    virtual void vfn_0258();
    virtual void vfn_025c();
    virtual void vfn_0260();
    virtual void vfn_0264();
    virtual void vfn_0268();
    virtual void vfn_026c();
    virtual void vfn_0270();
    virtual void vfn_0274();
    virtual void vfn_0278();
    virtual void vfn_027c();
    virtual void vfn_0280();
    virtual void vfn_0284();
    virtual void vfn_0288();
    virtual void vfn_028c();
    virtual void vfn_0290();
    virtual void vfn_0294();
    virtual void vfn_0298();
    virtual void vfn_029c();
    virtual void vfn_02a0();
    virtual void vfn_02a4();
    virtual void SetPos(NiPoint3*);
    static TESObjectREFR* GetReferenceFromNiAVObject(
        NiAVObject*);                         // @ref 0x0056f930 GetReferenceFromNiAVObject@TESObjectREFR
    TESObjectCELL* GetParentCell();           // @ref 0x008d6f30 GetParentCell@TESObjectREFR
    void SetExtraDataString(TESObjectWEAP*);  // @ref 0x00571760 SetExtraDataString@TESObjectREFR
};
class Actor : public TESObjectREFR
{
  public:
    virtual void vfn_02ac();
    virtual void vfn_02b0();
    virtual void vfn_02b4();
    virtual void vfn_02b8();
    virtual void vfn_02bc();
    virtual void vfn_02c0();
    virtual void vfn_02c4();
    virtual void vfn_02c8();
    virtual void vfn_02cc();
    virtual void vfn_02d0();
    virtual void vfn_02d4();
    virtual void vfn_02d8();
    virtual void vfn_02dc();
    virtual void vfn_02e0();
    virtual void vfn_02e4();
    virtual void vfn_02e8();
    virtual void vfn_02ec();
    virtual void vfn_02f0();
    virtual void vfn_02f4();
    virtual void vfn_02f8();
    virtual void vfn_02fc();
    virtual void vfn_0300();
    virtual void IsGuard();
    virtual void vfn_0308();
    virtual void vfn_030c();
    virtual void vfn_0310();
    virtual void vfn_0314();
    virtual void vfn_0318();
    virtual void vfn_031c();
    virtual void vfn_0320();
    virtual void vfn_0324();
    virtual void vfn_0328();
    virtual void vfn_032c();
    virtual void vfn_0330();
    virtual void vfn_0334();
    virtual void DamageHealthAndFatigue(float, float, Actor*);
    virtual void vfn_033c();
    virtual void vfn_0340();
    virtual void vfn_0344();
    virtual void vfn_0348();
    virtual void vfn_034c();
    virtual void vfn_0350();
    virtual void vfn_0354();
    virtual void vfn_0358();
    virtual void vfn_035c();
    virtual void vfn_0360();
    virtual void vfn_0364();
    virtual void vfn_0368();
    virtual void vfn_036c();
    virtual void vfn_0370();
    virtual void vfn_0374();
    virtual void vfn_0378();
    virtual void vfn_037c();
    virtual void vfn_0380();
    virtual void vfn_0384();
    virtual void vfn_0388();
    virtual void vfn_038c();
    virtual void vfn_0390();
    virtual void vfn_0394();
    virtual void vfn_0398();
    virtual void vfn_039c();
    virtual void vfn_03a0();
    virtual void vfn_03a4();
    virtual void vfn_03a8();
    virtual void vfn_03ac();
    virtual void vfn_03b0();
    virtual void vfn_03b4();
    virtual void vfn_03b8();
    virtual void vfn_03bc();
    virtual void vfn_03c0();
    virtual void vfn_03c4();
    virtual void vfn_03c8();
    virtual void vfn_03cc();
    virtual void vfn_03d0();
    virtual void vfn_03d4();
    virtual void vfn_03d8();
    virtual void vfn_03dc();
    virtual void vfn_03e0();
    virtual void vfn_03e4();
    virtual void vfn_03e8();
    virtual void vfn_03ec();
    virtual void vfn_03f0();
    virtual void vfn_03f4();
    virtual void vfn_03f8();
    virtual void vfn_03fc();
    virtual void vfn_0400();
    virtual void vfn_0404();
    virtual void vfn_0408();
    virtual void vfn_040c();
    virtual void vfn_0410();
    virtual void vfn_0414();
    virtual void vfn_0418();
    virtual void vfn_041c();
    virtual float GetAlpha();
    unsigned char layoutPadding04[0xbc];
    Actor* pKillerEntry;
    void ProcessActorDamage(float, BooleanFloatQuery*);    // @ref 0x0088e8d0 ProcessActorDamage@Actor
    void FUN_0088fb00(float, BooleanFloatQuery*, Actor*);  // @ref 0x0088fb00 FUN_0088fb00
    void Kill(Actor*, float);                              // @ref 0x0089d900 Kill@Actor
    void HandleDismembermentTask(int, int, Actor*);        // @ref 0x008b51b0 HandleDismembermentTask@Actor
    void ProcessQueuedHit(bool, bool);                     // @ref 0x00899200 ProcessQueuedHit@Actor
    void ProcessHitData(BooleanFloatQuery*, char);         // @ref 0x0089a760 ProcessHitData@Actor
    void DismemberLimb(unsigned int, unsigned int, bool, bool, bool, bool);  // @ref 0x008b52a0 DismemberLimb@Actor
    void FUN_008a5f20(bool);                                                 // @ref 0x008a5f20 FUN_008a5f20
    void RefreshActorInteraction(bool, bool);  // @ref 0x008a7d50 RefreshActorInteraction@Actor
    void ProcessQueuedActorUpdate();           // @ref 0x008a1a70 ProcessQueuedActorUpdate@Actor
    void OnLifeStateChanged();                 // @ref 0x00887d00 OnLifeStateChanged@Actor
};
class PlayerCharacter : public Actor
{
};
class Character : public Actor
{
  public:
    void Reset3D();  // @ref 0x008d3fa0 Reset3D@Character
};
class BaseProcess
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual void vfn_00f0();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual void vfn_0100();
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void vfn_0144();
    virtual BSSimpleArray<ParentSpaceNode, 1024>* GetWeaponInfo();
    virtual void vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void Unk_58(void*, NiNode*, bool);
    virtual void vfn_0164();
    virtual void vfn_0168();
    virtual void vfn_016c();
    virtual void vfn_0170();
    virtual void vfn_0174();
    virtual void vfn_0178();
    virtual void vfn_017c();
    virtual void vfn_0180();
    virtual void vfn_0184();
    virtual void vfn_0188();
    virtual void vfn_018c();
    virtual void vfn_0190();
    virtual void vfn_0194();
    virtual void vfn_0198();
    virtual void vfn_019c();
    virtual void vfn_01a0();
    virtual void vfn_01a4();
    virtual void vfn_01a8();
    virtual void vfn_01ac();
    virtual void vfn_01b0();
    virtual void vfn_01b4();
    virtual void vfn_01b8();
    virtual void vfn_01bc();
    virtual void vfn_01c0();
    virtual void vfn_01c4();
    virtual void vfn_01c8();
    virtual void vfn_01cc();
    virtual void vfn_01d0();
    virtual void vfn_01d4();
    virtual void vfn_01d8();
    virtual void vfn_01dc();
    virtual void vfn_01e0();
    virtual void vfn_01e4();
    virtual void vfn_01e8();
    virtual void vfn_01ec();
    virtual void vfn_01f0();
    virtual void vfn_01f4();
    virtual void vfn_01f8();
    virtual void vfn_01fc();
    virtual void vfn_0200();
    virtual void vfn_0204();
    virtual void vfn_0208();
    virtual void vfn_020c();
    virtual void vfn_0210();
    virtual void vfn_0214();
    virtual void vfn_0218();
    virtual void vfn_021c();
    virtual void vfn_0220();
    virtual void vfn_0224();
    virtual void vfn_0228();
    virtual void vfn_022c();
    virtual void vfn_0230();
    virtual void vfn_0234();
    virtual void vfn_0238();
    virtual void vfn_023c();
    virtual void vfn_0240();
    virtual void vfn_0244();
    virtual void vfn_0248();
    virtual void vfn_024c();
    virtual void vfn_0250();
    virtual void vfn_0254();
    virtual void vfn_0258();
    virtual void vfn_025c();
    virtual void vfn_0260();
    virtual void vfn_0264();
    virtual void vfn_0268();
    virtual void vfn_026c();
    virtual void vfn_0270();
    virtual void vfn_0274();
    virtual void vfn_0278();
    virtual void vfn_027c();
    virtual void vfn_0280();
    virtual void vfn_0284();
    virtual void vfn_0288();
    virtual void vfn_028c();
    virtual void vfn_0290();
    virtual void vfn_0294();
    virtual void vfn_0298();
    virtual void vfn_029c();
    virtual void vfn_02a0();
    virtual void vfn_02a4();
    virtual void vfn_02a8();
    virtual void vfn_02ac();
    virtual void vfn_02b0();
    virtual void vfn_02b4();
    virtual void vfn_02b8();
    virtual void vfn_02bc();
    virtual void vfn_02c0();
    virtual void vfn_02c4();
    virtual void vfn_02c8();
    virtual void vfn_02cc();
    virtual void vfn_02d0();
    virtual void vfn_02d4();
    virtual void vfn_02d8();
    virtual void vfn_02dc();
    virtual void vfn_02e0();
    virtual void vfn_02e4();
    virtual void vfn_02e8();
    virtual void vfn_02ec();
    virtual void vfn_02f0();
    virtual void vfn_02f4();
    virtual void vfn_02f8();
    virtual void vfn_02fc();
    virtual void vfn_0300();
    virtual void vfn_0304();
    virtual void vfn_0308();
    virtual void vfn_030c();
    virtual void vfn_0310();
    virtual void vfn_0314();
    virtual void vfn_0318();
    virtual void vfn_031c();
    virtual void vfn_0320();
    virtual void vfn_0324();
    virtual void vfn_0328();
    virtual void vfn_032c();
    virtual void vfn_0330();
    virtual void vfn_0334();
    virtual void vfn_0338();
    virtual void vfn_033c();
    virtual void vfn_0340();
    virtual void vfn_0344();
    virtual void vfn_0348();
    virtual void vfn_034c();
    virtual void vfn_0350();
    virtual void vfn_0354();
    virtual void vfn_0358();
    virtual void vfn_035c();
    virtual void vfn_0360();
    virtual void vfn_0364();
    virtual void vfn_0368();
    virtual void vfn_036c();
    virtual void vfn_0370();
    virtual void vfn_0374();
    virtual void vfn_0378();
    virtual void vfn_037c();
    virtual void vfn_0380();
    virtual void vfn_0384();
    virtual void vfn_0388();
    virtual void vfn_038c();
    virtual void vfn_0390();
    virtual void vfn_0394();
    virtual void vfn_0398();
    virtual void vfn_039c();
    virtual void vfn_03a0();
    virtual void vfn_03a4();
    virtual void vfn_03a8();
    virtual void vfn_03ac();
    virtual void vfn_03b0();
    virtual void vfn_03b4();
    virtual void vfn_03b8();
    virtual void vfn_03bc();
    virtual void vfn_03c0();
    virtual void vfn_03c4();
    virtual void vfn_03c8();
    virtual void vfn_03cc();
    virtual void vfn_03d0();
    virtual void vfn_03d4();
    virtual void vfn_03d8();
    virtual void vfn_03dc();
    virtual void vfn_03e0();
    virtual void vfn_03e4();
    virtual void vfn_03e8();
    virtual void vfn_03ec();
    virtual void vfn_03f0();
    virtual void vfn_03f4();
    virtual void vfn_03f8();
    virtual void vfn_03fc();
    virtual void vfn_0400();
    virtual void vfn_0404();
    virtual void vfn_0408();
    virtual void vfn_040c();
    virtual void vfn_0410();
    virtual void vfn_0414();
    virtual void PushActorAway(Actor*, NiPoint3, float);
};
class HighProcess : public BaseProcess
{
  public:
    void RefreshProcessState(Actor*, TESObjectREFR*, float, float,
                             float);  // @ref 0x008fe9e0 RefreshProcessState@HighProcess
};
class PlayerQuestData
{
  public:
    Date* GetLogDate();  // @ref 0x008d8520 GetLogDate@PlayerQuestData
};
#define TASK_PROCESS(actor) reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())
class MobileObject : public TESObjectREFR
{
  public:
    unsigned int GetCurrentProcessLevel();
    bhkCharacterController*
    GetPhysicsCharacterController();  // @ref 0x009306d0 GetPhysicsCharacterController@MobileObject
};
class BooleanFloatQuery
{
  public:
    Actor* m_pkAttacker;
    char layoutPadding04_pad4[4];
    void* m_pSourceReference;
    int m_uiHitLocation;
    int m_uiHitFlags;
    float afDamageAmount;
    void DecRefCount();  // @ref 0x0087cea0 DecRefCount@BooleanFloatQuery
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    char m_vOffset1[12];
    char m_vOffset2[12];
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
};
class DismemberLimbTaskData
{
  public:
    unsigned int uiLimb;
    int iDismembermentOption;
    Actor* pActor;
};
class TESObjectWEAP
{
  public:
    void Fire(TESObjectREFR*);  // @ref 0x00523150 Fire@TESObjectWEAP
};
class BipedAnim
{
  public:
    static void SetNodeTranslation(NiAVObject*);                   // @ref 0x004ab0c0 SetNodeTranslation@BipedAnim
    static void SetNodeTranslation(NiAVObject*, const NiPoint3&);  // @ref 0x00b553d0 SetNodeTranslation@BipedAnim
    void AttachFaceGenNode();                                      // @ref 0x00571b50 AttachFaceGenNode@BipedAnim
};
class ShadowSceneNode
{
  public:
    void RemoveObject(NiAVObject*);  // @ref 0x00b5b1c0 RemoveObject@ShadowSceneNode
};
class NiAdditionalGeometryData
{
  public:
    static ShadowSceneNode* GetShadowSceneNodeForIndex(
        unsigned int);  // @ref 0x00450b80 GetShadowSceneNodeForIndex@NiAdditionalGeometryData
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool bMultithreaded;
    unsigned int uiFlags;
    void FUN_0043d410(float, bool, bool);  // @ref 0x0043d410 FUN_0043d410
};
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);
class Script
{
  public:
    static void SetReferenceScale(TESObjectREFR*, float);  // @ref 0x005c1c10 SetReferenceScale@Script
    static void MoveReferenceToPosition(TESObjectREFR*, TESObjectREFR*, float, float,
                                        float);  // @ref 0x005ccb20 MoveReferenceToPosition@Script
    static void MatchFaceGeometry(TESObjectREFR*, TESObjectREFR*, int);  // @ref 0x005d9bc0 MatchFaceGeometry@Script
    void SetOwnerQuest(TESQuest*);                                       // @ref 0x0087ce80 SetOwnerQuest@Script
};
void SetPosBase(TESObjectREFR*, unsigned char, float);  // @ref 0x005c0740 SetPosBase
void SetAngleBase(TESObjectREFR*, unsigned char, float);  // @ref 0x005c0b10 SetAngleBase
void FUN_005d3c20(TESObjectREFR*, float);                 // @ref 0x005d3c20 FUN_005d3c20
void FUN_005d4c20(TESObjectREFR*, float);                 // @ref 0x005d4c20 FUN_005d4c20
void UpdateSceneGraph(NiAVObject*);                       // @ref 0x005526f0 UpdateSceneGraph
void UpdateControllersRecursive(NiAVObject*);             // @ref 0x00552790 UpdateControllersRecursive
void FUN_00892460(TESObjectREFR*, bool);                  // @ref 0x00892460 FUN_00892460
void FUN_00c6a270(NiAVObject*, bool, bool, int);          // @ref 0x00c6a270 FUN_00c6a270
void FUN_00c69fc0(NiAVObject*, bool, bool, bool);         // @ref 0x00c69fc0 FUN_00c69fc0
class Creature
{
  public:
    static void SetNodeFlagsRecursive(NiAVObject*, int, bool, bool,
                                      bool);  // @ref 0x00c6a350 SetNodeFlagsRecursive@Creature
    char _pdbpad_1[435];
    bool bRagDoll;
    char _pdbpad_1b5[3];
    float m_fFirstResetValue;
    float m_fSecondValue;
};
void* GetObjectFromNode(NiAVObject*, bool, int);  // @ref 0x00c69ee0 GetObjectFromNode
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();
};
class MagicHitEffect
{
  public:
    static BSSimpleList<MagicHitEffect*>* GetEffectsForActiveEffect(
        ActiveEffect*);  // @ref 0x0081b8e0 GetEffectsForActiveEffect@MagicHitEffect
};
class BGSOpenCloseForm
{
  public:
    static bool SetOpenState(TESObjectREFR*, bool, bool);  // @ref 0x0047aec0 SetOpenState@BGSOpenCloseForm
};
class WaterZoneManager
{
  public:
    void SetWaterHeight(TESObjectREFR*, TESObjectREFR*, float);   // @ref 0x004e5c80 SetWaterHeight@WaterZoneManager
    void UpdateWaterZone(TESObjectREFR*, TESObjectREFR*, float);  // @ref 0x004e5df0 UpdateWaterZone@WaterZoneManager
    void AddWaterRipple(NiPoint3, float);                         // @ref 0x004e8510 AddWaterRipple@WaterZoneManager
};
class TES
{
  public:
    TESObjectCELL* GetDetailedActorPathHandler();  // @ref 0x00457070 GetDetailedActorPathHandler@TES
    WaterZoneManager* GetActorScale();
    void FUN_00453900();  // @ref 0x00453900 FUN_00453900
};
class DetailedActorPathHandler
{
  public:
    static void UpdateSceneNode(NiNode*);  // @ref 0x00552390 UpdateSceneNode@DetailedActorPathHandler
    void HandleReferenceUpdate(TESObjectREFR*, bool,
                               bool);  // @ref 0x0054a070 HandleReferenceUpdate@DetailedActorPathHandler
};
class ExtraDataList
{
  public:
    bhkWorld* GetRoomId();  // @ref 0x004543c0 GetRoomId@ExtraDataList
};
class bhkWorld
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void AddObject(NiAVObject*, bool, bool, int, bool);
    char _pdbpad_4[12];
    void* pDebugger;
    bool bStateChanged;
    bool bEnabled;
    bool m_bFlagAt16;
    char _pdbpad_17[1];
    unsigned int m_uiValueAt18;
    unsigned int m_uiReferenceCount;
    void* pTrapListener;
    void* m_pObjectAt24;
    void* m_pObjectAt28;
    void* m_pObjectAt2C;
    unsigned int m_uiValueAt30;
    void* m_pObjectAt34;
    unsigned int m_uiValueAt38;
    void* m_pObjectAt3C;
    unsigned int m_uiValueAt40;
    void* m_pObjectAt44;
    unsigned int m_uiValueAt48;
    void* m_pObjectAt4C;
    unsigned int m_uiValueAt50;
    char _pdbpad_54[12];
    char Origin[16];
    char m_achDataAt70[12];
    char m_achDataAt7C[12];
    float m_fValueAt88;
    float m_fValueAt8C;
    char ActionEntryList[8];
    char _pdbpad_98[8];
};
class NavMeshObstacleManager
{
  public:
    static NavMeshObstacleManager* GetSingleton();  // @ref 0x006c0720 GetSingleton@NavMeshObstacleManager
    void RemoveObstacleReference(TESObjectREFR*);   // @ref 0x006c0dc0 RemoveObstacleReference@NavMeshObstacleManager
    void AddObstacleReference(TESObjectREFR*);      // @ref 0x006c0f10 AddObstacleReference@NavMeshObstacleManager
};
class TESWaterListener
{
  public:
    static void UpdateWaterHeightAtPosition(float,
                                            NiPoint3);  // @ref 0x0062eb50 UpdateWaterHeightAtPosition@TESWaterListener
};
class bhkCharacterController
{
  public:
    void FUN_005620e0(void*);  // @ref 0x005620e0 FUN_005620e0
    void FUN_0080fb00(void*);  // @ref 0x0080fb00 FUN_0080fb00
    float FUN_005d10f0();      // @ref 0x005d10f0 FUN_005d10f0
    void FUN_0087cee0();       // @ref 0x0087cee0 FUN_0087cee0
    void ResetState();         // @ref 0x00c6e030 ResetState
};
void* FUN_00458b20();  // @ref 0x00458b20 FUN_00458b20
class TaskQueueParallelWork
{
  public:
    void(__cdecl* pCallback)(unsigned int, void*);
    void* pData;
    unsigned int ItemUpdateArray;
    unsigned int uiNext;
    void Construct(void(__cdecl*)(unsigned int, void*), void*, unsigned int);  // @ref 0x0087cf10 Construct
};
class TaskQueueParallelManager
{
  public:
    void FUN_00c44c90(TaskQueueParallelWork*);  // @ref 0x00c44c90 FUN_00c44c90
};
template <class T, unsigned int Growth> class BSScrapArray : public BSSimpleArray<T, Growth>
{
  public:
    void* m_pAllocator;
    BSScrapArray();   // @ref 0x0087d1b0 ??0BSScrapArray
    ~BSScrapArray();  // @ref 0x0087d230 ??1BSScrapArray
};
class BSSimpleArray_SandBoxChoiceListItem_1024_
{
  public:
    void Clear(bool);  // @ref 0x008454f0 Clear@BSSimpleArray_SandBoxChoiceListItem_1024_
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
};
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};                                                              // @ref 0x00408d60 Bool@?$SettingT
void UpdateAnimObjFromTask(unsigned int, void*);                // @ref 0x0087cf50 UpdateAnimObjFromTask
void FUN_0087cfb0(unsigned int, void*);                         // @ref 0x0087cfb0 FUN_0087cfb0
void FUN_0087d030(BSScrapArray<NiPointer<NiAVObject>, 1024>*);  // @ref 0x0087d030 FUN_0087d030
template <class T> class DFALL
{
};
template <class Allocator, class Key, class Value> class NiTMapBase
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, Key&, Value&);
};
NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>*
FUN_0087ce70();                                            // @ref 0x0087ce70 FUN_0087ce70
extern BSSimpleArray<ParentSpaceNode, 1024> DAT_011df244;  // @ref 0x011df244 DAT_011df244
extern BSSimpleArray<ParentSpaceNode, 1024> DAT_011df1c4;  // @ref 0x011df1c4 DAT_011df1c4
extern SettingT<INISettingCollection> DAT_011df1b8;        // @ref 0x011df1b8 DAT_011df1b8
extern TaskQueueParallelManager* DAT_01202df4;             // @ref 0x01202df4 DAT_01202df4
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;
int Warning(const char*, ...);
void operator delete(void*);
extern bool DAT_011a31f4;
extern "C" __declspec(dllimport) void __stdcall DebugBreak();

class InterfaceManager
{
  public:
    void FUN_00984f60(unsigned int);
    void ClearActivatePickResults();
};

class QuestStage
{
  public:
    unsigned char GetIndex();
};

InterfaceManager* FUN_004b7210();
#endif

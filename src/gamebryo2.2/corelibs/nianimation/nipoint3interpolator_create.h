#ifndef FNV_NIPOINT3INTERPOLATOR_CREATE_H
#define FNV_NIPOINT3INTERPOLATOR_CREATE_H

class NiPointLight
{
  public:
    char storage[252];
    static void* operator new(unsigned int);
    static void operator delete(void*);
    NiPointLight();
};
class StateNode
{
  public:
    void ResetCameraState();
};
class ImageSpaceModifierInstanceDOF
{
  public:
    void FUN_005bbd60(bool);
};
void FUN_005293f0(ImageSpaceModifierInstanceDOF*);
class NiPoint2
{
  public:
    float x, y;
    NiPoint2(float, float);
};
union SETTING_VALUE
{
  public:
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ DAT_011ce424, DAT_011ce564, DAT_011ce6d8, DAT_011cf1f8;
ImageSpaceModifierInstanceDOF* FUN_0052a440(float, float, float, float, float, NiPoint2*, float);
class VATS
{
  public:
    class LightTarget* FUN_005d8710();
    void SetLight(NiPointLight*, bool);
    void SetCurrentTarget(class TESObjectREFR*);
};
class LightTarget
{
  public:
    class NiAVObject* GetLight();
};
class Interface
{
  public:
    static class ShadowLightData* GetVATSEffect();
};
class ShadowLightData
{
  public:
    void FUN_008009d0();
};
class HUDMainMenu
{
  public:
    static void UpdateVisibilityState(int);
};
class Actor
{
  public:
    bool UnEquipObject(class TESBoundObject*, int, class ExtraDataList*, bool, bool, bool);
    bool CanStartCombat(bool);
};
class PlayerCharacter : public Actor
{
  public:
    void SetAimingWeapon(bool, bool, bool);
};
class InputManager
{
  public:
    void FUN_00a25410();
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720(int);
};
class GameTimerRecord
{
  public:
    void SetGlobalTimeMultiplier(float, bool);
};
class GlobalObject_009c6a30
{
};
class TimeGlobal
{
};
extern GlobalObject_009c6a30 g_011f2250;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern OSGlobals* g_osGlobals;
class ShadowSceneNode
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
    virtual void vfn_e8(class NiAVObject*);
    void AttachLight(class NiAVObject*);
};
ShadowSceneNode* FUN_00450b80(int);
class ExtraDataList
{
  public:
    void Set3DObject(class NiAVObject*);
};
class TemporaryEffect
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual ~TemporaryEffect();
};
extern TemporaryEffect* DAT_011f21e8;
extern TemporaryEffect* DAT_011f21ec;
extern TESObjectREFR* DAT_011f21cc;
extern PlayerCharacter* DAT_011f21f0;
extern int DAT_011f21b8, DAT_011f21c0, DAT_011f21c4, DAT_011f21c8, DAT_011f21dc;
extern bool DAT_011f21d0, DAT_011f21d2, DAT_011f21d3, DAT_011f21e4;
extern float DAT_011f21d4, DAT_011f21d8;
extern const float DAT_01016248;
void FUN_009c7190(bool);
#endif

// fallout/interface/forenderedmenu_decls.h: declares FORenderedMenu, BSAudio, TimeGlobal, NiFixedString, NiPoint3 and more

#include <stddef.h>

#ifndef FNV_FORENDEREDMENU_DECLS_H
#define FNV_FORENDEREDMENU_DECLS_H

class NiGeometry;
class ShadowSceneNode;
class BSShaderAccumulator;
class NiAVObject;
class NiScreenElements;
class NiTexture;
class NiPointLight;
class NiCamera;
class Tile;
class NiColor;
class NiObject;
class NiProperty;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};

#pragma pack(push, 4)
class FORenderedMenu
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiGeometry> m_pMenuBackgroundScreenGeometry;
    NiPointer<NiAVObject> m_pMenuRoot;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiTexture> m_pDefaultTexture;
    NiPointer<NiAVObject> m_pRenderedMenuObject;
    Tile* m_pFourthMenuObject;
    NiPointer<NiPointLight> m_pMenuLight;
    ShadowSceneNode* m_pSecondaryMenuObject;
    NiPointer<NiCamera> m_pMenuLightParameters;
    bool bInitialized;
    bool m_bUseMenuImageSpaceEffects;
    bool m_bEnableFlicker;
    unsigned char layoutPadding2B;
    float m_kScreenLightColor[3];
    float fScreenLightBaseIntensity;
    float m_fFlicker;
    float fBlurRadius;
    float fBlurIntensity;
    float m_fScanlineScale;
    bool m_bDoScanlines;
    bool m_bBurstActive;
    unsigned char layoutPadding4E[2];
    float m_fBurstElapsedTime;
    float fBurstDuration;
    float m_fBurstIntensity;
    float m_fBurstSoundChance;
    char padding60_pad60[4];
    float m_fShudderIntensity;
    float m_fShudderDuration;
    float m_fShudderFrequency;
    float m_fVerticalHoldDuration;
    bool m_bVerticalHoldActive;
    char padding60_pad75[3];
    float m_fVerticalHoldSpeed;
    float m_fVerticalHoldRate;
    float m_fVerticalHoldChance;
    float m_fShudderChance;
    float m_fPulseRadiusIntensity;
    float m_fPulseBrightenIntensity;
    float m_fPulseRate;
    bool m_bPulseActive;
    bool m_bShudderActive;
    char padding60_pad96[2];
    float m_fDistortHorizontalScale;
    float m_fDistortVerticalScale;
    float fDistortDuration;
    float m_fDistortTimeRemaining;
    char BackgroundColor[16];
    bool m_bMenuLightEnabled;
    bool m_bMenuLightCreated;
    char padding60_padba[2];
    NiPointer<NiTexture> m_pMenuLightShadowNode;
    char paddingC0_padc0[16];
    bool m_bMenuLightVisible;
    bool m_bMenuLightShadowed;
    bool m_bMenuLightAttached;
    char paddingC0_padd3[1];
    NiPointer<BSShaderAccumulator> m_pMenuLightNode;

    NiAVObject* GetMenuRoot();
    void FUN_007fc6f0();
    bool CreateMenuLight(const char*, ShadowSceneNode*);
    void OnMenuOpen();
    void SetDefaultTexture(NiTexture*);
    void GetCurrentTimeMilliseconds();
    void StartBurst(float duration, float intensity, float soundChance);
};
#pragma pack(pop)

typedef char FNV_ASSERT_menu_root_offset[(offsetof(FORenderedMenu, m_pRenderedMenuObject) == 0x14) ? 1 : -1];
typedef char FNV_ASSERT_burst_active_offset[(offsetof(FORenderedMenu, m_bBurstActive) == 0x4D) ? 1 : -1];
typedef char FNV_ASSERT_burst_duration_offset[(offsetof(FORenderedMenu, fBurstDuration) == 0x54) ? 1 : -1];

#pragma pack(push, 4)
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int eState;

    SoundPlaybackHandle();
    SoundPlaybackHandle(const SoundPlaybackHandle&);
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    ~SoundPlaybackHandle();
    bool Play(bool loopPlayback);
};
#pragma pack(pop)

typedef char FNV_ASSERT_sound_handle_size[(sizeof(SoundPlaybackHandle) == 12) ? 1 : -1];

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};

class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

extern TimeGlobal g_timeGlobal;
extern bool g_burstSoundEnabled;
bool __cdecl RandomBoolean(float chance);

class NiFixedString
{
  public:
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
};
struct NiPoint3
{
    float x, y, z;
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    unsigned int unused;
    NiUpdateData(float, bool, bool);
};
class NiNode;
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual NiNode* GetAsNiNode();
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

    virtual NiAVObject* GetObjectByName(const NiFixedString&);
    NiNode* GetParent();
    void FUN_00440460(const NiPoint3&);
    NiPoint3& FUN_0043c490();
    void Update(NiUpdateData&);
    void SetName(const NiFixedString&);
    void SetAppCulled(bool);
    NiFixedString& GetName();
    void AttachProperty(NiObject*);
    void UpdateSceneObject();
};
class NiNode : public NiAVObject
{
  public:
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

    virtual void AddObject(NiAVObject*, bool);
};
class NiPointLight : public NiAVObject
{
  public:
    unsigned char storage[0xfc - 4];
    NiPointLight();
    static void* operator new(size_t);
    static void operator delete(void*);
};
class NiGeometry : public NiAVObject
{
  public:
    NiProperty* GetProperty(int);
};
class ShadowSceneLight;
class NiLight;
class ShadowSceneNode
{
  public:
    ShadowSceneLight* GetShadowSceneLight(NiLight*, bool);
};
ShadowSceneNode* FUN_00450b80(unsigned int);
struct NiRTTI;
extern NiRTTI DAT_011f4a98;
NiAVObject* NiDynamicCast(const NiRTTI*, NiAVObject*);
int Warning(const char*, ...);
class BSShaderManager
{
  public:
    enum BATCHRENDERER_CREATION_MODE
    {
        Interface = 100
    };
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
};
class BSShaderAccumulator
{
  public:
    unsigned int storage[0x280 / 4];
    BSShaderAccumulator(BSShaderManager::BATCHRENDERER_CREATION_MODE, unsigned int, unsigned int);
    static void* operator new(size_t);
    static void operator delete(void*);
    void FUN_004a1040(unsigned int);
};
union SETTING_VALUE
{
    float f;
    const char* s;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
    const char* String();
};
extern SettingT_GameSettingCollection_ DAT_011db44c;
extern SettingT_GameSettingCollection_ DAT_011db470;
extern SettingT_GameSettingCollection_ DAT_011db3d8;

class NiObject
{
};
class NiProperty : public NiObject
{
  public:
    void FUN_00438230(NiTexture*);
    void FUN_004bc450(const NiColor*);
};
class NiAlphaProperty : public NiProperty
{
  public:
    unsigned char storage[0x1c];
    NiAlphaProperty();
    static void* operator new(size_t);
    static void operator delete(void*);
    void FUN_0049ed90(bool);
    void SetSrcBlendMode(int);
    void SetDestBlendMode(int);
};
class FOPipboyManager : public FORenderedMenu
{
  public:
    void FUN_007fc2d0(NiAVObject*);
    char m_pPipBoyObject0[4];
    char m_pPipBoyObject1[4];
    char m_pPipBoyObject2[4];
    char spPartialScreenGeometry_db[4];
    char m_cPipBoyButtonAvailability[12];
    char m_pButtonGlowObjects[12];
    char m_pGaugeObjects[12];
    char m_fChartFirstPoint[12];
    char m_fChartSecondPoint[12];
    char m_fGaugeValues2[12];
    char m_fTabKnobPositions[20];
    bool bScaledTexCoords_db;
    char _pdbpad_145[3];
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    char _pdbpad_151[3];
    char m_kPipBoyLightData[12];
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    char _pdbpad_163[1];
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    char _pdbpad_16d[3];
};
unsigned int FUN_00438220();
unsigned int FUN_004af350();
extern NiColor DAT_011f4998;
#endif

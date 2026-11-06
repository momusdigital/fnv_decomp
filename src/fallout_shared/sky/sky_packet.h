// fallout_shared/sky/sky_packet.h: declares TESForm_SkyExt, TESClimate, SkyObject, NiColor, Renderer and more
#ifndef FNV_SKY_PACKET_H
#define FNV_SKY_PACKET_H

// Shared classes come from the canonical include/ headers: TESForm (all 78 PC virtual slots), AutoMemContext and
// MEM_CONTEXT, BSSimpleList. Explicit ../../../include/ paths (case-insensitive shadows in src/fallout_shared).
// Unit-local supersets of canonical leaf types (same layout), for members the canonical headers lack:
//   NiPointer: out-of-line ctor(T*), dtor, operator=(T*), operator T*, ->, ==, != (Gamebryo smart-pointer API).
//   NiPoint3: (float,float,float) ctor (0x00416870).
// Still unit-local (no canonical header): TESClimate, TESWeather, SkyObject, Sky, Clouds, Precipitation, NiColor,
// Renderer, BGSLoadGameBuffer, and the SettingT<GameSettingCollection>::Float accessor.
// first-definition-wins type index shows them (not the renamed canonical text).
#include "sky_local_types.h"
#define NiPointer FNV_NiPointer_Canonical
#define NiPoint3 FNV_NiPoint3_Canonical
#include "../../../include/layout_support.h"
#include "../../../include/NiPoint3.h"
#undef NiPoint3
#undef NiPointer
FNV_STATIC_ASSERT(sizeof(NiPoint3) == sizeof(FNV_NiPoint3_Canonical));
#include "../../../include/TESForm.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/SETTING_VALUE.h"
class TESForm_SkyExt : public TESForm
{
  public:
    static TESForm* GetFormByID(unsigned int);
};
class TESClimate : public TESForm
{
};
class Sky;
class SkyObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void Update(Sky*, float);
};
class NiColor
{
  public:
    float r, g, b;
    NiColor();
};
class Renderer
{
  public:
    static bool SetBackgroundColor(NiColor&);
};
class TESWeather : public TESForm
{
};
class Clouds
{
  public:
    void ClearCloudLayers();
    void FUN_0063a610();
};
class Precipitation
{
  public:
    void FlushAll();
};
class BGSSaveLoadGame
{
  public:
    bool FUN_0063ef00();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class BGSLoadGameBuffer
{
  public:
    virtual unsigned char GetVersion();
    unsigned int ReadFormIdentifier();
    void ReadDataBlock(void*, unsigned int);
};
class NiAVObject;
class SkySound;
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GameSettingCollection;
template <class T> class SettingT : public SettingT_GameSettingCollection_
{
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting76;
extern NiColor DAT_011a9b7c;
void* operator new(unsigned int);
class Sky
{
  public:
    virtual ~Sky();
    NiPointer<NiAVObject> m_pRootNode, m_pSkyNode;
    TESClimate* m_pCurrentClimate;
    TESWeather *m_pRegionWeather, *m_pPreviousWeather, *m_pQueuedWeather, *m_pOverrideWeather;
    SkyObject* m_pAtmosphere;
    SkyObject* m_pStars;
    SkyObject* m_pSun;
    Clouds* m_pClouds;
    SkyObject *m_pPrimaryMoon, *m_pSecondaryMoon;
    Precipitation* m_pPrecipitation;
    NiColor m_kSkyColors[10];
    NiPoint3 m_kSunlightColor, m_kSkyColor;
    float m_fCurrentWeatherBlend, m_fTargetWeatherBlend, m_fCloudLayerAlpha[4], m_fFogNearDistance, m_fFogPower;
    float m_fFogFarDistance, fWeatherChance, m_fWeatherBlend;
    unsigned int eMode;
    BSSimpleList<SkySound*>* m_pSkySounds;
    float m_fWeatherFade;
    unsigned int field104, field108;
    float field10c, field110;
    unsigned int field114, flags;
    void *field11c, *field120, *field124, *field128;
    float field12c, field130, field134;
    Sky();
    void FUN_0063a030(bool);
    void LoadGame(BGSLoadGameBuffer*);
    void Update(float);
    void UpdateHDRValues();
    void SetCurrentClimate(TESClimate*, bool);
    void FUN_0063c9f0();
    void ResetWeather();
    void UpdateColors();
    void UpdateFog();
    void UpdateWeatherTransition(float);
};

#endif

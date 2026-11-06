// Unit-private declarations for the new processlists.cpp matches.
// Placeholders live here so they can be renamed later in one place.
#ifndef FNV_PROCESSLISTS_PRIVATE_DECLS_H
#define FNV_PROCESSLISTS_PRIVATE_DECLS_H


class MobileObject;

// Placeholder carrier for canonical binding ?IsUnk28Set@FOPipboyManager@@QAE_NXZ.
class FOPipboyManager
{
  public:
    unsigned char pad0028[0x28];
    bool bUnk28;  // +0x28
    bool IsUnk28Set();
    char _pdbpad_29[175];
    char m_pPipBoyObject0[4];
    char m_pPipBoyObject1[4];
    char m_pPipBoyObject2[4];
    char m_pScreenGeometry[4];
    char m_cPipBoyButtonAvailability[12];
    char m_pButtonGlowObjects[12];
    char m_pGaugeObjects[12];
    char m_fChartFirstPoint[12];
    char m_fChartSecondPoint[12];
    char m_fGaugeValues2[12];
    char m_fTabKnobPositions[20];
    bool m_bUseMenuImageSpaceEffects;
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

// 0x00408d60 canonical binding: ?Bool@?$SettingT@VINISettingCollection@@@@QAEPATSETTING_VALUE@@XZ
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};

class INISettingCollection;

template <class T> class SettingT
{
  public:
    void* vptr_;           // +0x0 (Setting base vtable, layout only)
    SETTING_VALUE uValue;  // +0x4
    SETTING_VALUE* Bool();
};

// Placeholder globals.
extern int DAT_01202800;
extern MobileObject* DAT_011e0e38;

// 0x00c68f00 canonical binding: ?SetWorldActive@bhkWorld@@QAEX_N@Z
void ProcessPendingItems();

class bhkWorld
{
  public:
    char pad001c_pad0[16];
    void* pDebugger;
    bool bStateChanged;
    bool bEnabled;
    bool m_bFlagAt16;
    char pad001c_pad17[1];
    unsigned int m_uiValueAt18;
    unsigned int unk1C;  // +0x1C
    char pad0050_pad20[4];
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
    unsigned int unk50;  // +0x50
    void ReleaseBodies();
    void ClearReferences();
    void ClearEntries();
    void FlushEntries();
    void SetWorldActive(bool arg);
    char _pdbpad_54[12];
    char Origin[16];
    char m_achDataAt70[12];
    char m_achDataAt7C[12];
    float m_fValueAt88;
    float m_fValueAt8C;
    char ActionEntryList[8];
    char _pdbpad_98[8];
};

extern float DAT_011e0e2c;
extern double DAT_0108c160;
extern "C" int FNV_IsNaN(double);
extern "C" int FNV_Finite(double);
class Crime
{
  public:
    void FUN_009ec400(BGSLoadGameBuffer*);
};
int MinInt(int, int);
class TESGlobal;
template <class K, class V> class NiTMap
{
  public:
    static void NewItem();
};
namespace bsrandom_singleton {
class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
};
}
void FUN_004ee7d0();
void RemoveAllDecals();
class MagicShaderHitEffect;
class NiAVObject;
class BGSTerrainManager
{
  public:
    unsigned int GetMinLevel();
};
class GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_011dc804;
bool FUN_0043b300(const NiRTTI*, NiAVObject*);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESWATERFORM_H
#define FNV_TESWATERFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
#include "layout_support.h"
class BGSPlaceableWater;
class BSRenderedTexture;
class RgbaColor;
class NiTexture;
class TESAttackDamageForm;
class TESWaterForm;
class WaterShaderSettings;
#pragma pack(push, 4)
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    void SetAttackDamage(unsigned short);
    unsigned short m_usAttackDamage;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // TESAttackDamageForm
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    // bool __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    // GetAttackDamage
    // void __cdecl TESAttackDamageForm::*(unsigned short)
    // TESAttackDamageForm& __cdecl TESAttackDamageForm::*(const TESAttackDamageForm&)
    // void* __cdecl TESAttackDamageForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttackDamageForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESAttackDamageForm, m_usAttackDamage) == 4);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class WaterShaderSettings
{
  public:
    float SplatterSettings;                        // +0x0, 4 bytes
    float m_fSecondParameter;                      // +0x4, 4 bytes
    float m_fThirdParameter;                       // +0x8, 4 bytes
    float m_fFourthSetting;                        // +0xC, 4 bytes
    float SevenFloatParameterData;                 // +0x10, 4 bytes
    float SevenFloatParameters;                    // +0x14, 4 bytes
    float SevenFloatData;                          // +0x18, 4 bytes
    float m_fEighthParameter;                      // +0x1C, 4 bytes
    float FiveFloatAndTwoUnsignedIntegerRecord;    // +0x20, 4 bytes
    float FourFloatAndThreeUnsignedIntegerRecord;  // +0x24, 4 bytes
    unsigned int FloatColorSettingsRecord;         // +0x28, 4 bytes
    unsigned int ShaderColorParameterBlock;        // +0x2C, 4 bytes
    unsigned int ColorSettingsRecord;              // +0x30, 4 bytes
    unsigned char m_ucSplatterMode;                // +0x34, 1 bytes
    unsigned char layoutPadding35[3];
    float SplatterColorSettings;               // +0x38, 4 bytes
    float SplatterScalarSettings;              // +0x3C, 4 bytes
    float SplatterFloatSettings;               // +0x40, 4 bytes
    float SplatterParameterSet;                // +0x44, 4 bytes
    float SplatterTimingSettings;              // +0x48, 4 bytes
    float SevenFloatRecordWithGlobals;         // +0x4C, 4 bytes
    float SevenFloatRecordWithStepAndGlobals;  // +0x50, 4 bytes
    float SevenFloatRecordWithStep;            // +0x54, 4 bytes
    float SevenFloatFormatBlock;               // +0x58, 4 bytes
    float SevenFloatRecordWithUnitValue;       // +0x5C, 4 bytes
    float SevenFloatParameterSet;              // +0x60, 4 bytes
    float SevenFloatParameterCollection;       // +0x64, 4 bytes
    float SevenFloatParameterGroup;            // +0x68, 4 bytes
    float SevenFloatValues;                    // +0x6C, 4 bytes
    float SevenFloatSet;                       // +0x70, 4 bytes
    float SevenFloatBlock;                     // +0x74, 4 bytes
    float WaterFogParameters;                  // +0x78, 4 bytes
    float m_fWaterFogParameter1;               // +0x7C, 4 bytes
    float m_fValueBeforeWaterFogSettings;      // +0x80, 4 bytes
    float WaterFogSettings;                    // +0x84, 4 bytes
    float WaterFogParameterData;               // +0x88, 4 bytes
    float fUnderwaterFogAmount;                // +0x8C, 4 bytes
    float fUnderwaterFogDistNear;              // +0x90, 4 bytes
    float fUnderwaterFogDistFar;               // +0x94, 4 bytes
    float WaterShaderProperties;               // +0x98, 4 bytes
    float m_fShininess;                        // +0x9C, 4 bytes
    float WaterShaderParameters;               // +0xA0, 4 bytes
    float MaterialParametersWithLeadingFloat;  // +0xA4, 4 bytes
    float MaterialParameters;                  // +0xA8, 4 bytes
    float m_fWaterParameter1;                  // +0xAC, 4 bytes
    float m_fWaterParameter2;                  // +0xB0, 4 bytes
    float m_fWaterParameter3;                  // +0xB4, 4 bytes
    float m_fWaterParameter4;                  // +0xB8, 4 bytes
    float m_fWaterParameter5;                  // +0xBC, 4 bytes
    float m_fWaterParameter6;                  // +0xC0, 4 bytes
    void Initialize();
    void Endian();
    // void __cdecl WaterShaderSettings::*()
    // void __cdecl WaterShaderSettings::*()
    // void __cdecl WaterShaderSettings::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WaterShaderSettings) == 196);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterSettings) == 0);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fSecondParameter) == 4);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fThirdParameter) == 8);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fFourthSetting) == 12);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatParameterData) == 16);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatParameters) == 20);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatData) == 24);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fEighthParameter) == 28);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, FiveFloatAndTwoUnsignedIntegerRecord) == 32);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, FourFloatAndThreeUnsignedIntegerRecord) == 36);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, FloatColorSettingsRecord) == 40);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, ShaderColorParameterBlock) == 44);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, ColorSettingsRecord) == 48);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_ucSplatterMode) == 52);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterColorSettings) == 56);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterScalarSettings) == 60);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterFloatSettings) == 64);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterParameterSet) == 68);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SplatterTimingSettings) == 72);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatRecordWithGlobals) == 76);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatRecordWithStepAndGlobals) == 80);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatRecordWithStep) == 84);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatFormatBlock) == 88);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatRecordWithUnitValue) == 92);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatParameterSet) == 96);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatParameterCollection) == 100);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatParameterGroup) == 104);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatValues) == 108);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatSet) == 112);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, SevenFloatBlock) == 116);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, WaterFogParameters) == 120);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterFogParameter1) == 124);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fValueBeforeWaterFogSettings) == 128);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, WaterFogSettings) == 132);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, WaterFogParameterData) == 136);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, fUnderwaterFogAmount) == 140);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, fUnderwaterFogDistNear) == 144);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, fUnderwaterFogDistFar) == 148);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, WaterShaderProperties) == 152);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fShininess) == 156);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, WaterShaderParameters) == 160);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, MaterialParametersWithLeadingFloat) == 164);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, MaterialParameters) == 168);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter1) == 172);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter2) == 176);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter3) == 180);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter4) == 184);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter5) == 188);
FNV_STATIC_ASSERT(offsetof(WaterShaderSettings, m_fWaterParameter6) == 192);
#pragma pack(push, 4)
class TESWaterForm : public TESForm, public TESFullName, public TESAttackDamageForm
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    // base TESAttackDamageForm at +0x24, size 8
    bool m_bNeedsUpdate;  // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    NiPointer<BSRenderedTexture> m_pRenderedTexture;  // +0x30, 4 bytes
    RgbaColor m_kTextureScrollLayer0;                 // +0x34, 16 bytes
    RgbaColor m_kTextureScrollLayer1;                 // +0x44, 16 bytes
    RgbaColor m_kTextureScrollLayer2;                 // +0x54, 16 bytes
    TESTexture m_kNoiseMapTexture;                    // +0x64, 12 bytes
    unsigned char m_ucOpacity;                        // +0x70, 1 bytes
    unsigned char cFlags;                             // +0x71, 1 bytes
    unsigned char layoutPadding72[2];
    BSStringT<char> m_kMaterialId;             // +0x74, 8 bytes
    TESSound* m_pWaterSound;                   // +0x7C, 4 bytes
    TESWaterForm* m_pWaterForm;                // +0x80, 4 bytes
    WaterShaderSettings Data;                  // +0x84, 196 bytes
    TESWaterForm* m_apWaterForms[3];           // +0x148, 12 bytes
    int m_iCurrentTextureSelection1;           // +0x154, 4 bytes
    int m_iCurrentTextureSelection2;           // +0x158, 4 bytes
    unsigned int m_uiNoiseFrequencyX;          // +0x15C, 4 bytes
    unsigned int m_uiNoiseFrequencyY;          // +0x160, 4 bytes
    int m_iNoiseOctaveCount;                   // +0x164, 4 bytes
    float m_fNoiseAmplitude;                   // +0x168, 4 bytes
    float m_fNoiseLacunarity;                  // +0x16C, 4 bytes
    float fSideOffset;                         // +0x170, 4 bytes
    float m_fDistanceScale;                    // +0x174, 4 bytes
    SpellItem* m_pWaterSpell;                  // +0x178, 4 bytes
    NiPointer<NiTexture> m_kNoiseTextureData;  // +0x17C, 4 bytes
    BGSPlaceableWater* m_pPlaceableAutoWater;  // +0x180, 4 bytes
    BGSPlaceableWater* m_pPlaceableWater;      // +0x184, 4 bytes
    int m_iRadiationMagnitude;                 // +0x188, 4 bytes
    int m_iHealthMagnitude;                    // +0x18C, 4 bytes
    bool m_bResetNoiseTextures;                // +0x190, 1 bytes
    unsigned char layoutPadding191[3];
    void ResetFormData();
    virtual void InitItem();
    virtual bool Load(TESFile*);
    void SetSpellItem(SpellItem*);
    WaterShaderSettings* FUN_0057eef0();
    // TESWaterForm
    // void __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*()
    // bool __cdecl TESWaterForm::*(TESFile*)
    // void __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(TESForm*)
    // bool __cdecl TESWaterForm::*(TESForm*)
    // void __cdecl TESWaterForm::*()
    // bool __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(bool)
    // unsigned int __cdecl TESWaterForm::*()
    // const char* __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(const char*)
    // void __cdecl TESWaterForm::*(NiPointer<NiTexture>&)
    // void __cdecl TESWaterForm::*(NiTexture*)
    // float __cdecl TESWaterForm::*()
    // SpellItem* __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(SpellItem*)
    // int __cdecl TESWaterForm::*()
    // int __cdecl TESWaterForm::*()
    // const char* __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(const char*)
    // WaterShaderSettings* __cdecl TESWaterForm::*()
    // unsigned int __cdecl TESWaterForm::*()
    // SetShallowColor
    // unsigned int __cdecl TESWaterForm::*()
    // SetDeepColor
    // unsigned int __cdecl TESWaterForm::*()
    // SetReflectionColor
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(TESSound*)
    // TESSound* __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(WATER_WEATHER_CONTROL, TESWaterForm*)
    // TESWaterForm* __cdecl TESWaterForm::*(WATER_WEATHER_CONTROL)
    // float __cdecl TESWaterForm::*()
    // float __cdecl TESWaterForm::*()
    // BGSPlaceableWater* __cdecl TESWaterForm::*()
    // BGSPlaceableWater* __cdecl TESWaterForm::*()
    // bool __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(bool)
    // bool __cdecl TESWaterForm::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // TESWaterForm* __cdecl TESWaterForm::*()
    // void __cdecl TESWaterForm::*(TESWaterForm*)
    // void __cdecl TESWaterForm::*(BGSSaveFormBuffer*)
    // void __cdecl TESWaterForm::*(BGSLoadFormBuffer*)
    // void __cdecl TESWaterForm::*(BGSLoadFormBuffer*)
    // TESWaterForm& __cdecl TESWaterForm::*(const TESWaterForm&)
    // void __cdecl TESWaterForm::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESWaterForm) == 404);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_bNeedsUpdate) == 44);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pRenderedTexture) == 48);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kTextureScrollLayer0) == 52);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kTextureScrollLayer1) == 68);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kTextureScrollLayer2) == 84);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kNoiseMapTexture) == 100);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_ucOpacity) == 112);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, cFlags) == 113);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kMaterialId) == 116);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pWaterSound) == 124);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pWaterForm) == 128);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, Data) == 132);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_apWaterForms) == 328);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_iCurrentTextureSelection1) == 340);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_iCurrentTextureSelection2) == 344);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_uiNoiseFrequencyX) == 348);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_uiNoiseFrequencyY) == 352);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_iNoiseOctaveCount) == 356);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_fNoiseAmplitude) == 360);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_fNoiseLacunarity) == 364);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, fSideOffset) == 368);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_fDistanceScale) == 372);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pWaterSpell) == 376);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_kNoiseTextureData) == 380);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pPlaceableAutoWater) == 384);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_pPlaceableWater) == 388);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_iRadiationMagnitude) == 392);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_iHealthMagnitude) == 396);
FNV_STATIC_ASSERT(offsetof(TESWaterForm, m_bResetNoiseTextures) == 400);
#endif

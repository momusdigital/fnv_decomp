
#include "imagespacemodifierinstance_calls.h"
#include "NiObject.h"
#include "TESForm.h"
// Source unit: fallout_shared/imagespacemodifierinstance.cpp
//
// which are not canonical source. Only call-protocol member declarations
// were added; data members, order, packing and layout asserts are unchanged.

class ImageSpaceModifierInstance;
class ImageSpaceModifierInstanceForm;
class ImageSpaceModifierInstanceTemp;
class NiAVObject;
class TESImageSpaceModifier;

// NiPointer<NiAVObject> exposes the conversion operator the instance code
// calls (folded at 0x00559450); declared here as an explicit specialization.
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    __forceinline NiPointer(NiAVObject* object)
    {
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
    }
    ~NiPointer();
    operator NiAVObject*() const;
};
FNV_STATIC_ASSERT(sizeof(NiPointer<NiAVObject>) == 4);

#pragma pack(push, 4)
class ImageSpaceModifierInstance : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    bool m_bHasBeenApplied;  // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    float fWaterLevelItem;                   // +0xC, 4 bytes
    NiPointer<NiAVObject> m_spTargetObject;  // +0x10, 4 bytes
    float m_fStartTime;                        // +0x14, 4 bytes
    unsigned int iFlags;                     // +0x18, 4 bytes
    // ImageSpaceModifierInstance
    // Call-protocol declarations added by the matcher unit; layout unchanged.
    ImageSpaceModifierInstance(float, float, NiAVObject*);
    ~ImageSpaceModifierInstance();
    static float GetTime();
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
    virtual ImageSpaceModifierInstanceForm* GetInstanceForm();
    // void __cdecl ImageSpaceModifierInstance::*()
    // void __cdecl ImageSpaceModifierInstance::*(float)
    // float __cdecl ImageSpaceModifierInstance::*()
    // void __cdecl ImageSpaceModifierInstance::*(float)
    // float __cdecl ImageSpaceModifierInstance::*()
    // void __cdecl ImageSpaceModifierInstance::*(NiAVObject*)
    // NiAVObject* __cdecl ImageSpaceModifierInstance::*()
    // void __cdecl ImageSpaceModifierInstance::*(bool)
    // bool __cdecl ImageSpaceModifierInstance::*()
    // void __cdecl ImageSpaceModifierInstance::*(ImageSpaceModifierInstance*)
    // ImageSpaceModifierInstance& __cdecl ImageSpaceModifierInstance::*(const ImageSpaceModifierInstance&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstance) == 28);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstance, m_bHasBeenApplied) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstance, fWaterLevelItem) == 12);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstance, m_spTargetObject) == 16);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstance, m_fStartTime) == 20);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstance, iFlags) == 24);
#pragma pack(push, 4)
class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance, public NiMemObjectAllocation
{
  public:
    // base ImageSpaceModifierInstance at +0x0, size 28
    TESImageSpaceModifier* m_pPreviousImageSpaceModifier;  // +0x1C, 4 bytes
    TESImageSpaceModifier* m_pImageSpaceModifier;          // +0x20, 4 bytes
    float m_fBlendWeight;                                  // +0x24, 4 bytes
    NiPointer<NiAVObject> m_pTargetNode;                   // +0x28, 4 bytes
    float m_fElapsedTime;                                  // +0x2C, 4 bytes
    // ImageSpaceModifierInstanceForm
    // Call-protocol declarations added by the matcher unit; layout unchanged.
    ImageSpaceModifierInstanceForm(TESImageSpaceModifier*, float, float, NiAVObject*);
    static void Stop(TESImageSpaceModifier*);
    TESImageSpaceModifier* GetImageSpaceMod();
    static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier*, float, NiAVObject*);
    bool IsExpired();
    void Apply();
    // void __cdecl ImageSpaceModifierInstanceForm::*()
    // bool __cdecl ImageSpaceModifierInstanceForm::*()
    // void __cdecl ImageSpaceModifierInstanceForm::*()
    // ImageSpaceModifierInstanceForm* __cdecl ImageSpaceModifierInstanceForm::*()
    // void __cdecl ImageSpaceModifierInstanceForm::*(TESImageSpaceModifier*)
    // TESImageSpaceModifier* __cdecl ImageSpaceModifierInstanceForm::*()
    // bool __cdecl ImageSpaceModifierInstanceForm::*(TESImageSpaceModifier*, float, float, NiAVObject*)
    // ImageSpaceModifierInstanceForm* __cdecl ImageSpaceModifierInstanceForm::*(TESImageSpaceModifier*, float, NiAVObject*)
    // ImageSpaceModifierInstanceForm* __cdecl ImageSpaceModifierInstanceForm::*(TESImageSpaceModifier*, float, NiAVObject*)
    // void __cdecl ImageSpaceModifierInstanceForm::*(TESImageSpaceModifier*)
    // void __cdecl ImageSpaceModifierInstanceForm::*(char*)
    // ImageSpaceModifierInstanceForm& __cdecl ImageSpaceModifierInstanceForm::*(const ImageSpaceModifierInstanceForm&)
    // void __cdecl ImageSpaceModifierInstanceForm::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceForm) == 48);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceForm, m_pPreviousImageSpaceModifier) == 28);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceForm, m_pImageSpaceModifier) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceForm, m_fBlendWeight) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceForm, m_pTargetNode) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceForm, m_fElapsedTime) == 44);
#pragma pack(push, 4)
class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
  public:
    // base ImageSpaceModifierInstance at +0x0, size 28
    float fDuration;  // +0x1C, 4 bytes
    // ImageSpaceModifierInstanceTemp
    // Call-protocol declarations added by the matcher unit; layout unchanged.
    ImageSpaceModifierInstanceTemp(float, float, NiAVObject*, float);
    ~ImageSpaceModifierInstanceTemp();
    void DestroyMembers();
    bool IsExpired();
    // bool __cdecl ImageSpaceModifierInstanceTemp::*()
    // void __cdecl ImageSpaceModifierInstanceTemp::*()
    // void __cdecl ImageSpaceModifierInstanceTemp::*(char*)
    // void __cdecl ImageSpaceModifierInstanceTemp::*()
    // ImageSpaceModifierInstanceTemp& __cdecl ImageSpaceModifierInstanceTemp::*(const ImageSpaceModifierInstanceTemp&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceTemp) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceTemp, fDuration) == 28);

// Names of nested/template specializations use the canonical generator identifier mapping.
class RgbaColor;
class NiColorData;
class NiColorInterpolator;
class NiFloatData;
class NiFloatInterpolator;
class NiInterpolator;
class NiKeyBasedInterpolator;
class AlphaColor;
class TimedFloatKey;
class NiPoint2;
class TESImageSpaceModifier;
class TESImageSpaceModifier__ImageSpaceModifierData;
#pragma pack(push, 4)
class NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint2) == 8);
FNV_STATIC_ASSERT(offsetof(NiPoint2, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint2, y) == 4);
#pragma pack(push, 4)
class TESImageSpaceModifier__ImageSpaceModifierData
{
  public:
    bool m_bOverride;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    float fDuration;                                          // +0x4, 4 bytes
    unsigned int m_auiKeyframeCountsByTypeAndChannel[21][2];  // +0x8, 168 bytes
    unsigned int m_uiEffectEntryCountFirst;                   // +0xB0, 4 bytes
    unsigned int m_uiEffectEntryCountSecond;                  // +0xB4, 4 bytes
    unsigned int m_uiEffectEntryCountThird;                   // +0xB8, 4 bytes
    unsigned int m_uiEffectEntryCountFourth;                  // +0xBC, 4 bytes
    unsigned int m_uiEffectEntryCountFifth;                   // +0xC0, 4 bytes
    unsigned int m_uiEffectEntryCountSixth;                   // +0xC4, 4 bytes
    bool m_bUseRadialBlur;                                    // +0xC8, 1 bytes
    unsigned char layoutPaddingC9[3];
    NiPoint2 m_kRadialBlurCenter;              // +0xCC, 8 bytes
    unsigned int m_uiEffectEntryCountSeventh;  // +0xD4, 4 bytes
    unsigned int m_uiEffectEntryCountEighth;   // +0xD8, 4 bytes
    unsigned int m_uiEffectEntryCountNinth;    // +0xDC, 4 bytes
    bool m_bUseEffectEntries;                  // +0xE0, 1 bytes
    unsigned char m_ucEffectMode;              // +0xE1, 1 bytes
    unsigned char layoutPaddingE2[2];
    unsigned int m_uiEffectEntryCountTenth;       // +0xE4, 4 bytes
    unsigned int m_uiEffectEntryCountEleventh;    // +0xE8, 4 bytes
    unsigned int m_uiEffectEntryCountTwelfth;     // +0xEC, 4 bytes
    unsigned int m_uiEffectEntryCountThirteenth;  // +0xF0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifier__ImageSpaceModifierData) == 244);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_bOverride) == 0);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, fDuration) == 4);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_auiKeyframeCountsByTypeAndChannel) == 8);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountFirst) == 176);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountSecond) == 180);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountThird) == 184);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountFourth) == 188);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountFifth) == 192);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountSixth) == 196);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_bUseRadialBlur) == 200);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_kRadialBlurCenter) == 204);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountSeventh) == 212);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountEighth) == 216);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountNinth) == 220);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_bUseEffectEntries) == 224);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_ucEffectMode) == 225);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountTenth) == 228);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountEleventh) == 232);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountTwelfth) == 236);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier__ImageSpaceModifierData, m_uiEffectEntryCountThirteenth) == 240);
#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    float m_fLastTime;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl NiInterpolator::*()
    // void __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiObject*)
    // void __cdecl NiInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpolator::*()
    // Update
    // void __cdecl NiInterpolator::*()
    // NiInterpolator
    // bool __cdecl NiInterpolator::*(float)
    // NiInterpolator& __cdecl NiInterpolator::*(const NiInterpolator&)
    // void __cdecl NiInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);
FNV_STATIC_ASSERT(offsetof(NiInterpolator, m_fLastTime) == 8);
#pragma pack(push, 4)
class NiKeyBasedInterpolator : public NiInterpolator
{
  public:
    // base NiInterpolator at +0x0, size 12
    // const NiRTTI* __cdecl NiKeyBasedInterpolator::*()
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // bool __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // bool __cdecl NiKeyBasedInterpolator::*(NiObject*)
    // void __cdecl NiKeyBasedInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiKeyBasedInterpolator::*()
    // unsigned int __cdecl NiKeyBasedInterpolator::*(unsigned short)
    // void __cdecl NiKeyBasedInterpolator::*(unsigned short)
    // void __cdecl NiKeyBasedInterpolator::*(float&, float&)
    // NiKeyBasedInterpolator
    // NiKeyBasedInterpolator& __cdecl NiKeyBasedInterpolator::*(const NiKeyBasedInterpolator&)
    // void __cdecl NiKeyBasedInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiKeyBasedInterpolator) == 12);
#pragma pack(push, 4)
class NiFloatInterpolator : public NiKeyBasedInterpolator
{
  public:
    // base NiKeyBasedInterpolator at +0x0, size 12
    float m_fFloatValue;                   // +0xC, 4 bytes
    NiPointer<NiFloatData> m_spFloatData;  // +0x10, 4 bytes
    unsigned int m_uiLastKeyIndex;         // +0x14, 4 bytes
    // const NiRTTI* __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*(NiStream&)
    // void __cdecl NiFloatInterpolator::*(NiStream&)
    // bool __cdecl NiFloatInterpolator::*(NiStream&)
    // void __cdecl NiFloatInterpolator::*(NiStream&)
    // bool __cdecl NiFloatInterpolator::*(NiObject*)
    // NiObject* __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiFloatInterpolator
    // bool __cdecl NiFloatInterpolator::*(float, NiObjectNET*, float&)
    // bool __cdecl NiFloatInterpolator::*()
    // NiFloatData* __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*(NiFloatData*)
    // void __cdecl NiFloatInterpolator::*(float)
    // unsigned short __cdecl NiFloatInterpolator::*()
    // unsigned int __cdecl NiFloatInterpolator::*(unsigned short)
    // unsigned char __cdecl NiFloatInterpolator::*(unsigned short)
    // bool __cdecl NiFloatInterpolator::*(unsigned short)
    // void __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*(float, float)
    // NiInterpolator* __cdecl NiFloatInterpolator::*(float, float)
    // float __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*()
    // NiFloatInterpolator& __cdecl NiFloatInterpolator::*(const NiFloatInterpolator&)
    // void __cdecl NiFloatInterpolator::*()
    // void __cdecl NiFloatInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFloatInterpolator) == 24);
FNV_STATIC_ASSERT(offsetof(NiFloatInterpolator, m_fFloatValue) == 12);
FNV_STATIC_ASSERT(offsetof(NiFloatInterpolator, m_spFloatData) == 16);
FNV_STATIC_ASSERT(offsetof(NiFloatInterpolator, m_uiLastKeyIndex) == 20);
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
class NiColorInterpolator : public NiKeyBasedInterpolator
{
  public:
    // base NiKeyBasedInterpolator at +0x0, size 12
    RgbaColor m_kColorValue;               // +0xC, 16 bytes
    NiPointer<NiColorData> m_spColorData;  // +0x1C, 4 bytes
    unsigned int m_uiLastKeyIndex;         // +0x20, 4 bytes
    // const NiRTTI* __cdecl NiColorInterpolator::*()
    // void __cdecl NiColorInterpolator::*(NiStream&)
    // void __cdecl NiColorInterpolator::*(NiStream&)
    // bool __cdecl NiColorInterpolator::*(NiStream&)
    // void __cdecl NiColorInterpolator::*(NiStream&)
    // bool __cdecl NiColorInterpolator::*(NiObject*)
    // NiObject* __cdecl NiColorInterpolator::*()
    // void __cdecl NiColorInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiColorInterpolator
    // bool __cdecl NiColorInterpolator::*(float, NiObjectNET*, RgbaColor&)
    // bool __cdecl NiColorInterpolator::*()
    // NiColorData* __cdecl NiColorInterpolator::*()
    // void __cdecl NiColorInterpolator::*(NiColorData*)
    // void __cdecl NiColorInterpolator::*(RgbaColor)
    // unsigned short __cdecl NiColorInterpolator::*()
    // unsigned int __cdecl NiColorInterpolator::*(unsigned short)
    // unsigned char __cdecl NiColorInterpolator::*(unsigned short)
    // bool __cdecl NiColorInterpolator::*(unsigned short)
    // void __cdecl NiColorInterpolator::*()
    // void __cdecl NiColorInterpolator::*(float, float)
    // NiInterpolator* __cdecl NiColorInterpolator::*(float, float)
    // void __cdecl NiColorInterpolator::*()
    // NiColorInterpolator& __cdecl NiColorInterpolator::*(const NiColorInterpolator&)
    // void __cdecl NiColorInterpolator::*()
    // void __cdecl NiColorInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiColorInterpolator) == 36);
FNV_STATIC_ASSERT(offsetof(NiColorInterpolator, m_kColorValue) == 12);
FNV_STATIC_ASSERT(offsetof(NiColorInterpolator, m_spColorData) == 28);
FNV_STATIC_ASSERT(offsetof(NiColorInterpolator, m_uiLastKeyIndex) == 32);
#pragma pack(push, 4)
class TESImageSpaceModifier : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESSound* pOutroSound;                               // +0x18, 4 bytes
    TESSound* pIntroSound;                               // +0x1C, 4 bytes
    TESImageSpaceModifier__ImageSpaceModifierData Data;  // +0x20, 244 bytes
    NiFloatInterpolator m_akFloatInterpolators[21][2];   // +0x114, 1008 bytes
    NiFloatInterpolator m_kFloatInterpolatorOne;         // +0x504, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorTwo;         // +0x51C, 24 bytes
    NiColorInterpolator m_kColorInterpolatorOne;         // +0x534, 36 bytes
    NiColorInterpolator m_kColorInterpolatorTwo;         // +0x558, 36 bytes
    NiFloatInterpolator m_kFloatInterpolatorNine;        // +0x57C, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorTen;         // +0x594, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorEleven;      // +0x5AC, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorThree;       // +0x5C4, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorFour;        // +0x5DC, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorFive;        // +0x5F4, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorSix;         // +0x60C, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorSeven;       // +0x624, 24 bytes
    NiFloatInterpolator m_kFloatInterpolatorEight;       // +0x63C, 24 bytes
    TimedFloatKey* pEffectEntryTable[21][2];             // +0x654, 168 bytes
    TimedFloatKey* pSecondEffectEntries;                 // +0x6FC, 4 bytes
    TimedFloatKey* pThirdEffectEntries;                  // +0x700, 4 bytes
    AlphaColor* pFirstEffectRecordArray;                 // +0x704, 4 bytes
    AlphaColor* pSecondEffectRecordArray;                // +0x708, 4 bytes
    TimedFloatKey* pTenthEffectEntries;                  // +0x70C, 4 bytes
    TimedFloatKey* pEleventhEffectEntries;               // +0x710, 4 bytes
    TimedFloatKey* pTwelfthEffectEntries;                // +0x714, 4 bytes
    TimedFloatKey* pFourthEffectEntries;                 // +0x718, 4 bytes
    TimedFloatKey* pFifthEffectEntries;                  // +0x71C, 4 bytes
    TimedFloatKey* pSeventhEffectEntries;                // +0x720, 4 bytes
    TimedFloatKey* pEighthEffectEntries;                 // +0x724, 4 bytes
    TimedFloatKey* pNinthEffectEntries;                  // +0x728, 4 bytes
    TimedFloatKey* pSixthEffectEntries;                  // +0x72C, 4 bytes
    BSStringT<char> strName;                             // +0x730, 8 bytes
    // TESImageSpaceModifier
    // Call-protocol declarations added by the matcher unit; layout unchanged.
    TESSound* GetIntroSound();
    TESSound* GetOutroSound();
    bool IsExpired(float m_fStartTime);
    void Apply(float fWaterLevelItem, float m_fStartTime, NiAVObject* pTarget);
    void EvaluateInterpolators(float fWaterLevelItem, float m_fStartTime);
    static void BlendModifiers(float afBlendWeight, TESImageSpaceModifier* pLastModifier,
                               TESImageSpaceModifier* pModifier, float m_fBlendWeight, float fWaterLevelItem,
                               NiAVObject* coordinate, NiAVObject* pTarget);
    // void __cdecl TESImageSpaceModifier::*()
    // bool __cdecl TESImageSpaceModifier::*()
    // float __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(bool)
    // void __cdecl TESImageSpaceModifier::*(float)
    // void __cdecl TESImageSpaceModifier::*(bool)
    // bool __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(float, float, NiAVObject*)
    // void __cdecl TESImageSpaceModifier::*(float, float)
    // bool __cdecl TESImageSpaceModifier::*(float)
    // void __cdecl TESImageSpaceModifier::*(float, TESImageSpaceModifier*, TESImageSpaceModifier*, float, float, NiAVObject*, NiAVObject*)
    // bool __cdecl TESImageSpaceModifier::*(NiFloatInterpolator&)
    // bool __cdecl TESImageSpaceModifier::*(NiColorInterpolator&)
    // void __cdecl TESImageSpaceModifier::*(NiFloatInterpolator&, float)
    // void __cdecl TESImageSpaceModifier::*(NiColorInterpolator&)
    // bool __cdecl TESImageSpaceModifier::*(TESFile*)
    // void __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(TESForm*)
    // bool __cdecl TESImageSpaceModifier::*(TESForm*)
    // void __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*()
    // bool __cdecl TESImageSpaceModifier::*()
    // TESSound* __cdecl TESImageSpaceModifier::*()
    // TESSound* __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(float)
    // float __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(float)
    // void __cdecl TESImageSpaceModifier::*()
    // void __cdecl TESImageSpaceModifier::*(bool)
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifier::*()
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifier::*()
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifier::*()
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifier::*()
    // TESImageSpaceModifier& __cdecl TESImageSpaceModifier::*(const TESImageSpaceModifier&)
    // void __cdecl TESImageSpaceModifier::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifier) == 1848);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pOutroSound) == 24);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pIntroSound) == 28);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, Data) == 32);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_akFloatInterpolators) == 276);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorOne) == 1284);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorTwo) == 1308);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kColorInterpolatorOne) == 1332);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kColorInterpolatorTwo) == 1368);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorNine) == 1404);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorTen) == 1428);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorEleven) == 1452);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorThree) == 1476);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorFour) == 1500);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorFive) == 1524);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorSix) == 1548);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorSeven) == 1572);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_kFloatInterpolatorEight) == 1596);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEffectEntryTable) == 1620);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pSecondEffectEntries) == 1788);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pThirdEffectEntries) == 1792);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pFirstEffectRecordArray) == 1796);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pSecondEffectRecordArray) == 1800);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pTenthEffectEntries) == 1804);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEleventhEffectEntries) == 1808);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pTwelfthEffectEntries) == 1812);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pFourthEffectEntries) == 1816);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pFifthEffectEntries) == 1820);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pSeventhEffectEntries) == 1824);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEighthEffectEntries) == 1828);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pNinthEffectEntries) == 1832);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pSixthEffectEntries) == 1836);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, strName) == 1840);

// Returns whether the referenced image space modifier is expired, or false when no modifier is set.
// @fnv 0x005297b0
bool ImageSpaceModifierInstanceForm::IsExpired()
{
    if (m_pPreviousImageSpaceModifier)
        return m_pPreviousImageSpaceModifier->IsExpired(m_fStartTime);
    else
        return false;
}

// @fnv 0x005297e0
void ImageSpaceModifierInstanceForm::Apply()
{
    if (fWaterLevelItem > 0.0 || m_fBlendWeight > 0.0)
    {
        if (m_pPreviousImageSpaceModifier)
        {
            if (m_fStartTime < -10000.0)
                m_fStartTime = ImageSpaceModifierInstance::GetTime();
            if (m_pImageSpaceModifier)
            {
                float afTime = ImageSpaceModifierInstance::GetTime();
                float afBlendWeight = (afTime - m_fStartTime) / m_fElapsedTime;
                if (afBlendWeight < 1.0)
                {
                    TESImageSpaceModifier::BlendModifiers(afBlendWeight, m_pImageSpaceModifier,
                                                          m_pPreviousImageSpaceModifier, m_fBlendWeight,
                                                          fWaterLevelItem, m_pTargetNode, m_spTargetObject);
                }
                else
                {
                    m_pImageSpaceModifier = NULL;
                    m_fBlendWeight = 0.0f;
                    if (m_bHasBeenApplied)
                        m_pPreviousImageSpaceModifier->EvaluateInterpolators(m_fStartTime, fWaterLevelItem);
                    else
                        m_pPreviousImageSpaceModifier->Apply(m_fStartTime, fWaterLevelItem, m_spTargetObject);
                }
            }
            else
            {
                if (m_bHasBeenApplied)
                    m_pPreviousImageSpaceModifier->EvaluateInterpolators(m_fStartTime, fWaterLevelItem);
                else
                    m_pPreviousImageSpaceModifier->Apply(m_fStartTime, fWaterLevelItem, m_spTargetObject);
            }
        }
    }
}

// @fnv 0x0052a920
bool ImageSpaceModifierInstanceTemp::IsExpired()
{
    bool bExpired = false;
    if (fDuration != 0.0)
        bExpired = ((ImageSpaceModifierInstance::GetTime() - m_fStartTime) > fDuration) ? 1 : 0;
    return bExpired;
}

// Creates an ImageSpaceModifierInstanceForm for the given modifier, appends it to a list, plays its intro sound, and returns the instance.
// @fnv 0x005299a0
ImageSpaceModifierInstanceForm* ImageSpaceModifierInstanceForm::Trigger(TESImageSpaceModifier* modifier, float strength,
                                                                        NiAVObject* target)
{
    ImageSpaceModifierInstanceForm* instance = NULL;
    if (modifier)
    {
        instance = new ImageSpaceModifierInstanceForm(modifier, DAT_0102d270, strength, target);
        g_TES->FUN_0043b5d0()->AddTail(instance);
        if (modifier->GetIntroSound())
            BSAudio::GetSingleton()
                ->GetSoundHandleByFormID(modifier->GetIntroSound()->GetFormID(), 0x200000, false)
                .Play();
    }
    return instance;
}

#include "imagespacemodifierinstance_effects.h"

// @fnv 0x0052a670
void ImageSpaceModifierInstanceDRB::Apply()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();
        ImageSpaceManager* manager = ImageSpaceManager::FUN_004e3270();
        if (m_spTargetObject)
        {
            ((NiAVObject*)m_spTargetObject)->UpdateWorldBound();
            manager->ApplyDepthOfFieldModifier(fWaterLevelItem, Mode, m_fRampUp, fStart,
                                               ((NiAVObject*)m_spTargetObject)->GetBoundingVolume());
        }
        else
            manager->SetIfHigherPriority(fWaterLevelItem, Mode, fDistance, fImpulseRadiusSquared, m_fRampUp, fStart, Center);
    }
}

// @fnv 0x0052a060
void ImageSpaceModifierInstanceDOF::Apply()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();
        ImageSpaceManager* manager = ImageSpaceManager::FUN_004e3270();
        if (m_spTargetObject)
        {
            ((NiAVObject*)m_spTargetObject)->UpdateWorldBound();
            manager->SetDistanceEffect(fWaterLevelItem, Mode, m_fMaskConstant,
                                       ((NiAVObject*)m_spTargetObject)->GetBoundingVolume());
        }
        else
            manager->SetDepthOfFieldParameters(fWaterLevelItem, Mode, m_fMaskConstant, fDistance, fImpulseRadiusSquared);
    }
}

#include "imagespacemodifierinstance_audio.h"

// Sends SOUND_MSG_ENTER_DIALOGUE to the audio manager with no target object or position.
// @fnv 0x00ad85a0
void DialogMenuAudioCalls::EnableAudio()
{
    BSAudioManager::GetRandomGenerator().SendSoundMessage(SOUND_MSG_ENTER_DIALOGUE, 1, 0, NULL, (NiAVObject*)NULL,
                                                 NiPoint3::ZERO);
}

// @fnv 0x00529c90
void ImageSpaceModifierInstanceForm::Stop(TESImageSpaceModifier* modifier)
{
    if (!modifier)
        return;
    bool playedSound = false;
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* node = g_TES->FUN_0043b5d0();
    while (node)
    {
        ImageSpaceModifierInstance* instance = node->GetItem();
        if (instance && instance->GetInstanceForm() && instance->GetInstanceForm()->GetImageSpaceMod() == modifier)
        {
            node->Remove(instance);
            if (modifier->GetOutroSound() && !playedSound)
            {
                playedSound = true;
                BSAudio::GetSingleton()
                    ->GetSoundHandleByFormID(modifier->GetOutroSound()->GetFormID(), 0x200000, false)
                    .Play();
            }
        }
        else
            node = node->GetNext();
    }
}

// Creates a new ImageSpaceModifierInstanceDRB with the given parameters, appends it to the list from g_TES->FUN_0043b5d0(), and returns it.
// @fnv 0x0052a780
ImageSpaceModifierInstanceDRB* ImageSpaceModifierInstanceDRB::Trigger(float distance, float range,
                                                                      DepthOfFieldMode mode, float strength,
                                                                      float rampup, float start, float rampdown,
                                                                      float downstart, const NiPoint2& center,
                                                                      float duration)
{
    ImageSpaceModifierInstanceDRB* instance = new ImageSpaceModifierInstanceDRB(
        strength, DAT_0102d270, NULL, duration, mode, distance, range, rampup, start, rampdown, downstart, center);
    g_TES->FUN_0043b5d0()->AddTail(instance);
    return instance;
}

// Allocates an ImageSpaceModifierInstanceDOF with the given parameters, appends it to the modifier list, and returns it.
// @fnv 0x0052a150
ImageSpaceModifierInstanceDOF* ImageSpaceModifierInstanceDOF::CreateAndRegister(float distance, float range,
                                                                                DepthOfFieldMode mode, float strength,
                                                                                float mask, float duration)
{
    ImageSpaceModifierInstanceDOF* instance =
        new ImageSpaceModifierInstanceDOF(strength, DAT_0102d270, mode, distance, range, mask, NULL, duration);
    g_TES->FUN_0043b5d0()->AddTail(instance);
    return instance;
}

// Constructs a depth-of-field modifier instance, initializing the base temp instance and storing ramp, center, distance, range and mode values.
// @fnv 0x0052a590
ImageSpaceModifierInstanceDRB::ImageSpaceModifierInstanceDRB(float strength, float startTime, NiAVObject* target,
                                                             float duration, DepthOfFieldMode mode, float distance,
                                                             float range, float rampup, float start, float rampdown,
                                                             float downstart, const NiPoint2& center)
    : ImageSpaceModifierInstanceTemp(startTime, strength, target, duration)
{
    m_fRampUp = rampup;
    fStart = start;
    m_fRampDown = rampdown;
    m_fRampDownStart = downstart;
    Center = center;
    fDistance = distance;
    fImpulseRadiusSquared = range;
    Mode = mode;
}

// Constructs a DOF modifier instance: forwards startTime, strength, target and duration to the temp base, then stores distance, range, mask and mode.
// @fnv 0x00529fb0
ImageSpaceModifierInstanceDOF::ImageSpaceModifierInstanceDOF(float strength, float startTime, DepthOfFieldMode mode,
                                                             float distance, float range, float mask,
                                                             NiAVObject* target, float duration)
    : ImageSpaceModifierInstanceTemp(startTime, strength, target, duration)
{
    fDistance = distance;
    fImpulseRadiusSquared = range;
    m_fMaskConstant = mask;
    Mode = mode;
}

// Constructs a temporary image space modifier instance, forwarding strength, start time and target to the base and storing the duration.
// @fnv 0x0052a8b0
ImageSpaceModifierInstanceTemp::ImageSpaceModifierInstanceTemp(float startTime, float strength, NiAVObject* target,
                                                               float duration)
    : ImageSpaceModifierInstance(strength, startTime, target)
{
    fDuration = duration;
}

// @fnv 0x0052a650
void ImageSpaceModifierInstanceDOF::DestroyMembers()
{
    this->ImageSpaceModifierInstanceTemp::~ImageSpaceModifierInstanceTemp();
}

// @fnv 0x0052a040
void ImageSpaceModifierInstanceTemp::DestroyMembers()
{
    this->ImageSpaceModifierInstance::~ImageSpaceModifierInstance();
}

// @fnv 0x00529990
float ImageSpaceModifierInstance::GetTime()
{
    return DAT_011c96fc;
}

// Explicit readable equivalent of the compiler's scalar deleting destructor.
// Destructs the ImageSpaceModifierInstanceDOF and, if flags bit 0 is set, frees its memory via operator delete, returning this.
// @fnv 0x0052a010
void* ImageSpaceModifierInstanceDOF::ScalarDeletingDestructor(unsigned int flags)
{
    this->ImageSpaceModifierInstanceDOF::~ImageSpaceModifierInstanceDOF();
    if (flags & 1)
        NiMemObjectAllocation::operator delete(this, sizeof(ImageSpaceModifierInstanceDOF));
    return this;
}

// Walks the image space modifier instance list from g_TES and removes every entry matching apInstance.
// @fnv 0x005293f0
void __cdecl FUN_005293f0(ImageSpaceModifierInstance* apInstance)
{
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* pkList = g_TES->FUN_0043b5d0();
    while (pkList)
    {
        ImageSpaceModifierInstance* pinstance = pkList->GetItem();
        if (pinstance == apInstance)
        {
            pkList->Remove(pinstance);
        }
        else
        {
            pkList = pkList->GetNext();
        }
    }
}

void __fastcall FUN_00529690(void*);

struct FUN_00529660_view : public ImageSpaceModifierInstanceForm
{
    void* Destroy(unsigned int flags);
};

// @fnv 0x00529660
void* FUN_00529660_view::Destroy(unsigned int flags)
{
    FUN_00529690(this);
    if (flags & 1)
        NiMemObjectAllocation::operator delete(this, 0x30);
    return this;
}

class NiNode;
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    ~NiPointer();
    NiPointer<NiNode>& operator=(NiNode*);
};

struct FUN_00529690_dtor : public ImageSpaceModifierInstance
{
    TESImageSpaceModifier* m_pPreviousImageSpaceModifier;
    TESImageSpaceModifier* m_pImageSpaceModifier;
    float m_fBlendWeight;
    NiPointer<NiNode> m_pTargetNode;
    float m_fElapsedTime;
    virtual ~FUN_00529690_dtor();
};

// Destructor that clears the NiPointer member by assigning null to it.
// @fnv 0x00529690
FUN_00529690_dtor::~FUN_00529690_dtor()
{
    m_pTargetNode = 0;
}

extern void* DAT_0102d1cc[];
struct _Call_a5d3a0
{
    void** m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    _Call_a5d3a0();
    ~_Call_a5d3a0();
};
struct GO
{
    void* m_pObject;
    GO(int);
};
struct FUN_00529540 : public _Call_a5d3a0
{
    bool m_bHasBeenApplied;
    unsigned char pad9[3];
    float fWaterLevelItem;
    GO m_spTargetObject;
    float m_fStartTime;
    unsigned int iFlags;
    FUN_00529540(float afStrength, float afStartTime, NiAVObject* apTarget);
};

// @fnv 0x00529540
FUN_00529540::FUN_00529540(float afStrength, float afStartTime, NiAVObject* apTarget)
    : fWaterLevelItem((m_ppVirtualMethodTable = DAT_0102d1cc, afStrength)), m_spTargetObject((int)apTarget)
{
    m_fStartTime = afStartTime;
}

class NiNode;
struct NiPtrNode
{
    NiPtrNode& operator=(NiNode*);
    ~NiPtrNode();
    NiNode* m_pObject;
};
struct FUN_00a5d3d0
{
    virtual void vfn_0();
    ~FUN_00a5d3d0();
    unsigned int m_uiRefCount;
};
struct FUN_005295c0 : public FUN_00a5d3d0
{
    bool m_bHasBeenApplied;
    float fWaterLevelItem;
    NiPtrNode m_spTargetObject;
    ~FUN_005295c0();
};

// Destructor that clears the node pointer reference by assigning null to it.
// @fnv 0x005295c0
FUN_005295c0::~FUN_005295c0()
{
    m_spTargetObject = 0;
}

extern "C" const char* const g_011f36dc_arg1;

struct FUN_00529530_shell
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x00529530
const char* const* __thiscall FUN_00529530_shell::GetArg1Ptr()
{
    return &g_011f36dc_arg1;
}

struct ImageSpaceModifierInstanceDestructionView
{
    void Destruct();
};

void* _delete(void*, unsigned int);

struct FUN_00529630_shell : ImageSpaceModifierInstance
{
    ImageSpaceModifierInstance* FUN_00529630(unsigned int flags);
};

// Calls Destruct on this instance and, when flags has bit 0 set, frees it with _delete; returns this.
// @fnv 0x00529630
ImageSpaceModifierInstance* FUN_00529630_shell::FUN_00529630(unsigned int flags)
{
    reinterpret_cast<ImageSpaceModifierInstanceDestructionView*>(this)->Destruct();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

namespace fnv_0052a620 {
extern "C" void _delete(void* p, unsigned int size);

struct FUN_0052a620_shell
{
    void* __thiscall FUN_0052a620(unsigned int flags);
};

// Destroys the object's members and, when flags has bit 0 set, frees the 0x44-byte object; returns this.
// @fnv 0x0052a620
void* __thiscall FUN_0052a620_shell::FUN_0052a620(unsigned int flags)
{
    reinterpret_cast<ImageSpaceModifierInstanceDOF*>(this)->DestroyMembers();
    if (flags & 1)
        _delete(this, 0x44);
    return this;
}
}  // namespace fnv_0052a620

namespace fnv_0052a8f0 {
extern "C" void* __cdecl _delete(void* ptr, unsigned int size);

struct ImageSpaceModifierInstanceTempDestructionView
{
    void Destruct();
};

struct FUN_0052a8f0_shell
{
    void* DestroyImageSpaceModifierInstanceTemp(unsigned int flags);
};

// Calls Destruct on the object, then frees it with _delete when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0052a8f0
void* FUN_0052a8f0_shell::DestroyImageSpaceModifierInstanceTemp(unsigned int flags)
{
    reinterpret_cast<ImageSpaceModifierInstanceTempDestructionView*>(this)->Destruct();
    if (flags & 1)
        _delete(this, 0x20);
    return this;
}
}  // namespace fnv_0052a8f0

int _sprintf_s(char*, unsigned int, const char*, ...);
struct FUN_0052a240_shell : public ImageSpaceModifierInstance
{
    int _pad1C;
    float fDistance;
    float fImpulseRadiusSquared;
    void FormatDofParams(char* apBuffer);
};
// Writes the DOF distance, range and strength values into apBuffer with _sprintf_s.
// @fnv 0x0052a240
void FUN_0052a240_shell::FormatDofParams(char* apBuffer)
{
    _sprintf_s(apBuffer, 0x800, "  DOF  Distance: %f  Range: %f  Str: %f", fDistance, fImpulseRadiusSquared, fWaterLevelItem);
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct Shell0052a880
{
    void WriteDepthRadialBlurLabel(char*);
};
// @fnv 0x0052a880
void Shell0052a880::WriteDepthRadialBlurLabel(char* apBuffer)
{
    _sprintf_s(apBuffer, 0x800, "  Depth Radial Blur");
}

struct FUN_00529ea0_shell
{
    char padding[0x20];
    unsigned char m_flags;  // +0x20
    unsigned char FUN_00529ea0();
};

// @fnv 0x00529ea0
unsigned char FUN_00529ea0_shell::FUN_00529ea0()
{
    return m_flags;
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char str_0102d408[];
struct ImageSpaceModifierInstanceRB
{
    char _pad0[12];
    float fWaterLevelItem;
    char _pad1[16];
    float m_fRampUp;
    float fStart;
    float m_fRampDown;
    float m_fRampDownStart;
    void PrintInfo(char* apBuffer);
};
// @fnv 0x0052a530
void ImageSpaceModifierInstanceRB::PrintInfo(char* apBuffer)
{
    _sprintf_s(apBuffer, 0x800, str_0102d408, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart, fWaterLevelItem);
}

namespace fnv_00529490 {
struct GO
{
    int x;
    GO(int);
    ~GO();
};
struct FUN_00529490 : ImageSpaceModifierInstance
{
    TESImageSpaceModifier* m_pPreviousImageSpaceModifier;
    TESImageSpaceModifier* m_pImageSpaceModifier;
    float m_fBlendWeight;
    GO g;
    float f;
    FUN_00529490();
};
// @fnv 0x00529490
FUN_00529490::FUN_00529490()
    : ImageSpaceModifierInstance(0.0f, 0.0f, 0), m_pPreviousImageSpaceModifier(0), m_pImageSpaceModifier(0),
      m_fBlendWeight(0.0f), g(0), f(0.0f)
{
    m_bHasBeenApplied = false;
}
}  // namespace fnv_00529490

namespace fnv_00529700 {
struct GO
{
    int m;
    GO(int);
};
struct FUN_00529700 : public ImageSpaceModifierInstance
{
    TESImageSpaceModifier* m_pPreviousImageSpaceModifier;
    TESImageSpaceModifier* m_pImageSpaceModifier;
    float m_fBlendWeight;
    GO m_pTargetNode;
    float m_fElapsedTime;
    FUN_00529700(TESImageSpaceModifier*, float, float, NiAVObject*);
    virtual ~FUN_00529700();
};
// Constructs an ImageSpaceModifierInstance from a modifier, start, strength and target, initializing the modifier pointer and clearing the remaining fields.
// @fnv 0x00529700
FUN_00529700::FUN_00529700(TESImageSpaceModifier* apModifier, float start, float strength, NiAVObject* target)
    : ImageSpaceModifierInstance(strength, start, target), m_pPreviousImageSpaceModifier(apModifier),
      m_pImageSpaceModifier(0), m_fBlendWeight(0.0f), m_pTargetNode(0), m_fElapsedTime(0.0f)
{
    m_bHasBeenApplied = false;
}
}  // namespace fnv_00529700

namespace fnv_00529df0 {
struct Worker
{
    bool FUN_00529ea0();
};

struct GO
{
    void operator=(void*);
};

struct Helper62d0
{
    void* operator=(void const*);
};

struct FUN_00529df0_shell : public ImageSpaceModifierInstanceForm
{
    bool FUN_00529df0(TESImageSpaceModifier*, float, float, NiAVObject*);
};

// @fnv 0x00529df0
bool FUN_00529df0_shell::FUN_00529df0(TESImageSpaceModifier* pModifier, float m_fElapsedTime, float fWaterLevelItem,
                                      NiAVObject* pTarget)
{
    if ((this->m_pPreviousImageSpaceModifier != 0 &&
         reinterpret_cast<Worker*>(this->m_pPreviousImageSpaceModifier)->FUN_00529ea0()) ||
        (pModifier != 0 && reinterpret_cast<Worker*>(pModifier)->FUN_00529ea0()))
    {
        return false;
    }

    this->m_pImageSpaceModifier = this->m_pPreviousImageSpaceModifier;
    this->m_fBlendWeight = this->fWaterLevelItem;
    reinterpret_cast<Helper62d0*>(&this->m_pTargetNode)->operator=(&this->m_spTargetObject);
    this->m_fStartTime = ImageSpaceModifierInstance::GetTime();
    this->m_fElapsedTime = m_fElapsedTime;
    this->m_pPreviousImageSpaceModifier = pModifier;
    this->fWaterLevelItem = fWaterLevelItem;
    reinterpret_cast<GO*>(&this->m_spTargetObject)->operator=(pTarget);

    return true;
}
}  // namespace fnv_00529df0

namespace fnv_0052a330 {
class GO
{
  public:
    operator unsigned int() const;
};

ImageSpaceManager* FUN_004e3270(void);

struct ImageSpaceManagerAccess
{
    void FUN_00b8b760(float, float, float, float, float, const NiBound&);
    void SetRadialBlurParameters(float, float, float, float, float, const NiPoint2&);
};

struct ImageSpaceModifierInstanceRB
{
    void* vftable;
    unsigned int unused04;
    unsigned int unused08;
    float fWaterLevelItem;
    GO m_spTargetObject;
    float m_fStartTime;
    unsigned int iFlags;
    void* unused1c;
    float m_fRampUp;
    float fStart;
    float m_fRampDown;
    float m_fRampDownStart;
    NiPoint2 radCenter;

    void FUN_0052a330();
};

// @fnv 0x0052a330
void ImageSpaceModifierInstanceRB::FUN_0052a330()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();

        ImageSpaceManager* pmanager = FUN_004e3270();

        if (m_spTargetObject.operator unsigned int())
        {
            reinterpret_cast<NiAVObject*>(m_spTargetObject.operator unsigned int())->UpdateWorldBound();

            reinterpret_cast<ImageSpaceManagerAccess*>(pmanager)->FUN_00b8b760(
                fWaterLevelItem, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart,
                reinterpret_cast<NiAVObject*>(m_spTargetObject.operator unsigned int())->GetBoundingVolume());
        }
        else
        {
            reinterpret_cast<ImageSpaceManagerAccess*>(pmanager)->SetRadialBlurParameters(
                fWaterLevelItem, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart, radCenter);
        }
    }
}
}  // namespace fnv_0052a330

// Checks whether an instance for apModifier already exists; if not, creates one, appends it to the list, and plays the modifier's intro sound.
// @fnv 0x00529ae0
ImageSpaceModifierInstanceForm* __cdecl CreateImageSpaceModifierInstance(TESImageSpaceModifier* apModifier,
                                                                         float afStrength, NiAVObject* apTarget)
{
    bool bFound = false;
    ImageSpaceModifierInstanceForm* pInstance = 0;
    if (apModifier)
    {
        BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* pIter = g_TES->FUN_0043b5d0();
        while (pIter)
        {
            ImageSpaceModifierInstance* pCurrent = pIter->GetItem();
            if (pCurrent && pCurrent->GetInstanceForm() &&
                pCurrent->GetInstanceForm()->m_pPreviousImageSpaceModifier == apModifier)
            {
                bFound = true;
                break;
            }
            pIter = pIter->GetNext();
        }
        if (!bFound)
        {
            pInstance = new ImageSpaceModifierInstanceForm(apModifier, DAT_0102d270, afStrength, apTarget);
            g_TES->FUN_0043b5d0()->AddTail(pInstance);
            if (apModifier->GetIntroSound())
            {
                BSAudio::GetSingleton()
                    ->GetSoundHandleByFormID(apModifier->GetIntroSound()->GetFormID(), 0x200000, false)
                    .Play();
            }
        }
    }
    return pInstance;
}

struct FUN_00529ec0_obj
{
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
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
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
    virtual const char* vfn_130();
};
struct FUN_00529ec0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned short unk0A;
    float m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FUN_00529ec0_obj* m_1c;
    FUN_00529ec0_obj* m_20;
    void FormatDebugString(char* apBuffer);
};
extern const char DAT_0102d288[];
extern const char DAT_01020770[];
extern const char str_0102d294[];
extern const char str_0102d28c[];
extern const char str_0102d274[];
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
// @fnv 0x00529ec0
void FUN_00529ec0_cls::FormatDebugString(char* apBuffer)
{
    if (m_20 != 0)
    {
        _sprintf_s(apBuffer, 0x800, "B %s %s", (m_1c != 0) ? m_1c->vfn_130() : "(NULL)", m_20->vfn_130());
    }
    else
    {
        _sprintf_s(apBuffer, 0x800, "%s %s Str: %1.3f ", (m_08 != 0) ? DAT_0102d288 : DAT_01020770,
                   (m_1c != 0) ? m_1c->vfn_130() : "(NULL)", (double)m_0c);
    }
}

class FUN_0052a290 : public ImageSpaceModifierInstanceTemp
{
  public:
    FUN_0052a290(float a, float b, NiAVObject* obj, float c, float m_fRampUp, float fStart, float m_fRampDown,
                 float m_fRampDownStart, const NiPoint2& center);

    float m_fRampup;
    float m_fStartValue;
    float m_fRampdown;
    float m_fDownStart;
    NiPoint2 m_kCenterPosition;
};

// Initializes an ImageSpaceModifierInstanceTemp from the given parameters and stores the ramp-up, ramp-down, down-start and center values.
// @fnv 0x0052a290
FUN_0052a290::FUN_0052a290(float a, float b, NiAVObject* obj, float c, float afRampup, float fStart, float afRampdown,
                           float afDownStart, const NiPoint2& center)
    : ImageSpaceModifierInstanceTemp(b, a, obj, c)
{
    m_fRampup = afRampup;
    m_fStartValue = fStart;
    m_fRampdown = afRampdown;
    m_fDownStart = afDownStart;
    m_kCenterPosition = center;
}

namespace fnv_0052a440 {
class ImageSpaceModifierInstanceRB : public ImageSpaceModifierInstanceTemp, public NiMemObjectAllocation
{
  public:
    ImageSpaceModifierInstanceRB(float, float, NiAVObject*, float, float, float, float, float, const NiPoint2&);
    float m_fRampUp;
    float fStart;
    float m_fRampDown;
    float m_fRampDownStart;
    NiPoint2 Center;
};

// Allocates an ImageSpaceModifierInstanceRB with the given parameters, appends it to the modifier list, and returns it.
// @fnv 0x0052a440
ImageSpaceModifierInstance* __cdecl FUN_0052a440(float afStrength, float afRampup, float afStart, float afRampdown,
                                                 float afDownStart, const NiPoint2& akCenter, float afDuration)
{
    ImageSpaceModifierInstanceRB* p = new ImageSpaceModifierInstanceRB(
        afStrength, DAT_0102d270, 0, afDuration, afRampup, afStart, afRampdown, afDownStart, akCenter);
    g_TES->FUN_0043b5d0()->AddTail(p);
    return p;
}
}  // namespace fnv_0052a440

extern "C" void _operator_delete_sized(void* apMemory, unsigned int aSize);

struct Shell_0052a300 : ImageSpaceModifierInstanceDOF
{
    void* FUN_0052a300(unsigned int aFlags);
};

// Calls DestroyMembers, then frees this via _operator_delete_sized when aFlags has bit 0 set, and returns this.
// @fnv 0x0052a300
void* Shell_0052a300::FUN_0052a300(unsigned int aFlags)
{
    DestroyMembers();
    if (aFlags & 1)
    {
        _operator_delete_sized(this, 0x38);
    }
    return this;
}

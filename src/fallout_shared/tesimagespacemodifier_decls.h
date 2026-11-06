// fallout_shared/tesimagespacemodifier_decls.h: declares TimedAnimationKey, TimedFloatKey, RgbaColor, ColorAnimationKey, AlphaColor and more
#ifndef TESIMAGESPACEMODIFIER_DECLS_H
#define TESIMAGESPACEMODIFIER_DECLS_H

#include "TESForm.h"
#include "layout_support.h"
class NiAVObject;
class NiObjectNET;
class NiBound;
class ImageSpaceManager;
#include <malloc.h>
enum TESImageModifierChunks
{
    CHUNK_ID_SNAM_LOCAL_ID = 0x4d414e53,
    CHUNK_ID_BNAM_ID = 0x4d414e42,
    CHUNK_ID_DNAM_ID = 0x4d414e44,
    CHUNK_ID_RDSI_ID = 0x49534452,
    CHUNK_ID_RDSD_ID = 0x44534452,
    CHUNK_ID_RNAM_ID = 0x4d414e52,
    CHUNK_ID_TNAM_ID = 0x4d414e54,
    CHUNK_ID_UNAM_ID = 0x4d414e55,
    CHUNK_ID_VNAM_ID = 0x4d414e56,
    CHUNK_ID_WNAM_ID = 0x4d414e57
};
void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
class TimedAnimationKey
{
  public:
    float m_fTime;
};
class TimedFloatKey : public TimedAnimationKey
{
  public:
    float m_fValue;
    TimedFloatKey();
    ~TimedFloatKey();
    void FUN_0052ce20(float);
    void FUN_004f5d90(float);
};
class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor(float, float, float, float);
    RgbaColor& ScaleRGBA(float);
};
class ColorAnimationKey
{
  public:
    float m_fTime;
    RgbaColor m_kRgbaColor;
};
class AlphaColor : public ColorAnimationKey
{
  public:
    AlphaColor();
    ~AlphaColor();
    void FUN_0052ce20(float);
    void FUN_0052cfc0(const RgbaColor&);
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
    NiPoint2 operator*(float) const;
};
class NiFloatData;
class NiColorData;
class TESImageSpaceColorDataPointer
{
  public:
    NiColorData*& operator=(NiColorData*);
};
class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0,
        LINKEY = 1
    };
};
class NiFloatInterpolator
{
  public:
    virtual ~NiFloatInterpolator();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual bool Update(float, NiObjectNET*, float&);
    unsigned int m_uiRefCount;
    float m_fLastTime, m_fFloatValue;
    NiFloatData* m_spFloatData;
    unsigned int m_uiLastKeyIndex;
    NiFloatInterpolator(NiFloatData* = 0);
    void FUN_007fc2b0(NiFloatData*);
    void SetAnimationKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
};
class NiColorInterpolator
{
  public:
    virtual ~NiColorInterpolator();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual bool Update(float, NiObjectNET*, RgbaColor&);
    unsigned int m_uiRefCount;
    float m_fLastTime;
    RgbaColor m_kColorValue;
    NiColorData* m_spColorData;
    unsigned int m_uiLastKeyIndex;
    NiColorInterpolator(NiColorData* = 0);
    void SetColorData(NiColorData*);
    void SetAnimationKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
class TESImageSpaceModifier : public TESForm
{
  public:
    class ImageSpaceModifierEffectData
    {
      public:
        bool m_bOverride;
        float fDuration;
        unsigned int m_auiKeyframeCountsByTypeAndChannel[21][2];
        unsigned int m_uiEffectEntryCountFirst, m_uiEffectEntryCountSecond, m_uiEffectEntryCountThird,
            m_uiEffectEntryCountFourth, m_uiEffectEntryCountFifth, m_uiEffectEntryCountSixth;
        bool m_bUseRadialBlur;
        NiPoint2 m_kRadialBlurCenter;
        unsigned int m_uiEffectEntryCountSeventh, m_uiEffectEntryCountEighth, m_uiEffectEntryCountNinth;
        bool m_bUseEffectEntries;
        unsigned char m_ucEffectMode;
        unsigned int m_uiEffectEntryCountTenth, m_uiEffectEntryCountEleventh, m_uiEffectEntryCountTwelfth,
            m_uiEffectEntryCountThirteenth;
        ImageSpaceModifierEffectData();
        void Endian();
    };
    TESSound* pOutroSound;
    TESSound* pIntroSound;
    ImageSpaceModifierEffectData Data;
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator m_kFloatInterpolatorOne, m_kFloatInterpolatorTwo;
    NiColorInterpolator m_kColorInterpolatorOne, m_kColorInterpolatorTwo;
    NiFloatInterpolator m_kFloatInterpolatorNine, m_kFloatInterpolatorTen, m_kFloatInterpolatorEleven,
        m_kFloatInterpolatorThree, m_kFloatInterpolatorFour;
    NiFloatInterpolator m_kFloatInterpolatorFive, m_kFloatInterpolatorSix, m_kFloatInterpolatorSeven,
        m_kFloatInterpolatorEight;
    TimedFloatKey* pEffectEntryTable[21][2];
    TimedFloatKey *pSecondEffectEntries, *pThirdEffectEntries;
    AlphaColor *pFirstEffectRecordArray, *pSecondEffectRecordArray;
    TimedFloatKey *pTenthEffectEntries, *pEleventhEffectEntries, *pTwelfthEffectEntries, *pFourthEffectEntries,
        *pFifthEffectEntries;
    TimedFloatKey *pSeventhEffectEntries, *pEighthEffectEntries, *pNinthEffectEntries, *pSixthEffectEntries;
    TESImageSpaceModifier();
    void ResetFormData();
    virtual bool Load(TESFile*);
    virtual void ClearData();
    virtual void InitItem();
    void Apply(float, float, NiAVObject*);
    void EvaluateInterpolators(float, float);
    bool IsExpired(float);
    void InitializeModifierData();
};
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifier::ImageSpaceModifierEffectData) == 0xf4);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_akFloatInterpolators) == 0x114);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEffectEntryTable) == 0x654);
extern float DAT_0118aba0[2];
extern float DAT_0118aba8[2];

extern float DAT_011c96fc;
extern const float DAT_01018f98;
void FUN_005330e0(float&, float, float);
class ImageSpaceManager
{
  public:
    static ImageSpaceManager* FUN_004e3270();
    void FUN_00b8cb30(int, int, float*, float);
    void AccumulateComponentValues(int, int, float*, float);
    void FUN_00b8b540(RgbaColor&);
    void FUN_00b8b610(RgbaColor&);
    void FUN_00b8b5c0(RgbaColor&);
    void FUN_00b8b690(RgbaColor&);
    void RaiseHighestBlurRadius(float);
    void RaiseBlurRadius(float);
    void FUN_00b8afb0(float);
    void FUN_00b8af40(float);
    void FUN_00b8af90(float);
    void AddDoubleVision(float);
    void SetRadialBlurParameters(float, float, float, float, float, const NiPoint2&);
    void FUN_00b8b760(float, float, float, float, float, const NiBound&);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDistanceEffect(float, unsigned int, float, const NiBound&);
    void FUN_00b8b6e0(float, float, float, float, float, const NiPoint2&);
    void FUN_00b8b130(float, unsigned int, float, float, float);
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual void UpdateWorldBound();
    const NiBound& FUN_0043d450() const;
};

extern TESImageSpaceModifier DAT_011c9750;
class TESSound : public TESForm
{
};
int __cdecl Warning(const char*, ...);
#endif

// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsaudio/bsgamesound.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00ae9ef0  BSGameSound::IsPlaying  (26 bytes)
//   0x00ae9f10  BSGameSound::IsInDecay  (28 bytes)
//   0x00ae9f30  BSGameSound::IsPaused  (26 bytes)
//   0x00ae9f50  BSGameSound::GetVolume  (17 bytes)
//   0x00ae9fb0  BSGameSound::SetListenerID  (25 bytes)
//
// uiSoundFlags at +0x10, m_fRolloff at +0x24 and m_uiSoundParameter7 at
// +0x154. NiPoint3 is the canonical engine header; NiTPointerList derives
// from the NiTPointerListBase template shipped in layout_support.h.
#ifndef FNV_BSGAMESOUND_H
#define FNV_BSGAMESOUND_H


#include "layout_support.h"
#include "NiPoint3.h"

class SoundMessageRecord;

template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<T>, T>
{
};

#pragma pack(push, 4)
class BSGameSound
{
  public:
    void** m_ppVirtualMethodTable;                                     // +0x0
    unsigned int m_uiSoundResourceID;                               // +0x4
    unsigned int m_uiSoundFlags;                         // +0x8
    unsigned int m_uiSoundParameter11;                   // +0xC
    unsigned int uiSoundFlags;                           // +0x10
    int m_iSoundType;                                    // +0x14
    unsigned short m_uiSoundParameterA;                  // +0x18
    unsigned short m_uiReverbAttenuation;                // +0x1A
    unsigned short m_uiSoundParameterB;                  // +0x1C
    unsigned short m_uiSoundParameter6;                  // +0x1E
    unsigned short m_uiSoundParameter5;                  // +0x20
    float m_fRolloff;                                    // +0x24
    float m_fMinimumDistance;                            // +0x28
    float m_fMaximumDistance;                            // +0x2C
    unsigned int m_uiSoundCategory;                      // +0x30
    unsigned short m_uiSoundParameter4;                  // +0x34
    char pFilename[262];                                 // +0x36
    float afValueAfterThirdFloat;                        // +0x13C
    float afThirdFloatArgument;                          // +0x140
    unsigned int m_uiSoundParameter12;                   // +0x144
    unsigned int m_uiSoundParameter3;                    // +0x148
    unsigned int m_uiSoundParameter13;                   // +0x14C
    float m_uiSoundParameter1;                           // +0x150
    unsigned int m_uiSoundParameter7;                    // +0x154
    unsigned char m_uiSoundParameter8;                   // +0x158
    unsigned short m_uiSoundParameter10;                 // +0x15A
    unsigned int m_uiPlaybackId;                         // +0x15C
    unsigned int m_uiSoundParameter2;                    // +0x160
    void(__cdecl* m_pfnBooleanCallback)(void*, bool);    // +0x164
    void(__cdecl* m_pfnIntegerCallback)(void*, int);     // +0x168
    void* m_pAudioSource;                                // +0x16C
    void* m_pAudioData;                                  // +0x170
    unsigned int m_uiSoundParameter9;                    // +0x174
    unsigned int m_uiTrailingValue2;                     // +0x178
    NiPoint3 m_kLocation;                                // +0x17C
    unsigned int iPriority;                              // +0x188
    NiTPointerList<SoundMessageRecord*> m_kMessageList;  // +0x18C

// @fnv 0x00ae9ef0
    bool IsPlaying()
    {
        return (uiSoundFlags & 0x20) != 0;
    }
// @fnv 0x00ae9f10
    bool IsInDecay()
    {
        return (uiSoundFlags & 0x80000) != 0;
    }
// @fnv 0x00ae9f30
    bool IsPaused()
    {
        return (uiSoundFlags & 0x40) != 0;
    }
// @fnv 0x00ae9f50
    float GetVolume()
    {
        return m_fRolloff;
    }
// @fnv 0x00ae9fb0
    void SetListenerID(unsigned int uiEnvironmentType)
    {
        m_uiSoundParameter7 = uiEnvironmentType;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSGameSound) == 0x198);
FNV_STATIC_ASSERT(offsetof(BSGameSound, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSGameSound, uiSoundFlags) == 0x10);
FNV_STATIC_ASSERT(offsetof(BSGameSound, m_fRolloff) == 0x24);
FNV_STATIC_ASSERT(offsetof(BSGameSound, m_uiSoundParameter7) == 0x154);
FNV_STATIC_ASSERT(offsetof(BSGameSound, m_kLocation) == 0x17C);
FNV_STATIC_ASSERT(offsetof(BSGameSound, m_kMessageList) == 0x18C);
#endif

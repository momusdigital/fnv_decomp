// fallout_shared/lipsynchanim_decls.h: declares BSFaceGenAnimationData, LipSyncAnimation, NiBinaryStream
#ifndef FNV_LIPSYNCHANIM_DECLS_H
#define FNV_LIPSYNCHANIM_DECLS_H


#include "layout_support.h"

enum BS_FACEGEN_MORPH_TYPE
{
    BS_FACEGEN_MORPH_PHONEME = 0,
    BS_FACEGEN_MORPH_MODIFIER = 2
};

class BSFaceGenAnimationData
{
  public:
    // Only the virtual entries used by this unit have known PC signatures.
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
    virtual void SetTransitionDuration(float duration);
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
    virtual void InsertPhonemeKeyframe(float* phonemes, float duration);
    virtual void AddModifierKeyframe(float* modifiers, float duration);
    virtual void AddKeyframe(BS_FACEGEN_MORPH_TYPE type, float duration, bool clear);
};

class LipSyncAnimation
{
  public:
    unsigned int iTransformCountPerTrack;
    int m_iValue;
    float** m_ppPhonemeFrames;
    float** m_ppModifierFrames;

    bool ApplyToAnimationData(BSFaceGenAnimationData* animation, float endDelay);
    void* DeleteThis(unsigned int flags);
    void FUN_004d5080();
    float GetNegativeMagnitude(bool, bool, bool, bool, bool);
};

FNV_STATIC_ASSERT(sizeof(LipSyncAnimation) == 16);
FNV_STATIC_ASSERT(offsetof(LipSyncAnimation, m_ppPhonemeFrames) == 8);
FNV_STATIC_ASSERT(offsetof(LipSyncAnimation, m_ppModifierFrames) == 12);

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl operator delete(void*);
float __cdecl FUN_0040ebd0(float, float);

class NiBinaryStream
{
  public:
    unsigned int Read(void*, unsigned int);
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
bool __cdecl Decompress(NiBinaryStream*, char*, unsigned int);

#endif

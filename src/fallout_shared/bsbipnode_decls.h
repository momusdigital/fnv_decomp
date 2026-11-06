// fallout_shared/bsbipnode_decls.h: declares NiQuaternion, NiQuatTransform, NiAVObject, NiInterpolator, NiBlendInterpolator and more
#ifndef FNV_BSBIPNODE_DECLS_H
#define FNV_BSBIPNODE_DECLS_H


#include "NiObjectNET.h"
#include "NiPoint3.h"

class NiQuaternion
{
  public:
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};

class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;

    NiQuatTransform();
    bool IsTranslateXNotNegatedConstant();
    const NiPoint3& GetTranslate();
    bool FUN_004f02e0();
    const NiQuaternion& GetOffsetC();
    bool FUN_004f0320();
    float GetFloatAtOffset1C();
};
FNV_STATIC_ASSERT(sizeof(NiQuatTransform) == 32);

// Only the APIs used here are needed; this unit does not allocate NiAVObject.
class NiAVObject : public NiObjectNET
{
  public:
    bool GetSelectiveUpdate();
    void FUN_00440460(const NiPoint3& translate);
    void FUN_004f0160(const NiQuaternion& rotate);
    void FUN_00440490(float scale);
};

class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;
    // NiObject's canonical declaration supplies slots 0 and 1. Preserve the
    // remaining inherited slots before the transform Update overload at 0x8c.
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
    virtual bool Update(float time, NiObjectNET* target, NiQuatTransform& transform);
};

class NiBlendInterpolator : public NiInterpolator
{
  public:
    struct InterpArrayItem;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    InterpArrayItem* m_pInterpArray;
    NiInterpolator* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;
};
class NiBlendTransformInterpolator : public NiBlendInterpolator
{
};
FNV_STATIC_ASSERT(sizeof(NiBlendTransformInterpolator) == 48);

class NiTimeController : public NiObject
{
  public:
    unsigned short m_uiObjectFlags;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    NiPointer<NiTimeController> m_spNextController;
};
class NiInterpController : public NiTimeController
{
};
class NiMultiTargetTransformController : public NiInterpController
{
  public:
    NiBlendTransformInterpolator* m_pkBlendInterpolators;
    NiAVObject** m_ppTargetObjects;
    unsigned short m_usNumInterps;
};
class AnimationInterpolatorNode : public NiMultiTargetTransformController
{
  public:
    bool FUN_004f05a0();
    void UpdateInterpolatorsAtTime(float time, bool selective);
};
FNV_STATIC_ASSERT(sizeof(AnimationInterpolatorNode) == 64);
FNV_STATIC_ASSERT(offsetof(AnimationInterpolatorNode, m_pkBlendInterpolators) == 0x34);
FNV_STATIC_ASSERT(offsetof(AnimationInterpolatorNode, m_ppTargetObjects) == 0x38);
FNV_STATIC_ASSERT(offsetof(AnimationInterpolatorNode, m_usNumInterps) == 0x3c);

#endif

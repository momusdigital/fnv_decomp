#ifndef NITRANSFORMINTERPOLATOR_DECLS_H
#define NITRANSFORMINTERPOLATOR_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
#include "nitransforminterpolator_types_NiQuatTransform.h"
#include "nitransforminterpolator_types_NiTransformData.h"

class NiKeyBasedInterpolator
{
  public:
    virtual void vfn_00();
    unsigned int m_iObjectReferenceCount;
    float m_fLastTime;
    NiKeyBasedInterpolator();
};

class NiTransformData;
class NiObjectNET;
class CloningProcess;

class NiBoolInterpolator
{
  public:
    void CopyMemberData(NiBoolInterpolator*, CloningProcess&);
};

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY
    };
    float m_fTime;
};
class PositionKeyInterpolator : public AnimationKey
{
  public:
    static NiPoint3 InterpolatePosition(float, PositionKeyInterpolator*, AnimationKey::KeyType, unsigned int,
                                        unsigned int&, unsigned char);
};
class TimedRotationKey : public AnimationKey
{
  public:
    static NiQuaternion InterpolatePosition(float, TimedRotationKey*, AnimationKey::KeyType, unsigned int,
                                            unsigned int&, unsigned char);
};
class TimedAnimationKey : public AnimationKey
{
  public:
    static float InterpolatePosition(float, TimedAnimationKey*, AnimationKey::KeyType, unsigned int, unsigned int&,
                                     unsigned char);
};

template <class T> class TransformDataPointer
{
  public:
    T* p;
    TransformDataPointer(T* value = 0) : p(value)
    {
        if (p)
            InterlockedIncrement((long volatile*)((char*)p + 4));
    }
    TransformDataPointer& operator=(const TransformDataPointer& rhs)
    {
        if (p != rhs.p)
        {
            if (p)
                p->DecRefCount();
            p = rhs.p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

class NiTransformInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiQuatTransform m_kDefaultTransform;
    TransformDataPointer<NiTransformData> m_spTransformData;
    unsigned short m_usLastRotationKeyIndex;
    unsigned short m_usLastPositionKeyIndex;
    unsigned short m_usLastScaleKeyIndex;
    unsigned char m_padding36[2];
    NiPoint3 m_kDefaultTranslation;
    bool m_bPoseValid;
    unsigned char m_padding45[3];

    NiTransformInterpolator(NiQuatTransform);
    NiTransformInterpolator(NiTransformData*);
    void CopyMemberData(NiTransformInterpolator*, CloningProcess&);
    void GetInterpolatorTimeRange(float&, float&);
    bool Update(float, NiObjectNET*, NiQuatTransform&);
    PositionKeyInterpolator* FUN_00a3f990(unsigned int&, AnimationKey::KeyType&, unsigned char&);
    TimedRotationKey* FUN_0058cb00(unsigned int&, AnimationKey::KeyType&, unsigned char&);
    TimedAnimationKey* GetScaleKeys(unsigned int&, AnimationKey::KeyType&, unsigned char&);
};
#endif

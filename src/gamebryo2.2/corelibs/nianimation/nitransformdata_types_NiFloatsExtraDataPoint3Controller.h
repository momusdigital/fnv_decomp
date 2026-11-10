// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_FNV_NIFLOATSEXTRADATAPOINT3CONTROLLER_H
#define FNV_NITRANSFORMDATA_FNV_NIFLOATSEXTRADATAPOINT3CONTROLLER_H

#include "nitransformdata_layout_support.h"
#include "nitransformdata_NiFixedString.h"
#include "nitransformdata_NiObject.h"
#include "nitransformdata_NiObjectNET.h"
#include "nitransformdata_layout_support.h"
class NiUpdateData;
class NiBlendInterpolator;
class NiRTTI;
class NiExtraDataController;
class NiFloatsExtraDataPoint3Controller;
class NiInterpController;
class NiInterpolator;
class NiSingleInterpController;
class NiTimeController : public NiObject
{
  public:
    virtual void Start(float time);
    virtual void Stop();
    virtual void Update(NiUpdateData& data);
    virtual void SetTarget(NiObjectNET* target);
    virtual bool IsTransformController() const;
    virtual bool IsVertexController() const;
    virtual float ComputeScaledTime(float time);
    virtual void ResetControllerState() const;
    virtual bool IsGeometryController() const;
    virtual bool IsTransformInterpolator() const;

    // base NiObject at +0x0, size 8
    unsigned short m_uiObjectFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    float m_fFrequency;                              // +0xC, 4 bytes
    float m_fPhase;                                  // +0x10, 4 bytes
    float m_fLoKeyTime;                              // +0x14, 4 bytes
    float m_fHiKeyTime;                              // +0x18, 4 bytes
    float m_fStartTime;                              // +0x1C, 4 bytes
    float m_fLastTime;                               // +0x20, 4 bytes
    float m_fWeightAdjustedLastTime;                 // +0x24, 4 bytes
    float m_fControllerTime;                         // +0x28, 4 bytes
    NiObjectNET* m_pkTarget;                         // +0x2C, 4 bytes
    NiPointer<NiTimeController> m_spNextController;  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiObject*)
    // void __cdecl NiTimeController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTimeController::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTimeController::*(unsigned short, unsigned short)
    // void __cdecl NiTimeController::*(bool, unsigned short)
    // bool __cdecl NiTimeController::*(unsigned short)
    // NiTimeController
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::AnimType)
    // NiTimeController::AnimType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::CycleType)
    // NiTimeController::CycleType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // NiObjectNET* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiObjectNET*)
    // unsigned int __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // NiTimeController* __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // bool __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // NiTimeController& __cdecl NiTimeController::*(const NiTimeController&)
    // void __cdecl NiTimeController::*()
};
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 52);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fFrequency) == 12);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fPhase) == 16);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLoKeyTime) == 20);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fHiKeyTime) == 24);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fStartTime) == 28);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLastTime) == 32);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fWeightAdjustedLastTime) == 36);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fControllerTime) == 40);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 44);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_spNextController) == 48);
class NiInterpController : public NiTimeController
{
  public:
    virtual unsigned short GetInterpolatorCount() const;
    virtual const char* GetTargetName(unsigned short index) const;
    virtual unsigned short GetTargetIndex(const char* id) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& id) const;
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void AdvanceControllerTime();
    virtual const char* GetControllerID() const;
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short index);
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                      bool accumulateAnimations, float threshold, unsigned char size);
    virtual void SetActiveTimeRange(float startTime, float endTime);

  protected:
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

  public:
    // base NiTimeController at +0x0, size 52
    // const NiRTTI* __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiObject*)
    // void __cdecl NiInterpController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpController::*(NiUpdateData&)
    // bool __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(bool)
    // SetActiveTimeRange
    // NiInterpController
    // void __cdecl NiInterpController::*()
    // NiInterpController& __cdecl NiInterpController::*(const NiInterpController&)
    // void __cdecl NiInterpController::*()
};
FNV_STATIC_ASSERT(sizeof(NiInterpController) == 52);
class NiSingleInterpController : public NiInterpController
{
  public:
    virtual bool TargetIsRequired(NiObjectNET* object) const;
    // base NiInterpController at +0x0, size 52
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x34, 4 bytes
    // const NiRTTI* __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiObject*)
    // void __cdecl NiSingleInterpController::*(NiTPrimitiveArray<char *>*)
    // unsigned short __cdecl NiSingleInterpController::*()
    // const char* __cdecl NiSingleInterpController::*(unsigned short)
    // unsigned short __cdecl NiSingleInterpController::*(const char*)
    // unsigned short __cdecl NiSingleInterpController::*(const NiFixedString&)
    // NiInterpolator* __cdecl NiSingleInterpController::*(unsigned short)
    // void __cdecl NiSingleInterpController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(float, float)
    // NiSingleInterpController
    // bool __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*()
    // NiSingleInterpController& __cdecl NiSingleInterpController::*(const NiSingleInterpController&)
    // void __cdecl NiSingleInterpController::*()
};
FNV_STATIC_ASSERT(sizeof(NiSingleInterpController) == 56);
FNV_STATIC_ASSERT(offsetof(NiSingleInterpController, m_spControllerInterpolator) == 52);
class NiExtraDataController : public NiSingleInterpController
{
  public:
    virtual bool IsEqual(NiObject* object) const;
    // base NiSingleInterpController at +0x0, size 56
    NiFixedString m_kDataName;            // +0x38, 4 bytes
    NiPointer<NiExtraData> m_pExtraData;  // +0x3C, 4 bytes
    // const NiRTTI* __cdecl NiExtraDataController::*()
    // void __cdecl NiExtraDataController::*(NiStream&)
    // void __cdecl NiExtraDataController::*(NiStream&)
    // bool __cdecl NiExtraDataController::*(NiStream&)
    // void __cdecl NiExtraDataController::*(NiStream&)
    // bool __cdecl NiExtraDataController::*(NiObject*)
    // void __cdecl NiExtraDataController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiExtraDataController::*()
    // const NiFixedString& __cdecl NiExtraDataController::*()
    // NiExtraData* __cdecl NiExtraDataController::*()
    // void __cdecl NiExtraDataController::*(NiObjectNET*)
    // void __cdecl NiExtraDataController::*(NiStream&)
    // const char* __cdecl NiExtraDataController::*()
    // NiExtraDataController
    // bool __cdecl NiExtraDataController::*(NiObjectNET*)
    // void __cdecl NiExtraDataController::*()
    // void __cdecl NiExtraDataController::*(const NiFixedString&)
    // NiExtraDataController& __cdecl NiExtraDataController::*(const NiExtraDataController&)
    // void __cdecl NiExtraDataController::*()
};
FNV_STATIC_ASSERT(sizeof(NiExtraDataController) == 64);
FNV_STATIC_ASSERT(offsetof(NiExtraDataController, m_kDataName) == 56);
FNV_STATIC_ASSERT(offsetof(NiExtraDataController, m_pExtraData) == 60);
class NiFloatsExtraDataPoint3Controller : public NiExtraDataController
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                      bool accumulateAnimations, float threshold, unsigned char size);

  protected:
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

  public:
    // base NiExtraDataController at +0x0, size 64
    int m_iFloatsExtraDataIndex;  // +0x40, 4 bytes
    NiFixedString m_kCtlrID;      // +0x44, 4 bytes
    // const NiRTTI* __cdecl NiFloatsExtraDataPoint3Controller::*()
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiStream&)
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiStream&)
    // bool __cdecl NiFloatsExtraDataPoint3Controller::*(NiStream&)
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiStream&)
    // bool __cdecl NiFloatsExtraDataPoint3Controller::*(NiObject*)
    // NiObject* __cdecl NiFloatsExtraDataPoint3Controller::*()
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiTPrimitiveArray<char *>*)
    // NiFloatsExtraDataPoint3Controller
    // void __cdecl NiFloatsExtraDataPoint3Controller::*()
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiUpdateData&)
    // int __cdecl NiFloatsExtraDataPoint3Controller::*()
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(int)
    // NiInterpolator* __cdecl NiFloatsExtraDataPoint3Controller::*(unsigned short)
    // void __cdecl NiFloatsExtraDataPoint3Controller::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiFloatsExtraDataPoint3Controller::*(unsigned short, bool, bool, float, unsigned char)
    // const char* __cdecl NiFloatsExtraDataPoint3Controller::*()
    // bool __cdecl NiFloatsExtraDataPoint3Controller::*(NiInterpolator*, unsigned short)
    // NiFloatsExtraDataPoint3Controller& __cdecl NiFloatsExtraDataPoint3Controller::*(const NiFloatsExtraDataPoint3Controller&)
    // void __cdecl NiFloatsExtraDataPoint3Controller::*()
};
FNV_STATIC_ASSERT(sizeof(NiFloatsExtraDataPoint3Controller) == 72);
FNV_STATIC_ASSERT(offsetof(NiFloatsExtraDataPoint3Controller, m_iFloatsExtraDataIndex) == 64);
FNV_STATIC_ASSERT(offsetof(NiFloatsExtraDataPoint3Controller, m_kCtlrID) == 68);
#endif

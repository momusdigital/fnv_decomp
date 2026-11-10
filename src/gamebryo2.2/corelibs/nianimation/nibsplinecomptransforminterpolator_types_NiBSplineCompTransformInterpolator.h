// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBSPLINECOMPTRANSFORMINTERPOLATOR_H
#define FNV_NIBSPLINECOMPTRANSFORMINTERPOLATOR_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiBSplineBasisData;
class NiStream;
class CloningProcess;
class NiObjectNET;
class NiBSplineCompTransformInterpolator;
class NiBSplineData;
class NiBSplineInterpolator;
class NiBSplineTransformInterpolator;
class NiInterpolator;
class NiQuatTransform;
class NiQuaternion;
#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    float m_fLastTime;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl NiInterpolator::*()
    // void __cdecl NiInterpolator::*(NiInterpolator*, CloningProcess&)
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
class NiBSplineInterpolator : public NiInterpolator
{
  public:
    // base NiInterpolator at +0x0, size 12
    float m_fStartTime;                                 // +0xC, 4 bytes
    float m_fEndTime;                                   // +0x10, 4 bytes
    NiPointer<NiBSplineData> m_spTransformData;         // +0x14, 4 bytes
    NiPointer<NiBSplineBasisData> m_spSplineBasisData;  // +0x18, 4 bytes
    // const NiRTTI* __cdecl NiBSplineInterpolator::*()
    // void __cdecl NiBSplineInterpolator::*(NiBSplineInterpolator*, CloningProcess&)
    // void __cdecl NiBSplineInterpolator::*(NiStream&)
    // void __cdecl NiBSplineInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineInterpolator::*(NiStream&)
    // void __cdecl NiBSplineInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineInterpolator::*(NiObject*)
    // void __cdecl NiBSplineInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiBSplineInterpolator::*()
    // void __cdecl NiBSplineInterpolator::*()
    // NiBSplineData* __cdecl NiBSplineInterpolator::*()
    // void __cdecl NiBSplineInterpolator::*(NiBSplineData*, NiBSplineBasisData*)
    // NiBSplineBasisData* __cdecl NiBSplineInterpolator::*()
    // void __cdecl NiBSplineInterpolator::*(float, float)
    // void __cdecl NiBSplineInterpolator::*(float&, float&)
    // void __cdecl NiBSplineInterpolator::*(float, float)
    // NiInterpolator* __cdecl NiBSplineInterpolator::*(float, float)
    // NiBSplineInterpolator
    // NiBSplineInterpolator& __cdecl NiBSplineInterpolator::*(const NiBSplineInterpolator&)
    // void __cdecl NiBSplineInterpolator::*()
    // void __cdecl NiBSplineInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineInterpolator) == 28);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_fStartTime) == 12);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_fEndTime) == 16);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_spTransformData) == 20);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_spSplineBasisData) == 24);
#pragma pack(push, 4)
class NiQuaternion
{
  public:
    float m_fVectorX;     // +0x0, 4 bytes
    float m_fVectorY;     // +0x4, 4 bytes
    float m_fVectorZ;     // +0x8, 4 bytes
    float m_fScalarPart;  // +0xC, 4 bytes
    // NiQuaternion
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*(float, float, float, float)
    // void __cdecl NiQuaternion::*(float&, float&, float&, float&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // operator-
    // operator*
    // operator*=
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // float __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float&, NiPoint3&)
    // void __cdecl NiQuaternion::*(float, const NiPoint3&)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float, float, float)
    // void __cdecl NiQuaternion::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiQuaternion::*(const char*)
    // void __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*(float, float, float)
    // float __cdecl NiQuaternion::*(float, float)
    void FastNormalize();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuaternion) == 16);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorX) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorY) == 4);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorZ) == 8);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fScalarPart) == 12);
#pragma pack(push, 4)
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;   // +0x0, 12 bytes
    NiQuaternion m_kRotate;  // +0xC, 16 bytes
    float m_fScale;          // +0x1C, 4 bytes
    // NiQuatTransform
    // const NiPoint3& __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(const NiPoint3&)
    // const NiQuaternion& __cdecl NiQuatTransform::*()
    // float __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(float)
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuatTransform) == 32);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kTranslate) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kRotate) == 12);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_fScale) == 28);
#pragma pack(push, 4)
class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
  public:
    // base NiBSplineInterpolator at +0x0, size 28
    NiQuatTransform m_kDefaultTransform;  // +0x1C, 32 bytes
    unsigned int m_kTransCPHandle;        // +0x3C, 4 bytes
    unsigned int m_kRotCPHandle;          // +0x40, 4 bytes
    unsigned int m_kScaleCPHandle;        // +0x44, 4 bytes
    // const NiRTTI* __cdecl NiBSplineTransformInterpolator::*()
    // NiObject* __cdecl NiBSplineTransformInterpolator::*(CloningProcess&)
    // void __cdecl NiBSplineTransformInterpolator::*(NiBSplineTransformInterpolator*, CloningProcess&)
    // void __cdecl NiBSplineTransformInterpolator::*(NiStream&)
    // void __cdecl NiBSplineTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineTransformInterpolator::*(NiStream&)
    // void __cdecl NiBSplineTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineTransformInterpolator::*(NiObject*)
    // NiObject* __cdecl NiBSplineTransformInterpolator::*()
    // void __cdecl NiBSplineTransformInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiBSplineTransformInterpolator
    // bool __cdecl NiBSplineTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // bool __cdecl NiBSplineTransformInterpolator::*()
    // void __cdecl NiBSplineTransformInterpolator::*(NiPoint3)
    // void __cdecl NiBSplineTransformInterpolator::*(NiQuaternion)
    // void __cdecl NiBSplineTransformInterpolator::*(float)
    // void __cdecl NiBSplineTransformInterpolator::*(NiQuatTransform)
    // unsigned short __cdecl NiBSplineTransformInterpolator::*()
    // unsigned int __cdecl NiBSplineTransformInterpolator::*(unsigned short)
    // unsigned int __cdecl NiBSplineTransformInterpolator::*(unsigned short)
    // bool __cdecl NiBSplineTransformInterpolator::*(unsigned short)
    // unsigned int __cdecl NiBSplineTransformInterpolator::*(unsigned short)
    // void __cdecl NiBSplineTransformInterpolator::*(unsigned int, unsigned short)
    // void __cdecl NiBSplineTransformInterpolator::*()
    // NiBSplineTransformInterpolator& __cdecl NiBSplineTransformInterpolator::*(const NiBSplineTransformInterpolator&)
    // void __cdecl NiBSplineTransformInterpolator::*()
    // void __cdecl NiBSplineTransformInterpolator::*()
    void FUN_00a57fd0(NiBSplineTransformInterpolator*, CloningProcess&);
    void LoadBinary(NiStream&);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineTransformInterpolator) == 72);
FNV_STATIC_ASSERT(offsetof(NiBSplineTransformInterpolator, m_kDefaultTransform) == 28);
FNV_STATIC_ASSERT(offsetof(NiBSplineTransformInterpolator, m_kTransCPHandle) == 60);
FNV_STATIC_ASSERT(offsetof(NiBSplineTransformInterpolator, m_kRotCPHandle) == 64);
FNV_STATIC_ASSERT(offsetof(NiBSplineTransformInterpolator, m_kScaleCPHandle) == 68);
#pragma pack(push, 4)
class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
  public:
    // base NiBSplineTransformInterpolator at +0x0, size 72
    float m_afOffsetAndHalfRange[6];  // +0x48, 24 bytes
    // const NiRTTI* __cdecl NiBSplineCompTransformInterpolator::*()
    // NiObject* __cdecl NiBSplineCompTransformInterpolator::*(CloningProcess&)
    // void __cdecl NiBSplineCompTransformInterpolator::*(NiBSplineCompTransformInterpolator*, CloningProcess&)
    // void __cdecl NiBSplineCompTransformInterpolator::*(NiStream&)
    // void __cdecl NiBSplineCompTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineCompTransformInterpolator::*(NiStream&)
    // void __cdecl NiBSplineCompTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBSplineCompTransformInterpolator::*(NiObject*)
    // NiObject* __cdecl NiBSplineCompTransformInterpolator::*()
    // void __cdecl NiBSplineCompTransformInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiBSplineCompTransformInterpolator
    // bool __cdecl NiBSplineCompTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // void __cdecl NiBSplineCompTransformInterpolator::*(float, unsigned short)
    // void __cdecl NiBSplineCompTransformInterpolator::*(float, unsigned short)
    // float __cdecl NiBSplineCompTransformInterpolator::*(unsigned short)
    // float __cdecl NiBSplineCompTransformInterpolator::*(unsigned short)
    // bool __cdecl NiBSplineCompTransformInterpolator::*()
    // void __cdecl NiBSplineCompTransformInterpolator::*()
    // NiBSplineCompTransformInterpolator& __cdecl NiBSplineCompTransformInterpolator::*(const NiBSplineCompTransformInterpolator&)
    // void __cdecl NiBSplineCompTransformInterpolator::*()
    // void __cdecl NiBSplineCompTransformInterpolator::*()
    virtual void LoadBinary(NiStream&);
    virtual void CopyMemberData(NiBSplineCompTransformInterpolator*, CloningProcess&);
    virtual bool Update(float, NiObjectNET*, NiQuatTransform&);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineCompTransformInterpolator) == 96);
FNV_STATIC_ASSERT(offsetof(NiBSplineCompTransformInterpolator, m_afOffsetAndHalfRange) == 72);
#endif

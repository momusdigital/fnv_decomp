// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BHKRIGIDBODY_H
#define FNV_BHKRIGIDBODY_H

#include "layout_support.h"
#include "NiObject.h"
#include <xmmintrin.h>
#include "layout_support.h"
class NiPoint3;
class NiQuaternion;
class hkpMotion;
class bhkEntity;
class bhkRefObject;
class bhkRigidBody;
class bhkSerializable;
class bhkWorldObject;
class hkReferencedObject;
class hkSerializableCinfo;
#pragma pack(push, 4)
class bhkRefObject : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    hkReferencedObject* m_pHavokObject;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl bhkRefObject::*()
    // void __cdecl bhkRefObject::*(NiTPrimitiveArray<char *>*)
    // bhkRefObject
    // void __cdecl bhkRefObject::*()
    // hkReferencedObject* __cdecl bhkRefObject::*()
    // hkReferencedObject* __cdecl bhkRefObject::*()
    // int __cdecl bhkRefObject::*()
    // bhkRefObject& __cdecl bhkRefObject::*(const bhkRefObject&)
    // void __cdecl bhkRefObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(bhkRefObject) == 12);
FNV_STATIC_ASSERT(offsetof(bhkRefObject, m_pHavokObject) == 8);
#pragma pack(push, 4)
class bhkSerializable : public bhkRefObject
{
  public:
    // base bhkRefObject at +0x0, size 12
    hkSerializableCinfo* pInfo;  // +0xC, 4 bytes
    // const NiRTTI* __cdecl bhkSerializable::*()
    // void __cdecl bhkSerializable::*(NiTPrimitiveArray<char *>*)
    // void __cdecl bhkSerializable::*(NiStream&)
    // void __cdecl bhkSerializable::*(NiStream&)
    // bool __cdecl bhkSerializable::*(NiStream&)
    // void __cdecl bhkSerializable::*(NiStream&)
    // bool __cdecl bhkSerializable::*(NiObject*)
    // bhkSerializable
    // void __cdecl bhkSerializable::*()
    // hkSerializableCinfo& __cdecl bhkSerializable::*()
    // void __cdecl bhkSerializable::*(hkReferencedObject*)
    // void __cdecl bhkSerializable::*()
    // void __cdecl bhkSerializable::*()
    // bhkSerializable& __cdecl bhkSerializable::*(const bhkSerializable&)
    // void __cdecl bhkSerializable::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(bhkSerializable) == 16);
FNV_STATIC_ASSERT(offsetof(bhkSerializable, pInfo) == 12);
#pragma pack(push, 4)
class bhkWorldObject : public bhkSerializable
{
  public:
    // base bhkSerializable at +0x0, size 16
    unsigned int iFlags;  // +0x10, 4 bytes
    // const NiRTTI* __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*(NiTPrimitiveArray<char *>*)
    // void __cdecl bhkWorldObject::*(NiStream&)
    // void __cdecl bhkWorldObject::*(NiStream&)
    // bool __cdecl bhkWorldObject::*(NiStream&)
    // void __cdecl bhkWorldObject::*(NiStream&)
    // bool __cdecl bhkWorldObject::*(NiObject*)
    // bhkWorldObject
    // void __cdecl bhkWorldObject::*()
    // hkpWorldObject* __cdecl bhkWorldObject::*()
    // hkpWorldObject* __cdecl bhkWorldObject::*()
    // const hkpCollidable* __cdecl bhkWorldObject::*()
    // hkpCollidable* __cdecl bhkWorldObject::*()
    // CFilter __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*(CFilter)
    // void __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*()
    // bool __cdecl bhkWorldObject::*()
    // bool __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(unsigned int, hkpPropertyValue&)
    // void __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(const char*)
    // const char* __cdecl bhkWorldObject::*()
    // GetProperty
    // hkpShape* __cdecl bhkWorldObject::*()
    // bhkShape* __cdecl bhkWorldObject::*()
    // bhkShape* __cdecl bhkWorldObject::*(bhkShape*)
    // const hkpWorld* __cdecl bhkWorldObject::*()
    // hkpWorld* __cdecl bhkWorldObject::*()
    // bool __cdecl bhkWorldObject::*(bhkWorld*)
    // bhkWorldObject* __cdecl bhkWorldObject::*(const hkpWorldObject*)
    // void __cdecl bhkWorldObject::*(NiAVObject*, unsigned int)
    // NiAVObject* __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(bool)
    // unsigned int __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(unsigned int, bool)
    // void __cdecl bhkWorldObject::*(unsigned int)
    // bool __cdecl bhkWorldObject::*(unsigned int)
    // void __cdecl bhkWorldObject::*(bool)
    // void __cdecl bhkWorldObject::*()
    // void __cdecl bhkWorldObject::*()
    // const hkpCollidable* __cdecl bhkWorldObject::*()
    // bhkWorldObject& __cdecl bhkWorldObject::*(const bhkWorldObject&)
    // void __cdecl bhkWorldObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(bhkWorldObject) == 20);
FNV_STATIC_ASSERT(offsetof(bhkWorldObject, iFlags) == 16);
#pragma pack(push, 4)
class bhkEntity : public bhkWorldObject
{
  public:
    // base bhkWorldObject at +0x0, size 20
    // const NiRTTI* __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*(NiTPrimitiveArray<char *>*)
    // bhkEntity
    // hkpEntity* __cdecl bhkEntity::*()
    // hkpEntity* __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*(hkpEntityListener*)
    // void __cdecl bhkEntity::*(hkpEntityListener*)
    // void __cdecl bhkEntity::*(hkpEntityActivationListener*)
    // void __cdecl bhkEntity::*(hkpEntityActivationListener*)
    // void __cdecl bhkEntity::*(hkpContactListener*)
    // void __cdecl bhkEntity::*(hkpContactListener*)
    // unsigned short __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*(unsigned short)
    // hkpSimulationIsland* __cdecl bhkEntity::*()
    // hkpMaterial& __cdecl bhkEntity::*()
    // bool __cdecl bhkEntity::*()
    // bool __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*()
    // bhkEntity* __cdecl bhkEntity::*(const hkpWorldObject*)
    // void __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*(NiStream&)
    // void __cdecl bhkEntity::*(NiStream&)
    // bool __cdecl bhkEntity::*()
    // void __cdecl bhkEntity::*()
    // bhkEntity& __cdecl bhkEntity::*(const bhkEntity&)
    // void __cdecl bhkEntity::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(bhkEntity) == 20);
#pragma pack(push, 4)
class bhkRigidBody : public bhkEntity
{
  public:
    // base bhkEntity at +0x0, size 20
    BSSimpleList<NiPointer<bhkSerializable> > m_kSerializableList;  // +0x14, 8 bytes
    const NiRTTI* GetRTTI();
    unsigned int GetInstanceSize();
    void SetPosition(const NiPoint3&);
    NiPoint3& GetPosition(NiPoint3&);
    __forceinline const __m128& PositionVector();
    NiQuaternion& GetRotation(NiQuaternion&);
    __forceinline const __m128& RotationVector();
    void SetRotation(const NiQuaternion&);
    float GetBodyMass();
    hkpMotion* GetStoredDynamicMotion();
    float GetMass();
    void SetPosRot(const NiPoint3&, const NiQuaternion&);
    void* FUN_00c87a50();
    NiPoint3& FUN_00c8d200(NiPoint3&);
    __forceinline const __m128& FUN_00c8d200Vector();
    NiPoint3& GetVec(NiPoint3&);
    __forceinline const __m128& FUN_00c8d240Vector();
    // void __cdecl bhkRigidBody::*(NiStream&)
    // void __cdecl bhkRigidBody::*(NiStream&)
    // bool __cdecl bhkRigidBody::*(NiStream&)
    // void __cdecl bhkRigidBody::*(NiStream&)
    // bool __cdecl bhkRigidBody::*(NiObject*)
    // const NiRTTI* __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(NiTPrimitiveArray<char *>*)
    // bhkRigidBody
    // void __cdecl bhkRigidBody::*()
    // bhkRigidBody* __cdecl bhkRigidBody::*()
    // hkpRigidBody* __cdecl bhkRigidBody::*()
    // hkpRigidBody* __cdecl bhkRigidBody::*()
    // NiObject* __cdecl bhkRigidBody::*()
    // hkSerializableCinfo& __cdecl bhkRigidBody::*(bool&)
    // int __cdecl bhkRigidBody::*(NiStream&)
    // void __cdecl bhkRigidBody::*(bool)
    // void __cdecl bhkRigidBody::*(const hkSerializableCinfo&)
    // unsigned int __cdecl bhkRigidBody::*()
    // bool __cdecl bhkRigidBody::*(bhkWorld*)
    // bool __cdecl bhkRigidBody::*(bhkWorld*)
    // bool __cdecl bhkRigidBody::*()
    // NiAVObject* __cdecl bhkRigidBody::*(NiNode*)
    // float __cdecl bhkRigidBody::*()
    // float __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(float)
    // void __cdecl bhkRigidBody::*(float)
    // GetPosition
    // GetRotation
    // SetPosition
    // SetRotation
    // hkpMotion::MotionType __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(hkAabb&)
    // float __cdecl bhkRigidBody::*()
    // float __cdecl bhkRigidBody::*()
    // hkpMotion* __cdecl bhkRigidBody::*()
    // GetAngularVelocity
    // const float __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(bool)
    // bool __cdecl bhkRigidBody::*()
    // SetLinearVelocity
    // SetAngularVelocity
    // bool __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(float&)
    // void __cdecl bhkRigidBody::*(float)
    // void __cdecl bhkRigidBody::*(float)
    // hkMatrix3& __cdecl bhkRigidBody::*(hkMatrix3&)
    // ApplyLinearImpulse
    // ApplyAngularImpulse
    // ApplyPointImpulse
    // bhkRigidBody* __cdecl bhkRigidBody::*(const hkpWorldObject*)
    // void __cdecl bhkRigidBody::*(bhkSerializable*)
    // void __cdecl bhkRigidBody::*(bhkSerializable*)
    // unsigned int __cdecl bhkRigidBody::*()
    // BSSimpleList<NiPointer<bhkSerializable> >* __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(bhkWorld*)
    // bool __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(bool)
    // bool __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(bool)
    // bool __cdecl bhkRigidBody::*(hkpMotion::MotionType)
    // void __cdecl bhkRigidBody::*(const hkVector4&, const hkQuaternion&, float, float)
    // void __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(bool)
    // void __cdecl bhkRigidBody::*(NiAVObject*, bool, bool)
    // void __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(NiAVObject*)
    // CalculateTotalCenterOfMass
    // void __cdecl bhkRigidBody::*(NiAVObject*, hkVector4&, float&)
    // void __cdecl bhkRigidBody::*(bool)
    // bool __cdecl bhkRigidBody::*()
    // bool __cdecl bhkRigidBody::*(hkpMotion::MotionType)
    // bool __cdecl bhkRigidBody::*(const hkpMotion::MotionType&)
    // bhkRigidBody* __cdecl bhkRigidBody::*(NiAVObject*)
    // void __cdecl bhkRigidBody::*()
    // void __cdecl bhkRigidBody::*(NiTPrimitiveArray<char *>*, hkpMotion::MotionType)
    // const bhkRigidBody& __cdecl bhkRigidBody::*(const bhkRigidBody&)
    // void __cdecl bhkRigidBody::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(bhkRigidBody) == 28);
FNV_STATIC_ASSERT(offsetof(bhkRigidBody, m_kSerializableList) == 20);
#endif

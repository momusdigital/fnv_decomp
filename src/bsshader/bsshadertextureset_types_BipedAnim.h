// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BIPEDANIM_H
#define FNV_BIPEDANIM_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESObjectREFR.h"
class BipedAnimBone;
class BipedAnimObject;
class NiAVObject;
class TESModel;
#pragma pack(push, 4)
class BipedAnimBone
{
  public:
    unsigned char cFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    NiNode* pParent;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BipedAnimBone) == 8);
FNV_STATIC_ASSERT(offsetof(BipedAnimBone, cFlags) == 0);
FNV_STATIC_ASSERT(offsetof(BipedAnimBone, pParent) == 4);
#pragma pack(push, 4)
class BipedAnimObject
{
  public:
    TESForm* pParent;            // +0x0, 4 bytes
    TESModel* m_pModel;          // +0x4, 4 bytes
    NiAVObject* m_pSceneObject;  // +0x8, 4 bytes
    bool bHasAnimation;          // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BipedAnimObject) == 16);
FNV_STATIC_ASSERT(offsetof(BipedAnimObject, pParent) == 0);
FNV_STATIC_ASSERT(offsetof(BipedAnimObject, m_pModel) == 4);
FNV_STATIC_ASSERT(offsetof(BipedAnimObject, m_pSceneObject) == 8);
FNV_STATIC_ASSERT(offsetof(BipedAnimObject, bHasAnimation) == 12);
#pragma pack(push, 4)
class BipedAnim
{
  public:
    NiNode* root;                            // +0x0, 4 bytes
    BipedAnimBone bone[5];                   // +0x4, 40 bytes
    BipedAnimObject object[20];              // +0x2C, 320 bytes
    BipedAnimObject m_kPreviousObjects[20];  // +0x16C, 320 bytes
    float m_fFadeAlpha;                      // +0x2AC, 4 bytes
    TESObjectREFR* m_pActor;                 // +0x2B0, 4 bytes
    // void __cdecl BipedAnim::*(TESObjectREFR*, NiNode*)
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(NiNode*)
    // NiNode* __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(NiAVObject*)
    // RemovePart
    // void __cdecl BipedAnim::*(NiAVObject*)
    // NiNode* __cdecl BipedAnim::*(BIPED_BONE)
    NiNode* GetParentBone(BIPED_BONE boneIndex);
    // TESForm* __cdecl BipedAnim::*(BIPED_OBJECT)
    // TESForm* __cdecl BipedAnim::*(NiAVObject*)
    // bool __cdecl BipedAnim::*(TESForm*)
    // BipedAnimObject* __cdecl BipedAnim::*(TESForm*)
    // BipedAnimObject* __cdecl BipedAnim::*(BIPED_OBJECT)
    // void __cdecl BipedAnim::*(TESRace*, SEX)
    // void __cdecl BipedAnim::*(TESForm*, TESModel*, BIPED_OBJECT)
    // void __cdecl BipedAnim::*(bool)
    // void __cdecl BipedAnim::*(IO_TASK_PRIORITY, NiPointer<QueuedHelmet>&, QueuedFile*)
    // void __cdecl BipedAnim::*(unsigned int, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BipedAnim::*(TESNPC*, BIPED_OBJECT, IO_TASK_PRIORITY, QueuedFile*)
    // BipedAnimObject* __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(TESObjectWEAP*, unsigned char)
    // void __cdecl BipedAnim::*(TESObjectWEAP*, unsigned char)
    // void __cdecl BipedAnim::*()
    // TESObjectWEAP* __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(float)
    // void __cdecl BipedAnim::*(NiNode*, float)
    // void __cdecl BipedAnim::*(TESAmmo*)
    // void __cdecl BipedAnim::*(TESAmmo*)
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(TESObjectARMO*)
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(TESObjectCLOT*, bool)
    // void __cdecl BipedAnim::*(bool)
    // void __cdecl BipedAnim::*(TESObjectCLOT*)
    // void __cdecl BipedAnim::*()
    // void __cdecl BipedAnim::*(TESObjectLIGH*)
    // void __cdecl BipedAnim::*(TESObjectLIGH*)
    // void __cdecl BipedAnim::*()
    // TESObjectLIGH* __cdecl BipedAnim::*()
    // NiNode* __cdecl BipedAnim::*()
    // BSFaceGenModel* __cdecl BipedAnim::*(BIPED_OBJECT)
    // NiNode* __cdecl BipedAnim::*(BSFaceGenModel*, NiNode*, BIPED_OBJECT)
    // void __cdecl BipedAnim::*(BSFaceGenModel*, NiNode*, BIPED_OBJECT)
    // void __cdecl BipedAnim::*(NiNode*, NiAVObject*, NiNode*, bool)
    // void __cdecl BipedAnim::*(NiNode*, NiNode*, NiNode*, BipedAnim*, BIPED_OBJECT, BSFaceGenModel*)
    // NiAVObject* __cdecl BipedAnim::*(TESForm*, TESModel*, BIPED_OBJECT, TESObjectREFR*, NiAVObject*)
    // void __cdecl BipedAnim::*(NiNode*, NiNode*, BIPED_OBJECT, TESObjectREFR*)
    // TESObjectREFR* __cdecl BipedAnim::*()
    // bool __cdecl BipedAnim::*(BIPED_OBJECT)
    // BSShaderPPLightingProperty* __cdecl BipedAnim::*(NiAVObject*)
    // BIPED_OBJECT __cdecl BipedAnim::*(NiAVObject*, BSShaderPPLightingProperty*)
    // unsigned int __cdecl BipedAnim::*(NiAVObject*)
    // NiAVObject* __cdecl BipedAnim::*(NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*)
    // NiAVObject* __cdecl BipedAnim::*(NiNode*, NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*)
    // void __cdecl BipedAnim::*(NiAVObject*, bool)
    // bool __cdecl BipedAnim::*(BIPED_OBJECT)
    // bool __cdecl BipedAnim::*(TESModel*, char*)
    // TESModel* __cdecl BipedAnim::*(BIPED_OBJECT, char*)
    // TESModel* __cdecl BipedAnim::*(BIPED_OBJECT, TESModel*)
    // void* __cdecl BipedAnim::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BipedAnim) == 692);
FNV_STATIC_ASSERT(offsetof(BipedAnim, root) == 0);
FNV_STATIC_ASSERT(offsetof(BipedAnim, bone) == 4);
FNV_STATIC_ASSERT(offsetof(BipedAnim, object) == 44);
FNV_STATIC_ASSERT(offsetof(BipedAnim, m_kPreviousObjects) == 364);
FNV_STATIC_ASSERT(offsetof(BipedAnim, m_fFadeAlpha) == 684);
FNV_STATIC_ASSERT(offsetof(BipedAnim, m_pActor) == 688);
#endif

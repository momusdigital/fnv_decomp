// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCAMERASHOT_H
#define FNV_BGSCAMERASHOT_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class BGSCameraShot;
class BGSCameraShot__CAMERA_SHOT_DATA;
class BSFileEntry;
class NiAVObject;
class TESImageSpaceModifiableForm;
class TESImageSpaceModifier;
class TESModel;
class FileEntryList;
enum BGSCameraShot__CAM_ACTION
{
    BGSCameraShot__CAM_ACTION_CA_SHOOT = 0,
    BGSCameraShot__CAM_ACTION_CA_FLY = 1,
    BGSCameraShot__CAM_ACTION_CA_HIT = 2,
    BGSCameraShot__CAM_ACTION_CA_ZOOM = 3,
    BGSCameraShot__CAM_ACTION_CA_COUNT = 4
};
enum BGSCameraShot__CAM_OBJECT
{
    BGSCameraShot__CAM_OBJECT_CO_ATTACKER = 0,
    BGSCameraShot__CAM_OBJECT_CO_PROJECTILE = 1,
    BGSCameraShot__CAM_OBJECT_CO_TARGET = 2,
    BGSCameraShot__CAM_OBJECT_CO_COUNT = 3
};
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel*, TESFile*);
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESImageSpaceModifiableForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESImageSpaceModifier* m_pImageSpaceModifier;  // +0x4, 4 bytes
    // TESImageSpaceModifiableForm
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*(TESForm*)
    // void __cdecl TESImageSpaceModifiableForm::*(BaseFormComponent*)
    // bool __cdecl TESImageSpaceModifiableForm::*(BaseFormComponent*)
    // TESImageSpaceModifier* __cdecl TESImageSpaceModifiableForm::*()
    // void __cdecl TESImageSpaceModifiableForm::*(TESImageSpaceModifier*)
    // TESImageSpaceModifiableForm& __cdecl TESImageSpaceModifiableForm::*(const TESImageSpaceModifiableForm&)
    void InitItem(TESForm*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifiableForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifiableForm, m_pImageSpaceModifier) == 4);
#pragma pack(push, 4)
class BGSCameraShot__CAMERA_SHOT_DATA
{
  public:
    void Endian();
    BGSCameraShot__CAM_ACTION m_eAction;    // +0x0, 4 bytes
    BGSCameraShot__CAM_OBJECT pInputFile;   // +0x4, 4 bytes
    BGSCameraShot__CAM_OBJECT m_eAttacker;  // +0x8, 4 bytes
    unsigned int iFlags;                    // +0xC, 4 bytes
    float m_fMinTime;                       // +0x10, 4 bytes
    float m_fTargetPercent;                 // +0x14, 4 bytes
    float m_fTimeMultiplier;                // +0x18, 4 bytes
    float fMaxTime;                         // +0x1C, 4 bytes
    float m_fCameraValue1;                  // +0x20, 4 bytes
    float m_fCameraValue2;                  // +0x24, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSCameraShot__CAMERA_SHOT_DATA) == 40);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_eAction) == 0);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, pInputFile) == 4);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_eAttacker) == 8);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, iFlags) == 12);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fMinTime) == 16);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fTargetPercent) == 20);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fTimeMultiplier) == 24);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, fMaxTime) == 28);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fCameraValue1) == 32);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fCameraValue2) == 36);
#pragma pack(push, 4)
class BGSCameraShot : public TESForm, public TESModel, public TESImageSpaceModifiableForm
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    // base TESImageSpaceModifiableForm at +0x30, size 8
    BGSCameraShot__CAMERA_SHOT_DATA Data;   // +0x38, 40 bytes
    NiPointer<NiAVObject> m_pLocationNode;  // +0x60, 4 bytes
    NiPointer<NiAVObject> m_pTargetNode;    // +0x64, 4 bytes
    TESObjectREFR* m_pReference;            // +0x68, 4 bytes
    NiPointer<NiNode> m_spPositionNode;     // +0x6C, 4 bytes
    NiPointer<NiAVObject> m_pSceneObject;   // +0x70, 4 bytes
    char m_bUpdateNodePosition;             // +0x74, 1 bytes
    bool m_bFlag74;                         // +0x75, 1 bytes
    bool m_bFlag75;                         // +0x76, 1 bytes
    unsigned char layoutPadding77[1];
    // BGSCameraShot
    // void __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(TESForm*)
    // bool __cdecl BGSCameraShot::*(TESForm*)
    // void __cdecl BGSCameraShot::*()
    // bool __cdecl BGSCameraShot::*(TESFile*)
    // void __cdecl BGSCameraShot::*()
    // float __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(float)
    // float __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(float)
    // float __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(float)
    // BGSCameraShot::CAM_OBJECT __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(BGSCameraShot::CAM_OBJECT)
    // BGSCameraShot::CAM_OBJECT __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(BGSCameraShot::CAM_OBJECT)
    // BGSCameraShot::CAM_ACTION __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(BGSCameraShot::CAM_ACTION)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(bool)
    // float __cdecl BGSCameraShot::*()
    // float __cdecl BGSCameraShot::*()
    // float __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(float)
    // void __cdecl BGSCameraShot::*(bool)
    // void __cdecl BGSCameraShot::*(TESObjectREFR*, BGSCameraShot::CAM_ZOOM)
    // bool __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*()
    // void __cdecl BGSCameraShot::*(NiAVObject*)
    // void __cdecl BGSCameraShot::*(NiAVObject*)
    // void __cdecl BGSCameraShot::*(float)
    // NiPoint3 __cdecl BGSCameraShot::*()
    // NiAVObject* __cdecl BGSCameraShot::*()
    // NiAVObject* __cdecl BGSCameraShot::*()
    // TESObjectREFR* __cdecl BGSCameraShot::*()
    // NiAVObject* __cdecl BGSCameraShot::*()
    // BGSCameraShot& __cdecl BGSCameraShot::*(const BGSCameraShot&)
    // void __cdecl BGSCameraShot::*()
    virtual bool Load(TESFile*);
    void ResetCameraShot();
    void ResetFormData();
    virtual void InitItem();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSCameraShot) == 120);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, Data) == 56);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_pLocationNode) == 96);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_pTargetNode) == 100);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_pReference) == 104);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_spPositionNode) == 108);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_pSceneObject) == 112);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_bUpdateNodePosition) == 116);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_bFlag74) == 117);
FNV_STATIC_ASSERT(offsetof(BGSCameraShot, m_bFlag75) == 118);
#endif

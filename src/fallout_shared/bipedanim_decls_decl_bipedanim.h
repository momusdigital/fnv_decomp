// fallout_shared/bipedanim_decls_decl_bipedanim.h: declares NiPoint3, CloningProcess, NiFixedString, NiMemObject, NiObject and more
#ifndef BIPEDANIM_DECLS_H
#define BIPEDANIM_DECLS_H

class NiUpdateData;
class BSShaderPPLightingProperty;
class NiTexture;
class NiSourceTexture;
class QueuedFile;
class QueuedHelmet;
class TESBipedModelForm;
class NiNode;
class NiAVObject;
class BSFadeNode;
class NiTriBasedGeom;
class NiProperty;
class NiExtraData;
class NiSkinData;
class NiSkinPartition;
class NiGeometryData;
class NiSkinInstance;
class TESObjectREFR;
class TESObjectWEAP;
class BSFaceGenModel;
class BipedAnim;
class TESModel;
class TESModelTextureSwap;
class TESBoundObject;
class TESRace;
class TESNPC;
class ExtraDataList;
class ExtraDismemberedLimbs;
class Animation;
class InventoryStackRecord;
class BaseProcess;
class BGSBipedModelList;
enum BIPED_BONE
{
    BIPED_BONE_WEAPON = 1
};
enum BIPED_OBJECT
{
    BIPED_HEAD = 0,
    BIPED_WEAPON = 5,
    BIPED_COUNT = 20
};
enum SEX
{
    SEX_MALE,
    SEX_FEMALE
};
enum ENUM_FORM_ID
{
    FORM_NPC = 42
};
enum IO_TASK_PRIORITY
{
    TASK_DEFAULT = 0
};
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
class ThreeByThreeMatrix
{
  public:
    float entry[3][3];
    ThreeByThreeMatrix();
    void SetYRotation(float);
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
};
class CloningProcess
{
  public:
    void* cloneMap;
    void* processMap;
    int copyType;
    char appendChar;
    NiPoint3 scale;
    CloningProcess(float);
    ~CloningProcess();
};
template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T*);
    NiPointer& operator=(const NiPointer&);
};
template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    BSStringT(const T*);
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    operator const T*() const;
    void FUN_004afad0();
};
class NiFixedString
{
  public:
    const char* data;
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
};
namespace oldstd {
template <class T> struct vector
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};
}
template <class T> class FaceGenMatrix
{
  public:
    oldstd::vector<T> kData;
    unsigned int uiRowCount, uiColCount;
    FaceGenMatrix();
    ~FaceGenMatrix();
};
typedef FaceGenMatrix<float> FaceGenCoord;
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiObject : public NiMemObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual void vfn_14();
    virtual NiTriBasedGeom* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
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
    virtual void UpdateDownwardPass(const NiUpdateData&, unsigned int);
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    unsigned int refCount;
    NiObject* Clone();
    NiObject* CloneObject(CloningProcess&);
    void ResolveObjectPointer(NiPointer<NiObject>&);
};
class NiTimeController;
class NiObjectNET : public NiObject
{
  public:
    NiTimeController* GetControllers() const;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* GetParent();
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(const ThreeByThreeMatrix&);
    ThreeByThreeMatrix& FUN_006a9540();
    float GetFloatAt64();
    void FUN_00440490(float);
    void UpdateSceneObject();
    void SetName(const NiFixedString&);
    void FUN_00450f90(bool);
    NiExtraData* GetExtraData(const NiFixedString&);
    bool RemoveExtraDataByName(const NiFixedString&);
    bool AddExtraData(const NiFixedString&, NiExtraData*);
    const NiFixedString& GetName() const;
};
class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject*, bool);
    virtual void AddObjectAt(unsigned int, NiAVObject*);
    virtual void RemoveObject2(NiAVObject*, NiAVObject**);
    virtual void RemoveObject(NiAVObject*);
    unsigned char nodeFields[0xa4];
    NiNode(unsigned short);
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(int);
    void DetachAllChildren();
    int FUN_00453470();
    void CompactChildArray();
};
class BSFadeNode : public NiNode
{
  public:
    void* FUN_0043b1b0();
    void SetFadeMode(int);
};
class NiGeometryData : public NiObject
{
};
class NiGeometry : public NiAVObject
{
  public:
    NiProperty* GetProperty(int);
    NiGeometryData* FUN_005495f0();
};
class NiTriBasedGeom : public NiGeometry
{
  public:
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void ReplaceModelData(NiGeometryData*);
    void SetSkinInstance(NiSkinInstance*);
    NiSkinInstance* FUN_0043fad0();
};
class TESForm
{
  public:
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
    virtual bool Unk_2B();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
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
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    ENUM_FORM_ID GetFormType() const;
    unsigned int GetFormID();
};
class TESBoundObject : public TESForm
{
};
class TESNPC : public TESBoundObject
{
  public:
    TESRace* FUN_004ac110();
    TESRace* GetRace();
    SEX GetSex(bool);
    void GetFaceGenCoords(FaceGenCoord (&)[4]);
};
class TESObjectWEAP : public TESForm
{
  public:
    bool GetHideBackpack();
    bool GetHasScope();
    bool GetHasModScope();
    TESModel* FUN_00504e60();
};
class TESModel
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    virtual void vfn_18();
    virtual TESModelTextureSwap* GetAsModelTextureSwap();
    unsigned char modelFields[20];
    unsigned int GetModelLength() const;
    unsigned int FUN_004abf80();
    bool FUN_004ae8f0();
};
class TESModelTextureSwap : public TESModel
{
  public:
    void ApplyTextureSwaps(NiAVObject*);
};
class InventoryStackRecord
{
  public:
    TESBoundObject* FUN_0044ddc0();
    void SetEquipmentState(bool, bool);
    ~InventoryStackRecord();
    TESObjectWEAP* GetObject();
    void* Destroy(unsigned int);
    unsigned char GetWeaponCategory();
    bool SetEquipmentState(unsigned char, float&);
};
class BaseProcess
{
  public:
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
    virtual void vfn_b8();
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
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual InventoryStackRecord* GetWeaponInfo();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual NiNode* GetWeaponNode(bool);
    virtual NiNode* GetQuiverNode(bool);
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void UpdateWeaponDrawn(bool, BipedAnim*, Animation*, TESObjectREFR*);
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void SetWeaponModelChanged(bool);
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual NiNode* GetWeaponNode(bool);
    virtual NiNode* GetQuiverNode(bool);
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual bool IsCreature();
    static bool ApplyReferenceExtraData(NiNode*);
    static TESObjectREFR* GetReferenceFromNiAVObject(NiAVObject*);
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
    NiAVObject* Get3DSimple();
    void SetExtraDataString(TESObjectWEAP*);
    const char* GetFullName();
};
class Actor : public TESObjectREFR
{
  public:
    BaseProcess* GetProcess();
    bool IsAlert();
    bool FUN_005721e0();
    void SetAimingWeapon(bool, bool, bool);
    void SetReloadState(bool);
    void SetLightingNode(NiAVObject*);
    bool IsInIdleState();
    Animation* GetAnimation();
};
class PlayerCharacter : public Actor
{
  public:
    bool IsAlert();
    void SetAimingWeapon(bool, bool, bool);
    NiNode* GetNode(bool);
    bool IsPlayerBipedAnimation(BipedAnim*);
    BipedAnim* GetBipedAnimation(bool);
    Animation* GetAnimation(bool);
};
class ExtraDismemberedLimbs
{
  public:
    bool IsBitSet(int);
};
class InventoryChanges;
class ExtraDataList
{
  public:
    InventoryChanges* GetContainerChangeData();
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
class ModelLoader
{
  public:
    void CallContainedObject();
    void FUN_004aaf10();
    void QueueModelFilePath(const char*, IO_TASK_PRIORITY, QueuedFile*);
    void ProcessModelRequest(TESModel*, IO_TASK_PRIORITY, QueuedFile*, int, bool, bool, bool);
    void QueueFile(const char*, IO_TASK_PRIORITY, QueuedFile*, int, bool, bool, bool);
    void FUN_0045a5e0(const char*);
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
class TES
{
  public:
    NiObject* CreateDeepCopySameTextures(NiObject*, CloningProcess&);
};
class TESSaveLoadGame
{
  public:
    bool GetLoading();
};
class BSFaceGenModel
{
  public:
    bool ApplyFaceGenMorphs(FaceGenCoord (*)[4], NiTriBasedGeom*, bool);
};
class TESFullName
{
  public:
    const char* GetFullName();
};
class TESActorBase
{
  public:
    SEX GetSex() const;
};
class TESRace : public TESForm
{
  public:
    bool GetBipedObjectModelPath(TESNPC*, BIPED_OBJECT, char*);
    void BuildBodyTexturePath(TESNPC*, char*);
    bool BuildBodyModTexturePath(TESNPC*, char*, char*);
    unsigned char raceFields[0x14];
    TESFullName fullName;
    bool GetSkinTextures(NiPointer<NiTexture>&, NiPointer<NiTexture>&, TESNPC*, BIPED_OBJECT, bool);
    TESModel* GetBipedObjectModel(SEX, BIPED_OBJECT);
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class BipedAnimBone
{
  public:
    unsigned char cFlags;
    NiNode* pParent;
};
class BipedAnimObject
{
  public:
    TESForm* pParent;
    TESModel* m_pModel;
    NiAVObject* m_pSceneObject;
    bool bHasAnimation;
};
class BipedAnim
{
  public:
    void QueueBipedParts(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet,
                      QueuedFile* file);  // declared for the original code (decl_variants.py) public:
    NiNode* root;
    BipedAnimBone bone[5];
    BipedAnimObject object[20];
    BipedAnimObject m_kPreviousObjects[20];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
    void ProcessQueuedHelmet(IO_TASK_PRIORITY, NiPointer<QueuedHelmet>&, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, IO_TASK_PRIORITY, QueuedFile*);
    void LoadBipedObject(TESNPC*, BIPED_OBJECT, IO_TASK_PRIORITY, QueuedFile*);
    void RequestModelLoad(IO_TASK_PRIORITY, QueuedFile*, NiPointer<QueuedHelmet>&, BIPED_OBJECT);
    void CompleteModelLoadTask();
    NiNode* GetBoneNode(BIPED_BONE);
    void AttachFaceGenNode();
    void RemoveBipedWeapon();
    void SetBipedVisibility(bool);
    NiAVObject* PrepareBipedModel(NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, BIPED_OBJECT, BSFaceGenModel*);
    void UpdateSkinInstance(NiAVObject*, bool);
    bool IsSlotHidden(BIPED_OBJECT);
    BSFaceGenModel* GetFaceGenModelForSlot(BIPED_OBJECT);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void ClearBipedObject(BipedAnimObject*, bool, TESForm*);
    void QueueItem(IO_TASK_PRIORITY, void*, BIPED_OBJECT);
    static bool CanLoadHiddenBipedObjects();
    static void ApplyReferenceExtraData(NiNode*, NiNode*, BIPED_OBJECT, TESObjectREFR*);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static BIPED_OBJECT GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* GetModelForSlot(BIPED_OBJECT, TESModel*);
    TESModel* FUN_004afa20(BIPED_OBJECT, char*);
    void RemovePart(BIPED_OBJECT, bool, TESForm*);
    void RemovePartsByParent(TESForm*);
    void SetBipedObject(TESForm*, TESModel*, BIPED_OBJECT);
    void UpdateRaceSex(TESRace*, SEX);
};
extern PlayerCharacter* g_thePlayer;
extern ModelLoader* g_modelLoader;
extern TES* g_TES;
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern bool DAT_011c5cb4;
extern SettingT<INISettingCollection> DAT_011c5ef0;
extern int DAT_01188be8[20];
extern const char* DAT_01188b98[20];
extern ThreeByThreeMatrix DAT_011a9448;
bool FUN_0043faf0();
void FUN_006570e0(TESBoundObject*);
bool IsObjectProcessable(NiObject*);
bool UpdateObjectVisibility(NiAVObject*);
int __cdecl Warning(const char*, ...);
void AddNodeEntries(int, NiAVObject*);
class DialogMenuInterfaceCalls
{
  public:
    static void SetHUDVisible(bool);
};
class Interface
{
  public:
    static void SetHUDVisible(bool);
    static void ClearGunScope();
    static void InitGunScope(TESModel*);
};
extern "C" void* __cdecl memset(void*, int, unsigned int);

template <class T> class NiTNewInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* data;
    unsigned short capacity, size, count, grow;
    NiTArray(unsigned short, unsigned short);
    unsigned int Add(const T&);
};
class TileWorkList
{
  public:
    void FUN_004700d0(NiAVObject* const&);
};
class NiExtraData
{
  public:
    bool FUN_00448a40();
    unsigned char prefix[0x34];
    TileWorkList children;
};
class NiSkinData : public NiObject
{
  public:
    unsigned int GetBoneCount();
};
class NiSkinPartition : public NiObject
{
};
class NiSkinInstance : public NiObject
{
  public:
    NiSkinData* GetSkinData();
    NiSkinData* GetData();
    NiAVObject** GetBones();
    NiSkinPartition* GetSkinPartition();
    void FUN_004addc0(NiSkinPartition*);
    void SetRootParent(NiNode*);
    void SetBone(unsigned int, NiAVObject*);
};
const NiFixedString& FUN_004ab220();
NiAVObject* FUN_004ade00(NiNode*, const NiFixedString&);
void FUN_004add50(char*, const char*, unsigned int);
int FUN_00404dc0(const char*, const char*);
extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
template <class T> unsigned int BSStringLength(const T*);

class InventoryChanges
{
  public:
    InventoryStackRecord* GetInventoryEntryData(BIPED_OBJECT, bool);
};
class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
class ShadowSceneNode
{
  public:
    void RemoveObject(NiAVObject*);
    void AddObject(NiAVObject*);
};
ShadowSceneNode* FUN_00450b80(int);
void FUN_00572220(bool);
int FUN_00408b20(const char*, const char*);
class VATS
{
};
extern VATS DAT_011f2250;
class TESDataHandler
{
  public:
    bool FUN_004226e0();
};
extern TESDataHandler* g_dataHandler;
class BGSListForm;
class BGSBipedModelList
{
  public:
    static BGSBipedModelList* GetBipedModelList(TESForm*);
    BGSListForm* GetList();
};

class NiStringExtraData : public NiExtraData
{
  public:
    const NiFixedString& GetString();
};
struct NiRTTI
{
};
class SkyShaderProperty;
extern NiRTTI DAT_011f4a38, DAT_011f9140, DAT_011f444c;
SkyShaderProperty* FUN_00653270(const NiRTTI*, NiProperty*);
const NiFixedString& FUN_004ae780();
class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeom;
    bool updateBounds;
    bool sceneGraphChange;
    NiUpdateData(float, bool, bool);
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
class bhkShape
{
};
class bhkFilter
{
  public:
    unsigned int value;
    int FUN_0043b4d0();
};
class bhkWorldObject
{
  public:
    bhkShape* FUN_004ae6a0();
    bhkFilter FUN_0043b4f0();
};
class bhkCollisionObject
{
  public:
    static bhkCollisionObject* GetFromNiAVObject(NiAVObject*);
    bhkWorldObject* FUN_006fa820();
};
bool HandleUnparentedObjectNode(NiNode*);
void SetCollisionRefFlag(NiNode*, bool);
void FUN_00c6a2e0(NiNode*, bool, bool);
void FUN_00c6a350(NiNode*, int, bool, bool, bool);
class NiTexture : public NiObject
{
};
class NiSourceTexture : public NiTexture
{
  public:
    bool FUN_004af860();
    void FUN_004af880();
    const NiFixedString& GetFilename();
};
class BSShaderPPLightingProperty
{
  public:
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
    virtual void vfn_b8();
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
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void SetTexture(int, NiTexture*);
    virtual void SetNormalTexture(int, NiTexture*);
    bool FUN_004a2020(int);
    bool GetFlag(int);
    int GetType();
    void SetFlag(int, bool);
};
const char* FUN_00464f30(const char*, bool);
extern const char* DAT_01199e8c[2];
void FUN_00b4f5e0(char*, const char*, const char*, bool);
void FUN_00b55840(const char*, bool, NiPointer<NiTexture>&, bool, bool);
NiTexture* FUN_004af8a0();
class TESBipedModelForm
{
  public:
    virtual void vfn_0();
    unsigned int m_uiBipedModelFlags;
    unsigned char m_ucBipedModelData;
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    static TESBipedModelForm* GetFormAsBipedModel(TESForm*);
    bool HasBipedModel(BIPED_OBJECT, bool, BGSBipedModelList*);
    const char* FUN_00480ce0();
};
extern int DAT_01188b88[3];
extern const char* DAT_01188c38[5];
extern TESModel DAT_011c5d10[20];
extern SettingT<INISettingCollection> DAT_011d5a10, DAT_011d5a44;
bool FUN_004910d0(NiNode*);
unsigned int FUN_004af350();
int FUN_004af340();
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
char* FUN_0040ab30(char*, int);
int strcat_s(char*, unsigned int, const char*);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_MISSING = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
extern ActorTaskManager DAT_011c5cf0;
const NiFixedString& FUN_00448a80();
void FUN_00577e20(NiNode*);
struct BipedSkinNameMatch
{
    const char* name;
    BIPED_OBJECT slot;
};
struct BipedRenderProperties
{
    NiProperty* material;
    NiProperty* alpha;
    BSShaderPPLightingProperty* shader;
};
struct BipedAttachmentTarget
{
    NiExtraData* metadata;
    NiNode* parent;
};
class TESTopic;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList<T>* GetNext();
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class NiTimeController
{
  public:
    int FUN_00441110();
};
class BSShaderManager
{
  public:
    static void BuildTexturePath(char*, const char*, const char*, bool);
};
extern "C" const char kMeshesFolder[];
class Animation
{
  public:
    static bool RemoveKeyframeControllers(NiAVObject*);
};
struct BipedWeaponEntry
{
    float value;
    TESObjectWEAP* weapon;
    InventoryStackRecord* entry;
};
struct BipedModelClone
{
    NiNode* model;
    NiObject* copy;
    NiNode* pNode;
};
struct BipedSkinAttachment
{
    NiNode* attachNode;
    BSFaceGenModel* face;
};
struct BipedSkinBoneMetadata
{
    NiExtraData* extra;
    NiExtraData* bones;
};
struct BipedSkinnedChild
{
    NiTriBasedGeom* geom;
    NiAVObject* child;
    NiSkinInstance* skin;
};
struct BipedSkinBoneBinding
{
    NiAVObject** boneArray;
    unsigned int count;
    NiAVObject* pBone;
};
#endif

struct BipedWeaponOwner
{
    BipedAnim* biped;
    Actor* actor;
    BaseProcess* process;
};
struct BipedEquippedWeapon
{
    TESObjectWEAP* weapon;
    InventoryChanges* changes;
};
struct BipedWeaponSearch
{
    NiNode* search;
    NiNode* found;
    NiNode* root;
};

struct BipedGeometryChild
{
    NiTriBasedGeom* geometry;
    NiAVObject* child;
};

class TESQuest;
class TESHairRaceResult;
class BGSPerkEntry;
class BGSQuestObjective
{
  public:
    void SetOwnerQuest(TESQuest*);
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class TESHairCanBeNPCData
{
  public:
    TESHairRaceResult* FUN_004ac110();
};
class TESSpellList
{
  public:
    BSSimpleList<InventoryStackRecord*>* GetOffsetC();
};

// These object and string getters are identical folded functions in the PC executable.
#define BIPED_OBJECT_NAME(object) (*(const NiFixedString*)((TESTopicInfoData*)(object))->GetLinkToList())
#define BIPED_STRING_TEXT(value) ((const char*)((BSFadeNode*)&(value))->FUN_0043b1b0())
#define BIPED_OBJECT_TEXT(object) BIPED_STRING_TEXT(BIPED_OBJECT_NAME(object))
#define BIPED_EXTRA_STRING(extra) (*(const NiFixedString*)((TESSpellList*)(extra))->GetOffsetC())

struct BipedSkinTextureTarget
{
    TESNPC* npc;
    BIPED_OBJECT slot;
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d5a10, g_011d5a44;
class GlobalObject_0044fae0
{
};
extern GlobalObject_0044fae0 g_011c5cf0;
// The canonical initializer name denotes the same 16-byte child array.
class GlobalObject_004aff00
{
  public:
    void* vtable;
    NiPointer<NiAVObject>* data;
    unsigned short capacity, size, count, grow;
    GlobalObject_004aff00(int, int);
    ~GlobalObject_004aff00();
};

typedef NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > BipedChildArray;

// Canonical RTTI alias bound to the NPC descriptor used by this cast.
class TESFaction : public TESForm
{
};

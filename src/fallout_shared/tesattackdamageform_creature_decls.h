// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESATTACKDAMAGEFORM_CREATURE_DECLS_H
#define FNV_TESATTACKDAMAGEFORM_CREATURE_DECLS_H

#include "layout_support.h"
class ActorBaseAttributes;
class PackedRecordData;
class BGSBodyPartData;
class BGSDestructibleObjectForm;
class BGSImpactDataSet;
class BGSTouchSpellForm;
class BGSVoiceType;
class BSFileEntry;
class TypedData;
class InventoryItemEntry;
class CreatureSoundCollection;
class CollisionComponent;
class FactionReaction;
class MagicItemForm;
class ShortPoint3;
class PackageList;
class TESAIForm;
class TESActorBaseData;
class TESAnimation;
class TESAttackDamageForm;
class TESLevItem;
class TESPackage;
class SpellItem;
class BGSListForm;
class BGSBodyPartData;
class TESCombatStyle;
class TESAttributes;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESCombatStyle;
class TESContainer;
class TESCreature;
class TESLevSpell;
class TESModel;
class TESModelList;
class TESFormList;
class TESSpellList;
class FileEntryList;
class FileEntryListCollection;
enum BGSImpactDataSet__IMPACT_MATERIAL_TYPE
{
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_STONE = 0,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_DIRT = 1,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GRASS = 2,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GLASS = 3,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_METAL = 4,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WOOD = 5,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC = 6,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_CLOTH = 7,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WATER = 8,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_HOLLOW_METAL = 9,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_BUG = 10,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_GLOW = 11,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_COUNT = 12
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

class TESForm : public BaseFormComponent
{
  public:
    virtual void Destroy(bool);
    virtual void SetToDefault();
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
    virtual BGSBodyPartData* GetBodyPartData();
    virtual void SetBodyPartData(BGSBodyPartData*);
    virtual TESCombatStyle* GetCombatStyle();
    virtual void SetCombatStyle(TESCombatStyle*);
    unsigned char formType;
    unsigned char formPadding[3];
    unsigned int formFlags;
    unsigned int formID;
    BSSimpleList<TESFile*> sourceFiles;
    ENUM_FORM_ID GetFormType() const;
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    void BaseFormRecord(BaseFormComponent*);
};
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;
    void BaseFormRecord(BaseFormComponent*);
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    void* pScript;
    bool bScriptResolved;
    unsigned char layoutPadding9[3];
    void BaseFormRecord(BaseFormComponent*);
};
class ActorValueOwner
{
  public:
    virtual void vfn_0();
};
class CreatureSoundCollection
{
  public:
    void Copy(CreatureSoundCollection*);
};
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
#pragma pack(push, 4)
class TESBoundAnimObject : public TESBoundObject
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 48);
#pragma pack(push, 4)
class ActorBaseAttributes
{
  public:
    int m_uiActorFlags;          // +0x0, 4 bytes
    unsigned short m_usField04;  // +0x4, 2 bytes
    unsigned short m_usField06;  // +0x6, 2 bytes
    unsigned short sLevel;       // +0x8, 2 bytes
    unsigned short m_usField0A;  // +0xA, 2 bytes
    unsigned short m_usField0C;  // +0xC, 2 bytes
    unsigned short m_usField0E;  // +0xE, 2 bytes
    float m_fField10;            // +0x10, 4 bytes
    unsigned short m_usField14;  // +0x14, 2 bytes
    unsigned short m_usField16;  // +0x16, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorBaseAttributes) == 24);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_uiActorFlags) == 0);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField04) == 4);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField06) == 6);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, sLevel) == 8);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0A) == 10);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0C) == 12);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0E) == 14);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_fField10) == 16);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField14) == 20);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField16) == 22);
#pragma pack(push, 4)
class TESActorBase;
class TESActorBaseData : public BaseFormComponent
{
  public:
    enum TEMPLATE_USE_FLAG
    {
        USE_TRAITS = 0,
        USE_STATS = 1,
        USE_FACTIONS = 2,
        USE_SPELLS = 3,
        USE_AI_DATA = 4,
        USE_AI_PACKAGES = 5,
        USE_MODEL = 6,
        USE_BASE_DATA = 7,
        USE_INVENTORY = 8,
        USE_SCRIPT = 9
    };
    virtual void CopyFromTemplateForm(TESActorBase*);
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
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();

    bool IsTemplateLeveled();
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    bool GetTemplateUseFlag(TEMPLATE_USE_FLAG);
    void SetTemplateUseFlags(unsigned short);
    void CopyFactionList(TESActorBaseData*);
    void SetFlags(int);
    void FUN_0050f9a0(TESLevItem*);  // SetDeathItem (inferred from field access)
    void SetKarmaValue(float);
    unsigned short GetLevel();
    unsigned short FUN_0047d390();  // GetCalcLevelMin (inferred from field access)
    unsigned short FUN_0047d3b0();  // GetCalcLevelMax (inferred from field access)
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    void SetLevel(unsigned short);
    void SetCalcLevelMin(unsigned short);
    void SetCalcLevelMax(unsigned short);
    unsigned short GetShortAtOffset12();  // GetSpeedMult (inferred from field access)
    void SetSpeedMult(unsigned short);
    void SetFatigue(unsigned short);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short&);

    ActorBaseAttributes actorData;             // +0x4, 24 bytes
    TESLevItem* m_pBaseTemplateForm;           // +0x1C, 4 bytes
    BGSVoiceType* m_kFactionList;              // +0x20, 4 bytes
    TESForm* m_ppTemplateForms;                // +0x24, 4 bytes
    int m_pDeathItem;                          // +0x28, 4 bytes
    BSSimpleList<FactionReaction*> m_pVoiceType;  // +0x2C, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESActorBaseData) == 52);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, actorData) == 4);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pBaseTemplateForm) == 28);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_kFactionList) == 32);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_ppTemplateForms) == 36);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pDeathItem) == 40);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pVoiceType) == 44);
#pragma pack(push, 4)
class TESContainer : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<InventoryItemEntry*> objectList;  // +0x4, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESContainer) == 12);
FNV_STATIC_ASSERT(offsetof(TESContainer, objectList) == 4);
#pragma pack(push, 4)
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    MagicItemForm* m_pMagicItem;        // +0x4, 4 bytes
    unsigned short m_usTouchSpellType;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSTouchSpellForm) == 12);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_pMagicItem) == 4);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_usTouchSpellType) == 8);
#pragma pack(push, 4)
class TESSpellList : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<SpellItem*> spellList;           // +0x4, 8 bytes
    BSSimpleList<TESLevSpell*> leveledSpellList;  // +0xC, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSpellList) == 20);
FNV_STATIC_ASSERT(offsetof(TESSpellList, spellList) == 4);
FNV_STATIC_ASSERT(offsetof(TESSpellList, leveledSpellList) == 12);
#pragma pack(push, 4)
class PackedRecordData
{
  public:
    unsigned char m_ucField00;  // +0x0, 1 bytes
    unsigned char m_ucField01;  // +0x1, 1 bytes
    unsigned char m_ucField02;  // +0x2, 1 bytes
    unsigned char m_ucField03;  // +0x3, 1 bytes
    unsigned char m_ucField04;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    unsigned int m_uiField08;   // +0x8, 4 bytes
    unsigned char m_ucField0C;  // +0xC, 1 bytes
    unsigned char m_ucField0D;  // +0xD, 1 bytes
    unsigned char m_ucField0E;  // +0xE, 1 bytes
    bool m_bField0F;            // +0xF, 1 bytes
    unsigned int m_uiField10;   // +0x10, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedRecordData) == 20);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField00) == 0);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField01) == 1);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField02) == 2);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField03) == 3);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField04) == 4);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField08) == 8);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0C) == 12);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0D) == 13);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0E) == 14);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_bField0F) == 15);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField10) == 16);
#pragma pack(push, 4)
class PackageList
{
  public:
    BSSimpleList<TESPackage*> m_kPackages;  // +0x0, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageList) == 8);
FNV_STATIC_ASSERT(offsetof(PackageList, m_kPackages) == 0);
#pragma pack(push, 4)
class TESAIForm : public BaseFormComponent
{
  public:
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(TESAIForm*);
    PackedRecordData m_kAIData;  // +0x4, 20 bytes
    PackageList m_kPackageList;  // +0x18, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAIForm) == 32);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kAIData) == 4);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kPackageList) == 24);
#pragma pack(push, 4)
class TESAttributes : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 12);
FNV_STATIC_ASSERT(offsetof(TESAttributes, cAttribute) == 4);
#pragma pack(push, 4)
class TESAnimation : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<const char*> m_kKFFileList;  // +0x4, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAnimation) == 12);
FNV_STATIC_ASSERT(offsetof(TESAnimation, m_kKFFileList) == 4);
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    CollisionComponent* pData;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESActorBase) == 268);
#pragma pack(push, 4)
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    void InitializeComponent();
    virtual void Free();
    virtual unsigned short GetAttackDamage();
    void BaseFormRecord(BaseFormComponent*);
    unsigned short m_usAttackDamage;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttackDamageForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESAttackDamageForm, m_usAttackDamage) == 4);
#pragma pack(push, 4)
class FileEntryListCollection
{
  public:
    unsigned int m_uiFileEntryCount;    // +0x0, 4 bytes
    FileEntryList** m_ppElementArray;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryListCollection) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryListCollection, m_uiFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryListCollection, m_ppElementArray) == 4);
#pragma pack(push, 4)
class TESModelList : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<const char*> m_kModelPaths;  // +0x4, 8 bytes
    FileEntryListCollection m_kModelData;     // +0xC, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelList) == 20);
FNV_STATIC_ASSERT(offsetof(TESModelList, m_kModelPaths) == 4);
FNV_STATIC_ASSERT(offsetof(TESModelList, m_kModelData) == 12);
#pragma pack(push, 4)
class TypedData
{
  public:
    char eType;                            // +0x0, 1 bytes
    unsigned char m_ucFirstByteAfterType;  // +0x1, 1 bytes
    unsigned char iOtherSignFlags;         // +0x2, 1 bytes
    unsigned char m_ucPayloadByte3;        // +0x3, 1 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TypedData) == 4);
FNV_STATIC_ASSERT(offsetof(TypedData, eType) == 0);
FNV_STATIC_ASSERT(offsetof(TypedData, m_ucFirstByteAfterType) == 1);
FNV_STATIC_ASSERT(offsetof(TypedData, iOtherSignFlags) == 2);
FNV_STATIC_ASSERT(offsetof(TypedData, m_ucPayloadByte3) == 3);
#pragma pack(push, 4)
class TESCreature : public TESActorBase, public TESAttackDamageForm, public TESModelList
{
  public:
    TESCreature();
    ~TESCreature();
    virtual void CopyFromTemplateForm(TESActorBase*);
    void SetCombatStyle(TESCombatStyle*);
    void CopyBoundData(TESCreature*);           // CopyBounds (inferred from field access)
    BGSImpactDataSet* GetImpactDataSet();      // GetImpactDataSet (inferred from field access)
    void SetImpactDataSet(BGSImpactDataSet*);  // SetImpactDataSet (inferred from field access)
    CreatureSoundCollection* GetCreatureSounds();
    CreatureSoundCollection* GetMutableCreatureSounds();
    TESCreature* GetSoundCreature();
    void SetCreatureSoundsFrom(TESCreature*);
    SOUND_LEVEL FUN_009c0070();        // GetSoundLevel (inferred from field access)
    unsigned char FUN_0059f3a0();      // GetCreatureType (inferred from field access)
    void FUN_005fbdb0(unsigned char);  // SetCreatureType (inferred from field access)
    BGSListForm* GetField158();        // GetWeaponList (inferred from field access)
    void FUN_005f8bd0(BGSListForm*);   // SetWeaponList (inferred from field access)
    unsigned char GetCombatSkill();
    void SetByteAt12D(unsigned char);     // SetCombatSkill (inferred from field access)
    unsigned char FUN_005f9ad0();         // GetHandReach (inferred from field access)
    void SetCreatureType(unsigned char);  // SetHandReach (inferred from field access)
    float FUN_00821640();                 // GetTurnSpeed (inferred from field access)
    void FUN_00507780(float);             // SetTurnSpeed (inferred from field access)
    float FUN_00567470();                 // GetBaseScale (inferred from field access)
    void SetBoltGrowWidth(float);         // SetBaseScale (inferred from field access)
    float FUN_00821660();                 // GetFootWeight (inferred from field access)
    void SetBoltSmallWidth(float);        // SetFootWeight (inferred from field access)

    union
    {                                                // overlapping CodeView storage
        TESCreature* m_pCreature;                    // +0x128, 4 bytes
        CreatureSoundCollection* m_pCreatureSounds;  // +0x128, 4 bytes
    };
    TypedData Data;                  // +0x12C, 4 bytes
    unsigned char m_ucCreatureType;  // +0x130, 1 bytes
    unsigned char layoutPadding131[3];
    float m_fFirstCreatureStat;                                // +0x134, 4 bytes
    float m_fSecondCreatureStat;                               // +0x138, 4 bytes
    float m_fThirdCreatureStatCur;                             // +0x13C, 4 bytes
    TESCombatStyle* m_pCombatStyle;                            // +0x140, 4 bytes
    BGSBodyPartData* m_pBodyPartDataCur;                       // +0x144, 4 bytes
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE m_eImpactMaterial;  // +0x148, 4 bytes
    BGSImpactDataSet* m_pImpactDataSet;                        // +0x14C, 4 bytes
    bool m_bHasImpactDataSet;                                  // +0x150, 1 bytes
    unsigned char layoutPadding151[3];
    SOUND_LEVEL m_eSoundLevel;         // +0x154, 4 bytes
    BGSListForm* m_pCreatureListForm;  // +0x158, 4 bytes
    char m_cCreatureDataFlag;          // +0x15C, 1 bytes
    unsigned char layoutPadding15D[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCreature) == 352);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pCreature) == 296);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pCreatureSounds) == 296);
FNV_STATIC_ASSERT(offsetof(TESCreature, Data) == 300);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_ucCreatureType) == 304);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_fFirstCreatureStat) == 308);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_fSecondCreatureStat) == 312);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_fThirdCreatureStatCur) == 316);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pCombatStyle) == 320);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pBodyPartDataCur) == 324);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_eImpactMaterial) == 328);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pImpactDataSet) == 332);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_bHasImpactDataSet) == 336);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_eSoundLevel) == 340);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_pCreatureListForm) == 344);
FNV_STATIC_ASSERT(offsetof(TESCreature, m_cCreatureDataFlag) == 348);
// The linker folded these tiny accessors with the canonical identities below.
// Keep those existing decorated names when accessing actor-template storage.
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class NiTimeController
{
  public:
    int FUN_00441110();
};
class PerkEntryConditionSet;
class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class TESIdleForm;
class TESResponse
{
  public:
    void SetSpeakerIdle(TESIdleForm*);
    void GetListenerIdle(TESIdleForm*);
};
TESCombatStyle* GetDefaultCombatStyle();
#endif

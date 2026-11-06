// fallout_shared/tesdatahandler_forms.h: declares TESForm, NiMemObject, TESFullName, BGSDestructibleObjectForm, TESProduceForm and more
#ifndef FNV_TESDATAHANDLER_FORMS_H
#define FNV_TESDATAHANDLER_FORMS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiNode;
class TESFile;
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NONE = 0
};
class TESForm
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(TESForm*);
    virtual bool CompareWithBase(TESForm*);
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool LoadForm(TESFile*);
    virtual void vfn_24(TESFile*);
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
    virtual void InitItem();
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
    virtual void SetAltered(bool);
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
    virtual bool vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void SetRefID(unsigned int, bool);
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    virtual bool SetEditorID_AtRuntime(const char*);
    unsigned char formType;
    unsigned int flags;
    unsigned int formID;
    void* sourceFiles[2];
    unsigned int GetFormID();
    const char* FUN_00440e30();
    void SetFile(TESFile*);
    void FUN_00483870();
    void ClearFormData();
    void SetMasterFile(bool);
    bool IsDeleted() const;
    void SetFormType(ENUM_FORM_ID);
    bool FUN_00460250();
    ENUM_FORM_ID GetFormType() const;
    void SetInitializationState(bool);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class TESFullName
{
  public:
    virtual ~TESFullName();
    void SetFullName(const char*);
    const char* GetFullName();
    char* fullName;
    unsigned short length, capacity;
};
class BGSDestructibleObjectForm
{
  public:
    virtual ~BGSDestructibleObjectForm();
    void* data;
};
class TESProduceForm
{
  public:
    virtual ~TESProduceForm();
    void* ingredient;
    unsigned char chance[4];
};
class TESSound;

class TESObject : public TESForm
{
  public:
    void* parentList;
    TESObject* prev;
    TESObject* next;
    TESObject* GetNext();
    bool GetScroll();
};
class TESBoundObject : public TESObject
{
  public:
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
    short bounds[6];
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
    virtual void SetModelFilePath(const char*);
    char* model;
    unsigned char data[16];
};
class TESReactionForm
{
  public:
    virtual void vfn_0();
    void SetReactionValue(TESForm*, int);
    unsigned char data[8];
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    void AddHead(T&);
    T& GetItem();
    void Remove(T const&);
    BSSimpleList* GetNext();
    void AddTail(T&);
    int GetSize();
    void SetItem(T&);
    bool IsEmpty();
    void RemoveHead();
};
class TESFormInitFlag
{
  public:
    static TESForm* LookupFormByEditorID(const char*);
    static TESForm* GetFormByID(unsigned int);
};
class TESFormList
{
  public:
    TESObject* AddToObjectList(TESObject*);
    TESObject* GetFirst();
};

class TESObjectACTI : public TESBoundObject
{
  public:
    TESObjectACTI();
    TESFullName fullName;
    unsigned char layout_3c[0x54];
};
typedef char check_TESObjectACTI_size[(sizeof(TESObjectACTI) == 0x90) ? 1 : -1];
class BGSTalkingActivator : public TESBoundObject
{
  public:
    BGSTalkingActivator();
    unsigned char formData[0x68];
};
typedef char check_BGSTalkingActivator_size[(sizeof(BGSTalkingActivator) == 0x98) ? 1 : -1];
class BGSTerminal : public TESBoundObject
{
  public:
    BGSTerminal();
    unsigned char formData[0x78];
};
typedef char check_BGSTerminal_size[(sizeof(BGSTerminal) == 0xa8) ? 1 : -1];
class TESObjectARMO : public TESBoundObject
{
  public:
    TESObjectARMO();
    unsigned char formData[0x160];
};
typedef char check_TESObjectARMO_size[(sizeof(TESObjectARMO) == 0x190) ? 1 : -1];
class TESObjectARMA : public TESBoundObject
{
  public:
    TESObjectARMA();
    unsigned char formData[0x160];
};
typedef char check_TESObjectARMA_size[(sizeof(TESObjectARMA) == 0x190) ? 1 : -1];
class TESObjectBOOK : public TESBoundObject
{
  public:
    TESObjectBOOK();
    unsigned char formData[0x94];
};
typedef char check_TESObjectBOOK_size[(sizeof(TESObjectBOOK) == 0xc4) ? 1 : -1];
class TESObjectCLOT : public TESBoundObject
{
  public:
    TESObjectCLOT();
    unsigned char formData[0x124];
};
typedef char check_TESObjectCLOT_size[(sizeof(TESObjectCLOT) == 0x154) ? 1 : -1];
class TESObjectCONT : public TESBoundObject
{
  public:
    TESObjectCONT();
    unsigned char layout_30[0x18];
    TESModel model;
    unsigned char layout_60[0x3c];
};
typedef char check_TESObjectCONT_size[(sizeof(TESObjectCONT) == 0x9c) ? 1 : -1];
class TESObjectDOOR : public TESBoundObject
{
  public:
    TESObjectDOOR();
    unsigned char layout_30[0xc];
    TESModel model;
    unsigned char layout_54[0x3c];
};
typedef char check_TESObjectDOOR_size[(sizeof(TESObjectDOOR) == 0x90) ? 1 : -1];
class IngredientItem : public TESBoundObject
{
  public:
    IngredientItem();
    unsigned char formData[0x74];
};
typedef char check_IngredientItem_size[(sizeof(IngredientItem) == 0xa4) ? 1 : -1];
class TESObjectLIGH : public TESBoundObject
{
  public:
    TESObjectLIGH();
    unsigned char formData[0x98];
};
typedef char check_TESObjectLIGH_size[(sizeof(TESObjectLIGH) == 0xc8) ? 1 : -1];
class TESObjectMISC : public TESBoundObject
{
  public:
    TESObjectMISC();
    unsigned char formData[0x7c];
};
typedef char check_TESObjectMISC_size[(sizeof(TESObjectMISC) == 0xac) ? 1 : -1];
class TESObjectIMOD : public TESBoundObject
{
  public:
    TESObjectIMOD();
    unsigned char formData[0x80];
};
typedef char check_TESObjectIMOD_size[(sizeof(TESObjectIMOD) == 0xb0) ? 1 : -1];
class BGSConstructibleObject : public TESBoundObject
{
  public:
    BGSConstructibleObject();
    unsigned char formData[0x84];
};
typedef char check_BGSConstructibleObject_size[(sizeof(BGSConstructibleObject) == 0xb4) ? 1 : -1];
class TESKey : public TESBoundObject
{
  public:
    TESKey();
    unsigned char formData[0x7c];
};
typedef char check_TESKey_size[(sizeof(TESKey) == 0xac) ? 1 : -1];
class TESObjectSTAT : public TESBoundObject
{
  public:
    TESObjectSTAT();
    TESModel model;
    unsigned char layout_48[0x10];
};
typedef char check_TESObjectSTAT_size[(sizeof(TESObjectSTAT) == 0x58) ? 1 : -1];
class BGSStaticCollection : public TESBoundObject
{
  public:
    BGSStaticCollection();
    unsigned char formData[0x20];
};
typedef char check_BGSStaticCollection_size[(sizeof(BGSStaticCollection) == 0x50) ? 1 : -1];
class BGSPlaceableWater : public TESBoundObject
{
  public:
    BGSPlaceableWater();
    unsigned char formData[0x20];
};
typedef char check_BGSPlaceableWater_size[(sizeof(BGSPlaceableWater) == 0x50) ? 1 : -1];
class TESGrass : public TESBoundObject
{
  public:
    TESGrass();
    unsigned char formData[0x38];
};
typedef char check_TESGrass_size[(sizeof(TESGrass) == 0x68) ? 1 : -1];
class TESIdleForm : public TESForm
{
  public:
    TESIdleForm();
    unsigned char formData[0x3c];
};
typedef char check_TESIdleForm_size[(sizeof(TESIdleForm) == 0x54) ? 1 : -1];
class BGSCameraPath : public TESForm
{
  public:
    BGSCameraPath();
    unsigned char formData[0x20];
};
typedef char check_BGSCameraPath_size[(sizeof(BGSCameraPath) == 0x38) ? 1 : -1];
class BGSIdleMarker : public TESBoundObject
{
  public:
    BGSIdleMarker();
    unsigned char formData[0x10];
};
typedef char check_BGSIdleMarker_size[(sizeof(BGSIdleMarker) == 0x40) ? 1 : -1];
class TESPackage : public TESForm
{
  public:
    TESPackage();
    unsigned char formData[0x68];
};
typedef char check_TESPackage_size[(sizeof(TESPackage) == 0x80) ? 1 : -1];
class TESObjectTREE : public TESBoundObject
{
  public:
    TESObjectTREE();
    unsigned char formData[0x64];
};
typedef char check_TESObjectTREE_size[(sizeof(TESObjectTREE) == 0x94) ? 1 : -1];
class TESFurniture : public TESBoundObject
{
  public:
    TESFurniture();
    unsigned char formData[0x64];
};
typedef char check_TESFurniture_size[(sizeof(TESFurniture) == 0x94) ? 1 : -1];
class TESObjectWEAP : public TESBoundObject
{
  public:
    TESObjectWEAP();
    TESFullName fullName;
    unsigned char layout_3c[0x34c];
    void SetByteAtOffsetF4(int);
};
typedef char check_TESObjectWEAP_size[(sizeof(TESObjectWEAP) == 0x388) ? 1 : -1];
class TESAmmo : public TESBoundObject
{
  public:
    TESAmmo();
    unsigned char formData[0xac];
};
typedef char check_TESAmmo_size[(sizeof(TESAmmo) == 0xdc) ? 1 : -1];
class ActorBaseData
{
  public:
    bool FUN_00461560();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10(bool);
};
class TESNPC : public TESBoundObject, public ActorBaseData
{
  public:
    TESNPC();
    void AutoCalcStats(bool);
    unsigned char formData[0x1d8];
};
typedef char check_TESNPC_size[(sizeof(TESNPC) == 0x20c) ? 1 : -1];
class TESCreature : public TESBoundObject, public ActorBaseData
{
  public:
    TESCreature();
    unsigned char formData[0x12c];
};
typedef char check_TESCreature_size[(sizeof(TESCreature) == 0x160) ? 1 : -1];
class TESLevCreature : public TESBoundObject
{
  public:
    TESLevCreature();
    unsigned char formData[0x40];
};
typedef char check_TESLevCreature_size[(sizeof(TESLevCreature) == 0x70) ? 1 : -1];
class TESLevCharacter : public TESBoundObject
{
  public:
    TESLevCharacter();
    unsigned char formData[0x40];
};
typedef char check_TESLevCharacter_size[(sizeof(TESLevCharacter) == 0x70) ? 1 : -1];
class SpellItem : public TESForm
{
  public:
    SpellItem();
    unsigned char formData[0x2c];
};
typedef char check_SpellItem_size[(sizeof(SpellItem) == 0x44) ? 1 : -1];
class EffectItemList
{
  public:
    bool HasNonDetrimentalEffectWithFlag(unsigned int);
    unsigned char data[0x10];
};
class TESBipedModelForm
{
  public:
    virtual ~TESBipedModelForm();
    bool FUN_0047c850();
};
class EnchantmentItem : public TESForm
{
  public:
    EnchantmentItem();
    bool IsValidObject(TESForm*);
    unsigned int GetEnchantmentType();
    unsigned char magicData[0xc];
    EffectItemList effects;
    unsigned int enchantmentType;
    unsigned char enchantmentData[0xc];
};
typedef char check_EnchantmentItem_size[(sizeof(EnchantmentItem) == 0x44) ? 1 : -1];
class AlchemyItem : public TESBoundObject
{
  public:
    AlchemyItem();
    unsigned char formData[0xa8];
};
typedef char check_AlchemyItem_size[(sizeof(AlchemyItem) == 0xd8) ? 1 : -1];
class TESLevItem : public TESBoundObject
{
  public:
    TESLevItem();
    unsigned char formData[0x1c];
};
typedef char check_TESLevItem_size[(sizeof(TESLevItem) == 0x4c) ? 1 : -1];
class TESObjectCELL;
class TESWorldSpace;
class TESObjectLAND;
class NavMeshCollection;
class ExtraDataList;
struct NiPoint3
{
    float x, y, z;
};
class TESObjectREFR : public TESForm
{
  public:
    TESObjectREFR();
    TESBoundObject* GetObjectReference();
    static TESObjectREFR* CreateReference(unsigned char, bool);
    ExtraDataList* GetExtraData();
    int GetReferenceType();
    bool GetReferencePersistence();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    TESObjectCELL* GetParentCell();
    bool IsPersistentFlagSet();
    void SetPersistentFlag(bool);
    bool FUN_00564e00();
    void FUN_00564eb0(bool);
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
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void Set3D(NiNode*, bool);
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPosition();
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
    virtual void SetParentCell(TESObjectCELL*);
    struct ParentCellData
    {
        virtual TESObjectCELL* GetContainingCell();
        unsigned char data[0x18];
    } parentCellData;
    unsigned char formData[0x34];
};
typedef char check_TESObjectREFR_size[(sizeof(TESObjectREFR) == 0x68) ? 1 : -1];
class BGSNote : public TESBoundObject
{
  public:
    BGSNote();
    unsigned char formData[0x50];
};
typedef char check_BGSNote_size[(sizeof(BGSNote) == 0x80) ? 1 : -1];
class BGSMenuIcon : public TESForm
{
  public:
    BGSMenuIcon();
    unsigned char formData[0xc];
};
typedef char check_BGSMenuIcon_size[(sizeof(BGSMenuIcon) == 0x24) ? 1 : -1];
class BGSListForm : public TESForm
{
  public:
    BGSListForm();
    unsigned char formData[0xc];
};
typedef char check_BGSListForm_size[(sizeof(BGSListForm) == 0x24) ? 1 : -1];
class BGSHeadPart : public TESForm
{
  public:
    BGSHeadPart();
    unsigned char formData[0x38];
};
typedef char check_BGSHeadPart_size[(sizeof(BGSHeadPart) == 0x50) ? 1 : -1];
class TESHair : public TESForm
{
  public:
    TESHair();
    unsigned char formData[0x34];
};
typedef char check_TESHair_size[(sizeof(TESHair) == 0x4c) ? 1 : -1];
class TESEyes : public TESForm
{
  public:
    TESEyes();
    TESFullName fullName;
    unsigned char layout_24[0x10];
};
typedef char check_TESEyes_size[(sizeof(TESEyes) == 0x34) ? 1 : -1];
class TESRace : public TESForm
{
  public:
    TESRace();
    TESFullName fullName;
    unsigned char formData[0x500];
};
typedef char check_TESRace_size[(sizeof(TESRace) == 0x524) ? 1 : -1];
class BGSEncounterZone : public TESForm
{
  public:
    BGSEncounterZone();
    static void CreateDefaultEncounterZone();
    unsigned char formData[0x18];
};
typedef char check_BGSEncounterZone_size[(sizeof(BGSEncounterZone) == 0x30) ? 1 : -1];
class TESClass : public TESForm
{
  public:
    TESClass();
    TESFullName fullName;
    unsigned char formData[0x3c];
};
typedef char check_TESClass_size[(sizeof(TESClass) == 0x60) ? 1 : -1];
// Keep the verified faction RTTI identity separate from the conflicting shared binding.
namespace TESDataHandlerTypes {
class TESFaction : public TESForm
{
  public:
    TESFaction();
    unsigned char layout_18[0xc];
    TESReactionForm reaction;
    unsigned char layout_30[0x1c];
    int InitializeFaction();
};
}
using TESDataHandlerTypes::TESFaction;
typedef char check_TESFaction_size[(sizeof(TESFaction) == 0x4c) ? 1 : -1];
class TESReputation : public TESForm
{
  public:
    TESReputation();
    unsigned char formData[0x38];
};
typedef char check_TESReputation_size[(sizeof(TESReputation) == 0x50) ? 1 : -1];
class TESChallenge : public TESForm
{
  public:
    TESChallenge();
    unsigned char formData[0x64];
};
typedef char check_TESChallenge_size[(sizeof(TESChallenge) == 0x7c) ? 1 : -1];
class TESSound : public TESForm
{
  public:
    TESSound();
    static void InitializeMagicSystem();
    unsigned char formData[0x54];
};
typedef char check_TESSound_size[(sizeof(TESSound) == 0x6c) ? 1 : -1];
class BGSAcousticSpace : public TESForm
{
  public:
    BGSAcousticSpace();
    unsigned char formData[0x3c];
};
typedef char check_BGSAcousticSpace_size[(sizeof(BGSAcousticSpace) == 0x54) ? 1 : -1];
class TESGlobal : public TESForm
{
  public:
    TESGlobal();
    void SetValue(float);
    unsigned char formData[0x10];
};
typedef char check_TESGlobal_size[(sizeof(TESGlobal) == 0x28) ? 1 : -1];
class BGSVoiceType : public TESForm
{
  public:
    BGSVoiceType();
    unsigned char formData[0xc];
};
typedef char check_BGSVoiceType_size[(sizeof(BGSVoiceType) == 0x24) ? 1 : -1];
class BGSImpactData : public TESForm
{
  public:
    BGSImpactData();
    unsigned char formData[0x60];
};
typedef char check_BGSImpactData_size[(sizeof(BGSImpactData) == 0x78) ? 1 : -1];
class BGSImpactDataSet : public TESForm
{
  public:
    BGSImpactDataSet();
    static void CacheImpactDataSet();
    unsigned char formData[0x34];
};
typedef char check_BGSImpactDataSet_size[(sizeof(BGSImpactDataSet) == 0x4c) ? 1 : -1];
class EffectSetting : public TESForm
{
  public:
    EffectSetting();
    unsigned char layout_18[0x20];
    TESFullName fullName;
    unsigned char layout_44[0x6c];
};
typedef char check_EffectSetting_size[(sizeof(EffectSetting) == 0xb0) ? 1 : -1];
class TESClimate : public TESForm
{
  public:
    TESClimate();
    void MakeDefault();
    unsigned char formData[0x40];
};
typedef char check_TESClimate_size[(sizeof(TESClimate) == 0x58) ? 1 : -1];
class TESImageSpace : public TESForm
{
  public:
    TESImageSpace();
    void InitDefaults();
    unsigned char formData[0x98];
};
typedef char check_TESImageSpace_size[(sizeof(TESImageSpace) == 0xb0) ? 1 : -1];
class TESImageSpaceModifier : public TESForm
{
  public:
    TESImageSpaceModifier();
    void InitializeModifierData();
    unsigned char formData[0x718];
};
typedef char check_TESImageSpaceModifier_size[(sizeof(TESImageSpaceModifier) == 0x730) ? 1 : -1];
class TESWeather : public TESForm
{
  public:
    TESWeather();
    void MakeDefault();
    unsigned char formData[0x354];
};
typedef char check_TESWeather_size[(sizeof(TESWeather) == 0x36c) ? 1 : -1];
class TESWorldSpace : public TESForm
{
  public:
    TESWorldSpace();
    void GetReferencesInArea(const NiPoint3&, float, const NiPoint3&, float, bool(__cdecl*)(TESObjectREFR*, long),
                             long);
    bool HasCell(TESObjectCELL*);
    TESObjectCELL* GetCellAtGridPosition(int, int);
    TESObjectCELL* GetCellByWorldPosition(const NiPoint3&);
    unsigned char formData[0xd4];
};
typedef char check_TESWorldSpace_size[(sizeof(TESWorldSpace) == 0xec) ? 1 : -1];
class TESObjectCELL : public TESForm
{
  public:
    TESObjectCELL();
    bool GetReferencesInArea(const NiPoint3&, float, const NiPoint3&, float, bool(__cdecl*)(TESObjectREFR*, long),
                             long);
    int GetCellGridX();
    int GetCellGridY();
    bool IsCellPersistent();
    void RemoveReference(TESObjectREFR*);
    TESWorldSpace* GetParentWorldSpace();
    NavMeshCollection* GetNavMeshArray();
    void SetNavMeshArray(NavMeshCollection*);
    TESObjectLAND* GetLandscape();
    void SetLandscape(TESObjectLAND*);
    bool IsInterior();
    void AddReference(TESObjectREFR*, bool);
    unsigned char formData[0xc8];
};
typedef char check_TESObjectCELL_size[(sizeof(TESObjectCELL) == 0xe0) ? 1 : -1];
class TESSkill : public TESForm
{
  public:
    TESSkill();
    void ResetData();
    unsigned char formData[0x48];
};
typedef char check_TESSkill_size[(sizeof(TESSkill) == 0x60) ? 1 : -1];
class TESLandTexture : public TESForm
{
  public:
    TESLandTexture();
    unsigned char formData[0x10];
};
typedef char check_TESLandTexture_size[(sizeof(TESLandTexture) == 0x28) ? 1 : -1];
class BGSCameraShot : public TESForm
{
  public:
    BGSCameraShot();
    unsigned char formData[0x60];
};
typedef char check_BGSCameraShot_size[(sizeof(BGSCameraShot) == 0x78) ? 1 : -1];
class TESQuest : public TESForm
{
  public:
    TESQuest();
    unsigned char formData[0x54];
};
typedef char check_TESQuest_size[(sizeof(TESQuest) == 0x6c) ? 1 : -1];
class TESRegion : public TESForm
{
  public:
    TESRegion();
    unsigned char formData[0x20];
};
typedef char check_TESRegion_size[(sizeof(TESRegion) == 0x38) ? 1 : -1];
class Script : public TESForm
{
  public:
    Script();
    unsigned char formData[0x3c];
};
typedef char check_Script_size[(sizeof(Script) == 0x54) ? 1 : -1];
class TESCombatStyle : public TESForm
{
  public:
    TESCombatStyle();
    unsigned char formData[0xf0];
};
typedef char check_TESCombatStyle_size[(sizeof(TESCombatStyle) == 0x108) ? 1 : -1];
class TESLoadScreen : public TESForm
{
  public:
    TESLoadScreen();
    unsigned char formData[0x28];
};
typedef char check_TESLoadScreen_size[(sizeof(TESLoadScreen) == 0x40) ? 1 : -1];
class TESWaterForm : public TESForm
{
  public:
    TESWaterForm();
    unsigned char formData[0x17c];
};
typedef char check_TESWaterForm_size[(sizeof(TESWaterForm) == 0x194) ? 1 : -1];
class TESLevSpell : public TESForm
{
  public:
    TESLevSpell();
    unsigned char formData[0x34];
};
typedef char check_TESLevSpell_size[(sizeof(TESLevSpell) == 0x4c) ? 1 : -1];
class TESObjectANIO : public TESForm
{
  public:
    TESObjectANIO();
    unsigned char formData[0x24];
};
typedef char check_TESObjectANIO_size[(sizeof(TESObjectANIO) == 0x3c) ? 1 : -1];
class TESObjectLAND : public TESForm
{
  public:
    TESObjectLAND();
    void InitializeForCell(TESObjectCELL*);
    unsigned char formData[0x14];
};
typedef char check_TESObjectLAND_size[(sizeof(TESObjectLAND) == 0x2c) ? 1 : -1];
class TESEffectShader : public TESForm
{
  public:
    TESEffectShader();
    unsigned char formData[0x158];
};
typedef char check_TESEffectShader_size[(sizeof(TESEffectShader) == 0x170) ? 1 : -1];
class BGSProjectile : public TESBoundObject
{
  public:
    BGSProjectile();
    unsigned char formData[0xa0];
};
typedef char check_BGSProjectile_size[(sizeof(BGSProjectile) == 0xd0) ? 1 : -1];
class BGSExplosion : public TESBoundObject
{
  public:
    BGSExplosion();
    TESFullName fullName;
    unsigned char layout_3c[0x6c];
};
typedef char check_BGSExplosion_size[(sizeof(BGSExplosion) == 0xa8) ? 1 : -1];
class BGSDebris : public TESForm
{
  public:
    BGSDebris();
    unsigned char formData[0xc];
};
typedef char check_BGSDebris_size[(sizeof(BGSDebris) == 0x24) ? 1 : -1];
class BGSTextureSet : public TESForm, public NiMemObject
{
  public:
    BGSTextureSet();
    static void InitializeNullTextureSet();
    unsigned char formData[0x88];
};
typedef char check_BGSTextureSet_size[(sizeof(BGSTextureSet) == 0xa0) ? 1 : -1];
class NavMesh : public TESForm, public NiMemObject
{
  public:
    NavMesh();
    TESObjectCELL* GetParentCell();
    unsigned char formData[0xf0];
};
typedef char check_NavMesh_size[(sizeof(NavMesh) == 0x108) ? 1 : -1];
class BGSPerk : public TESForm
{
  public:
    BGSPerk();
    unsigned char formData[0x38];
};
typedef char check_BGSPerk_size[(sizeof(BGSPerk) == 0x50) ? 1 : -1];
class BGSBodyPartData : public TESForm
{
  public:
    BGSBodyPartData();
    static void InitializeBodyPartData();
    unsigned char formData[0x5c];
};
typedef char check_BGSBodyPartData_size[(sizeof(BGSBodyPartData) == 0x74) ? 1 : -1];
class BGSAddonNode : public TESBoundObject
{
  public:
    BGSAddonNode();
    unsigned int GetIndex();
    void SetIndex(unsigned int);
    unsigned char formData[0x30];
};
typedef char check_BGSAddonNode_size[(sizeof(BGSAddonNode) == 0x60) ? 1 : -1];
class ActorValueInfo : public TESForm
{
  public:
    ActorValueInfo(int, const char*);
    unsigned char formData[0xac];
};
typedef char check_ActorValueInfo_size[(sizeof(ActorValueInfo) == 0xc4) ? 1 : -1];
class BGSRadiationStage : public TESForm
{
  public:
    BGSRadiationStage();
    unsigned char formData[0x8];
};
typedef char check_BGSRadiationStage_size[(sizeof(BGSRadiationStage) == 0x20) ? 1 : -1];
class BGSDehydrationStage : public TESForm
{
  public:
    BGSDehydrationStage();
    unsigned char formData[0x8];
};
typedef char check_BGSDehydrationStage_size[(sizeof(BGSDehydrationStage) == 0x20) ? 1 : -1];
class BGSHungerStage : public TESForm
{
  public:
    BGSHungerStage();
    unsigned char formData[0x8];
};
typedef char check_BGSHungerStage_size[(sizeof(BGSHungerStage) == 0x20) ? 1 : -1];
class BGSSleepDeprivationStage : public TESForm
{
  public:
    BGSSleepDeprivationStage();
    unsigned char formData[0x8];
};
typedef char check_BGSSleepDeprivationStage_size[(sizeof(BGSSleepDeprivationStage) == 0x20) ? 1 : -1];
class BGSMessage : public TESForm
{
  public:
    BGSMessage();
    unsigned char formData[0x28];
};
typedef char check_BGSMessage_size[(sizeof(BGSMessage) == 0x40) ? 1 : -1];
class BGSRagdoll : public TESForm
{
  public:
    BGSRagdoll();
    unsigned char formData[0x130];
};
typedef char check_BGSRagdoll_size[(sizeof(BGSRagdoll) == 0x148) ? 1 : -1];
class BGSLightingTemplate : public TESForm
{
  public:
    BGSLightingTemplate();
    unsigned char formData[0x2c];
};
typedef char check_BGSLightingTemplate_size[(sizeof(BGSLightingTemplate) == 0x44) ? 1 : -1];
class BGSMusicType : public TESForm
{
  public:
    BGSMusicType();
    unsigned char formData[0x1c];
};
typedef char check_BGSMusicType_size[(sizeof(BGSMusicType) == 0x34) ? 1 : -1];
class BGSRecipe : public TESForm
{
  public:
    BGSRecipe();
    unsigned char formData[0x44];
};
typedef char check_BGSRecipe_size[(sizeof(BGSRecipe) == 0x5c) ? 1 : -1];
class BGSRecipeCategory : public TESForm
{
  public:
    BGSRecipeCategory();
    unsigned char formData[0x10];
};
typedef char check_BGSRecipeCategory_size[(sizeof(BGSRecipeCategory) == 0x28) ? 1 : -1];
class TESAmmoEffect : public TESForm
{
  public:
    TESAmmoEffect();
    unsigned char formData[0x18];
};
typedef char check_TESAmmoEffect_size[(sizeof(TESAmmoEffect) == 0x30) ? 1 : -1];
class TESCasinoChips : public TESBoundObject
{
  public:
    TESCasinoChips();
    unsigned char formData[0x6c];
};
typedef char check_TESCasinoChips_size[(sizeof(TESCasinoChips) == 0x9c) ? 1 : -1];
class TESLoadScreenType : public TESForm
{
  public:
    TESLoadScreenType();
    unsigned char formData[0x58];
};
typedef char check_TESLoadScreenType_size[(sizeof(TESLoadScreenType) == 0x70) ? 1 : -1];
class TESCasino : public TESBoundObject
{
  public:
    TESCasino();
    unsigned char formData[0x1f0];
};
typedef char check_TESCasino_size[(sizeof(TESCasino) == 0x220) ? 1 : -1];
class MediaSet : public TESForm
{
  public:
    MediaSet();
    unsigned char formData[0xac];
};
typedef char check_MediaSet_size[(sizeof(MediaSet) == 0xc4) ? 1 : -1];
class MediaLocationController : public TESForm
{
  public:
    MediaLocationController();
    unsigned char formData[0xa0];
};
typedef char check_MediaLocationController_size[(sizeof(MediaLocationController) == 0xb8) ? 1 : -1];
class TESCaravanCard : public TESBoundObject
{
  public:
    TESCaravanCard();
    unsigned char formData[0x8c];
};
typedef char check_TESCaravanCard_size[(sizeof(TESCaravanCard) == 0xbc) ? 1 : -1];
class TESCaravanMoney : public TESBoundObject
{
  public:
    TESCaravanMoney();
    unsigned char formData[0x9c];
};
typedef char check_TESCaravanMoney_size[(sizeof(TESCaravanMoney) == 0xcc) ? 1 : -1];
class TESCaravanDeck : public TESForm
{
  public:
    TESCaravanDeck();
    unsigned char formData[0x14];
};
typedef char check_TESCaravanDeck_size[(sizeof(TESCaravanDeck) == 0x2c) ? 1 : -1];
class BGSMovableStatic : public TESFullName, public BGSDestructibleObjectForm, public TESObjectSTAT
{
  public:
    BGSMovableStatic();
    TESSound* soundLoop;
    unsigned char data;
};
typedef char check_BGSMovableStatic_size[(sizeof(BGSMovableStatic) == 0x74) ? 1 : -1];
class TESFlora : public TESProduceForm, public TESObjectACTI
{
  public:
    TESFlora();
};
typedef char check_TESFlora_size[(sizeof(TESFlora) == 0x9c) ? 1 : -1];
const char* GetStringForByte(unsigned char);
int Warning(const char*, ...);
template <class T> class NiTMallocInterface
{
};
template <class T> class NiTPointerList
{
  public:
    unsigned int data[3];
    void* Find(const T&, void*);
    void* GetHeadPos();
    T& GetNext(void*&);
    void AddTail(const T&);
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* data;
    unsigned short capacity, size, count, grow;
    T& GetAt(unsigned int);
    unsigned int GetSize();
    void SetAt(unsigned int, T&);
    unsigned int Add(T&);
};
class TESRegionList : public BSSimpleList<TESRegion*>
{
  public:
    virtual ~TESRegionList();
};
class TES
{
  public:
    void IsCellAttached(class NavMeshInfoMap*);
    void ProcessCellQueues(bool, bool);
    void ClearField88();
    void SetDawnSound(TESSound*);
    void ResetCachedValues();
    TESForm* GetActiveCell();
    TESObjectCELL* GetPrevPath();
    TESWorldSpace* GetHitSound();
};
extern TES* g_TES;
void RegisterEffectSetting(EffectSetting*);
class MobileObject : public TESObjectREFR
{
};
#endif

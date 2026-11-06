// Private declarations derived from supplied layouts and public PC class declarations.
#ifndef FNV_TESRACE_TYPES_H
#define FNV_TESRACE_TYPES_H

#define TESRACE_JOIN_INNER(a, b) a##b
#define TESRACE_JOIN(a, b) TESRACE_JOIN_INNER(a, b)
#define TESRACE_ASSERT(c) typedef char TESRACE_JOIN(tesrace_assert_, __LINE__)[(c) ? 1 : -1]
// Shared declarations come from the canonical include/ headers: layout_support (BSSimpleList, BSStringT,
// ENUM_FORM_ID, forward declarations) and BaseFormComponent. Canonical NiPointer/BSSimpleArray are renamed away:
// this unit has no NiPointer of its own yet and the canonical one inlines operator= (real calls are out of line).
// the form components (canonical ones have no ctors/dtors; TESRace() calls them), and TESRace/TESNPC/TESActorBase
// stand-ins (no canonical header).
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#include "../../include/layout_support.h"
#undef BSSimpleArray
#undef NiPointer
#include "../../include/BaseFormComponent.h"
class TESNPC;
enum BIPED_OBJECT
{
    BIPED_OBJECT_NONE = -1
};
class TESHair;
class TESEyes;
class BGSVoiceType;
class SpellItem;
class TESLevSpell;
class BSFileEntry;
class FaceGenUndo;
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    TESForm();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID() const;
    bool GetInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(enum ENUM_FORM_ID);

    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};

TESRACE_ASSERT(sizeof(TESForm) == 0x18);
class TESFullName : public BaseFormComponent
{
  public:
    TESFullName();
    virtual ~TESFullName();
    const char* GetFullName();
    BSStringT<char> m_kName;
};
class TESDescription : public BaseFormComponent
{
  public:
    TESDescription();
    unsigned long m_uiDescriptionFileOffset;
};
class TESSpellList : public BaseFormComponent
{
  public:
    TESSpellList();
    virtual ~TESSpellList();
    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
    void InitItem(TESForm*);
};
class TESReactionForm : public BaseFormComponent
{
  public:
    TESReactionForm();
    virtual ~TESReactionForm();
    BSSimpleList<ReactionInfo*> m_kReactionList;
    unsigned char m_ucReactionFlags;
    void InitItem(TESForm*);
};
class WeaponSkillEntry
{
  public:
    char m_eWeaponSkill;
    char m_cBonus;
};
class RaceDefinitionData
{
  public:
    WeaponSkillEntry m_kSkillBonuses[7];
    float m_fGlyphExtent[2];
    float fWeight[2];
    int iFlags;
};
class TESAttributes : public BaseFormComponent
{
  public:
    TESAttributes();
    virtual ~TESAttributes();
    unsigned char cAttribute[7];
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    BSFileEntry** m_ppFileEntries;
};
class TESModel : public BaseFormComponent
{
  public:
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
    unsigned int GetModelLength() const;
    TESModel();
    virtual ~TESModel();
    virtual const char* GetModelFilePath() const;
    virtual void SetModelFilePath(const char*);
};
class TESTexture : public BaseFormComponent
{
  public:
    TESTexture();
    virtual ~TESTexture();
    BSStringT<char> FullNameComponent;
};
class BGSTextureModel : public TESModel
{
  public:
    BGSTextureModel();
    virtual ~BGSTextureModel();
};
// The PC vector representation is 24 bytes (JohnnyGuitar FaceGen/oldstd.hpp).
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
template <class T> struct FaceGenMatrix
{
    FaceGenMatrix();
    ~FaceGenMatrix();
    oldstd::vector<T> data;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
};
template <class T> class NiTPrimitiveArray
{
  public:
    NiTPrimitiveArray(unsigned int, unsigned int);
    virtual ~NiTPrimitiveArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};
enum SEX
{
    SEX_SEX_NONE = -1,
    SEX_SEX_MALE = 0,
    SEX_SEX_FEMALE = 1,
    SEX_SEX_COUNT = 2
};
class TESRace : public TESForm, public TESFullName, public TESDescription, public TESSpellList, public TESReactionForm
{
  public:
    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes, m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    float m_fFaceGenMainClamp, m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2], m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    BSStringT<char> strEditorID;
    NiTPrimitiveArray<FaceGenUndo*> m_kFaceGenUndoList;
    TESRace();
    void ResetFormData();
    void ClearFaceGenUndo();
    TESModel* GetHeadPartModel(SEX, int);
    bool GetBipedObjectModelPath(TESNPC*, BIPED_OBJECT, char*);
    TESModel* GetBipedObjectModel(SEX, BIPED_OBJECT);
    TESModel* GetBodyPartModel(SEX, int);
    void BuildBodyTexturePath(TESNPC*, char*);
    void SetDefaultHairColor(SEX, unsigned char);
    void SetDefaultVoiceType(SEX, BGSVoiceType*);
    BGSTextureModel* GetBodyTextureModel(int);
    FaceGenMatrix<float> (*GetMeanFaceCoord(SEX))[2];
    bool BuildBodyModTexturePath(TESNPC*, char*, char*);
    virtual void InitItem();
};
class CharacterFlagByte
{
  public:
    char cFlags;
};
class BGSVoiceType : public TESForm
{
  public:
    CharacterFlagByte Data;
};
class TESHair : public TESForm, public TESFullName, public TESModel, public TESTexture
{
  public:
    char cFlags;
};
extern BGSVoiceType* g_pDefaultMaleVoiceType;
extern BGSVoiceType* g_pDefaultFemaleVoiceType;
int __cdecl Warning(const char*, ...);
TESRACE_ASSERT(sizeof(RaceDefinitionData) == 0x24);
TESRACE_ASSERT(sizeof(TESModel) == 0x18);
TESRACE_ASSERT(sizeof(FaceGenMatrix<float>) == 0x20);
TESRACE_ASSERT(sizeof(TESRace) == 0x524);
TESRACE_ASSERT(offsetof(TESRace, Data) == 0x50);
TESRACE_ASSERT(offsetof(TESRace, m_acDefaultHairColors) == 0x9c);
TESRACE_ASSERT(offsetof(TESRace, m_apDefaultVoiceTypes) == 0x4fc);
TESRACE_ASSERT(offsetof(TESRace, m_pOlderRace) == 0x504);
TESRACE_ASSERT(offsetof(TESRace, m_pYoungerRace) == 0x508);
TESRACE_ASSERT(offsetof(TESRace, strEditorID) == 0x50c);
class TESNPCModelComponent
{
  public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual bool HasModel();
};
class TESActorBase : public TESForm
{
  public:
    SEX GetSex() const;
};
class TESNPC : public TESActorBase
{
  public:
    char pad18[0x18];
    TESNPCModelComponent model;
    TESNPC* GetFaceNPC();
    FaceGenMatrix<float> (*GetOffsetFaceCoord())[2];
};
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl NormalizePartIndex(BIPED_OBJECT);
class TESBoundObject;
class TESObjectREFR
{
  public:
    TESBoundObject* GetObjectReference();
};
class PlayerCharacter : public TESObjectREFR
{
};
extern PlayerCharacter* g_thePlayer;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int __cdecl strcat_s(char*, unsigned int, const char*);
char* __cdecl FUN_0040ab30(char*, int);
extern "C" const char* __cdecl strrchr(const char*, int);
class NiAVObject;
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
};
class BSFaceGenModelMap
{
  public:
    bool HasFaceGenData(const char*);
};
struct FaceGenCoordinates;
class BSFaceGenManager
{
  public:
    static BSFaceGenModelMap* GetModelMap();
    static const char* BuildFaceGenModelPath(BSStringT<char>&, const char*);
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static void CopyFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2], bool, bool);
    static void BlendFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2],
                                        FaceGenMatrix<float> (*)[2], bool, float);
};
#endif


// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackage.cpp
//
// ActorPackageData. The package reference is refcounted through AddRef and
// Release; runtime-created packages are destroyed once the last reference
// goes away. PTYPE enumerators match guardpackage.h.

// ---- Minimal local declarations: layout-relevant members only ----

// The original TU reached NULL through the game core headers; this
// standalone reconstruction defines it directly.
#define NULL 0

typedef enum
{
    PTYPE_NONE = -1,
    PTYPE_EXPLORE = 0,
    PTYPE_FOLLOW,
    PTYPE_ESCORT,
    PTYPE_EAT,
    PTYPE_SLEEP,
    PTYPE_WANDER,
    PTYPE_TRAVEL,
    PTYPE_ACCOMPANY,
    PTYPE_USEITEMAT,
    PTYPE_AMBUSH,
    PTYPE_FLEE_NON_COMBAT,
    PTYPE_CAST_MAGIC,
    PTYPE_SANDBOX,
    PTYPE_PATROL,
    PTYPE_GUARD,
    PTYPE_DIALOGUE,
    PTYPE_USEWEAPON,
    PTYPE_FIND,
    PTYPE_COMBAT,
    PTYPE_COMBAT_LOW,
    PTYPE_ACTIVATE,
    PTYPE_ALARM,
    PTYPE_FLEE,
    PTYPE_TRESPASS,
    PTYPE_SPECTATOR,
    PTYPE_GREET,
    PTYPE_GET_UP,
    PTYPE_DO_NOTHING,
    PTYPE_IN_GAME_DIALOGUE,
    PTYPE_SURFACE,
    PTYPE_SEARCH_FOR_ATTACKER,
    PTYPE_AVOID_RADIATION,
    PTYPE_EXPLOSION_REACTION,
    PTYPE_GRENDADE_MINE_REACTION,
    PTYPE_STEAL_WARNING,
    PTYPE_PICKPOCKET_WARNING,
    PTYPE_MOVEMENT_BLOCKED,
    PTYPE_SANDMAN,
    PTYPE_CANNIBAL,
    PTYPE_BACK_UP,
    PTYPE_COUNT
} PTYPE;

class TESObjectREFR
{
};

class Actor : public TESObjectREFR
{
};

class TESFile;
template <class T> class BSStringT;
class BGSSaveFormBuffer;

class BGSLoadFormBuffer
{
  public:
    bool ReadFormIdentifier(void* apFormID);
    void ReadTypedData(void* apData, unsigned int auSize);
};

class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* apOther);
    virtual bool CompareWithBase(BaseFormComponent* apOther);
};

class TESForm : public BaseFormComponent
{
  public:
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07();
    virtual bool LoadForm(TESFile* apFile);
    virtual bool Unk_09(void* apArg);
    virtual bool AppendForm(TESFile* apFile);
    virtual void SaveForm();
    virtual bool LoadForm2(TESFile* apFile);
    virtual void WriteFormInfo(TESFile* apFile);
    virtual bool Unk_0E(void* apArg);
    virtual bool Sort(TESForm* apForm);
    virtual TESForm* CreateForm(void* apArg0, void* apMapToAddTo);
    virtual void Unk_11(void* apArg);
    virtual void MarkAsModified(unsigned int auiFlags);
    virtual void MarkAsUnmodified(unsigned int auiFlags);
    virtual unsigned int GetSaveSize(unsigned int auiVersion);
    virtual void Unk_15(void* apArg);
    virtual void SaveGame(unsigned int auiVersion);
    virtual void LoadGame(void* apArg);
    virtual void LoadGame2(unsigned int auiVersion);
    virtual void Unk_19(void* apArg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* apArg0, void* apArg1);
    virtual void Revert(unsigned int auiVersion);
    virtual void Unk_1D(void* apArg);
    virtual void Unk_1E(void* apArg);
    virtual bool Unk_1F(void* apArg);
    virtual void Unk_20(void* apArg);
    virtual void Unk_21(void* apArg);
    virtual void InitItem();
    virtual unsigned int GetTypeID();
    virtual void GetDebugName(BSStringT<char>* apDst);
    virtual bool IsQuestItem();
    virtual bool Unk_26();
    virtual bool Unk_27();
    virtual bool Unk_28();
    virtual bool Unk_29(bool abSet);
    virtual bool Unk_2A(bool abSet);
    virtual bool Unk_2B();
    virtual bool Unk_2C();
    virtual bool Unk_2D();
    virtual bool Unk_2E();
    virtual void Unk_2F(bool abSet);
    virtual bool Unk_30();
    virtual void MarkForDeletion(bool abSet);
    virtual void SetAltered(bool abSet);
    virtual void SetQuestItem(bool abSet);
    virtual void Unk_34(bool abSet);
    virtual void Unk_35(bool abSet);
    virtual void Unk_36(bool abSet);
    virtual void Unk_37();
    virtual void readOBNDSubRecord(TESFile* apFile);
    virtual bool IsActor_InEditor();
    virtual bool IsBoundObject();
    virtual bool Unk_3B();
    virtual bool GetIsReference() const;
    virtual bool Unk_3D();
    virtual bool Unk_3E();
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41();
    virtual void CopyFrom(const TESForm* apForm);
    virtual bool Compare(TESForm* apForm);
    virtual bool CheckFormGRUP(void* apArg);
    virtual void InitFormGRUP(void* apDst, void* apArg1);
    virtual bool Unk_46();
    virtual bool Unk_47();
    virtual bool Unk_48(unsigned int aeFormType);
    virtual bool Unk_49(void* apArg0, void* apArg1, void* apArg2, void* apArg3, void* apArg4);
    virtual void SetRefID(unsigned int auiRefID, bool abGenerateID);
    virtual char* GetName2();
    virtual char* GetName() const;
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int auiFormID);
};

class TESPackage : public TESForm
{
  public:
    void AddRef();
    int Release();
    bool IsMustComplete();
    PTYPE GetPackType();
    static TESPackage* CreatePackageForType(PTYPE aeType);
};

class BGSSaveLoadGame
{
  public:
    void ChangeFormID(unsigned int auiOldFormID, unsigned int auiNewFormID);
};

class TESSaveLoadGame
{
  public:
    bool GetLoading();
    void DeleteForm(TESForm* apForm);
};

class TESDataHandler
{
  public:
    bool FormIDExists(unsigned int auiFormID);
};

class PlayerCharacter
{
  public:
    unsigned char m_padding208[0x208];
    TESPackage* pCurrentPackage;
};

class Calendar
{
  public:
    float GetGameTime();
};

class ActorPackageData
{
  public:
    virtual ~ActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    static ActorPackageData* CreatePackageData(PTYPE aeType);
};

typedef enum
{
    GUARD_STATE_INIT = 0,
    GUARD_STATE_IDLE = 1,
    GUARD_STATE_WAIT_TO_ATTACK = 2
} GUARD_STATE;

class GuardActorPackageData : public ActorPackageData
{
  public:
    GUARD_STATE eState;     // +0x4
    Actor* pWarningTarget;  // +0x8
    int iWarningCount;      // +0xC
    float m_fWarningTimer;  // +0x10
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
};

class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
    void Clear();
    void SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    bool IsFlagSet(unsigned char aeFlag);
    void SetFlag(unsigned char aeFlag, bool abSet);
};

extern PlayerCharacter* g_thePlayer;
extern TESDataHandler* g_dataHandler;
extern Calendar g_calendar;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern const char* g_packageTypeNames[];
void LogWarning(const char* apFormat, ...);

static const char s_kPackageTypeChangedWarning[] =
    "Package '%s' (%08X) changed type from %s to %s, so the actor package data was replaced";

// Clears the stored actor reference if it matches the passed reference.
// @fnv 0x008c5ec0
void GuardActorPackageData::SetReferenceTarget(TESObjectREFR* apReference)
{
    if (apReference == pWarningTarget)
        pWarningTarget = NULL;
}

// @fnv 0x008c5ef0
void ActorPackageContext::Clear()
{
    if (pPackage)
    {
        if (pPackage == g_thePlayer->pCurrentPackage)
            g_thePlayer->pCurrentPackage = NULL;
        if (!pPackage->Release() && pPackage->IsMustComplete())
        {
            TESPackage* pOldPackage = pPackage;
            pPackage = NULL;
            if (g_TESSaveLoadGame->GetLoading())
                g_TESSaveLoadGame->DeleteForm(pOldPackage);
            else
                delete pOldPackage;
        }
        else
        {
            pPackage = NULL;
        }
    }
    if (pData)
    {
        delete pData;
        pData = NULL;
    }
    m_fPackageValue = -1.0F;
    m_iPackageValue = -1;
    iFlags = 0;
    pTarget = NULL;
}

// @fnv 0x008c6080
void ActorPackageContext::SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget)
{
    if (apPackage == pPackage)
        return;
    Clear();
    if (apPackage)
    {
        apPackage->AddRef();
        m_fPackageValue = g_calendar.GetGameTime();
        pPackage = apPackage;
        pData = ActorPackageData::CreatePackageData(apPackage->GetPackType());
        m_iPackageValue = 0;
        pTarget = apTarget;
    }
}

// Reads a package form ID, package type and package data from the buffer, then reads flags and target, creating the package if needed.
// @fnv 0x008c6730
void ActorPackageContext::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    unsigned int iFormID = 0;
    bool bResult = apBuffer->ReadFormIdentifier(&iFormID);
    bool bCreated;
    if (iFormID || bResult)
    {
        char cDataType;
        bCreated = false;
        if (g_dataHandler->FormIDExists(iFormID))
        {
            char cPackageType = 0;
            apBuffer->ReadTypedData(&cPackageType, 1);
            if (cPackageType != -1)
            {
                pPackage = TESPackage::CreatePackageForType((PTYPE)cPackageType);
                g_BGSSaveLoadGame->ChangeFormID(iFormID, pPackage->GetFormID());
                pPackage->LoadGame(apBuffer);
            }
            else
            {
                pPackage = (TESPackage*)iFormID;
                bCreated = true;
            }
        }
        else
        {
            pPackage = iFormID ? dynamic_cast<TESPackage*>(TESForm::GetFormByID(iFormID)) : NULL;
        }
        cDataType = -1;
        apBuffer->ReadTypedData(&cDataType, 1);
        if (cDataType != -1)
        {
            pData = ActorPackageData::CreatePackageData((PTYPE)cDataType);
            pData->LoadGame(apBuffer);
        }
        else
        {
            delete pData;
            pData = NULL;
        }
        apBuffer->ReadTypedData(&m_iPackageValue, 4);
        apBuffer->ReadTypedData(&m_fPackageValue, 4);
        apBuffer->ReadTypedData(&iFlags, 4);
        apBuffer->ReadFormIdentifier(&pTarget);
        if (bCreated)
            SetFlag(0, true);
    }
    if (bResult)
        Clear();
}

// @fnv 0x008c6b20
void ActorPackageContext::ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer)
{
    if (IsFlagSet(0))
        SetFlag(0, false);
    else if (pPackage && g_dataHandler->FormIDExists(pPackage->GetFormID()))
        pPackage->Unk_21(apBuffer);
    if (pData && pPackage)
    {
        if (pPackage->GetPackType() != pData->GetPackageType())
        {
            LogWarning(s_kPackageTypeChangedWarning, pPackage->GetName(), pPackage->GetFormID(),
                       g_packageTypeNames[pData->GetPackageType()], g_packageTypeNames[pPackage->GetPackType()]);
            delete pData;
            pData = ActorPackageData::CreatePackageData(pPackage->GetPackType());
        }
    }
}

#include "actorpackage_getters.h"

// @fnv 0x004fd3e0
TESSound* EffectSetting::GetHitSound()
{
    return hitSound;
}

extern int DAT_01031fac;

struct FUN_00527770_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00527770_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00527770
int* __fastcall FUN_00527770(int* self, FUN_00527770_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

struct FUN_008c5e70_shell : public ActorPackageContext
{
    void DeleteData();
};

// Deletes pData if it is non-null.
// @fnv 0x008c5e70
void FUN_008c5e70_shell::DeleteData()
{
    if (pData)
        delete pData;
}

struct FUN_008c6030_shell : public TESPackage
{
    unsigned int FUN_008c6030();
};

unsigned int __cdecl FinishScriptRunLock(void*);

// @fnv 0x008c6030
unsigned int FUN_008c6030_shell::FUN_008c6030()
{
    unsigned int newRefCount = FinishScriptRunLock((char*)this + 0x7c);
    return newRefCount;
}

struct FUN_008c6100_shell : public TESPackage
{
    unsigned int FUN_008c6100();
};

unsigned int __cdecl InitScriptRunLock(void*);

// Calls InitScriptRunLock on the object at offset 0x7c and returns its result.
// @fnv 0x008c6100
unsigned int FUN_008c6100_shell::FUN_008c6100()
{
    unsigned int newRefCount = InitScriptRunLock((char*)this + 0x7c);
    return newRefCount;
}

struct FUN_008c6130_shell : public ActorPackageContext
{
    void MovePackageData(ActorPackageContext*);
};

// @fnv 0x008c6130
void FUN_008c6130_shell::MovePackageData(ActorPackageContext* apDestPackageInstance)
{
    apDestPackageInstance->pPackage = pPackage;
    apDestPackageInstance->pData = pData;
    apDestPackageInstance->m_iPackageValue = m_iPackageValue;
    apDestPackageInstance->m_fPackageValue = m_fPackageValue;
    pPackage = NULL;
    pData = NULL;
    m_iPackageValue = -1;
    m_fPackageValue = -1.0f;
}

struct FUN_008c6b00_shell : public ActorPackageContext
{
    bool FUN_008c6b00(int);
};

// Returns true if the bit for aeFlag is set in the 32-bit flags field at offset 0x14 of this object.
// @fnv 0x008c6b00
bool FUN_008c6b00_shell::FUN_008c6b00(int aeFlag)
{
    return ((1 << aeFlag) & *(unsigned int*)((char*)this + 0x14)) ? true : false;
}

struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESFile;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
typedef char _sizecheck_BGSClipRoundsForm[sizeof(BGSClipRoundsForm) == 8 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
struct BGSMessageIcon : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    static void LoadMessageIcon(BGSMessageIcon*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char*);
    void* __vecDelDtor(unsigned int);
    TESIcon Icon;
};
typedef char _sizecheck_BGSMessageIcon[sizeof(BGSMessageIcon) == 16 ? 1 : -1];
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];
struct FUN_008c6060_shell : public BGSClipRoundsForm
{
    void FUN_008c6060();
};

// @fnv 0x008c6060
void FUN_008c6060_shell::FUN_008c6060()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) = 0;
}

struct FUN_008c65a0_shell
{
    void* pPackage;
    void FUN_008c65a0(int aiFlags);
};
// @fnv 0x008c65a0
void FUN_008c65a0_shell::FUN_008c65a0(int aiFlags)
{
    if ((aiFlags & 0) && pPackage)
        ((ActorPackageContext*)this)->Clear();
}

struct DataHandler
{
    bool FormIDExists(unsigned int auiFormID);
};

struct TESObjectREFRHelper
{
    void SetTargetingState(bool abTargeted);
};

struct FUN_0084aa90_shell
{
    unsigned int FUN_0084aa90(unsigned int auiFormID);
};

struct FUN_009611e0_shell
{
    int FUN_009611e0();
};

struct FUN_006777b0_shell
{
    void ComputePackageFlags(TESObjectREFR* apTarget);
};

int __cdecl FUN_0096a820(int);

struct FUN_008c6970_shell : public ActorPackageContext
{
    void FUN_008c6970(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x008c6970
void FUN_008c6970_shell::FUN_008c6970(BGSLoadFormBuffer* apBuffer)
{
    if (IsFlagSet(0))
    {
        unsigned int uiPackageFormID = ((FUN_0084aa90_shell*)g_BGSSaveLoadGame)->FUN_0084aa90((unsigned int)pPackage);
        pPackage = uiPackageFormID ? dynamic_cast<TESPackage*>(TESForm::GetFormByID(uiPackageFormID)) : 0;
    }
    else if (pPackage && ((DataHandler*)g_dataHandler)->FormIDExists(pPackage->GetFormID()))
    {
        pPackage->Unk_19(apBuffer);
    }
    if (pPackage)
    {
        if (((FUN_009611e0_shell*)pPackage)->FUN_009611e0() == -1)
            ((FUN_006777b0_shell*)pPackage)->ComputePackageFlags(0);
        pPackage->AddRef();
        int iCount = FUN_0096a820(((FUN_009611e0_shell*)pPackage)->FUN_009611e0());
        if (m_iPackageValue >= iCount)
            m_iPackageValue = iCount - 1;
    }
    if (pData)
        pData->InitLoadGame(apBuffer);
    pTarget = pTarget ? dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID((unsigned int)pTarget)) : 0;
    if (pTarget)
        ((TESObjectREFRHelper*)pTarget)->SetTargetingState(true);
}

struct NvGate
{
    bool Check(unsigned int aiValue);
};
extern NvGate* g_pNvGate;
struct NvInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual unsigned short v83();
    unsigned int GetA();
    bool Check();
};
struct NvOuter
{
    NvInner* m_pInner;
    unsigned short ComputeTotal(int aiFlags);
};
// @fnv 0x008c61a0
unsigned short NvOuter::ComputeTotal(int aiFlags)
{
    int total = 0;
    total += 4;
    if (m_pInner != 0)
    {
        unsigned int uiValue = m_pInner->GetA();
        if ((aiFlags & 0) != 0)
        {
            if (g_pNvGate->Check(uiValue))
            {
                bool b = m_pInner->Check();
                total += 1;
                if ((aiFlags & 0) == 0)
                {
                    total += m_pInner->v83();
                }
            }
        }
        total += 4;
    }
    total += 4;
    return (unsigned short)total;
}

class BGSSaveFormBuffer
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual int GetVersion();
    void SerializeFormData(void* apForm, int aiFlags);
    void SaveData(void* apData, unsigned int auSize, int aiFlags);
};

struct TESPackageEx : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual bool IsDataValidForVersion(int aiVersion);
};

struct ActorPackageSaver : public ActorPackageContext
{
    void SavePackage(BGSSaveFormBuffer* apBuffer);
};

// Saves the package's type, data, flags and target to the buffer, writing -1 for the type when the package data is invalid for the buffer version.
// @fnv 0x008c65d0
void ActorPackageSaver::SavePackage(BGSSaveFormBuffer* apBuffer)
{
    int iVersion = apBuffer->GetVersion();
    apBuffer->SerializeFormData(pPackage, 0);
    if (pPackage)
    {
        if (g_dataHandler->FormIDExists(pPackage->GetFormID()))
        {
            char cType = pPackage->GetPackType();
            if (!((TESPackageEx*)pPackage)->IsDataValidForVersion(iVersion))
                cType = -1;
            apBuffer->SaveData(&cType, 1, 0);
            if (cType != -1)
                pPackage->Unk_15(apBuffer);
        }
        char cDataType = pData ? pData->GetPackageType() : -1;
        apBuffer->SaveData(&cDataType, 1, 0);
        if (cDataType != -1)
            pData->SaveGame(apBuffer);
        apBuffer->SaveData(&m_iPackageValue, 4, 0);
        apBuffer->SaveData(&m_fPackageValue, 4, 0);
        apBuffer->SaveData(&iFlags, 4, 0);
        apBuffer->SerializeFormData(pTarget, 0);
    }
}

class TESForm;
class TESPackage;
TESForm* __cdecl FUN_004839c0(unsigned int id);
struct Manager
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void dispatch();
    unsigned FUN_0084e3a0();
    int FUN_009611e0();
};
struct Handler
{
    bool FUN_00469860(unsigned);
};
extern Handler* DAT_011c3f2c;
int __cdecl FUN_0096a820(int);
struct Owner
{
    Manager* manager;
    int unk04, unk08, interval;
    void FUN_008c6080(TESPackage*, int);
    void FUN_008c64d0(unsigned, unsigned);
};
// @fnv 0x008c64d0
void Owner::FUN_008c64d0(unsigned a, unsigned auiUnused)
{
    if (manager)
    {
        if (a & 0)
        {
            if (a & 0)
            {
                Manager* pManager = manager;
                FUN_008c6080(dynamic_cast<TESPackage*>(FUN_004839c0((unsigned)pManager)), 0);
            }
            else
            {
                if (DAT_011c3f2c->FUN_00469860(manager->FUN_0084e3a0()))
                    manager->dispatch();
            }
        }
        if (manager)
        {
            int elapsed = FUN_0096a820(manager->FUN_009611e0());
            if (interval >= elapsed)
                interval = elapsed - 1;
        }
    }
}

struct PackageSaveWriter
{
    void FUN_00857a10(void* data, unsigned int size);
    void SaveGameDataOLD(void* data, unsigned int size);
};
extern PackageSaveWriter* DAT_011de45c;

struct PackageVirtuals : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
};
struct ActorPackageLegacySave : public ActorPackageContext
{
    void FUN_008c6250(unsigned int auiFlags);
};
// Writes the package form ID, writes m_iPackageValue when the ID is nonzero, and always writes m_fPackageValue.
// @fnv 0x008c6250
void ActorPackageLegacySave::FUN_008c6250(unsigned int auiFlags)
{
    unsigned int auiFormId = 0;
    if (pPackage != NULL)
    {
        auiFormId = pPackage->GetFormID();
    }
    DAT_011de45c->FUN_00857a10(&auiFormId, 4);
    if (auiFormId != 0)
    {
        if ((auiFlags & 0) != 0 && g_dataHandler->FormIDExists(auiFormId))
        {
            unsigned char ucType = pPackage->GetPackType();
            DAT_011de45c->SaveGameDataOLD(&ucType, 1);
            if ((auiFlags & 0) == 0)
            {
                static_cast<PackageVirtuals*>(pPackage)->Unk_54();
            }
        }
        DAT_011de45c->SaveGameDataOLD(&m_iPackageValue, 4);
    }
    DAT_011de45c->SaveGameDataOLD(&m_fPackageValue, 4);
}

extern "C" void __cdecl FUN_005b5e40(const char* apFormat, ...);

struct LoadedPackage : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void InitAfterLoad();
    int GetLoadIndex();
    void SetTargetRef(TESObjectREFR* apTarget);
};

struct SaveLoadStub
{
    bool ReadFormID(unsigned int* apFormID, int aiSize);
    void ReadData(void* apData, unsigned int auiSize);
    void SkipData(unsigned int auiSize);
    LoadedPackage* GetCreatedPackage(unsigned int auiFormID, unsigned char aucType);
};

TESForm* LookupFormByID(unsigned int auiFormID);

struct ActorPackageLoad : public ActorPackageContext
{
    void FUN_008c6320(int aiFlags, int aiUnused);
    void SetProcIndex(int aiIndex);
};

// @fnv 0x008c6320
void ActorPackageLoad::FUN_008c6320(int aiFlags, int aiUnused)
{
    unsigned int auiFormId;
    bool bRead = ((SaveLoadStub*)g_TESSaveLoadGame)->ReadFormID(&auiFormId, 4);
    Clear();
    bool bFailed = false;
    if (auiFormId)
    {
        if ((aiFlags & 0) && g_dataHandler->FormIDExists(auiFormId))
        {
            unsigned char ucType;
            ((SaveLoadStub*)g_TESSaveLoadGame)->ReadData(&ucType, 1);
            if (!(aiFlags & 0))
            {
                LoadedPackage* pNew = ((SaveLoadStub*)g_TESSaveLoadGame)->GetCreatedPackage(auiFormId, ucType);
                pNew->InitAfterLoad();
                SetPackageAndTarget(pNew, 0);
                if (pNew->GetLoadIndex() == -1)
                {
                    pNew->SetTargetRef(pTarget);
                }
            }
            else
            {
                SetPackageAndTarget((TESPackage*)auiFormId, 0);
            }
        }
        else
        {
            SetPackageAndTarget(dynamic_cast<TESPackage*>(LookupFormByID(auiFormId)), 0);
            if (pPackage)
            {
                ((LoadedPackage*)pPackage)->SetTargetRef(pTarget);
            }
            else
            {
                bFailed = true;
            }
        }
        ((SaveLoadStub*)g_TESSaveLoadGame)->ReadData(&m_iPackageValue, 4);
    }
    else if (bRead)
    {
        ((SaveLoadStub*)g_TESSaveLoadGame)->SkipData(4);
        SetProcIndex(0);
        bFailed = true;
    }
    if (bFailed)
    {
        if (auiFormId)
        {
            FUN_005b5e40("AI: Couldn't find package %08X while loading and will try to choose a new one.", auiFormId);
        }
        else
        {
            FUN_005b5e40("AI: Couldn't find a plugin package while loading and will try to choose a new one.");
        }
        SetProcIndex(-1);
    }
    ((SaveLoadStub*)g_TESSaveLoadGame)->ReadData(&m_fPackageValue, 4);
}

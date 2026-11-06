// fallout/misc/saveload/bgssaveloadglobaldata.cpp: SaveGameLoader (23 functions)

#include "bgssaveloadglobaldata_packet.h"
class BGSLoadGameBuffer;
class TESObjectCELL;

class ProcessLists
{
  public:
    void InitLoadGame(BGSLoadGameBuffer* buffer);
    void Revert(BGSLoadGameBuffer*);
};

class TESWorldSpace
{
  public:
    TESObjectCELL* LookupCellByEditorID(const char* editorID);
};

extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

class ActorCause
{
  public:
    static void SaveActorCauses(BGSLoadGameBuffer* buffer);
    static void LoadReferencesFromBuffer(BGSLoadGameBuffer*);
    static void ClearActorCauseList(BGSLoadGameBuffer*);
};

class FalloutRadio
{
  public:
    static void InitLoadGame(BGSLoadGameBuffer* buffer);
    static void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
};

class SaveGameLoader
{
  public:
    static void LoadGameData(BGSLoadGameBuffer*);
    static void FreeChangeData();
    static void UnloadGameData();
    static bool LoadFormType(unsigned int, BGSLoadGameBuffer*);
    static void LoadEffects(BGSLoadGameBuffer*);
    static bool LoadFormRange(unsigned int, BGSLoadGameBuffer*, bool);
    static bool LoadGlobalDataRange(unsigned int, BGSLoadGameBuffer*);
    static bool LoadGlobalDataType(unsigned int type, BGSLoadGameBuffer* buffer);
};

void __cdecl LogWarning(const char* format, ...);
extern "C" void fnv_call_975af0();
extern "C" void fnv_call_993600();
extern "C" void fnv_call_66e810();
extern "C" void fnv_call_836af0();
extern "C" void fnv_call_845cc0();

// @fnv 0x0084d160
void SaveGameLoader::UnloadGameData()
{
    ScreenSplatter::Clear();
    ScreenCustomSplatter::Clear();
    FUN_0045a190()->BSPortal::~BSPortal();
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* node = g_TES->FUN_0043b5d0();
    while (node)
    {
        ImageSpaceModifierInstance* effect =
            (ImageSpaceModifierInstance*)((NiPointer<NiNode>*)&((BSSimpleList<BGSPerkEntry*>*)node)->GetItem())
                ->
                operator->();
        if (effect && !effect->IsFlagSet())
        {
            NiPointer<NiAVObject> ref((NiAVObject*)effect);
            node->Remove(ref);
            continue;
        }
        else
        {
            if (effect)
                ((ImageSpaceModifierInstanceDOF*)effect)->FUN_0063f790(0.0f);
        }
        node = (BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
}

// Dispatches loading of global game data by type to the matching loader, logging an error for unknown types.
// @fnv 0x0084c190
bool SaveGameLoader::LoadFormType(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        g_TES->ProcessItems(buffer);
        return true;
    case 3:
        return false;
    case 4:
        return false;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->ApplyLoadBuffer(buffer);
        return true;
    case 6:
        Interface::ApplyLoadBuffer(buffer);
        return true;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        return false;
    case 10:
        FalloutRadio::ApplyLoadBuffer(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    default:
        LogWarning("DEFAULT: Unknown global data type %i in FinishLoadGlobalData()", type);
        return false;
    }
}

// @fnv 0x0084d070
void SaveGameLoader::LoadEffects(BGSLoadGameBuffer* buffer)
{
    unsigned int count = buffer->ReadElementCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        float strength = 0.0f;
        buffer->ReadDataBlock(&strength, 4);
        TESImageSpaceModifier* modifier;
        {
            float age = 0.0f;
            if (buffer->GetVersion() >= 14)
                buffer->ReadDataBlock(&age, 4);
            modifier = 0;
            modifier = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
            if (modifier)
            {
                ImageSpaceModifierInstanceForm* instance =
                    ImageSpaceModifierInstanceForm::Trigger(modifier, strength, 0);
                if (instance)
                    instance->SetPad5(DAT_011c3c08 - age);
            }
        }
    }
}

// Dispatches on a global data type to revert the matching subsystem from the load buffer, returning false for unsupported types.
// @fnv 0x0084c330
bool SaveGameLoader::LoadFormRange(unsigned int type, BGSLoadGameBuffer* buffer, bool globals)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        g_TES->FUN_00459840(buffer);
        return true;
    case 3:
        if (globals)
        {
            FreeChangeData();
            return true;
        }
        return false;
    case 4:
        ((FalloutRadio*)&g_011e0e80)->Revert(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00993800(buffer);
        return true;
    case 6:
        Interface::Revert(buffer);
        return true;
    case 7:
        UnloadGameData();
        return true;
    case 0:
        FUN_004d60c0(buffer);
        return true;
    case 8:
        return false;
    case 9:
        ActorCause::ClearActorCauseList(buffer);
        return true;
    case 10:
        ResetRadioGlobals(buffer);
        return true;
    case 11:
        Interface::PrintDebugMessage(buffer);
        return true;
    case 1000:
        ((ProcessLists*)&g_011e0e80)->Revert(buffer);
        return true;
    default:
        LogWarning("DEFAULT: Unknown global data type %i in RevertGlobalData()", type);
        return false;
    }
}

// Dispatches loading of global game data to the handler for the given type, returning false and logging an error for unknown types.
// @fnv 0x0084be40
bool SaveGameLoader::LoadGlobalDataRange(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        LoadGameData(buffer);
        return true;
    case 2:
        g_TES->LoadGame(buffer);
        return true;
    case 3:
        FUN_0084cd40(buffer);
        return true;
    case 4:
        ((FalloutRadio*)&g_011e0e80)->LoadGame(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->LoadGame(buffer);
        return true;
    case 6:
        Interface::LoadGame(buffer);
        return true;
    case 7:
        LoadEffects(buffer);
        return true;
    case 0:
        ReadSavedSettings(buffer);
        return true;
    case 8:
        Sky::GetInstance()->LoadGame(buffer);
        return true;
    case 9:
        ActorCause::LoadReferencesFromBuffer(buffer);
        return true;
    case 10:
        FUN_008368b0(buffer);
        return true;
    case 11:
        SoundPlaybackManager::LoadGame(buffer);
        return true;
    case 1000:
        ((MagicCaster*)&g_011e0e80)->MagicCaster::SetSelectedMagicItem((MagicItem*)buffer);
        return true;
    default:
        LogWarning("SAVELOAD: Unknown global data type %i in LoadGlobalData()", type);
        return false;
    }
}

extern int _data_011c16bc;
class SaveLoadFile;
void __cdecl ReadFileIntoBuffer(SaveLoadFile*, unsigned int*, unsigned int);
struct LGB : BGSLoadGameBuffer
{
    void ReadAndVerifySize(SaveLoadFile*);
    int pad[3];
    ~LGB()
    {}
};
// Reads count entries from file, each a type followed by a buffer, and loads each global data range.
// @fnv 0x0084bc20
void __cdecl LoadGlobalDataRanges(SaveLoadFile* file, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        LGB buffer;
        {
            unsigned int type = 0;
            ReadFileIntoBuffer(file, &type, 4);
            buffer.ReadAndVerifySize(file);
            SaveGameLoader::LoadGlobalDataRange(type, &buffer);
        }
    }
}

namespace Local {
class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    int pad[4];
};
}

// @fnv 0x0084bfb0
void __cdecl FUN_0084bfb0(unsigned int start, unsigned int end)
{
    Local::BGSLoadGameBuffer buffer;
    for (unsigned int i = start; i < end; ++i)
    {
        SaveGameLoader::LoadGlobalDataType(i, reinterpret_cast< ::BGSLoadGameBuffer*>(&buffer));
    }
}

struct G975
{
    void fnv_call_975af0(BGSLoadGameBuffer*);
};
struct W993
{
    void fnv_call_993600(BGSLoadGameBuffer*);
};
// @fnv 0x0084c030
bool __cdecl FUN_0084c030(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        return false;
    case 3:
        return false;
    case 4:
        ((G975*)&g_011e0e80)->fnv_call_975af0(buffer);
        return true;
    case 5:
        ((W993*)BGSSaveLoadGlobalDataWorldspacePtr)->fnv_call_993600(buffer);
        return true;
    case 6:
        return false;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        ((void(__cdecl*)(BGSLoadGameBuffer*))fnv_call_66e810)(buffer);
        return true;
    case 10:
        ((void(__cdecl*)(BGSLoadGameBuffer*))fnv_call_836af0)(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    }
    ((void(__cdecl*)(const char*, unsigned int))fnv_call_845cc0)(
        "DEFAULT: Unknown global data type %i in InitGlobalData()", type);
    return false;
}

namespace fnv_0084c110 {
struct LGB : BGSLoadGameBuffer
{
    int pad[3];
    ~LGB()
    {}
};
// @fnv 0x0084c110
void __cdecl LoadSavedFormTypes(unsigned int aiStart, unsigned int aiEnd)
{
    LGB loadGameBuffer;
    for (unsigned int i = aiStart; i < aiEnd; ++i)
        SaveGameLoader::LoadFormType(i, &loadGameBuffer);
}
}  // namespace fnv_0084c110

struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_0084cc40_shell : public BGSSaveLoadGame
{
    void FUN_0084cc40(bool);
};

// Sets or clears bit 0x40 in the flags field according to abValue.
// @fnv 0x0084cc40
void FUN_0084cc40_shell::FUN_0084cc40(bool abValue)
{
    if (abValue)
        m_uiInitializationFlags |= 0x40;
    else
        m_uiInitializationFlags &= ~0x40;
}

struct FUN_0084d050_shell : public ImageSpaceModifierInstance
{
    bool IsFlagSet();
};

// @fnv 0x0084d050
bool FUN_0084d050_shell::IsFlagSet()
{
    return (*(unsigned int*)((char*)this + 0x18) & 1) ? true : false;
}

class FUN_0084c580_shell
{
  public:
    unsigned int field208;
    unsigned int __thiscall GetField208();
};

// @fnv 0x0084c580
unsigned int __thiscall FUN_0084c580_shell::GetField208()
{
    return *(unsigned int*)((char*)this + 0x208);
}

class TESGlobal : public TESForm
{
  public:
    bool IsConstantGlobal();
    float GetValue();
};

struct GlobalListNode
{
    TESGlobal*& FUN_006815c0();
    GlobalListNode* FUN_00726070();
};

struct TESDataHandler
{
    GlobalListNode* GetTESGlobalList();
};

struct BGSSaveFormBuffer
{
    void SerializeFormData(void* apForm, int aiFlags);
    void SaveData(void* apData, int aiSize, int aiFlags);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int aiCount, unsigned int auiPos);
};

extern TESDataHandler* g_dataHandler;

// @fnv 0x0084cc90
void FUN_0084cc90(BGSSaveFormBuffer* apBuffer)
{
    GlobalListNode* pList = g_dataHandler->GetTESGlobalList();
    int iCount = 0;
    unsigned int uiStart = apBuffer->FUN_00865f20();
    GlobalListNode* pIter = pList;
    while (pIter)
    {
        TESGlobal* pGlobalForm = pIter->FUN_006815c0();
        if (pGlobalForm && !pGlobalForm->IsConstantGlobal())
        {
            apBuffer->SerializeFormData(pGlobalForm, 0);
            float fValue = pGlobalForm->GetValue();
            apBuffer->SaveData(&fValue, 4, 0);
            ++iCount;
        }
        pIter = pIter->FUN_00726070();
    }
    apBuffer->FUN_00865ff0(iCount, uiStart);
}

namespace fnv_00866200 {
struct SaveLoadFile
{
    void WriteToFile(const void* apData, unsigned int auiSize);
};

struct PackedFormID
{
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
    void WriteFormIDBytes(unsigned int auiFormID);
};

struct BGSSaveLoadChangeFlags
{
    unsigned char cFlags1;
    unsigned char cFlags2;
    unsigned char cFlags3;
    unsigned char cFlags4;
};

struct BGSSaveLoadFormType
{
    unsigned char m_ucFormType;
    int FUN_00864520();
};

struct FormLoadContext
{
    PackedFormID iFormID;
    BGSSaveLoadChangeFlags m_pDeathItem;
    BGSSaveLoadFormType m_ucFormType;
    unsigned char cVersion;
    FormLoadContext();
};

int __cdecl ReadValueBySizeType(const char* apBuffer, unsigned int* apValue, int aiSize);
void __cdecl WriteValueByType(SaveLoadFile* apFile, unsigned int auiValue, int aiSize);

struct FUN_00866200_owner
{
    char* pBuffer;
    void FUN_00866200(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags);
};

// @fnv 0x00866200
void FUN_00866200_owner::FUN_00866200(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags)
{
    char* pData = pBuffer;
    char* pCurrent = pBuffer + 2;
    FormLoadContext header;
    header.iFormID.WriteFormIDBytes(auiFormID);
    header.m_pDeathItem = aChangeFlags;
    header.m_ucFormType.m_ucFormType = pData[0];
    header.cVersion = pData[1];
    apFile->WriteToFile(&header, 9);
    int iSize = header.m_ucFormType.FUN_00864520();
    unsigned int uiValue = 0;
    pCurrent += ReadValueBySizeType(pCurrent, &uiValue, iSize);
    WriteValueByType(apFile, uiValue, iSize);
    if (uiValue)
        apFile->WriteToFile(pCurrent, uiValue);
}
}  // namespace fnv_00866200

namespace fnv_00975840 {
struct BGSSaveFormBuffer
{
    void SaveData(void* apData, int aiSize, int aiFlags);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int aiCount, unsigned int auiPos);
};

struct SavedItem
{
    void SaveToStream(BGSSaveFormBuffer* apBuffer);
};

struct ItemListNode
{
    SavedItem*& FUN_006815c0();
    ItemListNode* FUN_00726070();
};

struct FUN_00975840_owner
{
    void FUN_00975840(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x00975840
void FUN_00975840_owner::FUN_00975840(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData((char*)this + 0x154, 4, 0);
    apBuffer->SaveData((char*)this + 0x158, 4, 0);
    apBuffer->SaveData((char*)this + 0x103b4, 4, 0);
    apBuffer->SaveData((char*)this + 0x103b8, 4, 0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        unsigned int ItemUpdateArray = 0;
        unsigned int uiStart = apBuffer->FUN_00865f20();
        ItemListNode* pIter = ((ItemListNode**)((char*)this + 0x44))[i];
        while (pIter)
        {
            SavedItem* pSavedItem = pIter->FUN_006815c0();
            if (pSavedItem)
            {
                pSavedItem->SaveToStream(apBuffer);
                ++ItemUpdateArray;
            }
            pIter = pIter->FUN_00726070();
        }
        apBuffer->FUN_00865ff0(ItemUpdateArray, uiStart);
    }
}
}  // namespace fnv_00975840

struct FUN_0084cbf0_shell
{
    unsigned int flags;
    void SetFlag20(bool set);
};

// Sets or clears bit 0x20 in the flags word at offset 0x244 based on the set argument.
// @fnv 0x0084cbf0
void FUN_0084cbf0_shell::SetFlag20(bool set)
{
    if (set)
        ((unsigned int*)((char*)this + 0x244))[0] |= 0x20;
    else
        ((unsigned int*)((char*)this + 0x244))[0] &= 0xffffffdf;
}

namespace fnv_0084ced0 {
class TESGlobal;
struct BGSReconstructFormsInAllFilesMap
{
  public:
    void FUN_00843630(TESGlobal*, int);
};
struct BGSSaveLoadGame
{
  public:
    BGSReconstructFormsInAllFilesMap* _FNV_GetObjectReference();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class TESDataHandler
{
  public:
    BSSimpleList<TESGlobal*>* GetTESGlobalList();
};
struct DH : public TESDataHandler
{
};
extern DH* g_dataHandler;
struct ListStub
{
  public:
    TESGlobal** _ref_006815c0();
    ListStub* _ref_00726070();
};
// Iterates the data handler's TESGlobal list and calls FUN_00843630 on each global through the save-load reconstruct map.
// @fnv 0x0084ced0
void ReconstructAllGlobals()
{
    BSSimpleList<TESGlobal*>* pGlobalList;
    BGSReconstructFormsInAllFilesMap* pReconstructMap;
    pReconstructMap = g_BGSSaveLoadGame->_FNV_GetObjectReference();
    pGlobalList = g_dataHandler->GetTESGlobalList();
    while (pGlobalList)
    {
        TESGlobal* pglobal;
        pglobal = *((ListStub*)pGlobalList)->_ref_006815c0();
        pReconstructMap->FUN_00843630(pglobal, 0);
        pGlobalList = (BSSimpleList<TESGlobal*>*)((ListStub*)pGlobalList)->_ref_00726070();
    }
}
}  // namespace fnv_0084ced0

union LLD_SettingValue
{
    bool b;
    float f;
    const char* s;
};
class LLD_INISettingCollection;
template <class T> class LLD_SettingT
{
  public:
    LLD_SettingValue* Bool();
    const char* String();
};
extern LLD_SettingT<LLD_INISettingCollection> g_011e08e0;
extern LLD_SettingT<LLD_INISettingCollection> g_011de25c;
struct LLD_Point3
{
    float x;
    float y;
    float z;
    LLD_Point3();
};
struct LLD_FullName
{
    const char* GetFullName();
};
struct LLD_FullNameLen
{
    unsigned int GetModelLength();
};
class LLD_Cell;
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_3a();
    virtual void vfn_3b();
    virtual void vfn_3c();
    virtual void vfn_3d();
    virtual void vfn_3e();
    virtual void vfn_3f();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_4a();
    virtual void vfn_4b();
    virtual void vfn_4c();
    virtual void vfn_4d();
    virtual void vfn_4e();
    virtual void vfn_4f();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_5a();
    virtual void vfn_5b();
    virtual void vfn_5c();
    virtual void vfn_5d();
    virtual void vfn_5e();
    virtual void vfn_5f();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_6a();
    virtual void vfn_6b();
    virtual void vfn_6c();
    virtual void vfn_6d();
    virtual void vfn_6e();
    virtual void vfn_6f();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_7a();
    virtual void vfn_7b();
    virtual void vfn_7c();
    virtual const LLD_Point3& GetPos() const;
    LLD_Cell* GetParentCell();
    const LLD_Point3& GetAngle() const;
    TESWorldSpace* GetParentWorldSpace() const;
};
class LLD_Quest : public TESForm
{
  public:
    unsigned int GetFormID();
};
class LLD_PlayerCharacter : public TESObjectREFR
{
  public:
    void FUN_0093c200(LLD_Point3, LLD_Point3, LLD_Cell*, bool);
    void FUN_0093cce0(LLD_Point3, LLD_Point3, TESWorldSpace*, bool);
    void FUN_0093db60(int, LLD_Cell*);
    void SetCameraPathEnabled(bool, unsigned int);
};
class LLD_Cell
{
  public:
    NiNode* FUN_00545cb0();
    void RemoveReference(TESObjectREFR*);
};
struct LLD_WorldSpaceHelper
{
    bool IsFlag8Set();
    bool ContainsPoint(LLD_Point3*);
    LLD_Cell* GetCellAtGridPosition(int, int);
    LLD_Cell* FUN_00585b30(int, int);
};
struct LLD_TESHelper
{
    void AssignWorldSpace(TESWorldSpace*);
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    int FindCellAtPosition(const LLD_Point3*, bool);
    void RefreshWorldState(int, TESForm*, int);
    void FUN_00454450(LLD_Point3*);
    void FUN_004539a0(bool, int);
};
class LLD_DataHandler
{
  public:
    BSSimpleList<LLD_Quest*>* GetTESQuestList();
    LLD_Cell* GetOrCreateCell(int, int, TESWorldSpace*, bool);
    LLD_Cell* FUN_00461330(int, int, int, TESWorldSpace*);
};
class LLD_SaveLoadGame
{
  public:
    void SetFlag20(bool);
    void FUN_0084cc40(bool);
};
class LLD_LoadingMenu
{
  public:
    static void LoadGame(BGSLoadGameBuffer*);
};
int __fastcall FNV_GetFormType(TESForm*);
int __cdecl TruncateFloatToInt(float);
void __cdecl FUN_0084cbd0(const char*, ...);
char* __cdecl FUN_00ec7750(const char*, const char*);
unsigned int __cdecl FUN_00ec8d08(const char*, char**, int);
void __cdecl FUN_00868d70(int);
void __cdecl FUN_00c459d0(int);
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
class TESDataHandler;
extern TESDataHandler* g_dataHandler;
class BGSSaveLoadGame;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x0084c5a0
void LoadPlayerLocation(BGSLoadGameBuffer* apLoadGameBuffer)
{
    TESForm* plocation;
    TESWorldSpace* ptesWorldSpace;
    int icurrentGridY;
    unsigned int inextID;
    int icurrentGridX;
    bool bvalidPlayerLocation;

    apLoadGameBuffer->ReadDataBlock(&inextID, 4);
    ptesWorldSpace = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(apLoadGameBuffer->ReadFormIdentifier()));
    apLoadGameBuffer->ReadDataBlock(&icurrentGridX, 4);
    apLoadGameBuffer->ReadDataBlock(&icurrentGridY, 4);
    plocation = TESForm::GetFormByID(apLoadGameBuffer->ReadFormIdentifier());
    LLD_Point3 playerLocation;
    apLoadGameBuffer->ReadDataBlock(&playerLocation, 12);
    LLD_LoadingMenu::LoadGame(apLoadGameBuffer);
    bvalidPlayerLocation = true;

    if (plocation)
    {
        if (FNV_GetFormType(plocation) == 0x39)
        {
            LLD_Cell* pcell = (LLD_Cell*)plocation;
            if (((LLD_PlayerCharacter*)g_thePlayer)->GetParentCell() != pcell)
                ((LLD_PlayerCharacter*)g_thePlayer)
                    ->FUN_0093c200(playerLocation, ((LLD_PlayerCharacter*)g_thePlayer)->GetAngle(), pcell, false);
            if (ptesWorldSpace)
                ((LLD_TESHelper*)g_TES)->AssignWorldSpace(ptesWorldSpace);
            ((LLD_TESHelper*)g_TES)->SetCurrentGridX(icurrentGridX);
            ((LLD_TESHelper*)g_TES)->SetCurrentGridY(icurrentGridY);
        }
        else if (FNV_GetFormType(plocation) == 0x41)
        {
            if (ptesWorldSpace)
                ((LLD_TESHelper*)g_TES)->AssignWorldSpace(ptesWorldSpace);
            TESWorldSpace* pworld = (TESWorldSpace*)plocation;
            if (((LLD_WorldSpaceHelper*)pworld)->IsFlag8Set() && g_011e08e0.Bool()->b &&
                !((LLD_WorldSpaceHelper*)pworld)->ContainsPoint(&playerLocation))
                bvalidPlayerLocation = false;
            if (bvalidPlayerLocation)
            {
                LLD_Point3 centerGridLocation;
                int icellX;
                LLD_Cell* pcell;
                int icellY;
                centerGridLocation.x = (float)(icurrentGridX << 12);
                centerGridLocation.y = (float)(icurrentGridY << 12);
                centerGridLocation.z = 0.0f;
                ((LLD_TESHelper*)g_TES)->FindCellAtPosition(&centerGridLocation, false);
                ((LLD_TESHelper*)g_TES)->RefreshWorldState(1, plocation, 0);
                icellX = TruncateFloatToInt(playerLocation.x) >> 12;
                icellY = TruncateFloatToInt(playerLocation.y) >> 12;
                pcell = ((LLD_DataHandler*)g_dataHandler)->GetOrCreateCell(icellX, icellY, pworld, false);
                if (!pcell || !pcell->FUN_00545cb0())
                {
                    if (((LLD_PlayerCharacter*)g_thePlayer)->GetParentCell())
                        ((LLD_PlayerCharacter*)g_thePlayer)
                            ->GetParentCell()
                            ->RemoveReference((LLD_PlayerCharacter*)g_thePlayer);
                    ((LLD_TESHelper*)g_TES)->FUN_00454450(&centerGridLocation);
                    pcell = ((LLD_DataHandler*)g_dataHandler)->GetOrCreateCell(icellX, icellY, pworld, true);
                }
                if (pcell)
                {
                    ((LLD_SaveLoadGame*)g_BGSSaveLoadGame)->SetFlag20(true);
                    ((LLD_PlayerCharacter*)g_thePlayer)
                        ->FUN_0093c200(playerLocation, ((LLD_PlayerCharacter*)g_thePlayer)->GetAngle(), pcell, false);
                    ((LLD_SaveLoadGame*)g_BGSSaveLoadGame)->SetFlag20(false);
                }
                else
                    bvalidPlayerLocation = false;
            }
        }
        else
            bvalidPlayerLocation = false;
    }
    else
        bvalidPlayerLocation = false;

    if (!bvalidPlayerLocation)
    {
        unsigned int isafeMarkerID;
        TESObjectREFR* pref;
        ((LLD_SaveLoadGame*)g_BGSSaveLoadGame)->FUN_0084cc40(true);
        BSSimpleList<LLD_Quest*>* pIter = ((LLD_DataHandler*)g_dataHandler)->GetTESQuestList();
        while (pIter && pIter->GetItem())
        {
            FUN_0084cbd0("Quest %s (%08x) compared to Patch04Debug\n",
                         ((LLD_FullName*)((char*)pIter->GetItem() + 0x30))->GetFullName(),
                         pIter->GetItem()->GetFormID());
            if (((LLD_FullNameLen*)((char*)pIter->GetItem() + 0x30))->GetModelLength() > 8 &&
                FUN_00ec7750(((LLD_FullName*)((char*)pIter->GetItem() + 0x30))->GetFullName(), "Patch04Debug"))
            {
                *(LLD_Quest**)((char*)g_thePlayer + 0xe4c) = pIter->GetItem();
                break;
            }
            pIter = pIter->GetNext();
        }
        ((LLD_PlayerCharacter*)g_thePlayer)->SetCameraPathEnabled(false, 0xff);
        isafeMarkerID = FUN_00ec8d08(g_011de25c.String(), 0, 16);
        pref = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(isafeMarkerID));
        if (pref)
        {
            LLD_Point3 loc = pref->GetPos();
            LLD_Point3 angle = pref->GetAngle();
            LLD_Cell* pcell = pref->GetParentCell();
            TESWorldSpace* pworld = pref->GetParentWorldSpace();
            bvalidPlayerLocation = true;
            if (pworld)
                ((LLD_PlayerCharacter*)g_thePlayer)->FUN_0093cce0(loc, angle, pworld, true);
            else if (pcell)
                ((LLD_PlayerCharacter*)g_thePlayer)->FUN_0093c200(loc, angle, pcell, true);
            else
                bvalidPlayerLocation = false;
        }
        if (!bvalidPlayerLocation)
        {
            TESWorldSpace* pworld = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(0xda726));
            if (pworld)
            {
                LLD_Cell* pcell = ((LLD_WorldSpaceHelper*)pworld)->GetCellAtGridPosition(-18, 0);
                if (!pcell)
                    pcell = ((LLD_WorldSpaceHelper*)pworld)->FUN_00585b30(-18, 0);
                if (!pcell)
                    pcell = ((LLD_WorldSpaceHelper*)pworld)->GetCellAtGridPosition(0, 0);
                if (!pcell)
                    pcell = ((LLD_WorldSpaceHelper*)pworld)->FUN_00585b30(0, 0);
                if (!pcell)
                    pcell = ((LLD_DataHandler*)g_dataHandler)->FUN_00461330(0, 0, 0, pworld);
                if (pcell)
                    ((LLD_PlayerCharacter*)g_thePlayer)->FUN_0093db60(0, pcell);
            }
        }
    }

    ((LLD_TESHelper*)g_TES)->FUN_004539a0(true, 0);
    FUN_00868d70(0);
    FUN_00c459d0(0);
}

class B84C490Form;

struct B84C490Point3
{
    float x;
    float y;
    float z;
};

class B84C490SaveBuffer
{
  public:
    void SaveData(void* pvData, int iSize, int iFlags);
    void SerializeFormData(B84C490Form* pkForm, int iFlags);
};

class B84C490DataHandler
{
  public:
    unsigned int GetField208();
};

class B84C490TES
{
  public:
    B84C490Form* GetParentWorldSpace();
    unsigned int GetGridX();
    int GetGridY();
};

class B84C490Player
{
  public:
    B84C490Form* GetParentCell();
    const B84C490Point3* GetPos();
};

B84C490Form* __fastcall FUN_00575d70(B84C490Player* pkRef);
void __cdecl SaveLoadScreenData(B84C490SaveBuffer* pkBuffer);

extern B84C490DataHandler* g_pkB84C490DataHandler;
extern B84C490TES* g_pkB84C490TES;
extern B84C490Player* g_pkB84C490Player;

// @fnv 0x0084c490
void __cdecl SavePlayerLocation(B84C490SaveBuffer* pkBuffer)
{
    unsigned int ItemUpdateArray = g_pkB84C490DataHandler->GetField208();
    pkBuffer->SaveData(&ItemUpdateArray, 4, 0);
    pkBuffer->SerializeFormData(g_pkB84C490TES->GetParentWorldSpace(), 0);
    unsigned int uiGridX = g_pkB84C490TES->GetGridX();
    int iGridY = g_pkB84C490TES->GetGridY();
    pkBuffer->SaveData(&uiGridX, 4, 0);
    pkBuffer->SaveData(&iGridY, 4, 0);
    B84C490Form* pkWorldSpace2 = FUN_00575d70(g_pkB84C490Player);
    if (!pkWorldSpace2)
        pkWorldSpace2 = g_pkB84C490Player->GetParentCell();
    pkBuffer->SerializeFormData(pkWorldSpace2, 0);
    B84C490Point3 kPos = *g_pkB84C490Player->GetPos();
    pkBuffer->SaveData(&kPos, 12, 0);
    SaveLoadScreenData(pkBuffer);
}

void __cdecl SavePlayerLocation(BGSSaveFormBuffer*);
void __cdecl FUN_007066d0(BGSSaveFormBuffer*);
void __cdecl SaveImageSpaceModifierInstances(BGSSaveFormBuffer*);
void __cdecl SaveMiscStats(BGSSaveFormBuffer*);
void __cdecl SaveE6D0Items(BGSSaveFormBuffer*);
void __cdecl FUN_008366e0(BGSSaveFormBuffer*);
void __cdecl FUN_0082ec40(BGSSaveFormBuffer*);
void __cdecl FUN_00845cc0(const char*, ...);
struct TES84
{
    void SaveGridState(BGSSaveFormBuffer*);
};
struct Manager84
{
    void FUN_00975840(BGSSaveFormBuffer*);
    void FUN_004534f0(BGSSaveFormBuffer*);
};
struct World84
{
    void FUN_009932d0(BGSSaveFormBuffer*);
};
struct Sky84
{
    void FUN_0063eb70(BGSSaveFormBuffer*);
};
Sky84* __cdecl FUN_0046dd00();
// Dispatches saving of global data to a handler based on the type id, logging an error and returning false for unknown types.
// @fnv 0x0084bcd0
bool __cdecl FUN_0084bcd0(unsigned int type, BGSSaveFormBuffer* buffer)
{
    switch (type)
    {
    case 1:
        SavePlayerLocation(buffer);
        return true;
    case 2:
        ((TES84*)g_TES)->SaveGridState(buffer);
        return true;
    case 3:
        FUN_0084cc90(buffer);
        return true;
    case 4:
        ((Manager84*)&g_011e0e80)->FUN_00975840(buffer);
        return true;
    case 5:
        ((World84*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_009932d0(buffer);
        return true;
    case 6:
        FUN_007066d0(buffer);
        return true;
    case 7:
        SaveImageSpaceModifierInstances(buffer);
        return true;
    case 0:
        SaveMiscStats(buffer);
        return true;
    case 8:
        FUN_0046dd00()->FUN_0063eb70(buffer);
        return true;
    case 9:
        SaveE6D0Items(buffer);
        return true;
    case 10:
        FUN_008366e0(buffer);
        return true;
    case 11:
        FUN_0082ec40(buffer);
        return true;
    case 1000:
        ((Manager84*)&g_011e0e80)->FUN_004534f0(buffer);
        return true;
    default:
        FUN_00845cc0("SAVELOAD: Unknown global data type %i in SaveGlobalData()", type);
        return false;
    }
}

struct TESGlobalEx : public TESGlobal
{
    bool IsConstant() const;
    void SetValue(float value);
};

struct SaveLoadChangeHistory
{
    void AddGlobal(TESGlobal* global, int flags);
};

struct GlobalSeenMap
{
    GlobalSeenMap(int hashSize);
    ~GlobalSeenMap();
    void SetAt(TESGlobal* key, bool value);
    bool RemoveAt(TESGlobal* key);
    void* GetFirstPos();
    void GetNext(void*& pos, TESGlobal*& key, bool& value);
    int vtbl;
    int hashSize;
    int buckets;
    int count;
};

// @fnv 0x0084cd40
void FUN_0084cd40(BGSLoadGameBuffer* pLoadBuffer)
{
    SaveLoadChangeHistory* history5 = g_BGSSaveLoadGame->GetHistory();
    GlobalSeenMap unchanged2(37);
    GlobalListNode* node2 = g_dataHandler->GetTESGlobalList();
    while (node2)
    {
        TESGlobal* globalVal = node2->FUN_006815c0();
        if (globalVal)
            unchanged2.SetAt(globalVal, true);
        node2 = node2->FUN_00726070();
    }
    {
        unsigned int count8 = pLoadBuffer->ReadElementCount();
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            TESGlobal* loaded =
                dynamic_cast<TESGlobal*>(TESForm::GetFormByID(pLoadBuffer->ReadFormIdentifier()));
            float value9 = 0.0f;
            pLoadBuffer->ReadDataBlock(&value9, 4);
            if (loaded)
            {
                if (!static_cast<TESGlobalEx*>(loaded)->IsConstant())
                    static_cast<TESGlobalEx*>(loaded)->SetValue(value9);
                unchanged2.RemoveAt(loaded);
            }
        }
    }
    void* pos2 = unchanged2.GetFirstPos();
    while (pos2)
    {
        TESGlobal* key3 = 0;
        bool seen4 = false;
        unchanged2.GetNext(pos2, key3, seen4);
        if (!static_cast<TESGlobalEx*>(key3)->IsConstant())
            history5->AddGlobal(key3, 0);
    }
}

struct NiBound
{
    float FUN_0084d030();
};

struct NiTimeController
{
    int FUN_00441110();
};

struct FUN_00865df0_buf
{
    void FUN_00865df0(void* apForm, int aiFlags);
};

struct FUN_00529990_Class
{
    static double GetTime();
};

struct FUN_0047c860_Class
{
    double __thiscall FUN_0047c860();
};

// @fnv 0x0084cf30
void __cdecl SaveImageSpaceModifierInstances(int pBuffer)
{
    int aV11;
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* i6;
    int v3;
    ImageSpaceModifierInstance* v8_2;
    void* v2;
    float aV6;
    float v5;

    v3 = 0;
    aV11 = ((BGSSaveFormBuffer*)pBuffer)->FUN_00865f20();
    i6 = g_TES->FUN_0043b5d0();
    while (i6 != 0)
    {
        v8_2 = i6->GetItem().operator->();
        if (v8_2 != 0 && !v8_2->IsFlagSet())
        {
            v2 = (void*)(*(int(__thiscall**)(int))(*(int*)v8_2 + 148))((int)v8_2);
            if (v2 != 0)
            {
                aV6 = ((NiBound*)v2)->FUN_0084d030();
                ((BGSSaveFormBuffer*)pBuffer)->SaveData(&aV6, 4, 0);
                v5 = (float)(FUN_00529990_Class::GetTime() - ((FUN_0047c860_Class*)v2)->FUN_0047c860());
                ((BGSSaveFormBuffer*)pBuffer)->SaveData(&v5, 4, 0);
                ((FUN_00865df0_buf*)pBuffer)->FUN_00865df0((void*)((NiTimeController*)v2)->FUN_00441110(), 0);
                ++v3;
            }
        }
        i6 = i6->GetNext();
    }
    ((BGSSaveFormBuffer*)pBuffer)->FUN_00865ff0(v3, aV11);
}

#include <stdarg.h>
void __cdecl FUN_00ecbe60(const char* fmt, va_list args);

// @fnv 0x0084cbd0
void __cdecl FUN_0084cbd0(const char* apFormat, ...)
{
    va_list args;
    va_start(args, apFormat);
    FUN_00ecbe60(apFormat, args);
}

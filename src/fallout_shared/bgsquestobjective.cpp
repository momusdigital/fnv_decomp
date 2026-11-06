// fallout_shared/bgsquestobjective.cpp: BGSQuestObjective, StandIn (15 functions)

#include "bgsquestobjective_decls.h"
// If not yet initialized, stores quest and calls InitItem on each entry of the target list, then marks the objective initialized.
// @fnv 0x005ec210
void BGSQuestObjective::InitItem(TESQuest* quest)
{
    if (bInitialized)
        return;
    m_pOwnerQuest = quest;
    BSSimpleList<RegionObjectEntry*>* targets = GetTargetList();
    while (targets && !reinterpret_cast<BSSimpleList<const char*>*>(targets)->IsEmpty())
    {
        reinterpret_cast<RegionObjectEntry*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(targets)->GetItem())
            ->InitItem(reinterpret_cast<TESForm*>(quest));
        targets = reinterpret_cast<BSSimpleList<RegionObjectEntry*>*>(
            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(targets)->GetNext());
    }
    bInitialized = true;
}

// @fnv 0x005ec1b0
void BGSQuestObjective::Initialize()
{
    iIndex = 0;
    m_kDisplayText = g_emptyTopicInfoPrompt;
    bInitialized = false;
    state = 0;
    m_pOwnerQuest = 0;
}

struct RecursiveSpinLock
{
    RecursiveSpinLock();
    ~RecursiveSpinLock();
    int pad[2];
};
struct StrMem
{
    StrMem();
    ~StrMem();
    int pad[3];
};
struct InitStub
{
    void Initialize();
};
struct FUN_005ec090
{
    FUN_005ec090();
    virtual void vfn_0();
    unsigned int iIndex;
    StrMem m_kDisplayText;
    RecursiveSpinLock lock;
};
// @fnv 0x005ec090
FUN_005ec090::FUN_005ec090()
{
    ((InitStub*)this)->Initialize();
}

struct FUN_005ec330_shell : public BGSQuestObjective
{
    char* GetPromptText();
};

struct StrH
{
    operator const char*() const;
};
// Returns the string stored at offset 8 of this objective, or g_emptyTopicInfoPrompt when that string is empty.
// @fnv 0x005ec330
char* FUN_005ec330_shell::GetPromptText()
{
    return (char*)((const char*)*(StrH*)((char*)this + 8) ? (const char*)*(StrH*)((char*)this + 8)
                                                          : g_emptyTopicInfoPrompt);
}

struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
struct TESForm;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct TESFile
{
    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTESFile(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsValidFileVersion();
    unsigned int GetFORMSize();
    char* GetPath();
    char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool CheckMasterFiles(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void SetCurrentForm(TESForm*);
    void ResetCurrentForm();
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool HasNextForm();
    void RewindForm();
    int GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int ReadFileBuffer(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();
    void* __vecDelDtor(unsigned int);
    int m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    void* m_pThreadSafeFileMap;
    BSFile* m_pSecondaryFile;
    BSFile* m_pFile;
    TESBitArrayFile* m_pBitArrayFile1;
    TESBitArrayFile* m_pBitArrayFile2;
    TESBitArrayFile* m_pBitArrayFile3;
    char m_acFilename[260];
    char m_acPath[260];
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiReadPosition;
    unsigned int m_uiBufferSize;
    TESObjectCELL* m_pCurrentCell;
    unsigned int m_uiFormCount;
    char m_kRecordInfo[24];
    int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    char m_kChunkInfo[24];
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    char m_kRecordList[8];
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    char _pad_29b[1];
    char m_kFindData[320];
    char m_kFileMetadata[12];
    unsigned int m_uiFileCount;
    char m_kFilenameList[8];
    char m_kFileSizeList[8];
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    char m_kLastWriteTime[8];
    unsigned char m_ucCompileIndex;
    char _pad_40d[3];
    char m_kCreator[8];
    char m_kSummary[8];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;
    char _pad_42b[1];
};
typedef char _sizecheck_TESFile[sizeof(TESFile) == 1068 ? 1 : -1];
struct FUN_005ec370_shell : public BGSQuestObjective
{
    void Load(TESFile*);
};

extern "C" void* __cdecl _alloca(unsigned int);
struct S_005ec440
{
    void FUN_005ec440(char*);
};
// Reads chunks from apFile: stores the QOBJ chunk's int in iIndex, and on the NNAM chunk passes its data (or null) to FUN_005ec440, then returns.
// @fnv 0x005ec370
void FUN_005ec370_shell::Load(TESFile* apFile)
{
    int chunkid;
    while ((chunkid = apFile->ReadCurrentForm()) != 0)
    {
        switch (chunkid)
        {
        case 0x4a424f51:
            apFile->GetChunkData(&iIndex);
            break;
        case 0x4d414e4e:
            if (apFile->GetChunkSize())
            {
                char* pMessage = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(pMessage, 0);
                ((S_005ec440*)this)->FUN_005ec440(pMessage);
            }
            else
            {
                ((S_005ec440*)this)->FUN_005ec440(0);
            }
            return;
        }
        if (!apFile->NextChunk())
            break;
    }
}

struct FUN_005ec500_shell : public BGSQuestObjective
{
    void AddMatchingTargetsToList(void*);
};

struct QObjOps
{
    int _FNV_GetObjectReference();
};
struct ListOps
{
    RegionObjectEntry** _ref_006815c0();
    ListOps* _ref_00726070();
};
struct TgtOps
{
    void* GetReference(bool);
    bool IsFlagSet();
    void* GetSourceFiles();
    void* GetPosition();
};
struct CondOps
{
    bool ContainsTrait(void*, int);
};
struct PlayerOps
{
    void FUN_00952d60(void*, void*, int);
};
struct OutList
{
    void AddTail(RegionObjectEntry**);
};
extern PlayerOps* g_thePlayer;

// If the objective's object reference is 1, walks the target list and appends targets whose condition passes to apListToFill, calling the player op on each.
// @fnv 0x005ec500
void FUN_005ec500_shell::AddMatchingTargetsToList(void* apListToFill)
{
    if (((QObjOps*)this)->_FNV_GetObjectReference() != 1)
        return;
    ListOps* pMasterList = (ListOps*)((BGSQuestObjective*)this)->GetTargetList();
    RegionObjectEntry* pTarget = 0;
    while (pMasterList && *pMasterList->_ref_006815c0())
    {
        pTarget = *pMasterList->_ref_006815c0();
        pMasterList = pMasterList->_ref_00726070();
        if (((CondOps*)((TgtOps*)pTarget)->GetPosition())->ContainsTrait(((TgtOps*)pTarget)->GetReference(0), 0))
        {
            g_thePlayer->FUN_00952d60(((TgtOps*)pTarget)->GetReference(1), ((TgtOps*)pTarget)->GetSourceFiles(),
                                      ((TgtOps*)pTarget)->IsFlagSet());
            ((OutList*)apListToFill)->AddTail(&pTarget);
        }
    }
}

struct S7010
{
    unsigned int Length();
};

struct FUN_005ec310_shell
{
    unsigned int GetLength();
};

// @fnv 0x005ec310
unsigned int FUN_005ec310_shell::GetLength()
{
    return ((S7010*)((char*)this + 8))->Length();
}

void __cdecl _Deallocate(void*);
struct S_005ec110
{
    void FUN_005ec140();
    void* FUN_005ec110(unsigned int);
};
// Calls FUN_005ec140, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005ec110
void* S_005ec110::FUN_005ec110(unsigned int flags)
{
    FUN_005ec140();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct StandIn
{
    void FUN_0060ffe0();
    void* FUN_005ec4d0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0060ffe0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005ec4d0
void* StandIn::FUN_005ec4d0(unsigned int flags)
{
    FUN_0060ffe0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005ec1f0_shell
{
    void FUN_005ec460();
    void FUN_005ec1f0();
};

// @fnv 0x005ec1f0
void FUN_005ec1f0_shell::FUN_005ec1f0()
{
    FUN_005ec460();
}

struct BSStr
{
    bool Set(const char*, unsigned int);
};

struct FUN_005ec440
{
    char pad[8];
    BSStr m_str;  // +0x08
    void Set(const char* name);
};

// @fnv 0x005ec440
void FUN_005ec440::Set(const char* name)
{
    m_str.Set(name, 0);
}

namespace fnv_005ec280 {
struct FUN_00485910_shell
{
    static void __cdecl FUN_00485910(int, void*);
};
struct FUN_004856f0_shell
{
    static void __cdecl FUN_004856f0(int, const char*, unsigned int);
};
struct FUN_005ec310_shell
{
    unsigned int GetLength();
};
struct FUN_005ec330_shell
{
    const char* GetPromptText();
};
struct Date
{
    ~Date();
};
struct FUN_005ec280_shell
{
    void FUN_005ec280();
};
// @fnv 0x005ec280
void FUN_005ec280_shell::FUN_005ec280()
{
    FUN_00485910_shell::FUN_00485910(0x4a424f51, ((BSSimpleList<RegionObjectEntry*>*)this)->GetNext());
    FUN_004856f0_shell::FUN_004856f0(0x4d414e4e, ((FUN_005ec330_shell*)this)->GetPromptText(),
                                     ((FUN_005ec310_shell*)this)->GetLength() + 1);
    BSSimpleList<RegionObjectEntry*>* list = ((BGSQuestObjective*)this)->GetTargetList();
    while (list && !list->IsEmpty())
    {
        ((Date*)list->GetItem())->Date::~Date();
        list = list->GetNext();
    }
}
}  // namespace fnv_005ec280

namespace fnv_005ec5d0 {
enum QUEST_OBJECTIVE_STATE
{
    QUEST_OBJECTIVE_STATE_0 = 0,
    QUEST_OBJECTIVE_STATE_1 = 1,
    QUEST_OBJECTIVE_STATE_3 = 3
};

struct BSAudio
{
    int GetAudioBackendData();
};

struct TESQuest
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void FUN_005ec000(unsigned int);

    bool GetCompleted();
    void SetEnabled(bool);
};

struct TESFaction_RankDataView
{
    bool HasFlag20();
};

struct FUN_005ec700_shell
{
    void SetFlag20(bool);
};

struct FUN_005ec330_shell
{
    char const* GetDisplayText();
};

struct Obj_009529d0
{
    void FUN_009529d0(int);
};

struct FUN_00952a20_shell
{
    void FUN_00952a20(BGSQuestObjective*);
};

struct PlayerCharacter : Obj_009529d0
{
};

extern PlayerCharacter* _g_thePlayer;

int __fastcall FUN_005cbb50(char*);
void __cdecl FUN_0077a480(void*);
void __cdecl FUN_0077a5b0(char const*, int, int);

struct FUN_005ec5d0_shell : BGSQuestObjective
{
    void FUN_005ec5d0(QUEST_OBJECTIVE_STATE);
};

// @fnv 0x005ec5d0
void FUN_005ec5d0_shell::FUN_005ec5d0(QUEST_OBJECTIVE_STATE aeNewState)
{
    TESQuest* powner = reinterpret_cast<TESQuest*>(reinterpret_cast<BSAudio*>(this)->GetAudioBackendData());

    powner->FUN_005ec000(0x20000000);

    if (aeNewState == QUEST_OBJECTIVE_STATE_1 || state == 0)
    {
        if (aeNewState == QUEST_OBJECTIVE_STATE_1)
        {
            if (!powner->GetCompleted())
            {
                powner->SetEnabled(true);
                if (!FUN_005cbb50(reinterpret_cast<char*>(_g_thePlayer)))
                {
                    reinterpret_cast<Obj_009529d0*>(_g_thePlayer)->FUN_009529d0(reinterpret_cast<int>(powner));
                }
            }

            FUN_0077a5b0(reinterpret_cast<FUN_005ec330_shell*>(this)->GetDisplayText(), 0, 0);

            if (!reinterpret_cast<TESFaction_RankDataView*>(powner)->HasFlag20())
            {
                FUN_0077a480(powner);
                reinterpret_cast<FUN_005ec700_shell*>(powner)->SetFlag20(true);
            }
        }

        reinterpret_cast<FUN_00952a20_shell*>(_g_thePlayer)->FUN_00952a20(this);
    }

    if (aeNewState == QUEST_OBJECTIVE_STATE_3 && state == QUEST_OBJECTIVE_STATE_1 && !powner->GetCompleted())
    {
        FUN_0077a5b0(reinterpret_cast<FUN_005ec330_shell*>(this)->GetDisplayText(), 1, 0);
    }

    state = aeNewState;
}
}  // namespace fnv_005ec5d0

struct FUN_005ec140
{
    virtual void vfn_0();
    unsigned int iIndex;
    StrMem m_kDisplayText;
    RecursiveSpinLock lock;
    void FUN_005ec1f0();
    ~FUN_005ec140();
};
// @fnv 0x005ec140
FUN_005ec140::~FUN_005ec140()
{
    FUN_005ec1f0();
}

struct FUN_005ec460_List
{
    bool FUN_008256d0();
    StandIn** FUN_006815c0();
    void FUN_0063f7b0();
};
struct FUN_005ec460_Owner
{
    FUN_005ec460_List* FUN_007d6bb0();
    void FUN_005ec460();
};
// @fnv 0x005ec460
void FUN_005ec460_Owner::FUN_005ec460()
{
    FUN_005ec460_List* list = FUN_007d6bb0();
    while (list && !list->FUN_008256d0())
    {
        StandIn* target = *list->FUN_006815c0();
        StandIn* deletionTarget = target;
        deletionTarget ? deletionTarget->FUN_005ec4d0(1) : 0;
        list->FUN_0063f7b0();
    }
}

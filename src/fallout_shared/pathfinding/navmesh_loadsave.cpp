// fallout_shared/pathfinding/navmesh_loadsave.cpp: NavMesh, TESForm, NavMeshStandIn, BSSimpleArrayActor and more (34 functions)

#include "navmesh_loadsave_decls.h"

// Public PC annotation: JohnnyGuitar TESForm.cpp, GAME 0x693EF0.
// @fnv 0x00693ef0
void TESForm::SetCollisionDisabled(bool noCollision)
{
    if (noCollision)
        m_uiFormFlags |= 0x10;
    else
        m_uiFormFlags &= ~0x10;
}

// TESForm/NavMesh PC slot 74 both bind the base SetRefID body to 00485c10.
// @fnv 0x006942c0
void NavMesh::ForceSetFormID(unsigned int formID)
{
    TESForm::SetRefID(formID, false);
}

// @fnv 0x00693e60
void NavMesh::InitItem()
{
    if (GetDisabled())
        ((TESForm*)FUN_0068efb0())->SetCollisionDisabled(true);
    if (IsDeleted())
    {
        bool altered = g_TES->GetActiveCell()->FUN_00460340();
        SetDeletionState(false);
        g_TES->GetActiveCell()->SetAltered(altered);
    }
    else
        InitializeNavMeshData();
}

// @fnv 0x006942e0
void NavMesh::CopyNavMeshDataTo(NavMeshPtr& copy)
{
    copy->m_pOwningCell = m_pOwningCell;
    Vertices.CopyFlagsTo(&copy->Vertices);
    Triangles.FUN_00694ea0(&copy->Triangles);
    m_kEdgeExtraInfo.FUN_00694f20(&copy->m_kEdgeExtraInfo);
    m_kIndexList.FUN_00694f80(&copy->m_kIndexList);
    m_kGrid.FUN_0069dd50(&copy->m_kGrid);
    m_kObstacleUndoData.FUN_00694fe0(&copy->m_kObstacleUndoData);
    m_kClosedDoorInfo.FUN_00695040(&copy->m_kClosedDoorInfo);
    void* pos = ((NavMeshObstacleMap*)pTriangleToObstacleMap)->GetFirstPos();
    while (pos)
    {
        unsigned short triangle;
        NiPointer<ObstacleData> m_spRegisteredObstacle(0);
        ((NavMeshObstacleMap*)pTriangleToObstacleMap)->FUN_006947e0(pos, triangle, m_spRegisteredObstacle);
        ((NavMeshObstacleMap*)copy->pTriangleToObstacleMap)->FUN_006946a0(triangle, m_spRegisteredObstacle);
    }
    pos = ((NavMeshPOVMap*)&POVPointerArray)->GetFirstPos();
    while (pos)
    {
        NavMeshPOVData POV;
        unsigned short key;
        ((NavMeshPOVMap*)&POVPointerArray)->FUN_00694d30(pos, key, POV);
        ((NavMeshPOVMap*)&copy->POVPointerArray)->InsertOrUpdate(key, POV);
    }
    m_kAdditionalIndexList.FUN_00694f80(&copy->m_kAdditionalIndexList);
    m_kAdditionalData.FUN_00694f80(&copy->m_kAdditionalData);
    copy->m_pNavigationMesh = 0;
}

struct FUN_00693b70_shell : public NavMeshTriangle
{
    bool HasFlag40();
};

// @fnv 0x00693b70
bool FUN_00693b70_shell::HasFlag40()
{
    return (*(unsigned int*)((char*)this + 0xc) & 0x40) != 0;
}

struct S00693b90
{
    bool FUN_00691140(unsigned int);
    bool FUN_00693b90();
};
// @fnv 0x00693b90
bool S00693b90::FUN_00693b90()
{
    return FUN_00691140(0x10);
}

extern unsigned int DAT_0106b0dc;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x00694e10
void __fastcall FUN_00694e10(GlobalObject_00869f00* pThis)
{
    *(unsigned int**)pThis = &DAT_0106b0dc;
    pThis->Clear(true);
}

struct E00694f20
{
    int a, b, c;
    void Assign(const E00694f20&);
};
struct DA00694f20
{
    int x;
    E00694f20* data;
    unsigned int count;
    E00694f20* FUN_006a1440(unsigned int);
    void FUN_00694b10(unsigned int, int);
};
struct SA00694f20
{
    int x;
    E00694f20* data;
    unsigned int count;
    void FUN_00694f20(DA00694f20* dest);
};
// @fnv 0x00694f20
void SA00694f20::FUN_00694f20(DA00694f20* dest)
{
    dest->FUN_00694b10(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->FUN_006a1440(i)->Assign(data[i]);
}

struct DA00694f80
{
    int x;
    unsigned short* data;
    unsigned int count;
    unsigned short& GetAt(int);
    void SetSize(unsigned int, bool);
};
struct SA00694f80
{
    int x;
    unsigned short* data;
    unsigned int count;
    void FUN_00694f80(DA00694f80* dest);
};
// Resizes dest to this container's count and copies each element from data into dest via GetAt.
// @fnv 0x00694f80
void SA00694f80::FUN_00694f80(DA00694f80* dest)
{
    dest->SetSize(count, true);
    for (unsigned int i = 0; i < count; i++)
        dest->GetAt(i) = data[i];
}

struct NN00694fe0
{
    int p;
    NN00694fe0& operator=(const NN00694fe0&);
};
struct DA00694fe0
{
    int x;
    NN00694fe0* data;
    unsigned int count;
    NN00694fe0& GetAt(unsigned int);
    void FUN_00695230(unsigned int, int);
};
struct SA00694fe0
{
    int x;
    NN00694fe0* data;
    unsigned int count;
    void FUN_00694fe0(DA00694fe0* dest);
};
// @fnv 0x00694fe0
void SA00694fe0::FUN_00694fe0(DA00694fe0* dest)
{
    dest->FUN_00695230(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetAt(i) = data[i];
}

struct TwoIntRecord
{
    int a, b;
    void FUN_FNVH(const TwoIntRecord&);
};
struct DA00695040
{
    int x;
    TwoIntRecord* data;
    unsigned int count;
    TwoIntRecord* GetElement(unsigned int);
    void FUN_006950f0(unsigned int, int);
};
struct SA00695040
{
    int x;
    TwoIntRecord* data;
    unsigned int count;
    void FUN_00695040(DA00695040* dest);
};
// @fnv 0x00695040
void SA00695040::FUN_00695040(DA00695040* dest)
{
    dest->FUN_006950f0(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetElement(i)->FUN_FNVH(data[i]);
}

struct E006950d0
{
    int a;
    int b;
};
struct S006950d0
{
    int x;
    E006950d0* data;
    E006950d0* GetElement(unsigned int i);
};
// @fnv 0x006950d0
E006950d0* S006950d0::GetElement(unsigned int uiIndex)
{
    return &data[uiIndex];
}

struct Item00694c50
{
    Item00694c50* next;
    unsigned short key;
};
struct Map00694c50
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short);
    virtual bool IsKeysEqual(unsigned short, unsigned short);
    virtual void SetValue(Item00694c50*, unsigned short, unsigned int);
    virtual void v10();
    virtual Item00694c50* NewItem();
    unsigned int size;
    Item00694c50** buckets;
    unsigned int count;
    void InsertOrUpdate(unsigned short key, unsigned int val);
};
// Looks up key in the hash bucket; updates the existing item's value or inserts a new item at the bucket head and increments count.
// @fnv 0x00694c50
void Map00694c50::InsertOrUpdate(unsigned short key, unsigned int auiValue)
{
    unsigned int uiIndex;
    unsigned int uiDepth;
    Item00694c50* pkItem;
    uiIndex = KeyToHashIndex(key);
    pkItem = buckets[uiIndex];
    uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (IsKeysEqual(key, pkItem->key))
        {
            *(unsigned int*)((char*)pkItem + 6) = auiValue;
            return;
        }
        pkItem = pkItem->next;
    }
    pkItem = NewItem();
    SetValue(pkItem, key, auiValue);
    pkItem->next = buckets[uiIndex];
    buckets[uiIndex] = pkItem;
    count++;
}

struct POV00694d30
{
    unsigned int d;
};
struct Item00694d30
{
    Item00694d30* next;
    unsigned short key;
};
struct Map00694d30
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short);
    unsigned int size;
    Item00694d30** buckets;
    void FUN_00694d30(Item00694d30** pos, unsigned short* key, POV00694d30* val);
};
// Reads the key and value of the entry at *pos, then advances *pos to the next entry or the next non-empty bucket, or null at the end.
// @fnv 0x00694d30
void Map00694d30::FUN_00694d30(Item00694d30** pos, unsigned short* key, POV00694d30* val)
{
    Item00694d30* pkItem = *pos;
    *key = pkItem->key;
    *val = *(POV00694d30*)((char*)pkItem + 6);
    if (pkItem->next)
    {
        *pos = pkItem->next;
        return;
    }
    unsigned int uiIndex = KeyToHashIndex(pkItem->key);
    for (uiIndex = uiIndex + 1; uiIndex < size; uiIndex++)
    {
        pkItem = buckets[uiIndex];
        if (pkItem)
        {
            *pos = pkItem;
            return;
        }
    }
    *pos = 0;
}

struct V12
{
    int a;
    int b;
    int c;
};
struct FUN_00694890_t
{
    void FUN_00694890(unsigned int, int);
};
namespace fnv_006a7af0 {
struct S3e60
{
    int x;
    V12* data;
    unsigned int count;
    V12& GetFlag(unsigned int) const;
};
}
struct S00694e30
{
    int x;
    V12* data;
    unsigned int count;
    void CopyFlagsTo(fnv_006a7af0::S3e60* dest);
};
// Calls FUN_00694890 on dest with count and 1, then copies each of the count entries from data into dest via GetFlag.
// @fnv 0x00694e30
void S00694e30::CopyFlagsTo(fnv_006a7af0::S3e60* dest)
{
    ((FUN_00694890_t*)dest)->FUN_00694890(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetFlag(i) = data[i];
}

struct V16
{
    int a;
    int b;
    int c;
    int d;
};
struct FUN_006949d0_t
{
    void FUN_006949d0(unsigned int, int);
};
struct S006949d0
{
    int x;
    V16* data;
    unsigned int count;
    V16& GetAt(int) const;
};
struct S00694ea0
{
    int x;
    V16* data;
    unsigned int count;
    void FUN_00694ea0(S006949d0* dest);
};
// @fnv 0x00694ea0
void S00694ea0::FUN_00694ea0(S006949d0* dest)
{
    ((FUN_006949d0_t*)dest)->FUN_006949d0(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetAt(i) = data[i];
}

// Clamps the unsigned short pointed to by a into the range [b, c].
// @fnv 0x00694660
void ClampUnsignedShort(unsigned short* pusValue, unsigned short usMin, unsigned short usMax)
{
    if (*pusValue > usMax)
        *pusValue = usMax;
    else if (*pusValue < usMin)
        *pusValue = usMin;
}

void __fastcall FUN_00694e10(void*);
void _Deallocate(void*);

struct FUN_006950a0_shell
{
    void* FUN_006950a0(unsigned int flags);
};

// Calls FUN_00694e10 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x006950a0
void* FUN_006950a0_shell::FUN_006950a0(unsigned int flags)
{
    FUN_00694e10(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00694b10 {
struct S5460
{
    void FUN_006a2770(unsigned int, unsigned int);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct FUN_00692320_shell
{
    void ConstructEntries(void*, unsigned int);
};
struct FUN_00694b10_shell
{
    void* vtbl;
    void* p;
    unsigned int allocated;
    unsigned int capacity;
    void FUN_00694b10(unsigned int size, bool flag);
};
// @fnv 0x00694b10
void FUN_00694b10_shell::FUN_00694b10(unsigned int size, bool abShrink)
{
    if (size == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abShrink);
    }
    else if (size > capacity)
    {
        if (capacity == 0)
        {
            p = ((void*(__thiscall*)(void*, unsigned int))((void**)vtbl)[1])(this, size);
            capacity = size;
        }
        else
        {
            ((S5460*)this)->FUN_006a2770(size, allocated);
            capacity = size;
        }
        ((FUN_00692320_shell*)this)->ConstructEntries((char*)p + allocated * 0xc, size - allocated);
        allocated = size;
    }
    else if (size < allocated)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80((char*)p + size * 0xc, allocated - size);
        allocated = size;
        if (abShrink && size <= capacity / 4)
        {
            ((S5460*)this)->FUN_006a2770(size, size);
            capacity = size;
        }
    }
    else
    {
        ((FUN_00692320_shell*)this)->ConstructEntries((char*)p + allocated * 0xc, size - allocated);
        allocated = size;
    }
}
}  // namespace fnv_00694b10

namespace fnv_006bc8e0 {
struct FUN_00694890_t
{
    void FUN_00694890(unsigned int, int);
};
struct FUN_006949d0_t
{
    void FUN_006949d0(unsigned int, int);
};
struct S006bebd0
{
    void FUN_006bebd0();
};
struct InnerB006bc8e0
{
    char _0[0x10];
    unsigned int v10;
    char _1[4];
    unsigned int v18;
};
struct InnerA006bc8e0
{
    char _0[0x28];
    FUN_00694890_t o28;
    char _1[15];
    FUN_006949d0_t o38;
};
struct Host006bc8e0
{
    InnerA006bc8e0* p0;
    int _4;
    InnerB006bc8e0* p8;
    bool FUN_006bc8e0(InnerA006bc8e0*, InnerB006bc8e0*);
};
// Stores the two inner pointers, calls FUN_006bebd0, then forwards b's v10 and v18 to the two sub-objects with flag 1 and returns true.
// @fnv 0x006bc8e0
bool Host006bc8e0::FUN_006bc8e0(InnerA006bc8e0* pInnerA, InnerB006bc8e0* pInnerB)
{
    p0 = pInnerA;
    p8 = pInnerB;
    ((S006bebd0*)this)->FUN_006bebd0();
    p0->o28.FUN_00694890(p8->v10, 1);
    p0->o38.FUN_006949d0(p8->v18, 1);
    return true;
}
}  // namespace fnv_006bc8e0

struct NavMeshStandIn
{
    char pad[0x24];
    TESForm* m_pOwningCell;
    void FUN_00694090(bool abVal);
};
// @fnv 0x00694090
void NavMeshStandIn::FUN_00694090(bool abVal)
{
    ((TESForm*)this)->TESForm::SetAltered(abVal);
    if (abVal && m_pOwningCell)
        m_pOwningCell->SetAltered(true);
}

struct BGSLoadFormBuffer
{
};
struct FUN_00694620_shell : TESForm
{
    char _pad[0x104 - sizeof(TESForm)];
    TESForm* m_pNavigationMesh;
    void FinishLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x00694620
void FUN_00694620_shell::FinishLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (m_pNavigationMesh != 0)
        m_pNavigationMesh->SetCollisionDisabled(GetDisabled());
}

namespace fnv_00692950 {
struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct NavMeshInfo;
struct TESBitArrayFile;
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
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct NavMeshSaveDataHeader
{
    void Endian();
    unsigned int m_uiField0;
    unsigned int VertexCount;
    unsigned int GetTriangleTotal;
    unsigned int m_uiField3;
    unsigned int m_uiField4;
    unsigned int m_uiField5;
};
typedef char _sizecheck_NavMeshSaveStruct[sizeof(NavMeshSaveDataHeader) == 24 ? 1 : -1];
struct NavMeshInfoSaveData
{
    static unsigned int GetSaveSize();
    float m_fValue;
    NavMeshInfo* m_pNavMeshInfo;
    unsigned int m_uiDoorFormID;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
    int m_iValue6;
    int PAD4_1;
    int PAD4_2;
    unsigned short m_usTriangleIdentifier;
    char _pad_2e[2];
};
typedef char _sizecheck_EdgeExtraInfoOLD[sizeof(NavMeshInfoSaveData) == 48 ? 1 : -1];
struct FUN_00692950_shell : public NavMesh
{
    bool Load(TESFile*);
};

extern "C" void* __cdecl _alloca(unsigned int);
void* operator new(unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(int*, EndianSizeTag<4>);
void BSEndian(unsigned short*, EndianSizeTag<2>);
int Warning(const char*, ...);
void* memcpy(void*, const void*, unsigned int);
struct EdgeExtraInfoOLDNoPad
{
    float m_fValue;
    NavMeshInfo* m_pNavMeshInfo;
    unsigned int m_uiDoorFormID;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
    int m_iValue6;
    int PAD4_1;
    int PAD4_2;
    unsigned short m_usTriangleIdentifier;
};
struct FUN_00694de0
{
    FUN_00694de0();
    ~FUN_00694de0();
    void* vtbl;
    int* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
};
struct NavMeshPortalIndexArray
{
    unsigned int Add(NavMesh* const&);
};
struct Flt
{
    operator unsigned int() const;
};
TESForm* GetFormByID(unsigned int);

struct AutoMemHelper
{
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int m_eMemoryContext;
};
struct SeqObj
{
    void FUN_00401970();
};
struct G00559a40
{
    void FUN_0040f6e0();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct LS3de0
{
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct ContainerItemExtraFileData
{
    void Endian();
};
struct BSXFlags_shell
{
    void ClearFlags(unsigned int);
};
struct ActiveEffect
{
    void FUN_00693d50(float);
};
struct TESRecipe
{
    void SetCategory(unsigned int);
};
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct PathingS
{
    NavMeshInfo* FindReferenceByFormId(unsigned int);
};
struct VertArr
{
    ContainerItemExtraFileData* FUN_006a1440(unsigned int);
};
struct EdgeS
{
    void FUN_0069d240(TESFile*, char*);
    void ReadFromFile(TESFile*, char*);
    unsigned int FUN_00693d10();
    unsigned int FUN_00693cd0();
};
struct EdgeArr
{
    EdgeS* FUN_006a1440(unsigned int);
};
struct DoorS
{
    unsigned int DoorRef;
    unsigned short m_usTriangleIdentifier;
    void FUN_004141e0();
};
struct DoorArr
{
    DoorS* GetElement(unsigned int);
    void FUN_00844c90(unsigned int, int);
};
struct TriS
{
    bool HasFlag40();
    bool FUN_00693b90();
    void FUN_00693bb0();
    void FUN_00693c10();
    void FUN_00693bd0(int);
    bool FUN_00690e10();
    bool IsEdgeFlagSet(int);
    unsigned short FUN_0068f2c0(int);
};
struct TriArr
{
    TriS& FUN_00558dd0(int);
};
struct FUN_00694890_t
{
    void FUN_00694890(unsigned int, int);
};
struct FUN_006949d0_t
{
    void FUN_006949d0(unsigned int, int);
};
struct DA00694f20
{
    void FUN_00694b10(unsigned int, int);
};
struct DA00694f80
{
    void SetSize(unsigned int, bool);
    unsigned short& GetBufferEntry(int);
};
struct DA00695040
{
    void FUN_006950f0(unsigned int, int);
};
struct GridS
{
    bool LoadRecord(void*, unsigned int, TESFile*);
};
struct InfoMapS
{
    void FUN_006b6990(unsigned int);
};
struct NavMeshS
{
    TriS* FUN_005582f0(unsigned short);
    EdgeExtraInfo* GetEdge(unsigned short);
    void FUN_006959b0();
    void RebuildTriangleList();
    void UpdateTriangleExtraInfo(unsigned short);
    TESForm* GetDoorForm();
    void FUN_006986d0();
    void Validate(bool);
};
unsigned int FUN_00693db0();
TESForm* __fastcall FUN_00690830(const NavMeshInfo*);
extern TESObjectCELL* DAT_011c3f30;
extern ProcessLists g_011d6ca8;

// Reads a NavMesh record from a TESFile, parsing subrecords, converting old versions, and resolving the parent cell and NavMeshInfo.
// @fnv 0x00692950
bool FUN_00692950_shell::Load(TESFile* apFile)
{
    AutoMemHelper tempMemContext(
        0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMesh_LoadSave.cpp", 0x113);
    if (((TESForm*)this)->IsDeleted())
    {
        ((SeqObj*)((char*)this + 0x1c))->FUN_00401970();
        return false;
    }
    unsigned char formid;
    formid = apFile->GetTESForm();
    if (formid != 0x43)
        return false;
    ((TESForm*)this)->LoadRecordHeader((::TESFile*)apFile);
    FUN_00694de0 oldDoorPortalIndices;
    int ifileVersionNumber = 1;
    bool bbadNavMesh = false;
    if (!((TESForm*)this)->IsDeleted())
    {
        char* pMessage;
        NavMeshSaveDataHeader saveStruct;
        do
        {
            switch (apFile->ReadCurrentForm())
            {
            case 0x44494445:  // EDID
                pMessage = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(pMessage, 0x200);
                ((TESForm*)this)->SetEditorID_AtRuntime(pMessage);
                break;
            case 0x444e424f:  // OBND
                ((TESForm*)this)->readOBNDSubRecord((::TESFile*)apFile);
                break;
            case 0x5245564e:  // NVER
                apFile->GetChunkData(&ifileVersionNumber, 4);
                if (apFile->QEndian())
                    BSEndian(&ifileVersionNumber, EndianSizeTag<4>());
                break;
            case 0x41544144:  // DATA
                if (ifileVersionNumber < 5)
                {
                    apFile->GetChunkData(&saveStruct, 0x14);
                    saveStruct.m_uiField5 = 0;
                }
                else
                {
                    apFile->GetChunkData(&saveStruct, 0x18);
                }
                if (apFile->QEndian())
                    saveStruct.Endian();
                if (saveStruct.GetTriangleTotal >= 0x10000000)
                {
                    saveStruct.GetTriangleTotal -= 0x10000000;
                    bbadNavMesh = true;
                }
                ((FUN_00694890_t*)((char*)this + 0x28))->FUN_00694890(saveStruct.VertexCount, 1);
                ((FUN_006949d0_t*)((char*)this + 0x38))->FUN_006949d0(saveStruct.GetTriangleTotal, 1);
                ((DA00694f20*)((char*)this + 0x48))->FUN_00694b10(saveStruct.m_uiField3, 1);
                ((DA00694f80*)((char*)this + 0x78))->SetSize(saveStruct.m_uiField4, true);
                ((DA00695040*)((char*)this + 0x58))->FUN_006950f0(saveStruct.m_uiField5, 1);
                TESForm::RemapFormIDForFile(saveStruct.m_uiField0, (::TESFile*)apFile);
                *(TESObjectCELL**)((char*)this + 0x24) =
                    dynamic_cast<TESObjectCELL*>(GetFormByID(saveStruct.m_uiField0));
                if (!*(TESObjectCELL**)((char*)this + 0x24))
                {
                    Warning("CELL: Could not find parent cell (%08X) for NavMesh (%08X).", saveStruct.m_uiField0,
                            ((TESForm*)this)->GetFormID());
                    if (DAT_011c3f30)
                    {
                        Warning("CELL: Attempting to remap NavMesh parent to cell (%08X) instead.",
                                ((TESForm*)DAT_011c3f30)->GetFormID());
                        *(TESObjectCELL**)((char*)this + 0x24) = DAT_011c3f30;
                    }
                }
                break;
            case 0x5856564e:  // NVVX
                apFile->GetChunkData(((VertArr*)((char*)this + 0x28))->FUN_006a1440(0),
                                     ((ArrSI*)((char*)this + 0x28))->GetFlags() * 12);
                if (apFile->QEndian())
                {
                    unsigned int isize = ((ArrSI*)((char*)this + 0x28))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                        ((VertArr*)((char*)this + 0x28))->FUN_006a1440(i)->Endian();
                }
                break;
            case 0x4143564e:  // NVCA
                apFile->GetChunkData(&((DA00694f80*)((char*)this + 0x78))->GetBufferEntry(0),
                                     ((ArrSI*)((char*)this + 0x78))->GetFlags() * 2);
                if (apFile->QEndian())
                {
                    unsigned int isize = ((ArrSI*)((char*)this + 0x78))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                        BSEndian(&((DA00694f80*)((char*)this + 0x78))->GetBufferEntry(i), EndianSizeTag<2>());
                }
                break;
            case 0x5044564e:  // NVDP
            {
                int isize = ((ArrSI*)((char*)this + 0x58))->GetFlags();
                apFile->GetChunkData(((DoorArr*)((char*)this + 0x58))->GetElement(0), isize * 8);
                for (int i = 0; i < isize; ++i)
                {
                    if (apFile->QEndian())
                        ((DoorArr*)((char*)this + 0x58))->GetElement(i)->FUN_004141e0();
                    unsigned int idoorID = ((DoorArr*)((char*)this + 0x58))->GetElement(i)->DoorRef;
                    TESForm::RemapFormIDForFile(idoorID, (::TESFile*)apFile);
                    TESObjectREFR* pdoor = (TESObjectREFR*)GetFormByID(idoorID);
                    if (pdoor)
                    {
                        ((DoorArr*)((char*)this + 0x58))->GetElement(i)->DoorRef = (unsigned int)pdoor;
                    }
                    else
                    {
                        BSStringT<char> navmeshString;
                        ((TESForm*)this)->GetDebugName(&navmeshString);
                        Warning(
                            "NavMesh: Door reference %08X is not found but is linked to %s.  Please finalize to resolve this.",
                            idoorID, (unsigned int)(const Flt&)navmeshString);
                        unsigned int itriIndex =
                            ((DoorArr*)((char*)this + 0x58))->GetElement(i)->m_usTriangleIdentifier;
                        if (itriIndex < ((ArrSI*)((char*)this + 0x38))->GetFlags())
                            ((BSXFlags_shell&)((TriArr*)((char*)this + 0x38))->FUN_00558dd0(itriIndex))
                                .ClearFlags(0x400);
                        ((DoorArr*)((char*)this + 0x58))->FUN_00844c90(i, 1);
                        --i;
                        --isize;
                    }
                }
            }
            break;
            case 0x5254564e:  // NVTR
            {
                apFile->GetChunkData(&((TriArr*)((char*)this + 0x38))->FUN_00558dd0(0),
                                     ((ArrSI*)((char*)this + 0x38))->GetFlags() * 16);
                unsigned int isize = ((ArrSI*)((char*)this + 0x38))->GetFlags();
                for (unsigned int i = 0; i < isize; ++i)
                {
                    if (apFile->QEndian())
                        ((TriArr*)((char*)this + 0x38))->FUN_00558dd0(i).FUN_00693c10();
                    ((TriArr*)((char*)this + 0x38))->FUN_00558dd0(i).FUN_00693bd0(0);
                }
            }
            break;
            case 0x4447564e:  // NVGD
            {
                unsigned int ichunkSize = apFile->GetChunkSize();
                void* pchunkData = operator new(ichunkSize);
                apFile->GetChunkData(pchunkData, ichunkSize);
                if (!((GridS*)((char*)this + 0xa8))->LoadRecord(pchunkData, ichunkSize, apFile))
                {
                    BSStringT<char> navmeshString;
                    ((TESForm*)this)->GetDebugName(&navmeshString);
                    Warning("MASTERFILE: Navmesh %s has a bad navmesh grid, please touch and resave",
                            (unsigned int)(const Flt&)navmeshString);
                    ((NavMeshS*)this)->FUN_006959b0();
                }
                operator delete(pchunkData);
            }
            break;
            case 0x5845564e:  // NVEX
            {
                unsigned int ichunksize = apFile->GetChunkSize();
                void* pchunkdata = operator new(ichunksize);
                apFile->GetChunkData(pchunkdata, ichunksize);
                char* pchunkPointer = (char*)pchunkdata;
                if (ifileVersionNumber < 5)
                {
                    unsigned int isize = ((ArrSI*)((char*)this + 0x48))->GetFlags();
                    EdgeExtraInfoOLDNoPad oldFormat;
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        memcpy(&oldFormat, pchunkPointer, 0x30);
                        if (oldFormat.m_uiDoorFormID)
                            ((NavMeshPortalIndexArray*)&oldDoorPortalIndices)->Add((NavMesh*)i);
                        char newFormat[48];
                        char* pbufferLoc = newFormat;
                        *(NavMeshInfo**)pbufferLoc = oldFormat.m_pNavMeshInfo;
                        pbufferLoc += 4;
                        *(unsigned short*)pbufferLoc = oldFormat.m_usTriangleIdentifier;
                        ((EdgeArr*)((char*)this + 0x48))->FUN_006a1440(i)->FUN_0069d240(apFile, newFormat);
                        pchunkPointer += FUN_00693db0();
                    }
                }
                else if (ifileVersionNumber < 9)
                {
                    unsigned int isize = ((ArrSI*)((char*)this + 0x48))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        ((EdgeArr*)((char*)this + 0x48))->FUN_006a1440(i)->FUN_0069d240(apFile, pchunkPointer);
                        pchunkPointer += ((EdgeArr*)((char*)this + 0x48))->FUN_006a1440(i)->FUN_00693d10();
                    }
                }
                else
                {
                    unsigned int isize = ((ArrSI*)((char*)this + 0x48))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        ((EdgeArr*)((char*)this + 0x48))->FUN_006a1440(i)->ReadFromFile(apFile, pchunkPointer);
                        pchunkPointer += ((EdgeArr*)((char*)this + 0x48))->FUN_006a1440(i)->FUN_00693cd0();
                    }
                }
                operator delete(pchunkdata);
            }
            break;
            }
        } while (apFile->NextChunk());
    }

    if (bbadNavMesh)
    {
        BSStringT<char> navmeshString;
        ((TESForm*)this)->GetDebugName(&navmeshString);
        Warning("MASTERFILE: %s has unresolved warnings and will not be loaded.",
                (unsigned int)(const Flt&)navmeshString);
        ((NavMesh*)this)->SetDeletionState(true);
        *(NavMeshInfo**)((char*)this + 0x104) = 0;
        *(TESObjectCELL**)((char*)this + 0x24) = 0;
        ((TESForm*)this)->TESForm::MarkForDeletion(true);
    }
    if (((TESForm*)this)->IsDeleted())
    {
        ((G00559a40*)((char*)this + 0x1c))->FUN_0040f6e0();
        ((InfoMapS*)g_TES->GetActiveCell())->FUN_006b6990(((TESForm*)this)->GetFormID());
        return false;
    }
    if (*(NavMeshInfo**)((char*)this + 0x104))
        *(NavMeshInfo**)((char*)this + 0x104) = 0;

    if (!((TESForm*)this)->IsDeleted())
    {
        if (ifileVersionNumber < 5)
        {
            if (((ArrSI*)&oldDoorPortalIndices)->GetFlags() > 0)
            {
                BSStringT<char> navmeshString;
                ((TESForm*)this)->GetDebugName(&navmeshString);
                Warning(
                    "Depreciated NavMesh Door Portals found in %s, removing portals, please refinalize cell to create new door portals",
                    (unsigned int)(const Flt&)navmeshString);
            }
            unsigned int isize = ((ArrSI*)&oldDoorPortalIndices)->GetFlags();
            for (int i = isize - 1; i >= 0; --i)
            {
                int imodified = *((Arr*)&oldDoorPortalIndices)->GetAt(i);
                ((NavMeshS*)this)->UpdateTriangleExtraInfo((unsigned short)imodified);
            }
        }
        if (ifileVersionNumber < 6)
        {
            bool bcoverMessedUp = false;
            unsigned int isize = ((ArrSI*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = ((NavMeshS*)this)->FUN_005582f0((unsigned short)i);
            }
            ((NavMeshS*)this)->RebuildTriangleList();
            if (bcoverMessedUp)
            {
                BSStringT<char> navmeshString;
                ((TESForm*)this)->GetDebugName(&navmeshString);
                Warning("%s had cover that could not be converted to the new format, please check and fix",
                        ((TESForm*)this)->GetFormID(), (unsigned int)(const Flt&)navmeshString);
            }
        }
        if (ifileVersionNumber < 8)
        {
            unsigned int isize = ((ArrSI*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = ((NavMeshS*)this)->FUN_005582f0((unsigned short)i);
                if (ptri->FUN_00693b90())
                    ptri->FUN_00693bb0();
            }
        }
        if (!g_TES->GetActiveCell())
            return false;
        *(NavMeshInfo**)((char*)this + 0x104) =
            ((PathingS*)g_TES->GetActiveCell())->FindReferenceByFormId(((TESForm*)this)->GetFormID());
        if (!*(NavMeshInfo**)((char*)this + 0x104))
        {
            Warning("MASTERFILE: Did not find matching NavMeshInfo for NavMesh ID %08X, Creating a temporary one",
                    ((TESForm*)this)->GetFormID());
            ((NavMeshS*)this)->FUN_006986d0();
        }
        else
        {
            if (!FUN_00690830(*(NavMeshInfo**)((char*)this + 0x104)))
                *(unsigned int*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 4) =
                    ((NavMeshS*)this)->GetDoorForm()->GetFormID();
            ((TESRecipe*)*(NavMeshInfo**)((char*)this + 0x104))->SetCategory((unsigned int)this);
        }
        if (ifileVersionNumber < 10)
        {
            unsigned int isize = ((ArrSI*)((char*)this + 0x38))->GetFlags();
            unsigned int ipreferredTris = 0;
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = ((NavMeshS*)this)->FUN_005582f0((unsigned short)i);
                if (ptri->HasFlag40())
                    ++ipreferredTris;
            }
            if (*(NavMeshInfo**)((char*)this + 0x104) && isize)
                ((ActiveEffect*)*(NavMeshInfo**)((char*)this + 0x104))
                    ->FUN_00693d50((float)ipreferredTris / (float)isize);
        }
        if (ifileVersionNumber < 11)
        {
            unsigned int isize = ((ArrSI*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = ((NavMeshS*)this)->FUN_005582f0((unsigned short)i);
                if (ptri->HasFlag40())
                {
                    if (!ptri->FUN_00690e10())
                        continue;
                    for (int e = 0; e < 3; ++e)
                    {
                        if (!ptri->IsEdgeFlagSet(e))
                            continue;
                        EdgeExtraInfo* pinfo;
                        unsigned short extraInfoIndex = ptri->FUN_0068f2c0(e);
                        pinfo = ((NavMeshS*)this)->GetEdge(extraInfoIndex);
                        if (!*(NavMeshInfo**)((char*)this + 0x104))
                            continue;
                        for (unsigned int j = 0;
                             j < ((ArrSI*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))->GetFlags(); ++j)
                        {
                            if (*((Arr*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))->GetAt(j) ==
                                (unsigned int)pinfo->Portal.m_pNavMeshInfo)
                            {
                                ((LS3de0*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))
                                    ->UpdateEntryValue(j, 1);
                                ((NavMeshPortalIndexArray*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x34))
                                    ->Add((NavMesh* const&)pinfo->Portal.m_pNavMeshInfo);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((*g_011d6ca8.GetLifeStateControlFlag() || !apFile->IsMasterFile()) && !((TESForm*)this)->IsDeleted())
        ((NavMeshS*)this)->Validate(false);
    return true;
}
}  // namespace fnv_00692950

struct BSSimpleArrayActor
{
    virtual ~BSSimpleArrayActor();
    virtual int* FUN_alloc1(unsigned int);

    void Clear(bool);
};

BSSimpleArrayActor::~BSSimpleArrayActor()
{}

struct FUN_006dc590 : public BSSimpleArrayActor
{
    void FUN_006dc590_(unsigned int, unsigned int);
};

struct FUN_0069b310_S : public FUN_006dc590
{
    void ConstructBounds(void*, int);
};

struct FUN_0072ba80_shell : public FUN_0069b310_S
{
    void FUN_0072ba80(char*, unsigned int);
};

struct FUN_00694890_shell : public FUN_0072ba80_shell
{
    int* data;
    unsigned int count;
    unsigned int capacity;

    void FUN_00694890(unsigned int, bool);
};

// @fnv 0x00694890
void FUN_00694890_shell::FUN_00694890(unsigned int newCount, bool reset)
{
    if (newCount == 0)
    {
        this->Clear(reset);
    }
    else if (newCount > this->capacity)
    {
        if (this->capacity == 0)
        {
            this->data = this->FUN_alloc1(newCount);
            this->capacity = newCount;
        }
        else
        {
            this->FUN_006dc590_(newCount, this->count);
            this->capacity = newCount;
        }

        this->ConstructBounds(reinterpret_cast<void*>(reinterpret_cast<char*>(this->data) + this->count * 12),
                              static_cast<int>(newCount - this->count));
        this->count = newCount;
    }
    else if (newCount < this->count)
    {
        this->FUN_0072ba80(reinterpret_cast<char*>(this->data) + newCount * 12, this->count - newCount);
        this->count = newCount;

        if (reset && newCount <= this->capacity / 4)
        {
            this->FUN_006dc590_(newCount, newCount);
            this->capacity = newCount;
        }
    }
    else
    {
        this->ConstructBounds(reinterpret_cast<void*>(reinterpret_cast<char*>(this->data) + this->count * 12),
                              static_cast<int>(newCount - this->count));
        this->count = newCount;
    }
}

namespace fnv_006949d0 {
struct Arr16
{
    void FUN_00644490(int, int);
};

struct BSSimpleArrayActor
{
    virtual ~BSSimpleArrayActor()
    {}
    virtual char* Allocate(unsigned int);

    void Clear(bool);

    char* m_data;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
};

struct S5460 : public BSSimpleArrayActor
{
    void FUN_009f6540(unsigned int, unsigned int);
    void FUN_006949d0(unsigned int, bool);
};

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(char*, unsigned int);
};

// @fnv 0x006949d0
void S5460::FUN_006949d0(unsigned int uiNewSize, bool bShrinkCapacity)
{
    if (uiNewSize == 0)
    {
        Clear(bShrinkCapacity);
        return;
    }

    if (uiNewSize > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = Allocate(uiNewSize);
            m_pRayCursor = uiNewSize;
        }
        else
        {
            FUN_009f6540(uiNewSize, m_uiItemCount);
            m_pRayCursor = uiNewSize;
        }

        reinterpret_cast<Arr16*>(this)->FUN_00644490(reinterpret_cast<int>(m_data + m_uiItemCount * 16),
                                                     uiNewSize - m_uiItemCount);
        m_uiItemCount = uiNewSize;
    }
    else if (uiNewSize < m_uiItemCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_data + uiNewSize * 16, m_uiItemCount - uiNewSize);
        m_uiItemCount = uiNewSize;

        if (bShrinkCapacity && uiNewSize <= m_pRayCursor / 4)
        {
            FUN_009f6540(uiNewSize, uiNewSize);
            m_pRayCursor = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<Arr16*>(this)->FUN_00644490(reinterpret_cast<int>(m_data + m_uiItemCount * 16),
                                                     uiNewSize - m_uiItemCount);
        m_uiItemCount = uiNewSize;
    }
}
}  // namespace fnv_006949d0

namespace fnv_006950f0 {
struct BSSimpleArrayActor
{
    virtual void* FUN_006950f0_v0();
    virtual int* FUN_006950f0_v1(unsigned int);
    void Clear(bool);

    int* m_data;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
};

struct FUN_0069b030_S : public BSSimpleArrayActor
{
    void ConstructPairCells(int, unsigned int);
};

struct S5460 : public FUN_0069b030_S
{
    void FUN_006a2770(unsigned int, unsigned int);
};

struct FUN_0072ba80_shell : public S5460
{
    void FUN_0072ba80(char*, unsigned int);
    void FUN_006950f0(unsigned int, bool);
};

// @fnv 0x006950f0
void FUN_0072ba80_shell::FUN_006950f0(unsigned int size, bool clear)
{
    if (size == 0)
    {
        this->BSSimpleArrayActor::Clear(clear);
        return;
    }

    if (size > this->m_pRayCursor)
    {
        if (this->m_pRayCursor == 0)
        {
            this->m_data = this->FUN_006950f0_v1(size);
            this->m_pRayCursor = size;
        }
        else
        {
            this->S5460::FUN_006a2770(size, this->m_uiItemCount);
            this->m_pRayCursor = size;
        }

        this->FUN_0069b030_S::ConstructPairCells(
            reinterpret_cast<int>(reinterpret_cast<char*>(this->m_data) + this->m_uiItemCount * 8),
            size - this->m_uiItemCount);
        this->m_uiItemCount = size;
        return;
    }

    if (size < this->m_uiItemCount)
    {
        this->FUN_0072ba80_shell::FUN_0072ba80(reinterpret_cast<char*>(this->m_data) + size * 8,
                                               this->m_uiItemCount - size);
        this->m_uiItemCount = size;

        if (clear && size <= (this->m_pRayCursor >> 2))
        {
            this->S5460::FUN_006a2770(size, size);
            this->m_pRayCursor = size;
        }
        return;
    }

    this->FUN_0069b030_S::ConstructPairCells(
        reinterpret_cast<int>(reinterpret_cast<char*>(this->m_data) + this->m_uiItemCount * 8),
        size - this->m_uiItemCount);
    this->m_uiItemCount = size;
}
}  // namespace fnv_006950f0

struct ChildCell_0068ef50
{
    virtual TESObjectCELL* FUN_0068ef50();
};
struct NavMesh_0068ef50 : TESForm, ChildCell_0068ef50
{
    TESObjectCELL* GetParentCell();
    TESObjectCELL* FUN_0068ef50();
};
typedef char _sizecheck_TESForm_0068ef50[sizeof(TESForm) == 0x18 ? 1 : -1];
// @fnv 0x0068ef50
TESObjectCELL* NavMesh_0068ef50::FUN_0068ef50()
{
    return GetParentCell();
}

struct FUN_00693f30_name
{
    FUN_00693f30_name();
    ~FUN_00693f30_name();
    const char* c_str() const;
    char* m_pData;
};

struct FUN_00693f30_obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual void vfn_90(FUN_00693f30_name* name);
};

struct FUN_00693f30_count
{
    int FUN_0044ddc0();
};

struct FUN_00693f30_cls
{
    char pad[0x38];
    FUN_00693f30_count triCount;
    FUN_00693f30_obj* FUN_0059bb30();
    unsigned int FUN_0084e3a0();
    void PrintNavMeshInfo(void* a1);
};

int FUN_00406f60(void*, const char*, ...);

// Builds a name via the nav object's vfn_90 and prints the navmesh id, triangle count and cell name through FUN_00406f60.
// @fnv 0x00693f30
void FUN_00693f30_cls::PrintNavMeshInfo(void* a1)
{
    int unk_pad;
    FUN_00693f30_name name;
    {
        FUN_00693f30_obj* nav = FUN_0059bb30();
        if (nav)
        {
            nav->vfn_90(&name);
        }
    }
    FUN_00406f60(a1, "NavMesh (%08X) with %d Triangles in Cell %s", FUN_0084e3a0(), triCount.FUN_0044ddc0(),
                 name.c_str());
}

struct FUN_00693fe0_cls;

struct Node
{
    unsigned char Test();
};

struct Res
{
    void Fin();
};

struct Mgr
{
    Res* Get(void* p);
};

extern Mgr* g_mgr;

void Bar(void* p);

struct FUN_00693fe0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32(bool flag);

    unsigned char GetA();
    Node* GetB(int arg);
    void Foo(unsigned char arg);
    void* GetC();
    void* GetD();

    void SetDelete(unsigned char arg);
};

// If arg differs from GetA, updates state via Foo and v32 based on GetB(0)->Test(); when arg is non-zero, calls Bar(GetC()) and Fin() on g_mgr->Get(GetD()).
// @fnv 0x00693fe0
void FUN_00693fe0_cls::SetDelete(unsigned char arg)
{
    bool flag;
    if (arg != GetA())
    {
        flag = true;
        Node* p = GetB(0);
        if (arg != 0)
        {
            if (!(p != 0 && p->Test() != 0))
                flag = false;
        }
        Foo(arg);
        v32(flag);
    }
    if (arg != 0)
    {
        Bar(GetC());
        g_mgr->Get(GetD())->Fin();
    }
}

struct NavMeshAction
{
    unsigned int descriptor;
    unsigned int userData;
    unsigned int triangleIndex;
    unsigned int action;
};
extern unsigned int DAT_01187020;
struct PathingService
{
    virtual void UnknownVirtual_00();
    virtual void UnknownVirtual_01();
    virtual void UnknownVirtual_02();
    virtual void UnknownVirtual_03();
    virtual void UnknownVirtual_04();
    virtual void UnknownVirtual_05();
    virtual void UnknownVirtual_06();
    virtual void UnknownVirtual_07();
    virtual void UnknownVirtual_08();
    virtual void UnknownVirtual_09();
    virtual void UnknownVirtual_0a();
    virtual void UnknownVirtual_0b();
    virtual void UnknownVirtual_0c();
    virtual void UnknownVirtual_0d();
    virtual void UnknownVirtual_0e();
    virtual void UnknownVirtual_0f();
    virtual void UnknownVirtual_10();
    virtual void UnknownVirtual_11();
    virtual void UnknownVirtual_12();
    virtual void UnknownVirtual_13();
    virtual void UnknownVirtual_14();
    virtual void UnknownVirtual_15();
    virtual void UnknownVirtual_16();
    virtual void UnknownVirtual_17();
    virtual void UnknownVirtual_18();
    virtual void UnknownVirtual_19();
    virtual void UnknownVirtual_1a();
    virtual void UnknownVirtual_1b();
    virtual void UnknownVirtual_1c();
    virtual void UnknownVirtual_1d();
    virtual void UnknownVirtual_1e();
    virtual void UnknownVirtual_1f();
    virtual void UnknownVirtual_20();
    virtual void UnknownVirtual_21();
    virtual void UnknownVirtual_22();
    virtual void UnknownVirtual_23();
    virtual void UnknownVirtual_24();
    virtual void UnknownVirtual_25();
    virtual void UnknownVirtual_26();
    virtual void UnknownVirtual_27();
    virtual void UnknownVirtual_28();
    virtual void UnknownVirtual_29();
    virtual void UnknownVirtual_2a();
    virtual void UnknownVirtual_2b();
    virtual void UnknownVirtual_2c();
    virtual void UnknownVirtual_2d();
    virtual void UnknownVirtual_2e();
    virtual void UnknownVirtual_2f();
    virtual void UnknownVirtual_30();
    virtual void UnknownVirtual_31();
    virtual void UnknownVirtual_32();
    virtual void UnknownVirtual_33();
    virtual void UnknownVirtual_34();
    virtual void UnknownVirtual_35();
    virtual void UnknownVirtual_36();
    virtual void UnknownVirtual_37();
    virtual void UnknownVirtual_38();
    virtual void UnknownVirtual_39();
    virtual void UnknownVirtual_3a();
    virtual void UnknownVirtual_3b();
    virtual void UnknownVirtual_3c();
    virtual void UnknownVirtual_3d();
    virtual void UnknownVirtual_3e();
    virtual void UnknownVirtual_3f();
    virtual void UnknownVirtual_40();
    virtual void UnknownVirtual_41();
    virtual void UnknownVirtual_42();
    virtual void UnknownVirtual_43();
    virtual unsigned char DispatchAction(NavMeshAction* action, unsigned char enabled, unsigned char option);
    unsigned char FUN_00485be0(unsigned int triangleIndex);
};
struct NavMeshActionController
{
    PathingService* FUN_0059bb30();
    unsigned char ProcessNavMeshAction(NavMeshAction* entry, unsigned char enabled, unsigned char option);
};
// Validates a NavMeshAction against DAT_01187020 and dispatches it by action type, checking the triangle for actions 6, 8 and 9.
// @fnv 0x006940e0
unsigned char NavMeshActionController::ProcessNavMeshAction(NavMeshAction* apAction, unsigned char enabled,
                                                            unsigned char option)
{
    unsigned char result = 0;
    if (apAction != 0 && apAction->descriptor == DAT_01187020)
    {
        PathingService* service = FUN_0059bb30();
        switch (apAction->action)
        {
        case 6:
            if (enabled == 0)
            {
                result = 0;
                break;
            }
        case 8:
        case 9: {
            unsigned char valid = 0;
            if (service->FUN_00485be0(apAction->triangleIndex))
                valid = 1;
            if (valid)
            {
                switch (apAction->action)
                {
                case 8:
                    result = 0;
                    break;
                default:
                    result = 1;
                    break;
                }
            }
            break;
        }
        default:
            if (enabled)
                result = service->DispatchAction(apAction, enabled, option);
            break;
        }
    }
    return result;
}

extern unsigned int DAT_01187020;

class FUN_006941c0_mid;

struct FUN_006941c0_out
{
    unsigned int vtbl;
    unsigned int unk04;
    void* unk08;
    unsigned int unk0C;
    unsigned int unk10;
};

struct FUN_006941c0_in
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    unsigned int unk0C;
};

class FUN_006941c0_mid
{
  public:
    void* GetCode();
    void* GetHandle();
};

class FUN_006941c0_cls
{
  public:
    FUN_006941c0_mid* GetMid();
    void MapHandleState(FUN_006941c0_out* out, FUN_006941c0_in* in);
};

// If out and in are non-null, checks in->unk0C (3/5/6) and in->unk08 against the mid's code or handle, filling out with DAT_01187020 and state 6 or 9.
// @fnv 0x006941c0
void FUN_006941c0_cls::MapHandleState(FUN_006941c0_out* out, FUN_006941c0_in* in)
{
    if (out != 0)
    {
        out->vtbl = 0;
        if (in != 0)
        {
            FUN_006941c0_mid* m1 = this->GetMid();
            void* h = this->GetMid()->GetHandle();
            switch (in->unk0C)
            {
            case 3:
            case 5:
                if (in->unk08 == m1->GetCode())
                {
                    out->vtbl = DAT_01187020;
                    out->unk0C = 6;
                    out->unk08 = h;
                    out->unk04 = 0;
                    out->unk10 = 0;
                }
                break;
            case 6:
                if (in->unk08 == h)
                {
                    out->vtbl = DAT_01187020;
                    out->unk0C = 9;
                    out->unk08 = this->GetMid()->GetHandle();
                    out->unk04 = 0;
                    out->unk10 = 0;
                }
                break;
            }
        }
    }
}

struct FUN_006947e0_node
{
    FUN_006947e0_node* pNext;
    unsigned short usKey;
    unsigned short unk06;
};

class FUN_006947e0_owner
{
  public:
    void FUN_006e5cc0(void* pData);
};

class FUN_006947e0_cls
{
  public:
    virtual void Unk_00(void);
    virtual int Unk_01(unsigned short key);
    unsigned int m_uiCount;
    FUN_006947e0_node** m_ppItems;

    void FUN_006947e0(FUN_006947e0_node** ppNode, unsigned short* pKey, FUN_006947e0_owner* pOwner);
};

// @fnv 0x006947e0
void FUN_006947e0_cls::FUN_006947e0(FUN_006947e0_node** ppNode, unsigned short* pKey, FUN_006947e0_owner* pOwner)
{
    FUN_006947e0_node* node = *ppNode;
    *pKey = node->usKey;
    pOwner->FUN_006e5cc0((char*)node + 8);
    if (node->pNext != 0)
    {
        *ppNode = node->pNext;
        return;
    }
    int i = Unk_01(node->usKey);
    i++;
    for (; (unsigned int)i < m_uiCount; i++)
    {
        node = m_ppItems[i];
        if (node != 0)
        {
            *ppNode = node;
            return;
        }
    }
    *ppNode = 0;
}

struct Mesh69
{
    bool FUN_00440da0();
    void FUN_00484af0(bool);
    void LinkMatchingEdges();
};
namespace Local {
struct NavMeshPtr
{
    Mesh69* value;
    NavMeshPtr();
    ~NavMeshPtr();
    Mesh69* FUN_00559450();
};
}
struct Info69
{
    bool FUN_00690860(Local::NavMeshPtr*);
    void FUN_00693ef0(bool);
};
struct Map69
{
    Info69* FUN_00693d70();
};
struct Manager69
{
    Map69* GetNavMeshInfoMap(unsigned int);
};
extern Manager69* DAT_011dea10;
void __cdecl FNV_Warning(const char*, ...);
// Looks up the NavMeshInfo for a NavMesh ID and sets its mesh disabled state, warning and returning false if the info or mesh is missing.
// @fnv 0x00694500
bool __cdecl FUN_00694500(unsigned int uiNavMeshId, bool disabled)
{
    Info69* info = DAT_011dea10->GetNavMeshInfoMap(uiNavMeshId)->FUN_00693d70();
    if (!info)
    {
        FNV_Warning("DisableNavMesh Script Function: Did not find matching NavMeshInfo for NavMesh ID parameter %08X",
                    uiNavMeshId);
        return false;
    }
    else
    {
        Local::NavMeshPtr navMeshPtr;
        if (!info->FUN_00690860(&navMeshPtr))
        {
            FNV_Warning("DisableNavMesh Script Function: Did not find matching NavMesh for NavMesh ID parameter %08X",
                        uiNavMeshId);
            return false;
        }
        else if (navMeshPtr.FUN_00559450()->FUN_00440da0() != disabled)
        {
            navMeshPtr.FUN_00559450()->FUN_00484af0(disabled);
            info->FUN_00693ef0(disabled);
            if (!disabled)
                navMeshPtr.FUN_00559450()->LinkMatchingEdges();
        }
    }
    return true;
}

struct RefObj6946a0;
struct RefPtr6946a0
{
    RefObj6946a0* m_pObject;
    RefPtr6946a0(const RefPtr6946a0&);
    ~RefPtr6946a0();
    RefPtr6946a0& operator=(const RefPtr6946a0&);
};
struct Item6946a0
{
    Item6946a0* m_pkNext;
    unsigned short m_key;
    RefPtr6946a0 m_val;
};
struct Map6946a0
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short key1, unsigned short key2);
    virtual void SetValue(Item6946a0* pkItem, unsigned short key, RefPtr6946a0 val);
    virtual void v10();
    virtual Item6946a0* NewItem();
    unsigned int m_uiHashSize;
    Item6946a0** m_ppkHashTable;
    unsigned int m_uiCount;
    void FUN_006946a0(unsigned short key, RefPtr6946a0 val);
};

// Looks up the bucket for key, updates the value if the key exists, otherwise inserts a new item and increments the count.
// @fnv 0x006946a0
void Map6946a0::FUN_006946a0(unsigned short key, RefPtr6946a0 aRefVal)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    Item6946a0* pkItem = m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (IsKeysEqual(key, pkItem->m_key))
        {
            pkItem->m_val = aRefVal;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = NewItem();
    SetValue(pkItem, key, aRefVal);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_uiCount++;
}

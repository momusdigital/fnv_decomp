// fallout_shared/region system/tesregion.cpp: TESRegion, RegionProxy, OwnQ (12 functions)

#include "tesregion_TESRegion.h"
#include "tesregion_TESRegionDataList.h"
#include "tesregion_TESRegionPointList.h"
#include "tesregion_data_types.h"
#include "tesregion_load.h"

// Clears the region's data list and deletes every point list held in the point list queue.
// @fnv 0x004f0ef0
void TESRegion::ClearData()
{
    if (m_pRegionDataList)
        m_pRegionDataList->Clear();
    if (pRegionPointList)
    {
        RegionPointList* pointList = pRegionPointList->GetItem();
        while (pointList)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = pRegionPointList->GetItem();
        }
    }
}

// @fnv 0x004f0f80
void TESRegion::InitItem()
{
    TESWorldSpace* world;
    BSSimpleList<TESRegionData*>* data;
    if (GetInitialized())
        return;
    {
        unsigned int worldID = (unsigned int)GetParentWorldSpace();
        RemapFormIDForFile(worldID, GetFile(-1));
        world = dynamic_cast<TESWorldSpace*>(GetFormByID(worldID));
    }
    if (world)
        AssignWorldSpace(world);
    SetInitializationState(true);
    data = GetRegionDataList();
    while (data && data->GetItem())
    {
        data->GetItem()->Initialize(this);
        data = data->GetNext();
    }
}

// Loads a TESRegion from a TESFile: reads the EDID/OBND/WNAM/RPLI/RPLD chunks and region-type subrecords, then prunes invalid point lists.
// @fnv 0x004f0b10
bool TESRegion::Load(TESFile* file)
{
    struct ReferenceItemCountEntry
    {
        RegionPointList* invalid;
        BSSimpleList<RegionPointList*>* lists;
        unsigned int distance;
        unsigned int worldID;
        char* editorID;
        int chunk;
        RegionPointList* pointList;
        char padding0, padding1, padding2;
        unsigned char type;
    } loadState;
    loadState.type = file->GetTESForm();
    loadState.pointList = 0;
    if (loadState.type != 55)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (loadState.chunk = file->GetChunkID())
    {
        switch (loadState.chunk)
        {
        case 0x44494445: {
            loadState.editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(loadState.editorID, 512);
            SetEditorID_AtRuntime(loadState.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e57: {
            loadState.worldID = 0;
            file->GetChunkData(&loadState.worldID);
            AssignWorldSpace((TESWorldSpace*)loadState.worldID);
            break;
        }
        case 0x494c5052: {
            loadState.distance = 0;
            file->GetChunkData(&loadState.distance);
            loadState.pointList = new RegionPointList(true);
            loadState.pointList->SetDistanceInsideAtMax(loadState.distance);
            GetRegionPointLists()->AddTail(loadState.pointList);
            break;
        }
        case 0x444c5052:
            if (loadState.pointList)
                loadState.pointList->ReadPointsFromFile(file);
            break;
        case 0x424f4452:
        case 0x42534452:
        case 0x44494452:
        case 0x44534452:
        case 0x444d4452:
        case 0x49534452:
        case 0x504d4452:
        case 0x4e4c4452:
        case 0x4a4f4452:
        case 0x4e4f4349:
        case 0x544f4452:
        case 0x53474452:
        case 0x54414452:
        case 0x54574452:
            ((TESRegionLoadHandler*)g_dataHandler)->GetRegionDataManager()->Load(file, this);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    loadState.lists = GetRegionPointLists();
    while (loadState.lists && loadState.lists->GetItem())
    {
        if (!loadState.lists->GetItem()->FUN_004f81e0(true))
        {
            loadState.invalid = loadState.lists->GetItem();
            ((TESRegionLoadList*)GetRegionPointLists())->Remove(loadState.invalid);
            delete loadState.invalid;
            loadState.lists = GetRegionPointLists();
        }
        else
            loadState.lists = loadState.lists->GetNext();
    }
    return true;
}

struct FUN_00740940_shell : public TESDataHandler
{
    TESRegionDataManager* GetRegionDataManager();
};

// @fnv 0x00740940
TESRegionDataManager* FUN_00740940_shell::GetRegionDataManager()
{
    return *(TESRegionDataManager**)((char*)this + 0x624);
}

void __fastcall GetRandomWeather(char*);

// @fnv 0x004f10b0
void __fastcall FUN_004f10b0(char* param_1)
{
    GetRandomWeather(param_1 + 8);
}

struct FUN_004f0890_shell
{
    void FUN_004f08c0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004f08c0 on this, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x004f0890
void* FUN_004f0890_shell::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_004f08c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct NiPoint3
{
    float x, y, z;
    void Set(float, float, float);
};
struct SoundPlaybackHandle
{
    void SetFormType(int);
};
struct SL
{
    void* a;
    void* b;
    SL();
};
struct RDL_004f3330
{
    void* a;
    void* b;
    void* c;
    RDL_004f3330(bool);
};

struct FUN_004f0770 : public TESForm
{
    RDL_004f3330* m_pRegionDataList;
    SL* pRegionPointList;
    void* m_pContainingWorldspace;
    void* m_pRegionWeather;
    float fWeatherChance;
    NiPoint3 m_kDiffuseColor;
    FUN_004f0770();
    ~FUN_004f0770();
};

// Initialises the object: zeroes the point, allocates two members, sets form type 0x37, clears two pointers and sets a float to -1.
// @fnv 0x004f0770
FUN_004f0770::FUN_004f0770()
{
    m_kDiffuseColor.Set(0.0f, 0.0f, 0.0f);
    m_pRegionDataList = new RDL_004f3330(true);
    pRegionPointList = new SL;
    ((SoundPlaybackHandle*)this)->SetFormType(0x37);
    m_pContainingWorldspace = 0;
    m_pRegionWeather = 0;
    fWeatherChance = -1.0f;
}

class FUN_00483630 : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    TESFile* firstSourceFile;
    BSSimpleList<TESFile*>* nextSourceFile;
    ~FUN_00483630();
};
class FUN_004f08c0 : public FUN_00483630
{
  public:
    RegionDataList* m_pRegionDataList;
    BSSimpleList<RegionPointList*>* pRegionPointList;
    TESWorldSpace* m_pContainingWorldspace;
    TESWeather* m_pRegionWeather;
    float fWeatherChance;
    NiColor m_kDiffuseColor;
    virtual ~FUN_004f08c0();
};

// @fnv 0x004f08c0
FUN_004f08c0::~FUN_004f08c0()
{
    if (m_pRegionDataList != 0)
    {
        delete m_pRegionDataList;
    }
    if (pRegionPointList != 0)
    {
        RegionPointList* pointList = pRegionPointList->GetItem();
        while (pointList != 0)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = pRegionPointList->GetItem();
        }
        delete pRegionPointList;
    }
}

struct PointProxy
{
    PointProxy* CloneRegionPointList(int);
};
struct ListProxy
{
    PointProxy*& FUN_006815c0();
    ListProxy* FUN_00726070();
    void FUN_005ae3d0(PointProxy* const&);
};
struct DataProxy
{
    void FUN_004f3470(DataProxy*);
};
struct RegionProxy : FUN_004f0770
{
    ListProxy* FUN_00441110();
    void WarnCopyUnsupported(RegionProxy*);
    DataProxy* FUN_009611e0();
    RegionProxy* FUN_004f10d0(RegionProxy*);
};
// Copies this region into destination (allocating one if null), copying its data and each list node's point proxy.
// @fnv 0x004f10d0
RegionProxy* RegionProxy::FUN_004f10d0(RegionProxy* destination)
{
    RegionProxy* result = destination ? destination : (RegionProxy*)new FUN_004f0770;
    ListProxy* pNode = FUN_00441110();
    WarnCopyUnsupported(result);
    FUN_009611e0()->FUN_004f3470(result->FUN_009611e0());
    while (pNode && pNode->FUN_006815c0())
    {
        result->FUN_00441110()->FUN_005ae3d0(pNode->FUN_006815c0()->CloneRegionPointList(0));
        pNode = pNode->FUN_00726070();
    }
    return result;
}

struct S_004f1300_Item
{
    int FUN_0084e3a0();
    float FUN_00526ae0();
};

struct S_004f1300_Base0
{
    virtual void vfn00();
};

struct S_004f1300_Holder : S_004f1300_Base0, BSSimpleList<S_004f1300_Item*>
{
};

struct S_004f1300_Mgr
{
    S_004f1300_Holder* FUN_004169d0();
};

struct S_004f1300_Save
{
    unsigned short* FUN_00825c00();
    void FUN_008579b0(void* apData, unsigned int auiSize);
    void FUN_00857a10(void* apData, unsigned int auiSize);
};

extern S_004f1300_Save* DAT_011de45c;
extern S_004f1300_Mgr* DAT_011c3f2c;

// @fnv 0x004f1300
void __cdecl FUN_004f1300()
{
    unsigned short m_usPassCountLocal = 0;
    unsigned short* pusCount4 = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->FUN_008579b0(&m_usPassCountLocal, 2);

    BSSimpleList<S_004f1300_Item*>* pNodeX = DAT_011c3f2c->FUN_004169d0();
    while (pNodeX && !pNodeX->IsEmpty())
    {
        S_004f1300_Item* pItem = pNodeX->GetItem();
        int iID2 = 0;
        float fSecondFunctionValue = 0.0f;
        if (pItem)
        {
            iID2 = pItem->FUN_0084e3a0();
            fSecondFunctionValue = pItem->FUN_00526ae0();
        }
        DAT_011de45c->FUN_00857a10(&iID2, 4);
        DAT_011de45c->FUN_008579b0(&fSecondFunctionValue, 4);
        m_usPassCountLocal++;
        pNodeX = pNodeX->GetNext();
    }
    *pusCount4 = m_usPassCountLocal;
}

class TESRegionDataWeather : public TESRegionData
{
  public:
    virtual ~TESRegionDataWeather();
};

class B4F1050DataList
{
  public:
    TESRegionData* GetDataByType(int eType);
};

void* __fastcall B4F1050GetWeatherTypes(TESRegionDataWeather* pkWeather);

class B4F1050Region
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B4F1050DataList* m_pkDataList;
    int unk1C;
    int unk20;
    void* m_pvWeatherTypes;

    void UpdateWeather();
};

// Clears m_pvWeatherTypes, then if m_pkDataList exists, gets the type-3 region data and stores its weather types.
// @fnv 0x004f1050
void B4F1050Region::UpdateWeather()
{
    m_pvWeatherTypes = 0;
    if (m_pkDataList)
    {
        TESRegionDataWeather* pkWeather = dynamic_cast<TESRegionDataWeather*>(m_pkDataList->GetDataByType(3));
        if (pkWeather)
            m_pvWeatherTypes = B4F1050GetWeatherTypes(pkWeather);
    }
}

void __cdecl FUN_00485910(unsigned int uiType, unsigned int uiID_ldrt);
struct RefQ
{
    unsigned int FUN_0084e3a0();
};
struct ElemQ
{
    void FUN_004f77c0();
};
struct VElemQ
{
    virtual void v0();
    virtual void Save();
};
struct LstAQ
{
    bool FUN_008256d0();
    ElemQ** FUN_006815c0();
    LstAQ* FUN_00726070();
};
struct LstBQ
{
    bool FUN_008256d0();
    VElemQ** FUN_006815c0();
    LstBQ* FUN_00726070();
};
struct OwnQ
{
    void FUN_004855a0();
    RefQ* FUN_007af430();
    LstAQ* FUN_00441110();
    LstBQ* FUN_009611e0();
    void FUN_00485680();
    void FUN_004f0a40();
};
// Calls FUN_004855a0, passes a reference-derived ID to FUN_00485910, traverses two lists calling FUN_004f77c0 and Save on their elements, then calls FUN_00485680.
// @fnv 0x004f0a40
void OwnQ::FUN_004f0a40()
{
    FUN_004855a0();
    RefQ* pRef_gmplt = FUN_007af430();
    if (pRef_gmplt)
    {
        unsigned int uiID_ldrt = pRef_gmplt->FUN_0084e3a0();
        FUN_00485910(0x4d414e57, uiID_ldrt);
    }
    LstAQ* pIterA_kkeo = FUN_00441110();
    while (pIterA_kkeo && !pIterA_kkeo->FUN_008256d0())
    {
        (*pIterA_kkeo->FUN_006815c0())->FUN_004f77c0();
        pIterA_kkeo = pIterA_kkeo->FUN_00726070();
    }
    LstBQ* pIterB_jeqla = FUN_009611e0();
    while (pIterB_jeqla && !pIterB_jeqla->FUN_008256d0())
    {
        (*pIterB_jeqla->FUN_006815c0())->Save();
        pIterB_jeqla = pIterB_jeqla->FUN_00726070();
    }
    FUN_00485680();
}

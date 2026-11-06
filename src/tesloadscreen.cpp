// tesloadscreen.cpp: TESLoadScreen, LoadScreenA6C, FormT (13 functions)

#include "tesloadscreen.h"
#include "tesloadscreen_decls.h"

extern "C" const char kTESLoadScreenWarning[];
const char kTESLoadScreenWarning[] = "MASTERFILE: File %s contains old data for loadscreen %s (%08X).";

// Empty destructor for TESLoadScreen; performs no work.
// @fnv 0x005a67b0
TESLoadScreen::~TESLoadScreen()
{}

// Reads the load screen record header and chunks (EDID, OBND, ICON, DESC, LNAM, FNAM, WMI1), storing editor ID, text, form list entries and load screen type.
// @fnv 0x005a68d0
bool TESLoadScreen::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESTexture*>(this), file);
            break;
        case 0x43534544: {
            char* text = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(text, 0);
            m_kLoadScreenText.Set(text, 0);
            break;
        }
        case 0x4d414e4c: {
            WorldCellRecord* loadForm = new WorldCellRecord;
            file->GetChunkData(loadForm, 12);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<ContainerItemExtraFileData*>(loadForm)->Endian();
            reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(&m_kWorldCellRecordList)
                ->AddHead(reinterpret_cast<TESObjectREFR*&>(loadForm));
            break;
        }
        case 0x4d414e46:
            Warning(kTESLoadScreenWarning, file->GetFilename(), GetName(), GetFormID());
            break;
        case 0x31494d57: {
            unsigned int loadScreenType = 0;
            file->GetChunkData(&loadScreenType);
            if (loadScreenType)
                m_pLoadScreenType = reinterpret_cast<TESLoadScreenType*>(loadScreenType);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x005a66e0
TESLoadScreen::TESLoadScreen()
{
    SetFormType(FORM_ID_LSCR);
    SetInitializationState(true);
    m_pLoadScreenType = 0;
}

// @fnv 0x005a6880
void TESLoadScreen::ClearData()
{
    ClearLoadScreenData();
    m_pLoadScreenType = 0;
    TESForm::ClearData();
}

// Deletes every element of the loading screen list and then clears the list.
// @fnv 0x005a6e50
void TESLoadScreen::ClearLoadScreenData()
{
    BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = item->GetItem();
        delete data;
        item = item->GetNext();
    }
    m_kWorldCellRecordList.RemoveAll();
}

// @fnv 0x005a6b70
void TESLoadScreen::InitItem()
{
    if (IsFormInitialized())
        return;
    BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
    BSSimpleList<WorldCellRecord*>* previous = 0;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = item->GetItem();
        if (data->auiFormId)
            TESForm::RemapFormIDForFile(data->auiFormId, GetFile(-1));
        if (data->uiWorldID)
            TESForm::RemapFormIDForFile(data->uiWorldID, GetFile(-1));
        previous = item;
        item = item->GetNext();
    }
    if (m_pLoadScreenType)
    {
        unsigned int formID = 0;
        formID = reinterpret_cast<unsigned int>(m_pLoadScreenType);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pLoadScreenType = g_dataHandler->GetLoadScreenType(formID);
    }
    SetInitializationState(true);
}

// Builds a location key from the form's cell, worldspace or reference and checks whether it matches an entry in the load screen location list.
// @fnv 0x005a6ec0
bool TESLoadScreen::MatchesFormLocation(TESForm* form)
{
    bool validLocation = false;
    WorldCellRecord location = {0, 0, 0};
    bool display = false;
    switch (form->GetFormType())
    {
    case FORM_ID_CELL: {
        TESObjectCELL* cell = static_cast<TESObjectCELL*>(form);
        if (cell->IsCellInterior())
        {
            location.auiFormId = cell->GetFormID();
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = cell->GetParentWorldSpace();
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = world->GetFormID();
                location.uiCellKey = TESWorldSpace::BuildCellKey(cell->GetCellGridX(), cell->GetCellGridY());
                display = true;
            }
        }
        break;
    }
    case FORM_ID_WRLD: {
        TESWorldSpace* world = static_cast<TESWorldSpace*>(form);
        location.auiFormId = world->GetFormID();
        location.uiWorldID = 0;
        location.uiCellKey = 0;
        display = true;
        break;
    }
    case FORM_ID_REFR:
    case FORM_ID_ACHR:
    case FORM_ID_ACRE:
    case FORM_ID_PMIS:
    case FORM_ID_PGRE:
    case FORM_ID_PBEA:
    case FORM_ID_PFLA:
    case FORM_ID_PBAR: {
        TESObjectREFR* ref = static_cast<TESObjectREFR*>(form);
        TESObjectCELL* cell = ref->GetParentCell();
        if (cell && cell->IsCellInterior())
        {
            location.auiFormId = cell->GetFormID();
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = ref->GetParentWorldSpace();
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = world->GetFormID();
                location.uiCellKey = TESWorldSpace::GetKeyForWorldCoord(*ref->GetPos());
                display = true;
            }
        }
        break;
    }
    }
    if (display)
    {
        BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
        while (item && !item->IsEmpty())
        {
            WorldCellRecord* data = item->GetItem();
            if (location.auiFormId)
            {
                if (data->auiFormId == location.auiFormId)
                {
                    validLocation = true;
                    break;
                }
            }
            else if (location.uiWorldID)
            {
                if (data->uiWorldID == location.uiWorldID && data->uiCellKey == location.uiCellKey)
                {
                    validLocation = true;
                    break;
                }
            }
            item = item->GetNext();
        }
    }
    return validLocation;
}

struct FUN_005a7110_shell : public TESLoadScreen
{
    bool IsDefaultLoadScreen();
};

bool __fastcall _ref_008256d0(void*);

// @fnv 0x005a7110
bool FUN_005a7110_shell::IsDefaultLoadScreen()
{
    return _ref_008256d0((char*)this + 0x2c);
}

struct FUN_005a7130_shell : public TESLoadScreen
{
    int FUN_005a7130();
};

// Returns the int at offset 0x18 of the object stored at this+0x34, or 0 if that pointer is null.
// @fnv 0x005a7130
int FUN_005a7130_shell::FUN_005a7130()
{
    int eRetVal = 0;
    if (*(int**)((char*)this + 0x34))
    {
        eRetVal = *(int*)((char*)*(int**)((char*)this + 0x34) + 0x18);
    }
    return eRetVal;
}

struct FUN_005a68b0_shell
{
    void FUN_005a68b0();
};

struct FUN_004855a0_standin
{
    void FUN_004855a0();
};
struct FUN_00485680_standin
{
    void FUN_00485680();
};

// @fnv 0x005a68b0
void FUN_005a68b0_shell::FUN_005a68b0()
{
    ((FUN_004855a0_standin*)this)->FUN_004855a0();
    ((FUN_00485680_standin*)this)->FUN_00485680();
}

// TESLoadScreen destructor: clear the form data; members and base components are destroyed afterwards.

class A67E0Form
{
  public:
    virtual ~A67E0Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class A67E0Texture
{
  public:
    virtual ~A67E0Texture();
    char* m_pcPath;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class A67E0Description
{
  public:
    virtual void Unk_00();
    int unk04;
};

class A67E0LocationList
{
  public:
    ~A67E0LocationList();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class A67E0String
{
  public:
    ~A67E0String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class FUN_005a67e0 : public A67E0Form, public A67E0Texture, public A67E0Description
{
  public:
    virtual ~FUN_005a67e0();
    virtual void ClearData();

    A67E0LocationList m_kLocations;
    A67E0String m_kLoadingText;
};

// @fnv 0x005a67e0
FUN_005a67e0::~FUN_005a67e0()
{
    ClearData();
}

class LoadFormListA6C : public BSSimpleList<WorldCellRecord*>
{
  public:
    void AddTail(WorldCellRecord* const& pkItem);
};

class LoadScreenA6C : public TESLoadScreen
{
  public:
    TESLoadScreenType* GetLoadScreenType();
    void SetLoadScreenType(TESLoadScreenType* pkType);
    void CopyFormData(TESForm* pkForm);
    void CopyLoadScreenData(TESForm* pkForm);
};

// Copies the load-screen type, form data and list items from another TESLoadScreen into this one.
// @fnv 0x005a6c70
void LoadScreenA6C::CopyLoadScreenData(TESForm* pkForm)
{
    BSSimpleList<WorldCellRecord*>* pkDstNode = 0;
    LoadScreenA6C* pkSource = static_cast<LoadScreenA6C*>(dynamic_cast<TESLoadScreen*>(pkForm));
    if (!pkSource)
        return;

    ClearLoadScreenData();

    BSSimpleList<WorldCellRecord*>* pkSrcIter = &pkSource->m_kWorldCellRecordList;
    pkDstNode = &m_kWorldCellRecordList;
    while (pkSrcIter && !pkSrcIter->IsEmpty())
    {
        static_cast<LoadFormListA6C*>(pkDstNode)->AddTail(pkSrcIter->GetItem());
        if (pkDstNode->GetNext())
            pkDstNode = pkDstNode->GetNext();
        pkSrcIter = pkSrcIter->GetNext();
    }

    SetLoadScreenType(pkSource->GetLoadScreenType());
    CopyFormData(pkSource);
}

extern char DAT_01186260, DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
class ListX
{
  public:
    int FUN_005ae380();
    bool FUN_008256d0();
    void* FUN_006815c0();
    ListX* FUN_00726070();
    bool FUN_005f65d0(void*);
    void* head;
    void* next;
};
class FormT
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    ListX kList;
    bool FUN_00485270(FormT*);
    int FUN_005f36f0();
    bool FUN_005a6d30(void* pOther);
};
// @fnv 0x005a6d30
bool FormT::FUN_005a6d30(void* pOther)
{
    FormT* pOtherForm = (FormT*)FUN_00ec43fb(pOther, 0, &DAT_01183028, &DAT_01186260, 0);
    if (!pOtherForm)
        return true;
    ListX* it = &pOtherForm->kList;
    if (kList.FUN_005ae380() != it->FUN_005ae380())
        return true;
    while (it && !it->FUN_008256d0())
    {
        if (!kList.FUN_005f65d0(it->FUN_006815c0()))
            return true;
        it = it->FUN_00726070();
    }
    if (FUN_00485270(pOtherForm))
        return true;
    if (FUN_005f36f0() != pOtherForm->FUN_005f36f0())
        return true;
    return false;
}

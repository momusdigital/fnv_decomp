// fallout_shared/tescaravan.cpp: TESCaravanCard, TESCaravanMoney, TESCaravanDeck, Holder and more (32 functions)

#include "tescaravan_decls.h"
class RegionDataEntry
{
  public:
    void Endian();
};

class BGSImpactData
{
  public:
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
};

extern "C" void* memset(void* dst, int val, unsigned int size);

// @fnv 0x0059a370
TESCaravanCard::TESCaravanCard()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x73));
    ResetFormData();
}

// @fnv 0x0059a670
void TESCaravanCard::ResetFormData()
{
    m_kFrontTexture.Init();
    m_kBackTexture.Init();
    memset(&data, 0, sizeof(data));
}

// @fnv 0x0059a6c0
void TESCaravanCard::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    TESScriptableForm::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Initializes both entries of the array by calling Init on each.
// @fnv 0x0059b120
void TESCaravanMoney::ResetFormData()
{
    m_kModelTextureSwaps[0].Init();
    m_kModelTextureSwaps[1].Init();
}

// @fnv 0x0059b160
void TESCaravanMoney::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x0059b880
TESCaravanDeck::TESCaravanDeck()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x75));
    ResetFormData();
}

// @fnv 0x0059b9f0
void TESCaravanDeck::ResetFormData()
{
    m_pCardListHeadCur = new BSSimpleList<TESCaravanCard*>();
    data.m_iValue = 0;
}

// Reads a TESCaravanDeck record from file: validates form type 0x75, loads header, then processes EDID, OBND, FULL, DATA and CARD chunks.
// @fnv 0x0059bb50
bool TESCaravanDeck::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x75)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(static_cast<TESFullName*>(this), file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &data, 4);
            break;
        case 0x44524143: {
            unsigned int formID;
            file->GetChunkData(&formID);
            RemapFormIDForFile(formID, file);
            TESForm* form = TESForm::GetFormByID(formID);
            TESCaravanCard* card = static_cast<TESCaravanCard*>(form);
            if (!m_pCardListHeadCur || m_pCardListHeadCur->IsEmpty())
                m_pCardListHeadCur->SetItem(card);
            else
                m_pCardListHeadCur->AddHead(card);
            break;
        }
        }
        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<RegionDataEntry*>(&data)->Endian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0059b290
bool TESCaravanMoney::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x74)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            char* textureSwapData;
            unsigned int chunkSize = file->GetChunkSize();
            textureSwapData = static_cast<char*>(_alloca(chunkSize));
            file->GetChunkData(textureSwapData, chunkSize);
            ParseTextureSwapData(textureSwapData, chunkSize,
                                 reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPickupSound(reinterpret_cast<TESSound*>(id));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPutdownSound(reinterpret_cast<TESSound*>(id));
            break;
        }
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, 0, 0);
            break;
        case 0x32444f4d: {
            char* model = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(model, 0);
            m_kModelTextureSwaps[0].SetModelFilePath(model);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[0], file);
            break;
        }
        case 0x33444f4d: {
            char* model = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(model, 0);
            m_kModelTextureSwaps[1].SetModelFilePath(model);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[1], file);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0059a800
bool TESCaravanCard::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    bool m_bHeaderParsed = false;
    if (formType != 0x73)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            char* textureSwapData;
            unsigned int chunkSize = file->GetChunkSize();
            textureSwapData = static_cast<char*>(_alloca(chunkSize));
            file->GetChunkData(textureSwapData, chunkSize);
            ParseTextureSwapData(textureSwapData, chunkSize,
                                 reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPickupSound(reinterpret_cast<TESSound*>(id));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPutdownSound(reinterpret_cast<TESSound*>(id));
            break;
        }
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, 0, 0);
            break;
        case 0x30305854:
            TESTextureLoader::ReadTextureData(&m_kFrontTexture, file);
            break;
        case 0x31305854:
            TESTextureLoader::ReadTextureData(&m_kBackTexture, file);
            break;
        case 0x56544e49:
            if (!m_bHeaderParsed)
            {
                file->GetChunkData(&data.m_uiSecondValue);
                m_bHeaderParsed = true;
            }
            else
            {
                file->GetChunkData(&data.m_uiFirstValue);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00503650_shell : public TESCaravanCard
{
    TESTexture* FUN_00503650();
};

// @fnv 0x00503650
TESTexture* FUN_00503650_shell::FUN_00503650()
{
    return reinterpret_cast<TESTexture*>(reinterpret_cast<char*>(this) + 0xA8);
}

struct FUN_0059adf0 : public TESForm
{
    void LoadGame(void* arg);
};

// @fnv 0x0059adf0
void FUN_0059adf0::LoadGame(void* arg)
{
    TESForm::LoadGame(arg);
}

struct FUN_0059b270_shell
{
    char* __thiscall FUN_0059b270(int index);
};

// @fnv 0x0059b270
char* __thiscall FUN_0059b270_shell::FUN_0059b270(int index)
{
    return &((char*)this)[index * 32 + 140];
}

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_0059b9c0_shell
{
    char pad1[0x24];
    List_009e03e0* m_pCardListHeadCur;
    unsigned int data;
    void ClearListAndData();
};

// Calls RemoveAll on the list and zeroes the 4-byte data field.
// @fnv 0x0059b9c0
void FUN_0059b9c0_shell::ClearListAndData()
{
    m_pCardListHeadCur->RemoveAll();
    memset(&data, 0, 4);
}

namespace fnv_0059b1b0 {
struct FUN_0048e370_shell
{
    void FUN_0048e370(int);
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(int);
};
struct FUN_0047b560_shell
{
    void LogFormIDs(void);
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_0059b270_shell
{
    char* FUN_0059b270(int);
};
struct FUN_0059b1b0_shell
{
    void FUN_0059b1b0();
};

// @fnv 0x0059b1b0
void FUN_0059b1b0_shell::FUN_0059b1b0()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_shell*)((char*)this + 0x5c))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x68))->FUN_0047a240(0x4f43494d);
    ((FUN_0047b560_shell*)((char*)this + 0x80))->LogFormIDs();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    ((S_0048a520*)((FUN_0059b270_shell*)this)->FUN_0059b270(0))->ProcessAndFreeData(0x32444f4d, 0x54444f4d, 0x53444f4d);
    ((S_0048a520*)((FUN_0059b270_shell*)this)->FUN_0059b270(1))->ProcessAndFreeData(0x33444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_00485680*)this)->M();
}
}  // namespace fnv_0059b1b0

void _Deallocate(void*);
struct Holder
{
    void FUN_0059a4f0();
    void* Release(unsigned int flags);
};
// Calls FUN_0059a4f0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0059a4c0
void* Holder::Release(unsigned int flags)
{
    this->FUN_0059a4f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047b560_holder
{
    void LogFormIDs();
};
struct FUN_0050d100_shell
{
    void* FUN_0050d100();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_00485680
{
    void M();
};
extern "C" unsigned int _FUN_00485910(unsigned int, unsigned int);

class TESDataHandler
{
  public:
    void* GetBGSRecipeCategoryList();
};

class FUN_0059a720_shell
{
  public:
    void Initialize();
};

// @fnv 0x0059a720
void FUN_0059a720_shell::Initialize()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_obj*)((char*)this + 0x5c))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x68))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x80))->FUN_0048cca0();
    ((FUN_0047b560_holder*)((char*)this + 0x8c))->LogFormIDs();
    ((FUN_0048e370_obj*)((FUN_0050d100_shell*)this)->FUN_0050d100())->FUN_0048e370(0x30305854);
    ((FUN_0048e370_obj*)((TESDataHandler*)this)->GetBGSRecipeCategoryList())->FUN_0048e370(0x31305854);
    _FUN_00485910(0x56544e49, *(unsigned int*)((char*)this + 0xb8));
    _FUN_00485910(0x56544e49, *(unsigned int*)((char*)this + 0xb4));
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    ((FUN_00485680*)this)->M();
}

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0059add0_shell : public FUN_00484d60_holder
{
    void ForwardToBase(unsigned int a);
};
// @fnv 0x0059add0
void FUN_0059add0_shell::ForwardToBase(unsigned int a)
{
    SaveIfChanged(a);
}

struct Place_0059af90
{
    void FUN_0059afc0();
    void* FUN_0059af90(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0059afc0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0059af90
void* Place_0059af90::FUN_0059af90(unsigned int flags)
{
    FUN_0059afc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FakeVTable_59b0e0
{
    virtual void F0();
    virtual void F1();
};
struct FUN_0059b0e0_shell : TESCaravanMoney
{
    void FUN_0059b0e0();
};
// @fnv 0x0059b0e0
void FUN_0059b0e0_shell::FUN_0059b0e0()
{
    reinterpret_cast<FakeVTable_59b0e0*>(&m_kModelTextureSwaps[0])->F1();
    reinterpret_cast<FakeVTable_59b0e0*>(&m_kModelTextureSwaps[1])->F1();
}

struct FUN_0059b910_shell
{
    void FUN_0059b940();
    void* FUN_0059b910(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0059b940, then frees this object with _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x0059b910
void* FUN_0059b910_shell::FUN_0059b910(unsigned int flags)
{
    FUN_0059b940();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0059ba80 {
struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct BSThread
{
    unsigned int GetThreadID();
};
extern "C" void __cdecl FUN_00485910(int, unsigned int);
extern "C" bool __cdecl FUN_00401500();
struct BipedModelForm
{
    void Endian();
};
struct FUN_00485e00_shell
{
    void __SaveData(int, int);
};
struct FUN_00485680
{
    void M();
};

struct FUN_0059ba80_shell : public FUN_004855a0
{
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;
    BipedModelForm data;
    void __SaveData(int, int);
    void M();
    void FUN_0059ba80();
};

// @fnv 0x0059ba80
void FUN_0059ba80_shell::FUN_0059ba80()
{
    M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    BSSimpleList<TESCaravanCard*>* current = (BSSimpleList<TESCaravanCard*>*)((BSThread*)this)->GetThreadID();
    while (current && current->GetItem())
    {
        FUN_00485910(0x44524143, current->GetItem()->GetFormID());
        current = current->GetNext();
    }
    if (FUN_00401500())
        ((BipedModelForm*)((char*)this + 0x28))->Endian();
    __SaveData((int)((char*)this + 0x28), 4);
    if (FUN_00401500())
        ((BipedModelForm*)((char*)this + 0x28))->Endian();
    ((FUN_00485680*)this)->M();
}
}  // namespace fnv_0059ba80

struct FakeTexture0059
{
    virtual void Unk0();
    virtual void Unk1();
    int field4;
    int field8;
};
struct CardOwner0059
{
    char _pad[0x9c];
    FakeTexture0059 m_kFrontTexture;
    FakeTexture0059 m_kBackTexture;
    char data[8];
    void FUN_0059a620();
};
// Calls Unk1 on both FakeTexture0059 members and clears the 8-byte data buffer.
// @fnv 0x0059a620
void CardOwner0059::FUN_0059a620()
{
    m_kFrontTexture.Unk1();
    m_kBackTexture.Unk1();
    memset(data, 0, 8);
}

struct CMBoundObject
{
    virtual ~CMBoundObject();
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
    int unk2c;
};
struct CMFullName
{
    virtual ~CMFullName();
    int unk04;
    int unk08;
};
struct CMModelTextureSwap
{
    virtual ~CMModelTextureSwap();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct CMIcon
{
    virtual ~CMIcon();
    int unk04;
    int unk08;
};
struct CMMessageIcon
{
    virtual ~CMMessageIcon();
    int unk04;
    int unk08;
    int unk0c;
};
struct CMValueForm
{
    virtual ~CMValueForm();
    int unk04;
};
struct CMPickupPutdownSounds
{
    virtual ~CMPickupPutdownSounds();
    int unk04;
    int unk08;
};

struct FUN_0059afc0 : public CMBoundObject,
                      public CMFullName,
                      public CMModelTextureSwap,
                      public CMIcon,
                      public CMMessageIcon,
                      public CMValueForm,
                      public CMPickupPutdownSounds
{
    CMModelTextureSwap m_kModelTextureSwaps[2];
    void ClearData();
    virtual ~FUN_0059afc0();
};

// @fnv 0x0059afc0
FUN_0059afc0::~FUN_0059afc0()
{
    ClearData();
}

namespace fnv_0059b680 {
extern "C"
{
    extern char DAT_0118c5e4[];
    extern char DAT_01183028[];
}

void* __cdecl FUN_00ec43fb(unsigned int, unsigned int, unsigned int, unsigned int, int);

struct FUN_0059b680_sub
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
    virtual void V6(void* arg);
};

struct FUN_0059b270_shell
{
    char* __thiscall FUN_0059b270(int index);
};

struct FUN_00401170_shell
{
    void* FUN_00401170();
};

struct FUN_0059b680_base
{
    void FUN_004851b0(void* p);
    void FUN_004f15a0(void* p);
};

class FUN_0059b680_cls : public FUN_0059b680_base
{
  public:
    char unk00[0x8c];
    FUN_0059b680_sub m_8c;
    char unk90[0x1c];
    FUN_0059b680_sub m_ac;

    void FUN_0059b680(int a1);
};

// @fnv 0x0059b680
void FUN_0059b680_cls::FUN_0059b680(int a1)
{
    void* p = FUN_00ec43fb(a1, 0, (unsigned int)DAT_01183028, (unsigned int)DAT_0118c5e4, 0);
    if (p == 0)
    {
    }
    else
    {
        FUN_004851b0(p);
        m_8c.V6(((FUN_0059b680_sub*)((FUN_0059b270_shell*)p)->FUN_0059b270(0))->V5());
        m_ac.V6(((FUN_0059b680_sub*)((FUN_0059b270_shell*)p)->FUN_0059b270(1))->V5());
        FUN_004f15a0(((FUN_00401170_shell*)a1)->FUN_00401170());
    }
}
}  // namespace fnv_0059b680

struct BaseDtor_b5117
{
    virtual void unk00();
    ~BaseDtor_b5117();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondDtor_b5117
{
    virtual void unk00();
    ~SecondDtor_b5117();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_0059b940 : BaseDtor_b5117, SecondDtor_b5117
{
    virtual void unk08();
    void unk0C();
    ~FUN_0059b940();
};

// @fnv 0x0059b940
FUN_0059b940::~FUN_0059b940()
{
    unk0C();
}

extern const char DAT_01183028[];
extern const char DAT_0118643c[];

struct Itc
{
    void** FUN_006815c0();
    Itc* FUN_00726070();
};

struct DeckData
{
    int x;
};

struct L1c
{
    Itc* FUN_0059bb30();
    DeckData* GetExtraDataList();
    unsigned int FUN_00401170();
};

struct P24c
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_00726c60(void*& v);
    void FUN_005ae3d0(void*& v);
};

struct FUN_0059bd50_cls
{
    void FUN_004851b0(L1c* rec);
    void FUN_004f15a0(unsigned int v);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    P24c* p24;
    DeckData f28;
    void LoadDeckData(void* arg);
};

L1c* __cdecl FUN_00ec43fb(void* arg, int a2, const char* a3, const char* a4, int a5);

// @fnv 0x0059bd50
void FUN_0059bd50_cls::LoadDeckData(void* arg)
{
    L1c* rec = FUN_00ec43fb(arg, 0, DAT_01183028, DAT_0118643c, 0);
    if (rec == 0)
    {
    }
    else
    {
        FUN_004851b0(rec);
        while (p24 != 0 && !p24->FUN_008256d0())
            p24->FUN_0063f7b0();
        Itc* it = rec->FUN_0059bb30();
        while (it != 0 && *it->FUN_006815c0() != 0)
        {
            void* v = *it->FUN_006815c0();
            if (p24 == 0 || p24->FUN_008256d0())
                p24->FUN_00726c60(v);
            else
                p24->FUN_005ae3d0(v);
            it = it->FUN_00726070();
        }
        f28 = *rec->GetExtraDataList();
        FUN_004f15a0(rec->FUN_00401170());
    }
}

struct FUN_0059a4f0 : TESBoundObject,
                      TESFullName,
                      TESModelTextureSwap,
                      TESIcon,
                      BGSMessageIcon,
                      TESValueForm,
                      TESScriptableForm,
                      BGSPickupPutdownSounds
{
    bool bIsActive;
    TESTexture m_kFrontTexture;
    TESTexture m_kBackTexture;
    UnsignedValuePair data;
    virtual ~FUN_0059a4f0();
};

// @fnv 0x0059a4f0
FUN_0059a4f0::~FUN_0059a4f0()
{
    static_cast<CardOwner0059*>(static_cast<void*>(this))->FUN_0059a620();
}

namespace fnv_0059ac20 {
extern char DAT_0118c5c4, DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
class StrB
{
  public:
    const char* FUN_00408da0();
};
class StrSet
{
  public:
    void FUN_00489100(const char*);
};
struct Pair8
{
    int a, b;
};
class SrcF
{
  public:
    StrB* FUN_0050d100();
    StrB* FUN_00503650();
    Pair8* FUN_006ab360();
};
class FormA
{
  public:
    int FUN_00401170();
};
class DstF
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    StrSet s9c;
    int unka0;
    int unka4;
    StrSet sa8;
    int unkac;
    int unkb0;
    Pair8 kb4;
    void FUN_004851b0(SrcF*);
    void FUN_004f15a0(int);
    void CopyFrom(FormA* pForm);
};
// @fnv 0x0059ac20
void DstF::CopyFrom(FormA* pForm)
{
    SrcF* pSrc = (SrcF*)FUN_00ec43fb(pForm, 0, &DAT_01183028, &DAT_0118c5c4, 0);
    if (!pSrc)
        return;
    FUN_004851b0(pSrc);
    s9c.FUN_00489100(pSrc->FUN_0050d100()->FUN_00408da0());
    sa8.FUN_00489100(pSrc->FUN_00503650()->FUN_00408da0());
    kb4 = *pSrc->FUN_006ab360();
    FUN_004f15a0(pForm->FUN_00401170());
}
}  // namespace fnv_0059ac20

namespace fnv_0059acd0 {
extern "C" void* __cdecl FNV_DynamicCast(void* pObj, int vfDelta, void* pSrcType, void* pTargetType, int isRef);
extern "C" void* DAT_0118c5c4;
extern "C" void* DAT_01183028;
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct StrHelper_00408da0
{
    const char* FUN_00408da0();
};

int FUN_00408b20(const char*, const char*);

struct CardType_0059acd0
{
    StrHelper_00408da0* FUN_0050d100();
    StrHelper_00408da0* FUN_00503650();
    void* FUN_006ab360();
};

struct Class_0059acd0
{
    char pad00[0x9c];
    StrHelper_00408da0 unk9c;
    char padA0[0xa8 - 0x9c - sizeof(StrHelper_00408da0)];
    StrHelper_00408da0 unka8;
    char padAC[0xb4 - 0xa8 - sizeof(StrHelper_00408da0)];
    char unkb4[8];

    bool FUN_00485270(CardType_0059acd0*);
    bool IsDifferentFromCard(void* param1);
};

// Returns true if the cast fails or either compared string or the 8-byte data differs.
// @fnv 0x0059acd0
bool Class_0059acd0::IsDifferentFromCard(void* apCard)
{
    CardType_0059acd0* card = (CardType_0059acd0*)FNV_DynamicCast(apCard, 0, &DAT_01183028, &DAT_0118c5c4, 0);
    if (!card)
        return true;
    if (this->FUN_00485270(card))
        return true;
    if (FUN_00408b20(this->unk9c.FUN_00408da0(), card->FUN_0050d100()->FUN_00408da0()))
        return true;
    if (FUN_00408b20(this->unka8.FUN_00408da0(), card->FUN_00503650()->FUN_00408da0()))
        return true;
    if (memcmp(this->unkb4, card->FUN_006ab360(), 8))
        return true;
    return false;
}
}  // namespace fnv_0059acd0

#include <string.h>
struct CardListNode
{
    TESCaravanCard*& FUN_006815c0();
    CardListNode* FUN_00726070();
    int FUN_005ae380();
    bool FUN_005f65d0(TESCaravanCard*& item);
};

struct FormCmpX
{
    bool FUN_00485270(TESForm* form);
};

// FUN_0059bb30 / FUN_004610d0 / FUN_0059be50 are not declared on TESCaravanDeck in
// today's tree; reach them through a derived stand-in with an identical layout.
struct TESCaravanDeckX : TESCaravanDeck
{
    CardListNode* FUN_0059bb30();
    CaravanDeckData* GetExtraDataList();
    bool FUN_0059be50(TESForm* form);
};

// Returns true if the cast fails, FUN_00485270 returns true, card counts differ, a card from the other deck is absent here, or CaravanDeckData differs.
// @fnv 0x0059be50
bool TESCaravanDeckX::FUN_0059be50(TESForm* form)
{
    TESCaravanDeck* pDeck2 = dynamic_cast<TESCaravanDeck*>(form);
    if (!pDeck2)
        return true;
    if (((FormCmpX*)this)->FUN_00485270(pDeck2))
        return true;
    if (FUN_0059bb30()->FUN_005ae380() != ((TESCaravanDeckX*)pDeck2)->FUN_0059bb30()->FUN_005ae380())
        return true;
    CardListNode* pNode = ((TESCaravanDeckX*)pDeck2)->FUN_0059bb30();
    while (pNode && pNode->FUN_006815c0())
    {
        if (!FUN_0059bb30()->FUN_005f65d0(pNode->FUN_006815c0()))
            return true;
        pNode = pNode->FUN_00726070();
    }
    if (memcmp(&data, ((TESCaravanDeckX*)pDeck2)->GetExtraDataList(), sizeof(CaravanDeckData)))
        return true;
    return false;
}

struct CaravanModelPathView
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual const char* GetPath();
};

struct CaravanMoneyCompare : public TESCaravanMoney
{
    CaravanModelPathView* FUN_0059b270(int);
    bool FUN_00485270(TESForm*);
    bool FUN_0059b740(TESForm*);
};

int __cdecl FUN_00408b20(const char*, const char*);

// @fnv 0x0059b740
bool CaravanMoneyCompare::FUN_0059b740(TESForm* other)
{
    CaravanMoneyCompare* compared = static_cast<CaravanMoneyCompare*>(dynamic_cast<TESCaravanMoney*>(other));

    if (!compared)
        return true;

    if (FUN_00485270(compared))
        return true;

    if (FUN_00408b20(reinterpret_cast<CaravanModelPathView*>(&m_kModelTextureSwaps[0])->GetPath(),
                     compared->FUN_0059b270(0)->GetPath()))
        return true;

    if (FUN_00408b20(reinterpret_cast<CaravanModelPathView*>(&m_kModelTextureSwaps[1])->GetPath(),
                     compared->FUN_0059b270(1)->GetPath()))
        return true;

    return false;
}

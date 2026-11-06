// fallout_shared/tesobjectarma.cpp: TESObjectARMA, ArmaCompare (12 functions)

#include "tesobjectarma_load.h"
class TESForm;

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class TESForm
{
  public:
    virtual ~TESForm();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char*);
    void LoadRecordHeader(TESFile*);
    void SetFormType(ENUM_FORM_ID);
    void SetInitializationState(bool initialized);
};

class TESBipedModelForm
{
  public:
    unsigned char prefix[4];
    unsigned int bipedFlags;
    unsigned char m_ucBipedModelData;
    unsigned char padding[3];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    TESTexture1024 m_kIcon[2];
    BGSMessageIcon messageIcon[2];
    TESModel m_kFaceGenModel;
    void InitItem(TESForm* form);
};

class BGSDestructibleObjectForm
{
  public:
    unsigned char bytes[8];
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    void InitItem(TESForm* form);
};

class TESObjectARMA : public TESForm
{
  public:
    unsigned char padToBiped[0x6c];
    TESBipedModelForm biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    unsigned char padToData[0x1c];
    ArmorData data;
    bool Load(TESFile* file);
    void ResetFormData();
    void InitItem();
};

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern int __cdecl Warning(const char* format, ...);

// Zeroes the ARMA's data block with memset.
// @fnv 0x00512010
void TESObjectARMA::ResetFormData()
{
    memset(&data, 0, sizeof(data));
}

// Initializes the armor form: warns if no biped slots are set, then initializes destructible and biped data and marks the form initialized.
// @fnv 0x00512030
void TESObjectARMA::InitItem()
{
    if (((TESFormInitFlag*)this)->IsFormInitialized())
        return;
    if (biped.bipedFlags == 0)
        Warning("MASTERFILE: Armor '%s' needs to have biped slots selected in the editor.", GetEditorID());
    destructible.InitItem((TESForm*)this);
    biped.InitItem((TESForm*)this);
    SetInitializationState(true);
}

// @fnv 0x005120a0
bool TESObjectARMA::Load(TESFile* file)
{
    unsigned char form = file->GetTESForm();
    if (form != 0x60)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (int chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this ? (TESFullName*)((char*)this + 0x30) : 0, file);
            break;
        case 'TDMB':
            if (((TESFileFormVersion*)file)->GetFormVersion() < 11)
            {
                BIPED_MODEL_OLD oldData;
                file->GetChunkData(&oldData, 4);
                if (file->IsEndianConversionRequired())
                    oldData.FUN_00512810();
                biped.m_ucBipedModelData = oldData.m_ucBipedModelData;
                biped.bipedFlags = oldData.m_uiBipedModelFlags;
            }
            else
            {
                file->GetChunkData(&biped.bipedFlags, 8);
                if (file->IsEndianConversionRequired())
                    ((RegionDataEntry*)&biped.bipedFlags)->Endian();
            }
            biped.m_ucBipedModelData &= ~0x10;
            break;
        case 'TCMB': {
            char* constraint = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(constraint, 0);
            biped.m_kFaceGenModel.SetModelFilePath(constraint);
            break;
        }
        case 'LDOM': {
            char* maleBiped = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleBiped, 0);
            biped.bipedModel[0].SetModelFilePath(maleBiped);
            break;
        }
        case 'TDOM':
            TESModel::LoadTextureSwapData(&biped.bipedModel[0], file);
            break;
        case 'SDOM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.bipedModel[0], file);
            break;
        case 'DDOM':
            TESModel::LoadModelData(&biped.bipedModel[0], file);
            break;
        case 'DSOM':
            TESModel::LoadModelData(&biped.bipedModel[1], file);
            break;
        case '2DOM': {
            char* maleWorld = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleWorld, 0);
            biped.worldModel[0].SetModelFilePath(maleWorld);
            break;
        }
        case 'T2OM':
            TESModel::LoadTextureSwapData(&biped.worldModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.worldModel[0], file);
            break;
        case 'NOCI': {
            char* maleIcon = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleIcon, 0);
            biped.m_kIcon[0].SetTexture(maleIcon);
            break;
        }
        case 'OCIM': {
            char* maleMessage = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleMessage, 0);
            biped.messageIcon[0].SetMessageIconTextureName(maleMessage);
            break;
        }
        case '2CIM': {
            char* femaleMessage = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleMessage, 0);
            biped.messageIcon[1].SetMessageIconTextureName(femaleMessage);
            break;
        }
        case '3DOM': {
            char* femaleBiped = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleBiped, 0);
            biped.bipedModel[1].SetModelFilePath(femaleBiped);
            break;
        }
        case 'T3OM':
            TESModel::LoadTextureSwapData(&biped.bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.bipedModel[1], file);
            break;
        case '4DOM': {
            char* femaleWorld = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleWorld, 0);
            biped.worldModel[1].SetModelFilePath(femaleWorld);
            break;
        }
        case 'T4OM':
            TESModel::LoadTextureSwapData(&biped.worldModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.worldModel[1], file);
            break;
        case '2OCI': {
            char* femaleIcon = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleIcon, 0);
            biped.m_kIcon[1].SetTexture(femaleIcon);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this ? &destructible : 0, file);
            break;
        case 'PYTE': {
            unsigned int type = 0;
            file->GetChunkData(&type);
            // Reuse the canonical identity of the folded scalar setter.
            ((TESResponse*)&equipType)->SetEmotionValue(type);
            break;
        }
        case 'MAND':
            memset(&data, 0, sizeof(data));
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.FUN_00535aa0();
            break;
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
            data.FUN_00535aa0();
        if (!file->NextChunk())
            break;
    }
    SetFormType(FORM_ARMO);
    return true;
}

struct TESObjectARMO
{
    TESObjectARMO();
    ~TESObjectARMO();
};
struct SFTX
{
    void SetFormType(int);
};
extern int DAT_0102a214;
extern int DAT_0102a228;
extern int DAT_0102a23c;
extern int DAT_0102a250;
extern int DAT_0102a264;
extern int DAT_0102a278;
extern int DAT_0102a2a4;
extern int DAT_0102a2b8;
extern int DAT_0102a2d8;
extern int DAT_0102a2f0;
extern int DAT_0102a304;
extern int DAT_0102a31c;
struct FUN_00511e40
{
    TESObjectARMO armo;
    FUN_00511e40();
};
// @fnv 0x00511e40
FUN_00511e40::FUN_00511e40()
{
    *(int*)((char*)this + 0x0) = (int)&DAT_0102a31c;
    *(int*)((char*)this + 0x30) = (int)&DAT_0102a304;
    *(int*)((char*)this + 0x3c) = (int)&DAT_0102a2f0;
    *(int*)((char*)this + 0x48) = (int)&DAT_0102a2d8;
    *(int*)((char*)this + 0x58) = (int)&DAT_0102a2b8;
    *(int*)((char*)this + 0x60) = (int)&DAT_0102a2a4;
    *(const char**)((char*)this + 0x68) = " rH";
    *(int*)((char*)this + 0x70) = (int)&DAT_0102a278;
    *(int*)((char*)this + 0x14c) = (int)&DAT_0102a264;
    *(int*)((char*)this + 0x154) = (int)&DAT_0102a250;
    *(int*)((char*)this + 0x15c) = (int)&DAT_0102a23c;
    *(int*)((char*)this + 0x164) = (int)&DAT_0102a228;
    *(int*)((char*)this + 0x16c) = (int)&DAT_0102a214;
    ((SFTX*)this)->SetFormType(0x60);
    ((TESObjectARMA*)this)->ResetFormData();
}

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0048ea40_holder
{
    void FUN_0048ea40(unsigned int);
};

struct FUN_005144c0_shell
{
    void FUN_005144c0(unsigned int flags);
};

// @fnv 0x005144c0
void FUN_005144c0_shell::FUN_005144c0(unsigned int flags)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(flags);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x58)->FUN_0048ea40(flags);
}

struct BGSLoadFormBuffer;

struct TESValueFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct TESFormBufferAccess
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct FUN_005160a0_shell : TESObjectARMO
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// Loads the form buffer via TESFormBufferAccess::LoadGame, then loads the value form at offset 0x58 via TESValueFormLoadGame::LoadGame.
// @fnv 0x005160a0
void FUN_005160a0_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormBufferAccess*>(this)->TESFormBufferAccess::LoadGame(buffer);
    reinterpret_cast<TESValueFormLoadGame*>(static_cast<TESObjectARMO*>(this) + 0x58)
        ->TESValueFormLoadGame::LoadGame(buffer);
}

void _Deallocate(void*);
struct FUN_00511f30_holder
{
    void FUN_00511f60();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00511f60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00511f30
void* FUN_00511f30_holder::DestroyIfFlagged(unsigned int flags)
{
    FUN_00511f60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00511f60_shell : TESObjectARMO
{
    void FUN_00511f60();
    void FUN_00512bd0();
};
// @fnv 0x00511f60
void FUN_00511f60_shell::FUN_00511f60()
{
    *(void**)this = (void*)&DAT_0102a31c;
    *(void**)((char*)this + 0x30) = (void*)&DAT_0102a304;
    *(void**)((char*)this + 0x3c) = (void*)&DAT_0102a2f0;
    *(void**)((char*)this + 0x48) = (void*)&DAT_0102a2d8;
    *(void**)((char*)this + 0x58) = (void*)&DAT_0102a2b8;
    *(void**)((char*)this + 0x60) = (void*)&DAT_0102a2a4;
    *(void**)((char*)this + 0x68) = (void*)" rH";
    *(void**)((char*)this + 0x70) = (void*)&DAT_0102a278;
    *(void**)((char*)this + 0x14c) = (void*)&DAT_0102a264;
    *(void**)((char*)this + 0x154) = (void*)&DAT_0102a250;
    *(void**)((char*)this + 0x15c) = (void*)&DAT_0102a23c;
    *(void**)((char*)this + 0x164) = (void*)&DAT_0102a228;
    *(void**)((char*)this + 0x16c) = (void*)&DAT_0102a214;
    FUN_00512bd0();
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
struct FUN_00512810_holder
{
    void FUN_00512810();
};
// Byte-swaps the 16-bit value at the start of this object by calling BSEndian.
// @fnv 0x00512810
void FUN_00512810_holder::FUN_00512810()
{
    BSEndian((unsigned short*)this, EndianSizeTag<2>());
}

void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_005128e0_obj
{
    void CopyFrom(TESForm* apCopy);
};
// If apCopy is a TESObjectARMO, copies 0xc bytes at offset 0x178 from apCopy into this and calls FUN_004851b0(apCopy).
// @fnv 0x005128e0
void FUN_005128e0_obj::CopyFrom(TESForm* apCopy)
{
    TESObjectARMO* parmo = dynamic_cast<TESObjectARMO*>(apCopy);
    if (parmo == 0)
        return;
    __memcpy((char*)this + 0x178, (char*)apCopy + 0x178, 0xc);
    ((FUN_005e78f0_t*)this)->FUN_004851b0(apCopy);
}

struct FUN_004855a0_shell
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
struct FUN_00480610_shell
{
    void InitBipedModel();
};
struct FUN_00479350_shell
{
    void FUN_00479350();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_00485680_shell
{
    void M();
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int size, void* apDest, unsigned int flags);
struct FUN_00512840_shell
{
    void SaveForm();
};
// @fnv 0x00512840
void FUN_00512840_shell::SaveForm()
{
    ((FUN_004855a0_shell*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((FUN_00480610_shell*)((char*)this + 0x70))->InitBipedModel();
    ((FUN_00479350_shell*)((char*)this + 0x154))->FUN_00479350();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (FUN_00401500())
        ((ArmorData*)((char*)this + 0x178))->FUN_00535aa0();
    AppendChunk(0x4d414e44, (char*)this + 0x178, 0xc);
    if (FUN_00401500())
        ((ArmorData*)((char*)this + 0x178))->FUN_00535aa0();
    ((FUN_00485680_shell*)this)->M();
}

extern int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
struct ArmaCompare : TESObjectARMA
{
    bool Compare(TESForm* apCompare);
};
// @fnv 0x00512940
bool ArmaCompare::Compare(TESForm* apCompare)
{
    TESObjectARMA* pcomp = dynamic_cast<TESObjectARMA*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;
    if (_memcmp(&data, &pcomp->data, sizeof(data)))
        return true;
    return false;
}

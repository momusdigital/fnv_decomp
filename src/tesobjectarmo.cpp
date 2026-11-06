// tesobjectarmo.cpp: TESObjectARMO, ArmorSerializer, ArmorCopy, TESObjectARMOFoley and more (15 functions)

#include "tesobjectarmo_decls.h"
#include "tesobjectarmo_load.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Warning(const char*, ...);

// @fnv 0x00512e10
void TESObjectARMO::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    m_bUsesSoundList = false;
    m_pSoundSourceArmor = 0;
    SetCastingType(MagicSystem__CastingType_CONSTANT_EFFECT);
}

// Returns 1 for heavy armor, 2 for medium armor, otherwise 0.
// @fnv 0x00514410
unsigned char TESObjectARMO::GetArmorType()
{
    if (GetIsHeavyArmor())
        return 1;
    if (GetIsMediumArmor())
        return 2;
    return 0;
}

// @fnv 0x00512e60
void TESObjectARMO::InitItem()
{
    if (IsFormInitialized())
        return;
    if (!m_kBipedModelForm.m_uiBipedModelFlags)
        Warning("MASTERFILE: Armor '%s' needs to have biped slots selected in the editor.", GetName());
    TESScriptableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESBipedModelForm::InitItem(this);
    BGSRepairItemList::InitItem(this);
    BGSBipedModelList::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    if (!m_bUsesSoundList && m_pSoundSourceArmor)
    {
        m_pSoundSourceArmor = static_cast<TESObjectARMO*>(GetFormByID((unsigned int)m_pSoundSourceArmor));
    }
    else if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        BSSimpleList<SoundDescriptor*>* soundList = m_pPickupPutdownSoundList;
        while (soundList && soundList->GetItem())
        {
            SoundDescriptor* sound = soundList->GetItem();
            soundList = soundList->GetNext();
            if (sound->SoundAssetTmp)
                sound->SoundAssetTmp = (TESSound*)GetFormByID((unsigned int)sound->SoundAssetTmp);
        }
    }
    SetInitializationState(true);
}

// Reads an ARMO record from the TESFile: checks form type 24, loads the record header, then dispatches each chunk to the matching sub-record loader.
// @fnv 0x00512fd0
bool TESObjectARMO::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 24)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 512);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 'IRCS': {
            unsigned int uiScriptFormID = 0;
            file->GetChunkData(&uiScriptFormID);
            SetScript((Script*)uiScriptFormID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'MANE':
        case 'MTIE': {
            unsigned int uiEnchantmentFormID = 0;
            file->GetChunkData(&uiEnchantmentFormID);
            SetFormEnchanting((EnchantmentItem*)uiEnchantmentFormID);
            break;
        }
        case 'MANA':
        case 'TMAE': {
            unsigned short usEnchantmentAmount = 0;
            ((TESFileChunkData16*)file)->GetChunkData(&usEnchantmentAmount);
            SetFormEnchantmentAmount(usEnchantmentAmount);
            break;
        }
        case 'TDMB': {
            if (((TESFileFormVersion*)file)->GetFormVersion() < 11)
            {
                TESObjectARMOOldBipedModel oldBipedModel;
                file->GetChunkData(&oldBipedModel, sizeof(oldBipedModel));
                if (file->IsEndianConversionRequired())
                    oldBipedModel.FUN_00512810();
                m_kBipedModelForm.m_ucBipedModelData = oldBipedModel.flags;
                m_kBipedModelForm.m_uiBipedModelFlags = oldBipedModel.slots;
            }
            else
            {
                file->GetChunkData(&m_kBipedModelForm, sizeof(m_kBipedModelForm));
                if (file->IsEndianConversionRequired())
                    m_kBipedModelForm.Endian();
            }
            m_kBipedModelForm.m_ucBipedModelData &= ~16;
            break;
        }
        case 'TCMB': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            m_kFaceGenModel.SetModelFilePath(name);
            break;
        }
        case 'LDOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            bipedModel[0].SetModelFilePath(name);
            break;
        }
        case 'TDOM':
            TESModel::LoadTextureSwapData(&bipedModel[0], file);
            break;
        case 'SDOM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[0], file);
            break;
        case 'DDOM':
            TESModel::LoadModelData(&bipedModel[0], file);
            break;
        case 'DSOM':
            TESModel::LoadModelData(&bipedModel[1], file);
            break;
        case '2DOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            worldModel[0].SetModelFilePath(name);
            break;
        }
        case 'T2OM':
            TESModel::LoadTextureSwapData(&worldModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&worldModel[0], file);
            break;
        case 'NOCI': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            ((TESTexture1024*)&m_kIcon[0])->SetTexture(name);
            break;
        }
        case 'OCIM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            messageIcon[0].SetMessageIconTextureName(name);
            break;
        }
        case '2CIM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            messageIcon[1].SetMessageIconTextureName(name);
            break;
        }
        case '3DOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            bipedModel[1].SetModelFilePath(name);
            break;
        }
        case 'T3OM':
            TESModel::LoadTextureSwapData(&bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[1], file);
            break;
        case '4DOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            worldModel[1].SetModelFilePath(name);
            break;
        }
        case 'T4OM':
            TESModel::LoadTextureSwapData(&worldModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&worldModel[1], file);
            break;
        case '2OCI': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            ((TESTexture1024*)&m_kIcon[1])->SetTexture(name);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'LPER': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            SetRepairList((BGSListForm*)uiListFormID);
            break;
        }
        case 'LPIB': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            SetBipedModelList((BGSListForm*)uiListFormID);
            break;
        }
        case 'PYTE': {
            unsigned int uiEquipType = 0;
            file->GetChunkData(&uiEquipType);
            SetEquipType((BGSEquipType__EQUIP_TYPE)uiEquipType);
            break;
        }
        case 'MANY': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetPickupSound((TESSound*)sound);
            break;
        }
        case 'MANZ': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetPutdownSound((TESSound*)sound);
            break;
        }
        case 'MANB': {
            unsigned int isBase = 0;
            file->GetChunkData(&isBase);
            if (isBase)
                m_bUsesSoundList = true;
            else
                m_bUsesSoundList = false;
            break;
        }
        case 'MANT': {
            if (!m_bUsesSoundList)
            {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pSoundSourceArmor = (TESObjectARMO*)formID;
            }
            break;
        }
        case 'MANS': {
            if (m_bUsesSoundList)
            {
                if (!m_pPickupPutdownSoundList)
                    m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
                SoundDescriptor* sound = new SoundDescriptor;
                ReadTypedData(file, sound, sizeof(SoundDescriptor));
                if (file->IsEndianConversionRequired())
                    sound->Endian();
                m_pPickupPutdownSoundList->AddHead(sound);
            }
            break;
        }
        case 'ATAD': {
            unsigned int added = GetDataSizeAdjustment();
            if (file->GetChunkSize() - added == 2)
            {
                TESObjectARMOOldData oldArmoData;
                memset(&oldArmoData, 0, sizeof(oldArmoData));
                ReadTypedData(file, &oldArmoData, sizeof(oldArmoData));
                if (file->IsEndianConversionRequired())
                    oldArmoData.FUN_00512810();
                memcpy(&data, &oldArmoData, sizeof(oldArmoData));
                data.cFlags = 0;
            }
            else
            {
                ReadTypedData(file, 0, 0);
            }
            break;
        }
        case 'MAND': {
            memset(&data, 0, sizeof(data));
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.FUN_00535aa0();
            break;
        }
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
            data.FUN_00535aa0();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00514450_shell : public TESBipedModelForm
{
    bool IsMedium();
};

// @fnv 0x00514450
bool FUN_00514450_shell::IsMedium()
{
    return *((unsigned char*)this + 8) & 8;
}

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_0048e9b0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_00514470
{
    FUN_00484bf0 m_00;
    unsigned char m_58[0x58];
    unsigned short GetSaveSize(unsigned int);
};

// Returns the sum of the save sizes reported by the sub-object at offset 0 and the one at offset 0x58, both queried with aiFlags.
// @fnv 0x00514470
unsigned short FUN_00514470::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += m_00.GetSaveSize(aiFlags);
    isize += ((FUN_0048e9b0*)((char*)this + 0x58))->GetSaveSize(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
    void FUN_00484c20(unsigned int);
    void FUN_0048e9e0(unsigned int);
};
struct FUN_00516040_shell
{
    FUN_0051b070_shell m0;
    char _pad[0x58 - sizeof(FUN_0051b070_shell)];
    FUN_0051b070_shell m58;
    void FUN_00516040(unsigned int);
};
// Calls FUN_00484c20 on m0 and FUN_0048e9e0 on m58, passing aiFlags to each.
// @fnv 0x00516040
void FUN_00516040_shell::FUN_00516040(unsigned int aiFlags)
{
    m0.FUN_00484c20(aiFlags);
    m58.FUN_0048e9e0(aiFlags);
}

struct TESFormStub
{
    void __thiscall FUN_00484c50(unsigned int, unsigned int);
};

struct TESValueFormStub
{
    void __thiscall FUN_0048ea10(unsigned int, unsigned int);
};

struct FUN_00516070_shell
{
    char _pad[0x58];
    TESValueFormStub m_valueStub;
    void __thiscall FUN_00516070(unsigned int, unsigned int);
};

// Forwards both arguments to TESFormStub::FUN_00484c50 on this object, then to m_valueStub.FUN_0048ea10.
// @fnv 0x00516070
void __thiscall FUN_00516070_shell::FUN_00516070(unsigned int a1, unsigned int a2)
{
    reinterpret_cast<TESFormStub*>(this)->FUN_00484c50(a1, a2);
    m_valueStub.FUN_0048ea10(a1, a2);
}

struct B1_4fe
{
    virtual ~B1_4fe();
    B1_4fe();
    char pad[0x2c];
};
namespace stand {
struct TESFullName
{
    virtual void f0();
    TESFullName();
    ~TESFullName();
    char pad[0x8];
};
struct TESScriptableForm
{
    virtual void f0();
    TESScriptableForm();
    char pad[0x8];
};
struct TESEnchantableForm
{
    virtual void f0();
    TESEnchantableForm();
    char pad[0xc];
};
struct TESValueForm
{
    virtual void f0();
    TESValueForm();
    ~TESValueForm();
    char pad[0x4];
};
struct TESWeightForm
{
    virtual void f0();
    TESWeightForm();
    ~TESWeightForm();
    char pad[0x4];
};
struct TESHealthForm
{
    virtual void f0();
    TESHealthForm();
    ~TESHealthForm();
    char pad[0x4];
};
struct TESBipedModelForm
{
    virtual void f0();
    TESBipedModelForm();
    ~TESBipedModelForm();
    char pad[0xd8];
};
struct BGSDestructibleObjectForm
{
    virtual void f0();
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    char pad[0x4];
};
struct BGSEquipType
{
    virtual void f0();
    BGSEquipType();
    char pad[0x4];
};
struct BGSRepairItemList
{
    virtual void f0();
    BGSRepairItemList();
    ~BGSRepairItemList();
    char pad[0x4];
};
struct BGSBipedModelList
{
    virtual void f0();
    BGSBipedModelList();
    ~BGSBipedModelList();
    char pad[0x4];
};
struct BGSPickupPutdownSounds
{
    virtual void f0();
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    char pad[0x8];
};
}
struct SoundPlaybackHandle
{
    void SetFormType(int);
};
struct FUN_005129f0_ARMO
{
    void ResetFormData();
};
struct FUN_005129f0 : public B1_4fe,
                      public stand::TESFullName,
                      public stand::TESScriptableForm,
                      public stand::TESEnchantableForm,
                      public stand::TESValueForm,
                      public stand::TESWeightForm,
                      public stand::TESHealthForm,
                      public stand::TESBipedModelForm,
                      public stand::BGSDestructibleObjectForm,
                      public stand::BGSEquipType,
                      public stand::BGSRepairItemList,
                      public stand::BGSBipedModelList,
                      public stand::BGSPickupPutdownSounds
{
    unsigned char data[0xc];
    unsigned int flags;
    void* m_pPickupPutdownSoundList;
    bool m_bUsesSoundList;
    FUN_005129f0();
    virtual ~FUN_005129f0();
};
// Sets the form type to 0x18 and then runs the ARMO-specific initialization on this object.
// @fnv 0x005129f0
FUN_005129f0::FUN_005129f0()
{
    ((SoundPlaybackHandle*)this)->SetFormType(0x18);
    ((FUN_005129f0_ARMO*)this)->ResetFormData();
}

struct FUN_0050e9f0 : public TESBoundObject
{
    ~FUN_0050e9f0();
};
struct FUN_00591300 : public TESFullName
{
    ~FUN_00591300();
};
struct FUN_0048e7d0 : public TESValueForm
{
    ~FUN_0048e7d0();
};
struct FUN_0048eaf0 : public TESWeightForm
{
    ~FUN_0048eaf0();
};
struct FUN_00487200 : public TESHealthForm
{
    ~FUN_00487200();
};
struct FUN_00480400 : public TESBipedModelForm
{
    ~FUN_00480400();
};
struct FUN_00475380 : public BGSDestructibleObjectForm
{
    ~FUN_00475380();
};
struct FUN_0047b880 : public BGSRepairItemList
{
    ~FUN_0047b880();
};
struct FUN_00474d40 : public BGSBipedModelList
{
    ~FUN_00474d40();
};
struct FUN_0047b520 : public BGSPickupPutdownSounds
{
    ~FUN_0047b520();
};
class FUN_00512bd0 : public FUN_0050e9f0,
                     public FUN_00591300,
                     public TESScriptableForm,
                     public TESEnchantableForm,
                     public FUN_0048e7d0,
                     public FUN_0048eaf0,
                     public FUN_00487200,
                     public FUN_00480400,
                     public FUN_00475380,
                     public BGSEquipType,
                     public FUN_0047b880,
                     public FUN_00474d40,
                     public FUN_0047b520
{
  public:
    virtual ~FUN_00512bd0();
};
// @fnv 0x00512bd0
FUN_00512bd0::~FUN_00512bd0()
{}

bool FUN_00401500();
void AppendChunk(unsigned int, void*, unsigned int);
void FUN_00485910(unsigned int, unsigned int);
struct FUN_004855a0_shell
{
    void FUN_004855a0();
    void FUN_00485680();
    void FUN_00485e00();
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};
struct S_00480610
{
    void InitBipedModel();
};
struct S_00477f20
{
    void FUN_00477f20();
};
struct S0047b8a0
{
    void FUN_0047b8a0();
};
struct FUN_00474d60_shell
{
    void FUN_00474d60();
};
struct FUN_00479350_shell
{
    void FUN_00479350();
};
struct FUN_0047b560_holder
{
    void LogFormIDs();
};
struct RefObj
{
    unsigned int _ref_0084e3a0();
};
struct FoleyNode : BSSimpleList<SoundDescriptor*>
{
    SoundDescriptor*& FUN_006815c0();
    FoleyNode* FUN_00726070();
};
struct FUN_00513d60
{
    unsigned int formID;
    unsigned char soundType;
    int value;
    FUN_00513d60();
    void FUN_00483710();
};
struct ArmorSerializer
{
    TESBoundObject bound;
    TESFullName fullName;
    TESScriptableForm scriptable;
    TESEnchantableForm enchantable;
    TESValueForm valueForm;
    TESWeightForm weightForm;
    TESHealthForm healthForm;
    TESBipedModelForm biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    BGSRepairItemList repairList;
    BGSBipedModelList modelList;
    BGSPickupPutdownSounds pickupSounds;
    ArmorData data;
    unsigned int flags;
    union
    {
        BSSimpleList<SoundDescriptor*>* m_pPickupPutdownSoundList;
        TESObjectARMO* m_pSoundSourceArmor;
    };
    bool m_bUsesSoundList;
    void Save();
};

// @fnv 0x00513d90
void ArmorSerializer::Save()
{
    ((FUN_004855a0_shell*)this)->FUN_004855a0();
    ((FUN_00487010_shell*)&fullName)->FUN_00487010();
    ((S_0048cca0*)&scriptable)->FUN_0048cca0();
    ((FUN_0047bd70_shell*)&enchantable)->FUN_0047bd70();
    ((S_00480610*)&biped)->InitBipedModel();
    ((S_00477f20*)&destructible)->FUN_00477f20();
    ((S0047b8a0*)&repairList)->FUN_0047b8a0();
    ((FUN_00474d60_shell*)&modelList)->FUN_00474d60();
    ((FUN_00479350_shell*)&equipType)->FUN_00479350();
    ((FUN_0047b560_holder*)&pickupSounds)->LogFormIDs();
    ((FUN_004855a0_shell*)this)->FUN_00485e00();
    if (FUN_00401500())
        data.FUN_00535aa0();
    AppendChunk(0x4d414e44, &data, sizeof(data));
    if (FUN_00401500())
        data.FUN_00535aa0();
    FUN_00485910(0x4d414e42, m_bUsesSoundList ? 1 : 0);
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor)
        {
            unsigned int formID = ((RefObj*)m_pSoundSourceArmor)->_ref_0084e3a0();
            FUN_00485910(0x4d414e54, formID);
        }
    }
    else if (m_pPickupPutdownSoundList)
    {
        FoleyNode* node = (FoleyNode*)m_pPickupPutdownSoundList;
        while (node && node->FUN_006815c0())
        {
            SoundDescriptor* sound = node->FUN_006815c0();
            node = node->FUN_00726070();
            if (sound && sound->SoundAssetTmp)
            {
                FUN_00513d60 saved;
                saved.formID = ((RefObj*)sound->SoundAssetTmp)->_ref_0084e3a0();
                saved.soundType = sound->layoutPadding4[0];
                saved.value = sound->eType;
                if (FUN_00401500())
                    saved.FUN_00483710();
                AppendChunk(0x4d414e53, &saved, sizeof(saved));
                if (FUN_00401500())
                    saved.FUN_00483710();
            }
        }
    }
    ((FUN_004855a0_shell*)this)->FUN_00485680();
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct ArmorCopy : TESObjectARMO
{
    void CopyBase(TESForm*);
    void CopyArmorData(TESForm* form);
};
// @fnv 0x00513fa0
void ArmorCopy::CopyArmorData(TESForm* form)
{
    TESObjectARMO* source3 = dynamic_cast<TESObjectARMO*>(form);
    BSSimpleList<SoundDescriptor*>* node_;
    BSSimpleList<SoundDescriptor*>* iter;
    SoundDescriptor* original9;
    SoundDescriptor* copy7;
    SoundDescriptor* sound;
    if (!source3)
        return;
    CopyBase(form);
    data = source3->data;
    if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        node_ = m_pPickupPutdownSoundList;
        while (node_ && node_->GetItem())
        {
            sound = node_->GetItem();
            operator delete(sound);
            node_ = node_->GetNext();
        }
        m_pPickupPutdownSoundList->RemoveAll();
        delete m_pPickupPutdownSoundList;
    }
    m_bUsesSoundList = source3->m_bUsesSoundList;
    if (!m_bUsesSoundList)
        m_pPickupPutdownSoundList = source3->m_pPickupPutdownSoundList;
    else
    {
        m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
        if (source3->m_pPickupPutdownSoundList)
        {
            iter = source3->m_pPickupPutdownSoundList;
            while (iter && iter->GetItem())
            {
                original9 = iter->GetItem();
                iter = iter->GetNext();
                if (original9 && original9->SoundAssetTmp)
                {
                    copy7 = new SoundDescriptor;
                    *copy7 = *original9;
                    m_pPickupPutdownSoundList->AddHead(copy7);
                }
            }
        }
    }
}

unsigned int DialogueRandom();

class TESObjectARMOFoley : public TESObjectARMO
{
  public:
    TESSound* GetFoleySound(int eType);
};

// Scans the armor's foley list for an entry matching eType whose random chance roll succeeds, returning its sound or null.
// @fnv 0x00512d40
TESSound* TESObjectARMOFoley::GetFoleySound(int eType)
{
    BSSimpleList<SoundDescriptor*>* pFoleyList;
    TESSound* pkSound = 0;
    SoundDescriptor* pkFoley;

    pFoleyList = m_bUsesSoundList ? m_pPickupPutdownSoundList
                                  : (m_pSoundSourceArmor ? m_pSoundSourceArmor->m_pPickupPutdownSoundList : 0);
    while (pFoleyList && !pFoleyList->IsEmpty() && !pkSound)
    {
        pkFoley = pFoleyList->GetItem();
        pFoleyList = pFoleyList->GetNext();
        if (pkFoley->SoundAssetTmp && pkFoley->eType == eType && (int)(DialogueRandom() & 0x63) < pkFoley->layoutPadding4[0])
            pkSound = pkFoley->SoundAssetTmp;
    }
    return pkSound;
}

struct FUN_00512ba0 : TESObjectARMO
{
    virtual ~FUN_00512ba0();
};
// @fnv 0x00512ba0
FUN_00512ba0::~FUN_00512ba0()
{}

#include <string.h>
struct ArmorCompare : TESObjectARMO
{
    bool FUN_00485270(TESObjectARMO* other);
    bool IsDifferentFrom(TESForm* form);
};
// Returns true if form is not an armor or differs in base compare, data, sound source armor, or pickup/putdown sound list entries.
// @fnv 0x00514220
bool ArmorCompare::IsDifferentFrom(TESForm* form)
{
    TESObjectARMO* pOther = dynamic_cast<TESObjectARMO*>(form);
    if (!pOther)
        return true;
    if (FUN_00485270(pOther))
        return true;
    if (memcmp(&data, &pOther->data, 12))
        return true;
    if (m_bUsesSoundList != pOther->m_bUsesSoundList)
        return true;
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor != pOther->m_pSoundSourceArmor)
            return true;
    }
    else
    {
        if (pOther->m_pPickupPutdownSoundList && m_pPickupPutdownSoundList &&
            pOther->m_pPickupPutdownSoundList->GetItem() == m_pPickupPutdownSoundList->GetItem())
        {
            BSSimpleList<SoundDescriptor*>* pCurrent = m_pPickupPutdownSoundList;
            while (pCurrent && pCurrent->GetItem())
            {
                bool bFound = false;
                BSSimpleList<SoundDescriptor*>* search = pOther->m_pPickupPutdownSoundList;
                while (search && search->GetItem())
                {
                    if (pCurrent->GetItem()->SoundAssetTmp == search->GetItem()->SoundAssetTmp &&
                        pCurrent->GetItem()->layoutPadding4[0] == search->GetItem()->layoutPadding4[0] &&
                        pCurrent->GetItem()->eType == search->GetItem()->eType)
                    {
                        bFound = true;
                        break;
                    }
                    search = search->GetNext();
                }
                if (!bFound)
                    return true;
                pCurrent = pCurrent->GetNext();
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

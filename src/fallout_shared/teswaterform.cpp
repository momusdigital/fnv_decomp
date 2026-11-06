// fallout_shared/teswaterform.cpp: TESWaterForm, BGSPlaceableWater, WaterShaderSettings, Holder and more (27 functions)

#include "teswaterform_decls.h"
#include "teswaterform_types_TESWaterForm.h"

// @fnv 0x0057ef10
void TESWaterForm::ResetFormData()
{
    m_ucOpacity = 0x4B;
    cFlags = 0;
    m_pWaterSound = 0;
    m_kMaterialId.Set(0, 0);
    FUN_0057eef0()->Initialize();

    for (int i = 0; i < 3; ++i)
        m_apWaterForms[i] = 0;
}

// Initializes the object's fields with default constants and global values.
// @fnv 0x0057e9c0
void WaterShaderSettings::Initialize()
{
    SplatterSettings = g_splatterDefaultSecond;
    m_fSecondParameter = DAT_010249d8;
    m_fThirdParameter = 0.5f;
    m_fFourthSetting = 1.0f;
    SevenFloatParameterData = DAT_0101b268;
    SevenFloatParameters = 0.5f;
    SevenFloatData = DAT_010313d4;
    m_fEighthParameter = 0.0f;
    FiveFloatAndTwoUnsignedIntegerRecord = 0.0f;
    FourFloatAndThreeUnsignedIntegerRecord = 0.0f;
    WaterFogSettings = 1.0f;
    fUnderwaterFogDistNear = 0.0f;
    fUnderwaterFogDistFar = DAT_01013974;
    fUnderwaterFogAmount = 1.0f;
    FloatColorSettingsRecord = 0x00808000;
    ShaderColorParameterBlock = 0x00190000;
    ColorSettingsRecord = 0x00FFFFFF;
    SplatterColorSettings = g_splatterDefaultSecond;
    SplatterScalarSettings = DAT_01018180;
    SplatterFloatSettings = DAT_010231a4;
    SplatterParameterSet = DAT_010162c0;
    SplatterTimingSettings = 0.01f;
    SevenFloatRecordWithGlobals = DAT_010231a8;
    SevenFloatRecordWithStepAndGlobals = DAT_01018180;
    SevenFloatRecordWithStep = DAT_010231a4;
    SevenFloatFormatBlock = 10.0f;
    SevenFloatRecordWithUnitValue = DAT_010181bc;
    m_fWaterFogParameter1 = 0.0f;
    m_fValueBeforeWaterFogSettings = 0.0f;
    SevenFloatParameterSet = 1.0f;
    WaterFogParameterData = DAT_01013d84;
    m_fWaterParameter1 = 100.0f;
    m_fWaterParameter2 = 100.0f;
    m_fWaterParameter3 = 100.0f;
    WaterShaderProperties = DAT_0101b2d0;
    m_fShininess = 100.0f;
    WaterShaderParameters = 1.0f;
    MaterialParametersWithLeadingFloat = DAT_01022958;
    MaterialParameters = 1.0f;
}

// @fnv 0x0057f8b0
void TESWaterForm::InitItem()
{
    if (GetInitialized())
        return;
    unsigned int id = (unsigned int)m_pWaterSound;
    if (id)
    {
        RemapFormIDForFile(id, GetFile(-1));
        m_pWaterSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(id));
        if (!m_pWaterSound)
            Warning("MASTERFILE: Could not find sound (%08X) for water type '%s' (%08X).", id, GetName(), GetFormID());
    }
    id = (unsigned int)m_pWaterSpell;
    if (id)
    {
        RemapFormIDForFile(id, GetFile(-1));
        m_pWaterSpell = dynamic_cast<SpellItem*>(TESForm::GetFormByID(id));
        if (!m_pWaterSpell)
            Warning("MASTERFILE: Could not find sound (%08X) for spell item '%s' (%08X).", id, GetName(), GetFormID());
        if (m_pWaterSpell && !m_pWaterSpell->IsEmpty())
        {
            WaterEffectList* node = m_pWaterSpell;
            EffectItem* radiation = 0;
            EffectItem* health = 0;
            while (node && (!radiation || !health))
            {
                EffectItem* effect = node->GetItem();
                if (effect->GetAffectedActorValue() == 54 && effect->GetEffectSetting()->IsFlagSet(4))
                {
                    radiation = effect;
                    m_iRadiationMagnitude = radiation->GetMagnitude();
                }
                else if (effect->GetAffectedActorValue() == 16 && !effect->GetEffectSetting()->IsFlagSet(4))
                {
                    health = effect;
                    m_iHealthMagnitude = health->GetMagnitude();
                }
                node = static_cast<WaterEffectList*>(node->GetNext());
            }
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        id = (unsigned int)m_apWaterForms[i];
        if (id)
        {
            RemapFormIDForFile(id, GetFile(-1));
            m_apWaterForms[i] = dynamic_cast<TESWaterForm*>(TESForm::GetFormByID(id));
            if (!m_apWaterForms[i])
                Warning("MASTERFILE: Could not find WaterForm (%08X) for water type '%s' (%08X).", id, GetName(),
                        GetFormID());
        }
    }
    SetInitializationState(true);
}

// Reads a TESWaterForm record from file: checks form type 78, loads the header, then processes chunks (EDID, OBND, FULL, DATA, DNAM, etc.) into the form's fields.
// @fnv 0x0057ef80
bool TESWaterForm::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 78)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch ((int)uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x41544144: {
            unsigned int uiAddedSize = file->GetChunkSize() - GetDataSizeAdjustment();
            if (!uiAddedSize)
            {
                reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, 0, 0);
                if (file->IsEndianConversionRequired())
                    Data.Endian();
            }
            else
            {
                reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, 196);
                if (file->IsEndianConversionRequired())
                    Data.Endian();
                Data.m_fWaterParameter1 = 100.0f;
                Data.m_fWaterParameter2 = 100.0f;
                Data.m_fWaterParameter3 = 100.0f;
                Data.m_fWaterParameter4 = 1.0f;
                Data.m_fWaterParameter5 = 0.5f;
                Data.m_fWaterParameter6 = 0.25f;
                SetAttackDamage(0);
            }
            break;
        }
        case 0x4d414e44:
            file->GetChunkData(&Data, 196);
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        case 0x4d414e4e:
            TESTextureLoader::ReadTextureData(&m_kNoiseMapTexture, file);
            break;
        case 0x4d414e41:
            file->GetChunkData(&m_ucOpacity, 1);
            break;
        case 0x4d414e46:
            file->GetChunkData(&cFlags, 1);
            break;
        case 0x4d414e53: {
            unsigned int shader = 0;
            file->GetChunkData(&shader);
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader((TESEffectShader*)shader);
            break;
        }
        case 0x4d414e58: {
            unsigned int spell = 0;
            file->GetChunkData(&spell);
            SetSpellItem((SpellItem*)spell);
            break;
        }
        case 0x4d414e4d: {
            char* material = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(material, 0);
            m_kMaterialId.Set(material, 0);
            break;
        }
        case 0x4d414e47:
            file->GetChunkData(m_apWaterForms, 12);
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < 3; ++i)
                    BSEndian((unsigned int*)&m_apWaterForms[i], EndianSizeTag<4>());
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_0057eef0_shell : public TESWaterForm
{
    WaterShaderSettings* FUN_0057eef0();
};

// @fnv 0x0057eef0
WaterShaderSettings* FUN_0057eef0_shell::FUN_0057eef0()
{
    return &Data;
}

struct FUN_0057f890_shell : public TESWaterForm
{
    void FUN_0057f890(SpellItem*);
};

// @fnv 0x0057f890
void FUN_0057f890_shell::FUN_0057f890(SpellItem* apSpellItem)
{
    m_pWaterSpell = apSpellItem;
}

struct FUN_0057fed0
{
    unsigned int m_0178;
    unsigned int GetMember();
};

// @fnv 0x0057fed0
unsigned int FUN_0057fed0::GetMember()
{
    return *(unsigned int*)((char*)this + 0x178);
}

struct BSStr
{
    bool Set(const char* s, unsigned int len);
};

struct FUN_0057fef0_shell
{
    char m_auiShapeKeys[0x74];
    BSStr m_str;
    void SetMaterialName(const char* name);
};

// @fnv 0x0057fef0
void FUN_0057fef0_shell::SetMaterialName(const char* name)
{
    m_str.Set(name, 0);
}

struct FUN_00580060_shell
{
    unsigned char _0000;  // +0x00
    unsigned char _0001;  // +0x01
    unsigned char _0002;  // +0x02
    unsigned char _0003;  // +0x03
    unsigned char _0004;  // +0x04
    unsigned char _0005;  // +0x05
    unsigned char _0006;  // +0x06
    unsigned char _0007;  // +0x07
    unsigned char _0008;  // +0x08
    unsigned char _0009;  // +0x09
    unsigned char _000A;  // +0x0A
    unsigned char _000B;  // +0x0B
    unsigned char _000C;  // +0x0C
    unsigned char _000D;  // +0x0D
    unsigned char _000E;  // +0x0E
    unsigned char _000F;  // +0x0F
    unsigned char _0010;  // +0x10
    unsigned char _0011;  // +0x11
    unsigned char _0012;  // +0x12
    unsigned char _0013;  // +0x13
    unsigned char _0014;  // +0x14
    unsigned char _0015;  // +0x15
    unsigned char _0016;  // +0x16
    unsigned char _0017;  // +0x17
    unsigned char _0018;  // +0x18
    unsigned char _0019;  // +0x19
    unsigned char _001A;  // +0x1A
    unsigned char _001B;  // +0x1B
    unsigned char _001C;  // +0x1C
    unsigned char _001D;  // +0x1D
    unsigned char _001E;  // +0x1E
    unsigned char _001F;  // +0x1F
    unsigned char _0020;  // +0x20
    unsigned char _0021;  // +0x21
    unsigned char _0022;  // +0x22
    unsigned char _0023;  // +0x23
    unsigned char _0024;  // +0x24
    unsigned char _0025;  // +0x25
    unsigned char _0026;  // +0x26
    unsigned char _0027;  // +0x27
    unsigned char _0028;  // +0x28
    unsigned char _0029;  // +0x29
    unsigned char _002A;  // +0x2A
    unsigned char _002B;  // +0x2B
    unsigned char _002C;  // +0x2C
    unsigned char _002D;  // +0x2D
    unsigned char _002E;  // +0x2E
    unsigned char _002F;  // +0x2F
    unsigned char _0030;  // +0x30
    unsigned char _0031;  // +0x31
    unsigned char _0032;  // +0x32
    unsigned char _0033;  // +0x33
    unsigned char _0034;  // +0x34
    unsigned char _0035;  // +0x35
    unsigned char _0036;  // +0x36
    unsigned char _0037;  // +0x37
    unsigned char _0038;  // +0x38
    unsigned char _0039;  // +0x39
    unsigned char _003A;  // +0x3A
    unsigned char _003B;  // +0x3B
    unsigned char _003C;  // +0x3C
    unsigned char _003D;  // +0x3D
    unsigned char _003E;  // +0x3E
    unsigned char _003F;  // +0x3F
    unsigned char _0040;  // +0x40
    unsigned char _0041;  // +0x41
    unsigned char _0042;  // +0x42
    unsigned char _0043;  // +0x43
    unsigned char _0044;  // +0x44
    unsigned char _0045;  // +0x45
    unsigned char _0046;  // +0x46
    unsigned char _0047;  // +0x47
    unsigned char _0048;  // +0x48
    unsigned char _0049;  // +0x49
    unsigned char _004A;  // +0x4A
    unsigned char _004B;  // +0x4B
    unsigned char _004C;  // +0x4C
    unsigned char _004D;  // +0x4D
    unsigned char _004E;  // +0x4E
    unsigned char _004F;  // +0x4F
    unsigned char _0050;  // +0x50
    unsigned char _0051;  // +0x51
    unsigned char _0052;  // +0x52
    unsigned char _0053;  // +0x53
    unsigned char _0054;  // +0x54
    unsigned char _0055;  // +0x55
    unsigned char _0056;  // +0x56
    unsigned char _0057;  // +0x57
    unsigned char _0058;  // +0x58
    unsigned char _0059;  // +0x59
    unsigned char _005A;  // +0x5A
    unsigned char _005B;  // +0x5B
    unsigned char _005C;  // +0x5C
    unsigned char _005D;  // +0x5D
    unsigned char _005E;  // +0x5E
    unsigned char _005F;  // +0x5F
    unsigned char _0060;  // +0x60
    unsigned char _0061;  // +0x61
    unsigned char _0062;  // +0x62
    unsigned char _0063;  // +0x63
    unsigned char _0064;  // +0x64
    unsigned char _0065;  // +0x65
    unsigned char _0066;  // +0x66
    unsigned char _0067;  // +0x67
    unsigned char _0068;  // +0x68
    unsigned char _0069;  // +0x69
    unsigned char _006A;  // +0x6A
    unsigned char _006B;  // +0x6B
    unsigned char _006C;  // +0x6C
    unsigned char _006D;  // +0x6D
    unsigned char _006E;  // +0x6E
    unsigned char _006F;  // +0x6F
    unsigned char _0070;  // +0x70
    unsigned char _0071;  // +0x71
    bool FUN_00580060();
};

// @fnv 0x00580060
bool FUN_00580060_shell::FUN_00580060()
{
    if (this->_0071 & 1)
        return true;
    return false;
}

struct TESModel
{
    unsigned int GetModelLength() const;
};

struct FUN_00580080_shell
{
    unsigned int FUN_00580080();
};

// @fnv 0x00580080
unsigned int FUN_00580080_shell::FUN_00580080()
{
    return ((TESModel*)((char*)this + 0x64))->GetModelLength();
}

struct FNStub
{
    char const* GetFullName() const;
};

struct FUN_005800a0_shell
{
    char const* FUN_005800a0() const;
};

// @fnv 0x005800a0
char const* FUN_005800a0_shell::FUN_005800a0() const
{
    return ((FNStub*)((const char*)this + 0x64))->GetFullName();
}

struct NP
{
    NP& operator=(void*);
};

struct FUN_005800c0_shell
{
    void* m_auiShapeKeys[0x17c / 4];
    NP m_np;  // +0x17c
    void SetNP(void* arg);
};

// @fnv 0x005800c0
void FUN_005800c0_shell::SetNP(void* apValue)
{
    m_np = apValue;
}

struct FormChangeMask
{
    unsigned int uiFlags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct FUN_00865df0_buf : BGSLoadFormBuffer
{
    void FUN_00865df0(void*, int);
};
struct FUN_005806e0_s
{
    char pad[0x80];
    void* m_pWaterForm;
    void SaveIfChanged(FUN_00865df0_buf*);
    void AppendSaveLoadFormBuffer(FUN_00865df0_buf* apSaveGameBuffer);
};
// @fnv 0x005806e0
void FUN_005806e0_s::AppendSaveLoadFormBuffer(FUN_00865df0_buf* apSaveGameBuffer)
{
    SaveIfChanged(apSaveGameBuffer);
    if (apSaveGameBuffer->GetChangeFlags(0x80000000))
        apSaveGameBuffer->FUN_00865df0(m_pWaterForm, 0);
}

namespace fnv_005807a0 {
struct FormChangeMask
{
    unsigned int m_flags;
    __forceinline operator bool() const
    {
        return m_flags != 0;
    }
};

struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int) const;
};

struct FUN_005807a0_shell : TESForm
{
    void FUN_005807a0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x005807a0
void FUN_005807a0_shell::FUN_005807a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (apLoadGameBuffer->GetOldChangeFlags(0x80000000))
        *(void**)((char*)this + 0x80) = 0;
}
}  // namespace fnv_005807a0

struct FUN_004fc990_t
{
    void FUN_004fc990(int, bool);
};
struct FUN_005802f0_shell
{
    void FUN_005802f0(bool abFlag);
};
// @fnv 0x005802f0
void FUN_005802f0_shell::FUN_005802f0(bool abFlag)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x20, abFlag);
}

struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
    unsigned int ReadFormIdentifier();
};

struct FUN_00580730_shell : public TESWaterForm
{
    void FUN_00580730(BGSLoadGameBuffer* apLoadGameBuffer);
};

// @fnv 0x00580730
void FUN_00580730_shell::FUN_00580730(BGSLoadGameBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000))
        m_pWaterForm = dynamic_cast<TESWaterForm*>(TESForm::GetFormByID(apLoadGameBuffer->ReadFormIdentifier()));
}

struct Flt
{
    operator unsigned int() const;
};
struct Holder
{
    unsigned char _pad[0x74];
    Flt m_kHandle;
    const char* GetMaterialName();
};
// Returns the stored string pointer if the field is nonzero, otherwise an empty string literal.
// @fnv 0x0057fda0
const char* Holder::GetMaterialName()
{
    return m_kHandle ? (const char*)(unsigned int)m_kHandle : "";
}

extern double g_d100;
struct FUN_00580100_obj
{
    unsigned char pad[0x70];
    unsigned char b70;
    float FUN_00580100();
};
// @fnv 0x00580100
float FUN_00580100_obj::FUN_00580100()
{
    return b70 / g_d100;
}

struct FUN_004855a0_standin
{
    void FUN_004855a0();
};
struct FUN_00485680_standin
{
    void FUN_00485680();
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct S7010
{
    unsigned int Length();
};
void FUN_004856f0(unsigned int id, void* data, unsigned int size);
void FUN_004858f0(unsigned int id, unsigned char value);
void FUN_00485910(unsigned int id, unsigned int value);
void AppendChunk(unsigned int id, void* data, unsigned int size);
void FUN_00485710(unsigned int id, unsigned int* data, unsigned int count);
bool FUN_00401500();

struct FUN_0057fbf0_shell : public TESWaterForm
{
    void SaveWaterForm();
};

// Serializes the water form: writes name, model, flags, form IDs, and a 0xc4-byte Data block, swapping endianness when needed.
// @fnv 0x0057fbf0
void FUN_0057fbf0_shell::SaveWaterForm()
{
    unsigned int auiFormIds[3];
    ((FUN_004855a0_standin*)this)->FUN_004855a0();
    ((FUN_00487010_shell*)((char*)this + 0x18))->FUN_00487010();
    FUN_004856f0(0x4d414e4e, (void*)((FNStub*)((char*)this + 0x64))->GetFullName(),
                 ((TESModel*)((char*)this + 0x64))->GetModelLength() + 1);
    FUN_004858f0(0x4d414e41, m_ucOpacity);
    FUN_004858f0(0x4d414e46, cFlags);
    FUN_004856f0(0x4d414e4d, (void*)((Holder*)this)->GetMaterialName(), ((S7010*)((char*)this + 0x74))->Length() + 1);
    if (m_pWaterSound)
    {
        unsigned int itempint = m_pWaterSound->GetFormID();
        FUN_00485910(0x4d414e53, itempint);
    }
    if (m_pWaterSpell)
    {
        unsigned int itempint = m_pWaterSpell->GetFormID();
        FUN_00485910(0x4d414e58, itempint);
    }
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (FUN_00401500())
        Data.Endian();
    AppendChunk(0x4d414e44, &Data, 0xc4);
    if (FUN_00401500())
        Data.Endian();
    for (int i = 0; i < 3; i++)
    {
        if (m_apWaterForms[i])
            auiFormIds[i] = m_apWaterForms[i]->GetFormID();
        else
            auiFormIds[i] = 0;
    }
    FUN_00485710(0x4d414e47, auiFormIds, 3);
    ((FUN_00485680_standin*)this)->FUN_00485680();
}

struct FUN_0057ff10_shell : public TESWaterForm
{
    bool FUN_0057ff10(TESForm* apCompare);
};

struct TESPackage
{
    unsigned int GetRefCount();
};

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};

struct FUN_0057ff10_texture
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool operator==(FUN_0057ff10_texture*);
};

extern int __cdecl _memcmp(const void*, const void*, unsigned int);

// @fnv 0x0057ff10
bool FUN_0057ff10_shell::FUN_0057ff10(TESForm* apCompare)
{
    TESWaterForm* pcomp;

    pcomp = dynamic_cast<TESWaterForm*>(apCompare);
    if (pcomp == 0)
        return true;

    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;

    if (*(unsigned char*)((char*)this + 0x71) != *(unsigned char*)((char*)pcomp + 0x71))
        return true;

    if (*(unsigned char*)((char*)this + 0x70) != *(unsigned char*)((char*)pcomp + 0x70))
        return true;

    if (_memcmp(FUN_0057eef0(), pcomp->FUN_0057eef0(), 0xc4) != 0)
        return true;

    if (((FUN_0057ff10_texture*)((char*)this + 0x64))->operator==((FUN_0057ff10_texture*)((char*)pcomp + 0x64)))
        return true;

    if (((TESPackage*)this)->GetRefCount() != ((TESPackage*)pcomp)->GetRefCount())
        return true;

    if (((Holder*)this)->GetMaterialName() != ((Holder*)pcomp)->GetMaterialName())
        return true;

    if (((FUN_0057fed0*)this)->GetMember() != ((FUN_0057fed0*)pcomp)->GetMember())
        return true;

    if (_memcmp((char*)this + 0x148, (char*)pcomp + 0x148, 0xc) != 0)
        return true;

    return false;
}

struct BGSPlaceableWater : public TESForm
{
    unsigned char _padding[0x38];

    BGSPlaceableWater();
    void FUN_004fc450(bool);
    void FUN_004fc3a0(bool);
};

struct FUN_00580310_t
{
    void SetFlag400(bool);
};

struct FUN_005802d0_shell
{
    void FUN_005802d0(bool);
};

struct FUN_00589f50_shell
{
    void SetSound(void*);
};

struct FUN_00580130_shell : public TESWaterForm
{
    BGSPlaceableWater* GetPlaceableAutoWater();
};

void* __cdecl operator new(unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);

BGSPlaceableWater::BGSPlaceableWater()
{}

void BGSPlaceableWater::FUN_004fc450(bool)
{}

void BGSPlaceableWater::FUN_004fc3a0(bool)
{}

void FUN_00580310_t::SetFlag400(bool)
{}

void FUN_005802d0_shell::FUN_005802d0(bool)
{}

void FUN_00589f50_shell::SetSound(void*)
{}

// Returns the BGSPlaceableWater stored at offset 0x180, creating and initialising it with editor ID "PlaceableAutoWater" if it is null.
// @fnv 0x00580130
BGSPlaceableWater* FUN_00580130_shell::GetPlaceableAutoWater()
{
    char ptempname[260];

    if (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180) == 0)
    {
        *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180) = new BGSPlaceableWater;

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->NotifySaveLoadGameOfFormChange();

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))->FUN_004fc450(true);

        reinterpret_cast<FUN_00580310_t*>(*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetFlag400(true);

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))->FUN_004fc3a0(true);

        reinterpret_cast<FUN_005802d0_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->FUN_005802d0(true);

        reinterpret_cast<FUN_005802f0_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->FUN_005802f0(true);

        _sprintf_s(ptempname, 0x104, "PlaceableAutoWater");

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetEditorID_AtRuntime(ptempname);

        reinterpret_cast<FUN_00589f50_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetSound(this);
    }

    return *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180);
}

namespace fnv_00580330 {
struct BGSPlaceableWater
{
    unsigned char m_auiShapeKeys[0x50];

    BGSPlaceableWater();
    void FUN_004fc360(bool);
    void FUN_004fc380(bool);
    void FUN_004fc3a0(bool);
    void FUN_004fc3c0(bool);
    void FUN_004fc3e0(bool);
    void SetValue(bool);
    void SetFlag80(bool);
    void SetFlag100(bool);
    void SetFlag8000000(bool);
};

struct FUN_005802d0_shell
{
    void FUN_005802d0(bool);
};

struct FUN_00589f50_shell
{
    void SetSound(void*);
};

struct FUN_00580330_shell
{
    unsigned char m_auiShapeKeys[0x184];
    BGSPlaceableWater* m_pPlaceableWater;

    BGSPlaceableWater* GetPlaceableLODWater();
};

void* __cdecl operator new(unsigned int);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// @fnv 0x00580330
BGSPlaceableWater* FUN_00580330_shell::GetPlaceableLODWater()
{
    char ptempname[260];

    if (m_pPlaceableWater == 0)
    {
        m_pPlaceableWater = new BGSPlaceableWater;

        reinterpret_cast<TESForm*>(m_pPlaceableWater)->NotifySaveLoadGameOfFormChange();

        m_pPlaceableWater->SetFlag8000000(true);
        m_pPlaceableWater->FUN_004fc360(true);
        m_pPlaceableWater->FUN_004fc3e0(false);
        m_pPlaceableWater->SetValue(false);
        m_pPlaceableWater->FUN_004fc380(false);
        m_pPlaceableWater->FUN_004fc3a0(true);

        reinterpret_cast<FUN_005802d0_shell*>(m_pPlaceableWater)->FUN_005802d0(true);

        reinterpret_cast<FUN_005802f0_shell*>(m_pPlaceableWater)->FUN_005802f0(false);

        m_pPlaceableWater->FUN_004fc3c0(true);
        m_pPlaceableWater->SetFlag80(false);
        m_pPlaceableWater->SetFlag100(false);

        _sprintf_s(ptempname, 0x104, "PlaceableLODWater");

        reinterpret_cast<TESForm*>(m_pPlaceableWater)->SetEditorID_AtRuntime(ptempname);

        reinterpret_cast<FUN_00589f50_shell*>(m_pPlaceableWater)->SetSound(this);
    }

    return m_pPlaceableWater;
}
}  // namespace fnv_00580330

struct FUN_0057ee10_Primary
{
    virtual ~FUN_0057ee10_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_0057ee10_Base18
{
    virtual ~FUN_0057ee10_Base18();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0057ee10_Base24
{
    virtual ~FUN_0057ee10_Base24();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0057ee10_Sub30
{
    ~FUN_0057ee10_Sub30();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
};

struct FUN_0057ee10_Sub64
{
    ~FUN_0057ee10_Sub64();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_0057ee10_Sub74
{
    ~FUN_0057ee10_Sub74();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
};
struct FUN_0057ee10_Sub17c
{
    ~FUN_0057ee10_Sub17c();
    void Unk_Init(unsigned int arg);
    unsigned int unk04;
};

struct FUN_0057ee10 : FUN_0057ee10_Primary, FUN_0057ee10_Base18, FUN_0057ee10_Base24
{
    FUN_0057ee10_Sub30 m_30;
    FUN_0057ee10_Sub64 m_64;
    FUN_0057ee10_Sub74 m_74;
    FUN_0057ee10_Sub17c m_17c;
    virtual ~FUN_0057ee10();
};

// Destructor that resets the m_17c sub-object by calling Unk_Init(0).
// @fnv 0x0057ee10
FUN_0057ee10::~FUN_0057ee10()
{
    m_17c.Unk_Init(0);
}

struct WaterFullNameBase
{
    WaterFullNameBase();
    ~WaterFullNameBase();
    virtual void Init();
    unsigned int nameData;
    unsigned int nameLength;
};
struct WaterAttackBase
{
    WaterAttackBase();
    ~WaterAttackBase();
    virtual void Init();
    unsigned short damage;
    unsigned short reserved;
    bool needUpdate;
};
struct WaterPointer
{
    WaterPointer(int);
    ~WaterPointer();
    void* object;
};
struct WaterColor
{
    WaterColor(float, float, float, float);
    float r, g, b, a;
};
struct WaterTexture
{
    WaterTexture();
    ~WaterTexture();
    virtual void Init();
    unsigned int nameData;
    unsigned int nameLength;
    unsigned char alpha, flags;
};
struct WaterString
{
    WaterString();
    ~WaterString();
    unsigned int data;
    unsigned int length;
};
struct FUN_0057e9a0 : WaterShaderSettings
{
    FUN_0057e9a0();
};
struct FUN_0057eba0 : TESForm, WaterFullNameBase, WaterAttackBase
{
    WaterPointer normalMap;
    WaterColor scroll0, scroll1, scroll2;
    WaterTexture texture;
    WaterString material;
    void* sound;
    void* remapped;
    FUN_0057e9a0 shader;
    void* weather0;
    void* weather1;
    void* weather2;
    int select01, select02;
    unsigned int frequencyX, frequencyY;
    int octaves;
    float amplitude, lacunarity, bias, gain;
    void* spell;
    WaterPointer noiseTexture;
    void* autoWater;
    void* lodWater;
    int radiation, health;
    bool reset;
    FUN_0057eba0();
    virtual ~FUN_0057eba0();
    void ResetFormData();
};
// @fnv 0x0057eba0
FUN_0057eba0::FUN_0057eba0()
    : normalMap(0), scroll0(0.0f, 0.0f, 0.0f, 0.0f), scroll1(0.0f, 0.0f, 0.0f, 0.0f), scroll2(0.0f, 0.0f, 0.0f, 0.0f),
      noiseTexture(0)
{
    SetFormType((ENUM_FORM_ID)0x4e);
    ResetFormData();
    select01 = 0;
    select02 = 0;
    frequencyX = 9;
    frequencyY = 9;
    octaves = 4;
    amplitude = 0.5f;
    lacunarity = 2.0f;
    bias = 0.5f;
    gain = 0.5f;
    spell = 0;
    needUpdate = true;
    reset = false;
    autoWater = 0;
    lodWater = 0;
    radiation = 0;
    health = 0;
    remapped = 0;
}

struct ByteArg
{
    unsigned char c;
};
void FUN_00401080(void* p, ByteArg v);
struct F3a0
{
    void FUN_0057f3a0();
};
// @fnv 0x0057f3a0
void F3a0::FUN_0057f3a0()
{
    FUN_00401080((char*)this + 0x0, ByteArg());
    FUN_00401080((char*)this + 0x4, ByteArg());
    FUN_00401080((char*)this + 0x8, ByteArg());
    FUN_00401080((char*)this + 0xc, ByteArg());
    FUN_00401080((char*)this + 0x10, ByteArg());
    FUN_00401080((char*)this + 0x14, ByteArg());
    FUN_00401080((char*)this + 0x18, ByteArg());
    FUN_00401080((char*)this + 0x1c, ByteArg());
    FUN_00401080((char*)this + 0x20, ByteArg());
    FUN_00401080((char*)this + 0x24, ByteArg());
    FUN_00401080((char*)this + 0x28, ByteArg());
    FUN_00401080((char*)this + 0x2c, ByteArg());
    FUN_00401080((char*)this + 0x30, ByteArg());
    FUN_00401080((char*)this + 0x38, ByteArg());
    FUN_00401080((char*)this + 0x3c, ByteArg());
    FUN_00401080((char*)this + 0x40, ByteArg());
    FUN_00401080((char*)this + 0x44, ByteArg());
    FUN_00401080((char*)this + 0x48, ByteArg());
    FUN_00401080((char*)this + 0x4c, ByteArg());
    FUN_00401080((char*)this + 0x50, ByteArg());
    FUN_00401080((char*)this + 0x54, ByteArg());
    FUN_00401080((char*)this + 0x58, ByteArg());
    FUN_00401080((char*)this + 0x5c, ByteArg());
    FUN_00401080((char*)this + 0x60, ByteArg());
    FUN_00401080((char*)this + 0x64, ByteArg());
    FUN_00401080((char*)this + 0x68, ByteArg());
    FUN_00401080((char*)this + 0x6c, ByteArg());
    FUN_00401080((char*)this + 0x70, ByteArg());
    FUN_00401080((char*)this + 0x74, ByteArg());
    FUN_00401080((char*)this + 0x78, ByteArg());
    FUN_00401080((char*)this + 0x7c, ByteArg());
    FUN_00401080((char*)this + 0x80, ByteArg());
    FUN_00401080((char*)this + 0x84, ByteArg());
    FUN_00401080((char*)this + 0x88, ByteArg());
    FUN_00401080((char*)this + 0x8c, ByteArg());
    FUN_00401080((char*)this + 0x90, ByteArg());
    FUN_00401080((char*)this + 0x94, ByteArg());
    FUN_00401080((char*)this + 0x98, ByteArg());
    FUN_00401080((char*)this + 0x9c, ByteArg());
    FUN_00401080((char*)this + 0xa0, ByteArg());
    FUN_00401080((char*)this + 0xa4, ByteArg());
    FUN_00401080((char*)this + 0xa8, ByteArg());
    FUN_00401080((char*)this + 0xac, ByteArg());
    FUN_00401080((char*)this + 0xb0, ByteArg());
    FUN_00401080((char*)this + 0xb4, ByteArg());
    FUN_00401080((char*)this + 0xb8, ByteArg());
    FUN_00401080((char*)this + 0xbc, ByteArg());
    FUN_00401080((char*)this + 0xc0, ByteArg());
}

struct FUN_006e5cc0_Class
{
    void __thiscall FUN_006e5cc0(void* a1);
};
struct FUN_005800e0_shell
{
    void FUN_005800e0(FUN_006e5cc0_Class* a1);
};
// @fnv 0x005800e0
void FUN_005800e0_shell::FUN_005800e0(FUN_006e5cc0_Class* a1)
{
    a1->FUN_006e5cc0((char*)this + 0x17c);
}

#include <string.h>

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct WaterEffectSetting : public TESWaterForm
{
    void FUN_0057fde0(TESForm* apCopy);
};
// Copies water effect settings from apCopy into this, including flags, opacity, shader, spell item, and noise map texture.
// @fnv 0x0057fde0
void WaterEffectSetting::FUN_0057fde0(TESForm* apCopy)
{
    TESWaterForm* pcopy = dynamic_cast<TESWaterForm*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<FUN_005e78f0_t*>(this)->FUN_004851b0(pcopy);
    this->cFlags = pcopy->cFlags;
    this->m_ucOpacity = pcopy->m_ucOpacity;
    memcpy(this->FUN_0057eef0(), pcopy->FUN_0057eef0(), 0xc4);
    reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(
        reinterpret_cast<TESEffectShader*>(reinterpret_cast<TESPackage*>(pcopy)->GetRefCount()));
    this->SetSpellItem(reinterpret_cast<SpellItem*>(reinterpret_cast<FUN_0057fed0*>(pcopy)->GetMember()));
    memcpy(reinterpret_cast<unsigned char*>(this) + 0x148, reinterpret_cast<unsigned char*>(pcopy) + 0x148, 0xc);
    this->m_kNoiseMapTexture.CopyFromBase(
        reinterpret_cast<BaseFormComponent*>(reinterpret_cast<unsigned char*>(pcopy) + 0x64));
    reinterpret_cast<FUN_0057fef0_shell*>(this)->SetMaterialName(reinterpret_cast<Holder*>(pcopy)->GetMaterialName());
}

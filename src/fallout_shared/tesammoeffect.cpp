// fallout_shared/tesammoeffect.cpp: TESAmmoEffect, AmmoEffectDesc (8 functions)

enum ENUM_FORM_ID
{
    kAmmoEffectForm = 0x72
};

class TESFile;
class TESFullName;

class TESForm
{
  public:
    TESForm();
    virtual ~TESForm()
    {}
    virtual void UnknownForm()
    {}
    void SetFormType(ENUM_FORM_ID);
    void LoadRecordHeader(TESFile*);
    void SetInitializationState(bool);
    void ReadTypedData(TESFile*, void*, unsigned short);

  private:
    unsigned char baseData[20];
};

class TESAmmoEffectMap
{
  public:
    TESAmmoEffectMap();
    virtual ~TESAmmoEffectMap()
    {}
    virtual void UnknownMap()
    {}

  private:
    unsigned char mapData[8];
};

class TESAmmoEffect : public TESForm, public TESAmmoEffectMap
{
  public:
    TESAmmoEffect();
    virtual void UnknownForm()
    {}
    virtual void UnknownMap()
    {}
    virtual bool Load(TESFile*);
    unsigned char effectData[12];
};

class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool IsEndianConversionRequired();
    bool NextChunk();
};

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};

class ContainerItemExtraFileData
{
  public:
    void Endian();
};

extern "C" void __cdecl _alloca_probe_16();
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int __security_cookie;

extern "C" void* __cdecl memset(void*, int, unsigned int);

// Constructs a TESAmmoEffect: zeroes effectData and sets the form type to kAmmoEffectForm.
// @fnv 0x00599c40
TESAmmoEffect::TESAmmoEffect() : TESForm(), TESAmmoEffectMap()
{
    memset(effectData, 0, 12);
    SetFormType(kAmmoEffectForm);
}

class Actor;
class TESAmmo;
class NiTexture;
class BGSMusicType;

class TESObjectWEAP
{
  public:
    TESAmmo* GetCurrentAmmo(Actor* actor);
};

class BSShaderNoLightingProperty
{
  public:
    NiTexture* GetBaseTexture();
};

class BGSAmmoForm
{
  public:
    TESAmmo* GetAmmoHelper();
};

class TESRegionDataSound
{
  public:
    BGSMusicType* GetMusicType();
};

class GetCurrentAmmoVTable
{
  public:
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void* GetMusicSource();
    virtual void* GetMusicSource2();
};

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct FUN_00599d70_shell : public TESAmmoEffect
{
    bool LoadAmmoEffect(TESFile*);
};

extern "C" void* __cdecl _alloca(unsigned int);

struct TESFormVtbl
{
    char pad0[0xE0];
    void(__thiscall* readOBND)(TESForm*, TESFile*);
    char pad1[0x134 - 0xE4];
    void(__thiscall* setEditorID)(TESForm*, char*);
};

// @fnv 0x00599d70
bool FUN_00599d70_shell::LoadAmmoEffect(TESFile* apFile)
{
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x72)
        return false;

    LoadRecordHeader(apFile);
    SetInitializationState(false);

    int chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            (*(TESFormVtbl**)this)->setEditorID(this, pMessage);
            break;
        }
        case 0x444e424f:
            (*(TESFormVtbl**)this)->readOBND(this, apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk((TESFullName*)((TESAmmoEffectMap*)this), apFile);
            break;
        case 0x41544144:
            ReadTypedData(apFile, effectData, 0xc);
            if (apFile->IsEndianConversionRequired())
                ((ContainerItemExtraFileData*)effectData)->Endian();
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00599cd0_StandIn
{
    void FUN_00599d00();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00599d00, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x00599cd0
void* FUN_00599cd0_StandIn::DestroyIfFlagged(unsigned int flags)
{
    FUN_00599d00();
    if (flags & 1)
        operator delete(this);
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
struct FUN_00485680
{
    void M();
};
struct FUN_00485e00_shell
{
    void __SaveData(int, int);
};
bool __cdecl FUN_00401500();
struct FUN_00599ef0_shell
{
    void SaveForm();
};
// @fnv 0x00599ef0
void FUN_00599ef0_shell::SaveForm()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    if (FUN_00401500())
        ((ContainerItemExtraFileData*)((char*)this + 0x24))->Endian();
    ((FUN_00485e00_shell*)this)->__SaveData((int)((char*)this + 0x24), 0xc);
    if (FUN_00401500())
        ((ContainerItemExtraFileData*)((char*)this + 0x24))->Endian();
    ((FUN_00485680*)this)->M();
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
void* __memcpy(void*, const void*, unsigned int);
struct FUN_00599f60_t : TESAmmoEffect
{
    void CopyFromAmmoEffect(TESForm*);
};
// @fnv 0x00599f60
void FUN_00599f60_t::CopyFromAmmoEffect(TESForm* apCopy)
{
    TESAmmoEffect* pmisc = dynamic_cast<TESAmmoEffect*>(apCopy);
    if (pmisc == 0)
        return;
    __memcpy(effectData, pmisc->effectData, 12);
    ((FUN_005e78f0_t*)this)->FUN_004851b0(apCopy);
}

struct AmmoEffectValue
{
    int FUN_0045cd60();
    int FUN_0059bb30();
    float FUN_00759450();
};
struct AmmoEffectList
{
    AmmoEffectValue* value;
    AmmoEffectList* next;
    AmmoEffectList();
    ~AmmoEffectList();
    AmmoEffectValue*& FUN_006815c0();
    AmmoEffectList* FUN_00726070();
    void FUN_005ae3d0(AmmoEffectValue*&);
    void FUN_00905820(AmmoEffectValue*&);
};
// @fnv 0x0059a030
float ComputeAmmoEffectValue(int iEffectType, AmmoEffectList* pEffectList, float fBaseValue)
{
    float fResult = fBaseValue;
    if (!pEffectList)
        return fResult;
    AmmoEffectList* sorted = new AmmoEffectList;
    while (pEffectList && pEffectList->FUN_006815c0())
    {
        if (pEffectList->FUN_006815c0()->FUN_0045cd60() == 1)
            sorted->FUN_005ae3d0(pEffectList->FUN_006815c0());
        else
            sorted->FUN_00905820(pEffectList->FUN_006815c0());
        pEffectList = pEffectList->FUN_00726070();
    }
    while (sorted && sorted->FUN_006815c0())
    {
        AmmoEffectValue* effect = sorted->FUN_006815c0();
        sorted = sorted->FUN_00726070();
        int effectType = effect->FUN_0059bb30();
        int iOperation = effect->FUN_0045cd60();
        float magnitude = effect->FUN_00759450();
        if (effectType != iEffectType)
            continue;
        switch (iOperation)
        {
        case 0:
            fResult += magnitude;
            break;
        case 1:
            fResult *= magnitude;
            break;
        case 2:
            fResult -= magnitude;
            break;
        }
    }
    delete sorted;
    return fResult;
}

extern "C" int __cdecl memcmp(const void* pvA, const void* pvB, unsigned int ItemUpdateArray);

struct FUN_00599fc0_shell : public TESAmmoEffect
{
    bool CompareFullName(TESForm* pkForm);
    bool Compare(TESForm* pkForm);
};

// @fnv 0x00599fc0
bool FUN_00599fc0_shell::Compare(TESForm* pkForm)
{
    TESAmmoEffect* pkOther = dynamic_cast<TESAmmoEffect*>(pkForm);
    if (!pkOther)
        return true;
    if (memcmp(effectData, pkOther->effectData, sizeof(effectData)))
        return true;
    if (CompareFullName(pkOther))
        return true;
    return false;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
int _sprintf_s(char* dst, unsigned int size, const char* fmt, ...);

class AmmoEffectSetting
{
  public:
    const char* String();
};

extern AmmoEffectSetting g_011caa94;
extern AmmoEffectSetting g_011caa84;
extern AmmoEffectSetting g_011caaa0;
extern AmmoEffectSetting g_011caa78;
extern AmmoEffectSetting g_011caaac;
extern AmmoEffectSetting g_011caab8;

class AmmoEffectDesc
{
  public:
    unsigned int GetOperation();
    unsigned int GetEffectType();
    float GetValue();
    void FormatDescription(char* buffer, int bufferSize);
};

// Formats the ammo effect description into buffer using the effect name, operation symbol, and value.
// @fnv 0x0059a1e0
void AmmoEffectDesc::FormatDescription(char* buffer, int bufferSize)
{
    char nameText_2[64];
    char opText[2];

    opText[0] = 0;
    switch (GetOperation())
    {
    case 0:
        strcpy_s(opText, 2, "+");
        break;
    case 1:
        strcpy_s(opText, 2, "x");
        break;
    case 2:
        strcpy_s(opText, 2, "-");
        break;
    }
    switch (GetEffectType())
    {
    case 0:
        strcpy_s(nameText_2, 64, g_011caa94.String());
        break;
    case 1:
        strcpy_s(nameText_2, 64, g_011caa84.String());
        break;
    case 2:
        strcpy_s(nameText_2, 64, g_011caaa0.String());
        break;
    case 3:
        strcpy_s(nameText_2, 64, g_011caa78.String());
        break;
    case 4:
        strcpy_s(nameText_2, 64, g_011caaac.String());
        break;
    case 5:
        strcpy_s(nameText_2, 64, g_011caab8.String());
        break;
    }
    _sprintf_s(buffer, bufferSize, "%s %s %.2f", nameText_2, opText, (double)GetValue());
}

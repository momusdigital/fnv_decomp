// fallout_shared/tesdescription.cpp: TESDescription, TESDataHandler, TermHack (14 functions)

#include "tesdescription_decls.h"
// @fnv 0x00482f20
bool TESDataHandler::LoadDescriptionForForm()
{
    return loadDescription;
}
// If both description and file are non-null, calls Initialize on the description with the file's offset as a CombatController.
// @fnv 0x00482d50
void TESDescription::ReadDescriptionFromFile(TESDescription* description, TESFile* file)
{
    if (description && file)
        reinterpret_cast<CombatProcedure*>(description)
            ->Initialize(reinterpret_cast<CombatController*>(file->GetOffset()));
}
// @fnv 0x00482c50
TESDescription::TESDescription()
{
    InitializeComponent();
}
// @fnv 0x00482e90
const char* TESDescription::GetDescription(TESForm* form, CHUNK_ID chunk)
{
    if (!g_dataHandler->LoadDescriptionForForm())
    {
        TESForm* owner = form;
        if (!owner)
            owner = dynamic_cast<TESForm*>(this);
        reinterpret_cast<TESFile*>(this)->ReadTESInfo(owner, chunk);
    }
    return reinterpret_cast<NiPointer<NiNode>*>(&g_menuParsedXML)->operator->()
               ? reinterpret_cast<const char*>(reinterpret_cast<NiPointer<NiNode>*>(&g_menuParsedXML)->operator->())
               : g_011c72c0_arg1;
}

extern "C" unsigned char DAT_011c54ba;

// @fnv 0x00401500
unsigned char FUN_00401500()
{
    return DAT_011c54ba;
}

struct TESObjectREFR;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
struct FUN_00482c80_shell : public TESDescription
{
    void ClearParsedXML();
};

extern "C" unsigned char DAT_011c54ba;
unsigned char FUN_00401500();

struct BSStr
{
    bool Set(char const*, unsigned int);
};

extern int DAT_011c5490;

// Resets the parsed XML string, clears DAT_011c5490, and zeroes the second dword of this object.
// @fnv 0x00482c80
void FUN_00482c80_shell::ClearParsedXML()
{
    ((BSStr*)&g_menuParsedXML)->Set(0, 0);
    DAT_011c5490 = 0;
    ((unsigned long*)this)[1] = 0;
}

void __cdecl WriteDescChunk(void*, int);

struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
};

// @fnv 0x00482cb0
void __thiscall FUN_00482cb0_shell::FUN_00482cb0()
{
    WriteDescChunk(this, 0x43534544);
}

void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct DescStandIn
{
    int GetMenuParsedXmlLength();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* vf4(int, int);
};
// @fnv 0x00482cd0
void __cdecl WriteDescChunk(void* apDesc, int aiChunk)
{
    char empty;
    if (apDesc)
    {
        if (((DescStandIn*)apDesc)->GetMenuParsedXmlLength())
        {
            FUN_004856f0(aiChunk, ((DescStandIn*)apDesc)->vf4(0, 0x43534544),
                         ((DescStandIn*)apDesc)->GetMenuParsedXmlLength() + 1);
        }
        else
        {
            empty = 0;
            FUN_004856f0(aiChunk, &empty, 1);
        }
    }
}

extern BSStringT<char> g_menuParsedXML;
struct S7010
{
    unsigned int Length();
};
struct FUN_00482d30_shell
{
    unsigned int __thiscall GetMenuParsedXmlLength();
};
// @fnv 0x00482d30
unsigned int __thiscall FUN_00482d30_shell::GetMenuParsedXmlLength()
{
    return ((S7010*)&g_menuParsedXML)->Length();
}

void __cdecl _Deallocate(void*);
struct ClassFFB70
{
    void __thiscall FUN_004ffba0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_004ffba0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004ffb70
void* __thiscall ClassFFB70::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_004ffba0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    const char* operator*() const;
};

struct FUN_005a6e10_shell
{
    unsigned int _pad[5];
    Flt m_str;
    const char* GetStringOrDefault(int a, int b);
};

// Returns the string held by m_str if it is non-null, otherwise returns g_011c72c0_arg1.
// @fnv 0x005a6e10
const char* FUN_005a6e10_shell::GetStringOrDefault(int aiUnusedA, int aiUnusedB)
{
    (void)aiUnusedA;
    (void)aiUnusedB;
    return *m_str ? *m_str : g_011c72c0_arg1;
}

struct StrCmpHelper
{
    int StrCmp(char const*, bool) const;
};

struct FUN_00482df0_shell
{
    bool __thiscall CompareComponent(BaseFormComponent* apComponent);
};

// @fnv 0x00482df0
bool __thiscall FUN_00482df0_shell::CompareComponent(BaseFormComponent* apComponent)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apComponent);
    if (!pDesc)
        return true;
    if (((DescStandIn*)this)->GetMenuParsedXmlLength() || ((DescStandIn*)pDesc)->GetMenuParsedXmlLength())
    {
        if (((DescStandIn*)this)->GetMenuParsedXmlLength() != ((DescStandIn*)pDesc)->GetMenuParsedXmlLength())
            return true;
        else if (((StrCmpHelper*)&g_menuParsedXML)->StrCmp((char const*)((DescStandIn*)pDesc)->vf4(0, 0x43534544), 0))
            return true;
    }
    return false;
}

struct TESObjectREFR;

struct PlayerCharacter
{
    int GetTerminalAccessResult(TESObjectREFR* apRef);
};
extern PlayerCharacter* g_thePlayer;

struct BSStringT_char
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    BSStringT_char();
    ~BSStringT_char();
    operator const char*() const;
};
int FUN_00406f60(BSStringT_char* apStr, const char* apFmt, ...);

struct SettingString
{
    const char* GetString();
};
extern SettingString g_011c8394;

namespace ActorValue {
enum Index
{
    kAV_0 = 0
};
const char* __cdecl GetActorValueName(Index aeIndex);
}

float __cdecl FUN_004bd510(float afValue, float afMult);
void __cdecl FUN_00709470(int, TESObjectREFR*, int, int, int, int);
bool __cdecl QueueUIMessage(const char* apMsg, int aeType, const char* apIcon, const char* apSound, float afTime,
                            bool abInstant);
void __cdecl FUN_0047a560(TESObjectREFR* apRef, PlayerCharacter* apActor, int aiUnk);

struct TermHackBase0
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct TermHackBase70
{
    virtual void FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor);
};

struct TermHack : TermHackBase0, TermHackBase70
{
    float FUN_005017a0(TESObjectREFR* apRef);
    virtual void FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor);
};

// @fnv 0x005015f0
void TermHack::FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor)
{
    if (apRef && apActor == g_thePlayer)
    {
        switch (g_thePlayer->GetTerminalAccessResult(apRef))
        {
        case 0:
        case 1:
            FUN_00709470(3, apRef, 0, 0, 1, 0);
            break;
        case 2:
        case 3:
            FUN_00709470(2, apRef, 0, 0, 1, 0);
            break;
        case 4: {
            BSStringT_char kMsg;
            FUN_00406f60(&kMsg, g_011c8394.GetString(), ActorValue::GetActorValueName((ActorValue::Index)0x28),
                         (int)FUN_004bd510(FUN_005017a0(apRef), 1.0f));
            QueueUIMessage(kMsg, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0, 2.0f, false);
        }
        break;
        }
        FUN_0047a560(apRef, apActor, 0);
    }
}

class GlobalObject_004037b0
{
  public:
    bool FUN_004037f0(const char* apString, unsigned int auiLength);
};
extern GlobalObject_004037b0 g_011c5498;
struct Off482d
{
    unsigned long FUN_00726070();
};

struct Desc482d : public TESDescription
{
    void CopyComponent(BaseFormComponent* apComponent);
};

// @fnv 0x00482d80
void Desc482d::CopyComponent(BaseFormComponent* apComponent)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apComponent);
    if (!pDesc)
        return;
    g_011c5498.FUN_004037f0((const char*)((DescStandIn*)pDesc)->vf4(0, 'CSED'), 0);
    m_uiDescriptionFileOffset = ((Off482d*)pDesc)->FUN_00726070();
}

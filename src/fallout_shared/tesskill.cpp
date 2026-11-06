
// src/fallout_shared/tesskill.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesskill.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_006180a0_shell
{
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
    void __thiscall SwapEndian();
};

// Byte-swaps the five int fields m0, m4, m8 and the two ints at m12 via BSEndian.
// @fnv 0x006180a0
void __thiscall FUN_006180a0_shell::SwapEndian()
{
    BSEndian(&m0, EndianSizeTag<3>());
    BSEndian(&m4, EndianSizeTag<3>());
    BSEndian(&m8, EndianSizeTag<3>());
    for (int i = 0; i < 2; ++i)
    {
        BSEndian(&m12 + i, EndianSizeTag<3>());
    }
}

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
// @fnv 0x00485910
void __cdecl FUN_00485910(unsigned int a, int aiValue)
{
    if (FUN_00401500())
        BSEndian(&aiValue, EndianSizeTag<3>());
    AppendChunk(a, &aiValue, 4);
}

void __cdecl Deallocate(void*);

struct FUN_00617f40_shell
{
    void __thiscall FUN_00617f40();
};

struct FUN_00617e50_shell : public FUN_00617f40_shell
{
    void* __thiscall FUN_00617e50(unsigned int flags);
};

// Calls FUN_00617f40, then if flags has bit 1 set deallocates this and returns this.
// @fnv 0x00617e50
void* __thiscall FUN_00617e50_shell::FUN_00617e50(unsigned int flags)
{
    FUN_00617f40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct TgtOps
{
    void __thiscall ClearSourceFiles();
};
struct FUN_00617ea0_shell
{
    void __thiscall ResetState();
};
// @fnv 0x00617ea0
void __thiscall FUN_00617ea0_shell::ResetState()
{
    *(int*)((char*)this + 0x2c) = -1;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x30) = 5;
    int iIndex = 0;
    for (; iIndex < 2; ++iIndex)
        *(float*)((char*)this + 0x38 + iIndex * 4) = 1.0f;
    int iSlot = 0;
    for (; iSlot < 4; ++iSlot)
        ((void(__thiscall*)(void*))(*(int**)((char*)this + 0x40 + iSlot * 8))[0])((char*)this + 0x40 + iSlot * 8);
    ((void(__thiscall*)(void*, int))(*(int**)((char*)this + 0x00))[0x32])((char*)this, 0);
    ((TgtOps*)this)->ClearSourceFiles();
}

namespace fnv_00617fc0 {
struct FUN_004855a0
{
    void __thiscall M();
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
};
struct FUN_0048e370_obj
{
    void __thiscall FUN_0048e370(unsigned int);
};
struct FUN_00485e00_shell
{
    void __thiscall __SaveData(int, int);
};
struct FUN_00485680
{
    void __thiscall M();
};
void __cdecl FUN_00485910(int, int);
void __cdecl WriteDescChunk(void*, int);
int __cdecl FUN_00401500();
struct FUN_00617fc0_shell
{
    void __thiscall SaveForm();
};
// @fnv 0x00617fc0
void __thiscall FUN_00617fc0_shell::SaveForm()
{
    ((FUN_004855a0*)this)->M();
    FUN_00485910(0x58444e49, *(int*)((char*)this + 0x2c));
    ((FUN_00482cb0_shell*)((char*)this + 0x18))->FUN_00482cb0();
    ((FUN_0048e370_obj*)((char*)this + 0x20))->FUN_0048e370(0x4e4f4349);
    if ((unsigned char)FUN_00401500())
        ((FUN_006180a0_shell*)((char*)this + 0x2c))->SwapEndian();
    ((FUN_00485e00_shell*)this)->__SaveData((int)((char*)this + 0x2c), 0x14);
    if ((unsigned char)FUN_00401500())
        ((FUN_006180a0_shell*)((char*)this + 0x2c))->SwapEndian();
    WriteDescChunk((char*)this + 0x40, 0x4d414e41);
    WriteDescChunk((char*)this + 0x48, 0x4d414e4a);
    WriteDescChunk((char*)this + 0x50, 0x4d414e45);
    WriteDescChunk((char*)this + 0x58, 0x4d414e4d);
    ((FUN_00485680*)this)->M();
}
}  // namespace fnv_00617fc0

extern "C" void* __cdecl _alloca(unsigned int);

typedef int CHUNK_ID;

struct TESFile;
struct TESDescription;
struct TESTexture;

struct TESFile
{
    int __thiscall _ref_00472660();
    int __thiscall _ref_004726b0();
    bool __thiscall _ref_004726f0();
    unsigned int __thiscall _ref_00401660();
    bool __thiscall _ref_00472890(void*, unsigned int);
    bool GetChunkData();
};

struct TESDescription
{
    static void __cdecl ReadDescriptionFromFile(TESDescription*, TESFile*);
};

struct TESTexture
{
    static void __cdecl ReadTextureData(TESTexture*, TESFile*);
};

struct TESForm
{
    void __thiscall _ref_00485110(TESFile*);
    void __thiscall ReadTypedData(TESFile*, void*, unsigned short);

    virtual void _slot00()
    {}
    virtual void _slot01()
    {}
    virtual void _slot02()
    {}
    virtual void _slot03()
    {}
    virtual void _slot04()
    {}
    virtual void _slot05()
    {}
    virtual void _slot06()
    {}
    virtual void _slot07()
    {}
    virtual void _slot08()
    {}
    virtual void _slot09()
    {}
    virtual void _slot10()
    {}
    virtual void _slot11()
    {}
    virtual void _slot12()
    {}
    virtual void _slot13()
    {}
    virtual void _slot14()
    {}
    virtual void _slot15()
    {}
    virtual void _slot16()
    {}
    virtual void _slot17()
    {}
    virtual void _slot18()
    {}
    virtual void _slot19()
    {}
    virtual void _slot20()
    {}
    virtual void _slot21()
    {}
    virtual void _slot22()
    {}
    virtual void _slot23()
    {}
    virtual void _slot24()
    {}
    virtual void _slot25()
    {}
    virtual void _slot26()
    {}
    virtual void _slot27()
    {}
    virtual void _slot28()
    {}
    virtual void _slot29()
    {}
    virtual void _slot30()
    {}
    virtual void _slot31()
    {}
    virtual void _slot32()
    {}
    virtual void _slot33()
    {}
    virtual void _slot34()
    {}
    virtual void _slot35()
    {}
    virtual void _slot36()
    {}
    virtual void _slot37()
    {}
    virtual void _slot38()
    {}
    virtual void _slot39()
    {}
    virtual void _slot40()
    {}
    virtual void _slot41()
    {}
    virtual void _slot42()
    {}
    virtual void _slot43()
    {}
    virtual void _slot44()
    {}
    virtual void _slot45()
    {}
    virtual void _slot46()
    {}
    virtual void _slot47()
    {}
    virtual void _slot48()
    {}
    virtual void _slot49()
    {}
    virtual void _slot50()
    {}
    virtual void _slot51()
    {}
    virtual void _slot52()
    {}
    virtual void _slot53()
    {}
    virtual void _slot54()
    {}
    virtual void _slot55()
    {}

    virtual void LoadBoundData(TESFile*)
    {}

    virtual void _slot57()
    {}
    virtual void _slot58()
    {}
    virtual void _slot59()
    {}
    virtual void _slot60()
    {}
    virtual void _slot61()
    {}
    virtual void _slot62()
    {}
    virtual void _slot63()
    {}
    virtual void _slot64()
    {}
    virtual void _slot65()
    {}
    virtual void _slot66()
    {}
    virtual void _slot67()
    {}
    virtual void _slot68()
    {}
    virtual void _slot69()
    {}
    virtual void _slot70()
    {}
    virtual void _slot71()
    {}
    virtual void _slot72()
    {}
    virtual void _slot73()
    {}
    virtual void _slot74()
    {}
    virtual void _slot75()
    {}
    virtual void _slot76()
    {}

    virtual void SetEditorID(char*)
    {}
};

struct TESSkill : public TESForm
{
    bool __thiscall Load(TESFile*);
};

// Reads a skill record from apFile: checks the record type, loads the base form, then dispatches each chunk to its handler until the file ends.
// @fnv 0x00618130
bool TESSkill::Load(TESFile* apFile)
{
    CHUNK_ID chunkID;

    if (apFile->_ref_00472660() != 0x0F)
        return false;

    this->_ref_00485110(apFile);

    while ((chunkID = apFile->_ref_004726b0()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* pMessage = static_cast<char*>(_alloca(apFile->_ref_00401660()));
            apFile->_ref_00472890(pMessage, 0x200);
            this->SetEditorID(pMessage);
            break;
        }

        case 0x444E424F:
            this->LoadBoundData(apFile);
            break;

        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(
                this ? reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x18) : 0, apFile);
            break;

        case 0x4E4F4349:
            TESTexture::ReadTextureData(this ? reinterpret_cast<TESTexture*>(reinterpret_cast<char*>(this) + 0x20) : 0,
                                        apFile);
            break;

        case 0x41544144:
            this->ReadTypedData(apFile, reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x2C), 0x14);
            break;

        case 0x4D414E41:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x40), apFile);
            break;

        case 0x4D414E4A:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x48), apFile);
            break;

        case 0x4D414E45:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x50), apFile);
            break;

        case 0x4D414E4D:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x58), apFile);
            break;

        default:
            break;
        }

        if (chunkID == 0x41544144 && apFile->GetChunkData())
        {
            reinterpret_cast<FUN_006180a0_shell*>(reinterpret_cast<char*>(this) + 0x2C)->SwapEndian();
        }

        if (!apFile->_ref_004726f0())
            break;
    }

    return true;
}

extern char DAT_01186518, DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
void FUN_00401460(void*, const void*, unsigned int);
class Elem
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void Copy(Elem*);
    int val;
};
class FormC
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
    int k2c[5];
    Elem arr[4];
    void FUN_004851b0(void*);
    void CopyFrom(void* pOther);
};
// Copies the k2c array and arr elements from another FormC instance into this one after resolving pOther.
// @fnv 0x00618390
void FormC::CopyFrom(void* pOther)
{
    FormC* pSource = (FormC*)FUN_00ec43fb(pOther, 0, &DAT_01183028, &DAT_01186518, 0);
    if (!pSource)
        return;
    FUN_004851b0(pOther);
    FUN_00401460(k2c, pSource->k2c, 0x14);
    for (int i = 0; i < 4; i++)
        arr[i].Copy(&pSource->arr[i]);
}

struct NiColor;

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};

struct TESRegion
{
    NiColor* GetDiffuseColor();
};

struct DescBaseQ
{
    virtual void FUN_00000001();
    virtual void FUN_00000002();
    virtual void FUN_00000003();
};

struct DescQ : public DescBaseQ
{
    int m0;
    virtual bool IsEqualToBase(DescQ*);
};

struct SkillV : public FUN_005e79a0_t
{
    unsigned char mPad[0x2c];
    unsigned char data[0x14];
    DescQ m_kDescriptions[4];

    bool Compare(TESForm*);
};

int __cdecl _memcmp(const void*, const void*, unsigned int);

// @fnv 0x00618430
bool SkillV::Compare(TESForm* apCompare)
{
    SkillV* pOther = reinterpret_cast<SkillV*>(dynamic_cast<TESSkill*>(apCompare));
    if (!pOther)
    {
        return true;
    }

    if (FUN_005e79a0_t::FUN_00485270(reinterpret_cast<TESForm*>(pOther)))
    {
        return true;
    }

    if (_memcmp(data, reinterpret_cast<TESRegion*>(pOther)->GetDiffuseColor(), sizeof(data)) != 0)
    {
        return true;
    }

    {
        int i;
        for (i = 0; i < 4; ++i)
        {
            if (m_kDescriptions[i].IsEqualToBase(&pOther->m_kDescriptions[i]))
            {
                return true;
            }
        }
    }

    return false;
}

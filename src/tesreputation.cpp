// tesreputation.cpp: TESReputation, ReputationTracker, Reputation, ReputationUpdate and more (25 functions)

#include "tesreputation_decls.h"
#include <malloc.h>

// @fnv 0x00615560
void TESReputation::ResetFormData()
{
    m_fFirstReputationValue = 0.0f;
    m_fSecondReputationValue = 0.0f;
}

// @fnv 0x00616290
bool TESReputation::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 'NOCI':
            TESTextureLoader::ReadTextureData(this, file);
            break;
        case 'OCIM':
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 'ATAD':
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x007dc0a0
unsigned int* TESReputation::GetUnsignedIntegerPointer(unsigned int* puiValue)
{
    ++*puiValue;
    return puiValue;
}

// @fnv 0x006155c0
float TESReputation::GetUnsignedIntegerPointer(ReputationType type)
{
    if (type == ReputationType_REPUTATION_POSITIVE)
    {
        return m_fFirstReputationValue;
    }
    else
    {
        return m_fSecondReputationValue;
    }
}

struct FUN_006153c0 : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
    FUN_006153c0();
    ~FUN_006153c0();
};

// @fnv 0x006153c0
FUN_006153c0::FUN_006153c0()
{
    ((TESReputation*)this)->TESReputation::ResetFormData();
    SetFormType((ENUM_FORM_ID)0x68);
}

char __cdecl ConsumeByteAtE4(void);
extern char DAT_0119a0bc;

// @fnv 0x00615720
void __cdecl FUN_00615720(void)
{
    DAT_0119a0bc = ConsumeByteAtE4();
}

struct FUN_006159e0_shell
{
    void SetValue(int value);
};

// @fnv 0x006159e0
void FUN_006159e0_shell::SetValue(int value)
{
    *(int*)((char*)this + 0xe0c) = value;
}

struct FNStub
{
    const char* __thiscall GetFullName(void);
};
struct TESModel
{
    unsigned int __thiscall GetModelLength(void) const;
};
extern const char $SG5812[];

struct FUN_006166e0_shell
{
    char pad[0x24];
    TESModel m_Model;
    const char* __thiscall GetReputationName(void);
};

// @fnv 0x006166e0
const char* FUN_006166e0_shell::GetReputationName()
{
    if (m_Model.GetModelLength())
        return ((FNStub*)((char*)this + 0x24))->GetFullName();
    return $SG5812;
}

struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};

struct FUN_006165f0_shell
{
    unsigned short __thiscall FUN_006165f0(unsigned int aiFlags);
};

// Returns the save size: the result of GetSaveSize(aiFlags) plus 8 bytes.
// @fnv 0x006165f0
unsigned short __thiscall FUN_006165f0_shell::FUN_006165f0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += 4;
    isize += 4;
    return isize;
}

struct BGSLoadFormBuffer
{
    void __thiscall ReadTypedData(void* data, unsigned int size);
};

struct FUN_006166a0_shell : public TESForm
{
    void FUN_006166a0(BGSLoadFormBuffer* buffer);
};

// @fnv 0x006166a0
void FUN_006166a0_shell::FUN_006166a0(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    buffer->ReadTypedData((char*)this + 0x44, 4);
    buffer->ReadTypedData((char*)this + 0x48, 4);
}

void __cdecl _Deallocate(void*);
struct FUN_00615480_shell
{
    void FUN_006154b0();
    void* FUN_00615480(unsigned int);
};
// Calls FUN_006154b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00615480
void* FUN_00615480_shell::FUN_00615480(unsigned int flags)
{
    FUN_006154b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0
{
    void __thiscall M(void);
};
struct S_00487010
{
    void __thiscall FUN_00487010(void);
};
struct FUN_0048e370_obj
{
    void __thiscall FUN_0048e370(unsigned int);
};
struct FUN_0047a240_shell
{
    void __thiscall FUN_0047a240(unsigned int);
};
struct FUN_00485e00_shell
{
    void __thiscall __SaveData(int, int);
};
struct FUN_00485680
{
    void __thiscall M(void);
};
unsigned char __cdecl FUN_00401500(void);
struct FUN_00616470_shell : public FUN_004855a0
{
    void __thiscall FUN_00616470(void);
};
// @fnv 0x00616470
void __thiscall FUN_00616470_shell::FUN_00616470()
{
    M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    ((FUN_0048e370_obj*)((char*)this + 0x24))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x30))->FUN_0047a240(0x4f43494d);
    if (FUN_00401500())
        ((ReputationLimitData*)((char*)this + 0x40))->Endian();
    ((FUN_00485e00_shell*)this)->__SaveData((int)((char*)this + 0x40), 4);
    if (FUN_00401500())
        ((ReputationLimitData*)((char*)this + 0x40))->Endian();
    ((FUN_00485680*)this)->M();
}

struct FUN_00615580_shell
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(int) = 0;
    char _pad[0x40];
    float m44;
    float m48;
    void SetReputationValue(int, float);
};
// Stores b into m44 when a equals 1, otherwise into m48, then calls v18 with 2.
// @fnv 0x00615580
void FUN_00615580_shell::SetReputationValue(int a, float afValue)
{
    if (a == 1)
        m44 = afValue;
    else
        m48 = afValue;
    v18(2);
}

struct FUN_00484d60_holder
{
    void __thiscall SaveIfChanged(unsigned int);
};

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, int, int);
};

struct FUN_00616660_shell
{
    char pad[0x44];
    unsigned int f0;
    unsigned int f1;
    void __thiscall SaveToBuffer(BGSSaveFormBuffer* buffer);
};

// Calls SaveIfChanged on this, then saves the two 4-byte fields f0 and f1 to the buffer.
// @fnv 0x00616660
void __thiscall FUN_00616660_shell::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged((unsigned int)buffer);
    buffer->SaveData(&f0, 4, 0);
    buffer->SaveData(&f1, 4, 0);
}

struct StartMenu
{
    const char* __thiscall GetMenuTitle(void);
};

struct TutorialState
{
    bool __thiscall ShowMessage(int, int, unsigned int);
};

struct FUN_006155f0_shell
{
    char pad_00[0x18];
    FNStub mFNStub;
    char pad_1c[0x30];
    int mField_4c;

    const char* __thiscall GetSelectedSettingString(void);
    const char* __thiscall GetReputationTitle(void);
    const char* __thiscall GetReputationIcon(void);
    void ShowMessageBox(void);
};

extern char g_011cba30;
extern char g_011cbcb0;
extern char g_011d38b8;

unsigned char* __cdecl _FUN_004b7210(void);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl FUN_00703f10(const char*, const char*, const char*, const char*, void(__cdecl*)(), int, int, float, float,
                          const char*, int);

// @fnv 0x006155f0
void FUN_006155f0_shell::ShowMessageBox(void)
{
    char buffer[0x200];

    _sprintf_s(buffer, 0x200, "%s\n%s", GetReputationTitle(), GetSelectedSettingString());

    reinterpret_cast<TutorialState*>(reinterpret_cast<unsigned char*>(_FUN_004b7210()) + 0x4d4)
        ->ShowMessage(0x27, 0, 0x1f4);

    if (mField_4c == 1)
    {
        FUN_00703f10(buffer, GetReputationIcon(), mFNStub.GetFullName(),
                     reinterpret_cast<StartMenu*>(&g_011cbcb0)->GetMenuTitle(), FUN_00615720, 1, 0x17, 0.0f, 0.0f,
                     reinterpret_cast<StartMenu*>(&g_011d38b8)->GetMenuTitle(), 0);
    }
    else
    {
        FUN_00703f10(buffer, GetReputationIcon(), mFNStub.GetFullName(),
                     reinterpret_cast<StartMenu*>(&g_011cba30)->GetMenuTitle(), FUN_00615720, 1, 0x17, 0.0f, 0.0f,
                     reinterpret_cast<StartMenu*>(&g_011d38b8)->GetMenuTitle(), 0);
    }
}

class Sub18_b9216
{
  public:
    virtual ~Sub18_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Sub24_b9216
{
  public:
    virtual ~Sub24_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Sub30_b9216
{
  public:
    virtual ~Sub30_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Base_b9216
{
  public:
    virtual ~Base_b9216();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
};

class FUN_006154b0_cls : public Base_b9216, public Sub18_b9216, public Sub24_b9216, public Sub30_b9216
{
  public:
    void Body();
    virtual ~FUN_006154b0_cls();
};

// @fnv 0x006154b0
FUN_006154b0_cls::~FUN_006154b0_cls()
{
    Body();
}

Base_b9216::~Base_b9216()
{}
Sub18_b9216::~Sub18_b9216()
{}
Sub24_b9216::~Sub24_b9216()
{}
Sub30_b9216::~Sub30_b9216()
{}

struct ReputationLimit
{
    float* __thiscall FUN_00403e20();
};
extern ReputationLimit DAT_011cba7c;
extern ReputationLimit DAT_011cbc70;
extern ReputationLimit DAT_011cbd68;
struct ReputationTracker
{
    float __thiscall GetPositiveRatio();
    float __thiscall GetNegativeRatio();
    unsigned char __thiscall GetReputationRank(int kind);
};
// @fnv 0x00616950
unsigned char ReputationTracker::GetReputationRank(int kind)
{
    float value = 0.0f;
    unsigned char rank = 0;
    if (kind == 1)
    {
        value = GetPositiveRatio();
    }
    else
    {
        value = GetNegativeRatio();
    }
    if (value >= *DAT_011cba7c.FUN_00403e20() && value < *DAT_011cbc70.FUN_00403e20())
    {
        rank = 1;
    }
    else if (value >= *DAT_011cbc70.FUN_00403e20() && value < *DAT_011cbd68.FUN_00403e20())
    {
        rank = 2;
    }
    else if (value >= *DAT_011cbd68.FUN_00403e20())
    {
        rank = 3;
    }
    return rank;
}

// Multiple-inheritance constructor: base A (0x18 bytes, out-of-line ctor),
// base B (4 bytes, vptr only, also the element type of the member array),
// base C (16 bytes, 8-aligned, out-of-line ctor), then an array of eight B
// members, a member call with 15, and a second member call.
struct BaseComponentA
{
    BaseComponentA();
    virtual void unk00();
    ~BaseComponentA();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct BaseComponentB
{
    BaseComponentB();
    virtual void unk00();
    int unk04;
};

struct BaseComponentC
{
    BaseComponentC();
    virtual void unk00();
    ~BaseComponentC();
    __int64 unk08;
};

struct FUN_00617da0 : public BaseComponentA, public BaseComponentB, public BaseComponentC
{
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    BaseComponentB unk40[4];
    FUN_00617da0();
    void unk60(int value);
    void unk64();
};

// Initializes the object by calling unk60 with 15 and then unk64.
// @fnv 0x00617da0
FUN_00617da0::FUN_00617da0()
{
    unk60(15);
    unk64();
}

struct FUN_00617f40_Primary
{
    virtual ~FUN_00617f40_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_00617f40_Base18
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_00617f40_Base20
{
    virtual ~FUN_00617f40_Base20();
    unsigned int unk04;
};

struct FUN_00617f40 : FUN_00617f40_Primary, FUN_00617f40_Base18, FUN_00617f40_Base20
{
    virtual ~FUN_00617f40();
};

// @fnv 0x00617f40
FUN_00617f40::~FUN_00617f40()
{}

struct NamePart
{
    const char* FUN_00408da0();
};
struct Setting
{
    const char* FUN_00403df0();
};
extern Setting DAT_011cbb98, DAT_011cbc34, DAT_011cba94, DAT_011cba00;
struct Player
{
    bool FUN_00953c50(bool*);
    void SetValue(void*);
};
extern Player* _g_thePlayer;
bool __cdecl IsInDialog();
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct Reputation
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void Mark(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NamePart name;
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
    float positive;
    float negative;
    int sound;
    char GetReputationRank(int);
    void ShowMessageBox();
    void RemoveReputationValue(int kind, float amount);
};
// @fnv 0x00615a00
void Reputation::RemoveReputationValue(int kind, float amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    oldRank = GetReputationRank(kind);
    if (kind == 1)
    {
        positive -= amount;
        positive = positive < 0.0 ? 0.0f : positive;
        _sprintf_s(message3, 250, "%s\n%s", name.FUN_00408da0(), DAT_011cbb98.FUN_00403df0());
        newRank = GetReputationRank(1);
        if (newRank != oldRank)
        {
            sound = 0;
            changed = true;
        }
        QueueUIMessage(message3, 0, DAT_011cbc34.FUN_00403df0(), 0, 2.0f, false);
    }
    else
    {
        negative -= amount;
        negative = negative < 0.0 ? 0.0f : negative;
        _sprintf_s(message3, 250, "%s\n%s", name.FUN_00408da0(), DAT_011cba94.FUN_00403df0());
        newRank = GetReputationRank(0);
        if (newRank != oldRank)
        {
            sound = 1;
            changed = true;
        }
        QueueUIMessage(message3, 0, DAT_011cba00.FUN_00403df0(), 0, 2.0f, false);
    }
    if (changed && !_g_thePlayer->FUN_00953c50(0) && !IsInDialog())
        ShowMessageBox();
    else if (changed)
        _g_thePlayer->SetValue(this);
    Mark(2);
}

struct ReputationSetting
{
    float* __thiscall FUN_00403e20();
    const char* __thiscall FUN_00403df0();
};
extern ReputationSetting DAT_011cbc88;
extern ReputationSetting DAT_011cbcc8;
extern ReputationSetting DAT_011cba70;
extern ReputationSetting DAT_011cbc54;
extern ReputationSetting DAT_011cbb70;
extern ReputationSetting DAT_011cbac0;
extern ReputationSetting DAT_011cba58;
extern ReputationSetting DAT_011cbd5c;
extern ReputationSetting DAT_011cbad0;
struct ReputationPlayer
{
    bool __thiscall FUN_00953c50(bool*);
    void __thiscall SetValue(TESReputation*);
};
extern ReputationPlayer* DAT_011dea3c;
bool __cdecl FUN_007050d0();
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
struct ReputationFullName : TESFullName
{
    const char* __thiscall FUN_00408da0();
};
struct ReputationUpdate : TESForm, ReputationFullName, TESIcon, BGSMessageIcon
{
    ReputationLimitData data;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    ReputationType m_eReputationType;
    void __thiscall ApplyReputationChange(int type, int amount);
};
// @fnv 0x00615c90
void ReputationUpdate::ApplyReputationChange(int iReputationType, int amount)
{
    if (amount <= 0 || amount >= 6)
        return;
    bool p = false;
    char j = 0;
    char c = 0;
    ReputationSetting* e[5] = {&DAT_011cbc88, &DAT_011cbcc8, &DAT_011cba70, &DAT_011cbc54, &DAT_011cbb70};
    char l[250];
    j = ((ReputationTracker*)this)->GetReputationRank(iReputationType);
    if (iReputationType == 1)
    {
        m_fFirstReputationValue += *e[amount - 1]->FUN_00403e20();
        m_fFirstReputationValue =
            m_fFirstReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fFirstReputationValue;
        _sprintf_s(l, 250, "%s\n%s", ReputationFullName::FUN_00408da0(), DAT_011cbac0.FUN_00403df0());
        c = ((ReputationTracker*)this)->GetReputationRank(1);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            p = true;
        }
        DispatchMessageToSink(l, 0, DAT_011cbd5c.FUN_00403df0(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += *e[amount - 1]->FUN_00403e20();
        m_fSecondReputationValue =
            m_fSecondReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fSecondReputationValue;
        _sprintf_s(l, 250, "%s\n%s", ReputationFullName::FUN_00408da0(), DAT_011cba58.FUN_00403df0());
        c = ((ReputationTracker*)this)->GetReputationRank(0);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
            p = true;
        }
        DispatchMessageToSink(l, 0, DAT_011cbad0.FUN_00403df0(), 0, 2.0f, false);
    }
    if (p && !DAT_011dea3c->FUN_00953c50(0) && !FUN_007050d0())
        ((FUN_006155f0_shell*)this)->ShowMessageBox();
    else if (p)
        DAT_011dea3c->SetValue((TESReputation*)this);
    MarkAsModified(2);
}

namespace fnv_00615fa0 {
struct RepSetting
{
    float* Float();
    const char* String();
};
extern RepSetting g_011cbc88, originalRuntimeFloatSetting52, originalRuntimeFloatSetting53,
    originalRuntimeFloatSetting54, originalRuntimeFloatSetting55;
extern RepSetting g_011cbb98, g_011cbc34, g_011cba94, g_011cbad0;
struct RepName
{
    const char* GetFullName();
};
struct RepPlayer
{
    bool FUN_00953c50(bool*);
    void Queue(void*);
};
extern RepPlayer* _g_thePlayer;
bool IsInDialog();
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
int _sprintf_s(char*, unsigned int, const char*, ...);
struct RepObject
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void Update(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RepName name;
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
    float positive;
    float negative;
    int sound;
    char GetRank(int);
    void Play();
    void RemoveReputationValueByLevel(int kind, int amount);
};
// @fnv 0x00615fa0
void RepObject::RemoveReputationValueByLevel(int kind, int amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    if (amount <= 0 || amount >= 6)
        return;
    RepSetting* settings3[5] = {&g_011cbc88, &originalRuntimeFloatSetting52, &originalRuntimeFloatSetting53,
                                &originalRuntimeFloatSetting54, &originalRuntimeFloatSetting55};
    oldRank = GetRank(kind);
    if (kind == 1)
    {
        positive -= *settings3[amount - 1]->Float();
        positive = positive < 0.0 ? 0.0f : positive;
        _sprintf_s(message3, 250, "%s\n%s", name.GetFullName(), g_011cbb98.String());
        newRank = GetRank(1);
        if (newRank != oldRank)
        {
            sound = 0;
            changed = true;
        }
        QueueUIMessage(message3, 0, g_011cbc34.String(), 0, 2.0f, false);
    }
    else
    {
        negative -= *settings3[amount - 1]->Float();
        negative = negative < 0.0 ? 0.0f : negative;
        _sprintf_s(message3, 250, "%s\n%s", name.GetFullName(), g_011cba94.String());
        newRank = GetRank(0);
        if (newRank != oldRank)
        {
            sound = 1;
            changed = true;
        }
        QueueUIMessage(message3, 0, g_011cbad0.String(), 0, 2.0f, false);
    }
    if (changed && !_g_thePlayer->FUN_00953c50(0) && !IsInDialog())
        Play();
    else if (changed)
        _g_thePlayer->Queue(this);
    Update(2);
}
}  // namespace fnv_00615fa0

struct SettingT_GameSettingCollection_
{
    const char* String();
};
class GlobalObject_0040c150 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject_0040c150 g_011cbac0;
extern GlobalObject_0040c150 g_011cba58;
extern GlobalObject_0040c150 g_011cbd5c;
extern GlobalObject_0040c150 g_011cbad0;
struct TESSoundFile
{
    const char* GetSoundFile() const;
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct Interface
{
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static bool IsInDialog();
};
struct PlayerCharacter
{
    bool FUN_00953c50(bool*);
};
extern PlayerCharacter* g_thePlayer;

struct Host615730
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(int);
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
    float m_fMaximumReputation;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    int m_eReputationType;
    void AddReputationValue(int kind, float delta);
};

// @fnv 0x00615730
void Host615730::AddReputationValue(int kind, float delta)
{
    signed char val;
    bool changed;
    char i[250];
    signed char after;
    changed = false;
    val = 0;
    after = 0;
    val = (char)((ReputationTracker*)this)->GetReputationRank(kind);
    if (kind == 1)
    {
        m_fFirstReputationValue += delta;
        m_fFirstReputationValue = (m_fFirstReputationValue > m_fMaximumReputation) ? (float)m_fMaximumReputation
                                                                                   : (float)m_fFirstReputationValue;
        _sprintf_s(i, 250, "%s\n%s", ((TESSoundFile*)((char*)this + 0x18))->GetSoundFile(), g_011cbac0.String());
        after = (char)((ReputationTracker*)this)->GetReputationRank(1);
        if (after != val)
        {
            m_eReputationType = 1;
            changed = true;
        }
        Interface::ShowMessage(i, 0, g_011cbd5c.String(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += delta;
        m_fSecondReputationValue = (m_fSecondReputationValue > m_fMaximumReputation) ? (float)m_fMaximumReputation
                                                                                     : (float)m_fSecondReputationValue;
        _sprintf_s(i, 250, "%s\n%s", ((TESSoundFile*)((char*)this + 0x18))->GetSoundFile(), g_011cba58.String());
        after = (char)((ReputationTracker*)this)->GetReputationRank(0);
        if (after != val)
        {
            changed = true;
            m_eReputationType = 0;
        }
        Interface::ShowMessage(i, 0, g_011cbad0.String(), 0, 2.0f, false);
    }
    if (changed && !g_thePlayer->FUN_00953c50(0) && !Interface::IsInDialog())
    {
        ((FUN_006155f0_shell*)this)->ShowMessageBox();
    }
    else if (changed)
    {
        ((FUN_006159e0_shell*)g_thePlayer)->SetValue((int)this);
    }
    v18(2);
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

struct ReputationCompareEntry : TESReputation
{
    ReputationLimitData* FUN_0087eaa0();
    bool FUN_00485270(TESForm*);
    bool FUN_00616570(TESForm* other);
};

// @fnv 0x00616570
bool ReputationCompareEntry::FUN_00616570(TESForm* other)
{
    TESReputation* pOtherReputation = dynamic_cast<TESReputation*>(other);
    if (!pOtherReputation)
        return true;
    if (_memcmp(&data, static_cast<ReputationCompareEntry*>(pOtherReputation)->FUN_0087eaa0(),
                sizeof(ReputationLimitData)) != 0)
        return true;
    if (FUN_00485270(pOtherReputation))
        return true;
    return false;
}

extern "C" void* __cdecl _memcpy(void*, const void*, unsigned int);

struct ReputationComponentCopy
{
    void FUN_004851b0(TESForm* source);
};

struct ReputationCopyReceiver : TESReputation
{
    void FUN_00616500(TESForm* source);
};

// Copies the two reputation values and the data block from source (cast to TESReputation) into this object, then calls FUN_004851b0 with source.
// @fnv 0x00616500
void ReputationCopyReceiver::FUN_00616500(TESForm* source)
{
    TESReputation* reputation = dynamic_cast<TESReputation*>(source);
    if (!reputation)
        return;

    m_fSecondReputationValue = reputation->m_fSecondReputationValue;
    m_fFirstReputationValue = reputation->m_fFirstReputationValue;
    _memcpy(&data, &reputation->data, sizeof(data));
    reinterpret_cast<ReputationComponentCopy*>(this)->FUN_004851b0(source);
}

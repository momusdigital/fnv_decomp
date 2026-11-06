// fallout_shared/tesanimgroup.cpp: TESAnimGroup, BSAnimGroupSequence, TESAnimGroupDestructionView, Holder (35 functions)

#include "tesanimgroup_types.h"
#include "tesanimgroup_sequence_types.h"

// Combines powerArmor, move, weapon and group into a packed 16-bit animation group value via bit shifts.
// @fnv 0x005f2370
unsigned short TESAnimGroup::AnimGroup(ANIM_GROUP_MOVE_ENUM move, ANIM_GROUP_WEAPON_ENUM weapon, ANIM_GROUP_ENUM group,
                                       bool powerArmor)
{
    return (powerArmor << 15) + (move << 12) + (weapon << 8) + group;
}

// @fnv 0x005f23c0
ANIM_GROUP_MOVE_ENUM TESAnimGroup::GetMoveType(unsigned short group)
{
    return static_cast<ANIM_GROUP_MOVE_ENUM>((group & 0x7000) >> 12);
}

// @fnv 0x005f2440
ANIM_GROUP_ENUM TESAnimGroup::GetType(unsigned short group)
{
    return static_cast<ANIM_GROUP_ENUM>(group & 0xFF);
}

// @fnv 0x005f2420
ANIM_GROUP_ENUM TESAnimGroup::GetType() const
{
    return GetType(sType);
}

// Returns true when the animation group action type is one of the attack variants, false otherwise.
// @fnv 0x005f25a0
bool TESAnimGroup::IsActionTypeValid(ANIM_GROUP_ACTION_TYPE aeActionType)
{
    switch (aeActionType)
    {
    case _AnimationGroupActionType::ATTACK:
    case _AnimationGroupActionType::ATTACK_POWER:
    case _AnimationGroupActionType::ATTACK_THROW:
    case _AnimationGroupActionType::ATTACK_THROW_ATTACH:
    case _AnimationGroupActionType::ATTACK_SPIN:
        return true;
    default:
        return false;
    }
}

// Returns true if group is not ANIM_GROUP_NONE and its type falls between ANIM_GROUP_AIM and ANIM_GROUP_AIM_IS_DOWN.
// @fnv 0x005f2630
bool TESAnimGroup::IsAimAnimation(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    ANIM_GROUP_ENUM type = GetType(group);
    if (type >= ANIM_GROUP_ENUM_ANIM_GROUP_AIM && type <= ANIM_GROUP_ENUM_ANIM_GROUP_AIM_IS_DOWN)
        return true;
    return false;
}

// @fnv 0x005f26b0
bool TESAnimGroup::IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE type)
{
    return type == _AnimationGroupActionType::ATTACK_POWER;
}

// Returns true if the animation group type is one of the jump-loop variants, false otherwise.
// @fnv 0x005f4d60
bool TESAnimGroup::IsJumpAnimation() const
{
    switch (GetType(sType))
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_FORWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_BACKWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_LEFT:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_RIGHT:
        return true;
    default:
        return false;
    }
}

// @fnv 0x005f4c70
float TESAnimGroup::GetAnimationSpeed() const
{
    return speed.Length();
}

// @fnv 0x005f3870
char* TESAnimGroup::FindNextLine(char* pcText)
{
    pcText = strchr(pcText, '\n');
    while (pcText && *pcText && (*pcText == '\r' || *pcText == '\n'))
        ++pcText;
    if (pcText && *pcText)
        return pcText;
    return 0;
}

// @fnv 0x0048f7f0
TESAnimGroup* BSAnimGroupSequence::GetAnimGroup() const
{
    return m_spAnimGroup;
}

// Returns false for ANIM_GROUP_ENUM_ANIM_GROUP_NONE, otherwise recurses on the action of the group's type entry in DAT_011977e4.
// @fnv 0x005f2670
bool TESAnimGroup::IsValidAnimationGroup(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    return IsValidAnimationGroup(DAT_011977e4[GetType(group)].action);
}

// @fnv 0x005f2540
bool TESAnimGroup::IsActionTypeValid(unsigned short group)
{
    ANIM_GROUP_ENUM type = GetType(group);
    if (type == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    switch (type)
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_DOWN:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_DOWN:
        return true;
    }
    return IsActionTypeValid(DAT_011977e4[type].action);
}

// @fnv 0x005f4d00
void TESAnimGroup::SetSoundsFromSequence(NiControllerSequence* sequence)
{
    BSAnimGroupSequence* animSequence = static_cast<BSAnimGroupSequence*>(sequence);
    for (int i = 0; i < 8; ++i)
    {
        if (DAT_01199bcc[i])
            m_ucSectionPriorities[i] = animSequence->GetPriority(DAT_01199bcc[i], 0);
    }
}

struct FUN_0047d3b0_shell : public TESAnimGroup
{
    unsigned short FUN_0047d3b0();
};

// @fnv 0x0047d3b0
unsigned short FUN_0047d3b0_shell::FUN_0047d3b0()
{
    return sType;
}

struct NiMemObjectAllocation
{
    static void __cdecl operator delete(void* p, unsigned int size);
};

struct TESAnimGroupDestructionView : public TESAnimGroup
{
    void FUN_005f22d0();
    void* FUN_005f22a0(unsigned int flags);
};

// Calls FUN_005f22d0, frees this via NiMemObjectAllocation::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x005f22a0
void* TESAnimGroupDestructionView::FUN_005f22a0(unsigned int flags)
{
    this->FUN_005f22d0();
    if (flags & 1)
        NiMemObjectAllocation::operator delete(this, sizeof(TESAnimGroup));
    return this;
}

struct FUN_005f3740_shell : public TESAnimGroup
{
    bool FUN_005f3740(unsigned int, float);
};

// Writes afValue into the times array at aiIndex, returning false if times is null or aiIndex is out of range.
// @fnv 0x005f3740
bool FUN_005f3740_shell::FUN_005f3740(unsigned int aiIndex, float afValue)
{
    if (!times)
        return false;
    if (aiIndex >= frameCount)
        return false;
    times[aiIndex] = afValue;
    return true;
}

struct FUN_005f3780_shell : public TESAnimGroup
{
    float FUN_005f3780(int);
};

void __cdecl _FNV_Warning(const char*, ...);
int __cdecl _FNV_IsNaN(double);

struct AnimGroupInfo_011977d8
{
    const char* name;
    char pad[0x20];
};
extern AnimGroupInfo_011977d8 DAT_011977d8[];

// Validates groupAction against frameCount, warns on out-of-range or NaN times, and returns times[groupAction] or 0.0f.
// @fnv 0x005f3780
float FUN_005f3780_shell::FUN_005f3780(int groupAction)
{
    if (groupAction < 0)
    {
        _FNV_Warning("ANIMATION: Invalid anim group action (action %d too small) in %s (%04X).", groupAction,
                     DAT_011977d8[GetType(sType)].name, sType);
        return 0.0f;
    }
    if ((unsigned int)groupAction >= frameCount)
    {
        _FNV_Warning("ANIMATION: Invalid anim group action (action %d too big %d max) in %s (%04x).", groupAction,
                     frameCount, DAT_011977d8[GetType(sType)].name, sType);
        return 0.0f;
    }
    if (times)
    {
        if (_FNV_IsNaN(times[groupAction]))
        {
            _FNV_Warning("ANIMATION: Time %d in group %04X is QNAN", groupAction, sType);
            return 0.0f;
        }
        return times[groupAction];
    }
    return 0.0f;
}

template <typename T> unsigned int __cdecl BSStringLength(const T* str);

const char* __cdecl _strrchr(const char*, int);
int __cdecl __strnicmp(const char*, const char*, unsigned int);

extern const char* DAT_01197794[];
extern const char* DAT_011977a4[];

// @fnv 0x005f38d0
void __cdecl ParseAnimGroupFilename(const char* apModelName, unsigned int* aeMove, unsigned int* aeWeapon, bool* abPowerArmor)
{
    unsigned int n;
    const char* plastSlash = _strrchr(apModelName, '\\');
    *abPowerArmor = false;
    *aeMove = 0;
    *aeWeapon = 0;
    if (plastSlash)
    {
        plastSlash = plastSlash + 1;
        if (__strnicmp(plastSlash, "PA", BSStringLength("PA")) == 0)
        {
            *abPowerArmor = true;
            plastSlash += BSStringLength("PA");
        }
        for (n = 1; n < 4; ++n)
        {
            if (__strnicmp(plastSlash, DAT_01197794[n], BSStringLength(DAT_01197794[n])) == 0)
            {
                *aeMove = n;
                plastSlash += BSStringLength(DAT_01197794[n]);
                break;
            }
        }
        for (n = 1; n < 12; ++n)
        {
            if (__strnicmp(plastSlash, DAT_011977a4[n], BSStringLength(DAT_011977a4[n])) == 0)
            {
                *aeWeapon = n;
                break;
            }
        }
    }
}

struct FUN_005f4c40_shell : public TESAnimGroup
{
    void SetSpeed(NiPoint3*);
};

// Stores the NiPoint3 pointed to by apSpeed into the speed field.
// @fnv 0x005f4c40
void FUN_005f4c40_shell::SetSpeed(NiPoint3* apSpeed)
{
    speed = *apSpeed;
}

extern char* PTR_s_Start_01199a50[][11];
struct UShortArg
{
    unsigned short v;
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x005f2450
void __fastcall SetAnimGroupType(TESAnimGroup* self, UShortArg type)
{
    self->sType = type.v;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (!*PTR_s_Start_01199a50[i][*(int*)&DAT_011977e4[TESAnimGroup::GetType(type.v)]])
            break;
    }
    self->frameCount = i;
    if (self->times)
        delete self->times;
    if (self->frameCount)
    {
        self->times = new float[self->frameCount];
        memset(self->times, 0, self->frameCount * sizeof(float));
    }
    else
    {
        self->times = 0;
    }
}

extern int DAT_010484e8;

void __cdecl operator delete(void*);

struct EBase
{
    virtual ~EBase();
};

struct FUN_005f22d0 : EBase
{
    char pad18[0x18 - sizeof(EBase)];
    void* times;
    char pad34[0x34 - 0x18 - sizeof(void*)];
    int m_uiSoundEntryCount;
    void* sounds;

    virtual ~FUN_005f22d0();
};

// @fnv 0x005f22d0
FUN_005f22d0::~FUN_005f22d0()
{
    void* p = times;
    operator delete(p);
    times = 0;
    operator delete(sounds);
    sounds = 0;
    m_uiSoundEntryCount = 0;
}

struct FUN_005f23a0_shell : TESAnimGroup
{
    ANIM_GROUP_MOVE_ENUM GetMoveAnimGroup();
};

// @fnv 0x005f23a0
ANIM_GROUP_MOVE_ENUM FUN_005f23a0_shell::GetMoveAnimGroup()
{
    return TESAnimGroup::GetMoveType(this->sType);
}

extern "C" unsigned short __cdecl FUN_005f2400(unsigned short);

struct FUN_005f23e0_shell
{
    unsigned short __thiscall FUN_005f23e0();
};

// @fnv 0x005f23e0
unsigned short __thiscall FUN_005f23e0_shell::FUN_005f23e0()
{
    return FUN_005f2400(*((unsigned short*)((char*)this + 0x10)));
}

namespace fnv_005f2400 {
// @fnv 0x005f2400
int FUN_005f2400(unsigned short ausValue)
{
    return (ausValue & 0xf00) >> 8;
}
}  // namespace fnv_005f2400

// @fnv 0x005f2610
bool __cdecl IsNine(int aiValue)
{
    if (aiValue == 9)
    {
        return true;
    }
    return false;
}

// @fnv 0x005f2700
bool IsValidCharCode(int aiCharCode)
{
    if (aiCharCode >= 0xb1 && aiCharCode <= 0xc7)
        return true;
    return false;
}

bool __cdecl IsIronSightsAction(ANIM_GROUP_ENUM);

// Returns false for anim group 0xff, otherwise checks whether the group's type is an iron sights action.
// @fnv 0x005f2720
bool IsIronSightsAnimGroup(unsigned short usAnimGroup)
{
    if (usAnimGroup == 0xff)
        return false;
    return IsIronSightsAction(TESAnimGroup::GetType(usAnimGroup));
}

int __cdecl GetType(unsigned short);
bool __cdecl IsNine(int);

// Returns false for type 0xff, otherwise looks up the type's entry and returns the result of IsNine on its stored value.
// @fnv 0x005f25d0
bool IsAttackSpinAction(unsigned short ausType)
{
    if (ausType == 0xff)
        return false;
    return IsNine(*(int*)(GetType(ausType) * 0x24 + 0x11977e4));
}

struct TESSound;
struct SoundPlaybackEntry
{
    float fTime;
    unsigned char m_bFlag;
    char _pad_5[3];
    float fCurrentSpeed;
    TESSound* SoundAssetTmp;
};
typedef char _sizecheck_GROUP_SOUND[sizeof(SoundPlaybackEntry) == 16 ? 1 : -1];
struct FUN_005f2820_shell : public TESAnimGroup
{
    void FUN_005f2820(unsigned int);
};

void* __cdecl _Deallocate(void*);
void* __cdecl __memcpy(void*, const void*, unsigned int);
void* __cdecl _Reallocate(void*, unsigned int);

// Resizes the sounds array to count entries, copying existing entries and initialising new ones with default time, type and volume values.
// @fnv 0x005f2820
void FUN_005f2820_shell::FUN_005f2820(unsigned int count)
{
    unsigned int oldSoundCount = m_uiSoundEntryCount;
    m_uiSoundEntryCount = count;
    if (!m_uiSoundEntryCount)
    {
        _Deallocate(sounds);
        sounds = 0;
        return;
    }
    if (oldSoundCount)
    {
        SoundPlaybackEntry* sounds_old = (SoundPlaybackEntry*)operator new(oldSoundCount * 16);
        __memcpy(sounds_old, sounds, oldSoundCount * 16);
        sounds = (AnimGroupSound*)_Reallocate(sounds, m_uiSoundEntryCount * 16);
        unsigned int n = oldSoundCount;
        if (oldSoundCount > m_uiSoundEntryCount)
            n = m_uiSoundEntryCount;
        __memcpy(sounds, sounds_old, n * 16);
        _Deallocate(sounds_old);
        for (unsigned int i = oldSoundCount; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
    else
    {
        sounds = (AnimGroupSound*)operator new(m_uiSoundEntryCount * 16);
        for (unsigned int i = 0; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
}

int __cdecl GetType(unsigned short);
// Returns true when GetType(a) is 0, 1 or 0xAA, otherwise false.
// @fnv 0x005f4cc0
bool __cdecl IsIdleAnim(unsigned short ausType)
{
    switch (GetType(ausType))
    {
    case 0:
    case 1:
    case 0xAA:
        return true;
    default:
        return false;
    }
}

namespace fnv_005f3a20 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiStream;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob36
{
    char b[36];
};
struct TimedTextEntry
{
    void SetTime(float);
    float GetTime();
    void SetText(void*);
    void* GetText();
    TimedTextEntry* Copy();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void RegisterStreamables(NiStream*);
    void* __vecDelDtor(unsigned int);
    float m_fTime;
    NiFixedString m_kText;
};
typedef char _sizecheck_NiTextKey[sizeof(TimedTextEntry) == 8 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

int _stricmp(const char* str1, const char* str2);
int __strnicmp(const char* str1, const char* str2, int count);
const char* _strrchr(const char* str, int ch);
void _FNV_Warning(const char* format, ...);
template <class T> unsigned int BSStringLength(const T* str);
char* strchr(char* str, int ch);
double atof(const char* str);
long atol(const char* str);
int strcpy_s(char* dest, unsigned int size, const char* src);
int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
int TruncateFloatToInt(float f);
void FUN_0043b2b0(bool b);

struct NiFixedStringEx : NiFixedString
{
    NiFixedStringEx(const NiFixedString& kString);
    ~NiFixedStringEx();
    bool Exists() const;
    operator const char*() const;
};

struct NiTextKeyExtraData
{
    TimedTextEntry* GetKeys(unsigned int& uiNumKeys) const;
};

struct NiControllerSequenceEx : NiControllerSequence
{
    const NiFixedStringEx& GetName() const;
    const NiFixedStringEx& GetAccumRootName() const;
    unsigned int GetNumIDs() const;
    void GetIDTagName(unsigned int uiIndex, char* pcName);
    bool GetEntryByte0d(int iIndex);
    void SetEntryByte(int iIndex, bool bValue);
    NiTextKeyExtraData* GetTextKeys() const;
    unsigned int GetCycleType() const;
};

enum ANIM_ENUM
{
};

struct TESSound
{
    unsigned int GetSoundID();
};

struct BSAudio
{
    static BSAudio* GetSingleton();
    void ForwardToManager(unsigned int uiSoundID, bool bValue);
};

struct TESDataHandler
{
    TESSound* GetSoundByEditorID(const char* pName);
};

struct TESFile
{
    static char* IsTempIDLoadable();
};

struct TESAnimGroupEx : TESAnimGroup
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    TESAnimGroupEx(unsigned short sGroup);
    unsigned int GetSoundCount();
    void ResizeSoundList(unsigned int ItemUpdateArray);
    void SetSoundTime(unsigned int uiIndex, float fTime);
    void SetSound(unsigned int uiIndex, TESSound* SoundAssetTmp);
    void SetSoundEnum(unsigned int uiIndex, ANIM_ENUM eType, unsigned int uiData);
    void SetSoundVolume(unsigned int uiIndex, float m_fFadeDuration);
    void SetSoundPitch(unsigned int uiIndex, float fCurrentSpeed);
    void SetParentName(const char* pName);
    void SetBlendIn(unsigned char cFrames);
    void SetBlendOut(unsigned char cFrames);
    void SetBlend(unsigned char cFrames);
    void SetDecal(unsigned char m_ucDecal);
    char GetMorphKey();
    void SetMorphKey(unsigned char cKey);
    bool SetActionTime(unsigned int eAction, float fTime);
    float GetActionTime(int eAction);
};

void ParseAnimationGroupFilename(const char* pFilename, ANIM_GROUP_MOVE_ENUM& eMove, ANIM_GROUP_WEAPON_ENUM& eWeapon,
                                 bool& bPowerArmor);

struct AnimGroupInfo
{
    const char* pName;
    int iUnk04;
    int iLoopType;
    int iSequenceType;
    int m_iPadding[5];
};

extern AnimGroupInfo DAT_011977d8[];
extern const char* DAT_01199a50[][11];
extern const char* DAT_01199b50[];
extern const char* DAT_011a8244;
extern TESDataHandler* g_dataHandler;

// Parses a controller sequence's text keys to build a TESAnimGroupEx, setting parent, morph, blend, decal and sound data and warning on bad notes.
// @fnv 0x005f3a20
TESAnimGroup* FUN_005f3a20(NiControllerSequenceEx* apSequence, const char* apModelName)
{
    ANIM_GROUP_ENUM m;
    char message[260];
    bool bshowWarning = false;
    TESAnimGroupEx* panimGroup = 0;
    ANIM_GROUP_ENUM lastGroup = (ANIM_GROUP_ENUM)0xff;
    unsigned int iactionIndex = 0;
    bool bpowerArmor = false;
    ANIM_GROUP_MOVE_ENUM eanimMove = ANIM_GROUP_MOVE_ENUM_AGM_NONE;
    ANIM_GROUP_WEAPON_ENUM eanimWeapon = ANIM_GROUP_WEAPON_ENUM_AGW_NONE;
    const char* plastSlash = _strrchr(apModelName, '\\');
    FUN_0043b2b0(true);
    const char* paccumName = apSequence->GetAccumRootName();
    int iaccumIndex = -1;
    int inonAccumIndex = -1;
    char cnonAccumName[64];
    sprintf_s(cnonAccumName, 64, "%s NonAccum", paccumName);
    unsigned int n;
    for (n = 0; n < apSequence->GetNumIDs(); n++)
    {
        char ptestName[260];
        apSequence->GetIDTagName(n, ptestName);
        if (ptestName[0])
        {
            if (!_stricmp(paccumName, ptestName))
                iaccumIndex = n;
            else if (!_stricmp(cnonAccumName, ptestName))
                inonAccumIndex = n;
        }
        else
        {
            _FNV_Warning("No object name at index %i for sequence '%s'.", n, (const char*)apSequence->GetName());
        }
        if (iaccumIndex != -1 && inonAccumIndex != -1)
        {
            apSequence->SetEntryByte(inonAccumIndex, apSequence->GetEntryByte0d(iaccumIndex));
            break;
        }
    }

    ParseAnimationGroupFilename(apModelName, eanimMove, eanimWeapon, bpowerArmor);

    if (apSequence && apSequence->GetTextKeys())
    {
        unsigned int numKeys;
        char plocalKeyText[260];
        TimedTextEntry* key = apSequence->GetTextKeys()->GetKeys(numKeys);
        for (n = 0; n < numKeys; n++)
        {
            NiFixedStringEx keyText(*(NiFixedString*)key[n].GetText());
            float time = key[n].GetTime();
            if (!keyText.Exists())
            {
                _FNV_Warning("ANIMATION: AnimGroup empty note key at time %.2f in sequence '%s' in model '%s'.", time,
                             (const char*)apSequence->GetName(), apModelName);
                bshowWarning = true;
            }
            else if (!__strnicmp(keyText, "prn:", 4))
            {
                if (((const char*)keyText)[4] != ' ')
                    panimGroup->SetParentName(keyText + 4);
                else
                    panimGroup->SetParentName(keyText + 5);
            }
            else
            {
                strcpy_s(plocalKeyText, 260, keyText);
                char* ptoken = plocalKeyText;
                char* pfirstLineOfKeyText = plocalKeyText;
                while (ptoken && BSStringLength(ptoken))
                {
                    if (*ptoken == '\r')
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                    if (!__strnicmp(ptoken, DAT_011a8244, BSStringLength(DAT_011a8244)))
                    {
                        if (!panimGroup->GetMorphKey())
                            panimGroup->SetMorphKey(ptoken[2]);
                    }
                    else if (!__strnicmp(ptoken, "BlendIn:", 8))
                    {
                        if (ptoken[8] != ' ')
                            panimGroup->SetBlendIn(atol(ptoken + 8));
                        else
                            panimGroup->SetBlendIn(atol(ptoken + 9));
                    }
                    else if (!__strnicmp(ptoken, "BlendOut:", 9))
                    {
                        if (ptoken[9] != ' ')
                            panimGroup->SetBlendOut(atol(ptoken + 9));
                        else
                            panimGroup->SetBlendOut(atol(ptoken + 10));
                    }
                    else if (!__strnicmp(ptoken, "Blend:", 6))
                    {
                        if (ptoken[6] != ' ')
                            panimGroup->SetBlend(atol(ptoken + 6));
                        else
                            panimGroup->SetBlend(atol(ptoken + 7));
                    }
                    else if (!__strnicmp(ptoken, "Decal:", 6))
                    {
                        if (ptoken[6] != ' ')
                            panimGroup->SetDecal(atol(ptoken + 6));
                        else
                            panimGroup->SetDecal(atol(ptoken + 7));
                    }
                    else if (!__strnicmp(ptoken, "Sound:", BSStringLength("Sound:")) ||
                             !__strnicmp(ptoken, "Enum:", BSStringLength("Enum:")))
                    {
                        bool benum = false;
                        if (!__strnicmp(ptoken, "Enum:", BSStringLength("Enum:")))
                            benum = true;
                        if (panimGroup)
                        {
                            char* cr2 = strchr(ptoken, '\r');
                            if (cr2)
                                *cr2 = 0;
                            const char* soundID = ptoken;
                            if (benum)
                                soundID += BSStringLength("Enum: ");
                            else
                                soundID += BSStringLength("Sound: ");
                            strcpy_s(message, 260, soundID);
                            char* vol = 0;
                            char* pitch = 0;
                            char* cr = strchr(message, ',');
                            if (cr)
                            {
                                vol = cr + 1;
                            }
                            else
                            {
                                cr = strchr(message, ' ');
                                if (cr)
                                    vol = cr + 1;
                            }
                            if (cr)
                                *cr = 0;
                            if (vol)
                            {
                                while (*vol == ' ' && *vol != '\r')
                                    vol++;
                                cr = strchr(vol, ',');
                                if (cr)
                                {
                                    pitch = cr + 1;
                                }
                                else
                                {
                                    cr = strchr(vol, ' ');
                                    if (cr)
                                        pitch = cr + 1;
                                }
                                if (cr)
                                    *cr = 0;
                            }
                            bool bbadNote = false;
                            if (benum)
                            {
                                ANIM_ENUM etype = (ANIM_ENUM)0;
                                while (etype < 31 && _stricmp(DAT_01199b50[etype], message))
                                    etype = (ANIM_ENUM)(etype + 1);
                                if (etype < 31)
                                {
                                    unsigned int iElementIndex = ((ptoken - pfirstLineOfKeyText) << 8) | n;
                                    unsigned int m_uiSoundEntryCount = panimGroup->GetSoundCount();
                                    panimGroup->ResizeSoundList(m_uiSoundEntryCount + 1);
                                    panimGroup->SetSoundTime(m_uiSoundEntryCount, time);
                                    panimGroup->SetSoundEnum(m_uiSoundEntryCount, etype, iElementIndex);
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            else
                            {
                                TESSound* openSound = g_dataHandler->GetSoundByEditorID(message);
                                if (openSound)
                                {
                                    BSAudio::GetSingleton()->ForwardToManager(openSound->GetSoundID(), false);
                                    unsigned int m_uiSoundEntryCount = panimGroup->GetSoundCount();
                                    panimGroup->ResizeSoundList(m_uiSoundEntryCount + 1);
                                    panimGroup->SetSoundTime(m_uiSoundEntryCount, time);
                                    panimGroup->SetSound(m_uiSoundEntryCount, openSound);
                                    if (vol && *vol)
                                        panimGroup->SetSoundVolume(m_uiSoundEntryCount, atof(vol));
                                    if (pitch)
                                        panimGroup->SetSoundPitch(m_uiSoundEntryCount, atof(pitch));
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            if (bbadNote)
                            {
                                _FNV_Warning("ANIMATION: Bad note string \"%s\" frame %d in \"%s\".", ptoken,
                                             TruncateFloatToInt(time * 30.0), apModelName);
                                bshowWarning = true;
                            }
                            if (cr2)
                                *cr2 = '\r';
                        }
                    }
                    else
                    {
                        for (m = (ANIM_GROUP_ENUM)0; m < 245; m = (ANIM_GROUP_ENUM)(m + 1))
                        {
                            if (lastGroup != 0xff)
                                m = lastGroup;
                            if (!_stricmp(apSequence->GetName(), DAT_011977d8[m].pName))
                            {
                                lastGroup = m;
                                ANIM_GROUP_ACTION action = (ANIM_GROUP_ACTION)DAT_011977d8[m].m_iPadding[iactionIndex];
                                if (action == -1)
                                    break;
                                if (m == 2 && iactionIndex == 1 &&
                                    !__strnicmp(ptoken, DAT_01199a50[3][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[3][DAT_011977d8[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if (DAT_011977d8[m].iSequenceType == 5 && iactionIndex == 2 &&
                                    !__strnicmp(ptoken, DAT_01199a50[3][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[3][DAT_011977d8[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if (!__strnicmp(ptoken, DAT_01199a50[action][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[action][DAT_011977d8[m].iSequenceType])))
                                {
                                    if (!panimGroup)
                                    {
                                        if (m == 2)
                                            panimGroup = new TESAnimGroupEx((unsigned short)m);
                                        else
                                            panimGroup = new TESAnimGroupEx(
                                                TESAnimGroup::AnimGroup(eanimMove, eanimWeapon, m, bpowerArmor));
                                    }
                                    if (time > -1.0)
                                        panimGroup->SetActionTime(action, time);
                                    if (DAT_011977d8[m].iSequenceType == 1 && apSequence->GetCycleType())
                                    {
                                        if (DAT_011977d8[m].iLoopType != 1)
                                        {
                                            _FNV_Warning("ANIMATION: '%s' should be a looping animation.", apModelName);
                                            bshowWarning = true;
                                        }
                                    }
                                    else if (DAT_011977d8[m].iSequenceType != 1 && !apSequence->GetCycleType())
                                    {
                                        _FNV_Warning("ANIMATION: '%s' should NOT be a looping animation.", apModelName);
                                        bshowWarning = true;
                                    }
                                    iactionIndex++;
                                    break;
                                }
                                if (iactionIndex == 5 || DAT_011977d8[m].m_iPadding[iactionIndex] == -1)
                                {
                                    char* cr = strchr(ptoken, '\r');
                                    if (cr)
                                        *cr = 0;
                                    _FNV_Warning("ANIMATION: Bad note string \"%s\" frame %d in \"%s\".", ptoken,
                                                 TruncateFloatToInt(time * 30.0), apModelName);
                                    if (cr)
                                        *cr = '\r';
                                    bshowWarning = true;
                                }
                                break;
                            }
                            else if (m == lastGroup)
                            {
                                break;
                            }
                        }
                        if (m == 245)
                        {
                            _FNV_Warning("ANIMATION: AnimGroup unable to find sequence '%s' in model '%s'.",
                                         (const char*)apSequence->GetName(), apModelName);
                            bshowWarning = true;
                            ptoken = 0;
                            n = numKeys;
                        }
                    }
                    if (ptoken)
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                }
            }
        }

        if (panimGroup)
        {
            panimGroup->SetSoundsFromSequence(apSequence);
            ANIM_GROUP_ACTION estartAction = (ANIM_GROUP_ACTION)0;
            ANIM_GROUP_ACTION eendAction = (ANIM_GROUP_ACTION)1;
            switch (DAT_011977d8[panimGroup->GetType()].iSequenceType)
            {
            case 7:
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 8:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 9:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 5:
                if (panimGroup->GetActionTime(2) < panimGroup->GetActionTime(1))
                    panimGroup->SetActionTime(2, panimGroup->GetActionTime(1));
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 6:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 10:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 2:
                if (panimGroup->GetActionTime(1) < panimGroup->GetActionTime(0))
                    panimGroup->SetActionTime(1, panimGroup->GetActionTime(0));
                if (panimGroup->GetActionTime(2) <= panimGroup->GetActionTime(1))
                    panimGroup->SetActionTime(2, panimGroup->GetActionTime(3));
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 3:
            case 4:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            }
            if (panimGroup->GetActionTime(eendAction) <= panimGroup->GetActionTime(estartAction))
            {
                _FNV_Warning("ANIMATION: (%s) End frame is less than or equal to Start frame in \"%s\".",
                             DAT_011977d8[panimGroup->GetType()].pName, apModelName);
                bshowWarning = true;
            }
            if (panimGroup->m_ucBlendCount && (panimGroup->m_ucBlendInCount || panimGroup->m_ucBlendOutCount))
            {
                _FNV_Warning("ANIMATION: (%s) too many blend values in \"%s\". Blend %d, BlendIn %d, BlendOut %d",
                             DAT_011977d8[panimGroup->GetType()].pName, apModelName, panimGroup->m_ucBlendCount,
                             panimGroup->m_ucBlendInCount, panimGroup->m_ucBlendOutCount);
                bshowWarning = true;
            }
        }
    }

    FUN_0043b2b0(false);
    if (bshowWarning)
        _FNV_Warning("ANIMATION: Animation group note problem. See %s file.", TESFile::IsTempIDLoadable());
    return panimGroup;
}
}  // namespace fnv_005f3a20

struct FUN_005f26c0_cls : public TESAnimGroup
{
    bool FUN_005f26c0();
};

int __cdecl FUN_005f2440(unsigned short);

// Returns true when the animation group's sType maps to one of the codes 0x5c through 0x65, otherwise false.
// @fnv 0x005f26c0
bool FUN_005f26c0_cls::FUN_005f26c0()
{
    switch (FUN_005f2440(sType))
    {
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
        return true;
    default:
        return false;
    }
}

// FUN_005f2750: switch over a byte-coded action id; true for the listed action ids.
// @fnv 0x005f2750
bool __cdecl FUN_005f2750(int a)
{
    switch (a)
    {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8d:
    case 0x8e:
    case 0x8f:
    case 0x93:
    case 0x94:
    case 0x95:
        return true;
    default:
        return false;
    }
}

struct Vec3
{
    int x;
    int y;
    int z;
};

struct Holder
{
    char pad[0x1c];
    Vec3 m_vec;
    Vec3* GetVec(Vec3* out);
};

// Copies m_vec into the out parameter and returns out.
// @fnv 0x005f4c90
Vec3* Holder::GetVec(Vec3* out)
{
    *out = m_vec;
    return out;
}

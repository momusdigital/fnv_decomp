// fallout_shared/teschallenge.cpp: TESChallenge, ChallengeManager (16 functions)

#include "teschallenge_decls.h"

// @fnv 0x005F5080
void TESChallenge::InitItem()
{
    if (GetInitialized())
        return;
    TESScriptableForm::InitItem(this);
    unsigned int formID = reinterpret_cast<unsigned int>(m_pPrimaryForm);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pPrimaryForm = GetFormByID(formID);
        if (!m_pPrimaryForm)
            Warning("MASTERFILE: Could not find Form (%08X) on challenge '%s' (%08X).", formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(m_pSecondaryForm);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSecondaryForm = GetFormByID(formID);
        if (!m_pSecondaryForm)
            Warning("MASTERFILE: Could not find Form (%08X) on challenge '%s' (%08X).", formID, GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x005F57C0
void TESChallenge::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    buffer->ReadTypedData(&progress.iProgress, sizeof(progress.iProgress));
    buffer->ReadTypedData(&progress.m_iCompletionCount, sizeof(progress.m_iCompletionCount));
}

// @fnv 0x005F5950
bool ChallengeManager::UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                               unsigned short specialOne, unsigned short specialTwo,
                                               unsigned short specialThree)
{
    if (type >= CHALLENGE_TYPE_CHALLENGE_TYPE_COUNT || type < 0)
        return false;
    BSSimpleList<TESChallenge*>* list = &pChallengeList[type];
    bool completed = false;
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = list->GetItem();
        bool applicable = true;
        if (challenge)
        {
            if (challenge->GetCompleted() && !challenge->GetRecurring())
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetStartsLocked() && !challenge->GetUnlocked())
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetFormOne())
            {
                if (!formOne)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE_LIST: {
                        BGSListForm* formList = static_cast<BGSListForm*>(challenge->GetFormOne());
                        if (formList && !formList->GetList()->IsInList(formOne))
                            applicable = false;
                        break;
                    }
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_SKILL:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_CRAFT_WITH_ITEM:
                        if (formOne != challenge->GetFormOne())
                            applicable = false;
                        break;
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                        if (formOne != challenge->GetFormOne())
                            applicable = false;
                        break;
                    }
                }
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetFormTwo())
            {
                if (!formTwo)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_CATEGORY:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE: {
                        BGSListForm* formList = static_cast<BGSListForm*>(challenge->GetFormTwo());
                        if (formList && !formList->GetList()->IsInList(formTwo))
                            applicable = false;
                        break;
                    }
                    }
                }
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            bool special = false;
            if (challenge->GetSpecialOne())
            {
                if (!specialOne)
                    applicable = false;
                if (specialOne != challenge->GetSpecialOne())
                    applicable = false;
            }
            else if (challenge->GetChallengeType() == CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT)
            {
                if (specialOne != challenge->GetSpecialOne())
                    applicable = false;
            }
            if (challenge->GetSpecialTwo())
            {
                if (!specialTwo)
                    applicable = false;
                if (specialTwo != challenge->GetSpecialTwo())
                    applicable = false;
            }
            else
            {
                switch (challenge->GetChallengeType())
                {
                case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    if (specialTwo && specialTwo != 1)
                        applicable = false;
                    break;
                }
            }
            if (challenge->GetSpecialThree())
            {
                if (!specialThree)
                    applicable = false;
                if (specialThree != challenge->GetSpecialThree())
                    applicable = false;
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            challenge->IncrementProgress(count);
            if (challenge->GetProgressValue() >= challenge->GetThreshold())
            {
                if (challenge->GetScript())
                    challenge->GetScript()->ExecuteScript(reinterpret_cast<TESObjectREFR*>(g_thePlayer), 0);
                if (challenge->GetChallengeType() != CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT ||
                    challenge->GetSpecialOne() != 27)
                    TopicMenuController::IncrementMiscStat(27);
                if (challenge->GetFullName() && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                    DAT_011cb4d4.Bool()->b)
                {
                    char message[512];
                    sprintf_s(message, sizeof(message), "%s   %d\\%d\n%s", challenge->GetFullName(),
                              challenge->GetThreshold(), challenge->GetThreshold(),
                              challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                    Interface::ShowMessage(message, 0, TESTextureLoader::GetTextureResourceName(challenge, 0), 0,
                                           DAT_010162c0, false);
                    Interface::PlayUISound(21);
                }
                if (challenge->GetRecurring() && !challenge->GetRemovedRecurring())
                {
                    int excess = challenge->GetProgressValue() - challenge->GetThreshold();
                    challenge->ClearProgress();
                    challenge->SetCompletedRecurring(true);
                    challenge->IncrementProgress(excess);
                }
                else
                {
                    challenge->MarkCompleted(true);
                    completed = true;
                }
            }
            else
            {
                struct ProgressInterval
                {
                    int interval;
                    int progress;
                } values;
                values.progress = challenge->GetProgressValue();
                values.interval = challenge->GetInterval() ? challenge->GetInterval() : 100;
                for (int value = values.progress; value >= 0; value -= values.interval)
                {
                    if (value == 0)
                    {
                        if (challenge->GetFullName() && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                            DAT_011cb4d4.Bool()->b)
                        {
                            char message[512];
                            sprintf_s(message, sizeof(message), "%s   %d\\%d\n%s", challenge->GetFullName(),
                                      challenge->GetProgressValue(), challenge->GetThreshold(),
                                      challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                            Interface::ShowMessage(message, 0, TESTextureLoader::GetTextureResourceName(challenge, 0),
                                                   0, DAT_010162c0, false);
                        }
                    }
                }
            }
        }
        list = list->GetNext();
    }
    if (completed)
        CheckCompletedChallenges();
    return true;
}

// @fnv 0x005F51A0
bool TESChallenge::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    CHUNK_ID chunk;
    while (chunk = (CHUNK_ID)file->GetChunkID())
    {
        switch (chunk)
        {
        case (CHUNK_ID)0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case (CHUNK_ID)0x444e424f:
            readOBNDSubRecord(file);
            break;
        case (CHUNK_ID)0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case (CHUNK_ID)0x4e4f4349:
            TESTextureLoader::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case (CHUNK_ID)0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case (CHUNK_ID)0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case (CHUNK_ID)0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case (CHUNK_ID)0x41544144:
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.SwapEndianFields();
            break;
        case (CHUNK_ID)0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SetFormOne(reinterpret_cast<TESForm*>(formID));
            break;
        }
        case (CHUNK_ID)0x4d414e58: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SetFormTwo(reinterpret_cast<TESForm*>(formID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005F5880
void ChallengeManager::CheckCompletedChallenges()
{
    Clear();
    BSSimpleList<TESChallenge*>* list = g_dataHandler->FUN_00461150();
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = list->GetItem();
        if (challenge && !challenge->GetCompleted() && (!challenge->GetStartsLocked() || challenge->GetUnlocked()))
            pChallengeList[challenge->GetChallengeType()].AddHead(challenge);
        else if (challenge)
            ms_kInactiveChallengesByType[challenge->GetChallengeType()].AddHead(challenge);
        list = list->GetNext();
    }
}

// @fnv 0x005F4FD0
void TESChallenge::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    memset(&progress, 0, sizeof(progress));
    m_pPrimaryForm = 0;
    m_pSecondaryForm = 0;
    SetShowZero(true);
}

// Sets or clears bit 2 of data.nFlags according to show.
// @fnv 0x005f5020
void TESChallenge::SetShowZero(bool show)
{
    !show ? data.nFlags &= ~4 : data.nFlags |= 4;
}

// Clears all 14 entries by calling RemoveAll on both parallel arrays.
// @fnv 0x005f5840
void ChallengeManager::Clear()
{
    for (int i = 0; i < 14; ++i)
    {
        pChallengeList[i].RemoveAll();
        ms_kInactiveChallengesByType[i].RemoveAll();
    }
}

// @fnv 0x005f5800
void TESChallenge::MarkForSave()
{
    MarkAsModified(2);
}

// @fnv 0x005f5930
int TESChallenge::GetStartsLocked()
{
    return data.nFlags & 1;
}

struct FUN_005f4e00 : public TESForm,
                      public TESFullName,
                      public TESDescription,
                      public TESScriptableForm,
                      public TESIcon,
                      public BGSMessageIcon
{
    FUN_005f4e00();
    ~FUN_005f4e00();
};

// @fnv 0x005f4e00
FUN_005f4e00::FUN_005f4e00()
{
    ((TESChallenge*)this)->TESChallenge::ResetFormData();
    SetFormType((ENUM_FORM_ID)0x71);
}

struct FUN_00484bf0_shell
{
    unsigned short __thiscall FUN_00484bf0(unsigned int aiFlags);
};

struct FUN_005a7770_shell
{
    unsigned short __thiscall FUN_005a7770(unsigned int aiFlags);
};

// @fnv 0x005a7770
unsigned short __thiscall FUN_005a7770_shell::FUN_005a7770(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0_shell*)this)->FUN_00484bf0(aiFlags);
    return isize;
}

struct FUN_005f5820_shell
{
    void ClearField6C();
};

// @fnv 0x005f5820
void FUN_005f5820_shell::ClearField6C()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6c) = 0;
}

struct FUN_0051b070_shell
{
    void __thiscall FUN_00484c20(unsigned int aiFlags);
};

struct FUN_0059adb0_shell
{
    void __thiscall FUN_0059adb0(unsigned int aiFlags);
};

// @fnv 0x0059adb0
void __thiscall FUN_0059adb0_shell::FUN_0059adb0(unsigned int aiFlags)
{
    ((FUN_0051b070_shell*)this)->FUN_00484c20(aiFlags);
}

struct TESFormStub
{
    void __thiscall FUN_00484c50(unsigned int, unsigned int);
};

struct FUN_00616640_shell : public TESFormStub
{
    void __thiscall FUN_00616640(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// @fnv 0x00616640
void __thiscall FUN_00616640_shell::FUN_00616640(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    this->FUN_00484c50(aiFlags, aiCurrentFlags);
}

struct TESQuest
{
    PerkEntryConditionSet* __thiscall GetConditions(void);
};

struct FUN_005e79a0_t
{
    bool __thiscall FUN_00485270(TESForm* apForm);
};

extern "C" int _memcmp(const void*, const void*, unsigned int);

struct FUN_005f56b0_shell
{
    bool __thiscall IsNotEqual(TESForm* apCompare);
};

// Compares this TESChallenge against apCompare: returns true if it is not a TESChallenge or if data, form two, form one or the base comparison differ.
// @fnv 0x005f56b0
bool __thiscall FUN_005f56b0_shell::IsNotEqual(TESForm* apCompare)
{
    TESChallenge* pcomp = dynamic_cast<TESChallenge*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(&((TESChallenge*)this)->data, ((TESQuest*)pcomp)->GetConditions(), 0x18) != 0)
        return true;
    if (((TESChallenge*)this)->GetFormTwo() != pcomp->GetFormTwo())
        return true;
    if (((TESChallenge*)this)->GetFormOne() != pcomp->GetFormOne())
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;
    return false;
}

struct FUN_005f4ee0_shell
{
    void __thiscall FUN_005f4f10();
    void* __thiscall FUN_005f4ee0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_005f4f10 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005f4ee0
void* __thiscall FUN_005f4ee0_shell::FUN_005f4ee0(unsigned int flags)
{
    this->FUN_005f4f10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

bool __cdecl FUN_00401500();
void __cdecl FUN_00485910(unsigned int, unsigned int);
struct FUN_004855a0
{
    void __thiscall M();
};
struct S_00487010
{
    void __thiscall FUN_00487010();
};
struct S_0048cca0
{
    void __thiscall FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
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
    void __thiscall M();
};
struct FUN_005f5540_shell
{
    void __thiscall Initialize();
};
// @fnv 0x005f5540
void __thiscall FUN_005f5540_shell::Initialize()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    ((FUN_0048e370_obj*)((char*)this + 0x38))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x44))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x2c))->FUN_0048cca0();
    ((FUN_00482cb0_shell*)((char*)this + 0x24))->FUN_00482cb0();
    if (FUN_00401500())
        ((ChallengeData*)((char*)this + 0x54))->SwapEndianFields();
    ((FUN_00485e00_shell*)this)->__SaveData((int)((char*)this + 0x54), 0x18);
    if (FUN_00401500())
        ((ChallengeData*)((char*)this + 0x54))->SwapEndianFields();
    if (*(unsigned int*)((char*)this + 0x74))
    {
        unsigned int v1 = ((TESForm**)((char*)this + 0x74))[0]->GetFormID();
        FUN_00485910(0x4d414e53, v1);
    }
    if (*(unsigned int*)((char*)this + 0x78))
    {
        unsigned int v2 = ((TESForm**)((char*)this + 0x78))[0]->GetFormID();
        FUN_00485910(0x4d414e58, v2);
    }
    ((FUN_00485680*)this)->M();
}

struct FUN_005e78f0_t
{
    void __thiscall FUN_004851b0(TESForm* apForm);
};

void* __cdecl memcpy(void* dest, const void* src, unsigned int size);

struct FUN_005f5630_shell
{
    void __thiscall CopyFromChallenge(TESForm* apCopy);
};

// Copies the TESChallenge data block and both forms from apCopy into this challenge, then calls FUN_004851b0 with apCopy.
// @fnv 0x005f5630
void __thiscall FUN_005f5630_shell::CopyFromChallenge(TESForm* apCopy)
{
    TESChallenge* challenge = dynamic_cast<TESChallenge*>(apCopy);
    if (!challenge)
        return;
    memcpy(&((TESChallenge*)this)->data, &challenge->data, sizeof(ChallengeData));
    ((TESChallenge*)this)->SetFormOne(challenge->GetFormOne());
    ((TESChallenge*)this)->SetFormTwo(challenge->GetFormTwo());
    ((FUN_005e78f0_t*)((TESChallenge*)this))->FUN_004851b0(apCopy);
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, int, int);
};
struct FUN_00484d60_holder
{
    void __thiscall SaveIfChanged(BGSSaveFormBuffer*);
};
struct FUN_005f5780_holder
{
    void __thiscall AppendSaveLoadFormBuffer(BGSSaveFormBuffer*);
};
// Calls the base save routine, then writes the 4-byte values at offsets 0x6C and 0x70 into the save buffer.
// @fnv 0x005f5780
void __thiscall FUN_005f5780_holder::AppendSaveLoadFormBuffer(BGSSaveFormBuffer* apBuffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged(apBuffer);
    apBuffer->SaveData((char*)this + 0x6C, 4, 0);
    apBuffer->SaveData((char*)this + 0x70, 4, 0);
}

struct BSIntToType1
{
    char c;
};
struct BSIntToType10
{
    char c;
};
struct BSIntToType2
{
    char c;
};
struct BSIntToType4
{
    char c;
};
struct BSIntToType8
{
    char c;
};
struct BSIntToType16
{
    char c;
};
struct BSIntToType32
{
    char c;
};
void __cdecl BSEndian(unsigned char*, BSIntToType1);
void __cdecl BSEndian(unsigned char*, BSIntToType10);
void __cdecl BSEndian(unsigned char*, BSIntToType2);
void __cdecl BSEndian(unsigned char*, BSIntToType4);
void __cdecl BSEndian(unsigned char*, BSIntToType8);
void __cdecl BSEndian(unsigned char*, BSIntToType16);
void __cdecl BSEndian(unsigned char*, BSIntToType32);

struct FUN_005f5480_shell
{
    void __thiscall SwapEndianFields();
};

// Byte-swaps the fields at offsets 0, 4, 8, 12, 16, 18 and 20 of this object to the opposite endianness.
// @fnv 0x005f5480
void __thiscall FUN_005f5480_shell::SwapEndianFields()
{
    BSEndian((unsigned char*)this, BSIntToType1());
    BSEndian((unsigned char*)this + 4, BSIntToType10());
    BSEndian((unsigned char*)this + 8, BSIntToType2());
    BSEndian((unsigned char*)this + 12, BSIntToType4());
    BSEndian((unsigned char*)this + 16, BSIntToType8());
    BSEndian((unsigned char*)this + 18, BSIntToType16());
    BSEndian((unsigned char*)this + 20, BSIntToType32());
}

class B5F4F10Form
{
  public:
    virtual ~B5F4F10Form();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class B5F4F10FullName
{
  public:
    virtual void Init();
    ~B5F4F10FullName();

    const char* m_pcName;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B5F4F10Description
{
  public:
    virtual void Init();

    unsigned int m_uiFileOffset;
};

class B5F4F10ScriptableForm
{
  public:
    virtual void Init();

    void* m_pkScript;
    bool m_bScriptReady;
};

class B5F4F10Icon
{
  public:
    virtual void Init();
    ~B5F4F10Icon();

    const char* m_pcPath;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B5F4F10Container
{
  public:
    virtual void Init();
    ~B5F4F10Container();

    void* m_pkFirst;
    void* m_pkNext;
};

class FUN_005f4f10_cls : public B5F4F10Form,
                         public B5F4F10FullName,
                         public B5F4F10Description,
                         public B5F4F10ScriptableForm,
                         public B5F4F10Icon,
                         public B5F4F10Container
{
  public:
    virtual ~FUN_005f4f10_cls();
    void ClearData();
};

// @fnv 0x005f4f10
FUN_005f4f10_cls::~FUN_005f4f10_cls()
{
    ClearData();
}

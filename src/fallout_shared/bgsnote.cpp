// fallout_shared/bgsnote.cpp: BGSNote, Proxy, BGSNoteStandin, NoteRecord and more (25 functions)

#include "bgsnote_decls.h"
// @fnv 0x005e8240
void BGSNote::ResetFormData()
{
    cType = 0;
    m_pText = 0;
    m_pDialogueSpeaker = 0;
    m_bIsRead = false;
}

// Returns the note's TESDescription when GetNoteType reports 1, otherwise returns null.
// @fnv 0x005e91d0
TESDescription* BGSNote::GetNoteDescription()
{
    if (GetNoteType() == 1)
        return (TESDescription*)m_pText;
    return 0;
}

// @fnv 0x005e8060
BGSNote::BGSNote()
{
    SetFormType(kNote);
    ResetFormData();
}

// If type differs from cType, deletes the current TESDescription or TESTexture, stores the new type, and allocates the matching object.
// @fnv 0x005e8f90
void BGSNote::ChangeNoteType(NOTE_TYPE type)
{
    if (type != cType)
    {
        switch (cType)
        {
        case 1:
            delete (TESDescription*)m_pText;
            m_pText = 0;
            break;
        case 2:
            delete (TESTexture*)m_pText;
            m_pText = 0;
            break;
        }
        cType = (signed char)type;
        switch (cType)
        {
        case 1:
            m_pText = new TESDescription;
            break;
        case 2:
            m_pText = new TESTexture;
            break;
        }
    }
}

// @fnv 0x005e8900
void BGSNote::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<TESQuest*>* current = &ownerQuests;
    BSSimpleList<TESQuest*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        BGSNoteReference<TESQuest> noteRef;
        noteRef.id = (unsigned int)current->GetItem();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESQuest*>(GetFormByID(noteRef.id));
        if (noteRef.form)
        {
            current->SetItem(noteRef.form);
            previous = current;
            current = current->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Unable to find owner quest (%08X) for Note '%s' (%08X).", noteRef.id, GetEditorID(),
                    GetFormID());
            if (previous)
            {
                previous->Remove(current->GetItem());
                current = previous->GetNext();
            }
            else
                current->RemoveHead();
        }
    }
    if (GetNoteSound())
    {
        BGSNoteReference<TESSound> noteRef;
        noteRef.id = (unsigned int)GetNoteSound();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESSound*>(GetFormByID(noteRef.id));
        SetNoteSound(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find sound (%08X) for Note '%s' (%08X).", noteRef.id, GetEditorID(),
                    GetFormID());
    }
    if (GetNoteTopic())
    {
        BGSNoteReference<TESTopic> noteRef;
        noteRef.id = (unsigned int)GetNoteTopic();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESTopic*>(GetFormByID(noteRef.id));
        SetNoteTopic(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find topic (%08X) for Note '%s' (%08X).", noteRef.id, GetEditorID(),
                    GetFormID());
    }
    if (GetNoteSpeaker())
    {
        BGSNoteReference<TESActorBase> noteRef;
        noteRef.id = (unsigned int)GetNoteSpeaker();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESActorBase*>(GetFormByID(noteRef.id));
        SetNoteSpeaker(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find actor base (%08X) for Note '%s' (%08X).", noteRef.id, GetEditorID(),
                    GetFormID());
    }
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Reads a NOTE record's chunks from the file, dispatching editor ID, bounds, full name, model, texture, sounds, type, owner quests and type-specific chunks.
// @fnv 0x005e84e0
bool BGSNote::Load(TESFile* file)
{
    if (file->GetTESForm() != kNote)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPickupSound((TESSound*)id);
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPutdownSound((TESSound*)id);
            break;
        }
        case 0x41544144: {
            unsigned char type = 0;
            file->GetChunkData(&type, 1);
            ChangeNoteType((NOTE_TYPE)type);
            break;
        }
        case 0x4d414e4f: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            ownerQuests.AddHead((TESQuest*)id);
            break;
        }
        case 0x4d414e58: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* name = (char*)_alloca(size);
                file->GetChunkData(name, size);
                if (GetNoteTexture())
                    GetNoteTexture()->AssignTextureName(name);
            }
            break;
        }
        default:
            switch (cType)
            {
            case 0:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteSound((TESSound*)id);
                }
                break;
            case 1:
                if (chunk == 0x4d414e54)
                {
                    TESDescription* description = GetNoteDescription();
                    if (description)
                        TESDescription::ReadDescriptionFromFile(description, file);
                }
                break;
            case 2:
                if (IsChunkTypeIcon(chunk))
                {
                    TESTexture* texture = GetNoteTexture();
                    if (texture)
                        TESTexture::ReadTextureData(texture, file);
                }
                break;
            case 3:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteSpeaker((TESActorBase*)id);
                }
                else if (chunk == 0x4d414e54)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteTopic((TESTopic*)id);
                }
                break;
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_005e8d40_shell : public BGSNote
{
    int GetNoteType();
};

// @fnv 0x005e8d40
int FUN_005e8d40_shell::GetNoteType()
{
    return cType;
}

// Returns the note's sound if its type is NoteSound, otherwise returns null.
// @fnv 0x005e9100
TESSound* BGSNote::GetNoteSound()
{
    if (GetNoteType() == NoteSound)
        return (TESSound*)m_pText;
    return 0;
}

// Returns the note texture if the note type is NoteTexture, otherwise returns null.
// @fnv 0x005e9160
TESTexture* BGSNote::GetNoteTexture()
{
    if (GetNoteType() == NoteTexture)
        return (TESTexture*)m_pText;
    return 0;
}

// Returns the stored topic when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e9240
TESTopic* BGSNote::GetNoteTopic()
{
    if (GetNoteType() == 3)
        return (TESTopic*)m_pText;
    return 0;
}

struct FUN_005e9270_shell : public BGSNote
{
    void FUN_005e9270(TESTopic*);
};

// @fnv 0x005e9270
void FUN_005e9270_shell::FUN_005e9270(TESTopic* apTopic)
{
    if (GetNoteType() == 3)
        m_pText = apTopic;
}

// Returns the stored TESActorBase pointer when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e92a0
TESActorBase* BGSNote::GetNoteSpeaker()
{
    if (GetNoteType() == 3)
        return (TESActorBase*)m_pDialogueSpeaker;
    return 0;
}

struct FUN_005e92d0_shell : public BGSNote
{
    void FUN_005e92d0(TESActorBase*);
};

// If GetNoteType() returns 3, stores apSpeaker into a field.
// @fnv 0x005e92d0
void FUN_005e92d0_shell::FUN_005e92d0(TESActorBase* apSpeaker)
{
    if (GetNoteType() == 3)
        m_pDialogueSpeaker = apSpeaker;
}

struct FUN_005e9130_shell : BGSNote
{
    void FUN_005e9130(int a1);
};

// If GetNoteType returns 0, stores a1 at offset 0x6c of this object.
// @fnv 0x005e9130
void FUN_005e9130_shell::FUN_005e9130(int a1)
{
    if (GetNoteType() == 0)
        *(int*)((char*)this + 0x6c) = a1;
}

void _Deallocate(void*);
struct Proxy
{
    void FUN_005e8170();
    void* Release(unsigned int);
};
// Calls FUN_005e8170, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x005e8140
void* Proxy::Release(unsigned int flags)
{
    this->FUN_005e8170();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Fake9190
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2(int)
    {}
};
struct FUN_005e9190_shell : BGSNote
{
    void SetNoteImage(int);
};
// @fnv 0x005e9190
void FUN_005e9190_shell::SetNoteImage(int a)
{
    if (GetNoteType() == 2)
        ((Fake9190*)m_pText)->f2(a);
}

struct Helper005e9200
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*);
};
struct FUN_005e9200_shell : BGSNote
{
    void FUN_005e9200(void*);
};
// @fnv 0x005e9200
void FUN_005e9200_shell::FUN_005e9200(void* apArg)
{
    if (GetNoteType() == 1)
        ((Helper005e9200*)m_pText)->f2(apArg);
}

struct FormChangeMask
{
    unsigned int m_flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct TESFormBufferAccess
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct BGSNoteStandin : TESForm
{
    void FUN_005e9480(BGSLoadFormBuffer*);
};
// @fnv 0x005e9480
void BGSNoteStandin::FUN_005e9480(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((TESFormBufferAccess*)this)->LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000))
        *(unsigned char*)((char*)this + 0x7d) = 1;
}

namespace fnv_005e94d0 {
struct FormChangeMask
{
    int data;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int);
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int);
};
struct FUN_005e94d0_shell : TESForm
{
    void Revert(BGSLoadFormBuffer*);
};
// @fnv 0x005e94d0
void FUN_005e94d0_shell::Revert(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0(reinterpret_cast<unsigned int>(apLoadGameBuffer));
    if (apLoadGameBuffer->GetOldChangeFlags(0x80000000))
        *(char*)((char*)this + 0x7d) = 0;
}
}  // namespace fnv_005e94d0

struct FUN_005e9300_Host
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int);
    virtual void v19(unsigned int);
    char _pad[0x79];
    bool mRead;
    void SetRead(bool abRead);
};
// @fnv 0x005e9300
void FUN_005e9300_Host::SetRead(bool abRead)
{
    if (mRead == abRead)
        return;
    mRead = abRead;
    if (mRead)
        v18(0x80000000);
    else
        v19(0x80000000);
}

struct FUN_005e8170 : public TESBoundObject,
                      public TESModel,
                      public TESFullName,
                      public TESIcon,
                      public BGSPickupPutdownSounds
{
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    char padding7e[2];
    void ClearNoteData();
    virtual ~FUN_005e8170();
};

// Destructor that calls ClearNoteData to release the note's data.
// @fnv 0x005e8170
FUN_005e8170::~FUN_005e8170()
{
    ClearNoteData();
}

struct NoteQuestList
{
    unsigned int head;
    unsigned int tail;
    void __thiscall FUN_00470470();
};
struct NoteRecord
{
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
    TESDescription* noteData;
    void* speaker;
    NoteQuestList ownerQuests;
    unsigned char noteType;
    unsigned char wasRead;
    void __thiscall Destroy();
};
// @fnv 0x005e8270
void NoteRecord::Destroy()
{
    ownerQuests.FUN_00470470();
    switch (noteType)
    {
    case 1:
        delete noteData;
        noteData = 0;
        break;
    case 2:
        delete reinterpret_cast<TESTexture*>(noteData);
        noteData = 0;
        break;
    }
}

struct SaveForm
{
    unsigned int SerializeFormData();
};
struct SaveTexture : TESTexture
{
    unsigned int GetNameLength();
    const char* GetName();
};
struct SaveFullName : TESFullName
{
    void SaveFullNameChunk();
};
struct SaveModel : TESModel
{
    void SaveModelChunk(unsigned int, unsigned int);
};
struct SaveIcon : TESIcon
{
    void SaveIconChunk(unsigned int);
};
struct SavePickup : BGSPickupPutdownSounds
{
    void SavePickupChunk();
};
struct SaveQuestList
{
    bool IsListEmpty();
    TESQuest*& GetListItem();
    SaveQuestList* GetListNext();
};

void SaveByteChunk(unsigned int, unsigned char);
void SaveIntChunk(unsigned int, unsigned int);
void SaveDataChunk(unsigned int, const void*, unsigned int);
void SaveDescriptionChunk(void*, unsigned int);

struct BGSNoteSave : TESBoundObject, SaveModel, SaveFullName, SaveIcon, SavePickup
{
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    TESTexture* GetNoteTexture();
    TESSound* GetNoteSound();
    TESTopic* GetNoteTopic();
    TESActorBase* GetNoteSpeaker();
    void StartSave();
    void EndSave();
    SaveQuestList* GetOwnerQuests();
    void* GetNoteTextData();
    void SaveNote();
};

// @fnv 0x005e8300
void BGSNoteSave::SaveNote()
{
    StartSave();
    SaveFullNameChunk();
    SaveModelChunk(0x4c444f4d, 0x54444f4d);
    SaveIconChunk(0x4e4f4349);
    SavePickupChunk();
    SaveByteChunk(0x41544144, cType);
    SaveQuestList* pNode = GetOwnerQuests();
    while (pNode && !pNode->IsListEmpty())
    {
        TESQuest* pOwner = pNode->GetListItem();
        unsigned int uiOwnerQuestID = ((SaveForm*)pOwner)->SerializeFormData();
        SaveIntChunk(0x4d414e4f, uiOwnerQuestID);
        pNode = pNode->GetListNext();
    }
    switch (cType)
    {
    case 0: {
        TESSound* SoundAssetTmp = GetNoteSound();
        if (SoundAssetTmp)
        {
            unsigned int uiSoundID = ((SaveForm*)SoundAssetTmp)->SerializeFormData();
            SaveIntChunk(0x4d414e53, uiSoundID);
        }
        break;
    }
    case 1: {
        void* pText = GetNoteTextData();
        if (pText)
            SaveDescriptionChunk(pText, 0x4d414e54);
        break;
    }
    case 2: {
        SaveTexture* pNoteTexture = (SaveTexture*)GetNoteTexture();
        if (pNoteTexture)
            SaveDataChunk(0x4d414e58, pNoteTexture->GetName(), pNoteTexture->GetNameLength() + 1);
        break;
    }
    case 3: {
        TESTopic* pTopic = GetNoteTopic();
        if (pTopic)
        {
            unsigned int uiTopicFormID = ((SaveForm*)pTopic)->SerializeFormData();
            SaveIntChunk(0x4d414e54, uiTopicFormID);
        }
        TESActorBase* m_pDialogueSpeaker = GetNoteSpeaker();
        if (m_pDialogueSpeaker)
        {
            unsigned int uiSpeakerFormID = ((SaveForm*)m_pDialogueSpeaker)->SerializeFormData();
            SaveIntChunk(0x4d414e53, uiSpeakerFormID);
        }
        break;
    }
    }
    EndSave();
}

namespace fnv_005e8c00 {
struct NoteQuestList
{
    void RemoveAll();
};

class BGSNoteCopy : public BGSNote
{
  public:
    void CopyGenericComponents(TESForm* apForm);
    void SetNoteFlags(int aiFlags);
    void SetNoteSpeaker(TESActorBase* apSpeaker);
    void SetNoteSound(TESSound* apSound);
    TESDescription* FUN_005e91d0();
    void SetNoteText(TESDescription* apText);
    void SetNoteTexture(TESTexture* apTexture);
    void SetNoteTopic(TESTopic* apTopic);
    BSSimpleList<TESQuest*>* GetOwnerQuests();

    void CopyFromNote(TESForm* apForm);
};

// Copies generic components, flags, speaker, type-specific data and owner quests from another BGSNote into this one.
// @fnv 0x005e8c00
void BGSNoteCopy::CopyFromNote(TESForm* apForm)
{
    BGSNoteCopy* pSource = (BGSNoteCopy*)dynamic_cast<BGSNote*>(apForm);
    if (!pSource)
        return;

    CopyGenericComponents(apForm);
    BSSimpleList<TESQuest*>* pIter = 0;
    SetNoteFlags(pSource->GetNoteType());
    SetNoteSpeaker(pSource->GetNoteSpeaker());
    switch (cType)
    {
    case 0:
        SetNoteSound(pSource->GetNoteSound());
        break;
    case 1:
        SetNoteText(pSource->FUN_005e91d0());
        break;
    case 2:
        SetNoteTexture(pSource->GetNoteTexture());
        break;
    case 3:
        SetNoteTopic(pSource->GetNoteTopic());
        break;
    }

    ((NoteQuestList*)&ownerQuests)->RemoveAll();
    pIter = pSource->GetOwnerQuests();
    while (pIter && !pIter->IsEmpty())
    {
        ownerQuests.AddHead(pIter->GetItem());
        pIter = pIter->GetNext();
    }
    m_bIsRead = pSource->m_bIsRead;
}
}  // namespace fnv_005e8c00

namespace fnv_005e8d60 {
struct NoteCompareData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool IsDifferent(NoteCompareData* apOther);
};

struct NoteQuestList
{
    TESQuest* pItem;
    NoteQuestList* pNext;

    int GetSize();
    bool IsEmpty();
    TESQuest*& GetItem();
    bool IsInList(TESQuest*& arItem);
    NoteQuestList* GetNext();
};

struct NoteCompare : BGSNote
{
    bool CompareBase(BGSNote* apOther);
    NoteQuestList* GetOwnerQuests();
    NoteCompareData* FUN_005e91d0();
    NoteCompareData* GetNoteTexture();
    bool Compare(TESForm* apForm);
};

// Compares this note against apForm by base data, type-specific data and owner quest lists, returning true when they differ.
// @fnv 0x005e8d60
bool NoteCompare::Compare(TESForm* apForm)
{
    BGSNote* pNote = dynamic_cast<BGSNote*>(apForm);
    if (!pNote)
        return true;
    if (CompareBase(pNote))
        return true;
    if (pNote->cType != cType)
        return true;

    switch (cType)
    {
    case 0:
        if (GetNoteSound() != pNote->GetNoteSound())
            return true;
        break;
    case 1: {
        NoteCompareData* pMine = FUN_005e91d0();
        NoteCompareData* pTheirs = ((NoteCompare*)pNote)->FUN_005e91d0();
        if (pMine && pTheirs)
        {
            if (pMine->IsDifferent(pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 2: {
        NoteCompareData* pMine = GetNoteTexture();
        NoteCompareData* pTheirs = ((NoteCompare*)pNote)->GetNoteTexture();
        if (pMine && pTheirs)
        {
            if (pMine->IsDifferent(pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 3:
        if (GetNoteTopic() != pNote->GetNoteTopic())
            return true;
        if (GetNoteSpeaker() != pNote->GetNoteSpeaker())
            return true;
        break;
    }

    if (GetOwnerQuests()->GetSize() != ((NoteCompare*)pNote)->GetOwnerQuests()->GetSize())
        return true;

    NoteQuestList* pNode = GetOwnerQuests();
    while (pNode && !pNode->IsEmpty())
    {
        TESQuest* pQuest = pNode->GetItem();
        if (!((NoteCompare*)pNote)->GetOwnerQuests()->IsInList(pQuest))
            return true;
        pNode = pNode->GetNext();
    }
    return false;
}
}  // namespace fnv_005e8d60

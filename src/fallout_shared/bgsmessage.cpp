// fallout_shared/bgsmessage.cpp: BGSMessage, MessageCopyAccess, MessageCompare (16 functions)

#include "bgsmessage_match_decls.h"
#include "BGSMessage.h"
#include "PerkButtonEntry.h"

class BGSMenuIcon : public TESForm
{
};

struct BGSMessageInitItemLocals
{
    PerkButtonEntry* button;
    int conditionErrors;
    int warningState;
    BSSimpleList<PerkButtonEntry*>* buttonList;
    unsigned int buttonIndex;
    unsigned int iconFormID;
};

// @fnv 0x00590530
BGSMessage::BGSMessage()
{
    SetFormType(ENUM_FORM_ID_MESG_ID);
    ResetFormData();
}

// @fnv 0x005906a0
void BGSMessage::ResetFormData()
{
    pIcon = 0;
    iFlags = 1;
    m_uiDisplayDuration = 2;
}

// @fnv 0x005906d0
void BGSMessage::ClearData()
{
    SetIcon(0);
    ClearButtons();
}

// @fnv 0x005906f0
void BGSMessage::InitItem()
{
    if (IsFormInitialized())
    {
        return;
    }

    BGSMessageInitItemLocals locals;
    locals.iconFormID = reinterpret_cast<BGSMessageInitAccess*>(this)->GetIconFormID();
    if (locals.iconFormID)
    {
        TESForm::RemapFormIDForFile(locals.iconFormID, GetFile(-1));
        SetIcon(dynamic_cast<BGSMenuIcon*>(TESForm::GetFormByID(locals.iconFormID)));

        if (!reinterpret_cast<BGSMessageInitAccess*>(this)->GetIconFormID())
        {
            Warning("MASTERFILE: Could not find icon (%08X) on weapon '%s' (%08X).", locals.iconFormID, GetName(),
                    GetFormID());
        }
    }

    locals.buttonList =
        reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList());
    locals.buttonIndex = 0;
    while (locals.buttonList && !locals.buttonList->IsEmpty())
    {
        locals.button = locals.buttonList->GetItem();
        locals.buttonList = locals.buttonList->GetNext();
        locals.button->Conditions.InitItem(this);
        locals.warningState = Warning();
        SetWarningState(reinterpret_cast<NiTexture*>(1));
        BGSMessageWarningAuxiliary(0);
        SetWarningState(0);
        locals.conditionErrors = Warning();
        BGSMessageWarningAuxiliary(locals.warningState);
        if (locals.conditionErrors)
        {
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for conditions on menu item %d for terminal '%s' (%08X)",
                locals.buttonIndex, GetName(), GetFormID());
        }
        ++locals.buttonIndex;
    }

    SetInitializationState(true);
}

struct BGSMessageLoadLocals
{
    char* buttonText;
    PerkButtonEntry* newButton;
    char* editorIDText;
    unsigned int iconFormID;
    int chunkID;
    PerkButtonEntry* currentButton;
    unsigned int unused;
};

// @fnv 0x00590880
bool BGSMessage::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    LoadRecordHeader(file);
    SetInitializationState(false);

    BGSMessageLoadLocals locals;
    locals.currentButton = 0;
    locals.unused = 0;
    while ((locals.chunkID = file->GetChunkID()) != 0)
    {
        switch (locals.chunkID)
        {
        case 0x44494445: {
            locals.editorIDText = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(locals.editorIDText, 0x200);
            SetEditorID_AtRuntime(locals.editorIDText);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(static_cast<TESDescription*>(this), file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(static_cast<TESFullName*>(this), file);
            break;
        case 0x4d414e49: {
            file->GetChunkData(&locals.iconFormID);
            SetIcon(reinterpret_cast<BGSMenuIcon*>(locals.iconFormID));
            break;
        }
        case 0x4d414e44:
            file->GetChunkData(&iFlags);
            break;
        case 0x4d414e54:
            file->GetChunkData(&m_uiDisplayDuration);
            break;
        case 0x54585449: {
            locals.buttonText = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(locals.buttonText, 0);
            locals.newButton = new PerkButtonEntry;
            locals.newButton->cButtonText.Set(locals.buttonText, 0);
            reinterpret_cast<BGSMessageLoadAccess*>(this)->AddButton(locals.newButton);
            locals.currentButton = locals.newButton;
            break;
        }
        case 0x41445443:
            if (locals.currentButton)
            {
                locals.currentButton->Conditions.Load(file);
            }
            break;
        default:
            break;
        }

        if (!file->NextChunk())
        {
            break;
        }
    }

    return true;
}

// Removes every item from the button list, deleting each button until the list is empty.
// @fnv 0x005910d0
void BGSMessage::ClearButtons()
{
    while (!m_kButtonEntries.IsEmpty())
    {
        PerkButtonEntry* button = m_kButtonEntries.GetItem();
        m_kButtonEntries.RemoveHead();
        delete button;
    }
}

struct FUN_00590d00_shell : public BGSMessage
{
    bool GetIsMessageBox();
};

// @fnv 0x00590d00
bool FUN_00590d00_shell::GetIsMessageBox()
{
    return (*(unsigned int*)((char*)this + 0x38) & 1) ? true : false;
}

struct FUN_00590ed0_shell : public BGSMessage
{
    bool IsFlagSet();
};

// @fnv 0x00590ed0
bool FUN_00590ed0_shell::IsFlagSet()
{
    return (*(unsigned int*)((char*)this + 0x38) & 2) ? true : false;
}

struct FUN_005911d0_shell : public BGSMessage
{
    void FUN_005911d0(PerkButtonEntry*);
};

// If apItem is non-null, appends it to the BSSimpleList at offset 0x30 of this object.
// @fnv 0x005911d0
void FUN_005911d0_shell::FUN_005911d0(PerkButtonEntry* apItem)
{
    if (apItem != 0)
    {
        reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<char*>(this) + 0x30)->AddTail(apItem);
    }
}

struct FUN_00590e80_shell
{
    int data[0x38 / 4 + 1];
    void SetEnabled(bool enabled);
};

// Sets or clears bit 0 of the flag word at offset 0x38 according to enabled.
// @fnv 0x00590e80
void FUN_00590e80_shell::SetEnabled(bool enabled)
{
    enabled ? data[0x38 / 4] |= 1 : data[0x38 / 4] &= ~1;
}

void __cdecl _Deallocate(void*);
struct X905e0
{
    void FUN_00590610();
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x005905e0
void* X905e0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00590610();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00590ef0_shell
{
    int pad[14];
    int val38;
    void FUN_00590ef0(bool);
};
// @fnv 0x00590ef0
void FUN_00590ef0_shell::FUN_00590ef0(bool enabled)
{
    enabled ? val38 |= 2 : val38 &= ~2;
}

class B590610File;
class B590610MenuIcon;
class B590610Button;

template <class T> class B590610SimpleList
{
  public:
    ~B590610SimpleList();

    T m_item;
    B590610SimpleList* m_pkNext;
};

class B590610Form
{
  public:
    virtual ~B590610Form();
    virtual void ClearData();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    B590610File* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class B590610FullName
{
  public:
    virtual void Init();
    ~B590610FullName();

    const char* m_pcName;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B590610Description
{
  public:
    virtual void Init();

    unsigned int m_uiFileOffset;
};

class FUN_00590610_Message : public B590610Form, public B590610FullName, public B590610Description
{
  public:
    virtual ~FUN_00590610_Message();
    virtual void ClearData();

    B590610MenuIcon* m_pkIcon;
    B590610SimpleList<B590610Button*> m_kButtonList;
    unsigned int m_uiValue1;
    unsigned int m_uiDisplayTime;
};

// @fnv 0x00590610
FUN_00590610_Message::~FUN_00590610_Message()
{
    ClearData();
}

struct MessageCopyAccess : public BGSMessage
{
    BGSMenuIcon* GetIcon();
    bool GetAutoDisplay();
    void SetAutoDisplay(bool value);
    bool GetMessageBoxFlag();
    void SetMessageBoxFlag(bool value);
    TESForm* GetQuest();
    void SetQuest(TESForm* quest);
    BSSimpleList<PerkButtonEntry*>* GetButtonList();
    void AddButton(PerkButtonEntry* button);
    void CopyBase(TESForm* form);
    void CopyFromMessage(TESForm* form);
};

struct ButtonTextAccess
{
    BSStringT<char>& Assign(const BSStringT<char>& other);
};

struct ConditionCopyAccess
{
    void CopyFrom(PerkEntryConditionSet* other, bool flag);
};

// Clears the message data, copies icon, auto-display, message-box flag, quest and button list from form, then copies the base form.
// @fnv 0x00590d20
void MessageCopyAccess::CopyFromMessage(TESForm* form)
{
    BSSimpleList<PerkButtonEntry*>* node;
    ClearData();
    MessageCopyAccess* src = (MessageCopyAccess*)form;
    SetIcon(((MessageCopyAccess*)form)->GetIcon());
    SetAutoDisplay(src->GetAutoDisplay());
    SetMessageBoxFlag(src->GetMessageBoxFlag());
    SetQuest(src->GetQuest());
    node = src->GetButtonList();
    while (node && !node->IsEmpty())
    {
        PerkButtonEntry* item = node->GetItem();
        node = node->GetNext();
        PerkButtonEntry* button = new PerkButtonEntry;
        ((ButtonTextAccess*)&button->cButtonText)->Assign(item->cButtonText);
        ((ConditionCopyAccess*)&button->Conditions)->CopyFrom(&item->Conditions, false);
        AddButton(button);
    }
    CopyBase(form);
}

struct Component0bc0
{
    int unk00, unk04, unk08;
    void FUN_00487010();
};
struct Description0bc0
{
    int unk00, unk04;
    void FUN_00482cb0();
};
struct Icon0bc0
{
    unsigned int FUN_0084e3a0();
};
struct String0bc0
{
    int unk00, unk04;
    const char* FUN_00559450();
};
struct Conditions0bc0
{
    void ProcessItems();
};
struct Button0bc0
{
    String0bc0 text;
    Conditions0bc0 conditions;
};
struct List0bc0
{
    bool FUN_008256d0();
    Button0bc0*& FUN_006815c0();
    List0bc0* FUN_00726070();
};
void __cdecl FUN_00485910(unsigned int, unsigned int);
int __cdecl FUN_0044a670(const char*);
void __cdecl FUN_004856f0(unsigned int, const char*, unsigned int);
struct Target0bc0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Component0bc0 fullName;
    Description0bc0 description;
    Icon0bc0* icon;
    int unk30, unk34;
    unsigned int flags, time;
    void FUN_004855a0();
    Icon0bc0* FUN_0055b980();
    bool GetIsMessageBox();
    List0bc0* FUN_00436aa0();
    void FUN_00485680();
    void WriteToStream();
};
// @fnv 0x00590bc0
void Target0bc0::WriteToStream()
{
    FUN_004855a0();
    description.FUN_00482cb0();
    fullName.FUN_00487010();
    unsigned int id = FUN_0055b980() ? FUN_0055b980()->FUN_0084e3a0() : 0;
    FUN_00485910(0x4d414e49, id);
    FUN_00485910(0x4d414e44, flags);
    if (!GetIsMessageBox())
        FUN_00485910(0x4d414e54, time);
    List0bc0* node = FUN_00436aa0();
    while (node && !node->FUN_008256d0())
    {
        Button0bc0* button = node->FUN_006815c0();
        node = node->FUN_00726070();
        if (button->text.FUN_00559450())
            FUN_004856f0(0x54585449, button->text.FUN_00559450(), FUN_0044a670(button->text.FUN_00559450()) + 1);
        else
            FUN_00485910(0x54585449, 0);
        button->conditions.ProcessItems();
    }
    FUN_00485680();
}

struct ButtonConditionView
{
    bool FUN_00680b70(ButtonConditionView*);
};
struct ButtonView
{
    int text00, text04;
    ButtonConditionView conditions;
    bool FUN_00501c30(ButtonView*);
};
struct ButtonListView
{
    int FUN_005ae380();
    bool FUN_008256d0();
    ButtonView** FUN_006815c0();
    ButtonListView* FUN_00726070();
};
struct MessageCompare : BGSMessage
{
    unsigned int FUN_0055b980();
    bool GetIsMessageBox();
    bool IsFlagSet();
    unsigned int FUN_00639b40();
    ButtonListView* FUN_00436aa0();
    bool FUN_00485270(TESForm*);
    bool IsNotEqual(TESForm*);
};
// @fnv 0x00590f40
bool MessageCompare::IsNotEqual(TESForm* form)
{
    MessageCompare* right = static_cast<MessageCompare*>(form);
    if (!right)
        return true;
    if (FUN_0055b980() != right->FUN_0055b980())
        return true;
    if (GetIsMessageBox() != right->GetIsMessageBox())
        return true;
    if (IsFlagSet() != right->IsFlagSet())
        return true;
    if (FUN_00639b40() != right->FUN_00639b40())
        return true;
    ButtonListView* left = FUN_00436aa0();
    ButtonListView* other = right->FUN_00436aa0();
    if (left->FUN_005ae380() != other->FUN_005ae380())
        return true;
    while (other && !other->FUN_008256d0() && left && !left->FUN_008256d0())
    {
        ButtonView* rhs = *other->FUN_006815c0();
        ButtonView* lhs = *left->FUN_006815c0();
        if (lhs->FUN_00501c30(rhs))
            return true;
        if (lhs->conditions.FUN_00680b70(&rhs->conditions))
            return true;
        other = other->FUN_00726070();
        left = left->FUN_00726070();
    }
    if (FUN_00485270(form))
        return true;
    return false;
}

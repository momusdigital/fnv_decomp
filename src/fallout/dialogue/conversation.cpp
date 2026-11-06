// fallout/dialogue/conversation.cpp: ConversationLoad, DialogueItem, ListNode, Conversation and more (11 functions)

#include "conversation_decls.h"

// @fnv 0x0083c7b0
bool DialogueItem::SelectDefaultResponseList()
{
    m_pCurrentResponseList = &m_kResponseList;
    return m_pCurrentResponseList->GetItem() != 0;
}

struct ListItem
{
    void FUN_0083cdf0();
};
struct ListNode
{
    bool _ref_008256d0() const;
    ListItem** _ref_006815c0() const;
    ListNode* _ref_00726070() const;
    void FUN_0083c220();
};
// Walks the list from this node, calling FUN_0083cdf0 on each node's item until a node satisfies _ref_008256d0 or the list ends.
// @fnv 0x0083c220
void ListNode::FUN_0083c220()
{
    ListNode* current = this;
    while (current && !current->_ref_008256d0())
    {
        ListItem* item = *current->_ref_006815c0();
        item->FUN_0083cdf0();
        current = current->_ref_00726070();
    }
}

struct Conversation
{
    BSSimpleList<DialogueItem*> m_kDialogueItems;
    void FUN_0083c420(BGSLoadFormBuffer*);
};
struct DialogueItem_Stub
{
    void RefreshObjectRef(BGSLoadFormBuffer*);
};
// Iterates the dialogue item list and calls each item's load function with the buffer.
// @fnv 0x0083c420
void Conversation::FUN_0083c420(BGSLoadFormBuffer* pBuffer)
{
    BSSimpleList<DialogueItem*>* pCurrentElementNext = reinterpret_cast<BSSimpleList<DialogueItem*>*>(this);
    while (pCurrentElementNext)
    {
        DialogueItem* pdialogueItem = pCurrentElementNext->GetItem();
        if (pdialogueItem)
        {
            reinterpret_cast<DialogueItem_Stub*>(pdialogueItem)->RefreshObjectRef(pBuffer);
        }
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
}

void __cdecl _FNV_Warning(const char*);

struct Conversation_Stub
{
    short FUN_0083ba50(DialogueItem* item);
};

// Walks the dialogue item list looking for item and returns its index, warning and returning 0 if not found.
// @fnv 0x0083ba50
short Conversation_Stub::FUN_0083ba50(DialogueItem* item)
{
    short index = 0;
    ListNode* node = (ListNode*)this;
    while (node && !node->_ref_008256d0())
    {
        if (item == (DialogueItem*)node->_ref_006815c0()[0])
            return index;
        ++index;
        node = node->_ref_00726070();
    }
    _FNV_Warning(
        "DIALOGUE: When trying to get a dialogue item index, the dialogue item was not found in the dialogue items list.");
    return 0;
}

struct FormRecordMetadata
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags[4];
    unsigned char cVersion;
};
struct TESFormStub
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetFormDisplayName();
};
struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
    bool FUN_00862110();
    unsigned char FUN_008df040();
};
struct EffectSetting
{
    FormRecordMetadata* GetBoltSound();
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
struct DialogueItemLoad : DialogueItem
{
    void FUN_0083cc10();
};
struct StandIn
{
    void FUN_0083c8a0(void*);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
TESForm* FUN_004839c0(unsigned int);
void FNV_Warning(const char*, ...);
struct ConversationLoad : Conversation
{
    void* m_pConversationLoadContext;
    void* GetDialogueItemByIndex(unsigned short);
    void LoadFromSave();
};

// Reads a save block header and dialogue item count, creates and appends DialogueItem objects, sets the current item, and warns on buffer overrun or underrun.
// @fnv 0x0083bec0
void ConversationLoad::LoadFromSave()
{
    unsigned short usBlockSize = 0;
    unsigned int uiStartBufferPosition = 0;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int uiBlockHeader;
        g_TESSaveLoadGame->ReadTypedData(&uiBlockHeader, 4);
        if (uiBlockHeader != 0x424c4f4b)
        {
            FormRecordMetadata* pheader = ((EffectSetting*)g_TESSaveLoadGame)->GetBoltSound();
            if (pheader)
            {
                TESForm* pform = FUN_004839c0(pheader->iFormID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xe7,
                    pheader->iFormID, ((TESFormStub*)pform)->GetFormDisplayName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
            }
            else
            {
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xe7,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
        uiStartBufferPosition = ((GameTimerRecord*)g_TESSaveLoadGame)->GetTime();
        g_TESSaveLoadGame->ReadTypedData(&usBlockSize, 2);
    }
    unsigned short icount;
    g_TESSaveLoadGame->ReadTypedData(&icount, 2);
    for (unsigned int i = 0; i < icount; i++)
    {
        DialogueItem* pdialogueItem = new DialogueItem;
        ((DialogueItemLoad*)pdialogueItem)->FUN_0083cc10();
        m_kDialogueItems.AddTail(pdialogueItem);
    }
    short sCurrentItemIndex;
    g_TESSaveLoadGame->ReadTypedData(&sCurrentItemIndex, 2);
    if (sCurrentItemIndex != -1)
        ((StandIn*)this)->FUN_0083c8a0(GetDialogueItemByIndex(sCurrentItemIndex));
    else
        m_pConversationLoadContext = 0;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int uiCurrentBufferPosition = ((GameTimerRecord*)g_TESSaveLoadGame)->GetTime();
        FormRecordMetadata* pheader = ((EffectSetting*)g_TESSaveLoadGame)->GetBoltSound();
        if (pheader)
        {
            TESForm* pform = FUN_004839c0(pheader->iFormID);
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    uiCurrentBufferPosition - (usBlockSize + uiStartBufferPosition),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    pheader->iFormID, ((TESFormStub*)pform)->GetFormDisplayName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    usBlockSize + uiStartBufferPosition - uiCurrentBufferPosition,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    pheader->iFormID, ((TESFormStub*)pform)->GetFormDisplayName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
        }
        else
        {
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    uiCurrentBufferPosition - (usBlockSize + uiStartBufferPosition),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    g_TESSaveLoadGame->FUN_008df040());
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    usBlockSize + uiStartBufferPosition - uiCurrentBufferPosition,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    g_TESSaveLoadGame->FUN_008df040());
        }
    }
}

struct DialogueItemListRef
{
    bool _ref_008256d0() const;
};

// Walks the dialogue item list until the entry at aiIndex is found and returns its item, warning and returning 0 if the index is out of range.
// @fnv 0x0083bac0
void* ConversationLoad::GetDialogueItemByIndex(unsigned short aiIndex)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueItem*>* pCurrentElementNext = (BSSimpleList<DialogueItem*>*)this;
    while (pCurrentElementNext && !((DialogueItemListRef*)pCurrentElementNext)->_ref_008256d0())
    {
        if (iElementIndex == (short)aiIndex)
            return pCurrentElementNext->GetItem();
        iElementIndex++;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    FNV_Warning(
        "DIALOGUE: When trying to get a dialogue item by its index, the index was larger than the size of the dialogue items list.");
    return 0;
}

namespace fnv_0083c330 {
struct BGSLoadFormBuffer
{
    int ReadElementCount();
    void ReadTypedData(void* data, unsigned int size);
};

struct DialogueItem_shell
{
    void LoadDialogueItem(BGSLoadFormBuffer* buffer);
};

struct SoundListView
{
    void AddTail(char* const& item);
};

struct FUN_0083c330_shell
{
    void FUN_0083c330(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0083c330
void FUN_0083c330_shell::FUN_0083c330(BGSLoadFormBuffer* buffer)
{
    short count;
    unsigned int currentItem = buffer->ReadElementCount();
    unsigned int index = 0;

    for (; index < currentItem; ++index)
    {
        DialogueItem* item = new DialogueItem;
        reinterpret_cast<DialogueItem_shell*>(item)->LoadDialogueItem(buffer);
        reinterpret_cast<SoundListView*>(this)->AddTail(*reinterpret_cast<char* const*>(&item));
    }

    count = -1;
    buffer->ReadTypedData(&count, 2);

    if (count != -1)
    {
        reinterpret_cast<StandIn*>(this)->FUN_0083c8a0(
            reinterpret_cast<ConversationLoad*>(this)->GetDialogueItemByIndex(static_cast<unsigned short>(count)));
    }
}
}  // namespace fnv_0083c330

class StrList
{
  public:
    StrList();
    ~StrList();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0083b850;

void __cdecl GenerateConversation(void* pvA, void* pvB, FUN_0083b850* pkList, void* pvC);

class FUN_0083b850 : public StrList
{
  public:
    FUN_0083b850(void* pvA, void* pvB, void* pvC);

    int m_iArrayLength;
};

// @fnv 0x0083b850
FUN_0083b850::FUN_0083b850(void* pvA, void* pvB, void* pvC)
{
    m_iArrayLength = 0;
    GenerateConversation(pvA, pvB, this, pvC);
}

struct FormIDEntry
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char cVersion;
};
struct SaveLoadGameStub
{
    bool FUN_00862110();
    FormIDEntry* GetCurrentFormHeader();
};
struct SettingStub
{
    unsigned char* Bool();
};
struct FormStub
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetEditorName();
};
struct DialogueItemSave
{
    unsigned short GetSaveSize();
};
struct DialogueItemNode
{
    bool IsEmpty() const;
    DialogueItemSave** GetItem() const;
    DialogueItemNode* GetNext() const;
};
struct DialogueItemList : DialogueItemNode
{
    unsigned short FUN_0083bb30();
};
extern SaveLoadGameStub* g_SaveLoadGameStub;
extern SettingStub g_011de4e8;
FormStub* LookupFormByID(unsigned int);
void SaveWarning(const char*, ...);
static const char kConversationFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp";
static const char kSaveSizeFormFormat[] =
    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s";
static const char kSaveSizeFormat[] = "GetSaveSize(): %-5i ending at line %i in file %s";

// @fnv 0x0083bb30
unsigned short DialogueItemList::FUN_0083bb30()
{
    unsigned short size3 = 0;
    unsigned short start = size3;
    if (g_SaveLoadGameStub->FUN_00862110())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 2;
    DialogueItemNode* node5 = this;
    while (node5 && !node5->IsEmpty())
    {
        DialogueItemSave* item8 = *node5->GetItem();
        size3 += item8->GetSaveSize();
        node5 = node5->GetNext();
    }
    size3 += 2;
    if (*g_011de4e8.Bool())
    {
        FormIDEntry* header3 = g_SaveLoadGameStub->GetCurrentFormHeader();
        if (header3)
        {
            FormStub* form = LookupFormByID(header3->iFormID);
            SaveWarning(kSaveSizeFormFormat, size3 - start, header3->iFormID, form->GetEditorName(),
                        *(unsigned int*)&header3->iFlags, 192, kConversationFile);
        }
        else
        {
            SaveWarning(kSaveSizeFormat, size3 - start, 192, kConversationFile);
        }
    }
    return size3;
}

class B83C270Buffer
{
  public:
    unsigned int BeginChunk();
    void EndChunk(int iCount, unsigned int uiChunk);
    void SaveData(void* pvData, int iSize, int iFlags);
};

class B83C270Item
{
  public:
    void SaveGame(B83C270Buffer* pkBuffer);
};

class B83C270Node
{
  public:
    B83C270Item** GetItem();
    B83C270Node* GetNext();
};

class B83C270Conversation
{
  public:
    B83C270Node m_kHead;
    int unk04;
    B83C270Node* m_pkCurrent;

    short GetIndex(B83C270Item* pkItem);
    void FUN_0083c270(B83C270Buffer* pkBuffer);
};

// Begins a chunk, saves each non-null item in the node list, ends the chunk, then saves the current node's item index (or -1).
// @fnv 0x0083c270
void B83C270Conversation::FUN_0083c270(B83C270Buffer* pkBuffer)
{
    int iCount7 = 0;
    unsigned int uiChunk = pkBuffer->BeginChunk();
    B83C270Node* pkNode4 = &m_kHead;
    while (pkNode4)
    {
        B83C270Item* pkItem = *pkNode4->GetItem();
        if (pkItem)
        {
            pkItem->SaveGame(pkBuffer);
            iCount7++;
        }
        pkNode4 = pkNode4->GetNext();
    }
    pkBuffer->EndChunk(iCount7, uiChunk);
    short sIndex3 = m_pkCurrent ? GetIndex(*m_pkCurrent->GetItem()) : -1;
    pkBuffer->SaveData(&sIndex3, 2, 0);
}

struct CVItem
{
    void SaveDialogueItem();
};

struct CVNode
{
    void* m_item;
    CVNode* m_pkNext;
    bool IsEmpty() const;
    CVItem** GetItem() const;
    CVNode* GetNext() const;
};

struct CVConv : CVNode
{
    CVNode* m_pConversationLoadContext;
    short FUN_0083ba50(CVItem* item);
    void SaveConversation();
};

struct CVSaveLoad
{
    unsigned int GetTimeStamp();
    bool FUN_00862110();
    void SaveGameDataOLD(void*, int);
    void* GetHitSound();
};

extern "C" CVSaveLoad* g_saveLoad;
extern "C" char DAT_01015318;
extern "C" char DAT_0101536c;
extern "C" char DAT_010153a0;
extern "C" char DAT_0107db20;
void __cdecl FUN_0040fbe0(const char* fmt, ...);
void __cdecl FUN_005b5e40(const char* fmt, const char* file, int line);

// @fnv 0x0083bc80
void CVConv::SaveConversation()
{
    short sCount_ = 0;                                  // slot -0x10
    short* pSizeTmp = 0;                                // slot -0x04
    unsigned int pCount7 = g_saveLoad->GetTimeStamp();  // slot -0x14
    if (*g_011de4e8.Bool())
        pCount7 = g_saveLoad->GetTimeStamp();
    if (g_saveLoad->FUN_00862110())
    {
        unsigned int uiBlok9 = 0x424c4f4b;  // slot -0x20
        g_saveLoad->SaveGameDataOLD(&uiBlok9, 4);
        pSizeTmp = (short*)g_saveLoad->GetTimeStamp();
        g_saveLoad->SaveGameDataOLD(&sCount_, 2);
    }
    short sIndex5 = 0;                                  // slot -0x1c
    short* sVer7 = (short*)g_saveLoad->GetTimeStamp();  // slot -0x0c
    g_saveLoad->SaveGameDataOLD(&sIndex5, 2);
    CVNode* uiStartTime4 = this;  // slot -0x18
    while (uiStartTime4 && !uiStartTime4->IsEmpty())
    {
        CVItem* pItem = *uiStartTime4->GetItem();  // slot -0x24
        pItem->SaveDialogueItem();
        sIndex5++;
        uiStartTime4 = uiStartTime4->GetNext();
    }
    *sVer7 = sIndex5;
    short pNode2 = -1;  // slot -0x08
    if (m_pConversationLoadContext)
        pNode2 = FUN_0083ba50(*m_pConversationLoadContext->GetItem());
    g_saveLoad->SaveGameDataOLD(&pNode2, 2);
    if (*g_011de4e8.Bool())
    {
        unsigned int uiEndTime4 = g_saveLoad->GetTimeStamp();  // slot -0x2c
        void* _pWorld = g_saveLoad->GetHitSound();             // slot -0x28
        if (_pWorld)
        {
            TESFormStub* pForm = (TESFormStub*)FUN_004839c0(*(unsigned int*)_pWorld);  // -0x30
            FUN_0040fbe0(&DAT_010153a0, uiEndTime4 - pCount7, *(unsigned int*)_pWorld, pForm->GetFormDisplayName(),
                         *(unsigned int*)((char*)_pWorld + 5), 0xe1, &DAT_0107db20);
        }
        else
        {
            FUN_0040fbe0(&DAT_0101536c, uiEndTime4 - pCount7, 0xe1, &DAT_0107db20);
        }
    }
    if (g_saveLoad->FUN_00862110())
    {
        unsigned int uiEnd7 = g_saveLoad->GetTimeStamp();  // slot -0x34
        unsigned int uiStart2 = (unsigned int)pSizeTmp;    // slot -0x38
        if (uiEnd7 > uiStart2 + 0xffff)
            FUN_005b5e40(&DAT_01015318, &DAT_0107db20, 0xe1);
        *pSizeTmp = (short)(uiEnd7 - uiStart2);
    }
}

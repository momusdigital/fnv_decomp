// fallout/dialogue/dialogueitem.cpp: DialogueItem, DelStandIn, StandIn, DialogueItemResolver and more (14 functions)

#include "dialogueitem_decls.h"

// @fnv 0x0083c820
DialogueResponse* DialogueItem::GetActiveResponse()
{
    if (m_pCurrentResponseList)
        return m_pCurrentResponseList->GetItem();
    else
        return NULL;
}

// @fnv 0x005e3fa0
TESObjectREFR* DialogueItem::SelectDefaultResponseList()
{
    return *(TESObjectREFR**)((char*)this + 0x6c);
}

void dialogueitem_emit_deleting_destructor(DialogueItem* item);

struct FUN_0083c7e0_shell : public DialogueItem
{
    bool FUN_0083c7e0();
};

void* __fastcall _ref_00726070(void* pThis);

// @fnv 0x0083c7e0
bool FUN_0083c7e0_shell::FUN_0083c7e0()
{
    if (*(void**)((char*)this + 8))
    {
        *(void**)((char*)this + 8) = _ref_00726070(*(void**)((char*)this + 8));
    }
    return *(void**)((char*)this + 8) != 0;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_005c90d0(unsigned int flags);
};
// Calls the destructor on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005c90d0
void* DelStandIn::FUN_005c90d0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_0083c670 {
struct DialogueResponse
{
    ~DialogueResponse();
};
struct ListX
{
    ~ListX();
    bool _ref_008256d0();
    DialogueResponse** _ref_006815c0();
    void _ref_0063f7b0();
};
struct FUN_0083c670
{
    ListX list;
    ~FUN_0083c670();
};
// Destructor that repeatedly deletes the list's current DialogueResponse and advances until the list reports empty.
// @fnv 0x0083c670
FUN_0083c670::~FUN_0083c670()
{
    ListX* pList = &list;
    while (pList && !pList->_ref_008256d0())
    {
        delete *pList->_ref_006815c0();
        pList->_ref_0063f7b0();
    }
}
}  // namespace fnv_0083c670

struct FUN_0083c9e0_resp
{
    unsigned short FUN_0083d420();
};
struct FUN_0083c9e0_t
{
    bool IsEmpty();
    FUN_0083c9e0_resp** GetItem();
    FUN_0083c9e0_t* GetNext();
    unsigned short FUN_0083c9e0();
};

// @fnv 0x0083c9e0
unsigned short FUN_0083c9e0_t::FUN_0083c9e0()
{
    unsigned short usSize = 0;
    usSize += 1;
    FUN_0083c9e0_t* pIter = this;
    while (pIter && !pIter->IsEmpty())
    {
        FUN_0083c9e0_resp* pResponse = *pIter->GetItem();
        usSize += pResponse->FUN_0083d420();
        pIter = pIter->GetNext();
    }
    usSize += 1;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}

void _FNV_Warning(const char* message);

struct FUN_0083c900_shell : public DialogueItem
{
    short GetResponseIndex(DialogueResponse* response);
};

// Returns the index of response in the dialogue responses list, warning and returning 0 if it is not found.
// @fnv 0x0083c900
short FUN_0083c900_shell::GetResponseIndex(DialogueResponse* response)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueResponse*>* pCurrentElementNext = &m_kResponseList;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        if (response == pCurrentElementNext->GetItem())
            return iElementIndex;
        ++iElementIndex;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    _FNV_Warning(
        "DIALOGUE: When trying to get a dialogue response index, the dialogue item was not found in the dialogue responses list.");
    return 0;
}

void FNV_Warning(const char* message);

struct DialogueItem_shell : public DialogueItem
{
    DialogueResponse* GetResponseByIndex(short index);
};

// Walks the dialogue response list and returns the response at the given index, warning and returning null if the index is out of range.
// @fnv 0x0083c970
DialogueResponse* DialogueItem_shell::GetResponseByIndex(short index)
{
    short current = 0;
    BSSimpleList<DialogueResponse*>* node = &m_kResponseList;
    while (node && !node->IsEmpty())
    {
        if (current == index)
            return node->GetItem();
        ++current;
        node = node->GetNext();
    }
    FNV_Warning(
        "DIALOGUE: When trying to get a dialogue response by its index, the index was larger than the size of the dialogue responses list.");
    return 0;
}

bool __fastcall _ref_008256d0(void*);
struct DialogueResponse;
DialogueResponse*& __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
struct StandIn
{
    char _pad[8];
    void* _cur;
    void FUN_0083c8a0(DialogueResponse* apDialogueResponse);
};
// @fnv 0x0083c8a0
void StandIn::FUN_0083c8a0(DialogueResponse* apDialogueResponse)
{
    void* pCurrentElementNext = (void*)this;
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        if (apDialogueResponse == _ref_006815c0(pCurrentElementNext))
        {
            _cur = pCurrentElementNext;
            break;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}

struct TESSaveLoadGame
{
    char* GetCurrentPosition();
    void SaveGameDataOLD(void*, int);
    void FUN_00857a10(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct DialogueFormRef
{
    unsigned int GetFormID();
};
struct DialogueResponseSave
{
    void SaveToGame();
};
struct FUN_0083ca90_t : DialogueItem
{
    short GetResponseIndex(DialogueResponse*);
    void SaveDialogueItem();
};

// @fnv 0x0083ca90
void FUN_0083ca90_t::SaveDialogueItem()
{
    char cCount4 = 0;
    char* pCountPos8 = g_TESSaveLoadGame->GetCurrentPosition();
    g_TESSaveLoadGame->SaveGameDataOLD(&cCount4, 1);
    BSSimpleList<DialogueResponse*>* plist2 = &m_kResponseList;
    while (plist2 && !plist2->IsEmpty())
    {
        DialogueResponse* presponse3 = plist2->GetItem();
        ((DialogueResponseSave*)presponse3)->SaveToGame();
        cCount4++;
        plist2 = plist2->GetNext();
    }
    *pCountPos8 = cCount4;

    char cCurrentVal = -1;
    if (m_pCurrentResponseList)
        cCurrentVal = GetResponseIndex(m_pCurrentResponseList->GetItem());
    g_TESSaveLoadGame->SaveGameDataOLD(&cCurrentVal, 1);

    unsigned int aIInfoID = 0;
    if (pInfo)
        aIInfoID = ((DialogueFormRef*)pInfo)->GetFormID();
    g_TESSaveLoadGame->FUN_00857a10(&aIInfoID, 4);

    unsigned int m_uiTopicFormID = 0;
    if (pTopic)
        m_uiTopicFormID = ((DialogueFormRef*)pTopic)->GetFormID();
    g_TESSaveLoadGame->FUN_00857a10(&m_uiTopicFormID, 4);

    unsigned int iQuestID_2 = 0;
    if (pQuest)
        iQuestID_2 = ((DialogueFormRef*)pQuest)->GetFormID();
    g_TESSaveLoadGame->FUN_00857a10(&iQuestID_2, 4);

    unsigned int iSpeakerID = 0;
    if (m_pDialogueSpeaker)
        iSpeakerID = ((DialogueFormRef*)m_pDialogueSpeaker)->GetFormID();
    g_TESSaveLoadGame->FUN_00857a10(&iSpeakerID, 4);
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectREFR : public TESForm
{
};
TESForm* GetFormByID(unsigned int);
class DialogueItemResolver : public DialogueItem
{
  public:
    void FUN_0083cdf0();
};
// @fnv 0x0083cdf0
void DialogueItemResolver::FUN_0083cdf0()
{
    unsigned int loc = reinterpret_cast<unsigned int>(m_pDialogueSpeaker);
    if (loc)
    {
        m_pDialogueSpeaker = dynamic_cast<TESObjectREFR*>(GetFormByID(loc));
    }
}

struct BGSSaveGameBuffer
{
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue(unsigned int, unsigned int);
    void SaveData(void*, int, int);
    void SerializeFormData(void*, int);
};
struct DialogueResponseBufferWriter
{
    void FUN_0083d690(BGSSaveGameBuffer*);
};
struct DialogueItemBufferWriter : ::DialogueItem
{
    short GetResponseIndex(::DialogueResponse*);
    void FUN_0083ce40(BGSSaveGameBuffer* apSaveGameBuffer);
};

// Writes the response list, current response index, and associated form data (pInfo, pTopic, pQuest, m_pDialogueSpeaker) to apSaveGameBuffer.
// @fnv 0x0083ce40
void DialogueItemBufferWriter::FUN_0083ce40(BGSSaveGameBuffer* apSaveGameBuffer)
{
    short scurrentResponse;
    ::BSSimpleList< ::DialogueResponse*>* pCurrentElementNext;
    unsigned int isaveGameBufferPos;
    unsigned int isaveGameCount;

    isaveGameCount = 0;
    isaveGameBufferPos = apSaveGameBuffer->StartVariableSizedValue();
    pCurrentElementNext = &m_kResponseList;
    while (pCurrentElementNext)
    {
        ::DialogueResponse* presponse = pCurrentElementNext->GetItem();
        if (presponse)
        {
            reinterpret_cast<DialogueResponseBufferWriter*>(presponse)->FUN_0083d690(apSaveGameBuffer);
            isaveGameCount++;
        }
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    apSaveGameBuffer->SaveVariableSizedValue(isaveGameCount, isaveGameBufferPos);
    scurrentResponse = m_pCurrentResponseList ? GetResponseIndex(m_pCurrentResponseList->GetItem()) : -1;
    apSaveGameBuffer->SaveData(&scurrentResponse, 2, 0);
    apSaveGameBuffer->SerializeFormData(pInfo, 0);
    apSaveGameBuffer->SerializeFormData(pTopic, 0);
    apSaveGameBuffer->SerializeFormData(pQuest, 0);
    apSaveGameBuffer->SerializeFormData(m_pDialogueSpeaker, 0);
}

namespace fnv_0083c520 {
struct TESResponse
{
    int GetNext();
};
struct TESResponseList
{
    TESResponseList();
    ~TESResponseList();
    operator unsigned int() const;
    TESResponse* pHead;
};
struct FUN_0061e760_shell
{
    TESResponseList* FUN_0061e760(TESResponseList*);
};
struct DialogueResponse;
typedef ::BSSimpleList<DialogueResponse*> DialogueResponseList;
struct DialogueResponse
{
    DialogueResponse(TESQuest*, TESTopic*, TESTopicInfo*, TESObjectREFR*, TESResponse*);
    char* pResponseText;
    unsigned short usResponseLen;
    unsigned short usResponseMax;
    unsigned int eEmotion;
    int ActorProjectileState;
    char* pVoiceFile;
    unsigned short usVoiceLen;
    unsigned short usVoiceMax;
    void* m_pFirstIdleForm;
    void* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
};
struct FUN_0083c520
{
    DialogueResponseList ResponseList;
    void* m_pCurrentResponseList;
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
    FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};

// Constructs a dialogue response list by iterating over TESResponse entries from apInfo and appending a DialogueResponse for each.
// @fnv 0x0083c520
FUN_0083c520::FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker)
{
    m_pCurrentResponseList = 0;
    pInfo = 0;
    if (apTopic && apInfo && apQuest)
    {
        pInfo = apInfo;
        pTopic = apTopic;
        pQuest = apQuest;
        m_pDialogueSpeaker = apSpeaker;
        TESResponseList responseList;
        ((FUN_0061e760_shell*)apInfo)->FUN_0061e760(&responseList);
        TESResponse* presponse = (TESResponse*)(unsigned int)responseList;
        while (presponse)
        {
            DialogueResponse* pResponse = new DialogueResponse(apQuest, apTopic, apInfo, apSpeaker, presponse);
            ResponseList.AddTail(pResponse);
            presponse = (TESResponse*)presponse->GetNext();
        }
    }
}
}  // namespace fnv_0083c520

struct DialogueLoadGame : ::TESSaveLoadGame
{
    void LoadGameDataOLD(void*, int);
    void FUN_00857aa0(void*, int);
};
class TESTopicInfo : public ::TESForm
{
};
class TESTopic : public ::TESForm
{
};
class TESQuest : public ::TESForm
{
};
class TESIdleForm;
class DialogueResponse
{
  public:
    DialogueResponse();
    void FUN_0083d550();
    BSStringT<char> m_kResponseText;
    unsigned int eEmotion;
    unsigned int m_uiEmotionValue;
    BSStringT<char> m_kResponseNotes;
    TESIdleForm* m_pFirstIdleForm;
    TESIdleForm* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESTopicInfo* pInfo;
    TESQuest* pQuest;
};
struct DialogueItemLoad : ::DialogueItem
{
    ::DialogueResponse* GetResponseByIndex(unsigned short);
    void FUN_0083c8a0(::DialogueResponse*);
    void FUN_0083cc10();
};

// Reads response count, current index, topic info, topic, quest, and speaker IDs from the save stream into the dialogue item.
// @fnv 0x0083cc10
void DialogueItemLoad::FUN_0083cc10()
{
    unsigned char cCount4;
    unsigned int iloopB;
    ::DialogueResponse* presponse3;
    char cCurrentVal;
    unsigned int aIInfoID;
    unsigned int m_uiTopicFormID;
    unsigned int iQuestID_2;
    unsigned int iSpeakerID;

    ((DialogueLoadGame*)g_TESSaveLoadGame)->LoadGameDataOLD(&cCount4, 1);
    for (iloopB = 0; iloopB < cCount4; iloopB++)
    {
        presponse3 = reinterpret_cast< ::DialogueResponse*>(new DialogueResponse);
        reinterpret_cast<DialogueResponse*>(presponse3)->FUN_0083d550();
        m_kResponseList.AddTail(presponse3);
    }

    ((DialogueLoadGame*)g_TESSaveLoadGame)->LoadGameDataOLD(&cCurrentVal, 1);
    if (cCurrentVal != -1)
        FUN_0083c8a0(GetResponseByIndex(cCurrentVal));
    else
        m_pCurrentResponseList = 0;

    ((DialogueLoadGame*)g_TESSaveLoadGame)->FUN_00857aa0(&aIInfoID, 4);
    if (aIInfoID)
        pInfo = reinterpret_cast< ::TESTopicInfo*>(dynamic_cast<TESTopicInfo*>(::GetFormByID(aIInfoID)));
    ((DialogueLoadGame*)g_TESSaveLoadGame)->FUN_00857aa0(&m_uiTopicFormID, 4);
    if (m_uiTopicFormID)
        pTopic = reinterpret_cast< ::TESTopic*>(dynamic_cast<TESTopic*>(::GetFormByID(m_uiTopicFormID)));
    ((DialogueLoadGame*)g_TESSaveLoadGame)->FUN_00857aa0(&iQuestID_2, 4);
    if (iQuestID_2)
        pQuest = reinterpret_cast< ::TESQuest*>(dynamic_cast<TESQuest*>(::GetFormByID(iQuestID_2)));
    ((DialogueLoadGame*)g_TESSaveLoadGame)->FUN_00857aa0(&iSpeakerID, 4);
    m_pDialogueSpeaker = (::TESObjectREFR*)iSpeakerID;
}

// fallout_shared/tesreactionform.cpp: TESReactionForm, ReactionCompare, C0B0Owner, TESReactionFormLoad (21 functions)

#include "tesreactionform_decls.h"

void __cdecl operator delete(void* pointer);

static const int kInitializeDataComponentValue1 = 8;

// @fnv 0x0048bad0
void TESReactionForm::InitializeComponent()
{
    m_ucReactionFlags = kInitializeDataComponentValue1;
}

// @fnv 0x0048baf0
void TESReactionForm::ClearComponent()
{
    ClearReactionList();
}

// @fnv 0x0048bb10
void TESReactionForm::ClearReactionList()
{
    while (reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())
               ->GetItem() != 0)
    {
        InventoryStackRecord* pToFree =
            reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())
                ->GetItem();
        InventoryStackRecord* pItem = pToFree;
        ::operator delete(pItem);
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())
            ->RemoveHead();
    }
}

// Constructs the map base by forwarding the given size to the TESReactionMapStorage base constructor.
// Constructs a BSMapBase<int, DistantTreeTextureInfo*> with the given size, delegating to TESReactionMapStorage.
// @fnv 0x0048b380
template <> BSMapBase<int, DistantTreeTextureInfo*>::BSMapBase(unsigned int size) : TESReactionMapStorage(size)
{}

// On load, walks the reaction list and drops entries whose formID no longer resolves, unlinking them from the list.
// @fnv 0x0048cb40
void TESReactionForm::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(4))
    {
        BSSimpleList<BGSCameraShot*>* current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(&m_kReactionList);
        BSSimpleList<BGSCameraShot*>* previous = 0;
        while (current && !current->IsEmpty())
        {
            ReactionInfo* reaction = reinterpret_cast<ReactionInfo*>(current->GetItem());
            bool remove = false;
            if (reaction)
            {
                reaction->formID = reaction->formID
                                       ? reinterpret_cast<unsigned int>(TESForm::GetFormByID(reaction->formID))
                                       : 0;
                if (!reaction->formID)
                {
                    delete reaction;
                    remove = true;
                }
            }
            else
            {
                remove = true;
            }
            if (remove)
            {
                if (previous)
                {
                    previous->Remove(current->GetItem());
                    current = previous->GetNext();
                }
                else
                {
                    current->RemoveHead();
                }
            }
            else
            {
                previous = current;
                current = current->GetNext();
            }
        }
    }
}

// Resolves each reaction entry's formID against the given form's file, warns and removes entries whose form cannot be found.
// @fnv 0x0048bc30
void TESReactionForm::InitItem(TESForm* form)
{
    // Local names preserve the original MSVC9 stack allocation.
    TESFile* pPrev;
    BSSimpleList<BGSCameraShot*>* pList =
        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    BSSimpleList<BGSCameraShot*>* pFile = 0;
    pPrev = form ? form->GetFile(-1) : 0;
    while (pList && pList->GetItem())
    {
        ReactionInfo* reaction = reinterpret_cast<ReactionInfo*>(pList->GetItem());
        unsigned int formID = reaction->formID;
        TESForm::RemapFormIDForFile(formID, pPrev);
        reaction->formID = reinterpret_cast<unsigned int>(TESForm::GetFormByID(formID));
        if (reaction->formID)
        {
            pList = pList->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Form (%08X) not found for reaction of pForm (%08X) '%s'.\r\n", formID,
                    form->GetFormID(), form->GetEditorID());
            if (pList->GetNext() || !pFile)
            {
                pList->RemoveHead();
            }
            else
            {
                pFile->Remove(reinterpret_cast<BGSCameraShot* const&>(reaction));
                pList = pFile->GetNext();
            }
            delete reaction;
        }
    }
}

struct FUN_0048c1b0_shell : public TESReactionForm
{
    int FUN_0048c1b0(TESForm*);
};

struct GROUP_REACTION_dummy
{
    TESForm* pForm;
    int iOffset;
    int eFightReaction;
};

GROUP_REACTION_dummy** __fastcall _ref_006815c0(void* pList);
void* __fastcall _ref_00726070(void* pList);

// Searches the reaction list for a matching form and returns its fight reaction, or 0 if not found.
// @fnv 0x0048c1b0
int FUN_0048c1b0_shell::FUN_0048c1b0(TESForm* apForm)
{
    if (apForm != 0)
    {
        void* pList = reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData();
        while (pList != 0 && *_ref_006815c0(pList) != 0)
        {
            GROUP_REACTION_dummy* fr = *_ref_006815c0(pList);
            if (fr->pForm == apForm)
                return fr->eFightReaction;
            pList = _ref_00726070(pList);
        }
    }
    return 0;
}

struct SoundListView
{
    void AddTail(GROUP_REACTION_dummy* const&);
};
struct ListH_0048bfc0
{
    void _ref_00905330(GROUP_REACTION_dummy**);
};
struct RF_0048bfc0
{
    char pad[4];
    ListH_0048bfc0 list;
};
struct Args_0048bfc0
{
    TESForm* apForm;
    int aiReaction;
};
// @fnv 0x0048bfc0
void __fastcall SetReaction(BaseProcess* self, Args_0048bfc0 args)
{
    if (!args.apForm)
        return;
    bool bFound = false;
    void* pList = self->GetCurrentProcessData();
    while (pList && *_ref_006815c0(pList))
    {
        GROUP_REACTION_dummy* fr = *_ref_006815c0(pList);
        if (fr->pForm == args.apForm)
        {
            if (args.aiReaction == 0 && fr->eFightReaction == 0)
            {
                ((ListH_0048bfc0*)((char*)self + 4))->_ref_00905330(&fr);
                delete fr;
            }
            else
            {
                fr->iOffset = args.aiReaction;
            }
            bFound = true;
            break;
        }
        pList = _ref_00726070(pList);
    }
    if (!bFound && args.aiReaction)
    {
        GROUP_REACTION_dummy* fr = new GROUP_REACTION_dummy;
        fr->pForm = args.apForm;
        fr->iOffset = args.aiReaction;
        ((SoundListView*)self->GetCurrentProcessData())->AddTail(fr);
    }
}

struct BFC_s
{
    BFC_s();
    virtual void Init();
};
struct SL
{
    void* item;
    void* next;
    SL();
    ~SL();
};
struct FUN_0048ba00 : public BFC_s
{
    SL m_kReactionList;
    unsigned char m_ucReactionFlags;
    FUN_0048ba00();
};
// @fnv 0x0048ba00
FUN_0048ba00::FUN_0048ba00()
{
    ((TESReactionForm*)this)->InitializeComponent();
}

struct ListX
{
    ~ListX();
};
struct FUN_0048ba70 : BaseFormComponent
{
    ListX m_kNode;
    ~FUN_0048ba70();
};
// @fnv 0x0048ba70
FUN_0048ba70::~FUN_0048ba70()
{
    ((TESReactionForm*)(void*)this)->ClearComponent();
}

void __cdecl operator delete(void*);
void* __cdecl operator new(unsigned int);
struct ReactionEntry
{
    unsigned int formID;
    int a;
    int b;
};
struct G2
{
    void AddHead(ReactionEntry* const&);
};
struct BGSLoadFormBufferA
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
struct FUN_0048ca90 : TESReactionForm
{
    void LoadReaction(BGSLoadFormBuffer* buffer);
};
// @fnv 0x0048ca90
void FUN_0048ca90::LoadReaction(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(4))
    {
        ClearReactionList();
        unsigned int count = ((BGSLoadFormBufferA*)buffer)->ReadElementCount();
        for (unsigned int i = 0; i < count; ++i)
        {
            ReactionEntry* entry = new ReactionEntry;
            ((BGSLoadFormBufferA*)buffer)->ReadFormIdentifier(&entry->formID);
            ((BGSLoadFormBufferA*)buffer)->ReadTypedData(&entry->a, 4);
            ((BGSLoadFormBufferA*)buffer)->ReadTypedData(&entry->b, 4);
            ((G2*)((char*)this + 4))->AddHead(entry);
        }
    }
}

struct RefH : public TESForm
{
    bool IsDeleted() const;
};

struct ContainerItemExtraFileData
{
    unsigned int formID;
    unsigned int field4;
    unsigned int field8;
    void Endian();
};

bool FUN_00401500();
void AppendChunk(unsigned int, void*, unsigned int);

struct FUN_0048bb70_shell : public BaseProcess
{
    void WriteCameraShotList();
};

// @fnv 0x0048bb70
void FUN_0048bb70_shell::WriteCameraShotList()
{
    BSSimpleList<BGSCameraShot*>* current = (BSSimpleList<BGSCameraShot*>*)GetCurrentProcessData();
    BGSCameraShot* shot;
    ContainerItemExtraFileData data;

    while (current && current->GetItem())
    {
        shot = current->GetItem();

        if (!(*reinterpret_cast<RefH**>(shot))->IsDeleted())
        {
            data.formID = (*reinterpret_cast<RefH**>(shot))->GetFormID();
            data.field4 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 4);
            data.field8 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 8);

            if (FUN_00401500())
                data.Endian();

            AppendChunk(0x4d414e58, &data, 0xc);

            if (FUN_00401500())
                data.Endian();
        }

        current = (BSSimpleList<BGSCameraShot*>*)current->GetNext();
    }
}

struct GROUP_REACTION_bd50
{
    TESForm* pForm;
    int iOffset;
    int eFightReaction;
};

struct ReactionListOps_bd50
{
    ReactionListOps_bd50* FUN_00717e50();
    GROUP_REACTION_bd50** FUN_006815c0();
    void FUN_00905820(GROUP_REACTION_bd50** item);
    ReactionListOps_bd50* FUN_00726070();
};

extern int DAT_01183040;
extern int DAT_01186b30;
void* __cdecl FUN_00ec43fb(TESForm* form, unsigned int a, void* b, void* c, unsigned int d);

struct FUN_0048bd50_shell : public TESReactionForm
{
    void FUN_0048bb10();
    void CopyReactionList(TESForm* form);
};

// @fnv 0x0048bd50
void FUN_0048bd50_shell::CopyReactionList(TESForm* form)
{
    ReactionListOps_bd50* p = (ReactionListOps_bd50*)FUN_00ec43fb(form, 0, &DAT_01183040, &DAT_01186b30, 0);
    if (p == 0)
    {
        return;
    }
    this->FUN_0048bb10();
    ReactionListOps_bd50* cur5;
    ReactionListOps_bd50* dst;
    dst = ((ReactionListOps_bd50*)this)->FUN_00717e50();
    cur5 = p->FUN_00717e50();
    while (cur5 != 0 && *cur5->FUN_006815c0() != 0)
    {
        GROUP_REACTION_bd50* src2 = *cur5->FUN_006815c0();
        GROUP_REACTION_bd50* item = new GROUP_REACTION_bd50;
        item->pForm = src2->pForm;
        item->iOffset = src2->iOffset;
        item->eFightReaction = src2->eFightReaction;
        dst->FUN_00905820(&item);
        if (dst->FUN_00726070() != 0)
        {
            dst = dst->FUN_00726070();
        }
        cur5 = cur5->FUN_00726070();
    }
}

struct ReactionData
{
    unsigned int form;
    int offset;
    int fight;
};
struct ReactionList
{
    ReactionData** FUN_006815c0();
    ReactionList* FUN_00726070();
    bool FUN_008256d0();
};
struct ReactionAccess
{
    ReactionList* FUN_00717e50();
};
struct ReactionCompare : TESReactionForm
{
    bool CompareComponent(BaseFormComponent*);
};
// Compares this reaction form's list against another TESReactionForm's list entry by entry, returning true when they differ or the other list is longer.
// @fnv 0x0048be40
bool ReactionCompare::CompareComponent(BaseFormComponent* component)
{
    TESReactionForm* right = dynamic_cast<TESReactionForm*>(component);
    if (!right)
        return true;
    ReactionList* other = reinterpret_cast<ReactionAccess*>(this)->FUN_00717e50();
    ReactionList* left = reinterpret_cast<ReactionAccess*>(right)->FUN_00717e50();
    while (other)
    {
        if (!left)
            return true;
        ReactionData* rhs = *other->FUN_006815c0();
        ReactionData* lhs = *left->FUN_006815c0();
        if (rhs && lhs)
        {
            if (rhs->form != lhs->form)
                return true;
            if (rhs->offset != lhs->offset)
                return true;
            if (rhs->fight != lhs->fight)
                return true;
        }
        else if (rhs || lhs)
            return true;
        left = left->FUN_00726070();
        other = other->FUN_00726070();
    }
    if (left && !left->FUN_008256d0())
        return true;
    return false;
}

// Adjust the stored count for a form: add a new entry if missing, remove the entry when its count reaches zero.

class C0B0Form;

struct C0B0Entry
{
    C0B0Form* m_pkForm;
    int m_iArrayLength;
    int unk08;
};

class C0B0Node
{
  public:
    C0B0Entry** GetItem();
    C0B0Node* GetNext();
};

class C0B0List : public C0B0Node
{
  public:
    void AddTail(C0B0Entry* const& rpkEntry);
    void Remove(C0B0Entry* const& rpkEntry);
};

class C0B0Owner
{
  public:
    C0B0List* GetList();
    void ModReaction(C0B0Form* pkForm, int iDelta);
};

// @fnv 0x0048c0b0
void C0B0Owner::ModReaction(C0B0Form* pkForm, int iDelta)
{
    if (!pkForm || !iDelta)
        return;

    C0B0Entry* pkEntry = 0;
    C0B0Node* pkIter = GetList();
    bool bFound = false;
    while (pkIter && *pkIter->GetItem())
    {
        pkEntry = *pkIter->GetItem();
        if (pkEntry->m_pkForm == pkForm)
        {
            bFound = true;
            break;
        }
        pkIter = pkIter->GetNext();
    }

    if (!bFound)
    {
        pkEntry = new C0B0Entry;
        pkEntry->m_pkForm = pkForm;
        pkEntry->m_iArrayLength = iDelta;
        GetList()->AddTail(pkEntry);
    }
    else
    {
        pkEntry->m_iArrayLength += iDelta;
        if (!pkEntry->m_iArrayLength)
        {
            GetList()->Remove(pkEntry);
            delete pkEntry;
        }
    }
}

struct FUN_0048c220_shell
{
    void* FUN_00717e50();
    void SetFightReaction(TESForm* apForm, int aiReaction);
};
// If apForm is non-null, updates the matching list entry's reaction or appends a new entry when aiReaction is non-zero.
// @fnv 0x0048c220
void FUN_0048c220_shell::SetFightReaction(TESForm* apForm, int aiReaction)
{
    if (apForm == 0)
    {
        return;
    }
    bool bFound = false;
    void* pNode = FUN_00717e50();
    while (pNode != 0 && *_ref_006815c0(pNode) != 0)
    {
        GROUP_REACTION_dummy* pItem = *_ref_006815c0(pNode);
        if (pItem->pForm == apForm)
        {
            pItem->eFightReaction = aiReaction;
            bFound = true;
            break;
        }
        pNode = _ref_00726070(pNode);
    }
    if (!bFound && aiReaction != 0)
    {
        GROUP_REACTION_dummy* newItem = new GROUP_REACTION_dummy;
        newItem->pForm = apForm;
        newItem->iOffset = 0;
        newItem->eFightReaction = aiReaction;
        static_cast<SoundListView*>(FUN_00717e50())->AddTail(newItem);
    }
}

namespace fnv_0048c2e0 {
extern "C" char str_01012c78[];
extern "C" char str_0101d4c8[];
extern "C" char str_01012cb0[];
extern void* DAT_011de45c;
extern unsigned char DAT_011de4e8;
struct Global_011de45c
{
    bool FUN_00862110();
    unsigned int* FUN_004fd3e0();
};
struct Global_011de4e8
{
    const unsigned char* FUN_00408d60();
};
struct ActorPackageContext
{
    int FUN_005ae380();
};
struct FUN_0048c2e0_shell : BaseProcess
{
    ActorPackageContext* FUN_00717e50();
    unsigned short FUN_0048c2e0(unsigned int flags);
};
void __cdecl FUN_0040fbe0(const char*, ...);
// Computes the serialized size of the package data when flag bit 4 is set, adding fixed fields and per-entry sizes, and logs the result.
// @fnv 0x0048c2e0
unsigned short FUN_0048c2e0_shell::FUN_0048c2e0(unsigned int flags)
{
    unsigned short count = 0;
    if ((flags & 4) != 0)
    {
        unsigned short start = count;
        if (((Global_011de45c*)DAT_011de45c)->FUN_00862110())
        {
            count += 4;
            count += 2;
        }
        ActorPackageContext* package = FUN_00717e50();
        count += 2;
        count += package->FUN_005ae380() * 8;
        if (*((Global_011de4e8*)&DAT_011de4e8)->FUN_00408d60() != 0)
        {
            unsigned int* formID = ((Global_011de45c*)DAT_011de45c)->FUN_004fd3e0();
            if (formID != 0)
            {
                TESForm* form = TESForm::GetFormByID(*formID);
                FUN_0040fbe0(str_01012cb0, count - start, *formID, form->GetEditorID(),
                             *(unsigned int*)((unsigned char*)formID + 5), 0x557, str_0101d4c8);
            }
            else
            {
                FUN_0040fbe0(str_01012c78, count - start, 0x557, str_0101d4c8);
            }
        }
    }
    return count;
}
}  // namespace fnv_0048c2e0

struct ObjC400
{
    unsigned int formID;
    char flag4;
    int field5;
};
struct SaveC400
{
    unsigned int FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void*, int);
    void FUN_00857a10(void*, int);
    ObjC400* FUN_004fd3e0();
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern SaveC400* DAT_011de45c;
extern GlobalObject_0045cf30 DAT_011de4e8;
extern const char str_0101d4c8[];
extern const char str_010153a0[];
extern const char str_0101536c[];
extern const char str_01015318[];
TESForm* __cdecl FUN_004839c0(unsigned int);
void __cdecl FUN_0040fbe0(const char*, ...);
int Warning(const char*, ...);

struct S24
{
    void WriteReactionList(unsigned int arg);
};

// @fnv 0x0048c400
void S24::WriteReactionList(unsigned int auiFlags)
{
    if (auiFlags & 4)
    {
        unsigned short sizeWord = 0;
        unsigned int posSize4 = 0;
        unsigned int startPos = DAT_011de45c->FUN_00825c00();
        if (*DAT_011de4e8.Bool())
        {
            startPos = DAT_011de45c->FUN_00825c00();
        }
        if (DAT_011de45c->FUN_00862110())
        {
            int tag = 0x424c4f4b;
            DAT_011de45c->FUN_008579b0(&tag, 4);
            posSize4 = DAT_011de45c->FUN_00825c00();
            DAT_011de45c->FUN_008579b0(&sizeWord, 2);
        }
        unsigned short kCount = 0;
        unsigned int posCountC = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->FUN_008579b0(&kCount, 2);
        ReactionListOps_bd50* node = ((ReactionListOps_bd50*)this)->FUN_00717e50();
        while (node)
        {
            GROUP_REACTION_bd50* item = *node->FUN_006815c0();
            if (item)
            {
                unsigned int formID = item->pForm->GetFormID();
                DAT_011de45c->FUN_00857a10(&formID, 4);
                DAT_011de45c->FUN_008579b0(&item->iOffset, 4);
                kCount++;
            }
            node = node->FUN_00726070();
        }
        *(unsigned short*)posCountC = kCount;
        if (*DAT_011de4e8.Bool())
        {
            unsigned int endPos2 = DAT_011de45c->FUN_00825c00();
            ObjC400* kObj = DAT_011de45c->FUN_004fd3e0();
            if (kObj)
            {
                TESForm* form = FUN_004839c0(kObj->formID);
                FUN_0040fbe0(str_010153a0, endPos2 - startPos, kObj->formID, form->GetEditorID(),
                             *(int*)((char*)kObj + 5), 1403, str_0101d4c8);
            }
            else
            {
                FUN_0040fbe0(str_0101536c, endPos2 - startPos, 1403, str_0101d4c8);
            }
        }
        if (DAT_011de45c->FUN_00862110())
        {
            unsigned int endPos = DAT_011de45c->FUN_00825c00();
            unsigned int blockStart = posSize4;
            if (endPos > blockStart + 0xffff)
            {
                Warning(str_01015318, str_0101d4c8, 1403);
            }
            *(unsigned short*)posSize4 = (unsigned short)(endPos - blockStart);
        }
    }
}

struct SaveLoadFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsByte0;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
    unsigned char version;
};

struct SaveLoadGameStub
{
    bool FUN_00862110();
    void ReadTypedData(void* apData, unsigned int auiSize);
    void ReadFormIdentifier(unsigned int* apID, int aiSize);
    SaveLoadFormInfo* GetCurrentFormInfo();
    unsigned int GetBufferPosition();
    unsigned char GetVersion();
};
extern SaveLoadGameStub* g_TESSaveLoadGame;

TESForm* LookupFormByID(unsigned int auiFormID);

struct TESReactionFormLoad : public TESReactionForm
{
    void ResetReactions();
    void AddReaction(unsigned int auiFormID, int aiReaction);
    void LoadReactions(unsigned int auiChangeFlags, BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x0048c640
void TESReactionFormLoad::LoadReactions(unsigned int auiChangeFlags, BGSLoadFormBuffer* apBuffer)
{
    if (auiChangeFlags & 4)
    {
        unsigned short usLength = 0;
        unsigned int dwStart = 0;
        unsigned short usNum;
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int uiMarker;
            g_TESSaveLoadGame->ReadTypedData(&uiMarker, 4);
            if (uiMarker != 0x424C4F4B)
            {
                SaveLoadFormInfo* pInfo = g_TESSaveLoadGame->GetCurrentFormInfo();
                if (pInfo)
                {
                    TESForm* pForm = LookupFormByID(pInfo->formID);
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1415,
                        pInfo->formID, pForm->GetEditorID(), pInfo->version, *(unsigned int*)&pInfo->flagsByte0);
                }
                else
                {
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1415,
                        g_TESSaveLoadGame->GetVersion());
                }
            }
            dwStart = g_TESSaveLoadGame->GetBufferPosition();
            g_TESSaveLoadGame->ReadTypedData(&usLength, 2);
        }
        ResetReactions();
        g_TESSaveLoadGame->ReadTypedData(&usNum, 2);
        for (unsigned int i = 0; i < usNum; i++)
        {
            unsigned int auiFormId;
            g_TESSaveLoadGame->ReadFormIdentifier(&auiFormId, 4);
            int iFactionReaction;
            g_TESSaveLoadGame->ReadTypedData(&iFactionReaction, 4);
            AddReaction(auiFormId, iFactionReaction);
        }
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int endPos = g_TESSaveLoadGame->GetBufferPosition();
            SaveLoadFormInfo* pEndInfo = g_TESSaveLoadGame->GetCurrentFormInfo();
            if (pEndInfo)
            {
                TESForm* pEndForm = LookupFormByID(pEndInfo->formID);
                if (endPos > usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        endPos - (usLength + dwStart),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        pEndInfo->formID, pEndForm->GetEditorID(), pEndInfo->version,
                        *(unsigned int*)&pEndInfo->flagsByte0);
                }
                else if (endPos < usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        (usLength + dwStart) - endPos,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        pEndInfo->formID, pEndForm->GetEditorID(), pEndInfo->version,
                        *(unsigned int*)&pEndInfo->flagsByte0);
                }
            }
            else
            {
                if (endPos > usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        endPos - (usLength + dwStart),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        g_TESSaveLoadGame->GetVersion());
                }
                else if (endPos < usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        (usLength + dwStart) - endPos,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        g_TESSaveLoadGame->GetVersion());
                }
            }
        }
    }
}

void* __fastcall _ref_00717e50(void* pList);
void __fastcall _ref_0063f7b0(void* pList);
unsigned int __cdecl _ref_004839c0(unsigned int aFormID);

struct FUN_0048c930_shell
{
    void ResolveGroupReactionForms(unsigned int flags, unsigned int unused);
};

// When flags has bit 4, walks the list, resolves each entry's pForm via _ref_004839c0, and deletes entries whose form resolves to null.
// @fnv 0x0048c930
void FUN_0048c930_shell::ResolveGroupReactionForms(unsigned int flags, unsigned int unused)
{
    if (flags & 4)
    {
        void* iter = _ref_00717e50(this);
        int count = 0;
        while (iter != 0)
        {
            GROUP_REACTION_dummy* entry = *_ref_006815c0(iter);
            if (entry != 0)
            {
                unsigned int formID = (unsigned int)entry->pForm;
                entry->pForm = (TESForm*)_ref_004839c0(formID);
                if (entry->pForm == 0)
                {
                    _ref_0063f7b0(iter);
                    GROUP_REACTION_dummy* dead = entry;
                    operator delete(dead);
                }
                else
                {
                    iter = _ref_00726070(iter);
                }
            }
            else
            {
                iter = _ref_00726070(iter);
            }
        }
    }
}

struct FUN_0048c9d0_ChangeFlags
{
    bool FUN_004280f0();
};

struct FUN_0048c9d0_ListNode
{
    void* item;
    FUN_0048c9d0_ListNode* next;

    FUN_0048c9d0_ListNode* FUN_006815c0();
    FUN_0048c9d0_ListNode* FUN_00726070();
};

struct FUN_0048c9d0_SaveBuffer
{
    FUN_0048c9d0_ChangeFlags* FUN_00428110(int* value, int size);
    unsigned int FUN_00865f20();
    void FUN_00865df0(int value, int flag);
    void FUN_00865e50(void* data, unsigned int size, int flag);
    void FUN_00865ff0(int count, unsigned int value);
};

struct FUN_0048c9d0_Class
{
    int unk00;
    FUN_0048c9d0_ListNode list;

    void FUN_0048c9d0(FUN_0048c9d0_SaveBuffer* buffer);
};

// @fnv 0x0048c9d0
void FUN_0048c9d0_Class::FUN_0048c9d0(FUN_0048c9d0_SaveBuffer* buffer)
{
    void* item;
    FUN_0048c9d0_ListNode* cursor;
    unsigned int value;
    int count;

    {
        int temp;
        if (buffer->FUN_00428110(&temp, 4)->FUN_004280f0())
        {
            count = 0;
            value = buffer->FUN_00865f20();
            cursor = &list;
            while (cursor != 0)
            {
                item = cursor->FUN_006815c0()->item;
                if (item != 0)
                {
                    buffer->FUN_00865df0(*(int*)item, 0);
                    buffer->FUN_00865e50((char*)item + 4, 4, 0);
                    buffer->FUN_00865e50((char*)item + 8, 4, 0);
                    count = count + 1;
                }
                cursor = cursor->FUN_00726070();
            }
            buffer->FUN_00865ff0(count, value);
        }
    }
}

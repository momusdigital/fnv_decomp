// fallout/ai/escortpackage.cpp: EscortActorPackageData (10 functions)

#include "escortpackage_decls.h"

// Initializes the EscortActorPackageData object by calling FUN_0067d920, setting its vtable to kVtbl_UseWeaponActorPackageData, and clearing pActor.
// @fnv 0x0067d8f0
EscortActorPackageData::EscortActorPackageData()
{
    FUN_0067d920();
    m_ppVirtualMethodTable = kVtbl_UseWeaponActorPackageData;
    pActor = 0;
}

struct G2
{
    void AddHead(Actor* const&);
};
struct LH
{
    bool IsInList(Actor* const&);
};
struct FUN_009f0a20
{
    G2 m_kNode;
    void RegisterActor(Actor* apActor);
};
// Adds apActor to the head of the list at offset 0x10 only if it is not already in that list.
// @fnv 0x009f0a20
void __thiscall FUN_009f0a20::RegisterActor(Actor* apActor)
{
    if (!(((LH*)((char*)this + 0x10))->IsInList(apActor)))
        ((G2*)((char*)this + 0x10))->AddHead(apActor);
}

struct S0980
{
    void FUN_009f09b0();
    void* FUN_009f0980(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_009f09b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x009f0980
void* S0980::FUN_009f0980(unsigned int flags)
{
    FUN_009f09b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESObjectREFR
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsActor();
};
struct H_9f0b70
{
    void RemoveActorFromList(Actor*);
    void HandleDeletedReference(TESObjectREFR*);
};
// If the deleted reference is an Actor, casts it to Actor and forwards it to RemoveActorFromList.
// @fnv 0x009f0b70
void H_9f0b70::HandleDeletedReference(TESObjectREFR* apDeletedObj)
{
    Actor* pactor;
    if (!apDeletedObj->IsActor())
        return;
    pactor = reinterpret_cast<Actor*>(apDeletedObj);
    RemoveActorFromList(pactor);
}

struct BSSimpleList_I
{
    void Remove(int);
};
struct BSSimpleList_Actor
{
    void Remove(Actor* const&);
};

// @fnv 0x009f0a60
void H_9f0b70::RemoveActorFromList(Actor* actor)
{
    ((BSSimpleList_Actor*)((char*)this + 0x10))->Remove(actor);
}

struct RefH
{
    bool IsDeleted() const;
};

struct FUN_008bc860_class
{
    bool FUN_008bc860(Actor*);
};

struct FUN_0055d3b0_class
{
    bool FUN_0055d3b0(void*);
};

struct ListStandin
{
    void _ref_00905330(Actor* const&);
    bool _ref_008256d0();
};

extern void** __fastcall _ref_006815c0(void*);
extern void* __fastcall _ref_00726070(void*);

struct FUN_009f0a80_shell
{
    int FUN_009f0a80(Actor* apEscorter, void* apType);
};

// @fnv 0x009f0a80
int FUN_009f0a80_shell::FUN_009f0a80(Actor* apEscorter, void* apType)
{
    void* pNode;
    int iCount;

    pNode = (void*)((char*)this + 0x10);
    while (pNode)
    {
        Actor* pactor = (Actor*)*_ref_006815c0(pNode);
        pNode = _ref_00726070(pNode);
        if (pactor)
        {
            if (((RefH*)pactor)->IsDeleted() || !((FUN_008bc860_class*)pactor)->FUN_008bc860(apEscorter))
            {
                ((ListStandin*)((char*)this + 0x10))->_ref_00905330(pactor);
                if (!((ListStandin*)((char*)this + 0x10))->_ref_008256d0())
                {
                    pNode = (void*)((char*)this + 0x10);
                }
            }
        }
    }

    iCount = 0;
    for (pNode = (void*)((char*)this + 0x10); pNode; pNode = _ref_00726070(pNode))
    {
        Actor* pactor = (Actor*)*_ref_006815c0(pNode);
        if (pactor && ((FUN_0055d3b0_class*)pactor)->FUN_0055d3b0(apType))
        {
            iCount++;
        }
    }

    return iCount;
}

struct BGSSaveFormBuffer
{
    void SerializeFormData(void* form, int flags);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int count, unsigned int pos);
};

extern void** __fastcall _ref_006815c0(void*);
extern void* __fastcall _ref_00726070(void*);

struct FUN_009f0bb0_shell
{
    void SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Writes the form at offset 8, then each non-null form from the list at offset 0x10, and stores the count at the saved buffer position.
// @fnv 0x009f0bb0
void FUN_009f0bb0_shell::SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SerializeFormData(*(void**)((char*)this + 8), 0);

    unsigned int isaveGameCount = 0;
    unsigned int isaveGameBufferPos = apSaveGameBuffer->FUN_00865f20();
    void* pCurrentElementNext = (void*)((char*)this + 0x10);
    while (pCurrentElementNext)
    {
        void* pForm = *_ref_006815c0(pCurrentElementNext);
        if (pForm)
        {
            apSaveGameBuffer->SerializeFormData(pForm, 0);
            isaveGameCount++;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
    apSaveGameBuffer->FUN_00865ff0(isaveGameCount, isaveGameBufferPos);
}

struct BGSLoadGameBuffer
{
    unsigned int ReadFormIdentifier();
    bool ReadFormIdentifier(void*);
    int ReadElementCount();
};

struct TESForm
{
    virtual ~TESForm();
};

struct TESPackage : public TESForm
{
};

extern TESForm* _ref_004839c0(unsigned int);

struct StandIn006759b0
{
    void* FUN_006759b0();
};

struct FUN_009f0c40_shell
{
    void* pad00;
    void* pad04;
    TESPackage* pPackage;
    void* m_pEscortPackageData;
    G2 m_kNode;

    void LoadPackageAndActors(BGSLoadGameBuffer* apLoadGameBuffer);
};

// Resolves a TESPackage from the buffer's form id, stores its result, then reads a count of Actors and adds each to a list.
// @fnv 0x009f0c40
void FUN_009f0c40_shell::LoadPackageAndActors(BGSLoadGameBuffer* apLoadGameBuffer)
{
    pPackage = dynamic_cast<TESPackage*>(_ref_004839c0(apLoadGameBuffer->ReadFormIdentifier()));
    m_pEscortPackageData = pPackage ? ((StandIn006759b0*)pPackage)->FUN_006759b0() : 0;

    unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
    for (unsigned int uiIndex = 0; uiIndex < isaveGameCount; uiIndex++)
    {
        Actor* pForm = 0;
        apLoadGameBuffer->ReadFormIdentifier(&pForm);
        m_kNode.AddHead(pForm);
    }
}

class B9F09B0Base
{
  public:
    virtual ~B9F09B0Base();

    int unk04;
    int unk08;
    int unk0C;
};

template <class T> class B9F09B0List
{
  public:
    ~B9F09B0List();
    void RemoveAll();

    T m_item;
    B9F09B0List* m_pkNext;
};

class FUN_009f09b0_cls : public B9F09B0Base
{
  public:
    virtual ~FUN_009f09b0_cls();

    B9F09B0List<void*> m_kEntries;
};

// Destructor that removes all entries from the m_kEntries list.
// @fnv 0x009f09b0
FUN_009f09b0_cls::~FUN_009f09b0_cls()
{
    m_kEntries.RemoveAll();
}

class Actor : public TESForm
{
};

struct ActorListNode
{
    bool IsEmpty();
    Actor** GetItemPtr();
    void SetItem(Actor* const&);
    void RemoveItem(Actor* const&);
    ActorListNode* GetNext();
    void RemoveHead();
};

struct FUN_009f0cf0_arg
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual int f03();
};

struct FUN_009f0cf0_shell
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    ActorListNode m_kNode;

    void PruneActorList(FUN_009f0cf0_arg* apArg);
};

// Walks the actor list, re-resolves each entry via _ref_004839c0, removes entries that fail, then stores apArg->f03() in unk04.
// @fnv 0x009f0cf0
void FUN_009f0cf0_shell::PruneActorList(FUN_009f0cf0_arg* apArg)
{
    ActorListNode* pNode = &m_kNode;
    ActorListNode* pPrev = 0;
    while (pNode && !pNode->IsEmpty())
    {
        Actor* pActor = *pNode->GetItemPtr();
        bool bRemove = false;
        if (pActor)
        {
            pActor = pActor ? dynamic_cast<Actor*>(_ref_004839c0((unsigned int)pActor)) : 0;
            if (pActor)
                pNode->SetItem(pActor);
            else
                bRemove = true;
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pPrev)
            {
                pPrev->RemoveItem(*pNode->GetItemPtr());
                pNode = pPrev->GetNext();
            }
            else
            {
                pNode->RemoveHead();
            }
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->GetNext();
        }
    }
    unk04 = apArg->f03();
}

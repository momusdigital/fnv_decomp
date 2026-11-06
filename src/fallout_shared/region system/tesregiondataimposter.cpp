// fallout_shared/region system/tesregiondataimposter.cpp: Callees, ParamCls, TESRegionDataImposter (11 functions)

#include "tesregiondataimposter_decls.h"

// Adds ref to the list; if that fails, appends it to the fallback list and returns true, otherwise returns false.
// @fnv 0x004f2390
bool TESRegionDataImposter::AddImposter(TESObjectREFR* ref)
{
    if (!((BSSimpleList<TESForm*>*)((TESTopicInfoData*)this)->GetLinkToList())
             ->AddHead(reinterpret_cast<TESForm*&>(ref)))
    {
        ((BSSimpleList<QuantityData*>*)&m_kImposterList)->AddTail(reinterpret_cast<QuantityData*&>(ref));
        return true;
    }
    return false;
}

// @fnv 0x004f2190
bool TESRegionDataImposter::ReadRegionData(TESFile* file)
{
    if (!file)
        return false;
    switch (file->GetChunkID())
    {
    case 0x44494452: {
        unsigned int uiChunkSize = file->GetChunkSize();
        struct ImposterArrayCounts
        {
            unsigned int formIDSize;
            unsigned int count;
        } loadCounts;
        loadCounts.formIDSize = sizeof(unsigned int);
        loadCounts.count = uiChunkSize / loadCounts.formIDSize;
        unsigned int* formIDs = new unsigned int[loadCounts.count];
        file->GetChunkData(formIDs, uiChunkSize);
        for (unsigned int i = 0; i < loadCounts.count; i++)
        {
            unsigned int formID = formIDs[i];
            if (file->IsEndianConversionRequired())
                BSEndian(&formID, EndianSizeTag<4>());
            AddImposter(reinterpret_cast<TESObjectREFR*>(formID));
        }
        delete[] formIDs;
        break;
    }
    default:
        return false;
    }
    return true;
}

// Walks the imposter's reference list, resolving each stored form ID to a TESObjectREFR and removing entries that fail to resolve.
// @fnv 0x004f2290
void TESRegionDataImposter::InitItem(TESForm* form)
{
    struct ImposterResolution
    {
        TESObjectREFR* reference;
        unsigned int formID;
    } entry;
    entry.reference = 0;
    BSSimpleList<TESObjectREFR*>* pList = (BSSimpleList<TESObjectREFR*>*)((TESTopicInfoData*)this)->GetLinkToList();
    while (pList)
    {
        if (pList->GetItem())
        {
            entry.formID = reinterpret_cast<unsigned int>(pList->GetItem());
            TESFile* file = form ? form->GetFile(-1) : 0;
            TESForm::RemapFormIDForFile(entry.formID, file);
            entry.reference = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(entry.formID));
            pList->SetItem(entry.reference);
        }
        if (!entry.reference)
        {
            pList->RemoveHead();
            if (!pList->GetItem())
                break;
        }
        else
        {
            pList = pList->GetNext();
        }
    }
}

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_004f2370_shell
{
    bool ClearList();
};

// @fnv 0x004f2370
bool FUN_004f2370_shell::ClearList()
{
    ((List_009e03e0*)((TESTopicInfoData*)this)->GetLinkToList())->RemoveAll();
    return true;
}

struct T004f1f40
{
    void FUN_004f2040();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_004f2040, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004f1f40
void* T004f1f40::DestroyIfFlagged(unsigned int flags)
{
    FUN_004f2040();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESRegionData
{
    virtual void f0() const;
    virtual void f1() const;
    virtual void f2() const;
    virtual void f3() const;
    virtual void f4() const;
};
struct FUN_004f2450_holder
{
    void CallRegionDataVirtual(const TESRegionData* apRegionData, unsigned int aiTotalBlending);
};
// @fnv 0x004f2450
void FUN_004f2450_holder::CallRegionDataVirtual(const TESRegionData* apRegionData, unsigned int aiTotalBlending)
{
    TESRegionDataImposter* pdataIn = (TESRegionDataImposter*)apRegionData;
    if (apRegionData != 0)
        apRegionData->f4();
}

struct FUN_004f1f70_shell
{
    char m_data[16];
    FUN_004f1f70_shell(const FUN_004f1f70_shell*);
};
struct FUN_004f23d0_shell : FUN_004f1f70_shell
{
    FUN_004f1f70_shell* CreateCopy();
};
// Allocates a new shell object by copy-constructing it from this object and returns the new pointer.
// @fnv 0x004f23d0
FUN_004f1f70_shell* FUN_004f23d0_shell::CreateCopy()
{
    FUN_004f1f70_shell* pdata = new FUN_004f1f70_shell((const FUN_004f1f70_shell*)this);
    return pdata;
}

class FUN_004f2040_sub
{
  public:
    ~FUN_004f2040_sub();
};

class FUN_004f2040_base
{
  public:
    virtual ~FUN_004f2040_base();
    unsigned int unk04;
};

class FUN_004f2040_cls : public FUN_004f2040_base
{
  public:
    void Body();
    FUN_004f2040_sub m_08;
    virtual ~FUN_004f2040_cls();
};

// @fnv 0x004f2040
FUN_004f2040_cls::~FUN_004f2040_cls()
{
    Body();
}

void __cdecl FUN_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_004f20b0_elem
{
    unsigned int Probe();
};
struct FUN_004f20b0_node
{
    FUN_004f20b0_elem** GetItem();
    FUN_004f20b0_node* GetNext();
    int GetSize();
    FUN_004f20b0_elem* item;
    FUN_004f20b0_node* next;
};
struct FUN_004f20b0_cls
{
    int unk00;
    int unk04;
    FUN_004f20b0_node m08;
    void ClearAll();
    void ResetAndCollectProbes();
};
// @fnv 0x004f20b0
void FUN_004f20b0_cls::ResetAndCollectProbes()
{
    ClearAll();
    FUN_004f20b0_elem* pElem = 0;
    int count = m08.GetSize();
    if (count)
    {
        FUN_004f20b0_node* pNode = &m08;
        unsigned int* pProbes = new unsigned int[count];
        for (unsigned int iIndex = 0; pNode && iIndex < (unsigned int)count; iIndex++)
        {
            pElem = *pNode->GetItem();
            unsigned int v2 = pElem->Probe();
            pProbes[iIndex] = v2;
            pNode = pNode->GetNext();
        }
        FUN_00485710(0x44494452, pProbes, count);
        delete pProbes;
    }
}

struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
struct Item4f11
{
    bool FUN_004f81e0(int);
};
struct Node4f11
{
    Item4f11** FUN_006815c0();
};
struct Head4f11
{
    bool FUN_004f3610();
};

class Obj4f11
{
  public:
    char _pad[0x18];
    Head4f11* m_pHead;
    ContNode* m_pNext;
    bool Validate();
};

// Returns false if m_pNext or m_pHead is null, m_pHead->FUN_004f3610() fails, or any node's item fails FUN_004f81e0(1); otherwise true.
// @fnv 0x004f11e0
bool Obj4f11::Validate()
{
    ContNode* pNode = m_pNext;
    if (!m_pNext || !m_pHead)
        return false;
    if (!m_pHead->FUN_004f3610())
        return false;
    while (pNode && *((Node4f11*)pNode)->FUN_006815c0())
    {
        if (!(*((Node4f11*)pNode)->FUN_006815c0())->FUN_004f81e0(1))
            return false;
        pNode = FUN_00726070(pNode);
    }
    return true;
}

struct Callees
{
    void FUN_004f1460(void* param);
    void FUN_0096a2d0();
    void* FUN_00413f40();
    void FUN_00470470();
    void* FUN_006815c0();
    void FUN_00905820(void* item);
    void* FUN_00726070();
};

void Callees::FUN_004f1460(void* /*param*/)
{}
void Callees::FUN_0096a2d0()
{}
void* Callees::FUN_00413f40()
{
    return 0;
}
void Callees::FUN_00470470()
{}
void* Callees::FUN_006815c0()
{
    return 0;
}
void Callees::FUN_00905820(void* /*item*/)
{}
void* Callees::FUN_00726070()
{
    return 0;
}

struct BaseCls
{
    int m_unk04;
    BaseCls(void* param)
    {
        ((Callees*)this)->FUN_004f1460(param);
    }
    virtual ~BaseCls();
};

struct MemberCls
{
    void* m_item;
    MemberCls* m_pkNext;
    MemberCls()
    {
        ((Callees*)this)->FUN_0096a2d0();
    }
    ~MemberCls();
};

struct ParamCls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};

void ParamCls::v0()
{}
void ParamCls::v1()
{}
void ParamCls::v2()
{}
void ParamCls::v3()
{}
int ParamCls::v4()
{
    return 0;
}

struct FUN_004f1f70_cls : BaseCls
{
    MemberCls m_kMemberDescriptor;
    FUN_004f1f70_cls(void* param);
    ~FUN_004f1f70_cls();
};

// Calls FUN_00470470 on the result of this->FUN_00413f40(); if param's v4() is 8, traverses its list and passes each node's item to m_kMemberDescriptor.
// @fnv 0x004f1f70
FUN_004f1f70_cls::FUN_004f1f70_cls(void* param) : BaseCls(param)
{
    ((Callees*)((Callees*)this)->FUN_00413f40())->FUN_00470470();

    void* refr = param;
    if (((ParamCls*)refr)->v4() == 8)
    {
        void* node = ((Callees*)refr)->FUN_00413f40();
        while (node != 0)
        {
            ((Callees*)&m_kMemberDescriptor)->FUN_00905820(((Callees*)node)->FUN_006815c0());
            node = ((Callees*)node)->FUN_00726070();
        }
    }
}

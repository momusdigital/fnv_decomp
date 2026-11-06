// fallout_shared/tesfaction.cpp: TESFaction, Holder, DelStandIn, FakeFaction and more (36 functions)

#include "tesfaction_decls.h"

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern TESDataHandler* g_dataHandler;

// @fnv 0x005fc840
void TESFaction::ClearData()
{
    ClearReactions();
}

// @fnv 0x005fc800
void TESFaction::ResetFormData()
{
    m_iFirstFactionValue = 0;
    m_iSecondFactionValue = 0;
    pReputationData = 0;
    memset(&data, 0, sizeof(data));
}

// Reverts the form from the load buffer, then initializes the reaction's load-game state from the same buffer.
// @fnv 0x005fd7d0
void TESFaction::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))->TESFormBufferAccess::Revert(buffer);
    reinterpret_cast<TESFactionReactionView&>(*this).reaction.TESReactionFormBufferAccess::InitLoadGame(buffer);
}

// @fnv 0x005fd800
void TESFaction::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))->TESFormBufferAccess::Revert(buffer);
    if (buffer->GetOldChangeFlags(0x80000000))
    {
        m_iFirstFactionValue = 0;
        m_iSecondFactionValue = 0;
    }
}

// @fnv 0x005fc860
void TESFaction::ClearReactions()
{
    FactionRankPresentation* rankData;
    while (!GetRankDataList()->IsEmpty())
    {
        rankData = GetRankDataList()->GetItem();
        delete rankData;
        GetRankDataList()->RemoveHead();
    }
}

// @fnv 0x005fcf80
void TESFaction::InitItem()
{
    if (GetInitialized())
        return;

    reinterpret_cast<TESFactionReactionView&>(*this).reaction.TESReactionFormBufferAccess::InitItem(this);
    SetInitializationState(true);
    if (pReputationData != 0)
    {
        unsigned int formID = 0;
        formID = reinterpret_cast<unsigned int>(pReputationData);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        pReputationData = reinterpret_cast<TESDataHandlerAccess*>(g_dataHandler)->GetReputation(formID);
    }
}

// @fnv 0x005fd730
void TESFaction::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))->TESFormBufferAccess::LoadGame(buffer);
    reinterpret_cast<TESFactionReactionView&>(*this).reaction.TESReactionFormBufferAccess::FUN_0048ca90(buffer);
    if (buffer->GetChangeFlags(2))
        buffer->ReadTypedData(&data, 4);
    if (buffer->GetChangeFlags(0x80000000))
    {
        buffer->ReadTypedData(&m_iFirstFactionValue, 4);
        buffer->ReadTypedData(&m_iSecondFactionValue, 4);
    }
}

struct FUN_005fc840_shell : public TESFaction
{
    void FUN_005fc840();
};

// @fnv 0x005fc840
void FUN_005fc840_shell::FUN_005fc840()
{
    ClearReactions();
}

struct FUN_005fc860_shell : public TESFaction
{
    void FUN_005fc860();
};

// Deletes every entry in the rank data list and removes each node until the list is empty.
// @fnv 0x005fc860
void FUN_005fc860_shell::FUN_005fc860()
{
    while (!GetRankDataList()->IsEmpty())
    {
        FactionRankPresentation* rankData = GetRankDataList()->GetItem();
        delete rankData;
        GetRankDataList()->RemoveHead();
    }
}

extern unsigned int _data_011c16bc;
struct SB005fc900
{
    char p[8];
    ~SB005fc900();
};
struct TT005fc900
{
    virtual ~TT005fc900();
    char p[0xc];
};
struct FUN_005fc900 : public SB005fc900
{
    SB005fc900 s;
    TT005fc900 t;
    ~FUN_005fc900();
};
// Destructor for FUN_005fc900 that destroys its embedded SB005fc900 and TT005fc900 members.
// @fnv 0x005fc900
FUN_005fc900::~FUN_005fc900()
{}

struct FUN_005fcf80_shell : public TESFaction
{
    void FUN_005fcf80();
};

class TESReputation;

struct TESFormInitHelper
{
    bool IsFormInitialized() const;
};

struct TESReactionFormInitHelper
{
    void InitItem(TESForm*);
};

struct TESDataHandlerRepHelper
{
    TESReputation* GetReputation(unsigned int);
};

// Initializes the faction's reaction form, marks it initialized, and resolves its reputation from the data handler.
// @fnv 0x005fcf80
void FUN_005fcf80_shell::FUN_005fcf80()
{
    if (reinterpret_cast<const TESFormInitHelper*>(this)->IsFormInitialized())
        return;
    reinterpret_cast<TESReactionFormInitHelper*>(reinterpret_cast<char*>(this) + 0x24)->InitItem(this);
    SetInitializationState(true);
    if (*reinterpret_cast<TESReputation**>(reinterpret_cast<char*>(this) + 0x38) != 0)
    {
        unsigned int uiReputationFormID = 0;
        uiReputationFormID = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x38);
        RemapFormIDForFile(uiReputationFormID, GetFile(-1));
        *reinterpret_cast<TESReputation**>(reinterpret_cast<char*>(this) + 0x38) =
            reinterpret_cast<TESDataHandlerRepHelper*>(g_dataHandler)->GetReputation(uiReputationFormID);
    }
}

struct FUN_005fd3b0_shell : public TESFaction
{
    int GetFactionReaction(TESFaction*);
};

struct Dummy_0048bf50
{
    int FindValueByKey(TESFaction*);
};

// @fnv 0x005fd3b0
int FUN_005fd3b0_shell::GetFactionReaction(TESFaction* pFaction)
{
    return ((Dummy_0048bf50*)((char*)this + 0x24))->FindValueByKey(pFaction);
}

struct Sub005fd430
{
    char pad[0x24];
};
struct F005fd430
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12(int);
    char pad[0x24 - 4];
    void SetFightReaction(F005fd430*, int);
    void SetFactionFightReaction(F005fd430* f, int r);
};
// Forwards f and r to the object at this+0x24 via SetFightReaction, then calls v12(4).
// @fnv 0x005fd430
void F005fd430::SetFactionFightReaction(F005fd430* f, int r)
{
    ((F005fd430*)((char*)this + 0x24))->SetFightReaction(f, r);
    v12(4);
}

struct FUN_005fd460_shell : public TESFaction
{
    int FUN_005fd460();
};

// Counts the entries in the rank data list, appends a new rank data node to the tail (or head if empty), and returns the previous count.
// @fnv 0x005fd460
int FUN_005fd460_shell::FUN_005fd460()
{
    int iElementIndex = 0;
    FactionRankPresentation* pdata = new FactionRankPresentation;
    BSSimpleList<FactionRankPresentation*>* pCurrentElementNext = GetRankDataList();
    BSSimpleList<FactionRankPresentation*>* plastlist = 0;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        ++iElementIndex;
        plastlist = pCurrentElementNext;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    if (plastlist)
    {
        plastlist->AddTail(pdata);
    }
    else
    {
        GetRankDataList()->AddHead(pdata);
    }
    return iElementIndex;
}

struct FUN_005fd730_shell : public TESFaction
{
    void FUN_005fd730(BGSLoadFormBuffer*);
};

// Loads the form, then reads the reaction buffer and, per change flags, reads 4-byte values into offsets 0x34, 0x44 and 0x48.
// @fnv 0x005fd730
void FUN_005fd730_shell::FUN_005fd730(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    ((TESReactionFormBufferAccess*)((char*)this + 0x24))->FUN_0048ca90(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(2))
    {
        apLoadGameBuffer->ReadTypedData((char*)this + 0x34, 4);
    }
    if (apLoadGameBuffer->GetChangeFlags(0x80000000))
    {
        apLoadGameBuffer->ReadTypedData((char*)this + 0x44, 4);
        apLoadGameBuffer->ReadTypedData((char*)this + 0x48, 4);
    }
}

struct FUN_005fd800_shell : public TESFaction
{
    void FUN_005fd800(BGSLoadFormBuffer*);
};

// @fnv 0x005fd800
void FUN_005fd800_shell::FUN_005fd800(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (apLoadGameBuffer->GetOldChangeFlags(0x80000000))
    {
        *(int*)((char*)this + 0x44) = 0;
        *(int*)((char*)this + 0x48) = 0;
    }
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x005fc8d0
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FactionFormBase
{
    unsigned char pad[0x14];
    FactionFormBase();
    ~FactionFormBase();
    virtual void vfn0();
};
struct FactionFullNameBase
{
    unsigned char pad[8];
    FactionFullNameBase();
    ~FactionFullNameBase();
    virtual void vfn0();
};
struct FactionReactionBase
{
    unsigned char pad[0xc];
    FactionReactionBase();
    ~FactionReactionBase();
    virtual void vfn0();
};
struct SL
{
    unsigned char data[8];
    SL();
    ~SL();
};
class FUN_005fc680 : public FactionFormBase, public FactionFullNameBase, public FactionReactionBase
{
  public:
    unsigned int data34;
    void* pReputationData;
    SL m_kRankDataList;
    FUN_005fc680();
    void ResetFormData();
    void SetFormType(int);
};
// @fnv 0x005fc680
FUN_005fc680::FUN_005fc680()
{
    ResetFormData();
    SetFormType(8);
}

namespace fnv_005fc730 {
extern "C" void* __cdecl Deallocate(void*);

struct FUN_005fc730_shell
{
    void FUN_005fc760();
    void* FUN_005fc730(unsigned int flags);
};

// Calls FUN_005fc760, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x005fc730
void* FUN_005fc730_shell::FUN_005fc730(unsigned int flags)
{
    FUN_005fc760();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_005fc730

struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};

struct FUN_0048c2e0_shell
{
    unsigned short __thiscall FUN_0048c2e0(unsigned int);
};

struct FUN_005fd550_shell
{
    unsigned short GetSaveSize(unsigned int);
};

// Returns the sum of the save sizes of the object and its sub-object at offset 0x24, plus 4 when aiFlags has bit 2 set.
// @fnv 0x005fd550
unsigned short FUN_005fd550_shell::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += ((FUN_0048c2e0_shell*)((char*)this + 0x24))->FUN_0048c2e0(aiFlags);
    if (aiFlags & 2)
        isize += 4;
    return isize;
}

struct NiFormArray
{
    unsigned int GetIndexOfForm(TESForm* form);
};

struct FUN_005ff520_shell
{
    unsigned int GetIndexForChild(unsigned int flags);
};

// @fnv 0x005ff520
unsigned int FUN_005ff520_shell::GetIndexForChild(unsigned int apForm)
{
    unsigned int index = 0xffffffff;
    if (*reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x40))
    {
        index = (*reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x40))
                    ->GetIndexOfForm(reinterpret_cast<TESForm*>(apForm));
    }
    return index;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<2>);
struct Class005a6b10
{
    int m0;
    int m1;
    int m2;
    void FUN_005a6b10();
};
// Byte-swaps the three int fields m0, m1 and m2 via BSEndian.
// @fnv 0x005a6b10
void Class005a6b10::FUN_005a6b10()
{
    BSEndian(&m0, EndianSizeTag<2>());
    BSEndian(&m1, EndianSizeTag<2>());
    BSEndian(&m2, EndianSizeTag<2>());
}

struct FUN_0051b070_shell
{
    void FUN_00484c20(unsigned int);
};
struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
struct S24
{
    void WriteReactionList(unsigned int);
};
struct FUN_005fd5c0_shell
{
    void FUN_005fd5c0(unsigned int);
};
// @fnv 0x005fd5c0
void FUN_005fd5c0_shell::FUN_005fd5c0(unsigned int aiFlags)
{
    ((FUN_0051b070_shell*)this)->FUN_00484c20(aiFlags);
    ((S24*)((char*)this + 0x24))->WriteReactionList(aiFlags);
    if (aiFlags & 2)
        ((PC7d*)this)->FUN_00484ce0((unsigned int)((char*)this + 0x34), 4);
}

struct TESFormStub
{
    void FUN_00484c50(unsigned int, unsigned int);
};
struct STR24
{
    void LoadReactions(unsigned int, unsigned int);
};
struct STR00
{
    void FUN_00484d00(void*, unsigned int);
};
struct FUN_005fd610_shell
{
    void FUN_005fd610(unsigned int, unsigned int);
};
// @fnv 0x005fd610
void FUN_005fd610_shell::FUN_005fd610(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    ((TESFormStub*)this)->FUN_00484c50(aiFlags, aiCurrentFlags);
    ((STR24*)((char*)this + 0x24))->LoadReactions(aiFlags, aiCurrentFlags);
    if (aiFlags & 2)
        ((STR00*)this)->FUN_00484d00((void*)((char*)this + 0x34), 4);
}

struct Holder
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
    char _pad[0x30];
    int m_flags;
    void FUN_005fc970(int flag, bool value);
};
// Sets or clears the given bit in m_flags based on value, then calls v18(2).
// @fnv 0x005fc970
void Holder::FUN_005fc970(int flag, bool value)
{
    value ? m_flags |= flag : m_flags &= ~flag;
    v18(2);
}

struct HackReact
{
    void SetReactionValue(struct TESForm* form, int v);
};
struct Unk_005fd3d0
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
    virtual void v18(int v);
    char pad[32];
    HackReact m_hack;
    void SetFactionReaction(struct TESForm* form, int v);
};
// @fnv 0x005fd3d0
void Unk_005fd3d0::SetFactionReaction(struct TESForm* form, int v)
{
    m_hack.SetReactionValue(form, v);
    v18(4);
}

struct Helper_48c0b0
{
    void ModReaction(int, int);
};
struct Outer_5fd400
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
    virtual void v18(int);
    int _pad[8];
    Helper_48c0b0 _h;
    void ModFactionReaction(int, int);
};
// Calls the helper's ModReaction with a and b, then invokes virtual v18 with 4.
// @fnv 0x005fd400
void Outer_5fd400::ModFactionReaction(int aiArg1, int aiArg2)
{
    _h.ModReaction(aiArg1, aiArg2);
    v18(4);
}

namespace fnv_005fd660 {
struct SkyObject
{
    void Update(unsigned int, unsigned int);
};
struct MidObj
{
    void ResolveGroupReactionForms(unsigned int, unsigned int);
};
struct Holder : SkyObject
{
    char _pad[0x24];
    MidObj mid;
    void InitLoadGameTES(unsigned int, unsigned int);
};
// Calls SkyObject::Update and then mid.ResolveGroupReactionForms with the same two arguments.
// @fnv 0x005fd660
void Holder::InitLoadGameTES(unsigned int auiArg1, unsigned int auiArg2)
{
    SkyObject::Update(auiArg1, auiArg2);
    mid.ResolveGroupReactionForms(auiArg1, auiArg2);
}
}  // namespace fnv_005fd660

struct Unk38
{
    void CommitCrime(int);
};
struct FakeFaction
{
    virtual void F00();
    virtual void F01();
    virtual void F02();
    virtual void F03();
    virtual void F04();
    virtual void F05();
    virtual void F06();
    virtual void F07();
    virtual void F08();
    virtual void F09();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void F14();
    virtual void F15();
    virtual void F16();
    virtual void F17();
    virtual void F18(int);
    char pad0[0x34];
    Unk38* p38;
    int pad1[3];
    int i48;
    void ModifyReputation(int aiCount, bool bModRep);
};
// @fnv 0x005fda00
void FakeFaction::ModifyReputation(int aiCount, bool bModRep)
{
    i48 += aiCount;
    if (p38 != 0 && bModRep)
        p38->CommitCrime(0);
    F18(0x80000000);
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct NiAVObject
{
    const void* GetRotate() const;
};
void* __memcpy(void*, const void*, unsigned int);
struct TESTopicInfo
{
    TESSound* GetConversationData();
};
struct BGSAcousticSpace
{
    void SetNoonSound(TESSound*);
};
struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct Flt
{
    operator unsigned int();
};

struct FUN_005fd210_shell : TESFaction
{
    void FUN_005fd210(TESForm* apCopy);
};

// Copies faction data from apCopy: base copy, rotation, noon sound, then deep-copies each rank entry into this faction's rank list.
// @fnv 0x005fd210
void FUN_005fd210_shell::FUN_005fd210(TESForm* apCopy)
{
    BSSimpleList<FactionRankPresentation*>* pDestRankList;
    {
        TESFaction* faction = dynamic_cast<TESFaction*>(apCopy);
        if (!faction)
            return;
        ((FUN_005e78f0_t*)this)->FUN_004851b0(apCopy);
        __memcpy((char*)this + 0x34, ((NiAVObject*)faction)->GetRotate(), 4);
        ((BGSAcousticSpace*)this)->SetNoonSound(((TESTopicInfo*)faction)->GetConversationData());
        ClearReactions();
        pDestRankList = GetRankDataList();
        {
            BSSimpleList<FactionRankPresentation*>* pSourceRankList = faction->GetRankDataList();
            while (pSourceRankList && !pSourceRankList->IsEmpty())
            {
                FactionRankPresentation* pdata = new FactionRankPresentation;
                ((BSStr*)&pdata->m_kMaleRankName)
                    ->Set((const char*)(unsigned int)*(Flt*)&pSourceRankList->GetItem()->m_kMaleRankName, 0);
                ((BSStr*)&pdata->m_kFemaleRankName)
                    ->Set((const char*)(unsigned int)*(Flt*)&pSourceRankList->GetItem()->m_kFemaleRankName, 0);
                pdata->m_kRankTexture.CopyFromBase(&pSourceRankList->GetItem()->m_kRankTexture);
                pDestRankList->AddTail(pdata);
                if (pDestRankList->GetNext())
                    pDestRankList = (BSSimpleList<FactionRankPresentation*>*)pDestRankList->GetNext();
                pSourceRankList = (BSSimpleList<FactionRankPresentation*>*)pSourceRankList->GetNext();
            }
        }
    }
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    void SaveIfChanged(BGSSaveFormBuffer*);
    void FUN_0048c9d0(BGSSaveFormBuffer*);
    FormChangeMask GetChangeFlags(unsigned int);
};
struct FUN_005fd690_s
{
    void AppendSaveLoadFormBuffer(BGSSaveFormBuffer* buffer);
};
// @fnv 0x005fd690
void FUN_005fd690_s::AppendSaveLoadFormBuffer(BGSSaveFormBuffer* buffer)
{
    ((BGSSaveFormBuffer*)this)->SaveIfChanged(buffer);
    ((BGSSaveFormBuffer*)((char*)this + 0x24))->FUN_0048c9d0(buffer);
    if (buffer->GetChangeFlags(2))
        buffer->SaveData((char*)this + 0x34, 4, 0);
    if (buffer->GetChangeFlags(0x80000000))
    {
        buffer->SaveData((char*)this + 0x44, 4, 0);
        buffer->SaveData((char*)this + 0x48, 4, 0);
    }
}

namespace fnv_005fd850 {
int __fastcall FUN_00871a30(int);
int __fastcall FNV_GetFormType(TESForm*);
void FNV_Warning(const char*, ...);
struct Node_006815c0
{
    void** _ref_006815c0();
};
struct TgtOps
{
    void* GetPosition();
};
struct _FactionSub
{
    int FUN_0048c1b0(TESFaction*);
};
struct F005fd430
{
    void SetFactionFightReaction(F005fd430*, int);
};
struct Reaction_5fd850
{
    TESFaction* pFaction;
    int iMod;
    int eReaction;
};
// Iterates all factions and their reactions; for friend/ally reactions not reciprocated, warns and forces the other faction to be a friend.
// @fnv 0x005fd850
void ValidateFactionReactions()
{
    BSSimpleList<TESFaction*>* pIter = (BSSimpleList<TESFaction*>*)FUN_00871a30((int)g_dataHandler);
    while (pIter)
    {
        TESFaction* pFaction = (TESFaction*)*((Node_006815c0*)pIter)->_ref_006815c0();
        if (pFaction)
        {
            BSSimpleList<Reaction_5fd850*>* pRIter =
                (BSSimpleList<Reaction_5fd850*>*)((TgtOps*)((char*)pFaction + 0x24))->GetPosition();
            while (pRIter)
            {
                Reaction_5fd850* pReaction = (Reaction_5fd850*)*((Node_006815c0*)pRIter)->_ref_006815c0();
                if (pReaction && pReaction->pFaction && FNV_GetFormType((TESForm*)pReaction->pFaction) == 8 &&
                    (pReaction->eReaction == 3 || pReaction->eReaction == 2))
                {
                    TESFaction* pOther = pReaction->pFaction;
                    int iFactionReaction = ((_FactionSub*)((char*)pOther + 0x24))->FUN_0048c1b0(pFaction);
                    if (iFactionReaction != 2 && iFactionReaction != 3)
                    {
                        FNV_Warning(
                            "DEFAULT: (Faction Reaction Error) Faction '%s' (%08X) is a Friend or Ally of Faction '%s' (%08X), but Faction '%s' (%08X) is not a Friend or Ally of Faction '%s' (%08X). Faction '%s'(%08X) will be forced to be a Friend of Faction '%s' (%08X) ",
                            pFaction->GetName(), pFaction->GetFormID(), pOther->GetName(), pOther->GetFormID(),
                            pOther->GetName(), pOther->GetFormID(), pFaction->GetName(), pFaction->GetFormID(),
                            pOther->GetName(), pFaction->GetName(), pFaction->GetName(), pFaction->GetFormID());
                        ((F005fd430*)pOther)->SetFactionFightReaction((F005fd430*)pFaction, 3);
                    }
                }
                pRIter = pRIter->GetNext();
            }
        }
        pIter = pIter->GetNext();
    }
}
}  // namespace fnv_005fd850

struct ListX
{
    ~ListX();
};

struct Base5a
{
    virtual ~Base5a();
    char padding[0x14];
};

struct FUN_00591300
{
    virtual ~FUN_00591300();
    char padding[8];
};

struct FUN_0048ba70
{
    virtual ~FUN_0048ba70();
    char padding[0x14];
};

struct FUN_005fc760 : public Base5a, public FUN_00591300, public FUN_0048ba70
{
    ListX m_kReactionList;

    ~FUN_005fc760();
};

// Destructor that calls TESFaction::ClearData on this object.
// @fnv 0x005fc760
FUN_005fc760::~FUN_005fc760()
{
    reinterpret_cast<TESFaction*>(this)->TESFaction::ClearData();
}

struct RankTitle : BSStringT<char>
{
    unsigned int GetLength();
    operator const char*() const;
};
struct RankInsignia : TESTexture
{
    unsigned int GetModelLength();
    const char* GetTextureResourceName();
};
class TESReputation
{
  public:
    unsigned int GetSaveFormID();
};
struct FullNameSaver : TESFullName
{
    void SaveName();
};
struct ReactionSaver : TESReactionForm
{
    void SaveReactions();
};
bool IsSaveEndianSwap();
void SaveChunkValue(unsigned int chunk, unsigned int value);
void SaveChunkData(unsigned int chunk, const void* data, unsigned int size);

struct TESFactionSaveShell : TESForm, FullNameSaver, ReactionSaver
{
    FactionSaveData data;
    TESReputation* pReputationData;
    BSSimpleList<FactionRankPresentation*> m_kRankDataList;
    int m_iFirstFactionValue;
    int m_iSecondFactionValue;
    BSSimpleList<FactionRankPresentation*>* GetRankDataList();
    void BeginSaveForm();
    void EndSaveForm();
    void SaveChunk(void* data, int size);
    void SaveFactionData();
};

// @fnv 0x005fc9d0
void TESFactionSaveShell::SaveFactionData()
{
    BeginSaveForm();
    SaveName();
    SaveReactions();
    if (IsSaveEndianSwap())
        data.Endian();
    SaveChunk(&data, 4);
    if (IsSaveEndianSwap())
        data.Endian();
    int iRankIndex = 0;
    BSSimpleList<FactionRankPresentation*>* pNode = GetRankDataList();
    while (pNode && !pNode->IsEmpty())
    {
        FactionRankPresentation* pRank = pNode->GetItem();
        SaveChunkValue(0x4d414e52, iRankIndex);
        if (static_cast<RankTitle&>(pRank->m_kMaleRankName).GetLength())
            SaveChunkData(0x4d414e4d, (const char*)static_cast<RankTitle&>(pRank->m_kMaleRankName),
                          static_cast<RankTitle&>(pRank->m_kMaleRankName).GetLength() + 1);
        if (static_cast<RankTitle&>(pRank->m_kFemaleRankName).GetLength())
            SaveChunkData(0x4d414e46, (const char*)static_cast<RankTitle&>(pRank->m_kFemaleRankName),
                          static_cast<RankTitle&>(pRank->m_kFemaleRankName).GetLength() + 1);
        if (static_cast<RankInsignia&>(pRank->m_kRankTexture).GetModelLength())
            SaveChunkData(0x4d414e49, static_cast<RankInsignia&>(pRank->m_kRankTexture).GetTextureResourceName(),
                          static_cast<RankInsignia&>(pRank->m_kRankTexture).GetModelLength() + 1);
        iRankIndex++;
        pNode = pNode->GetNext();
    }
    if (pReputationData)
    {
        unsigned int uiRepID = pReputationData->GetSaveFormID();
        SaveChunkValue(0x31494d57, uiRepID);
    }
    EndSaveForm();
}

class TESTexture1024 : public TESTexture
{
  public:
    void SetTexture(const char* path);
};

class FactionLoader : public TESFaction
{
  public:
    bool LoadFactionRecord(TESFile* file);
};

// Reads a faction record's chunks (editor ID, bounds, full name, reactions, flags, ranks, reputation) from file until no chunks remain and returns true.
// @fnv 0x005fcb70
bool FactionLoader::LoadFactionRecord(TESFile* file)
{
    FactionRankPresentation* rankData = NULL;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case CHUNK_ID_EDID_ID: {
            char* pEditorId = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pEditorId, 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_FULL_ID:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case CHUNK_ID_XNAM_ID: {
            ReactionInfo* reaction = new ReactionInfo;
            file->GetChunkData(reaction, 0xC);
            if (file->IsEndianConversionRequired())
            {
                reaction->Endian();
            }
            ((TESReactionFormLoader*)((char*)this + 0x24))->GetReactionList()->AddTail(reaction);
            break;
        }
        case 0x41544144: {  // DATA
            if (reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion() < 9)
            {
                char byteData;
                reinterpret_cast<TESFactionRecordLoader*>(this)->ReadTypedData(file, &byteData, 1);
                data.iFlags = byteData;
            }
            else
            {
                reinterpret_cast<TESFactionRecordLoader*>(this)->ReadTypedData(file, &data, 4);
                if (file->IsEndianConversionRequired())
                {
                    data.Endian();
                }
            }
            break;
            break;
        }
        case 0x4D414E52: {  // RNAM
            rankData = ::new FactionRankPresentation;
            GetRankDataList()->AddTail(rankData);
            break;
        }
        case 0x4D414E4D: {  // MNAM
            if (rankData)
            {
                char* pMaleRank = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(pMaleRank, 0);
                rankData->m_kMaleRankName.Set(pMaleRank, 0);
            }
            break;
        }
        case CHUNK_ID_FNAM_ID: {
            if (rankData)
            {
                char* pFemaleRank = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(pFemaleRank, 0);
                rankData->m_kFemaleRankName.Set(pFemaleRank, 0);
            }
            break;
        }
        case 0x4D414E49: {  // INAM
            if (rankData)
            {
                char* pInsignia = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(pInsignia, 0);
                reinterpret_cast<TESTexture1024*>(&rankData->m_kRankTexture)->SetTexture(pInsignia);
            }
            break;
        }
        case 0x31494D57: {  // WMI1
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            if (formID)
            {
                pReputationData = (TESReputation*)formID;
            }
            break;
        }
        default:
            break;
        }
    } while (file->NextChunk());
    return true;
}

#include <string.h>
struct FactionCompareAccess : TESFaction
{
    bool FUN_00485270(TESForm*);
    const FactionSaveData* FUN_006a9540();
    TESReputation* GetField38();
    BSSimpleList<FactionRankPresentation*>* FUN_005a8080();
    bool IsDifferentFrom(TESForm* other);
};

struct RankStringAccess : BSStringT<char>
{
    unsigned int FUN_004048e0() const;
    const char* FUN_00559450() const;
    int FUN_00408a80(const char*, bool) const;
};

// Returns true if this faction differs from other in save data, reputation, or rank presentation lists; false if identical.
// @fnv 0x005fd000
bool FactionCompareAccess::IsDifferentFrom(TESForm* other)
{
    FactionCompareAccess* faction2 = static_cast<FactionCompareAccess*>(dynamic_cast<TESFaction*>(other));
    if (!faction2)
        return true;
    if (FUN_00485270(faction2))
        return true;
    if (memcmp(&data, faction2->FUN_006a9540(), 4))
        return true;
    if (pReputationData != faction2->GetField38())
        return true;

    BSSimpleList<FactionRankPresentation*>* node1 = FUN_005a8080();
    BSSimpleList<FactionRankPresentation*>* node2 = faction2->FUN_005a8080();
    while (node1 && !node1->IsEmpty())
    {
        if (!node2 || !node2->GetItem())
            return true;
        FactionRankPresentation* current2 = node1->GetItem();
        FactionRankPresentation* current = node2->GetItem();
        if (static_cast<RankStringAccess&>(current2->m_kMaleRankName).FUN_004048e0() ||
            static_cast<RankStringAccess&>(current->m_kMaleRankName).FUN_004048e0())
        {
            if (static_cast<RankStringAccess&>(current2->m_kMaleRankName).FUN_004048e0() !=
                static_cast<RankStringAccess&>(current->m_kMaleRankName).FUN_004048e0())
                return true;
            else if (static_cast<RankStringAccess&>(current2->m_kMaleRankName)
                         .FUN_00408a80(static_cast<RankStringAccess&>(current->m_kMaleRankName).FUN_00559450(), false))
                return true;
        }
        if (static_cast<RankStringAccess&>(current2->m_kFemaleRankName).FUN_004048e0() ||
            static_cast<RankStringAccess&>(current->m_kFemaleRankName).FUN_004048e0())
        {
            if (static_cast<RankStringAccess&>(current2->m_kFemaleRankName).FUN_004048e0() !=
                static_cast<RankStringAccess&>(current->m_kFemaleRankName).FUN_004048e0())
                return true;
            else if (static_cast<RankStringAccess&>(current2->m_kFemaleRankName)
                         .FUN_00408a80(static_cast<RankStringAccess&>(current->m_kFemaleRankName).FUN_00559450(),
                                       false))
                return true;
        }
        if (current2->m_kRankTexture.CompareWithBase(&current->m_kRankTexture))
            return true;
        node1 = node1->GetNext();
        node2 = node2->GetNext();
    }
    if (node2 && !node2->IsEmpty())
        return true;
    return false;
}

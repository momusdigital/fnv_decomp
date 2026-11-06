
// src/fallout/magic/associateditemeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/associateditemeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Actor;
struct FUN_00806da0_shell
{
    unsigned short FUN_00806da0(Actor* apActor);
};
struct ActiveEffect
{
    unsigned short __thiscall GetSaveSize(Actor* apActor);
};

// Returns the ActiveEffect save size for apActor plus 4 bytes.
// @fnv 0x00806da0
unsigned short FUN_00806da0_shell::FUN_00806da0(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ((ActiveEffect*)this)->GetSaveSize(apActor);
    isize += 4;
    return isize;
}

struct ActiveEffect_LoadGame_Helper
{
    void LoadGame(Actor*);
};
struct TESSaveLoadGame
{
    void FUN_00857aa0(unsigned int*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct AssociatedItemEffect
{
    char _pad0[0x48];
    unsigned int _p48;
    void FUN_00806e30(Actor* apActor);
};
// Calls LoadGame on the effect, reads a 4-byte form ID from the save game, and stores it in _p48.
// @fnv 0x00806e30
void AssociatedItemEffect::FUN_00806e30(Actor* apActor)
{
    unsigned int iformID;
    ((ActiveEffect_LoadGame_Helper*)this)->LoadGame(apActor);
    g_TESSaveLoadGame->FUN_00857aa0(&iformID, 4);
    _p48 = iformID;
}

namespace fnv_00806e70 {
struct Actor;
struct TESForm;
extern "C" TESForm* __cdecl _ref_004839c0(int);
struct InitLoadGameHelper
{
    void __thiscall InitLoadGame(Actor* apActor);
};
struct AssociatedItemEffect : ActiveEffect
{
    TESForm* m_pAssociatedForm;
    void __thiscall FUN_00806e70(Actor* apActor);
};
// Calls InitLoadGame on this, then replaces the TESForm pointer at offset 0x48 with the result of _ref_004839c0 if it is non-null.
// @fnv 0x00806e70
void __thiscall AssociatedItemEffect::FUN_00806e70(Actor* apActor)
{
    ((InitLoadGameHelper*)this)->InitLoadGame(apActor);
    TESForm* form = *(TESForm**)((char*)this + 0x48);
    if (form)
        *(TESForm**)((char*)this + 0x48) = _ref_004839c0((int)form);
}
}  // namespace fnv_00806e70

namespace fnv_00806de0 {
struct TESForm
{
    unsigned int __thiscall _ref_0084e3a0();
};
struct TESSaveLoadGame
{
    void __thiscall FUN_00857a10(unsigned int*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct ActiveEffect_SaveGame_helper
{
    void __thiscall SaveGame(Actor* apActor);
};
struct AssociatedItemEffect
{
    unsigned char _pad[0x48];
    TESForm* m_pAssociatedForm;
    void __thiscall FUN_00806de0(Actor* apActor);
};
// @fnv 0x00806de0
void __thiscall AssociatedItemEffect::FUN_00806de0(Actor* apActor)
{
    ((ActiveEffect_SaveGame_helper*)this)->SaveGame(apActor);
    unsigned int iformID = 0;
    if (m_pAssociatedForm)
        iformID = m_pAssociatedForm->_ref_0084e3a0();
    g_TESSaveLoadGame->FUN_00857a10(&iformID, 4);
}
}  // namespace fnv_00806de0

struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct ItemEffectClone
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
    virtual void CopyTo(ItemEffectClone* apTarget);

    int unk04;
    MagicItem* pSpell;
    EffectItem* pEffectItem;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    MagicCaster* m_pEffectInstance;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;

    ItemEffectClone(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffectItem);
    ItemEffectClone* Clone();
};

// Allocates a new ItemEffectClone from this object's caster, spell and effect item, copies this object's data into it, and returns the clone.
// @fnv 0x00806ca0
ItemEffectClone* ItemEffectClone::Clone()
{
    ItemEffectClone* pEffect = new ItemEffectClone(m_pEffectInstance, pSpell, pEffectItem);
    CopyTo(pEffect);
    return pEffect;
}

extern char DAT_0107951c;

struct FUN_00806c20_helper2
{
    void* FUN_005f5f80();
};

struct FUN_00806c20_helper1
{
    FUN_00806c20_helper2* FUN_00825c00();
};

struct FUN_00806c20_base
{
    FUN_00806c20_base(void* a1, void* a2, FUN_00806c20_helper1* a3);
    ~FUN_00806c20_base();
};

struct FUN_00806c20_cls : FUN_00806c20_base
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* m_48;
    FUN_00806c20_cls(void* a1, void* a2, FUN_00806c20_helper1* a3);
};

// Sets the vtable pointer and stores the pointer returned by a3->FUN_00825c00()->FUN_005f5f80() into m_48.
// @fnv 0x00806c20
FUN_00806c20_cls::FUN_00806c20_cls(void* a1, void* a2, FUN_00806c20_helper1* a3) : FUN_00806c20_base(a1, a2, a3)
{
    m_vptr = &DAT_0107951c;
    FUN_00806c20_helper2* tmp = a3->FUN_00825c00();
    m_48 = tmp->FUN_005f5f80();
}

extern "C" unsigned int DAT_011a0d1c;
extern "C" unsigned int DAT_011a0d60;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

struct AssociatedItemBaseCopyCall
{
    void FUN_00804090(::ActiveEffect* target);
};

struct AssociatedItemCopyEntry : ::AssociatedItemEffect
{
    void CopyData(::ActiveEffect* target);
};

// Calls the base routine with target, obtains an AssociatedItemEffect from target, and copies _p48 into it.
// @fnv 0x00806d50
void AssociatedItemCopyEntry::CopyData(::ActiveEffect* target)
{
    reinterpret_cast<AssociatedItemBaseCopyCall*>(this)->FUN_00804090(target);
    ::AssociatedItemEffect* destination =
        static_cast< ::AssociatedItemEffect*>(FUN_00ec43fb(target, 0, &DAT_011a0d1c, &DAT_011a0d60, 0));
    if (destination)
        destination->_p48 = _p48;
}

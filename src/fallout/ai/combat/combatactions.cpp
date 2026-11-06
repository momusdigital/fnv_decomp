// fallout/ai/combat/combatactions.cpp: CombatAction, CombatActionStandIn, CombatActionAttackRangedExplosive, CombatActionMoveStandIn and more (83 functions)

#include "combatactions_packet.h"
// Constructs a CombatActionIgnoreBlockedTarget by initializing the base CombatAction with the given action and calling FUN_0097adc0(6, 0).
// @fnv 0x0097cc80
CombatActionIgnoreBlockedTarget::CombatActionIgnoreBlockedTarget(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097adc0(6, 0);
}
// Ensures the list at DAT_011f13d0[index] exists, then appends action to it.
// @fnv 0x0097ab30
void CombatActionAttackRangedExplosive::Execute(int index, CombatAction* action)
{
    if (!DAT_011f13d0[index])
    {
        DAT_011f13d0[index] = new BSSimpleList<CombatAction*>;
    }
    DAT_011f13d0[index]->AddTail(action);
}
// Forwards the state and value to Effects.AddSoundEntry.
// @fnv 0x0097adc0
void CombatAction::FUN_0097adc0(int state, int value)
{
    Effects.AddSoundEntry(state, value);
}
// Forwards the state and value arguments to AddSoundEntry on the member object.
// @fnv 0x0097ade0
void CombatAction::FUN_0097ade0(int state, int value)
{
    m_kFirstSoundEntryNode.AddSoundEntry(state, value);
}
// Forwards state and value to AddSoundEntry on the member object.
// @fnv 0x0097bc60
void CombatAction::FUN_0097bc60(int state, int value)
{
    m_kSecondSoundEntryNode.AddSoundEntry(state, value);
}
// @fnv 0x0097c070
void CombatAction::FUN_0097c070(int state)
{
    m_kActionWorldStateNode.RemoveItemByOwner(state);
}
// @fnv 0x0097c240
void CombatAction::FUN_0097c240(int state)
{
    Effects.RemoveItemByOwner(state);
}
// @fnv 0x0097c260
void CombatAction::FUN_0097c260(int state)
{
    m_kFirstSoundEntryNode.RemoveItemByOwner(state);
}
// @fnv 0x0097ad10
CombatActionAttackRanged::CombatActionAttackRanged(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(3, 0);
    FUN_00984390(5, 1);
    FUN_00984390(6, 0);
    FUN_00984390(11, 1);
    FUN_00984390(10, 1);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097aeb0
CombatActionAttackRangedFromCover::CombatActionAttackRangedFromCover(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(4, 1);
    FUN_0097ade0(7, 0);
    FUN_00984390(11, 1);
    FUN_00984390(10, 1);
    FUN_00984390(1, 2);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b0b0
CombatActionAttackRangedExplosive::CombatActionAttackRangedExplosive(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(3, 0);
    FUN_0097ade0(8, 0);
    FUN_00984390(5, 1);
    FUN_00984390(6, 0);
    FUN_00984390(11, 0);
    FUN_00984390(10, 0);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b280
CombatActionAttackRangedExplosiveFromCover::CombatActionAttackRangedExplosiveFromCover(COMBAT_ACTION action)
    : CombatAction(action)
{
    FUN_0097ade0(18, 0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(4, 1);
    FUN_0097ade0(8, 0);
    FUN_0097ade0(7, 0);
    FUN_00984390(11, 0);
    FUN_00984390(10, 0);
    FUN_00984390(1, 2);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b350
CombatActionAttackMelee::CombatActionAttackMelee(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 17);
    FUN_0097ade0(3, 0);
    FUN_0097ade0(18, 18);
    FUN_00984390(11, 2);
    FUN_00984390(10, 2);
    FUN_00984390(1, 1);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b4e0
CombatActionAttackHandToHand::CombatActionAttackHandToHand(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 17);
    FUN_0097ade0(3, 0);
    FUN_0097ade0(18, 18);
    FUN_00984390(11, 6);
    FUN_00984390(10, 6);
    FUN_00984390(1, 1);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b620
CombatActionAttackGrenade::CombatActionAttackGrenade(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(3, 0);
    FUN_0097ade0(8, 0);
    FUN_00984390(5, 1);
    FUN_00984390(11, 3);
    FUN_00984390(10, 3);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097b7a0
CombatActionAttackGrenadeFlushTarget::CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(8, 0);
    FUN_0097ade0(7, 0);
    FUN_00984390(11, 3);
    FUN_00984390(10, 3);
    FUN_0097adc0(9, 1);
}
// @fnv 0x0097b9e0
CombatActionAttackGrenadeFromCover::CombatActionAttackGrenadeFromCover(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(4, 1);
    FUN_0097ade0(8, 0);
    FUN_0097ade0(7, 0);
    FUN_00984390(11, 3);
    FUN_00984390(10, 3);
    FUN_00984390(1, 2);
    FUN_0097adc0(0, 1);
}
// @fnv 0x0097bbd0
CombatActionMove::CombatActionMove(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 17);
    FUN_00984390(10, -65512);
    FUN_0097adc0(1, -1);
    FUN_0097bc60(6, 0);
}
// @fnv 0x0097bfe0
CombatActionMoveAndSwitchToMelee::CombatActionMoveAndSwitchToMelee(COMBAT_ACTION action) : CombatActionMove(action)
{
    FUN_0097c070(10);
    FUN_0097ade0(12, 2);
    FUN_0097bc60(11, 2);
    FUN_0097bc60(10, 2);
}
// @fnv 0x0097c170
CombatActionMoveAndAttackRanged::CombatActionMoveAndAttackRanged(COMBAT_ACTION action)
    : CombatActionAttackRanged(action)
{
    FUN_0097c260(3);
    FUN_0097c260(18);
    FUN_0097c070(1);
    FUN_0097c070(6);
    FUN_0097c070(5);
    FUN_0097c240(0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(15, 0);
    FUN_0097adc0(1, -1);
    FUN_0097bc60(6, 0);
}
// @fnv 0x0097c3a0
CombatActionMoveAndAttackRangedExplosive::CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION action)
    : CombatActionAttackRangedExplosive(action)
{
    FUN_0097c260(3);
    FUN_0097c260(18);
    FUN_0097c070(1);
    FUN_0097c070(6);
    FUN_0097c070(5);
    FUN_0097c240(0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(15, 0);
    FUN_0097adc0(1, -1);
    FUN_0097bc60(6, 0);
}
// @fnv 0x0097c560
CombatActionMoveAndAttackGrenade::CombatActionMoveAndAttackGrenade(COMBAT_ACTION action)
    : CombatActionAttackGrenade(action)
{
    FUN_0097c260(3);
    FUN_0097c070(1);
    FUN_0097c070(6);
    FUN_0097c070(5);
    FUN_0097c240(0);
    FUN_0097ade0(18, 17);
    FUN_0097ade0(15, 0);
    FUN_0097adc0(1, -1);
    FUN_0097bc60(6, 0);
}
// @fnv 0x0097c700
CombatActionDrawWeapon::CombatActionDrawWeapon(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(12, -1);
    FUN_0097ade0(10, 7);
    FUN_0097adc0(11, -1);
    FUN_0097adc0(10, -1);
}
// @fnv 0x0097c850
CombatActionSwitchWeapon::CombatActionSwitchWeapon(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(12, -1);
    FUN_0097adc0(11, -1);
    FUN_0097adc0(10, -1);
}
// @fnv 0x0097c9d0
CombatActionAvoidThreat::CombatActionAvoidThreat(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 17);
    FUN_00984390(1, 14);
    FUN_0097adc0(14, 0);
}
// @fnv 0x0097ca60
CombatActionSearch::CombatActionSearch(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_0097ade0(18, 17);
    FUN_00984390(10, -65512);
    FUN_0097adc0(3, 0);
}
// @fnv 0x0097cb70
CombatActionInvestigate::CombatActionInvestigate(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_00984390(10, -65512);
    FUN_00984390(1, 15);
    FUN_0097adc0(3, 0);
}
// @fnv 0x0097cc00
CombatActionDodge::CombatActionDodge(COMBAT_ACTION action) : CombatAction(action)
{
    FUN_00984390(1, 3);
    FUN_0097adc0(6, 0);
}

struct FUN_0097ae90_Class
{
    char pad[0xbc];
    int field_bc;
    int get()
    {
        return field_bc;
    }
};

// @fnv 0x0097ae90
int __fastcall GetFieldBC(FUN_0097ae90_Class* pThis)
{
    return pThis->field_bc;
}

struct FUN_0097d130_shell : public CombatAction
{
    FUN_0097d130_shell(CombatAction::COMBAT_ACTION aeType);
};
// @fnv 0x0097d130
FUN_0097d130_shell::FUN_0097d130_shell(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_0097ade0(3, 0);
    FUN_00984390(1, 0);
    FUN_0097adc0(6, 0);
    FUN_0097adc0(5, 1);
}

struct FUN_0097d1c0_shell : public CombatAction
{
    FUN_0097d1c0_shell(CombatAction::COMBAT_ACTION aeType);
};
// @fnv 0x0097d1c0
FUN_0097d1c0_shell::FUN_0097d1c0_shell(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_0097ade0(3, 0);
    FUN_00984390(1, 13);
    FUN_0097adc0(5, 1);
}

extern int DAT_0108cdd4;
struct FUN_0097d250_shell : public CombatAction
{
    FUN_0097d250_shell(CombatAction::COMBAT_ACTION aeType);
};
// Constructs a CombatAction of the given type, then calls FUN_00984390(1, 10) and FUN_0097adc0(0x11, -1).
// @fnv 0x0097d250
FUN_0097d250_shell::FUN_0097d250_shell(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_00984390(1, 10);
    FUN_0097adc0(0x11, -1);
}

struct FUN_00984390_shell : public CombatAction
{
    void FUN_00984390(int, int);
};

// Forwards aeState and aiValue to AddSoundEntry on the object at offset 0xc of this combat action.
// @fnv 0x00984390
void FUN_00984390_shell::FUN_00984390(int aeState, int aiValue)
{
    ((CombatWorldStateListNode*)((char*)this + 0xc))->AddSoundEntry(aeState, aiValue);
}

class FUN_0097cd30 : public CombatAction
{
  public:
    FUN_0097cd30(CombatAction::COMBAT_ACTION aeType);
    virtual void vfn_0();
};
// Constructs a CombatAction with the given action type, then calls FUN_00984390(1, 0xc) and FUN_0097adc0(0xf, 0).
// @fnv 0x0097cd30
FUN_0097cd30::FUN_0097cd30(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_00984390(1, 0xc);
    FUN_0097adc0(0xf, 0);
}

struct FUN_0097ce90 : CombatAction
{
    FUN_0097ce90(COMBAT_ACTION aeType);
};
// Constructs the combat action with aeType, then calls FUN_00984390(1, -1) and FUN_0097adc0(13, -1).
// @fnv 0x0097ce90
FUN_0097ce90::FUN_0097ce90(COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_00984390(1, -1);
    FUN_0097adc0(13, -1);
}

class FUN_0097cfe0 : public CombatAction
{
  public:
    FUN_0097cfe0(CombatAction::COMBAT_ACTION aeType);
};
// @fnv 0x0097cfe0
FUN_0097cfe0::FUN_0097cfe0(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    FUN_00984390(0xd, -1);
    FUN_0097adc0(0x10, -1);
}

// @fnv 0x0097b050
unsigned int __fastcall GetFieldValue(unsigned int* pThis)
{
    return pThis[0x39];
}

struct FUN_0097d110_shell
{
    int __thiscall GetAt(int index);
};

// @fnv 0x0097d110
int __thiscall FUN_0097d110_shell::GetAt(int index)
{
    return *(int*)((int)this + index * 4 + 0x1a4);
}

struct CombatController;
double __cdecl GetWeaponDPSDeficit(CombatController*, int);

struct RangedFromCoverStandIn
{
    double FUN_00979e40(CombatController*, int);
    float FUN_0097b070(CombatController* apCombatController, int aiActionValue);
};

// Returns the sum of FUN_00979e40(apCombatController, aiActionValue) and GetWeaponDPSDeficit(apCombatController, 1).
// @fnv 0x0097b070
float RangedFromCoverStandIn::FUN_0097b070(CombatController* apCombatController, int aiActionValue)
{
    return FUN_00979e40(apCombatController, aiActionValue) + GetWeaponDPSDeficit(apCombatController, 1);
}

namespace fnv_0097b240 {
struct CombatController;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097b240_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097b240(CombatController* c, int v);
};
// @fnv 0x0097b240
float FUN_0097b240_cls::FUN_0097b240(CombatController* apController, int v)
{
    return FUN_00979e40(apController, v) + GetWeaponDPSDeficit(apController, 0);
}
}  // namespace fnv_0097b240

namespace fnv_0097b4a0 {
struct CombatController;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097b4a0_cls
{
    float FUN_00979e40(CombatController*, int);
    float GetCost(CombatController* c, int v);
};
// Returns the sum of FUN_00979e40(c, v) and GetWeaponDPSDeficit(c, 2).
// @fnv 0x0097b4a0
float FUN_0097b4a0_cls::GetCost(CombatController* apController, int v)
{
    return FUN_00979e40(apController, v) + GetWeaponDPSDeficit(apController, 2);
}
}  // namespace fnv_0097b4a0

namespace fnv_0097b5a0 {
struct CombatController;
struct Weap;
struct ActH2
{
    Weap* GetActiveWeapon();
};
struct Actor
{
    bool IsPlayerTeammate();
};
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
struct FUN_0097b5a0_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097b5a0(CombatController* c, int v);
};
// @fnv 0x0097b5a0
float FUN_0097b5a0_cls::FUN_0097b5a0(CombatController* c, int iValue)
{
    if (((TESAmmoInitCalls*)c)->GetFieldBC() && ((TESAmmoInitCalls*)c)->GetFieldBC()->IsPlayerTeammate() &&
        ((ActH2*)((TESAmmoInitCalls*)c)->GetFieldBC())->GetActiveWeapon())
        return DAT_0108cb10;
    return FUN_00979e40(c, iValue) + GetWeaponDPSDeficit(c, 6);
}
}  // namespace fnv_0097b5a0

struct Tile
{
    bool FUN_0099ac20();
};
struct CombatController;
struct CombatStateArray;
struct IMH
{
    Tile* FUN_00586150(int);
};
struct FUN_0097b840_cls
{
    bool FUN_00979e90(CombatController*, CombatStateArray*, int);
    bool FUN_0097b840(CombatController* c, CombatStateArray* w, int v);
};
// @fnv 0x0097b840
bool FUN_0097b840_cls::FUN_0097b840(CombatController* apController, CombatStateArray* w, int aiValue)
{
    if (!FUN_00979e90(apController, w, aiValue))
        return false;
    return ((IMH*)apController)->FUN_00586150(0xb)->FUN_0099ac20();
}

struct B006815c0
{
    void _ref_006815c0();
};

struct FUN_0097b940_shell
{
    void FUN_0097b940();
};

// @fnv 0x0097b940
void FUN_0097b940_shell::FUN_0097b940()
{
    reinterpret_cast<B006815c0*>(this)->_ref_006815c0();
}

struct FUN_0097b960_shell
{
    unsigned char GetByte76();
};

// @fnv 0x0097b960
unsigned char FUN_0097b960_shell::GetByte76()
{
    return *(reinterpret_cast<unsigned char*>(this) + 0x76);
}

namespace fnv_0097b980 {
struct CombatController;
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097b980_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097b980(CombatController* c, int v);
};
// @fnv 0x0097b980
float FUN_0097b980_cls::FUN_0097b980(CombatController* apCombatController, int v)
{
    float attack = GetWeaponDPSDeficit(apCombatController, 3);
    if (attack >= DAT_0108cb10)
        return DAT_0108cb10;
    return FUN_00979e40(apCombatController, v) + attack;
}
}  // namespace fnv_0097b980

namespace fnv_0097bb90 {
struct CombatController;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097bb90_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097bb90(CombatController* c, int v);
};
// Returns the sum of FUN_00979e40(c, v) and GetWeaponDPSDeficit(c, 3).
// @fnv 0x0097bb90
float FUN_0097bb90_cls::FUN_0097bb90(CombatController* apCombatController, int v)
{
    return FUN_00979e40(apCombatController, v) + GetWeaponDPSDeficit(apCombatController, 3);
}
}  // namespace fnv_0097bb90

struct CombatController;
bool __cdecl IsCombatActionValid(CombatController*, int);

struct CombatActionMoveStandIn
{
    bool FUN_0097bc80(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097bc80
bool CombatActionMoveStandIn::FUN_0097bc80(CombatController* apCombatController, int aiActionValue)
{
    return IsCombatActionValid(apCombatController, aiActionValue);
}

namespace fnv_0097bca0 {
struct CombatController;
void __cdecl FUN_0097bed0(CombatController*, int);

struct CombatActionMoveStandIn
{
    void FUN_0097bca0(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097bca0
void CombatActionMoveStandIn::FUN_0097bca0(CombatController* apCombatController, int aiActionValue)
{
    FUN_0097bed0(apCombatController, aiActionValue);
}
}  // namespace fnv_0097bca0

struct CombatController;
struct Sub
{
    float FUN_0097bd00();
};
struct FUN_005e3fc0_shell
{
    Sub* Get(int);
};
struct FUN_0097bcc0_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097bcc0(CombatController* c, int v);
};
// @fnv 0x0097bcc0
float FUN_0097bcc0_cls::FUN_0097bcc0(CombatController* apController, int v)
{
    float cost = FUN_00979e40(apController, v);
    cost += ((FUN_005e3fc0_shell*)apController)->Get(v)->FUN_0097bd00();
    return cost;
}

struct CombatActionStandIn
{
    float FUN_0097bd00(unsigned int idx);
};

// @fnv 0x0097bd00
float CombatActionStandIn::FUN_0097bd00(unsigned int uiIndex)
{
    return reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb8)[uiIndex];
}

namespace fnv_0097c150 {
struct CombatActionStandIn
{
    int FUN_0097c150(unsigned int idx);
};

// @fnv 0x0097c150
int CombatActionStandIn::FUN_0097c150(unsigned int uiIndex)
{
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc)[uiIndex];
}
}  // namespace fnv_0097c150

namespace fnv_0097c470 {
struct CombatActionStandIn
{
    void FUN_00979c80();
    void FUN_0097c470();
};

// @fnv 0x0097c470
void CombatActionStandIn::FUN_0097c470()
{
    FUN_00979c80();
}
}  // namespace fnv_0097c470

struct CombatController;
struct CombatStateArray;
bool __cdecl FUN_0097beb0(CombatController*, CombatStateArray*, int);
struct FUN_0097c490_cls
{
    bool FUN_00979e90(CombatController*, CombatStateArray*, int);
    bool FUN_0097c490(CombatController* c, CombatStateArray* w, int v);
};
// @fnv 0x0097c490
bool FUN_0097c490_cls::FUN_0097c490(CombatController* apController, CombatStateArray* w, int aiValue)
{
    if (!FUN_00979e90(apController, w, aiValue))
        return false;
    return FUN_0097beb0(apController, w, aiValue);
}

namespace fnv_0097c4d0 {
struct CombatController;
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097c4d0_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097c4d0(CombatController* c, int v);
};
// Returns DAT_0108cb10 if GetWeaponDPSDeficit(c, 0) is at least DAT_0108cb10, otherwise returns FUN_00979e40(c, v).
// @fnv 0x0097c4d0
float FUN_0097c4d0_cls::FUN_0097c4d0(CombatController* c, int iValue)
{
    if (GetWeaponDPSDeficit(c, 0) >= DAT_0108cb10)
        return DAT_0108cb10;
    return FUN_00979e40(c, iValue);
}
}  // namespace fnv_0097c4d0

extern const char* DAT_011a5700[];
int _sprintf_s(char*, unsigned int, const char*, ...);
struct FUN_0097c520_cls
{
    const char* GetCombatActionName();
    void FUN_0097c520(char* buf, unsigned int size, int v);
};
// @fnv 0x0097c520
void FUN_0097c520_cls::FUN_0097c520(char* pcBuffer, unsigned int size, int v)
{
    _sprintf_s(pcBuffer, size, "%s: %s", GetCombatActionName(), DAT_011a5700[v & 0xffff]);
}

namespace fnv_0097c6b0 {
struct CombatController;
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
struct FUN_0097c6b0_cls
{
    float FUN_00979e40(CombatController*, int);
    float FUN_0097c6b0(CombatController* c, int v);
};
// Returns DAT_0108cb10 if GetWeaponDPSDeficit(c, 3) reaches it, otherwise returns FUN_00979e40(c, v).
// @fnv 0x0097c6b0
float FUN_0097c6b0_cls::FUN_0097c6b0(CombatController* c, int v)
{
    if (GetWeaponDPSDeficit(c, 3) >= DAT_0108cb10)
        return DAT_0108cb10;
    return FUN_00979e40(c, v);
}
}  // namespace fnv_0097c6b0

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char* DAT_0118a8a8[];

struct DrawWeaponStandIn
{
    const char* GetCombatActionName();
    void FUN_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};

// Writes "%s: %s" into apDebugText using GetCombatActionName() and DAT_0118a8a8[aiActionValue].
// @fnv 0x0097c990
void DrawWeaponStandIn::FUN_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    _sprintf_s(apDebugText, aiMaxLength, "%s: %s", GetCombatActionName(), DAT_0118a8a8[aiActionValue]);
}

namespace fnv_0097ccf0 {
struct Tile
{
    void FUN_0097cd10(unsigned char v);
};

struct IMH
{
    Tile* FUN_00586150();
};

struct IgnoreBlockedTargetStandIn
{
    void FUN_0097ccf0(IMH* apCombatController, int aiActionValue);
};

// @fnv 0x0097ccf0
void IgnoreBlockedTargetStandIn::FUN_0097ccf0(IMH* apCombatController, int aiActionValue)
{
    apCombatController->FUN_00586150()->FUN_0097cd10(0);
}
}  // namespace fnv_0097ccf0

namespace fnv_0097cd10 {
struct CombatActionStandIn
{
    void FUN_0097cd10(unsigned char v);
};

// @fnv 0x0097cd10
void CombatActionStandIn::FUN_0097cd10(unsigned char v)
{
    *(reinterpret_cast<unsigned char*>(this) + 0x72) = v;
}
}  // namespace fnv_0097cd10

namespace fnv_0097cfc0 {
struct CombatActionStandIn
{
    int GetActionAtIndex(unsigned int idx);
};

// @fnv 0x0097cfc0
int CombatActionStandIn::GetActionAtIndex(unsigned int uiIndex)
{
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x190)[uiIndex];
}
}  // namespace fnv_0097cfc0

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct CombatActionHideStandIn
{
    const char* GetCombatActionName();
    void GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};

// Writes "<name>: <value>" into apDebugText using _sprintf_s, with the name from GetCombatActionName and aiActionValue.
// @fnv 0x0097d370
void CombatActionHideStandIn::GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    _sprintf_s(apDebugText, aiMaxLength, "%s: %i", GetCombatActionName(), aiActionValue);
}

struct FUN_009d8b60
{
    FUN_009d8b60();
    char pad[0x40];
};
struct FUN_00980250_shell
{
    void FUN_009801b0(FUN_009d8b60*);
};
struct FUN_0097caf0_cls
{
    void FUN_0097caf0(FUN_00980250_shell* c, int v);
};
// Allocates a new FUN_009d8b60 and passes it to c->FUN_009801b0; v is unused.
// @fnv 0x0097caf0
void FUN_0097caf0_cls::FUN_0097caf0(FUN_00980250_shell* c, int aiValue)
{
    c->FUN_009801b0(new FUN_009d8b60);
}

namespace fnv_0097ae00 {
struct CombatController;

struct Actor
{
    bool IsPlayerTeammate();
    float ComputeFromNode(const char*);
};

struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};

struct FUN_0097bcc0_cls
{
    float FUN_00979e40(CombatController*, int);
};

float __cdecl GetWeaponDPSDeficit(CombatController*, int);

extern float DAT_0108cb10;

struct FUN_0097ae00_shell : FUN_0097bcc0_cls
{
    float FUN_0097ae00(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097ae00
float FUN_0097ae00_shell::FUN_0097ae00(CombatController* apCombatController, int aiActionValue)
{
    if (((TESAmmoInitCalls*)apCombatController)->GetFieldBC() &&
        ((Actor*)((TESAmmoInitCalls*)apCombatController)->GetFieldBC())->IsPlayerTeammate() &&
        ((Actor*)((TESAmmoInitCalls*)apCombatController)->GetFieldBC())->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        return DAT_0108cb10;
    }
    return FUN_0097bcc0_cls::FUN_00979e40(apCombatController, aiActionValue) +
           GetWeaponDPSDeficit(apCombatController, 1);
}
}  // namespace fnv_0097ae00

namespace fnv_0097af70 {
struct CombatController;

struct IMH
{
    int FUN_00586150();
};

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_00980250_shell
{
    void FUN_00980110(int);
    void FUN_009801b0(int);
};

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

struct FUN_009d2440
{
    char pad[0x6c];
    FUN_009d2440(unsigned int);
};

struct FUN_0097af70_shell
{
    void FUN_0097af70(CombatController* apCombatController, int aiActionValue);
};

// Creates a FUN_009d0890 and a FUN_009d2440 from GetFieldValue of the controller's IMH result, passing both to the controller's FUN_00980110 and FUN_009801b0.
// @fnv 0x0097af70
void FUN_0097af70_shell::FUN_0097af70(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110((int)new FUN_009d0890());
    ((FUN_00980250_shell*)apCombatController)
        ->FUN_009801b0((int)new FUN_009d2440(GetFieldValue((unsigned int*)((IMH*)apCombatController)->FUN_00586150())));
}
}  // namespace fnv_0097af70

namespace fnv_0097b170 {
struct CombatController;

struct FUN_00980250_shell
{
    void FUN_00980110(int);
    void FUN_009801b0(int);
};

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

struct FUN_009d3a00
{
    char pad[0x64];
    FUN_009d3a00();
};

struct FUN_0097b170_shell
{
    void FUN_0097b170(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009d0890 and a FUN_009d3a00 and passes them to FUN_00980110 and FUN_009801b0 on the combat controller.
// @fnv 0x0097b170
void FUN_0097b170_shell::FUN_0097b170(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110((int)new FUN_009d0890());
    ((FUN_00980250_shell*)apCombatController)->FUN_009801b0((int)new FUN_009d3a00());
}
}  // namespace fnv_0097b170

namespace fnv_0097b410 {
struct CombatController;

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_009cc0c0
{
    char pad[0x88];
    FUN_009cc0c0();
};

struct FUN_0097b410_shell
{
    void FUN_0097b410(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009cc0c0 object and passes it to the combat controller's FUN_00980110 method.
// @fnv 0x0097b410
void FUN_0097b410_shell::FUN_0097b410(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110(reinterpret_cast<int>(new FUN_009cc0c0));
}
}  // namespace fnv_0097b410

namespace fnv_0097b6d0 {
struct CombatController;

struct FUN_00980250_shell
{
    void FUN_00980110(int);
    void FUN_009801b0(int);
};

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

struct FUN_009d3a00
{
    char pad[0x64];
    FUN_009d3a00();
};

struct FUN_0097b6d0_shell
{
    void FUN_0097b6d0(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009cadf0 and a FUN_009d3a00 and passes each to the combat controller's FUN_00980110 and FUN_009801b0 methods.
// @fnv 0x0097b6d0
void FUN_0097b6d0_shell::FUN_0097b6d0(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110((int)new FUN_009cadf0());
    ((FUN_00980250_shell*)apCombatController)->FUN_009801b0((int)new FUN_009d3a00());
}
}  // namespace fnv_0097b6d0

namespace fnv_0097b880 {
struct CombatController;
struct CombatState;
struct CombatAvoidanceSphere;

int __fastcall GetField18C(char*);

struct IMH
{
    int FUN_00586150();
};

struct FUN_0097b940_shell
{
    int FUN_0097b940();
};

struct FUN_0097b960_shell
{
    unsigned char GetByte76();
};

struct FUN_009caee0
{
    char pad[0x3c];
    FUN_009caee0(int, unsigned char);
};

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_0097b880_shell
{
    void FUN_0097b880(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097b880
void FUN_0097b880_shell::FUN_0097b880(CombatController* apCombatController, int aiActionValue)
{
    CombatState* pcombatState = (CombatState*)((IMH*)apCombatController)->FUN_00586150();
    CombatAvoidanceSphere* pcombatLocation =
        (CombatAvoidanceSphere*)GetField18C((char*)((IMH*)apCombatController)->FUN_00586150());
    ((FUN_00980250_shell*)apCombatController)
        ->FUN_00980110((int)new FUN_009caee0(((FUN_0097b940_shell*)pcombatLocation)->FUN_0097b940(),
                                             ((FUN_0097b960_shell*)pcombatState)->GetByte76()));
}
}  // namespace fnv_0097b880

namespace fnv_0097bab0 {
struct CombatController;

struct IMH
{
    int FUN_00586150();
};

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_00980250_shell
{
    void FUN_00980110(int);
    void FUN_009801b0(int);
};

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

struct FUN_009d2440
{
    char pad[0x6c];
    FUN_009d2440(unsigned int);
};

struct FUN_0097bab0_shell
{
    void FUN_0097bab0(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097bab0
void FUN_0097bab0_shell::FUN_0097bab0(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110((int)new FUN_009cadf0());
    ((FUN_00980250_shell*)apCombatController)
        ->FUN_009801b0((int)new FUN_009d2440(GetFieldValue((unsigned int*)((IMH*)apCombatController)->FUN_00586150())));
}
}  // namespace fnv_0097bab0

namespace fnv_0097c090 {
struct TESObjectWEAP;
struct CombatController;

struct FUN_0097bca0_cls
{
    void FUN_0097bca0(CombatController*, int);
};

struct IMH
{
    int FUN_00586150();
};

struct CombatStateStub
{
    TESObjectWEAP* FUN_0097c150(int);
};

struct FUN_009da720
{
    char pad[0x18];
    FUN_009da720(TESObjectWEAP*);
};

struct FUN_00980270_shell
{
    void FUN_00980270(int);
};

struct FUN_00714d70
{
    void SetField(int);
};

struct FUN_0097c090_shell : FUN_0097bca0_cls
{
    void FUN_0097c090(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097c090
void FUN_0097c090_shell::FUN_0097c090(CombatController* apCombatController, int aiActionValue)
{
    FUN_0097bca0(apCombatController, aiActionValue);
    TESObjectWEAP* pweapon = ((CombatStateStub*)((IMH*)apCombatController)->FUN_00586150())->FUN_0097c150(2);
    ((FUN_00980270_shell*)apCombatController)->FUN_00980270((int)new FUN_009da720(pweapon));
    ((FUN_00714d70*)apCombatController)->SetField((int)pweapon);
}
}  // namespace fnv_0097c090

namespace fnv_0097c280 {
struct CombatController;

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

void __cdecl FUN_0097bed0(CombatController*, int);

struct FUN_0097c280_shell
{
    void FUN_0097c280(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009d0890 object, passes it to the combat controller's FUN_00980110, then calls FUN_0097bed0 with the action value.
// @fnv 0x0097c280
void FUN_0097c280_shell::FUN_0097c280(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110(reinterpret_cast<int>(new FUN_009d0890));
    FUN_0097bed0(apCombatController, aiActionValue);
}
}  // namespace fnv_0097c280

namespace fnv_0097c310 {
struct CombatController;

struct Actor
{
    bool IsPlayerTeammate();
    float ComputeFromNode(const char*);
};

struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};

struct FUN_0097bcc0_cls
{
    float FUN_00979e40(CombatController*, int);
};

float __cdecl GetWeaponDPSDeficit(CombatController*, int);

extern float DAT_0108cb10;

struct FUN_0097c310_shell : FUN_0097bcc0_cls
{
    float FUN_0097c310(CombatController* apCombatController, int aiActionValue);
};

// Returns DAT_0108cb10 when GetWeaponDPSDeficit reaches it or the actor is a teammate with CombatStyleMelee 1.0, otherwise FUN_00979e40's result.
// @fnv 0x0097c310
float FUN_0097c310_shell::FUN_0097c310(CombatController* apCombatController, int aiActionValue)
{
    if (GetWeaponDPSDeficit(apCombatController, 1) >= DAT_0108cb10)
    {
        return DAT_0108cb10;
    }
    if (((TESAmmoInitCalls*)apCombatController)->GetFieldBC() &&
        ((Actor*)((TESAmmoInitCalls*)apCombatController)->GetFieldBC())->IsPlayerTeammate() &&
        ((Actor*)((TESAmmoInitCalls*)apCombatController)->GetFieldBC())->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        return DAT_0108cb10;
    }
    return FUN_0097bcc0_cls::FUN_00979e40(apCombatController, aiActionValue);
}
}  // namespace fnv_0097c310

namespace fnv_0097c620 {
struct CombatController;

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

void __cdecl FUN_0097bed0(CombatController*, int);

struct FUN_0097c620_shell
{
    void FUN_0097c620(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009cadf0 object, passes it to FUN_00980110 on the controller, then calls FUN_0097bed0 with the action value.
// @fnv 0x0097c620
void FUN_0097c620_shell::FUN_0097c620(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)->FUN_00980110(reinterpret_cast<int>(new FUN_009cadf0));
    FUN_0097bed0(apCombatController, aiActionValue);
}
}  // namespace fnv_0097c620

namespace fnv_0097c790 {
struct TESObjectWEAP;
struct CombatController;
typedef int COMBAT_WEAPON_TYPE;

struct IMH
{
    int FUN_00586150();
};

struct CombatStateStub
{
    TESObjectWEAP* FUN_0097c150(int);
};

struct FUN_009da720
{
    char pad[0x18];
    FUN_009da720(TESObjectWEAP*);
};

struct FUN_00980270_shell
{
    void FUN_00980270(int);
};

struct FUN_00714d70
{
    void SetField(int);
};

struct FUN_0097c790_shell
{
    void FUN_0097c790(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097c790
void FUN_0097c790_shell::FUN_0097c790(CombatController* apCombatController, int aiActionValue)
{
    TESObjectWEAP* pweapon = 0;
    COMBAT_WEAPON_TYPE ecombatWeaponType = (COMBAT_WEAPON_TYPE)aiActionValue;
    if (aiActionValue != 6)
    {
        pweapon = ((CombatStateStub*)((IMH*)apCombatController)->FUN_00586150())->FUN_0097c150(ecombatWeaponType);
    }
    ((FUN_00980270_shell*)apCombatController)->FUN_00980270((int)new FUN_009da720(pweapon));
    ((FUN_00714d70*)apCombatController)->SetField((int)pweapon);
}
}  // namespace fnv_0097c790

namespace fnv_0097c8e0 {
struct CombatController;
struct TESObjectWEAP;
typedef int COMBAT_WEAPON_TYPE;

extern float DAT_0108cb10;

bool __fastcall FUN_006450c0(TESObjectWEAP*);

struct Actor
{
    bool IsPlayerTeammate();
    float ComputeFromNode(const char*);
};

struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};

struct IMH
{
    int FUN_00586150();
};

struct CombatStateStub
{
    TESObjectWEAP* FUN_0097c150(int);
};

struct FUN_0097bcc0_cls
{
    float FUN_00979e40(CombatController*, int);
};

struct FUN_0097c8e0_shell : FUN_0097bcc0_cls
{
    float GetCost(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097c8e0
float FUN_0097c8e0_shell::GetCost(CombatController* apCombatController, int aiActionValue)
{
    if (((TESAmmoInitCalls*)apCombatController)->GetFieldBC() &&
        ((TESAmmoInitCalls*)apCombatController)->GetFieldBC()->IsPlayerTeammate() &&
        ((TESAmmoInitCalls*)apCombatController)->GetFieldBC()->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        TESObjectWEAP* pweapon = 0;
        COMBAT_WEAPON_TYPE ecombatWeaponType = (COMBAT_WEAPON_TYPE)aiActionValue;
        if (aiActionValue != 6)
        {
            pweapon = ((CombatStateStub*)((IMH*)apCombatController)->FUN_00586150())->FUN_0097c150(ecombatWeaponType);
        }
        if (pweapon && !FUN_006450c0(pweapon))
        {
            return DAT_0108cb10;
        }
    }
    return FUN_0097bcc0_cls::FUN_00979e40(apCombatController, aiActionValue);
}
}  // namespace fnv_0097c8e0

namespace fnv_0097cdb0 {
struct CombatController;

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting432;

struct IMH
{
    int FUN_00586150();
};

struct BSFaceGenNiNode
{
    void SetApplyRotToParent(int);
};

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_009d6030
{
    char pad[0x40];
    FUN_009d6030(unsigned int, float, bool, bool);
};

struct FUN_00980250_shell
{
    void FUN_009801b0(int);
};

struct FUN_0097cdb0_shell
{
    void FUN_0097cdb0(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097cdb0
void FUN_0097cdb0_shell::FUN_0097cdb0(CombatController* apCombatController, int aiActionValue)
{
    ((BSFaceGenNiNode*)((IMH*)apCombatController)->FUN_00586150())->SetApplyRotToParent(2);
    ((FUN_00980250_shell*)apCombatController)
        ->FUN_009801b0((int)new FUN_009d6030(GetFieldValue((unsigned int*)((IMH*)apCombatController)->FUN_00586150()),
                                             *originalRuntimeFloatSetting432.Float(), true, true));
}
}  // namespace fnv_0097cdb0

namespace fnv_0097cf10 {
struct TESObjectREFR;
struct TESBoundObject;
struct CombatController;

struct CombatReferenceEntry
{
    TESObjectREFR* pRef;
    TESBoundObject* m_pBaseObject;
};

struct IMH
{
    int FUN_00586150();
};

struct C99
{
    int* GetActionAtIndex(int);
};

struct FUN_009ca5f0
{
    char pad[0x1c];
    FUN_009ca5f0(TESObjectREFR*, TESBoundObject*);
};

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_0097cf10_shell
{
    void FUN_0097cf10(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x0097cf10
void FUN_0097cf10_shell::FUN_0097cf10(CombatController* apCombatController, int aiActionValue)
{
    CombatReferenceEntry* pcombatItem =
        (CombatReferenceEntry*)((C99*)((IMH*)apCombatController)->FUN_00586150())->GetActionAtIndex(aiActionValue - 17);
    if (pcombatItem)
    {
        ((FUN_00980250_shell*)apCombatController)
            ->FUN_00980110((int)new FUN_009ca5f0(pcombatItem->pRef, pcombatItem->m_pBaseObject));
    }
}
}  // namespace fnv_0097cf10

namespace fnv_0097d060 {
struct TESBoundObject;
struct CombatController;

struct IMH
{
    int FUN_00586150();
};

struct FUN_0097d110_shell
{
    int GetAt(int);
};

struct FUN_009daa10
{
    char pad[0x18];
    FUN_009daa10(TESBoundObject*);
};

struct FUN_00980250_shell
{
    void FUN_00980110(int);
};

struct FUN_0097d060_shell
{
    void FUN_0097d060(CombatController* apCombatController, int aiActionValue);
};

// Looks up a TESBoundObject for the given action value minus 17 and, if found, passes a new FUN_009daa10 wrapping it to the combat controller.
// @fnv 0x0097d060
void FUN_0097d060_shell::FUN_0097d060(CombatController* apCombatController, int aiActionValue)
{
    TESBoundObject* pitem =
        (TESBoundObject*)((FUN_0097d110_shell*)((IMH*)apCombatController)->FUN_00586150())->GetAt(aiActionValue - 17);
    if (pitem)
    {
        ((FUN_00980250_shell*)apCombatController)->FUN_00980110((int)new FUN_009daa10(pitem));
    }
}
}  // namespace fnv_0097d060

namespace fnv_0097d2d0 {
struct CombatController;

struct IMH
{
    int FUN_00586150();
};

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_00980250_shell
{
    void FUN_009801b0(int);
};

struct FUN_009d6030
{
    char pad[0x40];
    FUN_009d6030(unsigned int, float, int, int);
};

struct FUN_0097d2d0_shell
{
    void FUN_0097d2d0(CombatController* apCombatController, int aiActionValue);
};

// Allocates a FUN_009d6030 from the combat controller's IMH value and aiActionValue, then passes it to FUN_009801b0.
// @fnv 0x0097d2d0
void FUN_0097d2d0_shell::FUN_0097d2d0(CombatController* apCombatController, int aiActionValue)
{
    ((FUN_00980250_shell*)apCombatController)
        ->FUN_009801b0(reinterpret_cast<int>(new FUN_009d6030(
            GetFieldValue((unsigned int*)((IMH*)apCombatController)->FUN_00586150()), (float)aiActionValue, 0, 0)));
}
}  // namespace fnv_0097d2d0

namespace fnv_0097bed0 {
struct IMH
{
    int FUN_00586150();
};

struct AvoidSphere
{
    float GetRadius() const;
};

struct CombatAvoidanceSphere : AvoidSphere
{
    bool FUN_0097be60(int);
};

struct CombatProcedure
{
};

struct FUN_00980250_shell
{
    void FUN_009801b0(int);
};

struct CombatController
{
};

struct FUN_009d5ad0
{
    unsigned char data[0x18];
    FUN_009d5ad0(int);
};

struct FUN_009d69f0
{
    unsigned char data[0x7c];
    FUN_009d69f0(CombatAvoidanceSphere*, float, int);
};

int __fastcall GetField18C(char*);

// @fnv 0x0097bed0
void FUN_0097bed0(CombatController* apCombatController, int aiLocation)
{
    CombatProcedure* pmovementProcedure = 0;
    CombatAvoidanceSphere* pcombatLocation;

    pcombatLocation = reinterpret_cast<CombatAvoidanceSphere*>(
        GetField18C(reinterpret_cast<char*>(reinterpret_cast<IMH*>(apCombatController)->FUN_00586150())));

    if (pcombatLocation->FUN_0097be60(1))
    {
        pmovementProcedure = reinterpret_cast<CombatProcedure*>(new FUN_009d5ad0(aiLocation));
    }
    else
    {
        pmovementProcedure = reinterpret_cast<CombatProcedure*>(
            new FUN_009d69f0(pcombatLocation, pcombatLocation->GetRadius(), aiLocation));
    }

    reinterpret_cast<FUN_00980250_shell*>(apCombatController)->FUN_009801b0(reinterpret_cast<int>(pmovementProcedure));
}
}  // namespace fnv_0097bed0

// FUN_0097be60 : thiscall, one stack argument, returns a byte-sized flag test.
//
// The original reads a 32-bit field at this+0x1C, masks it with the
// stack argument and returns the (non-zero) result of that test.
struct FUN_0097be60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_1c;
    unsigned char FUN_0097be60(unsigned int aValue);
};

// @fnv 0x0097be60
unsigned char FUN_0097be60_cls::FUN_0097be60(unsigned int aValue)
{
    return (m_1c & aValue) != 0;
}

struct ActionDescriptor

{

    bool _Call_439090();
};

struct FormIDEntry;

struct TESSaveLoadGame

{

    FormIDEntry* GetCurrentFormHeader();
};

struct InterfaceManager_helper

{

    Tile* FUN_00586150();
};

int __fastcall GetField18C(char*);

int __fastcall GetField38(char*);

unsigned int __fastcall FUN_0044edb0(void*);

struct FUN_009cde10_shell

{

    virtual void vfn_00();

    virtual void vfn_04();

    virtual void vfn_08();

    virtual void vfn_0c();

    virtual void vfn_10();

    virtual void vfn_14();

    virtual void vfn_18();

    virtual void vfn_1c();

    virtual void vfn_20();

    virtual void vfn_24();

    virtual void vfn_28();

    virtual void vfn_2c();

    virtual void vfn_30();

    virtual int GetActionType();

    int GetSection();

    bool FUN_0097be60(int);

    ActionDescriptor* FUN_0097be80(char*);

    ActionDescriptor* FUN_0097b940(ActionDescriptor*);
};

struct Twin_00639b40

{

    const char* GetEntryPoint();
};

struct CombatController;

// Checks the current form header and interface tile against the given section and action type, returning false on any mismatch.
// @fnv 0x0097bd20
bool __cdecl IsCombatActionValid(CombatController* controller, int iSection)

{

    FUN_009cde10_shell* piStack_c2;

    FUN_009cde10_shell* iStack_c;

    int iStack_8;

    FUN_009cde10_shell* piStack4;

    FUN_009cde10_shell* piStack_18;

    struct TargetTemp

    {

        int a;

        int b;

        int c;

    } auStack2;

    piStack_c2 = (FUN_009cde10_shell*)((TESSaveLoadGame*)controller)->GetCurrentFormHeader();

    if (piStack_c2 == 0)

        return false;

    iStack_c = (FUN_009cde10_shell*)GetField18C(

        (char*)((InterfaceManager_helper*)controller)->FUN_00586150());

    if (iStack_c == 0 || iStack_c->GetSection() != iSection)

        return false;

    iStack_8 = piStack_c2->GetActionType();

    if (iStack_8 == 6)

    {

        piStack4 = piStack_c2;

        if (iStack_c->GetSection() != (int)((Twin_00639b40*)piStack4)->GetEntryPoint())

            return false;

        if (FUN_0044edb0(iStack_c) != 0)

        {

            if (FUN_0044edb0(iStack_c) != GetField38((char*)piStack4))

                return false;
        }

        else

        {

            if (iStack_c
                    ->FUN_0097b940(

                        piStack4->FUN_0097be80((char*)&auStack2))
                    ->_Call_439090())

                return false;
        }

        if (iStack_c->FUN_0097be60(1))

            return false;
    }

    else

    {

        if (iStack_8 == 4)

        {

            piStack_18 = piStack_c2;

            if (!iStack_c->FUN_0097be60(1))

                return false;

            if (iStack_c->GetSection() != piStack_18->GetSection())

                return false;
        }

        else

        {

            return false;
        }
    }

    return true;
}

// fallout/ai/combat/combataction.cpp: CombatAction (12 functions)

#include "combataction_decls.h"

// Creates and returns a new CombatAction subclass instance matching the given COMBAT_ACTION type, warning and returning 0 for unknown types.
// @fnv 0x00979f90
CombatAction* CombatAction::CreateAction(COMBAT_ACTION type)
{
    switch (type)
    {
    case COMBAT_ACTION_ATTACK_RANGED:
        return new CombatActionAttackRanged(type);
    case COMBAT_ACTION_ATTACK_RANGED_FROM_COVER:
        return new CombatActionAttackRangedFromCover(type);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionAttackRangedExplosive(type);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE_FROM_COVER:
        return new CombatActionAttackRangedExplosiveFromCover(type);
    case COMBAT_ACTION_ATTACK_MELEE:
        return new CombatActionAttackMelee(type);
    case COMBAT_ACTION_ATTACK_HAND_TO_HAND:
        return new CombatActionAttackHandToHand(type);
    case COMBAT_ACTION_ATTACK_GRENADE:
        return new CombatActionAttackGrenade(type);
    case COMBAT_ACTION_ATTACK_GRENADE_FLUSH_TARGET:
        return new CombatActionAttackGrenadeFlushTarget(type);
    case COMBAT_ACTION_ATTACK_GRENADE_FROM_COVER:
        return new CombatActionAttackGrenadeFromCover(type);
    case COMBAT_ACTION_MOVE:
        return new CombatActionMove(type);
    case COMBAT_ACTION_MOVE_AND_SWITCH_TO_MELEE:
        return new CombatActionMoveAndSwitchToMelee(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED:
        return new CombatActionMoveAndAttackRanged(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionMoveAndAttackRangedExplosive(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_GRENADE:
        return new CombatActionMoveAndAttackGrenade(type);
    case COMBAT_ACTION_DRAW_WEAPON:
        return new CombatActionDrawWeapon(type);
    case COMBAT_ACTION_SWITCH_WEAPON:
        return new CombatActionSwitchWeapon(type);
    case COMBAT_ACTION_AVOID_THREAT:
        return new CombatActionAvoidThreat(type);
    case COMBAT_ACTION_SEARCH:
        return new CombatActionSearch(type);
    case COMBAT_ACTION_INVESTIGATE:
        return new CombatActionInvestigate(type);
    case COMBAT_ACTION_DODGE:
        return new CombatActionDodge(type);
    case COMBAT_ACTION_IGNORE_BLOCKED_TARGET:
        return new CombatActionIgnoreBlockedTarget(type);
    case COMBAT_ACTION_FLEE:
        return new CombatActionFlee(type);
    case COMBAT_ACTION_ACTIVATE_COMBAT_ITEM:
        return new CombatActionActivateCombatItem(type);
    case COMBAT_ACTION_USE_COMBAT_ITEM:
        return new CombatActionUseCombatItem(type);
    case COMBAT_ACTION_ACQUIRE_LINE_OF_SIGHT:
        return new CombatActionAcquireLineOfSight(type);
    case COMBAT_ACTION_HIDE:
        return new CombatActionHide(type);
    case COMBAT_ACTION_APPROACH_TARGET:
        return new CombatActionApproachTarget(type);
    default:
        Warning("COMBAT: Could not create combat action of type %i", type);
        return 0;
    }
}

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};
extern CombatActionEntry DAT_011a4280[];

struct BSThread
{
    unsigned int GetThreadID();
};

struct FUN_00979e20_shell
{
    char* GetCombatActionName();
};

// @fnv 0x00979e20
char* FUN_00979e20_shell::GetCombatActionName()
{
    return DAT_011a4280[reinterpret_cast<BSThread*>(this)->GetThreadID()].pName;
}

namespace fnv_00979e40 {
struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};
extern CombatActionEntry DAT_011a4280[];

struct BSThread
{
    unsigned int GetThreadID();
};

struct CombatController;

struct FUN_00979e40_shell
{
    float FUN_00979e40(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x00979e40
float FUN_00979e40_shell::FUN_00979e40(CombatController* apCombatController, int aiActionValue)
{
    return DAT_011a4280[reinterpret_cast<BSThread*>(this)->GetThreadID()].m_fPathingCostCur;
}
}  // namespace fnv_00979e40

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

struct FUN_00979e60_shell
{
    char* GetCombatActionName();
    void GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};

// @fnv 0x00979e60
void FUN_00979e60_shell::GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    TaskQueueInterface::CopyStringToBuffer(apDebugText, aiMaxLength, GetCombatActionName());
}

struct CombatController;
struct CombatStateArray
{
    bool FUN_009aadc0(unsigned int, int);
};
struct UnsignedIdHandle
{
    int _ref_00726070();
    operator unsigned int() const;
};
struct B006815c0
{
    UnsignedIdHandle** _ref_006815c0();
};
struct CombatWorldStateListNext
{
    CombatWorldStateListNode* GetNext();
};
struct TgtOps
{
    void* GetPosition();
};
struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
struct FUN_00979f70_shell
{
    void FUN_00979f70(unsigned int);
};

struct FUN_00979e90_shell
{
    bool FUN_00979f50(int, int*);
    bool FUN_00979e90(CombatController* apCombatController, CombatStateArray* apWorldStateArray, int aiActionValue);
};

// @fnv 0x00979e90
bool FUN_00979e90_shell::FUN_00979e90(CombatController* apCombatController, CombatStateArray* apWorldStateArray,
                                      int aiActionValue)
{
    UnsignedIdHandle* pWorldState4;
    int iValue3;
    int _iCombatLocation;
    CombatWorldStateListNode* pList;

    pList = reinterpret_cast<CombatWorldStateListNode*>(reinterpret_cast<TgtOps*>(this)->GetPosition());
    while (pList)
    {
        pWorldState4 = *reinterpret_cast<B006815c0*>(pList)->_ref_006815c0();
        if (pWorldState4)
        {
            iValue3 = pWorldState4->_ref_00726070() == -1 ? aiActionValue : pWorldState4->_ref_00726070();
            if (!apWorldStateArray->FUN_009aadc0(*pWorldState4, iValue3))
                return false;
        }
        pList = reinterpret_cast<CombatWorldStateListNext*>(pList)->GetNext();
    }
    _iCombatLocation = -1;
    if (FUN_00979f50(1, &_iCombatLocation))
        reinterpret_cast<FUN_00979f70_shell*>(reinterpret_cast<FUN_005e3fc0_shell*>(apCombatController)->Get())
            ->FUN_00979f70(_iCombatLocation);
    return true;
}

struct FUN_009aa410_shell
{
    void FindStateByType(int, int);
};

struct FUN_00979f50_shell
{
    void FUN_00979f50(int a, int b);
};

// Calls FindStateByType on the object at offset 0xc of this, passing a and b through.
// @fnv 0x00979f50
void FUN_00979f50_shell::FUN_00979f50(int aiArg1, int aiArg2)
{
    reinterpret_cast<FUN_009aa410_shell*>(reinterpret_cast<char*>(this) + 0xc)->FindStateByType(aiArg1, aiArg2);
}

namespace fnv_00979f70 {
struct QuantityData
{
    void SetQuantity(unsigned int);
};

struct FUN_00979f70_shell
{
    void FUN_00979f70(unsigned int aiQuantity);
};

// @fnv 0x00979f70
void FUN_00979f70_shell::FUN_00979f70(unsigned int aiQuantity)
{
    (*reinterpret_cast<QuantityData**>(reinterpret_cast<char*>(this) + 4))->SetQuantity(aiQuantity);
}
}  // namespace fnv_00979f70

namespace fnv_0097abd0 {
int __cdecl FUN_00404dc0(const char*, const char*);

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};
extern CombatActionEntry DAT_011a4280[];

// @fnv 0x0097abd0
bool FUN_0097abd0(char* apCombatActionName, float afCost)
{
    for (unsigned int i = 0; i < 0x1b; i++)
    {
        if (!FUN_00404dc0(DAT_011a4280[i].pName, apCombatActionName))
        {
            DAT_011a4280[i].m_fPathingCostCur = afCost;
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0097abd0

struct CombatController;
struct FUN_009cdac0_shell
{
    float GetField60Float();
};
struct CombatState : FUN_009cdac0_shell
{
    float FUN_0097ac90(int);
};
struct IMH
{
    CombatState* FUN_00586150();
};
extern double _gModifierZero;
extern float DAT_0108ca80;

// Gets the combat state's attack DPS for a weapon type and returns the default value if zero, otherwise the max attack DPS minus it.
// @fnv 0x0097ac30
float GetWeaponDPSDeficit(CombatController* apCombatController, int aeWeaponType)
{
    float fattackDPS;
    CombatState* pcombatState;
    float fmaxAttackDPS;

    pcombatState = reinterpret_cast<IMH*>(apCombatController)->FUN_00586150();
    fattackDPS = pcombatState->FUN_0097ac90(aeWeaponType);
    if (fattackDPS == _gModifierZero)
        return DAT_0108ca80;
    fmaxAttackDPS = pcombatState->GetField60Float();
    return fmaxAttackDPS - fattackDPS;
}

struct FUN_0097ac90_shell
{
    float FUN_0097ac90(int aiIndex);
};

// @fnv 0x0097ac90
float FUN_0097ac90_shell::FUN_0097ac90(int aiIndex)
{
    return reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3c)[aiIndex];
}

struct CombatController;
struct CoordinateTriple
{
    double GetDistanceSquared(CoordinateTriple*);
};
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);
extern float DAT_0108cb00;
extern double DAT_0108cb08;

// @fnv 0x0097acb0
float FUN_0097acb0(CombatController* apCombatController, CoordinateTriple* arStartWorldLoc,
                   CoordinateTriple* arEndWorldLoc)
{
    float fmovementCost;

    fmovementCost = arStartWorldLoc->GetDistanceSquared(arEndWorldLoc) / DAT_0108cb08;
    fmovementCost = FUN_0040ebd0(fmovementCost, DAT_0108cb00);
    fmovementCost = FUN_00404010(fmovementCost, 0.01f);
    return fmovementCost;
}

extern int DAT_0108cab8;

struct CondS
{
    int data[2];
    CondS();
    ~CondS();
};

struct FUN_00979bd0
{
    virtual void vfunc();
    CondS cond0;
    CondS cond1;
    CondS cond2;
    CondS cond3;
    int aeType;
    int iFlags;

    FUN_00979bd0(int aeType);
};

// Stores the type argument in aeType and copies iFlags from the global type table entry at that index.
// @fnv 0x00979bd0
FUN_00979bd0::FUN_00979bd0(int a)
{
    aeType = a;
    iFlags = DAT_011a4280[aeType].iFlags;
}

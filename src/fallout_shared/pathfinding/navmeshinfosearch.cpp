// fallout_shared/pathfinding/navmeshinfosearch.cpp: NavMeshInfoSearch, StandInSearch (8 functions)

#include "navmeshinfosearch_decls.h"

// The legacy destructor label is contradicted by the queue member initialization
// at AStarSearch construction: the receiver is this + 0x1ff4.
// Default-constructs the AStarOpenList, initializing m_fValue to -1.0f and zeroing the m_ppNodes array.
// @fnv 0x006b9470
template <> AStarOpenList<const NavMeshInfo*, TESObjectREFR*>::AStarOpenList()
{
    m_fValue = -1.0f;
    memset(m_ppNodes, 0, sizeof(m_ppNodes));
}

// @fnv 0x006b8c20
bool NavMeshInfoSearch::HasReachedGoal(const AStarNodeType* pNode)
{
    return pNode->ObjectResolver == m_pGoalNavMeshInfo;
}

// Builds the A* connection list for pNode from its mesh's connections, preferred connections and door portals, computing costs and adding nodes to pConnections.
// @fnv 0x006b8490
bool NavMeshInfoSearch::CollectConnections(const AStarNodeType* pNode,
                                           BSSimpleArray<AStarNodeType*, 1024>* pConnections)
{
    float fInitialCost = pNode->m_fPathingCostCur;
    const NavMeshInfo* m_pNavigationMesh = pNode->ObjectResolver;
    float fCostMultiplier = 1.0f - m_pNavigationMesh->FUN_007df1f0() * 100.0;
    FUN_005330e0(fCostMultiplier, 0.1f, 1.0f);
    unsigned int ItemUpdateArray = m_pNavigationMesh->m_kConnectedNavMeshInfos.GetSize();
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        const NavMeshInfo* pNextMesh = m_pNavigationMesh->m_kConnectedNavMeshInfos.GetAt(i);
        if (!pNextMesh)
            continue;
        NiPoint3 Start =
            m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition : m_pNavigationMesh->m_kNavMeshPosition;
        NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
        float fConnectionCost = (Goal - Start).Length() * fCostMultiplier * 3.0 + fInitialCost;
        AStarNodeType* pNewAStarNode;
        switch (CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
        {
        case ASTARNODE_CREATED:
            pNewAStarNode->ObjectResolver = pNextMesh;
            if (m_bUseGoalDistanceHeuristic)
                pNewAStarNode->m_fCost = (m_kGoalPosition - pNextMesh->m_kNavMeshPosition).Length() * 0.1f;
            else
                pNewAStarNode->m_fCost = 1.0f;
        case ASTARNODE_UPDATED:
            pNewAStarNode->m_kOpenListLink = 0;
            pConnections->Add(pNewAStarNode);
            break;
        }
    }
    unsigned int uiPreferredConnections = m_pNavigationMesh->m_kPreferredConnections.GetSize();
    for (unsigned int i = 0; i < uiPreferredConnections; ++i)
    {
        const NavMeshInfo* pNextMesh = m_pNavigationMesh->m_kPreferredConnections.GetAt(i);
        if (!pNextMesh)
            continue;
        NiPoint3 Start =
            m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition : m_pNavigationMesh->m_kNavMeshPosition;
        NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
        float fConnectionCost = (Goal - Start).Length() * fCostMultiplier + fInitialCost;
        AStarNodeType* pNewAStarNode;
        switch (CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
        {
        case ASTARNODE_CREATED:
            pNewAStarNode->ObjectResolver = pNextMesh;
            if (m_bUseGoalDistanceHeuristic)
                pNewAStarNode->m_fCost = (m_kGoalPosition - pNextMesh->m_kNavMeshPosition).Length() * 0.1f;
            else
                pNewAStarNode->m_fCost = 1.0f;
        case ASTARNODE_UPDATED:
            pNewAStarNode->m_kOpenListLink = 0;
            pConnections->Add(pNewAStarNode);
            break;
        }
    }
    if (m_pPathingActorData || m_eDoorLockDisposition == Pathing::ALLOW_LOCKS)
    {
        ItemUpdateArray = m_pNavigationMesh->m_kDoorReferences.GetSize();
        for (unsigned int i = 0; i < ItemUpdateArray; ++i)
        {
            TESObjectREFR* pPathNodeDoor = m_pNavigationMesh->m_kDoorReferences.GetAt(i);
            if (!pPathNodeDoor)
                continue;
            if (pPathNodeDoor->GetDisabled())
                continue;
            m_kDoorAccessData.SetDoorReference(pPathNodeDoor);
            bool bDoorLocked;
            bool bCanUnlockLockedDoor = m_kDoorAccessData.CanUnlockDoor(m_pPathingActorData, pPathNodeDoor, bDoorLocked);
            float fDoorCost = 0.0f;
            if (!bCanUnlockLockedDoor || bDoorLocked)
            {
                switch (m_eDoorLockDisposition)
                {
                case Pathing::ALLOW_LOCKS:
                    break;
                case Pathing::PENALIZE_LOCKS:
                    fDoorCost = 409600.0f;
                    break;
                case Pathing::IGNORE_LOCKS:
                    continue;
                }
            }
            if (reinterpret_cast<TESObjectDOOR*>(pPathNodeDoor->GetObjectReference())->IsTeleportDoor())
                fDoorCost = 409600.0f;
            if (m_eDoorLockDisposition == Pathing::PENALIZE_LOCKS && pPathNodeDoor->GetIsHiddenDoor())
                continue;
            if (!pPathNodeDoor->Set3DObject())
                continue;
            TESObjectREFR* m_pLinkedDoorReference = pPathNodeDoor->Set3DObject()->GetLinkedDoor();
            if (!m_pLinkedDoorReference)
                continue;
            NavMeshPortalData* pExtraNavMeshPortal = m_pLinkedDoorReference->GetExtraData()->GetExtraNavMeshPortal();
            if (pExtraNavMeshPortal)
            {
                const NavMeshInfo* pNextMesh =
                    g_TES->GetActiveCell(pExtraNavMeshPortal->m_uiNavMeshID)->FindReferenceByFormId();
                if (pNextMesh && !pNextMesh->FUN_0068f320())
                {
                    NiPoint3 Start = m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition
                                                                              : m_pNavigationMesh->m_kNavMeshPosition;
                    NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
                    float fConnectionCost = (m_pLinkedDoorReference->Set3DObject()->GetPosition() - Start).Length() +
                                            (Goal - pPathNodeDoor->Set3DObject()->GetPosition()).Length();
                    fConnectionCost *= fCostMultiplier;
                    fConnectionCost *= 3.0;
                    fConnectionCost += fInitialCost;
                    fConnectionCost += fDoorCost;
                    AStarNodeType* pNewAStarNode;
                    switch (
                        CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
                    {
                    case ASTARNODE_CREATED:
                        pNewAStarNode->ObjectResolver = pNextMesh;
                        if (m_bUseGoalDistanceHeuristic)
                            pNewAStarNode->m_fCost = pNode->GetHeuristic() * 2;
                        else
                            pNewAStarNode->m_fCost = 1.0f;
                    case ASTARNODE_UPDATED:
                        pNewAStarNode->m_kOpenListLink = pPathNodeDoor;
                        pConnections->Add(pNewAStarNode);
                        break;
                    }
                }
            }
        }
    }
    return true;
}

struct RefA
{
    char b[12];
    RefA();
};
struct FUN_00501cd0
{
    char b[8];
    FUN_00501cd0();
};
struct FUN_006b8d90
{
    virtual ~FUN_006b8d90();
    char pad[0x2054];
    FUN_006b8d90();
};
struct FUN_006b8340 : public FUN_006b8d90
{
    RefA a;
    int i1;
    RefA b;
    int i2;
    int i3;
    char pad2[8];
    FUN_00501cd0 c;
    FUN_006b8340();
    virtual ~FUN_006b8340();
};
// Initializes the three integer members i1, i2 and i3 to zero.
// @fnv 0x006b8340
FUN_006b8340::FUN_006b8340()
{
    i3 = 0;
    i1 = 0;
    i2 = 0;
}

struct DoorLockX
{
    char b[8];
    ~DoorLockX();
};
struct FUN_006b8e40
{
    virtual ~FUN_006b8e40();
    char pad[0x2080];
};
struct FUN_006b8420 : public FUN_006b8e40
{
    DoorLockX lock;
    virtual ~FUN_006b8420();
};
// Destructor for FUN_006b8420; destroys the embedded lock member and the base FUN_006b8e40.
// @fnv 0x006b8420
FUN_006b8420::~FUN_006b8420()
{}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b83f0_shell : public FUN_006b8420
{
    void* DestroyAndFree(unsigned int flags);
};

// Runs the base destructor, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006b83f0
void* FUN_006b83f0_shell::DestroyAndFree(unsigned int flags)
{
    FUN_006b8420::~FUN_006b8420();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct NavMeshInfo;
struct NavMeshInfoMap
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void virtC8(int);
    void InsertNavMeshInfo(NavMeshInfo*);
};
struct DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
};
struct StandInSearch : public NavMeshInfoMap
{
    char pad[0x18];
    DummyPointerMap map;
    void RegisterNavMeshInfo(TeleportableReference*);
};
// @fnv 0x006b6940
void StandInSearch::RegisterNavMeshInfo(TeleportableReference* pInfo)
{
    map.SetAt((unsigned int)pInfo->GetLinkedDoor(), (unsigned int)pInfo);
    InsertNavMeshInfo((NavMeshInfo*)pInfo);
    virtC8(1);
}

namespace fnv_006b8c50 {
struct InventoryChanges;
struct TESActorBase;
struct PathingActorData
{
    TESActorBase* m_pActorBaseFormItem;
    InventoryChanges* m_pInventoryChangesValue;
    bool m_bCanIgnoreLocks;
    char _pad_9[3];
};
typedef char _sizecheck_ActorLockData[sizeof(PathingActorData) == 12 ? 1 : -1];
struct FUN_006b8c50_shell : public NavMeshInfoSearch
{
    bool SetupNavMeshSearch(PathingActorData*, void*, void*, void*, void*, void*, void*, int);
};

class TESWorldSpace;
TESWorldSpace* __fastcall GetWorldSpace(const NavMeshInfo*);
struct NavSearch_S
{
    void FUN_006b8ec0(void*, void**, float);
    bool ProcessWithFallback(void*, void*, bool);
};
// @fnv 0x006b8c50
bool FUN_006b8c50_shell::SetupNavMeshSearch(PathingActorData* apActorLockData, void* aStartLocation, void* apStartMesh,
                                            void* aGoalLocation, void* apGoalMesh, void* apReturnNodes,
                                            void* apReturnLinks, int aeDoorLockDisposition)
{
    *(NiPoint3*)((char*)this + 0x2058) = *(const NiPoint3*)aStartLocation;
    *(void**)((char*)this + 0x2064) = apStartMesh;
    *(NiPoint3*)((char*)this + 0x2068) = *(const NiPoint3*)aGoalLocation;
    *(void**)((char*)this + 0x2074) = apGoalMesh;
    *(PathingActorData**)((char*)this + 0x2078) = apActorLockData;
    *(int*)((char*)this + 0x207c) = aeDoorLockDisposition;
    *(bool*)((char*)this + 0x2080) = false;
    if (GetWorldSpace((const NavMeshInfo*)apStartMesh) &&
        GetWorldSpace((const NavMeshInfo*)apStartMesh) == GetWorldSpace((const NavMeshInfo*)apGoalMesh))
        *(bool*)((char*)this + 0x2080) = true;
    float fstartheuristic = 3.402823466e+38F;
    if (*(bool*)((char*)this + 0x2080))
        fstartheuristic = ((NiPoint3*)((char*)this + 0x2068))
                              ->
                              operator-((*(const NavMeshInfo**)((char*)this + 0x2064))->m_kNavMeshPosition)
                              .Length() *
                          (double)0.1f;
    else
        fstartheuristic = 1.0f;
    ((NavSearch_S*)this)->FUN_006b8ec0(apStartMesh, &apStartMesh, fstartheuristic);
    if (!((NavSearch_S*)this)->ProcessWithFallback(apReturnNodes, apReturnLinks, true))
        return false;
    return true;
}
}  // namespace fnv_006b8c50

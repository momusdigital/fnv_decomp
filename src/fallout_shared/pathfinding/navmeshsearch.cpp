// fallout_shared/pathfinding/navmeshsearch.cpp: NavMeshSearch, NavMeshSearchEdges (25 functions)

#include "navmeshsearch_decls.h"

// Clears the node and link arrays, sets up start and goal points, runs the search, and optionally collects meshes from the solution.
// @fnv 0x006a6b70
bool NavMeshSearch::ComputePath(const PathingRequest* request, const NavMeshTriangleReference& start,
                                const NavMeshTriangleReference& goal, BSSimpleArray<NavMeshTriangleReference>* nodes,
                                BSSimpleArray<NavMeshTriangleEdgeReference>* links,
                                BSSimpleArray<NavMeshInfo*>* solution)
{
    m_pPathingRequest = request;
    nodes->Clear(false);
    links->Clear(false);
    NavMeshSearch::~NavMeshSearch();
    m_kStartingTriangle.m_pLocationNavMesh = start.m_pLocationNavMesh;
    m_kStartingTriangle.m_usTriangleIdentifier = start.m_usTriangleIdentifier;
    NiPoint3 center =
        m_kStartingTriangle.m_pLocationNavMesh->GetNavMeshData(m_kStartingTriangle.m_usTriangleIdentifier);
    m_kStartingTriangle.GetCenterX = center.x;
    m_kStartingTriangle.m_fCenterY = center.y;
    m_kStartingTriangle.m_fCenterZ = center.z;
    m_kGoalTriangle.m_pLocationNavMesh = goal.m_pLocationNavMesh;
    m_kGoalTriangle.m_usTriangleIdentifier = goal.m_usTriangleIdentifier;
    center = m_kGoalTriangle.m_pLocationNavMesh->GetNavMeshData(m_kGoalTriangle.m_usTriangleIdentifier);
    m_kGoalTriangle.GetCenterX = center.x;
    m_kGoalTriangle.m_fCenterY = center.y;
    m_kGoalTriangle.m_fCenterZ = center.z;
    FUN_006a7d30((m_kStartingTriangle.FUN_006a6eb0() - m_kGoalTriangle.FUN_006a6eb0()).ComputeMagnitude() * 2.0f);
    FindOrCreateSearchNode(
        FUN_006a94f0(m_kStartingTriangle.m_pLocationNavMesh, m_kStartingTriangle.m_usTriangleIdentifier),
        m_kStartingTriangle, (m_kStartingTriangle.FUN_006a6eb0() - m_kGoalTriangle.FUN_006a6eb0()).ComputeMagnitude());
    m_pNavMeshInfos = solution;
    if (m_pNavMeshInfos)
    {
        BSSimpleArray<NavMeshPtr> meshes(m_pNavMeshInfos->GetSize());
        for (unsigned int i = 0; i < m_pNavMeshInfos->GetSize(); i++)
        {
            NavMeshPtr mesh;
            if (m_pNavMeshInfos->GetAt(i)->ResolveNavMesh(mesh))
                meshes[i] = mesh;
        }
    }
    if (!Search(nodes, links, true))
        return false;
    return true;
}

// @fnv 0x006a79c0
bool NavMeshSearch::HasReachedGoal(const SearchNode* node)
{
    if (m_pPathingRequest && m_pPathingRequest->GetFloatAtOffset68() > 100.0)
    {
        NiPoint3 kDelta = m_kGoalTriangle.FUN_006a6eb0() - node->GetNode().FUN_006a6eb0();
        float fDistanceSquared = kDelta.GetSquaredXYLength();
        float fHeightSquared = kDelta.z * kDelta.z;
        if (m_pPathingRequest->FUN_009b0bd0() * 0.25 * m_pPathingRequest->FUN_009b0bd0() > fDistanceSquared &&
            fHeightSquared < fDistanceSquared)
            return true;
    }
    return node->GetNode().m_pLocationNavMesh == m_kGoalTriangle.m_pLocationNavMesh &&
           node->GetNode().m_usTriangleIdentifier == m_kGoalTriangle.m_usTriangleIdentifier;
}

// @fnv 0x006a6ef0
void NavMeshSearch::SetSearchNodeTriangle(SearchNode* node, NavMesh* mesh, unsigned short triangle)
{
    NavMeshTriangleReference& data = node->GetNode();
    data.m_pLocationNavMesh = mesh;
    data.m_usTriangleIdentifier = triangle;
    NiPoint3 center = mesh->GetNavMeshData(triangle);
    data.GetCenterX = center.x;
    data.m_fCenterY = center.y;
    data.m_fCenterZ = center.z;
    float distance = (data.FUN_006a6eb0() - m_kGoalTriangle.FUN_006a6eb0()).ComputeMagnitude();
    node->FUN_004f5d90(distance * double(0.01f));
}

// Calls FUN_00996800 and FUN_006a84e0, then zeroes three members.
// @fnv 0x006a7c40
NavMeshSearch::~NavMeshSearch()
{
    m_kNodeHashTable.FUN_00996800();
    AStarBucketQueue.FUN_006a84e0();
    m_pFirstNode = 0;
    m_pCurrentNode = 0;
    m_pLastCreatedNode = 0;
}

struct FUN_006a7940_shell : public PathingRequest
{
    bool FUN_006a7940();
};

// @fnv 0x006a7940
bool FUN_006a7940_shell::FUN_006a7940()
{
    return *reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0x9d);
}

struct FUN_006a7980_shell : public PathingRequest
{
    bool FUN_006a7980();
};

// @fnv 0x006a7980
bool FUN_006a7980_shell::FUN_006a7980()
{
    return *((bool*)this + 0xa2);
}

struct FUN_006a79a0_shell : public PathingRequest
{
    bool FUN_006a79a0();
};

// @fnv 0x006a79a0
bool FUN_006a79a0_shell::FUN_006a79a0()
{
    return *((bool*)((unsigned char*)this + 0xA4));
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_006a7ad0(unsigned int f);
};
// @fnv 0x006a7ad0
bool S3e60::FUN_006a7ad0(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

namespace fnv_006a7af0 {
struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_006a7af0(unsigned int f);
};
// @fnv 0x006a7af0
bool S3e60::FUN_006a7af0(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}
}  // namespace fnv_006a7af0

class Date
{
  public:
    ~Date();
};

class FUN_00982610_Type
{
  public:
    int pad[4];
    ~FUN_00982610_Type();
};

struct FUN_006a7bc0_Class
{
    virtual ~FUN_006a7bc0_Class();
    FUN_00982610_Type m_sub0;
    Date m_date1;
    char m_auiShapeKeys[0x1ff4 - 0x14 - sizeof(Date)];
    Date m_date2;
};

// Destructor for FUN_006a7bc0_Class; the body is empty, so member destructors run implicitly.
// @fnv 0x006a7bc0
FUN_006a7bc0_Class::~FUN_006a7bc0_Class()
{}

struct PNode;
struct HX
{
    bool FUN_006a8290(PNode*, BSSimpleArray<NavMeshTriangleReference, 1024>*, BSSimpleArray<EdgeExtraInfo, 1024>*);
};
struct S20
{
    int a[5];
};
struct S12
{
    int a[3];
};
struct H1
{
    void FUN_006a8750(unsigned int, int);
};
struct H2
{
    void FUN_006a8890(int, int);
};
struct H3
{
    S12* FUN_006a1440(unsigned short);
};
struct H4
{
    S20* FUN_006b3160(unsigned int);
};
struct PNode
{
    char pad[8];
    S20 f;
    S12 e;
    PNode* next;
};
// @fnv 0x006a8290
bool HX::FUN_006a8290(PNode* apFinalNode, BSSimpleArray<NavMeshTriangleReference, 1024>* arr,
                      BSSimpleArray<EdgeExtraInfo, 1024>* arrEdges)
{
    PNode* pNode;
    int iElementIndex;
    int icount;
    if (!apFinalNode)
        return false;
    icount = 0;
    pNode = apFinalNode;
    while (pNode)
    {
        icount = icount + 1;
        pNode = pNode->next;
    }
    ((H1*)arr)->FUN_006a8750(icount, 1);
    ((H2*)arrEdges)->FUN_006a8890(icount - 1, 1);
    pNode = apFinalNode;
    iElementIndex = icount - 1;
    while (pNode)
    {
        *((H4*)arr)->FUN_006b3160(iElementIndex) = pNode->f;
        if (iElementIndex > 0)
            *((H3*)arrEdges)->FUN_006a1440(iElementIndex - 1) = pNode->e;
        pNode = pNode->next;
        iElementIndex = iElementIndex - 1;
    }
    return true;
}

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x006a84e0
void __fastcall FUN_006a84e0(char* this_ptr)
{
    memset(this_ptr + 4, 0, 0x50);
}

struct FUN_006a94f0_shell : public NavMeshSearch
{
    unsigned int FUN_006a94f0(NavMesh*, unsigned short);
};

unsigned int __fastcall _ref_0084e3a0(NavMesh*);

// @fnv 0x006a94f0
unsigned int FUN_006a94f0_shell::FUN_006a94f0(NavMesh* apNavMesh, unsigned short aiTri)
{
    return ((_ref_0084e3a0(apNavMesh) & 0xFFFF) << 16) | aiTri;
}

struct P3
{
    void Set(float, float, float);
};

struct GetCenterX_006a6eb0
{
    char pad[8];
    float x;
    float y;
    float z;
    P3* FUN_006a6eb0(P3* ret);
};

// Copies the object's x, y and z into the returned P3 via Set and returns it.
// @fnv 0x006a6eb0
P3* GetCenterX_006a6eb0::FUN_006a6eb0(P3* ret)
{
    ret->Set(x, y, z);
    return ret;
}

extern int DAT_0106b63c;
struct FUN_006a7b10
{
    FUN_006a7b10();
    ~FUN_006a7b10();
};
struct FUN_00501cd0_s
{
    void FUN_00501cd0();
};
namespace FUN_006a6a40 {
struct NavMeshSearch : public ::FUN_006a7b10
{
    NavMeshSearch();
};
}

// Constructor: installs the vtable, constructs the sub-object at offset 0x208c, and zeroes fields at 0x2058, 0x2084 and 0x2088.
// @fnv 0x006a6a40
FUN_006a6a40::NavMeshSearch::NavMeshSearch()
{
    *(int**)this = &DAT_0106b63c;
    ((FUN_00501cd0_s*)((char*)this + 0x208c))->FUN_00501cd0();
    *(int*)((char*)this + 0x2058) = 0;
    *(int*)((char*)this + 0x2084) = 0;
    *(int*)((char*)this + 0x2088) = 0;
}

namespace stub {
struct FUN_006a7bc0_Class
{
    virtual void Unused0();
    ~FUN_006a7bc0_Class();
    char pad[0x2054];
};
struct DoorAccessData
{
    ~DoorAccessData();
    int a;
};
}
namespace FUN_006a6b00 {
struct NavMeshSearch : public stub::FUN_006a7bc0_Class
{
    ~NavMeshSearch();
    char pad[0x34];
    stub::DoorAccessData lock;
};
}

// Destructor for NavMeshSearch; destroys the embedded lock member and the base class.
// @fnv 0x006a6b00
FUN_006a6b00::NavMeshSearch::~NavMeshSearch()
{}

namespace fnv_006a7b10 {
class NavMeshInfo;
class TESObjectREFR;
struct FUN_006a8380
{
    FUN_006a8380();
    ~FUN_006a8380();
    char pad[0x10];
};
struct FUN_006b3de0
{
    FUN_006b3de0();
    ~FUN_006b3de0();
    char pad[0x1fe0];
};
template <class A, class B> struct AStarOpenList
{
    AStarOpenList();
    char pad[0x54];
};
namespace FUN_006a7b10 {
struct FUN_006a7bc0_Class
{
    virtual void Unused0();
    FUN_006a7bc0_Class();
    FUN_006a8380 m04;
    FUN_006b3de0 m14;
    AStarOpenList<const NavMeshInfo*, TESObjectREFR*> m1ff4;
    int m2048;
    int m204c;
    int m2050;
    bool m2054;
};
}

// Initializes the three integer fields at offsets 0x2048, 0x204c and 0x2050 to zero and the bool at 0x2054 to false.
// @fnv 0x006a7b10
FUN_006a7b10::FUN_006a7bc0_Class::FUN_006a7bc0_Class()
{
    m2048 = 0;
    m204c = 0;
    m2050 = 0;
    m2054 = false;
}
}  // namespace fnv_006a7b10

struct FUN_006a7960_class
{
    char GetByteAtOffset9E();
};

// @fnv 0x006a7960
char FUN_006a7960_class::GetByteAtOffset9E()
{
    return ((char*)this)[0x9e];
}

struct FUN_00aa5410_Helper
{
    int InitWithAlignedSize(unsigned int);
    FUN_00aa5410_Helper* FUN_006a8380();
};

// @fnv 0x006a8380
FUN_00aa5410_Helper* FUN_00aa5410_Helper::FUN_006a8380()
{
    InitWithAlignedSize(0x7800);
    return this;
}

struct FUN_006a8490_node
{
    char pad[0x2c];
    FUN_006a8490_node* pPrev;  // +0x2c
    FUN_006a8490_node* pNext;  // +0x30
};

struct FUN_006a8490_class
{
    void UnlinkNode(FUN_006a8490_node* pNode);
};

// Unlinks pNode from its doubly linked list by patching its neighbours' pointers, then clears pNode's own pPrev and pNext.
// @fnv 0x006a8490
void FUN_006a8490_class::UnlinkNode(FUN_006a8490_node* pNode)
{
    if (pNode->pPrev != 0)
    {
        *reinterpret_cast<FUN_006a8490_node**>(pNode->pPrev) = pNode->pNext;
    }
    if (pNode->pNext != 0)
    {
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pNode->pPrev = 0;
    pNode->pNext = 0;
}

struct A83A0ScrapHeap;

void* operator new(unsigned int uiSize, A83A0ScrapHeap* pkHeap);

struct A83A0Node
{
    A83A0Node();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct A83A0ScrapHeap
{
    A83A0Node* CreateNode();
};

// Allocates an A83A0Node from this scrap heap and returns it.
// @fnv 0x006a83a0
A83A0Node* A83A0ScrapHeap::CreateNode()
{
    A83A0Node* pkNode = new (this) A83A0Node;
    return pkNode;
}

struct SortNode
{
    unsigned int unk00;
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
    SortNode** m_ppPrevious;
    SortNode* m_pNext;
    float GetKey();
};

class FUN_006a83f0_cls
{
  public:
    unsigned int m_uiItemCount;
    SortNode* m_buckets[1];
    unsigned int GetScaledValue(SortNode* node);
    void InsertSortedNode(SortNode* node);
};

// Computes a bucket index for node, walks the bucket's list while keys are smaller, then links node into the list at that position.
// @fnv 0x006a83f0
void FUN_006a83f0_cls::InsertSortedNode(SortNode* node)
{
    unsigned int idx = GetScaledValue(node);
    SortNode** pp = &m_buckets[idx];
    SortNode** slot = pp;
    while (*slot != 0 && (double)(*slot)->GetKey() < node->GetKey())
    {
        slot = &(*slot)->m_pNext;
    }
    if (*slot != 0)
    {
        (*slot)->m_ppPrevious = &node->m_pNext;
    }
    node->m_pNext = *slot;
    node->m_ppPrevious = slot;
    *slot = node;
}

extern double DAT_01012060, DAT_01016408, DAT_01011588, DAT_0101ff40;
extern float DAT_01016410, DAT_0101712c, DAT_0101e570, DAT_010231a0;
extern float DAT_0106b648, DAT_0102b3c8;

struct NavMeshPointLength : NiPoint3
{
    float FUN_00457990();
};

struct NavMeshSearchEdges : NavMeshSearch
{
    bool FindEdgeConnections(const SearchNode* current, BSSimpleArray<SearchNode*>* connections);
};

// @fnv 0x006a6fa0
bool NavMeshSearchEdges::FindEdgeConnections(const SearchNode* current, BSSimpleArray<SearchNode*>* connections)
{
    const NavMeshTriangleReference& currentNode = current->GetNode();
    for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex)
    {
        NavMesh* neighborMesh;
        unsigned short neighborTriangle;
        int outEdge;
        {
            NavMeshTriangle* triangle;
            NavMeshInfo* info;
            if (m_pNavMeshInfos != 0)
            {
                triangle = currentNode.m_pLocationNavMesh->FUN_005582f0(currentNode.m_usTriangleIdentifier);
                if (triangle->IsEdgeFlagSet(edgeIndex))
                {
                    info = currentNode.m_pLocationNavMesh->GetEdge(triangle->FUN_0068f2c0(edgeIndex))->info;
                    if (m_pNavMeshInfos->Find(info, 0, FUN_009a3830) == (unsigned int)-1)
                        continue;
                }
            }
            {
                EdgeExtraInfo* edgeInfoA;
                float usePenalty6;
                float stancePenalty4;
                bool nextCrouchX;
                bool currentCrouch3;
                float revisitPenalty4;
                float baseDistance7;
                SearchNode* resultNodeA;
                if (currentNode.m_pLocationNavMesh->FindAdjacentTriangle(currentNode.m_usTriangleIdentifier, edgeIndex,
                                                                         neighborMesh, neighborTriangle, outEdge))
                {
                    edgeInfoA =
                        currentNode.m_pLocationNavMesh->GetEdgeInfo(currentNode.m_usTriangleIdentifier, edgeIndex);
                    if (edgeInfoA != 0 && edgeInfoA->type == 1)
                        continue;
                    if (currentNode.m_pLocationNavMesh == neighborMesh &&
                        currentNode.m_usTriangleIdentifier == neighborTriangle)
                        continue;
                    if (m_pPathingRequest->FUN_006a78f0() > 0.0)
                    {
                        NiPoint3 centerA = neighborMesh->GetNavMeshData(neighborTriangle);
                        NiPoint3 toDestination = centerA - m_pPathingRequest->FUN_006a7910();
                        if (toDestination.FUN_004a7290() >
                            m_pPathingRequest->FUN_006a78f0() * m_pPathingRequest->FUN_006a78f0())
                            continue;
                    }
                    usePenalty6 = 1.0f;
                    if (neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x1000))
                    {
                        if (m_pPathingRequest->FUN_0073cb80())
                            continue;
                        else
                        {
                            bool canUnlock3;
                            const PathingActorData* lockData7;
                            unsigned int doorID = neighborMesh->GetClosedDoorInfo(neighborTriangle)->door;
                            TESObjectREFR* doorRef = (TESObjectREFR*)TESForm::GetFormByID(doorID);
                            if (doorRef != 0)
                            {
                                if (!m_pPathingRequest->FUN_006a79a0())
                                {
                                    if (doorRef->FUN_0057b460())
                                        continue;
                                    m_kDoorAccessData.SetDoorReference(doorRef);
                                    lockData7 = m_pPathingRequest->FUN_006c9900();
                                    if (!m_kDoorAccessData.CanUnlockDoor(lockData7, doorRef, canUnlock3))
                                        continue;
                                }
                                if (((TESObjectDOOR*)doorRef->GetObjectReference())->IsTeleportDoor())
                                    usePenalty6 = DAT_01016410;
                            }
                        }
                    }
                    if (m_pPathingRequest->GetFloatAtOffset68() > DAT_011d6ef0.Float()->f &&
                        neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x10))
                        continue;
                    stancePenalty4 = 1.0f;
                    nextCrouchX = neighborMesh->FUN_005582f0(neighborTriangle)->FUN_006a5ec0();
                    currentCrouch3 = currentNode.FUN_006a78d0()->FUN_006a5ec0();
                    if (!m_pPathingRequest->FUN_006a7940() && !m_pPathingRequest->GetByteAtOffset9E())
                    {
                        if (nextCrouchX)
                            continue;
                    }
                    else if (nextCrouchX != currentCrouch3)
                        stancePenalty4 = DAT_0101712c;
                    else if (nextCrouchX)
                        stancePenalty4 = DAT_0101e570;
                    revisitPenalty4 = 1.0f;
                    if (m_pNavMeshTriangleEdges != 0)
                    {
                        for (unsigned int i = 0; i < m_pNavMeshTriangleEdges->GetSize(); ++i)
                        {
                            if (m_pNavMeshTriangleEdges->GetAt(i).m_usTriangleIdentifier ==
                                    current->Node.m_usTriangleIdentifier &&
                                m_pNavMeshTriangleEdges->GetAt(i).m_pLocationNavMesh ==
                                    current->Node.m_pLocationNavMesh &&
                                m_pNavMeshTriangleEdges->GetAt(i).m_iEdgeIndex == edgeIndex)
                            {
                                revisitPenalty4 = DAT_01016410;
                                break;
                            }
                        }
                    }
                    {
                        NiPoint3 nextCenter = neighborMesh->GetNavMeshData(neighborTriangle);
                        NiPoint3 currentCenter5 = current->GetNode().FUN_006a6eb0();
                        baseDistance7 = (nextCenter - currentCenter5).FUN_00589850();
                        if (neighborMesh->FUN_005582f0(neighborTriangle)->HasFlag40())
                            baseDistance7 *= DAT_01016408;
                        if (m_pPathingRequest != 0 && m_pPathingRequest->GetString() != 0)
                        {
                            float avoidance = m_pPathingRequest->GetString()->GetAvoidanceAtPoint(nextCenter);
                            if (avoidance > 0.0)
                                baseDistance7 *= 1.0f + avoidance;
                        }
                        if (neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x80000000))
                        {
                            BSSimpleArray<NavMeshStaticAvoidNode*> staticAvoids;
                            if (neighborMesh->GetStaticAvoidNodesForTriangle(neighborTriangle, staticAvoids))
                            {
                                float staticPenalty = 0.0f;
                                for (unsigned int i = 0; i < staticAvoids.GetSize(); ++i)
                                    staticPenalty += staticAvoids.GetAt(i)->GetFloatAtOffset1C();
                                baseDistance7 *= staticPenalty;
                            }
                        }
                        NiPoint3 edgeStart, edgeEnd5;
                        neighborMesh->GetEdgeVertices(neighborTriangle, outEdge, edgeStart, edgeEnd5);
                        float edgeLength = (edgeStart - edgeEnd5).FUN_00589850();
                        float maxEdgeLength6 = DAT_010231a0;
                        float narrowPenalty2 = 1.0f - edgeLength / maxEdgeLength6;
                        FUN_005330e0(narrowPenalty2, 0.0f, 1.0f);
                        baseDistance7 *= narrowPenalty2 * DAT_01011588 + DAT_01011588;
                        baseDistance7 *= stancePenalty4;
                        baseDistance7 *= revisitPenalty4;
                        baseDistance7 *= usePenalty6;
                        if (m_pPathingRequest->FUN_006a7980())
                        {
                            NiPoint3 goalVector = m_kStartingTriangle.FUN_006a6eb0() - m_kGoalTriangle.FUN_006a6eb0();
                            NiPoint3 nodeVector = nextCenter - m_kGoalTriangle.FUN_006a6eb0();
                            float goalDistance8 = GetDirectionAngle(goalVector);
                            float nodeDistance3 = GetDirectionAngle(nodeVector);
                            float difference7 = nodeDistance3 - goalDistance8;
                            WrapValueToRange(difference7, DAT_0106b648, DAT_0102b3c8);
                            difference7 = std::abs(difference7);
                            float goalLength7 = static_cast<NavMeshPointLength&>(goalVector).FUN_00457990();
                            float adjustedTmp = (DAT_0101ff40 - difference7) * goalLength7 / DAT_0101ff40;
                            float nodeLength_ = static_cast<NavMeshPointLength&>(nodeVector).FUN_00457990();
                            baseDistance7 *= std::abs(nodeLength_ - adjustedTmp) * DAT_0119cdf8;
                        }
                        baseDistance7 += current->GetCost();
                        switch (CreateOrUpdateNode(FUN_006a94f0(neighborMesh, neighborTriangle), baseDistance7,
                                                   resultNodeA))
                        {
                        case 0:
                            SetSearchNodeTriangle(resultNodeA, neighborMesh, neighborTriangle);
                        case 1:
                            resultNodeA->Link.m_pLocationNavMesh = current->Node.m_pLocationNavMesh;
                            resultNodeA->Link.m_usTriangleIdentifier = current->Node.m_usTriangleIdentifier;
                            resultNodeA->Link.m_iEdgeIndex = edgeIndex;
                            connections->Add(resultNodeA);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
    return true;
}

struct blob12
{
    char b[12];
};
struct FUN_006a7910_shell : public PathingRequest
{
    struct blob12 FUN_006a7910();
};

// @fnv 0x006a7910
struct blob12 FUN_006a7910_shell::FUN_006a7910()
{
    return *reinterpret_cast<const blob12*>(reinterpret_cast<const char*>(this) + 0x7C);
}

struct FUN_006a6ad0 : public FUN_006a7b10
{
    virtual ~FUN_006a6ad0();
};
// @fnv 0x006a6ad0
FUN_006a6ad0::~FUN_006a6ad0()
{}

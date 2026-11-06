// fallout_shared/pathfinding/navmeshsearch_decls.h: declares NiPoint3, NavMeshTriangle, EdgeExtraInfo, NavMeshEdgeExtra, NavMeshClosedDoorInfo and more
#ifndef NAVMESHSEARCH_DECLS_H
#define NAVMESHSEARCH_DECLS_H

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
    float ComputeMagnitude();
    float FUN_004a7290() const;
    float FUN_00589850() const;
    float GetSquaredXYLength() const;
};
class NavMesh;
class NavMeshInfo;
class NavMeshStaticAvoidNode;
class TESObjectREFR;
class PathingActorData;
class PathingAvoidNodeArray;
template <class T, int N = 1024> class BSSimpleArray
{
  public:
    void* vtable;
    T* pBase;
    unsigned int uiSize, uiAllocSize;
    BSSimpleArray();
    BSSimpleArray(unsigned int);
    ~BSSimpleArray();
    unsigned int GetSize();
    T& GetAt(int);
    T& operator[](unsigned int);
    void Clear(bool);
    unsigned int Add(T&);
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
};
class NavMeshTriangle
{
  public:
    bool IsEdgeFlagSet(int);
    unsigned short FUN_0068f2c0(int);
    bool FUN_00691140(unsigned int);
    bool FUN_006a5ec0();
    bool HasFlag40();
};
class EdgeExtraInfo
{
  public:
    int type;
};
class NavMeshEdgeExtra
{
  public:
    unsigned int unknown;
    NavMeshInfo* info;
};
class NavMeshClosedDoorInfo
{
  public:
    unsigned int door;
};
class NavMesh
{
  public:
    NiPoint3 GetNavMeshData(unsigned short);
    NavMeshTriangle* FUN_005582f0(unsigned short);
    NavMeshEdgeExtra* GetEdge(unsigned short);
    bool FindAdjacentTriangle(unsigned short, int, NavMesh*&, unsigned short&, int&);
    EdgeExtraInfo* GetEdgeInfo(unsigned short, int);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
    bool GetStaticAvoidNodesForTriangle(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode*>&);
    void GetEdgeVertices(unsigned short, int, NiPoint3&, NiPoint3&);
};
class NavMeshTriangleReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX, m_fCenterY, m_fCenterZ;
    NiPoint3 FUN_006a6eb0() const;
    NavMeshTriangle* FUN_006a78d0() const;
};
class NavMeshTriangleEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    int m_iEdgeIndex;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int key;
    float cost;
    N Node;
    L Link;
    N& GetNode() const;
    void FUN_004f5d90(float);
    float GetCost() const;
};
typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> SearchNode;
class NavMeshStaticAvoidNode
{
  public:
    float GetFloatAtOffset1C();
};
class PathingAvoidNodeArray
{
  public:
    float GetAvoidanceAtPoint(NiPoint3&);
};
class PathingRequest
{
  public:
    float FUN_006a78f0() const;
    NiPoint3 FUN_006a7910() const;
    bool FUN_0073cb80() const;
    bool FUN_006a79a0() const;
    const PathingActorData* FUN_006c9900() const;
    float GetFloatAtOffset68() const;
    float FUN_009b0bd0() const;
    bool FUN_006a7940() const;
    bool GetByteAtOffset9E() const;
    bool FUN_006a7980() const;
    PathingAvoidNodeArray* GetString() const;
};
class TESForm
{
  public:
    static TESForm* GetFormByID(unsigned int);
};
class TESBoundObject
{
};
class TESObjectDOOR : public TESBoundObject
{
  public:
    bool IsTeleportDoor();
};
class TESObjectREFR : public TESForm
{
  public:
    bool FUN_0057b460();
    TESBoundObject* GetObjectReference();
};
class DoorAccessData
{
  public:
    unsigned int fields[6];
    void SetDoorReference(TESObjectREFR*);
    bool CanUnlockDoor(const PathingActorData*, TESObjectREFR*, bool&);
};
class AStarMapNav
{
  public:
    char storage[0x1fe0];
    void FUN_00996800();
};
class AStarQueueNav
{
  public:
    char storage[0x54];
    void FUN_006a84e0();
};
class NavMeshSearch
{
  public:
    char Heap[0x14];
    AStarMapNav m_kNodeHashTable;
    AStarQueueNav AStarBucketQueue;
    SearchNode* m_pFirstNode;
    SearchNode* m_pCurrentNode;
    SearchNode* m_pLastCreatedNode;
    unsigned int searchState;
    const PathingRequest* m_pPathingRequest;
    NavMeshTriangleReference m_kStartingTriangle, m_kGoalTriangle;
    BSSimpleArray<NavMeshTriangleEdgeReference>* m_pNavMeshTriangleEdges;
    BSSimpleArray<NavMeshInfo*>* m_pNavMeshInfos;
    DoorAccessData m_kDoorAccessData;
    bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*>*);
    bool ComputePath(const PathingRequest*, const NavMeshTriangleReference&, const NavMeshTriangleReference&,
                     BSSimpleArray<NavMeshTriangleReference>*, BSSimpleArray<NavMeshTriangleEdgeReference>*,
                     BSSimpleArray<NavMeshInfo*>*);
    void SetSearchNodeTriangle(SearchNode*, NavMesh*, unsigned short);
    bool HasReachedGoal(const SearchNode*);
    ~NavMeshSearch();
    void FUN_006a7d30(float);
    SearchNode* FindOrCreateSearchNode(unsigned int, const NavMeshTriangleReference&, float);
    bool Search(BSSimpleArray<NavMeshTriangleReference>*, BSSimpleArray<NavMeshTriangleEdgeReference>*, bool);
    unsigned int FUN_006a94f0(NavMesh*, unsigned short);
    int CreateOrUpdateNode(unsigned int, float, SearchNode*&);
};
class NavMeshPtr
{
  public:
    NavMesh* ptr;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
};
class NavMeshInfo
{
  public:
    bool ResolveNavMesh(NavMeshPtr&);
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ DAT_011d6ef0;
extern float DAT_0119cdf8;
namespace std {
float abs(float);
}
float GetDirectionAngle(const NiPoint3&);
void WrapValueToRange(float&, float, float);
void FUN_005330e0(float&, float, float);
bool FUN_009a3830(NavMeshInfo*&, NavMeshInfo*&);
#endif

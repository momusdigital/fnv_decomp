// fallout_shared/pathfinding/navmesh_util_decls.h: declares NiPoint3, TwoIntRecord, NavMeshEdgeData, NavMeshTriangleHandle, NavMeshPOVData and more
#ifndef NAVMESH_UTIL_DECLS_H
#define NAVMESH_UTIL_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
namespace std {
float abs(float);
}
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3 Cross(const NiPoint3&) const;
    NiPoint3 CrossProduct(const NiPoint3&) const;
    void ComputeMagnitude();
    float DotProduct(const NiPoint3&) const;
    float FUN_00589850() const;
    float GetSquaredXYLength() const;
    static const NiPoint3 ZERO;
};
bool FUN_006b9cf0(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, float&, float, float);
class NavMesh;
class TwoIntRecord
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usVertexId;
    TwoIntRecord();
    TwoIntRecord(NavMesh*, unsigned short);
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
};
class NavMeshEdgeData
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    NavMeshEdgeData();
    NavMeshEdgeData(NavMesh*, unsigned short, int);
    NavMeshEdgeData& operator=(const NavMeshEdgeData&);
};
class NavMeshTriangleHandle
{
  public:
    unsigned short m_usIndex;
    void Set(const NavMeshEdgeData&);
};
class NavMeshPOVData
{
  public:
    NavMeshTriangleHandle m_kFirstEdge, m_kSecondEdge;
};
template <class T, int N = 1024> class BSSimpleArray
{
  public:
    void* vtable;
    T* data;
    unsigned int size, capacity;
    BSSimpleArray();
    ~BSSimpleArray();
    unsigned int GetSize();
    void Clear(bool);
    unsigned int ReserveIndex(const T&);
    T& FUN_006a1440(unsigned int);
    unsigned short& GetBufferEntry(unsigned int);
    unsigned int AppendElement(const T&);
    unsigned int Append(const T&);
    T& GetElement(unsigned int);
};
class NavMeshVertexEdgeData
{
  public:
    TwoIntRecord m_kVertexKey;
    BSSimpleArray<NavMeshEdgeData> Edges, m_kOutgoingEdges;
    NavMeshVertexEdgeData();
    ~NavMeshVertexEdgeData();
};
template <class K, class V> class NiTPointerMap
{
  public:
    void* vtable;
    unsigned int hashSize;
    void* table;
    unsigned int count;
    void RemoveAll();
    void* GetFirstPos();
    void InsertOrUpdate(unsigned short, NavMeshPOVData);
    void FUN_00694d30(void*&, unsigned short&, NavMeshPOVData&);
};
class NavMeshVertexMap
{
  public:
    void* vtable;
    unsigned int hashSize;
    void* table;
    unsigned int count;
    NavMeshVertexMap(unsigned int);
    ~NavMeshVertexMap();
    void* GetFirstPos();
    bool FUN_0069b4d0(TwoIntRecord, NavMeshVertexEdgeData*&);
    void SetKeyValue(TwoIntRecord, NavMeshVertexEdgeData*);
    void GetNextEntry(void*&, TwoIntRecord&, NavMeshVertexEdgeData*&);
};
class NavMeshTriangle
{
  public:
    unsigned short FUN_005582d0(int);
    unsigned short FUN_0068f2c0(int);
    bool IsEdgeFlagSet(int);
    void FUN_00691570(unsigned int);
};
struct NavMeshEdgeVertexPair
{
    const NiPoint3* first;
    const NiPoint3* second;
};
class NavMeshClosedDoorInfo
{
  public:
    unsigned int iDoorID;
    unsigned short m_usTriangleID;
    NavMeshClosedDoorInfo();
};
class ObstacleData
{
  public:
    unsigned char prefix[0x40];
    NiPoint3 m_kBoundsMin, m_kBoundsMax;
};
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer(T*);
    NiPointer(const NiPointer&);
    ~NiPointer();
};
class NavMesh
{
  public:
    unsigned char prefix[0x68];
    BSSimpleArray<NavMeshClosedDoorInfo> m_kClosedDoorInfo;
    BSSimpleArray<unsigned short> m_kIndexList;
    NiTPointerMap<unsigned int, unsigned int> POVPointerArray;
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
    void InitializeNavMeshData();
    unsigned int FUN_00558200();
    NavMeshTriangle* GetTriangle(unsigned short);
    const NiPoint3& FUN_0068f0a0(unsigned short);
    NavMeshEdgeVertexPair FUN_0068f040(unsigned short, int);
    NiPoint3 FUN_00697290(unsigned short);
    void GetOverlappedTriangleList(const NiPointer<ObstacleData>&, const NiPoint3&, BSSimpleArray<unsigned short>*);
    NiPoint3 GetPlaneNormal(unsigned short);
    bool AddDoorObstacle(unsigned int, ObstacleData*);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
    bool FindHeightOnTriangle(unsigned short, const NiPoint3&, float&, float, float);
};
#endif
class SineCosine
{
  public:
    float sine, cosine;
    SineCosine operator-(const SineCosine&) const;
    float FUN_006a0840() const;
};
class CircularArc
{
  public:
    SineCosine Start, End;
    int Dir;
    float GetLength(float);
};

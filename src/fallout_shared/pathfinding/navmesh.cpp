// fallout_shared/pathfinding/navmesh.cpp: NavMesh, ActorMover, BGSCameraPath, TESEffectShader and more (97 functions)

class ActorMover
{
  public:
    char _pad24[0x24];
    unsigned int preferredMoveMode;
    unsigned int GetCurrentMoveModeType();
};

class BGSCameraPath
{
  public:
    char _pad34[0x34];
    BGSCameraPath* previousPath;
    BGSCameraPath* GetPrevPath();
};

class BGSDebris;
class TESEffectShader
{
  public:
    char _pad10c[0x10c];
    BGSDebris* addonModels;
    BGSDebris* GetAddonModels();
};

class InventoryStackRecord;
class MiddleHighProcess
{
  public:
    char _pad114[0x114];
    InventoryStackRecord* currentWeapon;
    InventoryStackRecord* GetActiveWeapon();
};

class EdgeExtraInfo;
class NavMeshStaticAvoidNode
{
  public:
    char _pad24[0x24];
    unsigned short triangle;
    unsigned short GetShortValueAtOffset24();
};
class NavMeshTriangle;
class NavMeshInfo;
class TESForm;
class TESObjectCELL;
class TESWorldSpace;

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};

class CoordinateTriple
{
  public:
    NiPoint3 Point;
    TESForm* m_pPathingCell;
};

template <class T> class BSSimpleList
{
  public:
    T item;
    T& GetItem();
};

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** vtable;
    T* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int GetSize();
    T& GetAt(int);
    unsigned int Add(T&);
    EdgeExtraInfo* FUN_00558dd0(unsigned short, int);
    EdgeExtraInfo* FUN_006a1440(unsigned short);
    NavMeshStaticAvoidNode* FUN_00691750(int);
    bool FUN_0076b610();
};

class EdgeExtraInfo
{
  public:
    int type;
    int portal;
    int reserved;
    bool IsEdgeFlagSet();
    unsigned short FUN_0068f2c0();
};

class PathingLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<const NavMeshInfo*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char _pad27;
    PathingLocation(const CoordinateTriple&, NavMeshInfo*, unsigned short);
    void SetAllMeshesReachable(bool);
};

class NavMeshInfo
{
  public:
    char _pad0c[0x0c];
    unsigned int locationKey;
    TESWorldSpace* GetParentWorldSpace();
    TESObjectCELL* GetInteriorCell();
};

class NavMesh
{
  public:
    char _pad38[0x38];
    BSSimpleArray<NavMeshTriangle, 1024> Triangles;
    BSSimpleArray<EdgeExtraInfo, 1024> m_kEdgeExtraInfo;
    char _pad58_f4[0x9c];
    BSSimpleArray<NavMeshStaticAvoidNode, 1024> m_kStaticAvoidNodes;
    void FUN_0042fd70(int);
    NavMeshStaticAvoidNode* GetStaticAvoidNodeData();
    EdgeExtraInfo* GetEdgeInfo(unsigned short, int);
    bool GetStaticAvoidNodesForTriangle(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode*, 1024>&);
};

// @fnv 0x0059bb30
unsigned int ActorMover::GetCurrentMoveModeType()
{
    return preferredMoveMode;
}

// @fnv 0x005f36f0
BGSCameraPath* BGSCameraPath::GetPrevPath()
{
    return previousPath;
}

// @fnv 0x005a29b0
BGSDebris* TESEffectShader::GetAddonModels()
{
    return addonModels;
}

// @fnv 0x008d81e0
InventoryStackRecord* MiddleHighProcess::GetActiveWeapon()
{
    return currentWeapon;
}

// @fnv 0x0042fb00
NavMeshStaticAvoidNode* NavMesh::GetStaticAvoidNodeData()
{
    FUN_0042fd70(0);
    return (NavMeshStaticAvoidNode*)this;
}

// @fnv 0x00691660
bool NavMesh::GetStaticAvoidNodesForTriangle(unsigned short triangle,
                                             BSSimpleArray<NavMeshStaticAvoidNode*, 1024>& arOutput)
{
    unsigned int i = 0;
    for (; i < ((BSSimpleArray<NavMeshInfo*, 1024>&)m_kStaticAvoidNodes).GetSize(); ++i)
    {
        if (m_kStaticAvoidNodes.FUN_00691750(i)->GetShortValueAtOffset24() == triangle)
        {
            NavMeshStaticAvoidNode* node = m_kStaticAvoidNodes.FUN_00691750(i);
            ((BSSimpleArray<NavMeshInfo*, 1024>&)arOutput).Add(*(NavMeshInfo**)&node);
        }
    }
    return !arOutput.FUN_0076b610();
}

// Initializes a PathingLocation from a location, NavMeshInfo and triangle index, storing the navmesh's cell or location key and marking all meshes reachable.
// @fnv 0x006dd010
PathingLocation::PathingLocation(const CoordinateTriple& location, NavMeshInfo* navMesh, unsigned short triangle)
{
    m_ppVirtualMethodTable = (void**)0x0102583c;
    ((BSSimpleList<InventoryStackRecord*>*)&Location)->GetItem();
    Location = location.Point;
    uiFlags = 0;
    m_pLocationNavMesh = navMesh;
    pNavMeshInfoArray = 0;
    m_pContainingWorldspace = navMesh->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = navMesh->locationKey;
    }
    else
    {
        pCell = navMesh->GetInteriorCell();
        m_uiPathingFlags = 0xdeaddead;
    }
    SetAllMeshesReachable(true);
    m_usTriangleID = triangle;
}

struct BSExtraData
{
    virtual void vb();
    char pad[8];
    BSExtraData(unsigned char);
    ~BSExtraData();
};
struct TwoIntRecord
{
    int h[2];
    TwoIntRecord(const TwoIntRecord&);
};
extern int DAT_01014618;
struct FUN_00416ad0 : public BSExtraData
{
    TwoIntRecord vh;
    FUN_00416ad0(TwoIntRecord v);
};
// @fnv 0x00416ad0
FUN_00416ad0::FUN_00416ad0(TwoIntRecord v) : BSExtraData(0x5a), vh(v)
{}

class NiAVObject
{
  public:
    void FUN_00401970();
};

// If the stored object pointer is non-null, calls FUN_00401970 on the NiAVObject at offset 0x1c within it.
// @fnv 0x0042fda0
void __fastcall FUN_0042fda0(int* pObjectPtr)
{
    if (*pObjectPtr != 0)
    {
        ((NiAVObject*)(*pObjectPtr + 0x1c))->FUN_00401970();
    }
}

struct FUN_0068ed30_shell : public NavMesh
{
    void DestroyNavMesh();
};

struct NavMeshDestructView
{
    void FUN_0068ed70();
};

class NiMemObject
{
  public:
    static void __cdecl operator delete(void*, unsigned int);
};

struct FUN_0068ed30_impl : public FUN_0068ed30_shell
{
    void* DestroyNavMesh(unsigned int flags);
};

// Calls the NavMesh destructor and, when bit 0 of flags is set, frees this with NiMemObject::operator delete; returns this.
// @fnv 0x0068ed30
void* FUN_0068ed30_impl::DestroyNavMesh(unsigned int flags)
{
    reinterpret_cast<NavMeshDestructView*>(this)->FUN_0068ed70();
    if (flags & 1)
    {
        NiMemObject::operator delete(this, 0x108);
    }
    return this;
}

struct NavMeshInfo;
struct FUN_0068efb0_shell : public NavMesh
{
    NavMeshInfo* FUN_0068efb0();
};

// @fnv 0x0068efb0
NavMeshInfo* FUN_0068efb0_shell::FUN_0068efb0()
{
    return *(NavMeshInfo**)((char*)this + 0x104);
}

struct EdgeT
{
    unsigned short a;
    unsigned short b;
};
struct EdgeV
{
    const NiPoint3* a;
    const NiPoint3* b;
};
struct NH
{
    void GetEdge(EdgeT*, unsigned short, int);
    const NiPoint3& FUN_0068f0a0(unsigned short);
};
struct FloatValueProvider : public NavMesh
{
    EdgeV FUN_0068f040(unsigned short tri, int idx);
};
// Fetches the edge indices for a triangle via GetEdge and returns pointers to the two edge vertices from FUN_0068f0a0.
// @fnv 0x0068f040
EdgeV FloatValueProvider::FUN_0068f040(unsigned short ausTriIndex, int aiEdgeIndex)
{
    EdgeT edge;
    EdgeV ev;
    ((NH*)this)->GetEdge(&edge, ausTriIndex, aiEdgeIndex);
    ev.a = &((NH*)this)->FUN_0068f0a0(edge.a);
    ev.b = &((NH*)this)->FUN_0068f0a0(edge.b);
    return ev;
}

struct FUN_0068f0a0_shell : public NavMesh
{
    void* FUN_0068f0a0(unsigned short);
};

// @fnv 0x0068f0a0
void* FUN_0068f0a0_shell::FUN_0068f0a0(unsigned short asVertexIndex)
{
    return ((BSSimpleArray<EdgeExtraInfo, 1024>*)((char*)this + 0x28))->FUN_006a1440(asVertexIndex);
}

struct EdgeExtraInfo;
struct FUN_0068f230_shell : public NavMesh
{
    EdgeExtraInfo* FUN_0068f230(unsigned short, int);
};

// @fnv 0x0068f230
EdgeExtraInfo* FUN_0068f230_shell::FUN_0068f230(unsigned short ausTriangleIndex, int aiEdgeIndex)
{
    if (Triangles.FUN_00558dd0(ausTriangleIndex, aiEdgeIndex)->IsEdgeFlagSet() &&
        Triangles.FUN_00558dd0(ausTriangleIndex, aiEdgeIndex)->FUN_0068f2c0() != 0xFFFF)
        return m_kEdgeExtraInfo.FUN_006a1440(Triangles.FUN_00558dd0(ausTriangleIndex, aiEdgeIndex)->FUN_0068f2c0());
    else
        return 0;
}

// @fnv 0x0068f320
bool __fastcall FUN_0068f320(const NavMeshInfo* apNavMeshInfo)
{
    return (*(const unsigned int*)((const char*)apNavMeshInfo + 8) & 0x10) != 0;
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESWorldSpace : public TESForm
{
};

TESForm* __fastcall GetParentSpace(const NavMeshInfo*);

// Casts the result of GetParentSpace(_this) to TESWorldSpace* and returns it.
// @fnv 0x00690800
TESWorldSpace* __fastcall GetWorldSpace(const NavMeshInfo* apNavMeshInfo)
{
    return dynamic_cast<TESWorldSpace*>(GetParentSpace(apNavMeshInfo));
}

TESForm* __cdecl _ref_004839c0(unsigned int);

// @fnv 0x00690830
TESForm* __fastcall GetParentSpace(const NavMeshInfo* pThis)
{
    if (*(TESForm**)((char*)pThis + 0x1c))
        return *(TESForm**)((char*)pThis + 0x1c);
    else
        return _ref_004839c0(*(unsigned int*)((char*)pThis + 0x4));
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct PathingAvoidanceNode
{
    float GetAvoidanceAtPoint(NiPoint3*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    NiPoint3 m_kLocation;
    NiPoint3 TwoComponentVector;
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};
typedef char _sizecheck_PathingAvoidNode[sizeof(PathingAvoidanceNode) == 36 ? 1 : -1];
struct FUN_006915d0_shell : public PathingAvoidanceNode
{
    void FUN_006915d0(void*, void*, float, float);
};

void __fastcall _ref_006815c0(NiPoint3*);

struct FUN_006915d0_helper : public PathingAvoidanceNode
{
    PathingAvoidanceNode* FUN_006915d0(const NiPoint3& arPoint, float afRadius, float afCost);
};

// @fnv 0x006915d0
PathingAvoidanceNode* FUN_006915d0_helper::FUN_006915d0(const NiPoint3& arPoint, float afRadius, float afCost)
{
    m_kLocation = arPoint;
    _ref_006815c0(&TwoComponentVector);
    fRadius = afRadius;
    m_fPathingCostCur = afCost;
    eType = 0;
    return this;
}

extern int DAT_01031fac;

struct FUN_006916f0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006916f0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006916f0
int* __fastcall FUN_006916f0(int* self, FUN_006916f0_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_00691720 {
extern int DAT_01031fac;

struct FUN_00691720_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00691720_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00691720
int* __fastcall FUN_00691720(int* self, FUN_00691720_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_00691720

// @fnv 0x00691750
template <class T, unsigned int Growth> NavMeshStaticAvoidNode* BSSimpleArray<T, Growth>::FUN_00691750(int aiIndex)
{
    return reinterpret_cast<NavMeshStaticAvoidNode*>(reinterpret_cast<char*>(buffer) + aiIndex * 0x28);
}

template NavMeshStaticAvoidNode* BSSimpleArray<NavMeshStaticAvoidNode, 1024>::FUN_00691750(int);

class GlobalObject_00869f00
{
  public:
    void* vtable;
    void Clear(bool);
};

extern void* DAT_0106abe4;

// @fnv 0x00691800
void __fastcall FUN_00691800(GlobalObject_00869f00* pThis)
{
    pThis->vtable = &DAT_0106abe4;
    pThis->Clear(true);
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x00691a60
void* __fastcall FUN_00691a60(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

extern void* DAT_0106ac2c;
struct Helper_00644400
{
    void FUN_00644400(int, int);
};

// Sets the vtable pointer and calls FUN_00644400 with 0, 0, then returns the object.
// @fnv 0x00691b10
void* __fastcall FUN_00691b10(BSSimpleArray<NavMeshTriangle, 1024>* apArray)
{
    apArray->vtable = &DAT_0106ac2c;
    reinterpret_cast<Helper_00644400*>(apArray)->FUN_00644400(0, 0);
    return apArray;
}

extern void* DAT_0106ac40;

struct FUN_006923f0_Caller
{
    void FUN_006923f0(int, int);
};

// Sets the vtable of pThis and calls FUN_006923f0 with 0, 0, then returns pThis.
// @fnv 0x00691bc0
BSSimpleArray<EdgeExtraInfo, 1024>* __fastcall FUN_00691bc0(BSSimpleArray<EdgeExtraInfo, 1024>* apArray)
{
    apArray->vtable = &DAT_0106ac40;
    reinterpret_cast<FUN_006923f0_Caller*>(apArray)->FUN_006923f0(0, 0);
    return apArray;
}

extern void* DAT_0106ac54;

struct Dummy_00691d40
{
    void FUN_00692520(int, int);
};

// Sets *thisPtr to point at DAT_0106ac54, then calls FUN_00692520 with 0, 0 and returns thisPtr.
// @fnv 0x00691d40
void* __fastcall FUN_00691d40(void** thisPtr)
{
    *thisPtr = &DAT_0106ac54;
    reinterpret_cast<Dummy_00691d40*>(thisPtr)->FUN_00692520(0, 0);
    return thisPtr;
}

struct Helper_00692520
{
    void FUN_00692520(int, int);
};

// Stores the string "@!i" at *_this, then calls FUN_00692520 with 0 and 0, and returns _this.
// @fnv 0x00691d90
const char** __fastcall FUN_00691d90(const char** _this)
{
    *_this = "@!i";
    reinterpret_cast<Helper_00692520*>(_this)->FUN_00692520(0, 0);
    return _this;
}

class NiAVObject;
template <class T> class NiPointer;
extern void* DAT_0106ac9c;
template <> class BSSimpleArray<NiPointer<NiAVObject>, 1024>
{
  public:
    void** vtable;
    void FUN_00822860(unsigned int, bool);
};

// Sets the vtable pointer and calls FUN_00822860 with 0 and false, then returns the array.
// @fnv 0x00691f60
BSSimpleArray<NiPointer<NiAVObject>, 1024>* __fastcall FUN_00691f60(BSSimpleArray<NiPointer<NiAVObject>, 1024>* _this)
{
    _this->vtable = &DAT_0106ac9c;
    _this->FUN_00822860(0, false);
    return _this;
}

namespace fnv_00691fb0 {
extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x00691fb0
void* __fastcall FUN_00691fb0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}
}  // namespace fnv_00691fb0

struct NavMeshClosedDoorInfo
{
    unsigned int m_uiDoorFormID;
    unsigned short m_usDoorTriangleIndex;
    char _pad_6[2];
};
typedef char _sizecheck_NavMeshClosedDoorInfo[sizeof(NavMeshClosedDoorInfo) == 8 ? 1 : -1];
struct FUN_00692870_shell : public NavMeshClosedDoorInfo
{
    void InitNavMeshClosedDoorInfo(void*);
};

// @fnv 0x00692870
NavMeshClosedDoorInfo* __fastcall InitNavMeshClosedDoorInfo(NavMeshClosedDoorInfo* pThis)
{
    pThis->m_uiDoorFormID = 0;
    pThis->m_usDoorTriangleIndex = 0xFFFF;
    return pThis;
}

struct G00559a40
{
    void FUN_0040f6e0();
};
struct Holder42
{
    char* p;
    Holder42* FUN_0042fd70(char*);
};
// Stores v in p and, when v is non-null, calls FUN_0040f6e0 on the object at v+0x1c; returns this.
// @fnv 0x0042fd70
Holder42* Holder42::FUN_0042fd70(char* v)
{
    p = v;
    if (p)
    {
        ((G00559a40*)(p + 0x1c))->FUN_0040f6e0();
    }
    return this;
}

namespace fnv_0068f0c0 {
struct NavMeshTriangleVertexIndices
{
    char Vertices[4];
};
typedef char _sizecheck_NavMeshEdge[sizeof(NavMeshTriangleVertexIndices) == 4 ? 1 : -1];
struct NavMeshEdgeVertexPair
{
    char Vertices[8];
};
typedef char _sizecheck_NavMeshEdgeVertices[sizeof(NavMeshEdgeVertexPair) == 8 ? 1 : -1];
struct FUN_0068f0c0_shell : public NavMesh
{
    bool GetEdgeVertices(unsigned short, int, NiPoint3*, NiPoint3*);
};

struct NavMeshTriangle
{
    unsigned short FUN_005582d0(int);
};
struct NavMesh_GetTriangle_h
{
    NavMeshTriangle* GetTriangle(unsigned short);
};
struct NH
{
    const NiPoint3& FUN_0068f0a0(unsigned short);
};

// Looks up the two vertex indices of the given triangle edge and writes their positions into p0 and p1, returning true.
// @fnv 0x0068f0c0
bool FUN_0068f0c0_shell::GetEdgeVertices(unsigned short ausTriIndex, int aiEdgeIndex, NiPoint3* pStartVertex,
                                      NiPoint3* pEndVertex)
{
    int iNext;
    unsigned short v1;
    unsigned short v0;
    v1 = ((NavMesh_GetTriangle_h*)this)->GetTriangle(ausTriIndex)->FUN_005582d0(aiEdgeIndex);
    iNext = (aiEdgeIndex + 1) % 3;
    v0 = ((NavMesh_GetTriangle_h*)this)->GetTriangle(ausTriIndex)->FUN_005582d0(iNext);
    *pStartVertex = ((NH*)this)->FUN_0068f0a0(v1);
    *pEndVertex = ((NH*)this)->FUN_0068f0a0(v0);
    return true;
}
}  // namespace fnv_0068f0c0

struct FUN_00690e10_shell
{
    char _pad0c[0x0c];
    unsigned int flags;
    bool __thiscall HasEdgeExtraInfo();
};

// @fnv 0x00690e10
bool __thiscall FUN_00690e10_shell::HasEdgeExtraInfo()
{
    return (flags & 7) != 0;
}

struct FUN_00691000_shell
{
    char _pad38[0x38];
    void FUN_00691b60(int);
    void FUN_00691000(int arg);
};

// @fnv 0x00691000
void FUN_00691000_shell::FUN_00691000(int arg)
{
    ((FUN_00691000_shell*)((char*)this + 0x38))->FUN_00691b60(arg);
}

struct FUN_00691020_shell
{
    char _pad48[0x48];
    void FUN_00691c10(int);
    void FUN_00691020(int a);
};

// @fnv 0x00691020
void FUN_00691020_shell::FUN_00691020(int a)
{
    ((FUN_00691020_shell*)((char*)this + 0x48))->FUN_00691c10(a);
}

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00691620_shell
{
    char _padf4[0xf4];
    ArrSI* pArrSI;
    unsigned int GetFlags();
};

// @fnv 0x00691620
unsigned int FUN_00691620_shell::GetFlags()
{
    return ((ArrSI*)((char*)this + 0xf4))->GetFlags();
}

struct FUN_00691640_shell : NavMesh
{
    NavMeshStaticAvoidNode* FUN_00691640(int index);
};

// @fnv 0x00691640
NavMeshStaticAvoidNode* FUN_00691640_shell::FUN_00691640(int index)
{
    return m_kStaticAvoidNodes.FUN_00691750(index);
}

namespace fnv_00691a90 {
struct GlobalObject_00869f00
{
    void* vtable;
    void Clear(bool);
    void FUN_00691a90();
};

extern "C" void* DAT_010159d4;

// @fnv 0x00691a90
void __thiscall GlobalObject_00869f00::FUN_00691a90()
{
    this->vtable = &DAT_010159d4;
    this->Clear(true);
}
}  // namespace fnv_00691a90

namespace fnv_00691d70 {
extern void* DAT_0106ac54;

struct GlobalObject_00869f00
{
    void* vtable;
    void Clear(bool);
    void FUN_00691d70();
};

// @fnv 0x00691d70
void GlobalObject_00869f00::FUN_00691d70()
{
    vtable = &DAT_0106ac54;
    Clear(true);
}
}  // namespace fnv_00691d70

struct FUN_00691e50_shell
{
    bool IsEqual(unsigned short a, unsigned short b);
};

// @fnv 0x00691e50
bool FUN_00691e50_shell::IsEqual(unsigned short ausLeft, unsigned short ausRight)
{
    return ausLeft == ausRight;
}

struct NiTPointerMap
{
    void RemoveAll();
};
extern "C" void _NiFreeAlias(void*);

struct FUN_00691f00_shell : NiTPointerMap
{
    char _pad8[8];
    void* _member8;
    void FUN_00691f00();
};

// Sets the vtable pointer to "p!i", removes all entries from the map, and frees the member pointer.
// @fnv 0x00691f00
void FUN_00691f00_shell::FUN_00691f00()
{
    *reinterpret_cast<void**>(this) = "p!i";
    this->RemoveAll();
    _NiFreeAlias(_member8);
}

extern void* DAT_0106ac9c;

struct Arr3520
{
    void* vtable;
    void RemoveAll(bool);
    void FUN_00691f90();
};

// @fnv 0x00691f90
void Arr3520::FUN_00691f90()
{
    vtable = (void*)&DAT_0106ac9c;
    RemoveAll(true);
}

namespace fnv_0042fd40 {
struct G00559a40
{
    void FUN_0040f6e0();
};

struct FUN_0042fd40_shell
{
    void* FUN_0042fd40(void* arg);
};

// Copies the value from arg into this and, if non-zero, calls FUN_0040f6e0 on the object at offset 0x1c of that value; returns this.
// @fnv 0x0042fd40
void* FUN_0042fd40_shell::FUN_0042fd40(void* apSource)
{
    *reinterpret_cast<unsigned int*>(this) = *reinterpret_cast<unsigned int*>(apSource);
    if (*reinterpret_cast<unsigned int*>(this) != 0)
    {
        reinterpret_cast<G00559a40*>(*reinterpret_cast<unsigned int*>(this) + 0x1c)->FUN_0040f6e0();
    }
    return this;
}
}  // namespace fnv_0042fd40

namespace fnv_0068f160 {
struct NavMeshTriangle
{
    unsigned short FUN_005582d0(int);
};

struct NavMeshWithGetTriangle
{
    NavMeshTriangle* GetTriangle(unsigned short);
};

class NH : public NavMesh
{
  public:
    NiPoint3 const& FUN_0068f0a0(unsigned short);
    void GetTriangleVertexPositions(unsigned short, unsigned int*, unsigned int*, unsigned int*);
};

// Looks up the triangle for a1 and writes pointers to the positions of its three vertices into a2, a3 and a4.
// @fnv 0x0068f160
void NH::GetTriangleVertexPositions(unsigned short ausTriangleIndex, unsigned int* pVertex0, unsigned int* pVertex1,
                                    unsigned int* pVertex2)
{
    NavMeshTriangle* tri = reinterpret_cast<NavMeshWithGetTriangle*>(this)->GetTriangle(ausTriangleIndex);
    *pVertex0 = reinterpret_cast<unsigned int>(&this->FUN_0068f0a0(tri->FUN_005582d0(0)));
    *pVertex1 = reinterpret_cast<unsigned int>(&this->FUN_0068f0a0(tri->FUN_005582d0(1)));
    *pVertex2 = reinterpret_cast<unsigned int>(&this->FUN_0068f0a0(tri->FUN_005582d0(2)));
}
}  // namespace fnv_0068f160

struct FUN_00690df0_shell
{
    unsigned short pArray[1];
    void SetArrayElement(unsigned int index, unsigned short value);
};

// @fnv 0x00690df0
void FUN_00690df0_shell::SetArrayElement(unsigned int index, unsigned short value)
{
    pArray[index] = value;
}

struct FUN_00691160_shell
{
    unsigned short a[6];
    int b;
    void FUN_00691160();
};

// Sets all six elements of the array a to 0xffff and clears b to 0.
// @fnv 0x00691160
void FUN_00691160_shell::FUN_00691160()
{
    a[0] = 0xffff;
    a[1] = 0xffff;
    a[2] = 0xffff;
    a[3] = 0xffff;
    a[4] = 0xffff;
    a[5] = 0xffff;
    b = 0;
}

namespace fnv_00691b40 {
class GlobalObject_00869f00
{
  public:
    void Clear(bool bClear);
};

extern void* DAT_0106ac2c;

class FUN_00691b40_shell
{
  public:
    void FUN_00691b40();
};

// @fnv 0x00691b40
void FUN_00691b40_shell::FUN_00691b40()
{
    *(void**)((char*)this + 0) = &DAT_0106ac2c;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00691b40

namespace fnv_00691dc0 {
class GlobalObject_00869f00
{
  public:
    void Clear(bool);
    void FUN_00691dc0();
};

void* $SG3320;

// @fnv 0x00691dc0
void GlobalObject_00869f00::FUN_00691dc0()
{
    *reinterpret_cast<void**>(this) = &$SG3320;
    Clear(true);
}
}  // namespace fnv_00691dc0

struct FUN_00691e70_shell
{
    void FUN_00691e70(unsigned char* param1, unsigned short param2, unsigned int param3);
};

// Stores a 16-bit value at offset 4 and a 32-bit value at offset 6 of the given buffer.
// @fnv 0x00691e70
void __thiscall FUN_00691e70_shell::FUN_00691e70(unsigned char* pBuffer, unsigned short usValue, unsigned int uiValue)
{
    *reinterpret_cast<unsigned short*>(pBuffer + 4) = usValue;
    *reinterpret_cast<unsigned int*>(pBuffer + 6) = uiValue;
}

struct Unk42ffa0
{
    int dummy;
    void FUN_0042ffa0(int);
};
struct Unk42fb20
{
    void FUN_0042fb20(Unk42ffa0*, unsigned int);
};
// Calls FUN_0042ffa0(0) on each of the count elements of arr.
// @fnv 0x0042fb20
void Unk42fb20::FUN_0042fb20(Unk42ffa0* apItems, unsigned int count)
{
    for (int i = 0; i < count; ++i)
        apItems[i].FUN_0042ffa0(0);
}

struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
};
struct FUN_0042fc00_shell
{
    void** vtable;
    void* m_pCurrent;
    unsigned int m_iKey;
    void FUN_0042fb60(void*, void*, unsigned int);
    void FUN_0042fc00(void* p, unsigned int key);
};
// @fnv 0x0042fc00
void FUN_0042fc00_shell::FUN_0042fc00(void* p, unsigned int key)
{
    if (m_pCurrent)
    {
        if (key == *(unsigned int*)((char*)this + 0xc))
        {
            m_pCurrent = ((void*(__thiscall*)(void*, void*, void*))vtable[3])(this, m_pCurrent, p);
        }
        else
        {
            void* result = ((void*(__thiscall*)(void*, void*))vtable[1])(this, p);
            FUN_0042fb60(result, m_pCurrent, key);
            ((NavMeshSearchLOSArray*)this)->FUN_006a8500();
            m_pCurrent = result;
        }
    }
    else
    {
        m_pCurrent = ((void*(__thiscall*)(void*, void*))vtable[1])(this, p);
        *(unsigned int*)((char*)this + 0xc) = (unsigned int)p;
    }
}

struct S2f850
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    virtual void v0();
    virtual unsigned int v1(unsigned int);
    void FUN_0042fa60(unsigned int, unsigned int);
    void FUN_0042fcb0(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x0042fcb0
void S2f850::FUN_0042fcb0(unsigned int requested, unsigned int savedSize)
{
    a = 0;
    b = 0;
    c = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        a = v1(requested);
        c = requested;
    }
    if (savedSize > 0)
    {
        FUN_0042fa60(a, savedSize);
        b = savedSize;
    }
}

class EdgeExtraInfo;
struct FUN_0068f2c0_shell
{
    unsigned short FUN_0068f2c0(int index);
};
// @fnv 0x0068f2c0
unsigned short FUN_0068f2c0_shell::FUN_0068f2c0(int index)
{
    return ((unsigned short*)((char*)this + 6))[index];
}

struct NavMesh_MatchHelper
{
    bool FindAdjacentTriangle(unsigned short, int, NavMesh*&, unsigned short&, int&);
};
struct In670
{
    int _f0;
    unsigned short _f4;
    short _pad6;
    int _f8;
};
struct Out670
{
    NavMesh* _f0;
    unsigned short _f4;
    short _pad6;
    int _f8;
};
struct Holder670
{
    bool MatchNavMesh(In670*, Out670*);
};
// Calls the match helper with the input's _f4 and _f8, writing the resulting NavMesh pointer, _f4 and _f8 into the output.
// @fnv 0x0068f670
bool Holder670::MatchNavMesh(In670* pIn, Out670* pOut)
{
    return ((NavMesh_MatchHelper*)this)->FindAdjacentTriangle(pIn->_f4, pIn->_f8, pOut->_f0, pOut->_f4, pOut->_f8);
}

void __cdecl AddPoint(unsigned int);
struct FUN_00690fe0_shell
{
    void __thiscall FUN_00690fe0(unsigned int state);
};
// @fnv 0x00690fe0
void __thiscall FUN_00690fe0_shell::FUN_00690fe0(unsigned int state)
{
    ((void(__thiscall*)(void*, unsigned int))AddPoint)(this + 0x28, state);
}

struct FUN_00691040_shell
{
    void GetPackedFlags(unsigned short, unsigned short*, bool*, bool*);
};
// Extracts a 4-bit value and two flag bits from the 32-bit field at offset 0xc, shifted by a1*6+16, writing them to a2, a3 and a4.
// @fnv 0x00691040
void FUN_00691040_shell::GetPackedFlags(unsigned short ausIndex, unsigned short* a2, bool* pbFlag16, bool* pbFlag32)
{
    unsigned int shift = ausIndex * 6 + 16;
    unsigned int uiBits = *(unsigned int*)((char*)this + 0xc) >> shift;
    *a2 = uiBits & 15;
    *pbFlag16 = 0 < (uiBits & 16);
    *pbFlag32 = 0 < (uiBits & 32);
}

struct Flt
{
    operator unsigned int();
};
struct S006911c0
{
    char _pad[0xA8];
    Flt _f;
    unsigned int FUN_006911c0();
};
// Returns the product of the float member converted to unsigned int with itself.
// @fnv 0x006911c0
unsigned int S006911c0::FUN_006911c0()
{
    return (unsigned int)_f * (unsigned int)_f;
}

struct FUN_006911f0_shell
{
    void FUN_00691210(int);
    void FUN_006911f0(int a);
};
// @fnv 0x006911f0
void FUN_006911f0_shell::FUN_006911f0(int a)
{
    ((FUN_006911f0_shell*)((char*)this + 0xa8))->FUN_00691210(a);
}

struct NavMeshGrid
{
    int gridWidth;
    void GetCellCoords(NiPoint3 const&, unsigned int&, unsigned int&);
    int GetCellIndex(NiPoint3 const&);
};
// Converts a point to grid coordinates via GetCellCoords and returns the linear cell index x * gridWidth + y.
// @fnv 0x00691260
int NavMeshGrid::GetCellIndex(NiPoint3 const& aPoint)
{
    unsigned int x = 0;
    {
        unsigned int y = 0;
        GetCellCoords(aPoint, x, y);
        return x * gridWidth + y;
    }
}

struct Dummy914e0
{
    int fld0;
    void FUN_0069da10(unsigned short, int);
    void FUN_006914e0(unsigned short, int, int);
};
// Calls FUN_0069da10 with a and b plus c multiplied by fld0.
// @fnv 0x006914e0
void Dummy914e0::FUN_006914e0(unsigned short a, int b, int c)
{
    FUN_0069da10(a, c * fld0 + b);
}

struct EH;
struct S5460
{
    unsigned int FUN_00978bc0();
};
struct FUN_0069b310_S
{
    int _pad0;
    NiPoint3* pElementBuffer;
    void ConstructBounds(EH*, int);
    unsigned int AddPoint(const NiPoint3&);
};
// @fnv 0x00691ab0
unsigned int FUN_0069b310_S::AddPoint(const NiPoint3& aPoint)
{
    unsigned int index = ((S5460*)this)->FUN_00978bc0();
    ConstructBounds((EH*)&pElementBuffer[index], 1);
    pElementBuffer[index] = aPoint;
    return index;
}

struct Elem16
{
    int a0;
    int a1;
    int a2;
    int a3;
};
struct Arr16
{
    int _pad0;
    Elem16* buffer;
    unsigned int FUN_006f31f0();
    void FUN_00644490(void*, int);
    unsigned int FUN_00691b60(Elem16*);
};
// @fnv 0x00691b60
unsigned int Arr16::FUN_00691b60(Elem16* apElement)
{
    unsigned int idx = FUN_006f31f0();
    FUN_00644490(&buffer[idx], 1);
    buffer[idx] = *apElement;
    return idx;
}

extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern const char $SG3635[];

struct FUN_00691de0_shell
{
    void** vtable;
    unsigned int count;
    void* buffer;
    unsigned int reserved;
    FUN_00691de0_shell* FUN_00691de0(unsigned int count);
};

// @fnv 0x00691de0
FUN_00691de0_shell* FUN_00691de0_shell::FUN_00691de0(unsigned int count)
{
    vtable = (void**)$SG3635;
    this->count = count;
    reserved = 0;
    unsigned int byteCount = this->count * 4;
    buffer = _NiMalloc(byteCount);
    memset(buffer, 0, this->count * 4);
    return this;
}

struct Unk65
{
    void FUN_0065de30(int);
};
struct Unk6b
{
    void FreeMemory(void*);
};
struct UnkParam
{
    char _pad[6];
    Unk65 f;
};
struct UnkHost
{
    char _pad[12];
    Unk6b f2;
    void FUN_00691f30(UnkParam*);
};
// Calls FUN_0065de30(0) on a1->f, then passes a1 to f2.FreeMemory.
// @fnv 0x00691f30
void UnkHost::FUN_00691f30(UnkParam* pParam)
{
    pParam->f.FUN_0065de30(0);
    f2.FreeMemory(pParam);
}

namespace fnv_006dc990 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Node680
{
    float EvaluateFalloff(int);
};
struct S3e60
{
    Node680* FUN_006a1400(unsigned int);
};
struct Sdc990
{
    float SumNodeValues(int);
};
// Sums the values returned by EvaluateFalloff(a1) over all nodes obtained from FUN_006a1400 up to GetFlags() count.
// @fnv 0x006dc990
float Sdc990::SumNodeValues(int a1)
{
    float fSum = 0.0f;
    unsigned int cnt = ((ArrSI*)this)->GetFlags();
    unsigned int idx = 0;
    Node680* pNode;
    for (; idx < cnt; idx++)
    {
        pNode = ((S3e60*)this)->FUN_006a1400(idx);
        fSum += pNode->EvaluateFalloff(a1);
    }
    return fSum;
}
}  // namespace fnv_006dc990

struct DoorH
{
    TESForm* GetParentWorldSpace();
};
struct NavMeshProxy
{
    char _pad[0x24];
    DoorH* m_pOwningCell;
    TESForm* GetDoorForm();
};
// @fnv 0x0068ef70
TESForm* NavMeshProxy::GetDoorForm()
{
    if (m_pOwningCell)
    {
        if (m_pOwningCell->GetParentWorldSpace())
            return m_pOwningCell->GetParentWorldSpace();
        else
            return (TESForm*)m_pOwningCell;
    }
    else
    {
        return 0;
    }
}

struct NavMeshInfoProxy
{
    char _pad[0x54];
    void* field54;
    bool FUN_0068f320() const;
    bool FUN_0068f2e0(void**);
};
// If FUN_0068f320() is true, sets *p to null and returns false; otherwise stores field54 in *p and returns whether field54 is non-null.
// @fnv 0x0068f2e0
bool NavMeshInfoProxy::FUN_0068f2e0(void** apOut)
{
    if (FUN_0068f320())
    {
        *apOut = 0;
        return false;
    }
    *apOut = field54;
    return field54 != 0;
}

struct FUN_00844160_shell
{
    FUN_00844160_shell* FUN_00844160(int);
};

FUN_00844160_shell* FUN_00844160_shell::FUN_00844160(int index)
{
    return this;
}

struct FUN_0068f6b0_shell
{
    char _pad58[0x58];
    FUN_00844160_shell* FUN_0068f6b0(unsigned short index);
};

// @fnv 0x0068f6b0
FUN_00844160_shell* FUN_0068f6b0_shell::FUN_0068f6b0(unsigned short index)
{
    return ((FUN_00844160_shell*)((char*)this + 0x58))->FUN_00844160(index);
}

struct TriHack
{
    char _pad0[6];
    unsigned short field6[3];
    int fieldC;
    void ClearFlag(int);
};
// Clears bit idx in fieldC and sets the corresponding entry of field6 to 0xffff.
// @fnv 0x00690790
void TriHack::ClearFlag(int aiIndex)
{
    fieldC &= ~(1 << aiIndex);
    field6[aiIndex] = 0xffff;
}

struct S6907D0
{
    char _pad[6];
    unsigned short arr[64];
    void ClearFlag(int);
    void SetArrayValue(int, unsigned short);
};
// Calls ClearFlag with a, then stores b into arr at index a.
// @fnv 0x006907d0
void S6907D0::SetArrayValue(int aiIndex, unsigned short ausValue)
{
    ClearFlag(aiIndex);
    arr[aiIndex] = ausValue;
}

struct Unk00690e30
{
    char _pad[6];
    unsigned short arr[3];
    unsigned int flags;
    void SetSlotValue(int, unsigned short);
};
// Sets bit a in flags and stores b into arr[a].
// @fnv 0x00690e30
void Unk00690e30::SetSlotValue(int aiIndex, unsigned short ausValue)
{
    flags |= (1 << aiIndex);
    arr[aiIndex] = ausValue;
}

struct FUN_00690e70_shell
{
    char _pad0c[0x0c];
    unsigned int field_c;
    bool IsFlag400Set();
};

// @fnv 0x00690e70
bool FUN_00690e70_shell::IsFlag400Set()
{
    return 0 < (field_c & 0x400);
}

struct S691210
{
    unsigned int m0;
    char _pad[32];
    int mBase;
    int FUN_00691210(unsigned int);
};
// Returns 0 if idx is outside m0*m0, otherwise returns idx*16 plus mBase.
// @fnv 0x00691210
int S691210::FUN_00691210(unsigned int uiIndex)
{
    if (uiIndex >= m0 * m0)
    {
        return 0;
        goto done;
    }
    return uiIndex * 16 + mBase;
done:;
}

struct FUN_00691240_shell
{
    char _pad_a8[0xa8];
    struct Inner
    {
        void GetCellIndex(int);
    };
    Inner inner;
    void ForwardToInner(int arg);
};

// @fnv 0x00691240
void __thiscall FUN_00691240_shell::ForwardToInner(int arg)
{
    inner.GetCellIndex(arg);
}

namespace fnv_00691590 {
class PathingAvoidanceNode;
struct FUN_006915d0_helper
{
    char _pad[36];
    unsigned short field24;
    PathingAvoidanceNode* FUN_006915d0(NiPoint3 const&, float, float);
    FUN_006915d0_helper* FUN_00691590(NiPoint3 const&, unsigned short, float, float);
};
// Calls FUN_006915d0 with the position and two floats, stores the unsigned short in field24, and returns this.
// @fnv 0x00691590
FUN_006915d0_helper* FUN_006915d0_helper::FUN_00691590(NiPoint3 const& akPosition, unsigned short ausValue, float c,
                                                       float d)
{
    FUN_006915d0(akPosition, c, d);
    field24 = ausValue;
    return this;
}
}  // namespace fnv_00691590

namespace fnv_0068ed70 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct TESRecipe
{
    void SetCategory(unsigned int);
};
struct Base5a
{
    virtual ~Base5a();
    char pad04[0x14];
};
struct FUN_0068ed70_ChildCell
{
    virtual void vf00();
};
struct EBase
{
    virtual ~EBase();
    char pad04[0x8];
};
template <> class BSSimpleArray<unsigned short, 1024>
{
  public:
    virtual ~BSSimpleArray();
    unsigned short* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct FUN_00691a90
{
    char pad[0x10];
    ~FUN_00691a90();
};
struct FUN_00691b40
{
    char pad[0x10];
    ~FUN_00691b40();
};
struct FUN_00691bf0
{
    char pad[0x10];
    ~FUN_00691bf0();
};
struct FUN_00691d70
{
    char pad[0x10];
    ~FUN_00691d70();
};
struct FUN_00691dc0
{
    char pad[0x10];
    ~FUN_00691dc0();
};
struct FUN_00691ea0
{
    char pad[0x10];
    ~FUN_00691ea0();
};
struct FUN_00691f90
{
    char pad[0x10];
    ~FUN_00691f90();
};
struct FUN_00691fe0
{
    char pad[0x10];
    ~FUN_00691fe0();
};
struct FUN_0069d2d0_shell
{
    char pad[0x28];
    void FUN_0069d2d0();
};
struct FUN_0068ed70_Owned
{
    virtual ~FUN_0068ed70_Owned();
};

struct FUN_0068ed70 : public Base5a, public FUN_0068ed70_ChildCell, public EBase
{
    FUN_00691a90 m28;
    FUN_00691b40 m38;
    FUN_00691bf0 m48;
    FUN_00691d70 m58;
    FUN_00691dc0 m68;
    BSSimpleArray<unsigned short, 1024> m78;
    FUN_00691ea0 m88;
    BSSimpleArray<unsigned short, 1024> m98;
    FUN_0069d2d0_shell ma8;
    FUN_00691f90 md0;
    FUN_0068ed70_Owned* pe0;
    BSSimpleArray<unsigned short, 1024> me4;
    FUN_00691fe0 mf4;
    TESRecipe* p104;
    virtual ~FUN_0068ed70();
};

// @fnv 0x0068ed70
FUN_0068ed70::~FUN_0068ed70()
{
    ((GlobalObject_00869f00*)&m28)->Clear(true);
    ((GlobalObject_00869f00*)&m38)->Clear(true);
    ((GlobalObject_00869f00*)&m48)->Clear(true);
    ((GlobalObject_00869f00*)&m58)->Clear(true);
    ((GlobalObject_00869f00*)&m78)->Clear(true);
    ma8.FUN_0069d2d0();
    if (p104)
        p104->SetCategory(0);
    if (pe0)
        delete pe0;
}
}  // namespace fnv_0068ed70

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

struct FUN_0042fb60_shell
{
    void FUN_0042fb60(char* a, char* b, unsigned int n);
};

// Copies n 4-byte elements from b to a, choosing forward or backward iteration based on the relative addresses of a and b.
// @fnv 0x0042fb60
void FUN_0042fb60_shell::FUN_0042fb60(char* pDst, char* pSrc, unsigned int n)
{
    if (n <= 0)
        return;
    if ((unsigned int)pDst < (unsigned int)pSrc)
    {
        for (unsigned int i = 0; i < n; ++i)
            FUN_00ec7230(pDst + i * 4, pSrc + i * 4, 4);
    }
    else if ((unsigned int)pDst > (unsigned int)pSrc)
    {
        for (int i = (int)n - 1; i >= 0; --i)
            FUN_00ec7230(pDst + i * 4, pSrc + i * 4, 4);
    }
}

namespace fnv_00690d50 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct Arr3520
{
    void RemoveAll(bool);
};
struct FUN_0069d2d0_s
{
    void FUN_0069d2d0();
};
struct FUN_006b6a00_s
{
    void ActivateNavigationEntry();
};
struct FUN_0084e3a0_s
{
    void* FUN_0084e3a0();
};
struct TES
{
    void* GetActiveCell(void*);
};
extern TES g_TES;
struct FUN_00690d50_shell
{
    void ClearNavMesh(bool abCheckout);
};
// @fnv 0x00690d50
void FUN_00690d50_shell::ClearNavMesh(bool abCheckout)
{
    ((GlobalObject_00869f00*)((char*)this + 0x28))->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0x38))->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0x48))->Clear(true);
    ((FUN_0069d2d0_s*)((char*)this + 0xa8))->FUN_0069d2d0();
    ((GlobalObject_00869f00*)((char*)this + 0x78))->Clear(true);
    ((Arr3520*)((char*)this + 0xd0))->RemoveAll(true);
    ((GlobalObject_00869f00*)((char*)this + 0x58))->Clear(true);
    if (*(void**)((char*)this + 0x104))
    {
        ((FUN_006b6a00_s*)((TES*)*(int*)&g_TES)->GetActiveCell(((FUN_0084e3a0_s*)this)->FUN_0084e3a0()))
            ->ActivateNavigationEntry();
    }
}
}  // namespace fnv_00690d50

namespace fnv_006910a0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct NavMeshTriangle
{
    bool GetFlag(int);
    bool HasFlags();
};
struct NavMeshTriangleArr
{
    NavMeshTriangle* GetTriangle(unsigned short);
};
struct BSSimpleArrayUS
{
    unsigned int ReserveIndex(const unsigned short&);
};
struct FUN_006910a0_shell : NavMesh
{
    void RebuildTriangleList();
};

// Clears the array at offset 0x78, then appends each triangle index whose flag 0x20 is unset and whose HasFlags check passes.
// @fnv 0x006910a0
void FUN_006910a0_shell::RebuildTriangleList()
{
    unsigned int i;
    unsigned int isize2;
    ((GlobalObject_00869f00*)((char*)this + 0x78))->Clear(false);
    isize2 = ((ArrSI*)((char*)this + 0x38))->GetFlags();
    for (i = 0; i < isize2; i++)
    {
        if (!((NavMeshTriangleArr*)this)->GetTriangle(i)->GetFlag(0x20) &&
            ((NavMeshTriangleArr*)this)->GetTriangle(i)->HasFlags())
        {
            ((BSSimpleArrayUS*)((char*)this + 0x78))->ReserveIndex(i);
        }
    }
}
}  // namespace fnv_006910a0

struct FUN_0069b030_S
{
    virtual ~FUN_0069b030_S();
    virtual int Write(unsigned int);
    void ConstructPairCells(int, unsigned int);
    void FUN_00692520(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x00692520
void FUN_0069b030_S::FUN_00692520(unsigned int requested, unsigned int savedSize)
{
    ((int*)this)[1] = 0;
    ((int*)this)[2] = 0;
    ((int*)this)[3] = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        ((int*)this)[1] = Write(requested);
        ((int*)this)[3] = requested;
    }
    if (savedSize > 0)
    {
        ConstructPairCells(((int*)this)[1], savedSize);
        ((int*)this)[2] = savedSize;
    }
}

namespace fnv_00690e90 {
struct ArrSI
{
    unsigned int GetFlags();
};

struct S006949d0
{
    void* GetAt(int);
};

struct FUN_00691c90_shell
{
    void FUN_00691c90(unsigned int, unsigned int);
};

struct FUN_00690e10_shell
{
    bool HasEdgeExtraInfo();
};

struct S6907D0
{
    void ClearFlag(int);
};

struct Unk00690e30
{
    void SetSlotValue(int, unsigned short);
};

class NavMeshTriangle
{
  public:
    bool IsEdgeFlagSet(int);
    unsigned short FUN_0068f2c0(int);
};

class FUN_00690e90_shell
{
  public:
    void UpdateTriangleExtraInfo(unsigned short aiExtraInfo);
};

// @fnv 0x00690e90
void FUN_00690e90_shell::UpdateTriangleExtraInfo(unsigned short aiExtraInfo)
{
    unsigned int i;
    unsigned int itriSize4;
    unsigned int t;

    reinterpret_cast<FUN_00691c90_shell*>(reinterpret_cast<unsigned char*>(this) + 0x48)->FUN_00691c90(aiExtraInfo, 1);

    itriSize4 = reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetFlags();

    for (i = 0; i < itriSize4; ++i)
    {
        if (reinterpret_cast<FUN_00690e10_shell*>(
                reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                ->HasEdgeExtraInfo())
        {
            for (t = 0; t < 3; ++t)
            {
                if (reinterpret_cast<NavMeshTriangle*>(
                        reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                        ->IsEdgeFlagSet(t))
                {
                    if (reinterpret_cast<NavMeshTriangle*>(
                            reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                            ->FUN_0068f2c0(t) == aiExtraInfo)
                    {
                        reinterpret_cast<S6907D0*>(
                            reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                            ->ClearFlag(t);
                    }
                    else if (reinterpret_cast<NavMeshTriangle*>(
                                 reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                                 ->FUN_0068f2c0(t) ==
                             reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x48)->GetFlags())
                    {
                        reinterpret_cast<Unk00690e30*>(
                            reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)->GetAt(i))
                            ->SetSlotValue(t, aiExtraInfo);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00690e90

class StrMem
{
  public:
    StrMem();
    ~StrMem();
    char* FUN_00559450();
    char* m_str;
    unsigned short m_len;
    unsigned short m_cap;
};

struct InfoView
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void FillCellName(StrMem*);
    unsigned int FUN_0054ddd0();
};

class NavMeshTriangle
{
  public:
    bool IsEdgeFlagSet(int);
    unsigned char IsEdgeConnected(int);
    unsigned short FUN_0068f2c0(int);
    unsigned short FUN_005582d0(int);
    void ClearFlag(int);
    void SetArrayValue(int, unsigned short);
    bool HasFlags();
};

class NavMeshPtr
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
    char* FUN_00559450();
    void* m_ptr;
};

struct MeshView
{
    char* FUN_00559450();
    unsigned int FUN_0084e3a0();
    unsigned int FUN_00558200();
    unsigned int GetWorldSpace();
    bool FUN_00690860(NavMeshPtr*);
};

struct VertArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int FUN_0044ddc0();
    NiPoint3* FUN_006a1440(unsigned int);
};
struct TriArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int FUN_0044ddc0();
    NavMeshTriangle* FUN_00558dd0(int);
};
struct ArrView
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int FUN_0044ddc0();
};
struct CoverArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int FUN_0044ddc0();
    unsigned short& GetBufferEntry(int);
};
struct EdgeInfoView
{
    int m_00;
    MeshView* m_04;
    unsigned short m_08;
    unsigned short m_0a;
};

extern double DAT_0106ab98;
extern const char DAT_0106ab40[];
extern const char DAT_0106aae8[];
extern const char DAT_0106aa90[];
extern const char DAT_0106aa28[];
extern const char DAT_0106a9c0[];
extern const char DAT_0106a960[];
extern const char DAT_0106a8f0[];
extern const char DAT_0106a860[];
extern const char DAT_0106a7d8[];
extern const char DAT_0106a770[];
extern const char DAT_0106a708[];
extern const char DAT_0106a6a0[];
extern const char DAT_0106a640[];
extern const char DAT_0106a5e0[];
extern const char DAT_0106a580[];
extern const char DAT_0106a520[];
extern const char DAT_0106a480[];
extern const char DAT_0106a418[];
extern const char DAT_0106a3b0[];
extern const char DAT_0106a330[];
extern const char DAT_0106a2c8[];
extern const char DAT_0106a260[];
extern const char DAT_0106a1f0[];

void __cdecl FUN_005b5e40(const char* fmt, ...);
int __cdecl FUN_00ec7595(double);
double __cdecl FUN_00408840(float);

struct NavMeshView
{
    char _pad24[0x24];
    int m_24;
    VertArr verts;
    TriArr tris;
    ArrView arr48;
    char _pad58[0x20];
    CoverArr cover;
    InfoView* FUN_0059bb30();
    unsigned int FUN_0084e3a0();
    NavMeshTriangle* FUN_005582f0(unsigned short);
    EdgeInfoView* FUN_0068f230(unsigned short, int);
    NiPoint3 FUN_006971e0(unsigned short);
    void SwapTriangleEdges(unsigned short);
    void UpdateTriangleExtraInfo(unsigned short);
    void CheckNeighborCells();
    bool Validate(int);
};

// @fnv 0x0068f6d0
bool NavMeshView::Validate(int a0)
{
    bool hadError = false;
    StrMem p;
    FUN_0059bb30()->FillCellName(&p);

    for (unsigned int i = 0; i < verts.FUN_0044ddc0(); i++)
    {
        if (FUN_00ec7595(verts.FUN_006a1440(i)->x) == 0 || FUN_00408840(verts.FUN_006a1440(i)->x) > DAT_0106ab98)
        {
            FUN_005b5e40(DAT_0106ab40, FUN_0084e3a0(), p.FUN_00559450());
            hadError = true;
            break;
        }
        if (FUN_00ec7595(verts.FUN_006a1440(i)->y) == 0 || FUN_00408840(verts.FUN_006a1440(i)->y) > DAT_0106ab98)
        {
            FUN_005b5e40(DAT_0106aae8, FUN_0084e3a0(), p.FUN_00559450());
            hadError = true;
            break;
        }
        if (FUN_00ec7595(verts.FUN_006a1440(i)->z) == 0 || FUN_00408840(verts.FUN_006a1440(i)->z) > DAT_0106ab98)
        {
            FUN_005b5e40(DAT_0106aa90, FUN_0084e3a0(), p.FUN_00559450());
            hadError = true;
            break;
        }
    }

    if (tris.FUN_0044ddc0() >= 0x7d0)
    {
        FUN_005b5e40(DAT_0106aa28, FUN_0084e3a0(), p.FUN_00559450(), tris.FUN_0044ddc0());
    }

    for (unsigned int j = 0; j < tris.FUN_0044ddc0(); j++)
    {
        NavMeshTriangle* triA = tris.FUN_00558dd0(j);
        for (long k = 0; k < 3; k++)
        {
            if (!triA->IsEdgeFlagSet(k) && triA->IsEdgeConnected(k) != 0 && triA->FUN_0068f2c0(k) >= tris.FUN_0044ddc0())
            {
                FUN_005b5e40(DAT_0106a9c0, FUN_0084e3a0(), p.FUN_00559450(), j, k);
                triA->SetArrayValue(k, 0xffff);
                hadError = true;
            }
        }
        NiPoint3 normal = FUN_006971e0((unsigned short)j);
        if (normal.z < 0.0f)
        {
            FUN_005b5e40(DAT_0106a960, FUN_0084e3a0(), p.FUN_00559450(), j);
            SwapTriangleEdges((unsigned short)j);
            hadError = true;
        }
    }

    for (unsigned int b = 0; b < tris.FUN_0044ddc0(); b++)
    {
        NavMeshTriangle* sh = FUN_005582f0((unsigned short)b);
        for (long tri7 = 0; tri7 < 3; tri7++)
        {
            if (sh->IsEdgeFlagSet(tri7))
            {
                if (sh->FUN_0068f2c0(tri7) >= arr48.FUN_0044ddc0())
                {
                    FUN_005b5e40(DAT_0106a8f0, FUN_0084e3a0(), p.FUN_00559450(), b, tri7);
                    sh->ClearFlag(tri7);
                    hadError = true;
                    continue;
                }
                EdgeInfoView* pRetrievedObject = FUN_0068f230((unsigned short)b, tri7);
                if (pRetrievedObject->m_04 == 0)
                {
                    UpdateTriangleExtraInfo(sh->FUN_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else if (pRetrievedObject->m_08 == 0xffff)
                {
                    UpdateTriangleExtraInfo(sh->FUN_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else
                {
                    NavMeshPtr pTri;
                    if (pRetrievedObject->m_04->FUN_00690860(&pTri))
                    {
                        if (pRetrievedObject->m_08 >= ((MeshView*)pTri.FUN_00559450())->FUN_00558200())
                        {
                            FUN_005b5e40(DAT_0106a860, FUN_0084e3a0(), p.FUN_00559450(), b, tri7,
                                         ((MeshView*)pTri.FUN_00559450())->FUN_0084e3a0(), pRetrievedObject->m_08);
                            UpdateTriangleExtraInfo(sh->FUN_0068f2c0(tri7));
                            hadError = true;
                            continue;
                        }
                    }
                    if (FUN_0059bb30()->FUN_0054ddd0() != pRetrievedObject->m_04->GetWorldSpace())
                    {
                        FUN_005b5e40(DAT_0106a7d8, FUN_0084e3a0(), p.FUN_00559450(), b, tri7,
                                     pRetrievedObject->m_04->FUN_00559450());
                        UpdateTriangleExtraInfo(sh->FUN_0068f2c0(tri7));
                        hadError = true;
                        continue;
                    }
                }
            }
        }
    }

    for (unsigned int t4 = 0; t4 < tris.FUN_0044ddc0(); t4++)
    {
        NavMeshTriangle* tri4 = FUN_005582f0((unsigned short)t4);
        if (tri4->FUN_005582d0(0) == tri4->FUN_005582d0(1))
        {
            FUN_005b5e40(DAT_0106a770, FUN_0084e3a0(), p.FUN_00559450(), t4, tri4->FUN_005582d0(0));
            hadError = true;
        }
        if (tri4->FUN_005582d0(0) == tri4->FUN_005582d0(2))
        {
            FUN_005b5e40(DAT_0106a708, FUN_0084e3a0(), p.FUN_00559450(), t4, tri4->FUN_005582d0(0));
            hadError = true;
        }
        if (tri4->FUN_005582d0(1) == tri4->FUN_005582d0(2))
        {
            FUN_005b5e40(DAT_0106a6a0, FUN_0084e3a0(), p.FUN_00559450(), t4, tri4->FUN_005582d0(1));
            hadError = true;
        }
    }

    for (unsigned int e7 = 0; e7 < tris.FUN_0044ddc0(); e7++)
    {
        NavMeshTriangle* tri5 = FUN_005582f0((unsigned short)e7);
        if (tri5->FUN_0068f2c0(0) == tri5->FUN_0068f2c0(1) && tri5->FUN_0068f2c0(0) != 0xffff &&
            tri5->IsEdgeFlagSet(0) == tri5->IsEdgeFlagSet(1))
        {
            FUN_005b5e40(DAT_0106a640, FUN_0084e3a0(), p.FUN_00559450(), e7, tri5->FUN_0068f2c0(0));
            hadError = true;
        }
        if (tri5->FUN_0068f2c0(0) == tri5->FUN_0068f2c0(2) && tri5->FUN_0068f2c0(0) != 0xffff &&
            tri5->IsEdgeFlagSet(0) == tri5->IsEdgeFlagSet(2))
        {
            FUN_005b5e40(DAT_0106a5e0, FUN_0084e3a0(), p.FUN_00559450(), e7, tri5->FUN_0068f2c0(0));
            hadError = true;
        }
        if (tri5->FUN_0068f2c0(1) == tri5->FUN_0068f2c0(2) && tri5->FUN_0068f2c0(1) != 0xffff &&
            tri5->IsEdgeFlagSet(1) == tri5->IsEdgeFlagSet(2))
        {
            FUN_005b5e40(DAT_0106a580, FUN_0084e3a0(), p.FUN_00559450(), e7, tri5->FUN_0068f2c0(1));
            hadError = true;
        }
    }

    for (unsigned int t6 = 0; t6 < tris.FUN_0044ddc0(); t6++)
    {
        NavMeshTriangle* tri6 = FUN_005582f0((unsigned short)t6);
        for (long e6 = 0; 3 > e6; e6++)
        {
            int edge = e6;
            unsigned int e = edge + 1;
            if (e == 3)
                e = 0;
            unsigned short vA = tri6->FUN_005582d0(edge);
            unsigned short pForm = tri6->FUN_005582d0(e);
            for (int tri3 = 0; tri3 < tris.FUN_0044ddc0(); tri3++)
            {
                if (tri3 == t6)
                    continue;
                NavMeshTriangle* tri = FUN_005582f0((unsigned short)tri3);
                for (int t5 = 0; t5 < 3; t5++)
                {
                    if (tri->FUN_005582d0(t5) != pForm)
                        continue;
                    unsigned short tIn = (unsigned short)(t5 + 1);
                    if (tIn == 3)
                        tIn = 0;
                    for (int e8 = 0; 3 > e8; e8++)
                    {
                        if (e8 == t5)
                            continue;
                        if (tri->FUN_005582d0(e8) != vA)
                            continue;
                        if (e8 != tIn)
                        {
                            FUN_005b5e40(DAT_0106a520, FUN_0084e3a0(), p.FUN_00559450(), t6, tri3);
                            hadError = true;
                        }
                        if (!tri6->IsEdgeFlagSet(e6))
                        {
                            if (tri6->FUN_0068f2c0(e6) != 0xffff)
                            {
                                if (tri->IsEdgeFlagSet(t5))
                                {
                                    FUN_005b5e40(DAT_0106a480, FUN_0084e3a0(), p.FUN_00559450(), t6, e6, tri3, tri3,
                                                 t5);
                                    hadError = true;
                                }
                                if (tri6->FUN_0068f2c0(e6) != tri3)
                                {
                                    FUN_005b5e40(DAT_0106a418, FUN_0084e3a0(), p.FUN_00559450(), t6, e6, tri3);
                                    hadError = true;
                                }
                                if (tri->FUN_0068f2c0(t5) != t6)
                                {
                                    FUN_005b5e40(DAT_0106a418, FUN_0084e3a0(), p.FUN_00559450(), tri3, t5, t6);
                                    hadError = true;
                                }
                            }
                        }
                        else
                        {
                            if (!tri->IsEdgeFlagSet(t5))
                            {
                                FUN_005b5e40(DAT_0106a3b0, FUN_0084e3a0(), p.FUN_00559450(), tri3, t5);
                                hadError = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (unsigned int e10 = 0; e10 < tris.FUN_0044ddc0(); e10++)
    {
        NavMeshTriangle* tri8 = FUN_005582f0((unsigned short)e10);
        for (int e9 = 0; 3 > e9; e9++)
        {
            if (!tri8->IsEdgeFlagSet(e9) && tri8->FUN_0068f2c0(e9) != 0xffff)
            {
                NavMeshTriangle* h = FUN_005582f0(tri8->FUN_0068f2c0(e9));
                bool s = false;
                int a;
                for (a = 0; 3 > a; a++)
                {
                    if (!h->IsEdgeFlagSet(a) && h->FUN_0068f2c0(a) != 0xffff && h->FUN_0068f2c0(a) == e10)
                    {
                        s = true;
                        break;
                    }
                }
                if (!s)
                {
                    FUN_005b5e40(DAT_0106a330, FUN_0084e3a0(), p.FUN_00559450(), e10, tri8->FUN_0068f2c0(e9),
                                 tri8->FUN_0068f2c0(e9));
                    hadError = true;
                }
                if (a < 3)
                {
                    int bIdx = e9;
                    long c = e9 + 1;
                    if (c == 3)
                        c = 0;
                    int c2 = a;
                    int q = a + 1;
                    if (q == 3)
                        q = 0;
                    if (tri8->FUN_005582d0(bIdx) != h->FUN_005582d0(q) || tri8->FUN_005582d0(c) != h->FUN_005582d0(c2))
                    {
                        FUN_005b5e40(DAT_0106a2c8, FUN_0084e3a0(), p.FUN_00559450(), e10, tri8->FUN_0068f2c0(e9));
                        hadError = true;
                    }
                }
            }
        }
    }

    for (unsigned int ci = 0; ci < cover.FUN_0044ddc0(); ci++)
    {
        unsigned short triC = cover.GetBufferEntry(ci);
        NavMeshTriangle* coverTri = FUN_005582f0(triC);
        if (coverTri == 0)
        {
            FUN_005b5e40(DAT_0106a260, FUN_0084e3a0(), p.FUN_00559450(), ci, triC);
            hadError = true;
        }
        else if (!coverTri->HasFlags())
        {
            FUN_005b5e40(DAT_0106a1f0, FUN_0084e3a0(), p.FUN_00559450(), ci, triC);
            hadError = true;
        }
    }

    CheckNeighborCells();
    return !hadError;
}

class B690770Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;

    bool HasFlags();
};

// @fnv 0x00690770
bool B690770Object::HasFlags()
{
    return (m_uiValue1 & 0xfbe0000) > 0;
}

struct ProbeResult
{
    void* value;
    ~ProbeResult();
    void* FUN_00458b50();
};

struct ProbeArray
{
    unsigned int GetReferenceFlags();
    ProbeResult FUN_00464f60(unsigned int index);
};

struct ProbeHolder
{
    ProbeArray* FUN_0070ec90();
};

struct ProbeCell
{
    ProbeHolder* FUN_005875a0();
};

struct ProbeGrid
{
    bool FUN_00425fd0();
    int FUN_00544c30();
    int FUN_00544c60();
    ProbeCell* FUN_0054ddd0(int x, int y);
};

bool __cdecl FUN_005d4a40(void* self, void* value, int mode, float x, float y);

struct Searcher
{
    ProbeGrid* FUN_0059bb30();
    bool CheckNeighborCells();
};

// @fnv 0x006908f0
bool Searcher::CheckNeighborCells()
{
    if (FUN_0059bb30()->FUN_00425fd0())
    {
        return true;
    }

    bool result = true;
    int cellX2 = FUN_0059bb30()->FUN_00544c30();
    int cellY8 = FUN_0059bb30()->FUN_00544c60();

    float xWorld = (float)(cellX2 << 12);
    ProbeHolder* kWest = FUN_0059bb30()->FUN_0054ddd0(cellX2 - 1, cellY8)->FUN_005875a0();
    if (kWest != 0 && kWest->FUN_0070ec90() != 0)
    {
        for (unsigned int westIdx = 0; westIdx < kWest->FUN_0070ec90()->GetReferenceFlags(); ++westIdx)
        {
            if (!FUN_005d4a40(this, kWest->FUN_0070ec90()->FUN_00464f60(westIdx).FUN_00458b50(), 1, xWorld, 0.0f))
            {
                result = false;
            }
        }
    }

    xWorld = (float)(cellX2 << 12) + 4096.0;
    ProbeHolder* east = FUN_0059bb30()->FUN_0054ddd0(cellX2 + 1, cellY8)->FUN_005875a0();
    if (east != 0 && east->FUN_0070ec90() != 0)
    {
        for (unsigned int eastIdx = 0; eastIdx < east->FUN_0070ec90()->GetReferenceFlags(); ++eastIdx)
        {
            if (!FUN_005d4a40(this, east->FUN_0070ec90()->FUN_00464f60(eastIdx).FUN_00458b50(), 1, xWorld, 0.0f))
            {
                result = false;
            }
        }
    }

    float yWorld = (float)(cellY8 << 12);
    ProbeHolder* southVal = FUN_0059bb30()->FUN_0054ddd0(cellX2, cellY8 - 1)->FUN_005875a0();
    if (southVal != 0 && southVal->FUN_0070ec90() != 0)
    {
        for (unsigned int southIdx = 0; southIdx < southVal->FUN_0070ec90()->GetReferenceFlags(); ++southIdx)
        {
            if (!FUN_005d4a40(this, southVal->FUN_0070ec90()->FUN_00464f60(southIdx).FUN_00458b50(), 0, 0.0f, yWorld))
            {
                result = false;
            }
        }
    }

    yWorld = (float)(cellY8 << 12) + 4096.0;
    ProbeHolder* north2 = FUN_0059bb30()->FUN_0054ddd0(cellX2, cellY8 + 1)->FUN_005875a0();
    if (north2 != 0 && north2->FUN_0070ec90() != 0)
    {
        for (unsigned int northIdx = 0; northIdx < north2->FUN_0070ec90()->GetReferenceFlags(); ++northIdx)
        {
            if (!FUN_005d4a40(this, north2->FUN_0070ec90()->FUN_00464f60(northIdx).FUN_00458b50(), 0, 0.0f, yWorld))
            {
                result = false;
            }
        }
    }

    return result;
}

struct FUN_00691140_shell : public NavMeshTriangle
{
    bool FUN_00691140(int);
};

// @fnv 0x00691140
bool FUN_00691140_shell::FUN_00691140(int aFlag)
{
    return (aFlag & *(unsigned int*)((char*)this + 0xc)) != 0;
}

struct NavMeshGridX
{
    int gridWidth;
    float cellSizeX;
    float cellSizeY;
    float originX;
    float originY;
    void GetCellCoords(NiPoint3 const& point, unsigned int& outRow, unsigned int& outCol);
};

float __cdecl FUN_00406ce0(float x);
void __cdecl ClampInt(int* value, int lo, int hi);

// @fnv 0x006912a0
void NavMeshGridX::GetCellCoords(NiPoint3 const& point, unsigned int& outRow, unsigned int& outCol)
{
    float dxH = point.x - this->originX;
    float dY0 = point.y - this->originY;
    float gx1 = dxH / this->cellSizeX;
    float gY = dY0 / this->cellSizeY;

    int nCol = (int)FUN_00406ce0(gx1);
    ClampInt(&nCol, 0, this->gridWidth - 1);
    outCol = nCol;

    int row = (int)FUN_00406ce0(gY);
    ClampInt(&row, 0, this->gridWidth - 1);
    outRow = row;
}

struct NavMeshTriangle;
struct NiPoint3;
struct TriLike
{
    unsigned short GetVertex(unsigned int idx);
};
struct TriArrStub
{
    void* vt;
    void* buf;
    unsigned int sz;
    unsigned int cap;
    TriLike* GetTri(int idx);
};
struct GridStub
{
    int gridWidth;
    void GetCoords(const NiPoint3& pt, unsigned int& x, unsigned int& y);
    bool EmptyStructPlaceholder(unsigned short tri, int y, int x);
    int GetWidth();
};
struct OutArr
{
    void Clear(bool);
    unsigned int Add(int&);
    unsigned int GetSize();
};
unsigned int MaxU(unsigned int, unsigned int);
unsigned int MinU(unsigned int, unsigned int);
struct NavMeshStub
{
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
    TriArrStub tris;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    GridStub grid;
    const NiPoint3& GetVertexPos(unsigned short idx);
    unsigned int CollectTriangleCells(unsigned short tri, OutArr& out);
};
// @fnv 0x00691350
unsigned int NavMeshStub::CollectTriangleCells(unsigned short tri, OutArr& out)
{
    TriLike* pTri6 = tris.GetTri(tri);
    out.Clear(false);
    unsigned int maxX2 = 0;
    unsigned int minX7 = 0xFFFFFFFF;
    unsigned int maxY8 = 0;
    unsigned int minY7 = 0xFFFFFFFF;
    for (unsigned int i = 0; i < 3; i++)
    {
        const NiPoint3& pt2 = GetVertexPos(pTri6->GetVertex(i));
        unsigned int x9 = 0;
        unsigned int y6 = 0;
        grid.GetCoords(pt2, x9, y6);
        maxX2 = MaxU(maxX2, x9);
        minX7 = MinU(minX7, x9);
        maxY8 = MaxU(maxY8, y6);
        minY7 = MinU(minY7, y6);
    }
    for (unsigned int xi2 = minX7; xi2 < maxX2 + 1; xi2++)
    {
        for (unsigned int yi = minY7; yi < maxY8 + 1; yi++)
        {
            if (grid.EmptyStructPlaceholder(tri, yi, xi2))
            {
                int cell = grid.GetWidth() * xi2 + yi;
                out.Add(cell);
            }
        }
    }
    return out.GetSize();
}

struct AvoidNodeDescription
{
    NiPoint3 point1, point2;
    float radius, cost;
    unsigned int type, flags;
    void FUN_00691590(void* source, unsigned short triangle, float radius, float cost);
};
struct EdgeInfoOps : EdgeExtraInfo
{
    void FUN_00691570();
};
struct StaticAvoidOps : BSSimpleArray<NavMeshStaticAvoidNode, 1024>
{
    void AddData(AvoidNodeDescription* node);
};
struct NavMeshOps : NavMesh
{
    void AddAvoidNode(void* source, unsigned short triangle, float radius, float cost);
};
// @fnv 0x00691510
void NavMeshOps::AddAvoidNode(void* source, unsigned short triangle, float radius, float cost)
{
    AvoidNodeDescription avoidNode;
    avoidNode.FUN_00691590(source, triangle, radius, cost);
    static_cast<EdgeInfoOps*>(Triangles.FUN_00558dd0(triangle, -2147483647 - 1))->FUN_00691570();
    static_cast<StaticAvoidOps*>(&m_kStaticAvoidNodes)->AddData(&avoidNode);
}

struct FUN_00691570_shell : public NavMeshTriangle
{
    void FUN_00691570(int);
};

// @fnv 0x00691570
void FUN_00691570_shell::FUN_00691570(int aFlag)
{
    *(unsigned int*)((char*)this + 0xc) |= aFlag;
}

struct NHc_b9119;
struct NHc2_b9119
{
    NHc_b9119* FUN_005582f0(unsigned short tri, int idx);
};
struct NHc_b9119
{
    unsigned short FUN_005582d0();
};

struct FUN_0068efd0_cls
{
    EdgeT* GetEdge(EdgeT* out, unsigned short tri, int idx);
};

// @fnv 0x0068efd0
EdgeT* FUN_0068efd0_cls::GetEdge(EdgeT* out, unsigned short tri, int idx)
{
    EdgeT r;
    r.a = ((NHc2_b9119*)this)->FUN_005582f0(tri, idx)->FUN_005582d0();
    int m2 = (idx + 1) % 3;
    r.b = ((NHc2_b9119*)this)->FUN_005582f0(tri, m2)->FUN_005582d0();
    *out = r;
    return out;
}

struct FUN_0068f1d0_shell : public NavMeshTriangle
{
    bool IsEdgeFlagSet(int);
};

// Returns true if the bit at aiEdgeIndex is set in the 32-bit flags word at offset 0xc of this NavMeshTriangle.
// @fnv 0x0068f1d0
bool FUN_0068f1d0_shell::IsEdgeFlagSet(int aiEdgeIndex)
{
    return ((1 << aiEdgeIndex) & *(unsigned int*)((char*)this + 0xc)) != 0;
}

struct FUN_0068f200_shell : public NavMeshTriangle
{
    bool IsEdgeConnected(int);
};

// Returns true if the triangle's edge entry at aiEdgeIndex is not 0xFFFF.
// @fnv 0x0068f200
bool FUN_0068f200_shell::IsEdgeConnected(int aiEdgeIndex)
{
    return ((unsigned short*)((char*)this + 6))[aiEdgeIndex] != 0xFFFF;
}

extern float DAT_01016970;
class D2d0Elem
{
  public:
    virtual ~D2d0Elem();
    int m_04;
};
struct D2d0Cls
{
    int m_00;
    int m_04, m_08;
    float m_0c;
    int m_10, m_14, m_18, m_1c, m_20;
    D2d0Elem* m_24;
    void FUN_0069d2d0();
};
// Deletes the m_24 array and clears it, resets m_00 to 0 and sets m_0c to DAT_01016970.
// @fnv 0x0069d2d0
void D2d0Cls::FUN_0069d2d0()
{
    if (m_24)
    {
        delete[] m_24;
        m_24 = 0;
    }
    m_00 = 0;
    m_0c = DAT_01016970;
}

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    NiPointer<T>& operator=(const NiPointer<T>& ptr);
};
NiPointer<NavMesh> MakeNavMeshPointer(NavMesh* pMesh);
class NavMeshEdgeQuery
{
  public:
    bool FindAdjacentEdge(unsigned short usTri, int m_iEdgeNumber, NavMesh** m_ppLandNodes, int a4, int a5);
    bool FUN_0068f3b0(unsigned short usTri, int m_iEdgeNumber, NiPointer<NavMesh>& pFoundNavMesh, int a4, int a5);
};
// @fnv 0x0068f3b0
bool NavMeshEdgeQuery::FUN_0068f3b0(unsigned short usTri, int m_iEdgeNumber, NiPointer<NavMesh>& apMeshOut, int a4,
                                    int a5)
{
    NavMesh* pMesh = 0;
    if (FindAdjacentEdge(usTri, m_iEdgeNumber, &pMesh, a4, a5))
    {
        apMeshOut = MakeNavMeshPointer(pMesh);
        return true;
    }
    else
    {
        return false;
    }
}

struct ProxyX
{
    bool FUN_0068f2e0(void** appOut);
};

struct EInfoX
{
    int type;
    ProxyX* portal;
    unsigned short tri;
    unsigned short pad;
};

struct TriX
{
    bool IsEdgeFlagSet(int);
    unsigned short FUN_0068f2c0(int);
    unsigned char IsEdgeConnected(int);
};

struct MeshX
{
    unsigned int FUN_00558200();
    TriX* GetTriangle(unsigned short);
    EInfoX* GetEdgeInfo(unsigned short, int);
    ProxyX* FUN_0068efb0();
    bool FindAdjacentEdge(unsigned short, int, MeshX**, unsigned short*, int*);
};

// Finds the mesh, triangle and edge adjacent to aTri/aEdge, following a portal or the triangle's neighbour, and writes them to the out parameters.
// @fnv 0x0068f460
bool MeshX::FindAdjacentEdge(unsigned short aTri, int aEdge, MeshX** appOutMesh, unsigned short* apTri, int* apEdge)
{
    if (aTri >= this->FUN_00558200())
        return false;
    TriX* pTri = this->GetTriangle(aTri);
    if (pTri->IsEdgeConnected(aEdge))
    {
        if (pTri->IsEdgeFlagSet(aEdge))
        {
            EInfoX* pEdgeInfo = this->GetEdgeInfo(aTri, aEdge);
            if (!pEdgeInfo->portal)
            {
                return false;
            }
            else
            {
                MeshX* pMesh;
                if (pEdgeInfo->portal->FUN_0068f2e0((void**)&pMesh))
                {
                    unsigned short usPortalTri = pEdgeInfo->tri;
                    if (usPortalTri >= pMesh->FUN_00558200())
                        return false;
                    TriX* pAdjTriangle = pMesh->GetTriangle(usPortalTri);
                    int q;
                    for (q = 0; q < 3; q++)
                    {
                        if (pAdjTriangle->IsEdgeFlagSet(q))
                        {
                            EInfoX* pE = pMesh->GetEdgeInfo(usPortalTri, q);
                            if (!pE)
                                continue;
                            if (pE->portal == this->FUN_0068efb0() && pE->tri == aTri)
                                break;
                        }
                    }
                    if (q == 3)
                    {
                        return false;
                    }
                    else
                    {
                        *appOutMesh = pMesh;
                        *apTri = usPortalTri;
                        *apEdge = q;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            *appOutMesh = this;
            *apTri = pTri->FUN_0068f2c0(aEdge);
            TriX* pAdjTriangle = this->GetTriangle(*apTri);
            int r;
            for (r = 0; r < 3; r++)
            {
                if (!pAdjTriangle->IsEdgeFlagSet(r) && pAdjTriangle->FUN_0068f2c0(r) == aTri)
                    break;
            }
            if (r >= 3)
                return false;
            *apEdge = r;
            return true;
        }
    }
    else
    {
        return false;
    }
}

class NavMesh68F3
{
  public:
    const NavMeshInfo* FUN_0068efb0();
};

struct NavMeshEdgeRef68F3
{
    int unk00;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

struct NavMeshEdgeOut68F3
{
    const NavMeshInfo* m_pNavigationMesh;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

class NavMeshPortalMgr68F3
{
  public:
    bool FindAdjacentEdge(unsigned short m_usTriangleID, int m_iEdgeNumber, NavMesh68F3** ppNavMesh,
                          unsigned short* pusTriangle, int* piEdge);
    bool FUN_0068f340(const NavMeshEdgeRef68F3* pkRef, NavMeshEdgeOut68F3* pkOut);
};

// On success, stores the adjacent mesh's navigation info, triangle ID, and edge number in pkOut.
// @fnv 0x0068f340
bool NavMeshPortalMgr68F3::FUN_0068f340(const NavMeshEdgeRef68F3* pkRef, NavMeshEdgeOut68F3* pkOut)
{
    NavMesh68F3* m_pLocationNavMesh = 0;
    int edgeIndex = -1;
    unsigned short triangle;
    if (FindAdjacentEdge(pkRef->m_usTriangleID, pkRef->m_iEdgeNumber, &m_pLocationNavMesh, &triangle, &edgeIndex))
    {
        pkOut->m_pNavigationMesh = m_pLocationNavMesh->FUN_0068efb0();
        pkOut->m_usTriangleID = triangle;
        pkOut->m_iEdgeNumber = edgeIndex;
        return true;
    }
    else
    {
        return false;
    }
}

class FUN_00691f00
{
  public:
    virtual ~FUN_00691f00();

    void FUN_00438af0();
};

class FUN_00691ea0 : public FUN_00691f00
{
  public:
    virtual ~FUN_00691ea0();
};

// @fnv 0x00691ea0
FUN_00691ea0::~FUN_00691ea0()
{
    FUN_00438af0();
}

// fallout_shared/pathfinding/navmeshrender.cpp: NavMeshObstacleManager, ObstacleTask, NavRenderX, RenderTask and more (12 functions)

#include "navmeshrender_decls.h"

// The PC spans supplied for this unit are obstacle-management methods. The
// legacy PaddedBooleanState labels disagree with their member layouts and lifetimes.

// Iterates the obstacle list, looks up each rigid body's ObstacleData, skips ones already in the active list, and adds the rest to its head.
// @fnv 0x006c49e0
void NavMeshObstacleManager::ProcessActivatedObstacles()
{
    unsigned int count = m_kActivatedRigidBodies.GetCount();
    for (unsigned int uiIndex = 0; uiIndex < count; ++uiIndex)
    {
        bhkRigidBody* body;
        m_kActivatedRigidBodies.FUN_006c6030(body);
        NiPointer<ObstacleData> obstacle;
        if (RigidBodyObstacleLookup.GetAt(body, obstacle))
        {
            if (m_kActiveObstacles.Contains(obstacle))
                continue;
            m_kActiveObstacles.AddHead(obstacle);
        }
    }
}

// Stores the obstacle pointer, task type and navmesh pointer into the object's fields.
// @fnv 0x006c7d70
ObstacleTask::ObstacleTask(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type, const NavMeshPtr& navMesh)
{
    m_spRegisteredObstacle = obstacle;
    eType = type;
    apSearchNavMesh = navMesh;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x0049f1c0
void* __fastcall FUN_0049f1c0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

struct NavMeshTriangle
{
    void Clear();
    bool HasEdgeExtraInfo();
    bool IsPreferred();
    void TogglePreferred();
    bool IsWaterTriangle();
    void ToggleWater();
    bool IsNoLargeCreature();
    void ToggleNoLargeCreature();
    void GetVerts(unsigned short*, unsigned short*, unsigned short*);
    void GetTris(unsigned short*, unsigned short*, unsigned short*);
    void SetVerts(unsigned short, unsigned short, unsigned short);
    void SetTris(unsigned short, unsigned short, unsigned short);
    bool GetFlag(int);
    void SetFlag(int);
    void ClearFlag(int);
    unsigned int GetTriangleFlags();
    void SetTriangleFlags(unsigned int);
    unsigned short GetVert(unsigned int);
    void SetVert(unsigned int, unsigned short);
    unsigned short GetTri(unsigned int);
    void SetTri(unsigned int, unsigned short);
    bool EdgeHasExtraInfo(int);
    unsigned short GetEdgeExtraInfoValue(int);
    void SetEdgeExtraInfo(int, unsigned short);
    void ClearEdgeExtraInfo(int);
    bool HasDoorPortal();
    bool IsEdgeConnected(int);
    unsigned short GetTriOrExtraInfo(int);
    void SetTriOrExtraInfo(int, unsigned short);
    unsigned short GetObjectCount();
    void SetObjectCount(unsigned short);
    void ClearObjectCount();
    static bool HasCover(unsigned int);
    bool HasCover();
    bool HasCoverEdge0();
    bool HasCoverEdge1();
    static bool HasCoverOrWallFlags(unsigned int);
    bool HasCoverOrWallFlags();
    bool HasCoverOrWallEdge0();
    bool HasCoverOrWallEdge1();
    bool IsWall(unsigned short);
    bool IsEdgeOpen(unsigned short);
    unsigned short GetEdgeCover(unsigned short);
    bool GetEdgeSides(unsigned short, bool*, bool*);
    static void GetEdgeCoverData(unsigned int, unsigned short, unsigned short*, bool*, bool*);
    void GetEdgeCoverData(unsigned short, unsigned short*, bool*, bool*);
    void ClearCover();
    static void SetEdgeCover(unsigned int*, unsigned short, unsigned short, bool, bool);
    void SetEdgeCover(unsigned short, unsigned short, bool, bool);
    int Rotate(int);
    bool ConvertCoverEdgeFormat();
    static unsigned int GetCoverLevel(float, bool, bool);
    static float GetCoverHeight(unsigned int);
    void Endian();
    char Vertices[6];
    char Triangles[6];
    unsigned int m_uiTriangleFlags;
};
typedef char _sizecheck_NavMeshTriangle[sizeof(NavMeshTriangle) == 16 ? 1 : -1];
struct FUN_006a5ec0_shell : public NavMeshTriangle
{
    bool FUN_006a5ec0();
};

// @fnv 0x006a5ec0
bool FUN_006a5ec0_shell::FUN_006a5ec0()
{
    return GetFlag(0x200);
}

struct FUN_006a5b30_shell
{
    short m_uiX;
    short m_uiY;
    short m_uiZ;
    void GetTripleShorts(short* a, short* b, short* c);
};

// Copies the three short fields of this object into the three output pointers.
// @fnv 0x006a5b30
void __thiscall FUN_006a5b30_shell::GetTripleShorts(short* pFirst, short* pSecond, short* pThird)
{
    *pFirst = this->m_uiX;
    *pSecond = this->m_uiY;
    *pThird = this->m_uiZ;
}

struct FUN_006a5b70_shell
{
    short m_00;
    short m_02;
    short m_04;
    short m_06;
    short m_08;
    short m_0A;
    void FUN_006a5b70(short* a, short* b, short* c);
};

// Copies the shell's m_06, m_08 and m_0A shorts into the three output pointers.
// @fnv 0x006a5b70
void FUN_006a5b70_shell::FUN_006a5b70(short* a, short* b, short* c)
{
    *a = m_06;
    *b = m_08;
    *c = m_0A;
}

extern float runtimeInitializationFloat369;
// Clamps a to 0xF and returns it multiplied by runtimeInitializationFloat369.
// @fnv 0x006a5af0
float ScaleClampedValue(unsigned int auiValue)
{
    if (auiValue > 0xF)
        auiValue = 0xF;
    return auiValue * runtimeInitializationFloat369;
}

struct NiUpdateData
{
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;

    NiUpdateData(float, bool, bool);
};

struct NiNode
{
    void Update(const NiUpdateData&);
    void FUN_004def90();
};

struct NiAVObject : public NiNode
{
    void UpdateSceneObject();
};

struct GO
{
    operator unsigned int() const;
};

struct GlobalObject_00633c90 : public GO
{
};

extern GlobalObject_00633c90 g_011d6e5c;

struct PaddedBooleanState
{
    unsigned char padding[0x210];
    bool m_bState;

    void SetDraw(bool);
};

// @fnv 0x006a36e0
void PaddedBooleanState::SetDraw(bool abDraw)
{
    if (abDraw)
    {
        reinterpret_cast<NiAVObject*>(g_011d6e5c.operator unsigned int())->UpdateSceneObject();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(g_011d6e5c.operator unsigned int())->Update(UpdateData);
    }
    else
    {
        reinterpret_cast<NiNode*>(g_011d6e5c.operator unsigned int())->FUN_004def90();
        reinterpret_cast<NiAVObject*>(g_011d6e5c.operator unsigned int())->UpdateSceneObject();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(g_011d6e5c.operator unsigned int())->Update(UpdateData);

        reinterpret_cast<NiTPointerMap<NiNode*, NiNode*>*>(reinterpret_cast<char*>(this) + 0x200)->RemoveAll();
    }

    m_bState = abDraw;
}

namespace fnv_006a5ca0 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};

struct DoorH
{
    void* GetParentWorldSpace();
};

struct TESWorldSpace
{
    TESObjectCELL* GetCellAtGridPosition(int x, int y);
};

struct TES
{
    TESObjectCELL* GetDetailedActorPathHandler();
};

struct GlobalObject_0045cfe0
{
    int* Int();
};

struct PaddedBooleanState
{
    void SetDraw(bool value);
    void AddDrawOnlyNavMeshes(TESObjectCELL* cell, bool value);
    void UpdateRenderOnlyNavMeshes();
};

bool __fastcall FUN_00425fd0(TESObjectCELL* cell);
int __cdecl FUN_00552ba0(void);

GlobalObject_0045cfe0 g_011c63cc;
int g_TES;

// @fnv 0x006a5ca0
void PaddedBooleanState::UpdateRenderOnlyNavMeshes()
{
    TESObjectCELL* pcellVal;
    int d8;
    int x9;
    int y3;
    TESObjectCELL* pgridCell4;

    SetDraw(false);
    pcellVal = reinterpret_cast<TES*>(g_TES)->GetDetailedActorPathHandler();
    if (pcellVal)
    {
        if (!FUN_00425fd0(pcellVal))
        {
            d8 = (g_011c63cc.Int()[0] - 1) / 2;
            x9 = reinterpret_cast<CellH*>(pcellVal)->GetCellGridX() - d8;
            for (; x9 <= reinterpret_cast<CellH*>(pcellVal)->GetCellGridX() + d8; ++x9)
            {
                y3 = reinterpret_cast<CellH*>(pcellVal)->GetCellGridY() - d8;
                for (; y3 <= reinterpret_cast<CellH*>(pcellVal)->GetCellGridY() + d8; ++y3)
                {
                    pgridCell4 = reinterpret_cast<TESWorldSpace*>(reinterpret_cast<DoorH*>(pcellVal)->GetParentWorldSpace())
                                     ->GetCellAtGridPosition(x9, y3);
                    AddDrawOnlyNavMeshes(pgridCell4, false);
                }
            }
        }
        else
        {
            reinterpret_cast<PaddedBooleanState*>(FUN_00552ba0())->AddDrawOnlyNavMeshes(pcellVal, false);
        }
    }
    SetDraw(true);
}
}  // namespace fnv_006a5ca0

struct Pt3X
{
    float x, y, z;
    Pt3X();
    Pt3X operator*(float afScale) const;
    Pt3X operator+(const Pt3X& arPt) const;
    Pt3X operator-(const Pt3X& arPt) const;
    void Unitize();
    Pt3X& operator*=(float afScale);
};
struct EmptyX
{
};
struct Pt3PodX : public EmptyX
{
    float x, y, z;
    Pt3PodX* Set(float afX, float afY, float afZ);
};
struct ColorX
{
    float r, g, b, a;
    ColorX();
    ColorX(float afR, float afG, float afB, float afA);
};
struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    short sPad;
    int iActionIndex;
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct FixedStrX
{
    const char* pString;
    FixedStrX(const char* apString);
    ~FixedStrX();
};
struct AVObjX;
struct ObjX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void AttachChildInAvailableSlot(AVObjX* apChild, bool abFirstAvail);
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
};
struct AVObjX : public ObjX
{
    void AttachProperty(AVObjX* apProperty);
    void GetTransformScale(const Pt3PodX* apPos);
    void SetName(const FixedStrX& arName);
    void SetAlphaBlending(bool abBlend);
    void SetFlags(int aiFlags, int aiArg);
};
struct NodeX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    NodeX(unsigned short ausChildren);
    void Update(const UpdateDataX& arData);
    void UpdateSceneObject();
};
struct LinesX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    LinesX(unsigned short ausVerts, Pt3X* apVerts, ColorX* apColors, int a, int b, int c, bool* apFlags);
};
struct TriShapeX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    TriShapeX(unsigned short ausVerts, Pt3X* apVerts, Pt3X* apNormals, ColorX* apColors, void* apUV,
              unsigned short ausUV, int aiFlags, unsigned short ausTris, unsigned short* apusList);
};
struct PropX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    PropX();
};
struct AlphaX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    AlphaX();
};
template <class T> struct SpX
{
    T* m_pObject;
    SpX(T* apObject);
    SpX(const SpX& arPtr);
    ~SpX();
    void operator=(T* apObject);
    operator T*() const;
};
struct Pt3ArrX
{
    Pt3X* pData;
    int iSize, iAlloc, iGrow;
    Pt3ArrX(int aiSize);
    ~Pt3ArrX();
    Pt3X& GetAt(unsigned int auiIndex);
    void SetSize(int aiSize, int aiArg);
};
struct ColorArrX
{
    ColorX* pData;
    int iSize, iAlloc, iGrow;
    ColorArrX(int aiSize);
    ~ColorArrX();
    ColorX& GetAt(int aiIndex);
    void SetSize(int aiSize, int aiArg);
};
struct BoolArrX
{
    bool* pData;
    int iSize, iAlloc, iGrow;
    BoolArrX(int aiSize);
    ~BoolArrX();
    bool& GetAt(int aiIndex);
};
struct NavTriX
{
    bool GetFlag(int aiFlag);
    void GetVerts(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    void GetTris(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    bool EdgeHasExtraInfo(int aiEdge);
    void GetEdgeCoverData(unsigned short ausEdge, unsigned short* apusCover, bool* apbLeft, bool* apbRight);
};
struct SphereX
{
    float GetRadius() const;
    Pt3PodX* GetNavMeshData();
};
struct NavMeshX;
struct NavMeshPtrX
{
    NavMeshX* m_pObject;
    NavMeshPtrX();
    NavMeshPtrX(const NavMeshPtrX& arPtr);
    ~NavMeshPtrX();
    NavMeshPtrX& operator=(const NavMeshPtrX& arPtr);
    operator NavMeshX*() const;
    bool Equals(const NavMeshPtrX& arPtr);
};
struct NavInfoX
{
    bool IsLoaded() const;
    void GetMesh(NavMeshPtrX& arMesh);
};
struct EdgeInfoX
{
    int iActionIndex;
    NavInfoX* pTarget;
    unsigned short usTri;
};
struct NavMeshX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    Pt3ArrX kVerts;
    unsigned int GetTriCount();
    unsigned int GetVertCount();
    bool IsDisabled();
    NavTriX* GetTriangle(unsigned short ausTri);
    EdgeInfoX* GetEdgeInfo(unsigned short ausTri, int aiEdge);
    unsigned int GetSphereCount();
    SphereX& GetSphere(unsigned int auiIndex);
};
struct NavArrX
{
    NavMeshPtrX GetAt(unsigned int auiIndex);
};
struct CellX
{
    NavArrX* GetNavMeshArray();
};
struct CellMapX
{
    bool GetAt(CellX* apCell, SpX<NodeX>& arNode);
    void SetAt(CellX* apCell, SpX<NodeX> aspNode);
};
struct NavRenderX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    SpX<AVObjX> spWireframe;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    SpX<AVObjX> spVertexColor;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    ColorX aColors[11];
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    SpX<AVObjX> spZBuffer;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    CellMapX kMap;
    int GetTriColor(NavTriX* apTri);
    void AddDrawOnlyNavMeshes(CellX* apCell, bool abUpdate);
};
unsigned int __fastcall xGetNavMeshCount(NavArrX* apArray);
void* __cdecl xNiMalloc(unsigned int auiSize);
float __cdecl xGetCoverHeight(unsigned int auiCover);
AVObjX* __cdecl xMakeLine(Pt3X& arA, Pt3X& arB, float afA, float afB, float afHeight, float afOffset, ColorX& arColor,
                          int aiArg);
AVObjX* __cdecl xMakeSphere(float afRadius, int aiSlices, int aiStacks, ColorX* apColor);
void __cdecl xUpdateNode(NodeX* apNode);
void __cdecl xPrepareNode(NodeX* apNode, int a, int b);
extern "C" void* __cdecl memcpy(void* apDst, const void* apSrc, unsigned int auiSize);
extern SpX<NodeX> xspNavRoot;
extern bool xbShowPortals;
extern bool xbShowCover;
extern float xfCoverWidth, xfCoverScale, xfCoverOffset, xfCoverWidth2;
// Builds and attaches a navmesh debug render node for the cell: lines, cover lines, triangles and spheres, then updates the nav root if requested.
// @fnv 0x006a37a0
void NavRenderX::AddDrawOnlyNavMeshes(CellX* apCell, bool abUpdate)
{
    NavArrX* qfTOqo;
    unsigned int qQMZREG;
    if (!apCell)
        return;
    qfTOqo = apCell->GetNavMeshArray();
    if (!qfTOqo)
        return;
    qQMZREG = xGetNavMeshCount(qfTOqo);
    SpX<NodeX> qAhbO(0);
    if (!kMap.GetAt(apCell, qAhbO))
    {
        qAhbO = new NodeX(qQMZREG * 2);
        ((NodeX*)xspNavRoot)->AttachChildInAvailableSlot(qAhbO, true);
        kMap.SetAt(apCell, qAhbO);
    }
    else
    {
        return;
    }
    NavMeshPtrX qsSDDgz;
    for (unsigned int qbfQdhM = 0; qbfQdhM < qQMZREG; qbfQdhM++)
    {
        unsigned int qXMUYT;
        unsigned int qpia;
        ColorX* qJDuOZ;
        bool* qxQHW;
        unsigned int qIpA;
        unsigned int qArxcFu;
        unsigned int qMBds;
        unsigned short* qaGEwZ;
        Pt3X* qFffvLe;
        ColorX* qZAdkzg;
        bool qfCsmZ;
        unsigned int qVduN;
        Pt3X* qbXcw;
        unsigned int qBCzzXA;
        qsSDDgz = qfTOqo->GetAt(qbfQdhM);
        qMBds = ((NavMeshX*)qsSDDgz)->GetTriCount();
        qBCzzXA = ((NavMeshX*)qsSDDgz)->GetVertCount();
        if (!qMBds)
            continue;
        qfCsmZ = ((NavMeshX*)qsSDDgz)->IsDisabled();
        Pt3ArrX qkJsUdT(qBCzzXA);
        ColorArrX qrEZrs(qBCzzXA);
        if (qfCsmZ)
        {
            for (unsigned int qAXSCg = 0; qAXSCg < qBCzzXA; qAXSCg++)
            {
                qkJsUdT.GetAt(qAXSCg) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qAXSCg);
                qrEZrs.GetAt(qAXSCg) = aColors[10];
            }
        }
        else
        {
            for (unsigned int qBLsiu = 0; qBLsiu < qBCzzXA; qBLsiu++)
            {
                qkJsUdT.GetAt(qBLsiu) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qBLsiu);
                qrEZrs.GetAt(qBLsiu) = aColors[0];
            }
        }
        qaGEwZ = (unsigned short*)xNiMalloc(qMBds * 3 * sizeof(unsigned short));
        qXMUYT = qBCzzXA;
        qVduN = 0;
        qIpA = qMBds * 6;
        Pt3ArrX qDdzMIp(qIpA);
        BoolArrX qHXYKT(qIpA);
        ColorArrX qGfbX(qIpA);
        qpia = 0;
        Pt3ArrX qZWI(qIpA);
        BoolArrX qrKBG(qIpA);
        ColorArrX qpqRa(qIpA);
        qArxcFu = 0;
        for (unsigned int qrUCJDN = 0; qrUCJDN < qMBds; qrUCJDN++)
        {
            NavTriX* qidnYUK = ((NavMeshX*)qsSDDgz)->GetTriangle(qrUCJDN);
            if (qidnYUK->GetFlag(0x20))
                continue;
            unsigned short qxWmVch[3];
            qidnYUK->GetVerts(&qxWmVch[0], &qxWmVch[1], &qxWmVch[2]);
            if (qfCsmZ)
            {
                qaGEwZ[qVduN] = qxWmVch[0];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[1];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[2];
                qVduN++;
            }
            else
            {
                int qhQRuW = GetTriColor(qidnYUK);
                if (qhQRuW)
                {
                    qkJsUdT.SetSize(qXMUYT + 3, 1);
                    qrEZrs.SetSize(qXMUYT + 3, 1);
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[0]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[1]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[2]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                }
                else
                {
                    qaGEwZ[qVduN] = qxWmVch[0];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[1];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[2];
                    qVduN++;
                }
            }
            unsigned short qpydTG[3];
            qidnYUK->GetTris(&qpydTG[0], &qpydTG[1], &qpydTG[2]);
            for (unsigned short qOFvKuu = 0; qOFvKuu < 3; qOFvKuu++)
            {
                unsigned int qxDeKK = qpia + 1;
                bool qZNIZJV = qidnYUK->EdgeHasExtraInfo(qOFvKuu);
                if (xbShowPortals && qpydTG[qOFvKuu] != 0xffff)
                {
                    NavMeshPtrX qfpzU(qsSDDgz);
                    NavTriX* qYdAnhh = 0;
                    bool qoPB = false;
                    unsigned short qQGWBE = 0xffff;
                    if (qZNIZJV)
                    {
                        EdgeInfoX* qXSF = ((NavMeshX*)qsSDDgz)->GetEdgeInfo(qrUCJDN, qOFvKuu);
                        if (qXSF && qXSF->pTarget && qXSF->pTarget->IsLoaded())
                        {
                            qXSF->pTarget->GetMesh(qfpzU);
                            unsigned int qgqKr = qXSF->usTri;
                            qYdAnhh = ((NavMeshX*)qfpzU)->GetTriangle(qgqKr);
                            unsigned short qGTHx[3];
                            qYdAnhh->GetTris(&qGTHx[0], &qGTHx[1], &qGTHx[2]);
                            for (int qBMjHz = 0; qBMjHz < 3; qBMjHz++)
                            {
                                if (qYdAnhh->EdgeHasExtraInfo(qBMjHz))
                                {
                                    EdgeInfoX* qoqcoe = ((NavMeshX*)qfpzU)->GetEdgeInfo(qgqKr, qBMjHz);
                                    if (qoqcoe)
                                    {
                                        NavMeshPtrX qVCM;
                                        qoqcoe->pTarget->GetMesh(qVCM);
                                        if (qVCM.Equals(qsSDDgz) && qoqcoe->usTri == qrUCJDN)
                                        {
                                            qoPB = true;
                                            qQGWBE = qBMjHz;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        qYdAnhh = ((NavMeshX*)qsSDDgz)->GetTriangle(qpydTG[qOFvKuu]);
                        unsigned short qRBAdC[3];
                        qYdAnhh->GetTris(&qRBAdC[0], &qRBAdC[1], &qRBAdC[2]);
                        for (int qQirx = 0; qQirx < 3; qQirx++)
                        {
                            if (qRBAdC[qQirx] == qrUCJDN)
                            {
                                qoPB = true;
                                qQGWBE = qQirx;
                            }
                        }
                    }
                    if (qoPB)
                    {
                        unsigned int qdmSnI = qArxcFu + 1;
                        unsigned short qSuoDt = qxWmVch[qOFvKuu];
                        unsigned short qbGYp = qxWmVch[(qOFvKuu + 1) % 3];
                        Pt3X qzzQr = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qSuoDt);
                        Pt3X qsAu = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qbGYp);
                        Pt3X qArJcY = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[(qOFvKuu + 2) % 3]);
                        float qnuVZg = 0.37f;
                        float qqtISP = 0.33f;
                        float qdbVTq = 0.3f;
                        Pt3X qHVMR = qsAu * qnuVZg + qzzQr * qqtISP + qArJcY * qdbVTq;
                        unsigned short qhxpxJd[3];
                        qYdAnhh->GetVerts(&qhxpxJd[0], &qhxpxJd[1], &qhxpxJd[2]);
                        if (false && qQGWBE > 2)
                        {
                        }  // release build: index assert compiled out
                        Pt3X qyFp = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[qQGWBE]);
                        Pt3X qVar = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[(qQGWBE + 1) % 3]);
                        Pt3X qOqnE = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[(qQGWBE + 2) % 3]);
                        Pt3X qkbsJ = qyFp * qnuVZg + qVar * qqtISP + qOqnE * qdbVTq;
                        qZWI.GetAt(qArxcFu) = qHVMR;
                        qZWI.GetAt(qdmSnI) = qkbsJ;
                        qrKBG.GetAt(qArxcFu) = true;
                        qrKBG.GetAt(qdmSnI) = false;
                        qpqRa.GetAt(qArxcFu) = aColors[2];
                        qpqRa.GetAt(qdmSnI) = aColors[9];
                        qArxcFu += 2;
                    }
                }
                if (qpydTG[qOFvKuu] > qrUCJDN || qZNIZJV)
                {
                    qDdzMIp.GetAt(qpia) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[qOFvKuu]);
                    qDdzMIp.GetAt(qxDeKK) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[(qOFvKuu + 1) % 3]);
                    qHXYKT.GetAt(qpia) = true;
                    qHXYKT.GetAt(qxDeKK) = false;
                    if (qpydTG[qOFvKuu] != 0xffff)
                    {
                        if (qZNIZJV)
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                        else
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                    }
                    else
                    {
                        unsigned short qXGDO = 0;
                        bool qnEqwa = false;
                        bool qtOMjSX = false;
                        if (qOFvKuu < 2u)
                            qidnYUK->GetEdgeCoverData(qOFvKuu, &qXGDO, &qnEqwa, &qtOMjSX);
                        switch (qXGDO)
                        {
                        case 0:
                            qGfbX.GetAt(qpia) = aColors[6];
                            qGfbX.GetAt(qxDeKK) = aColors[6];
                            break;
                        case 1:
                            qGfbX.GetAt(qpia) = aColors[10];
                            qGfbX.GetAt(qxDeKK) = aColors[10];
                            break;
                        case 2:
                            qGfbX.GetAt(qpia) = aColors[5];
                            qGfbX.GetAt(qxDeKK) = aColors[5];
                            break;
                        case 0xf:
                            qGfbX.GetAt(qpia) = aColors[9];
                            qGfbX.GetAt(qxDeKK) = aColors[9];
                            break;
                        default:
                            qGfbX.GetAt(qpia) = aColors[7];
                            qGfbX.GetAt(qxDeKK) = aColors[7];
                            break;
                        }
                        if (xbShowCover && qXGDO > 1u)
                        {
                            float qObI = xGetCoverHeight(qXGDO);
                            AVObjX* qYePyBl = xMakeLine(qDdzMIp.GetAt(qpia), qDdzMIp.GetAt(qxDeKK), xfCoverWidth,
                                                        xfCoverWidth, qObI, 0.0f, qGfbX.GetAt(qpia), 0);
                            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qYePyBl, true);
                            Pt3X qZgNzZy = qDdzMIp.GetAt(qpia) - qDdzMIp.GetAt(qxDeKK);
                            qZgNzZy.Unitize();
                            qZgNzZy *= xfCoverScale;
                            if (qnEqwa)
                            {
                                Pt3X qqrLNms = qDdzMIp.GetAt(qxDeKK) - qZgNzZy;
                                Pt3X qYvz = qDdzMIp.GetAt(qxDeKK) + qZgNzZy;
                                AVObjX* qrBzVM = xMakeLine(qqrLNms, qYvz, xfCoverWidth2, xfCoverWidth2,
                                                           qObI + xfCoverOffset, 0.0f, aColors[10], 0);
                                ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qrBzVM, true);
                            }
                            if (qtOMjSX)
                            {
                                Pt3X qCVSV = qDdzMIp.GetAt(qpia) - qZgNzZy;
                                Pt3X qOPw = qDdzMIp.GetAt(qpia) + qZgNzZy;
                                AVObjX* qjThF = xMakeLine(qCVSV, qOPw, xfCoverWidth2, xfCoverWidth2,
                                                          qObI + xfCoverOffset, 0.0f, aColors[10], 0);
                                ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qjThF, true);
                            }
                        }
                    }
                    qpia += 2;
                }
            }
        }
        qbXcw = new Pt3X[qpia];
        qJDuOZ = new ColorX[qpia];
        qxQHW = new bool[qpia];
        memcpy(qbXcw, &qDdzMIp.GetAt(0), qpia * sizeof(Pt3X));
        memcpy(qJDuOZ, &qGfbX.GetAt(0), qpia * sizeof(ColorX));
        memcpy(qxQHW, &qHXYKT.GetAt(0), qpia);
        SpX<AVObjX> qrzAir(new LinesX(qpia, qbXcw, qJDuOZ, 0, 0, 0, qxQHW));
        SpX<AVObjX> qdqWL(new PropX());
        ((AVObjX*)qdqWL)->SetFlags(0x20, 0);
        ((AVObjX*)qrzAir)->AttachProperty(qdqWL);
        ((AVObjX*)qrzAir)->AttachProperty(spWireframe);
        ((AVObjX*)qrzAir)->AttachProperty(spZBuffer);
        ((AVObjX*)qrzAir)->GetTransformScale(Pt3PodX().Set(0.0f, 0.0f, 1.0f));
        SpX<AVObjX> qvyWyw(0);
        if (qArxcFu > 0)
        {
            Pt3X* qOHwfb = new Pt3X[qArxcFu];
            ColorX* qkPflib = new ColorX[qArxcFu];
            bool* qEXZLB = new bool[qArxcFu];
            memcpy(qOHwfb, &qZWI.GetAt(0), qArxcFu * sizeof(Pt3X));
            memcpy(qkPflib, &qpqRa.GetAt(0), qArxcFu * sizeof(ColorX));
            memcpy(qEXZLB, &qrKBG.GetAt(0), qArxcFu);
            qvyWyw = new LinesX(qArxcFu, qOHwfb, qkPflib, 0, 0, 0, qEXZLB);
            qdqWL = new PropX();
            ((AVObjX*)qdqWL)->SetFlags(0x20, 0);
            ((AVObjX*)qvyWyw)->AttachProperty(qdqWL);
            ((AVObjX*)qvyWyw)->AttachProperty(spZBuffer);
            ((AVObjX*)qvyWyw)->GetTransformScale(Pt3PodX().Set(0.0f, 0.0f, 3.0f));
        }
        qFffvLe = new Pt3X[qXMUYT];
        qZAdkzg = new ColorX[qXMUYT];
        memcpy(qFffvLe, &qkJsUdT.GetAt(0), qXMUYT * sizeof(Pt3X));
        memcpy(qZAdkzg, &qrEZrs.GetAt(0), qXMUYT * sizeof(ColorX));
        SpX<AVObjX> qpTd(new TriShapeX(qXMUYT, qFffvLe, 0, qZAdkzg, 0, 0, 0, qMBds, qaGEwZ));
        ((AVObjX*)qpTd)->SetName(FixedStrX("NavMesh Triangles"));
        SpX<AVObjX> qSVM(new PropX());
        ((AVObjX*)qSVM)->SetFlags(0x20, 0);
        ((AVObjX*)qpTd)->AttachProperty(spVertexColor);
        ((AVObjX*)qpTd)->AttachProperty(spZBuffer);
        ((AVObjX*)qpTd)->AttachProperty(qSVM);
        ((AVObjX*)qpTd)->GetTransformScale(Pt3PodX().Set(0.0f, 0.0f, 1.0f));
        for (unsigned int qMFd = 0; qMFd < ((NavMeshX*)qsSDDgz)->GetSphereCount(); qMFd++)
        {
            SphereX* qsCroYH = &((NavMeshX*)qsSDDgz)->GetSphere(qMFd);
            ColorX qODE(0.25f, 0.0f, 0.0f, 0.5f);
            SpX<AVObjX> qFwpo(xMakeSphere(qsCroYH->GetRadius(), 10, 10, &qODE));
            SpX<AVObjX> qmgeiw(new AlphaX());
            ((AVObjX*)qmgeiw)->SetAlphaBlending(true);
            ((AVObjX*)qFwpo)->AttachProperty(qmgeiw);
            ((AVObjX*)qFwpo)->GetTransformScale(qsCroYH->GetNavMeshData());
            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qFwpo, true);
        }
        ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qrzAir, true);
        ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qpTd, true);
        if (qArxcFu > 0)
            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qvyWyw, true);
        xUpdateNode(qAhbO);
        xPrepareNode(qAhbO, 0, 0);
    }
    if (abUpdate)
    {
        UpdateDataX qBQkjNg(0.0f, false, false);
        ((NodeX*)xspNavRoot)->Update(qBQkjNg);
        ((NodeX*)xspNavRoot)->UpdateSceneObject();
    }
}

struct WorldObject : public NiAVObject
{
    virtual void DeleteThis();
    virtual void GetRTTI();
    virtual void AsNode();
    virtual void AsSwitchNode();
    virtual void AsFadeNode();
    virtual void AsMultiBoundNode();
    virtual void AsGeometry();
    virtual void AsTriStrips();
    virtual void AsTriShape();
    virtual void AsSegmentedTriShape();
    virtual void AsSubIndexTriShape();
    virtual void AsDynamicTriShape();
    virtual void AsNiGeometry();
    virtual void AsNiTriBasedGeom();
    virtual void AsNiTriShape();
    virtual void AsParticlesGeom();
    virtual void AsLinesGeom();
    virtual void AsCollisionObject();
    virtual void AsBlendCollisionObject();
    virtual void AsAttachmentCollisionObject();
    virtual void AsRigidBody();
    virtual void AsLimitedHingeConstraint();
    virtual void MakeClone();
    virtual void LoadBinary();
    virtual void LinkObject();
    virtual void RegisterStreamables();
    virtual void SaveBinary();
    virtual void IsEqual();
    virtual void ProcessClone();
    virtual void PostLinkObject();
    virtual void StreamCanSkip();
    virtual void GetStreamableRTTI();
    virtual void GetBlockAllocationSize();
    virtual void GetGroup();
    virtual void SetGroup();
    virtual void AsControllerManager();
    virtual void UpdateControllers();
    virtual void PerformOperation();
    virtual void AttachProperty();
    virtual void SetMaterialNeedsUpdate();
    virtual void SetDefaultMaterialNeedsUpdateFlag();
    virtual void GetObjectByName();
    virtual void SetSelectiveUpdateFlags();
    virtual void UpdateDownwardPass();
    virtual void UpdateSelectedDownwardPass();
    virtual void UpdateRigidDownwardPass();
    virtual void UpdateWorldBound();
    virtual void UpdateWorldData();
    virtual void UpdateTransformAndBounds();
    virtual void PreAttachUpdate();
    virtual void CompleteAttachUpdate();
    virtual void OnVisible();
    virtual void UpdateWorldTransform();
    virtual void UpdateEffects();
    virtual void CalculateWorldBound();
    virtual void PropagateControllers();
    virtual void GetWorldTransform();
    virtual void GetLocalTransform();
    virtual void AttachChildInAvailableSlot(WorldObject* child);
};
struct WorldPointer : public GO
{
    WorldObject* object;
    WorldPointer(WorldObject* object = 0);
    ~WorldPointer();
};
struct QueryQueue
{
    bool FUN_006c62d0(int key, WorldPointer* result);
    void RemoveKey(int key);
};
struct RenderTask
{
    void UpdateChildByKey(int key);
};
// @fnv 0x006a5bb0
void RenderTask::UpdateChildByKey(int key)
{
    WorldPointer child(0);
    if (reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)->FUN_006c62d0(key, &child))
    {
        reinterpret_cast<WorldObject*>(static_cast<unsigned int>(g_011d6e5c))
            ->AttachChildInAvailableSlot(reinterpret_cast<WorldObject*>(static_cast<unsigned int>(child)));
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(g_011d6e5c))->Update(updateData);
        reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(g_011d6e5c))->UpdateSceneObject();
        reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)->RemoveKey(key);
    }
}

struct NavTriStub
{
    unsigned short ObjCount();
    bool Flag(unsigned int);
    bool Check3b70();
    bool Check0e70();
    bool Check5ec0();
    bool Check3b90();
};

struct NavRenderStub
{
    int GetNavTriColor(NavTriStub* pTri);
};

// Returns a color code chosen from the triangle's object count and its flags/checks, defaulting to 0.
// @fnv 0x006a5da0
int NavRenderStub::GetNavTriColor(NavTriStub* pNavTri)
{
    int iColorCode = 0;
    if (pNavTri->ObjCount() > 0)
    {
        if (pNavTri->Flag(0x100))
        {
            iColorCode = 12;
        }
        else
        {
            iColorCode = 11;
        }
    }
    else if (pNavTri->Check3b70())
    {
        if (pNavTri->Check0e70())
        {
            iColorCode = 5;
        }
        else if (pNavTri->Check5ec0())
        {
            iColorCode = 8;
        }
        else
        {
            iColorCode = 13;
        }
    }
    else if (pNavTri->Check5ec0())
    {
        iColorCode = 7;
    }
    else if (pNavTri->Check3b90())
    {
        iColorCode = 14;
    }
    else if (pNavTri->Check0e70())
    {
        iColorCode = 4;
    }
    else if (pNavTri->Flag(0x1000))
    {
        iColorCode = 9;
    }
    else if (pNavTri->Flag(0x80000000))
    {
        iColorCode = 16;
    }
    return iColorCode;
}

// fallout_shared/pathfinding/navmeshobstacletask.cpp: ObstacleTaskData, BSTaskletData, DelStandIn, ObstacleTaskShell (15 functions)

#include "navmeshobstacletask_decls.h"
// Validates the operation against existing entries by type, then appends it to Operations if the navmesh is available.
// @fnv 0x006c7a30
bool ObstacleTaskData::AddOperation(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type)
{
    switch (type)
    {
    case REMOVE:
    case REMOVE_UPDATE: {
        bool bCanAdd = true;
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == ADD)
                {
                    reinterpret_cast<void(__cdecl*)(const char*, ...)>(&Interface::PrintDebugMessage)(
                        "Removing previous operation ADD for Task on Navmesh 0x%08x (srcptr = 0x%08x)", pInfo->id,
                        m_spSourceNavMesh.ptr);
                    Operations.Remove(i, true);
                    --i;
                }
                else
                    bCanAdd = false;
            }
        }
        if (!bCanAdd)
            return false;
        break;
    }
    case ADD:
    case ADD_UPDATE: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == ADD)
                    return false;
            }
        }
        break;
    }
    case ADD_DOOR: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if (OPERATION_AT(Operations, i).eType == ADD_DOOR)
                    return false;
            }
        }
        break;
    }
    case REMOVE_DOOR: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if (OPERATION_AT(Operations, i).eType == REMOVE_DOOR)
                    return false;
            }
        }
        break;
    }
    default:
        return false;
    }
    NavMeshPtr navMesh;
    if (pInfo->ResolveNavMesh(navMesh))
    {
        Operations.AppendValue(ObstacleTask(obstacle, type, navMesh));
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x006c8170
void ObstacleTaskData::Process()
{
    AutoMemContext context(MEM_CONTEXT_NAVMESH, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleTask.c",
                           357);
    NavMeshObstacleManager::GetSingleton()->GetCharPtrAtOffset()->FUN_00483710();
    if (pInfo->ResolveNavMesh(m_spSourceNavMesh))
    {
        m_spWorkingNavMesh = reinterpret_cast<NavMeshPtr(__cdecl*)(NavMesh*)>(&MakeNavMeshPointer)(new NavMesh);
        NAVMESH_FROM(m_spSourceNavMesh)->CopyNavMeshDataTo(m_spWorkingNavMesh);
        FUN_006c8150();
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            switch (OPERATION_AT(Operations, i).eType)
            {
            case ADD:
            case ADD_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->Search(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case REMOVE:
            case REMOVE_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveObstacleAndUpdateLinks(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case REMOVE_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case ADD_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->AddDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id,
                                          OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            }
        }
        for (unsigned int i = 0; i < m_kParentChildLinks.parents.GetSize(); ++i)
            EDGE_AT(m_kParentChildLinks.parents, i).pInfo = pInfo;
        for (unsigned int i = 0; i < m_kParentChildLinks.children.GetSize(); ++i)
            EDGE_AT(m_kParentChildLinks.children, i).pInfo = pInfo;
    }
    else
    {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
            OPERATION_AT(Operations, i).m_kResult = 1;
    }
    NavMeshObstacleManager::GetSingleton()->AddProcessedTask(this);
    NavMeshObstacleManager::GetSingleton()->GetCharPtrAtOffset()->FUN_00483710();
}

struct BaseT
{
    virtual ~BaseT();
    int b[6];
};
struct M34
{
    int x[4];
    ~M34();
};
struct M24
{
    int x[2];
    ~M24();
};
struct FUN_006c79a0 : public BaseT
{
    NavMeshPtr a;
    NavMeshPtr b2;
    M24 c;
    int pad[2];
    M34 d;
    virtual ~FUN_006c79a0();
};
// Destructor for a structure holding two NavMeshPtr members and two small sub-objects; the body is empty.
// @fnv 0x006c79a0
FUN_006c79a0::~FUN_006c79a0()
{}

struct NiNodeHolder
{
    NiNode* p;
    ~NiNodeHolder();
};
struct FUN_006c7e00
{
    NiNodeHolder node;
    int pad[2];
    NavMeshPtr mesh;
    ~FUN_006c7e00();
};
// @fnv 0x006c7e00
FUN_006c7e00::~FUN_006c7e00()
{}

struct FUN_006c8150_shell : public ObstacleTaskData
{
    void FUN_006c8150();
};

void __cdecl CompareObstacleEntries();

struct Helper_006c8980
{
    void FUN_006c8980(void(__cdecl*)());
};

// @fnv 0x006c8150
void FUN_006c8150_shell::FUN_006c8150()
{
    ((Helper_006c8980*)((char*)this + 0x24))->FUN_006c8980(CompareObstacleEntries);
}

struct Elem16
{
    int a[4];
    void AssignFrom(int v);
};
struct Arr16
{
    int pad;
    Elem16* data;
    unsigned int FUN_006f31f0();
    void InitializeArray(Elem16* e, int f);
    unsigned int AppendValue(int value);
};
// Appends a new element at the end of the array, initializes it with the given value, and returns its index.
// @fnv 0x006c8810
unsigned int Arr16::AppendValue(int value)
{
    unsigned int index = FUN_006f31f0();
    InitializeArray(&data[index], 1);
    data[index].AssignFrom(value);
    return index;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_006c7970(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006c7970
void* DelStandIn::FUN_006c7970(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

void __cdecl operator delete(void*);

struct BSTaskletData
{
    virtual ~BSTaskletData();
    void* DestroyIfFlagged(unsigned int);
    void FUN_006c78f0();
};

void BSTaskletData::FUN_006c78f0()
{}

// Calls FUN_006c78f0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006c7910
void* BSTaskletData::DestroyIfFlagged(unsigned int flags)
{
    FUN_006c78f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_006c7940 {
struct BaseT
{
    virtual ~BaseT();
};
struct FUN_006c7940_shell : BaseT
{
    void* FUN_006c7940(unsigned int flags);
};
// Runs the base destructor, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x006c7940
void* FUN_006c7940_shell::FUN_006c7940(unsigned int flags)
{
    BaseT::~BaseT();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_006c7940

struct FUN_006c85c0_shell
{
    char* GetCharPtrAtOffset();
};

// @fnv 0x006c85c0
char* FUN_006c85c0_shell::GetCharPtrAtOffset()
{
    return reinterpret_cast<char*>(this) + 0x1A1;
}

extern int DAT_0106c8d4;
struct S_006c87c0
{
    int FUN_006c8c70(int, int);
    S_006c87c0* FUN_006c87c0();
};
// Sets the object's vtable pointer to DAT_0106c8d4, calls FUN_006c8c70(0, 0), and returns this.
// @fnv 0x006c87c0
S_006c87c0* S_006c87c0::FUN_006c87c0()
{
    *(int*)this = (int)&DAT_0106c8d4;
    FUN_006c8c70(0, 0);
    return this;
}

extern int DAT_0106c8d4;
struct FUN_006c87f0_shell
{
    void* vftable;
    void __thiscall FUN_006c8a30(int a);
    void __thiscall FUN_006c87f0();
};
// @fnv 0x006c87f0
void __thiscall FUN_006c87f0_shell::FUN_006c87f0()
{
    vftable = &DAT_0106c8d4;
    FUN_006c8a30(1);
}

struct ObstacleMeshView
{
    int FindEntryIndex(const ObstacleTask* op);
};

struct ObstacleMeshRef
{
    ObstacleMeshView* ptr;
    ObstacleMeshRef(const NavMeshPtr& other);
    ~ObstacleMeshRef();
    ObstacleMeshView* Get();
    ObstacleMeshView* operator->() const;
};

// @fnv 0x006c7e60
int __cdecl CompareObstacleEntries(const void* apEntryA, const void* apEntryB)
{
    const ObstacleTask* a = (const ObstacleTask*)apEntryA;
    const ObstacleTask* b = (const ObstacleTask*)apEntryB;
    switch (a->eType)
    {
    case REMOVE_DOOR:
        if (b->eType == REMOVE_DOOR)
            return 0;
        else
            return -1;
        break;
    case ADD_DOOR:
        if (b->eType == ADD_DOOR)
            return 0;
        else
            return 1;
        break;
    case ADD:
    case ADD_UPDATE:
        switch (b->eType)
        {
        case REMOVE_DOOR:
            return 1;
            break;
        case ADD_DOOR:
            return -1;
            break;
        case ADD:
        case ADD_UPDATE:
            return a->m_spRegisteredObstacle->source->id - b->m_spRegisteredObstacle->source->id;
            break;
        case REMOVE:
        case REMOVE_UPDATE:
            return 1;
            break;
        }
        break;
    case REMOVE:
    case REMOVE_UPDATE:
        switch (b->eType)
        {
        case REMOVE_DOOR:
            return 1;
            break;
        case ADD_DOOR:
            return -1;
            break;
        case ADD:
        case ADD_UPDATE:
            return -1;
            break;
        case REMOVE:
        case REMOVE_UPDATE: {
            ObstacleMeshRef mesh(a->apSearchNavMesh);
            if (mesh.Get())
            {
                int ia = mesh->FindEntryIndex(a);
                int ib = mesh->FindEntryIndex(b);
                return ib - ia;
            }
            else
            {
                return 0;
            }
        }
        }
        break;
    }
    return 0;
}

struct Element16
{
    int a;
    int b;
    int c;
    int d;
};
class FUN_006c8860_Class
{
  public:
    virtual void v0();
    virtual Element16* Allocate(unsigned int);
    Element16* data;
    unsigned int size;
    unsigned int capacity;
    bool FUN_006f3170();
    unsigned int FUN_00869600();
    void FUN_006c8bd0(Element16*, const Element16*, unsigned int);
    void FUN_006c8b90(Element16*, unsigned int);
    void FUN_006a8500();
    void RemoveAt(unsigned int index, bool shrink);
};
// Removes the element at index, optionally reallocating a smaller buffer first, then shifts the remaining elements down and decrements size.
// @fnv 0x006c8860
void FUN_006c8860_Class::RemoveAt(unsigned int index, bool shrink)
{
    if (shrink && FUN_006f3170())
    {
        unsigned int uiNewCapacity = FUN_00869600();
        Element16* pNewData = Allocate(uiNewCapacity);
        FUN_006c8bd0(pNewData, data, index);
        FUN_006c8b90(data + index, 1);
        FUN_006c8bd0(pNewData + index, data + index + 1, size - 1);
        FUN_006a8500();
        data = pNewData;
        capacity = uiNewCapacity;
    }
    else
    {
        FUN_006c8b90(data + index, 1);
        FUN_006c8bd0(data + index, data + index + 1, size - index - 1);
    }
    size = size - 1;
}

struct ObstacleMesh;
struct ObstacleMeshHandle
{
    ObstacleMesh* ptr;
    ObstacleMeshHandle(const ObstacleMeshHandle&);
    ~ObstacleMeshHandle();
    operator ObstacleMesh*() const;
    ObstacleMesh* Get();
};
struct ObstacleCellChild
{
    void FUN_00469500(ObstacleMeshHandle);
    void FUN_0069bb00(ObstacleMeshHandle);
};
struct ObstacleCell
{
    ObstacleCellChild* FUN_0070ec90();
};
struct ObstacleMesh
{
    unsigned int GetFormID();
    ObstacleCell* GetParentCell();
    void ForceSetFormID(unsigned int);
    void FUN_006d3100(NavMeshInfo*);
};
struct ObstacleOperation
{
    int unk00;
    int unk04;
    unsigned int m_kResult;
};
struct ObstacleOperationArray
{
    unsigned int GetSize();
    ObstacleOperation* GetAt(unsigned int);
};
struct ObstacleInfo
{
    void SetField54(ObstacleMesh*);
};
struct ObstacleTaskShell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ObstacleInfo* pInfo;
    ObstacleMeshHandle m_spSourceNavMesh;
    ObstacleMeshHandle m_spWorkingNavMesh;
    ObstacleOperationArray Operations;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    bool bForce;
    bool ReplaceNavMesh();
};

// @fnv 0x006c85e0
bool ObstacleTaskShell::ReplaceNavMesh()
{
    if (!(ObstacleMesh*)m_spSourceNavMesh)
        return false;
    if (!(ObstacleMesh*)m_spWorkingNavMesh)
        return false;
    bool bFound = false;
    if (!bForce)
    {
        for (unsigned int i = 0; i < Operations.GetSize(); i++)
        {
            if (Operations.GetAt(i)->m_kResult == 0)
            {
                bFound = true;
                break;
            }
        }
    }
    else
    {
        bFound = true;
    }
    if (bFound)
    {
        unsigned int formID = ((ObstacleMesh*)m_spSourceNavMesh)->GetFormID();
        ObstacleCell* pCell = ((ObstacleMesh*)m_spSourceNavMesh)->GetParentCell();
        if (pCell)
        {
            pCell->FUN_0070ec90()->FUN_00469500(m_spWorkingNavMesh);
            pCell->FUN_0070ec90()->FUN_0069bb00(m_spSourceNavMesh);
        }
        ((ObstacleMesh*)m_spSourceNavMesh)->ForceSetFormID(0);
        ((ObstacleMesh*)m_spSourceNavMesh)->FUN_006d3100(0);
        ((ObstacleMesh*)m_spWorkingNavMesh)->ForceSetFormID(formID);
        ((ObstacleMesh*)m_spWorkingNavMesh)->FUN_006d3100((NavMeshInfo*)pInfo);
        pInfo->SetField54(m_spWorkingNavMesh.Get());
        return true;
    }
    else
    {
        return false;
    }
}

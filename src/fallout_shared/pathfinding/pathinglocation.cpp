// fallout_shared/pathfinding/pathinglocation.cpp: PathingLocation, PathingLocationProxy, PathingLocationArray, StandInShell and more (34 functions)

#include "pathinglocation_decls.h"

// @fnv 0x004ff7e0
bool PathingLocation::HasValidTriangle()
{
    m_ppVirtualMethodTable = (void**)0x0102583c;
    __assume(0);
}

// @fnv 0x006dce10
PathingLocation::PathingLocation(const NiPoint3& location, TESObjectREFR* reference)
{
    m_ppVirtualMethodTable = (void**)0x0102583c;
    reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(&Location)->GetItem();
    SetLocationData(location, reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(reference)->GetTarget()),
                    reference->GetParentWorldSpace());
}

static const int kClearTriangleDataValue1 = 65535;

// @fnv 0x006ddbe0
void PathingLocation::ResetLocation()
{
    m_usTriangleID = kClearTriangleDataValue1;
}

// Copies Location, the Id fields, pCell and uiFlags from other into this PathingLocation and returns *this.
// @fnv 0x006dcce0
PathingLocation& PathingLocation::operator=(const PathingLocation& other)
{
    Location = other.Location;
    m_pLocationNavMesh = other.m_pLocationNavMesh;
    pNavMeshInfoArray = other.pNavMeshInfoArray;
    pCell = other.pCell;
    m_pContainingWorldspace = other.m_pContainingWorldspace;
    m_uiPathingFlags = other.m_uiPathingFlags;
    m_usTriangleID = other.m_usTriangleID;
    uiFlags = other.uiFlags;
    return *this;
}

// @fnv 0x006dd4f0
TESObjectCELL* PathingLocation::GetContainingCell()
{
    if (pCell)
        return pCell;
    else if (m_pContainingWorldspace)
    {
        TESObjectCELL* cell = m_pContainingWorldspace->GetCellByKey(m_uiPathingFlags);
        if (cell)
            return cell;
    }
    return 0;
}

// @fnv 0x006dd610
bool PathingLocation::ResolveNavMesh(NavMeshPtr& navMesh)
{
    if (m_pLocationNavMesh)
        return const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh);
    else
        return false;
}

// If a NavMeshInfo is set and its triangle index is valid, checks it against navMesh, writes the triangle index to triangle and returns true.
// @fnv 0x006dd640
bool PathingLocation::FindNavMeshTriangle(NavMeshPtr& navMesh, unsigned short& triangle)
{
    if (m_pLocationNavMesh)
    {
        if (m_usTriangleID == 0xFFFF)
            return false;
        if (!const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh))
            return false;
        triangle = m_usTriangleID;
        return true;
    }
    else
        return false;
}

// @fnv 0x006dd540
const NavMeshInfo* PathingLocationProxy::GetAssociatedNavMesh()
{
    if (m_pLocationNavMesh)
        return m_pLocationNavMesh;
    else if (!pNavMeshInfoArray)
        return 0;
    else if (IsPathingLocationFlagSet())
        return (const NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(0);
    else
        return 0;
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
// Placement-constructs count PathingLocation objects in the items array.
// @fnv 0x006d00a0
void PathingLocationArray::ConstructItems(PathingLocation* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
        new (items + i) PathingLocation;
}

// Reads a PathingLocation from a load-game buffer: location, navmesh id, cell/worldspace, flags and optional mesh data.
// @fnv 0x006df010
void PathingLocation::LoadGame(BGSLoadGameBuffer* buffer)
{
    buffer->ReadDataBlock(&Location, 12);
    unsigned int navMeshID = 0;
    ((BGSLoadFormBuffer*)buffer)->ReadFormIdentifier(&navMeshID);
    m_pLocationNavMesh = g_TES->GetActiveCell(navMeshID)->FindReferenceByFormId();
    pCell = dynamic_cast<TESObjectCELL*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
    m_pContainingWorldspace = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
    buffer->ReadDataBlock(&m_uiPathingFlags, 4);
    buffer->ReadDataBlock(&m_usTriangleID, 2);
    m_usTriangleID = kClearTriangleDataValue1;
    buffer->ReadDataBlock(&uiFlags, 1);
    bool hasMeshes = false;
    buffer->ReadDataBlock(&hasMeshes, 1);
    if (hasMeshes)
    {
        if (m_pContainingWorldspace)
            pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
        else if (pCell)
            pNavMeshInfoArray = FUN_006d6f40(pCell);
    }
}

// Checks whether the location is reachable via its nav mesh or mesh array, pruning invalid meshes and updating reachability state.
// @fnv 0x006de250
bool PathingLocation::HasPathingLocation()
{
    if (FUN_006a9520())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (m_pLocationNavMesh->FUN_0068f320())
            return false;
        else
            return true;
    }
    else
    {
        PathBuilderDetailedPathInfos meshes;
        ((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->CopyTo(&meshes);
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize(); ++i)
        {
            struct
            {
                NavMeshBounds* bounds;
                NavMeshInfo* info;
            } meshEntry;
            meshEntry.info = (NavMeshInfo*)((NiFormArray*)&meshes)->FUN_00877a30(i);
            meshEntry.bounds = (NavMeshBounds*)((LowProcess*)meshEntry.info)->GetPackageObjectType();
            if (meshEntry.bounds)
            {
                if (meshEntry.bounds->ContainsPoint(Location))
                {
                    ((BSSimpleArray<unsigned short, 1024>*)&meshes)->Clear(false);
                    ((BSSimpleArray<NavMeshInfo*, 1024>*)&meshes)->Add(meshEntry.info);
                    break;
                }
                else
                {
                    ((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)->UpdateEntryValue(i, 1);
                    --i;
                }
            }
            else
            {
                NavMeshPtr mesh;
                if (meshEntry.info->ResolveNavMesh(mesh) && ((NiPointer<NiNode>*)&mesh)->operator->()->IsDeleted())
                {
                    ((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)->UpdateEntryValue(i, 1);
                    --i;
                }
            }
        }
        if (((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize() == 1)
        {
            m_pLocationNavMesh = meshes.GetFirstForm();
            pNavMeshInfoArray = 0;
            SetAllMeshesReachable(true);
            return true;
        }
        else
        {
            SetAllMeshesReachable(GetAllMeshesReachable());
            return IsPathingLocationFlagSet();
        }
    }
}

// @fnv 0x006dd6f0
bool PathingLocationProxy::FindContainingTriangle(FindTriangleForLocationFilter* filter)
{
    if (FUN_006a9520())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (m_pLocationNavMesh->FUN_0068f320())
            return false;
        if (m_usTriangleID == 0xffff)
        {
            NavMeshPtr mesh;
            if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                m_usTriangleID =
                    ((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())->FindTriangleForLocation(Location, filter);
        }
        return true;
    }
    else if (GetContainingCell() && GetContainingCell()->IsOutdoorCell())
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            NavMeshPtr mesh;
            if (((NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(i))
                    ->ResolveNavMesh(mesh) &&
                !((NiPointer<NiNode>*)&mesh)->operator->()->GetDisabled())
            {
                unsigned short triangle =
                    ((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())->FindTriangleForLocation(Location, filter);
                if (triangle != 0xffff)
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(i);
                    pNavMeshInfoArray = 0;
                    m_usTriangleID = triangle;
                    SetAllMeshesReachable(true);
                    return true;
                }
            }
        }
        NiPoint3 savedLocation = Location;
        bool resolved = IsPathingLocationValid();
        m_usTriangleID = kClearTriangleDataValue1;
        Location = savedLocation;
        if (resolved)
            SetAllMeshesReachable(true);
        else
            SetAllMeshesReachable(IsPathingLocationFlagSet());
        return resolved;
    }
    else
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(i);
            if (!info->FUN_0068f320())
            {
                NavMeshBounds* bounds = (NavMeshBounds*)((LowProcess*)info)->GetPackageObjectType();
                if (bounds && bounds->ContainsPoint(Location))
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(i);
                    pNavMeshInfoArray = 0;
                    NavMeshPtr mesh;
                    if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                        m_usTriangleID = ((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())
                                             ->FindTriangleForLocation(Location, filter);
                    SetAllMeshesReachable(true);
                    return true;
                }
            }
        }
        struct
        {
            int noBoundsIndex;
            float minimumDistance;
            int closestIndex;
        } nearest;
        nearest.noBoundsIndex = -1;
        nearest.minimumDistance = 3.402823466e+38F;
        nearest.closestIndex = -1;
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(i);
            if (!info->FUN_0068f320())
            {
                NavMeshBounds* bounds = (NavMeshBounds*)((LowProcess*)info)->GetPackageObjectType();
                if (bounds)
                {
                    NiPoint3 delta = bounds->FUN_0069c070(Location);
                    float distance = delta.FUN_004a7290();
                    if (distance < nearest.minimumDistance)
                    {
                        nearest.minimumDistance = distance;
                        nearest.closestIndex = i;
                    }
                }
                else
                    nearest.noBoundsIndex = i;
            }
        }
        if (nearest.minimumDistance < DAT_0106cd60)
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(nearest.closestIndex);
            pNavMeshInfoArray = 0;
            m_usTriangleID = kClearTriangleDataValue1;
            SetAllMeshesReachable(true);
            return true;
        }
        else
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(nearest.noBoundsIndex);
            pNavMeshInfoArray = 0;
            SetAllMeshesReachable(GetAllMeshesReachable());
            return IsPathingLocationFlagSet();
        }
    }
}

struct FUN_006dcfe0_shell : public PathingLocation
{
    void FUN_006dcfe0(int);
};

// Clears bit 0 of the byte at offset 0x26 and sets it to the low bit of aiVal.
// @fnv 0x006dcfe0
void FUN_006dcfe0_shell::FUN_006dcfe0(int aiVal)
{
    *((unsigned char*)this + 0x26) &= ~1;
    *((unsigned char*)this + 0x26) |= aiVal;
}

// @fnv 0x006dd5a0
int __fastcall IsPathingLocationFlagSet(PathingLocation* pThis)
{
    return *((unsigned char*)pThis + 0x26) & 1;
}

// @fnv 0x006df160
TESForm*& __fastcall GetFirstForm(NiFormArray* pThis)
{
    return pThis->FUN_00877a30(0);
}

extern int DAT_0102583c;

struct StandIn6815c0
{
    void _ref_006815c0();
};

struct Point3_12
{
    int a, b, c;
};

struct StandInShell
{
    StandInShell* FUN_006dcc40(void* other);
};

// @fnv 0x006dcc40
StandInShell* StandInShell::FUN_006dcc40(void* other)
{
    *(int*)this = (int)&DAT_0102583c;
    ((StandIn6815c0*)((char*)this + 4))->_ref_006815c0();
    *(Point3_12*)((char*)this + 4) = *(Point3_12*)((char*)other + 4);
    *(int*)((char*)this + 0x10) = *(int*)((char*)other + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)other + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)((char*)other + 0x18);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)other + 0x1c);
    *(int*)((char*)this + 0x20) = *(int*)((char*)other + 0x20);
    *(short*)((char*)this + 0x24) = *(short*)((char*)other + 0x24);
    *(char*)((char*)this + 0x26) = *(char*)((char*)other + 0x26);
    return this;
}

namespace fnv_006dcf20 {
extern int DAT_0102583c;
struct PtrLoc
{
    const NiPoint3* p;
};
struct PtrNav
{
    const NavMeshInfo* p;
};
void __fastcall FUN_006815c0(NiPoint3*);
TESWorldSpace* __fastcall FUN_00690800(const NavMeshInfo*);
TESObjectCELL* __fastcall FUN_006b77b0(const NavMeshInfo*);
struct FUN_006dcfe0_shell : public PathingLocation
{
    void FUN_006dcfe0(int);
};

// Initialises a PathingLocation from a point and navmesh info: sets vtable, location, flags, worldspace/cell and clears triangle data.
// @fnv 0x006dcf20
PathingLocation* __fastcall FUN_006dcf20(PathingLocation* self, PtrLoc aLocation, PtrNav apNavMeshInfo)
{
    self->m_ppVirtualMethodTable = (void**)&DAT_0102583c;
    FUN_006815c0(&self->Location);
    self->Location = *aLocation.p;
    self->uiFlags = 0;
    self->m_pLocationNavMesh = apNavMeshInfo.p;
    self->pNavMeshInfoArray = 0;
    self->m_pContainingWorldspace = FUN_00690800(apNavMeshInfo.p);
    if (self->m_pContainingWorldspace)
    {
        self->pCell = 0;
        self->m_uiPathingFlags = *(unsigned int*)((const char*)apNavMeshInfo.p + 0xc);
    }
    else
    {
        self->pCell = FUN_006b77b0(apNavMeshInfo.p);
        self->m_uiPathingFlags = 0xdeaddead;
    }
    ((FUN_006dcfe0_shell*)self)->FUN_006dcfe0(1);
    self->m_usTriangleID = kClearTriangleDataValue1;
    return self;
}
}  // namespace fnv_006dcf20

extern int DAT_0102583c;
void __fastcall _ref_006815c0(void*);
struct FUN_006dce60_shell : PathingLocation
{
    PathingLocation* FUN_006dce60(NiPoint3 const&, TESObjectCELL*);
};
// @fnv 0x006dce60
PathingLocation* FUN_006dce60_shell::FUN_006dce60(NiPoint3 const& a, TESObjectCELL* b)
{
    m_ppVirtualMethodTable = (void**)&DAT_0102583c;
    _ref_006815c0(&Location);
    SetLocationData(a, b, 0);
    return this;
}

struct FUN_006dd4d0_shell
{
    char _pad[0x24];
    unsigned short m_0x24;
    void SetField(unsigned short value);
};

// @fnv 0x006dd4d0
void FUN_006dd4d0_shell::SetField(unsigned short value)
{
    m_0x24 = value;
}

struct FUN_006dd5c0_Cls
{
    char _pad[16];
    void* f10;
    BSSimpleArray<unsigned int, 1024>* f14;
    bool FUN_006dd5c0(BSSimpleArray<void*, 1024>* arr);
};
// Appends f10 to arr if set, otherwise copies f14 into arr; returns whether either source was available.
// @fnv 0x006dd5c0
bool FUN_006dd5c0_Cls::FUN_006dd5c0(BSSimpleArray<void*, 1024>* arr)
{
    if (f10)
    {
        arr->Add(f10);
        return true;
    }
    else
    {
        if (f14)
        {
            f14->CopyTo((BSSimpleArray<unsigned int, 1024>*)arr);
            return true;
        }
        else
        {
            return false;
        }
    }
}

extern int DAT_0102583c;
class TESObjectREFR;
struct _ref_006815c0_t
{
    void _ref_006815c0();
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct SandboxProcedureData
{
    TESObjectREFR* GetTarget();
};
struct SetupData_t
{
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
};
struct FUN_006dd0d0
{
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const void* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    FUN_006dd0d0(const NiPoint3* aLocation, PathingLocation* aHintLoc);
};
// Initializes a pathing location from a point, using the hint location's navmesh triangle if found, otherwise setting up from the point and cell/worldspace.
// @fnv 0x006dd0d0
FUN_006dd0d0::FUN_006dd0d0(const NiPoint3* aLocation, PathingLocation* aHintLoc)
{
    m_ppVirtualMethodTable = (void**)&DAT_0102583c;
    ((_ref_006815c0_t*)&Location)->_ref_006815c0();
    Location = *aLocation;
    uiFlags = 0;
    m_usTriangleID = kClearTriangleDataValue1;
    NavMeshPtr pFoundNavMesh;
    if (aHintLoc->ResolveNavMesh(pFoundNavMesh))
    {
        m_usTriangleID =
            ((NavMesh*)((SandboxProcedureData*)&pFoundNavMesh)->GetTarget())->FindTriangleForLocation(*aLocation, 0);
        if (m_usTriangleID != kClearTriangleDataValue1)
        {
            m_pLocationNavMesh = aHintLoc->m_pLocationNavMesh;
            pNavMeshInfoArray = 0;
            pCell = aHintLoc->pCell;
            m_pContainingWorldspace = aHintLoc->m_pContainingWorldspace;
            m_uiPathingFlags = aHintLoc->m_uiPathingFlags;
            return;
        }
    }
    ((SetupData_t*)this)
        ->SetLocationData((void*)aLocation, aHintLoc->GetContainingCell(),
                          (TESWorldSpace*)((BGSTerrainManager*)aHintLoc)->GetMinLevel());
}

struct NavMeshInfoStandIn : NavMeshInfo
{
    TESWorldSpace* GetParentWorldSpace();
    TESObjectCELL* GetInteriorCell();
    unsigned int GetCellKey();
};

struct FUN_006dd3e0_shell : PathingLocation
{
    void SetAllMeshesReachable(bool);
    void FUN_006dd3e0(const NavMeshInfo* mesh);
};

// @fnv 0x006dd3e0
void FUN_006dd3e0_shell::FUN_006dd3e0(const NavMeshInfo* mesh)
{
    pNavMeshInfoArray = 0;
    m_pLocationNavMesh = mesh;
    m_pContainingWorldspace = ((NavMeshInfoStandIn*)mesh)->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = *(unsigned int*)((char*)mesh + 0xc);
    }
    else
    {
        pCell = ((NavMeshInfoStandIn*)mesh)->GetInteriorCell();
        m_uiPathingFlags = 0xdeaddead;
    }
    SetAllMeshesReachable(true);
    m_usTriangleID = 65535;
}

struct WsH
{
    static int __cdecl GetKeyForWorldCoord(const NiPoint3&);
};
struct PathingLocationSetup
{
    void SetLocationData(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
};
struct FUN_006dd460 : PathingLocation
{
    void FUN_006dd460_1(const NiPoint3& pos);
};
// @fnv 0x006dd460
void FUN_006dd460::FUN_006dd460_1(const NiPoint3& pos)
{
    Location = pos;
    m_usTriangleID = 65535;
    if (m_pContainingWorldspace)
    {
        int key = WsH::GetKeyForWorldCoord(Location);
        if (key != m_uiPathingFlags)
            SetLocationData(pos, 0, m_pContainingWorldspace);
    }
}

namespace fnv_006def40 {
class TESObjectREFR;

struct SandboxProcedureData
{
    TESObjectREFR* GetTarget();
};

struct FUN_00865db0_shell
{
    void FUN_00865db0(unsigned int, unsigned int);
};

struct SaveFormIDHelper : public FUN_00865db0_shell
{
    void SerializeFormData(void*, int);
};

struct BGSSaveFormBuffer : public SaveFormIDHelper
{
    void SaveData(void*, int, int);
};

struct FUN_006def40_shell
{
    unsigned char pad0[4];
    unsigned char data[12];
    SandboxProcedureData* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;

    void SaveGame(BGSSaveFormBuffer*);
};

// @fnv 0x006def40
void FUN_006def40_shell::SaveGame(BGSSaveFormBuffer* buffer)
{
    bool bhadNavMeshesArray;

    buffer->SaveData(data, 12, 0);
    buffer->FUN_00865db0(reinterpret_cast<unsigned int>(m_pLocationNavMesh ? m_pLocationNavMesh->GetTarget() : 0), 0);
    buffer->SerializeFormData(pCell, 0);
    buffer->SerializeFormData(m_pContainingWorldspace, 0);
    buffer->SaveData(&data[0x1c], 4, 0);
    buffer->SaveData(&data[0x20], 2, 0);
    buffer->SaveData(&data[0x22], 1, 0);

    bhadNavMeshesArray = pNavMeshInfoArray;
    buffer->SaveData(&bhadNavMeshesArray, 1, 0);
}
}  // namespace fnv_006def40

struct PathingCellAccess : TESObjectCELL
{
    bool FUN_00425fd0();
    TESWorldSpace* FUN_0054ddd0();
    int FUN_00544c60();
    int FUN_00544c30();
};
unsigned int FUN_00587440(const NiPoint3&);
unsigned int PackShortPair(int, int);
const BSSimpleArray<NavMeshInfo_const*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);
const BSSimpleArray<NavMeshInfo_const*, 1024>* FUN_006d6f40(TESObjectCELL*);
struct SetupPathingLocation : PathingLocation
{
    void FUN_006dd280(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
};
// Stores the position, resolves the nav-mesh array from the world or cell, marks all meshes reachable when exactly one mesh exists, and sets flags.
// @fnv 0x006dd280
void SetupPathingLocation::FUN_006dd280(const NiPoint3& position, TESObjectCELL* cell, TESWorldSpace* world)
{
    Location = position;
    uiFlags = 0;
    if (world)
    {
        m_pContainingWorldspace = world;
        m_uiPathingFlags = FUN_00587440(Location);
        pCell = 0;
        pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
    }
    else
    {
        pNavMeshInfoArray = FUN_006d6f40(cell);
        if (cell && !static_cast<PathingCellAccess*>(cell)->FUN_00425fd0())
        {
            m_pContainingWorldspace = static_cast<PathingCellAccess*>(cell)->FUN_0054ddd0();
            m_uiPathingFlags = PackShortPair(static_cast<PathingCellAccess*>(cell)->FUN_00544c30(),
                                             static_cast<PathingCellAccess*>(cell)->FUN_00544c60());
            pCell = 0;
        }
        else
        {
            pCell = cell;
            m_pContainingWorldspace = 0;
            m_uiPathingFlags = 0xDEADDEAD;
        }
    }
    if (pNavMeshInfoArray && const_cast<BSSimpleArray<NavMeshInfo_const*, 1024>*>(pNavMeshInfoArray)->GetSize() == 1)
    {
        SetAllMeshesReachable(true);
        m_pLocationNavMesh = reinterpret_cast<const NavMeshInfo*>(
            const_cast<BSSimpleArray<NavMeshInfo_const*, 1024>*>(pNavMeshInfoArray)->GetAt(0));
        pNavMeshInfoArray = 0;
    }
    else
    {
        SetAllMeshesReachable(false);
        m_pLocationNavMesh = 0;
    }
    m_usTriangleID = 0xFFFF;
}

struct NiPointOps : NiPoint3
{
    NiPoint3 Sub(const NiPoint3& rhs) const;
};

struct FUN_006deeb0_cls : PathingLocation
{
    bool IsWithinDistanceOfSameLocation(const PathingLocation* other, float dist);
};

// @fnv 0x006deeb0
bool FUN_006deeb0_cls::IsWithinDistanceOfSameLocation(const PathingLocation* other, float dist)
{
    if (other->m_pContainingWorldspace != m_pContainingWorldspace)
    {
        return false;
    }
    if (m_pContainingWorldspace != 0)
    {
        if (other->m_uiPathingFlags != m_uiPathingFlags)
        {
            return false;
        }
    }
    else
    {
        if (other->pCell != pCell)
        {
            return false;
        }
    }
    if (static_cast<const NiPointOps&>(other->Location).Sub(Location).FUN_004a7290() > dist * dist)
    {
        return false;
    }
    return true;
}

struct FUN_006dcf20
{
    void** vtable;
    NiPoint3 location;
    const NavMeshInfo* navMesh;
    const BSSimpleArray<NavMeshInfo_const*, 1024>* navMeshes;
    TESObjectCELL* cell;
    TESWorldSpace* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    unsigned char reserved;
    FUN_006dcf20(const NiPoint3& position, TESObjectREFR* reference);
    ~FUN_006dcf20();
};
struct PathingLocationOwner
{
    void FUN_006ed7a0(FUN_006dcf20* location);
    void FUN_006ed730(const NiPoint3& position, TESObjectREFR* reference);
};
// Constructs a pathing location from a position and reference, then passes it to the owner's location setter.
// @fnv 0x006ed730
void PathingLocationOwner::FUN_006ed730(const NiPoint3& position, TESObjectREFR* reference)
{
    FUN_006dcf20 location(position, reference);
    FUN_006ed7a0(&location);
}

struct FUN_006dcbb0 : public PathingLocation
{
    FUN_006dcbb0();
    ~FUN_006dcbb0();
    void FUN_006dcce0(int);
    bool FUN_006dd6f0(int);
};

struct FUN_006f4da0
{
    unsigned int flags;
    FUN_006dcbb0 path;
    int context;
    FUN_006f4da0(int, int);
};

// Initialises the path from source, stores contextValue, sets flags to 6 and adds bit 1 when the path check for 0 succeeds.
// @fnv 0x006f4da0
FUN_006f4da0::FUN_006f4da0(int source, int contextValue) : path()
{
    path.FUN_006dcce0(source);
    context = contextValue;
    flags = 6;
    if (path.FUN_006dd6f0(0))
        flags |= 1;
}

struct MeshPoint
{
    float x;
    float y;
    float z;
};
struct MeshTriangle
{
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
};
class MeshTriangleArray
{
  public:
    unsigned int FUN_0044ddc0();                 // GetSize
    MeshTriangle* FUN_0069ccf0(unsigned int i);  // GetAt
};
class MeshVertexArray
{
  public:
    bool FUN_0076b610();                      // IsEmpty
    MeshPoint* FUN_006a1440(unsigned int i);  // GetAt
};
bool __cdecl FUN_006b9cf0(const MeshPoint* pkA, const MeshPoint* pkB, const MeshPoint* pkC, const MeshPoint* pkPoint,
                          float* pfHeight, float fAbove, float fBelow);

class MeshBounds
{
  public:
    MeshPoint m_kMin;           // +0x00
    MeshPoint m_kMax;           // +0x0c
    MeshTriangleArray m_kTris;  // +0x18
    int unk1c[3];
    MeshVertexArray m_kVerts;  // +0x28

    bool ContainsPoint(const MeshPoint* pkPoint);
};

// @fnv 0x0069bea0
bool MeshBounds::ContainsPoint(const MeshPoint* pkPoint)
{
    if (pkPoint->x >= m_kMin.x && pkPoint->x <= m_kMax.x && pkPoint->y >= m_kMin.y && pkPoint->y <= m_kMax.y &&
        m_kMin.z - 180.0 <= pkPoint->z && m_kMax.z + 180.0 >= pkPoint->z)
    {
        if (!m_kVerts.FUN_0076b610())
        {
            float m_fGlyphExtent = m_kMax.z - m_kMin.z;
            float fOut;
            for (unsigned int i = 0; i < m_kTris.FUN_0044ddc0(); i++)
            {
                MeshPoint kA = *m_kVerts.FUN_006a1440(m_kTris.FUN_0069ccf0(i)->v0);
                MeshPoint kB = *m_kVerts.FUN_006a1440(m_kTris.FUN_0069ccf0(i)->v1);
                MeshPoint kC = *m_kVerts.FUN_006a1440(m_kTris.FUN_0069ccf0(i)->v2);
                if (FUN_006b9cf0(&kA, &kB, &kC, pkPoint, &fOut, m_fGlyphExtent, m_fGlyphExtent))
                    return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

extern const char DAT_0106cdec[];
extern const char DAT_0106cdd8[];
int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
int __cdecl FUN_00408b20(const char*, const char*);
struct DebugForm
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
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* editorName();
};
struct DebugWorld : DebugForm
{
    DebugForm* FUN_00587550(const NiPoint3&);
};
struct DebugMesh
{
    unsigned int FUN_00559450();
    DebugWorld* FUN_00690800();
    DebugForm* FUN_006b7770();
};
struct DebugMeshes
{
    unsigned int FUN_0044ddc0();
    DebugMesh*& FUN_006a7ad0(unsigned int);
};
struct DebugLocation
{
    void* unk00;
    NiPoint3 location;
    DebugMesh* mesh;
    DebugMeshes* meshes;
    DebugForm* cell;
    DebugWorld* world;
    int cellKey;
    unsigned short triangle;
    void FormatDebugString(char*, unsigned int);
};
// Writes a formatted description of the location's cell, world, mesh or mesh list and coordinates into out up to capacity.
// @fnv 0x006de790
void DebugLocation::FormatDebugString(char* acBuffer, unsigned int capacity)
{
    if (!mesh || (meshes && !meshes->FUN_0044ddc0()))
    {
        if (!world)
        {
            FUN_00406d00(acBuffer, capacity, "Cell %s, %.2f %.2f %.2f", cell ? cell->editorName() : "NONE", location.x,
                         location.y, location.z);
        }
        else
        {
            int cellX2 = (int)location.x >> 12;
            int y8 = (int)location.y >> 12;
            DebugForm* found8 = world->FUN_00587550(location);
            if (found8)
                FUN_00406d00(acBuffer, capacity, "Cell %s[%d,%d] %s,  %.2f %.2f %.2f", world->editorName(), cellX2, y8,
                             found8->editorName(), location.x, location.y, location.z);
            else
                FUN_00406d00(acBuffer, capacity, "Cell %s[%d,%d], %.2f %.2f %.2f", world->editorName(), cellX2, y8,
                             location.x, location.y, location.z);
        }
    }
    else
    {
        char meshName2[256];
        if (mesh)
        {
            if (triangle != 65535)
                FUN_00406d00(acBuffer, capacity, DAT_0106cdec, meshName2, triangle, location.x, location.y, location.z);
            else
                FUN_00406d00(acBuffer, capacity, DAT_0106cdd8, meshName2, location.x, location.y, location.z);
        }
        else
        {
            char list7[256];
            FUN_00406d00(list7, capacity, "[");
            {
                unsigned int i3;
                for (i3 = 0; i3 < meshes->FUN_0044ddc0(); i3++)
                {
                    char entry2[64];
                    FUN_00406d00(entry2, 64, "%08x", meshes->FUN_006a7ad0(i3)->FUN_00559450());
                    FUN_00406d50(list7, 256, entry2);
                    if (i3 < meshes->FUN_0044ddc0() - 1)
                        FUN_00406d50(list7, 256, ", ");
                }
                FUN_00406d50(list7, 256, "]");
                DebugWorld* listWorld4 = meshes->FUN_006a7ad0(0)->FUN_00690800();
                DebugForm* listCell3 = meshes->FUN_006a7ad0(0)->FUN_006b7770();
                if (!listWorld4)
                {
                    FUN_00406d00(acBuffer, capacity, "%s Cell %s, %.2f %.2f %.2f", list7, listCell3->editorName(),
                                 location.x, location.y, location.z);
                }
                else
                {
                    int gx = (int)location.x >> 12;
                    int gy2 = (int)location.y >> 12;
                    if (listCell3 && FUN_00408b20(listCell3->editorName(), ""))
                        FUN_00406d00(acBuffer, capacity, "%s Cell %s[%d, %d](%s), %.2f %.2f %.2f", list7,
                                     listWorld4->editorName(), gx, gy2, listCell3->editorName(), location.x, location.y,
                                     location.z);
                    else
                        FUN_00406d00(acBuffer, capacity, "%s Cell %s[%d, %d], %.2f %.2f %.2f", list7,
                                     listWorld4->editorName(), gx, gy2, location.x, location.y, location.z);
                }
            }
        }
    }
}

struct PathingLocationCheck : PathingLocation
{
    void FUN_006dd6f0(int);
    bool FUN_006dd6a0();
    NiPoint3 FUN_005c3420() const;
    bool FUN_006ded70(float fRadius);
};

bool __cdecl PathingLocationTestPoint(PathingLocation* pLoc, NiPoint3* pPoint, int a, int b);

extern double _gModifierZero;

// @fnv 0x006ded70
bool PathingLocationCheck::FUN_006ded70(float afRadius)
{
    FUN_006dd6f0(0);
    if (!FUN_006dd6a0())
        return false;
    if (afRadius <= _gModifierZero)
        return true;
    NiPoint3 kLoc4 = FUN_005c3420();
    NiPoint3 kMinX2 = kLoc4;
    kMinX2.x -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinX2, 0, 0))
        return false;
    NiPoint3 kMaxX7 = kLoc4;
    kMaxX7.x += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxX7, 0, 0))
        return false;
    NiPoint3 kMinY = kLoc4;
    kMinY.y -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinY, 0, 0))
        return false;
    NiPoint3 kMaxY6 = kLoc4;
    kMaxY6.y += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxY6, 0, 0))
        return false;
    return true;
}

class Node_cls;

class NodeArr_cls
{
  public:
    void* unk00;
    Node_cls** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetCount();
    Node_cls*& GetAt(unsigned int index);
    int Find(Node_cls** item, unsigned int start, int (*pred)());
};

class Node_cls
{
  public:
    unsigned char unk00[0x24];
    NodeArr_cls m_24;
    NodeArr_cls m_34;
};

class Owner_cls : public NodeArr_cls
{
  public:
    bool Check();
    Node_cls** GetNodeRef(unsigned int index);
};

class Snap_cls : public NodeArr_cls
{
  public:
    Snap_cls();
    ~Snap_cls();
    void Add(Node_cls** item);
};

int FUN_009a3830();

class FUN_006de490_cls
{
  public:
    unsigned char unk00[0x10];
    int m_10;
    Owner_cls* m_14;
    bool HasAllNodes();
};

// @fnv 0x006de490
bool FUN_006de490_cls::HasAllNodes()
{
    Snap_cls list;
    Node_cls* itemB;
    Node_cls* fCur;
    Node_cls* item2;
    unsigned int aJ;
    unsigned int b;
    unsigned int iG;
    unsigned int j6;
    unsigned int k;
    bool changed2;
    int unk2C;

    if (m_10 != 0)
    {
        return true;
    }
    else
    {
        if (m_14 != 0 && !m_14->Check())
        {
            list.Add(m_14->GetNodeRef(0));
            aJ = (*m_14->GetNodeRef(0))->m_24.GetCount();
            b = (*m_14->GetNodeRef(0))->m_34.GetCount();
            for (iG = 0; iG < aJ + b; iG++)
            {
                if (iG < aJ)
                {
                    itemB = (*m_14->GetNodeRef(0))->m_24.GetAt(iG);
                }
                else
                {
                    itemB = (*m_14->GetNodeRef(0))->m_34.GetAt(iG - aJ);
                }
                if (m_14->Find(&itemB, 0, FUN_009a3830) != -1)
                {
                    list.Add(&itemB);
                }
            }
            if (list.GetCount() == m_14->GetCount())
            {
                return true;
            }
            do
            {
                changed2 = false;
                for (k = 1; k < list.GetCount(); k++)
                {
                    fCur = list.GetAt(k);
                    aJ = fCur->m_24.GetCount();
                    b = fCur->m_34.GetCount();
                    for (j6 = 0; j6 < fCur->m_24.GetCount(); j6++)
                    {
                        if (j6 < aJ)
                        {
                            item2 = fCur->m_24.GetAt(j6);
                        }
                        else
                        {
                            item2 = fCur->m_34.GetAt(j6 - aJ);
                        }
                        if (m_14->Find(&item2, 0, FUN_009a3830) != -1)
                        {
                            if (list.Find(&item2, 0, FUN_009a3830) == -1)
                            {
                                list.Add(&item2);
                                changed2 = true;
                            }
                        }
                    }
                }
            } while (changed2);
            if (list.GetCount() == m_14->GetCount())
            {
                return true;
            }
        }
    }
    return false;
}

struct NLPoint
{
    float x, y, z;
    NLPoint ApplyScaled(float fScale) const;            // operator*
    NLPoint FUN_00439e90(const NLPoint& kOther) const;  // operator+
    NLPoint FUN_00439ef0(const NLPoint& kOther) const;  // operator-
    float GetSquaredXYLength() const;                   // horizontal length
};

struct NLEdgeHit
{
    int m_iEdgeNumber;
    int unk04;
    NLPoint kPoint;
};

class NLMesh
{
  public:
    bool FUN_00696cf0(const NLPoint& kPos, unsigned short& m_usTriangleID, bool& bInside);
    NLPoint FUN_00558220(unsigned short m_usTriangleID);  // triangle center
    NLEdgeHit FindEdgeIntersection(unsigned short m_usTriangleID, int m_iEdgeNumber, const NLPoint& kFrom,
                                   const NLPoint& kTo);
};

class NLMeshPtrView
{
  public:
    NLMesh* FUN_00559450();  // operator->
    NLMesh* FUN_00458b50();  // get
};

class NLMeshInfo
{
  public:
    bool FUN_0068f320();
    bool FUN_0069ad00(NavMeshPtr& pFoundNavMesh);  // ResolveNavMesh
};

class NLMeshInfoArray
{
  public:
    unsigned int FUN_0044ddc0();                      // GetSize
    NLMeshInfo*& FUN_006a7ad0(unsigned int uiIndex);  // GetAt
};

class NLTES
{
  public:
    float GetCellHeightAtPosition(const NLPoint& kPos, void* pvCell);
};
extern NLTES* DAT_011dea10;
extern const float DAT_01016970;  // FLT_MAX

class NLLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NLPoint Location;
    NLMeshInfo* m_pLocationNavMesh;
    NLMeshInfoArray* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;

    void FUN_006dd280(const NLPoint& kPos, void* pvCell, void* pvWorldSpace);
    bool UpdateMeshLocation();
};

// @fnv 0x006ddc00
bool NLLocation::UpdateMeshLocation()
{
    FUN_006dd280(Location, pCell, m_pContainingWorldspace);
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    if (m_pLocationNavMesh && m_usTriangleID != kClearTriangleDataValue1)
        return true;

    if (m_pLocationNavMesh)
    {
        bool bInside = false;
        NavMeshPtr kMeshPtr;
        if (m_pLocationNavMesh->FUN_0069ad00(kMeshPtr))
        {
            if (((NLMeshPtrView*)&kMeshPtr)->FUN_00559450()->FUN_00696cf0(Location, m_usTriangleID, bInside))
            {
                if (!bInside)
                {
                    NLPoint kTriCenter = ((NLMeshPtrView*)&kMeshPtr)->FUN_00559450()->FUN_00558220(m_usTriangleID);
                    NLEdgeHit kResult = ((NLMeshPtrView*)&kMeshPtr)
                                            ->FUN_00559450()
                                            ->FindEdgeIntersection(m_usTriangleID, -1, kTriCenter, Location);
                    if (kResult.m_iEdgeNumber)
                        Location = kResult.kPoint.ApplyScaled(0.9f).FUN_00439e90(kTriCenter.ApplyScaled(0.1f));
                }
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        float fNearest = DAT_01016970;
        int iClosest = -1;
        unsigned short usBestTri = kClearTriangleDataValue1;
        bool bValidFound = false;
        unsigned int uiNumMeshes = pNavMeshInfoArray->FUN_0044ddc0();
        bool bClose = false;
        if (DAT_011dea10->GetCellHeightAtPosition(Location, pCell) + 25.0 > Location.z)
            bClose = true;
        for (unsigned int i = 0; i < uiNumMeshes; i++)
        {
            unsigned short usTri = kClearTriangleDataValue1;
            bool bInTri = false;
            NavMeshPtr pFoundNavMesh;
            NLMeshInfo* pInfo = pNavMeshInfoArray->FUN_006a7ad0(i);
            if (!pInfo->FUN_0068f320() && pInfo->FUN_0069ad00(pFoundNavMesh) &&
                !((NLMeshPtrView*)&pFoundNavMesh)->FUN_00559450()->FUN_00696cf0(Location, usTri, bInTri))
                continue;
            if (bInTri)
            {
                m_pLocationNavMesh = pNavMeshInfoArray->FUN_006a7ad0(i);
                pNavMeshInfoArray = 0;
                m_usTriangleID = usTri;
                return true;
            }
            else if (((NLMeshPtrView*)&pFoundNavMesh)->FUN_00458b50())
            {
                NLPoint kToCenter =
                    Location.FUN_00439ef0(((NLMeshPtrView*)&pFoundNavMesh)->FUN_00559450()->FUN_00558220(usTri));
                float fDist = kToCenter.GetSquaredXYLength();
                float m_fGlyphExtent = kToCenter.z;
                bool bGood = false;
                if ((bClose || m_fGlyphExtent < 180.0) && m_fGlyphExtent > -64.0)
                    bGood = true;
                if (bValidFound)
                {
                    if (bGood && fDist < fNearest)
                    {
                        fNearest = fDist;
                        usBestTri = usTri;
                        iClosest = i;
                    }
                }
                else if (bGood)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                    bValidFound = true;
                }
                else if (fDist < fNearest)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                }
            }
        }
        if (iClosest != -1)
        {
            m_pLocationNavMesh = pNavMeshInfoArray->FUN_006a7ad0(iClosest);
            pNavMeshInfoArray = 0;
            m_usTriangleID = usBestTri;
            NavMeshPtr spBest;
            if (m_pLocationNavMesh->FUN_0069ad00(spBest))
            {
                NLPoint kTriCenter = ((NLMeshPtrView*)&spBest)->FUN_00559450()->FUN_00558220(usBestTri);
                NLEdgeHit kResult = ((NLMeshPtrView*)&spBest)
                                        ->FUN_00559450()
                                        ->FindEdgeIntersection(usBestTri, -1, kTriCenter, Location);
                if (kResult.m_iEdgeNumber)
                    Location = kTriCenter.ApplyScaled(0.1f).FUN_00439e90(kResult.kPoint.ApplyScaled(0.9f));
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}

class PathingRequest;
class PathingSolution;

class FUN_006d0b80
{
  public:
    ~FUN_006d0b80();

    int unk00[13];
};

class PathBuilder : public FUN_006d0b80
{
  public:
    PathBuilder(PathingRequest* pRequest, PathingSolution* m_pOutputSolution);
    bool BuildPath();
};

// Creates a PathBuilder from pRequest and m_pOutputSolution, calls BuildPath, and returns its result.
// @fnv 0x006d0b10
bool __cdecl FUN_006d0b10(PathingRequest* pRequest, PathingSolution* m_pOutputSolution)
{
    PathBuilder kBuilder(pRequest, m_pOutputSolution);
    bool bResult = kBuilder.BuildPath();
    return bResult;
}

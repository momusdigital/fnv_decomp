// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHBUILDER_H
#define FNV_PATHBUILDER_H

#include "layout_support.h"
#include "layout_support.h"
class FindTriangleForLocationFilter;
class NavMesh;
class NavMeshPtr;
class PathBuilder;
class PathBuilder__FindTriangleForLocationWaterFilter;
class PathingRequest;
class PathingSolution;
class PathingInfoEntry;
class ScrapHeapBuffer;
class MemoryManager
{
  public:
    ScrapHeapBuffer* GetGeneralAllocator();
};
MemoryManager* FUN_00401020();
#pragma pack(push, 4)
class FindTriangleForLocationFilter
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // FindTriangleForLocationFilter
    // FindTriangleForLocationFilter& __cdecl FindTriangleForLocationFilter::*(const FindTriangleForLocationFilter&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FindTriangleForLocationFilter) == 4);
FNV_STATIC_ASSERT(offsetof(FindTriangleForLocationFilter, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class PathBuilder__FindTriangleForLocationWaterFilter : public FindTriangleForLocationFilter
{
  public:
    PathBuilder__FindTriangleForLocationWaterFilter();
    // base FindTriangleForLocationFilter at +0x0, size 4
    // bool __cdecl PathBuilder::FindTriangleForLocationWaterFilter::*(const NiPoint3&, const NavMesh*, unsigned short, const NiPoint3&)
    // FindTriangleForLocationWaterFilter
    // PathBuilder::FindTriangleForLocationWaterFilter& __cdecl PathBuilder::FindTriangleForLocationWaterFilter::*(const PathBuilder::FindTriangleForLocationWaterFilter&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathBuilder__FindTriangleForLocationWaterFilter) == 4);
#pragma pack(push, 4)
class NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    // base NiPointer<NavMesh> at +0x0, size 4
    // NavMeshPtr
    // void __cdecl NavMeshPtr::*()
    // NavMeshPtr& __cdecl NavMeshPtr::*(const NavMeshPtr&)
    // bool __cdecl NavMeshPtr::*(const NavMeshPtr&)
    // bool __cdecl NavMeshPtr::*(const NavMeshPtr&)
    // NavMesh* __cdecl NavMeshPtr::*()
    // GetPtr
    // void* __cdecl NavMeshPtr::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshPtr) == 4);
class PathBuilderDetailedPathInfos : public BSSimpleArray<const NavMeshInfo*, 1024>
{
  public:
    PathBuilderDetailedPathInfos();
    ~PathBuilderDetailedPathInfos();
};
class PathBuilderDetailedPathMeshes : public BSSimpleArray<NavMeshPtr, 1024>
{
  public:
    PathBuilderDetailedPathMeshes();
    ~PathBuilderDetailedPathMeshes();
};
#pragma pack(push, 4)
class PathBuilder
{
  public:
    PathingRequest* pRequest;                                                        // +0x0, 4 bytes
    PathingSolution* m_pOutputSolution;                                              // +0x4, 4 bytes
    ScrapHeapBuffer* m_pAllocator;                                                   // +0x8, 4 bytes
    PathBuilder__FindTriangleForLocationWaterFilter m_kTriangleLocationWaterFilter;  // +0xC, 4 bytes
    bool m_bPathFound;                                                               // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    PathBuilderDetailedPathInfos DetailedPathInfoList;   // +0x14, 16 bytes
    PathBuilderDetailedPathMeshes DetailedPathMeshList;  // +0x24, 16 bytes
    PathBuilder(PathingRequest*, PathingSolution*);
    bool BuildPath();
    bool BuildActorPathSegments(Actor*);
    bool BuildPathSpans(BSSimpleArray<NavMeshEdgeData, 1024>&);
    bool TryConnectPathNodes(unsigned int, unsigned int);
    bool BuildPathSegment(unsigned int, unsigned int);
    bool IsNavMeshInfoCompatible(const NavMeshInfo*, const NavMeshInfo*);
    bool CanPathBetweenNavMeshes(const NavMeshInfo*, const NavMeshInfo*);
    bool BuildTeleportDoorPath();
    bool BuildPathForActor(Actor*, unsigned int);
    void* AdvanceCounter();
    void* FUN_006e8f40(void*);
    PathingInfoEntry* GetPathingInfoEntry(PathingInfoEntry&);
    // PathBuilder
    // bool __cdecl PathBuilder::*()
    // Pathing::UPDATE_DETAILED_PATH_RESULT __cdecl PathBuilder::*(unsigned int, const NiPoint3&)
    // Pathing::UPDATE_DETAILED_PATH_RESULT __cdecl PathBuilder::*()
    // Pathing::UPDATE_DETAILED_PATH_RESULT __cdecl PathBuilder::*(unsigned int)
    // bool __cdecl PathBuilder::*(const NavMeshInfo*, const NavMeshInfo*)
    // bool __cdecl PathBuilder::*()
    // bool __cdecl PathBuilder::*(const NavMeshInfo*, const NavMeshInfo*)
    // bool __cdecl PathBuilder::*(unsigned int, int*, int*)
    // bool __cdecl PathBuilder::*(Actor*, unsigned int)
    // bool __cdecl PathBuilder::*(Actor*)
    // bool __cdecl PathBuilder::*(unsigned int, unsigned int)
    // PathBuilder::ADD_NODES_FROM_NAVMESH_RESULT __cdecl PathBuilder::*(PathingLocation&, PathingLocation&, unsigned int, unsigned int)
    // bool __cdecl PathBuilder::*(const NiPoint3&, const NiPoint3&, ParentSpaceNode*, TESObjectREFR*)
    // bool __cdecl PathBuilder::*(const NiPoint3&, const NiPoint3&, ParentSpaceNode*, TESObjectREFR*)
    // bool __cdecl PathBuilder::*(unsigned int, unsigned int)
    // RAYCASTPATH_RESULT __cdecl PathBuilder::*(PathingLocation&, PathingLocation&, BSSimpleArray<PathingLocation,1024>&)
    // bool __cdecl PathBuilder::*(PathingLocation&, PathingLocation&)
    // void __cdecl PathBuilder::*()
    // PathBuilder& __cdecl PathBuilder::*(const PathBuilder&)
    // void* __cdecl PathBuilder::*(unsigned int)
};
#pragma pack(pop)
void* FUN_006e6da0(unsigned int, void*);
FNV_STATIC_ASSERT(sizeof(PathBuilder) == 52);
FNV_STATIC_ASSERT(offsetof(PathBuilder, pRequest) == 0);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_pOutputSolution) == 4);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_pAllocator) == 8);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_kTriangleLocationWaterFilter) == 12);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_bPathFound) == 16);
FNV_STATIC_ASSERT(offsetof(PathBuilder, DetailedPathInfoList) == 20);
FNV_STATIC_ASSERT(offsetof(PathBuilder, DetailedPathMeshList) == 36);
#endif

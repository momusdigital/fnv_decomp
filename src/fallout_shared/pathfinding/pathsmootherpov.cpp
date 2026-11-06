// fallout_shared/pathfinding/pathsmootherpov.cpp: PathSmootherPOVSearch, std, MyHolder, Manager6AE and more (63 functions)

#include "pathsmootherpov_decls.h"

// @fnv 0x006afcc0
void PathSmootherPOVSearch::AddPathPoints(bool addGoal)
{
    for (unsigned int i = 0; i < Links.GetSize(); ++i)
    {
        NiPoint3 delta = Links.GetBufferElementAddress(i).m_kEndPoint.Location -
                         Links.GetBufferElementAddress(i).m_kStartPoint.Location;
        float segmentLength = delta.FUN_00457990();
        bool bAdd = true;
        if (i > 0)
        {
            SineCosine difference =
                Links.GetBufferElementAddress(i).m_kStartAngle - Links.GetBufferElementAddress(i - 1).m_kEnd;
            CircularArc halfCircle(SineCosine(-1.5707963705062866f), SineCosine(1.5707963705062866f), AD_CCW);
            if (difference.FUN_006a0840() * Nodes.FUN_006a1440(i).m_pAvoidNode->fRadius < 50.0 &&
                halfCircle.FUN_006a0660(difference))
                bAdd = false;
            if (m_bUnderwaterPath)
            {
                float water = g_TES->UpdateTESState(
                    Links.GetBufferElementAddress(i).m_kStartPoint.Location,
                    Links.GetBufferElementAddress(i).m_kStartPoint.m_pLocationNavMesh->GetCurrentMoveModeType());
                if (water >= Links.GetBufferElementAddress(i).m_kStartPoint.Location.z)
                    Links.GetBufferElementAddress(i).m_kStartPoint.Location.z = water;
            }
        }
        if (bAdd)
        {
            PathingLocation Location(Links.GetBufferElementAddress(i).m_kStartPoint.Location,
                                     Links.GetBufferElementAddress(i).m_kStartPoint.m_pLocationNavMesh->FUN_0068efb0());
            NiPoint3 Dir =
                RotatePoint90(Links.GetBufferElementAddress(i).m_kStartAngle, Nodes.FUN_006a1440(i).Direction);
            if (i > 0)
            {
                SineCosine difference =
                    Links.GetBufferElementAddress(i).m_kStartAngle - Links.GetBufferElementAddress(i - 1).m_kEnd;
                float arcLength = std::abs(difference.FUN_006a0840() * Nodes.FUN_006a1440(i).m_pAvoidNode->fRadius);
                Dir *= arcLength;
            }
            else
                Dir *= Nodes.FUN_006a1440(i).m_pAvoidNode->fRadius;
            Dir *= 3.0f;
            if (Dir.FUN_004a7290() > segmentLength * segmentLength)
            {
                Dir.ComputeMagnitude();
                Dir *= segmentLength;
            }
            m_pOutputSolution->ReserveIndex(Location, Dir);
        }
        if (m_bUnderwaterPath && (i < Links.GetSize() - 1 || m_pOutputSolution->FUN_006b05d0() || addGoal))
        {
            float water = g_TES->UpdateTESState(
                Links.GetBufferElementAddress(i).m_kEndPoint.Location,
                Links.GetBufferElementAddress(i).m_kEndPoint.m_pLocationNavMesh->GetCurrentMoveModeType());
            if (water >= Links.GetBufferElementAddress(i).m_kEndPoint.Location.z)
                Links.GetBufferElementAddress(i).m_kEndPoint.Location.z = water;
        }
        PathingLocation Location(Links.GetBufferElementAddress(i).m_kEndPoint.Location,
                                 Links.GetBufferElementAddress(i).m_kEndPoint.m_pLocationNavMesh->FUN_0068efb0());
        NiPoint3 Dir = RotatePoint90(Links.GetBufferElementAddress(i).m_kEnd, Nodes.FUN_006a1440(i + 1).Direction);
        AddNavMeshEdgeRecord(Links.GetBufferElementAddress(i).m_kStartPoint.m_pLocationNavMesh,
                             Links.GetBufferElementAddress(i).m_kStartPoint.m_usTriangleID,
                             Links.GetBufferElementAddress(i).m_kStartPoint.Location,
                             Links.GetBufferElementAddress(i).m_kEndPoint.Location);
        if (i < Links.GetSize() - 1)
        {
            SineCosine difference =
                Links.GetBufferElementAddress(i + 1).m_kStartAngle - Links.GetBufferElementAddress(i).m_kEnd;
            float arcLength = std::abs(difference.FUN_006a0840() * Nodes.FUN_006a1440(i + 1).m_pAvoidNode->fRadius);
            Dir *= arcLength;
        }
        else
            Dir *= Nodes.FUN_006a1440(i + 1).m_pAvoidNode->fRadius;
        Dir *= 3.0f;
        if (Dir.FUN_004a7290() > segmentLength * segmentLength)
        {
            Dir.ComputeMagnitude();
            Dir *= segmentLength;
        }
        m_pOutputSolution->ReserveIndex(Location, Dir);
    }
    if (pRequest->GetFaceTargetAtGoal() && !Links.FUN_0076b610())
    {
        NiPoint3 Dir = m_pOutputSolution->FUN_006b05a0()->FUN_005d8a70();
        float fStartAngle = GetDirectionAngle(Dir);
        float goalAngle = pRequest->FUN_00507e10();
        float difference = goalAngle - fStartAngle;
        WrapValueToRange(difference, -3.1415927410125732f, 3.1415927410125732f);
        if (std::abs(difference) < 1.5707963267948966)
        {
            float segmentLength = Dir.FUN_00589850();
            NiPoint3 NewTangent;
            NewTangent.x = cos(goalAngle) * segmentLength;
            NewTangent.y = FUN_004e44b0(goalAngle) * segmentLength;
            NewTangent.z = 0.0f;
            m_pOutputSolution->FUN_006b05a0()->FUN_006b0570(NewTangent);
        }
    }
}

// @fnv 0x006af500
void PathSmootherPOVSearch::BuildSmoothedPath()
{
    NavMeshEdgePoint startEdge;
    PathingLocation StartLoc(m_kPathStartPosition, Triangles->GetFirstElement().m_pLocationNavMesh->FUN_0068efb0(),
                             Triangles->GetFirstElement().m_usTriangleIdentifier);
    if (FUN_006d4570(StartLoc, pRequest->GetFloatAtOffset68(), startEdge))
    {
        NiPoint3 Diff = m_kPathStartPosition - startEdge.Location;
        NiPoint3 Perp = DAT_011a9484.CrossProduct(Diff);
        PathSmootherPOVPoint* pLeftPOV = new PathSmootherPOVPoint;
        pLeftPOV->eType = 4;
        pLeftPOV->m_kFirstEdge = NiPoint3::ZERO;
        pLeftPOV->m_kSecondEdge = NiPoint3::ZERO;
        pLeftPOV->Center = m_kPathStartPosition + Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pLeftPOV->m_fWeight = 1.0f;
        pLeftPOV->fRadius = pRequest->GetFloatAtOffset68();
        pLeftPOV->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pLeftPOV);
        m_kRequestPathPoints.Add(pLeftPOV);
        PathSmootherPOVPoint* pPOV2 = new PathSmootherPOVPoint;
        pPOV2->eType = 4;
        pPOV2->m_kFirstEdge = NiPoint3::ZERO;
        pPOV2->m_kSecondEdge = NiPoint3::ZERO;
        pPOV2->Center = m_kPathStartPosition - Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pPOV2->m_fWeight = 1.0f;
        pPOV2->fRadius = pRequest->GetFloatAtOffset68();
        pPOV2->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pPOV2);
        m_kRequestPathPoints.Add(pPOV2);
    }
    NavMeshEdgePoint GoalEdgeLoc;
    PathingLocation GoalPathLocation(m_kGoalPosition, Triangles->GetLastElement().m_pLocationNavMesh->FUN_0068efb0(),
                                     Triangles->GetLastElement().m_usTriangleIdentifier);
    if (FUN_006d4570(GoalPathLocation, pRequest->GetFloatAtOffset68(), GoalEdgeLoc))
    {
        NiPoint3 Diff = m_kGoalPosition - GoalEdgeLoc.Location;
        NiPoint3 Perp = DAT_011a9484.CrossProduct(Diff);
        PathSmootherPOVPoint* pLeftPOV = new PathSmootherPOVPoint;
        pLeftPOV->eType = 4;
        pLeftPOV->m_kFirstEdge = NiPoint3::ZERO;
        pLeftPOV->m_kSecondEdge = NiPoint3::ZERO;
        pLeftPOV->Center = m_kGoalPosition + Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pLeftPOV->m_fWeight = 1.0f;
        pLeftPOV->fRadius = pRequest->GetFloatAtOffset68();
        pLeftPOV->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pLeftPOV);
        m_kRequestPathPoints.Add(pLeftPOV);
        PathSmootherPOVPoint* pPOV2 = new PathSmootherPOVPoint;
        pPOV2->eType = 4;
        pPOV2->m_kFirstEdge = NiPoint3::ZERO;
        pPOV2->m_kSecondEdge = NiPoint3::ZERO;
        pPOV2->Center = m_kGoalPosition - Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pPOV2->m_fWeight = 1.0f;
        pPOV2->fRadius = pRequest->GetFloatAtOffset68();
        pPOV2->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pPOV2);
        m_kRequestPathPoints.Add(pPOV2);
    }
}

// @fnv 0x006ad770
bool PathSmootherPOVSearch::SearchForPath(PathingRequest* request,
                                          const BSSimpleArray<NavMeshTriangleReference>& triangles,
                                          const BSSimpleArray<NavMeshTriangleEdgeReference>& edges,
                                          const NiPoint3& start, const NiPoint3& goal, PathingSolution* solution,
                                          BSSimpleArray<NavMeshTriangleEdgeReference>* extraEdges,
                                          BSSimpleArray<const NavMeshInfo*>* infos)
{
    pRequest = request;
    m_kPathStartPosition = start;
    m_kGoalPosition = goal;
    Triangles = &triangles;
    Edges = &edges;
    m_pOutputSolution = solution;
    m_pNavMeshInfos = infos;
    bool startUnderWater =
        triangles.GetFirstElement().m_pLocationNavMesh->GetCurrentMoveModeType()
            ? triangles.GetFirstElement().FUN_006a6eb0().z <
                  g_TES->UpdateTESState(start,
                                        triangles.GetFirstElement().m_pLocationNavMesh->GetCurrentMoveModeType()) +
                      50.0f
            : true;
    if (!startUnderWater)
    {
        float z = m_kPathStartPosition.z;
        triangles.GetFirstElement().m_pLocationNavMesh->GetTriangleHeightAtPoint(
            triangles.GetFirstElement().m_usTriangleIdentifier, m_kPathStartPosition, 180.0f, 64.0f, z);
        m_kPathStartPosition.z = z;
    }
    bool bGoalUnderWater = false;
    if (!request->FUN_006a9540()->FUN_006a9520() &&
        triangles.GetLastElement().m_pLocationNavMesh->GetCurrentMoveModeType() &&
        triangles.GetLastElement().FUN_006a6eb0().z <
            g_TES->UpdateTESState(goal, triangles.GetLastElement().m_pLocationNavMesh->GetCurrentMoveModeType()) +
                50.0f)
        bGoalUnderWater = true;
    if (!bGoalUnderWater)
    {
        float z = m_kGoalPosition.z;
        triangles.GetLastElement().m_pLocationNavMesh->GetTriangleHeightAtPoint(
            triangles.GetLastElement().m_usTriangleIdentifier, m_kGoalPosition, 180.0f, 64.0f, z);
        m_kGoalPosition.z = z;
    }
    if (startUnderWater && bGoalUnderWater)
        m_bUnderwaterPath = true;
    m_kPrimaryPathPoints.GrowCapacity(edges.GetSize());
    m_kSecondaryPathPoints.GrowCapacity(edges.GetSize());
    m_kPrimaryEdgeRecords.ReserveIndex(edges.GetSize());
    m_kSecondaryEdgeRecords.ReserveIndex(edges.GetSize());
    m_kRequestPathPoints.GrowCapacity(pRequest->GetString() ? pRequest->GetString()->GetSize() * 2 : 0);
    m_kPathPoints.GrowCapacity(edges.GetSize() * 2 + m_kRequestPathPoints.FUN_0084e3a0() + 2);
    AddAvoidanceNodes();
    PathSmootherPOVAvoidanceNode m_kStartingTriangle;
    m_kStartingTriangle.m_pAvoidNode = m_pStartPoint;
    m_kStartingTriangle.Direction = AD_CCW;
    InsertNode(FUN_0069f900(m_pStartPoint, AD_CCW), m_kStartingTriangle,
               (m_kGoalPosition - m_kPathStartPosition).FUN_00457990() * 0.75f);
    Nodes.Clear(false);
    Links.Clear(false);
    bool success = FUN_006b3380(&Nodes, &Links, true);
    if (!success)
    {
        BuildFallbackPath();
        if (extraEdges)
        {
            FUN_006b2fc0(extraEdges);
            if (Nodes.GetLastEdge().m_pAvoidNode->eType == 0 || Nodes.GetLastEdge().m_pAvoidNode->eType == 1)
            {
                NavMeshEdgeData Edge(Nodes.GetLastEdge().m_pAvoidNode->MeshEdgeRecord);
                NavMeshTriangleEdgeReference link;
                link.m_pLocationNavMesh = Edge.m_pLocationNavMesh;
                link.m_usTriangleIdentifier = Edge.m_usTriangleID;
                link.m_iEdgeIndex = Edge.m_iEdgeIndex;
                extraEdges->Add(link);
            }
        }
    }
    AddPathPoints(!success);
    for (unsigned int i = 0; i < triangles.GetSize(); ++i)
    {
        if (triangles.FUN_006b3160(i).FUN_006a78d0()->FUN_00691140(0x1000))
        {
            void* door = triangles.FUN_006b3160(i)
                             .m_pLocationNavMesh->GetClosedDoorInfo(triangles.FUN_006b3160(i).m_usTriangleIdentifier)
                             ->pPathNodeDoor;
            m_pOutputSolution->Doors.Add(door);
        }
    }
    for (unsigned int i = 0; i < m_kPathPoints.GetSize(); ++i)
        delete m_kPathPoints[i];
    return success;
}

// @fnv 0x006b0ad0
bool PathSmootherPOVSearch::CollectConnections(const POVNode* node, BSSimpleArray<POVNode*>* connections)
{
    const PathSmootherPOVAvoidanceNode& Node = node->FUN_00413f40();
    const int iMaxFailureCount = 4;
    unsigned int size = 0xffffffff;
    unsigned int failures = 0;
    FindPathToPoint(node, m_pGoalPoint, connections);
    if (Node.m_pAvoidNode->eType == 0)
    {
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiListIndex + 1; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiReferenceIndex; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else if (Node.m_pAvoidNode->eType == 1)
    {
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiListIndex + 1; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiReferenceIndex; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else if (Node.m_pAvoidNode->eType == 2)
    {
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else
    {
        size = m_kSecondaryPathPoints.GetSize();
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            FindPathToPoint(node, pov, connections);
        }
        size = m_kPrimaryPathPoints.GetSize();
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            FindPathToPoint(node, pov, connections);
        }
    }
    size = m_kRequestPathPoints.GetSize();
    for (unsigned int i = 0; i < size; ++i)
    {
        PathSmootherPOVPoint* pov = m_kRequestPathPoints[i];
        FindPathToPoint(node, pov, connections);
    }
    return true;
}

// Walks up to 1000 triangles from a start point toward an end point, smoothing the path across edges and adding pathing locations at crossings.
// @fnv 0x006b05f0
void PathSmootherPOVSearch::AddNavMeshEdgeRecord(NavMesh* mesh, unsigned short triangle, const NiPoint3& from,
                                                 const NiPoint3& to)
{
    NiPoint3 start = from;
    NiPoint3 end = to;
    NiPoint3 pathDirection = end - start;
    pathDirection.ComputeMagnitude();
    NiPoint3 CurrentLoc = start;
    NavMeshEdgeData currentEdge(mesh, triangle, -1);
    int iterations = 0;
    while (iterations < 1000)
    {
        ++iterations;
        int index = currentEdge.m_pLocationNavMesh->FindCrossedEdge(currentEdge.m_usTriangleID,
                                                                    currentEdge.m_iEdgeIndex, CurrentLoc, end);
        if (index == -1)
        {
            break;
        }
        else
        {
            NavMeshEdgeData exit(currentEdge.m_pLocationNavMesh, currentEdge.m_usTriangleID, index);
            NavMeshEdgeData entry;
            bool connected = exit.m_pLocationNavMesh->MatchNavMesh(exit, entry);
            if (connected)
            {
                if (currentEdge.m_pLocationNavMesh != entry.m_pLocationNavMesh)
                {
                    NavMeshEdgeVertexPair vertices =
                        entry.m_pLocationNavMesh->FUN_0068f040(entry.m_usTriangleID, entry.m_iEdgeIndex);
                    NiPoint3 center = (*vertices.p1 + *vertices.p2) * 0.5f;
                    CurrentLoc = FUN_006ba550(*vertices.p1, *vertices.p2, start, end);
                    CurrentLoc += (center - CurrentLoc) * 0.01f;
                }
                NiPoint3 exitNormal = exit.m_pLocationNavMesh->FUN_006971e0(exit.m_usTriangleID);
                NiPoint3 entryNormal = entry.m_pLocationNavMesh->FUN_006971e0(entry.m_usTriangleID);
                if (exitNormal.Dot(entryNormal) < 0.9f)
                {
                    NiPoint3 p1, p2;
                    exit.m_pLocationNavMesh->FUN_0068f0c0(exit.m_usTriangleID, exit.m_iEdgeIndex, p1, p2);
                    NiPoint3 Crossing;
                    if (FUN_006ba100(p1, p2, start, end, Crossing))
                    {
                        if ((Crossing - start).FUN_004a7290() > 1024.0f && (Crossing - end).FUN_004a7290() > 1024.0f &&
                            m_pOutputSolution->FUN_006b05a0() &&
                            (Crossing - m_pOutputSolution->FUN_006b05a0()->FUN_00717e50().FUN_005c3420())
                                    .FUN_004a7290() > 1024.0f)
                        {
                            if (m_bUnderwaterPath)
                            {
                                float water = g_TES->UpdateTESState(
                                    Crossing, m_pOutputSolution->FUN_006b05a0()->FUN_00717e50().FUN_006dd4f0());
                                if (water >= Crossing.z)
                                    Crossing.z = water;
                            }
                            PathingLocation location(Crossing, exit.m_pLocationNavMesh->FUN_0068efb0(),
                                                     exit.m_usTriangleID);
                            NiPoint3 Dir = pathDirection * pRequest->GetFloatAtOffset68();
                            m_pOutputSolution->ReserveIndex(location, Dir);
                        }
                    }
                }
                currentEdge = entry;
            }
            else
                break;
        }
    }
}

// @fnv 0x006b2c00
bool PathSmootherPOVSearch::CalculatePathCost(PathSmootherPOVPoint* from, PathSmootherPOVPoint* to,
                                              const NiPoint3& start, const NiPoint3& end, float* pfCost)
{
    *pfCost = (end - start).FUN_00457990();
    if ((end - start).GetSquaredXYLength() < 0.001f)
        return true;
    for (unsigned int i = 0; i < m_kRequestPathPoints.GetSize(); ++i)
    {
        PathSmootherPOVPoint* pov = m_kRequestPathPoints[i];
        if (FUN_006bab00(pov->Center, pov->fRadius, start, end))
        {
            Sphere sphere(pov->Center, pov->fRadius);
            Segment kSegment(start, end);
            SphereIntersection result;
            IntersectLineCircle(sphere, kSegment, result);
            NiPoint3 entryPoint, leavePoint;
            switch (result.type)
            {
            case 0:
            case 3:
                continue;
            case 5:
                entryPoint = start;
                leavePoint = end;
                break;
            case 4:
                entryPoint = start + (end - start) * result.t1;
                leavePoint = start + (end - start) * result.t2;
                break;
            case 1:
                entryPoint = start;
                leavePoint = start + (end - start) * result.t1;
                break;
            case 2:
                entryPoint = start + (end - start) * result.t1;
                leavePoint = end;
                break;
            }
            if (pov->eType == 5 && pov != to)
            {
                if (pRequest->GetByteAtOffset9B() && from->eType != 2)
                    return false;
                else
                    *pfCost *= 10.0f;
            }
            float segmentLength = (leavePoint - entryPoint).FUN_00457990();
            float fDist = DistanceToSegment(pov->Center, entryPoint, leavePoint, 0);
            float costFraction = (pov->fRadius - fDist) / pov->fRadius;
            if (costFraction < 0.0f)
                costFraction = 0.0f;
            *pfCost += (1.0f + costFraction * DAT_011d7084.Float()->f) * segmentLength;
        }
    }
    return true;
}

// Collects unique NavMesh pointers from Triangles, then for each mesh and triangle creates a POV object with center, radius and index and adds it to two arrays.
// @fnv 0x006af2b0
void PathSmootherPOVSearch::CollectUniqueNavMeshes()
{
    BSSimpleArray<NavMesh*> uniqueMeshes;
    for (unsigned int i = 0; i < Triangles->GetSize(); ++i)
    {
        if (uniqueMeshes.Find(Triangles->FUN_006dad90(i), 0, FUN_009a3830) == 0xffffffff)
            uniqueMeshes.Add(Triangles->FUN_006dad90(i));
    }
    for (unsigned int i = 0; i < uniqueMeshes.GetSize(); ++i)
    {
        NavMesh* mesh = uniqueMeshes[i];
        for (unsigned int j = 0; j < mesh->FUN_00691620(); ++j)
        {
            PathSmootherPOVPoint* pov = new PathSmootherPOVPoint;
            pov->eType = 4;
            pov->m_kFirstEdge = NiPoint3::ZERO;
            pov->m_kSecondEdge = NiPoint3::ZERO;
            pov->Center = mesh->FUN_00691640(j).FUN_006815c0();
            pov->m_fWeight = 1.0f;
            pov->fRadius = mesh->FUN_00691640(j).GetRadius() + pRequest->GetFloatAtOffset68() * 1.2f;
            pov->m_uiReferenceIndex = 0xffffffff;
            pov->m_uiCompositeId = i * 1000 + j;
            m_kPathPoints.Add(pov);
            m_kRequestPathPoints.Add(pov);
        }
    }
}

// Destructor for PathSmootherPOVSearch; the empty body performs no cleanup.
// @fnv 0x006ad690
PathSmootherPOVSearch::~PathSmootherPOVSearch()
{}

// Returns true when the node's FUN_00413f40 result has an eType field equal to 3.
// @fnv 0x006b1dc0
bool PathSmootherPOVSearch::HasReachedGoal(const POVNode* node)
{
    return node->FUN_00413f40().m_pAvoidNode->eType == 3;
}

// MSVC9 allocates these locals by identifier as well as scope.
// Semantic aliases preserve the verified stack layout while keeping the body readable.
#define currentNode iNumTangents
#define incomingLink pCurrentLink
#define centerDelta Tangents
#define xyDistanceSquared iTested
#define heightSquared fZDistSqr
#define startSphere Diff
#define endSphere Node
#define tangentData fXYDistSqr
#define tangentCount EndSphere
#define testedCount StartSphere
#define direction Dir
#define leftDirection Left
#define sourceArc EntryLoc
#define sourceLocation Arc
#define exitLocation ExitLoc
#define entryLocation ProjectedLoc
#define destination height
#define projectedPoint EndLoc
#define heightDelta StartLoc
#define discount fDiscount
#define cost m_fPathingCostCur
#define nextNode pListNode
#define radialDistance Right
#define rightDirection fScaleMultiplier
#define tangentLength Perp
#define perpendicular fTangentLength

// @fnv 0x006b0f40
bool PathSmootherPOVSearch::FindPathToPoint(const POVNode* node, PathSmootherPOVPoint* pov,
                                            BSSimpleArray<POVNode*>* connections)
{
    int failedCount;
    const NavMeshEdgeSegment* incomingLink;
    {
        const PathSmootherPOVAvoidanceNode& currentNode = node->FUN_00413f40();
        incomingLink = &node->FUN_007d6bb0();
        if (pov == currentNode.m_pAvoidNode)
            return true;
        if (node->GetField54() && pov == node->GetField54()->FUN_00413f40().m_pAvoidNode)
            return true;
        NiPoint3 centerDelta = pov->Center - currentNode.m_pAvoidNode->Center;
        float xyDistanceSquared = centerDelta.GetSquaredXYLength();
        float heightSquared = centerDelta.z * centerDelta.z;
        if (!m_bUnderwaterPath && xyDistanceSquared * 1.2000000476837158 * 1.2000000476837158 < heightSquared)
            return true;
        Sphere startSphere(currentNode.m_pAvoidNode->Center, currentNode.m_pAvoidNode->fRadius);
        Sphere endSphere(pov->Center, pov->fRadius);
        SphereTangents tangentData;
        int tangentCount =
            NavMeshPOVSearch::FindSphereTangents(startSphere, endSphere, currentNode.Direction, tangentData);
        if (!node->GetField54())
        {
            NiPoint3 direction = currentNode.m_pAvoidNode->Center - pov->Center;
            if (direction.FUN_004a7290() < pov->fRadius * pov->fRadius)
            {
                direction.z = 0.0f;
                float radialDistance = direction.GetLengthSquared();
                NiPoint3 leftDirection, rightDirection;
                if (pov->fRadius * 0.5 > radialDistance)
                {
                    leftDirection = direction;
                    rightDirection = direction;
                }
                else
                {
                    float tangentLength;
                    {
                        tangentLength = FUN_004019b0(pov->fRadius * pov->fRadius - radialDistance * radialDistance);
                        NiPoint3 perpendicular(-direction.y, direction.x, 0.0f);
                        perpendicular *= tangentLength;
                        leftDirection = direction * radialDistance + perpendicular;
                        leftDirection.ComputeMagnitude();
                        rightDirection = direction * radialDistance - perpendicular;
                        rightDirection.ComputeMagnitude();
                    }
                }
                tangentData.Count = 2;
                tangentData.Tangents[0].Direction = AD_CCW;
                tangentData.Tangents[0].m_kStartAngle.fCos = leftDirection.x;
                tangentData.Tangents[0].m_kStartAngle.fSin = leftDirection.y;
                tangentData.Tangents[0].m_kEnd.fCos = leftDirection.x;
                tangentData.Tangents[0].m_kEnd.fSin = leftDirection.y;
                tangentData.Tangents[1].Direction = AD_CW;
                tangentData.Tangents[1].m_kStartAngle.fCos = rightDirection.x;
                tangentData.Tangents[1].m_kStartAngle.fSin = rightDirection.y;
                tangentData.Tangents[1].m_kEnd.fCos = rightDirection.x;
                tangentData.Tangents[1].m_kEnd.fSin = rightDirection.y;
                tangentCount = 2;
            }
        }
        if (!tangentCount)
            return true;
        int testedCount = 0;
        failedCount = 0;
        for (int i = 0; i < tangentCount; i++)
        {
            float fScaleMultiplier;
            {
                float discount;
                {
                    POVNode* nextNode;
                    {
                        float cost;
                        {
                            if (pov->eType == 0 && tangentData.Tangents[i].Direction == AD_CW)
                                continue;
                            if (pov->eType == 1 && tangentData.Tangents[i].Direction == AD_CCW)
                                continue;
                            if (node->GetField54() && (node->GetField54()->Node.m_pAvoidNode->eType == 0 ||
                                                       node->GetField54()->Node.m_pAvoidNode->eType == 1))
                            {
                                SineCosine angle = tangentData.Tangents[i].m_kStartAngle - incomingLink->m_kEnd;
                                if (currentNode.Direction == AD_CCW)
                                {
                                    float radians = angle.FUN_006a0840();
                                    if (radians < 0.0)
                                        radians += 6.2831854820251465;
                                    if (radians > 3.4906585216522217)
                                        continue;
                                }
                                else
                                {
                                    float radians = angle.FUN_006a0840();
                                    if (radians > 0.0)
                                        radians -= 6.2831854820251465;
                                    if (radians < -3.4906585216522217)
                                        continue;
                                }
                            }
                            CircularArc sourceArc(incomingLink->m_kEnd, tangentData.Tangents[i].m_kStartAngle,
                                                  currentNode.Direction);
                            NavMeshEdgePoint sourceLocation;
                            if (!node->GetField54())
                            {
                                sourceLocation.m_pLocationNavMesh = Triangles->GetFirstElement().m_pLocationNavMesh;
                                sourceLocation.m_usTriangleID = Triangles->GetFirstElement().m_usTriangleIdentifier;
                                sourceLocation.m_iEdgeIndex = -1;
                                sourceLocation.Location = m_kPathStartPosition;
                            }
                            else
                                sourceLocation = incomingLink->m_kEndPoint;
                            ++testedCount;
                            NavMeshEdgePoint exitLocation;
                            if (!node->GetField54())
                                exitLocation = sourceLocation;
                            else
                            {
                                sourceLocation.m_iEdgeIndex = -1;
                                if (!FUN_006b1e50(sourceLocation, startSphere, sourceArc, &exitLocation))
                                {
                                    ++failedCount;
                                    continue;
                                }
                                if (std::abs((exitLocation.Location - startSphere.Center).z) >= 180.0)
                                {
                                    ++failedCount;
                                    continue;
                                }
                            }
                            NavMeshEdgePoint entryLocation;
                            NiPoint3 destination =
                                endSphere.Center + tangentData.Tangents[i].m_kEnd.MakePointOnCircle(endSphere.Radius);
                            exitLocation.m_iEdgeIndex = -1;
                            discount = 0.0f;
                            if (!FUN_006b25f0(exitLocation, destination, &entryLocation,
                                              currentNode.m_pAvoidNode->eType == 2, pov->eType == 3, discount))
                            {
                                ++failedCount;
                                continue;
                            }
                            if (node->GetField54())
                            {
                                sourceLocation.m_iEdgeIndex = -1;
                                if (!m_bUnderwaterPath && !FUN_006b23d0(sourceLocation, startSphere, sourceArc))
                                {
                                    ++failedCount;
                                    continue;
                                }
                            }
                            NiPoint3 projectedPoint = entryLocation.Location;
                            entryLocation.m_pLocationNavMesh->GetTriangleHeightAtPoint(
                                entryLocation.m_usTriangleID, entryLocation.Location, 3.402823466e38f, 3.402823466e38f,
                                projectedPoint.z);
                            float heightDelta = projectedPoint.z - endSphere.Center.z;
                            if (!((entryLocation.Location.z <
                                       g_TES->UpdateTESState(
                                           entryLocation.Location,
                                           entryLocation.m_pLocationNavMesh->GetCurrentMoveModeType()) ||
                                   heightDelta > -64.0f) &&
                                  heightDelta < 180.0f))
                            {
                                ++failedCount;
                                continue;
                            }
                            fScaleMultiplier = 0.0f;
                            if (!m_bUnderwaterPath &&
                                !CalculatePathCost(currentNode.m_pAvoidNode, pov, exitLocation.Location,
                                                   entryLocation.Location, &fScaleMultiplier))
                                continue;
                            discount *= 0.8999999761581421;
                            FUN_005330e0(discount, 0.0f, 1.0f);
                            cost = node->FUN_006a7f50();
                            if (node->GetField54())
                                cost += sourceArc.FUN_006a07a0(currentNode.m_pAvoidNode->fRadius) * pov->m_fWeight *
                                        (1.0f - discount);
                            cost += fScaleMultiplier * pov->m_fWeight * (1.0f - discount);
                            switch (InsertOrUpdateNode(FUN_0069f900(pov, tangentData.Tangents[i].Direction), cost,
                                                       nextNode))
                            {
                            case 0:
                                SetPOVSearchNode(nextNode, pov, tangentData.Tangents[i].Direction);
                            case 1:
                                nextNode->Link.m_kStartPoint = exitLocation;
                                nextNode->Link.m_kEndPoint = entryLocation;
                                nextNode->Link.m_kStartAngle = tangentData.Tangents[i].m_kStartAngle;
                                nextNode->Link.m_kEnd = tangentData.Tangents[i].m_kEnd;
                                connections->Add(nextNode);
                            }
                        }
                    }
                }
            }
        }
        return testedCount == 0 || testedCount > failedCount;
    }
}

#undef currentNode
#undef incomingLink
#undef centerDelta
#undef xyDistanceSquared
#undef heightSquared
#undef startSphere
#undef endSphere
#undef tangentData
#undef tangentCount
#undef testedCount
#undef direction
#undef leftDirection
#undef sourceArc
#undef sourceLocation
#undef exitLocation
#undef entryLocation
#undef destination
#undef projectedPoint
#undef heightDelta
#undef discount
#undef cost
#undef nextNode
#undef radialDistance
#undef rightDirection
#undef tangentLength
#undef perpendicular

struct FUN_00505c00_shell : public PathingRequest
{
    bool GetFaceTargetAtGoal();
};

// @fnv 0x00505c00
bool FUN_00505c00_shell::GetFaceTargetAtGoal()
{
    return *((bool*)((char*)this + 0x99));
}

struct FUN_00507e10_shell : public PathingRequest
{
    float FUN_00507e10();
};

// @fnv 0x00507e10
float FUN_00507e10_shell::FUN_00507e10()
{
    return *(float*)((char*)this + 0x8c);
}

struct FUN_0069f900_shell : public PathSmootherPOVSearch
{
    unsigned int FUN_0069f900(PathSmootherPOVPoint*, int);
};

// @fnv 0x0069f900
unsigned int FUN_0069f900_shell::FUN_0069f900(PathSmootherPOVPoint* apPOV, int aDirection)
{
    return reinterpret_cast<unsigned int>(apPOV) + aDirection;
}

struct P3
{
    int x, y, z;
};
struct FUN_006a04b0_stand
{
    P3 center;
    float r;
    FUN_006a04b0_stand* SetCenterAndRadius(const P3* c, float radius);
};
// Copies the given P3 into center, stores radius in r, and returns this.
// @fnv 0x006a04b0
FUN_006a04b0_stand* FUN_006a04b0_stand::SetCenterAndRadius(const P3* apCenter, float radius)
{
    center = *apCenter;
    r = radius;
    return this;
}

class NiBound
{
  public:
    char pad[0xc];
    NiBound();
};

// Initializes the object: sets index to -1, zeroes position and a float, constructs NiBound, initializes two AvoidSpheres, and sets a float to 1.0.
// @fnv 0x006ae120
void* __fastcall FUN_006ae120(char* pObject)
{
    *(int*)pObject = -1;
    *(NiPoint3*)(pObject + 4) = NiPoint3::ZERO;
    *(float*)(pObject + 0x10) = 0.0f;
    ((NiBound*)(pObject + 0x14))->NiBound::NiBound();
    ((AvoidSphere*)(pObject + 0x20))->FUN_006815c0();
    ((AvoidSphere*)(pObject + 0x2c))->FUN_006815c0();
    *(float*)(pObject + 0x38) = 1.0f;
    return pObject;
}

struct FUN_006b05d0_shell : public PathingSolution
{
    bool FUN_006b05d0();
};

// @fnv 0x006b05d0
bool FUN_006b05d0_shell::FUN_006b05d0()
{
    return *((bool*)((char*)this + 0x40));
}

struct FUN_006b1df0_shell : public PathSmootherPOVSearch
{
    void SetPOVSearchNode(void*, PathSmootherPOVPoint*, int);
};

struct NiFixedString;
class NiAVObject
{
  public:
    NiFixedString& GetName();
};

// @fnv 0x006b1df0
void FUN_006b1df0_shell::SetPOVSearchNode(void* apNode, PathSmootherPOVPoint* apPOV, int aDirection)
{
    reinterpret_cast<int*>(&reinterpret_cast<NiAVObject*>(apNode)->GetName())[0] = reinterpret_cast<int>(apPOV);
    reinterpret_cast<int*>(&reinterpret_cast<NiAVObject*>(apNode)->GetName())[1] = aDirection;

    *reinterpret_cast<float*>(reinterpret_cast<char*>(apNode) + 4) =
        (*reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(apPOV) + 4) -
         *reinterpret_cast<NiPoint3*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x20c8) + 4))
            .FUN_00457990() *
        0.1f;
}

struct Dummy64
{
    char pad[0x40];
};

struct DummyArr
{
    void* vtbl;
    Dummy64* pBuffer;
    int __thiscall GetBufferElementAddress(unsigned int aiIndex);
};

// @fnv 0x006b30e0
int __thiscall DummyArr::GetBufferElementAddress(unsigned int aiIndex)
{
    return reinterpret_cast<int>(&pBuffer[aiIndex]);
}

struct FUN_006b3160_shell
{
    int pad0;
    char* data;
    char* FUN_006b3160(unsigned int i);
};
// @fnv 0x006b3160
char* FUN_006b3160_shell::FUN_006b3160(unsigned int uiIndex)
{
    return uiIndex * 0x14 + data;
}

// @fnv 0x006b3180
const NavMeshTriangleReference& __fastcall GetFirstElement(const BSSimpleArray<NavMeshTriangleReference, 1024>* pThis)
{
    return pThis->FUN_006b3160(0);
}

// @fnv 0x006b31a0
const NavMeshTriangleReference& __fastcall GetLastElement(const BSSimpleArray<NavMeshTriangleReference, 1024>* pThis)
{
    return pThis->FUN_006b3160(*(const unsigned int*)((const char*)pThis + 8) - 1);
}

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

struct FUN_006b3270_Class
{
    virtual ~FUN_006b3270_Class();
    FUN_00982610_Type m_sub0;
    Date m_date1;
    char m_auiShapeKeys[0x1ff4 - 0x14 - sizeof(Date)];
    Date m_date2;
};

// Destroys the object; the body is empty, so the compiler-generated member destructors do the work.
// @fnv 0x006b3270
FUN_006b3270_Class::~FUN_006b3270_Class()
{}

extern int DAT_0106ba1c;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x006b35a0
void __fastcall InitGlobalObject(GlobalObject_00869f00* _this)
{
    *(int**)_this = &DAT_0106ba1c;
    _this->Clear(true);
}

namespace fnv_006b35f0 {
extern int DAT_0106ba30;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

// @fnv 0x006b35f0
void __fastcall FUN_006b35f0(GlobalObject_00869f00* pThis)
{
    *(int**)pThis = &DAT_0106ba30;
    pThis->Clear(true);
}
}  // namespace fnv_006b35f0

extern int DAT_0106ba44;

// @fnv 0x006b3640
void __fastcall InitSimpleArray(BSSimpleArray<NavMeshEdgeSegment, 1024>* _this)
{
    *(int**)_this = &DAT_0106ba44;
    _this->Clear(true);
}

namespace fnv_006b3710 {
class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x006b3710
void __fastcall FUN_006b3710(GlobalObject_00869f00* pThis)
{
    *(const char**)pThis = "p9k";
    pThis->Clear(true);
}
}  // namespace fnv_006b3710

struct WaitableObject
{
    void FUN_0040f6e0();
};
struct FUN_006b37b0_stand
{
    int* p;
    FUN_006b37b0_stand* SetObject(int* obj);
};
// Stores obj in p and, if non-null, calls FUN_0040f6e0 on the subobject at offset 0x10; returns this.
// @fnv 0x006b37b0
FUN_006b37b0_stand* FUN_006b37b0_stand::SetObject(int* pObject)
{
    p = pObject;
    if (p)
        ((WaitableObject*)((char*)p + 0x10))->FUN_0040f6e0();
    return this;
}

namespace fnv_006b37e0 {
struct NiAVObject
{
    void FUN_00401970();
};

// If the object pointer at pThis is non-null, calls FUN_00401970 on the NiAVObject at offset 0x10 of that pointer.
// @fnv 0x006b37e0
void __fastcall FUN_006b37e0(char** pThis)
{
    if (*pThis)
    {
        ((NiAVObject*)(*pThis + 0x10))->FUN_00401970();
    }
}
}  // namespace fnv_006b37e0

struct EdgeArr
{
    char* FUN_006a1440(unsigned int i);
};
struct FUN_006ced90_stand
{
    int a, b;
    unsigned int count;
    char* GetLastEdge();
};
// @fnv 0x006ced90
char* FUN_006ced90_stand::GetLastEdge()
{
    return ((EdgeArr*)this)->FUN_006a1440(count - 1);
}

namespace fnv_006b3100 {
struct DummyArr
{
    void* m_data;
    void* m_ptr;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    int GetBufferElementAddress(unsigned int);
    int FUN_006b3100();
};

// @fnv 0x006b3100
int DummyArr::FUN_006b3100()
{
    return GetBufferElementAddress(m_iElementCount - 1);
}
}  // namespace fnv_006b3100

struct FUN_006b3120_shell
{
    char m_Pad[4];
    char* m_Array;  // +0x4

    char* __thiscall GetElementAt(unsigned int aiIndex);
};

// @fnv 0x006b3120
char* __thiscall FUN_006b3120_shell::GetElementAt(unsigned int aiIndex)
{
    return m_Array + aiIndex * 0x20;
}

struct FUN_006b3140_shell
{
    int m_00;
    int m_04;
    int m_08;
    void GetElementAt(int);
    void FUN_006b3140();
};

// @fnv 0x006b3140
void FUN_006b3140_shell::FUN_006b3140()
{
    GetElementAt(m_08 - 1);
}

struct FUN_006b3570_shell
{
    void* vtable;
    void FUN_006b3eb0(int, int);
    void* __thiscall FUN_006b3570();
};

extern int DAT_0106ba1c;

// Sets the vtable to DAT_0106ba1c, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x006b3570
void* __thiscall FUN_006b3570_shell::FUN_006b3570()
{
    vtable = &DAT_0106ba1c;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_006b3780_shell
{
    void* __thiscall AllocateScaledBlock(unsigned int size);
};

// Allocates size << 5 bytes via operator new and returns the pointer.
// @fnv 0x006b3780
void* __thiscall FUN_006b3780_shell::AllocateScaledBlock(unsigned int size)
{
    void* p = ::operator new(size << 5);
    return p;
}

struct Dummy_0061bf20
{
    void* vtable;
    void FUN_006b3f40(int, int);
    Dummy_0061bf20* FUN_006b35c0();
};

extern int DAT_0106ba30;

// Sets the vtable to DAT_0106ba30, calls FUN_006b3f40 with 0 and 0, and returns this.
// @fnv 0x006b35c0
Dummy_0061bf20* Dummy_0061bf20::FUN_006b35c0()
{
    vtable = &DAT_0106ba30;
    this->FUN_006b3f40(0, 0);
    return this;
}

struct FUN_006b36b0_shell
{
    void* AllocateBlock(int count);
};

// Allocates count * 64 bytes via operator new and returns the pointer.
// @fnv 0x006b36b0
void* FUN_006b36b0_shell::AllocateBlock(int count)
{
    void* mem = operator new(count * 64);
    return mem;
}

void __cdecl _Deallocate(void*);
struct FUN_006ad660_shell : PathSmootherPOVSearch
{
    void* DestroyPathSmootherPOVSearch(unsigned int);
};
// Destructs the PathSmootherPOVSearch object and frees it when the low bit of flags is set, then returns the object pointer.
// @fnv 0x006ad660
void* FUN_006ad660_shell::DestroyPathSmootherPOVSearch(unsigned int flags)
{
    this->PathSmootherPOVSearch::~PathSmootherPOVSearch();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006aeb70 {
struct BaseS
{
    char _d[8];
    BaseS();
};
struct NiBound
{
    NiBound();
};
struct FUN_006aeb70
{
    BaseS a;
    NiBound b;
    FUN_006aeb70();
};
// Constructs the object, default-constructing its BaseS member and NiBound member.
// @fnv 0x006aeb70
FUN_006aeb70::FUN_006aeb70()
{}
}  // namespace fnv_006aeb70

struct B006815c0
{
    char _d[8];
    B006815c0();
};
struct FUN_006b1d80
{
    B006815c0 m0;
    B006815c0 m1;
    NavMeshEdgePoint m2;
    NavMeshEdgePoint m3;
    FUN_006b1d80();
};
// @fnv 0x006b1d80
FUN_006b1d80::FUN_006b1d80()
{}

extern int DAT_0106ba44;
struct S_006b3610
{
    void* vtable;
    void FUN_006a2130(int, int);
    S_006b3610* FUN_006b3610();
};
// Sets the vtable pointer to DAT_0106ba44, calls FUN_006a2130 with 0, 0, and returns this.
// @fnv 0x006b3610
S_006b3610* S_006b3610::FUN_006b3610()
{
    vtable = &DAT_0106ba44;
    FUN_006a2130(0, 0);
    return this;
}

struct Elem3660
{
    char data[64];
    void FUN_006b3910(int);
};
struct Holder3660
{
    int _0;
    Elem3660* p;
    int FUN_006b3fd0();
    void FUN_006a2630(Elem3660*, int);
    int FUN_006b3660(int);
};
// @fnv 0x006b3660
int Holder3660::FUN_006b3660(int a)
{
    int iIndex = FUN_006b3fd0();
    FUN_006a2630(&p[iIndex], 1);
    p[iIndex].FUN_006b3910(a);
    return iIndex;
}

extern int $SG4390;
struct S006b36e0
{
    void* vtable;
    void FUN_006b4190(int, int);
    S006b36e0* FUN_006b36e0();
};
// Sets the vtable to $SG4390, calls FUN_006b4190 with 0, 0, and returns this.
// @fnv 0x006b36e0
S006b36e0* S006b36e0::FUN_006b36e0()
{
    vtable = &$SG4390;
    FUN_006b4190(0, 0);
    return this;
}

struct H4060
{
    int GetNextIndex();
};
struct H40F0
{
    void ConstructElements(void* p, int i);
};
struct H39A0
{
    void FUN_006b39a0(int a);
};
struct MyHolder
{
    int f0;
    char* f4;
    int FUN_006b3730(int a);
};
// @fnv 0x006b3730
int MyHolder::FUN_006b3730(int a)
{
    int iIndex;
    iIndex = ((H4060*)this)->GetNextIndex();
    ((H40F0*)this)->ConstructElements((void*)(iIndex * 32 + f4), 1);
    ((H39A0*)(iIndex * 32 + f4))->FUN_006b39a0(a);
    return iIndex;
}

namespace fnv_006ad4c0 {
struct FUN_006b31c0
{
    FUN_006b31c0();
    virtual ~FUN_006b31c0();
    char pad[0x2054];
};
struct B006815c0
{
    B006815c0();
    float x, y, z;
};
struct FUN_006b3570
{
    FUN_006b3570();
    ~FUN_006b3570();
    int data[4];
};
struct FUN_006b35c0
{
    FUN_006b35c0();
    ~FUN_006b35c0();
    int data[4];
};
struct FUN_006b3610
{
    FUN_006b3610();
    ~FUN_006b3610();
    int data[4];
};
struct FUN_006b36e0
{
    FUN_006b36e0();
    ~FUN_006b36e0();
    int data[4];
};

struct FUN_006ad4c0 : public FUN_006b31c0
{
    FUN_006ad4c0();
    virtual ~FUN_006ad4c0();
    int i2058;
    int i205c;
    B006815c0 p2060;
    B006815c0 p206c;
    bool b2078;
    int i207c;
    int i2080;
    FUN_006b3570 l2084;
    FUN_006b3570 l2094;
    FUN_006b3570 l20a4;
    FUN_006b3570 l20b4;
    int i20c4;
    int i20c8;
    FUN_006b35c0 l20cc;
    FUN_006b3610 l20dc;
    FUN_006b36e0 l20ec;
    FUN_006b36e0 l20fc;
    int i210c;
};

// @fnv 0x006ad4c0
FUN_006ad4c0::FUN_006ad4c0()
{
    i2058 = 0;
    NiPoint3 m_kPathStartPosition = NiPoint3::ZERO;
    NiPoint3 m_kGoalPosition = NiPoint3::ZERO;
    i207c = 0;
    i2080 = 0;
    i205c = 0;
    i20c4 = 0;
    i20c8 = 0;
    b2078 = false;
    i210c = 0;
}
}  // namespace fnv_006ad4c0

struct PSNode
{
    float m_fPathingCostCur;
    char pad04[0x5c];
    unsigned int uiKey;
    PSNode* pNext;
};
struct FUN_00996840_shell
{
    PSNode* m_ppNodes[2040];
    unsigned int FUN_00996840(unsigned int);
};
struct PSNodePool
{
    PSNode* FUN_006b3d90();
    char pad[0x10];
};
struct PSOpenList
{
    void UnlinkFromList(PSNode*);
};
struct FUN_006b3420_shell
{
    void* pad00;
    PSNodePool kPool;
    FUN_00996840_shell kMap;
    PSOpenList kOpen;
    int InsertOrUpdateNode(unsigned int aiKey, float afCost, PSNode** aRetNode);
};

// @fnv 0x006b3420
int FUN_006b3420_shell::InsertOrUpdateNode(unsigned int aiKey, float afCost, PSNode** aRetNode)
{
    PSNode** pBucketHead = &kMap.m_ppNodes[kMap.FUN_00996840(aiKey)];
    if (*pBucketHead)
    {
        if ((*pBucketHead)->uiKey == aiKey)
        {
            if ((*pBucketHead)->m_fPathingCostCur > afCost)
            {
                *aRetNode = *pBucketHead;
                kOpen.UnlinkFromList(*aRetNode);
                (*aRetNode)->m_fPathingCostCur = afCost;
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            PSNode* pcurrent;
            PSNode* pprev;
            pprev = *pBucketHead;
            pcurrent = (*pBucketHead)->pNext;
            while (pcurrent)
            {
                if (pcurrent->uiKey == aiKey)
                {
                    if (pcurrent->m_fPathingCostCur > afCost)
                    {
                        *aRetNode = pcurrent;
                        kOpen.UnlinkFromList(*aRetNode);
                        (*aRetNode)->m_fPathingCostCur = afCost;
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
                pprev = pcurrent;
                pcurrent = pcurrent->pNext;
            }
        }
    }
    *aRetNode = kPool.FUN_006b3d90();
    (*aRetNode)->uiKey = aiKey;
    (*aRetNode)->m_fPathingCostCur = afCost;
    (*aRetNode)->pNext = *pBucketHead;
    *pBucketHead = *aRetNode;
    return 0;
}

struct BSSimpleArrayActor
{
    unsigned int Add(void*& value);
};

struct FUN_006ae190_shell
{
    void FUN_006ae190();
};

// @fnv 0x006ae190
void FUN_006ae190_shell::FUN_006ae190()
{
    struct POD12
    {
        unsigned int x;
        unsigned int y;
        unsigned int z;
    };

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4) = new PathSmootherPOVPoint;

    reinterpret_cast<unsigned int*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4))[0] = 2;

    *reinterpret_cast<POD12*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 4) =
        *reinterpret_cast<POD12*>(reinterpret_cast<char*>(this) + 0x2060);

    *reinterpret_cast<float*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 0x10) = 0.0f;

    *reinterpret_cast<unsigned short*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 0x48) = 0xffff;

    reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<char*>(this) + 0x20b4)
        ->Add(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4));
}

namespace fnv_006ae280 {
struct BSSimpleArrayActor
{
    unsigned int Add(void*& value);
    unsigned char padding[0x13];
};

struct FUN_006ae280_Position
{
    float x;
    float y;
    float z;
};

struct FUN_006ae280_Smoother
{
    int type;
    FUN_006ae280_Position position;
    float value;
    unsigned char padding[0x34];
    unsigned short flags;
};

struct FUN_006ae280_shell
{
    unsigned char padding0[0x206c];
    FUN_006ae280_Position position;
    unsigned char padding1[0x3c];
    BSSimpleArrayActor actors;
    void* smoother;

    void CreateSmoother();
};

// Allocates a smoother, sets its type to 3, copies this position, zeroes value, sets flags to 0xffff, and adds it to the actors array.
// @fnv 0x006ae280
void FUN_006ae280_shell::CreateSmoother()
{
    this->smoother = new PathSmootherPOVPoint;

    reinterpret_cast<FUN_006ae280_Smoother*>(this->smoother)->type = 3;
    reinterpret_cast<FUN_006ae280_Smoother*>(this->smoother)->position = this->position;
    reinterpret_cast<FUN_006ae280_Smoother*>(this->smoother)->value = 0.0f;
    reinterpret_cast<FUN_006ae280_Smoother*>(this->smoother)->flags = 0xffff;

    this->actors.Add(this->smoother);
}
}  // namespace fnv_006ae280

class Key6AE
{
  public:
    Key6AE* Copy(const Key6AE* pkOther);

    int unk00;
    int unk04;
};

class Data6AE
{
  public:
    Data6AE& operator=(const Data6AE& kOther);

    int unk00;
    int unk04;
    int unk08;
};

class Entry6AE
{
  public:
    Entry6AE();

    Key6AE m_kControlPoint;
    Data6AE m_kData;
    int m_iCountA;
    int m_iCountB;
    int m_iIndex;
};

class List6AE
{
  public:
    int GetCount();
    int Add(Entry6AE* pkEntry);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class Manager6AE
{
  public:
    void AddEntry(const Key6AE* pkKey, const Data6AE& kData);

    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC;
    int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C;
    int unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C;
    int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C;
    int unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C;
    int unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC;
    int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC;
    int unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC;
    int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C;
    int unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C;
    int unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C;
    int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C;
    int unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC;
    int unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C;
    int unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C;
    int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C;
    int unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C;
    int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C;
    int unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC;
    int unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC;
    int unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C;
    int unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C;
    int unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C;
    int unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C;
    int unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C;
    int unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC;
    int unk1CC0, unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC;
    int unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC;
    int unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C;
    int unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C;
    int unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C;
    int unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C;
    int unk1D80, unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C;
    int unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC;
    int unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC;
    int unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC;
    int unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C;
    int unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C;
    int unk1E40, unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C;
    int unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C;
    int unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C;
    int unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC;
    int unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC;
    int unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC;
    int unk1F00, unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C;
    int unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C;
    int unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C;
    int unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C;
    int unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C;
    int unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC;
    int unk1FC0, unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC;
    int unk1FE0, unk1FE4, unk1FE8, unk1FEC, unk1FF0, unk1FF4, unk1FF8, unk1FFC;
    int unk2000, unk2004, unk2008, unk200C, unk2010, unk2014, unk2018, unk201C;
    int unk2020, unk2024, unk2028, unk202C, unk2030, unk2034, unk2038, unk203C;
    int unk2040, unk2044, unk2048, unk204C, unk2050, unk2054, unk2058, unk205C;
    int unk2060, unk2064, unk2068, unk206C, unk2070, unk2074, unk2078, unk207C;
    int unk2080, unk2084, unk2088, unk208C, unk2090, unk2094, unk2098, unk209C;
    int unk20A0, unk20A4, unk20A8, unk20AC, unk20B0, unk20B4, unk20B8, unk20BC;
    int unk20C0, unk20C4, unk20C8, unk20CC, unk20D0, unk20D4, unk20D8, unk20DC;
    int unk20E0, unk20E4, unk20E8;
    List6AE m_kEntries;
    List6AE m_kOther;
};

// Builds an Entry6AE from pkKey and kData, fills its counts from m_kOther and m_kEntries, sets index -1, and appends it to m_kEntries.
// @fnv 0x006aea90
void Manager6AE::AddEntry(const Key6AE* pkKey, const Data6AE& kData)
{
    Entry6AE kEntry;
    kEntry.m_kControlPoint.Copy(pkKey);
    kEntry.m_kData = kData;
    kEntry.m_iCountA = m_kOther.GetCount();
    kEntry.m_iCountB = m_kEntries.GetCount();
    kEntry.m_iIndex = -1;
    m_kEntries.Add(&kEntry);
}

struct Point17
{
    float x, y, z;
    Point17 operator+(const Point17&) const;
    Point17 operator-(const Point17&) const;
    void FUN_004a0c10();
    Point17& operator*=(float);
    Point17& Subtract(const Point17&);
};
struct Angle17
{
    float cosine, sine;
    Point17 MakePointOnCircle(float) const;
    Angle17& operator=(const Angle17&);
};
struct Arc17
{
    Angle17 start, end;
    ANGLE_DIRECTION direction;
    Arc17(const Angle17&, const Angle17&, ANGLE_DIRECTION);
    Arc17(const Arc17&);
};
struct Sphere17
{
    Point17 center;
    float radius;
    Sphere17(const Point17&, float);
};
struct LinkArrayOps
{
    const NavMeshEdgeSegment& FUN_006b3100();
};
struct LocationOps17
{
    NavMeshEdgePoint& FUN_006cf900(const NavMeshEdgePoint&);
};
struct MeshOps17
{
    unsigned int FUN_0059bb30();
};
struct Link17
{
    Angle17 m0, m1;
    NavMeshEdgePoint m2, m3;
    Link17();
};
int FUN_006bb570(const Sphere17&, const Sphere17&, ANGLE_DIRECTION, SphereTangents&);
struct LastNodeSearch17 : PathSmootherPOVSearch
{
    bool FUN_006b1e50(const NavMeshEdgePoint&, Sphere17&, Arc17, NavMeshEdgePoint*);
    bool FUN_006b23d0(const NavMeshEdgePoint&, Sphere17&, Arc17);
    bool FUN_006b25f0(const NavMeshEdgePoint&, const Point17&, NavMeshEdgePoint*, bool, bool, float&);
    bool FindPath(const NavMeshEdgePoint&, const Point17&, NavMeshEdgePoint*, float&);
    bool FUN_006b2c00(PathSmootherPOVPoint*, PathSmootherPOVPoint*, NiPoint3&, const Point17&, float&);
    bool TryAddLastNode();
};
// Computes tangents between the current node and the target, validates the path, adjusts the endpoint for water, and appends a link and node.
// @fnv 0x006b1970
bool LastNodeSearch17::TryAddLastNode()
{
    if (Links.FUN_0076b610())
        return false;
    const PathSmootherPOVAvoidanceNode& h = Nodes.GetLastEdge();
    const NavMeshEdgeSegment& eb = ((LinkArrayOps*)&Links)->FUN_006b3100();
    Sphere17 f((const Point17&)h.m_pAvoidNode->Center, h.m_pAvoidNode->fRadius);
    Sphere17 k((const Point17&)m_pGoalPoint->Center, m_pGoalPoint->fRadius);
    SphereTangents b;
    int q = FUN_006bb570(f, k, h.Direction, b);
    if (!q)
        return false;
    Arc17 c((const Angle17&)eb.m_kEnd, (const Angle17&)b.Tangents[0].m_kStartAngle, h.Direction);
    NavMeshEdgePoint cf;
    if (!FUN_006b1e50(eb.m_kEndPoint, f, c, &cf))
        return false;
    if (!FUN_006b23d0(eb.m_kEndPoint, f, c))
        return false;
    NavMeshEdgePoint s;
    Point17 ba = k.center + ((const Angle17&)b.Tangents[0].m_kEnd).MakePointOnCircle(k.radius);
    cf.m_iEdgeIndex = -1;
    float p = 0;
    if (pRequest->GetFloatAtOffset68() >= 100.0)
    {
        if (FUN_006b25f0(cf, ba, &s, false, true, p))
        {
            float radius = 0;
            if (!FUN_006b2c00(h.m_pAvoidNode, m_pGoalPoint, cf.Location, ba, radius))
                return false;
        }
    }
    else
    {
        if (FindPath(cf, ba, &s, p))
        {
            float radius = 0;
            if (!FUN_006b2c00(h.m_pAvoidNode, m_pGoalPoint, cf.Location, ba, radius))
                return false;
        }
    }
    if (m_bUnderwaterPath)
    {
        float water = g_TES->UpdateTESState(s.Location, ((MeshOps17*)s.m_pLocationNavMesh)->FUN_0059bb30());
        if (water >= s.Location.z)
            s.Location.z = water;
    }
    Point17 l = ba - (const Point17&)cf.Location;
    l.FUN_004a0c10();
    l *= pRequest->GetFloatAtOffset68() * 2.0f;
    ((Point17&)s.Location).Subtract(l);
    Link17 a;
    ((LocationOps17*)&a.m2)->FUN_006cf900(cf);
    ((LocationOps17*)&a.m3)->FUN_006cf900(s);
    ((Angle17&)a.m0) = (const Angle17&)b.Tangents[0].m_kStartAngle;
    ((Angle17&)a.m1) = (const Angle17&)b.Tangents[0].m_kEnd;
    Links.Add((const NavMeshEdgeSegment&)a);
    PathSmootherPOVAvoidanceNode i;
    i.m_pAvoidNode = m_pGoalPoint;
    i.m_fPathDistance = 0;
    i.Direction = b.Tangents[0].Direction;
    Nodes.Add(i);
    return true;
}

// @fnv 0x006b2fc0
bool PathSmootherPOVSearch::FUN_006b2fc0(BSSimpleArray<NavMeshTriangleEdgeReference>* apEdges)
{
    if (apEdges == 0)
        return false;
    bool bStateChanged = false;
    for (unsigned int i = 0; i < Edges->GetSize(); i++)
    {
        NiPoint3 kStartPt;
        NiPoint3 kEndPt;
        Edges->operator[](i).m_pLocationNavMesh->FUN_0068f0c0(Edges->operator[](i).m_usTriangleIdentifier,
                                                              Edges->operator[](i).m_iEdgeIndex, kStartPt, kEndPt);
        if ((kStartPt - kEndPt).FUN_004a7290() < pRequest->GetFloatAtOffset68() * pRequest->GetFloatAtOffset68() * 4.0)
        {
            apEdges->Add(Edges->operator[](i));
            bStateChanged = true;
        }
    }
    return bStateChanged;
}

struct FUN_006b31c0_sub04
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    FUN_006b31c0_sub04();
    ~FUN_006b31c0_sub04();
};

struct FUN_006b31c0_sub14
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
    int unk1C04;
    int unk1C08;
    int unk1C0C;
    int unk1C10;
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    int unk1C30;
    int unk1C34;
    int unk1C38;
    int unk1C3C;
    int unk1C40;
    int unk1C44;
    int unk1C48;
    int unk1C4C;
    int unk1C50;
    int unk1C54;
    int unk1C58;
    int unk1C5C;
    int unk1C60;
    int unk1C64;
    int unk1C68;
    int unk1C6C;
    int unk1C70;
    int unk1C74;
    int unk1C78;
    int unk1C7C;
    int unk1C80;
    int unk1C84;
    int unk1C88;
    int unk1C8C;
    int unk1C90;
    int unk1C94;
    int unk1C98;
    int unk1C9C;
    int unk1CA0;
    int unk1CA4;
    int unk1CA8;
    int unk1CAC;
    int unk1CB0;
    int unk1CB4;
    int unk1CB8;
    int unk1CBC;
    int unk1CC0;
    int unk1CC4;
    int unk1CC8;
    int unk1CCC;
    int unk1CD0;
    int unk1CD4;
    int unk1CD8;
    int unk1CDC;
    int unk1CE0;
    int unk1CE4;
    int unk1CE8;
    int unk1CEC;
    int unk1CF0;
    int unk1CF4;
    int unk1CF8;
    int unk1CFC;
    int unk1D00;
    int unk1D04;
    int unk1D08;
    int unk1D0C;
    int unk1D10;
    int unk1D14;
    int unk1D18;
    int unk1D1C;
    int unk1D20;
    int unk1D24;
    int unk1D28;
    int unk1D2C;
    int unk1D30;
    int unk1D34;
    int unk1D38;
    int unk1D3C;
    int unk1D40;
    int unk1D44;
    int unk1D48;
    int unk1D4C;
    int unk1D50;
    int unk1D54;
    int unk1D58;
    int unk1D5C;
    int unk1D60;
    int unk1D64;
    int unk1D68;
    int unk1D6C;
    int unk1D70;
    int unk1D74;
    int unk1D78;
    int unk1D7C;
    int unk1D80;
    int unk1D84;
    int unk1D88;
    int unk1D8C;
    int unk1D90;
    int unk1D94;
    int unk1D98;
    int unk1D9C;
    int unk1DA0;
    int unk1DA4;
    int unk1DA8;
    int unk1DAC;
    int unk1DB0;
    int unk1DB4;
    int unk1DB8;
    int unk1DBC;
    int unk1DC0;
    int unk1DC4;
    int unk1DC8;
    int unk1DCC;
    int unk1DD0;
    int unk1DD4;
    int unk1DD8;
    int unk1DDC;
    int unk1DE0;
    int unk1DE4;
    int unk1DE8;
    int unk1DEC;
    int unk1DF0;
    int unk1DF4;
    int unk1DF8;
    int unk1DFC;
    int unk1E00;
    int unk1E04;
    int unk1E08;
    int unk1E0C;
    int unk1E10;
    int unk1E14;
    int unk1E18;
    int unk1E1C;
    int unk1E20;
    int unk1E24;
    int unk1E28;
    int unk1E2C;
    int unk1E30;
    int unk1E34;
    int unk1E38;
    int unk1E3C;
    int unk1E40;
    int unk1E44;
    int unk1E48;
    int unk1E4C;
    int unk1E50;
    int unk1E54;
    int unk1E58;
    int unk1E5C;
    int unk1E60;
    int unk1E64;
    int unk1E68;
    int unk1E6C;
    int unk1E70;
    int unk1E74;
    int unk1E78;
    int unk1E7C;
    int unk1E80;
    int unk1E84;
    int unk1E88;
    int unk1E8C;
    int unk1E90;
    int unk1E94;
    int unk1E98;
    int unk1E9C;
    int unk1EA0;
    int unk1EA4;
    int unk1EA8;
    int unk1EAC;
    int unk1EB0;
    int unk1EB4;
    int unk1EB8;
    int unk1EBC;
    int unk1EC0;
    int unk1EC4;
    int unk1EC8;
    int unk1ECC;
    int unk1ED0;
    int unk1ED4;
    int unk1ED8;
    int unk1EDC;
    int unk1EE0;
    int unk1EE4;
    int unk1EE8;
    int unk1EEC;
    int unk1EF0;
    int unk1EF4;
    int unk1EF8;
    int unk1EFC;
    int unk1F00;
    int unk1F04;
    int unk1F08;
    int unk1F0C;
    int unk1F10;
    int unk1F14;
    int unk1F18;
    int unk1F1C;
    int unk1F20;
    int unk1F24;
    int unk1F28;
    int unk1F2C;
    int unk1F30;
    int unk1F34;
    int unk1F38;
    int unk1F3C;
    int unk1F40;
    int unk1F44;
    int unk1F48;
    int unk1F4C;
    int unk1F50;
    int unk1F54;
    int unk1F58;
    int unk1F5C;
    int unk1F60;
    int unk1F64;
    int unk1F68;
    int unk1F6C;
    int unk1F70;
    int unk1F74;
    int unk1F78;
    int unk1F7C;
    int unk1F80;
    int unk1F84;
    int unk1F88;
    int unk1F8C;
    int unk1F90;
    int unk1F94;
    int unk1F98;
    int unk1F9C;
    int unk1FA0;
    int unk1FA4;
    int unk1FA8;
    int unk1FAC;
    int unk1FB0;
    int unk1FB4;
    int unk1FB8;
    int unk1FBC;
    int unk1FC0;
    int unk1FC4;
    int unk1FC8;
    int unk1FCC;
    int unk1FD0;
    int unk1FD4;
    int unk1FD8;
    int unk1FDC;
    FUN_006b31c0_sub14();
    ~FUN_006b31c0_sub14();
};

struct FUN_006b31c0_sub1ff4
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    FUN_006b31c0_sub1ff4();
};

class FUN_006b31c0_cls
{
  public:
    virtual ~FUN_006b31c0_cls();
    FUN_006b31c0_sub04 m_04;
    FUN_006b31c0_sub14 m_14;
    FUN_006b31c0_sub1ff4 m_1ff4;
    int m_2048;
    int m_204c;
    int m_2050;
    char m_2054;
    FUN_006b31c0_cls();
};

// Initializes m_2048, m_204c, m_2050 and m_2054 to zero.
// @fnv 0x006b31c0
FUN_006b31c0_cls::FUN_006b31c0_cls()
{
    m_2048 = 0;
    m_204c = 0;
    m_2050 = 0;
    m_2054 = 0;
}

struct PSNodeSlot
{
    void InsertSorted(POVNode* pNode);
};

struct PSSearchView
{
    void* vtbl;
    char unk0004[0x1ff0];
    PSNodeSlot m_1ff4;
    char unk1ff5[0x2050 - 0x1ff5];
    POVNode* m_2050;
    int InsertOrUpdateNode(unsigned int aiKey, float afCost, POVNode*& aRetNode);
    POVNode* InsertNode(unsigned int aiKey, const PathSmootherPOVAvoidanceNode& aNode, float afCost);
};

// @fnv 0x006b32f0
POVNode* PSSearchView::InsertNode(unsigned int aiKey, const PathSmootherPOVAvoidanceNode& aNode, float afCost)
{
    POVNode* pNode;
    switch (InsertOrUpdateNode(aiKey, 0.0f, pNode))
    {
    case 0:
        pNode->m_fPathingCostCur = afCost;
        pNode->Node = aNode;
        m_1ff4.InsertSorted(pNode);
        m_2050 = pNode;
        return pNode;
    case 1:
        return pNode;
    case 2:
        return 0;
    default:
        return 0;
    }
}

struct FUN_006b3380_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char v3(int);
};

FUN_006b3380_obj* FUN_00b00a00();
int FUN_0040fc90();

struct FUN_006b3380_shell : public PathSmootherPOVSearch
{
    void* FUN_006b3a30();
    void CopyNodeListToArrays(void* cur, BSSimpleArray<PathSmootherPOVAvoidanceNode>* nodes,
                              BSSimpleArray<NavMeshEdgeSegment>* links);
    bool FUN_006b3380(BSSimpleArray<PathSmootherPOVAvoidanceNode>* nodes, BSSimpleArray<NavMeshEdgeSegment>* links,
                      bool bUseCached);
};

// @fnv 0x006b3380
bool FUN_006b3380_shell::FUN_006b3380(BSSimpleArray<PathSmootherPOVAvoidanceNode>* nodes,
                                      BSSimpleArray<NavMeshEdgeSegment>* links, bool bUseCached)
{
    bool result2;
    void* p4;
    void* cur;
    searchState[0x2050] = FUN_00b00a00()->v3(FUN_0040fc90());
    p4 = FUN_006b3a30();
    if (p4 != 0)
    {
        result2 = true;
        cur = p4;
    }
    else if (bUseCached)
    {
        result2 = false;
        cur = *(void**)&searchState[0x2044];
    }
    else
    {
        result2 = false;
        cur = 0;
    }
    if (cur != 0)
        CopyNodeListToArrays(cur, nodes, links);
    return result2;
}

struct NiPoint3Cmp
{
    float x, y, z;
    bool IsEqual(const NiPoint3& other);
};
NiPoint3 operator*(float scale, const NiPoint3& point);

// @fnv 0x006ba550
NiPoint3 FUN_006ba550(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d)
{
    if (((NiPoint3Cmp*)&a)->IsEqual(b))
        return a;
    float fB = (c.x - b.x) * (d.y - b.y) - (c.y - b.y) * (d.x - b.x);
    float fA2 = (c.x - a.x) * (d.y - a.y) - (c.y - a.y) * (d.x - a.x);
    float fRatio = fA2 / (fA2 - fB);
    NiPoint3 kResult3 = a + fRatio * (b - a);
    if (fB * fA2 > 0.0)
    {
        if ((kResult3 - a).FUN_004a7290() < (kResult3 - b).FUN_004a7290())
            return a;
        else
            return b;
    }
    else
    {
        return kResult3;
    }
}

namespace AvoidNodes {
struct Vec
{
    float x, y, z;
    Vec FUN_00439e90(const Vec&) const;
    Vec FUN_00439ef0(const Vec&) const;
    Vec ApplyScaled(float) const;
    Vec FUN_004b3800(const Vec&) const;
    float FUN_00457990();
};
extern const Vec DAT_011a9484;
extern const float DAT_01016248, DAT_0101df44, DAT_01016410;
extern const double DAT_010290c0, DAT_010290b0;
struct FUN_006ae120
{
    int type;
    Vec center;
    float radius;
    int unk14, unk18, unk1c;
    Vec edge1, edge2;
    float cost;
    unsigned int thisSide, otherSide, avoidIndex;
    unsigned short vertex;
    FUN_006ae120();
};
struct NodeList
{
    void FUN_007cb2e0(FUN_006ae120*&);
};
struct Request
{
    bool FUN_006a7980();
};
struct Search : PathSmootherPOVSearch
{
    void FUN_006ae190();
    void BuildPOVLinks();
    void CreateSmoother();
    void FUN_006aefc0();
    void FUN_006af2b0();
    void FUN_006af500();
    void AddAvoidanceNodes();
};
// Runs the search steps, then if the request passes, creates three type-4 avoidance nodes (center, left, right) and adds each to both node lists.
// @fnv 0x006adcb0
void Search::AddAvoidanceNodes()
{
    FUN_006ae190();
    BuildPOVLinks();
    CreateSmoother();
    FUN_006aefc0();
    FUN_006af2b0();
    FUN_006af500();
    if (((Request*)pRequest)->FUN_006a7980())
    {
        FUN_006ae120* centerSlot13 = new FUN_006ae120;
        centerSlot13->type = 4;
        centerSlot13->center =
            ((Vec&)m_kPathStartPosition).FUN_00439e90((Vec&)m_kGoalPosition).ApplyScaled(DAT_01016248);
        centerSlot13->radius =
            ((Vec&)m_kPathStartPosition).FUN_00439ef0((Vec&)m_kGoalPosition).FUN_00457990() * DAT_010290c0;
        centerSlot13->vertex = 0xffff;
        centerSlot13->cost = DAT_01016410;
        ((NodeList*)&m_kPathPoints)->FUN_007cb2e0(centerSlot13);
        ((NodeList*)&m_kRequestPathPoints)->FUN_007cb2e0(centerSlot13);
        Vec direction = ((Vec&)m_kPathStartPosition).FUN_00439ef0((Vec&)m_kGoalPosition);
        Vec perpendicularSlot2 = DAT_011a9484.FUN_004b3800(direction);
        FUN_006ae120* leftSlot15 = new FUN_006ae120;
        leftSlot15->type = 4;
        leftSlot15->center = ((Vec&)m_kGoalPosition)
                                 .FUN_00439e90(direction.ApplyScaled(DAT_0101df44))
                                 .FUN_00439e90(perpendicularSlot2.ApplyScaled(DAT_0101df44));
        leftSlot15->radius =
            ((Vec&)m_kPathStartPosition).FUN_00439ef0((Vec&)m_kGoalPosition).FUN_00457990() * DAT_010290b0;
        leftSlot15->vertex = 0xffff;
        leftSlot15->cost = DAT_01016410;
        ((NodeList*)&m_kPathPoints)->FUN_007cb2e0(leftSlot15);
        ((NodeList*)&m_kRequestPathPoints)->FUN_007cb2e0(leftSlot15);
        FUN_006ae120* rightSlot10 = new FUN_006ae120;
        rightSlot10->type = 4;
        rightSlot10->center = ((Vec&)m_kGoalPosition)
                                  .FUN_00439e90(direction.ApplyScaled(DAT_0101df44))
                                  .FUN_00439ef0(perpendicularSlot2.ApplyScaled(DAT_0101df44));
        rightSlot10->radius =
            ((Vec&)m_kPathStartPosition).FUN_00439ef0((Vec&)m_kGoalPosition).FUN_00457990() * DAT_010290b0;
        rightSlot10->vertex = 0xffff;
        rightSlot10->cost = DAT_01016410;
        ((NodeList*)&m_kPathPoints)->FUN_007cb2e0(rightSlot10);
        ((NodeList*)&m_kRequestPathPoints)->FUN_007cb2e0(rightSlot10);
    }
}
}

class AvoidSphereExt : public AvoidSphere
{
  public:
    int FUN_007af430();
};

class AvoidNodeArray
{
  public:
    unsigned int GetCount();
    AvoidSphere* At(unsigned int);
};

class AvoidNodeArrayHolder
{
  public:
    void* unk00;
    AvoidNodeArrayHolder(BSSimpleArray<void*>*);
    ~AvoidNodeArrayHolder();
    AvoidNodeArray* Get();
};

extern const NiPoint3 DAT_011f426c;

struct FUN_006aefc0_cls : public PathSmootherPOVSearch
{
    void FUN_006aefc0();
};

// @fnv 0x006aefc0
void FUN_006aefc0_cls::FUN_006aefc0()
{
    AvoidNodeArrayHolder holder(this->pRequest->GetString());
    if (holder.Get() != 0)
    {
        for (unsigned int i = 0; i < holder.Get()->GetCount(); i++)
        {
            AvoidSphereExt* avoid = (AvoidSphereExt*)holder.Get()->At(i);
            PathSmootherPOVPoint* cur = new PathSmootherPOVPoint();
            cur->eType = 4;
            cur->m_kFirstEdge = DAT_011f426c;
            cur->m_kSecondEdge = DAT_011f426c;
            cur->Center = avoid->FUN_006815c0();
            cur->m_fWeight = 1.0f;
            cur->fRadius = (float)(avoid->GetRadius() + this->pRequest->GetFloatAtOffset68() * 1.2f);
            cur->m_uiReferenceIndex = 0xffffffff;
            cur->m_uiCompositeId = i;
            this->m_kPathPoints.Add(cur);
            this->m_kRequestPathPoints.Add(cur);

            if (avoid->FUN_007af430() == 2)
            {
                PathSmootherPOVPoint* pov2 = new PathSmootherPOVPoint();
                pov2->eType = 5;
                pov2->m_kFirstEdge = DAT_011f426c;
                pov2->m_kSecondEdge = DAT_011f426c;
                pov2->Center = avoid->FUN_006815c0();
                pov2->m_fWeight = 10.0f;
                pov2->fRadius = (float)(avoid->GetRadius() * 0.25 + this->pRequest->GetFloatAtOffset68() * 1.2f);
                pov2->m_uiReferenceIndex = 0xffffffff;
                pov2->m_uiCompositeId = i;
                this->m_kPathPoints.Add(pov2);
                this->m_kRequestPathPoints.Add(pov2);
            }
        }
    }
}

struct Vec
{
    float x, y, z;
    Vec operator-(const Vec&) const;
    Vec Cross(const Vec&) const;
};
struct Edge
{
    unsigned short a, b;
    Edge();
};
struct Mesh
{
    Edge GetEdge(unsigned short, int);
    const Vec& Vertex(unsigned short);
    bool Previous(unsigned short, int, Mesh**, unsigned short*, int*);
};
struct Handle
{
    Mesh* mesh;
    unsigned short tri;
    int edge;
    Handle(Mesh*, unsigned short, int);
};
struct Vertex
{
    Mesh* mesh;
    unsigned short index;
    Vertex(Mesh*, unsigned short);
    bool Equals(const Vertex&) const;
};
struct Link
{
    Mesh* mesh;
    unsigned short tri;
    int edge;
};
struct Links
{
    unsigned int Size() const;
    Link& At(unsigned int);
};
struct Triangles
{
    Link* At(int) const;
};
struct VertInfo
{
    Vertex vertex;
    Handle edge;
    unsigned int other, thisSide, pov;
};
struct Verts
{
    int vtable;
    VertInfo* data;
    unsigned int size, capacity;
    void Clear(bool);
    unsigned int Size() const;
    Vertex& Last();
    VertInfo& GetElementAt(unsigned int);
};
struct POV
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    unsigned int other;
};
struct POVPointerArray
{
    int vtable;
    POV** data;
    unsigned int size, capacity;
    POV*& FUN_00877a30(unsigned int);
};
struct Smoother
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111c;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112c;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113c;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114c;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115c;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116c;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117c;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118c;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119c;
    int unk11a0;
    int unk11a4;
    int unk11a8;
    int unk11ac;
    int unk11b0;
    int unk11b4;
    int unk11b8;
    int unk11bc;
    int unk11c0;
    int unk11c4;
    int unk11c8;
    int unk11cc;
    int unk11d0;
    int unk11d4;
    int unk11d8;
    int unk11dc;
    int unk11e0;
    int unk11e4;
    int unk11e8;
    int unk11ec;
    int unk11f0;
    int unk11f4;
    int unk11f8;
    int unk11fc;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120c;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121c;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122c;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123c;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124c;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125c;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126c;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127c;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128c;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129c;
    int unk12a0;
    int unk12a4;
    int unk12a8;
    int unk12ac;
    int unk12b0;
    int unk12b4;
    int unk12b8;
    int unk12bc;
    int unk12c0;
    int unk12c4;
    int unk12c8;
    int unk12cc;
    int unk12d0;
    int unk12d4;
    int unk12d8;
    int unk12dc;
    int unk12e0;
    int unk12e4;
    int unk12e8;
    int unk12ec;
    int unk12f0;
    int unk12f4;
    int unk12f8;
    int unk12fc;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130c;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131c;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132c;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133c;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134c;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135c;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136c;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137c;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138c;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139c;
    int unk13a0;
    int unk13a4;
    int unk13a8;
    int unk13ac;
    int unk13b0;
    int unk13b4;
    int unk13b8;
    int unk13bc;
    int unk13c0;
    int unk13c4;
    int unk13c8;
    int unk13cc;
    int unk13d0;
    int unk13d4;
    int unk13d8;
    int unk13dc;
    int unk13e0;
    int unk13e4;
    int unk13e8;
    int unk13ec;
    int unk13f0;
    int unk13f4;
    int unk13f8;
    int unk13fc;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140c;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141c;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142c;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143c;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145c;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146c;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147c;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148c;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149c;
    int unk14a0;
    int unk14a4;
    int unk14a8;
    int unk14ac;
    int unk14b0;
    int unk14b4;
    int unk14b8;
    int unk14bc;
    int unk14c0;
    int unk14c4;
    int unk14c8;
    int unk14cc;
    int unk14d0;
    int unk14d4;
    int unk14d8;
    int unk14dc;
    int unk14e0;
    int unk14e4;
    int unk14e8;
    int unk14ec;
    int unk14f0;
    int unk14f4;
    int unk14f8;
    int unk14fc;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150c;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151c;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152c;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153c;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154c;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155c;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156c;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157c;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158c;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159c;
    int unk15a0;
    int unk15a4;
    int unk15a8;
    int unk15ac;
    int unk15b0;
    int unk15b4;
    int unk15b8;
    int unk15bc;
    int unk15c0;
    int unk15c4;
    int unk15c8;
    int unk15cc;
    int unk15d0;
    int unk15d4;
    int unk15d8;
    int unk15dc;
    int unk15e0;
    int unk15e4;
    int unk15e8;
    int unk15ec;
    int unk15f0;
    int unk15f4;
    int unk15f8;
    int unk15fc;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160c;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161c;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162c;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163c;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164c;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165c;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166c;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167c;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168c;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169c;
    int unk16a0;
    int unk16a4;
    int unk16a8;
    int unk16ac;
    int unk16b0;
    int unk16b4;
    int unk16b8;
    int unk16bc;
    int unk16c0;
    int unk16c4;
    int unk16c8;
    int unk16cc;
    int unk16d0;
    int unk16d4;
    int unk16d8;
    int unk16dc;
    int unk16e0;
    int unk16e4;
    int unk16e8;
    int unk16ec;
    int unk16f0;
    int unk16f4;
    int unk16f8;
    int unk16fc;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170c;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171c;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172c;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173c;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174c;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175c;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176c;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177c;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178c;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179c;
    int unk17a0;
    int unk17a4;
    int unk17a8;
    int unk17ac;
    int unk17b0;
    int unk17b4;
    int unk17b8;
    int unk17bc;
    int unk17c0;
    int unk17c4;
    int unk17c8;
    int unk17cc;
    int unk17d0;
    int unk17d4;
    int unk17d8;
    int unk17dc;
    int unk17e0;
    int unk17e4;
    int unk17e8;
    int unk17ec;
    int unk17f0;
    int unk17f4;
    int unk17f8;
    int unk17fc;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180c;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181c;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182c;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183c;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184c;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185c;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186c;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187c;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188c;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189c;
    int unk18a0;
    int unk18a4;
    int unk18a8;
    int unk18ac;
    int unk18b0;
    int unk18b4;
    int unk18b8;
    int unk18bc;
    int unk18c0;
    int unk18c4;
    int unk18c8;
    int unk18cc;
    int unk18d0;
    int unk18d4;
    int unk18d8;
    int unk18dc;
    int unk18e0;
    int unk18e4;
    int unk18e8;
    int unk18ec;
    int unk18f0;
    int unk18f4;
    int unk18f8;
    int unk18fc;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190c;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191c;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192c;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193c;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194c;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195c;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196c;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197c;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198c;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199c;
    int unk19a0;
    int unk19a4;
    int unk19a8;
    int unk19ac;
    int unk19b0;
    int unk19b4;
    int unk19b8;
    int unk19bc;
    int unk19c0;
    int unk19c4;
    int unk19c8;
    int unk19cc;
    int unk19d0;
    int unk19d4;
    int unk19d8;
    int unk19dc;
    int unk19e0;
    int unk19e4;
    int unk19e8;
    int unk19ec;
    int unk19f0;
    int unk19f4;
    int unk19f8;
    int unk19fc;
    int unk1a00;
    int unk1a04;
    int unk1a08;
    int unk1a0c;
    int unk1a10;
    int unk1a14;
    int unk1a18;
    int unk1a1c;
    int unk1a20;
    int unk1a24;
    int unk1a28;
    int unk1a2c;
    int unk1a30;
    int unk1a34;
    int unk1a38;
    int unk1a3c;
    int unk1a40;
    int unk1a44;
    int unk1a48;
    int unk1a4c;
    int unk1a50;
    int unk1a54;
    int unk1a58;
    int unk1a5c;
    int unk1a60;
    int unk1a64;
    int unk1a68;
    int unk1a6c;
    int unk1a70;
    int unk1a74;
    int unk1a78;
    int unk1a7c;
    int unk1a80;
    int unk1a84;
    int unk1a88;
    int unk1a8c;
    int unk1a90;
    int unk1a94;
    int unk1a98;
    int unk1a9c;
    int unk1aa0;
    int unk1aa4;
    int unk1aa8;
    int unk1aac;
    int unk1ab0;
    int unk1ab4;
    int unk1ab8;
    int unk1abc;
    int unk1ac0;
    int unk1ac4;
    int unk1ac8;
    int unk1acc;
    int unk1ad0;
    int unk1ad4;
    int unk1ad8;
    int unk1adc;
    int unk1ae0;
    int unk1ae4;
    int unk1ae8;
    int unk1aec;
    int unk1af0;
    int unk1af4;
    int unk1af8;
    int unk1afc;
    int unk1b00;
    int unk1b04;
    int unk1b08;
    int unk1b0c;
    int unk1b10;
    int unk1b14;
    int unk1b18;
    int unk1b1c;
    int unk1b20;
    int unk1b24;
    int unk1b28;
    int unk1b2c;
    int unk1b30;
    int unk1b34;
    int unk1b38;
    int unk1b3c;
    int unk1b40;
    int unk1b44;
    int unk1b48;
    int unk1b4c;
    int unk1b50;
    int unk1b54;
    int unk1b58;
    int unk1b5c;
    int unk1b60;
    int unk1b64;
    int unk1b68;
    int unk1b6c;
    int unk1b70;
    int unk1b74;
    int unk1b78;
    int unk1b7c;
    int unk1b80;
    int unk1b84;
    int unk1b88;
    int unk1b8c;
    int unk1b90;
    int unk1b94;
    int unk1b98;
    int unk1b9c;
    int unk1ba0;
    int unk1ba4;
    int unk1ba8;
    int unk1bac;
    int unk1bb0;
    int unk1bb4;
    int unk1bb8;
    int unk1bbc;
    int unk1bc0;
    int unk1bc4;
    int unk1bc8;
    int unk1bcc;
    int unk1bd0;
    int unk1bd4;
    int unk1bd8;
    int unk1bdc;
    int unk1be0;
    int unk1be4;
    int unk1be8;
    int unk1bec;
    int unk1bf0;
    int unk1bf4;
    int unk1bf8;
    int unk1bfc;
    int unk1c00;
    int unk1c04;
    int unk1c08;
    int unk1c0c;
    int unk1c10;
    int unk1c14;
    int unk1c18;
    int unk1c1c;
    int unk1c20;
    int unk1c24;
    int unk1c28;
    int unk1c2c;
    int unk1c30;
    int unk1c34;
    int unk1c38;
    int unk1c3c;
    int unk1c40;
    int unk1c44;
    int unk1c48;
    int unk1c4c;
    int unk1c50;
    int unk1c54;
    int unk1c58;
    int unk1c5c;
    int unk1c60;
    int unk1c64;
    int unk1c68;
    int unk1c6c;
    int unk1c70;
    int unk1c74;
    int unk1c78;
    int unk1c7c;
    int unk1c80;
    int unk1c84;
    int unk1c88;
    int unk1c8c;
    int unk1c90;
    int unk1c94;
    int unk1c98;
    int unk1c9c;
    int unk1ca0;
    int unk1ca4;
    int unk1ca8;
    int unk1cac;
    int unk1cb0;
    int unk1cb4;
    int unk1cb8;
    int unk1cbc;
    int unk1cc0;
    int unk1cc4;
    int unk1cc8;
    int unk1ccc;
    int unk1cd0;
    int unk1cd4;
    int unk1cd8;
    int unk1cdc;
    int unk1ce0;
    int unk1ce4;
    int unk1ce8;
    int unk1cec;
    int unk1cf0;
    int unk1cf4;
    int unk1cf8;
    int unk1cfc;
    int unk1d00;
    int unk1d04;
    int unk1d08;
    int unk1d0c;
    int unk1d10;
    int unk1d14;
    int unk1d18;
    int unk1d1c;
    int unk1d20;
    int unk1d24;
    int unk1d28;
    int unk1d2c;
    int unk1d30;
    int unk1d34;
    int unk1d38;
    int unk1d3c;
    int unk1d40;
    int unk1d44;
    int unk1d48;
    int unk1d4c;
    int unk1d50;
    int unk1d54;
    int unk1d58;
    int unk1d5c;
    int unk1d60;
    int unk1d64;
    int unk1d68;
    int unk1d6c;
    int unk1d70;
    int unk1d74;
    int unk1d78;
    int unk1d7c;
    int unk1d80;
    int unk1d84;
    int unk1d88;
    int unk1d8c;
    int unk1d90;
    int unk1d94;
    int unk1d98;
    int unk1d9c;
    int unk1da0;
    int unk1da4;
    int unk1da8;
    int unk1dac;
    int unk1db0;
    int unk1db4;
    int unk1db8;
    int unk1dbc;
    int unk1dc0;
    int unk1dc4;
    int unk1dc8;
    int unk1dcc;
    int unk1dd0;
    int unk1dd4;
    int unk1dd8;
    int unk1ddc;
    int unk1de0;
    int unk1de4;
    int unk1de8;
    int unk1dec;
    int unk1df0;
    int unk1df4;
    int unk1df8;
    int unk1dfc;
    int unk1e00;
    int unk1e04;
    int unk1e08;
    int unk1e0c;
    int unk1e10;
    int unk1e14;
    int unk1e18;
    int unk1e1c;
    int unk1e20;
    int unk1e24;
    int unk1e28;
    int unk1e2c;
    int unk1e30;
    int unk1e34;
    int unk1e38;
    int unk1e3c;
    int unk1e40;
    int unk1e44;
    int unk1e48;
    int unk1e4c;
    int unk1e50;
    int unk1e54;
    int unk1e58;
    int unk1e5c;
    int unk1e60;
    int unk1e64;
    int unk1e68;
    int unk1e6c;
    int unk1e70;
    int unk1e74;
    int unk1e78;
    int unk1e7c;
    int unk1e80;
    int unk1e84;
    int unk1e88;
    int unk1e8c;
    int unk1e90;
    int unk1e94;
    int unk1e98;
    int unk1e9c;
    int unk1ea0;
    int unk1ea4;
    int unk1ea8;
    int unk1eac;
    int unk1eb0;
    int unk1eb4;
    int unk1eb8;
    int unk1ebc;
    int unk1ec0;
    int unk1ec4;
    int unk1ec8;
    int unk1ecc;
    int unk1ed0;
    int unk1ed4;
    int unk1ed8;
    int unk1edc;
    int unk1ee0;
    int unk1ee4;
    int unk1ee8;
    int unk1eec;
    int unk1ef0;
    int unk1ef4;
    int unk1ef8;
    int unk1efc;
    int unk1f00;
    int unk1f04;
    int unk1f08;
    int unk1f0c;
    int unk1f10;
    int unk1f14;
    int unk1f18;
    int unk1f1c;
    int unk1f20;
    int unk1f24;
    int unk1f28;
    int unk1f2c;
    int unk1f30;
    int unk1f34;
    int unk1f38;
    int unk1f3c;
    int unk1f40;
    int unk1f44;
    int unk1f48;
    int unk1f4c;
    int unk1f50;
    int unk1f54;
    int unk1f58;
    int unk1f5c;
    int unk1f60;
    int unk1f64;
    int unk1f68;
    int unk1f6c;
    int unk1f70;
    int unk1f74;
    int unk1f78;
    int unk1f7c;
    int unk1f80;
    int unk1f84;
    int unk1f88;
    int unk1f8c;
    int unk1f90;
    int unk1f94;
    int unk1f98;
    int unk1f9c;
    int unk1fa0;
    int unk1fa4;
    int unk1fa8;
    int unk1fac;
    int unk1fb0;
    int unk1fb4;
    int unk1fb8;
    int unk1fbc;
    int unk1fc0;
    int unk1fc4;
    int unk1fc8;
    int unk1fcc;
    int unk1fd0;
    int unk1fd4;
    int unk1fd8;
    int unk1fdc;
    int unk1fe0;
    int unk1fe4;
    int unk1fe8;
    int unk1fec;
    int unk1ff0;
    int unk1ff4;
    int unk1ff8;
    int unk1ffc;
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200c;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201c;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202c;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203c;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204c;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205c;
    Vec start, goal;
    int underwater;
    Triangles* triangles;
    Links* edges;
    POVPointerArray leftPOVs, rightPOVs, avoidPOVs, m_kPathPoints;
    POV* startPOV;
    POV* goalPOV;
    int nodesVtable, nodesData, nodesSize, nodesCap;
    int linksVtable, linksData, linksSize, linksCap;
    Verts left, right;
    void AddLeft(const Vertex&, const Handle&);
    void AddRight(const Vertex&, const Handle&);
    void InsertPOVPoint(Verts*, unsigned int, int);
    void BuildPOVLinks();
};
// @fnv 0x006ae370
void Smoother::BuildPOVLinks()
{
    left.Clear(false);
    right.Clear(false);
    for (int i = 0; i < edges->Size(); ++i)
    {
        Handle c(edges->At(i).mesh, edges->At(i).tri, edges->At(i).edge);
        Edge j = edges->At(i).mesh->GetEdge(edges->At(i).tri, edges->At(i).edge);
        Vertex l(edges->At(i).mesh, j.a);
        Vertex e(edges->At(i).mesh, j.b);
        if (i == 0)
        {
            Vec diffVal = l.mesh->Vertex(l.index) - e.mesh->Vertex(e.index);
            Vec crossVal = diffVal.Cross(l.mesh->Vertex(l.index) - start);
            if (crossVal.z > 0.0)
            {
                AddLeft(e, c);
                AddRight(l, c);
            }
            else
            {
                AddLeft(l, c);
                AddRight(e, c);
            }
        }
        else if (l.Equals(left.Last()))
        {
            AddRight(e, c);
        }
        else if (l.Equals(right.Last()))
        {
            AddLeft(e, c);
        }
        else if (e.Equals(left.Last()))
        {
            AddRight(l, c);
        }
        else if (e.Equals(right.Last()))
        {
            AddLeft(l, c);
        }
        else
        {
            Mesh* handle = 0;
            unsigned short edge5 = 0xffff;
            int edge = -1;
            if (triangles->At(i - 1)->mesh->Previous(triangles->At(i - 1)->tri, edges->At(i - 1).edge, &handle, &edge5,
                                                     &edge))
            {
            }
            Handle edge2(handle, edge5, edge);
            Edge edge3 = handle->GetEdge(edge5, edge);
            Vertex edge9(edges->At(i).mesh, edge3.a);
            Vertex edge6(edges->At(i).mesh, edge3.b);
            if (l.Equals(edge9))
            {
                AddRight(e, edge2);
            }
            else if (l.Equals(edge6))
            {
                AddLeft(e, edge2);
            }
            else if (e.Equals(edge9))
            {
                AddRight(l, edge2);
            }
            else if (e.Equals(edge6))
            {
                AddLeft(l, edge2);
            }
        }
    }
    for (unsigned int j = 0; j < left.Size(); ++j)
        InsertPOVPoint(&left, j, 1);
    for (unsigned int k = 0; k < right.Size(); ++k)
        InsertPOVPoint(&right, k, 0);
    for (unsigned int l = 0; l < left.Size(); ++l)
    {
        if (left.GetElementAt(l).pov != -1)
        {
            for (unsigned int m = left.GetElementAt(l).other; m < right.Size(); ++m)
            {
                if (right.GetElementAt(m).pov != -1)
                {
                    leftPOVs.FUN_00877a30(left.GetElementAt(l).pov)->other = right.GetElementAt(m).pov;
                    break;
                }
            }
        }
    }
    for (unsigned int n = 0; n < right.Size(); ++n)
    {
        if (right.GetElementAt(n).pov != -1)
        {
            for (unsigned int o = right.GetElementAt(n).other; o < left.Size(); ++o)
            {
                if (left.GetElementAt(o).pov != -1)
                {
                    rightPOVs.FUN_00877a30(right.GetElementAt(n).pov)->other = left.GetElementAt(o).pov;
                    break;
                }
            }
        }
    }
}

namespace fnv_006b1e50 {
struct P3
{
    float x, y, z;
};

struct ASC
{
    float fCos, fSin;
    void SetFromAngle(float);
    ASC& operator=(const ASC&);
    ASC Multiply(const ASC&) const;
    P3 MakePointOnCircle(float) const;
};

struct ASCArc
{
    ASC Start, End;
    int Direction;
    bool FUN_006a0660(const ASC*) const;
};

struct PtEx
{
    float x, y, z, r;
    P3 FUN_00439e90(const P3&) const;
};

struct EdgeLoc
{
    void* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    P3 Location;
    void FUN_006a0480();
    void FUN_006a0e50(const EdgeLoc*);
    void FUN_006cf900(const EdgeLoc*);
};

extern float DAT_01064f64;
extern float DAT_0106b3a8;

struct POVSearch
{
    bool FUN_006b1e50(const EdgeLoc&, PtEx&, ASCArc, EdgeLoc*);
    bool FindPath(const EdgeLoc&, const P3&, EdgeLoc*, float*);
};

// @fnv 0x006b1e50
bool POVSearch::FUN_006b1e50(const EdgeLoc& edge, PtEx& sphere, ASCArc arc, EdgeLoc* out)
{
    ASC rot3;
    rot3.SetFromAngle(arc.Direction == 0 ? DAT_01064f64 : DAT_0106b3a8);
    ASC startAng5;
    startAng5 = arc.Start;
    ASC angTmp = startAng5.Multiply(rot3);
    P3 RunFourthVirtual = sphere.FUN_00439e90(angTmp.MakePointOnCircle(sphere.r));
    EdgeLoc cur4;
    cur4.FUN_006a0e50(&edge);
    EdgeLoc arr5;
    arr5.FUN_006a0480();
    unsigned int count9 = 0;
    int idx4 = -1;
    float weight = 0.0f;
    while (arc.FUN_006a0660(&angTmp) && count9 < 0x18)
    {
        cur4.m_iEdgeIndex = -1;
        if (!FindPath(cur4, RunFourthVirtual, &arr5, &weight))
        {
            out->FUN_006cf900(&arr5);
            return false;
        }
        cur4.FUN_006cf900(&arr5);
        startAng5 = angTmp;
        angTmp = startAng5.Multiply(rot3);
        RunFourthVirtual = sphere.FUN_00439e90(angTmp.MakePointOnCircle(sphere.r));
        idx4 = arr5.m_iEdgeIndex;
        count9 = count9 + 1;
    }
    if (count9 == 0x18)
    {
        out->FUN_006cf900(&arr5);
        return false;
    }
    P3 q2 = sphere.FUN_00439e90(arc.End.MakePointOnCircle(sphere.r));
    cur4.m_iEdgeIndex = -1;
    if (!FindPath(cur4, q2, &arr5, &weight))
    {
        out->FUN_006cf900(&arr5);
        return false;
    }
    out->FUN_006cf900(&arr5);
    return true;
}
}  // namespace fnv_006b1e50

struct TESFile;
struct EdgeExtraInfo
{
    void Clear();
    int GetSaveSize();
    int GetSaveSizeOld();
    void FillBuffer(char*);
    void SerializeToFile(TESFile*, char*);
    void DeserializeFromFile(TESFile*, char*);
    int eType;
    char Portal[8];
};
typedef char _sizecheck_EdgeExtraInfo[sizeof(EdgeExtraInfo) == 12 ? 1 : -1];
struct FUN_006b2060_shell : public PathSmootherPOVSearch
{
    bool FindPath(void*, void*, NavMeshEdgePoint*, float*);
};

class NavMeshAccess : public NavMesh
{
  public:
    NavMeshTriangle* FUN_005582f0(unsigned short);
    EdgeExtraInfo* FUN_0068f230(unsigned short, int);
};
class TriangleAccess : public NavMeshTriangle
{
  public:
    bool HasFlag40();
    bool FUN_00693b90();
};
class MeshEdgeRecord : public NavMeshEdgeData
{
  public:
    MeshEdgeRecord();
    MeshEdgeRecord(const NavMeshEdgePoint&);
    MeshEdgeRecord(NavMesh*, unsigned short, int);
    MeshEdgeRecord& operator=(const MeshEdgeRecord&);
};
class EdgeLocation : public NavMeshEdgePoint
{
  public:
    EdgeLocation(const MeshEdgeRecord&, const NiPoint3&);
};
extern SettingT_GameSettingCollection_ DAT_011d6ef0;
bool FUN_006ba240(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, NiPoint3&);
class PathSmootherAccess : public PathSmootherPOVSearch
{
  public:
    bool FindPath(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint*, float&);
};

// @fnv 0x006b2060
bool PathSmootherAccess::FindPath(const NavMeshEdgePoint& start, const NiPoint3& goal, NavMeshEdgePoint* output,
                                  float& ratio)
{
    NiPoint3 position2 = start.Location;
    NiPoint3 position8 = goal;
    NiPoint3 normal = position8 - position2;
    normal.ComputeMagnitude();
    NiPoint3 position = position2;
    MeshEdgeRecord current(start);
    int count = 0;
    int index7 = 0;
    while (index7 < 1000)
    {
        ++index7;
        if (static_cast<TriangleAccess*>(
                static_cast<NavMeshAccess*>(current.m_pLocationNavMesh)->FUN_005582f0(current.m_usTriangleID))
                ->HasFlag40())
            ++count;
        int NextEdge = current.m_pLocationNavMesh->FindCrossedEdge(current.m_usTriangleID, current.m_iEdgeIndex,
                                                                   position, position8);
        if (NextEdge == -1)
        {
            float Height = position8.z;
            current.m_pLocationNavMesh->GetTriangleHeightAtPoint(current.m_usTriangleID, position8, 3.402823466e38F,
                                                                 3.402823466e38F, Height);
            position8.z = Height;
            *output = EdgeLocation(current, position8);
            ratio = float(count) / index7;
            return true;
        }
        else
        {
            MeshEdgeRecord next2(current.m_pLocationNavMesh, current.m_usTriangleID, NextEdge);
            MeshEdgeRecord next;
            bool result9 = next2.m_pLocationNavMesh->MatchNavMesh(next2, next);
            if (result9)
            {
                EdgeExtraInfo* info = static_cast<NavMeshAccess*>(next2.m_pLocationNavMesh)
                                          ->FUN_0068f230(next2.m_usTriangleID, next2.m_iEdgeIndex);
                if (info && info->eType == 1)
                    result9 = false;
                if (pRequest->GetFloatAtOffset68() > DAT_011d6ef0.Float()->f &&
                    static_cast<TriangleAccess*>(
                        static_cast<NavMeshAccess*>(next.m_pLocationNavMesh)->FUN_005582f0(next.m_usTriangleID))
                        ->FUN_00693b90())
                    result9 = false;
            }
            if (result9)
            {
                if (current.m_pLocationNavMesh != next.m_pLocationNavMesh)
                {
                    NavMeshEdgeVertexPair index =
                        next.m_pLocationNavMesh->FUN_0068f040(next.m_usTriangleID, next.m_iEdgeIndex);
                    NiPoint3 point = (*index.p1 + *index.p2) * 0.5F;
                    position = FUN_006ba550(*index.p1, *index.p2, position2, position8);
                    position += (point - position) * 0.01F;
                }
                current = next;
            }
            else
            {
                NavMeshEdgeVertexPair index = next2.m_pLocationNavMesh->FUN_0068f040(next2.m_usTriangleID, NextEdge);
                NiPoint3 point;
                FUN_006ba240(position2, position8, *index.p1, *index.p2, point);
                *output = EdgeLocation(next2, point);
                ratio = float(count) / index7;
                return false;
            }
        }
    }
    *output = EdgeLocation(current, position8);
    if (index7 > 0)
        ratio = float(count) / index7;
    else
        ratio = 0.0F;
    return false;
}

namespace fnv_006aeb00 {
struct PathPos6AE
{
    int unk00;
    int unk04;
    PathPos6AE* FUN_0069a690(const PathPos6AE* pkOther);
};

struct PathLoc6AE
{
    int unk00;
    int unk04;
    int unk08;
    PathLoc6AE& CopyFromNavMeshEdge(const PathLoc6AE& kOther);
};

struct FUN_006aeb70
{
    PathPos6AE kPos;
    PathLoc6AE kLoc;
    int iCount1;
    int iCount2;
    int iIndex;
    FUN_006aeb70();
};

struct List6AE
{
    int FUN_0044ddc0();
    int FUN_006b3730(FUN_006aeb70* pkRequest);
};

class FUN_006aeb00_C
{
  public:
    char unk0000[0x20ec];
    List6AE kList1;
    char unk20ED[0xf];
    List6AE kList2;

    int FUN_006aeb00(const PathPos6AE* pkPos, const PathLoc6AE& kLoc);
};

// Copies the position and location into a request, sets counts from both lists, and returns the result of calling kList2.FUN_006b3730.
// @fnv 0x006aeb00
int FUN_006aeb00_C::FUN_006aeb00(const PathPos6AE* pkPos, const PathLoc6AE& kLoc)
{
    FUN_006aeb70 kRequest;
    kRequest.kPos.FUN_0069a690(pkPos);
    kRequest.kLoc.CopyFromNavMeshEdge(kLoc);
    kRequest.iCount1 = kList1.FUN_0044ddc0();
    kRequest.iCount2 = kList2.FUN_0044ddc0();
    kRequest.iIndex = -1;
    return kList2.FUN_006b3730(&kRequest);
}
}  // namespace fnv_006aeb00

struct Thing
{
    NiPoint3* RotatePoint90(NiPoint3* out, float* in, int flag);
};

// Rotates a 2D point 90 degrees clockwise or counter-clockwise based on flag, storing the result in out with z set to zero.
// @fnv 0x006b0a60
NiPoint3* Thing::RotatePoint90(NiPoint3* out, float* in, int flag)
{
    NiPoint3 ptTmp;
    if (flag == 0)
    {
        ptTmp.x = -in[1];
        ptTmp.y = in[0];
    }
    else
    {
        ptTmp.x = in[1];
        ptTmp.y = -in[0];
    }
    ptTmp.z = 0.0f;
    *out = ptTmp;
    return out;
}

typedef PathSmootherPOVSearch::NavMeshEdgeRecord PathEdgeVertType;
typedef BSSimpleArray<PathEdgeVertType, 1024> EdgeVertArray;
struct NavMeshVertexAccess : NavMesh
{
    const NiPoint3* FUN_0068f0a0(unsigned short);
};
struct VertAccess
{
    PathEdgeVertType& GetElementAt(unsigned int);
};
struct Unitizer
{
    void Unitize();
};
struct CrossAccess
{
    NiPoint3 FUN_004b3800(const NiPoint3&) const;
};
struct RequestAccess
{
    float GetFloatAtOffset68();
};
struct CornerSearch : PathSmootherPOVSearch
{
    void InsertPOVPoint(EdgeVertArray* vertices, unsigned int index, bool left);
};
extern const double DAT_01012060;
extern const double DAT_0103c7c8;
extern const double DAT_0106b9d8;
extern const double DAT_010290f0;

// Checks the vertex directions, then adds a PathSmootherPOVPoint to the path lists when endpoint or cross and dot conditions select it.
// @fnv 0x006aeba0
void CornerSearch::InsertPOVPoint(EdgeVertArray* vertices, unsigned int index, bool left)
{
    NiPoint3 point =
        *reinterpret_cast<NavMeshVertexAccess*>(
             reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index))
                 ->m_pLocationNavMesh)
             ->FUN_0068f0a0(
                 reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index))
                     ->m_usVertexId);
    NiPoint3 prevDir;
    NiPoint3 right;
    if (index == 0)
    {
        prevDir = m_kPathStartPosition - point;
    }
    else
    {
        prevDir =
            *reinterpret_cast<NavMeshVertexAccess*>(
                 reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index - 1))
                     ->m_pLocationNavMesh)
                 ->FUN_0068f0a0(reinterpret_cast<PathEdgeVertType*>(
                                    &reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index - 1))
                                    ->m_usVertexId) -
            point;
    }
    if (index == vertices->GetSize() - 1)
    {
        right = m_kGoalPosition - point;
    }
    else
    {
        right =
            *reinterpret_cast<NavMeshVertexAccess*>(
                 reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index + 1))
                     ->m_pLocationNavMesh)
                 ->FUN_0068f0a0(reinterpret_cast<PathEdgeVertType*>(
                                    &reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index + 1))
                                    ->m_usVertexId) -
            point;
    }
    prevDir.z = 0.0f;
    right.z = 0.0f;
    reinterpret_cast<Unitizer*>(&prevDir)->Unitize();
    reinterpret_cast<Unitizer*>(&right)->Unitize();
    NiPoint3 cross = left ? reinterpret_cast<CrossAccess*>(&prevDir)->FUN_004b3800(right)
                          : reinterpret_cast<CrossAccess*>(&right)->FUN_004b3800(prevDir);
    float dot = right.Dot(prevDir);
    bool usePOV = false;
    if (index == 0 || index == vertices->GetSize() - 1)
    {
        usePOV = true;
    }
    else if (dot > DAT_01012060)
    {
        if (cross.z < DAT_0103c7c8)
        {
            usePOV = true;
        }
    }
    else if (cross.z < DAT_0106b9d8)
    {
        usePOV = true;
    }
    if (usePOV)
    {
        PathSmootherPOVPoint* pov = new PathSmootherPOVPoint;
        pov->eType = !left;
        pov->MeshEdgeRecord =
            reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index))->Edge;
        pov->m_kFirstEdge = prevDir;
        pov->m_kSecondEdge = right;
        pov->Center = point;
        pov->m_fWeight = 1.0f;
        pov->fRadius = reinterpret_cast<RequestAccess*>(pRequest)->GetFloatAtOffset68() * DAT_010290f0;
        pov->m_usResult =
            reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index))
                ->m_usVertexId;
        pov->m_uiReferenceIndex = -1;
        if (left)
        {
            pov->m_uiListIndex = m_kPrimaryPathPoints.GetSize();
        }
        else
        {
            pov->m_uiListIndex = m_kSecondaryPathPoints.GetSize();
        }
        reinterpret_cast<PathEdgeVertType*>(&reinterpret_cast<VertAccess*>(vertices)->GetElementAt(index))
            ->m_uiTrailingValue = pov->m_uiListIndex;
        m_kPathPoints.Add(pov);
        if (left)
        {
            m_kPrimaryPathPoints.Add(pov);
        }
        else
        {
            m_kSecondaryPathPoints.Add(pov);
        }
    }
}

struct CollisionProbe
{
    bool FindPath(const NavMeshEdgePoint& origin, const NiPoint3& target, NavMeshEdgePoint* hit, float& height);
};

struct VectorUnitizer
{
    void Unitize();
};
struct VectorNegation
{
    NiPoint3 FUN_004a0bd0() const;
};
extern const double DAT_0106b9e8;
extern const float DAT_01016248;
extern const float DAT_010177e8;
extern const float DAT_01016970;

struct ClearanceSearch : PathSmootherPOVSearch
{
    bool FUN_006b25f0(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint*, bool, bool, float&);
};

// Finds a path from origin to target, then probes four lateral offsets around the route to verify clearance, adjusting the hit height if flipB is false.
// @fnv 0x006b25f0
bool ClearanceSearch::FUN_006b25f0(const NavMeshEdgePoint& origin, const NiPoint3& target, NavMeshEdgePoint* hit,
                                   bool flipA, bool flipB, float& afDestinationHeight)
{
    if (!reinterpret_cast<CollisionProbe*>(this)->FindPath(origin, target, hit, afDestinationHeight))
        return false;

    if (m_bUnderwaterPath)
    {
        hit->Location.z = target.z;
        return true;
    }

    NiPoint3 delta = target - origin.Location;
    NiPoint3 kDirection = delta;
    reinterpret_cast<VectorUnitizer*>(&kDirection)->Unitize();

    NiPoint3 offsetAVal, offsetBVal, aOffsetC, offsetD2;

    float spread9;
    if (pRequest->GetFloatAtOffset68() * pRequest->GetFloatAtOffset68() > delta.FUN_004a7290())
        spread9 = delta.FUN_00457990() * DAT_0106b9e8;
    else
        spread9 = pRequest->GetFloatAtOffset68() * DAT_0106b9e8;

    NiPoint3 advance3 = kDirection * spread9;
    NiPoint3 lateral4 = reinterpret_cast<const CrossAccess*>(&DAT_011a9484)->FUN_004b3800(kDirection);

    if (flipA)
    {
        offsetAVal = ((lateral4 * spread9) * DAT_01016248) + (advance3 * DAT_01016248);
        offsetBVal = ((reinterpret_cast<const VectorNegation*>(&lateral4)->FUN_004a0bd0() * spread9) * DAT_01016248) +
                     (advance3 * DAT_01016248);
    }
    else
    {
        offsetAVal = (lateral4 * pRequest->GetFloatAtOffset68()) * DAT_010177e8;
        offsetBVal =
            (reinterpret_cast<const VectorNegation*>(&lateral4)->FUN_004a0bd0() * pRequest->GetFloatAtOffset68()) *
            DAT_010177e8;
    }
    if (flipB)
    {
        aOffsetC = ((lateral4 * spread9) * DAT_01016248) - (advance3 * DAT_01016248);
        offsetD2 = ((reinterpret_cast<const VectorNegation*>(&lateral4)->FUN_004a0bd0() * spread9) * DAT_01016248) -
                   (advance3 * DAT_01016248);
    }
    else
    {
        aOffsetC = (lateral4 * pRequest->GetFloatAtOffset68()) * DAT_010177e8;
        offsetD2 =
            (reinterpret_cast<const VectorNegation*>(&lateral4)->FUN_004a0bd0() * pRequest->GetFloatAtOffset68()) *
            DAT_010177e8;
    }

    float height2;
    NavMeshEdgePoint firstVal;
    if (!reinterpret_cast<CollisionProbe*>(this)->FindPath(origin, origin.Location + offsetAVal, &firstVal, height2))
        return false;
    NavMeshEdgePoint secondB;
    if (!reinterpret_cast<CollisionProbe*>(this)->FindPath(firstVal, target + aOffsetC, &secondB, height2))
        return false;
    NavMeshEdgePoint third3;
    if (!reinterpret_cast<CollisionProbe*>(this)->FindPath(origin, origin.Location + offsetBVal, &third3, height2))
        return false;
    NavMeshEdgePoint fourth;
    if (!reinterpret_cast<CollisionProbe*>(this)->FindPath(third3, target + offsetD2, &fourth, height2))
        return false;
    if (!flipB)
    {
        float savedHeight = hit->Location.z;
        hit->m_pLocationNavMesh->GetTriangleHeightAtPoint(hit->m_usTriangleID, hit->Location, DAT_01016970,
                                                          DAT_01016970, savedHeight);
        hit->Location.z = savedHeight;
    }
    return true;
}

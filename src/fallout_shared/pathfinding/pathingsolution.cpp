// fallout_shared/pathfinding/pathingsolution.cpp: PathingSolution, OwnS, DelS, HermiteStub and more (34 functions)

#include "pathingsolution_types_PathingSolution.h"

// Initializes the PathingSolution object by setting two local sentinel values to -1 and clearing the boolean member.
// @fnv 0x006e7650
PathingSolution::PathingSolution()
{
    volatile int first;
    volatile int second;
    second = -1;
    first = -1;
    m_bHasValidPath = false;
}

// @fnv 0x006e7800
float PathingSolution::CalculatePathLength()
{
    struct Stack
    {
        NiPoint3 thirdPoint;
        NiPoint3 secondPoint;
        NiPoint3 firstPoint;
        unsigned int index;
        unsigned int count;
        PacketNodeRecord* second;
        PacketNodeRecord* first;
        float distance;
    } stack;
    stack.distance = 0.0f;
    stack.count = GetVirtualNodeCount();
    for (stack.index = 1; stack.index < stack.count; ++stack.index)
    {
        stack.first = GetVirtualNode(stack.index - 1);
        if (stack.first->IsDoor())
            continue;
        stack.second = GetVirtualNode(stack.index);
        stack.distance += stack.second
                              ->GetPosition(stack.firstPoint, stack.thirdPoint,
                                            stack.first->GetPosition(stack.secondPoint)->GetLocation())
                              ->GetLocation()
                              ->GetDoorPathingPoint()
                              ->GetDistance();
    }
    return stack.distance;
}

struct DelS
{
    void FUN_006e7720();
    static void operator delete(void*, unsigned int);
    void* FUN_006e76f0(unsigned int flags);
};
// Calls FUN_006e7720, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e76f0
void* DelS::FUN_006e76f0(unsigned int flags)
{
    FUN_006e7720();
    if (flags & 1)
        DelS::operator delete(this, 0x44);
    return this;
}

struct PSClearStub
{
    void Clear(bool);
};
struct PSNodeStub
{
    void FUN_006cf120(bool);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};

// Clears the three members of the pathing solution, sets member1's two values to -1 and clears the flag.
// @fnv 0x006e77b0
void __fastcall ResetPathingSolution(PathingSolution* self)
{
    ((PSClearStub*)&self->member1)->Clear(true);
    ((PSNodeStub*)&self->member2)->FUN_006cf120(true);
    ((GlobalObject_00869f00*)&self->member3)->Clear(true);
    self->member1.firstValue = -1;
    self->member1.secondValue = -1;
    self->m_bHasValidPath = false;
}

struct FUN_006e78b0_shell : public PathingSolution
{
    void* FUN_006e78b0(unsigned int);
};

struct PathBuilder
{
    void* FUN_006e8f40(void*);
};

// @fnv 0x006e78b0
void* FUN_006e78b0_shell::FUN_006e78b0(unsigned int aiIndex)
{
    return ((PathBuilder*)((char*)this + 8))->FUN_006e8f40((void*)aiIndex);
}

struct FUN_006e7970_shell : public PathingSolution
{
    void* FUN_006e7970(unsigned int);
};

void* __fastcall FUN_006e8f80(void* this_ptr);

struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int aiIndex);
};

// @fnv 0x006e7970
void* FUN_006e7970_shell::FUN_006e7970(unsigned int aiIndex)
{
    return ((Dummy_006e8f80*)((char*)this + 0x20))->FUN_006e8f80(aiIndex);
}

struct FUN_00457990_shell
{
    float FUN_00457990();
};

struct FUN_006e7990_shell
{
    int GetObjectFlags();
    PacketNodeRecord* FUN_006e7970(int);
    float FUN_006e7990(int);
};

// Returns 0.0f if the index is at or past the last element, otherwise computes a value from the positions of the element at the index and the next one.
// @fnv 0x006e7990
float FUN_006e7990_shell::FUN_006e7990(int aiIndex)
{
    if (aiIndex >= GetObjectFlags() - 1)
        return 0.0f;
    NiPoint3 loc1;
    NiPoint3 loc2;
    NiPoint3 loc3;
    return ((FUN_00457990_shell*)FUN_006e7970(aiIndex)
                ->GetPosition(loc3, loc2, FUN_006e7970(aiIndex + 1)->GetPosition(loc1)->GetLocation())
                ->GetLocation()
                ->GetDoorPathingPoint())
        ->FUN_00457990();
}

struct BaseS
{
    char pad[0x14];
    BaseS();
    ~BaseS();
};
struct MemS
{
    char pad[0x18];
    MemS();
};
struct FUN_006e7b60 : BaseS
{
    MemS m1;
    MemS m2;
    FUN_006e7b60();
};
// Constructs the object by running the BaseS constructor and default-constructing its two MemS members.
// @fnv 0x006e7b60
FUN_006e7b60::FUN_006e7b60()
{}

extern NiPoint3 _NiPoint3_ZERO;

// Sets two NiPoint3 values at offsets 0 and 0xc of pThis to _NiPoint3_ZERO and returns pThis.
// @fnv 0x006e7bd0
void* __fastcall InitZeroPoints(void* pThis)
{
    *(NiPoint3*)pThis = _NiPoint3_ZERO;
    *(NiPoint3*)((char*)pThis + 0xc) = _NiPoint3_ZERO;
    return pThis;
}

void __fastcall FUN_006e7c40(void* pThis, float arg);

// @fnv 0x006e7c20
void __fastcall FUN_006e7c20(void* pThis, float arg)
{
    FUN_006e7c40(pThis, arg);
}

extern double DAT_0106d4c8;
struct HermiteStub
{
    float t;
    float a;
    float b;
    float c;
    float d;
    void FUN_006e7c40(float t);
};
// @fnv 0x006e7c40
void HermiteStub::FUN_006e7c40(float tp)
{
    float t2;
    float t3;
    float tt;
    t = tp;
    tt = tp;
    t2 = tt * tt;
    t3 = t2 * tt;
    c = t3 * DAT_0106d4c8 + t2 * 3.0;
    a = -c + 1.0;
    d = t3 - t2;
    b = d - t2 + tt;
}

struct SubS
{
    void FUN_006e7d10(int);
};
struct RetS
{
    float v[3];
};
struct OwnS
{
    char pad[0x14];
    SubS s1;
    char pad2[0x17];
    SubS s2;
    RetS FUN_006e7d60(int, int);
    RetS FUN_006e7cc0(int a, int b);
};
// Calls FUN_006e7d10 on s1 with a and on s2 with b, then returns FUN_006e7d60(a, b).
// @fnv 0x006e7cc0
RetS OwnS::FUN_006e7cc0(int aiFirst, int aiSecond)
{
    s1.FUN_006e7d10(aiFirst);
    s2.FUN_006e7d10(aiSecond);
    return FUN_006e7d60(aiFirst, aiSecond);
}

struct _S_006e7d10_vec
{
    float x, y, z;
};

struct _S_006e7d10
{
    _S_006e7d10_vec a;
    _S_006e7d10_vec b;
};

struct _Arg_006e7d10
{
    const _S_006e7d10* p;
};

// Copies the two vector members a and b from the pointed-to struct into this struct and returns this.
// @fnv 0x006e7d10
_S_006e7d10* __fastcall FUN_006e7d10(_S_006e7d10* this_ptr, _Arg_006e7d10 aSource)
{
    this_ptr->a = aSource.p->a;
    this_ptr->b = aSource.p->b;
    return this_ptr;
}

struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
    NP3S GetLocation();
};
struct M24
{
    NP3S a;
    NP3S b;
    M24();
    M24(const M24&);
};
struct OwnS2
{
    char pad[4];
    LocS loc;
    char pad2[0x27];
    NP3S tangent;
    M24 GetLocationAndTangent();
};
// Builds an M24 from the object's location and tangent and returns it.
// @fnv 0x006e7e10
M24 OwnS2::GetLocationAndTangent()
{
    M24 m;
    m.a = loc.GetLocation();
    m.b = tangent;
    return m;
}

struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
typedef char _sizecheck_PathingSpline[sizeof(SplineInterpolator) == 68 ? 1 : -1];
struct PathingControlPoint
{
    NiPoint3 Location;
    NiPoint3 Tangent;
};
typedef char _sizecheck_PathingSplineKey[sizeof(PathingControlPoint) == 24 ? 1 : -1];
struct FUN_006e8450_shell : public SplineInterpolator
{
    void SetKeys(void*, void*);
};

struct FUN_006e7d10_caller
{
    void FUN_006e7d10(void*);
};

// Forwards each of the two key arguments to the corresponding key object's FUN_006e7d10 method.
// @fnv 0x006e8450
void FUN_006e8450_shell::SetKeys(void* aKey1, void* aKey2)
{
    reinterpret_cast<FUN_006e7d10_caller*>(this->Key1)->FUN_006e7d10(aKey1);
    reinterpret_cast<FUN_006e7d10_caller*>(this->Key2)->FUN_006e7d10(aKey2);
}

namespace fnv_006e8f60 {
class PathBuilder
{
  public:
    void* FUN_006e8f40(void*);
    void* FUN_006e8f60(void* a1);
};

// @fnv 0x006e8f60
void* PathBuilder::FUN_006e8f60(void* apArg)
{
    return FUN_006e8f40(apArg);
}
}  // namespace fnv_006e8f60

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_006e8fa0(unsigned int f);
};
// @fnv 0x006e8fa0
bool S3e60::FUN_006e8fa0(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

struct FUN_006e9080
{
    char b[0x18];
    ~FUN_006e9080();
};
struct FUN_006e9260
{
    char b[0x10];
    ~FUN_006e9260();
};
struct FUN_00438690
{
    char b[8];
    ~FUN_00438690();
};
struct EBase
{
    virtual ~EBase();
    char b[4];
};
struct FUN_006e7720 : public EBase
{
    FUN_006e9080 m1;
    FUN_006e9260 m2;
    FUN_00438690 m3;
    virtual ~FUN_006e7720();
};
void __fastcall ResetPathingSolution(FUN_006e7720*);
// @fnv 0x006e7720
FUN_006e7720::~FUN_006e7720()
{
    ResetPathingSolution(this);
}

namespace fnv_006e78d0 {
struct FUN_006e78d0_shell : public PathingSolution
{
    float GetTotalPathLength();
};

struct FUN_006e7970_shell
{
    void* FUN_006e7970(unsigned int);
};
struct SizeH
{
    unsigned int GetObjectFlags();
};
struct NiPoint3H
{
    float Length() const;
};
// Sums the lengths of the segments between consecutive path nodes and returns the total length.
// @fnv 0x006e78d0
float FUN_006e78d0_shell::GetTotalPathLength()
{
    float ftotalLength = 0.0f;
    PacketNodeRecord* plastNode;
    PacketNodeRecord* pnextNode;
    unsigned int isize = ((SizeH*)this)->GetObjectFlags();
    for (unsigned int i = 1; i < isize; i++)
    {
        plastNode = (PacketNodeRecord*)((FUN_006e7970_shell*)this)->FUN_006e7970(i - 1);
        pnextNode = (PacketNodeRecord*)((FUN_006e7970_shell*)this)->FUN_006e7970(i);
        NiPoint3 a;
        NiPoint3 b;
        NiPoint3 c;
        ftotalLength += ((NiPoint3H*)pnextNode->GetPosition(a, c, plastNode->GetPosition(b)->GetLocation())
                             ->GetLocation()
                             ->GetDoorPathingPoint())
                            ->Length();
    }
    return ftotalLength;
}
}  // namespace fnv_006e78d0

struct _ref_006815c0
{
    float x;
    float y;
    float z;
    _ref_006815c0();
};
struct FUN_006e7d60_stub
{
    float ComputeWeightedSum(float*, float*, float*, float*);
    _ref_006815c0 FUN_006e7d60(char* p3, char* p4);
};
// Computes a vector from two structures by calling ComputeWeightedSum on each of the x, y and z component pairs.
// @fnv 0x006e7d60
_ref_006815c0 FUN_006e7d60_stub::FUN_006e7d60(char* pFirst, char* pSecond)
{
    _ref_006815c0 vecResult;
    vecResult.x = ComputeWeightedSum((float*)pFirst, (float*)pSecond, (float*)(pFirst + 0xc), (float*)(pSecond + 0xc));
    vecResult.y = ComputeWeightedSum((float*)(pFirst + 4), (float*)(pSecond + 4), (float*)(pFirst + 0x10),
                                     (float*)(pSecond + 0x10));
    {
        float a = 0.0f;
        float b = 0.0f;
        vecResult.z = ComputeWeightedSum((float*)(pFirst + 8), (float*)(pSecond + 8), &b, &a);
    }
    return vecResult;
}

struct FUN_006e8f40_shell
{
    int FUN_006e8f40(int a) const;
};

// @fnv 0x006e8f40
int FUN_006e8f40_shell::FUN_006e8f40(int aiIndex) const
{
    return aiIndex * 0x30 + *(int*)((char*)this + 4);
}

namespace fnv_006e7e70 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
typedef char _sizecheck_PathingSpline[sizeof(SplineInterpolator) == 68 ? 1 : -1];
struct FUN_006e7e70_shell : public PathingSolution
{
    bool FindPointOnPath(float, float, bool, float*, NiPoint3*);
};

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};
unsigned int __fastcall GetObjectFlags(char*);
PathingGraphNode* __fastcall FUN_006b05a0(PathingSolution*);
PathingGraphNode* __fastcall FUN_006e8480(PathingSolution*);
struct PathingSplineKeyS
{
    float fData[6];
};
struct OwnS2
{
    PathingSplineKeyS GetLocationAndTangent();
};
struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int);
};
struct PathingLocationExt
{
    NiPoint3 FUN_005c3420() const;
};
PathingLocationExt& __fastcall FUN_00717e50(PathingGraphNode*);
struct BSSplineS
{
    void* pData[5];
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    ~FUN_006e7b60();
    void SetKeys(const PathingSplineKeyS&, const PathingSplineKeyS&);
    bool FindPointAtDistance(float, float, bool, float*, NiPoint3*, float);
    float MeasurePathLength(float, float, unsigned int);
    BSSplineS SplinePath;
    PathingSplineKeyS Key1;
    PathingSplineKeyS Key2;
};

// Walks the spline segments forward or backward from afCurrentParameter by afDist, writing the resulting parameter and point to the output pointers.
// @fnv 0x006e7e70
bool FUN_006e7e70_shell::FindPointOnPath(float afCurrentParameter, float afDist, bool abForward, float* apNewParameter,
                                      NiPoint3* apNewPoint)
{
    if (!GetObjectFlags((char*)this))
        return false;
    if (abForward)
    {
        bool bfound;
        int isize = GetObjectFlags((char*)this) - 1;
        if (afCurrentParameter >= isize)
        {
            if (apNewParameter)
                *apNewParameter = isize;
            if (apNewPoint)
                *apNewPoint = FUN_00717e50(FUN_006b05a0(this)).FUN_005c3420();
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        FUN_006e7b60 spline;
        spline.SetKeys(
            ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent(),
            ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent());
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(fcurrentParam - icurrentSpline, 1.0f, 2);
            ++icurrentSpline;
            fcurrentParam = icurrentSpline;
            if (icurrentSpline >= isize - 1)
            {
                if (apNewParameter)
                    *apNewParameter = isize;
                if (apNewPoint)
                    *apNewPoint = FUN_00717e50(FUN_006b05a0(this)).FUN_005c3420();
                return false;
            }
            spline.SetKeys(
                ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent(),
                ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent());
            bfound = spline.FindPointAtDistance(0.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
    else
    {
        bool bfound;
        int isize = GetObjectFlags((char*)this) - 1;
        if (afCurrentParameter <= 0.0)
        {
            if (apNewParameter)
                *apNewParameter = 0.0f;
            if (apNewPoint)
                *apNewPoint = FUN_00717e50(FUN_006e8480(this)).FUN_005c3420();
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        if (icurrentSpline < 0)
            icurrentSpline = 0;
        if (icurrentSpline >= (int)((ArrSI*)&member2)->GetFlags() - 1)
            --icurrentSpline;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        FUN_006e7b60 spline;
        spline.SetKeys(
            ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent(),
            ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent());
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(0.0f, fcurrentParam - icurrentSpline, 2);
            --icurrentSpline;
            fcurrentParam = icurrentSpline + 1;
            if (icurrentSpline < 0)
            {
                if (apNewParameter)
                    *apNewParameter = 0.0f;
                if (apNewPoint)
                    *apNewPoint = FUN_00717e50(FUN_006e8480(this)).FUN_005c3420();
                return false;
            }
            spline.SetKeys(
                ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent(),
                ((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent());
            bfound = spline.FindPointAtDistance(1.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
}
}  // namespace fnv_006e7e70

struct ArrHelper
{
    bool FUN_0076b610() const;
    int FUN_006e8fc0();
};
struct FUN_006e8480_shell
{
    char _pad[32];
    ArrHelper m;
    int FUN_006e8480();
};
// Returns 0 when m.FUN_0076b610() is true, otherwise returns m.FUN_006e8fc0().
// @fnv 0x006e8480
int FUN_006e8480_shell::FUN_006e8480()
{
    if (m.FUN_0076b610())
    {
        return 0;
    }
    return m.FUN_006e8fc0();
}

struct HelperA
{
    char data[16];
    void FUN_006e9410(void*);
};
struct HelperB
{
    char data[32];
    void FUN_006e9470(void*);
};
struct MyClass
{
    char _0[8];
    HelperA ha;
    int m18;
    int m1c;
    HelperB hb;
    unsigned char m40;
    void FUN_006e8ab0(MyClass* p);
};
// @fnv 0x006e8ab0
void MyClass::FUN_006e8ab0(MyClass* apTarget)
{
    apTarget->m18 = m18;
    apTarget->m1c = m1c;
    apTarget->m40 = m40;
    ha.FUN_006e9410(&apTarget->ha);
    hb.FUN_006e9470(&apTarget->hb);
}

struct PathingGraphNode;
struct BSSimpleArray_PathingNode_1024
{
    int m_auiShapeKeys;
    int m_pBase;
    PathingGraphNode* FUN_006e8f80(unsigned int aiIndex);
};
// @fnv 0x006e8f80
PathingGraphNode* BSSimpleArray_PathingNode_1024::FUN_006e8f80(unsigned int aiIndex)
{
    return (PathingGraphNode*)((char*)m_pBase + aiIndex * 0x3C);
}

namespace fnv_006e9ab0 {
void __fastcall FUN_006e7c20(void*, float);
struct RetS
{
    int _a[3];
};
struct OwnS
{
    char _pad[48];
    RetS FUN_006e9ab0(float);
    RetS FUN_006e7d60(int, int);
};
// @fnv 0x006e9ab0
RetS OwnS::FUN_006e9ab0(float f)
{
    FUN_006e7c20(this, f);
    return FUN_006e7d60((int)((char*)this + 0x14), (int)((char*)this + 0x2c));
}
}  // namespace fnv_006e9ab0

namespace fnv_006e7a10 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
typedef char _sizecheck_PathingSpline[sizeof(SplineInterpolator) == 68 ? 1 : -1];
struct FUN_006e7a10_shell : public PathingSolution
{
    void GetLocationAtSplineParameter(float, NiPoint3*);
};

struct StageItemNode;
StageItemNode* __fastcall FUN_00717e50(void*);
unsigned int __fastcall GetObjectFlags(char*);
struct FUN_006e7970_shell
{
    void* FUN_006e7970(unsigned int);
};
struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
    NP3S GetLocation();
};
struct M24
{
    float k[6];
};
struct RetS
{
    float x;
    float y;
    float z;
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
void __fastcall FUN_006e7c20(void*, float);
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
    int SplinePath[5];
    int Key1[6];
    int Key2[6];
};
struct FUN_006e7b60 : public FUN_0052d240_obj
{
    FUN_006e7b60();
};
struct OwnS
{
    RetS FUN_006e7cc0(const M24&, const M24&);
};

// Clamps the spline parameter to the last node and returns the interpolated location between the surrounding nodes into aOutLoc.
// @fnv 0x006e7a10
void FUN_006e7a10_shell::GetLocationAtSplineParameter(float afCurrentSplineParameter, NiPoint3* aOutLoc)
{
    unsigned int uiNodeIndex = (int)afCurrentSplineParameter;
    float remainder = afCurrentSplineParameter - uiNodeIndex;
    int isize = GetObjectFlags((char*)this) - 1;
    if ((int)uiNodeIndex >= isize)
    {
        *(NP3S*)aOutLoc = ((LocS*)FUN_00717e50(((FUN_006e7970_shell*)this)->FUN_006e7970(isize)))->GetLocation();
        return;
    }
    FUN_006e7b60 spline;
    FUN_006e7c20(&spline, remainder);
    *(RetS*)aOutLoc =
        ((OwnS*)&spline)
            ->FUN_006e7cc0(
                ((OwnS2*)((FUN_006e7970_shell*)this)->FUN_006e7970(uiNodeIndex))->GetLocationAndTangent(),
                ((OwnS2*)((FUN_006e7970_shell*)this)->FUN_006e7970(uiNodeIndex + 1))->GetLocationAndTangent());
}
}  // namespace fnv_006e7a10

namespace fnv_006e84b0 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
typedef char _sizecheck_PathingSpline[sizeof(SplineInterpolator) == 68 ? 1 : -1];
struct FUN_006e84b0_shell : public PathingSolution
{
    float GetSplineLengthAtParameter(float);
};

struct M24
{
    float f[6];
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    float fData[17];
};
struct FUN_0052d240_obj : public FUN_006e7b60
{
    FUN_0052d240_obj() : FUN_006e7b60()
    {}
    ~FUN_0052d240_obj();
};
struct FUN_006e8450_shell
{
    void SetKeys(const M24&, const M24&);
};
struct FUN_006e9af0_S
{
    float MeasurePathLength(float, float, unsigned int);
};
struct FUN_006e7970_shell
{
    OwnS2* FUN_006e7970(unsigned int);
};
struct FUN_008b6800_S
{
    unsigned int GetObjectFlags();
};
struct FUN_006e78d0_S
{
    float GetTotalPathLength();
};

// @fnv 0x006e84b0
float FUN_006e84b0_shell::GetSplineLengthAtParameter(float afParameter)
{
    if (((FUN_008b6800_S*)this)->GetObjectFlags() == 0)
        return 0.0f;
    if (afParameter >= ((FUN_008b6800_S*)this)->GetObjectFlags() - 1)
        return ((FUN_006e78d0_S*)this)->GetTotalPathLength();
    int inode = (int)afParameter;
    float ftotalLength = 0.0f;
    FUN_0052d240_obj spline;
    for (int i = 0; i < inode; ++i)
    {
        ((FUN_006e8450_shell*)&spline)
            ->SetKeys(((FUN_006e7970_shell*)this)->FUN_006e7970(i)->GetLocationAndTangent(),
                           ((FUN_006e7970_shell*)this)->FUN_006e7970(i + 1)->GetLocationAndTangent());
        ftotalLength += ((FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, 1.0f, 2);
    }
    ((FUN_006e8450_shell*)&spline)
        ->SetKeys(((FUN_006e7970_shell*)this)->FUN_006e7970(inode)->GetLocationAndTangent(),
                       ((FUN_006e7970_shell*)this)->FUN_006e7970(inode + 1)->GetLocationAndTangent());
    ftotalLength += ((FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, afParameter - inode, 2);
    return ftotalLength;
}
}  // namespace fnv_006e84b0

namespace fnv_006e8680 {
void __cdecl FUN_005330e0(float&, float, float);
extern double _gModifierZero;
struct FUN_006e7990_shell
{
    float FUN_006e7990(int);
    int GetObjectFlags();
    float FindSegmentAtFraction(float, float, unsigned int*);
};
// @fnv 0x006e8680
float FUN_006e7990_shell::FindSegmentAtFraction(float afPosition, float afScale, unsigned int* piNode)
{
    bool bFound;
    float fTotal;
    float fDistance;
    float fSequenceTimeRatio;
    FUN_005330e0(afPosition, 0.0f, 1.0f);
    fDistance = afPosition * afScale;
    fTotal = 0.0f;
    bFound = false;
    *piNode = 0;
    fSequenceTimeRatio = 0.0f;
    for (unsigned int i = 0; i < GetObjectFlags() - 1; ++i)
    {
        float fSeg = FUN_006e7990(i);
        if (fTotal + fSeg >= fDistance)
        {
            *piNode = i;
            fSequenceTimeRatio = fSeg != _gModifierZero ? (fDistance - fTotal) / fSeg : 0.0;
            bFound = true;
            break;
        }
        fTotal += fSeg;
    }
    if (!bFound)
    {
        *piNode = GetObjectFlags() - 2;
        fSequenceTimeRatio = 1.0f;
    }
    return *piNode + fSequenceTimeRatio;
}
}  // namespace fnv_006e8680

struct Actor;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
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
struct FUN_006e8d50_shell : public PathingSolution
{
    void FUN_006e8d50(BGSLoadFormBuffer*);
};

struct FUN_006f5100_shell
{
    void FUN_006f5100(BGSLoadFormBuffer*);
};
struct FUN_006e23b0_shell
{
    void FUN_006e23b0(BGSLoadFormBuffer*);
};
struct FUN_006dc910_shell
{
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
};
struct FUN_006e90a0_shell
{
    void FUN_006e90a0(unsigned int, bool);
    FUN_006f5100_shell* FUN_006e8f60(unsigned int);
};
struct FUN_006e9280_shell
{
    void FUN_006e9280(unsigned int, bool);
    FUN_006e23b0_shell* FUN_006e8fa0(unsigned int);
};
struct FUN_006a1400_shell
{
    FUN_006dc910_shell* FUN_006a1400(unsigned int);
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_006a7ad0_shell
{
    unsigned int& FUN_006a7ad0(int);
};
struct PathingAvoidNodeArray
{
    int pad[6];
    PathingAvoidNodeArray();
    ~PathingAvoidNodeArray();
    void SetSize(unsigned int, bool);
};

// Loads pathing solution data from a BGSLoadFormBuffer: fixed fields, then virtual nodes, pathing nodes, avoid nodes, and door IDs when version >= 0x12.
// @fnv 0x006e8d50
void FUN_006e8d50_shell::FUN_006e8d50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((char*)this + 0x40, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x18, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x1c, 4);
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
        ((FUN_006e90a0_shell*)((char*)this + 8))->FUN_006e90a0(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006f5100_shell* virtualNode = ((FUN_006e90a0_shell*)((char*)this + 8))->FUN_006e8f60(i);
            virtualNode->FUN_006f5100(apLoadGameBuffer);
        }
    }
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
        ((FUN_006e9280_shell*)((char*)this + 0x20))->FUN_006e9280(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006e23b0_shell* pathingNode = ((FUN_006e9280_shell*)((char*)this + 0x20))->FUN_006e8fa0(i);
            pathingNode->FUN_006e23b0(apLoadGameBuffer);
        }
    }
    PathingAvoidNodeArray avoidNodeArray;
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
        avoidNodeArray.SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006dc910_shell* avoidNode = ((FUN_006a1400_shell*)&avoidNodeArray)->FUN_006a1400(i);
            avoidNode->LoadPathingAvoidNode(apLoadGameBuffer);
        }
    }
    if (apLoadGameBuffer->GetVersion() >= 0x12)
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
        ((_Mem_20a4*)((char*)this + 0x30))->SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            unsigned int* puiDoorID = &((FUN_006a7ad0_shell*)((char*)this + 0x30))->FUN_006a7ad0(i);
            apLoadGameBuffer->ReadFormIdentifier(puiDoorID);
        }
    }
}

struct PathVec3
{
    float x;
    float y;
    float z;
};

struct PathVecHelper
{
    void Combine(PathVec3* a, PathVec3* b);
};

struct PathMagHelper
{
    float Measure();
};

void PathClampHelper(float* t, float lo, float hi);

class FUN_006e9af0_cls
{
  public:
    void Eval(PathVec3* out, float t);
    float MeasurePathLength(float a, float b, unsigned int n);
};

// @fnv 0x006e9af0
float FUN_006e9af0_cls::MeasurePathLength(float afStart, float afEnd, unsigned int uiSteps)
{
    float sum_2;
    PathVec3 p9;
    unsigned int idx;
    PathVec3 p3;
    PathVec3 p5;
    float t;

    this->Eval(&p9, afStart);
    sum_2 = 0.0f;
    for (idx = 0; idx < uiSteps; idx++)
    {
        t = (afEnd - afStart) * (float)(idx + 1) / (float)uiSteps + afStart;
        PathClampHelper(&t, 0.0f, 1.0f);
        this->Eval(&p5, t);
        ((PathVecHelper*)&p5)->Combine(&p3, &p9);
        sum_2 = sum_2 + ((PathMagHelper*)&p3)->Measure();
        p9 = p5;
    }
    return sum_2;
}

struct Vec
{
    float x, y, z;
    Vec();
};

struct Key
{
    float x, y, z, tx, ty, tz;
    Key& FUN_006e7d10(const Key&);
};
struct Node
{
    Key GetLocationAndTangent();
};
struct Location
{
    Vec FUN_005c3420();
};
struct Tail
{
    Location* FUN_00717e50();
};
struct SplinePath
{
    float unk00, unk04, unk08, unk0c, unk10;
    SplinePath();
    ~SplinePath();
    Key first, second;

    void SetKeys(Key*, Key*);
    float MeasurePathLength(float, float, unsigned int);
    bool FindPointOnSpline(float, float, bool, float*, Vec*, float);
};
struct Solution
{
    unsigned int GetNodeCount();
    Tail* FUN_006b05a0();
    Node* FUN_006e7970(unsigned int);
    Vec GetPointAtDistance(float position, float distance);
};
// Walks the spline nodes from the given position until the remaining distance is consumed, returning the interpolated point or the tail location.
// @fnv 0x006e8790
Vec Solution::GetPointAtDistance(float position, float distance)
{
    if (!GetNodeCount())
        return (const Vec&)_NiPoint3_ZERO;
    if (position >= GetNodeCount() - 1)
        return FUN_006b05a0()->FUN_00717e50()->FUN_005c3420();
    float remaining7 = distance;
    int index = (int)position;
    float parameterTmp = position - index;
    Key next2 = FUN_006e7970(index + 1)->GetLocationAndTangent();
    Key current = FUN_006e7970(index)->GetLocationAndTangent();
    SplinePath spline3;
    ((SplinePath*)&spline3)->SetKeys(&current, &next2);
    float lengthVal = ((SplinePath*)&spline3)->MeasurePathLength(parameterTmp, 1.0f, 2);
    while (index < (int)(GetNodeCount() - 2) && lengthVal < remaining7)
    {
        remaining7 -= lengthVal;
        index = index + 1;
        current.FUN_006e7d10(next2);
        next2.FUN_006e7d10(FUN_006e7970(index + 1)->GetLocationAndTangent());
        ((SplinePath*)&spline3)->SetKeys(&current, &next2);
        parameterTmp = 0.0f;
        lengthVal = ((SplinePath*)&spline3)->MeasurePathLength(0.0f, 1.0f, 2);
    }
    if (lengthVal > remaining7)
    {
        float result6;
        Vec point2;
        if (!(int)((SplinePath*)&spline3)->FindPointOnSpline(parameterTmp, remaining7, true, &result6, &point2, 10.0f))
        {
            point2 = (const Vec&)next2;
        }
        return point2;
    }
    else
    {
        return FUN_006b05a0()->FUN_00717e50()->FUN_005c3420();
    }
}

struct SaveBuffer
{
    void SaveData(void*, unsigned int, int);
    void SaveVariableSizedValue(unsigned int);
    void FUN_00865db0(unsigned int, int);
};
struct SaveEntryA
{
    void FUN_006f50b0(SaveBuffer*);
};
struct SaveEntryB
{
    void FUN_006e2350(SaveBuffer*);
};
struct SaveEntryC
{
    void SaveGame(SaveBuffer*);
};
struct CountView
{
    unsigned int Count();
};
struct SaveArrayA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SaveEntryA* FUN_006e8f60(unsigned int);
};
struct SaveArrayB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SaveEntryB* GetEntry(unsigned int);
};
struct SaveArrayD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int& GetEntry(unsigned int);
};
struct AvoidArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    AvoidArray();
    ~AvoidArray();
    SaveEntryC* GetEntry(unsigned int);
};
struct SaveSolution
{
    int unk00;
    int unk04;
    SaveArrayA first;
    int unk18;
    int unk1c;
    SaveArrayB second;
    SaveArrayD fourth;
    unsigned char flags;
    void FUN_006e8b10(SaveBuffer* buffer);
};
// Writes flags, unk18 and unk1c to the buffer, then serializes the counts and entries of first, second, a local AvoidArray and fourth.
// @fnv 0x006e8b10
void SaveSolution::FUN_006e8b10(SaveBuffer* buffer)
{
    buffer->SaveData(&flags, 1, 0);
    buffer->SaveData(&unk18, 4, 0);
    buffer->SaveData(&unk1c, 4, 0);
    unsigned int countA9 = &first ? ((CountView*)&first)->Count() : 0;
    buffer->SaveVariableSizedValue(countA9);
    for (unsigned int indexA = 0; indexA < countA9; ++indexA)
    {
        SaveEntryA* entryA8 = first.FUN_006e8f60(indexA);
        entryA8->FUN_006f50b0(buffer);
    }
    {
        unsigned int countB8 = &second ? ((CountView*)&second)->Count() : 0;
        buffer->SaveVariableSizedValue(countB8);
        for (unsigned int indexB6 = 0; indexB6 < countB8; ++indexB6)
        {
            SaveEntryB* entryB9 = second.GetEntry(indexB6);
            entryB9->FUN_006e2350(buffer);
        }
    }
    AvoidArray avoided5;
    {
        unsigned int countCA = &avoided5 ? ((CountView*)&avoided5)->Count() : 0;
        buffer->SaveVariableSizedValue(countCA);
        for (unsigned int indexC5 = 0; indexC5 < countCA; ++indexC5)
        {
            SaveEntryC* entryC2 = avoided5.GetEntry(indexC5);
            entryC2->SaveGame(buffer);
        }
    }
    {
        unsigned int countD8 = &fourth ? ((CountView*)&fourth)->Count() : 0;
        buffer->SaveVariableSizedValue(countD8);
        for (unsigned int indexD = 0; indexD < countD8; ++indexD)
        {
            unsigned int& entryD3 = fourth.GetEntry(indexD);
            buffer->FUN_00865db0(entryD3, 0);
        }
    }
}

void __cdecl FUN_005330e0(float& arfValue, float afMin, float afMax);

struct FUN_004a7290_point
{
    float FUN_004a7290() const;
};

struct FUN_006e9830_shell
{
    char pad[0x14];
    NiPoint3 kStart;
    char padCur[0x2c - 0x20];
    NiPoint3 kEnd;
    NiPoint3 FUN_006e9ab0(float afT);
    bool FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT, NiPoint3* apkOutPoint,
                             float afTolerance);
};

// Binary-searches the segment parameter so the point is within tolerance of afDistance from the point at afT, writing the found t and point to the outputs.
// @fnv 0x006e9830
bool FUN_006e9830_shell::FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT,
                                             NiPoint3* apkOutPoint, float afTolerance)
{
    if (afDistance <= afTolerance)
    {
        *apkOutPoint = FUN_006e9ab0(afT);
        *apfOutT = afT;
        return true;
    }

    float kFMaxSqr = (afDistance + afTolerance) * (afDistance + afTolerance);
    float fNewMinSqr = (afDistance - afTolerance) * (afDistance - afTolerance);
    FUN_005330e0(afT, 0.0f, 1.0f);

    float fMin;
    float fHigh2;
    float fCurrentAmountNext;
    if (abForward)
    {
        fMin = afT;
        fCurrentAmountNext = fHigh2 = 1.0f;
    }
    else
    {
        fMin = 0.0f;
        fHigh2 = afT;
        fCurrentAmountNext = fMin;
    }

    NiPoint3 _kOrigin = FUN_006e9ab0(afT);
    NiPoint3 kPoint = abForward ? kEnd : kStart;
    bool bFound = false;
    while (!bFound)
    {
        kPoint = FUN_006e9ab0(fCurrentAmountNext);
        float _fLength = ((const FUN_004a7290_point*)&(_kOrigin - kPoint))->FUN_004a7290();
        if ((_fLength < fNewMinSqr && abForward) || (_fLength > kFMaxSqr && !abForward))
        {
            if (fCurrentAmountNext >= 0.99f)
            {
                bFound = false;
                break;
            }
            else
                fMin = fCurrentAmountNext;
        }
        else if ((_fLength > kFMaxSqr && abForward) || (_fLength < fNewMinSqr && !abForward))
        {
            if (fCurrentAmountNext <= 0.01f)
            {
                bFound = false;
                break;
            }
            else
                fHigh2 = fCurrentAmountNext;
        }
        else
        {
            bFound = true;
            break;
        }
        fCurrentAmountNext = (fMin + fHigh2) * 0.5;
    }

    if (!bFound)
    {
        if (abForward)
        {
            *apfOutT = 1.0f;
            *apkOutPoint = kEnd;
        }
        else
        {
            *apfOutT = 0.0f;
            *apkOutPoint = kStart;
        }
        return false;
    }
    else
    {
        *apfOutT = fCurrentAmountNext;
        *apkOutPoint = kPoint;
        return true;
    }
}

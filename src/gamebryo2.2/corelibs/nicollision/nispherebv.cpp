
// src/gamebryo2.2/corelibs/nicollision/nispherebv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nispherebv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream
{
    void GetLoadedObject();
};

struct NiObject
{
    virtual void LinkObject(NiStream&);
};

struct NiSphere
{
    void LoadBinary(NiStream&);
};

struct NiSphereBV : NiObject
{
    NiSphere m_kBoundingSphere;
    void FUN_00eab860(NiStream& kStream);
};

// @fnv 0x00eab860
void NiSphereBV::FUN_00eab860(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    m_kBoundingSphere.LoadBinary(kStream);
}

namespace fnv_00eab880 {
struct NiStream;
struct NiBoundingVolume
{
    void SaveBinary(NiStream&);
};
struct NiSphere
{
    void SaveBinary(NiStream&);
};
struct NiSphereBV : NiBoundingVolume
{
    NiSphere m_kBoundingSphere;
    void FUN_00eab880(NiStream&);
};

// @fnv 0x00eab880
void NiSphereBV::FUN_00eab880(NiStream& kStream)
{
    NiBoundingVolume::SaveBinary(kStream);
    ((NiSphere*)((char*)this + 4))->SaveBinary(kStream);
}
}  // namespace fnv_00eab880

namespace fnv_00eab8d0 {
struct NiPoint3
{
    float x, y, z;
};

struct NiSphere
{
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

struct NiBoundingVolume
{
    NiBoundingVolume* m_pParent;
    NiSphere m_kBoundingSphere;
};

struct NiSphereBV : NiBoundingVolume
{
    void CopySphereFrom(const NiBoundingVolume&);
};

// Copies the sphere (center and radius) from the given bounding volume into this sphere bounding volume.
// @fnv 0x00eab8d0
void NiSphereBV::CopySphereFrom(const NiBoundingVolume& kABV)
{
    NiSphereBV* kSBV = this;
    kSBV->m_kBoundingSphere = kABV.m_kBoundingSphere;
}
}  // namespace fnv_00eab8d0

struct NiBoundingVolume
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3() const;
};
struct Q
{
    bool FUN_00a92660(Q const&) const;
};
struct MyBV
{
    void* _vf;
    Q m_kBoundingSphere;
    int FUN_00eab820(const NiBoundingVolume& kABV);
};
// @fnv 0x00eab820
int MyBV::FUN_00eab820(const NiBoundingVolume& kABV)
{
    return kABV.f3() == 0 && ((Q const*)((char const*)&kABV + 4))->FUN_00a92660(m_kBoundingSphere);
}

extern int DAT_010f1854;
struct Proxy00eab8a0
{
    Proxy00eab8a0* InitFromParams(float, int const*);
};
// Sets the vtable pointer, copies three ints from p into slots 1-3, stores f in slot 4, and returns this.
// @fnv 0x00eab8a0
Proxy00eab8a0* Proxy00eab8a0::InitFromParams(float afValue, int const* paiParams)
{
    *(int*)this = (int)&DAT_010f1854;
    ((int*)this)[1] = paiParams[0];
    ((int*)this)[2] = paiParams[1];
    ((int*)this)[3] = paiParams[2];
    ((float*)this)[4] = afValue;
    return this;
}

struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
extern int DAT_010f1854;
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct FUN_00eac170_Ret
{
    virtual void F(NiStream&);
    NiPoint3 c;
    float r;
};
// @fnv 0x00eac170
FUN_00eac170_Ret* FUN_00eac170(NiStream& kStream)
{
    void* mem = g_memoryManager.Allocate(20);
    FUN_00eac170_Ret* p;
    if (mem)
    {
        *(void**)mem = (void*)&DAT_010f1854;
        ((FUN_00eac170_Ret*)mem)->c = _NiPoint3_ZERO;
        ((FUN_00eac170_Ret*)mem)->r = 1.0f;
        p = (FUN_00eac170_Ret*)mem;
    }
    else
    {
        p = 0;
    }
    p->F(kStream);
    return p;
}

namespace fnv_00eac1d0 {
extern int DAT_010f16f4;
struct P03MM
{
    void __thiscall Deallocate(void*);
};
extern P03MM g_memoryManager;
struct FUN_00eac1d0_shell
{
    void* m_p;
    void* InitAndMaybeFree(bool b);
};
// Sets m_p to DAT_010f16f4, frees this via g_memoryManager.Deallocate when b has bit 0 set, and returns this.
// @fnv 0x00eac1d0
void* FUN_00eac1d0_shell::InitAndMaybeFree(bool abFree)
{
    m_p = &DAT_010f16f4;
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00eac1d0

namespace fnv_00eac200 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int DAT_010f1854;
extern int _NiPoint3_ZERO;
extern int DAT_011f4270;
extern int DAT_011f4274;
struct NiBoundingVolume;
// Allocates 0x14 bytes, initialises a vtable pointer and four fields (including a float set to 1.0), and returns the new NiBoundingVolume or null.
// @fnv 0x00eac200
NiBoundingVolume* CreateNiBoundingVolume()
{
    void* p = g_memoryManager.Allocate(0x14);
    if (p)
    {
        *(void**)p = (void*)&DAT_010f1854;
        *(int*)((char*)p + 4) = _NiPoint3_ZERO;
        *(int*)((char*)p + 8) = DAT_011f4270;
        int k = DAT_011f4274;
        *(float*)((char*)p + 16) = 1.0;
        *(int*)((char*)p + 12) = k;
        return (NiBoundingVolume*)p;
    }
    return 0;
}
}  // namespace fnv_00eac200

namespace fnv_00eacac0 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int DAT_010f1854;
struct S16
{
    int i0;
    int i1;
    int i2;
    int i3;
};
struct BVClone
{
    int v;
    S16 s;
    BVClone* Clone();
};
// Allocates a 20-byte BVClone, sets its vtable pointer and copies the S16 at offset 4 from this, returning the clone or 0.
// @fnv 0x00eacac0
BVClone* BVClone::Clone()
{
    BVClone* pkClone = (BVClone*)g_memoryManager.Allocate(20);
    if (pkClone)
    {
        *(int*)pkClone = (int)&DAT_010f1854;
        *(S16*)((char*)pkClone + 4) = *(S16*)((char*)this + 4);
        return pkClone;
    }
    return 0;
}
}  // namespace fnv_00eacac0

struct S_00eab900_Pt
{
    float x, y, z;
    S_00eab900_Pt()
    {}
    S_00eab900_Pt(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    S_00eab900_Pt operator+(const S_00eab900_Pt& p) const
    {
        return S_00eab900_Pt(x + p.x, y + p.y, z + p.z);
    }
};
inline S_00eab900_Pt operator*(float s, const S_00eab900_Pt& p)
{
    return S_00eab900_Pt(s * p.x, s * p.y, s * p.z);
}
struct S_00eab900_Mat
{
    float e[3][3];
    S_00eab900_Pt operator*(const S_00eab900_Pt& p) const
    {
        return S_00eab900_Pt(e[0][1] * p.y + e[0][0] * p.x + e[0][2] * p.z,
                             e[1][1] * p.y + e[1][0] * p.x + e[1][2] * p.z,
                             e[2][1] * p.y + e[2][0] * p.x + e[2][2] * p.z);
    }
};
struct S_00eab900_Xform
{
    S_00eab900_Mat rot;
    S_00eab900_Pt trans;
    float scale;
};
struct S_00eab900_Bound
{
    void* vf;
    S_00eab900_Pt c;
    float r;
};
struct S_00eab900 : S_00eab900_Bound
{
    void TransformBound(const S_00eab900_Bound& b, const S_00eab900_Xform& x);
};
// Transforms the bound's center by the transform's rotation and scale plus translation, and scales its radius.
// @fnv 0x00eab900
void S_00eab900::TransformBound(const S_00eab900_Bound& aBound, const S_00eab900_Xform& aXform)
{
    c = aXform.scale * (aXform.rot * aBound.c) + aXform.trans;
    r = aBound.r * aXform.scale;
}

struct Point3Lite
{
    float x, y, z;
    Point3Lite()
    {}
    Point3Lite(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    Point3Lite operator-(const Point3Lite& p) const
    {
        Point3Lite r;
        r.x = x - p.x;
        r.y = y - p.y;
        r.z = z - p.z;
        return r;
    }
    float operator*(const Point3Lite& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
};

struct SphereLite
{
    Point3Lite m_kCenter;
    float m_fBoundRadius;
};

struct BoundVolLite
{
    virtual ~BoundVolLite();
};

struct SphereBVLite : BoundVolLite
{
    SphereLite m_kBoundingSphere;
    static bool CheckSweptSphereOverlap(float fTime, const BoundVolLite& kBV0, const Point3Lite& kV0,
                                        const BoundVolLite& kBV1, const Point3Lite& kV1);
};

// Tests whether two moving spheres overlap within fTime by comparing squared centre distance against the squared sum of radii.
// @fnv 0x00eab9d0
bool SphereBVLite::CheckSweptSphereOverlap(float fTime, const BoundVolLite& kBV0, const Point3Lite& kV0,
                                           const BoundVolLite& kBV1, const Point3Lite& kV1)
{
    Point3Lite kVel;
    kVel = kV1 - kV0;
    float fVelSqrLen = kVel.SqrLength();
    const SphereLite& kS0 = ((const SphereBVLite&)kBV0).m_kBoundingSphere;
    const SphereLite& kS1 = ((const SphereBVLite&)kBV1).m_kBoundingSphere;
    Point3Lite kDiff = kS1.m_kCenter - kS0.m_kCenter;
    float fCenterDistSqr = kDiff.SqrLength();
    float fRadiusSum = ((const SphereBVLite&)kBV0).m_kBoundingSphere.m_fBoundRadius +
                       ((const SphereBVLite&)kBV1).m_kBoundingSphere.m_fBoundRadius;
    float fRadiusSumSqr = fRadiusSum * fRadiusSum;
    if (fVelSqrLen > 0.0f)
    {
        float fCenterVelDot = kDiff * kVel;
        if (fCenterVelDot <= 0.0f)
        {
            if (-fTime * fVelSqrLen <= fCenterVelDot)
                return fVelSqrLen * fCenterDistSqr - fCenterVelDot * fCenterVelDot <= fVelSqrLen * fRadiusSumSqr;
            else
                return fTime * (fTime * fVelSqrLen + 2.0f * fCenterVelDot) + fCenterDistSqr <= fRadiusSumSqr;
        }
    }
    return fCenterDistSqr <= fRadiusSumSqr;
}

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl FUN_00aa1070(unsigned int);
extern "C" int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
extern const char str_010f18a4[];
extern const char str_010f1898[];
extern const char str_010f1884[];
extern const double DAT_01017a40;
struct Stream0
{
    int unk00;
    int unk04;
    unsigned short capacity08;
    unsigned short size0a;
    unsigned short unk0c;
    unsigned short grow0e;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char**);
};
struct StringPart0
{
    char* FUN_00a59af0(const char*);
};
struct Display0
{
    int unk00;
    StringPart0 child04;
    int unk08;
    int unk0c;
    float rate10;
    void AppendFormattedText(char* text, Stream0* out);
};
// @fnv 0x00eacbe0
void Display0::AppendFormattedText(char* text, Stream0* out)
{
    char* original;
    unsigned int bytes = strlen(text) + 13;
    original = text;
    text = (char*)FUN_00aa1070(bytes);
    FUN_00a305b0(text, bytes, str_010f18a4, original);
    unsigned int size = out->size0a;
    if (size >= out->capacity08)
        out->FUN_0096ad30(size + out->grow0e);
    out->FUN_0096ae90(size, &text);
    text = child04.FUN_00a59af0(str_010f1898);
    size = out->size0a;
    if (size >= out->capacity08)
        out->FUN_0096ad30(size + out->grow0e);
    out->FUN_0096ae90(size, &text);
    bytes = strlen(original) + 30;
    text = (char*)FUN_00aa1070(bytes);
    int scaled = (int)(rate10 * DAT_01017a40);
    FUN_00a305b0(text, bytes, str_010f1884, (float)scaled / DAT_01017a40);
    size = out->size0a;
    if (size >= out->capacity08)
        out->FUN_0096ad30(size + out->grow0e);
    out->FUN_0096ae90(size, &text);
}

struct Triangle3
{
    Point3Lite m_kStartPoint;
    Point3Lite m_kPoint1;
    Point3Lite m_kPoint2;
};

struct Segment3
{
    Point3Lite m_kStartPoint;
    Point3Lite m_kLightVector;
};

inline Point3Lite operator*(const Point3Lite& p, float s)
{
    Point3Lite r;
    r.x = p.x * s;
    r.y = p.y * s;
    r.z = p.z * s;
    return r;
}

inline bool operator==(const Point3Lite& a, const NiPoint3& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline bool operator!=(const Point3Lite& a, const NiPoint3& b)
{
    return !(a == b);
}

float FUN_00eb1d20(const Segment3&, const Triangle3&, float*, float*, float*);
float GetSquaredDistanceToTriangle(const Point3Lite&, const Triangle3&, float*, float*);

// Builds a triangle from three points and tests whether the sphere's center swept along kV0-kV1 over fTime comes within the sphere radius of the triangle.
// @fnv 0x00eac240
bool SphereTriangleSweepTest(float fTime, const SphereBVLite& kBV0, const Point3Lite& kV0, const Point3Lite& kTriP0,
                             const Point3Lite& kTriP1, const Point3Lite& kTriP2, const Point3Lite& kV1)
{
    Triangle3 kTriangle;
    kTriangle.m_kStartPoint = kTriP0;
    kTriangle.m_kPoint1 = kTriP1 - kTriP0;
    kTriangle.m_kPoint2 = kTriP2 - kTriP0;

    Point3Lite kDelta = kV0 - kV1;

    float fSqrDistance;
    float fTriP0;
    float fTriP1;

    if (kDelta != _NiPoint3_ZERO)
    {
        Segment3 seg;
        seg.m_kStartPoint = kBV0.m_kBoundingSphere.m_kCenter;
        seg.m_kLightVector = kDelta * fTime;

        float fSegP;
        fSqrDistance = FUN_00eb1d20(seg, kTriangle, &fSegP, &fTriP0, &fTriP1);
    }
    else
    {
        fSqrDistance = GetSquaredDistanceToTriangle(kBV0.m_kBoundingSphere.m_kCenter, kTriangle, &fTriP0, &fTriP1);
    }

    double fRadius = kBV0.m_kBoundingSphere.m_fBoundRadius;
    return fSqrDistance <= fRadius * fRadius;
}

struct NiColor
{
    float r, g, b;
    void LoadBinary(NiStream&);
};

struct BinStrB0
{
    unsigned int pad0;
    unsigned int m_uiPos;
    unsigned int (*m_pfnRead)(BinStrB0*, void*, unsigned int, unsigned int*, unsigned int);
};

struct StreamAccess
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    BinStrB0* m_pBinaryStream;
};

inline void ReadRawData(BinStrB0* p, float& f)
{
    unsigned int uiSize = 4;
    p->m_uiPos += p->m_pfnRead(p, &f, 4, &uiSize, 1);
}

struct ObjB0
{
    void* vf;
    NiPoint3 m_iThirdValue;
    float m_r;
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    ObjB0(const NiPoint3& c, float r) : vf(&DAT_010f1854), m_iThirdValue(c), m_r(r)
    {}
};

// Reads three NiColor values and three floats from kStream, then allocates and returns an ObjB0 built from the first color and the third float.
// @fnv 0x00eacb00
ObjB0* ReadObjB0(NiStream& kStream)
{
    NiColor a, b, c;
    a.LoadBinary(kStream);
    b.LoadBinary(kStream);
    c.LoadBinary(kStream);
    float f1, f2, f3;
    ReadRawData(((StreamAccess&)kStream).m_pBinaryStream, f1);
    ReadRawData(((StreamAccess&)kStream).m_pBinaryStream, f2);
    ReadRawData(((StreamAccess&)kStream).m_pBinaryStream, f3);
    return new ObjB0(*(NiPoint3*)&a, f3);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" double sqrt(double);
struct V3
{
    float x, y, z;
    V3()
    {}
    V3(float X, float Y, float Z) : x(X), y(Y), z(Z)
    {}
    V3 operator+(const V3& v) const
    {
        V3 r;
        r.x = x + v.x;
        r.y = y + v.y;
        r.z = z + v.z;
        return r;
    }
    V3 operator-(const V3& v) const
    {
        V3 r;
        r.x = x - v.x;
        r.y = y - v.y;
        r.z = z - v.z;
        return r;
    }
    V3 operator-() const
    {
        V3 r;
        r.x = -x;
        r.y = -y;
        r.z = -z;
        return r;
    }
    V3 operator*(float f) const
    {
        return V3(x * f, y * f, z * f);
    }
    float operator*(const V3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    void FUN_004a0c10();
};
inline V3 operator*(float f, const V3& v)
{
    return V3(f * v.x, f * v.y, f * v.z);
}
struct Sphere0 : BoundVolLite
{
    V3 c;
    float r;
};
extern V3 DAT_011a946c;
inline V3 ScaleLife(const float& f, const V3& v)
{
    return V3(f * v.x, f * v.y, f * v.z);
}
// Tests sphere separation over fDur and writes contact data on a hit; normal outputs are conditional on flag in some branches.
// @fnv 0x00eabb20
bool IntersectSpheres(float afDuration, const Sphere0& A, const V3& B, const Sphere0& C, const V3& D, float& time,
                      V3& point, bool flag, V3& normal0, V3& normal1)
{
    V3& local_point = point;

    float vx = D.x - B.x;
    float vy = D.y - B.y;
    float vz = D.z - B.z;
    V3 a;
    a.x = vx;
    float scale = vy;
    a.y = scale;
    a.z = vz;
    float fRelVelSq = a.SqrLength();
    float fDistSq;
    V3 vCenterDiff = C.c - A.c;
    fDistSq = vCenterDiff.SqrLength();
    float fRadiusA = A.r;
    float fRadiusB = C.r;
    float sum = fRadiusA + fRadiusB;
    float c = sum * sum;
    if (fRelVelSq > 0.0f)
    {
        float p = vCenterDiff * a;
        if (p <= 0.0f)
        {
            if (!(p >= -afDuration * fRelVelSq))
            {
                if (!(afDuration * (fRelVelSq * afDuration + 2.0f * p) + fDistSq <= c + static_cast<double>(1.0e-5f)))
                    return false;
            }
            float b = (float)(fDistSq - c);
            float pForm;
            pForm = p * p - fRelVelSq * b;
            if (pForm >= 0.0f)
            {
                if (b <= 0.0f)
                {
                    time = 0.0f;
                    local_point = 0.5f * (A.c + C.c);
                    if (flag)
                    {
                        if (fDistSq > 1.1920928955078125e-7f)
                        {
                            normal0 = vCenterDiff;
                            normal0.FUN_004a0c10();
                        }
                        else
                            normal0 = DAT_011a946c;
                        normal1 = -normal0;
                    }
                    return true;
                }
                pForm = (float)sqrt(pForm);
                p = -(p + pForm) / fRelVelSq;
                time = p;
                if (time < 0.0f)
                    time = 0.0f;
                else if (time > afDuration)
                    time = afDuration;
                scale = time;
                a = vCenterDiff + ScaleLife(scale, a);
                float disc = A.r / sum;
                V3 y = a * disc;
                vCenterDiff = A.c + time * B;
                local_point = vCenterDiff + y;
                if (flag)
                {
                    normal0 = a;
                    normal0.FUN_004a0c10();
                    V3 n;
                    n = V3(-normal0.x, -normal0.y, -normal0.z);
                    normal1 = n;
                }
                _ReadWriteBarrier();
                return true;
            }
            return false;
        }
    }
    if (!(fDistSq <= c))
        return false;
    time = 0.0f;
    float fDistBSq;
    fDistBSq = D.SqrLength();
    float dotBB = B.SqrLength();
    if (fDistBSq > dotBB)
    {
        normal0 = C.c - A.c;
        normal0.FUN_004a0c10();
        float radius = A.r;
        local_point = A.c + radius * normal0;
        normal1 = -normal0;
        return true;
    }
    normal1 = A.c - C.c;
    normal1.FUN_004a0c10();
    local_point = C.c + C.r * normal1;
    normal0 = -normal1;
    return true;
}

struct DotTerm
{
    const float& first;
    const float& second;
    DotTerm(const float& a, const float& b) : first(a), second(b)
    {}
    double Value() const
    {
        return first * second;
    }
};
inline float SumTerms(DotTerm c, DotTerm a, DotTerm b)
{
    double sum = a.Value();
    sum += b.Value();
    return sum + c.Value();
}
struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float xx, float yy, float zz) : x(xx), y(yy), z(zz)
    {}
    Pt3 operator+(Pt3 const& p) const
    {
        Pt3 r;
        r.x = x + p.x;
        r.y = y + p.y;
        r.z = z + p.z;
        return r;
    }
    Pt3 operator-(Pt3 const& p) const
    {
        return Pt3(x - p.x, y - p.y, z - p.z);
    }
    Pt3 operator-() const
    {
        return Pt3(-x, -y, -z);
    }
    Pt3 operator*(float s) const
    {
        return Pt3(x * s, y * s, z * s);
    }
    float Dot(Pt3 const& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float DotAccumulated(Pt3 const& p) const
    {
        const float* a[2] = {&y, &z};
        const float* b[2] = {&p.y, &p.z};
        double sum = x * p.x;
        for (int i = 0; i < 2; ++i)
            sum += (*a[i]) * (*b[i]);
        return sum;
    }
    float DotPlane(Pt3 const& p) const
    {
        return SumTerms(DotTerm(z, p.z), DotTerm(x, p.x), DotTerm(y, p.y));
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    Pt3 Cross(Pt3 const& p) const
    {
        return Pt3(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    void FUN_004a0c10();
    float DotProduct(Pt3 const&) const;
};
struct Sphere : BoundVolLite
{
    Pt3 center;
    float radius;
};
struct Triangle
{
    Pt3 origin, edge0, edge1;
    float radiusSquared, b, q;
    Pt3 GetTriangleUnitNormal() const;
};
float __cdecl GetSquaredDistanceToTriangle(Pt3 const&, Triangle const&, float&, float&);
Pt3 __cdecl FUN_004a3760(float, Pt3 const&);
struct Isect
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    void FUN_00eb5e30(Sphere const&, Pt3 const&, Pt3 const&, Pt3 const&, float, float, float, int);
    void Solve(Pt3 const&, Pt3 const&);
    float FUN_00eae6f0();
    int FUN_00be0aa0();
    void FUN_00eae6d0();
    Pt3 const& FUN_00eae700();
    Pt3 const& FUN_00eae710();
};
struct Query
{
    Pt3 c, l;
    Triangle k;
};
// Computes the time and point of collision between a moving sphere and a moving triangle, returning true if they intersect.
// @fnv 0x00eac3f0
bool __cdecl SphereTriangleCollision(float time, Sphere const& sphere, Pt3 const& sphereVelocity, Pt3 const& v0,
                                     Pt3 const& v1, Pt3 const& v2, Pt3 const& triangleVelocity, float& contactTime,
                                     Pt3& contactPoint, bool calcNormals, Pt3& sphereNormal, Pt3& triangleNormal)
{
    Query query;
    query.c = sphere.center;

    query.k.radiusSquared = sphere.radius * sphere.radius;
    query.k.origin = v0;
    query.k.edge0 = v1 - v0;
    query.k.edge1 = v2 - v0;
    float distance = GetSquaredDistanceToTriangle(query.c, query.k, query.k.b, query.k.q) - query.k.radiusSquared;
    if (distance <= 0.0f)
    {
        contactTime = 0.0f;
        contactPoint = query.k.origin + query.k.edge0 * query.k.b + query.k.edge1 * query.k.q;
        if (calcNormals)
        {
            triangleNormal = query.k.GetTriangleUnitNormal();
            sphereNormal = -triangleNormal;
        }
        return true;
    }
    Pt3 vRelativeVelocity = sphereVelocity - triangleVelocity;
    query.l = vRelativeVelocity;
    float speedSquared = vRelativeVelocity.SqrLength();
    if (speedSquared * time <= double(0.00001f))
        return false;
    {
        Pt3 normal = -query.k.edge0.Cross(query.k.edge1);
        float centerProjection = normal.Dot(query.c);
        float planeProjection = normal.DotAccumulated(v0);
        float difference = centerProjection - planeProjection;
        float normalSquared = normal.SqrLength();
        float extentSquared = query.k.radiusSquared * normalSquared;
        if (difference * difference > extentSquared)
        {
            normal.FUN_004a0c10();
            Pt3 vSupport;
            if (centerProjection > planeProjection)
            {
                float direction = normal.Dot(vRelativeVelocity);
                if (direction >= 0.0f)
                    return false;
                vSupport = query.c - FUN_004a3760(sphere.radius, normal);
            }
            else
            {
                float direction = normal.Dot(vRelativeVelocity);
                if (direction <= 0.0f)
                    return false;
                vSupport = FUN_004a3760(sphere.radius, normal) + query.c;
            }
            planeProjection = v0.DotPlane(normal);
            float supportProjection = normal.Dot(vSupport);
            if (supportProjection > planeProjection + double(0.001f))
            {
                if (normal.DotProduct(vSupport + FUN_004a3760(time, query.l)) > planeProjection + double(0.001f))
                    return false;
            }
        }
    }
    Isect intersection;
    intersection.FUN_00eb5e30(sphere, v0, v1, v2, time, 0.001f, 0.0001f, 32);
    intersection.Solve(sphereVelocity, triangleVelocity);
    contactTime = intersection.FUN_00eae6f0();
    if (intersection.FUN_00be0aa0() != 3 && intersection.FUN_00be0aa0() != 2)
    {
        intersection.FUN_00eae6d0();
        return false;
    }
    contactPoint = intersection.FUN_00eae700();
    if (calcNormals)
    {
        sphereNormal = intersection.FUN_00eae710();
        triangleNormal = -sphereNormal;
    }
    intersection.FUN_00eae6d0();
    return true;
}

#include <math.h>
struct PositionDifference
{
    float x, y, z;
    float Dot(const PositionDifference& rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
};

// Computes the squared distance from a point to a triangle, writing the closest point's barycentric coordinates to s and t.
// @fnv 0x00eb5450
float __cdecl GetSquaredDistanceToTriangle(const Point3Lite& first, const Triangle3& second, float* s, float* t)
{
    float tmp0;
    float tmp1;
    float numer;
    float denom;
    float fProjS;
    float fProjT;
    Point3Lite difference = second.m_kStartPoint - first;
    float a = second.m_kPoint1 * second.m_kPoint1;
    float b = second.m_kPoint1 * second.m_kPoint2;
    float c = second.m_kPoint2 * second.m_kPoint2;
    float d = difference * second.m_kPoint1;
    float e = difference * second.m_kPoint2;
    float fSqDist = difference.SqrLength();
    float det = fabsf(a * c - b * b);
    *s = e * b - d * c;
    *t = b * d - a * e;
    if (*t + *s <= det)
    {
        if (*s < 0.0f)
        {
            if (*t < 0.0f)
            {
                if (d < 0.0f)
                {
                    *t = 0.0f;
                    if (-d >= a)
                    {
                        *s = 1.0f;
                        return fabsf(a + 2.0f * d + fSqDist);
                    }
                    fProjS = -d / a;
                    *s = fProjS;
                    return fabsf(fProjS * d + fSqDist);
                }
                *s = 0.0f;
                if (e >= 0.0f)
                {
                    *t = 0.0f;
                    return fabsf(fSqDist);
                }
                if (-e >= c)
                {
                    *t = 1.0f;
                    return fabsf(c + 2.0f * e + fSqDist);
                }
                fProjT = -e / c;
                *t = fProjT;
                return fabsf(fProjT * e + fSqDist);
            }
            *s = 0.0f;
            if (e >= 0.0f)
            {
                *t = 0.0f;
                return fabsf(fSqDist);
            }
            if (-e >= c)
            {
                *t = 1.0f;
                return fabsf(c + 2.0f * e + fSqDist);
            }
            fProjT = -e / c;
            *t = fProjT;
            return fabsf(fProjT * e + fSqDist);
        }
        if (*t < 0.0f)
        {
            *t = 0.0f;
            if (d >= 0.0f)
            {
                *s = 0.0f;
                return fabsf(fSqDist);
            }
            if (-d >= a)
            {
                *s = 1.0f;
                return fabsf(a + 2.0f * d + fSqDist);
            }
            fProjS = -d / a;
            *s = fProjS;
            return fabsf(fProjS * d + fSqDist);
        }
        det = 1.0f / det;
        *s *= det;
        *t *= det;
        return fabsf(*s * (*s * a + *t * b + 2.0 * d) + *t * (*s * b + *t * c + 2.0 * e) + fSqDist);
    }
    if (*s < 0.0f)
    {
        tmp0 = d + b;
        tmp1 = e + c;
        if (tmp1 > tmp0)
        {
            numer = tmp1 - tmp0;
            denom = a - 2.0 * b + c;
            if (numer >= denom)
            {
                *s = 1.0f;
                *t = 0.0f;
                return fabsf(a + 2.0f * d + fSqDist);
            }
            fProjS = numer / denom;
            *s = fProjS;
            *t = 1.0f - fProjS;
            return fabsf((c + 2.0 * e + fSqDist) - numer * *s);
        }
        *s = 0.0f;
        if (tmp1 <= 0.0f)
        {
            *t = 1.0f;
            return fabsf(c + 2.0f * e + fSqDist);
        }
        if (e >= 0.0f)
        {
            *t = 0.0f;
            return fabsf(fSqDist);
        }
        fProjT = -e / c;
        *t = fProjT;
        return fabsf(fProjT * e + fSqDist);
    }
    if (*t < 0.0f)
    {
        tmp0 = e + b;
        tmp1 = d + a;
        if (tmp1 > tmp0)
        {
            numer = tmp1 - tmp0;
            denom = a - 2.0 * b + c;
            if (numer >= denom)
            {
                *t = 1.0f;
                *s = 0.0f;
                return fabsf(c + 2.0f * e + fSqDist);
            }
            fProjT = numer / denom;
            *t = fProjT;
            *s = 1.0f - fProjT;
            return fabsf((a + 2.0 * d + fSqDist) - numer * *t);
        }
        *t = 0.0f;
        if (tmp1 <= 0.0f)
        {
            *s = 1.0f;
            return fabsf(a + 2.0f * d + fSqDist);
        }
        if (d >= 0.0f)
        {
            *s = 0.0f;
            return fabsf(fSqDist);
        }
        fProjS = -d / a;
        *s = fProjS;
        return fabsf(fProjS * d + fSqDist);
    }
    numer = (e + c) - (d + b);
    if (numer <= 0.0f)
    {
        *s = 0.0f;
        *t = 1.0f;
        return fabsf(c + 2.0f * e + fSqDist);
    }
    denom = a - 2.0 * b + c;
    if (numer >= denom)
    {
        *s = 1.0f;
        *t = 0.0f;
        return fabsf(a + 2.0f * d + fSqDist);
    }
    fProjS = numer / denom;
    *s = fProjS;
    *t = 1.0f - fProjS;
    return fabsf((c + 2.0 * e + fSqDist) - numer * *s);
}

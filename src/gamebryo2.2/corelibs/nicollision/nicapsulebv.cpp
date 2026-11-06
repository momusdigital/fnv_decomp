
// src/gamebryo2.2/corelibs/nicollision/nicapsulebv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsulebv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00c1ba40
int __cdecl FUN_00c1ba40()
{
    return 2;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct NiBoundingVolume
{
};
struct NiCapsuleBV : NiBoundingVolume
{
    NiCapsuleBV* FUN_00ea0640(const NiCapsuleBV&);
    NiBoundingVolume* FUN_00ea0700();
};
// @fnv 0x00ea0700
NiBoundingVolume* NiCapsuleBV::FUN_00ea0700()
{
    NiCapsuleBV* pNewInstance = (NiCapsuleBV*)g_memoryManager.Allocate(0x3c);
    if (pNewInstance)
        return pNewInstance->FUN_00ea0640(*this);
    return 0;
}

namespace fnv_00e9f170 {
struct ComparableRecord
{
    bool FUN_00eae690(const ComparableRecord&) const;
};
struct NiBoundingVolume
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int F3() const;
};
struct NiCapsuleBV : NiBoundingVolume
{
    char _pad[28];
    ComparableRecord m_kComparableRecord;
    int FUN_00e9f170(const NiBoundingVolume&) const;
};
// @fnv 0x00e9f170
int NiCapsuleBV::FUN_00e9f170(const NiBoundingVolume& kABV) const
{
    if (kABV.F3() == 2 && ((const NiCapsuleBV&)kABV).m_kComparableRecord.FUN_00eae690(m_kComparableRecord))
        return 1;
    return 0;
}
}  // namespace fnv_00e9f170

namespace fnv_00e9f280 {
struct NiPoint3
{
    float x, y, z;
};
struct NiBoundingVolume
{
    int __vftable;
};
struct NiCapsuleBV : NiBoundingVolume
{
    NiPoint3 m_kCenter;
    NiPoint3 m_kAxisDirection;
    float m_fHalfLength;
    char _pad[0x18];
    float m_fBoundRadius;
    void FUN_00e9f1b0();
    void FUN_00e9f280(const NiBoundingVolume& kABV);
};
// @fnv 0x00e9f280
void NiCapsuleBV::FUN_00e9f280(const NiBoundingVolume& kABV)
{
    NiCapsuleBV* kCBV = (NiCapsuleBV*)&kABV;
    m_kCenter = kCBV->m_kCenter;
    m_kAxisDirection = kCBV->m_kAxisDirection;
    m_fHalfLength = kCBV->m_fHalfLength;
    m_fBoundRadius = kCBV->m_fBoundRadius;
    FUN_00e9f1b0();
}
}  // namespace fnv_00e9f280

extern int DAT_010f17d0;
struct S00ea0640
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    float vf;
    char pad[24];
    float vf2;
    void FUN_00e9f1b0();
    S00ea0640* FUN_00ea0640(S00ea0640* a1);
};
// @fnv 0x00ea0640
S00ea0640* S00ea0640::FUN_00ea0640(S00ea0640* apSource)
{
    v0 = (int)&DAT_010f17d0;
    v1 = apSource->v1;
    v2 = apSource->v2;
    v3 = apSource->v3;
    v4 = apSource->v4;
    v5 = apSource->v5;
    v6 = apSource->v6;
    vf = apSource->vf;
    vf2 = apSource->vf2;
    FUN_00e9f1b0();
    return this;
}

struct MatchList
{
    int unk00;
    int unk04;
    void** entries;
    unsigned short unk0c;
    unsigned short count;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int foundIndex;
};
bool __cdecl FUN_00e9ca50(float value, void* item, unsigned int arg3, unsigned int arg4, unsigned int arg5,
                          unsigned int arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9,
                          unsigned int arg10, unsigned int arg11, unsigned int arg12);
// Scans list->entries for the first item accepted by FUN_00e9ca50, stores its index in list->foundIndex and returns true, otherwise returns false.
// @fnv 0x00e9ec10
bool __cdecl FUN_00e9ec10(float value, MatchList* pMatchList, unsigned int arg3, unsigned int arg4, unsigned int arg5,
                          unsigned int arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9,
                          unsigned int arg10, unsigned int arg11, unsigned int arg12)
{
    for (unsigned int i = 0; i < pMatchList->count; ++i)
    {
        void* item = pMatchList->entries[i];
        if (FUN_00e9ca50(value, item, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12))
        {
            pMatchList->foundIndex = i;
            return true;
        }
    }
    return false;
}

extern double DAT_01011590;

struct S_00e9f1b0_P3
{
    float x, y, z;
    S_00e9f1b0_P3()
    {}
    S_00e9f1b0_P3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
inline S_00e9f1b0_P3 operator*(const S_00e9f1b0_P3& p, float s)
{
    return S_00e9f1b0_P3(p.x * s, p.y * s, p.z * s);
}
inline S_00e9f1b0_P3 operator*(const S_00e9f1b0_P3& p, double s)
{
    return S_00e9f1b0_P3((float)(p.x * s), (float)(p.y * s), (float)(p.z * s));
}
inline S_00e9f1b0_P3 operator-(const S_00e9f1b0_P3& a, const S_00e9f1b0_P3& b)
{
    return S_00e9f1b0_P3(a.x - b.x, a.y - b.y, a.z - b.z);
}

struct S_00e9f1b0_Cls
{
    int unk00;
    S_00e9f1b0_P3 m04;
    S_00e9f1b0_P3 m10;
    float m1c;
    S_00e9f1b0_P3 m20;
    S_00e9f1b0_P3 m2c;
    float m38;
    void FUN_00e9f1b0();
};

// Computes m20 as m04 minus m10 scaled by (m1c - m38), and m2c as that scaled delta times DAT_01011590.
// @fnv 0x00e9f1b0
void S_00e9f1b0_Cls::FUN_00e9f1b0()
{
    m20 = m04 - m10 * (m1c - m38);
    m2c = (m10 * (m1c - m38)) * DAT_01011590;
}

extern float DAT_010141cc;
extern float DAT_01017d00;

struct S_00e9f400_P3
{
    float x, y, z;
};
struct S_00e9f400_Obj
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
    int unk40;
    int unk44;
    void InitFromParams(int a, int b, float c, float d, float e, int f);
    void Solve(int a, int b);
    float FUN_00eae6f0();
    int FUN_00be0aa0();
    S_00e9f400_P3* FUN_00eae700();
    S_00e9f400_P3* FUN_00eae710();
    void FUN_00eae6d0();
};

// @fnv 0x00e9f400
bool __cdecl FUN_00e9f400(float p1, int p2, int p3, int p4, int p5, float* p6, S_00e9f400_P3* p7, bool abWantNormal,
                          S_00e9f400_P3* p9, S_00e9f400_P3* p10)
{
    S_00e9f400_Obj obj;
    obj.InitFromParams(p2, p4, p1, DAT_01017d00, DAT_010141cc, 0x20);
    obj.Solve(p3, p5);
    *p6 = obj.FUN_00eae6f0();
    if (obj.FUN_00be0aa0() != 3 && obj.FUN_00be0aa0() != 2)
    {
        obj.FUN_00eae6d0();
        return false;
    }
    *p7 = *obj.FUN_00eae700();
    if (abWantNormal)
    {
        *p9 = *obj.FUN_00eae710();
        S_00e9f400_P3 n;
        n.x = -p9->x;
        n.y = -p9->y;
        n.z = -p9->z;
        *p10 = n;
    }
    obj.FUN_00eae6d0();
    return true;
}

struct S_Vec3
{
    float x, y, z;
};

struct S_Seg
{
    S_Vec3 p;
    S_Vec3 d;
};

struct S_Capsule
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_Seg seg;
    float radius;
};

struct S_Sphere
{
    int unk00;
    S_Vec3 pos;
    float radius;
};

extern float DAT_011f426c;
extern float DAT_011f4270;
extern float DAT_011f4274;

float __cdecl FUN_00eaf310(const S_Seg* a, const S_Seg* b, float* s, float* t);
float __cdecl DistanceSquaredToSegment(const S_Vec3* p, const S_Seg* b, float* s);

// @fnv 0x00e9f620
bool __cdecl SweepSphereAgainstCapsule(float t, S_Capsule* apCapsule, const S_Vec3* from, S_Sphere* apSphere,
                                       const S_Vec3* to)
{
    S_Vec3 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    float fDistSq;
    float s;
    float fSegParam2;
    bool nz = d.x != DAT_011f426c || d.y != DAT_011f4270 || d.z != DAT_011f4274;
    if (nz)
    {
        S_Seg sweepSeg;
        d.x *= t;
        d.y *= t;
        d.z *= t;
        sweepSeg.p = apSphere->pos;
        sweepSeg.d = d;
        fDistSq = FUN_00eaf310(&sweepSeg, &apCapsule->seg, &s, &fSegParam2);
    }
    else
    {
        fDistSq = DistanceSquaredToSegment(&apSphere->pos, &apCapsule->seg, &s);
    }
    float fRadiusSum = apCapsule->radius + apSphere->radius;
    float fRadiusSumSq = fRadiusSum * fRadiusSum;
    return fDistSq <= fRadiusSumSq;
}

namespace fnv_00ea04b0 {
struct S_00ea04b0_Alloc
{
    void* FUN_00aa3e40(unsigned int sz) throw();
};

extern "C" S_00ea04b0_Alloc DAT_011f6238;

struct S_00ea04b0_Vec3
{
    float x;
    float y;
    float z;
};

extern "C" S_00ea04b0_Vec3 DAT_011f426c;
extern "C" S_00ea04b0_Vec3 DAT_011a946c;

struct S_00ea04b0_Obj
{
    virtual void vfn_00(void* arg);

    S_00ea04b0_Vec3 m_v04;
    S_00ea04b0_Vec3 m_v10;
    float m_f1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float m_f38;

    static void* operator new(unsigned int sz) throw()
    {
        return DAT_011f6238.FUN_00aa3e40(sz);
    }
    static void operator delete(void*, unsigned int) throw()
    {}
    void FUN_00e9f1b0() throw();

    __forceinline S_00ea04b0_Obj(S_00ea04b0_Vec3 v1, S_00ea04b0_Vec3 v2) throw() : m_f1c(1.0f), m_f38(1.0f)
    {
        m_v04 = v2;
        m_v10 = v1;
        FUN_00e9f1b0();
    }
};

// Allocates an S_00ea04b0_Obj from two global Vec3 values, calls vfn_00 with arg, and returns the object.
// @fnv 0x00ea04b0
S_00ea04b0_Obj* CreateObjWithArg(void* arg)
{
    S_00ea04b0_Obj* p = new S_00ea04b0_Obj(DAT_011f426c, DAT_011a946c);
    p->vfn_00(arg);
    return p;
}
}  // namespace fnv_00ea04b0

// The two indirect calls pass &outCount as an argument; the out-count slot has
// to live in an inner scope so that MSVC keeps the call target in EDX *and*
// hoists the `mov edx, [ebx+8]` load to the top of the block (the outer-scope
// version puts the target in EAX, the direct-call version sinks the load).
struct Holder
{
    int unk00;
    int unk04;
    int(__cdecl* unk08)(Holder*, void*, unsigned int, unsigned int*, unsigned int);
};

struct SubA
{
    void FUN_00a59be0(unsigned int a1);
};

struct FUN_00ea0540_cls
{
    void FUN_00a89af0(unsigned int a1);
    void FUN_00ea0540(unsigned int a1);
};

// @fnv 0x00ea0540
void FUN_00ea0540_cls::FUN_00ea0540(unsigned int a1)
{
    unsigned int obj = a1;
    this->FUN_00a89af0(obj);
    reinterpret_cast<SubA*>((char*)this + 0x4)->FUN_00a59be0(obj);
    reinterpret_cast<SubA*>((char*)this + 0x10)->FUN_00a59be0(obj);

    {
        Holder* h = *(Holder**)((char*)obj + 0x24c);
        {
            unsigned int a1 = 4;
            int r1 = h->unk08(h, (char*)this + 0x1c, 4, &a1, 1);
            h->unk04 += r1;
        }
    }
    {
        Holder* h2 = *(Holder**)((char*)obj + 0x24c);
        {
            unsigned int a1 = 4;
            int r2 = h2->unk08(h2, (char*)this + 0x38, 4, &a1, 1);
            h2->unk04 += r2;
        }
    }

    reinterpret_cast<struct S00ea0640*>(this)->FUN_00e9f1b0();
}

struct S_00ea05c0_Bin;
typedef int(__cdecl* S_00ea05c0_Fn)(S_00ea05c0_Bin* b, void* buf, unsigned int size, int* count, unsigned int n);
struct S_00ea05c0_Bin
{
    int unk00;
    int m04;
    int unk08;
    S_00ea05c0_Fn m0c;
    int Read(void* buf, unsigned int size, int* count, unsigned int n)
    {
        return m0c(this, buf, size, count, n);
    }
};
__forceinline void BinW(S_00ea05c0_Bin* bin, void* v, unsigned int bytes)
{
    int sz = 4;
    bin->m04 += bin->Read(v, bytes, &sz, 1);
}

struct NiStream
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S_00ea05c0_Bin* m250;
};
struct NiColorSaveHelper
{
    int a;
    int b;
    int c;
    void SaveBinary(NiStream&);
};
struct NiBoundingVolume_SaveHelper
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    void SaveBinary(NiStream&);
};
struct S_00ea05c0_Cls : NiBoundingVolume_SaveHelper
{
    NiColorSaveHelper m04;
    NiColorSaveHelper m10;
    int m1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int m38;
    void FUN_00ea05c0(NiStream& s);
};

// Saves the base bounding volume, two color helpers, and the 4-byte fields m1c and m38 to the stream.
// @fnv 0x00ea05c0
void S_00ea05c0_Cls::FUN_00ea05c0(NiStream& aStream)
{
    NiBoundingVolume_SaveHelper::SaveBinary(aStream);
    m04.SaveBinary(aStream);
    m10.SaveBinary(aStream);
    BinW(aStream.m250, &m1c, 4);
    BinW(aStream.m250, &m38, 4);
}

namespace fnv_00ea0690 {
struct S_P3
{
    int x, y, z;
};
struct S_00ea0690
{
    void* vt;
    S_P3 center;
    S_P3 axis;
    float unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    float unk38;
    void FUN_00e9f1b0();
};
extern int DAT_011f426c;
extern int DAT_011f4270;
extern int DAT_011f4274;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;

// Allocates a 0x3c-byte object, initializes its vtable, center and axis vectors and two floats to 1.0, calls FUN_00e9f1b0, and returns it.
// @fnv 0x00ea0690
S_00ea0690* __cdecl FUN_00ea0690()
{
    S_00ea0690* p = (S_00ea0690*)g_memoryManager.Allocate(0x3c);
    if (p)
    {
        S_P3 c = {DAT_011f426c, DAT_011f4270, DAT_011f4274};
        S_P3 a = {DAT_011a946c, DAT_011a9470, DAT_011a9474};
        p->unk1c = 1.0f;
        p->unk38 = 1.0f;
        p->vt = &DAT_010f17d0;
        p->center = c;
        p->axis = a;
        p->FUN_00e9f1b0();
        return p;
    }
    return 0;
}
}  // namespace fnv_00ea0690

struct Vec3e
{
    float x, y, z;
};
struct IsectObj
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
    int unk40;
    int unk44;
    int unk48;
    void Initialize(int a, int b, float c, float d, float e, int f);
    void Solve(int a, int b);
    float FUN_00eae6f0();
    int FUN_00be0aa0();
    Vec3e* FUN_00eae700();
    Vec3e* FUN_00eae710();
    void FUN_00eae6d0();
};
extern float DAT_010141cc;
extern float DAT_01017d00;
// @fnv 0x00e9f510
bool __cdecl FUN_00e9f510(float p1, int p2, int p3, int p4, int p5, float* p6, Vec3e* p7, bool abWantNormal, Vec3e* p9,
                          Vec3e* p10)
{
    IsectObj o;
    o.Initialize(p2, p4, p1, DAT_01017d00, DAT_010141cc, 0x20);
    o.Solve(p3, p5);
    *p6 = o.FUN_00eae6f0();
    if (o.FUN_00be0aa0() != 3 && o.FUN_00be0aa0() != 2)
    {
        o.FUN_00eae6d0();
        return false;
    }
    *p7 = *o.FUN_00eae700();
    if (abWantNormal)
    {
        *p9 = *o.FUN_00eae710();
        Vec3e n = {-p9->x, -p9->y, -p9->z};
        *p10 = n;
    }
    o.FUN_00eae6d0();
    return true;
}

struct TrianglePointSet
{
    S_Vec3 m_kStartPoint;
    S_Vec3 m_kPoint1;
    S_Vec3 m_kPoint2;
};

extern const S_Vec3 NiPoint3_ZERO;

float __cdecl FUN_00eaff20(const S_Seg* pkSeg, const TrianglePointSet* pkPgm, float* pfSegParam, float* pfPgmParam0,
                           float* pfPgmParam1);

inline S_Vec3 operator-(const S_Vec3& kA, const S_Vec3& kB)
{
    S_Vec3 kResult;
    kResult.x = kA.x - kB.x;
    kResult.y = kA.y - kB.y;
    kResult.z = kA.z - kB.z;
    return kResult;
}

inline S_Vec3 operator*(const S_Vec3& kA, float fScale)
{
    S_Vec3 kResult;
    kResult.x = kA.x * fScale;
    kResult.y = kA.y * fScale;
    kResult.z = kA.z * fScale;
    return kResult;
}

inline bool operator!=(const S_Vec3& kA, const S_Vec3& kB)
{
    return kA.x != kB.x || kA.y != kB.y || kA.z != kB.z;
}

// @fnv 0x00e9f760
bool __cdecl IsCapsuleSweptHit(float fTime, S_Capsule* pkCapsule0, const S_Vec3* pkVelocity0, S_Capsule* pkCapsule1,
                               const S_Vec3* pkVelocity1)
{
    S_Vec3 kRelVelocity = *pkVelocity1 - *pkVelocity0;
    float fParam0;
    float fParam1;
    float fSqrDist;
    if (kRelVelocity != NiPoint3_ZERO)
    {
        TrianglePointSet kSwept;
        kSwept.m_kStartPoint = pkCapsule1->seg.p;
        kSwept.m_kPoint1 = pkCapsule1->seg.d;
        kSwept.m_kPoint2 = kRelVelocity * fTime;
        fSqrDist = FUN_00eaff20(&pkCapsule0->seg, &kSwept, &fSqrDist, &fParam0, &fParam1);
    }
    else
    {
        fSqrDist = FUN_00eaf310(&pkCapsule0->seg, &pkCapsule1->seg, &fSqrDist, &fParam1);
    }

    float fRadiusSum = pkCapsule0->radius + pkCapsule1->radius;
    float fRadiusSqr = fRadiusSum * fRadiusSum;
    return fSqrDist <= fRadiusSqr;
}

struct S9f2c0_P3
{
    float x, y, z;
    S9f2c0_P3()
    {}
    S9f2c0_P3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    S9f2c0_P3 operator+(const S9f2c0_P3& p) const
    {
        return S9f2c0_P3(x + p.x, y + p.y, z + p.z);
    }
    S9f2c0_P3 operator*(float s) const
    {
        return S9f2c0_P3(x * s, y * s, z * s);
    }
};
struct S9f2c0_M3
{
    float m[3][3];
    S9f2c0_P3 operator*(const S9f2c0_P3& p) const
    {
        return S9f2c0_P3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z, m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                         m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
};
struct S9f2c0_Xf
{
    S9f2c0_M3 m_kOrientation;
    S9f2c0_P3 m_kTranslation;
    float m_fScale;
};
struct S9f2c0_Caps
{
    int vtbl;
    S9f2c0_P3 m_kCenter;
    S9f2c0_P3 m_kAxisDirection;
    float m_fHalfLength;
    S9f2c0_P3 m_kSegOrigin;
    S9f2c0_P3 m_kSegDir;
    float m_fBoundRadius;
    void FUN_00e9f1b0();
    void TransformToWorld(const S9f2c0_Caps& kModel, const S9f2c0_Xf& kWorld);
};

// Transforms the capsule's center, axis, half-length, and bound radius from model to world space using the given transform, then calls FUN_00e9f1b0.
// @fnv 0x00e9f2c0
void S9f2c0_Caps::TransformToWorld(const S9f2c0_Caps& kModel, const S9f2c0_Xf& kWorld)
{
    m_kCenter = (kWorld.m_kOrientation * kModel.m_kCenter) * kWorld.m_fScale + kWorld.m_kTranslation;
    m_kAxisDirection = kWorld.m_kOrientation * kModel.m_kAxisDirection;
    m_fHalfLength = kWorld.m_fScale * kModel.m_fHalfLength;
    m_fBoundRadius = kWorld.m_fScale * kModel.m_fBoundRadius;
    FUN_00e9f1b0();
}

struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(const Vec3& b) : x(b.x), y(b.y), z(b.z)
    {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z)
    {}
    Vec3 operator+(const Vec3& b) const
    {
        return Vec3(x + b.x, y + b.y, z + b.z);
    }
    Vec3 operator-(const Vec3& b) const
    {
        return Vec3(x - b.x, y - b.y, z - b.z);
    }
    Vec3 operator-() const
    {
        return Vec3(-x, -y, -z);
    }
    Vec3 operator*(float s) const
    {
        return Vec3(x * s, y * s, z * s);
    }
    Vec3 Cross(const Vec3& b) const
    {
        return Vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
    float Dot(const Vec3& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }
    __declspec(noalias) void FUN_004a0c10();
};
inline Vec3 operator*(float s, const Vec3& b)
{
    return Vec3(s * b.x, s * b.y, s * b.z);
}
struct CenterPoint
{
    float x, y, z;
    float Dot(const Vec3& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    Vec3 operator+(const Vec3& b) const
    {
        return Vec3(x + b.x, y + b.y, z + b.z);
    }
    Vec3 operator-(const Vec3& b) const
    {
        return Vec3(x - b.x, y - b.y, z - b.z);
    }
};
struct PtOp
{
    float x;
    float y;
    float z;
};
struct Capsule
{
    float f00;
    union
    {
        CenterPoint ptv;
        PtOp pt;
        struct
        {
            float px, py, pz;
        };
    };
    float f10;
    float f14;
    float f18;
    float f1c;
    Vec3 c20;
    Vec3 c2c;
    float radius;
};
struct Trio
{
    Vec3 n;
    Vec3 tmp;
    Vec3 v;
};
struct Query
{
    Vec3 origin;
    Vec3 V;
    Vec3 U;
};
struct BigStruct
{
    Vec3 c20;
    Vec3 c2c;
    Vec3 prod;
};
float __cdecl FUN_00eb1d20(Vec3* c20, Query* q, float* pf3c, float* p30, float* pftmp);
float __cdecl TriangleTriangleDistance(Query* q, BigStruct* bs, float* p30, float* pftmp, float* pR, float* pf3c);
// Tests capsule proximity to the triangle formed by pOrg, pA, and pB, then compares the computed squared distance with the squared radius.
// @fnv 0x00e9f8c0
bool __cdecl CapsuleTriangleIntersect(float afScale, Capsule* apCapsule, Vec3* p2, Vec3* apOrigin, Vec3* apVecA,
                                      Vec3* apVecB, Vec3* apVec6)
{
    float tr, big;
    Query s;
    float fResult;
    Vec3 vDir;
    float i;
    s.origin = *apOrigin;
    s.V = *apVecA - *apOrigin;
    s.U = *apVecB - *apOrigin;
    vDir = *p2 - *apVec6;
    Vec3 n = -s.V.Cross(s.U);
    n.Dot(n);
    fResult = apCapsule->ptv.Dot(n);
    big = apCapsule->f1c > apCapsule->radius ? apCapsule->f1c : apCapsule->radius;
    i = apOrigin->Dot(n);
    float dist = fResult - i;
    if (dist * dist > (float)(n.LengthSquared() * big * big))
    {
        n.FUN_004a0c10();
        Vec3 point;
        if (fResult > i)
        {
            if (n.Dot(vDir) >= 0.0f)
                return false;
            point = apCapsule->ptv - big * n;
        }
        else
        {
            if (n.Dot(vDir) <= 0.0f)
                return false;
            Vec3 vOffset = big * n;
            point = Vec3(apCapsule->ptv.x + vOffset.x, apCapsule->ptv.y + vOffset.y, apCapsule->ptv.z + vOffset.z);
        }
        i = apOrigin->Dot(n);
        Vec3 support = point;
        double dPlane = (double)i + (double)0.001f;
        tr = support.Dot(n);
        if (tr > dPlane)
        {
            point = support + afScale * vDir;
            tr = point.Dot(n);
            if (tr > dPlane)
                return false;
        }
    }
    if (vDir.x != DAT_011f426c)
        goto ftmp;
    if (vDir.y != DAT_011f4270)
        goto ftmp;
    if (vDir.z != DAT_011f4274)
        goto ftmp;
    fResult = FUN_00eb1d20(&apCapsule->c20, &s, &i, &fResult, &tr);
    goto done;
ftmp: {
    BigStruct bigStruct;
    bigStruct.c20 = apCapsule->c20;
    bigStruct.c2c = apCapsule->c2c;
    bigStruct.prod = afScale * vDir;
    fResult = TriangleTriangleDistance(&s, &bigStruct, &fResult, &tr, &big, &i);
}
done:
    return fResult <= apCapsule->radius * apCapsule->radius;
}

#include <math.h>
inline float magnitude(float value)
{
    return (float)fabs(value);
}
inline float dot3(const S_Vec3& a, const S_Vec3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline float component(const S_Vec3& v)
{
    return v.y;
}
inline S_Vec3 cross3(const S_Vec3& a, const S_Vec3& b)
{
    S_Vec3 v;
    v.x = component(a) * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - component(a) * b.x;
    return v;
}

// Computes the squared distance between segments a and b and writes the closest-point parameters s and t.
// @fnv 0x00eaf310
float __cdecl FUN_00eaf310(const S_Seg& a, const S_Seg& b, float& s, float& t)
{
    float edge;
    S_Vec3 vDelta = a.p - b.p;
    float aa = dot3(a.d, a.d);
    float ab = -dot3(b.d, a.d);
    float bb = dot3(b.d, b.d);
    float ad = dot3(a.d, vDelta);
    float bd = -dot3(b.d, vDelta);
    float dd = dot3(vDelta, vDelta);
    float det = magnitude(aa * bb - ab * ab);
    const S_Vec3& vUB = b.d;
    S_Vec3 vCross = cross3(a.d, vUB);
    if (dot3(vCross, vCross) > 0.000001f)
    {
        s = ab * bd - bb * ad;
        t = ab * ad - aa * bd;
        if (s >= 0.0f)
        {
            if (s <= det)
            {
                if (t >= 0.0f)
                {
                    if (t <= det)
                    {
                        float inv = 1.0f / det;
                        s *= inv;
                        t *= inv;
                        return magnitude(s * (aa * s + ab * t + 2.0 * ad) + t * (ab * s + bb * t + 2.0 * bd) + dd);
                    }
                    t = 1.0f;
                    edge = ab + ad;
                    if (edge >= 0.0f)
                    {
                        s = 0.0f;
                        return magnitude(bb + 2.0 * bd + dd);
                    }
                    if (-edge >= aa)
                    {
                        s = 1.0f;
                        return magnitude(aa + bb + dd + 2.0 * (bd + edge));
                    }
                    s = -edge / aa;
                    return magnitude(edge * s + bb + 2.0 * bd + dd);
                }
                t = 0.0f;
                if (ad >= 0.0f)
                {
                    s = 0.0f;
                    return magnitude(dd);
                }
                if (-ad >= aa)
                {
                    s = 1.0f;
                    return magnitude(aa + 2.0 * ad + dd);
                }
                s = -ad / aa;
                return magnitude(ad * s + dd);
            }
            if (t >= 0.0f)
            {
                if (t <= det)
                {
                    s = 1.0f;
                    edge = ab + bd;
                    if (edge >= 0.0f)
                    {
                        t = 0.0f;
                        return magnitude(aa + 2.0 * ad + dd);
                    }
                    if (-edge >= bb)
                    {
                        t = 1.0f;
                        return magnitude(aa + bb + dd + 2.0 * (ad + edge));
                    }
                    t = -edge / bb;
                    return magnitude(edge * t + aa + 2.0 * ad + dd);
                }
                edge = ab + ad;
                if (-edge <= aa)
                {
                    t = 1.0f;
                    if (edge >= 0.0f)
                    {
                        s = 0.0f;
                        return magnitude(bb + 2.0 * bd + dd);
                    }
                    s = -edge / aa;
                    return magnitude(edge * s + bb + 2.0 * bd + dd);
                }
                s = 1.0f;
                edge = ab + bd;
                if (-edge >= bb)
                {
                    t = 1.0f;
                    return magnitude(aa + bb + dd + 2.0 * (ad + edge));
                }
                if (edge > 0.0f)
                {
                    t = 0.0f;
                    return magnitude(aa + 2.0 * ad + dd);
                }
                t = -edge / bb;
                return magnitude(edge * t + aa + 2.0 * ad + dd);
            }
            if (-ad < aa)
            {
                t = 0.0f;
                if (ad >= 0.0f)
                {
                    s = 0.0f;
                    return magnitude(dd);
                }
                s = -ad / aa;
                return magnitude(ad * s + dd);
            }
            s = 1.0f;
            edge = ab + bd;
            if (edge >= 0.0f)
            {
                t = 0.0f;
                return magnitude(aa + 2.0 * ad + dd);
            }
            if (-edge >= bb)
            {
                t = 1.0f;
                return magnitude(aa + bb + dd + 2.0 * (ad + edge));
            }
            t = -edge / bb;
            return magnitude(edge * t + aa + 2.0 * ad + dd);
        }
        if (t >= 0.0f)
        {
            if (t <= det)
            {
                s = 0.0f;
                if (bd >= 0.0f)
                {
                    t = 0.0f;
                    return magnitude(dd);
                }
                if (-bd >= bb)
                {
                    t = 1.0f;
                    return magnitude(bb + 2.0 * bd + dd);
                }
                t = -bd / bb;
                return magnitude(bd * t + dd);
            }
            edge = ab + ad;
            if (edge < 0.0f)
            {
                t = 1.0f;
                if (-edge >= aa)
                {
                    s = 1.0f;
                    return magnitude(aa + bb + dd + 2.0 * (bd + edge));
                }
                s = -edge / aa;
                return magnitude(edge * s + bb + 2.0 * bd + dd);
            }
            s = 0.0f;
            edge = bb + bd;
            if (edge <= 0.0f)
            {
                t = 1.0f;
                return magnitude(bb + 2.0 * bd + dd);
            }
            if (bd >= 0.0f)
            {
                t = 0.0f;
                return magnitude(dd);
            }
            t = -bd / bb;
            return magnitude(bd * t + dd);
        }
        if (ad < 0.0f)
        {
            t = 0.0f;
            if (-ad >= aa)
            {
                s = 1.0f;
                return magnitude(aa + 2.0 * ad + dd);
            }
            s = -ad / aa;
            return magnitude(ad * s + dd);
        }
        s = 0.0f;
        if (bd >= 0.0f)
        {
            t = 0.0f;
            return magnitude(dd);
        }
        if (-bd >= bb)
        {
            t = 1.0f;
            return magnitude(bb + 2.0 * bd + dd);
        }
        t = -bd / bb;
        return magnitude(bd * t + dd);
    }
    if (ab > 0.0f)
    {
        if (ad >= 0.0f)
        {
            s = 0.0f;
            t = 0.0f;
            return magnitude(dd);
        }
        if (-ad <= aa)
        {
            s = -ad / aa;
            t = 0.0f;
            return magnitude(ad * s + dd);
        }
        s = 1.0f;
        edge = aa + ad;
        if (-edge >= ab)
        {
            t = 1.0f;
            return magnitude(aa + bb + dd + 2.0 * (ab + ad + bd));
        }
        t = -edge / ab;
        return magnitude(aa + 2.0 * ad + dd + t * (bb * t + 2.0 * (ab + bd)));
    }
    if (-ad >= aa)
    {
        s = 1.0f;
        t = 0.0f;
        return magnitude(aa + 2.0 * ad + dd);
    }
    if (ad <= 0.0f)
    {
        s = -ad / aa;
        t = 0.0f;
        return magnitude(ad * s + dd);
    }
    s = 0.0f;
    if (ad >= -ab)
    {
        t = 1.0f;
        return magnitude(bb + 2.0 * bd + dd);
    }
    t = -ad / ab;
    return magnitude(dd + t * (2.0 * bd + bb * t));
}

#include <string.h>
void* __cdecl FUN_00aa1070(unsigned int);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
struct S_00ea0730_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
// Formats name as "name = CAPSULE_BV", grows the array if needed, and appends the buffer pointer to arr.
// @fnv 0x00ea0730
void __stdcall AddCapsuleBV(const char* name, S_00ea0730_Arr* arr)
{
    unsigned int n = strlen(name) + 14;
    char* buf = (char*)FUN_00aa1070(n);
    FUN_00a305b0(buf, n, "%s = CAPSULE_BV", name);
    unsigned int i = arr->esize;
    if (i >= arr->size)
        arr->FUN_0096ad30(i + arr->growBy);
    arr->FUN_0096ae90(i, buf);
}

namespace fnv_00e9fdc0 {
struct Vec3
{
    float x, y, z;
    Vec3()
    {}

    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z)
    {}
    Vec3 Cross(const Vec3& b) const
    {
        return Vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
    float Dot(const Vec3& b) const
    {
        float r = x * b.x + y * b.y + z * b.z;
        return r;
    }
    float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }
    __declspec(noalias) void FUN_004a0c10();
    __declspec(noalias) float DotProduct(const Vec3&) const;
    Vec3 FUN_00439e90(const Vec3&) const;
    Vec3 FUN_00439ef0(const Vec3&) const;
};
__forceinline Vec3 operator+(const Vec3& a, const Vec3& b)
{
    return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline Vec3 operator-(const Vec3& a)
{
    Vec3 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    return r;
}
inline Vec3 operator*(const Vec3& a, float s)
{
    return Vec3(a.x * s, a.y * s, a.z * s);
}
inline Vec3 operator*(float s, const Vec3& b)
{
    return Vec3(s * b.x, s * b.y, s * b.z);
}
struct CenterPoint
{
    float x, y, z;
    float Dot(const Vec3& b) const
    {
        float r = x * b.x + y * b.y + z * b.z;
        return r;
    }
    Vec3 FUN_00439e90(const Vec3& b) const;
    Vec3 FUN_00439ef0(const Vec3& b) const;
};
struct PtOp
{
    float x;
    float y;
    float z;
};
struct Capsule
{
    float f00;
    Vec3 ptv;
    float f10;
    float f14;
    float f18;
    float f1c;
    Vec3 c20;
    Vec3 c2c;
    float radius;
};
struct CapsuleSegment
{
    Vec3 p, d;
};
struct CollisionTriangle
{
    Vec3 p, u, v;
    Vec3 GetTriangleUnitNormal() const;
};
struct CapsuleTriangleQuery
{
    void* vtable;
    float maxTime, derivativeStep, inverseStep, threshold;
    int maxIterations, resultType;
    float contactTime;
    Vec3 contactPoint, contactNormal;
    Capsule* capsule;
    CollisionTriangle triangle;
    float inverseRadiusSquared, segmentParameter, triangleParameter;
    void FUN_00eb3750(Capsule*, const Vec3*, const Vec3*, const Vec3*, float, float, float, int);
    void Solve(int, int);
    float FUN_00eae6f0();
    int FUN_00be0aa0();
    const Vec3* FUN_00eae700();
    const Vec3* FUN_00eae710();
    void FUN_00eae6d0();
};
__declspec(noalias) float __cdecl FUN_00eb1d20(const CapsuleSegment*, const CollisionTriangle*, float*, float*, float*);
__declspec(noinline) Vec3 __cdecl FUN_004a3760(float s, const Vec3& v)
{
    return Vec3(s * v.x, s * v.y, s * v.z);
}
extern double DAT_0101dae8;
extern double DAT_01016978;
extern const float DAT_01011d78 = 0.0f;
struct DistanceData
{
    CapsuleSegment segment;
    Vec3 motion;
    CollisionTriangle triangle;
    float radiusSquared, segmentParameter, triangleU, triangleV;
};
// Tests a moving capsule against a triangle for static overlap and swept collision, returning contact time, point, and normal.
// @fnv 0x00e9fdc0
bool __cdecl FUN_00e9fdc0(float afTime, Capsule* apCapsule, Vec3* a2, const Vec3* apTriA, Vec3* apTriB, Vec3* apTriC,
                          Vec3* a6, float* a7, Vec3* apPoint, bool abNormal, Vec3* apNormal, Vec3* apNormal2)
{
    DistanceData collisionData;
    collisionData.segment.p = apCapsule->c20;
    collisionData.segment.d = apCapsule->c2c;
    collisionData.radiusSquared = apCapsule->radius * apCapsule->radius;
    collisionData.triangle.p = *apTriA;
    collisionData.triangle.u = *apTriB - *apTriA;
    collisionData.triangle.v = *apTriC - *apTriA;
    float separation = FUN_00eb1d20(&collisionData.segment, &collisionData.triangle, &collisionData.segmentParameter,
                                    &collisionData.triangleU, &collisionData.triangleV) -
                       collisionData.radiusSquared;
    if (separation <= 0.0f)
    {
        *a7 = 0.0f;
        *apPoint = (collisionData.triangle.p + collisionData.triangleU * collisionData.triangle.u) +
                   collisionData.triangleV * collisionData.triangle.v;
        if (abNormal)
        {
            *apNormal2 = collisionData.triangle.GetTriangleUnitNormal();
            *apNormal = -*apNormal2;
        }
        return true;
    }
    Vec3 motion = *a2 - *a6;
    collisionData.motion = motion;
    float lengthSquared = collisionData.motion.LengthSquared();
    if (lengthSquared * afTime <= DAT_0101dae8)
        return false;
    Vec3 normal = -collisionData.triangle.u.Cross(collisionData.triangle.v);
    float centerPlane = normal.Dot(apCapsule->ptv);
    float extent = apCapsule->f1c > apCapsule->radius ? apCapsule->f1c : apCapsule->radius;
    float radiusPlaneSquared = normal.LengthSquared() * extent * extent;
    float trianglePlane = normal.Dot(*apTriA);
    float planeDistance = centerPlane - trianglePlane;
    if (planeDistance * planeDistance > radiusPlaneSquared)
    {
        normal.FUN_004a0c10();
        Vec3 support;
        if (centerPlane > trianglePlane)
        {
            float speed = motion.Dot(normal);
            if (speed >= DAT_01011d78)
                return false;
            support = apCapsule->ptv.FUN_00439ef0(FUN_004a3760(extent, normal));
        }
        else
        {
            float speed = motion.Dot(normal);
            if (speed <= DAT_01011d78)
                return false;
            support = apCapsule->ptv.FUN_00439e90(FUN_004a3760(extent, normal));
        }
        trianglePlane = normal.Dot(*apTriA);
        double planeLimit = trianglePlane + (double)0.001f;
        float supportPlane = normal.Dot(support);
        if (supportPlane > planeLimit)
        {
            if (normal.DotProduct(support + FUN_004a3760(afTime, collisionData.motion)) >
                trianglePlane + (double)0.001f)
                return false;
        }
    }
    CapsuleTriangleQuery query;
    query.FUN_00eb3750(apCapsule, apTriA, apTriB, apTriC, afTime, DAT_01017d00, DAT_010141cc, 0x20);
    query.Solve((int)a2, (int)a6);
    *a7 = query.FUN_00eae6f0();
    if (query.FUN_00be0aa0() != 3 && query.FUN_00be0aa0() != 2)
    {
        query.FUN_00eae6d0();
        return false;
    }
    const Vec3* point = query.FUN_00eae700();
    *apPoint = *point;
    if (abNormal)
    {
        const Vec3* pNormal = query.FUN_00eae710();
        *apNormal = *pNormal;
        *apNormal2 = -*apNormal;
    }
    query.FUN_00eae6d0();
    return true;
}
}  // namespace fnv_00e9fdc0

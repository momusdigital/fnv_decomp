
// src/gamebryo2.2/corelibs/nicollision/nicapsuletriintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsuletriintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_eb5ce0_Pt
{
    float x, y, z;
    S_eb5ce0_Pt()
    {}
    S_eb5ce0_Pt(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    S_eb5ce0_Pt operator+(const S_eb5ce0_Pt& p) const
    {
        return S_eb5ce0_Pt(x + p.x, y + p.y, z + p.z);
    }
    S_eb5ce0_Pt operator*(float s) const
    {
        return S_eb5ce0_Pt(x * s, y * s, z * s);
    }
    S_eb5ce0_Pt& operator+=(const S_eb5ce0_Pt& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    S_eb5ce0_Pt operator-() const
    {
        return S_eb5ce0_Pt(-x, -y, -z);
    }
    const S_eb5ce0_Pt* GetTriangleUnitNormal(const S_eb5ce0_Pt* p);
};
struct S_eb5ce0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int mode;
    float unk1c;
    S_eb5ce0_Pt p20;
    S_eb5ce0_Pt p2c;
    int unk38;
    S_eb5ce0_Pt p3c;
    S_eb5ce0_Pt pA;
    S_eb5ce0_Pt pB;
    int unk60;
    float s64;
    float s68;
    void FUN_00eb5ce0(int unused, const S_eb5ce0_Pt* d);
};
// Recomputes p20 from p3c, pA, pB and s64/s68, sets p2c to the negated result of GetTriangleUnitNormal on p3c, and offsets p20 by d*unk1c when mode is 2.
// @fnv 0x00eb5ce0
void S_eb5ce0_Obj::FUN_00eb5ce0(int unused, const S_eb5ce0_Pt* d)
{
    p20 = (p3c + pA * s64) + pB * s68;
    S_eb5ce0_Pt n;
    p2c = -*p3c.GetTriangleUnitNormal(&n);
    if (mode == 2)
    {
        p20 += *d * unk1c;
    }
}

extern double DAT_01012070;
struct Point856
{
    float x, y, z;
    Point856()
    {}
    Point856(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point856 operator+(const Point856& p) const
    {
        return Point856(x + p.x, y + p.y, z + p.z);
    }
    Point856 operator*(float s) const
    {
        return Point856(x * s, y * s, z * s);
    }
    Point856& operator+=(const Point856& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
};
struct Pair856
{
    Point856 points[2];
};
struct Triple856
{
    Point856 points[3];
};
struct Source856
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Pair856 pair;
};
struct Frame856
{
    Point856 delta;
    Pair856 pair;
    Triple856 triple;
};
struct Frame2
{
    Pair856 pair;
    Triple856 triple;
};
float __cdecl FUN_00eb1d20(Point856* a, Point856* b, float* time, float* p, float* q);
class Native856
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Source856* source;
    Triple856 triple;
    float scale, p, q;
    float Evaluate(const Point856* a, const Point856* b, float s);
};
// @fnv 0x00eb3640
float Native856::Evaluate(const Point856* apOffset, const Point856* b, float s)
{
    Pair856 pair = source->pair;
    Triple856 localTriple = triple;
    pair.points[0] += *apOffset * s;
    localTriple.points[0] += *b * s;
    float time;
    return (float)((double)(FUN_00eb1d20(pair.points, localTriple.points, &time, &p, &q) * scale) - DAT_01012070);
}

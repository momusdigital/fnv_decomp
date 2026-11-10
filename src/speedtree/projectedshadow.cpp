
// src/speedtree/projectedshadow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/projectedshadow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Sub
{
    void fopen_0044a730(int a, int b);
};
struct V3
{
    float x, y, z;
    V3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
};
struct CProjectedShadow
{
    V3 a;
    V3 b;
    V3 c;
    Sub s;
    CProjectedShadow* ClearVectors();
};
// Zeroes the three V3 members a, b and c, calls FUN_0044a730(0, 0) on s, and returns this.
// @fnv 0x00b3e6c0
CProjectedShadow* CProjectedShadow::ClearVectors()
{
    unsigned char flag;
    unsigned char* r;
    int X[1];
    a.z = 0.0f;
    a.y = 0.0f;
    a.x = 0.0f;
    V3* p = &b;
    p->z = 0.0f;
    p->y = 0.0f;
    p->x = 0.0f;
    V3* q = &c;
    q->z = 0.0f;
    q->y = 0.0f;
    q->x = 0.0f;
    {
        char pad[16];
    }
    {
        Sub* t = &s;
        r = &flag;
        t->fopen_0044a730(0, 0);
    }
    return this;
}

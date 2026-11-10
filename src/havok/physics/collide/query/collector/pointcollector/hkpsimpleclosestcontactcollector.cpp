
// src/havok/physics/collide/query/collector/pointcollector/hkpsimpleclosestcontactcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/pointcollector/hkpsimpleclosestcontactcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct Source
{
    __m128 v0;
    __m128 v1;
};

struct hkpSimpleClosestContactCollector
{
    int unk00;
    float unk04;
    bool flag;
    __m128 v0;
    __m128 v1;

    void Update(Source* src);
};

// If flag is unset or src's v1 w is less than the stored v1 w, sets flag and copies v0, v1 and that w from src.
// @fnv 0x00dafc90
void hkpSimpleClosestContactCollector::Update(Source* src)
{
    if (!flag || src->v1.m128_f32[3] < v1.m128_f32[3])
    {
        flag = true;
        v0 = src->v0;
        v1 = src->v1;
        unk04 = src->v1.m128_f32[3];
    }
}

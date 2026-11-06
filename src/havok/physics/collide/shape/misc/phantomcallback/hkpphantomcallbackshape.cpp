// src/havok/physics/collide/shape/misc/phantomcallback/hkpphantomcallbackshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/phantomcallback/hkpphantomcallbackshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhantomCallbackShape.h"

// 0x00c9e390  ret 0xc
// @fnv 0x00c9e390
void __stdcall FUN_00c9e390(int, int, int)
{}

extern char DAT_01268910[];
void __cdecl FUN_00c90360(void*, void*);

// @fnv 0x00c9e3a0
void __cdecl FUN_00c9e3a0(void* object, void* callback)
{
    FUN_00c90360(object, DAT_01268910);
}

#include <xmmintrin.h>
// @fnv 0x00c9e3b0
__m128* __stdcall FUN_00c9e3b0(int aUnused, int bUnused, __m128* p)
{
    const __m128 z = _mm_setzero_ps();
    p[0] = z;
    p[1] = z;
    return p;
}

// @fnv 0x00c9e3d0
void __stdcall castRayImpl(char* p, int a, int b)
{
    *p = 0;
}

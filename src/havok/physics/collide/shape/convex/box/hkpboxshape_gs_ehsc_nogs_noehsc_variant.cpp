
// src/havok/physics/collide/shape/convex/box/hkpboxshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/box/hkpboxshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpBoxShape.h"
int __cdecl FUN_00c9db70();
float __cdecl FUN_00c9e0f0(float a, float b);
extern "C" void* DAT_0102e388;
struct FUN_00c9db80_class
{
    void __thiscall FUN_00c9db80();
};
struct MemoryManager
{
    virtual ~MemoryManager()
    {}
    virtual void unused()
    {}
    virtual void Free(void* object, unsigned short size) = 0;
};
struct MemoryRouter
{
    unsigned char unknown1[16];
    MemoryManager* manager;
};
struct FUN_00c9e1b0_class
{
    void* vftable;
    unsigned short size;

    int FUN_00c9db80();
    void* FUN_00c9e1b0(unsigned char flags);
};
MemoryRouter* __cdecl _D1A0E0GetMemoryRouter();
int __stdcall FUN_00c9e1a0(int a1, int a2);
extern "C" int DAT_01268940;
void __cdecl FUN_00c90360(int a, int* b);
void __cdecl FUN_00c9db60(int a, int* b);
struct hkAabb;
void __cdecl ComputeAabbFromTransform(const hkTransform& transform, const hkVector4& halfExtents, hkReal tolerance,
                                      hkAabb& out);
struct FUN_00c9dc10_class : public hkpBoxShape
{
    void __thiscall GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
};
extern void* DAT_010c70b4;
struct VectorExtents
{
    float x, y, z, w;
};
struct CenteredPointBounds
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usAllocationSize;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_iType;
    float m_fSphereRadius;
    float m_localCenterX;
    float m_localCenterY;
    float m_localCenterZ;
    VectorExtents m_vHalfExtents;

    CenteredPointBounds* SetExtentsAndRadius(const float* extents, float radius);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" int _mm_movemask_ps(__m128);
extern float DAT_010c44d0[4];
struct S00c9dc40_Box : public hkpBoxShape
{
    void __thiscall getSupportingVertexImpl(const float* src, float* dst);
};
// @fnv 0x00c9dcb0
extern "C" void __stdcall ZeroResult(__m128* result)
{
    *result = _mm_setzero_ps();
}

extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C" const __m128 DAT_010c7030[];

struct FUN_00c9dcd0_vertex
{
    union
    {
        __m128 quad;
        struct
        {
            float x;
            float y;
            float z;
            unsigned int id;
        };
    };
};

struct FUN_00c9dcd0_object
{
    unsigned char unknown00[0x20];
    __m128 halfExtents;

    void __thiscall convertVertexIdsToVerticesImpl(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output);
};

// @fnv 0x00c9dcd0
void __thiscall FUN_00c9dcd0_object::convertVertexIdsToVerticesImpl(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output)
{
    for (int i = count - 1; i >= 0; --i)
    {
        unsigned int id = *ids;
        __m128 value = _mm_mul_ps(DAT_010c7030[id], halfExtents);

        output->quad = value;
        output->id = id | 0x3f000000u;

        ++output;
        ++ids;
    }
}

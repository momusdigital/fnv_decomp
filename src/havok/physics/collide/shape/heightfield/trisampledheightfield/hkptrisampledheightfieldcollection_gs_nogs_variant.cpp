
// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpTriSampledHeightFieldCollection.h"
struct FUN_00d263f0_t
{
    char pad0[0x18];
    void* m_obj;    // +0x18
    int m_field1c;  // +0x1c
    char pad20[0x20];
    char m_buf40[0x40];  // +0x40

    int calcSizeForSpu(int a, int b);
};
struct FUN_00d26760_StandIn
{
    void FUN_00d26760();
};
struct FUN_00d26880_MemoryManagerClient
{
    virtual void BeforeAllocate1() = 0;
    virtual void BeforeAllocate2() = 0;
    virtual void Deallocate(void* object, unsigned short size) = 0;
};
struct FUN_00d26880_MemoryRouter
{
    unsigned char Padding[0x10];
    FUN_00d26880_MemoryManagerClient* Manager;
};
FUN_00d26880_MemoryRouter* _D1A0E0GetMemoryRouter();
struct FUN_00d26880_StandIn : public hkpTriSampledHeightFieldCollection
{
    hkpTriSampledHeightFieldCollection* FUN_00d26880(unsigned int flags);
};
int FUN_00d26390();
struct FUN_00d263a0_data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct FUN_00d263a0_cls
{
    int unk00;
    int unk04;
    FUN_00d263a0_data* unk08;
    int GetNextKey(unsigned int key);
};
int __stdcall FUN_00d26440(int arg0);
struct FUN_00d26450_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* unk18;
    void* FUN_00d26450();
};
class hkpSampledHeightFieldShape : public hkpShape
{
  public:
    int m_unk10;
};
struct S_d264d0_Coll : public hkpTriSampledHeightFieldCollection
{
    hkpSampledHeightFieldShape* FUN_00d26450();
    void FUN_00d264d0(unsigned int key, unsigned short value);
};
__declspec(noinline) hkpSampledHeightFieldShape* S_d264d0_Coll::FUN_00d26450()
{
    return m_pHeightFieldShape;
}
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern int DAT_010ce390;
extern int DAT_010ce370;
void __stdcall FUN_00d21410(int a, int b);
struct Target26700
{
    void __thiscall FUN_00c90510();
};
struct FUN_00d26700
{
    void* m_vptr1;  // +0x00
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr2;  // +0x10
    int m_14;
    void* m_p;  // +0x18
    int m_1c;
    volatile float m_f;  // +0x20
    volatile int m_uiX;  // +0x24
    volatile int m_uiY;  // +0x28
    volatile int m_uiZ;  // +0x2c
    __m128 m_v;          // +0x30

    FUN_00d26700(void* p, float f);
};
class hkMemoryAllocatorD267
{
  public:
    virtual ~hkMemoryAllocatorD267() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& n) throw();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct hkMemoryRouterD267
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD267* m_pStreamAllocator;
    hkMemoryAllocatorD267& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD267 {
extern "C" hkMemoryRouterD267& __cdecl FUN_00c85750() throw();
}

template <class T> struct hkArrayD267
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~hkArrayD267() throw()
    {
        hkMemoryAllocatorD267& alloc = hkRouterD267::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct RefD267 : public hkReferencedObject
{
    void FUN_00c905b0() throw();
};
class hkBase0D267
{
  public:
    virtual ~hkBase0D267() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08[2];
};
class hkBase1D267
{
  public:
    virtual ~hkBase1D267() throw()
    {}
    int unk14;
};
class FUN_00d26760 : public hkBase0D267, public hkBase1D267
{
  public:
    RefD267* m_pkRef;
    int unk1C[2];
    hkArrayD267<short> m_ppData;

    virtual ~FUN_00d26760() throw();
};
struct FUN_00d26450_S
{
    void* FUN_00d26450();
};
struct FUN_00d267c0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* data, int size);
};
void* FUN_00c85750(void);
void FUN_00c908c0(int a1, int a2, int a3, int a4);
struct FUN_00d267c0_t : FUN_00d26450_S
{
    void initWeldingInfo(int mode);
};

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
}
}

struct hkAabb_d26460
{
    N::__m128 m_kMinimumCorner;
    N::__m128 m_kMaximumCorner;
};
struct hkTransform_d26460;
struct hkShape_d26460
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransform_d26460& kTransform, float fTolerance, hkAabb_d26460& kAabbOut);
};
struct FUN_00d26460_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fBoundRadius;
    int unk24;
    int unk28;
    int unk2C;
    N::__m128 m_kTranslation;
    hkShape_d26460* FUN_00d26450();
    void FUN_00d26460(const hkTransform_d26460& kTransform, float fTolerance, hkAabb_d26460& kAabbOut);
};
// @fnv 0x00d26460
void FUN_00d26460_cls::FUN_00d26460(const hkTransform_d26460& kTransform, float fTolerance, hkAabb_d26460& kAabbOut)
{
    hkAabb_d26460 kAabb;
    FUN_00d26450()->getAabb(kTransform, m_fBoundRadius + fTolerance, kAabb);
    N::__m128 kMaxPoint = N::_mm_add_ps(m_kTranslation, kAabb.m_kMaximumCorner);
    N::__m128 kMinBoundsCur = N::_mm_add_ps(m_kTranslation, kAabb.m_kMinimumCorner);
    kAabbOut.m_kMinimumCorner = N::_mm_min_ps(kAabb.m_kMinimumCorner, kMinBoundsCur);
    kAabbOut.m_kMaximumCorner = N::_mm_max_ps(kAabb.m_kMaximumCorner, kMaxPoint);
}

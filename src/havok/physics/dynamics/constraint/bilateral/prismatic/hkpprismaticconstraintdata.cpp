
// src/havok/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPrismaticConstraintData.h"

extern "C" void* __cdecl FUN_00d21a60(void* self, int a, void* b);

struct FUN_00d4f880_class
{
    void* __thiscall getConstraintInfo(int a);
};

// @fnv 0x00d4f880
void* __thiscall FUN_00d4f880_class::getConstraintInfo(int a)
{
    return FUN_00d21a60((char*)this + 0x10, 0xc0, (void*)a);
}

// @fnv 0x00d4f8a0
void __stdcall getRuntimeInfo(int aiUnused, hkpPrismaticConstraintData* apConstraintData)
{
    *(int*)((char*)apConstraintData + 4) = 8;
    *(int*)((char*)apConstraintData + 0) = 0x48;
}

extern int DAT_010d0b3c;
extern int DAT_0102e388;
struct DDCC60World
{
    void removeReference();
};
struct FUN_00d4f8d0_class
{
    int* vtbl;
    void FUN_00d4f8d0();
};
// Sets the vtable to DAT_010d0b3c, releases the DDCC60World reference at offset 0xac if present, then sets the vtable to DAT_0102e388.
// @fnv 0x00d4f8d0
void FUN_00d4f8d0_class::FUN_00d4f8d0()
{
    DDCC60World* p = *reinterpret_cast<DDCC60World**>(reinterpret_cast<unsigned char*>(this) + 0xac);
    vtbl = &DAT_010d0b3c;
    if (p)
        p->removeReference();
    vtbl = &DAT_0102e388;
}

// FUN_00d4f8c0: cdecl constant-return leaf (mov eax,6; ret)
// @fnv 0x00d4f8c0
int FUN_00d4f8c0()
{
    return 6;
}

class hkBoolD4FD
{
  public:
    hkBoolD4FD(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

extern float DAT_01017d00;

class hkTransformD4FD
{
  public:
    hkBoolD4FD IsOrthonormal(float epsilon) const;
    float m_data[16];
};

class hkObjD4FD
{
  public:
    int unk00[8];
    hkTransformD4FD m_kPointA;
    hkTransformD4FD m_kPointB;
    int unkA0[10];
    float m_kMinimumCorner;
    float m_kMaximumCorner;

    hkBoolD4FD IsValid() const;
};

// @fnv 0x00d4fdd0
hkBoolD4FD hkObjD4FD::IsValid() const
{
    return m_kPointA.IsOrthonormal(DAT_01017d00) && m_kPointB.IsOrthonormal(DAT_01017d00) && m_kMinimumCorner <= m_kMaximumCorner;
}

class hkMemoryAllocatorD4FF
{
  public:
    virtual ~hkMemoryAllocatorD4FF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4FF
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4FF* m_pStreamAllocator;
    hkMemoryAllocatorD4FF& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4FF& __cdecl FUN_00c85750();

class FUN_00d4f8d0
{
  public:
    virtual ~FUN_00d4f8d0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d4f8d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4f8d0* FUN_00d4ffd0(unsigned int uiFlags) throw();
};

// Runs the destructor and, when bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00d4ffd0
FUN_00d4f8d0* FUN_00d4f8d0::FUN_00d4ffd0(unsigned int uiFlags) throw()
{
    this->FUN_00d4f8d0::~FUN_00d4f8d0();
    if (uiFlags & 1)
        FUN_00d4f8d0::operator delete(this);
    return this;
}

extern int DAT_010d0b9c;
extern int DAT_0102e388;

struct RefObj
{
    void removeReference();
};

struct Embedded
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
    void Run();
};

struct FUN_00d50c50
{
    int* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Embedded mSub;
    RefObj** mArr;
    int mCount;
    ~FUN_00d50c50();
};

// @fnv 0x00d50c50
FUN_00d50c50::~FUN_00d50c50()
{
    vtbl = &DAT_010d0b9c;
    for (int i = 0; i < mCount; ++i)
    {
        mArr[i]->removeReference();
    }
    mSub.Run();
    vtbl = &DAT_0102e388;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

static __forceinline void hkNormalize3(hkVector4q& v)
{
    __m128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct hkMatrix3q
{
    hkVector4q m_col[3];
};

struct hkpPrismaticTransforms
{
    char pad0[0x10];
    hkMatrix3q m_kRotationA;
    hkVector4 m_kTranslationA;
    hkMatrix3q m_kRotationB;
    hkVector4 m_kTranslationB;
};

struct hkpPrismaticConstraintDataEx : public hkpPrismaticConstraintData
{
    void FUN_00d4fba0(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA, const hkVector4& axisB,
                      const hkVector4& axisAPerp, const hkVector4& axisBPerp);
};

// Stores pivotA/pivotB as translations and builds rotation matrices from axis/axisPerp pairs into m_kBridgeAtoms.
// @fnv 0x00d4fba0
void hkpPrismaticConstraintDataEx::FUN_00d4fba0(const hkVector4& pivotA, const hkVector4& pivotB,
                                                const hkVector4& axisA, const hkVector4& axisB,
                                                const hkVector4& axisAPerp, const hkVector4& axisBPerp)
{
    hkpPrismaticTransforms& t = *reinterpret_cast<hkpPrismaticTransforms*>(&m_kBridgeAtoms);

    reinterpret_cast<hkVector4q&>(t.m_kTranslationA).m_vComponents =
        reinterpret_cast<const hkVector4q&>(pivotA).m_vComponents;
    reinterpret_cast<hkVector4q&>(t.m_kTranslationB).m_vComponents =
        reinterpret_cast<const hkVector4q&>(pivotB).m_vComponents;

    hkMatrix3q& ca = t.m_kRotationA;
    ca.m_col[0].m_vComponents = reinterpret_cast<const hkVector4q&>(axisA).m_vComponents;
    hkNormalize3(ca.m_col[0]);
    ca.m_col[1].m_vComponents = reinterpret_cast<const hkVector4q&>(axisAPerp).m_vComponents;
    hkNormalize3(ca.m_col[1]);
    hkSetCross(ca.m_col[2], ca.m_col[0], ca.m_col[1]);

    hkMatrix3q& cb = t.m_kRotationB;
    cb.m_col[0].m_vComponents = reinterpret_cast<const hkVector4q&>(axisB).m_vComponents;
    hkNormalize3(cb.m_col[0]);
    cb.m_col[1].m_vComponents = reinterpret_cast<const hkVector4q&>(axisBPerp).m_vComponents;
    hkNormalize3(cb.m_col[1]);
    hkSetCross(t.m_kRotationB.m_col[2], t.m_kRotationB.m_col[0], t.m_kRotationB.m_col[1]);
}

#include <math.h>
struct hkVector4Out : public hkVector4
{
    void SetTransformedPosition(const hkTransform& t, const hkVector4& v);
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4q& in, hkVector4q& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetTransposeMul(hkMatrix3q& out, const hkMatrix3q& a, const hkMatrix3q& b)
{
    __m128 c0 = a.m_col[0].m_vComponents;
    __m128 c1 = a.m_col[1].m_vComponents;
    __m128 c2 = a.m_col[2].m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

    for (int i = 0; i < 3; i++)
    {
        const __m128 v = b.m_col[i].m_vComponents;
        __m128 b0 = _mm_shuffle_ps(v, v, 0x00);
        __m128 b1 = _mm_shuffle_ps(v, v, 0x55);
        __m128 b2 = _mm_shuffle_ps(v, v, 0xaa);
        out.m_col[i].m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b0, c0), _mm_mul_ps(b1, c1)), _mm_mul_ps(b2, c2));
    }
}

struct PrismaticWorldSpaceView : public hkpPrismaticConstraintData
{
    void FUN_00d4f8f0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& axis);
};

// Builds a basis from axis, then sets each body's local frame rotation via transpose-multiply and its translation from the transformed pivot.
// @fnv 0x00d4f8f0
void PrismaticWorldSpaceView::FUN_00d4f8f0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                           const hkVector4& pivot, const hkVector4& axis)
{
    hkMatrix3q rot;
    rot.m_col[0].m_vComponents = reinterpret_cast<const hkVector4q&>(axis).m_vComponents;
    hkNormalize3(rot.m_col[0]);

    hkCalculatePerpendicularVector(rot.m_col[0], rot.m_col[1]);
    hkNormalize3(rot.m_col[1]);

    hkSetCross(rot.m_col[2], rot.m_col[0], rot.m_col[1]);

    hkpSetLocalTransformsConstraintAtom& t = m_kBridgeAtoms.m_kTransforms;

    hkSetTransposeMul(reinterpret_cast<hkMatrix3q&>(t.m_kBodyALocalFrame.m_rotation),
                      reinterpret_cast<const hkMatrix3q&>(bodyATransform.m_rotation), rot);
    hkSetTransposeMul(reinterpret_cast<hkMatrix3q&>(t.m_kBodyBLocalFrame.m_rotation),
                      reinterpret_cast<const hkMatrix3q&>(bodyBTransform.m_rotation), rot);

    static_cast<hkVector4Out&>(t.m_kBodyALocalFrame.m_vTranslation).SetTransformedPosition(bodyATransform, pivot);
    static_cast<hkVector4Out&>(t.m_kBodyBLocalFrame.m_vTranslation).SetTransformedPosition(bodyBTransform, pivot);
}

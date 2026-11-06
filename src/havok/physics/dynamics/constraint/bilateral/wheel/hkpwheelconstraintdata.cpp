
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpWheelConstraintData.h"

// Writes 6 and 0x30 into a2[1] and a2[0] when a1 is nonzero, otherwise writes zeros to both.
// @fnv 0x00d4e580
void __stdcall FUN_00d4e580(char a1, int* a2)
{
    if (a1)
    {
        a2[1] = 6;
        a2[0] = 0x30;
    }
    else
    {
        a2[1] = 0;
        a2[0] = 0;
    }
}

void* __cdecl FUN_00d21a60(void* a, int b, int c);
struct FUN_00d4e560
{
    void* __thiscall PopulateInfo(int ai);
};
// @fnv 0x00d4e560
void* __thiscall FUN_00d4e560::PopulateInfo(int aiIndex)
{
    return FUN_00d21a60((char*)this + 0x10, 0x124, aiIndex);
}

// @fnv 0x00d4e5b0
int __cdecl FUN_00d4e5b0()
{
    return 9;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d4e5c0 {
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

struct hkVector4Out : public hkVector4
{
    void setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
};

struct hkRotationQ
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

struct hkTransformQ
{
    hkRotationQ m_rotation;
    hkVector4q m_vTranslation;
};

struct hkpWheelAtomsQ
{
    char m_suspensionBaseHeader[0x10];
    hkTransformQ m_kBodyALocalFrame;
    hkTransformQ m_kBodyBLocalFrame;
    char m_steeringBaseHeader[0x30];
    hkRotationQ m_kRotationA;
    hkRotationQ m_kRotationB;
    char pad120[0x10];
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

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

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4q& out, const hkTransform& t, const hkVector4& v)
{
    static_cast<hkVector4Out&>(out.m_vec).setRotatedInverseDir(t.m_rotation, v);
}

static __forceinline void hkSetTransformedInversePos(hkVector4q& out, const hkTransform& t, const hkVector4& p)
{
    hkVector4q s;
    s.m_vComponents = _mm_sub_ps(reinterpret_cast<const __m128&>(p), reinterpret_cast<const __m128&>(t.m_vTranslation));
    hkSetRotatedInverseDir(out, t, s.m_vec);
}

static __forceinline void hkSetIdentity(hkRotationQ& r)
{
    __m128 zero = _mm_setzero_ps();
    r.m_kColumn0.m_vComponents = zero;
    r.m_kColumn1.m_vComponents = zero;
    r.m_kColumn2.m_vComponents = zero;
    r.m_kColumn0(0) = 1.0f;
    r.m_kColumn1(1) = 1.0f;
    r.m_kColumn2(2) = 1.0f;
}

struct hkpWheelConstraintDataEx : public hkpWheelConstraintData
{
    void UpdateWheelAtoms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                          const hkVector4& axle, const hkVector4& suspensionAxis, const hkVector4& steeringAxis);
};

// Normalizes axle and steering axes, then writes body local frames, rotations, and axle/steering directions into m_kBridgeAtoms.
// @fnv 0x00d4e5c0
void hkpWheelConstraintDataEx::UpdateWheelAtoms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                                const hkVector4& pivot, const hkVector4& axle,
                                                const hkVector4& suspensionAxis, const hkVector4& steeringAxis)
{
    hkVector4q axleN;
    axleN.m_vec = axle;
    hkNormalize3(axleN);

    hkVector4q steeringN;
    steeringN.m_vec = steeringAxis;
    hkNormalize3(steeringN);

    hkpWheelAtomsQ& atoms = *reinterpret_cast<hkpWheelAtomsQ*>(&m_kBridgeAtoms);

    hkSetTransformedInversePos(atoms.m_kBodyALocalFrame.m_vTranslation, bodyATransform, pivot);
    hkSetTransformedInversePos(atoms.m_kBodyBLocalFrame.m_vTranslation, bodyBTransform, pivot);
    hkSetIdentity(atoms.m_kBodyALocalFrame.m_rotation);
    hkSetRotatedInverseDir(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, bodyBTransform, suspensionAxis);
    hkCalculatePerpendicularVector(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
                                   atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkNormalize3(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCross(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn2, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
               atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);

    {
        hkRotationQ& rotA = atoms.m_kRotationA;
        hkRotationQ& rotB = atoms.m_kRotationB;
        hkSetRotatedInverseDir(rotA.m_kColumn0, bodyATransform, axleN.m_vec);
        hkSetRotatedInverseDir(rotB.m_kColumn0, bodyBTransform, axleN.m_vec);
        reinterpret_cast<hkVector4q&>(m_kAxleDirectionInBodyB).m_vComponents = rotB.m_kColumn0.m_vComponents;
        hkSetRotatedInverseDir(rotA.m_kColumn1, bodyATransform, steeringN.m_vec);
        hkSetRotatedInverseDir(rotB.m_kColumn1, bodyBTransform, steeringN.m_vec);
        reinterpret_cast<hkVector4q&>(m_kSteeringDirectionInBodyB).m_vComponents = rotB.m_kColumn1.m_vComponents;
        hkSetCross(rotA.m_kColumn2, rotA.m_kColumn0, rotA.m_kColumn1);
        hkSetCross(rotB.m_kColumn2, rotB.m_kColumn0, rotB.m_kColumn1);
    }
}
}  // namespace fnv_00d4e5c0

namespace fnv_00d4e960 {
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

struct hkVector4Out : public hkVector4
{
    void setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
};

struct hkRotationQ
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline hkVector4q& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
};

struct hkMatrix3Q
{
    hkVector4q m_col[3];
};

struct hkTransformQ
{
    hkRotationQ m_rotation;
    hkVector4q m_vTranslation;
};

struct hkpWheelAtomsQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformQ m_kBodyALocalFrame;
    hkTransformQ m_kBodyBLocalFrame;
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
    hkRotationQ m_kRotationA;
    hkRotationQ m_kRotationB;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

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

static __forceinline hkReal getA(const hkVector4q& v, int i)
{
    return reinterpret_cast<const hkReal*>(&v.m_vComponents)[i];
}
static __forceinline hkReal getP(const hkVector4q& v, int i)
{
    const hkReal* p = reinterpret_cast<const hkReal*>(&v) + i;
    return *p;
}
static __forceinline hkReal getQ(const hkVector4q& v, int i)
{
    const hkReal* p = reinterpret_cast<const hkReal*>(&v);
    const hkReal* q = p + i;
    return *q;
}
static __forceinline hkReal& refA(hkVector4q& v, int i)
{
    return reinterpret_cast<hkReal*>(&v.m_vComponents)[i];
}
static __forceinline hkReal& refP(hkVector4q& v, int i)
{
    hkReal* p = reinterpret_cast<hkReal*>(&v) + i;
    return *p;
}
static __forceinline hkReal& refQ(hkVector4q& v, int i)
{
    hkReal* p = reinterpret_cast<hkReal*>(&v);
    hkReal* q = p + i;
    return *q;
}
static __forceinline void perpI1(const hkVector4q& in, hkVector4q& out)
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
    refA(out, ok1) = getA(in, ok2);
    refQ(out, ok2) = -getQ(in, ok1);
}

static __forceinline void perpI2(const hkVector4q& in, hkVector4q& out)
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
    refA(out, ok1) = getA(in, ok2);
    refA(out, ok2) = -getA(in, ok1);
}

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4q& out, const hkTransform& t, const hkVector4& v)
{
    static_cast<hkVector4Out&>(out.m_vec).setRotatedInverseDir(t.m_rotation, v);
}

static __forceinline void hkSetTransformedInversePos(hkVector4q& out, const hkTransform& t, const hkVector4& p)
{
    hkVector4q s;
    s.m_vComponents = _mm_sub_ps(reinterpret_cast<const __m128&>(p), reinterpret_cast<const __m128&>(t.m_vTranslation));
    hkSetRotatedInverseDir(out, t, s.m_vec);
}

static __forceinline void hkSetIdentity(hkRotationQ& r)
{
    __m128 zero = _mm_setzero_ps();
    r.m_kColumn0.m_vComponents = zero;
    r.m_kColumn1.m_vComponents = zero;
    r.m_kColumn2.m_vComponents = zero;
    r.m_kColumn0(0) = 1.0f;
    r.m_kColumn1(1) = 1.0f;
    r.m_kColumn2(2) = 1.0f;
}

static __forceinline void hkSetCrossC(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 a = v0.m_vComponents;
    __m128 b = v1.m_vComponents;
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}
static __forceinline void hkSetCrossF(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 b = v1.m_vComponents;
    __m128 a = v0.m_vComponents;
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}
static __forceinline void hkSetCrossD(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    hkVector4q t;
    hkSetCross(t, v0, v1);
    out.m_vComponents = t.m_vComponents;
}

static __forceinline void hkSetVec(hkVector4q& out, const hkVector4& v)
{
    out.m_vComponents = reinterpret_cast<const __m128&>(v);
}

struct WheelConstraintLayout : public hkpConstraintData
{
    int unknown0c;
    hkpWheelAtomsQ m_kBridgeAtoms;
    hkVector4q m_kAxleDirectionInBodyB;
    hkVector4q m_kSteeringDirectionInBodyB;
    void FUN_00d4e960(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axleA, const hkVector4& axleB,
                      const hkVector4& suspensionB, const hkVector4& steeringB);
};

// Populates wheel constraint atoms and axle/steering directions from pivot, axle, suspension, and steering vectors.
// @fnv 0x00d4e960
void WheelConstraintLayout::FUN_00d4e960(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axleA,
                                         const hkVector4& axleB, const hkVector4& suspensionB,
                                         const hkVector4& steeringB)
{
    hkpWheelAtomsQ& atoms = m_kBridgeAtoms;

    hkSetVec(atoms.m_kBodyALocalFrame.m_vTranslation, pivotA);
    hkSetVec(atoms.m_kBodyBLocalFrame.m_vTranslation, pivotB);
    hkSetIdentity(atoms.m_kBodyALocalFrame.m_rotation);

    hkSetVec(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, suspensionB);
    perpI1(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkNormalize3(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCrossF(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn2, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
                atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);

    hkVector4q axleAn;
    hkSetVec(axleAn, axleA);
    hkNormalize3(axleAn);
    atoms.m_kRotationA.m_kColumn0.m_vComponents = axleAn.m_vComponents;

    hkVector4q axleBn;
    hkSetVec(axleBn, axleB);
    hkSetVec(atoms.m_kRotationB.getColumn(0), axleB);
    hkNormalize3(axleBn);
    atoms.m_kRotationB.m_kColumn0.m_vComponents = axleBn.m_vComponents;
    reinterpret_cast<hkVector4q&>(m_kAxleDirectionInBodyB).m_vComponents = axleBn.m_vComponents;

    hkVector4q& baseIn = atoms.m_kRotationA.m_kColumn0;
    perpI2(baseIn, atoms.m_kRotationA.m_kColumn1);
    hkNormalize3(atoms.m_kRotationA.m_kColumn1);
    hkSetVec(atoms.m_kRotationB.m_kColumn1, steeringB);
    hkNormalize3(atoms.m_kRotationB.m_kColumn1);
    reinterpret_cast<hkVector4q&>(m_kSteeringDirectionInBodyB).m_vComponents =
        atoms.m_kRotationB.m_kColumn1.m_vComponents;

    hkSetCrossF(atoms.m_kRotationA.m_kColumn2, atoms.m_kRotationA.m_kColumn0, atoms.m_kRotationA.m_kColumn1);
    hkSetCross(atoms.m_kRotationB.m_kColumn2, atoms.m_kRotationB.m_kColumn0, atoms.m_kRotationB.m_kColumn1);
}
}  // namespace fnv_00d4e960

extern int DAT_010d0a64;
struct WheelHeader
{
    int* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags, m_sReferenceCount;
    unsigned int m_ulUserData;
    WheelHeader() : m_sReferenceCount(1), m_ulUserData(0)
    {
        m_ppVirtualMethodTable = &DAT_010d0a64;
    }
};
union Vec4
{
    __m128 simd;
    volatile float component[4];
};
struct FloatMatrix3
{
    Vec4 axis0, axis1, axis2;
    void SetIdentity()
    {
        __m128 zero = _mm_setzero_ps();
        axis0.simd = zero;
        axis1.simd = zero;
        axis2.simd = zero;
        axis0.component[0] = 1.0f;
        axis1.component[1] = 1.0f;
        axis2.component[2] = 1.0f;
    }
};
struct FUN_00d4f000
{
    unsigned int unk00, unk04, unk08, unk0C;
    FloatMatrix3 m_20;
    Vec4 m_50;
    FloatMatrix3 m_60;
    Vec4 m_90;
    unsigned char unkA0, unkA1, m_a2, unkA3;
    float m_a4, m_a8;
    unsigned char unkAC, unkAD, m_ae, unkAF;
    float m_b0, m_b4;
    unsigned char unkB8, unkB9, m_ba, unkBB, unkBC, unkBD, m_be, unkBF;
    Vec4 m_c0;
    FloatMatrix3 m_d0, m_100;
    unsigned char unk130, unk131;
    volatile unsigned char m_132;
    unsigned char unk133;
    unsigned int unk134, unk138, unk13C;
    FUN_00d4f000();
};
struct FUN_00d4edc0
{
    WheelHeader m_kHeader;
    unsigned int m_reserved0C;
    FUN_00d4f000 m_kBridgeAtoms;
    Vec4 m_kAxleDirectionInBodyB, m_kSteeringDirectionInBodyB;
    FUN_00d4edc0();
};
// Constructs the wheel object by initializing bridge atom parameters, setting matrices to identity, and zeroing vectors.
// @fnv 0x00d4edc0
FUN_00d4edc0::FUN_00d4edc0()
{
    m_kBridgeAtoms.m_a4 = -0.5f;
    m_kBridgeAtoms.m_a2 = 0;
    m_kBridgeAtoms.m_a8 = 0.5f;
    m_kBridgeAtoms.m_ae = 0;
    m_kBridgeAtoms.m_ba = 1;
    m_kBridgeAtoms.m_be = 2;
    m_kBridgeAtoms.m_b4 = m_kBridgeAtoms.m_b0 = 0.0f;
    m_kBridgeAtoms.m_d0.SetIdentity();
    m_kBridgeAtoms.m_100.SetIdentity();
    m_kBridgeAtoms.m_20.SetIdentity();
    __m128 zero = _mm_setzero_ps();
    m_kBridgeAtoms.m_50.simd = zero;
    m_kBridgeAtoms.m_60.SetIdentity();
    m_kBridgeAtoms.m_90.simd = zero;
    m_kBridgeAtoms.m_132 = 0;
}

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet()
    {}
    hkBoolRet(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

extern "C" void IsOrthonormal();
extern float DAT_01267e30;

struct DummyTransform
{
};
typedef hkBoolRet (DummyTransform::*MemFn)(float tol);

struct hkVector4_SSE
{
    __m128 m_vComponents;
};

struct MyAtoms
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
    int unk90;
    float m_suspensionMin;
    float m_suspensionMax;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
};

struct hkpWheelConstraintData_Standin
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    MyAtoms m_kBridgeAtoms;
    hkVector4 m_kAxleDirectionInBodyB;
    hkVector4 m_kSteeringDirectionInBodyB;

    hkBoolRet isValid();
};

// Returns true if IsOrthonormal passes with 0.001f on both body frames and the two rotation-based transforms and m_suspensionMin <= m_suspensionMax.
// @fnv 0x00d4eec0
hkBoolRet hkpWheelConstraintData_Standin::isValid()
{
    MemFn fn;
    *(void**)&fn = (void*)IsOrthonormal;

    __declspec(align(16)) hkTransform t1;
    __declspec(align(16)) hkTransform t2;

    ((hkVector4_SSE*)&t1.m_rotation.m_kColumn0)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationA.m_kColumn0)->m_vComponents;
    ((hkVector4_SSE*)&t1.m_rotation.m_kColumn1)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationA.m_kColumn1)->m_vComponents;
    ((hkVector4_SSE*)&t1.m_rotation.m_kColumn2)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationA.m_kColumn2)->m_vComponents;
    t1.m_vTranslation = *(hkVector4*)&DAT_01267e30;

    ((hkVector4_SSE*)&t2.m_rotation.m_kColumn0)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationB.m_kColumn0)->m_vComponents;
    ((hkVector4_SSE*)&t2.m_rotation.m_kColumn1)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationB.m_kColumn1)->m_vComponents;
    ((hkVector4_SSE*)&t2.m_rotation.m_kColumn2)->m_vComponents =
        ((hkVector4_SSE*)&m_kBridgeAtoms.m_kRotationB.m_kColumn2)->m_vComponents;
    t2.m_vTranslation = *(hkVector4*)&DAT_01267e30;

    return ((((DummyTransform*)&m_kBridgeAtoms.m_kBodyALocalFrame)->*fn)(0.001f) &&
            (((DummyTransform*)&m_kBridgeAtoms.m_kBodyBLocalFrame)->*fn)(0.001f) &&
            (((DummyTransform*)&t1)->*fn)(0.001f) && (((DummyTransform*)&t2)->*fn)(0.001f) &&
            (m_kBridgeAtoms.m_suspensionMin <= m_kBridgeAtoms.m_suspensionMax));
}


// src/havok/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpHingeConstraintData.h"

struct FUN_00cbe1b0_class
{
    void setBodyToNotify(int index);
};

// @fnv 0x00cbe1b0
void FUN_00cbe1b0_class::setBodyToNotify(int index)
{
    reinterpret_cast<unsigned char*>(this)[0xa6] = (unsigned char)(1 << index);
}

extern "C" void* __cdecl FUN_00d21a60(void* thisPtr, int size, int param);

struct hkpHingeConstraintData_ : public hkpConstraintData
{
    void* __thiscall FUN_00cbe210(int param);
};

// @fnv 0x00cbe210
void* __thiscall hkpHingeConstraintData_::FUN_00cbe210(int param)
{
    return FUN_00d21a60((char*)this + 0x10, 0x9c, param);
}

// Writes 5 and 0x28 into target[1] and target[0] when param is nonzero, otherwise writes zeros.
// @fnv 0x00cbe1e0
void __stdcall SetTargetValues(char param, int* target)
{
    if (param)
    {
        target[1] = 5;
        target[0] = 0x28;
    }
    else
    {
        target[1] = 0;
        target[0] = 0;
    }
}

struct FUN_00cbe190_class
{
    void FUN_00cbe190(float value);
};
// @fnv 0x00cbe190
void FUN_00cbe190_class::FUN_00cbe190(float value)
{
    *(float*)((char*)this + 0xa8) = value;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    float value;
    float FUN_00cbe1a0();
};
// @fnv 0x00cbe1a0
float CpuObject::FUN_00cbe1a0()
{
    return value;
}

// Reads a flag byte at +0xA6 and returns it shifted right by one.

class FUN_00cbe1d0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9C;
    unsigned short m_A0;
    unsigned short m_A2;
    unsigned short m_A4;
    unsigned char m_A6;
    unsigned int FUN_00cbe1d0();
};

// @fnv 0x00cbe1d0
unsigned int FUN_00cbe1d0_cls::FUN_00cbe1d0()
{
    return (unsigned int)m_A6 >> 1;
}

// @fnv 0x00cbe230
int __cdecl FUN_00cbe230()
{
    return 1;
}

class hkBoolCBE7
{
  public:
    hkBoolCBE7()
    {}
    hkBoolCBE7(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkTransformCBE7
{
  public:
    float m_data[16];

    hkBoolCBE7 IsOrthonormal(float fEpsilon) const;
};

class FUN_00cbe750_C
{
  public:
    int unk00[8];
    hkTransformCBE7 m_kPointA;
    hkTransformCBE7 m_kPointB;

    hkBoolCBE7 isValid() const;
};

// @fnv 0x00cbe750
hkBoolCBE7 FUN_00cbe750_C::isValid() const
{
    return m_kPointA.IsOrthonormal(0.001f) && m_kPointB.IsOrthonormal(0.001f);
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00cbe240 {
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

    void FUN_004b4ab0(const hkRotation& r, const hkVector4q& v);
    void FUN_00c7f690(const hkTransform& t, const hkVector4& v);
};

struct hkpSetLocalTransformsAtom
{
    hkUint16 m_type;
    hkUint16 unk02;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkVector4q m_kRotationA[3];
    hkVector4q m_kTranslationA;
    hkVector4q m_kRotationB[3];
    hkVector4q m_kTranslationB;
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

struct hkpHingeConstraintDataEx : public hkpHingeConstraintData
{
    void SetLocalTransforms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                            const hkVector4& pivot, const hkVector4& axis);
};

// Builds a perpendicular basis from axis, then writes each body's rotation and translation (pivot) into m_kBridgeAtoms via FUN_004b4ab0 and FUN_00c7f690.
// @fnv 0x00cbe240
void hkpHingeConstraintDataEx::SetLocalTransforms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                                  const hkVector4& pivot, const hkVector4& axis)
{
    hkpSetLocalTransformsAtom& t = *reinterpret_cast<hkpSetLocalTransformsAtom*>(&m_kBridgeAtoms);
    const hkVector4q& axle = reinterpret_cast<const hkVector4q&>(axis);

    hkVector4q perpToAxle1;
    hkVector4q perpToAxle2;
    hkCalculatePerpendicularVector(axle, perpToAxle1);
    hkNormalize3(perpToAxle1);
    hkSetCross(perpToAxle2, axle, perpToAxle1);

    t.m_kRotationA[0].FUN_004b4ab0(bodyATransform.m_rotation, axle);
    t.m_kRotationA[1].FUN_004b4ab0(bodyATransform.m_rotation, perpToAxle1);
    t.m_kRotationA[2].FUN_004b4ab0(bodyATransform.m_rotation, perpToAxle2);
    t.m_kTranslationA.FUN_00c7f690(bodyATransform, pivot);

    t.m_kRotationB[0].FUN_004b4ab0(bodyBTransform.m_rotation, axle);
    t.m_kRotationB[1].FUN_004b4ab0(bodyBTransform.m_rotation, perpToAxle1);
    t.m_kRotationB[2].FUN_004b4ab0(bodyBTransform.m_rotation, perpToAxle2);
    t.m_kTranslationB.FUN_00c7f690(bodyBTransform, pivot);
}
}  // namespace fnv_00cbe240

namespace fnv_00cbe400 {
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

struct hkMatrix3q
{
    hkVector4q m_col[3];
};

struct hkpHingeTransforms
{
    char pad0[0x10];
    hkMatrix3q m_kRotationA;
    hkVector4q m_kTranslationA;
    hkMatrix3q m_kRotationB;
    hkVector4q m_kTranslationB;
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

struct hkpHingeConstraintDataEx : public hkpHingeConstraintData
{
    void FUN_00cbe400(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA, const hkVector4& axisB);
};

// Stores pivotA and pivotB as translations, and builds rotation matrices for A and B from axisA and axisB using hkCalculatePerpendicularVector and hkSetCross.
// @fnv 0x00cbe400
void hkpHingeConstraintDataEx::FUN_00cbe400(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA,
                                            const hkVector4& axisB)
{
    hkpHingeTransforms& t = *reinterpret_cast<hkpHingeTransforms*>(&m_kBridgeAtoms);

    t.m_kTranslationA.m_vComponents = reinterpret_cast<const hkVector4q&>(pivotA).m_vComponents;
    t.m_kTranslationB.m_vComponents = reinterpret_cast<const hkVector4q&>(pivotB).m_vComponents;

    hkVector4q& axleA = t.m_kRotationA.m_col[0];
    axleA.m_vComponents = reinterpret_cast<const hkVector4q&>(axisA).m_vComponents;
    hkNormalize3(axleA);
    hkCalculatePerpendicularVector(axleA, t.m_kRotationA.m_col[1]);
    hkNormalize3(t.m_kRotationA.m_col[1]);
    hkSetCross(t.m_kRotationA.m_col[2], axleA, t.m_kRotationA.m_col[1]);

    hkVector4q& axleB = t.m_kRotationB.m_col[0];
    axleB.m_vComponents = reinterpret_cast<const hkVector4q&>(axisB).m_vComponents;
    hkNormalize3(axleB);
    hkCalculatePerpendicularVector(axleB, t.m_kRotationB.m_col[1]);
    hkNormalize3(t.m_kRotationB.m_col[1]);
    hkSetCross(t.m_kRotationB.m_col[2], axleB, t.m_kRotationB.m_col[1]);
}
}  // namespace fnv_00cbe400

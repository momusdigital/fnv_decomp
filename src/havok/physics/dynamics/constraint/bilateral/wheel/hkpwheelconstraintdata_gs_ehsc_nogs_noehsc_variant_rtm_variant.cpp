
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpWheelConstraintData.h"
void __stdcall FUN_00d4e580(char a1, int* a2);
void* __cdecl FUN_00d21a60(void* a, int b, int c);
struct FUN_00d4e560
{
    void* __thiscall PopulateInfo(int ai);
};
int __cdecl FUN_00d4e5b0();
#include <xmmintrin.h>
#include <math.h>
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

struct WheelSteeringView : hkpConstraintData
{
    int unk0C;
    hkVector4 unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    hkVector4 unk90, unkA0, unkB0, unkC0, unkD0, unkE0, unkF0;
    __m128 steeringDirection;
    hkVector4 unk110;
    __m128 perpendicularDirection;
    hkVector4 unk130;
    __m128 axleDirection, steeringAxis;
};

static __forceinline __m128 WheelAngleCross(const __m128& b, const __m128& a)
{
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(p, q);
}

static __forceinline __m128 WheelAnglePerpendicular(const __m128& a, const __m128& b)
{
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(left, right);
}
struct WheelAngleScalar
{
    __m128 v;
    __forceinline WheelAngleScalar(float x)
    {
        v = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(v, v, 0);
    }
};
// @fnv 0x00d4e480
void __fastcall FUN_00d4e480(hkpWheelConstraintData* self, void*, float angle)
{
    WheelSteeringView& wheel = *reinterpret_cast<WheelSteeringView*>(self);
    float s = sinf(angle);
    float c = sqrtf(1.0f - s * s);
    WheelAngleScalar co(c);
    WheelAngleScalar si(s);
    __m128 cr = WheelAngleCross(wheel.axleDirection, wheel.steeringAxis);
    __m128 st = _mm_mul_ps(cr, si.broadcast());
    __m128 ct = _mm_mul_ps(co.broadcast(), wheel.axleDirection);
    __m128 result = _mm_add_ps(st, ct);
    wheel.steeringDirection = result;
    wheel.perpendicularDirection = WheelAnglePerpendicular(result, wheel.steeringAxis);
}

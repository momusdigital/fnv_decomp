
// src/havok/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpLimitedHingeConstraintData.h"

struct FUN_00cb8a90_class
{
    void __thiscall SetConstraintFlag(int cl);
};

// @fnv 0x00cb8a90
void __thiscall FUN_00cb8a90_class::SetConstraintFlag(int aiBitIndex)
{
    ((char*)this)[0xd6] = (char)(1 << aiBitIndex);
}

extern "C" void* __cdecl FUN_00d21a60(void* self, int a, int b);

struct FUN_00cb8af0_cls
{
    void* __thiscall FUN_00cb8af0(int arg);
};

// @fnv 0x00cb8af0
void* __thiscall FUN_00cb8af0_cls::FUN_00cb8af0(int arg)
{
    return FUN_00d21a60((char*)this + 0x10, 0xcc, arg);
}

struct FUN_00cb8b10Class
{
    void __thiscall FUN_00cb8b10(int* a1, int* a2);
};

// @fnv 0x00cb8b10
void __thiscall FUN_00cb8b10Class::FUN_00cb8b10(int* apUnused, int* a2)
{
    a2[1] = 8;
    a2[0] = 80;
}

struct FUN_00cb8a70_class
{
    void __thiscall FUN_00cb8a70(float v);
};
// @fnv 0x00cb8a70
void __thiscall FUN_00cb8a70_class::FUN_00cb8a70(float v)
{
    *(float*)((char*)this + 0xd8) = v;
}

struct RefObj
{
    void __thiscall RetainReference();
    void __thiscall removeReference();
};
struct FUN_00cb8ac0_class
{
    void __thiscall SetReferencedObject(RefObj* obj);
};
// @fnv 0x00cb8ac0
void __thiscall FUN_00cb8ac0_class::SetReferencedObject(RefObj* pObject)
{
    if (pObject)
        pObject->RetainReference();
    RefObj* pOldObject = *(RefObj**)((char*)this + 0xb0);
    if (pOldObject)
        pOldObject->removeReference();
    *(RefObj**)((char*)this + 0xb0) = pObject;
}

struct DDCC60World
{
    void removeReference();
};
extern int DAT_010c89e4;
extern int DAT_0102e388;
struct FUN_00cb8b40_class
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    void __thiscall DestroyWorldReference();
};
// @fnv 0x00cb8b40
void __thiscall FUN_00cb8b40_class::DestroyWorldReference()
{
    DDCC60World* p = (DDCC60World*)*((int*)this + 44);
    *((int*)this) = (int)&DAT_010c89e4;
    if (p)
        p->removeReference();
    *((int*)this) = (int)&DAT_0102e388;
}

// Stores b at self+0xa2 and its negation at self+0xb6; if a is non-null, zeroes four floats at a->0x30->0x1c.
// @fnv 0x00cb8fe0
void __fastcall FUN_00cb8fe0(char* self, int, int a, bool b)
{
    self[0xa2] = b;
    self[0xb6] = !b;
    if (a)
    {
        int* p = *(int**)((char*)a + 0x30);
        if (p)
        {
            float* f = *(float**)((char*)p + 0x1c);
            if (f)
            {
                f[0] = 0.0f;
                f[1] = 0.0f;
                f[2] = 0.0f;
                f[3] = 0.0f;
            }
        }
    }
}

class FUN_00cb8a80_cls
{
  public:
    char unkPad0[0xd8];
    float m_fD8;
    float FUN_00cb8a80();
};

// @fnv 0x00cb8a80
float FUN_00cb8a80_cls::FUN_00cb8a80()
{
    return m_fD8;
}

struct FUN_00cb8ab0_class
{
    char pad0[0xD6];
    unsigned char m_byteD6;
    char padD7[0x1];

    unsigned char __thiscall FUN_00cb8ab0();
};

// @fnv 0x00cb8ab0
unsigned char __thiscall FUN_00cb8ab0_class::FUN_00cb8ab0()
{
    return m_byteD6 >> 1;
}

// @fnv 0x00cb8b30
int __cdecl FUN_00cb8b30()
{
    return 2;
}

struct hkBoolCB90
{
    char m_cBooleanValue;
    hkBoolCB90()
    {}
    hkBoolCB90(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkTransformCB90
{
    float m_data[16];
    hkBoolCB90 IsOrthonormal(float eps) const;
};

class hkObjCB90
{
  public:
    int unk00[8];
    hkTransformCB90 m_kPointA;
    hkTransformCB90 m_kPointB;
    char unkA0[2];
    bool m_hasC;
    char unkA3[0x1f];
    bool m_cValid;

    hkBoolCB90 isValid() const;
};

// @fnv 0x00cb9020
hkBoolCB90 hkObjCB90::isValid() const
{
    return m_kPointA.IsOrthonormal(1e-3f) && m_kPointB.IsOrthonormal(1e-3f) && (!m_hasC || m_cValid);
}

struct FnvCpu_FUN_00cb9220_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cb9220_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cb9220_CpuAllocator* allocator;
};
FnvCpu_FUN_00cb9220_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00cb9220_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void DestroyWorldReference();
    FnvCpu_FUN_00cb9220_CpuObject* Destroy(unsigned int flags);
};
// Calls DestroyWorldReference, then if flags has bit 0 set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00cb9220
FnvCpu_FUN_00cb9220_CpuObject* FnvCpu_FUN_00cb9220_CpuObject::Destroy(unsigned int flags)
{
    DestroyWorldReference();
    if (flags & 1)
    {
        FnvCpu_FUN_00cb9220_CpuAllocatorHolder* pAllocatorHolder = FUN_00c85750();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

struct FUN_00b5aea0_self
{
    void FUN_00cb9930(int* a, int* b, unsigned int c);
};

struct FUN_00cb9ce0_cls
{
    virtual void v0();
    virtual void* v1(int a);
    virtual void v2(int a);
    virtual int v3(int a, int b);
    virtual void v4(int a, int b);
    int m_004;
    int m_008;
    int m_00c;
    void FUN_00cb9ce0(int a, int b);
};

// @fnv 0x00cb9ce0
void FUN_00cb9ce0_cls::FUN_00cb9ce0(int a, int b)
{
    if (m_004)
    {
        if (b == m_00c)
        {
            m_004 = v3(m_004, a);
        }
        else
        {
            int r = reinterpret_cast<int>(v1(a));
            reinterpret_cast<FUN_00b5aea0_self*>(this)->FUN_00cb9930(reinterpret_cast<int*>(r),
                                                                     reinterpret_cast<int*>(m_004), b);
            v2(m_004);
            m_004 = r;
        }
    }
    else
    {
        int r = reinterpret_cast<int>(v1(a));
        m_00c = a;
        m_004 = r;
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

struct hkVector4D4FE
{
    __m128 m_vComponents;

    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkRotationD4FE
{
    hkVector4D4FE m_kColumn0, m_kColumn1, m_kColumn2;

    __forceinline void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransformD4FE
{
    hkRotationD4FE m_rotation;
    hkVector4D4FE m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

class __declspec(align(16)) FUN_00d4ff60
{
  public:
    FUN_00d4ff60() throw();

    unsigned short m_transformsType;
    unsigned short unk02;
    int unk04, unk08, unk0C;
    hkTransformD4FE m_kBodyALocalFrame;
    hkTransformD4FE m_kBodyBLocalFrame;
    unsigned short m_stabilizationType;
    volatile unsigned char m_stabilizationEnabled;
    volatile unsigned char m_motorEnabled;
    volatile short m_iInitializedOffset;
    volatile short m_iPreviousTargetAngleOffset;
    volatile float m_fTargetAngle;
    volatile unsigned long m_pMotor;
    unsigned short m_frictionType;
    unsigned char unkA2;
    volatile unsigned char m_frictionEnabled;
    volatile float m_fMaxFrictionTorque;
    unsigned short m_ang2dType;
    volatile unsigned char m_ang2dEnabled;
    volatile unsigned char m_ang2dFreeAxis;
    unsigned short m_angTypeB;
    volatile unsigned char m_angAxisB;
    unsigned char unkAF;
    unsigned short m_angTypeC;
    volatile unsigned char m_angAxisC;
    unsigned char unkB3;
    unsigned short m_limitType;
    volatile unsigned char m_limitEnabled;
    unsigned char unkB7;
    volatile float m_fMinAngle;
    volatile float m_fMaxAngle;
    int unkC0, unkC4, unkC8, unkCC;
};

class hkReferencedObjectD4FE
{
  public:
    hkReferencedObjectD4FE() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD4FE() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataD4FE : public hkReferencedObjectD4FE
{
  public:
    hkpConstraintDataD4FE() throw()
    {
        m_ulUserData = 0;
    }
    virtual ~hkpConstraintDataD4FE() throw()
    {}

    unsigned long m_ulUserData;
};

class FUN_00d4fe80 : public hkpConstraintDataD4FE
{
  public:
    FUN_00d4fe80() throw();
    virtual ~FUN_00d4fe80() throw();

    int unk0C;
    FUN_00d4ff60 m_kBridgeAtoms;
};

// @fnv 0x00d4fe80
FUN_00d4fe80::FUN_00d4fe80() throw()
{
    m_kBridgeAtoms.m_kBodyALocalFrame.setIdentity();
    m_kBridgeAtoms.m_kBodyBLocalFrame.setIdentity();
    m_kBridgeAtoms.m_limitEnabled = 0;
    m_kBridgeAtoms.m_fMinAngle = -3.40282e+38f;
    m_kBridgeAtoms.m_frictionEnabled = 0;
    m_kBridgeAtoms.m_fMaxAngle = 3.40282e+38f;
    m_kBridgeAtoms.m_fMaxFrictionTorque = 0.0f;
    m_kBridgeAtoms.m_stabilizationEnabled = 0;
    m_kBridgeAtoms.m_fTargetAngle = 0.0f;
    m_kBridgeAtoms.m_pMotor = 0ul;
    m_kBridgeAtoms.m_motorEnabled = 0;
    m_kBridgeAtoms.m_ang2dEnabled = 0;
    m_kBridgeAtoms.m_iInitializedOffset = 0x40;
    m_kBridgeAtoms.m_iPreviousTargetAngleOffset = 0x44;
    m_kBridgeAtoms.m_ang2dFreeAxis = 3;
    m_kBridgeAtoms.m_angAxisB = 1;
    m_kBridgeAtoms.m_angAxisC = 2;
}

#include <math.h>
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
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
    void SetTransformedPosition(const hkTransform& t, const hkVector4& v);
};

struct hkpSetupStabilizationAtom
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkpLimitedHingeTransforms
{
    hkpSetupStabilizationAtom m_kHeader;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
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

struct hkpLimitedHingeConstraintDataEx : public hkpLimitedHingeConstraintData
{
    void FUN_00cb8b60(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& axis);
};

// Builds perpendicular axes from the normalized axis and stores them with the pivot in m_kBridgeAtoms as local frames for body A and body B via their transforms.
// @fnv 0x00cb8b60
void hkpLimitedHingeConstraintDataEx::FUN_00cb8b60(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                                   const hkVector4& pivot, const hkVector4& axis)
{
    hkVector4q axisN;
    axisN.m_vec = axis;
    hkNormalize3(axisN);

    hkVector4q perpToAxle1;
    hkCalculatePerpendicularVector(axisN, perpToAxle1);
    hkNormalize3(perpToAxle1);

    hkVector4q perpToAxle2;
    hkSetCross(perpToAxle2, axisN, perpToAxle1);

    hkpLimitedHingeTransforms& t = *reinterpret_cast<hkpLimitedHingeTransforms*>(&m_kBridgeAtoms);

    static_cast<hkVector4Out&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn0)
        .setRotatedInverseDir(bodyATransform.m_rotation, axisN.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn1)
        .setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle1.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn2)
        .setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle2.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyALocalFrame.m_vTranslation).SetTransformedPosition(bodyATransform, pivot);

    static_cast<hkVector4Out&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn0)
        .setRotatedInverseDir(bodyBTransform.m_rotation, axisN.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn1)
        .setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle1.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn2)
        .setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle2.m_vec);
    static_cast<hkVector4Out&>(t.m_kBodyBLocalFrame.m_vTranslation).SetTransformedPosition(bodyBTransform, pivot);
}

extern "C"
{
    void _ReadWriteBarrier(void);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct hkVector4_Havok
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4_Havok& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void normalize3()
    {
        __m128 mul = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 xy = _mm_add_ss(y, mul);
        __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 lenSq = _mm_add_ss(z, xy);
        __m128 r = _mm_rsqrt_ss(lenSq);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 half = _mm_set_ss(0.5f);
        __m128 r_sq = _mm_mul_ss(_mm_mul_ss(lenSq, r), r);
        __m128 diff = _mm_sub_ss(three, r_sq);
        __m128 half_r = _mm_mul_ss(half, r);
        __m128 nr = _mm_mul_ss(half_r, diff);
        __m128 mask = _mm_cmpeq_ss(lenSq, zero);
        __m128 inv = _mm_andnot_ps(mask, nr);
        __m128 inv4 = _mm_shuffle_ps(inv, inv, 0);
        m_vComponents = _mm_mul_ps(inv4, m_vComponents);
    }

    __forceinline void setCross(const hkVector4_Havok& a, const hkVector4_Havok& b)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
    }
};

static __forceinline void hkSetCross(hkVector4_Havok& out, const hkVector4_Havok& v0, const hkVector4_Havok& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct hkRotation_Havok
{
    hkVector4_Havok m_kColumn0;
    hkVector4_Havok m_kColumn1;
    hkVector4_Havok m_kColumn2;
};

struct hkTransform_Havok
{
    hkRotation_Havok m_rotation;
    hkVector4_Havok m_vTranslation;
};

struct HingeClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkTransform_Havok m_kBodyALocalFrame;
    hkTransform_Havok m_kBodyBLocalFrame;

    void __thiscall FUN_00cb8da0(const hkVector4_Havok& pivotA, const hkVector4_Havok& pivotB,
                                 const hkVector4_Havok& axisA, const hkVector4_Havok& axisB,
                                 const hkVector4_Havok& axisAPerp, const hkVector4_Havok& axisBPerp);
};

// Sets the rotation and translation of m_kBodyALocalFrame and m_kBodyBLocalFrame from the given pivot and axis vectors.
// @fnv 0x00cb8da0
void __thiscall HingeClass::FUN_00cb8da0(const hkVector4_Havok& pivotA, const hkVector4_Havok& pivotB,
                                         const hkVector4_Havok& axisA, const hkVector4_Havok& axisB,
                                         const hkVector4_Havok& axisAPerp, const hkVector4_Havok& axisBPerp)
{
    m_kBodyALocalFrame.m_rotation.m_kColumn0 = axisA;
    m_kBodyALocalFrame.m_rotation.m_kColumn0.normalize3();
    m_kBodyALocalFrame.m_rotation.m_kColumn1 = axisAPerp;
    m_kBodyALocalFrame.m_rotation.m_kColumn1.normalize3();
    m_kBodyALocalFrame.m_rotation.m_kColumn2.setCross(m_kBodyALocalFrame.m_rotation.m_kColumn0,
                                                      m_kBodyALocalFrame.m_rotation.m_kColumn1);
    m_kBodyALocalFrame.m_vTranslation = pivotA;
    _ReadWriteBarrier();

    m_kBodyBLocalFrame.m_rotation.m_kColumn0 = axisB;
    m_kBodyBLocalFrame.m_rotation.m_kColumn0.normalize3();
    m_kBodyBLocalFrame.m_rotation.m_kColumn1 = axisBPerp;
    m_kBodyBLocalFrame.m_rotation.m_kColumn1.normalize3();
    hkSetCross(m_kBodyBLocalFrame.m_rotation.m_kColumn2, m_kBodyBLocalFrame.m_rotation.m_kColumn0,
               m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    m_kBodyBLocalFrame.m_vTranslation = pivotB;
}

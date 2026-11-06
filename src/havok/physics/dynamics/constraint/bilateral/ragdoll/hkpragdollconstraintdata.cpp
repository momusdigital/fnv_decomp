
// src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRagdollConstraintData.h"

// @fnv 0x00cde9d0
void __stdcall getRuntimeInfo(int* apUnused, int* apiOut)
{
    apiOut[1] = 0xc;
    apiOut[0] = 0x80;
}

struct FUN_00cde980_cls
{
    void __thiscall FUN_00cde980(int a);
};
// @fnv 0x00cde980
void __thiscall FUN_00cde980_cls::FUN_00cde980(int aiBitIndex)
{
    *(char*)((char*)this + 0x13a) = (char)(1 << aiBitIndex);
}

struct FUN_00cde960_cls
{
    void __thiscall setMaxLinearImpulse(float a);
};
// @fnv 0x00cde960
void __thiscall FUN_00cde960_cls::setMaxLinearImpulse(float a)
{
    *(float*)((char*)this + 0x13c) = a;
}

void* __cdecl FUN_00d21a60(void* a, int b, int c);
struct FUN_00cde9b0_cls
{
    char* getConstraintInfo(int a);
};
// @fnv 0x00cde9b0
char* FUN_00cde9b0_cls::getConstraintInfo(int aiIndex)
{
    return (char*)FUN_00d21a60((char*)this + 0x10, 0x130, aiIndex);
}

extern int DAT_010cb71c;
extern int _DAT_0102e388;

struct DDCC60World
{
    void __thiscall removeReference(void);
};

struct FUN_00cdf1f0
{
    void* m_ppVirtualMethodTable;          // +0x00
    char pad[0xdc];          // +0x04 .. +0xdf
    DDCC60World* m_refs[3];  // +0xe0
    ~FUN_00cdf1f0();
};

// @fnv 0x00cdf1f0
FUN_00cdf1f0::~FUN_00cdf1f0()
{
    m_ppVirtualMethodTable = &DAT_010cb71c;
    for (int i = 0; i < 3; ++i)
    {
        DDCC60World* p = m_refs[i];
        if (p)
            p->removeReference();
    }
    m_ppVirtualMethodTable = &_DAT_0102e388;
}

struct FUN_00cde970_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
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
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    float m_13c;
    float getMaxLinearImpulse();
};

// @fnv 0x00cde970
float FUN_00cde970_cls::getMaxLinearImpulse()
{
    return m_13c;
}

// FUN_00cde9a0
//   movzx eax, byte ptr [ecx + 0x13a]
//   shr   eax, 1
//   ret
//
// The unit file does not declare this function, so it is modelled here from the
// disassembly.  The object is an hkpRagdollConstraintData (m_kBridgeAtoms at +0x10);
// inside m_kBridgeAtoms the hkpBallSocketConstraintAtom sits at +0x128, so its
// hkUint8 m_ucBodiesToNotify member is at +0x13a of the complete object.
// The getter returns that byte shifted right by one bit.
struct RagdollBodiesToNotify : public hkpRagdollConstraintData
{
    int __thiscall FUN_00cde9a0();
};

// @fnv 0x00cde9a0
int RagdollBodiesToNotify::FUN_00cde9a0()
{
    return m_kBridgeAtoms.m_kBallSocket.m_ucBodiesToNotify >> 1;
}

// @fnv 0x00cdead0
int __cdecl FUN_00cdead0()
{
    return 7;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
struct __declspec(align(16)) FUN_00cdf190_Vec
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00cdf190_Out
{
    FUN_00cdf190_Vec a;
    FUN_00cdf190_Vec b;
    FUN_00cdf190_Vec c;
};
struct FUN_00cdf190_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00cdf190_Vec v20;
    FUN_00cdf190_Vec v30;
    FUN_00cdf190_Vec v40;
    void CopyVectorsToOut(FUN_00cdf190_Out* out);
};
// Copies the three 16-byte vectors v20, v30 and v40 into the output's a, b and c fields.
// @fnv 0x00cdf190
void FUN_00cdf190_Class::CopyVectorsToOut(FUN_00cdf190_Out* out)
{
    *(__m128*)&out->a = *(const __m128*)&v20;
    *(__m128*)&out->b = *(const __m128*)&v30;
    *(__m128*)&out->c = *(const __m128*)&v40;
}

struct FnvCpu_FUN_00cdf530_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cdf530_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cdf530_CpuAllocator* allocator;
};
FnvCpu_FUN_00cdf530_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00cdf530_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cdf1f0();
    FnvCpu_FUN_00cdf530_CpuObject* FUN_00cdf530(unsigned int flags);
};
// @fnv 0x00cdf530
FnvCpu_FUN_00cdf530_CpuObject* FnvCpu_FUN_00cdf530_CpuObject::FUN_00cdf530(unsigned int flags)
{
    FUN_00cdf1f0();
    if (flags & 1)
    {
        FnvCpu_FUN_00cdf530_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

struct Cdf1c0_vec48
{
    __m128 a;
    __m128 b;
    __m128 c;
};

class Cdf1c0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    Cdf1c0_vec48 m60;
    Cdf1c0_vec48 m70;
    Cdf1c0_vec48 m80;
    void GetM60(Cdf1c0_vec48* out);
};

// Copies the m60 vector from the Cdf1c0_cls instance into the out parameter.
// @fnv 0x00cdf1c0
void Cdf1c0_cls::GetM60(Cdf1c0_vec48* out)
{
    out->a = m60.a;
    out->b = m60.b;
    out->c = m60.c;
}

extern "C" __m128 _mm_setzero_ps(void);

struct hkVector4B90
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

struct hkRotationB90
{
    hkVector4B90 m_kColumn0, m_kColumn1, m_kColumn2;

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

struct hkTransformB90
{
    hkRotationB90 m_rotation;
    hkVector4B90 m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct hkBoolB90
{
    char m_cBooleanValue;
    __forceinline hkBoolB90& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct hkpConstraintAtomB90
{
    unsigned short m_type;
};

struct hkpSetLocalTransformsConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned short unk02;
    int unk04, unk08, unk0C;
    hkTransformB90 m_kBodyALocalFrame;
    hkTransformB90 m_kBodyBLocalFrame;
};

struct hkpAngMotorConstraintAtomB90 : public hkpConstraintAtomB90
{
    hkBoolB90 m_bLimitEnabled;
    unsigned char m_ucMotorAxis;
    short m_iInitializedOffset;
    short m_iPreviousTargetAngleOffset;
    short m_iCorrespondingAngLimitSolverResultOffset;
    float m_fTargetAngle;
    void* m_pMotor;
};

struct hkpAngFrictionConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_bLimitEnabled;
    unsigned char m_ucFirstFrictionAxis;
    unsigned char m_ucNumFrictionAxes;
    float m_fMaxFrictionTorque;
};

struct hkpAngLimitConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_bLimitEnabled;
    unsigned char m_ucLimitAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};

struct hkp2dAngConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_ucFreeRotationAxis;
};

struct hkpBallSocketConstraintAtomB90 : public hkpConstraintAtomB90
{
    unsigned char m_ucBodiesToNotify;
    unsigned char unk03;
    float m_usFlags;
};

class __declspec(align(16)) FUN_00cb9170
{
  public:
    FUN_00cb9170() throw();

    hkpSetLocalTransformsConstraintAtomB90 m_kTransforms;
    hkpAngMotorConstraintAtomB90 m_kAngularMotor;
    hkpAngFrictionConstraintAtomB90 m_kFriction;
    hkpAngLimitConstraintAtomB90 m_kAngularLimit;
    hkp2dAngConstraintAtomB90 m_kTwoDimensionalAngular;
    hkpBallSocketConstraintAtomB90 m_kBallSocket;
};

class hkReferencedObjectB90
{
  public:
    hkReferencedObjectB90() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectB90() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataB90 : public hkReferencedObjectB90
{
  public:
    hkpConstraintDataB90() throw()
    {
        m_ulUserData = 0;
    }
    virtual ~hkpConstraintDataB90() throw()
    {}

    unsigned long m_ulUserData;
};

class FUN_00cb9090 : public hkpConstraintDataB90
{
  public:
    FUN_00cb9090() throw();
    virtual ~FUN_00cb9090() throw();

    int unk0C;
    FUN_00cb9170 m_kBridgeAtoms;
};

// Initializes m_kBridgeAtoms with identity transforms, default angular limits, friction, motor, and 2D angular constraint values.
// @fnv 0x00cb9090
FUN_00cb9090::FUN_00cb9090() throw()
{
    m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.setIdentity();
    m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.setIdentity();

    m_kBridgeAtoms.m_kTwoDimensionalAngular.m_ucFreeRotationAxis = 0;

    m_kBridgeAtoms.m_kAngularLimit.m_ucLimitAxis = 0;
    m_kBridgeAtoms.m_kAngularLimit.m_fMinAngle = -3.14159274f;
    m_kBridgeAtoms.m_kAngularLimit.m_fMaxAngle = 3.14159274f;
    m_kBridgeAtoms.m_kAngularLimit.m_fAngularLimitsTauFactor = 1.0f;

    m_kBridgeAtoms.m_kFriction.m_ucFirstFrictionAxis = 0;
    m_kBridgeAtoms.m_kFriction.m_ucNumFrictionAxes = 1;
    m_kBridgeAtoms.m_kFriction.m_fMaxFrictionTorque = 0.0f;

    m_kBridgeAtoms.m_kAngularMotor.m_iInitializedOffset = 0x40;
    m_kBridgeAtoms.m_kAngularMotor.m_iPreviousTargetAngleOffset = 0x44;
    m_kBridgeAtoms.m_kAngularMotor.m_iCorrespondingAngLimitSolverResultOffset = 0x10;
    m_kBridgeAtoms.m_kAngularMotor.m_bLimitEnabled = false;
    m_kBridgeAtoms.m_kAngularMotor.m_fTargetAngle = 0.0f;
    m_kBridgeAtoms.m_kAngularMotor.m_pMotor = 0;
    m_kBridgeAtoms.m_kAngularMotor.m_ucMotorAxis = 0;
}

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

struct hkVector4Out : public hkVector4
{
    void SetTransformedPosition(const hkTransform& t, const hkVector4& v);
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

    __forceinline void operator=(const hkMatrix3q& m)
    {
        m_col[0].m_vComponents = m.m_col[0].m_vComponents;
        m_col[1].m_vComponents = m.m_col[1].m_vComponents;
        m_col[2].m_vComponents = m.m_col[2].m_vComponents;
    }
};

struct hkRagdollTransformsq
{
    hkUint16 m_type;
    hkUint16 unk02;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3q m_kRotationA;
    hkVector4 m_kTranslationA;
    hkMatrix3q m_kRotationB;
    hkVector4 m_kTranslationB;
    hkUint16 m_motorType;
    hkUint16 unk82;
    int unk84;
    int unk88;
    int unk8C;
    hkMatrix3q m_kMotorAxes;
};

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

struct hkpRagdollConstraintDataEx : public hkpRagdollConstraintData
{
    void FUN_00cdeae0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& twistAxisW, const hkVector4& planeAxisW);
};

// Builds a constraint basis from twist and plane axes, then stores rotated and translated transforms into the ragdoll bridge atom data.
// @fnv 0x00cdeae0
void hkpRagdollConstraintDataEx::FUN_00cdeae0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                              const hkVector4& pivot, const hkVector4& twistAxisW,
                                              const hkVector4& planeAxisW)
{
    hkMatrix3q baseConstraint;
    baseConstraint.m_col[0].m_vComponents = reinterpret_cast<const hkVector4q&>(twistAxisW).m_vComponents;
    hkNormalize3(baseConstraint.m_col[0]);
    baseConstraint.m_col[1].m_vComponents = reinterpret_cast<const hkVector4q&>(planeAxisW).m_vComponents;
    hkNormalize3(baseConstraint.m_col[1]);
    hkSetCross(baseConstraint.m_col[2], baseConstraint.m_col[0], baseConstraint.m_col[1]);

    hkRagdollTransformsq& t = *reinterpret_cast<hkRagdollTransformsq*>(&m_kBridgeAtoms);

    hkSetTransposeMul(t.m_kRotationA, reinterpret_cast<const hkMatrix3q&>(bodyATransform.m_rotation), baseConstraint);
    hkSetTransposeMul(t.m_kRotationB, reinterpret_cast<const hkMatrix3q&>(bodyBTransform.m_rotation), baseConstraint);

    static_cast<hkVector4Out&>(t.m_kTranslationA).SetTransformedPosition(bodyATransform, pivot);
    static_cast<hkVector4Out&>(t.m_kTranslationB).SetTransformedPosition(bodyBTransform, pivot);

    t.m_kMotorAxes = t.m_kRotationB;
}

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);

extern const __m128 DAT_010c71e0;

struct Quat
{
    __m128 m_vec;
    void FUN_00cb2450(const __m128* axis, float angle);
};

struct Vec4
{
    __m128 m_vComponents;
    __forceinline void setCross(const Vec4& a, const Vec4& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline void setBroadcast3(const Vec4& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setMul4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const Vec4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void addMul4(__m128 s, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void addMul4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline __m128 dot3(const Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    __forceinline void SetRotatedDirection(const Quat& quat, const Vec4& direction)
    {
        const Vec4& imag = *(const Vec4*)&quat.m_vec;
        Vec4 qreal;
        qreal.setBroadcast3(imag);
        Vec4 q2minus1;
        q2minus1.setMul4(qreal, qreal);
        q2minus1.add4(*(const Vec4*)&DAT_010c71e0);
        Vec4 ret;
        ret.setMul4(direction, q2minus1);
        __m128 imagDotDir = imag.dot3(direction);
        ret.addMul4(imagDotDir, imag);
        Vec4 imagCrossDir;
        imagCrossDir.setCross(imag, direction);
        ret.addMul4(imagCrossDir, qreal);
        setAdd4(ret, ret);
    }
};

struct FUN_00cdef90_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    Vec4 m_dir;
    Vec4 m_kAxisEndPoints;
    Vec4 m_kStartPerpendicular;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    float m_halfRange;
    void FUN_00cdef90(float a, float b);
};

// Rotates m_dir about m_kAxisEndPoints by minus the midpoint of a and b, sets m_kStartPerpendicular to their cross, and stores (b - a) / 2 in m_halfRange.
// @fnv 0x00cdef90
void FUN_00cdef90_cls::FUN_00cdef90(float afStart, float afEnd)
{
    float center = (afStart + afEnd) * 0.5;
    Quat q;
    q.FUN_00cb2450(&m_kAxisEndPoints.m_vComponents, -center);
    m_dir.SetRotatedDirection(q, m_dir);
    Vec4* perp = &m_kStartPerpendicular;
    perp->setCross(m_dir, m_kAxisEndPoints);
    m_halfRange = (afEnd - afStart) * 0.5;
}

namespace fnv_00cb9170 {
struct FUN_00ca9360_sub
{
    void FUN_00ca9360(float*);
};

struct FUN_00cb9170
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    unsigned short m_10;
    unsigned short m_12;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
    unsigned short m_1a;
    unsigned short m_1c;
    unsigned short m_1e;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short m_26;
    unsigned short m_28;
    unsigned short m_2a;
    unsigned short m_2c;
    unsigned short m_2e;
    unsigned short m_30;
    unsigned short m_32;
    unsigned short m_34;
    unsigned short m_36;
    unsigned short m_38;
    unsigned short m_3a;
    unsigned short m_3c;
    unsigned short m_3e;
    unsigned short m_40;
    unsigned short m_42;
    unsigned short m_44;
    unsigned short m_46;
    unsigned short m_48;
    unsigned short m_4a;
    unsigned short m_4c;
    unsigned short m_4e;
    unsigned short m_50;
    unsigned short m_52;
    unsigned short m_54;
    unsigned short m_56;
    unsigned short m_58;
    unsigned short m_5a;
    unsigned short m_5c;
    unsigned short m_5e;
    unsigned short m_60;
    unsigned short m_62;
    unsigned short m_64;
    unsigned short m_66;
    unsigned short m_68;
    unsigned short m_6a;
    unsigned short m_6c;
    unsigned short m_6e;
    unsigned short m_70;
    unsigned short m_72;
    unsigned short m_74;
    unsigned short m_76;
    unsigned short m_78;
    unsigned short m_7a;
    unsigned short m_7c;
    unsigned short m_7e;
    unsigned short m_80;
    unsigned short m_82;
    unsigned short m_84;
    unsigned short m_86;
    unsigned short m_88;
    unsigned short m_8a;
    unsigned short m_8c;
    unsigned short m_8e;
    volatile unsigned short m_90;
    volatile unsigned char m_92;
    unsigned char m_93;
    volatile unsigned short m_94;
    volatile unsigned short m_96;
    unsigned char m_98;
    unsigned char m_99;
    unsigned char m_9a;
    unsigned char m_9b;
    unsigned char m_9c;
    unsigned char m_9d;
    unsigned char m_9e;
    unsigned char m_9f;
    unsigned char m_a0;
    unsigned char m_a1;
    unsigned char m_a2;
    unsigned char m_a3;
    volatile unsigned short m_a4;
    volatile unsigned char m_a6;
    unsigned char m_a7;
    volatile unsigned char m_a8;
    unsigned char m_a9;
    unsigned char m_aa;
    unsigned char m_ab;
    unsigned char m_ac;
    unsigned char m_ad;
    unsigned char m_ae;
    unsigned char m_af;
    volatile unsigned short m_b0;
    volatile unsigned char m_b2;
    unsigned char m_b3;
    unsigned char m_b4;
    unsigned char m_b5;
    unsigned char m_b6;
    unsigned char m_b7;
    unsigned char m_b8;
    unsigned char m_b9;
    unsigned char m_ba;
    unsigned char m_bb;
    unsigned char m_bc;
    unsigned char m_bd;
    unsigned char m_be;
    unsigned char m_bf;
    volatile unsigned short m_c0;
    unsigned char m_c2;
    unsigned char m_c3;
    volatile unsigned short m_c4;
    unsigned char m_c6;
    FUN_00ca9360_sub m_c7;
    float m_fC8;
    FUN_00cb9170();
};
extern "C" float DAT_0104da48;
// Initializes the FUN_00cb9170 object by setting default values for its fields and calling FUN_00ca9360 with a float pointer.
// @fnv 0x00cb9170
FUN_00cb9170::FUN_00cb9170()
{
    float f = 1.0f;
    m_00 = 2;
    m_90 = 0x12;
    m_92 = 1;
    m_94 = 0;
    m_96 = 0;
    m_a6 = 1;
    m_a8 = 1;
    m_a4 = 0x11;
    m_b0 = 0xe;
    m_b2 = 1;
    volatile unsigned short* limit = &m_c0;
    *limit = 0xc;
    m_c4 = 5;
    m_c6 = 0;
    m_c7.FUN_00ca9360(&f);
    m_fC8 = DAT_0104da48;
}
}  // namespace fnv_00cb9170

struct RagdollRotation3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

struct RagdollTransformq
{
    RagdollRotation3q m_rotation;
    hkVector4q m_vTranslation;
};

struct RagdollLayout
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RagdollTransformq m_kBodyALocalFrame;
    RagdollTransformq m_kBodyBLocalFrame;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    RagdollRotation3q m_kMotorAxes;
};

// out = a x b, with the operands passed as (b, a)
static __forceinline void hkSetCrossReversed(hkVector4q& out, const hkVector4q& b, const hkVector4q& a)
{
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9),
                               _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2));
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2),
                               _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}
struct hkpRagdollConstraintDataBodySpace : public hkpRagdollConstraintData
{
    void FUN_00cded30(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& planeAxisA,
                      const hkVector4& planeAxisB, const hkVector4& twistAxisA, const hkVector4& twistAxisB);
};

// Stores normalized twist and plane axes, their cross product and the pivot for each body, then copies body B's rotation into the motor axes.
// @fnv 0x00cded30
void hkpRagdollConstraintDataBodySpace::FUN_00cded30(const hkVector4& pivotA, const hkVector4& pivotB,
                                                     const hkVector4& planeAxisA, const hkVector4& planeAxisB,
                                                     const hkVector4& twistAxisA, const hkVector4& twistAxisB)
{
    RagdollLayout& layout = *reinterpret_cast<RagdollLayout*>(this);

    hkVector4q& twistA = layout.m_kBodyALocalFrame.m_rotation.m_kColumn0;
    twistA.m_vComponents = reinterpret_cast<const hkVector4q&>(twistAxisA).m_vComponents;
    hkNormalize3(twistA);
    layout.m_kBodyALocalFrame.m_rotation.m_kColumn1.m_vComponents =
        reinterpret_cast<const hkVector4q&>(planeAxisA).m_vComponents;
    hkNormalize3(layout.m_kBodyALocalFrame.m_rotation.m_kColumn1);
    hkSetCross(layout.m_kBodyALocalFrame.m_rotation.m_kColumn2, layout.m_kBodyALocalFrame.m_rotation.m_kColumn0,
               layout.m_kBodyALocalFrame.m_rotation.m_kColumn1);
    layout.m_kBodyALocalFrame.m_vTranslation.m_vComponents = reinterpret_cast<const hkVector4q&>(pivotA).m_vComponents;

    hkVector4q& twistB = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0;
    twistB.m_vComponents = reinterpret_cast<const hkVector4q&>(twistAxisB).m_vComponents;
    hkNormalize3(twistB);
    layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1.m_vComponents =
        reinterpret_cast<const hkVector4q&>(planeAxisB).m_vComponents;
    hkNormalize3(layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCrossReversed(layout.m_kBodyBLocalFrame.m_rotation.m_kColumn2, layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1,
                       layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0);
    layout.m_kBodyBLocalFrame.m_vTranslation.m_vComponents = reinterpret_cast<const hkVector4q&>(pivotB).m_vComponents;

    layout.m_kMotorAxes.m_kColumn0.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0.m_vComponents;
    layout.m_kMotorAxes.m_kColumn1.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1.m_vComponents;
    layout.m_kMotorAxes.m_kColumn2.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn2.m_vComponents;
}

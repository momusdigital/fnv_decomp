
// src/havok/physics/dynamics/motion/hkpmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/hkpmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMotion.h"

extern "C" void __cdecl SetMotionState(void*, void*);

struct FUN_00c86400_Class
{
    void __thiscall FUN_00c86400(void* a);
};

// @fnv 0x00c86400
void __thiscall FUN_00c86400_Class::FUN_00c86400(void* a)
{
    SetMotionState(a, (char*)this + 0x10);
}

struct FUN_00c86420_Class
{
    void __thiscall FUN_00c86420(char a);
};
// @fnv 0x00c86420
void __thiscall FUN_00c86420_Class::FUN_00c86420(char a)
{
    ((char*)this)[0xbe] = a;
}

struct FUN_00c86480_Class
{
    void __thiscall setMassInv(float v);
};
// @fnv 0x00c86480
void __thiscall FUN_00c86480_Class::setMassInv(float v)
{
    *(float*)((char*)this + 0xcc) = v;
}

struct FUN_00c86330_Class
{
    void __thiscall setMass(float mass);
};

// Computes the inverse of mass (0 if mass is 0) and passes it to the virtual function at vtable slot 4.
// @fnv 0x00c86330
void __thiscall FUN_00c86330_Class::setMass(float mass)
{
    float invMass;
    if (mass == 0.0f)
    {
        invMass = 0.0f;
    }
    else
    {
        invMass = 1.0f / mass;
    }
    void** vtbl = *(void***)this;
    void(__thiscall * fn)(void*, float) = (void(__thiscall*)(void*, float))vtbl[4];
    fn(this, invMass);
}

extern "C" void __cdecl FUN_00cf20d0(void*, void*);
struct FUN_00c863a0_Class
{
    void __thiscall FUN_00c863a0(void* a);
};
// @fnv 0x00c863a0
void __thiscall FUN_00c863a0_Class::FUN_00c863a0(void* a)
{
    FUN_00cf20d0(a, (char*)this + 0x10);
}

extern "C" void __cdecl FUN_00cf2160(void*, void*);

struct FUN_00c863c0_Class
{
    void __thiscall FUN_00c863c0(void* a);
};

// @fnv 0x00c863c0
void __thiscall FUN_00c863c0_Class::FUN_00c863c0(void* a)
{
    FUN_00cf2160(a, (char*)this + 0x10);
}

extern void __cdecl FUN_00cf1f80(void*, void*, void*);

struct FUN_00c863e0_Class
{
    void __thiscall FUN_00c863e0(void* param1, void* param2);
};

// @fnv 0x00c863e0
void FUN_00c863e0_Class::FUN_00c863e0(void* pFirst, void* pSecond)
{
    FUN_00cf1f80(pFirst, pSecond, static_cast<void*>(reinterpret_cast<char*>(this) + 0x10));
}

struct FUN_00cf22d0_Class
{
    void __thiscall Evaluate(float value, void* result);
};

struct FUN_00c86490_Class
{
    char pad[0x50];
    FUN_00cf22d0_Class sweptTransform;

    void __thiscall SweepTransform(float value, void* result);
};

// @fnv 0x00c86490
void FUN_00c86490_Class::SweepTransform(float value, void* result)
{
    sweptTransform.Evaluate(value, result);
}

int __cdecl ApplyDelta(int, int);
// @fnv 0x00c86380
int __fastcall FUN_00c86380(unsigned int registerArg0, unsigned int registerArg1, unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)ApplyDelta((int)arg0, (int)(registerArg0 + 16u));
    return (int)callResult0;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkVector4C864F
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4C864F& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4C864F& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4C864F& a, const hkVector4C864F& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

class hkBaseObjectC864F
{
  public:
    virtual ~hkBaseObjectC864F() throw();
};

class hkReferencedObjectC864F : public hkBaseObjectC864F
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpMotionC864F : public hkReferencedObjectC864F
{
  public:
    void ApplyImpulse(const hkVector4C864F& kImpulse);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4C864F m_motionState0[5];
    hkVector4C864F m_kCenterOfMass1;
    hkVector4C864F m_motionState1[5];
    hkVector4C864F m_kInertiaAndMassInv;
    hkVector4C864F m_kTranslationalVelocity;
    hkVector4C864F m_kAngularVelocity;
};

// Adds kImpulse scaled by the w component of m_kInertiaAndMassInv to m_kTranslationalVelocity.
// @fnv 0x00c864f0
void hkpMotionC864F::ApplyImpulse(const hkVector4C864F& kImpulse)
{
    hkVector4C864F kDeltaLin;
    kDeltaLin.setMul4(m_kInertiaAndMassInv.getSimdAt3(), kImpulse);
    m_kTranslationalVelocity.add4(kDeltaLin);
}

namespace fnv_00c86530 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4C865
{
    __m128 m_vComponents;

    hkVector4C865()
    {}
    hkVector4C865(const hkVector4C865& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4C865& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkQuaternionC865
{
    hkVector4C865 m_vec;
};

class hkHalfC865
{
  public:
    hkHalfC865& operator=(const float& f)
    {
        int t = reinterpret_cast<const int*>(&f)[0];
        m_uiFilterValue = static_cast<short>(t >> 16);
        return *this;
    }

    short m_uiFilterValue;
};

struct hkMotionStateC865
{
    void FUN_00cf2410(const hkVector4C865& kPosition, const hkQuaternionC865& kRotationBasis);

    hkVector4C865 m_kMotionTransform[4];
    hkVector4C865 m_kSweptTransform[5];
    hkVector4C865 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    unsigned char m_fSurfaceFriction;
    unsigned char m_fRestitution;
    unsigned char m_uiDeactivationClass;
    unsigned char unkAF;
};

class hkBaseObjectC865
{
  public:
    virtual ~hkBaseObjectC865() throw();
};

class hkReferencedObjectC865 : public hkBaseObjectC865
{
  public:
    hkReferencedObjectC865() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC865() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00c86530 : public hkReferencedObjectC865
{
  public:
    FUN_00c86530(const hkVector4C865& kPosition, const hkQuaternionC865& kRotationBasis,
                 bool bWantDeactivation) throw();
    virtual ~FUN_00c86530() throw();

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkMotionStateC865 m_kMotionState;
    hkVector4C865 m_kInertiaAndMassInv;
    hkVector4C865 m_kTranslationalVelocity;
    hkVector4C865 m_kAngularVelocity;
    hkVector4C865 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    void* m_pSavedMotion;
    unsigned short m_savedMotionSize;
    hkHalfC865 m_fGravityFactor;
};

// Constructor: zeroes velocities, damping and deactivation data, sets up m_kMotionState from position and rotation, and sets the gravity factor to 1.0.
// @fnv 0x00c86530
FUN_00c86530::FUN_00c86530(const hkVector4C865& kPosition, const hkQuaternionC865& kRotationBasis,
                           bool bWantDeactivation) throw()
{
    hkVector4C865 kZero;
    kZero.setZero4();
    m_kTranslationalVelocity = kZero;
    m_kAngularVelocity = kZero;
    m_kMotionState.FUN_00cf2410(kPosition, kRotationBasis);
    m_kMotionState.m_fAngularDamping = m_kMotionState.m_fLinearDamping = 0.0f;
    m_type = 0;
    if (bWantDeactivation)
    {
        m_ucDeactivationIntegrateCounter = static_cast<unsigned char>(0xf & static_cast<int>(kPosition(0)));
    }
    else
    {
        m_ucDeactivationIntegrateCounter = 0xff;
    }
    m_ausDeactivationNumInactiveFrames[0] = 0;
    m_ausDeactivationNumInactiveFrames[1] = 0;
    m_akDeactivationReferencePositions[0] = kZero;
    m_akDeactivationReferencePositions[1] = kZero;
    m_auiDeactivationReferenceOrientations[0] = 0;
    m_auiDeactivationReferenceOrientations[1] = 0;
    m_fGravityFactor = 1.0f;
}
}  // namespace fnv_00c86530

namespace fnv_00c86610 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
struct Motion_00c86660
{
    void __thiscall FUN_00c86660(void* a);
};
struct Motion_00c86610
{
    Motion_00c86610();
    void __thiscall getMotionStateAndVelocitiesAndDeactivationType(Motion_00c86610* dst);
};
// Copies the embedded Motion_00c86660 member and the two __m128 blocks plus one byte from this to dst.
// @fnv 0x00c86610
void __thiscall Motion_00c86610::getMotionStateAndVelocitiesAndDeactivationType(Motion_00c86610* apDest)
{
    ((Motion_00c86660*)((char*)apDest + 0x10))->FUN_00c86660((char*)this + 0x10);
    *(__m128*)((char*)apDest + 0xd0) = *(__m128*)((char*)this + 0xd0);
    *(__m128*)((char*)apDest + 0xe0) = *(__m128*)((char*)this + 0xe0);
    ((unsigned char*)apDest + 9)[0] = ((unsigned char*)this + 9)[0];
}
}  // namespace fnv_00c86610

struct FUN_00c864b0_Class
{
    void __thiscall FUN_00c864b0(const float* a);
};
// @fnv 0x00c864b0
void __thiscall FUN_00c864b0_Class::FUN_00c864b0(const float* apVector)
{
    __m128 v = *(const __m128*)apVector;
    *((__m128*)(this + 0xd0)) = v;
}

struct FUN_00c864d0_Class
{
    char m_e0[0xe0];
    __m128 m_f0e0;
    void __thiscall CopyFrom(__m128* v);
};
// @fnv 0x00c864d0
void __thiscall FUN_00c864d0_Class::CopyFrom(__m128* apSource)
{
    m_f0e0 = *apSource;
}

extern "C" void _mm_store_ss(float*, __m128);

struct MotionMassView : hkpMotionC864F
{
    float FUN_00c86430();
};

// Reads the inverse-mass component from m_kInertiaAndMassInv, returns 0.0f if it is zero, otherwise returns its reciprocal as the mass.
// @fnv 0x00c86430
float MotionMassView::FUN_00c86430()
{
    __m128 v = m_kInertiaAndMassInv.m_vComponents;
    float invMass;
    _mm_store_ss(&invMass, _mm_shuffle_ps(v, v, 0xFF));
    if (invMass == 0.0f)
        return 0.0f;
    float mass = 1.0f / invMass;
    return mass;
}

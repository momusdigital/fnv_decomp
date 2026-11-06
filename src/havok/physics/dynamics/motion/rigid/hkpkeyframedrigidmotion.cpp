
// src/havok/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpKeyframedRigidMotion.h"

struct FUN_00d1df70
{
    void RetainReference();
    void removeReference();
    void SetAndAddReference(hkReferencedObject* obj);
};
// @fnv 0x00d1df70
void FUN_00d1df70::SetAndAddReference(hkReferencedObject* apObject)
{
    if (apObject)
        ((FUN_00d1df70*)apObject)->RetainReference();
    if (*(hkReferencedObject**)((char*)this + 0x118))
        ((FUN_00d1df70*)*(hkReferencedObject**)((char*)this + 0x118))->removeReference();
    *(hkReferencedObject**)((char*)this + 0x118) = apObject;
}

struct DDCC60World
{
    void removeReference();
};
extern int DAT_010c6bec;
extern int _DAT_0102e388;
struct FUN_00d1dff0
{
    void setMotion();
};
// Sets the vtable to DAT_010c6bec, releases the reference at offset 0x118 if present, then sets the vtable to _DAT_0102e388.
// @fnv 0x00d1dff0
void FUN_00d1dff0::setMotion()
{
    *reinterpret_cast<void**>(this) = (void*)&DAT_010c6bec;
    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x118))
        reinterpret_cast<DDCC60World*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x118))
            ->removeReference();
    *reinterpret_cast<void**>(this) = (void*)&_DAT_0102e388;
}

// @fnv 0x00d1dec0
void __stdcall setMass(int)
{}

// @fnv 0x00d1ded0
void __stdcall setMassInv(int)
{}

// @fnv 0x00d1dee0
void __stdcall FUN_00d1dee0(int)
{}

// @fnv 0x00d1def0
void __stdcall FUN_00d1def0(int)
{}

// @fnv 0x00d1df00
void __stdcall FUN_00d1df00(int)
{}

// @fnv 0x00d1df10
void __stdcall applyPointImpulse(int, int)
{}

// @fnv 0x00d1df20
void __stdcall applyAngularImpulse(int)
{}

// @fnv 0x00d1df30
void __stdcall FUN_00d1df30(int, int)
{}

// @fnv 0x00d1df40
void __stdcall FUN_00d1df40(int a, int b, int c)
{}

// @fnv 0x00d1df50
void __stdcall FUN_00d1df50(int, int)
{}

// @fnv 0x00d1df60
void __stdcall FUN_00d1df60(int, int)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D1DF
{
    __m128 m_vComponents;

    hkVector4D1DF()
    {}
    hkVector4D1DF(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkQuaternionD1DF
{
    hkVector4D1DF m_vec;
};

class hkBaseObjectD1DF
{
  public:
    virtual ~hkBaseObjectD1DF() throw();
};

class hkReferencedObjectD1DF : public hkBaseObjectD1DF
{
  public:
    virtual ~hkReferencedObjectD1DF() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00c86530 : public hkReferencedObjectD1DF
{
  public:
    FUN_00c86530(const hkVector4D1DF& kPosition, const hkQuaternionD1DF& kRotationBasis,
                 bool bWantDeactivation) throw();
    virtual ~FUN_00c86530() throw();

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    unsigned int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    unsigned int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    hkVector4D1DF m_kInertiaAndMassInv;
    hkVector4D1DF m_kTranslationalVelocity;
    hkVector4D1DF m_kAngularVelocity;
    hkVector4D1DF m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    void* m_pSavedMotion;
    unsigned short m_savedMotionSize;
    short m_fGravityFactor;
};

class FUN_00d1dfa0 : public FUN_00c86530
{
  public:
    FUN_00d1dfa0(const hkVector4D1DF& kPosition, const hkQuaternionD1DF& kRotationBasis) throw();
    virtual ~FUN_00d1dfa0() throw();
};

// Calls base FUN_00c86530(kPosition, kRotationBasis, false), zeroes the saved-motion fields and m_kInertiaAndMassInv, and sets m_type to 4.
// @fnv 0x00d1dfa0
FUN_00d1dfa0::FUN_00d1dfa0(const hkVector4D1DF& kPosition, const hkQuaternionD1DF& kRotationBasis) throw()
    : FUN_00c86530(kPosition, kRotationBasis, false)
{
    m_pSavedMotion = 0;
    m_savedMotionSize = 0;
    m_kInertiaAndMassInv.setZero4();
    m_type = 4;
}

struct FUN_00d1e030_t
{
    float f0, f1, f2, f3;
    float f4, f5, f6, f7;
    float f8, f9, fA, fB;
    float fC, fD, fE, fF;
};
// @fnv 0x00d1e030
void __stdcall FUN_00d1e030(FUN_00d1e030_t* p)
{
    __m128 z = _mm_setzero_ps();
    *(__m128*)&p->f0 = z;
    *(__m128*)&p->f4 = z;
    *(__m128*)&p->f8 = z;
}

// @fnv 0x00d1e050
void __stdcall ZeroFloatArray(float* apFloats)
{
    __m128 z = _mm_setzero_ps();
    *reinterpret_cast<__m128*>(apFloats) = z;
    *reinterpret_cast<__m128*>(apFloats + 4) = z;
    *reinterpret_cast<__m128*>(apFloats + 8) = z;
}

// @fnv 0x00d1e070
void __stdcall ZeroFloats(float* apFloats)
{
    __m128 z = _mm_setzero_ps();
    *(reinterpret_cast<__m128*>(apFloats)) = z;
    *(reinterpret_cast<__m128*>(apFloats) + 1) = z;
    *(reinterpret_cast<__m128*>(apFloats) + 2) = z;
}

namespace fnv_00d1e090 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
}

struct Veh_00d1e090 : public hkpKeyframedRigidMotion
{
    void ComputeVelocityAlongDirection(hkVector4* position, hkVector4* direction, float* angularResult,
                                       float* zeroResult);
};

// Writes transVel.direction + angVel.(direction x (position - center of mass)) to angularResult and 0 to zeroResult.
// @fnv 0x00d1e090
void Veh_00d1e090::ComputeVelocityAlongDirection(hkVector4* position, hkVector4* direction, float* angularResult,
                                                 float* zeroResult)
{
    __m128 delta =
        _mm_sub_ps(_mm_load_ps(reinterpret_cast<const float*>(position)),
                   _mm_load_ps(reinterpret_cast<const float*>(&m_kMotionState.m_kSweptTransform.m_vCenterOfMass1)));
    __m128 a = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(direction)),
                                         _mm_load_ps(reinterpret_cast<const float*>(direction)), 0xC9),
                          _mm_shuffle_ps(delta, delta, 0xD2));
    __m128 b = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(direction)),
                                         _mm_load_ps(reinterpret_cast<const float*>(direction)), 0xD2),
                          _mm_shuffle_ps(delta, delta, 0xC9));
    __m128 lin = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&m_kTranslationalVelocity)),
                            _mm_load_ps(reinterpret_cast<const float*>(direction)));
    __m128 cross = _mm_mul_ps(_mm_sub_ps(a, b), _mm_load_ps(reinterpret_cast<const float*>(&m_kAngularVelocity)));
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(cross, cross, 0x55), cross);
    __m128 s2 = _mm_add_ss(_mm_shuffle_ps(cross, cross, 0xAA), s1);
    __m128 t1 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0x55), lin);
    __m128 t2 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0xAA), t1);
    struct Vector4f
    {
        float x, y, z, w;
    } q;
    _mm_store_ss(&q.w, _mm_add_ss(s2, t2));
    *angularResult = q.w;
    *zeroResult = 0.0f;
}
}  // namespace fnv_00d1e090

extern "C" void _mm_store_ps(float*, __m128);

// @fnv 0x00d1e010
void __stdcall getInertiaLocal(hkVector4* inertia)
{
    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(reinterpret_cast<float*>(inertia), zero);
    _mm_store_ps(reinterpret_cast<float*>(inertia) + 4, zero);
    _mm_store_ps(reinterpret_cast<float*>(inertia) + 8, zero);
}

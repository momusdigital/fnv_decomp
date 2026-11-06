
// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleDefaultAerodynamics.h"
extern double DAT_01011588;
struct VehicleAerodynamicsStandIn
{
    float calcAerodynamicLift(float speed);
};

#include <xmmintrin.h>

struct hkSimdRealE443
{
    __m128 m_vValue;
    hkSimdRealE443(const float& f)
    {
        m_vValue = _mm_load_ss(&f);
    }
};

struct __declspec(align(16)) hkVector4E443
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }

    void setZero4()
    {
        getQuad() = _mm_setzero_ps();
    }
    void setMul4(const float& r, const hkVector4E443& v)
    {
        getQuad() = _mm_mul_ps(_mm_load1_ps(&r), v.getQuad());
    }
    void addMul4(const hkSimdRealE443& r, const hkVector4E443& v)
    {
        __m128 rr = r.m_vValue;
        rr = _mm_shuffle_ps(rr, rr, 0);
        getQuad() = _mm_add_ps(getQuad(), _mm_mul_ps(rr, v.getQuad()));
    }
    float dot3(const hkVector4E443& v) const
    {
        __m128 p = _mm_mul_ps(getQuad(), v.getQuad());
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, _MM_SHUFFLE(2, 2, 2, 2)),
                              _mm_add_ss(_mm_shuffle_ps(p, p, _MM_SHUFFLE(1, 1, 1, 1)), p));
        float f;
        _mm_store_ss(&f, s);
        return f;
    }
};

struct hkRotationE443
{
    hkVector4E443 m_kColumn0;
    hkVector4E443 m_kColumn1;
    hkVector4E443 m_kColumn2;
};

__forceinline void setRotatedDirE443(hkVector4E443& kOut, const hkRotationE443& r, const hkVector4E443& b)
{
    const __m128 q = b.getQuad();
    __m128 xb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(0, 0, 0, 0)), r.m_kColumn0.getQuad());
    __m128 yb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 1, 1, 1)), r.m_kColumn1.getQuad());
    __m128 zb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(2, 2, 2, 2)), r.m_kColumn2.getQuad());
    kOut.getQuad() = _mm_add_ps(_mm_add_ps(xb, yb), zb);
}

class hkpMotionE443
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_08;
    int m_0c;
    hkRotationE443 m_rotation;
    hkVector4E443 m_vTranslation;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    hkVector4E443 m_kTranslationalVelocity;

    float FUN_00c86430() const throw();
};

class hkpRigidBodyE443
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    hkpMotionE443 m_pMotionState;

    const hkRotationE443& getRotation() const
    {
        return m_pMotionState.m_rotation;
    }
    const hkVector4E443& getLinearVelocity() const
    {
        return m_pMotionState.m_kTranslationalVelocity;
    }
    float GetMassValue() const
    {
        return m_pMotionState.FUN_00c86430();
    }
};

struct hkpVehicleDataE443
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    hkRotationE443 m_kChassisOrientation;
};

struct hkpVehicleInstanceE443
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    hkpRigidBodyE443* m_pChassisCollidable;
    hkpVehicleDataE443* m_data;

    const hkpRigidBodyE443* getChassis() const
    {
        return m_pChassisCollidable;
    }
};

struct AerodynamicsDragOutputE443
{
    hkVector4E443 m_kForce;
    hkVector4E443 m_kTorque;
};

class hkpVehicleDefaultAerodynamicsE443 : public hkpVehicleDefaultAerodynamics
{
  public:
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual float calcDragForce(float m_fGain) throw();
    virtual float calcLiftForce(float m_fGain) throw();

    void calcAerodynamics(const float fMoveElapsedTime, const hkpVehicleInstanceE443* pkVehicle,
                      AerodynamicsDragOutputE443& kDragInfoOut) throw();
};

// @fnv 0x00e44370
void hkpVehicleDefaultAerodynamicsE443::calcAerodynamics(const float fMoveElapsedTime,
                                                     const hkpVehicleInstanceE443* pkVehicle,
                                                     AerodynamicsDragOutputE443& kDragInfoOut) throw()
{
    const hkpRigidBodyE443* pkChassis = pkVehicle->getChassis();
    const hkRotationE443& kRotationBasis = pkChassis->getRotation();

    hkVector4E443 kForward;
    setRotatedDirE443(kForward, kRotationBasis, pkVehicle->m_data->m_kChassisOrientation.m_kColumn2);
    hkVector4E443 kUp;
    setRotatedDirE443(kUp, kRotationBasis, pkVehicle->m_data->m_kChassisOrientation.m_kColumn1);

    const float m_fGain = pkChassis->getLinearVelocity().dot3(kForward);
    const float fDragForce = calcDragForce(m_fGain);
    const float fLiftForce = calcLiftForce(m_fGain);

    kDragInfoOut.m_kForce.setMul4(fDragForce, kForward);
    kDragInfoOut.m_kForce.addMul4(hkSimdRealE443(fLiftForce), kUp);

    const float fMass = pkChassis->GetMassValue();
    kDragInfoOut.m_kForce.addMul4(hkSimdRealE443(fMass),
                                  reinterpret_cast<const hkVector4E443&>(m_vExtraGravityWorldSpace));
    kDragInfoOut.m_kTorque.setZero4();
}

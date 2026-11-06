
// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultAerodynamics.h"

extern double DAT_01011588;

struct VehicleAerodynamicsStandIn
{
    float calcAerodynamicLift(float speed);
};

// @fnv 0x00e442e0
float VehicleAerodynamicsStandIn::calcAerodynamicLift(float speed)
{
    return reinterpret_cast<float*>(this)[2] * DAT_01011588 * reinterpret_cast<float*>(this)[5] *
           reinterpret_cast<float*>(this)[3] * speed * speed;
}

#include <xmmintrin.h>
class hkReferencedObjectE443
{
  public:
    hkReferencedObjectE443()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectE443() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e44310 : public hkReferencedObjectE443
{
  public:
    FUN_00e44310() throw();
    virtual ~FUN_00e44310() throw();

    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    __m128 m_20;
};

// Constructor that zero-initialises four float fields and one __m128 field of the object.
// @fnv 0x00e44310
FUN_00e44310::FUN_00e44310() throw()
{
    m_08 = 0.0f;
    m_0c = 0.0f;
    m_10 = 0.0f;
    m_14 = 0.0f;
    m_20 = _mm_setzero_ps();
}

#include <math.h>
class FUN_00e44340_cls
{
  public:
    char pad00[0x8];
    float unk08;
    float unk0C;
    float unk10;
    float calcAerodynamicDrag(float v);
};

// Returns v times |v| times (unk08 * -0.5 * unk10 * unk0C).
// @fnv 0x00e44340
float FUN_00e44340_cls::calcAerodynamicDrag(float v)
{
    float fAbs = (float)fabs((double)v);
    return v * (fAbs * (unk08 * -0.5 * unk10 * unk0C));
}

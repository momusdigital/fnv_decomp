// include/havok/hkpVehicleDefaultTransmission.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x34.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTTRANSMISSION_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTTRANSMISSION_H

#include "hkBase.h"
#include "hkpVehicleTransmission_decl_hkpvehicledefaulttransmission.h"
#pragma pack(push, 1)
class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
  public:
    float calcTransmissionRPM(const struct Vehicle* vehicle,
                       const void* input);  // declared for the original code (decl_variants.py)

  public:
    hkReal m_fDownshiftRPM;                // +0x8
    hkReal m_fUpshiftRPM;                  // +0xC
    hkReal m_fPrimaryTransmissionRatio;    // +0x10
    hkReal m_fClutchDelayTime;             // +0x14
    hkReal m_fReverseGearRatio;            // +0x18
    hkArray<hkReal> m_kGearRatios;         // +0x1C
    hkArray<hkReal> m_kWheelTorqueRatios;  // +0x28
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultTransmission[(sizeof(hkpVehicleDefaultTransmission) == 0x34) ? 1 : -1];
#endif

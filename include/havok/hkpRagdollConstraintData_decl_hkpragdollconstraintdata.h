// include/havok/hkpRagdollConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x140.
#ifndef FNV_HAVOK_HKPRAGDOLLCONSTRAINTDATA_H
#define FNV_HAVOK_HKPRAGDOLLCONSTRAINTDATA_H

#include "hkBase_decl_hkpragdollconstraintdata.h"
#include "hkpConstraintData.h"
#include "hkpRagdollConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpRagdollConstraintData : public hkpConstraintData
{
  public:
    hkBool isValid() const;  // declared for the original code (decl_variants.py)

  public:
    enum MotorIndex
    {
        MOTOR_TWIST = 0,
        MOTOR_PLANE = 1,
        MOTOR_CONE = 2
    };
    char padC[0x4];
    hkpRagdollConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRagdollConstraintData[(sizeof(hkpRagdollConstraintData) == 0x140) ? 1 : -1];
#endif

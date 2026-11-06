
// src/havok/physics/dynamics/constraint/chain/hingelimits/hkphingelimitsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hingelimits/hkphingelimitsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpHingeLimitsData.h"

extern "C" void __cdecl FUN_00d21a60(void* a, int b, int c);
struct hkPhingeLimitsData
{
    void __thiscall FUN_00d52f10(int arg);
};
// @fnv 0x00d52f10
void __thiscall hkPhingeLimitsData::FUN_00d52f10(int arg)
{
    FUN_00d21a60((char*)this + 0x10, 0x84, arg);
}

struct hkHingeLimitsData
{
    int m_fMinAngle;
    int m_fMaxAngle;
};

// @fnv 0x00d52f30
void __stdcall InitHingeLimitsData(const char* a, hkHingeLimitsData* pHingeLimitsData)
{
    pHingeLimitsData->m_fMaxAngle = 3;
    pHingeLimitsData->m_fMinAngle = 0x1c;
}

// @fnv 0x00d52fb0
int __cdecl FUN_00d52fb0()
{
    return 18;
}

struct hkBoolD52F
{
    char m_cBooleanValue;
    hkBoolD52F()
    {}
    hkBoolD52F(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) hkRotationD52F
{
    float m_kColumn0[4];
    float m_kColumn1[4];
    float m_kColumn2[4];

    hkBoolD52F IsOrthonormal(float fEpsilon) const;
};

class hkpConstraintFramesD52F
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
    hkRotationD52F m_kRotationA;
    hkRotationD52F m_kRotationB;

    hkBoolD52F isValid() const;
};

// @fnv 0x00d52f50
hkBoolD52F hkpConstraintFramesD52F::isValid() const
{
    return m_kRotationA.IsOrthonormal(0.001f) && m_kRotationB.IsOrthonormal(0.001f);
}

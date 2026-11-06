
// src/havok/physics/dynamics/constraint/pulley/hkppulleyconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/pulley/hkppulleyconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00d21a60(void* a, int b, int c);

struct hkpPulleyConstraintData
{
    void getConstraintInfo(int a);
};

// @fnv 0x00deef40
void hkpPulleyConstraintData::getConstraintInfo(int a)
{
    FUN_00d21a60((char*)this + 0x10, 0x70, a);
}

// Writes 1 and 8 into b[1] and b[0] when a is nonzero, otherwise writes 0 into both.
// @fnv 0x00deef60
void __stdcall FUN_00deef60(char a, int* b)
{
    if (a)
    {
        b[1] = 1;
        b[0] = 8;
    }
    else
    {
        b[1] = 0;
        b[0] = 0;
    }
}

struct S_00deef90_hkBool
{
    char m_cBooleanValue;
    S_00deef90_hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct S_00deef90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    float m_70;
    float m_74;
    S_00deef90_hkBool isValid() const;
};

// Returns true when both m_70 and m_74 are greater than zero.
// @fnv 0x00deef90
S_00deef90_hkBool S_00deef90::isValid() const
{
    return m_70 > 0.0f && m_74 > 0.0f;
}

// @fnv 0x00deefc0
int FUN_00deefc0(void)
{
    return 15;
}

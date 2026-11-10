
// src/speedtree/windengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/windengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern float DAT_010a5784;
extern float DAT_010a5788;

struct FUN_00b37510_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    void SetFromSource(const float* src);
};

// Copies src[0], src[1] and src[6] into f18, f1c and f4, and computes f20 and f24 from src[6] scaled by DAT_010a5784 and DAT_010a5788.
// @fnv 0x00b37510
void FUN_00b37510_shell::SetFromSource(const float* afSource)
{
    f18 = afSource[0];
    f1c = afSource[1];
    f20 = DAT_010a5784 * afSource[6] * f1c;
    f24 = DAT_010a5788 * afSource[6] * f18;
    f4 = afSource[6];
}

struct MatrixRange
{
    char _pad[0x28];
    unsigned int m_uiStartingMatrix;
    unsigned int m_uiMatrixSpan;
    void SetMatrixRange(unsigned int nStartingMatrix, unsigned int nMatrixSpan);
};

// @fnv 0x00b37570
void MatrixRange::SetMatrixRange(unsigned int nStartingMatrix, unsigned int nMatrixSpan)
{
    m_uiStartingMatrix = nStartingMatrix;
    m_uiMatrixSpan = nMatrixSpan;
}

extern float DAT_011f8d80;
struct CWindEngine
{
    float SetStrength(float fOldStrength, float fNewStrength, float fOldTimeShift);
};
// Stores the old strength, recomputes the frequency-scaled values at offsets 0x20/0x24 and the phase at offset 0, resets 0x30/0x34, and returns the phase.
// @fnv 0x00b37470
float CWindEngine::SetStrength(float fOldStrength, float fNewStrength, float fOldTimeShift)
{
    float fNewLeafFrequency = DAT_010a5784 * fNewStrength * ((float*)((char*)this + 0x1c))[0];
    ((float*)((char*)this + 4))[0] = fOldStrength;
    ((float*)((char*)this + 0x20))[0] =
        DAT_010a5784 * ((float*)((char*)this + 4))[0] * ((float*)((char*)this + 0x1c))[0];
    ((float*)((char*)this + 0x24))[0] =
        DAT_010a5788 * ((float*)((char*)this + 4))[0] * ((float*)((char*)this + 0x18))[0];
    ((float*)((char*)this + 0))[0] =
        DAT_011f8d80 * fNewLeafFrequency + fOldTimeShift - DAT_011f8d80 * ((float*)((char*)this + 0x20))[0];
    ((unsigned int*)((char*)this + 0x34))[0] = 0;
    ((unsigned int*)((char*)this + 0x30))[0] = 0;
    return ((float*)((char*)this + 0))[0];
}

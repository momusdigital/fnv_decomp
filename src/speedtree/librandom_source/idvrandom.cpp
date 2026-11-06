// speedtree/librandom_source/idvrandom.cpp: RandomNumberGenerator, Uniform (8 functions)

#include "idvrandom_decls.h"

// @fnv 0x00b3f100
RandomNumberGenerator::RandomNumberGenerator()
{
    if (!DAT_011f8eb8)
        SeedRandomGenerator(-1);
}

// @fnv 0x00b3f160
void RandomNumberGenerator::SeedRandomGenerator(long seed)
{
    if (seed == -1)
    {
        long randomSeed = 12345;
        if (DAT_011f8eb8)
            randomSeed = (long)GenerateRandomFloat(0.0f, 2147483648.0f);
        long currentTime = (long)_time64(0);
        if (randomSeed > currentTime)
            Random::Set((double)currentTime / randomSeed);
        else
            Random::Set((double)randomSeed / currentTime);
    }
    else
    {
        if (seed <= 1)
            seed = 1;
        Random::SetLong(seed);
    }
    DAT_011f8eb8 = true;
}

struct FUN_00b3f270_shell
{
    int GetOne();
};

// @fnv 0x00b3f270
int FUN_00b3f270_shell::GetOne()
{
    return 1;
}

struct DAT_011f8ebc_type
{
    double GetRandomSample();
};
extern DAT_011f8ebc_type DAT_011f8ebc;
struct FUN_00b3f130_shell
{
    float FUN_00b3f130(float fMin, float fScaledValue);
};
// Linearly interpolates between fMin and the second argument using a factor returned by DAT_011f8ebc.GetRandomSample().
// @fnv 0x00b3f130
float FUN_00b3f130_shell::FUN_00b3f130(float fMin, float afMax)
{
    return (float)((afMax - fMin) * DAT_011f8ebc.GetRandomSample() + fMin);
}

struct FloatIntPair
{
    float f;
    int i;
};
struct StandIn210
{
    FloatIntPair* InitHalf(FloatIntPair* p);
};
// Sets p->i to 0 and p->f to 0.5, then returns p.
// @fnv 0x00b3f210
FloatIntPair* StandIn210::InitHalf(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = 0.5f;
    return pValue;
}

namespace fnv_00b3f240 {
extern float DAT_010a58ec;
struct FloatIntPair
{
    float f;
    int i;
};
struct S00B3F240
{
    FloatIntPair* FUN_00b3f240(FloatIntPair* p);
};
// Sets p->i to 0 and p->f to DAT_010a58ec, then returns p.
// @fnv 0x00b3f240
FloatIntPair* S00B3F240::FUN_00b3f240(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = DAT_010a58ec;
    return pValue;
}
}  // namespace fnv_00b3f240

struct FUN_00b3f280_shell
{
    int Next();
};

struct FUN_00b433a0_shell
{
    int __thiscall GetRandomSample();
};

// @fnv 0x00b3f280
int FUN_00b3f280_shell::Next()
{
    return ((FUN_00b433a0_shell*)this)->GetRandomSample();
}

extern double _gModifierZero;
struct Uniform
{
    float Density(float x) const;
};
// Returns 1.0f when x is within [_gModifierZero, 1.0], otherwise 0.0f.
// @fnv 0x00b3f2a0
float Uniform::Density(float afValue) const
{
    return (afValue < _gModifierZero || afValue > 1.0) ? 0.0f : 1.0f;
}

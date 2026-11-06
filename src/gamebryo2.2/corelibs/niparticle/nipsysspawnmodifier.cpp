
#include "nipsysspawnmodifier_decls.h"

// Calls the base NiPSysModifier::LoadBinary, then loads eight values from kStream via a helper.
// @fnv 0x00c247f0
void NiPSysSpawnModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_usSpawnGenerationCount);
    ReadBinaryValue(kStream, m_fSpawnPercentage);
    ReadBinaryValue(kStream, m_usMinimumParticlesToSpawn);
    ReadBinaryValue(kStream, m_usMaximumParticlesToSpawn);
    ReadBinaryValue(kStream, m_fSpawnedSpeedChaos);
    ReadBinaryValue(kStream, m_fSpawnDirectionChaos);
    ReadBinaryValue(kStream, m_fYValue);
    ReadBinaryValue(kStream, m_fLifeSpanVariation);
}

// @fnv 0x00c2d6d0
void NiPSysBoundUpdateModifier::LinkObject(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
}

// @fnv 0x00c2d6e0
bool NiPSysBoundUpdateModifier::IsEqual(NiObject* pkObject)
{
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;

    NiPSysBoundUpdateModifier* pkModifier = static_cast<NiPSysBoundUpdateModifier*>(pkObject);
    return pkModifier->m_usUpdateSkip == m_usUpdateSkip ? true : false;
}

// @fnv 0x00c2d710
const NiRTTI* NiPSysBoundUpdateModifier::GetRTTI() const
{
    return &ms_kRTTI;
}

extern "C" const NiRTTI g_01202550;

// @fnv 0x00c23ce0
const NiRTTI* __cdecl FUN_00c23ce0()
{
    return &g_01202550;
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, int);
void __cdecl FUN_00c31750();

struct FUN_00c23cf0_shell
{
    FUN_00c23cf0_shell* __thiscall FUN_00c23cf0(int param);
};

// @fnv 0x00c23cf0
FUN_00c23cf0_shell* __thiscall FUN_00c23cf0_shell::FUN_00c23cf0(int param)
{
    FUN_00c31750();
    if (param & 1)
        __Dummy_00b6fef0(this, 0x34);
    return this;
}

struct FUN_00c23b70_shell : NiObject
{
    bool __thiscall IsEqual(NiObject*) const;
    char pad[0x18 - sizeof(NiObject)];
    unsigned short m_usSpawnGenerationCount;
    float m_fSpawnPercentage;
    unsigned short m_usMinimumParticlesToSpawn;
    unsigned short m_usMaximumParticlesToSpawn;
    float m_fSpawnedSpeedChaos;
    float m_fSpawnDirectionChaos;
    float m_fYValue;
    float m_fLifeSpanVariation;
    bool __thiscall FUN_00c23b70(NiObject* pkObject);
};
// Compares this object with pkObject: checks IsEqual and that eight stored values match, returning true only if all are equal.
// @fnv 0x00c23b70
bool __thiscall FUN_00c23b70_shell::FUN_00c23b70(NiObject* pkObject)
{
    FUN_00c23b70_shell* pkDest = static_cast<FUN_00c23b70_shell*>(pkObject);
    if (IsEqual(pkObject) && pkDest->m_usSpawnGenerationCount == m_usSpawnGenerationCount &&
        pkDest->m_fSpawnPercentage == m_fSpawnPercentage &&
        pkDest->m_usMinimumParticlesToSpawn == m_usMinimumParticlesToSpawn &&
        pkDest->m_usMaximumParticlesToSpawn == m_usMaximumParticlesToSpawn &&
        pkDest->m_fSpawnedSpeedChaos == m_fSpawnedSpeedChaos &&
        pkDest->m_fSpawnDirectionChaos == m_fSpawnDirectionChaos && pkDest->m_fYValue == m_fYValue &&
        pkDest->m_fLifeSpanVariation == m_fLifeSpanVariation)
        return true;
    return false;
}

struct StrArr
{
    unsigned char pad[8];
    unsigned short m_usCapacity;
    unsigned short m_usSize;
    unsigned short m_usReserved;
    unsigned short m_usGrowth;

    void __thiscall SetSize(unsigned int size);
    void __thiscall SetAt(unsigned int index, char*& value);
};

struct Base00c319e0
{
    unsigned char pad[0x18];

    void __thiscall FUN_00c319e0(StrArr* strings);
};

struct FUN_00c24a50_shell : Base00c319e0
{
    unsigned short m_usSpawnGenerationCount;
    float m_fSpawnPercentage;
    unsigned short m_usMinimumParticlesToSpawn;
    unsigned short m_usMaximumParticlesToSpawn;
    float m_fSpawnedSpeedChaos;
    float m_fSpawnDirectionChaos;
    float m_fYValue;
    float m_fLifeSpanVariation;

    void __thiscall AppendSpawnSettingsStrings(StrArr* strings);
};

char* __cdecl _FUN_00a7d330(void* value);
char* __cdecl FUN_00a7d490(char const* name, unsigned short value);
char* __cdecl FUN_00a7d550(char const* name, float value);

// Appends formatted spawn-setting name/value strings to the StrArr, growing it when full.
// @fnv 0x00c24a50
void __thiscall FUN_00c24a50_shell::AppendSpawnSettingsStrings(StrArr* strings)
{
    Base00c319e0::FUN_00c319e0(strings);

    {
        char* value = _FUN_00a7d330(*reinterpret_cast<void* const*>(&g_01202550));
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d490("Num Spawn Generations", m_usSpawnGenerationCount);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d550("Percentage Spawned", m_fSpawnPercentage);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d490("Min Num to Spawn", m_usMinimumParticlesToSpawn);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d490("Max Num to Spawn", m_usMaximumParticlesToSpawn);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d550("Spawn Speed Chaos", m_fSpawnedSpeedChaos);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d550("Spawn Dir Chaos", m_fSpawnDirectionChaos);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d550("Life Span", m_fYValue);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d550("Life Span Variation", m_fLifeSpanVariation);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usCapacity)
            strings->SetSize(index + strings->m_usGrowth);
        strings->SetAt(index, value);
    }
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_010be124;

struct FUN_00c23d10_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    short m_18;
    short unk1A;
    float m_1C;
    short m_20;
    short m_22;
    float m_24;
    float m_28;
    float m_2C;
    float m_30;

    void FUN_00c31720();
    void FUN_00c31780(FUN_00c23d10_cls* pDst, int a1);
    FUN_00c23d10_cls* Clone(int a1);
};

// @fnv 0x00c23d10
FUN_00c23d10_cls* FUN_00c23d10_cls::Clone(int aiArg)
{
    FUN_00c23d10_cls* pkNew = (FUN_00c23d10_cls*)FUN_00aa13e0(0x34);
    if (pkNew != 0)
    {
        pkNew->FUN_00c31720();
        pkNew->m_1C = 1.0f;
        pkNew->m_24 = 0.0f;
        pkNew->m_28 = 0.0f;
        *(int*)pkNew = (int)&DAT_010be124;
        pkNew->m_2C = 0.0f;
        pkNew->m_18 = 1;
        pkNew->m_30 = 0.0f;
        pkNew->m_20 = 1;
        pkNew->m_22 = 1;
    }
    else
    {
        pkNew = 0;
    }
    this->FUN_00c31780(pkNew, aiArg);
    pkNew->m_18 = this->m_18;
    pkNew->m_1C = this->m_1C;
    pkNew->m_20 = this->m_20;
    pkNew->m_22 = this->m_22;
    pkNew->m_24 = this->m_24;
    pkNew->m_28 = this->m_28;
    pkNew->m_2C = this->m_2C;
    pkNew->m_30 = this->m_30;
    return pkNew;
}

struct SaveBinaryStream
{
    void** unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(SaveBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(SaveBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    __forceinline unsigned int BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes,
                                           unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, buffer, bytes, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

struct SaveStream : NiStream
{
    SaveBinaryStream* m_pBackingStream;
};

template <class T> __forceinline void BinaryStreamSave(SaveBinaryStream& stream, const T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(value, sizeof(T) * count, &size, 1);
}

template <class T> __forceinline void StreamSaveBinary(SaveStream& stream, const T& value)
{
    BinaryStreamSave(*stream.m_pBackingStream, &value, 1);
}

struct SpawnModifier : NiPSysSpawnModifier
{
    void __thiscall FUN_00c31950(SaveStream& stream);
    void __thiscall SaveBinary(SaveStream& stream);
};

// Saves the SpawnModifier fields to the stream after calling the base class save routine.
// @fnv 0x00c24920
void SpawnModifier::SaveBinary(SaveStream& stream)
{
    FUN_00c31950(stream);
    StreamSaveBinary(stream, m_usSpawnGenerationCount);
    StreamSaveBinary(stream, m_fSpawnPercentage);
    StreamSaveBinary(stream, m_usMinimumParticlesToSpawn);
    StreamSaveBinary(stream, m_usMaximumParticlesToSpawn);
    StreamSaveBinary(stream, m_fSpawnedSpeedChaos);
    StreamSaveBinary(stream, m_fSpawnDirectionChaos);
    StreamSaveBinary(stream, m_fYValue);
    StreamSaveBinary(stream, m_fLifeSpanVariation);
}

#include <string.h>
struct FUN_00c23c00_shell
{
    void __thiscall AddDelta(float*, float*);
};

// Copies 9 floats from the object into fTimeSinceScaleStart, then adds each element of fDelta2 to the corresponding element.
// @fnv 0x00c23c00
void FUN_00c23c00_shell::AddDelta(float* afOut, float* afDelta)
{
    memcpy(afOut, (float*)this, 9 * sizeof(float));
    afOut[0] += afDelta[0];
    afOut[1] += afDelta[1];
    afOut[2] += afDelta[2];
    afOut[3] += afDelta[3];
    afOut[4] += afDelta[4];
    afOut[5] += afDelta[5];
    afOut[6] += afDelta[6];
    afOut[7] += afDelta[7];
    afOut[8] += afDelta[8];
}

struct FUN_00c23c70_shell
{
    void SubtractFrom(float* dst, const float* sub);
};

// Copies the 36-byte object into dst, then subtracts each element of sub from the first 9 floats in dst.
// @fnv 0x00c23c70
void FUN_00c23c70_shell::SubtractFrom(float* dst, const float* sub)
{
    memcpy(dst, this, 36);
    for (int i = 0; i < 9; ++i)
        dst[i] -= sub[i];
}

#include <stdlib.h>
#include <math.h>
struct ParticleInfoX
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysDataX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    ParticleInfoX* m_pkParticleInfo;
};

struct ParticleSystemX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    PSysDataX* m_spGeometryData;
};

class SpawnModifierX
{
  public:
    virtual ~SpawnModifierX();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void UpdateSpawning(float afTime, float fTime, unsigned short usOldIndex, ParticleSystemX* pkSystem);

    unsigned int m_uiRefCount;
    int m_kName;
    unsigned int m_uiUpdateOrder;
    ParticleSystemX* m_pkTarget;
    bool m_bModifierActive;
    char unk15;
    short unk16;
    unsigned short m_usSpawnGenerationCount;
    float m_fSpawnPercentage;
    unsigned short m_usMinimumParticlesToSpawn;
    unsigned short m_usMaximumParticlesToSpawn;
    float m_fSpawnedSpeedChaos;
    float m_fSpawnDirectionChaos;
    float m_fYValue;
    float m_fLifeSpanVariation;

    void FUN_00c23db0(float afTime, float fTime, unsigned short usOldIndex, ParticleSystemX* pkSystem);
};

inline float RandomFloat0To1()
{
    return (float)(rand() / (double)RAND_MAX);
}

// @fnv 0x00c23db0
void SpawnModifierX::FUN_00c23db0(float afTime, float fTime, unsigned short usOldIndex, ParticleSystemX* pkSystem)
{
    PSysDataX* pkData = pkSystem->m_spGeometryData;
    if (pkData->m_pkParticleInfo[usOldIndex].m_usFirstValue < m_usSpawnGenerationCount &&
        !(RandomFloat0To1() > m_fSpawnPercentage))
    {
        float fNumToSpawn = (m_usMaximumParticlesToSpawn - m_usMinimumParticlesToSpawn) * RandomFloat0To1();
        unsigned short usExtra = (unsigned short)fNumToSpawn;
        if (fmod(fNumToSpawn, 1.0f) > 0.5f)
            usExtra++;
        unsigned short usNumToSpawn = m_usMinimumParticlesToSpawn + usExtra;
        if (usNumToSpawn == 0)
            usNumToSpawn = 1;
        for (unsigned short us = 0; us < usNumToSpawn; us++)
            UpdateSpawning(afTime, fTime, usOldIndex, pkSystem);
    }
}

extern "C" int __cdecl rand();
extern "C" const double DAT_01029790;
extern "C" const double DAT_01012070;
extern "C" const double DAT_0101ff40;
extern "C" const double DAT_01028338;
extern "C" const double DAT_01012060;
extern "C" const double DAT_01011588;
extern "C" const float DAT_011aeb34;
extern "C" const float DAT_010c09c0;
extern "C" const float DAT_01012054;
extern "C" const float DAT_011f52e0[];
extern "C" const float DAT_011f4ae0[];
extern "C" const unsigned short DAT_010be248;

struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt3 operator-() const
    {
        return Pt3(-x, -y, -z);
    }
};

struct ColA
{
    float r, g, b, a;
};

struct Mat3
{
    float m[3][3];
    static const Mat3 IDENTITY;
    Mat3()
    {}
    Mat3(const Pt3& c0, const Pt3& c1, const Pt3& c2);
    Mat3 operator*(float f) const;
    Mat3 operator+(const Mat3& o) const;
    Mat3 operator-(const Mat3& o) const;
    Mat3 operator*(const Mat3& o) const;
};

__declspec(noinline) Mat3 Mat3::operator*(float f) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            result.m[row][col] = m[row][col] * f;
    return result;
}
__declspec(noinline) Mat3 Mat3::operator+(const Mat3 & o) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            result.m[row][col] = m[row][col] + o.m[row][col];
    return result;
}
__declspec(noinline) Mat3 Mat3::operator-(const Mat3 & o) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            result.m[row][col] = m[row][col] - o.m[row][col];
    return result;
}
__declspec(noinline) Mat3 Mat3::operator*(const Mat3 & o) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            result.m[row][col] = m[row][0] * o.m[0][col] + m[row][1] * o.m[1][col] + m[row][2] * o.m[2][col];
    return result;
}

struct Xform
{
    Mat3 m_kOrientation;
    Pt3 m_kTranslation;
    float m_fScale;
    Pt3 operator*(const Pt3& p) const;
    void Invert(Xform& dst) const;
};

struct PInfo
{
    Pt3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysData
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual unsigned short GetParticleVertexCount();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Pt3* m_pkVertex;
    int unk24;
    ColA* m_pkColor;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    float* m_pfRadii;
    int unk50;
    float* m_pfSizes;
    int unk58;
    float* m_pfRotationAngles;
    Pt3* m_pkRotationAxes;
    int unk64, unk68, unk6C;
    PInfo* m_pkParticleInfo;
    float* m_pfRotationSpeeds;
};

struct PSys
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    Xform m_kWorldSpaceTransform;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    PSysData* m_spGeometryData;
    void InitializeSpawnedParticle(unsigned short usNewParticle);
};

static inline float UnitRandom()
{
    return (float)(rand() / DAT_01029790);
}

static inline void FastSinCos(float f, float& sine, float& cosine)
{
    int index = (int)(f * (DAT_01028338 / DAT_011aeb34)) & 0x1ff;
    sine = DAT_011f52e0[index];
    cosine = DAT_011f4ae0[index];
}

static inline Pt3 MulMV(Mat3 m, const Pt3& p)
{
    Pt3 r;
    r.x = m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2] * p.z;
    r.y = m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2] * p.z;
    r.z = m.m[2][0] * p.x + m.m[2][1] * p.y + m.m[2][2] * p.z;
    return r;
}

static inline Pt3 InverseMulMV(Mat3 m, const Pt3& p)
{
    Pt3 r;
    r.x = (double)(m.m[0][0] * p.x) + m.m[0][1] * p.y + m.m[0][2] * p.z;
    r.y = (double)(m.m[1][0] * p.x) + m.m[1][1] * p.y + m.m[1][2] * p.z;
    r.z = (double)(m.m[2][0] * p.x) + m.m[2][1] * p.y + m.m[2][2] * p.z;
    return r;
}

__declspec(noinline) Pt3 Xform::operator*(const Pt3 & p) const
{
    Pt3 result = MulMV(m_kOrientation, p);
    result.x = result.x * m_fScale + m_kTranslation.x;
    result.y = result.y * m_fScale + m_kTranslation.y;
    result.z = result.z * m_fScale + m_kTranslation.z;
    return result;
}

struct Element
{
    float value;
    Element& operator=(float f)
    {
        value = f;
        return *this;
    }
    operator float() const
    {
        return value;
    }
};
struct LocalPoint
{
    float x;
    Element y;
    float z;
};

struct SpawnWorker : NiPSysSpawnModifier
{
    void FUN_00c23ee0(float afTime, float fTimeDelta, unsigned short usOldIndex, PSys* pkOldPSystem);
};

// @fnv 0x00c23ee0
void SpawnWorker::FUN_00c23ee0(float afTime, float fTimeDelta, unsigned short usOldIndex, PSys* pkOldPSystem)
{
    Pt3 kMotionVelocity;
    (void)kMotionVelocity.x;
    PSysData* pkOldData = pkOldPSystem->m_spGeometryData;
    PInfo* pkOldInfo = &pkOldData->m_pkParticleInfo[usOldIndex];
    Pt3* pkOldVerts = pkOldData->m_pkVertex;
    ColA* pkOldColors = pkOldData->m_pkColor;
    float* pfOldRadii = pkOldData->m_pfRadii;
    float* pfOldSizes = pkOldData->m_pfSizes;
    float* pfOldRotAngles = pkOldData->m_pfRotationAngles;
    Pt3* pkOldRotAxes = pkOldData->m_pkRotationAxes;
    float* pfOldRotSpeeds = pkOldData->m_pfRotationSpeeds;

    Pt3 kPosition = pkOldVerts[usOldIndex];
    kMotionVelocity = pkOldInfo->m_kValue;

    PSys* pkTarget = (PSys*)m_pkTarget;
    if (pkOldPSystem != pkTarget)
    {
        Xform kOldWorld = pkOldPSystem->m_kWorldSpaceTransform;
        (void)kOldWorld.m_kOrientation.m[0][0];
        kPosition = kOldWorld * kPosition;
        kMotionVelocity = MulMV(kOldWorld.m_kOrientation, kMotionVelocity);
        Xform kTargetWorld = pkTarget->m_kWorldSpaceTransform;
        kTargetWorld.Invert(kOldWorld);
        kPosition = kOldWorld * kPosition;
        kMotionVelocity = InverseMulMV(kOldWorld.m_kOrientation, kMotionVelocity);
    }

    PSysData* pkData = ((PSys*)m_pkTarget)->m_spGeometryData;
    unsigned short usNewIndex = pkData->GetParticleVertexCount();
    if (usNewIndex == DAT_010be248)
        return;

    float fPreviousTime = afTime - fTimeDelta;
    PInfo* pkNewInfo = &pkData->m_pkParticleInfo[usNewIndex];
    Pt3* pkNewVerts = pkData->m_pkVertex;
    ColA* pkNewColors = pkData->m_pkColor;
    float* pfNewRadii = pkData->m_pfRadii;
    float* pfNewSizes = pkData->m_pfSizes;
    float* pfNewRotAngles = pkData->m_pfRotationAngles;
    Pt3* pkNewRotAxes = pkData->m_pkRotationAxes;
    float* pfNewRotSpeeds = pkData->m_pfRotationSpeeds;

    float fLenSq = (double)(kMotionVelocity.x * kMotionVelocity.x + kMotionVelocity.y * kMotionVelocity.y +
                            kMotionVelocity.z * kMotionVelocity.z);
    float fLen = sqrtf(fLenSq);

    float fSpeedVar = m_fSpawnedSpeedChaos * UnitRandom();
    float fSpeed = (fSpeedVar + DAT_01012070) * fLen;

    float fDecl = (float)(m_fSpawnDirectionChaos * UnitRandom() * DAT_0101ff40);
    float fRand = UnitRandom();
    float fSinDecl, fCosDecl;
    FastSinCos(fDecl, fSinDecl, fCosDecl);
    float fPlanar = fRand * DAT_011aeb34;
    float fSinPlanar, fCosPlanar;
    FastSinCos(fPlanar, fSinPlanar, fCosPlanar);
    Pt3 kWorldPosition;
    kWorldPosition.x = fSinDecl * fCosPlanar;
    kWorldPosition.y = fSinDecl * fSinPlanar;
    kWorldPosition.z = fCosDecl;

    Mat3 kRot = Mat3::IDENTITY;

    {
        Pt3 kNeg = -kMotionVelocity;
        Mat3 kSkew;
        kSkew.m[0][0] = 0.0f;
        kSkew.m[1][0] = 0.0f;
        kSkew.m[0][1] = 0.0f;
        kSkew.m[1][1] = 0.0f;
        kSkew.m[2][0] = kMotionVelocity.x;
        kSkew.m[2][1] = kMotionVelocity.y;
        kSkew.m[0][2] = kNeg.x;
        kSkew.m[1][2] = kNeg.y;
        kSkew.m[2][2] = 0.0f;
        Pt3 kAxis(kMotionVelocity.y, -kMotionVelocity.x, 0.0f);

        LocalPoint kCross;
        kCross.x = kWorldPosition.y * kMotionVelocity.z - kWorldPosition.z * kMotionVelocity.y;
        kCross.y = kWorldPosition.z * kMotionVelocity.x - kWorldPosition.x * kMotionVelocity.z;
        kCross.z = kWorldPosition.x * kMotionVelocity.y - kWorldPosition.y * kMotionVelocity.x;
        float fDot = (float)((double)(kCross.x * kAxis.x) + kAxis.y * kCross.y + kCross.z * DAT_01012060);

        if (fDot > DAT_010c09c0)
        {
            kRot = kRot + kSkew *
                              (kRot + kSkew * ((fLen - kMotionVelocity.z) / (kMotionVelocity.x * kMotionVelocity.x +
                                                                             kMotionVelocity.y * kMotionVelocity.y))) *
                              (1.0f / fLen);
        }
        else if (-fDot > DAT_010c09c0)
        {
            kRot = kRot - kSkew *
                              (kRot - kSkew * ((fLen - kMotionVelocity.z) / (kMotionVelocity.x * kMotionVelocity.x +
                                                                             kMotionVelocity.y * kMotionVelocity.y))) *
                              (1.0f / fLen);
        }
        else if (kMotionVelocity.z < kAxis.z)
        {
            kRot = Mat3(Pt3(DAT_01012054, 0.0f, 0.0f), Pt3(0.0f, DAT_01012054, 0.0f), Pt3(0.0f, 0.0f, DAT_01012054));
        }
    }

    Mat3 kScaled;
    kScaled.m[0][0] = kRot.m[0][0] * fSpeed;
    kScaled.m[0][1] = kRot.m[0][1] * fSpeed;
    kScaled.m[0][2] = kRot.m[0][2] * fSpeed;
    kScaled.m[1][0] = kRot.m[1][0] * fSpeed;
    kScaled.m[1][1] = kRot.m[1][1] * fSpeed;
    kScaled.m[1][2] = kRot.m[1][2] * fSpeed;
    kScaled.m[2][0] = kRot.m[2][0] * fSpeed;
    kScaled.m[2][1] = kRot.m[2][1] * fSpeed;
    kScaled.m[2][2] = kRot.m[2][2] * fSpeed;
    kWorldPosition = MulMV(kScaled, kWorldPosition);
    pkNewInfo->m_kValue = kWorldPosition;
    pkNewInfo->m_fXValue = fPreviousTime;
    pkNewInfo->m_fYValue = (float)((UnitRandom() - DAT_01011588) * m_fLifeSpanVariation + m_fYValue);
    pkNewInfo->m_usFirstValue = pkOldInfo->m_usFirstValue + 1;

    pkNewVerts[usNewIndex] = kPosition;

    if (pkOldColors && pkNewColors)
        pkNewColors[usNewIndex] = pkOldColors[usOldIndex];
    if (pfOldRadii && pfNewRadii)
        pfNewRadii[usNewIndex] = pfOldRadii[usOldIndex];
    if (pfOldSizes && pfNewSizes)
        pfNewSizes[usNewIndex] = pfOldSizes[usOldIndex];
    if (pfOldRotAngles && pfNewRotAngles)
    {
        pfNewRotAngles[usNewIndex] = pfOldRotAngles[usOldIndex];
        pfNewRotSpeeds[usNewIndex] = pfOldRotSpeeds[usOldIndex];
    }
    if (pkOldRotAxes && pkNewRotAxes)
        pkNewRotAxes[usNewIndex] = pkOldRotAxes[usOldIndex];

    pkNewInfo->m_fZValue = afTime - pkNewInfo->m_fXValue;
    ((PSys*)m_pkTarget)->InitializeSpawnedParticle(usNewIndex);
}

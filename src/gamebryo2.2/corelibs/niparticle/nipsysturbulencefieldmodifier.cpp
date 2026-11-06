
// src/gamebryo2.2/corelibs/niparticle/nipsysturbulencefieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysturbulencefieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const void* const g_01202698;

// @fnv 0x00c273c0
const void* __cdecl FUN_00c273c0()
{
    return &g_01202698;
}

struct NiObject
{
    char _pad;
};

struct NiPSysFieldModifier
{
    char _pad[0x30];
    bool __thiscall FUN_00c32060(NiObject* pkObject);
};

struct NiPSysTurbulenceFieldModifier : NiPSysFieldModifier
{
    float m_fFrequency;
    bool __thiscall IsEqual(NiObject* pkObject);
};

// @fnv 0x00c27390
bool __thiscall NiPSysTurbulenceFieldModifier::IsEqual(NiObject* pkObject)
{
    NiPSysTurbulenceFieldModifier* pkDest;
    if (!NiPSysFieldModifier::FUN_00c32060(pkObject))
        return false;
    pkDest = (NiPSysTurbulenceFieldModifier*)pkObject;
    if (pkDest->m_fFrequency != m_fFrequency)
        return false;
    return true;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct NiPSysParticle
{
    void FUN_00c32020(NiPSysParticle*, CloningProcess*);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00c31ff0
{
    FUN_00c31ff0();
};
extern float DAT_01015f5c;
extern float DAT_01022958;
extern double DAT_01032980;
extern int DAT_010be774;
struct NiPSysFieldModifier_00c27670
{
    int* _vtable;
    char _pad[0x2c];
    float m_fFrequency;
    float m_fFieldMagnitude;
    float m_fFieldDistance;
    NiPSysFieldModifier_00c27670();
    void FUN_00c32020(NiPSysParticle*, CloningProcess*);
};
// @fnv 0x00c27670
NiPSysFieldModifier_00c27670* __fastcall CloneFieldModifier(NiPSysFieldModifier_00c27670* self, int,
                                                            CloningProcess* kCloning)
{
    NiPSysFieldModifier_00c27670* pkObject = (NiPSysFieldModifier_00c27670*)BSFadeNode::operator new(0x3c);
    if (pkObject)
    {
        ((FUN_00c31ff0*)pkObject)->FUN_00c31ff0::FUN_00c31ff0();
        pkObject->m_fFrequency = 0.0f;
        pkObject->_vtable = &DAT_010be774;
        pkObject->m_fFieldDistance = DAT_01015f5c;
        pkObject->m_fFieldMagnitude = DAT_01022958;
    }
    else
        pkObject = 0;
    ((NiPSysParticle*)self)->FUN_00c32020((NiPSysParticle*)pkObject, kCloning);
    pkObject->m_fFrequency = self->m_fFrequency;
    if (pkObject->m_fFrequency < DAT_01032980)
        pkObject->m_fFieldMagnitude = DAT_01022958;
    else
        pkObject->m_fFieldMagnitude = 1.0f / pkObject->m_fFrequency;
    return pkObject;
}

struct C27A30RTTI
{
    const char* m_pcName;
    const C27A30RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

struct C27A30StringArray
{
    virtual ~C27A30StringArray();

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);

    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

extern "C" char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d550(const char* pcPrefix, float fValue);

struct C27A30Base
{
    void GetViewerStrings(C27A30StringArray* pkStrings);
};

struct C27A30Object : C27A30Base
{
    static C27A30RTTI ms_kRTTI;

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
    float m_fFrequency;

    void GetViewerStrings(C27A30StringArray* pkStrings);
};

// Appends the RTTI name and a formatted "Frequency" string for m_fFrequency to pkStrings after calling the base handler.
// @fnv 0x00c27a30
void C27A30Object::GetViewerStrings(C27A30StringArray* pkStrings)
{
    C27A30Base::GetViewerStrings(pkStrings);
    char* pcString = FUN_00a7d330(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
    pcString = FUN_00a7d550("Frequency", m_fFrequency);
    pkStrings->Add(pcString);
}

struct FieldReadState;
typedef unsigned int(__cdecl* ReadFunction)(FieldReadState*, float*, unsigned int, unsigned int*, unsigned int);
struct FieldReadState
{
    int unk00;
    unsigned int bytesRead;
    ReadFunction read;
    void ReadFloat(float* value)
    {
        unsigned int readSize = 4;
        bytesRead += read(this, value, 4, &readSize, 1);
    }
};
extern double DAT_01032980;
extern float DAT_01022958;
struct FUN_00c27700_class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    float m_uiFilterValue, m_inverse;
    void __thiscall LoadFromStream(void* object);
    void __thiscall ReadFloatAndComputeInverse(void* object);
};
// Reads a float from the stream at object+0x24c and stores its reciprocal, or a fallback constant when the value is below DAT_01032980.
// @fnv 0x00c27700
void __thiscall FUN_00c27700_class::ReadFloatAndComputeInverse(void* object)
{
    LoadFromStream(object);
    FieldReadState* stream = *(FieldReadState**)((char*)object + 0x24c);
    stream->ReadFloat(&m_uiFilterValue);
    if (m_uiFilterValue < DAT_01032980)
        m_inverse = DAT_01022958;
    else
        m_inverse = 1.0f / m_uiFilterValue;
}

// FUN_00c274c0: NiPSysTurbulenceFieldModifier::Update - random velocity kick
// for every particle within the field's maximum distance.
int __cdecl FUN_00ecadb8();
extern double DAT_01029790;

struct TPoint3
{
    float x, y, z;

    TPoint3()
    {}
    TPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    TPoint3 operator-(const TPoint3& kPt) const
    {
        return TPoint3(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    TPoint3 operator*(float fScalar) const
    {
        return TPoint3(fScalar * x, fScalar * y, fScalar * z);
    }
    TPoint3& operator+=(const TPoint3& kPt)
    {
        x += kPt.x;
        y += kPt.y;
        z += kPt.z;
        return *this;
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
};

struct TMatrix3
{
    float m_afEntries[3][3];
};

struct NiTransform
{
    TMatrix3 m_kOrientation;
    TPoint3 m_kTranslation;
    float m_fScale;

    void FUN_004b4880(NiTransform& kDest) const;
    NiTransform operator*(const NiTransform& kXform) const;
};

struct TAVObject
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
    NiTransform m_kWorldSpaceTransform;
};

struct TParticleInfo
{
    TPoint3 m_kValue;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct TPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TPoint3* m_pkVertex;
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
    unsigned short m_usVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TParticleInfo* m_pkParticleInfo;

    TPoint3* GetVertices() const
    {
        return m_pkVertex;
    }
    TParticleInfo* GetParticleInfo() const
    {
        return m_pkParticleInfo;
    }
};

inline float SymmetricRandom()
{
    return (float)(2.0 * FUN_00ecadb8() / DAT_01029790 - 1.0);
}

struct TTurbulenceModifier
{
    void* m_pVtbl;
    int m_iRefCount;
    int m_kName;
    unsigned int m_uiUpdateOrder;
    TAVObject* m_pkTarget;
    bool m_bModifierActive;
    TAVObject* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    float m_fFieldStrength;

    void FUN_00c274c0(float fTime, TPSysData* pkData);
};

// Applies a random offset scaled by m_fInfluence to particle values whose squared distance from the transformed field position is at most m_fFieldStrength.
// @fnv 0x00c274c0
void TTurbulenceModifier::FUN_00c274c0(float fTime, TPSysData* pkData)
{
    NiTransform kFieldXform = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvPSys;
    {
        NiTransform kPSysXform = m_pkTarget->m_kWorldSpaceTransform;
        kPSysXform.FUN_004b4880(kInvPSys);
    }

    {
        NiTransform kFieldToPSys = kInvPSys * kFieldXform;
        for (unsigned short i = 0; i < pkData->m_usVertices; i++)
        {
            TParticleInfo* pkInfo = &pkData->GetParticleInfo()[i];
            TPoint3 kPos = pkData->GetVertices()[i];
            TPoint3 kDiff = kPos - kFieldToPSys.m_kTranslation;
            if (kDiff.SqrLength() <= m_fFieldStrength)
            {
                TPoint3 kRand;
                kRand.x = SymmetricRandom();
                kRand.y = SymmetricRandom();
                kRand.z = SymmetricRandom();
                pkInfo->m_kValue += kRand * m_fInfluence;
            }
        }
    }
}

#include <math.h>
extern "C" int __cdecl rand();

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3()
    {}
    NiPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}

    void operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
    }
    NiPoint3 operator-(const TPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    float Length() const;
    void operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
    }
};

struct NiAVObject
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
    NiTransform m_kWorldSpaceTransform;

    const NiTransform& GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
};

struct ParticleInfo
{
    NiPoint3 m_kValue;
    float unk0c;
    float unk10;
    float unk14;
    unsigned short unk18;
    unsigned short unk1a;
};

struct NiPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* m_pkPositions;
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
    unsigned short m_usNumParticles;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    ParticleInfo* m_pkParticleInfo;

    unsigned short GetShaderParticleCount() const
    {
        return m_usNumParticles;
    }
    ParticleInfo* GetParticleInfo() const
    {
        return m_pkParticleInfo;
    }
    NiPoint3* GetVertices() const
    {
        return m_pkPositions;
    }
};

struct NiPSysTurbulenceFieldModifierDerived
{
    void* _vtable;
    int unk04;
    int unk08;
    int unk0c;
    NiAVObject* m_pkTarget;
    int unk14;
    NiAVObject* m_spFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    char unk25;
    char unk26;
    char unk27;
    float m_fDistanceLimit;
    int unk2c;
    float m_fFrequency;
    float m_fFieldMagnitude;
    float m_fFieldDistance;

    float ReadScalar() const
    {
        return m_fInfluence;
    }

    void __thiscall ApplyRandomOffset(float fTime, NiPSysData* pkData);
    void __thiscall FUN_00c274c0(float fTime, NiPSysData* pkData);
    void __thiscall UpdateTurbulence(float fTime, NiPSysData* pkData);
};

inline float NiPoint3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

// Applies random turbulence offsets to particle values based on distance from the field object, scaling by influence and attenuation.
// @fnv 0x00c277b0
void __thiscall NiPSysTurbulenceFieldModifierDerived::UpdateTurbulence(float fTime, NiPSysData* pkData)
{
    if (fTime >= m_fFieldDistance && fTime < m_fFieldDistance + m_fFieldMagnitude)
        return;

    m_fFieldDistance = fTime;

    if (ReadScalar() == 0.0f || pkData->GetShaderParticleCount() == 0 || !m_spFieldObject)
        return;

    if (m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            FUN_00c274c0(fTime, pkData);
        else
            ApplyRandomOffset(fTime, pkData);
    }
    else
    {
        NiTransform kField = m_spFieldObject->GetWorldTransform();
        NiTransform kInv;
        {
            NiTransform kTarget = m_pkTarget->GetWorldTransform();
            kTarget.FUN_004b4880(kInv);
        }
        {
            NiTransform kPos = kInv * kField;

            for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); ++i)
            {
                ParticleInfo* pkInfo = &pkData->GetParticleInfo()[i];
                NiPoint3 kPt = pkData->GetVertices()[i];
                NiPoint3 kDiff = kPt - kPos.m_kTranslation;

                float fDist = kDiff.Length();

                if (!m_bEnableMaxDistance || fDist <= m_fDistanceLimit)
                {
                    NiPoint3 kRandom;
                    kRandom.x = (float)((rand() * 2.0 / 32767.0) - 1.0);
                    kRandom.y = (float)((rand() * 2.0 / 32767.0) - 1.0);
                    kRandom.z = (float)((double)((double)((rand() * 2.0 / 32767.0) - 1.0)));

                    float fFactor = ReadScalar() / (1.0f + m_fFieldAttenuation * fDist);

                    kRandom *= fFactor;
                    pkInfo->m_kValue += kRandom;
                }
            }
        }
    }
}

extern double g_C273D0RandMax;

inline float C273D0SymmetricRandom()
{
    return (float)(rand() * 2.0 / g_C273D0RandMax - 1.0);
}

struct C273D0Point3
{
    float x;
    float y;
    float z;

    C273D0Point3()
    {}
    C273D0Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    C273D0Point3 operator*(float f) const
    {
        return C273D0Point3(x * f, y * f, z * f);
    }
    C273D0Point3& operator+=(const C273D0Point3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
};

struct C273D0ParticleInfo
{
    C273D0Point3 m_kValue;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct C273D0ParticleData
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
    unsigned short m_usNumParticles;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    C273D0ParticleInfo* m_pkParticleInfo;
};

struct C273D0Modifier
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_fInfluence;

    void ApplyRandomOffset(float fTime, C273D0ParticleData* pkData);
};

// Adds a random 3D offset scaled by m_fInfluence to each particle's m_kValue in pkData.
// @fnv 0x00c273d0
void C273D0Modifier::ApplyRandomOffset(float fTime, C273D0ParticleData* pkData)
{
    for (unsigned short us = 0; us < pkData->m_usNumParticles; us++)
    {
        C273D0ParticleInfo* pkInfo = &pkData->m_pkParticleInfo[us];
        C273D0Point3 kWorldPosition;
        kWorldPosition.x = C273D0SymmetricRandom();
        kWorldPosition.y = C273D0SymmetricRandom();
        kWorldPosition.z = C273D0SymmetricRandom();
        pkInfo->m_kValue += kWorldPosition * m_fInfluence;
    }
}

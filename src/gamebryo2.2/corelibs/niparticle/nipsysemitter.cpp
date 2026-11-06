// gamebryo2.2/corelibs/niparticle/nipsysemitter.cpp: NiPSysEmitter, Emitter (9 functions)

#include "nipsysemitter_decls.h"
#include "nipsysemitter_types.h"
// @fnv 0x00c223b0
void NiPSysEmitter::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    ReadFloat(stream, m_fEmissionSpeed);
    ReadFloat(stream, m_fSpeedVariation);
    ReadFloat(stream, m_fEmissionDeclination);
    ReadFloat(stream, m_fDeclinationVariation);
    ReadFloat(stream, m_fEmissionPlanarAngle);
    ReadFloat(stream, m_fPlanarAngleVariation);
    m_kParticleColor.LoadBinary(stream);
    ReadFloat(stream, m_fEmissionRadius);
    if (stream.m_uiNifVersion >= 0x0A030002)
        ReadFloat(stream, m_fRadiusVariation);
    ReadFloat(stream, m_fYValue);
    ReadFloat(stream, m_fLifeSpanVariation);
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);

struct FUN_00c220a0_shell
{
    void* __thiscall FUN_00c220a0(unsigned int flags);
};

// @fnv 0x00c220a0
void* __thiscall FUN_00c220a0_shell::FUN_00c220a0(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x54);
    return this;
}

struct FUN_00c21fd0_shell : public NiPSysEmitter
{
    void* GetRTTI();
};

extern char const* const g_01202500_arg1;

// @fnv 0x00c21fd0
void* __thiscall FUN_00c21fd0_shell::GetRTTI()
{
    return (void*)&g_01202500_arg1;
}

struct StrArr
{
    void* m_pPadding[2];
    unsigned short m_usCapacity;
    unsigned short m_usElementCount;
    unsigned short m_usUnknown;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct Base00c319e0
{
    void FUN_00c319e0(StrArr*);
};

struct FUN_00a69720_shell
{
    char* ToString(char const*);
};

char* __cdecl _FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d550(char const*, float);

extern char const str_01044b18[];
extern char const str_010bdf30[];
extern char const str_010bdf44[];
extern char const str_010bdf50[];
extern char const str_010bdf64[];
extern char const str_010bdf74[];
extern char const str_010bdf84[];
extern char const str_010bdf9c[];
extern char const str_010bdfac[];
extern char const str_010bdfc4[];
extern char const str_010bdfd0[];

struct FUN_00c22780_shell : public Base00c319e0
{
    void GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00c22780
void FUN_00c22780_shell::GetViewerStrings(StrArr* pkStrings)
{
    char* pString;
    unsigned int index;

    Base00c319e0::FUN_00c319e0(pkStrings);

    pString = _FUN_00a7d330(g_01202500_arg1);
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_01044b18, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x18));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdfd0, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdfc4, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x20));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdfac, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf9c, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x28));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf84, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2c));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = reinterpret_cast<FUN_00a69720_shell*>(reinterpret_cast<char*>(this) + 0x30)->ToString(str_010bdf74);
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf64, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x40));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf50, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x44));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf44, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x48));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = FUN_00a7d550(str_010bdf30, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x4c));
    index = pkStrings->m_usElementCount;
    if (index >= pkStrings->m_usCapacity)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);
}

// Equals: thiscall bool compare of two objects (float fields + sub-object)

class FUN_00c226a0_sub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    bool unk4a4c90(FUN_00c226a0_sub* other);
};

class FUN_00c226a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00c226a0_sub m_30;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    bool unk00c31830(FUN_00c226a0_cls* other);
    bool Equals(FUN_00c226a0_cls* other);
};

// @fnv 0x00c226a0
bool FUN_00c226a0_cls::Equals(FUN_00c226a0_cls* other)
{
    if (unk00c31830(other) && other->m_18 == m_18 && other->m_1c == m_1c && other->m_20 == m_20 &&
        other->m_24 == m_24 && other->m_28 == m_28 && other->m_2c == m_2c && !other->m_30.unk4a4c90(&m_30) &&
        other->m_40 == m_40 && other->m_44 == m_44 && other->m_48 == m_48 && other->m_4c == m_4c)
        return true;
    return false;
}

// @fnv 0x00d070a0
void __stdcall FUN_00d070a0(int, int)
{}

extern int __cdecl FUN_00ecadb8();
extern unsigned short DAT_010be248;
extern float DAT_011aeae8;
extern float DAT_011f4ae0[];
extern float DAT_011f52e0[];
inline float RandomFloat0To1()
{
    return (float)(FUN_00ecadb8() / 32767.0);
}
inline float NiSymmetricRandom()
{
    return (float)(2.0 * FUN_00ecadb8() / 32767.0 - 1.0);
}
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator*(float fScalar) const
    {
        NiPoint3 kResult;
        kResult.x = x * fScalar;
        kResult.y = y * fScalar;
        kResult.z = z * fScalar;
        return kResult;
    }
};
struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFlags;
    unsigned short m_usFirstValue;
};
class NiPSysData
{
  public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual unsigned short GetParticleVertexCount();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPoint3* m_pkVertex;
    unsigned int unk24;
    RgbaColor* m_pkColor;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    float* m_pfRadii;
    unsigned int unk50;
    float* m_pfSizes;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char* m_pucTexIndex;
    unsigned int unk68;
    unsigned char m_ucTexCount;
    unsigned char unk6d;
    unsigned short unk6e;
    Point3ParameterData* m_pkParticleInfo;
};
class NiParticleSystem
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    NiPSysData* m_spGeometryData;
    void FUN_00c1aee0(unsigned short usParticle);
};
class Emitter : public NiPSysEmitter
{
  public:
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void GetPositionAndDirection(NiPoint3& kPosition, NiPoint3& kMotionVelocity);
    void EmitParticles(float fTime, unsigned short usNumParticles, const float* afAges);
};
inline float NiFastSin(float fAngleDifference)
{
    return DAT_011f52e0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
inline float NiFastCos(float fAngleDifference)
{
    return DAT_011f4ae0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
// @fnv 0x00c220c0
void Emitter::EmitParticles(float fTime, unsigned short usNumParticles, const float* afAges)
{
    NiPSysData* pkData = m_pkTarget->m_spGeometryData;
    NiPoint3* pkVertex = pkData->m_pkVertex;
    RgbaColor* pkColor = pkData->m_pkColor;
    float* pfRadii = pkData->m_pfRadii;
    float* pfSizes = pkData->m_pfSizes;
    unsigned char* pucTex = pkData->m_pucTexIndex;
    unsigned char ucTexCount = pkData->m_ucTexCount;
    for (unsigned short us = 0; us < usNumParticles; us++)
    {
        float m_fFirstFloatValue = afAges[us];
        float fLifeSpan = m_fYValue + (RandomFloat0To1() - 0.5) * m_fLifeSpanVariation;
        if (m_fFirstFloatValue > fLifeSpan)
            continue;
        unsigned short usNew = pkData->GetParticleVertexCount();
        if (usNew == DAT_010be248)
            break;
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[usNew];
        float fSpeed = m_fEmissionSpeed + (RandomFloat0To1() - 0.5) * m_fSpeedVariation;
        float fDec = m_fEmissionDeclination + m_fDeclinationVariation * NiSymmetricRandom();
        float fPlanar = m_fEmissionPlanarAngle + m_fPlanarAngleVariation * NiSymmetricRandom();
        float fSinDec = NiFastSin(fDec);
        NiPoint3 kWorldPosition(NiFastCos(fPlanar) * fSinDec, fSinDec * NiFastSin(fPlanar), NiFastCos(fDec));
        pkInfo->m_kValue = kWorldPosition * fSpeed;
        pkInfo->m_fXValue = m_fFirstFloatValue;
        pkInfo->m_fYValue = fLifeSpan;
        pkInfo->m_usFlags = 0;
        GetPositionAndDirection(pkVertex[usNew], pkInfo->m_kValue);
        if (pkColor)
            pkColor[usNew] = m_kParticleColor;
        if (pfRadii)
            pfRadii[usNew] = (m_fEmissionRadius + m_fRadiusVariation * NiSymmetricRandom()) * m_fScale;
        if (pfSizes)
            pfSizes[usNew] = 1.0f;
        if (pucTex)
            pucTex[usNew] = FUN_00ecadb8() % ucTexCount;
        pkInfo->m_fZValue = fTime - pkInfo->m_fXValue;
        m_pkTarget->FUN_00c1aee0(usNew);
    }
}

char* __cdecl FUN_00a5b690(const char* pcString);

extern char* g_pcC21FE0NullString;

class BC21FE0FixedString
{
  public:
    BC21FE0FixedString(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = g_pcC21FE0NullString;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }

    ~BC21FE0FixedString()
    {
        if (m_kHandle != g_pcC21FE0NullString)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }

    char* m_kHandle;
};

class BC21FE0Color
{
  public:
    float r;
    float g;
    float b;
    float a;
};

class BC21FE0Modifier
{
  public:
    BC21FE0Modifier(const BC21FE0FixedString& kName, unsigned int uiOrder) throw();
    virtual ~BC21FE0Modifier();

    int unk04;
    char* m_kName;
    unsigned int m_uiUpdateOrder;
    void* m_pkTarget;
    bool m_bModifierActive;
};

class FUN_00c21fe0_cls : public BC21FE0Modifier
{
  public:
    FUN_00c21fe0_cls(const char* pcName, unsigned int uiOrder, float fSpeed, float fSpeedVar, float fDeclination,
                     float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar, BC21FE0Color kInitialColor,
                     float fInitialRadius, float fLifeSpan, float fLifeSpanVar, float fRadiusVar) throw();
    virtual ~FUN_00c21fe0_cls();

    float m_fEmissionSpeed;
    float m_fSpeedVariation;
    float m_fEmissionDeclination;
    float m_fDeclinationVariation;
    float m_fEmissionPlanarAngle;
    float m_fPlanarAngleVariation;
    BC21FE0Color m_kParticleColor;
    float m_fEmissionRadius;
    float m_fRadiusVariation;
    float m_fYValue;
    float m_fLifeSpanVariation;
    float m_fScale;
};

// Constructs a particle emitter modifier, storing emission speed, declination, planar angle, color, radius, life span and their variations.
// @fnv 0x00c21fe0
FUN_00c21fe0_cls::FUN_00c21fe0_cls(const char* pcName, unsigned int uiOrder, float fEmissionSpeed, float fSpeedVar,
                                   float fDeclination, float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar,
                                   BC21FE0Color kInitialColor, float fInitialRadius, float fLifeSpan,
                                   float fLifeSpanVar, float fRadiusVar) throw()
    : BC21FE0Modifier(pcName, uiOrder), m_fEmissionSpeed(fEmissionSpeed), m_fSpeedVariation(fSpeedVar),
      m_fEmissionDeclination(fDeclination), m_fDeclinationVariation(fDeclinationVar),
      m_fEmissionPlanarAngle(fPlanarAngle), m_fPlanarAngleVariation(fPlanarAngleVar), m_kParticleColor(kInitialColor),
      m_fEmissionRadius(fInitialRadius), m_fRadiusVariation(fRadiusVar), m_fYValue(fLifeSpan),
      m_fLifeSpanVariation(fLifeSpanVar), m_fScale(1.0f)
{}

struct EmitterColorWriter
{
    void FUN_00a698a0(NiStream& stream);
};
struct S_00c22530_BinaryStream : NiBinaryStream
{
    unsigned int(__cdecl* m_readElement)(S_00c22530_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct S_00c22530_Stream : NiStream
{
    S_00c22530_BinaryStream* m_pStreamReader;
};
inline void S_00c22530_BinaryRead(S_00c22530_BinaryStream* b, void* p)
{
    unsigned int size = 4;
    unsigned int got = b->m_readElement(b, p, 4, &size, 1);
    b->m_uiStreamFlags += got;
}
inline void S_00c22530_ReadFloat(S_00c22530_Stream& s, float& f)
{
    S_00c22530_BinaryRead(s.m_pStreamReader, &f);
}
struct S_00c22530_Emitter : NiPSysEmitter
{
    void FUN_00c31950(NiStream& stream);
    void FUN_00c22530(S_00c22530_Stream& stream);
};
// Calls FUN_00c31950, then reads emitter fields and particle color from the stream.
// @fnv 0x00c22530
void S_00c22530_Emitter::FUN_00c22530(S_00c22530_Stream& stream)
{
    FUN_00c31950(stream);
    S_00c22530_ReadFloat(stream, m_fEmissionSpeed);
    S_00c22530_ReadFloat(stream, m_fSpeedVariation);
    S_00c22530_ReadFloat(stream, m_fEmissionDeclination);
    S_00c22530_ReadFloat(stream, m_fDeclinationVariation);
    S_00c22530_ReadFloat(stream, m_fEmissionPlanarAngle);
    S_00c22530_ReadFloat(stream, m_fPlanarAngleVariation);
    reinterpret_cast<EmitterColorWriter*>(&m_kParticleColor)->FUN_00a698a0(stream);
    S_00c22530_ReadFloat(stream, m_fEmissionRadius);
    S_00c22530_ReadFloat(stream, m_fRadiusVariation);
    S_00c22530_ReadFloat(stream, m_fYValue);
    S_00c22530_ReadFloat(stream, m_fLifeSpanVariation);
}

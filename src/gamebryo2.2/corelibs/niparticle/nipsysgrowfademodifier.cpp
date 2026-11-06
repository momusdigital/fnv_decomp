// gamebryo2.2/corelibs/niparticle/nipsysgrowfademodifier.cpp: NiPSysGrowFadeModifier (8 functions)

#include "nipsysgrowfademodifier_decls.h"
// Loads the modifier's base data, then four fields and, for stream version above 16, one more field from the stream.
// @fnv 0x00c2a530
void NiPSysGrowFadeModifier::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_fGrowthTime);
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_usGrowGenerationLimit);
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_fFadeDuration);
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_usFadeGenerationLimit);
    if (stream.version > 16)
        NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &m_fInitialScale);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012026f8;

// @fnv 0x00c2a360
GlobalObjectO2_00a7b610* __cdecl FUN_00c2a360()
{
    return &g_012026f8;
}

void __cdecl FUN_00c31750();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00c2a370_shell : NiPSysGrowFadeModifier
{
    FUN_00c2a370_shell* FUN_00c2a370(unsigned int flags);
};
// Calls FUN_00c31750, then deletes this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c2a370
FUN_00c2a370_shell* FUN_00c2a370_shell::FUN_00c2a370(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

struct NiObject
{
    bool IsEqual(NiObject*) const;
};

struct FUN_00c2a2f0_shell : NiPSysGrowFadeModifier
{
    bool FUN_00c2a2f0(NiObject* pkObject);
};

// @fnv 0x00c2a2f0
bool FUN_00c2a2f0_shell::FUN_00c2a2f0(NiObject* pkObject)
{
    FUN_00c2a2f0_shell* pkDest = (FUN_00c2a2f0_shell*)pkObject;
    if (((NiObject*)this)->IsEqual(pkObject) && m_fGrowthTime == pkDest->m_fGrowthTime &&
        m_usGrowGenerationLimit == pkDest->m_usGrowGenerationLimit && m_fFadeDuration == pkDest->m_fFadeDuration &&
        m_fInitialScale == pkDest->m_fInitialScale && m_usFadeGenerationLimit == pkDest->m_usFadeGenerationLimit)
        return true;
    return false;
}

extern float DAT_010c09c0;

struct ParticleInfo_00c2a390
{
    float unk00;
    float unk04;
    float unk08;
    float age;
    float lifeSpan;
    unsigned int unk14;
    unsigned short generation;
    unsigned short unk1a;
};
struct ParticleData_00c2a390
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    unsigned short activeCount;
    unsigned short maxCount;
    float* scales;
    unsigned int unk58, unk5c, unk60, unk64, unk68, unk6c;
    ParticleInfo_00c2a390* particles;
};
struct FUN_00c2a390_shell : NiPSysGrowFadeModifier
{
    void ComputeParticleScales(unsigned int, ParticleData_00c2a390*);
};

// For each active particle, computes a fade/grow ratio from age and lifespan and writes the clamped scale into data->scales.
// @fnv 0x00c2a390
void FUN_00c2a390_shell::ComputeParticleScales(unsigned int, ParticleData_00c2a390* data)
{
    float scaleRange = 1.0f - m_fInitialScale;
    for (unsigned short i = 0; i < data->activeCount; ++i)
    {
        const ParticleInfo_00c2a390& particle = data->particles[i];
        float fade = 1.0f;
        if (particle.generation == m_usGrowGenerationLimit && particle.age < m_fGrowthTime && m_fGrowthTime != 0.0f)
        {
            fade = particle.age / m_fGrowthTime;
        }

        float grow = 1.0f;
        float remaining = particle.lifeSpan - particle.age;
        if (particle.generation == m_usFadeGenerationLimit && remaining < m_fFadeDuration && m_fFadeDuration != 0.0f)
        {
            grow = remaining / m_fFadeDuration;
        }
        float ratio = grow > fade ? fade : grow;
        float scale = ratio * scaleRange + m_fInitialScale;
        if (scale < DAT_010c09c0)
        {
            scale = DAT_010c09c0;
        }
        data->scales[i] = scale;
    }
}

struct GrowFadeBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(GrowFadeBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct GrowFadeStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    GrowFadeBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysModifierStand
{
    void* vtable;
    char unk04[0x14];
    void LoadStream(NiStream& stream);
};

struct FUN_00c2a610_cls : NiPSysGrowFadeModifier
{
    void LoadGrowFadeModifier(NiStream& stream);
};

// Loads the base modifier stream, then reads five values from the stream into the grow/fade modifier's fields.
// @fnv 0x00c2a610
void FUN_00c2a610_cls::LoadGrowFadeModifier(NiStream& stream)
{
    reinterpret_cast<NiPSysModifierStand*>(this)->LoadStream(stream);
    GrowFadeStreamView* pStreamView = reinterpret_cast<GrowFadeStreamView*>(&stream);
    pStreamView->m_pUnderlyingStream->Load(&m_fGrowthTime);
    pStreamView->m_pUnderlyingStream->Load(&m_usGrowGenerationLimit);
    pStreamView->m_pUnderlyingStream->Load(&m_fFadeDuration);
    pStreamView->m_pUnderlyingStream->Load(&m_usFadeGenerationLimit);
    pStreamView->m_pUnderlyingStream->Load(&m_fInitialScale);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012026f8;
char* __cdecl FUN_00a7d330(char* pcText);
char* __cdecl FUN_00a7d550(const char* pcName, float fValue);
char* __cdecl FUN_00a7d490(const char* pcName, unsigned short usValue);
struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};
struct Base00c319e0
{
    void FUN_00c319e0(StrArr* pkStrings);
};
struct FUN_00c2a6e0_shell : NiPSysGrowFadeModifier
{
    void AppendGrowFadeModifierStrings(StrArr* pkStrings);
};
// @fnv 0x00c2a6e0
void FUN_00c2a6e0_shell::AppendGrowFadeModifierStrings(StrArr* pkStrings)
{
    ((Base00c319e0*)this)->FUN_00c319e0(pkStrings);
    char* pcString = FUN_00a7d330(*(char**)&g_012026f8);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d550("Grow Time", m_fGrowthTime);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d490("Grow Generation", m_usGrowGenerationLimit);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d550("Fade Time", m_fFadeDuration);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d490("Fade Generation", m_usFadeGenerationLimit);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d550("Base Scale", m_fInitialScale);
    pkStrings->Add(pcString);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
struct A4b0Clone;
class FUN_00c31720
{
  public:
    virtual void v00();
    int m_04, m_08, m_0c, m_10, m_14;
    FUN_00c31720();
    void __thiscall FUN_00c31780(FUN_00c31720* dest, A4b0Clone* cloning);
};
class A4b0Cls : public FUN_00c31720
{
  public:
    virtual void v00();
    float m_18;
    short m_1c;
    float m_20;
    short m_24;
    float m_28;
    A4b0Cls()
    {
        m_18 = 0.0f;
        m_1c = 0;
        m_20 = 0.0f;
        m_24 = 0;
        m_28 = 0.0f;
    }
    FUN_00c31720* __thiscall CreateClone(A4b0Clone* cloning);
};
// Allocates an A4b0Cls, copies the base via FUN_00c31780, then copies m_18, m_1c, m_20, m_24 and m_28 from this object and returns it.
// @fnv 0x00c2a4b0
FUN_00c31720* A4b0Cls::CreateClone(A4b0Clone* cloning)
{
    void* mem = FUN_00aa13e0(sizeof(A4b0Cls));
    A4b0Cls* p = mem ? new (mem) A4b0Cls : 0;
    FUN_00c31780(p, cloning);
    p->m_18 = m_18;
    p->m_1c = m_1c;
    p->m_20 = m_20;
    p->m_24 = m_24;
    p->m_28 = m_28;
    return p;
}

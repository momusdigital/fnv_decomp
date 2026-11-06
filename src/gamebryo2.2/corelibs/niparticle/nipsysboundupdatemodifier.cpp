
// src/gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiParticleSystem;
struct NiPSysModifier_shell
{
    void FUN_00c31640(NiParticleSystem*);
    void FUN_00c2dc70(NiParticleSystem* system);
};
// Clears the flag at offset 0xd9 on the previously attached system, sets it on the new system, then calls FUN_00c31640.
// @fnv 0x00c2dc70
void NiPSysModifier_shell::FUN_00c2dc70(NiParticleSystem* system)
{
    NiParticleSystem* pOldSystem = *(NiParticleSystem**)((char*)this + 0x10);
    if (pOldSystem)
        ((char*)pOldSystem)[0xd9] = 0;
    if (system)
        ((char*)system)[0xd9] = 1;
    FUN_00c31640(system);
}

struct MM
{
    void _DeallocateAlias(void* p);
};
extern MM g_memoryManager;
extern int DAT_010c0134;
void __cdecl _delete(void* p, unsigned int s);
struct NiPSysBoundUpdateModifier
{
    void* _vptr;
    char _pad[0x18];
    void* m_pkBounds;
    void FUN_00c31750();
    void* Destroy(unsigned int);
};
// Restores the vtable, frees the stored pointer via the memory manager, calls FUN_00c31750, and optionally deletes this with size 0x20.
// @fnv 0x00c2dca0
void* NiPSysBoundUpdateModifier::Destroy(unsigned int auiFlags)
{
    void* p = m_pkBounds;
    *(void**)this = (void*)&DAT_010c0134;
    g_memoryManager._DeallocateAlias(p);
    FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x20);
    return this;
}

namespace fnv_00c2dec0 {
extern int DAT_010c0134;
struct CloningProcess
{
};
struct NiObject
{
};
struct BSFadeNode
{
    char _pad[0x18];
    static void* __cdecl operator new(unsigned int);
};
struct NiPSysModifier : BSFadeNode
{
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
};
struct NiPSysPositionModifier : NiPSysModifier
{
    NiPSysPositionModifier() throw();
};
struct NiPSysBoundUpdateModifier : NiPSysPositionModifier
{
    unsigned short m_usUpdateSkip;
    unsigned short m_usUpdateSkipCounter;
    void* m_pkBounds;
    NiPSysBoundUpdateModifier() throw();
    void SetUpdateSkipCounter(int);
    NiObject* CreateClone(CloningProcess&);
};
inline NiPSysBoundUpdateModifier::NiPSysBoundUpdateModifier() throw()
{
    *(void**)this = (void*)&DAT_010c0134;
    m_usUpdateSkip = 0;
    m_usUpdateSkipCounter = 0;
    m_pkBounds = 0;
}
// @fnv 0x00c2dec0
NiObject* NiPSysBoundUpdateModifier::CreateClone(CloningProcess& kCloning)
{
    NiPSysBoundUpdateModifier* pkObject = new NiPSysBoundUpdateModifier;
    CopyMemberData(pkObject, kCloning);
    pkObject->SetUpdateSkipCounter(m_usUpdateSkip);
    return (NiObject*)pkObject;
}
}  // namespace fnv_00c2dec0

namespace fnv_00c2e3f0 {
struct NiBinaryStream
{
    int _0;
    int position;
    int (*read)(NiBinaryStream*, void*, int, unsigned int*, int);
    int (*write)(NiBinaryStream*, void*, int, unsigned int*, int);
};
struct NiStream
{
    char _pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct NiPSysModifier
{
    char _b[0x18];
    void FUN_00c31950(NiStream&);
};
struct NiPSysBoundUpdateModifier : NiPSysModifier
{
    short m_s;
    void SaveBinary(NiStream&);
};
// @fnv 0x00c2e3f0
void NiPSysBoundUpdateModifier::SaveBinary(NiStream& stream)
{
    FUN_00c31950(stream);
    NiBinaryStream* __restrict out = stream.m_pBackingStream;
    unsigned int size = 2;
    out->position += out->write(out, &m_s, 2, &size, 1);
}
}  // namespace fnv_00c2e3f0

class BC2E370BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC2E370BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BC2E370Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BC2E370BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void BC2E370BinaryStreamLoad(BC2E370BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC2E370LoadBinary(BC2E370Stream& kStream, T& value)
{
    BC2E370BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class BC2E370Modifier
{
  public:
    virtual void LoadBinary(BC2E370Stream& kStream);
};

class BC2E370Emitter : public BC2E370Modifier
{
  public:
    virtual void LoadBinary(BC2E370Stream& kStream);
    void FUN_00c2e370(BC2E370Stream& kStream);
    void SetFlags(unsigned short usFlags);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
};

// Loads the modifier base data, then reads the flags (or a local usFlags on older file versions) and applies them via SetFlags.
// @fnv 0x00c2e370
void BC2E370Emitter::FUN_00c2e370(BC2E370Stream& kStream)
{
    BC2E370Modifier::LoadBinary(kStream);
    if (kStream.m_uiFileVersion <= 0x0A010064)
    {
        unsigned short usFlags;
        BC2E370LoadBinary(kStream, usFlags);
        SetFlags(usFlags);
    }
    else
    {
        BC2E370LoadBinary(kStream, m_usFlags);
        SetFlags(m_usFlags);
    }
}

extern "C" void* g_01202788;
struct NiStream;

struct NiStrTable
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, char*& v);
    void Add(char* v)
    {
        unsigned int n = unk0A;
        if (n >= unk08)
        {
            SetSize(n + unk0E);
        }
        SetAt(n, v);
    }
};

struct StrArr;
struct Base00c319e0
{
    void FUN_00c319e0(StrArr* arr);
};

extern "C" char* __cdecl FUN_00a7d330(char* s);
extern "C" char* __cdecl FUN_00a7d450(const char* key, unsigned short value);

struct FUN_00c2e430_shell : Base00c319e0, NiPSysBoundUpdateModifier
{
    void GetViewerStrings(NiStream& stream);
};

// @fnv 0x00c2e430
void FUN_00c2e430_shell::GetViewerStrings(NiStream& stream)
{
    Base00c319e0::FUN_00c319e0(reinterpret_cast<StrArr*>(&stream));
    reinterpret_cast<NiStrTable&>(stream).Add(FUN_00a7d330((char*)g_01202788));
    reinterpret_cast<NiStrTable&>(stream).Add(FUN_00a7d450("Update Skip", *(unsigned short*)((char*)this + 0x18)));
}

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    static const NiPoint3 ZERO;
};

class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    void Merge(const NiBound* pkBound);
};

extern NiBound DAT_011f4288;

struct Particle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pkBound;
};

struct BoundDataBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pkBound;
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
    Particle** m_pkParticles;
};

struct NiParticleSystem
{
    int unk00;
    int unk04;
    unsigned short m_usMaxNumParticles;
    short pad0A;
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
    float* m_pfRadius;
    unsigned short m_usNumParticles;
    short pad52;
    float* m_pfSize;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    BoundDataBlock* m_pUserData;
};

struct ModifierHost
{
    void* _vptr;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    short m_usUpdateSkip;
    unsigned short m_usCurrentBound;
    NiBound* m_pkBounds;

    void FUN_00c2d720(short count);
    void FUN_00c2dce0(float fTime, NiParticleSystem* pkTarget);
};

// Merges particle bounds into the current bound slot, resets the remaining slots, and advances m_usCurrentBound cyclically.
// @fnv 0x00c2dce0
void ModifierHost::FUN_00c2dce0(float fTime, NiParticleSystem* pkTarget)
{
    unsigned short usNumParticles = pkTarget->m_usNumParticles;
    BoundDataBlock* pkData = pkTarget->m_pUserData;

    if (m_usUpdateSkip == -1)
    {
        FUN_00c2d720((short)(pkTarget->m_usMaxNumParticles / 20 + 1));
    }

    int iCount = usNumParticles;
    int iMaxUpdateSkip = iCount / 20 + 1;
    int iSkip = m_usUpdateSkip < iMaxUpdateSkip ? m_usUpdateSkip : iMaxUpdateSkip;
    if (iSkip <= 1)
    {
        iSkip = 1;
    }

    Particle* pFirstParticle = pkData->m_pkParticles[0];
    NiBound* pkFirstBound = pFirstParticle->m_pkBound ? pFirstParticle->m_pkBound : &DAT_011f4288;
    NiBound kBound = *pkFirstBound;
    for (int i = m_usCurrentBound; i < iCount; i += iSkip)
    {
        Particle* pkParticle = pkData->m_pkParticles[i];
        NiBound* pkParticleBound = pkParticle->m_pkBound;
        if (!pkParticleBound)
        {
            pkParticleBound = &DAT_011f4288;
        }
        kBound.Merge(pkParticleBound);
    }

    m_pkBounds[m_usCurrentBound].m_kCenter = kBound.m_kCenter;
    m_pkBounds[m_usCurrentBound].m_fBoundRadius = kBound.m_fBoundRadius;

    for (int i = iSkip; i < m_usUpdateSkip; ++i)
    {
        m_pkBounds[i].m_kCenter = NiPoint3::ZERO;
        m_pkBounds[i].m_fBoundRadius = 0.0f;
    }

    for (int i = 1; i < iSkip; ++i)
    {
        if (m_pkBounds[i].m_fBoundRadius != 0.0f)
        {
            kBound.Merge(&m_pkBounds[i]);
        }
    }

    if (kBound.m_fBoundRadius == 0.0f)
    {
        kBound.m_fBoundRadius = (*pkTarget->m_pfSize) * (*pkTarget->m_pfRadius);
    }
    float fRadius = kBound.m_fBoundRadius;
    NiBound* pkDest = pkData->m_pkBound;
    pkDest->m_kCenter = kBound.m_kCenter;
    pkDest->m_fBoundRadius = fRadius;
    m_usCurrentBound++;
    if ((int)m_usCurrentBound >= iSkip)
    {
        m_usCurrentBound = 0;
    }
}

template <class T> inline T kFirstBoundsPointEntry(const T& a, const T& b)
{
    return a < b ? a : b;
}
template <class T> inline T kBoundsMaximum(const T& a, const T& b)
{
    return a > b ? a : b;
}
extern "C" double __cdecl sqrt(double);
struct BoundPoint : NiPoint3
{
    BoundPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    BoundPoint operator*(float f) const
    {
        return BoundPoint(x * f, y * f, z * f);
    }
    float Length() const
    {
        float sq = x * x + y * y + z * z;
        return (float)sqrt(sq);
    }
};
struct FUN_00c25db0_shell
{
    unsigned short FUN_00c25db0(unsigned short);
};
struct FUN_00c25e40_shell
{
    float FUN_00c25e40(unsigned short, unsigned short);
};
struct FUN_00c25e20_shell
{
    float GetInnerValue(unsigned short, unsigned short);
};
struct TESBoundObjectBounds
{
    int unk00, unk04;
    unsigned short capacity, unk0a;
    int unk0c;
    NiBound bound;
    NiPoint3* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float* radii;
    unsigned short count, unk52;
    float* sizes;
    NiPoint3* GetSlotData(unsigned short, unsigned short);
};
struct FUN_00c2d720_shell
{
    void FUN_00c2d720(short);
};
struct BoundUpdater
{
    void* vptr;
    int unk04, unk08, unk0c, unk10, unk14;
    short m_usUpdateSkip;
    unsigned short m_usCurrentBound;
    NiBound* m_pkBounds;
    void FUN_00c2d880(float, TESBoundObjectBounds*);
};
// Computes the bounding sphere for the current bound slot from position and radius data, merges it into the overall bound, and advances the current bound index.
// @fnv 0x00c2d880
void BoundUpdater::FUN_00c2d880(float time, TESBoundObjectBounds* apBounds)
{
    unsigned short count = apBounds->count;
    if (m_usUpdateSkip == -1)
        ((FUN_00c2d720_shell*)this)->FUN_00c2d720(apBounds->capacity / 10 + 1);
    int stride = kFirstBoundsPointEntry((int)m_usUpdateSkip, count / 10 + 1);
    stride = kBoundsMaximum(stride, 1);
    float lx = apBounds->positions[0].x;
    float ly = apBounds->positions[0].y;
    float fMinZ = apBounds->positions[0].z;
    float hx = lx;
    float hy = ly;
    float fMaxZ = fMinZ;
    for (int i = m_usCurrentBound; i < count; i += stride)
    {
        unsigned short n = ((FUN_00c25db0_shell*)apBounds)->FUN_00c25db0((unsigned short)i);
        for (unsigned short j = 0; j < n; ++j)
        {
            NiPoint3* p = apBounds->GetSlotData((unsigned short)i, j);
            float r = ((FUN_00c25e40_shell*)apBounds)->FUN_00c25e40((unsigned short)i, j) *
                      ((FUN_00c25e20_shell*)apBounds)->GetInnerValue((unsigned short)i, j);
            double fTemp;
            fTemp = p->x - r;
            lx = kFirstBoundsPointEntry(lx, (float)fTemp);
            fTemp = p->x + r;
            hx = kBoundsMaximum(hx, (float)fTemp);
            fTemp = p->y - r;
            ly = kFirstBoundsPointEntry(ly, (float)fTemp);
            fTemp = p->y + r;
            hy = kBoundsMaximum(hy, (float)fTemp);
            fTemp = p->z - r;
            fMinZ = kFirstBoundsPointEntry(fMinZ, (float)fTemp);
            fTemp = p->z + r;
            fMaxZ = kBoundsMaximum(fMaxZ, (float)fTemp);
        }
    }
    m_pkBounds[m_usCurrentBound].m_kCenter = BoundPoint(hx + lx, hy + ly, fMaxZ + fMinZ) * 0.5f;
    float rad = BoundPoint(hx - lx, hy - ly, fMaxZ - fMinZ).Length() * 0.5;
    m_pkBounds[m_usCurrentBound].m_fBoundRadius = rad;
    for (int k = stride; k < m_usUpdateSkip; ++k)
    {
        m_pkBounds[k].m_kCenter = NiPoint3::ZERO;
        m_pkBounds[k].m_fBoundRadius = 0;
    }
    NiBound kMergedBound;
    kMergedBound.m_kCenter = m_pkBounds[m_usCurrentBound].m_kCenter;
    kMergedBound.m_fBoundRadius = m_pkBounds[m_usCurrentBound].m_fBoundRadius;
    for (int k = 1; k < stride; ++k)
        if (m_pkBounds[k].m_fBoundRadius != 0)
            kMergedBound.Merge(&m_pkBounds[k]);
    apBounds->bound.m_kCenter = kMergedBound.m_kCenter;
    apBounds->bound.m_fBoundRadius = kMergedBound.m_fBoundRadius;
    if (apBounds->bound.m_fBoundRadius == 0)
        apBounds->bound.m_fBoundRadius = apBounds->sizes[0] * apBounds->radii[0];
    ++m_usCurrentBound;
    if (m_usCurrentBound >= stride)
        m_usCurrentBound = 0;
}

struct LocalPoint3
{
    float x;
    float y;
    float z;
    LocalPoint3 operator+(const LocalPoint3& p) const
    {
        return LocalPoint3(x + p.x, y + p.y, z + p.z);
    }
    LocalPoint3 operator-(const LocalPoint3& p) const
    {
        return LocalPoint3(x - p.x, y - p.y, z - p.z);
    }
    LocalPoint3()
    {}
    LocalPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    LocalPoint3 operator*(double d) const
    {
        return LocalPoint3((float)(x * d), (float)(y * d), (float)(z * d));
    }
};
extern LocalPoint3 NiPoint3_ZERO;
struct LocalBound
{
    LocalPoint3 m_kCenter;
    float m_fBoundRadius;
    void Merge(const LocalBound* pkOther);
};
class GlobalObjectO2_00a7b610
{
  public:
    const char* m_pcName;
    const GlobalObjectO2_00a7b610* m_pBaseRTTI;
};
extern GlobalObjectO2_00a7b610 g_012027c0;
extern GlobalObjectO2_00a7b610 g_01202680;
struct NiPSysData
{
    virtual void v0();
    virtual void v1();
    virtual const GlobalObjectO2_00a7b610* GetRTTI() const;
    bool IsKindOfType(const GlobalObjectO2_00a7b610* pkRTTI) const
    {
        const GlobalObjectO2_00a7b610* pkIter = GetRTTI();
        while (pkIter)
        {
            if (pkIter == pkRTTI)
                return true;
            pkIter = pkIter->m_pBaseRTTI;
        }
        return false;
    }
    int unk04;
    unsigned short m_usMaxNumParticles;
    short unk0a;
    int unk0c;
    LocalBound m_kBound;
    LocalPoint3* m_pkPositions;
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
    float* m_pfRadii;
    unsigned short m_usNumParticles;
    short unk52;
    float* m_pfSizes;
};
extern "C" double __cdecl sqrt(double);
struct BoundUpdateModifier
{
    void* m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    short m_usUpdateSkip;
    unsigned short m_usCurrentSample;
    LocalBound* m_pkBounds;
    void UpdateBounds(float fTime, NiPSysData* pkData);
    void FUN_00c2d720(int iCount);
    void FUN_00c2dce0(float fTime, NiPSysData* pkData);
    void FUN_00c2d880(float fTime, NiPSysData* pkData);
};
// Computes the particle system's bounding sphere from sampled positions and radii, merging previous samples and storing the result in pkData->m_kBound.
// @fnv 0x00c2df20
void BoundUpdateModifier::UpdateBounds(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticles = pkData->m_usNumParticles;
    if (usNumParticles <= 0)
    {
        pkData->m_kBound.m_kCenter = NiPoint3_ZERO;
        pkData->m_kBound.m_fBoundRadius = 0.0f;
        m_usCurrentSample = 0;
        return;
    }
    if (pkData->IsKindOfType(&g_012027c0))
    {
        FUN_00c2dce0(fTime, pkData);
        return;
    }
    if (pkData->IsKindOfType(&g_01202680))
    {
        FUN_00c2d880(fTime, pkData);
        return;
    }
    if (m_usUpdateSkip == -1)
    {
        FUN_00c2d720(pkData->m_usMaxNumParticles / 50 + 1);
    }
    int pkPositions = usNumParticles / 50 + 1;
    int iStride = m_usUpdateSkip;
    if (iStride >= pkPositions)
        iStride = pkPositions;
    if (iStride <= 1)
        iStride = 1;
    LocalPoint3* j = pkData->m_pkPositions;
    float* pkPositionArray = (float*)j;
    float m_fGridOriginX = j[0].x;
    float kDiff = j[0].y;
    float fMinZ = j[0].z;
    float kPointArrayBench;
    kPointArrayBench = m_fGridOriginX;
    float m_fWorldTransformCoefficient4 = kDiff;
    float fMaxZ = fMinZ;
    float* pkBoundEntry = pkData->m_pfRadii;
    float* y = pkData->m_pfSizes;
    int i = m_usCurrentSample;
    int k = i * 3;
    if (i < usNumParticles)
    {
        for (; i < usNumParticles;)
        {
            float fRadius = y[i] * pkBoundEntry[i];
            float lo = pkPositionArray[k] - fRadius;
            if (!(lo > m_fGridOriginX))
                m_fGridOriginX = lo;
            float hi = pkPositionArray[k] + fRadius;
            if (!(kPointArrayBench > hi))
                kPointArrayBench = hi;
            lo = pkPositionArray[k + 1] - fRadius;
            if (!(lo > kDiff))
                kDiff = lo;
            hi = pkPositionArray[k + 1] + fRadius;
            if (!(m_fWorldTransformCoefficient4 > hi))
                m_fWorldTransformCoefficient4 = hi;
            lo = pkPositionArray[k + 2] - fRadius;
            if (!(fMinZ < lo))
                fMinZ = lo;
            hi = pkPositionArray[k + 2] + fRadius;
            if (!(fMaxZ > hi))
                fMaxZ = hi;
            k += iStride * 3;
            i += iStride;
        }
    }
    LocalPoint3 res =
        LocalPoint3(kPointArrayBench, m_fWorldTransformCoefficient4, fMaxZ) + LocalPoint3(m_fGridOriginX, kDiff, fMinZ);
    m_pkBounds[m_usCurrentSample].m_kCenter = res * 0.5;
    LocalPoint3 afWorldOriginY;
    afWorldOriginY =
        LocalPoint3(kPointArrayBench, m_fWorldTransformCoefficient4, fMaxZ) - LocalPoint3(m_fGridOriginX, kDiff, fMinZ);
    float fExtentSq =
        afWorldOriginY.x * afWorldOriginY.x + afWorldOriginY.y * afWorldOriginY.y + afWorldOriginY.z * afWorldOriginY.z;
    float fExtent = (float)sqrt(fExtentSq);
    float fRadius = (float)(fExtent * 0.5);
    m_pkBounds[m_usCurrentSample].m_fBoundRadius = fRadius;
    for (int k = iStride; k < m_usUpdateSkip; ++k)
    {
        m_pkBounds[k].m_kCenter = NiPoint3_ZERO;
        m_pkBounds[k].m_fBoundRadius = 0.0f;
    }
    LocalBound kBound;
    kBound.m_kCenter = m_pkBounds[m_usCurrentSample].m_kCenter;
    kBound.m_fBoundRadius = m_pkBounds[m_usCurrentSample].m_fBoundRadius;
    if (1 < iStride)
    {
        for (int pkPositions = 1; pkPositions < iStride; ++pkPositions)
        {
            if (m_pkBounds[pkPositions].m_fBoundRadius != 0.0f)
            {
                kBound.Merge(&m_pkBounds[pkPositions]);
            }
        }
    }
    pkData->m_kBound.m_fBoundRadius = kBound.m_fBoundRadius;
    pkData->m_kBound.m_kCenter = kBound.m_kCenter;
    if (kBound.m_fBoundRadius == 0.0f)
    {
        pkData->m_kBound.m_fBoundRadius = *(volatile float*)pkData->m_pfRadii * pkData->m_pfSizes[0];
    }
    if (++m_usCurrentSample >= iStride)
    {
        m_usCurrentSample = 0;
    }
}

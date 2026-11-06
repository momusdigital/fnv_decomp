
// src/gamebryo2.2/corelibs/niparticle/nipsysbombmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysbombmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiObject
{
};
struct CloningProcess;
struct NiTStringPointerMap_00e93020
{
    bool GetAt(void*, void*&);
};
struct CloningProcess
{
    NiTStringPointerMap_00e93020* m_pCloneMap;
};
struct NiPSysModifier
{
    virtual void ProcessClone(CloningProcess&);
};
struct NiPSysBombModifier : NiPSysModifier
{
    char _pad[20];
    NiObject* m_pkBombObject;
    void FUN_00c2e610(CloningProcess&);
};
// @fnv 0x00c2e610
void NiPSysBombModifier::FUN_00c2e610(CloningProcess& kCloning)
{
    bool bFound;
    NiObject* pkClone;
    NiPSysBombModifier* pkDest;
    NiPSysModifier::ProcessClone(kCloning);
    pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, (void*&)pkClone);
    pkDest = (NiPSysBombModifier*)pkClone;
    bFound = kCloning.m_pCloneMap->GetAt(m_pkBombObject, (void*&)pkClone);
    if (bFound)
        pkDest->m_pkBombObject = pkClone;
    else
        pkDest->m_pkBombObject = m_pkBombObject;
}

struct NiObjVt
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
    virtual bool IsEqual(NiObjVt* pkObject);
};

struct NiPoint3
{
    float x, y, z;
    bool operator!=(const NiPoint3& pt) const;
};

struct BombMod : NiPSysBombModifier
{
    NiPoint3 m_kBombDirection;
    float m_fDistanceDecay;
    float m_fDeltaVelocity;
    int m_eBombDecayType;
    int m_eSymmetryType;

    NiObjVt* Bomb()
    {
        return (NiObjVt*)m_pkBombObject;
    }
    bool FUN_00c31830(NiObject* pkObject);
    bool FUN_00c2eaf0(NiObject* pkObject);
};

// @fnv 0x00c2eaf0
bool BombMod::FUN_00c2eaf0(NiObject* pkObject)
{
    if (!FUN_00c31830(pkObject))
        return false;

    BombMod* pkDest = (BombMod*)pkObject;

    if ((m_pkBombObject && !pkDest->m_pkBombObject) || (!m_pkBombObject && pkDest->m_pkBombObject) ||
        (m_pkBombObject && pkDest->m_pkBombObject &&
         !((NiObjVt*)m_pkBombObject)->IsEqual((NiObjVt*)pkDest->m_pkBombObject)))
    {
        return false;
    }

    if (m_kBombDirection != pkDest->m_kBombDirection || m_fDistanceDecay != pkDest->m_fDistanceDecay ||
        m_fDeltaVelocity != pkDest->m_fDeltaVelocity || m_eBombDecayType != pkDest->m_eBombDecayType ||
        m_eSymmetryType != pkDest->m_eSymmetryType)
    {
        return false;
    }

    return true;
}

namespace fnv_00c2ed00 {
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610* g_01202790;
char* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610*);
char* __cdecl FUN_00a7d5e0(const char*, const char*);
char* __cdecl FUN_00a7d550(const char*, float);

struct StrArr
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);

    void Add(char* str)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, str);
    }
};

struct BombNamed
{
    void* m_vtbl;
    int unk04;
    const char* m_kName;
};

struct BombPoint3
{
    float x, y, z;
    char* FUN_00a59af0(const char*) const;
};

struct BombModBase
{
    virtual void vfunc00();
    char pad04[0x14];
    void FUN_00c319e0(StrArr*);
};

struct BombMod : BombModBase
{
    BombNamed* m_pkBombObject;
    BombPoint3 m_kBombDirection;
    float m_fDistanceDecay;
    float m_fDeltaVelocity;
    int m_eBombDecayType;
    int m_eSymmetryType;

    static const char* GetDecayTypeName(int e)
    {
        switch (e)
        {
        case 0:
            return "NONE";
        case 1:
            return "LINEAR";
        case 2:
            return "EXPONENTIAL";
        default:
            return "Unknown";
        }
    }
    static const char* GetSymmTypeName(int e)
    {
        switch (e)
        {
        case 0:
            return "SPHERICAL";
        case 1:
            return "CYLINDRICAL";
        case 2:
            return "PLANAR";
        default:
            return "Unknown";
        }
    }

    void AppendToStrings(StrArr* pkStrings);
};

// Appends the base strings plus the bomb object name, axis, decay, deltaV, decay type and symmetry type to pkStrings.
// @fnv 0x00c2ed00
void BombMod::AppendToStrings(StrArr* pkStrings)
{
    FUN_00c319e0(pkStrings);

    pkStrings->Add(FUN_00a7d330(g_01202790));
    pkStrings->Add(FUN_00a7d5e0("Bomb Object", m_pkBombObject ? m_pkBombObject->m_kName : "None"));
    pkStrings->Add(m_kBombDirection.FUN_00a59af0("Bomb Axis"));
    pkStrings->Add(FUN_00a7d550("Decay", m_fDistanceDecay));
    pkStrings->Add(FUN_00a7d550("DeltaV", m_fDeltaVelocity));
    pkStrings->Add(FUN_00a7d5e0("Decay Type", GetDecayTypeName(m_eBombDecayType)));
    pkStrings->Add(FUN_00a7d5e0("Symmetry Type", GetSymmTypeName(m_eSymmetryType)));
}
}  // namespace fnv_00c2ed00

struct BinaryInput
{
    unsigned int flags;
    unsigned int bytesRead;
    unsigned int(__cdecl* read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& value)
    {
        unsigned int size = 4;
        bytesRead += read(this, &value, 4, &size, 1);
    }
    template <class Enum> void ReadEnum(Enum& value)
    {
        unsigned int temp;
        unsigned int size = 4;
        bytesRead += read(this, &temp, 4, &size, 1);
        value = (Enum)temp;
    }
};
struct ParticleStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    BinaryInput* input;
    void FUN_00a645b0();
};
struct PointReader
{
    float x, y, z;
    void LoadBinary(ParticleStream&);
};
enum DecayType
{
};
enum SymmetryType
{
};
struct BombLoader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    PointReader axis;
    float decay;
    float delta;
    DecayType decayType;
    SymmetryType symmetryType;
    void FUN_00c318b0(ParticleStream&);
    void FUN_00c2eb80(ParticleStream& stream);
};
// Loads the base data, then reads axis, decay, delta, decayType and symmetryType from the stream's input.
// @fnv 0x00c2eb80
void BombLoader::FUN_00c2eb80(ParticleStream& stream)
{
    FUN_00c318b0(stream);
    stream.FUN_00a645b0();
    axis.LoadBinary(stream);
    stream.input->ReadFloat(decay);
    stream.input->ReadFloat(delta);
    stream.input->ReadEnum(decayType);
    stream.input->ReadEnum(symmetryType);
}

class C2EC40BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C2EC40BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C2EC40BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C2EC40Object;

class NiStreamC2E
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void SaveLinkID(void* pkObject);
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(C2EC40Object* pkObject);
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
    int unk0D8;
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
    int unk24C;
    C2EC40BinaryStream* m_pBackingStream;
};

template <class T>
inline void C2EC40BinaryStreamSave(C2EC40BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C2EC40SaveBinary(NiStreamC2E& kStream, const T& value)
{
    C2EC40BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class NiColorC2E
{
  public:
    void SaveBinary(NiStreamC2E& kStream);

    float r;
    float g;
    float b;
};

class NiPSysModifierC2E
{
  public:
    void SaveBinary(NiStreamC2E& kStream);

    int unk00, unk04, unk08, unk0C, unk10, unk14;
};

class NiPSysEmitterC2E : public NiPSysModifierC2E
{
  public:
    void FUN_00c2ec40(NiStreamC2E& kStream);

    void* m_pkTarget;
    NiColorC2E m_kFogTint;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
};

// Saves the modifier base, the target link ID, the color, and the four float values to the stream.
// @fnv 0x00c2ec40
void NiPSysEmitterC2E::FUN_00c2ec40(NiStreamC2E& kStream)
{
    NiPSysModifierC2E::SaveBinary(kStream);
    kStream.SaveLinkID(m_pkTarget);
    m_kFogTint.SaveBinary(kStream);
    C2EC40SaveBinary(kStream, m_fCoefficientA);
    C2EC40SaveBinary(kStream, m_fB);
    C2EC40SaveBinary(kStream, m_fC);
    C2EC40SaveBinary(kStream, m_fD);
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_010c01ec;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;
struct C2E570_Base
{
    void FUN_00c31720() throw();
};
struct C2E570_Modifier : C2E570_Base
{
    void* m_pVtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    float m_28;
    float m_2C;
    int m_30;
    int m_34;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    C2E570_Modifier()
    {
        FUN_00c31720();
        m_pVtable = &DAT_010c01ec;
        m_18 = 0;
        m_1C = DAT_011a946c;
        m_20 = DAT_011a9470;
        m_24 = DAT_011a9474;
        m_28 = 0.0f;
        m_2C = 0.0f;
        m_30 = 0;
        m_34 = 0;
    }
    void FUN_00c31780(C2E570_Modifier* clone, int arg);
    C2E570_Modifier* CreateClone(int arg);
};
// Creates a new modifier, calls FUN_00c31780 on it, copies m_1C, m_20, m_24, m_28, m_2C, m_30, and m_34, then returns it.
// @fnv 0x00c2e570
C2E570_Modifier* C2E570_Modifier::CreateClone(int arg)
{
    C2E570_Modifier* clone = new C2E570_Modifier;
    FUN_00c31780(clone, arg);
    clone->m_1C = m_1C;
    clone->m_20 = m_20;
    clone->m_24 = m_24;
    clone->m_28 = m_28;
    clone->m_2C = m_2C;
    clone->m_30 = m_30;
    clone->m_34 = m_34;
    return clone;
}

#include <string.h>
#include <math.h>
extern NiPoint3 NiPoint3_ZERO;

struct BombPoint
{
    float x, y, z;
    BombPoint()
    {}
    BombPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    BombPoint(const NiPoint3& p)
    {
        memcpy(this, &p, sizeof(*this));
    }
    __declspec(noalias) void FUN_004a0c10();
    float Dot(const BombPoint& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
    BombPoint operator-(const BombPoint& p) const
    {
        return BombPoint(x - p.x, y - p.y, z - p.z);
    }
    BombPoint operator-() const
    {
        return BombPoint(-x, -y, -z);
    }
    BombPoint operator*(float f) const
    {
        return BombPoint(x * f, y * f, z * f);
    }
    BombPoint operator/(float f) const
    {
        float r = 1.0f / f;
        return BombPoint(x * r, y * r, z * r);
    }
    BombPoint& operator/=(float f)
    {
        float r = 1.0f / f;
        x *= r;
        y *= r;
        z *= r;
        return *this;
    }
    BombPoint& operator+=(const BombPoint& p)
    {
        x += p.x;
        float* dest = &y;
        *dest += p.y;
        z += p.z;
        return *this;
    }
};
inline BombPoint operator*(float f, const BombPoint& p)
{
    return BombPoint(f * p.x, f * p.y, f * p.z);
}
struct ThreeByThreeMatrix
{
    float m_00, m_01, m_02;
    float m_10, m_11, m_12;
    float m_20, m_21, m_22;
    BombPoint FUN_004b4500(const NiPoint3& pt) const;
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    BombPoint m_kTranslation;
    float m_fScale;
    void Invert(NiTransform& kDest) const;
    NiTransform* Multiply(NiTransform* out, const NiTransform* rhs) const;
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

struct NiPoint3Helper
{
    __declspec(noalias) void Unitize();
};

struct Point3ParameterData
{
    BombPoint m_kValue;
    float unk0c;
    float unk10;
    float m_fZValue;
    int unk18;
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
    BombPoint* m_pkPositions;
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
    unsigned short m_usNumActive;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};

struct NiPSysModifierStandIn
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    NiAVObject* m_pkTarget;
};

struct BombModShell : BombMod
{
    void FUN_00c2e670(float fTime, NiPSysData* pkData);
};

// Applies velocity impulses to particles based on bomb direction, symmetry type, and distance decay over the elapsed time step.
// @fnv 0x00c2e670
void BombModShell::FUN_00c2e670(float fTime, NiPSysData* pkData)
{
    Point3ParameterData* pkInfo;
    (void)pkInfo;
    float fDist;
    (void)fDist;
    BombPoint kTargetCenter = NiPoint3_ZERO;
    BombPoint kBombAxis = m_kBombDirection;
    BombPoint kDiff;
    float fDeltaT;
    BombPoint kRadial;
    BombPoint kDirection;

    (void)kBombAxis.x;
    if (pkData->m_usNumParticles > 0 && m_pkBombObject)
    {
        NiTransform kBombWorld = ((NiAVObject*)m_pkBombObject)->m_kWorldSpaceTransform;
        NiTransform kBombToTarget = ((NiPSysModifierStandIn*)this)->m_pkTarget->m_kWorldSpaceTransform;
        NiTransform kTargetInv;
        kBombToTarget.Invert(kTargetInv);
        kTargetInv.Multiply(&kBombToTarget, &kBombWorld);

        kTargetCenter = kBombToTarget.m_kTranslation;
        kBombAxis = kBombToTarget.m_kOrientation.FUN_004b4500(m_kBombDirection);
        kBombAxis.FUN_004a0c10();
    }

    for (unsigned short i = 0; i < pkData->m_usNumParticles; ++i)
    {
        pkInfo = &pkData->m_pkParticleInfo[i];
        float ActorConditionAndAnimationState = pkInfo->m_fZValue;
        if (fTime > ActorConditionAndAnimationState)
        {
            fDeltaT = fTime - ActorConditionAndAnimationState;

            kDiff = pkData->m_pkPositions[i] - kTargetCenter;

            fDist = kDiff.Length();

            if (m_eBombDecayType != 0 && !(fDist <= m_fDistanceDecay))
                continue;

            switch (m_eSymmetryType)
            {
            case 0: {
                kDirection = kDiff / fDist;
                break;
            }
            case 1: {
                fDist = kBombAxis.Dot(kDiff);
                BombPoint kTemp = kBombAxis * fDist;
                kRadial = kDiff - kTemp;
                kDirection = kRadial;
                fDist = kRadial.Length();
                if (fDist != 0.0f)
                {
                    kDirection /= fDist;
                }
                break;
            }
            case 2: {
                fDist = kBombAxis.Dot(kDiff);
                if (fDist < 0.0f)
                {
                    fDist = -fDist;
                    kDirection = -kBombAxis;
                }
                else
                {
                    kDirection = kBombAxis;
                }
                break;
            }
            }

            float fVolumeScale = 1.0f;
            if (m_eBombDecayType == 1)
            {
                fVolumeScale = (m_fDistanceDecay - fDist) / m_fDistanceDecay;
            }
            else if (m_eBombDecayType == 2)
            {
                fVolumeScale = expf(-fDist / m_fDistanceDecay);
            }

            pkInfo->m_kValue += (m_fDeltaVelocity * fVolumeScale * fDeltaT) * kDirection;
        }
    }
}


// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012027a8;

// @fnv 0x00c2f590
void* __cdecl FUN_00c2f590()
{
    return &g_012027a8;
}

void __cdecl FUN_00c31750(void);
void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

struct NiPSysAirFieldModifier
{
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00c31750, then if flags has bit 1 set calls __Dummy_00b6fef0 on this with 0x68, and returns this.
// @fnv 0x00c2f5a0
void* __thiscall NiPSysAirFieldModifier::Destroy(unsigned int flags)
{
    void* p = this;
    FUN_00c31750();
    if (flags & 1)
        __Dummy_00b6fef0(p, 0x68);
    return p;
}

struct CloningProcess
{
};
struct NiObject
{
};
struct NiPSysFieldModifier
{
    void __thiscall FUN_00c32020(NiPSysFieldModifier*, CloningProcess&);
    NiObject* __thiscall Clone(CloningProcess&);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct AirTmp : NiPSysFieldModifier
{
    AirTmp* __thiscall FUN_00c2f5c0();
    void __thiscall FUN_00c2f500(void*);
};
// @fnv 0x00c2fad0
NiObject* __thiscall NiPSysFieldModifier::Clone(CloningProcess& kCloning)
{
    AirTmp* pkObject;
    void* pMemory = BSFadeNode::operator new(0x68);
    if (pMemory)
        pkObject = ((AirTmp*)pMemory)->FUN_00c2f5c0();
    else
        pkObject = 0;
    FUN_00c32020(pkObject, kCloning);
    pkObject->FUN_00c2f500((char*)this + 0x40);
    return (NiObject*)pkObject;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00c2f630
void* __cdecl CreateAirTmp()
{
    AirTmp* p = (AirTmp*)A51BF0Base::operator new(0x68);
    if (p)
        return p->FUN_00c2f5c0();
    return 0;
}

extern float DAT_011f426c;
extern float DAT_011f4270;
extern float DAT_011f4274;
extern float DAT_011a946c;
extern float DAT_011a9470;
extern float DAT_011a9474;
struct TmpVec3
{
    int x;
    int y;
    int z;
    void __thiscall FUN_004a0c10();
};
// Copies three ints from param into this+0x40 and this+0x4c, calls FUN_004a0c10, and replaces the vector with DAT_011a946c/70/74 if it equals DAT_011f426c/70/74.
// @fnv 0x00c2f500
void AirTmp::FUN_00c2f500(void* pSource)
{
    int* p = (int*)pSource;
    int* a = (int*)((char*)this + 0x40);
    a[0] = p[0];
    a[1] = p[1];
    a[2] = p[2];
    TmpVec3* v = (TmpVec3*)((char*)this + 0x4c);
    v->x = p[0];
    v->y = p[1];
    v->z = p[2];
    v->FUN_004a0c10();
    if (*(float*)&v->x == DAT_011f426c && *(float*)&v->y == DAT_011f4270 && *(float*)&v->z == DAT_011f4274)
    {
        v->x = *(int*)&DAT_011a946c;
        v->y = *(int*)&DAT_011a9470;
        v->z = *(int*)&DAT_011a9474;
    }
}

struct SubObject40
{
    int unk00;
    bool FUN_00439090(void* other);
};

struct FUN_00c2fb10_cls
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
    SubObject40 m_40;

    bool FUN_00c32060(void* other);
    bool IsEqual(void* other);
};

// @fnv 0x00c2fb10
bool FUN_00c2fb10_cls::IsEqual(void* other)
{
    FUN_00c2fb10_cls* p = (FUN_00c2fb10_cls*)other;
    if (FUN_00c32060(other) == false)
    {
        return false;
    }
    if (p->m_40.FUN_00439090(&m_40))
        return false;
    return true;
}

struct NiBinaryStream
{
    typedef unsigned int(__cdecl* WriteFn)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* unk08;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pv, unsigned int uiBytes, unsigned int* puiSizes, unsigned int uiElementCount)
    {
        unsigned int uiWritten = m_pfnWrite(this, pv, uiBytes, puiSizes, uiElementCount);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};

struct NiStream
{
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
    NiBinaryStream* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiBinaryStream* pkStr, const T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStr->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

struct NiColor
{
    float r, g, b;
    void SaveBinary(NiStream& stream);
};

struct NiPSysFieldModifierBase
{
    void SaveBinary(NiStream& stream);
};

struct NiPSysGravityFieldModifier : NiPSysFieldModifierBase
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
    NiColor m_kFogTint;
    int unk4C;
    int unk50;
    int unk54;
    float m_f58;
    float m_f5C;
    bool m_b60;
    bool m_b61;
    bool m_b62;
    float m_f64;

    void FUN_00c302a0(NiStream& stream);
};

// Saves the base field modifier, a color, m_f58, m_f5C, the three bools m_b60-m_b62 and m_f64 to the stream.
// @fnv 0x00c302a0
void NiPSysGravityFieldModifier::FUN_00c302a0(NiStream& stream)
{
    NiPSysFieldModifierBase::SaveBinary(stream);
    m_kFogTint.SaveBinary(stream);
    SerializeValue(stream.m_pBackingStream, m_f58);
    SerializeValue(stream.m_pBackingStream, m_f5C);
    unsigned char ucBool = m_b60;
    SerializeValue(stream.m_pBackingStream, ucBool);
    ucBool = m_b61;
    SerializeValue(stream.m_pBackingStream, ucBool);
    ucBool = m_b62;
    SerializeValue(stream.m_pBackingStream, ucBool);
    SerializeValue(stream.m_pBackingStream, m_f64);
}

class BC2F5C0Point3
{
  public:
    BC2F5C0Point3()
    {}
    BC2F5C0Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    BC2F5C0Point3 operator-() const
    {
        return BC2F5C0Point3(-x, -y, -z);
    }

    float x;
    float y;
    float z;
};

extern const BC2F5C0Point3 g_kC2F5C0UnitZ;
extern const BC2F5C0Point3 g_kC2F5C0Zero;

class BC2F5C0Modifier
{
  public:
    BC2F5C0Modifier() throw();
    virtual ~BC2F5C0Modifier();

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
};

class FUN_00c2f5c0_cls : public BC2F5C0Modifier
{
  public:
    FUN_00c2f5c0_cls() throw();
    virtual ~FUN_00c2f5c0_cls();

    void SetDirection(const BC2F5C0Point3& kDirection);

    BC2F5C0Point3 m_kPathOffset;
    float m_fFirstLightParameter;
};

// Initialises the modifier: sets direction to -unit Z, resets the point to zero, and sets the float to FLT_MAX.
// @fnv 0x00c2f5c0
FUN_00c2f5c0_cls::FUN_00c2f5c0_cls() throw()
{
    SetDirection(-g_kC2F5C0UnitZ);
    m_kPathOffset = g_kC2F5C0Zero;
    m_fFirstLightParameter = 3.402823466e+38f;
}

extern "C" void* g_012027a8;

struct ViewerStrings
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
};

struct ViewerSub
{
    int unk00;
    int unk04;
    int unk08;

    void* FUN_00a59af0(const char* name);
};

void* __cdecl FUN_00a7d330(void* g);
void* __cdecl FUN_00a7d550(const char* name, float value);
void* __cdecl FUN_00a7d370(const char* name, bool value);

struct FUN_00c303c0_cls
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
    ViewerSub m_40;
    ViewerSub m_4c;
    float m_58;
    float m_5c;
    bool m_60;
    bool m_61;
    bool m_62;
    float m_64;

    void GetViewerStrings(ViewerStrings* s);
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void** value);
    void BuildViewerStrings(ViewerStrings* s);
};

static void AddViewerString(ViewerStrings* s, void* value)
{
    FUN_00c303c0_cls* arr = reinterpret_cast<FUN_00c303c0_cls*>(s);
    unsigned int count = s->m_0a;
    if (count >= s->m_08)
    {
        arr->FUN_0096ad30(count + s->m_0e);
    }
    arr->FUN_0096ae90(count, &value);
}

// @fnv 0x00c303c0
void FUN_00c303c0_cls::BuildViewerStrings(ViewerStrings* s)
{
    GetViewerStrings(s);
    void* v = FUN_00a7d330(g_012027a8);
    AddViewerString(s, v);
    v = m_40.FUN_00a59af0("Direction");
    AddViewerString(s, v);
    v = m_4c.FUN_00a59af0("Unit Direction");
    AddViewerString(s, v);
    v = FUN_00a7d550("AirFriction", m_58);
    AddViewerString(s, v);
    v = FUN_00a7d550("Inherit Velocity", m_5c);
    AddViewerString(s, v);
    v = FUN_00a7d370("Inherit Rotation", m_60);
    AddViewerString(s, v);
    v = FUN_00a7d370("Component Only", m_61);
    AddViewerString(s, v);
    v = FUN_00a7d370("Enable Spread", m_62);
    AddViewerString(s, v);
    v = FUN_00a7d550("Spread", m_64);
    AddViewerString(s, v);
}

struct AirFieldModifier
{
    void __thiscall FUN_00c2e520(NiStream& stream);
    void __thiscall FUN_00c2f4e0(NiStream& stream);
};

// @fnv 0x00c2f4e0
void __thiscall AirFieldModifier::FUN_00c2f4e0(NiStream& stream)
{
    FUN_00c2e520(stream);
}

struct FUN_00c61f60_class
{
    unsigned char __thiscall FUN_00c28b60(int param);
    unsigned char __thiscall FUN_00c2f4f0(int param);
};

// @fnv 0x00c2f4f0
unsigned char __thiscall FUN_00c61f60_class::FUN_00c2f4f0(int param)
{
    return FUN_00c28b60(param);
}

struct NiPoint3
{
    float x, y, z;

    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    NiPoint3 operator*(float fScalar) const
    {
        return NiPoint3(x * fScalar, y * fScalar, z * fScalar);
    }

    friend NiPoint3 operator*(float fScalar, const NiPoint3& pt)
    {
        return NiPoint3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
    }

    NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }

    NiPoint3 operator+(const NiPoint3& pt) const
    {
        return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
    }

    NiPoint3& operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }

    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }

    float Dot(const NiPoint3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

struct ThreeByThreeMatrix
{
    float m_00, m_01, m_02;
    float m_10, m_11, m_12;
    float m_20, m_21, m_22;

    ThreeByThreeMatrix()
    {}

    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;

    void Invert(NiTransform& kDest) const;
    NiTransform operator*(const NiTransform& rhs) const;
};

struct TargetObj
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

    NiTransform GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
};

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    int unk0c;
    int unk10;
    float m_fZValue;
    float GetLastUpdate() const
    {
        return m_fZValue;
    }
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
    NiPoint3* m_pkPositions;
    NiPoint3* GetPositions()
    {
        return m_pkPositions;
    }
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
    unsigned short GetShaderParticleCount() const
    {
        return m_usNumParticles;
    }
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
    Point3ParameterData* GetParticleInfo()
    {
        return m_pkParticleInfo;
    }
};

struct Cls_00c2f650
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    TargetObj* m_pkTarget;
    int unk14;
    TargetObj* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    char unk25;
    char unk26;
    char unk27;
    float m_fDistanceLimit;
    float m_fMaxDistanceSquared;
    float GetMaxDistanceSquared() const
    {
        return m_fMaxDistanceSquared;
    }
    NiPoint3 m_kTransformedFieldPosition;
    float m_fLastTime;
    NiPoint3 m_kLightVector;
    NiPoint3 m_kParticleVelocityDirection;
    float m_fParticleAirFriction;
    float GetAirFriction() const
    {
        return m_fParticleAirFriction;
    }
    float m_fInheritedVelocity;
    bool m_bFlagAtOffset60;
    char unk61;
    char unk62;
    char unk63;
    float unk64;

    void UpdateParticleAirFriction(float fTime, NiPSysData* pkData);
};

inline void* operator new(unsigned int, void* pv)
{
    return pv;
}

// For particles within the squared distance limit, adds an air-friction-scaled field velocity over elapsed time when relative velocity points against it.
// @fnv 0x00c2f650
void Cls_00c2f650::UpdateParticleAirFriction(float fTime, NiPSysData* pkData)
{
    if (m_fInfluence == 0.0f)
        return;

    NiTransform kInvPSys;
    NiTransform kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kFieldToPSys = m_pkTarget->m_kWorldSpaceTransform;
    kFieldToPSys.Invert(kInvPSys);
    new (&kFieldToPSys) NiTransform(kInvPSys * kField);

    m_kTransformedFieldPosition = kFieldToPSys.m_kTranslation;
    m_fLastTime = fTime;

    NiPoint3 kWorldPosition;
    if (m_bFlagAtOffset60)
    {
        kWorldPosition = kFieldToPSys.m_kOrientation * m_kParticleVelocityDirection;
    }
    else
    {
        kWorldPosition = m_kParticleVelocityDirection;
    }

    NiPoint3 kAirVel;
    kAirVel = m_fInfluence * kWorldPosition;

    for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); ++i)
    {
        Point3ParameterData* pkInfo = &pkData->GetParticleInfo()[i];
        float fMoveElapsedTime = fTime - pkInfo->GetLastUpdate();
        if (fMoveElapsedTime != 0.0f)
        {
            NiPoint3 kPos = pkData->GetPositions()[i];
            kWorldPosition = kPos - kFieldToPSys.m_kTranslation;
            float fDistSqr = kWorldPosition.SqrLength();
            if (fDistSqr <= GetMaxDistanceSquared())
            {
                float fDot;
                NiPoint3 kRelVel;
                kRelVel = pkInfo->m_kValue - kAirVel;
                fDot = kRelVel.Dot(kAirVel);
                if (fDot < 0.0f)
                {
                    NiPoint3 kForce = GetAirFriction() * kAirVel;
                    pkInfo->m_kValue += kForce * fMoveElapsedTime;
                }
            }
        }
    }
}

struct S00c30170_Rd
{
    int vtable;
    unsigned m_uiStreamFlags;
    unsigned(__cdecl* m_pfnRead)(S00c30170_Rd*, void*, unsigned, unsigned*, unsigned);
    unsigned BinaryRead(void* pv, unsigned uiTotalBytes, unsigned* puiSizes, unsigned uiElementCount)
    {
        unsigned uiBytesRead = m_pfnRead(this, pv, uiTotalBytes, puiSizes, uiElementCount);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline unsigned S00c30170_Load(S00c30170_Rd& r, T* p, unsigned n)
{
    unsigned uiSize = sizeof(T);
    return r.BinaryRead(p, n * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream* s, T& v)
{
    S00c30170_Load(*(S00c30170_Rd*)s->unk24C, &v, 1);
}
struct S00c30170_Pt
{
    float x, y, z;
    void __thiscall FUN_00a59be0(NiStream*);
};
struct S00c30170_Obj : AirTmp
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
    S00c30170_Pt m_40;
    int unk4c;
    int unk50;
    int unk54;
    float m_58;
    float m_5c;
    bool m_60;
    bool m_61;
    bool m_62;
    float m_64;
    void __thiscall LoadFromStream(NiStream*);
    void __thiscall LoadBinary(NiStream* stream);
};
// Calls LoadFromStream, reads m_40, applies FUN_00c2f500 to it, then reads m_58, m_5c, m_60, m_61, m_62, and m_64.
// @fnv 0x00c30170
void __thiscall S00c30170_Obj::LoadBinary(NiStream* stream)
{
    LoadFromStream(stream);
    m_40.FUN_00a59be0(stream);
    FUN_00c2f500(&m_40);
    ReadBinaryValue(stream, m_58);
    ReadBinaryValue(stream, m_5c);
    unsigned char b;
    ReadBinaryValue(stream, b);
    m_60 = b != 0;
    ReadBinaryValue(stream, b);
    m_61 = b != 0;
    ReadBinaryValue(stream, b);
    m_62 = b != 0;
    ReadBinaryValue(stream, m_64);
}

struct S00c2f8d0_Mod
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    TargetObj* m_pkTarget;
    int unk14;
    TargetObj* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    char unk25;
    char unk26;
    char unk27;
    float m_fDistanceLimit;
    float m_fMaxDistanceSquared;
    NiPoint3 m_kTransformedFieldPosition;
    float m_fLastTime;
    NiPoint3 m_kLightVector;
    NiPoint3 m_kParticleVelocityDirection;
    float m_fParticleAirFriction;
    float GetAirFriction() const
    {
        return m_fParticleAirFriction;
    }
    float m_fInheritedVelocity;
    bool m_bFlagAtOffset60;
    char unk61;
    char unk62;
    char unk63;
    float unk64;

    void UpdateAirFriction(float fTime, NiPSysData* pkData);
};

// When influence is nonzero, transforms the field direction and adjusts particle velocities using air friction and the time delta.
// @fnv 0x00c2f8d0
void S00c2f8d0_Mod::UpdateAirFriction(float fTime, NiPSysData* pkData)
{
    if (m_fInfluence == 0.0f)
        return;

    NiTransform kFieldXform = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvSys;
    {
        NiTransform kSysXform = m_pkTarget->m_kWorldSpaceTransform;
        kSysXform.Invert(kInvSys);
    }
    {
        NiTransform kFieldToSys = kInvSys * kFieldXform;

        m_kTransformedFieldPosition = kFieldToSys.m_kTranslation;
        m_fLastTime = fTime;

        NiPoint3 kWorldPosition;
        if (m_bFlagAtOffset60)
            kWorldPosition = kFieldToSys.m_kOrientation * m_kParticleVelocityDirection;
        else
            kWorldPosition = m_kParticleVelocityDirection;

        NiPoint3 kAirVel = kWorldPosition * m_fInfluence;

        for (unsigned short i = 0; i < pkData->m_usNumParticles; i++)
        {
            Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[i];
            float fDeltaT = fTime - pkInfo->GetLastUpdate();
            if (fDeltaT != 0.0f)
            {
                NiPoint3 kDiff = pkInfo->m_kValue - kAirVel;
                if (kDiff.Dot(kAirVel) < 0.0f)
                {
                    pkInfo->m_kValue += GetAirFriction() * kAirVel * fDeltaT;
                }
            }
        }
    }
}

#include <math.h>
struct AirPoint3
{
    float x, y, z;
    AirPoint3()
    {}
    AirPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    bool FUN_00439090(const AirPoint3&) const;
    float FUN_00457910();
    void FUN_004a0c10();
    AirPoint3 FUN_0053d280(float) const;
    AirPoint3 operator+(const AirPoint3& v) const
    {
        return AirPoint3(x + v.x, y + v.y, z + v.z);
    }
    AirPoint3 operator-(const AirPoint3& v) const
    {
        return AirPoint3(x - v.x, y - v.y, z - v.z);
    }
    AirPoint3 operator*(float s) const
    {
        return AirPoint3(x * s, y * s, z * s);
    }
    AirPoint3& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    AirPoint3& operator+=(const AirPoint3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    float Dot(const AirPoint3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
};
inline AirPoint3 operator*(float s, const AirPoint3& v)
{
    return AirPoint3(s * v.x, s * v.y, s * v.z);
}
struct AirMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    AirPoint3 FUN_004b4500(const AirPoint3*) const;
};
struct AirTransform
{
    AirMatrix rotation;
    AirPoint3 position;
    float scale;
    void FUN_004b4880(AirTransform*) const;
    void FUN_0062c250(const AirTransform*, const AirTransform*);
};
struct AirObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64;
    AirTransform world;
};
struct AirParticle
{
    AirPoint3 velocity;
    float unk0c, unk10, creationTime, unk18;
};
struct AirParticles
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AirPoint3* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned short count;
    unsigned short unk52;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    AirParticle* particles;
};
extern AirPoint3 NiPoint3_ZERO;
extern AirPoint3 DAT_011af220;
extern float DAT_011af218;
extern float DAT_011af21c;
extern float DAT_011f4ae0[];
struct AirModifier
{
    int unk00, unk04, unk08, unk0c;
    AirObject* owner;
    int unk14;
    AirObject* source;
    float magnitude;
    float attenuation;
    bool useMaxDistance;
    float maxDistance;
    float maxDistanceSquared;
    AirPoint3 previousPosition;
    float previousTime;
    int unk40, unk44, unk48;
    AirPoint3 direction;
    float airFriction;
    float inheritVelocity;
    bool inheritRotation;
    bool unk61;
    bool enableSpread;
    float spread;
    void UpdateParticleAirFriction(float, AirParticles*);
    void UpdateAirFriction(float, AirParticles*);
    void FUN_00c2fb40(float, AirParticles*);
};
// Updates particle velocities using the field direction and magnitude, with optional spread, distance limiting, attenuation, and inherited velocity.
// @fnv 0x00c2fb40
void AirModifier::FUN_00c2fb40(float time, AirParticles* apParticles)
{
    if (apParticles->count == 0 || !source)
        return;
    if (attenuation == 0.0f && inheritVelocity == 0.0f && !enableSpread)
    {
        if (useMaxDistance)
            UpdateParticleAirFriction(time, apParticles);
        else
            UpdateAirFriction(time, apParticles);
        return;
    }
    AirTransform sourceWorld = source->world;
    AirTransform ownerWorld = owner->world;
    AirTransform inverseTransform;
    ownerWorld.FUN_004b4880(&inverseTransform);
    inverseTransform.FUN_0062c250(&ownerWorld, &sourceWorld);
    AirPoint3 fieldDirection;
    if (inheritRotation)
        fieldDirection = ownerWorld.rotation.FUN_004b4500(&direction);
    else
        fieldDirection = direction;
    AirPoint3 unitVelocity = NiPoint3_ZERO;
    if (previousPosition.FUN_00439090(DAT_011af220) && previousTime != 3.4028234663852886e38 && previousTime != time)
    {
        unitVelocity = ((ownerWorld.position - previousPosition) * inheritVelocity).FUN_0053d280(time - previousTime);
    }
    previousTime = time;
    previousPosition = ownerWorld.position;
    unitVelocity += fieldDirection * magnitude;
    if (unitVelocity.SquaredLength() == 0.0f)
        return;
    {
        AirPoint3 fieldVelocity = unitVelocity;
        float speed = fieldVelocity.FUN_00457910();
        float fMinDot = 0.0f;
        if (enableSpread)
        {
            float angle = spread * DAT_011af218;
            fMinDot = DAT_011f4ae0[((int)(angle * (512.0 / DAT_011af21c))) & 511];
        }
        for (unsigned short i = 0; i < apParticles->count; ++i)
        {
            AirParticle& particle = apParticles->particles[i];
            float delta = time - particle.creationTime;
            if (delta == 0.0f)
                continue;
            AirPoint3* positions = apParticles->positions;
            AirPoint3 position = positions[i];
            AirPoint3 offset = position - ownerWorld.position;
            float distanceSquared = offset.SquaredLength();
            bool limited = useMaxDistance;
            if (limited && !(distanceSquared <= maxDistanceSquared))
                continue;
            AirPoint3 velocity = unitVelocity;
            if (enableSpread)
            {
                velocity = offset;
                velocity.FUN_004a0c10();
                float dot = fieldVelocity.Dot(velocity);
                if (dot < fMinDot)
                    continue;
                velocity *= speed;
            }
            AirPoint3 currentVelocity = particle.velocity;
            (void)currentVelocity.y;
            (void)currentVelocity.z;
            AirPoint3 difference = currentVelocity - velocity;
            float dot = difference.Dot(velocity);
            if (!(dot < 0.0f))
                continue;
            float factor = delta;
            if (limited && attenuation != 0.0f)
            {
                float distance = (float)sqrt(distanceSquared);
                float normalized = 1.0f - distance / maxDistance;
                float falloff = (float)pow(normalized, attenuation);
                factor = falloff * delta;
            }
            currentVelocity += (airFriction * velocity) * factor;
            particle.velocity = currentVelocity;
        }
    }
}

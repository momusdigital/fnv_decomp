
// src/gamebryo2.2/corelibs/niparticle/nipsysgravitymodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravitymodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

extern NiMemObject g_01202548;

// @fnv 0x00c22af0
NiMemObject* __cdecl FUN_00c22af0()
{
    return &g_01202548;
}

extern "C" void* g_01202790;

// @fnv 0x00c2e540
void* __cdecl FUN_00c2e540()
{
    return &g_01202790;
}

namespace fnv_00c22b00 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

struct NiPoint3
{
    float x, y, z;
};
struct NiPSysModifier
{
    char _pad[0x1c];
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
};
struct NiPSysGravityModifier : NiPSysModifier
{
    NiPoint3 m_kGravityDirection;
    float m_fDistanceDecay;
    float m_fValue;
    int m_eRequestType;
    float m_fTurbulenceAmount;
    float m_fScale;
    bool m_bFieldFlag;
    void* operator new(unsigned int);
    NiPSysGravityModifier* InitDefaults();
    NiPSysGravityModifier* CreateClone(CloningProcess&);
};
// Allocates and constructs a copy of this gravity modifier, copies its fields, runs the base clone step with process, and returns the clone.
// @fnv 0x00c22b00
NiPSysGravityModifier* NiPSysGravityModifier::CreateClone(CloningProcess& process)
{
    NiPSysGravityModifier* clone = static_cast<NiPSysGravityModifier*>(operator new(0x40));
    if (clone)
        clone = clone->InitDefaults();
    else
        clone = 0;
    CopyMemberData(clone, process);
    clone->m_kGravityDirection = m_kGravityDirection;
    clone->m_fDistanceDecay = m_fDistanceDecay;
    clone->m_fValue = m_fValue;
    clone->m_eRequestType = m_eRequestType;
    clone->m_fTurbulenceAmount = m_fTurbulenceAmount;
    clone->m_fScale = m_fScale;
    clone->m_bFieldFlag = m_bFieldFlag;
    return clone;
}
}  // namespace fnv_00c22b00

namespace fnv_00c2e520 {
struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiTexture;
struct NiThread;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiStream
{
    NiObject* GetLoadedObject(void);
};

struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};

struct NiPSysBombModifier : NiPSysModifier
{
    char _pad[0x14];
    NiObject* m_pPointer;  // +0x18
    void LinkObject(NiStream&);
};

void NiPSysBombModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    m_pPointer = stream.GetLoadedObject();
}

struct FUN_00c2e520_shell : NiPSysBombModifier
{
    void LinkObject(NiStream&);
};

// @fnv 0x00c2e520
void FUN_00c2e520_shell::LinkObject(NiStream& stream)
{
    NiPSysBombModifier::LinkObject(stream);
}
}  // namespace fnv_00c2e520

struct S_00c236b0_BinaryStream;
typedef unsigned int(__cdecl* S_00c236b0_ReadFn)(S_00c236b0_BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S_00c236b0_BinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00c236b0_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T>
inline void S_00c236b0_BinaryStreamLoad(S_00c236b0_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct S_00c236b0_Stream
{
    int unk0;
    unsigned int m_uiUserVersion;  // +04
    int unk8;
    int unkC;
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiNifVersion;  // +D8
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    S_00c236b0_BinaryStream* m_pUnderlyingStream;  // +24C

    void FUN_00a645b0();
};

template <class T> inline void S_00c236b0_StreamLoadBinary(S_00c236b0_Stream& kStream, T& value)
{
    S_00c236b0_BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

struct S_00c236b0_Member1C
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00a59be0(S_00c236b0_Stream& kStream);
};

struct S_00c236b0_Base
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void FUN_00c318b0(S_00c236b0_Stream& kStream);  // LoadBinary
};

struct S_00c236b0_Obj : S_00c236b0_Base
{
    S_00c236b0_Member1C m_1C;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    bool m_3C;

    void LoadFromStream(S_00c236b0_Stream& kStream);
};

// Loads the object's base data, member m_1C, m_28, m_2C, m_30, and conditionally m_34, m_38 and m_3C from kStream based on version checks.
// @fnv 0x00c236b0
void S_00c236b0_Obj::LoadFromStream(S_00c236b0_Stream& kStream)
{
    FUN_00c318b0(kStream);
    kStream.FUN_00a645b0();
    m_1C.FUN_00a59be0(kStream);
    S_00c236b0_StreamLoadBinary(kStream, m_28);
    S_00c236b0_StreamLoadBinary(kStream, m_2C);
    int iValue;
    S_00c236b0_StreamLoadBinary(kStream, iValue);
    m_30 = iValue;
    if (kStream.m_uiNifVersion >= 0x0a00010e)
    {
        S_00c236b0_StreamLoadBinary(kStream, m_34);
        S_00c236b0_StreamLoadBinary(kStream, m_38);
    }
    if (kStream.m_uiUserVersion > 20)
    {
        S_00c236b0_StreamLoadBinary(kStream, m_3C);
    }
}

struct FNVStreamWriter
{
    void* owner;
    unsigned int writtenBytes;
    void* streamState;
    int(__cdecl* write)(FNVStreamWriter*, const void*, unsigned int, unsigned int*, int);
};
struct FNVStreamArchive
{
};
struct FNVSubproperty
{
    void FUN_00a69780(FNVStreamArchive*);
};
struct FNVSerializer
{
    void FUN_00c31950(FNVStreamArchive*);
    void WriteToStream(FNVStreamArchive*);
};
// Writes a header, a subproperty, and five 4-byte values plus one 1-byte value from this object to the stream writer.
// @fnv 0x00c237c0
void FNVSerializer::WriteToStream(FNVStreamArchive* stream)
{
    FUN_00c31950(stream);
    typedef void(__thiscall * HeaderWriter)(FNVStreamArchive*, unsigned int);
    HeaderWriter pHeaderWriter = reinterpret_cast<HeaderWriter>((*reinterpret_cast<void***>(stream))[12]);
    pHeaderWriter(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18));
    reinterpret_cast<FNVSubproperty*>(reinterpret_cast<char*>(this) + 0x1c)->FUN_00a69780(stream);
    FNVStreamWriter* __restrict writer;
    unsigned int length;
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x28, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x2c, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x30, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x34, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x38, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 1;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x3c, 1, reinterpret_cast<unsigned int*>(&length), 1);
}

struct NiViewerStringsArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int usIndex = m_usSize;
        if (usIndex >= m_usMaxSize)
            FUN_0096ad30(usIndex + m_usGrowBy);
        FUN_0096ae90(usIndex, element);
        return usIndex;
    }
};

struct NiRTTIStandIn
{
    const char* m_pcName;
};
extern NiRTTIStandIn g_kGravityModifierRTTI_01202548;

char* __cdecl FUN_00a7d330(const char* pcName);
char* __cdecl FUN_00a7d5e0(const char* pcPrefix, const char* pcValue);
char* __cdecl FUN_00a7d550(const char* pcPrefix, float fValue);
char* __cdecl FUN_00a7d370(const char* pcPrefix, bool bValue);

struct NiPoint3StandIn
{
    float x, y, z;
    char* FUN_00a59af0(const char* pcPrefix) const;
};

struct NiAVObjectStandIn
{
    int unk00;
    int unk04;
    const char* m_kName;
};

struct NiPSysGravityModifierImpl
{
    char pad00[0x18];
    NiAVObjectStandIn* m_pkGravityObject;
    NiPoint3StandIn m_kGravityDirection;
    float m_fDistanceDecay;
    float m_fValue;
    int m_eForceType;
    float m_fTurbulenceAmount;
    float m_fTurbulenceScale;
    bool m_bFieldFlag;

    void FUN_00c319e0(NiViewerStringsArray* pkStrings);
    void AddViewerStrings(NiViewerStringsArray* pkStrings);
};

// Appends the gravity modifier's RTTI name, gravity object, axis, decay, strength, turbulence, force type and world-aligned flag to the viewer strings array.
// @fnv 0x00c238c0
void NiPSysGravityModifierImpl::AddViewerStrings(NiViewerStringsArray* pkStrings)
{
    FUN_00c319e0(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_kGravityModifierRTTI_01202548.m_pcName));
    const char* pcGravityObjName;
    if (m_pkGravityObject)
        pcGravityObjName = m_pkGravityObject->m_kName;
    else
        pcGravityObjName = "None";
    pkStrings->Add(FUN_00a7d5e0("Gravity Object", pcGravityObjName));
    pkStrings->Add(m_kGravityDirection.FUN_00a59af0("Gravity Axis"));
    pkStrings->Add(FUN_00a7d550("Decay", m_fDistanceDecay));
    pkStrings->Add(FUN_00a7d550("Strength", m_fValue));
    pkStrings->Add(FUN_00a7d550("Turbulence", m_fTurbulenceAmount));
    pkStrings->Add(FUN_00a7d550("TurbulenceScale", m_fTurbulenceScale));
    const char* pcForceTypeName;
    if (m_eForceType == 0)
        pcForceTypeName = "FORCE_PLANAR";
    else if (m_eForceType == 1)
        pcForceTypeName = "FORCE_SPHERICAL";
    else
        pcForceTypeName = "Unknown";
    pkStrings->Add(FUN_00a7d5e0("Force Type", pcForceTypeName));
    pkStrings->Add(FUN_00a7d370("WorldAligned", m_bFieldFlag));
}

struct Node18
{
    virtual void v00();
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
    virtual bool v5c(void* p);
};

struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00c235f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Node18* m_18;
    SubObj m_1c;
    float m_28;
    float m_2c;
    int m_30;
    float m_34;
    float m_38;
    char m_3c;

    bool FUN_00c31830(FUN_00c235f0_cls* o);
    bool FUN_00439090(void* p);
    bool IsEqual(FUN_00c235f0_cls* o);
};

// Compares two FUN_00c235f0_cls objects for equality, checking m_18, m_1c, and the float/int/char fields m_28 through m_3c.
// @fnv 0x00c235f0
bool FUN_00c235f0_cls::IsEqual(FUN_00c235f0_cls* apOther)
{
    if (FUN_00c31830(apOther))
    {
        if ((m_18 && !apOther->m_18) || (!m_18 && apOther->m_18))
            return false;
        if (m_18 && apOther->m_18 && !m_18->v5c(apOther->m_18))
            return false;
        if (((FUN_00c235f0_cls*)&apOther->m_1c)->FUN_00439090(&m_1c))
            return false;
        if (apOther->m_28 != m_28)
            return false;
        if (apOther->m_2c != m_2c)
            return false;
        if (apOther->m_30 != m_30)
            return false;
        if (apOther->m_34 != m_34)
            return false;
        if (apOther->m_38 != m_38)
            return false;
        if (apOther->m_3c != m_3c)
            return false;
        return true;
    }
    return false;
}

#include <string.h>
#include <math.h>
extern const double DAT_0106efa0 = 1.600000023841858;
inline float DecayExp(float value)
{
    return (float)exp(value);
}

struct VectorC22
{

    union
    {
        struct
        {
            float x, y, z;
        };
        float components[3];
    };
    float& operator[](unsigned i)
    {
        return components[i];
    }
    const float& operator[](unsigned i) const
    {
        return components[i];
    }
    __forceinline float& X()
    {
        return x;
    }
    __forceinline float& Y()
    {
        return y;
    }
    __forceinline float& Z()
    {
        return z;
    }
    __forceinline const float& X() const
    {
        return x;
    }
    __forceinline const float& Y() const
    {
        return y;
    }
    __forceinline const float& Z() const
    {
        return z;
    }

    __forceinline void CopyAxis(VectorC22 source)
    {
        memcpy(&z, &source.z, 4);
        memcpy(&y, &source.y, 4);
        memcpy(&x, &source.x, 4);
    }

    VectorC22()
    {}

    VectorC22(float a, float b, float c) : x(a), y(b), z(c)
    {}

    VectorC22 operator-(const VectorC22& p) const
    {
        VectorC22 result(x - p.x, y - p.y, z - p.z);
        return result;
    }

    VectorC22 operator*(float k) const
    {
        VectorC22 result(x * k, y * k, z * k);
        return result;
    }

    VectorC22 operator+(const VectorC22& p) const
    {
        VectorC22 result(x + p.x, y + p.y, z + p.z);
        return result;
    }

    VectorC22& operator+=(const VectorC22& p)
    {
        X() += p.X();
        Y() += p.Y();
        Z() += p.Z();
        return *this;
    }

    float Dot(const VectorC22& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }

    float Length() const
    {
        return (float)sqrt((double)(float)(x * x + y * y + z * z));
    }
};

inline VectorC22 operator*(float scale, const VectorC22& point)
{
    return VectorC22(point.x * scale, point.y * scale, point.z * scale);
}

__declspec(noinline) void __fastcall FUN_004a0c10(VectorC22* point)
{
    float length = point->Length();
    if (length > 9.999999974752427e-07)
    {
        float inverse = 1.0f / length;
        point->x *= inverse;
        point->y *= inverse;
        point->z *= inverse;
    }
    else
    {
        point->x = point->y = point->z = 0.0f;
    }
}

__declspec(noinline) float __fastcall FUN_00457910(VectorC22* point)
{
    float length = point->Length();
    if (length > 9.999999974752427e-07)
    {
        float inverse = 1.0f / length;
        point->x *= inverse;
        point->y *= inverse;
        point->z *= inverse;
    }
    else
    {
        point->x = point->y = point->z = 0.0f;
        length = 0.0f;
    }
    return length;
}

struct MatrixC22
{

    float xx, xy, xz, yx, yy, yz, zx, zy, zz;

    VectorC22 FUN_004b4500(const VectorC22* source) const;
};

struct TransformC22
{

    __forceinline TransformC22& operator=(const TransformC22& other)
    {
        memcpy(this, &other, sizeof(*this));
        return *this;
    }

    TransformC22()
    {}

    __forceinline TransformC22(const TransformC22& other)
    {
        memcpy(this, &other, sizeof(*this));
    }

    MatrixC22 rotation;

    VectorC22 translation;

    float scale;

    TransformC22* FUN_004b4880(TransformC22* destination);

    void FUN_0062c250(const TransformC22* lhs, const TransformC22* rhs);
};

struct SourceC22
{

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    int unk20, unk24, unk28, unk2c, unk30;

    TransformC22 localTransform;

    TransformC22 worldTransform;
};

struct ParticleC22
{

    VectorC22 position;

    float unk0c, unk10, activeTime, unk18;
    float GetActiveTime() const
    {
        return activeTime;
    }
    VectorC22& GetPosition()
    {
        return position;
    }

    __forceinline void ApplyMotion(VectorC22 motion, float elapsed)
    {

        float step = elapsed - activeTime;

        VectorC22 displacement = motion * step;

        position.x += displacement.x;

        position.y += displacement.y;

        position.z += displacement.z;
    }
};

struct EmitterC22
{

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    VectorC22* sourcePositions;

    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;

    unsigned short activeCount;

    unsigned short unk52;

    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;

    ParticleC22* particles;
    ParticleC22* GetParticles() const
    {
        return particles;
    }
    VectorC22* GetSourcePositions() const
    {
        return sourcePositions;
    }
    unsigned short GetActiveCount() const
    {
        return activeCount;
    }
};

extern float __cdecl FUN_006397c0();

struct EffectC22
{

    int unk00, unk04, unk08, unk0c;

    SourceC22* sourceTransform;

    int unk14;

    SourceC22* directionSource;

    VectorC22 location;

    float radialStrength;

    float speed;

    int movementType;

    float dispersion;

    float spread;

    unsigned char useSource;
    float GetDecay() const
    {
        return radialStrength;
    }
    float GetAttributeStrength() const
    {
        return speed;
    }
    float GetTurbulence() const
    {
        return dispersion;
    }
    float GetTurbulenceScale() const
    {
        return spread;
    }

    __forceinline VectorC22 Axis(const TransformC22& local)
    {
        VectorC22 result;
        if (useSource)
            result = directionSource->localTransform.rotation.FUN_004b4500(&location);
        else
            result = local.rotation.FUN_004b4500(&location);
        return result;
    }

    void FUN_00c22b70(float elapsed, EmitterC22* emitter);
};

// Moves each active particle in the emitter by applying force, decay, and turbulence based on the effect's movement type and elapsed time.
// @fnv 0x00c22b70
void EffectC22::FUN_00c22b70(float elapsed, EmitterC22* emitter)
{

    if (!emitter->GetActiveCount() || !directionSource)
        return;

    TransformC22 x = directionSource->worldTransform;

    TransformC22 pForm;

    pForm = sourceTransform->worldTransform;

    TransformC22 ptr;

    pForm.FUN_004b4880(&ptr);

    ptr.FUN_0062c250(&pForm, &x);

    VectorC22 vForceDirection;
    if (useSource)
    {
        const MatrixC22& m = directionSource->localTransform.rotation;
        vForceDirection = m.FUN_004b4500(&location);
    }
    else
        vForceDirection = pForm.rotation.FUN_004b4500(&location);

    FUN_004a0c10(&vForceDirection);

    unsigned short j;
    j = emitter->GetActiveCount();

    float fSourceStrength;

    fSourceStrength = (float)(GetAttributeStrength() * DAT_0106efa0);

    switch (movementType)
    {

    case 0:

        if (GetDecay() == 0.0f && GetTurbulence() == 0.0f)
        {

            unsigned short i;
            float s;
            VectorC22* p;
            (void)i;
            (void)s;
            (void)p;
            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            for (i = 0; i < j; ++i, ++pParticle)
            {

                s = (elapsed - pParticle->GetActiveTime()) * fSourceStrength;

                VectorC22 vDisplacement = vForceDirection * s;
                p = &pParticle->position;
                float& deltaz = vDisplacement.z;
                p->x += vDisplacement.x;
                p->y += vDisplacement.y;
                p->z += deltaz;
            }
        }
        else if (GetDecay() == 0.0f && GetTurbulence() != 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            float randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle)
            {

                VectorC22 kIter;
                kIter = fSourceStrength * vForceDirection;

                VectorC22 vOffset;

                vOffset.x = FUN_006397c0() * randomScale;

                vOffset.y = FUN_006397c0() * randomScale;

                vOffset.z = FUN_006397c0() * randomScale;

                pParticle->position += (kIter + vOffset) * (elapsed - pParticle->activeTime);
            }
        }
        else if (radialStrength != 0.0f && GetTurbulence() == 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            VectorC22* y;
            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                VectorC22 z;

                z = pForm.translation - *y;

                float fDot;

                fDot = z.Dot(vForceDirection);

                float fDecay;
                if (fDot < 0.0f)
                    fDecay = DecayExp(fDot * GetDecay());
                else
                    fDecay = DecayExp(fDot * -GetDecay());

                pParticle->GetPosition() +=
                    vForceDirection * ((elapsed - pParticle->GetActiveTime()) * (fSourceStrength * fDecay));
            }
        }
        else if (GetDecay() != 0.0f && GetTurbulence() != 0.0f)
        {

            ParticleC22* pParticle;

            pParticle = emitter->GetParticles();

            VectorC22* y;
            y = emitter->GetSourcePositions();

            float randomScale;

            randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                VectorC22 vOffset;

                VectorC22 kIter = fSourceStrength * vForceDirection;

                vOffset.x = FUN_006397c0() * randomScale;

                vOffset.y = FUN_006397c0() * randomScale;

                vOffset.z = FUN_006397c0() * randomScale;

                VectorC22 z = pForm.translation - *y;

                float v;

                float fDot;

                fDot = z.Dot(vForceDirection);

                if (fDot < 0.0f)
                    v = DecayExp(fDot * GetDecay());

                else
                    v = DecayExp(fDot * -GetDecay());

                pParticle->ApplyMotion(v * kIter + vOffset, elapsed);
            }
        }

        break;

    case 1:

        if (GetDecay() == 0.0f && GetTurbulence() == 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            VectorC22* y;
            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                vForceDirection.X() = pForm.translation.X() - y->X();

                vForceDirection.Y() = pForm.translation.Y() - y->Y();

                vForceDirection.Z() = pForm.translation.Z() - y->Z();

                FUN_004a0c10(&vForceDirection);

                float s = (elapsed - pParticle->activeTime) * fSourceStrength;
                pParticle->GetPosition() += vForceDirection * s;
            }
        }
        else if (GetDecay() == 0.0f && dispersion != 0.0f)
        {

            float randomScale = (float)(GetTurbulenceScale() * GetTurbulence() * 500.0);

            ParticleC22* pParticle = emitter->GetParticles();

            VectorC22* y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                vForceDirection.X() = pForm.translation.X() - y->x;

                vForceDirection.Y() = pForm.translation[1] - y->Y();

                vForceDirection.Z() = pForm.translation.Z() - y->Z();

                FUN_004a0c10(&vForceDirection);

                VectorC22 vOffset;

                vOffset.x = FUN_006397c0() * randomScale;

                vOffset.y = FUN_006397c0() * randomScale;

                vOffset.z = FUN_006397c0() * randomScale;

                pParticle->GetPosition() +=
                    (fSourceStrength * vForceDirection + vOffset) * (elapsed - pParticle->GetActiveTime());
            }
        }
        else if (GetDecay() != 0.0f && GetTurbulence() == 0.0f)
        {

            VectorC22* y;

            ParticleC22* pParticle;

            pParticle = emitter->GetParticles();

            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                vForceDirection.X() = pForm.translation.X() - y->x;

                vForceDirection.Y() = pForm.translation.Y() - y->Y();

                vForceDirection.Z() = pForm.translation.Z() - y->z;

                float fDecay = DecayExp((float)(-GetDecay() * FUN_00457910(&vForceDirection)));

                float s = fDecay * fSourceStrength * (elapsed - pParticle->GetActiveTime());
                pParticle->GetPosition() += vForceDirection * s;
            }
        }
        else if (GetDecay() != 0.0f && dispersion != 0.0f)
        {

            ParticleC22* pParticle = emitter->GetParticles();

            VectorC22* y;

            y = emitter->GetSourcePositions();

            float randomScale;
            randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                VectorC22 vOffset;

                VectorC22 kIter = vForceDirection * fSourceStrength;

                vOffset.x = FUN_006397c0() * randomScale;

                vOffset.y = FUN_006397c0() * randomScale;

                vOffset.z = FUN_006397c0() * randomScale;

                VectorC22 z = pForm.translation - *y;

                float fDecay;
                fDecay = DecayExp((float)(-GetDecay() * FUN_00457910(&z)));

                pParticle->ApplyMotion(kIter * fDecay + vOffset, elapsed);
            }
        }

        break;
    }
}

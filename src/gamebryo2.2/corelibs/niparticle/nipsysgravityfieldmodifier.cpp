
// src/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream
{
    void GetLoadedObject();
};

struct NiColor
{
    void SaveBinary(NiStream&);
};

struct NiPSysFieldModifier
{
    void SaveBinary(NiStream&);
};

struct NiPSysGravityFieldModifier : NiPSysFieldModifier
{
    NiPSysGravityFieldModifier();
    void FUN_00c267f0(NiStream&);
};

// @fnv 0x00c267f0
void NiPSysGravityFieldModifier::FUN_00c267f0(NiStream& stream)
{
    NiPSysFieldModifier::SaveBinary(stream);
    ((NiColor*)(this + 0x30))->SaveBinary(stream);
}

extern "C"
{
    extern const void* g_01202708;
}

// @fnv 0x00c2a9b0
const void* __cdecl FUN_00c2a9b0()
{
    return &g_01202708;
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);
struct FUN_00c2a9c0_Holder
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00c31750, then deletes this with size 0x48 when bit 0 of a1 is set, and returns this.
// @fnv 0x00c2a9c0
void* FUN_00c2a9c0_Holder::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x48);
    return this;
}

struct CloningProcess
{
};
struct NiObject
{
};
struct NiPoint3
{
    float x;
    float y;
    float z;
    void ComputeMagnitude();
};
struct BSFadeNode
{
    void* __cdecl operator new(unsigned int);
};
struct CtorHelper
{
    NiPSysGravityFieldModifier* Ctor();
};
struct CopyHelper
{
    void FUN_00c32020(NiPSysGravityFieldModifier*, CloningProcess&);
};
struct CloneHelper
{
    NiObject* Clone(CloningProcess&);
};
// @fnv 0x00c2ac50
NiObject* CloneHelper::Clone(CloningProcess& kCloning)
{
    NiPSysGravityFieldModifier* pkObject;
    void* pMemory = BSFadeNode::operator new(0x48);
    if (pMemory)
        pkObject = ((CtorHelper*)pMemory)->Ctor();
    else
        pkObject = 0;
    ((CopyHelper*)this)->FUN_00c32020(pkObject, kCloning);
    *(NiPoint3*)((char*)pkObject + 0x30) = *(NiPoint3*)((char*)this + 0x30);
    *(NiPoint3*)((char*)pkObject + 0x3c) = *(NiPoint3*)((char*)this + 0x30);
    ((NiPoint3*)((char*)pkObject + 0x3c))->ComputeMagnitude();
    return (NiObject*)pkObject;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

// @fnv 0x00c2aa50
NiPSysGravityFieldModifier* __cdecl CreateGravityFieldModifier()
{
    void* memory = A51BF0Base::operator new(0x48);
    if (memory != 0)
        return reinterpret_cast<CtorHelper*>(memory)->Ctor();

    return 0;
}

struct S_00c26db0_Vec
{
    int unk00;
    int unk04;
    int unk08;
    char FUN_00439090(const S_00c26db0_Vec* other);
};
struct S_00c26db0_Base
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
    bool FUN_00c32060(S_00c26db0_Base* other);
};
struct S_00c26db0_Obj : S_00c26db0_Base
{
    S_00c26db0_Vec m_v;
    char FUN_00c26db0(S_00c26db0_Obj* other);
};
// @fnv 0x00c26db0
char S_00c26db0_Obj::FUN_00c26db0(S_00c26db0_Obj* other)
{
    if (!FUN_00c32060(other))
        return 0;
    return !other->m_v.FUN_00439090(&m_v);
}

extern "C" float DAT_011a9478;
extern "C" float DAT_011a947c;
extern "C" float DAT_011a9480;
extern "C" int DAT_010bf2ac;

struct GravityBaseCtor
{
    void FUN_00c31ff0();
};

struct GravityFieldLayout
{
    void* vfptr;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    NiPoint3 originalDirection;
    NiPoint3 normalizedDirection;
};

// @fnv 0x00c2a9e0
NiPSysGravityFieldModifier* CtorHelper::Ctor()
{
    reinterpret_cast<GravityBaseCtor*>(this)->FUN_00c31ff0();
    GravityFieldLayout* fields = reinterpret_cast<GravityFieldLayout*>(this);
    fields->vfptr = &DAT_010bf2ac;
    NiPoint3 direction = {-DAT_011a9478, -DAT_011a947c, -DAT_011a9480};
    fields->originalDirection = direction;
    fields->normalizedDirection = direction;
    fields->normalizedDirection.ComputeMagnitude();
    return reinterpret_cast<NiPSysGravityFieldModifier*>(this);
}

struct FUN_00c2aa70_Base : NiPSysFieldModifier
{
    void LoadBinary(NiStream& s);
};

struct FUN_00c2aa70_Vec : NiPoint3
{
    void LoadBinary(NiStream& s);
};

struct FUN_00c2aa70_Unit
{
    void FUN_004a0c10();
};

struct FUN_00c2aa70_Class : NiPSysGravityFieldModifier
{
    void FUN_00c2aa70(NiStream& s);
};

// Loads the base modifier and a NiPoint3 from the stream, copies the point to offset 0x3c and calls FUN_004a0c10 on it.
// @fnv 0x00c2aa70
void FUN_00c2aa70_Class::FUN_00c2aa70(NiStream& aStream)
{
    ((FUN_00c2aa70_Base*)this)->LoadBinary(aStream);
    FUN_00c2aa70_Vec* a = (FUN_00c2aa70_Vec*)((char*)this + 0x30);
    a->LoadBinary(aStream);
    volatile unsigned int* src = (volatile unsigned int*)((char*)this + 0x30);
    src[0] = src[0];
    src[1] = src[1];
    src[2] = src[2];
    NiPoint3* b = (NiPoint3*)((char*)this + 0x3c);
    *b = *(NiPoint3*)a;
    ((FUN_00c2aa70_Unit*)b)->FUN_004a0c10();
}

struct FUN_00c322b0_Obj
{
    void __thiscall GetViewerStrings(NiStream* stream);
};

struct FUN_00c2af80_Array
{
    void* unk00;
    void* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void __thiscall FUN_0096ad30(unsigned int size);
    void __thiscall FUN_0096ae90(unsigned int index, void** item);
};

struct FUN_00a59af0_Point
{
    float x;
    float y;
    float z;

    void* __thiscall FUN_00a59af0(const char* value);
};

void* __cdecl FUN_00a7d330(void* value);

struct FUN_00c2af80_Obj
{
    void __thiscall GetViewerStrings(NiStream* stream);
};

// @fnv 0x00c2af80
void __thiscall FUN_00c2af80_Obj::GetViewerStrings(NiStream* stream)
{
    reinterpret_cast<FUN_00c322b0_Obj*>(this)->GetViewerStrings(stream);

    FUN_00c2af80_Array* array = reinterpret_cast<FUN_00c2af80_Array*>(stream);

    void* item = FUN_00a7d330(const_cast<void*>(g_01202708));

    unsigned int count = array->unk0A;
    if (count >= array->unk08)
        array->FUN_0096ad30(array->unk0E + count);
    array->FUN_0096ae90(count, &item);

    item = reinterpret_cast<FUN_00a59af0_Point*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00a59af0("Direction");

    count = array->unk0A;
    if (count >= array->unk08)
        array->FUN_0096ad30(array->unk0E + count);
    array->FUN_0096ae90(count, &item);
}

struct Vec3
{
    float x;
    float y;
    float z;
    Vec3()
    {}
    Vec3(float fx, float fy, float afDepth)
    {
        x = fx;
        y = fy;
        z = afDepth;
    }
    Vec3 operator*(float s) const
    {
        return Vec3(x * s, y * s, z * s);
    }
    Vec3& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    Vec3& operator+=(const Vec3& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    void Unitize();
};
inline Vec3 operator*(float s, const Vec3& p)
{
    Vec3 r;
    r.x = s * p.x;
    r.y = s * p.y;
    r.z = s * p.z;
    return r;
}
struct ThreeByThreeMatrix
{
    float m[3][3];
    Vec3 operator*(const Vec3& p) const
    {
        return Vec3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z, m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                    m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    Vec3 m_kTranslation;
    float m_fScale;
    NiTransform operator*(const NiTransform& t) const;
    void InvertInto(NiTransform& out) const;
};
struct NiAVObjectStub
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
    NiTransform GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
};
struct Point3ParameterData
{
    Vec3 m_kValue;
    int unk0C;
    int unk10;
    float m_fZValue;
    int unk18;
};
struct NiPSysDataStub
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
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    Point3ParameterData* m_pkParticleInfo;
};
struct GravityFieldStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiAVObjectStub* m_pkTarget;
    int unk14;
    NiAVObjectStub* m_pkFieldObject;
    float m_fInfluence;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Vec3 m_kLightVector;
    void ApplyGravityToParticles(float fTime, NiPSysDataStub* pkData);
};

// @fnv 0x00c2aac0
void GravityFieldStub::ApplyGravityToParticles(float fTime, NiPSysDataStub* pkData)
{
    NiTransform kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInv;
    {
        NiTransform kPSys = m_pkTarget->m_kWorldSpaceTransform;
        kPSys.InvertInto(kInv);
    }
    Vec3 kAccel;
    {
        NiTransform kX = kInv * kField;
        Vec3 kDirection = kX.m_kOrientation * m_kLightVector;
        kDirection.Unitize();
        kDirection *= m_fInfluence;
        kAccel = kDirection;
    }
    for (unsigned short i = 0; i < pkData->m_usActiveVertices; i++)
    {
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[i];
        float fTimeSinceScaleStart = fTime - pkInfo->m_fZValue;
        if (fTimeSinceScaleStart != 0.0f)
        {
            Vec3 change = kAccel * fTimeSinceScaleStart;
            Vec3& velocity = pkInfo->m_kValue;
            velocity.x += change.x;
            float fVelocityY = velocity.y;
            velocity.y = fVelocityY + change.y;
            velocity.z += change.z;
        }
    }
}

#include <math.h>
struct Point141
{
    float x, y, z;
    Point141 operator-(const Point141& p) const
    {
        Point141 r;
        r.x = x - p.x;
        r.y = y - p.y;
        r.z = z - p.z;
        return r;
    }
    Point141()
    {}
    Point141(float fx, float fy, float afDepth)
    {
        x = fx;
        y = fy;
        z = afDepth;
    }
    Point141 operator*(float f) const
    {
        return Point141(f * x, f * y, f * z);
    }
    Point141& operator+=(const Point141& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    friend Point141 operator*(float f, const Point141& p)
    {
        Point141 r;
        r.x = f * p.x;
        r.y = f * p.y;
        r.z = f * p.z;
        return r;
    }
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
};
struct Matrix141
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Point141 FUN_004b4500(const Point141*) const;
    Point141 operator*(const Point141& p) const
    {
        return FUN_004b4500(&p);
    }
};
struct Transform141
{
    Matrix141 rotation;
    Point141 translation;
    float scale;
    void FUN_004b4880(Transform141*) const;
    Transform141 FUN_0062c250(const Transform141&) const;
};
struct Node141
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
    Transform141 world;
};
struct Particle141
{
    Point141 velocity;
    float unk0c, unk10, lastTime, unk18;
};
struct Data141
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Point141* positions;
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
    unsigned short count, unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle141* particles;
};
struct Field141
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Node141* owner;
    int unk14;
    Node141* field;
    float strength;
    float attenuation;
    bool volume;
    unsigned char unk25, unk26, unk27;
    int unk28;
    float radiusSquared;
    int unk30;
    int unk34;
    int unk38;
    Point141 direction;
    void ApplyGravityToParticles(float, Data141*);
    void ApplyForceToParticles(float, Data141*);
};
float FUN_00404010(float, float);
// Applies a directional force to particles within the field, scaling by strength, time delta, and optional distance attenuation or volume radius.
// @fnv 0x00c2acb0
void Field141::ApplyForceToParticles(float time, Data141* data)
{
    if (strength == 0 || data->count == 0 || !field)
        return;
    if (!volume && attenuation == 0)
    {
        ApplyGravityToParticles(time, data);
        return;
    }
    Transform141 fieldWorld;
    fieldWorld = field->world;
    Transform141 inverse;
    {
        Transform141 world = owner->world;
        world.FUN_004b4880(&inverse);
    }
    {
        Transform141 world = inverse.FUN_0062c250(fieldWorld);
        float halfAttenuation = 0.5 * attenuation;
        Point141 forceDirection;
        forceDirection = world.rotation * direction;
        for (unsigned short i = 0; i < data->count; i++)
        {
            Particle141& particle = data->particles[i];
            float delta = time - particle.lastTime;
            if (!delta)
                continue;
            Point141 position = data->positions[i];
            Point141 offset = position - world.translation;
            float distanceSquared = offset.SquaredLength();
            if (volume && !(radiusSquared >= distanceSquared))
                continue;
            Point141 change;
            if (attenuation == 0.0f || distanceSquared == 0.0f)
            {
                change = forceDirection * (strength * delta);
            }
            else
            {
                float scale = strength * delta / FUN_00404010(1.0f, (float)pow(distanceSquared, halfAttenuation));
                const Point141& dir = forceDirection;
                const double& wide = scale;
                change = Point141(wide * dir.x, scale * dir.y, scale * dir.z);
            }
            particle.velocity += change;
        }
    }
}

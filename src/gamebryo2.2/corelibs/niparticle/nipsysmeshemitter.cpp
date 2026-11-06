
// src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int g_01202500;

// @fnv 0x00c1f4f0
int* __cdecl FUN_00c1f4f0()
{
    return &g_01202500;
}

struct NiAVObject;
struct NiPSysVolumeEmitter
{
    NiPSysVolumeEmitter();
    void FUN_00c1fa30(NiAVObject* pkEmitterObj);
};

// @fnv 0x00c1fa30
void NiPSysVolumeEmitter::FUN_00c1fa30(NiAVObject* pkEmitterObj)
{
    *(NiAVObject**)((char*)this + 0x54) = pkEmitterObj;
}

extern void* g_01202508;

// @fnv 0x00c1fa40
void* __cdecl FUN_00c1fa40()
{
    return &g_01202508;
}

struct NiPSysCylinderEmitter : NiPSysVolumeEmitter
{
    float m_fCylinderRadius;
    float m_fCylinderHeight;
    bool __thiscall FUN_00c31b80(NiAVObject* pkObject);
    bool __thiscall FUN_00c1f9e0(NiAVObject* pkObject);
};
// @fnv 0x00c1f9e0
bool __thiscall NiPSysCylinderEmitter::FUN_00c1f9e0(NiAVObject* pkObject)
{
    NiPSysCylinderEmitter* pkDest = (NiPSysCylinderEmitter*)pkObject;
    if (FUN_00c31b80(pkObject) && ((float*)((char*)this + 0x58))[0] == ((float*)((char*)pkDest + 0x58))[0] &&
        ((float*)((char*)this + 0x5c))[0] == ((float*)((char*)pkDest + 0x5c))[0])
        return true;
    return false;
}

extern double DAT_01011588;
extern double DAT_01016ff0;
// @fnv 0x00c1ced0
float FUN_00c1ced0(float number)
{
    float y = number;
    float fHalfX = number * DAT_01011588;
    int i = *(int*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (DAT_01016ff0 - (fHalfX * y * y));
    y = number * y;
    return y;
}

void __cdecl ReleaseObjectArray(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010bd698;
extern int DAT_010bd6a0;
struct Holder31750
{
    void __thiscall FUN_00c31750();
};
struct NiPSysMeshEmitter
{
    char _pad0[0x54];
    void* m_54;
    void* m_58;
    char _pad1[0x64 - 0x5C];
    void* m_64;
    void* m_68;
    char _pad2[0x88 - 0x6C];
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00c1f500
void* __thiscall NiPSysMeshEmitter::Destroy(unsigned int flags)
{
    void* tmp1 = m_68;
    m_64 = (void*)&DAT_010bd6a0;
    ReleaseObjectArray(tmp1);
    void* tmp2 = m_58;
    m_54 = (void*)&DAT_010bd698;
    ReleaseObjectArray(tmp2);
    ((Holder31750*)this)->FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x88);
    return this;
}

namespace fnv_00c1f990 {
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
    unsigned int GetLinkID();
    NiObject* GetLoadedObject();
};
struct NiPSysEmitter
{
    virtual void LinkObject(NiStream&);
};
struct NiGeometry;
struct NiPSysMeshEmitter : NiPSysEmitter
{
    char _pad_4[0x50];
    struct GeomEmitterArray
    {
        void FUN_00c1e9a0(unsigned int);
    } m_kGeometryEmitters;
    void SetSkinGeom(NiGeometry*);
    void FUN_00c1f990(NiStream&);
};
// @fnv 0x00c1f990
void NiPSysMeshEmitter::FUN_00c1f990(NiStream& kStream)
{
    NiPSysEmitter::LinkObject(kStream);
    unsigned int uiSize = kStream.GetLinkID();
    unsigned int i;
    NiGeometry* pkChild;
    if (uiSize != 0)
    {
        m_kGeometryEmitters.FUN_00c1e9a0(uiSize);
        for (i = 0; i < uiSize; i++)
        {
            pkChild = (NiGeometry*)kStream.GetLoadedObject();
            SetSkinGeom(pkChild);
        }
    }
}
}  // namespace fnv_00c1f990

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiSkinnedEmitterData
{
    char _pad[4];
};

struct NiGeometry
{
    char _pad[0xBC];
    NiSkinnedEmitterData* m_bc;
};

struct NiSkinInstance
{
    char _pad[8];
    int m_kPointB;
    void __thiscall EnsureSkinPartition(NiGeometry* pkGeometry);
};

int __cdecl GetRandomNumber(void);
extern double DAT_01029790;

struct FUN_00c1f5f0_shell : NiPSysMeshEmitter
{
    void __thiscall PickRandomVertex(NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall PickEmitterParticle(NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall GetRandomEmitterParticle(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall FUN_00c1e080(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall FUN_00c1e4e0(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall EmitFromMesh(NiGeometry*, NiPoint3&, NiPoint3&);

    void __thiscall FUN_00c1f5f0(NiPoint3& kPosition, NiPoint3& kMotionVelocity);
};

// @fnv 0x00c1f5f0
void __thiscall FUN_00c1f5f0_shell::FUN_00c1f5f0(NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    unsigned int uiEmitterIndex;
    NiGeometry* pkGeomEmitter;
    unsigned int uiGeometryEmitterCount;
    NiSkinInstance* pkSkin;
    NiSkinnedEmitterData* pkEmitData;

    uiGeometryEmitterCount = *(unsigned short*)((char*)this + 0x60);
    if (!uiGeometryEmitterCount)
        return;

    {
        float fRandom = GetRandomNumber() / DAT_01029790;
        uiEmitterIndex = (unsigned int)(fRandom * uiGeometryEmitterCount);
    }

    if (uiEmitterIndex == uiGeometryEmitterCount)
        uiEmitterIndex = uiGeometryEmitterCount - 1;

    if (uiEmitterIndex >= *(unsigned short*)((char*)this + 0x60))
        return;

    pkGeomEmitter = ((NiGeometry**)m_58)[uiEmitterIndex];
    if (!pkGeomEmitter)
        return;

    pkEmitData = pkGeomEmitter->m_bc;

    if (uiEmitterIndex < *(unsigned short*)((char*)this + 0x70))
        pkSkin = ((NiSkinInstance**)m_68)[uiEmitterIndex];
    else
        pkSkin = 0;

    if (pkEmitData && pkSkin && !pkSkin->m_kPointB)
        pkSkin->EnsureSkinPartition(pkGeomEmitter);

    switch (*(int*)((char*)this + 0x78))
    {
    case 1:
    case 3:
        if (pkEmitData)
        {
            FUN_00c1e080(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        EmitFromMesh(pkGeomEmitter, kPosition, kMotionVelocity);
        return;

    case 2:
    case 4:
        if (pkEmitData)
        {
            FUN_00c1e4e0(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        PickEmitterParticle(pkGeomEmitter, kPosition, kMotionVelocity);
        return;

    default:
        if (pkEmitData)
        {
            GetRandomEmitterParticle(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        PickRandomVertex(pkGeomEmitter, kPosition, kMotionVelocity);
        return;
    }
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct SkinData_c1d170
{
    int unk[17];
    unsigned int m_uiBoneCount;
};

struct Partition_c1d170
{
    int unk[4];
    Partition_c1d170() throw();
    bool MakePartitions(void* pkModelData, SkinData_c1d170* pkSkinData, unsigned int uiBonesPerPartition,
                        unsigned int uiBonesPerVertex, unsigned int uiStart, bool bForce, bool barg7, bool barg8);
    static void* __cdecl operator new(unsigned int s) throw()
    {
        return FUN_00aa13e0(s);
    }
};

struct SkinInst_c1d170
{
    int unk00;
    int unk04;
    SkinData_c1d170* m_pSkinData;
    Partition_c1d170* m_pkSkinMeshPartition;
};

struct Geom_c1d170
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* v7();
    int unk[45];
    void* m_pkModelData;
    SkinInst_c1d170* m_spSkinningInstance;
};

struct Ptr_c1d170
{
    Partition_c1d170* m_pObject;
    Ptr_c1d170& operator=(Partition_c1d170* p);
};

struct Host_c1d170
{
    int unk00;
    int unk04;
    Ptr_c1d170 m_spPartition;
    bool EnsureSkinPartition(Geom_c1d170* pkGeometry);
};

// Validates the geometry and its skin instance, builds a partition from the skin data if missing, stores it in m_spPartition and returns whether it succeeded.
// @fnv 0x00c1d170
bool Host_c1d170::EnsureSkinPartition(Geom_c1d170* pkGeometry)
{
    if (!pkGeometry || !pkGeometry->v7())
        return false;
    SkinInst_c1d170* pkSkin = pkGeometry->m_spSkinningInstance;
    if (pkSkin)
    {
        Partition_c1d170* pkPartition = pkSkin->m_pkSkinMeshPartition;
        if (!pkPartition)
        {
            if (!pkSkin->m_pSkinData)
                return false;
            unsigned int uiBonesPerPartition = pkSkin->m_pSkinData->m_uiBoneCount;
            if (uiBonesPerPartition < 4)
                uiBonesPerPartition = 4;
            pkPartition = new Partition_c1d170();
            if (!pkPartition->MakePartitions(pkGeometry->m_pkModelData, pkSkin->m_pSkinData, uiBonesPerPartition, 4, 0,
                                             false, false, false))
                return false;
        }
        m_spPartition = pkPartition;
        return true;
    }
    return false;
}

class C1E8E0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C1E8E0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C1E8E0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C1E8E0Object;

class NiStream
{
  public:
    virtual void unk00();
    virtual void unk04();
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
    virtual void SaveLinkID(C1E8E0Object* pkObject);
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
    C1E8E0BinaryStream* m_pBackingStream;
};

template <class T>
inline void C1E8E0BinaryStreamSave(C1E8E0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C1E8E0SaveBinary(NiStream& kStream, const T& value)
{
    C1E8E0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class NiColorSaveHelper
{
  public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};

class Stub_00c31b60
{
  public:
    void* m_ppVirtualMethodTable;
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

    void FUN_00c22530(void* pkStream);
};

class C1E8E0Controller : public Stub_00c31b60
{
  public:
    C1E8E0Object** m_ppkObjects;
    unsigned short unk5C;
    unsigned short m_usObjectCount;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    float m_fValue0;
    float m_fValue1;
    NiColorSaveHelper m_kFogTint;

    void FUN_00c1e8e0(NiStream& kStream);
};

// Writes the object count, each object's link ID, m_fValue0, m_fValue1 and the color helper to the stream.
// @fnv 0x00c1e8e0
void C1E8E0Controller::FUN_00c1e8e0(NiStream& kStream)
{
    FUN_00c22530(&kStream);
    unsigned int uiObjectCount = m_usObjectCount;
    C1E8E0SaveBinary(kStream, uiObjectCount);
    for (unsigned int i = 0; i < uiObjectCount; i++)
        kStream.SaveLinkID(m_ppkObjects[i]);
    C1E8E0SaveBinary(kStream, m_fValue0);
    C1E8E0SaveBinary(kStream, m_fValue1);
    m_kFogTint.SaveBinary(kStream);
}

struct NiPoint3b
{
    float x, y, z;
    void FUN_004a0c10();
    NiPoint3b operator*(float f) const
    {
        NiPoint3b v = {x * f, y * f, z * f};
        return v;
    }
    NiPoint3b& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
};
struct M_004b4500
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3b FUN_004b4500(const NiPoint3b* v);
};
struct NiTransform
{
    M_004b4500 rotation;
    NiPoint3b translation;
    float scale;
    void FUN_004b4880(NiTransform& result);
    void FUN_0062c250(NiTransform& result, const NiTransform& other) const;
    NiPoint3b FUN_00524c40(const NiPoint3b* v);
};
struct NiAVObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    NiTransform world;
};
struct MeshEmitter_c1cf50
{
    int unk00, unk04, unk08, unk0c;
    NiAVObject* object;
    int unk14;
    float speed, speedVariation;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70;
    int velocityMode;
    int unk78;
    NiPoint3b direction;
    void ComputeEmitterParticleTransform(NiAVObject* geometry, NiPoint3b& position, NiPoint3b& velocity);
};
// Transforms position into the emitter object's space and computes velocity from velocityMode using the geometry's world transform and random values.
// @fnv 0x00c1cf50
void MeshEmitter_c1cf50::ComputeEmitterParticleTransform(NiAVObject* geometry, NiPoint3b& arPosition,
                                                         NiPoint3b& arVelocity)
{
    if (!geometry)
        return;
    NiTransform geometryWorld = geometry->world;
    NiTransform transform = object->world;
    NiTransform inverseWorld;
    transform.FUN_004b4880(inverseWorld);
    inverseWorld.FUN_0062c250(transform, geometryWorld);
    arPosition = transform.FUN_00524c40(&arPosition);
    switch (velocityMode)
    {
    case 0:
        arVelocity = transform.rotation.FUN_004b4500(&arVelocity);
        break;
    case 1:
        arVelocity.x = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.y = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.z = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.FUN_004a0c10();
        {
            float random = (float)(GetRandomNumber() / DAT_01029790);
            float magnitude = speed + speedVariation * (random - DAT_01011588);
            arVelocity *= magnitude;
        }
        break;
    case 2: {
        NiPoint3b v = transform.rotation.FUN_004b4500(&direction);
        float random = (float)(GetRandomNumber() / DAT_01029790);
        float magnitude = speed + speedVariation * (random - DAT_01011588);
        v.FUN_004a0c10();
        arVelocity = v * magnitude;
    }
    break;
    }
}

struct Vec3_c1f880
{
    int x;
    int y;
    int z;
};

struct Sub54_c1f880
{
    int unk00;
    void FUN_00c1e9a0(unsigned short arg);
};

struct Emit_c1f880
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
    Sub54_c1f880 unk54;
    int unk58;
    unsigned short unk5C;
    unsigned short unk5E;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    Vec3_c1f880 vec7C;
    Emit_c1f880* FUN_00c1f550();
    void CopyTo(Emit_c1f880* pkEmitter, unsigned int uiArg);
    Emit_c1f880* FUN_00c1f880(unsigned int uiArg);
};

// @fnv 0x00c1f880
Emit_c1f880* Emit_c1f880::FUN_00c1f880(unsigned int uiArg)
{
    Emit_c1f880* pkNew = (Emit_c1f880*)FUN_00aa13e0(0x88);
    Emit_c1f880* pkResult;
    if (pkNew != 0)
    {
        pkResult = pkNew->FUN_00c1f550();
    }
    else
    {
        pkResult = 0;
    }
    CopyTo(pkResult, uiArg);
    pkResult->unk54.FUN_00c1e9a0(unk5E);
    pkResult->unk74 = unk74;
    pkResult->unk78 = unk78;
    pkResult->vec7C = vec7C;
    return pkResult;
}

// Factory: allocates a 0x88-byte NiPSysMeshEmitter and runs its out-of-line constructor (FUN_00c1f550).
struct NiPSysMeshEmitterObject
{
    static void* __cdecl operator new(unsigned int);
    NiPSysMeshEmitterObject() throw();
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};

// @fnv 0x00c1f970
NiPSysMeshEmitterObject* __cdecl CreateNiPSysMeshEmitterObject()
{
    return new NiPSysMeshEmitterObject;
}

extern "C" void __cdecl FUN_00c31750();

// @fnv 0x00c1fa20
void __cdecl FUN_00c1fa20()
{
    FUN_00c31750();
}

struct BoneTransformD230
{
    float m_00;
    float m_01;
    float m_02;
    float m_10;
    float m_11;
    float m_12;
    float m_20;
    float m_21;
    float m_22;
    NiPoint3 m_translate;
    float m_fScale;
    BoneTransformD230 __thiscall operator*(const BoneTransformD230& rhs) const;
};
struct Sub4880
{
    void __thiscall FUN_004b4880(void* p);
};
struct Holder68
{
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
    Sub4880 m_68;
};
struct BoneEntry
{
    BoneTransformD230 transform;
    NiPoint3 center;
    float radius;
    unsigned short count;
    unsigned short flags;
    void* weights;
};
struct BoneHead
{
    int m_00;
    int m_04;
    int m_08;
    BoneTransformD230 m_0c;
    BoneEntry* m_40;
};
struct ArrObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPoint3* m_20;
    NiPoint3* m_24;
};
struct Arg3Obj
{
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
    ArrObj* m_b8;
};
struct SceneBone
{
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
    BoneTransformD230 world;
};
struct Arg4Obj
{
    void* m_00;
    void* m_04;
    BoneHead* m_08;
    void* m_0c;
    Holder68* m_10;
    SceneBone** m_14;
};
struct Arg5Obj
{
    int m_00;
    unsigned short* m_04;
    float* m_08;
    unsigned short* m_0c;
    unsigned char* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    unsigned short m_24;
};
extern NiPoint3 DAT_011f426c;
struct AccObj
{
    NiPoint3 a1;
    NiPoint3 a2;
    __declspec(noalias) void __thiscall FUN_004a0c10();
};
struct LoopPair
{
    NiPoint3 first;
    NiPoint3 second;
};
struct Mat3
{
    float m[9];
};
NiPoint3 operator*(const NiPoint3& a, float f)
{
    NiPoint3 r;
    r.x = a.x * f;
    r.y = a.y * f;
    r.z = a.z * f;
    return r;
}
NiPoint3& operator+=(NiPoint3& a, const NiPoint3& b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
void scale(NiPoint3& r, const NiPoint3& a, float f)
{
    r.x = a.x * f;
    r.y = a.y * f;
    r.z = a.z * f;
}
// Accumulates weighted transformed positions and normals for the selected vertex, then writes the results to the output vectors.
// @fnv 0x00c1d230
void __stdcall SkinVertex(NiPoint3* outPos, NiPoint3* outVel, Arg3Obj* arg3, Arg4Obj* arg4, Arg5Obj* arg5, int vert)
{
    BoneHead* skin = arg4->m_08;
    BoneTransformD230 c;
    arg4->m_10->m_68.FUN_004b4880((void*)&c);
    BoneTransformD230 ptr;
    ptr = skin->m_0c * c;
    BoneEntry* bones = skin->m_40;
    AccObj acc;
    LoopPair scratch;
    acc.a2 = DAT_011f426c;
    acc.a1 = DAT_011f426c;
    const ArrObj* __restrict pwv = arg3->m_b8;
    const NiPoint3* positions = pwv->m_20;
    const NiPoint3* normals = pwv->m_24;
    unsigned int loopT = arg5->m_0c[vert];
    NiPoint3 pForm;
    pForm = positions[loopT];
    NiPoint3 cnt;
    if (normals)
    {
        cnt = normals[loopT];
    }
    else
    {
        NiPoint3 fallback;
        fallback.x = 1.0f;
        fallback.y = 0.0f;
        fallback.z = 0.0f;
        cnt = fallback;
    }
    unsigned long idx;
    idx = arg5->m_24;
    unsigned int r = 0;
    if (0 < idx)
    {
        do
        {
            unsigned short bindDir;
            if (arg5->m_10)
            {
                bindDir = arg5->m_04[arg5->m_10[idx * vert + r]];
            }
            else
            {
                bindDir = arg5->m_04[r];
            }
            BoneTransformD230* res = &arg4->m_14[bindDir]->world;
            BoneTransformD230* wv = &bones[bindDir].transform;
            Mat3 ls;
            c = (ptr * *res) * *wv;
            BoneTransformD230& a = c;
            Mat3& elemT = ls;
            elemT.m[0] = a.m_00 * a.m_fScale;
            elemT.m[1] = a.m_01 * a.m_fScale;
            elemT.m[2] = a.m_02 * a.m_fScale;
            elemT.m[3] = a.m_10 * a.m_fScale;
            elemT.m[4] = a.m_11 * a.m_fScale;
            elemT.m[5] = a.m_12 * a.m_fScale;
            elemT.m[6] = a.m_20 * a.m_fScale;
            elemT.m[7] = a.m_21 * a.m_fScale;
            elemT.m[8] = a.m_22 * a.m_fScale;
            float val = arg5->m_08[vert * 4 + r];
            NiPoint3 accB;
            accB.x = elemT.m[0] * pForm.x + elemT.m[1] * pForm.y + elemT.m[2] * pForm.z + a.m_translate.x;
            accB.y = elemT.m[3] * pForm.x + elemT.m[4] * pForm.y + elemT.m[5] * pForm.z + a.m_translate.y;
            accB.z = elemT.m[6] * pForm.x + elemT.m[7] * pForm.y + elemT.m[8] * pForm.z + a.m_translate.z;
            scratch.second.x = a.m_00 * cnt.x + a.m_01 * cnt.y + a.m_02 * cnt.z;
            scratch.second.y = cnt.x * a.m_10 + a.m_11 * cnt.y + a.m_12 * cnt.z;
            scratch.second.z = a.m_20 * cnt.x + a.m_21 * cnt.y + a.m_22 * cnt.z;
            scale(scratch.first, accB, val);
            acc.a2 += scratch.first;
            NiPoint3 kIter;
            kIter = scratch.second * val;
            acc.a1 += kIter;
            ++r;
            idx = arg5->m_24;
        } while (r < idx);
    }
    acc.FUN_004a0c10();
    *outPos = acc.a2;
    *outVel = acc.a1;
}

namespace fnv_00c1dec0 {
struct GeometryVirtual
{
    virtual void virt00();
    virtual void virt04();
    virtual void virt08();
    virtual void virt0c();
    virtual void virt10();
    virtual void virt14();
    virtual void virt18();
    virtual int IsReady();
};
struct SkinRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short vertexCount;
    unsigned short unk1e;
    int unk20, unk24, unk28;
};
struct SkinContainer
{
    int unk00, unk04;
    unsigned short recordCount, unk0a;
    SkinRecord* records;
};
struct GeometryExtra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int hasData;
};
struct SkinGeometry : GeometryVirtual
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    GeometryExtra* extra;
    NiSkinnedEmitterData* emitterData;
};
struct SkinInst
{
    int unk00, unk04;
    SkinContainer* container;
};
extern int __cdecl FUN_00ecadb8();
inline float UnitRandom()
{
    return float(double(FUN_00ecadb8()) / DAT_01029790);
}
struct Point3
{
    float x, y, z;
    float __thiscall FUN_00457990() const;
    float Length() const
    {
        return FUN_00457990();
    }
};
extern Point3 DAT_011f426c;
Point3 __cdecl FUN_004a3760(float, const Point3&);
struct SkinEmitter
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    void __thiscall SkinVertex(Point3*, Point3*, SkinGeometry*, NiSkinnedEmitterData*, SkinRecord*, int);
    void __thiscall ComputeEmitterParticleTransform(SkinGeometry*, Point3&, Point3&);
    bool GetRandomEmitterParticle(SkinInst* skin, SkinGeometry* geometry, Point3& position, Point3& velocity);
};
// Picks a random skin record and vertex, computes a particle position and velocity, and transforms them into emitter space.
// @fnv 0x00c1dec0
bool SkinEmitter::GetRandomEmitterParticle(SkinInst* skin, SkinGeometry* geometry, Point3& position, Point3& velocity)
{
    if (!geometry || !geometry->IsReady())
        return false;
    SkinContainer* container = skin->container;
    if (!container)
        return false;
    unsigned short count = container->recordCount;
    float randomRecord = UnitRandom();
    int recordIndex = (int)(unsigned int)(randomRecord * count);
    if (recordIndex >= int(count) - 1)
        recordIndex = int(count) - 1;
    SkinRecord* record = &skin->container->records[recordIndex];
    float randomVertex = UnitRandom();
    NiSkinnedEmitterData* data = geometry->emitterData;
    if (!data)
        return false;
    {
        Point3 localVelocity;
        {
            Point3 localPosition = DAT_011f426c;
            localVelocity = DAT_011f426c;
            SkinVertex(&localPosition, &localVelocity, geometry, data, record,
                       (int)(unsigned int)((record->vertexCount - 1) * randomVertex));
            position = localPosition;
        }
        if (unk74 == 0 && geometry->extra->hasData != 0)
        {
            float length = velocity.Length();
            velocity = FUN_004a3760(length, localVelocity);
        }
    }
    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}
}  // namespace fnv_00c1dec0

int __cdecl FUN_00ecadb8();
float __cdecl FUN_00639780();
void __cdecl FUN_00525340(NiPoint3*);
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
extern NiPoint3 NiPoint3_ZERO;

struct Partition
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short* m_pusTriList;
    int unk18;
    unsigned short unk1C;
    unsigned short m_usTriangles;
    unsigned short unk20;
    unsigned short m_usStrips;
    int unk24;
    int unk28;
};

struct MySkinPartition
{
    int unk00;
    int unk04;
    unsigned short m_usPartitions;
    unsigned short unk0A;
    Partition* m_pPartitions;
};

struct MySkinInstance
{
    int unk00;
    int unk04;
    MySkinPartition* m_pkSkinMeshPartition;
};

struct MyGeomVtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* GetModelData();
};

struct MyPoint3 : NiPoint3
{
    MyPoint3()
    {}
    MyPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    MyPoint3 operator+(const MyPoint3& pt) const
    {
        return MyPoint3(x + pt.x, y + pt.y, z + pt.z);
    }
    MyPoint3 operator-(const MyPoint3& pt) const
    {
        return MyPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    MyPoint3 operator*(float f) const
    {
        return MyPoint3(x * f, y * f, z * f);
    }
    NiPoint3 __thiscall FUN_0053d280(float) const;
    float __thiscall FUN_00457990();
};

struct EmitterAccessor
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
    int m_iEmissionDirection;
    int m_iEmissionType;

    bool __thiscall GetRandomEmitterParticle(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry,
                                             NiPoint3& kPosition, NiPoint3& kMotionVelocity);
    __declspec(noalias) bool __thiscall SkinVertex(NiPoint3& kPosition, NiPoint3& kNormal, NiGeometry* pkGeometry,
                                                   NiSkinnedEmitterData* pkData, Partition* pkPartition,
                                                   unsigned int m_usVertexId);
    bool __thiscall ComputeEmitterParticleTransform(NiGeometry* pkGeometry, NiPoint3& kPosition,
                                                    NiPoint3& kMotionVelocity);

    bool __thiscall FUN_00c1e4e0(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry, NiPoint3& kPosition,
                                 NiPoint3& kMotionVelocity);
};

// Picks a random skin partition and triangle, samples two vertices and normals, computes a position, and may update motion velocity.
// @fnv 0x00c1e4e0
bool EmitterAccessor::FUN_00c1e4e0(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry, NiPoint3& kPosition,
                                   NiPoint3& kMotionVelocity)
{
    if (!pkGeometry || !((MyGeomVtbl*)pkGeometry)->GetModelData())
        return false;

    if (!((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition)
        return false;

    unsigned short usPartitions = ((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition->m_usPartitions;
    float fRand = (float)(FUN_00ecadb8() / DAT_01029790);
    unsigned int uiPartition = (unsigned int)(fRand * (int)usPartitions);
    int iMaxPartition = (int)usPartitions - 1;
    if ((int)uiPartition >= iMaxPartition)
        uiPartition = iMaxPartition;

    Partition* pkPartition = &((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition->m_pPartitions[uiPartition];
    if (!pkPartition->m_usTriangles)
        return this->GetRandomEmitterParticle(pkSkinInstance, pkGeometry, kPosition, kMotionVelocity);

    unsigned int uiTriangle = (unsigned int)(pkPartition->m_usTriangles * FUN_00639780());
    int iMaxTriangle = (int)pkPartition->m_usTriangles - 1;
    if ((int)uiTriangle >= iMaxTriangle)
        uiTriangle = iMaxTriangle;

    NiSkinnedEmitterData* pkData = pkGeometry->m_bc;
    if (!pkData)
        return false;

    unsigned int usV0, usV1, usV2;
    if (pkPartition->m_usStrips)
    {
        usV0 = pkPartition->m_pusTriList[uiTriangle];
        usV1 = pkPartition->m_pusTriList[uiTriangle + 1];
        usV2 = pkPartition->m_pusTriList[uiTriangle + 2];
    }
    else
    {
        usV0 = pkPartition->m_pusTriList[3 * uiTriangle];
        usV1 = pkPartition->m_pusTriList[3 * uiTriangle + 1];
        usV2 = pkPartition->m_pusTriList[3 * uiTriangle + 2];
    }

    switch (FUN_00ecadb8() % 3)
    {
    case 1:
        usV0 = usV1;
        usV1 = usV2;
        break;
    case 2:
        usV1 = usV2;
        break;
    }

    NiPoint3 kPos0 = NiPoint3_ZERO;
    NiPoint3 kNorm0 = NiPoint3_ZERO;
    NiPoint3 kPos1 = NiPoint3_ZERO;
    NiPoint3 kNorm1 = NiPoint3_ZERO;

    this->SkinVertex(kPos0, kNorm0, pkGeometry, pkData, pkPartition, usV0);
    this->SkinVertex(kPos1, kNorm1, pkGeometry, pkData, pkPartition, usV1);
    {
        NiPoint3 kTmp = ((MyPoint3&)kPos0 + (MyPoint3&)kPos1).FUN_0053d280(2.0f);
        kPosition = kTmp;
    }

    if (this->m_iEmissionDirection == 0)
    {
        NiPoint3 kNormal = ((MyPoint3&)kNorm0 + (MyPoint3&)kNorm1).FUN_0053d280(2.0f);
        FUN_00525340(&kNormal);
        float fSpeed = ((MyPoint3*)&kMotionVelocity)->FUN_00457990();
        kMotionVelocity = FUN_004a3760(fSpeed, kNormal);
    }

    if (this->m_iEmissionType == 4)
    {
        kPosition = ((MyPoint3&)kPos1 - (MyPoint3&)kPos0) * FUN_00639780() + (MyPoint3&)kPos0;
    }

    this->ComputeEmitterParticleTransform(pkGeometry, kPosition, kMotionVelocity);
    return true;
}

extern int g_01202500;
struct EmitterObject
{
    int unk00;
    int unk04;
    const char* m_kName;
};

struct NiViewerStringsArray
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcString);

    __forceinline unsigned int Add(char* pcString)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcString);
        return uiIndex;
    }

    __forceinline void AddAxis(char* pcString)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        if (uiIndex >= m_usSize)
        {
            m_usSize = uiIndex + 1;
            if (pcString)
                m_usESize++;
        }
        else
        {
            if (pcString)
            {
                if (!m_pBase[uiIndex])
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex])
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = pcString;
    }
};

char* __cdecl FUN_00a7d330(char*);
char* __cdecl FUN_00a7d5e0(const char*, const char*);
char* __cdecl FUN_00a7d550(const char*, float);

struct Standin_VolumeEmitter
{
    void FUN_00c22780(NiViewerStringsArray* pkStrings);
};

struct MeshEmitter
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
    EmitterObject** m_ppkEmitterObjs;
    int unk5c;
    unsigned short m_usNumEmitterObjs;
    unsigned short unk62;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned int m_eInitVelocityType;
    unsigned int m_eEmissionType;
    NiPoint3 m_kEmissionAxis;

    unsigned int GetEmitterObjCount() const
    {
        return m_usNumEmitterObjs;
    }

    EmitterObject* GetEmitterObj(unsigned int i) const
    {
        if (i < m_usNumEmitterObjs)
            return m_ppkEmitterObjs[i];
        return 0;
    }

    void WriteToViewerStrings(NiViewerStringsArray* pkStrings);
};

// Appends emitter object names, emission type, initial velocity type, and emission axis values to pkStrings.
// @fnv 0x00c1f050
void MeshEmitter::WriteToViewerStrings(NiViewerStringsArray* pkStrings)
{
    ((Standin_VolumeEmitter*)this)->FUN_00c22780(pkStrings);

    pkStrings->Add(FUN_00a7d330((char*)g_01202500));

    unsigned int i = 0;
    while (i < GetEmitterObjCount())
    {
        EmitterObject* pkObj = GetEmitterObj(i);
        if (pkObj)
        {
            const char* pcObjName = pkObj->m_kName;
            pkStrings->Add(FUN_00a7d5e0("Emitter Object", pcObjName));
        }
        i++;
    }

    switch (m_eEmissionType)
    {
    case 0:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_VERTICES"));
        break;
    case 1:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_FACE_CENTER"));
        break;
    case 2:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_EDGE_CENTER"));
        break;
    case 3:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_FACE_SURFACE"));
        break;
    case 4:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_EDGE_SURFACE"));
        break;
    default:
        pkStrings->Add(FUN_00a7d5e0("m_eEmissionType", "UNKNOWN!!!"));
        break;
    }

    switch (m_eInitVelocityType)
    {
    case 0:
        pkStrings->Add(FUN_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_NORMALS"));
        break;
    case 1:
        pkStrings->Add(FUN_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_RANDOM"));
        break;
    case 2:
        pkStrings->Add(FUN_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_DIRECTION"));
        break;
    default:
        pkStrings->Add(FUN_00a7d5e0("m_eInitVelocityType", "UNKNOWN!!!"));
        break;
    }

    pkStrings->AddAxis(FUN_00a7d550("m_kEmissionAxis.x", m_kEmissionAxis.x));
    pkStrings->AddAxis(FUN_00a7d550("m_kEmissionAxis.y", m_kEmissionAxis.y));
    pkStrings->AddAxis(FUN_00a7d550("m_kEmissionAxis.z", m_kEmissionAxis.z));
}

struct CmpItem
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool vCompare(CmpItem* other);
};

struct CmpSub
{
    bool FUN_00439090(void* other);
};

struct FUN_00c1d6b0_cls
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
    CmpItem** m_58;
    short unk5C;
    unsigned short m_5E;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int m_74;
    int m_78;
    CmpSub m_7C;

    bool Equals(FUN_00c1d6b0_cls* other);
    bool IsEquivalent(FUN_00c1d6b0_cls* other);
};

// Returns false on failed equality, count, item, or integer-field checks; otherwise returns the negation of m_7C.FUN_00439090.
// @fnv 0x00c1d6b0
bool FUN_00c1d6b0_cls::IsEquivalent(FUN_00c1d6b0_cls* other)
{
    if (!Equals(other))
        return false;
    unsigned int otherCount = other->m_5E;
    unsigned int count = m_5E;
    if (count != otherCount)
        return false;
    for (unsigned int i = 0; i < count; i++)
    {
        CmpItem* a = m_58[i];
        CmpItem* b = other->m_58[i];
        if (a != 0 && b == 0)
            return false;
        if (a == 0 && b != 0)
            return false;
        if (a != 0 && !a->vCompare(b))
            return false;
    }
    if (m_74 != other->m_74)
        return false;
    if (m_78 != other->m_78)
        return false;
    return m_7C.FUN_00439090(&other->m_7C) ? false : true;
}

#include <math.h>
extern int __cdecl FUN_00ecadb8(void);
struct C1d9e0_Emitter : MeshEmitter_c1cf50
{
    bool __thiscall PickRandomVertex(NiGeometry* pkGeometry, NiPoint3& kPosition, NiPoint3& kMotionVelocity);
};
// @fnv 0x00c1d9e0
bool __thiscall C1d9e0_Emitter::PickRandomVertex(NiGeometry* pkGeometry, NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    int iRandomIndex = FUN_00ecadb8();
    char* data = *(char**)((char*)pkGeometry + 0xb8);
    unsigned short count = *(unsigned short*)(data + 8);
    iRandomIndex %= count;
    NiPoint3* positions = *(NiPoint3**)(data + 0x20);
    NiPoint3b* normals = *(NiPoint3b**)(data + 0x24);
    if (positions == 0)
        return false;
    kPosition = positions[iRandomIndex];
    NiPoint3b normal = normals[iRandomIndex];
    if (velocityMode == 0 && *(NiPoint3b**)(*(char**)((char*)pkGeometry + 0xb8) + 0x24) != 0)
    {
        float length = (float)sqrt(kMotionVelocity.x * kMotionVelocity.x + kMotionVelocity.y * kMotionVelocity.y +
                                   kMotionVelocity.z * kMotionVelocity.z);
        NiPoint3b result = normal * length;
        kMotionVelocity = *(NiPoint3*)&result;
    }
    ComputeEmitterParticleTransform((NiAVObject*)pkGeometry, (NiPoint3b&)kPosition, (NiPoint3b&)kMotionVelocity);
    return true;
}

struct MeshPoint
{
    float x, y, z;
    MeshPoint()
    {}
    MeshPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    MeshPoint operator+(const MeshPoint& r) const
    {
        return MeshPoint(x + r.x, y + r.y, z + r.z);
    }
    MeshPoint operator-(const MeshPoint& r) const
    {
        return MeshPoint(x - r.x, y - r.y, z - r.z);
    }
    MeshPoint operator*(float r) const
    {
        return MeshPoint(x * r, y * r, z * r);
    }
};
inline MeshPoint operator*(float l, const MeshPoint& r)
{
    return MeshPoint(l * r.x, l * r.y, l * r.z);
}

struct GeometryDataLayout
{
    void* vtable;
    int unk04;
    unsigned short vertexCount;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    MeshPoint* vertices;
    MeshPoint* normals;
};

struct GeometryLayout
{
    void** vtable;
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryDataLayout* modelData;
};

struct EmitterLayout
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
    int unk68;
    int unk6c;
    int unk70;
    int velocityType;
    int emissionType;
};

struct GeometryRuntimeType
{
    const char* name;
    const GeometryRuntimeType* parent;
};

extern GeometryRuntimeType DAT_011f4a48;
extern "C" void __cdecl FUN_00525340(MeshPoint* point);

typedef int(__thiscall* GeometryTestFn)(NiGeometry*);
typedef GeometryRuntimeType*(__thiscall* GeometryRTTIFn)(NiGeometry*);
typedef unsigned short(__thiscall* GetTriangleCountFn)(void*);
typedef void(__thiscall* GetTriangleIndicesFn)(void*, unsigned int, unsigned short*, unsigned short*, unsigned short*);

struct MeshEmitterCandidate : FUN_00c1f5f0_shell
{
    bool __thiscall PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    void __thiscall ComputeEmitterParticleTransform(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
};

// Selects triangle vertices or a consecutive vertex pair, computes position and velocity, then applies the particle transform.
// @fnv 0x00c1dae0
bool MeshEmitterCandidate::PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity)
{
    if (!geometry)
        goto cleanup_fail;

    unsigned short vertex0, vertex1;

    if ((reinterpret_cast<GeometryTestFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[7]))(geometry))
    {
        unsigned int triangleCount = (reinterpret_cast<GetTriangleCountFn>(
            (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[42]))(
            reinterpret_cast<GeometryLayout*>(geometry)->modelData);
        unsigned int triangleIndex = static_cast<unsigned int>(GetRandomNumber()) % triangleCount;
        unsigned short vertex2;
        int triangleAttempts = 0;
        do
        {
            (reinterpret_cast<GetTriangleIndicesFn>(
                (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[43]))(
                reinterpret_cast<GeometryLayout*>(geometry)->modelData, triangleIndex, &vertex0, &vertex1, &vertex2);
            if (vertex0 != vertex1 && vertex0 != vertex2 && vertex1 != vertex2)
                break;
            triangleIndex += 1;
            if (triangleIndex >= triangleCount)
                triangleIndex = 0;
            triangleAttempts += 1;
        } while (triangleAttempts < 6);

        switch (GetRandomNumber() % 3)
        {
        case 1:
            vertex0 = vertex1;
            vertex1 = vertex2;
            break;
        case 2:
            vertex1 = vertex2;
            break;
        }
    }
    else
    {
        GeometryRuntimeType* runtimeType =
            reinterpret_cast<GeometryRTTIFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[2])(geometry);
        while (runtimeType)
        {
            if (runtimeType == &DAT_011f4a48)
                goto found_line;
            runtimeType = const_cast<GeometryRuntimeType*>(runtimeType->parent);
        }
    cleanup_fail:
        return false;

    found_line:
        float fRatio = static_cast<float>(GetRandomNumber()) / DAT_01029790;
        unsigned short vertexCount = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertexCount;
        unsigned int seg = static_cast<unsigned int>(static_cast<float>(vertexCount - 1) * fRatio);
        vertex0 = static_cast<unsigned short>(seg);
        vertex1 = static_cast<unsigned short>(seg + 1);
    }

    const MeshPoint* vertices = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertices;
    const MeshPoint* __restrict normals = reinterpret_cast<GeometryLayout*>(geometry)->modelData->normals;
    if (!vertices)
        goto cleanup_fail;

    MeshPoint v0 = vertices[vertex0];
    MeshPoint v1 = vertices[vertex1];
    MeshPoint vertexSum = v0 + v1;
    position = vertexSum * 0.5f;

    if (reinterpret_cast<EmitterLayout*>(this)->velocityType == 0 && normals)
    {
        MeshPoint normal0 = normals[vertex0];
        MeshPoint normal1 = normals[vertex1];
        MeshPoint normal = (normal0 + normal1) * 0.5f;
        FUN_00525340(&normal);
        float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z);
        velocity = normal * magnitude;
    }

    if (reinterpret_cast<EmitterLayout*>(this)->emissionType == 4)
    {
        float fRatio = static_cast<float>(GetRandomNumber()) / DAT_01029790;
        position = v0 + (v1 - v0) * fRatio;
    }

    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}

class NiBinaryStreamC1E
{
  public:
    typedef unsigned int(__cdecl* ReadFunc)(NiBinaryStreamC1E* pkThis, void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    virtual ~NiBinaryStreamC1E();
    unsigned int m_uiStreamFlags;
    ReadFunc m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class NiStreamC1E
{
  public:
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
    NiBinaryStreamC1E* m_pUnderlyingStream;
    void FUN_00a64670();
};
template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStreamC1E& kBinStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int auiComponentSizes[1] = {sizeof(T)};
    return kBinStream.BinaryRead(pValue, uiNumEls * sizeof(T), auiComponentSizes, 1);
}
template <class T> inline void ReadBinaryValue(NiStreamC1E& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}
template <class T> inline T NiStreamLoadValue(NiStreamC1E& kStream)
{
    T value;
    ReadBinaryValue(kStream, value);
    return value;
}
template <class T> inline T ReadC1E(NiBinaryStreamC1E& s)
{
    T v;
    NiBinaryStreamLoad(s, &v, 1);
    return v;
}
struct LoadableC1E
{
    void FUN_00a59be0(NiStreamC1E& kStream);
};
class LoadObjectC1E
{
  public:
    virtual ~LoadObjectC1E();
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
    int unk68;
    int unk6c;
    int unk70;
    unsigned int m_uiValue74;
    unsigned int m_uiValue78;
    LoadableC1E m_kMember7C;
    void FUN_00c223b0(NiStreamC1E& kStream);
    void Load(NiStreamC1E& kStream);
};
// Calls FUN_00c223b0, FUN_00a64670, reads two unsigned ints into m_uiValue74 and m_uiValue78, then calls m_kMember7C.FUN_00a59be0.
// @fnv 0x00c1e850
void LoadObjectC1E::Load(NiStreamC1E& kStream)
{
    FUN_00c223b0(kStream);
    kStream.FUN_00a64670();
    m_uiValue74 = ReadC1E<unsigned int>(*kStream.m_pUnderlyingStream);
    m_uiValue78 = ReadC1E<unsigned int>(*kStream.m_pUnderlyingStream);
    m_kMember7C.FUN_00a59be0(kStream);
}

namespace fnv_00c1eb20 {
struct MeshPoint
{
    float x, y, z;
    MeshPoint()
    {}
    MeshPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    MeshPoint operator+(const MeshPoint& r) const
    {
        return MeshPoint(x + r.x, y + r.y, z + r.z);
    }
    MeshPoint operator-(const MeshPoint& r) const
    {
        return MeshPoint(x - r.x, y - r.y, z - r.z);
    }
    MeshPoint operator*(float r) const
    {
        return MeshPoint(x * r, y * r, z * r);
    }
};
inline MeshPoint operator*(float l, const MeshPoint& r)
{
    return MeshPoint(l * r.x, l * r.y, l * r.z);
}
struct GeometryDataLayout
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    MeshPoint* vertices;
    MeshPoint* normals;
};
struct GeometryLayout
{
    void** vtable;
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryDataLayout* modelData;
};
struct EmitterLayout
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
    int unk68;
    int unk6c;
    int unk70;
    int velocityType;
    int emissionType;
};
struct GeometryRuntimeType
{
    const char* name;
    const GeometryRuntimeType* parent;
};
extern GeometryRuntimeType DAT_011f4a48;
extern const double DAT_01099ee0;
extern "C" void __cdecl FUN_00525340(MeshPoint* point);
typedef int(__thiscall* GeometryTestFn)(NiGeometry*);
typedef GeometryRuntimeType*(__thiscall* GeometryRTTIFn)(NiGeometry*);
typedef unsigned short(__thiscall* GetTriangleCountFn)(void*);
typedef void(__thiscall* GetTriangleIndicesFn)(void*, unsigned int, unsigned short*, unsigned short*, unsigned short*);
struct MeshEmitterCandidate : FUN_00c1f5f0_shell
{
    bool __thiscall EmitFromMesh(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    bool __thiscall PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    void __thiscall ComputeEmitterParticleTransform(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
};
// For triangle geometry, selects triangle vertices, averages their positions and normals, applies mode-dependent sampling, then transforms the particle.
// @fnv 0x00c1eb20
bool MeshEmitterCandidate::EmitFromMesh(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity)
{
    if (geometry)
    {
        if ((reinterpret_cast<GeometryTestFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[7]))(geometry))
        {
            unsigned int triangleCount = (reinterpret_cast<GetTriangleCountFn>(
                (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[42]))(
                (reinterpret_cast<GeometryLayout*>(geometry)->modelData));
            unsigned int triangleIndex = static_cast<unsigned int>(GetRandomNumber()) % triangleCount;
            if (triangleIndex == triangleCount)
                triangleIndex = triangleCount - 1;
            unsigned short vertex0, vertex1, vertex2;
            int triangleAttempts = 0;
            do
            {
                (reinterpret_cast<GetTriangleIndicesFn>(
                    (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[43]))(
                    (reinterpret_cast<GeometryLayout*>(geometry)->modelData), triangleIndex, &vertex0, &vertex1,
                    &vertex2);
                if (vertex0 != vertex1 && vertex0 != vertex2 && vertex1 != vertex2)
                    break;
                triangleIndex += 1;
                if (triangleIndex >= triangleCount)
                    triangleIndex = 0;
                triangleAttempts += 1;
            } while (triangleAttempts < 6);
            const MeshPoint* vertices = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertices;
            const MeshPoint* __restrict normals;
            normals = reinterpret_cast<GeometryLayout*>(geometry)->modelData->normals;
            if (!vertices)
                return false;
            MeshPoint v0 = vertices[vertex0];
            MeshPoint v1 = vertices[vertex1];
            MeshPoint v2 = vertices[vertex2];
            const float oneThird = 1.0f / 3.0f;
            MeshPoint vertexSum = v0 + v1 + v2;
            position = vertexSum * oneThird;
            if (reinterpret_cast<EmitterLayout*>(this)->velocityType == 0 && normals)
            {
                MeshPoint normal0 = normals[vertex0];
                MeshPoint normal1 = normals[vertex1];
                MeshPoint normal2 = normals[vertex2];
                MeshPoint normalSum = normal0 + normal1 + normal2;
                MeshPoint normal = normalSum * oneThird;
                FUN_00525340(&normal);
                float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z);
                velocity = normal * magnitude;
            }
            if (reinterpret_cast<EmitterLayout*>(this)->emissionType == 3)
            {
                MeshPoint edgeA = v1 - v0;
                MeshPoint edgeB = v2 - v0;
                float scaleA = FUN_00c1ced0(static_cast<float>(GetRandomNumber()) / DAT_01029790);
                float scaleB = static_cast<float>(GetRandomNumber()) / DAT_01029790;
                position = edgeA + (scaleA * (edgeB * scaleB - edgeA) + v0);
            }
            ComputeEmitterParticleTransform(geometry, position, velocity);
            return true;
        }
        GeometryRuntimeType* runtimeType =
            reinterpret_cast<GeometryRTTIFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[2])(geometry);
        for (; runtimeType; runtimeType = const_cast<GeometryRuntimeType*>(runtimeType->parent))
        {
            if (runtimeType == &DAT_011f4a48)
                return PickEmitterParticle(geometry, position, velocity);
        }
    }
    return false;
}
}  // namespace fnv_00c1eb20

struct CloneOut
{
    void __thiscall SetSkinGeom(void* item);
};
struct CloneMap
{
    bool __thiscall FUN_00a53c30(void* key, void** out);
};
struct CloneProcess
{
    CloneMap* map;
};
struct CloneEmitter
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
    void** items;
    unsigned int unk5c;
    unsigned short count;
    void __thiscall FUN_00c317e0(CloneProcess& process);
    void __thiscall CloneItems(CloneProcess& process);
    unsigned int GetCount() const
    {
        return count;
    }
    void* GetItem(unsigned int i) const
    {
        return i < count ? items[i] : 0;
    }
};
// Looks up each non-null item in the process map and appends its mapped value, or the original item when absent, to output.
// @fnv 0x00c1f8f0
void __thiscall CloneEmitter::CloneItems(CloneProcess& process)
{
    FUN_00c317e0(process);
    void* clone = 0;
    process.map->FUN_00a53c30(this, &clone);
    CloneOut* output = (CloneOut*)clone;
    for (unsigned int i = 0; i < GetCount(); ++i)
    {
        void* item = GetItem(i);
        if (item)
        {
            if (process.map->FUN_00a53c30(item, &clone))
                output->SetSkinGeom(clone);
            else
                output->SetSkinGeom(item);
        }
    }
}

#include <windows.h>
extern int DAT_0101dce4;
extern long DAT_011f4400;
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct NiRefObject
{
    virtual void v00();
    virtual void v04();
    long m_refs;
};

struct FUN_00c1d660_cls
{
    void* m_00;
    int unk04;
    NiRefObject* m_08;

    FUN_00c1d660_cls* Release(unsigned char acFlags);
};

// Releases the referenced NiRefObject, clears m_00, decrements a global counter, and optionally frees memory when acFlags has bit 0 set.
// @fnv 0x00c1d660
FUN_00c1d660_cls* FUN_00c1d660_cls::Release(unsigned char acFlags)
{
    LONG(__stdcall * pDecrement)(LONG volatile*) = &InterlockedDecrement;
    FUN_00c1d660_cls* self = this;
    NiRefObject* obj = self->m_08;
    if (obj != 0)
    {
        if (pDecrement(&obj->m_refs) == 0)
        {
            obj->v04();
        }
    }
    self->m_00 = &DAT_0101dce4;
    pDecrement(&DAT_011f4400);
    if (acFlags & 1)
    {
        FUN_00aa1460(self, 0xc);
    }
    return self;
}

struct NiSkinObj790;

struct NiFlags790
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
    unsigned char m_38;
};

struct NiSkinData790
{
    int unk00, unk04, unk08;
    unsigned int m_0c;
};

struct NiSkinGeom790
{
    virtual void v0();
    virtual void v1();
    long m_04;
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
    NiFlags790* m_b8;
    NiSkinData790* m_bc;
};

struct NiSkinSub790
{
    unsigned int m_00;
    void __thiscall FUN_0066b0d0(unsigned int v);
};

struct NiSkinObj790
{
    virtual void v0();
    virtual void v1();
    long m_04;
    NiSkinSub790 m_08;
};

struct NiSkinRaw790
{
    NiSkinObj790* __thiscall FUN_00c1cf20();
};

struct NiSkinSlot790
{
    void __thiscall InsertFirstEmptySlot(NiSkinGeom790** pp);
    void __thiscall FUN_00c1f420(NiSkinGeom790** pp);
};

void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00c1f790_cls : NiPSysMeshEmitter
{
    void __thiscall SetSkinGeom(NiSkinGeom790* pkGeom);
};

// Sets skin geometry on the emitter, updating m_54 and m_64 slots, and sets flags 0x33 on the geometry's flags.
// @fnv 0x00c1f790
void __thiscall FUN_00c1f790_cls::SetSkinGeom(NiSkinGeom790* pkGeom)
{
    NiSkinGeom790* pSkinGeom = pkGeom;
    if (pSkinGeom != 0)
    {
        NiSkinGeom790* temp = pSkinGeom;
        InterlockedIncrement(&pSkinGeom->m_04);
        reinterpret_cast<NiSkinSlot790*>(&m_54)->InsertFirstEmptySlot(&temp);
        if (InterlockedDecrement(&pSkinGeom->m_04) == 0)
        {
            pSkinGeom->v1();
        }
        NiSkinData790* skin = pSkinGeom->m_bc;
        NiSkinObj790* pSkinObj;
        NiSkinRaw790* p;
        if (skin != 0)
        {
            unsigned int edi = skin->m_0c;
            p = (NiSkinRaw790*)FUN_00aa13e0(12);
            if (edi != 0)
            {
                if (p != 0)
                {
                    pSkinObj = p->FUN_00c1cf20();
                    pSkinObj->m_08.FUN_0066b0d0(edi);
                    goto joined;
                }
            null_obj:
                pSkinObj = 0;
                pSkinObj->m_08.FUN_0066b0d0(edi);
                goto joined;
            }
        }
        else
        {
            p = (NiSkinRaw790*)FUN_00aa13e0(12);
        }
        if (p != 0)
        {
            pSkinObj = p->FUN_00c1cf20();
        }
        else
        {
            pSkinObj = 0;
        }
    joined:
        temp = (NiSkinGeom790*)pSkinObj;
        if (pSkinObj)
        {
            InterlockedIncrement(&pSkinObj->m_04);
        }
        reinterpret_cast<NiSkinSlot790*>(&m_64)->FUN_00c1f420(&temp);
        if (pSkinObj)
        {
            if (InterlockedDecrement(&pSkinObj->m_04) == 0)
            {
                pSkinObj->v1();
            }
        }
        NiFlags790* flags = pSkinGeom->m_b8;
        if (flags != 0)
        {
            flags->m_38 |= 0x33;
        }
    }
}

extern "C" void _ReadWriteBarrier(void);
struct GeometryCapability
{
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual int HasUsableSkinData();
};
struct MeshParticleSample
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    const unsigned short* particleIndices;
    unsigned int unk18;
    unsigned short unk1c;
    union
    {
        unsigned short particleCount;
        short signedParticleCount;
    };
    unsigned short unk20, separateChannels;
    unsigned int unk24, unk28;
};
struct MeshParticleGroup
{
    unsigned int unk00, unk04;
    unsigned short groupCount, unk0a;
    MeshParticleSample* samples;
};
struct MeshVectorOps
{
    float x, y, z;
    void FUN_0053d280(NiPoint3* output, float scalar) const;

    float FUN_00457990() const;
};
__forceinline NiPoint3 ScaleVector(const NiPoint3& value, float scalar)
{
    NiPoint3 result;
    reinterpret_cast<const MeshVectorOps*>(&value)->FUN_0053d280(&result, scalar);
    return result;
}
__forceinline void AddVector(NiPoint3& output, const NiPoint3& a, const NiPoint3& b)
{
    output.x = a.x + b.x;
    output.y = a.y + b.y;
    output.z = a.z + b.z;
}
struct SumValue
{
    float x, y, z;
    SumValue()
    {}
    SumValue(float x) : x(x)
    {}
};
__forceinline void AddAccumulator(NiPoint3& output, const SumValue& a, const NiPoint3& b)
{
    output.x = a.x + b.x;
    output.y = a.y + b.y;
    output.z = a.z + b.z;
}
extern "C" float __cdecl func_0x00639780();
extern "C" NiPoint3* __cdecl FUN_004a3760(NiPoint3*, float, NiPoint3*);
extern float DAT_01017718;
extern NiPoint3 NiPoint3_ZERO;
class MeshReconstruction : public FUN_00c1f5f0_shell
{
  public:
    bool FUN_00c1e080(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    bool GetRandomEmitterParticle(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void SkinVertex(NiPoint3&, NiPoint3&, NiGeometry*, NiSkinnedEmitterData*, MeshParticleSample*, unsigned int);
    void ComputeEmitterParticleTransform(NiGeometry*, NiPoint3&, NiPoint3&);
    int GetVelocitySpaceMode() const
    {
        return reinterpret_cast<const MeshEmitter_c1cf50*>(this)->velocityMode;
    }
    int GetVelocityMode() const
    {
        return reinterpret_cast<const MeshEmitter_c1cf50*>(this)->unk78;
    }
};
// Picks a random particle from a skin group, computes its position and velocity from three skinned vertices, and applies velocity-space and mode transforms.
// @fnv 0x00c1e080
bool MeshReconstruction::FUN_00c1e080(NiSkinInstance* apSkinInstance, NiGeometry* geometry, NiPoint3& position,
                                      NiPoint3& velocity)
{
    if (!geometry || !reinterpret_cast<GeometryCapability*>(geometry)->HasUsableSkinData())
        return false;
    MeshParticleGroup* group = reinterpret_cast<MeshParticleGroup*>(apSkinInstance->m_kPointB);
    if (!group)
        return false;
    unsigned short groupCount = group->groupCount;
    int groupIndex = (unsigned int)(float(double(GetRandomNumber()) / DAT_01029790) * (int)groupCount);
    if (groupIndex >= (int)groupCount - 1)
        groupIndex = groupCount - 1;
    MeshParticleSample* sample = &reinterpret_cast<MeshParticleGroup*>(apSkinInstance->m_kPointB)->samples[groupIndex];
    if (!sample->signedParticleCount)
        return GetRandomEmitterParticle(apSkinInstance, geometry, position, velocity);
    _ReadWriteBarrier();
    int particleCount = sample->particleCount;
    int particleIndex = (unsigned int)(func_0x00639780() * (int)particleCount);
    if (particleIndex >= (int)particleCount - 1)
        particleIndex = particleCount - 1;
    NiSkinnedEmitterData* data = geometry->m_bc;
    if (!data)
        return false;
    unsigned int first, second, uiThirdIndex;
    if (sample->separateChannels)
    {
        first = sample->particleIndices[particleIndex];
        second = sample->particleIndices[particleIndex + 1];
        uiThirdIndex = sample->particleIndices[particleIndex + 2];
    }
    else
    {
        const unsigned short* indices = sample->particleIndices + particleIndex * 3;
        first = indices[0];
        second = indices[1];
        uiThirdIndex = indices[2];
    }
    struct TriangleVectors
    {
        NiPoint3 p0, p1, p2, v0, v1, v2, accumulator;
    } triangle;
    triangle.p0 = NiPoint3_ZERO;
    triangle.v0 = NiPoint3_ZERO;
    triangle.p1 = NiPoint3_ZERO;
    triangle.v1 = NiPoint3_ZERO;
    triangle.p2 = NiPoint3_ZERO;
    triangle.v2 = NiPoint3_ZERO;
    SkinVertex(triangle.p0, triangle.v0, geometry, data, sample, first);
    SkinVertex(triangle.p1, triangle.v1, geometry, data, sample, second);
    SkinVertex(triangle.p2, triangle.v2, geometry, data, sample, uiThirdIndex);
    {
        SumValue scratch(triangle.p0.x + triangle.p1.x);
        scratch.y = triangle.p1.y + triangle.p0.y;
        scratch.z = triangle.p1.z + triangle.p0.z;
        AddAccumulator(triangle.accumulator, scratch, triangle.p2);
    }
    position = ScaleVector(triangle.accumulator, DAT_01017718);
    if (GetVelocitySpaceMode() == 0)
    {
        SumValue scratch(triangle.v0.x + triangle.v1.x);
        scratch.y = triangle.v1.y + triangle.v0.y;
        scratch.z = triangle.v1.z + triangle.v0.z;
        AddAccumulator(triangle.accumulator, scratch, triangle.v2);
        reinterpret_cast<MeshVectorOps*>(&triangle.accumulator)->FUN_0053d280(&triangle.v2, DAT_01017718);
        FUN_00525340(&triangle.v2);
        float magnitude = reinterpret_cast<MeshVectorOps*>(&velocity)->FUN_00457990();
        NiPoint3* result = FUN_004a3760(&triangle.accumulator, magnitude, &triangle.v2);
        velocity = *result;
    }
    if (GetVelocityMode() == 3)
    {
        NiPoint3 scratch;
        scratch.x = triangle.p1.x - triangle.p0.x;
        scratch.y = triangle.p1.y - triangle.p0.y;
        scratch.z = triangle.p1.z - triangle.p0.z;
        triangle.accumulator.x = triangle.p2.x - triangle.p0.x;
        triangle.accumulator.y = triangle.p2.y - triangle.p0.y;
        triangle.accumulator.z = triangle.p2.z - triangle.p0.z;
        float parameter = FUN_00c1ced0(func_0x00639780());
        NiPoint3* firstResult = FUN_004a3760(&triangle.v1, func_0x00639780(), &triangle.accumulator);
        triangle.accumulator.x = firstResult->x - scratch.x;
        triangle.accumulator.y = firstResult->y - scratch.y;
        triangle.accumulator.z = firstResult->z - scratch.z;
        NiPoint3* secondResult = FUN_004a3760(&triangle.v0, parameter, &triangle.accumulator);
        triangle.v2.x = secondResult->x + triangle.p0.x;
        triangle.v2.y = secondResult->y + triangle.p0.y;
        triangle.v2.z = secondResult->z + triangle.p0.z;
        AddVector(triangle.v1, triangle.v2, scratch);
        position = triangle.v1;
    }
    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}

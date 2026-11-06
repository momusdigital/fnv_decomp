
// src/gamebryo2.2/corelibs/niparticle/nipsysdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nipsysdata_types_NiPSysData.h"
#include "nipsysdata_types_NiStream.h"
#include "nipsysdata_types_NiParticleInfo.h"
#include "nipsysdata_types_NiQuaternion.h"
#include "MemoryManager.h"
#include "nipsysdata_stream.h"
extern MemoryManager g_memoryManager;
void* _NiMalloc(unsigned int size);
extern "C" void* fnv_zlib_memset(void* dst, int value, unsigned long size);

struct FUN_00a67c00
{
    FUN_00a67c00();
};
extern char* DAT_010a05e4;
struct NiGeometryData_SetConsistency_View
{
    void SetDataConsistency(int);
};
struct FUN_00a963f0 : FUN_00a67c00
{
    FUN_00a963f0();
};
// @fnv 0x00a963f0
FUN_00a963f0::FUN_00a963f0()
{
    *(void**)this = (void*)&DAT_010a05e4;
    *(int*)((char*)this + 0x4c) = 0;
    *(unsigned short*)((char*)this + 0x50) = 0;
    *(int*)((char*)this + 0x54) = 0;
    *(int*)((char*)this + 0x58) = 0;
    *(int*)((char*)this + 0x5c) = 0;
    *(int*)((char*)this + 0x60) = 0;
    *(int*)((char*)this + 0x64) = 0;
    *(int*)((char*)this + 0x68) = 0;
    *(unsigned char*)((char*)this + 0x6c) = 0;
    *(unsigned char*)((char*)this + 0x40) = 0;
    ((NiGeometryData_SetConsistency_View*)this)->SetDataConsistency(0);
    *(unsigned char*)((char*)this + 0x3c) = 0;
}

struct FUN_00a967e0_class
{
    unsigned short m_usActive;
    void __thiscall SetActiveVertexCount(unsigned short usActive);
};

// @fnv 0x00a967e0
void __thiscall FUN_00a967e0_class::SetActiveVertexCount(unsigned short usActive)
{
    unsigned short active = *(unsigned short*)((char*)this + 8);
    if (usActive <= active)
        *(unsigned short*)((char*)this + 0x50) = usActive;
    else
        *(unsigned short*)((char*)this + 0x50) = active;
}

struct NiPSysData_StandIn
{
    char _0[0x50];
    unsigned short m_50;
    char _1[0x1E];
    struct Item
    {
        int v[7];
    }* m_pkParticleInfo;
    float* m_pfRotationSpeeds;
    void FUN_00c24cc0(unsigned short usParticle);
    void RemoveParticle(unsigned short);
};
// @fnv 0x00c24cc0
void NiPSysData_StandIn::FUN_00c24cc0(unsigned short usParticle)
{
    unsigned short usLastParticle = m_50 - 1;
    RemoveParticle(usParticle);
    if (usParticle != usLastParticle)
    {
        m_pkParticleInfo[usParticle] = m_pkParticleInfo[usLastParticle];
        if (m_pfRotationSpeeds)
            m_pfRotationSpeeds[usParticle] = m_pfRotationSpeeds[usLastParticle];
    }
}

extern const char* const g_01202680_arg1;

// @fnv 0x00c24e90
const char* const* __cdecl FUN_00c24e90()
{
    return &g_01202680_arg1;
}

extern int DAT_010be254;
void _NiFreeAlias(void*);
void _delete(void*, unsigned int);
struct Holder00a96800
{
    void FUN_00a96800();
};
struct S_00c25280
{
    char _pad[0x70];
    void* _a70;
    void* _b74;
    void* FUN_00c25280(unsigned int);
};
// @fnv 0x00c25280
void* S_00c25280::FUN_00c25280(unsigned int f)
{
    *(void**)this = (void*)&DAT_010be254;
    g_memoryManager.Deallocate(_a70);
    _NiFreeAlias(_b74);
    ((Holder00a96800*)this)->FUN_00a96800();
    if (f & 1)
        _delete(this, 0x7c);
    return this;
}

namespace fnv_00c24ef0 {
extern int DAT_010be254;
void __cdecl _NiFreeAlias(void*);
struct Holder00a96800
{
    void FUN_00a96800();
};
struct Unknown00c24ef0
{
    void* f0;
    char pad[108];
    void* p70;
    void* p74;
    void FUN_00c24ef0();
};
// @fnv 0x00c24ef0
void Unknown00c24ef0::FUN_00c24ef0()
{
    f0 = (void*)&DAT_010be254;
    g_memoryManager.Deallocate(p70);
    _NiFreeAlias(p74);
    ((Holder00a96800*)this)->FUN_00a96800();
}
}  // namespace fnv_00c24ef0

// Reconstruction of ResolveAddedParticles.
//
// thiscall member of a NiPSysData-derived class (the game's vtable for the
// class has 44 slots; slot 41 is the particle callback the body calls with
// the running particle index, and slot 43 is this function itself).
//
// Shape of the body:
//   * read the two 16-bit counters: the live particle count at +0x50
//     (m_usActive) and the base index at +0x7a (m_usNumParticles);
//   * if the count has already reached the base, the count is bumped by the
//     number of added particles and the function is done;
//   * otherwise the count is set to base + added, and the callback is run
//     for every particle index from the old count upwards while the count
//     stays above the base - the callback itself adds particles;
//   * if the loop stopped early the count and the base are both set to the
//     current index, otherwise the base is set to the count;
//   * in both cases the "added particles" counter at +0x78 is cleared.

struct FnvPSysData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void FUN_00c24cc0(unsigned short usParticle);

    char _pad04[0x4c];
    unsigned short m_usActive;  // +0x50
    char _pad52[0x26];
    unsigned short m_usNumActive;     // +0x78
    unsigned short m_usNumParticles;  // +0x7a

    void ResolveAddedParticles();
};

// @fnv 0x00c24d20
void FnvPSysData::ResolveAddedParticles()
{
    if (m_usActive < m_usNumParticles)
    {
        unsigned short i = m_usActive;
        m_usActive = m_usNumActive + m_usNumParticles;

        while (i < m_usNumParticles)
        {
            if (m_usActive <= m_usNumParticles)
                break;
            FUN_00c24cc0(i);
            ++i;
        }

        if (i < m_usNumParticles)
        {
            m_usActive = i;
        }
    }
    else
    {
        m_usActive = m_usNumActive + m_usActive;
    }

    m_usNumActive = 0;
    m_usNumParticles = m_usActive;
}

extern int DAT_010be254;
void* __cdecl FUN_00aa13e0(unsigned int size);

class FUN_00c24da0_cls
{
  public:
    void* m_vtbl;
    char unk04[0x6c];
    unsigned int unk70;
    unsigned int unk74;
    unsigned short unk78;
    unsigned short unk7a;

    void FUN_00a963f0();
};

// @fnv 0x00c24da0
FUN_00c24da0_cls* __cdecl FUN_00c24da0()
{
    FUN_00c24da0_cls* p = (FUN_00c24da0_cls*)FUN_00aa13e0(0x7c);
    if (p != 0)
    {
        p->FUN_00a963f0();
        p->m_vtbl = (void*)&DAT_010be254;
        p->unk70 = 0;
        p->unk74 = 0;
        p->unk78 = 0;
        p->unk7a = 0;
        return p;
    }
    return 0;
}

struct HookBase
{
    bool FUN_00a96a30(void* p);
};
struct ParticleItemStand
{
    bool Equals(void* p);
};
struct PSDataEqStand : NiPSysData_StandIn
{
    unsigned short m_78;
    unsigned short m_7a;
    bool IsEqual(PSDataEqStand* other);
};

// @fnv 0x00c24de0
bool PSDataEqStand::IsEqual(PSDataEqStand* other)
{
    if (!reinterpret_cast<HookBase*>(this)->FUN_00a96a30(other))
    {
        return false;
    }
    if (m_pfRotationSpeeds != 0 && other->m_pfRotationSpeeds == 0)
    {
        return false;
    }
    if (m_pfRotationSpeeds == 0 && other->m_pfRotationSpeeds != 0)
    {
        return false;
    }
    unsigned short i = 0;
    while (i < m_50)
    {
        if (!reinterpret_cast<ParticleItemStand*>(&m_pkParticleInfo[i])->Equals(&other->m_pkParticleInfo[i]))
        {
            return false;
        }
        if (m_pfRotationSpeeds != 0)
        {
            if (m_pfRotationSpeeds[i] != other->m_pfRotationSpeeds[i])
            {
                return false;
            }
        }
        i++;
    }
    if (m_78 != other->m_78 || m_7a != other->m_7a)
    {
        return false;
    }
    return true;
}

struct NiPSysData_CountView : NiPSysData
{
    unsigned int AddParticle();
};
// @fnv 0x00c24ea0
unsigned int NiPSysData_CountView::AddParticle()
{
    unsigned short count = m_usNumActive;
    if (count == 0)
    {
        unsigned short first = m_usActive;
        m_usNumParticles = first;
        if (first < m_usVertices)
        {
            return (unsigned short)(first + m_usNumActive++);
        }
    }
    else
    {
        unsigned short base = m_usNumParticles;
        if (m_usNumParticles + m_usNumActive < m_usVertices)
        {
            return (unsigned short)(base + m_usNumActive++);
        }
    }
    return 0xffff;
}

struct NiParticlesDataWriter : NiParticlesData
{
    void __thiscall FUN_00a97290(NiStream&);
};
struct NiPSysDataWriter : NiParticlesDataWriter
{
    Point3ParameterData* particleInfo;
    float* rotationSpeeds;
    void __thiscall FUN_00c25560(NiStream&);
};
// @fnv 0x00c25560
void NiPSysDataWriter::FUN_00c25560(NiStream& stream)
{
    NiParticlesDataWriter::FUN_00a97290(stream);
    bool hasRotationSpeeds = rotationSpeeds != 0;
    NiBinaryStream* output = stream.m_pBackingStream;
    unsigned int(__cdecl * writer)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int) =
        output->m_pfnWrite;
    unsigned int count = 1;
    output->m_uiStreamFlags += writer(output, &hasRotationSpeeds, 1, &count, 1);
}

// FUN_00c25850 : initialiser of a small (0x14 byte) engine object.
//
// The original code calls the immediate-base routine with `this` in ecx, then
// clears the two integer members at +8 and +0xc, installs the class vtable
// pointer (the extern data object DAT_010be45c) at +0 and stores 0.0f in the
// float member at +0x10, finally returning the object itself.
//
// The volatile qualifiers only pin the order of the four member stores
// (int +8, vtable, int +0xc, float +0x10); they do not change the semantics.

extern int DAT_010be45c;

struct FUN_00c25850_cls
{
    void* m_pVTable;
    int m_iValue04;
    volatile int m_iValue08;
    volatile int m_iValue0c;
    volatile float m_fValue10;

    void BaseCtor();
    FUN_00c25850_cls* FUN_00c25850();
};

// @fnv 0x00c25850
FUN_00c25850_cls* FUN_00c25850_cls::FUN_00c25850()
{
    BaseCtor();
    m_iValue08 = 0;
    m_pVTable = (void*)&DAT_010be45c;
    m_iValue0c = 0;
    m_fValue10 = 0.0f;
    return this;
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short maxSize, size, eSize, grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= maxSize)
            SetSize(index + grow);
        SetAt(index, value);
    }
};
char* __cdecl FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d5a0(const char*, void*);
char* __cdecl FUN_00a7d490(const char*, unsigned short);
extern const char* const g_01202680_arg1;
extern const char DAT_010be340[];
extern const char DAT_010be32c[];
extern const char DAT_010be318[];
extern const char DAT_010be304[];
struct Source08
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
    void* ptr70;
    void* ptr74;
    unsigned short value78, value7a;
    void FUN_00a97420(StrArr*);
    void GetViewerStrings(StrArr*);
};
// @fnv 0x00c255b0
void Source08::GetViewerStrings(StrArr* strings)
{
    FUN_00a97420(strings);
    strings->Add(FUN_00a7d330(g_01202680_arg1));
    strings->Add(FUN_00a7d5a0(DAT_010be340, ptr70));
    strings->Add(FUN_00a7d5a0(DAT_010be32c, ptr74));
    strings->Add(FUN_00a7d490(DAT_010be318, value78));
    strings->Add(FUN_00a7d490(DAT_010be304, value7a));
}

__declspec(noinline) Point3ParameterData::Point3ParameterData() throw()
{
    m_kValue = NiPoint3::ZERO;
    m_fXValue = 0.0f;
    m_fYValue = 0.0f;
    m_fZValue = 0.0f;
    m_usFirstValue = 0;
    m_usSecondValue = 0;
}

extern MemoryManager g_memoryManager;
void* _NiMalloc(unsigned int size) throw();
void _NiFreeAlias(void*) throw();
extern "C" void* __cdecl _fnv_zlib_memcpy(void* dst, const void* src, unsigned int size) throw();

class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor() throw();
};

__forceinline void* operator new[](size_t size) throw()
{
    return g_memoryManager.Allocate(size);
}

struct ParticlePoint : NiPoint3
{
    ParticlePoint() throw()
    {}
};
struct ParticleRotation : NiQuaternion
{
    ParticleRotation() throw()
    {}
};

struct NiObject_Stub
{
    void CopyMembersStream(void* pkDest, void* kCloning) throw();
};

struct NiPSysData_View : NiPSysData
{
    void Replace(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, RgbaColor* pkColor, void* pkTexture,
                 unsigned short usNumTextureSets, void* pkNormalBuffer) throw();
    void ReplaceSizes(float* pfSizes) throw();
    void ReplaceRadii(float* pfRadii) throw();
    void ReplaceRotationAngles(float* pfRotationAngles) throw();
    void ReplaceRotationAxes(NiPoint3* pkRotationAxes) throw();
    void ReplaceTextureIndices(unsigned char* pucTextureIndices) throw();
    void ReplaceSubTextureOffsets(RgbaColor* pkOffsets, unsigned char ucCount) throw();

    void ReplaceParticleInfo(Point3ParameterData* pkInfo) throw()
    {
        g_memoryManager.Deallocate(m_pkParticleInfo);
        m_pkParticleInfo = pkInfo;
    }
    void ReplaceParticleRotationSpeeds(float* pfSpeeds) throw()
    {
        _NiFreeAlias(m_pfRotationSpeeds);
        m_pfRotationSpeeds = pfSpeeds;
    }

    void FUN_00c24f20(NiPSysData_View* pkDest, void* kCloning);
};

static inline void SetCenterAndRadius(NiBound& kBound, const NiPoint3& kTargetCenter, float fRadius)
{
    kBound.m_kCenter = kTargetCenter;
    kBound.m_fBoundRadius = fRadius;
}
// @fnv 0x00c24f20
void NiPSysData_View::FUN_00c24f20(NiPSysData_View* pkDest, void* kCloning)
{
    ((NiObject_Stub*)this)->CopyMembersStream(pkDest, kCloning);

    NiPoint3* pkVertex = new ParticlePoint[m_usVertices];
    unsigned int uiVertexSize = sizeof(NiPoint3) * m_usVertices;
    _fnv_zlib_memcpy(pkVertex, m_pkVertex, uiVertexSize);

    NiPoint3* pkNormal = 0;
    if (m_pkNormal)
    {
        pkNormal = new ParticlePoint[m_usVertices];
        _fnv_zlib_memcpy(pkNormal, m_pkNormal, uiVertexSize);
    }

    RgbaColor* pkColor = 0;
    if (m_pkColor)
    {
        pkColor = new RgbaColor[m_usVertices];
        _fnv_zlib_memcpy(pkColor, m_pkColor, sizeof(RgbaColor) * m_usVertices);
    }

    pkDest->Replace(m_usVertices, pkVertex, pkNormal, pkColor, 0, 0, 0);

    NiQuaternion* pkRotations = 0;
    if (m_pkRotations)
    {
        pkRotations = new ParticleRotation[m_usVertices];
        _fnv_zlib_memcpy(pkRotations, m_pkRotations, sizeof(NiQuaternion) * m_usVertices);
    }
    pkDest->SetRotations(pkRotations);

    float* pfSizes = (float*)_NiMalloc(sizeof(float) * m_usVertices);
    unsigned int uiFloatSize = sizeof(float) * m_usVertices;
    _fnv_zlib_memcpy(pfSizes, m_pfSizes, uiFloatSize);
    pkDest->ReplaceSizes(pfSizes);

    float* pfRadii = (float*)_NiMalloc(sizeof(float) * m_usVertices);
    _fnv_zlib_memcpy(pfRadii, m_pfRadii, uiFloatSize);
    pkDest->ReplaceRadii(pfRadii);

    pkDest->m_usActive = m_usActive;

    if (m_pfRotationAngles)
    {
        float* pfRotationAngles = (float*)_NiMalloc(sizeof(float) * m_usVertices);
        _fnv_zlib_memcpy(pfRotationAngles, m_pfRotationAngles, uiFloatSize);
        pkDest->ReplaceRotationAngles(pfRotationAngles);
    }

    if (m_pkRotationAxes)
    {
        NiPoint3* pkRotationAxes = new ParticlePoint[m_usVertices];
        _fnv_zlib_memcpy(pkRotationAxes, m_pkRotationAxes, sizeof(NiPoint3) * m_usVertices);
        pkDest->ReplaceRotationAxes(pkRotationAxes);
    }

    if (m_pucTextureIndices)
    {
        unsigned char* pucTextureIndices = (unsigned char*)_NiMalloc(sizeof(unsigned char) * m_usVertices);
        _fnv_zlib_memcpy(pucTextureIndices, m_pucTextureIndices, sizeof(unsigned char) * m_usVertices);
        pkDest->ReplaceTextureIndices(pucTextureIndices);
    }

    if (m_pkSubTextureOffsets)
    {
        RgbaColor* pkSubTextureOffsets = (RgbaColor*)_NiMalloc(sizeof(RgbaColor) * m_ucSubTextureOffsetCount);
        _fnv_zlib_memcpy(pkSubTextureOffsets, m_pkSubTextureOffsets, sizeof(RgbaColor) * m_ucSubTextureOffsetCount);
        pkDest->ReplaceSubTextureOffsets(pkSubTextureOffsets, m_ucSubTextureOffsetCount);
    }

    Point3ParameterData* pkParticleInfo = 0;
    if (m_pkParticleInfo)
    {
        pkParticleInfo = new Point3ParameterData[m_usVertices];
        _fnv_zlib_memcpy(pkParticleInfo, m_pkParticleInfo, sizeof(Point3ParameterData) * m_usVertices);
    }
    pkDest->ReplaceParticleInfo(pkParticleInfo);

    float* pfRotationSpeeds = 0;
    if (m_pfRotationSpeeds)
    {
        pfRotationSpeeds = (float*)_NiMalloc(sizeof(float) * m_usVertices);
        _fnv_zlib_memcpy(pfRotationSpeeds, m_pfRotationSpeeds, sizeof(float) * m_usVertices);
    }
    pkDest->ReplaceParticleRotationSpeeds(pfRotationSpeeds);

    pkDest->m_usNumActive = m_usNumActive;
    pkDest->m_usNumParticles = m_usNumParticles;

    SetCenterAndRadius(pkDest->m_kBound, m_kBound.m_kCenter, m_kBound.m_fBoundRadius);
}

struct S00c25340_Pt3
{
    float x, y, z;
    S00c25340_Pt3()
    {}
    static void* operator new[](unsigned int size, MemoryManager& mm)
    {
        return mm.Allocate(size);
    }
};

struct S00c25340_Info : Point3ParameterData
{
    static void* operator new[](unsigned int size, MemoryManager& mm)
    {
        return mm.Allocate(size);
    }
};

struct S00c25340_Data : NiPSysData
{
    void FUN_00c25340(NiStream& stream);
};

struct S00c25340_Stream : NiBinaryStream
{
    void Read(void* destination, unsigned int size, unsigned int elementSize)
    {
        m_uiStreamFlags += m_pfnRead(this, destination, size, &elementSize, 1);
    }
};

static inline void S00c25340_Read(NiBinaryStream* input, void* destination, unsigned int size, unsigned int elementSize)
{
    static_cast<S00c25340_Stream*>(input)->Read(destination, size, elementSize);
}

// @fnv 0x00c25340
void S00c25340_Data::FUN_00c25340(NiStream& stream)
{
    NiParticlesData::LoadBinary(stream);
    if (stream.m_uiNifVersion < 0x0a030005 && m_pkRotations)
    {
        m_pfRotationAngles = (float*)_NiMalloc(m_usVertices * 4);
        m_pkRotationAxes = (NiPoint3*)new (g_memoryManager) S00c25340_Pt3[m_usVertices];
        for (unsigned short i = 0; i < m_usVertices; ++i)
            m_pkRotations[i].GetAngleAxis(m_pfRotationAngles[i], m_pkRotationAxes[i]);
        SetRotations(0);
    }
    m_pkParticleInfo = (Point3ParameterData*)new (g_memoryManager) S00c25340_Info[m_usVertices];
    if (stream.m_kHeader.uiVersion < 0x13)
        for (unsigned short i = 0; i < m_usVertices; ++i)
            m_pkParticleInfo[i].LoadBinary(stream);
    if (stream.m_uiNifVersion >= 0x14000002)
    {
        unsigned char res;
        S00c25340_Read(stream.m_pUnderlyingStream, &res, 1, 1);
        if (res)
        {
            m_pfRotationSpeeds = (float*)_NiMalloc(m_usVertices * 4);
            if (stream.m_kHeader.uiVersion < 0x13)
                S00c25340_Read(stream.m_pUnderlyingStream, m_pfRotationSpeeds, m_usVertices * 4, 4);
        }
    }
    else if (m_pfRotationAngles)
    {
        m_pfRotationSpeeds = (float*)_NiMalloc(m_usVertices * 4);
        fnv_zlib_memset(m_pfRotationSpeeds, 0, m_usVertices * 4);
    }
    if (stream.m_kHeader.uiVersion < 0x13)
    {
        S00c25340_Read(stream.m_pUnderlyingStream, &m_usNumActive, 2, 2);
        S00c25340_Read(stream.m_pUnderlyingStream, &m_usNumParticles, 2, 2);
    }
}

extern int DAT_010be254;

struct PSysDataClone
{
    void* m_vtbl;
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
    void* m_70;
    void* m_74;
    unsigned short m_78;
    unsigned short m_7a;

    static void* operator new(unsigned int);
    void FUN_00a963f0() throw();
    PSysDataClone()
    {
        FUN_00a963f0();
        m_vtbl = (void*)&DAT_010be254;
        m_70 = 0;
        m_74 = 0;
        m_78 = 0;
        m_7a = 0;
    }
};

struct PSysDataCloneSrc
{
    void FUN_00c24f20(PSysDataClone* pkDest, void* kCloning);
    PSysDataClone* CreateClone(void* kCloning);
};

// @fnv 0x00c252d0
PSysDataClone* PSysDataCloneSrc::CreateClone(void* kCloning)
{
    PSysDataClone* pkClone = new PSysDataClone;
    FUN_00c24f20(pkClone, kCloning);
    return pkClone;
}

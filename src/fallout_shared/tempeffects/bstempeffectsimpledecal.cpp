// fallout_shared/tempeffects/bstempeffectsimpledecal.cpp: BSTempEffectSimpleDecal, NiPoint3, DecalStub, DecalHolder and more (27 functions)

#include "original_bstempeffectsimpledecal.h"

// Original PC source filename label passed to the preload memory context;
// contents and target are verified against the engine data section.
const char kBSTempEffectSimpleDecalFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectSimpleDecal.cpp";

// Source line of the preload context in the original PC file (0x11f).
enum
{
    kPreloadDecalDataSourceLine = 0x11f
};

NiPointer<QueuedFile> BSTempEffectSimpleDecal::ms_pPreloadDecalDataFile;

// @fnv 0x0068b3e0
void BSTempEffectSimpleDecal::QueueDecalDataFile()
{
    if (ms_pPreloadDecalDataFile)
        return;

    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_EFFECTS_OVERHEAD, true, kBSTempEffectSimpleDecalFileLabel,
                           kPreloadDecalDataSourceLine);
    ms_pPreloadDecalDataFile = new QueuedFile(5);
}

// Returns the cross product of this NiPoint3 with point, computing each component from the other two axes.
// @fnv 0x004b3800
NiPoint3 NiPoint3::Cross(const NiPoint3& point) const
{
    return NiPoint3(y * point.z - z * point.y, z * point.x - x * point.z, x * point.y - y * point.x);
}

struct DecalStub
{
    char pad[0x3c];
    float v;
    void FUN_004bc480(int);
    void FUN_0068c9f0(float c);
};
// Stores c into v and calls FUN_004bc480 with 1.
// @fnv 0x0068c9f0
void DecalStub::FUN_0068c9f0(float afValue)
{
    v = afValue;
    FUN_004bc480(1);
}

struct FUN_0068c890_shell
{
    unsigned short pad[12];
    unsigned short uiFlags;
    bool HasFlag(unsigned short aFlag);
};

// @fnv 0x0068c890
bool FUN_0068c890_shell::HasFlag(unsigned short aFlag)
{
    return (uiFlags & aFlag) != 0;
}

struct FUN_0068c8b0_shell
{
    char _pad[0xe8];
    float fE8;
    void SetFieldE8(float value);
};

// @fnv 0x0068c8b0
void FUN_0068c8b0_shell::SetFieldE8(float value)
{
    fE8 = value;
}

struct NiFixedString;

extern NiFixedString* DAT_011c622c;

// @fnv 0x0068c8d0
NiFixedString* __cdecl FUN_0068c8d0()
{
    return DAT_011c622c;
}

struct NiRTTI;

extern NiRTTI g_011d6bf0;

struct FUN_0068acb0_shell
{
    NiRTTI* __thiscall GetRTTI();
};

// @fnv 0x0068acb0
NiRTTI* __thiscall FUN_0068acb0_shell::GetRTTI()
{
    return &g_011d6bf0;
}

namespace fnv_0068c870 {
struct FUN_0068c890_shell
{
    bool HasFlag(unsigned short);
    bool FUN_0068c870();
};

// @fnv 0x0068c870
bool FUN_0068c890_shell::FUN_0068c870()
{
    return HasFlag(1);
}
}  // namespace fnv_0068c870

void __cdecl _delete(void*, unsigned int);
struct S_0068b080
{
    void FUN_0068b080();
};
struct S_0068ace0
{
    void* FUN_0068ace0(unsigned int);
};
// Calls FUN_0068b080 on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x0068ace0
void* S_0068ace0::FUN_0068ace0(unsigned int flags)
{
    ((S_0068b080*)this)->FUN_0068b080();
    if (flags & 1)
        _delete(this, 0x144);
    return this;
}

// Returns the larger of the two arguments, comparing the float against the double and returning a double.
// @fnv 0x0068b050
double FUN_0068b050(double adValue, float afValue)
{
    double dMax;
    if (afValue < adValue)
        dMax = adValue;
    else
        dMax = afValue;
    return dMax;
}

struct Flt
{
    operator unsigned int();
};
struct DecalHolder
{
    bool ProcessGeometry(unsigned int);
    void FUN_00682810();
    void FUN_0068b1e0();
};
// @fnv 0x0068b1e0
void DecalHolder::FUN_0068b1e0()
{
    if (!ProcessGeometry(*(Flt*)((char*)this + 0x10C)))
        return;
    FUN_00682810();
}

namespace fnv_0068acc0 {
struct Flt
{
    operator unsigned int() const;
};

struct FUN_0068acc0_shell
{
    unsigned char _pad[0x28];
    Flt m_flt;
    void* FUN_0068acc0();
};

// @fnv 0x0068acc0
void* FUN_0068acc0_shell::FUN_0068acc0()
{
    return (void*)m_flt.operator unsigned int();
}
}  // namespace fnv_0068acc0

struct _ref_006815c0
{
    float x, y, z;
    _ref_006815c0();
};
int __cdecl ClipPolygonToPlane(void* plane, int count, _ref_006815c0* inPos, float* inB, _ref_006815c0* inC,
                               float* outB, _ref_006815c0* outPos, _ref_006815c0* outC);
struct FUN_0068d660_stand
{
    int ClipPolygonByPlanes(int count, float* a, _ref_006815c0* b, _ref_006815c0* c, float* d, _ref_006815c0* e,
                            _ref_006815c0* f);
};
// Clips the input polygon through six planes at offsets 0x64..0xb4, ping-ponging between temp and output buffers, and returns the surviving vertex count.
// @fnv 0x0068d660
int FUN_0068d660_stand::ClipPolygonByPlanes(int count, float* apInVerts, _ref_006815c0* apInB, _ref_006815c0* apInC,
                                            float* apOutB, _ref_006815c0* apOutPos, _ref_006815c0* apOutC)
{
    _ref_006815c0 tempPos[9];
    _ref_006815c0 tempC[9];
    float n[9];
    int tempB = ClipPolygonToPlane((char*)this + 0x64, count, (_ref_006815c0*)apInVerts, (float*)apInB, apInC, n,
                                   tempPos, tempC);
    if (tempB)
    {
        tempB = ClipPolygonToPlane((char*)this + 0x74, tempB, (_ref_006815c0*)n, (float*)tempPos, tempC, apOutB,
                                   apOutPos, apOutC);
        if (tempB)
        {
            tempB = ClipPolygonToPlane((char*)this + 0x84, tempB, (_ref_006815c0*)apOutB, (float*)apOutPos, apOutC, n,
                                       tempPos, tempC);
            if (tempB)
            {
                tempB = ClipPolygonToPlane((char*)this + 0x94, tempB, (_ref_006815c0*)n, (float*)tempPos, tempC, apOutB,
                                           apOutPos, apOutC);
                if (tempB)
                {
                    tempB = ClipPolygonToPlane((char*)this + 0xb4, tempB, (_ref_006815c0*)apOutB, (float*)apOutPos,
                                               apOutC, n, tempPos, tempC);
                    if (tempB)
                    {
                        tempB = ClipPolygonToPlane((char*)this + 0xa4, tempB, (_ref_006815c0*)n, (float*)tempPos, tempC,
                                                   apOutB, apOutPos, apOutC);
                    }
                }
            }
        }
    }
    return tempB;
}

struct FUN_0068b4a0_shell : BSTempEffectSimpleDecal
{
    static void FUN_0068b4a0();
};

// @fnv 0x0068b4a0
void FUN_0068b4a0_shell::FUN_0068b4a0()
{
    ms_pPreloadDecalDataFile = 0;
}

struct ScrapHeapBuffer
{
    void Deallocate(void* pointer);
};

struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};

struct Arr
{
    unsigned int* GetAt(int index);
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct BSSimpleArrayActor
{
    void Clear(bool clear);
};

struct Date
{
  public:
    ~Date()
    {}
};

MemoryManager* __cdecl FUN_00401020();
void NiFree(void* pointer);

struct FUN_0068b220_shell
{
    void CleanUpMemory();
};

// If the flag at offset 0x2d is clear, deallocates the six pointers at 0xcc-0xf4 and nulls them, then deletes each element of the array at 0xf8 and clears it.
// @fnv 0x0068b220
void FUN_0068b220_shell::CleanUpMemory()
{
    ScrapHeapBuffer* pAllocator;

    if (!reinterpret_cast<unsigned char*>(this)[0x2d])
    {
        pAllocator = FUN_00401020()->GetGeneralAllocator();

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc))
            pAllocator->Deallocate(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4))
            pAllocator->Deallocate(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc))
            pAllocator->Deallocate(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4))
            pAllocator->Deallocate(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec))
            pAllocator->Deallocate(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec));

        if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4))
            NiFree(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4));

        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xcc) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xd4) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xdc) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xe4) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xec) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0xf4) = 0;
    }

    {
        int i;

        for (i = 0; i < reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->GetFlags(); ++i)
        {
            delete reinterpret_cast<Date*>(
                reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->GetAt(i)[0]);

            reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->GetAt(i)[0] = 0;
        }
    }

    reinterpret_cast<BSSimpleArrayActor*>(reinterpret_cast<unsigned char*>(this) + 0xf8)->Clear(true);
}

struct NiNode;
struct TESObjectCELL;

struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3(float fx, float fy, float afDepth);
};

struct NiPlane
{
    float nx, ny, nz, c;
    NiPlane();
};

struct DecalList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecalList();
    ~DecalList();
};

struct GlobalObject_004a4a40
{
    int* Int();
};
extern GlobalObject_004a4a40 g_011c57fc;
extern int DAT_0119c298;
extern float DAT_0119c29c;

float cos(float);
double FUN_0068b050(double param_1, float param_2);

struct DecalData
{
    Pt3 akStart;     // 00
    Pt3 kDirection;  // 0c
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    NiNode* pNode;  // 28
    int unk2C;
    int unk30;  // 30
    int unk34;
    float f38;
    float f3C;
    float f40;
    float f44;
    TESObjectCELL* pCell;  // 48
    float f4C;
    int unk50;
    float f54;
    float f58;
    int unk5C;
    Pt3 kColor;  // 60
    int unk6C;
    char b70;
    char b71;
    char b72;
    char b73;
    char b74;
    char b75;
    char b76;
    char b77;
    char b78;
    char b79;
};

class BSTempEffect
{
  public:
    BSTempEffect(TESObjectCELL* pCell, float m_fParticleParameter5);
    virtual ~BSTempEffect();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    char b18;
    char b19;
    char b1A;
};

class FUN_0068ad20 : public BSTempEffect
{
  public:
    FUN_0068ad20(int p1, float m_fParticleParameter5, DecalData* pData);
    virtual ~FUN_0068ad20();

    int unk1C;
    NiPointer<NiNode> spNode20;
    int unk24;
    NiPointer<NiNode> spNode28;
    char b2C;
    char b2D;
    char b2E;
    int unk30;
    Pt3 kPt34;
    Pt3 kPt40;
    Pt3 kPt4C;
    Pt3 kPt58;
    NiPlane g_kFrustumPlanes[6];
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    DecalList kList;
    int unk108;
    NiPointer<NiNode> spNode10C;
    int unk110;
    float f114;
    float f118;
    float f11C;
    float f120;
    char b124;
    char b125;
    float f128;
    char b12C;
    char b12D;
    char b12E;
    float f130;
    Pt3 kPt134;
    char b140;
    char b141;
};

// @fnv 0x0068ad20
FUN_0068ad20::FUN_0068ad20(int p1, float m_fParticleParameter5, DecalData* pData)
    : BSTempEffect(pData->pCell, m_fParticleParameter5), kPt134(0.0f, 0.0f, 0.0f)
{
    b18 = 0;
    b2D = 0;
    b19 = 0;
    b1A = 0;
    unk30 = pData->unk30;
    if (DAT_0119c298 == -1)
    {
        DAT_0119c298 = *g_011c57fc.Int();
    }
    unk108 = p1;
    spNode10C = pData->pNode;
    spNode28 = 0;
    b2C = pData->b71;
    b2E = pData->b78;
    unkC4 = 0;
    unkC8 = 0;
    kPt34 = pData->akStart;
    kPt40 = pData->kDirection;
    f118 = pData->f38;
    f11C = pData->f3C;
    f120 = pData->f40;
    f114 = pData->f44;
    b124 = pData->b70;
    unk1C = 0;
    spNode20 = 0;
    DAT_0119c29c = cos((float)(pData->f58 * 0.01745329238474369));
    DAT_0119c29c = FUN_0068b050(1.1, DAT_0119c29c);
    b125 = pData->b73;
    f128 = pData->f4C;
    b12C = pData->b76;
    b12D = pData->b74;
    b12E = pData->b75;
    f130 = pData->f54;
    kPt134 = pData->kColor;
    b140 = pData->b77;
    b141 = pData->b79;
}

extern const double DAT_01012060;
extern const double DAT_01012070;
void* __cdecl FUN_004af350();

struct DecalEffect
{
    float FUN_00598040();
    void FUN_0068c9f0(float value);
};
struct DecalTarget
{
    void FUN_004ee560(void* effect);
};
struct DecalState
{
    DecalEffect* FUN_00a59d30(void* texture);
    DecalTarget* FUN_009611e0();
};
struct DecalRef
{
    DecalState* FUN_00559450();
};
struct DecalHost
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
    DecalRef decalRef;
    bool FUN_006828a0(float alpha);
    double FUN_00621b00();
    double FUN_00488d50();
    bool UpdateDecalFade(float alpha);
};
// @fnv 0x0068c8e0
bool DecalHost::UpdateDecalFade(float alpha)
{
    bool changed = FUN_006828a0(alpha);
    DecalTarget* pDecalTarget;
    if (!changed && decalRef.FUN_00559450())
    {
        float elapsed = (float)(FUN_00621b00() - FUN_00488d50());
        float intensity;
        if (elapsed >= DAT_01012060 && elapsed <= DAT_01012070)
        {
            intensity = (float)((1.0 - elapsed) / DAT_01012070);
            DecalEffect* pDecalEffect = decalRef.FUN_00559450()->FUN_00a59d30(FUN_004af350());
            DecalEffect* pEffect = pDecalEffect;
            if (pEffect && pEffect->FUN_00598040() != intensity)
                pEffect->FUN_0068c9f0(intensity);
            return true;
        }
        pDecalTarget = decalRef.FUN_00559450()->FUN_009611e0();
        if (pDecalTarget)
            pDecalTarget->FUN_004ee560(this);
    }
    return changed;
}

class B68CA10Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B68CA10Object(unsigned int uiArg);
    virtual ~B68CA10Object();

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
};

// Allocates and constructs a B68CA10Object with the given argument, returning the new object.
// @fnv 0x0068ca10
B68CA10Object* __cdecl CreateB68CA10Object(unsigned int uiArg)
{
    return new B68CA10Object(uiArg);
}

class B68CA90Geometry
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B68CA90Geometry(unsigned short usVertices, void* pvPositions, void* pvNormals, void* pvColors, void* pvTexture,
                    int iTextureSets, int iDataFlags, unsigned short usTriangles, void* pvTriList);

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
};

class B68CA90Builder
{
  public:
    B68CA90Geometry* FUN_0068ca90();

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
    unsigned short m_usVertices;
    unsigned short unkC6;
    unsigned short m_usTriangles;
    unsigned short unkCA;
    int unkCC;
    void* m_pvPositions;
    int unkD4;
    void* m_pvNormals;
    int unkDC;
    void* m_pvTexture;
    int unkE4;
    void* m_pvColors;
    int unkEC;
    void* m_pvTriList;
};

// Allocates a B68CA90Geometry from the builder's vertex, normal, color, texture and triangle data and returns it.
// @fnv 0x0068ca90
B68CA90Geometry* B68CA90Builder::FUN_0068ca90()
{
    B68CA90Geometry* pkGeometry = new B68CA90Geometry(m_usVertices, m_pvPositions, m_pvNormals, m_pvColors, m_pvTexture,
                                                      1, 0, m_usTriangles, m_pvTriList);
    return pkGeometry;
}

struct DecalTextureObject
{
    ~DecalTextureObject();
    bool FUN_00c4edf0(unsigned int* value, int flags);
};

struct FUN_0068de30_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DecalTextureObject* unk1c;
    int unk20;
    unsigned int unk24;
    bool ReleaseTextureObject();
};

// Calls FUN_00c4edf0 on unk1c with unk24; on success deletes unk1c, nulls it and returns true, otherwise returns false.
// @fnv 0x0068de30
bool FUN_0068de30_holder::ReleaseTextureObject()
{
    if (!unk1c->FUN_00c4edf0(&unk24, 0))
    {
        return false;
    }
    else
    {
        delete unk1c;
        unk1c = 0;
        return true;
    }
}

struct TESObjectCELL;
struct DecalNode;

void __cdecl FUN_00b5b0e0(void* pObject);

struct DecalOwner
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void DetachDecal(DecalNode* pNode);
};

struct DecalNode
{
    DecalOwner* GetOwner();
};

struct DecalPointList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~DecalPointList();
};

extern int DAT_011c57ec;

class FUN_0068b080 : public BSTempEffect
{
  public:
    virtual ~FUN_0068b080();
    void CleanUpMemory();

    int unk1C;
    NiPointer<DecalNode> spNode20;
    int unk24;
    NiPointer<DecalNode> spNode28;
    bool b2C;
    bool b2D;
    char b2E;
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
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    DecalPointList kList;
    int unk108;
    NiPointer<DecalNode> spNode10C;
};

// Releases the decal nodes, detaches the node from its owner, calls CleanUpMemory, and decrements DAT_011c57ec when b2D is set.
// @fnv 0x0068b080
FUN_0068b080::~FUN_0068b080()
{
    spNode10C = 0;
    unk108 = 0;
    DecalNode* pNode;
    if (!b2C && (DecalNode*)spNode28)
    {
        pNode = spNode28;
        FUN_00b5b0e0(pNode);
        if (((DecalNode*)spNode28)->GetOwner())
        {
            ((DecalNode*)spNode28)->GetOwner()->DetachDecal(spNode28);
        }
        spNode28 = 0;
    }
    CleanUpMemory();
    if (b2D)
    {
        DAT_011c57ec--;
    }
}

struct DecalSetup;
struct Color4
{
    float r, g, b, a;
    Color4(float, float, float, float);
};
struct UpdateInfo
{
    float time;
    bool a, b;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct Graph;
template <class T> class NiPointer;
struct Graph
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void texture(int, NiPointer<Graph>*);
    virtual void slot094();
    virtual Graph* geometry(int);
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual int hasFlag(int, int);
    virtual void slot0F8();
    virtual void slot0FC();
    virtual void slot100();
    virtual void attach(DecalSetup*, int);
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
    Graph* list;
    void AttachProperty(void*);
    Graph* FUN_0050d100();
    Graph* FUN_00458b50();
    bool checkFlag();
    Color4* GetNextProc();
    unsigned short FUN_00456650();
    Graph* FUN_009611e0();
    unsigned int FUN_0043b480();
    Graph* FUN_0043b4a0(unsigned int);
    void* FUN_0043c490();
    void SetWorldPosition(void*);
    void* rotation();
    void SetBodyOrientation(void*);
    float scale();
    void setScale(float);
    void refresh();
    void update(UpdateInfo&);
    void SetParentObject(void*);
    void addHead(const NiPointer<Graph>&);
};
struct Material
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Material();
    void setAlpha(float);
};
struct Alpha
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Alpha();
    void blending(bool);
    void flag512(bool);
    void flags(unsigned short);
    void threshold(unsigned char);
};
struct Stencil
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Stencil();
    void mode(int);
};
struct Shader
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual int hasFlag(int, int);
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Shader();
    void category(int);
    void flag(int, bool);
    void setTexture(int, void*);
    void intensity(float);
    void opacity(float);
};
struct Lighting
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Lighting();
    void flag(int, bool);
    void setTexture(Graph*);
};
struct Attachment
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Attachment(Graph*, int);
};
struct TextureAccessor
{
    void* getTexture();
};
struct TextureOwner
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
    Graph texturePart;
};
struct EffectList
{
    void addTail(const NiPointer<Graph>&);
    NiPointer<Graph>& head();
    void removeHead();
};
struct Manager
{
    void remove(DecalSetup*);
};
struct Setting
{
    unsigned char* Bool();
};
extern int DAT_011c57f4, DAT_011d6a20, DAT_0119c298;
extern float DAT_011c3c08;
extern EffectList g_011d6a30;
extern Manager DAT_011e0e80;
extern Setting g_011c5904;
extern int g_011c7d34;
struct NiFixedString;
NiFixedString* __cdecl FUN_0068c8d0();
void* __cdecl FUN_00688460();
void __cdecl finalize(Graph*, int, int);
void __cdecl prepare(Graph*);
void __cdecl tag(Graph*, int);
bool __cdecl matches(void*, Graph*);
void __cdecl warning(const char*, ...);
Graph* __cdecl scene(int);
struct SceneOps
{
    void add(Graph*);
};
struct DecalSetup
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual Graph* geometry(int);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    bool b018;
    bool b019;
    bool b01A;
    bool b01B;
    int unk01C;
    int unk020;
    int unk024;
    NiPointer<Graph> p028;
    bool b02C;
    bool b02D;
    bool b02E;
    bool b02F;
    TextureOwner* textures;
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
    Graph* attachment;
    NiPointer<Graph> p10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    bool b124;
    bool b125;
    bool b126;
    bool b127;
    float f128;
    unsigned char b12C;
    bool b12D;
    bool b12E;
    bool b12F;
    float f130;
    int unk134;
    int unk138;
    int unk13C;
    bool b140;
    bool b141;
    bool b142;
    bool b143;
    bool Initialize();
    void finish();
};
// @fnv 0x0068be90
bool DecalSetup::Initialize()
{
    bool disabled = false;
    if ((Graph*)p028)
    {
        Material* l = new Material;
        l->setAlpha(f130);
        ((Graph*)p028)->AttachProperty(l);
        Alpha* e = new Alpha;
        e->blending(b12E);
        e->flag512(b12D);
        e->flags(4);
        e->threshold(128);
        ((Graph*)p028)->AttachProperty(e);
        if (b141)
        {
            Stencil* stencil = new Stencil;
            stencil->mode(3);
            ((Graph*)p028)->AttachProperty(stencil);
        }
        Shader* c = 0;
        c = new Shader;
        c->category(29);
        c->flag(5, true);
        c->setTexture(0, ((TextureAccessor*)textures)->getTexture());
        if (c->hasFlag(1, 0) && !disabled)
        {
            if (c->hasFlag(3, 0))
            {
                c->flag(11, true);
                if (b125)
                {
                    c->flag(28, true);
                    c->intensity(f128);
                    c->opacity((float)(unsigned char)b12C);
                }
            }
            c->flag(27, true);
            Graph* eb = (Graph*)p10C;
            Graph* cf = eb->FUN_0050d100();
            bool q = cf->FUN_00458b50()->checkFlag();
            if (q)
                c->flag(53, true);
            ((Graph*)p028)->AttachProperty(c);
            finalize((Graph*)p028, 0, 0);
        }
        else
        {
            Lighting* cf = new Lighting;
            if (!disabled && textures && !(DAT_011c57f4 & 32))
            {
                NiPointer<Graph> texture(0);
                textures->texturePart.texture(0, &texture);
                cf->setTexture((Graph*)texture);
            }
            cf->flag(27, true);
            Graph* f = (Graph*)p10C;
            Graph* eb = f->FUN_0050d100();
            bool q = eb->FUN_00458b50()->checkFlag();
            if (q)
                cf->flag(53, true);
            ((Graph*)p028)->AttachProperty(cf);
            if (DAT_011c57f4 & 32)
            {
                Graph* geom = (Graph*)p028;
                Color4* colors = geom->GetNextProc();
                for (int index = 0; index < geom->FUN_00456650(); index++)
                    colors[index] = Color4(1, 1, 0, 1);
            }
            finalize((Graph*)p028, 0, 0);
        }
        if (b02C)
            ((Graph*)p028)->SetParentObject(FUN_0068c8d0());
        else
            ((Graph*)p028)->SetParentObject(FUN_00688460());
        prepare((Graph*)p028);
        tag((Graph*)p028, 5);
        if (!b02C)
        {
            if (b02E)
                DAT_011e0e80.remove(this);
            else
            {
                g_011d6a30.addTail((Graph*)this);
                DAT_011d6a20++;
                if (DAT_011d6a20 > DAT_0119c298)
                {
                    DAT_011e0e80.remove((DecalSetup*)(Graph*)g_011d6a30.head());
                    g_011d6a30.removeHead();
                    DAT_011d6a20--;
                    if (*g_011c5904.Bool())
                        warning("DECAL: Reached Max Decal Limit of %d! Removing oldest decal...", DAT_0119c298);
                }
            }
        }
        Graph* k = ((Graph*)p10C)->FUN_009611e0();
        Graph* ba = 0;
        bool b = false;
        if (k)
        {
            for (unsigned int childIndex = 0; childIndex < k->FUN_0043b480(); childIndex++)
            {
                Graph* child = k->FUN_0043b4a0(childIndex);
                if (child && matches(&g_011c7d34, child))
                {
                    b = true;
                    ba = child;
                    break;
                }
            }
        }
        else
        {
            b018 = true;
            return false;
        }
        if (!b)
            attachment = (Graph*)new Attachment(((Graph*)p10C)->FUN_009611e0(), 0);
        else
            attachment = ba;
        attachment->attach(this, 1);
        ((Graph*)p028)->SetWorldPosition(((Graph*)p10C)->FUN_0043c490());
        ((Graph*)p028)->SetBodyOrientation(((Graph*)p10C)->rotation());
        ((Graph*)p028)->setScale(((Graph*)p10C)->scale());
        ((Graph*)p028)->refresh();
        UpdateInfo j(DAT_011c3c08, false, false);
        ((Graph*)p028)->update(j);
        ((SceneOps*)scene(0))->add(geometry(0));
        attachment->list->addHead((Graph*)this);
        finish();
        b019 = false;
        b02D = true;
        b018 = true;
        return true;
    }
    else
    {
        b018 = true;
        return false;
    }
}

struct DecalPoint
{
    float x, y, z;
    double DotProduct(const DecalPoint&);
    double FUN_00457990();
};
struct DecalColor
{
    float r, g, b, a;
    DecalColor(float, float, float, float);
};
struct DecalPointRecord
{
    DecalPoint position;
    short index;
    short flags;
    DecalPointRecord();
};
struct DecalVertices
{
    unsigned count;
    DecalPointRecord** data;
    unsigned capacity;
    unsigned growth;
    unsigned FUN_0044ddc0();
    DecalPointRecord*& FUN_00877a30(unsigned);
    void FUN_007cb2e0(DecalPointRecord* const&);
};
struct DecalGeometry
{
    unsigned short FUN_004a1ff0();
};
struct DecalGeometryRef
{
    DecalGeometry* object;
    DecalGeometry* FUN_00559450();
};
struct DecalHeap
{
    void* FUN_00aa54a0(unsigned, unsigned);
};
struct DecalMemoryManager
{
    DecalHeap* FUN_00aa42e0();
};

void* FUN_00aa1070(unsigned);
void* FUN_00403d30(void*, int, unsigned);
bool AreVectorsEqual(const DecalPoint*, const DecalPointRecord*, float);
extern unsigned DAT_010a2720;
extern float DAT_0119c29c;
struct DecalBuilder
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    DecalPoint direction;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    int vertexCount;
    int triangleCount;
    DecalPoint* positions;
    unsigned unkD0;
    DecalPoint* normals;
    unsigned unkD8;
    void* texcoords;
    unsigned unkE0;
    DecalColor* colors;
    unsigned unkE8;
    unsigned short* triangles;
    unsigned unkF0;
    short* remap;
    DecalVertices vertices;
    unsigned unk108;
    DecalGeometryRef geometry;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    float red, green, blue;
    bool AddDecalGeometry(int, int*, DecalPoint*, DecalPoint*);
};
// @fnv 0x0068cb60
bool DecalBuilder::AddDecalGeometry(int count, int* paiIndices, DecalPoint* points, DecalPoint* vectors)
{
    long used2;
    used2 = vertexCount;
    if (used2 + count >= 512)
        return false;
    if (positions == 0)
    {
        DecalHeap* vertex_;
        vertex_ = reinterpret_cast<DecalMemoryManager*>(FUN_00401020())->FUN_00aa42e0();
        positions = (DecalPoint*)vertex_->FUN_00aa54a0(6144, DAT_010a2720);
        normals = (DecalPoint*)vertex_->FUN_00aa54a0(6144, DAT_010a2720);
        texcoords = vertex_->FUN_00aa54a0(4096, DAT_010a2720);
        colors = (DecalColor*)vertex_->FUN_00aa54a0(8192, DAT_010a2720);
        triangles = (unsigned short*)vertex_->FUN_00aa54a0(6144, DAT_010a2720);
        DecalGeometry* aMesh = geometry.FUN_00559450();
        int _numTriangles = aMesh->FUN_004a1ff0();
        remap = (short*)FUN_00aa1070(_numTriangles * 3 * 2);
        FUN_00403d30(remap, -1, _numTriangles * 3 * 2);
    }
    float scale = 1.0f / (1.0f - DAT_0119c29c);
    for (int i = 0; i < count; ++i)
    {
        unsigned int mapped8 = paiIndices[i];
        if (mapped8 != -1)
        {
            if (remap[mapped8] != -1)
            {
                paiIndices[i] = remap[mapped8];
            }
            else
            {
                positions[used2] = points[i];
                remap[mapped8] = (short)used2;
                normals[used2] = vectors[i];
                float a;
                DecalPoint normal = normals[used2];
                a = (direction.DotProduct(normal) / normal.FUN_00457990() - DAT_0119c29c) * scale;
                colors[used2] = DecalColor(red, green, blue, a > 0.0 ? a : 0.0f);
                paiIndices[i] = used2;
                used2++;
            }
        }
        else
        {
            for (unsigned jA = 0; jA < vertices.FUN_0044ddc0(); ++jA)
            {
                if (AreVectorsEqual(&points[i], vertices.FUN_00877a30(jA), 0.01f))
                {
                    mapped8 = vertices.FUN_00877a30(jA)->index;
                    break;
                }
            }
            if (mapped8 != -1)
            {
                paiIndices[i] = mapped8;
            }
            else
            {
                positions[used2] = points[i];
                DecalPointRecord* s = new DecalPointRecord;
                s->position = positions[used2];
                s->index = (short)used2;
                vertices.FUN_007cb2e0(s);
                normals[used2] = vectors[i];
                DecalPoint normal = normals[used2];
                float a = (direction.DotProduct(normal) / normal.FUN_00457990() - DAT_0119c29c) * scale;
                colors[used2] = DecalColor(red, green, blue, a > 0.0 ? a : 0.0f);
                paiIndices[i] = used2;
                used2++;
            }
        }
    }
    unsigned short* output;
    output = &triangles[triangleCount * 3];
    triangleCount += count - 2;
    int outIndex8 = 0;
    for (int i = 2; i < count; ++i)
    {
        output[outIndex8] = (unsigned short)paiIndices[0];
        outIndex8 += 1;
        output[outIndex8] = (unsigned short)paiIndices[i - 1];
        ++outIndex8;
        output[outIndex8] = (unsigned short)paiIndices[i];
        outIndex8 += 1;
    }
    vertexCount = used2;
    return true;
}

struct Point
{
    float x, y, z;
    Point();
    Point operator-(const Point&) const;
    Point Cross(const Point&) const;
    float Dot(const Point&) const;
    float Length() const;
};
struct UnsignedShortBuffer
{
    unsigned short* FUN_00a75f10();
};
struct FixedName
{
    operator const char*() const;
};
struct Geometry
{
    Point* FUN_0049ec60();
    Point* FUN_004a8030();
    UnsignedShortBuffer* FUN_005495f0();
    FixedName& FUN_00413f40();
    unsigned short FUN_004a1ff0();
};
void __cdecl FUN_005b5e40(const char*, ...);
extern float DAT_0119c29c;
struct FUN_0068d230_Class
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54;
    Point direction;
    int ClipPolygonByPlanes(int, unsigned*, Point*, Point*, unsigned*, Point*, Point*);
    bool AddDecalGeometry(int, unsigned*, Point*, Point*);
    void ProcessDecalTriangles(Geometry*);
};
// Iterates triangle strips from the geometry, skips degenerate triangles, and clips those whose face normal faces along direction past a threshold.
// @fnv 0x0068d230
void FUN_0068d230_Class::ProcessDecalTriangles(Geometry* input)
{
    Geometry* data = input;
    Point* normals = data->FUN_0049ec60();
    Point* geometry = data->FUN_004a8030();
    UnsignedShortBuffer* vertices = data->FUN_005495f0();
    if (normals && !geometry)
    {
        FUN_005b5e40("TEXTURES: Decal Parent '%s' has no normals!", (const char*)input->FUN_00413f40());
        return;
    }
    if (!vertices)
        return;
    {
        Point third[9];
        Point strip[9];
        unsigned short old;
        UnsignedShortBuffer* count = vertices;
        int first = data->FUN_004a1ff0();
        unsigned short* positions = count->FUN_00a75f10();
        unsigned second[9];
        unsigned short indices, bridge;
        for (int i = 0; i < first; i++)
        {
            if (positions[i] == positions[i + 1] || positions[i] == positions[i + 2] ||
                positions[i + 1] == positions[i + 2])
                continue;
            if (i % 2 == 0)
            {
                old = positions[i];
                indices = positions[i + 1];
                bridge = positions[i + 2];
            }
            else
            {
                old = positions[i + 1];
                indices = positions[i];
                bridge = positions[i + 2];
            }
            const Point& edge3 = normals[old];
            const Point& edge1 = normals[indices];
            const Point& a = normals[bridge];
            Point edge2 = edge1 - edge3;
            Point b = a - edge3;
            Point c = edge2.Cross(b);
            if (direction.Dot(c) > c.Length() * DAT_0119c29c)
            {
                second[0] = old;
                second[1] = indices;
                second[2] = bridge;
                third[0] = edge3;
                third[1] = edge1;
                third[2] = a;
                strip[0] = geometry[old];
                strip[1] = geometry[indices];
                strip[2] = geometry[bridge];
                int clipped = ClipPolygonByPlanes(3, second, third, strip, second, third, strip);
                if (clipped)
                {
                    if (!AddDecalGeometry(clipped, second, third, strip))
                        break;
                }
            }
        }
    }
}

namespace DecalClipping {
struct Point
{
  private:
    float x, y, z;

  public:
    Point FUN_00439ef0(const Point&);
    Point FUN_00439e90(const Point&);
    Point ApplyScaled(float);
    double DotProduct(const Point&);
};
struct Plane
{
    int ClassifyPoint(const Point&);
    const Point& FUN_006815c0();
    double FUN_0084d030();
};
extern const double DAT_01012070, DAT_01069ff0, DAT_01012060;
extern const char DAT_01069f88[];
void FUN_005b5e40(const char*, ...);
// Clips a polygon against a plane, emitting intersection vertices where edges cross it and dropping vertices outside, and returns the output vertex count.
// @fnv 0x0068d820
int ClipPolygonToPlane(Plane* plane, int count, const int* indices, const Point* positions, const Point* attributes,
                       int* outIndices, Point* outPositions, Point* outAttributes)
{
    bool outside4[10];
    int rejected = 0;
    for (int i = 0; i < count; ++i)
    {
        if (plane->ClassifyPoint(positions[i]) == 2)
        {
            outside4[i] = true;
            ++rejected;
        }
        else
            outside4[i] = false;
    }
    if (rejected == count)
        return 0;
    int output = 0;
    for (int current = 0; current < count; ++current)
    {
        int previous = current ? current - 1 : count - 1;
        if (outside4[current])
        {
            if (!outside4[previous])
            {
                Point start4 = positions[previous];
                Point _end = positions[current];
                Point edgeTmp = start4.FUN_00439ef0(_end);
                Point normal = plane->FUN_006815c0();
                float fraction = (normal.DotProduct(start4) + -plane->FUN_0084d030()) / normal.DotProduct(edgeTmp);
                if (fraction > DAT_01012070 && fraction <= DAT_01069ff0)
                    fraction = 1.0f;
                if (fraction < DAT_01012060)
                {
                    FUN_005b5e40(DAT_01069f88, fraction);
                    fraction = 0.0f;
                }
                else if (fraction > DAT_01012070)
                {
                    FUN_005b5e40(DAT_01069f88, fraction);
                    fraction = 1.0f;
                }
                outIndices[output] = -1;
                outPositions[output] = start4.ApplyScaled(1.0f - fraction).FUN_00439e90(_end.ApplyScaled(fraction));
                Point _startAttr = attributes[previous];
                Point endAttr = attributes[current];
                outAttributes[output] =
                    endAttr.ApplyScaled(1.0f - fraction).FUN_00439e90(_startAttr.ApplyScaled(fraction));
                ++output;
            }
        }
        else
        {
            if (outside4[previous])
            {
                Point start_ = positions[current];
                Point end2 = positions[previous];
                Point edge_ = start_.FUN_00439ef0(end2);
                Point normal3 = plane->FUN_006815c0();
                float fraction2 = (normal3.DotProduct(start_) + -plane->FUN_0084d030()) / normal3.DotProduct(edge_);
                if (fraction2 < DAT_01012060)
                {
                    FUN_005b5e40(DAT_01069f88, fraction2);
                    fraction2 = 0.0f;
                }
                else if (fraction2 > DAT_01012070)
                {
                    FUN_005b5e40(DAT_01069f88, fraction2);
                    fraction2 = 1.0f;
                }
                outIndices[output] = -1;
                outPositions[output] = start_.ApplyScaled(1.0f - fraction2).FUN_00439e90(end2.ApplyScaled(fraction2));
                Point startAttr6 = attributes[current];
                Point endAttr4 = attributes[previous];
                outAttributes[output] =
                    endAttr4.ApplyScaled(1.0f - fraction2).FUN_00439e90(startAttr6.ApplyScaled(fraction2));
                ++output;
            }
            outIndices[output] = indices[current];
            outPositions[output] = positions[current];
            outAttributes[output] = attributes[current];
            ++output;
        }
    }
    return output;
}
}

extern int DAT_011f4a20;
extern int DAT_011f426c;
extern char str_01069efc;

struct P3
{
    float x;
    float y;
    float z;
    void FUN_006815c0();
    float DotProduct(P3*);
    P3 FUN_00439ef0(P3*);
    P3 ApplyScaled(float);
};
struct M3
{
    float m[9];
    void FUN_006815c0();
    void FUN_004b45b0(M3*);
    P3 FUN_004b4500(P3*);
    void FUN_00476930(int, P3*);
};
struct Plane
{
    float x;
    float y;
    float z;
    float w;
    Plane* FUN_00a69970(P3*, float);
};
struct V2
{
    float x;
    float y;
    V2* FUN_00452dc0(float, float);
};
struct H36
{
    float m[9];
    void FUN_006815c0();
    void FUN_004a0c90(float);
    M3 FUN_0043f8d0(M3*);
};
struct SubOut
{
    float x;
    float y;
    float z;
    P3* FUN_00439ef0(P3*, P3*);
};
struct PtSet
{
    P3* FUN_00416870(float, float, float);
};
struct Param
{
    P3* FUN_0045bb80();
    float FUN_008d01e0();
    M3* FUN_006a9540();
    M3* FUN_00461130();
};
struct Sub28
{
    int dummy;
    void FUN_0066b0d0(int);
    void* FUN_00559450();
};
struct StrObj
{
    const char* FUN_0043b1b0();
};
struct MidObj
{
    StrObj* FUN_00413f40();
};
struct Obj10c
{
    int dummy;
    MidObj* FUN_00559450();
};
struct Sing
{
    unsigned char b0;
    Sing* FUN_00408d60();
};
struct Node8
{
    void* p;
    V2* secondary;
};

bool __cdecl FUN_0043b300(const char*, Param*);
void __cdecl FUN_00a582f0(M3*, const char*, int, P3*, P3*);
void __cdecl FUN_00c4b600(M3*, P3);
int __cdecl CreateB68CA10Object(int);
void __cdecl FUN_005b5e40(const char*, const char*);
extern Sing DAT_011c5904;

struct FUN_00416870 : P3
{
    FUN_00416870(float, float, float);
};
struct FUN_00a69970 : Plane
{
    FUN_00a69970(const P3&, float);
};
struct FUN_00452dc0 : V2
{
    FUN_00452dc0(float, float);
};

struct Host
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char u1a;
    unsigned char u1b;
    int u1c;
    int u20;
    int u24;
    Sub28 m_28;
    unsigned char flag2c;
    unsigned char u2d;
    unsigned char u2e;
    unsigned char u2f;
    int u30;
    P3 m_34;
    P3 m_40;
    P3 m_4c;
    P3 m_58;
    Plane m_64;
    Plane m_74;
    Plane m_84;
    Plane m_94;
    Plane m_a4;
    Plane m_b4;
    int m_c4;
    int m_c8;
    P3* m_cc;
    Node8 m_kNodeCollection[5];
    unsigned int unknownf8;
    int uf8;
    int ufc;
    int u100;
    int u104;
    Obj10c m_10c;
    int u110;
    float f114;
    float f118;
    float f11c;
    float f120;
    unsigned char mode124;
    unsigned char u125;
    unsigned char u126;
    unsigned char u127;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    unsigned char flag140;
    void ProcessDecalTriangles(Param*);
    void ResizeMeshBuffers();
    int FUN_0068ca90();
    bool ProcessGeometry(Param*);
};

// @fnv 0x0068b4c0
bool Host::ProcessGeometry(Param* apParam)
{
    float vValue40;
    int modeValue10;
    float uValue22;
    P3 diffValue4;
    int iValue13;
    int tValue0;
    float inv11cValue22;
    float inv118Value2;
    M3 mecValue16;
    float dotValue29;
    P3 gValue23;
    M3 m1Value12;
    P3 fValue3;
    M3 m2Value40;
    H36 hValue8;
    P3 eValue2;
    P3 d40Value6;
    P3 c34Value43;
    P3 aValue1;
    P3 bValue0;
    bool resultValue23;

    aValue1.FUN_006815c0();

    bValue0.FUN_006815c0();
    if (apParam && FUN_0043b300((const char*)&DAT_011f4a20, apParam))
    {

        c34Value43 = m_34;

        d40Value6 = m_40;

        fValue3.FUN_006815c0();

        gValue23.FUN_006815c0();

        m1Value12.FUN_006815c0();
        if (flag140)
            m1Value12 = *apParam->FUN_006a9540();
        else
            m1Value12 = *apParam->FUN_00461130();

        m1Value12.FUN_004b45b0(&mecValue16);
        fValue3 = mecValue16.FUN_004b4500(&d40Value6);

        eValue2.FUN_006815c0();
        if (flag140)
        {
            eValue2 = c34Value43;
        }
        else
        {
            eValue2 = c34Value43.FUN_00439ef0(apParam->FUN_0045bb80());
            eValue2 = eValue2.ApplyScaled(1.0f / apParam->FUN_008d01e0());
        }
        FUN_00a582f0(&mecValue16, (const char*)&DAT_011f426c, 1, &eValue2, &gValue23);
        f118 *= 1.0f / apParam->FUN_008d01e0();
        f11c *= 1.0f / apParam->FUN_008d01e0();
        f120 *= 1.0f / apParam->FUN_008d01e0();
        m_4c = gValue23;
        m_58 = fValue3;

        FUN_00c4b600(&m2Value40, fValue3);

        hValue8.FUN_006815c0();
        hValue8.FUN_004a0c90(f114);
        m2Value40 = hValue8.FUN_0043f8d0(&m2Value40);
        m2Value40.FUN_00476930(0, &aValue1);
        m2Value40.FUN_00476930(1, &bValue0);

        dotValue29 = m_4c.DotProduct(&aValue1);
        {
            m_64 = FUN_00a69970(FUN_00416870(aValue1.x, aValue1.y, aValue1.z), -(f118 * 0.5 - dotValue29));
        }
        {
            m_74 = FUN_00a69970(FUN_00416870(-aValue1.x, -aValue1.y, -aValue1.z), -(f118 * 0.5 + dotValue29));
        }
        dotValue29 = m_4c.DotProduct(&bValue0);
        {
            m_84 = FUN_00a69970(FUN_00416870(bValue0.x, bValue0.y, bValue0.z), -(f11c * 0.5 - dotValue29));
        }
        {
            m_94 = FUN_00a69970(FUN_00416870(-bValue0.x, -bValue0.y, -bValue0.z), -(f11c * 0.5 + dotValue29));
        }
        dotValue29 = m_4c.DotProduct(&m_58);
        {
            m_a4 = FUN_00a69970(FUN_00416870(-m_58.x, -m_58.y, -m_58.z), -(f120 + dotValue29));
        }
        {
            m_b4 = FUN_00a69970(FUN_00416870(m_58.x, m_58.y, m_58.z), -(f120 - dotValue29));
        }
        ProcessDecalTriangles(apParam);
        if (m_c8 == 0)
        {
            m_18 = 1;
            if (DAT_011c5904.FUN_00408d60()->b0)
            {
                FUN_005b5e40(&str_01069efc, m_10c.FUN_00559450()->FUN_00413f40()->FUN_0043b1b0());
            }
            resultValue23 = false;
        }
        else
        {
            inv118Value2 = 1.0f / f118;
            inv11cValue22 = 1.0f / f11c;

            for (iValue13 = 0; iValue13 < m_c4; iValue13++)
            {

                ((SubOut*)&m_cc[iValue13])->FUN_00439ef0(&diffValue4, &m_4c);
                uValue22 = diffValue4.DotProduct(&aValue1) * inv118Value2 + 0.5;
                vValue40 = diffValue4.DotProduct(&bValue0) * inv11cValue22 + 0.5;
                modeValue10 = mode124;
                uValue22 = uValue22 / 2.0;
                vValue40 = vValue40 / 2.0;
                switch (modeValue10)
                {
                case 0:
                    break;
                case 1:
                    uValue22 = uValue22 + 0.5;
                    break;
                case 2:
                    vValue40 = vValue40 + 0.5;
                    break;
                case 3:
                    uValue22 = uValue22 + 0.5;
                    vValue40 = vValue40 + 0.5;
                    break;
                default:
                    uValue22 = uValue22 * 2.0;
                    vValue40 = vValue40 * 2.0;
                    break;
                }
                if (flag2c)
                {
                    m_kNodeCollection[1].secondary[iValue13] = FUN_00452dc0(1.0f - uValue22, vValue40);
                }
                else
                {
                    m_kNodeCollection[1].secondary[iValue13] = FUN_00452dc0(uValue22, vValue40);
                }
            }
            ResizeMeshBuffers();
            tValue0 = FUN_0068ca90();
            m_28.FUN_0066b0d0(CreateB68CA10Object(tValue0));
            if (m_28.FUN_00559450())
            {
                m_kNodeCollection[0].p = 0;
                m_kNodeCollection[1].p = 0;
                m_kNodeCollection[2].p = 0;
                m_kNodeCollection[3].p = 0;
                m_kNodeCollection[4].p = 0;
            }
            m_19 = 1;
            resultValue23 = true;
        }
    }
    else
    {
        m_18 = 1;
        resultValue23 = false;
    }
    return resultValue23;
}

struct xPoint3
{
    float x, y, z;
    bool IsEqual(const xPoint3&);
};
struct xColorA
{
    float r, g, b, a;
};
struct xMat
{
    xMat();
    xMat Transpose();
    xPoint3 operator*(const xPoint3&) const;
    xMat operator*(const xMat&) const;
    void SetZRotation(float);
    float m[9];
};
xMat xFromEuler(xPoint3);
extern const xPoint3 xg_Zero;
struct xFixedStr
{
    xFixedStr(const char*);
    ~xFixedStr();
    const char* m_p;
};
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB;
    int m_iThirdValue;
};
struct xNode;
struct xGO;

struct xVObj
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Refresh();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AddNode(xNode*, bool);
};
struct xAV
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
    virtual struct xAV* GetObjectByName(const xFixedStr&);
    void SetName(const xFixedStr&);
    void Clone(xGO&);
    void GetTransformScale(const xPoint3*);
    void SetLocalRotation(const xMat&);
    void SetScale(float);
    void AttachProperty(void*);
    void F68e740();
    void Update(const xUpdateData&);
    xVObj* GetParentObj();
    const xMat& GetRotate();
    const xMat& GetWorldRotate();
    const xPoint3* GetTranslate();
    float GetScale();
};

struct xNode : xAV
{
};
struct xGeom : xAV
{
    xPoint3* GetVertices();
    xColorA* GetColors();
    unsigned short GetVertexCount();
};
struct xGO
{
    xGO(xAV*);
    ~xGO();
    operator xNode*();
    xNode* operator->();
    void operator=(xAV*);
    xAV* m_p;
};
extern xGO xg_DecalBox;
struct xStream
{
    xStream();
    ~xStream();
    bool Load(const char*, bool);
    xAV* GetObjectAt(unsigned int);
    char m_auiShapeKeys[0x5d0];
};
int __fastcall xObjCount(xStream*);
struct xNiObj
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct xAlpha : xNiObj
{
    xAlpha();
    void SetBlend(bool);
    int m_auiShapeKeys[7];
};
struct xShaderProp : xNiObj
{
    xShaderProp();
    void SetFlag(int, int);
    int m_auiShapeKeys[0x20];
};
struct xDecalNode : xNiObj
{
    xDecalNode(float);
    int m_auiShapeKeys[0x2c];
};
struct xTES
{
    void AddDecal(xNode*, float);
};
extern xTES* xg_TES;
void x62bc10(xNode*);
bool xIsNear(float, float, float);
void xb57e30(xAV*, int, int);
struct FUN_0068dea0_cls
{
    int m_auiShapeKeys[13];
    xPoint3 m_34, m_40, m_4c, m_58;
    int m_pad64[0x2a];
    xGO m_10c;
    int m_110;
    float m_114, m_118, m_11c, m_120;
    int m_pad124[7];
    bool m_140;
    void UpdateDebugDecalBox(const xColorA*, bool);
};

// Loads and clones the debug decal box, scales its vertices, sets its color and rotation, attaches alpha and shader properties, and adds it to the scene.
// @fnv 0x0068dea0
void FUN_0068dea0_cls::UpdateDebugDecalBox(const xColorA* COLOR, bool FLAG)
{
    if (!xg_DecalBox)
    {
        xStream qfTOqo;
        if (qfTOqo.Load("Data\\Meshes\\Decals\\DebugDecalBox.NIF", false))
        {
            if (xObjCount(&qfTOqo) == 1)
                xg_DecalBox = qfTOqo.GetObjectAt(0);
            xg_DecalBox->SetName(xFixedStr("Debug Decal Box"));
        }
    }
    if (xg_DecalBox)
    {
        xGO qrzAir(0);
        xg_DecalBox->Clone(qrzAir);
        xNode* qbXcw = qrzAir;
        xAV* qrKBG = qbXcw->GetObjectByName(xFixedStr("DebugDecalBox01:0"));
        xGeom* qZAdkzg = (xGeom*)qrKBG;
        x62bc10(qbXcw);
        xPoint3* qGfbX = qZAdkzg->GetVertices();
        xColorA* qArxcFu = qZAdkzg->GetColors();
        for (int qJDuOZ = 0; qJDuOZ < qZAdkzg->GetVertexCount(); qJDuOZ++)
        {
            qGfbX[qJDuOZ].x = qGfbX[qJDuOZ].x * m_118;
            qGfbX[qJDuOZ].y = qGfbX[qJDuOZ].y * m_11c;
            qGfbX[qJDuOZ].z *= m_120 * 2.0f;
            qArxcFu[qJDuOZ] = *COLOR;
        }
        if (xIsNear(m_58.x, 0.0f, 0.001f))
            m_58.x = 0.0f;
        if (xIsNear(m_58.y, 0.0f, 0.001f))
            m_58.y = 0.0f;
        if (xIsNear(m_58.z, 0.0f, 0.001f))
            m_58.z = 0.0f;
        xPoint3 qxQHW = m_58;
        if (qxQHW.IsEqual(xg_Zero))
        {
            qxQHW = m_40;
            xMat qpia;
            if (m_140)
                qpia = m_10c->GetRotate();
            else
                qpia = m_10c->GetWorldRotate();
            xMat qZWI = qpia.Transpose();
            qxQHW = qZWI * qxQHW;
        }
        xMat qRqUtp = xFromEuler(qxQHW);
        xMat qAhbO;
        qAhbO.SetZRotation(-m_114);
        if (m_140)
        {
            qbXcw->GetTransformScale(m_10c->GetTranslate());
            qbXcw->SetLocalRotation(m_10c->GetRotate());
            qbXcw->SetScale(m_10c->GetScale());
            xMat qXMUYT = qRqUtp * qAhbO;
            qrKBG->SetLocalRotation(qXMUYT);
            qrKBG->GetTransformScale(&m_4c);
        }
        else
        {
            xMat qbfQdhM = m_10c->GetWorldRotate() * qRqUtp * qAhbO;
            qrKBG->SetLocalRotation(qbfQdhM);
            qrKBG->GetTransformScale(&m_34);
        }
        qbXcw->F68e740();
        {
            xAlpha* qAXSCg = new xAlpha();
            qAXSCg->SetBlend(true);
            qbXcw->AttachProperty(qAXSCg);
        }
        xShaderProp* qsTDDg = new xShaderProp();
        if (FLAG)
            qsTDDg->SetFlag(0x30, 1);
        qrKBG->AttachProperty(qsTDDg);
        xb57e30(qrKBG, 0, 0);
        if (m_140)
        {
            xVObj* qBLsiu = (xVObj*)new xDecalNode(30.0f);
            qBLsiu->AddNode(qbXcw, true);
            m_10c->GetParentObj()->AddNode((xNode*)qBLsiu, true);
        }
        else
            xg_TES->AddDecal(qbXcw, 30.0f);
        qbXcw->GetParentObj()->Refresh();
        xUpdateData qBCzzXA(0.0f, false, false);
        qbXcw->Update(qBCzzXA);
    }
}

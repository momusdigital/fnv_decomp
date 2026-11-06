// fallout_shared/sky/sun.cpp: Sun, NiPick, A6A0Sun (11 functions)

#include "sun_decls.h"
// Initializes the Sun object's fields to zero and creates a BSShaderAccumulator for SunMode, disabling occlusion tests.
// @fnv 0x006404f0
Sun::Sun()
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    m_pSunGlarePick = 0;
    m_fSunGlareIntensity = 0.0f;
    bDoOcclusionTests = false;
    m_pSunShaderAccumulator = reinterpret_cast<NiAVObject*>(new BSShaderAccumulator(BSShaderManager::SunMode, 1, 1));
}

// @fnv 0x00461110
int __fastcall FUN_00461110(int param_1)
{
    return param_1 + 0x78;
}

// @fnv 0x00514f30
int __fastcall FUN_00514f30(int this_ptr)
{
    return this_ptr + 0xC0;
}

struct NiPick
{
    virtual ~NiPick();
    void* ScalarDeletingDestructor(unsigned int flags);
};

// Destroys the NiPick object and, when flags has bit 0 set, frees its memory via operator delete; returns this.
// @fnv 0x006407e0
void* NiPick::ScalarDeletingDestructor(unsigned int flags)
{
    NiPick::~NiPick();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_00640670_shell
{
    void FUN_006406a0();
    void* FUN_00640670(unsigned int);
};
// @fnv 0x00640670
void* FUN_00640670_shell::FUN_00640670(unsigned int flags)
{
    this->FUN_006406a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00642660_shell
{
    float m_data[3][3];
    void SetMatrixElement(int a, int b, float v);
};
// @fnv 0x00642660
void FUN_00642660_shell::SetMatrixElement(int aiRow, int aiColumn, float afValue)
{
    m_data[aiRow][aiColumn] = afValue;
}

namespace fnv_00640810 {
struct BSMaterialEmittanceMultController;
struct BSRefractionFirePeriodController;
struct BSRefractionStrengthController;
struct BSShaderNoLightingProperty;
struct BSShaderPPLightingProperty;
struct BSShaderProperty;
struct BSShaderTextureSet;
struct NiAVObject;
struct NiAlphaController;
struct NiMaterialColorController;
struct NiNode;
struct NiStream;
struct SkyShaderProperty;
struct TallGrassShaderProperty;
struct TileShaderProperty;
struct VolumetricFogShaderProperty;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
typedef char _sizecheck_NiColorA[sizeof(RgbaColor) == 16 ? 1 : -1];
struct ShaderPropertyConversionData
{
    void Convert(NiAVObject*, unsigned int);
    void CheckTextureAlphas();
    void AddShaderProperty(NiAVObject*);
    void AddMaterialProperty(NiAVObject*);
    void AddAlphaProperty(NiAVObject*);
    BSShaderProperty* GetShaderProperty();
    void SetupShaderFlags(BSShaderProperty*, NiAVObject*);
    void SetupTexturesPPLightingShader(BSShaderPPLightingProperty*);
    void SetupDataPPLightingShader(BSShaderPPLightingProperty*);
    void SetupTexturesNoLightingShader(BSShaderNoLightingProperty*);
    void SetupDataVolumetricFogShader(VolumetricFogShaderProperty*);
    void SetupTexturesTallGrassShader(TallGrassShaderProperty*);
    void SetupTexturesSkyShader(SkyShaderProperty*);
    void SetupDataSkyShader(SkyShaderProperty*);
    void SetupTexturesTileShader(TileShaderProperty*);
    bool IsValidProperty(NiAVObject*, BSShaderProperty*);
    int m_iShaderType;
    char m_kAmbientColor[12];
    char m_kDiffuseColor[12];
    float m_fShininess;
    float fAlpha;
    float m_fEmittanceMultiplier;
    NiMaterialColorController* m_pAmbientColorController;
    NiMaterialColorController* m_pDiffuseColorController;
    NiAlphaController* m_pAlphaController;
    BSMaterialEmittanceMultController* m_pEmittanceMultiplierController;
    bool m_bHasMaterialProperty;
    char _pad_39[3];
    int m_iShaderFlags1;
    int m_iShaderFlags2;
    bool m_bHasAlphaProperty;
    char _pad_45[3];
    int m_iShaderOption;
    unsigned char m_uiShaderOptionByte;
    bool m_bShaderFeature1;
    bool m_bShaderFeature2;
    bool m_bShaderFeature3;
    bool m_bShaderFeature4;
    bool m_bShaderFeature5;
    bool m_bShaderFeature6;
    bool m_bShaderFeatureActive;
    bool m_bShaderFeature8;
    bool m_bShaderFeature9;
    bool m_bShaderFeature10;
    bool m_bShaderFeature11;
    float m_fValueBeforeTextureCount;
    bool m_bShaderFeature12;
    char _pad_5d[3];
    int m_iTextureCount;
    BSRefractionStrengthController* m_pRefractionStrengthController;
    BSRefractionFirePeriodController* m_pRefractionFirePeriodController;
    bool m_bShaderFeature13;
    bool m_bShaderFeature14;
    char _pad_6e[2];
    float m_fRefractionStrength;
    float m_fRefractionFirePeriod;
    char m_kSpecularColor[12];
    float m_fShaderParameter1;
    bool m_bShaderFeature15;
    bool m_bShaderFeature16;
    bool m_bShaderFeature17;
    char _pad_8b[1];
    float m_fShaderParameter2;
    int m_iShaderOptionIndex;
    bool m_bShaderFeature18;
    char _pad_95[3];
    RgbaColor m_kEmissiveColor;
    BSShaderTextureSet* m_pTextureSet;
    char m_cTrailingBytes[7];
    char _pad_b3[1];
    int m_iShaderDataFlags;
};
typedef char _sizecheck_BSShaderData[sizeof(ShaderPropertyConversionData) == 184 ? 1 : -1];
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_00640810_shell : public Sun
{
    void FUN_00640810(NiNode*);
};

namespace _ {
struct SunPoint3 : NiPoint3
{
    SunPoint3();
    SunPoint3(float, float, float);
};
struct SunPoint2 : NiPoint2
{
    SunPoint2();
    SunPoint2(float, float);
};
struct SunColorA : RgbaColor
{
    SunColorA();
    SunColorA(float, float, float, float);
};
struct SkyObject
{
    void Initialize(NiNode*);
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
}

struct NiColor
{
    float r, g, b;
};
struct C3;

struct NiAVObject : _::NiMemObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    void FUN_00440490(float);
    char _pad_04[0x98];
};
struct NiNode : NiAVObject
{
    virtual void AttachChildInAvailableSlot(NiAVObject* pkChild, bool abFirstAvailableSlot);
    void FUN_004902f0(bool);
    char _pad_9c[0x10];
};
struct FUN_0051cf00 : NiNode
{
    FUN_0051cf00();
    void FUN_0051d000(int);
    char _pad_ac[0x8];
};
struct NiTriBasedGeom : NiAVObject
{
    void FUN_004902f0(bool);
    char _pad_9c[0x24];
};
struct NiTriShape : NiTriBasedGeom
{
    NiTriShape(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, void* pkColor, NiPoint2* pkTexture,
               unsigned short usNumTextureSets, unsigned int eNBTMethod, unsigned short usTriangles,
               unsigned short* pusTriList);
    char _pad_c0[0x4];
};
struct NiPointLight : NiAVObject
{
    void FUN_0050dd20(float);
    void SetEffectColor(const NiPoint3&);
    char _pad_9c[0x58];
};
struct NiDirectionalLight : NiPointLight
{
    NiDirectionalLight();
    char _pad_f4[0x8];
};
struct FUN_004bc280_S
{
    void FUN_004bc280(const C3*);
};
struct GlobalObject_00e98f20
{
    GlobalObject_00e98f20(int, int);
    char _pad_00[0x34];
};
struct QuantityData
{
    void SetQuantity(unsigned int);
};
struct TESObjectREFR
{
    void SetFlags(unsigned int);
};
struct FUN_00632d20_shell
{
    void SetFrontOnly(bool);
};
struct RadioSignal
{
    void SetByteAtOffset17(unsigned char);
};
struct FUN_00baf3c0_S
{
    void FUN_00baf3c0();
};
struct FUN_00bb0180_S
{
    void AddProperties(NiAVObject*, unsigned int);
};
struct NP
{
    NP& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct Setting_S
{
    float* Float();
};
void* __cdecl _NiMalloc(unsigned int);

extern Setting_S g_011cce7c;
extern Setting_S g_011cce50;
extern NiColor DAT_011a9b7c;
extern NiPoint3 _NiPoint3_ZERO;

struct FUN_00640810_t
{
    void FUN_00640810(NiNode* apSkyRoot);
};

// @fnv 0x00640810
void FUN_00640810_t::FUN_00640810(NiNode* apSkyRoot)
{
    NiPoint3* psunNormals;
    NiPoint3* pglareNormals;
    RgbaColor* psunColors;
    unsigned short* sglareVertOrder;
    NiPoint3* pglareVertices;
    RgbaColor* pglareColors;
    ShaderPropertyConversionData bsshaderdata;
    unsigned short* ssunVertOrder;
    NiPoint3* psunVertices;
    NiPoint2* psunTexture;
    NiPoint2* pglareTexture;

    ((_::SkyObject*)(Sun*)this)->Initialize(apSkyRoot);

    psunVertices = new _::SunPoint3[4];
    psunVertices[0] = _::SunPoint3(-1.0 * *g_011cce7c.Float(), *g_011cce7c.Float(), 0.0f);
    psunVertices[1] = _::SunPoint3(-1.0 * *g_011cce7c.Float(), -1.0 * *g_011cce7c.Float(), 0.0f);
    psunVertices[2] = _::SunPoint3(*g_011cce7c.Float(), *g_011cce7c.Float(), 0.0f);
    psunVertices[3] = _::SunPoint3(*g_011cce7c.Float(), -1.0 * *g_011cce7c.Float(), 0.0f);

    psunNormals = new _::SunPoint3[4];
    psunNormals[0] = _NiPoint3_ZERO;
    psunNormals[1] = _NiPoint3_ZERO;
    psunNormals[2] = _NiPoint3_ZERO;
    psunNormals[3] = _NiPoint3_ZERO;

    pglareVertices = new _::SunPoint3[4];
    pglareVertices[0] = _::SunPoint3(-1.0 * *g_011cce50.Float(), *g_011cce50.Float(), 0.0f);
    pglareVertices[1] = _::SunPoint3(-1.0 * *g_011cce50.Float(), -1.0 * *g_011cce50.Float(), 0.0f);
    pglareVertices[2] = _::SunPoint3(*g_011cce50.Float(), *g_011cce50.Float(), 0.0f);
    pglareVertices[3] = _::SunPoint3(*g_011cce50.Float(), -1.0 * *g_011cce50.Float(), 0.0f);

    pglareNormals = new _::SunPoint3[4];
    pglareNormals[0] = _NiPoint3_ZERO;
    pglareNormals[1] = _NiPoint3_ZERO;
    pglareNormals[2] = _NiPoint3_ZERO;
    pglareNormals[3] = _NiPoint3_ZERO;

    {
        _::SunColorA defaultColor(1.0f, 0.0f, 0.0f, 1.0f);

        psunColors = new _::SunColorA[4];
        psunColors[0] = defaultColor;
        psunColors[1] = defaultColor;
        psunColors[2] = defaultColor;
        psunColors[3] = defaultColor;

        pglareColors = new _::SunColorA[4];
        pglareColors[0] = defaultColor;
        pglareColors[1] = defaultColor;
        pglareColors[2] = defaultColor;
        pglareColors[3] = defaultColor;
    }

    psunTexture = new _::SunPoint2[4];
    psunTexture[0] = _::SunPoint2(0.0f, 0.0f);
    psunTexture[1] = _::SunPoint2(0.0f, 1.0f);
    psunTexture[2] = _::SunPoint2(1.0f, 0.0f);
    psunTexture[3] = _::SunPoint2(1.0f, 1.0f);

    pglareTexture = new _::SunPoint2[4];
    pglareTexture[0] = _::SunPoint2(0.0f, 0.0f);
    pglareTexture[1] = _::SunPoint2(0.0f, 1.0f);
    pglareTexture[2] = _::SunPoint2(1.0f, 0.0f);
    pglareTexture[3] = _::SunPoint2(1.0f, 1.0f);

    ssunVertOrder = (unsigned short*)_NiMalloc(sizeof(unsigned short) * 6);
    ssunVertOrder[0] = 0;
    ssunVertOrder[1] = 1;
    ssunVertOrder[2] = 2;
    ssunVertOrder[3] = 2;
    ssunVertOrder[4] = 1;
    ssunVertOrder[5] = 3;

    sglareVertOrder = (unsigned short*)_NiMalloc(sizeof(unsigned short) * 6);
    sglareVertOrder[0] = 0;
    sglareVertOrder[1] = 1;
    sglareVertOrder[2] = 2;
    sglareVertOrder[3] = 2;
    sglareVertOrder[4] = 1;
    sglareVertOrder[5] = 3;

    (NP&)((Sun*)this)->m_pThirdSceneObject =
        new NiTriShape(4, psunVertices, psunNormals, psunColors, psunTexture, 1, 0, 2, ssunVertOrder);
    ((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject)->FUN_004902f0(true);

    (NP&)((Sun*)this)->m_pFirstSceneObject = new FUN_0051cf00;
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)->FUN_004902f0(true);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)->FUN_0051d000(2);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)
        ->AttachChildInAvailableSlot((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject, true);

    (NP&)((Sun*)this)->m_pFourthSceneObject =
        new NiTriShape(4, pglareVertices, pglareNormals, pglareColors, pglareTexture, 1, 0, 2, sglareVertOrder);
    ((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject)->FUN_004902f0(true);

    (NP&)((Sun*)this)->m_pSecondSceneObject = new FUN_0051cf00;
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)->FUN_004902f0(true);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)->FUN_0051d000(2);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)
        ->FUN_00440490(((Sun*)this)->m_fSunGlareIntensity);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)
        ->AttachChildInAvailableSlot((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject, true);

    ((NiNode*)(unsigned int)(const Flt&)((Sun*)this)->m_pRootNode)
        ->AttachChildInAvailableSlot((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject, true);

    (NP&)((Sun*)this)->m_pMenuLight = new NiDirectionalLight;
    ((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)->FUN_0050dd20(1.0f);
    ((FUN_004bc280_S*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)->FUN_004bc280((const C3*)&DAT_011a9b7c);
    ((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)
        ->SetEffectColor((const NiPoint3&)DAT_011a9b7c);
    ((NiNode*)(unsigned int)(const Flt&)((Sun*)this)->m_pRootNode)
        ->AttachChildInAvailableSlot((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight, true);

    ((Sun*)this)->m_pSunGlarePick = new GlobalObject_00e98f20(0, 8);
    ((QuantityData*)((Sun*)this)->m_pSunGlarePick)->SetQuantity(1);
    ((TESObjectREFR*)((Sun*)this)->m_pSunGlarePick)->SetFlags(1);
    ((FUN_00632d20_shell*)((Sun*)this)->m_pSunGlarePick)->SetFrontOnly(true);
    ((RadioSignal*)((Sun*)this)->m_pSunGlarePick)->SetByteAtOffset17(1);

    ((FUN_00baf3c0_S*)&bsshaderdata)->FUN_00baf3c0();
    bsshaderdata.m_iShaderType = 6;
    bsshaderdata.m_iShaderOptionIndex = 0;
    ((FUN_00bb0180_S*)&bsshaderdata)
        ->AddProperties((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject, 1);
    bsshaderdata.m_iShaderOptionIndex = 1;
    ((FUN_00bb0180_S*)&bsshaderdata)
        ->AddProperties((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject, 1);
}
}  // namespace fnv_00640810

namespace fnv_00641830 {
struct Actor;
struct Atmosphere;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSFile;
struct BSFogProperty;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct Clouds;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImageSpaceModifierInstanceForm;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct Moon;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiNode;
struct NiPick;
struct NiRenderedTexture;
struct NiStream;
struct Precipitation;
struct SeenData;
struct Sky;
struct SkyTextureManager;
struct Stars;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWeather;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];
struct FUN_00641830_shell : public Sun
{
    void UpdateSun(Sky*, float);
};

struct TES;
struct C3;
struct V3;
struct NiNode_00558310;
namespace H {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int pad;
};
struct ThreeByThreeMatrix
{
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
    void SetYRotation(float);
    void SetMatrixElement(int, int, float);
    float m[9];
};
struct SkyObject
{
    void Update(Sky*, float);
};
struct NiPoint3
{
    void ComputeMagnitude();
};
}
struct Setting_S
{
    float* Float();
};
struct GlobalObject_0044f440
{
    float FUN_00450410();
};
struct Flt
{
    operator unsigned int() const;
};
struct RgbaColor
{
    RgbaColor(float, float, float, float);
    float r, g, b, a;
};
struct P3
{
    void Set(float, float, float);
};
struct TESObjectTREE
{
    NiPoint3* GetData();
};
struct TESDataHandler
{
    NiPoint3* GetTESEyesList();
    C3* GetTESRaceList();
    float* GetBGSCameraShotList();
    NiPoint3* GetTESCaravanDeckList();
};
struct NiAVObject
{
    void SetLocalRotation(const H::ThreeByThreeMatrix&);
    void FUN_00440490(float);
    void SetAppCulled(bool);
    bool GetDisplayObject();
};
struct FUN_00440460_S
{
    void FUN_00440460(const V3*);
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct BSAudio
{
    void* GetAudioBackendData();
};
struct Sky
{
    int FUN_00476c90();
    bool IsFlag4Set();
};
struct FUN_00476980_S
{
    void FUN_004769c0(int, int);
};
struct CP_008c48d0
{
    TESObjectCELL* GetPrevPath();
};
struct FUN_004a0c90_shell
{
    void FUN_004a0c90(float);
};
struct FUN_004bc280_S
{
    void FUN_004bc280(const C3*);
};
struct NiPointLight
{
    void SetEffectColor(const NiPoint3&);
    void FUN_0050dd50(const NiPoint3&);
};
struct TESWeather
{
    float GetWeatherData(int, float, float);
};
struct KFModel
{
    NiAVObject* GetControllerSequence();
};
struct EffectSetting
{
    void* GetEffectID();
};
struct AnimIdle
{
    int GetSection();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct Cell_S
{
    unsigned int FUN_00544910();
    unsigned int FUN_00544970();
};
struct Sun_S
{
    float FUN_006427c0();
    void FUN_00642890();
    void* pad[8];
    float m_fSunGlareIntensity;
};
float __cdecl FUN_00408860(float);
float __cdecl FUN_004dd130(float, float);
bool GetPlayerUnderwater();
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
NiNode_00558310* FUN_0045c670();
float __fastcall GetSunriseBegin(char*);
float __fastcall GetSunriseEnd(char*);
float __fastcall GetSunsetBegin(char*);
float __fastcall GetSunsetEnd(void*);
float __fastcall GetCurrentWeatherPct(const char*);
float __fastcall GetFieldEC(const char*);
void __fastcall _ref_006815c0(void*);
int __fastcall _ref_0084e3a0(TES*);
extern Setting_S originalRuntimeFloatSetting80;
extern Setting_S originalRuntimeFloatSetting81;
extern Setting_S originalRuntimeFloatSetting82;
extern Setting_S originalRuntimeFloatSetting83;
extern Setting_S originalRuntimeFloatSetting84;
extern Setting_S originalRuntimeFloatSetting85;
extern TES* g_TES;
extern NiPoint3 _NiPoint3_ZERO;
extern H::ThreeByThreeMatrix DAT_011a9448;
extern float DAT_0104f2a8;
extern const double DAT_01023128;
extern double DAT_01011588;
extern float _DAT_010162c0;

// @fnv 0x00641830
void FUN_00641830_shell::UpdateSun(Sky* apSky, float afSecondsPassed)
{
    H::AutoMemContext tempMemContext(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp",
                                     300);
    NiPoint3 newLoc = _NiPoint3_ZERO;
    float fhour = GetFieldEC((const char*)apSky);
    ((H::SkyObject*)this)->Update(apSky, afSecondsPassed);
    if (apSky->FUN_00476c90() == 0)
    {
        H::ThreeByThreeMatrix lightDir = DAT_011a9448;
        TESObjectCELL* pcell = g_TES ? ((CP_008c48d0*)g_TES)->GetPrevPath() : 0;
        if (pcell)
        {
            H::ThreeByThreeMatrix rotmat;
            _ref_006815c0(&rotmat);
            ((FUN_004a0c90_shell*)&lightDir)->FUN_004a0c90(((Cell_S*)pcell)->FUN_00544910() * DAT_01023128);
            rotmat.SetYRotation(((Cell_S*)pcell)->FUN_00544970() * DAT_01023128);
            lightDir = lightDir * rotmat;
        }
        else
        {
            lightDir.SetMatrixElement(1, 0, DAT_0104f2a8);
            lightDir.SetMatrixElement(2, 0, DAT_0104f2a8);
        }
        ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))->SetLocalRotation(lightDir);
        ((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_004bc280(((TESDataHandler*)apSky)->GetTESRaceList());
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))->SetEffectColor(*((TESObjectTREE*)apSky)->GetData());
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_0050dd50(*((TESDataHandler*)apSky)->GetTESCaravanDeckList());
    }
    else if (apSky->FUN_00476c90() == 1)
    {
        H::ThreeByThreeMatrix lightDir = DAT_011a9448;
        TESObjectCELL* pcell = g_TES ? ((CP_008c48d0*)g_TES)->GetPrevPath() : 0;
        if (pcell)
        {
            H::ThreeByThreeMatrix rotmat;
            _ref_006815c0(&rotmat);
            ((FUN_004a0c90_shell*)&lightDir)->FUN_004a0c90(((Cell_S*)pcell)->FUN_00544910() * DAT_01023128);
            rotmat.SetYRotation(((Cell_S*)pcell)->FUN_00544970() * DAT_01023128);
            lightDir = lightDir * rotmat;
        }
        else
        {
            lightDir.SetMatrixElement(1, 0, DAT_0104f2a8);
            lightDir.SetMatrixElement(2, 0, DAT_0104f2a8);
        }
        ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))->SetLocalRotation(lightDir);
        ((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_004bc280(((TESDataHandler*)apSky)->GetTESRaceList());
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))->SetEffectColor(*((TESObjectTREE*)apSky)->GetData());
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_0050dd50(*((TESDataHandler*)apSky)->GetTESCaravanDeckList());
    }
    else if (apSky->FUN_00476c90() == 3 || apSky->FUN_00476c90() == 2)
    {
        ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 4))
            ->SetAppCulled(!((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 4))->GetDisplayObject());
        float fSunriseBegin = (GetSunriseEnd((char*)apSky) + GetSunriseBegin((char*)apSky)) / 2.0;
        float fSunsetEnd = (GetSunsetEnd(apSky) + GetSunsetBegin((char*)apSky)) / 2.0;
        float fhalftrans = *originalRuntimeFloatSetting82.Float() * DAT_01011588;
        float fAlphaInBegin = fSunriseBegin - fhalftrans;
        float fAlphaInEnd = fSunriseBegin + fhalftrans;
        float fAlphaOutBegin = fSunsetEnd - fhalftrans;
        float fAlphaOutEnd = fSunsetEnd + fhalftrans;
        float fDiscAlpha = 1.0f;
        if (!(fAlphaInBegin <= fhour && fhour <= fAlphaOutEnd))
        {
            fDiscAlpha = 0.0f;
        }
        else if (fAlphaInBegin < fhour && fhour < fAlphaInEnd)
        {
            fDiscAlpha = (fhour - fAlphaInBegin) / (fAlphaInEnd - fAlphaInBegin);
        }
        else if (fAlphaOutBegin < fhour && fhour < fAlphaOutEnd)
        {
            fDiscAlpha = 1.0f - (fhour - fAlphaOutBegin) / (fAlphaOutEnd - fAlphaOutBegin);
        }
        TESWeather* pCurr = (TESWeather*)((BSAudio*)apSky)->GetAudioBackendData();
        TESWeather* pLast = (TESWeather*)((AnimIdle*)apSky)->GetSection();
        float fCurrPct = GetCurrentWeatherPct((const char*)apSky);
        float fGlareAlpha = (pCurr ? pCurr->GetWeatherData(4, fCurrPct * fDiscAlpha, 0.0f) : fDiscAlpha) +
                            (pLast ? pLast->GetWeatherData(4, (1.0f - fCurrPct) * fDiscAlpha, 0.0f) : 0.0f);
        void* pshadeProperty =
            ((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))->GetProperty(3) == 0)
                 ? 0
                 : (((BGSTerrainManager*)((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))->GetProperty(3))
                        ->GetMinLevel() == 13))
                ? ((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))->GetProperty(3)
                : 0;
        if (pshadeProperty)
        {
            *(RgbaColor*)((char*)pshadeProperty + 0x60) =
                RgbaColor(((TESDataHandler*)apSky)->GetBGSCameraShotList()[0],
                          ((TESDataHandler*)apSky)->GetBGSCameraShotList()[1],
                          ((TESDataHandler*)apSky)->GetBGSCameraShotList()[2], fDiscAlpha);
        }
        pshadeProperty =
            ((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))->GetProperty(3) == 0)
                 ? 0
                 : (((BGSTerrainManager*)((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))->GetProperty(3))
                        ->GetMinLevel() == 13))
                ? ((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))->GetProperty(3)
                : 0;
        if (pshadeProperty)
        {
            *(RgbaColor*)((char*)pshadeProperty + 0x60) =
                RgbaColor(((TESDataHandler*)apSky)->GetBGSCameraShotList()[0],
                          ((TESDataHandler*)apSky)->GetBGSCameraShotList()[1],
                          ((TESDataHandler*)apSky)->GetBGSCameraShotList()[2], fGlareAlpha);
        }
        {
            float fxNewAim = 0.0f;
            H::ThreeByThreeMatrix newSunRot = DAT_011a9448;
            float ftemp;
            NiPoint3 ksundirection;
            if (fAlphaInBegin < fhour && fhour < fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaInBegin) / (fAlphaOutEnd - fAlphaInBegin);
                fxNewAim = (1.0 - 2.0 * ftemp) * *originalRuntimeFloatSetting83.Float();
            }
            else if (fhour >= fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaOutEnd) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *originalRuntimeFloatSetting83.Float();
            }
            else if (fhour <= fAlphaInBegin)
            {
                ftemp = (24.0 - fAlphaOutEnd + fhour) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *originalRuntimeFloatSetting83.Float();
            }
            newLoc.x = fxNewAim;
            newLoc.y = ((GlobalObject_0044f440*)&originalRuntimeFloatSetting84)->FUN_00450410();
            newLoc.z = FUN_00408860(((GlobalObject_0044f440*)&originalRuntimeFloatSetting83)->FUN_00450410()) -
                       FUN_00408860(fxNewAim);
            ((FUN_00440460_S*)(unsigned int)*(Flt*)((char*)this + 4))->FUN_00440460((const V3*)&newLoc);
            ((FUN_00440460_S*)(unsigned int)*(Flt*)((char*)this + 0xc))->FUN_00440460((const V3*)&newLoc);
            ((P3*)&ksundirection)
                ->Set(-fxNewAim, ((GlobalObject_0044f440*)&originalRuntimeFloatSetting84)->FUN_00450410(),
                      ((GlobalObject_0044f440*)&originalRuntimeFloatSetting85)->FUN_00450410());
            ((H::NiPoint3*)&ksundirection)->ComputeMagnitude();
            ((FUN_00476980_S*)&newSunRot)->FUN_004769c0(0, (int)&ksundirection);
            ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))->SetLocalRotation(newSunRot);
            ((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))
                ->FUN_004bc280(((TESDataHandler*)apSky)->GetTESRaceList());
            ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
                ->SetEffectColor(*((TESObjectTREE*)apSky)->GetData());
            ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
                ->FUN_0050dd50(*((TESDataHandler*)apSky)->GetTESCaravanDeckList());
        }
        if (g_TES && _ref_0084e3a0(g_TES))
        {
            NiPoint3 origin = *((TESDataHandler*)FUN_00558310(FUN_0045c670()))->GetTESEyesList();
            NiPoint3 direction = newLoc;
            float fscaleChange = *originalRuntimeFloatSetting81.Float() * afSecondsPassed;
            ((H::NiPoint3*)&direction)->ComputeMagnitude();
            bool bblocked =
                ((Sun_S*)this)->FUN_006427c0() >= 1.0 || (((EffectSetting*)g_TES)->GetEffectID(), GetPlayerUnderwater());
            float fscale = FUN_004dd130(1.0f - ((Sun_S*)this)->FUN_006427c0(), _DAT_010162c0);
            ((Sun_S*)this)->FUN_00642890();
            if (bblocked || fscale < *originalRuntimeFloatSetting80.Float())
            {
                if (((Sun_S*)this)->m_fSunGlareIntensity - fscaleChange < *originalRuntimeFloatSetting80.Float())
                {
                    ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))->SetAppCulled(true);
                    ((Sun_S*)this)->m_fSunGlareIntensity = 0.0f;
                }
                else
                {
                    ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))->SetAppCulled(false);
                    ((Sun_S*)this)->m_fSunGlareIntensity -= fscaleChange;
                    ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))
                        ->FUN_00440490(((Sun_S*)this)->m_fSunGlareIntensity);
                }
            }
            else
            {
                if (((Sun_S*)this)->m_fSunGlareIntensity + fscaleChange >= fscale ||
                    ((Sun_S*)this)->m_fSunGlareIntensity >= fscale)
                {
                    ((Sun_S*)this)->m_fSunGlareIntensity = fscale;
                }
                else
                {
                    ((Sun_S*)this)->m_fSunGlareIntensity += fscaleChange;
                }
                ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))->SetAppCulled(false);
                ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))
                    ->FUN_00440490(((Sun_S*)this)->m_fSunGlareIntensity);
            }
            if (!((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))->GetDisplayObject())
            {
                ((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))->SetAppCulled(true);
            }
        }
        if (apSky->IsFlag4Set())
        {
            ((KFModel*)this)->GetControllerSequence()->SetAppCulled(true);
        }
        else
        {
            ((KFModel*)this)->GetControllerSequence()->SetAppCulled(false);
        }
    }
}
}  // namespace fnv_00641830

struct FUN_00642680_shell
{
    float m_data[3][3];
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
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    unsigned int unk118;
    bool IsFlag4Set();
};

// @fnv 0x00642680
bool FUN_00642680_shell::IsFlag4Set()
{
    return 0 < (unk118 & 4);
}

struct SunGlarePick
{
    ~SunGlarePick();
};

class FUN_006406a0 : public SkyObject
{
  public:
    virtual ~FUN_006406a0();
    NiPointer<NiAVObject> m_pFirstSceneObject, m_pSecondSceneObject, m_pThirdSceneObject, m_pFourthSceneObject;
    SunGlarePick* m_pSunGlarePick;
    NiPointer<NiAVObject> m_pMenuLight;
    float m_fSunGlareIntensity;
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> m_pSunShaderAccumulator;
};

// @fnv 0x006406a0
FUN_006406a0::~FUN_006406a0()
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    if (m_pSunGlarePick)
        delete m_pSunGlarePick;
    m_pSunShaderAccumulator = 0;
}

// Sun update: with a world and enabled, point the glare at the new target and run its update at a scaled time step.

extern const double g_dA6A0TimeScale;

class AutoMemHelper
{
  public:
    AutoMemHelper(int aiMemoryContext, bool bPush, const char* pcFile, int iLine);
    ~AutoMemHelper();

    int m_iContext;
};

class A6A0World
{
  public:
    float GetTimeStep();
    void SetTimeStep(float fTimeStep);
};

class A6A0Target
{
  public:
    void Update(A6A0World* pkWorld, void* pvArg0, void* pvArg1);
};

class A6A0Ref
{
  public:
    void Reset(void* pvObject);
};

class A6A0Sun
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    bool m_bEnableState;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    A6A0Ref m_kRoomNode;

    A6A0World* GetWorld();
    void FUN_006426a0(void* pvArg0, A6A0Target* pkTarget, void* pvArg1);
};

// @fnv 0x006426a0
void A6A0Sun::FUN_006426a0(void* pvArg0, A6A0Target* pkTarget, void* pvArg1)
{
    AutoMemHelper kMem(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp", 0x222);
    if (GetWorld() && m_bEnableState)
    {
        A6A0Target* pkCurrent = pkTarget;
        if (pkCurrent)
        {
            m_kRoomNode.Reset(pkTarget);
            A6A0World* pkWorld = GetWorld();
            pkWorld->SetTimeStep((float)(pkWorld->GetTimeStep() / g_dA6A0TimeScale));
            pkCurrent->Update(pkWorld, pvArg0, pvArg1);
            pkWorld->SetTimeStep((float)(pkWorld->GetTimeStep() * g_dA6A0TimeScale));
        }
    }
}

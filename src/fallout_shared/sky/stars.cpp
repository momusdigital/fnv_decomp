// fallout_shared/sky/stars.cpp: Stars, StarsLoader (7 functions)

#include "stars_decls.h"
// @fnv 0x0063fd90
void Stars::Initialize(NiNode* node)
{
    SkyObject::Initialize(node);
}

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};

struct FUN_0043fa80_s
{
    char _pad[0x34];
    ThreeByThreeMatrix m_kLocalTransform;
    void FUN_0043fa80(const ThreeByThreeMatrix& kRot);
};

// @fnv 0x0043fa80
void FUN_0043fa80_s::FUN_0043fa80(const ThreeByThreeMatrix& kRot)
{
    m_kLocalTransform = kRot;
}

struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiStream;
struct blob16
{
    char b[16];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiQuaternion
{
    void SetW(float);
    void SetX(float);
    void SetY(float);
    void SetZ(float);
    float GetW();
    float GetX();
    float GetY();
    float GetZ();
    void SetValues(float, float, float, float);
    void GetValues(float*, float*, float*, float*);
    static float Dot(void*, void*);
    static struct blob16 MakeUnitLength(void*);
    static struct blob16 Exp(void*);
    static struct blob16 Log(void*);
    void Slerp(float, void*, void*);
    static struct blob16 Intermediate(void*, void*, void*);
    void InterpolateSquad(float, void*, void*, void*, void*);
    void GetAngleAxis(float*, NiPoint3*);
    void FromAngleAxis(float, void*);
    void FromAngleAxisX(float);
    void FromAngleAxisY(float);
    void FromAngleAxisZ(float);
    void SetRotationFromEulerXYZ(float, float, float);
    void ToRotationMatrix(ThreeByThreeMatrix*);
    void FromRotationMatrix(void*);
    void Snap();
    static void LoadBinary(NiStream*, NiQuaternion*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiQuaternion*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Normalize();
    void EnsureCanonicalSign();
    static float ISqrt_approx_in_neighborhood(float);
    static float Lerp(float, float, float);
    static float CalculateSlerpWeight(float, float);
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};
typedef char _sizecheck_NiQuaternion[sizeof(NiQuaternion) == 16 ? 1 : -1];

struct FUN_004f0160_arg
{
    NiQuaternion* kQuat;
};

// @fnv 0x004f0160
void __fastcall FUN_004f0160(char* _this, FUN_004f0160_arg aQuatArg)
{
    aQuatArg.kQuat->ToRotationMatrix((ThreeByThreeMatrix*)(_this + 0x34));
}

namespace fnv_00640020 {
struct Atmosphere;
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct BSFogProperty;
struct BSMultiBoundNode;
struct Clouds;
struct ImageSpaceModifierInstanceForm;
struct Moon;
struct NiColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiNode;
struct NiStream;
struct Precipitation;
struct Sky;
struct SkyTextureManager;
struct Sun;
struct TESClimate;
struct TESWeather;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
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
struct FUN_00640020_shell : public Stars
{
    void UpdateStars(Sky*, float);
};

class NiAVObject;
class NiGeometry;
class NiProperty;
class NiAVObject
{
  public:
    virtual ~NiAVObject();
    virtual void DeleteThis();
    virtual void* GetRTTI();
    virtual NiNode* IsSceneNode();
    virtual void* IsFadeNode();
    virtual void* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    void SetAppCulled(bool);
    void SetLocalRotation(float, float, float, float);
};
struct NiNode : public NiAVObject
{
    int FUN_00453470();
    NiAVObject* GetAt(unsigned int);
};
class NiGeometry : public NiAVObject
{
  public:
    NiProperty* GetProperty(int);
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct SkyShaderProperty
{
    char _hdr[0x60];
    float r, g, b, fAlpha;
};
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex(float, float, float);
    void ComputeMagnitude();
};
class WaterShaderSettings;
struct TESWaterForm
{
    WaterShaderSettings* FUN_0057eef0();
};
struct SkyObjectS
{
    void Update(Sky*, float);
};
struct BSAudio
{
    void* GetAudioBackendData();
};
struct Sky
{
    float GetFieldEC();
    int FUN_00476c90();
};
struct FUN_00595fc0_shell
{
    float GetSunsetBegin();
};
struct FUN_00595f50_shell
{
    float GetSunriseEnd();
};
struct FUN_0063ba30_shell
{
    float FUN_0063ba30();
};
struct FUN_0063b9b0_shell
{
    float FUN_0063b9b0();
};
struct FUN_006366b0_shell
{
    bool GetDisplayObject();
};
struct Call_439090_tgt
{
    bool _Call_439090(const void*);
};
struct Flt
{
    operator unsigned int() const;
};
union SETTING_VALUE
{
    float f;
    int i;
    char* s;
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
class GlobalObject_0040e0b0 : public SettingT<GameSettingCollection>
{
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting79;
extern GlobalObject_0040e0b0 g_011ccdc4;
extern GlobalObject_0040e0b0 g_011ccddc;
extern GlobalObject_0040e0b0 g_011cce30;
class Calendar
{
  public:
    unsigned int GetGameDaysPassed();
};
extern Calendar g_calendar;
float __cdecl FUN_004b1520(float, float);

// Updates the stars node's fade alpha from the sky hour, recolors star geometry, and rotates the stars node by the elapsed game time.
// @fnv 0x00640020
void FUN_00640020_shell::UpdateStars(Sky* apSky, float afSecondsPassed)
{
    if (!((BSAudio*)apSky)->GetAudioBackendData())
        return;
    float fhour = apSky->GetFieldEC();
    *(float*)((char*)this + 0xc) = 0.0f;
    static NiPoint3Ex lastColor(0.0f, 0.0f, 0.0f);
    ((SkyObjectS*)this)->Update(apSky, afSecondsPassed);
    if (apSky->FUN_00476c90() == 3 || apSky->FUN_00476c90() == 2)
    {
        if (!((FUN_006366b0_shell*)(unsigned int)*(const Flt*)((char*)this + 4))->GetDisplayObject())
        {
            ((NiAVObject*)(unsigned int)*(const Flt*)((char*)this + 4))->SetAppCulled(true);
            return;
        }
        float fSunsetBegin = ((FUN_00595fc0_shell*)apSky)->GetSunsetBegin();
        float fSunsetEnd = ((FUN_0063ba30_shell*)apSky)->FUN_0063ba30();
        float fSunriseEnd = ((FUN_00595f50_shell*)apSky)->GetSunriseEnd();
        float fSunriseBegin = ((FUN_0063b9b0_shell*)apSky)->FUN_0063b9b0();
        float fBeginFadeIn = fSunsetEnd - (fSunsetEnd - fSunsetBegin) * 0.5f;
        float fEndFadeOut = fSunriseEnd - (fSunriseEnd - fSunriseBegin) * 0.5f;
        if (fSunriseBegin < fhour && fhour < fEndFadeOut)
            *(float*)((char*)this + 0xc) = (fEndFadeOut - fhour) / (fEndFadeOut - fSunriseBegin);
        else if (fEndFadeOut <= fhour && fhour <= fBeginFadeIn)
            *(float*)((char*)this + 0xc) = 0.0f;
        else if (fBeginFadeIn < fhour && fhour < fSunsetEnd)
            *(float*)((char*)this + 0xc) = (fhour - fBeginFadeIn) / (fSunsetEnd - fBeginFadeIn);
        else
            *(float*)((char*)this + 0xc) = 1.0f;
        if (*(float*)((char*)this + 0xc) > 0.0)
        {
            ((NiAVObject*)(unsigned int)*(const Flt*)((char*)this + 4))->SetAppCulled(false);
            NiPoint3Ex colorThisFrame = *(NiPoint3Ex*)((TESWaterForm*)apSky)->FUN_0057eef0();
            NiGeometry* pstarsgeo = 0;
            NiAVObject* pchild = 0;
            unsigned int icount = (unsigned int)*(const Flt*)((char*)this + 8)
                                      ? ((NiNode*)(unsigned int)*(const Flt*)((char*)this + 8))->FUN_00453470()
                                      : 0;
            for (unsigned int i = 0; i < icount; i++)
            {
                pchild = ((NiNode*)(unsigned int)*(const Flt*)((char*)this + 8))->GetAt(i);
                if (pchild)
                {
                    pstarsgeo = pchild->IsGeometry();
                    if (pstarsgeo)
                    {
                        SkyShaderProperty* pStarsProp =
                            (pstarsgeo->GetProperty(3) == 0
                                 ? 0
                                 : ((BGSTerrainManager*)pstarsgeo->GetProperty(3))->GetMinLevel() == 13)
                                ? (SkyShaderProperty*)pstarsgeo->GetProperty(3)
                                : 0;
                        if (pStarsProp)
                        {
                            if (((Call_439090_tgt*)&lastColor)->_Call_439090(&colorThisFrame))
                            {
                                pStarsProp->r = colorThisFrame.x;
                                pStarsProp->g = colorThisFrame.y;
                                pStarsProp->b = colorThisFrame.z;
                            }
                            pStarsProp->fAlpha = *(float*)((char*)this + 0xc);
                        }
                    }
                }
            }
            lastColor = colorThisFrame;
            float felapsed = g_calendar.GetGameDaysPassed() + apSky->GetFieldEC() / 24.0;
            float fangle = FUN_004b1520(felapsed, originalRuntimeFloatSetting79.Float()->f) * 6.2831854820251465 /
                           originalRuntimeFloatSetting79.Float()->f;
            NiPoint3Ex axis(g_011ccdc4.Float()->f, g_011cce30.Float()->f, g_011ccddc.Float()->f);
            axis.ComputeMagnitude();
            if ((unsigned int)*(const Flt*)((char*)this + 8))
                ((NiNode*)(unsigned int)*(const Flt*)((char*)this + 8))
                    ->SetLocalRotation(fangle, axis.x, axis.y, axis.z);
        }
        else
        {
            ((NiAVObject*)(unsigned int)*(const Flt*)((char*)this + 4))->SetAppCulled(true);
        }
    }
}
}  // namespace fnv_00640020

struct FUN_0063fcf0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

struct FUN_0063fd20_shell
{
    void FUN_0063fd20();
};

void __cdecl _Deallocate(void* p);

// @fnv 0x0063fcf0
void* FUN_0063fcf0_shell::DestroyIfFlagged(unsigned int flags)
{
    ((FUN_0063fd20_shell*)this)->FUN_0063fd20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_0063fd20_Base
{
    virtual ~S_0063fd20_Base();
    int unk04;
};
struct S_0063fd20_Member
{
    int unk00;
    int unk04;
    void FUN_0066b0d0(int a);
    ~S_0063fd20_Member();
};
struct FUN_0063fd20 : S_0063fd20_Base
{
    S_0063fd20_Member m_08;
    virtual ~FUN_0063fd20();
};
// Destructor that calls m_08.FUN_0066b0d0 with 0 before the base destructor runs.
// @fnv 0x0063fd20
FUN_0063fd20::~FUN_0063fd20()
{
    m_08.FUN_0066b0d0(0);
}

// Minimal interfaces used by the stars model loader.
template <class T> struct BSStringT
{
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    operator const T*() const;
};
class NiNode
{
  public:
    virtual void virtual_00();
    virtual void virtual_01();
    virtual void virtual_02();
    virtual void virtual_03();
    virtual void virtual_04();
    virtual void virtual_05();
    virtual void virtual_06();
    virtual void virtual_07();
    virtual void virtual_08();
    virtual void virtual_09();
    virtual void virtual_10();
    virtual void virtual_11();
    virtual void virtual_12();
    virtual void virtual_13();
    virtual void virtual_14();
    virtual void virtual_15();
    virtual void virtual_16();
    virtual void virtual_17();
    virtual void virtual_18();
    virtual void virtual_19();
    virtual void virtual_20();
    virtual void virtual_21();
    virtual void virtual_22();
    virtual void virtual_23();
    virtual void virtual_24();
    virtual void virtual_25();
    virtual void virtual_26();
    virtual void virtual_27();
    virtual void virtual_28();
    virtual void virtual_29();
    virtual void virtual_30();
    virtual void virtual_31();
    virtual void virtual_32();
    virtual void virtual_33();
    virtual void virtual_34();
    virtual void virtual_35();
    virtual void virtual_36();
    virtual void virtual_37();
    virtual void virtual_38();
    virtual void virtual_39();
    virtual void virtual_40();
    virtual void virtual_41();
    virtual void virtual_42();
    virtual void virtual_43();
    virtual void virtual_44();
    virtual void virtual_45();
    virtual void virtual_46();
    virtual void virtual_47();
    virtual void virtual_48();
    virtual void virtual_49();
    virtual void virtual_50();
    virtual void virtual_51();
    virtual void virtual_52();
    virtual void virtual_53();
    virtual void virtual_54();
    virtual void AttachChildInAvailableSlot(NiNode* child, bool firstAvailable);
    virtual void virtual_56();
    virtual void virtual_57();
    virtual void InsertChild(NiNode* child);
    void SetDisplayObject(bool enabled);
    void FUN_004902f0(bool enabled);
    void FUN_00a5a040();
};
template <class T> class NiPointer
{
  public:
    T* object;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
struct BSStream
{
    virtual ~BSStream();
    unsigned int version;
    char header[64];
    char copyright[64];
    char author[64];
    unsigned int unk0c8;
    void* unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    BSStream();
    bool FUN_00c3a8a0(const char* path, bool);
    unsigned int GetRefAt21C();
    NiNode* GetStringAt(unsigned int index);
};
class Model
{
  public:
    unsigned int unk00, unk04, unk08;
    NiNode* object;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
    NiNode* GetObject3D();
};
extern const char* const DAT_011f4428;
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);
bool __cdecl FUN_0043b300(const void*, NiNode*);
void __cdecl FNV_Warning(const char*);
struct StarsLoader
{
    unsigned int unk00;
    NiPointer<NiNode> parent;
    NiPointer<NiNode> stars;
    void LoadGeometry(const char* path);
};
// @fnv 0x0063fdb0
void StarsLoader::LoadGeometry(const char* path)
{
    if (!path || !*path)
    {
        parent->SetDisplayObject(false);
        return;
    }
    BSStringT<char> fileName;
    FUN_00406f60(&fileName, "%s%s%s", "Meshes", "\\", path);
    {
        BSStream stream;
        if (!stream.FUN_00c3a8a0(fileName, false) || stream.GetRefAt21C() != 1 ||
            !FUN_0043b300(&DAT_011f4428, stream.GetStringAt(0)))
        {
            FNV_Warning("DEFAULT: Cannot load the stars.");
            parent->SetDisplayObject(false);
            return;
        }
        Model model(fileName, &stream, true, false);
        parent->SetDisplayObject(true);
        parent->InsertChild(stars);
        stars = model.GetObject3D();
        stars->FUN_004902f0(true);
        parent->AttachChildInAvailableSlot(stars, true);
        stars->FUN_00a5a040();
    }
}

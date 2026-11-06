// fallout_shared/sky/moon.cpp: Moon, TaskQueueInterface (11 functions)

#include "moon_types.h"

// @fnv 0x006366d0
float Moon::GetMoonVisibility()
{
    float fadeStart = 180.0 - m_fFadeStartAngle;
    float fadeEnd = 180.0 - m_fFadeEndAngle;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= m_fFadeStartAngle && fPos >= m_fFadeEndAngle)
        return (fPos - m_fFadeEndAngle) / (m_fFadeStartAngle - m_fFadeEndAngle);
    else if (fPos >= fadeStart && fPos <= fadeEnd)
        return (fadeEnd - fPos) / (fadeEnd - fadeStart);
    else if (fPos > m_fFadeStartAngle && fPos < fadeStart)
        return 1.0f;
    else
        return 0.0f;
}

// Returns a 0..1 visibility factor from fPos using start/end fade angles and their 180-degree mirrored late angles.
// @fnv 0x006367e0
float Moon::GetMoonShadowVisibility()
{
    struct FadeAngles
    {
        float start;
        float lateStart;
        float end;
        float lateEnd;
    } fadeAngles;
    fadeAngles.start = m_fFadeEndAngle;
    fadeAngles.end = m_fFadeEndAngle - m_fFadeAngleRange;
    fadeAngles.lateStart = 180.0 - fadeAngles.start;
    fadeAngles.lateEnd = 180.0 - fadeAngles.end;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= fadeAngles.start && fPos >= fadeAngles.end)
        return (fPos - fadeAngles.end) / (fadeAngles.start - fadeAngles.end);
    else if (fPos >= fadeAngles.lateStart && fPos <= fadeAngles.lateEnd)
        return (fadeAngles.lateEnd - fPos) / (fadeAngles.lateEnd - fadeAngles.lateStart);
    else if (fPos > fadeAngles.start && fPos < fadeAngles.lateStart)
        return 1.0f;
    else
        return 0.0f;
}

class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool, unsigned int);
    void SetDisplayObject(bool bDisplay);
};

// @fnv 0x00635fe0
void TaskQueueInterface::SetDisplayObject(bool bDisplay)
{
    SetTaskFlagDWord(bDisplay, 0x20);
}

class Flag512Receiver
{
  public:
    void FUN_00633ba0(bool, unsigned int);
    void SetNoSorter(bool enabled);
};

// @fnv 0x00636000
void Flag512Receiver::SetNoSorter(bool enabled)
{
    FUN_00633ba0(enabled, 0x2000);
}

struct Calendar
{
    unsigned int GetGameDaysPassed(void);
};
extern Calendar g_calendar;
extern unsigned int DAT_011cca80;
void* __fastcall _ref_0084e3a0(const Sky*);
unsigned int __fastcall GetMoonPhaseDays(void*);

// @fnv 0x006368f0
bool __cdecl FUN_006368f0(const Sky* apSky)
{
    if (_ref_0084e3a0(apSky) && GetMoonPhaseDays(_ref_0084e3a0(apSky)))
    {
        unsigned int eNewPhase = (g_calendar.GetGameDaysPassed() % (GetMoonPhaseDays(_ref_0084e3a0(apSky)) * 8)) /
                                 GetMoonPhaseDays(_ref_0084e3a0(apSky));
        if (eNewPhase != DAT_011cca80)
        {
            DAT_011cca80 = eNewPhase;
            return true;
        }
    }
    return false;
}

struct FUN_00636980_Helper
{
    char pad[0x55];
    unsigned char f55;
    unsigned char GetMoonPhaseDays();
};

// @fnv 0x00636980
unsigned char FUN_00636980_Helper::GetMoonPhaseDays()
{
    return f55 & ~0xc0;
}

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
};

struct FUN_006366b0_shell
{
    bool GetDisplayObject();
};

// @fnv 0x006366b0
bool FUN_006366b0_shell::GetDisplayObject()
{
    return ((FUN_00456630_helper*)this)->FUN_00456630(0x20);
}

void _Deallocate(void*);
struct S00634cb0
{
    void FUN_00634ce0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00634ce0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00634cb0
void* S00634cb0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00634ce0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

class NiNode
{
  public:
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Vfn10();
    virtual void Vfn14();
    virtual void Vfn18();
    virtual void Vfn1C();
    virtual void Vfn20();
    virtual void Vfn24();
    virtual void Vfn28();
    virtual void Vfn2C();
    virtual void Vfn30();
    virtual void Vfn34();
    virtual void Vfn38();
    virtual void Vfn3C();
    virtual void Vfn40();
    virtual void Vfn44();
    virtual void Vfn48();
    virtual void Vfn4C();
    virtual void Vfn50();
    virtual void Vfn54();
    virtual void Vfn58();
    virtual void Vfn5C();
    virtual void Vfn60();
    virtual void Vfn64();
    virtual void Vfn68();
    virtual void Vfn6C();
    virtual void Vfn70();
    virtual void Vfn74();
    virtual void Vfn78();
    virtual void Vfn7C();
    virtual void Vfn80();
    virtual void Vfn84();
    virtual void Vfn88();
    virtual void Vfn8C();
    virtual void Vfn90();
    virtual void Vfn94();
    virtual void Vfn98();
    virtual void Vfn9C();
    virtual void VfnA0();
    virtual void VfnA4();
    virtual void VfnA8();
    virtual void VfnAC();
    virtual void VfnB0();
    virtual void VfnB4();
    virtual void VfnB8();
    virtual void VfnBC();
    virtual void VfnC0();
    virtual void VfnC4();
    virtual void VfnC8();
    virtual void VfnCC();
    virtual void VfnD0();
    virtual void VfnD4();
    virtual void VfnD8();
    virtual void VfnDC();
    virtual void VfnE0();
    virtual void VfnE4();
    virtual void DetachChildAlt(NiNode* child);
    NiNode* GetParent();
};

class FUN_00634ce0 : public SkyObject
{
  public:
    virtual ~FUN_00634ce0();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    int m_eUpdateStatus;
    float fPos;
    float m_fValue;
};

// Clears the four NiPointer members, detaches the node from its parent if it has one, then clears the node pointer.
// @fnv 0x00634ce0
FUN_00634ce0::~FUN_00634ce0()
{
    m_pMoonShadowShape = 0;
    m_pMoonShape = 0;
    m_pMoonShadowNode = 0;
    m_pMoonNode = 0;
    if (m_pRootNode->GetParent())
    {
        m_pRootNode->GetParent()->DetachChildAlt(m_pRootNode);
    }
    m_pRootNode = 0;
}

// 0x00634a70  /MT /Od /Oy- /GS /EHsc /Gy /GF  thiscall ctor, 7 args (ret 0x1c)
// Moon::Moon(name, fadeStart, fadeEnd, shadowEarlyFade, speed, zOffset, size)

struct FUN_00406f90_this;
int __cdecl FUN_00406f60(FUN_00406f90_this*, const char*, ...);

class FUN_00634a70 : public SkyObject
{
  public:
    FUN_00634a70(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed, float zOffset,
                 unsigned int size);
    virtual ~FUN_00634a70();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    int m_eUpdateStatus;
    float fPos;
    float m_fValue;
};

// Builds the moon texture paths from name and phase suffixes, stores fade/speed/z-offset/size parameters, and initialises position and node pointers.
// @fnv 0x00634a70
FUN_00634a70::FUN_00634a70(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed,
                           float zOffset, unsigned int size)
    : m_pMoonNode(0), m_pMoonShadowNode(0), m_pMoonShape(0), m_pMoonShadowShape(0)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 50);
    const char* fmt = "\\Textures\\Sky\\%s_%s.dds";
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[3], fmt, name, "one_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[5], fmt, name, "one_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[2], fmt, name, "half_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[6], fmt, name, "half_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[1], fmt, name, "three_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[7], fmt, name, "three_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[0], fmt, name, "full");

    m_fFadeStartAngle = fadeStart;
    m_fFadeEndAngle = fadeEnd;
    m_fFadeAngleRange = shadowEarlyFade;
    fSpeed = speed;
    m_fGlyphVerticalOffset = zOffset;
    iSize = size;
    fPos = 0.0f;
    m_fValue = 3.402823466e+38F;
    m_pMoonNode = 0;
    m_pMoonShadowNode = 0;
    m_pMoonShape = 0;
    m_pMoonShadowShape = 0;
    m_eUpdateStatus = 0;
}

struct NiTexture;
struct TESSaveLoadGame;

extern TESSaveLoadGame* g_TESSaveLoadGame;
extern double _gModifierZero;
extern double _DAT_010231b0;
extern double DAT_01012638;
extern double DAT_0103c348;
extern const double DAT_01023128;
extern float DAT_010249d8;

float __cdecl FUN_0040ebd0(float, float);
float __fastcall GetFieldEC(const char*);

namespace MoonUpdateDetail {

struct Flt
{
    operator unsigned int() const;
};

struct Mtx
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    void _ref_006815c0();
    Mtx operator*(const Mtx&) const;
};

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};

struct NiAVObject
{
    void SetLocalRotation(const Mtx&);
    void SetAppCulled(bool);
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};

struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};

struct SkyShaderProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    RgbaColor kColor;

    void SetTexture(::NiTexture*);
};

struct BSShaderManager
{
    static void __cdecl GetTexture(const char*, bool, ::NiPointer< ::NiTexture>&, bool, bool);
};

struct SkyView
{
    int FUN_00476c90();
};

struct BSThread
{
    unsigned int GetThreadID();
};

struct Twin_0084d030
{
    float GetStoredFloatValue();
};

struct TESSaveLoadGame
{
    bool GetLoading();
};

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
};

struct FUN_00524ac0_shell
{
    void FUN_00524ac0(float);
};

struct FUN_004a0c90_shell
{
    void FUN_004a0c90(float);
};

struct FUN_00636020_shell : public ::Moon
{
    void FUN_00636020(::Sky*, float);
};

// Updates moon position and visibility, sets texture and culling state on moon nodes, and applies rotation matrices when the sky view is active.
// @fnv 0x00636020
void FUN_00636020_shell::FUN_00636020(::Sky* apSky, float afSecondsPassed)
{
    float fTimePassed;
    float fvisShadow;
    float fvisMoon;
    float fvisStars;
    ::AutoMemContext tempMemContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 0x124);

    ::SkyObject::Update(apSky, afSecondsPassed);

    if (m_fValue == _DAT_010231b0)
    {
        m_fValue = 0;
        fPos = DAT_010249d8;
    }
    if (((TESSaveLoadGame*)::g_TESSaveLoadGame)->GetLoading())
    {
        m_fValue = -((double)(g_calendar.GetGameDaysPassed() - 1) * 24.0);
        fPos = DAT_010249d8;
    }
    fTimePassed = GetFieldEC((const char*)apSky) - m_fValue;
    if (fTimePassed < _gModifierZero)
        fTimePassed = fTimePassed + 24.0;
    fPos = fSpeed * DAT_01012638 * fTimePassed + fPos;
    while (fPos < _gModifierZero)
        fPos = fPos + DAT_0103c348;
    while (fPos >= DAT_0103c348)
        fPos = fPos - DAT_0103c348;
    m_fValue = GetFieldEC((const char*)apSky);

    fvisMoon = GetMoonVisibility();
    fvisShadow = GetMoonShadowVisibility();
    fvisStars = ((Twin_0084d030*)((BSThread*)apSky)->GetThreadID())->GetStoredFloatValue();
    fvisShadow = FUN_0040ebd0(fvisShadow, fvisStars);

    if (m_eUpdateStatus == US_INITIALIZE ||
        (m_eUpdateStatus == US_WHEN_CULLED && fvisMoon <= _gModifierZero && fvisShadow <= _gModifierZero))
    {
        SkyShaderProperty* pprop =
            (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetProperty(3);
        ::NiPointer< ::NiTexture> spTex(0);
        BSShaderManager::GetTexture(
            (const char*)((const Flt*)&m_kMoonTexturePaths[DAT_011cca80])->operator unsigned int(), true, spTex, true,
            false);
        ::NiTexture* ptex = (::NiTexture*)((const Flt*)&spTex)->operator unsigned int();
        if (ptex)
            pprop->SetTexture(ptex);
        ((::TaskQueueInterface*)((const Flt*)&m_pMoonShape)->operator unsigned int())->SetDisplayObject(ptex != 0);
        m_eUpdateStatus = US_NOT_REQUIRED;
    }

    if (((SkyView*)apSky)->FUN_00476c90() == 3 || ((SkyView*)apSky)->FUN_00476c90() == 2)
    {
        if (!((::FUN_006366b0_shell*)((const Flt*)&m_pRootNode)->operator unsigned int())->GetDisplayObject())
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(true);
            return;
        }
        Mtx matrixMoonZ;
        Mtx matrixMoonX;
        matrixMoonX._ref_006815c0();
        matrixMoonZ._ref_006815c0();
        ((FUN_00524ac0_shell*)&matrixMoonX)->FUN_00524ac0(-fPos * DAT_01023128);
        ((FUN_004a0c90_shell*)&matrixMoonZ)->FUN_004a0c90(m_fGlyphVerticalOffset * DAT_01023128);
        ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetLocalRotation(matrixMoonX * matrixMoonZ);
        if (fvisMoon <= _gModifierZero && fvisShadow <= _gModifierZero)
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(true);
        }
        else
        {
            ((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())->SetAppCulled(false);
            if (fvisMoon <= _gModifierZero ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetDisplayObject())
            {
                ((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())->SetAppCulled(true);
            }
            else
            {
                ((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())->SetAppCulled(false);
                SkyShaderProperty* pshadeProperty =
                    (((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())->GetProperty(3) == 0
                         ? 0
                         : ((BGSTerrainManager*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())
                                ->GetProperty(3))
                                   ->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())
                              ->GetProperty(3)
                        : 0;
                if (pshadeProperty)
                    pshadeProperty->kColor.a = fvisMoon;
            }
            if (fvisShadow <= _gModifierZero ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())->GetDisplayObject())
            {
                ((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())->SetAppCulled(true);
            }
            else
            {
                ((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())->SetAppCulled(false);
                SkyShaderProperty* pshadeProperty =
                    (((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())->GetProperty(3) == 0
                         ? 0
                         : ((BGSTerrainManager*)((PropHelper*)((const Flt*)&m_pMoonShadowShape)
                                                     ->
                                                     operator unsigned int())
                                ->GetProperty(3))
                                   ->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())
                              ->GetProperty(3)
                        : 0;
                if (pshadeProperty)
                    pshadeProperty->kColor =
                        RgbaColor(((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[0],
                                  ((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[1],
                                  ((float*)((TESFaction_RankDataView*)apSky)->GetRankDataList())[2], fvisShadow);
            }
        }
    }
}

}

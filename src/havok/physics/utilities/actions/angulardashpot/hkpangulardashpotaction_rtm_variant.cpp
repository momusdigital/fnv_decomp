// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpAngularDashpotAction.h"
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
struct hkQuaternionD4DB
{
    __m128 m_vec;
};
extern const __m128 DAT_010c71b0;
class FUN_00cf4d80
{
  public:
    FUN_00cf4d80(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00cf4d80() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    const char* m_name;
    void* m_pEntityA;
    void* m_pEntityB;
};
class FUN_00d4dbe0 : public FUN_00cf4d80
{
  public:
    FUN_00d4dbe0(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00d4dbe0() throw();

    hkQuaternionD4DB m_rotation;
    float m_fSpringStrength;
    float m_fMotorDamping;
    int unk38, unk3C;
};

typedef hkpAngularDashpotAction DashpotActionBaseD4DCB0;
typedef hkReferencedObject DashpotReferencedBaseD4DCB0;

namespace AngularDashpotApplyD4DCB0 {

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
};
typedef __m128 DashpotQuadD4DCB0;

extern "C" DashpotQuadD4DCB0 _mm_xor_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_load_ss(const float* x);
extern "C" DashpotQuadD4DCB0 _mm_shuffle_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b, int n);
static __forceinline DashpotQuadD4DCB0 splat(const float& x)
{
    DashpotQuadD4DCB0 t = _mm_load_ss(&x);
    return _mm_shuffle_ps(t, t, 0);
}
extern "C" DashpotQuadD4DCB0 _mm_setzero_ps();
extern "C" DashpotQuadD4DCB0 _mm_mul_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_add_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_sub_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);

extern "C" double DAT_010179e0;
extern const float DAT_01017d00 = 0.001f;

static const DashpotQuadD4DCB0 DashpotNegXY = {{-0.0f, -0.0f, -0.0f, 0.0f}};
static const DashpotQuadD4DCB0 DashpotNegAll = {{-0.0f, -0.0f, -0.0f, -0.0f}};

struct S00d4dcb0_DashpotInputRec
{
    unsigned int unk00;
    unsigned int unk04;
    float m_stepDt;
};

struct S00d4dcb0_FUN_00c66320_shell
{
    DashpotQuadD4DCB0 m_vec;
    __declspec(noalias) void FUN_00c66320(const DashpotQuadD4DCB0* a, const DashpotQuadD4DCB0* b);
    __declspec(noalias) float FUN_00c74c20();
};

struct S00d4dcb0_DashpotVObjRec
{
    virtual void virt00();
    virtual void virt04();
    virtual void virt08();
    virtual void virt0c();
    virtual void virt10();
    virtual void virt14();
    virtual void virt18();
    virtual void virt1c();
    virtual void virt20();
    virtual void virt24();
    virtual void virt28();
    virtual void virt2c();
    virtual void virt30();
    virtual void virt34();
    virtual void virt38();
    virtual void virt3c();
    virtual void virt40();
    virtual void virt44();
    virtual void virt48();
    virtual void virt4c();
    virtual void virt50();
    virtual void virt54(const void* arg);
};

struct S00d4dcb0_DashpotEntRec : public DashpotReferencedBaseD4DCB0
{
    void FUN_00c9c1d0();
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    S00d4dcb0_DashpotVObjRec unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    DashpotQuadD4DCB0 unk160;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    DashpotQuadD4DCB0 unk1C0;
};

class S00d4dcb0_DashpotAct_shell : public DashpotActionBaseD4DCB0
{
  public:
    void applyAction(const S00d4dcb0_DashpotInputRec& input);
};

// @fnv 0x00d4dcb0
void S00d4dcb0_DashpotAct_shell::applyAction(const S00d4dcb0_DashpotInputRec& input)
{
    float w = input.m_stepDt * DAT_010179e0;
    S00d4dcb0_DashpotEntRec* aEnt = (S00d4dcb0_DashpotEntRec*)m_pEntityA;
    S00d4dcb0_DashpotEntRec* bEnt = (S00d4dcb0_DashpotEntRec*)m_pEntityB;
    struct S00d4dcb0_Vectors
    {
        S00d4dcb0_FUN_00c66320_shell qprod;
        DashpotQuadD4DCB0 tmp;
    } v;
    S00d4dcb0_FUN_00c66320_shell* __restrict quat = &v.qprod;
    quat->FUN_00c66320(&bEnt->unk160, (DashpotQuadD4DCB0*)&m_rotation);

    v.tmp = _mm_xor_ps(v.qprod.m_vec, DashpotNegXY);
    quat->FUN_00c66320(&aEnt->unk160, &v.tmp);
    v.tmp = _mm_sub_ps(aEnt->unk1C0, bEnt->unk1C0);

    float t = quat->FUN_00c74c20();

    DashpotQuadD4DCB0 corr = _mm_setzero_ps();
    if (t > DAT_01017d00)
        corr = _mm_mul_ps(splat(t), quat->m_vec);

    DashpotQuadD4DCB0 strength, damping;
    {
        float ws0 = w * m_fSpringStrength;
        strength = _mm_load_ss(&ws0);
    }
    {
        float ws1 = w * m_fMotorDamping;
        damping = _mm_load_ss(&ws1);
    }
    union S00d4dcb0_Impulse
    {
        DashpotQuadD4DCB0 v;
    };
    S00d4dcb0_Impulse impulse;
    DashpotQuadD4DCB0& sum = impulse.v;
    sum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(damping, damping, 0), v.tmp),
                     _mm_mul_ps(_mm_shuffle_ps(strength, strength, 0), corr));

    bEnt->FUN_00c9c1d0();
    bEnt->unkE0.virt54(&sum);
    sum = _mm_xor_ps(sum, DashpotNegAll);
    aEnt->FUN_00c9c1d0();
    aEnt->unkE0.virt54(&sum);
}

}


// src/fallout/magic/magicfogprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicfogprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicfogprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicfogprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
    bool FUN_00ad89e0(float);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern xFltSetting xg_11d16f8;
extern xFltSetting xg_11d1c28;
extern const float xg_107ad40;
extern xFltSetting xg_11d1b74;
extern xFltSetting xg_11d15c8;
extern xFltSetting xg_11d15f8;
float xFUN_00404010(float, float);
struct xItem
{
    int FUN_004044d0();
    int FUN_00404420();
};
void xFUN_0080fae0(float);
struct xRadius
{
    float FUN_009b0bd0();
};
struct xSndForm
{
    void* FUN_0084e3a0();
};
struct xEffect
{
    xSndForm* FUN_004fd3c0();
};
struct xCtl
{
    void FUN_0080fb00(xVec4*);
};
struct xCell
{
    void FUN_00548230(void*, bool);
};
struct xOwner
{
    void FUN_0081c4a0(void*);
    void Fade(bool, float);
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
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
    virtual void* FUN_2c();
};

extern void* xg_player_11dea3c;
struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    float m_a8;
    float m_ac;
    float m_b0;
    int m_b4;
    float m_b8;
    xSound m_bc;
    int m_c8;
    xOwner* m_cc;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xEffect* FUN_004fd400();
    xItem* FUN_00586150();
    void FUN_00570f70(void*);
    void FUN_0081e570(int);
    void InitProjectileEffect();
    void FUN_00819ca0();
    xCtl* GetCharController();
    xCell* FUN_008d6f30();
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
    void FUN_0081eba0();
    xActorV* FUN_009185e0();
};
// @fnv 0x00819360
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_ac = xFUN_00404010((float)FUN_00586150()->FUN_004044d0(), *xg_11d1b74.FUN_00403e20());
    m_b0 = xFUN_00404010((float)FUN_00586150()->FUN_00404420(), *xg_11d15c8.FUN_00403e20());
    m_88 = ((xRadius*)FUN_004fd400())->FUN_009b0bd0() * *xg_11d16f8.FUN_00403e20();
    m_b4 = 0;
    m_a8 = 0.0f;
    m_b8 = 1.0f;
    m_cc = 0;
    m_c8 = 0;
    if (apE)
        FUN_00570f70(apE);
    else
        FUN_0081e570(0);
    InitProjectileEffect();
    FUN_00819ca0();
    xVec4 V(-xg_107ad40, 0.0f, 0.0f, 0.0f);
    GetCharController()->FUN_0080fb00(&V);
    FUN_008d6f30()->FUN_00548230(this, false);
    if (FUN_004fd400()->FUN_004fd3c0())
    {
        void* NAME = FUN_004fd400()->FUN_004fd3c0()->FUN_0084e3a0();
        if (m_bc.FUN_00ad8ce0())
            m_bc.FUN_00ad8d10();
        m_bc = PlaySoundByFormID(NAME, 1, 0x40000102, 1);
        m_bc.FUN_00ad89e0(1.0f);
    }
    if (apOwner)
    {
        apOwner->FUN_0081c4a0(this);
        m_cc = apOwner;
        m_cc->Fade(false, m_ac);
    }
    FUN_0081eba0();
    void* SHOOTER = FUN_009185e0() ? FUN_009185e0()->FUN_2c() : 0;
    if (SHOOTER != xg_player_11dea3c)
        xFUN_0080fae0(*xg_11d15f8.FUN_00403e20());
}

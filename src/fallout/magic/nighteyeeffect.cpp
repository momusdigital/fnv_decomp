
// src/fallout/magic/nighteyeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/nighteyeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ValueModifierEffect
{
    void Update(float);
};

struct FUN_0080cea0 : ValueModifierEffect
{
    void Update(float);
};

// @fnv 0x0080cea0
void FUN_0080cea0::Update(float afSecondsElapsed)
{
    ValueModifierEffect::Update(afSecondsElapsed);
}

namespace fnv_00825710 {
struct ValueModifierEffect
{
    ValueModifierEffect(void* a, void* b, void* c);
};

extern int DAT_0107bd7c;

struct FUN_00825710 : ValueModifierEffect
{
    FUN_00825710(void* a, void* b, void* c);
};

// Constructs a ValueModifierEffect base and installs the vtable pointer from DAT_0107bd7c into this object.
// @fnv 0x00825710
FUN_00825710::FUN_00825710(void* apArg1, void* apArg2, void* apArg3) : ValueModifierEffect(apArg1, apArg2, apArg3)
{
    *(void**)this = (void*)&DAT_0107bd7c;
}
}  // namespace fnv_00825710

struct PC7d;
extern PC7d* g_thePlayer;
void __fastcall FUN_00804cb0(void*, float);
void UpdateImageSpaceEffectFromPlayerState();
struct FUN_0082a670_shell
{
    void FUN_0082c000();
};
struct BSThread
{
    unsigned int GetThreadID();
};
struct VirtualObj
{
    virtual void f0();
    virtual PC7d* f1();
};
struct NightEyeEffect
{
    void Start();
};
// @fnv 0x00825810
void NightEyeEffect::Start()
{
    FUN_00804cb0(this, 1.0f);
    ((FUN_0082a670_shell*)this)->FUN_0082c000();
    if (((VirtualObj*)((BSThread*)this)->GetThreadID())->f1() == g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}

namespace fnv_00825860 {
struct PC7d;
extern PC7d* g_thePlayer;
void UpdateImageSpaceEffectFromPlayerState();
struct BSThread
{
    unsigned int GetThreadID();
};
struct RetObj
{
    virtual void f0();
    virtual PC7d* f1();
};
struct Helper082c810
{
    void ApplyEffect();
};
struct NightEyeEffect : ValueModifierEffect
{
    void FUN_00825860();
};
// @fnv 0x00825860
void NightEyeEffect::FUN_00825860()
{
    ((Helper082c810*)this)->ApplyEffect();
    if (((RetObj*)((BSThread*)this)->GetThreadID())->f1() == g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}
}  // namespace fnv_00825860

namespace fnv_00825920 {
struct Actor;
struct PC7d;
extern PC7d* g_thePlayer;
struct ActiveEffect
{
    void InitLoadGame(Actor*);
};
void __cdecl UpdateImageSpaceEffectFromPlayerState();
struct NightEyeEffect : ActiveEffect
{
    void FUN_00825920(Actor* apActor);
};
// Calls ActiveEffect::InitLoadGame for apActor, then UpdateImageSpaceEffectFromPlayerState if apActor is the player.
// @fnv 0x00825920
void NightEyeEffect::FUN_00825920(Actor* apActor)
{
    ActiveEffect::InitLoadGame(apActor);
    if ((void*)apActor == (void*)g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}
}  // namespace fnv_00825920

namespace fnv_00825950 {
struct Actor;
struct TESForm
{
    void Revert(unsigned int);
};
struct TESSaveLoadGame
{
    bool FUN_0055f5b0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern Actor* g_thePlayer;
void __cdecl UpdateImageSpaceEffectFromPlayerState();
struct FUN_00825950_shell : TESForm
{
    void FUN_00825950(Actor* apActor);
};
// Reverts this form with apActor, and if a save/load check passes and apActor is the player, calls UpdateImageSpaceEffectFromPlayerState.
// @fnv 0x00825950
void FUN_00825950_shell::FUN_00825950(Actor* apActor)
{
    Revert(reinterpret_cast<unsigned int>(apActor));
    if (g_TESSaveLoadGame->FUN_0055f5b0() && apActor == g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}
}  // namespace fnv_00825950

struct S_008258a0_Effect
{
    int unk0;
    int unk4;
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
    S_008258a0_Effect(int a, int b, int c);
};

// Allocates and constructs an S_008258a0_Effect from the three arguments and returns the new object.
// @fnv 0x008258a0
S_008258a0_Effect* FUN_008258a0(int aiArg0, int aiArg1, int aiArg2)
{
    return new S_008258a0_Effect(aiArg0, aiArg1, aiArg2);
}

void* operator new(unsigned int size) throw();

struct ActiveEffect;

struct SpawnedEffect
{
    unsigned int unk00[19];
    SpawnedEffect(int a, int b, int c);
};

struct FUN_00825760_cls
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual ActiveEffect* HookEffect(ActiveEffect* e);

    int unk04;
    int m_08;
    int m_0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;

    ActiveEffect* CreateSpawnedEffect();
};

// Allocates a SpawnedEffect from m_28, m_08 and m_0C, passes it to HookEffect, and returns it.
// @fnv 0x00825760
ActiveEffect* FUN_00825760_cls::CreateSpawnedEffect()
{
    ActiveEffect* e = (ActiveEffect*)new SpawnedEffect(m_28, m_08, m_0C);
    HookEffect(e);
    return e;
}

struct FUN_00825990_ImageSpaceEffect
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C(int);
};

struct FUN_00825990_ImageSpaceManager
{
    FUN_00825990_ImageSpaceEffect* __thiscall FUN_004ebbc0(int);
};

struct FUN_00825990_PlayerBase
{
    virtual void vf00();
    virtual void vf04();
    virtual int vf08(int);
};

struct FUN_00825990_PlayerData
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
    FUN_00825990_PlayerBase unkA4;
};

extern FUN_00825990_ImageSpaceManager* __cdecl FUN_004e3270();
extern float* __fastcall FUN_00403e20(float*);
extern FUN_00825990_PlayerData* DAT_011dea3c;
extern float DAT_011d1668;
extern float DAT_011f947c;

// @fnv 0x00825990
void UpdateImageSpaceEffectFromPlayerState()
{
    FUN_00825990_ImageSpaceEffect* effect;

    {
        FUN_00825990_ImageSpaceManager* manager = FUN_004e3270();
        effect = manager->FUN_004ebbc0(3);
    }

    if (DAT_011dea3c->unkA4.vf08(0x32) > 0)
    {
        DAT_011f947c = *FUN_00403e20(&DAT_011d1668);
        effect->vf2C(1);
    }
    else
    {
        DAT_011f947c = 0.0f;
        effect->vf2C(0);
    }
}

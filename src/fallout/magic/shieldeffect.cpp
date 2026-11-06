
// src/fallout/magic/shieldeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/shieldeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ActiveEffect
{
    virtual ~ActiveEffect()
    {}
};
struct ValueModifierEffect : ActiveEffect
{
    virtual void CopyData(ActiveEffect*);
};
struct ShieldEffect : ValueModifierEffect
{
    unsigned int pad0;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
    unsigned int pad6;
    unsigned int pad7;
    unsigned int pad8;
    unsigned int pad9;
    unsigned int pad10;
    unsigned int pad11;
    unsigned int pad12;
    unsigned int pad13;
    unsigned int pad14;
    unsigned int pad15;
    unsigned int pad16;
    unsigned int pad17;
    unsigned int m_uiUnknownValue;
    void FUN_00828050(ActiveEffect*);
};

// @fnv 0x00828050
void ShieldEffect::FUN_00828050(ActiveEffect* apDestination)
{
    ValueModifierEffect::CopyData(apDestination);
    ShieldEffect* pvme = dynamic_cast<ShieldEffect*>(apDestination);
    if (pvme)
        pvme->m_uiUnknownValue = m_uiUnknownValue;
}

struct Actor;
struct LimbConditionEffect
{
    unsigned short FUN_00802d90(Actor*);
};
struct TESSaveLoadGame
{
    unsigned char FUN_008df040(void);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_008283a0_shell
{
    unsigned short GetSaveSize(Actor*);
};
// Returns the save size of the limb condition effect, adding 4 bytes when the save version is at least 0x6E.
// @fnv 0x008283a0
unsigned short FUN_008283a0_shell::GetSaveSize(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ((LimbConditionEffect*)this)->FUN_00802d90(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6E)
        isize += 4;
    return isize;
}

namespace fnv_008283f0 {
struct Actor;
struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
    void SaveGameDataOLD(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct ShieldEffectHelper
{
    void FUN_00802db0(Actor*);
};

struct ShieldEffect_008283f0 : ShieldEffect
{
    void SaveShieldData(Actor*);
};

// @fnv 0x008283f0
void ShieldEffect_008283f0::SaveShieldData(Actor* actor)
{
    ((ShieldEffectHelper*)this)->FUN_00802db0(actor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6e)
        g_TESSaveLoadGame->SaveGameDataOLD((char*)this + 0x4c, 4);
}
}  // namespace fnv_008283f0

namespace fnv_00828430 {
struct Actor;
struct Base00802dd0
{
    void FUN_00802dd0(Actor*);
};
struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
    void ReadTypedData(void*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00828430_shell : ShieldEffect
{
    void FUN_00828430(ActiveEffect* actor);
};

// @fnv 0x00828430
void FUN_00828430_shell::FUN_00828430(ActiveEffect* pEffect)
{
    ((Base00802dd0*)this)->FUN_00802dd0((Actor*)pEffect);
    if ((unsigned char)g_TESSaveLoadGame->FUN_008df040() >= 0x6e)
        g_TESSaveLoadGame->ReadTypedData(&m_uiUnknownValue, 4);
}
}  // namespace fnv_00828430

struct BSThread
{
    unsigned int GetThreadID();
};
struct EffectSetting
{
    bool IsFlagSet(unsigned int);
};
struct MagicTarget
{
    Actor* GetOwnerActor() const;
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
struct ShieldEffectMod
{
    void FUN_008282e0(Actor*, float);
};
struct ValueModifierEffectUpdate
{
    void Update(float);
};
extern double gModifierZero;
struct ShieldEffectUpdate
{
    void UpdateShieldEffect(float dt);
};
// @fnv 0x008281b0
void ShieldEffectUpdate::UpdateShieldEffect(float dt)
{
    ((ValueModifierEffectUpdate*)this)->Update(dt);
    if (!((EffectSetting*)((GameTimerRecord*)(*(unsigned int*)((char*)this + 0xc)))->GetTime())->IsFlagSet(2))
    {
        Actor* actor =
            ((BSThread*)this)->GetThreadID() ? ((MagicTarget*)((BSThread*)this)->GetThreadID())->GetOwnerActor() : 0;
        if (*(float*)((char*)this + 0x20) > gModifierZero || *(unsigned int*)((char*)this + 0x2c) == 4)
            ((ShieldEffectMod*)this)->FUN_008282e0(actor, *(float*)((char*)this + 0x1c) * dt);
    }
}

void* __cdecl operator new(unsigned int);

struct ShieldEffect;

struct ShieldEffectCtor : ShieldEffect
{
    ShieldEffectCtor(unsigned int a, unsigned int b, unsigned int c);
};

// Allocates and constructs a ShieldEffectCtor with the three given arguments, returning it as a ShieldEffect pointer.
// @fnv 0x008280a0
ShieldEffect* CreateShieldEffect(unsigned int auiArg1, unsigned int auiArg2, unsigned int auiArg3)
{
    return new ShieldEffectCtor(auiArg1, auiArg2, auiArg3);
}

extern unsigned int _data_011c16bc;

struct FUN_00827fa0_vtable : ActiveEffect
{
    virtual void StartEffect()
    {}
    virtual void StopEffect()
    {}
    virtual void filler2()
    {}
    virtual void filler3()
    {}
    virtual void filler4()
    {}
    virtual void filler5()
    {}
    virtual void filler6()
    {}
    virtual void filler7()
    {}
    virtual void filler8()
    {}
    virtual void filler9()
    {}
    virtual void filler10()
    {}
    virtual void filler11()
    {}
    virtual void filler12()
    {}
    virtual void filler13()
    {}
    virtual void filler14()
    {}
    virtual void filler15()
    {}
    virtual void CopyFrom(ActiveEffect*)
    {}
};

struct FUN_00827fa0_shell : ShieldEffect
{
    ActiveEffect* FUN_00827fa0();
};

// @fnv 0x00827fa0
ActiveEffect* FUN_00827fa0_shell::FUN_00827fa0()
{
    ShieldEffect* pNewEffect = new ShieldEffectCtor(pad9, pad1, pad2);
    reinterpret_cast<FUN_00827fa0_vtable*>(this)->CopyFrom(pNewEffect);
    return pNewEffect;
}

struct EffectItemStub
{
    int FUN_00403ea0();
};

struct EffectBase
{
    EffectBase(void* a, void* b, void* c);
    ~EffectBase()
    {}
    virtual void Update();
    void FUN_00673400(int value);
};

struct FUN_00827f20 : EffectBase
{
    FUN_00827f20(void* a, void* b, void* c);
};

// @fnv 0x00827f20
FUN_00827f20::FUN_00827f20(void* a, void* b, void* apItem) : EffectBase(a, b, apItem)
{
    FUN_00673400(((EffectItemStub*)apItem)->FUN_00403ea0());
}

struct Actor;
struct FUN_00828120_a
{
    void FUN_0082c000();
    unsigned int FUN_0059bb30();
};
struct FUN_00828120_x
{
    unsigned char FUN_00403e60();
};
struct FUN_00828120_y
{
    FUN_00828120_x* FUN_00825c00(unsigned int);
};
struct FUN_00828120_z
{
    Actor* FUN_00822b40();
};

struct FUN_00828120_cls : ShieldEffect
{
    void FUN_00828120();
};

// Calls FUN_0082c000, then if a flag check or gModifierZero matches, resolves an Actor and calls FUN_008282e0 with it and pad6.
// @fnv 0x00828120
void FUN_00828120_cls::FUN_00828120()
{
    Actor* actor;
    ((FUN_00828120_a*)this)->FUN_0082c000();
    if (((FUN_00828120_y*)this->pad2)->FUN_00825c00(2)->FUN_00403e60() || *(float*)&this->pad7 == gModifierZero)
    {
        actor = (((FUN_00828120_a*)this)->FUN_0059bb30() != 0)
                    ? ((FUN_00828120_z*)((FUN_00828120_a*)this)->FUN_0059bb30())->FUN_00822b40()
                    : 0;
        ((ShieldEffectMod*)this)->FUN_008282e0(actor, *(float*)&this->pad6);
    }
}

class EffectSetting828
{
  public:
    bool IsFlagSet(unsigned int uiFlag);
};

class EffectItem828
{
  public:
    EffectSetting828* GetEffectSetting();
};

class Actor828
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual void unkv0D4();
    virtual void unkv0D8();
    virtual void unkv0DC();
    virtual void unkv0E0();
    virtual void unkv0E4();
    virtual void unkv0E8();
    virtual void unkv0EC();
    virtual void unkv0F0();
    virtual void unkv0F4();
    virtual void unkv0F8();
    virtual void unkv0FC();
    virtual void unkv100();
    virtual void unkv104();
    virtual void unkv108();
    virtual void unkv10C();
    virtual void unkv110();
    virtual void unkv114();
    virtual void unkv118();
    virtual void unkv11C();
    virtual void unkv120();
    virtual void unkv124();
    virtual void unkv128();
    virtual void unkv12C();
    virtual void unkv130();
    virtual void unkv134();
    virtual void unkv138();
    virtual void unkv13C();
    virtual void unkv140();
    virtual void unkv144();
    virtual void unkv148();
    virtual void unkv14C();
    virtual void unkv150();
    virtual void unkv154();
    virtual void unkv158();
    virtual void unkv15C();
    virtual void unkv160();
    virtual void unkv164();
    virtual void unkv168();
    virtual void unkv16C();
    virtual void unkv170();
    virtual void unkv174();
    virtual void unkv178();
    virtual void unkv17C();
    virtual void unkv180();
    virtual void unkv184();
    virtual void unkv188();
    virtual void unkv18C();
    virtual void unkv190();
    virtual void unkv194();
    virtual void unkv198();
    virtual void unkv19C();
    virtual void unkv1A0();
    virtual void unkv1A4();
    virtual void unkv1A8();
    virtual void unkv1AC();
    virtual void unkv1B0();
    virtual void unkv1B4();
    virtual void unkv1B8();
    virtual void unkv1BC();
    virtual void unkv1C0();
    virtual void unkv1C4();
    virtual void unkv1C8();
    virtual void unkv1CC();
    virtual void unkv1D0();
    virtual void unkv1D4();
    virtual void unkv1D8();
    virtual void unkv1DC();
    virtual void unkv1E0();
    virtual void unkv1E4();
    virtual void unkv1E8();
    virtual void unkv1EC();
    virtual void unkv1F0();
    virtual void unkv1F4();
    virtual void unkv1F8();
    virtual void unkv1FC();
    virtual void unkv200();
    virtual void unkv204();
    virtual void unkv208();
    virtual void unkv20C();
    virtual void unkv210();
    virtual void unkv214();
    virtual void unkv218();
    virtual void unkv21C();
    virtual void unkv220();
    virtual void unkv224();
    virtual void unkv228();
    virtual void unkv22C();
    virtual void unkv230();
    virtual void unkv234();
    virtual void unkv238();
    virtual void unkv23C();
    virtual void unkv240();
    virtual void unkv244();
    virtual void unkv248();
    virtual void unkv24C();
    virtual void unkv250();
    virtual void unkv254();
    virtual void unkv258();
    virtual void unkv25C();
    virtual void unkv260();
    virtual void unkv264();
    virtual void unkv268();
    virtual void unkv26C();
    virtual void unkv270();
    virtual void unkv274();
    virtual void unkv278();
    virtual void unkv27C();
    virtual void unkv280();
    virtual void unkv284();
    virtual void unkv288();
    virtual void unkv28C();
    virtual void unkv290();
    virtual void unkv294();
    virtual void unkv298();
    virtual void unkv29C();
    virtual void unkv2A0();
    virtual void unkv2A4();
    virtual void unkv2A8();
    virtual void unkv2AC();
    virtual void unkv2B0();
    virtual void unkv2B4();
    virtual void unkv2B8();
    virtual void unkv2BC();
    virtual void unkv2C0();
    virtual void unkv2C4();
    virtual void unkv2C8();
    virtual void unkv2CC();
    virtual void unkv2D0();
    virtual void unkv2D4();
    virtual void unkv2D8();
    virtual void unkv2DC();
    virtual void unkv2E0();
    virtual void unkv2E4();
    virtual void unkv2E8();
    virtual void unkv2EC();
    virtual void unkv2F0();
    virtual void unkv2F4();
    virtual void unkv2F8();
    virtual void unkv2FC();
    virtual void unkv300();
    virtual void unkv304();
    virtual void unkv308();
    virtual void unkv30C();
    virtual void unkv310();
    virtual void unkv314();
    virtual void unkv318();
    virtual void unkv31C();
    virtual void unkv320();
    virtual void unkv324();
    virtual void unkv328();
    virtual void unkv32C();
    virtual void unkv330();
    virtual void unkv334();
    virtual void unkv338();
    virtual void unkv33C();
    virtual void unkv340();
    virtual void unkv344();
    virtual void unkv348();
    virtual void unkv34C();
    virtual void unkv350();
    virtual void unkv354();
    virtual void unkv358();
    virtual void unkv35C();
    virtual void unkv360();
    virtual void unkv364();
    virtual void unkv368();
    virtual void unkv36C();
    virtual void unkv370();
    virtual void unkv374();
    virtual void unkv378();
    virtual void unkv37C();
    virtual void unkv380();
    virtual void unkv384();
    virtual void unkv388();
    virtual void unkv38C();
    virtual void unkv390();
    virtual void unkv394();
    virtual void unkv398();
    virtual void DamageActorValue(int iAV, float fValue, int iUnk);
    virtual void unkv3A0();
    virtual void unkv3A4();
    virtual void unkv3A8();
    virtual void ModActorValue(int iAV, float fValue, int iUnk);
    virtual void unkv3B0();
    virtual void SetActorValue(int iAV, float fValue);
};

class ActiveEffect828
{
  public:
    int GetActorValue();
    void FUN_008282e0(Actor828* pkTarget, float m_fElapsedTime);

    int unk00;
    int unk04;
    int unk08;
    EffectItem828* m_pkEffectItem;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    int m_iCastingType;
};

// @fnv 0x008282e0
void ActiveEffect828::FUN_008282e0(Actor828* pkTarget, float m_fElapsedTime)
{
    if (!pkTarget || GetActorValue() == 0x4d)
        return;

    if (m_iCastingType == 4)
        pkTarget->SetActorValue(GetActorValue(), m_fElapsedTime);
    else if (m_pkEffectItem->GetEffectSetting()->IsFlagSet(2))
        pkTarget->DamageActorValue(GetActorValue(), m_fElapsedTime, 0);
    else
        pkTarget->ModActorValue(GetActorValue(), m_fElapsedTime, 0);
}

struct FUN_00828260_cls : ValueModifierEffect
{
    int unk04;
    int unk08;
    FUN_00828120_y* unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
    void ApplyEffect();
    FUN_00828120_z* FUN_0059bb30();
    void FUN_008282e0(Actor*, float);
    void FUN_00828260();
};

// @fnv 0x00828260
void FUN_00828260_cls::FUN_00828260()
{
    ApplyEffect();
    if (unk0c->FUN_00825c00(2)->FUN_00403e60())
    {
        Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
        FUN_008282e0(actor, -unk1c);
    }
}

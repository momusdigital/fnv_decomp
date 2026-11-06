
// src/fallout/magic/turnundeadeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/turnundeadeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NiPoint3
{
  public:
    float x, y, z;
};
struct hkVector4
{
    float x, y, z, w;
};
NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, hkVector4 const&);
struct ScriptLocalsX
{
    void* GetLocalData();
};
class MagicCaster
{
};
struct TurnUndeadEffect : ScriptLocalsX
{
    void ApplyTurnUndeadEffect(MagicCaster* apCaster);
};
// Gets a script-local object and, if present, converts its hkVector4 at offset 0x30 into the caster's NiPoint3.
// @fnv 0x0082aa50
void TurnUndeadEffect::ApplyTurnUndeadEffect(MagicCaster* apCaster)
{
    void* bresult = GetLocalData();
    if (bresult)
        SetNiPoint3FromHkVector4(*(NiPoint3*)apCaster, *(hkVector4 const*)((char*)bresult + 0x30));
}

extern unsigned int _data_011c16bc;
void* __cdecl operator new(unsigned int);

class ActiveEffect
{
  public:
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

    char pad0[4];
    int field8;
    int fieldc;
    char pad1[0x18];
    int field28;
    char pad2[0x1c];

    virtual void CopyFrom(ActiveEffect*);
};

class FUN_0082b370 : public ActiveEffect
{
  public:
    bool m_bEffectFlag;

    FUN_0082b370(int, int, int);

    ActiveEffect* Clone();
};

// @fnv 0x0082b3b0
ActiveEffect* FUN_0082b370::Clone()
{
    FUN_0082b370* presult = new FUN_0082b370(field28, field8, fieldc);
    presult->m_bEffectFlag = m_bEffectFlag;
    CopyFrom(presult);
    return presult;
}

class Actor
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool HasFlag139(int);
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual bool HasFlag186();
    unsigned short FUN_0087f9f0();
    bool IsReanimated();
};
class Reference
{
  public:
    Actor* FUN_00822b40();
};
extern char _data_011a0ef8;
extern char _data_011a106c;
bool __cdecl FUN_006494d0(unsigned short value, float strength);
int __cdecl FUN_00ec43fb(Reference* reference, int flag, void* first, void* second, int extra);
class EffectEvaluator
{
  public:
    float GetFloatAtOffset1C();
    bool CheckTarget(Reference* reference);
};
// @fnv 0x0082b460
bool EffectEvaluator::CheckTarget(Reference* reference)
{
    Actor* actor = reference ? reference->FUN_00822b40() : 0;
    if (actor != 0)
    {
        if (!actor->HasFlag139(0) && !actor->HasFlag186())
        {
            if (FUN_006494d0(actor->FUN_0087f9f0(), GetFloatAtOffset1C()))
            {
                int result = FUN_00ec43fb(reference, 0, &_data_011a0ef8, &_data_011a106c, 0);
                if (result != 0)
                {
                }
                else if (actor->IsReanimated())
                    return true;
            }
        }
    }
rejected:
    return false;
}

struct O
{
    int FUN_00822b40();
    int FUN_00815410();
    void FUN_008d0600();
};

struct C
{
    int FUN_0059bb30();
    int FUN_0045cd60();
    void Start();
};

struct D
{
    int FUN_0045cd60();
};

struct V
{
    virtual int v0();
};
// @fnv 0x0082b530
void C::Start()
{
    int b;
    int a;
    b = FUN_0059bb30() ? ((O*)FUN_0059bb30())->FUN_00822b40() : 0;
    a = FUN_0045cd60() ? ((O*)FUN_0045cd60())->FUN_00815410() : 0;
    if (b != 0 && a != 0 && (*(int(__thiscall**)(int))(*(int**)b + 266))(b) != 0)
    {
        ((O*)(*(int(__thiscall**)(int, int, int))(*(int**)b + 266))(b, a, 0))->FUN_008d0600();
        *(char*)((char*)this + 72) = 1;
    }
}

class B82B5E0Package;
class B82B5E0Actor;

class B82B5E0Process
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual void VFunc174();
    virtual void VFunc178();
    virtual void VFunc17C();
    virtual void VFunc180();
    virtual void VFunc184();
    virtual void VFunc188();
    virtual void VFunc18C();
    virtual void VFunc190();
    virtual void VFunc194();
    virtual void VFunc198();
    virtual void VFunc19C();
    virtual void VFunc1A0();
    virtual void VFunc1A4();
    virtual void VFunc1A8();
    virtual void VFunc1AC();
    virtual void VFunc1B0();
    virtual void VFunc1B4();
    virtual void VFunc1B8();
    virtual void VFunc1BC();
    virtual void VFunc1C0();
    virtual void VFunc1C4();
    virtual void VFunc1C8();
    virtual void VFunc1CC();
    virtual void VFunc1D0();
    virtual void VFunc1D4();
    virtual void VFunc1D8();
    virtual void VFunc1DC();
    virtual void VFunc1E0();
    virtual void VFunc1E4();
    virtual void VFunc1E8();
    virtual void VFunc1EC();
    virtual void VFunc1F0();
    virtual void VFunc1F4();
    virtual void VFunc1F8();
    virtual void VFunc1FC();
    virtual void VFunc200();
    virtual void VFunc204();
    virtual void VFunc208();
    virtual void VFunc20C();
    virtual void VFunc210();
    virtual void VFunc214();
    virtual void VFunc218();
    virtual void VFunc21C();
    virtual void VFunc220();
    virtual void VFunc224();
    virtual void VFunc228();
    virtual void VFunc22C();
    virtual void VFunc230();
    virtual void VFunc234();
    virtual void VFunc238();
    virtual void VFunc23C();
    virtual void VFunc240();
    virtual void VFunc244();
    virtual void VFunc248();
    virtual void VFunc24C();
    virtual void VFunc250();
    virtual void VFunc254();
    virtual void VFunc258();
    virtual void VFunc25C();
    virtual void VFunc260();
    virtual void VFunc264();
    virtual void VFunc268();
    virtual void VFunc26C();
    virtual void VFunc270();
    virtual void VFunc274();
    virtual void VFunc278();
    virtual void VFunc27C();
    virtual void VFunc280();
    virtual void VFunc284();
    virtual void VFunc288();
    virtual void VFunc28C();
    virtual void VFunc290();
    virtual void VFunc294();
    virtual void VFunc298();
    virtual void VFunc29C();
    virtual void VFunc2A0();
    virtual void VFunc2A4();
    virtual void VFunc2A8();
    virtual void VFunc2AC();
    virtual void VFunc2B0();
    virtual void VFunc2B4();
    virtual void VFunc2B8();
    virtual void VFunc2BC();
    virtual void VFunc2C0();
    virtual void VFunc2C4();
    virtual void VFunc2C8();
    virtual void VFunc2CC();
    virtual void VFunc2D0();
    virtual void VFunc2D4();
    virtual void VFunc2D8();
    virtual void VFunc2DC();
    virtual void VFunc2E0();
    virtual void VFunc2E4();
    virtual void VFunc2E8();
    virtual void VFunc2EC();
    virtual void VFunc2F0();
    virtual void VFunc2F4();
    virtual void VFunc2F8();
    virtual void VFunc2FC();
    virtual void VFunc300();
    virtual void VFunc304();
    virtual void VFunc308();
    virtual void VFunc30C();
    virtual void VFunc310();
    virtual void VFunc314();
    virtual void VFunc318();
    virtual void VFunc31C();
    virtual void VFunc320();
    virtual void VFunc324();
    virtual void VFunc328();
    virtual void VFunc32C();
    virtual void VFunc330();
    virtual void VFunc334();
    virtual void VFunc338();
    virtual void StartPackage(B82B5E0Actor* pkActor, B82B5E0Package* pkPackage, bool bA, int iB, int iC, int iD, int iE,
                              int iF, int iG, int iH, int iI, bool bJ, int iK);
};

class B82B5E0Actor
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual void VFunc174();
    virtual void VFunc178();
    virtual void VFunc17C();
    virtual void VFunc180();
    virtual void VFunc184();
    virtual void VFunc188();
    virtual void VFunc18C();
    virtual void VFunc190();
    virtual void VFunc194();
    virtual void VFunc198();
    virtual void VFunc19C();
    virtual void VFunc1A0();
    virtual void VFunc1A4();
    virtual void VFunc1A8();
    virtual void VFunc1AC();
    virtual void VFunc1B0();
    virtual void VFunc1B4();
    virtual void VFunc1B8();
    virtual void VFunc1BC();
    virtual void VFunc1C0();
    virtual void VFunc1C4();
    virtual void VFunc1C8();
    virtual void VFunc1CC();
    virtual void VFunc1D0();
    virtual void VFunc1D4();
    virtual void VFunc1D8();
    virtual void VFunc1DC();
    virtual void VFunc1E0();
    virtual void VFunc1E4();
    virtual void VFunc1E8();
    virtual void VFunc1EC();
    virtual void VFunc1F0();
    virtual void VFunc1F4();
    virtual void VFunc1F8();
    virtual void VFunc1FC();
    virtual void VFunc200();
    virtual void VFunc204();
    virtual void VFunc208();
    virtual void VFunc20C();
    virtual void VFunc210();
    virtual void VFunc214();
    virtual void VFunc218();
    virtual void VFunc21C();
    virtual void VFunc220();
    virtual void VFunc224();
    virtual void VFunc228();
    virtual void VFunc22C();
    virtual void VFunc230();
    virtual void VFunc234();
    virtual void VFunc238();
    virtual void VFunc23C();
    virtual void VFunc240();
    virtual void VFunc244();
    virtual void VFunc248();
    virtual void VFunc24C();
    virtual void VFunc250();
    virtual void VFunc254();
    virtual void VFunc258();
    virtual void VFunc25C();
    virtual void VFunc260();
    virtual void VFunc264();
    virtual void VFunc268();
    virtual void VFunc26C();
    virtual void VFunc270();
    virtual void VFunc274();
    virtual void VFunc278();
    virtual void VFunc27C();
    virtual void VFunc280();
    virtual void VFunc284();
    virtual void VFunc288();
    virtual void VFunc28C();
    virtual void VFunc290();
    virtual void VFunc294();
    virtual void VFunc298();
    virtual void VFunc29C();
    virtual void VFunc2A0();
    virtual void VFunc2A4();
    virtual void VFunc2A8();
    virtual void VFunc2AC();
    virtual void VFunc2B0();
    virtual void VFunc2B4();
    virtual void VFunc2B8();
    virtual void VFunc2BC();
    virtual void VFunc2C0();
    virtual void VFunc2C4();
    virtual void VFunc2C8();
    virtual void VFunc2CC();
    virtual void VFunc2D0();
    virtual void VFunc2D4();
    virtual void VFunc2D8();
    virtual void VFunc2DC();
    virtual void VFunc2E0();
    virtual void VFunc2E4();
    virtual void VFunc2E8();
    virtual void VFunc2EC();
    virtual void VFunc2F0();
    virtual void VFunc2F4();
    virtual void VFunc2F8();
    virtual void VFunc2FC();
    virtual void VFunc300();
    virtual void VFunc304();
    virtual void VFunc308();
    virtual void VFunc30C();
    virtual void VFunc310();
    virtual void VFunc314();
    virtual void VFunc318();
    virtual void VFunc31C();
    virtual void VFunc320();
    virtual void VFunc324();
    virtual void VFunc328();
    virtual void VFunc32C();
    virtual void VFunc330();
    virtual void VFunc334();
    virtual void VFunc338();
    virtual void VFunc33C();
    virtual void VFunc340();
    virtual void VFunc344();
    virtual void VFunc348();
    virtual void VFunc34C();
    virtual void VFunc350();
    virtual void VFunc354();
    virtual void VFunc358();
    virtual void VFunc35C();
    virtual void VFunc360();
    virtual void VFunc364();
    virtual void VFunc368();
    virtual void VFunc36C();
    virtual void VFunc370();
    virtual void VFunc374();
    virtual void VFunc378();
    virtual void VFunc37C();
    virtual void VFunc380();
    virtual void VFunc384();
    virtual void VFunc388();
    virtual void VFunc38C();
    virtual void VFunc390();
    virtual void VFunc394();
    virtual void VFunc398();
    virtual void VFunc39C();
    virtual void VFunc3A0();
    virtual void VFunc3A4();
    virtual void VFunc3A8();
    virtual void VFunc3AC();
    virtual void VFunc3B0();
    virtual void VFunc3B4();
    virtual void VFunc3B8();
    virtual void VFunc3BC();
    virtual void VFunc3C0();
    virtual void VFunc3C4();
    virtual void VFunc3C8();
    virtual void VFunc3CC();
    virtual void VFunc3D0();
    virtual void VFunc3D4();
    virtual void VFunc3D8();
    virtual void VFunc3DC();
    virtual void VFunc3E0();
    virtual void VFunc3E4();
    virtual void VFunc3E8();
    virtual void VFunc3EC();
    virtual void VFunc3F0();
    virtual void VFunc3F4();
    virtual void VFunc3F8();
    virtual void VFunc3FC();
    virtual void VFunc400();
    virtual void VFunc404();
    virtual void VFunc408();
    virtual void VFunc40C();
    virtual void VFunc410();
    virtual void VFunc414();
    virtual void VFunc418();
    virtual void VFunc41C();
    virtual void VFunc420();
    virtual void VFunc424();
    virtual void VFunc428();
    virtual void VFunc42C();
    virtual void VFunc430();
    virtual void SetPackage(B82B5E0Package* pkPackage);

    bool FUN_00493bb0();
    B82B5E0Process* GetProcess();
};

class B82B5E0ActorHandle
{
  public:
    B82B5E0Actor* Get();
};

class B82B5E0PackageHandle
{
  public:
    B82B5E0Package* Get();
};

class B82B5E0Request
{
  public:
    B82B5E0ActorHandle* GetActorHandle();
    B82B5E0PackageHandle* GetPackageHandle();
    void ApplyPackageToActor();

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
    bool m_bModifierActive;
};

// If the request is active, resolves the actor and package handles and, when the actor passes FUN_00493bb0, sets the package and starts it on the actor's process.
// @fnv 0x0082b5e0
void B82B5E0Request::ApplyPackageToActor()
{
    if (!m_bModifierActive)
        return;
    B82B5E0Actor* pkActor = GetActorHandle() ? GetActorHandle()->Get() : 0;
    B82B5E0Package* pkPackage3 = GetPackageHandle() ? GetPackageHandle()->Get() : 0;
    if (pkActor && pkActor->FUN_00493bb0())
    {
        pkActor->SetPackage(pkPackage3);
        if (pkPackage3 && pkActor->GetProcess())
            pkActor->GetProcess()->StartPackage(pkActor, pkPackage3, true, 0, 0, 0, 0, 0, 0, 0, 0, true, 0);
    }
}

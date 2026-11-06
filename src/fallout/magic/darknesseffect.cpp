
// src/fallout/magic/darknesseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/darknesseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01079d2c;

struct ValueModifierEffect
{
    void* vtbl;
    void* a;
    void* b;
    void* c;
    ValueModifierEffect(void* x, void* y, void* z);
};

struct FUN_0080c460_shell : public ValueModifierEffect
{
    FUN_0080c460_shell(void* x, void* y, void* z);
};

// Constructs a ValueModifierEffect subobject and sets its vtable pointer to DAT_01079d2c.
// @fnv 0x0080c460
FUN_0080c460_shell::FUN_0080c460_shell(void* apArg1, void* apArg2, void* apArg3)
    : ValueModifierEffect(apArg1, apArg2, apArg3)
{
    vtbl = &DAT_01079d2c;
}

struct TESForm
{
    virtual void Revert(unsigned int);
};
struct TESObjectREFR
{
    int GetReferenceType();
};
struct Actor : TESObjectREFR
{
};
struct DarknessEffect : TESForm
{
    void FUN_0080c850(Actor*);
};
void __cdecl FUN_00b55b00(int, float);
// @fnv 0x0080c850
void DarknessEffect::FUN_0080c850(Actor* apActor)
{
    TESForm::Revert((unsigned int)apActor);
    if (apActor->GetReferenceType())
        FUN_00b55b00(apActor->GetReferenceType(), 1.0F);
}

struct FUN_0080c730_shell : public FUN_0080c460_shell
{
    char pad[0x4c - sizeof(FUN_0080c460_shell)];
    FUN_0080c730_shell(void* x, void* y, void* z);
};
// Allocates and constructs a new FUN_0080c730_shell from the three given arguments and returns it.
// @fnv 0x0080c730
FUN_0080c730_shell* __cdecl FUN_0080c730(void* a, void* b, void* c)
{
    return new FUN_0080c730_shell(a, b, c);
}

void* __cdecl operator new(unsigned int);

typedef void ActiveEffect;

struct CopyTarget
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void CopyFrom(ActiveEffect*)
    {}
};

struct FUN_0080c4c0_shell
{
    void* vtbl;
    void* a;
    void* b;
    void* c;
    void* d;

    ActiveEffect* Clone();
};

// @fnv 0x0080c4c0
ActiveEffect* FUN_0080c4c0_shell::Clone()
{
    ActiveEffect* presult = new FUN_0080c730_shell(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28),
                                                   *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08),
                                                   *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x0c));

    reinterpret_cast<CopyTarget*>(this)->CopyFrom(presult);
    return presult;
}

struct BSThread
{
    unsigned int GetThreadID(void);
};

struct MagicTarget
{
    Actor* GetOwnerActor(void) const;
};

struct FUN_0080dd30_shell
{
    void FUN_0082c000(void);
};

double _DAT_01012060;
double g_d100;

struct FUN_0080c570_ActorVirtuals
{
    virtual void F000() = 0;
    virtual void F001() = 0;
    virtual void F002() = 0;
    virtual void F003() = 0;
    virtual void F004() = 0;
    virtual void F005() = 0;
    virtual void F006() = 0;
    virtual void F007() = 0;
    virtual void F008() = 0;
    virtual void F009() = 0;
    virtual void F010() = 0;
    virtual void F011() = 0;
    virtual void F012() = 0;
    virtual void F013() = 0;
    virtual void F014() = 0;
    virtual void F015() = 0;
    virtual void F016() = 0;
    virtual void F017() = 0;
    virtual void F018() = 0;
    virtual void F019() = 0;
    virtual void F020() = 0;
    virtual void F021() = 0;
    virtual void F022() = 0;
    virtual void F023() = 0;
    virtual void F024() = 0;
    virtual void F025() = 0;
    virtual void F026() = 0;
    virtual void F027() = 0;
    virtual void F028() = 0;
    virtual void F029() = 0;
    virtual void F030() = 0;
    virtual void F031() = 0;
    virtual void F032() = 0;
    virtual void F033() = 0;
    virtual void F034() = 0;
    virtual void F035() = 0;
    virtual void F036() = 0;
    virtual void F037() = 0;
    virtual void F038() = 0;
    virtual void F039() = 0;
    virtual void F040() = 0;
    virtual void F041() = 0;
    virtual void F042() = 0;
    virtual void F043() = 0;
    virtual void F044() = 0;
    virtual void F045() = 0;
    virtual void F046() = 0;
    virtual void F047() = 0;
    virtual void F048() = 0;
    virtual void F049() = 0;
    virtual void F050() = 0;
    virtual void F051() = 0;
    virtual void F052() = 0;
    virtual void F053() = 0;
    virtual void F054() = 0;
    virtual void F055() = 0;
    virtual void F056() = 0;
    virtual void F057() = 0;
    virtual void F058() = 0;
    virtual void F059() = 0;
    virtual void F060() = 0;
    virtual void F061() = 0;
    virtual void F062() = 0;
    virtual void F063() = 0;
    virtual void F064() = 0;
    virtual void F065() = 0;
    virtual void F066() = 0;
    virtual void F067() = 0;
    virtual void F068() = 0;
    virtual void F069() = 0;
    virtual void F070() = 0;
    virtual void F071() = 0;
    virtual void F072() = 0;
    virtual void F073() = 0;
    virtual void F074() = 0;
    virtual void F075() = 0;
    virtual void F076() = 0;
    virtual void F077() = 0;
    virtual void F078() = 0;
    virtual void F079() = 0;
    virtual void F080() = 0;
    virtual void F081() = 0;
    virtual void F082() = 0;
    virtual void F083() = 0;
    virtual void F084() = 0;
    virtual void F085() = 0;
    virtual void F086() = 0;
    virtual void F087() = 0;
    virtual void F088() = 0;
    virtual void F089() = 0;
    virtual void F090() = 0;
    virtual void F091() = 0;
    virtual void F092() = 0;
    virtual void F093() = 0;
    virtual void F094() = 0;
    virtual void F095() = 0;
    virtual void F096() = 0;
    virtual void F097() = 0;
    virtual void F098() = 0;
    virtual void F099() = 0;
    virtual void F100() = 0;
    virtual void F101() = 0;
    virtual void F102() = 0;
    virtual void F103() = 0;
    virtual void F104() = 0;
    virtual void F105() = 0;
    virtual void F106() = 0;
    virtual void F107() = 0;
    virtual void F108() = 0;
    virtual void F109() = 0;
    virtual void F110() = 0;
    virtual void F111() = 0;
    virtual void F112() = 0;
    virtual void F113() = 0;
    virtual void F114() = 0;
    virtual void F115() = 0;
    virtual int GetValue() = 0;
};

struct FUN_0080c570_InnerBase
{
    virtual void F000() = 0;
    virtual void F001() = 0;
    virtual void F002() = 0;
};

struct FUN_0080c570_Inner : public FUN_0080c570_InnerBase
{
    virtual double GetValue(unsigned int) = 0;
};

struct FUN_0080c570_shell : public DarknessEffect
{
    void UpdateDarkness();
};

// Gets the target actor, calls FUN_0082c000, and if the actor has a value, computes a clamped darkness from its inner value and applies it via FUN_00b55b00.
// @fnv 0x0080c570
void FUN_0080c570_shell::UpdateDarkness()
{
    Actor* ptargetActor;
    float fnewDarkness;

    ptargetActor =
        reinterpret_cast<BSThread*>(this)->GetThreadID()
            ? reinterpret_cast<MagicTarget*>(reinterpret_cast<BSThread*>(this)->GetThreadID())->GetOwnerActor()
            : 0;

    reinterpret_cast<FUN_0080dd30_shell*>(this)->FUN_0082c000();

    if (ptargetActor && reinterpret_cast<FUN_0080c570_ActorVirtuals*>(ptargetActor)->GetValue())
    {
        fnewDarkness = static_cast<float>(
            1.0 - reinterpret_cast<FUN_0080c570_Inner*>(reinterpret_cast<char*>(ptargetActor) + 0xa4)
                          ->GetValue(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48)) /
                      g_d100);

        if (fnewDarkness < _DAT_01012060)
            fnewDarkness = 0.0f;

        if (fnewDarkness > 1.0)
            fnewDarkness = 1.0f;

        FUN_00b55b00(reinterpret_cast<FUN_0080c570_ActorVirtuals*>(ptargetActor)->GetValue(), fnewDarkness);
    }
}

namespace fnv_0080c650 {
extern double _DAT_01012060;
extern double g_d100;

struct BSThread
{
    unsigned int GetThreadID();
};

struct MagicTarget
{
    Actor* GetOwnerActor() const;
};

struct FUN_0082c810_shell
{
    void ApplyEffect();
};

struct FUN_0080c650_ActorVTableBase
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual void v076()
    {}
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
};

struct FUN_0080c650_ActorVTable : public FUN_0080c650_ActorVTableBase
{
    virtual int v116()
    {
        return 1;
    }
};

struct FUN_0080c650_Nested
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual double v003(int)
    {
        return 0.0;
    }
};

struct FUN_0080c650_shell : public DarknessEffect
{
    void UpdateDarknessEffect();
};

// @fnv 0x0080c650
void FUN_0080c650_shell::UpdateDarknessEffect()
{
    reinterpret_cast<FUN_0082c810_shell*>(this)->ApplyEffect();

    Actor* ptargetActor =
        reinterpret_cast<BSThread*>(this)->GetThreadID()
            ? reinterpret_cast<MagicTarget*>(reinterpret_cast<BSThread*>(this)->GetThreadID())->GetOwnerActor()
            : 0;
    float fnewDarkness;

    if (ptargetActor && reinterpret_cast<FUN_0080c650_ActorVTable*>(ptargetActor)->v116())
    {
        fnewDarkness = 1.0 - reinterpret_cast<FUN_0080c650_Nested*>(reinterpret_cast<char*>(ptargetActor) + 0xa4)
                                     ->v003(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x48)) /
                                 g_d100;

        if (fnewDarkness < _DAT_01012060)
            fnewDarkness = 0.0f;
        if (fnewDarkness > 1.0)
            fnewDarkness = 1.0f;

        FUN_00b55b00(reinterpret_cast<FUN_0080c650_ActorVTable*>(ptargetActor)->v116(), fnewDarkness);
    }
}
}  // namespace fnv_0080c650

extern double _DAT_01012060;
extern double g_d100;

struct P09H
{
    int __thiscall GetReferenceType();
};

struct InvisibilityEffect
{
    void __thiscall FUN_0082cd10(Actor*);
};

struct FUN_0080c7b0_helper
{
// @fnv 0x0080c7b0
    virtual void FUN_0080c7b0_1()
    {}
    virtual void FUN_0080c7b0_2()
    {}
    virtual void FUN_0080c7b0_3()
    {}
    virtual float GetValue(int)
    {
        return 0.0f;
    }
};

struct FUN_0080c7b0_shell : public DarknessEffect
{
    void FinishInitLoadGame(Actor*);
};

void FUN_0080c7b0_shell::FinishInitLoadGame(Actor* apActor)
{
    reinterpret_cast<InvisibilityEffect*>(this)->FUN_0082cd10(apActor);

    float fnewDarkness = 1.0 - (reinterpret_cast<FUN_0080c7b0_helper*>(reinterpret_cast<char*>(apActor) + 0xa4))
                                       ->GetValue(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x48)) /
                                   g_d100;

    if (fnewDarkness < 0.0)
        fnewDarkness = 0.0f;

    if (fnewDarkness > 1.0)
        fnewDarkness = 1.0f;

    if (reinterpret_cast<P09H*>(apActor)->GetReferenceType() != 0)
        FUN_00b55b00(reinterpret_cast<P09H*>(apActor)->GetReferenceType(), fnewDarkness);
}

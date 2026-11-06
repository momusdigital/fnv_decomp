
// src/fallout/magic/chameleoneffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/chameleoneffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0107994c;

struct ValueModifierEffect
{
    ValueModifierEffect(void* a, void* b, void* c);
};

struct FUN_0080acf0_shell : ValueModifierEffect
{
    FUN_0080acf0_shell(void* a, void* b, void* c);
};

// Constructs a ValueModifierEffect base and installs the vtable pointer from DAT_0107994c.
// @fnv 0x0080acf0
FUN_0080acf0_shell::FUN_0080acf0_shell(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *reinterpret_cast<int**>(this) = &DAT_0107994c;
}

struct TESForm
{
    virtual void Revert(unsigned int);
};
bool __cdecl FUN_005b9b00();
struct Actor
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void d196();
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void At0x384(int, float);
    void UpdateActorPresentation();
};
struct ChameleonEffect : TESForm
{
    void FUN_0080b1b0(Actor*);
};
// @fnv 0x0080b1b0
void ChameleonEffect::FUN_0080b1b0(Actor* apActor)
{
    TESForm::Revert((unsigned int)apActor);
    if (FUN_005b9b00())
        apActor->At0x384(1, 0.0F);
    else
        apActor->UpdateActorPresentation();
}

namespace fnv_0080b310 {
bool __cdecl FUN_005b9b00(void);
struct TESForm
{
    void Revert(unsigned int);
};
struct Actor
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void func225(int, float);
    void UpdateActorPresentation(void);
};
struct BGSLoadFormBuffer
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual Actor* b3();
};
struct ChameleonEffect : TESForm
{
    void FUN_0080b310(BGSLoadFormBuffer* apActor);
};
// @fnv 0x0080b310
void ChameleonEffect::FUN_0080b310(BGSLoadFormBuffer* apActor)
{
    Actor* actor = apActor->b3();
    TESForm::Revert((unsigned int)apActor);
    if (FUN_005b9b00())
        actor->func225(1, 0.0f);
    else
        actor->UpdateActorPresentation();
}
}  // namespace fnv_0080b310

struct FUN_0080b040_shell : FUN_0080acf0_shell
{
    char pad[76];
    FUN_0080b040_shell(void* a, void* b, void* c);
};

// Allocates and constructs a FUN_0080b040_shell from three arguments and returns it.
// @fnv 0x0080b040
FUN_0080acf0_shell* __cdecl FUN_0080b040(void* a, void* b, void* c)
{
    return new FUN_0080b040_shell(a, b, c);
}

extern double DAT_01017a40;

struct FUN_0080b0c0_sub
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual float GetX(int v);
};

struct FUN_0080b0c0_arg : Actor
{
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
    FUN_0080b0c0_sub m_a4;
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void At0x41c(float f);
};

struct FUN_008c4640_cls
{
    void FUN_008c4640();
};

struct FUN_0080b0c0_cls
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
    int m_48;
    void FUN_0082cd10(FUN_0080b0c0_arg* a);
    void FinishInitLoadGame(FUN_0080b0c0_arg* a1);
};

float __cdecl FUN_00404010(float a, float b);
float __cdecl FUN_0040ebd0(float a, float b);
float __cdecl FUN_0040df50();
float __cdecl GetOriginalRuntimeFloatSetting9();
float __cdecl LinearInterpolate(float a, float b, float c, float d, float e);

// @fnv 0x0080b0c0
void FUN_0080b0c0_cls::FinishInitLoadGame(FUN_0080b0c0_arg* a1)
{
    FUN_0082cd10(a1);
    if (FUN_005b9b00())
    {
        a1->At0x41c(1.0f);
        float h;
        float s;
        h = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(a1->m_a4.GetX(m_48) / DAT_01017a40)));
        s = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f, 1.0f - h);
        a1->At0x384(1, s);
    }
    else
    {
        reinterpret_cast<FUN_008c4640_cls*>(a1)->FUN_008c4640();
    }
}

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_0040df50();
float __cdecl GetOriginalRuntimeFloatSetting9();
float __cdecl LinearInterpolate(float, float, float, float, float);

struct ActorValueOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int avCode);
};

struct ChamActor
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void d196();
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void SetAlpha(int unk, float alpha);
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void AssignActorValue(float value);
    void UpdateActorPresentation();

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
    ActorValueOwner avOwner;
};

struct MagicTarget
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ChamActor* GetTargetActor();
};

struct ChamActiveEffect
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    bool bApplied;
    char pad11;
    char pad12;
    char pad13;
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
    int actorVal;

    void Start(MagicTarget* target);
    void FUN_0080b200(MagicTarget* target);
};

// @fnv 0x0080b200
void ChamActiveEffect::FUN_0080b200(MagicTarget* target)
{
    ChamActor* actor = target->GetTargetActor();
    Start(target);
    if (bApplied)
    {
        if (FUN_005b9b00())
        {
            actor->AssignActorValue(1.0f);
            float clamped =
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(actor->avOwner.GetActorValue(actorVal) / 100.0)));
            float alpha4 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f,
                                             (float)(1.0 - clamped));
            actor->SetAlpha(1, alpha4);
        }
        else
        {
            actor->UpdateActorPresentation();
        }
    }
}

struct MidObj
{
    FUN_0080b0c0_arg* FUN_00822b40();
};
extern double DAT_01012060;
struct ThiS
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int actorVal;
    void ApplyEffect();
    MidObj* FUN_0059bb30();
    void FUN_0080aef0();
};

// @fnv 0x0080aef0
void ThiS::FUN_0080aef0()
{
    FUN_0080b0c0_arg* actor;
    float ratio3;
    float interp2;

    ApplyEffect();
    actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : (FUN_0080b0c0_arg*)0;
    if (actor != 0)
    {
        if (FUN_005b9b00())
        {
            ratio3 = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, actor->m_a4.GetX(actorVal) / DAT_01017a40));
            if (ratio3 > DAT_01012060)
            {
                interp2 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f,
                                            1.0f - ratio3 / DAT_01017a40);
                actor->At0x384(1, interp2);
            }
            else
            {
                actor->At0x384(1, 0.0f);
                ((FUN_008c4640_cls*)actor)->FUN_008c4640();
            }
        }
        else
        {
            ((FUN_008c4640_cls*)actor)->FUN_008c4640();
        }
    }
}

struct MyChamActor : ChamActor
{
    void FUN_008c4640();
};

struct EffectOwner
{
    MyChamActor* FUN_00822b40();
};

struct MyActiveEffect : ChamActiveEffect
{
    EffectOwner* FUN_0059bb30();
    void FUN_0082c000();
    void UpdateChameleonEffect();
};

// @fnv 0x0080add0
void MyActiveEffect::UpdateChameleonEffect()
{
    MyChamActor* q = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    FUN_0082c000();
    if (q != 0)
    {
        if (FUN_005b9b00())
        {
            q->AssignActorValue(1.0f);
            float r2 = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, q->avOwner.GetActorValue(actorVal) / DAT_01017a40));
            float r3 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f, 1.0f - r2);
            q->SetAlpha(1, r3);
        }
        else
        {
            q->FUN_008c4640();
        }
    }
}

struct FUN_0080acf0_Effect
{
    FUN_0080acf0_Effect(void* a, void* b, void* c);
    virtual ~FUN_0080acf0_Effect();
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
};
struct EffectAD20
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void CopyTo(FUN_0080acf0_Effect* pkCopy);
    int unk04;
    void* m_08;
    void* m_0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* m_28;
    FUN_0080acf0_Effect* Clone();
};

// Allocates a new FUN_0080acf0_Effect using m_28, m_08, m_0C, copies state into it via CopyTo, and returns the new object.
// @fnv 0x0080ad20
FUN_0080acf0_Effect* EffectAD20::Clone()
{
    FUN_0080acf0_Effect* pkCopy = new FUN_0080acf0_Effect(m_28, m_08, m_0C);
    CopyTo(pkCopy);
    return pkCopy;
}

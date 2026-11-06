
// src/fallout/magic/magicballprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicballprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicballprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicballprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicballprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicballprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00810a80_shell
{
    float GetFloatAtOffset53C();
};
extern double _gModifierZero;
struct FUN_00822a20_shell
{
    void CheckModifierNonZero(float a);
};

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct xFilter
{
    unsigned int FUN_004a3a20();
    unsigned int m_uiFilterValue;
};
struct xCell;
struct xWorld
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
    virtual void FUN_d0(void*, int, int, unsigned int, int);
};

xWorld* __fastcall xFUN_004543c0(xCell*);
float __fastcall xFUN_005471e0(xCell*);
bool __fastcall xFUN_004bae00(xWorld*);
struct xAVOwner
{
    int FUN_0066ef20(int);
};
float xFUN_00646660(float, float, int);
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct __declspec(align(16)) xCtlCinfo
{
    xCtlCinfo(int);
    ~xCtlCinfo();
    void FUN_00810550(float);
    void FUN_00407860(float);
    void SetWaterForm(void*);
    void FUN_00810510(const xP3&);
    void SetSound(xWorld*);
    void SetPointer(void*);
    void FUN_00810530(bool);
    void FUN_00810590(int, unsigned int);
    void SetAssociatedActorValue(int);
    xM128 m_q[12];
};
unsigned int xFUN_008cddb0();
bool xFUN_00525420();
void xFUN_00b6b910(void*, int);
void xFUN_00c6a350(void*, int, bool, bool, bool);
void xFUN_00c69ee0(void*, int, int);
void xFUN_00c69f50(void*, int, int);
extern const float xg_1015f5c;
struct xActor;
void* __cdecl xFUN_00553300(unsigned int);
struct xCharCtl
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
    virtual void FUN_d0(int);
    static void* operator new(unsigned int n)
    {
        return xFUN_00553300(n);
    }
    static void operator delete(void*);
    xCharCtl(xCtlCinfo*, xActor*);
    void SetFallTime(float);
    void FUN_00810610(bool);
    void FUN_008105e0(bool);
    void FUN_00810640(xActor*);
    void FUN_0057b1d0(float);
    xWorld* FUN_00621ad0();
    void FUN_00c70c90(xWorld*);
    void* GetNiObject();
    void FUN_00c6d7a0(void*);
    void FUN_005620e0(xP3*);
    xFilter FUN_0070c440();
    int m_auiShapeKeys[0x197];
};

struct xCtlPtr
{
    xCtlPtr(xCharCtl*);
    ~xCtlPtr();
    void* m_p;
};
struct xMid
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
    virtual void FUN_290(xCtlPtr);
    void* FUN_0045cd60();
};
struct xActor
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
    virtual void* FUN_1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    char m_pad04[0x64];
    xMid* m_68;
    char m_pad6c[0x38];
    xAVOwner m_a4;
    xCharCtl* GetCharController();
    xCell* FUN_008d6f30();
    xFilter FUN_00931ed0();
    void InitHavok(xActor* apOther, float afVal);
};

// @fnv 0x008caea0
void xActor::InitHavok(xActor* apOther, float afVal)
{
    if (!m_68 || m_68->FUN_0045cd60())
        return;
    xCharCtl* CTL = GetCharController();
    xCell* CELL = FUN_008d6f30();
    xWorld* WORLD = CELL ? xFUN_004543c0(CELL) : 0;
    if (!CTL)
    {
        xCtlCinfo CI(1);
        CI.FUN_00810550(0.0f);
        if (apOther)
            CI.FUN_00407860(xFUN_00646660(afVal, 50.0f, apOther->m_a4.FUN_0066ef20(0xb)));
        CI.SetWaterForm(FUN_1d0());
        CI.FUN_00810510(*FUN_1f4());
        CI.SetSound(WORLD);
        CI.SetPointer(new xShape(0.1f, true));
        CI.FUN_00810530(false);
        if (apOther)
            CI.FUN_00810590(6, apOther->FUN_00931ed0().FUN_004a3a20());
        else
            CI.FUN_00810590(6, xFUN_008cddb0());
        CI.SetAssociatedActorValue(6);
        CTL = new xCharCtl(&CI, this);
        CTL->SetFallTime(1.0f);
        CTL->FUN_00810610(xFUN_00525420());
        CTL->FUN_008105e0(true);
        m_68->FUN_290(CTL);
        CTL->FUN_00810640(this);
    }
    if (CTL)
    {
        if (CELL && WORLD)
            CTL->FUN_0057b1d0(xFUN_005471e0(CELL));
        else
            CTL->FUN_0057b1d0(xg_1015f5c);
        xWorld* PREV = CTL->FUN_00621ad0();
        CTL->FUN_00c70c90(WORLD);
        void* NODE = FUN_1d0();
        void* CUR = CTL->GetNiObject();
        bool ADD = true;
        if (CUR != NODE)
        {
            CTL->FUN_00c6d7a0(NODE);
            if (WORLD && xFUN_004bae00(WORLD))
            {
                CTL->FUN_d0(0);
                xFUN_00b6b910(CTL->GetNiObject(), 1);
            }
            xFUN_00c6a350(NODE, 4, true, false, true);
            ADD = true;
        }
        xP3 POS = *FUN_1f4();
        if (PREV != WORLD)
        {
            if (PREV)
                xFUN_00c69ee0(NODE, 1, 0);
            POS.z = POS.z + 8.0;
            ADD = true;
        }
        if (WORLD)
        {
            CTL->FUN_005620e0(&POS);
            if (ADD)
            {
                xFilter FILTER = CTL->FUN_0070c440();
                unsigned int LAYER = FILTER.FUN_004a3a20();
                WORLD->FUN_d0(NODE, 1, 0, LAYER, 0);
            }
            else
                xFUN_00c69f50(NODE, 1, 0);
        }
    }
}

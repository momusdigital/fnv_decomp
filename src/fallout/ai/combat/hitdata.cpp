
// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_009b7040_shell
{
    float GetField168();
};

// @fnv 0x009b7040
float FUN_009b7040_shell::GetField168()
{
    return *(float*)((char*)this + 0x168);
}

struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
};

// @fnv 0x009b73b0
char FUN_009b73b0_shell::GetByteAtOffset() const
{
    return *(char*)((char*)this + 0x1c8);
}

struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
};

// If a exceeds the float at offset 0x5c, stores a there, keeping the larger of the two.
// @fnv 0x009b7840
void FUN_009b7840_shell::RaiseMaxValue(float afValue)
{
    if (afValue > *((float*)((char*)this + 0x5c)))
    {
        *((float*)((char*)this + 0x5c)) = afValue;
    }
}

// Returns true for the index values 0, 1, 2, 16, 17, 20 and 21, and false for any other value.
// @fnv 0x0066de30
bool FUN_0066de30(int a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 16:
    case 17:
    case 20:
    case 21:
        return true;
    default:
        return false;
    }
}

extern float DAT_011f4270;
extern float DAT_011f4274;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern NiPoint3 _NiPoint3_ZERO;

struct BooleanFloatQuery
{
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void FUN_009b4dc0();
};

// @fnv 0x009b4dc0
void BooleanFloatQuery::FUN_009b4dc0()
{
    m_pAggressor = 0;
    pTarget = 0;
    m_pSourceReference = 0;
    m_uiHitLocation = 0x4d;
    m_uiHitFlags = 0xffffffff;
    m_fDamage = 0.0f;
    m_fArmorDamage = 0.0f;
    m_fHealthDamage = 0.0f;
    m_fLimbDamage = 0.0f;
    m_fFatigueDamage = 0.0f;
    m_fSneakAttackMultiplier = 0.0f;
    m_fCriticalHitMultiplier = 0.0f;
    vOffset1 = _NiPoint3_ZERO;
    vOffset2 = _NiPoint3_ZERO;
    pWeapon = 0;
    m_fWeaponDamage = 0.0f;
    m_pHitDataObjectAtOffset50 = 0;
    m_pHitDataObjectAtOffset54 = 0;
    uiFlags = 0;
    BackgroundTask = 0;
    m_fHitValueAtOffset5C = 0.0f;
}

struct GlobalObject_00869f00
{
    void Clear(bool a);
};

extern int DAT_0108f9e8;

struct FUN_009b7970_shell
{
    void InitializeAndClear();
};

// @fnv 0x009b7970
void FUN_009b7970_shell::InitializeAndClear()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0108f9e8;
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}

struct FUN_009b7010_shell
{
    NiPoint3& FUN_009b7010(NiPoint3& akDest);
};
// Copies the NiPoint3 stored at offset 0x104 of this object into akDest and returns it.
// @fnv 0x009b7010
NiPoint3& FUN_009b7010_shell::FUN_009b7010(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x104);
    return akDest;
}

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};
struct FUN_009b7940_shell
{
    int* vtable;
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    FUN_009b7940_shell* Initialize();
};
// Sets the vtable to DAT_0108f9e8, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x009b7940
FUN_009b7940_shell* FUN_009b7940_shell::Initialize()
{
    vtable = &DAT_0108f9e8;
    FUN_006b3eb0(0, 0);
    return this;
}

template <typename T, int N> struct BSSimpleArray
{
    void* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int uiPad;
    unsigned int Add(T&);
};
struct BGSBodyPart
{
};
struct WeightedResultList
{
    BSSimpleArray<void*, 1024> kResults;
    BSSimpleArray<void*, 1024> kWeights;
    int m_iTotalWeight;
    void AddWeightedBodyPart(BGSBodyPart* aResult, unsigned int aiWeight);
};
// @fnv 0x009b7990
void WeightedResultList::AddWeightedBodyPart(BGSBodyPart* aResult, unsigned int aiWeight)
{
    m_iTotalWeight += aiWeight;
    kWeights.Add((void*&)aiWeight);
    kResults.Add((void*&)aResult);
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_009ca4c0_shell
{
    void FreeStoredPointer();
};
// If the pointer at offset 0x14 is set, deallocates it and clears that field.
// @fnv 0x009ca4c0
void FUN_009ca4c0_shell::FreeStoredPointer()
{
    if (*(void**)((char*)this + 0x14))
    {
        void* p = *(void**)((char*)this + 0x14);
        Deallocate(p);
        *(void**)((char*)this + 0x14) = 0;
    }
}

struct BaseS
{
    char data[12];
    BaseS();
};
struct FUN_009b4d90
{
    char _pad[56];
    BaseS m1;
    BaseS m2;
    FUN_009b4d90();
};
// Constructs the object by calling FUN_009b4dc0 on this.
// @fnv 0x009b4d90
FUN_009b4d90::FUN_009b4d90()
{
    ((BooleanFloatQuery*)this)->FUN_009b4dc0();
}

struct HitDataEx : BooleanFloatQuery
{
    void FUN_009b4ec0(const BooleanFloatQuery& src);
};

// @fnv 0x009b4ec0
void HitDataEx::FUN_009b4ec0(const BooleanFloatQuery& src)
{
    m_pAggressor = src.m_pAggressor;
    pTarget = src.pTarget;
    m_pSourceReference = src.m_pSourceReference;
    m_uiHitLocation = src.m_uiHitLocation;
    m_uiHitFlags = src.m_uiHitFlags;
    m_fDamage = src.m_fDamage;
    m_fArmorDamage = src.m_fArmorDamage;
    m_fHealthDamage = src.m_fHealthDamage;
    m_fLimbDamage = src.m_fLimbDamage;
    m_fFatigueDamage = src.m_fFatigueDamage;
    m_fSneakAttackMultiplier = src.m_fSneakAttackMultiplier;
    m_fCriticalHitMultiplier = src.m_fCriticalHitMultiplier;
    vOffset1 = src.vOffset1;
    vOffset2 = src.vOffset2;
    pWeapon = src.pWeapon;
    m_fWeaponDamage = src.m_fWeaponDamage;
    m_pHitDataObjectAtOffset50 = src.m_pHitDataObjectAtOffset50;
    m_pHitDataObjectAtOffset54 = src.m_pHitDataObjectAtOffset54;
    uiFlags = src.uiFlags;
    m_fHitValueAtOffset5C = src.m_fHitValueAtOffset5C;
}

struct SpawnObj
{
    unsigned int unk00;
    unsigned char flag4;
};

struct SpawnLocal
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    SpawnLocal();
    void FUN_00407e00(unsigned int a, bool b);
};

void __cdecl SetContextInfo(SpawnLocal* ctx, SpawnObj* p);

// @fnv 0x009b4fe0
float __cdecl FUN_009b4fe0(SpawnObj* pSpawnObj)
{
    if (pSpawnObj == 0)
    {
        return 0.0f;
    }
    SpawnLocal L;
    L.FUN_00407e00(0x800, true);
    L.FUN_00407e00(0x1000, true);
    unsigned char saved = pSpawnObj->flag4;
    pSpawnObj->flag4 = 1;
    SetContextInfo(&L, pSpawnObj);
    pSpawnObj->flag4 = saved;
    return L.unk14;
}

struct SpawnedSub
{
    unsigned int unk00[4];
    SpawnedSub();
};

struct SpawnedBase
{
    SpawnedBase();
    ~SpawnedBase()
    {}
};

struct FUN_009b7870 : SpawnedBase
{
    unsigned int unk00[4];
    SpawnedSub m10;
    unsigned int m20;
    FUN_009b7870();
};

// Initializes the object by setting m20 to 0.
// @fnv 0x009b7870
FUN_009b7870::FUN_009b7870()
{
    m20 = 0;
}

class Actor;
void __cdecl ApplyPerkModifiers(int aeEntry, Actor* apActor, ...);
float __cdecl GetWeaponDPS(void* apOwner, void* apWeapon);
float& __fastcall FUN_00403e20(float* apSetting);
unsigned int __cdecl FUN_00487f50();
extern unsigned int DAT_011ca278;
extern int DAT_011ce46c;
extern int DAT_011ce858;
extern int DAT_011ce57c;
extern const double DAT_01012060;

struct FUN_009b7060_weapon
{
    unsigned short GetShortAtOffset1C0();
    bool GetByteAtOffset();
    unsigned int GetField1CC();
};

struct FUN_009b7060_actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual bool v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual bool v139(int aiFlag);
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
    virtual bool v216();
    bool FUN_004997b0();
    bool FUN_008bc700(Actor* apActor);
    bool FUN_0088b880(int a1, Actor* apActor, int a3, int a4, int a5);
    int FUN_008a0d10(int a1, Actor* apActor, char* apDetected, int a4, int a5, int a6, int a7);
};

struct FUN_009b7060_shell
{
    Actor* pSource;
    Actor* pTarget;
    char pad[0x14 - 0x08];
    float afDamageAmount;
    char padCur[0x30 - 0x18];
    FUN_009b7060_weapon* pWeapon;
    char kad[0x50 - 0x34];
    unsigned int uiValue;
    int iValue;
    bool FUN_0058cba0(int aeFlag);
    void FUN_00407e00(int aeFlag, bool abSet);
    void ApplyCriticalHit();
};

// @fnv 0x009b7060
void FUN_009b7060_shell::ApplyCriticalHit()
{
    if (pTarget && ((FUN_009b7060_actor*)((char*)pTarget + 0x94))->v004())
        return;
    if (FUN_0058cba0(0x800))
        return;

    float fLimbDamage4 = 0.0f;
    float fCritChance =
        GetWeaponDPS(pSource ? (char*)pSource + 0xa4 : 0, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278);
    ApplyPerkModifiers(1, pSource, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pTarget, &fCritChance);
    ApplyPerkModifiers(0x24, pTarget, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pSource, &fCritChance);
    if (iValue)
        fCritChance += FUN_00403e20((float*)&DAT_011ce46c);
    fCritChance *= 10.0;

    if (pSource && ((FUN_009b7060_actor*)pSource)->v216() && pTarget && ((FUN_009b7060_actor*)pTarget)->v064() &&
        !((FUN_009b7060_actor*)pTarget)->v139(0) && ((FUN_009b7060_actor*)pSource)->FUN_004997b0() &&
        !((FUN_009b7060_actor*)pTarget)->FUN_008bc700(pSource))
    {
        char cDetected = ((FUN_009b7060_actor*)pTarget)->FUN_0088b880(0, pSource, 1, 0, 0);
        int iDetection = ((FUN_009b7060_actor*)pTarget)->FUN_008a0d10(0, pSource, &cDetected, 0, 0, 0, 0);
        if (iDetection <= 0)
        {
            fCritChance *= FUN_00403e20((float*)&DAT_011ce858);
            FUN_00407e00(0x400, true);
        }
    }

    int iNewRoll = FUN_00487f50() % 1000;
    if (iNewRoll < (int)fCritChance)
    {
        FUN_00407e00(4, true);
        FUN_009b7060_weapon* pCritWeapon = pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278;
        if (pCritWeapon)
        {
            fLimbDamage4 =
                pWeapon ? (double)pWeapon->GetShortAtOffset1C0() : afDamageAmount * FUN_00403e20((float*)&DAT_011ce57c);
            ApplyPerkModifiers(2, pSource, pCritWeapon, pTarget, &fLimbDamage4);
            if (fLimbDamage4 > DAT_01012060)
                afDamageAmount += fLimbDamage4;
            FUN_00407e00(8, pCritWeapon->GetByteAtOffset());
            uiValue = pCritWeapon->GetField1CC();
        }
    }
}

namespace fnv_009b73d0 {
struct Item;
struct Process;
struct ActorBase;
struct Parts;
struct Part;
struct ValueInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float Value(int);
};
struct StateInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Test();
};
struct ActorCore
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
    virtual bool Ready();
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
    virtual bool IsPlayer();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    StateInterface state;
    int unk98;
    int unk9c;
    int unka0;
};
struct Actor : ActorCore, ValueInterface
{
    Process* ProcessNow();
    ActorBase* Base();
};
struct Process
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
    virtual Item* GetItem();
};
struct ActorBase
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
    virtual Parts* GetParts();
};
struct Item
{
    Parts* Flags();
    float Health(int);
};
struct Parts
{
    bool Special();
    Part* Find(int);
};
struct Part
{
    bool Valid();
    unsigned char Chance();
    bool Critical();
    signed char ValueIndex();
};
struct Command
{
    int unk00;
    int unk04;
    unsigned char count;
};
struct Weapon
{
    bool Check();
};
struct Setting
{
    float* Float();
};
extern Setting originalRuntimeFloatSetting748;
extern Setting g_011cf794;
extern Weapon* DAT_011ca278;
void Compute(ValueInterface*, Weapon*, int, int, int, bool, bool*, bool*);
struct Hit
{
    Actor* source;
    Actor* target;
    void* ref;
    int skill;
    int limb;
    float health;
    float total;
    float fatigue;
    float limbDamage;
    float blocked;
    float armor;
    float weaponDamage;
    Weapon* weapon;
    float weaponHealth;
    NiPoint3 offset1;
    NiPoint3 offset2;
    void* critical;
    Command* command;
    unsigned flags;
    float bonus;
    int refs;
    bool GetFlag(unsigned);
    void SetFlag(unsigned, bool);
    void ApplyDamageEffects();
};
// @fnv 0x009b73d0
void Hit::ApplyDamageEffects()
{
    if (!target || !target->Ready())
        return;
    if (target->state.Test())
        return;
    if (bonus > 0.0)
    {
        if (bonus >= 1.0 && GetFlag(0x400))
        {
            if (!weapon || weapon->Check())
                bonus *= *originalRuntimeFloatSetting748.Float();
            else
                bonus *= *g_011cf794.Float();
        }
        health *= bonus;
        if (source && !source->IsPlayer() && skill == 45)
            fatigue *= bonus;
        total *= bonus;
    }
    float count = 1.0f;
    if (command && command->count > 1)
        count = command->count;
    int current = 0;
    bool guaranteed = false;
    bool criticalFlagX = false;
    if (limb == 14)
    {
        Item* item_ = target->ProcessNow()->GetItem();
        Parts* flags_ = item_ ? item_->Flags() : 0;
        if (flags_)
        {
            float itemHealth4 = item_->Health(0);
            if (itemHealth4 - limbDamage <= 0.0)
            {
                if (target->IsPlayer() || flags_->Special())
                    SetFlag(0x200, true);
                else
                    SetFlag(0x100, true);
            }
        }
    }
    else if (limb != -1)
    {
        Parts* partsX = target->Base()->GetParts();
        if (partsX)
        {
            Part* part = partsX->Find(limb);
            if (part && part->Valid())
            {
                current = part->Chance();
                criticalFlagX = part->Critical();
                guaranteed = criticalFlagX && current >= 100;
                int index7 = part->ValueIndex();
                float valueVal = target->Value(index7);
                if (valueVal > 0.0 && valueVal - limbDamage <= 0.0)
                    SetFlag(0x80, true);
            }
        }
    }
    float chance9 = target->Value(16);
    if (chance9 - health * count <= 0.0)
    {
        SetFlag(0x10, true);
        if (limb != -1)
        {
            bool explodeTmp = false;
            bool dismember8 = guaranteed;
            if (!dismember8)
                Compute(static_cast<ValueInterface*>(target), weapon ? weapon : (skill == 45 ? DAT_011ca278 : 0),
                        current, 0, 0, criticalFlagX, &explodeTmp, &dismember8);
            if (explodeTmp)
                SetFlag(0x20, true);
            if (dismember8)
                SetFlag(0x40, true);
        }
    }
}
}  // namespace fnv_009b73d0

struct FUN_00438690
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~FUN_00438690();
};

struct Base_009b78e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Base_009b78e0();
};

struct FUN_009b78e0 : Base_009b78e0
{
    FUN_00438690 m10;
    int m20;
    ~FUN_009b78e0();
};

// @fnv 0x009b78e0
FUN_009b78e0::~FUN_009b78e0()
{}

namespace n9b {
struct Tgt
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual int v52();
};
struct Mgr
{
    Tgt* FUN_008d8520();
};
struct Info
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    char pad[7];
    Tgt* m_iThirdValue;
};
struct Ctx
{
    char pad[0x54];
    Info* m_54;
};
}
extern n9b::Mgr* DAT_011dea3c;
bool __cdecl FUN_0066de30(int v);
void __cdecl InitHitData(n9b::Ctx* ctx, n9b::Mgr* mgr, n9b::Tgt* t, int v, bool flag);
// @fnv 0x009b5050
void __cdecl SetContextInfo(n9b::Ctx* ctx, n9b::Info* info)
{
    if (!ctx || !info || !info->m_iThirdValue)
        return;
    ctx->m_54 = info;
    bool flag = FUN_0066de30(info->m_iWordAt00) && info->m_iWordAt04;
    InitHitData(ctx, DAT_011dea3c, info->m_iThirdValue->v40() ? info->m_iThirdValue : 0, DAT_011dea3c->FUN_008d8520()->v52(), flag);
}

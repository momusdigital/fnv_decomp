// fallout/ai/combat/grenadeprojectile.cpp: GrenadeProjectile, GPShell, ImpactProjectile (11 functions)

#include "grenadeprojectile_types.h"

// Returns true if the projectile's explosion detonates, or if it has an alt trigger and a positive explosion proximity.
// @fnv 0x009bdf80
bool GrenadeProjectile::IsProximityTriggered()
{
    return GetProjectileBase()->GetHasExplosionDetonates() ||
           (GetProjectileBase()->GetHasExplosionAltTrigger() && GetProjectileBase()->GetExplosionProximity() > 0.0);
}

struct S_004f15a0
{
    void FUN_004f15a0(int);
};
struct GP_Base0
{
    virtual ~GP_Base0();
    char pad04[0x14];
};
struct GP_Base1
{
    virtual void f();
};
struct FUN_009bbc70 : public GP_Base0, public GP_Base1
{
    FUN_009bbc70(bool);
    virtual ~FUN_009bbc70();
    char pad1c[0x150 - 0x1c];
};
class FUN_009b3fa0 : public FUN_009bbc70
{
  public:
    bool bFlag150;
    FUN_009b3fa0(bool abFlag);
    virtual ~FUN_009b3fa0();
};
// Constructs the object via the base constructor with abFlag, clears bFlag150, and calls FUN_004f15a0 with 0x3e.
// @fnv 0x009b3fa0
FUN_009b3fa0::FUN_009b3fa0(bool abFlag) : FUN_009bbc70(abFlag)
{
    bFlag150 = false;
    ((S_004f15a0*)this)->FUN_004f15a0(0x3e);
}

struct S4700
{
    bool TurnOff(int, bool);
    bool FUN_009b4700(int, bool);
    virtual void f0(), f1(), f2(), f3(), f4(), f5(), f6(), f7(), f8(), f9(), f10(), f11(), f12(), f13(), f14(), f15(),
        f16(), f17(), f18(), f19(), f20(), f21(), f22(), f23(), f24(), f25(), f26(), f27(), f28(), f29(), f30(), f31(),
        f32(), f33(), f34(), f35(), f36(), f37(), f38(), f39(), f40(), f41(), f42(), f43(), f44(), f45(), f46(), f47(),
        f48(), f49(), f50(), f51(), f52(), f53(), f54(), f55(), f56(), f57(), f58(), f59(), f60(), f61(), f62(), f63(),
        f64();
    virtual void f65(), f66(), f67(), f68(), f69(), f70(), f71(), f72(), f73(), f74(), f75(), f76(), f77(), f78(),
        f79(), f80(), f81(), f82(), f83(), f84(), f85(), f86(), f87(), f88(), f89(), f90(), f91(), f92(), f93(), f94(),
        f95(), f96(), f97(), f98(), f99(), f100(), f101(), f102(), f103(), f104(), f105(), f106(), f107(), f108(),
        f109(), f110(), f111(), f112(), f113(), f114(), f115(), f116(), f117(), f118(), f119(), f120(), f121(), f122(),
        f123(), f124(), f125(), f126(), f127(), f128(), f129();
    virtual void f130(), f131(), f132(), f133(), f134(), f135(), f136(), f137(), f138(), f139(), f140(), f141(), f142(),
        f143(), f144(), f145(), f146(), f147(), f148(), f149(), f150(), f151(), f152(), f153(), f154(), f155(), f156(),
        f157(), f158(), f159(), f160(), f161(), f162(), f163(), f164(), f165(), f166(), f167(), f168(), f169(), f170(),
        f171(), f172(), f173(), f174(), f175(), f176(), f177(), f178(), f179(), f180(), f181(), f182(), f183(), f184(),
        f185(), f186(), f187(), f188(), f189(), f190(), f191(), f192(), f193(), f194();
    virtual void At30C();
};
// Calls TurnOff with the given arguments, then invokes At30C, returning the result of the first call.
// @fnv 0x009b4700
bool S4700::FUN_009b4700(int aiArg, bool b)
{
    bool r = TurnOff(aiArg, b);
    At30C();
    return r;
}

struct NiAVObject;
struct Creature
{
    static void __cdecl SetNodeFlagsRecursive(NiAVObject*, int, bool, bool, bool);
};
extern double _gModifierZero;
struct FUN_009b4c70_shell : public Projectile
{
    void FUN_009b4c70();
};
// @fnv 0x009b4c70
void FUN_009b4c70_shell::FUN_009b4c70()
{
    if (GetProjectileBase()->GetHasExplosionDetonates() ||
        (GetProjectileBase()->GetHasExplosionAltTrigger() &&
         GetProjectileBase()->GetExplosionProximity() > _gModifierZero))
    {
        Creature::SetNodeFlagsRecursive(reinterpret_cast<NiAVObject*>(GetNiNode()), 5, true, false, true);
    }
}

struct BGSLoadFormBuffer;
struct C009c58e0
{
    void __thiscall FUN_009c58e0(BGSLoadFormBuffer*);
};
struct S009b4d10 : public FUN_009b3fa0
{
    void __thiscall FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009b4d10
void __thiscall S009b4d10::FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((C009c58e0*)this)->FUN_009c58e0(apLoadGameBuffer);
    bFlag150 = 0;
}

struct NiAVObject;

struct ObjHelper
{
    void* __thiscall FUN_00810660();
    TESForm* __thiscall FUN_00621a90();
};

extern TESObjectREFR* __cdecl GetReferenceFromNiAVObject(NiAVObject*);

struct FUN_009b4bf0_shell
{
    void DispatchReferenceSourceFiles(ObjHelper* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};

// If a1 is set and its object resolves, gets the reference and its source file list, then calls virtual slot 203 with them.
// @fnv 0x009b4bf0
void FUN_009b4bf0_shell::DispatchReferenceSourceFiles(ObjHelper* pObjHelper, void* a2, void* a3, void* a4, void* a5,
                                                      void* a6, void* a7)
{
    if (pObjHelper)
    {
        if (pObjHelper->FUN_00810660())
        {
            TESObjectREFR* pRef8;
            BSSimpleList<TESFile*>* m_kSourceFiles;
            int nCount2;
            pRef8 = GetReferenceFromNiAVObject((NiAVObject*)pObjHelper->FUN_00810660());
            m_kSourceFiles = pObjHelper->FUN_00621a90()->GetSourceFiles();
            nCount2 = -1;
            ((void(__thiscall*)(void*, TESObjectREFR*, void**, void**, BSSimpleList<TESFile*>*, int, int))(
                (*(void***)this)[203]))(this, pRef8, &a2, &a5, m_kSourceFiles, nCount2, 0x24);
        }
    }
}

struct S9b46c0
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
    virtual void* GetLight();
    bool FUN_00444d00(int);
    void FUN_005726e0(void*, bool);
    void SetLightEnabled();
};
// Enables or disables the light returned by GetLight based on whether flag 0x200 is set.
// @fnv 0x009b46c0
void S9b46c0::SetLightEnabled()
{
    FUN_005726e0(GetLight(), !FUN_00444d00(0x200));
}

struct Base0
{
    virtual void vf0();
    char pad0[0x14];
};

struct Base1
{
    virtual void vf1();
};

struct FUN_009bbef0 : public Base0, public Base1
{
    FUN_009bbef0(void*, void*, void*, NiPoint3, float, float);
    ~FUN_009bbef0();
    char pad[0x150 - 0x1c];
};

struct FUN_009b4020 : public FUN_009bbef0
{
    bool bFlag150;

    virtual void vf0();
    virtual void vf1();

    FUN_009b4020(void* a1, void* a2, void* a3, NiPoint3 a4, float a5, float a6);
};

// Constructs the base object, clears bFlag150, and calls FUN_004f15a0 with 0x3e.
// @fnv 0x009b4020
FUN_009b4020::FUN_009b4020(void* a1, void* a2, void* a3, NiPoint3 aPoint, float a5, float a6)
    : FUN_009bbef0(a1, a2, a3, aPoint, a5, a6)
{
    bFlag150 = false;
    ((S_004f15a0*)this)->FUN_004f15a0(0x3e);
}

struct hkpRigidBody;
struct hkVector4;
struct bhkCollisionObject
{
    static bhkCollisionObject* __cdecl GetFromRigidBody(const hkpRigidBody*);
};
struct ArrSI
{
    NiAVObject* GetFlags();
};
struct FUN_00624020_Class
{
    FUN_00624020_Class* GetLastNode();
};
struct GPCdBody
{
    void* _ref_006815c0();
};
void* __cdecl FUN_004b59f0(const void*);
NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, const hkVector4&);
struct NiColor
{
    NiColor& operator*=(float);
};
struct GPContact
{
    FUN_00624020_Class* pBodyA;
    FUN_00624020_Class* pBodyB;
    int pad08, pad0c;
    GPCdBody* pPoint;
    int pad14, pad18, pad1c;
    int iFlag;
};
struct GPRefVt
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void r116();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual void r125();
    virtual void r126();
    virtual void r127();
    virtual void r128();
    virtual void r129();
    virtual void r130();
    virtual void r131();
    virtual void r132();
    virtual void r133();
    virtual void r134();
    virtual void r135();
    virtual void r136();
    virtual bool Unk_89b();
};
struct GPShell
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
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
    virtual void v064();
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
    virtual void HandleHit(TESObjectREFR*, NiPoint3*, NiPoint3*, int, int, int);
    void HandleContactHit(GPContact* apContact);
};

// Resolves the reference behind each contact body, picks the hit target and position/normal, calls HandleHit, and flags the contact when both bodies are present.
// @fnv 0x009b4950
void GPShell::HandleContactHit(GPContact* apContact)
{
    void* pCollA2 = FUN_004b59f0(apContact->pBodyA->GetLastNode());
    bhkCollisionObject* pbhkA8 = pCollA2 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollA2) : 0;
    NiAVObject* pNiA2 = pbhkA8 ? ((ArrSI*)pbhkA8)->GetFlags() : 0;
    TESObjectREFR* pRefA_ = pNiA2 ? GetReferenceFromNiAVObject(pNiA2) : 0;
    void* pCollB3 = FUN_004b59f0(apContact->pBodyB->GetLastNode());
    bhkCollisionObject* pbhkB_ = pCollB3 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollB3) : 0;
    NiAVObject* pNiB = pbhkB_ ? ((ArrSI*)pbhkB_)->GetFlags() : 0;
    TESObjectREFR* pRefB = pNiB ? GetReferenceFromNiAVObject(pNiB) : 0;
    TESObjectREFR* kPTarget = 0;
    NiPoint3 kPos = NiPoint3::ZERO;
    NiPoint3 _kNormal = NiPoint3::ZERO;
    int iShapeKey = 0;
    int iBody5 = -1;
    if (pRefA_ && ((GPRefVt*)pRefA_)->Unk_89b())
    {
        kPTarget = pRefB;
        SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)apContact->pPoint->_ref_006815c0());
        SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        ((NiColor*)&_kNormal)->operator*=(-1.0f);
        iShapeKey = (int)apContact->pBodyB->GetLastNode();
        iBody5 = (int)((BSSimpleList<TESFile*>*)apContact->pBodyB)->GetNext();
    }
    else if (pRefB && ((GPRefVt*)pRefB)->Unk_89b())
    {
        kPTarget = pRefA_;
        SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        iShapeKey = (int)apContact->pBodyA->GetLastNode();
        iBody5 = (int)((BSSimpleList<TESFile*>*)apContact->pBodyA)->GetNext();
    }
    HandleHit(kPTarget, &kPos, &_kNormal, iShapeKey, iBody5, 0x24);
    if (kPTarget && kPTarget->IsActor() && pCollA2 && pCollB3)
        apContact->iFlag = 1;
}

struct FUN_009b40d0_owner
{
    bool CheckA();
    bool CheckB();
    bool CheckC();
};

class FUN_009b40d0_cls : public Projectile
{
  public:
    void InitProjectileFlags();
    void SetProjFlag(unsigned int flag, bool on);
    bool TestFlag400(unsigned int flag);
    FUN_009b40d0_owner* GetOwnerCell();
    void FinishSetup();
};

// Sets projectile flags based on the 0x400 test and owner cell checks, then calls FinishSetup.
// @fnv 0x009b40d0
void FUN_009b40d0_cls::InitProjectileFlags()
{
    SetProjFlag(4, true);
    if (TestFlag400(0x400))
    {
        SetProjFlag(2, true);
        SetProjFlag(0x100, false);
    }
    else
    {
        SetProjFlag(0x100, true);
    }

    SetProjFlag(0x2000,
                (GetOwnerCell()->CheckA() && !GetOwnerCell()->CheckB() && !GetOwnerCell()->CheckC()) ? true : false);
    SetProjFlag(0x8000, true);
    SetProjFlag(0x40000, true);
    FinishSetup();
}

struct Vec3
{
    float x, y, z;
};

struct Ref
{

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

    virtual bool IsActor();

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

    virtual void ApplyTime(float, int);

    virtual void slot82();

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void ApplyValue(int);

    virtual int GetValue();

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

    virtual bool CheckFlag(int);

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

    virtual void slot186();

    virtual void slot187();

    virtual void slot188();

    virtual void slot189();

    virtual void slot190();

    virtual void slot191();

    virtual void slot192();

    virtual void slot193();

    virtual void slot194();

    virtual void slot195();

    virtual void slot196();

    virtual void slot197();

    virtual void slot198();

    virtual void slot199();

    virtual void slot200();

    virtual void slot201();

    virtual void slot202();

    virtual void slot203();

    virtual void slot204();

    virtual void slot205();

    virtual void slot206();

    virtual void slot207();

    virtual void slot208();

    virtual void slot209();

    virtual void slot210();

    virtual void slot211();

    virtual void slot212();

    virtual void slot213();

    virtual void slot214();

    virtual void slot215();

    virtual bool IsValidTarget();

    int FUN_0043fcd0();

    bool FUN_00437b90();

    bool FUN_00477ba0();

    unsigned int FUN_0044ddc0();

    unsigned short GetShortAtOffset1C0();

    int FUN_00517630();

    int SetEffectValue(int, float, int);

    void FUN_0089a760(void*, int);
};

struct Hit
{

    Ref* reference;

    Vec3 position;

    Vec3 normal;

    int itemID;

    int unk20;

    int unk24;

    bool valid28;

    bool valid29;
};

struct HitList
{

    Hit* data;

    HitList* next;

    bool FUN_008256d0();

    Hit** FUN_006815c0();

    HitList* FUN_00726070();
};

struct ContactHelper
{
    void* reference;

    ContactHelper(void*);

    ~ContactHelper();

    Ref* FUN_00559450();
};

struct LoadedProjectile
{
    int unk00;
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

    LoadedProjectile();

    ~LoadedProjectile();
};

struct Resource
{

    int FUN_0043fcd0();

    int FUN_00517630();
};

struct EventStatus
{

    bool GetHasExplosion();

    bool FUN_00975300();

    bool FUN_005de080();
};

extern Ref* DAT_011dea3c;

extern Ref* DAT_011f21e8;

extern Ref* DAT_011f21ec;

extern float DAT_0102918c;

extern double DAT_01012060;

struct TargetSettings
{
    bool FUN_00525430();
};
extern TargetSettings DAT_011f2250;

extern void __cdecl PlayMysteriousStrangerSound();

extern Ref* __cdecl FUN_004b5a80(int);

struct FormID
{
    Ref* FUN_00460140();
};

extern LoadedProjectile* __cdecl FUN_009b4d90();

extern void __cdecl InitFromObjects(Ref*, int, Ref*, int, Ref*);

struct ImpactProjectile : Ref
{

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int unk030;

    int unk034;

    int unk038;

    int unk03c;

    int unk040;

    int unk044;

    int unk048;

    int unk04c;

    int unk050;

    int unk054;

    int unk058;

    int unk05c;

    int unk060;

    int unk064;

    int unk068;

    int unk06c;

    int unk070;

    int unk074;

    int unk078;

    int unk07c;

    int unk080;

    int unk084;

    HitList list88;

    bool impacted90;

    bool ProcessHits();

    float GetFieldDC();

    Ref* FUN_00874480();

    Ref* FUN_00476c90();

    EventStatus* FUN_004181e0();

    void NotifyActorIfEligible(Ref*, int);

    void ApplyImpact(Ref*, const Vec3*, const Vec3*, Ref*, int);

    Vec3 FUN_009b7010(Ref*);

    void FUN_009c2e80(Vec3, Vec3);
};

// Iterates the hit list, applies impact effects to each hit's target, and marks the projectile as impacted.
// @fnv 0x009c1b70
bool ImpactProjectile::ProcessHits()
{

    bool processed = false;

    bool inverse = false;

    if (!impacted90 && !list88.FUN_008256d0())
    {

        HitList* node = &list88;

        while (node && !node->FUN_008256d0())
        {

            Hit* hit = *node->FUN_006815c0();

            node = node->FUN_00726070();

            bool aChanged = false;

            Ref* aTarget = hit->reference;

            if (aTarget && GetFieldDC() > DAT_01012060 && hit->valid29)
            {

                int oldState = hit->reference->FUN_0043fcd0();

                if (FUN_00874480() && FUN_00874480()->IsActor() &&

                    aTarget->IsActor() && !FUN_00874480()->FUN_00437b90())
                {

                    inverse = !aTarget->CheckFlag(0);

                    NotifyActorIfEligible(aTarget, 0);
                }
                else
                {

                    Ref* form = FUN_004b5a80(hit->itemID);

                    if (form && form->FUN_00517630() < 4)

                        aTarget->ApplyValue(GetValue());

                    Ref* attacker = (FUN_00874480() && FUN_00874480()->IsActor()) ? FUN_00874480() : 0;

                    float jump = 0.0f;

                    if (attacker && attacker->IsValidTarget() && DAT_011f2250.FUN_00525430() && FUN_00476c90())

                        jump = (float)FUN_00476c90()->GetShortAtOffset1C0();

                    float delay = GetFieldDC() + jump;

                    if (aTarget->IsActor())
                    {

                        Ref* actor = aTarget;
                        ContactHelper helper(new LoadedProjectile());

                        InitFromObjects(helper.FUN_00559450(), 0, actor, 0, this);

                        inverse = !actor->CheckFlag(0);

                        actor->FUN_0089a760(helper.FUN_00559450(), 0);
                    }
                    else
                    {

                        hit->reference->ApplyTime(delay, 0);
                    }

                    if (aTarget->FUN_00477ba0() && FUN_00874480() == DAT_011dea3c)

                        DAT_011dea3c->SetEffectValue(10, DAT_0102918c, 0);
                }

                if (oldState != aTarget->FUN_0043fcd0())
                    aChanged = true;
            }

            if (!aTarget || !(aTarget->FUN_0044ddc0() & 0x20))
            {

                if (!FUN_004181e0()->GetHasExplosion() || FUN_004181e0()->FUN_00975300() || FUN_004181e0()->FUN_005de080())
                {

                    if (!aChanged)
                    {

                        if (DAT_011f21e8 && DAT_011f21e8 == FUN_00874480() && aTarget && aTarget->IsActor())

                            PlayMysteriousStrangerSound();

                        if (DAT_011f21ec && DAT_011f21ec == FUN_00874480() && aTarget && aTarget->IsActor() &&
                            aTarget->CheckFlag(0) && inverse)

                            PlayMysteriousStrangerSound();

                        Ref* form = hit->itemID ? ((FormID*)hit->itemID)->FUN_00460140() : 0;

                        ApplyImpact(aTarget, &hit->position, &hit->normal, form, hit->unk20);

                        FUN_009c2e80(hit->position, FUN_009b7010(form));
                    }
                }
            }

            processed = true;

            if (FUN_00437b90())

                break;
        }

        impacted90 = true;
    }

    return processed;
}

// fallout/ai/combat/combatmanager.cpp: CombatFlagHolder, CombatBox, CombatManager, CombatNodeArray and more (37 functions)

#include "combatmanager_decls.h"

// @fnv 0x00993790
void CombatManager::ApplyLoadBuffer(BGSLoadGameBuffer* buffer)
{
    for (unsigned int i = 0; i < m_kCombatGroups.GetSize(); i++)
    {
        ActorCombatGroup* group = m_kCombatGroups.GetAt(i);
        if (group)
            group->RemoveActorsNotInGroup(buffer);
    }
    m_pThreatMap->ProcessAllProjectiles(buffer);
}

void* __cdecl operator new(unsigned int);

namespace N {
class CombatThreatMap
{
  public:
    CombatThreatMap();
    char pad[0x3c];
};
}

extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

void __cdecl InitCombatActions();
void __cdecl InitCombatGoalTable();
void __cdecl FUN_00990070();
void __cdecl NegateCharacterControllerValue();
void __cdecl EnsureGlobalAllocated();

// @fnv 0x00990f20
void __cdecl FUN_00990f20()
{
    if (BGSSaveLoadGlobalDataWorldspacePtr)
        return;

    AutoMemContext context(static_cast<MEM_CONTEXT>(0x2b), true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp", 0x43);
    BGSSaveLoadGlobalDataWorldspacePtr = reinterpret_cast<TESWorldSpace*>(new N::CombatThreatMap());
    InitCombatActions();
    InitCombatGoalTable();
    FUN_00990070();
    NegateCharacterControllerValue();
    EnsureGlobalAllocated();
}

struct FUN_00991dc0_shell : public CombatManager
{
    void FUN_00991dc0();
};

struct GlobalObject_004aff00
{
    unsigned int GetSize();
};
struct Arr
{
    unsigned int* GetAt(int);
};
typedef void(__thiscall* ActorVFn)(Actor*);
// Iterates every group, calls a virtual function on each member actor, and re-reads the member count when it changes.
// @fnv 0x00991dc0
void FUN_00991dc0_shell::FUN_00991dc0()
{
    for (unsigned int i = 0; i < ((GlobalObject_004aff00*)this)->GetSize(); i++)
    {
        ActorCombatGroup* pgroup = (ActorCombatGroup*)*((Arr*)this)->GetAt(i);
        if (pgroup)
        {
            unsigned int imemberCount = pgroup->GetCount();
            for (unsigned int j = 0; j < imemberCount; j++)
            {
                Actor* pactor = pgroup->GetIntAt(j);
                (*(ActorVFn**)pactor)[0x430 / 4](pactor);
                unsigned int inewMemberCount = pgroup->GetCount();
                if (inewMemberCount != imemberCount)
                {
                    imemberCount = inewMemberCount;
                    j--;
                }
            }
        }
    }
}

namespace fnv_00991770 {
struct ActiveEffect;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatAction;
struct CombatGoal;
struct CombatPlan;
struct CombatBehavior;
struct CombatProcedure;
struct CombatState;
struct IDebugText;
struct InventoryStackRecord;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct Projectile;
struct Script;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESFile;
struct TESIdleForm;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct FUN_00991770_shell : public CombatManager
{
    void UpdateDetectionVisuals();
};

class NiObject;
class NiAVObject;
class NiNode;

struct GlobalObject_004aff00
{
    unsigned int GetSize();
};

struct Arr
{
    unsigned int* GetAt(int);
};

struct CombatGroupStandIn
{
    void RebuildDebugVisuals(int);
};

struct Flt
{
    operator unsigned int() const;
};

struct Calendar
{
    unsigned int GetDaysPassed();
};

struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*);
};

struct NiUpdateData
{
    int a, b, c;
    NiUpdateData(float, bool, bool);
};

class NiAVObject : public BSFadeNode
{
  public:
    void FUN_00440460(NiPoint3 const&);
    void AttachProperty(NiObject*);
    void UpdateSceneObject();
};

class NiNode : public NiAVObject
{
  public:
    int pad[0x2b];
    NiNode(unsigned short);
    void Update(NiUpdateData const&);
};

struct NiAlphaProperty : public BSFadeNode
{
    int pad[7];
    NiAlphaProperty();
    void FUN_0049ed90(bool);
};

struct TeleportableReference
{
    NiPoint3 const& GetPosition();
};

struct MobileObjectProcessArray
{
    MobileObject* GetItem(unsigned int) const;
};

struct TopicInfoArray
{
    unsigned int FUN_005be5c0(int);
};

struct DetectionEvent
{
    int soundLevel;
    NiPoint3 pos;
};

struct TES
{
    void* GetLogDate();
};

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};

struct BSShaderManager
{
    static void __cdecl UpdateObjectTypeRecurse(NiAVObject*, bool, bool);
};

NiAVObject* __fastcall FUN_00524cf0(TESObjectCELL*);
NiAVObject* __cdecl FUN_00c56680(float, int, int, RgbaColor const&);
NiAVObject* __cdecl FUN_00c5a0f0(NiPoint3 const&, NiPoint3 const&, float, float, RgbaColor const&, RgbaColor const&);
void __cdecl AttachLightingPropertyRecursive(unsigned int);

struct VtblStandIn
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
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);  // slot 55 (+0xDC)
    virtual void v056();
    virtual void v057();
    virtual void InsertChild(unsigned int);  // slot 58 (+0xE8)
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual DetectionEvent* GetDetectionEvent(Actor*);  // slot 62 (+0xF8)
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
    virtual void v225();
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
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual TESForm* GetCombatController();  // slot 266 (+0x428)
};

extern float const g_011d86e0_arg1;
extern float _DAT_010162c0;
extern float DAT_0108aff0;
extern float DAT_0108da38;
extern TeleportableReference DAT_011e0e80;
extern ProcessLists g_011f197c;

// @fnv 0x00991770
void FUN_00991770_shell::UpdateDetectionVisuals()
{
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x14))->TESForm::ClearData();
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x18))->TESForm::ClearData();
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1c))->TESForm::ClearData();
    for (unsigned int i = 0; i < reinterpret_cast<GlobalObject_004aff00*>(this)->GetSize(); ++i)
    {
        ActorCombatGroup* pgroup = reinterpret_cast<ActorCombatGroup*>(*reinterpret_cast<Arr*>(this)->GetAt(i));
        if (pgroup)
        {
            reinterpret_cast<CombatGroupStandIn*>(pgroup)->RebuildDebugVisuals(0);
            unsigned int imemberCount = pgroup->GetCount();
            for (unsigned int j = 0; j < imemberCount; ++j)
            {
                Actor* pactor = pgroup->GetIntAt(j);
                if (pactor)
                {
                    TESForm* pcombatController = reinterpret_cast<VtblStandIn*>(pactor)->GetCombatController();
                    if (pcombatController)
                    {
                        pcombatController->TESForm::Revert(0);
                    }
                }
            }
        }
    }
    if (*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38) &&
        reinterpret_cast<Calendar*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->GetDaysPassed())
    {
        reinterpret_cast<VtblStandIn*>(reinterpret_cast<Calendar*>(static_cast<unsigned int>(*reinterpret_cast<Flt*>(
                                                                       reinterpret_cast<char*>(this) + 0x38)))
                                           ->GetDaysPassed())
            ->InsertChild(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38));
    }
    *reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x38) = 0;
    if (!reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell() ||
        !FUN_00524cf0(reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell()))
    {
        return;
    }
    if (*g_011f197c.GetLifeStateControlFlag())
    {
        if (!*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))
        {
            *reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x38) = new NiNode(0);
        }
        unsigned int iHighActorCount =
            reinterpret_cast<TopicInfoArray*>(const_cast<NiPoint3*>(&DAT_011e0e80.GetPosition()))->FUN_005be5c0(0);
        for (unsigned int i = 0; i < iHighActorCount + 1; ++i)
        {
            MobileObject* pMobileObject =
                (i == iHighActorCount)
                    ? reinterpret_cast<MobileObject*>(g_thePlayer)
                    : reinterpret_cast<const MobileObjectProcessArray*>(&DAT_011e0e80.GetPosition())->GetItem(i);
            if (pMobileObject && reinterpret_cast<TESForm*>(pMobileObject)->IsActor())
            {
                Actor* pactor = reinterpret_cast<Actor*>(pMobileObject);
                DetectionEvent* pdetectionEvent =
                    reinterpret_cast<VtblStandIn*>(reinterpret_cast<TES*>(pactor)->GetLogDate())
                        ->GetDetectionEvent(pactor);
                if (pdetectionEvent)
                {
                    RgbaColor arrowColor(0.0f, 0.25f, 0.25f, 0.5f);
                    RgbaColor sphereColor(0.0f, g_011d86e0_arg1, g_011d86e0_arg1, 0.5f);
                    RgbaColor color(1.0f, DAT_0108da38, DAT_0108aff0, 0.5f);
                    float fradius = pdetectionEvent->soundLevel + 32.0;
                    NiAVObject* psphere = FUN_00c56680(fradius, 10, 10, sphereColor);
                    psphere->FUN_00440460(pdetectionEvent->pos);
                    reinterpret_cast<VtblStandIn*>(
                        static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
                        ->AttachChildInAvailableSlot(psphere, true);
                    NiPoint3 actorPos = *reinterpret_cast<TESObjectREFR*>(pactor)->GetPos();
                    NiAVObject* parrow = FUN_00c5a0f0(actorPos, pdetectionEvent->pos, _DAT_010162c0, _DAT_010162c0,
                                                      arrowColor, sphereColor);
                    reinterpret_cast<VtblStandIn*>(
                        static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
                        ->AttachChildInAvailableSlot(parrow, true);
                }
            }
        }
    }
    if (*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))
    {
        NiAlphaProperty* pAlphaProperty = new NiAlphaProperty();
        pAlphaProperty->FUN_0049ed90(true);
        reinterpret_cast<NiAVObject*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->AttachProperty(reinterpret_cast<NiObject*>(pAlphaProperty));
        AttachLightingPropertyRecursive(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38));
        BSShaderManager::UpdateObjectTypeRecurse(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(
                                                     *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))),
                                                 false, false);
        reinterpret_cast<VtblStandIn*>(FUN_00524cf0(reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell()))
            ->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(
                                             *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))),
                                         true);
        reinterpret_cast<NiAVObject*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->UpdateSceneObject();
        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->Update(UpdateData);
    }
}
}  // namespace fnv_00991770

namespace fnv_00992d90 {
struct ActiveEffect;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatAction;
struct CombatGoal;
struct CombatPlan;
struct CombatBehavior;
struct CombatProcedure;
struct CombatState;
struct IDebugText;
struct InventoryStackRecord;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct Projectile;
struct Script;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESFile;
struct TESIdleForm;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct FUN_00992d90_shell : public CombatManager
{
    bool UpdateCombatMusic();
};

class Tile;

struct RegionPoint
{
    float GetX();
};

struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};

struct Animation
{
    float FUN_00453700();
};

struct IMH
{
    Tile* FUN_00586150();
};

struct PathingSolution
{
    unsigned int GetVirtualNodeCount();
};

struct GlobalObject_004aff00
{
    unsigned int GetSize();
};

struct Arr
{
    unsigned int* GetAt(int);
};

struct CombatTimerStandIn
{
    void FUN_008d7f40(float);
    bool FUN_008d7f80();
    void FUN_00910b10();
    bool FUN_0097fa50();
};

struct ActorStandIn
{
    float GetModifiedDamagePerSecond(float);
    bool FUN_009670f0(Actor*);
};

struct CombatGroupStandIn
{
    bool FUN_0097ef30();
    bool FUN_0098a2e0();
    void GetCombatTargetTimestamp(CombatTargetTimestamp*, Actor*);
    bool FUN_009931a0();
    int FUN_00989880(Actor*, float);
    float GetModifierSum(int);
};

struct FUN_00435de0_ctor
{
    float fTimeStamp;
    void* FUN_00435de0(float);
};

float __cdecl FUN_00435dd0();

struct ActorVtblStandIn
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
    virtual void v225();
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
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual IMH* GetCombatController();
};

extern double _gModifierZero;
extern float DAT_0108d9b0;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting486;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting485;
extern SettingT_GameSettingCollection_ g_011ce72c;
extern SettingT_GameSettingCollection_ g_011ceec0;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting483;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting484;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// Checks combat groups against the player to decide whether combat music should play, updating the music timer and timestamp fields accordingly.
// @fnv 0x00992d90
bool FUN_00992d90_shell::UpdateCombatMusic()
{
    bool bplayingMusic =
        (reinterpret_cast<RegionPoint*>(reinterpret_cast<char*>(this) + 0x20)->GetX() != -DAT_0108d9b0) ? true : false;
    if (!reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x2c)->FUN_008d7f80() ||
        g_BGSSaveLoadGame->FUN_0042ce10())
    {
        return bplayingMusic;
    }
    reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x2c)
        ->FUN_008d7f40(*reinterpret_cast<float*>(g_011ceec0.Float()));
    bool bplayCombatMusic = false;
    float fnearbyGroupCombatStrength = 0.0f;
    bool bnearbyGroupDetected = false;
    float fplayerCombatStrength = reinterpret_cast<ActorStandIn*>(g_thePlayer)->GetModifiedDamagePerSecond(-1.0f);
    for (unsigned int i = 0; i < reinterpret_cast<GlobalObject_004aff00*>(this)->GetSize(); ++i)
    {
        ActorCombatGroup* pgroup = reinterpret_cast<ActorCombatGroup*>(*reinterpret_cast<Arr*>(this)->GetAt(i));
        if (pgroup)
        {
            if (reinterpret_cast<CombatGroupStandIn*>(pgroup)->FUN_0097ef30() ||
                !reinterpret_cast<PathingSolution*>(pgroup)->GetVirtualNodeCount() ||
                reinterpret_cast<CombatGroupStandIn*>(pgroup)->FUN_0098a2e0())
            {
                continue;
            }
            if (pgroup->ContainsActor(reinterpret_cast<Actor*>(g_thePlayer)))
            {
                CombatTargetTimestamp flastDetectedTimeSTamp;
                reinterpret_cast<CombatGroupStandIn*>(pgroup)->GetCombatTargetTimestamp(
                    &flastDetectedTimeSTamp, reinterpret_cast<Actor*>(g_thePlayer));
                if (flastDetectedTimeSTamp.GetElapsedTime() <
                    *reinterpret_cast<float*>(originalRuntimeFloatSetting413.Float()))
                {
                    if (bplayingMusic)
                    {
                        bplayCombatMusic = true;
                    }
                    else
                    {
                        float fgroupCombatStrength = 0.0f;
                        unsigned int imemberCount = pgroup->GetCount();
                        for (unsigned int i = 0; i < imemberCount; ++i)
                        {
                            Actor* pmember = pgroup->GetIntAt(i);
                            if (reinterpret_cast<ActorStandIn*>(g_thePlayer)->FUN_009670f0(pmember))
                            {
                                IMH* pcombatController =
                                    reinterpret_cast<ActorVtblStandIn*>(pmember)->GetCombatController();
                                if (pcombatController)
                                {
                                    fgroupCombatStrength +=
                                        reinterpret_cast<Animation*>(pcombatController->FUN_00586150())->FUN_00453700();
                                }
                            }
                        }
                        if (fgroupCombatStrength > _gModifierZero)
                        {
                            float fthreatRatio = fplayerCombatStrength / fgroupCombatStrength;
                            if (fthreatRatio < *reinterpret_cast<float*>(originalRuntimeFloatSetting486.Float()))
                            {
                                bplayCombatMusic = true;
                            }
                        }
                    }
                }
            }
            else if (reinterpret_cast<CombatGroupStandIn*>(pgroup)->FUN_009931a0())
            {
                if (bplayingMusic)
                {
                    if (reinterpret_cast<CombatGroupStandIn*>(pgroup)->FUN_00989880(
                            reinterpret_cast<Actor*>(g_thePlayer),
                            *reinterpret_cast<float*>(originalRuntimeFloatSetting485.Float())))
                    {
                        bplayCombatMusic = true;
                    }
                }
                else
                {
                    if (reinterpret_cast<CombatGroupStandIn*>(pgroup)->FUN_00989880(
                            reinterpret_cast<Actor*>(g_thePlayer),
                            *reinterpret_cast<float*>(originalRuntimeFloatSetting484.Float())))
                    {
                        if (!bnearbyGroupDetected)
                        {
                            unsigned int imemberCount = pgroup->GetCount();
                            for (unsigned int i = 0; i < imemberCount; ++i)
                            {
                                Actor* pmember = pgroup->GetIntAt(i);
                                if (reinterpret_cast<ActorStandIn*>(g_thePlayer)->FUN_009670f0(pmember))
                                {
                                    bnearbyGroupDetected = true;
                                    break;
                                }
                            }
                        }
                        fnearbyGroupCombatStrength += reinterpret_cast<CombatGroupStandIn*>(pgroup)->GetModifierSum(0);
                        if (bnearbyGroupDetected &&
                            fplayerCombatStrength * *reinterpret_cast<float*>(g_011ce72c.Float()) <
                                fnearbyGroupCombatStrength)
                        {
                            bplayCombatMusic = true;
                        }
                    }
                }
            }
        }
        if (bplayCombatMusic)
        {
            break;
        }
    }
    if (bplayingMusic != bplayCombatMusic)
    {
        if (bplayCombatMusic)
        {
            reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00910b10();
            FUN_00435de0_ctor ts1;
            ts1.FUN_00435de0(FUN_00435dd0());
            *reinterpret_cast<FUN_00435de0_ctor*>(reinterpret_cast<char*>(this) + 0x20) = ts1;
        }
        else if (!reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x24)->FUN_0097fa50())
        {
            reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x24)
                ->FUN_008d7f40(*reinterpret_cast<float*>(originalRuntimeFloatSetting483.Float()));
        }
        else if (reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x24)->FUN_008d7f80())
        {
            FUN_00435de0_ctor ts2;
            ts2.FUN_00435de0(-DAT_0108d9b0);
            *reinterpret_cast<FUN_00435de0_ctor*>(reinterpret_cast<char*>(this) + 0x20) = ts2;
            reinterpret_cast<CombatTimerStandIn*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00910b10();
        }
    }
    return reinterpret_cast<RegionPoint*>(reinterpret_cast<char*>(this) + 0x20)->GetX() != -DAT_0108d9b0;
}
}  // namespace fnv_00992d90

struct CombatNode
{
    unsigned int FUN_00726070();
};
struct CombatNodeArray
{
    unsigned int GetSize();
    CombatNode** GetAt(unsigned int index);
    CombatNode* FindByKey(unsigned int key);
};
// Scans the array and returns the first node whose FUN_00726070() equals key, or null if none matches.
// @fnv 0x00991d60
CombatNode* CombatNodeArray::FindByKey(unsigned int key)
{
    for (unsigned int i = 0; i < GetSize(); ++i)
    {
        CombatNode* node = *GetAt(i);
        if (node && node->FUN_00726070() == key)
            return node;
    }
    return 0;
}

struct FUN_005a4320_shell
{
    unsigned int FUN_005a4320();
    Actor* FUN_00968630(unsigned int auiIndex);
};

struct ActorShell
{
    bool GetShouldHelp(Actor* apActor);
    bool IsHostileToActor(Actor* apTarget, int aiArg, int* apResult, bool abArg);
};

struct FUN_00992530_shell : public CombatManager
{
    bool FUN_00992530(Actor* apActor, Actor* apTarget);
};

// @fnv 0x00992530
bool FUN_00992530_shell::FUN_00992530(Actor* apActor, Actor* apTarget)
{
    unsigned int kIresult = 0;
    if (!((ActorShell*)apActor)->GetShouldHelp(apTarget))
        return false;
    if (apActor && apTarget)
    {
        ActorCombatGroup* pgroup2 = apTarget->GetCombatGroup();
        if (pgroup2)
        {
            unsigned int ihelperCount4 = ((FUN_005a4320_shell*)pgroup2)->FUN_005a4320();
            unsigned int imemberCount5;
            for (unsigned int i5 = 0; i5 < ihelperCount4; i5++)
            {
                Actor* phelper2 = ((FUN_005a4320_shell*)pgroup2)->FUN_00968630(i5);
                if (((ActorShell*)apActor)->GetShouldHelp(phelper2))
                    return false;
            }
            imemberCount5 = pgroup2->GetCount();
            for (unsigned int j2 = 0; j2 < imemberCount5; j2++)
            {
                Actor* pmember = pgroup2->GetIntAt(j2);
                int iattack = 0;
                if (((ActorShell*)apActor)->IsHostileToActor(pmember, 0, &iattack, false))
                    return false;
            }
        }
    }
    return true;
}

struct CombatBox
{
    void FUN_00992a50(unsigned int a, unsigned int b);
    void FUN_009926c0(unsigned int a, unsigned int b);
};
// @fnv 0x009926c0
void CombatBox::FUN_009926c0(unsigned int uiFirst, unsigned int uiSecond)
{
    FUN_00992a50(uiSecond, uiFirst);
}

namespace fnv_009926e0 {
struct CombatBox
{
    void ClearFlagIfSet(unsigned int a, unsigned int b);
    void SwapAndDispatch(unsigned int a, unsigned int b);
};
// @fnv 0x009926e0
void CombatBox::SwapAndDispatch(unsigned int uiFirst, unsigned int uiSecond)
{
    ClearFlagIfSet(uiSecond, uiFirst);
}
}  // namespace fnv_009926e0

namespace fnv_00992700 {
struct CombatBox
{
    void FUN_009929e0(unsigned int a);
    void FUN_00992700(unsigned int a, unsigned int b);
};
// @fnv 0x00992700
void CombatBox::FUN_00992700(unsigned int uiUnused, unsigned int uiValue)
{
    FUN_009929e0(uiValue);
}
}  // namespace fnv_00992700

struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool FUN_009928a0();
};
// @fnv 0x009928a0
bool CombatFlagHolder::FUN_009928a0()
{
    return HasCombatFlag(0x20);
}

namespace fnv_009928c0 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
};
// @fnv 0x009928c0
bool CombatFlagHolder::HasCombatFlag(unsigned int mask)
{
    return (*(unsigned int*)((char*)this + 0xa8) & mask) ? true : false;
}
}  // namespace fnv_009928c0

namespace fnv_009928e0 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool HasCombatFlag40();
};
// @fnv 0x009928e0
bool CombatFlagHolder::HasCombatFlag40()
{
    return HasCombatFlag(0x40);
}
}  // namespace fnv_009928e0

namespace fnv_00992900 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool HasCombatFlag80();
};
// @fnv 0x00992900
bool CombatFlagHolder::HasCombatFlag80()
{
    return HasCombatFlag(0x80);
}
}  // namespace fnv_00992900

struct CombatPair
{
    unsigned int a;
    unsigned int b;
};
struct CombatTarget
{
    bool Lookup(unsigned int key, CombatPair* out);
    void SetValue(unsigned int key, unsigned int x, unsigned int y);
};
struct CombatOwner
{
    void FUN_009929e0(unsigned int key);
};
// @fnv 0x009929e0
void CombatOwner::FUN_009929e0(unsigned int key)
{
    CombatPair pair = {0, 0};
    if (!(*(CombatTarget**)((char*)this + 0x10))->Lookup(key, &pair))
        (*(CombatTarget**)((char*)this + 0x10))->SetValue(key, 0, 0);
}

struct MapH
{
    bool RemoveAt(unsigned int key);
};
struct CombatMapOwner
{
    void FUN_00992a30(unsigned int key);
};
// @fnv 0x00992a30
void CombatMapOwner::FUN_00992a30(unsigned int key)
{
    (*(MapH**)((char*)this + 0x10))->RemoveAt(key);
}

struct Flt
{
    operator unsigned int() const;
};
struct CPHelper00992a50
{
    bool Lookup(Actor* a, unsigned __int64* out);
    void SetValue(Actor* a, unsigned __int64 v);
};
struct CPStandIn00992a50
{
    int f0, f4, f8, fc;
    CPHelper00992a50* pHelper;
    void FUN_00992a50(Actor* pactor, Flt& flt);
};

// Reads a bit mask for pactor, sets the bit given by flt if clear, and writes the mask back.
// @fnv 0x00992a50
void CPStandIn00992a50::FUN_00992a50(Actor* pactor, Flt& aiBitIndex)
{
    __int64 ullBit;
    unsigned __int64 ullMask = 0;
    if (!pHelper->Lookup(pactor, &ullMask))
        ullMask = 0;
    ullBit = 1 << (unsigned int)aiBitIndex;
    if ((ullMask & ullBit) == 0)
    {
        ullMask |= ullBit;
        pHelper->SetValue(pactor, ullMask);
    }
}

namespace fnv_00992b00 {
struct Flt
{
    operator unsigned int() const;
};
struct CPHelper00992b00
{
    bool Lookup(Actor* a, unsigned __int64* out);
    void SetValue(Actor* a, unsigned __int64 v);
};
struct CPStandIn00992b00
{
    int f0, f4, f8, fc;
    CPHelper00992b00* pHelper;
    void ClearFlagIfSet(Actor* pactor, Flt& flt);
};

// Queries the actor's mask via the helper; if the bit for flt is set, clears it and writes the updated mask back.
// @fnv 0x00992b00
void CPStandIn00992b00::ClearFlagIfSet(Actor* apActor, Flt& flt)
{
    __int64 ullBit;
    unsigned __int64 ullMask = 0;
    if (!pHelper->Lookup(apActor, &ullMask))
        return;
    ullBit = 1 << (unsigned int)flt;
    if ((ullMask & ullBit) != 0)
    {
        ullMask &= ~ullBit;
        pHelper->SetValue(apActor, ullMask);
    }
}
}  // namespace fnv_00992b00

struct CombatObj
{
    int FUN_009931a0();
};
// @fnv 0x009931a0
int CombatObj::FUN_009931a0()
{
    return *(char*)((char*)this + 0x154) == 1;
}

typedef unsigned __int64 CPOut00993a00;
struct CPMapItem00993a00
{
    CPMapItem00993a00* next;
    unsigned int key;
    CPOut00993a00 val;
};
struct CPMap00993a00
{
    virtual ~CPMap00993a00();
    virtual unsigned int GetHashIndex(unsigned int key);
    virtual bool IsKeyEqual(unsigned int key, unsigned int other);
    int iCount;
    CPMapItem00993a00** m_pkBuckets;
    bool Lookup(unsigned int key, CPOut00993a00* pOut);
};

// Hashes the key, walks that bucket's item chain, and on a matching key copies the item's value to pOut and returns true; otherwise returns false.
// @fnv 0x00993a00
bool CPMap00993a00::Lookup(unsigned int key, CPOut00993a00* pOutValue)
{
    unsigned int uiIndex = GetHashIndex(key);
    CPMapItem00993a00* pkItem = m_pkBuckets[uiIndex];
    while (pkItem)
    {
        if (IsKeyEqual(key, pkItem->key))
        {
            *pOutValue = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}

struct CPMapItem00993a80
{
    CPMapItem00993a80* next;
    unsigned int key;
    unsigned __int64 val;
};
struct CPMap00993a80
{
    virtual ~CPMap00993a80();
    virtual unsigned int GetHashIndex(unsigned int key);
    unsigned int iCount;
    CPMapItem00993a80** m_pkBuckets;
    void GetNextEntry(CPMapItem00993a80*& rpkNext, unsigned int* pKey, unsigned __int64* pVal);
};

// Outputs the current item's key and value, then advances the cursor to the next item in the same bucket or the next non-empty bucket.
// @fnv 0x00993a80
void CPMap00993a80::GetNextEntry(CPMapItem00993a80*& rpkNext, unsigned int* pKey, unsigned __int64* pVal)
{
    CPMapItem00993a80* pkItem = rpkNext;
    unsigned int uiIndex;
    *pKey = pkItem->key;
    *pVal = pkItem->val;
    if (pkItem->next)
    {
        rpkNext = pkItem->next;
        return;
    }
    uiIndex = GetHashIndex(pkItem->key);
    for (++uiIndex; uiIndex < iCount; ++uiIndex)
    {
        pkItem = m_pkBuckets[uiIndex];
        if (pkItem)
        {
            rpkNext = pkItem;
            return;
        }
    }
    rpkNext = 0;
}

struct CombatMap
{
    void ComputeHash();
};
struct CombatMapRef
{
    void FUN_009950a0(CombatMap** p);
};
// @fnv 0x009950a0
void CombatMapRef::FUN_009950a0(CombatMap** ppCombatMap)
{
    (*ppCombatMap)->ComputeHash();
}

extern const char $SG8126[];

struct AutoMemHelper
{
    char pad[4];
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

void _FNV_Warning(const char*, ...);

struct QuantityData
{
    void SetQuantity(unsigned int);
};

struct FUN_00985d10 : QuantityData
{
    char pad[0x15c];
    void* operator new(size_t size);
    FUN_00985d10(unsigned int);
};

struct FUN_00991e80_shell
{
    char pad_00[0x34];
    unsigned int m_uiDebugFlags;

    unsigned int Add(FUN_00985d10*&);

    FUN_00985d10* FUN_00991e80();
};

// Allocates a combat group with the next id, adds it to the manager, warns if the returned position exceeds 0x40, and sets that position as its quantity.
// @fnv 0x00991e80
FUN_00985d10* FUN_00991e80_shell::FUN_00991e80()
{
    AutoMemHelper tempMemContext(0x2b, true, $SG8126, 0x161);
    FUN_00985d10* pgroup = new FUN_00985d10(m_uiDebugFlags++);
    unsigned int ipos = Add(pgroup);
    if (ipos > 0x40)
    {
        _FNV_Warning(
            "COMBAT: In CombatManager, MAX_NUM_COMBAT_GROUPS( %i ) has been exceeded to %i.  Its value needs to be raised.",
            0x40, ipos);
    }
    pgroup->SetQuantity(ipos);
    return pgroup;
}

class CombatController
{
  public:
    char pad[0x188];
    CombatController(Actor* apActor, ActorCombatGroup* apGroup, bool abFlag);
    ActorCombatGroup* GetCombatGroup();
};
struct CombatGroup_9922b0
{
    bool AddMember(Actor* apActor);
    void ClearMembers();
    bool ActorMergeData(ActorCombatGroup* apGroup);
};
struct FUN_009922b0_shell : public CombatManager
{
    CombatController* GetOrCreateCombatController(Actor* apActor, ActorCombatGroup* apGroup);
};
// @fnv 0x009922b0
CombatController* FUN_009922b0_shell::GetOrCreateCombatController(Actor* apActor, ActorCombatGroup* apGroup)
{
    CombatController* pcombatController;
    AutoMemContext tempMemContext((MEM_CONTEXT)0x2b, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp",
                                  0x1c6);
    pcombatController = apActor->GetCombatController();
    if (pcombatController)
    {
        ActorCombatGroup* pcurrentGroup = pcombatController->GetCombatGroup();
        if (pcurrentGroup != apGroup && ((CombatGroup_9922b0*)apGroup)->ActorMergeData(pcurrentGroup))
            ((CombatGroup_9922b0*)pcurrentGroup)->ClearMembers();
    }
    else if (((CombatGroup_9922b0*)apGroup)->AddMember(apActor))
    {
        pcombatController = new CombatController(apActor, apGroup, false);
    }
    return pcombatController;
}

namespace fnv_009923d0 {
struct FUN_009867d0_shell
{
    void FUN_009867d0(void* arg1);
};

struct CombatController
{
    char pad[0x188];
    void* operator new(size_t size);
    CombatController(void* arg1, FUN_009867d0_shell* group, void* arg2);
};

struct FUN_009923d0_shell
{
    FUN_009867d0_shell* FUN_00991e80();

    CombatController* CreateCombatController(void* arg1, void* arg2);
};

// Gets a group via FUN_00991e80, initializes it with arg1, then allocates and returns a CombatController built from arg1, the group and arg2.
// @fnv 0x009923d0
CombatController* FUN_009923d0_shell::CreateCombatController(void* arg1, void* arg2)
{
    FUN_009867d0_shell* m_pCombatData = FUN_00991e80();
    m_pCombatData = m_pCombatData;
    m_pCombatData->FUN_009867d0(arg1);
    CombatController* m_pCombatController = new CombatController(arg1, m_pCombatData, arg2);
    return m_pCombatController;
}
}  // namespace fnv_009923d0

namespace fnv_00992920 {
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};

struct CombatMapOwner : Arr
{
    void FUN_00992a30(unsigned int);
};

struct FUN_00987820_shell
{
    void FUN_00987820(void*);
};

struct Member14
{
    void RemoveEntryForRef(void*);
};

struct Member1C
{
    void RemoveEntry(unsigned int);
};

struct TargetObj
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
    virtual bool IsActor();
};

struct FUN_00992920_shell : CombatMapOwner
{
    char pad_00[0x14];
    Member14* member_14;
    char pad_18[4];
    Member1C* member_1c;

    void ProcessCombatTarget(TargetObj* arg1);
};

// @fnv 0x00992920
void FUN_00992920_shell::ProcessCombatTarget(TargetObj* pTarget)
{
    if (g_BGSSaveLoadGame->FUN_0042ce10())
        return;

    TargetObj* pActor = 0;
    if (pTarget->IsActor())
        pActor = pTarget;

    for (unsigned int i = 0; i < Arr::GetSize(); i++)
    {
        FUN_00987820_shell* pGroup = (FUN_00987820_shell*)*Arr::GetAt(i);
        if (pGroup)
            pGroup->FUN_00987820(pTarget);
    }

    if (pActor)
    {
        CombatMapOwner::FUN_00992a30((unsigned int)pActor);
        member_1c->RemoveEntry((unsigned int)pActor);
    }

    member_14->RemoveEntryForRef(pTarget);
}
}  // namespace fnv_00992920

namespace fnv_00991600 {
struct ActiveEffect;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatAction;
struct CombatGoal;
struct CombatPlan;
struct CombatBehavior;
struct CombatProcedure;
struct CombatState;
struct IDebugText;
struct InventoryStackRecord;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct Projectile;
struct Script;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESFile;
struct TESIdleForm;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct FUN_00991600_shell : public CombatManager
{
    void FUN_00991600(bool);
};

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct StrArr
{
    void SetAt(unsigned int, char* const&);
};
struct BGSCameraPath;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTArray;
template <> class NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >
{
  public:
    void Compact();
};
struct FUN_00986c40_obj
{
    bool FUN_00986c40();
};
struct FUN_009914d0
{
    ~FUN_009914d0();
};
struct FUN_0097ef50_obj
{
    void ResetModifierIfActive();
};
struct FUN_00991770_obj
{
    void UpdateDetectionVisuals();
};
int __fastcall FUN_009938b0(void*);
// @fnv 0x00991600
void FUN_00991600_shell::FUN_00991600(bool abTimeStopped)
{
    unsigned int igroupCount = ((Arr*)this)->GetSize();
    if (igroupCount)
    {
        for (unsigned int i = 0; i < igroupCount; i++)
        {
            ActorCombatGroup* pgroup = (ActorCombatGroup*)*((Arr*)this)->GetAt(i);
            if (pgroup && ((FUN_00986c40_obj*)pgroup)->FUN_00986c40())
            {
                delete (FUN_009914d0*)pgroup;
                ((StrArr*)this)->SetAt(i, 0);
            }
        }
        if (!FUN_009938b0(this))
        {
            ((NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*)this)->Compact();
            ((NiTPointerMap<Actor*, __int64>*)m_pActorCombatGroupMap)->RemoveAll();
        }
    }
    if (!abTimeStopped)
    {
        for (unsigned int i = 0; i < ((Arr*)this)->GetSize(); i++)
        {
            ActorCombatGroup* pgroup = (ActorCombatGroup*)*((Arr*)this)->GetAt(i);
            if (pgroup)
            {
                unsigned int imemberCount = pgroup->GetCount();
                for (unsigned int j = 0; j < imemberCount; j++)
                {
                    CombatController* pcombatController;
                    Actor* pactor = pgroup->GetIntAt(j);
                    pcombatController = pactor->GetCombatController();
                    if (pcombatController)
                        ((FUN_0097ef50_obj*)pcombatController)->ResetModifierIfActive();
                }
            }
        }
    }
    ((FUN_00991770_obj*)this)->UpdateDetectionVisuals();
}
}  // namespace fnv_00991600

namespace fnv_00992640 {
struct FUN_00968630_stub
{
    Actor* FUN_00968630(unsigned int);
};

struct PathingSolution : FUN_00968630_stub
{
    unsigned int GetVirtualNodeCount();
};

struct TESWorldSpace
{
    bool FUN_00992530(Actor*, Actor*);
};

struct FUN_actor_vtstub
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
    virtual void v225();
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
    virtual ActorCombatGroup* GetCombatGroup();
};

struct FUN_00992640_shell : TESWorldSpace
{
    bool FUN_00992640(Actor*, Actor*);
};

// @fnv 0x00992640
bool FUN_00992640_shell::FUN_00992640(Actor* apActor, Actor* apAttacker)
{
    ActorCombatGroup* pgroup = ((FUN_actor_vtstub*)apAttacker)->GetCombatGroup();
    if (pgroup == 0)
    {
        return false;
    }
    unsigned int iGroupCount = ((PathingSolution*)pgroup)->GetVirtualNodeCount();
    for (unsigned int i = 0; i < iGroupCount; ++i)
    {
        Actor* pGroupMember = ((PathingSolution*)pgroup)->FUN_00968630(i);
        if (FUN_00992530(apActor, pGroupMember))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00992640

namespace fnv_009931c0 {
struct FUN_009931c0_shell : public CombatManager
{
    unsigned int CountCombatGroupMembers(Actor*, unsigned int*);
};

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
extern Actor* _g_thePlayer;
// @fnv 0x009931c0
unsigned int FUN_009931c0_shell::CountCombatGroupMembers(Actor* apActor, unsigned int* apNumLost)
{
    unsigned int icount = 0;
    if (apNumLost)
        *apNumLost = 0;
    for (unsigned int i = 0; i < ((Arr*)this)->GetSize(); i++)
    {
        ActorCombatGroup* pgroup = (ActorCombatGroup*)*((Arr*)this)->GetAt(i);
        if (pgroup && (!apActor || pgroup->ContainsActor(apActor)))
        {
            unsigned int igroupCount = pgroup->GetCount();
            if (igroupCount > 0 && pgroup == _g_thePlayer->GetCombatGroup())
                igroupCount--;
            icount += igroupCount;
            if (apActor && apNumLost)
            {
                CombatTargetTimestamp flastDetectedTimeStamp = pgroup->GetLastDetectedTimestamp(apActor);
                if (flastDetectedTimeStamp.GetElapsedTime() > *(float*)originalRuntimeFloatSetting413.Float())
                    *apNumLost += igroupCount;
            }
        }
    }
    return icount;
}
}  // namespace fnv_009931c0

namespace fnv_00993440 {
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00993440_shell : public CombatManager
{
    void LoadCombatState(BGSLoadGameBuffer*);
};

class BGSAddonNode;
struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct QuantityData
{
    void SetQuantity(unsigned int);
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct CombatTarget
{
    void SetValue(unsigned int, unsigned int, unsigned int);
};
struct FUN_00985d10
{
    FUN_00985d10(unsigned int);
    char pad[0x15c];
};
struct GroupShim
{
    void FUN_0098e3d0(BGSLoadGameBuffer*);
};
struct ThreatShim
{
    void FUN_009a5a70(BGSLoadGameBuffer*);
};
struct StampShim
{
    void FUN_009a5ff0(BGSLoadGameBuffer*);
};
struct TimerShim
{
    void FUN_009a5f20(BGSLoadFormBuffer*);
};
struct int64
{
    unsigned int lo;
    unsigned int hi;
};
struct CMView
{
    char pad[0x10];
    CombatTarget* m_pActorCombatGroupMap;
    ThreatShim* m_pThreatMap;
};
// @fnv 0x00993440
void FUN_00993440_shell::LoadCombatState(BGSLoadGameBuffer* apLoadGameBuffer)
{
    ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData((char*)this + 0x34, 4);
    unsigned int icount;
    unsigned int inumCombatGroups = ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadElementCount();
    for (unsigned int i = 0; i < inumCombatGroups; i++)
    {
        ActorCombatGroup* pgroup;
        unsigned int igroupNum = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData(&igroupNum, 4);
        unsigned int igroupID = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData(&igroupID, 4);
        pgroup = (ActorCombatGroup*)new FUN_00985d10(0);
        ((QuantityData*)pgroup)->SetQuantity(igroupNum);
        ((TESRaceForm*)pgroup)->Initialize(igroupID);
        ((GroupShim*)pgroup)->FUN_0098e3d0(apLoadGameBuffer);
        ((Arr86*)this)->SetAt(igroupNum, *(BGSAddonNode**)&pgroup);
    }
    ((CMView*)this)->m_pThreatMap->FUN_009a5a70(apLoadGameBuffer);
    icount = ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadElementCount();
    for (unsigned int i = 0; i < icount; i++)
    {
        Actor* pactor = 0;
        int64 itargetingBitfield;
        itargetingBitfield.lo = 0;
        itargetingBitfield.hi = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadFormIdentifier(&pactor);
        ((CMView*)this)
            ->m_pActorCombatGroupMap->SetValue((unsigned int)pactor, itargetingBitfield.lo, itargetingBitfield.hi);
    }
    ((StampShim*)((char*)this + 0x20))->FUN_009a5ff0(apLoadGameBuffer);
    ((TimerShim*)((char*)this + 0x24))->FUN_009a5f20((BGSLoadFormBuffer*)apLoadGameBuffer);
    ((TimerShim*)((char*)this + 0x2c))->FUN_009a5f20((BGSLoadFormBuffer*)apLoadGameBuffer);
}
}  // namespace fnv_00993440

namespace fnv_009932d0 {
struct CPMapItem00993a80;
struct MapX
{
    void* GetFirstPos();
};
struct Flt
{
    operator unsigned int();
};
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue(int, unsigned int);
};
struct CPMap00993a80
{
    void GetNextEntry(CPMapItem00993a80*&, unsigned int*, unsigned __int64*);
};
struct S0098de90
{
    void WriteToStream(BGSSaveFormBuffer*);
};
struct S009a59e0
{
    void SaveThreats(BGSSaveFormBuffer*);
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};
struct S009a5f90
{
    void SaveTimeStamp(void*);
};

struct FUN_009932d0_shell
{
    void FUN_009932d0(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x009932d0
void FUN_009932d0_shell::FUN_009932d0(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData((char*)this + 0x34, 4, 0);
    unsigned int uiSavedCount = 0;
    unsigned int uiPos = apBuffer->StartVariableSizedValue();
    {
        unsigned int uiMapCount;
        unsigned int uiPos2;
        for (unsigned int i = 0; i < ((Arr*)this)->GetSize(); i++)
        {
            Flt* pItem = (Flt*)*((Arr*)this)->GetAt(i);
            if (pItem)
            {
                unsigned int uiNext;
                {
                    unsigned int uiID = *pItem;
                    apBuffer->SaveData(&uiID, 4, 0);
                }
                uiNext = (unsigned int)((BSSimpleList<void*>*)pItem)->GetNext();
                apBuffer->SaveData(&uiNext, 4, 0);
                ((S0098de90*)pItem)->WriteToStream(apBuffer);
                uiSavedCount++;
            }
        }
        apBuffer->SaveVariableSizedValue(uiSavedCount, uiPos);
        ((S009a59e0*)*(void**)((char*)this + 0x14))->SaveThreats(apBuffer);
        uiMapCount = 0;
        uiPos2 = apBuffer->StartVariableSizedValue();
        for (CPMapItem00993a80* pMapPos = (CPMapItem00993a80*)((MapX*)*(void**)((char*)this + 0x10))->GetFirstPos();
             pMapPos;)
        {
            unsigned int uiKey;
            unsigned __int64 uiValue;
            ((CPMap00993a80*)*(void**)((char*)this + 0x10))->GetNextEntry(pMapPos, &uiKey, &uiValue);
            apBuffer->SerializeFormData((void*)uiKey, 0);
            uiMapCount++;
        }
        apBuffer->SaveVariableSizedValue(uiMapCount, uiPos2);
    }
    ((S009a5f90*)((char*)this + 0x20))->SaveTimeStamp(apBuffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x24))->FUN_009a5eb0(apBuffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x2c))->FUN_009a5eb0(apBuffer);
}
}  // namespace fnv_009932d0

struct Actor496
{
    virtual void unk000();
    virtual void unk001();
    virtual void unk002();
    virtual void unk003();
    virtual void unk004();
    virtual void unk005();
    virtual void unk006();
    virtual void unk007();
    virtual void unk008();
    virtual void unk009();
    virtual void unk00a();
    virtual void unk00b();
    virtual void unk00c();
    virtual void unk00d();
    virtual void unk00e();
    virtual void unk00f();
    virtual void unk010();
    virtual void unk011();
    virtual void unk012();
    virtual void unk013();
    virtual void unk014();
    virtual void unk015();
    virtual void unk016();
    virtual void unk017();
    virtual void unk018();
    virtual void unk019();
    virtual void unk01a();
    virtual void unk01b();
    virtual void unk01c();
    virtual void unk01d();
    virtual void unk01e();
    virtual void unk01f();
    virtual void unk020();
    virtual void unk021();
    virtual void unk022();
    virtual void unk023();
    virtual void unk024();
    virtual void unk025();
    virtual void unk026();
    virtual void unk027();
    virtual void unk028();
    virtual void unk029();
    virtual void unk02a();
    virtual void unk02b();
    virtual void unk02c();
    virtual void unk02d();
    virtual void unk02e();
    virtual void unk02f();
    virtual void unk030();
    virtual void unk031();
    virtual void unk032();
    virtual void unk033();
    virtual void unk034();
    virtual void unk035();
    virtual void unk036();
    virtual void unk037();
    virtual void unk038();
    virtual void unk039();
    virtual void unk03a();
    virtual void unk03b();
    virtual void unk03c();
    virtual void unk03d();
    virtual void unk03e();
    virtual void unk03f();
    virtual void unk040();
    virtual void unk041();
    virtual void unk042();
    virtual void unk043();
    virtual void unk044();
    virtual void unk045();
    virtual void unk046();
    virtual void unk047();
    virtual void unk048();
    virtual void unk049();
    virtual void unk04a();
    virtual void unk04b();
    virtual void unk04c();
    virtual void unk04d();
    virtual void unk04e();
    virtual void unk04f();
    virtual void unk050();
    virtual void unk051();
    virtual void unk052();
    virtual void unk053();
    virtual void unk054();
    virtual void unk055();
    virtual void unk056();
    virtual void unk057();
    virtual void unk058();
    virtual void unk059();
    virtual void unk05a();
    virtual void unk05b();
    virtual void unk05c();
    virtual void unk05d();
    virtual void unk05e();
    virtual void unk05f();
    virtual void unk060();
    virtual void unk061();
    virtual void unk062();
    virtual void unk063();
    virtual void unk064();
    virtual void unk065();
    virtual void unk066();
    virtual void unk067();
    virtual void unk068();
    virtual void unk069();
    virtual void unk06a();
    virtual void unk06b();
    virtual void unk06c();
    virtual void unk06d();
    virtual void unk06e();
    virtual void unk06f();
    virtual void unk070();
    virtual void unk071();
    virtual void unk072();
    virtual void unk073();
    virtual void unk074();
    virtual void unk075();
    virtual void unk076();
    virtual void unk077();
    virtual void unk078();
    virtual void unk079();
    virtual void unk07a();
    virtual void unk07b();
    virtual void unk07c();
    virtual void unk07d();
    virtual void unk07e();
    virtual void unk07f();
    virtual void unk080();
    virtual void unk081();
    virtual void unk082();
    virtual void unk083();
    virtual void unk084();
    virtual void unk085();
    virtual void unk086();
    virtual void unk087();
    virtual void unk088();
    virtual void unk089();
    virtual void unk08a();
    virtual bool IsDead(bool);
    virtual void unk08c();
    virtual void unk08d();
    virtual void unk08e();
    virtual void unk08f();
    virtual void unk090();
    virtual void unk091();
    virtual void unk092();
    virtual void unk093();
    virtual void unk094();
    virtual void unk095();
    virtual void unk096();
    virtual void unk097();
    virtual void unk098();
    virtual void unk099();
    virtual void unk09a();
    virtual void unk09b();
    virtual void unk09c();
    virtual void unk09d();
    virtual void unk09e();
    virtual void unk09f();
    virtual void unk0a0();
    virtual void unk0a1();
    virtual void unk0a2();
    virtual void unk0a3();
    virtual void unk0a4();
    virtual void unk0a5();
    virtual void unk0a6();
    virtual void unk0a7();
    virtual void unk0a8();
    virtual void unk0a9();
    virtual void unk0aa();
    virtual void unk0ab();
    virtual void unk0ac();
    virtual void unk0ad();
    virtual void unk0ae();
    virtual void unk0af();
    virtual void unk0b0();
    virtual void unk0b1();
    virtual void unk0b2();
    virtual void unk0b3();
    virtual void unk0b4();
    virtual void unk0b5();
    virtual void unk0b6();
    virtual void unk0b7();
    virtual void unk0b8();
    virtual void unk0b9();
    virtual void unk0ba();
    virtual void unk0bb();
    virtual void unk0bc();
    virtual void unk0bd();
    virtual void unk0be();
    virtual void unk0bf();
    virtual void unk0c0();
    virtual void unk0c1();
    virtual void unk0c2();
    virtual void unk0c3();
    virtual void unk0c4();
    virtual void unk0c5();
    virtual void unk0c6();
    virtual void unk0c7();
    virtual void unk0c8();
    virtual void unk0c9();
    virtual void unk0ca();
    virtual void unk0cb();
    virtual void unk0cc();
    virtual void unk0cd();
    virtual void unk0ce();
    virtual void unk0cf();
    virtual void unk0d0();
    virtual void unk0d1();
    virtual void unk0d2();
    virtual void unk0d3();
    virtual void unk0d4();
    virtual void unk0d5();
    virtual void unk0d6();
    virtual void unk0d7();
    virtual void unk0d8();
    virtual void unk0d9();
    virtual void unk0da();
    virtual void unk0db();
    virtual void unk0dc();
    virtual void unk0dd();
    virtual void unk0de();
    virtual void unk0df();
    virtual void unk0e0();
    virtual void unk0e1();
    virtual void unk0e2();
    virtual void unk0e3();
    virtual void unk0e4();
    virtual void unk0e5();
    virtual void unk0e6();
    virtual void unk0e7();
    virtual void unk0e8();
    virtual void unk0e9();
    virtual void unk0ea();
    virtual void unk0eb();
    virtual void unk0ec();
    virtual void unk0ed();
    virtual void unk0ee();
    virtual void unk0ef();
    virtual void unk0f0();
    virtual void unk0f1();
    virtual void unk0f2();
    virtual void unk0f3();
    virtual void unk0f4();
    virtual void unk0f5();
    virtual void unk0f6();
    virtual void unk0f7();
    virtual void unk0f8();
    virtual void unk0f9();
    virtual void unk0fa();
    virtual void unk0fb();
    virtual void unk0fc();
    virtual void unk0fd();
    virtual ActorCombatGroup* GetCombatGroup();
    virtual void unk0ff();
    virtual void unk100();
    virtual void unk101();
    virtual void unk102();
    virtual void unk103();
    virtual void unk104();
    virtual void unk105();
    virtual void unk106();
    virtual void unk107();
    virtual void unk108();
    virtual void unk109();
    virtual void unk10a();
    virtual void unk10b();
    virtual void unk10c();
    virtual void unk10d();
    virtual void unk10e();
    virtual void unk10f();
    virtual void unk110();
    virtual void unk111();
    virtual void unk112();
    virtual void unk113();
    virtual void unk114();
    virtual void unk115();
    virtual void unk116();
    virtual void unk117();
    virtual void unk118();
    virtual void unk119();
    virtual void unk11a();
    virtual void unk11b();
    virtual void unk11c();
    virtual void unk11d();
    virtual void unk11e();
    virtual void unk11f();
    virtual void unk120();
    virtual void unk121();
    virtual void unk122();
    virtual void unk123();
    virtual void unk124();
    virtual void unk125();
    virtual void unk126();
    virtual void unk127();
    virtual void unk128();
    virtual void unk129();
    virtual void unk12a();
    virtual void unk12b();
    virtual void unk12c();
    virtual void unk12d();
    virtual void unk12e();
    virtual void unk12f();
    virtual void unk130();
    virtual void unk131();
    virtual void unk132();
    virtual void unk133();
    virtual void unk134();
    virtual void unk135();
    virtual NiPoint3 Predict(float);
    bool GetDisabled() const;
    bool GetDeleted() const;
};
struct GroupIndexView
{
    unsigned int GetIndex();
};
struct PointLengthView
{
    float FUN_004a7290() const;
};
struct CombatMap496
{
    void* GetFirstPos();
    void GetNext(void*&, Actor496**, unsigned __int64*);
};
struct Manager496
{
    int unk00, unk04, unk08, unk0c;
    CombatMap496* map;
    int CountNearbyActors(NiPoint3, float, float, Actor496*, int*, int*, int*, int*);
};
typedef NiPoint3(__thiscall* Predict496)(Actor496*, float);
// @fnv 0x00992ba0
int Manager496::CountNearbyActors(NiPoint3 origin, float range, float time, Actor496* source, int* outSelf,
                                  int* outGroup, int* outAllied, int* outEnemy)
{
    int i = 0;
    int b = 0;
    int c = 0;
    int a = 0;
    int e = 0;
    ActorCombatGroup* d = source->GetCombatGroup();
    float g = range * range;
    unsigned __int64 f = 0;
    if (d)
        f = 1ui64 << reinterpret_cast<GroupIndexView*>(d)->GetIndex();
    void* h = map->GetFirstPos();
    while (h)
    {
        Actor496* F = 0;
        unsigned __int64 I = 0;
        map->GetNext(h, &F, &I);
        if (!F || (F && (F->IsDead(false) || F->GetDisabled() || F->GetDeleted())))
            continue;
        NiPoint3 A = F->Predict(time);
        NiPoint3 H = origin - A;
        if (g > reinterpret_cast<const PointLengthView*>(&H)->FUN_004a7290())
        {
            i++;
            if (F == source)
                b++;
            else if (F->GetCombatGroup() == d)
                c++;
            else if (I & f)
                a++;
            else
                e++;
        }
    }
    if (outSelf)
        *outSelf = b;
    if (outGroup)
        *outGroup = c;
    if (outAllied)
        *outAllied = a;
    if (outEnemy)
        *outEnemy = e;
    return i;
}

struct CombatGroupShell_00991f80 : ActorCombatGroup
{
    void FUN_009869a0(Actor* actor);
    bool FUN_009867d0(Actor* actor);
    void FUN_00986740(ActorCombatGroup* group);
    void FUN_00986410(Actor* actor);
};
struct ActorShell_00991f80 : Actor
{
    bool FUN_00566950();
    int FUN_00474cb0();
    unsigned int FUN_0055d520();
    unsigned int FUN_0084e3a0();
};
typedef void(__thiscall* SetCombatGroupProc_00991f80)(Actor*, ActorCombatGroup*);
typedef unsigned int(__thiscall* GetActorValueProc_00991f80)(Actor*);
extern const char UNK_0108dab0[];
void __cdecl FUN_005b5e40(const char*, unsigned int, unsigned int);
struct FUN_00991f80_shell : CombatManager
{
    FUN_00985d10* FUN_00991f80(Actor* actor);
};
// @fnv 0x00991f80
FUN_00985d10* FUN_00991f80_shell::FUN_00991f80(Actor* apActor)
{
    ActorCombatGroup* pGroup = g_thePlayer->GetCombatGroup();
    ((CombatGroupShell_00991f80*)pGroup)->FUN_009869a0(apActor);
    if (pGroup->GetCount() > 1)
    {
        ActorCombatGroup* pOldGroup = pGroup;
        ((CombatGroupShell_00991f80*)pOldGroup)->FUN_009869a0((Actor*)g_thePlayer);
        pGroup = (ActorCombatGroup*)((FUN_00991e80_shell*)this)->FUN_00991e80();
        ((CombatGroupShell_00991f80*)pGroup)->FUN_009867d0((Actor*)g_thePlayer);
        ((SetCombatGroupProc_00991f80)(*(void***)g_thePlayer)[0xff])((Actor*)g_thePlayer, pGroup);
        ((CombatGroupShell_00991f80*)pGroup)->FUN_00986740(pOldGroup);
        for (unsigned int uStack_14 = 0; uStack_14 < pOldGroup->GetCount(); uStack_14++)
        {
            Actor* piVar5 = pOldGroup->GetIntAt(uStack_14);
            if (((ActorShell_00991f80*)piVar5)->FUN_00566950())
            {
                if (((CombatGroupShell_00991f80*)pGroup)->FUN_009867d0(piVar5))
                {
                    ((CombatGroupShell_00991f80*)pOldGroup)->FUN_009869a0(piVar5);
                    ((SetCombatGroupProc_00991f80)(*(void***)piVar5)[0xff])((Actor*)piVar5, pGroup);
                    uStack_14--;
                }
                else
                {
                    FUN_005b5e40(UNK_0108dab0,
                                 ((ActorShell_00991f80*)piVar5)->FUN_00474cb0()
                                     ? ((GetActorValueProc_00991f80)(*(void***)piVar5)[0x130 / 4])(piVar5)
                                     : ((ActorShell_00991f80*)piVar5)->FUN_0055d520(),
                                 ((ActorShell_00991f80*)piVar5)->FUN_0084e3a0());
                }
            }
        }
    }
    ((CombatGroupShell_00991f80*)pGroup)->FUN_00986410(apActor);
    FUN_00985d10* pResult = ((FUN_00991e80_shell*)this)->FUN_00991e80();
    ((CombatGroupShell_00991f80*)pResult)->FUN_009867d0(apActor);
    return pResult;
}

struct ActorShell_992110
{
    bool CanAttackActor(Actor* apTarget);
};
struct CombatGroup_992110
{
    bool AddMember(Actor* apActor);
    bool FUN_00986410(Actor* apTarget);
};
struct CombatController_992110
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~CombatController_992110();
    CombatGroup_992110* GetCombatGroup();
};
struct FUN_00992110_shell : public FUN_00991e80_shell
{
    CombatController_992110* FUN_00992110(Actor* apActor, Actor* apTarget, int aiArg3, int aiArg4);
};

// @fnv 0x00992110
CombatController_992110* FUN_00992110_shell::FUN_00992110(Actor* apActor, Actor* apTarget, int aiArg3, int aiArg4)
{
    AutoMemHelper kMem(0x2b, true, $SG8126, 0x1a7);
    CombatController_992110* pController = (CombatController_992110*)apActor->GetCombatController();
    CombatGroup_992110* pGroup2 = 0;
    if (!pController)
    {
        if (!((ActorShell_992110*)apActor)->CanAttackActor(apTarget))
            return 0;
        pGroup2 = (CombatGroup_992110*)FUN_00991e80();
        pGroup2->AddMember(apActor);
        pController = (CombatController_992110*)new CombatController(apActor, (ActorCombatGroup*)pGroup2, false);
        if (!pGroup2->FUN_00986410(apTarget))
        {
            delete pController;
            return 0;
        }
    }
    else
    {
        pGroup2 = pController->GetCombatGroup();
        pGroup2->FUN_00986410(apTarget);
    }
    return pController;
}

struct ThreatFloatSetting
{
    float* FUN_00403e20();
};
struct ThreatIntSetting
{
    int* FUN_0043d4d0();
};
extern ThreatFloatSetting DAT_011cf3f0;
extern ThreatFloatSetting DAT_011cea74;
extern ThreatIntSetting DAT_011ce3cc;
struct ThreatState
{
    bool FUN_009928a0();
    bool HasCombatFlag40();
    bool HasCombatFlag80();
};
struct ThreatValueOwner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual int Value(int);
};
struct ThreatActor
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    ThreatValueOwner values;
    float FUN_00477900();
    float FUN_006a78f0();
    ThreatState* FUN_008a7f80();
};
struct ThreatPosition
{
    float x, y, z;
};
float ComputeExplosionDamageFalloff(float, float, float);
struct ThreatManager
{
    int CountNearbyActors(ThreatPosition, float, float, ThreatActor*, int*, int*, int*, int*);
    bool IsThreatWithinLimits(ThreatActor*, ThreatActor*, const ThreatPosition&, float);
};
// @fnv 0x00992720
bool ThreatManager::IsThreatWithinLimits(ThreatActor* actor, ThreatActor* target, const ThreatPosition& position,
                                         float radius)
{
    if (!target)
        return true;
    float strength = target->FUN_00477900();
    float distance = target->FUN_006a78f0();
    if (distance < *DAT_011cf3f0.FUN_00403e20())
        return true;
    strength = ComputeExplosionDamageFalloff(strength, distance, *DAT_011cf3f0.FUN_00403e20());
    if (strength < *DAT_011cea74.FUN_00403e20())
        return true;
    int firstB = 0;
    int second_ = 0;
    int third8 = 0;
    int fourth_2 = 0;
    int result2 = CountNearbyActors(position, strength, radius, actor, &firstB, &second_, &third8, &fourth_2);
    ThreatState* state = actor->FUN_008a7f80();
    if (firstB && !state->FUN_009928a0())
        return false;
    if (second_ && !state->HasCombatFlag40())
        return false;
    if (fourth_2 && actor->values.Value(3) >= *DAT_011ce3cc.FUN_0043d4d0() && !state->HasCombatFlag80())
        return false;
    return true;
}

extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

extern int DAT_011f1590;

class BaseProcess
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual TESPackage* GetAssignedPackage();  // 0x22c = index 139 (0x8b)
};

class FUN_00982430
{
  public:
    FUN_00982430();
    virtual ~FUN_00982430();
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00906f60
{
  public:
    FUN_00906f60();
    void FUN_008d7f40(float);
    float x;
    float y;
};

class FUN_006815c0
{
  public:
    FUN_006815c0();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_006707c0
{
  public:
    FUN_006707c0();
    virtual ~FUN_006707c0();
    void SetPackageType(int);
    int b004;
    int b008;
    int b00C;
    int b010;
    int b014;
    int b018;
    int b01C;
    int b020;
    int b024;
    int b028;
    int b02C;
    int b030;
    int b034;
    int b038;
    int b03C;
    int b040;
    int b044;
    int b048;
    int b04C;
    int b050;
    int b054;
    int b058;
    int b05C;
    int b060;
    int b064;
    int b068;
    int b06C;
    int b070;
    int b074;
    int b078;
    int b07C;
};

class SubClass_997600
{
  public:
    SubClass_997600(class FUN_0097d3a0* parent, float val);
    int s000;
    int s001;
    int s002;
    int s003;
    int s004;
    int s005;
    int s006;
    int s007;
    int s008;
    int s009;
    int s010;
    int s011;
    int s012;
    int s013;
    int s014;
    int s015;
    int s016;
    int s017;
    int s018;
    int s019;
    int s020;
    int s021;
    int s022;
    int s023;
    int s024;
    int s025;
    int s026;
    int s027;
    int s028;
    int s029;
    int s030;
    int s031;
    int s032;
    int s033;
    int s034;
    int s035;
    int s036;
    int s037;
    int s038;
    int s039;
    int s040;
    int s041;
    int s042;
    int s043;
    int s044;
    int s045;
    int s046;
    int s047;
    int s048;
    int s049;
    int s050;
    int s051;
    int s052;
    int s053;
    int s054;
    int s055;
    int s056;
    int s057;
    int s058;
    int s059;
    int s060;
    int s061;
    int s062;
    int s063;
    int s064;
    int s065;
    int s066;
    int s067;
    int s068;
    int s069;
    int s070;
    int s071;
    int s072;
    int s073;
    int s074;
    int s075;
    int s076;
    int s077;
    int s078;
    int s079;
    int s080;
    int s081;
    int s082;
    int s083;
    int s084;
    int s085;
    int s086;
    int s087;
    int s088;
    int s089;
    int s090;
    int s091;
    int s092;
    int s093;
    int s094;
    int s095;
    int s096;
    int s097;
    int s098;
    int s099;
    int s100;
    int s101;
    int s102;
    int s103;
    int s104;
    int s105;
    int s106;
    int s107;
    int s108;
    int s109;
    int s110;
    int s111;
    int s112;
    int s113;
    int s114;
    int s115;
    int s116;
    int s117;
    int s118;
    int s119;
    int s120;
    int s121;
    int s122;
    int s123;
    int s124;
    int s125;
    int s126;
    int s127;
    int s128;
    int s129;
    int s130;
    int s131;
    int s132;
    int s133;
    int s134;
    int s135;
    int s136;
    int s137;
    int s138;
};

class AnimIdle
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class FUN_0097d3a0 : public FUN_006707c0
{
  public:
    FUN_0097d3a0(Actor* a1, int a2, TESPackage* a3);
    virtual ~FUN_0097d3a0();

    void FUN_00984f60(unsigned int);
    void SetupPackageTarget(TESPackage*);

    int unk80;
    int unk84;
    int unk88;
    FUN_00982430 unk8C;
    SubClass_997600* unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    FUN_00906f60 unkB4;
    Actor* actor;
    int unkC0;
    unsigned char byteC4;
    unsigned char byteC5;
    unsigned char byteC6;
    unsigned char byteC7;
    int unkC8;
    float floatCC;
    float floatD0;
    bool byteD4;
    bool byteD5;
    char padD6_0;
    char padD6_1;
    float floatD8;
    float floatDC;
    float floatE0;
    unsigned char byteE4;
    char padE5_0;
    char padE5_1;
    char padE5_2;
    NiPointer<AnimIdle> unkE8;
    NiPointer<AnimIdle> unkEC;
    int unkF0;
    int unkF4;
    unsigned char byteF8;
    unsigned char byteF9;
    char padFA_0;
    char padFA_1;
    struct Struct14A
    {
        int a;
        int b;
        int c;
        int d;
        int e;
    } unkFC;
    struct Struct14B
    {
        int a;
        int b;
        int c;
        int d;
        int e;
    } unk110;
    unsigned char byte124;
    unsigned char byte125;
    unsigned char byte126;
    char pad127;
    FUN_006815c0 unk128[2];
    struct Struct02
    {
        char a;
        char b;
    } unk140;
    unsigned char byte142;
    char pad143;
    int unk144;
    float unk148;
    struct Struct3C
    {
        int s00;
        int s04;
        int s08;
        int s0C;
        int s10;
        int s14;
        int s18;
        int s1C;
        int s20;
        int s24;
        int s28;
        int s2C;
        int s30;
        int s34;
        int s38;
    } unk14C;
};

// Initializes the process fields, creates a SubClass_997600, and if an actor is set, resolves the package and calls SetupPackageTarget.
// @fnv 0x0097d3a0
FUN_0097d3a0::FUN_0097d3a0(Actor* apActor, int a2, TESPackage* apPackage)
{
    float val = (DAT_011f1590 % 10) * (double)0.1f;
    DAT_011f1590++;
    this->unk80 = a2;
    this->unk84 = 0;
    this->unk88 = 0;
    this->unk9C = new SubClass_997600(this, val);
    this->unkA0 = 0;
    this->unkA4 = 0;
    this->unkA8 = 0;
    this->unkAC = 0;
    this->unkB0 = 0;
    this->unkF0 = 0;
    this->unkF4 = 0;
    this->unkB4.FUN_008d7f40(0.1f);
    this->unk148 = 0.0f;
    memset(&this->unk14C, 0, sizeof(this->unk14C));
    this->actor = apActor;
    this->unkC0 = 0;
    this->SetPackageType(0x12);
    this->floatE0 = -1.0f;
    this->byteC4 = 0;
    this->byteE4 = 0;
    this->byteC7 = 0;
    this->unkC8 = 0;
    this->floatCC = 128.0f;
    this->floatD0 = 64.0f;
    this->byteD4 = 1;
    this->byteD5 = 1;
    this->floatD8 = 1.0f;
    this->floatDC = 1.0f;
    this->unk148 = 0.0f;
    this->byte124 = 0;
    this->byteC6 = 0xff;
    this->byteC5 = 0;
    this->byteF9 = 0;
    this->FUN_00984f60(0xc);
    this->byteF8 = 0;
    this->byte125 = 0;
    this->byte126 = 0;
    this->unk144 = 0;
    memset(&this->unkFC, 0, sizeof(this->unkFC));
    memset(&this->unk110, 0, sizeof(this->unk110));
    memset(this->unk128, 0, sizeof(this->unk128));
    memset(&this->unk140, 0, sizeof(this->unk140));
    this->byte142 = 0;
    if (this->actor != 0)
    {
        if (apPackage == 0)
        {
            apPackage = this->actor->GetProcess()->GetAssignedPackage();
        }
        this->SetupPackageTarget(apPackage);
    }
}

namespace fnv_00992480 {

struct TESPackage
{
    int GetPackType();
};

struct SpectatorPackage : public TESPackage
{
    void FUN_009f8330(Actor* target);
};

class BaseProcess_SV
{
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
    virtual void s128();
    virtual void s129();
    virtual void s130();
    virtual void s131();
    virtual void s132();
    virtual void s133();
    virtual void s134();
    virtual void s135();
    virtual void s136();
    virtual void s137();
    virtual void s138();
    virtual TESPackage* GetCurrentPackage();
};

struct CombatOwner_SV
{
    void FUN_009929e0(unsigned int);
    void FUN_00992480(Actor* a1, Actor* a2);
};

// Calls Unk_103 and reloads the package if its type is not 0x18; passes a2 to a SpectatorPackage if present, then calls FUN_009929e0 on a1.
// @fnv 0x00992480
void CombatOwner_SV::FUN_00992480(Actor* apActor, Actor* apTarget)
{
    if (apActor == apTarget)
        return;

    TESPackage* package;
    {
        BaseProcess_SV* process = (BaseProcess_SV*)apActor->GetProcess();
        package = process->GetCurrentPackage();
        if (!package || package->GetPackType() != 0x18)
        {
            apActor->Unk_103();
            package = process->GetCurrentPackage();
        }
    }
    if (package && package->GetPackType() == 0x18)
    {
        SpectatorPackage* spectatorPackage = (SpectatorPackage*)package;
        spectatorPackage->FUN_009f8330(apTarget);
    }
    FUN_009929e0((unsigned int)apActor);
}
}  // namespace fnv_00992480

// fallout/ai/creature.cpp: Creature, Holder, XActorQ (25 functions)

#include "creature_decls.h"

// @fnv 0x008d4ff0
void Creature::LoadGame(BGSLoadFormBuffer* buffer)
{
    Actor::LoadGame(buffer);
    m_uiActorFlags = 0;
}

// Returns the run speed from actor value 21 scaled by 1.1 and the run animation group multiplier, or 0 if overencumbered.
// @fnv 0x008d4eb0
float Creature::CalculateRunSpeed()
{
    float fRunSpeed = 0.0f;
    typedef bool(__thiscall * IsOverencumberedFn)(Creature*);
    if (!((IsOverencumberedFn)(*(void***)(this))[214])(this))
        fRunSpeed = actorValues.GetCurrentActorValue(21) * 1.1 * Creature::GetAnimationSpeedMultiplier(kAnimGroupRun);
    return fRunSpeed;
}

// @fnv 0x008d4f70
float Creature::GetAnimationSpeedMultiplier(ANIM_GROUP_ENUM group)
{
    if (!((CreatureAnimationAccess*)this)->GetAnimData())
        return 32.0f;
    typedef unsigned short (__thiscall Actor::*GroupFn)(ANIM_GROUP_ENUM, InventoryStackRecord*);
    unsigned short animGroup =
        (this->*reinterpret_cast<GroupFn>(&Actor::GetAnimGroup))(group, pAnimData->GetWeaponInfo(1, 0));
    return ((CreatureAnimationAccess*)this)->GetAnimData()->GetGroupSection(animGroup);
}

struct FUN_008d4a80_shell : public Creature
{
    int MapActorValue(int);
};

namespace ActorValue {
enum Index
{
};
bool __cdecl GetFlag(Index, unsigned int);
}

// Returns 0x2d if the actor value at aiWhich has flag 0x400 set, otherwise returns aiWhich.
// @fnv 0x008d4a80
int FUN_008d4a80_shell::MapActorValue(int aiWhich)
{
    if (ActorValue::GetFlag((ActorValue::Index)aiWhich, 0x400))
        return 0x2d;
    return aiWhich;
}

struct SFTX
{
    void SetFormType(int);
};
extern int DAT_01086f9c;
extern int DAT_01086fe4;
extern int DAT_01087014;
extern int DAT_0108704c;
extern int DAT_010870a0;
extern int DAT_010870ac;
struct FUN_0087d4a0
{
    FUN_0087d4a0(bool);
    ~FUN_0087d4a0();
    virtual void Dummy();
};
struct FUN_008d4500 : public FUN_0087d4a0
{
    FUN_008d4500(bool);
};
// @fnv 0x008d4500
FUN_008d4500::FUN_008d4500(bool abUnk) : FUN_0087d4a0(abUnk)
{
    *(void**)((char*)this + 0x18) = &DAT_010870a0;
    *(void**)((char*)this + 0x88) = &DAT_0108704c;
    *(void**)((char*)this + 0x94) = &DAT_01087014;
    *(void**)((char*)this + 0xa4) = &DAT_01086fe4;
    *(void**)((char*)this + 0xa8) = &DAT_01086f9c;
    ((SFTX*)this)->SetFormType(0x3c);
    *((char*)this + 0x1b4) = 0;
    *(float*)((char*)this + 0x1b8) = -1.0f;
    *(float*)((char*)this + 0x1bc) = -1.0f;
    *(int*)((char*)this + 0x140) = 0;
    *(int*)((char*)this + 0x13c) = 0;
}

// @fnv 0x008d44b0
unsigned char __fastcall GetByteAtOffset1B4(void* thisPtr)
{
    return *(unsigned char*)((char*)thisPtr + 0x1b4);
}

struct NiFixedString;
extern NiFixedString* DAT_011c6250;

// @fnv 0x008d4ca0
NiFixedString* FUN_008d4ca0()
{
    return DAT_011c6250;
}

struct NiFixedString;

extern NiFixedString* DAT_011c6258;

// @fnv 0x008d4cb0
NiFixedString* __cdecl FUN_008d4cb0()
{
    return DAT_011c6258;
}

struct FUN_008d4490_shell : Creature
{
    void SetRagdoll(bool bRagDoll);
};
// @fnv 0x008d4490
void FUN_008d4490_shell::SetRagdoll(bool bRagDoll)
{
    ((bool*)this)[0x1b4] = bRagDoll;
}

struct S008d48a0
{
    int MapActorValue(int, int);
    void FUN_008806d0(int);
    void FUN_008d48a0(int, int);
};
// Calls MapActorValue with a and b, then passes the result to FUN_008806d0.
// @fnv 0x008d48a0
void S008d48a0::FUN_008d48a0(int aiFirst, int aiSecond)
{
    this->FUN_008806d0(this->MapActorValue(aiFirst, aiSecond));
}

struct FUN_008d48d0_This
{
    int MapActorValue(int, float);
    void FUN_00880700(int);
    void FUN_008d48d0(int, float);
};
// Calls MapActorValue with aiWhich and aiValue, then passes the result to FUN_00880700.
// @fnv 0x008d48d0
void FUN_008d48d0_This::FUN_008d48d0(int aiWhich, float aiValue)
{
    FUN_00880700(MapActorValue(aiWhich, aiValue));
}

struct Unk008d49
{
    int MapActorValue(int, int, int);
    void FUN_00880950(int);
    void FUN_008d4900(int, int, int);
};
// Calls MapActorValue with a, b and c, then passes the result to FUN_00880950.
// @fnv 0x008d4900
void Unk008d49::FUN_008d4900(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00880950(MapActorValue(aiArg1, aiArg2, aiArg3));
}

struct FUN_008d4960_CLASS
{
    int MapActorValue(int, int, int);
    void FUN_00880c70(int);
    void FUN_008d4960(int, int, int);
};
// Computes a value from the three arguments via MapActorValue and passes the result to FUN_00880c70.
// @fnv 0x008d4960
void FUN_008d4960_CLASS::FUN_008d4960(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00880c70(MapActorValue(aiArg1, aiArg2, aiArg3));
}

struct Unk008d4a50
{
    int MapActorValue(int, float);
    void SetActorValue(int);
    void FUN_008d4a50(int, float);
};
// Calls MapActorValue with aiWhich and aiValue, then passes the result to SetActorValue.
// @fnv 0x008d4a50
void Unk008d4a50::FUN_008d4a50(int aiWhich, float aiValue)
{
    SetActorValue(MapActorValue(aiWhich, aiValue));
}

void _Deallocate(void*);
struct S
{
    void FUN_008d45f0();
    void* FUN_008d44d0(unsigned int);
};
// Calls FUN_008d45f0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x008d44d0
void* S::FUN_008d44d0(unsigned int flags)
{
    FUN_008d45f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESActorBase
{
    virtual ~TESActorBase();
};
struct TESCreature : TESActorBase
{
};
struct XActor
{
    TESActorBase* GetActorBase();
};
struct H008d46f0
{
    virtual void f0();
    virtual void f1();
    virtual int f2(int);
};
struct C008d46f0 : XActor
{
    char _pad[0xA3];
    H008d46f0 _h;
    float GetWeaponSkill();
};
// Casts the actor base to TESCreature and returns _h.f2(0x2D) as a float, or 0 if the cast fails.
// @fnv 0x008d46f0
float C008d46f0::GetWeaponSkill()
{
    TESCreature* pcreature;
    pcreature = dynamic_cast<TESCreature*>(GetActorBase());
    return (float)(pcreature ? _h.f2(0x2D) : 0);
}

struct Holder
{
    int MapActorValue(int, float, Actor*);
};
struct FUN_00880ad0_shell
{
    void FUN_00880ad0(int);
};
struct FUN_008d4930_shell
{
    void FUN_008d4930(int, float, Actor*);
};
// Calls MapActorValue with a, b and c, then passes the returned int to FUN_00880ad0 on this object.
// @fnv 0x008d4930
void FUN_008d4930_shell::FUN_008d4930(int aiArg, float afArg, Actor* apActor)
{
    ((FUN_00880ad0_shell*)this)->FUN_00880ad0(((Holder*)this)->MapActorValue(aiArg, afArg, apActor));
}

namespace fnv_008d4990 {
struct Holder
{
    int MapActorValue(int, float, int);
};
struct FUN_00880e00_OBJ
{
    void FUN_00880e00(int);
};
struct FUN_008d4990_OBJ : Holder
{
    void FUN_008d4990(int, float, int);
};
// Calls MapActorValue with the three arguments and passes its result to FUN_00880e00 on this object.
// @fnv 0x008d4990
void FUN_008d4990_OBJ::FUN_008d4990(int aiArg, float afArg, int aiArg2)
{
    ((FUN_00880e00_OBJ*)this)->FUN_00880e00(MapActorValue(aiArg, afArg, aiArg2));
}
}  // namespace fnv_008d4990

namespace fnv_008d49c0 {
struct Holder
{
    int MapActorValue(int, int, int);
    int FUN_00880fb0(int);
    void FUN_008d49c0(int, int, int);
};
// Calls MapActorValue with a, b and c, then passes the result to FUN_00880fb0.
// @fnv 0x008d49c0
void Holder::FUN_008d49c0(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00880fb0(MapActorValue(aiArg1, aiArg2, aiArg3));
}
}  // namespace fnv_008d49c0

namespace fnv_008d49f0 {
struct Holder
{
    int MapActorValue(int, float, void*);
    void ApplyActorValueDelta(int);
    void FUN_008d49f0(int, float, void*);
};
// Calls MapActorValue with the given arguments and passes its result to ApplyActorValueDelta.
// @fnv 0x008d49f0
void Holder::FUN_008d49f0(int aiArg, float afValue, void* a3)
{
    ApplyActorValueDelta(MapActorValue(aiArg, afValue, a3));
}
}  // namespace fnv_008d49f0

extern int DAT_011dffe4;

struct NiAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiAVObject* GetParent();
};

struct NiNode
{
    NiAVObject* FUN_0045bc00(unsigned int);
};

struct bhkCollisionObject;

bhkCollisionObject* __cdecl FUN_004a8b00(NiNode*);

struct FUN_008d4ab0_shell
{
    bool FUN_008d4ab0(NiAVObject*);
};

// @fnv 0x008d4ab0
bool FUN_008d4ab0_shell::FUN_008d4ab0(NiAVObject* apObject)
{
    bool bHasCollision = false;
    if (!apObject)
    {
        return false;
    }
    bhkCollisionObject* collision = FUN_004a8b00(reinterpret_cast<NiNode*>(apObject));
    ++DAT_011dffe4;
    if (collision)
    {
        bHasCollision = true;
    }
    else if (!collision && DAT_011dffe4 < 4)
    {
        NiAVObject* parent = apObject ? apObject->GetParent() : 0;
        if (parent)
        {
            bHasCollision = FUN_008d4ab0(reinterpret_cast<NiNode*>(parent)->FUN_0045bc00(0));
        }
    }
    --DAT_011dffe4;
    return bHasCollision;
}

namespace fnv_008c50f0 {
extern double _gModifierZero;

struct ShellH
{
    void FUN_00422750(bool, float);
};

struct XActor
{
    ShellH* GetExtra() const;
};

struct VProc
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
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
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
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
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
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
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
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
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
    virtual void v15a();
    virtual void v15b();
    virtual void v15c();
    virtual void v15d();
    virtual void v15e();
    virtual void v15f();
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
    virtual void v16a();
    virtual void v16b();
    virtual void v16c();
    virtual float vfunc_5b4();
};

struct TES
{
    VProc* GetLogDate();
};

void __cdecl FUN_00b68770(void*, bool, float, int, float, int);

struct FUN_008c50f0_shell
{
    void ApplyModifier(bool arg1, float arg2);
};

// @fnv 0x008c50f0
void FUN_008c50f0_shell::ApplyModifier(bool abEnabled, float afModifier)
{
    float f = afModifier;
    bool b;
    ShellH* val;

    if (abEnabled && f <= _gModifierZero)
    {
        if (((TES*)this)->GetLogDate())
        {
            f = ((TES*)this)->GetLogDate()->vfunc_5b4();
        }
    }

    b = abEnabled;
    if (b && f <= _gModifierZero)
    {
        b = false;
    }

    typedef void*(__thiscall * VFunc_1d0)(void*);
    FUN_00b68770(((VFunc_1d0)(*(void***)this)[0x1d0 / 4])(this), b, f, 0, 0.0f, 0);

    val = ((XActor*)this)->GetExtra();
    if (val)
    {
        val->FUN_00422750(b, afModifier);
    }
}
}  // namespace fnv_008c50f0

extern double _gModifierZero;

struct FUN_0087d880_class
{
    float FUN_0087d880();
};

struct SubA4
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual float vfunc_10(int av);
    virtual float vfunc_14(int av);
    virtual float vfunc_18(int av);
};

struct FUN_008d4cc0_shell
{
    char pad[0x1b8];
    float m_fFirstResetValue;

    float FUN_008d4cc0();
};

// Returns the cached modifier if non-negative; otherwise computes it from FUN_0087d880 and the SubA4 vfuncs at index 0x12, caching and returning the result.
// @fnv 0x008d4cc0
float FUN_008d4cc0_shell::FUN_008d4cc0()
{
    if (m_fFirstResetValue >= _gModifierZero)
        return m_fFirstResetValue;

    int f = 0x12;
    float temp = ((FUN_0087d880_class*)this)->FUN_0087d880();
    bool b = false;
    typedef float(__thiscall * VFunc_48c)(void*, int, bool*);
    float val = ((VFunc_48c)(*(void***)this)[0x48c / 4])(this, f, &b);
    if (b)
    {
        temp = val;
    }

    m_fFirstResetValue =
        (((((SubA4*)((char*)this + 0xa4))->vfunc_18(f) + temp) + ((SubA4*)((char*)this + 0xa4))->vfunc_10(f)) +
         ((SubA4*)((char*)this + 0xa4))->vfunc_14(f));
    return m_fFirstResetValue;
}

namespace fnv_008d4db0 {
extern double _gModifierZero;

struct FUN_0087d880_class
{
    float FUN_0087d880();
};

struct SubA4
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual float vfunc_14(int av);
    virtual float vfunc_18(int av);
};

struct FUN_008d4db0_shell
{
    char pad[0x1bc];
    float m_fSecondValue;

    float FUN_008d4db0();
};

// @fnv 0x008d4db0
float FUN_008d4db0_shell::FUN_008d4db0()
{
    if (m_fSecondValue >= _gModifierZero)
        return m_fSecondValue;

    int f = 0x4c;
    float temp = ((FUN_0087d880_class*)this)->FUN_0087d880();
    bool b = false;
    typedef float(__thiscall * VFunc_48c)(void*, int, bool*);
    float val = ((VFunc_48c)(*(void***)this)[0x48c / 4])(this, f, &b);
    if (b)
    {
        temp = val;
    }

    m_fSecondValue =
        (((SubA4*)((char*)this + 0xa4))->vfunc_18(f) + temp) + ((SubA4*)((char*)this + 0xa4))->vfunc_14(f);
    return m_fSecondValue;
}
}  // namespace fnv_008d4db0

struct NiControllerManager
{
    virtual void vm000();
    virtual void vm001();
    virtual void vm002();
    virtual void vm003();
    virtual void vm004();
    virtual void vm005();
    virtual void vm006();
    virtual void vm007();
    virtual void vm008();
    virtual void vm009();
    virtual void vm010();
    virtual void vm011();
    virtual void vm012();
    virtual void vm013();
    virtual void vm014();
    virtual void vm015();
    virtual void vm016();
    virtual void vm017();
    virtual void vm018();
    virtual void vm019();
    virtual void vm020();
    virtual void vm021();
    virtual void vm022();
    virtual void vm023();
    virtual void vm024();
    virtual void vm025();
    virtual void vm026();
    virtual void vm027();
    virtual void vm028();
    virtual void vm029();
    virtual void vm030();
    virtual void vm031();
    virtual void vm032();
    virtual void vm033();
    virtual void vm034();
    virtual NiAVObject* GetObjectByName(NiFixedString* name);
    NiControllerManager* GetStringAtOffset();
};
struct ActorAnimData
{
    NiControllerManager* FUN_00496940();
};
struct CreatureFlags30
{
    virtual void vs000();
    virtual void vs001();
    virtual void vs002();
    virtual void vs003();
    virtual void vs004();
    virtual void vs005();
    virtual void vs006();
    virtual void vs007();
    virtual void vs008();
    virtual void vs009();
    virtual void vs010();
    virtual void vs011();
    virtual void vs012();
    virtual void vs013();
    virtual bool vf38();
    virtual bool vf3c();
    virtual bool vf40();
};
struct CreatureViewQ
{
    char pad[0x30];
    CreatureFlags30 m30;
};
NiFixedString* FUN_008a30f0();
NiFixedString* FUN_008d4ca0();
NiFixedString* FUN_008d4cb0();
void FUN_0062bc10(NiAVObject* obj);
struct XActorQ
{
    virtual void vx000();
    virtual void vx001();
    virtual void vx002();
    virtual void vx003();
    virtual void vx004();
    virtual void vx005();
    virtual void vx006();
    virtual void vx007();
    virtual void vx008();
    virtual void vx009();
    virtual void vx010();
    virtual void vx011();
    virtual void vx012();
    virtual void vx013();
    virtual void vx014();
    virtual void vx015();
    virtual void vx016();
    virtual void vx017();
    virtual void vx018();
    virtual void vx019();
    virtual void vx020();
    virtual void vx021();
    virtual void vx022();
    virtual void vx023();
    virtual void vx024();
    virtual void vx025();
    virtual void vx026();
    virtual void vx027();
    virtual void vx028();
    virtual void vx029();
    virtual void vx030();
    virtual void vx031();
    virtual void vx032();
    virtual void vx033();
    virtual void vx034();
    virtual void vx035();
    virtual void vx036();
    virtual void vx037();
    virtual void vx038();
    virtual void vx039();
    virtual void vx040();
    virtual void vx041();
    virtual void vx042();
    virtual void vx043();
    virtual void vx044();
    virtual void vx045();
    virtual void vx046();
    virtual void vx047();
    virtual void vx048();
    virtual void vx049();
    virtual void vx050();
    virtual void vx051();
    virtual void vx052();
    virtual void vx053();
    virtual void vx054();
    virtual void vx055();
    virtual void vx056();
    virtual void vx057();
    virtual void vx058();
    virtual void vx059();
    virtual void vx060();
    virtual void vx061();
    virtual void vx062();
    virtual void vx063();
    virtual void vx064();
    virtual void vx065();
    virtual void vx066();
    virtual void vx067();
    virtual void vx068();
    virtual void vx069();
    virtual void vx070();
    virtual void vx071();
    virtual void vx072();
    virtual void vx073();
    virtual void vx074();
    virtual void vx075();
    virtual void vx076();
    virtual void vx077();
    virtual void vx078();
    virtual void vx079();
    virtual void vx080();
    virtual void vx081();
    virtual void vx082();
    virtual void vx083();
    virtual void vx084();
    virtual void vx085();
    virtual void vx086();
    virtual void vx087();
    virtual void vx088();
    virtual void vx089();
    virtual void vx090();
    virtual void vx091();
    virtual void vx092();
    virtual void vx093();
    virtual void vx094();
    virtual void vx095();
    virtual void vx096();
    virtual void vx097();
    virtual void vx098();
    virtual void vx099();
    virtual void vx100();
    virtual void vx101();
    virtual void vx102();
    virtual void vx103();
    virtual void vx104();
    virtual void vx105();
    virtual void vx106();
    virtual void vx107();
    virtual void vx108();
    virtual void vx109();
    virtual void vx110();
    virtual void vx111();
    virtual void vx112();
    virtual void vx113();
    virtual void vx114();
    virtual void vx115();
    virtual void vx116();
    virtual void vx117();
    virtual void vx118();
    virtual void vx119();
    virtual void vx120();
    virtual ActorAnimData* GetAnimData();
    void FUN_008d4b60();
};
// For each set creature flag, looks up an object through the controller manager and passes it to FUN_0062bc10.
// @fnv 0x008d4b60
void XActorQ::FUN_008d4b60()
{
    TESCreature* pCreature = dynamic_cast<TESCreature*>(((XActor*)(void*)this)->GetActorBase());
    if (!pCreature)
        return;
    ActorAnimData* pAnimData = GetAnimData();
    if (pAnimData)
    {
        if (!pAnimData->FUN_00496940())
            return;
        NiControllerManager* pManager = pAnimData->FUN_00496940()->GetStringAtOffset();
        if (((CreatureViewQ*)pCreature)->m30.vf38())
        {
            NiAVObject* pObject = pManager->GetObjectByName(FUN_008d4ca0());
            FUN_0062bc10(pObject);
        }
        if (((CreatureViewQ*)pCreature)->m30.vf3c())
        {
            NiAVObject* pObject = pManager->GetObjectByName(FUN_008d4cb0());
            FUN_0062bc10(pObject);
        }
        if (((CreatureViewQ*)pCreature)->m30.vf40())
        {
            NiAVObject* pObject = pManager->GetObjectByName(FUN_008a30f0());
            FUN_0062bc10(pObject);
        }
    }
}

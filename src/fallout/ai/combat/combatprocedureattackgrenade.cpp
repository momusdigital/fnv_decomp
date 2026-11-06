
// src/fallout/ai/combat/combatprocedureattackgrenade.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattackgrenade.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CombatProcedure
{
    void RunProcedure();
};

struct CombatProcedureAttackGrenade : CombatProcedure
{
    void Shutdown();
};

// @fnv 0x009cafc0
void CombatProcedureAttackGrenade::Shutdown()
{
    CombatProcedure::RunProcedure();
}

struct FUN_009cb440_shell
{
    void __thiscall FUN_009cb440(unsigned char b);
};

// @fnv 0x009cb440
void __thiscall FUN_009cb440_shell::FUN_009cb440(unsigned char b)
{
    *reinterpret_cast<unsigned char*>(this + 0x73) = b;
}

void __cdecl Deallocate(void*);

struct FUN_009caeb0_shell
{
    void __thiscall FUN_009cafa0();
    void* __thiscall FUN_009caeb0(unsigned int flags);
};

// Calls FUN_009cafa0, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009caeb0
void* __thiscall FUN_009caeb0_shell::FUN_009caeb0(unsigned int flags)
{
    FUN_009cafa0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_010909bc;
struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};
struct FUN_009cafa0_shell
{
    void FUN_009cafa0();
};
// @fnv 0x009cafa0
void FUN_009cafa0_shell::FUN_009cafa0()
{
    *reinterpret_cast<int**>(this) = &DAT_010909bc;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->FUN_009ca6c0();
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting375;
struct Projectile
{
    void __thiscall FUN_00966a00(float);
};
struct IMH
{
    struct FUN_009cb440_shell* FUN_00586150();
};
struct Helper_caae0
{
    void __thiscall SetState();
};
struct FUN_009cb830_shell
{
    void __thiscall FUN_009cb830(Projectile* apProjectile);
};
// @fnv 0x009cb830
void __thiscall FUN_009cb830_shell::FUN_009cb830(Projectile* apProjectile)
{
    if (*(bool*)((char*)this + 0x30))
    {
        apProjectile->FUN_00966a00(*originalRuntimeFloatSetting375.Float());
    }
    *(bool*)((char*)this + 0x30) = 0;
    if (*(bool*)((char*)this + 0x14))
    {
        (*(IMH**)((char*)this + 4))->FUN_00586150()->FUN_009cb440(1);
        ((Helper_caae0*)this)->SetState();
    }
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void* p, int a, int b);
};
struct FUN_009a5eb0_shell
{
    void __thiscall FUN_009a5eb0(BGSSaveFormBuffer* p);
};
struct CombatProcedureSaveGameShell
{
    void __thiscall SaveGame(BGSSaveFormBuffer* p);
};
struct FUN_009cb9c0_shell
{
    void __thiscall FUN_009cb9c0(BGSSaveFormBuffer* p);
};
// @fnv 0x009cb9c0
void __thiscall FUN_009cb9c0_shell::FUN_009cb9c0(BGSSaveFormBuffer* pBuffer)
{
    ((CombatProcedureSaveGameShell*)this)->SaveGame(pBuffer);
    pBuffer->SaveData((char*)this + 0x10, 4, 0);
    pBuffer->SaveData((char*)this + 0x14, 1, 0);
    pBuffer->SaveData((char*)this + 0x18, 0xc, 0);
    pBuffer->SaveData((char*)this + 0x24, 0xc, 0);
    pBuffer->SaveData((char*)this + 0x30, 1, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x34))->FUN_009a5eb0(pBuffer);
}

struct BGSLoadFormBuffer
{
    void __thiscall ReadTypedData(void* p, unsigned int size);
};
struct CombatProcedure_LoadGame
{
    void __thiscall LoadGame(BGSLoadFormBuffer* p);
};
struct TimeoutTimer
{
    void __thiscall LoadGame(BGSLoadFormBuffer* p);
};
struct FUN_009cba50_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_aa;
    int m_ab;
    int m_ac;
    int m_ad;
    int m_ae;
    int m_af;
    int m_ag;
    int m_ah;
    int m_ai;
    int m_aj;
    int m_ak;
    int m_al;
    int m_am;
    int m_an;
    int m_ao;
    int m_ap;
    int m_aq;
    int m_ar;
    int m_as;
    int m_at;
    int m_au;
    int m_av;
    int m_aw;
    int m_ax;
    int m_ay;
    int m_az;
    void __thiscall FUN_009cba50(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009cba50
void __thiscall FUN_009cba50_shell::FUN_009cba50(BGSLoadFormBuffer* buffer)
{
    ((CombatProcedure_LoadGame*)this)->LoadGame(buffer);
    buffer->ReadTypedData((char*)this + 0x10, 4);
    buffer->ReadTypedData((char*)this + 0x14, 1);
    buffer->ReadTypedData((char*)this + 0x18, 0xc);
    buffer->ReadTypedData((char*)this + 0x24, 0xc);
    buffer->ReadTypedData((char*)this + 0x30, 1);
    ((TimeoutTimer*)((char*)this + 0x34))->LoadGame(buffer);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    void __thiscall FUN_006815c0();
};
struct NonPodPoint3
{
    float x;
    float y;
    float z;
    NonPodPoint3();
};
NiPoint3* __cdecl FUN_009a8050(NiPoint3* result, void* actor);
void __cdecl GetTargetLocationWithOffset(NiPoint3* result, void* target, int mode);
NonPodPoint3 __cdecl GetTriple12(void* target);
unsigned char __cdecl FUN_009a7670(void* actor, void* target, unsigned int flags, NiPoint3 origin, NiPoint3 direction,
                                   NonPodPoint3 offset, unsigned int mode, unsigned int category, float scale);

// @fnv 0x009a7580
unsigned char __cdecl FUN_009a7580(void* actor, void* target, unsigned int flags, NiPoint3* optionalOrigin,
                                   unsigned int mode, unsigned int category, float scale)
{
    if (!actor || !target)
        return 0;
    NiPoint3 offset;
    offset.FUN_006815c0();
    if (optionalOrigin)
        offset = *optionalOrigin;
    else
    {
        NiPoint3 temp;
        offset = *FUN_009a8050(&temp, actor);
    }
    NiPoint3 origin;
    GetTargetLocationWithOffset(&origin, target, 2);
    NonPodPoint3 direction = GetTriple12(target);
    return FUN_009a7670(actor, target, flags, offset, origin, direction, mode, category, scale);
}

struct Vec3
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

extern int DAT_010909bc;
extern Vec3 DAT_011f426c;

struct CombatBaseObj
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    CombatBaseObj();
};

struct CombatMember34
{
    int m_00;
    void Init();
    ~CombatMember34();
};

struct FUN_009cadf0_cls : CombatBaseObj
{
    int m_10;
    unsigned char m_14;
    Vec3 m_18;
    Vec3 m_24;
    unsigned char m_30;
    CombatMember34 m_34;
    FUN_009cadf0_cls();
};

// Initialises the object: sets the vtable, zeroes m_10/m_14/m_30, copies DAT_011f426c into m_18 and m_24, and calls m_34.Init().
// @fnv 0x009cadf0
FUN_009cadf0_cls::FUN_009cadf0_cls()
{
    m_vptr = &DAT_010909bc;
    m_10 = 0;
    m_14 = 0;
    m_18 = DAT_011f426c;
    m_24 = DAT_011f426c;
    m_30 = 0;
    m_34.Init();
}

namespace fnv_009caee0 {
struct Vec3_b6365
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

extern Vec3_b6365 DAT_011f426c;

class Base_b6365
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    Base_b6365();
    ~Base_b6365();
};

class Member_b6365
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    void Reset();
};

class FUN_009caee0 : public Base_b6365
{
  public:
    virtual ~FUN_009caee0();
    unsigned char m_14;
    Vec3_b6365 m_18;
    Vec3_b6365 m_24;
    unsigned char m_30;
    Member_b6365 m_34;

    FUN_009caee0(const Vec3_b6365* src, unsigned char flag);
};

// Initialises the object: stores a copy of src into m_18, sets m_24 from DAT_011f426c, m_14 to 1, m_30 to flag, and resets m_34.
// @fnv 0x009caee0
FUN_009caee0::FUN_009caee0(const Vec3_b6365* src, unsigned char flag) : Base_b6365()
{
    m_10 = 0;
    m_14 = 1;
    m_18 = *src;
    m_24 = DAT_011f426c;
    m_30 = flag;
    m_34.Reset();
}
}  // namespace fnv_009caee0

class B9CB380Form;
class B9CB380Mobile;

class B9CB380Process
{
  public:
    void SetTarget(B9CB380Form* pkForm);
    void FUN_009cb440(bool bFlag);
};

class B9CB380Actor
{
  public:
    B9CB380Mobile* GetMobile();
    B9CB380Process* GetProcess();
};

class B9CB380World
{
  public:
    bool IsThreatWithinLimits(B9CB380Mobile* pkMobile, B9CB380Form* pkForm, int iArg, float fArg);
};

class B9CB380Setting
{
  public:
    float* Float();
};

class B9CB380Timer
{
  public:
    bool FUN_0097fa50();
    bool FUN_008d7f80();
    void FUN_008d7f40(float fTime);

    int unk00;
};

extern B9CB380World* g_pkB9CB380World;
extern B9CB380Setting g_kB9CB380Setting;

class B9CB380Package
{
  public:
    int unk00;
    B9CB380Actor* m_pkActor;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bFlag14;
    char unk15;
    short unk16;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B9CB380Timer m_kTimer;

    void SetState();
    bool FUN_009cb380(B9CB380Form* pkForm, int iArg, float fArg);
};

// @fnv 0x009cb380
bool B9CB380Package::FUN_009cb380(B9CB380Form* pkForm, int iArg, float fArg)
{
    B9CB380Mobile* pkMobile2 = m_pkActor->GetMobile();
    B9CB380Process* pkProcess = m_pkActor->GetProcess();
    if (!g_pkB9CB380World->IsThreatWithinLimits(pkMobile2, pkForm, iArg, fArg))
    {
        if (!m_kTimer.FUN_0097fa50())
            m_kTimer.FUN_008d7f40(*g_kB9CB380Setting.Float());
        else if (m_kTimer.FUN_008d7f80())
            pkProcess->SetTarget(pkForm);
        if (m_bFlag14)
        {
            pkProcess->FUN_009cb440(true);
            SetState();
        }
        return false;
    }
    return true;
}

namespace fnv_009cb6e0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
};
extern const NiPoint3 NiPoint3_ZERO;

extern Setting_S originalRuntimeFloatSetting375;

struct Actor;
struct PathingRequest
{
    float GetFloatAtOffset68();
};
struct TESObjectREFR
{
    PathingRequest* GetOrFallback(Actor* actor);
};
struct InterfaceManager
{
    TESObjectREFR* FUN_007031c0();
};

NiPoint3 __cdecl ComputeTrajectory(Actor* actor, void* target, int unused, PathingRequest* req, float dist, bool flag);
NiPoint3 __cdecl FUN_009a8d80(Actor* actor, NiPoint3* point, int unused, PathingRequest* req, float dist, bool flag);

struct CombatProcedureShell
{
    int unk00;
    InterfaceManager* unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool b14;
    NiPoint3 pt18;
    int unk24;
    int unk28;
    int unk2C;
    bool b30;

    Actor* FUN_00996de0();
    void* FUN_00996e00();
    NiPoint3 GetPathingPoint();
};

// @fnv 0x009cb6e0
NiPoint3 CombatProcedureShell::GetPathingPoint()
{
    if (!b14 && !FUN_00996e00())
    {
        return NiPoint3_ZERO;
    }
    TESObjectREFR* ref = unk04->FUN_007031c0();
    PathingRequest* req = ref->GetOrFallback(FUN_00996de0());
    float dist = req->GetFloatAtOffset68() * (b30 ? *originalRuntimeFloatSetting375.Float() : 1.0f);
    NiPoint3 point;
    if (!b14)
    {
        point = ComputeTrajectory(FUN_00996de0(), FUN_00996e00(), 0, req, dist, b30);
    }
    else
    {
        point = FUN_009a8d80(FUN_00996de0(), &pt18, 0, req, dist, b30);
    }
    return point;
}
}  // namespace fnv_009cb6e0

struct Point
{
    float x, y, z;
    Point();
};
struct Target
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
    virtual Point* Position();
};
struct Item
{
    void* Sound();
};
struct Manager
{
    Item* Select(void*);
};
struct Process
{
    void Set(unsigned char);
};
struct Owner
{
    Manager* ManagerGet();
    Process* ProcessGet();
};
struct Procedure
{
    int unk00;
    Owner* owner;
    int unk08, unk0c, unk10;
    unsigned char active;
    Point origin;
    Point destination;
    unsigned char category;
    void* ActorGet();
    Target* TargetGet();
    bool Validate(void*, Point*, float);
    void Reset();
    bool GetTargetedPoint(Point* output, Point* input);
};
extern Point zeroPoint;
extern const float scaleValue;
unsigned char Arc(void*, Target*, Item*, Point, Point, Point, unsigned char*, Point*, float);
unsigned char Direct(void*, Target*, Item*, Point*, unsigned char*, Point*, float);
float Distance(Item*, Point, Point, unsigned char, float);
// @fnv 0x009cb460
bool Procedure::GetTargetedPoint(Point* output, Point* input)
{
    void* i;
    i = ActorGet();
    Target* targetVal;
    targetVal = TargetGet();
    Manager* sound;
    sound = owner->ManagerGet();
    Item* z;
    z = sound->Select(i);
    void* pForm;
    pForm = z->Sound();
    bool ptr;
    ptr = false;
    if (active)
    {
        if (Arc(i, targetVal, z, *input, origin, zeroPoint, &category, &destination, scaleValue))
        {
            *output = destination;
            ptr = true;
        }
    }
    else
    {
        if (Direct(ActorGet(), TargetGet(), sound->Select(i), input, &category, &destination, scaleValue))
        {
            *output = destination;
            ptr = true;
        }
    }
    if (ptr && pForm)
    {
        Point position7;
        if (active)
            position7 = origin;
        else
        {
            position7 = destination;
            position7.z = targetVal->Position()->z;
        }
        float distance7;
        distance7 = Distance(z, *input, position7, category, 0.0f);
        if (!Validate(pForm, &position7, distance7))
            ptr = false;
    }
    if (!ptr && active)
    {
        owner->ProcessGet()->Set(1);
        Reset();
    }
    return ptr;
}

namespace fnv_009cafe0 {
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3* FUN_00439ef0(Pt3* out, Pt3* other);
    float GetSquaredXYLength();
    bool FUN_00439090(Pt3* other);
};

struct Obj70
{
    int GetSlotValue(int a);
};
struct ProcessObj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual bool vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c(int a);
};
struct ActorObj
{
    bool FUN_00894900();
    int FUN_008a7570();
    ProcessObj* FUN_008d8520();
    bool TryAttack(int a);
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual Obj70* vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual Pt3* vfn_1f4();
};
struct SoundObj
{
    int s00;
};
struct MidObj
{
    SoundObj* FUN_004fd3c0();
};
struct Obj703
{
    MidObj* GetOrFallback(ActorObj* a);
};
struct Obj586
{
    bool FUN_0097ee90();
    bool FUN_008b3c10();
    void FUN_00442a80(int a);
};
struct Sub04
{
    Obj586* FUN_00586150();
    Obj703* FUN_007031c0();
    bool FUN_00981970();
};
struct GlobalObj
{
    void FUN_00983970(void* a, int b, int c, int d);
};
extern GlobalObj* DAT_011f1708;
struct Member34
{
    void FUN_00910b10();
};
void __cdecl FUN_009a9180(Sub04* a, Obj703* b, float* x, float* y, float* z);
unsigned char __cdecl FUN_009a7580(ActorObj* a, ActorObj* b, MidObj* c, void* d, unsigned char* e, Pt3* f, float g);
bool __cdecl IsExplosionRadiusValid(SoundObj* a);

struct Package
{
    int unk00;
    Sub04* m_04;
    int unk08;
    int unk0c;
    int m_10;
    unsigned char m_14;
    unsigned char m_15;
    short m_16;
    Pt3 m_18;
    Pt3 m_24;
    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char m_33;
    Member34 m_34;
    ActorObj* FUN_00996de0();
    ActorObj* FUN_00996e00();
    void FUN_009caac0(const char* msg);
    void FUN_00996ea0();
    void SetLookAtPoint(Pt3* p, int a);
    Pt3* GetPathingPoint(Pt3* out);
    bool FUN_009cb380(SoundObj* s, Pt3* p, float f);
    void UpdateWeaponFire();
};

// @fnv 0x009cafe0
void Package::UpdateWeaponFire()
{
    ActorObj* actor2;
    actor2 = FUN_00996de0();
    ActorObj* i;
    i = FUN_00996e00();
    Obj586* n;
    n = m_04->FUN_00586150();
    Obj703* s;
    s = m_04->FUN_007031c0();
    Obj70* aPObj;
    aPObj = actor2->vfn_1e4();
    if (!s || !aPObj || !s->GetOrFallback(actor2))
    {
        FUN_009caac0("Missing either weapon, animation, or weapon projectile");
        return;
    }
    if (actor2->FUN_00894900())
    {
        m_10 = 1;
    }
    else if (actor2->FUN_008a7570() == -1)
    {
        m_10 = 0;
    }
    if (!m_14 && !m_10)
    {
        m_30 = 0;
    }
    if (!n->FUN_0097ee90() || n->FUN_008b3c10())
    {
        if (m_10)
        {
            FUN_00996ea0();
            m_10 = 0;
        }
        return;
    }
    DAT_011f1708->FUN_00983970(m_04, 2, 0, 0);
    Pt3 AJ;
    m_24 = *GetPathingPoint(&AJ);
    Pt3 dir3;
    dir3.x = 0.0f;
    dir3.y = 0.0f;
    dir3.z = 0.0f;
    FUN_009a9180(m_04, s, &dir3.x, &dir3.y, &dir3.z);
    Pt3 kIter;
    m_24.FUN_00439ef0(&kIter, actor2->vfn_1f4());
    if (kIter.GetSquaredXYLength() > dir3.z * dir3.z)
    {
        FUN_00996ea0();
        m_10 = 0;
        return;
    }
    if (m_24.FUN_00439090((Pt3*)&DAT_011f426c))
    {
        SetLookAtPoint(&m_24, 4);
    }
    if (1 == m_10 && (actor2->FUN_008a7570() != 4 || aPObj->GetSlotValue(4) > 2))
    {
        return;
    }
    if (!actor2->FUN_008d8520()->vfn_3f8() || m_04->FUN_00981970())
    {
        return;
    }
    SoundObj* idx;
    idx = s->GetOrFallback(actor2)->FUN_004fd3c0();
    Pt3* AP;
    Pt3 CTmp;
    if (idx)
    {
        AP = m_14 ? &m_18 : i->vfn_1f4();
        CTmp = *AP;
        if (!FUN_009cb380(idx, &CTmp, 0.0f))
        {
            return;
        }
    }
    MidObj* pForm;
    pForm = s->GetOrFallback(actor2);
    if (!m_14)
    {
        if (!FUN_009a7580(actor2, i, pForm, 0, &m_30, &m_24, -1.0f))
        {
            return;
        }
    }
    if (idx)
    {
        n->FUN_00442a80(0);
        m_34.FUN_00910b10();
    }
    actor2->FUN_008d8520()->vfn_43c(1);
    actor2->TryAttack(0x72);
    m_10 = 1;
    if (idx && IsExplosionRadiusValid(idx))
    {
        DAT_011f1708->FUN_00983970(m_04, 2, 4, 1);
    }
}
}  // namespace fnv_009cafe0

struct IDebugText
{
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void __cdecl Write(int location, int justify, const char* format, ...);
};

struct CTSHelper
{
    float __thiscall GetElapsedTime();
};

struct Modifier
{
    bool __thiscall FUN_0097fa50();
    float __thiscall GetValue();
};

struct FUN_009cb890_shell
{
    void __thiscall WriteDebugText(IDebugText* debugText, int location, int justify);
};

// Writes debug lines for the state, targeted point, high-arc flag and blocked-timer values via debugText->Write.
// @fnv 0x009cb890
void FUN_009cb890_shell::WriteDebugText(IDebugText* debugText, int location, int justify)
{
    switch (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10))
    {
    case 0:
        debugText->Write(location, justify, "IDLE");
        break;
    case 1:
        debugText->Write(location, justify, "ATTACKING");
        break;
    }

    debugText->Write(location, justify, "Targeted Point: %.02f, %.02f, %.02f",
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x24),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x28),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x2c));

    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x30))
    {
        debugText->Write(location, justify, "HIGH ARC");
    }

    if (reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)->FUN_0097fa50())
    {
        debugText->Write(location, justify, "Explosive Projectile Blocked Timer: %.02f/%.02f",
                         reinterpret_cast<CTSHelper*>(reinterpret_cast<unsigned char*>(this) + 0x34)->GetElapsedTime(),
                         reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)->GetValue());
    }
}

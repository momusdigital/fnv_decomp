
// src/fallout/ai/combat/combatprocedurehidefromtarget.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedurehidefromtarget.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CombatProcedure
{
    enum COMBAT_PROCEDURES
    {
        eHideFromTarget = 9
    };
};

struct CombatProcedureHideFromTarget : CombatProcedure
{
    COMBAT_PROCEDURES GetType();
};

// @fnv 0x009d60e0
CombatProcedure::COMBAT_PROCEDURES CombatProcedureHideFromTarget::GetType()
{
    return eHideFromTarget;
}

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};

struct FUN_009d6120_shell
{
    void FUN_009d6120();
};

// @fnv 0x009d6120
void __thiscall FUN_009d6120_shell::FUN_009d6120()
{
    *reinterpret_cast<int*>(this) = 0x01091a64;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->FUN_009ca6c0();
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_009d60f0_shell : public FUN_009d6120_shell
{
    void* FUN_009d60f0(unsigned int flags);
};

// Calls FUN_009d6120, then deallocates this object if flags has bit 0 set, and returns this.
// @fnv 0x009d60f0
void* FUN_009d60f0_shell::FUN_009d60f0(unsigned int flags)
{
    FUN_009d6120();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_009ca680
{
    void* m_vtbl;
    int m_iWordAt04, m_8, m_iThirdValue;
    FUN_009ca680();
    ~FUN_009ca680();
};

struct FUN_00906f60
{
    int m_iWordAt00, m_iWordAt04;
    FUN_00906f60();
};

struct FUN_006815c0
{
    int m_iWordAt00, m_iWordAt04, m_8;
    FUN_006815c0();
};

extern "C" char DAT_01091a64[];

struct FUN_009d6030 : FUN_009ca680
{
    int m_10;
    float m_14;
    FUN_00906f60 m_18;
    FUN_006815c0 m_20;
    FUN_006815c0 m_2c;
    int m_38;
    bool m_3c;
    bool m_3d;
    FUN_009d6030(int a, float b, bool c, bool d);
};

// Constructor: sets the vtable, initializes m_10 to 0, stores b in m_14, a in m_38, c in m_3c and d in m_3d.
// @fnv 0x009d6030
FUN_009d6030::FUN_009d6030(int aiValue, float afValue, bool abFlag1, bool abFlag2)
    : m_10((m_vtbl = DAT_01091a64, 0)), m_14(afValue)
{
    m_38 = aiValue;
    m_3c = abFlag1;
    m_3d = abFlag2;
}

struct S_009d6750_Output
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void Printf(int x, int y, const char* fmt, ...);
    virtual void vf18();
};

struct S_009d6750_Timer
{
    float FUN_00435e00();
    float FUN_006b9130();
};

struct S_009d6750 : CombatProcedureHideFromTarget
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int m_uiContentCount;
    int unk14;
    S_009d6750_Timer m_timer;
    void PrintState(S_009d6750_Output* out, int x, int y);
};

// @fnv 0x009d6750
void S_009d6750::PrintState(S_009d6750_Output* out, int x, int y)
{
    switch (m_uiContentCount)
    {
    case 0:
        out->Printf(x, y, "INITIALIZING");
        break;
    case 1:
        out->Printf(x, y, "MOVING_TO_COVER");
        break;
    case 2:
        out->Printf(x, y, "HIDING");
        out->Printf(x, y, "Hiding Timer: %.02f/%.02f", m_timer.FUN_00435e00(), m_timer.FUN_006b9130());
        break;
    }
}

struct BGSLoadFormBuffer
{
    void FUN_00864980(void* destination, unsigned int size);
};
struct FUN_00996ef0_shell
{
    void FUN_00996ef0(BGSLoadFormBuffer* stream);
};
struct FUN_009a5f20_shell
{
    float x;
    float y;
    void FUN_009a5f20(BGSLoadFormBuffer* stream);
};
struct FUN_009d6c80_shell
{
    FUN_009d6c80_shell* FUN_00586150();
};
struct FUN_0097fb60_shell
{
    unsigned int GetFieldAtE8();
};
unsigned int __fastcall GetFieldValue(void* object);
struct Float3
{
    float x;
    float y;
    float z;
};
struct HideTargetLayout
{
    void* unk00;
    FUN_009d6c80_shell* owner;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_009a5f20_shell unk18;
    Float3 unk20;
    Float3 unk2C;
    unsigned int state;
    unsigned char unk3C;
    unsigned char unk3D;
    void Load(BGSLoadFormBuffer* stream);
};
// Reads the hide target's fields from the stream and sets state from the owner when the trailing tag is 1 or 2.
// @fnv 0x009d6900
void HideTargetLayout::Load(BGSLoadFormBuffer* stream)
{
    ((FUN_00996ef0_shell*)this)->FUN_00996ef0(stream);
    stream->FUN_00864980(&unk10, 4);
    stream->FUN_00864980(&unk14, 4);
    unk18.FUN_009a5f20(stream);
    stream->FUN_00864980(&unk20, 12);
    stream->FUN_00864980(&unk2C, 12);
    stream->FUN_00864980(&unk3C, 1);
    stream->FUN_00864980(&unk3D, 1);
    unsigned char tag = 0;
    stream->FUN_00864980(&tag, 1);
    if (tag == 2)
    {
        state = ((FUN_0097fb60_shell*)owner->FUN_00586150())->GetFieldAtE8();
    }
    else if (tag == 1)
    {
        state = GetFieldValue(owner->FUN_00586150());
    }
}

struct Archive
{
    void FUN_00865e50(void* apData, unsigned int aSize, int aFlags);
};

struct Block12
{
    int unk00;
    int unk04;
    int unk08;
};

struct Sub18
{
    int unk00;
    int unk04;
    void FUN_009a5eb0(Archive* apArchive);
};

struct Handle
{
    int GetFieldAtE8();
};

struct Owner04
{
    Handle* FUN_00586150();
};

struct BaseNode
{
    void SaveToBuffer(Archive* apArchive);
};

struct FUN_009d6820_cls : BaseNode
{
    int unk00;
    Owner04* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Sub18 unk18;
    Block12 unk20;
    Block12 unk2c;
    int unk38;
    unsigned char unk3c;
    unsigned char unk3d;

    void Serialize(Archive* apArchive);
};

// Serializes the base node and its fields to the archive, then writes a state byte derived from comparing unk38 with a handle value.
// @fnv 0x009d6820
void FUN_009d6820_cls::Serialize(Archive* apArchive)
{
    unsigned char state;
    this->SaveToBuffer(apArchive);
    apArchive->FUN_00865e50(&unk10, 4, 0);
    apArchive->FUN_00865e50(&unk14, 4, 0);
    unk18.FUN_009a5eb0(apArchive);
    apArchive->FUN_00865e50(&unk20, 12, 0);
    apArchive->FUN_00865e50(&unk2c, 12, 0);
    apArchive->FUN_00865e50(&unk3c, 1, 0);
    apArchive->FUN_00865e50(&unk3d, 1, 0);
    state = 0;
    if (unk38 != 0)
    {
        state = (unk38 == unk04->FUN_00586150()->GetFieldAtE8()) ? 2 : 1;
    }
    apArchive->FUN_00865e50(&state, 1, 0);
}

struct Vec
{
    Vec();
    Vec(const Vec&);
    float x, y, z;
    Vec operator-(const Vec&) const;
    float FUN_004a7290() const;
};
struct WorldPos
{
    int a, b, c, d;
    double distance(const WorldPos&);
};
struct Clock
{
    int a, b;
    void FUN_008d7f40(float);
    bool expired();
    float elapsed();
};
struct Request
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    Request();
    ~Request();
    void SetInitialPathHeading(float);
};
struct ActorStub
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
    virtual Vec& position();
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
    virtual float speed(int);

    void* FUN_00575d70();
    void* FUN_008d6f30();
    void setup(Request*, Vec*, void*, void*, float, int);
    bool path(Request*);
    bool failed();
    bool failedMove();
    bool arrived();
    WorldPos world();
};
struct Hiding
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
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    bool active;
};
struct Cover
{
    unsigned char kind;
    int field4;
    WorldPos pos;
};
struct TimeValue
{
    int value;
    float elapsed();
};
struct StateStub
{
    bool find(Hiding*);
    void FUN_009a03d0(int);
    Cover* cover();
    bool ready();
    void turn(bool);
    TimeValue timer();
};
struct OwnerStub
{
    ActorStub* GetFieldBC();
    ActorStub* target();
    StateStub* FUN_00586150();
};
float height(void*, int, int);
void location(OwnerStub*, Hiding*, Vec*, Vec*);
Vec angle(ActorStub*, int);
float FUN_00435dd0();
struct SettingStub
{
    float* Float();
};
extern SettingStub originalRuntimeFloatSetting431;
struct HideProcedure
{
    int f00;
    OwnerStub* owner;
    int f08, f0c;
    int state;
    float duration;
    Clock clock;
    Vec destination;
    Vec rotation;
    Hiding* hiding;
    bool keep;
    bool reset;
    void FUN_00996e20(int);
    void SetLookAtPoint(const Vec&, unsigned char);
    void FUN_009caac0(const char*);
    void SetState();
    void Update();
};
// @fnv 0x009d6140
void HideProcedure::Update()
{
    ActorStub* actor2 = owner->GetFieldBC();
    ActorStub* enemy2 = owner->target();
    StateStub* target7 = owner->FUN_00586150();
    switch (state)
    {
    case 0: {
        bool found7 = target7->find(hiding);
        if (found7)
        {
            hiding->active = true;
            location(owner, hiding, &destination, &rotation);
            rotation.z += height(enemy2 ? enemy2 : actor2, 2, 0);
        }
        else
        {
            destination = actor2->position();
            if (enemy2)
                rotation = angle(enemy2, 2);
        }
        Vec delta7 = actor2->position() - destination;
        if (found7 && delta7.FUN_004a7290() > 625.0)
        {
            FUN_00996e20(3);
            Request request2;
            actor2->setup(&request2, &destination, actor2->FUN_008d6f30(), actor2->FUN_00575d70(), 0.0f, 0);
            request2.SetInitialPathHeading(actor2->speed(0));
            if (!actor2->path(&request2))
            {
                FUN_009caac0("Cannot setup path to hiding location");
                return;
            }
            state = 1;
        }
        else
        {
            clock.FUN_008d7f40(duration);
            if (enemy2)
                SetLookAtPoint(rotation, 3);
            FUN_00996e20(2);
            state = 2;
        }
        break;
    }
    case 1:
        FUN_00996e20(3);
        if (actor2->failed())
        {
            FUN_009caac0(actor2->failedMove() ? "Pathing failed while moving to hiding location"
                                              : "Path Building failed to hiding location");
            return;
        }
        if (actor2->arrived())
        {
            clock.FUN_008d7f40(duration);
            SetLookAtPoint(rotation, 3);
            FUN_00996e20(2);
            state = 2;
        }
        break;
    case 2:
        if (clock.expired())
        {
            if (reset)
                target7->FUN_009a03d0(0);
            SetState();
            return;
        }
        {
            bool shouldEnd3 = false;
            float time7 = clock.elapsed() + 1.0;
            if (time7 < FUN_00435dd0())
                shouldEnd3 = true;
            if (shouldEnd3)
            {
                Cover* cover = target7->cover();
                if (cover && cover->kind == 1 && cover->pos.distance(actor2->world()) < 4096.0)
                    shouldEnd3 = false;
            }
            if (shouldEnd3)
            {
                if (target7->ready())
                {
                    if (!keep)
                    {
                        owner->FUN_00586150()->FUN_009a03d0(1);
                        target7->turn(false);
                        SetState();
                        return;
                    }
                    if (enemy2)
                    {
                        WorldPos actorPosition = actor2->world();
                        WorldPos targetPosition = enemy2->world();
                        if (actorPosition.distance(targetPosition) <
                            *originalRuntimeFloatSetting431.Float() * *originalRuntimeFloatSetting431.Float())
                        {
                            owner->FUN_00586150()->FUN_009a03d0(1);
                            target7->turn(false);
                            SetState();
                            return;
                        }
                    }
                }
                if (time7 < target7->timer().elapsed())
                {
                    owner->FUN_00586150()->FUN_009a03d0(1);
                    target7->turn(false);
                    SetState();
                }
            }
        }
        break;
    }
}

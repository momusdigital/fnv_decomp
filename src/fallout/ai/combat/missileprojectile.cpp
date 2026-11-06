
// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_011c6278;

// @fnv 0x009b7cb0
int __cdecl FUN_009b7cb0()
{
    return DAT_011c6278;
}

extern char const* const g_01268310_arg1;

struct FUN_009ba4d0_shell
{
    char const* const* GetArg1Ptr();
};

// @fnv 0x009ba4d0
char const* const* __thiscall FUN_009ba4d0_shell::GetArg1Ptr()
{
    return &g_01268310_arg1;
}

extern "C" void __cdecl FUN_00c89640(void*);
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct bhkConstraint
{
    virtual ~bhkConstraint();
    void* DestroyConstraint(unsigned int);
};

// @fnv 0x009ba4e0
void* bhkConstraint::DestroyConstraint(unsigned int flags)
{
    this->bhkConstraint::~bhkConstraint();
    if (flags & 1)
        __Dummy_00b6fef0(this, 16);
    return this;
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};

struct BeamProjectile
{
    void LoadProjectile(BGSLoadFormBuffer*);
};

struct MissileProjectile : BeamProjectile
{
    void LoadGame(BGSLoadFormBuffer*);
};

// Calls the base BeamProjectile load routine, then reads 4 bytes from the load buffer into this+0x150.
// @fnv 0x009baad0
void MissileProjectile::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    BeamProjectile::LoadProjectile(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x150), 4);
}

namespace fnv_009bab70 {
struct BGSLoadFormBuffer;
struct Projectile
{
    void FUN_009c58e0(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct MissileProjectile : Projectile
{
    void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
};

void Projectile::FUN_009c58e0(BGSLoadFormBuffer* apLoadGameBuffer)
{}

// @fnv 0x009bab70
void MissileProjectile::Revert(BGSLoadFormBuffer* apLoadGameBuffer)
{
    FUN_009c58e0(apLoadGameBuffer);
    ((int*)this)[0x150 / 4] = 0;
}
}  // namespace fnv_009bab70

struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009b7c90_shell : BGSProjectile
{
    bool FUN_009b7c90();
};

// @fnv 0x009b7c90
bool FUN_009b7c90_shell::FUN_009b7c90()
{
    return GetFlag(0x100);
}

extern "C" void __cdecl _delete(void*, unsigned int);

struct bhkHingeConstraint : bhkConstraint
{
    void* FUN_009ba520(unsigned int);
};

// Destroys the constraint and, when flags has bit 0 set, frees the 0x10-byte object; returns this.
// @fnv 0x009ba520
void* bhkHingeConstraint::FUN_009ba520(unsigned int flags)
{
    this->bhkHingeConstraint::~bhkHingeConstraint();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_009b7a20_holder
{
    void FUN_009b7bc0();
    void* FUN_009b7a20(unsigned int);
};
// @fnv 0x009b7a20
void* FUN_009b7a20_holder::FUN_009b7a20(unsigned int flags)
{
    FUN_009b7bc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_009ba320_shell
{
    void FUN_009ba320(unsigned int a, unsigned int b);
    void FUN_009ba350(unsigned int);
    void FUN_009ba390(unsigned int);
};
// Calls FUN_009ba350 with a and FUN_009ba390 with b.
// @fnv 0x009ba320
void FUN_009ba320_shell::FUN_009ba320(unsigned int auiFirst, unsigned int auiSecond)
{
    FUN_009ba350(auiFirst);
    FUN_009ba390(auiSecond);
}

struct ScriptLocalsX
{
    void* GetLocalData();
};
struct FUN_009ba350_shell
{
    void* m_p;
    void FUN_009ba350(ScriptLocalsX* p);
};
// @fnv 0x009ba350
void FUN_009ba350_shell::FUN_009ba350(ScriptLocalsX* p)
{
    *(void**)((char*)this + 0xc) = p ? p->GetLocalData() : 0;
}

namespace fnv_009ba390 {
struct ScriptLocalsX
{
    void* GetLocalData();
};
struct FUN_009ba390_shell
{
    void FUN_009ba390(ScriptLocalsX*);
};
// @fnv 0x009ba390
void FUN_009ba390_shell::FUN_009ba390(ScriptLocalsX* apScriptLocals)
{
    *(void**)((char*)this + 0x10) = apScriptLocals ? apScriptLocals->GetLocalData() : 0;
}
}  // namespace fnv_009ba390

struct FUN_00cbe240_shell
{
    void __thiscall SetLocalTransforms(int a, int b, int c, int d);
};

struct FUN_009ba3d0_shell
{
    int m_iWordAt00;
    int m_iWordAt04;
    void FUN_009ba3d0(int a, int b, int c, int d);
};

// If the object stored at this+4 is non-null, forwards the four arguments to its SetLocalTransforms method.
// @fnv 0x009ba3d0
void FUN_009ba3d0_shell::FUN_009ba3d0(int a, int b, int c, int d)
{
    int obj = *(int*)((char*)this + 4);
    if (obj)
        ((FUN_00cbe240_shell*)obj)->SetLocalTransforms(a, b, c, d);
}

struct FUN_004b5120
{
    FUN_004b5120();
};
extern int DAT_0108febc;
extern int DAT_01268188;
struct FUN_009ba4a0 : FUN_004b5120
{
    int* m_iWordAt00;
    FUN_009ba4a0();
};
// Points the object's pointer at DAT_0108febc and increments DAT_01268188.
// @fnv 0x009ba4a0
FUN_009ba4a0::FUN_009ba4a0() : FUN_004b5120()
{
    m_iWordAt00 = &DAT_0108febc;
    DAT_01268188++;
}

extern int DAT_0108ffb4;
struct BaseS
{
    int a;
    int b;
    int c;
    int d;
    BaseS();
};
struct FUN_009ba570
{
    int v0;
    BaseS m;
    FUN_009ba570();
};
// Initializes v0 to the address of DAT_0108ffb4 and sets the embedded BaseS fields to 0, 1, 0, 0.
// @fnv 0x009ba570
FUN_009ba570::FUN_009ba570()
{
    v0 = (int)&DAT_0108ffb4;
    m.a = 0;
    m.b = 1;
    m.c = 0;
    m.d = 0;
}

void __cdecl operator delete(void*);

struct FUN_009ba5c0_shell
{
    void FUN_009ba5f0();
    void* __thiscall FUN_009ba5c0(unsigned int flags);
};

// Calls FUN_009ba5f0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x009ba5c0
void* __thiscall FUN_009ba5c0_shell::FUN_009ba5c0(unsigned int flags)
{
    FUN_009ba5f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_0108ffb4;

struct FUN_009ba5f0_shell
{
    void* p;
    void __thiscall FUN_009ba5f0();
    void __thiscall SetChildObject(int);
};

// @fnv 0x009ba5f0
void __thiscall FUN_009ba5f0_shell::FUN_009ba5f0()
{
    p = &DAT_0108ffb4;
    this->SetChildObject(0);
}

namespace fnv_009ba610 {
struct FUN_009ba5f0_shell
{
    void FUN_009ba5f0();
    void __thiscall FUN_009ba610();
};
// @fnv 0x009ba610
void __thiscall FUN_009ba5f0_shell::FUN_009ba610()
{
    FUN_009ba5f0();
}
}  // namespace fnv_009ba610

struct FUN_009ba630_shell
{
    void __thiscall FUN_009ba610();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009ba610, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009ba630
void* __thiscall FUN_009ba630_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009ba610();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
void __cdecl SaveProjectile(BGSLoadFormBuffer*);
struct FUN_009baaa0_shell
{
    void AppendSaveLoadFormBuffer(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009baaa0
void FUN_009baaa0_shell::AppendSaveLoadFormBuffer(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<void(__thiscall*)(void*, BGSLoadFormBuffer*)>(SaveProjectile)(this, buffer);
    reinterpret_cast<BGSSaveFormBuffer*>(buffer)->SaveData(reinterpret_cast<char*>(this) + 0x150, 4, 0);
}

struct S5870_Holder
{
    void FinishLoadGame(BGSLoadFormBuffer*);
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
    virtual int v116();
    char _pad[0x150];
    unsigned char b154;
    void FUN_009babe0();
    void LoadForm(BGSLoadFormBuffer*);
};
// Loads from the buffer via FinishLoadGame, then either calls FUN_009babe0 or sets b154 to 1 depending on v116().
// @fnv 0x009bab20
void S5870_Holder::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    FinishLoadGame(apLoadGameBuffer);
    if (v116())
        FUN_009babe0();
    else
        b154 = 1;
}

struct XActor
{
    void* GetActorBase();
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct PathingRequest
{
    bool IsRandomBelowRadiusThreshold();
};

struct FUN_009a7f00_obj
{
    float FUN_00966980();
    bool FUN_009a7f80() const;
};

struct BeamEffect
{
    void FUN_005de0a0(int, bool);
};

struct FUN_009bda10_shell
{
    void FUN_009bda10();
};

struct FUN_009b7cc0_shell
{
    void UpdateBeamFlags();
};

int DAT_011f2250;
extern double _DAT_01012060;

// Computes flags from the actor base's pathing/target state and the global flags, then sets each beam flag via FUN_005de0a0 and calls FUN_009bda10.
// @fnv 0x009b7cc0
void FUN_009b7cc0_shell::UpdateBeamFlags()
{
    bool bTime = reinterpret_cast<ArrSI*>(&DAT_011f2250)->GetFlags() == 4;

    bool bTarget = reinterpret_cast<PathingRequest*>(reinterpret_cast<XActor*>(this)->GetActorBase())
                       ->IsRandomBelowRadiusThreshold();

    bool bPathing =
        bTime ? false
              : reinterpret_cast<FUN_009a7f00_obj*>(reinterpret_cast<XActor*>(this)->GetActorBase())->FUN_009a7f80();

    bool bNewGame =
        reinterpret_cast<FUN_009a7f00_obj*>(reinterpret_cast<XActor*>(this)->GetActorBase())->FUN_00966980() > 0.0;

    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x10, bTarget);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(1, bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(8, bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x20, bTarget && bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(2, !bTarget && bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x40, bNewGame && !bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x100, true);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x8000, !bPathing);
    reinterpret_cast<BeamEffect*>(this)->FUN_005de0a0(0x2000, bPathing);

    reinterpret_cast<FUN_009bda10_shell*>(this)->FUN_009bda10();
}

struct FUN_009babe0_object
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
    virtual bool Check();
};

struct FUN_009babe0_impact
{
    FUN_009babe0_object* pObject;
};

struct FUN_009babe0_list
{
    FUN_009babe0_impact** _ref_006815c0();
    FUN_009babe0_list* _ref_00726070();
};

struct FUN_009b90b0_shell
{
    void FUN_009b90b0();
};

struct FUN_009ba660_shell
{
    void HandleMissileImpact();
};

// @fnv 0x009babe0
void S5870_Holder::FUN_009babe0()
{
    FUN_009babe0_impact* pimpact;

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4 ||
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 3)
    {
        pimpact = *reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)->_ref_006815c0();

        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4)
        {
            pimpact = reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)->_ref_00726070()
                          ? *reinterpret_cast<FUN_009babe0_list*>(reinterpret_cast<char*>(this) + 0x88)
                                 ->_ref_00726070()
                                 ->_ref_006815c0()
                          : 0;
        }

        if (pimpact && pimpact->pObject && pimpact->pObject->Check())
            reinterpret_cast<FUN_009b90b0_shell*>(this)->FUN_009b90b0();
    }

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4)
        reinterpret_cast<FUN_009ba660_shell*>(this)->HandleMissileImpact();
}

extern int DAT_0108fa44;
extern int DAT_0108fa38;
struct BaseA
{
    void* vptr;
    int pad[5];
    BaseA(unsigned char a);
    ~BaseA();
    void FUN_004f15a0(int);
};
struct FUN_009b7a50 : BaseA
{
    void* vptr2;
    int pad2[0x4d];
    int m150;
    unsigned char b154;
    float f158;
    float f15c;
    FUN_009b7a50(unsigned char a);
};
// Initialises the BaseA-derived object: sets both vtables, calls FUN_004f15a0(0x3d), and zeroes m150, b154, f158 and f15c.
// @fnv 0x009b7a50
FUN_009b7a50::FUN_009b7a50(unsigned char a) : BaseA(a)
{
    vptr = &DAT_0108fa44;
    vptr2 = &DAT_0108fa38;
    FUN_004f15a0(0x3d);
    m150 = 0;
    b154 = 0;
    f158 = 0.0f;
    f15c = 0.0f;
}

struct Vector3
{
    float x;
    float y;
    float z;
};
extern int DAT_0108fa44;
extern int DAT_0108fa38;

struct FUN_009bbef0
{
    int* m_primaryVtable;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    int* m_secondaryVtable;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    FUN_009bbef0(int a, int b, int c, Vector3 position, float magnitude, float duration);
    ~FUN_009bbef0();
    void FUN_004f15a0(unsigned int flag);
};

struct FUN_009b7af0 : FUN_009bbef0
{
    unsigned int unk150;
    unsigned char unk154;
    float unk158;
    float unk15c;

    FUN_009b7af0(int a, int b, int c, Vector3 position, float magnitude, float duration);
};

// Initialises the derived object: sets both vtables, calls FUN_004f15a0(61), and zeroes unk150, unk154, unk158 and unk15c.
// @fnv 0x009b7af0
FUN_009b7af0::FUN_009b7af0(int a, int b, int c, Vector3 position, float magnitude, float duration)
    : FUN_009bbef0(a, b, c, position, magnitude, duration)
{
    m_primaryVtable = &DAT_0108fa44;
    m_secondaryVtable = &DAT_0108fa38;
    FUN_004f15a0(61);
    unk150 = 0;
    unk154 = 0;
    unk158 = 0.0f;
    unk15c = 0.0f;
}

struct Base_b9999
{
    virtual ~Base_b9999();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct Sec_b9999
{
    virtual void v0();
};

struct Obj_b9999
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
    virtual Obj_b9999* v39(int);
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
    virtual void v58(Obj_b9999*);
    Obj_b9999* Probe3();
};

struct FUN_009b7bc0_cls : Base_b9999, Sec_b9999
{
    virtual ~FUN_009b7bc0_cls();
    void* Probe1();
    void* Probe2();
};

// @fnv 0x009b7bc0
FUN_009b7bc0_cls::~FUN_009b7bc0_cls()
{
    Obj_b9999* r;
    if (reinterpret_cast<FUN_009b7c90_shell*>(Probe1())->FUN_009b7c90())
    {
        Obj_b9999* s;
        if (Probe2() != 0)
        {
            r = reinterpret_cast<Obj_b9999*>(Probe2())->v39(FUN_009b7cb0());
            if (r != 0)
            {
                s = r->Probe3();
                s->v58(r);
            }
        }
    }
}

struct NiRTTI
{
    int unk00;
};
extern NiRTTI DAT_011f4428;
extern double _DAT_01012060;

struct NiPoint3s
{
    float x;
    float y;
    float z;
    NiPoint3s(float ax, float ay, float az);
    NiPoint3s operator-(const NiPoint3s& o) const;
    float Length();
};

struct NiBounds
{
    float cx;
    float cy;
    float cz;
    float radius;
    NiPoint3s* GetNavMeshData();
    float GetRadius();
};

struct NiUpdateDatas
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bUpdateSelected;
    int unk08;
    NiUpdateDatas(float t, bool a, bool b);
};

class NiAVObj
{
  public:
    virtual void a0();
    void SetAppCulled(bool b);
    NiBounds* GetBoundingVolume();
    NiPoint3s& GetWorldTranslate();
};

class NiNodeS : public NiAVObj
{
  public:
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
    virtual void UpdateWorldData(NiUpdateDatas& data);
    void* GetChildPtr(unsigned int idx);
    NiAVObj* GetAt(int idx);
};

bool FUN_0043b300(const NiRTTI* rtti, NiAVObj* obj);

struct PathReq
{
    float GetRadiusVal();
};

class ProjS
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
    virtual NiAVObj* Get3D();

    PathReq* GetBaseObj();
    bool IsFlagSet(int flag);
    float GetScaleDivisor();
    void SetPosAndScale(float scale, NiPoint3s pt);
    void SetFlags(int a, int b);
    float GetValueA();
    float GetValueB();
    void UpdateProjectileNodeVisibility();
};

// Updates the projectile's 3D node: toggles child culling by flag 0x10, rescales and repositions it from its bounds, and culls it when value A exceeds value B.
// @fnv 0x009b7e40
void ProjS::UpdateProjectileNodeVisibility()
{
    NiAVObj* p3D = Get3D();
    if (p3D && FUN_0043b300(&DAT_011f4428, p3D))
    {
        NiNodeS* pNode5 = (NiNodeS*)p3D;
        pNode5->SetAppCulled(false);
        if (GetBaseObj()->GetRadiusVal() > _DAT_01012060)
        {
            if (pNode5->GetChildPtr(0))
                pNode5->GetAt(0)->SetAppCulled(IsFlagSet(0x10));
            if (pNode5->GetChildPtr(1))
                pNode5->GetAt(1)->SetAppCulled(!IsFlagSet(0x10));
        }
        if (IsFlagSet(0x10))
        {
            NiBounds bound5 = *pNode5->GetBoundingVolume();
            NiPoint3s diff2 = pNode5->GetWorldTranslate() - *bound5.GetNavMeshData();
            float fLen = diff2.Length() + bound5.GetRadius();
            float fScale3 = fLen / GetScaleDivisor();
            SetPosAndScale(fScale3, NiPoint3s(0.0f, fLen, 0.0f));
            SetFlags(0, 1);
            NiUpdateDatas data(0.0f, false, false);
            pNode5->UpdateWorldData(data);
            if (GetValueA() > GetValueB())
                pNode5->SetAppCulled(true);
        }
    }
}

struct HitItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    bool flag;
};
struct HitList
{
    HitItem* value;
    void* next;
    bool FUN_008256d0();
    HitItem** FUN_006815c0();
};
struct Collider890
{
    int getCollisionFilterInfo();
};
struct CF845
{
    int value;
    CF845(int);
    int FUN_0043b4d0();
};
struct Target890;
bool CanProjectileHit(int, Collider890*, Target890*, void*);
struct Target890
{
    int unk000;
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
    HitList hits;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int kind;
    void* GetActorBase();
    bool ProcessHit(int, int, int, Collider890*, int, int);
    void FUN_009b8a20();
    bool FUN_009b8900(int, int, int, Collider890*, int, int);
};
// Checks the hit list and collider state, then calls ProcessHit and FUN_009b8a20 when the kind and collider conditions pass, returning true on success.
// @fnv 0x009b8900
bool Target890::FUN_009b8900(int aiArg1, int aiArg2, int aiArg3, Collider890* collider, int aiArg5, int aiArg6)
{
    bool p = hits.FUN_008256d0() || (*hits.FUN_006815c0())->flag;
    int h = collider ? CF845(collider->getCollisionFilterInfo()).FUN_0043b4d0() : 0;
    if (p && CanProjectileHit(aiArg1, collider, this, GetActorBase()) &&
        (kind != 3 || h == 1 || h == 2 || h == 9 || h == 17 || h == 13 || h == 20) &&
        ProcessHit(aiArg1, aiArg2, aiArg3, collider, aiArg5, aiArg6))
    {
        FUN_009b8a20();
        return true;
    }
    return false;
}

class BA410Base
{
  public:
    BA410Base();
    virtual ~BA410Base();
};

class BA410Interface
{
  public:
    int unk00;
};

class BA410Source : public BA410Interface
{
  public:
    int unk04;
};

class BA410SourceLink
{
  public:
    int unk00;
};

class BA410Target : public BA410SourceLink, public BA410Source
{
};

class FUN_009ba410 : public BA410Base
{
  public:
    FUN_009ba410(BA410Target* pkTarget);
    virtual ~FUN_009ba410();

    void SetSource(BA410Source* pkSource);

    static unsigned int ms_uiInstances;
};

// Stores pkTarget as the source via SetSource and increments the static instance counter.
// @fnv 0x009ba410
FUN_009ba410::FUN_009ba410(BA410Target* pkTarget)
{
    SetSource(pkTarget);
    ++ms_uiInstances;
}

struct SpawnedBase
{
    virtual ~SpawnedBase();
    SpawnedBase();
};

struct FUN_009ba550 : SpawnedBase
{
    FUN_009ba550();
    virtual ~FUN_009ba550();
};

// @fnv 0x009ba550
FUN_009ba550::FUN_009ba550()
{}

struct UpdateVec
{
    float x, y, z;
    UpdateVec operator-(const UpdateVec&) const;
    float FUN_00457990();
};
struct UpdateMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateMatrix();
    void FUN_00524ac0(float);
    void FUN_0043f850(float);
    void FUN_004a0c90(float);
    UpdateMatrix FUN_0043f8d0(const UpdateMatrix&);
};
struct UpdateTransform
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateVec translation;
    float scale;
    UpdateTransform FUN_0062c250(const UpdateTransform&);
};
struct UpdateNode
{
    void FUN_0043fa80(const void*);
    void FUN_00440460(UpdateVec*);
    void FUN_00a68bf0();
    void FUN_00450f90(bool);
    UpdateMatrix* FUN_006a9540();
};
struct UpdateRef
{
    void* FUN_00460140();
    UpdateTransform* FUN_00461130();
    UpdateVec GetTargetPosition();
};
struct UpdateImpact
{
    unsigned int unk00;
    UpdateVec position;
    unsigned int unk10, unk14, unk18;
    UpdateRef* reference;
    unsigned int unk20, unk24;
    bool flag;
};
struct UpdateList
{
    UpdateImpact* value;
    void* next;
    bool FUN_008256d0();
    UpdateImpact** FUN_006815c0();
};
struct UpdateBase
{
    bool FUN_009b88e0();
    float GetUnka4();
    float FUN_009b88a0();
    float FUN_009b88c0();
};
struct UpdateFloatSetting
{
    float* FUN_00403e20();
};
struct UpdateBoolSetting
{
    bool* FUN_00408d60();
};
extern UpdateFloatSetting DAT_011cff34, DAT_011f210c, DAT_011ce684;
extern UpdateBoolSetting DAT_011f20ec;
struct UpdateWorld
{
    void FUN_00458e20(void*, float);
};
extern UpdateWorld* DAT_011dea10;
extern const char DAT_0108fd78[];
UpdateRef* __cdecl FUN_004b5820(void*);
void* __cdecl FUN_004b3890(const UpdateVec*, const void*, const UpdateVec*, const void*, int);
void __cdecl FUN_005b5e40(int, const char*, ...);
struct UpdateColor
{
    float r, g, b, a;
    UpdateColor(float, float, float, float);
};
struct UpdateProjectile
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
    virtual UpdateNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual UpdateVec* GetPosition();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    UpdateList hits;
    bool pending;
    UpdateTransform transform;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    int kind;
    bool active;
    float timeout;
    float angle;
    void FUN_009b8030(float);
    void FUN_009babe0();
    float FUN_00508070();
    float GetFirstLightParameter();
    void FUN_009bc8f0();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00444d00(int);
    float FUN_00885bd0();
    UpdateRef* FUN_008d8b80();
    void SetOrientationFromDirection(UpdateVec);
    void ApplyScale(float);
    void FUN_00575830(const UpdateVec*);
    void FUN_009c6330(UpdateTransform*);
    void UpdateNodeTransform(bool, bool);
    UpdateBase* FUN_004181e0();
    const char* FUN_0055d520();
    void UpdateDetonation(float);
};
// @fnv 0x009b8030
void UpdateProjectile::FUN_009b8030(float afDeltaTime)
{
    if (active && Get3D())
        FUN_009babe0();
    if (GetFirstLightParameter() > FUN_00508070() && (hits.FUN_008256d0() || pending))
        FUN_009bc8f0();
    if (FUN_00440d80() || FUN_00440da0())
        return;
    if (kind == 4)
    {
        timeout -= afDeltaTime;
        if (timeout <= 0.0)
            FUN_009bc8f0();
    }
    if (FUN_00444d00(128) && kind == 4)
    {
        UpdateImpact* impact = *hits.FUN_006815c0();
        if (impact)
        {
            UpdateRef* node = impact->reference ? FUN_004b5820(impact->reference->FUN_00460140()) : 0;
            UpdateNode* reference = Get3D();
            if (node && reference)
            {
                UpdateTransform worldTransform = node->FUN_00461130()->FUN_0062c250(transform);
                reference->FUN_0043fa80(&worldTransform);
                FUN_009c6330(&worldTransform);
                reference->FUN_00440460(&worldTransform.translation);
                FUN_00575830(&worldTransform.translation);
            }
            UpdateNodeTransform(true, false);
        }
    }
    else if (!pending || FUN_00444d00(1) || kind == 3)
    {
        bool stopped = !(FUN_00885bd0() > 0.0);
        bool skipPosition = false;
        if (FUN_008d8b80())
        {
            SetOrientationFromDirection(FUN_008d8b80()->GetTargetPosition());
        }
        if (!stopped)
        {
            if (FUN_008d8b80())
            {
                UpdateVec positionDelta = FUN_008d8b80()->GetTargetPosition() - *GetPosition();
                if (positionDelta.FUN_00457990() > *DAT_011cff34.FUN_00403e20())
                    skipPosition = true;
            }
            if (*DAT_011f20ec.FUN_00408d60())
            {
                UpdateVec newPosition = *GetPosition();
                ApplyScale(afDeltaTime);
                UpdateVec color = *GetPosition();
                UpdateColor debugColor(1.0f, 1.0f, 0.0f, 1.0f);
                void* pDebugLine = FUN_004b3890(&newPosition, &debugColor, &color, &debugColor, 1);
                DAT_011dea10->FUN_00458e20(pDebugLine, *DAT_011f210c.FUN_00403e20());
            }
            else
                ApplyScale(afDeltaTime);
        }
        bool nearby = hits.FUN_008256d0() || (*hits.FUN_006815c0())->flag;
        if (!nearby && (!FUN_00444d00(1) || GetFirstLightParameter() > FUN_00508070()))
            FUN_00575830(&(*hits.FUN_006815c0())->position);
        UpdateNodeTransform(skipPosition, !stopped);
        if (Get3D())
            Get3D()->FUN_00a68bf0();
        if (FUN_004181e0()->FUN_009b88e0())
        {
            UpdateMatrix rotation;
            if (FUN_004181e0()->GetUnka4() > 0.0)
            {
                angle += FUN_004181e0()->GetUnka4() * afDeltaTime;
                rotation.FUN_00524ac0(angle);
            }
            else if (FUN_004181e0()->FUN_009b88a0() > 0.0)
            {
                angle += FUN_004181e0()->FUN_009b88a0() * afDeltaTime;
                rotation.FUN_0043f850(angle);
            }
            else if (FUN_004181e0()->FUN_009b88c0() > 0.0)
            {
                angle += FUN_004181e0()->FUN_009b88c0() * afDeltaTime;
                rotation.FUN_004a0c90(angle);
            }
            if (Get3D())
            {
                UpdateMatrix matrix = *Get3D()->FUN_006a9540();
                matrix = matrix.FUN_0043f8d0(rotation);
                Get3D()->FUN_0043fa80(&matrix);
            }
            else
                FUN_005b5e40(11, DAT_0108fd78, FUN_0055d520());
        }
    }
    UpdateDetonation(afDeltaTime);
    if (FUN_00885bd0() > *DAT_011ce684.FUN_00403e20() && kind != 4)
        FUN_009bc8f0();
    if (GetFirstLightParameter() > FUN_00508070() && (hits.FUN_008256d0() || pending))
    {
        if (Get3D())
            Get3D()->FUN_00450f90(true);
        FUN_009bc8f0();
    }
}

namespace ImpactResponse {
struct Impact;
struct Vector
{
    float x, y;

  private:
    float z;
    friend struct Impact;

  public:
    void FUN_00416870(float, float, float);
    Vector FUN_00439ef0(const Vector&);
    Vector FUN_00439e90(const Vector&);
    void FUN_00439180(float);
    float DotProduct(const Vector&);
};
Vector FUN_004a3760(float, const Vector&);
void UnitizeVector(Vector&);
double FUN_00408820(float);
double SignOfFloat(float);
extern const float DAT_01012054, DAT_010162c0;
extern Vector DAT_011f426c;
struct Matrix
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    Matrix();
    void FUN_004b46a0(Matrix&);
    Vector FUN_004b4500(const Vector&);
};
struct Update
{
    float time;
    int flags, unknown;
    Update(float, int, int);
};
struct Node
{
    void FUN_00440460(const Vector&);
    void FUN_00a59c60(const Update&);
    Matrix* FUN_00461130();
};
struct Contact
{
    int unk00;
    Vector position, normal;
};
struct ContactList
{
    bool FUN_008256d0();
    Contact** FUN_006815c0();
};
struct Physics
{
    void FUN_00573ed0(bool);
};
Physics* FUN_004b5260(Node*);
void FUN_00c6a350(Node*, int, int, int, int);
void FUN_00c6a3d0(Node*, int, int, int);
void FUN_00c6a0b0(Node*, int, int, int);
int FUN_005dbe10();
void FUN_0062b8d0(Node*, const Vector&, int);
void FUN_0062ba80(Node*, const Vector&, int);
struct Game
{
    bool FUN_0047c850();
};
extern Game* DAT_011de45c;
struct Impact;
struct Selection
{
    Impact* FUN_007af430();
    void SetValue(int);
};
extern Selection DAT_011f2250;
struct Setting
{
    const float* FUN_00403e20();
};
extern Setting DAT_011ce1dc;
struct Base
{
    float GetFloatAtOffset68();
};
struct Impact
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
    virtual Node* GetNode();
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
    virtual void Refresh();
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
    ContactList contacts;
    void FUN_005de0a0(int, int);
    int FUN_009d9f00();
    Vector FUN_009b7010();
    Base* FUN_004181e0();
    bool HandleContactResponse();
};
// If the node has contacts, clears the selection, refreshes, applies physics and impulse/angular responses, and returns true.
// @fnv 0x009b8c90
bool Impact::HandleContactResponse()
{
    if (GetNode() && !contacts.FUN_008256d0())
    {
        if (DAT_011f2250.FUN_007af430() == this)
            DAT_011f2250.SetValue(0);
        Node* node7 = GetNode();
        Contact* contact = *contacts.FUN_006815c0();
        FUN_005de0a0(4, 1);
        Refresh();
        Physics* physics = FUN_004b5260(node7);
        if (physics)
            physics->FUN_00573ed0(true);
        if (!DAT_011de45c->FUN_0047c850() && !FUN_009d9f00())
        {
            node7->FUN_00440460(contact->position);
            Update update(0.0f, 0, 0);
            node7->FUN_00a59c60(update);
        }
        FUN_00c6a350(node7, 1, 1, 0, 1);
        FUN_00c6a3d0(node7, FUN_005dbe10(), 1, 0);
        FUN_00c6a0b0(node7, 1, 1, 0);
        if (!DAT_011de45c->FUN_0047c850())
        {
            Vector linear_ = DAT_011f426c;
            Vector direction3;
            direction3 = FUN_004a3760(DAT_01012054, FUN_009b7010());
            direction3 = direction3;
            UnitizeVector(direction3);
            UnitizeVector(contact->normal);
            float dot = contact->normal.DotProduct(direction3);
            Vector correctionTmp =
                FUN_004a3760(DAT_010162c0, FUN_004a3760(dot, contact->normal).FUN_00439ef0(direction3));
            linear_ = direction3.FUN_00439e90(correctionTmp);
            linear_.FUN_00439180(*DAT_011ce1dc.FUN_00403e20() * FUN_004181e0()->GetFloatAtOffset68());
            FUN_0062b8d0(node7, linear_, 1);
            Vector kAngular = DAT_011f426c;
            Matrix rotation;
            GetNode()->FUN_00461130()->FUN_004b46a0(rotation);
            Vector local = rotation.FUN_004b4500(contact->normal);
            if (FUN_00408820(local.y) > FUN_00408820(local.z))
                local.z = FUN_00408820(local.y) * SignOfFloat(local.z);
            local.y = 0.0f;
            UnitizeVector(local);
            Vector spin2;
            spin2.FUN_00416870(-local.z, 0.0f, -local.x);
            kAngular = node7->FUN_00461130()->FUN_004b4500(spin2);
            kAngular.FUN_00439180(*DAT_011ce1dc.FUN_00403e20());
            FUN_0062ba80(node7, kAngular, 1);
        }
    }
    return true;
}
}

namespace fnv_009ba660 {
struct MissileActor;
struct MissileNode;
struct MissileBody;
struct MissileVector
{
    float x, y, z;
    MissileVector FUN_00439e90() const;
    MissileVector ApplyScaled(float) const;
};
struct MissileTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    MissileVector translation;
    float scale;
    MissileTransform();
    void FUN_004b4880(MissileTransform&);
    MissileTransform FUN_0062c250(const MissileTransform&) const;
};
struct MissileUpdate
{
    float time;
    int flags;
    int frame;
    MissileUpdate(float, bool, bool);
};
struct MissileHandle
{
    unsigned value;
    unsigned FUN_0043b4d0();
    void FUN_004a39f0(unsigned);
};
struct MissileBody
{
    MissileHandle FUN_0043b4f0();
    void FUN_00626cb0(unsigned);
    int FUN_00517630();
    void SetFlag(unsigned, bool);
};
struct MissileCollision
{
    MissileBody* FUN_006fa820();
};
struct MissileSetting
{
    float* FUN_00403e20();
};
extern MissileSetting DAT_011cfc8c;
struct MissilePause
{
    bool FUN_0042ce10();
};
extern MissilePause* DAT_011ddf38;
struct MissileVats
{
    MissileActor* FUN_007af430();
    void SetValue(int);
};
struct MissileQueue
{
    void FUN_005ae3d0(MissileActor* const&);
};
struct MissileManager
{
    MissileQueue* GetOffset70Ptr();
};
extern MissileManager DAT_011e0e80;
struct MissileReference
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual bool IsActor();
};
struct MissileHit
{
    MissileReference* reference;
    MissileVector position;
    int unk10, unk14, unk18;
    MissileNode* node;
};
struct MissileHitHandle
{
    unsigned value;
    bool FUN_008256d0();
    MissileHit** FUN_006815c0();
};
MissileNode* FUN_004b5820(void*);
MissileBody* FUN_004b5a80(MissileNode*);
MissileCollision* FUN_004b5260(MissileNode*);
void FUN_00c69f50(MissileNode*, int, int);
void FUN_00c6a350(MissileNode*, int, int, int, int);
int FUN_009b7cb0();
const float DAT_01017b78 = 10.0f;
struct MissileNode
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual MissileNode* Find(int);
    void* FUN_00460140();
    void FUN_00a59c60(MissileUpdate*);
    MissileTransform* FUN_00461130();
};
struct MissileActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual MissileNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual void Slot214();
    virtual void Slot218();
    virtual void Slot21C();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual void Slot22C();
    virtual void Slot230();
    virtual void Slot234();
    virtual void Slot238();
    virtual void Slot23C();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24C();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25C();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26C();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27C();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28C();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29C();
    virtual void Slot2A0();
    virtual void Detach();
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
    MissileHitHandle hitHandle;
    int unk8C, unk90;
    MissileTransform impactTransform;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    float distance;
    void FUN_005de0a0(unsigned, bool);
    MissileVector FUN_009b7010();
    void FUN_00575830(const MissileVector&, const MissileVector&);
    void UpdateNodeTransform(int, int);
    bool FUN_00444d00(unsigned);
    void HandleContactResponse();
    void HandleMissileImpact();
};
// @fnv 0x009ba660
void MissileActor::HandleMissileImpact()
{
    static float impactScale = *DAT_011cfc8c.FUN_00403e20();
    bool paused = DAT_011ddf38->FUN_0042ce10();
    if (Get3D() && !hitHandle.FUN_008256d0())
    {
        if (((MissileVats*)&DAT_011f2250)->FUN_007af430() == this)
            ((MissileVats*)&DAT_011f2250)->SetValue(0);
        distance = DAT_01017b78;
        MissileHit* hit31 = *hitHandle.FUN_006815c0();
        if (!hit31 || !hit31->node)
            return;
        MissileNode* node3 = Get3D();
        MissileNode* parent41 = FUN_004b5820(hit31->node->FUN_00460140());
        MissileBody* body20 = FUN_004b5a80(hit31->node);
        unsigned layer1 = body20 ? body20->FUN_0043b4f0().FUN_0043b4d0() : 0;
        if (body20 && layer1 != 19 && (!hit31->reference || !hit31->reference->IsActor()))
        {
            FUN_005de0a0(4, true);
            Detach();
            MissileCollision* collision9 = FUN_004b5260(node3);
            MissileBody* ownBody53 = collision9 ? collision9->FUN_006fa820() : 0;
            if (ownBody53)
            {
                MissileHandle handle = ownBody53->FUN_0043b4f0();
                handle.FUN_004a39f0(15);
                ownBody53->FUN_00626cb0(handle.value);
            }
            if (!paused)
                FUN_00575830(hit31->position.FUN_00439e90(), FUN_009b7010().ApplyScaled(impactScale));
            UpdateNodeTransform(0, 0);
            FUN_00c69f50(node3, 1, 1);
            MissileUpdate update53(0.0f, false, false);
            node3->FUN_00a59c60(&update53);
            if (body20->FUN_00517630() == 5)
                FUN_00c6a350(node3, 5, 1, 0, 1);
            else
            {
                FUN_00c6a350(node3, 4, 1, 0, 1);
                if (!FUN_00444d00(128))
                {
                    FUN_005de0a0(128, true);
                    MissileQueue* queue = DAT_011e0e80.GetOffset70Ptr();
                    if (queue)
                        queue->FUN_005ae3d0(this);
                }
                body20->SetFlag(256, true);
                if (!paused && parent41)
                {
                    MissileTransform inverse;
                    parent41->FUN_00461130()->FUN_004b4880(inverse);
                    impactTransform = inverse.FUN_0062c250(*node3->FUN_00461130());
                }
            }
            MissileNode* child2 = node3 ? node3->Find(FUN_009b7cb0()) : 0;
            if (child2)
                FUN_00c6a350(child2, 1, 1, 1, 1);
        }
        else
            HandleContactResponse();
    }
}
}  // namespace fnv_009ba660

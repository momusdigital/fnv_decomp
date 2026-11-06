
// src/fallout/ai/combat/combatprocedurebeincover.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedurebeincover.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
struct FUN_009d2510_shell : public TESAttributes
{
    unsigned int FUN_009d2510();
};

// @fnv 0x009d2510
unsigned int FUN_009d2510_shell::FUN_009d2510()
{
    return 7;
}

void __cdecl operator delete(void*);

struct FUN_009d2520_shell
{
    void __thiscall FUN_009d2550();
    void* __thiscall FUN_009d2520(unsigned int flags);
};

// Calls FUN_009d2550, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x009d2520
void* FUN_009d2520_shell::FUN_009d2520(unsigned int flags)
{
    FUN_009d2550();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" float __cdecl RandomFloat(float, float);

struct FUN_009d32e0_shell
{
    float __thiscall GetRandomFloatInRange();
};

// Returns a random float between the two floats stored at offsets 0x20 and 0x24 of this object.
// @fnv 0x009d32e0
float __thiscall FUN_009d32e0_shell::GetRandomFloatInRange()
{
    return RandomFloat(*(float*)(this + 0x20), *(float*)(this + 0x24));
}

float __cdecl RandomFloat(float, float);

struct FUN_009d3310_shell
{
    float __thiscall GetRandomFloat();
};

// Returns a random float between the two float values stored at offsets 0x28 and 0x2c of this object.
// @fnv 0x009d3310
float __thiscall FUN_009d3310_shell::GetRandomFloat()
{
    return RandomFloat(*(float*)((char*)this + 0x28), *(float*)((char*)this + 0x2c));
}

float __cdecl RandomFloat(float, float);

struct TESCombatStyle
{
    char pad[0x30];
    float m_fMinimum;
    float m_fMaximum;
    float __thiscall GetRandomValue();
};

// Returns a random float between the combat style's two stored float fields.
// @fnv 0x009d3340
float __thiscall TESCombatStyle::GetRandomValue()
{
    return RandomFloat(m_fMinimum, m_fMaximum);
}

struct FUN_009ca6c0_shell
{
    void __thiscall FUN_009ca6c0();
};
extern "C" int DAT_010910f4;

// @fnv 0x009d2550
void __thiscall FUN_009d2520_shell::FUN_009d2550()
{
    *reinterpret_cast<void**>(this) = &DAT_010910f4;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->FUN_009ca6c0();
}

struct Actor
{
    void StopMoving();
};
struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
struct CombatProcedure
{
    void RunProcedure();
};
struct CombatProcedureEngageTarget
{
    void FUN_00996e40();
};
struct FUN_009d2570_shell : public CombatProcedure
{
    char pad[4];
    TESAmmoInitCalls* m_pattacker;
    void StopAttackerAndEngageTarget();
};
// @fnv 0x009d2570
void FUN_009d2570_shell::StopAttackerAndEngageTarget()
{
    Actor* actor = m_pattacker->GetFieldBC();
    actor->StopMoving();
    ((CombatProcedureEngageTarget*)this)->FUN_00996e40();
    RunProcedure();
}

struct FUN_00980070_shell
{
    unsigned int FUN_00980070();
};
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};
struct FUN_00996de0_Class
{
    Actor* FUN_00996de0();
};
struct Projectile;
struct FUN_009d33e0_shell : CombatProcedure
{
    void UpdateCombatProcedure(Projectile* apProjectile);
};
// @fnv 0x009d33e0
void FUN_009d33e0_shell::UpdateCombatProcedure(Projectile* apProjectile)
{
    switch (*(int*)((char*)this + 0x10))
    {
    case 1:
        ((FUN_008d7f40_shell*)((char*)this + 0x3c))
            ->FUN_008d7f40(((FUN_009d32e0_shell*)((FUN_00980070_shell*)*(int*)((char*)this + 4))->FUN_00980070())
                               ->GetRandomFloatInRange());
        break;
    case 2:
        ((FUN_00996de0_Class*)this)->FUN_00996de0()->StopMoving();
        RunProcedure();
        *(int*)((char*)this + 0x10) = 4;
        ((FUN_008d7f40_shell*)((char*)this + 0x4c))
            ->FUN_008d7f40(
                ((TESCombatStyle*)((FUN_00980070_shell*)*(int*)((char*)this + 4))->FUN_00980070())->GetRandomValue());
        break;
    }
}

struct Modifier
{
    float GetValue();
};

struct CTSHelper : public Modifier
{
    float GetElapsedTime();
};

struct FUN_0097fa50_shell : public CTSHelper
{
    bool FUN_0097fa50();
};

enum DEBUGTEXT_LOCATION
{
    DEBUGTEXT_LOCATION_0
};

enum DEBUGTEXT_JUSTIFY
{
    DEBUGTEXT_JUSTIFY_0
};

struct IDebugText
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void __cdecl Print(DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY, const char*, ...) = 0;
};

extern const char $SG2706[];
extern const char str_01091084[];
extern const char str_0109135c[];
extern const char str_01091380[];
extern const char str_010913a4[];
extern const char str_010913c8[];
extern const char str_010913ec[];
extern const char str_010913fc[];
extern const char str_01091414[];
extern const char str_01091420[];
extern const char str_01091434[];
extern const char str_01091458[];
extern const char str_01091474[];
extern const char str_0109148c[];
extern const char str_01091498[];
extern const char str_010914b0[];

struct CombatProcedureBeInCover
{
    enum COVER_STATE
    {
        INITIALIZING = 0,
        WAITING_BEHIND_COVER,
        MOVING_OUT,
        WAITING_OUT_OF_COVER,
        FIRING_OUT_OF_COVER,
        MOVING_IN,
        MOVING_IN_AND_ROTATE,
        HOLDING_GROUND
    };

    unsigned char _pad0[0x10];
    COVER_STATE eState;
    void* m_pCurrentCoverPoint;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
    unsigned char _pad1[0x0C];

    FUN_0097fa50_shell m_waitTimer;
    unsigned char _pad2[7];
    FUN_0097fa50_shell m_waitingOutTimer;
    unsigned char _pad3[7];
    FUN_0097fa50_shell m_firingTimer;
    unsigned char _pad4[7];
    FUN_0097fa50_shell m_reevaluateTimer;
    unsigned char _pad5[7];
    FUN_0097fa50_shell m_holdingGroundTimer;
    unsigned char _pad6[7];
    FUN_0097fa50_shell m_targetBlockedTimer;

    void DebugText(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY);
};

// Prints debug text describing the current cover state and its timers, positions and target-blocked status via pDebugText.
// @fnv 0x009d3470
void CombatProcedureBeInCover::DebugText(IDebugText* pDebugText, DEBUGTEXT_LOCATION aeLocation,
                                         DEBUGTEXT_JUSTIFY aeJustify)
{
    switch (eState)
    {
    case INITIALIZING:
        pDebugText->Print(aeLocation, aeJustify, $SG2706);
        break;

    case WAITING_BEHIND_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_010914b0);
        pDebugText->Print(aeLocation, aeJustify, str_01091498, m_waitTimer.GetElapsedTime(), m_waitTimer.GetValue());
        break;

    case MOVING_OUT:
        pDebugText->Print(aeLocation, aeJustify, str_0109148c);
        break;

    case WAITING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091474);
        pDebugText->Print(aeLocation, aeJustify, str_01091458, m_waitingOutTimer.GetElapsedTime(),
                          m_waitingOutTimer.GetValue());
        if (m_targetBlockedTimer.FUN_0097fa50())
        {
            pDebugText->Print(aeLocation, aeJustify, str_01091434, m_targetBlockedTimer.GetElapsedTime(),
                              m_targetBlockedTimer.GetValue());
        }
        break;

    case FIRING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091420);
        pDebugText->Print(aeLocation, aeJustify, str_01091084, m_firingTimer.GetElapsedTime(),
                          m_firingTimer.GetValue());
        break;

    case MOVING_IN:
        pDebugText->Print(aeLocation, aeJustify, str_01091414);
        break;

    case MOVING_IN_AND_ROTATE:
        pDebugText->Print(aeLocation, aeJustify, str_010913fc);
        break;

    case HOLDING_GROUND:
        pDebugText->Print(aeLocation, aeJustify, str_010913ec);
        pDebugText->Print(aeLocation, aeJustify, str_010913c8, m_holdingGroundTimer.GetElapsedTime(),
                          m_holdingGroundTimer.GetValue());
        break;
    }

    if (m_reevaluateTimer.FUN_0097fa50())
    {
        pDebugText->Print(aeLocation, aeJustify, str_010913a4, m_reevaluateTimer.GetElapsedTime(),
                          m_reevaluateTimer.GetValue());
    }

    pDebugText->Print(aeLocation, aeJustify, str_01091380, m_afFirstVector[0], m_afFirstVector[1], m_afFirstVector[2]);

    pDebugText->Print(aeLocation, aeJustify, str_0109135c, m_afSecondVector[0], m_afSecondVector[1],
                      m_afSecondVector[2]);
}

struct CoverBaseCls
{
    virtual ~CoverBaseCls();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    CoverBaseCls();
};

struct CoverVec3
{
    float x;
    float y;
    float z;
    CoverVec3();
};

struct CoverTimer
{
    unsigned int unk00;
    unsigned int unk04;
    CoverTimer();
};

struct FUN_009d2440_cls : CoverBaseCls
{
    virtual void v0();
    int m_eAnimationState;
    void* m_pLocation;
    CoverVec3 m_curCover;
    CoverVec3 m_curFire;
    CoverVec3 m_thirdVec;
    CoverTimer m_t0;
    CoverTimer m_t1;
    CoverTimer m_t2;
    CoverTimer m_t3;
    CoverTimer m_t4;
    CoverTimer m_t5;
    FUN_009d2440_cls(void* pLoc);
    virtual ~FUN_009d2440_cls();
};

// @fnv 0x009d2440
FUN_009d2440_cls::FUN_009d2440_cls(void* pLoc) : m_eAnimationState(0), m_pLocation(pLoc)
{}

struct FUN_00996ed0_shell
{
    void SaveToBuffer(void* a1);
};

struct FUN_00586150_shell
{
    void* FUN_00586150();
};

struct FUN_0097fb60_shell
{
    int GetFieldAtE8();
};

struct FUN_00865e50_shell
{
    void FUN_00865e50(void* p, int size, int flags);
};

struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(void* a1);
};

struct FUN_009d3800_cls
{
    void FUN_009d3800(void* a1);
};

// @fnv 0x009d3800
void FUN_009d3800_cls::FUN_009d3800(void* a1)
{
    unsigned char flag;

    ((FUN_00996ed0_shell*)this)->SaveToBuffer(a1);
    flag = ((FUN_0097fb60_shell*)((FUN_00586150_shell*)*(void**)((char*)this + 4))->FUN_00586150())->GetFieldAtE8() ==
           *(int*)((char*)this + 0x14);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x10, 4, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(&flag, 1, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x18, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x24, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x30, 0xc, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x3c))->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)((char*)this + 0x44))->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)((char*)this + 0x4c))->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)((char*)this + 0x54))->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)((char*)this + 0x5c))->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)((char*)this + 0x64))->FUN_009a5eb0(a1);
}

class Tile;
struct BGSLoadFormBuffer
{
    void LoadData(void* apData, unsigned int auiSize);
};
struct InterfaceManager
{
    Tile* FUN_00586150();
};

unsigned int __fastcall GetFieldValue(unsigned int* apData);
struct FUN_00996ef0_shell
{
    void FUN_00996ef0(BGSLoadFormBuffer* apBuffer);
};
struct FUN_009a5f20_Timer
{
    char data[8];
    void FUN_009a5f20(BGSLoadFormBuffer* apBuffer);
};
struct FUN_009d38f0_shell : FUN_00996ef0_shell
{
    void* vtbl;
    InterfaceManager* pManager;
    char pad08[8];
    int eState;
    unsigned int uiCoverLocation;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
    float LastPosition[3];
    FUN_009a5f20_Timer kWaitTimer;
    FUN_009a5f20_Timer kWaitingOutTimer;
    FUN_009a5f20_Timer kTimer4c;
    FUN_009a5f20_Timer kTimer54;
    FUN_009a5f20_Timer kTimer5c;
    FUN_009a5f20_Timer kTimer64;
    void FUN_009d38f0(BGSLoadFormBuffer* apBuffer);
};
// Loads state, cover location, three 3-float vectors and six timers from the form buffer, resolving the cover location via the interface manager.
// @fnv 0x009d38f0
void FUN_009d38f0_shell::FUN_009d38f0(BGSLoadFormBuffer* apBuffer)
{
    FUN_00996ef0(apBuffer);
    bool bHasCover = false;
    apBuffer->LoadData(&eState, 4);
    apBuffer->LoadData(&bHasCover, 1);
    if (bHasCover)
        uiCoverLocation = ((FUN_0097fb60_shell*)pManager->FUN_00586150())->GetFieldAtE8();
    else
        uiCoverLocation = GetFieldValue((unsigned int*)pManager->FUN_00586150());
    apBuffer->LoadData(m_afFirstVector, 0xc);
    apBuffer->LoadData(m_afSecondVector, 0xc);
    apBuffer->LoadData(LastPosition, 0xc);
    kWaitTimer.FUN_009a5f20(apBuffer);
    kWaitingOutTimer.FUN_009a5f20(apBuffer);
    kTimer4c.FUN_009a5f20(apBuffer);
    kTimer54.FUN_009a5f20(apBuffer);
    kTimer5c.FUN_009a5f20(apBuffer);
    kTimer64.FUN_009a5f20(apBuffer);
}

struct CoverPoint
{
    float x, y, z;
    CoverPoint operator-(const CoverPoint&) const;
    float FUN_004a7290() const;
};
struct CoverClock
{
    int started;
    float duration;
    bool FUN_0097fa50();
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
    float GetElapsedTime();
    float GetValue();
    float FUN_006a7f50();
    void Reset();
};
struct CoverRequest
{
    virtual ~CoverRequest();
    CoverRequest();
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
    int unka4;
    int unka8;
    int unkac;
};
struct CoverActor
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
    virtual CoverPoint GetAim();
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
    virtual const CoverPoint& GetPosition();

    void StopMoving();
    float FUN_008854d0(bool);
    float GetActorHeight() const;
    void* GetWorld();
    void* GetContainingCell();
    void SetupPath(CoverRequest&, const CoverPoint&, void*, void*, float, int);
    bool RequestPath(CoverRequest*);
    bool IsAttacking();
    float AttackTime();
    void UpdateAttackState();
    bool PathFailed();
    bool PathBuiltFailed();
    bool PathFinished();
};
struct CombatCoverPoint
{
    int unk00, unk04;
    CoverPoint position;
    CoverPoint direction;
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
    bool occupied;
    bool CanFire();
    bool CanRotate();
    void SetFlag(int);
};
struct CoverStamp
{
    int value;
    float GetElapsedTime();
    float FUN_006a7f50();
};
struct CoverState
{
    bool Validate(CombatCoverPoint*);
    bool IsGroup();
    bool CheckPath(const CoverPoint&, const CoverPoint&, CoverActor*, int);
    CoverStamp GetStamp();
    void End(int);
    bool IsBlocked();
};
struct CoverGroup
{
    bool HasLOS(CoverActor*);
};
struct CoverStyle
{
    float GetRandomFloatInRange();
    float GetRandomFloat();
    float GetRandomValue();
};
struct CoverManager
{
    CoverState* FUN_00586150();
    CoverGroup* GetGroup();
    bool FUN_00998a30();
    CoverStyle* FUN_00980070();
};
struct CoverSetting
{
    float* Float();
};
extern CoverSetting originalRuntimeFloatSetting378, originalRuntimeFloatSetting379;
void ComputePositions(CoverManager*, CombatCoverPoint*, CoverPoint&, CoverPoint&);
struct CoverProcedure
{
    int unk00;
    CoverManager* manager;
    int unk08, unk0c;
    unsigned state;
    CombatCoverPoint* location;
    CoverPoint coverPosition, firePosition, lookPosition;
    CoverClock wait, outWait, firing, reevaluate, holding, blocked;
    CoverActor* FUN_00996de0();
    CoverActor* GetTarget();
    void Fail(const char*);
    void ClearLook();
    void LookAt(const CoverPoint&, unsigned char);
    void Action(int);
    void UpdateCoverState();
};
static const char kCoverLOS[] = "Target has LOS on Cover position";
// Validates the cover location, reevaluates paths/LOS, and advances the cover procedure state machine through movement, firing and holding phases.
// @fnv 0x009d25b0
void CoverProcedure::UpdateCoverState()
{
    if (!manager->FUN_00586150()->Validate(location))
    {
        Fail("Cover Location no longer exists");
        return;
    }
    CoverActor* actor_ = FUN_00996de0();
    CoverActor* targetTmp = GetTarget();
    CoverState* combat7 = manager->FUN_00586150();
    CoverGroup* group7 = manager->GetGroup();
    bool evaluatedA = false;
    bool changedVal = false;
    bool canFire4 = location->CanFire();
    bool active8 = manager->FUN_00998a30();
    if (!reevaluate.FUN_0097fa50())
        reevaluate.FUN_008d7f40(1.0f);
    else if (reevaluate.FUN_008d7f80())
    {
        reevaluate.FUN_008d7f40(1.0f);
        evaluatedA = true;
        if (state != 0)
        {
            if (combat7->IsGroup())
            {
                bool reachable4 = combat7->CheckPath(location->direction, coverPosition, targetTmp, 1);
                if (!reachable4 && state != 7)
                {
                    actor_->StopMoving();
                    ClearLook();
                    state = 7;
                    holding.FUN_008d7f40(2.0f);
                    changedVal = true;
                }
            }
            else
            {
                CoverPoint coverPos9 = targetTmp->GetPosition();
                CoverPoint targetPos = location->position;
                CoverPoint delta = coverPos9 - targetPos;
                if (delta.FUN_004a7290() > 589824.0 && group7->HasLOS(targetTmp))
                    location->SetFlag(1);
            }
        }
    }
    switch (state)
    {
    case 0: {
        location->occupied = false;
        ComputePositions(manager, location, coverPosition, firePosition);
        lookPosition = firePosition;
        float height = manager->FUN_00998a30() ? actor_->FUN_008854d0(false) : actor_->GetActorHeight();
        lookPosition.z = height * 0.75 + lookPosition.z;
        CoverRequest request;
        actor_->SetupPath(request, coverPosition, actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
        if (!actor_->RequestPath(&request))
        {
            Fail("Cannot setup path to Cover position");
            return;
        }
        state = 6;
        if (location->CanRotate())
            LookAt(lookPosition, 3);
        Action(3);
        break;
    }
    case 1: {
        if (!actor_->IsAttacking())
        {
            if (combat7->GetStamp().GetElapsedTime() > 0.5 &&
                actor_->AttackTime() < *originalRuntimeFloatSetting378.Float())
            {
                actor_->UpdateAttackState();
            }
            else if (wait.FUN_008d7f80())
            {
                CoverRequest request;
                actor_->SetupPath(request, firePosition, actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
                if (!actor_->RequestPath(&request))
                {
                    Fail("Cannot setup path to Fire position");
                    return;
                }
                if (location->CanRotate())
                    ClearLook();
                LookAt(targetTmp->GetAim(), 1);
                state = 2;
                Action(canFire4 && active8 ? 2 : 1);
            }
        }
        break;
    }
    case 2: {
        if (actor_->PathFailed())
        {
            Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving out" : "Path Building failed to move out");
            return;
        }
        if (actor_->PathFinished())
        {
            state = 3;
            ClearLook();
            outWait.FUN_008d7f40(manager->FUN_00980070()->GetRandomFloat());
        }
        break;
    }
    case 3: {
        CoverStamp stamp = combat7->GetStamp();
        if (stamp.FUN_006a7f50() > wait.FUN_006a7f50())
        {
            state = 4;
            firing.FUN_008d7f40(manager->FUN_00980070()->GetRandomValue());
            blocked.Reset();
        }
        else if (outWait.FUN_008d7f80())
        {
            combat7->End(0);
            Fail("Waited out of cover without firing");
            return;
        }
        else if (outWait.GetElapsedTime() > 2.0 && !combat7->IsGroup() && group7->HasLOS(targetTmp))
        {
            combat7->End(0);
            Fail("Waited out of cover and group member has LOS on target");
            return;
        }
        if (combat7->IsBlocked())
        {
            if (!blocked.FUN_0097fa50())
                blocked.FUN_008d7f40(2.0f);
            else if (blocked.FUN_008d7f80())
            {
                combat7->End(1);
                Fail("Waited out of cover but was blocked");
                return;
            }
        }
        break;
    }
    case 4: {
        float attackTime_ = actor_->AttackTime();
        if (attackTime_ < *originalRuntimeFloatSetting379.Float() || actor_->IsAttacking() || firing.FUN_008d7f80())
        {
            CoverRequest request;
            actor_->SetupPath(request, coverPosition, actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
            if (!actor_->RequestPath(&request))
            {
                Fail("Cannot setup path to move back to Cover position");
                return;
            }
            Action(canFire4 && active8 ? 2 : 1);
            state = 5;
        }
        break;
    }
    case 5: {
        if (actor_->PathFailed())
        {
            Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving in" : "Path Building failed to move in");
            return;
        }
        if (actor_->PathFinished())
        {
            state = 1;
            ClearLook();
            Action(2);
            wait.FUN_008d7f40(manager->FUN_00980070()->GetRandomFloatInRange());
        }
        else
        {
            float dist9 = (actor_->GetPosition() - coverPosition).FUN_004a7290();
            if (dist9 < 1024.0)
            {
                state = 6;
                if (location->CanRotate())
                    LookAt(lookPosition, 3);
                Action(1);
            }
        }
        break;
    }
    case 6: {
        if (actor_->PathFailed())
        {
            Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving in and rotating"
                                           : "Path Building failed to move in and rotate");
            return;
        }
        if (actor_->PathFinished())
        {
            state = 1;
            Action(2);
            wait.FUN_008d7f40(manager->FUN_00980070()->GetRandomFloatInRange());
        }
        break;
    }
    case 7: {
        if (evaluatedA && !changedVal)
        {
            CoverRequest request;
            actor_->SetupPath(request, coverPosition, actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
            if (!actor_->RequestPath(&request))
            {
                Fail("Cannot setup path to move back to Cover position");
                return;
            }
            Action(canFire4 && active8 ? 2 : 1);
            state = 5;
        }
        else if (holding.FUN_008d7f80())
        {
            combat7->End(0);
            Fail(kCoverLOS);
            return;
        }
        else if (holding.GetElapsedTime() > holding.GetValue() / 4.0)
        {
            CoverPoint delta = targetTmp->GetPosition();
            CoverPoint targetPos = actor_->GetPosition();
            CoverPoint actorPos6 = targetPos - delta;
            if (actorPos6.FUN_004a7290() < 262144.0)
            {
                combat7->End(0);
                Fail(kCoverLOS);
            }
        }
        break;
    }
    }
}

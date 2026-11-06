
// src/fallout/ai/combat/combatproceduresearch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatproceduresearch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

enum COMBAT_PROCEDURES
{
    eCombatProcedure = 10
};

struct CombatProcedure
{
    virtual int GetType() = 0;
};

struct CombatProcedureSearch : CombatProcedure
{
    virtual int FUN_009d8c00();
};

// @fnv 0x009d8c00
int CombatProcedureSearch::FUN_009d8c00()
{
    return eCombatProcedure;
}

void __cdecl operator delete(void*);

struct FUN_009d8c10_shell
{
    void __thiscall FUN_009d8c40();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_009d8c40, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x009d8c10
void* FUN_009d8c10_shell::Destroy(unsigned int flags)
{
    FUN_009d8c40();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009d8d00_shell
{
    void SetFieldEC(int param);
};

// @fnv 0x009d8d00
void FUN_009d8d00_shell::SetFieldEC(int aiValue)
{
    *(int*)((char*)this + 0xec) = aiValue;
}

struct TESObjectREFR;
struct TESBoundObject;
struct FUN_009d9fa0_shell
{
    void* m_packed[0x3c / 4];
    TESObjectREFR* m_pReference;
    void ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount, bool abActivatedScriptOnly);
};

// Clears the stored reference when it equals apRef.
// @fnv 0x009d9fa0
void FUN_009d9fa0_shell::ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount,
                                           bool abActivatedScriptOnly)
{
    if (m_pReference == apRef)
        m_pReference = 0;
}

struct FUN_009ca6c0_shell
{
    void __thiscall FUN_009ca6c0();
};

extern int DAT_01091db4;

// @fnv 0x009d8c40
void FUN_009d8c10_shell::FUN_009d8c40()
{
    *reinterpret_cast<void**>(this) = (void*)&DAT_01091db4;
    ((FUN_009ca6c0_shell*)this)->FUN_009ca6c0();
}

struct AvoidSphere
{
    float GetRadius() const;
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_009da570_shell
{
    float GetAvoidRadius() const;
};
// Returns the radius of the AvoidSphere referenced at offset 0xd4, or -1.0f when that pointer is null.
// @fnv 0x009da570
float FUN_009da570_shell::GetAvoidRadius() const
{
    return reinterpret_cast<Flt*>(reinterpret_cast<char*>(const_cast<FUN_009da570_shell*>(this)) + 0xd4)
                   ->
                   operator unsigned int()
               ? reinterpret_cast<AvoidSphere*>(
                     reinterpret_cast<Flt*>(reinterpret_cast<char*>(const_cast<FUN_009da570_shell*>(this)) + 0xd4)
                         ->
                         operator unsigned int())
                     ->GetRadius()
               : -1.0f;
}

struct CoordinateTriple
{
    void __thiscall FUN_00527b70(void*);
};
struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};
struct FUN_009a5eb0_shell
{
    void __thiscall FUN_009a5eb0(BGSSaveFormBuffer*);
};
struct CombatProcedureSaveGameShell
{
    void __thiscall SaveGame(BGSSaveFormBuffer*);
};
struct CombatProcedureSearchSaveShell : CombatProcedureSearch
{
    void __thiscall FUN_009da5c0(BGSSaveFormBuffer*);
};
// Saves the combat procedure search state to the buffer: base data, a 4-byte field at 0x10, sub-objects at 0x2c/0x1c/0x14/0x24, and a pointer at 0x3c.
// @fnv 0x009da5c0
void CombatProcedureSearchSaveShell::FUN_009da5c0(BGSSaveFormBuffer* buffer)
{
    ((CombatProcedureSaveGameShell*)this)->SaveGame(buffer);
    buffer->SaveData((char*)this + 0x10, 4, 0);
    ((CoordinateTriple*)((char*)this + 0x2c))->FUN_00527b70(buffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x1c))->FUN_009a5eb0(buffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x14))->FUN_009a5eb0(buffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x24))->FUN_009a5eb0(buffer);
    buffer->SerializeFormData(*(void**)((char*)this + 0x3c), 0);
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    bool ReadFormIdentifier(void*);
};
struct FUN_00527ba0_Class
{
    void FUN_00527ba0(BGSLoadFormBuffer*);
};
struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct CombatProcedure_LoadGame : CombatProcedure
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct CombatProcedureSearch_LoadGame : CombatProcedureSearch
{
    void FUN_009da640(BGSLoadFormBuffer*);
};
// Loads the base CombatProcedure state, then reads a 4-byte field and loads four sub-objects and a bool from the buffer.
// @fnv 0x009da640
void CombatProcedureSearch_LoadGame::FUN_009da640(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<CombatProcedure_LoadGame*>(this)->LoadGame(buffer);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4);
    reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x2c)->FUN_00527ba0(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x1c)->LoadGame(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x14)->LoadGame(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->LoadGame(buffer);
    buffer->ReadFormIdentifier(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3c));
}

struct BGSLoadFormBuffer;
struct TESForm
{
    virtual void Revert(unsigned int);
    static TESForm* GetFormByID(unsigned int);
};
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
};
struct FUN_009da6c0_holder
{
    unsigned char _pad[0x3c];
    TESObjectREFR* m_pReference;
    void __thiscall RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009da6c0
void __thiscall FUN_009da6c0_holder::RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((TESForm*)this)->TESForm::Revert((unsigned int)apLoadGameBuffer);
    m_pReference =
        m_pReference ? dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID((unsigned int)m_pReference)) : 0;
}

struct Actor
{
    void StopMoving();
    void FUN_008bcd20();
};
struct EffectSetting
{
    EffectSetting* GetCastSound() const;
};
struct CombatProcedureEngageTarget
{
    Actor* FUN_00996de0();
    void FUN_00996e40();
};
struct FUN_009d8c60_shell : CombatProcedureEngageTarget
{
    void __thiscall UpdateEngageTarget();
};
struct FUN_0098c780_shell
{
    void ClearReservedFlag(int);
};
struct FUN_009d8d20_Class
{
    int GetFieldEC();
};
// @fnv 0x009d8c60
void __thiscall FUN_009d8c60_shell::UpdateEngageTarget()
{
    Actor* pattacker = FUN_00996de0();
    EffectSetting* pcombatGroup = ((EffectSetting**)((char*)this + 4))[0]->GetCastSound();
    if (pcombatGroup && ((FUN_009d8d20_Class*)pcombatGroup)->GetFieldEC() == (int)pattacker)
        ((FUN_009d8d00_shell*)pcombatGroup)->SetFieldEC(0);
    pattacker->StopMoving();
    FUN_00996e40();
    if (*(int*)((char*)this + 0x10) == 5 || *(int*)((char*)this + 0x10) == 4)
        pattacker->FUN_008bcd20();
    if (*(int*)((char*)this + 0x10) == 2 && pcombatGroup && *(void**)((char*)this + 0x3c))
        ((FUN_0098c780_shell*)pcombatGroup)->ClearReservedFlag((int)*(void**)((char*)this + 0x3c));
}

extern int DAT_01091db4;

struct FUN_009d8b60_base
{
    FUN_009d8b60_base();
    ~FUN_009d8b60_base();
};

struct FUN_009d8b60_member8
{
    void Init();
    int m_00;
    int m_04;
};

struct FUN_009d8b60_member16
{
    void Init();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_009d8b60_cls : FUN_009d8b60_base
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_009d8b60_member8 m_14;
    FUN_009d8b60_member8 m_1c;
    FUN_009d8b60_member8 m_24;
    FUN_009d8b60_member16 m_2c;
    int m_3c;

    FUN_009d8b60_cls();
};

// Initializes the object: sets the vtable pointer, zeroes m_10 and m_3c, and calls Init on the four member sub-objects.
// @fnv 0x009d8b60
FUN_009d8b60_cls::FUN_009d8b60_cls()
{
    m_vptr = (void*)&DAT_01091db4;
    m_10 = 0;
    m_14.Init();
    m_1c.Init();
    m_24.Init();
    m_2c.Init();
    m_3c = 0;
}

struct FUN_009da550_val
{
    int v;
};

struct FUN_009da550_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    FUN_009da550_val m_iE8;
    FUN_009da550_val* __thiscall GetValue(FUN_009da550_val* apOut);
};

// @fnv 0x009da550
FUN_009da550_val* FUN_009da550_cls::GetValue(FUN_009da550_val* apOut)
{
    *apOut = m_iE8;
    return apOut;
}

namespace SearchDiagnostics {
struct Vector
{
    float x, y, z;
};
struct Reference
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
    virtual const char* Name();
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
    virtual const Vector& Position();
    void* FUN_00575ca0();
};
struct Location
{
    int unk00, unk04, unk08, unk0c;
    const Vector& FUN_006815c0();
    Reference* FUN_0084e3a0();
};
struct Radius
{
    int value;
    double GetClampedDifference();
};
struct Range
{
    int unk00, unk04, unk08, unk0c;
    double FUN_006b9130();
    double FUN_00435e00();
    double FUN_006a7f50();
};
struct Context
{
    Range* FUN_009d9f40();
    Location FUN_009d9f60();
    float GetAvoidRadius();
    Radius GetValue();
    double FUN_009442a0();
    int GetFieldD0();
};
struct Owner
{
    Context* FUN_004fb070();
};
struct Output
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Print(int, int, const char*, ...);
};
extern const char DAT_01090b68[], DAT_01092078[], DAT_0109205c[], DAT_0108cfe4[], DAT_0109204c[], DAT_0109202c[],
    DAT_01092020[], DAT_0109200c[], DAT_01091ff0[], DAT_01091fe0[], DAT_01091fd8[], DAT_01091fb0[], DAT_01091f88[],
    DAT_01091f60[], DAT_01091f40[];
extern const double DAT_01012060, DAT_01017a40;
struct Search
{
    int unk00;
    Owner* owner;
    int unk08, unk0c;
    unsigned int state;
    int unk14, unk18;
    Range range;
    Location location;
    Reference* door;
    Reference* FUN_00996de0();
    void PrintDebugInfo(Output*, int, int);
};
// @fnv 0x009d9fd0
void Search::PrintDebugInfo(Output* output, int x, int y)
{
    Reference* actor = FUN_00996de0();
    Context* context = owner->FUN_004fb070();
    switch (state)
    {
    case 0:
        output->Print(x, y, DAT_01090b68);
        break;
    case 1:
        output->Print(x, y, DAT_01092078);
        output->Print(x, y, DAT_0109205c, location.FUN_006815c0().x, location.FUN_006815c0().y,
                      location.FUN_006815c0().z);
        output->Print(x, y, DAT_0108cfe4, location.FUN_0084e3a0()->Name());
        break;
    case 2:
        output->Print(x, y, DAT_0109204c);
        if (door)
            output->Print(x, y, DAT_0109202c, door->Name(), door->Position().x, door->Position().y, door->Position().z);
        break;
    case 3:
        output->Print(x, y, DAT_01092020);
        break;
    case 4:
        output->Print(x, y, DAT_0109200c);
        output->Print(x, y, DAT_01091ff0, range.FUN_00435e00(), range.FUN_006b9130());
        break;
    case 5:
        output->Print(x, y, DAT_01091fe0);
        output->Print(x, y, DAT_01091ff0, range.FUN_00435e00(), range.FUN_006b9130());
        break;
    case 6:
        output->Print(x, y, DAT_01091fd8);
        output->Print(x, y, DAT_01091ff0, range.FUN_00435e00(), range.FUN_006b9130());
        break;
    case 7:
        output->Print(x, y, DAT_01091fb0);
        output->Print(x, y, DAT_01091ff0, range.FUN_00435e00(), range.FUN_006b9130());
        if (context->FUN_009d9f40()->FUN_006a7f50() < range.FUN_006a7f50() &&
            context->FUN_009d9f60().FUN_0084e3a0() != actor->FUN_00575ca0())
            output->Print(x, y, DAT_01091f88, context->FUN_009d9f40()->FUN_00435e00(),
                          context->FUN_009d9f40()->FUN_006b9130());
        break;
    case 8:
        output->Print(x, y, DAT_01091f60);
        output->Print(x, y, DAT_0109205c, location.FUN_006815c0().x, location.FUN_006815c0().y,
                      location.FUN_006815c0().z);
        output->Print(x, y, DAT_0108cfe4, location.FUN_0084e3a0()->Name());
        break;
    }
    float confidence = context->GetAvoidRadius();
    if (confidence >= DAT_01012060)
        output->Print(x, y, DAT_01091f40, context->GetFieldD0(), context->FUN_009442a0(), confidence * DAT_01017a40,
                      context->GetValue().GetClampedDifference());
}
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_004a7290() const;
};

float WrapAngle(float);

struct GameSettingCollection;
struct SETTING_VALUE
{
    float f;
};

template <typename T> struct SettingT
{
    SETTING_VALUE* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting461;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting462;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting464;
extern SettingT<GameSettingCollection> g_011cecc4;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting465;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting460;
extern SettingT<GameSettingCollection> g_011cfad4;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting463;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting457;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting459;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting458;

extern const float DAT_010162c0;
extern const double DAT_0101db88;
extern const float DAT_0101e704;
extern const double DAT_0106cd60;
extern const float DAT_010231a0;
extern const float DAT_01017718;
extern const double DAT_01012060;
extern const double DAT_01012070;

struct FUN_008d7f40_shell
{
    int m_00;
    int m_04;
    void FUN_008d7f40(float);
    bool FUN_008d7f80();
    double FUN_006a7f50();
};

struct Location16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* FUN_006815c0();
    void* FUN_0084e3a0();
    double FUN_00527a40(const Location16*);
};

struct Obj0049f1c0;

struct BSPortalGraphSub
{
    bool FUN_006e0bc0(void*, int);
    bool FUN_006e0b50(void*);
};

struct TileSub
{
    bool FUN_009a02a0(Location16*, int, int);
    void* GetLODMultType();
    float FUN_009a0b00();
    void SetNodeBlockAndTimestamp(const Location16&);
};

struct S00568fa0
{
    int FUN_00568fa0();
};

struct SearchRef : S00568fa0
{
    void* FUN_0084e3a0();
    const NiPoint3& FUN_006815c0();
    float FUN_00985bb0();
    NiPoint3* FUN_00569000();
    void* FUN_00575ca0();
    void* FUN_00568e50();
    Location16 FUN_00575650();
    void* FUN_0043a3f0();
    void* FUN_00717e50();
    void FUN_006dd6f0(int);
};

struct RangeSub
{
    double FUN_006a7f50();
};

struct ContextSub
{
    BSPortalGraphSub* FUN_009d9f20();
    bool FUN_0097ef30();
    SearchRef* FindBestItem(void*, int, int);
    SearchRef* FindNearestCombatNode(void*, float, int);
    void FUN_0098c750(void*);
    Location16 FUN_009d9f60();
    void* GetFieldEC();
    bool CheckOtherEntriesForTarget(void*, Obj0049f1c0*);
    void SetFieldEC(void*);
    void UpdateProximityTimers(Location16*);
    void FUN_0098c710(void*);
    void FUN_0098c6e0(void*);
    void FUN_00915d20(int);
    RangeSub* FUN_009d9f40();
};

struct OwnerSub
{
    ContextSub* FUN_004fb070();
    TileSub* FUN_00586150();
    int FUN_009d9f00();
};

struct PathingLocation
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

    PathingLocation();
    PathingLocation(const NiPoint3&, void*);
    PathingLocation(Location16*);
    ~PathingLocation();

    NiPoint3 FUN_005c3420() const;
    void FUN_006dd6f0(int);
    bool FUN_006dd6a0();
    bool FUN_006dd610(void*);
    unsigned short GetShortValueAtOffset24();
};

bool FUN_006d7490(PathingLocation*, void*, int, int);

template <typename T> struct NiPointer
{
    int unk00;
    NiPointer(void*);
    ~NiPointer();
};

struct PathingRequestHelper
{
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

    PathingRequestHelper();
    virtual ~PathingRequestHelper();

    void SetUseSoft(bool);
    void SetTargetAngle(float);
    void SetDestination(PathingLocation*);
};

struct PathingRequestLOS : PathingRequestHelper
{
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;

    PathingRequestLOS();
    virtual ~PathingRequestLOS();

    void InitFromActor(void*);
    void SetCantOpenDoors(bool);
    void FUN_008df000();
    void AssignAtOffsetB0(const NiPointer<void>&);
    void FUN_006e5a40(NiPoint3, float);
    void FUN_006e4340(float);
    void SetByteAtOffset9B(int);
    void FUN_009d9ee0(Obj0049f1c0*);
};

struct Outer006d8910
{
    unsigned char GetNeighborCount(unsigned short);
};

struct NavMeshPtr
{
    int unk00;
    NavMeshPtr();
    ~NavMeshPtr();

    Outer006d8910* operator->();
};

struct Obj0049f1c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Obj0049f1c0();
    ~Obj0049f1c0();
};

struct ActorBaseSub
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
    virtual bool v10();
};

struct ActorBaseImpl
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
    ActorBaseSub sub;
};

struct ActorSub : Actor
{
    int FUN_00931850();
    void BuildPathingRequest(void*, const void*, void*, float, int);
    bool SetPathingRequestAvoidNodes(void*);
    void* FUN_00575ca0();
    Location16 FUN_00575650();
    bool DidPathingFail();
    bool FUN_008b3960();
    SearchRef* FUN_008b39d0();
    bool FUN_008b3bb0();
    void FUN_008bcd60();
    double GetMagicProcessValue();
    void FUN_008bcd20();
    bool FUN_008b3860(void*);
    bool FUN_008bb630(void*);
    void FUN_005757d0(float);
    void StopMoving();
    ActorBaseImpl* GetActorBase();

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
    virtual const NiPoint3& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool v135();
};

struct SearchProcedure : CombatProcedureSearch
{
    OwnerSub* owner;
    int unk08;
    int unk0c;
    unsigned int state;
    FUN_008d7f40_shell timer14;
    FUN_008d7f40_shell timer1c;
    FUN_008d7f40_shell timer24;
    Location16 location;
    SearchRef* m_pReference;

    ActorSub* FUN_00996de0();
    void* FUN_00996e00();
    void FUN_009caac0(const char*);
    void FUN_00996e20(int);

    void UpdateSearchState();
};

static const char* g_dummy_sg = "dummy";

// @fnv 0x009d8d40
void SearchProcedure::UpdateSearchState()
{
    ActorSub* pActor2;
    BSPortalGraphSub* m_pPortalConnectivityGraphInfo;
    int hasTarget_2;
    TileSub* pTile2;
    void* pUnk7;
    ContextSub* pContext;

    pActor2 = this->FUN_00996de0();
    pUnk7 = this->FUN_00996e00();
    hasTarget_2 = pActor2->FUN_00931850();
    pContext = this->owner->FUN_004fb070();
    m_pPortalConnectivityGraphInfo = pContext->FUN_009d9f20();
    pTile2 = this->owner->FUN_00586150();

    switch (this->state)
    {
    case 0:
        if (!hasTarget_2 && this->owner->FUN_009d9f00() == 4)
        {
            this->state = 7;
            this->timer1c.FUN_008d7f40(DAT_010162c0);
            break;
        }
        this->m_pReference = 0;
        if (pContext->FUN_0097ef30())
        {
            SearchRef* pObj28 = pContext->FindBestItem(pActor2, 0, 0);
            if (pObj28 && pObj28->FUN_00985bb0() > DAT_0101db88)
            {
                PathingRequestHelper req;
                pActor2->BuildPathingRequest(&req, &pObj28->FUN_006815c0(), pObj28->FUN_0084e3a0(), DAT_0101e704, 0);
                req.SetUseSoft(false);
                if (!pActor2->SetPathingRequestAvoidNodes(&req))
                {
                    this->FUN_009caac0("Cannot setup path to investigate point");
                    break;
                }
                this->state = 1;
                this->timer14.FUN_008d7f40(originalRuntimeFloatSetting461.Float()->f);
                this->location = *(Location16*)pObj28;
            }
            else
            {
                SearchRef* pObjE0 =
                    pContext->FindNearestCombatNode(pActor2,
                                                    (hasTarget_2 == 0) ? originalRuntimeFloatSetting462.Float()->f
                                                                       : originalRuntimeFloatSetting464.Float()->f,
                                                    1);
                if (pObjE0)
                {
                    PathingRequestHelper req;
                    pActor2->BuildPathingRequest(&req, (void*)pObjE0->FUN_00568fa0(), pObjE0->FUN_00575ca0(), 0.0f, 0);
                    NiPoint3 rot = *pObjE0->FUN_00569000();
                    req.SetTargetAngle(WrapAngle(rot.z - 3.1415927410125732));
                    if (!pActor2->SetPathingRequestAvoidNodes(&req))
                    {
                        this->FUN_009caac0("Cannot setup path to search door");
                        break;
                    }
                    this->state = 2;
                    this->m_pReference = pObjE0;
                    pContext->FUN_0098c750(pObjE0);
                }
                else
                {
                    Location16 loc1ac = pContext->FUN_009d9f60();
                    if (m_pPortalConnectivityGraphInfo == 0 || loc1ac.FUN_0084e3a0() != pActor2->FUN_00575ca0())
                    {
                        Location16 loc1bc = pActor2->FUN_00575650();
                        if (loc1bc.FUN_00527a40(&loc1ac) > DAT_0106cd60)
                        {
                            PathingRequestHelper req;
                            if (pTile2->FUN_009a02a0(&loc1ac, 1, 0))
                            {
                                pActor2->BuildPathingRequest(&req, loc1ac.FUN_006815c0(), loc1ac.FUN_0084e3a0(),
                                                             DAT_0101e704, 0);
                                if (!pActor2->SetPathingRequestAvoidNodes(&req))
                                {
                                    this->FUN_009caac0("Cannot setup path to search center");
                                    break;
                                }
                                this->location = loc1ac;
                                this->state = 8;
                            }
                        }
                        else
                        {
                            this->state = 6;
                            this->timer1c.FUN_008d7f40(1.0f);
                        }
                    }
                    else
                    {
                        void* p360 = pContext->GetFieldEC();
                        if (p360 && p360 != pActor2)
                        {
                            break;
                        }
                        PathingRequestLOS losReq;
                        losReq.InitFromActor(pActor2);
                        if (pActor2->v135())
                        {
                            losReq.SetCantOpenDoors(pActor2->GetActorBase()->sub.v10());
                        }
                        losReq.FUN_008df000();
                        losReq.AssignAtOffsetB0(m_pPortalConnectivityGraphInfo);
                        SearchRef* pSearch = (SearchRef*)pTile2->GetLODMultType();
                        if (pSearch && (*(unsigned char*)pSearch == 1 || *(unsigned char*)pSearch == 2 ||
                                        *(unsigned char*)pSearch == 3))
                        {
                            losReq.FUN_006e5a40(*(NiPoint3*)&((SearchRef*)((char*)pSearch + 8))->FUN_006815c0(),
                                                pTile2->FUN_009a0b00());
                        }
                        if (pObj28 && pObj28->FUN_0084e3a0() == pActor2->FUN_00575ca0())
                        {
                            losReq.SetDestination(&PathingLocation(pObj28->FUN_006815c0(), pActor2));
                        }
                        losReq.FUN_006e4340(DAT_010231a0);
                        losReq.SetByteAtOffset9B(0);
                        Obj0049f1c0 objLoc;
                        if (pContext->CheckOtherEntriesForTarget(pActor2, &objLoc))
                        {
                            losReq.FUN_009d9ee0(&objLoc);
                        }
                        if (!pActor2->FUN_008bb630(&losReq))
                        {
                            this->FUN_009caac0("Cannot setup LOS search path");
                            break;
                        }
                        pContext->SetFieldEC(pActor2);
                        this->timer14.FUN_008d7f40(g_011cecc4.Float()->f);
                        this->state = 3;
                        this->timer24.FUN_008d7f40(originalRuntimeFloatSetting465.Float()->f);
                    }
                }
            }
            this->FUN_00996e20(1);
        }
        break;

    case 1:
    case 8:
        if (pActor2->DidPathingFail())
        {
            if (!pActor2->FUN_008b3960())
            {
                pTile2->SetNodeBlockAndTimestamp(this->location);
            }
            this->FUN_009caac0(pActor2->FUN_008b3960() ? "Pathing failed while moving to destination"
                                                       : "Path Building failed to destination");
            break;
        }
        {
            bool bFlag361 = false;
            if (this->state == 1 && this->timer14.FUN_008d7f80())
            {
                Location16 loc374 = pActor2->FUN_00575650();
                if (loc374.FUN_00527a40(&this->location) <
                    originalRuntimeFloatSetting460.Float()->f * originalRuntimeFloatSetting460.Float()->f)
                {
                    PathingLocation loc39c(&this->location);
                    if (FUN_006d7490(&loc39c, loc374.FUN_006815c0(), 0, 0))
                    {
                        bFlag361 = true;
                    }
                }
                this->timer14.FUN_008d7f40(g_011cfad4.Float()->f);
            }
            if (bFlag361 || pActor2->FUN_008b3bb0())
            {
                if (bFlag361)
                {
                    pActor2->StopMoving();
                }
                pContext->UpdateProximityTimers(&this->location);
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;

    case 2:
        if (pActor2->DidPathingFail())
        {
            if (!pActor2->FUN_008b3960() && this->m_pReference)
            {
                pTile2->SetNodeBlockAndTimestamp(this->m_pReference->FUN_00575650());
                pContext->FUN_0098c710(this->m_pReference);
            }
            this->FUN_009caac0(pActor2->FUN_008b3960() ? "Pathing failed while moving to search door"
                                                       : "Path Building failed to search door");
            break;
        }
        if (pActor2->FUN_008b3bb0())
        {
            if (this->m_pReference)
            {
                pContext->FUN_0098c6e0(this->m_pReference);
                if (!hasTarget_2)
                {
                    pActor2->FUN_008bcd60();
                    this->state = 4;
                    this->timer1c.FUN_008d7f40(DAT_01017718);
                }
                else
                {
                    PathingRequestHelper req;
                    SearchRef* p3a0 = (SearchRef*)this->m_pReference->FUN_00568e50();
                    if (!p3a0)
                    {
                        break;
                    }
                    pActor2->BuildPathingRequest(&req, p3a0->FUN_00717e50(), p3a0->FUN_0043a3f0(), 0.0f, 0);
                    if (!pActor2->SetPathingRequestAvoidNodes(&req))
                    {
                        this->FUN_009caac0("Cannot setup path through search door");
                        break;
                    }
                    this->state = 2;
                }
                this->m_pReference = 0;
            }
            else
            {
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;

    case 3: {
        bool bFlag455;
        if (pActor2->DidPathingFail())
        {
            if (!pActor2->FUN_008b3960())
            {
                SearchRef* p45c = pActor2->FUN_008b39d0();
                if (p45c && m_pPortalConnectivityGraphInfo)
                {
                    p45c->FUN_006dd6f0(0);
                    m_pPortalConnectivityGraphInfo->FUN_006e0bc0(p45c, 1);
                    pContext->FUN_00915d20(1);
                }
            }
            this->FUN_009caac0(pActor2->FUN_008b3960() ? "Pathing failed while searching"
                                                       : "Path Building failed to search");
            break;
        }
        if (this->timer24.FUN_008d7f80() && !hasTarget_2)
        {
            this->timer24.FUN_008d7f40(originalRuntimeFloatSetting465.Float()->f);
            SearchRef* pObj460 = pContext->FindNearestCombatNode(pActor2, originalRuntimeFloatSetting463.Float()->f, 1);
            if (pObj460)
            {
                PathingRequestHelper req;
                pActor2->BuildPathingRequest(&req, (void*)pObj460->FUN_00568fa0(), pObj460->FUN_00575ca0(), 0.0f, 0);
                if (pActor2->SetPathingRequestAvoidNodes(&req))
                {
                    this->state = 2;
                    this->m_pReference = pObj460;
                    pContext->FUN_0098c750(pObj460);
                    break;
                }
            }
        }
        {
            bFlag455 = false;
            if (m_pPortalConnectivityGraphInfo && this->timer14.FUN_008d7f80())
            {
                PathingLocation loc53c;
                if (pActor2->FUN_008b3860(&loc53c))
                {
                    NiPoint3 vDiff = pActor2->Position() - loc53c.FUN_005c3420();
                    float dist = vDiff.FUN_004a7290();
                    if (dist < originalRuntimeFloatSetting457.Float()->f * originalRuntimeFloatSetting457.Float()->f)
                    {
                        loc53c.FUN_006dd6f0(0);
                        if (loc53c.FUN_006dd6a0() && m_pPortalConnectivityGraphInfo->FUN_006e0b50(&loc53c))
                        {
                            bFlag455 = true;
                            NavMeshPtr navMesh;
                            if (loc53c.FUN_006dd610(&navMesh))
                            {
                                char cRes = navMesh->GetNeighborCount(loc53c.GetShortValueAtOffset24());
                                if ((cRes == 1 && dist > originalRuntimeFloatSetting459.Float()->f *
                                                             originalRuntimeFloatSetting459.Float()->f) ||
                                    (cRes == 2 && dist > originalRuntimeFloatSetting458.Float()->f *
                                                             originalRuntimeFloatSetting458.Float()->f))
                                {
                                    bFlag455 = false;
                                }
                            }
                            if (bFlag455)
                            {
                                pActor2->StopMoving();
                            }
                        }
                    }
                }
                this->timer14.FUN_008d7f40(g_011cecc4.Float()->f);
            }
            if (bFlag455 || pActor2->FUN_008b3bb0())
            {
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;
    }

    case 4:
        if (pActor2->GetMagicProcessValue() <= DAT_01012060)
        {
            if (this->m_pReference)
            {
                NiPoint3 rot = *this->m_pReference->FUN_00569000();
                pActor2->FUN_005757d0(WrapAngle(rot.z));
            }
            this->state = 5;
        }
        break;

    case 5:
        if (this->timer1c.FUN_008d7f80())
        {
            if (pActor2->GetMagicProcessValue() < DAT_01012070)
            {
                pActor2->FUN_008bcd20();
            }
            this->state = 0;
        }
        break;

    case 6:
        if (this->timer1c.FUN_008d7f80())
        {
            this->state = 0;
        }
        break;

    case 7:
        if (pContext->FUN_009d9f40()->FUN_006a7f50() < this->timer1c.FUN_006a7f50())
        {
            if (pContext->FUN_009d9f60().FUN_0084e3a0() != pActor2->FUN_00575ca0())
            {
                break;
            }
        }
        if (this->timer1c.FUN_008d7f80())
        {
            this->state = 0;
        }
        break;
    }
}

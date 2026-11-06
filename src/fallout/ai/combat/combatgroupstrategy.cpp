
// src/fallout/ai/combat/combatgroupstrategy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatgroupstrategy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00990890_shell
{
    unsigned int FUN_00990890();
};

// @fnv 0x00990890
unsigned int FUN_00990890_shell::FUN_00990890()
{
    return reinterpret_cast<ArrSI*>(this + 0x18)->GetFlags();
}

namespace fnv_00990a60 {
struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00990a60_shell
{
    unsigned int GetArrFlags();
};

// @fnv 0x00990a60
unsigned int FUN_00990a60_shell::GetArrFlags()
{
    return ((ArrSI*)(this + 0x28))->GetFlags();
}
}  // namespace fnv_00990a60

struct FUN_00844160_holder
{
    void __thiscall FUN_00844160(int);
};

struct FUN_00990a80_shell
{
    void __thiscall ForwardToHolder(int arg);
};

// @fnv 0x00990a80
void __thiscall FUN_00990a80_shell::ForwardToHolder(int arg)
{
    ((FUN_00844160_holder*)((char*)this + 0x28))->FUN_00844160(arg);
}

struct FUN_00844160_shell
{
    void __thiscall FUN_00844160(int state);
};

struct FUN_00990aa0_shell
{
    void __thiscall FUN_00990aa0(int state);
};

void __thiscall FUN_00844160_shell::FUN_00844160(int state)
{}

// @fnv 0x00990aa0
void __thiscall FUN_00990aa0_shell::FUN_00990aa0(int state)
{
    ((FUN_00844160_shell*)((char*)this + 0x18))->FUN_00844160(state);
}

struct ActorCombatGroup
{
    unsigned int GetCount(void);
    void SetElementValue(int i, int a2);
};

struct MarkerStruct
{
};

struct CombatGroupStrategyFallBack
{
    void Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

// Iterates over every member of the group and calls SetElementValue with index i and value 2.
// @fnv 0x00990bd0
void CombatGroupStrategyFallBack::Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int i = 0;
    for (; i < apGroup->GetCount(); i++)
    {
        apGroup->SetElementValue((int)i, 2);
    }
}

namespace fnv_00990d30 {
struct ActorCombatGroup
{
    void* GetActorAtIndex(int);
};

struct CombatGroupStrategyAmbush
{
    bool FUN_00990d30(ActorCombatGroup*);
};

// Returns true if apGroup's lookup for index 3 returns a non-null value, otherwise false.
// @fnv 0x00990d30
bool CombatGroupStrategyAmbush::FUN_00990d30(ActorCombatGroup* apGroup)
{
    if (apGroup->GetActorAtIndex(3) == 0)
        return false;
    return true;
}
}  // namespace fnv_00990d30

struct FUN_00990480_shell
{
    bool FUN_00990480();
};

// Returns whether the float at offset 0x58 is greater than the float at offset 0x5c.
// @fnv 0x00990480
bool FUN_00990480_shell::FUN_00990480()
{
    return *(float*)((char*)this + 0x58) > *(float*)((char*)this + 0x5c);
}

struct Grp_Call2
{
    bool __thiscall FUN_009899a0();
};
struct Holder904c0
{
    Grp_Call2* m_pCombatData;
    int _pad;
    int m_iValue;
    unsigned char __thiscall FUN_009904c0();
};
// If the cached flag is unset, evaluates the held object's check and stores the result; returns whether the cached flag equals 1.
// @fnv 0x009904c0
unsigned char __thiscall Holder904c0::FUN_009904c0()
{
    if (m_iValue == -1)
        m_iValue = m_pCombatData->FUN_009899a0() != 0;
    return m_iValue == 1;
}

struct FUN_009905a0_shell
{
    void __thiscall UpdateMinProgress();
};
struct FUN_00990570_shell
{
    unsigned int __thiscall FUN_00990570();
};
// @fnv 0x00990570
unsigned int __thiscall FUN_00990570_shell::FUN_00990570()
{
    if (*(unsigned int*)((char*)this + 0x10) == 0x80000000)
        ((FUN_009905a0_shell*)this)->UpdateMinProgress();
    return *(unsigned int*)((char*)this + 0x10);
}

extern const double DAT_01026998;
struct DataOps
{
    int __thiscall _ref_00726070();
    double __thiscall GetCachedValue();
};
struct GroupOps
{
    bool __thiscall FUN_0098a470(int, float);
};
struct DummyFallback
{
    bool __thiscall CanExecute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};
// @fnv 0x00990b70
bool __thiscall DummyFallback::CanExecute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    if (((DataOps*)apGroupData)->_ref_00726070() < 2)
        return false;
    if (!((GroupOps*)apGroup)->FUN_0098a470(0, 30.0f))
        return false;
    if (((DataOps*)apGroupData)->GetCachedValue() > DAT_01026998)
        return false;
    return true;
}

struct HolderFor410
{
    int __thiscall FindByValue(int);
};
struct TargetClass
{
    bool __thiscall FUN_00990c10(struct ActorCombatGroup*);
};
// Calls FindByValue with 2 on the group and returns true if it succeeds, otherwise false.
// @fnv 0x00990c10
bool TargetClass::FUN_00990c10(struct ActorCombatGroup* apGroup)
{
    if (!((HolderFor410*)apGroup)->FindByValue(2))
        return false;
    return true;
}

struct CombatGroupStrategyAmbush
{
    void __thiscall Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

// @fnv 0x00990cb0
void __thiscall CombatGroupStrategyAmbush::Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int i;
    unsigned int i2;
    unsigned int ifallBackCount4 = apGroup->GetCount() >> 1;
    for (i = 0; i < ifallBackCount4; ++i)
    {
        apGroup->SetElementValue(i, 2);
    }
    for (i2 = ifallBackCount4; i2 < apGroup->GetCount(); ++i2)
    {
        apGroup->SetElementValue(i2, 3);
    }
}

struct IntPair
{
    int _0;
    int _4;
};
struct CombatGroupStrategyAdvance
{
    void __thiscall Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};
struct FUN_00990aa0_helper
{
    IntPair* __thiscall FUN_00990aa0(int);
};
// Iterates the group data's members and calls SetElementValue on the group with each member's _4 value and 4.
// @fnv 0x00990e70
void __thiscall CombatGroupStrategyAdvance::Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    int i;
    IntPair* pmember;
    for (i = 0; i < (int)((ActorCombatGroup*)apGroupData)->GetCount(); i++)
    {
        pmember = ((FUN_00990aa0_helper*)apGroupData)->FUN_00990aa0(i);
        apGroup->SetElementValue(pmember->_4, 4);
    }
}

namespace fnv_00990ec0 {
struct FUN_0098a410_cls
{
    int __thiscall FindByValue(int);
};
struct CombatGroupStrategyAdvance
{
    bool __thiscall FUN_00990ec0(ActorCombatGroup* apGroup);
};
// Calls FindByValue with 4 on apGroup and returns true if the result is nonzero, false otherwise.
// @fnv 0x00990ec0
bool __thiscall CombatGroupStrategyAdvance::FUN_00990ec0(ActorCombatGroup* apGroup)
{
    if (((FUN_0098a410_cls*)apGroup)->FindByValue(4) == 0)
        return false;
    return true;
}
}  // namespace fnv_00990ec0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char* buffer, unsigned int size, const char* name);
};

char* __cdecl FUN_004812f0(const char* lhs, const char* rhs);
int __cdecl FUN_0098e980(int index);
int __cdecl FUN_00eca7f4(int character);

extern const char* DAT_011a4ed0[4];

// Copies apName into a 260-byte buffer, lowercases it, then compares it against four names and returns the matching index's value or 0.
// @fnv 0x00990250
int FUN_00990250(const char* apName)
{
    char psearchName[260];
    char* pChar;

    TaskQueueInterface::CopyStringToBuffer(psearchName, 0x104, apName);
    pChar = psearchName;
    while (*pChar)
    {
        *pChar = static_cast<char>(FUN_00eca7f4(*pChar));
        ++pChar;
    }

    for (unsigned int i = 0; i < 4; ++i)
    {
        if (FUN_004812f0(DAT_011a4ed0[i], psearchName) != 0)
        {
            return FUN_0098e980(i);
        }
    }

    return 0;
}

struct FUN_00990a60_shell
{
    unsigned int __thiscall GetArrFlags();
};

struct FUN_00990a80_member
{
    IntPair* __thiscall ForwardToHolder(unsigned int index);
};

struct FUN_00990aa0_member
{
    IntPair* __thiscall FUN_00990aa0(unsigned int index);
};

struct FUN_00990640_shell
{
    void __thiscall SortMembersByTargetDistance();
};

struct FUN_00990930_shell
{
    void __thiscall Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

// @fnv 0x00990930
void FUN_00990930_shell::Execute(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int irangedMemberCount;
    unsigned int itotalMemberCount;
    float frangedPercentage;
    unsigned int irangedFlankers;
    unsigned int imeleeMemberCount;

    imeleeMemberCount = reinterpret_cast<FUN_00990a60_shell*>(apGroupData)->GetArrFlags();

    {
        unsigned int i;
        IntPair* pmember;

        for (i = 0; i < imeleeMemberCount; ++i)
        {
            pmember = reinterpret_cast<FUN_00990a80_member*>(apGroupData)->ForwardToHolder(i);
            apGroup->SetElementValue(pmember->_4, 1);
        }
    }

    irangedMemberCount = reinterpret_cast<ActorCombatGroup*>(apGroupData)->GetCount();
    itotalMemberCount = reinterpret_cast<DataOps*>(apGroupData)->_ref_00726070();
    frangedPercentage = static_cast<float>(irangedMemberCount) / static_cast<float>(itotalMemberCount);
    irangedFlankers = 0;

    if (frangedPercentage > 0.5)
        irangedFlankers = static_cast<unsigned int>((frangedPercentage - 0.5) * irangedMemberCount);

    if (irangedFlankers > 0)
    {
        reinterpret_cast<FUN_00990640_shell*>(apGroupData)->SortMembersByTargetDistance();

        {
            unsigned int i;
            IntPair* pmember;

            for (i = irangedMemberCount - irangedFlankers; i < irangedMemberCount; ++i)
            {
                pmember = reinterpret_cast<FUN_00990aa0_member*>(apGroupData)->FUN_00990aa0(i);
                apGroup->SetElementValue(pmember->_4, 1);
            }
        }
    }
}

struct CombatMemberState
{
    bool GetByteAtOffset();
    bool FUN_00990480();
};
struct MemberController
{
    CombatMemberState* FUN_00586150();
};
struct CombatMemberActor
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual void Reserved111();
    virtual void Reserved112();
    virtual void Reserved113();
    virtual void Reserved114();
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual void Reserved125();
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual void Reserved136();
    virtual void Reserved137();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void Reserved193();
    virtual void Reserved194();
    virtual void Reserved195();
    virtual void Reserved196();
    virtual void Reserved197();
    virtual void Reserved198();
    virtual void Reserved199();
    virtual void Reserved200();
    virtual void Reserved201();
    virtual void Reserved202();
    virtual void Reserved203();
    virtual void Reserved204();
    virtual void Reserved205();
    virtual void Reserved206();
    virtual void Reserved207();
    virtual void Reserved208();
    virtual void Reserved209();
    virtual void Reserved210();
    virtual void Reserved211();
    virtual void Reserved212();
    virtual void Reserved213();
    virtual void Reserved214();
    virtual void Reserved215();
    virtual void Reserved216();
    virtual void Reserved217();
    virtual void Reserved218();
    virtual void Reserved219();
    virtual void Reserved220();
    virtual void Reserved221();
    virtual void Reserved222();
    virtual void Reserved223();
    virtual void Reserved224();
    virtual void Reserved225();
    virtual void Reserved226();
    virtual void Reserved227();
    virtual void Reserved228();
    virtual void Reserved229();
    virtual void Reserved230();
    virtual void Reserved231();
    virtual void Reserved232();
    virtual void Reserved233();
    virtual void Reserved234();
    virtual void Reserved235();
    virtual void Reserved236();
    virtual void Reserved237();
    virtual void Reserved238();
    virtual void Reserved239();
    virtual void Reserved240();
    virtual void Reserved241();
    virtual void Reserved242();
    virtual void Reserved243();
    virtual void Reserved244();
    virtual void Reserved245();
    virtual void Reserved246();
    virtual void Reserved247();
    virtual void Reserved248();
    virtual void Reserved249();
    virtual void Reserved250();
    virtual void Reserved251();
    virtual void Reserved252();
    virtual void Reserved253();
    virtual void Reserved254();
    virtual void Reserved255();
    virtual void Reserved256();
    virtual void Reserved257();
    virtual void Reserved258();
    virtual void Reserved259();
    virtual void Reserved260();
    virtual void Reserved261();
    virtual void Reserved262();
    virtual void Reserved263();
    virtual void Reserved264();
    virtual void Reserved265();
    virtual MemberController* GetController();
};
struct GroupMembers
{
    unsigned int FUN_00990890();
    CombatMemberActor* GetIntAt(unsigned int);
};
struct IndexedMember
{
    CombatMemberActor* member;
    unsigned int index;
    IndexedMember(CombatMemberActor*, unsigned int);
};
struct IndexedMemberArray
{
    void* data;
    unsigned int size, capacity, growth;
    IndexedMemberArray();
    ~IndexedMemberArray();
    void InsertAtEnd(const IndexedMember&);
};
struct FUN_00990320
{
    GroupMembers* group;
    unsigned int activeCount;
    int intersectionCount;
    int minimum;
    int maximum;
    float strength;
    IndexedMemberArray normalMembers;
    IndexedMemberArray specialMembers;
    FUN_00990320(GroupMembers*);
};
// @fnv 0x00990320
FUN_00990320::FUN_00990320(GroupMembers* pGroup)
    : group(pGroup), activeCount(0), intersectionCount(-1), minimum(0x7fffffff), maximum(0x80000000), strength(0.0f)
{
    unsigned int count = pGroup->FUN_00990890();
    for (unsigned int index = 0; index < count; ++index)
    {
        CombatMemberActor* aActor = pGroup->GetIntAt(index);
        CombatMemberState* state = aActor->GetController()->FUN_00586150();
        if (!state->GetByteAtOffset())
        {
            ++activeCount;
            if (state->FUN_00990480())
                specialMembers.InsertAtEnd(IndexedMember(aActor, index));
            else
                normalMembers.InsertAtEnd(IndexedMember(aActor, index));
        }
    }
}

extern const float g_011dadbc_arg1;
struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode* node);

struct CombatGroupStrategyFlank
{
    virtual bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup);
};

// @fnv 0x009908b0
bool CombatGroupStrategyFlank::CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup)
{
    if ((int)FUN_00726070((ContNode*)apGroup) < 3)
    {
        return false;
    }
    if ((int)reinterpret_cast<FUN_00990890_shell*>(apGroup)->FUN_00990890() < 1)
    {
        return false;
    }
    if (!reinterpret_cast<GroupOps*>(apGroupData)->FUN_0098a470(2, g_011dadbc_arg1))
    {
        return false;
    }
    if ((int)reinterpret_cast<FUN_00990570_shell*>(apGroup)->FUN_00990570() <= 0)
    {
        return false;
    }
    if (reinterpret_cast<Holder904c0*>(apGroup)->FUN_009904c0())
    {
        return false;
    }
    return true;
}

struct NiPoint4
{
    float x, y, z, w;
};
struct CombatGroupMember
{
    int FUN_00575650(NiPoint4*, float, int);
};
extern const float DAT_01050b98;
struct CombatGroupMethods
{
    int FUN_0098a340(unsigned);
    CombatGroupMember* GetIntAt(unsigned);
    int FindRefInRadius(int);
};
struct CombatGroupStrategy
{
    bool Update(ActorCombatGroup*);
};
// @fnv 0x00990ac0
bool CombatGroupStrategy::Update(ActorCombatGroup* group)
{
    bool bFound = false;
    unsigned count = group->GetCount();
    for (unsigned index = 0; index < count; ++index)
    {
        if (((CombatGroupMethods*)group)->FUN_0098a340(index) == 1)
        {
            CombatGroupMember* pData = ((CombatGroupMethods*)group)->GetIntAt(index);
            NiPoint4 position;
            if (((CombatGroupMethods*)group)->FindRefInRadius(pData->FUN_00575650(&position, DAT_01050b98, 0)))
                group->SetElementValue(index, 0);
            else
                bFound = true;
        }
    }
    if (!bFound)
        return false;
    return true;
}

extern const float DAT_01034294;

struct FUN_00990c40_cls
{
    bool CanExecute(int a1, int a2);
};

struct FUN_00990c40_arg2
{
    int _ref_00726070();
    int FUN_00990570();
    unsigned char FUN_009904c0();
};

struct FUN_00990c40_arg1
{
    bool FUN_0098a470(int count, float value);
};

// @fnv 0x00990c40
bool FUN_00990c40_cls::CanExecute(int a1, int a2)
{
    if (((FUN_00990c40_arg2*)a2)->_ref_00726070() < 2)
    {
        return false;
    }
    if (!((FUN_00990c40_arg1*)a1)->FUN_0098a470(3, DAT_01034294))
    {
        return false;
    }
    if (((FUN_00990c40_arg2*)a2)->FUN_00990570() <= 0)
    {
        return false;
    }
    if (((FUN_00990c40_arg2*)a2)->FUN_009904c0() != 0)
    {
        return false;
    }
    return true;
}

struct Vec990d60
{
    float x, y, z;
    Vec990d60 FUN_00439ef0(const Vec990d60*);
    double FUN_004a7290();
};
extern const double DAT_0101ece0;
struct Target990d60
{
    virtual void unknown_slot_000();
    virtual void unknown_slot_001();
    virtual void unknown_slot_002();
    virtual void unknown_slot_003();
    virtual void unknown_slot_004();
    virtual void unknown_slot_005();
    virtual void unknown_slot_006();
    virtual void unknown_slot_007();
    virtual void unknown_slot_008();
    virtual void unknown_slot_009();
    virtual void unknown_slot_010();
    virtual void unknown_slot_011();
    virtual void unknown_slot_012();
    virtual void unknown_slot_013();
    virtual void unknown_slot_014();
    virtual void unknown_slot_015();
    virtual void unknown_slot_016();
    virtual void unknown_slot_017();
    virtual void unknown_slot_018();
    virtual void unknown_slot_019();
    virtual void unknown_slot_020();
    virtual void unknown_slot_021();
    virtual void unknown_slot_022();
    virtual void unknown_slot_023();
    virtual void unknown_slot_024();
    virtual void unknown_slot_025();
    virtual void unknown_slot_026();
    virtual void unknown_slot_027();
    virtual void unknown_slot_028();
    virtual void unknown_slot_029();
    virtual void unknown_slot_030();
    virtual void unknown_slot_031();
    virtual void unknown_slot_032();
    virtual void unknown_slot_033();
    virtual void unknown_slot_034();
    virtual void unknown_slot_035();
    virtual void unknown_slot_036();
    virtual void unknown_slot_037();
    virtual void unknown_slot_038();
    virtual void unknown_slot_039();
    virtual void unknown_slot_040();
    virtual void unknown_slot_041();
    virtual void unknown_slot_042();
    virtual void unknown_slot_043();
    virtual void unknown_slot_044();
    virtual void unknown_slot_045();
    virtual void unknown_slot_046();
    virtual void unknown_slot_047();
    virtual void unknown_slot_048();
    virtual void unknown_slot_049();
    virtual void unknown_slot_050();
    virtual void unknown_slot_051();
    virtual void unknown_slot_052();
    virtual void unknown_slot_053();
    virtual void unknown_slot_054();
    virtual void unknown_slot_055();
    virtual void unknown_slot_056();
    virtual void unknown_slot_057();
    virtual void unknown_slot_058();
    virtual void unknown_slot_059();
    virtual void unknown_slot_060();
    virtual void unknown_slot_061();
    virtual void unknown_slot_062();
    virtual void unknown_slot_063();
    virtual void unknown_slot_064();
    virtual void unknown_slot_065();
    virtual void unknown_slot_066();
    virtual void unknown_slot_067();
    virtual void unknown_slot_068();
    virtual void unknown_slot_069();
    virtual void unknown_slot_070();
    virtual void unknown_slot_071();
    virtual void unknown_slot_072();
    virtual void unknown_slot_073();
    virtual void unknown_slot_074();
    virtual void unknown_slot_075();
    virtual void unknown_slot_076();
    virtual void unknown_slot_077();
    virtual void unknown_slot_078();
    virtual void unknown_slot_079();
    virtual void unknown_slot_080();
    virtual void unknown_slot_081();
    virtual void unknown_slot_082();
    virtual void unknown_slot_083();
    virtual void unknown_slot_084();
    virtual void unknown_slot_085();
    virtual void unknown_slot_086();
    virtual void unknown_slot_087();
    virtual void unknown_slot_088();
    virtual void unknown_slot_089();
    virtual void unknown_slot_090();
    virtual void unknown_slot_091();
    virtual void unknown_slot_092();
    virtual void unknown_slot_093();
    virtual void unknown_slot_094();
    virtual void unknown_slot_095();
    virtual void unknown_slot_096();
    virtual void unknown_slot_097();
    virtual void unknown_slot_098();
    virtual void unknown_slot_099();
    virtual void unknown_slot_100();
    virtual void unknown_slot_101();
    virtual void unknown_slot_102();
    virtual void unknown_slot_103();
    virtual void unknown_slot_104();
    virtual void unknown_slot_105();
    virtual void unknown_slot_106();
    virtual void unknown_slot_107();
    virtual void unknown_slot_108();
    virtual void unknown_slot_109();
    virtual void unknown_slot_110();
    virtual void unknown_slot_111();
    virtual void unknown_slot_112();
    virtual void unknown_slot_113();
    virtual void unknown_slot_114();
    virtual void unknown_slot_115();
    virtual void unknown_slot_116();
    virtual void unknown_slot_117();
    virtual void unknown_slot_118();
    virtual void unknown_slot_119();
    virtual void unknown_slot_120();
    virtual void unknown_slot_121();
    virtual void unknown_slot_122();
    virtual void unknown_slot_123();
    virtual void unknown_slot_124();
    virtual Vec990d60* GetTargetValue();
};
struct Handle990d60
{
    Target990d60* FUN_004030b0();
};
struct Actor990d60
{
    virtual void unknown_slot_000();
    virtual void unknown_slot_001();
    virtual void unknown_slot_002();
    virtual void unknown_slot_003();
    virtual void unknown_slot_004();
    virtual void unknown_slot_005();
    virtual void unknown_slot_006();
    virtual void unknown_slot_007();
    virtual void unknown_slot_008();
    virtual void unknown_slot_009();
    virtual void unknown_slot_010();
    virtual void unknown_slot_011();
    virtual void unknown_slot_012();
    virtual void unknown_slot_013();
    virtual void unknown_slot_014();
    virtual void unknown_slot_015();
    virtual void unknown_slot_016();
    virtual void unknown_slot_017();
    virtual void unknown_slot_018();
    virtual void unknown_slot_019();
    virtual void unknown_slot_020();
    virtual void unknown_slot_021();
    virtual void unknown_slot_022();
    virtual void unknown_slot_023();
    virtual void unknown_slot_024();
    virtual void unknown_slot_025();
    virtual void unknown_slot_026();
    virtual void unknown_slot_027();
    virtual void unknown_slot_028();
    virtual void unknown_slot_029();
    virtual void unknown_slot_030();
    virtual void unknown_slot_031();
    virtual void unknown_slot_032();
    virtual void unknown_slot_033();
    virtual void unknown_slot_034();
    virtual void unknown_slot_035();
    virtual void unknown_slot_036();
    virtual void unknown_slot_037();
    virtual void unknown_slot_038();
    virtual void unknown_slot_039();
    virtual void unknown_slot_040();
    virtual void unknown_slot_041();
    virtual void unknown_slot_042();
    virtual void unknown_slot_043();
    virtual void unknown_slot_044();
    virtual void unknown_slot_045();
    virtual void unknown_slot_046();
    virtual void unknown_slot_047();
    virtual void unknown_slot_048();
    virtual void unknown_slot_049();
    virtual void unknown_slot_050();
    virtual void unknown_slot_051();
    virtual void unknown_slot_052();
    virtual void unknown_slot_053();
    virtual void unknown_slot_054();
    virtual void unknown_slot_055();
    virtual void unknown_slot_056();
    virtual void unknown_slot_057();
    virtual void unknown_slot_058();
    virtual void unknown_slot_059();
    virtual void unknown_slot_060();
    virtual void unknown_slot_061();
    virtual void unknown_slot_062();
    virtual void unknown_slot_063();
    virtual void unknown_slot_064();
    virtual void unknown_slot_065();
    virtual void unknown_slot_066();
    virtual void unknown_slot_067();
    virtual void unknown_slot_068();
    virtual void unknown_slot_069();
    virtual void unknown_slot_070();
    virtual void unknown_slot_071();
    virtual void unknown_slot_072();
    virtual void unknown_slot_073();
    virtual void unknown_slot_074();
    virtual void unknown_slot_075();
    virtual void unknown_slot_076();
    virtual void unknown_slot_077();
    virtual void unknown_slot_078();
    virtual void unknown_slot_079();
    virtual void unknown_slot_080();
    virtual void unknown_slot_081();
    virtual void unknown_slot_082();
    virtual void unknown_slot_083();
    virtual void unknown_slot_084();
    virtual void unknown_slot_085();
    virtual void unknown_slot_086();
    virtual void unknown_slot_087();
    virtual void unknown_slot_088();
    virtual void unknown_slot_089();
    virtual void unknown_slot_090();
    virtual void unknown_slot_091();
    virtual void unknown_slot_092();
    virtual void unknown_slot_093();
    virtual void unknown_slot_094();
    virtual void unknown_slot_095();
    virtual void unknown_slot_096();
    virtual void unknown_slot_097();
    virtual void unknown_slot_098();
    virtual void unknown_slot_099();
    virtual void unknown_slot_100();
    virtual void unknown_slot_101();
    virtual void unknown_slot_102();
    virtual void unknown_slot_103();
    virtual void unknown_slot_104();
    virtual void unknown_slot_105();
    virtual void unknown_slot_106();
    virtual void unknown_slot_107();
    virtual void unknown_slot_108();
    virtual void unknown_slot_109();
    virtual void unknown_slot_110();
    virtual void unknown_slot_111();
    virtual void unknown_slot_112();
    virtual void unknown_slot_113();
    virtual void unknown_slot_114();
    virtual void unknown_slot_115();
    virtual void unknown_slot_116();
    virtual void unknown_slot_117();
    virtual void unknown_slot_118();
    virtual void unknown_slot_119();
    virtual void unknown_slot_120();
    virtual void unknown_slot_121();
    virtual void unknown_slot_122();
    virtual void unknown_slot_123();
    virtual void unknown_slot_124();
    virtual Vec990d60* GetTargetValue();
    virtual void unknown_slot_126();
    virtual void unknown_slot_127();
    virtual void unknown_slot_128();
    virtual void unknown_slot_129();
    virtual void unknown_slot_130();
    virtual void unknown_slot_131();
    virtual void unknown_slot_132();
    virtual void unknown_slot_133();
    virtual void unknown_slot_134();
    virtual void unknown_slot_135();
    virtual void unknown_slot_136();
    virtual void unknown_slot_137();
    virtual void unknown_slot_138();
    virtual void unknown_slot_139();
    virtual void unknown_slot_140();
    virtual void unknown_slot_141();
    virtual void unknown_slot_142();
    virtual void unknown_slot_143();
    virtual void unknown_slot_144();
    virtual void unknown_slot_145();
    virtual void unknown_slot_146();
    virtual void unknown_slot_147();
    virtual void unknown_slot_148();
    virtual void unknown_slot_149();
    virtual void unknown_slot_150();
    virtual void unknown_slot_151();
    virtual void unknown_slot_152();
    virtual void unknown_slot_153();
    virtual void unknown_slot_154();
    virtual void unknown_slot_155();
    virtual void unknown_slot_156();
    virtual void unknown_slot_157();
    virtual void unknown_slot_158();
    virtual void unknown_slot_159();
    virtual void unknown_slot_160();
    virtual void unknown_slot_161();
    virtual void unknown_slot_162();
    virtual void unknown_slot_163();
    virtual void unknown_slot_164();
    virtual void unknown_slot_165();
    virtual void unknown_slot_166();
    virtual void unknown_slot_167();
    virtual void unknown_slot_168();
    virtual void unknown_slot_169();
    virtual void unknown_slot_170();
    virtual void unknown_slot_171();
    virtual void unknown_slot_172();
    virtual void unknown_slot_173();
    virtual void unknown_slot_174();
    virtual void unknown_slot_175();
    virtual void unknown_slot_176();
    virtual void unknown_slot_177();
    virtual void unknown_slot_178();
    virtual void unknown_slot_179();
    virtual void unknown_slot_180();
    virtual void unknown_slot_181();
    virtual void unknown_slot_182();
    virtual void unknown_slot_183();
    virtual void unknown_slot_184();
    virtual void unknown_slot_185();
    virtual void unknown_slot_186();
    virtual void unknown_slot_187();
    virtual void unknown_slot_188();
    virtual void unknown_slot_189();
    virtual void unknown_slot_190();
    virtual void unknown_slot_191();
    virtual void unknown_slot_192();
    virtual void unknown_slot_193();
    virtual void unknown_slot_194();
    virtual void unknown_slot_195();
    virtual void unknown_slot_196();
    virtual void unknown_slot_197();
    virtual void unknown_slot_198();
    virtual void unknown_slot_199();
    virtual void unknown_slot_200();
    virtual void unknown_slot_201();
    virtual void unknown_slot_202();
    virtual void unknown_slot_203();
    virtual void unknown_slot_204();
    virtual void unknown_slot_205();
    virtual void unknown_slot_206();
    virtual void unknown_slot_207();
    virtual void unknown_slot_208();
    virtual void unknown_slot_209();
    virtual void unknown_slot_210();
    virtual void unknown_slot_211();
    virtual void unknown_slot_212();
    virtual void unknown_slot_213();
    virtual void unknown_slot_214();
    virtual void unknown_slot_215();
    virtual void unknown_slot_216();
    virtual void unknown_slot_217();
    virtual void unknown_slot_218();
    virtual void unknown_slot_219();
    virtual void unknown_slot_220();
    virtual void unknown_slot_221();
    virtual void unknown_slot_222();
    virtual void unknown_slot_223();
    virtual void unknown_slot_224();
    virtual void unknown_slot_225();
    virtual void unknown_slot_226();
    virtual void unknown_slot_227();
    virtual void unknown_slot_228();
    virtual void unknown_slot_229();
    virtual void unknown_slot_230();
    virtual void unknown_slot_231();
    virtual void unknown_slot_232();
    virtual void unknown_slot_233();
    virtual void unknown_slot_234();
    virtual void unknown_slot_235();
    virtual void unknown_slot_236();
    virtual void unknown_slot_237();
    virtual void unknown_slot_238();
    virtual void unknown_slot_239();
    virtual void unknown_slot_240();
    virtual void unknown_slot_241();
    virtual void unknown_slot_242();
    virtual void unknown_slot_243();
    virtual void unknown_slot_244();
    virtual void unknown_slot_245();
    virtual void unknown_slot_246();
    virtual void unknown_slot_247();
    virtual void unknown_slot_248();
    virtual void unknown_slot_249();
    virtual void unknown_slot_250();
    virtual void unknown_slot_251();
    virtual void unknown_slot_252();
    virtual void unknown_slot_253();
    virtual void unknown_slot_254();
    virtual void unknown_slot_255();
    virtual void unknown_slot_256();
    virtual void unknown_slot_257();
    virtual void unknown_slot_258();
    virtual void unknown_slot_259();
    virtual void unknown_slot_260();
    virtual void unknown_slot_261();
    virtual void unknown_slot_262();
    virtual void unknown_slot_263();
    virtual void unknown_slot_264();
    virtual void unknown_slot_265();
    virtual Handle990d60* GetTargetHandle();
};
struct Member990d60
{
    Actor990d60* actor;
};
struct Data990d60
{
    int FUN_00990890();
    int FUN_00990540();
    Member990d60* FUN_00990aa0(unsigned int);
};
extern const float DAT_01034294;
struct Strategy990d60
{
    bool IsGroupTargetsSpread(GroupOps* group, Data990d60* data);
};
// @fnv 0x00990d60
bool Strategy990d60::IsGroupTargetsSpread(GroupOps* pGroupOps, Data990d60* data)
{
    if (data->FUN_00990890() < 2)
        return false;
    if (!pGroupOps->FUN_0098a470(1, DAT_01034294))
        return false;
    if (data->FUN_00990540() <= 0)
        return false;
    unsigned int count = data->FUN_00990890();
    for (unsigned int index = 0; index < count; ++index)
    {
        Member990d60* member9 = data->FUN_00990aa0(index);
        Handle990d60* handle5 = member9->actor->GetTargetHandle();
        Target990d60* target8 = handle5->FUN_004030b0();
        if (target8)
        {
            Vec990d60 delta = member9->actor->GetTargetValue()->FUN_00439ef0(target8->GetTargetValue());
            if (delta.FUN_004a7290() < DAT_0101ece0)
                return false;
        }
    }
    return true;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern const Vec990d60 DAT_011f426c;
struct Centroid990640
{
    float x, y, z;
    void FUN_0063c8a0(const Vec990d60*);
    void ScaleByInverse(float);
};
struct MemberList990640
{
    Member990d60* FUN_00844160(unsigned int);
    IntPair& GetElement(unsigned int);
};
struct Strategy990640
{
    GroupMembers* group;
    unsigned int activeCount;
    int intersectionCount;
    int minimum;
    int maximum;
    float strength;
    MemberList990640 normalMembers;
    unsigned int FUN_00990890();
    void SortMembersByTargetDistance();
};
// Computes each member's target value, averages them into a centroid, then selection-sorts members by distance to that centroid.
// @fnv 0x00990640
void Strategy990640::SortMembersByTargetDistance()
{
    // i: member count; a: positions; p: centroid; h: distances.
    unsigned int i = FUN_00990890();
    Vec990d60* a = (Vec990d60*)_alloca(i * sizeof(Vec990d60));
    Vec990d60 p = DAT_011f426c;
    for (unsigned int memberIndex = 0; memberIndex < i; ++memberIndex)
    {
        Member990d60* member = normalMembers.FUN_00844160(memberIndex);
        a[memberIndex] = *member->actor->GetTargetValue();
        ((Centroid990640*)&p)->FUN_0063c8a0(&a[memberIndex]);
    }
    ((Centroid990640*)&p)->ScaleByInverse((float)i);
    float* h = (float*)_alloca(i * sizeof(float));
    for (unsigned int j = 0; j < i; ++j)
        h[j] = a[j].FUN_00439ef0(&p).FUN_004a7290();
    for (unsigned int k = 0; k < i - 1; ++k)
    {
        unsigned int nearest = k;
        float nearestDistance = h[k];
        for (unsigned int n = k + 1; n < i; ++n)
        {
            if (nearestDistance > h[n])
            {
                nearest = n;
                nearestDistance = h[n];
            }
        }
        if (k != nearest)
        {
            // Save the distance and member while exchanging the pair.
            float p = h[k];
            h[k] = h[nearest];
            h[nearest] = p;
            IntPair j = normalMembers.GetElement(k);
            normalMembers.GetElement(k) = normalMembers.GetElement(nearest);
            normalMembers.GetElement(nearest) = j;
        }
    }
}

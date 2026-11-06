
// src/fallout_shared/packagedatapatrol.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatapatrol.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct TESPatrolPackageData
{
    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Writes the two bytes at offsets 4 and 5 of this object into the save buffer via SaveData.
// @fnv 0x0067c5e0
void TESPatrolPackageData::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 4, 1, 0);
    apSaveGameBuffer->SaveData((char*)this + 5, 1, 0);
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void* pDest, unsigned int size);
};

struct FUN_0067c620
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// Reads two single bytes from the load buffer into the object at offsets 4 and 5.
// @fnv 0x0067c620
void __thiscall FUN_0067c620::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((char*)this + 4, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 5, 1);
}

struct FUN_0067da40
{
    void Init(void);
};

struct FUN_0067c650_shell
{
    float f;
    FUN_0067da40 sub;
    FUN_0067c650_shell();
};

void FUN_0067da40::Init()
{}

// Initializes f to 0.0f and calls Init on the sub member.
// @fnv 0x0067c650
FUN_0067c650_shell::FUN_0067c650_shell()
{
    f = 0.0f;
    sub.Init();
}

struct FUN_0067c670_shell
{
    void CallNestedMethod();
};

struct FUN_0067da80_shell
{
    void FUN_0067da80();
};

// @fnv 0x0067c670
void FUN_0067c670_shell::CallNestedMethod()
{
    ((FUN_0067da80_shell*)((char*)this + 4))->FUN_0067da80();
}

void __cdecl FUN_0067c490();

struct FUN_0067c420_shell
{
    void FUN_0067c490();
    void* FUN_0067c420(unsigned int flags);
};

// Calls FUN_0067c490, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0067c420
void* FUN_0067c420_shell::FUN_0067c420(unsigned int flags)
{
    FUN_0067c490();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Base6450
{
    void __thiscall FUN_0067ad20();
};
extern int DAT_010689e4;
struct Param6450
{
    unsigned char a;
    unsigned char b;
};
struct S6450 : Base6450
{
    S6450* __thiscall FUN_0067c450(Param6450 v);
};
// Calls FUN_0067ad20, stores a pointer to DAT_010689e4 at offset 0 and copies v.a and v.b into bytes at offsets 4 and 5, then returns this.
// @fnv 0x0067c450
S6450* __thiscall S6450::FUN_0067c450(Param6450 aParams)
{
    FUN_0067ad20();
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_010689e4);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 4) = aParams.a;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5) = aParams.b;
    return this;
}

struct FUN_0067c690_t
{
    float m_fPatrolValue;
    FUN_0067da40 sub;
    FUN_0067c690_t* ConstructFromFloat(void* p);
};
// @fnv 0x0067c690
FUN_0067c690_t* FUN_0067c690_t::ConstructFromFloat(void* apValue)
{
    m_fPatrolValue = *(float*)apValue;
    sub.Init();
    return this;
}

struct CopyHolder
{
    void FUN_0067dad0(void* p);
};
struct Target0067c6f0
{
    float f;
    CopyHolder c;
    void FUN_0067c6f0(Target0067c6f0* src);
};
// @fnv 0x0067c6f0
void Target0067c6f0::FUN_0067c6f0(Target0067c6f0* apSource)
{
    f = apSource->f;
    c.FUN_0067dad0(&apSource->c);
}

struct FUN_0067dbf0_shell
{
    bool FUN_0067dbf0(const void* p);
};
struct FUN_0067c720_shell
{
    float m_fPatrolValue;
    void CallNestedMethod();
    void FUN_0067da80();
    bool FUN_0067c720(const FUN_0067c720_shell* apCompare);
};
// @fnv 0x0067c720
bool FUN_0067c720_shell::FUN_0067c720(const FUN_0067c720_shell* apCompare)
{
    if (((FUN_0067dbf0_shell*)((const char*)this + 4))->FUN_0067dbf0((const char*)apCompare + 4))
        return true;
    if (m_fPatrolValue != apCompare->m_fPatrolValue)
        return true;
    return false;
}

struct MagicCaster
{
    void SetSelectedMagicItem(int type);
};

struct PackageEventActionData
{
    void InitItem(int item);
};

struct FUN_0067c6c0_shell
{
    char pad[4];
    MagicCaster caster;
    PackageEventActionData action;
    void FUN_0067c6c0(int item);
};

// @fnv 0x0067c6c0
void FUN_0067c6c0_shell::FUN_0067c6c0(int item)
{
    caster.SetSelectedMagicItem(3);
    reinterpret_cast<PackageEventActionData*>(reinterpret_cast<char*>(this) + 4)->InitItem(item);
}

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
struct Date
{
    unsigned char b;
    unsigned short pad;
    ~Date();
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int id, void* p, unsigned int size);

struct FUN_0067c570_shell
{
    void Save();
};

// @fnv 0x0067c570
void FUN_0067c570_shell::Save()
{
    unsigned char patrolData[2];
    memset(patrolData, 0, 2);
    patrolData[0] = *((unsigned char*)this + 4);
    if (FUN_00401500())
        ((Date*)patrolData)->Date::~Date();
    AppendChunk(0x54504b50, patrolData, 2);
    if (FUN_00401500())
        ((Date*)patrolData)->Date::~Date();
}

struct S_0067c490_Base
{
    virtual ~S_0067c490_Base();
};

struct FUN_0067c490 : S_0067c490_Base
{
    virtual ~FUN_0067c490();
};
// @fnv 0x0067c490
FUN_0067c490::~FUN_0067c490()
{}

struct S67da40
{
    int a;
    int b;
    int c;
    int d;
    S67da40* FUN_0067da40();
};
// Sets all four integer fields of the S67da40 object to zero and returns a pointer to the object.
// @fnv 0x0067da40
S67da40* S67da40::FUN_0067da40()
{
    a = 0;
    c = 0;
    d = 0;
    b = 0;
    return this;
}

struct TESPackageData
{
    virtual ~TESPackageData();
};

struct PatrolComparisonEntry67 : TESPatrolPackageData
{
    virtual ~PatrolComparisonEntry67();
    bool m_bPrimaryComparisonFlag;
    bool m_bSecondaryComparisonFlag;
    bool Compare(TESPackageData* apCompare);
};

// @fnv 0x0067c500
bool PatrolComparisonEntry67::Compare(TESPackageData* apCompare)
{
    PatrolComparisonEntry67* pcomp =
        reinterpret_cast<PatrolComparisonEntry67*>(dynamic_cast<TESPatrolPackageData*>(apCompare));
    if (!pcomp)
        return true;
    if (m_bPrimaryComparisonFlag != pcomp->m_bPrimaryComparisonFlag)
        return true;
    if (m_bSecondaryComparisonFlag != pcomp->m_bSecondaryComparisonFlag)
        return true;
    return false;
}

struct TESPackageData;
struct PatrolCopyAccess : TESPatrolPackageData
{
    virtual ~PatrolCopyAccess();
    bool m_bPrimaryComparisonFlag;
    bool m_bSecondaryComparisonFlag;
    void CopyFrom(TESPackageData* apCopy);
};
// Copies the two boolean fields from a TESPatrolPackageData source into this PatrolCopyAccess instance.
// @fnv 0x0067c4b0
void PatrolCopyAccess::CopyFrom(TESPackageData* apCopy)
{
    PatrolCopyAccess* pcopy;
    pcopy = reinterpret_cast<PatrolCopyAccess*>(dynamic_cast<TESPatrolPackageData*>(apCopy));
    if (!pcopy)
        return;
    m_bPrimaryComparisonFlag = pcopy->m_bPrimaryComparisonFlag;
    m_bSecondaryComparisonFlag = pcopy->m_bSecondaryComparisonFlag;
}

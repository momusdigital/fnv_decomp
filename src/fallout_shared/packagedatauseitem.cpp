// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_004856d0(int);
struct LocationDescriptor
{
    void Save(int);
};
struct TESPackageData
{
    void Save(int);
};
struct TESUseItemPackageData
{
    TESPackageData base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c9d0();
};

// @fnv 0x0067c9d0
void TESUseItemPackageData::FUN_0067c9d0()
{
    FUN_004856d0(0x44495550);
    if (this->m_pPackageTarget != 0)
        this->m_pPackageTarget->Save(0x32444c50);
}

struct FUN_0067c7a0_shell : TESUseItemPackageData
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};
// @fnv 0x0067c7a0
void* FUN_0067c7a0_shell::FUN_0067c7a0(unsigned int flags)
{
    FUN_0067c7d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0067ad70
{
    virtual ~FUN_0067ad70();
};
struct LocationShell
{
    ~LocationShell();
};
struct FUN_0067c7d0 : FUN_0067ad70
{
    LocationShell* m_pPackageTarget;
    virtual ~FUN_0067c7d0();
};
// @fnv 0x0067c7d0
FUN_0067c7d0::~FUN_0067c7d0()
{
    delete m_pPackageTarget;
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long vf, void* src, void* tgt, int isRef);
extern int DAT_0119bdec;
extern int DAT_0119bed8;
struct FUN_0067f600_shell
{
    bool FUN_0067f600(FUN_0067f600_shell* apCompare);
};
struct FUN_0067c960_shell : TESUseItemPackageData
{
    bool Compare(TESPackageData* apCompare);
};
// Returns true if the cast fails, the target comparison returns true, or only the other target is non-null.
// @fnv 0x0067c960
bool FUN_0067c960_shell::Compare(TESPackageData* apCompare)
{
    TESUseItemPackageData* pUseItemData =
        (TESUseItemPackageData*)FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119bed8, 0);
    if (!pUseItemData)
        return true;
    if (m_pPackageTarget)
    {
        if (((FUN_0067f600_shell*)m_pPackageTarget)->FUN_0067f600((FUN_0067f600_shell*)pUseItemData->m_pPackageTarget))
            return true;
    }
    else if (pUseItemData->m_pPackageTarget)
        return true;
    return false;
}


// src/fallout_shared/packagedataambush.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataambush.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl _Deallocate(void*);
struct FUN_0067ad90_shell
{
    void __thiscall FUN_0067adc0();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_0067adc0, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0067ad90
void* __thiscall FUN_0067ad90_shell::Destroy(unsigned int flags)
{
    FUN_0067adc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl FUN_004856d0(int);
struct LocationDescriptor
{
    void __thiscall Save(int);
};
struct FUN_0067afc0_shell
{
    void* base;
    LocationDescriptor* m_pSaveObject;
    void __thiscall SaveWithTag();
};
// @fnv 0x0067afc0
void __thiscall FUN_0067afc0_shell::SaveWithTag()
{
    FUN_004856d0(0x4d414b50);
    if (m_pSaveObject)
        m_pSaveObject->Save(0x32444c50);
}

class Sub_0067adc0
{
  public:
    unsigned int m_00;
    int Release(unsigned int flags);
};

class Base_0067adc0
{
  public:
    virtual ~Base_0067adc0();
};

class FUN_0067adc0_cls : public Base_0067adc0
{
  public:
    Sub_0067adc0* m_04;
    virtual ~FUN_0067adc0_cls();
};

// Destructor releases the Sub_0067adc0 object stored in m_04 by calling Release(1) if it is non-null.
// @fnv 0x0067adc0
FUN_0067adc0_cls::~FUN_0067adc0_cls()
{
    Sub_0067adc0* copy;
    Sub_0067adc0* tmp;
    copy = m_04;
    tmp = copy;
    tmp != 0 ? tmp->Release(1) : 0;
}

extern int DAT_0119bdec;
extern int DAT_0119bdc8;
void* __cdecl operator new(unsigned int size);
struct PackageRecord
{
    int unk00;
    void* location04;
};
PackageRecord* __cdecl FUN_00ec43fb(int id, int flags, const int* name, const int* type, int option);
struct AmbushLocation
{
    int unk00, unk04, unk08;
    AmbushLocation();
    void* FUN_00670b30(int release);
    void FUN_0067f4d0(void* source, int flags);
};
struct PackageOwner
{
    int unk00;
    AmbushLocation* location04;
    void SetLocationFromPackage(int id);
};
// Looks up a package record by id; if found, releases the current location and creates a new AmbushLocation from the record's location.
// @fnv 0x0067ae50
void PackageOwner::SetLocationFromPackage(int aiPackageId)
{
    PackageRecord* record = FUN_00ec43fb(aiPackageId, 0, &DAT_0119bdec, &DAT_0119bdc8, 0);
    if (record)
    {
        if (location04)
        {
            AmbushLocation* pAllocatedPath = location04;
            AmbushLocation* pOldLocation = pAllocatedPath;
            pOldLocation ? pOldLocation->FUN_00670b30(1) : 0;
            location04 = 0;
        }
        if (record->location04)
        {
            location04 = new AmbushLocation();
            location04->FUN_0067f4d0(record->location04, 0);
        }
    }
}

// TESAmbushPackageData: report whether another package's data differs from ours (location only).

class AF50Location
{
  public:
    bool IsDifferent(AF50Location* pkOther);
};

class TESPackageData
{
  public:
    virtual ~TESPackageData();
};

class TESAmbushPackageData : public TESPackageData
{
  public:
    virtual ~TESAmbushPackageData();
    bool Compare(TESPackageData* pkOtherData);

    AF50Location* m_pkLocation;
};

// Casts pkOtherData to TESAmbushPackageData and returns true if the cast fails or the two m_pkLocation values differ, otherwise false.
// @fnv 0x0067af50
bool TESAmbushPackageData::Compare(TESPackageData* pkOtherData)
{
    TESAmbushPackageData* pkOther = dynamic_cast<TESAmbushPackageData*>(pkOtherData);
    if (!pkOther)
        return true;

    if (m_pkLocation)
    {
        if (m_pkLocation->IsDifferent(pkOther->m_pkLocation))
            return true;
    }
    else if (pkOther->m_pkLocation)
    {
        return true;
    }
    return false;
}

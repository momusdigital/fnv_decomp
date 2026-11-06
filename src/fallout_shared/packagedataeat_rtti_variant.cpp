
// src/fallout_shared/packagedataeat_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESEatPackageData). The skeleton of src/fallout_shared/packagedataeat.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct TESEatPackageData
{
    virtual ~TESEatPackageData();  // the original class is polymorphic (rtti_variants.py)
    void* m_pPackageTarget;
    void __thiscall FUN_0067bbb0();
};
void __cdecl _FUN_004856d0(int);
struct LocationDescriptor
{
    void __thiscall Save(int);
};
struct FakeCls
{
    void __thiscall FUN_0067b9b0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct PackageLocation_
{
    PackageLocation_();
    char pad[12];
};
struct TESEatPackageData_
{
    unsigned char base[4];
    void* m_pPackageTarget;
    void FUN_0067fbe0(BGSLoadFormBuffer*);
    void __thiscall Load(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct PkgLoc_b9420
{
    void* FUN_00670b30(int aFlags);
};
struct Base_b9420
{
    virtual ~Base_b9420();
};
struct FUN_0067b9b0_cls : public Base_b9420
{
    PkgLoc_b9420* m_04;
    virtual ~FUN_0067b9b0_cls();
};
extern "C" int __cdecl FUN_00ec43fb(int a1, int a2, int* a3, int* a4, int a5);
extern int DAT_0119bdec;
extern int DAT_0119be3c;
struct FUN_0067f600_Obj
{
    unsigned char __thiscall IsDifferentFrom(int a1);
};
struct FUN_0067bb40_Result
{
    int unk00;
    int unk04;
};
struct TESEatPackageData_StandIn
{
    unsigned char base[4];
    FUN_0067f600_Obj* m_pPackageTarget;

    unsigned char __thiscall FUN_0067bb40(int arg);
};

extern "C" int __cdecl FUN_00ec43fb(int, int, int*, int*, int);
extern int DAT_0119bdec;
extern int DAT_0119be3c;

struct FUN_0067f030
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
    void __thiscall FUN_0067f4d0(void* location, int flags);
};

struct FUN_0067ba40_Result
{
    int unk00;
    void* location;
};

struct TESEatPackageData_Copy
{
    int unk00;
    FUN_0067f030* m_pPackageTarget;
    void __thiscall FUN_0067ba40(int flags);
};

// @fnv 0x0067ba40
void __thiscall TESEatPackageData_Copy::FUN_0067ba40(int flags)
{
    FUN_0067ba40_Result* result = (FUN_0067ba40_Result*)FUN_00ec43fb(flags, 0, &DAT_0119bdec, &DAT_0119be3c, 0);
    if (result)
    {
        if (m_pPackageTarget)
        {
            delete m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (result->location)
        {
            m_pPackageTarget = new FUN_0067f030;
            m_pPackageTarget->FUN_0067f4d0(result->location, 0);
        }
    }
}

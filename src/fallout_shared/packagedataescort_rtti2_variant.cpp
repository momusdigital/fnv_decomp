// src/fallout_shared/packagedataescort_rtti2_variant.cpp - RTTI variant unit rebuilt 2026-11-01 from TODAY's src/fallout_shared/packagedataescort.cpp (its skeleton, namespace blocks of integrated candidates out)
// with TESPackageData, TESEscortPackageData made polymorphic, so dynamic_cast<TESEscortPackageData*> compiles next to the file's own names.


// src/fallout_shared/packagedataescort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void _Deallocate(void*);
struct TESEscortPackageData
{
    virtual ~TESEscortPackageData();  // the original class is polymorphic (rtti_variants.py)
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
};
struct TESForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct LocationDescriptor;
struct TESPackageData;
struct FUN_0067ad20_shell
{
    void __thiscall FUN_0067ad20();
};
extern int DAT_01068960;
struct FUN_0067bc60_shell
{
    void* m_vtbl;
    int m_flags;
    TESForm* m_form;
    FUN_0067bc60_shell* __thiscall ConstructFromForm(TESForm** pForm);
};
struct LocationDescriptor
{
    void* m_vtbl;
    int m_flags;
    ~LocationDescriptor();
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    LocationDescriptor* m_pLoc;
};
struct FUN_0067bca0 : FUN_0067ad70_cls
{
    ~FUN_0067bca0();
};
struct FUN_0067f030 : LocationDescriptor
{
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
    void FUN_0067f4d0(LocationDescriptor* pSource, int flags);
};
struct TESPackageData
{
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
    void* unk00;
    FUN_0067f030* m_pLoc;
    TESForm* m_form;
};
struct FUN_0067bd30_shell : FUN_0067ad70_cls
{
    TESForm* m_form;
    void LoadPackageData(BGSLoadFormBuffer* pBuffer);
};
extern const int DAT_0119bdec;
extern const int DAT_0119be60;
extern TESPackageData* __cdecl FUN_00ec43fb(BGSLoadFormBuffer* pBuffer, int arg2, const void* arg3, const void* arg4,
                                            int arg5);

struct EscortLocationComparison
{
    bool __thiscall IsDifferentFrom(LocationDescriptor* compare);
};

struct EscortComparison
{
    void* m_vtbl;
    LocationDescriptor* m_pPackageTarget;
    int m_iValue;

    bool __thiscall Compare(TESPackageData* compare);
};

// @fnv 0x0067be40
bool EscortComparison::Compare(TESPackageData* compare)
{
    EscortComparison* other = reinterpret_cast<EscortComparison*>(dynamic_cast<TESEscortPackageData*>(compare));
    if (!other)
        return true;
    if (m_pPackageTarget)
    {
        if (reinterpret_cast<EscortLocationComparison*>(m_pPackageTarget)->IsDifferentFrom(other->m_pPackageTarget))
            return true;
    }
    else if (other->m_pPackageTarget)
    {
        return true;
    }
    if (m_iValue != other->m_iValue)
        return true;
    return false;
}

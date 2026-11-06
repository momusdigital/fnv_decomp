
// src/fallout_shared/packagedatauseitem_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0067c860: the skeleton of src/fallout_shared/packagedatauseitem_rtti_variant.cpp
// with declarations corrected to what the original code does (unit: struct LocationDescriptor { void Save(int); }; -> struct LocationDescriptor { void Save(int); unsigned int u0, u4; unit: struct TESUseItemPackageData { virtual ~TESUseItemPackag -> struct TESUseItemPackageData : TESPackageData { virtual ). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/packagedatauseitem_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESPackageData, TESUseItemPackageData). The skeleton of src/fallout_shared/packagedatauseitem.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_004856d0(int);
struct LocationDescriptor
{
    void Save(int);
    unsigned int u0, u4, u8;
    LocationDescriptor();
    ~LocationDescriptor();
    void FUN_0067f4d0(LocationDescriptor* other, bool a);
};
struct TESPackageData
{
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
    void Save(int);
};
struct TESUseItemPackageData : TESPackageData
{
    virtual ~TESUseItemPackageData();  // the original class is polymorphic (rtti_variants.py)
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c9d0();
    void CopyFrom(TESPackageData* source);
};
struct FUN_0067c7a0_shell : TESUseItemPackageData
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};
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

// @fnv 0x0067c860
void TESUseItemPackageData::CopyFrom(TESPackageData* source)
{
    TESUseItemPackageData* copy = dynamic_cast<TESUseItemPackageData*>(source);
    if (copy)
    {
        if (m_pPackageTarget)
        {
            delete m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (copy->m_pPackageTarget)
        {
            m_pPackageTarget = new LocationDescriptor;
            m_pPackageTarget->FUN_0067f4d0(copy->m_pPackageTarget, false);
        }
    }
}

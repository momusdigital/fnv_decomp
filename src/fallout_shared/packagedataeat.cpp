
// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TESEatPackageData
{
    unsigned char base[4];
    void* m_pPackageTarget;
    void __thiscall FUN_0067bbb0();
};

void __cdecl _FUN_004856d0(int);
struct LocationDescriptor
{
    void __thiscall Save(int);
};

// @fnv 0x0067bbb0
void __thiscall TESEatPackageData::FUN_0067bbb0()
{
    _FUN_004856d0(0x44454b50);
    if (this->m_pPackageTarget != 0)
    {
        ((LocationDescriptor*)this->m_pPackageTarget)->Save(0x32444c50);
    }
}

namespace fnv_0067bfa0 {
struct BGSLoadFormBuffer;
struct LocationDescriptor
{
    void ResolveObject(BGSLoadFormBuffer*);
};
struct TESEatPackageData
{
    void* m_Base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067bfa0(BGSLoadFormBuffer*);
};

// @fnv 0x0067bfa0
void TESEatPackageData::FUN_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_pPackageTarget != 0)
    {
        m_pPackageTarget->ResolveObject(apLoadGameBuffer);
    }
}
}  // namespace fnv_0067bfa0

struct FakeCls
{
    void __thiscall FUN_0067b9b0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x0067b980
void* __thiscall FakeCls::DestroyIfFlagged(unsigned int flags)
{
    FUN_0067b9b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

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
// @fnv 0x0067b050
void __thiscall TESEatPackageData_::Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasLocation = false;
    apLoadGameBuffer->ReadTypedData(&bhasLocation, 1);
    if (bhasLocation)
    {
        m_pPackageTarget = new PackageLocation_;
        ((TESEatPackageData_*)m_pPackageTarget)->FUN_0067fbe0(apLoadGameBuffer);
    }
}

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

// @fnv 0x0067b9b0
FUN_0067b9b0_cls::~FUN_0067b9b0_cls()
{
    PkgLoc_b9420* a = m_04;
    PkgLoc_b9420* p = a;
    (p != 0) ? p->FUN_00670b30(1) : 0;
}

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

// @fnv 0x0067bb40
unsigned char __thiscall TESEatPackageData_StandIn::FUN_0067bb40(int arg)
{
    FUN_0067bb40_Result* result = (FUN_0067bb40_Result*)FUN_00ec43fb(arg, 0, &DAT_0119bdec, &DAT_0119be3c, 0);

    if (result == 0)
    {
        return 1;
    }

    if (m_pPackageTarget != 0)
    {
        if (m_pPackageTarget->IsDifferentFrom(result->unk04) != 0)
        {
            return 1;
        }
    }
    else if (result->unk04 != 0)
    {
        return 1;
    }

    return 0;
}

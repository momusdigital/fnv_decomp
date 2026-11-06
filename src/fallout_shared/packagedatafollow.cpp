
// src/fallout_shared/packagedatafollow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatafollow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);

struct FUN_0067c080_shell
{
    void __thiscall FUN_0067c080();
};

void __cdecl FUN_0067c080_stub();

struct FUN_0067c010_shell
{
    void __thiscall FUN_0067c080();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x0067c010
void* __thiscall FUN_0067c010_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0067c080();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01068988;
struct FUN_0067c040_shell
{
    void* vtbl;
    int m1;
    float m2;
    void FUN_0067ad20();
    FUN_0067c040_shell* Construct(float a);
};
// Calls FUN_0067ad20, sets vtbl to &DAT_01068988, stores a in m2, zeroes m1, and returns this.
// @fnv 0x0067c040
FUN_0067c040_shell* FUN_0067c040_shell::Construct(float afValue)
{
    FUN_0067ad20();
    vtbl = &DAT_01068988;
    m2 = afValue;
    m1 = 0;
    return this;
}

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" bool __cdecl FUN_00401500();
extern "C" void __cdecl AppendChunk(int, void*, int);
struct BipedModelForm
{
    void Endian();
};
struct LocationDescriptor
{
    void Save(int);
};
struct FUN_0067c2b0_shell
{
    void* pBase;
    void* m_pSaveTarget;
    float m_fSavedValue;
    void SaveFloatRecord();
};
// @fnv 0x0067c2b0
void FUN_0067c2b0_shell::SaveFloatRecord()
{
    float fValue;
    memset(&fValue, 0, 4);
    fValue = m_fSavedValue;
    if (FUN_00401500())
        ((BipedModelForm*)&fValue)->Endian();
    AppendChunk(0x44464b50, &fValue, 4);
    if (FUN_00401500())
        ((BipedModelForm*)&fValue)->Endian();
    if (m_pSaveTarget)
        ((LocationDescriptor*)m_pSaveTarget)->Save(0x32444c50);
}

struct FUN_00670b30_Object
{
    ~FUN_00670b30_Object();
};
struct FUN_0067ad70_Base
{
    virtual void v0();
    ~FUN_0067ad70_Base();
};
struct FUN_0067c080 : FUN_0067ad70_Base
{
    FUN_00670b30_Object* ownedObject;
    ~FUN_0067c080();
};
// Destructor that deletes the ownedObject pointer.
// @fnv 0x0067c080
FUN_0067c080::~FUN_0067c080()
{
    delete ownedObject;
}

class TESPackageData
{
  public:
    virtual void unk00()
    {}
};
class FollowPackageField
{
  public:
    int unk00;
    bool Cmp(FollowPackageField* p);
};
class TESFollowPackageData : public TESPackageData
{
  public:
    FollowPackageField* m_04;
    float m_08;
    bool Compare(TESPackageData* arg);
};
// @fnv 0x0067c220
bool TESFollowPackageData::Compare(TESPackageData* apData)
{
    TESFollowPackageData* other = dynamic_cast<TESFollowPackageData*>(apData);
    if (other == 0)
    {
        return true;
    }
    if (m_08 != other->m_08)
    {
        return true;
    }
    if (m_04 != 0)
    {
        if (m_04->Cmp(other->m_04))
        {
            return true;
        }
    }
    else
    {
        if (other->m_04 != 0)
        {
            return true;
        }
    }
    return false;
}

struct FUN_0067c110_shell : TESPackageData
{
    FollowPackageField* m_04;
    float m_08;
    void __thiscall CopyFrom(TESPackageData* other);
};

struct FUN_0067f030
{
    void* vtbl;
    int unk04;
    int unk08;
    FUN_0067f030();
    void FUN_0067f4d0(FollowPackageField* other, bool flag);
};

// For a compatible source, copies m_08, deletes the old m_04, and allocates and initializes m_04 when the source has one.
// @fnv 0x0067c110
void __thiscall FUN_0067c110_shell::CopyFrom(TESPackageData* other)
{
    TESFollowPackageData* source = dynamic_cast<TESFollowPackageData*>(other);
    if (source)
    {
        m_08 = source->m_08;
        if (m_04)
        {
            delete reinterpret_cast<FUN_00670b30_Object*>(m_04);
            m_04 = 0;
        }
        if (source->m_04)
        {
            m_04 = reinterpret_cast<FollowPackageField*>(new FUN_0067f030);
            reinterpret_cast<FUN_0067f030*>(m_04)->FUN_0067f4d0(source->m_04, false);
        }
    }
}

// fallout_shared/region system/tesregiondatamap.cpp: TESRegionDataMap, RegionMapMerge (11 functions)

#include "layout_support.h"
#include "TESFile.h"
#include <malloc.h>

#pragma pack(push, 4)
class TESRegionData
{
  public:
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    unsigned char layoutPadding7[1];
};
#pragma pack(pop)

#pragma pack(push, 4)
class TESRegionDataMap : public TESRegionData
{
  public:
    BSStringT<char> m_kMapName;

    virtual ~TESRegionDataMap();
    virtual bool LoadRegionMapData(TESFile* apFile);
    virtual const char* GetRegionMapName();
};
#pragma pack(pop)

// Reads the RDMP chunk from apFile into a buffer and stores it in the map string, returning true on success.
// @fnv 0x004f3e90
bool TESRegionDataMap::LoadRegionMapData(TESFile* apFile)
{
    if (!apFile || apFile->GetChunkID() != CHUNK_ID_RDMP_ID)
        return false;

    char* pChunkData = (char*)_alloca(apFile->GetChunkSize());
    apFile->GetChunkData(pChunkData, 0);
    m_kMapName.Set(pChunkData, 0);
    return true;
}

// @fnv 0x005585e0
const char* TESRegionDataMap::GetRegionMapName()
{
    return m_kMapName.String();
}

extern unsigned int _data_011c16bc;
struct B004f1400
{
    virtual ~B004f1400();
    char p[4];
    B004f1400();
};
struct StrMem
{
    char p[8];
    StrMem();
    ~StrMem();
    bool Set(const char*, unsigned int);
};
struct FUN_004f3ca0 : public B004f1400
{
    StrMem m_kMapName;
    FUN_004f3ca0();
    virtual ~FUN_004f3ca0();
};
// Constructs the object and sets its string member to "Default Region Name".
// @fnv 0x004f3ca0
FUN_004f3ca0::FUN_004f3ca0()
{
    m_kMapName.Set("Default Region Name", 0);
}

struct Proxy_004f3de0
{
    void FUN_004f3de0();
};
void _Deallocate(void*);
struct Proxy_004f3d20
{
    void* FUN_004f3d20(unsigned int);
};
// Calls FUN_004f3de0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004f3d20
void* Proxy_004f3d20::FUN_004f3d20(unsigned int flags)
{
    ((Proxy_004f3de0*)this)->FUN_004f3de0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S7010
{
    unsigned int Length();
};
struct Flt
{
    operator unsigned int();
};
struct H14c0
{
    void WriteSaveData();
};
struct H4280
{
    unsigned int GetLengthPlusOne();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_004f3e40Shell
{
    char _pad[8];
    union U
    {
        S7010 s;
        Flt f;
        H4280 h;
    } u;
    void Save();
};
// @fnv 0x004f3e40
void FUN_004f3e40Shell::Save()
{
    ((H14c0*)this)->WriteSaveData();
    if (u.s.Length())
        FUN_004856f0(0x504D4452, (void*)(unsigned int)u.f, u.h.GetLengthPlusOne());
}

namespace fnv_004f3f10 {
struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct Flt
{
    operator unsigned int();
};
struct S004f3f10
{
    char _p[8];
    Flt _f;
    void GetMapName(BSStr&);
};
// Calls Set on the BSStr with the float value converted to unsigned int as the string pointer and length 0.
// @fnv 0x004f3f10
void S004f3f10::GetMapName(BSStr& a)
{
    a.Set((const char*)(unsigned int)_f, 0);
}
}  // namespace fnv_004f3f10

struct BSStr
{
    char _d[8];
    int StrCmp(char const*, bool) const;
    bool Set(char const*, unsigned int);
};
struct FUN_004f3f40_shell
{
    char _pad[8];
    BSStr str;
    bool SetMapName(char const*);
};
// @fnv 0x004f3f40
bool FUN_004f3f40_shell::SetMapName(char const* apMapName)
{
    if (str.StrCmp(apMapName, true))
    {
        str.Set(apMapName, 0);
        return true;
    }
    return false;
}

struct FUN_004f14a0_shell
{
    void* FUN_004f14a0();
};
struct FUN_004f3de0 : public FUN_004f3ca0
{
    ~FUN_004f3de0();
};
// Destructor that calls FUN_004f14a0 on the subobject at offset 8 of this object.
// @fnv 0x004f3de0
FUN_004f3de0::~FUN_004f3de0()
{
    ((FUN_004f14a0_shell*)((char*)this + 8))->FUN_004f14a0();
}

void* __cdecl operator new(unsigned int);

struct FUN_004f3d50 : public TESRegionData
{
    char padding[12];
    FUN_004f3d50(const TESRegionDataMap* source);
};

struct FUN_004f3f80_shell : public TESRegionDataMap
{
    TESRegionData* CreateRegionData() const;
};

// Allocates a new TESRegionData-derived object from this TESRegionDataMap and returns it.
// @fnv 0x004f3f80
TESRegionData* FUN_004f3f80_shell::CreateRegionData() const
{
    TESRegionData* pdata = new FUN_004f3d50(this);
    return pdata;
}

namespace fnv_004f3d50 {
class ThisBase_b5917
{
  public:
    virtual ~ThisBase_b5917();
    unsigned int m_04;
    ThisBase_b5917(class ThisSource_b5917* aValue);
};

class ThisMember_b5917
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b5917();
    ~ThisMember_b5917();
};

class ThisSource_b5917
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual const char* GetName();
};

class FUN_004f3d50 : public ThisBase_b5917
{
  public:
    virtual ~FUN_004f3d50();
    ThisMember_b5917 m_08;
    void Set(const char* name);

    FUN_004f3d50(ThisSource_b5917* src);
};

// Constructs the object from a source, initializing the base with it and calling Set with the source's name.
// @fnv 0x004f3d50
FUN_004f3d50::FUN_004f3d50(ThisSource_b5917* apSource) : ThisBase_b5917(apSource)
{
    Set(apSource->GetName());
}
}  // namespace fnv_004f3d50

struct RegionMapMerge : TESRegionDataMap
{
    virtual void SaveRegionData();
    virtual unsigned int GetRegionDataType();
    virtual void CopyRegionData();
    virtual void CompareRegionData();
    virtual void ClearRegionData();
    virtual void InitializeRegionData();
    virtual void ValidateRegionData();
    virtual void UpdateRegionData();
    virtual const char* ReadMapName();
    virtual void SetRegionMapName(const char* name);
    bool FUN_004f1540();
    void FUN_004f15a0(bool value);
    unsigned char FUN_005bb4d0();
    bool FUN_004f15c0(unsigned char value);
    void MergeMapData(RegionMapMerge* data, void* context);
};
float __cdecl floor(float value);

// @fnv 0x004f4000
void RegionMapMerge::MergeMapData(RegionMapMerge* apOther, void* context)
{
    RegionMapMerge* other = apOther;
    if (!apOther || apOther->GetRegionDataType() != 4 || !context)
        return;
    if (m_bHasRegionData)
    {
        FUN_004f15a0(other->FUN_004f1540());
        FUN_004f15c0(other->FUN_005bb4d0());
        SetRegionMapName(other->ReadMapName());
    }
    else if (other->m_bHasRegionData)
    {
        return;
    }
    else if (bOverride)
    {
        if (other->FUN_004f1540() && other->FUN_005bb4d0() > FUN_005bb4d0())
        {
            FUN_004f15a0(other->FUN_004f1540());
            FUN_004f15c0(other->FUN_005bb4d0());
            SetRegionMapName(other->ReadMapName());
        }
        return;
    }
    else if (other->FUN_004f1540())
    {
        FUN_004f15a0(other->FUN_004f1540());
        FUN_004f15c0(other->FUN_005bb4d0());
        SetRegionMapName(other->ReadMapName());
    }
    else
    {
        if (other->FUN_005bb4d0() > FUN_005bb4d0())
            SetRegionMapName(other->ReadMapName());
        float priority = FUN_005bb4d0() * FUN_005bb4d0() + (100 - FUN_005bb4d0()) * other->FUN_005bb4d0();
        priority += (100 - other->FUN_005bb4d0()) * FUN_005bb4d0() + other->FUN_005bb4d0() * other->FUN_005bb4d0();
        priority *= 0.005f;
        FUN_004f15c0((unsigned char)floor(priority));
    }
}

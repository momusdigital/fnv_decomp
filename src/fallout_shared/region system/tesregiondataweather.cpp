// fallout_shared/region system/tesregiondataweather.cpp: TESRegionDataWeather, RegionWeather (8 functions)

#include "tesregiondataweather_decls.h"
// @fnv 0x004f51f0
void TESRegionDataWeather::LoadWeatherData(TESFile* file, TESRegion* region)
{
    int warnings = Warning();
    SetWarningState(true);
    TESWeatherList::LoadWeatherEntries(&weatherList, file, region);
    SetWarningState(false);
    if (Warning() > warnings && region)
        Warning("Warnings were encountered while loading weather list chunk from region %s", region->GetName());
}

extern unsigned int _data_011c16bc;
struct B004f1400
{
    virtual ~B004f1400();
    char p[4];
    B004f1400();
};
struct W004f5040
{
    char p[0xc];
    W004f5040();
    ~W004f5040();
};
struct FUN_004f5040 : public B004f1400
{
    W004f5040 list;
    FUN_004f5040();
    virtual ~FUN_004f5040();
};
// Constructs a FUN_004f5040, initializing its base B004f1400 and its W004f5040 list member.
// @fnv 0x004f5040
FUN_004f5040::FUN_004f5040()
{}

void _Deallocate(void*);
struct S004f50b0
{
    void FUN_004f50e0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004f50e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004f50b0
void* S004f50b0::DestroyIfFlagged(unsigned int flags)
{
    FUN_004f50e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct A004f14c0
{
    void WriteSaveData();
};
struct A00582380
{
    void WriteWeatherList(unsigned int);
};
struct S004f51c0
{
    char pad[8];
    A00582380 lst;
    void Save();
};
// @fnv 0x004f51c0
void S004f51c0::Save()
{
    ((A004f14c0*)this)->WriteSaveData();
    lst.WriteWeatherList(0x54574452);
}

void* __cdecl operator new(unsigned int);
struct FUN_004f5140_shell
{
    char p[0x10];
    FUN_004f5140_shell(const void* a);
};
struct FUN_004f5260_shell
{
    void* __thiscall CreateCopy();
};
// @fnv 0x004f5260
void* FUN_004f5260_shell::CreateCopy()
{
    FUN_004f5140_shell* pdata = new FUN_004f5140_shell(this);
    return pdata;
}

struct C004f52e0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual C004f52e0* v5();
    virtual void v6();
    virtual void v7(const C004f52e0*, int);
    C004f52e0* FUN_004f52e0(const C004f52e0* apRegionData);
};
// @fnv 0x004f52e0
C004f52e0* C004f52e0::FUN_004f52e0(const C004f52e0* apRegionData)
{
    C004f52e0* pdata = v5();
    pdata->v7(apRegionData, 2);
    return pdata;
}

struct H008256d0
{
    bool FUN_008256d0();
};
struct S004f5570
{
    char _pad[8];
    H008256d0 _lst;
    bool FUN_004f5570();
};
// Returns true when the contained list object's check returns false.
// @fnv 0x004f5570
bool S004f5570::FUN_004f5570()
{
    return !_lst.FUN_008256d0();
}

struct RegionWeatherList
{
    void CopyWeatherList(RegionWeatherList*, int);
};
struct RegionWeather
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    unsigned char overrideFlag;
    unsigned char disabled;
    unsigned char priority;
    unsigned char unknown07;
    RegionWeatherList list;
    bool FUN_004f1540();
    unsigned char FUN_005bb4d0();
    void FUN_004f15a0(int);
    bool FUN_004f15c0(unsigned char);
    void MergeWeather(RegionWeather*, int);
};
double _floor(float);
// @fnv 0x004f5320
void RegionWeather::MergeWeather(RegionWeather* apOther, int enabled)
{
    RegionWeather* other = apOther;
    if (!apOther || apOther->v4() != 3 || !enabled)
        return;
    if (disabled)
    {
        FUN_004f15a0(other->FUN_004f1540());
        FUN_004f15c0(other->FUN_005bb4d0());
        list.CopyWeatherList(&other->list, 0);
    }
    else if (other->disabled)
    {
        return;
    }
    else if (overrideFlag)
    {
        if (other->FUN_004f1540() && other->FUN_005bb4d0() > FUN_005bb4d0())
        {
            FUN_004f15a0(other->FUN_004f1540());
            FUN_004f15c0(other->FUN_005bb4d0());
            list.CopyWeatherList(&other->list, 0);
        }
        return;
    }
    else if (other->FUN_004f1540())
    {
        FUN_004f15a0(other->FUN_004f1540());
        FUN_004f15c0(other->FUN_005bb4d0());
        list.CopyWeatherList(&other->list, 0);
    }
    else
    {
        list.CopyWeatherList(&other->list, 1);
        float weight = FUN_005bb4d0() * FUN_005bb4d0() + (100 - FUN_005bb4d0()) * other->FUN_005bb4d0();
        weight += (100 - other->FUN_005bb4d0()) * FUN_005bb4d0() + other->FUN_005bb4d0() * other->FUN_005bb4d0();
        weight *= 0.004999999888241291;
        FUN_004f15c0((unsigned char)_floor(weight));
    }
}


// src/fallout/ai/spectatorpackage_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/spectatorpackage.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "spectatorpackage_decls.h"

struct NiPoint3
{
    float x, y, z;
};

struct FUN_009f7050_class
{
    NiPoint3& FUN_009f7050(NiPoint3& akDest);
};

// @fnv 0x009f7050
NiPoint3& FUN_009f7050_class::FUN_009f7050(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x14);
    return akDest;
}

namespace fnv_009f7080 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_009f7080_class
{
    NiPoint3& FUN_009f7080(NiPoint3& akDest);
};

// @fnv 0x009f7080
NiPoint3& FUN_009f7080_class::FUN_009f7080(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x20);
    return akDest;
}
}  // namespace fnv_009f7080

unsigned int __cdecl gm_GetTickCount(void);
struct BGSSaveFormBuffer
{
    void __thiscall SerializeFormData(void*, int);
    void __thiscall SaveData(void*, int, int);
};
struct SpectatorThreatInfo
{
    void __thiscall FUN_009f70b0(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009f70b0
void __thiscall SpectatorThreatInfo::FUN_009f70b0(BGSSaveFormBuffer* buffer)
{
    unsigned int imodifiedPerceivedTime;
    buffer->SaveData(this + 8, 4, 0);
    imodifiedPerceivedTime = gm_GetTickCount() - ((unsigned int*)this)[3];
    buffer->SaveData(&imodifiedPerceivedTime, 4, 0);
    buffer->SaveData(this + 16, 4, 0);
    buffer->SaveData(this + 20, 12, 0);
    buffer->SaveData(this + 32, 12, 0);
    buffer->SaveData(this + 44, 1, 0);
    buffer->SaveData(this + 45, 1, 0);
    buffer->SerializeFormData(*(void**)this, 0);
    buffer->SerializeFormData(*(void**)(this + 4), 0);
}

namespace fnv_009f7170 {
unsigned int __cdecl gm_GetTickCount();
struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
};
struct SpectatorThreatInfo
{
    void FUN_009f7170(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009f7170
void SpectatorThreatInfo::FUN_009f7170(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(this + 8, 4);
    unsigned int imodifiedPerceivedTime = 0;
    buffer->ReadTypedData(&imodifiedPerceivedTime, 4);
    *(unsigned int*)((char*)this + 0xc) = gm_GetTickCount() - imodifiedPerceivedTime;
    buffer->ReadTypedData(this + 0x10, 4);
    buffer->ReadTypedData(this + 0x14, 0xc);
    buffer->ReadTypedData(this + 0x20, 0xc);
    buffer->ReadTypedData(this + 0x2c, 1);
    buffer->ReadTypedData(this + 0x2d, 1);
    buffer->ReadFormIdentifier(this);
    buffer->ReadFormIdentifier(this + 4);
}
}  // namespace fnv_009f7170

struct FUN_009f73e0
{
    void __thiscall FUN_009f7410();
    void* __thiscall DeleteThis(unsigned int flags);
};

// @fnv 0x009f73e0
void* FUN_009f73e0::DeleteThis(unsigned int flags)
{
    FUN_009f7410();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_009f8300 {
struct NiPoint3
{
    float x, y, z;
};

struct FUN_009f8300_class
{
    NiPoint3& FUN_009f8300(NiPoint3& akDest);
};

// @fnv 0x009f8300
NiPoint3& FUN_009f8300_class::FUN_009f8300(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x94);
    return akDest;
}
}  // namespace fnv_009f8300

struct Saver
{
    unsigned short FUN_00678fd0();
    unsigned short FUN_009f86f0();
};
// @fnv 0x009f86f0
unsigned short Saver::FUN_009f86f0()
{
    unsigned short size = 0;
    size += FUN_00678fd0();
    size += 8;
    return size;
}

struct Base009f8770
{
    void FUN_00679340();
};
struct Helper009f8770
{
    void FUN_00484d00(void*, int);
};
struct Holder009f8770
{
    void FUN_009f8770();
};
// @fnv 0x009f8770
void Holder009f8770::FUN_009f8770()
{
    ((Base009f8770*)this)->FUN_00679340();
    ((Helper009f8770*)this)->FUN_00484d00((char*)this + 0x84, 4);
    ((Helper009f8770*)this)->FUN_00484d00((char*)this + 0x88, 4);
}

struct FUN_009f8aa0_class
{
    int __thiscall FUN_009f8ac0(int);
    int __thiscall FUN_009f8aa0();
};
// @fnv 0x009f8aa0
int __thiscall FUN_009f8aa0_class::FUN_009f8aa0()
{
    return FUN_009f8ac0(0);
}

struct FUN_009f8ac0_class
{
    int __thiscall FUN_009f8ac0(int a);
};
// @fnv 0x009f8ac0
int __thiscall FUN_009f8ac0_class::FUN_009f8ac0(int a)
{
    return a * 0x34 + *(int*)((char*)this + 4);
}

extern int DAT_01093980;
struct FUN_009f8ae0Class
{
    void* vtbl;
    void FUN_009f90f0(int a, int b);
    void* FUN_009f8ae0(int a, int b);
};
// @fnv 0x009f8ae0
void* FUN_009f8ae0Class::FUN_009f8ae0(int a, int b)
{
    vtbl = &DAT_01093980;
    FUN_009f90f0(a, b);
    return this;
}

namespace fnv_009f8b10 {
extern int DAT_01093980;
struct SpectatorThreatInfo
{
    void* ReallocateStorage(int);
    void FUN_009f8b10();
};
// @fnv 0x009f8b10
void SpectatorThreatInfo::FUN_009f8b10()
{
    *reinterpret_cast<void**>(this) = &DAT_01093980;
    ReallocateStorage(1);
}
}  // namespace fnv_009f8b10

namespace fnv_009f8d00 {
struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
};
struct SpectatorThreatInfo
{
    int _0;
    int _4;
    int _8;
    int _c;
};
struct FUN_009f8d00_class
{
    int _0;
    SpectatorThreatInfo* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void FUN_009f8f60(SpectatorThreatInfo* data, unsigned int size);
    void FUN_009f8d00(bool freeStorage);
};
// @fnv 0x009f8d00
void FUN_009f8d00_class::FUN_009f8d00(bool freeStorage)
{
    if (pBuffer)
    {
        FUN_009f8f60(pBuffer, iSize);
        if (freeStorage)
        {
            ((NavMeshSearchLOSArray*)this)->FUN_006a8500();
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}
}  // namespace fnv_009f8d00

struct FUN_009f8d60_Class
{
    void* __thiscall FUN_009f8d60(int size);
};

// @fnv 0x009f8d60
void* __thiscall FUN_009f8d60_Class::FUN_009f8d60(int size)
{
    void* memory = operator new(size * 0x34);
    return memory;
}

extern "C" void* __cdecl Reallocate(void*, int);

struct FUN_009f8d90
{
    void* __thiscall Reallocate(void* p, int n);
};

// @fnv 0x009f8d90
void* __thiscall FUN_009f8d90::Reallocate(void* p, int n)
{
    return ::Reallocate(p, n * 0x34);
}

struct FUN_009f8b10_class
{
    void FUN_009f8b10();
    void* FUN_009f8db0(unsigned int flags);
};

// @fnv 0x009f8db0
void* FUN_009f8b10_class::FUN_009f8db0(unsigned int flags)
{
    FUN_009f8b10();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct S009f9180
{
    char data[0x34];
    void __thiscall FUN_009f9180(int);
};
struct S009f8f60
{
    void __thiscall FUN_009f8f60(S009f9180*, unsigned int);
};
// @fnv 0x009f8f60
void __thiscall S009f8f60::FUN_009f8f60(S009f9180* a1, unsigned int a2)
{
    for (int i = 0; i < a2; ++i)
        a1[i].FUN_009f9180(0);
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct Holder_009f7fe0
{
    char _pad0[0x90];
    unsigned char _flag90;
    char _pad1[0xA0 - 0x90 - 1];
    ArrSI _arrA0;
    bool FUN_009f7fe0();
};
// @fnv 0x009f7fe0
bool Holder_009f7fe0::FUN_009f7fe0()
{
    return _arrA0.GetFlags() == 0 || _flag90 != 0;
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
struct S00679120
{
    void SavePackage();
};
struct Wrap
{
    char _pad[0x84];
    unsigned int u84;
    unsigned int u88;
    void FUN_009f8730();
};
// @fnv 0x009f8730
void Wrap::FUN_009f8730()
{
    ((S00679120*)this)->SavePackage();
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&u84, 4);
    ((PC7d*)this)->FUN_00484ce0((unsigned int)&u88, 4);
}

struct TESForm
{
    virtual ~TESForm();
};
struct Actor : TESForm
{
    virtual ~Actor();
};
struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};
struct FUN_009f7230_class
{
    Actor* p;
    Actor* q;
    void FUN_009f7230(TESObjectREFRHelper* a);
};
TESForm* __cdecl GetFormByID(unsigned int);
// @fnv 0x009f7230
void FUN_009f7230_class::FUN_009f7230(TESObjectREFRHelper* a)
{
    p = p ? dynamic_cast<Actor*>(GetFormByID((unsigned int)p)) : 0;
    q = q ? dynamic_cast<Actor*>(GetFormByID((unsigned int)q)) : 0;
    if (p)
        ((TESObjectREFRHelper*)p)->SetTargetingState(true);
    if (q)
        ((TESObjectREFRHelper*)q)->SetTargetingState(true);
}

struct Flt
{
    operator unsigned int();
};
struct FUN_009f8a80_class
{
    Flt* FUN_009f8a80(unsigned int);
    void* _ref_00726070();
};
struct FUN_009f8c70_class
{
    void FUN_009f8c70(unsigned int, unsigned int);
};
struct FUN_009f84d0_class
{
    char _pad[0xA0];
    ArrSI arr;
    void FUN_009f84d0(unsigned int);
};

// @fnv 0x009f84d0
void FUN_009f84d0_class::FUN_009f84d0(unsigned int id)
{
    int count = arr.GetFlags();
    for (int i = 0; i < count; ++i)
    {
        Flt* item = reinterpret_cast<FUN_009f8a80_class*>(&arr)->FUN_009f8a80(i);
        if (item->operator unsigned int() == id ||
            reinterpret_cast<FUN_009f8a80_class*>(item)->_ref_00726070() == (void*)id)
        {
            reinterpret_cast<FUN_009f8c70_class*>(&arr)->FUN_009f8c70(i, 1);
            --count;
            --i;
        }
    }
}

struct BSSimpleArrayActor
{
    void Clear(bool);
    void GrowCapacity(unsigned int);
    unsigned int Add(void*&);
};
struct FUN_009f8660_class
{
    void FUN_009f8660(BSSimpleArrayActor& aArray);
};
// @fnv 0x009f8660
void FUN_009f8660_class::FUN_009f8660(BSSimpleArrayActor& aArray)
{
    aArray.Clear(true);
    unsigned int count = ((FUN_009f84d0_class*)this)->arr.GetFlags();
    aArray.GrowCapacity(count << 1);
    {
        int i = 0;
        int j = 0;
        for (; j < (int)count; j++)
        {
            Flt* form = ((FUN_009f8a80_class*)((char*)this + 0xa0))->FUN_009f8a80(j);
            void* id = (void*)(unsigned int)*form;
            if (id)
                aArray.Add(id);
        }
    }
}

struct FUN_00679a90_shell
{
    void DispatchToSubobjects(void*);
};
struct FUN_009f8a10 : FUN_00679a90_shell
{
    void InitLoadGame(void* apLoadGameBuffer);
};
// @fnv 0x009f8a10
void FUN_009f8a10::InitLoadGame(void* apLoadGameBuffer)
{
    unsigned int i;
    unsigned int isaveGameCount8;
    SpectatorThreatInfo* threatInfo;
    DispatchToSubobjects(apLoadGameBuffer);
    isaveGameCount8 = ((ArrSI*)((char*)this + 0xa0))->GetFlags();
    for (i = 0; i < isaveGameCount8; ++i)
    {
        threatInfo = (SpectatorThreatInfo*)((FUN_009f8a80_class*)((char*)this + 0xa0))->FUN_009f8a80(i);
        ((FUN_009f7230_class*)threatInfo)->FUN_009f7230((TESObjectREFRHelper*)apLoadGameBuffer);
    }
}

struct Helper62d0
{
    Helper62d0& operator=(const Helper62d0&);
};
struct SpectatorThreatInfo62d0
{
    Actor* pSource;
    Actor* pTarget;
    int m_iFirstInteger;
    unsigned int m_uiSecondValue;
    float fRadius;
    NiPoint3 aPos;
    NiPoint3 bPos;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    char _pad[2];
    Helper62d0 spEffect;
    SpectatorThreatInfo62d0& FUN_009f7630(const SpectatorThreatInfo62d0& that);
};
// @fnv 0x009f7630
SpectatorThreatInfo62d0& SpectatorThreatInfo62d0::FUN_009f7630(const SpectatorThreatInfo62d0& that)
{
    pSource = that.pSource;
    pTarget = that.pTarget;
    m_iFirstInteger = that.m_iFirstInteger;
    m_uiSecondValue = that.m_uiSecondValue;
    fRadius = that.fRadius;
    aPos = that.aPos;
    bPos = that.bPos;
    m_bFirstFlag = that.m_bFirstFlag;
    m_bFollowingFlag = that.m_bFollowingFlag;
    spEffect = that.spEffect;
    return *this;
}

struct FUN_006797c0_shell
{
    void __thiscall FUN_006797c0(void*);
};

struct GameTimerRecord
{
    unsigned int GetTime() const;
};

struct BGSSaveGameBuffer
{
    void __thiscall SaveVariableSizedValue(unsigned int);
};

GameTimerRecord g_timeGlobal;

struct SpectatorPackageSave : SpectatorPackage
{
    void __thiscall FUN_009f87d0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009f87d0
void SpectatorPackageSave::FUN_009f87d0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    int i;
    unsigned int threatInfo;
    unsigned int ipathTimeDelta;
    SpectatorThreatInfo* isaveGameCount;

    reinterpret_cast<FUN_006797c0_shell*>(this)->FUN_006797c0(apSaveGameBuffer);

    i = g_timeGlobal.GetTime() - *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x80);

    apSaveGameBuffer->SaveData(&i, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x84), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x94), 12, 0);

    threatInfo = reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 0xa0)
                     ? reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 0xa0)->GetFlags()
                     : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->SaveVariableSizedValue(threatInfo);

    for (ipathTimeDelta = 0; ipathTimeDelta < threatInfo; ++ipathTimeDelta)
    {
        isaveGameCount = reinterpret_cast<SpectatorThreatInfo*>(
            reinterpret_cast<FUN_009f8a80_class*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_009f8a80(ipathTimeDelta));
        isaveGameCount->FUN_009f70b0(apSaveGameBuffer);
    }
}

struct FUN_009f8a80_wrapper : FUN_009f8aa0_class
{
    int __thiscall FUN_009f8a80(unsigned int a);
};
// @fnv 0x009f8a80
int FUN_009f8a80_wrapper::FUN_009f8a80(unsigned int a)
{
    return FUN_009f8ac0((int)a);
}

struct SpectatorPackageStandIn
{
    void __thiscall FUN_009f8420(Actor& aActor);
};

struct SpectatorThreatInfoStandIn
{
    unsigned int __thiscall _ref_00726070();
};

// @fnv 0x009f8420
void SpectatorPackageStandIn::FUN_009f8420(Actor& aActor)
{
    SpectatorThreatInfo* scanInfo;
    int isize_ = reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 0xA0)->GetFlags();
    int i6 = 0;

    for (; i6 < isize_; ++i6)
    {
        scanInfo = reinterpret_cast<SpectatorThreatInfo*>(
            reinterpret_cast<FUN_009f8a80_class*>(reinterpret_cast<char*>(this) + 0xA0)->FUN_009f8a80(i6));

        if (reinterpret_cast<Flt*>(scanInfo)->operator unsigned int() == reinterpret_cast<unsigned int>(&aActor))
        {
            reinterpret_cast<FUN_009f8c70_class*>(reinterpret_cast<char*>(this) + 0xA0)->FUN_009f8c70(i6, 1);
            isize_--;
            i6--;
        }
        else if (reinterpret_cast<SpectatorThreatInfoStandIn*>(scanInfo)->_ref_00726070() ==
                 reinterpret_cast<unsigned int>(&aActor))
        {
            *reinterpret_cast<Actor**>(reinterpret_cast<char*>(scanInfo) + 4) = 0;
            *reinterpret_cast<bool*>(reinterpret_cast<char*>(scanInfo) + 0x2D) = false;
        }
    }
}

struct BGSLoadFormBuffer
{
    void __thiscall ReadTypedData(void* data, unsigned int size);
    int __thiscall ReadElementCount();
};

struct TESPackage
{
    void __thiscall LoadGame(BGSLoadFormBuffer* buffer);
};

struct FUN_009f7170_class
{
    void __thiscall FUN_009f7170(BGSLoadFormBuffer* buffer);
};

struct FUN_009f8b30_class
{
    void __thiscall FUN_009f8b30(unsigned int size, int flag);
};

struct FUN_009f8900_class
{
    unsigned char _pad00[0x80];
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8C;
    unsigned char field90;
    unsigned char _pad91[3];
    unsigned char field94[12];
    unsigned char _padA0[4];

    void __thiscall FUN_009f8900(BGSLoadFormBuffer* buffer);
};

// @fnv 0x009f8900
void FUN_009f8900_class::FUN_009f8900(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<TESPackage*>(this)->LoadGame(apLoadGameBuffer);

    int ipathTimeDelta = 0;
    apLoadGameBuffer->ReadTypedData(&ipathTimeDelta, 4);
    field80 = g_timeGlobal.GetTime() - ipathTimeDelta;

    apLoadGameBuffer->ReadTypedData(&field84, 4);
    apLoadGameBuffer->ReadTypedData(&field88, 4);
    apLoadGameBuffer->ReadTypedData(&field8C, 4);
    apLoadGameBuffer->ReadTypedData(&field90, 1);
    apLoadGameBuffer->ReadTypedData(field94, 12);

    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();

        reinterpret_cast<FUN_009f8b30_class*>(reinterpret_cast<unsigned char*>(this) + 0xA0)
            ->FUN_009f8b30(isaveGameCount, 1);

        {
            unsigned int i;
            for (i = 0; i < isaveGameCount; ++i)
            {
                SpectatorThreatInfo* threatInfo = reinterpret_cast<SpectatorThreatInfo*>(
                    reinterpret_cast<FUN_009f8a80_wrapper*>(reinterpret_cast<unsigned char*>(this) + 0xA0)
                        ->FUN_009f8a80(i));

                reinterpret_cast<FUN_009f7170_class*>(threatInfo)->FUN_009f7170(apLoadGameBuffer);
            }
        }
    }
}

unsigned int __cdecl gm_GetTickCount(void);
int __cdecl ClampThreat(int, int);
struct WeapStub
{
    int GetWeaponType();
};
struct Item428
{
    WeapStub* GetLoadedForm();
};
struct ActorStub
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual NiPoint3* GetPosPtr();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229();
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual Item428* GetItem428();
};
struct ThreatInfo
{
    ActorStub* pSource;
    ActorStub* pTarget;
    int m_iFirstInteger;
    unsigned int m_uiSecondValue;
    float fRadius;
    NiPoint3 aPos;
    NiPoint3 bPos;
    void FUN_009f6d50();
};
// @fnv 0x009f6d50
void ThreatInfo::FUN_009f6d50()
{
    m_uiSecondValue = pSource ? gm_GetTickCount() : m_uiSecondValue;
    NiPoint3* pA = pSource ? pSource->GetPosPtr() : &aPos;
    aPos = *pA;
    NiPoint3* pB = pTarget ? pTarget->GetPosPtr() : &bPos;
    bPos = *pB;
    Item428* pItem = pSource ? pSource->GetItem428() : 0;
    WeapStub* pWeap7 = pItem ? pItem->GetLoadedForm() : 0;
    int iLevel = 0;
    if (pWeap7)
    {
        switch (pWeap7->GetWeaponType())
        {
        case 0:
            iLevel = 3;
            fRadius = 512.0f;
            break;
        case 1:
            iLevel = 2;
            fRadius = 256.0f;
            break;
        case 2:
            iLevel = 1;
            fRadius = 128.0f;
            break;
        case 3:
            iLevel = 3;
            fRadius = 512.0f;
            break;
        case 4:
            iLevel = 3;
            fRadius = 256.0f;
            break;
        }
    }
    m_iFirstInteger = ClampThreat(m_iFirstInteger, iLevel);
}

class Base_9f72f0
{
  public:
    virtual ~Base_9f72f0();
    Base_9f72f0();
};

struct Vec3U
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

extern Vec3U DAT_011f426c;

class SubA0
{
  public:
    SubA0(int a, int b);
    ~SubA0();
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
};

class SubB0
{
  public:
    SubB0(int a);
    ~SubB0();
    unsigned int m_unk00;
    unsigned int m_unk04;
};

class FUN_009f72f0 : public Base_9f72f0
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned int m_unk44;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    unsigned int m_unk6c;
    unsigned int m_unk70;
    unsigned int m_unk74;
    unsigned int m_unk78;
    unsigned int m_unk7c;
    int m_i80;
    unsigned int m_unk84;
    float m_f88;
    float m_f8c;
    unsigned char m_b90;
    Vec3U m_v94;
    SubA0 m_a0;
    SubB0 m_b0;
    FUN_009f72f0();
    virtual ~FUN_009f72f0();
    void SetPackageType(int a);
    void FUN_00984f60(int a);
};

// @fnv 0x009f72f0
FUN_009f72f0::FUN_009f72f0() : m_v94(DAT_011f426c), m_a0(0x20, 0), m_b0(0)
{
    SetPackageType(0x18);
    m_i80 = 0;
    m_f88 = 0.0f;
    m_f8c = 0.0f;
    m_b90 = 0;
    FUN_00984f60(0xf);
}

struct ActorObject
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void RemoveReference(void* referencedObject);
};
struct ObjectRef
{
    ActorObject* FUN_009611e0();
};
struct FUN_006708b0
{
    virtual ~FUN_006708b0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
};
struct FUN_009f8b10
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~FUN_009f8b10();
};
struct FUN_0045cec0
{
    ObjectRef* FUN_00559450();
    void FUN_0066b0d0(int release);
    ~FUN_0045cec0();
};
struct FUN_009f7410 : FUN_006708b0
{
    FUN_009f8b10 memberA0;
    FUN_0045cec0 memberB0;
    virtual ~FUN_009f7410();
};
// @fnv 0x009f7410
FUN_009f7410::~FUN_009f7410()
{
    if (memberB0.FUN_00559450())
    {
        if (memberB0.FUN_00559450()->FUN_009611e0())
        {
            memberB0.FUN_00559450()->FUN_009611e0()->RemoveReference(memberB0.FUN_00559450());
        }
        memberB0.FUN_0066b0d0(0);
    }
}

struct Parameter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual int GetMark();
};
struct Entry
{
    Parameter* FUN_00559450();
    int FUN_00726070();
    void SetSourceReference(Parameter*);
};
struct ThreatList
{
    int FUN_0044ddc0();
    Entry* FUN_009f8a80(int);
    void FUN_009f8b30(int, int);
};
struct Package
{
    void FUN_009f8330(Parameter*);
    void FUN_009f76e0();
};
// @fnv 0x009f8330
void Package::FUN_009f8330(Parameter* actor)
{
    int id = actor->GetMark();
    int count = ((ThreatList*)((char*)this + 0xA0))->FUN_0044ddc0();
    Entry* match = 0;
    for (int i = 0; i < count; ++i)
    {
        Entry* e = ((ThreatList*)((char*)this + 0xA0))->FUN_009f8a80(i);
        if (e->FUN_00559450() == actor && e->FUN_00726070() == id)
        {
            match = e;
            break;
        }
    }
    if (!match)
    {
        int n = ((ThreatList*)((char*)this + 0xA0))->FUN_0044ddc0();
        ((ThreatList*)((char*)this + 0xA0))->FUN_009f8b30(n + 1, 1);
        match = ((ThreatList*)((char*)this + 0xA0))->FUN_009f8a80(n);
    }
    match->SetSourceReference(actor);
    FUN_009f76e0();
}

struct ThreatArray
{
    virtual void ReleaseStorage();
    virtual S009f9180* Allocate(unsigned int count);
    S009f9180* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_009f8d00(bool);
    void EnsureBuffer(unsigned int, unsigned int);
    void FUN_009f8de0(S009f9180*, unsigned int);
    void FUN_009f8f60(S009f9180*, unsigned int);
    void FUN_009f8b30(unsigned int count, bool shrink);
};
// @fnv 0x009f8b30
void ThreatArray::FUN_009f8b30(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        FUN_009f8d00(shrink);
    }
    else if (count > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(count);
            capacity = count;
        }
        else
        {
            EnsureBuffer(count, size);
            capacity = count;
        }
        FUN_009f8de0(data + size, count - size);
        size = count;
    }
    else if (count < size)
    {
        FUN_009f8f60(data + count, size - count);
        size = count;
        if (shrink && count <= capacity / 4)
        {
            EnsureBuffer(count, count);
            capacity = count;
        }
    }
    else
    {
        FUN_009f8de0(data + size, count - size);
        size = count;
    }
}

int __cdecl SpanIndex(int a, int b);

struct FUN_009f8c70_cls
{
    int unk00;
    char* m_pData;
    int m_uiItemCount;

    void FUN_009f8f60(void* apElem, unsigned int auiArg);
    void CopyElements(void* apDst, void* apSrc, int aiIdx);
    void FUN_009f8c70(unsigned int a1, unsigned int a2);
};

// @fnv 0x009f8c70
void FUN_009f8c70_cls::FUN_009f8c70(unsigned int a1, unsigned int a2)
{
    int idx = SpanIndex(m_uiItemCount - a1 - a2, a2);
    FUN_009f8f60(m_pData + a1 * 0x34, a2);
    CopyElements(m_pData + a1 * 0x34, m_pData + m_uiItemCount * 0x34 - idx * 0x34, idx);
    m_uiItemCount = m_uiItemCount - a2;
}

namespace fnv_009f8e80 {
struct FUN_009f8e80_vec3
{
    float x;
    float y;
    float z;
};

extern FUN_009f8e80_vec3 DAT_011f426c;

struct FUN_009f8e80_sub
{
    FUN_009f8e80_sub(int a);
    ~FUN_009f8e80_sub();
    void FUN_00633c90(int a);
    void FUN_0066b0d0(int a);
};

class FUN_009f8e80_cls
{
  public:
    FUN_009f8e80_cls();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    float m_10;
    FUN_009f8e80_vec3 m_14;
    FUN_009f8e80_vec3 m_20;
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned short m_2e;
    FUN_009f8e80_sub m_30;
};

// @fnv 0x009f8e80
FUN_009f8e80_cls::FUN_009f8e80_cls()
    : m_00(0), m_04(0), m_08(0), m_0c(0), m_10(0.0f), m_14(DAT_011f426c), m_20(DAT_011f426c), m_2c(0), m_2d(0), m_30(0)
{
    m_30.FUN_0066b0d0(0);
}
}  // namespace fnv_009f8e80

struct SpectatorVolume
{
    float f00, f04, f08, f0C, f10, f14, f18, f1C, f20;
    SpectatorVolume(const NiPoint3& akFrom, const NiPoint3& akTo, float afRadius, float afHeight);
    SpectatorVolume(const NiPoint3& akCenter, float afRadius, float afHeight);
};

struct SpectatorInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float fRadius;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    bool bHasStart;
    bool bHasEnd;

    NiPoint3 GetStart();
    NiPoint3 GetEnd();
    void FUN_009f6f30(SpectatorVolume& arVolume);
};

// @fnv 0x009f6f30
void SpectatorInfo::FUN_009f6f30(SpectatorVolume& arVolume)
{
    if (bHasStart)
    {
        if (bHasEnd)
        {
            arVolume = SpectatorVolume(GetStart(), GetEnd(), fRadius, 100.0f);
        }
        else
        {
            arVolume = SpectatorVolume(GetStart(), fRadius, 100.0f);
        }
    }
    else if (bHasEnd)
    {
        arVolume = SpectatorVolume(GetEnd(), fRadius, 100.0f);
    }
}

struct FUN_009f7500_class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int field80;
    float field84;
    float field88;
    float field8c;
    unsigned char field90;
    unsigned char pad91;
    unsigned char pad92;
    unsigned char pad93;
    struct ThreeWords
    {
        unsigned int first;
        unsigned int second;
        unsigned int third;
    } field94;
    ArrSI arrA0;
    void CopyFromPackage(void*);
    void FUN_009f7500(void*);
};
extern int DAT_01183028;
extern int DAT_011a5fd8;
extern void* __cdecl FUN_00ec43fb(void*, int, int*, int*, int);
// @fnv 0x009f7500
void FUN_009f7500_class::FUN_009f7500(void* param_2)
{
    CopyFromPackage(param_2);
    FUN_009f7500_class* other = (FUN_009f7500_class*)FUN_00ec43fb(param_2, 0, &DAT_01183028, &DAT_011a5fd8, 0);
    if (other != 0)
    {
        field80 = other->field80;
        field84 = other->field84;
        field88 = other->field88;
        field8c = other->field8c;
        field94 = other->field94;
        field90 = other->field90;
        int count = other->arrA0.GetFlags();
        ((FUN_009f8b30_class*)&arrA0)->FUN_009f8b30(count, 1);
        int i;
        for (i = 0; i < count; i++)
        {
            ((SpectatorThreatInfo62d0*)((FUN_009f8a80_class*)&arrA0)->FUN_009f8a80(i))
                ->FUN_009f7630(*(SpectatorThreatInfo62d0*)((FUN_009f8a80_class*)&other->arrA0)->FUN_009f8a80(i));
        }
    }
}

namespace ThreatBounds {
struct Vec
{
    float x, y, z;
    void FUN_0063c8a0(const Vec&);
    void FUN_00439180(float);
    Vec FUN_00439ef0(const Vec&);
    float FUN_004a7290();
};
struct Threat
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    bool hasSource, hasTarget;
    Vec FUN_009f7050();
    Vec FUN_009f7080();
};
struct ThreatList
{
    unsigned int unk00;
    int FUN_0044ddc0();
    Threat* FUN_009f8a80(int);
};
extern const Vec DAT_011f426c;
extern const float DAT_01016248;
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
float FUN_004019d0(float);
struct Package
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    float radius;
    bool empty;
    Vec center;
    ThreatList threats;
    void FUN_009f76e0();
};
// @fnv 0x009f76e0
void Package::FUN_009f76e0()
{
    if (!threats.FUN_0044ddc0())
        return;
    int sizeSlot13 = threats.FUN_0044ddc0();
    int pointCountSlot1 = 0;
    Vec minimumSlot0 = DAT_011f426c;
    Vec maximumSlot27 = DAT_011f426c;
    bool unusedSlot12 = false;
    int index;
    for (index = 0; index < sizeSlot13; index++)
    {
        Threat* threat = threats.FUN_009f8a80(index);
        if (threat->hasSource && threat->hasTarget)
        {
            minimumSlot0.x = FUN_00404010(threat->FUN_009f7050().x, threat->FUN_009f7080().x);
            minimumSlot0.y = FUN_00404010(threat->FUN_009f7050().y, threat->FUN_009f7080().y);
            minimumSlot0.z = FUN_00404010(threat->FUN_009f7050().z, threat->FUN_009f7080().z);
            maximumSlot27.x = FUN_0040ebd0(threat->FUN_009f7050().x, threat->FUN_009f7080().x);
            maximumSlot27.y = FUN_0040ebd0(threat->FUN_009f7050().y, threat->FUN_009f7080().y);
            maximumSlot27.z = FUN_0040ebd0(threat->FUN_009f7050().z, threat->FUN_009f7080().z);
            pointCountSlot1 += 2;
            break;
        }
        else if (threat->hasSource)
        {
            minimumSlot0 = threat->FUN_009f7050();
            maximumSlot27 = threat->FUN_009f7050();
            pointCountSlot1++;
            break;
        }
        else if (threat->hasTarget)
        {
            minimumSlot0 = threat->FUN_009f7080();
            maximumSlot27 = threat->FUN_009f7080();
            pointCountSlot1++;
            break;
        }
    }
    for (index++; index < sizeSlot13; index++)
    {
        Threat* nextThreat = threats.FUN_009f8a80(index);
        if (nextThreat->hasSource)
        {
            minimumSlot0.x = FUN_00404010(minimumSlot0.x, nextThreat->FUN_009f7050().x);
            minimumSlot0.y = FUN_00404010(minimumSlot0.y, nextThreat->FUN_009f7050().y);
            minimumSlot0.z = FUN_00404010(minimumSlot0.z, nextThreat->FUN_009f7050().z);
            maximumSlot27.x = FUN_0040ebd0(maximumSlot27.x, nextThreat->FUN_009f7050().x);
            maximumSlot27.y = FUN_0040ebd0(maximumSlot27.y, nextThreat->FUN_009f7050().y);
            maximumSlot27.z = FUN_0040ebd0(maximumSlot27.z, nextThreat->FUN_009f7050().z);
            pointCountSlot1++;
        }
        if (nextThreat->hasTarget)
        {
            minimumSlot0.x = FUN_00404010(minimumSlot0.x, nextThreat->FUN_009f7080().x);
            minimumSlot0.y = FUN_00404010(minimumSlot0.y, nextThreat->FUN_009f7080().y);
            minimumSlot0.z = FUN_00404010(minimumSlot0.z, nextThreat->FUN_009f7080().z);
            maximumSlot27.x = FUN_0040ebd0(maximumSlot27.x, nextThreat->FUN_009f7080().x);
            maximumSlot27.y = FUN_0040ebd0(maximumSlot27.y, nextThreat->FUN_009f7080().y);
            maximumSlot27.z = FUN_0040ebd0(maximumSlot27.z, nextThreat->FUN_009f7080().z);
            pointCountSlot1++;
        }
    }
    if (pointCountSlot1 == 0)
    {
        empty = true;
        return;
    }
    Vec midpointSlot20 = minimumSlot0;
    midpointSlot20.FUN_0063c8a0(maximumSlot27);
    midpointSlot20.FUN_00439180(DAT_01016248);
    float distance = 0.0f;
    float radiusSquaredSlot57 = 0.0f;
    for (index = 0; index < sizeSlot13; index++)
    {
        Threat* radiusThreat = threats.FUN_009f8a80(index);
        if (!radiusThreat->hasSource && !radiusThreat->hasTarget)
            continue;
        if (radiusThreat->hasSource)
        {
            distance = midpointSlot20.FUN_00439ef0(radiusThreat->FUN_009f7050()).FUN_004a7290();
            if (distance >= radiusSquaredSlot57)
                radiusSquaredSlot57 = distance;
        }
        if (radiusThreat->hasTarget)
        {
            distance = midpointSlot20.FUN_00439ef0(radiusThreat->FUN_009f7080()).FUN_004a7290();
            if (distance >= radiusSquaredSlot57)
                radiusSquaredSlot57 = distance;
        }
    }
    center = midpointSlot20;
    radius = FUN_004019d0(radiusSquaredSlot57);
}
}

struct UnknownObject32
{
    unsigned int a, b, c, d, e, f, g, h;
};
struct UnknownObject64
{
    UnknownObject32 lo, hi;
};

struct TargetView;
struct TargetView
{
    virtual void tp0();
    virtual void tp1();
    virtual void tp2();
    virtual void tp3();
    virtual void tp4();
    virtual void tp5();
    virtual void tp6();
    virtual void tp7();
    virtual void tp8();
    virtual void tp9();
    virtual void tp10();
    virtual void tp11();
    virtual void tp12();
    virtual void tp13();
    virtual void tp14();
    virtual void tp15();
    virtual void tp16();
    virtual void tp17();
    virtual void tp18();
    virtual void tp19();
    virtual void tp20();
    virtual void tp21();
    virtual void tp22();
    virtual void tp23();
    virtual void tp24();
    virtual void tp25();
    virtual void tp26();
    virtual void tp27();
    virtual void tp28();
    virtual void tp29();
    virtual void tp30();
    virtual void tp31();
    virtual void tp32();
    virtual void tp33();
    virtual void tp34();
    virtual void tp35();
    virtual void tp36();
    virtual void tp37();
    virtual void tp38();
    virtual void tp39();
    virtual void tp40();
    virtual void tp41();
    virtual void tp42();
    virtual void tp43();
    virtual void tp44();
    virtual void tp45();
    virtual void tp46();
    virtual void tp47();
    virtual void tp48();
    virtual void tp49();
    virtual void tp50();
    virtual void tp51();
    virtual void tp52();
    virtual void tp53();
    virtual void tp54();
    virtual void tp55();
    virtual void tp56();
    virtual void tp57();
    virtual void tp58();
    virtual void tp59();
    virtual void tp60();
    virtual void tp61();
    virtual void tp62();
    virtual void tp63();
    virtual unsigned char IsActor();
};

struct BaseProcess
{
    virtual void bp0();
    virtual void bp1();
    virtual void bp2();
    virtual void bp3();
    virtual void bp4();
    virtual void bp5();
    virtual void bp6();
    virtual void bp7();
    virtual void bp8();
    virtual void bp9();
    virtual void bp10();
    virtual void bp11();
    virtual void bp12();
    virtual void bp13();
    virtual void bp14();
    virtual void bp15();
    virtual void bp16();
    virtual void bp17();
    virtual void bp18();
    virtual void bp19();
    virtual void bp20();
    virtual void bp21();
    virtual void bp22();
    virtual void bp23();
    virtual void bp24();
    virtual void bp25();
    virtual void bp26();
    virtual void bp27();
    virtual void bp28();
    virtual void bp29();
    virtual void bp30();
    virtual void bp31();
    virtual void bp32();
    virtual void bp33();
    virtual void bp34();
    virtual void bp35();
    virtual void bp36();
    virtual void bp37();
    virtual void bp38();
    virtual void bp39();
    virtual void bp40();
    virtual void bp41();
    virtual void bp42();
    virtual void bp43();
    virtual void bp44();
    virtual void bp45();
    virtual void bp46();
    virtual void bp47();
    virtual void bp48();
    virtual void bp49();
    virtual void bp50();
    virtual void bp51();
    virtual void bp52();
    virtual void bp53();
    virtual void bp54();
    virtual void bp55();
    virtual void bp56();
    virtual void bp57();
    virtual void bp58();
    virtual void bp59();
    virtual void bp60();
    virtual void bp61();
    virtual void bp62();
    virtual void bp63();
    virtual void bp64();
    virtual void bp65();
    virtual void bp66();
    virtual void bp67();
    virtual void bp68();
    virtual void bp69();
    virtual void bp70();
    virtual void bp71();
    virtual void bp72();
    virtual void bp73();
    virtual void bp74();
    virtual void bp75();
    virtual void bp76();
    virtual void bp77();
    virtual void bp78();
    virtual void bp79();
    virtual void bp80();
    virtual void bp81();
    virtual void bp82();
    virtual void bp83();
    virtual void bp84();
    virtual void bp85();
    virtual void bp86();
    virtual void bp87();
    virtual void bp88();
    virtual void bp89();
    virtual void bp90();
    virtual void bp91();
    virtual void bp92();
    virtual void bp93();
    virtual void bp94();
    virtual void bp95();
    virtual void bp96();
    virtual void bp97();
    virtual void bp98();
    virtual void bp99();
    virtual void bp100();
    virtual void bp101();
    virtual void bp102();
    virtual void bp103();
    virtual void bp104();
    virtual void bp105();
    virtual void bp106();
    virtual void bp107();
    virtual void bp108();
    virtual void bp109();
    virtual void bp110();
    virtual void bp111();
    virtual void bp112();
    virtual void bp113();
    virtual void bp114();
    virtual void bp115();
    virtual void bp116();
    virtual void bp117();
    virtual void bp118();
    virtual void bp119();
    virtual void bp120();
    virtual void bp121();
    virtual void bp122();
    virtual void bp123();
    virtual void bp124();
    virtual void bp125();
    virtual void bp126();
    virtual void bp127();
    virtual void bp128();
    virtual void bp129();
    virtual void bp130();
    virtual void bp131();
    virtual void bp132();
    virtual void bp133();
    virtual void bp134();
    virtual void bp135();
    virtual void bp136();
    virtual void bp137();
    virtual void bp138();
    virtual void bp139();
    virtual void bp140();
    virtual void bp141();
    virtual void bp142();
    virtual void bp143();
    virtual void bp144();
    virtual void bp145();
    virtual void bp146();
    virtual void bp147();
    virtual void bp148();
    virtual void bp149();
    virtual void bp150();
    virtual void bp151();
    virtual void bp152();
    virtual void bp153();
    virtual void bp154();
    virtual void bp155();
    virtual void bp156();
    virtual void bp157();
    virtual void bp158();
    virtual void bp159();
    virtual void bp160();
    virtual void bp161();
    virtual void bp162();
    virtual void bp163();
    virtual void bp164();
    virtual void bp165();
    virtual void bp166();
    virtual void bp167();
    virtual void bp168();
    virtual void bp169();
    virtual void bp170();
    virtual void bp171();
    virtual void bp172();
    virtual void bp173();
    virtual void bp174();
    virtual void bp175();
    virtual void bp176();
    virtual void bp177();
    virtual void bp178();
    virtual void bp179();
    virtual void bp180();
    virtual void bp181();
    virtual void bp182();
    virtual void bp183();
    virtual void bp184();
    virtual void bp185();
    virtual void bp186();
    virtual void bp187();
    virtual void bp188();
    virtual void bp189();
    virtual void bp190();
    virtual void bp191();
    virtual void bp192();
    virtual void bp193();
    virtual void bp194();
    virtual void bp195();
    virtual void bp196();
    virtual void bp197();
    virtual void bp198();
    virtual void bp199();
    virtual void bp200();
    virtual void bp201();
    virtual void bp202();
    virtual void bp203();
    virtual void bp204();
    virtual void bp205();
    virtual void bp206();
    virtual void bp207();
    virtual void bp208();
    virtual void bp209();
    virtual void bp210();
    virtual void bp211();
    virtual void bp212();
    virtual void bp213();
    virtual void bp214();
    virtual void bp215();
    virtual void bp216();
    virtual void bp217();
    virtual void bp218();
    virtual void bp219();
    virtual void bp220();
    virtual void bp221();
    virtual void bp222();
    virtual void bp223();
    virtual void bp224();
    virtual void bp225();
    virtual void bp226();
    virtual void bp227();
    virtual void bp228();
    virtual void bp229();
    virtual void bp230();
    virtual void bp231();
    virtual void bp232();
    virtual void bp233();
    virtual void bp234();
    virtual void bp235();
    virtual void bp236();
    virtual void bp237();
    virtual void bp238();
    virtual void bp239();
    virtual void bp240();
    virtual void bp241();
    virtual void bp242();
    virtual void bp243();
    virtual void bp244();
    virtual void bp245();
    virtual void bp246();
    virtual void bp247();
    virtual void bp248();
    virtual void bp249();
    virtual void bp250();
    virtual void bp251();
    virtual void bp252();
    virtual void bp253();
    virtual void bp254();
    virtual void bp255();
    virtual void bp256();
    virtual void bp257();
    virtual void bp258();
    virtual void bp259();
    virtual void bp260();
    virtual void bp261();
    virtual void bp262();
    virtual void bp263();
    virtual void bp264();
    virtual void bp265();
    virtual void bp266();
    virtual void bp267();
    virtual void bp268();
    virtual void bp269();
    virtual void bp270();
    virtual void bp271();
    virtual void bp272();
    virtual void bp273();
    virtual void bp274();
    virtual void bp275();
    virtual void bp276();
    virtual void bp277();
    virtual void bp278();
    virtual void bp279();
    virtual void bp280();
    virtual void bp281();
    virtual void bp282();
    virtual void bp283();
    virtual void bp284();
    virtual void bp285();
    virtual void bp286();
    virtual void bp287();
    virtual void bp288();
    virtual void bp289();
    virtual void bp290();
    virtual void bp291();
    virtual void bp292();
    virtual void bp293();
    virtual void bp294();
    virtual void bp295();
    virtual void bp296();
    virtual void bp297();
    virtual void bp298();
    virtual void bp299();
    virtual void bp300();
    virtual void bp301();
    virtual void bp302();
    virtual void bp303();
    virtual void bp304();
    virtual void bp305();
    virtual void bp306();
    virtual void bp307();
    virtual void bp308();
    virtual void bp309();
    virtual void bp310();
    virtual void bp311();
    virtual void bp312();
    virtual void bp313();
    virtual void bp314();
    virtual void bp315();
    virtual void bp316();
    virtual void bp317();
    virtual void bp318();
    virtual void bp319();
    virtual void bp320();
    virtual void bp321();
    virtual void bp322();
    virtual void bp323();
    virtual void bp324();
    virtual void bp325();
    virtual void bp326();
    virtual void bp327();
    virtual void bp328();
    virtual void bp329();
    virtual void bp330();
    virtual void bp331();
    virtual void bp332();
    virtual void bp333();
    virtual void bp334();
    virtual void bp335();
    virtual void bp336();
    virtual void bp337();
    virtual void bp338();
    virtual void bp339();
    virtual void bp340();
    virtual void bp341();
    virtual void bp342();
    virtual void bp343();
    virtual void bp344();
    virtual void bp345();
    virtual void bp346();
    virtual void bp347();
    virtual void bp348();
    virtual void bp349();
    virtual void bp350();
    virtual void bp351();
    virtual void bp352();
    virtual void bp353();
    virtual void bp354();
    virtual void bp355();
    virtual void bp356();
    virtual void bp357();
    virtual void bp358();
    virtual void bp359();
    virtual void bp360();
    virtual void bp361();
    virtual void bp362();
    virtual void bp363();
    virtual void bp364();
    virtual void bp365();
    virtual void bp366();
    virtual void bp367();
    virtual void bp368();
    virtual void bp369();
    virtual void bp370();
    virtual void bp371();
    virtual void bp372();
    virtual void bp373();
    virtual void bp374();
    virtual void bp375();
    virtual void bp376();
    virtual void bp377();
    virtual void bp378();
    virtual void bp379();
    virtual void bp380();
    virtual void bp381();
    virtual void bp382();
    virtual void bp383();
    virtual void bp384();
    virtual void bp385();
    virtual void bp386();
    virtual void bp387();
    virtual void bp388();
    virtual void bp389();
    virtual void bp390();
    virtual void bp391();
    virtual void bp392();
    virtual void bp393();
    virtual void SetTarget(TargetView* t);
    virtual void bp395();
    virtual void bp396();
    virtual void bp397();
    virtual void bp398();
    virtual void bp399();
    virtual void bp400();
    virtual void SetFallback(int v);
};

struct MobileObject
{
    void* __thiscall FUN_008d8520();
};

struct FUN_009f7f20_class
{
    UnknownObject64 u0, u1;
    UnknownObject32 u2;
    ArrSI entries;
    void __thiscall FUN_009f7f20(MobileObject* actor, unsigned char flag);
};

// @fnv 0x009f7f20
void __thiscall FUN_009f7f20_class::FUN_009f7f20(MobileObject* actor, unsigned char flag)
{
    TargetView* AX;
    if (flag != 0)
    {
        if ((unsigned int)(((ThreatList*)((char*)this + 0xa0))->FUN_0044ddc0()) > 0)
        {
            TargetView* A5 =
                (TargetView*)((Entry*)((FUN_009f8aa0_class*)((char*)this + 0xa0))->FUN_009f8aa0())->FUN_00726070();
            AX = (A5 != 0 && A5->IsActor() != 0) ? A5 : (TargetView*)0;
            if (AX != 0)
            {
                ((BaseProcess*)actor->FUN_008d8520())->SetTarget(AX);
                return;
            }
        }
    }
    ((BaseProcess*)actor->FUN_008d8520())->SetFallback(1);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int bytes);
struct FUN_006e3850
{
    void* begin;
    void* end;
    void* reservedEnd;
    unsigned int capacity;
    unsigned int count;
    unsigned int flags;
    static __forceinline void* __cdecl operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    FUN_006e3850();
    int __thiscall FUN_0044ddc0();
    void __thiscall SetSize(int newCount, int preserve);
    void* __thiscall FUN_006a1400(int index);
};
struct ThreatItem_009f8570
{
    void __thiscall FUN_009f6f30(void* element);
};
struct FUN_009f8570_class
{
    FUN_006e3850* __thiscall FUN_009f8570();
};
// @fnv 0x009f8570
FUN_006e3850* __thiscall FUN_009f8570_class::FUN_009f8570()
{
    FUN_006e3850* output = new FUN_006e3850;
    int total = reinterpret_cast<ThreatList*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_0044ddc0();
    for (int index = 0; index < total; ++index)
    {
        int used;
        ThreatItem_009f8570* item;
        item = reinterpret_cast<ThreatItem_009f8570*>(
            reinterpret_cast<ThreatList*>(reinterpret_cast<char*>(this) + 0xa0)->FUN_009f8a80(index));
        used = output->FUN_0044ddc0();
        output->SetSize(used + 1, 1);
        item->FUN_009f6f30(output->FUN_006a1400(used));
    }
    return output;
}

extern const double DAT_01012060;
unsigned int __cdecl FUN_00487f50();
void* __cdecl GetTopicSubTypeName(int iType, int iFlags);

struct Setting9f7d
{
    float* FUN_00403e20();
};
extern Setting9f7d DAT_011cdc04;
extern Setting9f7d DAT_011ccff0;

struct Timer9f7d
{
    float FUN_0084d030();
};
extern Timer9f7d DAT_011f6394;

struct Process9f7d
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void SetPackage(void* pkActor, void* pkPackage, int a3, int a4, int a5, int a6);
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual bool IsBusy();
    virtual void StopAll(int a1);
};
struct Target9f7d
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool IsValidTarget();
};

struct Candidate9f7d
{
    Target9f7d* FUN_00726070();
};

struct List9f7d
{
    unsigned int FUN_0044ddc0();
    Candidate9f7d* FUN_009f8aa0();
};

struct Actor9f7d
{
    Process9f7d* FUN_008d8520();
    void FUN_008b3ab0();
    void FUN_0057bd60(Target9f7d* pkTarget);
};

struct FUN_009f7d70_cls
{
    unsigned char unk00[0x88];
    float m_fTimer;
    unsigned char unk8C[0xa0 - 0x8c];
    List9f7d m_kTargets;

    void FUN_009f7d70(Actor9f7d* pkActor, bool bActive);
};

// @fnv 0x009f7d70
void FUN_009f7d70_cls::FUN_009f7d70(Actor9f7d* pkActor, bool bActive)
{
    if (!bActive)
    {
        pkActor->FUN_008d8520()->StopAll(0);
        pkActor->FUN_008b3ab0();
        return;
    }
    if (m_kTargets.FUN_0044ddc0() > 0)
    {
        int iRoll = FUN_00487f50() % 100;
        Target9f7d* pkCandidate = m_kTargets.FUN_009f8aa0()->FUN_00726070();
        Target9f7d* pkTarget = (pkCandidate && pkCandidate->IsValidTarget()) ? pkCandidate : 0;
        if (pkTarget)
        {
            if (pkActor->FUN_008d8520() && !pkActor->FUN_008d8520()->IsBusy() && iRoll < *DAT_011cdc04.FUN_00403e20() &&
                m_fTimer <= DAT_01012060)
            {
                void* pkPackage = GetTopicSubTypeName(6, 0);
                if (pkPackage)
                {
                    pkActor->FUN_0057bd60(pkTarget);
                    pkActor->FUN_008d8520()->SetPackage(pkActor, pkPackage, 0, 0, 1, 0);
                    m_fTimer = *DAT_011ccff0.FUN_00403e20();
                }
            }
            m_fTimer -= DAT_011f6394.FUN_0084d030();
        }
    }
}

struct Relation8020
{
    int unk00;
    int unk04;
    int count;
};
struct Actor8020
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual bool IsActor();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsDead(int);
    virtual bool IsDisabled();
    virtual bool IsStateActive();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual Actor8020* GetTarget();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual void slot309();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual Relation8020* GetRelation(Actor8020*, int);
    bool FUN_00440d80();
    Actor8020* FUN_008d8520();
};
struct Threat8020
{
    Actor8020* source;
    Actor8020* target;
    Actor8020* FUN_00559450();
    Actor8020* FUN_00726070();
    unsigned int FUN_0084e3a0();
    void FUN_009f6d50();
};
struct ThreatList8020
{
    int FUN_0044ddc0();
    Threat8020* FUN_009f8a80(int);
    void FUN_009f8c70(int, int);
};
struct SettingFloat8020
{
    float* Float();
};
extern SettingFloat8020 originalRuntimeFloatSetting144;
struct Package8020
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    ThreatList8020 threats;
    void FUN_009f8330(Actor8020*);
    void FUN_009f76e0();
    void FUN_004534f0(Actor8020*);
    void FUN_009f8020(Actor8020* actor);
};
// @fnv 0x009f8020
void Package8020::FUN_009f8020(Actor8020* owner)
{
    bool updated = false;
    int count = threats.FUN_0044ddc0();
    for (int i = 0; i < count; ++i)
    {
        Threat8020* entry = threats.FUN_009f8a80(i);
        if (entry->FUN_00559450() && entry->FUN_00726070())
        {
            Actor8020* currentTarget = entry->FUN_00559450()->GetTarget();
            if (currentTarget && currentTarget != entry->FUN_00726070())
            {
                FUN_009f8330(owner);
                updated = true;
            }
        }
    }
    count = threats.FUN_0044ddc0();
    for (int j = 0; j < count; ++j)
    {
        Threat8020* entry = threats.FUN_009f8a80(j);
        Actor8020* actor = entry->FUN_00559450();
        Actor8020* target = entry->FUN_00726070();
        if (gm_GetTickCount() <= entry->FUN_0084e3a0() + 2000)
            continue;
        if (gm_GetTickCount() > entry->FUN_0084e3a0() + *originalRuntimeFloatSetting144.Float() * 1000.0)
        {
            threats.FUN_009f8c70(j, 1);
            --count;
            --j;
            updated = true;
            continue;
        }
        if (target && (target->IsDead(0) || target->FUN_00440d80() || target->IsStateActive() || target->IsDisabled()))
        {
            entry->target = 0;
            updated = true;
            continue;
        }
        if (actor && actor->IsActor() && owner->FUN_008d8520())
        {
            Relation8020* relation = owner->FUN_008d8520() ? owner->FUN_008d8520()->GetRelation(actor, 0) : 0;
            if (!relation || relation->count <= 0)
                continue;
        }
        if (actor && target && actor->GetTarget() != target)
            continue;
        updated = true;
        entry->FUN_009f6d50();
    }
    if (updated)
        FUN_009f76e0();
    FUN_004534f0(owner);
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

struct Elem
{
    Elem();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};

struct ElemArray
{
    void FUN_009f8de0(Elem* apArray, unsigned int ItemUpdateArray);
};

// @fnv 0x009f8de0
void ElemArray::FUN_009f8de0(Elem* apArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        new (&apArray[i]) Elem;
    }
}

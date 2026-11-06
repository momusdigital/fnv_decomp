
// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
    void __thiscall FUN_0062e860();
};

void __cdecl _Deallocate(void* p);

// Calls FUN_0062e860, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062e750
void* FUN_0062e750_shell::FUN_0062e750(unsigned int flags)
{
    FUN_0062e860();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_011c7a3c;

// @fnv 0x0062f310
void FUN_0062f310(int value)
{
    DAT_011c7a3c = value;
}

extern unsigned char DAT_011c7a5a;

// @fnv 0x0062f8e0
void FUN_0062f8e0(unsigned char value)
{
    DAT_011c7a5a = value;
}

extern float _DAT_011c7a5c;

// @fnv 0x0062f8f0
void FUN_0062f8f0(float value)
{
    _DAT_011c7a5c = value;
}

struct BSOcclusionPlane
{
    unsigned int GetCullResult() const;
};

struct ExtraDataList
{
    unsigned int GetRoomId();
};

struct BSThread
{
    unsigned int GetThreadID();
};

// Returns the thread ID reached through the plane's cull result and its extra data, or 0 if any step is null.
// @fnv 0x0062fec0
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane)
{
    unsigned int result = 0;
    if (pPlane)
    {
        unsigned int cullResult = pPlane->GetCullResult();
        if (cullResult)
        {
            unsigned int room = ((ExtraDataList*)cullResult)->GetRoomId();
            if (room)
            {
                result = ((BSThread*)room)->GetThreadID();
            }
        }
    }
    return result;
}

extern "C" float __cdecl ExpFloat(float);

// @fnv 0x00630aa0
float FUN_00630aa0(float value)
{
    return ExpFloat(value);
}

extern "C" double __cdecl _exp(double);

// @fnv 0x00630ac0
float ExpFloat(float value)
{
    return static_cast<float>(_exp(value));
}

extern float _gModifierZero;

// Returns 1.0 for a positive input, -1.0 for a negative input, and 0.0 for zero.
// @fnv 0x00631070
float __cdecl SignOfFloat(float afValue)
{
    float result;
    if (afValue > 0.0f)
        result = 1.0f;
    else
    {
        float t;
        if (afValue < 0.0f)
            t = -1.0f;
        else
            t = 0.0f;
        result = t;
    }
    return result;
}

struct FUN_005631e0_shell
{
    int __thiscall MaskWithField(int a);
    bool __thiscall IsNonZero(int a);
};

// @fnv 0x005631e0
bool __thiscall FUN_005631e0_shell::IsNonZero(int aiValue)
{
    return MaskWithField(aiValue) != 0;
}

float __cdecl FUN_004a3e90(float);

struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};

// @fnv 0x0062e710
void __thiscall FUN_0062e710_shell::SetValueAt(float afValue, int a, int b)
{
    int index = a + b * (*(int*)((char*)this + 0x28));
    *(float*)((*(int*)((char*)this + 0x20)) + index * 4) = FUN_004a3e90(afValue);
}

struct BSSimpleList_Ragdoll
{
    void* __thiscall FUN_006310e0();
};
struct TESDataHandler
{
    BSSimpleList_Ragdoll* __thiscall GetBGSRagdollList();
};
struct FUN_006310c0_shell
{
    void __thiscall FUN_006310c0();
};

// @fnv 0x006310c0
void FUN_006310c0_shell::FUN_006310c0()
{
    ((TESDataHandler*)this)->GetBGSRagdollList()->FUN_006310e0();
}

void* __cdecl FUN_004b5a80(const void* p);
struct FUN_00c9a520_shell
{
    void __thiscall FUN_00c9a520(void* q);
};
struct FUN_0062e940_shell
{
    void __thiscall ProcessAndForward(const void* p);
};
// @fnv 0x0062e940
void __thiscall FUN_0062e940_shell::ProcessAndForward(const void* p)
{
    void* q = FUN_004b5a80(p);
    ((FUN_00c9a520_shell*)this)->FUN_00c9a520(q);
}

struct FUN_00576830_shell
{
    void* __thiscall FUN_00576830(BSOcclusionPlane* pPlane);
};

// Calls GetOcclusionPlaneThreadID on pPlane; if it returns non-null, calls FUN_00576830 on the object at offset 0x14 and returns its result, otherwise returns null.
// @fnv 0x0062fe80
void* FUN_0062fe80(BSOcclusionPlane* pPlane)
{
    void* result = 0;
    unsigned int cull = GetOcclusionPlaneThreadID(pPlane);
    if (cull)
        result = reinterpret_cast<FUN_00576830_shell*>(reinterpret_cast<char*>(cull) + 0x14)->FUN_00576830(pPlane);
    return result;
}

struct FUN_0062b0a0_shell
{
    void* __thiscall FUN_0062b0a0(void* a, void* b);
};
struct FUN_00630100_shell
{
    void* __thiscall FUN_00630100(void* arg);
};
// Calls FUN_0062b0a0 with arg and this, then returns arg.
// @fnv 0x00630100
void* __thiscall FUN_00630100_shell::FUN_00630100(void* arg)
{
    ((FUN_0062b0a0_shell*)this)->FUN_0062b0a0(arg, this);
    return arg;
}

struct PackedByteIntRecord
{
    char* __thiscall Endian();
};
// @fnv 0x006310e0
void* BSSimpleList_Ragdoll::FUN_006310e0()
{
    return (char*)((PackedByteIntRecord*)((char*)this + 0x10))->Endian() + 0x10;
}

struct UnkCall
{
    void __thiscall FUN_00c9c1d0();
};
struct VList
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void Target(float a, int b);
};
struct FUN_00631100_shell
{
    void __thiscall FUN_00631100(float a, int b);
};
// Calls FUN_00c9c1d0 on this, then forwards a and b to Target on the BGSRagdollList from TESDataHandler.
// @fnv 0x00631100
void __thiscall FUN_00631100_shell::FUN_00631100(float afValue, int aiValue)
{
    ((UnkCall*)this)->FUN_00c9c1d0();
    ((VList*)((TESDataHandler*)this)->GetBGSRagdollList())->Target(afValue, aiValue);
}

struct FUN_00c9c1d0_shell
{
    void __thiscall FUN_00c9c1d0();
};
struct ListCall00631140
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void Target(float, int, int);
};
struct FUN_00631140_shell
{
    void __thiscall FUN_00631140(float, int, int);
};
// Calls FUN_00c9c1d0 on this, then forwards a, b and c to Target on the BGSRagdollList from the data handler.
// @fnv 0x00631140
void __thiscall FUN_00631140_shell::FUN_00631140(float afValue, int aiArg1, int aiArg2)
{
    ((FUN_00c9c1d0_shell*)this)->FUN_00c9c1d0();
    ((ListCall00631140*)((TESDataHandler*)this)->GetBGSRagdollList())->Target(afValue, aiArg1, aiArg2);
}

struct AX
{
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
};
extern int DAT_0104e4bc;

struct FUN_00631750_shell
{
    void* __thiscall FUN_00631750();
};

// Sets the object's vtable pointer to DAT_0104e4bc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00631750
void* __thiscall FUN_00631750_shell::FUN_00631750()
{
    *(void**)this = &DAT_0104e4bc;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_00628f30_shell
{
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
    void __thiscall FUN_00628f70(int arg);
    void __thiscall SetFlag(int a, bool b);
};
// @fnv 0x00628f30
void __thiscall FUN_00628f30_shell::SetFlag(int aiFlag, bool abSet)
{
    if (abSet)
        m16 |= aiFlag;
    else
        FUN_00628f70(aiFlag);
}

struct ArrSI
{
    unsigned int GetFlags() const;
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct FUN_0057b700_class
{
    int FUN_0057b730(int);
    void FUN_0061ff30(int);
};
bool __cdecl FUN_009a3830(int const*, int const*);
struct FUN_0062e500_shell : FUN_0057b700_class
{
    void FUN_0062e500(int a, int b);
};

// @fnv 0x0062e500
void FUN_0062e500_shell::FUN_0062e500(int aiKey, int auiValue)
{
    int ptarget2 = *(int*)((char*)this + 0x14) ? FUN_0057b730(aiKey) : 0;
    unsigned int uindex;
    if (ptarget2)
    {
        uindex = ((LS3de0*)((char*)ptarget2 + 0x50))->Find(*(unsigned int*)&auiValue, 0, FUN_009a3830);
        if (uindex != (unsigned int)-1)
            ((LS3de0*)((char*)ptarget2 + 0x50))->UpdateEntryValue(uindex, 1);
        if (!((ArrSI*)((char*)ptarget2 + 0x50))->GetFlags())
            FUN_0061ff30(ptarget2);
    }
}

struct GameTimerRecord
{
    unsigned int GetTime() const;
};
struct FUN_0061fef0_Node
{
    void* FUN_0061fef0();
};
struct FUN_0042f130
{
    bool SetWaterZone(void*);
};
struct XActor
{
    void* GetExtra(void) const;
};
struct FUN_0042f030_shell
{
    void FUN_0042f030(void*, int);
};
struct FUN_006205e0_shell
{
    void RemoveNode(void*);
};
struct ref_0084e3a0_shell
{
    void* ref_0084e3a0();
};
struct FUN_006312d0_shell
{
    void FUN_006312d0(void* apWaterRef);
};
// @fnv 0x006312d0
void FUN_006312d0_shell::FUN_006312d0(void* apWaterRef)
{
    void* pzone = FUN_0062fe80((BSOcclusionPlane*)apWaterRef);
    if (pzone)
    {
        GameTimerRecord* pentry = (GameTimerRecord*)((GameTimerRecord*)pzone)->GetTime();
        while (pentry)
        {
            XActor* pActor = (XActor*)((ref_0084e3a0_shell*)((char*)pentry + 0x10))->ref_0084e3a0();
            if (pActor)
            {
                while (((FUN_0042f130*)((XActor*)pActor)->GetExtra())->SetWaterZone(pzone))
                    ((FUN_0042f030_shell*)((XActor*)pActor)->GetExtra())->FUN_0042f030(pzone, 0);
            }
            pentry = (GameTimerRecord*)((FUN_0061fef0_Node*)pentry)->FUN_0061fef0();
        }
        ((FUN_006205e0_shell*)((char*)this + 0x14))->RemoveNode(pzone);
    }
}

struct TESObjectREFR;
struct EffectSetting
{
    int __thiscall GetEffectID();
};
struct WaterZoneManager
{
    void* GetWaterZone(TESObjectREFR*, TESObjectREFR*, float);
};
extern int g_TES;
struct FUN_00631230_shell
{
    FUN_00631230_shell(TESObjectREFR*, void*);
    char m0[0x1c];
    void* pGroup;
};
struct FUN_00631180_shell
{
    FUN_00631230_shell* FUN_00631180(TESObjectREFR*, void*);
};
// Allocates a FUN_00631230_shell for apRef and apCol, stores the result of a call on the effect setting's object into pGroup, and returns it.
// @fnv 0x00631180
FUN_00631230_shell* FUN_00631180_shell::FUN_00631180(TESObjectREFR* apRef, void* apCol)
{
    FUN_00631230_shell* apWZone = new FUN_00631230_shell(apRef, apCol);
    apWZone->pGroup = ((WaterZoneManager*)(void*)((EffectSetting*)g_TES)->GetEffectID())
                          ->GetWaterZone(apRef, (TESObjectREFR*)0, 0.0f);
    return apWZone;
}

bool __cdecl FUN_009a3830(int const*, int const*);

struct RefList : LS3de0
{
    int list00;
    int list04;
    int list08;
    int list0C;
    unsigned int Add(unsigned int& item);
};

struct LinkBase
{
    int link00;
    int link04;
    int link08;
    int link0C;
    int link10;
    int link14;
    int link18;
    int link1C;
    int link20;
    int link24;
    int link28;
    int link2C;
    int link30;
    int link34;
    int link38;
    int link3C;
    void InsertAfterLink(int a, int b);
    void LinkTo(LinkBase* prev);
};

struct NodeHead
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct LinkedNode : NodeHead, LinkBase
{
    LinkedNode(int a, unsigned int b);
    static void* operator new(unsigned int size);
    static void operator delete(void*);
    RefList refs;
};

struct NodeOwner : FUN_0057b700_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LinkedNode* pHead;
    LinkedNode* FindOrCreateNode(int key, unsigned int ref, int arg);
};

// Looks up a node by key, adds ref to its ref list if missing, or creates and links a new node into the head list.
// @fnv 0x0062e3d0
LinkedNode* NodeOwner::FindOrCreateNode(int key, unsigned int ref, int arg)
{
    LinkedNode* pNode = pHead ? (LinkedNode*)FUN_0057b730(key) : 0;
    if (pNode)
    {
        if (pNode->refs.Find(ref, 0, FUN_009a3830) == -1)
            pNode->refs.Add(ref);
    }
    else
    {
        pNode = new LinkedNode(key, ref);
        pNode->InsertAfterLink(arg, 1);
        pNode->LinkTo(pHead);
        pHead = pNode;
    }
    return pNode;
}

struct SpawnedBase
{
    SpawnedBase(int a, int b);
    virtual void Vf();
};

struct SpawnedSub
{
    SpawnedSub();
    ~SpawnedSub();
    unsigned int FUN_00719b20(const int* a, int b, bool(__cdecl* cmp)(int const*, int const*));
    void FUN_007cb2e0(const int* a);
};

struct FUN_0062e590 : SpawnedBase
{
    FUN_0062e590(int a1, int a2);
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
    SpawnedSub m_50;
};

// Constructs the base with a1 and zero, then initializes m_50 from a2, falling back to FUN_007cb2e0 when FUN_00719b20 returns -1.
// @fnv 0x0062e590
FUN_0062e590::FUN_0062e590(int a1, int aiValue) : SpawnedBase(a1, 0), m_50()
{
    if (m_50.FUN_00719b20(&aiValue, 0, FUN_009a3830) == -1)
    {
        m_50.FUN_007cb2e0(&aiValue);
    }
}

struct FUN_00cb75d0
{
    virtual void OnEvent();
    void* owner;
    unsigned int flags;
    void* context;
    unsigned int referenceCount;
    FUN_00cb75d0();
    ~FUN_00cb75d0();
};
struct FUN_0061ffb0
{
    virtual void Update();
    unsigned int state;
    FUN_0061ffb0();
    ~FUN_0061ffb0();
};
struct FUN_0048f200
{
    FUN_0048f200();
    ~FUN_0048f200();
};
struct FUN_0062e630 : FUN_00cb75d0, FUN_0061ffb0
{
    float scale;
    int* data;
    unsigned int capacity;
    unsigned int enabled;
    int predecessor;
    int successor;
    FUN_0048f200 synchronization;
    FUN_0062e630(float value);
};
// Initializes the object: sets scale to 1.0, enabled to 1, allocates data, calls SetValueAt with value, and clears predecessor and successor.
// @fnv 0x0062e630
FUN_0062e630::FUN_0062e630(float value) : scale(1.0f)
{
    enabled = 1;
    data = new int;
    reinterpret_cast<FUN_0062e710_shell*>(this)->SetValueAt(value, 0, 0);
    predecessor = 0;
    successor = 0;
}

struct S_0062f320_Tmp
{
    int unk00;
};
struct S_0062f320_Type
{
    int FUN_0043b4d0();
};
struct S_0062f320_Form
{
    int FUN_00517630();
    S_0062f320_Type* FUN_0043b4f0(S_0062f320_Tmp* t);
};
extern int DAT_012681c0;
const char* __cdecl FUN_004b5a80(const char* p);
S_0062f320_Form* __cdecl FUN_00653270(int* table, const char* name);
struct S_0062f320_This
{
    S_0062f320_Form* FUN_0062f320(const char* name);
};
// Looks up a form by name in DAT_012681c0, rejects it if FUN_00517630 returns 5, and returns it only when FUN_0043b4d0 yields one of the listed values.
// @fnv 0x0062f320
S_0062f320_Form* S_0062f320_This::FUN_0062f320(const char* name)
{
    const char* akey = FUN_004b5a80(name);
    S_0062f320_Form* bform = FUN_00653270(&DAT_012681c0, akey);
    if (bform->FUN_00517630() == 5)
    {
        return 0;
    }
    if (bform)
    {
        S_0062f320_Tmp tmp;
        switch (bform->FUN_0043b4f0(&tmp)->FUN_0043b4d0())
        {
        case 4:
        case 5:
        case 6:
        case 8:
        case 10:
        case 12:
        case 13:
        case 14:
        case 29:
            return bform;
        }
    }
    return 0;
}

struct S_0062f5b0_Obj;

struct S_0062f5b0_Ptr
{
    S_0062f5b0_Obj* unk0;
    S_0062f5b0_Ptr(S_0062f5b0_Obj* p);
    ~S_0062f5b0_Ptr();
};

struct S_0062f5b0_Sub
{
    void FUN_00631540(const S_0062f5b0_Ptr& p);
};

S_0062f5b0_Obj* __cdecl FUN_004b59f0(void* a);

struct S_0062f5b0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    S_0062f5b0_Sub unk0c;
    bool __thiscall FUN_0062f5b0(void* a, int b);
};

// Wraps the object returned by FUN_004b59f0 in a scoped pointer, passes it to unk0c.FUN_00631540, and returns false.
// @fnv 0x0062f5b0
bool S_0062f5b0_Cls::FUN_0062f5b0(void* a, int b)
{
    bool result = false;
    {
        S_0062f5b0_Ptr p(FUN_004b59f0(a));
        unk0c.FUN_00631540(p);
    }
    return result;
}

void* __cdecl FUN_004b59f0(int a);

struct LocalObj
{
    unsigned int unk00;
    LocalObj(void* src);
    ~LocalObj();
};

struct MemberObj
{
    unsigned int unk00;
    void __thiscall FUN_00631620(LocalObj* p);
};

struct FUN_0062f630_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    MemberObj m_0c;

    bool ApplyToMember(int a, int unused);
};

// Builds a LocalObj from FUN_004b59f0(a), passes it to m_0c.FUN_00631620, then returns true.
// @fnv 0x0062f630
bool FUN_0062f630_cls::ApplyToMember(int a, int unused)
{
    bool done = false;
    {
        LocalObj tmp(FUN_004b59f0(a));
        m_0c.FUN_00631620(&tmp);
    }
    done = true;
    return done;
}

extern float g_fB630120Invalid;

class B630120Grid
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float* m_pfValues;
    int unk24;
    unsigned int m_uiSize;

    float GetValue(unsigned int uiX, unsigned int uiY);
};

// Returns the grid value at (uiX, uiY) if the computed index is within m_uiSize squared, otherwise g_fB630120Invalid.
// @fnv 0x00630120
float B630120Grid::GetValue(unsigned int uiX, unsigned int uiY)
{
    unsigned int uiIndex = uiY * m_uiSize + uiX;
    return uiIndex < m_uiSize * m_uiSize ? m_pfValues[uiIndex] : g_fB630120Invalid;
}

struct Vec3_62e970
{
    float x;
    float y;
    float z;
    Vec3_62e970();
};
struct FilterTmp_62e970
{
    int unk00;
};
struct Filter_62e970
{
    int FUN_0043b4d0();
};
struct Body_62e970
{
    Filter_62e970* FUN_0043b4f0(FilterTmp_62e970* t);
    void FUN_00560d50(Vec3_62e970& v);
    void FUN_00560bc0(Vec3_62e970& v);
};
float __fastcall GetMass(void* p);
float FUN_00408820(float f);
struct FloatSetting_62e970
{
    float* Float();
};
extern FloatSetting_62e970 originalRuntimeFloatSetting984;
extern FloatSetting_62e970 originalRuntimeFloatSetting985;
extern FloatSetting_62e970 originalRuntimeFloatSetting986;
struct Splash_62e970
{
    void Play(Vec3_62e970 pos, float scale);
};
struct TES_62e970
{
    void* GetInteriorCell();
    bool UpdateTESState(Vec3_62e970& pos, float& height);
    Splash_62e970* GetSplash();
};
struct TaskQueue_62e970
{
    static TaskQueue_62e970* GetInstance();
    void QueueSplash(float scale, Vec3_62e970* pos);
    void QueueSplashFx(float scale, Vec3_62e970* pos);
};
bool FUN_008c7aa0();
void __cdecl PlaySplashEffects(float scale, Vec3_62e970 pos);
extern const float kSplashScale_62e970;

struct WaterSplash_62e970
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float fCooldown;
    void SpawnWaterSplash(Body_62e970* apBody, float afWaterZ);
};

// @fnv 0x0062e970
void WaterSplash_62e970::SpawnWaterSplash(Body_62e970* apBody, float afWaterZ)
{
    FilterTmp_62e970 tmp4;
    float fMass;
    float fScale;
    float fSpeed;
    float fHeight4;

    if (!apBody || fCooldown > 0.0)
        return;
    if (apBody->FUN_0043b4f0(&tmp4)->FUN_0043b4d0() == 8)
        return;
    fMass = GetMass(apBody);
    Vec3_62e970 vel;
    apBody->FUN_00560d50(vel);
    fSpeed = FUN_00408820(vel.z);
    if (fSpeed < 0.001)
        return;
    fScale = *originalRuntimeFloatSetting985.Float() * fSpeed + fMass;
    if (vel.z > 0.0)
        fScale = fScale * *originalRuntimeFloatSetting986.Float();
    Vec3_62e970 _pos;
    apBody->FUN_00560bc0(_pos);
    fHeight4 = afWaterZ;
    if (!((TES_62e970*)g_TES)->GetInteriorCell() && ((TES_62e970*)g_TES)->UpdateTESState(_pos, fHeight4) &&
        fHeight4 > afWaterZ)
        return;
    _pos.z = afWaterZ;
    if (!FUN_008c7aa0())
        PlaySplashEffects(fScale, _pos);
    else
        TaskQueue_62e970::GetInstance()->QueueSplash(fScale, &_pos);
    if (!FUN_008c7aa0())
        ((TES_62e970*)g_TES)->GetSplash()->Play(_pos, kSplashScale_62e970);
    else
        TaskQueue_62e970::GetInstance()->QueueSplashFx(kSplashScale_62e970, &_pos);
    fCooldown = *originalRuntimeFloatSetting984.Float();
}

class GameSettingCollection;
union SETTING_VALUE
{
    float f;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

class GlobalObject_0040e0b0
{
  public:
    float* Float();
};

class GlobalObject_0040c150
{
  public:
    const char* String();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting981;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting982;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting983;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting987;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting988;
extern GlobalObject_0040e0b0 g_011d1458;
extern GlobalObject_0040c150 g_011d12c0;

class BSSoundHandleEx
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& rhs);
    bool IsValid();
    bool SetPosition(float x, float y, float z);
    bool Play(bool bUnk);
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct ThreeByThreeMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    ThreeByThreeMatrix();
    void SetZRotation(float angle);
};

struct TESWaterForm
{
    bool FUN_00580060();
};

class TESObjectCELL
{
  public:
    TESWaterForm* FUN_00547770();
};

class PlayerCharacter
{
  public:
    TESObjectCELL* GetParentCell();
};

extern PlayerCharacter* _g_thePlayer;

float __cdecl FUN_004a4240();
void* __cdecl FUN_00689210(TESObjectCELL* cell, float f1, const char* str, ThreeByThreeMatrix mat, NiPoint3 pos, float f2,
                           int b1, void* p0);
bool __cdecl FUN_008c7aa0();

struct TESWaterSystemMgr
{
    void AddWaterRipple(NiPoint3 pos, float amount);
};

class TES_Ext
{
  public:
    TESWaterSystemMgr* GetWaterMgr();
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueRipple(float amount, NiPoint3* pos);
};

// @fnv 0x0062eb50
void __cdecl PlaySplashEffects(float a1, NiPoint3 aPosition)
{
    float fMult = 1.0f;
    BSSoundHandleEx kSound;

    if (a1 > originalRuntimeFloatSetting981.Float()->f)
    {
        kSound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("CWaterLarge", 0x102);
        fMult = *g_011d1458.Float();
    }
    if (!kSound.IsValid() && a1 > originalRuntimeFloatSetting982.Float()->f)
    {
        kSound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("CWaterMedium", 0x102);
        fMult = originalRuntimeFloatSetting987.Float()->f;
    }
    if (!kSound.IsValid() && a1 > originalRuntimeFloatSetting983.Float()->f)
    {
        kSound = BSAudio::GetSingleton()->GetSoundHandleByEditorID("CWaterSmall", 0x102);
        fMult = originalRuntimeFloatSetting988.Float()->f;
    }
    if (kSound.IsValid())
    {
        kSound.SetPosition(aPosition.x, aPosition.y, aPosition.z);
        kSound.Play(false);
        if (fMult > 0.0 && _g_thePlayer->GetParentCell() && _g_thePlayer->GetParentCell()->FUN_00547770() &&
            !_g_thePlayer->GetParentCell()->FUN_00547770()->FUN_00580060())
        {
            ThreeByThreeMatrix kMat;
            kMat.SetZRotation(FUN_004a4240());
            FUN_00689210(_g_thePlayer->GetParentCell(), 1.0f, g_011d12c0.String(), kMat, aPosition, fMult, 1, 0);
        }
    }
    if (!FUN_008c7aa0())
    {
        ((TES_Ext*)g_TES)->GetWaterMgr()->AddWaterRipple(aPosition, 0.01f);
    }
    else
    {
        TaskQueueInterface::GetSingleton()->QueueRipple(0.01f, &aPosition);
    }
}

#include <xmmintrin.h>
struct FUN_00630d30_cls
{
    __m128 m_vec;
    void FUN_00630d30(const __m128* a, const __m128* b);
};
// Adds the element-wise product of two vectors to m_vec using SSE intrinsics.
// @fnv 0x00630d30
void FUN_00630d30_cls::FUN_00630d30(const __m128* apFirst, const __m128* apSecond)
{
    m_vec = _mm_add_ps(m_vec, _mm_mul_ps(*apFirst, *apSecond));
}

struct B631230Stats
{
    int unk00;
    int unk04;
    float m_fValue;
};

class B631230Actor
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void vfunc4F();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc5A();
    virtual void vfunc5B();
    virtual void vfunc5C();
    virtual void vfunc5D();
    virtual void vfunc5E();
    virtual void vfunc5F();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc6A();
    virtual void vfunc6B();
    virtual void vfunc6C();
    virtual void vfunc6D();
    virtual void vfunc6E();
    virtual void vfunc6F();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void vfunc73();
    virtual void vfunc74();
    virtual void vfunc75();
    virtual void vfunc76();
    virtual void vfunc77();
    virtual void vfunc78();
    virtual void vfunc79();
    virtual void vfunc7A();
    virtual void vfunc7B();
    virtual void vfunc7C();
    virtual B631230Stats* GetStats();
};

class B631230Base
{
  public:
    B631230Base(B631230Actor* pkActor, unsigned int uiType);
    virtual ~B631230Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_00631230 : public B631230Base
{
  public:
    float m_fStartValue;
    int m_iArrayLength;

    FUN_00631230(B631230Actor* pkActor, unsigned int uiType);
    virtual ~FUN_00631230();
};

// @fnv 0x00631230
FUN_00631230::FUN_00631230(B631230Actor* pkActor, unsigned int uiType) : B631230Base(pkActor, uiType)
{
    m_fStartValue = pkActor ? pkActor->GetStats()->m_fValue : 0.0f;
    m_iArrayLength = 0;
}

class TESBoundObject
{
  public:
    virtual void vf0();
};
class BGSPlaceableWater : public TESBoundObject
{
  public:
    bool IsRestricted();
};
struct PhysBody
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual PhysBody* Body();
};
struct Collision
{
    PhysBody* GetWorld();
};
struct Scene
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Collision* CollisionData();
};
struct SceneHolder
{
    Scene* GetScene();
};
struct WaterForm
{
};
struct TESObjectREFR
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual int WaterType();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual SceneHolder* BoneTransformData();
    TESBoundObject* GetBase();
    bool IsDeleted();
};
TESObjectREFR* __cdecl GetCdBodyRef(void*);
struct Cell
{
    float Height();
    int Water();
};
struct PlayerExtra
{
    struct WaterEntry* Find();
};
struct RefHolder
{
    TESObjectREFR* GetBase();
};
struct WaterSub
{
    struct RefHolder* Ref();
};
struct WaterEntry
{
    int unk00;
    WaterSub sub;
};
struct Player
{
    Cell* CellData();
    struct PlayerHandle* Handle();
    PlayerExtra* Extra();
};
struct PlayerHandle
{
    void* Get();
};
struct SettingWater
{
    unsigned char* Bool();
};
extern SettingWater g_011cc5a8;
void __cdecl ResetWater(int);
void FUN_0062f8f0(float);
void FUN_0062f8e0(unsigned char);
void FUN_0062f310(int);
struct WaterRecord
{
    TESObjectREFR* reference;
    PhysBody* body;
    TESObjectREFR* water;
    struct Group* group;
    void* source;
};
struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* data;
};
struct GroupMap
{
    Group* Find(void*);
};
struct RecordList
{
    void* Head();
    WaterRecord*& Get(void*);
    void* Next(void*);
    void Add(WaterRecord* const&);
};
struct EventWater
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* water;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    void* reference;
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
struct WaterManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    GroupMap* groups;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    RecordList records;
    void Process(WaterRecord*);
    bool FUN_0062f900(EventWater* event);
};
// Resolves the event's water and reference, checks restrictions, then handles the player case or records or processes the reference.
// @fnv 0x0062f900
bool WaterManager::FUN_0062f900(EventWater* event)
{
    bool f = false;
    TESObjectREFR* s = GetCdBodyRef(event->reference);
    TESObjectREFR* eb = GetCdBodyRef(event->water);
    if (!eb)
        return false;
    BGSPlaceableWater* i = dynamic_cast<BGSPlaceableWater*>(eb->GetBase());
    if (!*g_011cc5a8.Bool() && i->IsRestricted())
        return false;
    Group* p = groups ? groups->Find(event->water) : 0;
    Group* q = p;
    void* cf = q ? q->data : 0;
    if (!s && ((Player*)_g_thePlayer)->CellData())
    {
        if (event->reference == ((Player*)_g_thePlayer)->Handle()->Get())
        {
            ResetWater(0);
            FUN_0062f8f0(((Player*)_g_thePlayer)->CellData()->Height());
            FUN_0062f8e0(0);
            WaterEntry* entry = ((Player*)_g_thePlayer)->Extra()->Find();
            if (entry)
            {
                TESObjectREFR* ref = entry->sub.Ref()->GetBase();
                FUN_0062f310(ref->WaterType());
            }
            else
            {
                FUN_0062f310(((Player*)_g_thePlayer)->CellData()->Water());
            }
            return true;
        }
        return false;
    }
    else if (!s)
    {
        return false;
    }
    else if (s->IsDeleted())
    {
        return false;
    }
    PhysBody* a = 0;
    Scene* h = s->BoneTransformData()->GetScene();
    if (h)
    {
        Collision* collision = h->CollisionData();
        if (collision)
        {
            PhysBody* world = collision->GetWorld();
            if (world)
                a = world->Body();
        }
    }
    {
        void* p;
        int h;
        bool found8;
        WaterRecord* item5;
        WaterRecord* record3;
        WaterRecord recordX;
        unsigned int size;
        void* allocationX;
        if (a)
        {
            p = records.Head();
            h = 0;
            found8 = false;
            while (p)
            {
                item5 = records.Get(p);
                p = records.Next(p);
                if (item5->body == a)
                {
                    found8 = true;
                    break;
                }
            }
            if (!found8)
            {
                size = sizeof(WaterRecord);
                allocationX = operator new(size);
                record3 = allocationX ? (fnv_zlib_memset(allocationX, 0, size), (WaterRecord*)allocationX) : 0;
                record3->reference = s;
                record3->body = a;
                record3->water = eb;
                record3->group = q;
                record3->source = event->reference;
                records.Add(record3);
            }
        }
        else
        {

            recordX.reference = s;
            recordX.body = a;
            recordX.water = eb;
            recordX.group = q;
            recordX.source = event->reference;
            Process(&recordX);
        }
    }
    return true;
}

struct WaterPosition
{
    float x;
    float y;
    float z;
};
struct WaterContactPositionView
{
    virtual void Virtual000();
    virtual void Virtual001();
    virtual void Virtual002();
    virtual void Virtual003();
    virtual void Virtual004();
    virtual void Virtual005();
    virtual void Virtual006();
    virtual void Virtual007();
    virtual void Virtual008();
    virtual void Virtual009();
    virtual void Virtual010();
    virtual void Virtual011();
    virtual void Virtual012();
    virtual void Virtual013();
    virtual void Virtual014();
    virtual void Virtual015();
    virtual void Virtual016();
    virtual void Virtual017();
    virtual void Virtual018();
    virtual void Virtual019();
    virtual void Virtual020();
    virtual void Virtual021();
    virtual void Virtual022();
    virtual void Virtual023();
    virtual void Virtual024();
    virtual void Virtual025();
    virtual void Virtual026();
    virtual void Virtual027();
    virtual void Virtual028();
    virtual void Virtual029();
    virtual void Virtual030();
    virtual void Virtual031();
    virtual void Virtual032();
    virtual void Virtual033();
    virtual void Virtual034();
    virtual void Virtual035();
    virtual void Virtual036();
    virtual void Virtual037();
    virtual void Virtual038();
    virtual void Virtual039();
    virtual void Virtual040();
    virtual void Virtual041();
    virtual void Virtual042();
    virtual void Virtual043();
    virtual void Virtual044();
    virtual void Virtual045();
    virtual void Virtual046();
    virtual void Virtual047();
    virtual void Virtual048();
    virtual void Virtual049();
    virtual void Virtual050();
    virtual void Virtual051();
    virtual void Virtual052();
    virtual void Virtual053();
    virtual void Virtual054();
    virtual void Virtual055();
    virtual void Virtual056();
    virtual void Virtual057();
    virtual void Virtual058();
    virtual void Virtual059();
    virtual void Virtual060();
    virtual void Virtual061();
    virtual void Virtual062();
    virtual void Virtual063();
    virtual void Virtual064();
    virtual void Virtual065();
    virtual void Virtual066();
    virtual void Virtual067();
    virtual void Virtual068();
    virtual void Virtual069();
    virtual void Virtual070();
    virtual void Virtual071();
    virtual void Virtual072();
    virtual void Virtual073();
    virtual void Virtual074();
    virtual void Virtual075();
    virtual void Virtual076();
    virtual void Virtual077();
    virtual void Virtual078();
    virtual void Virtual079();
    virtual void Virtual080();
    virtual void Virtual081();
    virtual void Virtual082();
    virtual void Virtual083();
    virtual void Virtual084();
    virtual void Virtual085();
    virtual void Virtual086();
    virtual void Virtual087();
    virtual void Virtual088();
    virtual void Virtual089();
    virtual void Virtual090();
    virtual void Virtual091();
    virtual void Virtual092();
    virtual void Virtual093();
    virtual void Virtual094();
    virtual void Virtual095();
    virtual void Virtual096();
    virtual void Virtual097();
    virtual void Virtual098();
    virtual void Virtual099();
    virtual void Virtual100();
    virtual void Virtual101();
    virtual void Virtual102();
    virtual void Virtual103();
    virtual void Virtual104();
    virtual void Virtual105();
    virtual void Virtual106();
    virtual void Virtual107();
    virtual void Virtual108();
    virtual void Virtual109();
    virtual void Virtual110();
    virtual void Virtual111();
    virtual void Virtual112();
    virtual void Virtual113();
    virtual void Virtual114();
    virtual void Virtual115();
    virtual void Virtual116();
    virtual void Virtual117();
    virtual void Virtual118();
    virtual void Virtual119();
    virtual void Virtual120();
    virtual void Virtual121();
    virtual void Virtual122();
    virtual void Virtual123();
    virtual void Virtual124();
    virtual WaterPosition* GetWaterPosition();
};
TESObjectREFR* __cdecl GetCdBodyRef(void* handle);
struct PlayerWaterReference
{
    void* GetSourceFilesFromObject();
};
struct WaterContactReference : TESObjectREFR
{
    void FUN_0057b0d0(void* update, int enabled);
};
struct PlayerWater : TESObjectREFR
{
    PlayerWaterReference* FUN_0061f6c0();
};
void __cdecl FUN_00575c90(int enabled);
struct WaterRequest
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* source;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* destination;
};
struct WaterUpdates
{
    void* FUN_00620340(WaterRequest*, TESObjectREFR*, TESObjectREFR*, int, int);
};
struct WaterTaskQueue
{
    void FUN_0087b4a0(TESObjectREFR*, TESObjectREFR*, float);
};
WaterTaskQueue* __cdecl FUN_004537b0();
bool __cdecl FUN_008c7aa0();
struct WaterContactManager
{
    void AddObjectToEntry(TESObjectREFR*, TESObjectREFR*, float);
};
struct TESWaterAccess
{
    WaterContactManager* FUN_0070ec90();
};
struct WaterOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    WaterUpdates updates;
    void FUN_00631370(TESObjectREFR*, int, int);
    bool FUN_0062f6b0(WaterRequest* request);
};
// Processes a water request by resolving source and destination references, checking restrictions, and dispatching water contact updates.
// @fnv 0x0062f6b0
bool WaterOwner::FUN_0062f6b0(WaterRequest* request)
{
    bool e = false;
    TESObjectREFR* d = GetCdBodyRef(request->destination);
    if (!d)
    {
        if (request->destination == ((PlayerWater*)_g_thePlayer)->FUN_0061f6c0()->GetSourceFilesFromObject())
        {
            TESObjectREFR* f = GetCdBodyRef(request->source);
            if (!f)
                return false;
            BGSPlaceableWater* g = dynamic_cast<BGSPlaceableWater*>(f->GetBase());
            if (!*g_011cc5a8.Bool() && g->IsRestricted())
                return false;
            FUN_0062f8f0(((WaterContactPositionView*)f)->GetWaterPosition()->z);
            FUN_00575c90(1);
            FUN_0062f8e0(1);
            FUN_0062f310(((TESObjectREFR*)g)->WaterType());
            return true;
        }
        return false;
    }
    TESObjectREFR* b = GetCdBodyRef(request->source);
    if (!b)
        return false;
    BGSPlaceableWater* c = dynamic_cast<BGSPlaceableWater*>(b->GetBase());
    if (!*g_011cc5a8.Bool() && c->IsRestricted())
        return false;
    if (d == (TESObjectREFR*)_g_thePlayer)
        FUN_0062f310(((TESObjectREFR*)c)->WaterType());
    void* a = updates.FUN_00620340(request, b, d, 0, 0);
    ((WaterContactReference*)d)->FUN_0057b0d0(a, 1);
    if (FUN_008c7aa0() && FUN_004537b0())
    {
        FUN_004537b0()->FUN_0087b4a0(b, d, 0.0f);
    }
    else
    {
        WaterContactManager* h = ((TESWaterAccess*)g_TES)->FUN_0070ec90();
        h->AddObjectToEntry(b, d, 0.0f);
    }
    FUN_00631370(d, 0, 1);
    return true;
}

struct RetStruct
{
    int unk00;
    int unk04;
    float unk08;
};

struct VBase125
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
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
    virtual RetStruct* Vf125();
};

class EffectItem;

class Ref_0062fc70 : public VBase125
{
  public:
    TESObjectCELL* GetParentCell();
    void FUN_0057b0d0(EffectItem* a, int b);
    void FUN_0057b240(int a);
    ExtraDataList* GetExtraData();
};

class EffectItem
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
    void Process(Ref_0062fc70* a, int b);
    EffectSetting* GetEffectSetting();
};

struct NiTMap
{
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, void*& val);
};

struct EDL_Helper
{
    int FUN_0042f180();
    NiTMap* FUN_0042f1d0();
};

struct Holder0087b4f0
{
    void FUN_0087b4f0(int a, int b, float c);
};

bool FUN_008c7aa0();

unsigned int __fastcall FUN_0070ec90(char* p);

struct WaterGroupRemovalCall
{
    void FUN_004e5df0(TESObjectREFR* water, TESObjectREFR* reference, float height);
};

struct ParamStruct
{
    Ref_0062fc70* unk00;
    FUN_00628f30_shell* unk04;
    Ref_0062fc70* unk08;
    EffectItem* unk0c;
    int unk10;
};

struct WaterZoneRemoval : WaterSplash_62e970
{
    void RemoveReferenceFromZone(ParamStruct* param);
};

// @fnv 0x0062fc70
void WaterZoneRemoval::RemoveReferenceFromZone(ParamStruct* apParams)
{
    bool b5;
    bool b8 = false;
    bool b9;
    void* var_8 = apParams->unk0c ? apParams->unk0c->unk1c : 0;

    if (apParams->unk00 == (Ref_0062fc70*)_g_thePlayer && b8)
    {
        if (_g_thePlayer->GetParentCell())
        {
            FUN_0062f310((int)_g_thePlayer->GetParentCell()->FUN_00547770());
        }
    }

    b9 = false;
    if (apParams->unk0c)
    {
        apParams->unk0c->Process(apParams->unk00, apParams->unk10);
        if (!apParams->unk0c->GetEffectSetting())
        {
            b9 = true;
        }
    }

    if (apParams->unk04)
    {
        this->SpawnWaterSplash((Body_62e970*)apParams->unk04, apParams->unk08->Vf125()->unk08);
        apParams->unk04->SetFlag(0x80, false);
    }

    if (apParams->unk0c)
    {
        apParams->unk00->FUN_0057b0d0(apParams->unk0c, 0);
    }
    apParams->unk00->FUN_0057b240(0);

    b5 = true;
    if (!((EDL_Helper*)apParams->unk00->GetExtraData())->FUN_0042f180())
    {
        NiTMap* map4 = ((EDL_Helper*)apParams->unk00->GetExtraData())->FUN_0042f1d0();
        if (map4)
        {
            void* pos4 = map4->GetFirstPos();
            while (pos4)
            {
                void* val = 0;
                unsigned int keyTmp = 0;
                map4->GetNext(pos4, keyTmp, val);
                if (var_8 != 0 && ((EffectItem*)keyTmp)->unk1c == var_8)
                {
                    b5 = false;
                    break;
                }
            }
        }
    }

    if (b5)
    {
        if (FUN_008c7aa0() && TaskQueueInterface::GetSingleton())
        {
            ((Holder0087b4f0*)TaskQueueInterface::GetSingleton())
                ->FUN_0087b4f0((int)apParams->unk08, (int)apParams->unk00, 0.0f);
        }
        else
        {
            WaterGroupRemovalCall* pWaterSystem7 = (WaterGroupRemovalCall*)FUN_0070ec90((char*)g_TES);
            pWaterSystem7->FUN_004e5df0((TESObjectREFR*)apParams->unk08, (TESObjectREFR*)apParams->unk00, 0.0f);
        }
    }
}

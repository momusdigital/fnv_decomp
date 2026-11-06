
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldairfrictionctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldairfrictionctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int g_012027b8;

// @fnv 0x00c307c0
int* __cdecl FUN_00c307c0()
{
    return &g_012027b8;
}

struct NiPSysModifierFloatCtlr
{
    NiPSysModifierFloatCtlr();
    virtual ~NiPSysModifierFloatCtlr();
    void SetTargetValue(float fValue);
    void GetTargetValue(float& rfValue);
    NiPSysModifierFloatCtlr* m_pkTarget;
    float m_fValue;
};

struct NiPSysAirFieldAirFrictionCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c307d0(float& rfValue);
};

// @fnv 0x00c307d0
void NiPSysAirFieldAirFrictionCtlr::FUN_00c307d0(float& rfValue)
{
    NiPSysModifierFloatCtlr* pTarget = *(NiPSysModifierFloatCtlr**)((char*)this + 0x3c);
    rfValue = *(float*)((char*)pTarget + 0x58);
}

struct StrArr
{
    char _pad[8];
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrow;
};
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    char _pad[8];
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(int);
// @fnv 0x00c30880
void __stdcall FUN_00c30880(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pcStr = _FUN_00a7d330(g_012027b8);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiAlloc = pkStrings->m_usAlloc;
    typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > Arr;
    if (uiSize >= uiAlloc)
    {
        ((Arr*)pkStrings)->SetSize(uiSize + ((Arr*)pkStrings)->m_usGrow);
    }
    ((Arr*)pkStrings)->SetAt(uiSize, pcStr);
}

struct NiObjectNET;
struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
};
struct NiPSysModifier;
struct PsStandIn
{
    NiPSysModifier* FUN_00c1b0f0(void*);
};
struct NiObjectNET : PsStandIn
{
};
struct NiPSysModifier
{
    virtual void v0();
    virtual void v1();
    virtual NiPSysModifier* GetNextModifier();
    NiPSysModifier* next;
};
struct GlobalObjectO2_00a7b610
{
    int unk00;
    int unk04;
};
extern GlobalObjectO2_00a7b610 g_012027a8;
struct FUN_00c306f0_class : BaseStandIn
{
    bool HasModifierAfter(NiObjectNET*);
};
// @fnv 0x00c306f0
bool FUN_00c306f0_class::HasModifierAfter(NiObjectNET* target)
{
    if (!IsTargetParticleSystem(target))
        return false;
    NiPSysModifier* modifier = target->FUN_00c1b0f0((char*)this + 0x38);
    if (!modifier)
        return false;
    NiPSysModifier* item = modifier->GetNextModifier();
    while (item)
    {
        if (item == (NiPSysModifier*)&g_012027a8)
            return true;
        item = item->next;
    }
    return false;
}

struct WorkerTarget
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    float targetValue;
};
struct WorkerAirFriction : NiPSysAirFieldAirFrictionCtlr
{
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    int unk2c, unk30, unk34, unk38;
    WorkerTarget* target;
    void __thiscall SetAirFrictionClamped(volatile float value);
};
// Clamps value to [0,1] and stores it in target->targetValue.
// @fnv 0x00c307e0
void WorkerAirFriction::SetAirFrictionClamped(float value)
{
    WorkerTarget* pTarget = target;
    float clamped = value;
    if (0.0 > clamped)
        clamped = 0.0f;
    if (1.0 < clamped)
        clamped = 1.0f;
    pTarget->targetValue = clamped;
}

extern "C" char g_010c06e4;

void* __cdecl FUN_00aa13e0(unsigned int size);

class SpawnedObject
{
  public:
    void* m_vtbl;
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

    void FUN_00c32d80();
};

class FUN_00c30830_cls
{
  public:
    void FUN_00c32de0(SpawnedObject* obj, unsigned int arg);
    SpawnedObject* CreateSpawnedObject(unsigned int arg);
};

// Allocates a 0x40-byte SpawnedObject, initialises it, passes it to FUN_00c32de0 with arg, and returns it.
// @fnv 0x00c30830
SpawnedObject* FUN_00c30830_cls::CreateSpawnedObject(unsigned int arg)
{
    SpawnedObject* obj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        obj->FUN_00c32d80();
        obj->m_vtbl = (void*)&g_010c06e4;
    }
    else
    {
        obj = 0;
    }
    this->FUN_00c32de0(obj, arg);
    return obj;
}

struct NiPSysModifierCtlr;
struct NiStream;

void __cdecl LoadBinaryWithVersionCheck(NiPSysModifierCtlr*, int, NiStream&);

// @fnv 0x00c29e80
void __cdecl FUN_00c29e80(NiPSysModifierCtlr* a1, int a2, NiStream& a3)
{
    LoadBinaryWithVersionCheck(a1, a2, a3);
}

extern "C" void __cdecl FUN_00a44cd0();

// @fnv 0x00c29f80
void __cdecl FUN_00c29f80()
{
    FUN_00a44cd0();
}

void __cdecl FUN_00c32e10();

// @fnv 0x00c2b450
void __cdecl FUN_00c2b450()
{
    FUN_00c32e10();
}

void __cdecl FUN_00a41220();
// @fnv 0x00c2b8a0
void __cdecl FUN_00c2b8a0()
{
    FUN_00a41220();
}

bool __cdecl FUN_00c32df0(int, int);

// @fnv 0x00c2a190
bool __cdecl FUN_00c2a190(int param_1, int param_2)
{
    return FUN_00c32df0(param_1, param_2);
}

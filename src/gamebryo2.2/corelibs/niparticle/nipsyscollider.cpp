// gamebryo2.2/corelibs/niparticle/nipsyscollider.cpp: NiPSysCollider, NiPSysColliderStandin (9 functions)

#include "nipsyscollider_decls.h"

// @fnv 0x00C32840
void NiPSysCollider::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    ReadBinaryValue(stream, m_fBounceFactor);
    char spawn;
    char die;
    ReadBinaryValue(stream, spawn);
    m_bSpawnOnCollision = (spawn != 0);
    ReadBinaryValue(stream, die);
    m_bDieOnCollision = (die != 0);
    stream.ResetStreamState();
    stream.ResetStreamState();
    stream.ResetStreamState();
}

// @fnv 0x00C32580
void NiPSysCollider::ProcessClone(CloningProcess& cloning)
{
    NiObject::ProcessClone(cloning);
    NiObject* clone = 0;
    cloning.GetClone(this, clone);
    NiPSysCollider* collider = static_cast<NiPSysCollider*>(clone);
    if (m_pSpawnModifier)
    {
        if (cloning.GetClone(reinterpret_cast<NiObject*>(m_pSpawnModifier), clone))
            collider->m_pSpawnModifier = reinterpret_cast<NiPSysSpawnModifier*>(clone);
        else
            collider->m_pSpawnModifier = m_pSpawnModifier;
    }
    if (m_pColliderManager)
    {
        if (cloning.GetClone(reinterpret_cast<NiObject*>(m_pColliderManager), clone))
            collider->m_pColliderManager = reinterpret_cast<NiPSysColliderManager*>(clone);
        else
            collider->m_pColliderManager = m_pColliderManager;
    }
    NiPSysCollider* next = m_spNextController.m_pObject;
    if (next)
        next->ProcessClone(cloning);
}

// @fnv 0x00C32610
void NiPSysCollider::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_pSpawnModifier = reinterpret_cast<NiPSysSpawnModifier*>(stream.GetLoadedObject());
    m_pColliderManager = reinterpret_cast<NiPSysColliderManager*>(stream.GetLoadedObject());
    NiPSysCollider* next = static_cast<NiPSysCollider*>(stream.GetLoadedObject());
    NiPSysCollider* old = m_spNextController.m_pObject;
    if (old != next)
    {
        if (old)
            old->DecRefCount();
        m_spNextController.m_pObject = next;
        if (next)
            next->IncRefCount();
    }
}

struct FUN_00c327e0_shell : public NiPSysCollider
{
    void* GetRTTI();
};

extern const char* const g_012026a0_arg1;
// @fnv 0x00c327e0
void* FUN_00c327e0_shell::GetRTTI()
{
    return (void*)&g_012026a0_arg1;
}

struct StrArr
{
    void* vptr;
    void* data;
    unsigned short capacity;
    unsigned short size;
    unsigned short pad;
    unsigned short growth;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

void __stdcall AppendCameraPathEntries(StrArr* arr);
char* __cdecl _FUN_00a7d330(char const* value);
char* __cdecl _FUN_00a7d370(char const* value, bool flag);
char* __cdecl FUN_00a7d550(char const* value, float number);
char* __cdecl FUN_00a7d5a0(char const* value, void* object);
char* __cdecl FUN_00a7d5e0(char const* value, char const* name);

extern const char g_011d1f8c_arg1[];

struct SpawnRef
{
    void* pad0;
    void* pad1;
    char* name;
};

struct VirtualTarget
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24(StrArr* arr)
    {}
};

struct FUN_00c329c0_object
{
    virtual void v00()
    {}

    void* pad;
    float bounce;
    bool spawnOnCollide;
    bool dieOnCollide;
    SpawnRef* spawn;
    void* pad1;
    void* pad2;
    void* pad3;
    void* pad4;
    void* manager;
    VirtualTarget* target;

    void AppendProperties(StrArr* arr);
};

// @fnv 0x00c329c0
void FUN_00c329c0_object::AppendProperties(StrArr* arr)
{
    char* value;
    unsigned int index;
    unsigned int capacity;
    VirtualTarget* target;

    AppendCameraPathEntries(arr);

    value = _FUN_00a7d330(g_012026a0_arg1);
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    value = FUN_00a7d550("Bounce", this->bounce);
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    value = _FUN_00a7d370("Spawn on Collide", this->spawnOnCollide);
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    value = _FUN_00a7d370("Die on Collide", this->dieOnCollide);
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    {
        const char* name = this->spawn ? this->spawn->name : g_011d1f8c_arg1;
        value = FUN_00a7d5e0("Spawn Modifier", name);
    }
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    value = FUN_00a7d5a0("Manager", this->manager);
    index = arr->size;
    capacity = arr->capacity;
    if (index >= capacity)
        arr->SetSize(arr->growth + index);
    arr->SetAt(index, value);

    target = this->target;
    if (target)
        target->f24(arr);
}

struct FUN_00c32450_target
{
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
    virtual unsigned int FUN_00c32450_target_call(float param1, unsigned int param2, unsigned int param3,
                                                  unsigned int param4);
};

struct FUN_00c32450_shell : public NiPSysCollider
{
    unsigned int FUN_00c32450(float param1, unsigned int param2, unsigned int param3, unsigned int param4);
};

// Forwards the four arguments to the collider's m_pObject target and returns its result, or 0 if there is no target or it returns 0.
// @fnv 0x00c32450
unsigned int FUN_00c32450_shell::FUN_00c32450(float param1, unsigned int param2, unsigned int param3,
                                              unsigned int param4)
{
    FUN_00c32450_target* target = reinterpret_cast<FUN_00c32450_target*>(m_spNextController.m_pObject);

    if (target)
    {
        unsigned int result = target->FUN_00c32450_target_call(param1, param2, param3, param4);

        if (result)
            return result;
    }

    return 0;
}

// Stand-ins for the classes the pack header only forward-declares.
// Field offsets follow the offsets used by FUN_00c32490's machine code.

class NiPSysData : public NiObject
{
  public:
    // NiObject supplies virtual slots 0..24 (vtable 0x00..0x64).
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
    virtual void SetParticleCount(unsigned int uiIndex);  // slot 41 -> +0xA4

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiPoint3* m_pkVertex;  // +0x20: per-particle positions
};

class NiPSysSpawnModifier : public NiObject
{
  public:
    // NiObject supplies virtual slots 0..24.
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
    virtual void SpawnChildParticles(float fTime, float fCollisionTime, unsigned int uiIndex,
                                     NiPSysData* pkData);  // slot 41 -> +0xA4
};

class NiPSysColliderManager : public NiObject
{
  public:
    int unk08;
    int unk0C;
    NiPSysData* m_pUserData;  // +0x10
};

struct FUN_00c32490_shell : public NiPSysCollider
{
    void FUN_00c32490(float fTime, NiPSysData* pkData, unsigned int uiIndex);
};

// Writes a vertex position for the particle at uiIndex, runs the spawn modifier when both pointers are set, and calls the data update if a flag is set.
// @fnv 0x00c32490
void FUN_00c32490_shell::FUN_00c32490(float fTime, NiPSysData* pkData, unsigned int uiIndex)
{
    pkData->m_pkVertex[(unsigned short)uiIndex] = m_kCollisionPosition;

    if (m_bSpawnOnCollision && m_pSpawnModifier)
    {
        m_pSpawnModifier->SpawnChildParticles(fTime, m_fSpawnRate, uiIndex, m_pColliderManager->m_pUserData);
    }

    if (m_bDieOnCollision)
    {
        pkData->SetParticleCount(uiIndex);
    }
}

// Stand-in for the particle-system collider that owns the collision list.
// The layout mirrors the game class: the "next" collider pointer sits at +0x28.
class NiPSysColliderStandin
{
  public:
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
    virtual void v021(const char* aName);

    unsigned int m_uiRefCount;
    float m_fBounceFactor;
    bool m_bSpawnOnCollision;
    bool m_bDieOnCollision;
    NiPSysSpawnModifier* m_pSpawnModifier;
    NiPoint3 m_kCollisionPosition;
    float m_fSpawnRate;
    NiPSysColliderManager* m_pColliderManager;
    NiPSysColliderStandin* m_pNext;

    // Implemented elsewhere: tests the collider against the given name.
    bool CheckCollision(const char* aName);

    bool FUN_00c32680(const char* aName);
};

// Calls CheckCollision(aName); if it passes, invokes v021(aName) on m_pNext when present, and returns whether the check passed.
// @fnv 0x00c32680
bool NiPSysColliderStandin::FUN_00c32680(const char* aName)
{
    if (!CheckCollision(aName))
    {
        return false;
    }
    NiPSysColliderStandin* pNext = m_pNext;
    if (pNext)
    {
        pNext->v021(aName);
    }
    return true;
}

class C326B0Object
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual bool IsEqual(C326B0Object* pkObject);

    bool BaseIsEqual(C326B0Object* pkObject);
};

class C326B0Modifier : public C326B0Object
{
  public:
    int unk04;
    float m_fValue;
    bool m_bFlag0;
    bool m_bFlag1;
    short unk0E;
    C326B0Object* m_pkFirst;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    C326B0Object* m_pkSecond;
    C326B0Object* m_pkThird;

    bool FUN_00c326b0(C326B0Object* pkObject);
};

// @fnv 0x00c326b0
bool C326B0Modifier::FUN_00c326b0(C326B0Object* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    C326B0Modifier* pkOther = (C326B0Modifier*)pkObject;

    if (m_fValue != pkOther->m_fValue)
        return false;

    if (m_bFlag0 != pkOther->m_bFlag0 || m_bFlag1 != pkOther->m_bFlag1)
        return false;

    if ((m_pkFirst && !pkOther->m_pkFirst) || (!m_pkFirst && pkOther->m_pkFirst))
        return false;

    if (m_pkFirst && pkOther->m_pkFirst && !m_pkFirst->IsEqual(pkOther->m_pkFirst))
        return false;

    if ((m_pkSecond && !pkOther->m_pkSecond) || (!m_pkSecond && pkOther->m_pkSecond))
        return false;

    if ((m_pkThird && !pkOther->m_pkThird) || (!m_pkThird && pkOther->m_pkThird))
        return false;

    C326B0Object* pkThird = m_pkThird;
    if (pkThird && pkOther->m_pkThird && !pkThird->IsEqual(pkOther->m_pkThird))
        return false;

    return true;
}

extern int DAT_01098ccc;

struct c327f0_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00c327f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    c327f0_Counted* m_pCounted;

    void BaseCleanup();
    FUN_00c327f0_cls* FUN_00c327f0(unsigned char acFlags);
};

// @fnv 0x00c327f0
FUN_00c327f0_cls* FUN_00c327f0_cls::FUN_00c327f0(unsigned char acFlags)
{
    c327f0_Counted* pCounted = *(c327f0_Counted* volatile*)&m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x2c);
    }
    return this;
}

class C32900BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C32900BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C32900BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C32900Object;

class C32900Stream
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
    virtual void SaveLinkID(C32900Object* pkObject);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    C32900BinaryStream* m_pBackingStream;
};

template <class T>
inline void C32900BinaryStreamSave(C32900BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C32900SaveBinary(C32900Stream& kStream, const T& value)
{
    C32900BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class C32900Base
{
  public:
    int unk000;
    int unk004;

    void SaveBinary(C32900Stream& kStream);
};

class C32900Controller : public C32900Base
{
  public:
    int m_iType;
    bool m_bFirst;
    bool m_bSecond;
    C32900Object* m_pkFirst;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    C32900Object* m_pkSecond;
    C32900Object* m_pkThird;

    void FUN_00c32900(C32900Stream& kStream);
};

// SaveBinary
// Saves the base data, type, two flags and the three object link IDs to the stream.
// @fnv 0x00c32900
void C32900Controller::FUN_00c32900(C32900Stream& kStream)
{
    C32900Base::SaveBinary(kStream);
    C32900SaveBinary(kStream, m_iType);
    C32900SaveBinary(kStream, (unsigned char)m_bFirst);
    C32900SaveBinary(kStream, (unsigned char)m_bSecond);
    kStream.SaveLinkID(m_pkFirst);
    kStream.SaveLinkID(m_pkSecond);
    kStream.SaveLinkID(m_pkThird);
}

class FUN_00a5d3a0
{
  public:
    virtual void LoadBinary(NiStream&)
    {}
    virtual void ProcessClone(CloningProcess&)
    {}
    virtual void LinkObject(NiStream&)
    {}
    int m_iRefCount;
    FUN_00a5d3a0();
};

class NiPSysSpawnModifier;
class NiPSysColliderManager;

struct SPn
{
    void* m_p;
    SPn() : m_p(0)
    {}
};
class FUN_00c32780 : public FUN_00a5d3a0
{
  public:
    float m_fBounceFactor;
    bool m_bSpawnOnCollision;
    bool m_bDieOnCollision;
    NiPSysSpawnModifier* m_pSpawnModifier;
    NiPoint3 m_kCollisionPosition;
    float m_fSpawnRate;
    NiPSysColliderManager* m_pColliderManager;
    SPn m_spNextController;

    FUN_00c32780(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod);
};

// @fnv 0x00c32780
FUN_00c32780::FUN_00c32780(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod)
    : m_fBounceFactor(bounce), m_bSpawnOnCollision(spawn), m_bDieOnCollision(die), m_pSpawnModifier(spawnMod),
      m_kCollisionPosition(NiPoint3::ZERO), m_fSpawnRate(0.0f), m_pColliderManager(0)
{}

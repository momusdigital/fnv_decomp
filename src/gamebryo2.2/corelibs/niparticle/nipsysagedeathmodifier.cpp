
// src/gamebryo2.2/corelibs/niparticle/nipsysagedeathmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysagedeathmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;
extern NiRTTI g_01202798;

// @fnv 0x00c2efe0
const NiRTTI* __cdecl FUN_00c2efe0()
{
    return &g_01202798;
}

extern "C" const void* g_012027a0;

// @fnv 0x00c2f3d0
const void* __cdecl FUN_00c2f3d0()
{
    return &g_012027a0;
}

struct NiPSysAirFieldSpreadCtlr
{
    void __thiscall FUN_00c2f3e0(float& fValue);
};

// @fnv 0x00c2f3e0
void __thiscall NiPSysAirFieldSpreadCtlr::FUN_00c2f3e0(float& fValue)
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);
    int* ptr = reinterpret_cast<int*>(*(reinterpret_cast<int*>(base + 0x3c)));
    fValue = *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(ptr) + 0x64);
}

struct NiStream
{
    void* GetLoadedObject();
};

struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};

struct NiPSysSpawnModifier;

struct NiPSysAgeDeathModifier : NiPSysModifier
{
    char _pad[0x18];
    NiPSysSpawnModifier* m_pSpawnModifier;
    void FUN_00c2ef60(NiStream&);
};

// @fnv 0x00c2ef60
void NiPSysAgeDeathModifier::FUN_00c2ef60(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    m_pSpawnModifier = (NiPSysSpawnModifier*)kStream.GetLoadedObject();
}

namespace fnv_00c2eff0 {
void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
struct NiPSysAgeDeathModifier
{
    void* __thiscall Destroy(unsigned int);
};
// Calls FUN_00c31750, then frees this with _delete when flag has bit 0 set, and returns this.
// @fnv 0x00c2eff0
void* __thiscall NiPSysAgeDeathModifier::Destroy(unsigned int flag)
{
    FUN_00c31750();
    if (flag & 1)
        _delete(this, 0x20);
    return this;
}
}  // namespace fnv_00c2eff0

namespace fnv_00c2f1a0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

struct NiPSysModifier
{
    char _pad_00[0x1c];
    void __thiscall ProcessClone(CloningProcess&);
};
struct NiObject
{
    char _pad_00[1];
};
struct NiPSysSpawnModifier
{
    char _pad_00[1];
};
struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93020
{
    bool __thiscall GetAt(char const*, ShaderBufferRecord*&);
};
struct NiPSysAgeDeathModifier : NiPSysModifier
{
    NiPSysSpawnModifier* m_pSpawnModifier;
    void __thiscall FUN_00c2f1a0(CloningProcess&);
};
// Calls the base ProcessClone, looks up the clone in the cloning map, and remaps the spawn modifier pointer to its cloned counterpart.
// @fnv 0x00c2f1a0
void __thiscall NiPSysAgeDeathModifier::FUN_00c2f1a0(CloningProcess& kCloning)
{
    bool bFound;
    NiObject* pkClone;
    NiPSysAgeDeathModifier* pkDest;
    NiPSysModifier::ProcessClone(kCloning);
    pkClone = 0;
    ((NiTStringPointerMap_00e93020*)kCloning.m_pCloneMap)->GetAt((const char*)this, (ShaderBufferRecord*&)pkClone);
    pkDest = (NiPSysAgeDeathModifier*)pkClone;
    if (m_pSpawnModifier)
    {
        bFound = ((NiTStringPointerMap_00e93020*)kCloning.m_pCloneMap)
                     ->GetAt((const char*)m_pSpawnModifier, (ShaderBufferRecord*&)pkClone);
        if (bFound)
        {
            pkDest->m_pSpawnModifier = (NiPSysSpawnModifier*)pkClone;
            return;
        }
        pkDest->m_pSpawnModifier = m_pSpawnModifier;
    }
}
}  // namespace fnv_00c2f1a0

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00c32d80
{
    FUN_00c32d80();
};
extern int DAT_010c03cc;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00c2f3a0
FUN_00c32d80* __cdecl FUN_00c2f3a0()
{
    FUN_00c32d80* p = (FUN_00c32d80*)BSFadeNode::operator new(0x40);
    if (p)
    {
        new (p) FUN_00c32d80();
        *(int*)p = (int)&DAT_010c03cc;
        return p;
    }
    return 0;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct Base00c319e0
{
    void FUN_00c319e0(StrArr*);
};
char* __cdecl FUN_00a7d330(char*);
char* __cdecl FUN_00a7d370(char const*, bool);
char* __cdecl FUN_00a7d5e0(char const*, char const*);
extern char const* const g_011d1f8c_arg1;
struct FUN_00c2f2c0_shell : Base00c319e0
{
    char _pad[0x18];
    bool m_bHasString;
    char* m_pSpawnModifier;
    void GetViewerStrings(StrArr* pkStrings);
};
// @fnv 0x00c2f2c0
void FUN_00c2f2c0_shell::GetViewerStrings(StrArr* pkStrings)
{
    FUN_00c319e0(pkStrings);
    char* pcString = FUN_00a7d330(*(char**)&g_01202798);
    unsigned int uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
    pcString = FUN_00a7d370("Spawn on Death", m_bHasString);
    uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
    char const* pcModifierName =
        m_pSpawnModifier ? *(char const**)((char*)m_pSpawnModifier + 8) : (char const*)&g_011d1f8c_arg1;
    pcString = FUN_00a7d5e0("Spawn Modifier", pcModifierName);
    uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
}

struct NiPSysPositionModifier
{
    NiPSysPositionModifier();
};
struct CloningProcess;
struct NiPSysAgeDeathModifierClone : NiPSysPositionModifier
{
    char _pad[0x18];
    bool m_bHasString;
    NiPSysSpawnModifier* m_pSpawnModifier;
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
    NiPSysAgeDeathModifierClone* CreateClone(CloningProcess& kCloning);
};
extern int DAT_010c0304;
// @fnv 0x00c2f150
NiPSysAgeDeathModifierClone* NiPSysAgeDeathModifierClone::CreateClone(CloningProcess& kCloning)
{
    NiPSysAgeDeathModifierClone* pkObject = (NiPSysAgeDeathModifierClone*)BSFadeNode::operator new(0x20);
    if (pkObject)
    {
        pkObject->NiPSysPositionModifier::NiPSysPositionModifier();
        *reinterpret_cast<void**>(pkObject) = &DAT_010c0304;
        pkObject->m_bHasString = false;
        pkObject->m_pSpawnModifier = 0;
    }
    else
    {
        pkObject = 0;
    }
    CopyMemberData((NiPSysModifier*)pkObject, kCloning);
    pkObject->m_bHasString = m_bHasString;
    return pkObject;
}

class BC2EF80Object
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual bool IsEqual(BC2EF80Object* pkObject);
};

template <class T> class BC2EF80Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!() const
    {
        return m_pObject == 0;
    }

    T* m_pObject;
};

class BC2EF80Modifier : public BC2EF80Object
{
  public:
    bool ModifierIsEqual(BC2EF80Object* pkObject);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BC2EF80Emitter : public BC2EF80Modifier
{
  public:
    bool FUN_00c2ef80(BC2EF80Object* pkObject);

    bool m_bFlag;
    BC2EF80Object* m_pUserData;
};

// @fnv 0x00c2ef80
bool BC2EF80Emitter::FUN_00c2ef80(BC2EF80Object* pkObject)
{
    if (!ModifierIsEqual(pkObject))
        return false;

    BC2EF80Emitter* pkOther = (BC2EF80Emitter*)pkObject;

    if (pkOther->m_bFlag != m_bFlag)
        return false;

    if ((pkOther->m_pUserData && !m_pUserData) || (!pkOther->m_pUserData && m_pUserData))
        return false;

    if (pkOther->m_pUserData && m_pUserData && !pkOther->m_pUserData->IsEqual(m_pUserData))
        return false;

    return true;
}

// Reworked from another contributor's supplied best attempt; credit retained.

struct ParticleInfo
{
    float x, y, z, age, lifespan, lastUpdate, variance;
};
struct ParticleSystem
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void SetParticleCount(unsigned short);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short count;
    unsigned short capacity;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    ParticleInfo* info;
};
struct SpawnModifier
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void SpawnChildParticles(float, float, unsigned short, ParticleSystem*);
};
struct AgeDeath
{
    virtual ~AgeDeath();
    int unk04, unk08, unk0c;
    ParticleSystem* system;
    int unk14;
    bool spawnOnDeath;
    SpawnModifier* spawn;
    void UpdateAges(float time, ParticleSystem* particles);
};
// Advances each particle's age by the elapsed time and removes particles whose age exceeds their lifespan, optionally spawning on death.
// @fnv 0x00c2f010
void AgeDeath::UpdateAges(float time, ParticleSystem* particles)
{
    if (spawnOnDeath && spawn)
    {
        unsigned short info = particles->count;
        while (info > 0)
        {
            unsigned short index = info - 1;
            ParticleInfo* age = &particles->info[index];
            float r;
            r = time - age->lastUpdate + age->age;
            age->age = r;
            if (age->lifespan < r)
            {
                spawn->SpawnChildParticles(time, age->lifespan + time - r, index, system);
                particles->SetParticleCount(index);
            }
            --info;
        }
    }
    else
    {
        unsigned short info = particles->count;
        while (info > 0)
        {
            unsigned short index = info - 1;
            ParticleInfo* age = &particles->info[index];
            float r = time - age->lastUpdate + age->age;
            age->age = r;
            if (r > age->lifespan)
                particles->SetParticleCount(index);
            --info;
        }
    }
}

struct NiBinaryStream_c2f200
{
    void* vtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream_c2f200*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadScalar(void* pvValue, unsigned int uiSize)
    {
        unsigned int uiComponentSize = uiSize;
        m_uiStreamFlags += m_pfnRead(this, pvValue, 1, &uiComponentSize, 1);
    }
};

struct NiStream_c2f200
{
    char pad[0x24c];
    NiBinaryStream_c2f200* m_pUnderlyingStream;
    void ResetStreamState();
};

struct NiPSysModifier_c2f200
{
    char pad[0x18];
    void LoadBinary(NiStream_c2f200& kStream);
};

struct NiPSysAgeDeathModifier_c2f200 : NiPSysModifier_c2f200
{
    bool m_bHasString;
    void FUN_00c2f200(NiStream_c2f200& kStream);
};

// @fnv 0x00c2f200
void NiPSysAgeDeathModifier_c2f200::FUN_00c2f200(NiStream_c2f200& kStream)
{
    NiPSysModifier_c2f200::LoadBinary(kStream);
    unsigned char ucFlag;
    kStream.m_pUnderlyingStream->ReadScalar(&ucFlag, 1);
    m_bHasString = ucFlag != 0;
    kStream.ResetStreamState();
}

struct NiBinaryStream;
typedef unsigned int(__cdecl* BinaryWriteProc)(NiBinaryStream*, const void*, unsigned int, const void*, unsigned int);
struct NiBinaryStream
{
    void* m_pVtbl;
    unsigned int m_uiWriteOffset;
    void* m_pReadProc;
    BinaryWriteProc m_pWriteProc;

    void WriteSpawnFlag(const bool& onDeath)
    {
        unsigned int count = 1;
        unsigned int amount = m_pWriteProc(this, &onDeath, 1, &count, 1);
        m_uiWriteOffset += amount;
    }
};
struct NiPSysModifierSaveBase
{
    void FUN_00c31950(NiStream* stream);
};
struct FUN_00c2f260_shell
{
    void SaveAgeDeathModifier(NiStream* stream);
};
// Calls the base modifier save, writes the spawn-on-death flag to the stream's binary output, then writes the spawn modifier link.
// @fnv 0x00c2f260
void FUN_00c2f260_shell::SaveAgeDeathModifier(NiStream* stream)
{
    reinterpret_cast<NiPSysModifierSaveBase*>(this)->FUN_00c31950(stream);
    NiPSysAgeDeathModifierClone* modifier = reinterpret_cast<NiPSysAgeDeathModifierClone*>(this);
    bool spawnOnDeath = modifier->m_bHasString;
    NiBinaryStream* output = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x250);
    output->WriteSpawnFlag(spawnOnDeath);
    typedef void(__thiscall * WriteLinkProc)(NiStream*, NiPSysSpawnModifier*);
    WriteLinkProc* pVtbl = *reinterpret_cast<WriteLinkProc**>(stream);
    pVtbl[12](stream, modifier->m_pSpawnModifier);
}

struct FUN_00c2f3f0Target
{
    char _pad[0x64];
    float unk64;
};

struct NiPSysSpawnModifier
{
    char _pad[0x3c];
    FUN_00c2f3f0Target* unk3c;
    void __thiscall FUN_00c2f3f0(float fValue);
};

double g_01012060 = 0.0;
double g_01012070 = 1.0;

// Clamps fValue to [0,1] and stores it into the target's unk64 field.
// @fnv 0x00c2f3f0
void __thiscall NiPSysSpawnModifier::FUN_00c2f3f0(float fValue)
{
    FUN_00c2f3f0Target* target = this->unk3c;
    float fClamped = fValue;

    if (fClamped < g_01012060)
    {
        fClamped = 0.0f;
    }
    if (fClamped > g_01012070)
    {
        fClamped = 1.0f;
    }

    target->unk64 = fClamped;
}

void* __cdecl FUN_00aa13e0(unsigned int size);
struct Host2f440
{
    void FUN_00c32de0(FUN_00c32d80* obj, int arg);
    FUN_00c32d80* CreateAndInit(int arg);
};
// Allocates a 0x40-byte object, constructs it with a vtable, initializes it via FUN_00c32de0 with arg, and returns it (or null on allocation failure).
// @fnv 0x00c2f440
FUN_00c32d80* Host2f440::CreateAndInit(int arg)
{
    FUN_00c32d80* p = (FUN_00c32d80*)FUN_00aa13e0(0x40);
    if (p)
    {
        new (p) FUN_00c32d80;
        *(int**)p = &DAT_010c03cc;
    }
    else
    {
        p = 0;
    }
    FUN_00c32de0(p, arg);
    return p;
}

void __cdecl FUN_00c31670();

// @fnv 0x00c28b60
void __cdecl FUN_00c28b60()
{
    FUN_00c31670();
}

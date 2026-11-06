
// src/gamebryo2.2/corelibs/niparticle/nimeshparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nimeshparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202538;

// @fnv 0x00c21e10
void* __cdecl FUN_00c21e10()
{
    return &g_01202538;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void __thiscall FUN_00c1b5c0();
};
extern int DAT_010bdd84;
// @fnv 0x00c21e90
void* __cdecl FUN_00c21e90()
{
    void* p = BSFadeNode::operator new(0x118);
    if (p)
    {
        ((BSFadeNode*)p)->FUN_00c1b5c0();
        *(float*)((char*)p + 0x110) = 0.0f;
        *(void**)((char*)p + 0) = &DAT_010bdd84;
        *(char*)((char*)p + 0x114) = 1;
        return p;
    }
    return 0;
}

struct NiUpdateData
{
    float fTime;
    char _pad04;
    bool m_bRender;
    bool m_bInterpolate;
};
struct NiParticleSystem
{
    char _pad00[0x110];
    void __thiscall UpdateParticleSystem(NiUpdateData&, unsigned int);
};
struct NiMeshParticleSystem : NiParticleSystem
{
    float m_f110;
    void __thiscall FUN_00c21910(NiUpdateData&, unsigned int);
};
// @fnv 0x00c21910
void __thiscall NiMeshParticleSystem::FUN_00c21910(NiUpdateData& UpdateData, unsigned int uFlags)
{
    if (UpdateData.m_bRender)
    {
        UpdateData.m_bInterpolate = true;
        return;
    }
    UpdateParticleSystem(UpdateData, uFlags);
    m_f110 = UpdateData.fTime;
}

namespace fnv_00c21b60 {
class NiPropertyState
{
  public:
    int m_spProperties[7];
};
class NiGeometry
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
};
class NiMeshPSysData
{
  public:
    char _pad[0x7c];
    NiGeometry* m_pMeshNode;
};
class NiMeshParticleSystem : public NiGeometry
{
  public:
    char _pad1[0x98];
    NiPropertyState _st;
    NiMeshPSysData* _pk;
    void __thiscall UpdatePropertiesDownward(NiPropertyState* pkParentState);
};
// @fnv 0x00c21b60
void __thiscall NiMeshParticleSystem::UpdatePropertiesDownward(NiPropertyState* pkParentState)
{
    NiGeometry::UpdatePropertiesDownwardPass(pkParentState);
    _pk->m_pMeshNode->UpdatePropertiesDownwardPass(&_st);
}
}  // namespace fnv_00c21b60

namespace fnv_00c21bb0 {
struct NiParticleSystem
{
    void __thiscall SetSelectiveUpdateFlags(bool&, bool, bool&);
    char _pad[0xB8];
};
struct NiNode
{
    virtual void _V00();
    virtual void _V01();
    virtual void _V02();
    virtual void _V03();
    virtual void _V04();
    virtual void _V05();
    virtual void _V06();
    virtual void _V07();
    virtual void _V08();
    virtual void _V09();
    virtual void _V10();
    virtual void _V11();
    virtual void _V12();
    virtual void _V13();
    virtual void _V14();
    virtual void _V15();
    virtual void _V16();
    virtual void _V17();
    virtual void _V18();
    virtual void _V19();
    virtual void _V20();
    virtual void _V21();
    virtual void _V22();
    virtual void _V23();
    virtual void _V24();
    virtual void _V25();
    virtual void _V26();
    virtual void _V27();
    virtual void _V28();
    virtual void _V29();
    virtual void _V30();
    virtual void _V31();
    virtual void _V32();
    virtual void _V33();
    virtual void _V34();
    virtual void _V35();
    virtual void _V36();
    virtual void _V37();
    virtual void _V38();
    virtual void _V39();
    virtual void V_at_A0(bool&, bool, bool&);
    char _pad2[0x2C];
    int m_flags;
};
struct NiMeshPSysData
{
    char _pad[0x7C];
    NiNode* m_pMeshNode;
};
struct NiMeshParticleSystem : NiParticleSystem
{
    NiMeshPSysData* m_pUserData;
    void __thiscall UpdateSelective(bool&, bool, bool&);
};
// @fnv 0x00c21bb0
void __thiscall NiMeshParticleSystem::UpdateSelective(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                      bool& bRigid)
{
    NiParticleSystem::SetSelectiveUpdateFlags(bSelectiveUpdate, true, bRigid);
    NiMeshPSysData* pkData = m_pUserData;
    pkData->m_pMeshNode->V_at_A0(bSelectiveUpdate, true, bRigid);
    bRigid = false;
    pkData->m_pMeshNode->m_flags &= ~0x10;
}
}  // namespace fnv_00c21bb0

namespace fnv_00c21dc0 {
struct StrArr
{
    int _0;
    int _1;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
char* __cdecl _FUN_00a7d330(void*);
struct NiParticleSystem
{
    void __thiscall WriteParticleSystemInfo(StrArr*);
};
struct NiMeshParticleSystem : NiParticleSystem
{
    void __thiscall AppendString(StrArr*);
};
// Calls the base particle system handler, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it if full.
// @fnv 0x00c21dc0
void __thiscall NiMeshParticleSystem::AppendString(StrArr* pkStrings)
{
    NiParticleSystem::WriteParticleSystemInfo(pkStrings);
    char* pcString = _FUN_00a7d330(g_01202538);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcString);
}
}  // namespace fnv_00c21dc0

namespace fnv_00c21ed0 {
struct NiTPointerListBase
{
    void __thiscall RemoveAll();
};
void __cdecl _delete(void*, unsigned int);
struct NiMeshParticleSystem
{
    char _pad[0xC8];
    NiTPointerListBase m_kNode;
    void __thiscall FUN_00a80580();
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00c21ed0
void* __thiscall NiMeshParticleSystem::Destroy(unsigned int flags)
{
    m_kNode.RemoveAll();
    this->FUN_00a80580();
    if (flags & 1)
        _delete(this, 0x118);
    return this;
}
}  // namespace fnv_00c21ed0

namespace fnv_00c26350 {
struct RgbaColor
{
    float r, g, b, a;
};
extern RgbaColor DAT_011a9be0;
struct NiMeshParticleSystem
{
    RgbaColor* __thiscall GetParticleColor(unsigned short, unsigned short);
};
// @fnv 0x00c26350
RgbaColor* __thiscall NiMeshParticleSystem::GetParticleColor(unsigned short ausBlockIndex, unsigned short ausColorIndex)
{
    if (*(int*)((char*)this + 0x28))
    {
        unsigned int v1 = ausBlockIndex;
        unsigned int v2 = ausColorIndex;
        char* base = *(char**)((char*)this + 0x7c);
        v1 <<= 5;
        v2 *= 0x84;
        char* ptr = *(char**)(v1 + base);
        return (RgbaColor*)(ptr + v2 + 0x6c);
    }
    return &DAT_011a9be0;
}
}  // namespace fnv_00c26350

struct CloningProcess;
struct NiMeshParticleSystemClone : NiMeshParticleSystem
{
    static void* __cdecl operator new(unsigned int);
    void __thiscall FUN_00c1b6f0(NiMeshParticleSystemClone*, CloningProcess&);
    NiMeshParticleSystemClone* __thiscall CreateClone(CloningProcess&);
    char _pad114[4];
};
// Allocates and constructs a NiMeshParticleSystemClone, copies m_f110 and the byte at offset 0x114 from this, and returns it.
// @fnv 0x00c21e20
NiMeshParticleSystemClone* __thiscall NiMeshParticleSystemClone::CreateClone(CloningProcess& process)
{
    NiMeshParticleSystemClone* result = new NiMeshParticleSystemClone;
    if (result)
    {
        ((BSFadeNode*)result)->FUN_00c1b5c0();
        result->m_f110 = 0.0f;
        *(unsigned int*)result = (unsigned int)&DAT_010bdd84;
        *(unsigned char*)((char*)result + 0x114) = 1;
    }
    else
        result = 0;
    FUN_00c1b6f0(result, process);
    result->m_f110 = m_f110;
    *(unsigned char*)((char*)result + 0x114) = *(unsigned char*)((char*)this + 0x114);
    return result;
}

struct NiStream
{
    char _pad00[0x08];
    char m_acObjectName[0xD8];
    char m_acInputFilePath[260];
};

int __cdecl _NiStricmp(const char* string1, const char* string2);
int __cdecl sprintf(char* buffer, const char* format, ...);
extern void(__cdecl* DAT_011ac2ac)(char* buffer, const char* message, int value);

struct FUN_00c21960_shell
{
    void __thiscall CheckUnsupportedMeshParticle(NiStream& stream);
    void __thiscall LoadBinary(NiStream& stream);
};

// @fnv 0x00c21960
void __thiscall FUN_00c21960_shell::CheckUnsupportedMeshParticle(NiStream& stream)
{
    const char* pname = stream.m_acInputFilePath;
    bool bWarn = true;
    char* pdude;
    char acMessage[260];

    if (pname)
    {
        if (_NiStricmp(pname, "Meshes\\Sky\\RainHeavy.NIF") == 0)
        {
            bWarn = false;
        }
        else if (_NiStricmp(pname, "Meshes\\Sky\\RainLight.NIF") == 0)
        {
            bWarn = false;
        }
    }

    if (bWarn)
    {
        pdude = stream.m_acObjectName;
        if (!pdude[0])
        {
            pdude = "Please";
        }

        sprintf(acMessage, "File %s contains a mesh particle system! %s remove it.", pname, pdude);

        if (DAT_011ac2ac)
        {
            DAT_011ac2ac(acMessage, "Unsupported Object", 0);
        }
    }

    LoadBinary(stream);
}

class C21A10Object
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
    virtual void Apply(void* pvArg);
};

struct C21A10Group
{
    int unk00;
    C21A10Object** m_ppGeometries;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

class C21A10Owner
{
  public:
    int unk000;
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
    C21A10Group** m_ppkGroups;
    unsigned short m_usMaxGroups;
    unsigned short m_usGroups;

    void ApplyToAllObjects(void* pvArg);
};

// Iterates every group and its objects, calling Apply(pvArg) on each non-null object.
// @fnv 0x00c21a10
void C21A10Owner::ApplyToAllObjects(void* pvArg)
{
    unsigned int uiGroups = m_usGroups;
    for (unsigned int i = 0; i < uiGroups; i++)
    {
        C21A10Group* pkGroup = m_ppkGroups[i];
        if (pkGroup)
        {
            unsigned int uiObjects = pkGroup->m_usSize;
            for (unsigned int j = 0; j < uiObjects; j++)
            {
                C21A10Object* pkObject = pkGroup->m_ppGeometries[j];
                if (pkObject)
                    pkObject->Apply(pvArg);
            }
        }
    }
}

struct Inner
{
    virtual void u00();
    virtual void u01();
    virtual void u02();
    virtual void u03();
    virtual void u04();
    virtual void u05();
    virtual void u06();
    virtual void u07();
    virtual void u08();
    virtual void u09();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void Tail(int a);
};

struct Mid
{
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    Inner* m_7C;
};

struct FUN_00c21b90_cls
{
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    Mid* m_B8;
    void __thiscall TailViaMid(int a);
};

// @fnv 0x00c21b90
void FUN_00c21b90_cls::TailViaMid(int aiValue)
{
    m_B8->m_7C->Tail(aiValue);
}

struct FUN_00c21c60_src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    float m_0c;
};
extern FUN_00c21c60_src DAT_011f4288;
struct FUN_00c21c60_y
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00c21c60_src* m_20;
};
struct FUN_00c21c60_x
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    FUN_00c21c60_y* m_7c;
};
struct FUN_00c21c60_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00c21c60_src* m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    FUN_00c21c60_x* m_b8;
    void Refresh();
    void CopySourceToOutput();
};
// Calls Refresh, then copies m_00, m_04, m_08 and m_0c from the source record (or DAT_011f4288 if null) into m_20.
// @fnv 0x00c21c60
void FUN_00c21c60_cls::CopySourceToOutput()
{
    Refresh();
    FUN_00c21c60_y* y = m_b8->m_7c;
    FUN_00c21c60_src* pSource = y->m_20 != 0 ? y->m_20 : &DAT_011f4288;
    unsigned int a = pSource->m_00;
    volatile float fValue = pSource->m_0c;
    FUN_00c21c60_src* pOutput = m_20;
    pOutput->m_00 = a;
    pOutput->m_04 = pSource->m_04;
    unsigned int uiData = pSource->m_08;
    pOutput->m_0c = fValue;
    pOutput->m_08 = uiData;
}

struct NiRTTI
{
    const char* name;
    const NiRTTI* parent;
};
extern "C" NiRTTI DAT_01202500;
extern "C" NiRTTI DAT_01202530;
struct NiObject
{
    const NiRTTI* QueryRTTI()
    {
        typedef const NiRTTI*(__thiscall * Fn)(NiObject*);
        return ((Fn*)*(void***)this)[2](this);
    }
    void Update(unsigned int value)
    {
        typedef void(__thiscall * Fn)(NiObject*, unsigned int);
        ((Fn*)*(void***)this)[54](this, value);
    }
    unsigned short MeshChildCount() const
    {
        return *(const unsigned short*)((const char*)this + 0x60);
    }
    unsigned short ChildCount() const
    {
        return *(const unsigned short*)((const char*)this + 0x22);
    }
    NiObject** MeshChildren() const
    {
        return *(NiObject * * const*)((const char*)this + 0x58);
    }
    NiObject** Children() const
    {
        return *(NiObject * * const*)((const char*)this + 0x1c);
    }
    void __thiscall ApplyToAllObjects(unsigned int);
    void __thiscall PurgeRendererData(unsigned int);
    void __thiscall FUN_00c21cb0(unsigned int);
};
struct NiObjectNode
{
    NiObjectNode* next;
    NiObjectNode* previous;
    NiObject* object;
    static NiObject*& GetNext(NiObjectNode*& it)
    {
        NiObject*& result = it->object;
        it = it->next;
        return result;
    }
};
// @fnv 0x00c21cb0
void __thiscall NiObject::FUN_00c21cb0(unsigned int value)
{
    PurgeRendererData(value);
    NiObject* pLinkedObject = *(NiObject**)((char*)this + 0xb8);
    if (pLinkedObject)
    {
        NiObject* child = *(NiObject**)((char*)pLinkedObject + 0x7c);
        if (child)
            child->Update(value);
        pLinkedObject->ApplyToAllObjects(value);
    }
    for (NiObjectNode* node = *(NiObjectNode**)((char*)this + 0xc8); node;)
    {
        NiObject* object = NiObjectNode::GetNext(node);
        if (!object)
            continue;
        for (const NiRTTI* type = object->QueryRTTI(); type; type = type->parent)
        {
            if (type == &DAT_01202500)
            {
                unsigned int count = object->MeshChildCount();
                for (unsigned int i = 0; i < count; ++i)
                {
                    if (i < object->MeshChildCount())
                    {
                        NiObject* child = object->MeshChildren()[i];
                        if (child)
                            child->Update(value);
                    }
                }
                goto next_object;
            }
        }
        for (const NiRTTI* type = object->QueryRTTI(); type; type = type->parent)
        {
            if (type == &DAT_01202530)
            {
                unsigned int count = object->ChildCount();
                for (unsigned int i = 0; i < count; ++i)
                {
                    if (i < object->ChildCount())
                    {
                        NiObject* child = object->Children()[i];
                        if (child)
                            child->Update(value);
                    }
                }
                goto next_object;
            }
        }
    next_object:;
    }
}

// Particle system constructor: defaults with the last-update time marked invalid.

static const float NI_INFINITY = 3.402823466e+38f;
static const float INVALID_FLOAT = -NI_INFINITY;

class C1B5C0Base
{
  public:
    C1B5C0Base();
    virtual ~C1B5C0Base();
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
};

struct C1B5C0SystemList
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;

    C1B5C0SystemList()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
};

class FUN_00c1b5c0 : public C1B5C0Base
{
  public:
    FUN_00c1b5c0();
    virtual ~FUN_00c1b5c0();

    bool m_bPreSystemsFlag;
    C1B5C0SystemList m_kSystems;
    float m_fLastTime;
    bool m_bIsUpdating;
    bool m_bNeedsUpdate;
};

// @fnv 0x00c1b5c0
FUN_00c1b5c0::FUN_00c1b5c0() : m_bPreSystemsFlag(true)
{
    m_fLastTime = INVALID_FLOAT;
    m_bIsUpdating = false;
    m_bNeedsUpdate = false;
}

extern "C" int DAT_01202690;
struct FUN_00c21a80_obj;
struct FUN_00c21a80_entry
{
    unsigned int unk00;
    FUN_00c21a80_entry* m_pNext;
};
struct FUN_00c21a80_node
{
    FUN_00c21a80_node* m_pNext;
    unsigned int unk04;
    FUN_00c21a80_obj* m_pInventoryEntryData;
};
struct FUN_00c21a80_obj
{
    virtual void v00();
    virtual void v01();
    virtual void* v02();
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
    virtual void v36(NiUpdateData&);
    virtual void v37(NiUpdateData&);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(NiUpdateData&);
    virtual void v47();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    FUN_00c21a80_obj* m_pNext30;
};
struct FUN_00c21a80_cls
{
    virtual void v00();
    virtual void v01();
    virtual void* v02();
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
    virtual void v36(NiUpdateData&);
    virtual void v37(NiUpdateData&);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(NiUpdateData&);
    virtual void v47();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00c21a80_obj* m_pList0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_00c21a80_node* m_pList24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    float m_f110;
    char m_b114;
    void __thiscall UpdateDownwardPass(NiUpdateData&, unsigned int);
};
// Runs update callbacks over the node and object lists, defers the found object's v37, then stores the update time and flag.
// @fnv 0x00c21a80
void FUN_00c21a80_cls::UpdateDownwardPass(NiUpdateData& aUpdateData, unsigned int arg2)
{
    if (aUpdateData.m_bRender)
    {
        aUpdateData.m_bInterpolate = true;
        return;
    }
    FUN_00c21a80_obj* pDeferredObj = 0;
    if (aUpdateData._pad04 != 0)
    {
        FUN_00c21a80_node* node = m_pList24;
        while (node)
        {
            FUN_00c21a80_obj*& ref = node->m_pInventoryEntryData;
            node = node->m_pNext;
            if (ref && ref->m_0c != 0)
            {
                ref->v36(aUpdateData);
            }
        }
        FUN_00c21a80_obj* obj = (FUN_00c21a80_obj*)m_pList0C;
        while (obj)
        {
            FUN_00c21a80_entry* pEntry = (FUN_00c21a80_entry*)obj->v02();
            if (pEntry)
            {
                do
                {
                    if ((void*)pEntry == (void*)&DAT_01202690)
                    {
                        pDeferredObj = obj;
                        goto next;
                    }
                    pEntry = pEntry->m_pNext;
                } while (pEntry);
            }
            obj->v37(aUpdateData);
        next:
            obj = obj->m_pNext30;
        }
        v46(aUpdateData);
        if (pDeferredObj)
            pDeferredObj->v37(aUpdateData);
    }
    else
    {
        v46(aUpdateData);
    }
    v47();
    m_f110 = aUpdateData.fTime;
    m_b114 = aUpdateData._pad04;
}

extern "C" __declspec(noreturn) void __cdecl FUN_00c1ad80();

// @fnv 0x00c21900
__declspec(noreturn) void __cdecl FUN_00c21900()
{
    FUN_00c1ad80();
}

#include <math.h>
struct Xf36
{
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20;
};

struct Ps21Target
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e(unsigned int a1);
    char _pad04[0x30];
    Xf36 m_34;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    float m_64;
};

struct Ps21Owner
{
    char _pad00[0x7c];
    Ps21Target* m_7c;
};

struct Ps21Node
{
    char _pad00[0x68];
    Xf36 m_68;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    float m_98;
    char _pad9c[0x1c];
    Ps21Owner* m_b8;

    void UpdateWorldData(unsigned int a1);
    void CopyFromNode(unsigned int a1);
};

// Copies several fields and the absolute value of m_98 to the owner's target, then calls its virtual method.
// @fnv 0x00c21bf0
void Ps21Node::CopyFromNode(unsigned int a1)
{
    UpdateWorldData(a1);
    Ps21Owner* owner = m_b8;
    owner->m_7c->m_34 = m_68;
    Ps21Target* y = owner->m_7c;
    unsigned int* p = &y->m_58;
    *p = m_8c;
    p[1] = m_90;
    p[2] = m_94;
    float fAbsValue = (float)fabs(m_98);
    Ps21Target* z = owner->m_7c;
    z->m_64 = fAbsValue;
    z->v2e(a1);
}


// Gamebryo 2.2 NiMain: NiParticleMeshes. PC build's default constructor only
// constructs the NiParticles base and installs the NiParticleMeshes vtable.
// NiParticles is declared here with the interface this translation unit needs;
// its constructor and vtable live in their own NiMain units.

class NiRTTI;

class NiParticles
{
  public:
    NiParticles();
    virtual ~NiParticles();
    virtual const NiRTTI* GetRTTI() const;
};

class NiParticleMeshes : public NiParticles
{
  public:
    NiParticleMeshes();
    virtual ~NiParticleMeshes();
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x00a9b120
NiParticleMeshes::NiParticleMeshes()
{}

struct FUN_00a98ec0_shell : public NiParticleMeshes
{
    void* FUN_00a98ec0();
};

extern NiRTTI* g_011f5f14;

// @fnv 0x00a98ec0
void* FUN_00a98ec0_shell::FUN_00a98ec0()
{
    return &g_011f5f14;
}

extern void __cdecl FUN_00a80580();
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00a98ed0_shell : public NiParticleMeshes
{
    void* FUN_00a98ed0(unsigned int flags);
};

// Calls FUN_00a80580, then deletes this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a98ed0
void* FUN_00a98ed0_shell::FUN_00a98ed0(unsigned int flags)
{
    NiParticleMeshes* p = this;
    FUN_00a80580();
    if (flags & 1)
        _delete(p, 0xcc);
    return p;
}

class NiRenderer;
class NiParticleMeshesData;
struct HackBase
{
    void PurgeRendererData(NiRenderer*);
};
struct FUN_00a99090_shell : public NiParticleMeshes
{
    void PurgeRendererData(NiRenderer* pkRenderer);
};
// @fnv 0x00a99090
void FUN_00a99090_shell::PurgeRendererData(NiRenderer* pkRenderer)
{
    ((HackBase*)this)->PurgeRendererData(pkRenderer);
    NiParticleMeshesData* pkPMData = *(NiParticleMeshesData**)((char*)this + 0xb8);
    if (pkPMData)
    {
        void* pkMeshes = *(void**)((char*)pkPMData + 0x70);
        if (pkMeshes)
        {
            typedef void(__thiscall * Fn)(void*, NiRenderer*);
            ((Fn)(*(void***)pkMeshes)[54])(pkMeshes, pkRenderer);
        }
    }
}

template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    T* m_pData;
    unsigned int m_u04;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > StrArr2;
struct Caller
{
    void FUN_00a9b2e0(StrArr2*);
    void AppendString(StrArr2*);
};
char* __cdecl _FUN_00a7d330(const char*);
extern const char* const g_011f5f14_arg1;
// Appends the string returned by _FUN_00a7d330(g_011f5f14_arg1) to pkStrings, growing the array if it is full.
// @fnv 0x00a990c0
void Caller::AppendString(StrArr2* pkStrings)
{
    FUN_00a9b2e0(pkStrings);
    char* psz = _FUN_00a7d330(g_011f5f14_arg1);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMax;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, psz);
}

struct FUN_00a808f0_shell
{
    void UpdateSelectiveUpdateFlags(bool*, bool, bool*);
};
struct NiNode
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
    virtual void SetSelectiveUpdateFlags(bool*, bool, bool*);
};
struct FUN_00a99000_shell
{
    void FUN_00a99000(bool&, bool, bool&);
};
// @fnv 0x00a99000
void FUN_00a99000_shell::FUN_00a99000(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid)
{
    ((FUN_00a808f0_shell*)this)->UpdateSelectiveUpdateFlags(&bSelectiveUpdate, true, &bRigid);
    NiNode* pkParticlesContainer = *(NiNode**)((char*)*(void**)((char*)this + 0xb8) + 0x70);
    pkParticlesContainer->SetSelectiveUpdateFlags(&bSelectiveUpdate, true, &bRigid);
    bRigid = false;
    *(unsigned int*)((char*)pkParticlesContainer + 0x30) &= 0xffffffef;
}

namespace fnv_00a99040 {
struct NiPropertyState
{
    char _pad[28];
};
struct NiGeometry
{
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
};
struct NiNode
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
};
struct StandinNiParticleMeshes : NiGeometry
{
    void UpdatePropertyState(NiPropertyState* pkParentState);
};
// @fnv 0x00a99040
void StandinNiParticleMeshes::UpdatePropertyState(NiPropertyState* pkParentState)
{
    NiGeometry::UpdatePropertiesDownwardPass(pkParentState);
    NiNode* pkParticlesContainer = *(NiNode**)((char*)*(void**)((char*)this + 0xb8) + 0x70);
    pkParticlesContainer->UpdatePropertiesDownwardPass((NiPropertyState*)((char*)this + 0x9c));
}
}  // namespace fnv_00a99040

struct S_00a98e30_Val
{
    float f;
    bool b;
};
struct S_00a98e30
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
    int unkB8;
    int unkBC;
    int unkC0;
    float unkC4;
    bool unkC8;
    void FUN_00a59f90(S_00a98e30_Val* p, int x);
    void UpdateDownwardPass(S_00a98e30_Val* p, int x);
};
// @fnv 0x00a98e30
void S_00a98e30::UpdateDownwardPass(S_00a98e30_Val* apVal, int x)
{
    unkC4 = apVal->f;
    unkC8 = apVal->b;
    FUN_00a59f90(apVal, x);
}

struct S_00a98e50_UpdateData
{
    float m_fTime;
    bool m_bUpdate;
};
struct S_00a98e50_Base
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
    int unkB8;
    int unkBC;
    int unkC0;
    void UpdateDownwardPassIfSelective(S_00a98e50_UpdateData& kData);
};
struct S_00a98e50 : S_00a98e50_Base
{
    float m_fLastTime;
    void FUN_00a98e50(S_00a98e50_UpdateData& kData);
};
// Stores kData.m_fTime into m_fLastTime, then forwards kData to the base UpdateDownwardPassIfSelective.
// @fnv 0x00a98e50
void S_00a98e50::FUN_00a98e50(S_00a98e50_UpdateData& kData)
{
    m_fLastTime = kData.m_fTime;
    S_00a98e50_Base::UpdateDownwardPassIfSelective(kData);
}

struct NiRenderer;
struct RendTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void Render(NiRenderer* pkRenderer);
};
struct MeshesData
{
    char pad[0x70];
    RendTarget* m_pkTarget;
};
struct FUN_00a99070_shell
{
    char pad[0xb8];
    MeshesData* m_pUserData;
    void RenderTarget(NiRenderer* pkRenderer);
};
// @fnv 0x00a99070
void FUN_00a99070_shell::RenderTarget(NiRenderer* pkRenderer)
{
    m_pUserData->m_pkTarget->Render(pkRenderer);
}

extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern const char DAT_010a0a6c;

struct CreatedObj
{
    void FUN_00a9b120();
    const char* m_pTable;
    int unk04[49];
    bool m_bFlag;
};

struct FUN_00a98f00_shell : public NiParticleMeshes
{
    void FUN_00a9b140(CreatedObj* pObj, void* pArg);
    CreatedObj* CreateAndInitObj(void* pArg);
};

// Allocates a 0xcc-byte CreatedObj, initialises it with a table pointer and flag, then passes it to FUN_00a9b140 with pArg and returns it.
// @fnv 0x00a98f00
CreatedObj* FUN_00a98f00_shell::CreateAndInitObj(void* pArg)
{
    CreatedObj* pObj = (CreatedObj*)FUN_00aa13e0(0xcc);
    if (pObj != 0)
    {
        pObj->FUN_00a9b120();
        pObj->m_pTable = &DAT_010a0a6c;
        pObj->m_bFlag = true;
    }
    else
    {
        pObj = 0;
    }
    FUN_00a9b140(pObj, pArg);
    return pObj;
}

#include <math.h>
struct NiUpdateData;

struct A98F60Matrix3
{
    float m_afEntries[3][3];
};

struct A98F60Point3
{
    float x;
    float y;
    float z;
};

inline float A98F60Abs(float f)
{
    return (float)fabs(f);
}

struct A98F60Camera
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4C();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual void vfunc5C();
    virtual void vfunc60();
    virtual void vfunc64();
    virtual void vfunc68();
    virtual void vfunc6C();
    virtual void vfunc70();
    virtual void vfunc74();
    virtual void vfunc78();
    virtual void vfunc7C();
    virtual void vfunc80();
    virtual void vfunc84();
    virtual void vfunc88();
    virtual void vfunc8C();
    virtual void vfunc90();
    virtual void vfunc94();
    virtual void vfunc98();
    virtual void vfunc9C();
    virtual void vfuncA0();
    virtual void Update(NiUpdateData& kData, bool m_bUpdateEnabled);

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
    A98F60Matrix3 m_kWorldRotate;
    A98F60Point3 m_kWorldTranslate;
    float m_fWorldScale;
};

struct A98F60Renderer
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
    A98F60Camera* m_pkAccumulationCamera;
    bool m_bValueAt0C;

    void UpdateParticleMeshes();
};

struct A98F60AVObject
{
    virtual void UpdateWorldData(NiUpdateData& kData);

    void FUN_00a5a040();
    void FUN_00a29680();

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
    A98F60Matrix3 m_kWorldRotate;
    A98F60Point3 m_kWorldTranslate;
    float m_fWorldScale;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    A98F60Renderer* m_pOwnerShader;
};

struct FUN_00a98f60 : A98F60AVObject
{
    virtual void UpdateWorldData(NiUpdateData& kData);
};

// Copies the object's world transform to the accumulation camera, updates particle meshes, and calls two functions when the renderer flag is set.
// @fnv 0x00a98f60
void FUN_00a98f60::UpdateWorldData(NiUpdateData& kData)
{
    A98F60AVObject::UpdateWorldData(kData);
    A98F60Renderer* pkRenderer = m_pOwnerShader;
    A98F60Camera* pkCamera = pkRenderer->m_pkAccumulationCamera;
    pkRenderer->UpdateParticleMeshes();
    pkCamera->m_kWorldRotate = m_kWorldRotate;
    pkCamera->m_kWorldTranslate = m_kWorldTranslate;
    pkCamera->m_fWorldScale = A98F60Abs(m_fWorldScale);
    pkCamera->Update(kData, false);
    if (pkRenderer->m_bValueAt0C)
    {
        FUN_00a5a040();
        FUN_00a29680();
        pkRenderer->m_bValueAt0C = false;
    }
}

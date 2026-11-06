
// src/fallout_shared/sky/atmosphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/sky/atmosphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Atmosphere
{
    void FUN_00633190();
};

void __cdecl _Deallocate(void* p);

struct FUN_00633160_shell : Atmosphere
{
    void* FUN_00633160(unsigned int flags);
};

// @fnv 0x00633160
void* FUN_00633160_shell::FUN_00633160(unsigned int flags)
{
    FUN_00633190();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PathingRefStandIn
{
    void* m_pObject;

    ~PathingRefStandIn();
    void Reset(void* pObject);
};

struct PathingStandInBase
{
    virtual ~PathingStandInBase();

    int unk04;
};

struct FUN_00633190 : PathingStandInBase
{
    PathingRefStandIn m_kRefA;
    PathingRefStandIn m_kRefB;
    PathingRefStandIn m_kRefC;
    PathingRefStandIn m_kRefD;

    virtual ~FUN_00633190();
};

// Destructor that resets the four PathingRefStandIn members (m_kRefB, m_kRefA, m_kRefD, m_kRefC) to null.
// @fnv 0x00633190
FUN_00633190::~FUN_00633190()
{
    m_kRefB.Reset(0);
    m_kRefA.Reset(0);
    m_kRefD.Reset(0);
    m_kRefC.Reset(0);
}

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl AtmoFree(void* pvMem);

struct AtmoObject;

struct AtmoNode
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
    virtual void AttachChildInAvailableSlot(AtmoNode* pkChild, int abFirstAvailableSlot);

    int unk04[0xac / 4 - 1];
    AtmoNode(int iChildren);
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int)
    {
        AtmoFree(pvMem);
    }
    void FUN_004902f0(bool bAppCulled);
    void FUN_00440460(void* pkProperty);
};

template <class T> struct AtmoPtr
{
    T* m_pObject;
    AtmoPtr& FUN_0066b0d0(T* pObject);
    T* FUN_00559450() const;
};

struct AtmoProperty;
struct AtmoPropertyList
{
    void* FUN_0043c490();
};
struct AtmoShaderMgr
{
    AtmoPropertyList* FUN_00558310();
};
AtmoShaderMgr* __cdecl FUN_0045c670();
void __cdecl FUN_00b899a0(AtmoPtr<AtmoNode>* pspNode);
void __cdecl FUN_00b55540(int iUnk, AtmoProperty* pkFog);
void __cdecl FUN_005b5e40(const char* pFormat, ...);
extern unsigned char g_bNoSky_011f941e;
extern char g_kNiNodeRTTI_011f4a40[];
bool __cdecl FUN_0043b300(void* pkRTTI, AtmoObject* pkObject);

struct AtmoObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int IsGeometry();
    AtmoNode* FUN_0045bc00(int iIndex);
};

struct AtmoStream
{
    char unk000[0x5cc];
    AtmoStream();
    ~AtmoStream();
    bool FUN_00c3a8a0(const char* pPath, int iFlags);
};

struct AtmoLoadedModel
{
    int unk00[4];
    AtmoLoadedModel(const char* pPath, AtmoStream* pkStream, int a3, int a4);
    ~AtmoLoadedModel();
    AtmoObject* FUN_0043b230();
};

struct AtmosphereImpl
{
    int unk00;
    AtmoPtr<AtmoNode> m_spRootNode;
    AtmoPtr<AtmoNode> m_spAtmosphere;
    AtmoPtr<AtmoProperty> m_spFog;
    AtmoPtr<AtmoNode> m_spSkyNode;
    AtmoPtr<AtmoNode> m_spSkyShape;

    void CreateSortAdjustNode(AtmoNode* pkRoot);
    void SetAtmosphere(AtmoNode* pkRoot, AtmoProperty* pkFog);
};

// @fnv 0x00633260
void AtmosphereImpl::SetAtmosphere(AtmoNode* pkRoot, AtmoProperty* pkFog)
{
    CreateSortAdjustNode(pkRoot);
    if (!g_bNoSky_011f941e)
    {
        FUN_00b899a0(&m_spSkyShape);
        m_spSkyShape.FUN_00559450()->FUN_004902f0(true);
        m_spSkyShape.FUN_00559450()->FUN_00440460(FUN_0045c670()->FUN_00558310()->FUN_0043c490());
        m_spSkyNode.FUN_0066b0d0(new AtmoNode(0));
        m_spSkyNode.FUN_00559450()->FUN_004902f0(true);
        m_spSkyNode.FUN_00559450()->AttachChildInAvailableSlot(m_spSkyShape.FUN_00559450(), 1);
        m_spRootNode.FUN_00559450()->AttachChildInAvailableSlot(m_spSkyNode.FUN_00559450(), 1);
    }

    AtmoStream kStream;
    if (kStream.FUN_00c3a8a0("Meshes\\Sky\\Atmosphere.nif", 0))
    {
        AtmoLoadedModel kModel_("Meshes\\Sky\\Atmosphere.nif", &kStream, 0, 0);
        AtmoObject* pkFirstVal2 = kModel_.FUN_0043b230();
        AtmoNode* pkMeshRes = 0;
        AtmoObject* pkObjectOut = kModel_.FUN_0043b230();
        if (pkObjectOut)
        {
            if (pkObjectOut->IsGeometry())
                pkMeshRes = pkObjectOut->FUN_0045bc00(0);
            else if (FUN_0043b300(g_kNiNodeRTTI_011f4a40, pkObjectOut))
                pkMeshRes = (AtmoNode*)pkObjectOut;
        }
        if (!pkMeshRes)
        {
            FUN_005b5e40("Cannot load the atmosphere model.");
            return;
        }
        m_spAtmosphere.FUN_0066b0d0(pkMeshRes);
        m_spAtmosphere.FUN_00559450()->FUN_004902f0(true);
        m_spRootNode.FUN_00559450()->AttachChildInAvailableSlot(m_spAtmosphere.FUN_00559450(), 1);
    }
    m_spFog.FUN_0066b0d0(pkFog);
    FUN_00b55540(0, pkFog);
}

namespace fnv_006335d0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3* ScaleTo(NiPoint3* out, float s);
};
struct Param
{
    float a;
    float b;
    float c;
    float d;
    Param* FUN_00414430(float a0, float a1, float a2, float a3);
};
struct NiFrustum
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
};
struct NiCamera
{
    const NiFrustum& GetViewFrustum() const;
};
struct FUN_00507700_cls : NiCamera
{
    void SetMaxFarNearRatio(float f);
};
struct Stub_00a6faf0 : FUN_00507700_cls
{
    void FUN_00a6faf0(NiFrustum* fr);
};
struct BSFaceGenAnimationData : Stub_00a6faf0
{
};
struct Light
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
};
struct FUN_00633bf0_Class
{
    void FUN_00633bf0(const NiPoint3* v);
};
struct FUN_00633c20_Class : FUN_00633bf0_Class
{
    void FUN_00633c20(float a, float b);
};
struct FUN_00633c40_Class : FUN_00633c20_Class
{
    void FUN_00633c40(float a);
};
struct FUN_00633c60_Class : FUN_00633c40_Class
{
    void FUN_00633c60(const NiPoint3& v);
};
struct Fog : FUN_00633c60_Class
{
    void FUN_0049ed90(bool b);
    void FUN_005bf9a0(float a, float b);
    void FUN_005bfbd0(float a);
};
struct Ref
{
    int unk00;
    Fog* FUN_00559450();
};
struct FUN_009a5480_class
{
    float GetFieldE4Float();
};
struct BSMultiBoundRoom : FUN_009a5480_class
{
    void* FUN_006ab360();
};
struct Node : BSMultiBoundRoom
{
    int FUN_00476c90();
    NiPoint3* FUN_00624700();
    NiPoint3* FUN_0050d100();
    NiPoint3* FUN_009c1a50();
    NiPoint3* FUN_005a8080();
    Light* FUN_00923000();
    float GetFieldE8Float();
};
struct Probe
{
    int FUN_008d6f30();
    float FUN_0057b0a0();
};
struct Info
{
    float unk00;
    float unk04;
    float unk08;
};
struct BSFaceGenNiNode
{
    BSFaceGenAnimationData* GetAnimationData();
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
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual float v40();
};
extern Probe* DAT_011dea3c;
extern Param DAT_011ff8e0;
extern Param DAT_011ff8f0;
extern Param DAT_011ff900;
extern unsigned char DAT_011f941e;
extern float DAT_011f9190;
Fog* __cdecl FUN_00b55520(int a0);
void __cdecl FUN_00b55540(int a0, Fog* a1);
BSFaceGenNiNode* __cdecl FUN_0045c670();
void* __fastcall FUN_00558310(BSFaceGenNiNode* w);
Info* __fastcall FUN_0045bb80(void* p);
struct Atm
{
    int unk00;
    int unk04;
    Ref unk08;
    Ref unk0c;
    int unk10;
    int unk14;
    unsigned char unk18;
    void FUN_008d0600(Node* n, float f);
    void UpdateAtmosphere(Node* node, float f);
};
// Updates the atmosphere for a node: refreshes the fog reference, computes fog positions, and syncs the face-gen animation frustum far plane.
// @fnv 0x006335d0
void Atm::UpdateAtmosphere(Node* node, float f)
{
    float len;
    {
        float p3;
        Light* p1;
        {
            BSFaceGenAnimationData* u;
            {
                float farv;
                {
                    NiFrustum tmp;
                    {
                        Param pData;
                        {
                            Param light;
                            Param p0;
                            {
                                Param k;
                                {
                                    Param p4;
                                    Param t;
                                    {
                                        NiPoint3 pNode;

                                        if (!node)
                                            return;
                                        if (FUN_00b55520(0) != unk0c.FUN_00559450())
                                            FUN_00b55540(0, unk0c.FUN_00559450());
                                        FUN_008d0600(node, f);
                                        if (node->FUN_00476c90() == 3 || 2 == node->FUN_00476c90())
                                        {
                                            if (!(unk08.FUN_00559450()))
                                                return;
                                            if (DAT_011dea3c != 0 && DAT_011dea3c->FUN_008d6f30() &&
                                                FUN_0045bb80(FUN_00558310(FUN_0045c670()))->unk08 <
                                                    DAT_011dea3c->FUN_0057b0a0())
                                            {
                                                DAT_011ff8e0 = *pData.FUN_00414430(node->FUN_00624700()->x,
                                                                                   node->FUN_00624700()->y,
                                                                                   node->FUN_00624700()->z, 1.0f);
                                                DAT_011ff8f0 =
                                                    *p0.FUN_00414430(node->FUN_00624700()->x, node->FUN_00624700()->y,
                                                                     node->FUN_00624700()->z, 1.0f);
                                                DAT_011ff900 = *light.FUN_00414430(node->FUN_00624700()->x,
                                                                                   node->FUN_00624700()->y,
                                                                                   node->FUN_00624700()->z, 1.0);
                                            }
                                            else
                                            {
                                                DAT_011ff8e0 =
                                                    *k.FUN_00414430(node->FUN_0050d100()->x, node->FUN_0050d100()->y,
                                                                    node->FUN_0050d100()->z, 1.0);
                                                DAT_011ff8f0 =
                                                    *p4.FUN_00414430(node->FUN_009c1a50()->x, node->FUN_009c1a50()->y,
                                                                     node->FUN_009c1a50()->z, 1.0);
                                                DAT_011ff900 =
                                                    *t.FUN_00414430(node->FUN_005a8080()->x, node->FUN_005a8080()->y,
                                                                    node->FUN_005a8080()->z, 1.0f);
                                            }
                                        }
                                        if (0 != unk0c.FUN_00559450())
                                        {
                                            p1 = node->FUN_00923000();
                                            unk0c.FUN_00559450()->FUN_0049ed90(p1->unk04 > p1->unk00);
                                            if (unk18)
                                            {
                                                unk0c.FUN_00559450()->FUN_005bf9a0(p1->unk00, p1->unk04);
                                                unk0c.FUN_00559450()->FUN_005bfbd0(node->GetFieldE8Float());
                                            }
                                            if (!(DAT_011f941e))
                                            {
                                                p3 = DAT_011f9190 / 3.75f;
                                                unk0c.FUN_00559450()->FUN_00633bf0(
                                                    node->FUN_00624700()->ScaleTo(&pNode, p3));
                                            }
                                            else
                                            {
                                                unk0c.FUN_00559450()->FUN_00633bf0(node->FUN_00624700());
                                            }
                                            len = node->GetFieldE4Float();
                                            unk0c.FUN_00559450()->FUN_00633c40(node->GetFieldE4Float());
                                            unk0c.FUN_00559450()->FUN_00633c20(p1->unk08, p1->unk0c);
                                            unk0c.FUN_00559450()->FUN_00633c60(*(NiPoint3*)node->FUN_006ab360());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (unk18)
                    {
                        u = 0;
                        farv = FUN_0045c670()->v40();
                        u = FUN_0045c670()->GetAnimationData();
                        if (0 != u)
                        {
                            tmp = u->GetViewFrustum();
                            if (farv != tmp.unk14)
                            {
                                tmp.unk14 = farv;
                                u->SetMaxFarNearRatio(farv / tmp.unk10);
                                u->FUN_00a6faf0(&tmp);
                            }
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_006335d0

struct FUN_00633cc0_SkyObject
{
    FUN_00633cc0_SkyObject();
    ~FUN_00633cc0_SkyObject();
    virtual void vf();
};

struct FUN_00633cc0_ElemA
{
    void* m_pObject;
    FUN_00633cc0_ElemA();
    ~FUN_00633cc0_ElemA();
};

struct FUN_00633cc0_ElemB
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00633cc0_ElemB();
};

struct FUN_00633cc0 : FUN_00633cc0_SkyObject
{
    int unk04;
    FUN_00633cc0_ElemA m_kPointA[4];
    FUN_00633cc0_ElemA m_kPointB[4];
    FUN_00633cc0_ElemB m_iThirdValue[4];
    unsigned short m_58;
    unsigned char m_5a;

    void FUN_00633d90();
    void ClearTransTextures();
    FUN_00633cc0();
    virtual void vf();
};

// Initializes the object: clears m_58, calls FUN_00633d90 and ClearTransTextures, then sets m_5a to 0.
// @fnv 0x00633cc0
FUN_00633cc0::FUN_00633cc0() : m_58(0)
{
    FUN_00633d90();
    ClearTransTextures();
    m_5a = 0;
}

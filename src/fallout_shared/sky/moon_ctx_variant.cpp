
// moon_ctx_variant.cpp: context variant of src/fallout_shared/sky/moon.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "moon_types.h"

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
    void IncRefCount();
    void DecRefCount();
    unsigned int refCount;
};
namespace stand {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
}

class NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
};
class ImageSpaceEffectParam
{
  public:
    float r, g, b, a;
    ImageSpaceEffectParam();
    ImageSpaceEffectParam(float, float, float, float);
};
class NiTexture : public NiObject
{
};
class SkyShaderProperty
{
  public:
    void SetTexture(NiTexture*);
};
class NiTriShape : public NiObject
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, NiPoint2*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
    void FUN_004902f0(bool);
    void AttachProperty(NiObject*);
    SkyShaderProperty* GetProperty(unsigned int);
    void SetDisplayObject(bool);
    void FUN_004bc1f0(float, float, float);
    void FUN_0043fa80(const void*);
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
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char unk4c, unk4d, unk4e, unk4f;
    unsigned char unk50, unk51, unk52, unk53;
    unsigned char unk54, unk55, unk56, unk57;
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned char unkb0, unkb1, unkb2, unkb3;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
};
class NiNode : public NiMemObject
{
  public:
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Vfn10();
    virtual void Vfn14();
    virtual void Vfn18();
    virtual void Vfn1C();
    virtual void Vfn20();
    virtual void Vfn24();
    virtual void Vfn28();
    virtual void Vfn2C();
    virtual void Vfn30();
    virtual void Vfn34();
    virtual void Vfn38();
    virtual void Vfn3C();
    virtual void Vfn40();
    virtual void Vfn44();
    virtual void Vfn48();
    virtual void Vfn4C();
    virtual void Vfn50();
    virtual void Vfn54();
    virtual void Vfn58();
    virtual void Vfn5C();
    virtual void Vfn60();
    virtual void Vfn64();
    virtual void Vfn68();
    virtual void Vfn6C();
    virtual void Vfn70();
    virtual void Vfn74();
    virtual void Vfn78();
    virtual void Vfn7C();
    virtual void Vfn80();
    virtual void Vfn84();
    virtual void Vfn88();
    virtual void Vfn8C();
    virtual void Vfn90();
    virtual void Vfn94();
    virtual void Vfn98();
    virtual void Vfn9C();
    virtual void VfnA0();
    virtual void VfnA4();
    virtual void VfnA8();
    virtual void VfnAC();
    virtual void VfnB0();
    virtual void VfnB4();
    virtual void VfnB8();
    virtual void VfnBC();
    virtual void VfnC0();
    virtual void VfnC4();
    virtual void VfnC8();
    virtual void VfnCC();
    virtual void VfnD0();
    virtual void VfnD4();
    virtual void VfnD8();
    virtual void AttachChildInAvailableSlot(NiObject*, bool);
    NiNode(unsigned short);
    void FUN_004902f0(bool);
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
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char unk4c, unk4d, unk4e, unk4f;
    unsigned char unk50, unk51, unk52, unk53;
    unsigned char unk54, unk55, unk56, unk57;
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
};
class NiAlphaProperty : public NiObject
{
  public:
    NiAlphaProperty();
    unsigned int unk08, unk0c, unk10, unk14, unk18;
    void FUN_0049ed90(bool);
    void SetSrcBlendMode(int);
    void SetDestBlendMode(int);
    void SetNoSorter(bool);
};
class FUN_00baf3c0
{
  public:
    FUN_00baf3c0();
    unsigned int shaderType;
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
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char flags[12];
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int shadowType;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned char unkb0, unkb1, unkb2, unkb3;
    unsigned int unkb4;
    void AddProperties(NiTriShape*, unsigned int);
};
class B006815c0
{
  public:
    float m[3][3];
    B006815c0();
    void FUN_00524ac0(float);
};
class Sky
{
  public:
    static Sky* GetInstance();
    int FUN_00476c90();
};
class BSShaderManager
{
  public:
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
};
extern void* __cdecl NiMalloc(unsigned int);
extern "C" void __cdecl FUN_00b57e30(NiNode*, int, int);
class MoonInit : public Moon
{
  public:
    void FUN_00634e20(NiNode*, const char*);
};
// @fnv 0x00634e20
void MoonInit::FUN_00634e20(NiNode* root, const char* name)
{
    AutoMemContext kContext((MEM_CONTEXT)33, true,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 102);
    stand::NiPoint3* aMoonNormals = 0;
    stand::NiPoint3* moonVertices4 = 0;
    stand::NiPoint3* shadowNormals9 = 0;
    stand::NiPoint3* k = 0;
    NiPoint2* moonUVX = 0;
    NiPoint2* kc = 0;
    ImageSpaceEffectParam* moonColors4 = 0;
    ImageSpaceEffectParam* shadowColors_ = 0;
    unsigned short* moonIndices4 = 0;
    unsigned short* shadowIndicesA = 0;
    SkyObject::Initialize(root);
    aMoonNormals = new stand::NiPoint3[4];
    moonVertices4 = new stand::NiPoint3[4];
    shadowNormals9 = new stand::NiPoint3[4];
    k = new stand::NiPoint3[4];
    moonVertices4[0] = stand::NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    moonVertices4[1] = stand::NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    moonVertices4[2] = stand::NiPoint3((float)iSize, (float)iSize, 0.0f);
    moonVertices4[3] = stand::NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    k[0] = stand::NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    k[1] = stand::NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    k[2] = stand::NiPoint3((float)iSize, (float)iSize, 0.0f);
    k[3] = stand::NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    moonUVX = new NiPoint2[4];
    kc = new NiPoint2[4];
    moonUVX[0] = NiPoint2(0, 0);
    moonUVX[1] = NiPoint2(0, 1);
    moonUVX[2] = NiPoint2(1, 0);
    moonUVX[3] = NiPoint2(1, 1);
    kc[0] = NiPoint2(0, 0);
    kc[1] = NiPoint2(0, 1);
    kc[2] = NiPoint2(1, 0);
    kc[3] = NiPoint2(1, 1);
    moonColors4 = new ImageSpaceEffectParam[4];
    shadowColors_ = new ImageSpaceEffectParam[4];
    ImageSpaceEffectParam iRed(1, 0, 0, 1);
    moonColors4[0] = iRed;
    moonColors4[1] = iRed;
    moonColors4[2] = iRed;
    moonColors4[3] = iRed;
    shadowColors_[0] = iRed;
    shadowColors_[1] = iRed;
    shadowColors_[2] = iRed;
    shadowColors_[3] = iRed;
    moonIndices4 = (unsigned short*)NiMalloc(12);
    shadowIndicesA = (unsigned short*)NiMalloc(12);
    moonIndices4[0] = 0;
    moonIndices4[1] = 1;
    moonIndices4[2] = 2;
    moonIndices4[3] = 2;
    moonIndices4[4] = 1;
    moonIndices4[5] = 3;
    shadowIndicesA[0] = 0;
    shadowIndicesA[1] = 1;
    shadowIndicesA[2] = 2;
    shadowIndicesA[3] = 2;
    shadowIndicesA[4] = 1;
    shadowIndicesA[5] = 3;
    m_pMoonShape = new NiTriShape(4, (NiPoint3*)moonVertices4, (NiPoint3*)aMoonNormals, moonColors4, moonUVX, 1, 0, 2,
                                  moonIndices4);
    ((NiTriShape*)m_pMoonShape)->FUN_004902f0(true);
    m_pMoonShadowShape =
        new NiTriShape(4, (NiPoint3*)k, (NiPoint3*)shadowNormals9, shadowColors_, kc, 1, 0, 2, shadowIndicesA);
    ((NiTriShape*)m_pMoonShadowShape)->FUN_004902f0(true);
    {
        NiPointer<NiAlphaProperty> alpha(new NiAlphaProperty);
        ((NiAlphaProperty*)alpha)->FUN_0049ed90(true);
        ((NiAlphaProperty*)alpha)->SetSrcBlendMode(6);
        ((NiAlphaProperty*)alpha)->SetDestBlendMode(0);
        ((NiAlphaProperty*)alpha)->SetNoSorter(true);
        ((NiTriShape*)m_pMoonShape)->AttachProperty(alpha);
        alpha = 0;
    }
    FUN_00baf3c0 kB;
    kB.shaderType = 6;
    kB.shadowType = 6;
    kB.AddProperties(m_pMoonShape, 1);
    kB.shadowType = 7;
    kB.AddProperties(m_pMoonShadowShape, 1);
    if (Sky::GetInstance()->FUN_00476c90() == 3 || Sky::GetInstance()->FUN_00476c90() == 2)
    {
        SkyShaderProperty* texture = ((NiTriShape*)m_pMoonShadowShape)->GetProperty(3);
        NiPointer<NiTexture> loaded(0);
        BSShaderManager::GetTexture("Textures\\Sky\\MoonShadow.dds", true, loaded, true, false);
        NiTexture* shader = loaded;
        if (shader)
            texture->SetTexture(shader);
        ((NiTriShape*)m_pMoonShadowShape)->SetDisplayObject(shader != 0);
        m_eUpdateStatus = US_INITIALIZE;
    }
    m_pMoonNode = new NiNode(0);
    m_pMoonShadowNode = new NiNode(0);
    ((NiNode*)m_pMoonNode)->FUN_004902f0(true);
    ((NiNode*)m_pMoonShadowNode)->FUN_004902f0(true);
    ((NiNode*)m_pMoonNode)->AttachChildInAvailableSlot(m_pMoonShape, true);
    ((NiNode*)m_pMoonShadowNode)->AttachChildInAvailableSlot(m_pMoonShadowShape, true);
    ((NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiObject*)(NiNode*)m_pMoonShadowNode, true);
    ((NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiObject*)(NiNode*)m_pMoonNode, true);
    {
        B006815c0 rotation;
        rotation.FUN_00524ac0(-1.5707963705062866f);
        ((NiTriShape*)m_pMoonShape)->FUN_004bc1f0(0, 512, 0);
        ((NiTriShape*)m_pMoonShape)->FUN_0043fa80(&rotation);
        ((NiTriShape*)m_pMoonShadowShape)->FUN_004bc1f0(0, 512, 0);
        ((NiTriShape*)m_pMoonShadowShape)->FUN_0043fa80(&rotation);
        FUN_00b57e30(m_pRootNode, 0, 0);
    }
}

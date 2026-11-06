
// src/gamebryo2.2/corelibs/nimain/nibspnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibspnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream;
struct NiNode
{
    void LoadBinary(NiStream&);
};
struct NiSphere
{
    void LoadBinary(NiStream&);
};

struct NiBSPNode : NiNode
{
    NiSphere m_pSphere;
    void FUN_00a9a710(NiStream& stream);
};

// @fnv 0x00a9a710
void NiBSPNode::FUN_00a9a710(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    ((NiSphere*)((char*)this + 0xac))->LoadBinary(stream);
}

namespace fnv_00a9a840 {
struct NiUpdateData
{
};
struct NiAVObject
{
    void __thiscall UpdateWorldData(NiUpdateData&);
};
struct NiBSPNode : NiAVObject
{
    void __thiscall FUN_00a9a840(NiUpdateData&);
    void __thiscall FUN_00a9a760();
};

// @fnv 0x00a9a840
void __thiscall NiBSPNode::FUN_00a9a840(NiUpdateData& aUpdateData)
{
    NiAVObject::UpdateWorldData(aUpdateData);
    FUN_00a9a760();
}
}  // namespace fnv_00a9a840

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5f54;

// @fnv 0x00a9adc0
GlobalObjectO2_00a7b610* __cdecl FUN_00a9adc0()
{
    return &g_011f5f54;
}

struct Unk_00a5e930
{
    void FUN_00a5e930();
};
void __cdecl _delete(void*, unsigned int);
struct FUN_00a9add0_shell
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a5e930 on this, deletes this with size 0xCC when bit 0 of a1 is set, and returns this.
// @fnv 0x00a9add0
void* FUN_00a9add0_shell::DestroyIfFlagged(unsigned int auiFlags)
{
    ((Unk_00a5e930*)this)->FUN_00a5e930();
    if (auiFlags & 1)
        _delete(this, 0xCC);
    return this;
}

namespace fnv_00a9a740 {
struct NiStream;
struct NiSphere
{
    void SaveBinary(NiStream& stream);
};
struct NiNode
{
    void SaveBinary(NiStream& stream);
};
struct NiBSPNode : NiNode
{
    char _pad_0x00[0xac];
    NiSphere m_pSphere;
    void FUN_00a9a740(NiStream& stream);
};

// @fnv 0x00a9a740
void NiBSPNode::FUN_00a9a740(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    m_pSphere.SaveBinary(stream);
}
}  // namespace fnv_00a9a740

struct StrArr
{
    unsigned int m_usSize;
    unsigned int m_usMaxSize;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct FUN_00c51570_Class
{
    void* FUN_00a5ea70(void*);
};
struct FUN_00a69a60_Owner
{
    char* FUN_00a69a60(const char*);
};
char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610*);

struct FUN_00a9acf0_shell : NiBSPNode
{
    void AppendPlaneNames(StrArr* apViewerStrings);
};

// @fnv 0x00a9acf0
void FUN_00a9acf0_shell::AppendPlaneNames(StrArr* apViewerStrings)
{
    ((FUN_00c51570_Class*)this)->FUN_00a5ea70(apViewerStrings);
    char* pName = _FUN_00a7d330(*(GlobalObjectO2_00a7b610**)&g_011f5f54);
    unsigned int uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
    pName = ((FUN_00a69a60_Owner*)((char*)this + 0xac))->FUN_00a69a60("m_kModelPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
    pName = ((FUN_00a69a60_Owner*)((char*)this + 0xbc))->FUN_00a69a60("m_kWorldPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
}

struct NiStream;

struct FUN_00a59e00_shell
{
    void FUN_00a59e00(NiStream& stream);
};

struct FUN_0049da80_shell
{
    int ClassifyPoint(void* ptr);
};

struct BinaryDataRecord
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    float unk68;
    int unk6c;
    int unk70;
    float unk74;
    int unk78;
    int unk7c;
    float unk80;
    int unk84;
    int unk88;
    float unk8c;
};

struct NiStream
{
    int unk00;
    int unk04;
    int unk08;
    BinaryDataRecord* unk0c;
};

struct PtrPair
{
    FUN_00a59e00_shell* unk00;
    FUN_00a59e00_shell* unk04;
};

struct TriFloat
{
    float f0;
    float f1;
    float f2;
};

struct FUN_00a9ac10_shell
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    PtrPair* unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    FUN_0049da80_shell unkBC;

    void LoadFromStream(NiStream& stream);
};

// @fnv 0x00a9ac10
void FUN_00a9ac10_shell::LoadFromStream(NiStream& stream)
{
    BinaryDataRecord* data = stream.unk0c;
    int r = unkBC.ClassifyPoint(&data->unk8c);
    if (r == 0)
    {
        TriFloat kTriple;
        kTriple.f0 = data->unk68;
        kTriple.f1 = data->unk74;
        kTriple.f2 = data->unk80;
        r = unkBC.ClassifyPoint(&kTriple);
    }
    PtrPair* p = unkA0;
    FUN_00a59e00_shell* a = p->unk00;
    FUN_00a59e00_shell* b = p->unk04;
    if (r == 2)
    {
        if (b != 0)
        {
            b->FUN_00a59e00(stream);
        }
        if (a != 0)
        {
            a->FUN_00a59e00(stream);
        }
    }
    else
    {
        if (a != 0)
        {
            a->FUN_00a59e00(stream);
        }
        if (b != 0)
        {
            b->FUN_00a59e00(stream);
        }
    }
}

class A9ACB0Object;

class A9ACB0Bound
{
  public:
    bool operator!=(const A9ACB0Bound& kBound) const;

    float m_afCenter[3];
    float m_fBoundRadius;
};

class A9ACB0Base
{
  public:
    bool IsEqual(A9ACB0Object* pkObject);

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
};

class A9ACB0Node : public A9ACB0Base
{
  public:
    A9ACB0Bound m_kBound;

    bool IsEqualWithBound(A9ACB0Object* pkObject);
};

// Returns true if IsEqual(pkObject) holds and this node's m_kBound equals the other node's m_kBound; otherwise false.
// @fnv 0x00a9acb0
bool A9ACB0Node::IsEqualWithBound(A9ACB0Object* pkObject)
{
    if (!IsEqual(pkObject))
        return false;

    A9ACB0Node* pkOther = (A9ACB0Node*)pkObject;
    if (m_kBound != pkOther->m_kBound)
        return false;

    return true;
}

extern char vtable_010a1024;
void* __cdecl FUN_00aa13e0(unsigned int bytes);
struct ObjBase
{
    void FUN_00a5ecb0(int);
};
struct SubObject
{
    void FUN_00a69940();
};
struct ChildNode
{
    void FUN_0060bef0(unsigned int);
};
struct FourInts
{
    int first;
    int second;
    int third;
    int fourth;
};
struct NodeOwner
{
    void FUN_00a5dc80(void*, void*);
    void* CreateClone(void* arg);
};
// @fnv 0x00a9ae00
void* NodeOwner::CreateClone(void* arg)
{
    char* memory = (char*)FUN_00aa13e0(0xcc);
    char* result;
    if (memory)
    {
        ((ObjBase*)memory)->FUN_00a5ecb0(0);
        *(void**)memory = &vtable_010a1024;
        ((SubObject*)(memory + 0xac))->FUN_00a69940();
        ((SubObject*)(memory + 0xbc))->FUN_00a69940();
        ((ChildNode*)(memory + 0x9c))->FUN_0060bef0(2);
        *(unsigned short*)(memory + 0xaa) = 0;
        result = memory;
    }
    else
    {
        result = 0;
    }
    FUN_00a5dc80(result, arg);
    *(FourInts*)(result + 0xac) = *(FourInts*)((char*)this + 0xac);
    return result;
}

__declspec(noreturn) void __cdecl ReadChildListFromStream();

// @fnv 0x00a9a730
void __cdecl FUN_00a9a730()
{
    ReadChildListFromStream();
}

void __cdecl RegisterChildStreamables();
// @fnv 0x00a93c40
void __cdecl FUN_00a93c40()
{
    RegisterChildStreamables();
}

struct Vec_a9a760
{
    float x, y, z;
    Vec_a9a760()
    {}
    Vec_a9a760(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float Dot(const Vec_a9a760& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};
struct Mat_a9a760
{
    Vec_a9a760 a, b, c;
    Vec_a9a760 operator*(const Vec_a9a760& v) const
    {
        return Vec_a9a760(a.x * v.x + a.y * v.y + a.z * v.z, b.x * v.x + b.y * v.y + b.z * v.z,
                          c.x * v.x + c.y * v.y + c.z * v.z);
    }
};
struct Plane_a9a760
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    Mat_a9a760 rotation;
    Vec_a9a760 translation;
    float scale;
    int unk9c, unka0, unka4, unka8;
    Vec_a9a760 modelNormal;
    volatile float modelConstant;
    Vec_a9a760 worldNormal;
    float worldConstant;
    void FUN_00a9a760();
};
// Transforms modelNormal and modelConstant into world space using rotation, translation, and scale.
// @fnv 0x00a9a760
void Plane_a9a760::FUN_00a9a760()
{
    Vec_a9a760 normal = rotation * modelNormal;
    volatile float fWorldConstant = translation.Dot(normal);
    worldNormal = normal;
    double oldConstant = fWorldConstant;
    fWorldConstant = oldConstant + scale * modelConstant;
    worldConstant = fWorldConstant;
}

struct NiPoint3
{
    float x, y, z;
    const float& X() const
    {
        return x;
    }
    const float& Y() const
    {
        return y;
    }
    const float& Z() const
    {
        return z;
    }
    float Get(unsigned i) const
    {
        return i == 0 ? x : (i == 1 ? y : z);
    }
    const NiPoint3& Value() const
    {
        return *this;
    }
    NiPoint3()
    {}
    NiPoint3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    NiPoint3 operator+(const NiPoint3& p) const
    {
        return NiPoint3(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    float operator*(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    NiPoint3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NiPoint3(x * inv, y * inv, z * inv);
    }
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    const float& At(unsigned i, unsigned j) const
    {
        return m_afEntries[i][j];
    }
    float Get(unsigned i, unsigned j) const
    {
        return m_afEntries[i][j];
    }
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix& m) const;
    ThreeByThreeMatrix ComposeMatrices(const ThreeByThreeMatrix& m) const;
    bool Inverse(ThreeByThreeMatrix& inv) const;
    NiPoint3 operator*(const NiPoint3& p) const
    {
        NiPoint3 r;
        r.x = m_afEntries[0][0] * p.x + (p.y * (m_afEntries[0][1])) + (p.z) * (m_afEntries[0][2]);
        r.y = (((p.x) * m_afEntries[1][0]) + m_afEntries[1][1] * p.y + p.z * m_afEntries[1][2]);
        r.z = (m_afEntries[2][0] * (p.x)) + (p.y) * (m_afEntries[2][1]) + (p.z) * (m_afEntries[2][2]);
        return r;
    }
    __forceinline NiPoint3 TransformNormal(const NiPoint3& p) const
    {
        const NiPoint3& normal = p;
        NiPoint3 r;
        r.x = ((At(0, 0) * normal.x) + (normal.y * Get(1, 0))) + (Get(2, 0) * normal.z);
        r.y = ((p.Value().x * m_afEntries[0][1]) + (p.Y() * Get(1, 1))) + (p.z * m_afEntries[2][1]);
        r.z = ((m_afEntries[1][2] * p.y) + (p.Value().x * m_afEntries[0][2])) + (m_afEntries[2][2] * p.Z());
        return r;
    }
    friend NiPoint3 operator*(const NiPoint3& p, const ThreeByThreeMatrix& m)
    {
        return NiPoint3(p.x * m.m_afEntries[0][0] + p.y * m.m_afEntries[1][0] + p.z * m.m_afEntries[2][0],
                        p.x * m.m_afEntries[0][1] + p.y * m.m_afEntries[1][1] + p.z * m.m_afEntries[2][1],
                        p.x * m.m_afEntries[0][2] + p.y * m.m_afEntries[1][2] + p.z * m.m_afEntries[2][2]);
    }
};
struct AVChild
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
    virtual void ApplyTransform(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft);
};
struct NiPlane
{
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    __forceinline void Apply(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn)
    {
        ThreeByThreeMatrix kInv;
        kMat.Inverse(kInv);
        m_kPlaneNormal = m_kPlaneNormal * kInv;
        m_fPlaneConstant += m_kPlaneNormal * kTrn;
    }
};
struct BSPNodeX
{
    void* vtbl;
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
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    AVChild** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    int unka8;
    NiPlane m_kModelPlane;
    __forceinline void AddPlaneConst(const NiPoint3& kTrn)
    {

        m_kModelPlane.m_fPlaneConstant += (m_kModelPlane.m_kPlaneNormal) * kTrn;
    }
    __forceinline void ApplyPlane(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn)
    {
        ThreeByThreeMatrix kInv;
        kMat.Inverse(kInv);
        m_kModelPlane.m_kPlaneNormal = m_kModelPlane.m_kPlaneNormal * kInv;
        AddPlaneConst(kTrn);
    }
    __forceinline void ApplyPlane2(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn)
    {
        ThreeByThreeMatrix kInv;
        kMat.Inverse(kInv);
        NiPoint3 normal = kInv.TransformNormal(m_kModelPlane.m_kPlaneNormal);
        m_kModelPlane.m_kPlaneNormal = normal;
        m_kModelPlane.m_fPlaneConstant += m_kModelPlane.m_kPlaneNormal * kTrn;
    }
    void FUN_00a9a860(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft);
};

// Applies the supplied matrix and translation to the node's model plane and passes them to each non-null child.
// @fnv 0x00a9a860
void BSPNodeX::FUN_00a9a860(const ThreeByThreeMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft)
{
    if (bOnLeft)
    {
        ThreeByThreeMatrix kRot = m_kRotate.ComposeMatrices(kMat * m_kRotate);
        NiPoint3 kT = ((kTrn + kMat * m_kTranslate) - m_kTranslate) * m_kRotate / m_fScale;
        ApplyPlane(kRot, kT);
        for (unsigned int i = 0; i < m_usSize; i++)
        {
            AVChild* pChild = m_pBase[i];
            if (pChild)
                pChild->ApplyTransform(kRot, kT, true);
        }
    }
    else
    {
        ApplyPlane2(kMat, kTrn);
        for (unsigned int i = 0; i < m_usSize; i++)
        {
            AVChild* pChild = m_pBase[i];
            if (pChild)
                pChild->ApplyTransform(kMat, kTrn, true);
        }
    }
}

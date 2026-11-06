// fallout_shared/bgsprimitive.cpp: BGSPrimitiveSphere, BGSPrimitiveBox, BSMultiBoundAABB, BSMultiBoundSphere and more (113 functions)

#include "bgsprimitive_decls.h"

// Takes the absolute value of each radius component, stores it, rebuilds the box and frame geometry vertices, and updates the model and world bounds.
// @fnv 0x004a6640
void BGSPrimitiveBox::NormalizeRadii(NiPoint3& radii)
{
    radii[0] = std::abs(radii[0]);
    radii[1] = std::abs(radii[1]);
    radii[2] = std::abs(radii[2]);
    m_kRadii = radii;
    if (m_kGeometry)
    {
        struct GeometryVertices
        {
            NiPoint3* vertices;
            NiGeometryData* data;
        } geometry;
        geometry.data = m_kGeometry->FUN_005495f0();
        geometry.vertices = geometry.data->GetVertices();
        geometry.vertices[0] = NiPoint3(-m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        geometry.vertices[1] = NiPoint3(m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        geometry.vertices[2] = NiPoint3(m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        geometry.vertices[3] = NiPoint3(-m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        geometry.vertices[4] = NiPoint3(-m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        geometry.vertices[5] = NiPoint3(m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        geometry.vertices[6] = NiPoint3(m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        geometry.vertices[7] = NiPoint3(-m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        geometry.data->SetDirtyFlags(1);
    }
    if (m_kLines)
    {
        NiGeometryData* pkData = m_kLines->FUN_005495f0();
        {
            struct FrameVertices
            {
                NiPoint3* vertices;
                NiPoint3 scale;
            } frame = {pkData->GetVertices(), radii};
            if (std::abs(frame.scale.x) < (double)0.01f)
                frame.scale.x = 0.01f;
            if (std::abs(frame.scale.y) < (double)0.01f)
                frame.scale.y = 0.01f;
            if (std::abs(frame.scale.z) < (double)0.01f)
                frame.scale.z = 0.01f;
            for (int i = 0; i < pkData->GetVertexCount(); i++)
            {
                frame.vertices[i].x = frame.vertices[i].x < 0.0 ? -1.0f : 1.0f;
                frame.vertices[i].y = frame.vertices[i].y < 0.0 ? -1.0f : 1.0f;
                frame.vertices[i].z = frame.vertices[i].z < 0.0 ? -1.0f : 1.0f;
                frame.vertices[i].x *= frame.scale.x;
                frame.vertices[i].y *= frame.scale.y;
                frame.vertices[i].z *= frame.scale.z;
                pkData->SetDirtyFlags(1);
            }
        }
    }
    NiUpdateData kUpdateData(0.0f, false, false);
    if (m_pController)
    {
        float radius = radii.x;
        if (radii.y > radii.x && radii.y > radii.z)
            radius = radii.y;
        if (radii.z > radii.y && radii.z > radii.x)
            radius = radii.z;
        NiBound bound;
        bound.SetCenterAndRadius(NiPoint3::ZERO, radius);
        m_kGeometry->SetModelBound(bound);
        m_pController->Update(kUpdateData);
        m_kGeometry->UpdateSceneObject();
        m_pController->UpdateWorldBound();
    }
}

// @fnv 0x004a53e0
void BGSPrimitivePlane::SetColor(RgbaColor& color)
{
    Color = color;
    if (m_kGeometry)
    {
        struct GeometryColors
        {
            RgbaColor* colors;
            NiGeometryData* data;
        } geometry;
        geometry.data = m_kGeometry->FUN_005495f0();
        geometry.colors = geometry.data->GetColors();
        geometry.colors[0] = geometry.colors[1] = geometry.colors[2] = geometry.colors[3] = geometry.colors[4] =
            geometry.colors[5] = geometry.colors[6] = geometry.colors[7] = Color;
        geometry.data->SetDirtyFlags(4);
    }
    if (m_kLines)
        m_kLines->SetAppCulled(color.a < 0.001);
}

// Stores color, then if geometry exists, fills both geometry data color arrays with it and sets app-culled based on alpha.
// @fnv 0x004a64e0
void BGSPrimitiveBox::SetColor(RgbaColor& color)
{
    Color = color;
    if (m_kGeometry)
    {
        struct GeometryColors
        {
            RgbaColor* colors;
            NiGeometryData* data;
        } geometry;
        geometry.data = m_kGeometry->FUN_005495f0();
        geometry.colors = geometry.data->GetColors();
        int i;
        for (i = 0; i < geometry.data->GetVertexCount(); i++)
            geometry.colors[i] = Color;
        geometry.data->SetDirtyFlags(4);
        geometry.data = m_kLines->FUN_005495f0();
        geometry.colors = geometry.data->GetColors();
        for (i = 0; i < geometry.data->GetVertexCount(); i++)
            geometry.colors[i] = Color;
        geometry.data->SetDirtyFlags(4);
        m_kLines->SetAppCulled(color.a < 0.001);
    }
}

// Creates a BSFadeNode named "Box" and stores it in the primitive's node pointer if not already created.
// @fnv 0x004a63f0
void BGSPrimitiveBox::Build()
{
    if (!m_pController)
    {
        m_pController = new BSFadeNode;
        m_pController->SetName(NiFixedString("Box"));
        m_pController->UpdateSceneObject();
    }
}

// Initializes the primitive box: clears two fields and sets eType to 1.
// @fnv 0x004a6370
BGSPrimitiveBox::BGSPrimitiveBox()
{
    m_kGeometry = 0;
    m_pController = 0;
    eType = 1;
}

// @fnv 0x004a60f0
unsigned int bhkMultiSphereShape::GetInstanceSize()
{
    return 16;
}

struct FUN_004a4cc0_shell : public RgbaColor
{
    bool FUN_004a4cc0(void*);
};

// Compares this object's first four floats with those of p and returns true only if all four are equal.
// @fnv 0x004a4cc0
bool FUN_004a4cc0_shell::FUN_004a4cc0(void* apOther)
{
    return reinterpret_cast<const float*>(this)[0] == static_cast<const float*>(apOther)[0] &&
           reinterpret_cast<const float*>(this)[1] == static_cast<const float*>(apOther)[1] &&
           reinterpret_cast<const float*>(this)[2] == static_cast<const float*>(apOther)[2] &&
           reinterpret_cast<const float*>(this)[3] == static_cast<const float*>(apOther)[3];
}

struct FUN_004a51d0_shell : public NiBound
{
    void FUN_004a51d0(void*, float);
};

// @fnv 0x004a51d0
void FUN_004a51d0_shell::FUN_004a51d0(void* apCenter, float fRadius)
{
    m_kCenter = *(const NiPoint3*)apCenter;
    m_fBoundRadius = fRadius;
}

struct FUN_004a5250_shell : public NiBound
{
    void* AssignFromBound(void*);
};

// Copies the center and radius from the given NiBound into this bound and returns this.
// @fnv 0x004a5250
void* FUN_004a5250_shell::AssignFromBound(void* aRhs)
{
    SetCenterAndRadius(static_cast<const NiBound*>(aRhs)->m_kCenter, static_cast<const NiBound*>(aRhs)->m_fBoundRadius);
    return this;
}

void __fastcall _ref_006815c0(void* pThis);

// @fnv 0x006240d0
void* __fastcall FUN_006240d0(void* pThis)
{
    _ref_006815c0(pThis);
    return pThis;
}

void __fastcall FUN_00c4f980(void*);

// @fnv 0x00c37ec0
void* __fastcall FUN_00c37ec0(void* this_ptr)
{
    FUN_00c4f980(this_ptr);
    *(const char**)this_ptr = "`pJ";
    return this_ptr;
}

// @fnv 0x004a6100
int __fastcall FUN_004a6100(int this_)
{
    return 0x1e;
}

struct Pt
{
    float Length() const;
};

struct BSMultiBoundAABB
{
    unsigned char pad[0x18];
    Pt m_afExtents;
    float GetPointLength();
};

// @fnv 0x004a7040
float BSMultiBoundAABB::GetPointLength()
{
    return m_afExtents.Length();
}

extern int g_01202818;

struct FUN_004a70f0_shell
{
    int* __thiscall FUN_004a70f0();
};

// @fnv 0x004a70f0
int* __thiscall FUN_004a70f0_shell::FUN_004a70f0()
{
    return &g_01202818;
}

// @fnv 0x00c365e0
int __fastcall FUN_00c365e0(int)
{
    return 2;
}

struct FUN_00c382a0_shell
{
    int FUN_00c382a0();
};

// @fnv 0x00c382a0
int FUN_00c382a0_shell::FUN_00c382a0()
{
    return 1;
}

void* g_012030b8;

struct FUN_00c4f8d0_shell
{
    void* __thiscall GetGlobalPtr();
};

// @fnv 0x00c4f8d0
void* __thiscall FUN_00c4f8d0_shell::GetGlobalPtr()
{
    return &g_012030b8;
}

struct FUN_00c4fec0_shell
{
    int __thiscall FUN_00c4fec0();
};

// @fnv 0x00c4fec0
int __thiscall FUN_00c4fec0_shell::FUN_00c4fec0()
{
    return 3;
}

struct FUN_004a6d90_shell
{
    bool IsPointInsideBox(NiPoint3& aPoint);
};

// Returns true when aPoint lies within the axis-aligned box given by the negated and positive extents stored at offset 0x18 of this.
// @fnv 0x004a6d90
bool FUN_004a6d90_shell::IsPointInsideBox(NiPoint3& aPoint)
{
    if (-((NiPoint3*)((char*)this + 0x18))->x > aPoint.x || -((NiPoint3*)((char*)this + 0x18))->y > aPoint.y ||
        -((NiPoint3*)((char*)this + 0x18))->z > aPoint.z || aPoint.x > ((NiPoint3*)((char*)this + 0x18))->x ||
        aPoint.y > ((NiPoint3*)((char*)this + 0x18))->y || aPoint.z > ((NiPoint3*)((char*)this + 0x18))->z)
        return false;
    return true;
}

struct CloningProcess;
struct NiRefObject
{
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};
struct NiPoint2
{
    float x, y;
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
struct NiPlane
{
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
};
struct NiFrustumPlanes
{
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};
struct FUN_00c335d0 : NiRefObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    NiPoint3 kTargetCenter;
    NiPoint2 m_kPoint2;
    ThreeByThreeMatrix kRotationBasis;
    int m_uiShapeType;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kCornerPoints[4];
    NiPoint3 m_kReferencePoint;
    bool m_bIsInFrustum;
    bool m_bIsVisible;
    bool m_bCornerVisible[4];
    bool m_bDecalTextureCreated;
    FUN_00c335d0* m_apDecalObjects[4];
    FUN_00c335d0();
};
struct FUN_00c33730_shell
{
    void CopyStateTo(FUN_00c335d0* pkDest, CloningProcess& kCloning);
    FUN_00c335d0* FUN_00c33730(CloningProcess& kCloning);
};

// @fnv 0x00c33730
FUN_00c335d0* FUN_00c33730_shell::FUN_00c33730(CloningProcess& kCloning)
{
    FUN_00c335d0* pkObject = new FUN_00c335d0;
    CopyStateTo(pkObject, kCloning);
    return pkObject;
}

namespace fnv_00c36330 {
struct CloningProcess;
struct NiRefObject
{
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
struct FUN_00c36310 : NiRefObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    int m_uiShapeType;
    NiPoint3 kTargetCenter;
    NiPoint3 kSize;
    ThreeByThreeMatrix kAxis;
    FUN_00c36310();
};
struct FUN_00c36330_shell
{
    void FUN_00c363c0(FUN_00c36310* pkDest, CloningProcess& kCloning);
    FUN_00c36310* FUN_00c36330(CloningProcess& kCloning);
};

// @fnv 0x00c36330
FUN_00c36310* FUN_00c36330_shell::FUN_00c36330(CloningProcess& kCloning)
{
    FUN_00c36310* pkObject = new FUN_00c36310;
    FUN_00c363c0(pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00c36330

namespace fnv_00c37ee0 {
struct CloningProcess;
struct NiRefObject
{
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};
struct FUN_00c37ec0 : NiRefObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    int m_uiShapeType;
    NiPoint3 kTargetCenter;
    NiPoint3 m_kPoint2;
    FUN_00c37ec0();
};
struct FUN_00c37ee0_shell
{
    void FUN_00c37f70(FUN_00c37ec0* pkDest, CloningProcess& kCloning);
    FUN_00c37ec0* FUN_00c37ee0(CloningProcess& kCloning);
};

// @fnv 0x00c37ee0
FUN_00c37ec0* FUN_00c37ee0_shell::FUN_00c37ee0(CloningProcess& kCloning)
{
    FUN_00c37ec0* pkObject = new FUN_00c37ec0;
    FUN_00c37f70(pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00c37ee0

namespace fnv_00c4fb30 {
struct CloningProcess;
struct NiRefObject
{
    virtual ~NiRefObject();
    unsigned int m_uiRefCount;
};
struct FUN_00c4fb10 : NiRefObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    int m_uiShapeType;
    NiPoint3 kTargetCenter;
    float fRadius;
    FUN_00c4fb10();
};
struct FUN_00c4fb30_shell
{
    void FUN_00c4fbc0(FUN_00c4fb10* pkDest, CloningProcess& kCloning);
    FUN_00c4fb10* FUN_00c4fb30(CloningProcess& kCloning);
};

// @fnv 0x00c4fb30
FUN_00c4fb10* FUN_00c4fb30_shell::FUN_00c4fb30(CloningProcess& kCloning)
{
    FUN_00c4fb10* pkObject = new FUN_00c4fb10;
    FUN_00c4fbc0(pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00c4fb30

extern char const* const g_012030b0_arg1;

struct FUN_004a60e0_shell
{
    char const* const* __thiscall FUN_004a60e0();
};

// @fnv 0x004a60e0
char const* const* __thiscall FUN_004a60e0_shell::FUN_004a60e0()
{
    return &g_012030b0_arg1;
}

struct FUN_004a62c0_shell
{
    int* FUN_004a62c0();
};

extern int g_012030b0;

// @fnv 0x004a62c0
int* FUN_004a62c0_shell::FUN_004a62c0()
{
    return &g_012030b0;
}

namespace fnv_004a7030 {
struct BSMultiBoundAABB
{
    int FUN_004a7030();
};

// @fnv 0x004a7030
int BSMultiBoundAABB::FUN_004a7030()
{
    return 0x24;
}
}  // namespace fnv_004a7030

struct BGSPrimitiveSphere
{
    void SetRadius(float radius);
    void FUN_004a71d0(NiPoint3& akRadii);
};

// @fnv 0x004a71d0
void BGSPrimitiveSphere::FUN_004a71d0(NiPoint3& aPoint)
{
    SetRadius(aPoint.x);
}

struct FUN_004a4bd0_shell
{
    void FUN_004a4bd0();
};

void FUN_004a4bd0_shell::FUN_004a4bd0()
{}

struct FUN_004a7220_shell
{
    void FUN_004a7220();
};

// @fnv 0x004a7220
void FUN_004a7220_shell::FUN_004a7220()
{
    ((FUN_004a4bd0_shell*)this)->FUN_004a4bd0();
}

struct BSMultiBoundSphere
{
    void DestroyBase();
    static void _delete(void* p, unsigned int size);
    void* FUN_004a7bf0(unsigned int flags);
};

// Calls DestroyBase, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004a7bf0
void* BSMultiBoundSphere::FUN_004a7bf0(unsigned int flags)
{
    DestroyBase();
    if (flags & 1)
        _delete(this, 28);
    return this;
}

struct FUN_00c38020_shell
{
    unsigned char __thiscall FUN_00c4fa30(int a);
    unsigned char __thiscall FUN_00c38020(int a);
};

// Returns 0 if FUN_00c4fa30(a) is false, otherwise returns 1.
// @fnv 0x00c38020
unsigned char __thiscall FUN_00c38020_shell::FUN_00c38020(int aiArg)
{
    if (!FUN_00c4fa30(aiArg))
        return 0;
    return 1;
}

struct FUN_00c4f6c0_shell
{
    void FUN_00c4f6c0(int, int);
};

// @fnv 0x00c4f6c0
void FUN_00c4f6c0_shell::FUN_00c4f6c0(int, int)
{}

struct FUN_00c4f550_shell
{
    void FUN_00c4f550();
};
void __cdecl _delete(void* p, unsigned int size);

struct FUN_00c4f820_shell
{
    void* FUN_00c4f820(unsigned int flags);
};

// @fnv 0x00c4f820
void* FUN_00c4f820_shell::FUN_00c4f820(unsigned int flags)
{
    reinterpret_cast<FUN_00c4f550_shell*>(this)->FUN_00c4f550();
    if (flags & 1)
        _delete(this, 0xc4);
    return this;
}

struct NiStream
{
};

struct NiObject
{
    virtual void LoadBinary(NiStream&);
};

struct FUN_00c4f9f0_shell : NiObject
{
    void FUN_00c4f9f0(NiStream& stream);
};

// @fnv 0x00c4f9f0
void FUN_00c4f9f0_shell::FUN_00c4f9f0(NiStream& stream)
{
    NiObject::LoadBinary(stream);
}

namespace fnv_00c4fa10 {
struct NiStream
{
};

struct NiObject
{
    virtual void LinkObject(NiStream&);
};

struct FUN_00c4fa10_shell : NiObject
{
    void FUN_00c4fa10(NiStream& stream);
};

// @fnv 0x00c4fa10
void FUN_00c4fa10_shell::FUN_00c4fa10(NiStream& stream)
{
    NiObject::LinkObject(stream);
}
}  // namespace fnv_00c4fa10

namespace fnv_00c4fa30 {
class NiStream;

struct NiObject
{
    virtual bool RegisterStreamables(NiStream&);
};

struct FUN_00c4fa30_shell : NiObject
{
    bool FUN_00c4fa30(NiStream& stream);
};

// Calls the base NiObject::RegisterStreamables and returns its result.
// @fnv 0x00c4fa30
bool FUN_00c4fa30_shell::FUN_00c4fa30(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream))
        return false;
    return true;
}
}  // namespace fnv_00c4fa30

namespace fnv_00c4fa60 {
struct NiStream
{
};

struct NiObject
{
    virtual void LinkObject(NiStream&);
};

void NiObject::LinkObject(NiStream&)
{}

struct FUN_00c4fa60_shell : NiObject
{
    void FUN_00c4fa60(NiStream& stream);
};

// @fnv 0x00c4fa60
void FUN_00c4fa60_shell::FUN_00c4fa60(NiStream& stream)
{
    NiObject::LinkObject(stream);
}
}  // namespace fnv_00c4fa60

extern char const* const g_01202820_arg1;

struct FUN_00c4fb00_shell
{
    char const* const* FUN_00c4fb00();
};

// @fnv 0x00c4fb00
char const* const* FUN_00c4fb00_shell::FUN_00c4fb00()
{
    return &g_01202820_arg1;
}

namespace fnv_004a4c90 {
struct FUN_004a4cc0_shell
{
    bool FUN_004a4cc0(void*);
};
struct FUN_004a4c90_shell : FUN_004a4cc0_shell
{
    bool FUN_004a4c90(void*);
};
// Returns the logical negation of FUN_004a4cc0 called on c.
// @fnv 0x004a4c90
bool FUN_004a4c90_shell::FUN_004a4c90(void* c)
{
    return !FUN_004a4cc0(c);
}
}  // namespace fnv_004a4c90

struct _Fake_FUN_004a7090
{
    void f();
};
void __cdecl _delete(void*, unsigned int);
struct BSOcclusionPlane
{
    void* FUN_004a6110(unsigned int);
};
// @fnv 0x004a6110
void* BSOcclusionPlane::FUN_004a6110(unsigned int flags)
{
    ((_Fake_FUN_004a7090*)this)->f();
    if (flags & 1)
        _delete(this, 0xfc);
    return this;
}

void __cdecl _delete(void*, unsigned int);
struct Unk462D0
{
    void __thiscall FUN_004a6310();
    void* __thiscall FUN_004a62d0(unsigned int);
};
// @fnv 0x004a62d0
void* __thiscall Unk462D0::FUN_004a62d0(unsigned int flags)
{
    this->FUN_004a6310();
    if (flags & 1)
        _delete(this, 0x108);
    return this;
}

struct GO
{
    void* p;
    ~GO();
};
struct FUN_004a7090
{
    ~FUN_004a7090();
    char _pad[0x104];
};
struct FUN_004a6310 : FUN_004a7090
{
    GO field_104;
    ~FUN_004a6310();
};
// Destructor for FUN_004a6310 that destroys its field_104 member and the base FUN_004a7090.
// @fnv 0x004a6310
FUN_004a6310::~FUN_004a6310()
{}

namespace fnv_004a7060 {
struct BSMultiBoundSphere
{
    void DestroyBase();
};
void __cdecl _delete(void*, unsigned int);
struct BSMultiBoundAABB
{
    void* FUN_004a7060(unsigned int);
};
// Calls DestroyBase on this, optionally frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004a7060
void* BSMultiBoundAABB::FUN_004a7060(unsigned int flags)
{
    reinterpret_cast<BSMultiBoundSphere*>(this)->DestroyBase();
    if (flags & 1)
        _delete(this, 0x24);
    return this;
}
}  // namespace fnv_004a7060

struct BSMultiBoundOBB
{
    void FUN_004a7130();
    void* FUN_004a7100(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x004a7100
void* BSMultiBoundOBB::FUN_004a7100(unsigned int flags)
{
    this->FUN_004a7130();
    if (flags & 1)
        _delete(this, 72);
    return this;
}

namespace fnv_004a71f0 {
struct FUN_004a7220_shell
{
    void FUN_004a7220();
};
void _Deallocate(void*);
struct FUN_004a71f0_shell : FUN_004a7220_shell
{
    void* FUN_004a71f0(unsigned int);
};
// Calls FUN_004a7220, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x004a71f0
void* FUN_004a71f0_shell::FUN_004a71f0(unsigned int flags)
{
    FUN_004a7220();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004a71f0

namespace fnv_004a7240 {
struct TESCombatStyle
{
    float UpdateCombatStyle();
};
struct BGSPrimitiveSphere
{
    bool FUN_004a7240(TESCombatStyle& aPoint);
};
// @fnv 0x004a7240
bool BGSPrimitiveSphere::FUN_004a7240(TESCombatStyle& aPoint)
{
    return (double)*(float*)((char*)this + 0x18) * *(float*)((char*)this + 0x18) > aPoint.UpdateCombatStyle();
}
}  // namespace fnv_004a7240

struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
};
struct S
{
    void FUN_004a7800();
};
// Constructs an ImageSpaceEffectParam on this object with all four float arguments set to 0.0f.
// @fnv 0x004a7800
void S::FUN_004a7800()
{
    ((ImageSpaceEffectParam*)this)->ImageSpaceEffectParam::ImageSpaceEffectParam(0.0f, 0.0f, 0.0f, 0.0f);
}

void __fastcall FUN_00c4f980(void*);
extern int DAT_0101ea8c;
struct FUN_004a7b40_Pt
{
    float x;
    float y;
    float z;
};
struct FUN_004a7b40
{
    int _00;
    int _04;
    int _08;
    FUN_004a7b40_Pt mPt;
    float mRadius;
    FUN_004a7b40(const FUN_004a7b40_Pt&, float);
};
// Initializes the object's vtable, copies the given point into mPt and stores the radius in mRadius.
// @fnv 0x004a7b40
FUN_004a7b40::FUN_004a7b40(const FUN_004a7b40_Pt& aPt, float aRadius)
{
    FUN_00c4f980(this);
    *(void**)this = (void*)&DAT_0101ea8c;
    mPt = aPt;
    mRadius = aRadius;
}

namespace fnv_00c36400 {
class NiStream;
struct ThreeByThreeMatrix
{
    void LoadBinary(NiStream&);
};
struct My36400
{
    void FUN_00c37fc0(NiStream&);
    void FUN_00c36400(NiStream&);
    char pad[0x24];
    ThreeByThreeMatrix m;
};
// Loads the object from the stream: calls FUN_00c37fc0(s), then loads the member via LoadBinary(s).
// @fnv 0x00c36400
void My36400::FUN_00c36400(NiStream& aStream)
{
    FUN_00c37fc0(aStream);
    m.LoadBinary(aStream);
}
}  // namespace fnv_00c36400

namespace fnv_00c36450 {
struct FUN_00c38020_shell
{
    unsigned char FUN_00c38020(int);
};
struct FUN_00c36450_shell : FUN_00c38020_shell
{
    bool FUN_00c36450(int);
};
// @fnv 0x00c36450
bool FUN_00c36450_shell::FUN_00c36450(int aiValue)
{
    if (!FUN_00c38020(aiValue))
        return false;
    return true;
}
}  // namespace fnv_00c36450

class NiStream;
struct FUN_00a59a90_tgt
{
    void ReadMatrixFromStream(NiStream*);
};
struct S00c38050
{
    char _f[36];
    void FUN_00c38050(NiStream*);
};
struct FUN_00c36480_tgt : S00c38050, FUN_00a59a90_tgt
{
    void FUN_00c36480(NiStream*);
};
// @fnv 0x00c36480
void FUN_00c36480_tgt::FUN_00c36480(NiStream* p)
{
    S00c38050::FUN_00c38050(p);
    FUN_00a59a90_tgt::ReadMatrixFromStream(p);
}

namespace fnv_00c37110 {
struct Pt
{
    float Length() const;
};
struct Vec12
{
    float x;
    float y;
    float z;
};
struct Out12
{
    Vec12 v;
    float l;
};
struct S37110
{
    char _pad[12];
    Vec12 v;
    Pt p;
    void GetVectorAndLength(Out12* a);
};
// Copies v into a->v and stores the length of p into a->l.
// @fnv 0x00c37110
void S37110::GetVectorAndLength(Out12* apOut)
{
    int dummy;
    {
        float f = p.Length();
        apOut->v = v;
        apOut->l = f;
    }
}
}  // namespace fnv_00c37110

namespace fnv_00c37fc0 {
struct NiColor
{
    float r, g, b;
    void LoadBinary(class NiStream&);
};
struct FUN_00c4f9f0_shell
{
    char _pad[12];
    void FUN_00c4f9f0(class NiStream&);
};
struct FUN_00c37fc0_shell : FUN_00c4f9f0_shell
{
    NiColor unk0C;
    NiColor unk18;
    void FUN_00c37fc0(class NiStream&);
};
// Calls the base loader, then reads two NiColor members from the stream.
// @fnv 0x00c37fc0
void FUN_00c37fc0_shell::FUN_00c37fc0(class NiStream& aStream)
{
    FUN_00c4f9f0_shell::FUN_00c4f9f0(aStream);
    unk0C.LoadBinary(aStream);
    unk18.LoadBinary(aStream);
}
}  // namespace fnv_00c37fc0

class NiStream;
struct NiColor
{
    float r, g, b;
    void SaveBinary(NiStream&);
};
struct FUN_00c38050_Holder
{
    char _pad[12];
    NiColor c1;
    NiColor c2;
    void FUN_00c4fa60(NiStream&);
    void FUN_00c38050(NiStream&);
};
// @fnv 0x00c38050
void FUN_00c38050_Holder::FUN_00c38050(NiStream& aStream)
{
    FUN_00c4fa60(aStream);
    c1.SaveBinary(aStream);
    c2.SaveBinary(aStream);
}

namespace fnv_00c389e0 {
struct Pt
{
    float Length() const;
};
struct Vec3
{
    float x;
    float y;
    float z;
};
struct Vec4
{
    Vec3 v;
    float w;
};
struct BSMultiBoundAABB
{
    char pad0[12];
    Vec3 v;
    Pt pt;
    void FUN_00c389e0(Vec4* p);
};
// @fnv 0x00c389e0
void BSMultiBoundAABB::FUN_00c389e0(Vec4* apOut)
{
    int pad;
    {
        float len = pt.Length();
        apOut->v = v;
        apOut->w = len;
    }
}
}  // namespace fnv_00c389e0

namespace fnv_00c4f9b0 {
struct NiObject
{
    void CopyMembersStream(unsigned int, void*);
    int _pad0;
    int _pad4;
    int m08;
};
struct FUN_00c4f9b0_class : NiObject
{
    void CopyMembersStreamWithField(NiObject*, void*);
};
// Calls NiObject::CopyMembersStream on pDest with pArg, then copies m08 into pDest->m08.
// @fnv 0x00c4f9b0
void FUN_00c4f9b0_class::CopyMembersStreamWithField(NiObject* pDest, void* pArg)
{
    int tmp;
    NiObject::CopyMembersStream((unsigned int)pDest, pArg);
    tmp = m08;
    pDest->m08 = tmp;
}
}  // namespace fnv_00c4f9b0

struct TCEq
{
    bool IsSameAs(class NiObject*);
    bool FUN_00c4fa80(class NiObject*);
};
// @fnv 0x00c4fa80
bool TCEq::FUN_00c4fa80(class NiObject* apObject)
{
    bool result = IsSameAs(apObject);
    return result;
}

namespace fnv_00c4fad0 {
struct NiRefObject
{
    virtual ~NiRefObject();
};
void __cdecl _delete(void*, unsigned int);
struct FUN_00c4fad0_host : NiRefObject
{
    void* FUN_00c4fad0(unsigned int);
};
// Destructs the NiRefObject base and, when flags has bit 0 set, frees this with _delete, returning this.
// @fnv 0x00c4fad0
void* FUN_00c4fad0_host::FUN_00c4fad0(unsigned int flags)
{
    this->NiRefObject::~NiRefObject();
    if (flags & 1)
        _delete(this, 12);
    return this;
}
}  // namespace fnv_00c4fad0

namespace fnv_00c4fc10 {
class NiStream;
struct NiColor
{
    void LoadBinary(NiStream&);
};
struct FUN_00c4f9f0_shell
{
    void FUN_00c4f9f0(NiStream&);
};
template <typename T> void ReadBinaryValue(NiStream&, T&);
struct FUN_00c4fc10_shell
{
    void FUN_00c4fc10(NiStream&);
};
// @fnv 0x00c4fc10
void FUN_00c4fc10_shell::FUN_00c4fc10(NiStream& stream)
{
    ((FUN_00c4f9f0_shell*)this)->FUN_00c4f9f0(stream);
    ((NiColor*)((char*)this + 0xC))->LoadBinary(stream);
    ReadBinaryValue<unsigned int>(stream, *(unsigned int*)((char*)this + 0x18));
}
}  // namespace fnv_00c4fc10

namespace fnv_00c4fc70 {
struct FUN_00c38020_shell
{
    unsigned char FUN_00c4fa30(int);
    unsigned char FUN_00c4fc70(int);
};
// Returns 1 if FUN_00c4fa30 returns nonzero for a, otherwise returns 0.
// @fnv 0x00c4fc70
unsigned char FUN_00c38020_shell::FUN_00c4fc70(int a)
{
    if (!FUN_00c4fa30(a))
        return 0;
    return 1;
}
}  // namespace fnv_00c4fc70

namespace fnv_00c4fca0 {
class NiStream;
struct NiColor
{
    float r;
    float g;
    float b;
    void SaveBinary(NiStream&);
};
struct Holder60
{
    void FUN_00c4fa60(NiStream&);
};
void __cdecl CallAnimCallback(NiStream&, void*);
struct FUN_00c4fca0_This
{
    char _pad[12];
    NiColor _c;
    int _f18;
    void SaveToStream(NiStream&);
};
// @fnv 0x00c4fca0
void FUN_00c4fca0_This::SaveToStream(NiStream& s)
{
    ((Holder60*)this)->FUN_00c4fa60(s);
    _c.SaveBinary(s);
    CallAnimCallback(s, &_f18);
}
}  // namespace fnv_00c4fca0

extern char const* const g_01202818_arg1;

struct FUN_004a7020_shell
{
    char const* const* __thiscall FUN_004a7020();
};

// @fnv 0x004a7020
char const* const* __thiscall FUN_004a7020_shell::FUN_004a7020()
{
    return &g_01202818_arg1;
}

namespace fnv_004a7130 {
struct BSMultiBoundSphere
{
    void DestroyBase();
    void FUN_004a7130();
};

// @fnv 0x004a7130
void BSMultiBoundSphere::FUN_004a7130()
{
    DestroyBase();
}
}  // namespace fnv_004a7130

namespace fnv_004a7830 {
struct Flt
{
    operator unsigned int();
};
struct BGSPrimitiveSphere : NiGeometry
{
    BGSPrimitiveSphere();
    RgbaColor m_kRgbaColor;
    unsigned int m_uiValue1;
    void FUN_004a7830(RgbaColor&);
};
// @fnv 0x004a7830
void BGSPrimitiveSphere::FUN_004a7830(RgbaColor& apTextColor)
{
    *(RgbaColor*)((char*)this + 8) = apTextColor;
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x24)->operator unsigned int())
    {
        NiGeometryData* pgeomdata =
            reinterpret_cast<NiGeometry*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x24)->operator unsigned int())
                ->FUN_005495f0();
        RgbaColor* pcolors = pgeomdata->GetColors();
        int i2 = 0;
        for (; i2 < 112; ++i2)
            pcolors[i2] = *(RgbaColor*)((char*)this + 8);
        pgeomdata->SetDirtyFlags(4);
    }
}
}  // namespace fnv_004a7830

extern "C" void* g_01203108;

struct FUN_004a7b90_shell
{
    void* __thiscall GetGlobalPointer();
};

// @fnv 0x004a7b90
void* __thiscall FUN_004a7b90_shell::GetGlobalPointer()
{
    return &g_01203108;
}

namespace fnv_004a7c20 {
struct FUN_004a7090
{
    ~FUN_004a7090();
};

struct FUN_004a7c20_shell : FUN_004a7090
{
    void DestroyBase();
};

// @fnv 0x004a7c20
void FUN_004a7c20_shell::DestroyBase()
{
    FUN_004a7090::~FUN_004a7090();
}
}  // namespace fnv_004a7c20

struct FUN_00c36430_shell
{
    void FUN_00c38000(int);
    void FUN_00c36430(int a);
};

// @fnv 0x00c36430
void FUN_00c36430_shell::FUN_00c36430(int a)
{
    FUN_00c38000(a);
}

struct FUN_00c38000_shell
{
    void FUN_00c4fa10(int);
    void FUN_00c38000(int a);
};

// @fnv 0x00c38000
void FUN_00c38000_shell::FUN_00c38000(int a)
{
    FUN_00c4fa10(a);
}

struct FUN_00c4f9a0_shell
{
    void* GetSelf(void* a);
};

// @fnv 0x00c4f9a0
void* FUN_00c4f9a0_shell::GetSelf(void* apUnused)
{
    return this;
}

struct FUN_00c4fab0_shell
{
    void __thiscall AppendCameraPathEntries(int);
    void __thiscall FUN_00c4fab0(int a);
};

// @fnv 0x00c4fab0
void __thiscall FUN_00c4fab0_shell::FUN_00c4fab0(int a)
{
    AppendCameraPathEntries(a);
}

struct FUN_00c4fa10_shell
{
    void __thiscall FUN_00c4fa10(int);
    void __thiscall FUN_00c4fc50(int a);
};
// @fnv 0x00c4fc50
void __thiscall FUN_00c4fa10_shell::FUN_00c4fc50(int a)
{
    FUN_00c4fa10(a);
}

struct FUN_00c50370_shell
{
    void FUN_00c50370(int a, int b, int c, int d, int e, int f);
};

// @fnv 0x00c50370
void FUN_00c50370_shell::FUN_00c50370(int a, int b, int c, int d, int e, int f)
{}

extern float _DAT_010162c0;

struct RgbaColor;

struct NiPoint2_helper : public NiPoint2
{
    NiPoint2_helper(float, float);
    NiPoint2 operator*(float) const;
};

struct NiPoint3_helper : public NiPoint3
{
    NiPoint3 operator*(float) const;
};

void* __cdecl FUN_004a4f80(NiPoint2*, RgbaColor*);
void* __cdecl CreatePrimitiveBox(NiPoint3*, RgbaColor*);
void* __cdecl FUN_004a5100(float, RgbaColor*);

// @fnv 0x004a4e90
void* __cdecl FUN_004a4e90(int eType, NiPoint3* apPoint, RgbaColor* apTextColor)
{
    switch (eType)
    {
    case 3: {
        NiPoint2 extents = NiPoint2_helper(apPoint->x, apPoint->z) * _DAT_010162c0;
        return FUN_004a4f80(&extents, apTextColor);
    }
    case 1: {
        NiPoint3 extents = *(NiPoint3_helper*)apPoint * _DAT_010162c0;
        return CreatePrimitiveBox(&extents, apTextColor);
    }
    case 2:
        return FUN_004a5100(apPoint->x, apTextColor);
    default:
        return 0;
    }
}

void __fastcall FUN_00c4f980(void*);
struct FUN_004a6fc0_Pt
{
    float x;
    float y;
    float z;
};
struct FUN_004a6fc0
{
    const char* f00;
    char pad[8];
    FUN_004a6fc0_Pt p0c;
    FUN_004a6fc0_Pt p18;
    FUN_004a6fc0(const FUN_004a6fc0_Pt&, const FUN_004a6fc0_Pt&);
};
// Initializes the object via FUN_00c4f980, sets f00 to a string literal, and copies the two point arguments into p0c and p18.
// @fnv 0x004a6fc0
FUN_004a6fc0::FUN_004a6fc0(const FUN_004a6fc0_Pt& aPoint1, const FUN_004a6fc0_Pt& aPoint2)
{
    FUN_00c4f980(this);
    f00 = "`pJ";
    p0c = aPoint1;
    p18 = aPoint2;
}

extern int DAT_0101e9a4;
struct Data9
{
    int v[9];
};
struct BaseFake
{
    int pad[9];
    void FUN_004a6fc0(int a, int b);
};
struct MyHolder : BaseFake
{
    Data9 d;
    MyHolder* FUN_004a70b0(int a, int b, const Data9& c);
};
// Calls FUN_004a6fc0 with a and b, sets the vtable pointer to DAT_0101e9a4, copies c into d, and returns this.
// @fnv 0x004a70b0
MyHolder* MyHolder::FUN_004a70b0(int aiArg1, int aiArg2, const Data9& arData)
{
    FUN_004a6fc0(aiArg1, aiArg2);
    *(int*)this = (int)&DAT_0101e9a4;
    d = arData;
    return this;
}

struct Holder
{
    char _pad[0x24];
    struct Nine
    {
        int v[9];
    } fld;
    void FUN_00c37f70(Holder*, int);
    void FUN_00c363c0(Holder*, int);
};
// Calls FUN_00c37f70 on the passed Holder and then copies this object's fld into it.
// @fnv 0x00c363c0
void Holder::FUN_00c363c0(Holder* apTarget, int b)
{
    FUN_00c37f70(apTarget, b);
    apTarget->fld = fld;
}

struct Mat364
{
    char d[36];
    bool __thiscall _Call_4d9ae0(const Mat364&) const;
};
struct Obj364
{
    char pad[36];
    Mat364 m;
    bool __thiscall FUN_00c38090(Obj364*);
    bool __thiscall FUN_00c364b0(Obj364*);
};
// Calls FUN_00c38090 on other; if it returns true, also compares m with other's m via _Call_4d9ae0 and returns that result.
// @fnv 0x00c364b0
bool __thiscall Obj364::FUN_00c364b0(Obj364* other)
{
    bool ret = FUN_00c38090(other);
    if (ret)
    {
        Obj364* p = other;
        ret = m._Call_4d9ae0(p->m);
    }
    return ret;
}

struct D12_00c37f70
{
    int x, y, z;
};
struct A00c37f70
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
    virtual void vm(void* p);
    char _04[20];
    D12_00c37f70 d;
};
struct C00c37f70
{
    char _00[12];
    int _0C;
    char _10[8];
    D12_00c37f70 d;
    void CopyMembersStreamWithField(A00c37f70* a, int b);
    void FUN_00c37f70(A00c37f70* a, int b);
};
// Calls CopyMembersStreamWithField, then passes &_0C to a->vm and copies d into a->d.
// @fnv 0x00c37f70
void C00c37f70::FUN_00c37f70(A00c37f70* apTarget, int b)
{
    CopyMembersStreamWithField(apTarget, b);
    apTarget->vm((void*)&_0C);
    apTarget->d = d;
}

struct S_C4F420
{
    char _pad[0xFC];
    int m_fc;
    int m_100;
    void CopyFields(S_C4F420* a, int b);
};
// Copies m_fc and m_100 from this object into the object pointed to by a.
// @fnv 0x00c4f420
void S_C4F420::CopyFields(S_C4F420* apTarget, int aiUnused)
{
    apTarget->m_fc = this->m_fc;
    apTarget->m_100 = this->m_100;
}

struct Shell
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
    virtual void Real(int*);
    char _pad0[8];
    int _m0C;
    char _pad1[8];
    float _m18;
    void CopyMembersStreamWithField(Shell*, int);
    void FUN_00c4fbc0(Shell*, int);
};
// Calls CopyMembersStreamWithField with a2, invokes Real on _m0C, then reads and rewrites _m18 with its own value.
// @fnv 0x00c4fbc0
void Shell::FUN_00c4fbc0(Shell* a1, int a2)
{
    CopyMembersStreamWithField(a1, a2);
    a1->Real(&_m0C);
    float f = _m18;
    a1->_m18 = f;
}

struct V00c50330
{
    float x;
    float y;
    float z;
};
struct O00c50330
{
    V00c50330 v;
    float w;
};
struct H00c50330
{
    char pad[12];
    V00c50330 v;
    float w;
    void CopyTo(O00c50330* p);
};
// Copies the stored vector and scalar into the given output structure.
// @fnv 0x00c50330
void H00c50330::CopyTo(O00c50330* pOut)
{
    float f = w;
    pOut->v = v;
    pOut->w = f;
}

struct FUN_00c4fb10_shell
{
    char m0[0x1c];
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00c4fb10_shell();
};
// Allocates and constructs a new FUN_00c4fb10_shell object, returning the pointer.
// @fnv 0x00c4fdb0
FUN_00c4fb10_shell* FUN_00c4fdb0()
{
    return new FUN_00c4fb10_shell;
}

namespace fnv_004a5100 {
struct FUN_004a5100
{
    virtual void v0();
    virtual void v1(int);
    virtual void v2(int);
    char pad[0x30];
    FUN_004a5100();
    virtual ~FUN_004a5100();
    void SetRadius(float f);
};
// Allocates a FUN_004a5100, calls v2(a) and SetRadius(f), sets the field at offset 4 to 2, and returns it.
// @fnv 0x004a5100
FUN_004a5100* FUN_004a5100_create(float afValue, int aiArg)
{
    FUN_004a5100* p = new FUN_004a5100;
    p->v2(aiArg);
    p->SetRadius(afValue);
    *(int*)((char*)p + 4) = 2;
    return p;
}
}  // namespace fnv_004a5100

namespace fnv_004a5300 {
class GO
{
  public:
    void operator=(void*);
    operator unsigned int() const;
};

struct A51BF0Base
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_004a5300_shell
{
    unsigned char m_unk_00[0x2C];
    GO m_go;

    void CreatePlaneFadeNode();
};

// @fnv 0x004a5300
void FUN_004a5300_shell::CreatePlaneFadeNode()
{
    m_go = new BSFadeNode;
    reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(m_go))->SetName(NiFixedString("Plane"));
    reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(m_go))->UpdateSceneObject();
}
}  // namespace fnv_004a5300

namespace fnv_004a6150 {
struct NiPoint2
{
    float x;
    float y;

    NiPoint2(float, float);
};

struct NiPoint3Access
{
    static NiPoint3 const ZERO;
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct BSPortal : A51BF0Base
{
    char data[0x108];

    BSPortal(NiPoint3 const&, NiPoint2*, char*);
};

struct FUN_004a6150_shell
{
    BSPortal* CreateBSPortal();
};

extern char DAT_011a9448;
extern int _data_011c16bc;

// Allocates a BSPortal using the zero point, a NiPoint2 built from the floats at this+0x18 and this+0x20, and DAT_011a9448, then returns it.
// @fnv 0x004a6150
BSPortal* FUN_004a6150_shell::CreateBSPortal()
{
    return new BSPortal(NiPoint3Access::ZERO,
                        &NiPoint2(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x18),
                                  *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x20)),
                        &DAT_011a9448);
}
}  // namespace fnv_004a6150

namespace fnv_00c38220 {
struct FUN_00c4fab0_shell
{
    void FUN_00c4fab0(int);
};

struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(unsigned int const&);
};

struct NiPoint3_FUN_00a59af0_helper
{
    char* FUN_00a59af0(char const*);
};

void* _FUN_00a7d330(char const*);

extern char const* const g_01202818_arg1;

struct FUN_00c38220_shell : public FUN_00c4fab0_shell
{
    void AddPropertyNames(NiTPrimitiveArray_unsigned_int_*);
};

// Calls the base method, then appends the property id and the "Center" and "Half Extents" names to the array.
// @fnv 0x00c38220
void FUN_00c38220_shell::AddPropertyNames(NiTPrimitiveArray_unsigned_int_* array)
{
    char unused[0x20];
    char* denter;

    FUN_00c4fab0_shell::FUN_00c4fab0(reinterpret_cast<int>(array));

    char const* volatile property = g_01202818_arg1;
    void* propertyId = _FUN_00a7d330(property);
    array->AddFirstEmpty(reinterpret_cast<unsigned int const&>(propertyId));

    denter =
        reinterpret_cast<NiPoint3_FUN_00a59af0_helper*>(reinterpret_cast<char*>(this) + 0x0c)->FUN_00a59af0("Center");
    array->AddFirstEmpty(reinterpret_cast<unsigned int const&>(denter));

    char* halfExtents = reinterpret_cast<NiPoint3_FUN_00a59af0_helper*>(reinterpret_cast<char*>(this) + 0x18)
                            ->FUN_00a59af0("Half Extents");
    array->AddFirstEmpty(reinterpret_cast<unsigned int const&>(halfExtents));
}
}  // namespace fnv_00c38220

namespace fnv_00c4f620 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    virtual ~A51BF0Base();
};

struct FUN_00c4f460 : public A51BF0Base
{
    unsigned char pad[0xc0];

    FUN_00c4f460(int);
};

struct FUN_00c4f6c0_shell
{
    void FUN_00c4f6c0(int, int);
    FUN_00c4f460* FUN_00c4f620(int);
};

// Allocates a FUN_00c4f460 using the int at this+0xc0, passes it and arg to FUN_00c4f6c0, and returns the new object.
// @fnv 0x00c4f620
FUN_00c4f460* FUN_00c4f6c0_shell::FUN_00c4f620(int arg)
{
    FUN_00c4f460* object = new FUN_00c4f460(*(int*)((char*)this + 0xc0));

    this->FUN_00c4f6c0((int)object, arg);

    return object;
}
}  // namespace fnv_00c4f620

class Base_b4940
{
  public:
    virtual ~Base_b4940();
    unsigned int m_04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Base_b4940();
};

class Ptr_b4940
{
  public:
    void* m_pObject;
    Ptr_b4940(void* aObject);
};

class FUN_004a5280 : public Base_b4940
{
  public:
    virtual ~FUN_004a5280();
    Ptr_b4940 m_24;
    unsigned int unk28;
    Ptr_b4940 m_2c;
    unsigned int unk30;

    FUN_004a5280();
};

// Initializes the base, sets m_04 to 3, and constructs the two pointer members m_24 and m_2c with null.
// @fnv 0x004a5280
FUN_004a5280::FUN_004a5280() : Base_b4940(), m_24(0), m_2c(0)
{
    m_04 = 3;
}

struct NiAVObjB8_shell
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void UpdateB8(NiUpdateData&);
};
struct FUN_004a55a0_shell : public BGSPrimitiveBox
{
    void UpdateBoxGeometry(NiPoint3& akRadii);
};

// Takes the absolute X/Z of a point, zeroes Y, writes the 8 or 16 box vertices into the geometry data and updates the model bound and node.
// @fnv 0x004a55a0
void FUN_004a55a0_shell::UpdateBoxGeometry(NiPoint3& aExtents)
{
    aExtents[0] = std::abs(aExtents[0]);
    aExtents[1] = 0.0f;
    aExtents[2] = std::abs(aExtents[2]);
    m_kRadii = aExtents;
    if (m_kGeometry)
    {
        NiGeometryData* dataB = m_kGeometry->FUN_005495f0();
        NiPoint3* verts = dataB->GetVertices();
        verts[0] = NiPoint3(-m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        verts[1] = NiPoint3(m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        verts[2] = NiPoint3(m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        verts[3] = NiPoint3(-m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        verts[4] = NiPoint3(-m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        verts[5] = NiPoint3(m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        verts[6] = NiPoint3(m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        verts[7] = NiPoint3(-m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        dataB->SetDirtyFlags(1);
    }
    if (m_kLines)
    {
        NiGeometryData* data2 = m_kLines->FUN_005495f0();
        NiPoint3* aVerts2 = data2->GetVertices();
        aVerts2[0] = NiPoint3(-m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        aVerts2[1] = NiPoint3(m_kRadii[0], m_kRadii[1], m_kRadii[2]);
        aVerts2[2] = NiPoint3(m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        aVerts2[3] = NiPoint3(-m_kRadii[0], -m_kRadii[1], m_kRadii[2]);
        aVerts2[4] = aVerts2[0];
        aVerts2[5] = NiPoint3(-m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        aVerts2[6] = NiPoint3(-m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        aVerts2[7] = NiPoint3(m_kRadii[0], -m_kRadii[1], -m_kRadii[2]);
        aVerts2[8] = NiPoint3(m_kRadii[0], m_kRadii[1], -m_kRadii[2]);
        aVerts2[9] = aVerts2[5];
        aVerts2[10] = aVerts2[3];
        aVerts2[11] = aVerts2[6];
        aVerts2[12] = aVerts2[1];
        aVerts2[13] = aVerts2[8];
        aVerts2[14] = aVerts2[2];
        aVerts2[15] = aVerts2[7];
        data2->SetDirtyFlags(1);
    }
    NiUpdateData updateData3(0.0f, false, false);
    if (m_pController)
    {
        float fMax3 = aExtents.x;
        if (aExtents.y > aExtents.x && aExtents.y > aExtents.z)
            fMax3 = aExtents.y;
        if (aExtents.z > aExtents.y && aExtents.z > aExtents.x)
            fMax3 = aExtents.z;
        NiBound bound2;
        bound2.SetCenterAndRadius(NiPoint3::ZERO, fMax3);
        m_kGeometry->SetModelBound(bound2);
        m_pController->Update(updateData3);
        ((NiAVObjB8_shell*)(BSFadeNode*)m_pController)->UpdateB8(updateData3);
        m_kGeometry->UpdateSceneObject();
        m_pController->UpdateWorldBound();
    }
}

struct BGSPrimBase
{
    BGSPrimBase();
    virtual ~BGSPrimBase();
    unsigned int unk04;
};

struct BGSPrimPair
{
    unsigned int m_00;
    unsigned int m_04;
};

struct BGSPrimMatrix
{
    unsigned int m_00[9];
};

struct BGSPrimSub
{
    BGSPrimSub();
    unsigned int unk00[25];
};

struct BGSPrimElem
{
    BGSPrimElem();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

class FUN_004a5ff0_cls : public BGSPrimBase
{
  public:
    NiPoint3 m_kCenter;
    BGSPrimPair m_pair;
    BGSPrimMatrix m_mat;
    unsigned int m_40;
    BGSPrimSub m_sub;
    BGSPrimElem m_aiIndexedValues[4];
    BGSPrimElem m_kPrimitiveElement;
    unsigned char m_e4;
    unsigned char m_e5;
    unsigned char unkE6[4];
    unsigned char m_ea;

    FUN_004a5ff0_cls(NiPoint3& a1, BGSPrimPair& a2, BGSPrimMatrix& a3);
    virtual ~FUN_004a5ff0_cls();
};

// Constructs the primitive from a center point, pair and matrix, and initializes m_e4, m_e5, m_ea to 1 and m_40 to 0.
// @fnv 0x004a5ff0
FUN_004a5ff0_cls::FUN_004a5ff0_cls(NiPoint3& akCenter, BGSPrimPair& akPair, BGSPrimMatrix& akMatrix)
    : m_kCenter(akCenter), m_pair(akPair), m_mat(akMatrix)
{
    m_e4 = 1;
    m_e5 = 1;
    m_40 = 0;
    m_ea = 1;
}

class Base_b4579
{
  public:
    virtual ~Base_b4579();
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
    Base_b4579(int aA, int aB, int aC);
};

class Sub_b4579
{
  public:
    unsigned int unk00;
    Sub_b4579(int aValue);
    ~Sub_b4579();
    void Ping(int aValue);
};

class FUN_004a61f0 : public Base_b4579
{
  public:
    virtual ~FUN_004a61f0();
    unsigned int m_40;
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
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned char m_e4;
    unsigned char m_e5;
    unsigned short unke6;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int m_fc;
    unsigned int m_100;
    Sub_b4579 m_104;

    FUN_004a61f0(int aA, int aB, int aC);
};

// Initializes the base with aA, aB, aC, sets m_e4/m_e5 to 1, zeroes m_40, m_100, m_fc, and constructs m_104 with 0 then calls Ping(0).
// @fnv 0x004a61f0
FUN_004a61f0::FUN_004a61f0(int aA, int aB, int aC) : Base_b4579(aA, aB, aC), m_104(0)
{
    m_e4 = 1;
    m_e5 = 1;
    m_40 = 0;
    m_100 = 0;
    m_fc = 0;
    m_104.Ping(0);
}

struct BoundMatrix3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    BoundMatrix3();
    void SetRotationFromEulerXYZ(float x, float y, float z);
    static const BoundMatrix3 IDENTITY;
};

struct BoundBase : public NiMemObject
{
};

struct BoundOBB : public BoundBase
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
    BoundOBB(const NiPoint3& akStart, const NiPoint3& kExtents, const BoundMatrix3& kRot);
    void SetRotation(const BoundMatrix3& kRot);
};

struct BoundAABB : public BoundBase
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
    BoundAABB(const NiPoint3& akStart, const NiPoint3& kExtents);
};

struct BoundOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiPoint3 kExtents;
    BoundBase* CreateBound(NiPoint3* pAngles);
};

// Creates an OBB rotated by pAngles when any angle exceeds 0.01, otherwise creates an axis-aligned AABB, both from kExtents.
// @fnv 0x004a6e30
BoundBase* BoundOwner::CreateBound(NiPoint3* pAngles)
{
    bool bRotated = false;
    if (std::abs(pAngles->x) > (double)0.01f)
        bRotated = true;
    if (std::abs(pAngles->y) > (double)0.01f)
        bRotated = true;
    if (std::abs(pAngles->z) > (double)0.01f)
        bRotated = true;
    if (bRotated)
    {
        BoundOBB* pOBB = new BoundOBB(NiPoint3::ZERO, kExtents, BoundMatrix3::IDENTITY);
        {
            BoundMatrix3 kRot;
            kRot.SetRotationFromEulerXYZ(pAngles->x, pAngles->y, pAngles->z);
            pOBB->SetRotation(kRot);
        }
        return pOBB;
    }
    else
    {
        return new BoundAABB(NiPoint3::ZERO, kExtents);
    }
}

struct FUN_004a7aa0_color
{
    float x, y, z;
    FUN_004a7aa0_color(float, float, float, float);
};

struct FUN_004a7aa0_obj
{
    int _00;
    int _04;
    int _08;
    FUN_004a7aa0_color mColor;
    float mRadius;
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_004a7aa0_obj(const FUN_004a7aa0_color& c);
};

struct FUN_004a7aa0_cls
{
    char _00[0x18];
    float m_f18;
    void* FUN_004a7aa0(int a1);
};

// Allocates a new object constructed from a color built with the class's m_f18 value and returns it.
// @fnv 0x004a7aa0
void* FUN_004a7aa0_cls::FUN_004a7aa0(int aiUnused)
{
    return new FUN_004a7aa0_obj(FUN_004a7aa0_color(0.0f, 0.0f, 0.0f, m_f18));
}

class BC36500Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    BC36500Object();
    virtual ~BC36500Object();

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
};

// Allocates and constructs a new BC36500Object, returning the pointer.
// @fnv 0x00c36500
BC36500Object* __cdecl CreateBC36500Object()
{
    return new BC36500Object;
}

extern "C" int _NiPoint3_ZERO;

class C37E00Point3
{
  public:
    float Dot(const C37E00Point3& kPoint) const;

    float x;
    float y;
    float z;
};

struct C37E00Matrix3
{
    float m_afEntries[3][3];
};

struct C37E00Plane
{
    C37E00Point3 m_kPlaneNormal;
    float m_fPlaneConstant;
};

class C37E00Box
{
  public:
    int unk00;
    int unk04;
    int unk08;
    C37E00Point3 m_kCenter;
    int unk18;
    int unk1C;
    int unk20;
    C37E00Matrix3 m_kRotate;

    void GetPlanes(C37E00Plane* pkPlanes);
};

// Builds three planes from the columns of m_kRotate, setting each plane normal to a matrix column and its constant to the dot product with m_kCenter.
// @fnv 0x00c37e00
void C37E00Box::GetPlanes(C37E00Plane* pkPlanes)
{
    for (int i = 0; i < 3; i++)
    {
        C37E00Point3 kColumn = reinterpret_cast<const C37E00Point3&>(_NiPoint3_ZERO);
        const C37E00Matrix3& kMatrix = m_kRotate;
        kColumn.x = kMatrix.m_afEntries[0][i];
        kColumn.y = kMatrix.m_afEntries[1][i];
        kColumn.z = kMatrix.m_afEntries[2][i];
        pkPlanes[i].m_kPlaneNormal = kColumn;
        float fConstant = kColumn.Dot(m_kCenter);
        pkPlanes[i].m_fPlaneConstant = fConstant;
    }
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct NewBodyCls
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    NewBodyCls();
};

// Allocates and constructs a NewBodyCls object, returning the new instance.
// @fnv 0x00c381a0
NewBodyCls* __cdecl CreateNewBodyCls()
{
    return new NewBodyCls();
}

struct Vec12
{
    float x;
    float y;
    float z;
};

struct ProbeElem16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct ProbeSet
{
    ProbeElem16 elems[6];
    unsigned int mask;
};

struct FUN_0049da80_shell
{
    int __thiscall ClassifyPoint(Vec12* p);
};

struct FUN_00c38920_cls
{
    void __thiscall FUN_00c39270(Vec12* a);
    bool __thiscall FUN_00c38920(ProbeSet* other);
};

// Builds eight box points, then for each masked element tests all eight points and returns false if any test returns 2, otherwise true.
// @fnv 0x00c38920
bool __thiscall FUN_00c38920_cls::FUN_00c38920(ProbeSet* pProbeSet)
{
    Vec12 boxPts[8];
    int i;
    int j;
    {
        int n = 8;
        Vec12* p = boxPts;
        unsigned int scratch[90];
        int unkTail;
        while (--n >= 0)
        {
            p++;
        }
    }
    FUN_00c39270(boxPts);
    for (i = 0; i < 6; i++)
    {
        if (bool(pProbeSet->mask & (1u << i)))
        {
            for (j = 0; j < 8; j++)
            {
                if (((FUN_0049da80_shell*)&pProbeSet->elems[i])->ClassifyPoint(&boxPts[j]) == 2)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

struct FUN_00c49850_cls
{
    void FUN_00c49850();
};

struct FUN_00a59e00_cls
{
    void FUN_00a59e00(void* pObj);
};

struct FUN_00c4f6d0_sub
{
    int unk00;
    FUN_00a59e00_cls** unk04;
    unsigned short unk08;
    unsigned short unk0A;
};

struct FUN_00c4f6d0_arg
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
    FUN_00c49850_cls* m_pThing;
};

struct FUN_00c4f6d0_cls
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
    FUN_00c4f6d0_sub m_sub;
    unsigned short m_uFlag;
    unsigned short unkAA;
    FUN_00c49850_cls* m_pEntryObject;

    void FUN_00c4f6d0(FUN_00c4f6d0_arg* pObj);
};

// @fnv 0x00c4f6d0
void FUN_00c4f6d0_cls::FUN_00c4f6d0(FUN_00c4f6d0_arg* pObj)
{
    FUN_00c4f6d0_sub* tgtC;
    FUN_00c4f6d0_arg* subB = 0;
    FUN_00c49850_cls* savA;
    FUN_00c49850_cls* pSwapE;
    unsigned int cntB;
    unsigned int idxD;
    FUN_00a59e00_cls** pSlotE;
    FUN_00a59e00_cls* pElemA;
    if (m_uFlag == 0)
    {
    }
    else
    {
        subB = pObj;
        savA = subB->m_pThing;
        pSwapE = m_pEntryObject;
        subB->m_pThing = pSwapE;
        if (m_pEntryObject != 0)
        {
            m_pEntryObject->FUN_00c49850();
        }
        tgtC = &this->m_sub;
        cntB = tgtC->unk0A;
        for (idxD = 0; idxD < cntB; idxD++)
        {
            pSlotE = &tgtC->unk04[idxD];
            pElemA = *pSlotE;
            if (pElemA != 0)
            {
                pElemA->FUN_00a59e00(pObj);
            }
        }
        subB->m_pThing = savA;
    }
}

int __fastcall FUN_00c4f860(int value);

struct FUN_00c4f7b0_scratch
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};

struct FUN_00c4f7b0_cls
{
    char _pad[0xfc];
    int m_fc;
    int m_100;
    int FUN_00c4f7b0();
};

// Returns whether either of the two fields m_fc or m_100 is nonzero and passes FUN_00c4f860 with result 1.
// @fnv 0x00c4f7b0
int FUN_00c4f7b0_cls::FUN_00c4f7b0()
{
    FUN_00c4f7b0_scratch scratch;
    int result5 = 0;
    int v = m_fc;
    if (v != 0)
    {
        result5 = (FUN_00c4f860(v) == 1);
    }
    v = m_100;
    if (v != 0)
    {
        result5 |= (FUN_00c4f860(v) == 1);
    }
    return result5;
}

struct FUN_00a5d3a0_shell
{
    virtual void v00();
    FUN_00a5d3a0_shell();
};

struct FUN_00c4f980 : public FUN_00a5d3a0_shell
{
    FUN_00c4f980();
};

FUN_00a5d3a0_shell::FUN_00a5d3a0_shell()
{}

// @fnv 0x00c4f980
FUN_00c4f980::FUN_00c4f980()
{}

struct FUN_00c4fce0_cls
{
    char _00[0xc];
    NiPoint3 m_pos;
    float m_18;
    bool FUN_00c4fa80(void* other);
    bool Equals(FUN_00c4fce0_cls* other);
};

// Compares this object with another: first calls FUN_00c4fa80, then checks m_pos x/y/z and m_18 are equal, returning the combined result.
// @fnv 0x00c4fce0
bool FUN_00c4fce0_cls::Equals(FUN_00c4fce0_cls* other)
{
    bool r6 = FUN_00c4fa80(other);
    if (r6)
    {
        FUN_00c4fce0_cls* o4 = other;
        NiPoint3* pb = &o4->m_pos;
        NiPoint3* pa = &m_pos;
        r6 = (pa->x == pb->x && pa->y == pb->y && pa->z == pb->z);
        float t = m_18;
        r6 = r6 & (t == o4->m_18);
    }
    return r6;
}

struct NodeArgB9733
{
    void FUN_0096a610(void** pp);
};

struct NodeSubB9733
{
    char unk00[0xc];
    void* FUN_00a59af0(const char* name);
};

void* FUN_00a7d330(void* g);
void* FUN_00a7d550(const char* name, float value);

extern void* DAT_01203108;

struct FUN_00c4fe30_cls
{
    char unk00[0xc];
    NodeSubB9733 m_sub0c;
    float m_f18;
    void Init(NodeArgB9733* p);
    void InitNode(NodeArgB9733* pNode);
};

// @fnv 0x00c4fe30
void FUN_00c4fe30_cls::InitNode(NodeArgB9733* pNode)
{
    Init(pNode);
    unsigned int data[5];
    unsigned int unk[4];
    void* g = DAT_01203108;
    void* root = FUN_00a7d330(g);
    pNode->FUN_0096a610(&root);
    void* center7 = m_sub0c.FUN_00a59af0("Center");
    pNode->FUN_0096a610(&center7);
    float r = m_f18;
    void* radius = FUN_00a7d550("Radius", r);
    pNode->FUN_0096a610(&radius);
}

struct Point2_construct_shell
{
    float x, y;
    Point2_construct_shell(float width, float height, const void* axis);
};
struct FUN_004a5ff0_shell : FUN_00c335d0
{
    FUN_004a5ff0_shell(const void* type, const Point2_construct_shell& extent);
};
struct FUN_004a5f50_shell : BGSPrimitive
{
    FUN_004a5ff0_shell* CreatePrimitive();
};
extern int g_011a9448;
extern int g_011f426c;

// Allocates a new primitive of type g_011f426c using this primitive's x and z extents and returns it.
// @fnv 0x004a5f50
FUN_004a5ff0_shell* FUN_004a5f50_shell::CreatePrimitive()
{
    return new FUN_004a5ff0_shell(&g_011f426c, Point2_construct_shell(m_kRadii.x, m_kRadii.z, &g_011a9448));
}

struct SphereVertex
{
    double x;
    double y;
    double z;
};
extern SphereVertex DAT_01187ac8[];

struct NiPoint3_ext : public NiPoint3
{
    NiPoint3_ext& operator*=(float);
};

// @fnv 0x004a78e0
void BGSPrimitiveSphere::SetRadius(float radius)
{
    radius = std::abs(radius);
    if (((BGSPrimitive*)this)->m_kGeometry)
    {
        NiGeometryData* pkData5 = ((BGSPrimitive*)this)->m_kGeometry->FUN_005495f0();
        NiPoint3* pkVertices2 = pkData5->GetVertices();
        for (int i = 0; i < 0x70; i++)
        {
            pkVertices2[i].x = DAT_01187ac8[i].x;
            pkVertices2[i].y = DAT_01187ac8[i].y;
            pkVertices2[i].z = DAT_01187ac8[i].z;
            ((NiPoint3_ext*)pkVertices2)[i] *= radius;
        }
        pkData5->SetDirtyFlags(1);
    }
    ((BGSPrimitive*)this)->m_kRadii.x = ((BGSPrimitive*)this)->m_kRadii.y = ((BGSPrimitive*)this)->m_kRadii.z = radius;
    NiUpdateData kUpdateDataTmp(0.0f, false, false);
    if (((BGSPrimitive*)this)->m_pController)
    {
        NiBound kBound;
        kBound.SetCenterAndRadius(NiPoint3(0.0f, 0.0f, 0.0f), radius);
        ((BGSPrimitive*)this)->m_kGeometry->SetModelBound(kBound);
        ((BGSPrimitive*)this)->m_pController->Update(kUpdateDataTmp);
        ((BGSPrimitive*)this)->m_kGeometry->UpdateSceneObject();
        ((BGSPrimitive*)this)->m_pController->UpdateWorldBound();
    }
}

namespace fnv_004a72d0 {
struct SphereVertexColor : public RgbaColor
{
    SphereVertexColor();
};

struct SphereVertexPosition
{
    float x, y, z;
    SphereVertexPosition();
};

class Lines_Standin : public NiLines
{
  public:
    Lines_Standin(unsigned short count, SphereVertexPosition* vertices, void* normals, RgbaColor* colors, void* extra1,
                  void* extra2, void* extra3, unsigned short segments, unsigned int groups, unsigned short* lengths,
                  unsigned short* indices);
    void AttachProperty(void*);
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
};

class BSShaderLightingProperty : public NiMemObject
{
  public:
    BSShaderLightingProperty();
    void FUN_005a8060(unsigned int);
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
};

class NiAlphaProperty : public NiAVObject
{
  public:
    NiAlphaProperty();
    void FUN_0049ed90(bool);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};

template <> class NiPointer<NiAlphaProperty>
{
  public:
    NiAlphaProperty* m_pObject;
    NiPointer(NiAlphaProperty* = 0);
    ~NiPointer();
    operator NiAlphaProperty*() const;
    NiPointer& operator=(NiAlphaProperty*);
};

struct NiPropertyHelper
{
    void FUN_00441130(unsigned int, bool);
};

struct NiGeometryHelper : public NiGeometry
{
    NiPropertyHelper* GetProperty(unsigned int);
};

class BSFadeNodeHelper : public BSFadeNode
{
  public:
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AttachChildInAvailableSlot(NiGeometry*, bool);
};

extern const double gSphereCoordinates[112][3];
void __cdecl FUN_00b57e30(Lines_Standin*, int, int);

class BGSPrimitiveSphere : public BGSPrimitive
{
  public:
    virtual void vfn_04();
    virtual void ApplyColor(RgbaColor&);
    void CreateSphereGeometry();
    void SetRadius(float);
};

// Builds the sphere's line geometry, shader and alpha properties and fade node on first call, otherwise updates radius and color, then updates the fade node.
// @fnv 0x004a72d0
void BGSPrimitiveSphere::CreateSphereGeometry()
{
    if (!m_kGeometry)
    {
        SphereVertexColor* colors5 = new SphereVertexColor[112];
        SphereVertexPosition* positions = new SphereVertexPosition[112];
        unsigned short* indices5 = new unsigned short[112];

        for (int i2 = 0; i2 < 112; ++i2)
        {
            positions[i2].x = (float)gSphereCoordinates[i2][0] * m_kRadii.x;
            positions[i2].y = (float)gSphereCoordinates[i2][1] * m_kRadii.x;
            positions[i2].z = (float)gSphereCoordinates[i2][2] * m_kRadii.x;
            (RgbaColor&)colors5[i2] = Color;
            indices5[i2] = (unsigned short)i2;
        }

        unsigned short* lengths3 = new unsigned short[1];
        lengths3[0] = 112;

        Lines_Standin* lines2 =
            new Lines_Standin(112, positions, 0, (RgbaColor*)colors5, 0, 0, 0, 110, 1, lengths3, indices5);
        BSShaderLightingProperty* prop2 = new BSShaderLightingProperty;
        prop2->FUN_005a8060(33);
        lines2->AttachProperty(prop2);
        FUN_00b57e30(lines2, 0, 0);
        m_kGeometry = lines2;

        NiPointer<NiAlphaProperty> spAlphaProperty2 = new NiAlphaProperty;
        ((NiAlphaProperty*)spAlphaProperty2)->SetName(NiFixedString("primitive: alpha"));
        ((NiAlphaProperty*)spAlphaProperty2)->FUN_0049ed90(true);
        ((Lines_Standin*)(NiGeometry*)m_kGeometry)->AttachProperty((NiAlphaProperty*)spAlphaProperty2);
        ((NiGeometryHelper*)(NiGeometry*)m_kGeometry)->GetProperty(3)->FUN_00441130(32, false);

        m_pController = new BSFadeNode;
        ((BSFadeNodeHelper*)(BSFadeNode*)m_pController)->AttachChildInAvailableSlot(m_kGeometry, true);
        m_pController->SetName(NiFixedString("Sphere"));
        m_pController->UpdateSceneObject();
        m_kGeometry->UpdateSceneObject();
    }
    else
    {
        SetRadius(m_kRadii[0]);
        ApplyColor(Color);
    }

    NiUpdateData updateData3(0.0f, false, false);
    m_pController->Update(updateData3);
}
}  // namespace fnv_004a72d0

struct KVec
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
};

class KPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
};

class KPlanes
{
  public:
    KPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};

struct KSphere
{
    KVec m_kCenter;
    float m_fBoundRadius;
    int Side(KPlane* pPlane);
};

class FUN_00c50210_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    bool WithinFrustum(KPlanes* planes);
};

// @fnv 0x00c50210
bool FUN_00c50210_cls::WithinFrustum(KPlanes* planes)
{
    int iPlaneIndex;
    float fRad = m_fBoundRadius;
    int result;
    KSphere kBound;
    unsigned int iLoop;
    kBound.m_kCenter = *(KVec*)&m_kCenter;
    kBound.m_fBoundRadius = fRad;
    for (iLoop = 0; iLoop < 6; ++iLoop)
    {
        if ((bool)((planes->m_uiActivePlaneMask & (1u << iLoop)) != 0))
        {
            result = kBound.Side(&planes->m_akPlanes[iLoop]);
            if (result == 2)
                return false;
        }
    }
    return true;
}

// Explicit expansion of the geometry accessors used during box mesh construction.
struct PointB
{
    float x, y, z;
    PointB* Difference(PointB* result, const PointB& origin) const;
};
struct ColorB
{
    float r, g, b, a;
};
extern ColorB DAT_011a9be0;
struct DataB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    PointB* vertices;
    int unk24;
    ColorB* colors;
    int unk2c, unk30, unk34, unk38, unk3c;
    bool* flags;
    unsigned short* GetIndices();
};
struct MeshB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    PointB position;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    DataB* data;
};
struct BoxB
{
    int unk00, unk04, unk08;
    PointB position;
    void FillCorners(PointB*);
    void BuildBoxGeometry(MeshB*, MeshB*, ColorB);
};
// Temporary working records used by the mesh builder. Their lifetime does not
// overlap external mesh ownership.
struct BoxBuildContext
{
    MeshB mesh;
    DataB data;
    PointB center, radii;
    ColorB edgeColor, faceColor;
    float selectionBrightness, selectionAlpha;
};
typedef char ContextSizeCheck[sizeof(BoxBuildContext) == 320 ? 1 : -1];
struct CornerTraversalB
{
    int completed;
    int remaining;
};
struct BoundsPairB
{
    PointB center, radii;
};
struct TrianglePointsB
{
    PointB a, b, c;
};
// Fills the line and face meshes with the box's 8 corners: 12 edges and 12 triangles, setting vertices, colors, flags and indices.
// @fnv 0x00c37150
void BoxB::BuildBoxGeometry(MeshB* apLineMesh, MeshB* apFaceMesh, ColorB aFaceColor)
{
    // Locals are declared separately from their first assignment so that the
    // index tables and operation results have independent lifetimes.
    TrianglePointsB scratch3;
    DataB* faceIndexDataS;
    ColorB* pTemp;
    DataB* faceColorData4;
    PointB* faceVertexResultV;
    DataB* faceVertexDataJ;
    BoundsPairB scratch7;
    bool* lineFlagResult8;
    DataB* lineFlagData6;
    ColorB* lineColorResult2;
    DataB* _lineColorDataR;
    PointB* lineVertexResultR;
    DataB* lineVertexData7;
    float nScratch4;
    BoxBuildContext scratchC;
    int remainingE;
    PointB* cursorM2;
    PointB point, point5, pointB, pointC, pointR;
    unsigned short j4;
    int i8;
    PointB cornersInA[8];
    ColorB _white;
    PointB* _vertices;
    unsigned short* indices2;
    unsigned short triangles6[12][3];
    unsigned short edges9[12][2];
    ColorB color9;
    ColorB* colorsT;
    bool* flagsR;
    remainingE = 8;
    cursorM2 = cornersInA;
    while (--remainingE >= 0)
    {
        ++cursorM2;
    }
    FillCorners(cornersInA);
    edges9[0][0] = 0;
    edges9[0][1] = 1;
    edges9[1][0] = 0;
    edges9[1][1] = 2;
    edges9[2][0] = 1;
    edges9[2][1] = 3;
    edges9[3][0] = 3;
    edges9[3][1] = 2;
    edges9[4][0] = 4;
    edges9[4][1] = 5;
    edges9[5][0] = 4;
    edges9[5][1] = 6;
    edges9[6][0] = 5;
    edges9[6][1] = 7;
    edges9[7][0] = 7;
    edges9[7][1] = 6;
    edges9[8][0] = 0;
    edges9[8][1] = 4;
    edges9[9][0] = 1;
    edges9[9][1] = 5;
    edges9[10][0] = 2;
    edges9[10][1] = 6;
    edges9[11][0] = 3;
    edges9[11][1] = 7;
    triangles6[0][0] = 2;
    triangles6[0][1] = 3;
    triangles6[0][2] = 1;
    triangles6[1][0] = 2;
    triangles6[1][1] = 1;
    triangles6[1][2] = 0;
    triangles6[2][0] = 5;
    triangles6[2][1] = 7;
    triangles6[2][2] = 6;
    triangles6[3][0] = 5;
    triangles6[3][1] = 6;
    triangles6[3][2] = 4;
    triangles6[4][0] = 7;
    triangles6[4][1] = 2;
    triangles6[4][2] = 6;
    triangles6[5][0] = 7;
    triangles6[5][1] = 3;
    triangles6[5][2] = 2;
    triangles6[6][0] = 4;
    triangles6[6][1] = 0;
    triangles6[6][2] = 5;
    triangles6[7][0] = 5;
    triangles6[7][1] = 0;
    triangles6[7][2] = 1;
    triangles6[8][0] = 6;
    triangles6[8][1] = 0;
    triangles6[8][2] = 4;
    triangles6[9][0] = 6;
    triangles6[9][1] = 2;
    triangles6[9][2] = 0;
    triangles6[10][0] = 3;
    triangles6[10][1] = 7;
    triangles6[10][2] = 1;
    triangles6[11][0] = 7;
    triangles6[11][1] = 5;
    triangles6[11][2] = 1;
    color9 = aFaceColor;
    _white = DAT_011a9be0;
    lineVertexData7 = apLineMesh->data;
    lineVertexResultR = lineVertexData7->vertices;
    _vertices = lineVertexResultR;
    _lineColorDataR = apLineMesh->data;
    lineColorResult2 = _lineColorDataR->colors;
    colorsT = lineColorResult2;
    lineFlagData6 = apLineMesh->data;
    lineFlagResult8 = lineFlagData6->flags;
    flagsR = lineFlagResult8;
    apLineMesh->position = position;
    for (i8 = 0; i8 < 12; ++i8)
    {
        _vertices[i8 * 2] = *cornersInA[edges9[i8][0]].Difference(&pointR, position);
        colorsT[i8 * 2] = _white;
        _vertices[i8 * 2 + 1] = *cornersInA[edges9[i8][1]].Difference(&pointC, position);
        colorsT[i8 * 2 + 1] = _white;
        flagsR[i8 * 2] = true;
        flagsR[i8 * 2 + 1] = false;
    }
    faceVertexDataJ = apFaceMesh->data;
    faceVertexResultV = faceVertexDataJ->vertices;
    _vertices = faceVertexResultV;
    faceColorData4 = apFaceMesh->data;
    pTemp = faceColorData4->colors;
    colorsT = pTemp;
    faceIndexDataS = apFaceMesh->data;
    indices2 = faceIndexDataS->GetIndices();
    apFaceMesh->position = position;
    for (j4 = 0; j4 < 12; ++j4)
    {
        _vertices[j4 * 3] = *cornersInA[triangles6[j4][0]].Difference(&pointB, position);
        colorsT[j4 * 3] = color9;
        _vertices[j4 * 3 + 1] = *cornersInA[triangles6[j4][1]].Difference(&point5, position);
        colorsT[j4 * 3 + 1] = color9;
        _vertices[j4 * 3 + 2] = *cornersInA[triangles6[j4][2]].Difference(&point, position);
        colorsT[j4 * 3 + 2] = color9;
        indices2[j4 * 3] = j4 * 3;
        indices2[j4 * 3 + 1] = j4 * 3 + 1;
        indices2[j4 * 3 + 2] = j4 * 3 + 2;
    }
}

struct Xform
{
    float a, b, c, d;
    Xform(float, float, float, float);
};
struct ListQ
{
    void *x, *y, *z;
    ListQ();
};
struct SlotQ
{
    int v;
    SlotQ(int);
    ~SlotQ();
    void FUN_0066b0d0(int);
};

struct FUN_004a4ac0
{
    int unk04;
    Xform xform;
    ListQ list;
    SlotQ s24;
    SlotQ s28;
    SlotQ s2c;
    int field30;
    FUN_004a4ac0();
    virtual ~FUN_004a4ac0();
};

// Constructs a FUN_004a4ac0 object, initializing xform to zero, s24, s28, s2c to 0, and field30 to 7.
// @fnv 0x004a4ac0
FUN_004a4ac0::FUN_004a4ac0() : xform(0.0f, 0.0f, 0.0f, 0.0f), s24(0), s28(0), s2c(0)
{
    s24.FUN_0066b0d0(0);
    s2c.FUN_0066b0d0(0);
    s28.FUN_0066b0d0(0);
    field30 = 7;
}

#include <math.h>
struct SphereBoxTest
{
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 m_kCenter;
    NiPoint3 m_kExtents;
    int TestSphereBox(const NiBound& bound);
};
// Tests a sphere against the axis-aligned box m_kCenter/m_kExtents and returns 2 for inside, 1 for intersecting, or 0 for outside.
// @fnv 0x00c382b0
int SphereBoxTest::TestSphereBox(const NiBound& bound)
{
    NiPoint3 p = bound.m_kCenter;
    float cf = bound.m_fBoundRadius;
    bool s = true;
    bool eb = true;
    float f, q, b;
    float c, e, j;
    c = (p.x) - (m_kCenter.x);
    f = (double)(float)fabs((double)c);
    s &= f - (m_kExtents.x - cf) <= 0.0;
    eb &= f - (m_kExtents.x + cf) <= 0.0;
    if (s || eb)
    {
        e = (p.y) - (m_kCenter.y);
        q = (double)(float)fabs((double)e);
        if (s)
            s &= q - (m_kExtents.y - cf) <= 0.0;
        eb &= q - (m_kExtents.y + cf) <= 0.0;
        if (s || eb)
        {
            j = (p.z) - (m_kCenter.z);
            b = (double)(float)fabs((double)j);
            if (s)
                s &= b - (m_kExtents.z - cf) <= 0.0;
            eb &= b - (m_kExtents.z + cf) <= 0.0;
        }
    }
    return s ? 2 : (eb ? 1 : 0);
}

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex() : NiPoint3(0.0f, 0.0f, 0.0f)
    {}
    NiPoint3Ex(float fx, float fy, float afDepth) : NiPoint3(fx, fy, afDepth)
    {}
    NiPoint3Ex operator-(const NiPoint3& pt) const
    {
        return NiPoint3Ex(x - pt.x, y - pt.y, z - pt.z);
    }
    float Length() const;
};

extern double DAT_01012060;

class FUN_00c4fed0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    NiBound m_kBound;
    int FUN_00c4fed0(const NiBound& kBound);
};

// Returns 2 when center distance is at most the radius difference plus DAT_01012060, 1 when at most the radius sum plus that value, otherwise 0.
// @fnv 0x00c4fed0
int FUN_00c4fed0_cls::FUN_00c4fed0(const NiBound& kBound)
{
    NiPoint3Ex kDiff = static_cast<const NiPoint3Ex&>(m_kBound.m_kCenter) - kBound.m_kCenter;
    float fCenterDist = kDiff.Length();
    float ba;
    float k;
    float l;
    float c;
    float j = kBound.m_fBoundRadius;
    if (fCenterDist - (m_kBound.m_fBoundRadius - j) <= DAT_01012060)
        return 2;
    else
    {
        float kTemp = kBound.m_fBoundRadius;
        if (fCenterDist - (m_kBound.m_fBoundRadius + kTemp) <= DAT_01012060)
            return 1;
    }
    return 0;
}

struct Plane
{
    float x, y, z, d;
};
struct Frustum
{
    Plane planes[6];
    unsigned int kComparisonMask;
};
struct Sphere
{
    NiPoint3 center;
    float radius;
    int ClassifySphereAgainstPlane(const Plane& plane);
};
struct BoundObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    NiPoint3 center;
    float radius;
    bool CompletelyWithinFrustum(const Frustum* frustum);
};
// Returns true when every plane selected by kComparisonMask classifies the sphere as 1; otherwise returns false.
// @fnv 0x00c502a0
bool BoundObject::CompletelyWithinFrustum(const Frustum* frustum)
{
    float radius = this->radius;
    Sphere bound = {center, radius};
    int planeSide;
    unsigned int uiPlaneIndex;
    for (uiPlaneIndex = 0; uiPlaneIndex < 6; ++uiPlaneIndex)
    {
        if (bool(frustum->kComparisonMask & (1 << uiPlaneIndex)))
        {
            planeSide = bound.ClassifySphereAgainstPlane(frustum->planes[uiPlaneIndex]);
            if (planeSide != 1)
                return false;
        }
    }
    {
        int ReportDiagnostic;
    }
    return true;
}

namespace fnv_004a7150 {
struct FUN_004a4ac0
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FUN_004a4ac0();
    virtual ~FUN_004a4ac0();
};
struct FUN_0066b0d0
{
    int unk00;
    int unk04;
    FUN_0066b0d0(int a);
};
struct Obj_004a7150 : FUN_004a4ac0
{
    FUN_0066b0d0 unk24;
    FUN_0066b0d0 unk2c;
    Obj_004a7150();
    virtual ~Obj_004a7150();
};
// Constructor for Obj_004a7150 that initializes unk24 and unk2c to 0 and sets unk04 to 2.
// @fnv 0x004a7150
Obj_004a7150::Obj_004a7150() : unk24(0), unk2c(0)
{
    unk04 = 2;
}
}  // namespace fnv_004a7150

void* __fastcall FUN_00c37ec0(void*);
extern int DAT_0101e9a4;
struct FUN_00c36310_shell
{
    int __thiscall FUN_00c36310();
};
// @fnv 0x00c36310
int __thiscall FUN_00c36310_shell::FUN_00c36310()
{
    FUN_00c37ec0(this);
    *(int**)this = &DAT_0101e9a4;
    return (int)this;
}

void __fastcall FUN_00c4f980(void*);
extern int DAT_0101ea8c;
// @fnv 0x00c4fb10
void* __fastcall FUN_00c4fb10(void* apObj)
{
    FUN_00c4f980(apObj);
    *(int*)apObj = (int)&DAT_0101ea8c;
    return apObj;
}

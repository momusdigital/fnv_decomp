// staging/blk_00ca0000_od_o2_nood_variant.cpp: Picker_ca3b, TriMeshShape, VecOwnerAB, CacObj and more (15 functions)

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
#include <windows.h>
// src/staging/blk_00ca0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00ca0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ca0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct hkTransform;
class hkVector4
{
  public:
    __m128 m_vComponents;
    float getX() const
    {
        float x;
        _mm_store_ss(&x, m_vComponents);
        return x;
    }
    void FUN_00c7f640(const hkTransform& t, const hkVector4& v);
};
struct hkTransform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    hkTransform& operator=(const hkTransform& t)
    {
        m_kColumn0.m_vComponents = t.m_kColumn0.m_vComponents;
        m_kColumn1.m_vComponents = t.m_kColumn1.m_vComponents;
        m_kColumn2.m_vComponents = t.m_kColumn2.m_vComponents;
        m_kColumn3.m_vComponents = t.m_kColumn3.m_vComponents;
        return *this;
    }
};
struct hkVertex3
{
    float x;
    float y;
    float z;
};
struct hkVertexArray
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_iElementCount;
    int unk10;
    int unk14;
    hkVertex3* m_data;
};
class ShapeCa36a0
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
    hkTransform m_kMotionTransform;
    hkVector4 m_cachedMin;
    hkVector4 m_cachedMax;
    float m_cachedScale;
    hkVertexArray* m_kVertices;
    int unk88;
    int unk8C;
    hkVector4 m_vScale;
    float m_fSphereRadius;
    void FUN_00ca36a0(const hkTransform& t);
};
// @fnv 0x00ca36a0
void ShapeCa36a0::FUN_00ca36a0(const hkTransform& t)
{
    m_kMotionTransform = t;
    m_cachedScale = m_vScale.getX();
    m_cachedMin.m_vComponents = _mm_setr_ps(3.40282e38f, 3.40282e38f, 3.40282e38f, 0.0f);
    m_cachedMax.m_vComponents = _mm_setr_ps(-3.40282e38f, -3.40282e38f, -3.40282e38f, 0.0f);
    for (unsigned int i = 0; i < m_kVertices->m_iElementCount; i++)
    {
        const hkVertex3& p = m_kVertices->m_data[i];
        hkVector4 v;
        v.m_vComponents.m128_f32[0] = p.x;
        v.m_vComponents.m128_f32[1] = p.y;
        v.m_vComponents.m128_f32[2] = p.z;
        v.m_vComponents.m128_f32[3] = 0.0f;
        v.m_vComponents = _mm_mul_ps(m_vScale.m_vComponents, v.m_vComponents);
        hkVector4 tv;
        tv.FUN_00c7f640(t, v);
        m_cachedMin.m_vComponents = _mm_min_ps(m_cachedMin.m_vComponents, tv.m_vComponents);
        m_cachedMax.m_vComponents = _mm_max_ps(m_cachedMax.m_vComponents, tv.m_vComponents);
    }
}

namespace fnv_00ca37e0 {
class hkBool
{
  public:
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct hkTransform;

class hkVector4
{
  public:
    __m128 m_vComponents;
    void add(__m128 r)
    {
        m_vComponents = _mm_add_ps(m_vComponents, r);
    }
    float getX() const
    {
        float x;
        _mm_store_ss(&x, m_vComponents);
        return x;
    }
    void FUN_00c7f640(const hkTransform& t, const hkVector4& v);
};

struct hkVertex3
{
    float x;
    float y;
    float z;
};

struct hkVertexArray
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_iElementCount;
    int unk10;
    int unk14;
    hkVertex3* m_data;
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct hkShapeCache
{
    hkBool FUN_00cb2160(const hkTransform& t, float tolerance) const;
    int unk00;
};

class ShapeCa37e0
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
    hkShapeCache m_pAccessManager;
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
    hkVector4 m_cachedMin;
    hkVector4 m_cachedMax;
    float m_cachedScale;
    hkVertexArray* m_kVertices;
    int unk88;
    int unk8C;
    hkVector4 m_vScale;
    float m_fSphereRadius;

    void FUN_00ca37e0(const hkTransform& t, float tolerance, hkAabb& out);
};

// @fnv 0x00ca37e0
void ShapeCa37e0::FUN_00ca37e0(const hkTransform& t, float tolerance, hkAabb& out)
{
    if (m_cachedMin.getX() != 3.402820018375656e+38 && m_pAccessManager.FUN_00cb2160(t, 0.001f))
    {
        if (m_vScale.getX() == m_cachedScale)
        {
            out.m_kMinimumCorner.m_vComponents = m_cachedMin.m_vComponents;
            out.m_kMaximumCorner.m_vComponents = m_cachedMax.m_vComponents;
            goto addRadius;
        }
    }
    out.m_kMinimumCorner.m_vComponents = _mm_setr_ps(3.40282e38f, 3.40282e38f, 3.40282e38f, 0.0f);
    out.m_kMaximumCorner.m_vComponents = _mm_setr_ps(-3.40282e38f, -3.40282e38f, -3.40282e38f, 0.0f);
    for (unsigned int i = 0; i < m_kVertices->m_iElementCount; i++)
    {
        const hkVertex3& p = m_kVertices->m_data[i];
        hkVector4 v;
        v.m_vComponents.m128_f32[0] = p.x;
        v.m_vComponents.m128_f32[1] = p.y;
        v.m_vComponents.m128_f32[2] = p.z;
        v.m_vComponents.m128_f32[3] = 0.0f;
        v.m_vComponents = _mm_mul_ps(m_vScale.m_vComponents, v.m_vComponents);
        hkVector4 tv;
        tv.FUN_00c7f640(t, v);
        out.m_kMinimumCorner.m_vComponents = _mm_min_ps(out.m_kMinimumCorner.m_vComponents, tv.m_vComponents);
        out.m_kMaximumCorner.m_vComponents = _mm_max_ps(out.m_kMaximumCorner.m_vComponents, tv.m_vComponents);
    }
addRadius:
    float radius = m_fSphereRadius + tolerance;
    __m128 r = _mm_load_ps1(&radius);
    out.m_kMinimumCorner.m_vComponents = _mm_sub_ps(out.m_kMinimumCorner.m_vComponents, r);
    out.m_kMaximumCorner.add(r);
}
}  // namespace fnv_00ca37e0

extern unsigned int DAT_010c74ec;

class FUN_00ca39a0
{
  public:
    unsigned int m_vtbl;   // 0x00
    unsigned short unk04;  // 0x04 (untouched half)
    unsigned short m_w06;  // 0x06
    unsigned int m_d08;    // 0x08
    unsigned int m_d0C;    // 0x0C
    float m_f10;           // 0x10
    unsigned short m_w14;  // 0x14
    unsigned char m_b16;   // 0x16
    unsigned char m_b17;   // 0x17
    unsigned int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    __m128 m_quad50;  // 0x50
    FUN_00ca39a0(float x);
};

// @fnv 0x00ca39a0
FUN_00ca39a0::FUN_00ca39a0(float x)
{
    m_f10 = x;
    m_w06 = 1;
    m_d08 = 0;
    m_d0C = 3;
    m_w14 = 0;
    m_b16 = 6;
    m_quad50 = _mm_setzero_ps();
    m_b17 = 0;
    m_vtbl = (unsigned int)&DAT_010c74ec;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Ca39f0Vector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const Ca39f0Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct Ca39f0RefObject
{
    virtual ~Ca39f0RefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct Ca39f0Pointer
{
    Ca39f0RefObject* m_pObject;
    Ca39f0Pointer() : m_pObject(0)
    {}
    ~Ca39f0Pointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    Ca39f0Pointer& operator=(const Ca39f0Pointer& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Ca39f0Aabb
{
    Ca39f0Vector4 m_kMinimumCorner;
    Ca39f0Vector4 m_kMaximumCorner;
    __forceinline void setEmpty()
    {
        m_kMinimumCorner.set(3.40282e+38f, 3.40282e+38f, 3.40282e+38f, 0.0f);
        m_kMaximumCorner.set(-3.40282e+38f, -3.40282e+38f, -3.40282e+38f, 0.0f);
    }
};

struct Ca39f0Cinfo
{
    int unk00;
    Ca39f0Pointer m_object;
    float m_fSphereRadius;
    int unk0c;
    Ca39f0Vector4 m_offset;
};

struct Ca39f0BaseA
{
    virtual ~Ca39f0BaseA();
    int unk04;
    int unk08;
    int unk0c;
};

struct Ca39f0BaseB
{
    virtual void vb00();
    bool m_enabled;
};

struct Ca39f0Base : Ca39f0BaseA, Ca39f0BaseB
{
    Ca39f0Base(int type, int flags);
    virtual ~Ca39f0Base();
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
};

struct FUN_00ca39f0 : Ca39f0Base
{
    Ca39f0Aabb m_kBounds;
    int unk80;
    Ca39f0Pointer m_pReferencedObject;
    int unk88;
    int unk8c;
    Ca39f0Vector4 m_offset;
    float m_fSphereRadius;

    FUN_00ca39f0(const Ca39f0Cinfo& info);
    virtual ~FUN_00ca39f0();
    virtual void vb00();
};

// @fnv 0x00ca39f0
FUN_00ca39f0::FUN_00ca39f0(const Ca39f0Cinfo& info) : Ca39f0Base(0x1f, 3)
{
    m_pReferencedObject = info.m_object;
    m_fSphereRadius = info.m_fSphereRadius;
    m_offset = info.m_offset;
    m_kBounds.setEmpty();
    m_enabled = true;
}

class RefObject_ca3b
{
  public:
    virtual ~RefObject_ca3b();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class Pointer_ca3b
{
  public:
    Pointer_ca3b& operator=(const Pointer_ca3b& kPointer)
    {
        if (m_pObject != kPointer.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kPointer.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    Pointer_ca3b& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

struct Vector4_ca3b
{
    __m128 m_vComponents;
    Vector4_ca3b& operator=(const Vector4_ca3b& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct PickResult_ca3b
{
    int unk00;
    Pointer_ca3b<RefObject_ca3b> m_pReferencedObject;
    float m_fHitDistance;
    int unk0c;
    Vector4_ca3b m_kPoint;
};

class Picker_ca3b
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80;
    Pointer_ca3b<RefObject_ca3b> m_pReferencedObject;
    int unk88, unk8c;
    Vector4_ca3b m_kPoint;
    float m_fHitDistance;

    void FUN_00ca3b20(PickResult_ca3b* pkResult);
};

// @fnv 0x00ca3b20
void Picker_ca3b::FUN_00ca3b20(PickResult_ca3b* pkResult)
{
    pkResult->m_fHitDistance = m_fHitDistance;
    pkResult->m_kPoint = m_kPoint;
    pkResult->m_pReferencedObject = m_pReferencedObject;
}

struct TriVec3
{
    float v[3];
};
struct TriIndices
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short flags;
};

struct TriMeshData
{
    int unk00;
    int unk04;
    unsigned int numTriangles;
    int unk0C;
    int unk10;
    TriIndices* triangles;
    TriVec3* vertices;
    TriVec3 GetVertex(unsigned int i) const
    {
        return vertices[i];
    }
    const TriVec3& GetVertexRef(unsigned int i) const
    {
        return vertices[i];
    }
};

struct SimdReal
{
    __m128 m_vValue;
    SimdReal(__m128 r) : m_vValue(r)
    {}
    float getReal() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct Vec4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents.m128_f32[0] = x;
        m_vComponents.m128_f32[1] = y;
        m_vComponents.m128_f32[2] = z;
        m_vComponents.m128_f32[3] = w;
    }
    void mul4(const Vec4& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    SimdReal getSimdAt0() const
    {
        return SimdReal(m_vComponents);
    }
};

struct TriShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 vertex0;
    Vec4 vertex1;
    Vec4 vertex2;
    TriShape* FUN_00ca39a0(float radius);
};

struct TriMeshShape
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
    TriMeshData* data;
    int unk78;
    int unk7C;
    Vec4 scale;
    float radius;
    TriShape* FUN_00ca3c40(unsigned int key, TriShape* buffer);
};

static inline void SetVertex(Vec4& v, const TriVec3& p)
{
    v.set(p.v[0], p.v[1], p.v[2]);
}

// @fnv 0x00ca3c40
TriShape* TriMeshShape::FUN_00ca3c40(unsigned int key, TriShape* buffer)
{
    unsigned int index = key & 0xFFFFFF;
    if (index >= data->numTriangles)
        return 0;
    TriIndices* tri = &data->triangles[index];
    TriShape* shape = buffer ? buffer->FUN_00ca39a0(radius) : 0;
    SetVertex(shape->vertex0, data->GetVertex(tri->a));
    SetVertex(shape->vertex1, data->GetVertex(tri->b));
    SetVertex(shape->vertex2, data->GetVertex(tri->c));
    const SimdReal& sr = scale.getSimdAt0();
    if (sr.getReal() != 1.0f)
    {
        const Vec4& s = scale;
        shape->vertex0.mul4(s);
        shape->vertex1.mul4(s);
        shape->vertex2.mul4(s);
    }
    return shape;
}

static const float HK_REAL_MAX_CA4B = 3.40282e+38f;

struct hkVector4CA4B
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct AabbCA4B
{
    hkVector4CA4B m_kMin;
    hkVector4CA4B m_kMax;
    void setEmpty()
    {
        m_kMin.set(HK_REAL_MAX_CA4B, HK_REAL_MAX_CA4B, HK_REAL_MAX_CA4B, 0.0f);
        m_kMax.set(-HK_REAL_MAX_CA4B, -HK_REAL_MAX_CA4B, -HK_REAL_MAX_CA4B, 0.0f);
    }
};

struct ShapeBaseCA4B
{
    ShapeBaseCA4B(int type, int subType);
    virtual ~ShapeBaseCA4B();
    int unk04;
    int unk08;
    int unk0C;
};

struct __declspec(novtable) ShapeIfaceCA4B
{
    virtual void Vf00();
};

struct PointCA4B
{
    int unk00;
    int unk04;
};

struct PointArrayBaseCA4B
{
    static PointCA4B* Allocate(unsigned int ItemUpdateArray);
    PointArrayBaseCA4B(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiMaxSize > 0)
            m_pBase = Allocate(m_uiMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~PointArrayBaseCA4B();
    PointCA4B* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
};

struct PointArrayCA4B : public PointArrayBaseCA4B
{
    PointArrayCA4B(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : PointArrayBaseCA4B(uiMaxSize, uiGrowBy)
    {}
    virtual ~PointArrayCA4B();
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const PointCA4B& kElement);
    unsigned int SetAtGrow(unsigned int uiIndex, const PointCA4B& kElement)
    {
        if (uiIndex >= m_uiMaxSize)
            SetSize(uiIndex + m_uiGrowBy);
        SetAt(uiIndex, kElement);
        return uiIndex;
    }
    unsigned int Add(const PointCA4B& kElement)
    {
        return SetAtGrow(m_uiSize, kElement);
    }
};

struct ShapeInfoCA4B
{
    int unk00;
    float m_fBoundRadius;
    int unk08;
    PointCA4B* m_pkPoints;
    int unk10;
    int m_iNumPoints;
    int unk18;
    int unk1C;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

class FUN_00ca4bc0 : public ShapeBaseCA4B, public ShapeIfaceCA4B
{
  public:
    FUN_00ca4bc0(const ShapeInfoCA4B* pkInfo);
    virtual ~FUN_00ca4bc0();

    bool m_bValueAt0C;
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
    AabbCA4B m_kAabb;
    hkVector4CA4B m_kCenter;
    float m_fBoundRadius;
    PointArrayCA4B m_kPoints;
};

// @fnv 0x00ca4bc0
FUN_00ca4bc0::FUN_00ca4bc0(const ShapeInfoCA4B* pkInfo) : ShapeBaseCA4B(0x1e, 3), m_fBoundRadius(pkInfo->m_fBoundRadius)
{
    m_fBoundRadius = pkInfo->m_fBoundRadius;
    m_kCenter.set(pkInfo->m_fVectorY, pkInfo->m_fVectorZ, pkInfo->m_fScalarPart, pkInfo->m_fVectorX);
    for (int i = 0; i < pkInfo->m_iNumPoints; i++)
    {
        m_kPoints.Add(pkInfo->m_pkPoints[i]);
    }
    m_kAabb.setEmpty();
    m_bValueAt0C = true;
}

struct MassInfo_ca5360
{
    int unk00;
    int unk04;
    float m_fMass;
    int unk0C;
    __m128 m_kInertia;
};
struct Shape_ca5360
{
    void FUN_00ca3b20(MassInfo_ca5360* pkInfo);
};
struct Base_ca5360
{
    void FUN_00c84e20(MassInfo_ca5360* pkInfo);
};
struct FUN_00ca5360_cls : Base_ca5360
{
    int unk00;
    int unk04;
    Shape_ca5360* m_pShape;
    void FUN_00ca5360(MassInfo_ca5360* pkInfo);
};
// @fnv 0x00ca5360
void FUN_00ca5360_cls::FUN_00ca5360(MassInfo_ca5360* pkInfo)
{
    Base_ca5360::FUN_00c84e20(pkInfo);
    if (this != 0 && m_pShape != 0)
        m_pShape->FUN_00ca3b20(pkInfo);
    else
    {
        pkInfo->m_fMass = 0.0f;
        pkInfo->m_kInertia = _mm_set1_ps(1.0f);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern float DAT_01012068;

class Ca5580Ref
{
  public:
    virtual ~Ca5580Ref();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class Ca5580Ptr
{
  public:
    Ca5580Ref* m_pObject;
    Ca5580Ptr(Ca5580Ref* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~Ca5580Ptr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    Ca5580Ptr& operator=(Ca5580Ref* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

__declspec(align(16)) struct FUN_00ca5580
{
    int unk00;
    Ca5580Ptr m_sp;
    float m_f;
    __m128 m_v;
    FUN_00ca5580();
};

// @fnv 0x00ca5580
FUN_00ca5580::FUN_00ca5580() : unk00(0), m_sp(0), m_f(0.0f)
{
    m_sp = (Ca5580Ref*)0;
    m_v = _mm_set1_ps(DAT_01012068);
}

struct VecCAB
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};
struct BaseCAB0
{
    virtual void v00();
    int m_04;
};
struct BaseCAB1
{
    virtual void v10();
};
struct BaseCAB2
{
    virtual void v20();
};
struct ConstraintCAB : BaseCAB0, BaseCAB1, BaseCAB2
{
    int m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    ConstraintCAB(int a);
};
struct FUN_00cabec0 : ConstraintCAB
{
    VecCAB m_40;
    int m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4, m_a8, m_ac;
    int m_b0, m_b4, m_b8, m_bc;
    int m_c0;
    FUN_00cabec0(int a);
    virtual void v00();
    virtual void v10();
    virtual void v20();
};
// @fnv 0x00cabec0
FUN_00cabec0::FUN_00cabec0(int a) : ConstraintCAB(a)
{
    m_c0 = 0;
    m_40.set(0.0f, 0.0f, 1.0f, 0.0f);
}

class VecOwnerAB
{
  public:
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    __m128 m_v;
    float FUN_00cac860();
};

// @fnv 0x00cac860
float VecOwnerAB::FUN_00cac860()
{
    return _mm_cvtss_f32(_mm_shuffle_ps(m_v, m_v, 0xff));
}

struct CacV4
{
    __m128 m_vComponents;
};

struct CacObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CacV4 v4;
    void FUN_00cac960(const CacV4* pv);
};

// @fnv 0x00cac960
void CacObj::FUN_00cac960(const CacV4* pv)
{
    v4.m_vComponents = pv->m_vComponents;
}

extern unsigned long DAT_0126fd98;
struct F7_Ctx
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2b4;
};
extern __declspec(thread) F7_Ctx F7_tls;
struct F7_Scope
{
    int saved;
    F7_Scope()
    {
        saved = F7_tls.unk2b4;
        F7_tls.unk2b4 = 0x10;
    }
    ~F7_Scope()
    {
        F7_tls.unk2b4 = saved;
    }
};
struct F7_Alloc
{
    virtual void slot0();
    virtual void* alloc(int bytes);
};
struct F7_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F7_Alloc* m_pStreamAllocator;
    F7_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
F7_Router* __cdecl FUN_00c85750();
struct F7_Vec
{
    __m128 q;
};
struct F7_Shape
{
    int unk00;
    unsigned short size;
    unsigned short refs;
    int unk08;
    int unk0c;
    F7_Vec unk10;
    F7_Vec v20, v30, v40, v50, v60, v70, v80, v90, va0;
    F7_Shape();
    static void* operator new(unsigned int amount)
    {
        void* r = FUN_00c85750()->heap().alloc(amount);
        ((F7_Shape*)r)->size = (unsigned short)amount;
        return r;
    }
    static void operator delete(void*);
};
static __declspec(noinline) void __cdecl FUN_00cbd9e0(float s, F7_Shape* d)
{
    __m128 k = _mm_set1_ps(s);
    F7_Vec* p = &d->v20;
    for (int i = 0; i < 3; i++)
        p[i].q = _mm_mul_ps(p[i].q, k);
}
struct F7_Params
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float scale;
};
struct F7_Clone
{
    int unk00;
    F7_Shape* shape;
    void ReleaseObject(F7_Shape*, F7_Params*);
    void CloneData(F7_Shape* dest, F7_Params* params);
};
// @fnv 0x00cbdb70
void F7_Clone::CloneData(F7_Shape* dest, F7_Params* params)
{
    F7_Scope scope;
    F7_Shape* src = shape;
    if (!dest)
        dest = new F7_Shape;
    dest->v20.q = src->v20.q;
    dest->v30.q = src->v30.q;
    dest->v40.q = src->v40.q;
    dest->v50.q = src->v50.q;
    dest->v60.q = src->v60.q;
    dest->v70.q = src->v70.q;
    dest->v80.q = src->v80.q;
    dest->v90.q = src->v90.q;
    float scale = params->scale;
    if (scale != 1.0f)
        FUN_00cbd9e0(scale, dest);
    ReleaseObject(dest, params);
}

namespace fnv_00cbeaf0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
}

extern __m128 DAT_010c4c10;

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void load3(const float* p)
    {
        m_vComponents.m128_f32[0] = p[0];
        m_vComponents.m128_f32[1] = p[1];
        m_vComponents.m128_f32[2] = p[2];
    }
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

// @fnv 0x00cbeaf0
void FUN_00cbeaf0(const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut)
{
    hkVector4 v;
    v.load3(vertexArray);
    __m128 vmin = v.m_vComponents;
    __m128 vmax = vmin;
    for (int i = 1; i < numVertices; i++)
    {
        v.load3((const float*)((const char*)vertexArray + i * striding));
        vmin = _mm_min_ps(vmin, v.m_vComponents);
        vmax = _mm_max_ps(vmax, v.m_vComponents);
    }
    aabbOut.m_kMinimumCorner.m_vComponents = _mm_and_ps(DAT_010c4c10, vmin);
    aabbOut.m_kMaximumCorner.m_vComponents = _mm_and_ps(DAT_010c4c10, vmax);
}
}  // namespace fnv_00cbeaf0

namespace fnv_00ca7a70 {
struct Reader
{
    void* unk00;
    unsigned position;
    unsigned(__cdecl* read)(Reader*, void*, unsigned, unsigned*, unsigned);
    void ReadScalar(void* output, unsigned bytes)
    {
        unsigned size = bytes;
        position += read(this, output, bytes, &size, 1);
    }
    void Read(void* output, unsigned bytes, unsigned* itemSize, unsigned count)
    {
        position += read(this, output, bytes, itemSize, count);
    }
};
struct NiStream
{
    unsigned unk00;
    unsigned version;
    char fileName[216];
    char filePath[260];
    unsigned char unk1e4;
    unsigned char littleEndian;
    unsigned short unk1e6;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    Reader* reader;
    void FUN_00a64670();
    template <class T> void ReadValue(T& value)
    {
        reader->ReadScalar(&value, sizeof(T));
    }
};
struct Allocator
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void unk0c() = 0;
    virtual void Free(void*, unsigned) = 0;
    template <class T> void FreeArray(T* data, unsigned capacity)
    {
        if (!(capacity & 0x80000000u))
            Free(data, (capacity & 0x3fffffffu) * sizeof(T));
    }
};
struct MemoryRouter
{
    unsigned unk00, unk04, unk08, unk0c;
    Allocator* heap;
};
MemoryRouter* __cdecl FUN_00c85750();
template <class T> struct LegacyArray
{
    T* data;
    int size;
    unsigned capacity;
    void Clear()
    {
        for (int i = size - 1; i >= 0; --i)
            data[i].~T();
        size = 0;
    }
    void ClearAndDeallocate(Allocator& allocator)
    {
        Clear();
        allocator.FreeArray(data, capacity);
        data = 0;
        capacity = 0x80000000u;
    }
    void ClearAndDeallocate()
    {
        MemoryRouter* router = FUN_00c85750();
        ClearAndDeallocate(*router->heap);
    }
};
struct __declspec(align(16)) FUN_00ca7310
{
    int material;
    float radius;
    unsigned unk08, unk0c;
    float scaleX, scaleY, scaleZ, scaleW;
    unsigned unk20;
    LegacyArray<unsigned> a24;
    LegacyArray<unsigned> a30;
    LegacyArray<unsigned> a3c;
    LegacyArray<unsigned> a48;
    LegacyArray<unsigned char> a54;
    LegacyArray<unsigned> a60;
    LegacyArray<unsigned> a6c;
    LegacyArray<unsigned> a78;
    LegacyArray<unsigned> a84;
    LegacyArray<unsigned> a90;
    LegacyArray<unsigned> a9c;
    LegacyArray<unsigned> aa8;
    unsigned unkb4, unkb8, unkbc;
    FUN_00ca7310();
    void FUN_00ca73c0();
    ~FUN_00ca7310()
    {
        FUN_00ca73c0();
    }
};
struct ReferenceObject
{
    virtual void unk00() = 0;
    virtual void DeleteThis() = 0;
    volatile LONG references;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
struct MaterialEntry
{
    ReferenceObject* object;
    unsigned flags;
    MaterialEntry() : object(0), flags(0)
    {}
    ~MaterialEntry()
    {
        if (object)
            object->DecRefCount();
    }
};
struct MaterialArray
{
    void* vtable;
    MaterialEntry* data;
    unsigned capacity, size, occupied, growth;
    void Resize(unsigned);
    void FUN_00ca49a0(unsigned, MaterialEntry&);
    void Append(MaterialEntry& value)
    {
        unsigned index = size;
        if (index >= capacity)
            Resize(index + growth);
        FUN_00ca49a0(index, value);
    }
};
struct RuntimeMesh
{
    unsigned material;
    float radius;
    MaterialArray materials;
};
struct TextFlag
{
    unsigned char enabled;
    TextFlag(bool value)
    {
        enabled = (char)value;
    }
    TextFlag(const TextFlag& value)
    {
        enabled = value.enabled;
    }
};
struct FUN_00cc0500
{
    void* vtable;
    unsigned short unk04, references;
    void* writer;
    FUN_00cc0500(char*, int, TextFlag);
    void FUN_00cc00e0();
    ~FUN_00cc0500()
    {
        FUN_00cc00e0();
    }
    FUN_00cc0500& FUN_00cc01c0(const char*);
};
struct WarningHandler
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void Report(int, unsigned, const char*, const char*, int) = 0;
};
extern WarningHandler* DAT_01268360;
extern const float DAT_010c72c0;
struct MeshShape
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void unk0c() = 0;
    virtual void unk10() = 0;
    virtual void unk14() = 0;
    virtual void unk18() = 0;
    virtual void unk1c() = 0;
    virtual void unk20() = 0;
    virtual void unk24() = 0;
    virtual void unk28() = 0;
    virtual void unk2c() = 0;
    virtual void unk30() = 0;
    virtual void unk34() = 0;
    virtual void unk38() = 0;
    virtual void unk3c() = 0;
    virtual void unk40() = 0;
    virtual void unk44() = 0;
    virtual void unk48() = 0;
    virtual void unk4c() = 0;
    virtual void unk50() = 0;
    virtual void unk54() = 0;
    virtual void unk58() = 0;
    virtual void unk5c() = 0;
    virtual void unk60() = 0;
    virtual void unk64() = 0;
    virtual void unk68() = 0;
    virtual void unk6c() = 0;
    virtual void unk70() = 0;
    virtual void unk74() = 0;
    virtual void unk78() = 0;
    virtual void unk7c() = 0;
    virtual void unk80() = 0;
    virtual void unk84() = 0;
    virtual void unk88() = 0;
    virtual void unk8c() = 0;
    virtual void unk90() = 0;
    virtual void unk94() = 0;
    virtual void unk98() = 0;
    virtual void unk9c() = 0;
    virtual void unka0() = 0;
    virtual void unka4() = 0;
    virtual void unka8() = 0;
    virtual void unkac() = 0;
    virtual void unkb0() = 0;
    virtual RuntimeMesh* GetRuntime(unsigned char*) = 0;
    unsigned references, field08, field0c;
    int material;
    void ReadGroup(NiStream&);
    void FUN_00c84d00(NiStream&);
    void LoadBinary(NiStream&);
};

// @fnv 0x00ca7a70
void MeshShape::LoadBinary(NiStream& stream)
{
    unsigned char allocated;
    RuntimeMesh* mesh = GetRuntime(&allocated);
    if (stream.version < 2)
    {
        const char* name = stream.fileName;
        if (!*name)
            name = "Please";
        {
            char message[512];
            FUN_00cc0500 text(message, 512, TextFlag(true));
            const char* path = stream.filePath;
            text.FUN_00cc01c0("File ")
                .FUN_00cc01c0(path)
                .FUN_00cc01c0(" contains an old bhkpMeshShape! ")
                .FUN_00cc01c0(name)
                .FUN_00cc01c0(" re-export\n");
            DAT_01268360->Report(1, 0x234f2250, message,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkNiTriStripsShape.cpp", 170);
        }
        ReadGroup(stream);
        FUN_00ca7310 old;
        stream.reader->Read(&old, 0xc0, 0, 0);
        old.a24.ClearAndDeallocate();
        old.a30.ClearAndDeallocate();
        old.a3c.ClearAndDeallocate();
        old.a48.ClearAndDeallocate();
        old.a54.ClearAndDeallocate();
        old.a60.ClearAndDeallocate();
        old.a6c.ClearAndDeallocate();
        old.a78.ClearAndDeallocate();
        old.a84.ClearAndDeallocate();
        old.a90.ClearAndDeallocate();
        old.a9c.ClearAndDeallocate();
        old.aa8.ClearAndDeallocate();
        if (stream.littleEndian != 1)
        {
            old.material = _byteswap_ulong(old.material);
            unsigned* radiusBits = reinterpret_cast<unsigned*>(&old.radius);
            *radiusBits = _byteswap_ulong(*radiusBits);
        }
        mesh->radius = old.radius;
        if (stream.littleEndian != 1)
        {
            unsigned* x = reinterpret_cast<unsigned*>(&old.scaleX);
            unsigned* y = reinterpret_cast<unsigned*>(&old.scaleY);
            unsigned* z = reinterpret_cast<unsigned*>(&old.scaleZ);
            unsigned* w = reinterpret_cast<unsigned*>(&old.scaleW);
            *x = _byteswap_ulong(*x);
            *y = _byteswap_ulong(*y);
            *z = _byteswap_ulong(*z);
            *w = _byteswap_ulong(*w);
        }
        if (old.material >= 36)
            old.material = 0;
        material = old.material;
        mesh->material = 0;
        mesh->radius = DAT_010c72c0;
        stream.FUN_00a64670();
    }
    else
    {
        FUN_00c84d00(stream);
        stream.FUN_00a64670();
        unsigned count = 0;
        stream.ReadValue(count);
        if (stream.littleEndian != 1)
        {
            unsigned* radiusBits = reinterpret_cast<unsigned*>(&mesh->radius);
            *radiusBits = _byteswap_ulong(*radiusBits);
        }
        for (unsigned index = 0; index < count; ++index)
        {
            MaterialEntry entry;
            stream.ReadValue(entry.flags);
            if (stream.version < 9 && (entry.flags & 0x20))
                entry.flags = (entry.flags & ~0x20u) | 0x8000;
            mesh->materials.Append(entry);
        }
    }
}
}  // namespace fnv_00ca7a70

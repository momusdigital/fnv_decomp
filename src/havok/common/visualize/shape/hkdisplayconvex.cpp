
// src/havok/common/visualize/shape/hkdisplayconvex.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplayconvex.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00de1d10
void __cdecl buildGeometry()
{}

#include <xmmintrin.h>
struct __declspec(align(16)) S_00de1d20_Vector4
{
    float x;
    float y;
    float z;
    float w;
    float& operator()(int i)
    {
        return (&x)[i];
    }
    void setZero4()
    {
        reinterpret_cast<__m128&>(*this) = _mm_setzero_ps();
    }
};

struct S_00de1d20_Matrix3
{
    S_00de1d20_Vector4 m_kColumn0;
    S_00de1d20_Vector4 m_kColumn1;
    S_00de1d20_Vector4 m_kColumn2;
    float& operator()(int r, int c)
    {
        return ((float*)&m_kColumn0)[c * 4 + r];
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};

struct S_00de1d20_Base
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00de1d20_Base()
    {
        m_sReferenceCount = 1;
    }
    virtual void v0();
};

struct S_00de1d20_Mid : S_00de1d20_Base
{
    int unk8;
    S_00de1d20_Matrix3 unk10;
    S_00de1d20_Vector4 unk40;
    int unk50;

    __forceinline S_00de1d20_Mid(int a)
    {
        unk50 = 6;
        unk10.setIdentity();
        unk40.setZero4();
    }
};

struct FUN_00de1d20 : S_00de1d20_Mid
{
    FUN_00de1d20(int a);
    virtual void v1();
};

// Constructor that initializes the base class with the given int and stores it in the unk8 field.
// @fnv 0x00de1d20
FUN_00de1d20::FUN_00de1d20(int aiValue) : S_00de1d20_Mid(aiValue)
{
    unk8 = aiValue;
}

namespace fnv_00de1d70 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkMemoryAllocator;
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

struct hkVector4
{
    __m128 m_vComponents;
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <typename T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct hkGeomTriangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};

struct TriIndices
{
    int a;
    int b;
    int c;
};

struct hkGeom
{
    hkArr<hkVector4> m_kVertices;
    hkArr<hkGeomTriangle> m_uiTriangleCount;
};

struct EdgeBuilder
{
    int unk00;
    int unk04;
    hkGeom* m_pSourceGeometry;
    void FUN_00de1d70(hkArr<hkVector4>& lines, hkMemoryAllocator& alloc);
};

// For each triangle in the source geometry, appends three vertex pairs (a-b, a-c, b-c) to lines.
// @fnv 0x00de1d70
void EdgeBuilder::FUN_00de1d70(hkArr<hkVector4>& lines, hkMemoryAllocator& alloc)
{
    if (m_pSourceGeometry)
    {
        for (int i = m_pSourceGeometry->m_uiTriangleCount.m_iElementCount - 1; i >= 0; i--)
        {
            TriIndices k;
            k.a = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_kPointA;
            k.b = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_kPointB;
            k.c = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_iThirdValue;
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.a]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.b]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.a]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.c]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.b]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.c]);
        }
    }
}
}  // namespace fnv_00de1d70


// src/havok/common/visualize/shape/hkdisplayplane.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplayplane.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
};
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
struct Float4
{
    float x, y, z, w;
};
struct Vec4_de4e20
{
    __m128 q;
    void setCross(const Vec4_de4e20& a, const Vec4_de4e20& b)
    {
        __m128 t0 = _mm_shuffle_ps(a.q, a.q, 0xc9);
        __m128 t1 = _mm_shuffle_ps(b.q, b.q, 0xd2);
        __m128 t2 = _mm_shuffle_ps(a.q, a.q, 0xd2);
        __m128 t3 = _mm_shuffle_ps(b.q, b.q, 0xc9);
        q = _mm_sub_ps(_mm_mul_ps(t0, t1), _mm_mul_ps(t2, t3));
    }
    void SetProduct(const Vec4_de4e20& a, const Vec4_de4e20& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void mul(const Vec4_de4e20& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    void set(const Vec4_de4e20& b)
    {
        q = b.q;
    }

    void add(const Vec4_de4e20& o)
    {
        q = _mm_add_ps(q, o.q);
    }
    void sub(const Vec4_de4e20& o)
    {
        q = _mm_sub_ps(q, o.q);
    }
};
struct Cls_00de4e20
{
    __m128 unk00, unk10, unk20, unk30, unk40, unk50;
    Vec4_de4e20 m_kPointA;
    Vec4_de4e20 m_p;
    Vec4_de4e20 m_kPointB;
    Vec4_de4e20 m_q;
    void __thiscall FUN_00de4e20(Vec4_de4e20* out);
};
// @fnv 0x00de4e20
void __thiscall Cls_00de4e20::FUN_00de4e20(Vec4_de4e20* out)
{
    Vec4_de4e20 cross;
    cross.setCross(m_kPointA, m_kPointB);
    out[0].set(m_p);
    out[1].set(m_p);
    out[2].set(m_p);
    out[3].set(m_p);
    Vec4_de4e20 t0 = cross, t1;
    t1.q = m_kPointB.q;
    t0.mul(m_q);
    t1.mul(m_q);
    out[0].add(t0);
    out[0].add(t1);
    out[1].add(t0);
    out[1].sub(t1);
    out[2].sub(t0);
    out[2].add(t1);
    out[3].sub(t0);
    out[3].sub(t1);
}

struct MatrixOwner
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
    __m128 unk60;
    __m128 unk70;
    __m128 unk80;
    __m128 unk90;
    void __thiscall SetFromVectors(const __m128*, const __m128*, const __m128*, const __m128*);
};
// Stores *a, *c, *b and *d into unk60, unk70, unk80 and unk90 respectively.
// @fnv 0x00de4ee0
void __thiscall MatrixOwner::SetFromVectors(const __m128* a, const __m128* b, const __m128* c, const __m128* d)
{
    unk60 = *a;
    unk70 = *c;
    unk80 = *b;
    unk90 = *d;
}

struct VecBuf
{
    unsigned char* m_data;       // +0x00
    unsigned int m_uiItemCount;  // +0x04
    unsigned int m_iElementCount;         // +0x08 (low 30 bits = size)
};

__declspec(align(16)) struct VecTemp4
{
    unsigned int m_00, m_04, m_08, m_0c;
    unsigned int m_10, m_14, m_18, m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    unsigned int m_30, m_34, m_38, m_3c;
};

extern "C" void __cdecl FUN_00c908c0(unsigned int a1, VecBuf* v, int cap, int elem);

struct FUN_00de5050_cls
{
    void Fill(VecTemp4* out);
    void getWireframeGeometry(VecBuf* s, unsigned int a2);
};

// @fnv 0x00de5050
void FUN_00de5050_cls::getWireframeGeometry(VecBuf* s, unsigned int a2)
{
    int n = (int)(s->m_iElementCount & 0x3fffffff);
    if (n < 12)
    {
        int cap = n + n;
        if (cap <= 12)
        {
            cap = 12;
        }
        FUN_00c908c0(a2, s, cap, 0x10);
    }
    VecTemp4 tmp;
    s->m_uiItemCount = 12;
    this->Fill(&tmp);

    __m128 v0 = _mm_load_ps((float*)&tmp.m_00);
    __m128 v1 = _mm_load_ps((float*)&tmp.m_10);
    __m128 v2 = _mm_load_ps((float*)&tmp.m_20);
    *(__m128*)(s->m_data + 0x00) = v0;
    __m128 v3 = _mm_load_ps((float*)&tmp.m_30);
    *(__m128*)(s->m_data + 0x10) = v1;
    *(__m128*)(s->m_data + 0x20) = v1;
    *(__m128*)(s->m_data + 0x30) = v2;
    *(__m128*)(s->m_data + 0x40) = v2;
    *(__m128*)(s->m_data + 0x50) = v3;
    *(__m128*)(s->m_data + 0x60) = v3;
    *(__m128*)(s->m_data + 0x70) = v0;
    *(__m128*)(s->m_data + 0x80) = v0;
    *(__m128*)(s->m_data + 0x90) = v2;
    *(__m128*)(s->m_data + 0xa0) = v1;
    *(__m128*)(s->m_data + 0xb0) = v3;
}

struct S_00de5110_Heap
{
    virtual void v00() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
};

struct S_00de5110_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00de5110_Heap* m_pStreamAllocator;
    S_00de5110_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

S_00de5110_Router& FUN_00c85750() throw();
void FUN_00c908c0(S_00de5110_Heap& alloc, void* array, int numElements, int sizeElem) throw();

template <typename T> struct S_00de5110_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00de5110_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    T* begin() throw()
    {
        return m_data;
    }

    __forceinline void GrowArrayCapacity(S_00de5110_Heap& a, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(a, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00de5110_Heap& a, int n) throw()
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
    __forceinline T* _expandBy(S_00de5110_Heap& a, int n) throw()
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(FUN_00c85750().heap(), n);
    }
    __forceinline T* expandBy(int n) throw()
    {
        return _expandBy(FUN_00c85750().heap(), n);
    }
};

struct __declspec(align(16)) S_00de5110_Vector4
{
    float x, y, z, w;
    void operator=(const S_00de5110_Vector4& v) throw()
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v);
    }
};

struct S_00de5110_Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
    void set(int a, int b, int c, int material = -1) throw()
    {
        m_kPointA = a;
        m_kPointB = b;
        m_iThirdValue = c;
        m_iMaterialIndex = material;
    }
};

struct S_00de5110_Geometry
{
    S_00de5110_Array<S_00de5110_Vector4> m_kVertices;
    S_00de5110_Array<S_00de5110_Triangle> m_uiTriangleCount;

    S_00de5110_Geometry() throw()
    {}
    static void* operator new(unsigned int n) throw()
    {
        return FUN_00c85750().heap().AllocateMemoryBlock(n);
    }
    static void operator delete(void*) throw()
    {}
};

struct S_00de5110_Pyramid
{
    int unk0;
    int unk4;
    S_00de5110_Geometry* m_pSourceGeometry;
    int unkC;
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
    S_00de5110_Vector4 m_apex;

    void FUN_00de4e20(S_00de5110_Vector4* verts);
    void BuildPyramidGeometry();
};

// Allocates a Geometry, sets 5 vertices with the apex at index 4, and adds 4 triangles connecting the base to the apex.
// @fnv 0x00de5110
void S_00de5110_Pyramid::BuildPyramidGeometry()
{
    m_pSourceGeometry = new S_00de5110_Geometry();
    m_pSourceGeometry->m_kVertices.SetSizeAndGrow(5);
    m_pSourceGeometry->m_kVertices[4] = m_apex;
    FUN_00de4e20(m_pSourceGeometry->m_kVertices.begin());
    m_pSourceGeometry->m_uiTriangleCount.expandBy(1)->set(2, 4, 3);
    m_pSourceGeometry->m_uiTriangleCount.expandBy(1)->set(0, 4, 2);
    m_pSourceGeometry->m_uiTriangleCount.expandBy(1)->set(1, 4, 0);
    m_pSourceGeometry->m_uiTriangleCount.expandBy(1)->set(3, 4, 1);
}

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_setzero_ps(void);

union Vec4f
{
    __m128 v;
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } s;
};

struct Vec4i
{
    int x;
    int y;
    int z;
    int w;
};

extern int DAT_010d828c;

class FUN_00de4f20_cls
{
  public:
    FUN_00de4f20_cls* FUN_00de4f20(const Vec4i* p0, const Vec4i* p1, const Vec4i* p2, const Vec4i* p3);

    int m_vptr;              // 0x00
    unsigned short unk04;    // 0x04
    unsigned short m_06;     // 0x06
    int m_08;                // 0x08
    int unk0C;               // 0x0c
    Vec4f m_rot0;            // 0x10
    Vec4f m_rot1;            // 0x20
    Vec4f m_rot2;            // 0x30
    Vec4f m_kAxisEndPoints;  // 0x40
    int m_50;                // 0x50
    int unk54;
    int unk58;
    int unk5C;
    Vec4i m_60;  // 0x60
    Vec4i m_70;  // 0x70
    Vec4i m_80;  // 0x80
    Vec4i m_90;  // 0x90
};

// Sets identity rotation columns, m_50 = 7 and m_06 = 1, zeroes m_kAxisEndPoints, and copies p0, p2, p1, p3 into m_60, m_70, m_80, m_90.
// @fnv 0x00de4f20
FUN_00de4f20_cls* FUN_00de4f20_cls::FUN_00de4f20(const Vec4i* p0, const Vec4i* p1, const Vec4i* p2, const Vec4i* p3)
{
    float one = 1.0f;
    *(volatile int*)&m_08 = 0;
    *(volatile int*)&m_50 = 7;
    *(volatile unsigned short*)&m_06 = 1;
    _mm_store_ps((float*)((char*)this + 0x10), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x20), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x30), _mm_setzero_ps());
    *(volatile float*)&m_rot0.s.x = one;
    *(volatile float*)&m_rot1.s.y = one;
    *(volatile float*)&m_rot2.s.z = one;
    _mm_store_ps((float*)&m_kAxisEndPoints.v, _mm_setzero_ps());
    m_vptr = (int)&DAT_010d828c;
    m_60 = *p0;
    m_70 = *p2;
    m_80 = *p1;
    m_90 = *p3;
    return this;
}

// Today's unit (hkdisplayplane.cpp) defines __m128 and its intrinsics itself;
// declare the one the matched code needs that the unit does not have.
extern "C" __m128 _mm_setzero_ps(void);

struct S_00de4ff0_Vec4
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct S_00de4ff0_Rotation
{
    S_00de4ff0_Vec4 m_kColumn0;
    S_00de4ff0_Vec4 m_kColumn1;
    S_00de4ff0_Vec4 m_kColumn2;

    __forceinline float& operator()(int r, int c)
    {
        return ((float*)this)[c * 4 + r];
    }
    __forceinline void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    __forceinline void setDiagonal(float x, float y, float z)
    {
        setZero();
        (*this)(0, 0) = x;
        (*this)(1, 1) = y;
        (*this)(2, 2) = z;
    }
    __forceinline void setIdentity()
    {
        setDiagonal(1.0f, 1.0f, 1.0f);
    }
};

struct S_00de4ff0_Transform
{
    S_00de4ff0_Rotation m_rotation;
    S_00de4ff0_Vec4 m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct __declspec(novtable) S_00de4ff0_RefObj
{
    virtual void vfn_00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    __forceinline S_00de4ff0_RefObj() throw() : m_sReferenceCount(1)
    {}
};

struct __declspec(novtable) S_00de4ff0_Base : S_00de4ff0_RefObj
{
    int m_field08;
    int unk0C;
    S_00de4ff0_Transform m_kMotionTransform;
    int m_field50;
    int unk54;
    int unk58;
    int unk5C;
    S_00de4ff0_Vec4 m_vec60;
    S_00de4ff0_Vec4 m_vec70;
    S_00de4ff0_Vec4 m_vec80;
    S_00de4ff0_Vec4 m_vec90;

    __forceinline S_00de4ff0_Base() throw() : m_field08(0), m_field50(7)
    {
        m_kMotionTransform.setIdentity();
    }
};

struct FUN_00de4ff0 : S_00de4ff0_Base
{
    FUN_00de4ff0() throw();
};

// Constructor that zero-initialises the four vector fields m_vec60, m_vec70, m_vec80, and m_vec90 after the base class setup.
// @fnv 0x00de4ff0
FUN_00de4ff0::FUN_00de4ff0() throw()
{
    m_vec90.setZero4();
    m_vec60.setZero4();
    m_vec70.setZero4();
    m_vec80.setZero4();
}

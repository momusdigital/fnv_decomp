// src/havok/common/visualize/shape/hkdisplaybox_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaybox.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/visualize/shape/hkdisplaybox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaybox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
struct hkTransform;
struct hkMemoryAllocator;
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void FUN_00c7f640(const hkTransform& t, const hkVector4& p);
    void set(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};
struct hkRotation
{
    hkVector4 c0, c1, c2;
};
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};
__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
struct hkVector4Array
{
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(hkVector4));
        }
        m_iElementCount = n;
    }
};
struct hkBoxGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4 m_vHalfExtents;

    void GetEdgeLines(hkVector4Array& lines, hkMemoryAllocator& alloc);
};
extern "C" __m128 _mm_setzero_ps(void);
struct __declspec(align(16)) Vector4D22DC0
{
    float x;
    float y;
    float z;
    float w;
    void setZero4()
    {
        *reinterpret_cast<__m128*>(this) = _mm_setzero_ps();
    }
    void operator=(const Vector4D22DC0& kOther)
    {
        *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther);
    }
};
struct RotationD22DC0
{
    Vector4D22DC0 m_kColumn0;
    Vector4D22DC0 m_kColumn1;
    Vector4D22DC0 m_kColumn2;
    float& operator()(int iRow, int iCol)
    {
        return reinterpret_cast<float*>(&m_kColumn0 + iCol)[iRow];
    }
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct TransformD22DC0
{
    RotationD22DC0 m_rotation;
    Vector4D22DC0 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct ReferencedD22DC0
{
    ReferencedD22DC0() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0
{
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType)
    {
        m_kMotionTransform.setIdentity();
    }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    TransformD22DC0 m_kMotionTransform;
    int m_type;
};
struct FUN_00d58510 : public ShapeD22DC0
{
    FUN_00d58510(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float fRadius, int iA, int iB) throw();
    virtual ~FUN_00d58510() throw();
    Vector4D22DC0 m_kA;
    Vector4D22DC0 m_kB;
    float m_fBoundRadius;
    int m_iA;
    int m_iB;
};

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
extern "C" void _ReadWriteBarrier();
extern const float DAT_010c4990 = -0.0f;
extern const float DAT_01011d78 = 0.0f;

struct BoxBuild2190AllocCtx
{
    virtual void vf0();
    virtual void* alloc(int size);
};
struct BoxBuild2190Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BoxBuild2190AllocCtx* m_10;
    __forceinline hkMemoryAllocator& heap()
    {
        return *reinterpret_cast<hkMemoryAllocator*>(m_10);
    }
};
BoxBuild2190Router* FUN_00c85750();

struct BoxBuild2190Tri
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};
template <class T> struct BoxBuild2190MatchArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    BoxBuild2190MatchArray() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int doubled = cap * 2;
            int desired = n < doubled ? doubled : n;
            FUN_00c908c0(alloc, this, desired, sizeof(T));
        }
    }
    __forceinline T* append(hkMemoryAllocator& alloc)
    {
        int oldCount = m_iElementCount;
        reserve(alloc, oldCount + 1);
        ++m_iElementCount;
        return m_data + oldCount;
    }
};
struct BoxBuild2190Geom
{
    BoxBuild2190MatchArray<hkVector4> m_verts;
    BoxBuild2190MatchArray<BoxBuild2190Tri> m_tris;
};

struct BoxBuild2190BoxShell
{
    int unk00;
    int unk04;
    BoxBuild2190Geom* m_08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4 m_vHalfExtents;
    void buildGeometry();
};

// @fnv 0x00de2190
void BoxBuild2190BoxShell::buildGeometry()
{
    BoxBuild2190Router* router = FUN_00c85750();
    BoxBuild2190Geom* mem = (BoxBuild2190Geom*)router->m_10->alloc(sizeof(BoxBuild2190Geom));
    BoxBuild2190Geom* geom;
    if (mem)
    {
        mem->m_verts.m_data = 0;
        mem->m_verts.m_iElementCount = 0;
        _ReadWriteBarrier();
        mem->m_verts.m_iCapacityState = (int)0x80000000;
        _ReadWriteBarrier();
        mem->m_tris.m_data = 0;
        mem->m_tris.m_iElementCount = 0;
        mem->m_tris.m_iCapacityState = (int)0x80000000;
        geom = mem;
    }
    else
        geom = 0;
    m_08 = geom;

    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, -m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, -m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, -m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArray<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, -m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }

    for (int i = 0; i < m_08->m_verts.m_iElementCount; i++)
        m_08->m_verts.m_data[i].FUN_00c7f640(m_kMotionTransform, m_08->m_verts.m_data[i]);

    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 3;
        t->m_kPointB = 2;
        t->m_iThirdValue = 1;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 3;
        t->m_kPointB = 1;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 6;
        t->m_kPointB = 7;
        t->m_iThirdValue = 4;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 6;
        t->m_kPointB = 4;
        t->m_iThirdValue = 5;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 4;
        t->m_kPointB = 7;
        t->m_iThirdValue = 3;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 4;
        t->m_kPointB = 3;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 2;
        t->m_kPointB = 6;
        t->m_iThirdValue = 5;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 2;
        t->m_kPointB = 5;
        t->m_iThirdValue = 1;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 7;
        t->m_kPointB = 6;
        t->m_iThirdValue = 2;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 7;
        t->m_kPointB = 2;
        t->m_iThirdValue = 3;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 1;
        t->m_kPointB = 5;
        t->m_iThirdValue = 4;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArray<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &FUN_00c85750()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 1;
        t->m_kPointB = 4;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
}

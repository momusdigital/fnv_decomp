
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexVerticesShape.h"

struct FUN_00d58d60_t
{
    char pad[0x40];
    float* m;
    void getFirstVertex(float* out);
};

// @fnv 0x00d58d60
void FUN_00d58d60_t::getFirstVertex(float* out)
{
    float* p = m;
    out[0] = p[0];
    out[1] = p[4];
    out[2] = p[8];
    out[3] = 0.0f;
}

struct FUN_00d591d0_class
{
    void FUN_00d591d0(void*, float, int);
};

void __cdecl FUN_00d26230(void*, void*, void*, float, int);

// Calls FUN_00d26230 with this+0x20, this+0x30, the float at this+0x10 plus b, and c.
// @fnv 0x00d591d0
void FUN_00d591d0_class::FUN_00d591d0(void* a, float afDelta, int c)
{
    FUN_00d26230(
        a,
        reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x20),
        reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30),
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x10) + afDelta,
        c
    );
}

struct RefObj { void RetainReference(); void removeReference(); };
struct DDCC60World { void removeReference(); };
struct FUN_00d5a320 {
    void FUN_00d59f40();
    void AssignReference(RefObj* p, bool b);
};
// Releases the current reference at this+0x60, stores p there, and if b and p are set calls FUN_00d59f40.
// @fnv 0x00d5a320
void FUN_00d5a320::AssignReference(RefObj* apRef, bool b)
{
    if (apRef) apRef->RetainReference();
    if (*(DDCC60World**)((char*)this + 0x60)) (*(DDCC60World**)((char*)this + 0x60))->removeReference();
    *(RefObj**)((char*)this + 0x60) = apRef;
    if (b && apRef) FUN_00d59f40();
}

struct MemoryManager {
    virtual void Method0();
    virtual void Method1();
    virtual void Free(void* object, unsigned short size);
};

struct MemoryRouter {
    unsigned char m_auiShapeKeys[0x10];
    MemoryManager* m_pMemoryManager;
};

MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d5a4e0_Base {
    void FUN_00d59870();
};

struct FUN_00d5a4e0_StandIn : public FUN_00d5a4e0_Base {
    unsigned char m_auiShapeKeys[4];
    unsigned short m_iElementCount;

    FUN_00d5a4e0_StandIn* FUN_00d5a4e0(unsigned char deleting);
};

// @fnv 0x00d5a4e0
FUN_00d5a4e0_StandIn* FUN_00d5a4e0_StandIn::FUN_00d5a4e0(unsigned char deleting) {
    this->FUN_00d59870();

    if (deleting & 1) {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short size = m_iElementCount;
        MemoryManager* manager = router->m_pMemoryManager;
        manager->Free(this, size);
    }

    return this;
}

struct Vec4 { float x, y, z, w; };

// @fnv 0x00d58d40
static Vec4* __cdecl FUN_00d58d40(Vec4* base, int index)
{
    return base + index;
}

Vec4* caller_d58d40(Vec4* base, int index)
{
    return FUN_00d58d40(base, index);
}

struct FnvCpu_FUN_00d58d10_CpuObject {
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    int value;
    int FUN_00d58d10();
};
// @fnv 0x00d58d10
int FnvCpu_FUN_00d58d10_CpuObject::FUN_00d58d10()
{
    return value;
}

struct FnvCpu_FUN_00d58d50_CpuObject { char* FUN_00d58d50(); };
// @fnv 0x00d58d50
char* FnvCpu_FUN_00d58d50_CpuObject::FUN_00d58d50()
{
    return reinterpret_cast<char*>(this) + 84;
}

struct CallTarget_00d5a410 { int FUN_00d5a410(int, int, int, int, int); };
struct SearchObject {
    int FUN_00d5a4c0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d5a4c0
int SearchObject::FUN_00d5a4c0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiCallResult = (unsigned int)((CallTarget_00d5a410*)this)->FUN_00d5a410((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)uiCallResult;
}

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct hkVec4Q {
    __m128 m_vComponents;
    void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    const float& operator()(int i) const { return ((const float*)&m_vComponents)[i]; }
};
struct hkSphereQ {
    hkVec4Q m_pos;
    hkVec4Q& getPositionAndRadius() { return m_pos; }
};
struct FourVectorsQ { hkVec4Q m_uiX; hkVec4Q m_uiY; hkVec4Q m_uiZ; };
struct ConvexVertsQ : public hkpShape {
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    FourVectorsQ* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;
    hkSphereQ* FillSphereBuffer(hkSphereQ* sphereBuffer) const;
};
// Writes m_kRotatedVertices positions and m_fSphereRadius into sphereBuffer as hkSphereQ entries, returning sphereBuffer.
// @fnv 0x00d58d80
hkSphereQ* ConvexVertsQ::FillSphereBuffer(hkSphereQ* sphereBuffer) const
{
    hkSphereQ* out = sphereBuffer;
    const FourVectorsQ* fv = m_kRotatedVertices;
    int i = m_iStridedVertexCount - 1;
    for (; i >= 3; i -= 4)
    {
        (out++)->getPositionAndRadius().set(fv->m_uiX(0), fv->m_uiY(0), fv->m_uiZ(0), m_fSphereRadius);
        (out++)->getPositionAndRadius().set(fv->m_uiX(1), fv->m_uiY(1), fv->m_uiZ(1), m_fSphereRadius);
        (out++)->getPositionAndRadius().set(fv->m_uiX(2), fv->m_uiY(2), fv->m_uiZ(2), m_fSphereRadius);
        (out++)->getPositionAndRadius().set(fv->m_uiX(3), fv->m_uiY(3), fv->m_uiZ(3), m_fSphereRadius);
        fv++;
    }
    if (i >= 0) (out++)->getPositionAndRadius().set(fv->m_uiX(0), fv->m_uiY(0), fv->m_uiZ(0), m_fSphereRadius);
    if (i >= 1) (out++)->getPositionAndRadius().set(fv->m_uiX(1), fv->m_uiY(1), fv->m_uiZ(1), m_fSphereRadius);
    if (i >= 2) (out++)->getPositionAndRadius().set(fv->m_uiX(2), fv->m_uiY(2), fv->m_uiZ(2), m_fSphereRadius);
    return sphereBuffer;
}

namespace fnv_00d59cc0 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_unpacklo_ps(__m128, __m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_movelh_ps(__m128, __m128);
__m128 _mm_movehl_ps(__m128, __m128);
}

typedef __m128 hkQuadReal;

extern const hkQuadReal hkQuadRealSignMask;

struct hkSimdRealq
{
    hkQuadReal m_vValue;
};

struct hkMatrix3q;

struct hkVector4q
{
    hkQuadReal m_vComponents;

    __forceinline void operator=(const hkVector4q& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setNeg4(const hkVector4q& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, hkQuadRealSignMask); }
    __forceinline void _setRotatedInverseDir(const hkMatrix3q& r, const hkVector4q& b);
    void SetRotatedDirection(const hkMatrix3q& r, const hkVector4q& b) throw();
    __forceinline hkSimdRealq dot4xyz1(const hkVector4q& a) const
    {
        const hkQuadReal xx = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const hkQuadReal x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
        const hkQuadReal x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        hkSimdRealq r;
        r.m_vValue = _mm_add_ps(x3, x2);
        return r;
    }
    __forceinline void setW(const hkSimdRealq& w)
    {
        const hkQuadReal ww = _mm_shuffle_ps(w.m_vValue, w.m_vValue, 0);
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, ww), 0xc4);
    }
};

struct hkMatrix3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

struct hkTransformq
{
    hkMatrix3q m_rotation;
    hkVector4q m_vTranslation;
};

__forceinline void hkVector4q::_setRotatedInverseDir(const hkMatrix3q& r, const hkVector4q& b)
{
    hkQuadReal c0 = r.m_kColumn0.m_vComponents;
    hkQuadReal c1 = r.m_kColumn1.m_vComponents;
    hkQuadReal c2 = r.m_kColumn2.m_vComponents;
    const hkQuadReal t0 = _mm_unpacklo_ps(c0, c1);
    const hkQuadReal t1 = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(t0, c2);
    c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, t0), c2, 0xd4);
    c2 = _mm_shuffle_ps(t1, c2, 0xe4);
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

union hkVector4U
{
    hkVector4 m_vec;
    hkQuadReal m_vComponents;
};

struct hkMemoryAllocatorq
{
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkThreadMemoryq
{
    char* m_stackTop;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorq* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorq& heap() { return *m_pStreamAllocator; }
};

void* __cdecl FUN_00c85750() throw();

static __forceinline hkThreadMemoryq* hkGetThreadMemory() { return (hkThreadMemoryq*)FUN_00c85750(); }

template <class T>
struct hkArrayq
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArrayq() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayq()
    {
        hkMemoryAllocatorq& alloc = hkGetThreadMemory()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
    __forceinline T* begin() { return m_data; }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
};

template <class T>
__forceinline T* hkAllocateStack(int n)
{
    hkThreadMemoryq* mem = hkGetThreadMemory();
    char* p = mem->m_stackTop;
    mem->m_stackTop = p + ((n * sizeof(T) + 127) & ~127);
    return (T*)p;
}

template <class T>
__forceinline void hkDeallocateStack(T* p)
{
    hkGetThreadMemory()->m_stackTop = (char*)p;
}

template <class T>
struct hkLocalArrayq : public hkArrayq<T>
{
    T* m_pStackAllocation;

    __forceinline hkLocalArrayq(int n)
    {
        this->m_data = hkAllocateStack<T>(n);
        m_pStackAllocation = this->m_data;
        this->m_iCapacityState = n | 0x80000000;
    }
    __forceinline ~hkLocalArrayq()
    {
        if (m_pStackAllocation == this->m_data)
        {
            this->m_iElementCount = 0;
        }
        hkDeallocateStack<T>(m_pStackAllocation);
    }
};

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors, hkVector4q* vectorsOut)
{
    hkVector4U c0;
    c0.m_vec = t.m_rotation.m_kColumn0;
    hkVector4U c1;
    c1.m_vec = t.m_rotation.m_kColumn1;
    hkVector4U c2;
    c2.m_vec = t.m_rotation.m_kColumn2;
    hkVector4U trans;
    trans.m_vec = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        const hkQuadReal b = vectorsIn[i].m_vComponents;
        const hkQuadReal b0 = _mm_shuffle_ps(b, b, 0x00);
        const hkQuadReal r0 = _mm_mul_ps(c0.m_vComponents, b0);
        const hkQuadReal b1 = _mm_shuffle_ps(b, b, 0x55);
        const hkQuadReal r1 = _mm_mul_ps(c1.m_vComponents, b1);
        const hkQuadReal b2 = _mm_shuffle_ps(b, b, 0xaa);
        const hkQuadReal r2 = _mm_mul_ps(c2.m_vComponents, b2);
        vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, trans.m_vComponents));
    }
    while (--i >= 0);
}

static __forceinline void hkTransformPlaneEquations(const hkTransformq& t, const hkVector4q* planes, int numPlanes, hkVector4q* planesOut)
{
    hkMatrix3q rotation;
    rotation.m_kColumn0 = t.m_rotation.m_kColumn0;
    rotation.m_kColumn1 = t.m_rotation.m_kColumn1;
    rotation.m_kColumn2 = t.m_rotation.m_kColumn2;
    hkVector4q tr;
    tr.setNeg4(t.m_vTranslation);
    hkVector4q pivotShift;
    pivotShift._setRotatedInverseDir(rotation, tr);

    int i = numPlanes - 1;
    do
    {
        const hkSimdRealq newDist = planes->dot4xyz1(pivotShift);
        planesOut->SetRotatedDirection(rotation, *planes);
        planesOut->setW(newDist);
        planes++;
        planesOut++;
    }
    while (--i >= 0);
}

class hkpConvexVerticesShapeq : public hkpShape
{
public:
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v0a() throw();
    virtual int getNumCollisionSpheres() const throw();

    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    void* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;
    void* m_pConvexPiece;
    hkVector4q* m_planeData;
    int m_iPlaneCount;
    int m_planeCapacity;

    void FUN_00d59200(hkArrayq<hkVector4q>& vertices) const throw();
    void FUN_00d59900(const float* vertices, int striding, int numVertices) throw();
    void Transform(const hkTransform& t);
};

// Gets the vertices, transforms them by t, calls FUN_00d59900 with them, then transforms the m_planeData plane equations in place by t.
// @fnv 0x00d59cc0
void hkpConvexVerticesShapeq::Transform(const hkTransform& t)
{
    hkLocalArrayq<hkVector4q> vertices(getNumCollisionSpheres());
    FUN_00d59200(vertices);
    hkTransformPoints(t, vertices.begin(), vertices.GetLogicalSize(), vertices.begin());
    FUN_00d59900((const float*)vertices.begin(), sizeof(hkVector4q), vertices.GetLogicalSize());
    hkTransformPlaneEquations((const hkTransformq&)t, m_planeData, m_iPlaneCount, m_planeData);
}
}  // namespace fnv_00d59cc0

struct AllocatorD5A360 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct RouterD5A360 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorD5A360* m_pkHeap;
};
RouterD5A360* GetRouterD5A360();
struct __declspec(align(16)) Vector4D5A360 {
    float x;
    float y;
    float z;
    float w;
    void operator=(const Vector4D5A360& v) { *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&v); }
};
template <class T> __forceinline void CopyD5A360(T* pDst, const T* pSrc, int iEntryIndex)
{
    for (int i = 0; i < iEntryIndex; i++)
        pDst[i] = pSrc[i];
}
template <class T> struct ArrayD5A360 {
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline ArrayD5A360& operator=(const ArrayD5A360& a)
    {
        AllocatorD5A360& kAlloc = *GetRouterD5A360()->m_pkHeap;
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        CopyD5A360(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct ConvexD5A360 {
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
    ArrayD5A360<Vector4D5A360> m_kVertices;
    int m_iConnectivity;
    void FUN_00d59f40();
    void SetVertices(const ArrayD5A360<Vector4D5A360>& kVertices);
};

// Copies kVertices into m_kVertices and calls FUN_00d59f40 if m_iConnectivity is nonzero.
// @fnv 0x00d5a360
void ConvexD5A360::SetVertices(const ArrayD5A360<Vector4D5A360>& kVertices)
{
    m_kVertices = kVertices;
    if (m_iConnectivity)
        FUN_00d59f40();
}

struct FUN_00d58d20
{
    char pad[0x30];
    __m128 m_kAabbCenter; // +0x30
    void GetCentre(__m128* out);
};

// @fnv 0x00d58d20
void FUN_00d58d20::GetCentre(__m128* out)
{
    *out = m_kAabbCenter;
}

class hkpConvexVerticesShapeFourVectors
{
public:
    hkReal m_uiX[4];
    hkReal m_uiY[4];
    hkReal m_uiZ[4];
};

struct Vector4WithInt24W
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkUint32 w;
    hkReal& operator()(int i) { return (&x)[i]; }
    void set(hkReal a, hkReal b, hkReal c) { x = a; y = b; z = c; }
    void setInt24W(int value) { w = (hkUint32)value | 0x3f000000; }
};

typedef hkUint16 hkpVertexId;

class hkpConvexVerticesShapeImpl : public hkpConvexVerticesShape
{
public:
    void convertVertexIdsToVerticesImpl(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
};

// Copies numIds rotated vertex positions from m_kRotatedVertices into verticesOut, packing each vertexId into the w field.
// @fnv 0x00d59060
void hkpConvexVerticesShapeImpl::convertVertexIdsToVerticesImpl(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const
{
    int i = numIds - 1;
    __assume(i >= 0);
    for (; i >= 0; i--)
    {
        int vertexId = ids[0];
        const hkpConvexVerticesShapeFourVectors& fv = m_kRotatedVertices.m_data[vertexId >> 2];
        int a = vertexId & 3;
        Vector4WithInt24W& v = verticesOut[0];
        v(0) = fv.m_uiX[a];
        v(1) = fv.m_uiY[a];
        v(2) = fv.m_uiZ[a];
        v.setInt24W(vertexId);
        verticesOut++;
        ids++;
    }
}

class SpliceAllocator;
struct AlignedSpliceVector {__m128 value;};
void __cdecl FUN_00c908c0(SpliceAllocator& allocator,void* array,int capacity,int elementBytes);
void __cdecl FUN_00d2cc70(void* destination,const void* source,unsigned bytes);
struct VectorSpliceArray {
    AlignedSpliceVector* data;
    int size;
    int capacityAndFlags;
    void FUN_00d5a410(SpliceAllocator& allocator,int first,int removeCount,const AlignedSpliceVector* source,int insertCount);
};
// Removes removeCount elements at first, inserts insertCount elements from source, and grows the buffer via FUN_00c908c0 if capacity is insufficient.
// @fnv 0x00d5a410
void VectorSpliceArray::FUN_00d5a410(SpliceAllocator& allocator,int first,int removeCount,const AlignedSpliceVector* source,int insertCount) {
    int newSize=size-removeCount+insertCount;
    int tailCount=size-first-removeCount;
    if((capacityAndFlags&0x3fffffff)<newSize) {
        int requested=(capacityAndFlags&0x3fffffff)*2;
        if(newSize>=requested)requested=newSize;
        FUN_00c908c0(allocator,this,requested,sizeof(AlignedSpliceVector));
    }
    FUN_00d2cc70(data+first+insertCount,data+first+removeCount,tailCount*sizeof(AlignedSpliceVector));
    AlignedSpliceVector* destination=data+first;
    for(int i=0;i<insertCount;++i) {
        __m128 value=source[i].value;
        destination[i].value=value;
    }
    size=newSize;
}

class hkMemoryAllocatorD598 {
public:
    virtual ~hkMemoryAllocatorD598() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD598 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD598* m_pStreamAllocator;

    hkMemoryAllocatorD598& heap() { return *m_pStreamAllocator; }
};

extern "C" hkMemoryRouterD598& __cdecl FUN_00c85750() throw();

template <class T>
class hkArrayD598 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD598() throw()
    {
        hkMemoryAllocatorD598& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD598 {
    class hkBaseObject {
    public:
        virtual ~hkBaseObject() throw() {}
    };

    class hkReferencedObject : public hkBaseObject {
    public:
        unsigned short m_usMemSizeAndFlags;
        short m_sReferenceCount;
        void FUN_00c905b0() throw();
    };

    class hkpShape : public hkReferencedObject {
    public:
        unsigned long m_ulUserData;
        int m_type;
    };

    class hkpSphereRepShape : public hkpShape {
    };

    class hkpConvexShape : public hkpSphereRepShape {
    public:
        float m_fSphereRadius;
    };

    struct hkVector4D598 {
        float x, y, z, w;
    };

    struct hkFourTransposedPointsD598 {
        hkVector4D598 m_uiX, m_uiY, m_uiZ;
    };
}

namespace FUN_00d59870 {
    class hkpConvexVerticesShape : public hkD598::hkpConvexShape {
    public:
        virtual ~hkpConvexVerticesShape();

        int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
        hkArrayD598<hkD598::hkFourTransposedPointsD598> m_kRotatedVertices;
        int m_iStridedVertexCount;
        int unk50;
        hkArrayD598<hkD598::hkVector4D598> m_kVertexPositions;
        hkD598::hkReferencedObject* m_pConnectivity;
    };

// Releases the m_pConnectivity referenced object by calling FUN_00c905b0 if it is not null.
// @fnv 0x00d59870
    hkpConvexVerticesShape::~hkpConvexVerticesShape()
    {
        if (m_pConnectivity)
            m_pConnectivity->FUN_00c905b0();
    }
}

extern "C" __m128 _mm_load_ps(const float*);
struct SelectBits { __m128 v; };
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_or_ps(__m128 a, __m128 b);

struct MatchVector
{
    __m128 m_vComponents;

    MatchVector() {}
 SelectBits compare(const MatchVector& a) const { SelectBits result; result.v=_mm_cmplt_ps(m_vComponents,a.m_vComponents); return result; }
    MatchVector(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    MatchVector(float v)
    {
        m_vComponents.m128_f32[0] = v;
        m_vComponents.m128_f32[1] = v;
        m_vComponents.m128_f32[2] = v;
        m_vComponents.m128_f32[3] = v;
    }
    void operator=(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
    void setMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents); }
    void addMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents)); }
    void add4(const MatchVector& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void setSelect4(const SelectBits& comp, const MatchVector& trueValue, const MatchVector& falseValue) { m_vComponents = _mm_or_ps(_mm_and_ps(comp.v, trueValue.m_vComponents), _mm_andnot_ps(comp.v, falseValue.m_vComponents)); }
    void selectIndex(const SelectBits& comp,const MatchVector& trueValue,const MatchVector& falseValue) {m_vComponents=_mm_or_ps(_mm_and_ps(comp.v,trueValue.m_vComponents),_mm_andnot_ps(_mm_load_ps((const float*)&comp.v),falseValue.m_vComponents));}
void setInt24W(int value) { ((int*)&m_vComponents)[3] = value | 0x3f000000; }
};

extern const MatchVector DAT_010d9fe0;
extern const MatchVector DAT_010d0fa0;

struct hkFourTransposedPointsQ
{
    MatchVector m_uiX;
    MatchVector m_uiY;
    MatchVector m_uiZ;
};

struct MatchShape : public hkpShape
{
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    hkFourTransposedPointsQ* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;

    void getSupportingVertexImpl(const MatchVector& direction, MatchVector& supportingVertexOut) const;
};

// Finds the vertex with the maximum dot product against direction and writes its position and index to supportingVertexOut.
// @fnv 0x00d58ee0
void MatchShape::getSupportingVertexImpl(const MatchVector& direction, MatchVector& supportingVertexOut) const
{
    const hkFourTransposedPointsQ* fv = m_kRotatedVertices;
    static const MatchVector minusMax(-3.40282e+38f);

    MatchVector bestDot = minusMax;
    MatchVector bestIndices;
    bestIndices.m_vComponents = _mm_setzero_ps();
    MatchVector curIndices = DAT_010d9fe0;

    MatchVector dirX;
    dirX.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x00);
    MatchVector dirY;
    dirY.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x55);
    MatchVector dirZ;
    dirZ.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xaa);

    const hkFourTransposedPointsQ* p = fv;
    for (int i = 0; i < m_rotatedSize * 4; i += 4)
    {
        MatchVector dot;
        dot.setMul4(p->m_uiX,dirX); dot.addMul4(p->m_uiY,dirY); dot.addMul4(p->m_uiZ,dirZ);
        SelectBits mask = bestDot.compare(dot);
        bestDot.setSelect4(mask, dot, bestDot);
        bestIndices.selectIndex(mask,curIndices,bestIndices);
        curIndices.m_vComponents = _mm_add_ps(DAT_010d0fa0.m_vComponents,curIndices.m_vComponents);
        p++;
    }

    int a = (bestDot(0) > bestDot(1)) ? 0 : 1;
    int b = (bestDot(2) > bestDot(3)) ? 2 : 3;
    int best = (bestDot(a) > bestDot(b)) ? a : b;
    int vertexId = (int)bestIndices(best);

    const hkFourTransposedPointsQ& v = fv[(unsigned int)vertexId >> 2];
    int k = vertexId & 3;
    supportingVertexOut(0) = v.m_uiX(k);
    supportingVertexOut(1) = v.m_uiY(k);
    supportingVertexOut(2) = v.m_uiZ(k);
    supportingVertexOut.setInt24W(vertexId);
}

extern void* DAT_010d0fc4;
extern "C" void _ReadWriteBarrier();


struct InputValues {
    int x;
    int y;
    int z;
};

struct FinalCall {
    void FUN_00d59900(int x, int z, int y);
};

__forceinline void AllocateVectors(
    AllocatorD5A360& allocator,
    int count,
    Vector4D5A360*& data,
    int& capacity)
{
    int bytes = count * 16;
    data = static_cast<Vector4D5A360*>(allocator.AllocateBufferWithSize(bytes));
    capacity = bytes / 16;
}

__forceinline void ResizePlanes(
    ArrayD5A360<Vector4D5A360>& planes,
    const ArrayD5A360<Vector4D5A360>& source)
{
    AllocatorD5A360& allocator = reinterpret_cast<AllocatorD5A360&>(FUN_00c85750().heap());

    if ((planes.m_iCapacityState & 0x3fffffff) < source.m_iElementCount) {
        if ((planes.m_iCapacityState & 0x80000000) == 0)
            allocator.ReturnMemory(
                planes.m_data,
                (planes.m_iCapacityState & 0x3fffffff) * 16);

        AllocateVectors(
            allocator,
            source.m_iElementCount,
            planes.m_data,
            planes.m_iCapacityState);
    }

    planes.m_iElementCount = source.m_iElementCount;
    CopyD5A360(planes.m_data, source.m_data, planes.m_iElementCount);
}


template<class T> struct ConstructedArray : ArrayD5A360<T> {
    __forceinline ConstructedArray() : ArrayD5A360<T>() {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct RefPart {
    void** m_ppVirtualMethodTable;
    unsigned short unk04;
    unsigned short referenceCount;
    __forceinline RefPart() : referenceCount(1) {}
};
struct ShapePart : RefPart {
    int userData;
    int type;
    __forceinline ShapePart(int shapeType) { userData = 0; type = shapeType; m_ppVirtualMethodTable = &DAT_010d0fc4; }
};
struct SpherePart : ShapePart {
    __forceinline SpherePart(int shapeType) : ShapePart(shapeType) {}
};
struct ConvexPart : SpherePart {
    float radius;
    __forceinline ConvexPart(int shapeType, float r) : SpherePart(shapeType) { radius = r; }
};
struct FUN_00d59bd0 : ConvexPart {
    int unk14;
    int unk18;
    int unk1C;
    Vector4D5A360 halfExtents;
    Vector4D5A360 center;
    ConstructedArray<Vector4D5A360> rotated;
    int numVertices;
    int convexPiece;
    ConstructedArray<Vector4D5A360> planes;
    int connectivity;

    FUN_00d59bd0(
        InputValues* input,
        const ArrayD5A360<Vector4D5A360>& source,
        float r);
};


// Constructs the base with type 6 and radius r, copies source into planes, then calls FUN_00d59900 with input->x, input->z and input->y.
// @fnv 0x00d59bd0
FUN_00d59bd0::FUN_00d59bd0(InputValues* input, const ArrayD5A360<Vector4D5A360>& source, float r)
    : ConvexPart(6, r), convexPiece(0), connectivity(0)
{
    ResizePlanes(planes, source);
    ((FinalCall*)this)->FUN_00d59900(input->x, input->z, input->y);
}

extern "C" __m128 _mm_set_ss(float);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_loadu_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned long DAT_0126835c;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern __m128 DAT_010c7160;
extern float DAT_01012054;

struct ConvexPiece;


struct TimerRec { const char* m_name; unsigned int m_uiCommandId; unsigned int unk08; };
struct TimerStream { int unk00; TimerRec* m_cur; int unk08; TimerRec* m_kRayEnd; };

__forceinline void TimerMark(const char* name, int kind)
{
    TimerStream* s = (TimerStream*)TlsGetValue(DAT_0126835c);
    TimerRec* r = s->m_cur;
    if (r < s->m_kRayEnd) {
        r->m_name = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uiCommandId = t;
        s->m_cur = r + 1;
    }
}

__forceinline void TimerMarkOut(const char* name, int kind)
{
    TimerStream* s = (TimerStream*)TlsGetValue(DAT_0126835c);
    TimerRec* r = s->m_cur;
    if (r < s->m_kRayEnd) {
        r->m_name = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uiCommandId = t;
        s->m_cur = r + 1;
    }
}

struct hkBoolRet {
    char m_cBooleanValue;
    hkBoolRet(bool b) { m_cBooleanValue = (char)b; }
};

struct __declspec(align(16)) V4 { float x, y, z, w; };
struct FourVecs { float xs[4]; float ys[4]; float zs[4]; };

void __cdecl ResizeAudioStream(void*, void*, int);

struct PlaneArr { V4* m_data; int m_iElementCount; int m_iCapacityState; };

struct ConvexPiece {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    const unsigned char* m_bytes;
    int unk20, unk24;
    const unsigned short* m_kIndices;
    int m_numFaces;
};

struct RayInput { V4 m_vFrom; V4 m_vTo; };
struct RayOutput {
    V4 m_vHitNormal;
    float m_fHitFraction;
    int unk14, unk18, unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

struct ConvexVertsShape {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FourVecs* m_rotated;
    int m_rotatedSize;
    int m_rotatedCap;
    int m_iStridedVertexCount;
    ConvexPiece* m_piece;
    PlaneArr m_kPlaneArray;
    hkBoolRet FUN_00d592a0(const RayInput& input, RayOutput& results);
};

static __forceinline float LowFloat(__m128 a) { float x; _mm_store_ss(&x, a); return x; }

static __forceinline void GetVert(V4& p, const FourVecs* fv, unsigned int b)
{
    unsigned int c = b & 3;
    const FourVecs& g = fv[b >> 2];
    p.x = g.xs[c];
    p.y = g.ys[c];
    p.z = g.zs[c];
}

static __forceinline float Dot4xyz1(const V4& p, const V4& v)
{
    __m128 q = *(const __m128*)&p;
    __m128 xx = _mm_mul_ps(q, *(const __m128*)&v);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    __m128 zw = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(q, q, 0xff));
    float r;
    _mm_store_ss(&r, _mm_add_ps(xy, zw));
    return r;
}

// @fnv 0x00d592a0
hkBoolRet ConvexVertsShape::FUN_00d592a0(const RayInput& input, RayOutput& results)
{
    TimerMark("TtrcConvexVert", 0);
    if (m_kPlaneArray.m_iElementCount == 0) {
        ConvexPiece* buildPiece = m_piece;
        if (buildPiece) {
            const unsigned short* face = buildPiece->m_kIndices;
            int n = buildPiece->m_numFaces - 1;
            if (n > 0) {
                struct FaceScratch { V4 p1, p0, p2, plane; __m128 zero, three, half; };
                FaceScratch scratch;
                scratch.zero = _mm_set_ss(DAT_01011d78);
                scratch.three = _mm_set_ss(DAT_01017718);
                scratch.half = _mm_set_ss(DAT_01016248);
                PlaneArr* arr = &m_kPlaneArray;
                int count = n;
                do {
                    const unsigned char* tri = buildPiece->m_bytes + *face;
                    GetVert(scratch.p0, m_rotated, tri[0]);
                    GetVert(scratch.p1, m_rotated, tri[1]);
                    GetVert(scratch.p2, m_rotated, tri[2]);
                    __m128 a = *(__m128*)&scratch.p0;
                    __m128 d1 = _mm_sub_ps(*(__m128*)&scratch.p1, a);
                    __m128 d2 = _mm_sub_ps(*(__m128*)&scratch.p2, a);
                    __m128 cross = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0xc9), _mm_shuffle_ps(d2, d2, 0xd2)),
                        _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0xd2), _mm_shuffle_ps(d2, d2, 0xc9)));
                    __m128 sq = _mm_mul_ps(cross, cross);
                    __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
                    len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), len);
                    __m128 r = _mm_rsqrt_ss(len);
                    __m128 scale = _mm_mul_ss(_mm_mul_ss(scratch.half, r),
                        _mm_sub_ss(scratch.three, _mm_mul_ss(_mm_mul_ss(len, r), r)));
                    scale = _mm_andnot_ps(_mm_cmpeq_ss(len, scratch.zero), scale);
                    *(__m128*)&scratch.plane = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), cross);
                    __m128 pd = _mm_mul_ps(*(__m128*)&scratch.plane, a);
                    __m128 dot = _mm_add_ss(_mm_shuffle_ps(pd, pd, 0x55), pd);
                    dot = _mm_add_ss(_mm_shuffle_ps(pd, pd, 0xaa), dot);
                    scratch.plane.w = LowFloat(_mm_sub_ss(DAT_010c7160, dot));
                    hkMemoryRouterD598& router = FUN_00c85750();
                    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
                        ResizeAudioStream(router.m_pStreamAllocator, arr, 0x10);
                    }
                    *(__m128*)&arr->m_data[arr->m_iElementCount] = *(__m128*)&scratch.plane;
                    arr->m_iElementCount++;
                    ++face;
                } while (--count != 0);
            }
        }
    }

    float lo = -1.0f;
    float hi = results.m_fHitFraction;
    __m128 best = _mm_setzero_ps();
    int i = m_kPlaneArray.m_iElementCount - 1;
    if (i >= 0) {
    ConvexPiece* piece = m_piece;
    __m128 from = *(const __m128*)&input.m_vFrom;
    __m128 to = *(const __m128*)&input.m_vTo;
    do {
        __m128 q;
        if(piece) q = *(const __m128*)&m_kPlaneArray.m_data[i];
        else q = _mm_load_ps(&m_kPlaneArray.m_data[i].x);
        __m128 a = _mm_mul_ps(q, from);
        __m128 axy = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        __m128 azw = _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), _mm_shuffle_ps(q, q, 0xff));
        float d0 = LowFloat(_mm_add_ps(axy, azw));
        __m128 b = _mm_mul_ps(q, to);
        __m128 bxy = _mm_add_ss(_mm_shuffle_ps(b, b, 0x55), b);
        __m128 bzw = _mm_add_ss(_mm_shuffle_ps(b, b, 0xaa), _mm_shuffle_ps(q, q, 0xff));
        float d1 = LowFloat(_mm_add_ps(bxy, bzw));
        if (d0 >= 0.0f) {
            if (d1 >= 0.0f) {
                TimerMarkOut("Et", 1);
                return false;
            }
            float t = (float)(d0 / (d0 - d1));
            if (t >= lo) {
                lo = t;
                best = q;
            }
        }
        else {
            if (!(d1 >= 0.0f)) {
                continue;
            }
            float t = (float)(d0 / (d0 - d1));
            if (!(t > hi)) {
                hi = t;
            }
        }
        if (hi < lo) {
            TimerMarkOut("Et", 2);
            return false;
        }
    } while (--i >= 0);
    }
    if (lo < 0.0f) {
        TimerMarkOut("Et", 3);
        return false;
    }
    results.m_fHitFraction = lo;
    *(__m128*)&results.m_vHitNormal = best;
    results.m_uiShapeKeys[results.m_uiShapeKeyIndex] = -1;
    TimerMarkOut("Et", 0);
    return true;
}

struct VertArray96Q {
    hkVec4Q* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkVec4Q& operator[](int i) { return m_data[i]; }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorD598& alloc = FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(reinterpret_cast<SpliceAllocator&>(alloc), this, newSize, sizeof(hkVec4Q));
        }
        m_iElementCount = n;
    }
};

struct ConvexVertsQ_d59200 : ConvexVertsQ {
    void FUN_00d59200(VertArray96Q& vertices) const;
};

// @fnv 0x00d59200
void ConvexVertsQ_d59200::FUN_00d59200(VertArray96Q& vertices) const
{
    vertices.SetSizeAndGrow(m_iStridedVertexCount);
    for (int i = 0; i < m_iStridedVertexCount; i++)
    {
        int a = i / 4;
        int b = i & 3;
        vertices[i].set(m_kRotatedVertices[a].m_uiX(b), m_kRotatedVertices[a].m_uiY(b), m_kRotatedVertices[a].m_uiZ(b), 0.0f);
    }
}

extern __m128 DAT_010c71d0;

struct hkMemoryAllocator;
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};
NineIntegerRecord* GetMemoryRouter_c85750();
void __cdecl ArrayUtilReserve_c908c0(hkMemoryAllocator& alloc, void* array, int numElements, int sizeElem);

struct FourFloatVector
{
    __m128 m_vComponents;
    __forceinline float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct FourVectors
{
    FourFloatVector m_uiX;
    FourFloatVector m_uiY;
    FourFloatVector m_uiZ;
};

template <class T> struct Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ArrayUtilReserve_c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) { _setSize(GetMemoryRouter_c85750()->heap(), n); }
    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct Aabb
{
    FourFloatVector m_kMinimumCorner;
    FourFloatVector m_kMaximumCorner;

    __forceinline void getCenter(FourFloatVector& center) const
    {
        center.m_vComponents = _mm_mul_ps(_mm_add_ps(m_kMinimumCorner.m_vComponents, m_kMaximumCorner.m_vComponents), DAT_010c71d0);
    }
    __forceinline void getHalfExtents(FourFloatVector& halfExtents) const
    {
        halfExtents.m_vComponents = _mm_mul_ps(_mm_sub_ps(m_kMaximumCorner.m_vComponents, m_kMinimumCorner.m_vComponents), DAT_010c71d0);
    }
};

void __cdecl CalcAabb_cbeaf0(const float* vertexArray, int numVertices, int striding, Aabb& aabbOut);

struct ConvexVerticesShape
{
    void* vtable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    float unk14;
    float unk18;
    float unk1C;
    FourFloatVector m_kAabbHalfExtents;
    FourFloatVector m_kAabbCenter;
    Array<FourVectors> m_kRotatedVertices;
    int m_iStridedVertexCount;

    void FUN_00d59900(const float* vertexIn, int byteStriding, int numVertices);
};

// Stores numVertices, copies vertexIn into m_kRotatedVertices padded to a multiple of four, and computes the AABB center and half-extents.
// @fnv 0x00d59900
void ConvexVerticesShape::FUN_00d59900(const float* vertexIn, int byteStriding, int numVertices)
{
    m_iStridedVertexCount = numVertices;
    int paddedSize = (numVertices + 3) & ~3;
    m_kRotatedVertices.SetSizeAndGrow(paddedSize / 4);

    const float* v = vertexIn;
    int i;
    for (i = 0; i < numVertices; i++)
    {
        int a = (unsigned)i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
        v = (const float*)((const char*)v + byteStriding);
    }

    v = (const float*)((const char*)v - byteStriding);
    // i == numVertices <= paddedSize; strict < drops the unroller's redundant
    // overflow guard. Equality still exits through the scalar cmp.
    __assume(i < paddedSize);
    for (; i < paddedSize; i++)
    {
        int a = i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
    }

    Aabb aabb;
    CalcAabb_cbeaf0(vertexIn, numVertices, byteStriding, aabb);
    aabb.getHalfExtents(m_kAabbHalfExtents);
    aabb.getCenter(m_kAabbCenter);
}

// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConvexVerticesShape.h"
struct FUN_00d58d60_t
{
    char pad[0x40];
    float* m;
    void getFirstVertex(float* out);
};
struct FUN_00d591d0_class
{
    void FUN_00d591d0(void*, float, int);
};
void __cdecl FUN_00d26230(void*, void*, void*, float, int);
struct RefObj { void RetainReference(); void removeReference(); };
struct DDCC60World { void removeReference(); };
struct FUN_00d5a320 {
    void FUN_00d59f40();
    void AssignReference(RefObj* p, bool b);
};
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
struct Vec4 { float x, y, z, w; };
static Vec4* __cdecl FUN_00d58d40(Vec4* base, int index);
Vec4* caller_d58d40(Vec4* base, int index);
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
struct FnvCpu_FUN_00d58d50_CpuObject { char* FUN_00d58d50(); };
struct CallTarget_00d5a410 { int FUN_00d5a410(int, int, int, int, int); };
struct SearchObject {
    int FUN_00d5a4c0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
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
struct FUN_00d58d20
{
    char pad[0x30];
    __m128 m_kAabbCenter; // +0x30
    void GetCentre(__m128* out);
};
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

extern "C" {

__m128 _mm_sub_ps(__m128,__m128);

__m128 _mm_mul_ps(__m128,__m128);

__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);

__m128 _mm_add_ss(__m128,__m128);

__m128 _mm_set_ps1(float);

void _mm_store_ss(float*,__m128);

}



extern "C" double __cdecl sqrt(double) throw();





struct Allocator {

    virtual void Method0();

    virtual void Method1();

    virtual void Method2();

    virtual void* allocateChunk(int* reqSizeInOut) throw();

    virtual void deallocateChunk(void* ptr, int size) throw();

};



struct ThreadMemory {

    void* m_stackCurrent;

    int unk04;

    int unk08;

    int unk0C;

    Allocator* m_pMemoryAllocator;



    Allocator& heap() throw() { return *m_pMemoryAllocator; }

};



class hkpConvexVerticesConnectivity : public hkReferencedObject {

public:

    hkArray<hkUint16> m_kVertexIndices;

    hkArray<hkUint8> m_kNumVerticesPerFace;

};



struct FUN_00d59200_Helper {

    void FUN_00d59200(void* vertices) throw();

};



struct FUN_00d5a4c0_Helper {

    void FUN_00d5a4c0(void* mem, int index, const void* src, int num) throw();

};



static __forceinline void copyVecs(hkVector4* dst, const hkVector4* src, int n) throw() {

    for (int i = 0; i < n; ++i) {

        *(__m128*)&dst[i] = *(const __m128*)&src[i];

    }

}



static __forceinline void copy16(void* dst, const void* src) throw() {

    unsigned __int64* d = (unsigned __int64*)dst;

    const unsigned __int64* s = (const unsigned __int64*)src;

    int i = 0;

    do {

        d[i] = s[i];

    } while (++i < 2);

}



struct PlaneArray {

    hkVector4* m_data;

    int m_iElementCount;

    int m_iCapacityState;



    __forceinline PlaneArray(hkpConvexVerticesShape* shape) throw() {

        m_data = 0;

        m_iCapacityState = 0x80000000;

        const hkArray<hkVector4>& other = shape->m_kVertexPositions;

        Allocator& alloc = ((ThreadMemory*)&FUN_00c85750())->heap();

        if (other.m_iElementCount > 0) {

            int req = other.m_iElementCount * 16;

            m_data = (hkVector4*)alloc.allocateChunk(&req);

            m_iCapacityState = req / 16;

        }

        m_iElementCount = other.m_iElementCount;

        copyVecs(m_data, other.m_data, m_iElementCount);

    }



    int GetLogicalSize() const throw() { return m_iElementCount; }

    hkVector4& operator[](int i) throw() { return m_data[i]; }

    hkVector4* begin() throw() { return m_data; }

    void removeAt(int index) throw() {

        m_iElementCount--;

        if (m_iElementCount != index) {

            copy16(&m_data[index], &m_data[m_iElementCount]);

        }

    }



    __forceinline void ClearAndRelease(Allocator& alloc) throw() {

        m_iElementCount = 0;

        if ((m_iCapacityState & 0x80000000) == 0) {

            alloc.deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * 16);

        }

        m_data = 0;

        m_iCapacityState = 0x80000000;

    }



    __forceinline ~PlaneArray() throw() {

        ClearAndRelease(((ThreadMemory*)&FUN_00c85750())->heap());

    }

};



struct LocalArray {

    hkVector4* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    void* m_initialStack;



    __forceinline LocalArray(int capacity) throw() {

        m_data = 0;

        m_iElementCount = 0;

        m_iCapacityState = 0x80000000;

        ThreadMemory* mem = (ThreadMemory*)&FUN_00c85750();

        void* p = mem->m_stackCurrent;

        int nBytes = (capacity * 16 + 127) & ~127;

        mem->m_stackCurrent = (char*)p + nBytes;

        m_data = (hkVector4*)p;

        m_initialStack = p;

        m_iCapacityState = capacity | 0x80000000;

    }



    __forceinline ~LocalArray() throw() {

        void* initial = m_initialStack;

        if (initial == m_data) {

            m_iElementCount = 0;

        }

        ((ThreadMemory*)&FUN_00c85750())->m_stackCurrent = initial;

        ClearAndRelease(((ThreadMemory*)&FUN_00c85750())->heap());

    }



    __forceinline void ClearAndRelease(Allocator& alloc) throw() {

        m_iElementCount = 0;

        if ((m_iCapacityState & 0x80000000) == 0) {

            alloc.deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * 16);

        }

        m_data = 0;

        m_iCapacityState = 0x80000000;

    }

};



static __forceinline float dot3_vec(__m128 a, __m128 b) throw() {

    __m128 m = _mm_mul_ps(a, b);

    __m128 shuf_y = _mm_shuffle_ps(m, m, 0x55);

    __m128 sum_xy = _mm_add_ss(shuf_y, m);

    __m128 shuf_z = _mm_shuffle_ps(m, m, 0xaa);

    __m128 sum_xyz = _mm_add_ss(shuf_z, sum_xy);

    float r;

    _mm_store_ss(&r, sum_xyz);

    return r;

}



static __forceinline void appendPlane(hkArray<hkVector4>& array, const hkVector4& v) throw() { copyVecs(array.m_data + array.m_iElementCount, &v, 1); ++array.m_iElementCount; }




extern "C" __m128 _mm_load_ss(const float*);
class PlaneScalar {
    __m128 value;
public:
    PlaneScalar() {}
    PlaneScalar(float f) { value = _mm_load_ss(&f); }
    PlaneScalar(const __m128& q): value(q) {}
    operator float() const { float f; _mm_store_ss(&f,value); return f; }
    __forceinline __m128 splat() const { return _mm_shuffle_ps(value,value,0); }
};
enum PlaneResult { PlaneSuccess, PlaneFailure };
class PlaneVector {
    __m128 value;
public:
    __forceinline operator __m128() const { return value; }
    __forceinline void operator=(const PlaneVector& v) { value=v.value; }
    __forceinline void difference(const PlaneVector& a,const PlaneVector& b) { value=_mm_sub_ps(a.value,b.value); }
    __forceinline void cross(const PlaneVector& a,const PlaneVector& b) {
        __m128 p=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        __m128 q=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(p,q);
    }
    __forceinline PlaneScalar dot(const PlaneVector& b) const {
        __m128 products=_mm_mul_ps(value,b.value);
        __m128 pair=_mm_add_ss(_mm_shuffle_ps(products,products,0x55),products);
        return _mm_add_ss(_mm_shuffle_ps(products,products,0xaa),pair);
    }
    __forceinline PlaneScalar squared() const { return dot(*this); }
    __forceinline void scale(const PlaneScalar& s) { value=_mm_mul_ps(s.splat(),value); }
    __forceinline PlaneResult normalize() {
        const float square=squared();
        if (square!=0.0f) {
            scale(1.0f/(float)sqrt((double)square));
            return PlaneSuccess;
        }
        return PlaneFailure;
    }
};

struct PlaneScanMath {

    __m128 fixedNormal;

    __m128& work;

    __forceinline PlaneScanMath(__m128 n, __m128& w) throw() : fixedNormal(n), work(w) {}

    __forceinline void scale(const __m128& v) throw() { fixedNormal = _mm_mul_ps(v, fixedNormal); }

    __forceinline float evaluate(const __m128& p) throw() {

        work = p; work = _mm_mul_ps(work, fixedNormal);

        __m128 y = _mm_shuffle_ps(work, work, 0x55);

        y = _mm_add_ss(y, work);

        __m128 z = _mm_shuffle_ps(work, work, 0xaa);

        z = _mm_add_ss(z, y);

        float result;

        _mm_store_ss(&result, z);

        return result;

    }

};



// @fnv 0x00d59f40
void FUN_00d5a320::FUN_00d59f40()

{

    hkpConvexVerticesShape* shape = reinterpret_cast<hkpConvexVerticesShape*>(this);

    PlaneArray planes(shape);

    hkArray<hkVector4>& planeEquations = shape->m_kVertexPositions;

    shape->m_kVertexPositions.m_iElementCount = 0;

    int numVertices = shape->m_iStridedVertexCount;



    LocalArray vertices(numVertices);

    reinterpret_cast<FUN_00d59200_Helper*>(shape)->FUN_00d59200(&vertices);



    int vertOffset = 0;

    for (int faceIdx = 0; faceIdx < shape->m_pConnectivity->m_kNumVerticesPerFace.m_iElementCount; ++faceIdx) {

        if (planes.GetLogicalSize() == 0) {

            break;

        }

        int numVerts = shape->m_pConnectivity->m_kNumVerticesPerFace.m_data[faceIdx];

        if (numVerts < 3) {

            continue;

        }

        int idx0 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset];

        int idx1 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset + 1];

        int idx2 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset + 2];

        vertOffset += numVerts;



        struct FaceVertices { hkVector4 v1, v0, v2; hkVector4 normal; } face;

        face.v0 = vertices.m_data[idx0];

        face.v1 = vertices.m_data[idx1];

        face.v2 = vertices.m_data[idx2];



        __m128 e1 = _mm_sub_ps(*(__m128*)&face.v1, *(__m128*)&face.v0);

        __m128 e2 = _mm_sub_ps(*(__m128*)&face.v2, *(__m128*)&face.v0);



        __m128 xmm2 = _mm_shuffle_ps(e2, e2, 0xc9);

        __m128 xmm3 = _mm_shuffle_ps(e1, e1, 0xd2);

        __m128 shuf_e2 = _mm_shuffle_ps(e2, e2, 0xd2);

        xmm2 = _mm_mul_ps(xmm2, xmm3);

        __m128 shuf_e1 = _mm_shuffle_ps(e1, e1, 0xc9);

        shuf_e2 = _mm_mul_ps(shuf_e2, shuf_e1);

        __m128& normal = *(__m128*)&face.normal;

        normal = _mm_sub_ps(shuf_e2, xmm2);



if (reinterpret_cast<PlaneVector&>(normal).normalize()==PlaneSuccess) {
    PlaneScanMath scan(normal,e1);
            int bestIdx = 0;

            float maxDot = scan.evaluate(*(__m128*)&planes[0]);

            for (int j = 1; j < planes.GetLogicalSize(); ++j) {

                float dot = scan.evaluate(*(__m128*)&planes[j]);

                if (dot > maxDot) {

                    maxDot = dot;

                    bestIdx = j;

                }

            }



            appendPlane(planeEquations, planes[bestIdx]);

            planes.removeAt(bestIdx);

        } else {

            appendPlane(planeEquations, planes[0]);

        }

    }



    if (planes.GetLogicalSize() > 0) {

        int index = shape->m_kVertexPositions.m_iElementCount;

        ThreadMemory* mem = (ThreadMemory*)&FUN_00c85750();

        reinterpret_cast<FUN_00d5a4c0_Helper*>(&planeEquations)->FUN_00d5a4c0(

            mem->m_pMemoryAllocator, index, planes.begin(), planes.GetLogicalSize());

    }

}

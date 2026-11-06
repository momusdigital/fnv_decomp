
// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/triangle/hkptriangleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTriangleShape.h"

extern char const* const g_01268970_arg1;

void __cdecl FUN_00c90360(char const*, char const* const*);

// @fnv 0x00d1fee0
void __cdecl FUN_00d1fee0(char const* arg1, char const* const* arg2)
{
    FUN_00c90360(arg1, &g_01268970_arg1);
}

// getNumCollisionSpheresImpl: hkpTriangleShape helper returning (m_ucWeldingPadding + 1) * 3.
class FUN_00d1ff10_cls : public hkpTriangleShape
{
public:
    int getNumCollisionSpheresImpl();
};

// @fnv 0x00d1ff10
int FUN_00d1ff10_cls::getNumCollisionSpheresImpl()
{
    return (m_ucWeldingPadding + 1) * 3;
}

// edge is a triangle edge index (0, 1, or 2).
// @fnv 0x00d1fef0
static __declspec(noinline) int __cdecl FUN_00d1fef0(unsigned short weldingInfo, int edge)
{
    char shift = edge * 5;
    return (weldingInfo >> shift) & 31;
}
int __cdecl ExtractEdge(unsigned short weldingInfo, int edge)
{
    return FUN_00d1fef0(weldingInfo, edge);
}

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern float DAT_0106c2e0;

class FUN_00d1ff40_cls {
public:
    int pad00[8];
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;

    void FUN_00d1ff40(hkVector4* out);
};

// Stores (m_20 + m_30 + m_40) multiplied by DAT_0106c2e0 into out.
// @fnv 0x00d1ff40
void FUN_00d1ff40_cls::FUN_00d1ff40(hkVector4* out)
{
    __m128 sum = _mm_add_ps(m_30, m_20);
    _mm_store_ps(&out->x, sum);
    __m128 total = _mm_add_ps(m_40, sum);
    _mm_store_ps(&out->x, total);
    __m128 half = _mm_load_ss(&DAT_0106c2e0);
    half = _mm_shuffle_ps(half, half, 0);
    _mm_store_ps(&out->x, _mm_mul_ps(half, total));
}

struct FUN_00d1ff20_s {
    void CopyVector(float* dst);
};

// @fnv 0x00d1ff20
void FUN_00d1ff20_s::CopyVector(float* dst)
{
    __m128 v = *(__m128*)((char*)this + 0x20);
    *(__m128*)dst = v;
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

// Computes the normalized cross product of two edge vectors and writes the result to out.
// @fnv 0x00d1ff80
static __declspec(noinline) void FUN_00d1ff80(const __m128* apVertexA, const __m128* apVertexB, const __m128* apVertexC, __m128* apNormal)
{
    __m128 vb = *apVertexB;
    __m128 va = *apVertexA;
    __m128 q;
    __m128& edge = q;
    __m128 p = _mm_sub_ps(vb, va);
    edge = _mm_sub_ps(*apVertexC, vb);
    __m128 qz = _mm_shuffle_ps(q, q, 0xd2);
    __m128 py = _mm_shuffle_ps(p, p, 0xc9);
    __m128 qy = _mm_shuffle_ps(q, q, 0xc9);
    __m128 pz = _mm_shuffle_ps(p, p, 0xd2);
    __m128 crossProduct = _mm_sub_ps(_mm_mul_ps(py, qz), _mm_mul_ps(pz, qy));
    __m128 squaredComponents = _mm_mul_ps(crossProduct, crossProduct);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(squaredComponents, squaredComponents, 0x55), squaredComponents);
    __m128 length = _mm_add_ss(_mm_shuffle_ps(squaredComponents, squaredComponents, 0xaa), xy);
    __m128 r = _mm_rsqrt_ss(length);
    __m128 r2 = _mm_mul_ss(_mm_mul_ss(length, r), r);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 mask = _mm_cmpeq_ss(length, zero);
    __m128 delta = _mm_sub_ss(_mm_set_ss(DAT_01017718), r2);
    __m128 newtonFactor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), delta);
    __m128 scale = _mm_andnot_ps(mask, newtonFactor);
    *apNormal = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), crossProduct);
}
const __m128* volatile inputA;
const __m128* volatile inputB;
const __m128* volatile inputC;
__m128* volatile outputV;
void invokeTriangleNormal() { FUN_00d1ff80(inputA, inputB, inputC, outputV); }

extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);

struct SimdVector {
    union { __m128 value; float component[4]; };
    void FUN_00c7f640(const void* transform, const SimdVector& vertex);
    __forceinline void lower(const SimdVector& a, const SimdVector& b) { value = _mm_min_ps(a.value, b.value); }
    __forceinline void upper(const SimdVector& a, const SimdVector& b) { value = _mm_max_ps(a.value, b.value); }
    __forceinline void sum(const SimdVector& a, const SimdVector& b) { value = _mm_add_ps(a.value, b.value); }
    __forceinline void difference(const SimdVector& a, const SimdVector& b) { value = _mm_sub_ps(a.value, b.value); }
    __forceinline void broadcast(float f) { __m128 scalar = _mm_load_ss(&f); value = _mm_shuffle_ps(scalar, scalar, 0); }
};
struct Bounds { SimdVector minimum, maximum; };
struct TriangleBounds : hkpConvexShape {
    unsigned short welding;
    unsigned char weldingType;
    unsigned char extruded;
    unsigned int unk18;
    unsigned int unk1c;
    SimdVector vertexA, vertexB, vertexC, extrusion;
    void FUN_00d20050(const void* transform, float tolerance, Bounds& out) const;
};
// Computes the axis-aligned bounding box of the triangle (and extrusion) under a transform, expanded by the sphere radius plus tolerance.
// @fnv 0x00d20050
void TriangleBounds::FUN_00d20050(const void* transform, float tolerance, Bounds& out) const {
    SimdVector extent;
    extent.broadcast(m_fSphereRadius + tolerance);
    SimdVector a, b, c;
    a.FUN_00c7f640(transform, vertexA);
    b.FUN_00c7f640(transform, vertexB);
    c.FUN_00c7f640(transform, vertexC);
    out.minimum.lower(a,b);
    out.maximum.upper(a,b);
    out.minimum.lower(out.minimum,c);
    out.maximum.upper(out.maximum,c);
    SimdVector shifted;
    shifted.value = _mm_add_ps(out.minimum.value,_mm_load_ps(extrusion.component));
    out.minimum.lower(out.minimum,shifted);
    shifted.value = _mm_add_ps(out.maximum.value,_mm_load_ps(extrusion.component));
    out.maximum.upper(out.maximum,shifted);
    out.minimum.difference(out.minimum,extent);
    out.maximum.sum(out.maximum,extent);
}

class Cls_00d20110 : public hkpTriangleShape
{
public:
    hkVector4* GetVertices(hkVector4* output);
};

// @fnv 0x00d20110
hkVector4* Cls_00d20110::GetVertices(hkVector4* apVertices)
{
    *(__m128*)apVertices = *(const __m128*)&m_kVertexA;
    apVertices->w = m_fSphereRadius;
    *(__m128*)(apVertices + 1) = *(const __m128*)&m_kVertexB;
    hkVector4* q = apVertices + 1;
    q->w = m_fSphereRadius;
    ++q;
    *(__m128*)q = *(const __m128*)&m_kVertexC;
    q->w = m_fSphereRadius;
    ++q;
    if (m_ucWeldingPadding != 0) {
        *(__m128*)q = _mm_add_ps(*(const __m128*)&m_kVertexTransform, *(const __m128*)&m_kVertexA);
        q->w = m_fSphereRadius;
        ++q;
        *(__m128*)q = _mm_add_ps(*(const __m128*)&m_kVertexTransform, *(const __m128*)&m_kVertexB);
        q->w = m_fSphereRadius;
        *(__m128*)&q[1] = _mm_add_ps(_mm_load_ps(reinterpret_cast<const float*>(&m_kVertexC.x)), *(const __m128*)&m_kVertexTransform);
        q[1].w = m_fSphereRadius;
    }
    return apVertices;
}

extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

__forceinline int rootSelect48(const float* sv)
{
    float L0=sv[0];
    float L1=sv[1];
    float L2=sv[2];
    int idx;
    float m;
    if (L2 > L1) { m = L2; idx = 2; }
    else { m = L1; idx = 1; }
    if (L0 > m) idx = 0;
    return idx;
}

struct SupportVector {
    union { __m128 vector; float components[4]; };
    __forceinline void add(const SupportVector& b) { vector = _mm_add_ps(vector, b.vector); }
};

struct TriangleSupport : hkpTriangleShape {
    void getSupportingVertexImpl(float const* pf, float* out);
};

// Picks the triangle vertex with the largest projection of pf, adds m_kVertexTransform if its dot with pf is positive, and stores the index in out[3].
// @fnv 0x00d20270
void TriangleSupport::getSupportingVertexImpl(float const* pf, float* out)
{
    __m128 v0 = *reinterpret_cast<const __m128*>(&m_kVertexA);
    __m128 v1 = *reinterpret_cast<const __m128*>(&m_kVertexB);
    __m128 v4 = *reinterpret_cast<const __m128*>(&m_kVertexC);
    __m128 tp = _mm_unpacklo_ps(v0, v1);
    __m128 ct = _mm_unpackhi_ps(v0, v1);
    v0 = _mm_movelh_ps(tp, v4);
    v1 = _mm_shuffle_ps(_mm_movehl_ps(v0, tp), v4, 0xd4);
    v4 = _mm_shuffle_ps(ct, v4, 0xe4);
    __m128 d = _mm_load_ps(pf);
    __m128 v2 = d;
    v2 = _mm_shuffle_ps(v2, d, 0x55);
    v2 = _mm_mul_ps(v2, v1);
    __m128 v3 = d;
    v3 = _mm_shuffle_ps(v3, d, 0);
    v2 = _mm_add_ps(v2, _mm_mul_ps(v3, v0));
    v2 = _mm_add_ps(v2, _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), v4));
    __m128 s = v2;
    float sv[4];
    _mm_store_ps(sv, s);
    int idx = rootSelect48(sv);
    _mm_store_ps(out, reinterpret_cast<const __m128*>(&m_kVertexA)[idx]);
    __m128 vD = *reinterpret_cast<const __m128*>(&m_kVertexTransform);
    __m128 vP = _mm_mul_ps(_mm_load_ps(pf), vD);
    __m128 e = _mm_add_ss(_mm_shuffle_ps(vP, vP, 0xaa), _mm_add_ss(_mm_shuffle_ps(vP, vP, 0x55), vP));
    float fE;
    _mm_store_ss(&fE, e);
    if (fE > 0.0f) {
        idx += 3;
        reinterpret_cast<SupportVector*>(out)->add(*reinterpret_cast<const SupportVector*>(&m_kVertexTransform));
    }
    ((int*)out)[3] = idx | 0x3f000000;
}

#include <math.h>



extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);

extern int DAT_011b3b4c[];
extern int DAT_011b3b50[];
extern float DAT_011b3b38[];
// hkpWeldingUtility sin/cos table: cosAccept0, sinAccept0, cosSnap0, cosSnap1, cosAccept1, sinAccept1
struct FloatArray6 { float value[6]; };
extern FloatArray6 DAT_01269210[];

static __forceinline float scalar(__m128 v) { float out; _mm_store_ss(&out, v); return out; }
static __forceinline __m128 splat(__m128 v) { return _mm_shuffle_ps(v, v, 0); }
static __forceinline __m128 horizontal3(__m128 p) {
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 xy = _mm_add_ss(y, p);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    return _mm_add_ss(z, xy);
}
static __forceinline __m128 dot3(__m128 a, __m128 b) { return horizontal3(_mm_mul_ps(a, b)); }
static __forceinline __m128 cross3(__m128 a, __m128 b) {
    return _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
        _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __forceinline __m128 normalized3(__m128 v) {
    __m128 length = dot3(v, v);
    __m128 estimate = _mm_rsqrt_ss(length);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 zeroMask = _mm_cmpeq_ss(length, zero);
    __m128 product = _mm_mul_ss(_mm_mul_ss(length, estimate), estimate);
    __m128 correction = _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, product));
    return _mm_mul_ps(splat(_mm_andnot_ps(zeroMask, correction)), v);
}

static __forceinline bool shouldSnapOneSided(unsigned int type, const __m128& face, const __m128& normal, const float* limits) {
    float alignment = scalar(dot3(face, normal));
    if (type == 0) return alignment < limits[type];
    return alignment > limits[type];
}
static __forceinline int getSector(unsigned int code, const __m128& face, const __m128& normal) {
    float alignment = scalar(dot3(face, normal));
    int cone;
    if (alignment >= DAT_01269210[code].value[0]) cone = 1;
    else if (alignment >= DAT_01269210[code].value[2]) cone = 0;
    else if (alignment >= DAT_01269210[code].value[3]) cone = 2;
    else if (alignment >= DAT_01269210[code].value[4]) cone = 4;
    else cone = 3;
    return cone;
}
struct VectorOperations {
    __m128 value;
    void FUN_00c7f700(const hkRotation*, const __m128*);
    void FUN_00c7f690(const hkTransform*, const hkVector4*);
    void FUN_00c7f640(const hkTransform*, const VectorOperations&);
};
struct SupportShape {
    virtual void slot00(); virtual void slot04(); virtual void slot08();
    virtual void slot0c(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c(); virtual void slot20();
    virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38();
    virtual void slot3c(); virtual void slot40();
    virtual void getSupport(VectorOperations*);
};
extern float __cdecl FUN_00c9e0f0(float, float);

class TriangleWelding : public hkpTriangleShape {
public:
    int weldContactPointImpl(unsigned short* indices, unsigned char* count,
        const hkVector4* position, const hkTransform* transform,
        SupportShape* source, const hkTransform* sourceTransform, hkVector4* output);
};

// Welds a triangle edge against a support shape, adjusting the face normal and separation based on welding type and sector cone.
// @fnv 0x00d203f0
int TriangleWelding::weldContactPointImpl(unsigned short* indices, unsigned char* count,
    const hkVector4* position, const hkTransform* transform,
    SupportShape* source, const hkTransform* sourceTransform, hkVector4* output) {
    unsigned int weldingType = m_eWeldingType;
    if (weldingType == 6) return 2;
    int edge = DAT_011b3b4c[indices[0]];
    unsigned char sectors = *count;
    if (sectors > 1) {
        int other = DAT_011b3b4c[indices[1]];
        if (sectors == 3) {
            if (indices[0] + indices[1] + indices[2] == 3) return 2;
            if (other == edge) other = DAT_011b3b4c[indices[2]];
            *count = 2;
            indices[0] = (unsigned short)edge;
            indices[1] = (unsigned short)other;
        }
        if (DAT_011b3b50[edge] != other) edge = other;
    }

    VectorOperations corrected;
    *(hkVector4*)&corrected = *output;
    __m128 v0 = *(const __m128*)&transform->m_rotation.m_kColumn0;
    __m128 v1 = *(const __m128*)&transform->m_rotation.m_kColumn1;
    __m128 v4 = *(const __m128*)&transform->m_rotation.m_kColumn2;
    __m128 tp = _mm_unpacklo_ps(v0, v1);
    __m128 ct = _mm_unpackhi_ps(v0, v1);
    v0 = _mm_movelh_ps(tp, v4);
    v1 = _mm_shuffle_ps(_mm_movehl_ps(v0, tp), v4, 0xd4);
    v4 = _mm_shuffle_ps(ct, v4, 0xe4);
    __m128 d = corrected.value;
    __m128 v2 = d;
    v2 = _mm_shuffle_ps(v2, d, 0x55);
    v2 = _mm_mul_ps(v2, v1);
    __m128 v3 = d;
    v3 = _mm_shuffle_ps(v3, d, 0);
    v2 = _mm_add_ps(v2, _mm_mul_ps(v3, v0));
    v2 = _mm_add_ps(v2, _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), v4));
    __m128 localNormal = v2;
    SimdVector normalStore;
    normalStore.value = v2;

    VectorOperations faceTemporary;
    FUN_00d1ff80((const __m128*)&m_kVertexA, (const __m128*)&m_kVertexB, (const __m128*)&m_kVertexC, &faceTemporary.value);
    __m128 face = faceTemporary.value;
    __m128 faceProduct = _mm_mul_ps(face, localNormal);
    float separation = (float)fabs(scalar(horizontal3(faceProduct))) * ((const hkVector4*)&corrected)->w;
    __m128 edgeDirection = normalized3(_mm_sub_ps(((const __m128*)&m_kVertexA)[DAT_011b3b50[edge]], ((const __m128*)&m_kVertexA)[edge]));
    unsigned int code = (m_kWeldingInfo >> ((signed char)edge * (signed char)5)) & 31;

    if (weldingType != 5) {
        if (!shouldSnapOneSided(weldingType, face, localNormal, DAT_01269210[code].value)) return 2;
        const float* limits = DAT_01269210[code].value;
        __m128 angleCos = _mm_load_ss(limits + weldingType);
        __m128 angleSin = _mm_load_ss(limits + weldingType + 1);
        corrected.value = normalized3(_mm_add_ps(
            _mm_mul_ps(cross3(edgeDirection, face), splat(angleSin)),
            _mm_mul_ps(splat(angleCos), face)));
        corrected.FUN_00c7f700(&transform->m_rotation, &corrected.value);
        if (m_ucWeldingPadding) {
            faceTemporary.value = _mm_mul_ps(_mm_load_ps1(DAT_011b3b38 + weldingType), faceTemporary.value);
            VectorOperations localPosition;
            localPosition.FUN_00c7f690(transform, position);
            separation = FUN_00c9e0f0(scalar(dot3(_mm_sub_ps(localPosition.value, *(const __m128*)&m_kVertexA), faceTemporary.value)), separation);
        } else {
            VectorOperations support;
            source->getSupport(&support);
            support.FUN_00c7f640(sourceTransform, support);
            __m128 projection = dot3(_mm_sub_ps(*(const __m128*)position, support.value), corrected.value);
            if ((_mm_movemask_ps(projection) & 1) == 0) return 0;
        }
    } else {
        int cone = getSector(code, face, localNormal);
        switch (cone) {
        case 0:
        case 4: break;
        case 2: return 0;
        default: return 2;
        }
        if (*count == 1) return 0;
        const FloatArray6& entry = DAT_01269210[code];
        __m128 angleCos = _mm_load_ss(&entry.value[cone]);
        __m128 angleSin = _mm_load_ss(&entry.value[cone + 1]);
        __m128 correction = normalized3(_mm_add_ps(
            _mm_mul_ps(cross3(edgeDirection, face), splat(angleSin)),
            _mm_mul_ps(splat(angleCos), face)));
        __m128 blend = _mm_add_ps(
            _mm_mul_ps(splat(dot3(edgeDirection, localNormal)), edgeDirection),
            _mm_mul_ps(splat(dot3(correction, localNormal)), correction));
        normalStore.value = normalized3(blend);
        corrected.FUN_00c7f700(&transform->m_rotation, &normalStore.value);
    }
    *(__m128*)output = corrected.value;
    output->w = separation;
    return 1;
}

typedef unsigned char hkUint8_S;
typedef unsigned short hkUint16_S;
typedef unsigned int hkUint32_S;
typedef unsigned long __w64 hkUlong_S;
typedef unsigned __w64 hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass_S;
typedef int hkBool32;
class hkBool_S
{
public:
typedef char CompileTimeTrueType;inline hkBool_S(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
private:
TYPE m_kStorage;};
extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong_S)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
class hkMemoryAllocator
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pStreamAllocator;};
class hkBaseObject_S
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject_S(){}
};
class hkStatisticsCollector;
class hkReferencedObject_S:public hkBaseObject_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16_S m_usMemSizeAndFlags;
public:
hkReferencedObject_S(class FinishingFlag flag){}
};typedef float hkReal_S;

extern "C"{






extern __m128 _mm_rcp_ps(__m128 _A);

extern __m128 _mm_and_ps(__m128 _A,__m128 _B);

extern __m128 _mm_or_ps(__m128 _A,__m128 _B);
extern __m128 _mm_xor_ps(__m128 _A,__m128 _B);

extern __m128 _mm_cmpeq_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmplt_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmple_ps(__m128 _A,__m128 _B);

extern int _mm_movemask_ps(__m128 _A);

extern __m128 _mm_setr_ps(float _A,float _B,float _C,float _D);
extern __m128 _mm_setzero_ps(void);};
typedef __m128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};
static const Mask ms_kLaneMasks[4];
__forceinline void setAnd(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_and_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setOr(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_or_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setNot(hkVector4ComparisonParameter a)
{
static __declspec(align(16))const hkUint32_S allBits[4]={0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};
m_uiMask=_mm_andnot_ps(a.m_uiMask,*(const hkQuadReal*)&allBits);
}
__forceinline hkBool32 anyIsSet(Mask m)const{return _mm_movemask_ps(m_uiMask)&m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4_S;};
namespace MathUtilities
{inline hkQuadReal quadReciprocal(hkQuadReal r)
{
hkQuadReal e=_mm_rcp_ps(r);
return _mm_sub_ps(_mm_add_ps(e,e),_mm_mul_ps(_mm_mul_ps(e,r),e));
}
}
extern const hkQuadReal g_kQuadRealConstant;
class hkTransform_S;
class hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4_S&v);
__forceinline void set(hkReal_S x,hkReal_S y,hkReal_S z,hkReal_S w=0);
__forceinline void SetAllComponents(hkSimdRealParameter x);
__forceinline void setZero4();
__forceinline void sub4(const hkVector4_S&a);
__forceinline void setSub4(const hkVector4_S&a,const hkVector4_S&b);
__forceinline void mul4(const hkVector4_S&a);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4_S&a);
__forceinline void addMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setCross(const hkVector4_S&a,const hkVector4_S&b);
__forceinline Vector4Comparison compareLessThan4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareEqual4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareLessThanEqual4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareGreaterThanEqual4(hkVector4Parameter a)const;
__forceinline VectorComponentValue dot3(const hkVector4_S&a)const;
__forceinline VectorComponentValue lengthSquared3()const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal_S&operator()(int i);
__forceinline void setReciprocal4(const hkVector4_S&v);
__forceinline VectorComponentValue getSimdAt(int i)const;
__forceinline void setBroadcast(hkVector4Parameter v,int i);
__forceinline hkQuadReal&getQuad();
__forceinline const hkQuadReal&getQuad()const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
inline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
inline const hkQuadReal&hkVector4_S::getQuad()const
{
return m_vComponents;
}
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::set(hkReal_S a,hkReal_S b,hkReal_S c,hkReal_S d)
{
m_vComponents=_mm_setr_ps(a,b,c,d);
}
inline void hkVector4_S::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4_S::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4_S::sub4(const hkVector4_S&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::mul4(const hkVector4_S&v)
{
m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setMul4(const hkVector4_S&a,const hkVector4_S&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_S::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4_S::addMul4(const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline Vector4Comparison hkVector4_S::compareLessThan4(hkVector4Parameter a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmplt_ps(m_vComponents,a.m_vComponents);
return m;
}
inline Vector4Comparison hkVector4_S::compareEqual4(hkVector4Parameter a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmpeq_ps(m_vComponents,a.m_vComponents);
return m;
}
inline Vector4Comparison hkVector4_S::compareLessThanEqual4(const hkVector4_S&a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmple_ps(m_vComponents,a.m_vComponents);
return m;
}
inline VectorComponentValue hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4_S::lengthSquared3()const
{
return this->dot3(*this);
}
inline VectorComponentValue hkVector4_S::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4_S::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline hkReal_S&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal_S*>(&m_vComponents)[a];
}
inline void hkVector4_S::setReciprocal4(const hkVector4_S&vec)
{
m_vComponents=MathUtilities::quadReciprocal(vec.m_vComponents);
}
inline VectorComponentValue hkVector4_S::getSimdAt(int i)const
{
switch(i)
{
case 0:
return m_vComponents;
case 1:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
case 2:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
case 3:
default:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline void hkVector4_S::setBroadcast(const hkVector4_S&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==1)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
}
else if(i==2)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline Vector4Comparison hkVector4_S::compareGreaterThanEqual4(hkVector4Parameter a)const
{
return a.compareLessThanEqual4(*this);
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool_S __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool_S m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32_S m_uiStartTicks;
hkUint32_S m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32_S ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4_S m_kMinimumCorner;};class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
enum hkpBufferSize
{
HK_SHAPE_BUFFER_SIZE=512
};
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
typedef hkUint16_S hkpVertexId;
typedef hkUint32_S hkpShapeKey;
class hkpConvexShape_S;
class hkpShape_S:public hkReferencedObject_S
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass_S&__cdecl staticClass();struct DefaultStruct;
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline hkpShape_S(CollisionShapeType type);
__forceinline CollisionShapeType getType()const;
__forceinline void getAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const;
virtual hkReal_S getMaximumProjection(const hkVector4_S&direction)const;
inline hkUlong_S getUserData()const;
inline void setUserData(hkUlong_S data);
__forceinline hkBool_S RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
__forceinline Vector4Comparison castRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output)const;
__forceinline Vector4Comparison castRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
__forceinline void castRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const=0;
virtual hkBool_S IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison FUN_00d20e70(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
static void __cdecl verifyShapeFunctions();
typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,hkVector4Parameter direction,Vector4WithInt24W&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const hkpVertexId*ids,int numIds,class Vector4WithInt24W*verticesOut);
typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,hkpVertexId*featurePoints,hkUint8_S&numFeaturePoints,hkVector4_S&contactPointWs,const hkTransform_S*thisObjTransform,const hkpConvexShape_S*collidingShape,const hkTransform_S*collidingTransform,hkVector4_S&separatingNormalInOut);
typedef void(__cdecl*GetCentreFunc)(const void*thisObj,hkVector4_S&centreOut);
typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const hkSphere*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,hkSphere*sphereBuffer);
typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out);
typedef hkBool_S(__cdecl*CastRayFunc)(const void*thisObj,const ShapeRayCastQuery&input,ShapeRayCastOutput&output);
typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector);
typedef Vector4Comparison(__cdecl*CastRayBundleFunc)(const void*thisObj,const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask);
typedef const hkpShape_S*(__cdecl*GetChildShapeFunc)(const void*thisObj,hkpShapeKey key,hkpShapeBuffer&buffer);
typedef hkUint32_S(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,hkpShapeKey key);
struct ShapeCallbackDispatchTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::ShapeCallbackDispatchTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ValueWrapper<GetSupportingVertexFunc>m_kGetSupportingVertexFunction;
ValueWrapper<ConvertVertexIdsToVerticesFunc>m_kConvertVertexIdsToVerticesFunction;
ValueWrapper<WeldContactPointFunc>m_kWeldContactPointFunction;
ValueWrapper<GetCentreFunc>m_kGetCentreFunction;
ValueWrapper<GetNumCollisionSpheresFunc>m_kGetNumCollisionSpheresFunction;
ValueWrapper<GetCollisionSpheresFunc>m_kGetCollisionSpheresFunction;
ValueWrapper<GetAabbFunc>m_kGetAabbFunction;
ValueWrapper<CastRayFunc>m_kCastRayFunction;
ValueWrapper<CastRayWithCollectorFunc>m_kCastRayWithCollectorFunction;
ValueWrapper<CastRayBundleFunc>m_kCastRayBundleFunction;
ValueWrapper<GetChildShapeFunc>m_kGetChildShapeFunction;
ValueWrapper<GetCollisionFilterInfoFunc>m_kGetCollisionFilterInfoFunction;
void reset();
};
struct AlignedShapeCallbackTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::AlignedShapeCallbackTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__declspec(align(64))GetSupportingVertexFunc m_kGetSupportingVertexFunction;
ConvertVertexIdsToVerticesFunc m_kConvertVertexIdsToVerticesFunction;
WeldContactPointFunc m_kWeldContactPointFunction;
GetCentreFunc m_kGetCentreFunction;
GetNumCollisionSpheresFunc m_kGetNumCollisionSpheresFunction;
GetCollisionSpheresFunc m_kGetCollisionSpheresFunction;
GetAabbFunc m_kGetAabbFunction;
CastRayFunc m_kCastRayFunction;
CastRayWithCollectorFunc m_kCastRayWithCollectorFunction;
CastRayBundleFunc m_kCastRayBundleFunction;
GetChildShapeFunc m_kGetChildShapeFunction;
GetCollisionFilterInfoFunc m_kGetCollisionFilterInfoFunction;
};
typedef void(__cdecl*RegisterFunc)(ShapeCallbackDispatchTable&sf);
public:
public:
hkUlong_S m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32_S>m_type;
public:
hkpShape_S(class FinishingFlag flag):hkReferencedObject_S(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};struct RayCastHitResult
{
inline void reset();
hkVector4_S m_vHitNormal;
hkReal_S m_fHitFraction;};struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setKey(hkpShapeKey key);
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};inline void ShapeRayCastOutput::setKey(hkpShapeKey key)
{
m_uiShapeKeys[m_uiShapeKeyIndex]=key;
}
struct ShapeRayCastOutputArray
{
ShapeRayCastOutput m_akRayOutputs[4];
void reset(){m_akRayOutputs[0].reset();m_akRayOutputs[1].reset();m_akRayOutputs[2].reset();m_akRayOutputs[3].reset();}
};
class hkpSphereRepShape_S:public hkpShape_S
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape_S(CollisionShapeType type):hkpShape_S(type){}
hkpSphereRepShape_S(FinishingFlag flag):hkpShape_S(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
extern hkReal_S g_fDefaultConvexRadius;
class hkpConvexShape_S:public hkpSphereRepShape_S
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape_S(CollisionShapeType type,hkReal_S radius);
public:
hkpConvexShape_S(FinishingFlag flag):hkpSphereRepShape_S(flag){m_type=HK_SHAPE_CONVEX;}
};class hkpWeldingUtility
{
public:
static const struct ClassMemberDescriptor Members[];
enum WeldingType
{
WELDING_TYPE_ANTICLOCKWISE=0,
WELDING_TYPE_CLOCKWISE=4,
WELDING_TYPE_TWO_SIDED=5,
WELDING_TYPE_NONE=6
};
public:
struct FloatArray6
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpWeldingUtility::FloatArray6));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal_S m_fValue0;
hkReal_S m_fValue1;
hkReal_S m_fValue2;
hkReal_S m_fValue3;
hkReal_S m_fValue4;
hkReal_S m_fValue5;
};};
class hkpTriangleShape_S:public hkpConvexShape_S
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass_S&__cdecl staticClass();struct DefaultStruct;
int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const{return sizeof(*this);};
__forceinline hkpTriangleShape_S(hkReal_S radius=g_fDefaultConvexRadius,hkUint16_S weldingInfo=0,hkpWeldingUtility::WeldingType type=hkpWeldingUtility::WELDING_TYPE_NONE);
__forceinline hkpTriangleShape_S(const hkVector4_S&v0,const hkVector4_S&v1,const hkVector4_S&v2,hkReal_S radius=g_fDefaultConvexRadius);
__forceinline const hkVector4_S*GetIndexedVertices()const;
__forceinline hkVector4_S&getVertex(int i);
__forceinline const hkVector4_S&getVertex(int i)const;
__forceinline void setVertex(int i,const hkVector4_S&vertex);
__forceinline hkUint16_S getWeldingInfo()const;
__forceinline void SetWeldingInfo(hkUint16_S info);
__forceinline hkpWeldingUtility::WeldingType getWeldingType()const;
__forceinline void setWeldingType(hkpWeldingUtility::WeldingType type);
__forceinline bool isExtruded()const;
__forceinline const hkVector4_S&getExtrusion()const;
__forceinline void setExtrusion(const hkVector4_S&extrusion);
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*verticesOut)const;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8_S&numFeaturePoints,hkVector4_S&contactPointWs,const hkTransform_S*thisObjTransform,const hkpConvexShape_S*collidingShape,const hkTransform_S*collidingTransform,hkVector4_S&separatingNormalInOut)const;
virtual void GetCentre(hkVector4_S&centreOut)const;
virtual int GetNumCollisionSpheres()const;
virtual const hkSphere*GetCollisionSpheres(hkSphere*sphereBuffer)const;
virtual void CalculateAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const;
virtual hkBool_S IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&results)const;
virtual Vector4Comparison FUN_00d20e70(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&results,hkVector4ComparisonParameter mask)const;
virtual void GetFirstVertex(hkVector4_S&v)const;
static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerGetAabbFunction(ShapeCallbackDispatchTable&sf);
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass_S*cls)const;
protected:
hkUint16_S m_kWeldingInfo;
hkEnum<hkpWeldingUtility::WeldingType,hkUint8_S>m_eWeldingType;
hkUint8_S m_ucWeldingPadding;
hkVector4_S m_kVertexA;
hkVector4_S m_kVertexB;
hkVector4_S m_kVertexC;
hkVector4_S m_kVertexTransform;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
hkpTriangleShape_S(FinishingFlag flag):hkpConvexShape_S(flag){m_type=HK_SHAPE_TRIANGLE;}
};const hkVector4_S&hkpTriangleShape_S::getVertex(int i)const
{
;
return(&m_kVertexA)[i];
}
struct ShapeRayBundleCastInput
{
hkVector4_S m_vFrom[3];
hkVector4_S m_vTo[3];};
namespace hkVector4Util_S
{
__forceinline void __cdecl mulSigns4(hkVector4_S&inout,const hkVector4_S&signsSource);}
inline void __cdecl hkVector4Util_S::mulSigns4(hkVector4_S&inout,const hkVector4_S&signs)
{
static __declspec(align(16))const hkUint32_S signmask[4]=
{0x80000000,0x80000000,0x80000000,0x80000000};
inout.getQuad()=_mm_xor_ps(inout.getQuad(),
_mm_and_ps(signs.getQuad(),*(const hkQuadReal*)&signmask));}
static void diffCrossDiffDotNormal(const hkVector4_S&p_i,const hkVector4_S&p_j,const hkVector4_S*hitPoints,const hkVector4_S&normal,hkVector4_S&dotsOut)
{
hkVector4_S A[3];
hkVector4_S B[3];
A[0].setBroadcast(p_i,0);
A[0].sub4(hitPoints[0]);
A[2].sub4(hitPoints[2]);
B[0].setBroadcast(p_j,0);
B[2].sub4(hitPoints[2]);
hkVector4_S temp;
hkVector4_S dots;
hkVector4_S cp;
dots.setZero4();
dots.addMul4(normal.getSimdAt(0),cp);
cp.setMul4(A[2],B[0]);temp.setMul4(A[0],B[2]);cp.sub4(temp);
dots.addMul4(normal.getSimdAt(2),cp);
dotsOut=dots;}
// @fnv 0x00d20e70
Vector4Comparison hkpTriangleShape_S::FUN_00d20e70(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&results,hkVector4ComparisonParameter mask)const
{
const hkpTriangleShape_S*thisObj=this;
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "rayBundleTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock54;
;
Vector4Comparison kComparisonMask=mask;
const hkVector4_S&vert0=thisObj->getVertex(0);
const hkVector4_S&vert1=thisObj->getVertex(1);
const hkVector4_S&vert2=thisObj->getVertex(2);
hkVector4_S v10;v10.setSub4(vert1,vert0);
hkVector4_S v20;v20.setSub4(vert2,vert0);
hkVector4_S triangleNormal;triangleNormal.setCross(v10,v20);
hkVector4_S dist;dist.SetAllComponents(vert0.dot3(triangleNormal));
hkVector4_S dist_a;dist_a.setZero4();
hkVector4_S dist_b;dist_b.setZero4();
dist_a.addMul4(triangleNormal.getSimdAt(0),input.m_vFrom[0]);
dist_b.addMul4(triangleNormal.getSimdAt(0),input.m_vTo[0]);
dist_a.addMul4(triangleNormal.getSimdAt(1),input.m_vFrom[1]);
dist_b.addMul4(triangleNormal.getSimdAt(1),input.m_vTo[1]);
dist_a.addMul4(triangleNormal.getSimdAt(2),input.m_vFrom[2]);
dist_b.addMul4(triangleNormal.getSimdAt(2),input.m_vTo[2]);
dist_a.sub4(dist);
dist_b.sub4(dist);
Vector4Comparison distMask;
{
hkVector4_S distProd;distProd.setMul4(dist_a,dist_b);
hkVector4_S zero;zero.setZero4();
Vector4Comparison distProdGteZero=distProd.compareGreaterThanEqual4(zero);
Vector4Comparison distAEqZero=dist_a.compareEqual4(zero);
Vector4Comparison distBEqZero=dist_b.compareEqual4(zero);
Vector4Comparison distBNeqZero;distBNeqZero.setNot(distBEqZero);
distAEqZero.setOr(distAEqZero,distBNeqZero);
distProdGteZero.setAnd(distProdGteZero,distAEqZero);
distMask.setNot(distProdGteZero);
}
kComparisonMask.setAnd(kComparisonMask,distMask);
hkVector4_S proj_length;proj_length.setSub4(dist_a,dist_b);
hkVector4_S distance;distance.setReciprocal4(proj_length);
distance.mul4(dist_a);
hkVector4_S oneMinusDistance;oneMinusDistance.getQuad()=g_kQuadRealConstant;
oneMinusDistance.sub4(distance);
const hkQuadReal edgeToleranceMul={-1e-4f,-1e-4f,-1e-4f,-1e-4f};
hkVector4_S edge_tolerance;edge_tolerance.getQuad()=edgeToleranceMul;
edge_tolerance.mul4(triangleNormal.lengthSquared3());
{
hkVector4_S earlyOutFractions;earlyOutFractions.set(results.m_akRayOutputs[0].m_fHitFraction,results.m_akRayOutputs[1].m_fHitFraction,results.m_akRayOutputs[2].m_fHitFraction,results.m_akRayOutputs[3].m_fHitFraction);
Vector4Comparison closeEnough=distance.compareLessThan4(earlyOutFractions);
kComparisonMask.setAnd(kComparisonMask,closeEnough);
}
hkVector4_S point[3];
point[0].setMul4(oneMinusDistance,input.m_vFrom[0]);
point[0].addMul4(distance,input.m_vTo[0]);
point[1].setMul4(oneMinusDistance,input.m_vFrom[1]);
point[1].addMul4(distance,input.m_vTo[1]);
point[2].setMul4(oneMinusDistance,input.m_vFrom[2]);
point[2].addMul4(distance,input.m_vTo[2]);
hkVector4_S dots01;
diffCrossDiffDotNormal(vert0,vert1,point,triangleNormal,dots01);
Vector4Comparison ok01=dots01.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok01);
hkVector4_S dots12;
diffCrossDiffDotNormal(vert1,vert2,point,triangleNormal,dots12);
Vector4Comparison ok12=dots12.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok12);
hkVector4_S dots20;
diffCrossDiffDotNormal(vert2,vert0,point,triangleNormal,dots20);
Vector4Comparison ok20=dots20.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok20);
for(int i=0;i<4;i++)
{
if(kComparisonMask.anyIsSet(Vector4Comparison::ms_kLaneMasks[i]))
{
triangleNormal.normalize3();
results.m_akRayOutputs[i].m_fHitFraction=distance(i);
hkVector4_S dist_a4;dist_a4.setBroadcast(dist_a,i);
hkVector4_S tempNormal;tempNormal=triangleNormal;
hkVector4Util_S::mulSigns4(tempNormal,dist_a4);
results.m_akRayOutputs[i].m_vHitNormal=tempNormal;
results.m_akRayOutputs[i].setKey(0xffffffff);
}
}
return kComparisonMask;
}

extern "C" __m128 _mm_setzero_ps();

class LaneScalar {
    __m128 value;
public:
    LaneScalar(const __m128& source) : value(source) {}
    __forceinline __m128 splat() const {
        return _mm_shuffle_ps(value,value,0);
    }
};

class LaneVector {
    __m128 value;
public:
    __forceinline operator __m128() const { return value; }
    __forceinline void operator=(const LaneVector& source) { value=source.value; }
    __forceinline void operator=(const __m128& source) { value=source; }
    __forceinline void broadcast(const LaneVector& source,int lane) {
        if(lane==0) value=_mm_shuffle_ps(source.value,source.value,0);
        else if(lane==1) value=_mm_shuffle_ps(source.value,source.value,0x55);
        else if(lane==2) value=_mm_shuffle_ps(source.value,source.value,0xaa);
        else value=_mm_shuffle_ps(source.value,source.value,0xff);
    }
    __forceinline LaneScalar scalar(int lane) const {
        switch(lane) {
        case 0: return value;
        case 1: return _mm_shuffle_ps(value,value,0x55);
        case 2: return _mm_shuffle_ps(value,value,0xaa);
        default: return _mm_shuffle_ps(value,value,0xff);
        }
    }
    __forceinline void clear() { value=_mm_setzero_ps(); }
    __forceinline void subtract(const LaneVector& other) { value=_mm_sub_ps(value,other.value); }
    __forceinline void product(const LaneVector& a,const LaneVector& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void accumulate(const LaneScalar& scale,const LaneVector& other) {
        value=_mm_add_ps(value,_mm_mul_ps(scale.splat(),other.value));
    }
};

// @fnv 0x00d201a0
static __declspec(noinline) void FUN_00d201a0(const LaneVector& first,const LaneVector& second,const LaneVector* rows,const LaneVector& weight,LaneVector& output)
{
    LaneVector left[3];
    LaneVector right[3];
    left[0].broadcast(first,0); left[0].subtract(rows[0]);
    left[1].broadcast(first,1); left[1].subtract(rows[1]);
    left[2].broadcast(first,2); left[2].subtract(rows[2]);
    right[0].broadcast(second,0); right[0].subtract(rows[0]);
    right[1].broadcast(second,1); right[1].subtract(rows[1]);
    right[2].broadcast(second,2); right[2].subtract(rows[2]);
    LaneVector scratch;
    LaneVector sum;
    LaneVector component;
    sum.clear();
    component.product(left[1],right[2]); scratch.product(left[2],right[1]); component.subtract(scratch);
    sum.accumulate(weight.scalar(0),component);
    component.product(left[2],right[0]); scratch.product(left[0],right[2]); component.subtract(scratch);
    sum.accumulate(weight.scalar(1),component);
    component.product(left[0],right[1]); scratch.product(left[1],right[0]); component.subtract(scratch);
    sum.accumulate(weight.scalar(2),component);
    output=sum;
}

extern const LaneVector* obtainVector();
extern LaneVector* obtainOutput();
void keepEdgeTest() { FUN_00d201a0(*obtainVector(),*obtainVector(),obtainVector(),*obtainVector(),*obtainOutput()); }

extern "C" void _mm_store_ss(float*, __m128);
struct ShapeRayCastQuery {
    hkVector4_S m_vFrom;
    hkVector4_S m_vTo;
};
class TriangleRayCast : public hkpTriangleShape_S {
public:
    hkBool_S FUN_00d20a70(const ShapeRayCastQuery&, ShapeRayCastOutput&) const;
};
static __forceinline float rayScalar(const VectorComponentValue& value) {
    float result;
    _mm_store_ss(&result, value.getQuad());
    return result;
}
static __forceinline void rayInterpolate(hkVector4_S& out, const hkVector4_S& a, const hkVector4_S& b, float fraction) {
    static __declspec(align(16)) const float ones[4] = {1,1,1,1};
    __m128 scalar = _mm_load_ss(&fraction);
    __m128 t = _mm_shuffle_ps(scalar,scalar,0);
    __m128 s = _mm_sub_ps(*(const __m128*)ones,t);
    out.getQuad() = _mm_add_ps(_mm_mul_ps(s,a.getQuad()),_mm_mul_ps(t,b.getQuad()));
}
static __forceinline void rayNegate(hkVector4_S& out, const hkVector4_S& a) {
    static __declspec(align(16)) const unsigned int signs[4] = {0x80000000,0x80000000,0x80000000,0x80000000};
    out.getQuad() = _mm_xor_ps(a.getQuad(),*(const __m128*)signs);
}
// Tests a ray against this triangle, writing hit fraction and normal to results and returning whether the ray hits inside the triangle.
// @fnv 0x00d20a70
hkBool_S TriangleRayCast::FUN_00d20a70(const ShapeRayCastQuery&input,ShapeRayCastOutput&results)const
{
const hkpTriangleShape_S*thisObj=this;
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "rcTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkVector4_S&vert0=thisObj->getVertex(0);
const hkVector4_S&vert1=thisObj->getVertex(1);
const hkVector4_S&vert2=thisObj->getVertex(2);
hkVector4_S v10;v10.setSub4(vert1,vert0);
hkVector4_S v20;v20.setSub4(vert2,vert0);
hkVector4_S triangleNormal;triangleNormal.setCross(v10,v20);
const hkReal_S dist=rayScalar(vert0.dot3(triangleNormal));
hkReal_S dist_a=rayScalar(triangleNormal.dot3(input.m_vFrom));
dist_a-=dist;
hkReal_S dist_b=rayScalar(triangleNormal.dot3(input.m_vTo));
dist_b-=dist;
if(dist_a*dist_b>=0.0f)
{
if(dist_a !=0.0f || dist_b==0.0f)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return false;
}
}
const hkReal_S proj_length=dist_a-dist_b;
const hkReal_S distance=dist_a / proj_length;
if(distance<results.m_fHitFraction)
{
hkReal_S edge_tolerance=rayScalar(triangleNormal.lengthSquared3());
edge_tolerance*=-0.0001f;
hkVector4_S point;rayInterpolate(point,input.m_vFrom,input.m_vTo,distance);
{
hkVector4_S v0p;v0p.setSub4(vert0,point);
hkVector4_S v1p;v1p.setSub4(vert1,point);
hkVector4_S cp0;cp0.setCross(v0p,v1p);
if(rayScalar(cp0.dot3(triangleNormal))>=edge_tolerance)
{
hkVector4_S v2p;v2p.setSub4(vert2,point);
hkVector4_S cp1;cp1.setCross(v1p,v2p);
if(rayScalar(cp1.dot3(triangleNormal))>=edge_tolerance)
{
hkVector4_S cp2;cp2.setCross(v2p,v0p);
if(rayScalar(cp2.dot3(triangleNormal))>=edge_tolerance)
{
results.m_fHitFraction=distance;
if(dist_a>0.0f)
{
results.m_vHitNormal=triangleNormal;
}
else
{
rayNegate(results.m_vHitNormal,triangleNormal);
}
results.m_vHitNormal.normalize3();
results.setKey(0xffffffff);
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return true;
}
}
}
}
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return false;
}

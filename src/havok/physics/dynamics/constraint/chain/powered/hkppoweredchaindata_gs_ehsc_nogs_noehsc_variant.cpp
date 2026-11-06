
// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpPoweredChainData.h"
struct FUN_00e3b720_s
{
    int pad0[3];
    int m_iElementCount;  // +0xc
    int pad1[3];
    int m_uiItemCount;  // +0x1c
    void getConstraintInfo(int* info) const;
};
struct FUN_00e3b7d0_first
{
    int pad[7];
    int count;
};
struct FUN_00e3b7d0_second
{
    int pad[7];
    unsigned char* data;
};
struct FUN_00e3b7d0_object
{
    int pad0[3];
    FUN_00e3b7d0_first* first;
    int pad1[8];
    FUN_00e3b7d0_second* second;
};
void FUN_00e3b7d0(FUN_00e3b7d0_object* object, int index, int bit);
int __cdecl FUN_00e3b670();
class hkRefObjE3B8
{
  public:
    virtual ~hkRefObjE3B8() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE3B8() throw()
    {
        m_sReferenceCount = 1;
    }
};
class hkBaseE3B8 : public hkRefObjE3B8
{
  public:
    void* m_pOwnerObject;
    hkBaseE3B8() throw() : m_pOwnerObject(0)
    {}
};
struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;

    FUN_00d21ce0_cls() throw()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* owner) throw();
};
template <typename T> struct hkArrayE3B8
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE3B8() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class FUN_00e3b8f0 : public hkBaseE3B8
{
  public:
    FUN_00d21ce0_cls m_link;
    hkArrayE3B8<void*> m_items;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    float m_3c;

    FUN_00e3b8f0() throw();
    virtual ~FUN_00e3b8f0() throw();
};
class FUN_00e3b9a0
{
  public:
    ~FUN_00e3b9a0() throw();
};
class hkMemoryAllocatorXe3c210
{
  public:
    virtual ~hkMemoryAllocatorXe3c210() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterXe3c210
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe3c210* m_pStreamAllocator;

    hkMemoryAllocatorXe3c210& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXe3c210& __cdecl FUN_00c85750() throw();
class hkObje3c210 : public FUN_00e3b9a0
{
  public:
    hkObje3c210* DestroyObject(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObje3c210*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

#include <xmmintrin.h>
__declspec(align(16)) extern const float DAT_010c44d0[4];

struct Vec4
{
    __m128 m_vComponents;
};

// @fnv 0x00e3b680
static __declspec(noinline) void FUN_00e3b680(const Vec4& b, const Vec4& a, Vec4& r)
{
    {
        __m128 v1 = a.m_vComponents;
        __m128 v2 = b.m_vComponents;
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0xc9), _mm_shuffle_ps(v1, v1, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0xd2), _mm_shuffle_ps(v1, v1, 0xc9));
        r.m_vComponents = _mm_sub_ps(c0, c1);
    }
    {
        __m128 aw = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xff);
        aw = _mm_shuffle_ps(aw, aw, 0);
        r.m_vComponents = _mm_add_ps(r.m_vComponents, _mm_mul_ps(aw, b.m_vComponents));
    }
    {
        __m128 bw = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xff);
        bw = _mm_shuffle_ps(bw, bw, 0);
        r.m_vComponents = _mm_sub_ps(r.m_vComponents, _mm_mul_ps(bw, a.m_vComponents));
    }
    r.m_vComponents = _mm_add_ps(r.m_vComponents, r.m_vComponents);
    __m128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    __m128 q = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    __m128 w = _mm_add_ps(_mm_shuffle_ps(q, q, 0xb1), q);
    if (_mm_movemask_ps(w) & 1)
        r.m_vComponents = _mm_xor_ps(r.m_vComponents, *(const __m128*)DAT_010c44d0);
}

volatile int g_a, g_b, g_r;
void caller_e3b680()
{
    FUN_00e3b680(*(Vec4*)g_b, *(Vec4*)g_a, *(Vec4*)g_r);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Vector
{
    union
    {
        __m128 simd;
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00cb26e0(const hkRotation*);
    void FUN_00c66320(const Vector*, const Vector*);
};
extern const __m128 DAT_010c4c00;
struct Rotation
{
    Vector col[3];
    void FUN_00cb2d90(const Vector*);
};
struct Transform
{
    Rotation rotation;
    Vector translation;
};
struct Entity;
struct ConstraintRuntime
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    char* solverResults;
};
struct ChainInstance
{
    int unk00, unk04, unk08, unk0c, unk10;
    Entity* master;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    ConstraintRuntime* runtime;
    int unk34;
    Entity** entities;
    int entityCount;
};
struct QueryInput
{
    int unk00;
    float unk04, unk08;
    int unk0c, unk10, unk14, unk18, unk1c;
    float virtualMass;
    float rhsFactor;
    int unk28, unk2c;
    int offsetA, offsetB;
    Transform* transformA;
    Transform* transformB;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    ChainInstance* chain;
    char* runtime;
    int unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct QueryOutput
{
    char* jacobian;
};
struct ConstraintInfo
{
    Vector pivotA, pivotB;
    Vector target, targetB;
    void* motors[3];
    unsigned char switched;
    unsigned char unk4d;
    short unk4e;
};
struct MotorState
{
    float unk00, unk04;
};
struct MotorInput
{
    float currentVelocity;
    void* step;
    MotorState state;
    float positionError, deltaTarget;
};
struct MotorOutput
{
    float a, b, c, d, e, f;
};
struct AngularResult
{
    float currentVelocity, zeroA, zeroB;
};
struct ChainMatrix
{
    unsigned char status;
    unsigned char unk01;
    short unk02;
    float values[15];
};
struct BuildInfo
{
    int count;
    float tau, damping, linAdd, linMul, angAdd, angMul;
    int* offsets;
    int offset;
    ChainMatrix* matrices;
    float zero;
    char* states;
    char* jacobian;
};
struct MemoryAllocator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void freeBlock(void*, int);
};
struct MemoryRouter
{
    int unk00, unk04, unk08, unk0c;
    MemoryAllocator* heap;
};
void __cdecl FUN_00c908c0(MemoryAllocator*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
extern "C" void __cdecl AppendEventRecord(const QueryInput*, QueryOutput*, char*, int);
char* __cdecl FUN_00dd13d0(char*);
char* __cdecl FUN_00dd13e0(char*, int);
void __cdecl FUN_00dcee70(QueryInput*);
void __cdecl FUN_00dcfc00(Vector*, Vector*, float, QueryInput*, char*);
void __cdecl FUN_00d6cd70(Vector*, QueryInput*, char*, float*);
void __cdecl FUN_00dcfff0(void*, MotorInput*, MotorOutput*);
void __cdecl WriteInputHeader(BuildInfo*, const QueryInput*, QueryOutput*);
struct Entity
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    Transform transform;
};
// Quaternion error, with sign chosen for the shortest arc.
static __declspec(noinline) void FUN_00e3b680(const Vector& b, const Vector& a, Vector& out)
{
    __m128 av = a.simd, bv = b.simd;
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(bv, bv, 0xc9), _mm_shuffle_ps(av, av, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(bv, bv, 0xd2), _mm_shuffle_ps(av, av, 0xc9)));
    out.simd = cross;
    __m128 aw = _mm_shuffle_ps(a.simd, a.simd, 0xff);
    aw = _mm_shuffle_ps(aw, aw, 0);
    out.simd = _mm_add_ps(_mm_mul_ps(aw, b.simd), cross);
    __m128 bw = _mm_shuffle_ps(b.simd, b.simd, 0xff);
    bw = _mm_shuffle_ps(bw, bw, 0);
    __m128 error = _mm_sub_ps(out.simd, _mm_mul_ps(bw, a.simd));
    out.simd = _mm_add_ps(error, error);
    __m128 dot = _mm_mul_ps(a.simd, b.simd);
    dot = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0x4e), dot);
    dot = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0xb1), dot);
    if (_mm_movemask_ps(dot) & 1)
        out.simd = _mm_xor_ps(out.simd, _mm_set1_ps(-0.0f));
}
static __forceinline void transformPoint(Vector& out, const Transform& t, const Vector& p)
{
    out.simd = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0x55), t.rotation.col[1].simd),
                   _mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0), t.rotation.col[0].simd)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p.simd, p.simd, 0xaa), t.rotation.col[2].simd), t.translation.simd));
}
template <class T> __forceinline void copyConstruct(T* dest, int n, const T& x)
{
    for (int i = 0; i < n; ++i)
        new (dest + i) T(x);
}
template <class T, int N> struct InplaceArray
{
    T* data;
    int size, capacity;
    T storage[N];
    InplaceArray() : data(storage), size(0), capacity(0x80000000 | N)
    {}
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryRouterXe3c210* router = &FUN_00c85750();
        MemoryAllocator* heap = reinterpret_cast<MemoryAllocator*>(router->m_pStreamAllocator);
        int c = capacity & 0x3fffffff;
        if (c < n)
        {
            int next = c * 2;
            if (n >= next)
                next = n;
            FUN_00c908c0(heap, this, next, sizeof(T));
        }
        for (int j = n; j < size; ++j)
            data[j].~T();
        for (int j = size; j < n; ++j)
            new (data + j) T;
        size = n;
    }
    __forceinline void pushBackUnchecked(const T& x)
    {
        copyConstruct(data + size, 1, x);
        ++size;
    }
    __forceinline void AddBack(const T& x)
    {
        hkMemoryRouterXe3c210* route = &FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(route->m_pStreamAllocator, this, sizeof(T));
        copyConstruct(data + size, 1, x);
        ++size;
    }
    __forceinline void deallocate(MemoryAllocator& heap)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            heap.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
    __forceinline void clear()
    {
        hkMemoryRouterXe3c210* router = &FUN_00c85750();
        MemoryAllocator* heap = reinterpret_cast<MemoryAllocator*>(router->m_pStreamAllocator);
        deallocate(*heap);
    }
};
__forceinline char* angularAndKeep(char* lin, QueryOutput& out, int n, char*& keep)
{
    char* p = out.jacobian;
    keep = lin;
    return FUN_00dd13e0(p, n);
}
struct PoweredChain : hkpPoweredChainData
{
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void* motorStep(char*);
    __forceinline ConstraintInfo& getInfo(int i)
    {
        return reinterpret_cast<ConstraintInfo*>(m_pConstraintInfo.m_data)[i];
    }
    void buildJacobian(const QueryInput&, QueryOutput&);
};
// @fnv 0x00e3ba40
void PoweredChain::buildJacobian(const QueryInput& input, QueryOutput& output)
{
    AppendEventRecord(&input, &output, input.runtime, 8);
    QueryInput query = input;
    query.chain = 0;
    query.runtime = 0;
    InplaceArray<int, 32> offsets;
    ChainInstance* chain = input.chain;
    int baseOffset = input.offsetA - chain->master->unka4;
    int count = chain->entityCount - 1;
    InplaceArray<ChainMatrix, 32> matrices;
    matrices.SetSizeAndGrow(count);
    Entity* first = chain->entities[0];
    query.offsetB = first->unka4 + baseOffset;
    offsets.pushBackUnchecked(query.offsetB - baseOffset);
    reinterpret_cast<int&>(query.virtualMass) = reinterpret_cast<const int&>(query.unk08);
    query.rhsFactor = 1.0f;
    query.transformB = &first->transform;
    char* schema = output.jacobian;
    char* jacobian;
    char* states = angularAndKeep(FUN_00dd13d0(schema), output, count, jacobian);
    for (int i = 0; i < count; ++i)
    {
        query.offsetA = query.offsetB;
        query.transformA = query.transformB;
        Entity* next = chain->entities[i + 1];
        query.offsetB = next->unka4 + baseOffset;
        int offset = query.offsetB - baseOffset;
        offsets.AddBack(offset);
        query.transformB = &next->transform;
        {
            Vector pivotA, pivotB;
            transformPoint(pivotA, *query.transformA, getInfo(i).pivotA);
            transformPoint(pivotB, *query.transformB, getInfo(i).pivotB);
            FUN_00dcee70(&query);
            FUN_00dcfc00(&pivotA, &pivotB, m_fMaximumAngularImpulse, &query, jacobian);
            jacobian += 0x90;
        }
        Vector rotationA, rotationB;
        rotationA.FUN_00cb26e0(reinterpret_cast<hkRotation*>(&query.transformA->rotation));
        rotationB.FUN_00cb26e0(reinterpret_cast<hkRotation*>(&query.transformB->rotation));
        if (getInfo(i).switched)
        {
            Vector tmp = rotationA;
            rotationA.simd = rotationB.simd;
            rotationB.simd = tmp.simd;
        }
        {
            Vector product;
            product.FUN_00c66320(&rotationB, &getInfo(i).targetB);
            rotationB.simd = product.simd;
        }
        Vector& target = getInfo(i).target;
        int n = m_pConstraintInfo.m_iElementCount;
        Vector* previous = reinterpret_cast<Vector*>(input.runtime + ((n + 3) & ~3) + (3 * n + i) * 16);
        Vector previousTarget;
        previousTarget.simd = _mm_setr_ps(previous->x, previous->y, previous->z, previous->w);
        __m128 sq = _mm_mul_ps(previousTarget.simd, previousTarget.simd);
        sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
        sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0xb1), sq);
        float squaredLength;
        _mm_store_ss(&squaredLength, sq);
        if (squaredLength == 0.0f)
            previousTarget.simd = target.simd;
        Vector targetWorld, oldTargetWorld;
        targetWorld.FUN_00c66320(&rotationA, &target);
        oldTargetWorld.FUN_00c66320(&rotationA, &previousTarget);
        previous->x = target.x;
        previous->y = target.y;
        previous->z = target.z;
        previous->w = target.w;
        Vector error, oldError;
        FUN_00e3b680(rotationB, targetWorld, error);
        FUN_00e3b680(rotationB, oldTargetWorld, oldError);
        error.simd = _mm_sub_ps(error.simd, oldError.simd);
        if (getInfo(i).switched)
        {
            error.simd = _mm_xor_ps(error.simd, DAT_010c4c00);
            oldError.simd = _mm_xor_ps(oldError.simd, DAT_010c4c00);
        }
        Rotation axes;
        axes.FUN_00cb2d90(&rotationB);
        for (int axis = 0; axis < 3; ++axis)
        {
            Vector direction = axes.col[axis];
            MotorInput motorInput;
            char* solverResults = chain->runtime->solverResults;
            MotorState* __restrict motorStates = static_cast<MotorState*>(motorStep(solverResults));
            motorInput.state.unk00 = 0.0f;
            motorInput.state.unk04 = 0.0f;
            FUN_00d6cd70(&direction, &query, states, &motorInput.currentVelocity);
            motorInput.positionError = reinterpret_cast<float*>(&error)[axis];
            motorInput.deltaTarget = reinterpret_cast<float*>(&oldError)[axis];
            motorInput.step = &query;
            motorInput.state = motorStates[i * 6 + axis + 3];
            MotorOutput motorOutput;
            FUN_00dcfff0(getInfo(i).motors[axis], &motorInput, &motorOutput);
            float* dst = matrices.data[i].values + axis * 5;
            dst[0] = motorOutput.c * query.unk04;
            dst[1] = motorOutput.d * query.unk04;
            dst[2] = motorOutput.b;
            dst[3] = motorOutput.e;
            dst[4] = motorOutput.f;
            reinterpret_cast<float*>(states)[7] = motorOutput.a * query.unk08;
            states += 0x20;
        }
    }
    char* status = chain->runtime->solverResults + m_pConstraintInfo.m_iElementCount * 0x30;
    for (int i = 0; i < count; ++i)
        matrices.data[i].status = status[i];
    {
        BuildInfo build;
        build.count = count;
        build.tau = m_fTau;
        build.damping = m_fMotorDamping;
        build.linAdd = m_fMaximumErrorDistance;
        build.linMul = m_fMaximumLinearImpulse;
        build.angAdd = m_fBreachImpulse;
        build.angMul = m_fInertiaStabilizationFactor;
        build.offsets = offsets.data;
        build.offset = baseOffset;
        build.matrices = matrices.data;
        build.zero = 0.0f;
        build.states = status;
        build.jacobian = states;
        WriteInputHeader(&build, &input, &output);
    }
    matrices.clear();
    offsets.clear();
}

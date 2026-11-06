// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct D3DD50CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D3DD50CollectorBase() : m_bFound(false) {}
};
struct D3DD50Collector : D3DD50CollectorBase {
    int m_iData;

    D3DD50Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl D3DD50Query(int a, int b, int c, D3DD50CollectorBase* collector);
void __cdecl QueryD3DCollector(int aiArg1, int aiArg2, int aiArg3, int aiData);
extern char DAT_010ce7fc[];
struct Functor_d3e110 {
    void* m_vtbl;
    float m_fHitFraction;
    int m_uiFilterValue;
};
void __cdecl FUN_00d3d8c0(int a, int b, int c, Functor_d3e110* f);
void __cdecl FUN_00d3e110(int a, int b, int aiArg3, int d);
struct SpawnedInner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14(unsigned short flags, void* param);
};
class FUN_00d3d200_cls
{
public:
    virtual void unk00(int flags);
    int m_unk04;                 // +0x04
    SpawnedInner* m_pInner;      // +0x08
    unsigned short m_wFlags;     // +0x0C

    void cleanup(void* param);
};
struct hkMemory {
    virtual void unk0();
    virtual void* allocateChunk(int size);
};
struct hkThreadMemory {
    char pad[0x10];
    hkMemory* m_pMemoryAllocator;

    void* allocateChunk(int size) {
        return m_pMemoryAllocator->allocateChunk(size);
    }
};
extern "C" hkThreadMemory* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00cd7160(void* src, void* dst);
extern "C" const void* DAT_010cf060;
extern "C" const void* DAT_010cf09c;
struct TargetAgent {
    const void* vtable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pContactManager;
    unsigned short m_padC;
    short m_padE;
    char m_pAccessManager[0x10];

    TargetAgent(const void* bodyA, void* mgr)
        : m_usMemSizeAndFlags(0x20),
          m_sReferenceCount(1),
          m_pContactManager(mgr),
          m_padC(0xffff)
    {
        vtable = &DAT_010cf060;
        void* triangle = *(void**)bodyA;
        FUN_00cd7160((char*)triangle + 0x20, m_pAccessManager);
        vtable = &DAT_010cf09c;
    }
};
void* __cdecl CreateTargetAgent(void* bodyA, void* bodyB, void* input, void* mgr);
extern char DAT_010ce81c[];
struct D3DD10Data
{
    void* vt;
    unsigned char flag;
    unsigned int value;
};
struct D3DD10Object
{
    void __thiscall getPenetrations(unsigned int a1, unsigned int a2,
                                 unsigned int a3, D3DD10Data* data);

    void __thiscall FUN_00d3dd10(unsigned int p0, unsigned int p1,
                                 unsigned int p2, unsigned int p3);
};
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void setBroadcast3(const hkVector4q& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
    __forceinline void xor4(const hkVector4q& b) { m_vComponents = _mm_xor_ps(m_vComponents, b.m_vComponents); }
    __forceinline void setXor4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_xor_ps(a.m_vComponents, b.m_vComponents); }
};
template <typename T>
__forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct NibblePair
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct SpawnedParticle
{
    hkVector4q m_vContactPosition;
    hkVector4q m_fVelocity;
    hkVector4q m_extra;
};
struct ParticleSystemState
{
    SpawnedParticle* m_kRayEnd;
    int unk0004;
    int unk0008;
    int unk000C;
    SpawnedParticle m_particles[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    hkVector4q m_3020;
    float m_3030;
    int unk3034;
    int unk3038;
    int unk303C;
    struct Info
    {
        unsigned short m_3040;
        unsigned short m_3042;
        unsigned short m_3044;
        unsigned short unk3046;
        unsigned char m_3048;
        unsigned char m_3049;
        NibblePair m_304a;
        unsigned char unk304b;
    } m_info;
};
extern hkVector4q DAT_010c4c00;
class ParticleSystemOps
{
public:
    void processCollision(int a, int b, int c, ParticleSystemState* state);
    void FUN_00d3e150(int a1, int a2, int a3, ParticleSystemState* s);
};
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_unpacklo_ps(__m128, __m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_movelh_ps(__m128, __m128);
__m128 _mm_movehl_ps(__m128, __m128);
void _mm_store_ps(float*, __m128);
}
extern "C" DWORD DAT_0126835c;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};
struct Res {
    Vec4 pt;
    float d;
};
struct Arg3S {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float f10;
};
struct ProfRec {
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};
struct ProfBuf {
    unsigned int unk00;
    ProfRec* cur;
    unsigned int unk08;
    ProfRec* end;
};
struct XForm {
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 t;
};
struct BodyB {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct BodyHolderB {
    BodyB* obj;
    int unk04;
    XForm* xf;
};
struct Sink {
    virtual void unk00();
    virtual void unk04(BodyHolderB& a, BodyHolderB& b);
};
extern void __cdecl FUN_00cd7850(Vec4* v, void* tri, float* f, Res* out, void* flag);
// non-POD 1-dword wrapper params: block the entry-enregister pass so the
// params are read lazily from their incoming arg slots (see e2fbc0)
struct BHWrap {
    BodyHolderB* p;
    BHWrap(BodyHolderB* q) : p(q) {}
};
struct SinkWrap {
    Sink* p;
    SinkWrap(Sink* q) : p(q) {}
};
class SphereTriAgent {
public:
    int unk00, unk04, unk08, unk0C;
    float unk10;
    void getPenetrations(BodyHolderB* a, BodyHolderB* b, int c_, Sink* sink);
};
// rotate the translation difference by the inverse of B's rotation (HK_TRANSPOSE3), compute the
// closest point, and report a contact when the distance is below the summed radii.
extern DWORD DAT_0126835c;
extern char DAT_010cf0d4[];
// "TtSphereTri"
extern char DAT_010c41f8[];
// "Et"
struct S_00d3d3e0_Entry {
    const char* name;
    unsigned time;
    int unk08;
};
struct S_00d3d3e0_Hdr {
    int unk00;
    S_00d3d3e0_Entry* cur;
    int unk08;
    S_00d3d3e0_Entry* end;
};
struct __declspec(align(16)) S_00d3d3e0_V4 {
    float x, y, z, w;
};
struct S_00d3d3e0_Mat {
    S_00d3d3e0_V4 r0, r1, r2, t;
};
struct S_00d3d3e0_Shape {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00d3d3e0_Obj {
    int unk00, unk04, unk08, unk0c;
    float f10;
    int unk14, unk18, unk1c;
    int unk20;
};
struct S_00d3d3e0_P1 {
    S_00d3d3e0_Shape* shape;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P2 {
    S_00d3d3e0_Obj* obj;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P3 {
    virtual void v0();
    virtual void v1(S_00d3d3e0_P1* a, S_00d3d3e0_P2* b);
};
struct __declspec(align(16)) S_00d3d3e0_Out {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
void __cdecl FUN_00cd7160(void* a, S_00d3d3e0_V4* out);
void __cdecl FUN_00cd7850(S_00d3d3e0_V4* a, void* b, S_00d3d3e0_V4* c, S_00d3d3e0_Out* d, bool* e);
struct S_00d3d3e0_P1P { S_00d3d3e0_P1* p; S_00d3d3e0_P1* val() const { return p; } };
struct S_00d3d3e0_P2P { S_00d3d3e0_P2* p; S_00d3d3e0_P2* val() const { return p; } };
struct S_00d3d3e0_P3P { S_00d3d3e0_P3* p; S_00d3d3e0_P3* val() const { return p; } };
void FUN_00d3d3e0(S_00d3d3e0_P1P a1, S_00d3d3e0_P2P a2, int unused, S_00d3d3e0_P3P a3);

extern "C" __m128 _mm_load_ss(float const*_A);
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
__m128 _mm_load_ss(const float*);
}
struct __declspec(align(16)) S00d3d6b0_Vec4 { float x,y,z,w; };
struct S00d3d6b0_Res { S00d3d6b0_Vec4 pt; float d; };
struct S00d3d6b0_ProfRec { const char* name; unsigned int tsc; unsigned int unk08; };
struct S00d3d6b0_ProfBuf { unsigned int unk00; S00d3d6b0_ProfRec* cur; unsigned int unk08; S00d3d6b0_ProfRec* end; };
struct S00d3d6b0_XForm { S00d3d6b0_Vec4 r0,r1,r2,t; };
struct S00d3d6b0_BodyB {
    int unk00,unk04,unk08,unk0C;
    float radius;
    int unk14,unk18,unk1C;
    S00d3d6b0_Vec4 vertices[3];
};
struct S00d3d6b0_BodyHolderB { S00d3d6b0_BodyB* obj; int unk04; S00d3d6b0_XForm* xf; };
struct S00d3d6b0_HitInfo { S00d3d6b0_Vec4 pt,nrm; S00d3d6b0_BodyHolderB* a; S00d3d6b0_BodyHolderB* b; };
struct S00d3d6b0_Sink { virtual void unk00(); virtual void unk04(S00d3d6b0_HitInfo*); };
struct S00d3d6b0_Input { int unk00,unk04; float tolerance; };
extern void __cdecl FUN_00cd7850(S00d3d6b0_Vec4* v, void* tri, float* f, S00d3d6b0_Res* out, void* flag);
class S00d3d6b0_SphereTriAgent {
public:
    int unk00,unk04,unk08,unk0C;
    float unk10;
    void FUN_00d3d6b0(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink);
};
// @fnv 0x00d3d6b0
void S00d3d6b0_SphereTriAgent::FUN_00d3d6b0(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink) {
    volatile unsigned int lo;
    {
        S00d3d6b0_ProfBuf* buf = (S00d3d6b0_ProfBuf*)TlsGetValue(DAT_0126835c);
        S00d3d6b0_ProfRec* r = buf->cur;
        if (r < buf->end) {
            r->name = "TtSphereTri";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            r->tsc = lo;
            buf->cur = r + 1;
        }
    }
    S00d3d6b0_HitInfo hit;
    hit.a=a;
    hit.b=b;
    S00d3d6b0_BodyB* shapeA = a->obj;
    S00d3d6b0_BodyB* shapeB = b->obj;
    S00d3d6b0_XForm* axf = a->xf;
    S00d3d6b0_Vec4* center = &axf->t;
    S00d3d6b0_Vec4 tri[3];
    S00d3d6b0_Res out;
    {
        S00d3d6b0_Vec4 r0,r1,r2;
        r0=b->xf->r0;
        r1=b->xf->r1;
        r2=b->xf->r2;
        out.pt=b->xf->t;
        for (int i=2; i>=0; --i) {
            __m128 v = *(__m128*)&shapeB->vertices[i];
            __m128 y = _mm_shuffle_ps(v,v,0x55);
            __m128 x = _mm_shuffle_ps(v,v,0);
            __m128 z = _mm_shuffle_ps(v,v,0xaa);
            __m128 px = _mm_mul_ps(x,*(__m128*)&r0);
            __m128 py = _mm_mul_ps(y,*(__m128*)&r1);
            __m128 pz = _mm_mul_ps(z,*(__m128*)&r2);
            *(__m128*)&tri[i] = _mm_add_ps(_mm_add_ps(py,px),_mm_add_ps(pz,*(__m128*)&out.pt));
        }
    }
    FUN_00cd7850(center,tri,&unk10,&out,0);
    float sum = shapeA->radius+shapeB->radius;
    float distance = out.d;
    float threshold = input->tolerance+sum;
    if (distance < threshold) {
        float delta = shapeB->radius-distance;
        __m128 centerValue = *(__m128*)center;
        __m128 scalar = _mm_load_ss(&delta);
        __m128 splat = _mm_shuffle_ps(scalar,scalar,0);
        __m128 normal = *(__m128*)&out.pt;
        __m128 pos = _mm_add_ps(_mm_mul_ps(splat,normal),centerValue);
        *(__m128*)&hit.pt = pos;
        *(__m128*)&hit.nrm = normal;
        hit.nrm.w = distance-sum;
        sink->unk04(&hit);
    }
    {
        S00d3d6b0_ProfBuf* buf = (S00d3d6b0_ProfBuf*)TlsGetValue(DAT_0126835c);
        S00d3d6b0_ProfRec* r = buf->cur;
        if (r < buf->end) {
            r->name = "Et";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            r->tsc = lo;
            buf->cur = r + 1;
        }
    }
}

extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_load_ss(const float*);
}

struct Transform;

struct FourFloatVector {
    union { __m128 m; float f[4]; };
    __forceinline void operator=(const FourFloatVector& rhs) { m = rhs.m; }
    __forceinline void transformed(const Transform& t, const FourFloatVector& v);
    __forceinline void addScaled(const FourFloatVector& base, const FourFloatVector& direction, float amount) {
        __m128 scalar = _mm_load_ss(&amount);
        scalar = _mm_shuffle_ps(scalar, scalar, 0);
        m = _mm_add_ps(base.m, _mm_mul_ps(scalar, direction.m));
    }
    __forceinline float& component(int n) { return f[n]; }

};

struct Transform {
    FourFloatVector col0;
    FourFloatVector col1;
    FourFloatVector col2;
    FourFloatVector translation;
    __forceinline Transform(const Transform& rhs) {
        const FourFloatVector c0 = rhs.col0, c1 = rhs.col1, c2 = rhs.col2, c3 = rhs.translation;
        col0 = c0; col1 = c1; col2 = c2; translation = c3;
    }
};

__forceinline void FourFloatVector::transformed(const Transform& t, const FourFloatVector& v) {
    __m128 splatX = _mm_shuffle_ps(v.m, v.m, 0);
    __m128 prodX = _mm_mul_ps(t.col0.m, splatX);
    __m128 splatY = _mm_shuffle_ps(v.m, v.m, 0x55);
    __m128 prodY = _mm_mul_ps(t.col1.m, splatY);
    __m128 splatZ = _mm_shuffle_ps(v.m, v.m, 0xaa);
    __m128 prodZ = _mm_mul_ps(t.col2.m, splatZ);
    m = _mm_add_ps(_mm_add_ps(prodX, prodY), _mm_add_ps(prodZ, t.translation.m));
}

struct AlignedPairData {
    FourFloatVector m_vContactPosition;
    FourFloatVector m_vSeparatingNormal;
    unsigned int m_iOwnerObjectOffset;
    int pad24;
    int pad28;
    int pad2C;
};

struct Shape;
struct CdBody {
    Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    Transform* m_kMotionState;
    Shape* shape() const { return m_pCollisionShape; }
    const Transform& transform() const { return *m_kMotionState; }
};

struct Shape {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual int weldContactPoint(void* a1, void* a2, void* a3, const void* a4, const void* a5, const void* a6, void* a7);

    float m_fSphereRadius;
    int pad14;
    int pad18;
    int pad1C;
    FourFloatVector m_kVertices[3];
};

struct CollisionConstraintOwner {};

struct ProcessCollisionOutput {
    AlignedPairData* m_pAlignedPairData;
    CollisionConstraintOwner* m_pConstraintOwner;
};

struct ProcessCollisionInput {
    int unk00;
    int unk04;
    float m_fCollisionTolerance;
};

struct ContactMgr {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned short addContactPoint(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result, int zero, AlignedPairData* cp);
    virtual void unk10();
    virtual void removeContactPoint(unsigned short id, CollisionConstraintOwner& owner);
};

struct MonitorRecord {
    const char* name;
    unsigned int timestamp;
    unsigned int auxiliary;
};
struct MonitorStream {
    void* unk0;
    MonitorRecord* m_pTileTemplate;
    void* unk8;
    MonitorRecord* m_pRayCursor;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

extern "C" int __cdecl FUN_00cd7850(
    const void* spherePos,
    const void* vertices,
    void* cache,
    void* output,
    void* weldFlag
);

union FeatureInfo {
    struct { unsigned char count; unsigned short indices[3]; };
    unsigned __int64 encoded;
};

struct ClosestPointOutput {
    FourFloatVector m_vHitNormal;
    float m_fClosestPointDistanceSquared;
};

static __forceinline int queryContact(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, void* cache, AlignedPairData* cp, FeatureInfo* feature) {
    Shape* shapeA = bodyA->shape();
    Shape* shapeB = bodyB->shape();
    const FourFloatVector* spherePos = &(&bodyA->transform())->translation;

    __declspec(align(16)) FourFloatVector vTransformed[3];
        const Transform* motionB = (&bodyB->transform());
        Transform copy(*motionB);
        for (int i=2; i>=0; --i) {
            vTransformed[i].transformed(copy, shapeB->m_kVertices[i]);
        }

    __declspec(align(16)) ClosestPointOutput cpOutput;
    int featureKind = FUN_00cd7850(spherePos, vTransformed, cache, &cpOutput, feature);

    float sumRadius = shapeA->m_fSphereRadius + shapeB->m_fSphereRadius;
    float maxDist = sumRadius + input->m_fCollisionTolerance;

    if (cpOutput.m_fClosestPointDistanceSquared < maxDist) {
        cp->m_vContactPosition.addScaled(*spherePos, cpOutput.m_vHitNormal, shapeB->m_fSphereRadius - cpOutput.m_fClosestPointDistanceSquared);
        cp->m_vSeparatingNormal = cpOutput.m_vHitNormal;
        cp->m_vSeparatingNormal.component(3) = cpOutput.m_fClosestPointDistanceSquared - sumRadius;

        if (featureKind) return 2; return 1;
    }
    return 0;
}

struct TargetAgent_Cand : TargetAgent {
    void processCollision(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result);
};

// @fnv 0x00d3dd90
void TargetAgent_Cand::processCollision(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result) {
    MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
    MonitorRecord* cur = stream->m_pTileTemplate;
    if (cur < stream->m_pRayCursor) {
        cur->name = DAT_010cf0d4;
        unsigned int ticks;
        _ReadWriteBarrier();
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cur->timestamp = ticks;
        stream->m_pTileTemplate = cur + 1;
    }

    AlignedPairData* cp = result->m_pAlignedPairData;
    FeatureInfo weldFlag;
    if (queryContact(bodyA, bodyB, input, this->m_pAccessManager, cp, &weldFlag)) {
        unsigned char m_uiMaterialIndex = weldFlag.count;
        if (m_uiMaterialIndex > 0) {
            Shape* weldShape = bodyB->shape();
            FourFloatVector normalOut = cp->m_vSeparatingNormal;
            FourFloatVector posOut = cp->m_vContactPosition;
            int weldRes = weldShape->weldContactPoint(weldFlag.indices, &m_uiMaterialIndex, &posOut, (&bodyB->transform()), bodyA->shape(), (&bodyA->transform()), &normalOut);
            if (weldRes == 0) {
                if (this->m_padC != 0xffff) {
                    ((ContactMgr*)this->m_pContactManager)->removeContactPoint(this->m_padC, *result->m_pConstraintOwner);
                    this->m_padC = 0xffff;
                }
                return;
            }
            if (weldRes == 1) {
                __m128 oldNormal = cp->m_vSeparatingNormal.m;
                __m128 newNormal = normalOut.m;
                __m128 unpck = _mm_unpackhi_ps(newNormal, oldNormal);
                cp->m_vSeparatingNormal.m = _mm_shuffle_ps(newNormal, unpck, 0xc4);
            }
        }

        if (this->m_padC == 0xffff) {
            this->m_padC = ((ContactMgr*)this->m_pContactManager)->addContactPoint(bodyA, bodyB, input, result, 0, cp);
        }
        if (this->m_padC != 0xffff) {
            cp->m_iOwnerObjectOffset = this->m_padC;
            ++result->m_pAlignedPairData;
        }
    } else {
        if (this->m_padC != 0xffff) {
            ((ContactMgr*)this->m_pContactManager)->removeContactPoint(this->m_padC, *result->m_pConstraintOwner);
            this->m_padC = 0xffff;
        }
    }

    MonitorStream* streamEnd = (MonitorStream*)TlsGetValue(DAT_0126835c);
    MonitorRecord* curEnd = streamEnd->m_pTileTemplate;
    if (curEnd < streamEnd->m_pRayCursor) {
        curEnd->name = DAT_010c41f8;
        unsigned int ticks;
        _ReadWriteBarrier();
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        curEnd->timestamp = ticks;
        streamEnd->m_pTileTemplate = curEnd + 1;
    }
}

extern "C" __m128 _mm_load_ss(const float*);
static __forceinline __m128 PlainBroadcast(const float& f) {
 __m128 t=_mm_load_ss(&f); return _mm_shuffle_ps(t,t,0);
}


struct __declspec(align(16)) S_00d3d520_V4 {
    float x, y, z, w;
    __m128& q() { return reinterpret_cast<__m128&>(*this); }
    const __m128& q() const { return reinterpret_cast<const __m128&>(*this); }
};

struct S_00d3d520_Col {
    float x, y, z, w;
};

struct S_00d3d520_T {
    S_00d3d520_Col c0;
    S_00d3d520_Col c1;
    S_00d3d520_Col c2;
    S_00d3d520_Col c3;
};

static __forceinline void S_00d3d520_Xform(S_00d3d520_V4& out, const S_00d3d520_Col& c0, const S_00d3d520_Col& c1, const S_00d3d520_Col& c2, const S_00d3d520_Col& c3, const S_00d3d520_V4& b)
{
    const __m128 xb = _mm_shuffle_ps(b.q(), b.q(), 0x00);
    const __m128 yb = _mm_shuffle_ps(b.q(), b.q(), 0x55);
    const __m128 zb = _mm_shuffle_ps(b.q(), b.q(), 0xaa);
    const __m128 t0 = _mm_mul_ps(xb, *(const __m128*)&c0);
    const __m128 t1 = _mm_mul_ps(yb, *(const __m128*)&c1);
    const __m128 t2 = _mm_mul_ps(zb, *(const __m128*)&c2);
    out.q() = _mm_add_ps(_mm_add_ps(t1, t0), _mm_add_ps(t2, *(const __m128*)&c3));
}

static __forceinline void S_00d3d520_TransformPoints(const S_00d3d520_T& t, const S_00d3d520_V4* in, S_00d3d520_V4* out)
{
    S_00d3d520_Col c0 = t.c0;
    S_00d3d520_Col c1 = t.c1;
    S_00d3d520_Col c2 = t.c2;
    S_00d3d520_Col c3 = t.c3;
    int i = 2;
    do {
        S_00d3d520_Xform(out[i], c0, c1, c2, c3, in[i]);
    } while (--i >= 0);
}

struct S_00d3d520_Shape {
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    S_00d3d520_V4 verts[3];
};

struct S_00d3d520_Body {
    S_00d3d520_Shape* shape;
    int unk04;
    S_00d3d520_T* motion;
};

struct S_00d3d520_A {
    S_00d3d520_Shape* shape;
    int unk04;
    S_00d3d520_V4* pos;
};

struct S_00d3d520_Info {
    int unk00;
    int unk04;
    float distance;
};

struct __declspec(align(16)) S_00d3d520_Res {
    S_00d3d520_V4 normal;
    float dist;
};

struct S_00d3d520_Out { S_00d3d520_V4 point; union { S_00d3d520_V4 normal; struct {float nx,ny,nz; volatile float distance;}; }; };

int __cdecl FUN_00cd7850(const S_00d3d520_V4* pos, const S_00d3d520_V4* tri, int a4, S_00d3d520_Res* out, char* flag);

// @fnv 0x00d3d520
int __cdecl FUN_00d3d520(S_00d3d520_A* a, S_00d3d520_Body* b, S_00d3d520_Info* info, int a4, S_00d3d520_Out* outp)
{
    S_00d3d520_V4 v[3]; S_00d3d520_Shape* sphere = a->shape;
    { S_00d3d520_Shape* tri = b->shape;
    const S_00d3d520_V4* count = a->pos + 3;
    
    S_00d3d520_TransformPoints(*b->motion, tri->verts, v);
    S_00d3d520_Res pen;
    int r = FUN_00cd7850(count, v, a4, &pen, 0);
    float k = sphere->radius + tri->radius;
    
    float thr = info->distance + k;
    if (pen.dist < thr) {
S_00d3d520_Out* o=outp;
float res=tri->radius-pen.dist;
double separation=pen.dist-k;
volatile float* distance=&o->distance;
o->point.q()=_mm_add_ps(count->q(),_mm_mul_ps(PlainBroadcast(res),pen.normal.q()));
o->normal.q()=pen.normal.q();
*distance=(float)separation;
        int f = 1 + (r != 0); return f;
    } }
    return 0;
}

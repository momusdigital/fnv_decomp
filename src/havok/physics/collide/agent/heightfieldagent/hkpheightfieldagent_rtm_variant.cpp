// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern char DAT_010ceaa8[];
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
};
struct BSAudio {
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
};
BSAudio* FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
struct SizeSource {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual int GetCount();
};
struct SourceRef {
    SizeSource* m_p;
};
struct hkArrayU16 {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init() { m_data = 0; m_iElementCount = 0; m_iCapacityState = 0x80000000; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(int n)
    {
        BSAudio* a = FUN_00c85750();
        hkMemoryAllocator* alloc = a->unk10;
        int c = m_iCapacityState & 0x3fffffff;
        if (c < n) {
            c = c * 2;
            FUN_00c908c0(*alloc, this, n < c ? c : n, 2);
        }
    }
    __forceinline void SetSizeAndGrow(int n, const unsigned short& fill)
    {
        reserve(n);
        int num = n - m_iElementCount;
        unsigned short* p = m_data + m_iElementCount;
        for (int i = 0; i < num; ++i) {
            p[i] = fill;
        }
        m_iElementCount = n;
    }
};
struct FUN_00d32060_Class {
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_flag;
    hkArrayU16 m_aiIndexedValues;

    FUN_00d32060_Class* Init(const SourceRef& src, int b, int c, int flag);
};
extern void __cdecl FUN_00d319e0(void*, void*, void*, void*);
void __stdcall FUN_00d32170(void* apArg1, void* apArg2, void* apArg3, void* apArg4);
typedef void (*S_00d321e0_Func)();
void FUN_00d32190();
void FUN_00d32370();
void FUN_00d323b0();
void FUN_00d323f0();
void AllocateTargetObj();
void FUN_00d317d0();
void FUN_00d319e0();
void FUN_00d31d30();
struct S_00d321e0_AgentFuncs {
    S_00d321e0_Func m_pCreateFunc;
    S_00d321e0_Func m_pQueryPenetrationsFunc;
    S_00d321e0_Func m_pGetPenetrationsFunc;
    S_00d321e0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d321e0_Dispatcher {
    void FUN_00cfbbe0(S_00d321e0_AgentFuncs& f, int typeA, int typeB);
};
void FUN_00d321e0(S_00d321e0_Dispatcher* dispatcher);
extern float g_D323B0MaxDistance;
struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(g_D323B0MaxDistance) {}
};
struct D323B0Collector : D323B0CollectorBase {
    int m_iData;

    D323B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl FUN_00d319e0(int a, int b, int c, D323B0CollectorBase* collector);
void __cdecl FUN_00d323b0(int aiArg1, int aiArg2, int aiArg3, int aiData);
struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void NotifyAndClear(int value);
};
extern "C" void __cdecl FUN_00d31d30(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// Forwards all five arguments unchanged to FUN_00d31d30.
// @fnv 0x00d32030
extern "C" void __stdcall FUN_00d32030(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    FUN_00d31d30(arg0, arg1, arg2, arg3, arg4);
}
extern "C" void __cdecl FUN_00d317d0(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d32150
extern "C" void __stdcall FUN_00d32150(void* arg0, void* arg1, void* arg2, void* arg3)
{
    FUN_00d317d0(arg0, arg1, arg2, arg3);
}
extern char DAT_010ce81c;
void __cdecl FUN_00d317d0(int a1, int a2, int a3, void* a4);
struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    int d;
};
void __cdecl FUN_00d32370(int aiArg1, int aiArg2, int aiArg3, int a4);
#include <xmmintrin.h>
namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128 {float m128_f32[4];};
extern "C" {
__m128 _mm_add_ps(__m128,__m128); __m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,int); __m128 _mm_unpackhi_ps(__m128,__m128);
__m128 _mm_load_ss(const float*);
}
}
extern unsigned long DAT_0126835c;
extern const char DAT_010cea38[];
extern const char DAT_010cea7c[];
extern const char DAT_010cea6c[];
extern const char DAT_010cea60[];
extern const char DAT_010cea54[];
extern const char DAT_010cea48[];
extern const char DAT_01076f38[];
extern const char str_010cea1c[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHi;
    const char* subName;
};
struct StringCursor {
    int unk00;
    char* m_memPos;
    int unk08;
    char* m_memEnd;

    static __forceinline StringCursor& GetMonitorStream() {
        return *(StringCursor*)TlsGetValue(DAT_0126835c);
    }
    __forceinline void timerBegin(const char* name1, const char* name2) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name1;
            cmd->subName = name2;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_memPos = (char*)(cmd + 1);
        }
    }
    __forceinline void timerSplit(const char* name) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_memPos = (char*)cmd + 12;
        }
    }
    __forceinline void timerEnd(const char* name) { timerSplit(name); }
};
struct hkTransform;
struct hkVector4 {
    union { N::__m128 m_vComponents; struct { float x,y,z,w; }; };

    __forceinline void SetRotatedDirection(const hkTransform& a, const hkVector4& b);
    __forceinline void SetTransformedPoint(const hkTransform& a, const hkVector4& b);
};
struct hkTransform {
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    hkTransform() {}
    __forceinline hkTransform(const hkTransform& other) {
        m_kColumn0.m_vComponents=other.m_kColumn0.m_vComponents;
        m_kColumn1.m_vComponents=other.m_kColumn1.m_vComponents;
        m_kColumn2.m_vComponents=other.m_kColumn2.m_vComponents;
        m_vTranslation.m_vComponents=other.m_vTranslation.m_vComponents;
    }
    void FUN_00cb22f0(const void* b, const void* a);
};
__forceinline void hkVector4::SetRotatedDirection(const hkTransform& a, const hkVector4& b) {
    N::__m128 y = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents));
}
__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b) {
    N::__m128 y = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_add_ps(N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
}
__forceinline void transformSphere(hkVector4& __restrict out, const hkTransform& __restrict a, const hkVector4& __restrict sphere) {
    N::__m128 y = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x55);
    N::__m128 x = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x00);
    N::__m128 z = N::_mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0xaa);
    N::__m128 pos = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, a.m_kColumn1.m_vComponents), N::_mm_mul_ps(x, a.m_kColumn0.m_vComponents)), N::_mm_add_ps(N::_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
    N::__m128 unpck = N::_mm_unpackhi_ps(pos, sphere.m_vComponents);
    out.m_vComponents = N::_mm_shuffle_ps(pos, unpck, 0xc4);
}
struct hkSphere : hkVector4 {};
__forceinline void transformSpheres(const hkTransform& tr, const hkSphere* src, int count, hkSphere* dst) {
    hkTransform local = tr;
    int i = count - 1;
    do {
        hkVector4 value;
        value.SetTransformedPoint(local,src[i]);
        value.m_vComponents = N::_mm_shuffle_ps(value.m_vComponents,N::_mm_unpackhi_ps(value.m_vComponents,src[i].m_vComponents),0xc4);
        dst[i].m_vComponents = value.m_vComponents;
    } while (--i >= 0);
}
struct hkpShape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int getNumCollisionSpheres();
    virtual const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer);
};
struct CollisionSphereData {
    __forceinline void setSpheres(const hkSphere* p){ m_kSpheres=p; }
    const hkSphere* m_kSpheres;
    int m_iSphereCount;
    float m_fScalar;
};
struct hkpHeightFieldShape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* hitResults);
};
struct hkMotionState {
    hkTransform m_kMotionTransform;
};
struct hkpCdBody {
    const hkpShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const hkMotionState* m_pMotionState;
};
struct CollisionAgentContext {
    int unk00;
    int unk04;
    float m_fScalar;
};
struct hkContactPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};
struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    ContactPointPair() {}
    __forceinline ContactPointPair(const hkpCdBody* a, const hkpCdBody* b) : m_pBodyA(a), m_pBodyB(b) {}
};
struct hkpCdPointCollector {
    virtual void v00();
    virtual void AddCdPoint(const ContactPointPair& point);
};
struct CollisionScratch { hkTransform transform; ContactPointPair contact; };
struct hkpCdBodyPairCollector {
    virtual void v00();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};
void __cdecl FUN_00d317d0(int a1, int a2, int a3, void* a4);

// @fnv 0x00d319e0
void __cdecl FUN_00d319e0(int a, int b, int c, D323B0CollectorBase* collector)
{
    const hkpCdBody* bodyA = (const hkpCdBody*)a;
    const hkpCdBody* bodyB = (const hkpCdBody*)b;
    const CollisionAgentContext* input = (const CollisionAgentContext*)c;

    StringCursor::GetMonitorStream().timerBegin(DAT_010cea38, DAT_010cea7c);

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    CollisionScratch scratch;
    scratch.transform.FUN_00cb22f0(bodyB->m_pMotionState, bodyA->m_pMotionState);

    int count = ((hkpShape*)shapeA)->getNumCollisionSpheres();

    BSAudio* q = FUN_00c85750();
    char* cur1 = (char*)q->unk00;
    hkSphere* sphereBuffer = (hkSphere*)cur1;
    q->unk00 = (int)(cur1 + ((count * 16 + 127) & ~127));

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea6c);

    const hkSphere* spheres = ((hkpShape*)shapeA)->getCollisionSpheres(sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea60);

    transformSpheres(scratch.transform, spheres, count, sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea54);

    const CollisionAgentContext* __restrict in = input;
    BSAudio* bs2 = FUN_00c85750();
    char* cur2 = (char*)bs2->unk00;
    hkSphere* hitResults = (hkSphere*)cur2;
    {
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        bs2->unk00 = (int)(cur2 + ((count * 16 + 127) & ~127));
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        shapeB->CollideSpheres(shB, hitResults);
    }

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea48);

    float tolerance = in->m_fScalar;
    const hkSphere* __restrict hitPtr = hitResults;
    const hkSphere* __restrict spherePtr = sphereBuffer;
    for (int i = count - 1; i >= 0; ++hitPtr, ++spherePtr, --i) {
        const hkSphere& __restrict hit = *hitPtr;
        if (hit.w <= tolerance) {
            ContactPointPair& point = scratch.contact;
            point.m_pBodyA = bodyA;
            point.m_pBodyB = bodyB;
            float distToPoint = -spherePtr->w - hit.w;

            hkVector4 posInB;
            N::__m128 dist4 = N::_mm_load_ss(&distToPoint);
            dist4 = N::_mm_shuffle_ps(dist4,dist4,0);
            posInB.m_vComponents = N::_mm_add_ps(N::_mm_mul_ps(dist4, hit.m_vComponents), spherePtr->m_vComponents);

            point.m_kPoint.m_vContactPosition.SetTransformedPoint(bodyB->m_pMotionState->m_kMotionTransform, posInB);
            point.m_kPoint.m_vSeparatingNormal.SetRotatedDirection(bodyB->m_pMotionState->m_kMotionTransform, hit);
            point.m_kPoint.m_vSeparatingNormal.w = hit.w;

            ((hkpCdPointCollector*)collector)->AddCdPoint(point);
        }
    }

    FUN_00c85750()->unk00 = (int)hitResults;
    FUN_00c85750()->unk00 = (int)sphereBuffer;

    StringCursor::GetMonitorStream().timerEnd(DAT_01076f38);
}

struct Scale {
    N::__m128 value;
    Scale(float f) { value = N::_mm_load_ss(&f); }
    __forceinline N::__m128 repeated() const { return N::_mm_shuffle_ps(value,value,0); }
};
static __forceinline void S_combine(hkVector4& out, const hkVector4& start, const hkVector4& direction, const Scale& amount) {
    out.m_vComponents = N::_mm_add_ps(start.m_vComponents, N::_mm_mul_ps(amount.repeated(), direction.m_vComponents));
}
static __forceinline void S_accumulate(hkVector4& out, const Scale& amount, const hkVector4& direction) {
    out.m_vComponents = N::_mm_add_ps(out.m_vComponents, N::_mm_mul_ps(amount.repeated(), direction.m_vComponents));
}
static __forceinline void S_rotate(hkVector4& out, const hkTransform& matrix, const hkVector4& input) {
    N::__m128 first = N::_mm_mul_ps(matrix.m_kColumn0.m_vComponents, N::_mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0));
    N::__m128 second = N::_mm_mul_ps(matrix.m_kColumn1.m_vComponents, N::_mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0x55));
    N::__m128 third = N::_mm_mul_ps(matrix.m_kColumn2.m_vComponents, N::_mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0xaa));
    out.m_vComponents = N::_mm_add_ps(N::_mm_add_ps(first, second), third);
}

struct S_00d32270_In;
struct S_00d32270_Target
{
    virtual void v00();
    virtual void v04(struct S_00d32270_In* in);
    float m_04;
};

struct S_00d32270_Q
{
    int unk00;
    int unk04;
    hkTransform* m_08;
};

struct S_00d32270_P
{
    hkVector4 v00;
    float f10;
};

struct S_00d32270_cls
{
    int unk00;
    float m_04;
    int unk08;
    int unk0c;
    hkVector4 m_10;
    float m_20;
    int unk24;
    int unk28;
    int unk2c;
    hkVector4 m_30;
    int m_40;
    S_00d32270_Target* m_44;
    void addRayHit(S_00d32270_Q* q, S_00d32270_P* p);
};

struct S_00d32270_In
{
    hkVector4 a;
    hkVector4 b;
    int m40;
    S_00d32270_Q* q;
    S_00d32270_In(int a, S_00d32270_Q* b) : m40(a), q(b) {}
};

static __forceinline float S_min(float a, float b) { return (b < a) ? b : a; }

// @fnv 0x00d32270
void S_00d32270_cls::addRayHit(S_00d32270_Q* q, S_00d32270_P* p)
{
    __declspec(align(16)) S_00d32270_In in(m_40, q);
    float s = -m_20;
    float t = p->f10;
    S_combine(in.a, m_10, m_30, Scale(p->f10));
    S_rotate(in.b, *q->m_08, p->v00);
    S_accumulate(in.a, Scale(s), in.b);
    in.b.w = t;
    m_44->v04(&in);
    float o = m_44->m_04;
    m_04 = S_min(m_04, o);
}

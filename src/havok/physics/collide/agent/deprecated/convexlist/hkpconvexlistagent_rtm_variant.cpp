// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00da3510(void*, void*);
struct hkpConvexListAgent
{
    void __thiscall RemovePoint(int a);
    void __thiscall FUN_00d33770(int a);
};
extern "C" void __cdecl FUN_00d339d0(int, int, int, int);
struct FUN_00d33b70_cls
{
    void __thiscall FUN_00d33b70(int a, int b, int c, int d);
};
extern "C"
{
    void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d);
}
struct FUN_00d33c80_class
{
    void __thiscall FUN_00d33c80(void* a, void* b, void* c, void* d);
};
struct hkpCollisionDispatcher
{
    struct CollisionAgentFunctionTable
    {
        void* pfnA;
        void* pfnB;
        void* pfnC;
        void* pfnD;
        char b1;
        char b2;
    };
    void __thiscall FUN_00cfbbe0(CollisionAgentFunctionTable* a, int b, int c);
};
extern void* __cdecl CreateConvexListAgent();
extern void* __cdecl InitSpawnedBuffer();
extern void* __cdecl FUN_00d34970();
extern void* __cdecl FUN_00d349b0();
extern void* __cdecl FUN_00d343f0();
extern void* __cdecl _FUN_00d33b90();
extern void* __cdecl _FUN_00d339d0();
extern void* __cdecl FUN_00d33ca0();
extern void* __cdecl FUN_00d34510();
void __cdecl RegisterConvexListAgentCollisionFuncs(hkpConvexListAgent* self);
struct FUN_00d337f0_self
{
    void __thiscall removePoint(int a);
    void __thiscall FUN_00d337f0(int a);
};
struct hkpGskfAgent
{
    void __thiscall AddPotential(int a);
};
struct FUN_00d33810_cls : hkpGskfAgent
{
    void __thiscall FUN_00d33810(int a);
};
extern void __cdecl FUN_00d97250(void*, void*, void*);
struct FUN_00d33740_cls
{
    void __thiscall FUN_00d33740(int a, int b);
};
void __cdecl FUN_00da42b0(void*, int, int, int);
struct FUN_00d33850_cls
{
    void __thiscall FUN_00d33850(int a);
};
void* __stdcall FUN_00d33da0(void* a, void* b, void* c, void* d, void* e);
struct hkpSimpleClosestContactCollector
{
    void Reset();
};
struct D338e0Agent
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};
inline void D338e0Agent::vf00()
{}
inline void D338e0Agent::vf04()
{}
inline void D338e0Agent::vf08()
{}
inline void D338e0Agent::vf0C()
{}
inline int D338e0Agent::vf10()
{
    return 0;
}
struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};
struct D338e0Owner
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
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    unsigned char unk84;

    void __thiscall FUN_00d338e0(int param1, int param2, int param3, int param4);
};
extern "C" void __cdecl FUN_00da48e0(int*, D338e0Local*);
inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    FUN_00da48e0(ownerField, local);
}
struct hkAllocatorD33D
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterD33D
{
    void* m_apvUnk00[4];
    hkAllocatorD33D* m_pkHeap;
    hkAllocatorD33D& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD33D* __cdecl FUN_00c85750() throw();
struct hkpCdBodyD33D;
struct hkpContactMgrD33D;
struct hkpCollisionInputD33D;
class hkpConvexListFilterD33D
{
  public:
    virtual ~hkpConvexListFilterD33D() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                    const hkpCollisionInputD33D& kInput) const throw();
};
struct hkpCollisionInputD33D
{
    int m_aiUnk00[4];
    hkpConvexListFilterD33D* m_pConvexListCollisionFilter;
};
class hkpCollisionAgentD33D
{
  public:
    virtual ~hkpCollisionAgentD33D() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpCollisionAgentD33D* p = (hkpCollisionAgentD33D*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
};
class FUN_00d33940 : public hkpCollisionAgentD33D
{
  public:
    FUN_00d33940(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, const hkpCollisionInputD33D& kInput,
                 hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x88];
};
class hkpSymmetricConvexListAgentD33D : public FUN_00d33940
{
  public:
    __forceinline hkpSymmetricConvexListAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                  const hkpCollisionInputD33D& kInput, hkpContactMgrD33D* pkMgr) throw()
        : FUN_00d33940(kBodyB, kBodyA, kInput, pkMgr)
    {}
    virtual ~hkpSymmetricConvexListAgentD33D() throw();
};
class FUN_00d440f0 : public hkpCollisionAgentD33D
{
  public:
    FUN_00d440f0(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, const hkpCollisionInputD33D& kInput,
                 hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x30];
};
class FUN_00dacbd0 : public hkpCollisionAgentD33D
{
  public:
    FUN_00dacbd0(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x78];
};
class hkpPredGskfAgentD33D : public FUN_00dacbd0
{
  public:
    __forceinline hkpPredGskfAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                       hkpContactMgrD33D* pkMgr) throw()
        : FUN_00dacbd0(kBodyA, kBodyB, pkMgr)
    {}
    virtual ~hkpPredGskfAgentD33D() throw();
};
hkpCollisionAgentD33D* __cdecl CreateConvexListAgent(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                     const hkpCollisionInputD33D& kInput,
                                                     hkpContactMgrD33D* pkMgr) throw();
void __cdecl ReleaseAllEntries(void* out, void* src, void* arg);
void InitBlockPool(void* p);
struct hkArrayD33E
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD33E() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};
struct hkObjD33E
{
    int unk00;
    int unk04;
    void* m_pObservedSource;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkArrayD33E m_ppData;
    float m_3c;
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
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    char m_84;
    char unk85;
    short m_86;

    void FUN_00d33ef0(void* arg);
};
class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};
class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(int filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    int m_iFilter;
};
extern "C" void __cdecl FUN_00d43dc0(void* a, void* b, void* c, hkCollectorBaseD347& collector);
void __cdecl FUN_00d34790(void* b, void* a, void* c, int filter);
extern "C" void __cdecl FUN_00d34810();
// @fnv 0x00d36930
extern "C" void __cdecl FUN_00d36930()
{
    FUN_00d34810();
}
struct hkMemberD337
{
    int unk00;
};
void __cdecl FUN_00da35f0(hkMemberD337* member, float a, float b, int c);
class hkObjD337
{
  public:
    int unk00[12];
    hkMemberD337 m_30;
    int unk34[20];
    bool m_84;

    void SetValueIfExpected(float a, float b, int c);
    void SetValue(float a, float b, int c);
};
// @fnv 0x00d33890
extern void __cdecl ReleaseAllEntries(void*, int, void*);
struct ContactAgent
{
    virtual void Invalidate(int);
    int unk04, collidable08;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int contact30;
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
    int state80;
    unsigned char flag84;
    void FUN_00d33890(void*);
};
void ContactAgent::FUN_00d33890(void* input)
{
    if (flag84)
    {
        ReleaseAllEntries(&contact30, collidable08, input);
    }
    else
    {
        FUN_00da42b0(&contact30, state80, collidable08, (int)input);
    }
    Invalidate(1);
}
extern float DAT_01012054;
extern char DAT_010cebf0[];
struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
    void FUN_00cb22f0(int a, int b);
};
struct S00d33940_Sub
{
    void FUN_00dafcd0(int a, int b, S00d33940_Out* c);
};
struct S00d33940_Base
{
    int vt;
    void FUN_00dacbd0(int* a, int* b, void* d);
};
struct S00d33940_Obj : S00d33940_Base
{
    int unk04;
    int unk08;
    S00d33940_Sub unk0c;
    char unk0d;
    char unk0e;
    char unk0f;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    float unk2c;
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
    unsigned char unk84;
    unsigned char unk85;
    S00d33940_Obj* FUN_00d33940(int* a, int* b, int* c, void* d);
};
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;
struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};
struct ProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};
struct HitCollector
{
    void* m_vtbl;
    bool m_bHit;
};
void __cdecl TestGsk(void* a, void* b, void* c, HitCollector* col);
void __cdecl FUN_00d34790(void* a, void* b, void* c, void* d);
// @fnv 0x00d33b90
extern "C" void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d)
{
    volatile DWORD tick;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = "LtCvxList";
        pRec->m_pName2 = "StcheckHull";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = (char*)pRec + 0x10;
    }

    HitCollector col;
    col.m_vtbl = &DAT_010cebd0;
    col.m_bHit = false;
    TestGsk(a, b, c, &col);
    if (col.m_bHit)
    {
        pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
            pRec->m_pName = "Stchildren";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_iTick = tick;
            pBuf->m_pCur = (char*)pRec + 0xc;
        }
        FUN_00d34790(a, b, c, d);
    }

    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = "lt";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = (char*)pRec + 0xc;
    }
}
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010cec28[];
extern const char str_01076f38[];
extern int DAT_010c476c;
extern float DAT_0104da48;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" int __cdecl TestGsk(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl FUN_00dac450(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl QueryClosestPoints(const void* a, const void* b, const void* c, void* d);
struct StringCursor
{
    int unk00;
    char* m_commandPointer;
    int unk08;
    char* m_endCommandPointer;
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& other)
    {
        m_vComponents = other.m_vComponents;
        return *this;
    }
};
struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float getDistance() const
    {
        return m_vSeparatingNormal.m_vComponents.m128_f32[3];
    }
    hkContactPoint& operator=(const hkContactPoint& other)
    {
        m_vContactPosition = other.m_vContactPosition;
        m_vSeparatingNormal = other.m_vSeparatingNormal;
        return *this;
    }
};
struct RootContactPoint
{
    hkContactPoint m_kPoint;
    const void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
};
struct hkpFlagCdBodyPairCollector
{
    const void* vtbl;
    bool m_flag;
    hkpFlagCdBodyPairCollector() : vtbl(&DAT_010cebd0), m_flag(false)
    {}
    bool DidHit() const
    {
        return m_flag;
    }
};
struct hkpClosestCdPointCollector
{
    const void* vtbl;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    RootContactPoint m_kHitPoint;
    RootContactPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollector()
    {
        m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents.m128_f32[3] = DAT_0104da48;
        m_fEarlyOutDistance = DAT_0104da48;
        vtbl = &DAT_010c476c;
        m_kHitPoint.m_pRootCollidableA = 0;
    }

    bool DidHit() const
    {
        return m_kHitPoint.m_pRootCollidableA != 0;
    }
};
struct hkpCdBody
{
    const void* m_pCollisionShape;
};
struct hkpConvexListShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_minDistanceToUseConvexHull;
};
struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const void* m_pBodyA;
    const void* m_pBodyB;
};
struct hkpCdPointCollector
{
    virtual void unk00() = 0;
    virtual void AddCdPoint(const ContactPointPair& point) = 0;
};
// @fnv 0x00d339d0
extern "C" void __cdecl FUN_00d339d0(int a1, int a2, int a3, int a4)
{
    {
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = "LtCvxList";
            *(const char**)(p + 12) = "StcheckHull";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 16;
        }
    }

    hkpFlagCdBodyPairCollector flagCollector;
    TestGsk((const void*)a1, (const void*)a2, (const void*)a3, &flagCollector);
    if (flagCollector.DidHit())
    {
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = "Stchildren";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            // Keep this timer read separate from the child-path timer read.
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 12;
        }
        QueryClosestPoints((const void*)a1, (const void*)a2, (const void*)a3, (hkpCdPointCollector*)a4);
    }
    else
    {
        hkpClosestCdPointCollector x;
        FUN_00dac450((const void*)a1, (const void*)a2, (const void*)a3, &x);
        if (!x.DidHit())
        {
            goto timer_end;
        }
        const hkpConvexListShape* shapeB = (const hkpConvexListShape*)((const hkpCdBody*)a2)->m_pCollisionShape;
        if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
        {
            ContactPointPair point;
            point.m_pBodyA = (const void*)a1;
            point.m_pBodyB = (const void*)a2;
            point.m_kPoint = x.m_kHitPoint.m_kPoint;
            ((hkpCdPointCollector*)a4)->AddCdPoint(point);
            goto timer_end;
        }
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = str_010cec28;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 12;
        }
        QueryClosestPoints((const void*)a1, (const void*)a2, (const void*)a3, (hkpCdPointCollector*)a4);
    }

timer_end: {
    StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* p = pForm->m_commandPointer;
    if (p < pForm->m_endCommandPointer)
    {
        *(const char**)p = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        pForm->m_commandPointer = p + 12;
    }
}
}

struct ProfileIndex
{
    unsigned long value;
    __forceinline ProfileIndex(unsigned long v) : value(v)
    {}
};
static __forceinline void* profileBuffer(const ProfileIndex& index)
{
    return TlsGetValue(index.value);
}
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sqrt_ss(__m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_load_ss(const float*);
}
static __forceinline __m128 Splat(const float& f)
{
    __m128 r = _mm_load_ss(&f);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float ParseFloatValue(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}

extern void* DAT_010ceb44;
extern const char str_010ceb84[], str_010ceb7c[], str_010ceb70[], str_010ceca0[], str_01076f38[];

union Vec4
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };
};
struct L16
{
    Vec4 v;
};
struct L64
{
    L16 a, b, c, d;
};
struct L256
{
    L64 a, b, c, d;
};
struct L1024
{
    L256 a, b, c, d;
};
struct L4096
{
    L1024 a, b, c, d;
};
struct L128
{
    L64 a, b;
};
struct Arg4;
struct Shape;  // Collision-output snapshot: 0x1080 bytes consumed by the snapshot/reset methods.
struct Workspace
{
    L4096 contacts;
    L128 state;
    void __thiscall FUN_00d33670(Arg4&);
    void __thiscall FUN_00d33600(const Shape&, const Shape&, Arg4&, void*);
};

struct Obj
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
    Vec4 m_40;
    Vec4 m_50;
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
    float m_9c;
    float m_a0;
};
struct ShapeHead
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
    int count;
};
struct Shape
{
    ShapeHead* m_00;
    int unkp04;
    Obj* m_08;
    Shape* m_0c;
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
    float m_4c;
};
struct Arg3
{
    int unk00;
    int unk04;
    float m_08;
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
    float m_58;
};
struct Arg4
{
    int unkp00;
    void* m_04;
};
struct CollObj
{
    Vec4 a, b, c, d;
    void __thiscall FUN_00cb22f0(Obj*, Obj*);
};
struct SStruct
{
    void* pCo;
    void* pObjA;
    void* a0;
    void* b0;
    float f;
};
struct StackObj
{
    void* vptr;
    short unkp04;
    short m_06s;
    int kind;
    void* saved;
    char flag;
    char unkp19a;
    short unkp20;
};
struct Big
{
    const Shape* a;
    const Shape* b;
    int zero;
    const Arg3* c;
    void* agent08;
    int unkp14, unk18, unk1c;
    CollObj co;
    int p60, p64, p68, p6c;
    Vec4 vec;
};
struct D33ProfBuf
{
    int unkp00;
    char* cursor;
    int unkp08;
    char* end;
};
struct Rec16
{
    const char* name;
    unsigned int tick;
    void* unk;
    const char* name2;
};
struct Rec12
{
    const char* name;
    unsigned int tick;
    void* unk;
};

void FUN_00d33670(void* a);
void FUN_00d33600(void* a, void* b, void* c, void* d);
void* FUN_00cb22f0(void* a, void* b);
int FUN_00dabca0(SStruct* a, void* b, void* c, void* d);
void FUN_00d33850(void* a);
void FUN_00d33ef0(void* a);
void FUN_00d42020(void* a, void* b, void* c, void* d);
struct AddressValue
{
    void* value;
    __forceinline AddressValue(void* p) : value(p)
    {}
};
void FUN_00da4aa0(void* a, const void* b, AddressValue wrapped, void* d, void* e);
void ReleaseAllEntries(void* a, void* b, void* c);
struct ScratchArena
{
    int* cursor;
};

typedef void(__thiscall* Ws70Fn)(void*, const void*);
typedef void(__thiscall* Ws00Fn)(void*, const void*, const void*, const void*, void*);
typedef void*(__thiscall* CbFn)(void*, void*, void*);
typedef void(__thiscall* Ag1Fn)(void*, void*);
typedef void(__thiscall* Ag4Fn)(void*, const void*, const void*, const void*, void*);

struct StreamState
{
    short flags;
    char count;
    char unknown;
    int field04, field08;
    float distance;
};
struct ScalarScratch;
struct Agent
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_20w;
    short unkp30;
    char m_32;
    char unkp33;
    int unk34;
    int unk38;
    float m_3c;
    __forceinline StreamState& streaming()
    {
        return *reinterpret_cast<StreamState*>(&unkp30);
    }
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
    char m_84;
    char m_85;
    short m_86;
    void __thiscall FUN_00d33850(void*);
    void __thiscall FUN_00d33ef0(void*);
    void __thiscall FUN_00d42020(const Shape&, const Shape&, const Arg3&, Arg4&);
    __forceinline void processCached(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, Workspace&, StackObj&,
                                     ScalarScratch&, bool&);
    void streamCollision(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, ShapeHead*);
    void __thiscall FUN_00d33f40(const Shape& a, const Shape& b, const Arg3& c, Arg4& d);
};

__forceinline void projectDistance(Vec4& normal, const Vec4& vec)
{
    __m128 p = _mm_mul_ps(normal.quad, vec.quad);
    __m128 v = vec.quad;
    __m128 s3 = _mm_shuffle_ps(v, v, 0xff);
    __m128 s2 = _mm_shuffle_ps(p, p, 0xaa);
    __m128 s1 = _mm_shuffle_ps(p, p, 0x55);
    __m128 rr = _mm_add_ps(_mm_add_ss(s2, s3), _mm_add_ss(s1, p));
    float dot;
    _mm_store_ss(&dot, rr);
    normal.w -= dot;
}
// Keep the two rounded scale values together for x87 and SIMD consumers.
struct MotionScales
{
    float a, b;
};
struct ScalarScratch
{
    union
    {
        float dt;
        D33ProfBuf* volatile monitor;
        float minimum;
    } first;
    union
    {
        float factor;
        volatile unsigned stamp;
    } a;
    float radius;
    union
    {
        float factor;
        volatile unsigned stamp;
    } b;
    union
    {
        ShapeHead* shape;
        volatile unsigned stamp;
    } last;
};
__forceinline void calculateMotion(const Obj& oa, const Obj& ob, ScalarScratch& scratch, Vec4& vec)
{
    scratch.a.factor = scratch.first.dt * oa.m_50.w;
    scratch.b.factor = scratch.first.dt * ob.m_50.w;
    __m128 scaleA = Splat(scratch.a.factor);
    __m128 scaleB = Splat(scratch.b.factor);
    __m128 vc = ob.m_40.quad;
    __m128 vd = ob.m_50.quad;
    __m128 va = oa.m_40.quad;
    __m128 vb = oa.m_50.quad;
    vec.quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vd, vc), scaleB), _mm_mul_ps(_mm_sub_ps(va, vb), scaleA));
    vec.w = oa.m_9c * scratch.a.factor * oa.m_a0 + ob.m_9c * scratch.b.factor * ob.m_a0;
}

__forceinline void Agent::streamCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                          ShapeHead* bHead)
{
    Big big;
    big.zero = 0;
    big.a = &a;
    big.b = &b;
    big.agent08 = m_08;
    __m128 motion = vec.quad;
    big.c = &c;
    big.vec.quad = motion;
    big.co.FUN_00cb22f0(a.m_08, b.m_08);
    int count = bHead->count;
    ScratchArena* pool = (ScratchArena*)FUN_00c85750();
    int* arr = pool->cursor;
    pool->cursor = (int*)((unsigned int)arr + (((unsigned int)(count * 4 + 4) + 0x7f) & ~0x7f));
    for (int i = 0; i < count; i++)
        arr[i] = i;
    arr[count] = -1;
    FUN_00da4aa0(&streaming(), &big, AddressValue(&bHead->unk14), arr, &d);
    ScratchArena* pool2 = (ScratchArena*)FUN_00c85750();
    pool2->cursor = arr;
}
__forceinline void Agent::processCached(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                        Workspace& ws, StackObj& so, ScalarScratch& scratch, bool& retry)
{
    if (m_20w.w > c.m_08)
    {
        projectDistance(m_20w, vec);
        if (m_20w.w > c.m_08)
        {
            if (m_32 != 0)
                ReleaseAllEntries(&unkp30, m_08, d.m_04);
            return;
        }
    }
    {
        D33ProfBuf* pBuf;
        pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c);
        scratch.first.monitor = pBuf;
        Rec12* pRec = (Rec12*)pBuf->cursor;
        if (pRec < (Rec12*)pBuf->end)
        {
            pRec->name = str_010ceca0;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.a.stamp;
            scratch.first.monitor->cursor = (char*)(pRec + 1);
        }
        so.kind = 2;
        so.m_06s = 1;
        so.vptr = &DAT_010ceb44;
        so.flag = 0;
        so.saved = m_08;
        m_08 = &so;
        FUN_00d42020(a, b, c, d);
        m_08 = so.saved;
        if (so.flag == 0)
        {
            if (m_32 == 0)
                return;
            if (m_85 != 0)
                return;
            const Shape* pa = &b;
            while (pa->m_0c)
                pa = pa->m_0c;
            scratch.radius = pa->m_4c;
            const Shape* pb = &a;
            while (pb->m_0c)
                pb = pb->m_0c;
            scratch.first.minimum = pb->m_4c;
            double cachedDistance;
            if (scratch.first.minimum < scratch.radius)
            {
                scratch.first.minimum = (const float&)(scratch.first.minimum * 1.0f);
                cachedDistance = m_20w.w;
            }
            else
            {
                scratch.first.minimum = scratch.radius;
                cachedDistance = m_20w.w;
            }
            scratch.radius = 2.0f * scratch.first.minimum;
            if (!(cachedDistance < -scratch.radius))
                return;
        }
        ws.FUN_00d33600(a, b, d, m_08);
        FUN_00d33ef0(d.m_04);
        retry = true;
        return;
    }
}
// @fnv 0x00d33f40
void __thiscall Agent::FUN_00d33f40(const Shape& a, const Shape& b, const Arg3& c, Arg4& d)
{
    Workspace ws;
    Vec4 vec;

    ScalarScratch scratch;
    CollObj co;
    union
    {
        SStruct query;
        StackObj manager;
    } temp;

    {
        D33ProfBuf* pBuf;
        Rec16* pRec = (Rec16*)(pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c))->cursor;
        if (pRec < (Rec16*)pBuf->end)
        {
            pRec->name = str_010ceb84;
            pRec->name2 = str_010ceb7c;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.a.stamp;
            pBuf->cursor = (char*)(pRec + 1);
        }
    }
    scratch.last.shape = b.m_00;
    scratch.first.dt = c.m_58;
    calculateMotion(*a.m_08, *b.m_08, scratch, vec);
    ws.FUN_00d33670(d);
    if (m_84 != 0)
        goto project;
stream: {
    D33ProfBuf* pBuf;
    pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c);
    scratch.first.monitor = pBuf;
    Rec12* pRec = (Rec12*)pBuf->cursor;
    if (pRec < (Rec12*)pBuf->end)
    {
        pRec->name = str_010ceb70;
        _ReadWriteBarrier();
        scratch.b.stamp = (unsigned int)__rdtsc();
        pRec->tick = scratch.b.stamp;
        scratch.first.monitor->cursor = (char*)(pRec + 1);
    }
    short oc = m_86;
    m_86 = (short)(oc - 1);
    if (oc >= 0)
        goto sqrtpath;
    m_86 = 0x19;
    {
        co.FUN_00cb22f0(a.m_08, b.m_08);
        SStruct& s = temp.query;
        Vec4 objD;
        s.a0 = a.m_00;
        s.b0 = b.m_00;
        s.pCo = &co;
        s.pObjA = a.m_08;
        s.f = c.m_08;
        int res = FUN_00dabca0(&s, &m_0c, &m_20w, &objD);
        if (res == 0)
        {
            streaming().distance = -m_20w.w;
            goto sqrtpath;
        }
        FUN_00d33850(d.m_04);
        ws.FUN_00d33600(a, b, d, m_08);
    }
}
// Update cached separation before choosing GSK or cached-contact export.
project: {
    bool retry = false;
    processCached(a, b, c, d, vec, ws, temp.manager, scratch, retry);
    if (retry)
        goto stream;
    goto tail;
}
// Streaming path: reduce cached distance by motion length, then visit all shape keys.
sqrtpath: {
    __m128 vv = vec.quad;
    __m128 sq = _mm_mul_ps(vv, vv);
    __m128 sh1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 s1 = _mm_add_ss(sh1, sq);
    __m128 sh2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s2 = _mm_add_ss(sh2, s1);
    __m128 len = _mm_sqrt_ss(s2);
    _mm_store_ss(&scratch.radius, len);
    streaming().distance -= scratch.radius;
    streamCollision(a, b, c, d, vec, scratch.last.shape);
}
tail:
    m_85 = 1;
    {
        D33ProfBuf* pBuf;
        unsigned long index = DAT_0126835c;
        Rec12* pRec = (Rec12*)(pBuf = (D33ProfBuf*)profileBuffer(ProfileIndex(index)))->cursor;
        if (pRec < (Rec12*)pBuf->end)
        {
            pRec->name = str_01076f38;
            _ReadWriteBarrier();
            scratch.last.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.last.stamp;
            pBuf->cursor = (char*)(pRec + 1);
        }
    }
}


// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00da3510(void*, void*);

struct hkpConvexListAgent
{
    void __thiscall RemovePoint(int a);
    void __thiscall FUN_00d33770(int a);
};

// @fnv 0x00d33770
void __thiscall hkpConvexListAgent::FUN_00d33770(int a)
{
    if (*(char*)((char*)this + 0x84))
        RemovePoint(a);
    else
        FUN_00da3510(this + 0x30, (void*)a);
}

extern "C" void __cdecl FUN_00d339d0(int, int, int, int);

struct FUN_00d33b70_cls
{
    void __thiscall FUN_00d33b70(int a, int b, int c, int d);
};

// @fnv 0x00d33b70
void __thiscall FUN_00d33b70_cls::FUN_00d33b70(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00d339d0(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C"
{
    void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d);
}

struct FUN_00d33c80_class
{
    void __thiscall FUN_00d33c80(void* a, void* b, void* c, void* d);
};

// @fnv 0x00d33c80
void __thiscall FUN_00d33c80_class::FUN_00d33c80(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d33b90(apArg1, apArg2, apArg3, apArg4);
}

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
// Fills a collision-function table three times and registers it with the dispatcher for the 0x16/0x12, 0x12/0x16 and 0x16/0x16 type pairs.
// @fnv 0x00d346b0
void __cdecl RegisterConvexListAgentCollisionFuncs(hkpConvexListAgent* self)
{
    hkpCollisionDispatcher::CollisionAgentFunctionTable funcTable;
    funcTable.pfnA = (void*)CreateConvexListAgent;
    funcTable.pfnB = (void*)InitSpawnedBuffer;
    funcTable.pfnC = (void*)FUN_00d34970;
    funcTable.pfnD = (void*)FUN_00d349b0;
    funcTable.b1 = 1;
    funcTable.b2 = 1;
    ((hkpCollisionDispatcher*)self)->FUN_00cfbbe0(&funcTable, 0x16, 0x12);
    funcTable.pfnA = (void*)FUN_00d343f0;
    funcTable.pfnB = (void*)_FUN_00d33b90;
    funcTable.pfnC = (void*)_FUN_00d339d0;
    funcTable.pfnD = (void*)FUN_00d33ca0;
    funcTable.b1 = 0;
    funcTable.b2 = 1;
    ((hkpCollisionDispatcher*)self)->FUN_00cfbbe0(&funcTable, 0x12, 0x16);
    funcTable.pfnA = (void*)FUN_00d34510;
    funcTable.pfnB = (void*)_FUN_00d33b90;
    funcTable.pfnC = (void*)_FUN_00d339d0;
    funcTable.pfnD = (void*)FUN_00d33ca0;
    funcTable.b1 = 0;
    funcTable.b2 = 1;
    ((hkpCollisionDispatcher*)self)->FUN_00cfbbe0(&funcTable, 0x16, 0x16);
}

struct FUN_00d337f0_self
{
    void __thiscall removePoint(int a);
    void __thiscall FUN_00d337f0(int a);
};

// @fnv 0x00d337f0
void __thiscall FUN_00d337f0_self::FUN_00d337f0(int a)
{
    if (*(char*)((char*)this + 0x84))
        removePoint(a);
}

struct hkpGskfAgent
{
    void __thiscall AddPotential(int a);
};

struct FUN_00d33810_cls : hkpGskfAgent
{
    void __thiscall FUN_00d33810(int a);
};

// @fnv 0x00d33810
void FUN_00d33810_cls::FUN_00d33810(int a)
{
    if (*(char*)((char*)this + 0x84))
        hkpGskfAgent::AddPotential(a);
}

namespace fnv_00d33830 {
struct FUN_00d33830_cls
{
    void __thiscall FUN_00d33830(int a);
};

struct hkpGskfAgent
{
    void __thiscall ClearSlotById(int a);
};

// @fnv 0x00d33830
void __thiscall FUN_00d33830_cls::FUN_00d33830(int aiArg)
{
    if (*(char*)((char*)this + 0x84))
        ((hkpGskfAgent*)this)->ClearSlotById(aiArg);
}
}  // namespace fnv_00d33830

extern void __cdecl FUN_00d97250(void*, void*, void*);

struct FUN_00d33740_cls
{
    void __thiscall FUN_00d33740(int a, int b);
};

// If the byte at offset 0x84 is zero, calls FUN_00d97250 with this+0x30, the pointer at a+8 and a.
// @fnv 0x00d33740
void FUN_00d33740_cls::FUN_00d33740(int a, int iUnused)
{
    if (*(char*)((char*)this + 0x84) == 0)
    {
        FUN_00d97250((char*)this + 0x30, *(void**)(a + 8), (void*)a);
    }
}

void __cdecl FUN_00da42b0(void*, int, int, int);
struct FUN_00d33850_cls
{
    void __thiscall FUN_00d33850(int a);
};
// Calls FUN_00da42b0 with fields at offsets 0x30, 0x80 and 8 plus a, then clears the field at 0x30 and sets the byte at 0x84 to 1.
// @fnv 0x00d33850
void __thiscall FUN_00d33850_cls::FUN_00d33850(int a)
{
    FUN_00da42b0(this + 0x30, *(int*)(this + 0x80), *(int*)(this + 8), a);
    *(int*)(this + 0x30) = 0;
    *(char*)(this + 0x84) = 1;
}

// Forwards all five arguments to FUN_00d33ca0 and returns its result.
// @fnv 0x00d33da0
void* __stdcall FUN_00d33da0(void* a, void* b, void* c, void* d, void* e)
{
    return ((void*(__cdecl*)(void*, void*, void*, void*, void*))FUN_00d33ca0)(a, b, c, d, e);
}

struct hkpSimpleClosestContactCollector
{
    void Reset();
};

// @fnv 0x00d34770
void hkpSimpleClosestContactCollector::Reset()
{
    float max = 3.402820018375656e+38f;
    *(char*)((char*)this + 8) = 0;
    *(float*)((char*)this + 0x2c) = max;
    *(float*)((char*)this + 4) = max;
}

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

// If unk84 is zero, fills a D338e0Local from the parameters and unk08, calls vf10 on the agent at param2, and dispatches the result with unk30.
// @fnv 0x00d338e0
void __thiscall D338e0Owner::FUN_00d338e0(int aiArg1, int apAgentPtr, int aiArg3, int aiArg4)
{
    if (unk84 == 0)
    {
        D338e0Local local;
        local.field00 = aiArg1;
        local.field04 = apAgentPtr;
        local.field10 = aiArg3;
        local.field14 = unk08;
        local.field18 = aiArg4;

        D338e0Agent** ppAgent = reinterpret_cast<D338e0Agent**>(apAgentPtr);
        int result = (*ppAgent)->vf10();

        D338e0Dispatch(&local, &unk30, result);
    }
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

// Creates a collision agent for the two bodies: picks the agent class from the convex list filter's result, or a default agent when pkMgr is null.
// @fnv 0x00d33dd0
hkpCollisionAgentD33D* __cdecl CreateConvexListAgent(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                     const hkpCollisionInputD33D& kInput,
                                                     hkpContactMgrD33D* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyA, kBodyB, kInput))
        {
        case 0:
            return new hkpSymmetricConvexListAgentD33D(kBodyA, kBodyB, kInput, pkMgr);
        case 1:
            return new FUN_00d440f0(kBodyA, kBodyB, kInput, pkMgr);
        case 2:
            return new hkpPredGskfAgentD33D(kBodyA, kBodyB, pkMgr);
        }
        return 0;
    }
    return new FUN_00d440f0(kBodyA, kBodyB, kInput, 0);
}

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

// Reinitializes the embedded array, clears m_84 and m_3c, and sets m_86 to 0x19.
// @fnv 0x00d33ef0
void hkObjD33E::FUN_00d33ef0(void* arg)
{
    ReleaseAllEntries(&m_ppData, m_pObservedSource, arg);
    m_84 = 0;
    new (&m_ppData) hkArrayD33E();
    InitBlockPool(&m_ppData);
    m_3c = 0.0f;
    m_86 = 0x19;
}

namespace fnv_00d343f0 {
struct hkAllocatorD343
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterD343
{
    void* m_apvUnk00[4];
    hkAllocatorD343* m_pkHeap;
    hkAllocatorD343& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD343* __cdecl FUN_00c85750() throw();

struct hkpCdBodyD343;
struct hkpContactMgrD343;
struct hkpCollisionInputD343;

class hkpConvexListFilterD343
{
  public:
    virtual ~hkpConvexListFilterD343() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                    const hkpCollisionInputD343& kInput) const throw();
};

struct hkpCollisionInputD343
{
    int m_aiUnk00[4];
    hkpConvexListFilterD343* m_pConvexListCollisionFilter;
};

class hkpCollisionAgentD343
{
  public:
    virtual ~hkpCollisionAgentD343() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpCollisionAgentD343* p = (hkpCollisionAgentD343*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
};

class FUN_00d33940 : public hkpCollisionAgentD343
{
  public:
    FUN_00d33940(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, const hkpCollisionInputD343& kInput,
                 hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x88];
};

class FUN_00d440f0 : public hkpCollisionAgentD343
{
  public:
    FUN_00d440f0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, const hkpCollisionInputD343& kInput,
                 hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x30];
};

class hkpSymmetricAgentD343 : public FUN_00d440f0
{
  public:
    __forceinline hkpSymmetricAgentD343(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                        const hkpCollisionInputD343& kInput, hkpContactMgrD343* pkMgr) throw()
        : FUN_00d440f0(kBodyB, kBodyA, kInput, pkMgr)
    {}
    virtual ~hkpSymmetricAgentD343() throw();
};

class FUN_00dacbd0 : public hkpCollisionAgentD343
{
  public:
    FUN_00dacbd0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x78];
};

class hkpPredGskfAgentD343 : public FUN_00dacbd0
{
  public:
    __forceinline hkpPredGskfAgentD343(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                       hkpContactMgrD343* pkMgr) throw()
        : FUN_00dacbd0(kBodyA, kBodyB, pkMgr)
    {}
    virtual ~hkpPredGskfAgentD343() throw();
};

// @fnv 0x00d343f0
hkpCollisionAgentD343* __cdecl FUN_00d343f0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                            const hkpCollisionInputD343& kInput, hkpContactMgrD343* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyB, kBodyA, kInput))
        {
        case 0:
            return new FUN_00d33940(kBodyA, kBodyB, kInput, pkMgr);
        case 1:
            return new hkpSymmetricAgentD343(kBodyA, kBodyB, kInput, pkMgr);
        case 2:
            return new hkpPredGskfAgentD343(kBodyA, kBodyB, pkMgr);
        }
        return 0;
    }
    return new hkpSymmetricAgentD343(kBodyA, kBodyB, kInput, 0);
}
}  // namespace fnv_00d343f0

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

// Constructs an hkCollectorD347 with the given filter and passes it to FUN_00d43dc0 along with a, b and c.
// @fnv 0x00d34790
void __cdecl FUN_00d34790(void* b, void* a, void* c, int filter)
{
    hkCollectorD347 collector(filter);
    FUN_00d43dc0(a, b, c, collector);
}

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

// Sets a value on the object, calling SetValueIfExpected when m_84 is true, otherwise delegating to FUN_00da35f0 on m_30.
// @fnv 0x00d337a0
void hkObjD337::SetValue(float a, float b, int c)
{
    if (m_84)
        SetValueIfExpected(a, b, c);
    else
        FUN_00da35f0(&m_30, a, b, c);
}

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

// Calls FUN_00dacbd0(a, b, d), sets vt to DAT_010cebf0 and unk80 to *c, sets unk84/85, calls FUN_00dafcd0 on unk0c, and sets unk18 and unk2c to DAT_01012054.
// @fnv 0x00d33940
S00d33940_Obj* S00d33940_Obj::FUN_00d33940(int* a, int* b, int* c, void* d)
{
    FUN_00dacbd0(a, b, d);
    vt = (int)DAT_010cebf0;
    unk80 = *c;
    unk84 = 1;
    unk85 = 0;
    int v1 = a[0];
    int v0 = b[0];
    S00d33940_Out o;
    o.FUN_00cb22f0(a[2], b[2]);
    unk0c.FUN_00dafcd0(v1, v0, &o);
    float* __restrict p2 = &unk2c;
    float* __restrict p1 = &unk18;
    *p1 = *p2 = DAT_01012054;
    return this;
}

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

// Writes timer entries (LtCvxList/StcheckHull, Stchildren, lt), calls TestGsk with a collector, and calls FUN_00d34790 if the collector registered a hit.
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

// If TestGsk reports a hit calls QueryClosestPoints; else adds the closest point to a4 when its distance exceeds b's shape threshold, otherwise calls QueryClosestPoints.
// @fnv 0x00d339d0
extern "C" void __cdecl FUN_00d339d0(int apBodyA, int apBodyB, int a3, int apCollector)
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
    TestGsk((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &flagCollector);
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
        QueryClosestPoints((const void*)apBodyA, (const void*)apBodyB, (const void*)a3,
                           (hkpCdPointCollector*)apCollector);
    }
    else
    {
        hkpClosestCdPointCollector x;
        FUN_00dac450((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &x);
        if (!x.DidHit())
        {
            goto timer_end;
        }
        const hkpConvexListShape* shapeB = (const hkpConvexListShape*)((const hkpCdBody*)apBodyB)->m_pCollisionShape;
        if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
        {
            ContactPointPair point;
            point.m_pBodyA = (const void*)apBodyA;
            point.m_pBodyB = (const void*)apBodyB;
            point.m_kPoint = x.m_kHitPoint.m_kPoint;
            ((hkpCdPointCollector*)apCollector)->AddCdPoint(point);
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
        QueryClosestPoints((const void*)apBodyA, (const void*)apBodyB, (const void*)a3,
                           (hkpCdPointCollector*)apCollector);
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

namespace fnv_00d33ca0 {
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long);
extern "C" void __cdecl FUN_00d34810(int, int, int, int, int);
extern "C" void __cdecl FUN_00daf8e0(int, int, int, void*, void*);

extern int DAT_0126835c;
extern float DAT_0104da48;
extern int DAT_010cebe0;
extern char str_010cec54[];
extern char str_010cec34[];
extern char str_010cec4c[];
extern char str_01076f38[];

struct S00d33ca0_Buf
{
    int unk00;
    unsigned int* cur;
    int unk08;
    unsigned int* limit;
};

struct __declspec(align(16)) S00d33ca0_Local
{
    void* unk00;
    float unk04;
    char unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    volatile float unk2c;
};

// Writes a timer entry, calls FUN_00daf8e0, and if local.unk08 is set writes another entry and calls FUN_00d34810; then writes a closing timer entry.
// @fnv 0x00d33ca0
extern "C" void __cdecl FUN_00d33ca0(int a, int b, int c, int d, int e)
{
    S00d33ca0_Buf* buf;
    unsigned int* p;
    volatile unsigned int ts;

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p[0] = (unsigned int)&str_010cec54[0];
        p[3] = (unsigned int)&str_010cec34[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->cur = p + 4;
    }

    {
        S00d33ca0_Local local;
        local.unk2c = DAT_0104da48;
        local.unk04 = DAT_0104da48;
        local.unk00 = &DAT_010cebe0;
        local.unk08 = 0;
        FUN_00daf8e0(a, b, c, &local, &local);
        if (local.unk08 != 0)
        {
            buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
            p = buf->cur;
            if (p < buf->limit)
            {
                p[0] = (unsigned int)&str_010cec4c[0];
                _ReadWriteBarrier();
                ts = __rdtsc();
                p[1] = ts;
                buf->cur = p + 3;
            }
            FUN_00d34810(a, b, c, d, e);
        }
    }

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p[0] = (unsigned int)&str_01076f38[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->cur = p + 3;
    }
}
}  // namespace fnv_00d33ca0

namespace fnv_00d34510 {
struct ChunkAllocator
{
    virtual void* vfunc0();
    virtual void* allocate(int size);
};

struct MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ChunkAllocator* m_pThreadAllocator;
};

extern "C"
{
    MemoryRouter* __cdecl FUN_00c85750();
    void* __cdecl FUN_00dacbd0();
    void* __cdecl FUN_00d440f0();
    void* __cdecl FUN_00d33940();
}

typedef void*(__thiscall* PfnDacbd0)(void* self, void* bodyA, void* bodyB, void* contactMgr);
typedef void*(__thiscall* PfnD440f0)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);
typedef void*(__thiscall* PfnD33940)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);

struct AgentCollisionDispatcher
{
    virtual void* vfunc0();
    virtual void* vfunc1();
    virtual void* vfunc2();
    virtual int getCollisionType(void* bodyA, void* bodyB, void* input);
};

struct AgentCollisionInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AgentCollisionDispatcher* m_pCollisionDispatcher;
};

struct AgentHeader
{
    void* vtable;
    unsigned short m_usMemSizeAndFlags;
    short m_iObjectReferenceCount;
};

// Dispatches on collision type to allocate and initialize the appropriate agent object for the given body pair and contact manager.
// @fnv 0x00d34510
void* __cdecl FUN_00d34510(void* bodyA, void* bodyB, AgentCollisionInput* input, void* contactMgr)
{
    if (contactMgr)
    {
        switch (input->m_pCollisionDispatcher->getCollisionType(bodyA, bodyB, input))
        {
        case 0: {
            MemoryRouter* pMemoryRouter = FUN_00c85750();
            int iAllocSize = 0x90;
            void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
            ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
            ((PfnD33940)FUN_00d33940)(agent, bodyB, bodyA, input, contactMgr);
            *(void**)agent = (void*)0x10cec68;
            return agent;
        }
        case 1: {
            MemoryRouter* pMemoryRouter = FUN_00c85750();
            int iAllocSize = 0x38;
            void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
            ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
            return ((PfnD440f0)FUN_00d440f0)(agent, bodyA, bodyB, input, contactMgr);
        }
        case 2: {
            switch (input->m_pCollisionDispatcher->getCollisionType(bodyB, bodyA, input))
            {
            case 0: {
                MemoryRouter* pMemoryRouter = FUN_00c85750();
                int iAllocSize = 0x90;
                void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
                ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                return ((PfnD33940)FUN_00d33940)(agent, bodyA, bodyB, input, contactMgr);
            }
            case 1: {
                MemoryRouter* pMemoryRouter = FUN_00c85750();
                int iAllocSize = 0x38;
                void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
                ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                ((PfnD440f0)FUN_00d440f0)(agent, bodyB, bodyA, input, contactMgr);
                *(void**)agent = (void*)0x10ce8b0;
                return agent;
            }
            case 2: {
                MemoryRouter* pMemoryRouter = FUN_00c85750();
                int iAllocSize = 0x80;
                void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
                ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                ((PfnDacbd0)FUN_00dacbd0)(agent, bodyA, bodyB, contactMgr);
                *(void**)agent = (void*)0x10ceb94;
                return agent;
            }
            }
            break;
        }
        }
        return 0;
    }
    else
    {
        MemoryRouter* pMemoryRouter = FUN_00c85750();
        int iAllocSize = 0x38;
        void* agent = pMemoryRouter->m_pThreadAllocator->allocate(iAllocSize);
        ((AgentHeader*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
        return ((PfnD440f0)FUN_00d440f0)(agent, bodyA, bodyB, input, 0);
    }
}
}  // namespace fnv_00d34510


// src/havok/physics/collide/agent/compoundagent/shapecollection/hkpshapecollectionagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/shapecollection/hkpshapecollectionagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpShapeCollectionAgent
{
    const void* vtbl;
    void* p0;
    void* p1;
    void* p2;
    int count;
    void FUN_00d436f0(int arg);
};

// @fnv 0x00d436f0
void hkpShapeCollectionAgent::FUN_00d436f0(int arg)
{
    for (int i = 0; i < count; ++i)
    {
        void** arr = reinterpret_cast<void**>(reinterpret_cast<void**>(this)[3]);
        void* obj = arr[i * 2 + 1];
        ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(obj))[7])(obj, arg);
    }
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(this))[0])(this, 1);
}

struct ShapeItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int arg);
};

struct ShapeEntry
{
    int unk00;
    ShapeItem* m_pInventoryEntryData;  // +0x4
};

class FUN_00d43730_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ShapeEntry* m_entries;  // +0xc
    int m_uiItemCount;      // +0x10

    void CallShapeItems(int arg);
};

// @fnv 0x00d43730
void FUN_00d43730_cls::CallShapeItems(int arg)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_entries[i].m_pInventoryEntryData->v09(arg);
            ++i;
        } while (i < m_uiItemCount);
    }
}

namespace fnv_00d43760 {
struct ShapeItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(float a, float b, int c);
};

struct ShapeEntry
{
    int unk00;
    ShapeItem* m_pInventoryEntryData;  // +0x4
};

class FUN_00d43760_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ShapeEntry* m_entries;  // +0xc
    int m_uiItemCount;      // +0x10

    void DispatchToEntries(float a, float b, int c);
};

// @fnv 0x00d43760
void FUN_00d43760_cls::DispatchToEntries(float afArg1, float afArg2, int aiArg3)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_entries[i].m_pInventoryEntryData->v10(afArg1, afArg2, aiArg3);
            ++i;
        } while (i < m_uiItemCount);
    }
}
}  // namespace fnv_00d43760

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned long DAT_0126835c;

struct StringCursor
{
    char* m_kRayStart;
    char* m_cur;
    char* m_pRayCursor;
    char* m_kRayEnd;
};

struct hkpShapeCollection;

struct hkpShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual hkpShapeCollection* GetShapeContainer();
    int m_unk04;
    int m_unk08;
    int m_type;
};

struct hkpShapeCollection
{
    virtual void v00();
    virtual void v04();
    virtual unsigned int GetFirstKey();
    virtual unsigned int GetNextShapeKey(unsigned int key);
    virtual void v10();
    virtual const hkpShape* GetShapeForKey(unsigned int key, void* buffer);
};

struct hkBool
{
    char m_cBooleanValue;
};

struct hkpCdBody;
struct CollisionAgentContext;

struct hkpShapeCollectionFilter
{
    virtual void v00();
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& bodyB,
                                      const hkpCdBody& bodyA, const hkpShapeCollection& containerShapeA,
                                      unsigned int key);
};

struct hkpCollisionFilter
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    hkpShapeCollectionFilter m_shapeCollectionFilter;
};

struct hkpCollisionDispatcher;

struct CollisionAgentContext
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
    int m_unk04;
    int m_unk08;
    hkpCollisionFilter* m_pCollisionFilter;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
};

typedef void(__cdecl* AgentFunc)(const hkpCdBody* local_body, const hkpCdBody* bodyB,
                                 const CollisionAgentContext* input, void* collector);

struct CollisionAgentFunctionTable
{
    AgentFunc m_staticGetClosestPoints;
    AgentFunc m_func1;
    AgentFunc m_func2;
    AgentFunc m_func3;
    AgentFunc m_func4;
};

struct hkpCollisionDispatcher
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    unsigned char m_agentTable[35][32];
    int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4;
    CollisionAgentFunctionTable m_agentFuncs[100];
};

__forceinline void hkTimerBegin(const char* tag)
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_cur;
    if (cur < stream->m_kRayEnd)
    {
        *(const char**)cur = tag;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_cur = cur;
    }
}

__forceinline void hkTimerEnd()
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_cur;
    if (cur < stream->m_kRayEnd)
    {
        *(const char**)cur = "Et";
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_cur = cur;
    }
}

// Iterates the shape collection's keys, filters each child shape, and dispatches the static get-closest-points agent for each accepted pair.
// @fnv 0x00d43960
void __cdecl GetClosestPointsShapeCollection(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                                             const CollisionAgentContext* input, void* collector)
{
    hkTimerBegin("TtShapeCollection");

    hkpShapeCollection* collection = ((hkpShape*)bodyA->m_pCollisionShape)->GetShapeContainer();
    const hkpShape* shapeB = bodyB->m_pCollisionShape;

    hkpCdBody local_body;
    local_body.m_pMotionState = bodyA->m_pMotionState;
    local_body.m_parent = bodyA;

    int typeB = shapeB->m_type;

    unsigned int key = collection->GetFirstKey();
    while (key != (unsigned int)-1)
    {
        if (input->m_pCollisionFilter->m_shapeCollectionFilter
                .IsCollisionEnabled(*input, *bodyB, *bodyA, *collection, key)
                .m_cBooleanValue)
        {
            __declspec(align(16)) int buffer[128];
            const hkpShape* childShape = collection->GetShapeForKey(key, buffer);
            local_body.m_pCollisionShape = childShape;
            local_body.m_uiCollisionShapeKey = key;

            int typeA = childShape->m_type;
            hkpCollisionDispatcher* pDispatcher = input->m_pCollisionDispatcher;
            unsigned char uiAgentIndex = pDispatcher->m_agentTable[typeA][typeB];
            AgentFunc func = pDispatcher->m_agentFuncs[uiAgentIndex].m_staticGetClosestPoints;
            func(&local_body, bodyB, input, collector);
        }
        key = collection->GetNextShapeKey(key);
    }

    hkTimerEnd();
}

extern "C" void __cdecl QueryClosestPoints();

// @fnv 0x00d36920
void __cdecl FUN_00d36920()
{
    QueryClosestPoints();
}

void FUN_00d34790();
// @fnv 0x00d36990
void FUN_00d36990()
{
    FUN_00d34790();
}

extern char DAT_010cf318[];

struct hkBoolS
{
    char m_cBooleanValue;
    hkBoolS()
    {}
};

struct ShapeS
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual struct ContainerS* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};

struct ContainerS
{
    virtual void v00();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int key) const;
    virtual void v04();
    virtual const ShapeS* GetShapeForKey(unsigned int key, void* buffer) const;
};

struct CdBodyS
{
    const ShapeS* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const CdBodyS* m_parent;

    CdBodyS(const CdBodyS* parent)
    {
        m_pMotionState = parent->m_pMotionState;
        m_parent = parent;
    }
    void SetCollisionShapeAndKey(const ShapeS* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct CollisionInputS;
struct ContactMgrS;
struct AgentS;

struct CollidableFilterS
{
    virtual void v00();
};
struct ShapeCollectionFilterS
{
    virtual void v00();
    virtual hkBoolS IsCollisionEnabled(const CollisionInputS& input, const CdBodyS& a, const CdBodyS& b,
                                       const ContainerS& bContainer, unsigned int bKey) const;
};
struct CollisionFilterS
{
    virtual void f00();
    int unk04;
    int unk08;
};
struct FilterS : CollisionFilterS, ShapeCollectionFilterS
{
};

typedef AgentS*(__cdecl* CreateFunc)(const CdBodyS&, const CdBodyS&, const CollisionInputS&, ContactMgrS*);

struct Agent2FuncS
{
    CreateFunc m_pCreateFunc;
    void* m_f1;
    void* m_f2;
    void* m_f3;
    int m_bIsFlipped;
};

struct DispatcherS
{
    char pad000[0x1a0];
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    Agent2FuncS m_agent2Funcs[1];

    AgentS* getNewCollisionAgent(const CdBodyS& bodyA, const CdBodyS& bodyB, const CollisionInputS& input,
                                 ContactMgrS* mgr) const;
};

struct CollisionInputS
{
    DispatcherS* m_pCollisionDispatcher;
    int m_collisionQuality;
    int m_forceAcceptContactPoints;
    FilterS* m_iFilter;
    int unk10;
    int m_bCreatePredictiveAgents;
};

inline AgentS* DispatcherS::getNewCollisionAgent(const CdBodyS& bodyA, const CdBodyS& bodyB,
                                                 const CollisionInputS& input, ContactMgrS* mgr) const
{
    const int typeA = bodyA.m_pCollisionShape->m_type;
    const int typeB = bodyB.m_pCollisionShape->m_type;
    const unsigned char(*table)[32] = input.m_bCreatePredictiveAgents ? m_agent3TypeMap : m_agent2TypeMap;
    int idx = table[typeA][typeB];
    CreateFunc f = m_agent2Funcs[idx].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct RouterS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pStreamAllocator;
};
RouterS* FUN_00c85750();
void FUN_00c908c0(void* alloc, void* arr, int n, int size);

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    AgentS* m_pCollisionAgent;
};

struct AgentArray
{
    CollisionAgentMapRecord* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    CollisionAgentMapRecord m_kStorage[4];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(void* alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(CollisionAgentMapRecord));
        }
    }
    void reserve(int n)
    {
        RouterS* r = FUN_00c85750();
        GrowArrayCapacity(r->m_pStreamAllocator, n);
    }
    void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000004;
    }
    CollisionAgentMapRecord* expandByUnchecked(int n)
    {
        int oldSize = m_iElementCount;
        m_iElementCount = oldSize + n;
        return m_data + oldSize;
    }
};

struct RefObjS
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjS()
    {
        m_sReferenceCount = 1;
    }
    virtual void r00();
};
struct CollisionAgentS : RefObjS
{
    ContactMgrS* m_pContactManager;
    CollisionAgentS(ContactMgrS* mgr)
    {
        m_pContactManager = mgr;
    }
    virtual void a01();
};
struct InplaceArrayS : AgentArray
{
    InplaceArrayS()
    {
        init();
    }
};
struct FUN_00d440f0 : CollisionAgentS
{
    InplaceArrayS m_agents2;
    FUN_00d440f0(const CdBodyS& bodyA, const CdBodyS& bodyB, const CollisionInputS& input, ContactMgrS* mgr);
    virtual void a02();
};

// Reserves space for the shapes in bodyA's container and appends a key/agent pair for each shape accepted by the filter.
// @fnv 0x00d440f0
FUN_00d440f0::FUN_00d440f0(const CdBodyS& bodyA, const CdBodyS& bodyB, const CollisionInputS& input,
                           ContactMgrS* apContactMgr)
    : CollisionAgentS(apContactMgr)
{
    CdBodyS newOperandA(&bodyA);

    const ContainerS* shapeContainer = bodyA.m_pCollisionShape->GetShapeContainer();
    int size = shapeContainer->GetNumChildShapes();
    m_agents2.reserve(size);

    __declspec(align(16)) unsigned int shapeBuffer[128];

    for (unsigned int key = shapeContainer->GetFirstKey(); key != 0xffffffff;
         key = shapeContainer->GetNextShapeKey(key))
    {
        const ShapeS* shape = shapeContainer->GetShapeForKey(key, shapeBuffer);
        newOperandA.SetCollisionShapeAndKey(shape, key);
        if (input.m_iFilter->IsCollisionEnabled(input, bodyB, bodyA, *shapeContainer, key).m_cBooleanValue)
        {
            CollisionAgentMapRecord& newPair = *m_agents2.expandByUnchecked(1);
            newPair.m_pCollisionAgent =
                input.m_pCollisionDispatcher->getNewCollisionAgent(newOperandA, bodyB, input, apContactMgr);
            newPair.m_key = key;
        }
    }
}

class hkBoolR
{
  public:
    hkBoolR()
    {}
    hkBoolR(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct __declspec(align(16)) ShapeBuffer
{
    int m_data[128];
};

struct HkShape;

struct ShapeContainer
{
    virtual void v00();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int key) const;
    virtual void v10();
    virtual const HkShape* GetShapeForKey(unsigned int key, ShapeBuffer& buffer) const;
};

struct HkShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const ShapeContainer* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};

struct CdBody
{
    const HkShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const CdBody* m_parent;

    CdBody(const CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    const HkShape* getShape() const
    {
        return m_pCollisionShape;
    }
    void SetCollisionShapeAndKey(const HkShape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct CollisionInput;

struct ShapeCollectionFilter
{
    virtual void v00();
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ReferencedObject
{
    virtual void v00();
    int unk04;
};

struct CollidableCollidableFilter
{
    virtual void v00();
};

struct CollisionFilter : ReferencedObject, CollidableCollidableFilter, ShapeCollectionFilter
{
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ConstraintOwner;
struct ContactMgr;
struct CollisionAgent;

typedef CollisionAgent*(__cdecl* CreateFuncA)(const CdBody& a, const CdBody& b, const CollisionInput& input,
                                              ContactMgr* mgr);

struct AgentFuncsA
{
    CreateFuncA m_pCreateFunc;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
};

struct CollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    AgentFuncsA m_agent2Funcs[32];

    CollisionAgent* getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                         ContactMgr* mgr) const;
};

struct CollisionInput
{
    CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    CollisionFilter* m_iFilter;
    int unk10;
    int m_bCreatePredictiveAgents;
};

inline CollisionAgent* CollisionDispatcher::getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB,
                                                                 const CollisionInput& input, ContactMgr* mgr) const
{
    int typeA = bodyA.getShape()->m_type;
    int typeB = bodyB.getShape()->m_type;
    const unsigned char* agentTypeTablePtr =
        (input.m_bCreatePredictiveAgents) ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
    int agentType = agentTypeTablePtr[typeA * 32 + typeB];
    CreateFuncA f = m_agent2Funcs[agentType].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct CollisionAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void cleanup(ConstraintOwner& owner);
    virtual void ProcessContactPoints(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                      ConstraintOwner& owner);
};

struct MemAllocator;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemAllocator* m_pStreamAllocator;
    MemAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize);

__forceinline MemRouter* getRouter()
{
    return (MemRouter*)FUN_00c85750();
}

__forceinline void memCpyOneAligned8(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<unsigned int*>(dst)[i] = static_cast<const unsigned int*>(src)[i];
    } while (++i < 2);
}

struct KeyAgentPairA
{
    unsigned int m_key;
    CollisionAgent* m_pCollisionAgent;
};

struct AgentPairArray
{
    KeyAgentPairA* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    KeyAgentPairA& operator[](int i)
    {
        return m_data[i];
    }

    KeyAgentPairA& AllocatePair()
    {
        MemAllocator& a = getRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&a, this, sizeof(KeyAgentPairA));
        return m_data[m_iElementCount++];
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            memCpyOneAligned8(m_data + index, m_data + m_iElementCount);
        }
    }
};

class ShapeCollectionAgentA
{
  public:
    virtual void v00();
    int unk04;
    ContactMgr* m_pContactManager;
    AgentPairArray m_pAgents;

    int findAgent(unsigned int key) const
    {
        for (int i = 0; i < m_pAgents.m_iElementCount; i++)
        {
            if (m_pAgents.m_data[i].m_key == key)
                return i;
        }
        return -1;
    }

    void updateShapeCollectionFilter(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                      ConstraintOwner& constraintOwner);
};

// Iterates shape keys in bodyA's container, creating or updating collision agents for enabled pairs and removing agents for disabled ones.
// @fnv 0x00d43f10
void ShapeCollectionAgentA::updateShapeCollectionFilter(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                         ConstraintOwner& constraintOwner)
{
    CdBody newOperandA(&bodyA);
    const ShapeContainer* container = bodyA.getShape()->GetShapeContainer();
    ShapeBuffer shapeBuffer;

    for (unsigned int key = container->GetFirstKey(); key != 0xffffffff; key = container->GetNextShapeKey(key))
    {
        int index = findAgent(key);

        if (input.m_iFilter->IsCollisionEnabled(input, bodyB, bodyA, *container, key))
        {
            newOperandA.SetCollisionShapeAndKey(container->GetShapeForKey(key, shapeBuffer), key);
            if (index == -1)
            {
                KeyAgentPairA& pair = m_pAgents.AllocatePair();
                pair.m_key = key;
                pair.m_pCollisionAgent =
                    input.m_pCollisionDispatcher->getNewCollisionAgent(newOperandA, bodyB, input, m_pContactManager);
            }
            else
            {
                m_pAgents[index].m_pCollisionAgent->ProcessContactPoints(newOperandA, bodyB, input, constraintOwner);
            }
        }
        else if (index != -1)
        {
            m_pAgents[index].m_pCollisionAgent->cleanup(constraintOwner);
            m_pAgents.removeAt(index);
        }
    }
}

#include <windows.h>
extern DWORD g_tlsIndex;

struct Rec
{
    const char* name;
    unsigned int ticks;
    int unk08;
};

struct ProfilerBuf
{
    int unk00;
    Rec* cur;
    int unk08;
    Rec* end;
};

struct Queryable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int v14(int id, void* out);
};

struct Source
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Queryable* v10();
};

struct Holder
{
    Source* unk00;
    int unk04;
    int unk08;
};

struct Packet
{
    int result;
    int id;
    int unk08;
    Holder* holder;
};

struct Handler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(Packet* packet, int a, int b, int c, int d);
};

struct Pair
{
    int id;
    Handler* handler;
};

struct __declspec(align(16)) B16
{
    int a;
    int b;
    int c;
    int d;
};
struct B64
{
    B16 a;
    B16 b;
    B16 c;
    B16 d;
};
struct B256
{
    B64 a;
    B64 b;
    B64 c;
    B64 d;
};
struct B512
{
    B256 a;
    B256 b;
};

// Calling convention note: declared __thiscall as in the packet (this in ecx, callee pops 20 bytes).
struct Agent : hkpShapeCollectionAgent
{
    void FUN_00d43aa0(Holder* holder, int a, int b, int c, int d);
};

// Records profiler markers, queries holder's Queryable for each pair, and dispatches results to each handler with the given arguments.
// @fnv 0x00d43aa0
void Agent::FUN_00d43aa0(Holder* holder, int a, int b, int c, int d)
{
    ProfilerBuf* pb = (ProfilerBuf*)TlsGetValue(g_tlsIndex);
    Rec* cur = pb->cur;
    if (cur < pb->end)
    {
        volatile unsigned int t;
        cur->name = "TtShapeCollection";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        cur->ticks = t;
        pb->cur = cur + 1;
    }
    Queryable* q = holder->unk00->v10();
    Packet packet;
    B512 buf;
    packet.unk08 = holder->unk08;
    packet.holder = holder;
    Pair* p = (Pair*)p2;
    for (int i = count - 1; i >= 0; i--)
    {
        int id = p->id;
        int r = q->v14(id, &buf);
        packet.result = r;
        packet.id = id;
        p->handler->v14(&packet, a, b, c, d);
        p++;
    }
    pb = (ProfilerBuf*)TlsGetValue(g_tlsIndex);
    cur = pb->cur;
    if (cur < pb->end)
    {
        volatile unsigned int t;
        cur->name = "Et";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        cur->ticks = t;
        pb->cur = cur + 1;
    }
}

extern DWORD DAT_0126835c;

struct S_00d43cd0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d43cd0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d43cd0_Timer(const char* name)
{
    S_00d43cd0_MonitorStream* s = (S_00d43cd0_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d43cd0_TimerCommand* h = (S_00d43cd0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct __declspec(align(16)) S_00d43cd0_ShapeBuffer
{
    unsigned int m_data[128];
};

struct S_00d43cd0_Shape;
struct S_00d43cd0_Container
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual const S_00d43cd0_Shape* GetShapeForKey(unsigned int key, S_00d43cd0_ShapeBuffer& buffer) const;
};

struct S_00d43cd0_Shape
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const S_00d43cd0_Container* GetShapeContainer() const;
};

struct S_00d43cd0_MotionState;

struct S_00d43cd0_CdBody
{
    const S_00d43cd0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d43cd0_MotionState* m_pMotionState;
    const S_00d43cd0_CdBody* m_parent;

    S_00d43cd0_CdBody(const S_00d43cd0_CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d43cd0_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct S_00d43cd0_Input;

struct S_00d43cd0_Collector
{
    void* vtbl;
    char m_fHitDistance;
};

struct S_00d43cd0_Agent
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void process(const S_00d43cd0_CdBody& a, const S_00d43cd0_CdBody& b, const S_00d43cd0_Input& input,
                         S_00d43cd0_Collector& c);
};

struct S_00d43cd0_Entry
{
    unsigned int m_key;
    S_00d43cd0_Agent* m_pCollisionAgent;
};

struct S_00d43cd0
{
    void* vtbl;
    int unk04;
    int unk08;
    S_00d43cd0_Entry* m_entries;
    int m_iElementCount;
    void ProcessCollisionEntries(const S_00d43cd0_CdBody& bodyA, const S_00d43cd0_CdBody& bodyB,
                                 const S_00d43cd0_Input& input, S_00d43cd0_Collector& collector);
};

// Iterates m_entries, resolving each key to a shape, and calls the agent's process on bodyA/bodyB until the collector reports a hit.
// @fnv 0x00d43cd0
void S_00d43cd0::ProcessCollisionEntries(const S_00d43cd0_CdBody& bodyA, const S_00d43cd0_CdBody& bodyB,
                                         const S_00d43cd0_Input& input, S_00d43cd0_Collector& collector)
{
    S_00d43cd0_Timer("TtShapeCollection");

    const S_00d43cd0_Container* container = bodyA.m_pCollisionShape->GetShapeContainer();
    S_00d43cd0_CdBody newBodyA(&bodyA);
    S_00d43cd0_ShapeBuffer shapeBuffer;

    S_00d43cd0_Entry* pEntry = m_entries;
    int n = m_iElementCount - 1;
    if (n >= 0)
    {
        do
        {
            unsigned int key = pEntry->m_key;
            const S_00d43cd0_Shape* shape = container->GetShapeForKey(key, shapeBuffer);
            newBodyA.SetCollisionShapeAndKey(shape, key);
            pEntry->m_pCollisionAgent->process(newBodyA, bodyB, input, collector);
            if (collector.m_fHitDistance)
                break;
            pEntry++;
        } while (--n >= 0);
    }

    S_00d43cd0_Timer("Et");
}

extern DWORD hkMonitorStreamTls;

struct S_00d43dc0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d43dc0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d43dc0_Timer(const char* name)
{
    S_00d43dc0_MonitorStream* s = (S_00d43dc0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d43dc0_TimerCommand* h = (S_00d43dc0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d43dc0_Bool
{
    char m_cBooleanValue;
    S_00d43dc0_Bool()
    {}
    S_00d43dc0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) S_00d43dc0_ShapeBuffer
{
    unsigned int m_data[128];
};

struct S_00d43dc0_ShapeContainer;

struct S_00d43dc0_Shape
{
    virtual ~S_00d43dc0_Shape();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const S_00d43dc0_ShapeContainer* GetShapeContainer() const;
    int unk04_;
    int unk08_;
    int m_type;
    int getType() const
    {
        return m_type;
    }
};

struct S_00d43dc0_ShapeContainer
{
    virtual ~S_00d43dc0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00d43dc0_Shape* GetShapeForKey(unsigned int key, S_00d43dc0_ShapeBuffer& buffer) const;
};

struct S_00d43dc0_MotionState;

struct S_00d43dc0_CdBody
{
    const S_00d43dc0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d43dc0_MotionState* m_pMotionState;
    const S_00d43dc0_CdBody* m_parent;

    S_00d43dc0_CdBody(const S_00d43dc0_CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d43dc0_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
    const S_00d43dc0_Shape* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct S_00d43dc0_CollisionInput;

struct S_00d43dc0_CdBodyPairCollector
{
    void* vtbl;
    S_00d43dc0_Bool m_fHitDistance;
    S_00d43dc0_Bool getEarlyOut() const
    {
        return m_fHitDistance;
    }
};

typedef void(__cdecl* S_00d43dc0_GetPenetrationsFunc)(const S_00d43dc0_CdBody& bodyA, const S_00d43dc0_CdBody& bodyB,
                                                      const S_00d43dc0_CollisionInput& input,
                                                      S_00d43dc0_CdBodyPairCollector& collector);

struct S_00d43dc0_Agent2Funcs
{
    void* m_pCreateFunc;
    S_00d43dc0_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct S_00d43dc0_Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d43dc0_Agent2Funcs m_agent2Funcs[32];

    S_00d43dc0_GetPenetrationsFunc getGetPenetrationsFunc(int typeA, int typeB) const
    {
        int idx = m_agent2TypeMap[typeA][typeB];
        return m_agent2Funcs[idx].m_pQueryPenetrationsFunc;
    }
};

struct S_00d43dc0_ShapeCollectionFilter
{
    virtual S_00d43dc0_Bool isCollisionEnabled0() const;
    virtual S_00d43dc0_Bool IsCollisionEnabled(const S_00d43dc0_CollisionInput& input, const S_00d43dc0_CdBody& a,
                                               const S_00d43dc0_CdBody& b, const S_00d43dc0_ShapeContainer& bContainer,
                                               unsigned int bKey) const = 0;
};

struct S_00d43dc0_FilterBase
{
    virtual void unk00();
    int unk04;
    int unk08;
};

struct S_00d43dc0_CollisionFilter : S_00d43dc0_FilterBase, S_00d43dc0_ShapeCollectionFilter
{
};

struct S_00d43dc0_CollisionInput
{
    S_00d43dc0_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    const S_00d43dc0_CollisionFilter* m_iFilter;
};

// Iterates shapes in bodyA's container, calls the dispatcher's penetration query for each enabled shape, and stops early if the collector requests it.
// @fnv 0x00d43dc0
void __cdecl FUN_00d43dc0(const S_00d43dc0_CdBody& bodyA, const S_00d43dc0_CdBody& bodyB,
                          const S_00d43dc0_CollisionInput& input, S_00d43dc0_CdBodyPairCollector& collector)
{
    S_00d43dc0_Timer("TtShapeCollection");

    const S_00d43dc0_ShapeContainer* shapeContainer = bodyA.getShape()->GetShapeContainer();
    S_00d43dc0_CdBody newOperandA(&bodyA);

    int typeB = bodyB.getShape()->getType();
    S_00d43dc0_ShapeBuffer shapeBuffer;

    for (unsigned int key = shapeContainer->GetFirstKey(); key != 0xffffffff;
         key = shapeContainer->GetNextShapeKey(key))
    {
        if (input.m_iFilter->IsCollisionEnabled(input, bodyB, bodyA, *shapeContainer, key))
        {
            const S_00d43dc0_Shape* shape = shapeContainer->GetShapeForKey(key, shapeBuffer);
            newOperandA.SetCollisionShapeAndKey(shape, key);
            S_00d43dc0_GetPenetrationsFunc getPenetrationsFunc =
                input.m_pCollisionDispatcher->getGetPenetrationsFunc(shape->getType(), typeB);
            getPenetrationsFunc(newOperandA, bodyB, input, collector);
            if (collector.getEarlyOut())
            {
                break;
            }
        }
    }

    S_00d43dc0_Timer("Et");
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

struct ShapeResult
{
    DWORD m_ret;
    DWORD m_key;
    DWORD m_pMotionState;
    void* m_parent;
};

struct KeyedPointerEntry
{
    DWORD m_key;
    void* m_pEntryObject;
};

__declspec(align(16)) struct ShapeKeyBuf
{
    DWORD m_key;
    DWORD unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
        unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC,
        unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC,
        unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134,
        unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C,
        unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4,
        unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC,
        unk1E0, unk1E4, unk1E8, unk1EC, unk1F0;
};

class ShapeSource
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void* vtbl10(void);
};

class ShapeKeyHandler
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void);
    virtual DWORD vtbl14(DWORD key, ShapeKeyBuf* pOut);
};

class ShapeObject
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void* pKey, DWORD a1, DWORD a2, DWORD a3);
};

struct ShapeHolder
{
    ShapeSource* m_pSrc;
    DWORD unk04;
    DWORD m_dw08;
};

struct FUN_00d43880_cls : public hkpShapeCollectionAgent
{
    void FUN_00d43880(ShapeHolder* pHolder, DWORD a1, DWORD a2, DWORD a3);
};

// Between profiler records, loops count pairs: pHandler->vtbl14 fills a result for each key, then the pair's object receives it via vtbl10 with a1, a2, a3.
// @fnv 0x00d43880
void FUN_00d43880_cls::FUN_00d43880(ShapeHolder* pHolder, DWORD a1, DWORD a2, DWORD a3)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtShapeCollection";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }

    ShapeKeyHandler* pHandler = (ShapeKeyHandler*)pHolder->m_pSrc->vtbl10();
    ShapeResult res;
    res.m_pMotionState = pHolder->m_dw08;
    int i = this->count - 1;
    res.m_parent = pHolder;
    KeyedPointerEntry* apPairs = (KeyedPointerEntry*)this->p2;
    ShapeKeyBuf keyBuf;
    if (i >= 0)
    {
        do
        {
            DWORD key = apPairs->m_key;
            res.m_ret = pHandler->vtbl14(key, &keyBuf);
            res.m_key = key;
            ShapeObject* pObj = (ShapeObject*)apPairs->m_pEntryObject;
            pObj->vtbl10(&res, a1, a2, a3);
            apPairs++;
            i--;
        } while (i >= 0);
    }

    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

extern const char str_010cf300[];
extern const char str_010c41f8[];

__declspec(align(16)) struct hkpShapeBuffer
{
    unsigned long m_data[125];
};

typedef void(__cdecl* LinearCastFunc)(const hkpCdBody* local_body, const hkpCdBody* bodyB,
                                      const CollisionAgentContext* input, void* a4, void* a5);

// Iterates each shape in bodyA's collection, dispatches the linear-cast agent for enabled shapes against bodyB, and times the work.
// @fnv 0x00d43b90
void __cdecl FUN_00d43b90(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const CollisionAgentContext* input, void* a4,
                          void* a5)
{
    hkTimerBegin(str_010cf300);

    hkpShapeCollection* collection = const_cast<hkpShape*>(bodyA->m_pCollisionShape)->GetShapeContainer();
    hkpCdBody localBody;
    localBody.m_pMotionState = bodyA->m_pMotionState;
    localBody.m_parent = bodyA;

    int typeB = bodyB->m_pCollisionShape->m_type;
    unsigned int key = collection->GetFirstKey();
    if (key != -1)
    {
        do
        {
            if (input->m_pCollisionFilter->m_shapeCollectionFilter
                    .IsCollisionEnabled(*input, *bodyB, *bodyA, *collection, key)
                    .m_cBooleanValue)
            {
                hkpShapeBuffer buffer;
                const hkpShape* childShape = collection->GetShapeForKey(key, &buffer);
                localBody.m_pCollisionShape = childShape;
                localBody.m_uiCollisionShapeKey = key;

                int typeA = childShape->m_type;
                unsigned char agentType = input->m_pCollisionDispatcher->m_agentTable[typeA][typeB];
                LinearCastFunc func = (LinearCastFunc)input->m_pCollisionDispatcher->m_agentFuncs[agentType].m_func1;
                func(&localBody, bodyB, input, a4, a5);
            }
            key = collection->GetNextShapeKey(key);
        } while (key != -1);
    }

    hkTimerBegin(str_010c41f8);
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct CollectionProcessHandler
{
    virtual void v00(void);
    virtual void v04(void);
    virtual void v08(void);
    virtual void v0c(void);
    virtual CollectionProcessHandler* v10(void);
    virtual void* v14(void* pShape, void* pOut);
    virtual void v18(void* apPairs, unsigned int a0, unsigned int a1, unsigned int a2);
};

struct ShapeArg
{
    CollectionProcessHandler* pHandler;
    void* unk04;
    unsigned int unk08;
};

struct CollectionProcessEntry
{
    void* pShape;
    CollectionProcessHandler* pHandler;
};

struct CollectionProcessBody
{
    void* pResult;
    void* pShape;
    unsigned int unk08;
    unsigned int unk0c;
};

struct CollectionProcessAgent : hkpShapeCollectionAgent
{
    void FUN_00d437a0(ShapeArg* arg, unsigned int a0, unsigned int a1, unsigned int a2);
};

// Records a TtShapeCollection profiler tick, calls v14 on each shape, dispatches results via v18, then records an Et profiler tick.
// @fnv 0x00d437a0
void CollectionProcessAgent::FUN_00d437a0(ShapeArg* arg, unsigned int a0, unsigned int a1, unsigned int a2)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtShapeCollection";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }

    CollectionProcessHandler* pRes = arg->pHandler->v10();
    CollectionProcessBody pair;
    hkpShapeBuffer out;
    pair.unk08 = arg->unk08;
    pair.unk0c = (unsigned int)arg;

    CollectionProcessEntry* pEntry = (CollectionProcessEntry*)p2;
    for (int i = count - 1; i >= 0; i--)
    {
        void* shape = pEntry->pShape;
        pair.pResult = pRes->v14(shape, out.m_data);
        pair.pShape = shape;
        pEntry->pHandler->v18(&pair, a0, a1, a2);
        pEntry++;
    }

    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

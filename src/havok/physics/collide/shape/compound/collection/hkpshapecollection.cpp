
// src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/hkpshapecollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpShapeCollection.h"

class hkPackedNiTriStripsShape;
class hkNiTriStripsShape;
class hkpListShape;

class hkpShapeCollection_L
{
  public:
    virtual ~hkpShapeCollection_L();
    virtual int getContainer();
};

// @fnv 0x00d213d0
int hkpShapeCollection_L::getContainer()
{
    if (this != 0)
    {
        return reinterpret_cast<int>(this) + 0x10;
    }
    return 0;
}

extern char const* const DAT_01268910;
void __cdecl FUN_00c90360(char const* const* first, char const* const* second);
// @fnv 0x00d213e0
void __cdecl FUN_00d213e0(char const* const* first, char const* const* ignored)
{
    FUN_00c90360(first, &DAT_01268910);
}

// @fnv 0x00d213f0
void __stdcall FUN_00d213f0(int, int)
{}

// @fnv 0x00d21400
void __stdcall initWeldingInfo(int a1)
{}

struct Allocator
{
    virtual void vfn0();
    virtual void vfn4();
    virtual void Free(void* pointer, unsigned short size);
};
struct MemorySystem
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    Allocator* allocator;
};
extern char DAT_010c6fb0;
extern char DAT_0102e388;
struct Holder
{
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    unsigned int userData;
    unsigned int shapeType;
    void* shapeVtable;
    MemorySystem* __thiscall FUN_00c85750();
    Holder* __thiscall Destroy(unsigned char flags);
};
// Sets shapeVtable and vtable, then frees the object via the memory system allocator if the low bit of flags is set.
// @fnv 0x00cf57e0
Holder* __thiscall Holder::Destroy(unsigned char flags)
{
    shapeVtable = &DAT_010c6fb0;
    vtable = &DAT_0102e388;
    if ((flags & 1) != 0)
    {
        MemorySystem* memory = FUN_00c85750();
        memory->allocator->Free(this, memSizeAndFlags);
    }
    return this;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet()
    {}
    hkBoolRet(char b) : m_cBooleanValue(b)
    {}
};

typedef unsigned int hkpShapeKey;

struct StringCursor
{
    char* m_kRayStart;
    char* m_pTileTemplate;
    char* m_pRayCursor;
    char* m_kRayEnd;
};

class ShapeRayCastQuery;
class ShapeRayCastOutput;
class hkpRayShapeCollectionFilter;

class hkpShape_V : public hkpShape
{
  public:
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual hkBoolRet RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual hkpShapeKey getFirstShapeKey() const;
    virtual hkpShapeKey getNextShapeKey(hkpShapeKey key) const;
    virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key) const;
    virtual const hkpShape_V* GetShapeForKey(hkpShapeKey key, void* buffer) const;
};

class FUN_00d21450_Class : public hkpShape
{
  public:
    hkpShapeContainer m_container;
    hkBool m_bDisableWelding;
    hkUint8 m_eCollectionType;
    char unk16;
    char unk17;

    hkBoolRet castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

struct ShapeRayCastQuery
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
    const hkpRayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};

struct ShapeRayCastOutput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpShapeKey m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

class hkpRayShapeCollectionFilter
{
  public:
    virtual hkBoolRet IsCollisionEnabled(const ShapeRayCastQuery& aInput, const FUN_00d21450_Class& aCollection,
                                         const hkpShapeContainer& bContainer, hkpShapeKey aKey) const = 0;
};

// Calls RayCast on each child in m_container (filtered if a filter is given), stores the last hit shape key in output.m_uiShapeKeys, returns true if any hit.
// @fnv 0x00d21450
hkBoolRet FUN_00d21450_Class::castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    volatile unsigned int time;
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* current = stream->m_pTileTemplate;
    if (current < stream->m_kRayEnd)
    {
        *(const char**)current = "TtrcShpCollect";
        _ReadWriteBarrier();
        time = (unsigned int)__rdtsc();
        *(unsigned int*)(current + 4) = time;
        current += 12;
        stream->m_pTileTemplate = current;
    }
    output.m_uiShapeKeyIndex++;
    const hkpShapeContainer* container = &m_container;
    hkpShapeKey uiHitKey = 0xffffffff;
    __declspec(align(16)) hkUlong buffer[512 / sizeof(hkUlong)];
    hkBoolRet hitResult;
    if (input.m_pRayShapeCollectionFilter == 0)
    {
        hkpShapeKey key = container->getFirstShapeKey();
        while (key != 0xffffffff)
        {
            const hkpShape_V* child = container->GetShapeForKey(key, buffer);
            hitResult.hkBoolRet::hkBoolRet(child->RayCast(input, output));
            if (hitResult.m_cBooleanValue)
                uiHitKey = key;
            key = container->getNextShapeKey(key);
        }
    }
    else
    {
        hkpShapeKey key = container->getFirstShapeKey();
        while (key != 0xffffffff)
        {
            if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *this, *container, key).m_cBooleanValue)
            {
                const hkpShape_V* child = container->GetShapeForKey(key, buffer);
                hitResult.hkBoolRet::hkBoolRet(child->RayCast(input, output));
                if (hitResult.m_cBooleanValue)
                    uiHitKey = key;
            }
            key = container->getNextShapeKey(key);
        }
    }

    output.m_uiShapeKeyIndex--;
    if (uiHitKey != 0xffffffff)
    {
        output.m_uiShapeKeys[output.m_uiShapeKeyIndex] = uiHitKey;
    }
    StringCursor* streamEnd = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* currentEnd = streamEnd->m_pTileTemplate;
    if (currentEnd < streamEnd->m_kRayEnd)
    {
        *(const char**)currentEnd = "Et";
        _ReadWriteBarrier();
        time = (unsigned int)__rdtsc();
        *(unsigned int*)(currentEnd + 4) = time;
        currentEnd += 12;
        streamEnd->m_pTileTemplate = currentEnd;
    }
    return hkBoolRet(uiHitKey != 0xffffffff);
}

namespace fnv_00d217d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwIndex);

extern "C" unsigned int DAT_0126835c;
extern "C" char str_010ce1f8[];
extern "C" char str_010c41f8[];

class Arg0_L;
class Arg1_L;
class Arg2_L;
class ShapeBuf_L;
struct Ctx_L;
class Owner_L;

struct ProfRec_L
{
    void* id;
    unsigned int time;
    int unk08;
};
struct ProfSlot_L
{
    int unk00;
    ProfRec_L* head;
    int unk08;
    ProfRec_L* end;
};

class Shape_L
{
  public:
    virtual ~Shape_L();
    virtual int s01();
    virtual int s02();
    virtual int s03();
    virtual int s04();
    virtual int s05();
    virtual int s06();
    virtual int s07();
    virtual int s08();
    virtual void process_L(Arg0_L* arg0, Ctx_L* ctx, Arg2_L* arg2);
};

class Coll_L2 : public hkpShapeCollection_L
{
  public:
    virtual int getFirstKey_L();
    virtual int getNextKey_L(int key);
    virtual int s04();
    virtual Shape_L* getChildShape_L(int key, ShapeBuf_L& buffer);
};

class Filter_L
{
  public:
    virtual char* isEnabled_L(char* out, Arg0_L* arg0, Owner_L* self, Coll_L2* coll, int key);
};

class Arg0_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    Filter_L* m_iFilter;
};

class Arg1_L
{
  public:
    void* unk00;
    void* unk04;
    int unk08;
};
class Arg2_L
{
  public:
    int dummy;
};

struct Ctx_L
{
    Shape_L* shape;
    int key;
    int unk08;
    Arg1_L* arg1;
};

struct __declspec(align(16)) ShapeBuf_L
{
    hkVector4 v00, v01, v02, v03, v04, v05, v06, v07;
    hkVector4 v08, v09, v10, v11, v12, v13, v14, v15;
    hkVector4 v16, v17, v18, v19, v20, v21, v22, v23;
    hkVector4 v24, v25, v26, v27, v28, v29, v30, v31;
};

class Owner_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Coll_L2 m_coll;
    void castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2);
};

// @fnv 0x00d217d0
void Owner_L::castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2)
{
    volatile unsigned int uiTimestamp;
    ProfSlot_L* pProfSlot = (ProfSlot_L*)TlsGetValue(DAT_0126835c);
    ProfRec_L* pProfRec = pProfSlot->head;
    if (pProfRec < pProfSlot->end)
    {
        pProfRec->id = &str_010ce1f8;
        _ReadWriteBarrier();
        uiTimestamp = (unsigned int)__rdtsc();
        pProfRec->time = uiTimestamp;
        pProfSlot->head = pProfRec + 1;
    }
    ShapeBuf_L buffer;
    char enabled;
    Ctx_L ctx;
    int key;
    if (arg0->m_iFilter == 0)
    {
        key = this->m_coll.getFirstKey_L();
        if (key != -1)
        {
            do
            {
                ctx.shape = this->m_coll.getChildShape_L(key, buffer);
                ctx.arg1 = arg1;
                ctx.unk08 = arg1->unk08;
                ctx.key = key;
                ctx.shape->process_L(arg0, &ctx, arg2);
                key = this->m_coll.getNextKey_L(key);
            } while (key != -1);
        }
    }
    else
    {
        key = this->m_coll.getFirstKey_L();
        if (key != -1)
        {
            do
            {
                if (*arg0->m_iFilter->isEnabled_L(&enabled, arg0, this, &this->m_coll, key))
                {
                    ctx.shape = this->m_coll.getChildShape_L(key, buffer);
                    ctx.arg1 = arg1;
                    ctx.unk08 = arg1->unk08;
                    ctx.key = key;
                    ctx.shape->process_L(arg0, &ctx, arg2);
                }
                key = this->m_coll.getNextKey_L(key);
            } while (key != -1);
        }
    }
    pProfSlot = (ProfSlot_L*)TlsGetValue(DAT_0126835c);
    pProfRec = pProfSlot->head;
    if (pProfRec < pProfSlot->end)
    {
        pProfRec->id = &str_010c41f8;
        _ReadWriteBarrier();
        uiTimestamp = (unsigned int)__rdtsc();
        pProfRec->time = uiTimestamp;
        pProfSlot->head = pProfRec + 1;
    }
}
}  // namespace fnv_00d217d0

extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern float DAT_0104e148;
extern const char str_010ce228[];
extern const char str_010c41f8[];

struct S00d216e0_Rec
{
    const char* name;
    unsigned int tick;
    unsigned int unk08;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        tick = uiTicks;
    }
};

struct S00d216e0_Ctx
{
    int unk00;
    S00d216e0_Rec* cur;
    int unk08;
    S00d216e0_Rec* end;
    static S00d216e0_Ctx& GetMonitorStream()
    {
        return *(S00d216e0_Ctx*)TlsGetValue(DAT_0126835c);
    }
};

__forceinline void S00d216e0_timer(const char* name)
{
    S00d216e0_Ctx& kCtx = S00d216e0_Ctx::GetMonitorStream();
    if (kCtx.cur < kCtx.end)
    {
        S00d216e0_Rec* h = kCtx.cur;
        h->name = name;
        h->setTime();
        kCtx.cur = h + 1;
    }
}

class ShapeIterator
{
  public:
    virtual ~ShapeIterator();
    virtual void Unk04();
    virtual int First();
    virtual int Next(int idx);
    virtual void Unk10();
    virtual class hkShape_StandIn* GetShape(int idx, float* outBuf);
};

class hkShape_StandIn : public hkpShape
{
  public:
    virtual ~hkShape_StandIn();
    virtual void Unk04();
    virtual void Unk08();
    virtual float GetMaxProjection(int arg);
};

class hkPackedNiTriStripsShape_StandIn : public hkpShapeCollection
{
  public:
    virtual ~hkPackedNiTriStripsShape_StandIn();
    virtual void Unk04();
    virtual int First();
    virtual float getMaximumProjection(int arg);
    virtual void Unk10();
    virtual void Unk14();
};

// Iterates child shapes via ShapeIterator, calls GetMaxProjection(arg) on each and returns the largest value, between two timer records.
// @fnv 0x00d216e0
float hkPackedNiTriStripsShape_StandIn::getMaximumProjection(int arg)
{
    volatile float maxProj;
    __declspec(align(16)) float buf[125];

    S00d216e0_timer(str_010ce228);

    ShapeIterator* iter = reinterpret_cast<ShapeIterator*>(reinterpret_cast<char*>(this) + 0x10);

    maxProj = DAT_0104e148;
    int idx = iter->First();

    while (idx != -1)
    {
        hkShape_StandIn* shape = iter->GetShape(idx, buf);
        float currentProj = shape->GetMaxProjection(arg);

        if (!(maxProj > currentProj))
        {
            maxProj = currentProj;
        }

        idx = iter->Next(idx);
    }

    S00d216e0_timer(str_010c41f8);

    return maxProj;
}

// sub ecx,0x10; jmp Destroy == MSVC adjustor thunk: Derived overrides a virtual that both
// bases declare; the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x10.
struct PrimaryBase
{
    virtual void FUN_00cf57d0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00cf57d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf57d0
    virtual void FUN_00cf57d0();
};

Derived::Derived()
{}

class hkpShape_ctor : public hkpShape
{
  public:
    hkpShape_ctor(int type)
    {
        m_sReferenceCount = 1;
        m_ulUserData = 0;
        m_type = type;
    }
};

class ShapeContainerLite
{
  public:
    virtual ~ShapeContainerLite();
    virtual int getContainer();
    ShapeContainerLite()
    {}
};

struct WeldingAndType
{
    char m_bDisableWelding;
    char m_eCollectionType;
    __forceinline WeldingAndType(char type)
    {
        m_bDisableWelding = 0;
        m_eCollectionType = type;
    }
};

class FUN_00d21410 : public hkpShape_ctor, public ShapeContainerLite
{
  public:
    WeldingAndType m_info;
    FUN_00d21410(int type, char collectionType);
    ~FUN_00d21410();
    virtual int getContainer();
};

// Constructs a shape object, initializing the reference count, user data, type, and collection type fields.
// @fnv 0x00d21410
FUN_00d21410::FUN_00d21410(int type, char collectionType)
    : hkpShape_ctor(type), ShapeContainerLite(), m_info(collectionType)
{}

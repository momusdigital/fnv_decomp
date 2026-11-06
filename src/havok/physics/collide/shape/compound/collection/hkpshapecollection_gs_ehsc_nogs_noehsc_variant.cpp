
// src/havok/physics/collide/shape/compound/collection/hkpshapecollection_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
extern char const* const DAT_01268910;
void __cdecl FUN_00c90360(char const* const* first, char const* const* second);
void __cdecl FUN_00d213e0(char const* const* first, char const* const* ignored);
void __stdcall FUN_00d213f0(int, int);
void __stdcall initWeldingInfo(int a1);
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

#include <xmmintrin.h>
struct Aabb
{
    __m128 minimum, maximum;
};
class ShapeAabb : public hkpShape
{
  public:
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void getAabb(const hkTransform&, float, Aabb&) const;
};
extern char DAT_010ce208;
extern char DAT_010c41f8;
class CollectionAabb : public FUN_00d21450_Class
{
  public:
    void FUN_00d215d0(const hkTransform& transform, float tolerance, Aabb& out) const;
};
// @fnv 0x00d215d0
void CollectionAabb::FUN_00d215d0(const hkTransform& transform, float tolerance, Aabb& out) const
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* event = stream->m_pTileTemplate;
    if (event < stream->m_kRayEnd)
    {
        *(const char**)event = &DAT_010ce208;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        *(unsigned int*)(event + 4) = stamp;
        stream->m_pTileTemplate = event + 12;
    }
    out.minimum = _mm_set1_ps(3.40282e38f);
    out.maximum = _mm_set1_ps(-3.40282e38f);
    hkpShapeKey key = m_container.getFirstShapeKey();
    while (key != (hkpShapeKey)-1)
    {
        __declspec(align(16)) char buffer[512];
        Aabb child;
        const ShapeAabb* shape = (const ShapeAabb*)m_container.GetShapeForKey(key, buffer);
        shape->getAabb(transform, tolerance, child);
        out.minimum = _mm_min_ps(out.minimum, child.minimum);
        out.maximum = _mm_max_ps(out.maximum, child.maximum);
        key = m_container.getNextShapeKey(key);
    }
    stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    event = stream->m_pTileTemplate;
    if (event < stream->m_kRayEnd)
    {
        *(const char**)event = &DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        *(unsigned int*)(event + 4) = stamp;
        stream->m_pTileTemplate = event + 12;
    }
}

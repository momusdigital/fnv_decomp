
// src/havok/physics/collide/filter/null/hkpnullcollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/null/hkpnullcollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpNullCollisionFilter.h"

extern int vftable_hkBaseObject;
extern int vftable_hkpCollidableCollidableFilter;
extern int vftable_hkpRayCollidableFilter;
extern int vftable_hkpShapeCollectionFilter;
extern int vftable_hkpRayShapeCollectionFilter;

struct FUN_00cfa860
{
    int a;
    int b;
    int c;
    int d;
    int e;
    ~FUN_00cfa860();
};

// @fnv 0x00cfa860
FUN_00cfa860::~FUN_00cfa860()
{
    *(void**)((char*)this + 0x14) = &vftable_hkpRayCollidableFilter;
    *(void**)((char*)this + 0x10) = &vftable_hkpRayShapeCollectionFilter;
    *(void**)((char*)this + 0x0c) = &vftable_hkpShapeCollectionFilter;
    *(void**)((char*)this + 0x08) = &vftable_hkpCollidableCollidableFilter;
    *(void**)((char*)this + 0x00) = &vftable_hkBaseObject;
}

extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
struct __declspec(align(16)) S_00cfab30_vec
{
    union
    {
        __m128 v;
        float f[4];
    };
};

struct S_00cfab30_arg
{
    S_00cfab30_vec vec;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char unk20;
};

struct __declspec(align(16)) S_00cfab30_local
{
    S_00cfab30_vec vec;
    int unk10;
    void* unk14;
    int unk18;
    void* unk1c;
};

struct S_00cfab30_record
{
    const char* name;
    unsigned int timestamp;
    unsigned int reserved;
};

struct S_00cfab30_allocator
{
    int unk00;
    S_00cfab30_record* next;
    int unk08;
    S_00cfab30_record* end;
};

struct S_00cfab30_this;

struct S_00cfab30_object
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v0a() = 0;
    virtual void v0b() = 0;
    virtual void v0c() = 0;
    virtual void v0d() = 0;
    virtual void v0e() = 0;
    virtual void v0f() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void target_call(S_00cfab30_local*, S_00cfab30_this*, int) = 0;
};

struct S_00cfab30_this
{
    void** vtable;
    void* unk04;
    void* unk08;
    void* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* unk34;

    void __thiscall RecordAndDispatch(S_00cfab30_object*, S_00cfab30_arg*, void*, void*, void*);
};

extern int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern const char str_010cc668[];
extern const char str_010c41f8[];

// Records a start timestamp, stores arguments into fields, invokes target_call on arg08 with a local struct, then records an end timestamp.
// @fnv 0x00cfab30
void __thiscall S_00cfab30_this::RecordAndDispatch(S_00cfab30_object* apTarget, S_00cfab30_arg* arg0c, void* apContext,
                                                   void* arg14, void* arg18)
{
    S_00cfab30_allocator* allocator;
    S_00cfab30_record* record;
    volatile unsigned int timestamp;
    S_00cfab30_local local;

    allocator = (S_00cfab30_allocator*)TlsGetValue(DAT_0126835c);
    record = allocator->next;

    if (record < allocator->end)
    {
        record->name = str_010cc668;
        _ReadWriteBarrier();
        timestamp = __rdtsc();
        record->timestamp = timestamp;
        allocator->next = record + 1;
    }

    void* context = apContext;
    unk04 = arg0c;
    unk0c = arg18;

    unk08 = context ? (char*)context + 0x14 : 0;
    _ReadWriteBarrier();

    if (arg0c->unk20)
    {
        void* pContextOffset10 = context ? (char*)context + 0x10 : 0;
        (void* volatile&)unk34 = pContextOffset10;
    }
    else
        unk34 = 0;
    local.unk10 = 1;
    local.unk18 = 0x10;
    local.vec.v = arg0c->vec.v;
    local.unk14 = &arg0c->unk10;
    local.unk1c = arg14;

    apTarget->target_call(&local, this, 0);

    allocator = (S_00cfab30_allocator*)TlsGetValue(DAT_0126835c);
    record = allocator->next;

    if (record < allocator->end)
    {
        record->name = str_010c41f8;
        _ReadWriteBarrier();
        timestamp = __rdtsc();
        record->timestamp = timestamp;
        allocator->next = record + 1;
    }
}

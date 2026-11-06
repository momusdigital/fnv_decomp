
// src/havok/physics/collide/shape/misc/bv/hkpbvshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/bv/hkpbvshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBvShape.h"

extern int DAT_010c6fb0;
extern int DAT_010c6fd0;
struct DDCC60World
{
    void __thiscall removeReference();
};
struct FUN_00c9d8c0
{
    int* vtbl;
    DDCC60World* m_pContainedShape;
    FUN_00c9d8c0* __thiscall doWork(int flags);
};
// @fnv 0x00c9d8c0
FUN_00c9d8c0* __thiscall FUN_00c9d8c0::doWork(int flags)
{
    DDCC60World* pOldWorld = m_pContainedShape;
    vtbl = (int*)&DAT_010c6fd0;
    if (pOldWorld)
        pOldWorld->removeReference();
    vtbl = (int*)&DAT_010c6fb0;
    return this;
}

struct FUN_00c9d970_shape
{
    virtual void method0() = 0;
    virtual void method1() = 0;
    virtual void method2() = 0;
    virtual void method3() = 0;
    virtual void method4() = 0;
    virtual void method5() = 0;
    virtual void method6() = 0;
    virtual void method7(int, float, void*) = 0;
};

struct FUN_00c9d970_class
{
    unsigned char padding[0x10];
    FUN_00c9d970_shape* shape;

    void DispatchShapeMethod7(int, float, void*);
};

// @fnv 0x00c9d970
void FUN_00c9d970_class::DispatchShapeMethod7(int value, float currentTime, void* queryFilter)
{
    shape->method7(value, currentTime, queryFilter);
}

struct FUN_00c9d930StandIn
{
    void FUN_00c9d930();
};

struct MemoryManagerStandIn
{
    virtual void Function0() = 0;
    virtual void Function1() = 0;
    virtual void Free(void* object, unsigned short flags) = 0;
};

struct hkpBvShapeStandIn
{
    hkpBvShapeStandIn* Destroy(int flags);
};

void* _D1A0E0GetMemoryRouter();

// Calls FUN_00c9d930 on this, then if flags has bit 0 set, frees this through the memory router's manager using the object flags at offset 4, and returns this.
// @fnv 0x00c9db30
hkpBvShapeStandIn* hkpBvShapeStandIn::Destroy(int flags)
{
    reinterpret_cast<FUN_00c9d930StandIn*>(this)->FUN_00c9d930();

    if (flags & 1)
    {
        void* router = _D1A0E0GetMemoryRouter();
        unsigned short objectFlags = *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 4);
        void* manager = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(router) + 0x10);

        reinterpret_cast<MemoryManagerStandIn*>(manager)->Free(this, objectFlags);
    }

    return this;
}

// @fnv 0x00c9d8b0
int __stdcall FUN_00c9d8b0(int a1)
{
    return -1;
}

extern int DAT_010c6fec;
extern int DAT_01268910;

struct C9D8F0Callback
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3(void* context, void* childShape, int flags);
};

struct C9D8F0Shape
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    void* m_pContainedShape;

    void FUN_00c90360(C9D8F0Callback* callback, void* typeInfo);
    void NotifyCallback(C9D8F0Callback* callback, int flags);
};

// @fnv 0x00c9d8f0
void C9D8F0Shape::NotifyCallback(C9D8F0Callback* callback, int flags)
{
    callback->method3(&DAT_010c6fec, m_pContainedShape, 0);
    FUN_00c90360(callback, &DAT_01268910);
}

struct hkpBvShapeContainerView : hkpBvShape
{
    hkpSingleShapeContainer* FUN_00c9d920();
};

// @fnv 0x00c9d920
hkpSingleShapeContainer* hkpBvShapeContainerView::FUN_00c9d920()
{
    return &m_pContainedShape;
}

extern int DAT_010c6ff8;
extern int DAT_010c6fd0;
struct Shape_00c9d990;
void __fastcall FUN_00c90510(Shape_00c9d990*);
struct FUN_00c9d990
{
    void* vtable;
    unsigned short memoryFlags;
    unsigned short referenceCount;
    unsigned int userData;
    unsigned int type;
    Shape_00c9d990* boundingVolume;
    void* containerVtable;
    Shape_00c9d990* child;
    FUN_00c9d990(Shape_00c9d990* bounds, Shape_00c9d990* childShape);
};
// @fnv 0x00c9d990
FUN_00c9d990::FUN_00c9d990(Shape_00c9d990* apBoundingVolume, Shape_00c9d990* childShape)
{
    referenceCount = 1;
    boundingVolume = apBoundingVolume;
    userData = 0;
    type = 27;
    vtable = &DAT_010c6ff8;
    containerVtable = &DAT_010c6fd0;
    child = childShape;
    FUN_00c90510(childShape);
    FUN_00c90510(boundingVolume);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010c7024[];
extern const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Rs_c9d9e0_Cmd
{
    const char* m_name;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct Rs_c9d9e0_Stream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_cap;

    __forceinline void timer(const char* name)
    {
        if (m_kRayEnd < m_cap)
        {
            Rs_c9d9e0_Cmd* c = reinterpret_cast<Rs_c9d9e0_Cmd*>(m_kRayEnd);
            c->m_name = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            c->m_uiStartTicks = t;
            m_kRayEnd = reinterpret_cast<char*>(c + 1);
        }
    }
};

struct Rs_c9d9e0_Input
{
    int unk00[16];
    int m_iValueAtOffset04;
};

struct Rs_c9d9e0_Shape
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual char* V20(char* r, int a, Rs_c9d9e0_Input* o);
};

struct Rs_c9d9e0_Self
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Rs_c9d9e0_Shape* m_pChildAtom;
    char* castRayImpl(char* ret, int a, Rs_c9d9e0_Input* o);
};

// Wraps m_pChildAtom->V20 in timer records and a counter increment/decrement on o; zeroes o->unk00[counter + 8] afterwards if *ret is nonzero; returns ret.
// @fnv 0x00c9d9e0
char* Rs_c9d9e0_Self::castRayImpl(char* ret, int a, Rs_c9d9e0_Input* o)
{
    static_cast<Rs_c9d9e0_Stream*>(TlsGetValue(DAT_0126835c))->timer(str_010c7024);
    o->m_iValueAtOffset04++;
    m_pChildAtom->V20(ret, a, o);
    o->m_iValueAtOffset04--;
    if (*ret)
        o->unk00[o->m_iValueAtOffset04 + 8] = 0;
    static_cast<Rs_c9d9e0_Stream*>(TlsGetValue(DAT_0126835c))->timer(str_010c41f8);
    return ret;
}

extern unsigned long DAT_0126835c;
struct hkMonitorCommand_c9da80
{
    const char* m_pName;
    unsigned int m_uiEventId;
    unsigned int m_uiPad;
};
struct hkMonitorStream_c9da80
{
    int unk00;
    hkMonitorCommand_c9da80* m_pCurrent;
    int unk08;
    hkMonitorCommand_c9da80* m_pRecordEnd;
};
static inline void TimerCommand_c9da80(const char* pName)
{
    hkMonitorStream_c9da80* pkStream = (hkMonitorStream_c9da80*)TlsGetValue(DAT_0126835c);
    hkMonitorCommand_c9da80* pkCommand = pkStream->m_pCurrent;
    if (pkCommand < pkStream->m_pRecordEnd)
    {
        pkCommand->m_pName = pName;
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        pkCommand->m_uiEventId = uiTicks;
        pkStream->m_pCurrent = pkCommand + 1;
    }
}
struct hkpShape_c9da80;
struct hkpCdBody_c9da80
{
    const hkpShape_c9da80* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody_c9da80* m_parent;
};
struct hkpShape_c9da80
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void castRayWithCollector(const void* pkInput, const hkpCdBody_c9da80& kBody, void* pkCollector) const;
};
struct ParentBody_c9da80
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct FUN_00c9da80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkpShape_c9da80* m_pChildShape;
    void castRayWithCollectorImpl(const void* pkInput, const hkpCdBody_c9da80& kParent, void* pkCollector) const;
};
// Builds a temporary hkpCdBody wrapping m_pChildShape with kParent as parent and forwards the ray cast to the child shape's castRayWithCollector.
// @fnv 0x00c9da80
void FUN_00c9da80_cls::castRayWithCollectorImpl(const void* pkInput, const hkpCdBody_c9da80& kParent, void* pkCollector) const
{
    TimerCommand_c9da80("TtrcBvShape");
    hkpCdBody_c9da80 kBody;
    kBody.m_parent = &kParent;
    kBody.m_pMotionState = kParent.m_pMotionState;
    kBody.m_pCollisionShape = m_pChildShape;
    kBody.m_uiCollisionShapeKey = 0;
    m_pChildShape->castRayWithCollector(pkInput, kBody, pkCollector);
    TimerCommand_c9da80("Et");
}

struct BvShapeReference
{
    void __thiscall FUN_00c905b0() throw();
};

extern int DAT_0102e388;

struct BvShapeReleaseView : hkpBvShape
{
    void FUN_00c9d930();
};

// Releases the held shape reference and the contained shape (if non-null), rewriting the object's two vtable pointers to fixed addresses around the calls.
// @fnv 0x00c9d930
void BvShapeReleaseView::FUN_00c9d930()
{
    hkpBvShape* self = (hkpBvShape*)this;

    BvShapeReference* bv = (BvShapeReference*)self->m_pBvShapeReference;
    *(int*)self = (int)&DAT_010c6ff8;
    bv->FUN_00c905b0();

    BvShapeReference* child = (BvShapeReference*)self->m_pContainedShape.m_pContainedShape;
    *(int*)&self->m_pContainedShape = (int)&DAT_010c6fd0;
    if (child)
        child->FUN_00c905b0();

    *(int*)self = (int)&DAT_0102e388;
    *(int*)&self->m_pContainedShape = (int)&DAT_010c6fb0;
}


// src/havok/physics/collide/shape/misc/transform/hkptransformshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/transform/hkptransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpTransformShape.h"
struct FUN_00cf5900
{
    int calc(int a2, int a3);
};
class hkClassCF58;
extern const hkClassCF58 DAT_01268910;
class hkStatisticsCollectorCF58
{
  public:
    virtual ~hkStatisticsCollectorCF58() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};
class hkpShapeCF58
{
  public:
    void FUN_00c90360(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};
class hkpSingleShapeContainerCF58 : public hkpShapeCF58
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const void* m_pContainedShape;

    void AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};
struct FnvCpu_FUN_00cf58f0_CpuObject
{
    char* FUN_00cf58f0();
};
class hkMemoryAllocatorCF5E
{
  public:
    virtual ~hkMemoryAllocatorCF5E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCF5E
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF5E* m_pStreamAllocator;
    hkMemoryAllocatorCF5E& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF5E& __cdecl FUN_00c85750();
struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
class hkReferencedObjectCF5E
{
  public:
    virtual ~hkReferencedObjectCF5E() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectCF5E*>(p)->m_usMemSizeAndFlags);
    }
};
class hkpShapeCF5E : public hkReferencedObjectCF5E
{
  public:
    hkUlong m_ulUserData;
    hkUint32 m_type;
};
class hkpShapeContainerCF5E
{
  public:
    virtual ~hkpShapeContainerCF5E() throw()
    {}
};
class hkpSingleShapeContainerCF5E : public hkpShapeContainerCF5E
{
  public:
    FUN_00d1df70* m_pContainedShape;

    ~hkpSingleShapeContainerCF5E() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->removeReference();
    }
};
class hkpTransformShapeCF5E : public hkpShapeCF5E, public hkpSingleShapeContainerCF5E
{
  public:
    hkpTransformShapeCF5E* DestroyAndMaybeFree(unsigned int uiFlags) throw();
};
extern int DAT_010cc41c;
extern int DAT_010c6fd0;
struct FUN_00c90510_class
{
    void FUN_00c90510();
};
struct cf5990_TransformShape
{
    void* m_vtbl;                      // 0x00
    unsigned short unk04;              // 0x04 (memSizeAndFlags, untouched here)
    unsigned short m_sReferenceCount;  // 0x06
    unsigned int m_ulUserData;         // 0x08
    unsigned int m_type;               // 0x0c
    void* m_childContainerVtbl;        // 0x10
    hkpShape* m_pContainedShape;       // 0x14

    void CopyBlock(const hkTransform& transform);
    int FUN_00cf5990(hkpShape* child, const hkTransform& transform);
};
struct __declspec(align(16)) Quaternion
{
    float x, y, z, w;
};
struct PackedTransform
{
    Quaternion rotationColumn0;
    Quaternion rotationColumn1;
    Quaternion rotationColumn2;
    Quaternion translation;
    void FUN_00cb2240(int a, Quaternion* base);
};
struct Dispatch
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c(PackedTransform* tmp, float factor, int flags);
};
struct FUN_00cf59e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Dispatch* dispatch;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Quaternion quaternion;
    void FUN_00cf59e0(int a, float factor, int flags);
};
#include <xmmintrin.h>
struct __declspec(align(16)) Vec4_cf5a
{
    float x, y, z, w;
};
class ConvexChild_cf5a
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual float getMaximumProjection(const Vec4_cf5a& direction) const;
};
class TransformShape_cf5a
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ConvexChild_cf5a* m_pContainedShape;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;

    float FUN_00cf5a20(const __m128& direction);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010cc448[];
extern const char str_010c41f8[];
struct CF5Mon
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pFreeList;
};
struct CF5Timer12
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int unk08;
};
struct CF5Bool
{
    char m_cBooleanValue;
    CF5Bool()
    {}
    CF5Bool(const CF5Bool& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};
struct CF5Vec
{
    float x, y, z, w;
};
struct CF5Rot
{
    CF5Vec c0;
    CF5Vec c1;
    CF5Vec c2;
};
struct CF5Transform
{
    CF5Rot rotation;
    CF5Vec translation;
};
struct CF5Input
{
    CF5Vec m_vFrom;
    CF5Vec m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct CF5Output
{
    CF5Vec m_vHitNormal;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_keys[8];
    int m_iValueAtOffset04;
    void FUN_00c7f700(const CF5Rot* rot, float* dir);
};
struct CF5Child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual CF5Bool RayCast(const CF5Input& in, CF5Output& out) const;
};
struct CF5Shape
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    CF5Child* m_pChildAtom;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    CF5Transform m_kMotionTransform;
    CF5Bool castRayImpl(const CF5Input& in, CF5Output& out) const;
};

static __forceinline void xfInvPos(CF5Vec& dst, const CF5Transform& xf, const CF5Vec& v)
{
    __m128 delta = _mm_sub_ps(*(const __m128*)&v, *(const __m128*)&xf.translation);
    __m128 axis0 = *(const __m128*)&xf.rotation.c0;
    __m128 axis1 = *(const __m128*)&xf.rotation.c1;
    __m128 axis2 = *(const __m128*)&xf.rotation.c2;
    __m128 low = _mm_unpacklo_ps(axis0, axis1);
    __m128 last = _mm_shuffle_ps(_mm_unpackhi_ps(axis0, axis1), axis2, 0xe4);
    axis0 = _mm_movelh_ps(low, axis2);
    axis1 = _mm_shuffle_ps(_mm_movehl_ps(axis0, low), axis2, 0xd4);
    axis2 = last;
    __m128 first = _mm_mul_ps(axis0, _mm_shuffle_ps(delta, delta, 0));
    __m128 second = _mm_mul_ps(axis1, _mm_shuffle_ps(delta, delta, 0x55));
    __m128 third = _mm_mul_ps(axis2, _mm_shuffle_ps(delta, delta, 0xaa));
    *(__m128*)&dst = _mm_add_ps(_mm_add_ps(first, second), third);
}

static void stamp1(CF5Mon* mon, const char* tag)
{
    char* pos = mon->m_kRayEnd;
    if (pos < mon->m_pFreeList)
    {
        volatile unsigned int ticks;
        CF5Timer12* t = (CF5Timer12*)pos;
        t->m_name = tag;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = pos + sizeof(CF5Timer12);
    }
}

// @fnv 0x00cf5b20
CF5Bool CF5Shape::castRayImpl(const CF5Input& in, CF5Output& out) const
{
    {
        CF5Mon* mon = (CF5Mon*)TlsGetValue(DAT_0126835c);
        stamp1(mon, str_010cc448);
    }
    CF5Input sub = in;
    xfInvPos(sub.m_vFrom, m_kMotionTransform, in.m_vFrom);
    xfInvPos(sub.m_vTo, m_kMotionTransform, in.m_vTo);
    out.m_iValueAtOffset04++;
    CF5Bool hit = m_pChildAtom->RayCast(sub, out);
    out.m_iValueAtOffset04--;
    if (hit.m_cBooleanValue)
    {
        CF5Vec n = out.m_vHitNormal;
        out.FUN_00c7f700(&m_kMotionTransform.rotation, &n.x);
        out.m_keys[out.m_iValueAtOffset04] = 0;
    }
    {
        CF5Mon* mon = (CF5Mon*)TlsGetValue(DAT_0126835c);
        stamp1(mon, str_010c41f8);
    }
    return hit;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern unsigned long hkMonitorStreamTlsIndex;

struct hkMonitorTimerCommand
{
    const char* m_pCommandName;
    hkUint32 m_uiStartTicks;
    hkUint32 m_uiEndTicks;
};

struct hkMonitorStreamInstance
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct hkTransformSetMul : public hkTransform
{
    void SetProduct(const hkTransform& a, const hkTransform& b);
};

struct hkVector4Sse
{
    __m128 m_vComponents;
};
struct SolTransform
{
    hkVector4Sse c0, c1, c2, tr;
};

struct hkpShapeRayCastInputSse
{
    hkVector4Sse m_vFrom;
    hkVector4Sse m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
    int unk28;
    int unk2C;
};

class hkpRayHitCollector;

struct hkpCdBodyLocal
{
    const hkpShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    const hkpCdBodyLocal* m_parent;
};

class hkpRayCastShape : public hkpShape
{
  public:
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void castRayWithCollector(const hkpShapeRayCastInputSse& input, const hkpCdBodyLocal& cdBody,
                                      hkpRayHitCollector& collector) const;
};

static __forceinline void timerCommand(const char* name)
{
    hkMonitorStreamInstance* stream = (hkMonitorStreamInstance*)TlsGetValue(hkMonitorStreamTlsIndex);
    char* end = stream->m_kRayEnd;
    if (end < stream->m_pCurrentCommand)
    {
        hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)end;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile hkUint32 ticks = (hkUint32)__rdtsc();
        h->m_uiStartTicks = ticks;
        stream->m_kRayEnd = (char*)(h + 1);
    }
}

static __forceinline __m128 transformInversePos(const SolTransform& t, __m128 v)
{
    __m128 b = _mm_sub_ps(v, t.tr.m_vComponents);
    __m128 c0 = t.c0.m_vComponents;
    __m128 c1 = t.c1.m_vComponents;
    __m128 c2 = t.c2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
    c0 = _mm_movelh_ps(tmp, c2);
    tmp = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(tmp, c2, _MM_SHUFFLE(3, 1, 1, 0));
    c2 = ctmp;
    __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
    __m128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class hkpTransformShapeRay : public hkpShape
{
  public:
    hkpSingleShapeContainer m_pContainedShape;
    int childSize;
    int unk1c;
    hkVector4Sse rotation;
    SolTransform m_kMotionTransform;
    void castRayWithCollectorImpl(const hkpShapeRayCastInputSse& input, const hkpCdBodyLocal& cdBody,
                      hkpRayHitCollector& collector) const;
};

// @fnv 0x00cf5cc0
void hkpTransformShapeRay::castRayWithCollectorImpl(const hkpShapeRayCastInputSse& input, const hkpCdBodyLocal& cdBody,
                                        hkpRayHitCollector& collector) const
{
    timerCommand("TtrcTransform");

    __m128 from = transformInversePos(m_kMotionTransform, input.m_vFrom.m_vComponents);
    hkpShapeRayCastInputSse subInput = input;
    subInput.m_vFrom.m_vComponents = from;
    subInput.m_vTo.m_vComponents = transformInversePos(m_kMotionTransform, input.m_vTo.m_vComponents);

    hkTransformSetMul t;
    t.SetProduct(*cdBody.m_pMotionState, reinterpret_cast<const hkTransform&>(m_kMotionTransform));

    hkpCdBodyLocal body;
    body.m_pMotionState = &t;
    body.m_parent = &cdBody;
    const hkpRayCastShape* child = static_cast<const hkpRayCastShape*>(m_pContainedShape.m_pContainedShape);
    body.m_pCollisionShape = child;
    body.m_uiCollisionShapeKey = 0;
    child->castRayWithCollector(subInput, body, collector);

    timerCommand("Et");
}

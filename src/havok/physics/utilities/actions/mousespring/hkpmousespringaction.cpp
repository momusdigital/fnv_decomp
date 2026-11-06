
// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/mousespring/hkpmousespringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMouseSpringAction.h"

struct FUN_00d2b1f0
{
    void __thiscall EntityRemovedCallback(int);
};

struct FUN_00cbb1c0 : FUN_00d2b1f0
{
    void __thiscall Method(int);
};

// @fnv 0x00cbb1c0
void __thiscall FUN_00cbb1c0::Method(int aiValue)
{
    EntityRemovedCallback(aiValue);
    *(int*)((char*)this + 0x18) = 0;
}

struct FUN_00cbb1b0_Class
{
    char pad0[0x48];
    hkReal m_fMaxRelativeForce;
    void __thiscall FUN_00cbb1b0(hkReal a);
};

// @fnv 0x00cbb1b0
void FUN_00cbb1b0_Class::FUN_00cbb1b0(hkReal a)
{
    m_fMaxRelativeForce = a;
}

extern "C" int DAT_01268a14;

// @fnv 0x00cbb8a0
int __cdecl getClassType()
{
    return (int)&DAT_01268a14;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern int DAT_010c8e94;
extern int DAT_010c476c;
extern float DAT_0101b2d0;
extern float DAT_0104da48;
extern const char str_011b1f3c[];

struct Ms_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* n);
    virtual void ReturnMemory(void* p, int n);
};
struct Ms_Tls
{
    int u0;
    int u1;
    int u2;
    int u3;
    Ms_Heap* heap;
};
Ms_Tls* __cdecl FUN_00c85750();

struct Ms_ArrInit
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};
struct Ms_Arr
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};

struct Ms_Sphere
{
    int v0;
    int v1;
    int v2;
    int type;
    float radius;
    int u5;
    int u6;
    int u7;
    void __thiscall FUN_00cd8160(float r);
};
struct Ms_Xf
{
    __m128 c0;
    __m128 c1;
    __m128 c2;
    __m128 t;
};
struct Ms_Body
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    void __thiscall FUN_00cd2d80(Ms_Sphere* s, Ms_Xf* x, int parent);
};
Ms_Xf* __cdecl FUN_00cd4b50();

struct Ms_Input
{
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    __m128 q0;
    __m128 q1;
    __m128 q2;
};
struct Ms_Coll
{
    int* vptr;
    float early;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    float dist;
    int hit;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int key;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};

struct Ms_Shape
{
    int u0;
    int u1;
    int u2;
    int type;
};
struct Ms_Disp
{
    int unk00;
};
struct Ms_World
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
    Ms_Input* input;
    int unk7c;
    Ms_Disp* disp;
};
struct Ms_Ent
{
    int u0;
    int u1;
    Ms_World* world;
    int u3;
    Ms_Shape* shape;
};
typedef void(__cdecl* Ms_Fn)(Ms_Body*, void*, Ms_Input*, Ms_Coll*);
struct Ms_B
{
    void __thiscall FUN_00d2b260(void* e, int z);
};
struct Ms_N
{
    void __thiscall FUN_00cb0c10(const char* s);
};
extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_load_ps(const float*);
}
struct Fv
{
    float x;
    float y;
    float z;
    float w;
};
struct Ms_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Fv pos;
    Fv mouse;
    float damping;
    float elasticity;
    float maxRel;
    float objDamping;
    int shapeKey;
    Ms_ArrInit cb;
    Ms_cls* FUN_00cbb560(__m128* a0, __m128* a1, float a2, float a3, float a4, Ms_Ent* a5, Ms_Arr* a6);
};

// Initializes the Ms_cls object with position, mouse, and damping parameters, copies an array, and computes a shape key via a collision test against the world.
// @fnv 0x00cbb560
Ms_cls* Ms_cls::FUN_00cbb560(__m128* apPos, __m128* apMouse, float afDamping, float afElasticity, float afObjDamping,
                             Ms_Ent* apEnt, Ms_Arr* apArr)
{
    ((Ms_B*)this)->FUN_00d2b260(apEnt, 0);
    *(int**)this = &DAT_010c8e94;
    _mm_store_ps(&pos.x, *apPos);
    _mm_store_ps(&mouse.x, *apMouse);
    damping = afDamping;
    elasticity = afElasticity;
    objDamping = afObjDamping;
    cb.init();
    maxRel = 250.0f;
    if (apArr)
    {
        Ms_Heap& h = *FUN_00c85750()->heap;
        int cap = cb.m_cap & 0x3fffffff;
        if (cap < apArr->m_iElementCount)
        {
            if ((cb.m_cap & 0x80000000) == 0)
                h.ReturnMemory(cb.m_data, cap * 4);
            int n = apArr->m_iElementCount * 4;
            cb.m_data = (int*)h.AllocateBufferWithSize(&n);
            cb.m_cap = n / 4;
        }
        int cnt = apArr->m_iElementCount;
        cb.m_iElementCount = cnt;
        int* dst = cb.m_data;
        int* src = apArr->m_data;
        for (int i = 0; i < cnt; i++)
            dst[i] = src[i];
    }
    Ms_World* w = apEnt->world;
    shapeKey = -1;
    if (w)
    {
        Ms_Sphere sph;
        sph.FUN_00cd8160(1.0f);
        Ms_Xf* ident = FUN_00cd4b50();
        Ms_Xf xf;
        xf.c0 = ident->c0;
        xf.c1 = ident->c1;
        xf.c2 = ident->c2;
        xf.t = *apMouse;
        Ms_Body body;
        body.FUN_00cd2d80(&sph, &xf, 0);
        Ms_Disp* d = w->disp;
        unsigned char t = *((unsigned char*)d + (((sph.type + 13) << 5) + apEnt->shape->type));
        Ms_Fn fn = *(Ms_Fn*)((char*)d + t * 20 + 0x9a8);
        Ms_Input in;
        Ms_Input* src = w->input;
        in.i0 = src->i0;
        in.i1 = src->i1;
        in.i2 = src->i2;
        in.i3 = src->i3;
        in.i4 = src->i4;
        in.i5 = src->i5;
        in.q0 = src->q0;
        in.q1 = src->q1;
        in.q2 = src->q2;
        Ms_Coll coll;
        coll.dist = DAT_0104da48;
        coll.early = DAT_0104da48;
        coll.vptr = &DAT_010c476c;
        coll.hit = 0;
        fn(&body, &apEnt->shape, &in, &coll);
        if (coll.hit)
            shapeKey = coll.key;
    }
    ((Ms_N*)&unk14)->FUN_00cb0c10(str_011b1f3c);
    return this;
}

namespace fnv_00cbb790 {
struct hkAllocatorCBB7
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCBB7
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    hkAllocatorCBB7* m_pStreamAllocator;
};
void* __cdecl FUN_00c85750();
inline hkAllocatorCBB7& heapCBB7()
{
    return *((hkMemoryRouterCBB7*)FUN_00c85750())->m_pStreamAllocator;
}

template <typename T> inline void copyCBB7(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <typename T> struct hkArrayCBB7
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline hkArrayCBB7& operator=(const hkArrayCBB7& kOther)
    {
        hkAllocatorCBB7& kAlloc = heapCBB7();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = kOther.m_iElementCount * sizeof(T);
            m_data = (T*)kAlloc.AllocateBufferWithSize(iNumBytes);
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        copyCBB7(m_data, kOther.m_data, m_iElementCount);
        return *this;
    }
};

struct __declspec(align(16)) hkVector4CBB7
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB7& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkpEntity;

class FUN_00cbb4e0 : public hkpUnaryAction
{
  public:
    hkUint32 m_1c;
    hkVector4CBB7 m_kMousePositionInWorld;
    hkVector4CBB7 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    hkUint32 m_uiCollisionShapeKey;
    hkArrayCBB7<void*> m_kAppliedCallbacks;

    FUN_00cbb4e0(hkpEntity* pkEntity) throw();

    void* operator new(unsigned int uiSize)
    {
        hkMemoryRouterCBB7* pkRouter = (hkMemoryRouterCBB7*)FUN_00c85750();
        hkReferencedObject* pkObj = (hkReferencedObject*)pkRouter->m_pStreamAllocator->AllocateMemoryBlock(uiSize);
        pkObj->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return pkObj;
    }

    FUN_00cbb4e0* CloneForEntity(const hkArrayCBB7<hkpEntity*>& kNewEntities,
                                 const hkArrayCBB7<void*>& kNewPhantoms) const throw();
};

// Creates a copy of this action for a single entity, returning null if the entity count is not one or any phantoms are present.
// @fnv 0x00cbb790
FUN_00cbb4e0* FUN_00cbb4e0::CloneForEntity(const hkArrayCBB7<hkpEntity*>& kNewEntities,
                                           const hkArrayCBB7<void*>& kNewPhantoms) const throw()
{
    if (kNewEntities.GetLogicalSize() != 1)
        return 0;
    if (kNewPhantoms.GetLogicalSize() != 0)
        return 0;

    FUN_00cbb4e0* pkAction = new FUN_00cbb4e0(kNewEntities[0]);
    pkAction->m_kMousePositionInWorld = m_kMousePositionInWorld;
    pkAction->m_kGrabPointInBodySpace = m_kGrabPointInBodySpace;
    pkAction->m_fSpringDamping = m_fSpringDamping;
    pkAction->m_fSpringElasticity = m_fSpringElasticity;
    pkAction->m_fMaxRelativeForce = m_fMaxRelativeForce;
    pkAction->m_fTau = m_fTau;
    pkAction->m_ulUserData = m_ulUserData;
    pkAction->m_uiCollisionShapeKey = m_uiCollisionShapeKey;
    pkAction->m_kAppliedCallbacks = m_kAppliedCallbacks;
    return pkAction;
}
}  // namespace fnv_00cbb790

class FUN_00d01a60
{
  public:
    FUN_00d01a60();
    int unk00[11];
};

extern const float DAT_01012054;

class hkpCdBodyCD2D
{
  public:
    hkpCdBodyCD2D(const void* shape, const void* motionState)
    {
        m_pCollisionShape = shape;
        m_pMotionState = motionState;
        m_parent = 0;
        m_uiCollisionShapeKey = 0xffffffff;
    }
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCD2D* m_parent;
};

class hkpBroadPhaseHandleCD2D
{
  public:
    hkpBroadPhaseHandleCD2D()
    {
        m_iOwnerObjectOffset = 0;
    }
    unsigned int m_iOwnerObjectOffset;
};

class hkpTypedBroadPhaseHandleCD2D : public hkpBroadPhaseHandleCD2D
{
  public:
    hkpTypedBroadPhaseHandleCD2D(int type)
    {
        m_type = (signed char)type;
        m_ucObjectQualityType = -1;
        m_uiCollisionFilterData = 0;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* owner)
    {
        int offset = (int)((char*)owner - (char*)this);
        m_iOwnerOffset = (signed char)offset;
    }
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};

class FUN_00cd2d80 : public hkpCdBodyCD2D
{
  public:
    FUN_00cd2d80(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleCD2D m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};

// Constructs the body from shape and motionState, builds the broad phase handle with type, sets its owner pointer, and sets a default allowed penetration depth.
// @fnv 0x00cd2d80
FUN_00cd2d80::FUN_00cd2d80(const void* apCollisionShape, const void* motionState, int aiBroadPhaseType)
    : hkpCdBodyCD2D(apCollisionShape, motionState), m_iOwnerOffset(0), m_kBroadPhaseHandle(aiBroadPhaseType),
      m_fAllowedPenetrationDepth(DAT_01012054)
{
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

struct Ms_Tls;
Ms_Tls* FUN_00c85750();

struct Ms_HeapX
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned short n);
    virtual void v0c();
    virtual void v10(int p, int n);
};

struct Cls
{
    void* m_vt;          // 0x00
    int m_04;            // 0x04 (word)
    char m_pad08[0x4c];  // to 0x54
    int m_54;
    int m_58;
    int m_5c;
    Cls* FUN_00cbb8b0(int flags);
    void FUN_00d2b2b0();
};

// Clears the array at m_54 and releases its buffer unless flagged, calls FUN_00d2b2b0, and frees this through the TLS heap when bit 0 of flags is set.
// @fnv 0x00cbb8b0
Cls* Cls::FUN_00cbb8b0(int flags)
{
    Ms_Tls* tls = FUN_00c85750();
    Ms_HeapX* heap = *(Ms_HeapX**)((char*)tls + 0x10);
    int n = m_5c;
    m_58 = 0;
    if (!((unsigned int)n & 0x80000000u))
        heap->v10(m_54, (n & 0x3fffffff) * 4);
    m_54 = 0;
    m_5c = 0x80000000;
    FUN_00d2b2b0();
    if (flags & 1)
    {
        Ms_Tls* tls2 = FUN_00c85750();
        Ms_HeapX* heap2 = *(Ms_HeapX**)((char*)tls2 + 0x10);
        heap2->v08(this, (unsigned short)m_04);
    }
    return this;
}

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_load_ps1(const float*);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern "C"
{
}

extern const __m128 DAT_01017d10;
extern const float DAT_01017d00;

struct __declspec(align(16)) hkVector4CBB1
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB1& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class UnkCall
{
  public:
    int unk00;
    int unk04;
    int m_pOwningWorld;

    void FUN_00c9c1d0();
};

class hkpPositionTrackerCBB1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    UnkCall* m_pOwnerObject;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4CBB1 m_vContactPosition;

    void FUN_00cbb150(const hkVector4CBB1& kPosition);
};

// @fnv 0x00cbb150
void hkpPositionTrackerCBB1::FUN_00cbb150(const hkVector4CBB1& kPosition)
{
    __m128 d = _mm_sub_ps(kPosition.m_vComponents, m_vContactPosition.m_vComponents);
    d = _mm_and_ps(d, DAT_01017d10);
    __m128 eps = _mm_load_ps1(&DAT_01017d00);
    int iMask = _mm_movemask_ps(_mm_cmple_ps(d, eps));
    if ((iMask & 7) != 7)
    {
        if (m_pOwnerObject && m_pOwnerObject->m_pOwningWorld)
            m_pOwnerObject->FUN_00c9c1d0();
    }
    m_vContactPosition = kPosition;
}

extern "C" __m128 _mm_setzero_ps(void);
struct FUN_00cbb4e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0C;
    unsigned int unk10;
    hkStringPtr m_name;
    void* m_pEntity;
    unsigned int unk1C;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    unsigned int m_uiCollisionShapeKey;
    hkArray<char> m_kAppliedCallbacks;
    FUN_00cbb4e0(int arg);
};
extern float DAT_01016248, DAT_01017870, DAT_0101ffc0;
// Initializes the hkpMouseSpringAction fields with default spring constants, zeroed vectors, and the action name.
// @fnv 0x00cbb4e0
FUN_00cbb4e0::FUN_00cbb4e0(int arg)
{
    ((Ms_B*)this)->FUN_00d2b260((void*)arg, 0);
    m_fSpringDamping = DAT_01016248;
    unk00 = (void*)&DAT_010c8e94;
    m_fSpringElasticity = DAT_01017870;
    __m128 zero = _mm_setzero_ps();
    m_fMaxRelativeForce = DAT_0101b2d0;
    m_fTau = DAT_0101ffc0;
    *(char* volatile*)&m_kAppliedCallbacks.m_data = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iElementCount = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iCapacityState = 0x80000000;
    _mm_store_ps((float*)&m_kMousePositionInWorld, zero);
    _mm_store_ps((float*)&m_kGrabPointInBodySpace, zero);
    m_uiCollisionShapeKey = 0xFFFFFFFF;
    ((Ms_N*)&m_name)->FUN_00cb0c10("hkpMouseSpringAction");
}

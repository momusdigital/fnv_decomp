
// src/havok/common/base/types/geometry/localframe/hklocalframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/localframe/hklocalframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkLocalFrame.h"

struct DDCC60World
{
    void removeReference(void);
};

struct hkReferencedObject_ : public hkReferencedObject
{
    void RetainReference(void);
};

struct FUN_00df6550
{
    void AddObjectReference(hkReferencedObject* p);
};

// @fnv 0x00df6550
void FUN_00df6550::AddObjectReference(hkReferencedObject* apObject)
{
    if (apObject)
        ((hkReferencedObject_*)apObject)->RetainReference();
    hkReferencedObject_* pOldObject = *(hkReferencedObject_**)((char*)this + 0x60);
    if (pOldObject)
        ((DDCC60World*)pOldObject)->removeReference();
    *(hkReferencedObject_**)((char*)this + 0x60) = (hkReferencedObject_*)apObject;
}

struct FUN_00df6690_StandIn
{
    char pad[0x50];
    int** m_table;

    int* getChildFrame(int index);
};

// @fnv 0x00df6690
int* FUN_00df6690_StandIn::getChildFrame(int index)
{
    return m_table[index];
}

struct FnvCpu_FUN_00df6680_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    int value;
    int FUN_00df6680();
};
// @fnv 0x00df6680
int FnvCpu_FUN_00df6680_CpuObject::FUN_00df6680()
{
    return value;
}

struct __declspec(align(16)) FNVTransform
{
    float m[16];
    void FUN_00cb2240(const FNVTransform* parent, const FNVTransform* local);
};
class FUN_00df66a0_Node
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(FNVTransform* dest);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual FUN_00df66a0_Node* v8();
    void GetWorldTransform(FNVTransform* dest);
};
// Computes the node's world transform: if it has a parent, combines the parent's transform with the local transform, otherwise writes the local transform to dest.
// @fnv 0x00df66a0
void FUN_00df66a0_Node::GetWorldTransform(FNVTransform* dest)
{
    if (v8())
    {
        FNVTransform parent;
        FNVTransform local;
        v8()->GetWorldTransform(&parent);
        v3(&local);
        dest->FUN_00cb2240(&parent, &local);
    }
    else
    {
        v3(dest);
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkSimdRealDF65
{
    __m128 m_vValue;

    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct hkVector4DF65
{
    __m128 m_vComponents;

    void setSub4(const hkVector4DF65& a, const hkVector4DF65& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealDF65 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        hkSimdRealDF65 r;
        r.m_vValue = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum));
        return r;
    }
    void FUN_00c7f690(const struct hkTransformDF65& kTransform, const hkVector4DF65& kPos);
};

struct hkTransformDF65
{
    hkVector4DF65 m_kColumn0;
    hkVector4DF65 m_kColumn1;
    hkVector4DF65 m_kColumn2;
    hkVector4DF65 m_vTranslation;
};

template <class T> struct hkArrayDF65
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpDF65Node;

class hkpDF65Collector
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AddHit(hkpDF65Node* pkNode, float fDistance);
};

class hkpDF65Child
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void query(const hkVector4DF65& kLocalPos, float fRadius, hkpDF65Collector* pkCollector);
};

class hkpDF65Base
{
  public:
    virtual ~hkpDF65Base();
};

class hkpDF65Node : public hkpDF65Base
{
  public:
    void getNearbyFrames(const hkVector4DF65& kPos, float fRadius, hkpDF65Collector* pkCollector);

    unsigned int unk04, unk08, unk0C;
    hkTransformDF65 m_kMotionTransform;
    hkArrayDF65<hkpDF65Child*> m_children;
};

// @fnv 0x00df65d0
void hkpDF65Node::getNearbyFrames(const hkVector4DF65& kPos, float afRadius, hkpDF65Collector* pkCollector)
{
    hkVector4DF65 kDiff;
    kDiff.setSub4(kPos, m_kMotionTransform.m_vTranslation);
    const float fDistance = kDiff.length3();
    if (fDistance <= afRadius)
    {
        pkCollector->AddHit(this, fDistance);
    }
    if (m_children.GetLogicalSize() > 0)
    {
        hkVector4DF65 kLocalPos;
        kLocalPos.FUN_00c7f690(m_kMotionTransform, kPos);
        for (int i = 0; i < m_children.GetLogicalSize(); i++)
        {
            m_children[i]->query(kLocalPos, afRadius, pkCollector);
        }
    }
}

// stand-in for the 64-byte SSE transform the original passes by address (movaps rows in callee);
// pack's hkMatrix4 is pack(1)/4-aligned, so a new 16-aligned type is used here
struct df6710_row
{
    float x, y, z, w;
};
struct __declspec(align(16)) df6710_vec16
{
    df6710_row r0, r1, r2, r3;
};

// callee of the direct call in the loop (reads edi as 4 float4 rows, buf as one float4)
struct df6710_mat
{
    void FUN_00c7f640(df6710_vec16* v, df6710_mat* m);
};

// object returned per iteration; slot 0xc fetches the vector, slot 0x20 walks to the next one
struct df6710_frame
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03(df6710_vec16* v);
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual df6710_frame* unk08();
};

// 'this' of FUN_00df6710: vtable slot 0x14 registers the matrix, slot 0x20 returns first frame
struct df6710_self
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05(df6710_mat* m);
    virtual void unk06();
    virtual void unk07();
    virtual df6710_frame* unk08();
    void FUN_00df6710(df6710_mat* m);
};

// Calls unk05 with m, then walks the unk08 chain and passes each unk03 output and m to FUN_00c7f640.
// @fnv 0x00df6710
void df6710_self::FUN_00df6710(df6710_mat* apMatrix)
{
    df6710_vec16 buf;
    unk05(apMatrix);
    for (df6710_frame* p = unk08(); p; p = p->unk08())
    {
        p->unk03(&buf);
        apMatrix->FUN_00c7f640(&buf, apMatrix);
    }
}

namespace fnv_00df6770 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } components;
};
struct FrameVector
{
    __m128 data;
};
struct __declspec(align(16)) FrameTransform
{
    FrameVector column0, column1, column2, translation;
};
struct LocalFrameStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getTransform(FrameTransform* result);
    void GetTranslation(FrameVector* result);
};
// Calls getTransform to fill a local FrameTransform and copies its translation column into the result FrameVector.
// @fnv 0x00df6770
void LocalFrameStandIn::GetTranslation(FrameVector* apTranslation)
{
    FrameTransform localTransform;
    getTransform(&localTransform);
    apTranslation->data = localTransform.translation.data;
}
}  // namespace fnv_00df6770

struct __declspec(align(16)) hkVector4DF67
{
    __m128 m_vComponents;

    hkVector4DF67()
    {}
    hkVector4DF67(const hkVector4DF67& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkTransformDF67
{
    hkVector4DF67 m_kColumn0;
    hkVector4DF67 m_kColumn1;
    hkVector4DF67 m_kColumn2;
    hkVector4DF67 m_vTranslation;
};

class FUN_00df67a0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkTransformDF67 m_kMotionTransform;

    hkTransformDF67 GetMotionTransform() const;
};

// Returns the m_kMotionTransform member of the class.
// @fnv 0x00df67a0
hkTransformDF67 FUN_00df67a0_cls::GetMotionTransform() const
{
    return m_kMotionTransform;
}

class hkMemoryAllocatorDF6
{
  public:
    virtual ~hkMemoryAllocatorDF6();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterDF6
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDF6* m_pTemp;
    hkMemoryAllocatorDF6* m_pStreamAllocator;
    hkMemoryAllocatorDF6& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDF6* __cdecl FUN_00c85750() throw();

struct hkRefDF6
{
    void FUN_00c905b0() throw();
};

template <class T> class hkArrayDF6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayDF6() throw()
    {
        hkMemoryAllocatorDF6& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00cb0c00_class
{
    const char* m_pcText;
    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class() throw()
    {
        FUN_00cb0c00();
    }
};

class hkBaseObjectDF6
{
  public:
    virtual ~hkBaseObjectDF6()
    {}
};

class hkReferencedObjectDF6 : public hkBaseObjectDF6
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00df67d0 : public hkReferencedObjectDF6
{
  public:
    int unk08;
    int unk0C;
    float m_kMotionTransform[16];
    hkArrayDF6<hkRefDF6*> m_children;
    hkRefDF6* m_pParentFrame;
    hkRefDF6* m_kGroupData;
    FUN_00cb0c00_class m_name;

    virtual ~FUN_00df67d0();
};

// Calls FUN_00c905b0 on each entry in m_children and on m_kGroupData when it is nonnull.
// @fnv 0x00df67d0
FUN_00df67d0::~FUN_00df67d0()
{
    int n = m_children.m_iElementCount;
    for (int i = 0; i < n; i++)
        m_children.m_data[i]->FUN_00c905b0();
    if (m_kGroupData)
        m_kGroupData->FUN_00c905b0();
}

struct FnvCpu_FUN_00df6580_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
    __m128 field30;
};
struct FnvCpu_FUN_00df6580_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    void CopyFrom(FnvCpu_FUN_00df6580_CpuData0* input0);
};
// Copies the four __m128 fields from the input CpuData0 struct into the corresponding fields of the CpuObject.
// @fnv 0x00df6580
void FnvCpu_FUN_00df6580_CpuObject::CopyFrom(FnvCpu_FUN_00df6580_CpuData0* apCpuData)
{
    this->field10 = apCpuData->field00;
    this->field20 = apCpuData->field10;
    this->field30 = apCpuData->field20;
    this->field40 = apCpuData->field30;
}

namespace fnv_00df65b0 {
struct __declspec(align(16)) hkVector4DF65
{
    __m128 m_vComponents;

    hkVector4DF65()
    {}
    hkVector4DF65(const hkVector4DF65& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class FUN_00df65b0_cls
{
  public:
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
    hkVector4DF65 m_vector;

    hkVector4DF65 FUN_00df65b0() const;
};

// @fnv 0x00df65b0
hkVector4DF65 FUN_00df65b0_cls::FUN_00df65b0() const
{
    return m_vector;
}
}  // namespace fnv_00df65b0


// src/havok/physics/collide/shape/deprecated/convexlist/hkpconvexlistshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexlist/hkpconvexlistshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexListShape.h"

struct FUN_00d5e2e0_Class
{
    int GetNextKey(int key);
};

// @fnv 0x00d5e2e0
int FUN_00d5e2e0_Class::GetNextKey(int key)
{
    ++key;
    if (key >= *(int*)((char*)this + 0x34))
        key = -1;
    return key;
}

// Iterates the objects in the array at offset 0x44 up to the count at 0x48, calling each object's virtual method at vtable offset 0x2c and summing the results.
// @fnv 0x00d5e190
int __fastcall SumVirtualResults(void* self)
{
    int iTotal = 0;
    int i = 0;
    char* p = (char*)self;
    if (*(int*)(p + 0x48) > 0)
    {
        do
        {
            void* pObject = *(void**)(*(int*)(p + 0x44) + i * 4);
            int(__fastcall * fn)(void*) = *(int(__fastcall**)(void*))(*(int*)pObject + 0x2c);
            iTotal += fn(pObject);
            i++;
        } while (i < *(int*)(p + 0x48));
    }
    return iTotal;
}

// @fnv 0x00d5e2f0
int __fastcall FUN_00d5e2f0(char* self, int edx, int key, int pad)
{
    return ((int*)((int*)self)[0xc])[key];
}

void __cdecl FUN_00d5e7c0();

struct FUN_00d5e850_Allocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void deallocate(void* object, unsigned short size);
};

struct FUN_00d5e850_MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00d5e850_Allocator* allocator;
};

FUN_00d5e850_MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d5e850_Class
{
    void* vtable;
    unsigned short field_04;
    FUN_00d5e850_Class* Destroy(int flags);
};

// Calls FUN_00d5e7c0, then if flags has bit 1 set, frees this via the memory router's allocator using field_04 as size, and returns this.
// @fnv 0x00d5e850
FUN_00d5e850_Class* FUN_00d5e850_Class::Destroy(int flags)
{
    FUN_00d5e7c0();

    if (flags & 1)
    {
        FUN_00d5e850_MemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->allocator->deallocate(this, field_04);
    }

    return this;
}

struct FUN_00d5e0f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    char* FUN_00d5e0f0();
};

// @fnv 0x00d5e0f0
char* FUN_00d5e0f0_cls::FUN_00d5e0f0()
{
    return this != 0 ? (char*)this + 0x14 : 0;
}

// @fnv 0x00d5e0d0
int __cdecl FUN_00d5e0d0()
{
    return 0;
}

// @fnv 0x00d5e0e0
int __stdcall FUN_00d5e0e0(int)
{
    return 0;
}

class hkTargetD5E1
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void run(void* a);
};

struct hkHolderD5E1
{
    hkTargetD5E1* m_target;
};

class hkObjD5E1
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    hkHolderD5E1* m_holder;

    void FUN_00d5e180(void* a);
};

// @fnv 0x00d5e180
void hkObjD5E1::FUN_00d5e180(void* a)
{
    m_holder->m_target->run(a);
}

struct FUN_00d5e1c0_Shape
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual int GetElementCount();
    virtual void WriteElements(void* destination);
};
struct FUN_00d5e1c0_Collection
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40;
    FUN_00d5e1c0_Shape** elements;
    int count;
    void* __thiscall WriteToBuffer(void* destination);
};
// Writes each element's data into destination, advancing the cursor by each element's element count times 16 bytes.
// @fnv 0x00d5e1c0
void* __thiscall FUN_00d5e1c0_Collection::WriteToBuffer(void* destination)
{
    char* cursor = (char*)destination;
    for (int i = 0; i < count; ++i)
    {
        FUN_00d5e1c0_Shape* element = elements[i];
        element->WriteElements(cursor);
        cursor += element->GetElementCount() * 16;
    }
    return destination;
}

struct FUN_00d5e2d0_cls
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
    int FUN_00d5e2d0();
};
// @fnv 0x00d5e2d0
int FUN_00d5e2d0_cls::FUN_00d5e2d0()
{
    return unk34;
}

struct BSAudio
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};

BSAudio* FUN_00c85750();
void FUN_00c908c0(void* allocator, void* arrayPtr, int newCapacity, int elementSize);
void __fastcall FUN_00c90510(hkpConvexShape* shape);

struct ConvexList : hkpConvexListShape
{
    void SetChildren(hkpConvexShape** children, int numChildren);
};

// @fnv 0x00d5e6e0
void ConvexList::SetChildren(hkpConvexShape** children, int numChildren)
{
    hkArray<hkpConvexShape*>* pChildrenArray = &m_kChildShapes;
    BSAudio* audio = FUN_00c85750();
    void* allocator = audio->allocator;
    int iCapacity = pChildrenArray->m_iCapacityState & 0x3fffffff;
    if (iCapacity < numChildren)
    {
        iCapacity *= 2;
        if (numChildren >= iCapacity)
        {
            iCapacity = numChildren;
        }
        FUN_00c908c0(allocator, pChildrenArray, iCapacity, sizeof(hkpConvexShape*));
    }
    pChildrenArray->m_iElementCount = numChildren;
    m_fSphereRadius = children[0]->m_fSphereRadius;
    for (int i = 0; i < numChildren; i++)
    {
        pChildrenArray->m_data[i] = children[i];
        FUN_00c90510(children[i]);
    }
}

struct ShapeOutD5E
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    unsigned int m_key;
};
class hkpShapeD5E
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void unkv2C();
    virtual void unkv30();
    virtual void unkv34();
    virtual void unkv38();
    virtual void getChildData(const int* keys, int numKeys, ShapeOutD5E* out);
};
class ShapeListD5E
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
    int unk40;
    hkpShapeD5E** m_kChildShapes;
    void GetChildData(const unsigned short* keys, int numKeys, ShapeOutD5E* out);
};
// @fnv 0x00d5e100
void ShapeListD5E::GetChildData(const unsigned short* keys, int numKeys, ShapeOutD5E* out)
{
    for (int i = 0; i < numKeys; i++)
    {
        int key = keys[0];
        int childIdx = (unsigned short)key >> 8;
        int childKey = key & 0xff;
        m_kChildShapes[childIdx]->getChildData(&childKey, 1, out);
        out->m_key = ((out->m_key & 0xc0ffffff) + ((unsigned int)childIdx << 8)) | 0x3f000000;
        keys++;
        out++;
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);

extern const __m128 DAT_010c71d0;
static const float DAT_0104da48 = 3.40282e+38f;
static const float DAT_0104e148 = -3.40282e+38f;

struct hkVector4D5E3
{
    __m128 m_vComponents;

    void setMin4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    hkVector4D5E3()
    {}
    hkVector4D5E3(const hkVector4D5E3& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D5E3& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }
    void setAdd4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }
};

struct hkTransformD5E3
{
    hkVector4D5E3 m_kColumn0;
    hkVector4D5E3 m_kColumn1;
    hkVector4D5E3 m_kColumn2;
    hkVector4D5E3 m_vTranslation;
};

struct hkAabbD5E3
{
    hkVector4D5E3 m_kMinimumCorner;
    hkVector4D5E3 m_kMaximumCorner;

    void includeAabb(const hkAabbD5E3& kOther)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, kOther.m_kMinimumCorner);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, kOther.m_kMaximumCorner);
    }
};

extern hkTransformD5E3 DAT_01268370;

template <class T> struct hkArrayD5E3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectD5E3
{
  public:
    virtual ~hkBaseObjectD5E3() throw();
};

class hkReferencedObjectD5E3 : public hkBaseObjectD5E3
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD5E3 : public hkReferencedObjectD5E3
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransformD5E3& kLocalToWorld, float fTolerance, hkAabbD5E3& kOut) const = 0;

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpConvexListShapeD5E3 : public hkpShapeD5E3
{
  public:
    void UpdateCachedAabb(bool bUseCachedAabb);

    float m_fSphereRadius;
    float m_fMaximumRadius;
    unsigned int unk18, unk1C;
    hkVector4D5E3 m_kAabbHalfExtents;
    hkVector4D5E3 m_kAabbCenter;
    bool m_bUseCachedAabb;
    hkArrayD5E3<const hkpShapeD5E3*> m_kChildShapes;
};

// Stores bUseCachedAabb and, when true, computes m_kAabbCenter and m_kAabbHalfExtents from the union of child shape AABBs.
// @fnv 0x00d5e210
void hkpConvexListShapeD5E3::UpdateCachedAabb(bool bUseCachedAabb)
{
    m_bUseCachedAabb = bUseCachedAabb;
    if (bUseCachedAabb)
    {
        hkAabbD5E3 kAabb;
        kAabb.m_kMinimumCorner.SetAllComponents(DAT_0104da48);
        kAabb.m_kMaximumCorner.SetAllComponents(DAT_0104e148);
        for (int i = 0; i < m_kChildShapes.GetLogicalSize(); i++)
        {
            hkAabbD5E3 kChildAabb;
            m_kChildShapes[i]->getAabb(DAT_01268370, 0.0f, kChildAabb);
            kAabb.includeAabb(kChildAabb);
        }
        hkVector4D5E3 kTargetCenter;
        kTargetCenter.setAdd4(kAabb.m_kMinimumCorner, kAabb.m_kMaximumCorner);
        kTargetCenter.mul4(DAT_010c71d0);
        m_kAabbCenter = kTargetCenter;
        hkVector4D5E3 m_kPoint2;
        m_kPoint2.setSub4(kAabb.m_kMaximumCorner, kAabb.m_kMinimumCorner);
        m_kPoint2.mul4(DAT_010c71d0);
        m_kAabbHalfExtents = m_kPoint2;
    }
}

namespace fnv_00d5e3c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);

struct hkVector4D5E3
{
    __m128 m_vComponents;

    void setMin4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVector4D5E3& a, const hkVector4D5E3& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkTransformD5E3
{
    hkVector4D5E3 m_kColumn0;
    hkVector4D5E3 m_kColumn1;
    hkVector4D5E3 m_kColumn2;
    hkVector4D5E3 m_vTranslation;
};

struct hkAabbD5E3
{
    hkVector4D5E3 m_kMinimumCorner;
    hkVector4D5E3 m_kMaximumCorner;

    void includeAabb(const hkAabbD5E3& kOther)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, kOther.m_kMinimumCorner);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, kOther.m_kMaximumCorner);
    }
};

void __cdecl FUN_00d26230(const hkTransformD5E3& kLocalToWorld, const hkVector4D5E3& m_kPoint2,
                          const hkVector4D5E3& kTargetCenter, float fExtraRadius, hkAabbD5E3& kAabbOut);

template <class T> struct hkArrayD5E3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectD5E3
{
  public:
    virtual ~hkBaseObjectD5E3() throw();
};

class hkReferencedObjectD5E3 : public hkBaseObjectD5E3
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD5E3 : public hkReferencedObjectD5E3
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransformD5E3& kLocalToWorld, float fTolerance, hkAabbD5E3& kOut) const = 0;

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpConvexListShapeD5E3 : public hkpShapeD5E3
{
  public:
    void FUN_00d5e3c0(const hkTransformD5E3& kLocalToWorld, float fTolerance, hkAabbD5E3& kOut) const;

    float m_fSphereRadius;
    float m_fMaximumRadius;
    unsigned int unk18, unk1C;
    hkVector4D5E3 m_kAabbHalfExtents;
    hkVector4D5E3 m_kAabbCenter;
    bool m_bUseCachedAabb;
    hkArrayD5E3<const hkpShapeD5E3*> m_kChildShapes;
};

// Computes the world-space AABB of a convex list shape, using cached extents when available or merging child shape AABBs otherwise.
// @fnv 0x00d5e3c0
void hkpConvexListShapeD5E3::FUN_00d5e3c0(const hkTransformD5E3& kLocalToWorld, float fTolerance,
                                          hkAabbD5E3& kOut) const
{
    if (m_bUseCachedAabb)
    {
        FUN_00d26230(kLocalToWorld, m_kAabbHalfExtents, m_kAabbCenter, m_fSphereRadius + fTolerance, kOut);
        return;
    }

    m_kChildShapes[0]->getAabb(kLocalToWorld, fTolerance, kOut);
    hkAabbD5E3 kTemp;
    for (int i = 1; i < m_kChildShapes.GetLogicalSize(); i++)
    {
        m_kChildShapes[i]->getAabb(kLocalToWorld, fTolerance, kTemp);
        kOut.includeAabb(kTemp);
    }
}
}  // namespace fnv_00d5e3c0

template <class T> struct hkArrayD5E7
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD5E7() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkReferencedObjectD5E7
{
  public:
    hkReferencedObjectD5E7()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD5E7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkShapeD5E7 : public hkReferencedObjectD5E7
{
  public:
    hkShapeD5E7(int type) : m_ulUserData(0), m_type(type)
    {
        m_fSphereRadius = 0.0f;
    }
    virtual ~hkShapeD5E7() throw()
    {}
    int m_ulUserData;
    int m_type;
    float m_fSphereRadius;
};

class hkContainerD5E7
{
  public:
    hkContainerD5E7()
    {}
    virtual ~hkContainerD5E7() throw()
    {}
    float m_vScale;
    int unk1C[10];
};

class FUN_00d5e750 : public hkShapeD5E7, public hkContainerD5E7
{
  public:
    FUN_00d5e750(void* a, void* b) throw();
    virtual ~FUN_00d5e750() throw();

    void SetChildren(void* a, void* b) throw();
    void UpdateCachedAabb(int flag) throw();

    hkArrayD5E7<int> m_ppData;
};

// @fnv 0x00d5e750
FUN_00d5e750::FUN_00d5e750(void* a, void* b) throw() : hkShapeD5E7(0x16)
{
    m_vScale = 1.0f;
    SetChildren(a, b);
    UpdateCachedAabb(1);
}

namespace fnv_00d5e7c0 {
struct hkAllocatorD5E7
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD5E7
{
    int unk00, unk04, unk08, unk0C;
    hkAllocatorD5E7* m_pkHeap;
    hkAllocatorD5E7& heap()
    {
        return *m_pkHeap;
    }
};

namespace hkRouterD5E7 {
extern "C" hkMemoryRouterD5E7* __cdecl FUN_00c85750() throw();
}

template <typename T> struct hkArrayD5E7
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void _clearAndDeallocate(hkAllocatorD5E7& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD5E7() throw()
    {
        _clearAndDeallocate(hkRouterD5E7::FUN_00c85750()->heap());
    }
};

class hkRefD5E7
{
  public:
    void FUN_00c905b0() throw();
};

class hkBaseAD5E7
{
  public:
    virtual ~hkBaseAD5E7() throw()
    {}
    int unk04, unk08, unk0C, unk10;
};

class hkBaseBD5E7
{
  public:
    virtual ~hkBaseBD5E7() throw()
    {}
};

class FUN_00d5e7c0 : public hkBaseAD5E7, public hkBaseBD5E7
{
  public:
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    hkArrayD5E7<hkRefD5E7*> m_kChildInfoList;

    virtual ~FUN_00d5e7c0() throw();
};

// Destructor: calls FUN_00c905b0 on each hkRefD5E7 pointer in m_kChildInfoList.
// @fnv 0x00d5e7c0
FUN_00d5e7c0::~FUN_00d5e7c0() throw()
{
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
    {
        m_kChildInfoList.m_data[i]->FUN_00c905b0();
    }
}
}  // namespace fnv_00d5e7c0

extern int _FUN_00d06f80(void*, int);
extern int DAT_01268940;
extern const char str_010cc3a4[];

struct S00d5e480_Visitor
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void visit(int, void*, int);
    virtual void slot10();
    virtual void visitArray(int, const char*, void*, int, int);

    int unk04;
    int unk08;
    int unk0c;
    char field10;
};

struct S00d5e480_Class
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
    void** children;
    int count;
    int capacity;

    void FUN_00c90360(S00d5e480_Visitor*, int*);
    void FUN_00d5e480(S00d5e480_Visitor*, int);
};

// @fnv 0x00d5e480
void S00d5e480_Class::FUN_00d5e480(S00d5e480_Visitor* visitor, int)
{
    if (!(capacity & 0x80000000) || visitor->field10 != 0)
    {
        void** childArray = children;
        int allocationSize = (capacity & 0x3fffffff) * 4;
        int allocated = _FUN_00d06f80(childArray, allocationSize);
        visitor->visitArray(3, str_010cc3a4, children, count * 4, allocated);
    }

    {
        int index = 0;
        while (index < count)
        {
            visitor->visit(0, children[index], 0);
            ++index;
        }
    }

    FUN_00c90360(visitor, &DAT_01268940);
}

#include <windows.h>
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

struct Node;
struct Coll
{
    virtual void v00();
    virtual void v04();
    virtual int First();
    virtual int Next(int id);
    virtual void v10();
    virtual Node* Get(int id, void* buf);
};
struct State
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int slots[8];
    int depth;
};
struct Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual bool* FUN_00d5e500(bool* __restrict result, void* other, State* st);
    DWORD unk04, unk08, unk0C, unk10;
    Coll coll;
};
struct __declspec(align(16)) Buf
{
    DWORD d[128];
};

// Recursively searches coll children for a match, records the selected id in st->slots, and sets *result to whether one was found.
// @fnv 0x00d5e500
bool* Node::FUN_00d5e500(bool* __restrict result, void* other, State* st)
{
    Buf buf;
    struct F
    {
        bool a, b, c, d;
    } found;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        volatile DWORD ticks;
        pRec->m_pName = "TtrcCxList";
        _ReadWriteBarrier();
        ticks = (DWORD)__rdtsc();
        pRec->m_iTick = ticks;
        pBuf->m_pCur = pRec + 1;
    }
    st->depth++;
    int iSelected = -1;
    for (int id = coll.First(); id != -1; id = coll.Next(id))
    {
        coll.Get(id, &buf)->FUN_00d5e500(&found.d, other, st);
        if (found.d)
            iSelected = id;
    }
    st->depth--;
    if (iSelected != -1)
        st->slots[st->depth] = iSelected;
    *result = iSelected != -1;
    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        volatile DWORD ticks;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        ticks = (DWORD)__rdtsc();
        pRec->m_iTick = ticks;
        pBuf->m_pCur = pRec + 1;
    }
    return result;
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern DWORD hkMonitorStream__tlsIndex;

struct StringCursor
{
    struct CommandTimingEntry
    {
        const char* m_pCommandName;
        hkUint32 m_uiStartTicks;
        hkUint32 m_uiEndTicks;
        inline void setTime()
        {
            _ReadWriteBarrier();
            volatile hkUint32 ticks = hkUint32(__rdtsc());
            m_uiStartTicks = ticks;
        }
    };
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static inline StringCursor& GetMonitorStream()
    {
        return *static_cast<StringCursor*>(TlsGetValue(hkMonitorStream__tlsIndex));
    }
    inline hkBool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    inline char* GetStreamEnd() const
    {
        return m_kRayEnd;
    }
    inline void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};

struct ShapeRayCastQuery;
struct hkpRayHitCollector;
struct hkpCdBody;

struct hkpShapeV : hkpShape
{
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual void castRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const;
};

struct hkpCdBody
{
    const hkpShapeV* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;

    inline hkpCdBody(const hkpCdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    inline void SetCollisionShapeAndKey(const hkpShapeV* shape, hkUint32 key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct hkpShapeContainerV
{
    struct ShapeBuffer
    {
        __declspec(align(16)) void* buf[128];
    };
    virtual ~hkpShapeContainerV();
    virtual int GetNumChildShapes() const;
    virtual hkUint32 GetFirstKey() const;
    virtual hkUint32 GetNextShapeKey(hkUint32 key) const;
    virtual hkUint32 GetFilterInfoForKey(hkUint32 key) const;
    virtual const hkpShapeV* GetShapeForKey(hkUint32 key, ShapeBuffer& buffer) const;
};

struct FUN_00d5e600_Class : hkpConvexShape, hkpShapeContainerV
{
    void FUN_00d5e600(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Iterates child shape keys, builds a child hkpCdBody for each, and calls castRayWithCollector on every child shape.
// @fnv 0x00d5e600
void FUN_00d5e600_Class::FUN_00d5e600(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const
{
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            StringCursor::CommandTimingEntry* h =
                reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "TtrcShpCollect";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
    hkUint32 key = GetFirstKey();
    while (key != 0xffffffff)
    {
        ShapeBuffer shapeBuffer;
        const hkpShapeV* childShape = GetShapeForKey(key, shapeBuffer);
        hkpCdBody childBody(&cdBody);
        childBody.SetCollisionShapeAndKey(childShape, key);
        childShape->castRayWithCollector(input, childBody, collector);
        key = GetNextShapeKey(key);
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            StringCursor::CommandTimingEntry* h =
                reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "Et";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
}

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00d5e840();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d5e840();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d5e840
    virtual void FUN_00d5e840();
};

Derived::Derived()
{}

extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkVector4q
{
    __m128 m_vComponents;

    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline hkReal dot3(const hkVector4q& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        const __m128 xyzSum = _mm_add_ss(z, xySum);
        hkReal r;
        _mm_store_ss(&r, xyzSum);
        return r;
    }

    __forceinline int getInt24W() const
    {
        return reinterpret_cast<const int*>(&m_vComponents)[3] & ~0x3f000000;
    }

    __forceinline void setInt24W(int value)
    {
        reinterpret_cast<int*>(&m_vComponents)[3] = value | 0x3f000000;
    }
};

class ConvexChildShape : public hkpConvexShape
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void GetSupportPoint(const hkVector4q& direction, hkVector4q& supportingVertex) const;
};

struct ConvexListShapeQ : hkpConvexListShape
{
    void getSupportingVertexImpl(const hkVector4q& direction, hkVector4q& supportingVertex) const;
};

// Finds the child convex shape with the maximum dot product against direction, sets supportingVertex, and encodes the child index into the vertex's w component.
// @fnv 0x00d5e300
void ConvexListShapeQ::getSupportingVertexImpl(const hkVector4q& direction, hkVector4q& supportingVertex) const
{
    hkReal maxDot = DAT_0104e148;
    int subShape = 0;
    for (int i = 0; i < m_kChildShapes.m_iElementCount; i++)
    {
        hkVector4q support;
        const ConvexChildShape* shape = static_cast<const ConvexChildShape*>(m_kChildShapes.m_data[i]);
        shape->GetSupportPoint(direction, support);
        hkReal dot = support.dot3(direction);
        if (dot > maxDot)
        {
            maxDot = dot;
            supportingVertex = support;
            subShape = i;
        }
    }
    int id = supportingVertex.getInt24W();
    id += (subShape << 8);
    supportingVertex.setInt24W(id);
}


// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTriSampledHeightFieldBvTreeShape.h"

// ---------------------------------------------------------------------------
// hkpShape is only forward declared by the pack's headers, so complete it
// here.  hkBaseObject contributes the virtual destructor, which sits in the
// first vtable slot; the four shape virtuals follow it, so the one the
// container forwards to ends up at vtable offset 0x10.
// ---------------------------------------------------------------------------
class hkpShape : public hkBaseObject
{
  public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

// ---------------------------------------------------------------------------
// The shape container.  It derives from the real class so that the members
// keep their real offsets: m_kChildContainer.m_pContainedShape lives at +0x18.
// ---------------------------------------------------------------------------
struct TriSampledHeightFieldBvTreeShape : public hkpTriSampledHeightFieldBvTreeShape
{
    void FUN_00d27200();
};

// @fnv 0x00d27200
void TriSampledHeightFieldBvTreeShape::FUN_00d27200()
{
    m_kChildContainer.m_pContainedShape->v4();
}

struct FUN_00d268b0_Obj : public hkpTriSampledHeightFieldBvTreeShape
{
    int __thiscall calcSizeForSpu(int a, int b);
};

// @fnv 0x00d268b0
int __thiscall FUN_00d268b0_Obj::calcSizeForSpu(int a, int aiUnused)
{
    hkpShape* childShape = m_kChildContainer.m_pContainedShape;
    void** vtable = *(void***)childShape;
    typedef int(__thiscall * ShapeFunction)(hkpShape*, int, int);
    ShapeFunction function = (ShapeFunction)vtable[6];

    unsigned int result = (unsigned int)function(childShape, a, 0x100);
    if (result <= 0x100u)
    {
        m_iChildSize = (hkInt32)result;
        return 0x30;
    }
    return -1;
}

struct CallbackShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* first, float value, void* last);
};
struct ShapeDispatch
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CallbackShape* shape;
    void DispatchCallback(void* first, float value, void* last);
};
// @fnv 0x00d26ae0
void ShapeDispatch::DispatchCallback(void* first, float value, void* last)
{
    shape->v1c(first, value, last);
}

struct hkResultD26B
{
    int m_00;
    hkResultD26B()
    {}
};

class hkTargetD26B
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
    virtual hkResultD26B query(void* a, void* b);
};

class hkHolderD26B
{
  public:
    hkTargetD26B* FUN_00d26450() throw();
};

class hkObjD26B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkHolderD26B* m_holder;

    hkResultD26B Query(void* a, void* b) throw();
};

// Forwards the two arguments to the query method of the target obtained from m_holder and returns its result.
// @fnv 0x00d26b00
hkResultD26B hkObjD26B::Query(void* a, void* b) throw()
{
    return m_holder->FUN_00d26450()->query(a, b);
}

extern void __cdecl ComputeAabbFromTransform(int, int, float, char*);

struct FUN_00d268f0_LocalBuffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class FUN_00d268f0_Shape
{
  public:
    virtual void vf00();
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
    virtual void ProcessBuffer(int, int, float, int);
    virtual void CollectHits(char*, int);
};

// Calls ComputeAabbFromTransform(a, b, c, &buffer), then calls CollectHits with that buffer and d.
// @fnv 0x00d268f0
void __thiscall FUN_00d268f0_Shape::ProcessBuffer(int a, int b, float c, int d)
{
    __declspec(align(16)) FUN_00d268f0_LocalBuffer buffer;

    ComputeAabbFromTransform(a, b, c, reinterpret_cast<char*>(&buffer));
    CollectHits(reinterpret_cast<char*>(&buffer), d);
}

extern int DAT_010c6fd0;
extern int DAT_010ce404;

struct CC9F10Shape
{
    void FUN_00c90510();
};

struct FUN_00d26b50
{
    const int* m_pVT;
    char pad4[2];
    unsigned short m_uiValue1;
    int m_iA;
    int m_iB;
    unsigned char m_bC;
    char pad11[3];
    const int* m_pD;
    CC9F10Shape* m_pShape;
    char pad1d[4];
    unsigned char m_bE;
    FUN_00d26b50(CC9F10Shape* pShape, unsigned char bE);
};

// Initializes a FUN_00d26b50 object with default values, assigns pShape and bE, and calls pShape->FUN_00c90510().
// @fnv 0x00d26b50
FUN_00d26b50::FUN_00d26b50(CC9F10Shape* pShape, unsigned char bE)
{
    m_uiValue1 = 1;
    m_iA = 0;
    m_iB = 8;
    m_bC = 1;
    m_pVT = &DAT_010ce404;
    m_pD = &DAT_010c6fd0;
    m_pShape = pShape;
    m_pShape->FUN_00c90510();
    m_bE = bE;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct hkMemory;

struct hkThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemory* m_pMemoryAllocator;
};

extern "C" hkThreadMemory* FUN_00c85750();
extern "C" void ResizeAudioStream(hkMemory* memory, void* array, int elemSize);
extern "C" void FUN_00c908c0(hkMemory* memory, void* array, int numElements, int elemSize);

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

struct hkShapeKeyArray
{
    hkUint32* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void AddBack(const hkUint32& e)
    {
        hkThreadMemory* tm = FUN_00c85750();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(tm->m_pMemoryAllocator, this, sizeof(hkUint32));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }

    __forceinline void SetSizeAndGrow(int n)
    {
        hkThreadMemory* tm = FUN_00c85750();
        hkMemory* memory = tm->m_pMemoryAllocator;
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(memory, this, newSize, sizeof(hkUint32));
        }
        m_iElementCount = n;
    }
};

class hkpSampledHeightFieldShapeq
{
  public:
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual hkReal getHeightAt(int x, int z) const;

    int m_pad04[7];
    hkReal m_kHeightScaleVector[4];
};

class hkpTriSampledHeightFieldCollectionq
{
  public:
    const hkpSampledHeightFieldShapeq* FUN_00d26450() const;
};

struct hkBoolq
{
    char m_cBooleanValue;
    hkBoolq(bool b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

__declspec(noalias) hkBoolq FUN_00d26940(const hkAabbq* aabb, const hkpTriSampledHeightFieldCollectionq* collection,
                                         hkUint32* minX, hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ);

struct TriSampledHeightFieldBvTreeShapeq : public hkpTriSampledHeightFieldBvTreeShape
{
    __forceinline const hkpTriSampledHeightFieldCollectionq* getShapeCollection() const
    {
        return reinterpret_cast<const hkpTriSampledHeightFieldCollectionq*>(m_kChildContainer.m_pContainedShape);
    }
    void CollectHits(const hkAabbq& aabbIn, hkShapeKeyArray& hits) const;
};

// Appends shape keys for grid cells overlapping aabbIn to hits; with bounds checking, drops them if all sampled heights are above or below the AABB.
// @fnv 0x00d26e50
void TriSampledHeightFieldBvTreeShapeq::CollectHits(const hkAabbq& aabbIn, hkShapeKeyArray& hits) const
{
    hkAabbq aabb;
    aabb.m_kMinimumCorner = aabbIn.m_kMinimumCorner;
    aabb.m_kMaximumCorner = aabbIn.m_kMaximumCorner;

    hkUint32 minX, maxX, minZ, maxZ;
    {
        hkBoolq valid = FUN_00d26940(&aabb, getShapeCollection(), &minX, &maxX, &minZ, &maxZ);
        if (!valid)
        {
            return;
        }
    }

    const hkpSampledHeightFieldShapeq* hf = getShapeCollection()->FUN_00d26450();
    int origSize = hits.GetLogicalSize();

    if (m_bCheckHeightFieldBounds)
    {
        hkBool allBelow = true;
        hkBool allAbove = true;

        for (hkUint32 x = minX; x <= maxX; x++)
        {
            for (hkUint32 z = minZ; z <= maxZ; z++)
            {
                hkUint32 key = (z << 16) + (x << 1);
                hits.AddBack(key);
                hits.AddBack(key | 1);

                if (allBelow || allAbove)
                {
                    hkReal raw = hf->getHeightAt(x, z);
                    hkReal h = raw * hf->m_kHeightScaleVector[1];
                    if (aabb.m_kMinimumCorner(1) < h)
                    {
                        allBelow = false;
                    }
                    if (h < aabb.m_kMaximumCorner(1))
                    {
                        allAbove = false;
                    }
                }
            }
        }

        if (!allBelow && !allAbove)
        {
            return;
        }

        for (hkUint32 x = minX; x <= maxX + 1; x++)
        {
            hkReal raw = hf->getHeightAt(x, maxZ + 1);
            hkReal h = raw * hf->m_kHeightScaleVector[1];
            if (aabb.m_kMinimumCorner(1) < h)
            {
                allBelow = false;
            }
            if (h < aabb.m_kMaximumCorner(1))
            {
                allAbove = false;
            }
        }

        for (hkUint32 z = minZ; z <= maxZ + 1; z++)
        {
            hkReal raw = hf->getHeightAt(maxX + 1, z);
            hkReal h = raw * hf->m_kHeightScaleVector[1];
            if (aabb.m_kMinimumCorner(1) < h)
            {
                allBelow = false;
            }
            if (h < aabb.m_kMaximumCorner(1))
            {
                allAbove = false;
            }
        }

        if (allBelow || allAbove)
        {
            hits.SetSizeAndGrow(origSize);
        }
    }
    else
    {
        for (hkUint32 x = minX; x <= maxX; x++)
        {
            for (hkUint32 z = minZ; z <= maxZ; z++)
            {
                hkUint32 key = (z << 16) + (x << 1);
                hits.AddBack(key);
                hits.AddBack(key | 1);
            }
        }
    }
}

struct TargetD26B
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Tail(int a, int b, int c, int d);
};

struct HolderD26B
{
    TargetD26B* FUN_00d26450();
};

struct FUN_00d26b30_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    HolderD26B* m_holder;

    void castRayWithCollectorImpl(int a, int b, int c, int d);
};

// @fnv 0x00d26b30
void FUN_00d26b30_cls::castRayWithCollectorImpl(int a, int b, int c, int d)
{
    m_holder->FUN_00d26450()->Tail(a, b, c, d);
}

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_or_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps(void);
}

struct hkVector4Comparisonq
{
    __m128 m_uiMask;
};

extern const __m128 hkVector4Comparison_maskXYZW;

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

extern const hkTransformq hkTransform_identity;

union hkQuadUintq
{
    __m128 q;
    hkUint32 i[4];
};

struct hkUint16x4
{
    hkUint16 x;
    hkUint16 y;
    hkUint16 z;
    hkUint16 w;
};

// The heightfield's getAabb slot (vtable index 7) with its real parameters.
class hkpSampledHeightFieldShapeAabbq
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void getAabb(const hkTransformq& localToWorld, hkReal tolerance, hkAabbq& out) const;
};

__forceinline const hkVector4q& getFloatToIntScale(const hkpSampledHeightFieldShapeq* hf)
{
    return reinterpret_cast<const hkVector4q*>(hf->m_kHeightScaleVector)[1];
}

__forceinline const hkVector4q& getFloatToIntOffsetFloorCorrected(const hkpSampledHeightFieldShapeq* hf)
{
    return reinterpret_cast<const hkVector4q*>(hf->m_kHeightScaleVector)[2];
}

extern const hkVector4q hkVector4Util_uint16Magic;

__forceinline hkReal getRadius(const hkpTriSampledHeightFieldCollectionq* collection)
{
    return reinterpret_cast<const hkReal*>(collection)[8];
}

__forceinline void SetAllComponents(hkVector4q& self, hkReal r)
{
    self.m_vComponents = _mm_set_ps1(r);
}
__forceinline void setZero4(hkVector4q& self)
{
    self.m_vComponents = _mm_setzero_ps();
}
__forceinline void set(hkVector4q& self, hkReal a, hkReal b, hkReal c, hkReal d)
{
    self.m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void add4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_add_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void sub4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_sub_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void mul4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_mul_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void setAdd4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMin4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMax4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline hkVector4Comparisonq compareLessThan4(const hkVector4q& self, const hkVector4q& a,
                                                    const hkVector4Comparisonq& mask)
{
    hkVector4Comparisonq c;
    c.m_uiMask = _mm_and_ps(_mm_cmplt_ps(self.m_vComponents, a.m_vComponents), mask.m_uiMask);
    return c;
}

__forceinline void setSelect4(hkVector4q& self, const hkVector4Comparisonq& comp, const hkVector4q& trueValue,
                              const hkVector4q& falseValue)
{
    self.m_vComponents = _mm_or_ps(_mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents),
                                   _mm_and_ps(comp.m_uiMask, trueValue.m_vComponents));
}

// Clip-converts one vector and returns the 65536.0f magic vector it added, so the
// second conversion can reuse the loaded value without re-reading the global.
__forceinline __m128 convertToUint16WithClip(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                             const hkVector4q& minVal, const hkVector4q& maxVal, hkUint16x4& out)
{
    hkVector4q x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    // Adding 65536 leaves value * 128 in the low mantissa bits.
    add4(x, hkVector4Util_uint16Magic);
    const __m128 magic = hkVector4Util_uint16Magic.m_vComponents;
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
    return magic;
}

// Same conversion, reusing the magic vector returned by the first call.
__forceinline void convertToUint16WithClipAgain(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                const hkVector4q& minVal, const hkVector4q& maxVal, const __m128 magic,
                                                hkUint16x4& out)
{
    hkVector4q x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    // Adding 65536 leaves value * 128 in the low mantissa bits.
    x.m_vComponents = _mm_add_ps(x.m_vComponents, magic);
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
}

// Expands aabb by the collection radius, clamps it to the height field's AABB, returns false if empty, else outputs uint16 grid min/max X and Z.
// @fnv 0x00d26940
hkBoolq FUN_00d26940(const hkAabbq* aabb, const hkpTriSampledHeightFieldCollectionq* collection, hkUint32* minX,
                     hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ)
{
    // The caller's aabb is expanded and clipped in place.
    const hkpSampledHeightFieldShapeq* hf = collection->FUN_00d26450();

    hkVector4q radius;
    SetAllComponents(radius, getRadius(collection));
    add4(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, radius);
    sub4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, radius);

    {
        hkAabbq hfAabb;
        reinterpret_cast<const hkpSampledHeightFieldShapeAabbq*>(hf)->getAabb(hkTransform_identity, 0.0f, hfAabb);

        hkVector4Comparisonq all;
        all.m_uiMask = hkVector4Comparison_maskXYZW;
        setSelect4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner,
                   compareLessThan4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, hfAabb.m_kMinimumCorner, all),
                   hfAabb.m_kMinimumCorner, const_cast<hkAabbq*>(aabb)->m_kMinimumCorner);
        setSelect4(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner,
                   compareLessThan4(hfAabb.m_kMaximumCorner, const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, all),
                   hfAabb.m_kMaximumCorner, const_cast<hkAabbq*>(aabb)->m_kMaximumCorner);
    }

    if (_mm_movemask_ps(_mm_cmple_ps(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner.m_vComponents,
                                     const_cast<hkAabbq*>(aabb)->m_kMinimumCorner.m_vComponents)) &
        7)
    {
        return false;
    }

    hkVector4q zero;
    setZero4(zero);
    hkVector4q maxVal;
    set(maxVal, hkReal(hf->m_pad04[3] - 2), 0.0f, hkReal(hf->m_pad04[4] - 2), 0.0f);

    hkUint16x4 out;
    const __m128 magic =
        convertToUint16WithClip(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, getFloatToIntOffsetFloorCorrected(hf),
                                getFloatToIntScale(hf), zero, maxVal, out);
    *minX = out.x;
    *minZ = out.z;

    convertToUint16WithClipAgain(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, getFloatToIntOffsetFloorCorrected(hf),
                                 getFloatToIntScale(hf), zero, maxVal, magic, out);
    *maxX = out.x;
    *maxZ = out.z;

    return true;
}

typedef hkUint32 hkpShapeKey;

struct hkAabb
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;

    __forceinline hkAabb(const hkAabb& a) throw()
    {
        m_kMinimumCorner = a.m_kMinimumCorner;
        m_kMaximumCorner = a.m_kMaximumCorner;
    }
};

class hkpSampledHeightFieldShape
{
  public:
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual hkReal GetHeightAtGridPoint(int x, int z) const;

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kHeightScaleVector;

    __forceinline hkReal getHeightAt(int x, int z) const throw()
    {
        hkReal h = GetHeightAtGridPoint(x, z);
        return h * m_kHeightScaleVector.y;
    }

    __forceinline hkReal getScaledHeight(int x, int z) const throw()
    {
        hkReal h = GetHeightAtGridPoint(x, z);
        return m_kHeightScaleVector.y * h;
    }
};

class hkpTriSampledHeightFieldCollection
{
  public:
    const hkpSampledHeightFieldShape* FUN_00d26450() const;
};

struct hkBoolResult
{
    hkBool m_cBooleanValue;
    hkBoolResult() throw();
    hkBoolResult(bool b) throw() : m_cBooleanValue(b)
    {}
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

static __declspec(noinline) hkBoolResult
    __cdecl FUN_00d26940(const hkAabb& aabb, const hkpTriSampledHeightFieldCollection* collection, hkUint32& minX,
                         hkUint32& maxX, hkUint32& minZ, hkUint32& maxZ)
{
    const hkpSampledHeightFieldShape* hf = collection->FUN_00d26450();
    minX = (int)(aabb.m_kMinimumCorner.m128_f32[0] * hf->m_kHeightScaleVector.x);
    maxX = (int)(aabb.m_kMaximumCorner.m128_f32[0] * hf->m_kHeightScaleVector.x);
    minZ = (int)(aabb.m_kMinimumCorner.m128_f32[2] * hf->m_kHeightScaleVector.z);
    maxZ = (int)(aabb.m_kMaximumCorner.m128_f32[2] * hf->m_kHeightScaleVector.z);
    return hkBoolResult(minX <= maxX && minZ <= maxZ);
}

typedef hkBoolResult(__cdecl* ExtentsQueryFn)(const hkAabb&, const hkpTriSampledHeightFieldCollection*, hkUint32&,
                                              hkUint32&, hkUint32&, hkUint32&);
ExtentsQueryFn S00d26ba0_extentsFp = &FUN_00d26940;

struct BvTreeShape : public hkpTriSampledHeightFieldBvTreeShape
{
    hkUint32 queryAabbImpl(const hkAabb& aabbIn, hkpShapeKey* hits, int maxNumKeys) const;
};

// Fills hits with shape keys for grid cells overlapping aabbIn and returns the count, or 0 if bounds checking finds every sampled height above or below it.
// @fnv 0x00d26ba0
hkUint32 BvTreeShape::queryAabbImpl(const hkAabb& aabbIn, hkpShapeKey* hits, int maxNumKeys) const
{
    hkAabb aabb(aabbIn);
    const hkpTriSampledHeightFieldCollection* collection =
        reinterpret_cast<const hkpTriSampledHeightFieldCollection*>(m_kChildContainer.m_pContainedShape);

    hkUint32 maxZ, minZ, maxX, minX;
    {
        hkBoolResult ok = FUN_00d26940(aabb, collection, minX, maxX, minZ, maxZ);
        if (!ok)
        {
            return 0;
        }
    }

    int numHits = 0;
    const hkpSampledHeightFieldShape* hf = collection->FUN_00d26450();

    if (m_bCheckHeightFieldBounds)
    {
        bool allBelow = true;
        bool allAbove = true;
        int x, z;

        for (x = minX; x <= maxX; x++)
        {
            for (z = minZ; z <= maxZ; z++)
            {
                hkpShapeKey key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                }
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key | 1;
                }
                if (allBelow || allAbove)
                {
                    hkReal height = hf->getScaledHeight(x, z);
                    if (aabb.m_kMinimumCorner.m128_f32[1] < height)
                    {
                        allBelow = false;
                    }
                    if (height < aabb.m_kMaximumCorner.m128_f32[1])
                    {
                        allAbove = false;
                    }
                }
            }
        }

        if (allBelow || allAbove)
        {
            for (x = minX; x <= maxX + 1; x++)
            {
                hkReal height = hf->getHeightAt(x, maxZ + 1);
                if (aabb.m_kMinimumCorner.m128_f32[1] < height)
                {
                    allBelow = false;
                }
                if (height < aabb.m_kMaximumCorner.m128_f32[1])
                {
                    allAbove = false;
                }
            }
            for (z = minZ; z <= maxZ + 1; z++)
            {
                hkReal height = hf->getHeightAt(maxX + 1, z);
                if (aabb.m_kMinimumCorner.m128_f32[1] < height)
                {
                    allBelow = false;
                }
                if (height < aabb.m_kMaximumCorner.m128_f32[1])
                {
                    allAbove = false;
                }
            }
            if (allBelow || allAbove)
            {
                return 0;
            }
        }
    }
    else
    {
        for (int x = minX; x <= maxX; x++)
        {
            for (int z = minZ; z <= maxZ; z++)
            {
                hkpShapeKey key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                    if (numHits < maxNumKeys)
                    {
                        hits[numHits++] = key | 1;
                    }
                }
            }
        }
    }
    return numHits;
}

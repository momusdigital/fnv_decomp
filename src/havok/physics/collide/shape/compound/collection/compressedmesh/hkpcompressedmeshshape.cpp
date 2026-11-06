
// src/havok/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCompressedMeshShape.h"

struct FUN_00e3cad0_Class
{
    unsigned int m_uiShapeIndex;
    unsigned int m_pCollisionShape;
    unsigned int m_pCollisionShape2;
    unsigned int m_pCollisionShape3;
    unsigned int GetShapeIndexMask();
};

// @fnv 0x00e3cad0
unsigned int FUN_00e3cad0_Class::GetShapeIndexMask()
{
    if (*(unsigned int*)((char*)this + 0x60))
        return 0;
    if (*(unsigned int*)((char*)this + 0x6c))
        return 1 << *(unsigned int*)((char*)this + 0xc);
    if (*(unsigned int*)((char*)this + 0x78))
        return ((1 << (32 - *(unsigned int*)((char*)this + 0xc))) - 1) << *(unsigned int*)((char*)this + 0xc);
    return -1;
}

struct FUN_00e3deb0_Class
{
    unsigned int m_reserved;
    unsigned short m_uiSize;

    void* __thiscall FUN_00e3deb0(unsigned int uiFlags);
};

struct FUN_00e3deb0_MemoryManager
{
    // Virtual destructor for the memory manager; does nothing.
// @fnv 0x00e3deb0
    virtual ~FUN_00e3deb0_MemoryManager()
    {}
    virtual void __thiscall Unused()
    {}
    virtual void __thiscall Free(void* pMemory, unsigned int uiSize)
    {}
};

struct FUN_00e3deb0_Router
{
    unsigned int m_reserved[4];
    FUN_00e3deb0_MemoryManager* m_pMemoryManager;
};

void __cdecl FUN_00e3dc50();
FUN_00e3deb0_Router* __cdecl _D1A0E0GetMemoryRouter();

void* __thiscall FUN_00e3deb0_Class::FUN_00e3deb0(unsigned int uiFlags)
{
    FUN_00e3deb0_Class* pShape = this;

    FUN_00e3dc50();

    if (uiFlags & 1)
    {
        FUN_00e3deb0_Router* pRouter = _D1A0E0GetMemoryRouter();
        pRouter->m_pMemoryManager->Free(pShape, pShape->m_uiSize);
    }

    return pShape;
}

// @fnv 0x00e3c9d0
__declspec(noinline) unsigned int __stdcall calcSizeForSpu(unsigned int a1, unsigned int a2)
{
    return 0xF0;
}

struct FUN_00e3d0d0_Class
{
    void SetWeldingType(unsigned char weldingType);
};
// Stores the given welding type byte at offset 0x2c of this object.
// @fnv 0x00e3d0d0
void FUN_00e3d0d0_Class::SetWeldingType(unsigned char weldingType)
{
    *((unsigned char*)this + 0x2c) = weldingType;
}

extern int DAT_01269198;
int __cdecl FUN_00d213e0(int first, int* second);

// @fnv 0x00e3c9c0
int __cdecl FUN_00e3c9c0(int first, int unusedSecond)
{
    return FUN_00d213e0(first, &DAT_01269198);
}

// @fnv 0x00e3ca00
int __stdcall FUN_00e3ca00(int arg0)
{
    return 0;
}

void __cdecl FUN_00e3cc20(void* pIndices, const hkVector4* pSrcVec, float fScale, hkVector4* pDstVec,
                          const hkVector4* pOtherVec);

struct FUN_00e3cd20_Class : hkVector4
{
    void* unk10;
    unsigned int unk14;

    void FUN_00e3cd20(float a1, hkVector4* a2, hkVector4* a3);
};

// Calls FUN_00e3cc20 with the object's unk10, this vector, a1, a2 and a3.
// @fnv 0x00e3cd20
void FUN_00e3cd20_Class::FUN_00e3cd20(float afScale, hkVector4* a2, hkVector4* a3)
{
    FUN_00e3cc20(&unk10, this, afScale, a2, a3);
}

extern "C" void _ReadWriteBarrier(void);

const void* DAT_010d0fc4[];

struct FUN_00d59710
{
    const void** m_vtbl;
    unsigned short unk04;
    unsigned short m_uiType;
    unsigned int m_uiPad;
    unsigned int m_uiNumShapes;
    float m_fScale;
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
    unsigned int m_uiF40;
    unsigned int m_uiF44;
    unsigned int m_uiF48;
    unsigned int unk4c;
    unsigned int m_uiF50;
    unsigned int m_uiF54;
    unsigned int m_uiF58;
    unsigned int m_uiF5c;
    unsigned int m_uiF60;
    FUN_00d59710(float fScale);
};

// @fnv 0x00d59710
FUN_00d59710::FUN_00d59710(float fScale)
{
    unsigned short us = 1;
    unsigned int uiZero = 0;
    m_fScale = fScale;
    m_uiType = us;
    m_uiPad = uiZero;
    m_uiNumShapes = 6;
    m_vtbl = DAT_010d0fc4;
    m_uiF40 = uiZero;
    m_uiF44 = uiZero;
    _ReadWriteBarrier();
    unsigned int uiHi = 0x80000000;
    m_uiF48 = uiHi;
    m_uiF50 = uiZero;
    m_uiF54 = uiZero;
    m_uiF58 = uiZero;
    m_uiF5c = uiHi;
    m_uiF60 = uiZero;
}

struct FUN_00e3ca10_Class
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
    unsigned short* unk28;
    int unk2c;

    int FUN_00e3ca10(int aiIndex, int* apOut);
};

// Locates aiIndex+1 among cumulative section sizes in unk28, adjusts it, sets *apOut to a parity bit in the strip part, and returns -1 once past unk20.
// @fnv 0x00e3ca10
int FUN_00e3ca10_Class::FUN_00e3ca10(int aiIndex, int* apOut)
{
    *apOut = 0;
    if (aiIndex < 0)
    {
        return unk20 ? 0 : -1;
    }

    int iCount = unk2c;
    ++aiIndex;
    int i = 0;
    int iAccumulated = 0;
    int iPrevious = 0;
    if (iCount != 0)
    {
        iAccumulated = unk28[0];
        if (aiIndex >= iAccumulated)
        {
            do
            {
                ++i;
                if (i >= iCount)
                {
                    break;
                }
                iPrevious = iAccumulated;
                iAccumulated += unk28[i];
            } while (aiIndex >= iAccumulated);
        }
    }

    if (i >= iCount)
    {
        int iDelta = aiIndex - iAccumulated;
        int iStride = 3;
        while (iDelta % iStride != 0)
        {
            ++iDelta;
            ++aiIndex;
        }
    }
    else if (aiIndex >= iAccumulated - 2)
    {
        aiIndex = iAccumulated;
    }
    else
    {
        *apOut = (aiIndex - iPrevious) & 1;
    }

    if (aiIndex >= unk20)
    {
        return -1;
    }

    return aiIndex;
}

struct StripsShapeE3CEB0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_iNumIndices;
    int unk24;
    unsigned short* m_pusStripLengths;
    int m_iNumStrips;
    int GetNumTriangles();
};

// Sums strip lengths to get total strip indices, computes triangles per strip, and adds remaining indices divided by three to return total triangle count.
// @fnv 0x00e3ceb0
int StripsShapeE3CEB0::GetNumTriangles()
{
    int iTotalStripIndices = 0;
    int iStripTriangles = 0;
    for (int i = 0; i < m_iNumStrips; i++)
    {
        iTotalStripIndices += m_pusStripLengths[i];
        iStripTriangles += m_pusStripLengths[i] - 2;
    }
    int iRemainingIndices = m_iNumIndices - iTotalStripIndices;
    return iRemainingIndices / 3 + iStripTriangles;
}

struct FUN_00e3d060_Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_uiShiftCount;
    unsigned int m_pShapeData;
    unsigned int m_pIndexData;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int m_pAttributeTable;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int m_pSubAttributeData;
    void __thiscall SetAttribute(unsigned long instanceMask, unsigned short attributeValue);
};

// Writes attributeValue to the attribute table or sub-attribute data based on instanceMask and m_uiShiftCount.
// @fnv 0x00e3d060
void __thiscall FUN_00e3d060_Owner::SetAttribute(unsigned long instanceMask, unsigned short attributeValue)
{
    unsigned int shiftResult = instanceMask >> m_uiShiftCount;

    if (!shiftResult)
    {
        unsigned int shapeOffset = m_pShapeData & instanceMask;
        *(unsigned short*)((char*)m_pAttributeTable + shapeOffset * 16 + 12) = attributeValue;
    }
    else
    {
        unsigned int indexOffset = m_pIndexData & instanceMask;
        unsigned int index = shiftResult - 1;
        unsigned short entry = *(unsigned short*)((char*)m_pSubAttributeData + index * 80 + 0x44);
        if (entry != 0xFFFF)
            index = entry;
        unsigned int attributeEntryOffset = *(unsigned int*)((char*)m_pSubAttributeData + index * 80 + 0x34);
        *(unsigned short*)((char*)attributeEntryOffset + indexOffset * 2) = attributeValue;
    }
}

struct FinishFlagE3DBD0
{
    int m_bFinishing;
};
struct ShapeE3DBD0
{
    ShapeE3DBD0(FinishFlagE3DBD0 flag) throw()
    {
        if (flag.m_bFinishing)
            m_type = 0;
    }
    virtual ~ShapeE3DBD0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
};
struct ContainerE3DBD0
{
    ContainerE3DBD0() throw()
    {}
    virtual ~ContainerE3DBD0() throw();
};
struct CollectionE3DBD0 : public ShapeE3DBD0, public ContainerE3DBD0
{
    CollectionE3DBD0(FinishFlagE3DBD0 flag) throw() : ShapeE3DBD0(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = 3;
        }
    }
    virtual ~CollectionE3DBD0() throw();
    unsigned char m_bDisableWelding;
    unsigned char m_eCollectionType;
    unsigned char m_aiValuesD34;
    unsigned char m_pad17;
};
struct FUN_00e3dbd0 : public CollectionE3DBD0
{
    FUN_00e3dbd0(FinishFlagE3DBD0 flag) throw();
    virtual ~FUN_00e3dbd0() throw();
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int m_iValueC0;
    int unkC4;
    int m_iValueC8;
    int m_iCountCC;
};

// @fnv 0x00e3dbd0
FUN_00e3dbd0::FUN_00e3dbd0(FinishFlagE3DBD0 flag) throw() : CollectionE3DBD0(flag)
{
    if (flag.m_bFinishing)
    {
        m_type = 0x10;
        m_eCollectionType = 6;
        if (m_iCountCC)
            m_iValueC0 = m_iValueC8;
    }
}

class hkMemoryAllocatorE3D
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterE3D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE3D* m_pStreamAllocator;
    hkMemoryAllocatorE3D& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE3D& __cdecl GetMemoryRouterE3D() throw();
template <typename T> __forceinline void DestructE3D(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}
template <typename T> struct hkArrayE3D
{
    __forceinline ~hkArrayE3D() throw()
    {
        hkMemoryAllocatorE3D& kAlloc = GetMemoryRouterE3D().heap();
        DestructE3D(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkStringPtrE3D
{
    ~hkStringPtrE3D() throw();
    const char* m_pcText;
};
struct __declspec(align(16)) hkVector4E3D
{
    float x;
    float y;
    float z;
    float w;
};
struct hkTransformE3D
{
    hkVector4E3D m_rotation[3];
    hkVector4E3D m_vTranslation;
};
struct BigTriangleE3D
{
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    unsigned short m_iThirdValue;
    unsigned short m_iMaterialIndex;
    unsigned short m_kWeldingInfo;
    unsigned short m_iSectionVertexCount;
    int unk0C;
};
struct ChunkE3D
{
    ~ChunkE3D() throw();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
};
struct ConvexPieceE3D
{
    ~ConvexPieceE3D() throw();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
};
struct NamedMaterialE3D
{
    unsigned int m_uiFilterInfo;
    hkStringPtrE3D m_name;
};
class hkReferencedObjectE3D
{
  public:
    virtual ~hkReferencedObjectE3D() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpShapeE3D : public hkReferencedObjectE3D
{
  public:
    unsigned int m_ulUserData;
    int m_type;
};
class hkpShapeContainerE3D
{
  public:
    virtual ~hkpShapeContainerE3D() throw()
    {}
};
class __declspec(novtable) FUN_00e3dc50 : public hkpShapeE3D, public hkpShapeContainerE3D
{
  public:
    virtual ~FUN_00e3dc50() throw();
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
    int m_iBitsPerIndex;
    int m_iBitsPerWIndex;
    int m_iNumBitsForIndex;
    int m_iNumBitsForWIndex;
    float m_fSphereRadius;
    unsigned char m_eWeldingType;
    unsigned char m_ucMaterialType;
    hkArrayE3D<unsigned int> m_kMaterials;
    hkArrayE3D<unsigned short> m_kMaterialIndices16;
    hkArrayE3D<unsigned char> m_kMaterialIndices8;
    hkArrayE3D<hkTransformE3D> m_kTransforms;
    hkArrayE3D<hkVector4E3D> m_kBigVertices;
    hkArrayE3D<BigTriangleE3D> m_kBigTriangles;
    hkArrayE3D<ChunkE3D> m_kChunks;
    hkArrayE3D<ConvexPieceE3D> m_kConvexPieces;
    float m_eScriptError;
    int unk94;
    int unk98;
    int unk9C;
    hkVector4E3D m_boundsMin;
    hkVector4E3D m_boundsMax;
    int m_uiShapeFlags;
    void* m_pUserData;
    hkArrayE3D<NamedMaterialE3D> m_kNamedMaterials;
};

// @fnv 0x00e3dc50
FUN_00e3dc50::~FUN_00e3dc50() throw()
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_setr_ps(float x, float y, float z, float w);
    __m128 _mm_set_ps1(float a);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
}

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    void FUN_00c7f640(const hkTransform& t, const hkVector4q& v);
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

class hkpConvexVerticesShapeq
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_usMemSizeAndFlags;
    unsigned int m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    unsigned int unk14;
    hkVector4q* m_kVertices;
    int m_iStridedVertexCount;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    float m_fSphereRadius;

    void FUN_00e3c270(const hkTransform& localToWorld, float tolerance, hkAabbq& out) const;
};

// Transforms each vertex of the convex shape by localToWorld, accumulates the min/max corners into out, then expands the AABB by m_fSphereRadius plus tolerance.
// @fnv 0x00e3c270
void hkpConvexVerticesShapeq::FUN_00e3c270(const hkTransform& localToWorld, float tolerance, hkAabbq& out) const
{
    out.m_kMinimumCorner.set(3.40282e+38f, 3.40282e+38f, 3.40282e+38f, 0.0f);
    out.m_kMaximumCorner.set(-3.40282e+38f, -3.40282e+38f, -3.40282e+38f, 0.0f);
    for (int i = 0; i < m_iStridedVertexCount; i++)
    {
        hkVector4q v;
        v.FUN_00c7f640(localToWorld, m_kVertices[i]);
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, v);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, v);
    }
    hkVector4q vTolerance;
    vTolerance.SetAllComponents(m_fSphereRadius + tolerance);
    out.m_kMinimumCorner.sub4(vTolerance);
    out.m_kMaximumCorner.add4(vTolerance);
}

struct FUN_00e3c9e0_Class
{
    char m_auiShapeKeys[0xe0];
    __m128 m_vec;
    void CopyFrom(__m128* src);
};

// @fnv 0x00e3c9e0
void FUN_00e3c9e0_Class::CopyFrom(__m128* src)
{
    m_vec = *src;
}

namespace fnv_00e3cc20 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);
extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4q
{
    __m128 m_vComponents;
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void mul4(const hkVector4q& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

// Finds the max x, y, z of the uint16 vertex triples, sets the max corner to max * scale + offset and min corner to offset, then multiplies both by scale4.
// @fnv 0x00e3cc20
void __cdecl FUN_00e3cc20(const hkArray<hkUint16>& vertices, const hkVector4q& offset, float scale, hkAabbq& aabbOut,
                          const hkVector4q& scale4)
{
    hkUint16 maxX = 0;
    hkUint16 maxY = 0;
    hkUint16 maxZ = 0;
    int numVertices = vertices.m_iElementCount / 3;
    for (int i = 0; i < numVertices; i++)
    {
        const hkUint16* v = &vertices.m_data[i * 3];
        if (v[0] > maxX)
            maxX = v[0];
        if (v[1] > maxY)
            maxY = v[1];
        if (v[2] > maxZ)
            maxZ = v[2];
    }
    hkVector4q scaleV;
    scaleV.m_vComponents = _mm_load_ss(&scale);
    scaleV.m_vComponents = _mm_shuffle_ps(scaleV.m_vComponents, scaleV.m_vComponents, 0);
    hkVector4q extent;
    extent.set(hkReal(maxX), hkReal(maxY), hkReal(maxZ), 0.0f);
    aabbOut.m_kMaximumCorner.m_vComponents =
        _mm_add_ps(_mm_mul_ps(extent.m_vComponents, scaleV.m_vComponents), offset.m_vComponents);
    aabbOut.m_kMinimumCorner = offset;
    aabbOut.m_kMaximumCorner.mul4(scale4);
    aabbOut.m_kMinimumCorner.mul4(scale4);
}
}  // namespace fnv_00e3cc20

class hkpCompressedMeshShapeChunk
{
  public:
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned materialInfo;
    unsigned short reference, unk46;
    unsigned unk48, unk4c;
    unsigned FUN_00e3ca10(unsigned triangle, unsigned* welding);
};
struct ValidatedMesh : hkpCompressedMeshShape
{
    unsigned FUN_00e3cfe0(unsigned key);
};
// Validates a packed triangle key against the compressed mesh chunks, returning 0 on success or an error code 1-4 on mismatch.
// @fnv 0x00e3cfe0
unsigned ValidatedMesh::FUN_00e3cfe0(unsigned key)
{
    int index = (int)(key >> m_iBitsPerWIndex);
    unsigned triangle = key & m_iNumBitsForIndex;
    int other = (int)triangle;
    triangle &= m_iNumBitsForWIndex;
    other >>= m_iBitsPerIndex;
    if (index == 0)
    {
        if (other != 0)
            return 1;
    }
    else
    {
        --index;
        if (index >= m_kChunks.m_iElementCount)
            return 2;
        unsigned uiNextTriangle = m_kChunks.m_data[index].FUN_00e3ca10(triangle - 1, &key);
        if (uiNextTriangle != triangle)
            return 3;
        if (key != (unsigned)other)
            return 4;
    }
    return 0;
}

namespace fnv_00e3d250 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, __m128);
}

struct TransformQ;

struct VectorQ
{
    __m128 m_vComponents;

    __forceinline void operator=(const VectorQ& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void FUN_00c7f640(const TransformQ* t, const VectorQ* v);
};

struct TransformQ
{
    VectorQ m_kColumn0;
    VectorQ m_kColumn1;
    VectorQ m_kColumn2;
    VectorQ m_vTranslation;
};

struct AabbQ
{
    VectorQ m_kMinimumCorner;
    VectorQ m_kMaximumCorner;
};

struct ChunkQ
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned short m_kSmartReference;
    unsigned short m_iSectionVertexCount;
    unsigned int unk48, unk4c;

    void FUN_00e3cd20(float error, AabbQ* aabb, const VectorQ* scale);
};

struct MeshQ
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    int m_iBitsPerIndex, m_iBitsPerWIndex, m_iNumBitsForIndex, m_iNumBitsForWIndex;
    float m_fSphereRadius;
    unsigned char m_eWeldingType, m_ucMaterialType;
    unsigned short unk2e;
    hkArray<unsigned int> m_kMaterials;
    hkArray<unsigned short> m_kMaterialIndices16;
    hkArray<unsigned char> m_kMaterialIndices8;
    hkArray<hkTransform> m_kTransforms;
    hkArray<hkVector4> m_kBigVertices;
    hkArray<int> m_kBigTriangles;
    hkArray<ChunkQ> m_kChunks;
    hkArray<int> m_kConvexPieces;
    float m_eScriptError;
    unsigned int unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    void* m_pUserData;
    unsigned short m_iIndexStriding, m_iNumTriangles;
    hkArray<int> m_kNamedMaterials;
    unsigned int unkd4, unkd8, unkdc;
    VectorQ m_vScale;

    void FUN_00e3d250(const ChunkQ* chunk, AabbQ* aabb);
};

union QuadVector
{
    hkVector4 v;
    __m128 q;
};

// Calls FUN_00e3cd20 with aabb on the chunk (or the chunk it references), then transforms aabb's corners by that chunk's transform scaled by m_vScale, if any.
// @fnv 0x00e3d250
void MeshQ::FUN_00e3d250(const ChunkQ* chunk, AabbQ* aabb)
{
    if (chunk->m_kSmartReference == 0xffff)
        ((ChunkQ*)chunk)->FUN_00e3cd20(m_eScriptError, aabb, &m_vScale);
    else
        m_kChunks.m_data[chunk->m_kSmartReference].FUN_00e3cd20(m_eScriptError, aabb, &m_vScale);

    if (chunk->m_iSectionVertexCount != 0xffff)
    {
        const hkTransform& t = m_kTransforms.m_data[chunk->m_iSectionVertexCount];
        QuadVector c0, c1, c2, tr;
        c0.v = t.m_rotation.m_kColumn0;
        c1.v = t.m_rotation.m_kColumn1;
        c2.v = t.m_rotation.m_kColumn2;
        tr.v = t.m_vTranslation;
        TransformQ scaled;
        scaled.m_kColumn0.m_vComponents = c0.q;
        scaled.m_kColumn1.m_vComponents = c1.q;
        scaled.m_kColumn2.m_vComponents = c2.q;
        scaled.m_vTranslation.m_vComponents = _mm_mul_ps(tr.q, m_vScale.m_vComponents);
        aabb->m_kMaximumCorner.FUN_00c7f640(&scaled, &aabb->m_kMaximumCorner);
        aabb->m_kMinimumCorner.FUN_00c7f640(&scaled, &aabb->m_kMinimumCorner);
    }
}
}  // namespace fnv_00e3d250

namespace fnv_00e3d380 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, __m128);
}

extern __m128 DAT_010c71d0;

void __cdecl FUN_00d26230(const hkTransform& localToWorld, const hkVector4& halfExtents, const hkVector4& center,
                          float tolerance, hkAabb& out);

struct CompressedMeshQ : hkpCompressedMeshShape
{
    void FUN_00e3d380(const hkTransform& localToWorld, float tolerance, hkAabb& out) const;
};

__forceinline __m128 LD(const hkVector4& v)
{
    return *reinterpret_cast<const __m128*>(&v);
}
__forceinline void ST(hkVector4& v, __m128 q)
{
    *reinterpret_cast<__m128*>(&v) = q;
}

__forceinline void getCenter(const hkAabb& b, hkVector4& c)
{
    ST(c, _mm_mul_ps(_mm_add_ps(LD(b.m_kMinimumCorner), LD(b.m_kMaximumCorner)), DAT_010c71d0));
}
__forceinline void getHalfExtents(const hkAabb& b, hkVector4& he)
{
    ST(he, _mm_mul_ps(_mm_sub_ps(LD(b.m_kMaximumCorner), LD(b.m_kMinimumCorner)), DAT_010c71d0));
}

// Computes the world-space AABB of the compressed mesh by transforming its bounds center and half extents with the given tolerance.
// @fnv 0x00e3d380
void CompressedMeshQ::FUN_00e3d380(const hkTransform& localToWorld, float tolerance, hkAabb& out) const
{
    hkVector4 center;
    getCenter(m_kBounds, center);
    hkVector4 halfExtents;
    getHalfExtents(m_kBounds, halfExtents);
    FUN_00d26230(localToWorld, halfExtents, center, tolerance, out);
}
}  // namespace fnv_00e3d380

// Returns the next key of the shape: big triangles first (chunk id 0), then the compressed
// chunks (chunk id 1..maxChunk-1), then the convex pieces (chunk id maxChunk).
// Key layout: bitsPerWIndex = chunk id, wIndexMask/indexMask = element index,
// bitsPerIndex = the winding bit of the returned triangle.

class hkpCompressedMeshShapeChunkE3CB
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    int m_iIndexCount;
    unsigned int unk24;
    unsigned short* m_pStripIndices;
    int m_numStrips;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    hkUint16 m_kSmartReference;  // 0xffff: no reference, otherwise an index into the chunk array
    unsigned short unk46;
    unsigned int unk48, unk4c;

    int FUN_00e3ca10(int iIndex, int& iWinding) throw();
};

class hkpShapeContainerE3CB
{
  public:
    virtual ~hkpShapeContainerE3CB() throw();
    virtual int GetNumChildShapes() const throw();
    virtual unsigned int GetFirstKey() const throw();
    virtual unsigned int FUN_00e3cb10(unsigned int uiOldKey) throw() = 0;
};

class hkpCompressedMeshShapeE3CB : public hkpShape, public hkpShapeContainerE3CB
{
  public:
    hkBool m_bDisableWelding;
    hkUint8 m_eCollectionType;
    unsigned short unk16;
    hkInt32 m_iBitsPerIndex;
    hkInt32 m_iBitsPerWIndex;
    hkInt32 m_iNumBitsForIndex;
    hkInt32 m_iNumBitsForWIndex;
    hkReal m_fSphereRadius;
    hkUint8 m_eWeldingType;
    hkUint8 m_ucMaterialType;
    unsigned short unk2e;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkTransform> m_kTransforms;
    hkArray<hkVector4> m_kBigVertices;
    hkArray<hkpCompressedMeshShapeBigTriangle> m_kBigTriangles;
    hkArray<hkpCompressedMeshShapeChunkE3CB> m_kChunks;
    hkArray<hkpCompressedMeshShapeConvexPiece> m_kConvexPieces;

    unsigned int FUN_00e3cb10(unsigned int uiOldKey) throw();
};

__declspec(noinline) int hkpCompressedMeshShapeChunkE3CB::FUN_00e3ca10(int index, int& winding) throw()
{
    winding = 0;
    if (index < 0)
        return m_iIndexCount ? 0 : -1;
    ++index;
    int strip = 0, end = 0, start = 0;
    for (; strip < m_numStrips; ++strip)
    {
        start = end;
        end += m_pStripIndices[strip];
        if (index < end)
            break;
    }
    if (strip >= m_numStrips)
    {
        while ((index - end) % 3)
            ++index;
    }
    else if (index >= end - 2)
    {
        index = end;
    }
    else
    {
        winding = (index - start) & 1;
    }
    return index < m_iIndexCount ? index : -1;
}

// Computes the next key in the compressed mesh shape key space by traversing big triangles, chunks, and convex pieces.
// @fnv 0x00e3cb10
unsigned int hkpCompressedMeshShapeE3CB::FUN_00e3cb10(unsigned int uiOldKey) throw()
{
    int i = (int)uiOldKey;
    hkArray<hkpCompressedMeshShapeChunkE3CB>& chunks = m_kChunks;
    const int iBitsPerWIndex = m_iBitsPerWIndex;
    unsigned int uiChunkId = (unsigned int)i >> iBitsPerWIndex;
    int iIndex = i & m_iNumBitsForWIndex;
    if (uiChunkId == 0)
    {
        // the big triangles come first
        iIndex++;
        if (iIndex < m_kBigTriangles.m_iElementCount)
            return (unsigned int)iIndex;
        uiChunkId = 1;
        iIndex = -1;
    }
    const unsigned int uiMaxChunk = (1u << (32 - iBitsPerWIndex)) - 1;
    if (uiChunkId != uiMaxChunk)
    {
        // walk the compressed chunks
        int i = (int)uiChunkId - 1;
        const int iNumChunks = chunks.m_iElementCount;
        if (i < iNumChunks)
        {
            hkpCompressedMeshShapeChunkE3CB* pkChunks = chunks.m_data;
            do
            {
                hkpCompressedMeshShapeChunkE3CB* pkChunk = &pkChunks[i];
                int iWinding = 0;
                if (pkChunk->m_kSmartReference != 0xffff)
                    iIndex = chunks.m_data[pkChunk->m_kSmartReference].FUN_00e3ca10(iIndex, iWinding);
                else
                    iIndex = pkChunk->FUN_00e3ca10(iIndex, iWinding);
                if (iIndex != -1 && iIndex <= m_iNumBitsForWIndex)
                    return ((iWinding & 1) << m_iBitsPerIndex) | ((i + 1) << iBitsPerWIndex) |
                           (iIndex & m_iNumBitsForIndex);
                iIndex = -1;
                i++;
            } while (i < iNumChunks);
        }
    }
    // the convex pieces come last
    iIndex++;
    if (iIndex < m_kConvexPieces.m_iElementCount)
        return (uiMaxChunk << iBitsPerWIndex) | (unsigned int)iIndex;
    return 0xffffffff;
}

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int mask);

class CompressedChunk
{
  public:
    hkVector4q m_offset;
    hkUint16* m_kVertices;
    int m_iStridedVertexCount;
    int m_verticesCapacity;

    __forceinline void getVertex(unsigned int index, hkReal error, hkVector4q& vertex) const
    {
        hkVector4q quantized;
        quantized.set(m_kVertices[index], m_kVertices[index + 1], m_kVertices[index + 2], 0.0f);
        __m128 scale = _mm_load_ss(&error);
        scale = _mm_shuffle_ps(scale, scale, 0);
        vertex.m_vComponents = _mm_add_ps(_mm_mul_ps(quantized.m_vComponents, scale), m_offset.m_vComponents);
    }

    void FUN_00e3cd50(unsigned int i0, unsigned int i1, unsigned int i2, hkReal error, hkVector4q& v0, hkVector4q& v1,
                      hkVector4q& v2) const;
};

// Calls getVertex for i0, i1 and i2 to write v0, v1 and v2, each uint16 triple scaled by error and offset by m_offset.
// @fnv 0x00e3cd50
void CompressedChunk::FUN_00e3cd50(unsigned int i0, unsigned int i1, unsigned int i2, hkReal error, hkVector4q& v0,
                                   hkVector4q& v1, hkVector4q& v2) const
{
    getVertex(i0, error, v0);
    getVertex(i1, error, v1);
    getVertex(i2, error, v2);
}

extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const float* p);
    void _mm_store_ps(float* p, __m128 a);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
}
inline void* operator new(unsigned int, void* memory)
{
    return memory;
}

struct __declspec(align(16)) Vector
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        __m128 q;
    };
    void FUN_00c7f640(const struct Transform& transform, const Vector& source);
};
struct Transform
{
    Vector x, y, z, translation;
};
extern Vector DAT_01268370;
extern Vector DAT_01268380;
extern Vector DAT_01268390;
extern Vector DAT_012683a0;
extern float DAT_011b153c;
extern float DAT_0104da48, DAT_0104e148, DAT_01011d78;
extern Vector DAT_010c71d0;
extern int DAT_010c749c;
struct VertexBlock
{
    Vector x, y, z;
};
struct Bounds
{
    Vector minimum, maximum;
};
extern VertexBlock DAT_0126ec10[];
struct ConvexPiece
{
    Vector offset;
    hkArray<hkUint16> vertices;
    hkArray<hkUint8> faces;
    hkArray<hkUint8> indices;
    hkUint16 reference, transform;
    unsigned int material;
    unsigned int unk3c;
};
struct Chunk
{
    Vector offset;
    hkArray<hkUint16> vertices;
    hkArray<hkUint16> indices;
    hkArray<hkUint16> strips;
    hkArray<hkUint16> welding;
    unsigned int unk40;
    hkUint16 reference, transform;
    unsigned int material;
    unsigned int unk4c;
    void FUN_00e3cd50(int a, int b, int c, float error, Vector& va, Vector& vb, Vector& vc);
};
struct BigTriangle
{
    hkUint16 a, b, c, unk06;
    unsigned int material;
    hkUint16 welding, unk0e;
};
inline __m128 MulV(const Vector& a, const Vector& b)
{
    return _mm_mul_ps(*(const __m128*)&a, *(const __m128*)&b);
}
inline __m128 MulQ(__m128 a, __m128 b)
{
    return _mm_mul_ps(a, b);
}
struct Triangle
{
    int* vtable;
    hkUint16 memorySize, references;
    unsigned int userData, type;
    float radius;
    hkUint16 welding;
    hkUint8 weldingType, extruded;
    Vector vertices[3], extrusion;
    __forceinline Triangle(float r)
    {
        references = 1;
        userData = 0;
        type = 3;
        radius = r;
        vtable = &DAT_010c749c;
        welding = 0;
        weldingType = 6;
        *(__m128*)&extrusion = _mm_setzero_ps();
        extruded = 0;
    }
};
struct ConvexShape
{
    int* vtable;
    hkUint16 memorySize, references;
    unsigned int userData, type;
    float radius;
    unsigned int unk14, unk18, unk1c;
    Vector halfExtents, center;
    VertexBlock* vertices;
    int blockCount, capacity, vertexCount;
    ConvexPiece* piece;
    ConvexShape(float radius);
};
struct ShapeBuffer
{
    ConvexShape* FUN_00d59710(float radius);
};
struct BufferRef
{
    ShapeBuffer* p;
    operator bool() const
    {
        return p != 0;
    }
    ShapeBuffer* operator->() const
    {
        return p;
    }
};
struct Mesh : hkReferencedObject
{
    int bitsPerIndex, bitsPerWIndex, wIndexMask, indexMask;
    float radius;
    hkUint8 weldingType, materialType;
    hkUint16 unk1e;
    hkArray<unsigned int> materials;
    hkArray<hkUint16> materials16;
    hkArray<hkUint8> materials8;
    hkArray<hkTransform> transforms;
    hkArray<hkVector4> bigVertices;
    hkArray<BigTriangle> bigTriangles;
    hkArray<Chunk> chunks;
    hkArray<ConvexPiece> convexPieces;
    float error;
    unsigned int unk84, unk88, unk8c;
    hkAabb bounds;
    void* meshMaterials;
    hkUint16 materialStriding, numMaterials;
    hkArray<void*> namedMaterials;
    unsigned int unkc4, unkc8, unkcc;
    float scaleX, scaleY, scaleZ, scaleW;
    Triangle* FUN_00e3d3f0(unsigned int key, BufferRef buffer);
};

// Decodes key into a big triangle, chunk triangle or convex piece, applies its transform and scale, and returns a Triangle or ConvexShape built in buffer.
// @fnv 0x00e3d3f0
Triangle* Mesh::FUN_00e3d3f0(unsigned int key, BufferRef buffer)
{
    int index;
    (void)index;
    int count;
    (void)count;
    int iBlockCount;
    (void)iBlockCount;
    BufferRef bufv = buffer;
    unsigned int chunkIndex = key >> bitsPerWIndex;
    index = key & wIndexMask;
    int winding = index >> bitsPerIndex;
    Transform transform;
    if (chunkIndex == (1 << (32 - bitsPerWIndex)) - 1)
    {
        _mm_store_ps(&transform.x.x, _mm_load_ps(&DAT_01268370.x));
        _mm_store_ps(&transform.y.x, _mm_load_ps(&DAT_01268380.x));
        _mm_store_ps(&transform.z.x, _mm_load_ps(&DAT_01268390.x));
        _mm_store_ps(&transform.translation.x, _mm_load_ps(&DAT_012683a0.x));
        ConvexShape* shape = bufv ? bufv->FUN_00d59710(radius) : 0;
        ConvexPiece* pieces = convexPieces.m_data;
        if (pieces[index].transform != 0xffff)
        {
            hkTransform& t = transforms.m_data[pieces[index].transform];
            _mm_store_ps(&transform.x.x, _mm_load_ps(&t.m_rotation.m_kColumn0.x));
            _mm_store_ps(&transform.y.x, _mm_load_ps(&t.m_rotation.m_kColumn1.x));
            _mm_store_ps(&transform.z.x, _mm_load_ps(&t.m_rotation.m_kColumn2.x));
            _mm_store_ps(&transform.translation.x, _mm_load_ps(&t.m_vTranslation.x));
        }
        if (pieces[index].reference != 0xffff)
            index = pieces[index].reference;
        ConvexPiece* piece = &pieces[index];
        const hkUint16* vertices = piece->vertices.m_data;
        count = piece->vertices.m_iElementCount / 3;
        iBlockCount = (count + 3) >> 2;
        Bounds bounds;
        __m128& minimum = *(__m128*)&bounds.minimum;
        __m128& maximum = *(__m128*)&bounds.maximum;
        minimum = _mm_set_ps1(DAT_0104da48);
        maximum = _mm_set_ps1(DAT_0104e148);
        __m128 tolerance = _mm_load_ss(&error);
        int vertex = 0;
        VertexBlock* output = DAT_0126ec10 + 1;
        int iv;
        Vector v[4];
        for (int i = 0; i < iBlockCount; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                float fx, fy, afDepth;
                *&iv = vertices[0];
                fx = (float)((float)iv);
                *&iv = vertices[1];
                fy = (float)iv;
                *&iv = vertices[2];
                afDepth = (float)iv;
                Vector source;
                _mm_store_ps(&source.x, _mm_add_ps(_mm_mul_ps(_mm_setr_ps(fx, fy, afDepth, DAT_01011d78),
                                                              _mm_shuffle_ps(tolerance, tolerance, 0)),
                                                   *(const __m128*)&piece->offset));
                v[j].FUN_00c7f640(transform, source);
                minimum = _mm_min_ps(minimum, _mm_load_ps(&source.x));
                maximum = _mm_max_ps(maximum, _mm_load_ps(&source.x));
                if (vertex < count - 1)
                {
                    ++vertex;
                    vertices += 3;
                }
            }
            __m128& r0 = *(__m128*)&v[0];
            __m128& r1 = *(__m128*)&v[1];
            __m128& r2 = *(__m128*)&v[2];
            __m128& r3 = *(__m128*)&v[3];
            __m128 tmp3, tmp2, tmp1, tmp0;
            tmp0 = _mm_shuffle_ps(r0, r1, 0x44);
            tmp2 = _mm_shuffle_ps(r0, r1, 0xEE);
            tmp1 = _mm_shuffle_ps(r2, r3, 0x44);
            tmp3 = _mm_shuffle_ps(r2, r3, 0xEE);
            r0 = _mm_shuffle_ps(tmp0, tmp1, 0x88);
            r1 = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
            r2 = _mm_shuffle_ps(tmp2, tmp3, 0x88);
            r3 = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            *(__m128*)&output[-1].x = r0;
            *(__m128*)&output[-1].y = r1;
            *(__m128*)&output[-1].z = r2;
            ++output;
        }
        shape->vertices = DAT_0126ec10;
        shape->blockCount = iBlockCount;
        _ReadWriteBarrier();
        shape->capacity = 8;
        _ReadWriteBarrier();
        shape->vertexCount = count;
        _ReadWriteBarrier();
        shape->piece = piece;
        shape->halfExtents.q = _mm_mul_ps(_mm_sub_ps(maximum, minimum), _mm_load_ps(&DAT_010c71d0.x));
        shape->center.q = _mm_mul_ps(_mm_add_ps(maximum, minimum), _mm_load_ps(&DAT_010c71d0.x));
        return reinterpret_cast<Triangle*>(shape);
    }
    Triangle* triangle = new (bufv.p) Triangle(DAT_011b153c);
    {
        Triangle* __restrict tt = triangle;
        tt->radius = radius;
    }
    triangle->weldingType = weldingType;
    if (chunkIndex == 0)
    {
        Triangle* __restrict tr = triangle;
        tr->welding = bigTriangles.m_data[index].welding;
        BigTriangle& big = bigTriangles.m_data[index];
        unsigned int iVertexA = big.a;
        const hkVector4* pBigVertices = bigVertices.m_data;
        _mm_store_ps(&tr->vertices[0].x, _mm_load_ps(&pBigVertices[iVertexA].x));
        _mm_store_ps(&tr->vertices[1].x, _mm_load_ps(&pBigVertices[big.b].x));
        _mm_store_ps(&tr->vertices[2].x, _mm_load_ps(&pBigVertices[big.c].x));
        Vector scalev;
        *(hkVector4*)&scalev = *(const hkVector4*)&scaleX;
        _mm_store_ps(&tr->vertices[0].x, MulV(scalev, tr->vertices[0]));
        _mm_store_ps(&tr->vertices[1].x, MulV(tr->vertices[1], scalev));
        _mm_store_ps(&triangle->vertices[2].x, MulQ(triangle->vertices[2].q, scalev.q));
        return triangle;
    }
    index &= indexMask;
    --chunkIndex;
    _mm_store_ps(&transform.x.x, _mm_setzero_ps());
    transform.x.x = 1.0f;
    _mm_store_ps(&transform.y.x, _mm_setzero_ps());
    transform.y.y = 1.0f;
    _mm_store_ps(&transform.z.x, _mm_setzero_ps());
    transform.z.z = 1.0f;
    _mm_store_ps(&transform.translation.x, _mm_setzero_ps());
    if (chunks.m_data[chunkIndex].transform != 0xffff)
    {
        hkTransform& t = transforms.m_data[chunks.m_data[chunkIndex].transform];
        _mm_store_ps(&transform.x.x, _mm_load_ps(&t.m_rotation.m_kColumn0.x));
        _mm_store_ps(&transform.y.x, _mm_load_ps(&t.m_rotation.m_kColumn1.x));
        _mm_store_ps(&transform.z.x, _mm_load_ps(&t.m_rotation.m_kColumn2.x));
        _mm_store_ps(&transform.translation.x, _mm_load_ps(&t.m_vTranslation.x));
    }
    if (chunks.m_data[chunkIndex].reference != 0xffff)
        chunkIndex = chunks.m_data[chunkIndex].reference;
    Chunk* chunk = &chunks.m_data[chunkIndex];
    Triangle* __restrict tw = triangle;
    tw->welding = chunk->welding.m_data[index];
    {
        Vector a, b, c;
        const hkUint16* indices = chunk->indices.m_data;
        chunk->FUN_00e3cd50(indices[index] * 3, indices[index + 1] * 3, indices[index + 2] * 3, error, a, b, c);
        a.FUN_00c7f640(transform, a);
        b.FUN_00c7f640(transform, b);
        c.FUN_00c7f640(transform, c);
        Triangle* __restrict tc = triangle;
        Vector scalev2;
        *(hkVector4*)&scalev2 = *(const hkVector4*)&scaleX;
        *(__m128*)&a = _mm_mul_ps(*(__m128*)&a, *(__m128*)&scalev2);
        *(__m128*)&b = _mm_mul_ps(*(__m128*)&b, *(__m128*)&scalev2);
        *(__m128*)&c = _mm_mul_ps(*(__m128*)&c, *(__m128*)&scalev2);
        *(__m128*)&tc->vertices[2 * winding] = *(__m128*)&a;
        *(__m128*)&tc->vertices[1] = *(__m128*)&b;
        *(__m128*)&tc->vertices[2 * (winding ^ 1)] = *(__m128*)&c;
        return triangle;
    }
}

void __cdecl FUN_00c908c0(hkMemoryAllocatorE3D& alloc, void* array, int numElem, int sizeElem);

template <class T> struct hkArr
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
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void _setSize(hkMemoryAllocatorE3D& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(GetMemoryRouterE3D().heap(), n);
    }
};

struct ConvexVertexDecoder : CompressedChunk
{
    void FUN_00e3d9d0(hkReal quantization, const hkTransform& transform, hkArr<hkVector4q>& vertices) const;
};

// Expands the compressed vertex data into hkVector4q entries, applying quantization, offset, and transform to fill the output array.
// @fnv 0x00e3d9d0
void ConvexVertexDecoder::FUN_00e3d9d0(hkReal quantization, const hkTransform& transform,
                                       hkArr<hkVector4q>& vertices) const
{
    vertices.SetSizeAndGrow(m_iStridedVertexCount / 3);
    for (int i = 0; i < m_iStridedVertexCount; i += 3)
    {
        hkVector4q vertex;
        vertex.set(m_kVertices[i], m_kVertices[i + 1], m_kVertices[i + 2], 0.0f);
        __m128 q = _mm_load_ss(&quantization);
        vertex.m_vComponents = _mm_mul_ps(vertex.m_vComponents, _mm_shuffle_ps(q, q, 0));
        vertex.add4(m_offset);
        vertex.FUN_00c7f640(transform, vertex);
        vertices[i / 3].m_vComponents = vertex.m_vComponents;
    }
}

struct FUN_00d21410_Obj
{
    void __thiscall FUN_00d21410(int a1, int a2);
};

extern int DAT_010eba5c;
extern int DAT_010eba3c;
extern float DAT_01012068;

struct FUN_00e3dae0_Class
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* unk10;
    unsigned int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    float unk28;
    volatile unsigned char unk2C;
    unsigned char unk2D;
    unsigned short unk2E;
    unsigned int volatile unk30;
    unsigned int volatile unk34;
    unsigned int volatile unk38;
    unsigned int volatile unk3C;
    unsigned int volatile unk40;
    unsigned int volatile unk44;
    unsigned int volatile unk48;
    unsigned int volatile unk4C;
    unsigned int volatile unk50;
    unsigned int volatile unk54;
    unsigned int volatile unk58;
    unsigned int volatile unk5C;
    unsigned int volatile unk60;
    unsigned int volatile unk64;
    unsigned int volatile unk68;
    unsigned int volatile unk6C;
    unsigned int volatile unk70;
    unsigned int volatile unk74;
    unsigned int volatile unk78;
    unsigned int volatile unk7C;
    unsigned int volatile unk80;
    unsigned int volatile unk84;
    unsigned int volatile unk88;
    unsigned int volatile unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int volatile unkC0;
    unsigned short volatile unkC4;
    unsigned short volatile unkC6;
    unsigned int volatile unkC8;
    unsigned int volatile unkCC;
    unsigned int volatile unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    float unkE0;
    float unkE4;
    float unkE8;
    float unkEC;

    FUN_00e3dae0_Class* __thiscall FUN_00e3dae0(float value);
};

// Initializes the object with a float value, sets default state fields, and returns this.
// @fnv 0x00e3dae0
FUN_00e3dae0_Class* __thiscall FUN_00e3dae0_Class::FUN_00e3dae0(float value)
{
    reinterpret_cast<FUN_00d21410_Obj*>(this)->FUN_00d21410(0x10, 6);

    unk28 = value;
    unk00 = &DAT_010eba5c;
    unk10 = &DAT_010eba3c;
    unk18 = 0x11;
    unk1C = 0x12;
    unk20 = 0x3FFFF;
    unk24 = 0x1FFFF;
    __m128 constantVector = _mm_set_ps1(DAT_01012068);

    unk30 = 0;
    unk34 = 0;
    unk38 = 0x80000000;
    unk3C = 0;
    unk40 = 0;
    unk44 = 0x80000000;
    unk48 = 0;
    unk4C = 0;
    unk50 = 0x80000000;
    unk54 = 0;
    unk58 = 0;
    unk5C = 0x80000000;
    unk60 = 0;
    unk64 = 0;
    unk68 = 0x80000000;
    unk6C = 0;
    unk70 = 0;
    unk74 = 0x80000000;
    unk78 = 0;
    unk7C = 0;
    unk80 = 0x80000000;
    unk84 = 0;
    unk88 = 0;
    unk8C = 0x80000000;

    unkC0 = 0;
    unkC4 = 0;
    unkC6 = 0;
    unkC8 = 0;
    unkCC = 0;
    unkD0 = 0x80000000;

    unk2C = 6;
    *reinterpret_cast<__m128*>(&unkE0) = constantVector;

    return this;
}

class hkpCompressedMeshShapeBigTriangle
{
  public:
    unsigned short a, b, c, weldingInfo;
    unsigned material;
    unsigned unk0c;
};
struct MaterialLookupE3D0 : hkpCompressedMeshShape
{
    void* FUN_00e3d0e0(unsigned key);
};
// Resolves a material index from a compressed mesh key and returns a pointer into the material data buffer.
// @fnv 0x00e3d0e0
void* MaterialLookupE3D0::FUN_00e3d0e0(unsigned key)
{
    char* materials = (char*)m_pUserData;
    if (!materials)
        return 0;
    unsigned chunkIndex = key >> m_iBitsPerWIndex;
    unsigned triangle = key & m_iNumBitsForWIndex;
    if (chunkIndex == 0)
    {
        triangle = m_kBigTriangles.m_data[triangle].material;
    }
    else
    {
        if (chunkIndex == ((1u << (32 - m_iBitsPerWIndex)) - 1))
            return 0;
        unsigned short reference = m_kChunks.m_data[chunkIndex - 1].reference;
        if (reference != 0xffff)
            chunkIndex = reference;
        else
            --chunkIndex;
        unsigned int material = m_kChunks.m_data[chunkIndex].materialInfo;
        switch ((unsigned int)m_ucMaterialType)
        {
        case MATERIAL_SINGLE_VALUE_PER_CHUNK:
            triangle = material;
            break;
        case MATERIAL_FOUR_BYTES_PER_TRIANGLE:
            triangle = m_kMaterials.m_data[material + triangle];
            break;
        case MATERIAL_TWO_BYTES_PER_TRIANGLE:
            triangle = m_kMaterialIndices16.m_data[material + triangle];
            break;
        case MATERIAL_ONE_BYTE_PER_TRIANGLE:
            triangle = m_kMaterialIndices8.m_data[material + triangle];
            break;
        default:
            return 0;
        }
    }
    return materials + m_iIndexStriding * triangle;
}

struct ChunkAabbCalls_00e3cf40
{
    void FUN_00e3cd20(float, hkVector4*, hkVector4*);
};
struct CompressedMeshAabbQuery_00e3cf40 : hkpCompressedMeshShape
{
    void FUN_00e3cf40(hkAabbq* out);
};

// Computes the bounding box by expanding an initial AABB with the AABB of each chunk in m_kChunks.
// @fnv 0x00e3cf40
void CompressedMeshAabbQuery_00e3cf40::FUN_00e3cf40(hkAabbq* out)
{
    out->m_kMinimumCorner.SetAllComponents(DAT_0104da48);
    out->m_kMaximumCorner.SetAllComponents(DAT_0104e148);
    for (int i = 0; i < m_kChunks.m_iElementCount; i++)
    {
        hkAabbq aabb;
        ((ChunkAabbCalls_00e3cf40&)m_kChunks.m_data[i])
            .FUN_00e3cd20(m_eScriptError, (hkVector4*)&aabb, (hkVector4*)&padD4[0xC]);
        out->m_kMinimumCorner.setMin4(out->m_kMinimumCorner, aabb.m_kMinimumCorner);
        out->m_kMaximumCorner.setMax4(out->m_kMaximumCorner, aabb.m_kMaximumCorner);
    }
}

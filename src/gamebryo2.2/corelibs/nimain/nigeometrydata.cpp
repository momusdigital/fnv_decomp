// gamebryo2.2/corelibs/nimain/nigeometrydata.cpp: NiGeometryData, NiGeometryDataRecovered, NiGeometryDataCmp, GeomData and more (36 functions)

#include "nigeometrydata_decls.h"

// If additional geometry data is absent or not packed, updates the consistency bits of m_usDirtyFlags to eConsistency.
// @fnv 0x00a67050
void NiGeometryData::SetDataConsistency(Consistency eConsistency)
{
    if (m_spAdditionalGeomData.m_pObject != NULL && m_spAdditionalGeomData.m_pObject->IsPacked())
    {
        return;
    }
    m_usDirtyFlags = (m_usDirtyFlags & ~CONSISTENCY_MASK) | eConsistency;
}

// ORs the low 12 bits of uiDirtyFlags into m_usDirtyFlags unless the additional geometry data object exists and is packed.
// @fnv 0x00a67090
void NiGeometryData::SetDirtyFlags(unsigned int uiDirtyFlags)
{
    if (m_spAdditionalGeomData.m_pObject != NULL && m_spAdditionalGeomData.m_pObject->IsPacked())
    {
        return;
    }
    m_usDirtyFlags |= (uiDirtyFlags & 0xFFF);
}

// Registers the object and its additional geometry data with the stream, returning false if either registration fails.
// @fnv 0x00a66f50
bool NiGeometryData::RegisterStreamables(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    NiAdditionalGeometryData* pkAdditional = m_spAdditionalGeomData.m_pObject;
    if (pkAdditional)
    {
        if (!pkAdditional->RegisterStreamables(kStream))
            return false;
    }
    return true;
}

// @fnv 0x00a677e0
void NiGeometryData::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);

    if (kStream.GetFileVersion() >= 0x0A030007)
    {
        NiAdditionalGeometryData* pkAdditional = (NiAdditionalGeometryData*)kStream.GetLoadedObject();
        if (m_spAdditionalGeomData.m_pObject != pkAdditional)
        {
            if (m_spAdditionalGeomData.m_pObject)
                m_spAdditionalGeomData.m_pObject->DecRefCount();
            m_spAdditionalGeomData.m_pObject = pkAdditional;
            if (m_spAdditionalGeomData.m_pObject)
                m_spAdditionalGeomData.m_pObject->IncRefCount();
        }
    }
}

// @fnv 0x00a67360
bool NiGeometryData::IsGeometryDataStreamable(bool bWrite)
{
    if (m_bIsDynamic)
        return false;
    NiAdditionalGeometryData* pkAdditional = m_spAdditionalGeomData.m_pObject;
    if (pkAdditional && pkAdditional->IsPacked())
    {
        if (bWrite)
            pkAdditional->FUN_00a725d0(0);
        else
        {
            unsigned int uiSize = 0;
            pkAdditional->FUN_00a72590(0, &uiSize);
        }
    }
    m_bBoundDirty = bWrite;
    m_bIsDynamic = true;
    return true;
}

#pragma optimize("", off)
// @fnv 0x004410f0
void NiGeometryData::SetCompressFlags(unsigned char ucCompressFlags)
{
    m_ucCompressFlags = ucCompressFlags;
}
#pragma optimize("", on)

struct FUN_00a673d0_shell : public NiGeometryData
{
    void FUN_00a673d0();
};

// @fnv 0x00a673d0
void FUN_00a673d0_shell::FUN_00a673d0()
{
    if (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x3a))
    {
        NiAdditionalGeometryData* pkAGD =
            *reinterpret_cast<NiAdditionalGeometryData**>(reinterpret_cast<char*>(this) + 0x30);
        if (pkAGD && pkAGD->IsPacked() && !*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x3b))
        {
            pkAGD->FUN_00a725d0(0);
        }
        *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x3a) = false;
    }
}

extern NiObjectGroup* DAT_011f4880;
// @fnv 0x00a669c0
NiObjectGroup* __cdecl FUN_00a669c0()
{
    return DAT_011f4880;
}

extern NiObjectGroup* DAT_011f4880;
// @fnv 0x00a669d0
void __stdcall FUN_00a669d0(NiObjectGroup* pkGroup)
{
    DAT_011f4880 = pkGroup;
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00a67000_shell
{
    char pad[0x24];
    void* m_pvBuf;
    void FreeBuffer();
};
// @fnv 0x00a67000
void FUN_00a67000_shell::FreeBuffer()
{
    if (m_pvBuf)
    {
        g_memoryManager.Deallocate(m_pvBuf);
        m_pvBuf = 0;
    }
}

struct FUN_00a67020_shell
{
    char pad[0x10];
    NiBound m_kBound;
    void FUN_00a67020(NiBound* kBound);
};
// @fnv 0x00a67020
void FUN_00a67020_shell::FUN_00a67020(NiBound* kBound)
{
    if (kBound)
    {
        float fRadius = m_kBound.m_fBoundRadius;
        kBound->m_kCenter = m_kBound.m_kCenter;
        kBound->m_fBoundRadius = fRadius;
    }
}

extern const char* const g_011f5b88_arg1;
// @fnv 0x00a67bf0
const char* const* __cdecl FUN_00a67bf0()
{
    return &g_011f5b88_arg1;
}

struct NiAdd
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool v35();
};
struct _Call_a5d3a0
{
    _Call_a5d3a0();
    virtual void bvf();
    int m_rc;
};
struct SP
{
    NiAdd* m_p;
    SP& operator=(NiAdd* p)
    {
        m_p = p;
        return *this;
    }
    NiAdd* operator->() const
    {
        return m_p;
    }
    operator NiAdd*() const
    {
        return m_p;
    }
};
struct FUN_00a67c00 : _Call_a5d3a0
{
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    char m_kBound[16];
    void* m_pkVertex;
    void* m_pkNormal;
    void* m_pkColor;
    void* m_pkTexture;
    SP m_spAdd;
    void* m_pkGeometryRendererData;
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
    bool m_bIsDynamic;
    bool m_bBoundDirty;
    bool m_bVerticesDirty;
    FUN_00a67c00();
};
// @fnv 0x00a67c00
FUN_00a67c00::FUN_00a67c00()
{
    m_usVertices = 0;
    m_usTrianglePoints = 0;
    m_usDirtyFlags = 0;
    m_pkVertex = 0;
    m_pkNormal = 0;
    m_pkColor = 0;
    m_pkTexture = 0;
    m_spAdd = 0;
    m_pkGeometryRendererData = 0;
    m_ucKeepFlags = 0;
    m_ucCompressFlags = 0;
    m_bIsDynamic = false;
    m_bBoundDirty = false;
    m_bVerticesDirty = true;
    if (!m_spAdd || !m_spAdd->v35())
        m_usDirtyFlags &= 0x8fff;
}

void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_00a68800_shell
{
    void DestroyGeometryData();
    void* FUN_00a68800(unsigned int flags);
};
// @fnv 0x00a68800
void* FUN_00a68800_shell::FUN_00a68800(unsigned int flags)
{
    DestroyGeometryData();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x40);
    return this;
}

struct FUN_00a725d0_shell
{
    char pad[8];
    unsigned int m_uiRefCount;
    char pad2[0x14];
    void*** m_ppChildren;
    char pad3[2];
    unsigned short m_usElementCount;
    void FUN_00a725d0(unsigned int idx);
};
struct VObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
};
struct FUN_00a725d0_shell2
{
    char pad[8];
    int m_uiValueCount;
    char pad2[0x14];
    VObj** m_aiIndexedValues;
    char pad3[2];
    unsigned short m_us;
    void FUN_00a725d0(unsigned int idx);
};
// @fnv 0x00a725d0
void FUN_00a725d0_shell2::FUN_00a725d0(unsigned int uiIndex)
{
    if (uiIndex < m_us)
    {
        VObj* p = m_aiIndexedValues[uiIndex];
        if (p)
        {
            p->f3(0, 0);
            ++m_uiValueCount;
        }
    }
}

struct NiGeometryData_shell
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usVertices;
    unsigned short m_usTrianglePoints;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    RgbaColor* m_pkColor;
    NiPoint2* m_pkTexture;
    void FUN_00a66bb0(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, RgbaColor* pkColor,
                      NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned short eNBTMethod);
};

// Stores vertex count, vertex/normal/color/texture pointers, and packs texture-set count and NBT method into the flags field.
// @fnv 0x00a66bb0
void NiGeometryData_shell::FUN_00a66bb0(unsigned short ausVertexCount, NiPoint3* pkVertex, NiPoint3* pkNormal,
                                        RgbaColor* pkColor, NiPoint2* pkTexture, unsigned short usNumTextureSets,
                                        unsigned short eNBTMethod)
{
    *(unsigned short*)((char*)this + 8) = ausVertexCount;
    *(NiPoint3**)((char*)this + 0x20) = pkVertex;
    *(NiPoint3**)((char*)this + 0x24) = pkNormal;
    *(RgbaColor**)((char*)this + 0x28) = pkColor;
    *(NiPoint2**)((char*)this + 0x2c) = pkTexture;
    *(unsigned short*)((char*)this + 0xc) =
        (*(unsigned short*)((char*)this + 0xc) & 0xFFE) | ((usNumTextureSets & 1)) | eNBTMethod;
}

namespace fnv_00a67c70 {
struct FUN_00a67c70_shell : public NiGeometryData
{
    void DestroyGeometryData();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

struct NiRenderer
{
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void PurgeGeometryData(void* pkData);
    static NiRenderer* ms_pRenderer;
};
struct MemoryManager
{
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
void __cdecl _delete(void* p, unsigned int size);
struct NiObjectGroup
{
    unsigned char pad[0xc];
    unsigned int m_uiRefCount;
    void FUN_00a8a670();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
        {
            FUN_00a8a670();
            _delete(this, 0x10);
        }
    }
};
extern NiObjectGroup* DAT_011f4880;

struct RefStub_a67c70
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
inline void ReleaseRef_a67c70(RefStub_a67c70* p)
{
    if (InterlockedDecrement((long volatile*)&p->m_uiRefCount) == 0)
        p->DeleteThis();
}

struct FUN_00a67c00
{
    virtual __forceinline ~FUN_00a67c00()
    {
        char* self = (char*)this;
        if (NiRenderer::ms_pRenderer)
            NiRenderer::ms_pRenderer->PurgeGeometryData(this);
        RefStub_a67c70*& spAdditional = *(RefStub_a67c70**)(self + 0x30);
        if (spAdditional != 0)
        {
            ReleaseRef_a67c70(spAdditional);
            spAdditional = 0;
        }
        if (DAT_011f4880)
        {
            if (*(void**)(self + 0x20))
                DAT_011f4880->DecRefCount();
            if (*(void**)(self + 0x24))
                DAT_011f4880->DecRefCount();
            if (*(void**)(self + 0x28))
                DAT_011f4880->DecRefCount();
            if (*(void**)(self + 0x2c))
                DAT_011f4880->DecRefCount();
        }
        else
        {
            g_memoryManager.Deallocate(*(void**)(self + 0x20));
            g_memoryManager.Deallocate(*(void**)(self + 0x24));
            g_memoryManager.Deallocate(*(void**)(self + 0x28));
            g_memoryManager.Deallocate(*(void**)(self + 0x2c));
        }
        if (spAdditional)
            ReleaseRef_a67c70(spAdditional);
        ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    }
};

// Destructor wrapper that invokes the base geometry-data destructor on this object.
// @fnv 0x00a67c70
void FUN_00a67c70_shell::DestroyGeometryData()
{
    ((FUN_00a67c00*)this)->FUN_00a67c00::~FUN_00a67c00();
}
}  // namespace fnv_00a67c70

struct NiBoundProxy
{
    void ComputeBoundingSphere(unsigned int vertexCount, NiPoint3* vertices);
};
struct NiGeometryDataRecovered : NiGeometryData
{
    virtual void ReservedGeometryMethod27();
    virtual void ReservedGeometryMethod28();
    virtual void ReservedGeometryMethod29();
    virtual void ReservedGeometryMethod30();
    virtual void ReservedGeometryMethod31();
    virtual void ReservedGeometryMethod32();
    virtual void ReservedGeometryMethod33();
    virtual void ReservedGeometryMethod34();
    virtual void ReservedGeometryMethod35();
    virtual unsigned short GetActualVertexCount();
    void FUN_00a66b30(unsigned short vertexCount, NiPoint3* vertices, NiPoint3* normals, RgbaColor* colors,
                      NiPoint2* textureCoords, unsigned short textureSetCount, unsigned short normalBinormalMethod);
};
// @fnv 0x00a66b30
void NiGeometryDataRecovered::FUN_00a66b30(unsigned short vertexCount, NiPoint3* vertices, NiPoint3* normals,
                                           RgbaColor* colors, NiPoint2* textureCoords, unsigned short textureSetCount,
                                           unsigned short normalBinormalMethod)
{
    m_usVertices = vertexCount;
    m_pkVertex = vertices;
    m_pkNormal = normals;
    unsigned short actualCount = GetActualVertexCount();
    if (actualCount != 0 && m_pkVertex != 0)
        reinterpret_cast<NiBoundProxy*>(&m_kBound)->ComputeBoundingSphere(actualCount, m_pkVertex);
    m_pkColor = colors;
    m_pkTexture = textureCoords;
    m_usTrianglePoints = (m_usTrianglePoints & 0x0ffe) | (textureSetCount & 1) | normalBinormalMethod;
}

static __declspec(noinline) int CompareFloats(const float* pA, const float* pB, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        if (pA[i] < pB[i])
            return -1;
        if (pA[i] > pB[i])
            return 1;
    }
    return 0;
}

struct NiGeometryDataCmp
{
    void* m_ppVirtualMethodTable;
    int unk04;
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    float m_kBound0;
    float m_kBound1;
    float m_kBound2;
    float m_kBound3;
    float* m_pkVertex;
    float* m_pkNormal;
    float* m_pkColor;
    float* m_pkTexture;
    int CompareVertices(unsigned short usA, unsigned short usB, unsigned int uiFlags);
};

// Compares vertex, normal, color and texture data of two vertices selected by usA/usB according to uiFlags, returning -1, 1 or 0.
// @fnv 0x00a66db0
int NiGeometryDataCmp::CompareVertices(unsigned short usVertexA, unsigned short usVertexB, unsigned int uiCompareFlags)
{
    float* pkVertex;
    pkVertex = m_pkVertex;
    if (uiCompareFlags & 1)
    {
        const float* pB;
        pB = pkVertex + usVertexB * 3;
        const float* pA = pkVertex + usVertexA * 3;
        for (unsigned int i = 0; i < 3; i++)
        {
            if (pA[i] < pB[i])
                return -1;
            if (pA[i] > pB[i])
                return 1;
        }
    }
    float* pkNormal = m_pkNormal;
    if (pkNormal && (uiCompareFlags & 2))
    {
        int iCompareResult;
        iCompareResult = CompareFloats(pkNormal + usVertexA * 3, pkNormal + usVertexB * 3, 3);
        if (iCompareResult)
            return iCompareResult;
    }
    float* pkColor = m_pkColor;
    if (pkColor && (uiCompareFlags & 4))
    {
        int iCompareResult = CompareFloats(pkColor + usVertexA * 4, pkColor + usVertexB * 4, 4);
        if (iCompareResult)
            return iCompareResult;
    }
    float* pkTexture;
    pkTexture = m_pkTexture;
    if (pkTexture && (uiCompareFlags & 8))
    {
        unsigned int uiStride = m_usVertices;
        unsigned short usBaseIndex = 0;
        unsigned short usTextureSets;
        usTextureSets = m_usTrianglePoints & 1;
        for (unsigned short usSet = 0; usSet < usTextureSets; usSet++)
        {
            const float* pB = pkTexture + (usVertexB + usBaseIndex) * 2;
            const float* pA = pkTexture + (usVertexA + usBaseIndex) * 2;
            for (unsigned int i = 0; i < 2; i++)
            {
                if (pA[i] < pB[i])
                    return -1;
                if (pA[i] > pB[i])
                    return 1;
            }
            usBaseIndex += uiStride;
        }
    }
    return 0;
}

struct FUN_00a66f90_cls : public NiGeometryData
{
    unsigned int FUN_00a66f90();
    unsigned int FUN_00e7cd40_base();
};

// Computes the total geometry data size from vertex, normal, color and texture buffers and adds the base size.
// @fnv 0x00a66f90
unsigned int FUN_00a66f90_cls::FUN_00a66f90()
{
    unsigned int total;

    if (m_pkVertex != 0)
    {
        total = m_usVertices * 3;
        total += total;
        total += total;
    }
    else
    {
        total = 0;
    }
    if (m_pkNormal != 0)
    {
        unsigned int uiNormalSize = (m_usTrianglePoints & 0xf000) != 0;
        uiNormalSize = uiNormalSize * 2 + 1;
        total += uiNormalSize * m_usVertices * 3 * 4;
    }
    if (m_pkColor != 0)
    {
        total += m_usVertices << 4;
    }
    if (m_pkTexture != 0)
    {
        total += (m_usTrianglePoints & 1) * m_usVertices * 8;
    }
    return FUN_00e7cd40_base() + total;
}

void* FUN_00aa1070(unsigned int uiSize);

class FUN_00a68820_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;

    void FUN_00a67dd0(unsigned short* pusIndices, unsigned int uiBase, unsigned int uiZero, int iLast);
    void BuildIndexMappings(unsigned short** ppusA, unsigned short** ppusB, unsigned int uiValue);
};

// @fnv 0x00a68820
void FUN_00a68820_cls::BuildIndexMappings(unsigned short** ppusForward, unsigned short** ppusInverse,
                                          unsigned int uiValue)
{
    unsigned short m_usPassCountLocal = m_08;
    unsigned int uiBytes = (unsigned int)m_usPassCountLocal * 2;
    *ppusForward = (unsigned short*)FUN_00aa1070(uiBytes);
    *ppusInverse = (unsigned short*)FUN_00aa1070(uiBytes);

    for (unsigned short i = 0; i < m_usPassCountLocal; i++)
    {
        (*ppusForward)[i] = i;
    }

    FUN_00a67dd0(*ppusForward, uiValue, 0, (int)m_usPassCountLocal - 1);

    for (unsigned short j = 0; j < m_usPassCountLocal; j++)
    {
        (*ppusInverse)[(*ppusForward)[j]] = j;
    }
}

struct StrArr
{
    virtual ~StrArr();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiNewSize);
    void SetAt(unsigned int uiIndex, char*& pValue);
};

extern char* DAT_011f4884;
char* __cdecl FUN_00a7d330(char* pName);
char* __cdecl FUN_00a7d490(const char* pName, unsigned short usValue);
char* __cdecl FUN_00a7d5a0(const char* pName, void* pValue);
char* __cdecl FUN_00a7d4d0(const char* pName, int iValue);
char* __cdecl FUN_00a7d410(const char* pName, unsigned char ucValue);

struct BoundVal
{
    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;
    float m_fBoundRadius;
    char* FUN_00a7fb20(const char* pName);
};

struct AddObj
{
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void reserved04();
    virtual void reserved05();
    virtual void reserved06();
    virtual void reserved07();
    virtual void reserved08();
    virtual void reserved09();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void RegisterFieldArray(StrArr* arr);
};

static __forceinline void AppendValue(StrArr* arr, char*& pValue)
{
    unsigned int uiSize = arr->m_usSize;
    if (uiSize >= arr->m_usMaxSize)
        arr->SetSize(uiSize + arr->m_usGrowBy);
    arr->SetAt(uiSize, pValue);
}

struct Base380
{
    void AppendCameraPathEntries(StrArr* arr);
};

struct GeomData : Base380
{
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    BoundVal m_kBound;
    void* m_pkVertex;
    void* m_pkNormal;
    void* m_pkColor;
    void* m_pkTexture;
    AddObj* m_spAdd;
    void* m_pkGeometryRendererData;
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
    bool m_bIsDynamic;
    bool m_bBoundDirty;
    bool m_bVerticesDirty;
    void RegisterFields(StrArr* arr);
};

// Appends this geometry's vertex, normal, color, texture, bound and flag fields to arr, then registers the additional-geometry object or a null entry.
// @fnv 0x00a688b0
void GeomData::RegisterFields(StrArr* arr)
{
    AppendCameraPathEntries(arr);
    char* pValue;
    pValue = FUN_00a7d330(DAT_011f4884);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d490("m_usVertices", m_usVertices);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d5a0("m_pkVertex", m_pkVertex);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d5a0("m_pkNormal", m_pkNormal);
    AppendValue(arr, pValue);
    int iNBTMethod = m_usTrianglePoints & 0xf000;
    pValue = FUN_00a7d4d0("NormalBinormalTangent", iNBTMethod);
    AppendValue(arr, pValue);
    pValue = m_kBound.FUN_00a7fb20("m_kBound");
    AppendValue(arr, pValue);
    pValue = FUN_00a7d5a0("m_pkColor", m_pkColor);
    AppendValue(arr, pValue);
    unsigned short usNumTextureSets = (unsigned short)(m_usTrianglePoints & 1);
    pValue = FUN_00a7d490("Num Texture Sets", usNumTextureSets);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d5a0("m_pkTexture", m_pkTexture);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d490("m_usDirtyFlags", m_usDirtyFlags);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d410("m_ucKeepFlags", m_ucKeepFlags);
    AppendValue(arr, pValue);
    pValue = FUN_00a7d410("m_ucCompressFlags", m_ucCompressFlags);
    AppendValue(arr, pValue);
    AddObj* pAddObj = m_spAdd;
    if (pAddObj)
    {
        pAddObj->RegisterFieldArray(arr);
    }
    else
    {
        pValue = FUN_00a7d4d0("m_spAdditionalGeomData", 0);
        AppendValue(arr, pValue);
    }
}

// NiGeometryData construction uses a nonthrowing constructor contract and real NiPointer initialization.
extern unsigned short DAT_011a9b14;
struct Base302
{
    virtual ~Base302();
    unsigned int references;
    Base302();
};
struct Bound302
{
    NiPoint3 center;
    float radius;
    void ComputeBoundingSphere(int vertices, const NiPoint3* data);
};
struct FUN_00a67b20 : Base302
{
    virtual ~FUN_00a67b20();
    unsigned short vertices, id, dataFlags, dirtyFlags;
    Bound302 bound;
    NiPoint3* vertex;
    NiPoint3* normal;
    RgbaColor* color;
    NiPoint2* texture;
    NiPointer<NiAdditionalGeometryData> additional;
    void* buffer;
    unsigned char keepFlags, compressFlags;
    bool locked, writeLocked, saveVertices;
    FUN_00a67b20(unsigned short count, NiPoint3* v, NiPoint3* n, RgbaColor* c, NiPoint2* t, unsigned short textureSets,
                 unsigned short nbt) throw();
};
// Initialises vertex/normal/color/texture pointers, sets data flags from textureSets and nbt, computes the bound, assigns a new id, and clears dirty flags.
// @fnv 0x00a67b20
FUN_00a67b20::FUN_00a67b20(unsigned short count, NiPoint3* apVertex, NiPoint3* apNormal, RgbaColor* apColor,
                           NiPoint2* apTexture, unsigned short textureSets, unsigned short nbt) throw()
    : vertices(count), dataFlags(0), dirtyFlags(0), vertex(apVertex), normal(apNormal), color(apColor),
      texture(apTexture), additional(0), buffer(0), keepFlags(0), compressFlags(0), locked(false), writeLocked(false),
      saveVertices(true)
{
    dataFlags = (dataFlags & 0x0ffe) | (textureSets & 1) | nbt;
    if (vertices > 0 && vertex)
        bound.ComputeBoundingSphere(vertices, vertex);
    id = DAT_011a9b14++;
    if (!additional || !additional->IsPacked())
        dirtyFlags &= 0x8fff;
}

struct GeomView
{
    void* vptr;
    unsigned int refs;
    unsigned short usVertices;
    unsigned short GetActiveVertexCount() const;
};
// @fnv 0x00a669e0
unsigned short GeomView::GetActiveVertexCount() const
{
    return usVertices;
}

struct MemoryHeap
{
    void* FUN_00aa3e40(unsigned int size);
};
extern MemoryHeap DAT_011f6238;

void __cdecl FUN_00ec61c0(void* dst, int value, unsigned int size);

struct NormalVec
{
    float x;
    float y;
    float z;
    NormalVec()
    {}
    static void* operator new[](unsigned int bytes)
    {
        return DAT_011f6238.FUN_00aa3e40(bytes);
    }
};

struct GeomNormals : public NiGeometryData
{
    void EnsureNormals(bool bZero);
};

// @fnv 0x00a669f0
void GeomNormals::EnsureNormals(bool bZero)
{
    unsigned int uiMul = 1;
    if ((m_usTrianglePoints & 0xf000) != 0)
    {
        uiMul = 3;
    }
    if (m_pkNormal == 0)
    {
        m_pkNormal = (NiPoint3*)new NormalVec[m_usVertices * uiMul];
    }
    if (bZero)
    {
        FUN_00ec61c0(m_pkNormal, 0, m_usVertices * uiMul * 12);
    }
}

struct FUN_00a67720_res
{
    unsigned int m_uiA;
    unsigned int m_uiB;
    unsigned char m_ucC;
};

struct FUN_00a67720_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool v35();
    unsigned int m_i04, m_i08, m_i0c, m_i10, m_i14, m_i18, m_i1c, m_i20, m_i24, m_i28;
    unsigned int m_uiKey2c;
    void FUN_00a72720(unsigned int uiFlags, unsigned int* pA, unsigned int* pW, unsigned int* pC, unsigned int* pV,
                      unsigned int* pU, unsigned int* pB);
};

class FUN_00a67720_cls
{
  public:
    unsigned int m_i00, m_i04, m_i08, m_i0c, m_i10, m_i14, m_i18, m_i1c, m_i20, m_i24, m_i28;
    unsigned int m_uiKey2c;
    FUN_00a67720_obj* m_pEntryObject;
    unsigned int m_i34;
    unsigned short m_us38;
    bool m_bFlag3a;
    void GetKeyAndMode(unsigned int uiArg, FUN_00a67720_res* pOut);
};

static unsigned int Mode(bool f0, unsigned int key)
{
    return (f0 + f0 + 2) + ((key >> 1) & 1);
}

// @fnv 0x00a67720
void FUN_00a67720_cls::GetKeyAndMode(unsigned int uiArg, FUN_00a67720_res* pOut)
{
    unsigned int a, b, c, u, v, w;
    if (!m_bFlag3a)
    {
        return;
    }
    b = 0;
    c = 0;
    a = 0;
    FUN_00a67720_obj* obj = m_pEntryObject;
    if (obj != 0 && obj->v35())
    {
        unsigned int key = obj->m_uiKey2c;
        unsigned int bit1 = (key >> 1) & 1;
        unsigned int uiMode = ((key & 1) != 0) ? 4 : 2;
        u = 0;
        obj->FUN_00a72720(uiMode + bit1, &a, &w, &c, &v, &u, &b);
    }
    unsigned int x, y;
    if (a == 0)
    {
        x = m_uiKey2c;
        y = 8;
    }
    else
    {
        x = a;
        y = b;
    }
    pOut->m_uiA = x;
    pOut->m_uiB = y;
    pOut->m_ucC = 0;
}

struct Owner;

typedef int(__cdecl* CallableFn)(struct Callable*, unsigned int, unsigned int, unsigned int*, unsigned int);

struct Callable
{
    int unk000;
    int m_nCount;
    int unk008;
    CallableFn m_pfn;

    int BinaryWrite(const void* pv, unsigned int bytes, unsigned int uiSize)
    {
        int res = m_pfn(this, (unsigned int)pv, bytes, &uiSize, 1);
        m_nCount += res;
        return res;
    }
};

struct Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    Callable* m_callable;
};

// Doubles a3 three times (multiplying by 8) and writes a2 with that size via the owner's callable BinaryWrite.
// @fnv 0x00a67ae0
void __cdecl FUN_00a67ae0(Owner* pOwner, unsigned int pData, unsigned int a3)
{
    Callable* pkCallable = pOwner->m_callable;
    for (unsigned int ui = 0; ui < 3; ++ui)
        a3 += a3;
    pkCallable->BinaryWrite((void*)pData, a3, 4);
}

namespace fnv_00a66a60 {
extern "C" void* __cdecl memset(void* pvDst, int iValue, unsigned int uiSize);

class MemoryManager
{
  public:
    void DeallocateAlias(void* pvMem);
};
extern MemoryManager g_memoryManager;

class FUN_00a5e3a0_Helper
{
  public:
    void* FUN_00aa3e40(unsigned int uiSize);
};

class NormalA66A
{
  public:
    float x, y, z;

    NormalA66A()
    {}

    static void* operator new[](unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&g_memoryManager)->FUN_00aa3e40(uiSize);
    }
    static void operator delete[](void* pvMem)
    {
        g_memoryManager.DeallocateAlias(pvMem);
    }
};

class GeometryDataA66A
{
  public:
    int unk00, unk04;
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    int unk10, unk14, unk18, unk1C;
    NormalA66A* m_pkVertex;
    NormalA66A* m_pkNormal;

    unsigned int GetNormalBinormalTangentMethod() const
    {
        return m_usTrianglePoints & 0xf000;
    }
    void SetNormalBinormalTangentMethod(unsigned int eMethod)
    {
        m_usTrianglePoints = (unsigned short)((m_usTrianglePoints & 0xfff) | eMethod);
    }

    void FUN_00a66a60(unsigned int eMethod);
};

// Sets the normal binormal tangent method, reallocating m_pkNormal to hold one or three NormalA66A per vertex depending on eMethod.
// @fnv 0x00a66a60
void GeometryDataA66A::FUN_00a66a60(unsigned int eMethod)
{
    if (GetNormalBinormalTangentMethod() == eMethod)
        return;
    SetNormalBinormalTangentMethod(eMethod);
    if (!m_pkNormal)
        return;

    unsigned int uiMultiplier = 1;
    if (eMethod)
        uiMultiplier = 3;
    NormalA66A* pkNewNormals = new NormalA66A[m_usVertices * uiMultiplier];
    for (unsigned int i = 0; i < m_usVertices; i++)
        pkNewNormals[i] = m_pkNormal[i];
    if (eMethod)
    {
        memset(&pkNewNormals[m_usVertices], 0, sizeof(NormalA66A));
    }
    delete[] m_pkNormal;
    m_pkNormal = pkNewNormals;
}
}  // namespace fnv_00a66a60

struct NiRenderObj30
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool v35();
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
    unsigned int m_uiFlags2c;
    void FUN_00a72720(unsigned int uiFlags, unsigned int* pA, unsigned int* pB, unsigned int* pC, unsigned int* pD,
                      unsigned int* pE, unsigned int* pF);
};

struct BoundOut
{
    unsigned int m_uiPtr;
    unsigned int m_uiCount;
    unsigned char m_ucFlag;
};

struct RenderOwner
{
    char unk00[0x24];
    unsigned int m_uiField24;
    unsigned int unk28;
    unsigned int unk2c;
    NiRenderObj30* m_pObj30;
    unsigned int unk34;
    unsigned char unk38;
    unsigned char unk39;
    bool m_bFlag3a;
    void GetBounds(BoundOut* pOut);
};

// When m_bFlag3a is set, fills pOut from m_pObj30 or falls back to m_uiField24 and count 0xc.
// @fnv 0x00a675b0
void RenderOwner::GetBounds(BoundOut* pOut)
{
    if (m_bFlag3a)
    {
        unsigned int uiA = 0;
        unsigned int uiD = 0;
        unsigned int uiC = 0;
        unsigned int uiE;
        unsigned int pObj;
        NiRenderObj30* pObj30 = m_pObj30;
        if (pObj30 != 0 && pObj30->v35())
        {
            unsigned int uiFlags = (pObj30->m_uiFlags2c & 1) * 2 | 1;
            unsigned int uiB = 0;
            pObj30->FUN_00a72720(uiFlags, &uiC, &pObj, &uiD, &uiE, &uiB, &uiA);
        }
        unsigned int uiPtr;
        unsigned int ItemUpdateArray;
        if (uiC == 0)
        {
            uiPtr = m_uiField24;
            ItemUpdateArray = 0xc;
        }
        else
        {
            uiPtr = uiC;
            ItemUpdateArray = uiA;
        }
        pOut->m_uiPtr = uiPtr;
        pOut->m_uiCount = ItemUpdateArray;
        pOut->m_ucFlag = 0;
    }
}

class NiBinaryStreamA67
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStreamA67* pkThis, const void* pvBuffer,
                                                   unsigned int uiBytes, unsigned int* puiComponentSizes,
                                                   unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA67();

    unsigned int m_uiStreamFlags;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;
    void* m_pfnRead;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

class NiStreamA67
{
  public:
    virtual ~NiStreamA67();

    unsigned char m_auPad[0x244];
    NiBinaryStreamA67* m_pUnderlyingStream;
    NiBinaryStreamA67* m_pBackingStream;
};

struct NiPoint2A67
{
    float x;
    float y;
};

template <class T> inline void WriteBinaryArray(NiBinaryStreamA67& os, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    os.BinaryWrite(pValue, uiSize * uiNumEls, &uiSize, 1);
}

// Writes an array of NiPoint2A67 values to the backing stream of kStream as a flat array of floats.
// @fnv 0x00a67aa0
void __cdecl FUN_00a67aa0(NiStreamA67& kStream, const NiPoint2A67* pkValue, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.m_pBackingStream, (const float*)pkValue, uiNumEls * 2);
}

class FUN_00a67dd0_cls
{
  public:
    unsigned int MedianOfThree(unsigned short* pBase, unsigned int uiKey, int iLo, int iHi);
    int CompareVertices(unsigned int uiA, unsigned int uiB, unsigned int uiKey);
    void FUN_00a67dd0(unsigned short* pArr, unsigned int uiKey, int iLo, int iHi);
};

// Reorders the unsigned-short entries in pArr between iLo and iHi using pivot selection and CompareVertices.
// @fnv 0x00a67dd0
void FUN_00a67dd0_cls::FUN_00a67dd0(unsigned short* pArr, unsigned int uiKey, int iLo, int iHi)
{
    if (iHi <= iLo)
        return;

    unsigned short* pBase = pArr;
    for (;;)
    {
        int j = iHi + 1;
        int i = iLo - 1;
        unsigned int pivot = MedianOfThree(pBase, uiKey, iLo, iHi);
        for (;;)
        {
            do
            {
                --j;
            } while (CompareVertices(pivot, pBase[j], uiKey) < 0);
            do
            {
                ++i;
            } while (CompareVertices(pBase[i], pivot, uiKey) < 0);
            if (i >= j)
                break;
            unsigned short t = pBase[i];
            pBase[i] = pBase[j];
            pBase[j] = t;
        }
        if (j == iHi)
        {
            iHi = j - 1;
        }
        else
        {
            FUN_00a67dd0(pBase, uiKey, iLo, j);
            iLo = j + 1;
        }
        if (iHi <= iLo)
            return;
    }
}

namespace fnv_00a68520 {
class NiObjectGroup;

// The context header only forward declares RgbaColor; its layout is four floats.
struct RgbaColor
{
    float m_afRGBA[4];
};

// The stream reached from NiStream while saving: the callback pair the context
// header declares for reading, plus the writing entry point used here.
struct NiBinaryStream
{
    void** m_vtableUnk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    FNV_FORCEINLINE unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiBytes,
                                             unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

// Stand-in for the saving-side NiStream: the members the context header does not
// describe, then the binary stream written to.
struct SaveStream : NiStream
{
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    NiBinaryStream* m_pBackingStream;

    unsigned int FUN_00a634f0(NiObjectGroup* pkGroup);
};

void FUN_00a67ae0(SaveStream& kStream, NiPoint2* pkTexture, unsigned int ItemUpdateArray);

// The bounding volume's saving entry point (declared on the real class).
struct NiBoundSave : NiBound
{
    void SaveBinary(SaveStream& kStream);
};

// The vtable the shipped image gives the stream's NiObject base: this project's
// NiRefObject contributes only its destructor there, so the NiObject entry
// points start one slot earlier than the context header's declaration and the
// extra-data entry point is reached at +0x30.
struct SaveStreamObjectVtbl
{
    virtual ~SaveStreamObjectVtbl();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& kCloning);
    virtual void CopyMemberData(NiObject* pkDest, CloningProcess& kCloning);
    virtual void PostLinkObject(NiStream& kStream);
    virtual bool StreamCanSkip();
    virtual bool GetStreamableRTTIName(char* acName, unsigned int uiMaxSize) const;
    virtual unsigned int GetBlockAllocationSize() const;
    virtual NiObjectGroup* GetGroup() const;
    virtual void SetGroup(NiObjectGroup* pkGroup);
    virtual void AddViewerStrings(NiViewerStringsArray* pkViewerStrings);
    virtual void SetName(unsigned int uiName);
    virtual bool AddExtraData(NiObject* pkExtra);
};

template <class T> FNV_FORCEINLINE void WriteBinaryArray(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

// Colour elements are one whole 16-byte RgbaColor each, so the byte count is
// formed straight from the vertex count.
template <class T>
FNV_FORCEINLINE void NiBinaryStreamSaveBytes(NiBinaryStream& kStream, T* pValue, unsigned int uiBytes)
{
    unsigned int uiSize = sizeof(float);
    kStream.BinaryWrite(pValue, uiBytes, &uiSize, 1);
}

template <class T> FNV_FORCEINLINE void SerializeValue(SaveStream& kStream, const T& value)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &value, 1);
}

extern NiObjectGroup* DAT_011f4880;

struct NiGeometryDataSave : NiGeometryData
{
    void FUN_00a68520(SaveStream& kStream);
};

// Serializes NiGeometryData vertex, normal, color, texture and bound data to kStream, writing arrays only when m_bVerticesDirty is set.
// @fnv 0x00a68520
void NiGeometryDataSave::FUN_00a68520(SaveStream& kStream)
{
    NiObject::SaveBinary(kStream);

    unsigned int uiObjectGroup = kStream.FUN_00a634f0(DAT_011f4880);
    SerializeValue(kStream, uiObjectGroup);

    SerializeValue(kStream, m_usVertices);
    SerializeValue(kStream, m_ucKeepFlags);
    SerializeValue(kStream, m_ucCompressFlags);

    bool bHasVertexData = (m_pkVertex != 0);
    SerializeValue(kStream, bHasVertexData);
    // The vertex blob is three floats per vertex; the byte count is formed
    // at the call site (element count times float size), as in the original.
    if (bHasVertexData && m_bVerticesDirty)
        NiBinaryStreamSaveBytes(*kStream.m_pBackingStream, (float*)m_pkVertex, m_usVertices * 3 * sizeof(float));

    if (m_pkTexture == 0)
        m_usTrianglePoints &= (unsigned short)~NiGeometryData::TEXTURE_SET_MASK;
    SerializeValue(kStream, m_usTrianglePoints);

    unsigned int uiNormalEls = m_usVertices;
    if (m_usTrianglePoints & NiGeometryData::NBT_METHOD_MASK)
        uiNormalEls = m_usVertices * 3;

    bool bHasNormalData = (m_pkNormal != 0);
    SerializeValue(kStream, bHasNormalData);
    if (bHasNormalData && m_bVerticesDirty)
        WriteBinaryArray(*kStream.m_pBackingStream, (float*)m_pkNormal, uiNormalEls * 3);

    (*(NiBoundSave*)&m_kBound).SaveBinary(kStream);

    bool bHasColorData = (m_pkColor != 0);
    SerializeValue(kStream, bHasColorData);
    if (bHasColorData && m_bVerticesDirty)
        NiBinaryStreamSaveBytes(*kStream.m_pBackingStream, (float*)m_pkColor, m_usVertices * sizeof(RgbaColor));

    unsigned int uiTextureCount = m_usVertices * (m_usTrianglePoints & NiGeometryData::TEXTURE_SET_MASK);
    if (uiTextureCount && m_pkTexture && m_bVerticesDirty)
        FUN_00a67ae0(kStream, m_pkTexture, uiTextureCount);

    SerializeValue(kStream, (unsigned short)(m_usDirtyFlags & 0x7000));

    (*(SaveStreamObjectVtbl*)&kStream).AddExtraData(m_spAdditionalGeomData);
}
}  // namespace fnv_00a68520

class SlotOverride
{
  public:
    virtual void v00();
    virtual bool HasSlot(int iSlot);  // +0x04
};

class SlotOwner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_uiLevel : 1;  // +0x0c
    unsigned short m_uiFlagBits : 11;
    unsigned short m_uiHighBits : 4;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_pSlot0;    // +0x20
    void* m_pSlot3;    // +0x24
    void* m_pSlot4;    // +0x28
    void* m_pLeveled;  // +0x2c
    int unk30;
    SlotOverride* m_pOverride;  // +0x34

    bool ContainsVertexData(int iSlot);
};

// Returns true if the slot is occupied, checking m_pOverride first, then the specific slot pointer or m_pLeveled with m_uiLevel thresholds.
// @fnv 0x00a66c00
bool SlotOwner::ContainsVertexData(int iSlot)
{
    if (m_pOverride && m_pOverride->HasSlot(iSlot))
        return true;
    switch (iSlot)
    {
    case 0:
        return m_pSlot0 != 0;
    case 3:
        return m_pSlot3 != 0;
    case 4:
        return m_pSlot4 != 0;
    case 5:
        return m_pLeveled && m_uiLevel >= 1;
    case 6:
        return m_pLeveled && m_uiLevel >= 2;
    case 7:
        return m_pLeveled && m_uiLevel >= 3;
    case 8:
        return m_pLeveled && m_uiLevel >= 4;
    case 9:
        return m_pLeveled && m_uiLevel >= 5;
    case 10:
        return m_pLeveled && m_uiLevel >= 6;
    case 11:
        return m_pLeveled && m_uiLevel >= 7;
    case 12:
        return m_pLeveled && m_uiLevel >= 8;
    case 13:
    case 14:
        return m_pSlot3 && m_uiHighBits;
    }
    return false;
}

struct FUN_00a67660_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool v35();
    void FUN_00a72720(unsigned int uiFlags, unsigned int* pA, unsigned int* pB, unsigned int* pC, unsigned int* pD,
                      unsigned int* pE, unsigned int* pF);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    unsigned int m_uiValue1;
};

struct StreamOut_a676
{
    unsigned int m_uiData;
    unsigned int m_uiStride;
    bool m_bFlag;
};

struct FUN_00a67660_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int m_uiDefault;
    int unk2C;
    FUN_00a67660_obj* m_pEntryObject;
    int unk34;
    unsigned short unk38;
    unsigned char m_bEnableState;
    void FUN_00a67660(StreamOut_a676* out);
};

// When enabled, it may return early; otherwise it writes data and stride from the entry object or defaults.
// @fnv 0x00a67660
void FUN_00a67660_cls::FUN_00a67660(StreamOut_a676* apStreamOut)
{
    if (!m_bEnableState)
        return;
    bool bFlag = false;
    unsigned int uiStride = 0;
    unsigned int uiW = 0;
    unsigned int uiData = 0;
    FUN_00a67660_obj* obj = m_pEntryObject;
    if (obj && obj->v35())
    {
        unsigned int fl = obj->m_uiValue1;
        if (!(fl & 2))
            return;
        unsigned int uiZ = 0;
        unsigned int uiU;
        unsigned int uiV;
        obj->FUN_00a72720((fl & 1) ? 4 : 2, &uiData, &uiV, &uiW, &uiU, &uiZ, &uiStride);
        if (fl & 0x20)
            bFlag = true;
    }
    if (!uiData)
    {
        uiData = m_uiDefault;
        uiStride = 0x10;
    }
    apStreamOut->m_uiData = uiData;
    apStreamOut->m_uiStride = uiStride;
    apStreamOut->m_bFlag = bFlag;
}

struct Point3Equality : NiPoint3
{
    bool operator==(const NiPoint3& pt) const
    {
        return (x == pt.x && y == pt.y && z == pt.z);
    }
    __declspec(noinline) bool FUN_00439090(const NiPoint3& pt) const
    {
        return !(*this == pt);
    }
};

struct BoundEquality : NiBound
{
    bool operator==(const NiBound& kBound) const
    {
        return (static_cast<const Point3Equality&>(m_kCenter) == kBound.m_kCenter &&
                m_fBoundRadius == kBound.m_fBoundRadius);
    }
    __declspec(noinline) bool FUN_00a926b0(const NiBound& kBound) const
    {
        return !(*this == kBound);
    }
};

class RgbaColor
{
  public:
    float r, g, b, a;
    bool operator==(const RgbaColor& c) const
    {
        return (r == c.r && g == c.g && b == c.b && a == c.a);
    }
    __declspec(noinline) bool FUN_004a4c90(const RgbaColor& c) const
    {
        return !(*this == c);
    }
};

class NiPoint2
{
  public:
    float x, y;
    bool operator==(const NiPoint2& pt) const
    {
        return (x == pt.x && y == pt.y);
    }
    __declspec(noinline) bool FUN_0051c330(const NiPoint2& pt) const
    {
        return !(*this == pt);
    }
};

struct GeometryEquality : NiGeometryData
{
    bool FUN_00a67840(NiObject* pkObject);
};

// Compares this NiGeometryData against pkObject, returning false if vertex, normal, bound, color, texture, or additional data differ.
// @fnv 0x00a67840
bool GeometryEquality::FUN_00a67840(NiObject* pkObject)
{
    if (!NiObject::IsEqual(pkObject))
        return false;

    NiGeometryData* pkData = static_cast<NiGeometryData*>(pkObject);

    if (m_usVertices != pkData->m_usVertices)
        return false;

    if ((m_pkVertex && !pkData->m_pkVertex) || (!m_pkVertex && pkData->m_pkVertex))
        return false;

    if (m_ucKeepFlags != pkData->m_ucKeepFlags)
        return false;

    if (m_ucCompressFlags != pkData->m_ucCompressFlags)
        return false;

    unsigned int i;

    if (m_pkVertex)
    {
        for (i = 0; i < m_usVertices; i++)
        {
            if (static_cast<Point3Equality*>(&m_pkVertex[i])->FUN_00439090(pkData->m_pkVertex[i]))
                return false;
        }
    }

    if ((m_pkNormal && !pkData->m_pkNormal) || (!m_pkNormal && pkData->m_pkNormal))
        return false;

    if (m_pkNormal)
    {
        if ((m_usTrianglePoints & NBT_METHOD_MASK) != (pkData->m_usTrianglePoints & NBT_METHOD_MASK))
            return false;

        unsigned int ItemUpdateArray =
            ((m_usTrianglePoints & NBT_METHOD_MASK) == NBT_METHOD_NONE) ? m_usVertices : 3 * m_usVertices;
        for (i = 0; i < ItemUpdateArray; i++)
        {
            if (static_cast<Point3Equality*>(&m_pkNormal[i])->FUN_00439090(pkData->m_pkNormal[i]))
                return false;
        }
    }

    if (static_cast<BoundEquality*>(&m_kBound)->FUN_00a926b0(pkData->m_kBound))
        return false;

    if ((m_pkColor && !pkData->m_pkColor) || (!m_pkTexture && pkData->m_pkTexture))
        return false;

    if (m_pkColor)
    {
        for (i = 0; i < m_usVertices; i++)
        {
            if (m_pkColor[i].FUN_004a4c90(pkData->m_pkColor[i]))
                return false;
        }
    }

    if ((m_pkTexture && !pkData->m_pkTexture) || (!m_pkTexture && pkData->m_pkTexture))
        return false;

    if (m_pkTexture)
    {
        if ((m_usTrianglePoints & TEXTURE_SET_MASK) != (pkData->m_usTrianglePoints & TEXTURE_SET_MASK))
            return false;

        unsigned int ItemUpdateArray = (m_usTrianglePoints & TEXTURE_SET_MASK) * m_usVertices;
        for (i = 0; i < ItemUpdateArray; i++)
        {
            if (m_pkTexture[i].FUN_0051c330(pkData->m_pkTexture[i]))
                return false;
        }
    }

    if ((m_spAdditionalGeomData && !pkData->m_spAdditionalGeomData) ||
        (!m_spAdditionalGeomData && pkData->m_spAdditionalGeomData))
        return false;

    if (m_spAdditionalGeomData && pkData->m_spAdditionalGeomData &&
        !m_spAdditionalGeomData->IsEqual(pkData->m_spAdditionalGeomData))
        return false;

    return true;
}

namespace fnv_00a67ea0 {
struct CountEA0
{
    int value;
    CountEA0(int v) : value(v)
    {}
};
struct DataEA0
{
    void* value;
    DataEA0(void* v) : value(v)
    {}
};
struct ElementEA0
{
    int value;
    ElementEA0(int v) : value(v)
    {}
};
struct ReaderEA0
{
    int m_iField0;
    int m_iPos;
    int(__cdecl* m_pfnRead)(ReaderEA0* pkReader, void* pvDest, int iTotal, int* piSize, int iFlag);
    __forceinline int ReadWrapped(void* data, CountEA0 bytes, ElementEA0 elem)
    {
        int result = m_pfnRead(this, data, bytes.value, &elem.value, 1);
        m_iPos += result;
        return result;
    }
    int BinaryRead(void* pv, int bytes, int uiSize)
    {
        int res = m_pfnRead(this, pv, bytes, &uiSize, 1);
        m_iPos += res;
        return res;
    }
};

class MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
    void Deallocate(void* pvMem);
};
extern MemoryManager g_memoryManager;
extern void* DAT_011f4880;
extern char UNK_0109c040;
extern char UNK_004a7800;

class StreamEA0
{
  public:
    int m_iField0;
    unsigned int m_uiUserVersion;
    int m_iField08;
    int m_iField0C;
    int m_iField10;
    int m_iField14;
    int m_iField18;
    int m_iField1C;
    int m_iField20;
    int m_iField24;
    int m_iField28;
    int m_iField2C;
    int m_iField30;
    int m_iField34;
    int m_iField38;
    int m_iField3C;
    int m_iField40;
    int m_iField44;
    int m_iField48;
    int m_iField4C;
    int m_iField50;
    int m_iField54;
    int m_iField58;
    int m_iField5C;
    int m_iField60;
    int m_iField64;
    int m_iField68;
    int m_iField6C;
    int m_iField70;
    int m_iField74;
    int m_iField78;
    int m_iField7C;
    int m_iField80;
    int m_iField84;
    int m_iField88;
    int m_iField8C;
    int m_iField90;
    int m_iField94;
    int m_iField98;
    int m_iField9C;
    int m_iFieldA0;
    int m_iFieldA4;
    int m_iFieldA8;
    int m_iFieldAC;
    int m_iFieldB0;
    int m_iFieldB4;
    int m_iFieldB8;
    int m_iFieldBC;
    int m_iFieldC0;
    int m_iFieldC4;
    int m_iFieldC8;
    int m_iFieldCC;
    int m_iFieldD0;
    int m_iFieldD4;
    unsigned int m_uiFileVersion;
    int m_iFieldDC;
    char m_cName;
    unsigned char m_ucFieldE1;
    unsigned char m_ucFieldE2;
    unsigned char m_ucFieldE3;
    int m_iFieldE4;
    int m_iFieldE8;
    int m_iFieldEC;
    int m_iFieldF0;
    int m_iFieldF4;
    int m_iFieldF8;
    int m_iFieldFC;
    int m_iField100;
    int m_iField104;
    int m_iField108;
    int m_iField10C;
    int m_iField110;
    int m_iField114;
    int m_iField118;
    int m_iField11C;
    int m_iField120;
    int m_iField124;
    int m_iField128;
    int m_iField12C;
    int m_iField130;
    int m_iField134;
    int m_iField138;
    int m_iField13C;
    int m_iField140;
    int m_iField144;
    int m_iField148;
    int m_iField14C;
    int m_iField150;
    int m_iField154;
    int m_iField158;
    int m_iField15C;
    int m_iField160;
    int m_iField164;
    int m_iField168;
    int m_iField16C;
    int m_iField170;
    int m_iField174;
    int m_iField178;
    int m_iField17C;
    int m_iField180;
    int m_iField184;
    int m_iField188;
    int m_iField18C;
    int m_iField190;
    int m_iField194;
    int m_iField198;
    int m_iField19C;
    int m_iField1A0;
    int m_iField1A4;
    int m_iField1A8;
    int m_iField1AC;
    int m_iField1B0;
    int m_iField1B4;
    int m_iField1B8;
    int m_iField1BC;
    int m_iField1C0;
    int m_iField1C4;
    int m_iField1C8;
    int m_iField1CC;
    int m_iField1D0;
    int m_iField1D4;
    int m_iField1D8;
    int m_iField1DC;
    int m_iField1E0;
    int m_iField1E4;
    int m_iField1E8;
    int m_iField1EC;
    int m_iField1F0;
    int m_iField1F4;
    int m_iField1F8;
    int m_iField1FC;
    int m_iField200;
    int m_iField204;
    int m_iField208;
    int m_iField20C;
    int m_iField210;
    int m_iField214;
    int m_iField218;
    int m_iField21C;
    int m_iField220;
    int m_iField224;
    int m_iField228;
    int m_iField22C;
    int m_iField230;
    int m_iField234;
    int m_iField238;
    int m_iField23C;
    int m_iField240;
    int m_iField244;
    int m_iField248;
    ReaderEA0* m_pkReader;

    void* FUN_00a634e0(unsigned int uiID);
    void FUN_00a645b0();
};

struct AllocEA0
{
    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
};

struct Point2EA0 : AllocEA0
{
    Point2EA0()
    {}
    float x;
    float y;
};

class ColorEA0 : public AllocEA0
{
  public:
    float r;
    float g;
    float b;
    float a;
};

struct Point3EA0 : AllocEA0
{
    Point3EA0()
    {}
    float x;
    float y;
    float z;
};

class SphereEA0
{
  public:
    Point3EA0 m_kCenter;
    float m_fBoundRadius;
    void FUN_00a69ac0(StreamEA0& kStream);
};

struct BuffEA0
{
    void* m_pField0;
    int m_iField4;
    void* m_pCurrent;
    int m_iArrayLength;
};

class ObjEA0
{
  public:
    virtual ~ObjEA0();
    virtual const void* GetRTTI() const;
    virtual ObjEA0* MakeClone(void* pCloning);
    virtual void CopyMemberData(ObjEA0* pkDest, void* pCloning);
    virtual void PostLinkObject(StreamEA0& kStream);
    virtual bool StreamCanSkip();
    virtual bool GetStreamableRTTIName(char* acName, unsigned int uiMaxSize) const;
    virtual unsigned int GetBlockAllocationSize() const;
    virtual void* GetGroup() const;
    virtual void SetGroup(void* pkGroup);
    virtual void AddViewerStrings(void* pkViewerStrings);
    virtual void SetName(unsigned int uiName);
    virtual bool AddExtraData(ObjEA0* pkExtra);
    virtual ObjEA0* GetExtraData() const;
    virtual bool RemoveExtraDataByName(ObjEA0* pkExtra);
    virtual void UpdateModelBound();
    virtual bool ResizeExtraData(unsigned short usSize);
    virtual void GetNumChildren();
    virtual void ReadGroup(StreamEA0& kStream);
    virtual void LinkObject(StreamEA0& kStream);
    virtual bool RegisterStreamables(StreamEA0& kStream);
    virtual void SaveBinary(StreamEA0& kStream);
    virtual bool IsEqual(ObjEA0* pkObject);
    virtual void GetViewerStrings(void* pkViewerStrings);
    virtual void InsertExtraData(ObjEA0* pkExtra);
    virtual void ProcessClone(void* pCloning);
    unsigned int m_uiRefCount;
};

__forceinline void ReadEA0(StreamEA0& kStream, void* pvDest, int iTotal, int iElem)
{
    ReaderEA0* pkReader = kStream.m_pkReader;
    pkReader->BinaryRead(pvDest, iTotal, iElem);
}

__forceinline void ReadNormalEA0(StreamEA0& stream, void* data, int count)
{
    ReaderEA0* reader = stream.m_pkReader;
    reader->ReadWrapped(data, count * 12, 4);
}

__forceinline void ReadPoint2EA0(StreamEA0& stream, void* data, unsigned int count)
{
    ReaderEA0* reader = stream.m_pkReader;
    for (unsigned int i = 0; i < 3; ++i)
        count += count;
    reader->BinaryRead(data, count, 4);
}

void* FUN_00ec61c0(void* pvDest, int iValue, unsigned int uiSize);
typedef void*(__thiscall* CtorStubEA0)(void*);
extern "C" void __stdcall _vector_constructor_iterator(void* apvArray, unsigned int uiElemSize, int iCount,
                                                       CtorStubEA0 pfnCtor);
void FUN_00a67aa0(StreamEA0& kStream, void* pvDest, int iCount);
void FUN_00a29680(const char* pcFmt, const char* pcName, int iKBytes);

class GeomEA0 : public ObjEA0
{
  public:
    virtual void* GetBoundObject();
    virtual void* GetVertexArray();
    virtual void* GetNormalArray();
    virtual void* GetColorArray();
    virtual void* GetTextureArray();
    virtual void* GetBufferObject();
    virtual BuffEA0* GetBuffData();

    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    SphereEA0 m_kBound;
    Point3EA0* m_pkVertex;
    Point3EA0* m_pkNormal;
    ColorEA0* m_pkColor;
    Point2EA0* m_pkTexture;
    void* m_spAdditionalGeomData;
    void* m_pkGeometryRendererData;
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
    bool m_bIsDynamic;
    bool m_bBoundDirty;
    bool m_bVerticesDirty;

    void ReadBinary(StreamEA0& kStream);
};

// Reads geometry arrays and bound data from the stream, using buffer storage when available and otherwise allocating arrays.
// @fnv 0x00a67ea0
void GeomEA0::ReadBinary(StreamEA0& kStream)
{
    void* pvCur;
    ObjEA0::ReadGroup(kStream);
    if (kStream.m_uiFileVersion >= 0x0a010072)
    {
        int pkBuff;
        ReadEA0(kStream, &pkBuff, 4, 4);
        DAT_011f4880 = kStream.FUN_00a634e0(pkBuff);
    }
    ReadEA0(kStream, &m_usVertices, 2, 2);
    if (kStream.m_uiFileVersion >= 0x0a000110)
    {
        ReadEA0(kStream, &m_ucKeepFlags, 1, 1);
        ReadEA0(kStream, &m_ucCompressFlags, 1, 1);
    }
    bool r;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkVertex, 4, 4);
        r = m_pkVertex != 0;
    }
    else
    {
        ReadEA0(kStream, &r, 1, 1);
    }
    if (r)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            int iTotal = 12 * m_usVertices;
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->m_pCurrent;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            tmp->m_iArrayLength++;
            m_pkVertex = (Point3EA0*)pvCur;
        }
        else
        {
            m_pkVertex = new Point3EA0[m_usVertices];
        }
        if (kStream.m_uiUserVersion >= 0x13 && !m_bVerticesDirty)
            FUN_00ec61c0(m_pkVertex, 0, m_usVertices * 12);
        else
            ReadEA0(kStream, m_pkVertex, m_usVertices * 12, 4);
    }
    int iNormalCount = m_usVertices;
    if (kStream.m_uiFileVersion >= 0x0a000002)
    {
        ReadEA0(kStream, &m_usTrianglePoints, 2, 2);
        if (m_usTrianglePoints & 0xf000)
            iNormalCount = iNormalCount * 3;
    }
    bool uiTexCount;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkNormal, 4, 4);
        uiTexCount = m_pkNormal != 0;
    }
    else
    {
        ReadEA0(kStream, &uiTexCount, 1, 1);
    }
    if (uiTexCount)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->m_pCurrent;
            unsigned int iTotal;
            iTotal = iNormalCount * 12;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            tmp->m_iArrayLength++;
            m_pkNormal = (Point3EA0*)pvCur;
        }
        else
        {
            m_pkNormal = new Point3EA0[iNormalCount];
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
            ReadNormalEA0(kStream, m_pkNormal, iNormalCount);
    }
    m_kBound.FUN_00a69ac0(kStream);
    bool bHasColor;
    if (kStream.m_uiFileVersion < 0x04010000)
    {
        ReadEA0(kStream, &m_pkColor, 4, 4);
        bHasColor = m_pkColor != 0;
    }
    else
    {
        ReadEA0(kStream, &bHasColor, 1, 1);
    }
    if (bHasColor)
    {
        if ((pvCur = GetBuffData()) != 0)
        {
            int iTotal = m_usVertices * 16;
            BuffEA0* tmp = GetBuffData();
            pvCur = tmp->m_pCurrent;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            tmp->m_iArrayLength++;
            m_pkColor = (ColorEA0*)pvCur;
        }
        else
        {
            unsigned int uiColorCount = m_usVertices;
            ColorEA0* pkColors = new ColorEA0[uiColorCount];
            if (pkColors)
                _vector_constructor_iterator(pkColors, 16, uiColorCount, (CtorStubEA0)&UNK_004a7800);
            else
                pkColors = 0;
            m_pkColor = pkColors;
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
            ReadEA0(kStream, m_pkColor, m_usVertices * 16, 4);
    }
    if (kStream.m_uiFileVersion < 0x0500000a)
    {
        unsigned short usTempFlags;
        ReadEA0(kStream, &usTempFlags, 2, 2);
        unsigned short bHasVertex = (usTempFlags ^ m_usTrianglePoints) & 1;
        m_usTrianglePoints ^= bHasVertex;
    }
    else if (kStream.m_uiFileVersion < 0x0a000002)
    {
        ReadEA0(kStream, &m_usTrianglePoints, 2, 2);
    }
    if (kStream.m_uiFileVersion < 0x04010000)
        ReadEA0(kStream, &m_pkTexture, 4, 4);
    unsigned int uiTextureFlags;
    if (kStream.m_uiUserVersion < 0x1b)
    {
        uiTextureFlags = m_usTrianglePoints & 0x1f;
        if ((unsigned short)uiTextureFlags > 1)
            m_usTrianglePoints |= 1;
    }
    else
    {
        uiTextureFlags = 0;
    }
    if ((unsigned short)(m_usTrianglePoints & 1) > 0)
    {
        unsigned int bHasNormal = (m_usTrianglePoints & 1) * m_usVertices;
        if ((pvCur = GetBuffData()) != 0)
        {
            BuffEA0* tmp = GetBuffData();
            int iTotal = bHasNormal * 8;
            pvCur = tmp->m_pCurrent;
            ++tmp->m_iArrayLength;
            tmp->m_pCurrent = (char*)pvCur + iTotal;
            m_pkTexture = (Point2EA0*)pvCur;
        }
        else
        {
            m_pkTexture = new Point2EA0[bHasNormal];
        }
        if (kStream.m_uiUserVersion < 0x13 || m_bVerticesDirty)
        {
            ReadPoint2EA0(kStream, m_pkTexture, bHasNormal);
            if ((unsigned short)uiTextureFlags > 1)
            {
                unsigned int uiExtraCount = ((unsigned short)uiTextureFlags - 1) * m_usVertices;
                Point2EA0* pkTemp = new Point2EA0[uiExtraCount];
                FUN_00a67aa0(kStream, pkTemp, uiExtraCount);
                g_memoryManager.Deallocate(pkTemp);
                FUN_00a29680(&UNK_0109c040, &kStream.m_cName, (uiExtraCount * 8) >> 10);
            }
        }
    }
    if (kStream.m_uiFileVersion >= 0x0500000a)
        ReadEA0(kStream, &m_usDirtyFlags, 2, 2);
    if (kStream.m_uiFileVersion >= 0x0a030007)
        kStream.FUN_00a645b0();
}
}  // namespace fnv_00a67ea0


// src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStorageExtendedMeshShape.h"

struct MemoryRouter
{
    virtual void Unused()
    {}
    virtual void Unused2()
    {}
    virtual void Release(void*, unsigned short)
    {}
};

struct MemoryManager
{
    unsigned char m_auiShapeKeys[0x10];
    MemoryRouter* m_router;
};

MemoryManager* _D1A0E0GetMemoryRouter();
void FUN_00d4ac70();

struct ShapeSubpartStorage
{
    virtual void Release(void*, unsigned short)
    {}
    unsigned short m_iElementCount;

    ShapeSubpartStorage* FUN_00d4ad20(int deletingFlag);
};

// @fnv 0x00d4ad20
ShapeSubpartStorage* ShapeSubpartStorage::FUN_00d4ad20(int deletingFlag)
{
    FUN_00d4ac70();

    if (deletingFlag & 1)
    {
        MemoryManager* memoryManager = _D1A0E0GetMemoryRouter();
        unsigned short size = m_iElementCount;
        memoryManager->m_router->Release(this, size);
    }

    return this;
}

namespace fnv_00d4b120 {
struct NineIntegerRecord
{
    virtual void method0() = 0;
    virtual void method1() = 0;
    virtual void deallocate(void*, unsigned int) = 0;
};

struct hkMemoryRouterContext
{
    unsigned char padding[0x10];
    NineIntegerRecord* router;
};

struct hkpStorageExtendedMeshShape_MeshSubpartStorage
{
    void* m_unknown;
    unsigned short m_iElementCount;

    void FUN_00d4af60();
    hkpStorageExtendedMeshShape_MeshSubpartStorage* DestroyStorage(unsigned int);
};

hkMemoryRouterContext* __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00d4b120
hkpStorageExtendedMeshShape_MeshSubpartStorage* hkpStorageExtendedMeshShape_MeshSubpartStorage::DestroyStorage(
    unsigned int deletingDestructor)
{
    FUN_00d4af60();

    if (deletingDestructor & 1)
    {
        hkMemoryRouterContext* context = _D1A0E0GetMemoryRouter();
        context->router->deallocate(this, m_iElementCount);
    }

    return this;
}
}  // namespace fnv_00d4b120

extern int DAT_010cfd84;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00d4a170(unsigned int unusedArg);
};

// @fnv 0x00d4a170
FnvVtObj* FnvVtObj::FUN_00d4a170(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010cfd84;
    return this;
}

struct hkAllocatorD49C
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Free(void* p, unsigned int uiNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        Free(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD49C
{
    void* m_apvUnk00[4];
    hkAllocatorD49C* m_pkHeap;
    hkAllocatorD49C& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD49C* __cdecl FUN_00c85750() throw();

template <typename T> inline void hkDestructD49C(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> struct hkArrayD49C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void clear()
    {
        hkDestructD49C(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(hkAllocatorD49C& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD49C()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

class hkReferencedObject
{
  public:
    void removeReference() throw();
};

class hkpStorageExtendedMeshShapeMeshSubpartStorage : public hkReferencedObject
{
};

class hkpStorageExtendedMeshShapeShapeSubpartStorage : public hkReferencedObject
{
};

struct FUN_00d56800
{
    int m_kNextStreamField[16];
    ~FUN_00d56800() throw();
};

struct hkpShapeD49C
{
    virtual ~hkpShapeD49C() throw();
    int m_aiUnk04[3];
};

struct hkpShapeContainerD49C
{
    virtual ~hkpShapeContainerD49C() throw();
};

struct FUN_00d56e00 : public hkpShapeD49C, public hkpShapeContainerD49C
{
    int m_aiUnk14[43];
    hkArrayD49C<FUN_00d56800> m_kTrianglesSubparts;
    int m_aiUnkCC[9];
    ~FUN_00d56e00() throw();
};

class FUN_00d49cb0 : public FUN_00d56e00
{
  public:
    hkArrayD49C<hkpStorageExtendedMeshShapeMeshSubpartStorage*> m_kMeshSubparts;
    hkArrayD49C<hkpStorageExtendedMeshShapeShapeSubpartStorage*> m_kShapeSubparts;
    int m_aiUnk108[2];
    ~FUN_00d49cb0() throw();
};

// @fnv 0x00d49cb0
FUN_00d49cb0::~FUN_00d49cb0() throw()
{
    for (int i = 0; i < m_kMeshSubparts.m_iElementCount; i++)
        m_kMeshSubparts.m_data[i]->removeReference();
    m_kTrianglesSubparts.clear();
    for (int i = 0; i < m_kShapeSubparts.m_iElementCount; i++)
        m_kShapeSubparts.m_data[i]->removeReference();
}

struct hkFinishLoadedObjectFlagD4A1
{
    int m_bFinishing;
};

class FUN_00d4a170
{
  public:
    virtual void CalcSizeForSpu() throw();
    int m_usMemSizeAndFlags;
    hkArray<hkReal> m_kVertices;
    hkArray<hkUint8> m_kIndices8;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<void*> m_kNamedMaterials;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    FUN_00d4a170(hkFinishLoadedObjectFlagD4A1 flag) throw();
};

class FUN_00d49c40
{
  public:
    virtual void CalcSizeForSpu() throw();
    int m_usMemSizeAndFlags;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    FUN_00d49c40(hkFinishLoadedObjectFlagD4A1 flag) throw();
};

__declspec(noinline) FUN_00d49c40::FUN_00d49c40(hkFinishLoadedObjectFlagD4A1 flag) throw()
{}

__declspec(noinline) FUN_00d4a170::FUN_00d4a170(hkFinishLoadedObjectFlagD4A1 flag) throw()
{}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

struct hkpTrianglesSubpartD4A1
{
    hkUint8 m_type;
    hkUint8 m_iMaterialIndexType;
    char m_pad02[2];
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iIndexStriding;
    int m_iNumTriangles;
    const float* m_pMaterialIndexBase;
    char m_pad1c[0x24];
    const void* m_pMaterialDataBase;
    int m_iMaterialStriding;
    hkUint8 m_ucIndexStridingType;
    char m_pad49[0x17];
};

struct hkpShapesSubpartD4A1
{
    hkUint8 m_type;
    hkUint8 m_iMaterialIndexType;
    char m_pad02[2];
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    char m_pad10[0x30];
};

class hkpShapeD4A1
{
  public:
    virtual void CalcSizeForSpu() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUlong m_ulUserData;
    hkUint32 m_type;
};

class hkpShapeContainerD4A1
{
  public:
    virtual int GetNumChildShapes() const throw();
};

class FUN_00d56f10 : public hkpShapeD4A1, public hkpShapeContainerD4A1
{
  public:
    char m_pad14[0xa0];
    hkArray<hkpTrianglesSubpartD4A1> m_kTrianglesSubparts;
    hkArray<hkpShapesSubpartD4A1> m_kShapesSubparts;
    char m_padCC[0x24];

    FUN_00d56f10(hkFinishLoadedObjectFlagD4A1 flag) throw();
};

class FUN_00d4a180 : public FUN_00d56f10
{
  public:
    hkArray<FUN_00d4a170*> m_kMeshSubparts;
    hkArray<FUN_00d49c40*> m_kShapeSubparts;
    char m_pad108[0x8];

    FUN_00d4a180(hkFinishLoadedObjectFlagD4A1 flag) throw();
};

// @fnv 0x00d4a180
FUN_00d4a180::FUN_00d4a180(hkFinishLoadedObjectFlagD4A1 flag) throw() : FUN_00d56f10(flag)
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kTrianglesSubparts.m_iElementCount; i++)
        {
            hkpTrianglesSubpartD4A1& kPart = m_kTrianglesSubparts.m_data[i];
            new (m_kMeshSubparts.m_data[i]) FUN_00d4a170(flag);
            FUN_00d4a170* pkStorage = m_kMeshSubparts.m_data[i];
            kPart.m_pMaterialIndexBase = pkStorage->m_kVertices.m_data;
            kPart.m_pMaterialDataBase = (kPart.m_ucIndexStridingType == 1) ? (const void*)pkStorage->m_kIndices8.m_data
                                        : (kPart.m_ucIndexStridingType == 2)
                                            ? (const void*)pkStorage->m_kIndices16.m_data
                                            : (const void*)pkStorage->m_kIndices32.m_data;
            kPart.m_pVertexBase = (kPart.m_iMaterialIndexType == 1)
                                      ? (const void*)pkStorage->m_kMaterialIndices8.m_data
                                      : (const void*)pkStorage->m_kMaterialIndices16.m_data;
            if (pkStorage->m_kMaterials.m_iElementCount)
                kPart.m_pIndexBase = pkStorage->m_kMaterials.m_data;
            else
                kPart.m_pIndexBase = pkStorage->m_kNamedMaterials.m_data;
        }
        for (int i = 0; i < m_kShapesSubparts.m_iElementCount; i++)
        {
            hkpShapesSubpartD4A1& kPart = m_kShapesSubparts.m_data[i];
            new (m_kShapeSubparts.m_data[i]) FUN_00d49c40(flag);
            FUN_00d49c40* pkStorage = m_kShapeSubparts.m_data[i];
            kPart.m_pVertexBase = (kPart.m_iMaterialIndexType == 1)
                                      ? (const void*)pkStorage->m_kMaterialIndices8.m_data
                                      : (const void*)pkStorage->m_kMaterialIndices16.m_data;
            kPart.m_pIndexBase = pkStorage->m_kMaterials.m_data;
        }
    }
}

struct FUN_00d4aec0_Class
{
    unsigned short m_usMemSizeAndFlags;
    void FUN_00d49cb0();
    virtual FUN_00d4aec0_Class* FUN_00d4aec0(unsigned char flags);
};
// @fnv 0x00d4aec0
FUN_00d4aec0_Class* FUN_00d4aec0_Class::FUN_00d4aec0(unsigned char flags)
{
    FUN_00d49cb0();
    if (flags & 1)
    {
        MemoryManager* mgr = _D1A0E0GetMemoryRouter();
        mgr->m_router->Release(this, m_usMemSizeAndFlags);
    }
    return this;
}

namespace fnv_00d4aef0 {
class hkMemoryAllocatorD4AE
{
  public:
    virtual ~hkMemoryAllocatorD4AE() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4AE
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4AE* m_pStreamAllocator;
    hkMemoryAllocatorD4AE& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4AE& __cdecl FUN_00c85750();

template <class T> __forceinline void destructD4AE(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayD4AE
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4AE() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ~hkArrayD4AE()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructD4AE(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorD4AE& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

struct hkVector4D4AE
{
    hkReal x, y, z, w;
};

struct hkpMeshMaterialD4AE
{
    hkUint32 m_uiFilterInfo;
};

struct hkpStorageExtendedMeshShapeMaterialD4AE : public hkpMeshMaterialD4AE
{
    hkHalf m_fElasticity;
    hkHalf m_fSlipAngle;
    hkUlong m_ulUserData;
};

struct hkpNamedMeshMaterialD4AE : public hkpMeshMaterialD4AE
{
    FUN_00cb0c00_class m_name;
};

class hkReferencedObjectD4AE
{
  public:
    hkReferencedObjectD4AE() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectD4AE() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d4aef0 : public hkReferencedObjectD4AE
{
  public:
    hkArrayD4AE<hkVector4D4AE> m_kVertices;
    hkArrayD4AE<hkUint8> m_kIndices8;
    hkArrayD4AE<hkUint16> m_kIndices16;
    hkArrayD4AE<hkUint32> m_kIndices32;
    hkArrayD4AE<hkUint8> m_kMaterialIndices8;
    hkArrayD4AE<hkpStorageExtendedMeshShapeMaterialD4AE> m_kMaterials;
    hkArrayD4AE<hkpNamedMeshMaterialD4AE> m_kNamedMaterials;
    hkArrayD4AE<hkUint16> m_kMaterialIndices16;

    FUN_00d4aef0() throw();
    virtual ~FUN_00d4aef0() throw();
};

// @fnv 0x00d4aef0
FUN_00d4aef0::FUN_00d4aef0() throw()
{}
}  // namespace fnv_00d4aef0

namespace fnv_00d4af60 {
class hkMemoryAllocatorD4AF
{
  public:
    virtual ~hkMemoryAllocatorD4AF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4AF
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4AF* m_pStreamAllocator;
    hkMemoryAllocatorD4AF& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4AF& __cdecl FUN_00c85750();

template <class T> __forceinline void destructD4AF(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayD4AF
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ~hkArrayD4AF()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructD4AF(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorD4AF& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

struct hkVector4D4AF
{
    hkReal x, y, z, w;
};

struct hkpMeshMaterialD4AF
{
    hkUint32 m_uiFilterInfo;
};

struct hkpStorageExtendedMeshShapeMaterialD4AF : public hkpMeshMaterialD4AF
{
    hkHalf m_fElasticity;
    hkHalf m_fSlipAngle;
    hkUlong m_ulUserData;
};

struct hkpNamedMeshMaterialD4AF : public hkpMeshMaterialD4AF
{
    FUN_00cb0c00_class m_name;
};

class hkReferencedObjectD4AF
{
  public:
    virtual ~hkReferencedObjectD4AF() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d4af60 : public hkReferencedObjectD4AF
{
  public:
    hkArrayD4AF<hkVector4D4AF> m_kVertices;
    hkArrayD4AF<hkUint8> m_kIndices8;
    hkArrayD4AF<hkUint16> m_kIndices16;
    hkArrayD4AF<hkUint32> m_kIndices32;
    hkArrayD4AF<hkUint8> m_kMaterialIndices8;
    hkArrayD4AF<hkpStorageExtendedMeshShapeMaterialD4AF> m_kMaterials;
    hkArrayD4AF<hkpNamedMeshMaterialD4AF> m_kNamedMaterials;
    hkArrayD4AF<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4af60() throw();
};

// @fnv 0x00d4af60
FUN_00d4af60::~FUN_00d4af60() throw()
{}
}  // namespace fnv_00d4af60

class hkMemoryAllocatorD4AC
{
  public:
    virtual ~hkMemoryAllocatorD4AC() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4AC
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD4AC* m_pStreamAllocator;

    hkMemoryAllocatorD4AC& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterD4AC& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayD4AC
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4AC() throw()
    {
        hkMemoryAllocatorD4AC& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD4AC {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};
}

struct MaterialD4AC
{
    int unk00, unk04, unk08;
};

struct FUN_00d4ac70
{
    struct hkpStorageExtendedMeshShape
    {
        struct ShapeSubpartStorage : public hkD4AC::hkReferencedObject
        {
            virtual ~ShapeSubpartStorage();

            hkArrayD4AC<unsigned char> m_kMaterialIndices8;
            hkArrayD4AC<MaterialD4AC> m_kMaterials;
            hkArrayD4AC<unsigned short> m_kMaterialIndices16;
        };
    };
};

// @fnv 0x00d4ac70
FUN_00d4ac70::hkpStorageExtendedMeshShape::ShapeSubpartStorage::~ShapeSubpartStorage()
{}

#include <xmmintrin.h>
namespace fnv_00d4aa70 {
class hkMemoryAllocatorD4AA
{
  public:
    virtual ~hkMemoryAllocatorD4AA() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> T* _bufAlloc(int& iReqNumInOut)
    {
        int n = iReqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        iReqNumInOut = n / (int)sizeof(T);
        return (T*)p;
    }
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4AA
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4AA* m_pStreamAllocator;
    hkMemoryAllocatorD4AA& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4AA& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD4AA(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayD4AA
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4AA() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }

    __forceinline void operator=(const hkArrayD4AA& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorD4AA& kAlloc, const hkArrayD4AA& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyD4AA(m_data, a.m_data, m_iElementCount);
    }
};

struct __declspec(align(16)) hkVector4D4AA
{
    __m128 m_vComponents;
    void operator=(const hkVector4D4AA& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkpTrianglesSubpartD4AA
{
    char m_pad00[0x60];
};

struct hkpShapesSubpartD4AA
{
    char m_pad00[0x40];
};

class hkpShapeD4AA
{
  public:
    virtual void CalcSizeForSpu() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUlong m_ulUserData;
    hkUint32 m_type;
};

class hkpShapeContainerD4AA
{
  public:
    virtual int GetNumChildShapes() const throw();
};

class FUN_00d569c0 : public hkpShapeD4AA, public hkpShapeContainerD4AA
{
  public:
    hkBool m_bDisableWelding;
    char m_pad15[0x6b];
    hkVector4D4AA m_kAabbHalfExtents;
    hkVector4D4AA m_kAabbCenter;
    char m_padA0[0x10];
    int m_iNumBitsForSubpartIndex;
    hkArrayD4AA<hkpTrianglesSubpartD4AA> m_kTrianglesSubparts;
    hkArrayD4AA<hkpShapesSubpartD4AA> m_kShapesSubparts;
    hkArrayD4AA<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    char m_padD9[0xb];
    hkReal m_fSphereRadius;
    char m_padE8[0x8];

    FUN_00d569c0(hkReal fRadius, int iNumBitsForSubpartIndex) throw();
    void FUN_00d55950() throw();
};

class FUN_00d4aa70 : public FUN_00d569c0
{
  public:
    hkArrayD4AA<void*> m_kMeshSubparts;
    hkArrayD4AA<void*> m_kShapeSubparts;
    char m_pad108[0x8];

    FUN_00d4aa70(const FUN_00d569c0* pkMesh) throw();
    void addTrianglesSubpart(const hkpTrianglesSubpartD4AA& kPart) throw();
    void addShapesSubpart(const hkpShapesSubpartD4AA& kPart) throw();
};

typedef char fnv_check_d4aa70_a[(sizeof(FUN_00d4aa70) == 0x110) ? 1 : -1];

// Constructs from pkMesh, copies its half extents, user data and welding data, calls addTrianglesSubpart and addShapesSubpart per subpart, then FUN_00d55950.
// @fnv 0x00d4aa70
FUN_00d4aa70::FUN_00d4aa70(const FUN_00d569c0* pkMesh) throw()
    : FUN_00d569c0(pkMesh->m_fSphereRadius, pkMesh->m_iNumBitsForSubpartIndex)
{
    m_kAabbHalfExtents = pkMesh->m_kAabbHalfExtents;
    m_ulUserData = pkMesh->m_ulUserData;
    m_bDisableWelding = pkMesh->m_bDisableWelding;

    for (int i = 0; i < pkMesh->m_kTrianglesSubparts.GetLogicalSize(); i++)
        addTrianglesSubpart(pkMesh->m_kTrianglesSubparts[i]);
    for (int i = 0; i < pkMesh->m_kShapesSubparts.GetLogicalSize(); i++)
        addShapesSubpart(pkMesh->m_kShapesSubparts[i]);

    m_kWeldingInfo = pkMesh->m_kWeldingInfo;
    m_eWeldingType = pkMesh->m_eWeldingType;
    FUN_00d55950();
}
}  // namespace fnv_00d4aa70

struct __declspec(align(16)) hkVector4D4AB
{
    __m128 m_vComponents;
    void operator=(const hkVector4D4AB& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkpExtendedMeshShapeSubpartD4AB
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    hkUlong m_ulUserData;
};

struct hkpExtendedMeshShapeTrianglesSubpartD4AB : public hkpExtendedMeshShapeSubpartD4AB
{
    int m_iVertexStride;
    const hkReal* m_pMaterialIndexBase;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    hkVector4D4AB m_kVertexTransform;
    int m_iTriangleIndexStride;
    int m_iMaterialStriding;
    hkInt8 m_ucIndexStridingType;
    hkInt8 m_bFlipAlternateTriangles;
    int m_iTriangleOffset;
    int m_userData50;

    hkpExtendedMeshShapeTrianglesSubpartD4AB& FUN_00d4abf0(
        const hkpExtendedMeshShapeTrianglesSubpartD4AB& kOther) throw();
};

// Copies all triangle subpart fields from kOther into this, after delegating to the base class assignment operator.
// @fnv 0x00d4abf0
hkpExtendedMeshShapeTrianglesSubpartD4AB& hkpExtendedMeshShapeTrianglesSubpartD4AB::FUN_00d4abf0(
    const hkpExtendedMeshShapeTrianglesSubpartD4AB& kOther) throw()
{
    hkpExtendedMeshShapeSubpartD4AB::operator=(kOther);
    m_iVertexStride = kOther.m_iVertexStride;
    m_pMaterialIndexBase = kOther.m_pMaterialIndexBase;
    m_iStridedVertexCount = kOther.m_iStridedVertexCount;
    m_pMaterialDataBase = kOther.m_pMaterialDataBase;
    m_kVertexTransform = kOther.m_kVertexTransform;
    m_iTriangleIndexStride = kOther.m_iTriangleIndexStride;
    m_iMaterialStriding = kOther.m_iMaterialStriding;
    m_ucIndexStridingType = kOther.m_ucIndexStridingType;
    m_bFlipAlternateTriangles = kOther.m_bFlipAlternateTriangles;
    m_iTriangleOffset = kOther.m_iTriangleOffset;
    m_userData50 = kOther.m_userData50;
    return *this;
}

namespace fnv_00d4ad60 {
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

template <class T> class hkRefPtrD4AD
{
  public:
    T* m_pRetainedObject;

    hkRefPtrD4AD(const hkRefPtrD4AD& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrD4AD()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(const hkRefPtrD4AD& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

class hkMemoryAllocatorD4AD;
struct hkMemoryRouterD4AD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4AD* m_pStreamAllocator;
    hkMemoryAllocatorD4AD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4AD& __cdecl FUN_00c85750();
int __cdecl FUN_00c908c0(hkMemoryAllocatorD4AD& kAlloc, void* apvArray, int iNumElements, int iSizeOfElement);

template <class T> __forceinline void destructD4AD(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <class T> __forceinline void copyD4AD(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}
template <class T> __forceinline void constructWithArrayD4AD(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; i++)
        new (t + i) T(tcopy[i]);
}

template <class T> class hkArrayD4AD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD4AD& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }

    __forceinline void operator=(const hkArrayD4AD& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorD4AD& kAlloc, const hkArrayD4AD& a)
    {
        int iOldSize = m_iElementCount;
        int iNewSize = a.m_iElementCount;
        int iCopiedSize = iNewSize > iOldSize ? iOldSize : iNewSize;

        reserve(kAlloc, iNewSize);

        destructD4AD(m_data + iNewSize, iOldSize - iNewSize);
        copyD4AD(m_data, a.m_data, iCopiedSize);
        constructWithArrayD4AD(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);

        m_iElementCount = iNewSize;
    }
};

struct __declspec(align(16)) hkVector4D4AD
{
    __m128 m_vComponents;
    void operator=(const hkVector4D4AD& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkQuaternionD4AD
{
    hkVector4D4AD m_vec;
};

class hkpConvexShapeD4AD : public FUN_00d1df70
{
};

struct hkpExtendedMeshShapeSubpartD4AD
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    hkUlong m_ulUserData;
};

struct hkpExtendedMeshShapeShapesSubpartD4AD : public hkpExtendedMeshShapeSubpartD4AD
{
    hkArrayD4AD<hkRefPtrD4AD<hkpConvexShapeD4AD> > m_kChildShapes;
    hkQuaternionD4AD m_rotation;
    hkVector4D4AD m_vTranslation;

    hkpExtendedMeshShapeShapesSubpartD4AD& FUN_00d4ad60(const hkpExtendedMeshShapeShapesSubpartD4AD& kOther) throw();
};

// Copies the base subpart fields, child shapes array, rotation, and translation from kOther into this subpart, then returns a reference to this.
// @fnv 0x00d4ad60
hkpExtendedMeshShapeShapesSubpartD4AD& hkpExtendedMeshShapeShapesSubpartD4AD::FUN_00d4ad60(
    const hkpExtendedMeshShapeShapesSubpartD4AD& kOther) throw()
{
    hkpExtendedMeshShapeSubpartD4AD::operator=(kOther);
    m_kChildShapes = kOther.m_kChildShapes;
    m_rotation = kOther.m_rotation;
    m_vTranslation = kOther.m_vTranslation;
    return *this;
}
}  // namespace fnv_00d4ad60

#include <string.h>
extern "C" void _ReadWriteBarrier();

void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        memcpy(p + i, &t, sizeof(T));
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct NineIntegerRecord
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    static __forceinline NineIntegerRecord& GetMonitorStream()
    {
        return *static_cast<NineIntegerRecord*>(static_cast<void*>(FUN_00c85750()));
    }
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct HavokArrayUtilities
{
    static __forceinline void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int reqCapacity,
                                                        int sizeElem)
    {
        FUN_00c908c0(&alloc, array, reqCapacity, sizeElem);
    }
    static __forceinline void __cdecl GrowArray(hkMemoryAllocator& alloc, void* array, int sizeElem)
    {
        ResizeAudioStream(&alloc, array, sizeElem);
    }
};

template <typename T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline T* begin()
    {
        return m_data;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            if (sizeof(T) == 12)
            {
                int doubled = capacity * 2;
                int count;
                if (n < doubled)
                    count = doubled;
                else
                    count = n;
                HavokArrayUtilities::GrowArrayCapacity(alloc, this, count, sizeof(T));
            }
            else
            {
                int cap2 = 2 * capacity;
                int newSize = n;
                if (newSize < cap2)
                    newSize = cap2;
                HavokArrayUtilities::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
            }
        }
    }
    __forceinline T* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    __forceinline T* expandBy(int n)
    {
        return _expandBy(NineIntegerRecord::GetMonitorStream().heap(), n);
    }

    __forceinline int expandByIndex(int n)
    {
        hkMemoryAllocator& alloc = NineIntegerRecord::GetMonitorStream().heap();
        int first = m_iElementCount;
        GrowArrayCapacity(alloc, first + n);
        m_iElementCount += n;
        return first;
    }
    __forceinline void AddBack(const T& t)
    {
        NineIntegerRecord& router = NineIntegerRecord::GetMonitorStream();
        if (m_iElementCount == getCapacity())
        {
            HavokArrayUtilities::GrowArray(router.heap(), this, sizeof(T));
        }
        constructWithCopy(m_data + m_iElementCount, 1, t);
        if (sizeof(T) == 2)
            _ReadWriteBarrier();
        ++m_iElementCount;
    }
};

__forceinline hkInt16 halfBits(hkReal r)
{
    return hkInt16(*(int*)&r >> 16);
}
struct hkHalfT
{
    hkInt16 m_uiFilterValue;
    __forceinline void operator=(const hkReal& r)
    {
        m_uiFilterValue = halfBits(r);
    }
};

struct StorageReferencedObject : hkBaseObject
{
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    __forceinline StorageReferencedObject() : m_sReferenceCount(1)
    {}
    __forceinline void* operator new(unsigned int nbytes)
    {
        StorageReferencedObject* b = static_cast<StorageReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        return b;
    }
};

class hkClass;
extern const hkClass g_kHkpMeshMaterialClass;

struct hkpMeshMaterial
{
    hkUint32 m_uiFilterInfo;
};

struct StorageMaterial : hkpMeshMaterial
{
    hkHalfT m_fElasticity;
    hkHalfT m_fSlipAngle;
    hkUlong m_ulUserData;
};

struct MeshSubpartStorage : StorageReferencedObject
{
    hkArr<hkUint8> m_kMaterialIndices8;
    hkArr<StorageMaterial> m_kMaterials;
    hkArr<hkUint16> m_kMaterialIndices16;
    __forceinline MeshSubpartStorage()
    {}
    virtual ~MeshSubpartStorage();
};

enum MaterialIndexStridingType
{
    MATERIAL_INDICES_INVALID,
    MATERIAL_INDICES_INT8,
    MATERIAL_INDICES_INT16,
};

struct TrianglesSubpart
{
    char m_type;
    char m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const hkpMeshMaterial* m_pIndexBase;
    const hkClass* m_pMaterialBase;
    hkUlong m_ulUserData;
    int m_iVertexStride;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    void FUN_00d4ad60(const TrianglesSubpart& other);
};

class StorageMeshShape
{
  public:
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    hkArr<TrianglesSubpart> m_kTrianglesSubparts;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_numBitsOrSomething;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    hkArr<MeshSubpartStorage*> m_kMeshSubparts;

    TrianglesSubpart* AppendElement();
    void FUN_00d55950();
    int FUN_00d55520(TrianglesSubpart& part);

    int addShapesSubpart(const TrianglesSubpart& partIn);
};

// Copies partIn into a new TrianglesSubpart, copies its vertex and material index data into MeshSubpartStorage, and returns the new subpart index.
// @fnv 0x00d49dc0
int StorageMeshShape::addShapesSubpart(const TrianglesSubpart& partIn)
{
    TrianglesSubpart& part = *AppendElement();
    m_kMeshSubparts.AddBack(new MeshSubpartStorage());
    MeshSubpartStorage* storage = m_kMeshSubparts.back();

    part.FUN_00d4ad60(partIn);

    part.m_iMaterialIndexType = partIn.m_iMaterialIndexType;
    if (partIn.m_pVertexBase)
    {
        if (partIn.m_iMaterialIndexType == MATERIAL_INDICES_INT8)
        {
            hkArr<hkUint8>& indices = storage->m_kMaterialIndices8;
            if (partIn.m_iVertexStriding == 0)
            {
                indices.AddBack(*(const hkUint8*)partIn.m_pVertexBase);
                part.m_pVertexBase = &indices.back();
            }
            else
            {
                int num = partIn.m_iVertexStride;
                hkUint8* dst = indices.expandBy(num);
                part.m_pVertexBase = dst;
                const hkUint8* src = (const hkUint8*)partIn.m_pVertexBase;
                for (int i = 0; i < num; i++)
                {
                    dst[i] = *src;
                    src += partIn.m_iVertexStriding;
                }
            }
        }
        else
        {
            hkArr<hkUint16>& indices = storage->m_kMaterialIndices16;
            if (partIn.m_iVertexStriding == 0)
            {
                indices.AddBack(*(const hkUint16*)partIn.m_pVertexBase);
                _ReadWriteBarrier();
                part.m_pVertexBase = &indices.back();
            }
            else
            {
                int num = partIn.m_iVertexStride;
                hkUint16* dst = indices.expandBy(num);
                part.m_pVertexBase = dst;
                const hkUint8* src = (const hkUint8*)partIn.m_pVertexBase;
                for (int i = 0; i < num; i++)
                {
                    dst[i] = *(const hkUint16*)src;
                    src += partIn.m_iVertexStriding;
                }
            }
        }
        part.m_iVertexStriding = partIn.m_iVertexStriding;
        if (part.m_iVertexStriding)
        {
            switch (part.m_iMaterialIndexType)
            {
            case MATERIAL_INDICES_INT8:
                part.m_iVertexStriding = sizeof(hkUint8);
                break;
            case MATERIAL_INDICES_INT16:
                part.m_iVertexStriding = sizeof(hkUint16);
                break;
            }
        }
    }
    else
    {
        part.m_pVertexBase = 0;
        part.m_iVertexStriding = 0;
    }

    if (part.m_pVertexBase)
    {
        hkArr<StorageMaterial>& materials = storage->m_kMaterials;
        int first = materials.expandByIndex(partIn.m_iNumTriangles);
        const hkpMeshMaterial* src = partIn.m_pIndexBase;
        StorageMaterial* dst = materials.m_data + first;
        for (int i = 0; i < partIn.m_iNumTriangles; i++)
        {
            if (partIn.m_pMaterialBase == &g_kHkpMeshMaterialClass)
            {
                *dst = *static_cast<const StorageMaterial*>(src);
            }
            else
            {
                dst->m_uiFilterInfo = src->m_uiFilterInfo;
                dst->m_fSlipAngle = 1.0f;
                dst->m_fElasticity = 0.0f;
            }
            src = (const hkpMeshMaterial*)((const char*)src + partIn.m_iIndexStriding);
            dst++;
        }
        if (partIn.m_iIndexStriding)
        {
            part.m_iIndexStriding = sizeof(StorageMaterial);
            part.m_iNumTriangles = partIn.m_iNumTriangles;
        }
        else
        {
            part.m_iIndexStriding = 0;
            part.m_iNumTriangles = 1;
        }
        part.m_pIndexBase = materials.begin();
    }

    FUN_00d55950();
    m_numBitsOrSomething += FUN_00d55520(part);
    return m_kTrianglesSubparts.m_iElementCount - 1;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00d4ad50();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d4ad50();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d4ad50
    virtual void FUN_00d4ad50();
};

Derived::Derived()
{}

#include <xmmintrin.h>
namespace fnv_00d56500 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_and_ps(__m128 a, __m128 b);
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    __m128 _mm_set_ps1(float a);
    int _mm_movemask_ps(__m128 a);
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

typedef float hkReal;
typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;

extern const __m128 g_hkQuadIdentityQuat;
extern const __m128 g_hkQuadZero;
extern const __m128 g_hkQuadAbsMask;
extern const float g_hkEqualsEps;

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};

struct hkMemoryRouterS
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterS* FUN_00c85750();

struct hkArrayUtilS
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int reqCapacity, int sizeElem);
};

struct hkConvexShapeS
{
    void RetainReference() const;
    void removeReference() const;
};

template <class T> struct hkRefPtrS
{
    T* m_pRetainedObject;

    __forceinline hkRefPtrS() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(T* e)
    {
        if (e)
        {
            e->RetainReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
};

template <typename T> struct hkArrS
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArrS() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtilS::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            new (p + i) T;
        }
    }

    __forceinline T* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        construct(m_data + m_iElementCount, n);
        m_iElementCount += n;
        return m_data + oldsize;
    }

    __forceinline T* expandBy(int n)
    {
        return _expandBy(FUN_00c85750()->heap(), n);
    }
};

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkVector4q
{
    __m128 m_vComponents;
};

struct ShapesSubpartS
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    unsigned int m_ulUserData;
    hkArrS<hkRefPtrS<hkConvexShapeS> > m_kChildShapes;
    hkVector4q m_rotation;
    hkVector4f m_vTranslation;

    __forceinline void initSubpart(hkInt8 type)
    {
        m_type = type;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_pIndexBase = 0;
        m_pVertexBase = 0;
        m_ulUserData = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
    }
    ShapesSubpartS* FUN_00d56500(hkConvexShapeS* const* childShapes, int numChildShapes, const hkVector4f& offset);
};

static __forceinline bool equals3(const hkVector4f& a, const __m128& b, hkReal epsilon)
{
    const __m128 diff = _mm_and_ps(_mm_sub_ps(*(const __m128*)&a, b), g_hkQuadAbsMask);
    const __m128 eps = _mm_set_ps1(epsilon);
    return (_mm_movemask_ps(_mm_cmple_ps(diff, eps)) & 7) == 7;
}

// Initializes a convex subpart with child shapes, translation offset, and identity rotation, encoding a non-zero flag in the translation w component.
// @fnv 0x00d56500
ShapesSubpartS* ShapesSubpartS::FUN_00d56500(hkConvexShapeS* const* childShapes, int numChildShapes,
                                             const hkVector4f& offset)
{
    initSubpart(1);
    m_kChildShapes.init();
    m_vTranslation = offset;

    hkRefPtrS<hkConvexShapeS>* dst = m_kChildShapes.expandBy(numChildShapes);
    for (int i = 0; i < numChildShapes; i++)
    {
        dst[i] = childShapes[i];
    }

    m_rotation.m_vComponents = g_hkQuadIdentityQuat;
    const int bOffsetNonZero = !equals3(offset, g_hkQuadZero, g_hkEqualsEps);
    *(int*)&m_vTranslation.w = bOffsetNonZero | 0x3f000000;
    return this;
}
}  // namespace fnv_00d56500

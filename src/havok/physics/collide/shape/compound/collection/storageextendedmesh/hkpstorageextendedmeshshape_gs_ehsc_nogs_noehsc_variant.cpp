
// src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
extern int DAT_010cfd84;
struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00d4a170(unsigned int unusedArg);
};
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
struct FUN_00d4aec0_Class
{
    unsigned short m_usMemSizeAndFlags;
    void FUN_00d49cb0();
    virtual FUN_00d4aec0_Class* FUN_00d4aec0(unsigned char flags);
};
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
#include <xmmintrin.h>
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

extern "C" void _ReadWriteBarrier();

extern "C" void* __cdecl FUN_00cb1280(void*, int, unsigned int);
enum hkPlacementNewArg
{
    hkPlacementNew
};
inline void* operator new(unsigned int, void* p, hkPlacementNewArg)
{
    return p;
}

struct Subpart
{
    unsigned char type;
    signed char materialIndexType;
    short materialStride;
    void* materialIndexBase;
    unsigned short materialIndexStride, numMaterials;
    const char* materialBase;
    const void* materialClass;
    int numTriangles;
    const char* vertexBase;
    int vertexStride, numVertices;
    __m128 extrusionVector;
    const char* indexBase;
    unsigned int indexStride;
    unsigned char indexType, extrusion;
    unsigned short flags;
    void FUN_00d4abf0(const Subpart&);
};
struct MaterialName
{
    const char* value;
    MaterialName(const char*) throw();
    MaterialName& operator=(const MaterialName&);
};
struct NamedMaterial
{
    int filterInfo;
    MaterialName name;
    NamedMaterial() throw() : name("Default")
    {
        filterInfo = 0;
    }
};
struct MeshMaterial
{
    int filterInfo;
    union
    {
        struct
        {
            short restitution, friction;
        };
        int properties;
    };
    int userData;
};
struct AllocationRouter
{
    virtual void Unused();
    virtual void* Allocate(int);
};
void FUN_00c908c0(void*, void*, int, int);
void ResizeAudioStream(void*, void*, int);
static __declspec(noinline) int FUN_00d49c20(int stride, int triangles)
{
    switch (stride)
    {
    case 1:
        return triangles + 2;
    case 2:
        return triangles * 2 + 1;
    default:
        return triangles * 4;
    }
}
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269bb4, g_01268c8c;

template <class T> inline void initializeItems(T*, int)
{}
inline void initializeItems(NamedMaterial* destination, int count)
{
    for (int i = 0; i < count; ++i)
        new (destination + i, hkPlacementNew) NamedMaterial;
}
template <class T> struct Buffer
{
    T* m_data;
    int m_iElementCount, m_iCapacityState;
    inline void reserveUsing(hkMemoryAllocatorD4AC& allocator, int requested)
    {
        int available = m_iCapacityState & 0x3fffffff;
        if (available < requested)
        {
            int next = requested < available * 2 ? available * 2 : requested;
            FUN_00c908c0(&allocator, this, next, sizeof(T));
        }
    }
    inline T* growUsing(hkMemoryAllocatorD4AC& allocator, int count)
    {
        int offset = m_iElementCount;
        reserveUsing(allocator, offset + count);
        initializeItems(m_data + m_iElementCount, count);
        m_iElementCount += count;
        return m_data + offset;
    }
    inline T* grow(int count)
    {
        return growUsing(fnvc_adapt::FUN_00c85750().heap(), count);
    }
};
struct FUN_00d4aef0
{
    int vtable;
    unsigned short size, flags;
    Buffer<__m128> vertices;
    Buffer<unsigned char> indices8;
    Buffer<unsigned short> indices16;
    Buffer<unsigned int> indices32;
    Buffer<unsigned char> materialIndices8;
    Buffer<MeshMaterial> materials;
    Buffer<NamedMaterial> namedMaterials;
    Buffer<unsigned short> materialIndices16;
    FUN_00d4aef0() throw();
    static void* operator new(unsigned int bytes)
    {
        hkMemoryAllocatorD4AC& allocator = fnvc_adapt::FUN_00c85750().heap();
        FUN_00d4aef0* memory = static_cast<FUN_00d4aef0*>(allocator.AllocateMemoryBlock(bytes));
        memory->size = static_cast<unsigned short>(bytes);
        return memory;
    }
};

template <class T> inline void copyItems(T* destination, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        destination[i] = value;
}
template <class T, template <class> class A> inline void append(A<T>& a, const T& value)
{
    hkMemoryRouterD49C* manager = FUN_00c85750();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager->m_pkHeap, &a, sizeof(T));
    copyItems(a.m_data + a.m_iElementCount, 1, value);
    ++a.m_iElementCount;
}
inline void append(Buffer<unsigned char>& a, const unsigned char& value)
{
    hkMemoryRouterD49C* manager = FUN_00c85750();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager->m_pkHeap, &a, sizeof(unsigned char));
    unsigned char* slot = a.m_data;
    _ReadWriteBarrier();
    slot += a.m_iElementCount;
    copyItems(slot, 1, value);
    ++a.m_iElementCount;
}
inline void append(Buffer<unsigned short>& a, const unsigned short& value)
{
    hkMemoryRouterD49C* manager = FUN_00c85750();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager->m_pkHeap, &a, sizeof(unsigned short));
    copyItems(a.m_data + a.m_iElementCount, 1, value);
    _ReadWriteBarrier();
    ++a.m_iElementCount;
    _ReadWriteBarrier();
}
inline short halfValue(const float& value)
{
    return short(*reinterpret_cast<const int*>(&value) >> 16);
}
struct SourceArg
{
    const Subpart* p;
    SourceArg(const Subpart* q) : p(q)
    {}
};
struct StorageShape : hkpStorageExtendedMeshShape
{
    Subpart* FUN_00d562f0();
    void FUN_00d55950();
    int Vec4(Subpart*, int);
    void addTrianglesSubpart(SourceArg sourceArg);
};

// @fnv 0x00d4a2b0
void StorageShape::addTrianglesSubpart(SourceArg sourceArg)
{
    Subpart* destination = FUN_00d562f0();
    const Subpart& source = *sourceArg.p;
    destination->FUN_00d4abf0(source);
    FUN_00d4aef0* created = new FUN_00d4aef0;
    hkArray<hkpStorageExtendedMeshShapeMeshSubpartStorage*>& mesh = m_kMeshSubparts;
    append(mesh, reinterpret_cast<hkpStorageExtendedMeshShapeMeshSubpartStorage*>(created));
    _ReadWriteBarrier();
    FUN_00d4aef0* storage = reinterpret_cast<FUN_00d4aef0*>(mesh.m_data[mesh.m_iElementCount - 1]);
    __m128* vertices = storage->vertices.grow(source.numVertices);
    const char* vertex = source.vertexBase;
    for (int i = 0; i < source.numVertices; ++i)
    {
        const float* v = reinterpret_cast<const float*>(vertex);
        *vertices++ = _mm_setr_ps(v[0], v[1], v[2], 0.0f);
        vertex += source.vertexStride;
    }
    destination->vertexBase = reinterpret_cast<const char*>(storage->vertices.m_data);
    destination->vertexStride = 16;
    destination->numVertices = source.numVertices;
    void* indices;
    if (source.indexType == 1)
    {
        const int inputStride = source.indexStride;
        const int stride = inputStride <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned char);
        int count = FUN_00d49c20(inputStride, source.numTriangles);
        unsigned char* data = storage->indices8.grow(count);
        FUN_00cb1280(data, 0, count * sizeof(unsigned char));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned char* p = reinterpret_cast<const unsigned char*>(input);
            unsigned char* q = reinterpret_cast<unsigned char*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    else if (source.indexType == 2)
    {
        const unsigned int inputStride = source.indexStride >> 1;
        const int stride = static_cast<int>(inputStride) <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned short);
        int count = FUN_00d49c20(inputStride, source.numTriangles);
        unsigned short* data = storage->indices16.grow(count);
        FUN_00cb1280(data, 0, count * sizeof(unsigned short));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned short* p = reinterpret_cast<const unsigned short*>(input);
            unsigned short* q = reinterpret_cast<unsigned short*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    else
    {
        const unsigned int inputStride = source.indexStride >> 2;
        const int stride = static_cast<int>(inputStride) <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned int);
        int count = FUN_00d49c20(inputStride, source.numTriangles);
        unsigned int* data = storage->indices32.grow(count);
        FUN_00cb1280(data, 0, count * sizeof(unsigned int));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned int* p = reinterpret_cast<const unsigned int*>(input);
            unsigned int* q = reinterpret_cast<unsigned int*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    destination->indexType = source.indexType;
    destination->numTriangles = source.numTriangles;
    destination->extrusion = source.extrusion;
    destination->indexBase = static_cast<const char*>(indices);
    destination->materialIndexType = source.materialIndexType;
    if (source.materialIndexBase)
    {
        if (source.materialIndexType == 1)
        {
            Buffer<unsigned char>& materialIndices = storage->materialIndices8;
            if (source.materialIndexStride == 0)
            {
                append(materialIndices, *static_cast<const unsigned char*>(source.materialIndexBase));
                destination->materialIndexBase = materialIndices.m_data + materialIndices.m_iElementCount - 1;
            }
            else
            {
                unsigned char* data = materialIndices.grow(source.numTriangles);
                destination->materialIndexBase = data;
                const char* input = static_cast<const char*>(source.materialIndexBase);
                for (int i = 0; i < source.numTriangles; ++i)
                {
                    data[i] = *reinterpret_cast<const unsigned char*>(input);
                    input += source.materialIndexStride;
                }
            }
        }
        else
        {
            Buffer<unsigned short>& materialIndices = storage->materialIndices16;
            if (source.materialIndexStride == 0)
            {
                append(materialIndices, *static_cast<const unsigned short*>(source.materialIndexBase));
                destination->materialIndexBase = materialIndices.m_data + materialIndices.m_iElementCount - 1;
            }
            else
            {
                unsigned short* data = materialIndices.grow(source.numTriangles);
                destination->materialIndexBase = data;
                const char* input = static_cast<const char*>(source.materialIndexBase);
                for (int i = 0; i < source.numTriangles; ++i)
                {
                    data[i] = *reinterpret_cast<const unsigned short*>(input);
                    input += source.materialIndexStride;
                }
            }
        }
        destination->materialIndexStride = source.materialIndexStride;
        if (destination->materialIndexStride)
        {
            switch (destination->materialIndexType)
            {
            case 1:
                destination->materialIndexStride = 1;
                break;
            case 2:
                destination->materialIndexStride = 2;
                break;
            }
        }
    }
    else
    {
        destination->materialIndexBase = 0;
        destination->materialIndexStride = 0;
    }
    if (destination->materialIndexBase)
    {
        if (source.materialClass == &g_01269bb4)
        {
            NamedMaterial* data = storage->namedMaterials.grow(source.numMaterials);
            const char* input = source.materialBase;
            for (int i = 0; i < source.numMaterials; ++i)
            {
                NamedMaterial* material = new (data + i, hkPlacementNew) NamedMaterial;
                const NamedMaterial* original = reinterpret_cast<const NamedMaterial*>(input);
                material->filterInfo = original->filterInfo;
                material->name = original->name;
                input += source.materialStride;
            }
            destination->materialBase = reinterpret_cast<const char*>(storage->namedMaterials.m_data);
            if (source.materialStride)
            {
                destination->materialStride = 8;
                destination->numMaterials = source.numMaterials;
            }
            else
            {
                destination->materialStride = 0;
                destination->numMaterials = 1;
            }
        }
        else
        {
            MeshMaterial* data = storage->materials.grow(source.numMaterials);
            const char* input = source.materialBase;
            for (int i = 0; i < source.numMaterials; ++i)
            {
                const MeshMaterial* original = reinterpret_cast<const MeshMaterial*>(input);
                if (source.materialClass == &g_01268c8c)
                {
                    data->filterInfo = original->filterInfo;
                    data->properties = original->properties;
                    data->userData = original->userData;
                }
                else
                {
                    data->filterInfo = original->filterInfo;
                    data->friction = halfValue(1.0f);
                    data->restitution = halfValue(0.0f);
                }
                input += source.materialStride;
                ++data;
            }
            destination->materialBase = reinterpret_cast<const char*>(storage->materials.m_data);
            if (source.materialStride)
            {
                destination->materialStride = 12;
                destination->numMaterials = source.numMaterials;
            }
            else
            {
                destination->materialStride = 0;
                destination->numMaterials = 1;
            }
        }
    }
    FUN_00d55950();
    FUN_00d49cb0* fields = reinterpret_cast<FUN_00d49cb0*>(this);
    int last = reinterpret_cast<FUN_00d56f10*>(this)->m_kTrianglesSubparts.m_iElementCount - 1;
    fields->m_aiUnkCC[5] += Vec4(destination, last);
}

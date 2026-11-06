
// src/havok/physics/collide/shape/compound/collection/simplemesh/hkpsimplemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/simplemesh/hkpsimplemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSimpleMeshShape.h"

struct FUN_00dfd080Object
{
    void* m_vftable;
    unsigned short m_iElementCount;

    void FUN_00dfcfd0();
    FUN_00dfd080Object* FUN_00dfd080(unsigned char flags);
};

struct FUN_00dfd080Manager
{
    // Virtual destructor for the manager object; the body is empty.
// @fnv 0x00dfd080
    virtual ~FUN_00dfd080Manager()
    {}
    virtual void unknown();
    virtual void deallocate(FUN_00dfd080Object* object, unsigned short size)
    {}
};

struct FUN_00dfd080Router
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    void* m_unknown0C;
    FUN_00dfd080Manager* m_manager;
};

FUN_00dfd080Router* _D1A0E0GetMemoryRouter();

FUN_00dfd080Object* FUN_00dfd080Object::FUN_00dfd080(unsigned char flags)
{
    this->FUN_00dfcfd0();

    if (flags & 1)
    {
        FUN_00dfd080Router* router = _D1A0E0GetMemoryRouter();
        router->m_manager->deallocate(this, m_iElementCount);
    }

    return this;
}

struct FUN_00e3c240_s
{
    void FUN_00e3c240(int ai, unsigned short aw);
};

// @fnv 0x00e3c240
void FUN_00e3c240_s::FUN_00e3c240(int aiIndex, unsigned short auValue)
{
    int* p = *(int**)((char*)this + 0x24);
    *(unsigned short*)(p + aiIndex * 4 + 3) = auValue;
}

struct CpuObject
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
    unsigned char value;
    void initWeldingInfo(unsigned char arg0);
};
// @fnv 0x00e3c260
void CpuObject::initWeldingInfo(unsigned char arg0)
{
    value = arg0;
}

class hkMemoryAllocatorDFCF
{
  public:
    virtual ~hkMemoryAllocatorDFCF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDFCF
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDFCF* m_pStreamAllocator;

    hkMemoryAllocatorDFCF& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDFCF& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayDFCF
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayDFCF() throw()
    {
        hkMemoryAllocatorDFCF& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkDFCF {
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

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer() throw()
    {}
};

namespace hkDFCF {
class ListenerDFCF : public hkReferencedObject
{
  public:
    int unk08, unk0C;
    hkpShapeContainer m_kContainer;
};

struct Elem12DFCF
{
    int unk00, unk04, unk08;
};

struct Elem16DFCF
{
    int unk00, unk04, unk08, unk0C;
};
}

class FUN_00dfcfd0
{
  public:
    ~FUN_00dfcfd0();

    hkDFCF::ListenerDFCF m_kShape;
    int unk14;
    hkArrayDFCF<hkDFCF::Elem16DFCF> m_kFirst;
    hkArrayDFCF<hkDFCF::Elem16DFCF> m_kSecond;
    hkArrayDFCF<unsigned char> m_kThird;
};

// Empty destructor body for the FUN_00dfcfd0 class; member destructors are invoked implicitly by the compiler.
// @fnv 0x00dfcfd0
FUN_00dfcfd0::~FUN_00dfcfd0()
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkVector4E3C4
{
    __m128 m_vComponents;

    hkVector4E3C4()
    {}
    hkVector4E3C4(const hkVector4E3C4& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4E3C4& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

template <class T> struct hkArrayE3C4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectE3C4
{
  public:
    virtual ~hkBaseObjectE3C4() throw();
};

class hkReferencedObjectE3C4 : public hkBaseObjectE3C4
{
  public:
    hkReferencedObjectE3C4() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE3C4() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeE3C4 : public hkReferencedObjectE3C4
{
  public:
    hkpShapeE3C4(unsigned int uiType) throw() : m_ulUserData(0), m_type(uiType)
    {}
    virtual ~hkpShapeE3C4() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpSphereRepShapeE3C4 : public hkpShapeE3C4
{
  public:
    hkpSphereRepShapeE3C4(unsigned int uiType) throw() : hkpShapeE3C4(uiType)
    {}
    virtual ~hkpSphereRepShapeE3C4() throw();
};

class hkpConvexShapeE3C4 : public hkpSphereRepShapeE3C4
{
  public:
    hkpConvexShapeE3C4(unsigned int uiType, float fRadius) throw()
        : hkpSphereRepShapeE3C4(uiType), m_fSphereRadius(fRadius)
    {}
    virtual ~hkpConvexShapeE3C4() throw();

    float m_fSphereRadius;
};

class FUN_00de10b0 : public hkpConvexShapeE3C4
{
  public:
    FUN_00de10b0(float fRadius, unsigned short usWeldingInfo, int eWeldingType) throw() : hkpConvexShapeE3C4(3, fRadius)
    {
        m_kWeldingInfo = usWeldingInfo;
        m_eWeldingType = static_cast<unsigned char>(eWeldingType);
        m_kVertexTransform.setZero4();
        m_ucWeldingPadding = 0;
    }
    virtual ~FUN_00de10b0() throw();

    void setVertex(int i, const hkVector4E3C4& kVertexDelta)
    {
        (&m_kVertexA)[i] = kVertexDelta;
    }

    unsigned short m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char m_ucWeldingPadding;
    hkVector4E3C4 m_kVertexA;
    hkVector4E3C4 m_kVertexB;
    hkVector4E3C4 m_kVertexC;
    hkVector4E3C4 m_kVertexTransform;
};

class hkpShapeContainerE3C4
{
  public:
    virtual ~hkpShapeContainerE3C4() throw();
    virtual const hkpShapeE3C4* GetTriangleShape(unsigned int uiKey, unsigned char* pucBuffer) const = 0;
};

class hkpShapeCollectionE3C4 : public hkpShapeE3C4, public hkpShapeContainerE3C4
{
  public:
    virtual ~hkpShapeCollectionE3C4() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpSimpleMeshShapeTriangleE3C4
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    unsigned short m_kWeldingInfo;
};

class hkpSimpleMeshShapeE3C4 : public hkpShapeCollectionE3C4
{
  public:
    virtual ~hkpSimpleMeshShapeE3C4() throw();
    virtual const hkpShapeE3C4* GetTriangleShape(unsigned int uiKey, unsigned char* pucBuffer) const;

    hkArrayE3C4<hkVector4E3C4> m_kVertices;
    hkArrayE3C4<hkpSimpleMeshShapeTriangleE3C4> m_uiTriangleCount;
    hkArrayE3C4<unsigned char> m_kMaterialIndices8;
    float m_fSphereRadius;
    unsigned char m_eWeldingType;
};

// Placement-constructs a triangle shape from the vertex indices in m_uiTriangleCount[uiKey] and returns it as a hkpShapeE3C4 pointer.
// @fnv 0x00e3c430
const hkpShapeE3C4* hkpSimpleMeshShapeE3C4::GetTriangleShape(unsigned int uiKey, unsigned char* pucBuffer) const
{
    FUN_00de10b0* pkTriangle =
        new (pucBuffer) FUN_00de10b0(m_fSphereRadius, m_uiTriangleCount[uiKey].m_kWeldingInfo, m_eWeldingType);
    pkTriangle->setVertex(0, m_kVertices[m_uiTriangleCount[uiKey].m_kPointA]);
    pkTriangle->setVertex(1, m_kVertices[m_uiTriangleCount[uiKey].m_kPointB]);
    pkTriangle->setVertex(2, m_kVertices[m_uiTriangleCount[uiKey].m_iThirdValue]);
    return pkTriangle;
}

struct hkBoolQ
{
    hkBoolQ(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct hkVector4Q
{
    float x, y, z, w;
};
struct TriangleQ
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};
template <class T> struct hkArrayQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};
extern float DAT_011b2e90;
hkBoolQ __cdecl IsDegenerateTriangle(const hkVector4Q& a, const hkVector4Q& b, const hkVector4Q& c, float tol);
struct hkGeometryQ
{
    int unk00;
    int unk04;
    hkArrayQ<hkVector4Q> m_kVertices;
    hkArrayQ<TriangleQ> m_uiTriangleCount;
    int FUN_00e3c340() const;
};
// Returns the index of the first triangle in m_uiTriangleCount that is not degenerate, or -1 if all are degenerate.
// @fnv 0x00e3c340
int hkGeometryQ::FUN_00e3c340() const
{
    for (int i = 0; i < m_uiTriangleCount.GetLogicalSize(); i++)
    {
        if (!IsDegenerateTriangle(m_kVertices[m_uiTriangleCount[i].m_kPointA], m_kVertices[m_uiTriangleCount[i].m_kPointB],
                                  m_kVertices[m_uiTriangleCount[i].m_iThirdValue], DAT_011b2e90))
            return i;
    }
    return -1;
}

template <class T> struct ArrE3C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};
struct Vec4E3C
{
    float v[4];
};
struct TriE3C
{
    int a, b, c, d;
};

int __cdecl FUN_00d06f80(const void* p, int bytes);
extern char DAT_01269198;

struct StatsCollectorE3C
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void AddMemoryChunk(int type, const char* name, const void* chunk, int usedSize, int allocatedSize);
    int unk04, unk08, unk0c;
    bool m_collectArrays;
    template <class T> void addArray(const char* name, int type, const ArrE3C<T>& a)
    {
        if ((a.m_iCapacityState & 0x80000000) == 0 || m_collectArrays)
        {
            const T* data = a.m_data;
            int allocated = FUN_00d06f80(data, a.getCapacity() * (int)sizeof(T));
            AddMemoryChunk(type, name, a.m_data, a.m_iElementCount * (int)sizeof(T), allocated);
        }
    }
};

struct MeshShapeE3C
{
    int pad[6];
    ArrE3C<Vec4E3C> m_kVertices;
    ArrE3C<TriE3C> m_uiTriangleCount;
    ArrE3C<unsigned char> m_materialIds;
    void FUN_00d213e0(StatsCollectorE3C* collector, const void* cls) const;
    void calcContentStatistics(StatsCollectorE3C* collector, const void* cls) const;
};

// Reports the vertex, triangle and material-id arrays to the StatsCollector and then calls FUN_00d213e0 with DAT_01269198.
// @fnv 0x00e3c4e0
void MeshShapeE3C::calcContentStatistics(StatsCollectorE3C* collector, const void* cls) const
{
    collector->addArray("Vertices", 3, m_kVertices);
    collector->addArray("Triangles", 3, m_uiTriangleCount);
    collector->addArray("MaterialIds", 3, m_materialIds);
    FUN_00d213e0(collector, &DAT_01269198);
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00dfcfc0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00dfcfc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dfcfc0
    virtual void FUN_00dfcfc0();
};

Derived::Derived()
{}

// Partial views: only the established virtual operation is declared.
struct hkBoolResult
{
    char m_cBooleanValue;
    hkBoolResult()
    {}
    hkBoolResult(bool value) : m_cBooleanValue(value ? 1 : 0)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct __declspec(align(16)) MeshVertex
{
    float x, y, z, w;
};
struct hkpSimpleMeshShapeTriangleAudit
{
    int m_kPointA, m_kPointB, m_iThirdValue;
    unsigned short m_kWeldingInfo;
};
template <class T> struct MeshArrayBase
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
template <class T> struct MeshArray : MeshArrayBase<T>
{
};
class hkpShapeContainerAudit
{
  public:
    virtual ~hkpShapeContainerAudit();
    virtual unsigned int FUN_00e3c3b0(unsigned int oldKey) const = 0;
};
class hkpShapeCollectionAudit : public hkpShape, public hkpShapeContainerAudit
{
  public:
    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};
class hkpSimpleMeshShapeAudit : public hkpShapeCollectionAudit
{
  public:
    MeshArray<MeshVertex> m_kVertices;
    MeshArray<hkpSimpleMeshShapeTriangleAudit> m_uiTriangleCount;
    MeshArray<unsigned char> m_kMaterialIndices8;
    float m_fSphereRadius;
    unsigned char m_eWeldingType;
    virtual unsigned int FUN_00e3c3b0(unsigned int oldKey) const;
};
extern float DAT_011b2e90;
hkBoolResult __cdecl IsDegenerateTriangle(const MeshVertex&, const MeshVertex&, const MeshVertex&, float);
// @fnv 0x00e3c3b0
unsigned int hkpSimpleMeshShapeAudit::FUN_00e3c3b0(unsigned int oldKey) const
{
    for (int i = static_cast<int>(oldKey) + 1; i < m_uiTriangleCount.GetLogicalSize(); ++i)
    {
        if (!IsDegenerateTriangle(m_kVertices[m_uiTriangleCount[i].m_kPointA], m_kVertices[m_uiTriangleCount[i].m_kPointB],
                                  m_kVertices[m_uiTriangleCount[i].m_iThirdValue], DAT_011b2e90))
            return i;
    }
    return 0xffffffffu;
}

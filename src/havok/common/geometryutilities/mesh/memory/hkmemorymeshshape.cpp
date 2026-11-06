
// src/havok/common/geometryutilities/mesh/memory/hkmemorymeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/mesh/memory/hkmemorymeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryMeshShape.h"

// @fnv 0x00e4a020
void __stdcall FUN_00e4a020(void* unused)
{}

class hkMemMeshShapeCand : public hkMemoryMeshShape
{
  public:
    int getNumSections();
};

// @fnv 0x00e4a030
int hkMemMeshShapeCand::getNumSections()
{
    return m_sections.m_iElementCount;
}

int FUN_00d06f80(const void* pvData, int iSize) throw();

template <typename T> inline int hkGetSize(const hkArray<T>& a)
{
    return a.m_iElementCount;
}
template <typename T> inline int hkGetCapacity(const hkArray<T>& a)
{
    return a.m_iCapacityState & 0x3fffffff;
}

class hkMeshSectionCinfo
{
  public:
    hkReferencedObject* m_pMeshVertexBuffer;
    hkReferencedObject* m_iMaterialIndex;
    int m_aiUnk08[6];
};

class hkStatisticsCollectorE4A0
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void AddObjectInstance(const char* pcFieldName, const hkReferencedObject* pkObject,
                                   const hkClass* pkClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcFieldName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();
    int m_aiUnk04[3];
    hkBool m_bExternalMemory;

    template <typename T> void addArray(const char* pcFieldName, const hkArray<T>& kArray)
    {
        if (!(kArray.m_iCapacityState & 0x80000000) || m_bExternalMemory)
        {
            const T* pData = kArray.m_data;
            int iAllocatedSize = FUN_00d06f80(pData, hkGetCapacity(kArray) * sizeof(T));
            AddMemoryChunk(3, pcFieldName, kArray.m_data, hkGetSize(kArray) * sizeof(T), iAllocatedSize);
        }
    }
};

class hkMemoryMeshShapeE4A0 : public hkMemoryMeshShape
{
  public:
    void CollectMemoryStatistics(hkStatisticsCollectorE4A0* pkCollector, const hkClass* pkClass) const throw();
};

// Reports the indices16, indices32 and sections arrays plus each section's vertexBuffer and material to the statistics collector.
// @fnv 0x00e4a0c0
void hkMemoryMeshShapeE4A0::CollectMemoryStatistics(hkStatisticsCollectorE4A0* pkCollector,
                                                    const hkClass* pkClass) const throw()
{
    pkCollector->addArray("indices16", m_kIndices16);
    pkCollector->addArray("indices32", m_kIndices32);
    pkCollector->addArray("sections", m_sections);
    const int iNumSections = m_sections.m_iElementCount;
    for (int iIndex = 0; iIndex < iNumSections; iIndex++)
    {
        const hkMeshSectionCinfo& kSection = m_sections.m_data[iIndex];
        pkCollector->AddObjectInstance("vertexBuffer", kSection.m_pMeshVertexBuffer, 0);
        pkCollector->AddObjectInstance("material", kSection.m_iMaterialIndex, 0);
    }
}

template <class ENUM, class STORAGE> class hkEnumE4A
{
  public:
    STORAGE m_kStorage;
    operator ENUM() const
    {
        return (ENUM)m_kStorage;
    }
    void operator=(ENUM e)
    {
        m_kStorage = (STORAGE)e;
    }
};

enum PrimitiveTypeE4A
{
    PRIMITIVE_TYPE_UNKNOWN
};

int __cdecl FUN_00e60cb0(PrimitiveTypeE4A type, int numPrimitives);

struct hkMeshSectionCinfoE4A
{
    void* m_pMeshVertexBuffer;
    void* m_iMaterialIndex;
    hkEnumE4A<PrimitiveTypeE4A, unsigned char> m_ePrimitiveType;
    int m_iNumPrimitives;
    bool m_hasIndices;
    void* m_ppIndices;
    int m_iIndexType;
    int m_iSectionVertexCount;
};

struct hkMeshSectionE4A
{
    hkEnumE4A<PrimitiveTypeE4A, unsigned char> m_ePrimitiveType;
    int m_iNumPrimitives;
    int m_iIndexCount;
    int m_iIndexType;
    int m_iSectionVertexCount;
    bool m_hasIndices;
    void* m_ppIndices;
    void* m_pMeshVertexBuffer;
    void* m_iMaterialIndex;
    int m_iVertexOffset;
};

class hkMemoryMeshShapeE4A
{
  public:
    virtual ~hkMemoryMeshShapeE4A();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkMeshSectionCinfoE4A* m_sections;
    void GetSection(int sectionIndex, unsigned char accessFlags, hkMeshSectionE4A& sectionOut);
};

// Copies the cinfo fields of the mesh section at sectionIndex into sectionOut, computing the index count and gating vertex/indices pointers by accessFlags.
// @fnv 0x00e4a040
void hkMemoryMeshShapeE4A::GetSection(int sectionIndex, unsigned char accessFlags, hkMeshSectionE4A& sectionOut)
{
    const hkMeshSectionCinfoE4A& cinfo = m_sections[sectionIndex];
    sectionOut.m_ePrimitiveType = cinfo.m_ePrimitiveType;
    sectionOut.m_iNumPrimitives = cinfo.m_iNumPrimitives;
    sectionOut.m_iIndexCount = FUN_00e60cb0(cinfo.m_ePrimitiveType, cinfo.m_iNumPrimitives);
    sectionOut.m_iIndexType = cinfo.m_iIndexType;
    sectionOut.m_hasIndices = cinfo.m_hasIndices;
    sectionOut.m_iSectionVertexCount = cinfo.m_iSectionVertexCount;
    sectionOut.m_pMeshVertexBuffer = (accessFlags & 2) ? cinfo.m_pMeshVertexBuffer : 0;
    sectionOut.m_ppIndices = 0;
    if ((accessFlags & 1) && cinfo.m_hasIndices)
        sectionOut.m_ppIndices = cinfo.m_ppIndices;
    sectionOut.m_iMaterialIndex = cinfo.m_iMaterialIndex;
    sectionOut.m_iVertexOffset = sectionIndex;
}

void __cdecl EnterTlsGuard() throw();
void __cdecl FUN_00c904e0() throw();

class hkBoolC
{
  public:
    hkBoolC() throw()
    {}
    hkBoolC(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
template <class ENUM, class STORAGE> class hkEnumC
{
  public:
    hkEnumC() throw()
    {}
    hkEnumC(ENUM e) throw()
    {
        m_kStorage = static_cast<STORAGE>(e);
    }
    STORAGE m_kStorage;
};
enum ConstraintPriority
{
    PRIORITY_INVALID,
    PRIORITY_PSI,
    PRIORITY_SIMPLIFIED_TOI_UNUSED,
    PRIORITY_TOI
};
enum OnDestructionRemapInfo
{
    ON_DESTRUCTION_REMAP = 0,
    ON_DESTRUCTION_REMOVE = 1,
    ON_DESTRUCTION_RESET_REMOVE = 2
};
class BaseObj
{
  public:
    BaseObj() throw()
    {}
    virtual ~BaseObj() throw();
};
class RefObject : public BaseObj
{
  public:
    RefObject() throw()
    {
        m_sReferenceCount = 1;
    }
    ~RefObject() throw();
    void FUN_00c90510() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class ConstraintEntity : public RefObject
{
};
class ConstraintData : public RefObject
{
};
class ConstraintOwner;
struct ConstraintModifier;
struct ConstraintInternal;
struct ConstraintListener;

struct ListenerArray
{
    ListenerArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}
    ConstraintListener** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

struct ConstraintName
{
    ConstraintName() throw();
    ~ConstraintName() throw();
    const char* m_pcText;
};

class FUN_00cf3ea0 : public RefObject
{
  public:
    FUN_00cf3ea0(ConstraintEntity* entityA, ConstraintEntity* entityB, ConstraintData* data,
                 ConstraintPriority priority) throw();
    virtual ~FUN_00cf3ea0() throw();

    ConstraintOwner* m_pOwnerObject;
    ConstraintData* m_data;
    ConstraintModifier* m_pConstraintModifier;
    ConstraintEntity* m_kActorEntries[2];
    hkEnumC<ConstraintPriority, unsigned char> m_priority;
    hkBoolC m_bWantRuntime;
    hkEnumC<OnDestructionRemapInfo, unsigned char> m_eDestructionRemapInfo;
    ListenerArray m_kListeners;
    ConstraintName m_name;
    unsigned int m_ulUserData;
    ConstraintInternal* m_pConstraintInternal;
    unsigned int m_uiUniqueId;
};

// Stores the entities, data, and priority, then increments references for entityA, nonnull entityB, and data.
// @fnv 0x00cf3ea0
FUN_00cf3ea0::FUN_00cf3ea0(ConstraintEntity* entityA, ConstraintEntity* entityB, ConstraintData* data,
                           ConstraintPriority priority) throw()
    : m_pOwnerObject(0), m_data(data), m_priority(priority), m_bWantRuntime(true),
      m_eDestructionRemapInfo(ON_DESTRUCTION_REMAP), m_ulUserData(0), m_pConstraintInternal(0), m_uiUniqueId(0xfffffff0)
{
    m_kActorEntries[0] = entityA;
    m_kActorEntries[1] = entityB;
    m_pConstraintModifier = 0;

    EnterTlsGuard();
    m_kActorEntries[0]->FUN_00c90510();
    if (m_kActorEntries[1])
    {
        m_kActorEntries[1]->FUN_00c90510();
    }
    m_data->FUN_00c90510();
    FUN_00c904e0();
}

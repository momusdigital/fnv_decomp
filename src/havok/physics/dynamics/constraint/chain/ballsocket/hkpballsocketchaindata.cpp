
// src/havok/physics/dynamics/constraint/chain/ballsocket/hkpballsocketchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/ballsocket/hkpballsocketchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBallSocketChainData.h"

struct S_00d53cf0
{
    int x, y;
};

struct hkpBallSocketChainData_00d53cf0
{
    int m_uiNumConstraints;
    void GetConstraintSizeInfo(bool a, S_00d53cf0* b);
};

// @fnv 0x00d53cf0
void hkpBallSocketChainData_00d53cf0::GetConstraintSizeInfo(bool abEnabled, S_00d53cf0* apSizeInfo)
{
    if (abEnabled)
    {
        apSizeInfo->y = 3 * *(int*)((char*)this + 0x1c);
        apSizeInfo->x = apSizeInfo->y * 8;
    }
    else
    {
        apSizeInfo->y = 0;
        apSizeInfo->x = 0;
    }
}

struct hkpBallSocketChainData_00d53ca0
{
    void InitChainData(char* out);
};
// Initializes the output chain data: stores a pointer to this+0xc, zeroes fields, and sets sizes from the count at this+0x1c.
// @fnv 0x00d53ca0
void hkpBallSocketChainData_00d53ca0::InitChainData(char* out)
{
    *(int*)(out + 0x10) = (int)(this + 0xc);
    int zero = 0;
    *(int*)(out + 8) = zero;
    *(int*)(out + 0xc) = zero;
    *(int*)out = zero;
    *(int*)(out + 4) = 0x10;
    *(int*)(out + 0x14) = 0xc;
    int iCount = *(int*)((char*)this + 0x1c);
    int iTripleCount = iCount * 3;
    *(int*)(out + 4) = (((iCount * 0x134 + 0x33) & 0xfffffff0) + 0x10);
    *(int*)(out + 8) = iTripleCount;
    *(int*)(out + 0xc) = iTripleCount;
}

// FUN_00d53c90 : a one-line function - getter
extern int g_target_00d53c90;
// @fnv 0x00d53c90
void* FUN_00d53c90()
{
    return &g_target_00d53c90;
}

class hkpConstraintDataD53E;

struct FUN_00d21ce0_cls
{
    hkUint16 m_type;
    hkUint16 m_pad02;
    void* m_pBridge;
    hkpConstraintDataD53E* m_pConstraintData;

    FUN_00d21ce0_cls()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* pvConstraintData) throw();
};

template <class T> class hkArrayD53E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD53E() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkReferencedObjectD53E
{
  public:
    hkReferencedObjectD53E()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD53E();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpConstraintDataD53E : public hkReferencedObjectD53E
{
  public:
    hkpConstraintDataD53E() : m_ulUserData(0)
    {}
    hkUlong m_ulUserData;
};

class FUN_00d53d90 : public hkpConstraintDataD53E
{
  public:
    FUN_00d21ce0_cls m_kBridgeAtom;
    hkArrayD53E<void*> m_entries;
    float m_fTau;
    float m_fMotorDamping;
    float m_epsilon;
    float m_maxRatio;

    FUN_00d53d90();
    virtual ~FUN_00d53d90();
};

// @fnv 0x00d53d90
FUN_00d53d90::FUN_00d53d90()
{
    m_fTau = 0.6f;
    m_fMotorDamping = 1.0f;
    m_epsilon = 1.1920929e-08f;
    m_maxRatio = 0.1f;
    m_kBridgeAtom.FUN_00d21ce0(this);
}

namespace fnv_00d53df0 {
struct hkFinishLoadedObjectFlagD53D
{
    int m_bFinishing;
};

class hkpConstraintDataD53D;

struct FUN_00d21ce0_cls
{
    hkUint16 m_type;
    hkUint16 m_pad02;
    void* m_pBridge;
    hkpConstraintDataD53D* m_pConstraintData;

    FUN_00d21ce0_cls(hkFinishLoadedObjectFlagD53D flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pConstraintData);
    }
    void FUN_00d21ce0(void* pvConstraintData) throw();
};

struct hkpBridgeAtomsD53D
{
    FUN_00d21ce0_cls m_kBridgeAtom;

    hkpBridgeAtomsD53D(hkFinishLoadedObjectFlagD53D flag) : m_kBridgeAtom(flag)
    {}
};

class hkReferencedObjectD53D
{
  public:
    hkReferencedObjectD53D(hkFinishLoadedObjectFlagD53D flag)
    {}
    virtual ~hkReferencedObjectD53D();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpConstraintDataD53D : public hkReferencedObjectD53D
{
  public:
    hkpConstraintDataD53D(hkFinishLoadedObjectFlagD53D flag) : hkReferencedObjectD53D(flag)
    {}
    hkUlong m_ulUserData;
};

class FUN_00d53df0 : public hkpConstraintDataD53D
{
  public:
    hkpBridgeAtomsD53D m_kBridgeAtoms;

    FUN_00d53df0(hkFinishLoadedObjectFlagD53D flag);
    virtual ~FUN_00d53df0();
};

// @fnv 0x00d53df0
FUN_00d53df0::FUN_00d53df0(hkFinishLoadedObjectFlagD53D flag) : hkpConstraintDataD53D(flag), m_kBridgeAtoms(flag)
{
    if (flag.m_bFinishing)
        m_kBridgeAtoms.m_kBridgeAtom.FUN_00d21ce0(this);
}
}  // namespace fnv_00d53df0

namespace fnv_00d53e30 {
class hkMemoryAllocatorD53E
{
  public:
    virtual ~hkMemoryAllocatorD53E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD53E
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD53E* m_pStreamAllocator;
    hkMemoryAllocatorD53E& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD53E& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayD53E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorD53E& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkEntryD53E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkBaseD53E
{
  public:
    virtual ~hkBaseD53E() throw()
    {}
};

class FUN_00d53e30 : public hkBaseD53E
{
  public:
    virtual ~FUN_00d53e30() throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkArrayD53E<hkEntryD53E> m_entries;
};

// Destructor that releases the m_entries array through the heap allocator.
// @fnv 0x00d53e30
FUN_00d53e30::~FUN_00d53e30() throw()
{
    m_entries.ClearAndRelease();
}
}  // namespace fnv_00d53e30

class hkMemoryAllocatorD541
{
  public:
    virtual ~hkMemoryAllocatorD541() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD541
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD541* m_pStreamAllocator;
    hkMemoryAllocatorD541& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD541& __cdecl FUN_00c85750();

class FUN_00d53e30
{
  public:
    virtual ~FUN_00d53e30() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d53e30*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d53e30* DestroyAndFree(unsigned int uiFlags) throw();
};

// Destructs the object and, when uiFlags has bit 0 set, frees its memory via operator delete, then returns this.
// @fnv 0x00d54150
FUN_00d53e30* FUN_00d53e30::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->FUN_00d53e30::~FUN_00d53e30();
    if (uiFlags & 1)
        FUN_00d53e30::operator delete(this);
    return this;
}

namespace fnv_00d549d0 {
struct MemManager
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void deallocateChunk(void* p, int nbytes);
};

struct ThreadContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemManager* memory;
};

void* FUN_00c85750();

struct Elem
{
    int a, b;
};

struct DummyClass
{
    int unk00;
    Elem* data1;
    int size1;
    int cap1;
    Elem* data2;
    int size2;
    int cap2;

    void ClearArrays();
};

// @fnv 0x00d549d0
void DummyClass::ClearArrays()
{
    ThreadContext* pThreadContext2 = (ThreadContext*)FUN_00c85750();
    MemManager& mem2 = *pThreadContext2->memory;
    int iCapacity2 = cap2;
    size2 = 0;
    if ((iCapacity2 & 0x80000000) == 0)
    {
        mem2.deallocateChunk(data2, (iCapacity2 & 0x3FFFFFFF) * 8);
    }
    data2 = 0;
    cap2 = 0x80000000;

    ThreadContext* pThreadContext1 = (ThreadContext*)FUN_00c85750();
    MemManager& mem1 = *pThreadContext1->memory;
    int iCapacity1 = cap1;
    size1 = 0;
    if ((iCapacity1 & 0x80000000) == 0)
    {
        mem1.deallocateChunk(data1, (iCapacity1 & 0x3FFFFFFF) * 8);
    }
    data1 = 0;
    cap1 = 0x80000000;
}
}  // namespace fnv_00d549d0

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct Router_00d53d30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

struct Pair_00d53d30
{
    __m128 a;
    __m128 b;
};

namespace fnvc_adapt {
Router_00d53d30* FUN_00c85750();
}
void ResizeAudioStream(void* alloc, void* arr, int elemSize);

struct Chain_00d53d30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkArray<Pair_00d53d30> m_aiIndexedValues;
    void Push(const __m128& a, const __m128& b);
};

// Appends a Pair_00d53d30 to m_aiIndexedValues, growing the array via ResizeAudioStream when capacity is exceeded.
// @fnv 0x00d53d30
void Chain_00d53d30::Push(const __m128& a, const __m128& b)
{
    hkArray<Pair_00d53d30>& arr = m_aiIndexedValues;
    Router_00d53d30* r = fnvc_adapt::FUN_00c85750();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(r->m_10, &arr, 0x20);
    Pair_00d53d30& e = arr.m_data[arr.m_iElementCount++];
    e.a = a;
    e.b = b;
}

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
struct hkpConstraintInstance;
struct hkpBallSocketChainDataConstraintInfo
{
    hkVector4 m_kPivotInA, m_kPivotInB;
};
struct ChainPlacement
{
};
inline void* operator new(unsigned int, ChainPlacement* pointer)
{
    return pointer;
}
template <class T> struct PortBodyArray
{
    T* m_data;
    int m_iElementCount, m_iCapacityState;
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline const T& operator[](int index) const
    {
        return m_data[index];
    }
};
template <class T> struct ChainValue
{
    T value;
    ChainValue()
    {}
    ChainValue(T x) : value(x)
    {}
    void operator=(T x)
    {
        value = x;
    }
    T val() const
    {
        return value;
    }
    operator T() const
    {
        return val();
    }
};
struct QueryResultSchema
{
    ChainValue<void*> m_pQueryResultSchema;
};
struct QuantizedBoundsData;
struct ChainStep
{
    __declspec(align(16)) ChainValue<float> unk00;
    ChainValue<float> unk04, m_kThirdChainValue, unk0c, unk10, unk14, unk18, unk1c, m_fThirdQueryValue,
        m_fFourthQueryValue, unk28;
};
struct ChainSimd
{
    __m128 value;
};
struct PortQuery : ChainStep
{
    __declspec(align(16)) ChainValue<const QuantizedBoundsData*> m_pBodyA;
    ChainValue<const QuantizedBoundsData*> m_pBodyB;
    ChainValue<const hkTransform*> m_kBodyALocalFrame, m_kBodyBLocalFrame;
    ChainValue<float> unk40, unk44;
    ChainSimd maximum;
    ChainValue<hkpConstraintInstance*> m_pConstraintChainInstance;
    ChainValue<void*> m_pByteBuffer;
    ChainValue<void*> unk68;
    ChainValue<unsigned int> unk6c, unk70;
    ChainValue<void*> unk74;
    PortQuery()
    {}
};

struct PortMemory
{
    virtual ~PortMemory();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
    template <class T> inline void _bufFree(void* pointer, int count)
    {
        ReturnMemory(pointer, count * sizeof(T));
    }
};
struct PortRouter
{
    int unk00, unk04, unk08, unk0c;
    PortMemory* m_pStreamAllocator;
    inline PortMemory& heap()
    {
        return *m_pStreamAllocator;
    }
};
inline PortRouter& chainRouter()
{
    return reinterpret_cast<PortRouter&>(FUN_00c85750());
}
extern "C" void ResizeAudioStream(PortMemory&, void*, int);
struct PortAllocator
{
    PortMemory& get(const void*)
    {
        return chainRouter().heap();
    }
};

struct PortArrayOps
{
    template <class T> static __forceinline void copyConstruct(T* dst, int count, const T& source)
    {
        for (int n = 0; n < count; ++n)
            ::new (reinterpret_cast<ChainPlacement*>(dst + n)) T(source);
    }
    template <class T> static __forceinline void destroy(T* data, int count)
    {
        for (int n = 0; n < count; ++n)
            data[n].~T();
    }
};
template <class T> struct PortArrayBase
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline PortArrayBase(T* data, int size, int cap)
        : m_data(data), m_iElementCount(size), m_iCapacityState(cap | 0x80000000)
    {}
    __forceinline ~PortArrayBase()
    {}
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void clear()
    {
        PortArrayOps::destroy(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void clearFree(PortMemory& memory)
    {
        clear();
        if (!(m_iCapacityState & 0x80000000))
            memory._bufFree<T>(m_data, capacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void append(PortMemory& memory, const T& item)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(memory, this, sizeof(T));
        PortArrayOps::copyConstruct(m_data + m_iElementCount, 1, item);
        ++m_iElementCount;
    }
    __forceinline void pushBackUnchecked(const T& item)
    {
        PortArrayOps::copyConstruct(m_data + m_iElementCount, 1, item);
        ++m_iElementCount;
    }
};
template <class T, class Allocator = PortAllocator> struct PortArray : PortArrayBase<T>
{
    __forceinline PortArray(T* data, int size, int cap) : PortArrayBase<T>(data, size, cap)
    {}
    __forceinline ~PortArray()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        PortArrayBase<T>::clearFree(Allocator().get(this));
    }
    __forceinline void AddBack(const T& item)
    {
        PortArrayBase<T>::append(Allocator().get(this), item);
    }
};
template <class T, unsigned N, class Allocator = PortAllocator> struct PortInplace : PortArray<T, Allocator>
{
    T m_kStorage[N];
    __forceinline PortInplace(int size = 0) : PortArray<T, Allocator>(m_kStorage, size, N)
    {}
};

struct PortMotion
{
    int unke0, unke4, unke8, unkec;
    hkTransform transform;
    inline const hkTransform& getTransform() const
    {
        return transform;
    }
};
struct PortEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0;
    int m_uiFilterInfo;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    PortMotion m_pMotionState;
    inline PortMotion* getMotion()
    {
        return &m_pMotionState;
    }
};
struct PortInstance
{
    int unk00, unk04, unk08, unk0c, unk10;
    PortEntity* m_actionOrEntity;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    PortBodyArray<PortEntity*> m_ppRigidBodies;
    inline PortEntity* getEntityA() const
    {
        return m_actionOrEntity;
    }
};

struct PortVector
{
    __m128 value;
    PortVector()
    {}
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& p)
    {
        __m128 v = *reinterpret_cast<const __m128*>(&p);
        __m128 c1 = *reinterpret_cast<const __m128*>(&t.m_rotation.m_kColumn1);
        __m128 c0 = *reinterpret_cast<const __m128*>(&t.m_rotation.m_kColumn0);
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0);
        y = _mm_add_ps(y, x);
        __m128 c2 = *reinterpret_cast<const __m128*>(&t.m_rotation.m_kColumn2);
        __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2);
        __m128 w = *reinterpret_cast<const __m128*>(&t.m_vTranslation);
        z = _mm_add_ps(z, w);
        value = _mm_add_ps(y, z);
    }
};

struct OffsetForChain
{
    int value;
    OffsetForChain()
    {}
    OffsetForChain(const QuantizedBoundsData* base, const QuantizedBoundsData* at)
        : value(int((const char*)at - (const char*)base))
    {}
};
extern "C"
{
    void AppendEventRecord(const PortQuery*, QueryResultSchema*, void*, int);
    char* FUN_00dd13c0(void*);
    void FUN_00dcee70(PortQuery*);
    void FUN_00dcfc00(const PortVector*, const PortVector*, float, PortQuery*, char*);
    void FUN_00dd0ad0(int, float, float, float, OffsetForChain*, const QuantizedBoundsData*, char*, const PortQuery*,
                      QueryResultSchema*);
}
struct ProbeRoot : public hkpBallSocketChainData
{
    void buildJacobian(const PortQuery&, QueryResultSchema&);
};
// Iterates a rigid-body constraint chain, computing transformed pivot positions and accumulating query results into the output schema.
// @fnv 0x00d53e80
void ProbeRoot::buildJacobian(const PortQuery& input, QueryResultSchema& output)
{
    void* solver = input.m_pByteBuffer.val();
    AppendEventRecord(&input, &output, solver, 8);
    PortQuery localQuery = input;
    localQuery.m_pConstraintChainInstance = 0;
    localQuery.m_pByteBuffer = 0;
    PortInplace<OffsetForChain, 32> offsets;
    PortInstance* instance = reinterpret_cast<PortInstance*>(input.m_pConstraintChainInstance.val());
    const QuantizedBoundsData* base = reinterpret_cast<const QuantizedBoundsData*>(
        reinterpret_cast<const char*>(input.m_pBodyA.val()) - instance->getEntityA()->m_uiFilterInfo);
    const PortBodyArray<PortEntity*>& bodies = instance->m_ppRigidBodies;
    int count = bodies.GetLogicalSize() - 1;
    PortEntity* body = bodies[0];
    PortMotion* motion = body->getMotion();
    localQuery.m_pBodyB =
        reinterpret_cast<const QuantizedBoundsData*>(reinterpret_cast<const char*>(base) + body->m_uiFilterInfo);
    offsets.pushBackUnchecked(OffsetForChain(base, localQuery.m_pBodyB));
    localQuery.m_kBodyBLocalFrame = &motion->getTransform();
    localQuery.m_fFourthQueryValue = 1.0f;
    localQuery.m_fThirdQueryValue = localQuery.m_kThirdChainValue;
    char* schema = FUN_00dd13c0(output.m_pQueryResultSchema);
    for (int index = 0; index < count; ++index)
    {
        localQuery.m_pBodyA = localQuery.m_pBodyB;
        localQuery.m_kBodyALocalFrame = localQuery.m_kBodyBLocalFrame;
        body = bodies[index + 1];
        motion = body->getMotion();
        localQuery.m_pBodyB =
            reinterpret_cast<const QuantizedBoundsData*>(reinterpret_cast<const char*>(base) + body->m_uiFilterInfo);
        offsets.AddBack(OffsetForChain(base, localQuery.m_pBodyB));
        localQuery.m_kBodyBLocalFrame = &motion->getTransform();
        PortVector a, b;
        a._setTransformedPos(*localQuery.m_kBodyALocalFrame, m_pConstraintInfo.m_data[index].m_kPivotInA);
        b._setTransformedPos(*localQuery.m_kBodyBLocalFrame, m_pConstraintInfo.m_data[index].m_kPivotInB);
        FUN_00dcee70(&localQuery);
        FUN_00dcfc00(&a, &b, m_fMaximumAngularImpulse, &localQuery, schema);
        schema += 0x90;
    }
    FUN_00dd0ad0(count, m_fTau, m_fMotorDamping, m_fMaxErrorDistance, offsets.begin(), base, schema, &input, &output);
}


// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMoppBvTreeShape.h"
struct FUN_00d54420_Interface
{
// @fnv 0x00d54420
    virtual ~FUN_00d54420_Interface()
    {}
    virtual void FUN_00d54420_f0() = 0;
    virtual void FUN_00d54420_f1() = 0;
    virtual void FUN_00d54420_f2() = 0;
    virtual void FUN_00d54420_f3() = 0;
    virtual void FUN_00d54420_f4() = 0;
    virtual void FUN_00d54420_f5(int, float, int) = 0;
    virtual void FUN_00d54420_f6(int, float, int) = 0;
};
struct FUN_00d54420_Owner
{
    virtual void FUN_00d54420_virtual() = 0;

    unsigned char padding[0x30];
    FUN_00d54420_Interface* m_pInterface;

    void FUN_00d54420(int, float, int);
};
void FUN_00d54420_Owner::FUN_00d54420(int a, float b, int c)
{
    m_pInterface->FUN_00d54420_f6(a, b, c);
}
struct hkReferencedObject
{
    void RetainReference();
};
extern int DAT_010c6fd0;
extern int DAT_010d0dac;
struct FUN_00d54490
{
    FUN_00d54490(int, int);
};
struct FUN_00d544f0 : public FUN_00d54490
{
    FUN_00d544f0(hkReferencedObject*, int);
};
struct FUN_00d54930MemoryManager
{
    virtual void ReportDiagnostic() = 0;
    virtual void unused1() = 0;
    virtual void Free(void* object, unsigned short size) = 0;
};
struct FUN_00d54930MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00d54930MemoryManager* manager;
};
FUN_00d54930MemoryRouter* _D1A0E0GetMemoryRouter();
struct FUN_00d54930Object
{
    virtual void ReportDiagnostic() = 0;

    unsigned short m_iElementCount;

    void FUN_00d543e0();
    FUN_00d54930Object* Destroy(unsigned char flags);
};
class hkClassD543;
extern const hkClassD543 DAT_01269c8c;
class hkStatisticsCollectorD543
{
  public:
    virtual ~hkStatisticsCollectorD543() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};
class hkpShapeD543
{
  public:
    void FUN_00c90360(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const throw();
};
class hkpSingleShapeContainerD543 : public hkpShapeD543
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const void* m_pMoppCode;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    const void* m_pContainedShape;

    void AddShapeChildrenToCollector(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const throw();
};
struct __declspec(align(16)) FUN_00dd1bf0_Obj
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
    int unk38;
    int unk3C;

    void __thiscall FUN_00dd1bf0(void* target, int a, int b, float c, int d);
};
struct FUN_00d54350_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;

    void __thiscall ForwardToTarget(int a, int b, float c, int d);
};
class hkMemoryAllocatorD548
{
  public:
    virtual ~hkMemoryAllocatorD548() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD548
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD548* m_pStreamAllocator;
    hkMemoryAllocatorD548& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD548& __cdecl FUN_00c85750();
struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
class hkReferencedObjectD548
{
  public:
    virtual ~hkReferencedObjectD548() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectD548*>(p)->m_usMemSizeAndFlags);
    }
};
class hkpShapeD548 : public hkReferencedObjectD548
{
  public:
    hkUlong m_ulUserData;
    hkUint32 m_type;
};
class hkpSingleChildShapeD548 : public hkpShapeD548
{
  public:
    int m_10;
    FUN_00d1df70* m_pContainedShape;

    virtual ~hkpSingleChildShapeD548() throw()
    {
        m_pContainedShape->removeReference();
    }
    hkpSingleChildShapeD548* FUN_00d548f0(unsigned int uiFlags) throw();
};
struct S00d54440_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    volatile unsigned char m_2C;
};
struct S00d54440_Vtable
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int, int);
};
struct S00d54440_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    S00d54440_Child* m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    S00d54440_Vtable* m_34;
    int m_38;

    int calcSizeForSpu(int, int);
};
#include <xmmintrin.h>
extern char DAT_010d0d70;
struct S00d54490_Ref
{
    void FUN_00c90510();
};
struct S00d54490_Obj
{
    void* volatile unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned short volatile unk06;
    int volatile unk08;
    int unk0C;
    volatile unsigned char unk10;
    void* unk14;
    int unk18;
    int unk1C;
    float unk20[4];
    S00d54490_Obj* __thiscall FUN_00d54490(int arg1, const hkpMoppBvTreeShape& arg2);
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const int DAT_010c92e0[4];
extern "C" const char str_010d0df0[];
extern "C" const char str_010c41f8[];
struct hkTimerCommandD546
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        m_uiStartTicks = uiTicks;
    }
};
struct hkMonitorStreamD546
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_capacityMinusReserve;
    static hkMonitorStreamD546& GetMonitorStream()
    {
        return *(hkMonitorStreamD546*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_capacityMinusReserve;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* p)
    {
        m_kRayEnd = p;
    }
};
__forceinline void timerD546(const char* pcCommand)
{
    hkMonitorStreamD546& kStream = hkMonitorStreamD546::GetMonitorStream();
    if (kStream.memoryAvailable())
    {
        hkTimerCommandD546* h = reinterpret_cast<hkTimerCommandD546*>(kStream.GetStreamEnd());
        h->m_pCommandName = pcCommand;
        h->setTime();
        kStream.setEnd((char*)(h + 1));
    }
}
struct __declspec(align(16)) hkVector4D546
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
};
struct hkVector4ComparisonD546
{
    union
    {
        __m128 m_uiMask;
        unsigned int m_int[4];
        float m_float[4];
    };
    int anyIsSet(int iMask) const
    {
        return _mm_movemask_ps(m_uiMask) & iMask;
    }
};
struct hkpShapeRayCastOutputD546
{
    hkVector4D546 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_18;
    int m_1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    const void* m_pRootCollidable;
    int m_48;
    int m_4c;

    void changeLevel(int iDelta)
    {
        m_uiShapeKeyIndex += iDelta;
    }
    void setKey(unsigned int uiKey)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = uiKey;
    }
};
struct hkpShapeRayBundleCastOutputD546
{

    hkpShapeRayCastOutputD546 m_akRayOutputs[4];
};
struct hkpShapeRayBundleCastInputD546;
struct hkpShapeContainerD546
{
    void* m_ppVirtualMethodTable;
};
struct hkpShapeD546
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};
struct hkpShapeCollectionD546 : public hkpShapeD546, public hkpShapeContainerD546
{
};
struct hkpMoppCodeD546
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_08;
    int m_0c;
    hkVector4D546 m_offset;
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned char m_eBuildType;
};
struct hkpMoppRayBundleVirtualMachineD546
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
    int m_a0, m_a4, m_a8, m_ac, m_b0, m_b4, m_b8, m_bc;
    int m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc;
    hkVector4ComparisonD546 FUN_00dd4870(const hkpShapeContainerD546* pkCollection, const hkpMoppCodeD546* pkCode,
                                         const hkpShapeRayBundleCastInputD546& kInput,
                                         hkpShapeRayBundleCastOutputD546& kResults,
                                         const hkVector4ComparisonD546& kRayMask) throw();
};
class hkpMoppBvTreeShapeD546
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
    int m_uiUserData;
    const hkpMoppCodeD546* m_pMoppCode;
    unsigned char* m_pMoppData;
    int m_uiMoppDataSize;
    hkVector4D546 m_kMoppCodeInfo;
    void* m_childVtable;
    const hkpShapeD546* m_pContainedShape;
    int m_iChildSize;
    int m_3c;

    hkVector4ComparisonD546 castRayBundleImpl(const hkpShapeRayBundleCastInputD546& kInput,
                                         hkpShapeRayBundleCastOutputD546& kResults,
                                         const hkVector4ComparisonD546& kRayMask) const throw();
};

struct hkVector4q
{
    __m128 m_vComponents;
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct hkMoppAllocQ : public hkMemoryAllocatorD548
{
    virtual void unused0C() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArr(T* buffer, int size, int capacity) : m_data(buffer), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _clearAndDeallocate(hkMemoryAllocatorD548& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            static_cast<hkMoppAllocQ&>(alloc).ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
    }
};

enum BuildKindQ
{
    kPlainQ = 2
};
template <class E, class S> struct SmallEnumQ
{
    S value;
    void operator=(E e)
    {
        value = (S)e;
    }
};
struct ByteViewQ
{
    const unsigned char* pointer;
    int size;
    int cap;
    void owned(const unsigned char* p, int n, int c)
    {
        pointer = p;
        size = n;
        cap = c;
    }
};

struct hkMoppCodeInfoQ
{
    hkVector4q m_offset;
};

struct __declspec(align(16)) hkpMoppCodeQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMoppCodeInfoQ m_info;
    const void* m_data;
    int m_iElementCount;
    int m_pRayCursor;
    unsigned char m_eBuildType;
    void init(const hkMoppCodeInfoQ& info, const void* data, int size)
    {
        m_info = info;
        m_data = data;
        m_iElementCount = size;
        m_pRayCursor = size;
        m_eBuildType = 2;
    }
};

struct hkMoppHitsQ
{
    hkArr<unsigned int>* m_kHits;
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

    void FUN_00dd1da0(const hkpMoppCodeQ* code, const hkAabbq* aabb, hkArr<unsigned int>* hits) throw();
};

extern double DAT_01091c00;

class hkMoppBvTreeShapeBaseQ : public hkMoppBvTreeShapeBase
{
  public:
    int queryAabbImpl(const hkAabbq& aabbIn, unsigned int* hits, int maxNumKeys) const;
};

// @fnv 0x00d54810
int hkMoppBvTreeShapeBaseQ::queryAabbImpl(const hkAabbq& aabbIn, unsigned int* hits, int maxNumKeys) const
{
    const hkVector4q& offset = reinterpret_cast<const hkVector4q&>(m_kMoppCodeInfo);

    hkAabbq aabb;
    int buffer[16];
    hkpMoppCodeQ* code = (hkpMoppCodeQ*)(((unsigned int)buffer + 15) & ~15u);
    code->init(reinterpret_cast<const hkMoppCodeInfoQ&>(offset), m_pMoppData, m_uiMoppDataSize);
    float extent = (float)(DAT_01091c00 / m_kMoppCodeInfo.w);
    aabb.m_kMinimumCorner.m_vComponents = _mm_max_ps(offset.m_vComponents, aabbIn.m_kMinimumCorner.m_vComponents);
    aabb.m_kMaximumCorner.m_vComponents =
        _mm_min_ps(_mm_add_ps(_mm_set_ps1(extent), offset.m_vComponents), aabbIn.m_kMaximumCorner.m_vComponents);
    hkArr<unsigned int> hitsArray(hits, 0, maxNumKeys);
    hkMoppHitsQ machine;
    machine.FUN_00dd1da0(code, &aabb, &hitsArray);
    int numHits = machine.m_kHits->m_iElementCount;
    hitsArray._clearAndDeallocate(FUN_00c85750().heap());
    return numHits;
}

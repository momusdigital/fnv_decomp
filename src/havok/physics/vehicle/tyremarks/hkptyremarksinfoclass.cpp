
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfoclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfoclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct ArrayMember
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~ArrayMember() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->bufFree(m_pData, (uCapacity & 0x3fffffff) * 0x20);
        m_pData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct SizedBase
{
    virtual void b00();

    unsigned short m_uSize;
    unsigned short m_u06;
    int m_i08;
    int m_i0c;

    virtual ~SizedBase() throw()
    {}
};

struct hkpTyremarksWheel : SizedBase
{
    ArrayMember m_kArray;

    hkpTyremarksWheel();

    // Empty virtual destructor; the m_kArray member's destructor then frees its array through the allocator.
// @fnv 0x00dfc2c0
// src: EXE 0x00dfc2c0
    virtual ~hkpTyremarksWheel() throw()
    {}

    static void operator delete(void* apMemory) throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(apMemory, ((hkpTyremarksWheel*)apMemory)->m_uSize);
    }
};

hkpTyremarksWheel::hkpTyremarksWheel()
{
    m_i08 = 0;
}

namespace fnv_00dfc330 {
struct hkpTyremarksInfo
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkpTyremarksInfo();
    virtual ~hkpTyremarksInfo();

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkpTyremarksInfo* b = static_cast<hkpTyremarksInfo*>(p);
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(p, b->m_usMemSizeAndFlags);
    }
};

// Empty default constructor of a class with size/flags and reference count fields.
// @fnv 0x00dfc330
// src: EXE 0x00dfc330
hkpTyremarksInfo::hkpTyremarksInfo()
{}
}  // namespace fnv_00dfc330

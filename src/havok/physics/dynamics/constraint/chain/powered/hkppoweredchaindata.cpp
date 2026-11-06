
// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPoweredChainData.h"

struct FUN_00e3b720_s
{
    int pad0[3];
    int m_iElementCount;  // +0xc
    int pad1[3];
    int m_uiItemCount;  // +0x1c
    void getConstraintInfo(int* info) const;
};

// @fnv 0x00e3b720
void FUN_00e3b720_s::getConstraintInfo(int* info) const
{
    info[4] = (int)&m_iElementCount;
    int zero = 0;
    info[2] = zero;
    info[3] = zero;
    info[0] = zero;
    info[1] = 0x10;
    info[5] = 0xc;
    int count = m_uiItemCount;
    int total = count * 3;
    int size = (count * 0x534 + 0x53) & 0xfffffff0;
    total = total * 2;
    size = size + 0x10;
    info[1] = size;
    info[2] = total;
    info[3] = total;
}

struct FUN_00e3b7d0_first
{
    int pad[7];
    int count;
};

struct FUN_00e3b7d0_second
{
    int pad[7];
    unsigned char* data;
};

struct FUN_00e3b7d0_object
{
    int pad0[3];
    FUN_00e3b7d0_first* first;
    int pad1[8];
    FUN_00e3b7d0_second* second;
};

// Clears a two-bit field at the given bit position in the byte at index within a 48-byte-strided block and sets it to 2.
// @fnv 0x00e3b7d0
void FUN_00e3b7d0(FUN_00e3b7d0_object* object, int index, int bit)
{
    int count = object->first->count;
    FUN_00e3b7d0_second* second = object->second;
    unsigned char* data = second->data;
    data += count * 48;

    unsigned char mask = static_cast<unsigned char>(3 << (bit * 2));
    unsigned char value = static_cast<unsigned char>(2 << (bit * 2));
    data[index] = static_cast<unsigned char>((data[index] & ~mask) | value);
}

// @fnv 0x00e3b670
int __cdecl FUN_00e3b670()
{
    return 102;
}

class hkRefObjE3B8
{
  public:
    virtual ~hkRefObjE3B8() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE3B8() throw()
    {
        m_sReferenceCount = 1;
    }
};

class hkBaseE3B8 : public hkRefObjE3B8
{
  public:
    void* m_pOwnerObject;
    hkBaseE3B8() throw() : m_pOwnerObject(0)
    {}
};

struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;

    FUN_00d21ce0_cls() throw()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* owner) throw();
};

template <typename T> struct hkArrayE3B8
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE3B8() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00e3b8f0 : public hkBaseE3B8
{
  public:
    FUN_00d21ce0_cls m_link;
    hkArrayE3B8<void*> m_items;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    float m_3c;

    FUN_00e3b8f0() throw();
    virtual ~FUN_00e3b8f0() throw();
};

// Initializes the float members to default values and calls m_link.FUN_00d21ce0 with this as owner.
// @fnv 0x00e3b8f0
FUN_00e3b8f0::FUN_00e3b8f0() throw()
{
    m_24 = 0.6f;
    m_28 = 1.0f;
    m_2c = 1.1920929e-08f;
    m_30 = 1.0f;
    m_34 = 1.1920929e-08f;
    m_38 = 1.0f;
    m_3c = 0.1f;
    m_link.FUN_00d21ce0(this);
}

namespace fnv_00e3b960 {
struct hkFinishFlagE3B9
{
    int m_bFinishing;
};

struct FUN_00d21ce0_cls
{
    int unk00;
    int unk04;
    void* m_08;
    void FUN_00d21ce0(void* p) throw();
};

struct hkMemberE3B9 : public FUN_00d21ce0_cls
{
    hkMemberE3B9(hkFinishFlagE3B9 flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_08);
    }
};

class hkRefObjE3B9
{
  public:
    virtual ~hkRefObjE3B9();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE3B9(hkFinishFlagE3B9 flag)
    {}
};

class FUN_00e3b960 : public hkRefObjE3B9
{
  public:
    int unk08;
    hkMemberE3B9 m_kMemberDescriptor;

    FUN_00e3b960(hkFinishFlagE3B9 flag);
    virtual ~FUN_00e3b960();
};

// @fnv 0x00e3b960
FUN_00e3b960::FUN_00e3b960(hkFinishFlagE3B9 flag) : hkRefObjE3B9(flag), m_kMemberDescriptor(flag)
{
    if (flag.m_bFinishing)
        m_kMemberDescriptor.FUN_00d21ce0(this);
}
}  // namespace fnv_00e3b960

class FUN_00e3b9a0
{
  public:
    ~FUN_00e3b9a0() throw();
};

class hkMemoryAllocatorXe3c210
{
  public:
    virtual ~hkMemoryAllocatorXe3c210() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXe3c210
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe3c210* m_pStreamAllocator;

    hkMemoryAllocatorXe3c210& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXe3c210& __cdecl FUN_00c85750() throw();

class hkObje3c210 : public FUN_00e3b9a0
{
  public:
    hkObje3c210* DestroyObject(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObje3c210*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Runs the base destructor, frees this via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00e3c210
hkObje3c210* hkObje3c210::DestroyObject(unsigned int uiFlags) throw()
{
    this->FUN_00e3b9a0::~FUN_00e3b9a0();
    if (uiFlags & 1)
        hkObje3c210::operator delete(this);
    return this;
}

struct S00e3b770_Result
{
    int offset;
    int stride;
};

struct S00e3b770_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iElementCount;

    void __thiscall getRuntimeInfo(int unused, S00e3b770_Result* result);
};

// @fnv 0x00e3b770
void __thiscall S00e3b770_Obj::getRuntimeInfo(int unused, S00e3b770_Result* result)
{
    int size = m_iElementCount;
    int stride = size * 6;

    result->stride = stride;

    stride += size * 2;
    int aligned = (size + 3) & ~3;
    result->offset = aligned + stride * 8;
}

#include <xmmintrin.h>
struct Motor
{
    void FUN_00c90510();
};
struct ConstraintInfo
{
    __m128 frameA;
    __m128 frameB;
    __m128 frameC;
    __m128 frameD;
    Motor* motorA;
    Motor* motorB;
    Motor* motorC;
    bool enabled;
};
struct InfoArray
{
    ConstraintInfo* data;
    int size;
    unsigned int capacityAndFlags;
};
struct MemoryRouter
{
    int unk00, unk04, unk08, unk0c;
    void* allocator;
};
extern void __cdecl ResizeAudioStream(void* allocator, InfoArray* array, int elementSize);
extern const __m128 DAT_012683b0;
struct PoweredChainData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    InfoArray infos;
    MemoryRouter* FUN_00c85750();
    void FUN_00e3b850(const __m128* a, const __m128* b, const __m128* c, Motor* motorA, Motor* motorB, Motor* motorC);
};
// Appends a ConstraintInfo entry to infos, storing frames a, b, c, motor pointers, and calling FUN_00c90510 on each motor.
// @fnv 0x00e3b850
void PoweredChainData::FUN_00e3b850(const __m128* apFrameA, const __m128* apFrameB, const __m128* apFrameC,
                                    Motor* motorA, Motor* motorB, Motor* motorC)
{
    InfoArray* array = &infos;
    MemoryRouter* router = FUN_00c85750();
    if (array->size == (int)(array->capacityAndFlags & 0x3fffffff))
        ResizeAudioStream(router->allocator, array, sizeof(ConstraintInfo));
    ConstraintInfo& info = array->data[array->size++];
    info.frameA = *apFrameA;
    info.frameB = *apFrameB;
    info.frameC = *apFrameC;
    info.motorA = motorA;
    motorA->FUN_00c90510();
    info.motorB = motorB;
    motorB->FUN_00c90510();
    info.motorC = motorC;
    motorC->FUN_00c90510();
    info.enabled = false;
    info.frameD = DAT_012683b0;
}

struct S00e3b810_Out
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_v;
};

struct S00e3b810_Src
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_kPointA;
    float m_kPointB;
};

struct S00e3b810_Dst
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float m_h;
};

// @fnv 0x00e3b810
static __declspec(noinline) void FUN_00e3b810(const S00e3b810_Src* src, S00e3b810_Dst* d, S00e3b810_Out* out,
                                              const float* s)
{
    out->m_uiX = src->m_uiZ * s[1];
    out->m_uiY = src->m_w * s[1];
    out->m_uiZ = src->m_uiY;
    out->m_w = src->m_kPointA;
    out->m_v = src->m_kPointB;
    d->m_h = s[2] * src->m_uiX;
}

S00e3b810_Out* volatile g_S00e3b810_out;
const float* volatile g_S00e3b810_s;
const S00e3b810_Src* volatile g_S00e3b810_src;
S00e3b810_Dst* volatile g_S00e3b810_d;

void S00e3b810_Caller()
{
    FUN_00e3b810(g_S00e3b810_src, g_S00e3b810_d, g_S00e3b810_out, g_S00e3b810_s);
}

namespace fnv_00e3b9a0 {
class hkMemoryAllocatorE3B9
{
  public:
    virtual ~hkMemoryAllocatorE3B9() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3B9
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE3B9* m_pStreamAllocator;

    hkMemoryAllocatorE3B9& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterE3B9& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayE3B9
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayE3B9() throw()
    {
        hkMemoryAllocatorE3B9& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkE3B9 {
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

namespace hkE3B9 {
struct hkVector4E3B9
{
    float x, y, z, w;
};

struct EntryE3B9
{
    hkVector4E3B9 unk00, unk10, unk20, unk30;
    hkReferencedObject* m_apkObjects[3];
    int unk4C;
};
}

namespace FUN_00e3b9a0 {
class hkpPoweredChainData : public hkE3B9::hkReferencedObject
{
  public:
    virtual ~hkpPoweredChainData();

    int unk08, unk0C, unk10, unk14;
    hkArrayE3B9<hkE3B9::EntryE3B9> m_kEntries;
};

// For each entry in m_kEntries, calls FUN_00c905b0 on each non-null object among its three object pointers.
// @fnv 0x00e3b9a0
hkpPoweredChainData::~hkpPoweredChainData()
{
    for (int i = 0; i < m_kEntries.m_iElementCount; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_kEntries.m_data[i].m_apkObjects[j])
                m_kEntries.m_data[i].m_apkObjects[j]->FUN_00c905b0();
        }
    }
}
}
}  // namespace fnv_00e3b9a0

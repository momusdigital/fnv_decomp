
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivity.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivity.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexVerticesConnectivity.h"

// clear  (hkpConvexVerticesConnectivity, vftable slot 2)
//
//   xor eax, eax
//   mov dword ptr [ecx + 0x0c], eax
//   mov dword ptr [ecx + 0x18], eax
//   ret
//
// The two cleared words are the *size* fields of the two hkArray members:
//   hkArray<hkUint16> m_kVertexIndices;      -> data +0x08, size +0x0c, capacity +0x10
//   hkArray<hkUint8>  m_kNumVerticesPerFace;  -> data +0x14, size +0x18, capacity +0x1c
// The stand-in derives from the pack's class so that `this` has exactly the
// real layout (the pack asserts sizeof(hkpConvexVerticesConnectivity) == 0x20).
struct hkpCVCStandIn : public hkpConvexVerticesConnectivity
{
    void clear();
};

// @fnv 0x00e48de0
void hkpCVCStandIn::clear()
{
    m_kVertexIndices.m_iElementCount = 0;
    m_kNumVerticesPerFace.m_iElementCount = 0;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Mem_e48d
{
    virtual void v00();
};
struct Router_e48d
{
    int unk00, unk04, unk08, unk0C;
    Mem_e48d* m_pStreamAllocator;
};
Router_e48d* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(Mem_e48d* mem, void* array, int sizeOfElement);

template <class T> struct hkArray_e48d
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        Router_e48d* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

struct Writer_e48d
{
    int unk00, unk04;
    hkArray_e48d<unsigned short> m_ppIndices;
    hkArray_e48d<unsigned char> m_counts;
    void FUN_00e48df0(const int* values, int count);
};

// Stores the element count and each index value into the m_counts and m_ppIndices arrays.
// @fnv 0x00e48df0
void Writer_e48d::FUN_00e48df0(const int* values, int count)
{
    m_counts.AddBack((unsigned char)count);
    for (int i = 0; i < count; i++)
        m_ppIndices.AddBack((unsigned short)values[i]);
}


// src/havok/common/base/system/io/writer/array/hkarraystreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/array/hkarraystreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkArrayStreamWriter.h"

struct FUN_00d467c0
{
    void write(const char* a, unsigned int b);
};
struct FUN_00d468a0_obj
{
    unsigned int pad[2];
    FUN_00d467c0* p;
    unsigned int WriteToStream(unsigned int arg, unsigned int b);
};
// @fnv 0x00d468a0
unsigned int FUN_00d468a0_obj::WriteToStream(unsigned int apData, unsigned int auiSize)
{
    p->write((const char*)apData, auiSize);
    return auiSize;
}

struct FUN_00d469c0
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00d469c0(int v);
};
// @fnv 0x00d469c0
FUN_00d469c0::FUN_00d469c0(int v)
{
    m2 = 0;
    m3 = 0;
    m4 = 0x80000000;
    m1 = v;
    m0 = v;
}

struct FUN_00d46b20_inner
{
    void Run();
};

struct FUN_00d46b20_cls
{
    int unk00;
    int unk04;
    FUN_00d46b20_inner* m_08;
    void FUN_00d46b20();
};

// @fnv 0x00d46b20
void FUN_00d46b20_cls::FUN_00d46b20()
{
    m_08->Run();
}

struct FUN_00d46c80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;

    void FUN_00d46c80(int aiDelta);
};

// @fnv 0x00d46c80
void FUN_00d46c80_cls::FUN_00d46c80(int aiDelta)
{
    m_0c += aiDelta;
}

extern int DAT_010cf734;
struct FUN_00d466e0
{
    void* unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00d466e0(int a, int b);
};
// Initializes the object: sets unk06 to 1, points unk00 at DAT_010cf734, stores b in unk10 and a in unk08, and clears unk0C.
// @fnv 0x00d466e0
FUN_00d466e0::FUN_00d466e0(int a, int b)
{
    unk06 = 1;
    unk00 = &DAT_010cf734;
    unk10 = b;
    unk08 = a;
    unk0C = 0;
}

struct FNVBuffer
{
    void* data;
    unsigned int used;
    unsigned int capacityAndFlags;
};
struct FNVWriter
{
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(int operation, const void* globalData, void* bytes, unsigned int count, unsigned int limit);
    int unk04;
    int unk08;
    int unk0c;
    unsigned char allowRestricted;
};
extern int DAT_010cc460;
extern unsigned int __cdecl FUN_00d06f80(void*, unsigned int);
struct FUN_00d46770_cls
{
    int unk00;
    int unk04;
    FNVBuffer* buffer;
    void WriteBufferToWriter(FNVWriter* writer, int unused);
};
// If buffer is set and either unrestricted or the writer allows restricted data, passes its data, used size and computed limit to writer->method14.
// @fnv 0x00d46770
void FUN_00d46770_cls::WriteBufferToWriter(FNVWriter* writer, int unused)
{
    FNVBuffer* b = buffer;
    if (b != 0)
    {
        unsigned int flags = b->capacityAndFlags;
        if ((flags & 0x80000000u) == 0 || writer->allowRestricted)
        {
            void* data = b->data;
            unsigned int limit = FUN_00d06f80(data, flags & 0x3fffffff);
            writer->method14(3, &DAT_010cc460, b->data, b->used, limit);
        }
    }
}

class hkMemoryAllocatorD469
{
  public:
    virtual ~hkMemoryAllocatorD469() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD469
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD469* m_pStreamAllocator;
    hkMemoryAllocatorD469& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD469 {
extern "C" hkMemoryRouterD469& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayD469
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorD469& kAlloc = hkRouterD469::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

inline void hkDeallocateChunkD469(void* p, int iNumBytes)
{
    hkRouterD469::FUN_00c85750().heap().ReleaseBlock(p, iNumBytes);
}

class hkBlockPoolD469
{
  public:
    int m_iDofCount;
    int m_pTileTemplate;
    hkArrayD469<void*> m_kBlocks;

    void FreeAllChunks();
};

// @fnv 0x00d469e0
void hkBlockPoolD469::FreeAllChunks()
{
    for (int i = 0; i < m_kBlocks.m_iElementCount; i++)
        hkDeallocateChunkD469(m_kBlocks.m_data[i], m_iDofCount);
    m_kBlocks.ClearAndRelease();
    m_pTileTemplate = m_iDofCount;
}

struct FUN_00d469e0_Obj
{
    void FreeAllChunks();
};
struct FUN_00d46be0_Inner
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4(int a, int b);
};
struct FUN_00d46be0_Res
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d46be0_Inner* inner;
};
void* __cdecl FUN_00c85750();
struct FUN_00d46be0_Cls
{
    int m00;
    int m04;
    int* m08;
    int m0c;
    int m10;
    void FUN_00d46be0();
};
// @fnv 0x00d46be0
void FUN_00d46be0_Cls::FUN_00d46be0()
{
    reinterpret_cast<FUN_00d469e0_Obj*>(this)->FreeAllChunks();
    FUN_00d46be0_Res* res = reinterpret_cast<FUN_00d46be0_Res*>(FUN_00c85750());
    FUN_00d46be0_Inner* pInner = res->inner;
    int v = m10;
    m0c = 0;
    if (v & 0x80000000)
        goto done;
    pInner->s4(reinterpret_cast<int>(m08), (v & 0x3fffffff) * 4);
done:
    m08 = 0;
    m10 = 0x80000000;
}

class hkMemoryAllocatorD46C
{
  public:
    virtual ~hkMemoryAllocatorD46C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD46C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD46C* m_pStreamAllocator;
    hkMemoryAllocatorD46C& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD46C {
extern "C" hkMemoryRouterD46C& __cdecl FUN_00c85750();
}

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void FUN_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        FUN_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        hkRouterD46C::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d46be0_class));
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectD46C
{
  public:
    virtual ~hkReferencedObjectD46C() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterD46C::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectD46C*>(p)->m_usMemSizeAndFlags);
    }
};

class FUN_00d46c30 : public hkReferencedObjectD46C
{
  public:
    FUN_00d46be0_class* m_stream;
    int m_0c;
    int m_ownership;

    virtual ~FUN_00d46c30() throw();
};

// Destructor that deletes m_stream when m_ownership equals 1.
// @fnv 0x00d46c30
FUN_00d46c30::~FUN_00d46c30() throw()
{
    if (m_ownership == 1)
        delete m_stream;
}

struct State
{
    bool status;
    State()
    {}
};
struct Counters
{
    int step;
    int base;
    int misc;
    int length;
};
struct FUN_00d46ca0_Class
{
    int unk00, unk04;
    Counters* counters;
    int position;
    State isOk();
};
// @fnv 0x00d46ca0
State FUN_00d46ca0_Class::isOk()
{
    State result;
    result.status = position <= (counters->length - 1) * counters->step + counters->base;
    return result;
}

namespace fnv_00d46cc0 {
struct FnvCpu_FUN_00d46cc0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d46cc0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d46cc0_CpuAllocator* allocator;
};
FnvCpu_FUN_00d46cc0_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d46cc0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d46c30();
    FnvCpu_FUN_00d46cc0_CpuObject* Destroy(unsigned int flags);
};
// @fnv 0x00d46cc0
FnvCpu_FUN_00d46cc0_CpuObject* FnvCpu_FUN_00d46cc0_CpuObject::Destroy(unsigned int flags)
{
    FUN_00d46c30();
    if (flags & 1)
    {
        FnvCpu_FUN_00d46cc0_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d46cc0

void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

class hkBlockStreamD466
{
  public:
    int m_iDofCount;
    int m_iLastBlockSize;
    char** m_kBlocks;
    int m_iBlockCount;

    void Read(void* buf, int nbytes, int offset);
};

// Copies nbytes from the block stream into buf, starting at byte offset, spanning blocks as needed.
// @fnv 0x00d46660
void hkBlockStreamD466::Read(void* apDest, int aiByteCount, int offset)
{
    int block = offset / m_iDofCount;
    int blockOffset = offset - block * m_iDofCount;
    while (aiByteCount > 0)
    {
        int size = (block < m_iBlockCount - 1) ? m_iDofCount : m_iLastBlockSize;
        char* src = m_kBlocks[block] + blockOffset;
        int avail = size - blockOffset;
        if (aiByteCount <= avail)
        {
            FUN_00cb1260(apDest, src, aiByteCount);
            return;
        }
        FUN_00cb1260(apDest, src, avail);
        apDest = (char*)apDest + avail;
        aiByteCount -= avail;
        block++;
        blockOffset = 0;
    }
}

class hkBoolD467
{
  public:
    hkBoolD467(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkBufferD467
{
  public:
    int m_iFirstIndex;
    int m_last;
    int unk08;
    int m_iCapacity;

    void Read(void* dst, int n, int offset) throw();
};

class hkStreamD467
{
  public:
    virtual ~hkStreamD467();
    virtual int read(void* dst, int n);
    virtual int skip(int n);
    virtual hkBoolD467 IsStreamValid();

    int unk04;
    hkBufferD467* m_buffer;
    int m_offset;

    int FUN_00d46710(void* dst, int n);
};

// Reads up to n bytes from the stream buffer into dst, advancing m_offset, and returns the number of bytes actually read.
// @fnv 0x00d46710
int hkStreamD467::FUN_00d46710(void* apBuffer, int aiCount)
{
    if (IsStreamValid())
    {
        int avail = (m_buffer->m_iCapacity - 1) * m_buffer->m_iFirstIndex + m_buffer->m_last - m_offset;
        int k = aiCount < avail ? aiCount : avail;
        m_buffer->Read(apBuffer, k, m_offset);
        m_offset += aiCount;
        return k;
    }
    return 0;
}

namespace fnv_00d468c0 {
class hkMemoryAllocatorD468;

struct hkMemoryRouterD468
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD468* m_pTemp;
    hkMemoryAllocatorD468* m_pStreamAllocator;
    hkMemoryAllocatorD468& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD468& __cdecl FUN_00c85750() throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD468& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T> class hkArrayD468
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD468& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        reserve(FUN_00c85750().heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkBufWriterD468
{
  public:
    int unk00;
    int unk04;
    hkArrayD468<char>* m_buf;
    int m_pos;

    void Reset();
};

// Resets the buffer writer by clearing the size and position, reserving one byte, and null-terminating the buffer.
// @fnv 0x00d468c0
void hkBufWriterD468::Reset()
{
    m_buf->m_iElementCount = 0;
    m_pos = 0;
    m_buf->reserve(m_buf->m_iElementCount + 1);
    m_buf->m_data[m_buf->m_iElementCount] = 0;
}
}  // namespace fnv_00d468c0

class hkMemoryAllocatorD46B;

struct hkMemoryRouterD46B
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD46B* m_pStreamAllocator;
    hkMemoryAllocatorD46B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterD46B& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD46B& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
extern "C" void* __cdecl fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiSize) throw();

class hkArrayD46B
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD46B& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(char));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const char& fill)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
        char* pDst = m_data + m_iElementCount;
        int iEntryIndex = n - m_iElementCount;
        if (iEntryIndex <= 0)
        {
            m_iElementCount = n;
            return;
        }
        fnv_zlib_memset(pDst, fill, iEntryIndex);
        m_iElementCount = n;
    }
    void popBack()
    {
        m_iElementCount--;
    }
};

class hkArrayStreamWriterD46B
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    hkArrayD46B* m_aiIndexedValues;
    int m_offset;

    int Seek(int iRelOffset, int eWhence);
};

// Seeks m_offset to iRelOffset relative to eWhence, growing m_aiIndexedValues if needed, and returns 1 on negative offset.
// @fnv 0x00d46b30
int hkArrayStreamWriterD46B::Seek(int iRelOffset, int eWhence)
{
    int iAbsOffset = m_offset;
    switch (eWhence)
    {
    case 0:
        iAbsOffset = iRelOffset;
        break;
    case 1:
        iAbsOffset = m_offset + iRelOffset;
        break;
    case 2:
        iAbsOffset = m_aiIndexedValues->GetLogicalSize() - iRelOffset;
        break;
    }
    if (iAbsOffset >= 0)
    {
        if (iAbsOffset > m_aiIndexedValues->GetLogicalSize())
        {
            m_aiIndexedValues->SetSizeAndGrow(iAbsOffset + 1, 0);
            m_aiIndexedValues->m_iElementCount = iAbsOffset;
        }
        m_offset = iAbsOffset;
        return 0;
    }
    return 1;
}

struct Alloc_d467
{
    virtual void vf00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct Router_d467
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Alloc_d467* m_pStreamAllocator;

    Alloc_d467& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct BlockArray_d467
{
    const char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class Stream_d467
{
  public:
    int m_iDofCount;
    int m_offset;
    BlockArray_d467 m_kBlocks;

    void FUN_00d467c0(const char* pcData, int iSize);
};

void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl FUN_00cb1260(void* dst, const void* src, int count);

// Copies iSize bytes from pcData into the stream's block array, allocating new blocks from the heap when the current block is full.
// @fnv 0x00d467c0
void Stream_d467::FUN_00d467c0(const char* pcData, int iSize)
{
    int blockIndex = m_kBlocks.m_iElementCount - 1;

    if (iSize > 0)
    {
        BlockArray_d467* blocks = &m_kBlocks;
        do
        {
            int blockSize = m_iDofCount;
            int available = blockSize - m_offset;

            if (available == 0)
            {
                Alloc_d467& heap = ((Router_d467*)FUN_00c85750())->heap();
                char* block = (char*)heap.AllocateMemoryBlock(blockSize);

                Router_d467* router = (Router_d467*)FUN_00c85750();
                if (blocks->m_iElementCount == (blocks->m_iCapacityState & 0x3fffffff))
                {
                    ResizeAudioStream(router->m_pStreamAllocator, blocks, 4);
                }

                const char** pSlot = &blocks->m_data[blocks->m_iElementCount];
                pSlot[0] = block;
                pSlot[0] = block;
                blocks->m_iElementCount++;
                blockIndex++;
                m_offset = 0;
                available = m_iDofCount;
            }

            char* destination = (char*)m_kBlocks.m_data[blockIndex] + m_offset;

            if (iSize > available)
            {
                FUN_00cb1260(destination, pcData, available);
                pcData += available;
                iSize -= available;
                m_offset = m_iDofCount;
            }
            else
            {
                FUN_00cb1260(destination, pcData, iSize);
                m_offset += iSize;
                return;
            }
        } while (iSize > 0);
    }
}

void __cdecl FUN_00c908c0(hkMemoryAllocatorD469* heap, void* array, int numElements, int sizeOfElement);
void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

template <class T> struct hkArray_d469
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void reserve(int n)
    {
        hkMemoryAllocatorD469& heap = hkRouterD469::FUN_00c85750().heap();
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
};

struct hkArrayStreamWriter_d469
{
    int* m_vtbl;
    int m_memSizeAndRefCount;
    hkArray_d469<char>* m_aiIndexedValues;
    int m_offset;
    int FUN_00d46920(const void* mem, int size);
};

// Copies size bytes from mem into the indexed values array at m_offset, growing the array if needed, then advances m_offset and returns size.
// @fnv 0x00d46920
int hkArrayStreamWriter_d469::FUN_00d46920(const void* mem, int size)
{
    int spaceLeft = m_aiIndexedValues->GetLogicalSize() - m_offset;
    if (size > spaceLeft)
    {
        int newSize = m_aiIndexedValues->GetLogicalSize() - spaceLeft + size;
        m_aiIndexedValues->reserve(newSize + 1);
        m_aiIndexedValues->m_iElementCount = newSize;
        (*m_aiIndexedValues)[newSize] = 0;
    }
    else if (m_aiIndexedValues->getCapacity() > m_aiIndexedValues->GetLogicalSize())
    {
        (*m_aiIndexedValues)[m_aiIndexedValues->GetLogicalSize()] = 0;
    }
    FUN_00cb1260(m_aiIndexedValues->m_data + m_offset, mem, size);
    m_offset += size;
    return size;
}

namespace fnv_00d46a50 {
struct V46a50Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, int n);
    virtual void v0c();
    virtual void ReturnMemory(void* p, int size);
};
struct V46a50Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    V46a50Alloc* m_alloc;
    V46a50Alloc& heap()
    {
        return *m_alloc;
    }
};
V46a50Router* __cdecl FUN_00c85750();

struct V46a50Elem
{
};
struct V46a50Owner
{
    void doElem(V46a50Elem* e, int n);
    void FUN_00d46a50(struct V46a50List* l);
};
struct V46a50List
{
    int m0;
    int m4;
    V46a50Elem** m_data;
    int m_iElementCount;
    int m_capFlags;
    void FreeAllChunks();
};

// Processes each stored element with doElem and heap v08, then releases the array buffer and resets the list.
// @fnv 0x00d46a50
void V46a50Owner::FUN_00d46a50(V46a50List* apList)
{
    int n = apList->m_iElementCount;
    for (int i = 0; i < n - 1; i++)
    {
        V46a50Elem* e = apList->m_data[i];
        doElem(e, apList->m0);
        int k = apList->m0;
        FUN_00c85750()->heap().v08(e, k);
    }
    if (n != 0)
    {
        V46a50Elem* e = apList->m_data[n - 1];
        doElem(e, apList->m4);
        int k = apList->m0;
        FUN_00c85750()->heap().v08(e, k);
    }
    V46a50Alloc& a = FUN_00c85750()->heap();
    apList->m_iElementCount = 0;
    if ((apList->m_capFlags & 0x80000000) == 0)
        a.ReturnMemory(apList->m_data, (apList->m_capFlags & 0x3fffffff) * sizeof(V46a50Elem*));
    apList->m_data = 0;
    apList->m_capFlags = 0x80000000;
    apList->FreeAllChunks();
}
}  // namespace fnv_00d46a50

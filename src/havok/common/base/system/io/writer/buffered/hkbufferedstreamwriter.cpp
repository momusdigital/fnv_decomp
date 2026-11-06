
// src/havok/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkBufferedStreamWriter.h"

struct FUN_00d27260_standin
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    char* m_buffer;
    int m_vContactPosition;
    int m_kRayEnd;

    int FlushToDestination();
    int write(const void* data, int size);
};

void _FUN_00cb1260(void* destination, const void* source, unsigned int size);

// @fnv 0x00d27260
int __thiscall FUN_00d27260_standin::write(const void* data, int size)
{
    int remaining = size;
    const char* bytes = static_cast<const char*>(data);
    int available = m_kRayEnd - m_vContactPosition;

    while (remaining > available)
    {
        _FUN_00cb1260(m_buffer + m_vContactPosition, bytes, available);
        m_vContactPosition += available;

        int position = m_vContactPosition;
        bytes += available;
        remaining -= available;

        if (FlushToDestination() != position)
            return size - remaining;

        available = m_kRayEnd - m_vContactPosition;
    }

    _FUN_00cb1260(m_buffer + m_vContactPosition, bytes, remaining);
    m_vContactPosition += remaining;
    return size;
}

struct FUN_00d27420_class
{
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3(const char*, void*, int) = 0;
    virtual void m4() = 0;
    virtual void m5(int, const char*, void*, void*, int) = 0;

    void WriteToStream(FUN_00d27420_class*, int);
};

// Writes the Buffer and stream members to the given stream via its virtual methods.
// @fnv 0x00d27420
void FUN_00d27420_class::WriteToStream(FUN_00d27420_class* stream, int)
{
    stream->m5(1, "Buffer", *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x0c),
               *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x14), 0);

    stream->m3("stream", *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08), 0);
}

struct DDCC60World
{
    void removeReference();
};

void __cdecl flush();
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl FUN_00c85660(void*, void*);

extern int DAT_010ce448;
extern int _DAT_0102e388;

struct FUN_00d27520
{
    void* m_vtbl;           // +0x00
    int m_04;               // +0x04
    DDCC60World* m_pWorld;  // +0x08
    void* m_pData;          // +0x0c
    int m_10;               // +0x10
    int m_14;               // +0x14
    char m_18;              // +0x18

    ~FUN_00d27520();
};

// @fnv 0x00d27520
FUN_00d27520::~FUN_00d27520()
{
    m_vtbl = &DAT_010ce448;
    flush();
    if (m_pWorld)
        m_pWorld->removeReference();
    if (m_18)
    {
        void* pData = m_pData;
        void* router = _D1A0E0GetMemoryRouter();
        FUN_00c85660(*(void**)((char*)router + 0x10), pData);
    }
    m_vtbl = &_DAT_0102e388;
}

namespace fnv_00d27570 {
struct FUN_00d27570Router
{
    virtual void method0();
    virtual void method1();
    virtual void deallocate(void* object, unsigned short id);
};

struct FUN_00d27570MemoryRouter
{
    void* reserved[4];
    FUN_00d27570Router* router;
};

FUN_00d27570MemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00d27570Writer
{
    void* vftable;
    unsigned short id;

    void FUN_00d27520();
    void* DestroyWriter(unsigned char deletingFlag);
};

// Calls FUN_00d27520, then if deletingFlag has bit 0 set, deallocates this through the memory router using id, and returns this.
// @fnv 0x00d27570
void* FUN_00d27570Writer::DestroyWriter(unsigned char deletingFlag)
{
    FUN_00d27520();

    if (deletingFlag & 1)
    {
        FUN_00d27570MemoryRouter* memoryRouter = _D1A0E0GetMemoryRouter();
        memoryRouter->router->deallocate(this, id);
    }

    return this;
}
}  // namespace fnv_00d27570

extern int DAT_012689e4;

// @fnv 0x00d27560
void* __cdecl FUN_00d27560()
{
    return &DAT_012689e4;
}

struct BufferedStreamDestination
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual int Write(const void* source, int bytes);
};
struct StreamBufferD27210
{
    void* unk00;
    void* unk04;
    BufferedStreamDestination* m_destination;
    char* m_buffer;
    int m_vContactPosition;
    int m_kRayEnd;
    int FlushToDestination();
};
// @fnv 0x00d27210
int StreamBufferD27210::FlushToDestination()
{
    if (m_destination != 0)
    {
        int written = 0;
        int remaining = m_vContactPosition;
        while (written < remaining)
        {
            int count = m_destination->Write(m_buffer + written, remaining - written);
            written += count;
            if (count == 0)
                return written;
        }
        m_vContactPosition = 0;
        return written;
    }
    return 0;
}

struct FUN_00d272e0_target
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
};

struct FUN_00d272e0_class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}

    int unk04;
    FUN_00d272e0_target* unk08;

    void flush();
};

// @fnv 0x00d272e0
void FUN_00d272e0_class::flush()
{
    reinterpret_cast<FUN_00d27260_standin*>(this)->FlushToDestination();

    if (unk08 != 0)
    {
        return unk08->vf14();
    }
}

struct hkBoolD273
{
    char m_cBooleanValue;
    hkBoolD273(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

class hkSourceD273
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual hkBoolD273 IsStreamValid();
};

class hkObjD273
{
  public:
    int unk00;
    int unk04;
    hkSourceD273* m_pObservedSource;
    int unk0C;
    int m_10;
    int m_14;

    hkBoolD273 GetBool();
};

// @fnv 0x00d27300
hkBoolD273 hkObjD273::GetBool()
{
    return m_pObservedSource ? m_pObservedSource->IsStreamValid() : hkBoolD273(m_10 != m_14);
}

enum hkResultD273
{
    HK_SUCCESS_D273 = 0,
    HK_FAILURE_D273 = 1
};

class hkStreamD273
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual hkResultD273 seek(int offset, int whence);
};

class hkBufferedStreamD273
{
  public:
    int unk00;
    int unk04;
    hkStreamD273* m_pChildAtom;
    int unk0C;
    int m_pos;
    int m_iElementCount;

    void FlushToDestination();
    hkResultD273 FUN_00d27380(int offset, int whence);
};

// @fnv 0x00d27380
hkResultD273 hkBufferedStreamD273::FUN_00d27380(int offset, int whence)
{
    if (m_pChildAtom)
    {
        FlushToDestination();
        return m_pChildAtom->seek(offset, whence);
    }
    int pos = -1;
    switch (whence)
    {
    case 0:
        pos = offset;
        break;
    case 1:
        pos = m_pos + offset;
        break;
    case 2:
        pos = m_pos - offset;
        break;
    }
    hkResultD273 res = HK_SUCCESS_D273;
    if (pos < 0)
    {
        pos = 0;
        res = HK_FAILURE_D273;
    }
    else if (pos > m_iElementCount)
    {
        pos = m_iElementCount;
        res = HK_FAILURE_D273;
    }
    m_pos = pos;
    return res;
}

extern "C" void __cdecl FUN_00cb1280(void* pvDest, int iValue, int iCount) throw();

class hkReferencedObjectD274
{
  public:
    hkReferencedObjectD274()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD274() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d274c0 : public hkReferencedObjectD274
{
  public:
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    hkBool m_overflowed;

    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBool bMemoryIsString) throw();
    virtual ~FUN_00d274c0() throw();
};

// @fnv 0x00d274c0
FUN_00d274c0::FUN_00d274c0(void* pvMem, int aiSize, hkBool bMemoryIsString) throw()
{
    m_offset = 0;
    m_buf = (char*)pvMem;
    m_curSize = 0;
    m_iCapacity = bMemoryIsString ? aiSize - 1 : aiSize;
    m_overflowed = false;
    if (bMemoryIsString)
        FUN_00cb1280(pvMem, 0, aiSize);
}

class hkInnerD273
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual hkBoolD273 isValid() const;
};

class FUN_00d27340_cls
{
  public:
    int unk00, unk04;
    hkInnerD273* m_inner;

    hkBoolD273 IsValid() const;
};

// Returns m_inner->isValid() when m_inner is non-null, otherwise true.
// @fnv 0x00d27340
hkBoolD273 FUN_00d27340_cls::IsValid() const
{
    return m_inner ? m_inner->isValid() : hkBoolD273(true);
}

class hkInnerD273F
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int getNumChildren() const;
};

class FUN_00d273f0_cls
{
  public:
    int unk00, unk04;
    hkInnerD273F* m_inner;
    int unk0C;
    int m_base;

    int tell() const;
};

// Returns m_base plus the child count from m_inner, or -1 when the count is negative.
// @fnv 0x00d273f0
int FUN_00d273f0_cls::tell() const
{
    int n = m_inner ? m_inner->getNumChildren() : 0;
    if (n >= 0)
        return m_base + n;
    return -1;
}

class hkMemoryAllocatorD274;
struct hkMemoryRouterD274
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD274* m_pStreamAllocator;
    hkMemoryAllocatorD274& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD274 {
extern "C" hkMemoryRouterD274& __cdecl FUN_00c85750() throw();
}
void* __cdecl FUN_00c85620(hkMemoryAllocatorD274& alloc, int iSize, int iAlign) throw();
class hkBaseObjectD274
{
  public:
    virtual ~hkBaseObjectD274() throw()
    {}
};
class hkRefObjD274 : public hkBaseObjectD274
{
  public:
    hkRefObjD274() : m_sReferenceCount(1)
    {}
    virtual ~hkRefObjD274() throw()
    {}
    void FUN_00c90510() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkStreamWriterD274 : public hkRefObjD274
{
  public:
    hkStreamWriterD274()
    {}
    virtual ~hkStreamWriterD274() throw()
    {}
};
class hkBufStreamWriterD274 : public hkStreamWriterD274
{
  public:
    hkBufStreamWriterD274(hkStreamWriterD274* s, int bufSize) throw();
    virtual ~hkBufStreamWriterD274() throw();
    hkStreamWriterD274* m_stream;
    char* m_buf;
    int m_iBufferPosition;
    int m_bufSize;
    hkBoolD273 m_bIsOk;
};
// Stores s, allocates bufSize bytes with alignment argument 0x40, and initializes the buffer size and position.
// @fnv 0x00d27460
hkBufStreamWriterD274::hkBufStreamWriterD274(hkStreamWriterD274* apStream, int aiBufferSize) throw()
    : m_stream(apStream), m_bIsOk(true)
{
    if (m_stream)
        m_stream->FUN_00c90510();
    m_buf = (char*)FUN_00c85620(hkRouterD274::FUN_00c85750().heap(), aiBufferSize, 0x40);
    m_bufSize = aiBufferSize;
    m_iBufferPosition = 0;
}

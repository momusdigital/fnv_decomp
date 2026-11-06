
// src/gamebryo2.2/corelibs/nisystem/nimemstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nimemstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiBinaryStream
{
};

struct NiMemStream : NiBinaryStream
{
    void __thiscall FUN_00aa2d70(int iNumBytes);
};

// @fnv 0x00aa2d70
void __thiscall NiMemStream::FUN_00aa2d70(int iNumBytes)
{
    int iValue = *(unsigned int*)((char*)this + 0x14) + iNumBytes;
    if (iValue >= 0 && iValue < *(unsigned int*)((char*)this + 0x1c))
    {
        *(unsigned int*)((char*)this + 0x14) = (unsigned int)iValue;
        *(unsigned int*)((char*)this + 4) = (unsigned int)iValue;
    }
}

void* __cdecl _NiMalloc(unsigned int size);
void __cdecl _NiFreeAlias(void* p);
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00aa2dd0
unsigned int __fastcall FUN_00aa2dd0(NiMemStream* pThis, void* unused, const void* data, unsigned int numBytes)
{
    if (*(unsigned char*)(pThis + 0x20))
        return 0;

    unsigned int freeSpace = *(unsigned int*)(pThis + 0x1c) - *(unsigned int*)(pThis + 0x14);
    if (numBytes > freeSpace)
    {
        unsigned int oldEnd = *(unsigned int*)(pThis + 0x1c);
        unsigned int oldStart = *(unsigned int*)(pThis + 0x14);
        unsigned int newSize;
        if (numBytes <= oldEnd + freeSpace)
            newSize = oldEnd * 2;
        else
            newSize = (oldEnd - freeSpace) + numBytes;

        void* newBuffer = _NiMalloc(newSize);
        _memmove(newBuffer, *(void**)(pThis + 0x10), *(unsigned int*)(pThis + 0x18));
        _NiFreeAlias(*(void**)(pThis + 0x10));
        *(void**)(pThis + 0x10) = newBuffer;
        *(unsigned int*)(pThis + 0x1c) = newSize;
    }

    _memmove((char*)*(void**)(pThis + 0x10) + *(unsigned int*)(pThis + 0x14), data, numBytes);
    *(unsigned int*)(pThis + 0x14) += numBytes;
    if (*(unsigned int*)(pThis + 0x14) > *(unsigned int*)(pThis + 0x18))
        *(unsigned int*)(pThis + 0x18) = *(unsigned int*)(pThis + 0x14);

    return numBytes;
}

namespace fnv_00aa2e60 {
extern "C" void* __cdecl _memmove(void* dest, const void* src, unsigned int size);

struct NiMemStream
{
    char pad[0x10];
    char* m_kRayStart;
    unsigned int m_pos;
    unsigned int m_kRayEnd;
};

// Copies up to count bytes from the stream's buffer at m_pos into dest, advances m_pos, and returns the number of bytes copied.
// @fnv 0x00aa2e60
unsigned int ReadMemoryStream(NiMemStream* stream, void* dest, unsigned int count)
{
    unsigned int available = stream->m_kRayEnd - stream->m_pos;
    if (count > available)
        count = available;
    _memmove(dest, stream->m_kRayStart + stream->m_pos, count);
    stream->m_pos += count;
    return count;
}
}  // namespace fnv_00aa2e60

int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
// Copies up to uLen bytes from the stream's buffer at its current position into pData, advances the position, and calls SwapBufferBySizes on the data.
// @fnv 0x00aa2ec0
unsigned int __cdecl FUN_00aa2ec0(NiMemStream* pStream, void* apBuffer, unsigned int auiLength, void* apArgA,
                                  void* apArgB)
{
    if (auiLength <= 0)
        return 0;
    unsigned int uiPosition = *(unsigned int*)((char*)pStream + 0x14);
    unsigned int uiAvailable = *(unsigned int*)((char*)pStream + 0x18) - uiPosition;
    unsigned int uiCopied = auiLength;
    if (uiCopied > uiAvailable)
        uiCopied = uiAvailable;
    char* pBufferBase = *(char**)((char*)pStream + 0x10);
    _memmove(apBuffer, pBufferBase + uiPosition, uiCopied);
    *(unsigned int*)((char*)pStream + 0x14) += uiCopied;
    SwapBufferBySizes(apBuffer, auiLength, apArgA, apArgB);
    return uiCopied;
}

int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
struct S_00aa2dd0
{
    unsigned int __thiscall FUN_00aa2dd0(const void*, unsigned int);
};
// Copies uSize bytes from pSrc into a temporary buffer, passes it to SwapBufferBySizes, writes it to pStream, frees the buffer and returns the write result.
// @fnv 0x00aa2f20
unsigned int __cdecl FUN_00aa2f20(NiMemStream* pStream, const void* pSrc, unsigned int uSize, void* pA, void* pB)
{
    if (uSize <= 0)
        return 0;
    void* pBuffer = _NiMalloc(uSize);
    _memmove(pBuffer, pSrc, uSize);
    SwapBufferBySizes(pBuffer, uSize, pA, pB);
    unsigned int uRet = ((S_00aa2dd0*)pStream)->FUN_00aa2dd0(pBuffer, uSize);
    _NiFreeAlias(pBuffer);
    return uRet;
}

namespace fnv_00aa2f80 {
extern "C" void __cdecl ReadMemoryStream(void*);
extern "C" void __cdecl FUN_00aa2ea0(void*);
extern "C" void __cdecl FUN_00aa2ec0(void*);
extern "C" void __cdecl FUN_00aa2f20(void*);

struct NiMemStream
{
    char pad[8];
    void (*m_read)(void*);
    void (*m_write)(void*);
    void SetSwapMode(bool bDoSwap);
};

// Assigns the read and write function pointers based on bDoSwap, choosing one pair of handlers or the other.
// @fnv 0x00aa2f80
void NiMemStream::SetSwapMode(bool bDoSwap)
{
    if (bDoSwap)
    {
        m_read = FUN_00aa2ec0;
        m_write = FUN_00aa2f20;
    }
    else
    {
        m_read = ReadMemoryStream;
        m_write = FUN_00aa2ea0;
    }
}
}  // namespace fnv_00aa2f80

void* __cdecl _NiMalloc(unsigned int size);
void __cdecl _NiFreeAlias(void* p);
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);
unsigned int __fastcall FUN_00aa2dd0(NiMemStream* pThis, void* unused, const void* data, unsigned int numBytes);
int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
unsigned int __cdecl FUN_00aa2ec0(NiMemStream* pStream, void* pData, unsigned int uLen, void* pA, void* pB);
int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);

unsigned int __cdecl FUN_00aa2f20(NiMemStream* pStream, const void* pSrc, unsigned int uSize, void* pA, void* pB);

// @fnv 0x00aa2ea0
void __cdecl FUN_00aa2ea0(S_00aa2dd0* pThis, const void* pData, unsigned int uLen)
{
    pThis->FUN_00aa2dd0(pData, uLen);
}

struct NiAlloc
{
    void __thiscall FUN_00aa4060(void* ptr);
};
extern NiAlloc DAT_011f6238;
void __cdecl FUN_00aa10f0(void* ptr);

struct FUN_00aa2d90 : NiBinaryStream
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* buffer;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned char flag20;
    unsigned char flag21;

    void __thiscall FUN_00aa1d30();
    virtual ~FUN_00aa2d90();
    static void operator delete(void* ptr)
    {
        DAT_011f6238.FUN_00aa4060(ptr);
    }
};

// When both flags are zero, passes buffer to FUN_00aa10f0, then calls FUN_00aa1d30.
// @fnv 0x00aa2d90
FUN_00aa2d90::~FUN_00aa2d90()
{
    if (!flag20 && !flag21)
    {
        FUN_00aa10f0(buffer);
    }
    FUN_00aa1d30();
}

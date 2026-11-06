
// src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
struct BSNiAllocator
{
    void FUN_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes);
};
// @fnv 0x00aa22b0
void BSNiAllocator::FUN_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 10)
    {
        if (pvMemory)
        {
            pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
            g_memoryManager._DeallocateAlias(pvMemory);
            return;
        }
    }
    else
    {
        g_memoryManager._DeallocateAlias(pvMemory);
    }
}

namespace fnv_00aa23e0 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
// @fnv 0x00aa23e0
void __stdcall DeallocateExternal(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 0x10)
    {
        if (!pvMemory)
            return;
        pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
        g_memoryManager.Deallocate(pvMemory);
        return;
    }
    g_memoryManager.Deallocate(pvMemory);
}
}  // namespace fnv_00aa23e0

namespace fnv_00aa24a0 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_010a24d0;
struct BSNiAllocator
{
    void* Destroy(unsigned int);
};
// Sets the vtable pointer to DAT_010a24d0 and, when bit 0 of flags is set, deallocates this via g_memoryManager, then returns this.
// @fnv 0x00aa24a0
void* BSNiAllocator::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010a24d0;
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00aa24a0

struct SpawnHeap_cls
{
    char* __thiscall FUN_00aa4150(char* pBase, int iSize);
    char* __thiscall FUN_00aa4200(char* pBlock, int a2, int a3, int a4, int a5);
};

extern MM g_memoryManager;

// For eType 8, reallocates pBlock with extra *pAdjust bytes and fixes the header offset; otherwise forwards to FUN_00aa4200.
// @fnv 0x00aa22f0
char* __stdcall ResizeHeapBlock(char* pBlock, int* pSize, unsigned char* pAdjust, int eType, int a5, int a6, int a7,
                                int a8, int a9)
{
    SpawnHeap_cls* heap = reinterpret_cast<SpawnHeap_cls*>(&g_memoryManager);
    if (eType == 8)
    {
        int sz = *pSize;
        unsigned char ucAdjust = *pAdjust;
        if (pBlock != 0)
        {
            unsigned char ucHeader = (unsigned char)pBlock[-1];
            char* base = pBlock - ucHeader;
            char* r = heap->FUN_00aa4150(base, ucAdjust + sz);
            unsigned char adj = ucAdjust - (unsigned char)((ucAdjust - 1) & (unsigned char)(unsigned long)r);
            r += adj;
            r[-1] = (char)adj;
            return r;
        }
        return 0;
    }
    return heap->FUN_00aa4200(pBlock, *pSize, a7, a8, a9);
}

struct NiAllocGlobal
{
    int unk00;
    unsigned int FUN_00aa3e40(unsigned int size);
    unsigned int FUN_00aa4030(unsigned int size, int a5, int a6, int a7);
};

extern NiAllocGlobal DAT_011f6238;

void FUN_00ec61c0(unsigned int p, int zero, unsigned int v);

// @fnv 0x00aa2370
unsigned int __stdcall AllocateAlignedBuffer(unsigned int* puiSize, unsigned char* pucAlignByte, int aiAlignMode,
                                             int aiUnused, int a5, int a6, int a7)
{
    unsigned int r;
    if (aiAlignMode == 0xd)
    {
        unsigned int uiSize = *puiSize;
        unsigned char ucAlignByte = *pucAlignByte;
        unsigned int base = DAT_011f6238.FUN_00aa3e40(uiSize + ucAlignByte);
        unsigned char adj = (unsigned char)(ucAlignByte - ((ucAlignByte - 1) & (unsigned char)base));
        *(unsigned char*)(base + adj - 1) = adj;
        r = base + adj;
    }
    else
    {
        r = DAT_011f6238.FUN_00aa4030(*puiSize, a5, a6, a7);
    }
    FUN_00ec61c0(r, 0, *puiSize);
    return r;
}

extern "C" void* __cdecl MemSetAA2(void* pvDest, int iValue, unsigned int uiSize);

class MemoryManagerAA2
{
  public:
    void* RawAllocate(unsigned int uiSize);
    void* Allocate(unsigned int uiSize, const char* pcFile, int iLine, const char* pcFunction);
};

extern MemoryManagerAA2 g_kMemoryManagerAA2;

enum NiMemEventTypeAA2
{
    NI_UNKNOWN,
    NI_OPER_NEW,
    NI_OPER_NEW_ARRAY,
    NI_OPER_DELETE,
    NI_OPER_DELETE_ARRAY,
    NI_MALLOC,
    NI_REALLOC,
    NI_ALIGNEDMALLOC
};

// Allocates memory (aligned or plain) via g_kMemoryManagerAA2, zeroes stSizeInBytes bytes, and returns the pointer.
// @fnv 0x00aa2240
void* __stdcall AllocateZeroedMemory(unsigned int& stSizeInBytes, unsigned int& stAlignment,
                                     NiMemEventTypeAA2 eMemEventType, bool bProvideAccurateSizeOnDeallocate,
                                     const char* pcFile, int iLine, const char* pcFunction)
{
    void* pvMem;
    if (eMemEventType == NI_ALIGNEDMALLOC)
    {
        unsigned int stSize = stSizeInBytes;
        unsigned char ucAlignment = (unsigned char)stAlignment;
        char* pcMem = (char*)g_kMemoryManagerAA2.RawAllocate(stSize + ucAlignment);
        unsigned char ucOffset = ucAlignment - ((ucAlignment - 1) & (unsigned char)(unsigned int)pcMem);
        pcMem += ucOffset;
        pcMem[-1] = ucOffset;
        pvMem = pcMem;
    }
    else
    {
        pvMem = g_kMemoryManagerAA2.Allocate(stSizeInBytes, pcFile, iLine, pcFunction);
    }
    MemSetAA2(pvMem, 0, stSizeInBytes);
    return pvMem;
}

class BAA2420MemoryManager
{
  public:
    void* Reallocate(void* pvMem, unsigned int uiSize);
    void* ReallocateTracked(void* pvMem, unsigned int uiSize, const char* pcFile, int iLine, const char* pcFunction);
};

extern BAA2420MemoryManager g_kAA2420MemoryManager;

// @fnv 0x00aa2420
void* __stdcall ReallocateExternal(void* pvMem, unsigned int& uiSize, unsigned char& ucAlignment, int aiAllocationType,
                             bool bProvideSize, unsigned int uiCurrentSize, const char* pcFile, int iLine,
                             const char* pcFunction)
{
    if (aiAllocationType == 14)
    {
        unsigned int uiNewSize = uiSize;
        unsigned char ucAlign = ucAlignment;
        if (pvMem)
        {
            char* pcBase = (char*)pvMem - ((unsigned char*)pvMem)[-1];
            char* pcNew = (char*)g_kAA2420MemoryManager.Reallocate(pcBase, ucAlign + uiNewSize);
            unsigned char ucOffset = ucAlign - ((ucAlign - 1) & (unsigned char)(unsigned int)pcNew);
            pcNew += ucOffset;
            pcNew[-1] = ucOffset;
            return pcNew;
        }
        return 0;
    }
    return g_kAA2420MemoryManager.ReallocateTracked(pvMem, uiSize, pcFile, iLine, pcFunction);
}

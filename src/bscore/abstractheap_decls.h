// bscore/abstractheap_decls.h: declares HeapFreeBlock, HeapFreeList, HeapBlockList, AbstractHeapLogger, AbstractHeap
#ifndef ABSTRACTHEAP_DECLS_H
#define ABSTRACTHEAP_DECLS_H

#include "IMemoryHeap.h"

class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
    __forceinline void SetNextFree(HeapFreeBlock* block)
    {
        m_pNextFree = block;
    }
    __forceinline void SetPrevFree(HeapFreeBlock* block)
    {
        m_pPrevFree = block;
    }
    void RemoveFromFreeList();
};

class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
    __forceinline void AddBlock(HeapFreeBlock* block)
    {
        if (pTail)
        {
            HeapFreeBlock* tail = pTail;
            block->m_pNextFree = tail;
            HeapFreeBlock* previous = tail->m_pPrevFree;
            block->m_pPrevFree = previous;
            if (previous)
                previous->m_pNextFree = block;
            tail->m_pPrevFree = block;
            pTail = block;
        }
        else
        {
            pHead = block;
            pTail = block;
        }
    }
};
class HeapBlockList
{
  public:
    int iCount;
    HeapFreeList* pFirst;
};
class AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;
class AbstractHeapLogger
{
  public:
    static __forceinline AbstractHeapLogger* Get()
    {
        return DAT_011f6388;
    }
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int, const char*, int, int, int);
};
__forceinline bool AbstractHeapHasLog()
{
    return DAT_011f6388 != 0;
}
extern "C"
{
    extern void(__stdcall* fnv_EnterCriticalSection)(void*);
    extern void(__stdcall* fnv_LeaveCriticalSection)(void*);
    __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned int, unsigned int);
    int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
}

class AbstractHeap : public IMemoryHeap
{
  public:
    virtual unsigned int TotalSize(const void*);
    virtual void ResetHeap();
    virtual void* AllocateHeapMemory(unsigned int, unsigned int);
    virtual void FreeHeapMemory(void*);
    virtual unsigned int CreateMorePages(void*, unsigned int, unsigned int);
    virtual unsigned int CleanExtraPages(void*, unsigned int, unsigned int);
    virtual void DecommitPages(HeapFreeBlock*);
    virtual void CommitPages(HeapFreeBlock*, unsigned int);

    const char* pName;
    int m_iBlockAlignment;
    unsigned int m_uiBlockHeaderSize;
    unsigned int m_uiHeapGrowthEnabled;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiMinimumCommitSize;
    unsigned int m_uiCurrentCommitSize;
    unsigned int m_uiInitialCommitSize;
    int m_iUsedSize;
    int m_iAllocationCount;
    int m_iAllocatedBlockSize;
    char* m_pHeapBase;
    int m_iFreeBlockCount;
    MemoryBlockHeader* m_pFirstBlock;
    MemoryBlockHeader* m_pLastBlock;

    int m_uiFreeBlockCount;
    HeapFreeList m_kFreeLists[1024];
    HeapFreeList* m_pCurrentFreeList;
    HeapFreeList m_kFreeListSentinel;
    MemoryBlockHeader** m_ppHeapBlocks;
    unsigned int m_uiBlockCount;
    HeapBlockList m_kSubBucketLists[16];
    // Win32 critical-section storage; lock imports receive its address.
    unsigned char m_kCriticalSection[24];

    __forceinline HeapFreeList* GetFreeList(unsigned int size)
    {
        int bucket = size / m_iBlockAlignment - 1;
        return bucket >= 1024 ? &m_kFreeListSentinel : &m_kFreeLists[bucket];
    }
    __forceinline int GetSubBucket(int size)
    {
        if (size > 4096)
            return -1;
        return (size / m_iBlockAlignment - 1) / 64;
    }
    __forceinline bool IsLastInSubBucket(int bucket, HeapFreeList* list)
    {
        return bucket < 16 ? list >= m_kSubBucketLists[bucket + 1].pFirst : list >= m_pCurrentFreeList;
    }
    void* BaseAllocate(unsigned int);
    void BaseFree(void*);
    void RemoveBlockFromFreeList(HeapFreeBlock*);
    void PushBlock(MemoryBlockHeader*);
    void InsertFreeHeapBlock(HeapFreeBlock*);
    void RemoveFreeHeapBlock(HeapFreeList*, HeapFreeBlock*);
    void IncrementSubBucket(int);
    void DecrementSubBucket(int);
    void RebuildFreeLists();
    void InsertFreeBlock(HeapFreeBlock*);
    void CoalesceFreeBlocks(HeapFreeBlock*, HeapFreeBlock*);
};
FNV_STATIC_ASSERT(sizeof(MemoryBlockHeader) == 8);
FNV_STATIC_ASSERT(offsetof(MemoryBlockHeader, m_uiSizeAndFlags) == 4);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_pLastBlock) == 0x3c);
FNV_STATIC_ASSERT(sizeof(HeapFreeBlock) == 16);
FNV_STATIC_ASSERT(sizeof(HeapFreeList) == 8);
FNV_STATIC_ASSERT(sizeof(HeapBlockList) == 8);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kFreeLists) == 0x44);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kFreeListSentinel) == 0x2048);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kSubBucketLists) == 0x2058);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kCriticalSection) == 0x20d8);
#endif

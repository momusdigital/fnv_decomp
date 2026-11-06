// bscore/abstractheap.cpp: AbstractHeap, HeapFreeBlock, AbstractHeapDump, AbstractHeapBuckets and more (19 functions)

#include "abstractheap_decls.h"

// @fnv 0x00aa9bd0
void AbstractHeap::InsertFreeBlock(HeapFreeBlock* freeBlock)
{
    HeapFreeBlock* block = freeBlock;
    if (block)
    {
        for (;;)
        {
            HeapFreeBlock* previous = (HeapFreeBlock*)block->GetPrevious();
            if (previous && previous->IsFree())
            {
                CoalesceFreeBlocks(previous, block);
                block = previous;
            }
            else
            {
                break;
            }
        }
    }
    if (block)
    {
        while (block != m_pLastBlock && block->GetNext()->IsFree())
        {
            CoalesceFreeBlocks(block, (HeapFreeBlock*)block->GetNext());
        }
    }
    RebuildFreeLists();
}

// @fnv 0x00aa8f50
void* AbstractHeap::BaseAllocate(unsigned int size)
{
    fnv_EnterCriticalSection(&m_kCriticalSection);
    if (size <= 8)
        size = 8;
    else
        size = (size + m_iBlockAlignment - 1) & ~(m_iBlockAlignment - 1);
    unsigned int uiBlockSize;
    void* pMemory = 0;
    HeapFreeList* pSizeClassFreeList = GetFreeList(size);
    if (!pSizeClassFreeList->pTail && pSizeClassFreeList != &m_kFreeListSentinel)
    {
        pSizeClassFreeList += m_uiBlockHeaderSize / m_iBlockAlignment;
        if (pSizeClassFreeList > m_pCurrentFreeList)
        {
            pSizeClassFreeList = &m_kFreeListSentinel;
        }
        else
        {
            int iSubBucketIndex = 0;
            int iFirstBucket = GetSubBucket(size + m_uiBlockHeaderSize);
            for (iSubBucketIndex = iFirstBucket; iSubBucketIndex < 16 && !pSizeClassFreeList->pTail; ++iSubBucketIndex)
            {
                if (m_kSubBucketLists[iSubBucketIndex].iCount)
                {
                    if (m_kSubBucketLists[iSubBucketIndex].pFirst > pSizeClassFreeList)
                        pSizeClassFreeList = m_kSubBucketLists[iSubBucketIndex].pFirst;
                    while (!pSizeClassFreeList->pTail && !IsLastInSubBucket(iSubBucketIndex, pSizeClassFreeList))
                        ++pSizeClassFreeList;
                }
            }
            if (iSubBucketIndex == 16)
                pSizeClassFreeList = &m_kFreeListSentinel;
        }
    }
    if (pSizeClassFreeList->pTail)
    {
        HeapFreeBlock* pBlock = pSizeClassFreeList->pHead;
        while (pBlock)
        {
            uiBlockSize = pBlock->GetSize();
            int iExtra = uiBlockSize - size;
            if (iExtra == 0 || iExtra >= (int)m_uiBlockHeaderSize)
            {
                HeapFreeBlock* pNewBlock = 0;
                bool bDecommitted = pBlock->IsDecommitted();
                RemoveFreeHeapBlock(pSizeClassFreeList, pBlock);
                if (iExtra)
                {
                    if (bDecommitted)
                    {
                        unsigned int iCommitSize = size + 24;
                        bool bCommitted = VirtualAlloc(pBlock, iCommitSize, 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            InsertFreeHeapBlock(pBlock);
                            fnv_LeaveCriticalSection(&m_kCriticalSection);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing Entire Free Block: %08X, %08X\r\n", pBlock, iCommitSize);
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                    pNewBlock = (HeapFreeBlock*)((char*)pBlock + size + sizeof(MemoryBlockHeader));
                    unsigned int iRemainingSize = uiBlockSize - (size + sizeof(MemoryBlockHeader));
                    pNewBlock->m_pNextFree = 0;
                    pNewBlock->m_pPrevFree = 0;
                    pNewBlock->SetFlags(iRemainingSize, 0);
                    pNewBlock->SetPrevious(pBlock);
                    if (pBlock == m_pLastBlock)
                        m_pLastBlock = pNewBlock;
                    else
                    {
                        MemoryBlockHeader* pNext = pBlock->GetNext();
                        pNext->SetPrevious(pNewBlock);
                    }
                    ++m_iFreeBlockCount;
                    InsertFreeHeapBlock(pNewBlock);
                    InsertFreeBlock(pNewBlock);
                }
                else
                {
                    if (bDecommitted)
                    {
                        bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            InsertFreeHeapBlock(pBlock);
                            fnv_LeaveCriticalSection(&m_kCriticalSection);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing perfectly matched Free Block: %08X, %08X\r\n", pBlock,
                                  size + sizeof(MemoryBlockHeader));
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                }
                pBlock->SetSize(size);
                pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
                m_iAllocatedBlockSize += pBlock->GetTotalSize();
                break;
            }
            pBlock = pBlock->m_pPrevFree;
        }
    }
    if (!pMemory)
    {
        unsigned int uiBlockAllocationSizeItem = size + sizeof(MemoryBlockHeader);
        unsigned int iNeededSize = m_iUsedSize + uiBlockAllocationSizeItem;
        if (m_uiHeapGrowthEnabled && iNeededSize > m_uiCurrentCommitSize && iNeededSize <= m_uiMaximumHeapSize)
            m_uiCurrentCommitSize += CreateMorePages(m_pHeapBase, m_uiCurrentCommitSize, uiBlockAllocationSizeItem);
        if (iNeededSize <= m_uiCurrentCommitSize)
        {
            MemoryBlockHeader* pBlock = (MemoryBlockHeader*)(m_pHeapBase + m_iUsedSize);
            if (m_uiHeapGrowthEnabled)
            {
                bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                if (!bCommitted)
                {
                    fnv_LeaveCriticalSection(&m_kCriticalSection);
                    return 0;
                }
                char szMessage[256];
                sprintf_s(szMessage, 256, "Committing memory on end of heap: %08X, %08X\r\n", pBlock,
                          size + sizeof(MemoryBlockHeader));
                if (AbstractHeapHasLog())
                {
                    AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                }
            }
            pBlock->SetFlags(size, 0);
            PushBlock(pBlock);
            m_iUsedSize += uiBlockAllocationSizeItem;
            if (m_iUsedSize > m_iAllocationCount)
                m_iAllocationCount = m_iUsedSize;
            pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
            m_iAllocatedBlockSize += uiBlockAllocationSizeItem;
        }
    }
    fnv_LeaveCriticalSection(&m_kCriticalSection);
    return pMemory;
}

// @fnv 0x00aa9a70
void AbstractHeap::RebuildFreeLists()
{
    MemoryBlockHeader* block = m_pLastBlock;
    while (block && block->IsFree() && block->GetNext() == (MemoryBlockHeader*)(m_pHeapBase + m_iUsedSize))
    {
        RemoveBlockFromFreeList((HeapFreeBlock*)block);
        m_iUsedSize -= block->GetTotalSize();
        --m_iFreeBlockCount;
        if (m_pFirstBlock == m_pLastBlock)
        {
            m_pLastBlock = 0;
            m_pFirstBlock = 0;
            break;
        }
        else
        {
            m_pLastBlock = block->GetPrevious();
        }
        block = m_pLastBlock;
    }
    if (m_uiHeapGrowthEnabled)
    {
        unsigned int unused = m_uiCurrentCommitSize - m_iUsedSize;
        if (m_uiCurrentCommitSize - unused < m_uiMinimumCommitSize)
            unused = m_uiCurrentCommitSize - m_uiMinimumCommitSize;
        if (unused >= m_uiHeapGrowthEnabled)
            m_uiCurrentCommitSize -= CleanExtraPages(m_pHeapBase, m_uiCurrentCommitSize, unused);
    }
}

// @fnv 0x00aa9970
void AbstractHeap::CoalesceFreeBlocks(HeapFreeBlock* pFirstBlock, HeapFreeBlock* pSecondBlock)
{
    RemoveBlockFromFreeList(pFirstBlock);
    RemoveBlockFromFreeList(pSecondBlock);
    if (pSecondBlock->IsDecommitted())
        pFirstBlock->SetDecommitted(true);
    pFirstBlock->SetSize(pFirstBlock->GetSize() + pSecondBlock->GetTotalSize());
    if (pSecondBlock == m_pLastBlock)
        m_pLastBlock = pFirstBlock;
    else
        pSecondBlock->GetNext()->SetPrevious(pFirstBlock);
    --m_iFreeBlockCount;
    InsertFreeHeapBlock(pFirstBlock);
}

// @fnv 0x00aa98f0
void AbstractHeap::BaseFree(void* pointer)
{
    if (!pointer)
        return;
    fnv_EnterCriticalSection(&m_kCriticalSection);
    HeapFreeBlock* block = (HeapFreeBlock*)((char*)pointer - sizeof(MemoryBlockHeader));
    m_iAllocatedBlockSize -= block->GetTotalSize();
    InsertFreeHeapBlock(block);
    InsertFreeBlock(block);
    fnv_LeaveCriticalSection(&m_kCriticalSection);
}

// Removes the given block from the free list corresponding to its size by calling RemoveFreeHeapBlock.
// @fnv 0x00aaa660
inline void AbstractHeap::RemoveBlockFromFreeList(HeapFreeBlock* block)
{
    RemoveFreeHeapBlock(GetFreeList(block->GetSize()), block);
}

// Clears the block's fields, marks it free, adds it to the free list for its size, and updates the free-block and sub-bucket counters.
// @fnv 0x00aa9d30
void AbstractHeap::InsertFreeHeapBlock(HeapFreeBlock* block)
{
    block->m_pPrevFree = 0;
    block->m_pNextFree = 0;
    block->SetFree(true);
    HeapFreeList* list = GetFreeList(block->GetSize());
    list->AddBlock(block);
    ++m_uiFreeBlockCount;
    IncrementSubBucket(block->GetSize());
}
// @fnv 0x00aa9e50
void AbstractHeap::RemoveFreeHeapBlock(HeapFreeList* apFreeList, HeapFreeBlock* block)
{
    HeapFreeBlock* pPrev = block->m_pPrevFree;
    HeapFreeBlock* pNext = block->m_pNextFree;
    block->RemoveFromFreeList();
    block->SetFree(false);
    if (block == apFreeList->pHead)
        apFreeList->pHead = pPrev;
    if (block == apFreeList->pTail)
        apFreeList->pTail = pNext;
    DecrementSubBucket(block->GetSize());
    --m_uiFreeBlockCount;
}
// Unlinks this node from the free list by patching its neighbours' free-list links, then clears the previous and next free pointers.
// @fnv 0x00aaa5e0
inline void HeapFreeBlock::RemoveFromFreeList()
{
    if (m_pNextFree)
        m_pNextFree->SetPrevFree(m_pPrevFree);
    if (m_pPrevFree)
        m_pPrevFree->SetNextFree(m_pNextFree);
    m_pPrevFree = 0;
    m_pNextFree = 0;
}
// Computes the sub-bucket index for size and, if valid, increments that bucket's iCount.
// @fnv 0x00aa9ef0
void AbstractHeap::IncrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        ++m_kSubBucketLists[bucket].iCount;
}
// Looks up the sub-bucket for size and decrements its iCount if a bucket was found.
// @fnv 0x00aa9f50
void AbstractHeap::DecrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        --m_kSubBucketLists[bucket].iCount;
}
// Links block into the heap's block list, setting its previous pointer and updating the head/tail and count.
// @fnv 0x00aa9ca0
void AbstractHeap::PushBlock(MemoryBlockHeader* block)
{
    if (m_pLastBlock)
    {
        block->SetPrevious(m_pLastBlock);
        m_pLastBlock = block;
    }
    else
    {
        m_pFirstBlock = block;
        m_pLastBlock = m_pFirstBlock;
    }
    ++m_iFreeBlockCount;
}

struct FUN_00aaa560_shell
{
    int __thiscall FUN_00aaa560(int arg);
};

// Returns -1 if arg is null, otherwise counts nodes by following the pointer at offset 0x4C until it is null.
// @fnv 0x00aaa560
int __thiscall FUN_00aaa560_shell::FUN_00aaa560(int pNode)
{
    if (!pNode)
        return -1;
    int count = 0;
    while (*(int*)(pNode + 0x4C))
    {
        ++count;
        pNode = *(int*)(pNode + 0x4C);
    }
    return count;
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct Heap00aaa5b0
{
    void FUN_00aa8da0();
    Heap00aaa5b0* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_00aa8da0, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00aaa5b0
Heap00aaa5b0* Heap00aaa5b0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00aa8da0();
    if (flags & 1)
    {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
struct FreeHeapBlock_aa9
{
    unsigned int m_uiChunkSize;
    int pad[2];
    FreeHeapBlock_aa9* pNext;
};
struct HeapBlock_aa9
{
    HeapBlock_aa9* pPrev;
};
struct FreeList_aa9
{
    FreeHeapBlock_aa9* pHead;
    int pad;
};
struct SubBucket_aa9
{
    int iCount;
    FreeList_aa9* pList;
};
struct FUN_00aaa0d0_s
{
    void FUN_00aaa0d0(int);
};
struct FUN_00aa9fb0_heap
{
    char pad0[0x3c];
    HeapBlock_aa9* m_pLastBlock;
    int pad40;
    FreeList_aa9 m_kFreeLists[0x400];
    int pad2044;
    FreeList_aa9 m_kFreeListSentinel;
    char pad2050[8];
    SubBucket_aa9 m_kSubBucketLists[16];
    char kCS[0x18];
    void FUN_00aa9fb0();
};
// @fnv 0x00aa9fb0
void FUN_00aa9fb0_heap::FUN_00aa9fb0()
{
    FreeHeapBlock_aa9* pblock;
    HeapBlock_aa9* pfreeCur;
    int i2;
    int isub;
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)kCS);
    pblock = 0;
    for (isub = 0; isub < 16; isub++)
    {
        if (m_kSubBucketLists[isub].iCount)
        {
            pblock = m_kSubBucketLists[isub].pList->pHead;
            while (pblock)
            {
                ((FUN_00aaa0d0_s*)this)->FUN_00aaa0d0((int)pblock);
                pblock = pblock->pNext;
            }
        }
    }
    for (i2 = 0; i2 < 0x400; i2++)
    {
        pblock = m_kFreeLists[i2].pHead;
        while (pblock)
        {
            ((FUN_00aaa0d0_s*)this)->FUN_00aaa0d0((int)pblock);
            pblock = pblock->pNext;
        }
    }
    pblock = m_kFreeListSentinel.pHead;
    while (pblock)
    {
        ((FUN_00aaa0d0_s*)this)->FUN_00aaa0d0((int)pblock);
        pblock = pblock->pNext;
    }
    pfreeCur = m_pLastBlock;
    while (pfreeCur)
    {
        pfreeCur = pfreeCur->pPrev;
    }
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)kCS);
}

struct _MEMORYSTATUS
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(_MEMORYSTATUS*);

struct AbstractHeapDump : AbstractHeap
{
    void LogFreeBlockStats(unsigned int blockSize, HeapFreeList* list);
};

// If heap logging is enabled, logs the block size, then counts free blocks in list and reports count, largest, total and available physical memory.
// @fnv 0x00aa9760
void AbstractHeapDump::LogFreeBlockStats(unsigned int blockSize, HeapFreeList* list)
{
    if (AbstractHeapHasLog())
    {
        unsigned int numBlocks4 = 0;
        unsigned int largest = 0;
        unsigned int total = 0;
        _MEMORYSTATUS status3;
        char buffer[256];
        sprintf_s(buffer, 256, "AbstractHeap: Checking list for block size %u\n", blockSize);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
        if (list)
        {
            MemoryBlockHeader* block = list->pHead;
            while (block)
            {
                numBlocks4++;
                unsigned int size = block->GetSize();
                total += size;
                if (size > largest)
                    largest = size;
                block = block->GetNext();
            }
        }
        GlobalMemoryStatus(&status3);
        sprintf_s(
            buffer, 256,
            "\tNumber of blocks free: %u\n\tLargest free block: %u\n\tTotal space in free blocks: %u\n\tAvailable global memory: %u\n",
            numBlocks4, largest, total, status3.dwAvailPhys);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
    }
}

struct HeapDumpFile
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int Write(void* data, unsigned int size);
};

struct BucketInfo
{
    unsigned int iSize;
    int iCount;
};

struct AbstractHeapBuckets : AbstractHeap
{
    int WriteBucketInfo(HeapDumpFile* file);
};

// Writes the bucket count and, for each bucket size, the number of free blocks to the given file, returning the total bytes written.
// @fnv 0x00aaa310
int AbstractHeapBuckets::WriteBucketInfo(HeapDumpFile* file)
{
    if (!file)
        return 0;
    fnv_EnterCriticalSection(m_kCriticalSection);
    BucketInfo bucketInfo;
    int numBuckets;
    int total;
    int i4;
    HeapFreeBlock* block;
    {
        HeapFreeList* list;
        total = 0;
        numBuckets = 0x401;
        total += file->Write(&numBuckets, 4);
        for (i4 = 0; i4 < numBuckets; i4++)
        {
            bucketInfo.iSize = (i4 + 1) * m_iBlockAlignment;
            bucketInfo.iCount = 0;
            list = GetFreeList(bucketInfo.iSize);
            block = list->pHead;
            while (block)
            {
                bucketInfo.iCount++;
                block = block->m_pPrevFree;
            }
            total += file->Write(&bucketInfo, 8);
        }
    }
    fnv_LeaveCriticalSection(m_kCriticalSection);
    return total;
}

class IMemoryManagerFile
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int Write(const void* buffer, unsigned int size);
};

struct HeapBlockInfo
{
    int iType;
    unsigned int iSize;
    int bFree;
    int unk0C;
    int unk10;
    int iOwner;
};

struct AbstractHeapBlockInfo : AbstractHeap
{
    int WriteHeapBlockInfo(IMemoryManagerFile* file, bool full);
};

// Writes the heap block count and, when full is set, each block's size, free flag and owner to the file, returning bytes written.
// @fnv 0x00aaa430
int AbstractHeapBlockInfo::WriteHeapBlockInfo(IMemoryManagerFile* file, bool full)
{
    if (!file)
        return 0;
    fnv_EnterCriticalSection(m_kCriticalSection);
    int total2 = 0;
    if (full)
    {
        total2 += file->Write(&m_iFreeBlockCount, 4);
        int i;
        HeapBlockInfo info2;
        info2.iType = 8;
        MemoryBlockHeader* block7 = m_pFirstBlock;
        for (i = 0; i < m_iFreeBlockCount; block7 = block7->GetNext(), i++)
        {
            info2.iSize = block7->GetSize();
            info2.bFree = block7->IsFree() != 0;
            info2.iOwner = -1;
            total2 += file->Write(&info2, sizeof(info2));
        }
    }
    else
    {
        int zero4 = 0;
        total2 += file->Write(&zero4, 4);
    }
    fnv_LeaveCriticalSection(m_kCriticalSection);
    return total2;
}

class HeapStatsX
{
  public:
    const char* pName;
    unsigned int iMemHeapSize;
    unsigned int m_uiCurrentCommitSize;
    int m_iUsedSize;
    unsigned int m_iFreeBlockCount;
    unsigned int m_uiFreeBlockCount;
    int iFreeSize;
    int iUsedSize;
    int iMinFreeBlock;
    int iMaxFreeBlock;
    unsigned int iHeapStructSize;
    unsigned int iFreeListBytes;
    int iBlockTableBytes;
    int iUnusedBytes;
    unsigned int m_uiTrailingStatsValue;
};

struct AbstractHeapX
{
    char pad00[0x04];
    const char* pName;
    char pad08[0x0c];
    unsigned int m_uiMaximumHeapSize;
    char pad18[0x04];
    unsigned int m_uiCurrentCommitSize;
    char pad20[0x04];
    int m_iUsedSize;
    char pad28[0x04];
    int m_iAllocatedBlockSize;
    char pad30[0x04];
    unsigned int m_iFreeBlockCount;
    MemoryBlockHeader* m_pFirstBlock;
    MemoryBlockHeader* m_pLastBlock;
    unsigned int m_uiFreeBlockCount;
    char pad44[0x20d8 - 0x44];
    char cs[0x18];
    void GetHeapStats(HeapStatsX* stats, bool full);
};

// @fnv 0x00aaa0e0
void AbstractHeapX::GetHeapStats(HeapStatsX* stats, bool full)
{
    fnv_EnterCriticalSection(&this->cs);
    stats->pName = this->pName;
    stats->iMemHeapSize = this->m_uiMaximumHeapSize;
    stats->m_uiCurrentCommitSize = this->m_uiCurrentCommitSize;
    stats->m_iUsedSize = this->m_iUsedSize;
    stats->m_iFreeBlockCount = this->m_iFreeBlockCount;
    stats->m_uiFreeBlockCount = this->m_uiFreeBlockCount;
    int iZero4 = 0;
    int iBlockBytes2 = stats->m_iFreeBlockCount * iZero4;
    int iHeaderSize3 = sizeof(MemoryBlockHeader) - iZero4;
    stats->iHeapStructSize = sizeof(AbstractHeapX);
    stats->iFreeListBytes = 0x2000;
    stats->iFreeListBytes += 0x80;
    stats->iBlockTableBytes = this->m_iFreeBlockCount * iHeaderSize3;
    stats->iUnusedBytes = iBlockBytes2;
    MemoryBlockHeader* aBlock = this->m_pFirstBlock;
    stats->iFreeSize = this->m_iUsedSize - this->m_iAllocatedBlockSize;
    stats->iUsedSize = this->m_iAllocatedBlockSize;
    stats->iMinFreeBlock = 0xfffffff;
    stats->iMaxFreeBlock = 0;
    if (full)
    {
        stats->iFreeSize = 0;
        stats->iUsedSize = 0;
        while (aBlock)
        {
            if (aBlock->IsFree())
            {
                int freeSize = aBlock->GetSize();
                stats->iFreeSize += freeSize + iHeaderSize3;
                if (freeSize < stats->iMinFreeBlock)
                    stats->iMinFreeBlock = freeSize;
                if (freeSize > stats->iMaxFreeBlock)
                    stats->iMaxFreeBlock = freeSize;
            }
            else
            {
                int usedSize_ = aBlock->GetSize();
                stats->iUsedSize += usedSize_ + iHeaderSize3;
            }
            aBlock = (aBlock == this->m_pLastBlock) ? 0 : aBlock->GetNext();
        }
        if (stats->m_uiFreeBlockCount == 0)
            stats->iMinFreeBlock = 0;
    }
    stats->m_uiTrailingStatsValue = stats->iMemHeapSize - stats->m_iUsedSize + stats->iFreeSize;
    fnv_LeaveCriticalSection(&this->cs);
}

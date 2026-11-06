
// src/havok/common/base/memory/allocator/freelist/hklargeblockallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hklargeblockallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd74b0_cls
{
    void FUN_00dd74b0(int a, int b, int c, int d);
    void* FUN_00dd7650(int a, int b, int c, int d);
};
// Calls FUN_00dd74b0 with the four arguments and returns this.
// @fnv 0x00dd7650
void* __thiscall FUN_00dd74b0_cls::FUN_00dd7650(int a, int b, int c, int d)
{
    FUN_00dd74b0(a, b, c, d);
    return this;
}

// @fnv 0x00dd8a80
void* __stdcall getAllocatedSize(void* p, void* apUnused)
{
    return reinterpret_cast<char*>(reinterpret_cast<size_t*>(p)[-3] & 0xfffffffc) - 0x10;
}

struct hkReferencedObject
{
    void removeReference();
};
extern int DAT_0102e388;
extern int DAT_010d7c80;
struct hkLargeBlockAllocator
{
    int* m_p;
    int* m_q;
    hkReferencedObject* m_r;
    void FUN_00dd91f0();
};
// @fnv 0x00dd91f0
void hkLargeBlockAllocator::FUN_00dd91f0()
{
    m_p = (int*)&DAT_010d7c80;
    if (m_r)
        m_r->removeReference();
    m_p = (int*)&DAT_0102e388;
}

// Returns the value at a[-3] with the low two bits cleared.
// @fnv 0x00dd8a90
int __stdcall getAllocatedSizeWithOverhead(int* pValues, int iUnused)
{
    return (pValues[-3] & 0xfffffffc);
}

struct DD7F10ListNode
{
    DD7F10ListNode* m_next;
    DD7F10ListNode* m_pSecondNode;
};

struct DD7F10Pool
{
    int unk00;
    int unk04;
    int m_numAllocated;
    int m_numFree;
    void** m_freeListPtr;
    void* m_kFreeListEntries;
    void* m_buckets[32];
    int unk98;
    void* m_freeHead;
    int m_blockShift;
    DD7F10ListNode m_kBlocks;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int m_totalBytes;
    int m_peakBytes;

    void FUN_00dd7f10();
};

// Clears the pool's counters, buckets, free list and sentinel node, then sets the block shift to 3.
// @fnv 0x00dd7f10
void DD7F10Pool::FUN_00dd7f10()
{
    m_peakBytes = 0;
    m_totalBytes = 0;
    m_numAllocated = 0;
    m_numFree = 0;
    for (int i = 0; i < 32; i++)
        m_buckets[i] = 0;
    m_freeHead = 0;
    m_kFreeListEntries = 0;
    m_blockShift = 3;
    m_freeListPtr = &m_freeHead;
    m_kBlocks.m_pSecondNode = &m_kBlocks;
    m_kBlocks.m_next = &m_kBlocks;
}

struct WorkItem
{
    int unk00;
    WorkItem* next;
    int unk08;
    int value;
};

struct WorkProcessor
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual void fourth();
    virtual void process(WorkItem*, int);
};

struct QueueOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    WorkProcessor* processor;
    int unk9c;
    int unka0;
    WorkItem sentinel;
    void ProcessAllItems();
    void FUN_00dd7f10();
};

// Iterates the sentinel-linked list from sentinel.next, calling processor->process on each item with its value, then calls FUN_00dd7f10.
// @fnv 0x00dd7fc0
void QueueOwner::ProcessAllItems()
{
    WorkItem* current = sentinel.next;
    if (current != &sentinel)
    {
        do
        {
            int value = current->value;
            WorkProcessor* pProcessor = processor;
            WorkItem* next = current->next;
            pProcessor->process(current, value);
            current = next;
        } while (current != &sentinel);
    }
    FUN_00dd7f10();
}

struct TreeChunk
{
    unsigned int m_iWordAt00;
    unsigned int m_pFirstNode;
    int m_8, m_iThirdValue;
    TreeChunk* m_pChildAtom[2];
};

// @fnv 0x00dd8310
unsigned int __stdcall GetMaxChunkSize(TreeChunk* apTreeChunk, unsigned int maxSize)
{
    while (apTreeChunk)
    {
        unsigned int size = apTreeChunk->m_pFirstNode & ~3u;
        if (size > maxSize)
            maxSize = size;
        apTreeChunk = apTreeChunk->m_pChildAtom[1] ? apTreeChunk->m_pChildAtom[1] : apTreeChunk->m_pChildAtom[0];
    }
    return maxSize;
}

int __cdecl FUN_00dd7e00(unsigned int size);

struct FUN_00dd8350_Alloc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int unk14;
    void* m_treeBins[32];

    unsigned int GetMaxChunkSize(void* tree, unsigned int size);
    unsigned int FUN_00dd8350();
};

// @fnv 0x00dd8350
unsigned int FUN_00dd8350_Alloc::FUN_00dd8350()
{
    unsigned int size = unk14;
    int idx = FUN_00dd7e00(size);
    for (int i = 31; i >= idx; i--)
    {
        void* tree = m_treeBins[i];
        if (tree)
            return GetMaxChunkSize(tree, size);
    }
    return size;
}

struct DD89B0MemChunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;

    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isPinuse() const
    {
        return (head & 1) != 0;
    }
    bool isCinuse() const
    {
        return (head & 2) != 0;
    }
    DD89B0MemChunk* chunkPlusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this + s);
    }
    DD89B0MemChunk* chunkMinusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this - s);
    }
    void setSizeAndPinuseOfFreeChunk(unsigned int s)
    {
        head = s | 1;
        chunkPlusOffset(s)->m_uiPreviousChunkSize = s;
    }
    void setFreeWithPinuse(unsigned int s, DD89B0MemChunk* n)
    {
        n->head &= ~1u;
        setSizeAndPinuseOfFreeChunk(s);
    }
};

struct DD89B0LargeBlockAllocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DD89B0MemChunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    unsigned int m_uiBufferCapacity;
    int m_overhead;

    void _unlinkChunk(DD89B0MemChunk* p);
    void _insertChunk(DD89B0MemChunk* p, unsigned int size);
    void Free(void* mem);
};

// Frees a block: merges it with adjacent free chunks, updates the top chunk or inserts the merged chunk into the free list.
// @fnv 0x00dd89b0
void DD89B0LargeBlockAllocator::Free(void* mem)
{
    if (!mem)
        return;
    DD89B0MemChunk* p = (DD89B0MemChunk*)((char*)mem - 16);
    unsigned int uiChunkSize = p->getChunkSize();
    m_uiBufferCapacity -= uiChunkSize;
    m_overhead += 16 - p->getChunkSize();
    DD89B0MemChunk* next = p->chunkPlusOffset(uiChunkSize);
    if (!p->isPinuse())
    {
        unsigned int prevsize = p->m_uiPreviousChunkSize;
        p = p->chunkMinusOffset(prevsize);
        _unlinkChunk(p);
        uiChunkSize += prevsize;
    }
    if (!next->isCinuse())
    {
        if (next == m_fMinimumV)
        {
            unsigned int uiTopSize = m_uiChunkSize += uiChunkSize;
            m_fMinimumV = p;
            p->head = uiTopSize | 1;
            return;
        }
        unsigned int uiNextSize = next->getChunkSize();
        uiChunkSize += uiNextSize;
        _unlinkChunk(next);
        p->setSizeAndPinuseOfFreeChunk(uiChunkSize);
    }
    else
    {
        p->setFreeWithPinuse(uiChunkSize, next);
    }
    _insertChunk(p, uiChunkSize);
}

typedef void(__cdecl* S_00dd8aa0_Callback)(void* start, unsigned int size, void* param);

struct S_00dd8aa0_Chunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;
    S_00dd8aa0_Chunk* fd;
    S_00dd8aa0_Chunk* bk;
    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isInuse() const
    {
        return ((head >> 1) & 1) != 0;
    }
    void* getPayload()
    {
        return (void*)(this + 1);
    }
    unsigned int getPayloadSize() const
    {
        return getChunkSize() - sizeof(S_00dd8aa0_Chunk);
    }
    S_00dd8aa0_Chunk* nextChunk()
    {
        return (S_00dd8aa0_Chunk*)((char*)this + getChunkSize());
    }
};

struct S_00dd8aa0_Page
{
    S_00dd8aa0_Page* m_pSecondNode;
    S_00dd8aa0_Page* m_next;
    int unk8;
    int unkC;
    char* m_kRayStart;
    char* m_kRayEnd;
    S_00dd8aa0_Chunk* getFirstChunk()
    {
        return (S_00dd8aa0_Chunk*)m_kRayStart;
    }
    S_00dd8aa0_Chunk* getFooter()
    {
        return (S_00dd8aa0_Chunk*)(m_kRayEnd - sizeof(S_00dd8aa0_Chunk));
    }
};

struct S_00dd8aa0_Allocator
{
    void* m_vtbl;
    int unk4;
    int unk8;
    int unkC;
    S_00dd8aa0_Chunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    S_00dd8aa0_Page m_kPage;
    void ForEachAllocatedBlock(S_00dd8aa0_Callback callback, void* param);
};

// @fnv 0x00dd8aa0
void S_00dd8aa0_Allocator::ForEachAllocatedBlock(S_00dd8aa0_Callback callback, void* param)
{
    m_fMinimumV->head = m_uiChunkSize | 1;
    for (S_00dd8aa0_Page* page = m_kPage.m_next; page != &m_kPage; page = page->m_next)
    {
        S_00dd8aa0_Chunk* end = page->getFooter();
        for (S_00dd8aa0_Chunk* cur = page->getFirstChunk(); cur != end;)
        {
            unsigned int size = cur->getChunkSize();
            if (cur->isInuse())
                callback(cur->getPayload(), cur->getPayloadSize(), param);
            cur = (S_00dd8aa0_Chunk*)((char*)cur + size);
        }
    }
}

// @fnv 0x00dd7e70
int __cdecl FUN_00dd7e70(int aiValue)
{
    unsigned int r = (unsigned int)(aiValue - 1);
    unsigned int t = r >> 12 & 0x10;
    unsigned int kIter = 0;
    kIter += t;
    r >>= t;
    t = r >> 5 & 8;
    kIter += t;
    r >>= t;
    t = r >> 2 & 4;
    kIter += t;
    r >>= t;
    t = r >> 1 & 2;
    kIter += t;
    r >>= t;
    t = r >> 1 & 1;
    kIter += t;
    r >>= t;
    return (int)(r + kIter);
}

struct ListNode
{
    int unk00;
    ListNode* next;
    int unk08;
    int value;
};

extern int DAT_010d7c34;
extern int DAT_010d7c10;

struct ListTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(ListNode* node, int value);
};

struct FUN_00dd7ec0_cls
{
    int* m_vptr;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    ListTarget* m_98;
    int unk9C;
    int unkA0;
    ListNode m_a4;
    void FUN_00dd7ec0();
};

// Sets the vtable, walks the m_a4 list calling m_98->v10 on each node, then sets the second vtable.
// @fnv 0x00dd7ec0
void FUN_00dd7ec0_cls::FUN_00dd7ec0()
{
    m_vptr = &DAT_010d7c34;
    ListNode* sentinel = &m_a4;
    ListNode* node = m_a4.next;
    if (node != sentinel)
    {
        do
        {
            int value = node->value;
            ListNode* next = node->next;
            m_98->v10(node, value);
            node = next;
        } while (node != sentinel);
    }
    m_vptr = &DAT_010d7c10;
}

struct tchunk
{
    int prev_foot;
    int head;
    tchunk* fd;
    tchunk* bk;
    tchunk* child[2];
    tchunk* parent;
    int index;
};

int __cdecl FUN_00dd7e00(int size);

struct TargetClass
{
    char pad00[8];
    unsigned int m_uiChunkCount;
    char pad0c[0xc];
    tchunk* m_apChunkLists[32];

    void InsertChunk(tchunk* x, int size);
};

// Computes a bin index from size, then inserts chunk x into that bin's list or tree, splitting by size bits until a matching chunk or empty slot is found.
// @fnv 0x00dd8010
void TargetClass::InsertChunk(tchunk* pChunk, int size)
{
    tchunk** ppBin;
    int index;
    index = FUN_00dd7e00(size);
    ppBin = &m_apChunkLists[index];
    pChunk->index = index;
    pChunk->child[0] = pChunk->child[1] = 0;
    if ((m_uiChunkCount & (1U << index)) == 0)
    {
        m_uiChunkCount |= (1U << index);
        *ppBin = pChunk;
        pChunk->parent = (tchunk*)ppBin;
        pChunk->fd = pChunk;
        pChunk->bk = pChunk;
    }
    else
    {
        tchunk* pTree = *ppBin;
        int shift = (index == 0x1f) ? 0 : (0x19 - (index >> 1));
        unsigned int uiBits = (unsigned int)size << shift;
        for (;;)
        {
            if ((pTree->head & ~3) != size)
            {
                tchunk** ppChild = &pTree->child[uiBits >> 31];
                uiBits += uiBits;
                if (*ppChild != 0)
                {
                    pTree = *ppChild;
                }
                else
                {
                    *ppChild = pChunk;
                    pChunk->parent = pTree;
                    pChunk->fd = pChunk;
                    pChunk->bk = pChunk;
                    break;
                }
            }
            else
            {
                tchunk* pNext = pTree->fd;
                pNext->bk = pChunk;
                pTree->fd = pChunk;
                pChunk->bk = pTree;
                pChunk->fd = pNext;
                pChunk->parent = 0;
                break;
            }
        }
    }
}

struct FUN_00dd80d0_node
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00dd80d0_node* m_pSecondNode;  // +0x08
    FUN_00dd80d0_node* m_next;         // +0x0c
    FUN_00dd80d0_node* m_fMinimumU;    // +0x10
    FUN_00dd80d0_node* m_fMaximumU;    // +0x14
    FUN_00dd80d0_node* m_parent;       // +0x18
    unsigned int m_bin;                // +0x1c
};

struct FUN_00dd80d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_freeMask;  // +0x08
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00dd80d0_node* m_bins[32];  // +0x18
    void RemoveNode(FUN_00dd80d0_node* node);
};

// Unlinks node from its sibling list or replaces it with a successor in the tree, then detaches it from its bin and reattaches its children to the replacement.
// @fnv 0x00dd80d0
void FUN_00dd80d0_cls::RemoveNode(FUN_00dd80d0_node* node)
{
    FUN_00dd80d0_node* next = node->m_next;
    FUN_00dd80d0_node* tree = node->m_parent;
    FUN_00dd80d0_node* r;

    if (next != node)
    {
        FUN_00dd80d0_node* prev = node->m_pSecondNode;
        prev->m_next = next;
        next->m_pSecondNode = prev;
        r = next;
    }
    else
    {
        FUN_00dd80d0_node** slot = &node->m_fMaximumU;
        r = node->m_fMaximumU;
        if (r == 0)
        {
            r = node->m_fMinimumU;
            slot = &node->m_fMinimumU;
        }
        if (r != 0)
        {
            for (;;)
            {
                FUN_00dd80d0_node** cur = &r->m_fMaximumU;
                if (r->m_fMaximumU == 0)
                {
                    cur = &r->m_fMinimumU;
                    if (r->m_fMinimumU == 0)
                    {
                        *slot = 0;
                        break;
                    }
                }
                r = *cur;
                slot = cur;
            }
        }
    }

    if (tree != 0)
    {
        unsigned int bin = node->m_bin;
        FUN_00dd80d0_node** head = &this->m_bins[bin];
        if (node == *head)
        {
            *head = r;
            if (r == 0)
            {
                this->m_freeMask &= ~(1u << node->m_bin);
                return;
            }
        }
        else
        {
            if (tree->m_fMinimumU == node)
            {
                tree->m_fMinimumU = r;
            }
            else
            {
                tree->m_fMaximumU = r;
            }
            if (r == 0)
            {
                return;
            }
        }
        r->m_parent = tree;
        FUN_00dd80d0_node* left = node->m_fMinimumU;
        if (left != 0)
        {
            r->m_fMinimumU = left;
            left->m_parent = r;
        }
        FUN_00dd80d0_node* right = node->m_fMaximumU;
        if (right != 0)
        {
            r->m_fMaximumU = right;
            right->m_parent = r;
        }
    }
}

struct FUN_00dd83a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_10;
    unsigned int m_14;
    void FUN_00dd83a0();
};

// @fnv 0x00dd83a0
void FUN_00dd83a0_cls::FUN_00dd83a0()
{
    *(unsigned int*)(m_10 + 4) = m_14 | 1;
    *(unsigned int*)(m_10 + m_14) = m_14;
}

struct hkBlockAllocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char* m_next;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    void* AllocateBlock(int a);
};

// Advances the allocator's counters and next pointer by a, writes size and flags into the new block header, and returns the previous block's payload.
// @fnv 0x00dd83c0
void* hkBlockAllocator::AllocateBlock(int aiSize)
{
    unkBC += aiSize;
    unkC0 += aiSize - 0x10;
    unk14 -= aiSize;
    char* pBlock = m_next;
    int flags = unk14 | 1;
    char* node = pBlock + aiSize;
    m_next = node;
    *(int*)node = aiSize;
    *(int*)(node + 4) = flags;
    *(int*)(pBlock + 4) = aiSize | 3;
    return pBlock + 0x10;
}

struct FUN_00dd8480_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    int unk10;
    unsigned int m_14;
    int AllocSlow(int a);
    int Allocate(int a);
};

int __stdcall ProbeSmall(int a);

// Tries ProbeSmall when m_08 is set, then AllocSlow if a+0x100 is below m_14, otherwise returns 0.
// @fnv 0x00dd8480
int FUN_00dd8480_cls::Allocate(int aiSize)
{
    if (m_08 != 0)
    {
        int r = ProbeSmall(aiSize);
        if (r != 0)
        {
            return r;
        }
    }
    if ((unsigned int)(aiSize + 0x100) < m_14)
    {
        return AllocSlow(aiSize);
    }
    return 0;
}

struct hkMemoryAllocator
{
    virtual void* unk00() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

struct hkMemoryManager
{
    virtual void* unk00() = 0;
    virtual void* unk04() = 0;
    virtual void* unk08() = 0;
    virtual void* unk0c() = 0;
    virtual void* unk10() = 0;
    virtual void* unk14() = 0;
    virtual void* unk18() = 0;
    virtual void* unk1c() = 0;
    virtual void* unk20() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

struct FUN_00dd8700_cls : public hkMemoryAllocator
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    hkMemoryManager* unk98;

    void* FUN_00dd8700(unsigned int size);
};

// Rounds size up to a 16-byte multiple, allocates it via this allocator or unk98, writes a tag at the start and returns the block offset by 0x10.
// @fnv 0x00dd8700
void* FUN_00dd8700_cls::FUN_00dd8700(unsigned int size)
{
    unsigned int uiAlignedSize = (size + 0x1fu) & 0xfffffff0u;
    void* block = allocate(uiAlignedSize);

    if (block != 0)
    {
        *static_cast<int*>(block) = 1;
        return static_cast<unsigned char*>(block) + 0x10;
    }

    block = unk98->allocate(uiAlignedSize);

    if (block != 0)
    {
        *static_cast<int*>(block) = 0;
        return static_cast<unsigned char*>(block) + 0x10;
    }

    return 0;
}

struct Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void V28(void* apBlock, unsigned int auiSize);
};

struct FUN_00dd8750_cls
{
    virtual void v00();
    virtual void v04();
    virtual void V08(void* apBlock);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    Heap* m_pHeap;

    void FUN_00dd8750(void* apBlock, unsigned int auiSize);
};

// @fnv 0x00dd8750
void FUN_00dd8750_cls::FUN_00dd8750(void* apBlock, unsigned int auiSize)
{
    int iCount = *(int*)((char*)apBlock - 0x10);
    switch (iCount)
    {
    case 0:
        m_pHeap->V28((char*)apBlock - 0x10, (auiSize + 0x1f) & 0xfffffff0);
        break;
    case 1:
        V08((char*)apBlock - 0x10);
        break;
    }
}

namespace fnv_00dd8790 {
struct FUN_00dd8790_hdr
{
    unsigned int m_00;
    unsigned int m_04;
};
struct FUN_00dd8790_node
{
    FUN_00dd8790_node* m_00;
    FUN_00dd8790_node* m_04;
    int unk08;
    void* m_0c;
    FUN_00dd8790_hdr* m_10;
    char* m_14;
};
struct FUN_00dd8790_owner
{
    virtual void v00();
    virtual unsigned char* v04(unsigned char* out);
    virtual void v08();
    virtual void v0c();
    virtual void v10(FUN_00dd8790_node* node, void* data);
};
struct FUN_00dd8790_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dd8790_hdr* m_10;
    unsigned int m_14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    FUN_00dd8790_owner* m_98;
    int m_9c;
    int unka0;
    FUN_00dd8790_node m_a4;

    void PurgeAndSelectBlock();
};

struct FUN_00dd83a0_cls
{
    void FUN_00dd83a0();
};
struct FUN_00dd80d0_cls
{
    void RemoveNode(FUN_00dd8790_hdr* h);
};
struct FUN_00dd8010_cls
{
    void InsertChunk(FUN_00dd8790_hdr* h, unsigned int n);
};
struct FUN_00dd8400_cls
{
    void ResizeSegment(unsigned char* p, unsigned int n);
};

// @fnv 0x00dd8790
void FUN_00dd8790_cls::PurgeAndSelectBlock()
{
    ((FUN_00dd83a0_cls*)this)->FUN_00dd83a0();
    FUN_00dd8790_node* sentinel = &m_a4;
    FUN_00dd8790_node* n = m_a4.m_04;
    if (n != sentinel)
    {
        do
        {
            FUN_00dd8790_hdr* h = n->m_10;
            unsigned int uSize = h->m_04;
            if ((((unsigned char)(uSize >> 1)) & 1) == 0 && (char*)h + (uSize & 0xfffffffcu) == (char*)n->m_14 - 0x10)
            {
                FUN_00dd8790_node* nx = n->m_04;
                n->m_00->m_04 = nx;
                n->m_04->m_00 = n->m_00;
                if (h == m_10)
                {
                    m_10 = (FUN_00dd8790_hdr*)&m_9c;
                    m_14 = 0;
                }
                else
                {
                    ((FUN_00dd80d0_cls*)this)->RemoveNode(h);
                }
                m_98->v10(n, n->m_0c);
                n = nx;
            }
            else
            {
                n = n->m_04;
            }
        } while (n != sentinel);
    }
    if (m_a4.m_04 == sentinel)
    {
        m_10 = (FUN_00dd8790_hdr*)&m_9c;
        m_14 = 0;
        return;
    }
    unsigned char b;
    unsigned char* flag = m_98->v04(&b);
    if (*flag != 0)
    {
        if (m_14 < 0x8000)
        {
            return;
        }
        FUN_00dd8790_node* head = m_a4.m_04;
        ((FUN_00dd8400_cls*)this)->ResizeSegment(&b, (unsigned int)m_10 - (unsigned int)head->m_10 + 0x120);
        return;
    }
    FUN_00dd8790_hdr* cur = m_10;
    if (cur != (FUN_00dd8790_hdr*)&m_9c)
    {
        ((FUN_00dd8010_cls*)this)->InsertChunk(cur, m_14);
        m_10 = (FUN_00dd8790_hdr*)&m_9c;
        m_14 = 0;
    }
    n = m_a4.m_04;
    FUN_00dd8790_hdr* best = 0;
    if (n != sentinel)
    {
        do
        {
            FUN_00dd8790_hdr* h = (FUN_00dd8790_hdr*)((char*)n->m_14 - 0x10);
            if ((h->m_04 & 1) == 0)
            {
                h = (FUN_00dd8790_hdr*)((char*)h - h->m_00);
                if (best == 0 || (h->m_04 & 0xfffffffcu) > (best->m_04 & 0xfffffffcu))
                {
                    best = h;
                }
            }
            n = n->m_04;
        } while (n != sentinel);
    }
    if (best != 0)
    {
        ((FUN_00dd80d0_cls*)this)->RemoveNode(best);
        m_10 = best;
        m_14 = best->m_04 & 0xfffffffcu;
        return;
    }
    m_10 = (FUN_00dd8790_hdr*)&m_9c;
    m_14 = 0;
}
}  // namespace fnv_00dd8790

struct BlockPage
{
    unsigned int unk00;
    BlockPage* next;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int start;
    unsigned int end;
};

struct FUN_00dd8910_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    unsigned int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0;
    BlockPage m_kPage;
    bool* IsChunkInPageList(bool* result, char* mem);
};

// Checks that mem is 16-byte aligned, its header flag is set, and the chunk lies in a listed page's chunk chain; writes the result to result.
// @fnv 0x00dd8910
bool* FUN_00dd8910_cls::IsChunkInPageList(bool* result, char* mem)
{
    unsigned int addr = (unsigned int)mem;
    if ((addr & 0xf) != 0)
    {
        *result = false;
        return result;
    }
    char* chunk = mem - 16;
    unsigned int head = *(unsigned int*)(chunk + 4);
    unsigned char flag = (unsigned char)(head >> 1);
    if ((flag & 1) == 0)
    {
        *result = false;
        return result;
    }
    BlockPage* page = m_kPage.next;
    BlockPage* sentinel = &m_kPage;
    unsigned int start = 0;
    unsigned int end = 0;
    if (page == sentinel)
    {
        goto fail;
    }
    for (;;)
    {
        start = page->start;
        end = page->end;
        if (addr >= start && addr < end)
        {
            break;
        }
        page = page->next;
        if (page == sentinel)
        {
            goto fail;
        }
    }
    char* last = (char*)end - 16;
    char* c = (char*)start;
    if (c == last)
    {
        goto fail;
    }
    do
    {
        if (c == chunk)
        {
            goto ok;
        }
        c += (*(unsigned int*)(c + 4)) & ~3u;
    } while (c != last);
fail:
    *result = false;
    return result;
ok:
    *result = true;
    return result;
}

struct S_00dd8b20_Ref
{
    int unk00;
    int unk04;
};
struct S_00dd8b20_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int key;
    int size;
};
struct S_00dd8b20_Ret
{
    int key;
    S_00dd8b20_Node* node;
    int size;
    S_00dd8b20_Ret()
    {}
};
struct FUN_00dd8b20_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00dd8b20_Ref* m10;
    unsigned m14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    S_00dd8b20_Node* ma8;
    S_00dd8b20_Ret FUN_00dd8b20();
};
// @fnv 0x00dd8b20
S_00dd8b20_Ret FUN_00dd8b20_cls::FUN_00dd8b20()
{
    S_00dd8b20_Ret r;
    m10->unk04 = m14 | 1;
    S_00dd8b20_Node* n = ma8;
    if (n == (S_00dd8b20_Node*)&unka4)
    {
        r.key = 0;
        return r;
    }
    r.key = n->key;
    r.node = n;
    r.size = n->size - 0x10;
    return r;
}

struct FUN_00dd8df0_cls
{
    int unk00;

    void FUN_00dd7ec0();
    FUN_00dd8df0_cls* FUN_00dd8df0(int arg);
};

// @fnv 0x00dd8df0
FUN_00dd8df0_cls* FUN_00dd8df0_cls::FUN_00dd8df0(int arg)
{
    FUN_00dd7ec0();
    return this;
}

struct SpanSegment
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_kRayEnd;
    unsigned int unk10;
    unsigned int m_iElementCount;
};

struct SpanServer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual unsigned char* resize(unsigned int* sizePtr, SpanSegment* seg, unsigned int end, unsigned int size,
                                  unsigned int* newEnd);
};

struct hkBool
{
    bool m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
};

struct FUN_00dd8400_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_base;
    unsigned int m_fMinimumV;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    SpanServer* m_pServer;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    SpanSegment* m_seg;
    hkBool ResizeSegment(unsigned int size);
};

// @fnv 0x00dd8400
hkBool FUN_00dd8400_cls::ResizeSegment(unsigned int size)
{
    SpanSegment* seg = m_seg;
    unsigned int slot;
    unsigned char* result = m_pServer->resize(&size, seg, seg->m_kRayEnd, size, &slot);
    if (*result == 0)
    {
        return hkBool(false);
    }
    unsigned int header = *(unsigned int*)(m_base + m_fMinimumV + 4) & 0xfffffffcu;
    unsigned int delta = slot - seg->m_kRayEnd;
    delta &= 0xfffffff0u;
    unsigned int newEnd = slot;
    m_fMinimumV = m_fMinimumV + delta;
    seg->m_iElementCount = seg->m_iElementCount + delta;
    seg->m_kRayEnd = newEnd;
    *(unsigned int*)(m_base + m_fMinimumV + 4) = (header - delta) | 2u;
    return hkBool(true);
}

struct AllocatorListener
{
    virtual void v00() = 0;
    virtual void v04(unsigned int size) = 0;
    virtual void v08(unsigned int size) = 0;
};

struct MemoryProvider
{
    virtual void v00() = 0;
    virtual hkBool canExtend() = 0;
    virtual unsigned int v08(unsigned int sizeNeeded) = 0;
    virtual S_00dd8aa0_Page* v0c(unsigned int size, unsigned int* actualSize) = 0;
};

struct Allocator_dd84c0
{
    void* m_vtbl;
    AllocatorListener* m_kListener;
    int unk08;
    int unk0c;
    S_00dd8aa0_Chunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    MemoryProvider* m_provider;
    int unk9c;
    int unka0;
    S_00dd8aa0_Page m_kPage;

    void* Allocate(unsigned int size);
    hkBool ResizeSegment(unsigned int newSize);
    void* AllocateBlock(unsigned int size);
    void FUN_00dd83a0();
    void InsertChunk(void* chunk, unsigned int size);

    void* alloc(unsigned int size);
};

inline char* alignUp(char* p)
{
    return (char*)(((int)p + 15) & -16);
}

inline void alignEnd(char*& p)
{
    *(unsigned int*)&p &= ~15;
}

// Rounds the requested size, tries allocation, then may extend the segment or request a page before allocating.
// @fnv 0x00dd84c0
void* Allocator_dd84c0::alloc(unsigned int size)
{
    unsigned int uiAlignedSize;
    uiAlignedSize = (size + 31) & ~15;
    if (uiAlignedSize < 256)
    {
        uiAlignedSize = 256;
    }

    void* pAllocated;
    pAllocated = this->Allocate(uiAlignedSize);
    if (pAllocated)
    {
        return pAllocated;
    }

    if (this->m_provider->canExtend().m_cBooleanValue)
    {
        S_00dd8aa0_Page* pNextPage;
        pNextPage = this->m_kPage.m_next;
        if (pNextPage != &this->m_kPage)
        {
            if (this->ResizeSegment(pNextPage->unkC + uiAlignedSize).m_cBooleanValue)
            {
                return this->AllocateBlock(uiAlignedSize);
            }
            if (this->m_kListener)
            {
                this->m_kListener->v04(uiAlignedSize);
                void* prev;
                prev = this->Allocate(uiAlignedSize);
                if (prev)
                {
                    return prev;
                }
                if (this->ResizeSegment(uiAlignedSize + pNextPage->unkC).m_cBooleanValue)
                {
                    return this->AllocateBlock(uiAlignedSize);
                }
                this->m_kListener->v08(uiAlignedSize);
            }
            return 0;
        }
    }

    S_00dd8aa0_Page* pNewPage;
    int i;
    i = uiAlignedSize + 0x138;
    unsigned int start;
    start = this->m_provider->v08(i);
    pNewPage = this->m_provider->v0c(start, &start);
    if (!pNewPage)
    {
        if (this->m_kListener)
        {
            this->m_kListener->v04(uiAlignedSize);
            void* prev;
            prev = this->Allocate(uiAlignedSize);
            if (prev)
            {
                return prev;
            }
            start = this->m_provider->v08(i);
            pNewPage = this->m_provider->v0c(start, &start);
            if (!pNewPage)
            {
                this->m_kListener->v08(uiAlignedSize);
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    char* kIter = (char*)pNewPage + 0x18;
    pNewPage->unk8 = 0;
    pNewPage->unkC = start;
    pNewPage->m_kRayStart = kIter;
    kIter = alignUp(kIter);
    pNewPage->m_kRayEnd = (char*)pNewPage + start;
    pNewPage->m_kRayStart = kIter;
    *(unsigned int*)&pNewPage->m_kRayEnd &= ~15u;

    S_00dd8aa0_Page* q;
    q = this->m_kPage.m_next;
    while (q != &this->m_kPage && q < pNewPage)
    {
        q = q->m_next;
    }
    pNewPage->m_next = q;
    S_00dd8aa0_Page* pPrev;
    pPrev = q->m_pSecondNode;
    pNewPage->m_pSecondNode = pPrev;
    pPrev->m_next = pNewPage;
    q->m_pSecondNode = pNewPage;

    if (this->m_fMinimumV != (S_00dd8aa0_Chunk*)&this->unk9c)
    {
        this->FUN_00dd83a0();
        this->InsertChunk(this->m_fMinimumV, this->m_fMinimumV->head & ~3);
    }

    this->m_uiChunkSize = (pNewPage->m_kRayEnd - pNewPage->m_kRayStart) - 0x10;
    this->m_fMinimumV = (S_00dd8aa0_Chunk*)pNewPage->m_kRayStart;
    this->FUN_00dd83a0();

    S_00dd8aa0_Chunk* endChunk;
    endChunk = (S_00dd8aa0_Chunk*)(pNewPage->m_kRayEnd - 0x10);
    endChunk->head = 2;
    if (pNewPage->m_next != &this->m_kPage)
    {
        endChunk->head = (pNewPage->m_next->m_kRayStart - (char*)endChunk) | 2;
    }

    S_00dd8aa0_Page* c;
    c = pNewPage->m_pSecondNode;
    if (c != &this->m_kPage)
    {
        S_00dd8aa0_Chunk* pPrevChunk;
        pPrevChunk = (S_00dd8aa0_Chunk*)(c->m_kRayEnd - 0x10);
        pPrevChunk->head = ((char*)this->m_fMinimumV - (char*)pPrevChunk) | (pPrevChunk->head & 3);
    }

    return this->AllocateBlock(uiAlignedSize);
}

struct S_dd8180_Chunk
{
    unsigned int unk00;
    unsigned int head;
    int unk08;
    int unk0c;
    S_dd8180_Chunk* child0;
    S_dd8180_Chunk* child1;
};

int __cdecl FUN_00dd7e00(unsigned int size);
int __cdecl FUN_00dd7e70(unsigned int bit);

struct S_dd8180_Alloc
{
    int unk00;
    int unk04;
    unsigned int treemap;
    int unk0c;
    int unk10;
    int unk14;
    S_dd8180_Chunk* bins[32];
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    unsigned int footprint;
    unsigned int used;
    void RemoveNode(S_dd8180_Chunk* c);
    void InsertChunk(S_dd8180_Chunk* c, unsigned int size);
    void* FUN_00dd8180(unsigned int nb);
};

// Finds the best-fit free chunk for nb bytes, splits it if the remainder is large enough, and returns a pointer to the allocated block.
// @fnv 0x00dd8180
void* S_dd8180_Alloc::FUN_00dd8180(unsigned int uiSize)
{
    S_dd8180_Chunk* t;
    S_dd8180_Chunk* pBest = 0;
    unsigned long uiRemainder = 0 - uiSize;
    int idx = 0;
    idx = FUN_00dd7e00(uiSize);
    t = bins[idx];
    if (t != 0)
    {
        unsigned int sizebits = uiSize << ((idx == 31) ? 0 : (25 - (idx >> 1)));
        S_dd8180_Chunk* pRight = 0;
        for (;;)
        {
            unsigned int trem = (t->head & 0xfffffffc) - uiSize;
            if (trem < uiRemainder)
            {
                pBest = t;
                uiRemainder = trem;
                if (uiRemainder == 0)
                    break;
            }
            S_dd8180_Chunk* right = t->child1;
            t = (&t->child0)[(sizebits >> 31) & 1];
            if (right != 0 && right != t)
                pRight = right;
            if (t == 0)
            {
                t = pRight;
                break;
            }
            sizebits <<= 1;
        }
    }
    if (t == 0 && pBest == 0)
    {
        unsigned int leftbit = (1u << idx) << 1;
        unsigned int leftbits = (leftbit | (0 - leftbit)) & treemap;
        if (leftbits != 0)
        {
            unsigned int leastbit = leftbits & (0 - leftbits);
            t = bins[FUN_00dd7e70(leastbit)];
        }
    }
    while (t != 0)
    {
        unsigned int trem = (t->head & 0xfffffffc) - uiSize;
        if (trem < uiRemainder)
        {
            uiRemainder = trem;
            pBest = t;
        }
        t = t->child0 ? t->child0 : t->child1;
    }
    if (pBest == 0)
        return 0;
    S_dd8180_Chunk* pRemainder = (S_dd8180_Chunk*)((char*)pBest + uiSize);
    RemoveNode(pBest);
    if (uiRemainder < 0x100)
    {
        unsigned int total = uiRemainder + uiSize;
        pBest->head = total | 3;
        S_dd8180_Chunk* nx = (S_dd8180_Chunk*)((char*)pBest + total);
        nx->head |= 1;
        footprint += uiRemainder + uiSize;
        used += uiRemainder + uiSize - 0x10;
    }
    else
    {
        pBest->head = uiSize | 3;
        footprint += uiSize;
        used += uiSize - 0x10;
        pRemainder->head = uiRemainder | 1;
        *(unsigned int*)((char*)pRemainder + uiRemainder) = uiRemainder;
        InsertChunk(pRemainder, uiRemainder);
    }
    return (char*)pBest + 0x10;
}

struct FUN_00dd7de0
{
    virtual ~FUN_00dd7de0();
};
// @fnv 0x00dd7de0
FUN_00dd7de0::~FUN_00dd7de0()
{}

namespace fnv_00dd7e00 {
// FUN_00dd7e00: fast 2*log2-style bit scan of (x >> 8).

// Shifts and tests bits of x, returning 0, 0x1f, or a value computed from the shifted bits.
// @fnv 0x00dd7e00
unsigned int __cdecl FUN_00dd7e00(unsigned int x)
{
    unsigned int hi = x >> 8;
    if (hi == 0)
    {
        return 0;
    }
    if (hi > 0xffff)
    {
        return 0x1f;
    }
    unsigned int a = ((hi - 0x100) >> 16) & 8;
    unsigned int e = hi << a;
    a += ((e - 0x1000) >> 16) & 4;
    e = e << ((e - 0x1000) >> 16 & 4);
    unsigned int c = ((e - 0x4000) >> 16) & 2;
    e = e << c;
    int r = (int)(e >> 15) - (int)c - (int)a + 0xe;
    return (unsigned int)(2 * r) + ((x >> (r + 7)) & 1);
}
}  // namespace fnv_00dd7e00

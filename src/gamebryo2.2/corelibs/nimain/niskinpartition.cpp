// gamebryo2.2/corelibs/nimain/niskinpartition.cpp: NiAccumulator, Partition, Holder, MyCls and more (36 functions)

#include "niskinpartition_decls.h"
// @fnv 0x00d47a40
void NiAccumulator::SetSortingCamera(const NiCamera* camera)
{
    m_pkAccumulationCamera = camera;
}
// Sums the strip lengths in m_pusStripLengths over m_usStrips entries and returns the total.
// @fnv 0x00a81c20
unsigned int NiSkinPartition::Partition::GetStripIndexCount()
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < m_usStrips; ++i)
        sum += m_pusStripLengths[i];
    return sum;
}

const void* g_011f5b1c;

// @fnv 0x00a820d0
const void* __cdecl FUN_00a820d0()
{
    return &g_011f5b1c;
}

// @fnv 0x00a82600
void __stdcall FUN_00a82600(int pTarget, int b, float c)
{
    *(float*)(pTarget + 8) = c;
    *(int*)(pTarget + 4) = b;
}

struct Holder
{
    unsigned short* m_pusData;
    unsigned int m_u4;
    unsigned int m_uiCount;
    bool ContainsSortedSubset(const Holder* pkOther);
};
// @fnv 0x00a82190
bool Holder::ContainsSortedSubset(const Holder* pkOther)
{
    unsigned int uiSrc = 0;
    for (unsigned int uiDst = 0; uiDst < pkOther->m_uiCount; ++uiDst)
    {
        while (uiSrc < m_uiCount && m_pusData[uiSrc] < pkOther->m_pusData[uiDst])
            ++uiSrc;
        if (uiSrc == m_uiCount)
            return false;
        if (m_pusData[uiSrc] != pkOther->m_pusData[uiDst])
            return false;
        ++uiSrc;
    }
    return true;
}

struct NiRefObject
{
    virtual ~NiRefObject();
};
struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
};
extern int DAT_0109e47c;
struct P03MM
{
    void __thiscall _DeallocateAlias(void* p);
};
extern P03MM g_memoryManager;
struct S : NiRefObject
{
    int f4;
    int f8;
    void* fC;
    void __thiscall FUN_00a824d0();
};
// @fnv 0x00a824d0
void __thiscall S::FUN_00a824d0()
{
    *(void**)this = (void*)&DAT_0109e47c;
    if (NiRenderer::ms_pRenderer)
        ((void(__thiscall*)(NiRenderer*, void*))(*(void***)NiRenderer::ms_pRenderer)[64])(NiRenderer::ms_pRenderer,
                                                                                          this);
    void* p = fC;
    if (p)
    {
        void* a = (char*)p - 4;
        if (*(int*)a != 0)
            (*(void(__thiscall**)(void*, int)) * (void**)p)(p, 3);
        else
            g_memoryManager._DeallocateAlias(a);
    }
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}

struct NiTAbstractPoolAllocator_unsigned_int
{
    struct LinkedListEntry* ms_pFreeList;
    struct RecursiveSpinLock* ms_kPoolState;
};
struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
};
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern NiTAbstractPoolAllocator_unsigned_int NiTAbstractPoolAllocator_unsigned_int_instance;
// @fnv 0x00a82620
void __stdcall PoolFreeUIntNode(void* apNode)
{
    *(float*)((char*)apNode + 8) = 0.0f;
    g_011c5f80.Lock(0);
    *(int*)((char*)apNode + 4) = 0;
    *(void***)apNode = *(void***)&NiTAbstractPoolAllocator_unsigned_int_instance.ms_pFreeList;
    --DAT_011c5f84;
    *(void***)&NiTAbstractPoolAllocator_unsigned_int_instance.ms_pFreeList = (void**)apNode;
    if (!DAT_011c5f84)
        *(unsigned int*)&g_011c5f80 = 0;
}

namespace fnv_00a82670 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
void _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_0109e50c;
struct S0082670
{
    void* Destroy(unsigned int);
};
// Sets the vtable, removes all map entries, frees the pointer at offset 8, and deallocates this when f has bit 0 set.
// @fnv 0x00a82670
void* S0082670::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109e50c;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a82670

void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFreeAlias(void*);

struct FUN_00a82710_shell
{
    void* m_p;
    unsigned int m_iElementCount;
    unsigned int m_uiItemCount;
    void FUN_00a82710(unsigned int n);
};

// @fnv 0x00a82710
void FUN_00a82710_shell::FUN_00a82710(unsigned int n)
{
    if (n != m_iElementCount)
    {
        void* p;
        if (n > 0)
        {
            p = NiMalloc(n * 2);
            for (unsigned int i = 0; i < m_uiItemCount; ++i)
                ((unsigned short*)p)[i] = ((unsigned short*)m_p)[i];
        }
        else
            p = 0;
        NiFreeAlias(m_p);
        m_p = p;
        m_iElementCount = n;
    }
}

struct FUN_00a82890_shell
{
    char __thiscall ContainsAllValues(void*);
    char __thiscall FUN_00a82890(const unsigned short* a, const void* b);
};

// Calls ContainsAllValues on three offsets into b taken from a, returning 0 if any call fails and 1 otherwise.
// @fnv 0x00a82890
char __thiscall FUN_00a82890_shell::FUN_00a82890(const unsigned short* a, const void* apBase)
{
    for (unsigned int i = 0; i < 3; ++i)
        if (!ContainsAllValues((char*)apBase + a[i] * 12))
            return 0;
    return 1;
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00a82c70_holder
{
    void FUN_00a824d0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a824d0, then deletes this with size 0x10 when bit 0 of a is set, and returns this.
// @fnv 0x00a82c70
void* FUN_00a82c70_holder::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00a824d0();
    if (auiFlags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00a82cf0 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern int DAT_0109e50c;
extern int DAT_0109e52c;
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct S_00a82cf0
{
    void* FUN_00a82cf0(unsigned int);
};
// Resets two vtable pointers, clears both maps, frees the pointer at offset 8, and deallocates this when f has bit 0 set.
// @fnv 0x00a82cf0
void* S_00a82cf0::FUN_00a82cf0(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109e52c;
    ((NiTMapBaseStub*)this)->RemoveAll();
    *(void**)this = (void*)&DAT_0109e50c;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a82cf0

struct C082d30
{
    unsigned short* f0;
    unsigned int f4;
    unsigned int f8;
    void FUN_00a82710(unsigned int);
    void AppendMatchingIndices(int, int*, unsigned int);
};
// Scans the first c entries of b and appends the index of each entry equal to a to f0, growing the buffer via FUN_00a82710 when full.
// @fnv 0x00a82d30
void C082d30::AppendMatchingIndices(int aiValue, int* paiValues, unsigned int c)
{
    for (unsigned int i = 0; i < c; ++i)
    {
        if (paiValues[i] == aiValue)
        {
            if (f8 == f4)
            {
                unsigned int n;
                if (f4 > 0)
                    n = f4 * 2;
                else
                    n = 1;
                FUN_00a82710(n);
            }
            f0[f8++] = (unsigned short)i;
        }
    }
}

struct Dummy13
{
    int v[13];
};
struct MyCls
{
    void* vf;
    int _04;
    int _08;
    Dummy13 _0c;
    int _40;
    int _44;
    void _Call_a5d3a0();
    void FUN_00a853c0(int);
    MyCls* InitFromData(int, int, const Dummy13&, int);
};
extern int DAT_0109e574;
int __cdecl FUN_00a853c0();
// Initialises the object: sets the vtable, clears _08, copies a3 into _0c, stores a2 and a1, then calls FUN_00a853c0(a4) and returns this.
// @fnv 0x00a854c0
MyCls* MyCls::InitFromData(int a1, int a2, const Dummy13& aData, int a4)
{
    _Call_a5d3a0();
    vf = (void*)&DAT_0109e574;
    _08 = 0;
    _0c = aData;
    _40 = a2;
    _44 = a1;
    FUN_00a853c0(a4);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFree(void*);

struct FUN_00a826b0_shell
{
    void* m_p;
    unsigned int m_uiItemCount;
    unsigned int m_uiBufferCapacity;
    void FUN_00a826b0(unsigned int n);
};

// @fnv 0x00a826b0
void FUN_00a826b0_shell::FUN_00a826b0(unsigned int n)
{
    if (n == m_uiItemCount)
        return;
    void* p;
    if (n > 0)
    {
        p = _NiMalloc(n * 8);
        unsigned int i = 0;
        if (m_uiBufferCapacity > 0)
        {
            do
            {
                unsigned int* src = (unsigned int*)m_p;
                unsigned int* dst = (unsigned int*)p;
                dst[i * 2] = src[i * 2];
                dst[i * 2 + 1] = src[i * 2 + 1];
                ++i;
            } while (i < m_uiBufferCapacity);
        }
    }
    else
    {
        p = 0;
    }
    _NiFree(m_p);
    m_p = p;
    m_uiItemCount = n;
}

struct FUN_00a81ff0_elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    bool FUN_00a81c90(const FUN_00a81ff0_elem* other);
};

struct FUN_00a81ff0_cls
{
    int m_00;
    int m_04;
    unsigned int m_uiItemCount;
    FUN_00a81ff0_elem* m_pElements;
    bool IsSameAs(const FUN_00a81ff0_cls* other);
    bool Equals(const FUN_00a81ff0_cls* other);
};

// @fnv 0x00a81ff0
bool FUN_00a81ff0_cls::Equals(const FUN_00a81ff0_cls* other)
{
    if (!IsSameAs(other))
        return false;
    unsigned int count = m_uiItemCount;
    if (count != other->m_uiItemCount)
        return false;
    unsigned int i = 0;
    if (count > 0)
    {
        FUN_00a81ff0_elem* a = m_pElements;
        int iOffset = (int)other->m_pElements - (int)m_pElements;
        do
        {
            if (!a->FUN_00a81c90((FUN_00a81ff0_elem*)((int)a + iOffset)))
                return false;
            i++;
            a++;
        } while (i < count);
    }
    return true;
}

struct S_00a82050_Node
{
    S_00a82050_Node* pNext;
    int iValue;
    float fValue;
};

struct S_00a82050_Base
{
    virtual ~S_00a82050_Base();
};

struct S_00a82050_Class : S_00a82050_Base
{
    void* p04;
    S_00a82050_Node** ppNodes;
    unsigned int uCount;

    virtual int __thiscall GetIndex(int);
    virtual bool __thiscall Compare(int, int);
    virtual void __thiscall Initialize(S_00a82050_Node*, int, float);
    virtual void Unknown();
    virtual S_00a82050_Node* __thiscall GetNode();

    void __thiscall FUN_00a82050(int, float);
};

S_00a82050_Base::~S_00a82050_Base()
{}

// Looks up the node matching iArg in the bucket at GetIndex(iArg) and sets its fValue to fArg, or inserts a new node at the bucket head and increments uCount.
// @fnv 0x00a82050
void __thiscall S_00a82050_Class::FUN_00a82050(int aiKey, float afValue)
{
    int iIndex;
    S_00a82050_Node* pNode;

    iIndex = GetIndex(aiKey);

    pNode = ppNodes[iIndex];
    if (pNode != 0)
    {
        do
        {
            if (Compare(aiKey, pNode->iValue))
            {
                pNode->fValue = afValue;
                return;
            }

            pNode = pNode->pNext;
        } while (pNode != 0);
    }

    pNode = GetNode();
    Initialize(pNode, aiKey, afValue);

    pNode->pNext = ppNodes[iIndex];
    ppNodes[iIndex] = pNode;
    ++uCount;
}

// Candidate reconstruction of ContainsAllValues (0x00a821f0, 83 bytes).
//
// What the original does (read from the image):
//   * ebx = the stack argument (a pointer to a block of 8-byte records),
//     ebp = ebx->unk08 (the number of records), esi = the record index,
//     edi = this.
//   * For every record it takes the 16-bit field at offset 0 of the record,
//     stores it into a 32-bit scratch slot that lives in the (by then dead)
//     incoming-argument slot, and hands the address of that slot to a CRT
//     binary-search helper together with this->unk00 (the array that is
//     searched), this->unk08 (its element count), the element size 2 and the
//     game's 16-bit comparison routine at 0x00a81b80.
//   * A record that is NOT found makes the function return 0; if every record
//     is found it returns 1.
//
// The helper and the comparison routine are declared but never defined, so the
// checker binds both call targets from the original's own bytes.

extern "C" void* __cdecl FNV_search_821f0(const void* key, const void* base, unsigned int count, unsigned int size,
                                          int(__cdecl* cmp)(const void*, const void*));

extern "C" int __cdecl FNV_cmp_us_821f0(const void* a, const void* b);

// One record of the list that is handed in: the 16-bit key sits at +0 and the
// record is eight bytes wide.
struct FNV_Rec_821f0
{
    unsigned short usVal;
    unsigned int unk04;
};

// The list handed in by the caller.
struct FNV_Arg_821f0
{
    FNV_Rec_821f0* unk00;
    unsigned int unk04;
    unsigned int unk08;
};

// The object that owns the array that is searched.
struct FNV_This_821f0
{
    unsigned short* m_pusData;
    unsigned int unk04;
    unsigned int m_uCount;
    char __thiscall ContainsAllValues(FNV_Arg_821f0* pArg);
};

// Returns 0 if any usVal in pArg's array is not found in m_pusData via binary search, otherwise 1.
// @fnv 0x00a821f0
char __thiscall FNV_This_821f0::ContainsAllValues(FNV_Arg_821f0* pArg)
{
    // The scratch slot that is handed to the search helper is address-taken, so
    // MSVC puts it in the dead incoming-argument slot of this frameless member
    // (that is where the original's "mov dword ptr [esp+0x28], ecx" lands).
    unsigned int key;
    unsigned int i;
    unsigned int count = pArg->unk08;

    for (i = 0; i < count; i++)
    {
        key = pArg->unk00[i].usVal;
        {
            // Reading the element count inside this inner scope is what makes
            // the count land in EAX and the array pointer in EDX, and it sinks
            // the store of the scratch slot below the whole argument-push
            // chain, i.e. right in front of the call.
            unsigned int uiSearchCount = m_uCount;
            if (FNV_search_821f0(&key, m_pusData, uiSearchCount, 2, FNV_cmp_us_821f0) == 0)
                return 0;
        }
    }
    return 1;
}

void* __cdecl NiMalloc(unsigned int);

struct TriIndexList
{
    unsigned short* m_pusTriangles;
};

struct GeomData
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void GetTriangleVertexIndices(unsigned short i, unsigned short& i0, unsigned short& i1,
                                          unsigned short& i2) const;
    int unk04;
    unsigned short m_usVertices;
};

struct PartitionEx : NiSkinPartition::Partition
{
    unsigned short* BuildVertexRemapTable(const TriIndexList& kTriangles, const GeomData* pkData);
};

// Builds an old-to-new vertex remap table from the partition's triangles, allocates the inverse new-to-old table, and stores the new vertex count.
// @fnv 0x00a822d0
unsigned short* PartitionEx::BuildVertexRemapTable(const TriIndexList& kTriangles, const GeomData* pkData)
{
    unsigned short* pusOldToNew;
    unsigned int uiVertices;
    uiVertices = pkData->m_usVertices;
    pusOldToNew = (unsigned short*)NiMalloc(uiVertices * sizeof(unsigned short));
    for (unsigned int i = 0; i < uiVertices; i++)
        pusOldToNew[i] = 0xffff;

    long lNew;
    lNew = 0;
    for (unsigned int i = 0; i < m_usTriangles; i++)
    {
        unsigned short ausTri[3];
        pkData->GetTriangleVertexIndices(kTriangles.m_pusTriangles[i], ausTri[0], ausTri[1], ausTri[2]);
        for (unsigned int j = 0; 3 > j; j++)
        {
            unsigned int uiOld;
            uiOld = ausTri[j];
            if (pusOldToNew[uiOld] == 0xffff)
                pusOldToNew[uiOld] = (unsigned short)(lNew++);
        }
    }

    m_pusSourceVertexIndices = (unsigned short*)NiMalloc(lNew * sizeof(unsigned short));
    m_usVertices = (unsigned short)lNew;
    for (unsigned int i = 0; i < uiVertices; i++)
    {
        if (pusOldToNew[i] != 0xffff)
            m_pusSourceVertexIndices[pusOldToNew[i]] = (unsigned short)i;
    }
    return pusOldToNew;
}

struct WeightedEntry
{
    void* key;
    float weight;
};
struct EntryGroup
{
    WeightedEntry* entries;
    unsigned int unk04;
    unsigned int count;
};
struct WeightedMapNode
{
    WeightedMapNode* next;
    void* key;
    float weight;
};
struct WeightedMap
{
    virtual void ReservedVirtual();
    virtual unsigned int HashKey(void* key);
    virtual bool KeysEqual(void* left, void* right);
    unsigned int unk04;
    WeightedMapNode** buckets;
    void FUN_00a82050(void* key, float weight);
};
// For each of three group indices, inserts each entry's key and weight into the map only if the key is absent or its stored weight is lower.
// @fnv 0x00a82530
void __stdcall MergeGroupWeights(WeightedMap* map, const unsigned short* groupIndices, EntryGroup* __restrict groups)
{
    for (unsigned int groupIndex = 0; groupIndex < 3; ++groupIndex)
    {
        EntryGroup* group = &groups[groupIndices[groupIndex]];
        unsigned int itemCount = group->count;
        for (unsigned int itemIndex = 0; itemIndex < itemCount; ++itemIndex)
        {
            void* key = group->entries[itemIndex].key;
            WeightedMapNode* node = map->buckets[map->HashKey(key)];
            while (node)
            {
                if (map->KeysEqual(key, node->key))
                {
                    volatile float previousWeight = node->weight;
                    if (!(previousWeight < group->entries[itemIndex].weight))
                        goto nextItem;
                    break;
                }
                node = node->next;
            }
            map->FUN_00a82050(key, group->entries[itemIndex].weight);
        nextItem:;
        }
    }
}

struct ItemSet
{
    void** m_items;
    unsigned int m_u4;
    unsigned int m_uiItemCount;
};

// Scans the item set for an entry whose flags byte equals key and whose FUN_00a82890 check succeeds, marking it and returning its index, or -1 if none match.
// @fnv 0x00a82c90
int __cdecl FindMatchingItem(ItemSet* pItemSet, const unsigned short* a2, const void* a3, unsigned char* flags,
                             unsigned char key)
{
    for (unsigned int i = 0; i < pItemSet->m_uiItemCount; ++i)
    {
        if (flags[i] == key)
        {
            void*& pItem = pItemSet->m_items[i];
            if (((FUN_00a82890_shell*)pItem)->FUN_00a82890(a2, a3))
            {
                flags[i] = 1;
                return (int)i;
            }
        }
    }
    return -1;
}

// FUN_00a833a0 : constructor of a three-dword value object; zeroes all members.

struct FUN_00a833a0_cls
{
    int m_i00;
    int m_i04;
    int m_i08;

    FUN_00a833a0_cls();
};

// @fnv 0x00a833a0
FUN_00a833a0_cls::FUN_00a833a0_cls()
{
    m_i00 = 0;
    m_i04 = 0;
    m_i08 = 0;
}

__forceinline bool EqualBuffers(const void* right, const void* left, unsigned int bytes)
{
    const unsigned int* second = (const unsigned int*)right;
    const unsigned int* first = (const unsigned int*)left;
    while (bytes >= 4)
    {
        if (*first != *second)
            return false;
        bytes -= 4;
        ++second;
        ++first;
    }
    const unsigned char* tailFirst = (const unsigned char*)first;
    const unsigned char* tailSecond = (const unsigned char*)second;
    if (bytes)
    {
        if (tailSecond[0] != tailFirst[0])
            return false;
        if (bytes > 1)
        {
            if (tailSecond[1] != tailFirst[1])
                return false;
            if (bytes > 2 && tailSecond[2] != tailFirst[2])
                return false;
        }
    }
    return true;
}
struct PartitionCompare : NiSkinPartition::Partition
{
    bool FUN_00a81c90(const PartitionCompare* other);
};
// @fnv 0x00a81c90
bool PartitionCompare::FUN_00a81c90(const PartitionCompare* other)
{
    if (m_usVertices != other->m_usVertices)
        return false;
    if (m_usTriangles != other->m_usTriangles)
        return false;
    if (m_usBoneCount != other->m_usBoneCount)
        return false;
    if (m_usStrips != other->m_usStrips)
        return false;
    if (m_usWeightsPerVertex != other->m_usWeightsPerVertex)
        return false;
    if (!EqualBuffers(other->m_pusBonePalette, m_pusBonePalette, m_usBoneCount * sizeof(unsigned short)))
        return false;
    if (!EqualBuffers(other->m_pusSourceVertexIndices, m_pusSourceVertexIndices, m_usVertices * sizeof(unsigned short)))
        return false;
    unsigned int count = m_usVertices * m_usWeightsPerVertex;
    if (!EqualBuffers(other->m_pfVertexWeights, m_pfVertexWeights, count * sizeof(float)))
        return false;
    if (!m_usStrips)
    {
        if (!EqualBuffers(other->m_pusTriList, m_pusTriList, m_usTriangles * 3 * sizeof(unsigned short)))
            return false;
    }
    else
    {
        if (!EqualBuffers(other->m_pusStripLengths, m_pusStripLengths, m_usStrips * sizeof(unsigned short)))
            return false;
        if (!EqualBuffers(other->m_pusTriList, m_pusTriList, GetStripIndexCount() * sizeof(unsigned short)))
            return false;
    }
    if ((m_pucBoneIndices == 0) != (other->m_pucBoneIndices == 0))
        return false;
    if (m_pucBoneIndices && !EqualBuffers(other->m_pucBoneIndices, m_pucBoneIndices, count))
        return false;
    return true;
}

struct CA82250IndexArray
{
    unsigned short* m_pusData;
    unsigned int unk04;
    unsigned int m_uiSize;

    unsigned short Get(unsigned int uiIndex) const
    {
        if (uiIndex < m_uiSize)
            return m_pusData[uiIndex];
        return 0xffff;
    }
};

class CA82250MergeIterator
{
  public:
    unsigned int m_uiFirstPos;
    unsigned int m_uiSecondPos;
    unsigned short m_usFirst;
    unsigned short m_usSecond;
    CA82250IndexArray* m_pkFirst;
    CA82250IndexArray* m_pkSecond;

    unsigned int GetNext();
};

// Returns the smaller of the two cached values, advancing the corresponding index array and refreshing the cached values.
// @fnv 0x00a82250
unsigned int CA82250MergeIterator::GetNext()
{
    if (m_usSecond < m_usFirst)
    {
        unsigned int uiResult = m_usSecond;
        m_usSecond = m_pkSecond->Get(++m_uiSecondPos);
        return uiResult;
    }

    unsigned int uiResult = m_usFirst;
    if (m_usSecond == m_usFirst)
        m_usSecond = m_pkSecond->Get(++m_uiSecondPos);
    m_usFirst = m_pkFirst->Get(++m_uiFirstPos);
    return uiResult;
}

// Build this partition's triangle list: fetch each source triangle and remap its vertex indices.

void* NiMalloc(unsigned int uiSize);

struct A2400TriangleSet
{
    unsigned short* m_pusTriangles;
};

class A2400Source
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void GetTriangle(unsigned short m_usTriangleID, unsigned short& rusI0, unsigned short& rusI1,
                             unsigned short& rusI2);
};

class A2400Partition
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short* m_pusTriList;
    int unk18;
    unsigned short unk1C;
    unsigned short m_usTriangles;

    void BuildTriangleList(A2400TriangleSet* pkSet, A2400Source* pkSource, unsigned short* pusRemap);
};

// Allocates a triangle index list and fills it by fetching each triangle from the source and remapping its three indices through pusRemap.
// @fnv 0x00a82400
void A2400Partition::BuildTriangleList(A2400TriangleSet* pkSet, A2400Source* pkSource, unsigned short* pusRemap)
{
    m_pusTriList = (unsigned short*)NiMalloc(m_usTriangles * 3 * sizeof(unsigned short));
    for (unsigned int i = 0; i < m_usTriangles; i++)
    {
        unsigned short ausIndex[3];
        pkSource->GetTriangle(pkSet->m_pusTriangles[i], ausIndex[0], ausIndex[1], ausIndex[2]);
        unsigned short* pusTri = &m_pusTriList[i * 3];
        pusTri[0] = pusRemap[ausIndex[0]];
        pusTri[1] = pusRemap[ausIndex[1]];
        pusTri[2] = pusRemap[ausIndex[2]];
    }
}

inline bool Degenerate(const unsigned short* indices)
{
    if (indices[0] == indices[1])
        return true;
    if (indices[1] == indices[2])
        return true;
    if (indices[2] == indices[0])
        return true;
    return false;
}
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int) throw();

struct SkinGeom
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual __declspec(nothrow) void GetTriangle(unsigned int, unsigned short&, unsigned short&,
                                                 unsigned short&) throw();
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
    unsigned short triangleCount;
};
struct SkinEntry
{
    int unk00;
    int unk04;
    int unk08;
    int key;
};
struct SkinItems
{
    SkinEntry** items;
    unsigned int capacity;
    unsigned int count;
};
struct SkinMapNode
{
    SkinMapNode* next;
    int key;
    int value;
};
struct SkinMap
{
    virtual ~SkinMap() throw()
    {
        FUN_00438af0();
        NiFreeAlias(buckets);
    }
    virtual __declspec(nothrow) unsigned int Hash(int key) throw();
    virtual __declspec(nothrow) bool Equal(int left, int right) throw();
    unsigned int size;
    SkinMapNode** buckets;
    unsigned int count;
    SkinMap() throw() : size(37), count(0)
    {
        buckets = (SkinMapNode**)NiMalloc(size * sizeof(SkinMapNode*));
        fnv_zlib_memset(buckets, 0, size * sizeof(SkinMapNode*));
    }
    __declspec(nothrow) void FUN_00438af0() throw();
    __declspec(nothrow) void InsertOrUpdate(int key, int value) throw();
    __declspec(nothrow) bool FUN_00a53c30(int key, int& value) throw();
    __declspec(nothrow) int Lookup(int key) throw()
    {
        SkinMapNode* node = buckets[Hash(key)];
        while (node)
        {
            if (Equal(key, node->key))
                return node->value;
            node = node->next;
        }
        return -1;
    }
};
struct SkinPointerMap : SkinMap
{
    SkinPointerMap() throw()
    {}
    ~SkinPointerMap() throw()
    {
        FUN_00438af0();
    }
};
struct SkinBuilder
{
    int unk00;
    int unk04;
    unsigned int count;
    __declspec(nothrow) void BuildBoneLODControllerSets(SkinGeom*, void*, SkinItems*, int*) throw();
    __declspec(nothrow) void FUN_00a839d0(unsigned int, SkinItems*) throw();
    bool BuildTriangleSetMapping(SkinGeom*, void*, unsigned int, void*, SkinItems*, int**, int*) throw();
};
// Builds a per-triangle set index mapping from group IDs or weights, compacts unused sets, and returns false if a triangle's vertices span three distinct groups.
// @fnv 0x00a84310
bool SkinBuilder::BuildTriangleSetMapping(SkinGeom* geom, void* unused, unsigned int input, void* weights,
                                          SkinItems* sets, int** mapping, int* groupIDs) throw()
{
    unsigned int triangles = geom->triangleCount;
    BuildBoneLODControllerSets(geom, weights, sets, groupIDs);
    FUN_00a839d0(input, sets);
    *mapping = (int*)NiMalloc(triangles * sizeof(int));
    unsigned int setCount = sets->count;
    unsigned char* pUsedFlags = (unsigned char*)NiMalloc(setCount);
    unsigned short indices[3];
    if (groupIDs)
    {
        SkinPointerMap map;
        for (unsigned int k = 0; k < sets->count; k++)
            map.InsertOrUpdate(sets->items[k]->key, k);
        for (unsigned int tri = 0; tri < triangles; tri++)
        {
            int found = -1;
            geom->GetTriangle(tri, indices[0], indices[1], indices[2]);
            if (groupIDs[indices[0]] == groupIDs[indices[1]] && groupIDs[indices[1]] == groupIDs[indices[2]] &&
                groupIDs[indices[0]] == groupIDs[indices[2]])
            {
                map.FUN_00a53c30(groupIDs[indices[0]], found);
                if (found != -1)
                    (*mapping)[tri] = found;
            }
            else
            {
                int a = groupIDs[indices[0]], b = groupIDs[indices[1]], c = groupIDs[indices[2]];
                int lowBC = (b < c ? b : c);
                int low = a < lowBC ? a : lowBC;
                int highBC = (b > c ? b : c);
                int high = a > highBC ? a : highBC;
                if (high > 100)
                    low = high;
                int selected = map.Lookup(low);
                if (selected != -1)
                    (*mapping)[tri] = selected;
            }
            if (groupIDs[indices[0]] != groupIDs[indices[1]] && groupIDs[indices[1]] != groupIDs[indices[2]] &&
                groupIDs[indices[0]] != groupIDs[indices[2]])
                return false;
        }
    }
    else
    {
        for (unsigned int k = 0; k < sets->count; k++)
            pUsedFlags[k] = 0;
        for (unsigned int tri = 0; tri < triangles; tri++)
        {
            geom->GetTriangle(tri, indices[0], indices[1], indices[2]);
            if (Degenerate(indices))
                (*mapping)[tri] = -1;
            else
            {
                int selected = FindMatchingItem((ItemSet*)sets, indices, weights, pUsedFlags, 1);
                if (selected < 0)
                    selected = FindMatchingItem((ItemSet*)sets, indices, weights, pUsedFlags, 0);
                (*mapping)[tri] = selected;
            }
        }
        unsigned int k = 0;
        while (k < sets->count)
        {
            if (pUsedFlags[k])
                ++k;
            else
            {
                --sets->count;
                sets->items[k] = sets->items[sets->count];
                unsigned int oldIndex = sets->count;
                for (unsigned int tri = 0; tri < triangles; tri++)
                    if ((*mapping)[tri] == oldIndex)
                        (*mapping)[tri] = k;
            }
        }
    }
    count = sets->count;
    NiFreeAlias(pUsedFlags);
    return true;
}

template <class T> class SkinTArray
{
  public:
    virtual ~SkinTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef SkinTArray<char*> SkinViewerStrings;

struct SkinRTTI
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern SkinRTTI g_kSkinPartitionRTTI;

char* __cdecl SkinGetViewerString(const char* pcName);
int __cdecl SkinSprintf(char* pcDest, unsigned int uiDestSize, const char* pcFormat, ...);

class SkinObjectBase
{
  public:
    virtual ~SkinObjectBase();
    void GetViewerStrings(SkinViewerStrings* pkStrings);
};

class SkinPartitionOwner : public SkinObjectBase
{
  public:
    unsigned int m_uiRefCount;
    unsigned int m_uiPartitionCount;
    NiSkinPartition::Partition* m_pPartitions;

    virtual ~SkinPartitionOwner();
    void FUN_00a846e0(SkinViewerStrings* pkStrings);
};

// Appends the RTTI name and one line per partition listing its bone count to the viewer strings array.
// @fnv 0x00a846e0
void SkinPartitionOwner::FUN_00a846e0(SkinViewerStrings* pkStrings)
{
    SkinObjectBase::GetViewerStrings(pkStrings);
    pkStrings->Add(SkinGetViewerString(g_kSkinPartitionRTTI.GetName()));

    for (unsigned int i = 0; i < m_uiPartitionCount; i++)
    {
        char acTemp[32];
        SkinSprintf(acTemp, 32, "Partition %d = %d bones", i, m_pPartitions[i].m_usBoneCount);
        pkStrings->Add(SkinGetViewerString(acTemp));
    }
}

struct NiBinaryStreamFake
{
    int unk00;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamFake* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct NiStreamFake
{
    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c, u030, u034, u038, u03c;
    int u040, u044, u048, u04c, u050, u054, u058, u05c, u060, u064, u068, u06c, u070, u074, u078, u07c;
    int u080, u084, u088, u08c, u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;
    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec, u0f0, u0f4, u0f8, u0fc;
    int u100, u104, u108, u10c, u110, u114, u118, u11c, u120, u124, u128, u12c, u130, u134, u138, u13c;
    int u140, u144, u148, u14c, u150, u154, u158, u15c, u160, u164, u168, u16c, u170, u174, u178, u17c;
    int u180, u184, u188, u18c, u190, u194, u198, u19c, u1a0, u1a4, u1a8, u1ac, u1b0, u1b4, u1b8, u1bc;
    int u1c0, u1c4, u1c8, u1cc, u1d0, u1d4, u1d8, u1dc, u1e0, u1e4, u1e8, u1ec, u1f0, u1f4, u1f8, u1fc;
    int u200, u204, u208, u20c, u210, u214, u218, u21c, u220, u224, u228, u22c, u230, u234, u238, u23c;
    int u240, u244, u248, u24c;
    NiBinaryStreamFake* m_pBackingStream;
};

template <class T>
inline unsigned int SerializeValue(NiBinaryStreamFake& binstream, const T* pvValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pvValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline unsigned int SerializeValue(NiStreamFake& bstream, const T& value)
{
    return SerializeValue(*bstream.m_pBackingStream, &value, 1);
}

template <class T> inline unsigned int SerializeValue(NiStreamFake& bstream, const T* pvValue, unsigned int uiNumEls)
{
    return SerializeValue(*bstream.m_pBackingStream, pvValue, uiNumEls);
}

struct PartitionSave : NiSkinPartition::Partition
{
    void WriteToStream(NiStreamFake& kStream);
};

// @fnv 0x00a830d0
void PartitionSave::WriteToStream(NiStreamFake& kStream)
{
    SerializeValue(kStream, m_usVertices);
    SerializeValue(kStream, m_usTriangles);
    SerializeValue(kStream, m_usBoneCount);
    SerializeValue(kStream, m_usStrips);
    SerializeValue(kStream, m_usWeightsPerVertex);
    SerializeValue(kStream, m_pusBonePalette, m_usBoneCount);

    bool bHasVertexMap = m_pusSourceVertexIndices != 0;
    SerializeValue(kStream, bHasVertexMap);
    if (bHasVertexMap)
    {
        SerializeValue(kStream, m_pusSourceVertexIndices, m_usVertices);
    }

    unsigned int uiBonePaletteSize = (unsigned int)m_usWeightsPerVertex * m_usVertices;

    bool bHasWeights = m_pfVertexWeights != 0;
    SerializeValue(kStream, bHasWeights);
    if (bHasWeights)
    {
        SerializeValue(kStream, m_pfVertexWeights, uiBonePaletteSize);
    }

    unsigned int uiTriListLength;
    if (m_usStrips == 0)
    {
        uiTriListLength = m_usTriangles * 3;
    }
    else
    {
        SerializeValue(kStream, m_pusStripLengths, m_usStrips);
        uiTriListLength = GetStripIndexCount();
    }

    bool bHasTriList = m_pusTriList != 0;
    SerializeValue(kStream, bHasTriList);
    if (bHasTriList)
    {
        SerializeValue(kStream, m_pusTriList, uiTriListLength);
    }

    bool bHasBonePalette = m_pucBoneIndices != 0;
    SerializeValue(kStream, bHasBonePalette);
    if (bHasBonePalette)
    {
        SerializeValue(kStream, m_pucBoneIndices, uiBonePaletteSize);
    }
}

struct Skp_00a828d0_pair
{
    unsigned int key;
    float weight;
};
struct Skp_00a828d0_grp
{
    Skp_00a828d0_pair* items;
    unsigned int unk04;
    unsigned int count;
};
struct Skp_00a828d0_src
{
    unsigned short* data;
    unsigned int unk04;
    unsigned int count;
};

struct Skp_00a828d0_cls : NiSkinPartition::Partition
{
    unsigned short* SplitTriangles(GeomData* pkData, void* pkSet);
    void ExpandTriangles(void* pkSet, void* pkSource, unsigned short* pusRemap);
    void PopulateSkinData(GeomData* pkData, Skp_00a828d0_src* pkSrc, void* pkSet, Skp_00a828d0_grp* pkGroups,
                          bool bWeights, bool bZeroPalette, unsigned char ucBonesPerVertex, unsigned int uiBones);
};

void* __cdecl AllocBlock(unsigned int uiSize);
void __cdecl FreeBlock(void* p);

// Fills bone palette, vertex weights and bone indices from pkSrc and pkGroups, splitting and expanding triangles via SplitTriangles and ExpandTriangles.
// @fnv 0x00a828d0
void Skp_00a828d0_cls::PopulateSkinData(GeomData* pkData, Skp_00a828d0_src* pkSrc, void* pkSet,
                                        Skp_00a828d0_grp* pkGroups, bool bWeights, bool bZeroPalette,
                                        unsigned char ucBonesPerVertex, unsigned int uiBones)
{
    int n = (int)pkSrc->count;
    if (n <= (int)ucBonesPerVertex)
        n = (int)ucBonesPerVertex;
    m_usBoneCount = (unsigned short)n;
    m_usTriangles = pkData->m_usVertices;
    m_pusBonePalette = (unsigned short*)AllocBlock((unsigned short)n * 2);
    for (unsigned int i = 0; i < m_usBoneCount; ++i)
        m_pusBonePalette[i] = (i < pkSrc->count) ? pkSrc->data[i] : 0;

    unsigned short* remap = SplitTriangles(pkData, pkSet);
    ExpandTriangles(pkData, pkSet, remap);
    FreeBlock(remap);

    unsigned int j;
    unsigned int s;
    if (bWeights)
    {
        m_usWeightsPerVertex = ucBonesPerVertex;
        unsigned int cnt = (unsigned int)m_usWeightsPerVertex * m_usVertices;
        m_pfVertexWeights = (float*)AllocBlock(cnt * 4);
        m_pucBoneIndices = (unsigned char*)AllocBlock(cnt);
        unsigned int* table = (unsigned int*)AllocBlock(uiBones * 4);
        pkSet = table;
        for (unsigned int i = 0; i < pkSrc->count; ++i)
            table[m_pusBonePalette[i]] = i;

        float* outW = m_pfVertexWeights;
        unsigned char* outP = m_pucBoneIndices;
        float* tmpW = (float*)AllocBlock(m_usWeightsPerVertex * 4);
        unsigned char* tmpP = (unsigned char*)AllocBlock(m_usWeightsPerVertex);
        for (s = 0; s < m_usVertices; ++s)
        {
            Skp_00a828d0_grp* g = &pkGroups[m_pusSourceVertexIndices[s]];
            float* pW = tmpW;
            unsigned char* pP = tmpP;
            for (j = 0; j < g->count; ++j)
            {
                Skp_00a828d0_pair* it = &g->items[j];
                *pW++ = it->weight;
                *pP++ = (unsigned char)((unsigned int*)pkSet)[it->key];
            }
            for (; j < m_usWeightsPerVertex; ++j)
            {
                *pW++ = 0.0f;
                *pP++ = 0;
            }
            for (unsigned int k = 0; k < m_usWeightsPerVertex; ++k)
            {
                unsigned int idx = 0;
                float best = tmpW[0];
                for (j = 1; j < m_usWeightsPerVertex; ++j)
                {
                    if (tmpW[j] > best)
                    {
                        best = tmpW[j];
                        idx = j;
                    }
                }
                *outW++ = tmpW[idx];
                *outP++ = tmpP[idx];
                tmpW[idx] = -3.4028234663852886e+38f;
            }
        }
        FreeBlock(tmpW);
        FreeBlock(tmpP);
        FreeBlock(pkSet);
    }
    else
    {
        m_usWeightsPerVertex = m_usBoneCount;
        unsigned int cnt = (unsigned int)m_usBoneCount * m_usVertices;
        m_pfVertexWeights = (float*)AllocBlock(cnt * 4);
        float* outW = m_pfVertexWeights;
        for (s = 0; s < m_usVertices; ++s)
        {
            Skp_00a828d0_grp* g = &pkGroups[m_pusSourceVertexIndices[s]];
            for (j = 0; j < pkSrc->count; ++j)
            {
                float w;
                for (unsigned int k = 0; k < g->count; ++k)
                {
                    if (g->items[k].key == pkSrc->data[j])
                    {
                        w = g->items[k].weight;
                        goto store;
                    }
                }
                w = 0.0f;
            store:
                *outW++ = w;
            }
            for (; j < m_usBoneCount; ++j)
                *outW++ = 0.0f;
        }
        if (bZeroPalette)
        {
            m_pucBoneIndices = (unsigned char*)AllocBlock(cnt);
            unsigned char* outP = m_pucBoneIndices;
            for (s = 0; s < m_usVertices; ++s)
            {
                for (j = 0; j < m_usBoneCount; ++j)
                    *outP++ = (unsigned char)j;
            }
        }
    }
}

void* __cdecl NiMalloc(unsigned int);

struct NiBinaryStream;

typedef unsigned int(__cdecl* NiBinaryStreamReadFn)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinaryStream
{
    int unk000;
    unsigned int m_uiStreamFlags;
    NiBinaryStreamReadFn m_pfnRead;

    template <class T> inline unsigned int BinaryRead(T* pvBuffer, unsigned int auiCount = 1)
    {
        unsigned int uiComponentSize = sizeof(T);
        unsigned int uiTotal = auiCount * sizeof(T);
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotal, &uiComponentSize, 1);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct NiStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned int m_uiFormatVersion;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_pkBinaryStream;
};

template <class T> inline void ReadBinaryValue(NiStream& kStream, T* ptVal, unsigned int auiCount = 1)
{
    kStream.m_pkBinaryStream->BinaryRead(ptVal, auiCount);
}

struct PartitionLoader : NiSkinPartition::Partition
{
    void FUN_00a82d90(NiStream& kStream);
};

// Reads skin partition vertex, triangle, strip, weight and bone palette data from kStream, allocating buffers as needed.
// @fnv 0x00a82d90
void PartitionLoader::FUN_00a82d90(NiStream& kStream)
{
    ReadBinaryValue(kStream, &m_usVertices);
    ReadBinaryValue(kStream, &m_usTriangles);
    ReadBinaryValue(kStream, &m_usBoneCount);
    ReadBinaryValue(kStream, &m_usStrips);
    ReadBinaryValue(kStream, &m_usWeightsPerVertex);

    m_pusBonePalette = (unsigned short*)NiMalloc(sizeof(unsigned short) * m_usBoneCount);
    ReadBinaryValue(kStream, m_pusBonePalette, m_usBoneCount);

    bool bHasVertexMap;
    if (kStream.m_uiFormatVersion >= 0x0a000112)
    {
        ReadBinaryValue(kStream, &bHasVertexMap);
    }
    else
    {
        bHasVertexMap = true;
    }
    if (bHasVertexMap)
    {
        m_pusSourceVertexIndices = (unsigned short*)NiMalloc(sizeof(unsigned short) * m_usVertices);
        ReadBinaryValue(kStream, m_pusSourceVertexIndices, m_usVertices);
    }

    unsigned int bHasTriList = m_usWeightsPerVertex * m_usVertices;
    bool bHasWeights;
    if (kStream.m_uiFormatVersion >= 0x0a000112)
    {
        ReadBinaryValue(kStream, &bHasWeights);
    }
    else
    {
        bHasWeights = true;
    }
    if (bHasWeights)
    {
        m_pfVertexWeights = (float*)NiMalloc(sizeof(float) * bHasTriList);
        ReadBinaryValue(kStream, m_pfVertexWeights, bHasTriList);
    }

    unsigned int uiTriListLength;
    if (m_usStrips == 0)
    {
        uiTriListLength = m_usTriangles * 3;
    }
    else
    {
        m_pusStripLengths = (unsigned short*)NiMalloc(sizeof(unsigned short) * m_usStrips);
        ReadBinaryValue(kStream, m_pusStripLengths, m_usStrips);
        uiTriListLength = GetStripIndexCount();
    }

    bool uiNumWeights;
    if (kStream.m_uiFormatVersion >= 0x0a000112)
    {
        ReadBinaryValue(kStream, &uiNumWeights);
    }
    else
    {
        uiNumWeights = true;
    }
    if (uiNumWeights)
    {
        m_pusTriList = (unsigned short*)NiMalloc(sizeof(unsigned short) * uiTriListLength);
        ReadBinaryValue(kStream, m_pusTriList, uiTriListLength);
    }

    bool bHasBonePalette;
    ReadBinaryValue(kStream, &bHasBonePalette);
    if (bHasBonePalette)
    {
        m_pucBoneIndices = (unsigned char*)NiMalloc(sizeof(unsigned char) * bHasTriList);
        ReadBinaryValue(kStream, m_pucBoneIndices, bHasTriList);
    }
}

class NiBinaryStreamA83C
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStreamA83C* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA83C();

    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    NIBINARYSTREAM_READFN m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiStreamA83C
{
  public:
    virtual ~NiStreamA83C();

    unsigned char m_auPad[0x24c];
    NiBinaryStreamA83C* m_pUnderlyingStream;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA83C& is, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStreamA83C& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

class FUN_00a89af0_helper
{
  public:
    void FUN_00a89af0(NiStreamA83C& kStream);
};

class ElemA83C
{
  public:
    void WriteToStream(NiStreamA83C& kStream);
    int unk00[11];
};

class SaverA83C : public FUN_00a89af0_helper
{
  public:
    int m_unk00[2];
    unsigned int m_uiCount;
    ElemA83C* m_pkElems;

    void SaveBinary(NiStreamA83C& kStream);
};

// Calls FUN_00a89af0, reads m_uiCount, then calls WriteToStream on each element.
// @fnv 0x00a83ce0
void SaverA83C::SaveBinary(NiStreamA83C& kStream)
{
    FUN_00a89af0(kStream);
    ReadBinaryValue(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        m_pkElems[i].WriteToStream(kStream);
}

struct NormalizedWeight
{
    unsigned int key;
    float weight;
};
class NormalizedWeights
{
  public:
    NormalizedWeight* entries;
    unsigned int capacity, count;
    void NormalizeWeights();
};
// Sums the entry weights and scales each by the reciprocal of that sum.
// @fnv 0x00a820e0
void NormalizedWeights::NormalizeWeights()
{
    float sum = 0.0f;
    unsigned int i;
    for (i = 0; i < count; ++i)
        sum += entries[i].weight;
    float inverse = 1.0f / sum;
    for (i = 0; i < count; ++i)
        entries[i].weight *= inverse;
}

struct ScriptProgram
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void GetTriangle(unsigned int, unsigned short&, unsigned short&, unsigned short&);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned short triangles;
};

void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFreeAlias(void*);
struct MemoryManager
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
int __cdecl FUN_00a81b80(const unsigned short*, const unsigned short*);
void __cdecl FUN_00ec6f20(void*, unsigned int, unsigned int,
                          int(__cdecl*)(const unsigned short*, const unsigned short*));
template <class T> struct BoneArray
{
    T* data;
    unsigned int capacity;
    unsigned int count;
    BoneArray() : data(0), capacity(0), count(0)
    {}
    void Resize(unsigned int size)
    {
        if (size == capacity)
            return;
        T* fresh;
        if (size > 0)
        {
            fresh = (T*)NiMalloc(size * sizeof(T));
            for (unsigned int n = 0; n < count; ++n)
                fresh[n] = data[n];
        }
        else
            fresh = 0;
        NiFreeAlias(data);
        data = fresh;
        capacity = size;
    }
    void Add(T value)
    {
        if (count == capacity)
            Resize(capacity > 0 ? 2 * capacity : 1);
        data[count++] = value;
    }
    unsigned int Find(T value)
    {
        for (unsigned int n = 0; n < count; ++n)
            if (data[n] == value)
                return n;
        return -1;
    }
};
struct BoneLODControllerArray : BoneArray<unsigned short>
{
    unsigned int key;
    bool Contains(const BoneLODControllerArray* other) const
    {
        return ((Holder*)this)->ContainsSortedSubset((const Holder*)other);
    }
    static void* operator new(unsigned int size) throw()
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete(void* ptr)
    {
        _g_memoryManager.Deallocate(ptr);
    }
    ~BoneLODControllerArray()
    {
        NiFreeAlias(data);
    }
};
struct BoneWeight
{
    unsigned short bone;
    float weight;
};
struct BoneWeights
{
    BoneWeight* data;
    unsigned int capacity;
    unsigned int count;
};
struct NiStreamLinkIDSet
{
    void Realloc(unsigned int);
};
// Builds and deduplicates BoneLODControllerArray sets from mesh triangles and vertex bone weights, optionally remapping vertex indices.
// @fnv 0x00a83d40
void __stdcall BuildBoneLODControllerSets(ScriptProgram* mesh, BoneWeights* weights,
                                          BoneArray<BoneLODControllerArray*>* sets, unsigned int* remap)
{
    unsigned int triangleCount = mesh->triangles;
    unsigned short vertices[3];
    if (remap)
    {
        for (unsigned int mappedTriangle = 0; mappedTriangle < mesh->triangles; ++mappedTriangle)
        {
            mesh->GetTriangle(mappedTriangle, vertices[0], vertices[1], vertices[2]);
            unsigned int keys[3] = {remap[vertices[0]], remap[vertices[1]], remap[vertices[2]]};
            for (unsigned int corner = 0; corner < 3; ++corner)
            {
                bool found = false;
                for (unsigned int index = 0; index < sets->count; ++index)
                {
                    BoneLODControllerArray* set = sets->data[index];
                    if (set->key == keys[corner])
                    {
                        found = true;
                        for (unsigned int vertex = 0; vertex < 3; ++vertex)
                        {
                            for (unsigned int entry = 0; entry < weights[vertices[vertex]].count; ++entry)
                            {
                                unsigned short bone = weights[vertices[vertex]].data[entry].bone;
                                if (set->Find(bone) == -1)
                                    set->Add(bone);
                            }
                        }
                        FUN_00ec6f20(set->data, set->count, 2, FUN_00a81b80);
                    }
                }
                if (!found)
                {
                    BoneLODControllerArray* set = new BoneLODControllerArray;
                    set->key = keys[corner];
                    for (unsigned int vertex = 0; vertex < 3; ++vertex)
                    {
                        for (unsigned int entry = 0; entry < weights[vertices[vertex]].count; ++entry)
                        {
                            unsigned short bone = weights[vertices[vertex]].data[entry].bone;
                            if (set->Find(bone) == -1)
                                set->Add(bone);
                        }
                    }
                    FUN_00ec6f20(set->data, set->count, 2, FUN_00a81b80);
                    sets->Add(set);
                }
            }
        }
    }
    else
    {
        for (unsigned int ordinaryTriangle = 0; ordinaryTriangle < triangleCount; ++ordinaryTriangle)
        {
            mesh->GetTriangle(ordinaryTriangle, vertices[0], vertices[1], vertices[2]);
            if (!(vertices[0] == vertices[1] || vertices[1] == vertices[2] || vertices[2] == vertices[0]))
            {
                BoneLODControllerArray* set = new BoneLODControllerArray;
                for (unsigned int corner = 0; corner < 3; ++corner)
                {
                    BoneWeights* list = weights + vertices[corner];
                    unsigned int count = list->count;
                    for (unsigned int entry = 0; entry < count; ++entry)
                    {
                        unsigned short bone = list->data[entry].bone;
                        if (set->Find(bone) == -1)
                        {
                            if (set->count == set->capacity)
                                ((C082d30*)set)->FUN_00a82710(set->capacity > 0 ? 2 * set->capacity : 1);
                            set->data[set->count++] = bone;
                        }
                    }
                }
                FUN_00ec6f20(set->data, set->count, 2, FUN_00a81b80);
                unsigned int index = 0;
                while (index < sets->count)
                {
                    BoneLODControllerArray* other = sets->data[index];
                    if (other->Contains(set))
                    {
                        delete set;
                        break;
                    }
                    if (set->Contains(other))
                    {
                        delete other;
                        --sets->count;
                        sets->data[index] = sets->data[sets->count];
                    }
                    else
                        ++index;
                }
                if (index == sets->count)
                {
                    if (sets->count == sets->capacity)
                        ((NiStreamLinkIDSet*)sets)->Realloc(sets->capacity > 0 ? 2 * sets->capacity : 1);
                    sets->data[sets->count++] = set;
                }
            }
        }
    }
}

class CA82770MergeIterator;

struct CA82770IndexArray
{
    unsigned short* m_pusData;
    unsigned int unk04;
    unsigned int m_uiSize;

    unsigned int GetMergeCount(CA82770IndexArray* pkOther);
};

class CA82770MergeIterator
{
  public:
    unsigned int m_uiFirstPos;
    unsigned int m_uiSecondPos;
    unsigned short m_ausCurrent[2];
    CA82770IndexArray* m_pkFirst;
    CA82770IndexArray* m_pkSecond;

    CA82770MergeIterator(CA82770IndexArray* pkCurrentObject, CA82770IndexArray* pkSecond)
    {
        m_pkFirst = pkCurrentObject;
        m_pkSecond = pkSecond;
        m_uiSecondPos = 0;
        m_uiFirstPos = 0;
        m_ausCurrent[0] = *pkCurrentObject->m_pusData;
        m_ausCurrent[1] = *pkSecond->m_pusData;
    }
    bool AtEnd() const
    {
        return m_ausCurrent[0] == 0xffff && m_ausCurrent[1] == 0xffff;
    }
    __declspec(noalias) unsigned int GetNext();
};

// Iterates through the merged sequence of this and pkOther index arrays and returns the total number of elements visited.
// @fnv 0x00a82770
unsigned int CA82770IndexArray::GetMergeCount(CA82770IndexArray* pkOther)
{
    CA82770MergeIterator kIter(this, pkOther);
    unsigned int ItemUpdateArray = 0;
    while (!kIter.AtEnd())
    {
        kIter.GetNext();
        ItemUpdateArray++;
    }
    return ItemUpdateArray;
}

struct ListMerge
{
    unsigned short* m_pusData;
    unsigned int m_u4;
    unsigned int m_uiCount;

    void Merge(const ListMerge* pkOther);
};

struct ListMergeIter
{
    unsigned int m_uIndexA;
    unsigned int m_uIndexB;
    unsigned short m_ausValues[2];
    ListMerge* m_pkSourceA;
    const ListMerge* m_pkSourceB;

    __declspec(noalias) unsigned short Next();
};

// Appends values returned by kIter.Next to a new buffer, then replaces m_pusData and updates m_u4 and m_uiCount.
// @fnv 0x00a827f0
void ListMerge::Merge(const ListMerge* pkOther)
{
    ListMergeIter kIter;
    kIter.m_pkSourceA = this;
    kIter.m_pkSourceB = pkOther;
    kIter.m_uIndexB = 0;
    kIter.m_uIndexA = 0;
    kIter.m_ausValues[0] = m_pusData[0];
    kIter.m_ausValues[1] = pkOther->m_pusData[0];

    unsigned int uiTotal = m_uiCount + pkOther->m_uiCount;
    unsigned short* pusNew = (unsigned short*)NiMalloc(uiTotal * 2);
    unsigned int ItemUpdateArray = 0;
    while (kIter.m_ausValues[0] != 0xffff || kIter.m_ausValues[1] != 0xffff)
    {
        pusNew[ItemUpdateArray++] = kIter.Next();
    }
    NiFreeAlias(m_pusData);
    m_u4 = uiTotal;
    m_pusData = pusNew;
    m_uiCount = ItemUpdateArray;
}

namespace SkinWeights {

extern "C" __declspec(nothrow) void* __cdecl NiMalloc(unsigned int);
extern "C" __declspec(nothrow) void __cdecl NiFreeAlias(void*);
__declspec(nothrow) void* FUN_00ec61c0(void*, int, unsigned int) throw();
extern const float DAT_01016970;

struct Weight
{
    unsigned int bone;
    float weight;
};
int CompareFloatDescending(const void*, const void*);
__declspec(nothrow) void FUN_00ec6f20(void*, unsigned int, unsigned int, int (*)(const void*, const void*)) throw();

struct Group
{
    Weight* entries;
    unsigned int capacity, count;
    __declspec(nothrow) void NormalizeWeights() throw();

    __forceinline void OrderedRemove(unsigned int i)
    {
        for (unsigned int j = i; j < count - 1; ++j)
            entries[j] = entries[j + 1];
        --count;
    }
    __forceinline bool Remove(unsigned int bone)
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            if (entries[i].bone == bone)
            {
                OrderedRemove(i);
                return true;
            }
        }
        return false;
    }

    __forceinline bool SameBones(const Group& other) const
    {
        if (other.count != count)
            return false;
        for (unsigned int i = 0; i < other.count; ++i)
            if (other.entries[i].bone != entries[i].bone)
                return false;
        return true;
    }
};

struct IndexList
{
    unsigned int* data;
    unsigned int capacity;
    unsigned int count;
    IndexList() : data(0), capacity(0), count(0)
    {}

    __forceinline void Resize(unsigned int size, unsigned int& capacityRef)
    {
        if (size != capacityRef)
        {
            unsigned int* newData;
            if (size > 0)
            {
                newData = (unsigned int*)NiMalloc(4 * size);
                for (unsigned int n = 0; n < count; ++n)
                    newData[n] = data[n];
            }
            else
            {
                newData = 0;
            }
            NiFreeAlias(data);
            data = newData;
            capacityRef = size;
        }
    }

    __forceinline void Add(const unsigned int& value, unsigned int& capacityRef)
    {
        if (count == capacityRef)
            Resize(capacityRef > 0 ? capacityRef * 2 : 1, capacityRef);
        data[count++] = value;
    }
};

struct Node
{
    Node* next;
    unsigned int bone;
    float weight;
};
struct WeightMap;
struct MapVTable
{
    void* destroy;
    unsigned int(__thiscall* hash)(WeightMap*, unsigned int);
    void* equal;
};
extern MapVTable DAT_0109e50c, DAT_0109e52c;

struct WeightMap
{
    MapVTable* table;
    unsigned int bucketsCount;
    Node** buckets;
    unsigned int count;

    __forceinline void Initialize()
    {
        table = &DAT_0109e50c;
        bucketsCount = 37;
        count = 0;
        buckets = (Node**)NiMalloc(37 * 4);
        FUN_00ec61c0(buckets, 0, bucketsCount * 4);
        table = &DAT_0109e52c;
    }

    __declspec(nothrow) void FUN_00b601a0() throw();
    __forceinline void Cleanup()
    {
        table = &DAT_0109e52c;
        FUN_00b601a0();
        table = &DAT_0109e50c;
        FUN_00b601a0();
        NiFreeAlias(buckets);
    }

    __forceinline Node* Begin()
    {
        for (unsigned int i = 0; i < bucketsCount; i++)
            if (buckets[i])
                return buckets[i];
        return 0;
    }

    __forceinline void Next(Node*& position, unsigned int& bone, float& weight)
    {
        Node* current = position;
        weight = current->weight;
        bone = current->bone;
        if (current->next)
        {
            position = current->next;
            return;
        }
        unsigned int bucket = table->hash(this, bone) + 1;
        if (bucket < bucketsCount)
        {
            do
            {
                Node* next = buckets[bucket];
                if (next)
                {
                    position = next;
                    return;
                }
                ++bucket;
            } while (bucket < bucketsCount);
        }
        position = 0;
    }
};

struct Geometry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    __declspec(nothrow) virtual void GetTriangle(unsigned int, unsigned short&, unsigned short&,
                                                 unsigned short&) throw();

    int unk04;
    unsigned short vertices, unk0a;
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
    unsigned short triangles, unk42;

    __declspec(nothrow) void BuildIndexMappings(unsigned short**, unsigned short**, bool) throw();
    __declspec(nothrow) int CompareVertices(unsigned int, unsigned int, bool) throw();
};

struct Processor
{
    __declspec(nothrow) void MergeGroupWeights(WeightMap*, const unsigned short*, Group*) throw();
    bool ReduceGroupWeights(Geometry*, unsigned char, unsigned char, Group*);
};

struct State
{
    unsigned int triangles;
    State()
    {}
};
// Limits bone weights per triangle and vertex by removing lowest-weight bones, returning false if a group becomes empty.
// @fnv 0x00a833b0
bool Processor::ReduceGroupWeights(Geometry* geometry, unsigned char maxTriangle, unsigned char maxVertex,
                                   Group* groups)
{
    State state;
    unsigned int vertices = geometry->vertices;
    state.triangles = geometry->triangles;
    WeightMap map;
    map.Initialize();
    unsigned int triangle, corner;
    IndexList linkedVertices;
    unsigned short* order;
    unsigned short* reverse;
    geometry->BuildIndexMappings(&order, &reverse, true);

    for (triangle = 0; triangle < state.triangles; triangle++)
    {
        unsigned short indices[3];
        geometry->GetTriangle(triangle, indices[0], indices[1], indices[2]);
        if (indices[0] != indices[1] && indices[1] != indices[2] && indices[2] != indices[0])
        {
            MergeGroupWeights(&map, indices, groups);
            unsigned int count = map.count;
            if (count > maxTriangle)
            {
                for (;;)
                {
                    Node* position = map.Begin();
                    float least = DAT_01016970;
                    unsigned int remove = 0;
                    do
                    {
                        float weight;
                        unsigned int bone;
                        map.Next(position, bone, weight);
                        if (weight < least)
                        {
                            least = weight;
                            remove = bone;
                        }
                    } while (position);

                    for (corner = 0; corner < 3; corner++)
                    {
                        unsigned int vertex = indices[corner];
                        linkedVertices.Add(vertex, linkedVertices.capacity);
                        Group* group = &groups[vertex];
                        unsigned int before, center, other;
                        before = center = reverse[vertex];

                        while (before > 0 && !geometry->CompareVertices(other = order[before - 1], vertex, true))
                        {
                            if (groups[other].SameBones(*group))
                                linkedVertices.Add(other, linkedVertices.capacity);
                            --before;
                        }
                        while (center < vertices - 1 &&
                               !geometry->CompareVertices(other = order[center + 1], vertex, true))
                        {
                            if (groups[other].SameBones(*group))
                                linkedVertices.Add(other, linkedVertices.capacity);
                            ++center;
                        }

                        for (unsigned int n = 0; n < linkedVertices.count; n++)
                        {
                            other = linkedVertices.data[n];
                            group = &groups[other];
                            if (group->Remove(remove))
                            {
                                if (group->count == 0)
                                {
                                    NiFreeAlias(order);
                                    NiFreeAlias(reverse);
                                    NiFreeAlias(linkedVertices.data);
                                    map.Cleanup();
                                    return false;
                                }
                                group->NormalizeWeights();
                            }
                        }
                        linkedVertices.count = 0;
                    }
                    if (--count == maxTriangle)
                        break;
                    map.FUN_00b601a0();
                    MergeGroupWeights(&map, indices, groups);
                }
            }
            map.FUN_00b601a0();
        }
    }

    for (corner = 0; corner < vertices; corner++)
    {
        Group* group = &groups[corner];
        if (group->count > maxVertex)
        {
            FUN_00ec6f20(group->entries, group->count, 8, CompareFloatDescending);
            group->count = maxVertex;
            group->NormalizeWeights();
        }
    }
    NiFreeAlias(order);
    NiFreeAlias(reverse);
    NiFreeAlias(linkedVertices.data);
    map.Cleanup();
    return true;
}

}  // namespace SkinWeights

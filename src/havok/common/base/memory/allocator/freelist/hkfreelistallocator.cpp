
// src/havok/common/base/memory/allocator/freelist/hkfreelistallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelistallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00cc0410(int, const char*);

struct hkFreeListAllocator
{
    void __thiscall PrintStatistics(int);
};

// @fnv 0x00d5f950
void __thiscall hkFreeListAllocator::PrintStatistics(int aiUnused)
{
    FUN_00cc0410(aiUnused,
                 "printStatistics is not supported on hkFreeListAllocator - use hkDebugMemory or hkPoolMemory\n");
}

struct FUN_00dd7200_cls
{
    void FUN_00dd7200();
};
struct FUN_00d5fc70_cls
{
    void FUN_00d5fc70(FUN_00dd7200_cls* p);
};
// Calls FUN_00dd7200 on p, then if p+0x34 is the pointer stored at this+0x238, subtracts 0x34 from that pointer.
// @fnv 0x00d5fc70
void FUN_00d5fc70_cls::FUN_00d5fc70(FUN_00dd7200_cls* p)
{
    p->FUN_00dd7200();
    if ((char*)p + 0x34 == *(char**)((char*)this + 0x238))
        *(char**)((char*)this + 0x238) -= 0x34;
}

struct FUN_00d5f910_elem
{
    void* unk00;
    void* m_pNext;
};

struct FUN_00d5f910_sub
{
    virtual void* v00(int, int);
    virtual void* v04(int, int);
    virtual void* v08(int, int);
    virtual void* v0c(int, int);
    virtual void* BlockAlloc(int aiUnused, int aiNumBytes);
};

struct FUN_00d5f910_cls
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
    FUN_00d5f910_sub m_sub28;
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    FUN_00d5f910_elem* pAudioItems[41];
    void* AllocateBlock(int aiUnused, int aiNumBytes);
};

// Returns a free block from the size-class list for requests up to 0x280 bytes, otherwise delegates to m_sub28.BlockAlloc.
// @fnv 0x00d5f910
void* FUN_00d5f910_cls::AllocateBlock(int aiUnused, int aiNumBytes)
{
    if (aiNumBytes <= 0x280)
    {
        if (aiNumBytes == 0)
            return 0;
        FUN_00d5f910_elem* pElem = pAudioItems[(aiNumBytes + 15) >> 4];
        if (pElem)
            return pElem->m_pNext;
    }
    return m_sub28.BlockAlloc(aiUnused, aiNumBytes);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FreeListEntry
{
    FreeListEntry* next;
};

struct StringListNode
{
    FreeListEntry* m_free;
    int m_iFirstIndex;
    char pad08[0x20];
    int m_iFreeCount;
};

class LargeAlloc
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p);
};

struct SixIntegerRecord
{
    char data[0x18];
};

class FLAllocator
{
  public:
    void* vtbl;
    SixIntegerRecord m_cs;
    int m_iPoolBlockSize;
    char pad20[0x8];
    LargeAlloc m_large;
    char pad2c[0xc0];
    StringListNode* m_pFreeBlockLists[41];
    void FreeBlocks(void** blocks, int numBlocks, int blockSize);
};

// @fnv 0x00d5f9f0
void FLAllocator::FreeBlocks(void** blocks, int numBlocks, int blockSize)
{
    SixIntegerRecord* cs = &m_cs;
    EnterCriticalSection(cs);
    if (blockSize <= 0x280)
    {
        StringListNode* list = m_pFreeBlockLists[(blockSize + 15) >> 4];
        int iOldCount = list->m_iFreeCount;
        void** p = blocks;
        FreeListEntry* head = list->m_free;
        list->m_iFreeCount = iOldCount + numBlocks;
        for (int i = numBlocks - 1; i >= 0; i--)
        {
            FreeListEntry* e = (FreeListEntry*)*p++;
            if (e)
            {
                e->next = head;
                head = e;
            }
            else
            {
                list->m_iFreeCount--;
            }
        }
        list->m_free = head;
        m_iPoolBlockSize += (list->m_iFreeCount - iOldCount) * list->m_iFirstIndex;
    }
    else
    {
        for (int i = 0; i < numBlocks; i++)
        {
            if (blocks[i])
                m_large.ReleaseBlock(blocks[i]);
        }
    }
    LeaveCriticalSection(cs);
}

struct D603E0Base
{
    ~D603E0Base();
};

struct D603E0Object : D603E0Base
{
    D603E0Object* FUN_00d603e0(unsigned int uiFlags);
};

// @fnv 0x00d603e0
D603E0Object* D603E0Object::FUN_00d603e0(unsigned int uiFlags)
{
    D603E0Base::~D603E0Base();
    return this;
}

struct FUN_00d61f30_shell
{
    void FUN_00d61cc0();
    void AppendStrings(int a, int b, int c, int d, int e, int f);
    void FUN_00d61f30(int a, int b, int c, int d, int e, int f);
};

// Calls FUN_00d61cc0, then forwards the six arguments to AppendStrings.
// @fnv 0x00d61f30
void FUN_00d61f30_shell::FUN_00d61f30(int a, int b, int c, int d, int e, int f)
{
    FUN_00d61cc0();
    AppendStrings(a, b, c, d, e, f);
}

struct FUN_00d5f850_cls
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
    virtual void v28(int* out);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void FUN_00d5f850();
};

// Zeroes a six-int buffer, fills it via v28, then stores the second element into unk20.
// @fnv 0x00d5f850
void FUN_00d5f850_cls::FUN_00d5f850()
{
    int buf[6];
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    this->v28(buf);
    this->unk20 = buf[1];
}

struct FUN_00d5f970_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int&);
    void FUN_00d5f970(int a);
};

// @fnv 0x00d5f970
void FUN_00d5f970_cls::FUN_00d5f970(int a)
{
    v3(a);
}

struct FUN_00d5fba0_cls
{
    int getMemorySoftLimit();
};

// @fnv 0x00d5fba0
int FUN_00d5fba0_cls::getMemorySoftLimit()
{
    return *(int*)((char*)this + 0xa94);
}

struct FUN_00d5fc30_cls
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
    void FUN_00d5fc30();
};

// @fnv 0x00d5fc30
void FUN_00d5fc30_cls::FUN_00d5fc30()
{
    this->v40();
}

struct FUN_00d5fc40_cls
{
    unsigned char HasRoomFor(unsigned int limit);
};

// Updates the peak of used minus base bytes and returns whether used is below the limit subtracted from the value at offset 0xa94.
// @fnv 0x00d5fc40
unsigned char FUN_00d5fc40_cls::HasRoomFor(unsigned int limit)
{
    char* self = (char*)this;
    unsigned int used = *(unsigned int*)(self + 0xe8) - *(unsigned int*)(self + 0x1c);
    unsigned int peak = *(unsigned int*)(self + 0x20);
    if (used > peak)
    {
        peak = used;
    }
    *(unsigned int*)(self + 0x20) = peak;
    unsigned int room = *(unsigned int*)(self + 0xa94) - limit;
    if (used < room)
    {
        return 1;
    }
    return 0;
}

// stand-in types for FUN_00d60270
struct Sub4
{
    void Init(int a1);
};

struct Sub28
{
    void Init(int a1);
};

struct Elem34
{
    void Init();
    int unk00;
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
};

struct HeapBase60270
{
    int Alloc(int a, int b, int c);
    void Reset(int a);
};

class FUN_00d60270_cls : public HeapBase60270
{
  public:
    FUN_00d60270_cls* FUN_00d60270(int a1);
    void* m_vptr;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int m_1c;
    int m_20;
    int m_24;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int m_tab[0x29];
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int m_234;
    int* m_238;
    int* m_23c;
    Elem34 m_items[0x29];
    int unkA94;
    int m_a98;
    int unkA9C;
};

extern char g_vtbl60270[];

// Initializes the object: sets the vtable, initializes sub-objects and item array, resets state, and allocates the size-class table slots.
// @fnv 0x00d60270
FUN_00d60270_cls* FUN_00d60270_cls::FUN_00d60270(int a1)
{
    m_vptr = g_vtbl60270;
    reinterpret_cast<Sub4*>(&unk004)->Init(0xfa0);
    m_24 = a1;
    reinterpret_cast<Sub28*>(&unk028)->Init(a1);
    Elem34* pItems = m_items;
    m_234 = 0;
    Elem34* e = pItems;
    for (int i = 0x28; i >= 0; --i)
    {
        e->Init();
        ++e;
    }
    m_a98 = 0;
    m_1c = 0;
    m_20 = 0;
    Reset(0x7fffffff);
    m_238 = (int*)pItems;
    pItems = (Elem34*)((char*)pItems + 0x854);
    m_23c = (int*)pItems;
    for (int i = 0; i < 0x29; ++i)
    {
        m_tab[i] = 0;
    }
    m_tab[0x20] = Alloc(0x200, 0x80, 0x10000);
    m_tab[0x10] = Alloc(0x100, 0x20, 0x8000);
    m_tab[0] = Alloc(0, 4, 0x100);
    int r4 = Alloc(0x220, 0x80, 0x5000);
    for (int i = 0x210; i <= 0x280; ++i)
    {
        m_tab[i >> 4] = r4;
    }
    int iSize = 0x280;
    do
    {
        int* slot = &m_tab[iSize >> 4];
        if (*slot == 0)
        {
            int iCount = 0x10;
            int sz;
            if (iSize > 0)
            {
                sz = iSize << 4;
                if ((unsigned int)iSize < 0x100)
                {
                    sz = 0x1000;
                }
            }
            else
            {
                sz = 0x1000;
            }
            if (iSize >= 0x40)
            {
                iCount = 0x20;
            }
            *slot = Alloc(iSize, iCount, sz);
        }
        iSize -= 0x10;
    } while (iSize >= 0x10);
    return this;
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);
namespace d5f {
struct Res
{
    bool m_kPointB;
    Res()
    {}
};
struct Block
{
    int unk;
    int m_iWordAt04;
    char pad[0x28 - 8];
    int m_28;
    Res FUN_00dd7c40(int n, int* got);
    void FUN_00dd7360();
};
struct Pool
{
    int unk;
    int m_cs[6];
    int m_1c;
    char pad[0x190 - 0x20];
    Block* m_apBlocks[(0x234 - 0x190) / 4];
    int m_iArrayLength;
    char padCur[0xa98 - 0x238];
    int m_iCur;
    void AllocateBlocks(int n);
};
// Locks the pool, walks blocks from m_iCur allocating n units, updates m_1c and m_iCur, then unlocks.
// @fnv 0x00d5feb0
void Pool::AllocateBlocks(int aiCount)
{
    int* cs = m_cs;
    DAT_00fdf05c(cs);
    if (aiCount < 1)
        aiCount = 1;
    int start = m_iCur;
    int iIndex = start;
    do
    {
        Block* b = m_apBlocks[iIndex];
        int before = b->m_28;
        int got;
        if (b->FUN_00dd7c40(aiCount, &got).m_kPointB)
        {
            iIndex++;
            if (iIndex >= m_iArrayLength)
                iIndex = 0;
        }
        b->FUN_00dd7360();
        aiCount -= got;
        m_1c += (b->m_28 - before) * b->m_iWordAt04;
    } while (aiCount > 0 && iIndex != start);
    m_iCur = iIndex;
    DAT_00fdf100(cs);
}
}

// @fnv 0x00d5fab0
void __stdcall FUN_00d5fab0(int)
{}

extern void(__stdcall* DAT_00fdf05c)(int* pkCriticalSection);
extern void(__stdcall* DAT_00fdf100)(int* pkCriticalSection);

class MemoryPoolW
{
  public:
    int Compact();
    void FUN_00dd7380(unsigned int uiTarget);

    int m_iUnk00;
    int m_iBlockSize;
    char m_pad08[0xc];
    unsigned int m_uiFreeCount;
    char m_pad18[0x10];
    int m_iBlockCount;
};

class MemoryPoolManagerW
{
  public:
    void UpdateTotalSize();

    int m_iUnk00;
    int m_akCriticalSection[6];
    int m_iTotalSize;
    char m_pad20[0x190 - 0x20];
    MemoryPoolW* m_apkPools[(0x234 - 0x190) / 4];
    int m_iPoolCount;
};

// @fnv 0x00d5fbb0
void MemoryPoolManagerW::UpdateTotalSize()
{
    int* pkCriticalSection = m_akCriticalSection;
    DAT_00fdf05c(pkCriticalSection);
    for (int i = 0; i < m_iPoolCount; i++)
    {
        MemoryPoolW* pkPool = m_apkPools[i];
        int iOldCount = pkPool->m_iBlockCount;
        if (pkPool->Compact() > 0)
            pkPool->FUN_00dd7380(pkPool->m_uiFreeCount - pkPool->m_uiFreeCount / 10);
        m_iTotalSize += (pkPool->m_iBlockCount - iOldCount) * pkPool->m_iBlockSize;
    }
    DAT_00fdf100(pkCriticalSection);
}

struct SubAllocator
{
    virtual void* v00();
    virtual void* v04(unsigned int aSize);
};

struct SizeClassPool
{
    void* m_00;
    unsigned int m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    volatile unsigned int m_20;
    unsigned int m_24;
    int m_28;

    void* AllocateElement();
};

void __cdecl FUN_00d88040(int);

struct DynamicMemoryAllocator
{
    int unk00;
    SixIntegerRecord m_04;
    int m_1c;
    int m_20;
    int unk24;
    SubAllocator m_28;

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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;

    int m_e8;
    SizeClassPool* m_ec[41];

    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;

    int m_a94;

    void blockAllocBatch(void** apOut, int aCount, int aSize);
};

struct ScopedCs
{
    DynamicMemoryAllocator* owner;
    SixIntegerRecord* cs;
};

// @fnv 0x00d5fd70
void DynamicMemoryAllocator::blockAllocBatch(void** apOut, int aCount, int aSize)
{
    ScopedCs guard;
    guard.owner = this;
    guard.cs = &m_04;
    EnterCriticalSection(&m_04);

    if (aSize <= 0x280)
    {
        SizeClassPool* pool = m_ec[(aSize + 15) >> 4];
        int iFreeCount = pool->m_28;
        void** cur = apOut;
        void** end = apOut + aCount;
        void* node = pool->m_00;
        while (cur < end)
        {
            if (node == 0)
            {
                break;
            }
            *cur = node;
            cur++;
            node = *(void**)node;
        }
        pool->m_00 = node;
        pool->m_28 -= (int)(cur - apOut);
        void** start = cur;
        while (cur < end)
        {
            if (pool->m_20 < pool->m_24)
            {
                do
                {
                    if (cur >= end)
                    {
                        break;
                    }
                    *cur = (void*)pool->m_20;
                    pool->m_20 += pool->m_04;
                    cur++;
                } while (pool->m_20 < pool->m_24);
                pool->m_28 -= (int)(cur - start);
            }
            else
            {
                *cur = pool->AllocateElement();
                cur++;
            }
            start = cur;
        }
        guard.owner->m_1c += (pool->m_28 - iFreeCount) * (int)pool->m_04;
    }
    else
    {
        for (int i = 0; i < aCount; i++)
        {
            apOut[i] = guard.owner->m_28.v04(aSize);
        }
    }

    DynamicMemoryAllocator* self = guard.owner;
    unsigned int avail = (unsigned int)(self->m_e8 - self->m_1c);
    unsigned int grow = (unsigned int)self->m_20;
    if (avail > grow)
    {
        grow = avail;
    }
    self->m_20 = (int)grow;
    if (avail >= (unsigned int)self->m_a94)
    {
        FUN_00d88040(1);
    }
    LeaveCriticalSection(guard.cs);
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef void(__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

struct hkFreeListBlock
{
    hkFreeListBlock* m_next;
};

struct hkFreeListW
{
    void* m_free;
    unsigned int m_iFirstIndex;
    unsigned int m_unk08;
    hkFreeListBlock* m_activeBlocks;
    hkFreeListBlock* m_pFreeBlocks;

    static int _getNumBlocks(const hkFreeListBlock* blocks)
    {
        int num = 0;
        while (blocks)
        {
            num++;
            blocks = blocks->m_next;
        }
        return num;
    }
    int getTotalNumBlocks() const
    {
        return _getNumBlocks(m_pFreeBlocks) + _getNumBlocks(m_activeBlocks);
    }
    void CollectFreeNodes(hkFreeListBlock** blocks, int numBlocks);
    void FUN_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
};

struct hkMemoryAllocatorW
{
    virtual ~hkMemoryAllocatorW();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemChunkW
{
    unsigned int m_prevFoot;
    unsigned int m_pFirstNode;
};

struct hkLargeBlockIteratorW
{
    hkMemChunkW* m_pCurrentMemoryChunk;
    void* m_pHandlePage;
    void* m_kRayEnd;
    bool isValid() const
    {
        return m_pCurrentMemoryChunk != 0;
    }
    void* GetChunkPayload() const
    {
        return (char*)m_pCurrentMemoryChunk + 0x10;
    }
    unsigned int GetLogicalSize() const
    {
        return m_pCurrentMemoryChunk->m_pFirstNode & ~3u;
    }
    hkBool isInuse() const
    {
        return (m_pCurrentMemoryChunk->m_pFirstNode & 2) != 0;
    }
};

struct hkLargeBlockAllocatorW
{
    hkLargeBlockIteratorW FUN_00dd8b20();
    hkBool AdvanceState(hkLargeBlockIteratorW& iter);
};

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl FUN_00dd7d00(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

inline void quickSortPointers(void** arr, int numElem)
{
    if (numElem > 1)
    {
        FUN_00dd7d00(arr, 0, numElem - 1, CompareLessThan);
    }
}

class hkFreeListAllocatorW
{
  public:
    void* m_vtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    hkMemoryAllocatorW* m_blockAllocator;
    hkLargeBlockAllocatorW m_kLargeBlockAllocator;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7c;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8c;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9c;
    int m_unka0;
    int m_unka4;
    int m_unka8;
    int m_unkac;
    int m_unkb0;
    int m_unkb4;
    int m_unkb8;
    int m_unkbc;
    int m_unkc0;
    int m_unkc4;
    int m_unkc8;
    int m_unkcc;
    int m_unkd0;
    int m_unkd4;
    int m_unkd8;
    int m_unkdc;
    int m_unke0;
    int m_unke4;
    int m_unke8;
    int m_unkec;
    int m_unkf0;
    int m_unkf4;
    int m_unkf8;
    int m_unkfc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13c;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14c;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15c;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16c;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17c;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18c;
    hkFreeListW* m_pFreeLists[41];
    int m_iFreeListCount;

    int walkMemory(hkMemoryWalkCallback callback, void* param);
};

// Collects free-list nodes, calls callback for other large-block chunks, then asks each free list to invoke its callback.
// @fnv 0x00d600c0
int hkFreeListAllocatorW::walkMemory(hkMemoryWalkCallback callback, void* apContext)
{
    int numBlocks = 0;
    for (int i = 0; i < m_iFreeListCount; i++)
    {
        numBlocks += m_pFreeLists[i]->getTotalNumBlocks();
    }

    hkFreeListBlock** blocks =
        (hkFreeListBlock**)m_blockAllocator->AllocateMemoryBlock(numBlocks * sizeof(hkFreeListBlock*));
    if (!blocks)
    {
        return 1;
    }

    {
        hkFreeListBlock** cur = blocks;
        for (int i = 0; i < m_iFreeListCount; i++)
        {
            hkFreeListW* freeList = m_pFreeLists[i];
            int numListBlocks = freeList->getTotalNumBlocks();
            freeList->CollectFreeNodes(cur, numListBlocks);
            cur += numListBlocks;
        }
    }

    quickSortPointers((void**)blocks, numBlocks);

    {
        hkFreeListBlock** curBlock = blocks;
        hkLargeBlockIteratorW iter = m_kLargeBlockAllocator.FUN_00dd8b20();
        for (; iter.isValid(); m_kLargeBlockAllocator.AdvanceState(iter))
        {
            void* block = iter.GetChunkPayload();
            if (block == (void*)*curBlock)
            {
                curBlock++;
                continue;
            }
            callback(block, iter.GetLogicalSize(), iter.isInuse(), 0, apContext);
        }
    }

    m_blockAllocator->ReleaseBlock(blocks, numBlocks * sizeof(hkFreeListBlock*));

    for (int i = 0; i < m_iFreeListCount; i++)
    {
        m_pFreeLists[i]->FUN_00dd78f0(callback, i + 1, apContext);
    }
    return 0;
}

struct PoolFreeBlock
{
    PoolFreeBlock* m_pNext;
};

struct PoolFreeList
{
    PoolFreeBlock* m_pHead;
    int m_iBlockSize;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iArrayLength;
};

struct PoolFallbackAlloc
{
    virtual void* v00();
    virtual void* v04();
    virtual void Free(void* apBlock);
};

struct FUN_00d5f980_cls
{
    int unk00;
    char m_kLock[0x18];
    int m_iTotal;
    int unk20;
    int unk24;
    PoolFallbackAlloc m_kFallback;
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
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    PoolFreeList* m_apLists[41];

    void blockFree(void* apBlock, int aiNumBytes);
};

// Returns apBlock to the pool free list for sizes up to 0x280 bytes, or to m_kFallback for larger sizes, updating m_iTotal.
// @fnv 0x00d5f980
void FUN_00d5f980_cls::blockFree(void* apBlock, int aiNumBytes)
{
    if (apBlock == 0)
        return;

    EnterCriticalSection(&m_kLock);

    if (aiNumBytes <= 0x280)
    {
        PoolFreeList* pList = m_apLists[(aiNumBytes + 0xf) >> 4];
        int iOldCount = pList->m_iArrayLength;
        pList->m_iArrayLength = iOldCount + 1;
        ((PoolFreeBlock*)apBlock)->m_pNext = pList->m_pHead;
        int iDelta = (pList->m_iArrayLength - iOldCount) * pList->m_iBlockSize;
        pList->m_pHead = (PoolFreeBlock*)apBlock;
        m_iTotal += iDelta;
    }
    else
    {
        m_kFallback.Free(apBlock);
    }

    LeaveCriticalSection(&m_kLock);
}

struct S_00d5fb70
{
    int unk0;
    SixIntegerRecord m_kCriticalSection;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    void setMemorySoftLimit(int value);
};

// Sets unkA94 to value while holding m_kCriticalSection.
// @fnv 0x00d5fb70
void S_00d5fb70::setMemorySoftLimit(int value)
{
    EnterCriticalSection(&m_kCriticalSection);
    unkA94 = value;
    LeaveCriticalSection(&m_kCriticalSection);
}

// ---- stand-in models of the objects the original code touches -------------
// The unit file only names hkFreeListAllocator, so the layout below is
// derived from the disassembly of getMemoryStatistics itself.

struct HkFLA_CritSec
{  // +0x04 : a CRITICAL_SECTION
    void* m_kAudioDefinition;
    int lockCount;
    int recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned int spinCount;
};

struct HkFLA_Out
{  // the 24 byte result block of FUN_00dd7430
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
};

struct HkFLA_Elem
{  // one entry of the element array
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    void FUN_00dd7430(HkFLA_Out* out);
};

struct HkFLA_Poly
{  // the object at +0x24 (virtual at +0x18)
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

struct HkFLA_Stats
{  // the out parameter
    int unk00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
};

struct HkFLA_Sub
{                                         // the sub object at +0x28 (its size is only
    void FUN_00dd8d70(HkFLA_Stats* out);  // known from the layout below)
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    int unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110, unk114;
    int unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164;
    int unk168;
};

struct HkFLA_StandIn
{
    int unk00;                 // +0x00
    HkFLA_CritSec m_cs;        // +0x04
    int unk1c;                 // +0x1c
    int f20;                   // +0x20
    HkFLA_Poly* f24;           // +0x24
    HkFLA_Sub f28;             // +0x28
    HkFLA_Elem* m_pElems[41];  // +0x190
    int m_uiItemCount;         // +0x234
    void getMemoryStatistics(HkFLA_Stats* out);
};

// Gathers aggregate statistics from all elements into out while holding the critical section.
// @fnv 0x00d5f750
void HkFLA_StandIn::getMemoryStatistics(HkFLA_Stats* apStats)
{
    HkFLA_CritSec* cs = &m_cs;
    EnterCriticalSection((void*)cs);
    f28.FUN_00dd8d70(apStats);
    // The original keeps a 24 byte block on the stack here and accumulates
    // into its first dword only; the dead members lose their stores but the
    // frame slot (and with it the frame size) stays.
    HkFLA_Out stTotals = {0, 0, 0, 0, 0, 0};
    int totalSize = 0;  // sum of the elements' f04
    int totalArea = 0;  // sum of the elements' f0c
    for (int i = 0; i < m_uiItemCount; i++)
    {
        HkFLA_Elem* e = m_pElems[i];
        HkFLA_Out s = {0, 0, 0, 0, 0, 0};
        e->FUN_00dd7430(&s);
        if (e->f00 != 0 || e->f20 < e->f24)
        {
            unsigned int uiValue = e->f04;
            if (uiValue > apStats->f14)
                apStats->f14 = uiValue;
        }
        totalArea += s.f0c;
        totalSize += s.f04;
        stTotals.f00 += s.f00;
    }
    apStats->f0c += totalArea;
    apStats->f04 += totalSize - stTotals.f00;
    apStats->f08 = f20;
    int iResult = f24->v6();
    if (iResult == -1)
        apStats->f10 = iResult;
    else
        apStats->f10 = apStats->f0c + iResult;
    LeaveCriticalSection((void*)cs);
}

struct ItemObj
{
    void __thiscall FUN_00dd7140_q(unsigned char* ok);
};

struct AllocModel
{
    int unk00;
    SixIntegerRecord m_cs;
    int unk1c;
    unsigned char* m_pByteData;
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
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEc;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFc;
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
    ItemObj* m_items[41];
    int m_uiItemCount;

    bool* __thiscall isOk(bool* __restrict p);
};

// Locks m_cs, sets *p to 1, calls each item's method until its output byte is zero, then returns p.
// @fnv 0x00d5f890
bool* __thiscall AllocModel::isOk(bool* __restrict pbSuccess)
{
    EnterCriticalSection(&m_cs);
    *pbSuccess = 1;
    for (int i = 0; i < m_uiItemCount; i++)
    {
        unsigned char ok;
        m_items[i]->FUN_00dd7140_q(&ok);
        if (!ok)
        {
            *pbSuccess = 0;
            break;
        }
    }
    LeaveCriticalSection(&m_cs);
    return pbSuccess;
}

struct FUN_00d5fac0_item
{
    int unk00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;
    int Compact();
    void FUN_00dd7360();
};

struct FUN_00d5fac0_sub
{
    int unk00;
    void PurgeAndSelectBlock();
};

struct FUN_00d5fac0_cls
{
    int unk00;
    char m_lock[0x18];
    int m_1c;
    int unk20;
    int unk24;
    FUN_00d5fac0_sub m_28;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    FUN_00d5fac0_item* m_items[41];
    int m_uiItemCount;
    void garbageCollect();
};

// Locks m_lock, iterates m_items calling FUN_00dd7360 and accumulating m_1c, retrying while flag and retry are set, then calls m_28.FUN_00dd8790.
// @fnv 0x00d5fac0
void FUN_00d5fac0_cls::garbageCollect()
{
    void* cs = &m_lock;
    EnterCriticalSection(cs);
    bool retry = false;
    bool flag;
    do
    {
        flag = false;
        for (int i = 0; i < m_uiItemCount; ++i)
        {
            FUN_00d5fac0_item* p = m_items[i];
            int saved = p->m_28;
            if (p->Compact() < 0)
            {
                retry = true;
            }
            if (p->m_10 != 0)
            {
                flag = true;
            }
            p->FUN_00dd7360();
            m_1c += (p->m_28 - saved) * p->m_04;
        }
    } while (flag && retry);
    m_28.PurgeAndSelectBlock();
    LeaveCriticalSection(cs);
}

struct CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

// Stand-in for the Fallout: New Vegas pool allocator that owns bufAlloc.

void __cdecl FUN_00d88040(int);

// One unused element of a size class.
struct hkPoolNode
{
    hkPoolNode* next;
};

// One size class of the pool.
struct hkPoolBucket
{
    hkPoolNode* freeHead;  // +0x00 head of the list of unused elements
    int elemSize;          // +0x04 size of a single element
    int unk08;             // +0x08
    void* freeNodes;       // +0x0c
    void* blocks;          // +0x10
    void* block;           // +0x14
    unsigned int align;    // +0x18
    int maxCount;          // +0x1c
    char* bump;            // +0x20 next element inside the current block
    char* bumpEnd;         // +0x24 end of the current block
    int count;             // +0x28 number of elements handed out
    void* AllocateElement();  // carve a new element out of a fresh block
};

// Allocator used for requests that are too large for the size classes.
struct hkPoolLarge
{
    virtual void* FUN_00dd8790_v0();
    virtual void* FUN_00dd8790_v1(int size);
    virtual void* FUN_00dd8790_v2(int size);
    int unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034;
    int unk038, unk03c, unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c, unk060, unk064;
    int unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094;
    int unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
};

// The pool itself.
struct hkPool
{
    int unk00;                        // +0x00
    CRITICAL_SECTION m_lock;          // +0x04
    unsigned int m_uiBufferCapacity;  // +0x1c bytes currently handed out (negated)
    unsigned int m_maxFree;           // +0x20
    int unk24;                        // +0x24
    hkPoolLarge m_large;              // +0x28
    unsigned int m_total;             // +0xe8
    hkPoolBucket* m_class[41];        // +0xec one bucket per size class
    hkPoolBucket* m_bucket[41];       // +0x190 every bucket of the pool
    int m_uiItemCount;                // +0x234
    void* m_kNode;                     // +0x238
    int unk23c;                       // +0x23c
    int unk240;                       // +0x240
    int unk244, unk248, unk24c, unk250, unk254, unk258;
    int unk25c, unk260, unk264, unk268, unk26c, unk270;
    int unk274, unk278, unk27c, unk280, unk284, unk288;
    int unk28c, unk290, unk294, unk298, unk29c, unk2a0;
    int unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8;
    int unk2bc, unk2c0, unk2c4, unk2c8, unk2cc, unk2d0;
    int unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8;
    int unk2ec, unk2f0, unk2f4, unk2f8, unk2fc, unk300;
    int unk304, unk308, unk30c, unk310, unk314, unk318;
    int unk31c, unk320, unk324, unk328, unk32c, unk330;
    int unk334, unk338, unk33c, unk340, unk344, unk348;
    int unk34c, unk350, unk354, unk358, unk35c, unk360;
    int unk364, unk368, unk36c, unk370, unk374, unk378;
    int unk37c, unk380, unk384, unk388, unk38c, unk390;
    int unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8;
    int unk3ac, unk3b0, unk3b4, unk3b8, unk3bc, unk3c0;
    int unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8;
    int unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0;
    int unk3f4, unk3f8, unk3fc, unk400, unk404, unk408;
    int unk40c, unk410, unk414, unk418, unk41c, unk420;
    int unk424, unk428, unk42c, unk430, unk434, unk438;
    int unk43c, unk440, unk444, unk448, unk44c, unk450;
    int unk454, unk458, unk45c, unk460, unk464, unk468;
    int unk46c, unk470, unk474, unk478, unk47c, unk480;
    int unk484, unk488, unk48c, unk490, unk494, unk498;
    int unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0;
    int unk4b4, unk4b8, unk4bc, unk4c0, unk4c4, unk4c8;
    int unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0;
    int unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8;
    int unk4fc, unk500, unk504, unk508, unk50c, unk510;
    int unk514, unk518, unk51c, unk520, unk524, unk528;
    int unk52c, unk530, unk534, unk538, unk53c, unk540;
    int unk544, unk548, unk54c, unk550, unk554, unk558;
    int unk55c, unk560, unk564, unk568, unk56c, unk570;
    int unk574, unk578, unk57c, unk580, unk584, unk588;
    int unk58c, unk590, unk594, unk598, unk59c, unk5a0;
    int unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8;
    int unk5bc, unk5c0, unk5c4, unk5c8, unk5cc, unk5d0;
    int unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8;
    int unk5ec, unk5f0, unk5f4, unk5f8, unk5fc, unk600;
    int unk604, unk608, unk60c, unk610, unk614, unk618;
    int unk61c, unk620, unk624, unk628, unk62c, unk630;
    int unk634, unk638, unk63c, unk640, unk644, unk648;
    int unk64c, unk650, unk654, unk658, unk65c, unk660;
    int unk664, unk668, unk66c, unk670, unk674, unk678;
    int unk67c, unk680, unk684, unk688, unk68c, unk690;
    int unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8;
    int unk6ac, unk6b0, unk6b4, unk6b8, unk6bc, unk6c0;
    int unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8;
    int unk6dc, unk6e0, unk6e4, unk6e8, unk6ec, unk6f0;
    int unk6f4, unk6f8, unk6fc, unk700, unk704, unk708;
    int unk70c, unk710, unk714, unk718, unk71c, unk720;
    int unk724, unk728, unk72c, unk730, unk734, unk738;
    int unk73c, unk740, unk744, unk748, unk74c, unk750;
    int unk754, unk758, unk75c, unk760, unk764, unk768;
    int unk76c, unk770, unk774, unk778, unk77c, unk780;
    int unk784, unk788, unk78c, unk790, unk794, unk798;
    int unk79c, unk7a0, unk7a4, unk7a8, unk7ac, unk7b0;
    int unk7b4, unk7b8, unk7bc, unk7c0, unk7c4, unk7c8;
    int unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0;
    int unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8;
    int unk7fc, unk800, unk804, unk808, unk80c, unk810;
    int unk814, unk818, unk81c, unk820, unk824, unk828;
    int unk82c, unk830, unk834, unk838, unk83c, unk840;
    int unk844, unk848, unk84c, unk850, unk854, unk858;
    int unk85c, unk860, unk864, unk868, unk86c, unk870;
    int unk874, unk878, unk87c, unk880, unk884, unk888;
    int unk88c, unk890, unk894, unk898, unk89c, unk8a0;
    int unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8;
    int unk8bc, unk8c0, unk8c4, unk8c8, unk8cc, unk8d0;
    int unk8d4, unk8d8, unk8dc, unk8e0, unk8e4, unk8e8;
    int unk8ec, unk8f0, unk8f4, unk8f8, unk8fc, unk900;
    int unk904, unk908, unk90c, unk910, unk914, unk918;
    int unk91c, unk920, unk924, unk928, unk92c, unk930;
    int unk934, unk938, unk93c, unk940, unk944, unk948;
    int unk94c, unk950, unk954, unk958, unk95c, unk960;
    int unk964, unk968, unk96c, unk970, unk974, unk978;
    int unk97c, unk980, unk984, unk988, unk98c, unk990;
    int unk994, unk998, unk99c, unk9a0, unk9a4, unk9a8;
    int unk9ac, unk9b0, unk9b4, unk9b8, unk9bc, unk9c0;
    int unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8;
    int unk9dc, unk9e0, unk9e4, unk9e8, unk9ec, unk9f0;
    int unk9f4, unk9f8, unk9fc, unka00, unka04, unka08;
    int unka0c, unka10, unka14, unka18, unka1c, unka20;
    int unka24, unka28, unka2c, unka30, unka34, unka38;
    int unka3c, unka40, unka44, unka48, unka4c, unka50;
    int unka54, unka58, unka5c, unka60, unka64, unka68;
    int unka6c, unka70, unka74, unka78, unka7c, unka80;
    int unka84, unka88, unka8c, unka90;
    unsigned int m_pFreeList;  // +0xa94
    void* bufAlloc(int* p);
};

// Allocates a block of the requested size from the pool's free list, bump allocator, or large allocator, and updates the high-water mark for free memory.
// @fnv 0x00d5fca0
void* hkPool::bufAlloc(int* apSize)
{
    int size = *apSize;
    EnterCriticalSection(&this->m_lock);
    void* result;
    if (size <= 0x280)
    {
        hkPoolBucket* b = this->m_class[(size + 15) >> 4];
        hkPoolNode* node = b->freeHead;
        int oldCount = b->count;
        if (node)
        {
            b->count = oldCount - 1;
            b->freeHead = node->next;
            result = node;
        }
        else if (b->bump >= b->bumpEnd)
        {
            result = b->AllocateElement();
        }
        else
        {
            result = b->bump;
            b->count = oldCount - 1;
            b->bump += b->elemSize;
        }
        this->m_uiBufferCapacity += (b->count - oldCount) * b->elemSize;
        *apSize = b->elemSize;
    }
    else
    {
        result = this->m_large.FUN_00dd8790_v1(size);
    }
    unsigned int free = this->m_total - this->m_uiBufferCapacity;
    unsigned int maxFree = this->m_maxFree;
    if (free > maxFree)
        maxFree = free;
    this->m_maxFree = maxFree;
    if (free >= this->m_pFreeList)
        FUN_00d88040(1);
    LeaveCriticalSection(&this->m_lock);
    return result;
}

struct QuitDeleteView
{
    __declspec(noinline) void FUN_00d5fc70(FUN_00dd7200_cls* entry);
};

struct QuitLargeBlockView
{
    void ProcessAllItems();
};

struct QuitAllocator : hkFreeListAllocatorW
{
    void quit();
};

// Frees each non-null free list, nulls later matching pointers, then calls the large-block allocator's cleanup.
// @fnv 0x00d5ff50
void QuitAllocator::quit()
{
    if (m_iFreeListCount > 0)
    {
        int index = 1;
        hkFreeListW** slot = m_pFreeLists;
        do
        {
            hkFreeListW* entry = *slot;
            if (entry)
            {
                reinterpret_cast<QuitDeleteView*>(this)->FUN_00d5fc70(reinterpret_cast<FUN_00dd7200_cls*>(entry));
                int later = index;
                if (later < m_iFreeListCount)
                {
                    hkFreeListW** next = slot + 1;
                    do
                    {
                        if (*next == entry)
                        {
                            *next = 0;
                        }
                        ++next;
                        ++later;
                    } while (later < m_iFreeListCount);
                }
            }
            ++index;
            ++slot;
        } while (index - 1 < m_iFreeListCount);
    }
    reinterpret_cast<QuitLargeBlockView*>(&m_kLargeBlockAllocator)->ProcessAllItems();
}

extern "C" int DAT_010d1464;
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct EmbeddedItem
{
    int m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30;
    void __thiscall FUN_00dd7200();
};
struct EmbeddedMember
{
    void __thiscall FUN_00dd7ec0();
};
struct FUN_00d5ffd0_class
{
    void* vtable;
    void __thiscall quit();
    void __thiscall FUN_00cbf1a0();
    void __thiscall FUN_00d5ffd0();
};
// Sets the vtable, calls cleanup and member functions, deletes the critical section, then calls another member function.
// @fnv 0x00d5ffd0
void FUN_00d5ffd0_class::FUN_00d5ffd0()
{
    vtable = &DAT_010d1464;
    quit();
    EmbeddedItem* end = reinterpret_cast<EmbeddedItem*>(reinterpret_cast<char*>(this) + 0xa94);
    for (int i = 40; i >= 0; --i)
    {
        (--end)->FUN_00dd7200();
    }
    reinterpret_cast<EmbeddedMember*>(reinterpret_cast<char*>(this) + 0x28)->FUN_00dd7ec0();
    DeleteCriticalSection(reinterpret_cast<char*>(this) + 4);
    FUN_00cbf1a0();
}

extern "C" void __debugbreak();
namespace FreeListCreationView {
struct DeleteView
{
    __declspec(noinline) void FUN_00d5fc70(FUN_00dd7200_cls*);
};
struct Slot17
{
    int unk00;
    int f4;
    int pad08;
    int pad0C;
    int pad10;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int pad24;
    int pad28;
    int pad2C;
    int pad30;
    void FUN_00dd7650(int a1, int a2, int a3, void* out);
};
struct Owner17
{
    int unk00;
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
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    FUN_00dd7200_cls* slots[41];
    int count234;
    Slot17* volatile cur238;
    Slot17* end23c;
    FUN_00dd7200_cls* FUN_00d60020(int a1, int a2, int a3);
};
// Advances cur238, initializes s when nonnull, then returns a matching slot or registers and returns s.
// @fnv 0x00d60020
FUN_00dd7200_cls* Owner17::FUN_00d60020(int aiParam1, int aiParam2, int aiParam3)
{
    if (cur238 >= end23c)
    {
        __debugbreak();
    }
    Slot17* s = cur238;
    cur238 = s + 1;
    if (s != 0)
    {
        s->FUN_00dd7650(aiParam1, aiParam2, aiParam3, &unk28);
    }
    for (int i = 0; i < count234; i++)
    {
        if (((Slot17*)slots[i])->f4 == s->f4)
        {
            ((DeleteView*)this)->FUN_00d5fc70((FUN_00dd7200_cls*)s);
            return slots[i];
        }
    }
    slots[count234] = (FUN_00dd7200_cls*)s;
    count234++;
    return (FUN_00dd7200_cls*)s;
}
}

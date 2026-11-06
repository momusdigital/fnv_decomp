
// src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb7460_class
{
    int __thiscall FUN_00cb7460(int value);
};

// @fnv 0x00cb7460
int __thiscall FUN_00cb7460_class::FUN_00cb7460(int value)
{
    if (value + 1 == *(int*)((char*)this + 8))
        return *(int*)this;
    return 0x200;
}

// If the slot index at p+0x22 is not 0xffff, clears the entry in the array at thisPtr+0x40 and resets the index to 0xffff.
// @fnv 0x00cb3fd0
void ClearSlotReference(int* thisPtr, int* p)
{
    unsigned short* s = (unsigned short*)((char*)p + 0x22);
    if (*s != 0xffff)
    {
        int* base = *(int**)((char*)thisPtr + 0x40);
        base[*s] = 0;
        *s = 0xffff;
    }
}

void FUN_00d27ac0(int first, int second);
void FUN_00d00960(int first, int second);
// @fnv 0x00cb3c80
void FUN_00cb3c80(int first, int second)
{
    FUN_00d27ac0(first, second);
    FUN_00d00960(first, second);
}

struct FUN_00cb3ca0_object
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
    int refCount94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};

void __cdecl FUN_00d27ac0(FUN_00cb3ca0_object* object, int* value);
void __cdecl FUN_00d00960(FUN_00cb3ca0_object* object, int* value);

// @fnv 0x00cb3ca0
int* __cdecl FUN_00cb3ca0(FUN_00cb3ca0_object* object, int* value, int shouldNotify)
{
    ++object->refCount94;
    FUN_00d27ac0(object, value);
    if (shouldNotify != 0)
    {
        FUN_00d00960(object, value);
    }
    --object->refCount94;
    if (object->refCount94 == 0 && object->flag9c == 0)
    {
        if (object->unk8c != 0)
        {
            object->FUN_00c91120();
        }
        if (object->unkA4 == 1 && object->unk90 != 0)
        {
            object->FUN_00c91140();
        }
    }
    return value;
}

struct S_00cb3da0_Ctx
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
};

void NotifyTargets(S_00cb3da0_Ctx* ctx, void* p);
void DetachRecord(void* p);

// If ctx->unk144 is nonzero, calls NotifyTargets with ctx and p, then always calls DetachRecord on p.
// @fnv 0x00cb3da0
void FUN_00cb3da0(S_00cb3da0_Ctx* ctx, void* p)
{
    if (ctx->unk144 != 0)
        NotifyTargets(ctx, p);
    DetachRecord(p);
}

struct CB3DD0Collidable
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
    unsigned char unk24;
    unsigned char m_flags;
};

struct CB3DD0Entity
{
    int unk00;
    int unk04;
    CB3DD0Collidable* m_kCollidable;
};

struct CB3DD0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk098;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk09D;
    unsigned char unk09E;
    unsigned char unk09F;
    int unk0A0;
    int m_iPendingOperationQueueCount;
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
    void* m_kListener;

    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount)
            return;
        if (m_bBlockExecutingPendingOperations)
            return;
        if (m_iPendingOperationCount)
            ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
            ExecutePendingOperationQueues();
    }
};

void __cdecl NotifyTargets(CB3DD0World* world, CB3DD0Entity* entity);
void __cdecl DetachRecord(CB3DD0Entity* entity);

// @fnv 0x00cb3dd0
void __cdecl FUN_00cb3dd0(CB3DD0World* world, CB3DD0Entity* entity, int fireCallbacks)
{
    CB3DD0Collidable* collidable = entity->m_kCollidable;
    collidable->m_flags = (collidable->m_flags & ~2) | 1;
    if (world->m_iCriticalOperationsLockCount)
    {
        if (fireCallbacks && world->m_kListener)
            NotifyTargets(world, entity);
        DetachRecord(entity);
        return;
    }
    world->lockCriticalOperations();
    if (fireCallbacks && world->m_kListener)
        NotifyTargets(world, entity);
    DetachRecord(entity);
    world->unlockCriticalOperations();
}

struct FUN_00d070b0_class
{
    void FUN_00d070b0();
};
struct CleanupList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d070b0_class* finalObject;
    int unk24;
    FUN_00d070b0_class** firstObjects;
    int firstCount;
    int unk30;
    FUN_00d070b0_class** secondObjects;
    int secondCount;
};
// Calls FUN_00d070b0 on every object in firstObjects and secondObjects in reverse order, then on finalObject.
// @fnv 0x00cb3e90
void __cdecl FUN_00cb3e90(CleanupList* apCleanupList)
{
    int i = apCleanupList->firstCount - 1;
    while (i >= 0)
    {
        apCleanupList->firstObjects[i]->FUN_00d070b0();
        --i;
    }
    i = apCleanupList->secondCount - 1;
    while (i >= 0)
    {
        apCleanupList->secondObjects[i]->FUN_00d070b0();
        --i;
    }
    apCleanupList->finalObject->FUN_00d070b0();
}

struct Obj;

struct Agent
{
    virtual void v0(int);
    char pad0[0x20 - 4];
    unsigned short m_20;
    char pad1[0x4c - 0x22];
    int m_4c;
    __declspec(nothrow) void RemoveItem(Obj* o);
};

struct Obj
{
    int pad0[2];
    int m_8;
    char pad1[0xc8 - 0xc];
    bool m_c8;
    char pad2[3];
    Agent* m_cc;
};

__declspec(nothrow) void __cdecl RemoveListItem(Obj* o, Agent* a);

// Clears o->m_8, calls the agent's RemoveItem, and if the agent's m_20 is not 0xffff, m_4c is 0 and ctx->m_c8 is set, calls RemoveListItem and v0(1).
// @fnv 0x00cb4740
void __cdecl FUN_00cb4740(Obj* ctx, Obj* o)
{
    Agent* a = o->m_cc;
    o->m_8 = 0;
    a->RemoveItem(o);
    if (a->m_20 != 0xffff && a->m_4c == 0 && ctx->m_c8)
    {
        RemoveListItem(ctx, a);
        a->v0(1);
    }
}

struct S_00cb5d00_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00cb5d00_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
struct S_00cb5d00_Router
{
    S_00cb5d00_Stack m_aiEntries;
    S_00cb5d00_Heap* m_pStreamAllocator;
    static S_00cb5d00_Router& FUN_00c85750() throw();
    S_00cb5d00_Stack& stack() throw()
    {
        return m_aiEntries;
    }
    S_00cb5d00_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb5d00_Elem
{
    int unk00;
    int unk04;
};
template <class T> struct S_00cb5d00_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00cb5d00_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~S_00cb5d00_Array() throw()
    {
        _clearAndDeallocate(*S_00cb5d00_Router::FUN_00c85750().m_pStreamAllocator);
    }
    void _clearAndDeallocate(S_00cb5d00_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct S_00cb5d00_LocalArray : S_00cb5d00_Array<T>
{
    T* m_pStackAllocation;
    __forceinline S_00cb5d00_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)S_00cb5d00_Router::FUN_00c85750().stack().allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00cb5d00_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        S_00cb5d00_Router::FUN_00c85750().stack().deallocateStack(mem);
    }
};
struct S_00cb5d00_Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out);
    void query(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out) throw()
    {
        unk1C(key, out);
    }
};
struct S_00cb5d00_Sink
{
    void DispatchPairs(S_00cb5d00_Elem* data, int n) throw();
};
struct S_00cb5d00_Owner
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
    S_00cb5d00_Source* unk58;
    int unk5C;
    int unk60;
    S_00cb5d00_Sink* unk64;
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
};
struct S_00cb5d00_Query
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
};
// @fnv 0x00cb5d00
void FUN_00cb5d00(S_00cb5d00_Owner* owner, S_00cb5d00_Query* query)
{
    S_00cb5d00_LocalArray<S_00cb5d00_Elem> results(owner->unk338);
    owner->unk58->query(&query->unk24, &results);
    if (results.m_iElementCount != 0)
        owner->unk64->DispatchPairs(results.m_data, results.m_iElementCount);
}

struct Object
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
    int** items;
    int count;
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
    unsigned char enabled;
};
extern void __cdecl PropagateStateToChildren(Object*, int*);
// If object->enabled is set, walks object->items backwards and calls PropagateStateToChildren for each item whose byte at offset 0x25 has bits 0-1 set.
// @fnv 0x00cb6f30
void __cdecl FUN_00cb6f30(Object* object)
{
    if (object->enabled != 0)
    {
        int index = object->count - 1;
        for (; index >= 0; --index)
        {
            int* item = object->items[index];
            if ((*(unsigned char*)((char*)item + 0x25) & 3) != 0)
                PropagateStateToChildren(object, item);
        }
    }
}

struct Box
{
    char pad[0x14];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

struct Holder
{
    char pad[0x30];
    Box* box;
};

struct Stats
{
    char pad[8];
    int maxv;
    int sum0;
    int sum1;
    int sum2;
    void AccumulateStats(Holder* h, const int* s);
};

// If the holder has a box, updates maxv and the three sums from s, adds s[1..3] into the box fields, and raises maxv to the box's a.
// @fnv 0x00cb74d0
void Stats::AccumulateStats(Holder* apHolder, const int* aiStats)
{
    if (apHolder->box)
    {
        {
            int t = aiStats[0];
            maxv = maxv > t ? maxv : t;
        }
        maxv = maxv > aiStats[1] ? maxv : aiStats[1];
        sum0 += aiStats[1];
        sum1 += aiStats[2];
        sum2 += aiStats[3];
        Box* b = apHolder->box;
        int nc = b->c + aiStats[3];
        int na = b->a + aiStats[1];
        b->b += aiStats[2];
        b->c = nc;
        b->a = na;
        int a = apHolder->box->a;
        maxv = maxv > a ? maxv : a;
    }
}

class S_00dd7d00_Bool
{
  public:
    S_00dd7d00_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct S_00dd7d00_Item;

typedef S_00dd7d00_Bool(__cdecl* S_00dd7d00_Less)(S_00dd7d00_Item* a, S_00dd7d00_Item* b);

// Sorts the range [d, h] of pArr in place with a Hoare-style quicksort using cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00dd7d00
void FUN_00dd7d00(S_00dd7d00_Item** apItems, int aiLow, int aiHigh, S_00dd7d00_Less apfnLess)
{
    int i, j;
    __declspec(align(16)) S_00dd7d00_Item* pPivot;
begin:
    i = aiHigh;
    j = aiLow;
    pPivot = apItems[(aiLow + aiHigh) >> 1];
    do
    {
        while (apfnLess(apItems[j], pPivot))
            j++;
        while (apfnLess(pPivot, apItems[i]))
            i--;
        if (i >= j)
        {
            if (i != j)
            {
                S_00dd7d00_Item* pTemp = apItems[i];
                apItems[i] = apItems[j];
                apItems[j] = pTemp;
            }
            i--;
            j++;
        }
    } while (j <= i);
    if (aiLow < i)
        FUN_00dd7d00(apItems, aiLow, i, apfnLess);
    if (j < aiHigh)
    {
        aiLow = j;
        goto begin;
    }
}

struct S_00c6aca0_Tls
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
    int unk0d8;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00c6aca0_Tls DAT_tls;

struct S_00c6aca0_Ctx
{
    int saved;
    __forceinline S_00c6aca0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00c6aca0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};

struct S_00c6aca0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00c6aca0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c6aca0_Heap* m10;
    __forceinline S_00c6aca0_Heap& heap()
    {
        return *m10;
    }
};
S_00c6aca0_Router* FUN_00c85750() throw();

struct S_00c6aca0_Item
{
    virtual ~S_00c6aca0_Item();
};
struct S_00c6aca0_Arr4
{
    S_00c6aca0_Item** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            int n = cap & 0x3fffffff;
            h.ReturnMemory(m_data, n * 4);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr4() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00c6aca0_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 8);
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr8() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

struct S_00c6aca0_Cont
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S_00c6aca0_Cont();
    void FUN_00c67f20();
};

struct S_00c6aca0_Mm
{
    void FUN_00aa4060(int p);
};
extern S_00c6aca0_Mm DAT_011f6238;
extern int DAT_012677a4;

struct S_00c6aca0_Ref
{
    void FUN_00c905b0();
};
struct S_00c6aca0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S_00c6aca0_Base();
    void FUN_00c876a0();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    __forceinline void callVfn94()
    {
        vfn_94();
    }
};

struct FUN_00c6aca0 : S_00c6aca0_Base
{
    S_00c6aca0_Ref* unk10;
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
    S_00c6aca0_Arr4 unk70;
    S_00c6aca0_Arr8 unk7c;
    int unk88;
    int unk8c;
    S_00c6aca0_Cont unk90;
    ~FUN_00c6aca0();
};

// @fnv 0x00c6aca0
FUN_00c6aca0::~FUN_00c6aca0()
{
    S_00c6aca0_Ctx ctxOuter(0x10);
    --DAT_012677a4;
    {
        S_00c6aca0_Ctx inner(0x10);
        if (unk10)
        {
            callVfn94();
            unk10->FUN_00c905b0();
            unk10 = 0;
        }
    }
    callVfn94();
    FUN_00c876a0();
    {
        int p = unk2c;
        DAT_011f6238.FUN_00aa4060(p);
    }
    {
        int p = unk34;
        DAT_011f6238.FUN_00aa4060(p);
    }
    {
        int p = unk3c;
        DAT_011f6238.FUN_00aa4060(p);
    }
    {
        int p = unk44;
        DAT_011f6238.FUN_00aa4060(p);
    }
    {
        int p = unk4c;
        DAT_011f6238.FUN_00aa4060(p);
    }
    for (int i = 0; i < unk70.m_iElementCount; i++)
    {
        S_00c6aca0_Item* p = unk70.m_data[i];
        if (p)
            delete p;
    }
    unk70.m_iElementCount = 0;
    unk90.FUN_00c67f20();
}

struct S_00cb3f90_Bool
{
    bool m_cBooleanValue;
    S_00cb3f90_Bool(bool b) : m_cBooleanValue(b)
    {}
};

struct S_00cb3f90_Inner
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
    unsigned int unkD4;
};

struct S_00cb3f90_Sub
{
    S_00cb3f90_Inner* m_pInner;
};

struct S_00cb3f90_Obj
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    S_00cb3f90_Sub* m_pSub;
};

// Returns false if b is null, true if a is null, otherwise compares a's inner unkD4 against b's inner unkD4.
// @fnv 0x00cb3f90
S_00cb3f90_Bool FUN_00cb3f90(S_00cb3f90_Obj* pObjA, S_00cb3f90_Obj* pObjB)
{
    if (!pObjB)
        return false;
    if (!pObjA)
        return true;
    return pObjA->m_pSub->m_pInner->unkD4 < pObjB->m_pSub->m_pInner->unkD4;
}

namespace fnv_00cb4000 {
struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_uiEdgeIndex;  // +0x20
    unsigned short unk22;          // +0x22
    unsigned short unk24;          // +0x24
    unsigned char m_flags;         // +0x26 (flags & 3 selects the list)
};

struct ListOwner
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
    ListItem** m_list28;  // +0x28
    int m_count2c;        // +0x2c
    int unk30;            // +0x30
    ListItem** m_list34;  // +0x34
    int m_count38;        // +0x38
};

void ClearSlotReference(int* thisPtr, int* p);

// Removes item from one of the owner's two lists by swapping in the last element, fixes its index, decrements the count, then calls ClearSlotReference.
// @fnv 0x00cb4000
void RemoveListItem(ListOwner* self, ListItem* volatile item)
{
    ListItem* pItem = item;
    if ((pItem->m_flags & 3) == 0)
    {
        ListItem** arr = self->m_list34;
        int last = self->m_count38 - 1;
        arr[pItem->m_uiEdgeIndex] = arr[last];
        self->m_list34[pItem->m_uiEdgeIndex]->m_uiEdgeIndex = pItem->m_uiEdgeIndex;
        self->m_count38--;
    }
    else
    {
        ListItem** arr = self->m_list28;
        int last = self->m_count2c - 1;
        arr[pItem->m_uiEdgeIndex] = arr[last];
        self->m_list28[pItem->m_uiEdgeIndex]->m_uiEdgeIndex = pItem->m_uiEdgeIndex;
        self->m_count2c--;
    }
    ClearSlotReference((int*)self, (int*)pItem);
}
}  // namespace fnv_00cb4000

namespace fnv_00cb5420 {
struct S_00cb5420_Heap;
struct S_00cb5420_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb5420_Heap* m_pStreamAllocator;
    S_00cb5420_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5420_Router& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S_00cb5420_Heap& alloc, void* array, int elemSize);

template <class T> struct S_00cb5420_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _pushBack(S_00cb5420_Heap& alloc, const T& t)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
            ResizeAudioStream(alloc, this, sizeof(T));
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i)
            p[i] = t;
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t)
    {
        _pushBack(FUN_00c85750().heap(), t);
    }
};

struct S_00cb5420_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short m_idx;
    unsigned short unk24;
    unsigned char m_flags;
};

struct S_00cb5420_Container
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    S_00cb5420_Array<S_00cb5420_Item*> m_items;
};

// Clears bits 0x0C in the item's flags; if the item's index is 0xFFFF, assigns it the container's item count and appends the item to the container's array.
// @fnv 0x00cb5420
void AddItemToContainer(S_00cb5420_Container* pContainer, S_00cb5420_Item* item)
{
    item->m_flags &= ~0x0C;
    if (item->m_idx == 0xFFFF)
    {
        item->m_idx = (unsigned short)pContainer->m_items.m_iElementCount;
        pContainer->m_items.AddBack(item);
    }
}
}  // namespace fnv_00cb5420

struct ObjB;
struct ObjA
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
    int m_94;
    void FUN_00c91160(void* p);
};
struct ObjB
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
    int m_cc;
};

struct FUN_00cb5570_arg
{
    unsigned char tag;
    ObjB* owner;
    ObjB* other;
};

void __cdecl FUN_00cb4c60(ObjA* a1, int a2, int a3);

// @fnv 0x00cb5570
void __cdecl FUN_00cb5570(ObjA* apObjA, ObjB* apOwner, ObjB* apOther)
{
    int iOwnerValue = apOwner->m_cc;
    int iOtherValue = apOther->m_cc;
    if (apObjA->m_94 != 0)
    {
        FUN_00cb5570_arg arg;
        arg.tag = 0xc;
        arg.owner = apOwner;
        arg.other = apOther;
        apObjA->FUN_00c91160(&arg);
        return;
    }
    FUN_00cb4c60(apObjA, iOwnerValue, iOtherValue);
}

namespace fnv_00cb59f0 {
struct S_00cb59f0_Elem
{
    int unk00;
    int unk04;
};

struct S_00cb59f0_Xf
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct S_00cb59f0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
};

struct S_00cb59f0_Router
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb59f0_Heap* heap;
};

S_00cb59f0_Router* FUN_00c85750() throw();

struct S_00cb59f0_Local
{
    S_00cb59f0_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    S_00cb59f0_Elem* m_localMem;
    __forceinline S_00cb59f0_Local(int n) throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
        S_00cb59f0_Router* r = FUN_00c85750();
        char* p = r->stackCur;
        r->stackCur = p + ((n * 8 + 0x7f) & 0xffffff80);
        m_data = (S_00cb59f0_Elem*)p;
        m_localMem = m_data;
        m_cap = n | 0x80000000;
    }
    __forceinline ~S_00cb59f0_Local() throw()
    {
        S_00cb59f0_Elem* lm = m_localMem;
        if (lm == m_data)
            m_iElementCount = 0;
        FUN_00c85750()->stackCur = (char*)lm;
        S_00cb59f0_Heap& h = *FUN_00c85750()->heap;
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.vfn_10(m_data, (cap & 0x3fffffff) * 8);
    }
};

struct S_00cb59f0_Obj58
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int* a, S_00cb59f0_Xf* b, S_00cb59f0_Local* c) throw();
};

struct S_00cb59f0_Obj64
{
    void FUN_00cf7080(S_00cb59f0_Elem* data, int n, char* extra) throw();
};

struct S_00cb59f0_Ctx
{
    int unk00;
};

struct S_00cb59f0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S_00cb59f0_B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb59f0_Sub sub;
    int unk28;
    int unk2c;
    S_00cb59f0_Xf unk30;
};

struct S_00cb59f0_A
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
    S_00cb59f0_Obj58* unk58;
    int unk5c;
    int unk60;
    S_00cb59f0_Obj64* unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    S_00cb59f0_Ctx* unk78;
    char* unk7c;
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
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
};

void __cdecl FUN_00d1a330(S_00cb59f0_Ctx* ctx, S_00cb59f0_B** items, int n) throw();

// @fnv 0x00cb59f0
void __cdecl FUN_00cb59f0(S_00cb59f0_A* a, S_00cb59f0_B* b) throw()
{
    S_00cb59f0_Sub* sub = &b->sub;
    if (sub->unk00 != 0)
    {
        S_00cb59f0_Local arr(a->unk338);
        FUN_00d1a330(a->unk78, &b, 1);
        __declspec(align(16)) S_00cb59f0_Xf localXf = b->unk30;
        a->unk58->vfn_14(&sub->unk14, &localXf, &arr);
        if (arr.m_iElementCount > 0)
            a->unk64->FUN_00cf7080(arr.m_data, arr.m_iElementCount, a->unk7c ? a->unk7c + 8 : 0);
    }
}
}  // namespace fnv_00cb59f0

namespace fnv_00cb5b10 {
// QueryEntityIntoBuffer candidate
struct WorldRec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
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
    struct BroadRec* m_pBroadPhaseRecord;
    unsigned int unk5C;
    unsigned int unk60;
    struct DispatchRec* m_pCollisionDispatcher;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    struct FilterRec* m_iFilter;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int m_cap;
};

struct __declspec(align(16)) OutSlot
{
    void* m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct BufAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void BufFree(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    unsigned char* m_cursor;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    BufAllocator* m_pAllocator;
};

struct LocalArr
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
};

struct BroadRec
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Query(void* aabbA, void* aabbB, LocalArr* out);
};

struct DispatchRec
{
    void FUN_00cf7080(void* pairs, int count, void* filter);
};

struct FilterRec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct EntityRec
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(OutSlot* out);
    void FUN_00d07950(OutSlot* out);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct ArrFrame
{
    LocalArr arr;
    unsigned char* saved;
};

struct OutPad
{
    OutSlot out;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

// @fnv 0x00cb5b10
void QueryEntityIntoBuffer(WorldRec* world, EntityRec* apEntity)
{
    unsigned int cap = world->m_cap;
    ArrFrame fr;
    fr.arr.m_pData = 0;
    fr.arr.m_iArrayLength = 0;
    fr.arr.m_uCapBits = 0x80000000u;
    AudioHolder* holder = FUN_00c85750();
    unsigned char* old = holder->m_cursor;
    holder->m_cursor = old + ((cap * 8 + 0x7f) & 0xffffff80u);
    fr.arr.m_pData = old;
    fr.arr.m_uCapBits = cap | 0x80000000u;
    fr.saved = old;

    OutPad outp;
    OutSlot* outPtr = &outp.out;
    apEntity->v18(outPtr);
    world->m_pBroadPhaseRecord->Query(&apEntity->m_24, outPtr, &fr.arr);
    apEntity->FUN_00d07950(outPtr);

    if (fr.arr.m_iArrayLength != 0)
    {
        FilterRec* f = world->m_iFilter;
        void* filter = f != 0 ? (void*)((char*)f + 8) : 0;
        world->m_pCollisionDispatcher->FUN_00cf7080(fr.arr.m_pData, fr.arr.m_iArrayLength, filter);
    }
    unsigned char* saved = fr.saved;
    if (saved == fr.arr.m_pData)
    {
        fr.arr.m_iArrayLength = 0;
    }
    FUN_00c85750()->m_cursor = saved;
    BufAllocator* alloc = FUN_00c85750()->m_pAllocator;
    fr.arr.m_iArrayLength = 0;
    if ((fr.arr.m_uCapBits & 0x80000000u) == 0)
    {
        alloc->BufFree(fr.arr.m_pData, (fr.arr.m_uCapBits & 0x3fffffffu) * 8);
    }
}
}  // namespace fnv_00cb5b10

// Stand-in model for the objects the original touches.
// The polymorphic target: vtable slots 0x10 / 0x1c / 0x20 are used.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* a, void* b);
    virtual void v20(void* a, int b, void* c, int d);
};

// The object at [owner + 0x64] - its member at 0xcf70f0 pops its own arguments.
struct Coll
{
    void __thiscall add(void* p, int n);
};

// The four-word record that is handed to v1c by address.
struct Slot
{
    void* a;
    int b;
    int c;
    void* d;
};

// The thread local block the accessor at 0xc85750 returns.
struct TlsBlk
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    VObj* f4;
};

// The second argument.
struct Evt
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
};

// The first argument.
struct Owner
{
    int unk00;
    int unk04;
    VObj* unk08;
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
    VObj* unk58;
    int unk5c;
    int unk60;
    Coll* unk64;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
};

// The thread local accessor at 0xc85750.
void* __cdecl tlsSlot_cb5c10();

// @fnv 0x00cb5c10
void __cdecl FUN_00cb5c10(Owner* pOwner, Evt* pEvent)
{
    // q is the flag word at +0x10; the original keeps that pointer in a
    // register, so &pEvt->unk24 is reached as q + 5.
    int* q = &pEvent->unk10;
    if (*q == 0)
        return;

    Slot s;
    // The address of the record escapes here: that is what keeps the dead
    // store of zero below and the shared zero register alive.
    Slot* pSlot = &s;

    pOwner->unk08->v20(&pEvent, 1, pOwner, 1);

    unsigned int count = pOwner->unk338;

    s.a = 0;
    s.b = 0;
    s.c = 0x80000000;

    TlsBlk* t = (TlsBlk*)tlsSlot_cb5c10();
    void* base = t->f0;
    t->f0 = (char*)base + ((count * 8 + 0x7f) & 0xffffff80u);
    s.a = base;
    s.d = base;

    s.c = count | 0x80000000u;

    pOwner->unk58->v1c(q + 5, pSlot);

    int n = s.b;
    if (n > 0)
        pOwner->unk64->add(s.a, n);

    void* d = s.d;
    if (d == s.a)
        s.b = 0;

    t = (TlsBlk*)tlsSlot_cb5c10();
    t->f0 = d;
    t = (TlsBlk*)tlsSlot_cb5c10();
    // The flag is read through a volatile lvalue so that the load keeps its
    // place in front of the receiver load, exactly as the original does.
    int c = *(volatile int*)&s.c;
    VObj* o = t->f4;
    s.b = 0;
    if (!(c & 0x80000000))
        o->v10(s.a, (c & 0x3fffffff) * 8);
}

namespace fnv_00cb5f50 {
struct S_00cb5f50_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00cb5f50_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb5f50_Allocator* m_pStreamAllocator;
    S_00cb5f50_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5f50_Router* FUN_00c85750() throw();

template <typename T> struct S_00cb5f50_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~S_00cb5f50_Array() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
    void _clearAndDeallocate(S_00cb5f50_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

template <typename T, int N> struct S_00cb5f50_InplaceArray : S_00cb5f50_Array<T>
{
    T m_kStorage[N];
    S_00cb5f50_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00cb5f50_Island;
struct S_00cb5f50_World;

struct S_00cb5f50_Entity
{
    int unk00;
    int unk04;
    S_00cb5f50_World* m_pOwningWorld;
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
    S_00cb5f50_Island* m_pSimulationIsland;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_bFlag;
};

struct S_00cb5f50_Constraint
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void getConnectedEntities(S_00cb5f50_Array<S_00cb5f50_Entity*>& entitiesOut) throw();
    void FUN_00c905b0() throw();
};

struct S_00cb5f50_Island
{
    void AddItem(S_00cb5f50_Constraint* c) throw();
};

struct S_00cb5f50_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00cb5f50_Island* m_pFixedIsland;
};

void FUN_00cb5570(S_00cb5f50_World* world, S_00cb5f50_Entity* a, S_00cb5f50_Entity* b) throw();

// @fnv 0x00cb5f50
void __cdecl ApplyConstraintsToEntity(S_00cb5f50_World* world, S_00cb5f50_Entity* entity,
                                      const S_00cb5f50_Array<S_00cb5f50_Constraint*>* constraints) throw()
{
    S_00cb5f50_Island* island = entity->m_pSimulationIsland;
    S_00cb5f50_InplaceArray<S_00cb5f50_Entity*, 16> entities;
    for (int i = 0; i < constraints->m_iElementCount; i++)
    {
        S_00cb5f50_Constraint* c = constraints->m_data[i];
        if (island != world->m_pFixedIsland)
        {
            island->AddItem(c);
            c->FUN_00c905b0();
            entities.clear();
            c->getConnectedEntities(entities);
            for (int j = 0; j < entities.m_iElementCount; j++)
            {
                S_00cb5f50_Entity* other = entities[j];
                if (other != entity && other->m_bFlag != 5 && entity->m_bFlag != 5 &&
                    other->m_pSimulationIsland != entity->m_pSimulationIsland)
                    FUN_00cb5570(other->m_pOwningWorld, other, entity);
            }
        }
        else
        {
            world->m_pFixedIsland->AddItem(c);
            c->FUN_00c905b0();
        }
    }
}
}  // namespace fnv_00cb5f50

struct FUN_00cb7480_node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
};

struct FUN_00cb7480_holder
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
    FUN_00cb7480_node* m_30;
};

struct FUN_00cb7480_delta
{
    int unk00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00cb7480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;

    void FUN_00cb7480(FUN_00cb7480_holder* a1, FUN_00cb7480_delta* a2);
};

// Subtracts the delta's m_04, m_08 and m_0c from m_0c, m_10 and m_14, and from the node's m_14, m_16 and m_18, when a1->m_30 is non-null.
// @fnv 0x00cb7480
void FUN_00cb7480_cls::FUN_00cb7480(FUN_00cb7480_holder* apHolder, FUN_00cb7480_delta* apDelta)
{
    if (apHolder->m_30 != 0)
    {
        m_0c -= apDelta->m_04;
        m_10 -= apDelta->m_08;
        m_14 -= apDelta->m_0c;
        FUN_00cb7480_node* n = apHolder->m_30;
        int dy = n->m_18 - apDelta->m_0c;
        int dx = n->m_14 - apDelta->m_04;
        n->m_16 -= (unsigned short)apDelta->m_08;
        n->m_14 = (unsigned short)dx;
        n->m_18 = (unsigned short)dy;
    }
}

namespace fnv_00d282c0 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <class T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        T* p = (T*)AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return p;
    }
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& stack()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

template <class T> struct hkLocalArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkLocalArr(int n)
    {
        hkMemoryAllocator& alloc = audio()->stack();
        m_data = n ? alloc._bufAlloc<T>(n) : 0;
        m_iElementCount = 0;
        m_iCapacityState = n ? n : 0x80000000;
    }
    __forceinline ~hkLocalArr()
    {
        hkMemoryAllocator& alloc = audio()->stack();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};

struct hkArr
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(int));
        }
        m_iElementCount = n;
    }
};

__forceinline int* localAlloc(hkMemoryAllocator& alloc, int n, int& m_iCapacity)
{
    int* p = n ? alloc._bufAlloc<int>(n) : 0;
    m_iCapacity = n ? n : 0x80000000;
    return p;
}

struct IndexRemap
{
    int** m_ppIndices;
    int m_iIndexCount;

    void RemapAndAccumulate(const hkArr& map, int n, hkArr& values);
};

// Remaps each entry of the index array through map, then sums values into n buckets by mapped index and writes the sums back into values.
// @fnv 0x00d282c0
void IndexRemap::RemapAndAccumulate(const hkArr& map, int n, hkArr& values)
{
    for (int i = 0; i < m_iIndexCount; i++)
        (*m_ppIndices)[i] = map.m_data[(*m_ppIndices)[i]];

    hkMemoryAllocator& stackAlloc = audio()->stack();
    int m_iCapacity;
    int* sums = localAlloc(stackAlloc, n, m_iCapacity);
    for (int i = 0; i < n; i++)
        sums[i] = 0;
    for (int i = 0; i < values.m_iElementCount; i++)
        sums[map.m_data[i]] += values.m_data[i];

    values.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
        values.m_data[i] = sums[i];

    hkMemoryAllocator& alloc = audio()->stack();
    if ((m_iCapacity & 0x80000000) == 0)
        alloc.ReturnMemory(sums, (m_iCapacity & 0x3fffffff) * sizeof(int));
}
}  // namespace fnv_00d282c0

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S00cb5310_Sub;
struct S00cb5310_Node;
struct S00cb5310_Piece;
struct S00cb5310_Owner;
struct S00cb5310_Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40(void* p);
    virtual void v44(void* p);
};
struct S00cb5310_List
{
    S00cb5310_Node** m_00;
    int m_04;
    unsigned int m_08;
};
struct S00cb5310_Alloc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct S00cb5310_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char m_26;
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float m_44;
    S00cb5310_Piece** m_48;
    int m_4c;
};
struct S00cb5310_Piece
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
    S00cb5310_Sub m_e0;
    int unkE4;
    int unkE8;
    int unkEC;
    int m_f0;
    int unkF4;
    int unkF8;
    int unkFC;
};
struct S00cb5310_Owner
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
    S00cb5310_Node** m_28;
    int m_2c;
    int unk30;
    S00cb5310_List m_34;
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
    float m_1d0;
};
extern int DAT_01267e30;
void ResizeAudioStream(void* alloc, S00cb5310_List* list, int n);
bool FUN_00d28560(float* p, S00cb5310_Piece** arr, int n, int size);
void UpdateRotationInterpolation(float f, void* p);
void FUN_00d011b0(S00cb5310_Owner* a1, S00cb5310_Node* a2);
// If FUN_00d28560 passes, moves node a2 from the owner's m_28 array to its m_34 list, updates its pieces and calls FUN_00d011b0; else sets a flag bit and returns.
// @fnv 0x00cb5310
void __cdecl FUN_00cb5310(S00cb5310_Owner* apOwner, S00cb5310_Node* apNode)
{
    S00cb5310_Piece** pForm;
    pForm = apNode->m_48;
    long holder;
    holder = apNode->m_4c;
    float* pf = &apOwner->m_1d0;
    if (FUN_00d28560(pf, pForm, holder, 0xe0) == 0)
    {
        apNode->m_26 = (unsigned char)((apNode->m_26 & 0xf7) | 4);
        return;
    }
    S00cb5310_List* list;
    list = &apOwner->m_34;
    S00cb5310_Alloc* p = reinterpret_cast<S00cb5310_Alloc*>(FUN_00c85750());
    if (list->m_04 == (int)(list->m_08 & 0x3fffffffu))
    {
        ResizeAudioStream(p->m_pAllocator, list, 4);
    }
    S00cb5310_Node** slot;
    slot = list->m_00 + list->m_04;
    __assume((bool)slot);
    new (slot) S00cb5310_Node*(apNode);
    list->m_04 += 1;
    apOwner->m_28[apNode->m_20] = apOwner->m_28[apOwner->m_2c - 1];
    apOwner->m_28[apNode->m_20]->m_20 = apNode->m_20;
    S00cb5310_List* _lst = &apOwner->m_34;
    apOwner->m_2c--;
    apNode->m_20 = (unsigned short)(_lst->m_04 - 1);
    apNode->m_26 &= 0xfc;
    int i;
    apNode->m_44 = *pf;
    i = 0;
    if (apNode->m_4c > i)
    {
        do
        {
            S00cb5310_Piece* pPiece = apNode->m_48[i];
            UpdateRotationInterpolation(apNode->m_44, &pPiece->m_f0);
            pPiece->m_e0.v40(&DAT_01267e30);
            pPiece->m_e0.v44(&DAT_01267e30);
            ++i;
        } while (i < apNode->m_4c);
    }
    FUN_00d011b0(apOwner, apNode);
}

namespace fnv_00cb5500 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Entry
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned short unk20;
    unsigned short index;
    unsigned short unk24;
    unsigned char flags;
};
struct EntryArray
{
    Entry** entries;
    unsigned int count;
    unsigned int capacity;
};
struct AllocatorContext
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int allocator;
};
extern AllocatorContext* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(unsigned int allocator, EntryArray* list, int entrySize);

// Sets entry flags, and if entry->index is 0xffff, appends entry to the EntryArray at owner+0x40, resizing it via ResizeAudioStream when full.
// @fnv 0x00cb5500
void __cdecl AddEntryToList(void* owner, Entry* entry)
{
    unsigned char bits = entry->flags;
    if ((bits & 0x0c) == 0 && (bits & 3) != 0)
    {
        entry->flags = (bits & ~0x20) | 0x10;
    }
    entry->flags = (entry->flags & ~0x08) | 0x04;
    if (entry->index == 0xffff)
    {
        entry->index = (unsigned short)*(unsigned int*)((unsigned char*)owner + 0x44);
        EntryArray* list = (EntryArray*)((unsigned char*)owner + 0x40);
        AllocatorContext* allocator = FUN_00c85750();
        if (list->count == (list->capacity & 0x3fffffff))
        {
            ResizeAudioStream(allocator->allocator, list, 4);
        }
        Entry** slot = list->entries + list->count;
        __assume(slot != 0);
        new (slot) Entry*(entry);
        ++list->count;
    }
}
}  // namespace fnv_00cb5500

struct Cb5750_Deferred
{
    unsigned char tag;
    struct Cb5750_Param* arg;
};

struct Cb5750_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};

struct Cb5750_Nav
{
    int unk00;
    int unk04;
    int unk08;
    Cb5750_Bv m_bv;
};

struct Cb5750_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    Cb5750_Nav m_nav;
};

struct Cb5750_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Cb5750_Inner inner;
};

struct Cb5750_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct Cb5750_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};

S_00c6aca0_Router* Cb5750_router() throw();

struct Cb5750_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};

template <class T> struct Cb5750_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Cb5750_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~Cb5750_Array() throw()
    {
        S_00c6aca0_Router* router = Cb5750_router();
        S_00c6aca0_Heap& heap = *router->m10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            heap.vfn_10(m_data, (cap & 0x3fffffff) * (int)sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <class T> struct Cb5750_LocalArray : Cb5750_Array<T>
{
    T* m_pStackAllocation;
    __forceinline Cb5750_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)((Cb5750_Stack*)Cb5750_router())->allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~Cb5750_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        ((Cb5750_Stack*)Cb5750_router())->deallocateStack(mem);
    }
};

struct Cb5750_Source
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual void v2c(Cb5750_Nav** key, Cb5750_Aabb* aabb, int count, Cb5750_Array<S_00cb5d00_Elem>* a,
                     Cb5750_Array<S_00cb5d00_Elem>* b) throw();
};

struct Cb5750_Sink
{
    void addSecond(S_00cb5d00_Elem* data, int n) throw();
    void addFirst(S_00cb5d00_Elem* data, int n, void* extra) throw();
};

S_00c6aca0_Router* Cb5750_router() throw();
void __cdecl Cb5750_merge(Cb5750_Array<S_00cb5d00_Elem>* a, Cb5750_Array<S_00cb5d00_Elem>* b) throw();
void __cdecl Cb5750_invalid(void* world, Cb5750_Param** pp, int count) throw();

struct Cb5750_Owner
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
    Cb5750_Source* unk58;
    int unk5C;
    int unk60;
    Cb5750_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;
    Cb5750_Sub8* unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
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

    void defer(Cb5750_Deferred* d) throw();
    void flush8c() throw();
    void flush90() throw();
    void __cdecl AddCollisionShape(Cb5750_Param* param) throw();
};

// If unk94 is set, defers the call; otherwise expands the shape's bounding volume into an AABB, queries unk58 with it, and passes results to unk64.
// @fnv 0x00cb5750
void __cdecl Cb5750_Owner::AddCollisionShape(Cb5750_Param* param) throw()
{
    if (unk94 != 0)
    {
        Cb5750_Deferred deferred;
        deferred.tag = 3;
        deferred.arg = param;
        defer(&deferred);
        return;
    }

    Cb5750_Param* held = param;
    void* shape = held->inner.m_pCollisionShape;
    unk94 = 1;
    if (shape != 0)
    {
        Cb5750_Inner* inner = &held->inner;
        Cb5750_LocalArray<S_00cb5d00_Elem> arr1(unk338);
        Cb5750_LocalArray<S_00cb5d00_Elem> arr2(unk338);
        if (inner->m_nav.m_bv.m_kMinimumCorner[0] > inner->m_nav.m_bv.m_kMaximumCorner[0])
            Cb5750_invalid(unk78, &param, 1);

        __declspec(align(16)) Cb5750_Aabb aabb;
        unsigned int uiExpansionShift = inner->m_nav.m_bv.m_ucExpansionShift;
        aabb.m_kMinimumCorner[0] =
            inner->m_nav.m_bv.m_kMinimumCorner[0] - (inner->m_nav.m_bv.m_ucExpansionMin[0] << uiExpansionShift);
        aabb.m_kMinimumCorner[1] =
            inner->m_nav.m_bv.m_kMinimumCorner[1] - (inner->m_nav.m_bv.m_ucExpansionMin[1] << uiExpansionShift);
        aabb.m_kMinimumCorner[2] =
            inner->m_nav.m_bv.m_kMinimumCorner[2] - (inner->m_nav.m_bv.m_ucExpansionMin[2] << uiExpansionShift);
        aabb.m_kMaximumCorner[0] =
            inner->m_nav.m_bv.m_kMaximumCorner[0] + (inner->m_nav.m_bv.m_ucExpansionMax[0] << uiExpansionShift);
        aabb.m_kMaximumCorner[1] =
            inner->m_nav.m_bv.m_kMaximumCorner[1] + (inner->m_nav.m_bv.m_ucExpansionMax[1] << uiExpansionShift);
        aabb.m_kMaximumCorner[2] =
            inner->m_nav.m_bv.m_kMaximumCorner[2] + (inner->m_nav.m_bv.m_ucExpansionMax[2] << uiExpansionShift);
        Cb5750_Nav* key = &inner->m_nav;

        unk58->v2c(&key, &aabb, 1, &arr1, &arr2);
        if (arr1.m_iElementCount + arr2.m_iElementCount > 0)
        {
            Cb5750_merge(&arr1, &arr2);
            unk64->addSecond(arr2.m_data, arr2.m_iElementCount);
            Cb5750_Sub8* sub = unk7C;
            void* extra = sub ? &sub->unk08 : 0;
            unk64->addFirst(arr1.m_data, arr1.m_iElementCount, extra);
        }
    }

    if (--unk94 == 0 && flag9c == 0)
    {
        if (unk8C != 0)
            flush8c();
        if (unkA4 == 1 && unk90 != 0)
            flush90();
    }
}

namespace fnv_00cb5dd0 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Producer;
struct Actor;
struct Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void freeMemory(void* pointer, unsigned int bytes);
};
struct MemoryContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Heap* heap;
};
extern "C" MemoryContext* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void* heap, void* array, int elementSize);

template <class T> struct Array
{
    T** data;
    int length;
    unsigned int capacity;
    void add(T* p)
    {
        MemoryContext* memory = FUN_00c85750();
        if (length == (int)(capacity & 0x3fffffff))
            ResizeAudioStream(memory->heap, this, 4);
        T** address = data + length;
        __assume(address != 0);
        new (address) T*(p);
        ++length;
    }
};
struct Scratch : Array<Actor>
{
    Actor* inline0;
    Actor* inline1;
    Actor* inline2;
    Actor* inline3;
    Actor* inline4;
    Actor* inline5;
    Actor* inline6;
    Actor* inline7;
    Actor* inline8;
    Actor* inline9;
    Actor* inline10;
    Actor* inline11;
    Actor* inline12;
    Actor* inline13;
    Actor* inline14;
    Actor* inline15;
    Scratch()
    {
        data = &inline0;
        length = 0;
        capacity = 0x80000010;
    }
};
struct Producer
{
    virtual void zero();
    virtual void one();
    virtual void two();
    virtual void three();
    virtual void enumerate(Scratch* result);
    void __thiscall FUN_00c90510();
};
struct Handle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short index22;
    unsigned char unk24;
    unsigned char flags25;
    void __thiscall RemoveEntry(Producer* object);
};
struct Actor
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
    unsigned char kindE8;
};
struct Manager
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
    Handle* currentCC;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    Producer** producers208;
    unsigned short producerCount20c;
};
struct Context
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
    Array<Handle> handles40;
};
// Enumerates each producer's actors, adds qualifying producers to output, removes them from currentCC, and frees the scratch buffer.
// @fnv 0x00cb5dd0
void __cdecl CollectProducers(Context* context, Manager* manager, Array<Producer>* output)
{
    Scratch scratch;
    int index = 0;
    Handle* handle = manager->currentCC;
    for (; index < manager->producerCount20c; ++index)
    {
        Producer* object = manager->producers208[index];
        object->enumerate(&scratch);
        int j = 0;
        if (scratch.length > 0)
        {
            do
            {
                Actor* other = scratch.data[j];
                if (other->kindE8 != 5 && other != reinterpret_cast<Actor*>(manager))
                    goto next_object;
                ++j;
            } while (j < scratch.length);
        }
        output->add(object);
        object->FUN_00c90510();
        handle->RemoveEntry(object);
        handle->flags25 = (handle->flags25 & 0xdf) | 0x10;
        if (handle->index22 == 0xffff)
        {
            handle->index22 = (unsigned short)context->handles40.length;
            context->handles40.add(handle);
        }
    next_object:;
    }
    MemoryContext* memory = FUN_00c85750();
    Heap* heap = memory->heap;
    unsigned int cap = scratch.capacity;
    scratch.length = 0;
    if ((cap & 0x80000000u) == 0)
        heap->freeMemory(scratch.data, (cap & 0x3fffffff) * 4);
}
}  // namespace fnv_00cb5dd0

struct Item_cb3d10
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
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
};
struct Owner_cb3d10
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
    unsigned char unkC8;
};
struct List_cb3d10
{
    Item_cb3d10** m_data;
    int m_iElementCount;
};
// Scans the last 20 list items backwards for a non-target item with unk26 & 0xc and max(unk4c, unk1c) + threshold < owner->unkB4; sets a unk25 bit and returns it.
// @fnv 0x00cb3d10
static __declspec(noinline) Item_cb3d10* FindItemForThreshold(Owner_cb3d10* owner, List_cb3d10* list, int threshold,
                                                              Item_cb3d10* target)
{
    int limit = owner->unkB4;
    if (threshold >= limit)
        return 0;
    if (!owner->unkC8)
        return 0;
    int i = list->m_iElementCount;
    int lo = (i - 20 < 0) ? 0 : i - 20;
    for (--i; i >= lo; --i)
    {
        Item_cb3d10* item = list->m_data[i];
        if (target != item)
        {
            int v = item->unk4c;
            if (v <= item->unk1c)
                v = item->unk1c;
            if (item->unk26 & 0xc)
            {
                if (v + threshold < limit)
                {
                    item->unk25 = (item->unk25 & 0xf7) | 4;
                    return item;
                }
            }
        }
    }
    return 0;
}
volatile int g_cb3d10_thr;
Owner_cb3d10* volatile g_cb3d10_owner;
List_cb3d10* volatile g_cb3d10_list;
Item_cb3d10* volatile g_cb3d10_target;
Item_cb3d10* volatile g_cb3d10_out;
void CallTarget_cb3d10()
{
    g_cb3d10_out = FindItemForThreshold(g_cb3d10_owner, g_cb3d10_list, g_cb3d10_thr, g_cb3d10_target);
}

struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_List
{
    B10293_Item** m_data;
    int m_uiItemCount;
};
struct B10293_Ctx
{
    unsigned char Sel(int off) const
    {
        return *((const unsigned char*)this + off);
    }
};
struct B10293_Arr
{
    int* m_aiIndexedValues;
};
struct B10293_Chain
{
    B10293_Arr* m_aiIndexedValues;
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}
// Zeroes out the output array, then for each list item computes a threshold from two packed fields and sets the indexed slot to 1 when the threshold is 5 or less.
// @fnv 0x00cb4080
static void MarkIndexedValues(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx)
{
    int i;
    for (i = 0; i < count; i++)
        (*out)[i] = 0;
    int j;
    for (j = 0; j < list->m_uiItemCount; j++)
    {
        B10293_Item* item = list->m_data[j];
        int a = Dec(item->Field(0xec), ctx->Sel(0x306));
        int c = Dec(item->Field(0xea), ctx->Sel(0x305));
        a &= 0x7f;
        c &= 0x7f;
        if (c > a)
            a = c;
        if (a <= 5)
            (*out)[chain->m_aiIndexedValues->m_aiIndexedValues[j]] = 1;
    }
}
int keep_alive_b10293(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx)
{
    MarkIndexedValues(count, list, out, chain, ctx);
    return count;
}

struct Shape
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
    unsigned short m_numShapeKeys;  // +0xb0
};

struct ShapeList
{
    Shape** m_items;
    int m_uiItemCount;
};

// For each shape in list, set flags[idx] to 1 and add its m_numShapeKeys (minimum 1) to counts[idx].
// @fnv 0x00cb41e0
static void FUN_00cb41e0(int*** indexMap, int** counts, ShapeList* list, int** flags)
{
    int**** pp = &indexMap;
    for (int i = 0; i < list->m_uiItemCount; i++)
    {
        Shape* s = list->m_items[i];
        int idx = (***pp)[i];
        (*flags)[idx] = 1;
        int n = s->m_numShapeKeys;
        (*counts)[idx] += n < 1 ? 1 : n;
    }
}
int keep_alive_b11420(ShapeList* list, int** flags, int*** indexMap, int** counts)
{
    FUN_00cb41e0(indexMap, counts, list, flags);
    return 0;
}

namespace fnv_00cb4790 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}

struct Entry;
struct Cell
{
    void* value;
    Cell()
    {}
};
struct Array
{
    Cell* data;
    int size;
    unsigned capacity;
};
struct Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* allocator;
};
Heap* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, Array*, int);
struct Actor
{
    unsigned short& id()
    {
        return *(unsigned short*)((char*)this + 0x22);
    }
    unsigned char& flags()
    {
        return *(unsigned char*)((char*)this + 0x25);
    }
    void __thiscall RemoveEntry(Entry*);
};
struct Entry
{
    int unk00;
    int unk04;
    int unk08;
    Actor* actor;
    void __thiscall FUN_00c90510();
};
// Adds each element entry whose actor is parent[8] to output and removes it from that actor, then lists the actor in parent[16] if its id is 0xffff.
// @fnv 0x00cb4790
void __cdecl CollectActorEntries(int* parent, int* elements, Array* output)
{
    for (int i = 0; i < *(unsigned short*)&elements[0x83]; i++)
    {
        Entry* item = ((Entry**)elements[0x82])[i];
        if (item->actor == (Actor*)parent[8])
        {
            Heap* heap = FUN_00c85750();
            if (output->size == (int)(output->capacity & 0x3fffffff))
                ResizeAudioStream(heap->allocator, output, 4);
            Cell* dst = &output->data[output->size];
            new (dst) Cell();
            dst->value = item;
            output->size++;
            item->FUN_00c90510();
            ((Actor*)parent[8])->RemoveEntry(item);
            ((Actor*)parent[8])->flags() = (((Actor*)parent[8])->flags() & 0xdf) | 0x10;
            Actor* actor = (Actor*)parent[8];
            if (actor->id() == 0xffff)
            {
                actor->id() = (unsigned short)((Array*)&parent[16])->size;
                Array* other = (Array*)&parent[16];
                Heap* heap2 = FUN_00c85750();
                if (other->size == (int)(other->capacity & 0x3fffffff))
                    ResizeAudioStream(heap2->allocator, other, 4);
                Cell* dst2 = &other->data[other->size];
                new (dst2) Cell();
                dst2->value = actor;
                other->size++;
            }
        }
    }
}
}  // namespace fnv_00cb4790

template <class T> inline void S00cb4c60_copy(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
struct hkpWorld;
struct hkpSimulationIsland;
struct hkpEntity;
struct hkpAction;
struct hkBool
{
    char value;
    hkBool(bool b) : value(b)
    {}
    hkBool(const hkBool& other) : value(other.value)
    {}
};
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> struct hkArrayNative
{
    T* data;
    int count;
    unsigned int capRaw;
    int getCapacity() const
    {
        return capRaw & 0x3fffffff;
    }
    void reserve(int n)
    {
        S_00c6aca0_Heap& a = FUN_00c85750()->heap();
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
    void AddBack(const T& t)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (count == getCapacity())
            ResizeAudioStream(&r->heap(), this, sizeof(T));
        S00cb4c60_copy(data + count, 1, t);
        count++;
    }
    void SetSize(int size)
    {
        reserve(size);
        count = size;
    }
};
struct hkpConstraintInstance
{
    int unk00, unk04;
    hkpSimulationIsland* owner;
};
struct ConstraintRuntimeInfo
{
    hkpConstraintInstance* constraint;
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
};
struct hkpAction
{
    int unk00, unk04, unk08;
    hkpSimulationIsland* owner;
};
struct hkpEntity
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short storageIndex, unkAA;
    ConstraintRuntimeInfo* constraintMasters;
    unsigned short constraintMasterCount, unkB2;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    hkpSimulationIsland* owner;
};
struct hkpSimulationIsland
{
    virtual ~hkpSimulationIsland();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short storageIndex, dirtyIndex;
    unsigned char unk24, flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char f26lo : 2;
            unsigned char f26mid : 2;
        } f26;
    };
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayNative<hkpAction*> actions;
    int unk44;
    hkArrayNative<hkpEntity*> entities;
    int unk54;
    int unk58;
    void FUN_00d07120();
    void MergeFrom(hkpSimulationIsland*);
};
struct hkpWorld
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpSimulationIsland* fixedIsland;
    int unk24;
    hkArrayNative<hkpSimulationIsland*> active;
    hkArrayNative<hkpSimulationIsland*> inactive;
    hkArrayNative<hkpSimulationIsland*> dirty;
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
    int refCount94;
    int unk98;
    unsigned char flag9c, unk9d, unk9e, unk9f;
    int unka0;
    int unka4;
    void FUN_00c910a0(hkpSimulationIsland*);
    void FUN_00c91120();
    void FUN_00c91140();
};
void __cdecl FUN_00cb5100(hkpWorld*, hkpSimulationIsland*, hkBool);
void __cdecl FUN_00cff290(void*, void*);
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl ClearSlotReference(hkpWorld*, hkpSimulationIsland*);
static inline int GrowCap(int cap, int need)
{
    int nc = cap * 2;
    if (need >= nc)
        nc = need;
    return nc;
}
// Merges island Q into P, reassigns entity and action owners, updates world lists, and deletes Q.
// @fnv 0x00cb4c60
void __cdecl FUN_00cb4c60(hkpWorld* apWorld, hkpSimulationIsland* apTarget, hkpSimulationIsland* apSource)
{
    hkpWorld* o = apWorld;
    if (apTarget->entities.count > apSource->entities.count)
    {
    }
    else if (apTarget->entities.count < apSource->entities.count || apTarget->storageIndex > apSource->storageIndex)
    {
        hkpSimulationIsland* t = apTarget;
        apTarget = apSource;
        apSource = t;
    }
    o->refCount94++;
    unsigned char pf = apTarget->flags26;
    unsigned char cl = pf & 3;
    unsigned char dl;
    if (cl == 0 && (apSource->flags26 & 3) == 0)
        dl = 0;
    else
        dl = 1;
    unsigned char f18;
    if ((pf & 0xc) != 0 || (apSource->flags26 & 0xc) != 0)
        f18 = 1;
    else
        f18 = 0;
    if (dl)
    {
        if (cl == 0)
        {
            apTarget->flags26 = (pf & 0xf7) | 4;
            FUN_00cb5100(apWorld, apTarget, hkBool(false));
        }
        else if ((apSource->flags26 & 3) == 0)
        {
            apSource->flags26 = (apSource->flags26 & 0xf7) | 4;
            FUN_00cb5100(apWorld, apSource, hkBool(false));
        }
    }
    apTarget->flags25 |= (apSource->flags25 & 0xc);
    apTarget->FUN_00d07120();
    apSource->FUN_00d07120();
    o->fixedIsland->FUN_00d07120();
    FUN_00cff290(&apTarget->unk58, &apSource->unk58);
    int iTargetCount = apTarget->entities.count;
    unsigned short idx = (unsigned short)iTargetCount;
    int total = iTargetCount + apSource->entities.count;
    hkArrayNative<hkpEntity*>* v48 = &apTarget->entities;
    v48->SetSize(total);
    hkArrayNative<hkpEntity*>* pSourceEntities = &apSource->entities;
    for (int i = 0; i < pSourceEntities->count; ++i, ++idx)
    {
        v48->data[idx] = pSourceEntities->data[i];
        pSourceEntities->data[i]->owner = apTarget;
        pSourceEntities->data[i]->storageIndex = (unsigned short)idx;
    }
    int k = apTarget->actions.count;
    int iTotalActions = k + apSource->actions.count;
    hkArrayNative<hkpAction*>* v38 = &apTarget->actions;
    v38->SetSize(iTotalActions);
    hkArrayNative<hkpAction*>* pSourceActions = &apSource->actions;
    for (int i = 0; i < pSourceActions->count; ++i)
    {
        if (pSourceActions->data[i] != 0)
        {
            v38->data[k] = pSourceActions->data[i];
            v38->data[k]->owner = apTarget;
            ++k;
        }
    }
    v38->SetSize(k);
    for (int i = 0; i < pSourceEntities->count; ++i)
    {
        hkpEntity* e = pSourceEntities->data[i];
        ConstraintRuntimeInfo* rec = e->constraintMasters;
        for (int cnt = e->constraintMasterCount - 1; cnt >= 0; --cnt)
        {
            rec->constraint->owner = apTarget;
            ++rec;
        }
    }
    apTarget->MergeFrom(apSource);
    apTarget->unk1C += apSource->unk1C;
    apSource->unk1C = 0;
    unsigned short uSourceIndex = apSource->storageIndex;
    hkArrayNative<hkpSimulationIsland*>* c = ((apSource->flags26 & 3) != 0) ? &o->active : &o->inactive;
    int iListCount = c->count;
    if ((int)uSourceIndex < iListCount - 1)
    {
        c->data[uSourceIndex] = c->data[iListCount - 1];
        c->data[uSourceIndex]->storageIndex = uSourceIndex;
    }
    c->count--;
    unsigned char al = ((apTarget->flags25 & 3) != 0 || (apSource->flags25 & 3) != 0) ? 1 : 0;
    unsigned char x25 = apTarget->flags25;
    x25 ^= al;
    x25 &= 3;
    apTarget->flags25 ^= x25;
    unsigned char cl2 = apTarget->flags25;
    unsigned char al2 = ((cl2 & 0x30) != 0 || (apSource->flags25 & 0x30) != 0) ? 1 : 0;
    unsigned char uNewFlags = (unsigned char)(al2 << 4);
    uNewFlags ^= cl2;
    uNewFlags &= 0x30;
    uNewFlags ^= cl2;
    apTarget->flags25 = uNewFlags;
    apTarget->f26.f26mid = f18 != 0;
    if (apSource->dirtyIndex != 0xffff && apTarget->dirtyIndex == 0xffff)
    {
        apTarget->dirtyIndex = (unsigned short)o->dirty.count;
        hkArrayNative<hkpSimulationIsland*>* pDirtyList = &o->dirty;
        pDirtyList->AddBack(apTarget);
    }
    ClearSlotReference(apWorld, apSource);
    delete apSource;
    int w;
    if ((apTarget->flags26 & 3) != 0 && (w = apTarget->storageIndex) != 0)
    {
        hkArrayNative<hkpSimulationIsland*>* pActiveList = &o->active;
        hkpSimulationIsland* pFirstIsland = pActiveList->data[0];
        if (apTarget->entities.count > pFirstIsland->entities.count)
        {
            apTarget->storageIndex = 0;
            pFirstIsland->storageIndex = w;
            pActiveList->data[0] = apTarget;
            pActiveList->data[w] = pFirstIsland;
        }
    }
    apWorld->FUN_00c910a0(apTarget);
    if (--o->refCount94 == 0 && o->flag9c == 0)
    {
        if (o->unk8c != 0)
            o->FUN_00c91120();
        if (o->unka4 == 1 && o->unk90 != 0)
        {
            o->FUN_00c91140();
            return;
        }
    }
}

struct IslandList
{
    struct IslandNode** items;
    int count;
    int capacity;
};
struct IslandNode
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
    unsigned char index;
    unsigned char flags;
    union
    {
        unsigned char state;
        struct
        {
            unsigned char lowState : 2;
            unsigned char highState : 2;
            unsigned char otherState : 4;
        };
    };
    unsigned char unk27;
    IslandList first;
    IslandList second;
};
void __cdecl FUN_00cb6060(IslandNode* data, Object* object, IslandList* list, int value);
void __cdecl AddItemToContainer(Object* object, IslandNode* item);
// Picks a list by the node's low state, runs FUN_00cb6060, then for each new item copies that state, sets its index, and may call AddItemToContainer.
// @fnv 0x00cb6e70
void __cdecl PropagateStateToChildren(Object* object, int* apNode)
{
    IslandNode* node = (IslandNode*)apNode;
    unsigned char uiLowState = node->state & 3;
    IslandList* list;
    if (uiLowState != 0)
        list = &((IslandNode*)object)->first;
    else
        list = &((IslandNode*)object)->second;
    node->flags &= 0xfc;
    int initialIndex = list->count;
    FUN_00cb6060(node, object, list, 0);
    unsigned char uiHighState = (node->state >> 2) & 3;
    int currentIndex = initialIndex;
    while (currentIndex < list->count)
    {
        IslandNode* item = list->items[currentIndex];
        item->highState = uiLowState;
        item->lowState = uiLowState;
        if (uiLowState != 0 && uiHighState == 0)
            AddItemToContainer(object, item);
        item->index = (unsigned char)(node->index - initialIndex + currentIndex);
        ++currentIndex;
    }
}

#include <windows.h>
namespace fnv_00cb5480 {
// Lock-guarded append of a pointer item into the list at this+0x40.
// Clears flag bits on the item, and if its word slot is 0xffff, stamps the
// current count into it and appends the item (growing via the allocator).

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

extern "C" AllocHolder* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int iStride);

struct PtrArray
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct LockedList
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
    PtrArray m_40;
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
    CRITICAL_SECTION* m_pCs;
};

struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short m_w22;
    unsigned short unk24;
    unsigned char m_b26;
};

// Clears bits 0xc of pItem's m_b26, then under the lock, if m_w22 is 0xffff, stores the array size in it and appends pItem to m_40.
// @fnv 0x00cb5480
void FUN_00cb5480(LockedList* pList, ListItem* pItem)
{
    pItem->m_b26 &= 0xf3;
    EnterCriticalSection(pList->m_pCs);
    if (pItem->m_w22 == 0xffff)
    {
        pItem->m_w22 = (unsigned short)pList->m_40.m_iArrayLength;
        PtrArray* arr = &pList->m_40;
        AllocHolder* holder = FUN_00c85750();
        if (arr->m_iArrayLength == (int)(arr->m_uCapFlags & 0x3fffffff))
        {
            ResizeAudioStream(holder->m_pAllocator, arr, 4);
        }
        ListItem** slot = (ListItem**)((char*)arr->m_pData + *(volatile int*)&arr->m_iArrayLength * 4);
        *slot = pItem;
        arr->m_iArrayLength++;
    }
    LeaveCriticalSection(pList->m_pCs);
}
}  // namespace fnv_00cb5480

struct Cb4890_Elem
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
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned short unk0e8;
    unsigned short m_ea;
    unsigned short m_ec;
};
struct Cb4890_ElemArray
{
    Cb4890_Elem** m_data;
    int m_iElementCount;
};
struct Cb4890_IntArray
{
    int* m_data;
    int m_iElementCount;
};
struct Cb4890_CharArray
{
    char* m_data;
    int m_iElementCount;
};
struct Cb4890_Stack
{
    char* m_next;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb4890_LocalBuffer
{
    T* m_p;
    int m_iElementCount;
    __forceinline Cb4890_LocalBuffer(int n) throw()
    {
        m_p = (T*)((Cb4890_Stack*)FUN_00c85750())->allocateStack(n * (int)sizeof(T));
    }
    __forceinline ~Cb4890_LocalBuffer() throw()
    {
        ((Cb4890_Stack*)FUN_00c85750())->deallocateStack(m_p);
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_p[i];
    }
};
struct Cb4890_Owner
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
    int unk0d8;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
struct Cb4890_RemapTable
{
    Cb4890_IntArray* m_entries;
    int m_iElementCount;
    void RemapAndAccumulate(Cb4890_LocalBuffer<int>& map, int count, Cb4890_IntArray* src) throw();
};
template <class T> __forceinline T Cb4890_max2(T a, T b)
{
    return a > b ? a : b;
}

__forceinline int RemapOne(Cb4890_LocalBuffer<int>& used, int* mapped, Cb4890_CharArray* out, int i, int count)
{
    if (used[i])
        mapped[i] = 0;
    else
    {
        mapped[i] = count;
        out->m_data[count] = 0;
        count++;
    }
    return count;
}
// Marks entries used by list elements whose decoded m_ea and m_ec are both at most 5, renumbers the rest via RemapOne, then calls RemapAndAccumulate unless k > n.
// @fnv 0x00cb4890
static __declspec(noinline) void RemapElements(const Cb4890_ElemArray& list, Cb4890_RemapTable* remap,
                                               Cb4890_Owner* owner, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    int n = src->m_iElementCount;
    Cb4890_LocalBuffer<int> used(n);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int j = 0; j < list.m_iElementCount; j++)
    {
        const Cb4890_Elem* e = list.m_data[j];
        int a = e->m_ec;
        if (owner->m_306 == (a >> 14))
            a = (a >> 7) & 0x7f;
        else
            a &= 0x7f;
        int b = e->m_ea;
        if (owner->m_305 == (b >> 14))
            b = (b >> 7) & 0x7f;
        else
            b &= 0x7f;
        if (Cb4890_max2(b & 0x7f, a & 0x7f) <= 5)
            used[remap->m_entries->m_data[j]] = 1;
    }
    int* remapOut = used.m_p;
    int k = 1;
    out->m_data[0] = 1;
    for (int i = 0; i < n; i++)
    {
        k = RemapOne(used, remapOut, out, i, k);
    }
    if (k > n)
        out->m_data[0] = 0;
    else
        remap->RemapAndAccumulate(used, k, src);
}

volatile int g_cb4890[5];
void Cb4890_caller()
{
    RemapElements(*(Cb4890_ElemArray*)g_cb4890[0], (Cb4890_RemapTable*)g_cb4890[1], (Cb4890_Owner*)g_cb4890[2],
                  (Cb4890_IntArray*)g_cb4890[3], (Cb4890_CharArray*)g_cb4890[4]);
}

struct S00cb5100_WBits
{
    unsigned short lo : 14;
    unsigned short hi : 2;
};
struct S00cb5100_Bits
{
    unsigned char lo : 2;
    unsigned char hi : 6;
};
struct S00cb5100_Body;
struct S00cb5100_Ent
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
    S00cb5100_Body* owner_cc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char unke8;
    union
    {
        unsigned char be9;
        S00cb5100_Bits bits9;
    };
    union
    {
        unsigned short wea;
        S00cb5100_WBits bea;
    };
    union
    {
        unsigned short wec;
        S00cb5100_WBits bec;
    };
    unsigned short unkee;
    int unkf0;
    void FUN_00c90510();
    void FUN_00c905b0();
    void setFilter(int a0, int a1, int a2)
    {
        if ((unsigned int)(a2 & 3) < (unsigned int)(be9 & 3))
            a0 = (~a0) << 14;
        else
            a0 <<= 14;
        if (a2 < be9)
            a1 = (~a1) << 14;
        else
            a1 <<= 14;
        wea = (unsigned short)((wea & 0x3fff) | a0);
        wec = (unsigned short)((wec & 0x3fff) | a1);
    }
};
struct S00cb5100_Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int f1c;
    unsigned short idx20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char flags26;
    unsigned char unk27;
    int unk28;
    int unk2c;
    float f30;
    float f34;
    int unk38;
    int unk3c;
    int unk40;
    float f44;
    S00cb5100_Ent** list48;
    int count4c;
};
void ResizeAudioStream(void* heap, void* arr, int elemSize);
struct S00cb5100_Arr
{
    S00cb5100_Body** m_data;
    int m_iElementCount;
    int m_cap;
    S00cb5100_Body* pick(int* n, S00cb5100_Body** b, int k);
    void AddBack(S00cb5100_Body* const& e)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->m10, this, 4);
        S00cb5100_Body** out = m_data + m_iElementCount;
        for (int k = 0; k < 1; ++k)
            out[k] = e;
        ++m_iElementCount;
    }
};
void FUN_00cf1480(float a, float b, void* p);
void ProcessBlocks(S00cb5100_Body* b, float f, float g, int h);
struct S00cb5100_World
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
    S00cb5100_Arr arr28;
    S00cb5100_Body** data34;
    int size38;
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
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    float f1d0;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char b305;
    unsigned char b306;
    union
    {
        unsigned char b307;
        S00cb5100_Bits bits307;
    };
};

void ProcessSceneCallbacks(S00cb5100_World* w, S00cb5100_Body* b);

static __declspec(noinline) S00cb5100_Body* FindItemForThreshold(S00cb5100_World* w, S00cb5100_Arr* arr, int n,
                                                                 S00cb5100_Body* b)
{
    if (w->size38 == 0 || arr->m_iElementCount == 0)
        return 0;
    return arr->pick(&n, &b, w->size38);
}

static inline bool S00cb5100_lt(unsigned char a, unsigned char b)
{
    return a < b;
}

// Moves b from w's data34 list to arr28, resets its entries, then merges it with another body via FUN_00cb4c60 if merge allows, else may swap it to the front.
// @fnv 0x00cb5100
void FUN_00cb5100(S00cb5100_World* apWorld, S00cb5100_Body* apBody, bool merge)
{
    apWorld->data34[apBody->idx20] = apWorld->data34[apWorld->size38 - 1];
    apWorld->data34[apBody->idx20]->idx20 = apBody->idx20;
    apWorld->size38--;

    S00cb5100_Arr* arr = &apWorld->arr28;
    arr->AddBack(apBody);

    apBody->idx20 = (unsigned short)(apWorld->arr28.m_iElementCount - 1);
    apBody->f30 = 0.0f;
    apBody->f34 = 0.0f;
    apBody->flags26 = (apBody->flags26 & ~2) | 1;

    for (int i = 0; i < apBody->count4c; i++)
    {
        S00cb5100_Ent* e = apBody->list48[i];
        FUN_00cf1480(0.0f, 0.0f, &e->unkf0);
        e->wea = 0;
        e->wec = 0;
        e->setFilter(apWorld->b305, apWorld->b306, apWorld->b307);
    }

    ProcessBlocks(apBody, apBody->f44, apWorld->f1d0, apWorld->unk78);
    S00cb5100_Ent* e0 = apBody->list48[0];
    e0->FUN_00c90510();
    ProcessSceneCallbacks(apWorld, apBody);
    if (e0->owner_cc == apBody)
    {
        e0->FUN_00c905b0();
        if (merge)
        {
            int m = apBody->f1c + 3;
            int n = apBody->count4c + 1;
            if (n > m)
                m = n;
            S00cb5100_Body* o = FindItemForThreshold(apWorld, arr, m, apBody);
            if (o)
            {
                FUN_00cb4c60((ObjA*)apWorld, (int)o, (int)apBody);
                return;
            }
        }
        unsigned int idx = apBody->idx20;
        if (idx != 0)
        {
            S00cb5100_Body* first = arr->m_data[0];
            if (apBody->count4c > first->count4c)
            {
                apBody->idx20 = 0;
                first->idx20 = (unsigned short)idx;
                arr->m_data[0] = apBody;
                arr->m_data[idx] = first;
            }
        }
    }
    else
    {
        e0->FUN_00c905b0();
    }
}

#include <xmmintrin.h>
extern float DAT_01017d00;

__forceinline int c6a870Equals3(const __m128& a, const __m128& b, float eps = 0.001f)
{
    static __declspec(align(16)) const unsigned int mask[4] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
    __m128 d = _mm_sub_ps(a, b);
    d = _mm_and_ps(d, _mm_load_ps((const float*)mask));
    __m128 e = _mm_set_ps1(eps);
    return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
}

struct C6A870_Child
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044, f048, f04c, f050, f054, f058, f05c;
    int f060, f064, f068, f06c, f070, f074, f078, f07c;
    int f080, f084, f088, f08c, f090, f094, f098, f09c;
    int f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc;
    int f0c0, f0c4, f0c8, f0cc, f0d0, f0d4, f0d8, f0dc;
    int f0e0, f0e4, f0e8, f0ec, f0f0, f0f4, f0f8, f0fc;
    int f100, f104, f108, f10c, f110, f114, f118, f11c;
    int f120, f124, f128, f12c, f130, f134, f138, f13c;
    int f140, f144, f148, f14c, f150, f154, f158, f15c;
    int f160, f164, f168, f16c, f170, f174, f178, f17c;
    int f180, f184, f188, f18c, f190, f194, f198, f19c;
    int f1a0, f1a4, f1a8, f1ac;
    __m128 m_vLinearConstraint;
    __m128 m_vAngularConstraint;
};

struct C6A870_Item
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044;
    C6A870_Child** m_children;
    int m_uiItemCount;
};

struct C6A870_Heap;
typedef void*(__thiscall* C6A870_AllocFn)(C6A870_Heap*, int&);
typedef void(__thiscall* C6A870_FreeFn)(C6A870_Heap*, void*, int);
struct C6A870_HeapTable
{
    void* v00;
    void* v04;
    void* v08;
    C6A870_AllocFn alloc;
    C6A870_FreeFn free;
};
struct C6A870_Heap
{
    C6A870_HeapTable* table;
    __forceinline void* AllocateBufferWithSize(int& numBytes)
    {
        return table->alloc(this, numBytes);
    }
    __forceinline void ReturnMemory(void* p, int n) throw()
    {
        table->free(this, p, n);
    }
    template <typename T> __forceinline T* _bufAlloc(int& n, int& numBytes)
    {
        C6A870_AllocFn alloc = table->alloc;
        numBytes = n * int(sizeof(T));
        void* p = alloc(this, numBytes);
        n = numBytes / int(sizeof(T));
        return (T*)p;
    }
};

__forceinline C6A870_Heap& c6a870Heap()
{
    return *(C6A870_Heap*)&FUN_00c85750()->heap();
}

template <typename T> __forceinline void c6a870Copy(T* dst, const T* src, int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> struct C6A870_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline C6A870_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~C6A870_Array() throw()
    {
        _clearAndDeallocate(c6a870Heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(C6A870_Heap& h) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _copyFromArray(C6A870_Heap& h, const C6A870_Array& a, int& scratch)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                h.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = a.GetLogicalSize();
            m_data = h._bufAlloc<T>(n, scratch);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        c6a870Copy(m_data, a.m_data, m_iElementCount);
    }
    __forceinline C6A870_Array& assign(const C6A870_Array& a, int& scratch)
    {
        _copyFromArray(c6a870Heap(), a, scratch);
        return *this;
    }
};

struct C6A870_World
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024;
    C6A870_Array<C6A870_Item*> m_items;
};

void __cdecl FUN_00cb55d0(C6A870_World* world);
void __cdecl AddItemToContainer(C6A870_World* world, C6A870_Item* item);

struct C6A870_Self;
typedef C6A870_World*(__thiscall* C6A870_Query)(C6A870_Self*);
struct C6A870_QueryTable
{
    void* f00;
    void* f04;
    void* f08;
    void* f0c;
    void* f10;
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    void* f40;
    void* f44;
    void* f48;
    void* f4c;
    void* f50;
    void* f54;
    void* f58;
    void* f5c;
    void* f60;
    void* f64;
    void* f68;
    void* f6c;
    void* f70;
    void* f74;
    void* f78;
    void* f7c;
    void* f80;
    void* f84;
    void* f88;
    void* f8c;
    void* f90;
    C6A870_Query query;
};
struct C6A870_View
{
    C6A870_QueryTable* table;
};

struct C6A870_Self
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
    virtual C6A870_World* getWorld();

    void FUN_00c6a870();
};

// Calls AddItemToContainer for each world item whose children all have both constraint vectors equal to a constant, with FUN_00cb55d0 called before and after.
// @fnv 0x00c6a870
void C6A870_Self::FUN_00c6a870()
{
    int i;
    C6A870_World* world = getWorld();
    if (!world)
        return;

    getWorld();
    FUN_00cb55d0(world);
    getWorld();

    C6A870_Array<C6A870_Item*> items;
    getWorld();
    items.assign(world->m_items, i);
    C6A870_QueryTable* pQueryTable = ((C6A870_View*)this)->table;
    pQueryTable->query(this);

    for (i = 0; i < items.GetLogicalSize(); ++i)
    {
        C6A870_Item* item = items[i];
        char moved = 0;
        int n = item->m_uiItemCount;
        for (int j = 0; j < n; j++)
        {
            if (moved)
                break;
            C6A870_Child* c = item->m_children[j];
            if (c6a870Equals3(c->m_vLinearConstraint, _mm_load_ps((const float*)&DAT_01267e30)))
            {
                if (c6a870Equals3(c->m_vAngularConstraint, _mm_load_ps((const float*)&DAT_01267e30)))
                    continue;
            }
            moved = 1;
        }
        if (!moved)
        {
            getWorld();
            AddItemToContainer(world, item);
            getWorld();
        }
    }

    getWorld();
    FUN_00cb55d0(world);
    getWorld();
}

struct Motion4120
{
    virtual void unused();
    unsigned short storageSize, refCount;
    unsigned char kind, counter;
    unsigned short inactive[2];
    __forceinline int frames(int slot, int flag)
    {
        int packed = inactive[slot];
        int mode = packed >> 14;
        int n;
        if (flag != mode)
        {
            n = packed & 127;
        }
        else
        {
            n = (packed >> 7) & 127;
        }
        return n & 127;
    }
};
struct Selector
{
    unsigned char first;
    unsigned char second;
};

struct Entry4120
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
    int unk98;
    int unk9c;

    int unka0;
    int unka4;
    int unka8;
    int unkac;

    unsigned short countB0;
    unsigned short unkb2;
    unsigned short unkb4;
    unsigned short unkb6;

    unsigned short unkb8;
    unsigned short unkba;
    unsigned short unkbc;
    unsigned short unkbe;

    unsigned short unkc0;
    unsigned short unkc2;
    unsigned short unkc4;
    unsigned short unkc6;

    unsigned short unkc8;
    unsigned short unkca;
    unsigned short unkcc;
    unsigned short unkce;

    unsigned short unkd0;
    unsigned short unkd2;
    unsigned short unkd4;
    unsigned short unkd6;

    unsigned short unkd8;
    unsigned short unkda;
    unsigned short unkdc;
    unsigned short unkde;

    Motion4120 motion;
    __forceinline Motion4120* movement()
    {
        return &motion;
    }
};
template <class T> struct View4120
{
    T* data;
    int count;
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline int size() const
    {
        return count;
    }
};
struct Groups4120
{
    View4120<int>& groups;
    int n;
};
template <class T> __forceinline T greater4120(T a, T b)
{
    return a > b ? a : b;
}

// Iterates entries, marks active groups when motion frames are 5 or fewer, and accumulates per-group size counts.
// @fnv 0x00cb4120
static __declspec(noinline) void UpdateGroupActivity(const Groups4120& map, const View4120<Entry4120*>& entries,
                                                     int unusedGroups, View4120<int>& active, View4120<int>& sizes,
                                                     unsigned char* flags)
{
    for (int i = 0; i < entries.size(); ++i)
    {
        Entry4120* entity = entries[i];
        int group = map.groups[i];
        int frames = greater4120(entity->movement()->frames(0, flags[0]), entity->movement()->frames(1, flags[1]));
        if (frames <= 5)
        {
            active[group] = 1;
        }
        int count = greater4120(1, (int)entity->countB0);
        sizes[group] += count;
    }
}

extern const Groups4120* volatile inputMap4120;
extern const View4120<Entry4120*>* volatile inputEntities4120;
extern View4120<int>* volatile outputActive4120;
extern View4120<int>* volatile outputSizes4120;
extern unsigned char* volatile inputFlags4120;
extern int volatile groupCount4120;
void caller4120()
{
    UpdateGroupActivity(*inputMap4120, *inputEntities4120, groupCount4120, *outputActive4120, *outputSizes4120,
                        inputFlags4120);
}

struct Inner;
struct CallA
{
    signed char delta;
    void UpdateCollisionIndices();
    void CopyAndSortGeometryList(void* p);
};
struct Mgr2
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
    unsigned char unk24;
    bool splitRequested : 2;
    bool sparseEnabled : 2;
    bool cleanup : 2;
    bool inActive : 2;
    unsigned char unk26, unk27;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int m_4c;
    int unk050;
    int unk054;
    int m_58;
    __forceinline void mark()
    {
        splitRequested = true;
    }
    __forceinline int count() const
    {
        return m_4c;
    }
};
struct MotionObj
{
    void* vt;
    int unk04;
    Inner* m_08;
    int unk0c;
    CallA collidable;
    unsigned char unk11, unk12, unk13;
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
    Mgr2* m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8, unke9, unkea, unkeb;
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
    int m_1f8;
};
struct Inner
{
    int unk00, unk04;
    MotionObj* m_08;
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
    int m_8c, m_90, m_94, unk98;
    unsigned char m_9c, m_9d, unk9e, unk9f;
    int m_a0, m_a4;
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
    float m_1d0;
};
typedef void(__thiscall* FnFree)(void* self, void* p, int bytes);
typedef void(__thiscall* Fn20)(void* self, void* p, int a, void* b, int c);
struct RemRef
{
    void FUN_00c905b0();
};

struct CallB
{
    void UpdateNodeSlotIndices();
    void FUN_00c90510();
};
struct CallInner
{
    void FUN_00c946e0(void* p, void* q, int a);
    void FUN_00c91120();
    void FUN_00c91140();
};
void FUN_00cf9c60(void* p, int a, void* b);
void FUN_00cb5000(MotionObj* a0, void* b);
void CollectActorEntries(Inner* s, MotionObj* a0, void* a);
void CollectProducers(Inner* s, MotionObj* a0, void* a);
void FUN_00cb4740(Inner* s, MotionObj* a0);
void FUN_00cb3ca0(Inner* s, void* e, int z);
struct ModeBool
{
    bool value;
    ModeBool()
    {}
    ModeBool(bool b) : value(b)
    {}
    ModeBool(const ModeBool& b) : value(b.test())
    {}
    void set(bool b)
    {
        static_cast<volatile bool&>(value) = b;
    }
    bool test() const
    {
        return value;
    }
    operator bool() const
    {
        return test();
    }
};
void FUN_00cb4230(MotionObj* a0, int mode, ModeBool fMode, ModeBool fCur, Inner* s);
void FUN_00cb4640(Inner* s, int a5, int a7);
void ApplyConstraintsToEntity(Inner* s, int a8, void* p);
void FUN_00cb3ee0(void* m, MotionObj* a3, void* w, int mode);
void FUN_00cff290(void* m, void* w);
void FUN_00cb5570(Inner* in, MotionObj* a0, MotionObj* e);
void UpdateRotationInterpolation(float f, void* p);
void NotifyEntityRemoved(void* p, MotionObj* a3);
struct VecB
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct VecA
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct Work
{
    int f0;
    void* data;
    int size;
    int cap;
    int buf0;
};
struct Elem8
{
    int f0;
    MotionObj* f4;
};
struct VecC
{
    Elem8* data;
    int size;
    int cap;
    VecC() : data(0), size(0), cap((int)0x80000000)
    {}
};
struct HeadC
{
    short unk10;
    ModeBool fCur;
    ModeBool fMode;
};
static __forceinline void FreeVec(void** dataP, int* sizeP, int* capP, int elem)
{
    S_00c6aca0_Router* m = FUN_00c85750();
    void* fo = m->m10;
    int cap = *capP;
    *sizeP = 0;
    if ((cap & (int)0x80000000) == 0)
    {
        FnFree fn = (FnFree)(*(void***)fo)[4];
        fn(fo, *dataP, (cap & 0x3fffffff) * elem);
    }
    *dataP = 0;
    *capP = (int)0x80000000;
}
// Returns if mode equals a0->m_e8; else calls FUN_00cb4230 and, if a0->m_08 is set and exactly one mode is 5, updates owner state, lists and constraints.
// @fnv 0x00cb6f70
void FUN_00cb6f70(MotionObj* apMotionObj, int aiNewMode, int a2, MotionObj* a3, int a4, int a5, int a6, int a7, int a8)
{
    {
        ModeBool fCur;
        ModeBool fMode;
        unsigned long uiCurMode = apMotionObj->m_e8;
        if (uiCurMode == aiNewMode)
            return;
        if (uiCurMode == 5)
        {
            apMotionObj->collidable.UpdateCollisionIndices();
            ((CallB*)apMotionObj)->UpdateNodeSlotIndices();
        }
        if (aiNewMode == 5)
            fMode.set(0);
        else
        {
            fMode.set(1);
            if (aiNewMode == 4)
                fMode.set(0);
        }
        if (uiCurMode == 5)
            fCur.set(0);
        else
        {
            fCur.set(1);
            if (uiCurMode == 4)
                fCur.set(0);
        }
        if (fMode.test() && !fCur.test() && apMotionObj->m_1f8 == 0)
            return;
        ((CallB*)apMotionObj)->FUN_00c90510();
        Inner* pForm = apMotionObj->m_08;
        bool diff5 = ((uiCurMode == 5) != (aiNewMode == 5));
        if (pForm != 0 && diff5)
        {
            VecB adj;
            VecA a;
            Work esi;
            adj.data = adj.buf;
            adj.cap = (int)0x80000010;
            a.data = a.buf;
            a.cap = (int)0x80000010;
            pForm->m_9c = 1;
            pForm->m_9d = 0;
            adj.size = 0;
            a.size = 0;
            esi.data = &esi.buf0;
            esi.size = 0;
            esi.cap = (int)0x80000001;
            esi.f0 = 0x200;
            FUN_00cb5000(apMotionObj, &adj);
            if (aiNewMode != 5)
                CollectActorEntries(pForm, apMotionObj, &a);
            else
                CollectProducers(pForm, apMotionObj, &a);
            Mgr2* manager = apMotionObj->m_cc;
            FUN_00cb3ee0(&manager->m_58, apMotionObj, &esi, aiNewMode);
            if (uiCurMode != 5)
            {
                if (apMotionObj->m_cc->count() > 2)
                    apMotionObj->m_cc->splitRequested = true;
            }
            FUN_00cb4740(pForm, apMotionObj);
            FUN_00cb4230(apMotionObj, aiNewMode, fMode, fCur, pForm);
            FUN_00cb4640(pForm, (int)apMotionObj, a2);
            ApplyConstraintsToEntity(pForm, (int)apMotionObj, &a);
            pForm->m_9d = 1;
            VecC vec;
            for (int i = 0; i < adj.size; i++)
            {
                MotionObj* e = ((MotionObj**)adj.data)[i];
                FUN_00cb3ca0(pForm, e, 0);
                ((RemRef*)e)->FUN_00c905b0();
            }
            if (aiNewMode != 5)
            {
                apMotionObj->collidable.CopyAndSortGeometryList(&vec);
                for (int i = 0; i < vec.size; i++)
                {
                    MotionObj* pOtherMotion = vec.data[i].f4;
                    MotionObj* work =
                        (MotionObj*)((char*)pOtherMotion + (int)(signed char)pOtherMotion->collidable.delta);
                    if (apMotionObj->m_e8 == 5)
                        continue;
                    if (work->m_e8 == 5)
                        continue;
                    if (apMotionObj->m_cc == work->m_cc)
                        continue;
                    FUN_00cb5570(apMotionObj->m_08, apMotionObj, work);
                }
            }
            FUN_00cff290(&apMotionObj->m_cc->m_58, &esi);
            if (aiNewMode == 5)
            {
                UpdateRotationInterpolation(pForm->m_1d0, &apMotionObj->unk0f0);
                MotionObj* o8 = pForm->m_08;
                pForm->m_94++;
                Fn20 fn = (Fn20)(*(void***)o8)[8];
                fn(o8, &apMotionObj, 1, pForm, 7);
                FUN_00cf9c60(&apMotionObj, 1, pForm);
                NotifyEntityRemoved(apMotionObj->m_08, apMotionObj);
                pForm->m_94--;
            }
            ((CallInner*)pForm)->FUN_00c946e0(apMotionObj, a3, 1);
            pForm->m_9c = 0;
            if (pForm->m_94 == 0)
            {
                if (pForm->m_8c != 0)
                    ((CallInner*)pForm)->FUN_00c91120();
                if (pForm->m_a4 == 1 && pForm->m_90 != 0)
                    ((CallInner*)pForm)->FUN_00c91140();
            }
            FreeVec((void**)&vec.data, &vec.size, &vec.cap, 8);
            FreeVec(&esi.data, &esi.size, &esi.cap, 4);
            FreeVec(&a.data, &a.size, &a.cap, 4);
            FreeVec(&adj.data, &adj.size, &adj.cap, 4);
        }
        else
        {
            FUN_00cb4230(apMotionObj, aiNewMode, fMode, fCur, pForm);
            if (pForm ? true : false)
                ((CallInner*)pForm)->FUN_00c946e0(apMotionObj, a3, 1);
        }
    }
    ((RemRef*)apMotionObj)->FUN_00c905b0();
}

struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
struct InertiaTensor
{
    InertiaTensor()
    {}
    S00cb4230_Vec4 m_kColumn0;
    S00cb4230_Vec4 m_kColumn1;
    S00cb4230_Vec4 m_kColumn2;
};
struct S00cb4230_Rotation : InertiaTensor
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
struct S00cb4230_Swept
{
    S00cb4230_Swept()
    {}
    float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    S00cb4230_Vec4 m_vCenterOfMass0;
    S00cb4230_Vec4 m_vCenterOfMass1;
    S00cb4230_Quat m_qRotation0;
    S00cb4230_Quat m_qRotation1;
    S00cb4230_Vec4 m_vCenterOfMassLocal;
};
extern float DAT_010c7948[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    S00cb4230_Swept& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const S00cb4230_Swept& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void FUN_00c86660(void* p);
    S00cb4230_Transform m_kMotionTransform;
    S00cb4230_Swept m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
enum S00cb4230_MotionType
{
    S00cb4230_INVALID,
    S00cb4230_DYNAMIC,
    S00cb4230_SPHERE,
    S00cb4230_BOX,
    S00cb4230_KEYFRAMED,
    S00cb4230_FIXED
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct AllocObj
{
    virtual void v00();
    virtual void* v01(int size);
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00();
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    {}
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(InertiaTensor& out) const;
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    S00cb4230_MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return m_kMotionState.getSweptTransform().m_qRotation1;
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return m_kMotionState.getSweptTransform().m_vCenterOfMassLocal;
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<S00cb4230_MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0();
    void FUN_00d1dff0();
    void SetFlagBits(int a, int b, int c);
    void getMotionStateAndVelocitiesAndDeactivationType(MotionBase* p);
    float FUN_00c86430();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        S_00c6aca0_Heap& h = FUN_00c85750()->heap();
        RefHeader31* b = static_cast<RefHeader31*>(((AllocObj*)&h)->v01(static_cast<int>(nbytes)));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S00cb4230_Keyframed : MotionBase
{
    S00cb4230_Keyframed() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    S00cb4230_Keyframed(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : S00cb4230_Keyframed
{
    MotionState() : S00cb4230_Keyframed()
    {}
};
struct BoxMotion : MotionBase
{
    BoxMotion(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
enum S00cb4230_Quality
{
    S00cb4230_QUALITY_FIXED,
    S00cb4230_QUALITY_KEYFRAMED
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    char m_auiShapeKeys;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(getCollidable()->getQualityType());
    }
    void setQualityType(S00cb4230_Quality type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = char(type);
    }
    void UpdateBoundingVolume(void* a, const void* b);
};
struct Node4
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    char m_305;
    char m_306;
    char m_307;
    float FUN_00c91020();
};
void __cdecl FUN_00cb1280(void* p, int a, int b);
template <typename T> __forceinline T* __cdecl S00cb4230_AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
void __cdecl FUN_00ca8240(int mode, const S00cb4230_Vec4* p40, const S00cb4230_Quat* p80, float fret,
                          const InertiaTensor* out, const S00cb4230_Vec4* p90, float f0, float f1, MotionBase* motion);
void __cdecl UpdateRotationInterpolation(float f, S00cb4230_MotionStateData* p);

// Switches the object's motion state to the requested mode, copying or constructing the appropriate MotionBase and updating collidable motion state.
// @fnv 0x00cb4230
void __cdecl FUN_00cb4230(ThisObj* self, S00cb4230_MotionType mode, MotionFlag31 flagA, MotionFlag31 flagB, Node4* node)
{
    if (flagA)
    {
        if (!flagB)
        {
            MotionBase* motion = self->getMotion();
            MotionState* pState = motion->m_118;
            motion->v25(pState);
            pState->m_0a = 0;
            pState->m_0c = 0;
            self->setQualityType(S00cb4230_Quality(motion->m_11c));
            S00cb4230_String::memCpy16NonEmpty(&self->m_pMotionState, pState, sizeof(MotionState) >> 4);
            FUN_00cb1280(S00cb4230_AddByteOffset(&self->m_pMotionState, sizeof(MotionState)), 0, 0);
            pState->FUN_00c905b0();
            self->UpdateBoundingVolume(node, self->getCollidable()->getShape());
        }

        if (self->m_pMotionState.getType() == mode || mode == S00cb4230_DYNAMIC)
        {
        }
        else
        {
            MotionState localState;
            S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
            InertiaTensor inertiaTensor;
            MotionBase* pMotionBase = &self->m_pMotionState;
            pMotionBase->GetInverseScaleMatrix(inertiaTensor);
            S00cb4230_MotionStateData* pStateData = localState.GetMotionState();
            float fRestitution = pStateData->m_fRestitution;
            float j = pStateData->m_fSurfaceFriction;
            FUN_00ca8240(mode, &localState.getPosition(), &localState.getRotation(), localState.FUN_00c86430(),
                         &inertiaTensor, &localState.getCenterOfMassLocal(), j, fRestitution, &self->m_pMotionState);
            localState.getMotionStateAndVelocitiesAndDeactivationType(pMotionBase);
            pMotionBase->setLinearDamping(localState.getLinearDamping());
            pMotionBase->setAngularDamping(localState.getAngularDamping());
            localState.FUN_00d1dff0();
            goto e0;
        }
    }
    else
    {
        MotionBase* pObj;
        MotionState localState;
        S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
        if (mode == S00cb4230_FIXED)
        {
            pObj = new (&self->m_pMotionState) BoxMotion(self->getPosition(), self->getRotation());
            pObj->m_kMotionState.FUN_00c86660(&localState.m_kMotionState);
            pObj->m_09 = localState.m_09;
            float c = localState.GetMotionState()->getSweptTransform().getInvDeltaTime();
            if (c != 0.0f)
            {
                UpdateRotationInterpolation(node ? node->FUN_00c91020()
                                                 : 1.0f / c +
                                                       localState.GetMotionState()->getSweptTransform().getBaseTime(),
                                            &pObj->m_kMotionState);
            }
        }
        else
        {
            pObj = new (&self->m_pMotionState) S00cb4230_Keyframed(self->getPosition(), self->getRotation());
            localState.getMotionStateAndVelocitiesAndDeactivationType(pObj);
        }

        if (flagB)
        {
            MotionState* cnt = new MotionState();
            unsigned short GetAllocationSize = cnt->m_04;
            S00cb4230_String::memCpy16NonEmpty(cnt, &localState, sizeof(MotionState) >> 4);
            cnt->m_04 = GetAllocationSize;
            cnt->m_06 = 1;
            pObj->m_118 = cnt;
            pObj->m_11c = (short)self->getCollidable()->getQualityType();
            self->UpdateBoundingVolume(node, self->getCollidable()->getShape());
        }
        else
        {
            MotionBase* old = &localState;
            pObj->v27(old->m_118);
            pObj->m_11c = old->m_11c;
        }
        self->m_a4 = 0;
        self->setQualityType(S00cb4230_Quality(mode != S00cb4230_FIXED));
        localState.FUN_00d1dff0();
    }
e0:
    self->m_kCollidable.setMotionState(self->getRigidMotion()->GetMotionState());
    if ((bool)node)
    {
        self->getMotion()->SetFlagBits((unsigned char)node->m_305, (unsigned char)node->m_306,
                                       (unsigned char)node->m_307);
    }
}

struct MergeWorld
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
    unsigned char state0;
    bool enabled;
    unsigned char state2;
    unsigned char state3;
    int unk0d8;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
union MergeListArg
{
    Cb4890_ElemArray* value;
};
static __forceinline void tallyActive(Cb4890_RemapTable* remap_, Cb4890_ElemArray*& list, int n,
                                      Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt, MergeWorld* owner,
                                      Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        int a = Dec(e->m_ec, owner->m_306);
        int b = Dec(e->m_ea, owner->m_305);
        int am = a & 0x7f;
        int bm = b & 0x7f;
        int mx = (bm > am) ? bm : am;
        if (mx <= 5)
            map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}

static __forceinline void tallyAll(Cb4890_RemapTable* remap_, Cb4890_ElemArray* list, int n,
                                   Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
// Tallies element weights per remap index, then greedily packs them into output slots bounded by owner->unk0b4 and calls FUN_00d282c0.
// @fnv 0x00cb49e0
void FUN_00cb49e0(MergeWorld* owner, int remap_, MergeListArg listArg, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    Cb4890_ElemArray* list = listArg.value;
    int n = src->m_iElementCount;
    Cb4890_LocalBuffer<int> cnt(n);
    Cb4890_ElemArray* activeList = list;
    Cb4890_LocalBuffer<int> map(n);

    for (int i = 0; i < n; i++)
    {
        map[i] = 0;
        cnt[i] = 0;
    }

    if (owner->enabled)
        tallyActive((Cb4890_RemapTable*)remap_, activeList, n, map, cnt, owner, listArg.value);
    else
        tallyAll((Cb4890_RemapTable*)remap_, list, n, map, cnt);

    for (int k = 0; k < n; k++)
    {
        if (map[k] == 0)
            cnt[k] = -1;
    }

    int pos = 0;
    int* pMap = map.m_p;
    for (int k = 0; k < n; k++)
    {
        int v = cnt[k];
        if (v == -2)
            continue;
        int p = pos++;
        out->m_data[p] = 0;
        pMap[k] = p;
        if (v < 0)
            continue;
        for (int j = k + 1; j < n; j++)
        {
            if (v + 10 >= owner->unk0b4)
                break;
            int w = cnt[j];
            if (w < 0)
                continue;
            if (v + w >= owner->unk0b4)
                continue;
            out->m_data[p] = 1;
            pMap[j] = p;
            v += w;
            cnt[j] = -2;
        }
    }

    ((Cb4890_RemapTable*)(*(volatile int*)&remap_))->RemapAndAccumulate(map, pos, src);
}

namespace fnv_00cb5000 {
extern "C" void _ReadWriteBarrier(void);
struct FUN_00cb5000_obj
{
    void Refresh();
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

Holder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* apAllocator, void* apVector, unsigned int auiElemSize);
void __cdecl FUN_00cb3dd0(int aCtx, int aObj, int aFlag);

struct PtrVec
{
    int* m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct Entry48
{
    FUN_00cb5000_obj* m_pEntryObject;
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
};

struct OwnerObj
{
    int unk00;
    int unk04;
    int m_iCtx;
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    Entry48* m_pEntries;
    unsigned short m_wEntryCount;
    unsigned short unkB2;
    int* m_pPtrs;
    int m_iPtrCount;
};

// Walks owner entries and pointers in reverse, calling Refresh and FUN_00cb3dd0 on each object and appending it to the output vector.
// @fnv 0x00cb5000
void __cdecl FUN_00cb5000(OwnerObj* apOwner, PtrVec* apOut)
{
    int ctx = apOwner->m_iCtx;
    int i = (int)apOwner->m_wEntryCount - 1;
    if (i >= 0)
    {
        do
        {
            FUN_00cb5000_obj* pObj = apOwner->m_pEntries[i].m_pEntryObject;
            pObj->Refresh();
            FUN_00cb3dd0(ctx, (int)pObj, 0);
            Holder* pHolder = FUN_00c85750();
            if (apOut->m_uCount == (apOut->m_uCapFlags & 0x3fffffffu))
            {
                ResizeAudioStream(pHolder->m_pAllocator, apOut, 4);
            }
            unsigned int idx = *(unsigned int volatile*)&apOut->m_uCount;
            int* data = apOut->m_pData;
            int* pSlot = &data[idx];
            _ReadWriteBarrier();
            *pSlot = (int)pObj;
            apOut->m_uCount++;
            i--;
        } while (i >= 0);
    }

    i = apOwner->m_iPtrCount - 1;
    if (i >= 0)
    {
        do
        {
            FUN_00cb5000_obj* pObj = (FUN_00cb5000_obj*)apOwner->m_pPtrs[i];
            pObj->Refresh();
            FUN_00cb3dd0(ctx, (int)pObj, 0);
            Holder* pHolder = FUN_00c85750();
            if (apOut->m_uCount == (apOut->m_uCapFlags & 0x3fffffffu))
            {
                ResizeAudioStream(pHolder->m_pAllocator, apOut, 4);
            }
            unsigned int idx = *(unsigned int volatile*)&apOut->m_uCount;
            int* data = apOut->m_pData;
            int* pSlot = &data[idx];
            _ReadWriteBarrier();
            *pSlot = (int)pObj;
            apOut->m_uCount++;
            i--;
        } while (i >= 0);
    }
}
}  // namespace fnv_00cb5000

struct S00cb3ee0_Entry
{
    int item;
    char* obj;
};

struct S00cb3ee0_Holder
{
    S00cb3ee0_Entry* entries;
    int count;
};

struct S00cb3ee0_Sub
{
    S00cb3ee0_Holder* FUN_00d081e0();
};

int PickIslandByValue(int a, int b, int c);
void CloneRecord(int a, int b);
void FUN_00cfe020(int a, int b);

// For each entry, calls FUN_00cfeca0 and FUN_00cfe020 if its owner byte at +0xe8 is 5, or if mode is 5 and PickIslandByValue returns motion+0xcc.
// @fnv 0x00cb3ee0
void FUN_00cb3ee0(void* m, MotionObj* motion, void* w, int mode)
{
    int a1 = (int)m;
    char* a2 = (char*)motion;
    int a3 = (int)w;
    int a4 = mode;
    S00cb3ee0_Holder* h = ((S00cb3ee0_Sub*)((char*)a2 + 0x10))->FUN_00d081e0();
    int i = 0;
    if (h->count > 0)
    {
        do
        {
            S00cb3ee0_Entry* e = &h->entries[i];
            char* obj = e->obj;
            char* esi = obj + (signed char)obj[0x10];
            if (*(unsigned char*)(esi + 0xe8) == 5)
            {
                int item = e->item;
                CloneRecord(a3, item);
                FUN_00cfe020(a1, item);
            }
            else if (a4 == 5)
            {
                if (PickIslandByValue(e->item, *(int*)(a2 + 0xcc), *(int*)(esi + 0xcc)) == *(int*)(a2 + 0xcc))
                {
                    int item = e->item;
                    CloneRecord(*(int*)(esi + 0xcc) + 0x58, item);
                    FUN_00cfe020(a1, item);
                }
            }
            ++i;
        } while (i < h->count);
    }
}

struct S55Item;

template <typename T>

struct S55Array
{

    T* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }

    __forceinline void popBack()
    {
        m_iElementCount--;
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00c6aca0_Heap& a, int n);

    __forceinline void _setSize(S_00c6aca0_Heap& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
};

void __cdecl FUN_00c908c0(S_00c6aca0_Heap& a, void* array, int reqCapacity, int sizeElem);

template <typename T>

__forceinline void S55Array<T>::GrowArrayCapacity(S_00c6aca0_Heap& a, int n)

{

    const int capacity = getCapacity();

    if (capacity < n)
    {

        int cap2 = 2 * capacity;

        int newSize = (n < cap2) ? cap2 : n;

        FUN_00c908c0(a, this, newSize, sizeof(T));
    }
}

struct S55Item
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int m_1c;

    unsigned short unk20;

    unsigned short m_22;

    unsigned char unk24;

    unsigned char m_25;

    unsigned char m_26;

    unsigned char unk27;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    S55Array<S55Item*> m_38;

    int unk44;

    ObjB** m_48;

    int m_4c;
};

struct S55Bool
{

    char m_cBooleanValue;

    S55Bool(bool b) : m_cBooleanValue(b)
    {}
};

struct S55Owner
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

    S55Array<S55Item*> m_28;

    int unk34;

    int unk38;

    int unk3c;

    S55Array<S55Item*> m_40;

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

    int m_b4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    unsigned char m_c8;

    void __thiscall FUN_00c910b0();
};

void __cdecl FUN_00cb5100(S55Owner* owner, S55Item* item, S55Bool b);

void __cdecl FUN_00cb5310(S55Owner* owner, S55Item* item);

extern "C" void __cdecl FUN_00cb5570(S55Owner* owner, ObjB* first, ObjB* second);

// Sorts owner->m_40, then drains it by popping items, compacting their m_38 arrays, and applying state changes via FUN_00cb5100, FUN_00cb5310, or FUN_00cb5570.
// @fnv 0x00cb55d0
void __cdecl FUN_00cb55d0(S55Owner* owner)

{

    if (owner->m_40.m_iElementCount == 0)

        return;

    if (owner->m_40.m_iElementCount > 1)

        FUN_00dd7d00((S_00dd7d00_Item**)owner->m_40.m_data, 0, owner->m_40.m_iElementCount - 1,

                     (S_00dd7d00_Less)FUN_00cb3f90);

    for (int i = 0; i < owner->m_40.m_iElementCount; i++)
    {

        S55Item* it = owner->m_40.m_data[i];

        if (it)

            it->m_22 = (unsigned short)i;
    }

    S55Item* it;

    int w;

    while (owner->m_40.m_iElementCount)
    {

        w = -1;

        it = owner->m_40.back();

        owner->m_40.m_iElementCount += w;

        if (!it)

            continue;

        it->m_22 = 0xffff;

        if (it->m_25 & 0x30)
        {

            S55Array<S55Item*>& arr = it->m_38;

            int k = 0;

            for (; k < arr.m_iElementCount; k++)
            {

                if (arr.m_data[k] == 0)
                {

                    w = k;

                    k++;

                    break;
                }
            }

            int d = w;

            for (; k < arr.m_iElementCount; k++)
            {

                if (arr.m_data[k] != 0)

                    arr.m_data[d++] = arr.m_data[k];
            }

            if (d != -1)

                arr._setSize(FUN_00c85750()->heap(), d);

            it->m_25 &= 0xcf;
        }

        unsigned char f = it->m_26;

        unsigned char newState = (f >> 2) & 3;

        if (newState != (f & 3))
        {

            if (newState)

                FUN_00cb5100(owner, it, true);

            else

                FUN_00cb5310(owner, it);
        }
        else if (f & 0x30)
        {

            it->m_26 = f & 0xcf;

            int n = it->m_4c;

            if (n <= it->m_1c)

                n = it->m_1c;

            S55Item* r =
                (S55Item*)FindItemForThreshold((Owner_cb3d10*)owner, (List_cb3d10*)&owner->m_28, n, (Item_cb3d10*)it);

            if (r)

                FUN_00cb5570(owner, *it->m_48, *r->m_48);
        }
    }

    owner->FUN_00c910b0();
}

extern "C" void _ReadWriteBarrier();

namespace fnv_00cb4640 {
struct TaskCtx;
struct TaskNode
{
    int unk00;
    unsigned short size04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    short index20;
    unsigned short unk22;
    unsigned char id24;
    unsigned char flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char low26 : 2;
            unsigned char high26 : 2;
            unsigned char upper26 : 4;
        };
    };
    unsigned char unk27;
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
    void FUN_00d07420(TaskCtx* arg);
    TaskNode* FUN_00d07830(TaskCtx* arg);
};
struct TaskList
{
    TaskNode** data;
    union
    {
        int count;
        struct
        {
            short countLow;
            short countHigh;
        };
    };
    int capacity;
};
struct TaskCtx
{
    int unk00;
    int unk04;
    TaskCtx* parent08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TaskNode* node20;
    int unk24;
    TaskList list28;
    TaskList list34;
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
    unsigned char enabledC8;
    unsigned char unkC9;
    unsigned short unkCA;
    int unkCC;
    int unkD0;
    unsigned char idD4;
    unsigned char unkD5;
    unsigned short unkD6;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char typeE8;
};
struct TaskHeap
{
    virtual void slot0();
    virtual TaskNode* alloc(int size);
};

// Sets b's parent to a, then calls FUN_00d07420 with b on a node of a: node20 if b's type is 5, else one found or allocated in list28/list34 or list28's first.
// @fnv 0x00cb4640
void __cdecl FUN_00cb4640(TaskCtx* apParent, TaskCtx* apChild, int mode)
{
    apChild->parent08 = apParent;
    if (apChild->typeE8 == 5)
    {
        apParent->node20->FUN_00d07420(apChild);
        return;
    }
    TaskNode* node;
    if (apParent->enabledC8)
    {
        bool active = mode == 1;
        TaskList* list;
        if (active)
        {
            list = &apParent->list28;
            TaskNode* found = (TaskNode*)::FindItemForThreshold((::Owner_cb3d10*)apParent, (::List_cb3d10*)list, 4, 0);
            if (found)
            {
                found->FUN_00d07420(apChild);
                return;
            }
        }
        else
        {
            list = &apParent->list34;
        }
        ::S_00c6aca0_Router* router = ::FUN_00c85750();
        TaskHeap* heap = (TaskHeap*)router->m10;
        TaskNode* raw = heap->alloc(0x6c);
        raw->size04 = 0x6c;
        node = raw->FUN_00d07830(apParent);
        node->high26 = active;
        node->low26 = active;
        node->index20 = (short)list->count;
        node->id24 = (unsigned char)node->index20;
        router = ::FUN_00c85750();
        if (list->count == (list->capacity & 0x3fffffff))
            ::fnv_00cb5480::ResizeAudioStream(router->m10, list, 4);
        TaskNode** slot = list->data + list->count;
        _ReadWriteBarrier();
        *slot = node;
        ++list->count;
    }
    else
    {
        node = apParent->list28.data[0];
    }
    node->FUN_00d07420(apChild);
    node->id24 = apChild->idD4;
}

}

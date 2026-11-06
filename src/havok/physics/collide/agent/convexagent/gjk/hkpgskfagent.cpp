
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00dacc00();
void __cdecl TestGsk();
void __cdecl FUN_00dac450();
void __cdecl FUN_00daf8e0();

struct FUN_00dacc70_vt
{
    void (*m_pVirtualFunction0)();
    void (*m_pVirtualFunction1)();
    void (*m_pVirtualFunction2)();
    void (*m_pVirtualFunction3)();
    unsigned char b0;
    unsigned char b1;
};

// Assigns four function pointers to the object's vtable slots and clears its two byte fields.
// @fnv 0x00dacc70
void __cdecl InitVtable(FUN_00dacc70_vt* p)
{
    p->m_pVirtualFunction0 = (void (*)())FUN_00dacc00;
    p->m_pVirtualFunction1 = (void (*)())TestGsk;
    p->m_pVirtualFunction2 = (void (*)())FUN_00dac450;
    p->m_pVirtualFunction3 = (void (*)())FUN_00daf8e0;
    p->b0 = 0;
    p->b1 = 0;
}

void __cdecl ReleaseAllEntries(void*, void*, void*);

struct FUN_00dacaf0_vt
{
    void(__thiscall* dtor)(void*, int);
};

struct FUN_00dacaf0
{
    FUN_00dacaf0_vt* vt;  // +0x00
    void* field4;         // +0x04
    void* field8;         // +0x08
    char pad[0x24];       // +0x0c..0x2f
    char field30[0x10];   // +0x30
    void cleanup(void* arg);
};

// Calls ReleaseAllEntries with field30, field8 and arg, then invokes the virtual destructor on this with flag 1.
// @fnv 0x00dacaf0
void FUN_00dacaf0::cleanup(void* arg)
{
    ReleaseAllEntries(&field30[0], field8, arg);
    vt->dtor(this, 1);
}

void __cdecl FUN_00dae340(void*, int);

struct hkpGskfAgent
{
    void removePoint(unsigned short id);
};

// Scans up to count entries at this+0x36 for a matching id and, if found, calls FUN_00dae340 with this+0x30 and the entry index.
// @fnv 0x00dacb20
void hkpGskfAgent::removePoint(unsigned short id)
{
    int count = *(unsigned char*)((char*)this + 0x32);
    int i = 0;
    if (count > 0)
    {
        char* p = (char*)this + 0x36;
        do
        {
            if (*(unsigned short*)p == id)
            {
                FUN_00dae340((char*)this + 0x30, i);
                return;
            }
            ++i;
            p += 8;
        } while (i < count);
    }
}

struct FUN_00dacb60_class
{
    unsigned char m_pad00[0x32];
    unsigned char m_uiItemCount;
    unsigned char m_pad01[3];

    struct Potential
    {
        unsigned short m_uiFilterValue;
        unsigned char m_auiShapeKeys[6];
    };

    Potential m_potentials[256];

    void __thiscall AddPotential(unsigned short value);
};

// @fnv 0x00dacb60
void __thiscall FUN_00dacb60_class::AddPotential(unsigned short value)
{
    int count = m_uiItemCount;
    int i;

    for (i = 0; i < count; ++i)
    {
        if (m_potentials[i].m_uiFilterValue == 0xffff)
        {
            m_potentials[i].m_uiFilterValue = value;
            return;
        }
    }
}

extern int DAT_010d5224;

struct FUN_00dabf10
{
    void* m_pVtbl;
    char m_b0[44];
    int m_i0;
    FUN_00dabf10(int, int, int);
    ~FUN_00dabf10();
};

struct FUN_00dacbd0 : FUN_00dabf10
{
    FUN_00dacbd0(int a, int b, int c);
    ~FUN_00dacbd0();
};

// Initializes the derived object: sets its vtable pointer to DAT_010d5224 and clears m_i0 after the base constructor runs.
// @fnv 0x00dacbd0
FUN_00dacbd0::FUN_00dacbd0(int a, int b, int c) : FUN_00dabf10(a, b, c)
{
    m_pVtbl = &DAT_010d5224;
    m_i0 = 0;
}

struct hkSlotDACB
{
    unsigned char m_00;
    unsigned char m_01;
    short m_iOwnerObjectOffset;
    int m_04;
};

class hkObjDACB
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    short unk30;
    unsigned char m_numSlots;
    unsigned char unk33;
    hkSlotDACB m_slots[8];

    void ClearSlotById(short id);
};

// @fnv 0x00dacba0
void hkObjDACB::ClearSlotById(short id)
{
    for (int i = 0; i < m_numSlots; i++)
    {
        hkSlotDACB& kSlot = m_slots[i];
        if (kSlot.m_iOwnerObjectOffset == id)
        {
            kSlot.m_00 = 0;
            kSlot.m_01 = 0;
            return;
        }
    }
}

struct Dvec4
{
    float x, y, z, w;
};

struct __declspec(align(16)) Dsub
{
    Dvec4 v0, v1, v2, v3;
    Dvec4 unk40, unk50;
    void FUN_00cb22f0(Dvec4* pts, Dvec4* other);
};

struct Dtask
{
    void* f00;
    void* f04;
    int f08;
    void* f0c;
    int f10;
    int unk14;
    int unk18;
    int unk1c;
    Dsub sub;
};

struct Dctx
{
    int f0;
    int f1;
    int f2;
    int f3;
};

struct Dsrc
{
    int unk00;
    int unk04;
    Dvec4* f08;
};

struct Drecv
{
    int unk00;
    int unk04;
    int f08;
    int f0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int f20;
    int unk24;
    int unk28;
    int unk2c;
    int f30;

    void FUN_00daccd0(Dsrc* a1, Dsrc* a2, Dsrc* a3, int a4);
};

void ProcessCollision(Dtask* task, int* ctx1, int* ctx2, int* node, int* a5, int* a6, int a7);

// Fills a Dtask from a1, a2, a3 and f08, calls FUN_00cb22f0 on its sub with a1->f08 and a2->f08, then ProcessCollision with the task, tmp, f0c, f30, f20 and a4.
// @fnv 0x00daccd0
void Drecv::FUN_00daccd0(Dsrc* a1, Dsrc* a2, Dsrc* a3, int a4)
{
    Dctx ctx;
    Dtask res;
    res.f08 = 0;
    res.f00 = a1;
    res.f04 = a2;
    res.f10 = f08;
    res.f0c = a3;
    res.sub.FUN_00cb22f0(a1->f08, a2->f08);
    ProcessCollision(&res, &ctx.f0, &ctx.f1, &f0c, &f30, &f20, a4);
}

class hkMemoryAllocatorDACC
{
  public:
    virtual ~hkMemoryAllocatorDACC() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDACC
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDACC* m_pStreamAllocator;
    hkMemoryAllocatorDACC& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDACC {
extern "C" hkMemoryRouterDACC& __cdecl FUN_00c85750() throw();
}

struct hkAllocHeaderDACC
{
    void* vtable;
    unsigned short allocationSize;
};

inline void* allocateAgentDACC(int nbytes)
{
    void* b = hkRouterDACC::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
    static_cast<hkAllocHeaderDACC*>(b)->allocationSize = (unsigned short)nbytes;
    return b;
}

struct GskInitDACC : FUN_00dacbd0
{
    FUN_00dabf10* __thiscall FUN_00dacbd0(int, int, int);
    FUN_00dabf10* __thiscall FUN_00dabf10(int, int, int);
};

// If c is nonzero, allocates 0x80 bytes and calls FUN_00dacbd0; otherwise allocates 0x30 bytes and calls FUN_00dabf10; returns the constructed object.
// @fnv 0x00dacc00
FUN_00dabf10* __cdecl FUN_00dacc00(int a, int b, int unused, int c)
{
    if (c)
        return static_cast<GskInitDACC*>(allocateAgentDACC(0x80))->FUN_00dacbd0(a, b, c);
    return static_cast<GskInitDACC*>(allocateAgentDACC(0x30))->FUN_00dabf10(a, b, 0);
}

__declspec(noinline) void __cdecl InitVtable(FUN_00dacc70_vt* p);

typedef FUN_00dacc70_vt D41FD0AgentFuncs;

struct D41FD0CollisionDispatcher
{
    void registerCollisionAgent(D41FD0AgentFuncs& funcs, int a, int b);
};

// Builds an agent function table with b0 and b1 zeroed and InitVtable, and registers it with the dispatcher for the pair 0x12, 0x12.
// @fnv 0x00dacca0
void __cdecl FUN_00dacca0(D41FD0CollisionDispatcher* dispatcher)
{
    D41FD0AgentFuncs funcs;
    funcs.b0 = 0;
    funcs.b1 = 0;
    InitVtable(&funcs);
    dispatcher->registerCollisionAgent(funcs, 0x12, 0x12);
}

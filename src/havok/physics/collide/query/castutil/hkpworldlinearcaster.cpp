
// src/havok/physics/collide/query/castutil/hkpworldlinearcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpworldlinearcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FloatHolder
{
    int unk00;
    float m_04;
};

struct SlotRecord
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    signed char m_05;
};

struct SlotTarget
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};

struct FuncEntry
{
    void* pfn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

typedef int(__cdecl* SlotFn)(int, int, int, int, int);

struct NodeMatcher
{
    virtual void v00();
    virtual unsigned char* Match(SlotRecord** ppRecord, int aKey, int aSlot);
};

struct hkpWorldLinearCaster
{
    int unk00;
    int unk04;
    NodeMatcher* m_08;
    FloatHolder* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int unk1c;
    unsigned char* m_20;

    float InvokeSlotHandler(SlotRecord* a1, int a2);
};

// Looks up a slot target, matches it via m_08, dispatches the handler from the m_20 table by code, and returns m_0c->m_04.
// @fnv 0x00cfae50
float hkpWorldLinearCaster::InvokeSlotHandler(SlotRecord* pRecord, int a2)
{
    int iSlotAddr = (int)pRecord + pRecord->m_05;
    SlotTarget* pTarget = *(SlotTarget**)iSlotAddr;
    if (pTarget != 0 && m_14 != iSlotAddr)
    {
        unsigned char* hit = m_08->Match((SlotRecord**)&pRecord, m_14, iSlotAddr);
        if (*hit != 0)
        {
            int index = ((m_18 + 0xd) << 5) + pTarget->m_0c;
            unsigned char code = m_20[index];
            FuncEntry* entries = (FuncEntry*)(m_20 + 0x9ac);
            SlotFn pfnHandler = (SlotFn)entries[code].pfn;
            pfnHandler(m_14, iSlotAddr, (int)&m_20, (int)m_0c, m_10);
        }
        return m_0c->m_04;
    }
    return m_0c->m_04;
}

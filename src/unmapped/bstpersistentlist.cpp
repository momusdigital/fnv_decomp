
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PoolLock_b1698
{
    void Lock(int hkSemaphore_release);
};

struct PoolNode_b1698
{
    PoolNode_b1698* m_00;
    unsigned int m_04;
};

extern "C" int DAT_011c5f80;
extern "C" PoolNode_b1698* DAT_011c5f58;
extern "C" int DAT_011c5f84;

struct FUN_00b63e90_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int* m_08;
    PoolNode_b1698* m_0c;

    void ReleasePoolNodes();
};

// @fnv 0x00b63e90
void FUN_00b63e90_cls::ReleasePoolNodes()
{
    PoolNode_b1698* cur = m_0c;
    if (cur != 0)
    {
        ((PoolLock_b1698*)&DAT_011c5f80)->Lock(0);
        do
        {
            PoolNode_b1698* node = cur;
            cur = cur->m_00;
            ((PoolLock_b1698*)&DAT_011c5f80)->Lock(0);
            node->m_04 = 0;
            node->m_00 = DAT_011c5f58;
            DAT_011c5f84 -= 1;
            DAT_011c5f58 = node;
            if (DAT_011c5f84 == 0)
            {
                DAT_011c5f80 = 0;
            }
        } while (cur != 0);
        DAT_011c5f84 -= 1;
        if (DAT_011c5f84 == 0)
        {
            DAT_011c5f80 = 0;
        }
    }
    unsigned int* p = m_08;
    m_0c = 0;
    if (p != 0)
    {
        *p = 0;
    }
}

struct FUN_00b63f10_Kind
{
    int m_type;
};

struct FUN_00b63f10_Target
{
    virtual void vf00();
    virtual void vf04();
    virtual const void* GetKind();
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
    unsigned char m_3c;
};

// sub-struct living at +0x9c, size 0x28 so that +0xa8, +0xbc and +0xc0 are inside it
struct FUN_00b63f10_Sub9C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00b63f10_Target* m_20;
    int m_24;
};

struct FUN_00b63f10_Arg
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
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    FUN_00b63f10_Sub9C m_9c;
};

typedef bool(__cdecl* FUN_00b63f10_Handler)(void* apThis, FUN_00b63f10_Arg* apArg, FUN_00b63f10_Sub9C* ap9c, int a8,
                                            int c0);

extern FUN_00b63f10_Kind g_011f49d8;
extern FUN_00b63f10_Handler g_011f9f80[];

struct FUN_00b63f10_CH
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
    int unk190;
    int unk194;
    int unk198;
    int m_19c;
    bool DispatchHandler(FUN_00b63f10_Arg* apArg);
};

// Checks the target object's kind and m_3c, then dispatches to the handler at g_011f9f80[m_19c] (or index 0) using the sub-object's m_24 and m_0c.
// @fnv 0x00b63f10
bool FUN_00b63f10_CH::DispatchHandler(FUN_00b63f10_Arg* apArg)
{
    FUN_00b63f10_Target* p = apArg->m_9c.m_20;
    if (p == 0 || p->GetKind() != &g_011f49d8 || p->m_3c != 0)
    {
        FUN_00b63f10_Sub9C* p9c = &apArg->m_9c;
        int c0 = p9c->m_24;
        int a8 = p9c->m_0c;
        if (c0 == 0 || a8 == 0)
            return true;
        FUN_00b63f10_Handler fn = g_011f9f80[m_19c];
        if (fn != 0)
            return fn(this, apArg, p9c, a8, c0);
        return g_011f9f80[0](this, apArg, p9c, a8, c0);
    }
    return true;
}

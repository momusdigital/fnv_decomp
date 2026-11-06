
// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_011f5b40;
void* __cdecl FUN_00a86fe0();
void __cdecl FinalizeEntries();
void __cdecl FUN_00a745c0();
void __cdecl RenderImmediate();
struct FUN_00a86ff0_shell
{
    void SetEntryActive(unsigned int index);
};

struct PointerSource
{
    int FUN_0059bb30();
    int FUN_0045cd60();
};
extern PointerSource* g_011dea10;

struct ScreenSize
{
    int* FUN_0043d4d0();
};
extern ScreenSize g_011c63cc;

struct HitRect
{
    int unk00;
    int extent;
    short left;
    short top;
    bool FUN_006fede0();
};

// @fnv 0x006fede0
bool HitRect::FUN_006fede0()
{
    int y;
    int x;
    x = g_011dea10->FUN_0059bb30() - (int)((unsigned int)*g_011c63cc.FUN_0043d4d0() >> 1);
    y = g_011dea10->FUN_0045cd60() - (int)((unsigned int)*g_011c63cc.FUN_0043d4d0() >> 1);
    if (x + *g_011c63cc.FUN_0043d4d0() >= left && x <= left + extent && y + *g_011c63cc.FUN_0043d4d0() >= top &&
        y <= top + extent)
    {
        return true;
    }
    return false;
}

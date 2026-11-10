// src/fallout/magic/nonactormagiccaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/nonactormagiccaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void FUN_00825b60();
void _Deallocate(void*);

struct NonActorMagicCaster
{
    void FUN_00825b60();
    void* ScalarDeletingDestructor(unsigned int flags);
};

// Calls FUN_00825b60, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00825aa0
// src: EXE 0x00825aa0
void* NonActorMagicCaster::ScalarDeletingDestructor(unsigned int flags)
{
    FUN_00825b60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

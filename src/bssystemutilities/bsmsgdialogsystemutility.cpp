// src/bssystemutilities/bsmsgdialogsystemutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystemutilities/bsmsgdialogsystemutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManagerGlobals.h"
MemoryManager g_memoryManager;

struct BSMsgDialogSystemUtility
{
    void __thiscall SetVirtualTable_00af3420();
    void* ScalarDeletingDestructor(unsigned int flags);
};

// Calls FUN_00af3420, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00af3440
// src: EXE 0x00af3440
void* BSMsgDialogSystemUtility::ScalarDeletingDestructor(unsigned int flags)
{
    SetVirtualTable_00af3420();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

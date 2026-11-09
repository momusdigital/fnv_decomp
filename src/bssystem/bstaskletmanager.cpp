
// src/bssystem/bstaskletmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bstaskletmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSTaskletManagerCallback.h"
#include "../../include/MemoryManager.h"

extern "C" void* __cdecl _DeallocateAlias(void*);
extern int vftable_BSTaskletManagerCallback;
extern MemoryManager g_memoryManager;

// Sets the vtable to vftable_BSTaskletManagerCallback and, when flags has bit 0 set, deallocates this through g_memoryManager, returning this.
// @fnv 0x00b00e90
void* __thiscall BSTaskletManagerCallback::Destroy(unsigned int flags)
{
    *reinterpret_cast<int**>(this) = &vftable_BSTaskletManagerCallback;
    if (flags & 1)
    {
        g_memoryManager._DeallocateAlias(this);
    }
    return this;
}

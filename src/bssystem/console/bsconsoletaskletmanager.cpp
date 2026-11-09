
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSTaskletManager.h"
#include "../../../include/MemoryManager.h"

extern int vftable_BSTaskletManager;
extern MemoryManager g_memoryManager;
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
// @fnv 0x00b02780
void* __thiscall BSTaskletManager::Destroy(unsigned int flags)
{
    *(int*)this = (int)&vftable_BSTaskletManager;
    CloseHandle(_0c);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

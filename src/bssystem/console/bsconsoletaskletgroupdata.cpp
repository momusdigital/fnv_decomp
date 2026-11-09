
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSTaskletGroupData.h"

extern int vftable_BSTaskletGroupData;
struct MMgr
{
    void _DeallocateAlias(void* p);
};
extern MMgr g_memoryManager;
// Sets the object's vtable pointer to vftable_BSTaskletGroupData and, if flags has bit 1 set, deallocates the object via g_memoryManager, returning this.
// @fnv 0x00b029c0
void* BSTaskletGroupData::DestroyIfFlagged(unsigned int flags)
{
    *(void**)this = (void*)&vftable_BSTaskletGroupData;
    if (flags & 1)
        g_memoryManager._DeallocateAlias((void*)this);
    return (void*)this;
}


#include "nitmap_decls.h"
template<>
// @fnv 0x00844a70
void* NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>::NewItem() {
    return allocator.FUN_006f99e0();
}
// @fnv 0x00975cf0
void NiTMap<TESGlobal*, bool>::NewItem() {
    g_011d6a30.FUN_004ee920();
    DAT_011d6a20 = 0;
}
template<>
// @fnv 0x0048eff0
void NiTMap<unsigned int, CombatThreatRecord*>::NewItem(void* item) {
    ReleaseKF(item, 1);
}

// gamebryo2.2/corelibs/nimain/nitmap_decls.h: declares NiMapAllocator

class BGSReconstructCellSubBlocksMap;
class CombatThreatRecord;
class TESGlobal;
class NiMapAllocator
{
  public:
    void* FUN_006f99e0();
};
class GlobalObject_004ee810
{
  public:
    void FUN_004ee920();
};
extern GlobalObject_004ee810 g_011d6a30;
extern unsigned int DAT_011d6a20;
template <class K, class V> class NiTMap
{
    unsigned int mapHeader[3];
    NiMapAllocator allocator;

  public:
    void* NewItem();
    void NewItem(void* item);
    void ReleaseKF(void* item, int mode);
};
template <> class NiTMap<TESGlobal*, bool>
{
  public:
    static void NewItem();
};

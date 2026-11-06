// fallout_shared/packagelocation_decls.h: declares LocationDescriptor
#ifndef FNV_PACKAGELOCATION_DECLS_H
#define FNV_PACKAGELOCATION_DECLS_H


class TESForm;
class TESObjectREFR;
class TESObjectCELL;
class MobileObject;

enum PACK_LOC_TYPE
{
    PLT_NONE = -1,
    PLT_REFERENCE = 0,
    PLT_CELL = 1,
    PLT_CURRLOC = 2,
    PLT_EDITORLOC = 3,
    PLT_OBJECT = 4,
    PLT_TYPE = 5,
    PLT_LINKEDREF = 6,
    PLT_FIRSTLOC = 7
};

// LocationDescriptor's nonvirtual, 12-byte layout is shared by the PC accessors
class LocationDescriptor
{
  public:
    char m_ucLocationType;
    unsigned int m_pLocationData;
    union
    {
        TESForm* pObject;
        TESObjectREFR* pRef;
        TESObjectCELL* pCell;
        TESForm* m_pLocationObject;
    };

    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    PACK_LOC_TYPE GetLocType() const;
    void SetLocCell(TESObjectCELL* cell);
    void SetValue(TESForm* object);
    // Keep this distinct, community-confirmed callee address explicit.
    void SetLocReference(TESObjectREFR* reference);
    void InitItem(TESForm* owner);
    TESObjectREFR* ResolveLocationReference(MobileObject* object);
};

typedef char PackageLocation_size_check[sizeof(LocationDescriptor) == 12 ? 1 : -1];
#endif

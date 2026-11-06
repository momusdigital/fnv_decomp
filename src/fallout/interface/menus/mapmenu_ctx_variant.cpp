
// mapmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/mapmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "mapmenu_decls.h"
// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    SetSelectedTile(0, notify);
}

struct TESFullName
{
    const char* GetFullName();
};

class PathingLocation
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    PathingLocation();
    PathingLocation(const NiPoint3*, TESWorldSpace*);
    ~PathingLocation();
    PathingLocation& operator=(const PathingLocation&);
    bool FUN_006de250();
};

class TESWorldSpaceCustom : public TESWorldSpace
{
  public:
    int unk10;
    int unk14;
    TESFullName fullName;

    bool HasFlag2();
    const char* GetWorldMapTextureName();
};

class TESDataHandler
{
  public:
    BSSimpleList<TESWorldSpace*>* GetWorldSpaces();
};

extern TESDataHandler* g_dataHandler;

extern "C" char* __cdecl FindString(const char*, const char*);
unsigned int __cdecl BSStringLength(const char*);
extern "C" int __cdecl _mbsnicmp(const char*, const char*, size_t);

// @fnv 0x007984d0
TESWorldSpace* MapMenu::FUN_007984d0(NiPoint3 pt)
{
    TESWorldSpace* result5 = 0;
    float maxDist = 3.402823466e+38F;
    for (BSSimpleList<TESWorldSpace*>* node2 = g_dataHandler->GetWorldSpaces(); node2 && node2->GetItem();
         node2 = node2->GetNext())
    {
        TESWorldSpaceCustom* ws4 = (TESWorldSpaceCustom*)node2->GetItem();
        const char* name = ws4->fullName.GetFullName();
        NiPoint3 ptCopy3 = pt;
        PathingLocation loc4;
        if (!name || !*name || FindString(name, "test") == name || ws4->HasFlag2())
        {
            continue;
        }
        ws4->GetCellAtPosition(ptCopy3, true);
        loc4 = PathingLocation(&ptCopy3, ws4);
        if (loc4.FUN_006de250() && this->m_pCurrentWorldspace && ws4)
        {
            if (BSStringLength(((TESWorldSpaceCustom*)this->m_pCurrentWorldspace)->GetWorldMapTextureName()) < 31 ||
                BSStringLength(ws4->GetWorldMapTextureName()) < 31)
            {
                continue;
            }
            if (_mbsnicmp(((TESWorldSpaceCustom*)this->m_pCurrentWorldspace)->GetWorldMapTextureName() + 29,
                          ws4->GetWorldMapTextureName() + 29, 3) == 0)
            {
                result5 = ws4;
                break;
            }
        }
    }
    if (!result5)
    {
        result5 = g_dataHandler->GetWorldSpaces()->GetItem();
    }
    return result5;
}

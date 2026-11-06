// bsmenu/tilemenu.cpp: TileMenu, TileRect, TileMenuStub (6 functions)

#include "tilemenu_decls.h"
#include "tilemenu_private.h"

// @fnv 0x00709a40
int TileMenu::GetType()
{
    return 0x389;
}

// @fnv 0x00a1ef30
void TileMenu::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    Tile::Init(parent, name, replacedChild);
    Set(0xFA1, 0.0f, true);
    Set(0xFA2, 0.0f, true);
    Set(0xFA8, 1.0f, true);
    Set(0xFC1, 0.25f, true);
    Set(0xFF4, 1.0f, true);
    Set(0xFA3, 0.0f, true);
    SetTileType(3);
    pMenu = 0;
}

// @fnv 0x00a1f140
NiNode* TileMenu::CalculateNode()
{
    NiNode* node = TileRect::CalculateNode();
    return node;
}

__forceinline TileRect::~TileRect()
{
    if (!IsSpecial())
        Release();
}
// @fnv 0x00a1eff0
TileMenu::~TileMenu()
{
    if (pMenu)
    {
        Menu::SetVisible(pMenu->GetID(), false);
        Menu::SetMenuRootTile(pMenu->GetID(), 0);
        pMenu->SetTileMenu(0, false);
        delete pMenu;
    }
    if (!IsSpecial())
        Release();
}

// @fnv 0x00a1f160
Tile* TileMenu::SetTraitValue(int valueID, float floatValue, const char* strValue)
{
    if (valueID == 0xFA4)
    {
        if (!pMenu)
        {
            Menu* menu = Interface::GetMenuById((int)floatValue);
            pMenu = menu;
        }
        if (!pMenu)
        {
            DebugLog("ERROR: Cant find menu class!");
        }
        else
        {
            pMenu->SetTileMenu(this, false);
            pMenu->m_iMenuId = pMenu->GetID();
            if (GetTraitFloat(0xFA7) == 102.0 || GetTraitFloat(0xFA7) == 103.0)
            {
                pMenu->SetModal(pMenu->GetID());
                Set(0xFAD, Menu::GetMenuScale(), true);
            }
            Menu::SetMenuRootTile((int)floatValue, this);
            return this;
        }
    }
    else if (pMenu && valueID >= 10000)
    {
        pMenu->OnUpdateUserTrait(valueID);
    }
    if (pMenu && valueID == 0xFA3)
    {
        Menu::SetVisible(pMenu->GetID(), floatValue != 0.0);
    }
    return 0;
}

class TileMenuStub : public TileMenu
{
  public:
    void ForceTextureRelease();
    void FUN_00a1f310();
};

// Returns early if pMenu's ID is 0x3ec or 0x3ef, otherwise calls ForceTextureRelease.
// @fnv 0x00a1f310
void TileMenuStub::FUN_00a1f310()
{
    if (pMenu && (pMenu->GetID() == 0x3ec || pMenu->GetID() == 0x3ef))
        return;
    else
        ForceTextureRelease();
}

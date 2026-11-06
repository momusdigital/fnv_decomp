// Private constructor declarations; field layouts follow the canonical PC headers.
#ifndef FNV_INVENTORYMENU_DECLS_H
#define FNV_INVENTORYMENU_DECLS_H

#include <stddef.h>
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]
class Tile;
class TileMenu;
class Tile__TileTemplate;
class InventoryStackRecord;
class TESBoundObject;
class ListBoxItem_ItemChange___;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    void AddHead(T&);
};
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    virtual void SetTile(unsigned int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleClick(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual unsigned int GetID();
    Tile* FUN_00726070();
    static bool ReadMenuDefinition(const char*, Menu*);
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    int m_iMenuId;
    int m_eFadeState;
};
class ListBoxBase
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04();
};
class InventoryMenu__sPageState
{
  public:
    int m_iSelectedItemIndex;  // +0x0
    int m_iScrollOffset;       // +0x4
};

class ListBox_ItemChange___ : public ListBoxBase
{
  public:
    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
    void Initialize(Tile*, const char*);
    void FUN_007a1930(bool);
    BSSimpleList<ListBoxItem_ItemChange___*> bSSimpleList_ListBoxItem_ItemChange______Component;  // +0x4
    Tile* m_pListTile;                                                                            // +0xC
    Tile* m_pSelectedTile;                                                                        // +0x10
    Tile* m_pHighlightedTile;                                                                     // +0x14
    const char* pTemplateName;                                                                    // +0x18
    unsigned short m_usSelectedIndex;                                                             // +0x1C
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned char layoutPadding2E[2];
};

class HotkeyWheelDisplay
{
  public:
    HotkeyWheelDisplay();
    ~HotkeyWheelDisplay();
    bool GetVisible();
    void SetVisible(bool);
    int GetSelectedHotkeyIndex(int);
    int FUN_006e4ba0();
    void SetHotkeyItem(InventoryStackRecord*);
    void Initialize(Tile*);
    Tile* m_pWheelTile;                  // +0x0
    Tile* m_ppHotkeySlotTiles[8];  // +0x4
    bool m_bHasHotkeySelection;    // +0x24
    unsigned char layoutPadding25[3];
    int m_iTileValueIdAtOffset28;  // +0x28
    int m_iTileValueIdAtOffset2C;  // +0x2C
    int m_iTileValueIdAtOffset30;  // +0x30
};

class InventoryMenu : public Menu
{
  public:
    InventoryMenu();
    virtual ~InventoryMenu();
    static int ms_iValueTileID;
    static int ms_iItemTypeTileID;
    static int ms_iCurrentTabTileID;
    static int ms_iKeyringOpenTileID;
    static int ms_iEquippableItemTileID;
    Tile* m_pTiles[23];                              // +0x28
    int m_iCurrentTab;                               // +0x84
    InventoryMenu__sPageState m_kPageStates[6];      // +0x88
    ListBox_ItemChange___ m_kItemList;               // +0xB8
    HotkeyWheelDisplay m_kMenuData;                        // +0xE8
    BSSimpleList<TESBoundObject*> m_kHotkeyObjects;  // +0x11C
    int GetClass();
    void UpdateDialog();
    static Tile* Create();
    static int FUN_0077ff80();
    bool HasAllInventoryTiles();
    void FUN_00867a20();
    static void UpdateItemList();
    static InventoryMenu* ms_pInventoryMenu;
    static InventoryStackRecord* ms_pActionPointSource;
    void AssignTileByID(int id, Tile* tile);
};

FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);

class Tile
{
  public:
    static int GetTraitID(const char*);
    void Set(int, int);
    void Set(int, float, bool);
    bool ContainsTrait(int);
    static float GetInterfaceScale();
    static Menu* FindMenuById(int);
    Tile* ReadFile(const char*);
    Menu* GetMenu();
    void Set(int, const char*, bool);
};
class TileListBoxCalls : public Tile
{
  public:
    float GetFloat(int);
};
class FOPipboyManager
{
  public:
    bool IsUnk28Set();
};
enum ENUM_FORM_ID;
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    static const int kArmor = 25;
    static const int kWeapon = 40;
    ENUM_FORM_ID GetFormType() const;
};
class TESBoundObject : public TESForm
{
};
class TESObjectARMO : public TESBoundObject
{
  public:
    float GetArmorRating();
    float GetDamageThreshold();
};
class InventoryStackRecord
{
  public:
    float GetConditionPercent(bool);
    TESBoundObject* FUN_0044ddc0();
};
class InputManager
{
  public:
    int FUN_00a24660(int, int);
    int FUN_00a23a50(int, int);
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720();
};
extern OSGlobals* g_osGlobals;
class ActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual float GetActorValue(int);
};
class PlayerCharacter
{
  public:
    unsigned char layoutPadding00[0xa4];
    ActorValueOwner actorValueOwner;
};
extern PlayerCharacter* g_thePlayer;
class Interface
{
  public:
    enum enumMenus
    {
        kInventory = 1002
    };
    static bool GetSelectedTargetIndex(enumMenus);
    static bool IsSaveLoadActive();
    static FOPipboyManager* GetPipboyManagerInstance();
    static void SetTileFormattedText(Tile*, int, const char*, ...);
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
class InterfaceManager
{
  public:
    class TutorialState
    {
      public:
        bool ShowMessage(int, int, unsigned int);
    };
    unsigned char layoutPadding00[0x4d4];
    TutorialState tutorialManager;
    Tile* FUN_00586150();
    static void UpdateContainerMenu(Tile*, Tile*, Tile*, InventoryStackRecord*, bool);
};
class InventoryMenuSetting
{
  public:
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d3810;
extern InventoryMenuSetting DAT_011d1e18;
extern bool DAT_011d9f38;
bool FUN_004b71d0();
InterfaceManager* FUN_004b7210();
int Warning(const char*, ...);
extern InventoryMenuSetting DAT_011d3258;
extern InventoryMenuSetting DAT_011d2acc;
extern InventoryMenuSetting DAT_011d40b4;
extern InventoryMenuSetting DAT_011d4d50;
extern InventoryMenuSetting DAT_011d29b8;
extern InventoryMenuSetting DAT_011d29f4;
extern InventoryMenuSetting DAT_011d2c7c;
extern InventoryMenuSetting DAT_011d412c;
extern InventoryMenuSetting DAT_011d330c;
extern InventoryMenuSetting DAT_011d20c4;
extern InventoryMenuSetting DAT_011d396c;
#endif

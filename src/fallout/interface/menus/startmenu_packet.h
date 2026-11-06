// Private declarations for the army-glm-5125 startmenu.cpp packet (tiny functions).
// Everything here is used only by this translation unit. Placeholder FUN_ names
// follow the approved placeholder convention and live in this one place so they
// can be renamed later in one spot.
#ifndef FNV_STARTMENU_PACKET_H
#define FNV_STARTMENU_PACKET_H


#include "layout_support.h"
#include "Menu.h"

#pragma pack(push, 4)

class Tile;
class BGSSaveLoadFileEntry;

// ListBox family (unit-local until the canonical ListBoxBase.h / ListBox_*.h declare their virtuals).
// PC layout as the canonical ListBox_*.h (0x30: vfptr, item list, tiles, ...); PC vftable = 9 slots:
class ListBoxBase
{
  public:
    virtual bool Highlight(Tile* apTile);                             // v00
    virtual Tile* GetHighlightedItem();                               // v04
    virtual Tile* GetTileForButton(int aeButton);                     // v08 (Interface::enumGamepadButtons)
    virtual bool BelongsTo(const Menu* apMenu);                       // v0C
    virtual void ScrollToHighlight();                                 // v10
    virtual Tile* GetTileAt(unsigned int auiIndex, bool abFiltered);  // v14
};

template <class T> class ListBoxItem
{
  public:
    Tile* pTile;       // +0x0
    T data;            // +0x4
    bool m_bFiltered;  // +0x8
};

template <class T> class ListBox : public ListBoxBase, public BSSimpleList<ListBoxItem<T>*>
{
  public:
    virtual ~ListBox();                                                              // v18
    virtual void RemoveAll();                                                        // v1C
    virtual void Sort(int(FNV_CDECL* apCompare)(ListBoxItem<T>*, ListBoxItem<T>*));  // v20
    void Initialize(Tile* apParent, const char* apTemplateName);
    Tile* AddItem(T aData, const char* apTemplateName, int(FNV_CDECL* apCompare)(ListBoxItem<T>*, ListBoxItem<T>*),
                  const char* apName);
    bool RemoveItem(Tile* apTile);
    bool RemoveAt(unsigned int auiIndex, bool abFiltered);
    bool IsListItem(Tile* apTile);
    bool IsEmpty();
    T GetSelectedData(Tile* apTile);
    T GetDataAt(unsigned int auiIndex, bool abFiltered);
    Tile* GetTileForData(const T& aData);
    unsigned int NumItems();
    void SetEnabled(bool abEnabled);
    bool IsEnabled();
    T GetHighlightedData();
    void ClearHighlight();
    void SetHighlightEnabled(bool abHighlight);
    ListBoxItem<T>* GetAt(unsigned int auiIndex, bool abFiltered);
    void SetFlag(int aeFlag, bool abSet);  // ListBox<T>::Flag
    bool GetFlag(int aeFlag);
    bool FUN_007d7580();               // 0x007d7580 (ListBox<BGSSaveLoadFileEntry*>, unnamed)
    Tile* m_pListTile;                 // +0x0C
    Tile* m_pSelectedTile;             // +0x10
    Tile* m_pHighlightedTile;          // +0x14
    const char* pTemplateName;         // +0x18
    unsigned short m_usSelectedIndex;  // +0x1C
    float m_fFirstListValue;           // +0x20
    float m_fSecondListValue;          // +0x24
    float m_fThirdListValue;           // +0x28
    unsigned short usFlags;            // +0x2C
};

// Hand-authored partial StartMenu layout for the members this translation unit
// consumes (same shape the accepted IsFlagSet body was compiled against).
class StartMenu : public Menu
{
  public:
    class Option;
    class UserOption;
    // StartMenu::OptionListBox: overrides GetTileForButton (PC vftable slot 2 = 0x007d6510).
    class OptionListBox : public ListBox<Option*>
    {
      public:
        virtual Tile* GetTileForButton(int aeButton);
    };
    enum Flag
    {
        FLAG_INGAME = 1,
        FLAG_OPTIONS_DIRTY = 2,
        FLAG_FORCE_RELOAD = 4,
        FLAG_SAVE_MODE = 8,
        FLAG_FADE_IN = 16,
        FLAG_SAVE_OPTIONS = 32,
        FLAG_RESET_HUD_OPACITY = 64,
        FLAG_DLC_NEEDS_UPDATE = 128,
        FLAG_NEW_DLC_INSTALLED = 256,
        FLAG_SEARCHING_DLC = 512,
        FLAG_DLC_WAIT_MESSAGE = 1024,
        FLAG_SYSUTILSAVECOMPLETE = 2048,
        FLAG_ACTION_MAPPING = 4096,
        FLAG_DELETE_MODE = 8192,
        FLAG_SAVE_WAIT_MESSAGE = 16384,
        FLAG_SAVE_WAIT_SAVING = 32768,
        FLAG_SHOWING_CREDITS = 65536,
        FLAG_DONT_FORCE_BACK = 131072,
        FLAG_SAVELOAD_BACKOUT = 262144,
        FLAG_IIS_PREFADE = 524288,
        FLAG_LOADING_SAVEGAMES = 1048576,
        FLAG_LIVE_MENU = 2097152,
        FLAG_RESTART_REQUIRED = 4194304,
        FLAG_MOUNT_DLC = 8388608,
        FLAG_DLC_CORRUPT_MESSAGE = 16777216,
        FLAG_USER_PRESSED_START = 33554432,
        FLAG_USER_IS_ACTION_MAPPING = 67108864,
        FLAG_MEM_CARD_REMOVED = 134217728,
        FLAG_SAVE_SAVING = 268435456,
        FLAG_MISSING_CONTENT = 536870912
    };
    bool IsFlagSet(Flag aFlag);
    static bool IsInGame();
    Tile* m_pTiles[23];  // +0x28
    // ListBox<T> (defined above): v00 Highlight, v04 GetHighlightedItem, v08 GetTileForButton, v0C BelongsTo, v10 ScrollToHighlight,
    // v14 GetTileAt, v18 ~ListBox, v1C RemoveAll, v20 Sort; StartMenu::Option / UserOption are defined below StartMenu.
    OptionListBox m_kFirstOptionListBox;             // +0x84
    OptionListBox m_kSecondOptionListBox;            // +0xB4
    OptionListBox m_kThirdOptionListBox;             // +0xE4
    OptionListBox m_kDownloadOptions;                // +0x114
    ListBox<int> m_kOptionIndexList;                 // +0x144
    ListBox<BGSSaveLoadFileEntry*> m_kOptionHelper;  // +0x174
    StartMenu::UserOption* m_pUserOption;            // +0x1A4
    unsigned int uiFlags;                            // +0x1A8
    float m_fMenuTimer;                              // +0x1AC
};

// StartMenu::Option: PC vftable .?AVOption@StartMenu@@ (1 slot); 0x10 bytes.
class StartMenu::Option
{
  public:
    virtual ~Option();  // v00
    bool IsForModes(unsigned int auiModes);
    const char* GetValueText;              // +0x04
    void(FNV_CDECL* m_pActionCallback)();  // +0x08
    unsigned int m_uiModes;                // +0x0C
};
// StartMenu::UserOption: PC vftable .?AVUserOption@StartMenu@@; 0x30 bytes.
class StartMenu::UserOption : public StartMenu::Option
{
  public:
    const char* pTemplate;                            // +0x10
    int iVal;                                         // +0x14
    int iDefaultValue;                                // +0x18
    int eType;                                        // +0x1C StartMenu::UserOption::UserOptionType
    unsigned int m_uiValueCount;                      // +0x20
    unsigned int m_uiModeFlags;                       // +0x24
    const char** m_ppOptionValues;                    // +0x28
    void(FNV_CDECL* m_pChangeCallback)(UserOption*);  // +0x2C
};

// 0x007d1340's receiver is g_thePlayer (PlayerCharacter, see callers 0x007d1260 /
// 0x007d12d0). The shared canonical PlayerCharacter header is not editable, so
// this translation unit completes the type with just the member it defines.
class PlayerCharacter
{
  public:
    int FUN_007d1340();  // reads +0x7C0
};

class NiTexture;
// layout_support.h's primary NiPointer template has no operator->; in the original
// the instantiations compile operator-> out of line and the identical bodies fold
// to 0x00559450 (canonical already binds the NiPointer<NiNode> instantiation there).
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* operator->() const;
};

// Receiver class of the +0x85/+0x87/+0x88 flag accessors around StartMenu's
// save/load UI (FUN_00a25920 hands out this class).
class BGSSaveLoadUI
{
  public:
    bool FUN_007d3170();      // reads +0x85
    void FUN_007d0bb0();      // sets +0x87
    void FUN_007d0bd0(bool);  // sets +0x88
};

class BGSSaveLoadFileEntry
{
  public:
    unsigned char layoutPadding00[0x10];
    char* m_pSaveFileName;  // +0x10
    unsigned char layoutPadding14[0x2C];
    NiPointer<NiTexture> spScreenshot;  // +0x40
    void
    ReadTypedData();  // ?ReadTypedData@BGSSaveLoadFileEntry@@QAEXXZ @ 0x00846900 (defined in the saveloadmanager unit)
    char* FUN_007d5140();       // ReadTypedData(); return m_pSaveFileName
    NiTexture* GetSaveScreenshot();  // return spScreenshot
};

class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
// 0x007d1b30 calls the routine at 0x00450410 through the receiver's own class and
// discards the result with no fstp, so at this call site it is the void variant
// (canonical binds the float variant ?FUN_00450410@GlobalObject_0044f440@@QAEMXZ
// to the same folded address).
class GlobalObject_004de370
{
  public:
    void FUN_00450410();
};
class GlobalObject_00709f00
{
  public:
    void GetBoolValue();
};

#pragma pack(pop)

FNV_STATIC_ASSERT(offsetof(StartMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(sizeof(ListBox<int>) == 0x30);
FNV_STATIC_ASSERT(offsetof(ListBox<int>, m_pListTile) == 0xC);
FNV_STATIC_ASSERT(offsetof(ListBox<int>, usFlags) == 0x2C);
FNV_STATIC_ASSERT(sizeof(StartMenu::Option) == 0x10);
FNV_STATIC_ASSERT(sizeof(StartMenu::UserOption) == 0x30);
FNV_STATIC_ASSERT(sizeof(StartMenu::OptionListBox) == 0x30);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_kFirstOptionListBox) == 0x84);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_kDownloadOptions) == 0x114);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_kOptionIndexList) == 0x144);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_kOptionHelper) == 0x174);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_pUserOption) == 0x1A4);
FNV_STATIC_ASSERT(offsetof(StartMenu, uiFlags) == 0x1A8);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_fMenuTimer) == 0x1AC);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_pSaveFileName) == 0x10);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, spScreenshot) == 0x40);

#endif

// ---- identities used by this packet (mapped in manifest.json) ----
extern bool DAT_011a0294;                 // ?DAT_011a0294@@3_NA
extern GlobalObject_004de370 g_011c71ac;  // ?g_011c71ac@@3VGlobalObject_004de370@@A
extern float DAT_011ad7b8[];              // ?DAT_011ad7b8@@3PAMA
extern GlobalObject_00709f00 g_011d8c4c;  // ?g_011d8c4c@@3VGlobalObject_00709f00@@A

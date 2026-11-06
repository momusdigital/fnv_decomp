// fallout/interface/menuconsole_decls.h: declares TaskQueueInterface, SettingT_GameSettingCollection_, NiFrustum, NiCamera, NiAVObject and more
#ifndef FNV_MENUCONSOLE_DECLS_H
#define FNV_MENUCONSOLE_DECLS_H

#include "menuconsole_support.h"
#include "ScriptHeaderData.h"

extern "C" char* __cdecl __insecure_strcpy(char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" int __cdecl sscanf(const char*, const char*, ...);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
int __cdecl strcat_s(char*, unsigned int, const char*);
int __cdecl _mbsicmp(const unsigned char*, const unsigned char*);
int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
int __cdecl _mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
template <class T> unsigned int BSStringLength(const T*);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
void DebugLog(const char*, ...);
int FUN_0071cfd0(const char*, const char*, unsigned int);
int FUN_0071cff0(const char*, const char*, unsigned int);
void FUN_005cbd90(char*, const char*, unsigned int);
void FUN_0071d030(ConsoleManager*, const char*, ...);
void FUN_007030c0(int, int);
void FUN_007038e0(int);
void FUN_00703920();
void FUN_00702c80(bool, bool);
void UpdateMenuTileVisibility();
int GetClassStatic();
int MinInt(int, int);
int FUN_00647b70(int, int);

union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
extern SettingT_GameSettingCollection_ DAT_011d8cfc;
extern SettingT_GameSettingCollection_ DAT_011d8d38;
extern bool DAT_011d8ce4;

class NiFrustum
{
  public:
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};
class NiCamera
{
  public:
    const NiFrustum& GetViewFrustum() const;
    void UpdateViewFrustum(const NiFrustum&);
};
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class NiNode : public NiAVObject
{
};
class SkyObject
{
  public:
    NiNode* GetRoot();
};
class BSFaceGenAnimationData;
class BSFaceGenNiNode
{
  public:
    BSFaceGenAnimationData* GetAnimationData();
};
class TESForm
{
  public:
    virtual ~TESForm();
    unsigned char m_eReferenceTypeInfo;
    unsigned char layoutPadding5[3];
    unsigned int m_uiFormFlags;
    unsigned int auiFormId;
    BSSimpleList<TESFile*> kFiles;
    void NotifySaveLoadGameOfFormChange();
    unsigned int GetFormID();
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    const char* GetFullName();
};
enum COMPILER_NAME
{
    COMPILER_NAME_CONSOLE = 1
};
class Script : public TESForm
{
  public:
    ScriptHeaderData m_kHeader;
    char* m_pText;
    char* m_data;
    float m_fValueAtOffset34, fValueAtOffset38, m_fValueAtOffset3C;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<ScriptReferencedObject*> m_kReferencedObjectList;
    BSSimpleList<ScriptVariableInfo*> m_kVariableList;
    Script();
    virtual ~Script();
    void SetText(const char*);
    void CompileScriptText(ScriptCompiler*, COMPILER_NAME, TESObjectREFR*);
};
FNV_STATIC_ASSERT(sizeof(Script) == 0x54);
class Tile
{
  public:
    virtual ~Tile();
    void Set(int, float, bool);
    const char* FUN_00700300();
    Tile* ReadFile(const char*);
    void SetParent(Tile*, Tile*);
    static int GetTraitID(const char*);
    static float GetInterfaceScale();
};
class TileListBoxCalls : public Tile
{
  public:
    float GetFloat(int);
};
Tile* FindNamedTile(Tile*, const char*);
class Menu
{
  public:
    virtual ~Menu();
    Tile* tile;
    static bool ReadMenuDefinition(const char*, Menu*);
};
class BookMenu : public Menu
{
  public:
    void ReadBook();
};
class TileMenu : public Tile
{
};
class TESResponse
{
  public:
    TESResponse* GetNext();
};
Menu* FindMenuById(int);
class TESObjectBOOK : public TESForm
{
};
class TESTopicInfo
{
  public:
    TESActorBase* GetSpeaker();
};
class StartMenu
{
  public:
    static bool Create(bool, bool);
};
class InterfaceManager
{
  public:
    bool FUN_007023a0();
    TESObjectREFR* FUN_007031c0();
    Tile* FUN_004fd400();
    Tile* FUN_00586150();
    void FUN_00500a20(Tile*);
    void SetNamedMenuOption(int);
    int GetTopEnterStackEntry();
    int GetMenuStackEntry(int);
    int AddMenuStackEntry(int, bool);
};
InterfaceManager* FUN_004b7210();
class MenuSystem
{
  public:
    static MenuSystem* Instance(bool);
    Tile* TileReloadContext(int);
    bool DeleteMenu(int);
    Menu* GetFrontmostMenu();
    bool IsMenuClassVisible(int);
};
class RgbaColor;
class DebugText
{
  public:
    static DebugText* Instance(bool);
    void FUN_00a103e0(char*, float, float, int);
    int Print(const char*, float, float, int, int, float, int, const RgbaColor* = 0);
    static void FUN_00a10c00(void*, const char*, int, float);
    static void ClearDebugText();
};
class FontManager
{
  public:
    static FontManager* __stdcall GetFontManager(bool);
    void SetByteAtOffset20();
};
void* DynamicCastByRTTI(void*, NiNode*);
extern unsigned char DAT_011f4428;
const char* FUN_00700300(Tile*);

class BSFile : public NiFile
{
  public:
    virtual ~BSFile();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool vfn_20(bool, bool);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual unsigned int vfn_34(char*, unsigned int, char);
    unsigned char m_fileData[0x154];
    BSFile(const char*, OpenMode, unsigned int, bool);
    void FUN_00473180(const void*, unsigned int);
    void Close();
};
FNV_STATIC_ASSERT(sizeof(BSFile) == 0x158);
FNV_STATIC_ASSERT(sizeof(NiFrustum) == 28);
#endif

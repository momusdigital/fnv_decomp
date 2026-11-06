// fallout/misc/saveload/bgssaveloadmanager_decls.h: declares TaskQueueInterface, TESFile, BGSLoadGameBuffer, SaveLoadHeader, BGSSaveLoadGame and more
#ifndef BGSSAVELOADMANAGER_DECLS_H
#define BGSSAVELOADMANAGER_DECLS_H

class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
class TESFile
{
  public:
    static char* IsTempIDLoadable();
};
int __cdecl strcat_s(char*, unsigned int, const char*);
char* __cdecl FUN_0086d480();
char* __cdecl FUN_004dc110();
char* __cdecl FUN_00c3bbd0();
char* __cdecl FUN_00c3bc20();
int __cdecl FUN_00ecbf05(const char*, int);
extern const char g_011d3eb0_arg1[];
extern const char g_011dece4_arg1[];
extern const char DAT_01082d70[];
extern const char DAT_01082d88[];
extern const char DAT_01082d94[];
extern const char DAT_01082da0[];
extern const char DAT_01082dac[];
extern const char DAT_01082dc4[];
extern const char* DAT_011a2ff0;
extern const char* DAT_011a2ff4;
extern int(__stdcall* DAT_00fdf0c4)(const char*, const char*, int, const char*);
extern int(__stdcall* DAT_00fdf274)(void*, int, void*, unsigned int, char*);
extern int(__stdcall* DAT_00fdf0b8)(const char*, void*);
extern int(__cdecl* DAT_00fdf0d4)(char*);
extern int(__stdcall* DAT_00fdf1b8)(const char*, const char*, int);

class SaveLoadFile;
class BGSLoadGameBuffer
{
  public:
    bool FUN_008463c0();
};
class SaveLoadHeader
{
  public:
    static int ReadHeaderFromFile(SaveLoadFile*);
    SaveLoadFile* ReadHeaderFromFile(SaveLoadFile*, bool, unsigned int, unsigned int);
};
class BGSSaveLoadGame
{
  public:
    bool LoadGame(SaveLoadFile*, bool);
    void FUN_0084cc40(bool);
};
class InterfaceManager
{
  public:
    void FUN_00714d70(int);
};
class Interface
{
  public:
    static bool IsInterfaceActive();
    static bool IsConsoleActive();
    static void RestoreConsoleVisibility();
    static bool ShowButtonDialog(const char*, const char*, const char*, void(__cdecl*)(), int, int, float, float,
                                 const char*, ...);
};
union SETTING_VALUE
{
    bool b;
    float f;
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
    SETTING_VALUE* Float();
};
class SettingT_GameSettingCollection_
{
  public:
    const char* String();
};
class GlobalObject_0040c150
{
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0040c150 g_011d2100, g_011d34f8, g_011d3684;
extern GlobalObject_0045cf30 g_011de248;
class OSGlobals;
class Main
{
  public:
    void RefreshAfterSave();
    void RunScripts();
    void OnGameLoaded();
};
extern OSGlobals* g_osGlobals;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern char DAT_011de138[260];
extern int DAT_011a224c;
extern bool DAT_011de23c;
extern int DAT_011dea24;
void __cdecl FUN_00850720();
void __cdecl DumpTextAndOpen(const char*);
InterfaceManager* __cdecl FUN_004b7210();

enum FADER_ENUM
{
    FADER_NONE = 0
};
class FaderManager
{
  public:
    bool HasFader(FADER_ENUM);
    void BeginFade(FADER_ENUM, float, bool);
};
extern Interface* DAT_011d8804;
class BGSSaveLoadManager;
extern BGSSaveLoadManager* DAT_011de134;

class ChallengeManager
{
  public:
    static void CheckCompletedChallenges();
};
class ModelLoader
{
  public:
    void ClearUnusedModels(bool);
    void FUN_00448420();
};
class TES
{
  public:
    void FUN_00459a00();
    void RefreshWorldState(int, int, int);
};
class ActorMover
{
  public:
    void RefreshMovementState();
};
template <class T, int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};
class GridCellArray
{
  public:
    void ReleaseGridCells();
};
class VATS
{
  public:
    void ProcessVATSCommands();
    void Update(int, bool);
};
class GlobalObject_009c6a30
{
};
extern GlobalObject_009c6a30 g_011f2250;
class NiPoint3;
class BGSTerrainManager
{
  public:
    void Update(const NiPoint3&, int);
};
class TESWorldSpace
{
  public:
    BGSTerrainManager* GetWorldTerrainManager();
};
class TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos() const;
    const char* GetFullName();
    TESWorldSpace* GetParentWorldSpace();
};
class PlayerCharacter : public TESObjectREFR
{
  public:
    bool GetUnderAIControl();
};
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern ModelLoader* g_modelLoader;
class BGSSaveLoadUI
{
  public:
    void FUN_007d0bd0(bool);
    void FUN_007d0bb0();
};
BGSSaveLoadUI* __cdecl FUN_00a25920();
class GameSettingCollection
{
  public:
    TESFile* FUN_004f8960();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting16;
class LoadingMenu
{
  public:
    static void UpdateLoadingScreenThread();
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    void FUN_00ad8740();
    void FUN_00ad84e0(int, bool);
    bool FUN_005bb4d0();
    void SetUseMultipleThreads(bool);
    void Update(bool);
};
void __cdecl FUN_00830660();
class GlobalObject_0096d020
{
  public:
    void FUN_00977660();
};
extern GlobalObject_0096d020 g_011e0e80;
class NavMeshObstacleManager
{
  public:
    static NavMeshObstacleManager* GetSingleton();
    void ResetObstacles();
    void Update();
};
class PathManager
{
  public:
    static PathManager* GetRandomGenerator();
    void FUN_006ebcd0();
    bool CallMemberFunction();
    void CallInner();
};

class TESQueuedCellManager
{
  public:
    void SubmitQueuedItems();
};
extern TESQueuedCellManager* DAT_011c9618;
void __cdecl FUN_005b4940();
void __cdecl FUN_005ae270();
void __cdecl FUN_005a9d60();
class HUDMainMenu
{
  public:
    bool RefreshTargetDisplay();
};
class InventoryStackRecord
{
  public:
    void SetEquipmentState(bool, bool);
};
class NiPoint3Interpolator
{
  public:
    void CreateObject(int, bool);
};
class TimeGlobal;
extern TimeGlobal g_timeGlobal;
class GameTimerRecord
{
  public:
    void SetGlobalTimeMultiplier(float, bool);
};
class ScriptLocals
{
  public:
    void ProcessPendingTasks();
};

class DownloadableContentManager
{
  public:
    const char* IsDLCAvailable();
};
extern GlobalObject_0040c150 g_011d38b8, g_011d3d0c;
extern const char DAT_0107fb78[];
extern const char DAT_0107faf8[];
class BGSSaveLoadManager
{
  public:
    unsigned char prefix[15];
    unsigned char m_cQueuedSaveLoad;
    unsigned char m_cAutosaveCountdown;
    unsigned char cQueuedQuicksave;
    unsigned char reserved12[14];
    SaveLoadFile* m_pSaveFile;
    bool m_bSaveOperationActive;
    bool m_bLoadOperationPending;
    bool m_bLoadingGame;
    bool LoadGame(const char*, int, bool, bool);
    bool CanLoadSaveGame(SaveLoadFile*);
    void FinishLoadingGame();
    void ProcessQueuedLoads();
    void ProcessQueuedSaveLoad();
    void Autosave();
    void FUN_008503b0(const char*, int, bool);
    void FUN_00850a90();
    void GetFullPath(char*, char*, bool);
    void FUN_00850100(SaveLoadFile*, bool);
    void SetSaveFileName(char*, int);
    static void GetSaveDirectory(char* output);
    bool IsQuickSaveFileName(const char* name);
    bool IsAutoSaveFileName(const char* name);
    void SanitizeSaveFileName(char* name);
    void GetFNVVersionInfo(char* output, unsigned int capacity);
    bool CanSave(bool);
    bool IsSaveFileNameDefault(const char*);
    bool IsSaveFileNameLegacyAutosave(const char*);
    bool IsSaveFileNameCustom(const char*);
    void UpdateSaveTimestamp();
    static void BuildAutosaveName(char*);
};
extern const char DAT_0107fae0[];
extern const char g_011d31e0_arg1[];
extern GlobalObject_0040c150 g_011d4060;
unsigned int gm_GetTickCount();
unsigned int FUN_00702440();
int FUN_00702400(unsigned int);
unsigned int FUN_008510e0();
extern const char DAT_01012058[];
#endif

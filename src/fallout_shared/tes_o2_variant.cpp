
// src/fallout_shared/tes_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tes.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_01202df8;
struct NiRTTI
{
};
struct FUN_00450620_shell
{
    const NiRTTI* GetNiRTTI() const;
};
struct BSTempNodeManager
{
    virtual ~BSTempNodeManager();
    void* FUN_00450630(unsigned int flags);
};
extern "C" void __cdecl FUN_00c44e20(BSTempNodeManager*);
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_004512a0_shell
{
    unsigned char m_ucState;
    void SetState(unsigned char ucState);
};
extern char DAT_01189184;
void FUN_00451520(unsigned char value);
struct NP
{
    NP& operator=(void*);
};
extern NP DAT_011f95e8;
void FUN_00451570(void* arg);
extern unsigned char DAT_011ad86c;
void FUN_00451590(unsigned char value);
struct AlchemyItem;
struct BGSAddonNode;
struct BGSDebris;
struct BGSExplosion;
struct BGSMessage;
struct BGSPerk;
struct BGSPrimitive;
struct BGSProjectile;
struct BGSVoiceType;
struct FormRecordHeader;
struct InventoryChanges;
struct InventoryStackRecord;
struct NiAVObject;
struct NiPoint3;
struct NiTriBasedGeom;
struct Script;
struct TESAmmoEffect;
struct TESBoundObject;
struct TESCaravanDeck;
struct TESCasino;
struct TESChallenge;
struct TESClass;
struct TESCombatStyle;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectREFR;
struct TESQuest;
struct TESRace;
struct TESRecipe;
struct TESRecipeCategory;
struct TESRegionDataManager;
struct TESRegionList;
struct TESReputation;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct TESDataHandler
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL*, void*, float, void*, float, int*, long);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, long);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject*, void*, TESObjectCELL*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    unsigned int GetAddonNodeCount();
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL* GetCellByNameAndGrid(char*);
    TESObjectCELL* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL* GetCellByIndex(unsigned int);
    TESObjectCELL* GetCellByNumericID(unsigned int);
    TESObjectCELL* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL*);
    void RemoveCell(TESObjectCELL*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    bool FormIDExists(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};
typedef char _sizecheck_TESDataHandler[sizeof(TESDataHandler) == 1596 ? 1 : -1];
struct FUN_004516b0_shell : public TESDataHandler
{
    bool FUN_004516b0();
};
struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_004523c0_shell : public BGSSaveLoadGame
{
    bool FUN_004523c0();
};
int __fastcall GetByteAtOffset38(void*);
struct FUN_00452420_shell
{
    unsigned int pad0;   // +0x00
    unsigned int pad1;   // +0x04
    unsigned int pad2;   // +0x08
    unsigned int pad3;   // +0x0C
    unsigned int flags;  // +0x10
    bool GetFlag(unsigned int aiFlags) const;
};
struct FUN_00452440_shell
{
    bool __thiscall FUN_00452440();
};
struct FUN_004e32c0_shell
{
    bool __thiscall HasFlags(int arg);
};
struct PlaceableWaterData
{
    unsigned int flags;
};
struct BGSPlaceableWater
{
    PlaceableWaterData* FUN_00624700();
    bool __thiscall HasFlags(unsigned int flags);
};
extern unsigned char DAT_0119b8c8;
unsigned char FUN_00452480();
int __fastcall FUN_009938b0(void*);
struct FUN_00453470_shell
{
    int __thiscall FUN_00453470(void);
};
struct FUN_004534f0_shell
{
    void __thiscall FUN_004534f0(unsigned int);
};
struct FUN_00453500_shell
{
    void FUN_00453500(bool set);
};
struct BSAudio;
BSAudio* DAT_011f6d98;
BSAudio* FUN_00453a70();
extern unsigned char DAT_011f9427;
void FUN_00454440(unsigned char value);
struct FNStub
{
    char const* GetFullName() const;
};
struct FUN_00454b50_shell
{
    char const* GetWaterNoiseTextureName() const;
};
struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList(void);
    bool FUN_00455620(void);
};
extern int DAT_011c56e8;
void FUN_00455680();
struct FUN_004565f0_shell
{
    float m_f;
    float GetFloat();
};
extern const void* const g_01202e00;
struct FUN_00458f20_shell
{
    const void* const* FUN_00458f20() const;
};
extern "C" void __fastcall FUN_00a5e930(void*);
extern int DAT_01017d24;
struct FUN_00458f70_shell
{
    void __thiscall FUN_00458f70();
};
struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectTREE;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void QueueModelLoad(char*, bool, unsigned int);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    NiNode* LoadFile(char*, int, bool, bool, bool, bool);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
typedef char _sizecheck_ModelLoader[sizeof(ModelLoader) == 48 ? 1 : -1];
struct FUN_0045a5e0_shell : public ModelLoader
{
    void FUN_0045a5e0(char*);
};
void __cdecl CreateCSDFadeNode(void);
void __cdecl CreateSpdFadeNode(void);
void __cdecl FUN_004f92e0(void);
void __cdecl FUN_00649e40(void);
void __cdecl FUN_0065c570(void);
void __cdecl FUN_00662760(void);
void __cdecl FUN_0045b020(void);
struct FUN_0045c650_shell
{
    void* FUN_0045c650();
};
struct Flt
{
    operator unsigned int(void) const;
};
extern Flt g_011deb7c;
unsigned int FUN_0045c670();
struct TESObjectREFR;
void FUN_00578060(TESObjectREFR* self);
void FUN_00578170(TESObjectREFR* self);
void FUN_0045c680(TESObjectREFR* arg, bool flag);
extern "C" double _gModifierZero;
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct NiCamera
{
    float x;
    float y;
    float z;
    float w;
    int __thiscall ClassifyPoint(const NiPoint3* other);
};
struct FUN_00451cd0_shell
{
    unsigned char FUN_00451cd0();
};
struct TESObjectCELL
{
    bool IsInterior(void);
};
struct TESObjectCELL_AddToInteriorBuffer
{
    void AddCellToInteriorBuffer(TESObjectCELL* cell);
};
struct TESObjectCELL_AddToExteriorBuffer
{
    void AddCellToExteriorBuffer(TESObjectCELL* cell);
};
struct FUN_00454b90_shell
{
    void AddCellToBuffer(TESObjectCELL* cell);
};
struct FUN_00458f30_shell
{
    void FUN_00458f70();
    void* DestroyIfFlagged(unsigned int flags);
};
void _delete(void* obj, unsigned int size);
struct FUN_00459840_shell
{
    void FUN_00458f90();
    void FUN_00459840(unsigned int a);
};
struct FUN_0045a730_shell
{
    char* FUN_0045a730();
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_0045ae20_shell
{
    void FUN_0045ae50();
    void* FUN_0045ae20(unsigned int flags);
};

struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93060
{
    bool GetAt(char const*, ShaderBufferRecord*&);
};
struct ShaderBufferRecord
{
    char pad[0x30];
    NiTStringPointerMap_00e93060 map;
};
struct TallGrassShaderProperty
{
    static NiTStringPointerMap_00e93060* __cdecl GetCacheDataMap();
};
// @fnv 0x00b617b0
bool __cdecl FUN_00b617b0(char const* a, char const* b)
{
    ShaderBufferRecord* pn = 0;
    if (!TallGrassShaderProperty::GetCacheDataMap()->GetAt(a, pn))
        return false;
    return pn->map.GetAt(b, pn);
}

// Release one update lock; when the last lock goes away, process (a budgeted part of) the pending queue
// or flush it, then run the post-update steps.

class C6B540Item;

extern bool g_bC6B540Processing;
extern unsigned int g_uiC6B540MaxPerFrame;

class C6B540Manager
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiLockCount;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    C6B540Item** m_ppkPending;
    unsigned int m_uiPendingCount;

    void ProcessPending(C6B540Item** ppkItems, unsigned int ItemUpdateArray);
    void FlushPending();
    void UpdateA();
    void UpdateB();
    void UpdateC();
    void FUN_00c6b540(bool bProcess);
};

// @fnv 0x00c6b540
void C6B540Manager::FUN_00c6b540(bool bProcess)
{
    if (m_uiLockCount > 0)
    {
        if (--m_uiLockCount == 0)
        {
            if (bProcess)
            {
                if (m_uiPendingCount > 0 && !g_bC6B540Processing)
                {
                    if (m_uiPendingCount >= 3000)
                        m_uiPendingCount = 3000;
                    unsigned int ItemUpdateArray =
                        m_uiPendingCount < g_uiC6B540MaxPerFrame ? m_uiPendingCount : g_uiC6B540MaxPerFrame;
                    unsigned int uiRemaining = m_uiPendingCount - ItemUpdateArray;
                    ProcessPending(&m_ppkPending[uiRemaining], ItemUpdateArray);
                    m_uiPendingCount = uiRemaining;
                    g_bC6B540Processing = true;
                }
            }
            else
            {
                FlushPending();
            }
            UpdateA();
            UpdateB();
            UpdateC();
        }
    }
    else if (m_uiPendingCount > 0 && !bProcess)
    {
        FlushPending();
    }
}

struct QueryStub
{
    unsigned char FUN_00c4edf0(unsigned int* state, int flags);
};

void __fastcall FUN_00c4ed40(void* p);

struct MemoryManager
{
    void Deallocate(void* p);
};

extern MemoryManager DAT_011f6238;

struct SlotEntry
{
    void* item;
    unsigned char flag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    int unk10;
};

struct HolderNode
{
    int unk00;
    int unk04;
    void* holder;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* item;
};

inline void* const& NextHolder(HolderNode*& pos)
{
    void* const& element = pos->holder;
    pos = (HolderNode*)pos->unk00;
    return element;
}

struct FUN_00b631d0_cls
{
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned char m_flag40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    SlotEntry m_entries[3];
    int unk84;
    unsigned short m_88;
    unsigned short m_uiItemCount;
    void** m_ppData;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    void* m_kNode;
    int unk144;
    int m_listCount;
    void FUN_00b631d0();
};

// @fnv 0x00b631d0
void FUN_00b631d0_cls::FUN_00b631d0()
{
    unsigned int state;
    int i = 0;
    while (i < m_uiItemCount)
    {
        if (m_ppData[i] != 0)
        {
            ((QueryStub*)m_ppData[i])->FUN_00c4edf0(&state, 1);

            void* item = m_ppData[i];
            if (item != 0)
            {
                FUN_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }

            m_ppData[i] = 0;
        }
        ++i;
    }

    SlotEntry* entry = m_entries;
    int remaining = 3;
    do
    {
        if (entry->item != 0)
        {
            ((QueryStub*)entry->item)->FUN_00c4edf0(&state, 1);
            void* item = entry->item;
            if (item != 0)
            {
                FUN_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }
            entry->item = 0;
            entry->flag = 0;
        }
        ++entry;
        --remaining;
    } while (remaining != 0);

    m_flag40 = 0;
    HolderNode* node = (HolderNode*)m_kNode;
    while (m_listCount != 0)
    {
        Holder* holder = (Holder*)NextHolder(node);
        if (holder != 0 && holder->item != 0)
        {
            ((QueryStub*)holder->item)->FUN_00c4edf0(&state, 1);
            void* item = holder->item;
            if (item != 0)
            {
                FUN_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }
            holder->item = 0;
        }
    }

    void** array = m_ppData;
    m_88 = 0;
    m_uiItemCount = 0;
    DAT_011f6238.Deallocate(array);
    m_ppData = 0;
}

struct Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int type;
};
struct Ref
{
    Item* ptr;
    Ref(Item*);
    ~Ref();
};
struct List
{
    int head;
    int tail;
    int count;
    void FUN_00c1b4a0(const Ref&);
    Ref FUN_00b9fcc0(const Ref&);
};
struct Node
{
    Node* next;
    Node* prev;
    Item** data;
};
struct S00b6da10_Other
{
    __declspec(noalias) void* FUN_00b58570(Item** const&);
};
struct Pending
{
    Node* head;
    Node* tail;
    int count;
    __declspec(noalias) void FUN_00e7d7f0(Node* const&);
    __forceinline void Find(Item* item, Node*& pos, Item**& found)
    {
        while (pos)
        {
            if (found)
                return;
            if (*pos->data == item)
                found = pos->data;
            else
                pos = pos->next;
        }
    }
};
struct Manager
{
    List list0;
    List list1;
    List list2;
    List list3;
    List list4;
    List dest0;
    List dest1;
    List dest2;
    List dest3;
    List dest4;
    S00b6da10_Other other;
    int o4;
    int o8;
    Pending pending;
    void FUN_00b6da10(Item* item);
    template <int N> static __forceinline void ProcT(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            l.FUN_00c1b4a0(tmp);
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
    __forceinline void Purge(Item* item, Node* pos, Item** found)
    {
        pending.Find(item, pos, found);
        if (found)
        {
            other.FUN_00b58570(found);
            pending.FUN_00e7d7f0(pos);
        }
    }
    static __forceinline void Proc(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            l.FUN_00c1b4a0(tmp);
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
};
// @fnv 0x00b6da10
void Manager::FUN_00b6da10(Item* item)
{
    if (item)
    {
        if (item->type > -1)
        {
            switch (item->type)
            {
            case 43: {
                {
                    Ref tmp(item);
                    list0.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest0.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 17: {
                {
                    Ref tmp(item);
                    list1.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest1.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 9: {
                {
                    Ref tmp(item);
                    list2.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest2.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 22: {
                {
                    Ref tmp(item);
                    list3.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest3.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 19: {
                {
                    Ref tmp(item);
                    list4.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest4.FUN_00b9fcc0(tmp);
                }
                break;
            }
            }
        }
        else
        {
            Item** found = 0;
            Node* pos = pending.head;
            pending.Find(item, pos, found);
            if (found)
            {
                other.FUN_00b58570(found);
                pending.FUN_00e7d7f0(pos);
            }
        }
    }
}

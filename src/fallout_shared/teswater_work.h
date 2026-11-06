// fallout_shared/teswater_work.h: declares NiPoint3, NiPoint2, LoadedAreaBound, BGSSaveLoadGame, SettingT_GameSettingCollection_ and more
#ifndef FNV_TESWATER_WORK_H
#define FNV_TESWATER_WORK_H

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    void ComputeMagnitude();
    static const NiPoint3 ZERO;
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2(float, float);
    bool FUN_00452df0(const NiPoint2&) const;
};
class TESObjectCELL;
class TESWorldSpace;
class TESObjectREFR;
class TESWaterForm;
class NiNode;
class GridCell;
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList<T>* next;
    void RemoveAll();
    T& GetItem();
};
class LoadedAreaBound
{
  public:
    void FUN_00628da0();
    void FUN_006271b0(TESObjectCELL*, void*);
};
class BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
    bool IsFlag20Set();
};
union SETTING_VALUE
{
    bool b;
    unsigned int ui;
    int i;
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class TESDataHandler
{
  public:
    BSSimpleList<TESWorldSpace*>* GetSourceFiles();
};
class bhkWorld
{
  public:
    void FUN_00c6b540(bool);
    void SetWorldActive(bool);
    void FUN_00c66310();
    void RefreshWorld();
    void FUN_00c66300();
    char _pdbpad_1[15];
    void* pDebugger;
    bool bStateChanged;
    bool bEnabled;
    bool m_bFlagAt16;
    char _pdbpad_17[1];
    unsigned int m_uiValueAt18;
    unsigned int m_uiReferenceCount;
    void* pTrapListener;
    void* m_pObjectAt24;
    void* m_pObjectAt28;
    void* m_pObjectAt2C;
    unsigned int m_uiValueAt30;
    void* m_pObjectAt34;
    unsigned int m_uiValueAt38;
    void* m_pObjectAt3C;
    unsigned int m_uiValueAt40;
    void* m_pObjectAt44;
    unsigned int m_uiValueAt48;
    void* m_pObjectAt4C;
    unsigned int m_uiValueAt50;
    char _pdbpad_54[12];
    char Origin[16];
    char m_achDataAt70[12];
    char m_achDataAt7C[12];
    float m_fValueAt88;
    float m_fValueAt8C;
    char ActionEntryList[8];
    char _pdbpad_98[8];
};
class TESObjectCELL
{
  public:
    static bhkWorld* GetExteriorbhkWorld();
    TESWaterForm* GetAssociatedWaterForm();
};
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
class GridCellArray
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void SetGridPosition(int, int);
};
class PlayerCharacter
{
  public:
    virtual void vfn_0();
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
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual const NiPoint3& GetPos();
};
class TES
{
  public:
    void** m_ppVirtualMethodTable;
    void* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    void* m_pLandRootNode;
    void* m_pWaterRootNode;
    void* m_pDistantLandRootNode;
    void* m_pObjectRootNode;
    void* m_pDirectionalLight;
    void* m_pFogProperty;
    int iFirstValue, iSecondValue;
    int m_iGridWidth, m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    char layoutPadding38[0x80 - 0x38];
    float m_fFirstWorldspaceValue, m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char layoutPadding8c[0xc0 - 0x8c];
    NiPointer<LoadedAreaBound> m_spLoadedAreaBound;
    int FindCellAtPosition(const NiPoint3*, bool);
    BSSimpleList<TESObjectCELL*>* FUN_0045bb80();
    void InitFromMatrix();
    void InitSoundGrid();
    TESObjectCELL* IsCellInterior();
    TESObjectCELL* GetDetailedActorPathHandler();
    void RefreshWorldState(int, int, int);
    void InitGridCells(const NiPoint3*, bool);
    unsigned int GetInteriorBufferCount(bool);
    void SetTESActive(bool);
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    TESWorldSpace* GetParentWorldSpace();
    void FUN_004581e0(const char*);
    void AssignWorldSpace(TESWorldSpace*);
    bool IsCellBuffering();
    void SetSkyMode(int);
    void RefreshGrid();
    void FUN_00452e50();
    static void RefreshWorldSpace();
};
class TESQueuedCellManager
{
  public:
    void FUN_005283c0(TESObjectCELL*);
    int CallVirtual17();
    void ProcessQueries();
    int FUN_005281f0();
    void FUN_005282d0();
};
class Interface
{
  public:
    static bool IsGamePaused();
};
int TruncateFloatToInt(float);
int FUN_00ec7d40(int);
void FUN_00452e40(bool);
float FUN_00452e70(bool);
extern bool DAT_011c3c0c, DAT_011f94aa;
extern float DAT_011f94ac;
extern NiPoint2 DAT_011f962c, DAT_011f9634, DAT_011f4980;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESDataHandler* g_dataHandler;
extern PlayerCharacter* g_thePlayer;
extern SettingT<INISettingCollection> DAT_011c9670, DAT_011c3d40;
extern SettingT_GameSettingCollection_ DAT_011c63cc;
extern TESQueuedCellManager* DAT_011c9618;

class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
    NiPoint3 operator*(const NiPoint3&) const;
};
class NiNode
{
  public:
    const ThreeByThreeMatrix& FUN_00461130() const;
    const NiPoint3& FUN_0045bb80() const;
};
class TESBoundObject
{
  public:
    virtual void vfn_0();
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
    virtual TESWaterForm* GetAssociatedWaterForm();
};
class TESObjectREFR
{
  public:
    virtual void vfn_0();
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
    TESBoundObject* GetObjectReference();
    TESObjectCELL* GetParentCell();
};
class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    NiPlane(const NiPoint3&, const NiPoint3&);
    const NiPoint3& GetPlaneNormal() const;
    float FUN_0084d030() const;
};
template <class T> class NiTPointerList
{
  public:
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const;
    void* DereferenceIfNotNull(void*) const;
    T& AddEight(void*) const;
};
template <class T> class NiTObjectList : public NiTPointerList<T>
{
};
class WaterSurface
{
  public:
    TESWaterForm* m_pOwningWater;
    NiPlane m_kWaterPlane;
    NiPlane m_kSecondaryPlane;
    NiTObjectList<TESObjectREFR*> m_kWaterReferences;
};
class WaterZoneManager
{
  public:
    char layoutPadding00[0x3c];
    NiTPointerList<WaterSurface*> m_kWaterZoneList;
    WaterSurface* GetWaterZone(TESObjectREFR*, TESObjectREFR*, float);
    void UpdateWaterZone(TESObjectREFR*, TESObjectREFR*, float);
    void RemoveReferenceFromCell(TESObjectREFR*, WaterSurface*);
};
bool AreVectorsEqual(const NiPoint3&, const NiPoint3&, float);
bool IsApproximatelyEqual(float, float, float);
#endif

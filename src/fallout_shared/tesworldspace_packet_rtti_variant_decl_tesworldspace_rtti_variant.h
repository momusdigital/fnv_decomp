#ifndef TESWORLDSPACE_PACKET_H
#define TESWORLDSPACE_PACKET_H

class TESWorldSpace;
class BGSTerrainManager;
class TESFile;
class TESObjectREFR;
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    virtual void F01();
    virtual void F02();
    virtual void F03();
    virtual void F04();
    virtual void F05();
    virtual void F06();
    virtual void F07();
    virtual void F08();
    virtual void F09();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void F14();
    virtual void F15();
    virtual TESForm* CloneForm(bool temporary, TESFile* file);
    virtual void F17();
    virtual void F18();
    virtual void F19();
    virtual void F20();
    virtual void F21();
    virtual void F22();
    virtual void F23();
    virtual void F24();
    virtual void F25();
    virtual void F26();
    virtual void F27();
    virtual void F28();
    virtual void F29();
    virtual void F30();
    virtual void F31();
    virtual void F32();
    virtual void F33();
    virtual void F34();
    virtual void F35();
    virtual void F36();
    virtual void F37();
    virtual void F38();
    virtual void F39();
    virtual void F40();
    virtual void F41();
    virtual void F42();
    virtual void F43();
    virtual void F44();
    virtual void F45();
    virtual void F46();
    virtual void F47();
    virtual void F48();
    virtual void F49();
    virtual void SetAltered(bool altered);

  public:
    bool IsTemporary() const;
    bool IsConstantGlobal();
};
class TESObjectREFR : public TESForm
{
};
template <class T, int N> class BSSimpleArray
{
  public:
    char data[16];
};
class TESObjectCELL : public TESForm
{
  public:
    virtual ~TESObjectCELL();  // the original class is polymorphic (rtti_variants.py)
  public:
    char pad[32];
    unsigned char flags;
    bool IsCellInterior() const;
    void AddReference(TESObjectREFR*, bool);
    void AppendCellReferences(BSSimpleArray<TESObjectREFR*, 1024>&);
};
template <class T> class BSStringT
{
  public:
    bool Set(const T*, unsigned int);
};
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
class TESFile
{
  public:
    TESFile* GetThreadSafeRootFile();
};
class TESRegion : public TESForm
{
  public:
    char pad[0x20];
    TESWorldSpace* world;
    void AssignWorldSpace(TESWorldSpace*);
};
class TESDataHandler
{
  public:
    bool LoadDescriptionForForm();
};
extern TESDataHandler* g_dataHandler;
extern NiTPointerMap<unsigned int, TESObjectREFR*>* DAT_011c40b0;
class TESWorldSpace
{
  public:
    virtual ~TESWorldSpace();  // the original class is polymorphic (rtti_variants.py)
  public:
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    char pad0[0x2c];
    NiTPointerMap<unsigned int, TESObjectREFR*>* cellMap;
    TESObjectCELL* m_pCell;
    char pad38[4];
    BGSTerrainManager* terrain;
    char pad40[0xC];
    unsigned char flags4C;
    char pad4D[1];
    unsigned short field4E;
    char pad50[0x20];
    TESWorldSpace* parent;
    char pad74[0x4c];
    BSStringT<char> mapName;
    char padC1[7];
    float fC8;
    float fCC;
    unsigned int fieldD0;
    bool SetDateTimeText(const char*);
    BGSTerrainManager* GetWorldTerrainManager();
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG);
    bool GetParentUseFlag(PARENT_USE_FLAG);
    TESObjectCELL* GetCellByKey(unsigned int);
    void AddPersistentReference(TESObjectREFR*);
    TESObjectCELL* CreatePersistentCell();
    void SetHasRegions(bool);
    static bool IsFormIDOwnedByFile(unsigned int, TESFile*);
    void ClearWorldSpaceReferences();
    TESObjectCELL* GetCellAtGridPosition(int, int);
    static int BuildCellKey(short, short);
    void FUN_00584150(float);
    void FUN_00586110(float);
    void FUN_00586130(float);
    bool GetSmallWorld();
    bool IsFlag4C20Set();
    void SetParent(TESWorldSpace*);
    void SetFieldD0(unsigned int);
    TESObjectCELL* GetInteriorCell();
    void AppendInteriorCellReferences(BSSimpleArray<TESObjectREFR*, 1024>&);
};
class Tile;
class InterfaceManager
{
  public:
    char pad[0x9C];
    Tile* pTile;
    Tile* FUN_00586150();
};
#endif
class TESSound;
class TESQuest;
class TESEffectShader;
class BGSAcousticSpace
{
  public:
    void SetNightSound(TESSound*);
};
class TESObjectACTI
{
  public:
    void SetLoopingSound(TESSound*);
};
class EffectSetting
{
  public:
    void SetEffectShader(TESEffectShader*);
};
class TESFullName
{
  public:
    void SetFullName(const char*);
};
extern "C" void* memset(void*, int, unsigned int);
extern float DAT_01031920;
extern const char DAT_010187a0[];
int Warning(const char*, ...);

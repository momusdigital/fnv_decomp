// Fallout shared perk entry declarations, reconstructed to the PC release layout.
#ifndef FNV_FALL_SHARED_BGSPERK_WORKER_H
#define FNV_FALL_SHARED_BGSPERK_WORKER_H


#include <stddef.h>

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);

class PerkEntryPointData
{
  public:
    unsigned char m_ucEntryPoint;
    unsigned char m_ucFunction;
    unsigned char m_ucConditionCount;
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    bool IsInList(T& item);
    void Insert(T item, int(__cdecl* compare)(T, T));
    void RemoveAll();
    void RemoveHead();
    void Remove(const T& item);
    void AddTail(const T& item);
    void AddHead(T& item);
    void SetItem(const T& item);
};

class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* name, class TESFile* file);
};

class Actor;
class BGSPerkEntry;
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* data);
    bool GetChunkData();
    bool NextChunk();
};
enum ENUM_FORM_ID
{
    kPerk = 0x56
};
class TESForm
{
  public:
    TESForm();
    virtual ~TESForm();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool Load(TESFile* file);
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
    virtual void InitItem();
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
    virtual void readOBNDSubRecord(TESFile* file);
    virtual bool IsActor_InEditor();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual bool GetIsReference() const;
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
    virtual const char* GetName() const;
    virtual bool SetEditorID(const char* id);
    static TESForm* GetFormByID(unsigned int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    TESFile* GetFile(int);
    unsigned int GetFormID();
    void NotifySaveLoadGameOfFormChange();
    void LoadRecordHeader(TESFile* file);
    void SetInitializationState(bool initialized);
    bool GetInitialized() const;
    void SetFormType(ENUM_FORM_ID type);
    unsigned char layoutData[0x14];
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

class PerkEntryFunctionType
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual int GetFunctionType();
};

class RegionDataEntry
{
  public:
    void Endian();
};

class PerkEntryConditionSet
{
  public:
    void* pFirstCondition;
    void* pNextCondition;
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitItem(TESForm* form);
    void Load(TESFile* file);
    bool ContainsTrait(class TESObjectREFR*, class TESObjectREFR*, bool&, bool);
};

class TESFullName
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[8];
    TESFullName();
    ~TESFullName();
};

class TESDescription
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[4];
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};

class TESTexture
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[8];
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

class PerkData
{
  public:
    bool m_bTrait;
    unsigned char cLevel;
    unsigned char m_ucRankCount;
    bool bPlayable;
    bool bHidden;
    unsigned char padding[3];
};

class BGSPerk : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
  public:
    PerkData Data;
    PerkEntryConditionSet m_kConditions;
    BSSimpleList<BGSPerkEntry*> m_kEntryList;
    BGSPerk();
    void ResetFormData();
    bool AppendPerkEntry(BGSPerkEntry* entry);
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void ApplyPerkEntries(Actor* actor, unsigned char rank, bool alternate);
};

class BGSEntryPointFunctionData
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};

class BGSPerkEntry
{
  public:
    void LoadFromSaveData(const void* data);
    unsigned char m_ucRank;               // +0x4
    unsigned char m_ucRegionPriority;  // +0x5
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void InitItem(TESForm* form);
    virtual void Save();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual bool Load(TESFile* file);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void Copy(BGSPerkEntry* entry);
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void ClearData();
    virtual ~BGSPerkEntry();
};

class BGSEntryPointPerkEntry : public BGSPerkEntry
{
  public:
    PerkEntryPointData Data;  // +0x8
    unsigned char layoutPaddingB[1];
    BGSEntryPointFunctionData* m_pFunctionData;  // +0xC
    PerkEntryConditionSet* m_pConditions;                 // +0x10
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void ClearData();
    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual unsigned char GetEntryPoint();
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);
    BGSEntryPointPerkEntry& operator=(const BGSEntryPointPerkEntry& entry);
};

class BGSQuestPerkEntry : public BGSPerkEntry
{
  public:
    struct
    {
        class TESQuest* pQuest;
        unsigned char stage;
        unsigned char padding[3];
    } Data;
    virtual bool Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};

#ifndef __GNUC__
FNV_STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x8);
FNV_STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, Data) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pFunctionData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pConditions) == 0x10);
#endif

#endif

BGSPerkEntry* CreatePerkEntry(unsigned char type);

void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
BGSEntryPointFunctionData* FUN_005e6280(unsigned char);
int Warning(const char*, ...);

class TESBoundObject : public TESForm
{
};
class TESObjectREFR : public TESForm
{
  public:
    TESObjectREFR();
    virtual ~TESObjectREFR();
    unsigned char referenceData[0x50];
    void ClearReferenceState(TESBoundObject*);
};
FNV_STATIC_ASSERT(sizeof(TESObjectREFR) == 0x68);

class TESQuest : public TESForm
{
};
class SpellItem : public TESForm
{
};
class BGSAbilityPerkEntry : public BGSPerkEntry
{
  public:
    SpellItem* m_pSpell;
    BGSAbilityPerkEntry* Initialize();
    virtual void InitItem(TESForm* form);
    virtual bool Load(TESFile* file);
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};

template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);

FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0x0c);
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x08);
FNV_STATIC_ASSERT(sizeof(TESIcon) == 0x0c);
FNV_STATIC_ASSERT(sizeof(BGSPerk) == 0x50);
FNV_STATIC_ASSERT(offsetof(BGSPerk, Data) == 0x38);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kConditions) == 0x40);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kEntryList) == 0x48);
FNV_STATIC_ASSERT(sizeof(BGSQuestPerkEntry) == 0x10);
FNV_STATIC_ASSERT(sizeof(BGSAbilityPerkEntry) == 0x0c);

class TESAIForm
{
  public:
    unsigned char FUN_004f6de0();
};
int ComparePerkEntries(BGSPerkEntry*, BGSPerkEntry*);

class BGSIdleMarker
{
  public:
    void FUN_005e9530();
};
extern unsigned int BGSAbilityPerkEntry_vtable[];
class TESConditionItem
{
  public:
    unsigned char data[8];
    unsigned short function;
    unsigned int GetConditionFunctionID();
};

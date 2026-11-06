// fallout_shared/tesqueststage_decls.h: declares TESFile, RegionDataEntry, TESForm, TESQuest, TESObjectREFR and more
#ifndef FNV_TESQUESTSTAGE_PRIVATE_DECLS_H
#define FNV_TESQUESTSTAGE_PRIVATE_DECLS_H


class TESForm;
class QuestStage;
class TESFile;
class TESQuest;
class PerkEntryConditionSet;
class TESObjectREFR;
class PlayerQuestData;
class Date;
class Script;
class ScriptContext;
class PackageList;
class ScriptVariableInfo;
class ScriptHeaderData;
class ScriptReferencedObject;

template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void AddTail(T& item);
};

class QuestStage
{
  public:
    ~QuestStage();
    unsigned char GetIndex();
    void MarkDone(bool done);
    bool FUN_0060fd70();
    bool IsFlag2Set();
    Script* GetOffsetC();
    unsigned char m_done;
    unsigned char layoutPadding1[11];
    unsigned int m_uiEdgeIndex;
    unsigned char layoutPadding10[0x65 - 0x10];
    unsigned char m_bCompleteObjective;
    unsigned char layoutPadding66[2];
    Date* m_pCompletionDate;
    TESQuest* m_pSharedOwner;
};

class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* data);
    bool IsEndianConversionRequired();
    bool NextChunk();
    unsigned int GetOffset();
};

class RegionDataEntry
{
  public:
    unsigned int m_ucClipIdentifier;
    unsigned int m_bCompleted;
    void Endian();
};

class RegionObjectEntry
{
  public:
    void Load(TESFile* file);
    unsigned char m_done;
    unsigned char layoutPadding1[11];
    unsigned int m_uiEdgeIndex;
};

class TESForm
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
    virtual const char* GetEditorID();
    TESFile* GetFile(int index);
    const char* GetDescription();
    static void RemapFormIDForFile(unsigned int& id, TESFile* file);
    static TESForm* GetFormByID(unsigned int id);
};

class TESQuest : public TESForm
{
  public:
    BSSimpleList<QuestStage*>* GetStageList();
    QuestStage* GetStage(unsigned char index);
    bool GetAllowRepeatStages();
    void MarkCompleted(bool completed);
    void SetQuestCompleted(bool failed);
};

class TESObjectREFR
{
};

class PerkEntryConditionSet
{
  public:
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    void InitItem(TESForm* form);
};

class PlayerCharacter : public TESObjectREFR
{
  public:
    bool CompleteQuestObjective(PlayerQuestData* item);
    TESQuest* FUN_005cbb50();
    void FUN_009529d0(int value);
    ScriptContext* FUN_005d43c0(bool first, bool second);
};

class ScriptContext
{
  public:
    void* FUN_00418830();
};

class PackageList
{
  public:
    unsigned char layoutPadding0[8];
    void* packages;
    unsigned char layoutPadding12[4];
    unsigned char m_ucPackageFlag;
};

class TESAIForm
{
  public:
    PackageList* GetPackageList();
};

class Script : public TESAIForm
{
  public:
    void InitItem(TESForm* form);
    ScriptHeaderData* GetHeader();
    BSSimpleList<ScriptVariableInfo*>* GetVariableList();
    BSSimpleList<ScriptReferencedObject*>* GetReferencedObjectList();
    void SetScriptData(unsigned int size, char* data);
    bool Run(TESObjectREFR* subject, void* args);
};

class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
    bool Load(TESFile* file);
    void InitItem(TESForm* form, QuestStage* stage);
    Script* GetOffsetC();
    void SetNextQuest(TESQuest* quest);
    unsigned char m_type;
    unsigned char layoutPadding1[11];
    Script m_pScript;
    unsigned char layoutPadding0d[0x60 - 0x0d];
    unsigned int m_formID;
    unsigned char layoutPadding64[8];
    TESQuest* m_pSharedOwner;
    unsigned int m_nameIndex;
};

template <class T> class BSStringT
{
  public:
    bool Set(const char* text, unsigned int length);
    unsigned char data[8];
};

class ScriptVariableInfo
{
  public:
    ScriptVariableInfo();
    void Load(TESFile* file);
    unsigned char layoutPadding0[0x18];
    BSStringT<char> m_name;
};

class ScriptHeaderData
{
  public:
    void Endian();
};

class ScriptReferencedObject
{
  public:
    ScriptReferencedObject();
    unsigned char layoutPadding0[8];
    unsigned int m_iOwnerObjectOffset;
    unsigned int m_uiFilterValue;
};

enum CALENDAR_MONTH
{
    CALENDAR_MONTH_UNKNOWN
};

class Calendar
{
  public:
    unsigned int GetYear();
    CALENDAR_MONTH GetCurrentMonth();
    signed char GetGameHour();
};

class Date
{
  public:
    Date(short day, CALENDAR_MONTH month, unsigned int year);
    unsigned int value;
};

class MemoryManager
{
  public:
    static void* Allocate(unsigned int size);
};

extern Calendar g_calendar;
extern PlayerCharacter* g_thePlayer;
extern "C" ScriptVariableInfo* DAT_011cb8ec;

int __cdecl Warning();
unsigned int __cdecl SetWarningState(bool enabled);
void __cdecl BGSMessageWarningAuxiliary(int value);
extern "C" const char DAT_0104ae98[];
extern "C" const char DAT_0104ae54[];
#endif

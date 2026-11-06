#ifndef TESOBJECTCELL_PACKET_H
#define TESOBJECTCELL_PACKET_H

struct TESRecordHeader;
class TESFile
{
  public:
    char pad[0x240];
    TESRecordHeader* GetRecordHeader();
};
class PlayerMover
{
  public:
    char pad[0x94];
    unsigned int moveMode;
    unsigned int GetActorStateFlags();
};
union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class NiAVObject;
class NiNode
{
  public:
    NiAVObject* FUN_0043b4a0(int index);
};
class TESImageSpaceModifier;
template <class T> class BSSimpleList;
class TESDataHandler
{
  public:
    BSSimpleList<TESImageSpaceModifier*>* GetTESImageSpaceModifierList();
};
class BGSEncounterZone;
class TESWorldSpace
{
  public:
    virtual ~TESWorldSpace();  // the original class is polymorphic (rtti_variants.py)
  public:
    BGSEncounterZone* FindEncounterZone() const;
};
class TESForm;
class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // the original class is polymorphic (rtti_variants.py)
  public:
    static BGSEncounterZone* FindEncounterZone();
};
class DoorCell
{
  public:
    TESForm* GetOwner();
};
class TESSound
{
  public:
    char pad[0x45];
    unsigned char field45;
    unsigned char GetField45();
};
extern unsigned int DAT_011ca438;
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
};
class GlobalObject_00633c90 : public GarbageCollectorObjectPtr
{
};
extern GlobalObject_00633c90 g_011deda4;
struct InteriorCellData
{
    char pad[0x20];
    float clipDist;
};
class CellLightingTemplate
{
  public:
    float FUN_009a9350();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
};
class BGSPerkEntry;
class BGSLoadedReferenceCollection
{
  public:
    void FUN_00526f20(BGSPerkEntry* reference);
};
extern BGSLoadedReferenceCollection* DAT_011c95c8;
class ActorCause;
class BSExtraData;
class BaseExtraList
{
  public:
    char data[0x20];
    BSExtraData* GetExtraData(unsigned char type);
};
class ExtraDataList : public BaseExtraList
{
  public:
    void RemoveNonPersistentCellData();
    BGSEncounterZone* FindEncounterZone() const;
    TESForm* GetOwner();
};
class RecursiveSpinLock
{
  public:
    void Lock(const char* name);
};
class ExteriorCellData
{
  public:
    int x;
    int y;
};
class TESWorldSpace;
class TESObjectCELL
{
  public:
    bool SavesBefore(struct FormGroupQuery* group);
    bool IsFormTypeBelowThreshold(struct FormGroupQuery* group);
    unsigned int FUN_005441b0();
    unsigned int FUN_00544210();
    bool FUN_005516c0();  // declared for the original code (decl_variants.py)
  public:
    virtual ~TESObjectCELL();
    virtual void VirtualSlot01();
    virtual void VirtualSlot02();
    virtual void VirtualSlot03();
    virtual void VirtualSlot04();
    virtual void VirtualSlot05();
    virtual void VirtualSlot06();
    virtual void VirtualSlot07();
    virtual void VirtualSlot08();
    virtual void VirtualSlot09();
    virtual void VirtualSlot10();
    virtual void VirtualSlot11();
    virtual void VirtualSlot12();
    virtual void VirtualSlot13();
    virtual void VirtualSlot14();
    virtual bool MatchForm(void* form);  // the original class is polymorphic (rtti_variants.py)
  public:
    char padToExtraData[32];
    unsigned char field24;
    char padToExtraData2[3];
    ExtraDataList extraDataList;
    void* cellData;
    char padToRefListLock[0x34];
    RecursiveSpinLock refListLock;
    char padToWorldSpace[0x3f];
    TESWorldSpace* worldSpace;
    char padToUnknownDC[0x18];
    unsigned int unknownDC;
    char padToField210[0x130];
    unsigned char field210;
    char padToField619[0x408];
    unsigned char field619;
    char padToField760[0x146];
    void* field760;
    char padToAudioMarkers[0x70];
    BSSimpleList<ActorCause*> audioMarkers;
    unsigned int audioMarkerCount;
    unsigned char GetField24();
    unsigned char FUN_00552bb0();
    unsigned char FUN_00542d20();
    void* FUN_005454d0();
    void ClearAudioMarkers();
    ExteriorCellData* GetExteriorData();
    int GetCellGridX();
    int GetCellGridY();
    bool HasCellExtraData();
    bool IsCellInterior() const;
    TESWorldSpace* GetParentWorldSpace();
    void CellRefLockEnter();
    void ClearData();
    void SetLightingTemplate(void* value);
    int GetCellStandValue();
    InteriorCellData* GetInteriorData();
    bool FUN_00558b80(int mask);
    CellLightingTemplate* GetLightingTemplate();
    float GetInteriorLightValue();
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();
    void CellRefLockLeave();
    void ClearCellReferenceList();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    NiNode* FUN_00545cb0();
    BGSEncounterZone* FindEncounterZone() const;
};

#endif

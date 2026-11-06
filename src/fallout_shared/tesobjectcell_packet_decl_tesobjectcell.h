// fallout_shared/tesobjectcell_packet_decl_tesobjectcell.h: declares TESFile, PlayerMover, SettingT_GameSettingCollection_, NiNode, TESDataHandler and more
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
    BGSEncounterZone* FindEncounterZone() const;
};
class TESForm
{
  public:
    virtual void TESFormV00();
    bool FUN_00440da0();
    bool IsDeleted();
};
class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class TESObjectREFR : public TESForm
{
  public:
    static BGSEncounterZone* FindEncounterZone();
    virtual void R001();
    virtual void R002();
    virtual void R003();
    virtual void R004();
    virtual void R005();
    virtual void R006();
    virtual void R007();
    virtual void R008();
    virtual void R009();
    virtual void R010();
    virtual void R011();
    virtual void R012();
    virtual void R013();
    virtual void R014();
    virtual void R015();
    virtual void R016();
    virtual void R017();
    virtual void R018();
    virtual void R019();
    virtual void R020();
    virtual void R021();
    virtual void R022();
    virtual void R023();
    virtual void R024();
    virtual void R025();
    virtual void R026();
    virtual void R027();
    virtual void R028();
    virtual void R029();
    virtual void R030();
    virtual void R031();
    virtual void R032();
    virtual void R033();
    virtual void R034();
    virtual void R035();
    virtual void R036();
    virtual void R037();
    virtual void R038();
    virtual void R039();
    virtual void R040();
    virtual void R041();
    virtual void R042();
    virtual void R043();
    virtual void R044();
    virtual void R045();
    virtual void R046();
    virtual void R047();
    virtual void R048();
    virtual void R049();
    virtual void R050();
    virtual void R051();
    virtual void R052();
    virtual void R053();
    virtual void R054();
    virtual void R055();
    virtual void R056();
    virtual void R057();
    virtual void R058();
    virtual void R059();
    virtual void R060();
    virtual void R061();
    virtual void R062();
    virtual void R063();
    virtual void R064();
    virtual void R065();
    virtual void R066();
    virtual void R067();
    virtual void R068();
    virtual void R069();
    virtual void R070();
    virtual void R071();
    virtual void R072();
    virtual void R073();
    virtual void R074();
    virtual void R075();
    virtual void R076();
    virtual void R077();
    virtual void R078();
    virtual void R079();
    virtual void R080();
    virtual void R081();
    virtual void R082();
    virtual void R083();
    virtual void R084();
    virtual void R085();
    virtual void R086();
    virtual void R087();
    virtual void R088();
    virtual void R089();
    virtual void R090();
    virtual void R091();
    virtual void R092();
    virtual void R093();
    virtual void R094();
    virtual void R095();
    virtual void R096();
    virtual void R097();
    virtual void R098();
    virtual void R099();
    virtual void R100();
    virtual void R101();
    virtual void R102();
    virtual void R103();
    virtual void R104();
    virtual void R105();
    virtual void R106();
    virtual void R107();
    virtual void R108();
    virtual void R109();
    virtual void R110();
    virtual void R111();
    virtual void R112();
    virtual void R113();
    virtual void R114();
    virtual void Set3D(NiNode* node, bool queue);
    virtual NiNode* GetNiNode();
    TESForm* FUN_007af430();
    bool FUN_005651e0();
    bool FUN_0056b250();
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
    T& FUN_006815c0();
    BSSimpleList* FUN_00726070();
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
    void QueueReferences(bool active);  // declared for the original code (decl_variants.py)
  public:
    char padToExtraData[0x24];
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
    BSSimpleList<TESObjectREFR*>* FUN_009604f0();
    void CellRefLockLeave();
    void ClearCellReferenceList();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    NiNode* FUN_00545cb0();
    BGSEncounterZone* FindEncounterZone() const;
};

#endif

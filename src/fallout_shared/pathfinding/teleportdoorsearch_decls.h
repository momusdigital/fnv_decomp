// fallout_shared/pathfinding/teleportdoorsearch_decls.h: declares NiPoint3, PathingLocation, PointerPairData, TESWorldSpace, TESObjectCELL and more

class TopicInfoArray;
class TESBoundObject;
class SandboxProcedureData;
class TESIdleForm;
class TESObjectCELL;
class TESObjectREFR;
class PathingActorData;
class ParentSpaceNode;
class TeleportLink;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};
class PathingLocation
{
  public:
    char data[40];
    NiPoint3 FUN_005c3420() const;
};
struct PointerPairData
{
    void* a;
    void* b;
};
template <class T, int N> class BSSimpleArray
{
  public:
    char data[16];
    void Clear(bool);
    unsigned int GetSize();
    unsigned int Add(T&);
};
class TESWorldSpace
{
  public:
    PointerPairData* GetWorldSpaceData();
    void AppendInteriorCellReferences(BSSimpleArray<TESObjectREFR*, 1024>&);
};
class TESObjectCELL
{
  public:
    void AppendCellReferences(BSSimpleArray<TESObjectREFR*, 1024>&);
};
class ExtraRadioData
{
  public:
    TESObjectCELL* FUN_0043a2b0();
};
class ExtraLock
{
  public:
    int FUN_0043a320();
};
class QuestDialogueInfo
{
  public:
    TopicInfoArray* GetInfoArray();
};
class TESObjectDOOR
{
  public:
    bool IsTeleportDoor();
};
class TESForm
{
  public:
    virtual void vfn_0();
    bool GetDisabled();
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
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos();
    ExtraRadioData* GetExtraRadioData();
    TESBoundObject* GetObjectReference();
};
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
};
class DoorAccessData
{
  public:
    int data[6];
    DoorAccessData(TESObjectREFR*);
    ~DoorAccessData();
    bool CanUnlockDoor(const PathingActorData*, TESObjectREFR*, bool&);
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
template <class N, class L> class AStarNode
{
  public:
    float cost, fitness;
    bool exterior;
    TESWorldSpace* world;
    TESObjectCELL* cell;
    TESObjectREFR* door;
    NiPoint3 pos;
};
class TeleportDoorSearch
{
  public:
    char prefix[0x205c];
    TESWorldSpace* startWorld;
    int pad;
    PathingLocation location;
    bool exterior;
    TESWorldSpace* world;
    TESObjectCELL* cell;
    int restriction;
    float maxCost;
    const PathingActorData* lockData;
    BSSimpleArray<TESObjectREFR*, 1024> doors;
    int disposition;
    bool HasReachedGoal(const AStarNode<ParentSpaceNode, TeleportLink>*);
    bool CollectConnections(const AStarNode<ParentSpaceNode, TeleportLink>*,
                            BSSimpleArray<AStarNode<ParentSpaceNode, TeleportLink>*, 1024>*);
    int InsertOrUpdateNode(void*, float, AStarNode<ParentSpaceNode, TeleportLink>*&);
};

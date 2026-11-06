// fallout/ai/combat/combatstate_decls.h: declares InventoryChanges, CombatLocations, CombatLOS, CombatPrefix, CombatState
class TESObjectREFR;
class TESForm;
class InventoryChanges
{
  public:
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    int GetObjectCount(TESForm*);
};
class CombatLocations
{
  public:
    virtual void Clear();
};
class CombatLOS
{
  public:
    bool HasCachedValues();
    void FUN_008be220(CombatLocations*);
};
class CombatPrefix
{
  public:
    virtual void PrefixSlot();
    char pad04[0x64];
    CombatLOS* los;
    char pad6c[0x3c];
};
class CombatState : public CombatPrefix, public CombatLocations
{
  public:
    int GetInventoryItemCount(TESForm*);
    void ProcessCoverLOSResult();
    char padac[0xd0];
    float timer, offsetX, offsetY;
    void UpdateCombatStateData(int, float*, float*, float);
};

class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
float RandomFloat(float, float);
bool RandomBoolean(float);
extern GlobalObject_0044f440 DAT_011d57d0;
extern GlobalObject_0044f440 DAT_011d5944;
extern GlobalObject_0044f440 DAT_011d5750;
extern GlobalObject_0044f440 DAT_011d5968;
extern GlobalObject_0044f440 DAT_011d5874;
extern GlobalObject_0044f440 DAT_011d58e8;
extern GlobalObject_0044f440 DAT_011d5988;
extern GlobalObject_0044f440 DAT_011d5794;
extern GlobalObject_0044f440 DAT_011d57b8;
extern GlobalObject_0044f440 DAT_011d581c;
extern GlobalObject_0044f440 DAT_011d5894;
extern GlobalObject_0044f440 DAT_011d5930;
extern GlobalObject_0044f440 DAT_011d58d8;
extern GlobalObject_0044f440 DAT_011d5868;
extern GlobalObject_0044f440 DAT_011d5834;
extern GlobalObject_0044f440 DAT_011d58c4;
extern GlobalObject_0044f440 DAT_011d5908;
extern GlobalObject_0044f440 DAT_011d585c;
extern const float DAT_01017870;
extern const float DAT_01017718;
extern const float DAT_010162c0;
extern const float DAT_01016088;
extern const float DAT_01016248;
extern const float DAT_0101e570;

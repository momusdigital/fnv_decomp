// fallout_shared/tescombatstyle_decls.h: declares StatsChunkData, TESCombatStyle, NiAVObject, BGSHungerStage, CombatStyleAccess and more

#include "TESForm.h"
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct UnsignedIntArray16
{
    unsigned int data[16];
    void FUN_00505610();
};
struct StatsChunkData
{
    unsigned int data[23];
    void SwapEndianFields();
};
struct UInt32ChunkData
{
    unsigned int data[21];
    void FUN_005057a0();
};
class TESCombatStyle : public TESForm
{
  public:
    UnsignedIntArray16 m_kUnsignedIntArray16;
    StatsChunkData Data;
    UInt32ChunkData m_kUInt32ChunkData;
    TESCombatStyle();
    void ResetFormData();
    bool Load(TESFile*);
};
TESCombatStyle* GetDefaultCombatStyle();
struct NiPoint3;
class NiAVObject
{
  public:
    NiPoint3& FUN_0043c490();
};
class HungerStageData;
class BGSHungerStage
{
  public:
    HungerStageData* FUN_00500940();
};
class CombatStyleAccess
{
  public:
    UInt32ChunkData* FUN_006ab360();
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileExtra
{
  public:
    bool FUN_00401680();
};

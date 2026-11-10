// fallout_shared/tesclass_decls.h: declares FormChangeMask, BGSLoadFormBuffer, TESFullName, TESDescription, TESTexture and more

#include "tesclass_form_decls.h"
namespace ActorValue {
enum Index
{
    None = -1
};
bool IsSkill(Index);
}
class FormChangeMask
{
    unsigned int flags;

  public:
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int);
    void ReadTypedData(void*, unsigned int);
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> name;
};
class TESDescription : public BaseFormComponent
{
  public:
    unsigned int offset;
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> name;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char attrs[7];
    void FUN_00480130(unsigned char*);
};
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class LegacyActorBaseData
{
  public:
    ActorValue::Index skills[3];
    char flags;
    int services;
    unsigned char trainingSkill, trainingLevel;
    void OLD_CLASS_DATA_Endian();
};
class TESClassData
{
  public:
    ActorValue::Index skills[4];
    char flags;
    int services;
    unsigned char trainingSkill, trainingLevel;
    void SwapEndian();
};
class TESClass : public TESForm, public TESFullName, public TESDescription, public TESTexture, public TESAttributes
{
  public:
    TESClassData data;
    void SetTagSkill(int, ActorValue::Index);
    void ResetFormData();
    void LoadGame(BGSLoadFormBuffer*);
    bool Load(TESFile*);
    bool ValidateSkillActorValue();
};
extern "C" void* __cdecl memset(void*, int, unsigned int);

extern "C" void* __cdecl _alloca(unsigned int);
int __cdecl Warning(const char*, ...);
class TESFileFormInt
{
  public:
    int GetTESForm();
};

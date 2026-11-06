
// src/fallout_shared/tesobjectimod_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectimod.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectimod_decls.h"
class TESFormInitFlag : public TESObjectIMODVirtuals
{
  public:
    bool IsFormInitialized() const;
};
enum ENUM_FORM_ID
{
    kIMOD = 0x67
};
class TESForm : public TESFormInitFlag
{
  private:
    unsigned char fields[0x14];

  public:
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile*);
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class TESBoundObject : public TESForm
{
  private:
    unsigned char fields[0x18];

  public:
    TESBoundObject();
    ~TESBoundObject();
};
class TESFullName : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESFullName();
    ~TESFullName();
};
class TESModel : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x14];

  public:
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  private:
    unsigned char fields[0x08];

  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm* form);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
};
class TESTexture : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class TESScriptableForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESScriptableForm();
    void SetScript(Script*);
    void InitItem(TESForm* form);
};
class TESDescription : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESValueForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESValueForm();
    ~TESValueForm();
};
class TESWeightForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESWeightForm();
    ~TESWeightForm();
};
class BGSDestructibleObjectForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    BGSDestructibleObjectForm();
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm* form);
};
class BGSMessageIcon : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x0c];

  public:
    BGSMessageIcon();
    static void LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
    ~BGSMessageIcon();
};
class BGSPickupPutdownSounds : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    BGSPickupPutdownSounds();
    void SetPickupSound(TESSound*);
    void SetPutdownSound(TESSound*);
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};
class TESObjectIMOD : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectIMOD();
    bool Load(TESFile*);
    void InitItem();
};
struct FUN_0051a5d0_shell
{
    void __thiscall LoadGame2(unsigned int, unsigned int);
};
struct TESFormStub
{
    void __thiscall FUN_00484c50(unsigned int, unsigned int);
};
struct TESValueFormStub
{
    void __thiscall FUN_0048ea10(unsigned int, unsigned int);
};
struct BGSLoadFormBuffer;
struct FUN_0051a630_shell : public TESObjectIMOD
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct TESFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct TESValueFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct FUN_00519e40_shell : public TESObjectIMOD
{
    void* __thiscall FUN_00519e40(unsigned int flags);
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_00519e70_stub
{
    void __thiscall FUN_00519e70();
};
struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};
struct FUN_0048e9b0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};
struct FUN_0051a550_shell
{
    unsigned short __thiscall FUN_0051a550(unsigned int aiFlags);
};
struct FUN_0051b070_shell
{
    void __thiscall FUN_00484c20(unsigned int);
    void __thiscall FUN_0048e9e0(unsigned int);
};
struct FUN_0051a5a0_shell
{
    void __thiscall SaveGame(unsigned int aiFlags);
};
struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
    void __thiscall SaveIfChanged(BGSSaveFormBuffer*);
};
struct FUN_0048ea40_holder
{
    void __thiscall FUN_0048ea40(BGSSaveFormBuffer*);
};
struct FUN_0051a600_shell
{
    void __thiscall AppendSaveLoadFormBuffer(BGSSaveFormBuffer* buffer);
};
struct S_00477f20
{
    void __thiscall FUN_00477f20();
};
struct S_00487010
{
    void __thiscall FUN_00487010();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void __thiscall FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
};
struct FUN_004855a0
{
    void __thiscall M();
};
struct FUN_00485680
{
    void __thiscall M();
};
struct FUN_00485e00_shell
{
    void __thiscall FUN_00485e00();
};
struct FUN_0047a240_holder
{
    void __thiscall FUN_0047a240(unsigned int);
};
struct FUN_0047b560_holder
{
    void __thiscall LogFormIDs();
};
struct FUN_0048e370_holder
{
    void __thiscall FUN_0048e370(unsigned int);
};
struct FUN_0051a420_shell : public TESObjectIMOD
{
    void SaveForm();
};

struct B1
{
    virtual void FUN_0051a680(unsigned int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

struct B2
{
    virtual void FUN_0051a680(unsigned int);
};

struct Derived : B1, B2
{
    Derived();
// @fnv 0x0051a680
    virtual void FUN_0051a680(unsigned int);
};

Derived::Derived()
{}

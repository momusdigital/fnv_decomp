
// src/fallout_shared/tesobjectmisc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectmisc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectmisc_decls.h"
#include <malloc.h>
extern const char DAT_0102b038[];
TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);
struct FUN_0051b070_shell
{
    void FUN_00484c20(unsigned int aiFlags);
    void FUN_0048e9e0(unsigned int aiFlags);
    void SaveGame(unsigned int aiFlags);
};
struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int aiFlags);
};
struct FUN_0048e9b0
{
    unsigned short __thiscall GetSaveSize(unsigned int aiFlags);
};
struct FUN_0051b020_shell
{
    unsigned short __thiscall FUN_0051b020(unsigned int aiFlags);
};
struct TESFormStub
{
    void FUN_00484c50(unsigned int, unsigned int);
};
struct TESValueFormStub
{
    void FUN_0048ea10(unsigned int, unsigned int);
};
struct BGSLoadFormBuffer;
struct FUN_0051b0a0_shell
{
    void LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer);
};

// MSVC adjustor thunk: the primary base occupies 0x3c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0051b130();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct SecondaryBase
{
    virtual void FUN_0051b130();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0051b130
    virtual void FUN_0051b130();
};

Derived::Derived()
{}


// src/fallout_shared/bgsexplosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsexplosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsexplosion_types_BGSExplosion.h"
#include "bgsexplosion_decls.h"

// sub ecx,0x3c; jmp ScalarDeletingDestructor  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x3c)
struct PrimaryBase
{
    virtual void FUN_004fb9f0();
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
    virtual void FUN_004fb9f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fb9f0
    virtual void FUN_004fb9f0();
};

Derived::Derived()
{}


// src/fallout_shared/tesworldspace_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesworldspace_packet_rtti2_tesworldspace.h"

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
struct S00585250_WorldData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Different(S00585250_WorldData*);
    int unk04, unk08;
};
struct S00585250_WorldReference
{
    bool Different(S00585250_WorldReference*);
};
struct WorldCompareView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    S00585250_WorldReference* reference;
    unsigned char flags;
    unsigned char unk4D;
    unsigned short field4E;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    float fC8;
    float fCC;
    unsigned int unkD0;
    S00585250_WorldData dataD4;
    S00585250_WorldData dataE0;
    bool BaseDifferent(WorldCompareView*);
    void* Climate();
    void* ImageSpace();
    void* Water();
    void* LODWater();
    float Height();
    void* Map();
    bool Compare(TESForm*);
};
// @fnv 0x00585250
bool WorldCompareView::Compare(TESForm* form)
{
    WorldCompareView* other = (WorldCompareView*)dynamic_cast< ::TESWorldSpace*>(form);
    if (!other)
        return true;
    if (BaseDifferent(other))
        return true;
    if (flags != other->flags)
        return true;
    if (field4E != other->field4E)
        return true;
    if (unk70 != other->unk70)
        return true;
    if (unkD0 != other->unkD0)
        return true;
    if (Climate() != other->Climate())
        return true;
    if (ImageSpace() != other->ImageSpace())
        return true;
    if (reference && other->reference)
    {
        if (reference->Different(other->reference))
            return true;
    }
    else if (reference || other->reference)
        return true;
    if (Water() != other->Water())
        return true;
    if (LODWater() != other->LODWater())
        return true;
    if (Height() != other->Height())
        return true;
    if (fC8 != other->fC8 || fCC != other->fCC)
        return true;
    if (memcmp(&unk80, &other->unk80, 16))
        return true;
    if (memcmp(&unk90, &other->unk90, 12))
        return true;
    if (Map() != other->Map())
        return true;
    if (dataD4.Different(&other->dataD4))
        return true;
    if (dataE0.Different(&other->dataE0))
        return true;
    return false;
}

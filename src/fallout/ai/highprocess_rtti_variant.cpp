
// src/fallout/ai/highprocess_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (FleePackage, TESPackage). The skeleton of src/fallout/ai/highprocess.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "highprocess_decls_rtti_variant.h"

namespace PackagePathing {
struct Actor;
struct Request;
struct List;
struct Vec
{
    float x, y, z;
    Vec();
};
struct Cell
{
    bool FUN_00425fd0();
};
struct Setting
{
    float* FUN_00403e20();
};
struct Package
{
    virtual void PackageTypeAnchor();
    int FUN_0041ca90();
    void FUN_009f8660(List*);
    bool FUN_009f7fe0();
    Vec FUN_009f8300();
    void FUN_009f8020(Actor*);
    void FUN_009f7f20(Actor*, int);
    void FUN_009f7d70(Actor*, int);
    unsigned int FUN_004fb070();
    void SetWaterForm(unsigned int);
    float FUN_00507e10();
    int FUN_009f8570();
    void FUN_009f1310(void*);
};
struct List
{
    unsigned int unk0, unk4, unk8, unkc;
    List();
    ~List();
    int FUN_0044ddc0();
    void** FUN_006a7ad0(int);
};
struct Values
{
    virtual void slot0();
    virtual void slot4();
    virtual int Value(int);
};
struct Process
{
    bool GetPathCoordinate(Vec*);
};
struct Race
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual bool Flag();
};
struct Base
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    Race race;
};
struct Location
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Location(const Vec&, Actor*);
    ~Location();
};
struct Request
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Request();
    ~Request();
    void InitFromActor(Actor*);
    void SetCantOpenDoors(bool);
    void SetPathingLocation(const Location&);
    void FUN_008dbd80(float);
    void FUN_006d3b00(float);
    void FUN_006d61e0(int);
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual const Vec& Position();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual bool Alternate();
    virtual bool HasRace();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual Package* Current();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void SetPath(Actor*, int, int);
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void Start(void*, int, int, int, int, int, float, float);
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    Values values;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    Process* process;
    void EndInterruptPackage(int);
    ::TESPackage* FUN_009344a0();
    float FUN_00572380(const Vec&);
    Cell* FUN_008d6f30();
    bool FUN_008b3bb0();
    Base* FUN_004181e0();
    bool FUN_008bb630(Request*);
    bool FUN_00894d60();
    void FUN_00894cc0(int);
    void SetMoveMode(int);
    bool DidPathingFail();
    void FUN_008db810(Actor*);
};
struct System
{
    bool FUN_008d0300(Actor*, int);
};
extern System* DAT_011f1958;
extern Setting DAT_011cd814, DAT_011cddb8, DAT_011cd990, DAT_011cdfe4;
struct Timer
{
    unsigned int FUN_00825c00();
};
extern Timer DAT_011f6394;
extern float DAT_01012054, DAT_0101e6ec;
extern double DAT_0102e430, DAT_010240c0;

// @fnv 0x008db810
void Actor::FUN_008db810(Actor* actor)
{
    Package* current = Current();
    Package* package = 0;
    if (current && current->FUN_0041ca90() == 24)
        package = current;
    if (!package)
        return;
    if (DAT_011f1958->FUN_008d0300(actor, 0) || actor->values.Value(1) <= 0)
    {
        List targetsSlot0;
        package->FUN_009f8660(&targetsSlot0);
        int count = targetsSlot0.FUN_0044ddc0();
        if (count > 0)
        {
            actor->EndInterruptPackage(0);
            actor->Start(*targetsSlot0.FUN_006a7ad0(0), 1, 1, 1, 0, 0, DAT_01012054, DAT_01012054);
            ::FleePackage* following = dynamic_cast< ::FleePackage*>(actor->FUN_009344a0());
            if (following)
            {
                for (int index = 0; index < count; index++)
                    following->AddAvoidedReference(static_cast< ::Actor*>(*targetsSlot0.FUN_006a7ad0(index)));
            }
            return;
        }
    }
    if (package->FUN_009f7fe0())
    {
        actor->EndInterruptPackage(0);
        return;
    }
    float nearDistanceSlot10 = 0.0f;
    float farDistanceSlot35 = 0.0f;
    Vec unusedSlot11;
    int flagsSlot15 = 513;
    Vec pointSlot13 = package->FUN_009f8300();
    float distanceSlot14 = actor->FUN_00572380(pointSlot13);
    Cell* cell = actor->FUN_008d6f30();
    bool nearSlot19 = false;
    if (cell && cell->FUN_00425fd0())
    {
        nearDistanceSlot10 = *DAT_011cd814.FUN_00403e20();
        farDistanceSlot35 = *DAT_011cddb8.FUN_00403e20();
        if (distanceSlot14 < nearDistanceSlot10)
            nearSlot19 = true;
    }
    else
    {
        nearDistanceSlot10 = *DAT_011cd990.FUN_00403e20();
        farDistanceSlot35 = *DAT_011cdfe4.FUN_00403e20();
        if (distanceSlot14 < farDistanceSlot35)
            nearSlot19 = true;
    }
    package->FUN_009f8020(actor);
    if (actor->FUN_008b3bb0())
    {
        package->FUN_009f7f20(actor, 1);
        package->FUN_009f7d70(actor, 1);
        unsigned int time = DAT_011f6394.FUN_00825c00();
        if (time > package->FUN_004fb070() + 1500)
        {
            package->SetWaterForm(time);
            Vec oldSlot17Slot17 = actor->Position();
            Request requestSlot13;
            requestSlot13.InitFromActor(actor);
            if (actor->HasRace())
                requestSlot13.SetCantOpenDoors(actor->FUN_004181e0()->race.Flag());
            requestSlot13.SetPathingLocation(Location(package->FUN_009f8300(), actor));
            requestSlot13.FUN_008dbd80(package->FUN_00507e10() + DAT_0102e430);
            requestSlot13.FUN_006d3b00(DAT_0101e6ec);
            int mode = package->FUN_009f8570();
            requestSlot13.FUN_006d61e0(mode);
            if (!actor->FUN_008bb630(&requestSlot13))
                return;
            if (actor->FUN_00894d60())
                actor->FUN_00894cc0(0);
            actor->SetMoveMode(512);
            Vec targetSlot6Slot10;
            if (actor->process->GetPathCoordinate(&targetSlot6Slot10))
            {
                float targetDistanceSlot1 = actor->FUN_00572380(targetSlot6Slot10);
                if (targetDistanceSlot1 <= DAT_010240c0)
                    flagsSlot15 = 257;
                SetPath(actor, flagsSlot15, 1);
            }
        }
    }
    else if (actor->Alternate())
    {
        package->FUN_009f7f20(actor, 1);
        package->FUN_009f7d70(actor, 1);
    }
    if (actor->DidPathingFail())
        return;
    if (distanceSlot14 > farDistanceSlot35 * 2.0f)
    {
    }
}
}

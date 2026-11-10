// src/speedtree/branchinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branchinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00b3f310_Item
{
    int unk00;
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    S_00b3f310_Item();
};
extern float DAT_01017870;
extern float DAT_01018f5c;
extern float DAT_01017b78;
extern float DAT_01016248;
extern float DAT_0101622c;
extern float DAT_0101e2bc;

struct CBranchInfo
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    float unk20;
    float unk24;
    int unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    int unk50;
    S_00b3f310_Item* unk54;
    S_00b3f310_Item* unk58;
    int unk5c;
    S_00b3f310_Item* unk60;
    S_00b3f310_Item* unk64;
    S_00b3f310_Item* unk68;
    S_00b3f310_Item* unk6c;
    int unk70;
    CBranchInfo();
};

// Initialises the object's fields to default values and allocates six S_00b3f310_Item instances into the pointer fields.
// @fnv 0x00b3f310
// src: GUESS 0x00b3f310 (confidence: medium)
CBranchInfo::CBranchInfo()
{
    unk00 = 6;
    unk04 = 3;
    unk08 = DAT_01017870;
    unk0c = 1.0f;
    unk10 = DAT_01017870;
    unk14 = 1.0f;
    unk18 = 1.0f;
    unk1c = 1;
    unk1d = 0;
    unk1e = 0;
    unk20 = 0.0f;
    unk24 = 1.0f;
    unk28 = 0;
    unk2c = 1.0f;
    unk30 = DAT_01018f5c;
    unk34 = DAT_01017b78;
    unk38 = 1.0f;
    unk3c = DAT_01016248;
    unk40 = DAT_0101622c;
    unk44 = DAT_01017870;
    unk48 = DAT_0101e2bc;
    unk4c = 1.0f;
    unk50 = 0;
    unk54 = 0;
    unk58 = 0;
    unk5c = 0;
    unk60 = 0;
    unk64 = 0;
    unk68 = 0;
    unk6c = 0;
    unk70 = 0;
    unk58 = new S_00b3f310_Item;
    unk54 = new S_00b3f310_Item;
    unk64 = new S_00b3f310_Item;
    unk6c = new S_00b3f310_Item;
    unk68 = new S_00b3f310_Item;
    unk60 = new S_00b3f310_Item;
}

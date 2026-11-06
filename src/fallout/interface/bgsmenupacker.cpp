
// src/fallout/interface/bgsmenupacker.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/bgsmenupacker.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FNVVector
{
    float x;
    float y;
    float z;
};
struct FNVAccessor
{
    FNVVector* FUN_0043c490();
};
struct FNVNested;
struct FNVNestedProxy
{
    int FUN_00700300();
};
struct FNVNested
{
    FNVNestedProxy* FUN_0045cd60();
    int FUN_00700300();
    FNVAccessor* FUN_0056c7f0();
};
struct FNVEntry
{
    float value00;
    float value04;
    float value08;
    float value0c;
    float value10;
    float value14;
    FNVNested* member18;
};
extern const char UNK_0106e8ac[];
extern const char UNK_0106e87c[];
extern const char UNK_0106e84c[];
extern const char UNK_0106e820[];
extern const char UNK_0106e800[];
int __cdecl PrintToConsole(const char*, ...);
struct FNVCollection
{
    int GetShortAtOffsetA();
    FNVEntry** FUN_00877a30(int);
    void DumpInfo();
};
// @fnv 0x00700350
void FNVCollection::DumpInfo()
{
    PrintToConsole(UNK_0106e8ac);
    for (int index = 0; index < GetShortAtOffsetA(); ++index)
    {
        FNVEntry* entry = *FUN_00877a30(index);
        PrintToConsole(UNK_0106e87c, entry->member18->FUN_00700300(), entry->member18->FUN_0045cd60()->FUN_00700300());
        PrintToConsole(UNK_0106e84c, entry->value00, entry->value04, entry->value10, entry->value14);
        PrintToConsole(UNK_0106e820, entry->value08, entry->value0c, entry->member18->FUN_0056c7f0()->FUN_0043c490()->x,
                     entry->member18->FUN_0056c7f0()->FUN_0043c490()->z);
    }
    PrintToConsole(UNK_0106e800);
}

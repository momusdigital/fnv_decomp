// fallout_shared/magic/magicitemobject.cpp: MagicItemObject, MagicItemObjectShell (5 functions)

#include "magicitemobject_decls.h"
// @fnv 0x0040c9d0
void MagicItemObject::InitItem()
{
    if (GetInitialized())
        return;
    LoadEffectsFromForm(this);
    SetInitializationState(true);
}

#include <malloc.h>
// Reads a magic item record's chunks (editor ID, bounds, full name, effects), warns when the effect list is empty, and returns true.
// @fnv 0x0040c650
bool MagicItemObject::Load(TESFile* file)
{
    int chunk;
    LoadRecordHeader(file);
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editor, 512);
            SetEditorID_AtRuntime(editor);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x44494645:
        case 0x41445443:
            effectList.Load(file, GetFullName());
            break;
        }
        Unk_10(file, chunk);
        if (chunk == GetTypeSignature())
        {
            memset(Unk_0A(), 0, Unk_0B());
            file->GetChunkData(Unk_0A(), Unk_0B());
            if (file->GetChunkData())
                vfn_180();
        }
        if (!file->NextChunk())
            break;
    }
    if (!effectList.effects.ItemsInList())
        Warning("GAME EFFECTS: Effect Item (%08X) %s has no effects defined.", GetFormID(), GetFullName());
    return true;
}

struct FUN_004855a0
{
    void M(void);
};
struct FUN_00485680
{
    void M(void);
};
struct DoorPart30
{
    void FUN_00487010(void);
};
void __fastcall Save(void*);

struct FUN_0040c5f0_shell
{
    void SaveForm();
};

// Calls M on the object, invokes FUN_00487010 and two virtual methods at offsets 0x38/0x3c on the subobject at 0x30, then Save on this+0x3c and M again.
// @fnv 0x0040c5f0
void FUN_0040c5f0_shell::SaveForm()
{
    ((FUN_004855a0*)this)->M();
    ((DoorPart30*)((char*)this + 0x30))->FUN_00487010();
    (*(void(__thiscall**)(void*))(*(int*)((char*)this + 0x30) + 0x38))((char*)this + 0x30);
    (*(void(__thiscall**)(void*))(*(int*)((char*)this + 0x30) + 0x3c))((char*)this + 0x30);
    Save((char*)this + 0x3c);
    ((FUN_00485680*)this)->M();
}

struct MagicItemCompare
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual bool CompareMagic(MagicItem* other);
    char name[8];
};
struct EffectListCompare
{
    bool FUN_00405a00(EffectItemList* other);
};
struct MagicItemObjectShell : TESForm, MagicItemCompare
{
    EffectItemList effectList;
    bool FUN_00485270(TESForm* other);
    bool Compare(TESForm* other);
};
// @fnv 0x0040c870
bool MagicItemObjectShell::Compare(TESForm* other)
{
    MagicItemObject* converted = dynamic_cast<MagicItemObject*>(other);
    if (!converted)
        return true;
    if (FUN_00485270(other))
        return true;
    if (CompareMagic(static_cast<MagicItem*>(converted)))
        return true;
    if (reinterpret_cast<EffectListCompare*>(&effectList)->FUN_00405a00(converted ? &converted->effectList : 0))
        return true;
    return false;
}

struct FUN_0040c930_m30
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34(MagicItem* other);
};

struct FUN_00405b10_Obj
{
    void CopyItemsFromList(int other);
};

struct FUN_005054b0_shell
{
    int unk00;
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
    FUN_0040c930_m30 m30;
    int unk34;
    int unk38;
    FUN_00405b10_Obj m3c;

    void FUN_004851b0(TESForm* other);
    void CopyFrom(TESForm* arg);
};

extern int DAT_01183028;
extern int DAT_011830e8;

MagicItemObject* __cdecl FUN_00ec43fb(TESForm* arg, int a, int* b, int* c, int d);

// @fnv 0x0040c930
void FUN_005054b0_shell::CopyFrom(TESForm* pForm)
{
    MagicItemObject* result = FUN_00ec43fb(pForm, 0, &DAT_01183028, &DAT_011830e8, 0);
    if (!result)
        return;

    FUN_004851b0(pForm);

    m30.vfn_34(result ? reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(result) + 0x30) : 0);

    m3c.CopyItemsFromList(result ? reinterpret_cast<int>(reinterpret_cast<char*>(result) + 0x3C) : 0);
}

// fallout_shared/magic/magicitemform.cpp: MagicItemForm (5 functions)

#include "magicitemform_decls.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x0040c230
bool MagicItemForm::Load(TESFile* file)
{
    LoadRecordHeader(file);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* chunkData = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(chunkData, 0x200);
            SetEditorID_AtRuntime(chunkData);
            break;
        }

        case 0x444e424f:
            readOBNDSubRecord(file);
            break;

        case 0x4c4c5546: {
            TESFullNameLoader::LoadFullNameChunk(this ? (TESFullName*)((char*)this + 0x18) : 0, file);
            break;
        }

        case 0x44494645:
        case 0x41445443:
            ((EffectItemList*)((char*)this + 0x24))->Load(file, ((TESFullName*)((char*)this + 0x18))->GetFullName());
            break;

        default:
            break;
        }

        ((MagicItem*)((char*)this + 0x18))->LoadMagicItemChunk(file, chunkID);

        if (chunkID == ((MagicItem*)((char*)this + 0x18))->GetTypeSignature())
        {
            memset(((MagicItem*)((char*)this + 0x18))->GetData(), 0, ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            file->GetChunkData(((MagicItem*)((char*)this + 0x18))->GetData(),
                               ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            if (file->IsEndianConversionRequired())
                Endian();
        }

        if (!file->NextChunk())
            break;
    }

    if (((BSSimpleList<EffectSetting*>*)((char*)this + 0x28))->ItemsInList() == 0)
    {
        Warning(DAT_0101361c, GetFormID(), ((TESFullName*)((char*)this + 0x18))->GetFullName());
    }

    return true;
}

// @fnv 0x0040c5b0
void MagicItemForm::InitItem()
{
    if (GetInitialized())
        return;
    ((MagicItem*)((char*)this + 0x18))->LoadEffectsFromForm(this);
    SetInitializationState(true);
}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
    void FUN_00487010();
};
void __fastcall Save(void*);
struct V18
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};
struct FUN_0040c1d0_obj
{
    void FUN_0040c1d0();
};
// Calls M on the object, runs FUN_00487010 and v14/v15 on the sub-object at offset 0x18, then Save on offset 0x24 and M again.
// @fnv 0x0040c1d0
void FUN_0040c1d0_obj::FUN_0040c1d0()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x18))->FUN_00487010();
    ((V18*)((char*)this + 0x18))->v14();
    ((V18*)((char*)this + 0x18))->v15();
    Save((void*)((char*)this + 0x24));
    ((FUN_00485680*)this)->M();
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};

struct FUN_0040c450_MagicItem
{
    virtual bool v0();
    virtual bool v1();
    virtual bool v2();
    virtual bool v3();
    virtual bool v4();
    virtual bool v5();
    virtual bool v6();
    virtual bool v7();
    virtual bool v8();
    virtual bool v9();
    virtual bool v10();
    virtual bool v11();
    virtual bool v12(FUN_0040c450_MagicItem*);
};

struct FUN_0040c450_EffectItemList
{
    bool FUN_00405a00(FUN_0040c450_EffectItemList*);
};

struct FUN_0040c450_shell
{
    bool FUN_0040c450(TESForm*);
};

// @fnv 0x0040c450
bool FUN_0040c450_shell::FUN_0040c450(TESForm* apCompare)
{
    MagicItemForm* pmagicItem = dynamic_cast<MagicItemForm*>(apCompare);

    if (!pmagicItem)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->FUN_00485270(apCompare))
        return true;

    if (reinterpret_cast<FUN_0040c450_MagicItem*>(reinterpret_cast<char*>(this) + 0x18)
            ->v12(pmagicItem ? reinterpret_cast<FUN_0040c450_MagicItem*>(reinterpret_cast<char*>(pmagicItem) + 0x18)
                             : 0))
        return true;

    if (reinterpret_cast<FUN_0040c450_EffectItemList*>(reinterpret_cast<char*>(this) + 0x24)
            ->FUN_00405a00(
                pmagicItem ? reinterpret_cast<FUN_0040c450_EffectItemList*>(reinterpret_cast<char*>(pmagicItem) + 0x24)
                           : 0))
        return true;

    return false;
}

extern const char DAT_01183028[];
extern const char DAT_0118395c[];

class MagicComp
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D(MagicComp* other);

    int unk18;
    int unk1C;
};

class EndianComp
{
  public:
    void CopyItemsFromList(EndianComp* other);
};

struct FUN_0040c510_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MagicComp m18;
    EndianComp m24;
    void FUN_004851b0(TESForm* form);
    void FUN_0040c510(TESForm* form);
};

FUN_0040c510_cls* __cdecl FUN_00ec43fb(TESForm* form, int a2, const char* a3, const char* a4, int a5);

// @fnv 0x0040c510
void FUN_0040c510_cls::FUN_0040c510(TESForm* form)
{
    FUN_0040c510_cls* rec = FUN_00ec43fb(form, 0, DAT_01183028, DAT_0118395c, 0);
    if (rec == 0)
    {
        return;
    }
    FUN_004851b0(form);
    m18.v0D(rec ? &rec->m18 : (MagicComp*)0);
    m24.CopyItemsFromList(rec ? &rec->m24 : (EndianComp*)0);
}

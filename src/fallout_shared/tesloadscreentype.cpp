// fallout_shared/tesloadscreentype.cpp: TESLoadScreenType, ScalarStandIn, LoadScreenTypeData_FUN (7 functions)

#include "tesloadscreentype_decls.h"
// Reads the record header and chunks (EDID, OBND, DATA) from file, applies endian conversion to data, and returns true.
// @fnv 0x005a72f0
bool TESLoadScreenType::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            ((BGSImpactData*)this)->ReadTypedData(file, &data, 88);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        data.Endian();
    return true;
}

void* __cdecl __memcpy(void* dst, const void* src, unsigned int size);

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};

struct TESLoadScreenType_Shell
{
    void __thiscall CopyFrom(TESForm* apCopy);
};

// @fnv 0x005a7690
void __thiscall TESLoadScreenType_Shell::CopyFrom(TESForm* apCopy)
{
    TESLoadScreenType* pmisc = (TESLoadScreenType*)dynamic_cast<TESLoadScreenType*>(apCopy);
    if (!pmisc)
    {
        return;
    }
    __memcpy((char*)this + 0x18, (char*)pmisc + 0x18, 0x58);
    ((FUN_005e78f0_t*)this)->FUN_004851b0(apCopy);
}

void __cdecl _Deallocate(void*);
struct ScalarStandIn
{
    void __thiscall FUN_005a72d0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_005a72d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005a72a0
void* __thiscall ScalarStandIn::DestroyIfFlagged(unsigned int flags)
{
    FUN_005a72d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

bool __cdecl FUN_00401500();
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
    void __thiscall __SaveData(int, int);
};
struct FUN_005a7630_shell
{
    char _pad[24];
    LoadScreenTypeData _data;
    void __thiscall SwapEndianAndProcess();
};
// Calls M, conditionally byte-swaps _data before and after __SaveData, then calls M again.
// @fnv 0x005a7630
void __thiscall FUN_005a7630_shell::SwapEndianAndProcess()
{
    ((FUN_004855a0*)this)->M();
    if (FUN_00401500())
        _data.Endian();
    ((FUN_00485e00_shell*)this)->__SaveData((int)&_data, 0x58);
    if (FUN_00401500())
        _data.Endian();
    ((FUN_00485680*)this)->M();
}

struct ScriptS
{
    void* GetHeader();
};
int __cdecl _memcmp(const void*, const void*, unsigned int);
struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
struct FUN_005a76f0_shell
{
    char _pad[0x18];
    bool __thiscall FUN_005a76f0(TESForm* apCompare);
};
// Compares a TESLoadScreenType against this object's header bytes and a nested check, returning true when either differs or the cast fails.
// @fnv 0x005a76f0
bool __thiscall FUN_005a76f0_shell::FUN_005a76f0(TESForm* apCompare)
{
    TESLoadScreenType* pcomp = dynamic_cast<TESLoadScreenType*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(&this->_pad[0x18], ((ScriptS*)pcomp)->GetHeader(), 0x58))
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;
    return false;
}

struct FUN_005a72d0_base
{
    virtual ~FUN_005a72d0_base();
};

struct FUN_005a72d0_cls : FUN_005a72d0_base
{
    virtual ~FUN_005a72d0_cls();
};

// @fnv 0x005a72d0
FUN_005a72d0_cls::~FUN_005a72d0_cls()
{}

struct EndianTag
{
};
void __cdecl FUN_00401080(int* apValue, EndianTag aTag);
struct LoadScreenTypeData_FUN
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    void SwapEndianFields();
};
// Byte-swaps every integer field of the structure by calling FUN_00401080 on each member.
// @fnv 0x005a7400
void LoadScreenTypeData_FUN::SwapEndianFields()
{
    FUN_00401080(&unk28, EndianTag());
    FUN_00401080(&unk10, EndianTag());
    FUN_00401080(&unk04, EndianTag());
    FUN_00401080(&unk08, EndianTag());
    FUN_00401080(&unk14, EndianTag());
    FUN_00401080(&unk0C, EndianTag());
    FUN_00401080(&unk1C, EndianTag());
    FUN_00401080(&unk20, EndianTag());
    FUN_00401080(&unk24, EndianTag());
    FUN_00401080(&unk38, EndianTag());
    FUN_00401080(&unk2C, EndianTag());
    FUN_00401080(&unk30, EndianTag());
    FUN_00401080(&unk3C, EndianTag());
    FUN_00401080(&unk34, EndianTag());
    FUN_00401080(&unk44, EndianTag());
    FUN_00401080(&unk48, EndianTag());
    FUN_00401080(&unk4C, EndianTag());
    FUN_00401080(&unk50, EndianTag());
    FUN_00401080(&unk00, EndianTag());
    FUN_00401080(&unk18, EndianTag());
    FUN_00401080(&unk40, EndianTag());
    FUN_00401080(&unk54, EndianTag());
}

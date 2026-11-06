// fallout_shared/bgslightingtemplate.cpp: BGSLightingTemplate, SwapBlock, LightingDelete, LightingTemplateInit and more (11 functions)

#include "bgslightingtemplate.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x005265c0
BGSLightingTemplate::BGSLightingTemplate()
{
    SetFormType(ENUM_FORM_ID_LGTM_ID);
    ResetFormData();
}

// @fnv 0x00526710
void BGSLightingTemplate::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads the LGTM record header and chunks (EDID, OBND, DATA) into the lighting template, converting endianness if required.
// @fnv 0x005268a0
bool BGSLightingTemplate::Load(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_LGTM_ID)
        return false;
    LoadRecordHeader(file);
    int iChunkID;
    while ((iChunkID = file->GetChunkID()) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x41544144:  // DATA
            ReadTypedData(file, &Data, sizeof(Data));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        Data.Endian();
    return true;
}

struct FUN_00526640
{
    int a;
    int b;
    int c;
    float d;
    float e;
    int f;
    int g;
    float h;
    float i;
    float j;
    int k;
    FUN_00526640();
};
// Initialises all members of FUN_00526640 to zero, with h and j set to 1.0f.
// @fnv 0x00526640
FUN_00526640::FUN_00526640()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0.0f;
    e = 0.0f;
    f = 0;
    g = 0;
    h = 1.0f;
    i = 0.0f;
    j = 1.0f;
    k = 0;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_005266f0 : Base5a
{
    virtual ~FUN_005266f0();
};
// @fnv 0x005266f0
FUN_005266f0::~FUN_005266f0()
{}

struct FUN_004855a0_shell
{
    void FUN_004855a0();
};
struct FUN_00485680_shell
{
    void FUN_00485680();
};
struct FUN_00485e00_shell
{
    void __SaveData(int, int);
};
extern "C" bool __cdecl FUN_00401500();
struct FUN_00526730_obj : FUN_004855a0_shell
{
    void FUN_00526730();
};
// @fnv 0x00526730
void FUN_00526730_obj::FUN_00526730()
{
    FUN_004855a0();
    if (FUN_00401500())
        ((InteriorData*)((char*)this + 0x18))->Endian();
    ((FUN_00485e00_shell*)this)->__SaveData((int)((char*)this + 0x18), 0x2c);
    if (FUN_00401500())
        ((InteriorData*)((char*)this + 0x18))->Endian();
    ((FUN_00485680_shell*)this)->FUN_00485680();
}

struct SwapTag
{
};

void SwapInt(int* p, SwapTag tag);

struct SwapBlock
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

    void SwapBytes();
};

// Swaps the byte order of every 32-bit field in the block by calling SwapInt on each member.
// @fnv 0x00526790
void SwapBlock::SwapBytes()
{
    SwapInt(&unk00, SwapTag());
    SwapInt(&unk04, SwapTag());
    SwapInt(&unk08, SwapTag());
    SwapInt(&unk0C, SwapTag());
    SwapInt(&unk10, SwapTag());
    SwapInt(&unk14, SwapTag());
    SwapInt(&unk18, SwapTag());
    SwapInt(&unk1C, SwapTag());
    SwapInt(&unk20, SwapTag());
    SwapInt(&unk24, SwapTag());
}

extern "C" void* __cdecl _memcpy(void* dst, const void* src, unsigned int size);

struct FUN_005054b0_shell : TESForm
{
    void FUN_004851b0(TESForm* arg);
};

struct FUN_005269f0_Lighting : BGSLightingTemplate
{
    void FUN_005269f0(TESForm* arg);
};

// Copies InteriorData from a BGSLightingTemplate source and calls the base class copy routine.
// @fnv 0x005269f0
void FUN_005269f0_Lighting::FUN_005269f0(TESForm* apSource)
{
    BGSLightingTemplate* src = dynamic_cast<BGSLightingTemplate*>(apSource);
    if (src == 0)
    {
    }
    else
    {
        _memcpy(&Data, &src->Data, sizeof(InteriorData));
        reinterpret_cast<FUN_005054b0_shell*>(this)->FUN_004851b0(apSource);
    }
}

void _Deallocate(void*);

struct LightingDelete : BGSLightingTemplate
{
    void FUN_005266f0();
    void* FUN_005266c0(unsigned int flags);
};

// Calls FUN_005266f0, then deallocates this via _Deallocate when the low bit of flags is set, and returns this.
// @fnv 0x005266c0
void* LightingDelete::FUN_005266c0(unsigned int flags)
{
    FUN_005266f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LightingTemplateInit : BGSLightingTemplate
{
    void FUN_005269c0();
};
// If the form is not yet initialized, clears its data and marks it as initialized.
// @fnv 0x005269c0
void LightingTemplateInit::FUN_005269c0()
{
    if (IsFormInitialized())
        return;
    TESForm::ClearData();
    SetInitializationState(true);
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
struct LightingComparison : public BGSLightingTemplate
{
    bool FUN_00526a50(TESForm*);
};
// Returns true when the cast fails, the InteriorData bytes differ, or TESForm::Compare returns true.
// @fnv 0x00526a50
bool LightingComparison::FUN_00526a50(TESForm* form)
{
    BGSLightingTemplate* other = dynamic_cast<BGSLightingTemplate*>(form);
    if (!other)
        return true;
    if (_memcmp(&Data, &other->Data, sizeof(InteriorData)))
        return true;
    if (TESForm::Compare(other))
        return true;
    return false;
}

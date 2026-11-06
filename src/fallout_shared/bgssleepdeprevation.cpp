// fallout_shared/bgssleepdeprevation.cpp: BGSSleepDeprevationStage (11 functions)

#include "bgssleepdeprevation.h"
#include <malloc.h>

class StageLoadVirtuals
{
  public:
    virtual void vfn_0000() = 0;
    virtual void vfn_0004() = 0;
    virtual void vfn_0008() = 0;
    virtual void vfn_000c() = 0;
    virtual void vfn_0010() = 0;
    virtual void vfn_0014() = 0;
    virtual void vfn_0018() = 0;
};

// @fnv 0x00402200
void BGSSleepDeprevationStage::ClearData()
{
    ClearStageData(this);
}

// @fnv 0x00402220
void BGSSleepDeprevationStage::InitItem()
{
    unsigned int formID;
    if (reinterpret_cast<TESFormInitFlag*>(reinterpret_cast<TESForm*>(this))->IsFormInitialized())
        return;
    formID = FUN_00441110();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, reinterpret_cast<TESForm*>(this)->GetFile(-1));
        FUN_0050f9a0(dynamic_cast<SpellItem*>(TESFormInitFlag::GetFormByID(formID)));
    }
    reinterpret_cast<TESForm*>(this)->SetInitializationState(true);
    FUN_00402550(this);
}

struct RemoveStageLocals
{
    BGSSleepDeprevationStage** oldStages;
    unsigned int source;
    unsigned int destination;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    bool found;
    unsigned int newCount;
    BGSDehydrationStage** newStages;
};

// Removes the given stage from the global stage array, reallocating a smaller array and deleting the old one.
// @fnv 0x00402650
void BGSSleepDeprevationStage::ClearStageData(BGSSleepDeprevationStage* stage)
{
    RemoveStageLocals locals;

    if (!DAT_011c31b0)
        return;

    locals.found = false;
    locals.index = 0;
    for (; !locals.found && locals.index < DAT_011c31b0; ++locals.index)
    {
        if (DAT_011c31b4[locals.index] == stage)
            locals.found = true;
    }

    if (!locals.found)
        return;

    locals.newCount = DAT_011c31b0 - 1;
    locals.newStages = BGSDehydrationStage::AllocateStageArray(locals.newCount);
    if (locals.newStages)
    {
        locals.destination = 0;
        locals.source = 0;
        for (; locals.source < DAT_011c31b0; ++locals.source)
        {
            if (DAT_011c31b4[locals.source] != stage)
            {
                reinterpret_cast<BGSSleepDeprevationStage**>(locals.newStages)[locals.destination] =
                    DAT_011c31b4[locals.source];
                ++locals.destination;
            }
        }
    }

    locals.oldStages = DAT_011c31b4;
    ::operator delete(locals.oldStages);
    DAT_011c31b0 = locals.newCount;
    DAT_011c31b4 = reinterpret_cast<BGSSleepDeprevationStage**>(locals.newStages);
}

// Reads a TESFile record, requiring form type 0x78, then dispatches EDID, OBND and DATA chunks until the chunk list ends.
// @fnv 0x00402390
bool BGSSleepDeprevationStage::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x78)
        return false;

    reinterpret_cast<StageLoadVirtuals*>(this)->vfn_0018();
    reinterpret_cast<TESForm*>(this)->LoadRecordHeader(file);
    reinterpret_cast<TESForm*>(this)->SetInitializationState(false);

    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            reinterpret_cast<TESForm*>(this)->SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444e424f:
            reinterpret_cast<TESForm*>(this)->readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSDehydrationStage*>(this)->LoadData(
                file, reinterpret_cast<BGSDehydrationStage*>(this)->FUN_00500940(8));
            break;
        }

        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<FUN_005a71d0*>(&data)->FUN_00462230();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct HSD
{
    HSD();
    int x;
};
struct HSI
{
    void ResetFormData();
};
struct FUN_004020f0 : public TESForm
{
    HSD data;
    FUN_004020f0();
    ~FUN_004020f0();
};
// @fnv 0x004020f0
FUN_004020f0::FUN_004020f0()
{
    SetFormType((ENUM_FORM_ID)0x78);
    ((HSI*)this)->ResetFormData();
}

extern unsigned int _DAT_011c31b0;
extern BGSDehydrationStage** _DAT_011c31b4;
struct HF
{
    unsigned int* FUN_00500940();
};
struct AddLocals
{
    BGSDehydrationStage** oldStages;
    unsigned int index;
    unsigned char p0, p1, p2;
    unsigned char newCount;
    unsigned int destination;
    unsigned char p3, p4, p5;
    bool inserted;
    BGSDehydrationStage** newStages;
};
// Inserts stage into the global dehydration-stage array in descending order of FUN_00500940 value, reallocating the array and updating the count.
// @fnv 0x00402550
void FUN_00402550(BGSDehydrationStage* stage)
{
    AddLocals locals;
    locals.newCount = (unsigned char)(_DAT_011c31b0 + 1);
    locals.newStages = BGSDehydrationStage::AllocateStageArray(locals.newCount);
    locals.destination = 0;
    locals.inserted = false;
    locals.index = 0;
    for (; locals.index < _DAT_011c31b0; ++locals.index)
    {
        if (*((HF*)stage)->FUN_00500940() > *((HF*)_DAT_011c31b4[locals.index])->FUN_00500940() && !locals.inserted)
        {
            locals.newStages[locals.destination] = stage;
            ++locals.destination;
            locals.inserted = true;
        }
        locals.newStages[locals.destination] = _DAT_011c31b4[locals.index];
        ++locals.destination;
    }
    if (!locals.inserted)
    {
        locals.newStages[locals.destination] = stage;
        ++locals.destination;
    }
    locals.oldStages = _DAT_011c31b4;
    ::operator delete(locals.oldStages);
    _DAT_011c31b0 = locals.newCount;
    _DAT_011c31b4 = locals.newStages;
}

extern unsigned int DAT_011c31b0;
BGSSleepDeprevationStage* __cdecl FUN_004027e0(unsigned int);

class Calendar
{
  public:
    unsigned int GetDaysPassed();
};

// Returns the first sleep-deprivation stage whose days-passed threshold is at or below level, or null if none match.
// @fnv 0x00402760
BGSSleepDeprevationStage* __cdecl GetSleepDeprivationStage(float level)
{
    BGSSleepDeprevationStage* result = 0;
    for (unsigned int index = 0; index < DAT_011c31b0 && !result; ++index)
    {
        BGSSleepDeprevationStage* stage = FUN_004027e0(index);
        if (stage && level >= reinterpret_cast<Calendar*>(stage)->GetDaysPassed())
            result = stage;
    }
    return result;
}

void _Deallocate(void*);
struct Dummy
{
    void FUN_004021a0();
    void* FUN_00402170(unsigned int);
};
// Calls FUN_004021a0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00402170
void* Dummy::FUN_00402170(unsigned int flags)
{
    FUN_004021a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_004021a0 : Base5a
{
    ~FUN_004021a0();
};
// Destructor that calls ClearData on the BGSSleepDeprevationStage object.
// @fnv 0x004021a0
FUN_004021a0::~FUN_004021a0()
{
    ((BGSSleepDeprevationStage*)this)->ClearData();
}

namespace fnv_004022b0 {
struct FUN_005e78f0_t
{
    void FUN_004851b0(BGSSleepDeprevationStage*);
};
struct HF
{
    void* FUN_00500940();
};
void* __memcpy(void*, const void*, unsigned int);
struct FUN_004022b0_Host
{
    void CopyFromSleepDeprivationStage(TESForm* apCopy);
};
// @fnv 0x004022b0
void FUN_004022b0_Host::CopyFromSleepDeprivationStage(TESForm* apCopy)
{
    BGSSleepDeprevationStage* pcopy = dynamic_cast<BGSSleepDeprevationStage*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0(pcopy);
    __memcpy(((HF*)this)->FUN_00500940(), ((HF*)pcopy)->FUN_00500940(), 8);
}
}  // namespace fnv_004022b0

extern "C" int __cdecl memcmp(const void* pvA, const void* pvB, unsigned int uiSize);

class B402310Stage
{
  public:
    bool FUN_00485270(BGSSleepDeprevationStage* pkOther);
    void* GetData();
    bool FUN_00402310(TESForm* pkForm);
};

// @fnv 0x00402310
bool B402310Stage::FUN_00402310(TESForm* pkForm)
{
    BGSSleepDeprevationStage* pkOther = dynamic_cast<BGSSleepDeprevationStage*>(pkForm);
    if (!pkOther)
        return true;
    if (FUN_00485270(pkOther))
        return true;
    if (memcmp(GetData(), reinterpret_cast<B402310Stage*>(pkOther)->GetData(), 8))
        return true;
    return false;
}

// fallout_shared/teslevcreature.cpp: Entry, TESLevCreature (7 functions)

#include "teslevcreature_decls.h"
// @fnv 0x0050af60
bool TESLevCreature::Load(TESFile* file)
{
    unsigned char type = file->GetTESForm();
    if (type != 44)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case 0x44494445: {
            char* uiGlobalId = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(uiGlobalId, 512);
            SetEditorID(uiGlobalId);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)file->GetChunkID())
            {
            case 0x4f4c564c: {
                LeveledObject leveledEntry;
                memset(&leveledEntry, 0, 12);
                file->GetChunkData(&leveledEntry, 12);
                if (file->IsEndianConversionRequired())
                    leveledEntry.SwapEndian();
                DAT_011c8eec =
                    (LeveledEntry*)CreateLeveledObject(leveledEntry.level, leveledEntry.count, leveledEntry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8eec)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    DAT_011c8eec->extra = extra;
                    DAT_011c8eec = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            file->GetChunkData(&chance, 0);
            FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            file->GetChunkData(&flags, 0);
            break;
        case 0x474c564c: {
            unsigned int uiGlobalId = 0;
            file->GetChunkData(&uiGlobalId);
            global = (TESForm*)uiGlobalId;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct
            {
                unsigned int size;
                void* data;
            } chunk;
            chunk.size = file->GetChunkSize();
            chunk.data = _alloca(chunk.size);
            file->GetChunkData(chunk.data, chunk.size);
            ParseTextureSwapData(chunk.data, chunk.size, file->GetFormVersion());
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

struct B1_4fe : public TESForm
{
    B1_4fe();
    ~B1_4fe();
    void SetFormType(int);
    void ClearData();
};
struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v[6];
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void vf2();
    int w;
};
struct FUN_0050adf0 : public B1_4fe, public FUN_00487650, public B2_4fe
{
    FUN_0050adf0();
    ~FUN_0050adf0();
};
// @fnv 0x0050adf0
FUN_0050adf0::FUN_0050adf0()
{
    SetFormType(0x2c);
    ClearData();
    SetInitializationState(true);
}

struct FUN_0050aea0_shell : public FUN_0050adf0
{
    void FUN_0050aed0();
    void* FUN_0050aea0(unsigned int flags);
};

// Calls FUN_0050aed0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0050aea0
void* FUN_0050aea0_shell::FUN_0050aea0(unsigned int flags)
{
    FUN_0050aed0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Date
{
    ~Date();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_00488400_shell
{
    void SaveLeveledList();
};
struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

struct FUN_0050a8e0_shell
{
    void FUN_0050a8e0();
};

// Calls M and the Date destructor on the object at offset 0, then SaveLeveledList at 0x30, ProcessAndFreeData at 0x4c, and M at offset 0.
// @fnv 0x0050a8e0
void FUN_0050a8e0_shell::FUN_0050a8e0()
{
    ((FUN_004855a0*)((char*)this + 0x00))->M();
    ((Date*)((char*)this + 0x00))->Date::~Date();
    ((FUN_00488400_shell*)((char*)this + 0x30))->SaveLeveledList();
    ((DoorPart3c*)((char*)this + 0x4c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_00485680*)((char*)this + 0x00))->M();
}

// Destructor of a form component with three polymorphic bases; the bases clean up in reverse order.

class AED0Primary
{
  public:
    virtual ~AED0Primary();
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
};

class AED0Model
{
  public:
    virtual ~AED0Model();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class AED0TextureSwap
{
  public:
    virtual ~AED0TextureSwap();
};

class FUN_0050aed0 : public AED0Primary, public AED0Model, public AED0TextureSwap
{
  public:
    virtual ~FUN_0050aed0();
};

// Destructor for a class combining AED0Primary, AED0Model and AED0TextureSwap; it performs no work.
// @fnv 0x0050aed0
FUN_0050aed0::~FUN_0050aed0()
{}

namespace LevCreatureCopyImplementation {

struct Entry : public TESLevCreature
{
    void FUN_004851b0(TESForm*);
    void CopyFrom(TESForm*);
};

// Casts source to TESLevCreature and, if valid, calls FUN_004851b0 to copy data from it.
// @fnv 0x0050b2e0
void Entry::CopyFrom(TESForm* source)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(source);
    if (!creature)
        return;
    FUN_004851b0(source);
}

}

namespace LevCreatureComparisonImplementation {

struct Entry : public TESLevCreature
{
    bool FUN_00485270(TESForm*);
    bool Compare(TESForm*);
};

// Returns true if the other form is not a TESLevCreature or if FUN_00485270(creature) is true, otherwise false.
// @fnv 0x0050b320
bool Entry::Compare(TESForm* other)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(other);
    if (!creature)
        return true;
    if (FUN_00485270(creature))
        return true;
    return false;
}

}

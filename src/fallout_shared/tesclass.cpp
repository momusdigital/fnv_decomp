// fallout_shared/tesclass.cpp: TESClass, ActorValue, ClassComparison (15 functions)

#include "tesclass_decls.h"
// Stores skill into data.skills[index] and marks the class modified when skill is a skill or None.
// @fnv 0x005f6e80
void TESClass::SetClassSkillAtIndex(int index, ActorValue::Index skill)
{
    if (ActorValue::IsSkill(skill) || skill == ActorValue::None)
    {
        data.skills[index] = skill;
        MarkAsModified(2);
    }
}
// Clears the 28-byte data block and sets all four actor value slots to ActorValue::None.
// @fnv 0x005f67c0
void TESClass::ResetFormData()
{
    memset(&data, 0, 28);
    for (int i = 0; i < 4; ++i)
        SetClassSkillAtIndex(i, ActorValue::None);
}
// Loads the base form data, then reads four skill values from the buffer when change flag 2 is set.
// @fnv 0x005f71c0
void TESClass::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags(2))
    {
        for (unsigned int i = 0; i < 4; ++i)
            buffer->ReadTypedData(&data.skills[i], 4);
    }
}
// Reads a TESClass record from the file, handling EDID, OBND, FULL, DESC, ICON, DATA and ATTR chunks, then warns if the class data is invalid.
// @fnv 0x005f6930
bool TESClass::Load(TESFile* file)
{
    if (((TESFileFormInt*)file)->GetTESForm() != 7)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x41544144:
            if (file->GetChunkSize() == GetDataSizeAdjustment() + 28)
            {
                ((BGSImpactData*)this)->ReadTypedData(file, &data, 28);
                if (file->IsEndianConversionRequired())
                    data.SwapEndian();
            }
            else if (file->GetChunkSize() == 24 || file->GetChunkSize() == GetDataSizeAdjustment() + 24)
            {
                LegacyActorBaseData oldData;
                if (file->GetChunkSize() == GetDataSizeAdjustment() + 24)
                    ((BGSImpactData*)this)->ReadTypedData(file, &oldData, 24);
                else
                    file->GetChunkData(&oldData, 24);
                if (file->IsEndianConversionRequired())
                    oldData.SwapEndianData();
                data.flags = oldData.flags;
                data.services = oldData.services;
                data.trainingLevel = oldData.trainingLevel;
                data.trainingSkill = oldData.trainingSkill;
                for (int i = 0; i < 3; ++i)
                    data.skills[i] = oldData.skills[i];
            }
            else
            {
                file->GetChunkData(&data, 28);
                if (file->IsEndianConversionRequired())
                    data.SwapEndian();
            }
            break;
        case 0x52545441: {
            unsigned char attributes[7];
            file->GetChunkData(attributes, 7);
            TESAttributes::FUN_00480130(attributes);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    if (!ValidateSkillActorValue())
        Warning("MASTERFILE: Class %s contains invalid data. Make sure all attributes and skills are unique",
                GetName());
    return true;
}

struct FUN_005f6e20_shell : public TESClass
{
    bool ValidateSkillActorValue();
};

struct TESClass_Helper
{
    ActorValue::Index GetTrainingSkill();
    void SetSkillIndex(int);
};

// @fnv 0x005f6e20
bool FUN_005f6e20_shell::ValidateSkillActorValue()
{
    bool bIsSkill = true;
    if (!ActorValue::IsSkill(((TESClass_Helper*)this)->GetTrainingSkill()))
    {
        ((TESClass_Helper*)this)->SetSkillIndex(0x20);
        bIsSkill = false;
    }
    return bIsSkill;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<4>);
void __cdecl BSEndian(int*, EndianSizeTag<3>);
void __cdecl BSEndian(float*, EndianSizeTag<3>);

struct FUN_005f68d0_shell
{
    void SwapEndian();
};

// Byte-swaps the four 3-byte values at the start of this object and the 4-byte value at offset 0x14.
// @fnv 0x005f68d0
void FUN_005f68d0_shell::SwapEndian()
{
    BSEndian((int*)(this + 0x14), EndianSizeTag<4>());
    for (int i = 0; i < 4; ++i)
        BSEndian((int*)this + i, EndianSizeTag<3>());
}

namespace fnv_005f6c90 {
template <int N> class EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_005f6c90_shell
{
    int m_data[4];
    void SwapEndianData();
};

// @fnv 0x005f6c90
void FUN_005f6c90_shell::SwapEndianData()
{
    BSEndian(&m_data[4], EndianSizeTag<3>());
    for (int i = 0; i < 3; ++i)
    {
        BSEndian(&m_data[i], EndianSizeTag<3>());
    }
}
}  // namespace fnv_005f6c90

struct FUN_005f6dd0_shell
{
    int GetTrainingSkill();
};

// @fnv 0x005f6dd0
int FUN_005f6dd0_shell::GetTrainingSkill()
{
    int result = *(unsigned char*)((char*)this + 0x5c) + 0x20;
    return result;
}

struct FUN_005f6df0_shell
{
    void SetSkillIndex(ActorValue::Index index);
};

// If index is a skill, stores index minus 0x20 into the byte at offset 0x5c of this object.
// @fnv 0x005f6df0
void FUN_005f6df0_shell::SetSkillIndex(ActorValue::Index aeSkillIndex)
{
    if (ActorValue::IsSkill(aeSkillIndex))
    {
        ((unsigned char*)this)[0x5c] = (unsigned char)(aeSkillIndex - 0x20);
    }
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};

struct FUN_005f7150_shell
{
    void SaveForm(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x005f7150
void __thiscall FUN_005f7150_shell::SaveForm(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    ((FUN_00484d60_holder*)this)->SaveIfChanged((unsigned int)apSaveGameBuffer);
    if (((BGSLoadFormBuffer*)apSaveGameBuffer)->GetChangeFlags(2))
    {
        for (i = 0; i < 4; ++i)
        {
            apSaveGameBuffer->SaveData((void*)((char*)this + 0x44 + i * 4), 4, 0);
        }
    }
}

extern "C"
{
    unsigned char __cdecl _FUN_00401500();
}

struct FUN_004855a0
{
    void __thiscall M(void);
};
struct S_00487010
{
    void __thiscall FUN_00487010(void);
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0(void);
};
struct FUN_00480100_shell
{
    unsigned int __thiscall Save(void*);
};
struct FUN_00485680
{
    void __thiscall M(void);
};

struct FUN_0048e370_obj
{
    void __thiscall FUN_0048e370(unsigned int);
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
void __cdecl _FUN_00485990(unsigned int, void*, unsigned int);

struct FUN_005f6810_shell
{
    void __thiscall FUN_005f6810(void);
};

// @fnv 0x005f6810
void __thiscall FUN_005f6810_shell::FUN_005f6810(void)
{
    char cAttribData[7];
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x18)->FUN_00487010();
    reinterpret_cast<FUN_00482cb0_shell*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00482cb0();
    reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x2c)->FUN_0048e370(0x4e4f4349);
    if (_FUN_00401500())
    {
        reinterpret_cast<TESClassData*>(reinterpret_cast<char*>(this) + 0x44)->SwapEndian();
    }
    _FUN_00485990(0x41544144, reinterpret_cast<char*>(this) + 0x44, 0x1c);
    if (_FUN_00401500())
    {
        reinterpret_cast<TESClassData*>(reinterpret_cast<char*>(this) + 0x44)->SwapEndian();
    }
    reinterpret_cast<FUN_00480100_shell*>(reinterpret_cast<char*>(this) + 0x38)->Save(cAttribData);
    FUN_004856f0(0x52545441, cAttribData, 7);
    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct S_005f66e0
{
    void FUN_005f6710();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_005f6710, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x005f66e0
void* S_005f66e0::DestroyIfFlagged(unsigned int flags)
{
    FUN_005f6710();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
    void CopyFromTESClass(TESForm* apCopy);
};
// @fnv 0x005f6d70
void FUN_005e78f0_t::CopyFromTESClass(TESForm* apCopy)
{
    TESClass* cl = dynamic_cast<TESClass*>(apCopy);
    if (!cl)
        return;
    FUN_004851b0(apCopy);
    __memcpy((void*)((char*)this + 0x44), ((XActor*)cl)->GetExtra(), 0x1c);
}

struct FUN_005f6710_Primary
{
    virtual ~FUN_005f6710_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_005f6710_Base18
{
    virtual ~FUN_005f6710_Base18();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005f6710_Base24
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_005f6710_Base2c
{
    virtual ~FUN_005f6710_Base2c();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005f6710_Base38
{
    virtual ~FUN_005f6710_Base38();
    unsigned int unk04;
};

struct FUN_005f6710 : FUN_005f6710_Primary,
                      FUN_005f6710_Base18,
                      FUN_005f6710_Base24,
                      FUN_005f6710_Base2c,
                      FUN_005f6710_Base38
{
    virtual ~FUN_005f6710();
};

// Destructor for FUN_005f6710; it has an empty body and only tears down the base subobjects.
// @fnv 0x005f6710
FUN_005f6710::~FUN_005f6710()
{}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

class ClassDataAccess : public TESClass
{
  public:
    TESClassData* FUN_005d43c0();
};

class ClassComparison : public TESClass
{
  public:
    bool FUN_00485270(TESForm*);
    bool FUN_005f6cf0(TESForm* other);
};

// Returns true if the cast fails, FUN_00485270 returns true, or the two TESClassData byte ranges differ.
// @fnv 0x005f6cf0
bool ClassComparison::FUN_005f6cf0(TESForm* other)
{
    TESClass* pClass = dynamic_cast<TESClass*>(other);
    if (!pClass)
        return true;
    if (FUN_00485270(pClass))
        return true;
    if (_memcmp(&data, static_cast<ClassDataAccess*>(pClass)->FUN_005d43c0(), sizeof(TESClassData)))
        return true;
    return false;
}

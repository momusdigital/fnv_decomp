
// src/fallout_shared/bgscliproundsform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgscliproundsform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TESForm;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
typedef char _sizecheck_BGSClipRoundsForm[sizeof(BGSClipRoundsForm) == 8 ? 1 : -1];
struct FUN_00475100_shell : public BGSClipRoundsForm
{
    void SetClipRounds();
};

// @fnv 0x00475100
void FUN_00475100_shell::SetClipRounds()
{
    m_ucClipRounds = 0xc;
}

struct SFTX
{
    void SetFormType(int);
};
struct FUN_00475120_shell : public BGSClipRoundsForm
{
    void CopyFormTypeFromComponent(BaseFormComponent*);
    int GetFormType();
};
// Casts component to BGSClipRoundsForm and, if successful, sets this object's form type to the component's form type.
// @fnv 0x00475120
void FUN_00475120_shell::CopyFormTypeFromComponent(BaseFormComponent* component)
{
    BGSClipRoundsForm* clipRounds = dynamic_cast<BGSClipRoundsForm*>(component);
    if (!clipRounds)
        return;
    ((SFTX*)this)->SetFormType(((FUN_00475120_shell*)clipRounds)->GetFormType());
}

struct TESForm
{
    int __thiscall FNV_GetFormType();
};
struct FUN_00475170_shell : public BGSClipRoundsForm
{
    bool CompareComponent(BaseFormComponent*);
};
// Casts other to BGSClipRoundsForm and returns true if the cast fails or the form types differ, otherwise false.
// @fnv 0x00475170
bool FUN_00475170_shell::CompareComponent(BaseFormComponent* other)
{
    BGSClipRoundsForm* pClipRoundsForm = dynamic_cast<BGSClipRoundsForm*>(other);
    if (!pClipRoundsForm)
        return true;
    if (reinterpret_cast<TESForm*>(this)->FNV_GetFormType() !=
        reinterpret_cast<TESForm*>(pClipRoundsForm)->FNV_GetFormType())
        return true;
    return false;
}

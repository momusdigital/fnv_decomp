// src/fallout_shared/tessoundfile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tessoundfile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct FNStub
{
    const char* GetFullName();
};
struct TESSoundFile : public BaseFormComponent
{
    virtual ~TESSoundFile();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void SetName(const char* name);
    void CopyComponent(BaseFormComponent* apCopyFC);
};
// Casts apCopyFC to TESSoundFile and, if successful, copies its full name via SetName.
// @fnv 0x0048cf00
void TESSoundFile::CopyComponent(BaseFormComponent* apCopyFC)
{
    TESSoundFile* pcopy = dynamic_cast<TESSoundFile*>(apCopyFC);
    if (!pcopy)
        return;
    SetName(((FNStub*)pcopy)->GetFullName());
}

struct TESModel
{
    unsigned int GetModelLength();
};
int _stricmp(const char*, const char*);
struct FUN_0048cf50_shell : public TESSoundFile
{
    bool CompareComponent(BaseFormComponent* apCompareFC);
};
// @fnv 0x0048cf50
bool FUN_0048cf50_shell::CompareComponent(BaseFormComponent* apCompareFC)
{
    TESSoundFile* pcompare = dynamic_cast<TESSoundFile*>(apCompareFC);
    if (!pcompare)
        return true;
    if (reinterpret_cast<TESModel*>(this)->GetModelLength() || reinterpret_cast<TESModel*>(pcompare)->GetModelLength())
    {
        if (reinterpret_cast<TESModel*>(this)->GetModelLength() !=
            reinterpret_cast<TESModel*>(pcompare)->GetModelLength())
            return true;
        else
        {
            if (_stricmp(reinterpret_cast<FNStub*>(this)->GetFullName(),
                         reinterpret_cast<FNStub*>(pcompare)->GetFullName()))
                return true;
        }
    }
    return false;
}

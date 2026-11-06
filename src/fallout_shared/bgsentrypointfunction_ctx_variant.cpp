
// bgsentrypointfunction_ctx_variant.cpp: context variant of src/fallout_shared/bgsentrypointfunction.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "BGSEntryPointFunction.h"

extern "C" void* __cdecl memset(void* dest, int c, size_t count);

class ScriptVariableInfo
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    BSStringT<char> name;

    ScriptVariableInfo();
};

extern ScriptVariableInfo* DAT_011cb0fc;

class FUN_005e2a20_shell
{
  public:
    void FUN_005e2a20(TESFile* file);
};

class FUN_00500910
{
  public:
    BSStringT<char> name;
    unsigned int formID;
    unsigned int variableOrIndex;

    FUN_00500910();
};

class ScriptHeader
{
  public:
    void ByteSwap();
};

class FUN_005d43e0_shell
{
  public:
    void* FUN_005d43e0();
};

class FUN_005d43c0_
{
  public:
    void* FUN_005d43c0();
};

class FUN_005aae70_shell
{
  public:
    void SetCompileData(unsigned int, char*);
};

class FUN_00472840_impl
{
  public:
    bool ReadChunkData(unsigned short*);
};

class FUN_005e6c60_shell
{
  public:
    void FUN_005e6c60(void* data);
};

class Script : public TESForm
{
  public:
    ScriptHeader* GetHeader();
};

class ActivateChoice : public BGSEntryPointFunctionDataActivateChoice
{
  public:
    bool FUN_005e6ee0(TESFile* file);
};

// @fnv 0x005e6ee0
bool ActivateChoice::FUN_005e6ee0(TESFile* file)
{
    void* scvrBuf3;
    unsigned int scdaSize4;
    void* scdaData;
    unsigned int scroRefID2;
    FUN_00500910* scroObjVal;
    unsigned int scrvRefID3;
    FUN_00500910* _scrvObj;
    void* epf2BufTmp;

    switch (static_cast<int>(file->GetChunkID()))
    {
    case 0x44534c53:  // 'SLSD'
    case 0x52564353:  // 'SCVR'
        if (file->GetChunkID() == 0x44534c53)
        {
            DAT_011cb0fc = new ScriptVariableInfo();
            reinterpret_cast<FUN_005e2a20_shell*>(DAT_011cb0fc)->FUN_005e2a20(file);
            reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43e0_shell*>(formStorage)->FUN_005d43e0())
                ->AddTail(reinterpret_cast<Actor*&>(DAT_011cb0fc));
        }
        else if (DAT_011cb0fc)
        {
            scvrBuf3 = _alloca(file->GetChunkSize());
            file->GetChunkData(scvrBuf3, 0x200);
            DAT_011cb0fc->name.Set(reinterpret_cast<const char*>(scvrBuf3), 0);
        }
        break;

    case 0x52484353:  // 'SCHR'
        file->GetChunkData(reinterpret_cast<Script*>(formStorage)->GetHeader(), 0);
        if (file->IsEndianConversionRequired())
        {
            reinterpret_cast<Script*>(formStorage)->GetHeader()->ByteSwap();
        }
        break;

    case 0x41444353:  // 'SCDA'
        scdaSize4 = file->GetChunkSize();
        scdaData = _alloca(scdaSize4);
        memset(scdaData, 0, scdaSize4);
        file->GetChunkData(scdaData, 0);
        reinterpret_cast<FUN_005aae70_shell*>(formStorage)->SetCompileData(scdaSize4, reinterpret_cast<char*>(scdaData));
        break;

    case 0x4f524353:  // 'SCRO'
        scroObjVal = new FUN_00500910();
        file->GetChunkData(&scroRefID2);
        scroObjVal->formID = scroRefID2;
        reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43c0_*>(formStorage)->FUN_005d43c0())
            ->AddTail(reinterpret_cast<Actor*&>(scroObjVal));
        break;

    case 0x56524353:  // 'SCRV'
        _scrvObj = new FUN_00500910();
        file->GetChunkData(&scrvRefID3);
        _scrvObj->variableOrIndex = scrvRefID3;
        reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43c0_*>(formStorage)->FUN_005d43c0())
            ->AddTail(reinterpret_cast<Actor*&>(_scrvObj));
        break;

    case 0x32465045:  // 'EPF2'
        epf2BufTmp = _alloca(file->GetChunkSize());
        file->GetChunkData(epf2BufTmp, 0);
        reinterpret_cast<FUN_005e6c60_shell*>(this)->FUN_005e6c60(epf2BufTmp);
        break;

    case 0x33465045:  // 'EPF3'
        reinterpret_cast<FUN_00472840_impl*>(file)->ReadChunkData(&flags);
        break;

    default:
        break;
    }

    return true;
}

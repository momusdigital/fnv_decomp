// fallout_shared/tesobjectimod.cpp: TESObjectIMOD (14 functions)

#include "tesobjectimod_decls.h"

class TESFormInitFlag : public TESObjectIMODVirtuals
{
  public:
    bool IsFormInitialized() const;
};

enum ENUM_FORM_ID
{
    kIMOD = 0x67
};

class TESForm : public TESFormInitFlag
{
  private:
    unsigned char fields[0x14];

  public:
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile*);
    void ReadTypedData(TESFile*, void*, unsigned short);
};

class TESBoundObject : public TESForm
{
  private:
    unsigned char fields[0x18];

  public:
    TESBoundObject();
    ~TESBoundObject();
};

class TESFullName : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESFullName();
    ~TESFullName();
};

class TESModel : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x14];

  public:
    static void LoadModelData(TESModel*, TESFile*);
};

class TESModelTextureSwap : public TESModel
{
  private:
    unsigned char fields[0x08];

  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm* form);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
};

class TESTexture : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};

class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

class TESScriptableForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESScriptableForm();
    void SetScript(Script*);
    void InitItem(TESForm* form);
};

class TESDescription : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};

class TESValueForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESValueForm();
    ~TESValueForm();
};

class TESWeightForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESWeightForm();
    ~TESWeightForm();
};

class BGSDestructibleObjectForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    BGSDestructibleObjectForm();
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm* form);
};

class BGSMessageIcon : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x0c];

  public:
    BGSMessageIcon();
    static void LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
    ~BGSMessageIcon();
};

class BGSPickupPutdownSounds : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    BGSPickupPutdownSounds();
    void SetPickupSound(TESSound*);
    void SetPutdownSound(TESSound*);
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};

class TESObjectIMOD : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectIMOD();
    bool Load(TESFile*);
    void InitItem();
};

// @fnv 0x00519fc0
void TESObjectIMOD::InitItem()
{
    if (IsFormInitialized())
        return;
    TESScriptableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Loads a TESObjectIMOD record: reads the header, then dispatches each chunk to its loader until no chunks remain, returning true.
// @fnv 0x0051a030
bool TESObjectIMOD::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = (int)file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            reinterpret_cast<TESObjectIMODVirtuals*>(this)->SetEditorID(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            reinterpret_cast<TESObjectIMODVirtuals*>(this)->readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x44444f4d:  // MODD
        case 0x54444f4d:  // MODT
        case 0x44534f4d:  // MOSD
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {  // MODS
            struct TextureSwapChunk
            {
                unsigned int size;
                void* data;
            } swaps;
            swaps.size = file->GetChunkSize();
            swaps.data = _alloca(swaps.size);
            file->GetChunkData(swaps.data, swaps.size);
            ParseTextureSwapData(swaps.data, swaps.size, file->GetFormVersion());
            break;
        }
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:  // MICO
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353: {  // SCRI
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x54534544:  // DEST
        case 0x44545344:  // DSTD
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59: {  // YNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetPickupSound(reinterpret_cast<TESSound*>(soundID));
            break;
        }
        case 0x4d414e5a: {  // ZNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetPutdownSound(reinterpret_cast<TESSound*>(soundID));
            break;
        }
        case 0x41544144:  // DATA
            ReadTypedData(file, 0, 0);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00519cc0
TESObjectIMOD::TESObjectIMOD()
{
    SetFormType(kIMOD);
    SetInitializationState(true);
}

struct FUN_0051a5d0_shell
{
    void __thiscall LoadGame2(unsigned int, unsigned int);
};

struct TESFormStub
{
    void __thiscall FUN_00484c50(unsigned int, unsigned int);
};
struct TESValueFormStub
{
    void __thiscall FUN_0048ea10(unsigned int, unsigned int);
};

// @fnv 0x0051a5d0
void __thiscall FUN_0051a5d0_shell::LoadGame2(unsigned int arg1, unsigned int arg2)
{
    reinterpret_cast<TESFormStub*>(this)->FUN_00484c50(arg1, arg2);
    reinterpret_cast<TESValueFormStub*>(reinterpret_cast<char*>(this) + 0x7c)->FUN_0048ea10(arg1, arg2);
}

struct BGSLoadFormBuffer;

struct FUN_0051a630_shell : public TESObjectIMOD
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct TESFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct TESValueFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0051a630
void FUN_0051a630_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormLoadGame*>(this)->LoadGame(buffer);
    reinterpret_cast<TESValueFormLoadGame*>(reinterpret_cast<char*>(this) + 0x7c)->LoadGame(buffer);
}

struct FUN_00519e40_shell : public TESObjectIMOD
{
    void* __thiscall FUN_00519e40(unsigned int flags);
};

extern "C" void __cdecl _Deallocate(void*);
struct FUN_00519e70_stub
{
    void __thiscall FUN_00519e70();
};

// Calls FUN_00519e70 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00519e40
void* FUN_00519e40_shell::FUN_00519e40(unsigned int flags)
{
    ((FUN_00519e70_stub*)this)->FUN_00519e70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};

struct FUN_0048e9b0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};

struct FUN_0051a550_shell
{
    unsigned short __thiscall FUN_0051a550(unsigned int aiFlags);
};

// Returns the sum of the save sizes reported by this object and the object at offset 0x7c, both queried with aiFlags.
// @fnv 0x0051a550
unsigned short __thiscall FUN_0051a550_shell::FUN_0051a550(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += ((FUN_0048e9b0*)((char*)this + 0x7c))->GetSaveSize(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
    void __thiscall FUN_00484c20(unsigned int);
    void __thiscall FUN_0048e9e0(unsigned int);
};

struct FUN_0051a5a0_shell
{
    void __thiscall SaveGame(unsigned int aiFlags);
};

// @fnv 0x0051a5a0
void __thiscall FUN_0051a5a0_shell::SaveGame(unsigned int aiFlags)
{
    reinterpret_cast<FUN_0051b070_shell*>(this)->FUN_00484c20(aiFlags);
    reinterpret_cast<FUN_0051b070_shell*>(reinterpret_cast<char*>(this) + 0x7c)->FUN_0048e9e0(aiFlags);
}

struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
    void __thiscall SaveIfChanged(BGSSaveFormBuffer*);
};
struct FUN_0048ea40_holder
{
    void __thiscall FUN_0048ea40(BGSSaveFormBuffer*);
};
struct FUN_0051a600_shell
{
    void __thiscall AppendSaveLoadFormBuffer(BGSSaveFormBuffer* buffer);
};

// Calls SaveIfChanged on this and FUN_0048ea40 on the sub-object at offset 0x7c, passing the save buffer to both.
// @fnv 0x0051a600
void __thiscall FUN_0051a600_shell::AppendSaveLoadFormBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(buffer);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x7c)->FUN_0048ea40(buffer);
}

struct S_00477f20
{
    void __thiscall FUN_00477f20();
};
struct S_00487010
{
    void __thiscall FUN_00487010();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void __thiscall FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
};
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
    void __thiscall FUN_00485e00();
};
struct FUN_0047a240_holder
{
    void __thiscall FUN_0047a240(unsigned int);
};
struct FUN_0047b560_holder
{
    void __thiscall LogFormIDs();
};
struct FUN_0048e370_holder
{
    void __thiscall FUN_0048e370(unsigned int);
};

struct FUN_0051a420_shell : public TESObjectIMOD
{
    void SaveForm();
};

// @fnv 0x0051a420
void FUN_0051a420_shell::SaveForm()
{
    ((FUN_004855a0*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->FUN_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_holder*)((char*)this + 0x5c))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_holder*)((char*)this + 0x94))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->FUN_0048cca0();
    ((FUN_00482cb0_shell*)((char*)this + 0x74))->FUN_00482cb0();
    ((S_00477f20*)((char*)this + 0x8c))->FUN_00477f20();
    ((FUN_0047b560_holder*)((char*)this + 0xa4))->LogFormIDs();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    ((FUN_00485680*)this)->M();
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct S_0051a4c0
{
    void CopyFrom(TESForm* apCopy);
};
// Casts apCopy to TESObjectIMOD and, if the cast succeeds, forwards it to FUN_004851b0 on this object.
// @fnv 0x0051a4c0
void S_0051a4c0::CopyFrom(TESForm* apCopy)
{
    TESObjectIMOD* pmisc = dynamic_cast<TESObjectIMOD*>(apCopy);
    if (!pmisc)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0(apCopy);
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
struct FUN_0051a500_holder
{
    bool Compare(TESForm* apCompare);
};
// Casts apCompare to TESObjectIMOD; returns true if the cast fails or if FUN_00485270 reports a match, otherwise false.
// @fnv 0x0051a500
bool FUN_0051a500_holder::Compare(TESForm* apCompare)
{
    TESObjectIMOD* pcomp;
    pcomp = dynamic_cast<TESObjectIMOD*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;
    return false;
}

class FUN_00519e70 : public TESBoundObject,
                     public TESFullName,
                     public TESModelTextureSwap,
                     public TESIcon,
                     public TESScriptableForm,
                     public TESDescription,
                     public TESValueForm,
                     public TESWeightForm,
                     public BGSDestructibleObjectForm,
                     public BGSMessageIcon,
                     public BGSPickupPutdownSounds
{
  public:
    void Shutdown();
    ~FUN_00519e70();
};
// @fnv 0x00519e70
FUN_00519e70::~FUN_00519e70()
{
    Shutdown();
}

struct FUN_0051a840 : TESBoundObject,
                      TESFullName,
                      TESModelTextureSwap,
                      TESIcon,
                      TESScriptableForm,
                      TESValueForm,
                      TESWeightForm,
                      BGSDestructibleObjectForm,
                      BGSMessageIcon,
                      BGSPickupPutdownSounds
{
    virtual ~FUN_0051a840();
    void FUN_00483710();
};
// @fnv 0x0051a840
FUN_0051a840::~FUN_0051a840()
{
    FUN_00483710();
}

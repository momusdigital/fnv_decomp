
// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSFileEntry;
struct FileFormCollection;
struct TESFile;
struct TESForm;
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct FUN_00488ff0_shell : public FileEntryList
{
    void FUN_00488ff0();
};

struct FUN_00489620_t
{
    void ClearTextureList();
};

// @fnv 0x00488ff0
void FUN_00488ff0_shell::FUN_00488ff0()
{
    ((FUN_00489620_t*)this)->ClearTextureList();
}

namespace fnv_00489620 {
struct BSFileEntry;
struct FileFormCollection;
struct TESFile;
struct TESForm;
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct FUN_00489620_shell : public FileEntryList
{
    bool ClearTextureList();
};

extern void __cdecl _Deallocate(void*);

// Frees the texture offset array if present, nulls it, resets the texture count, and returns whether anything was freed.
// @fnv 0x00489620
bool FUN_00489620_shell::ClearTextureList()
{
    bool bresult = false;
    if (m_ppFileEntries)
    {
        BSFileEntry** p = m_ppFileEntries;
        _Deallocate(p);
        m_ppFileEntries = 0;
        bresult = true;
    }
    m_ucFileEntryCount = 0;
    return bresult;
}
}  // namespace fnv_00489620

struct FUN_008c1be0_shell
{
    void FUN_008c1be0(int param_1);
};

void FUN_008c1be0_shell::FUN_008c1be0(int param_1)
{}

struct FUN_004898c0_shell
{
    void FUN_004898c0(int param_1);
};

// @fnv 0x004898c0
void FUN_004898c0_shell::FUN_004898c0(int param_1)
{
    ((FUN_008c1be0_shell*)((char*)this + 0xc))->FUN_008c1be0(param_1);
}

extern bool DAT_011acdf8;

// @fnv 0x004898e0
bool FUN_004898e0()
{
    return DAT_011acdf8;
}

struct FUN_004890e0_shell
{
    void ForwardToMember();
};

// @fnv 0x004890e0
void FUN_004890e0_shell::ForwardToMember()
{
    ((FUN_00489620_t*)((char*)this + 0xc))->ClearTextureList();
}

struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* __thiscall FUN_00489860(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};

// Stores the four byte arguments into b0..b3 and the int argument into i4, then returns this as an unsigned char pointer.
// @fnv 0x00489860
unsigned char* __thiscall FUN_00489860_shell::FUN_00489860(unsigned char aucByte0, unsigned char aucByte1,
                                                           unsigned char aucByte2, unsigned char aucByte3, int aiValue)
{
    b0 = aucByte0;
    b1 = aucByte1;
    b2 = aucByte2;
    b3 = aucByte3;
    i4 = aiValue;
    return (unsigned char*)this;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct ContainerItemExtra;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESHealthForm;
struct TESNPC;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESLeveledList : public BaseFormComponent
{
    virtual unsigned char GetChanceNone();
    virtual bool UsesAllEntries();
    virtual int GetMaxLevelDifference();
    virtual void ErrorCheckList();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void SetChanceNone(unsigned char);
    bool GetCalcAllBelow();
    void SetCalcAllBelow(bool);
    void SetMultCalc(bool);
    bool GetUseAll();
    void SetUseAll(bool);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal*);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void DeleteLeveledObject(LeveledObject*);
    void SelectLeveledObject(unsigned short, TESForm**, unsigned short*, ContainerItemExtra**, bool, int);
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, TESContainer*, int);
    void PopulateContainerFromReference(TESObjectREFR*, TESContainer*);
    void ClearScriptAddedLeveledObjects();
    void AddScriptAddedLeveledObject(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESLeveledList* GetFormAsLeveledList(TESForm*);
    void* GetLeveledList();
    void* __vecDelDtor(unsigned int);
    char leveledList[8];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    char _pad_e[2];
    TESGlobal* m_pLevelGlobal;
    char m_kLeveledObjects[8];
};
typedef char _sizecheck_TESLeveledList[sizeof(TESLeveledList) == 28 ? 1 : -1];
struct FUN_00487a00_shell : public TESLeveledList
{
    void FUN_00487a00(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
};

struct G2
{
    void AddHead(LeveledObject*&);
};
struct FakeOwner
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18(unsigned int);
};
// @fnv 0x00487a00
void FUN_00487a00_shell::FUN_00487a00(TESForm* apOwner, unsigned short asLevel, unsigned short asCount, TESForm* apForm,
                                      ContainerItemExtra* apExtra)
{
    LeveledObject* plev = CreateLeveledObject(asLevel, asCount, apForm, apExtra);
    if (plev)
    {
        ((G2*)m_kLeveledObjects)->AddHead(plev);
        ((FakeOwner*)apOwner)->a18(0x80000000);
    }
}

struct TESModel
{
    virtual ~TESModel();
    void* FUN_00489010(unsigned int flags);
};
void __cdecl _Deallocate(void*);
// Calls the TESModel destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x00489010
void* TESModel::FUN_00489010(unsigned int flags)
{
    this->TESModel::~TESModel();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00489040_shell
{
    char b0;
    char b1;
    char b2;
    char b3;
    BSStr FullNameComponent;
    void ClearString();
};
// If the BSStr member converts to a nonzero value, clears it via Set(0, 0), then zeroes the byte at offset 0x14.
// @fnv 0x00489040
void FUN_00489040_shell::ClearString()
{
    if ((Flt&)FullNameComponent)
        FullNameComponent.Set(0, 0);
    *(unsigned char*)((char*)this + 0x14) = 0;
}

struct FUN_004898a0_shell : public FUN_004898c0_shell
{
    int FUN_004898c0(int param_1);
    bool FUN_004898a0();
};

// @fnv 0x004898a0
bool FUN_004898a0_shell::FUN_004898a0()
{
    return FUN_004898c0(256) != 0;
}

namespace fnv_004898f0 {
struct Flt
{
    operator unsigned int();
    int v;
};
extern Flt DAT_011f8190[];
extern Flt DAT_011f81b4[];
// Returns the value at index param_1 from DAT_011f8190 if nonzero, otherwise from DAT_011f81b4.
// @fnv 0x004898f0
unsigned int GetFltValue(int aiIndex)
{
    Flt* b;
    {
        Flt* a;
        if ((unsigned int)DAT_011f8190[aiIndex])
            a = &DAT_011f8190[aiIndex];
        else
            a = &DAT_011f81b4[aiIndex];
        b = a;
    }
    return (unsigned int)*b;
}
}  // namespace fnv_004898f0

namespace fnv_00489940 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSFileEntry;
struct FileFormCollection;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBitArrayFile;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct blob8
{
    char b[8];
};
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00489940_shell : public FileEntryList
{
    void LoadChunkData(TESFile*, TESForm*, char*);
};

struct TESFile
{
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
};
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
// @fnv 0x00489940
void FUN_00489940_shell::LoadChunkData(TESFile* file, TESForm* form, char* name)
{
    unsigned int isize = file->GetChunkSize();
    if (isize % 24)
        return;
    unsigned int icount = isize / 24;
    int iusablesize = icount * 24;
    if (icount)
    {
        FileFormCollection* pdata = (FileFormCollection*)_alloca(iusablesize);
        memset(pdata, 0, iusablesize);
        file->GetChunkData(pdata, iusablesize);
        WriteFileEntryToBuffer(pdata, icount, form, name);
    }
}
}  // namespace fnv_00489940

struct FUN_004f9ec0_shell
{
    void CallInnerMethod();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls CallInnerMethod, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004f9ec0
void* FUN_004f9ec0_shell::DestroyIfFlagged(unsigned int flags)
{
    CallInnerMethod();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct SpawnedBase
{
    virtual void unk00();
    SpawnedBase();
};

struct SubObjA
{
    int unk00;
    int unk04;
    SubObjA();
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    int unk04;
    SubObjB();
    ~SubObjB();
};

struct FUN_00488f50_cls : SpawnedBase
{
    SubObjA m_04;
    SubObjB m_0c;

    FUN_00488f50_cls();
    virtual void unk00();
    void ClearString();
};

// @fnv 0x00488f50
FUN_00488f50_cls::FUN_00488f50_cls()
{
    ClearString();
}

struct FUN_00489120_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    void SetFarPath(char* path);
};

void __cdecl FUN_00406d30(char* dst, int maxLen, const char* src);
char* __cdecl FUN_0040ab30(const char* s, int ch);

// @fnv 0x00489120
void FUN_00489120_cls::SetFarPath(char* path)
{
    char* ext;
    FUN_00406d30(path, 0x104, GetPath());
    ext = FUN_0040ab30(path, 0x2e);
    if (ext != 0)
    {
        FUN_00406d30(ext, 0x104 - (ext - path), "_far.NIF");
    }
}

class B479FB0Actor;

class B479FB0Idle
{
  public:
    bool FUN_005ff430(B479FB0Actor* pkActor, int iArg, bool bFlag);
};

class B479FB0Actor
{
  public:
    bool HasIdleInFormArray(B479FB0Idle* pkIdle);
};

class B479FB0IdleList
{
  public:
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    unsigned char m_ucCount;
    short unk06;
    B479FB0Idle** m_ppkIdles;

    bool HasIdleForActor(B479FB0Actor* pkActor, int iArg);
};

// @fnv 0x00479fb0
bool B479FB0IdleList::HasIdleForActor(B479FB0Actor* pkActor, int iArg)
{
    if (pkActor)
    {
        for (int i = 0; i < m_ucCount; i++)
        {
            B479FB0Idle* pkIdle = m_ppkIdles[i];
            if (pkIdle && pkActor->HasIdleInFormArray(pkIdle) && pkIdle->FUN_005ff430(pkActor, iArg, true))
                return true;
        }
    }
    return false;
}

struct FUN_00488fd0_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    void* FUN_00488fd0();
};

// @fnv 0x00488fd0
void* FUN_00488fd0_shell::FUN_00488fd0()
{
    b0 = 0;
    i4 = 0;
    return this;
}

// Destructor: clear the entries; the entry list and the name string are destroyed afterwards.

class B9070String
{
  public:
    ~B9070String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class B9070List
{
  public:
    ~B9070List();
    void* m_pkHead;
    void* m_pkNext;
};

class FUN_00489070
{
  public:
    virtual ~FUN_00489070();
    void Clear();

    B9070String m_kName;
    B9070List m_kEntries;
};

// @fnv 0x00489070
FUN_00489070::~FUN_00489070()
{
    Clear();
}

int __cdecl B489480Stricmp(const char* pcA, const char* pcB);

struct FUN_00489480_shell : public TESModel
{
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual const char* GetModelPath();

    bool IsModelPathDifferent(BaseFormComponent* pkComponent);
};

// @fnv 0x00489480
bool FUN_00489480_shell::IsModelPathDifferent(BaseFormComponent* pkComponent)
{
    FUN_00489480_shell* pkOther = static_cast<FUN_00489480_shell*>(dynamic_cast<TESModel*>(pkComponent));
    if (!pkOther)
        return true;
    const char* pcPath = GetModelPath();
    {
        const char* pcOtherPath = pkOther->GetModelPath();
        if (pcPath && pcOtherPath)
        {
            if (B489480Stricmp(pcPath, pcOtherPath))
                return true;
        }
        else if (!pcPath || !pcOtherPath)
        {
            if (pcPath && *pcPath)
                return true;
            if (pcOtherPath && *pcOtherPath)
                return true;
        }
    }
    return false;
}

struct FUN_004898a0_shell;
struct FUN_00489860_shell;
struct Elem
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    int unk08;
    int unk0c;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    int i14;
};
struct ModelRef
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void unk2F();
    virtual void unk30();
    virtual void unk31();
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual void unk38();
    virtual void unk39();
    virtual void unk3A();
    virtual void unk3B();
    virtual void unk3C();
    virtual void unk3D();
    virtual void unk3E();
    virtual void unk3F();
    virtual void unk40();
    virtual void unk41();
    virtual void unk42();
    virtual void unk43();
    virtual void unk44();
    virtual void unk45();
    virtual void unk46();
    virtual void unk47();
    virtual void unk48();
    virtual void unk49();
    virtual void unk4A();
    virtual void unk4B();
    virtual const char* GetEditorName();
    unsigned int FUN_0084e3a0();
};
struct FUN_00408d60_shell
{
    unsigned char* FUN_00408d60();
};
struct Cls
{
    unsigned char m_00;
    unsigned int* m_04;
    void LoadTextureArchiveEntries(Elem* arr, unsigned int count, ModelRef* form, const char* model);
};
extern char DAT_011c5574;
extern char DAT_011c555c;
FUN_004898a0_shell* __cdecl GetFltValue(int);
bool __cdecl FUN_004898e0();
unsigned int __cdecl FindFileEntryInArchives(int, FUN_00489860_shell*, FUN_00489860_shell*, int);
void __cdecl FUN_005b5e40(const char* fmt, ...);

// Stores the count and allocates an array, then for each Elem builds two keys, looks up an archive entry, and logs a warning when the lookup fails.
// @fnv 0x00489670
void Cls::LoadTextureArchiveEntries(Elem* aElems, unsigned int count, ModelRef* form, const char* model)
{
    FUN_004898a0_shell* s = GetFltValue(1);
    if (!(s != 0 && ((FUN_004898a0_shell*)((char*)s + 0x160))->FUN_004898a0() &&
          *((FUN_00408d60_shell*)&DAT_011c5574)->FUN_00408d60() != 0))
        return;
    m_00 = (unsigned char)count;
    m_04 = new unsigned int[count];
    for (unsigned int i = 0; i < count; i++)
    {
        FUN_00489860_shell key0;
        key0.FUN_00489860(aElems[i].b0, aElems[i].b1, aElems[i].b2, aElems[i].b3, aElems[i].i4);
        FUN_00489860_shell key1;
        key1.FUN_00489860(aElems[i].c0, aElems[i].c1, aElems[i].c2, aElems[i].c3, aElems[i].i14);
        m_04[i] = FindFileEntryInArchives(1, &key1, &key0, 0);
        if (*((FUN_00408d60_shell*)&DAT_011c555c)->FUN_00408d60() != 0)
        {
            if (FUN_004898e0())
            {
                if (m_04[i] == 0)
                {
                    if (form != 0 && model != 0)
                    {
                        FUN_005b5e40(
                            "MASTERFILE: Failed to find archive file entry for texture on model '%s' for form %s (%08X).",
                            model, form->GetEditorName(), form->FUN_0084e3a0());
                    }
                    else if (model != 0)
                    {
                        FUN_005b5e40(
                            "MASTERFILE: Failed to find archive file entry for texture on model '%s' on UNKNOWN form.",
                            model);
                    }
                    else
                    {
                        FUN_005b5e40("MASTERFILE: Failed to find archive file entry for texture on UNKNOWN Model");
                    }
                }
            }
        }
    }
}

void __cdecl FUN_004856f0(char* pcDest, const char* pcSrc, unsigned int uiSize);

struct FUN_004891d0_hash
{
    void FUN_008d0600(void* pkOut, const char* pcPath);
};

struct FUN_004891d0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    int unk04;
    int unk08;
    FUN_004891d0_hash m_kObjectMap;
    unsigned int FUN_0048cee0();
    void WriteToBuffer(char* pcBuffer, void* pkOut);
};

// When FUN_0048cee0() is nonzero, copies GetPath() to pcBuffer and passes pkOut and GetPath() to m_kObjectMap.FUN_008d0600.
// @fnv 0x004891d0
void FUN_004891d0_cls::WriteToBuffer(char* pcBuffer, void* pkOut)
{
    if (FUN_0048cee0())
    {
        if (pcBuffer)
            FUN_004856f0(pcBuffer, GetPath(), FUN_0048cee0() + 1);
        if (pkOut)
            m_kObjectMap.FUN_008d0600(pkOut, GetPath());
    }
}

struct TESForm;
struct TESObjectREFR;
struct FUN_004895b0_model
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
};

extern "C" void* __cdecl FNV_DynamicCast(void* inptr, long vfDelta, void* srcType, void* targetType, int isReference);
extern "C" char FNV_RTTI_TESForm;
extern "C" char FNV_RTTI_TESObjectREFR;
extern unsigned char DAT_011831e8;

FUN_004895b0_model* GetWorldTESModel(TESForm* form, TESObjectREFR* ref);

// Calls FNV_DynamicCast and GetWorldTESModel, then returns v5() or an empty string.
// @fnv 0x004895b0
const char* GetModel(TESForm* apForm)
{
    FUN_004895b0_model* m = (FUN_004895b0_model*)FNV_DynamicCast(apForm, 0, &FNV_RTTI_TESForm, &DAT_011831e8, 0);
    if (m == 0)
    {
        m = GetWorldTESModel(apForm,
                         (TESObjectREFR*)FNV_DynamicCast(apForm, 0, &FNV_RTTI_TESForm, &FNV_RTTI_TESObjectREFR, 0));
    }
    if (m != 0)
    {
        return m->v5();
    }
    return "";
}

struct TESForm
{
    virtual ~TESForm();
};

struct DistantModelView : TESModel
{
    void SetFarPath(char*);
};
// If apForm is a TESModel, cast it to DistantModelView and call FUN_00489120 with apModelName.
// @fnv 0x00489190
void GetDistantModelName(char* apModelName, TESForm* apForm)
{
    TESModel* pmodel;
    if (apForm)
    {
        pmodel = dynamic_cast<TESModel*>(apForm);
        if (pmodel)
        {
            static_cast<DistantModelView*>(pmodel)->SetFarPath(apModelName);
        }
    }
}

struct TextureModelView : TESModel
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    char* modelName;
    unsigned short nameLength;
    unsigned short nameCapacity;
    FileEntryList textures;
};
// Loads texture file entries into the model's texture list from the given file, using the model's path and form context.
// @fnv 0x004893e0
void FUN_004893e0(TESModel* model, TESFile* file)
{
    if (model && file)
        static_cast<TextureModelView*>(model)->textures.Load(file, dynamic_cast<TESForm*>(model),
                                                             static_cast<TextureModelView*>(model)->GetPath());
}

struct ModelCopyView : TESModel
{
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual int GetFlags();
    virtual void SetFlags(int flags);
    void CopyComponent(BaseFormComponent* component);
};

// Copies the flags from a BaseFormComponent cast to TESModel into this ModelCopyView.
// @fnv 0x00489430
void ModelCopyView::CopyComponent(BaseFormComponent* component)
{
    TESModel* copy = dynamic_cast<TESModel*>(component);
    if (copy == 0)
        return;
    SetFlags(reinterpret_cast<ModelCopyView*>(copy)->GetFlags());
}

// @fnv 0x00489540
unsigned int __cdecl GetModelLength(void* apForm)
{
    void* result;

    result = ::FNV_DynamicCast(apForm, 0, &::FNV_RTTI_TESForm, &::DAT_011831e8, 0);
    if (result == 0)
    {
        result = ::GetWorldTESModel((::TESForm*)apForm, (::TESObjectREFR*)::FNV_DynamicCast(apForm, 0, &::FNV_RTTI_TESForm,
                                                                                        &::FNV_RTTI_TESObjectREFR, 0));
    }
    if (result != 0)
    {
        return ((::FUN_004891d0_cls*)result)->FUN_0048cee0();
    }
    return 0;
}

struct WorldModelEntry481010
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};

class TESBipedModelForm : public BaseFormComponent
{
  public:
    unsigned int partMask;
    unsigned int flags;
    WorldModelEntry481010 maleBipedModel;
    WorldModelEntry481010 femaleBipedModel;
    FUN_004895b0_model worldModel;

    FUN_004895b0_model* GetWorldModel(int sex);
};

struct ReferenceOwnerView481010
{
    TESForm* FUN_00567790();
};

struct ActorSexView481010
{
    int FUN_005f0cc0();
};

int __fastcall _FNV_GetFormType(TESForm*);

// Returns the biped model for a TESBipedModelForm, selecting the male or female variant based on the owner actor's sex when a reference is provided.
// @fnv 0x00481010
FUN_004895b0_model* __cdecl GetWorldTESModel(TESForm* apBipedModelForm, TESObjectREFR* apReference)
{
    TESBipedModelForm* sex = dynamic_cast<TESBipedModelForm*>(apBipedModelForm);
    TESForm* biped;
    int iOwnerSex;

    if (sex == 0)
        return 0;
    if (apReference == 0)
        return &sex->worldModel;

    biped = reinterpret_cast<ReferenceOwnerView481010*>(apReference)->FUN_00567790();
    iOwnerSex = 0;
    if (biped != 0 && _FNV_GetFormType(biped) == 0x2a)
        iOwnerSex = reinterpret_cast<ActorSexView481010*>(biped)->FUN_005f0cc0();
    return sex->GetWorldModel(iOwnerSex);
}


// src/fallout/misc/saveload/bgsloadgamebuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgsloadgamebuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
};

struct FUN_00835f80_shell
{
    char _0[0x1c];
    char _1c;
    char _1d;
    char _1e;
    char _1f;
    void FUN_00835f80(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x00835f80
void __thiscall FUN_00835f80_shell::FUN_00835f80(BGSLoadFormBuffer* apBuffer)
{
    apBuffer->ReadFormIdentifier(this);
    apBuffer->ReadTypedData(&this->_1c, 1);
    apBuffer->ReadTypedData(&this->_1d, 1);
    apBuffer->ReadTypedData(&this->_1e, 1);
    apBuffer->ReadTypedData(&this->_1f, 1);
}

struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00864720_shell : public BGSLoadGameBuffer
{
    unsigned char FUN_00864720();
};

struct BGSSaveLoadGame
{
    unsigned char GetLoadState(void);
};

BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x00864720
unsigned char FUN_00864720_shell::FUN_00864720()
{
    return g_BGSSaveLoadGame->GetLoadState();
}

namespace fnv_008647f0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_008647f0_shell : public BGSLoadGameBuffer
{
    void FUN_008647f0(char*, unsigned int, unsigned int);
};

// Initializes the load buffer with the given buffer pointer, size and position.
// @fnv 0x008647f0
void FUN_008647f0_shell::FUN_008647f0(char* apBuffer, unsigned int aiSize, unsigned int aiPosition)
{
    pBuffer = apBuffer;
    iBufferSize = aiSize;
    m_uiReadOffset = aiPosition;
}
}  // namespace fnv_008647f0

namespace fnv_00864980 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00864980_shell : public BGSLoadGameBuffer
{
    void LoadData(NiQuaternion*, unsigned int);
};

// @fnv 0x00864980
void FUN_00864980_shell::LoadData(NiQuaternion* apData, unsigned int aiSize)
{
    ReadTypedData(apData, aiSize);
}
}  // namespace fnv_00864980

namespace fnv_009f38b0 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct SandboxProcedureData
{
    TESObjectREFR* GetTarget();
    int GetSandboxProcedure();
    int GetBaseScore();
    int GetFullScore();
    void SetFullScore(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    TESObjectREFR* pTarget;
    int eProcedure;
    int m_iActivityState;
    int m_iProcedureData;
};
typedef char _sizecheck_SandBoxChoiceListItem[sizeof(SandboxProcedureData) == 16 ? 1 : -1];
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_009f38b0_shell : public SandboxProcedureData
{
    void FUN_009f38b0(BGSLoadFormBuffer*);
};

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    bool ReadFormIdentifier(void*);
};

// @fnv 0x009f38b0
void FUN_009f38b0_shell::FUN_009f38b0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(&eProcedure, 4);
    apLoadGameBuffer->ReadTypedData(&m_iActivityState, 4);
    apLoadGameBuffer->ReadTypedData(&m_iProcedureData, 4);
    apLoadGameBuffer->ReadFormIdentifier(&pTarget);
}
}  // namespace fnv_009f38b0

struct SaveGameLoader
{
    static bool __cdecl LoadFormRange(unsigned int, BGSLoadGameBuffer*, unsigned char);
};

struct LGB : public BGSLoadGameBuffer
{
    LGB();
    ~LGB();
};

// @fnv 0x0084c2a0
void FUN_0084c2a0(unsigned int start, unsigned int end, unsigned char flag)
{
    LGB lgb;
    for (unsigned int uiIndex = start; uiIndex < end; uiIndex++)
    {
        SaveGameLoader::LoadFormRange(uiIndex, &lgb, flag);
    }
}

namespace fnv_00864820 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00864820_shell : public BGSLoadGameBuffer
{
    void LoadRawData(void*, unsigned int);
};

extern "C" void* __cdecl __memcpy(void*, void*, unsigned int);
void __cdecl _fnv_call_845cc0(const char*);

// Copies aiSize bytes from the load buffer into apData, advances the offset, and checks that the next byte is the '|' spacer.
// @fnv 0x00864820
void FUN_00864820_shell::LoadRawData(void* apData, unsigned int aiSize)
{
    if (iBufferSize == 0)
    {
        return;
    }
    __memcpy(apData, pBuffer + m_uiReadOffset, aiSize);
    m_uiReadOffset += aiSize;
    if (pBuffer[m_uiReadOffset] != '|')
    {
        _fnv_call_845cc0("SAVELOAD: Invalid spacer hit while loading data from the buffer");
    }
    m_uiReadOffset += 1;
}
}  // namespace fnv_00864820

extern "C" void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_00857bd0
{
    void Init(unsigned int);
};
struct FUN_008579e0_shell
{
    char _0[0x14];
    void* _14;
    void LoadGameDataOLD(void* dst, unsigned int size);
};
// Copies size bytes from the object's _14 pointer into dst, then calls Init(size) on this.
// @fnv 0x008579e0
void FUN_008579e0_shell::LoadGameDataOLD(void* dst, unsigned int size)
{
    __memcpy(dst, _14, size);
    ((FUN_00857bd0*)this)->Init(size);
}

struct FUN_008646b0
{
    virtual unsigned char GetVersion();
    virtual void* GetForm();
    virtual void* GetReference();
    virtual void* GetActor();
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    FUN_008646b0();
};
// Initializes pBuffer, iBufferSize and the third field to zero.
// @fnv 0x008646b0
FUN_008646b0::FUN_008646b0()
{
    pBuffer = 0;
    iBufferSize = 0;
    m_uiReadOffset = 0;
}

namespace fnv_008646f0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_008646f0_shell : public BGSLoadGameBuffer
{
    void FUN_008646f0();
};

extern int DAT_01082048;

// @fnv 0x008646f0
void FUN_008646f0_shell::FUN_008646f0()
{
    char* p;
    *(char**)this = (char*)&DAT_01082048;
    p = (char*)pBuffer;
    operator delete(p);
}
}  // namespace fnv_008646f0

struct S_00864540
{
    int ReadFromFile(int, int);
};
void ReadFileIntoBuffer(SaveLoadFile*, unsigned int*, unsigned int);
struct FUN_00864740_shell
{
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    int __thiscall ReadAndVerifySize(SaveLoadFile* apFile);
};
// @fnv 0x00864740
int __thiscall FUN_00864740_shell::ReadAndVerifySize(SaveLoadFile* apFile)
{
    ReadFileIntoBuffer(apFile, &m_uiReadOffset, 4);
    int result = ((S_00864540*)this)->ReadFromFile((int)apFile, m_uiReadOffset);
    if (result != m_uiReadOffset)
        return -1;
    return result;
}

struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
};
struct FUN_00864790_shell
{
    void* p;
    char* buffer;
    unsigned int size;
    int ReadFromFile(SaveLoadFile* file, unsigned int n);
};
// Allocates a buffer of n bytes, reads n bytes from file into it, and returns the byte count or -1 on a short read.
// @fnv 0x00864790
int FUN_00864790_shell::ReadFromFile(SaveLoadFile* file, unsigned int uiSize)
{
    size = uiSize;
    char* buf = (char*)operator new(size);
    buffer = buf;
    unsigned int read = file->Read(buffer, size);
    if (read != size)
        return -1;
    return (int)read;
}

namespace fnv_008648a0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];
struct FUN_008648a0_shell : public BGSLoadGameBuffer
{
    bool LoadFormID(unsigned int*);
};

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
unsigned int __fastcall FUN_00853500(void*);
struct FUN_00864820_wrap
{
    void LoadRawData(void*, unsigned int);
};
struct FUN_008648a0_t : public BGSLoadGameBuffer
{
    unsigned int LoadFormID();
};
// @fnv 0x008648a0
unsigned int FUN_008648a0_t::LoadFormID()
{
    unsigned int iformID;
    PackedFormID formIDIndex;
    ((Dummy84eaf0*)&formIDIndex)->ClearNumericIDIndex();
    ((FUN_00864820_wrap*)this)->LoadRawData(&formIDIndex, 3);
    iformID = FUN_00853500(&formIDIndex);
    return iformID;
}
}  // namespace fnv_008648a0

namespace fnv_008648e0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];
struct FUN_008648e0_shell : public BGSLoadGameBuffer
{
    bool FUN_008648e0(unsigned int*);
};

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
unsigned int __fastcall FUN_00853500(void*);
bool __fastcall FUN_00864940(void*);
struct FUN_00864820_t
{
    void LoadRawData(void*, unsigned int);
};
// @fnv 0x008648e0
bool FUN_008648e0_shell::FUN_008648e0(unsigned int* aiFormID)
{
    PackedFormID formIDIndex;
    ((Dummy84eaf0*)&formIDIndex)->ClearNumericIDIndex();
    ((FUN_00864820_t*)this)->LoadRawData(&formIDIndex, 3);
    *aiFormID = FUN_00853500(&formIDIndex);
    return !FUN_00864940(&formIDIndex) && *aiFormID == 0;
}
}  // namespace fnv_008648e0

struct FUN_00864940_shell
{
    unsigned char FUN_00864940();
};

// Returns 1 if the first three bytes at this are all zero, otherwise 0.
// @fnv 0x00864940
unsigned char FUN_00864940_shell::FUN_00864940()
{
    return (!(unsigned char)*reinterpret_cast<char*>(this) && !(unsigned char)reinterpret_cast<char*>(this)[1] &&
            !(unsigned char)reinterpret_cast<char*>(this)[2])
               ? 1
               : 0;
}

namespace fnv_008649a0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_008649a0_shell : public BGSLoadGameBuffer
{
    char* FUN_008649a0(char*);
};

struct FUN_00864820_shell
{
    void LoadRawData(void*, unsigned int);
};

// @fnv 0x008649a0
char* FUN_008649a0_shell::FUN_008649a0(char* apString)
{
    unsigned short slength = 0;
    reinterpret_cast<FUN_00864820_shell*>(this)->LoadRawData(&slength, 2);
    if (slength)
    {
        if (!apString)
        {
            char* p = static_cast<char*>(operator new(slength + 1));
            apString = p;
        }
        reinterpret_cast<FUN_00864820_shell*>(this)->LoadRawData(apString, slength);
        apString[slength] = 0;
    }
    else if (apString)
    {
        apString[0] = 0;
    }
    return apString;
}
}  // namespace fnv_008649a0

namespace fnv_0043aaa0 {
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    bool ReadFormIdentifier(void*);
};

struct FUN_0043aaa0_shell
{
    char pad1[4];
    char pad2[4];
    char pad3[4];
    char pad4[4];
    char pad5[4];
    char pad6[4];
    char pad7[4];
    char pad8[4];
    char pad9[4];
    char pad10[4];
    char pad11[4];
    char pad12[4];
    char pad13[4];
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0043aaa0
void FUN_0043aaa0_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((char*)this + 4, 0xc);
    buffer->ReadTypedData((char*)this + 0x10, 0xc);
    buffer->ReadTypedData((char*)this + 0x1c, 1);
    buffer->ReadFormIdentifier(this);
}
}  // namespace fnv_0043aaa0

struct IntSeenData
{
    virtual void Unk()
    {}
    char _pad[0x20];
    IntSeenData();
};
struct FUN_0087a100 : IntSeenData
{
    char m_cX;
    char m_cY;
    char _p[2];
    int m_i28;
    FUN_0087a100(char acSectionX, char acSectionY);
};
// Initializes the object with the given section coordinates and sets the field at offset 0x28 to zero.
// @fnv 0x0087a100
FUN_0087a100::FUN_0087a100(char acSectionX, char acSectionY)
{
    m_cX = acSectionX;
    m_cY = acSectionY;
    m_i28 = 0;
}

struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];
struct FUN_00853500_shell : public PackedFormID
{
    unsigned int FUN_00853500();
};

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00846d20_shell
{
    unsigned int FUN_00846d20(unsigned int);
};
// @fnv 0x00853500
unsigned int FUN_00853500_shell::FUN_00853500()
{
    unsigned int uiValue = (unsigned int)((unsigned char)m_ucIDByte0 << 0x10) +
                           (unsigned int)((unsigned char)m_ucIDByte1 << 8) + (unsigned int)(unsigned char)m_ucIDByte2;
    if (uiValue & 0x800000)
    {
        uiValue &= 0xff7fffff;
        uiValue |= 0xff000000;
        return uiValue;
    }
    return ((FUN_00846d20_shell*)((ArrSI*)g_BGSSaveLoadGame)->GetFlags())->FUN_00846d20(uiValue);
}

void* __cdecl operator new(unsigned int);

int DAT_011d60cc;

struct FUN_0066deb0
{
    char _pad[0x1c];

    FUN_0066deb0();
    void FUN_0066e440(BGSLoadGameBuffer*);
};

// @fnv 0x0066e750
void FUN_0066e750(BGSLoadGameBuffer* apLoadGameBuffer)
{
    unsigned int iloop;
    unsigned int isaveGameCount;

    ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData(&DAT_011d60cc, 4);
    iloop = apLoadGameBuffer->ReadElementCount();

    for (isaveGameCount = 0; isaveGameCount < iloop; ++isaveGameCount)
    {
        FUN_0066deb0* pactorCause = new FUN_0066deb0();
        pactorCause->FUN_0066e440(apLoadGameBuffer);
    }
}

struct NiQuaternion
{
    void ToRotationMatrix(ThreeByThreeMatrix&);
};

struct BaseS
{
    unsigned int _data[4];
    BaseS();
};

struct FUN_00864a20_shell : public BGSLoadFormBuffer
{
    void FUN_00864a20(ThreeByThreeMatrix& matrix, unsigned int unused);
};

// @fnv 0x00864a20
void FUN_00864a20_shell::FUN_00864a20(ThreeByThreeMatrix& matrix, unsigned int unused)
{
    BaseS quatData;
    {
        BGSLoadFormBuffer* pBuffer = this;
        pBuffer->ReadTypedData(&quatData, 0x10);
        reinterpret_cast<NiQuaternion&>(quatData).ToRotationMatrix(matrix);
    }
}

void __cdecl operator delete(void* pointer);

struct FUN_0081db60_shell
{
    void FUN_0081db90();
    FUN_0081db60_shell* FUN_0081db60(unsigned int deletingFlags);
};

// Calls FUN_0081db90, frees this with operator delete when deletingFlags has bit 0 set, and returns this.
// @fnv 0x0081db60
FUN_0081db60_shell* FUN_0081db60_shell::FUN_0081db60(unsigned int deletingFlags)
{
    FUN_0081db90();
    if (deletingFlags & 1)
    {
        ::operator delete(this);
    }
    return this;
}

namespace fnv_00864a60 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00864a60_shell : public BGSLoadGameBuffer
{
    int LoadVariableSizedValue();
};

struct FUN_00864a60_cls : public BGSLoadGameBuffer
{
    int LoadVariableSizedValue();
};

// Reads a tag byte, dispatches on its low two bits to read a 1, 2 or 4 byte value, and returns that value shifted right by two.
// @fnv 0x00864a60
int FUN_00864a60_cls::LoadVariableSizedValue()
{
    unsigned char tag = (unsigned char)pBuffer[m_uiReadOffset];
    unsigned int flags9 = tag & 3;
    switch (flags9)
    {
    case 0: {
        unsigned char value = 0;
        ReadTypedData((void*)&value, 1);
        return (int)value >> 2;
    }
    case 1: {
        unsigned short value = 0;
        ReadTypedData((void*)&value, 2);
        return (int)value >> 2;
        break;
    }
    case 2: {
        unsigned int value = 0;
        ReadTypedData((void*)&value, 4);
        return (int)(value >> 2);
    }
    }
    return 0;
}
}  // namespace fnv_00864a60

// bssystem/archive.cpp: S_af9, NP_afc, ArchiveStand, CompressedArchiveFile and more (114 functions)

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
extern "C" int __cdecl _strlwr_s(char*, unsigned int);
extern "C" const char kDataPrefix[];
extern "C" const char kTexturePrefix[];

// Skips a drive letter, leading backslash, the data prefix and optionally the textures prefix, returning the offset into path where the remainder starts.
// @fnv 0x00af4170
unsigned int __cdecl GetPathHash(const char* pcPath, bool includeTextures)
{
    const char* current = pcPath;
    if (current[1] == ':')
        current += 3;
    if (*current == '\\')
        ++current;
    if (_strnicmp(current, kDataPrefix, 5) == 0)
        current += 5;
    if (includeTextures && _strnicmp(current, kTexturePrefix, 9) == 0)
        current += 9;
    return (unsigned int)(current - pcPath);
}

// @fnv 0x00af4200
bool __cdecl CleanPath(const char* path, char* output, unsigned int outputSize)
{
    bool result = true;
    output[0] = 0;
    {
        unsigned int offset = GetPathHash(path, false);
        strcat_s(output, outputSize, path + offset);
    }
    _strlwr_s(output, outputSize);
    return result;
}

// PC file-stream hierarchy (PC layouts and vtable slot order from the PC RTTI vftables, slot names and member names
struct _iobuf;
template <class T> class BSStringT;
class Archive;

class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();                 // v00
    virtual operator bool();                   // v04
    virtual void Seek(int iNumBytes);          // v08
    virtual unsigned int GetPosition();        // v0C
    virtual void SetEndianSwap(bool bDoSwap);  // v10
    unsigned int m_uiStreamFlags;              // +0x04
    void* m_pfnRead;                           // +0x08
    void* m_pfnWrite;                          // +0x0C
};

class NiFile : public NiBinaryStream
{
  public:
    virtual void Seek(int iOffset, int iWhence);  // v14
    virtual char* FileName();                     // v18
    virtual unsigned int GetFileSize();           // v1C
    unsigned int m_uiBufferAllocSize;             // +0x10
    unsigned int m_uiBufferReadSize;              // +0x14
    unsigned int m_uiPos;                         // +0x18
    unsigned int m_uiTotalFileSize;               // +0x1C
    char* m_pBuffer;                              // +0x20
    _iobuf* m_pFile;                              // +0x24
    int m_eMode;                                  // +0x28 NiFile::OpenMode
    bool m_bGood;                                 // +0x2C
  protected:
    bool Flush();
};

class BSFile : public NiFile
{
  public:
    virtual bool Open(bool, bool);           // v20
    virtual bool AttachFileStream(_iobuf*);  // v24
    virtual unsigned int GetSize();          // v28
    // MSVC places overloads in reverse declaration order: Read(char) is v2C, Read(wchar_t) v30
    virtual unsigned int Read(BSStringT<wchar_t>&, unsigned int);
    virtual unsigned int Read(BSStringT<char>&, unsigned int);
    virtual unsigned int GetLine(char*, unsigned int, wchar_t);  // v34
    // Write(char) is v38, Write(wchar_t) v3C
    virtual unsigned int Write(const BSStringT<wchar_t>&, bool);
    virtual unsigned int Write(const BSStringT<char>&, bool);
    virtual bool Exist();                                          // v40
    virtual unsigned int ReadRawData(void*, unsigned int);         // v44
    virtual unsigned int WriteRawData(const void*, unsigned int);  // v48
    virtual void SetEndianSwap(bool doSwap);                       // v10 override
    bool m_bIsOpen;                                                // +0x30
    bool m_bEndianSwap;                                            // +0x31
    char* m_pFileBuffer;                                           // +0x34
    int m_iBufferSize;                                             // +0x38
    unsigned int m_uiFileSize;                                     // +0x3C
    unsigned int m_uiFilePosition;                                 // +0x40
    char pFileName[260];                                           // +0x44
    int iResult;                                                   // +0x148
    unsigned int m_uiBufferPosition;                               // +0x14C
    unsigned int m_uiBufferSize;                                   // +0x150
    unsigned int m_uiValueId;                                      // +0x154
};

class ArchiveFile : public BSFile
{
  public:
    virtual void SetEndianSwap(bool doSwap);  // v10 override
    Archive* m_pArchive;                      // +0x158 NiPointer<Archive> in the original
    unsigned int m_uiFileIndex;               // +0x15C
};

class CompressedArchiveFile : public ArchiveFile
{
  public:
    virtual void SetEndianSwap(bool doSwap);  // v10 override
    virtual void Seek(int offset, int mode);  // v14 override
    void* m_pArchiveStream;                   // +0x160
    char* m_pCompressedBuffer;                // +0x164
    unsigned int m_uiCompressedSize;          // +0x168
    unsigned int m_uiUncompressedSize;        // +0x16C
    unsigned int m_uiCompressedPosition;      // +0x170
    unsigned int m_uiUncompressedPosition;    // +0x174
};

typedef char _sizecheck_NiFile[sizeof(NiFile) == 0x30 ? 1 : -1];
typedef char _sizecheck_BSFile[sizeof(BSFile) == 0x158 ? 1 : -1];
typedef char _sizecheck_ArchiveFile[sizeof(ArchiveFile) == 0x160 ? 1 : -1];
typedef char _sizecheck_CompressedArchiveFile[sizeof(CompressedArchiveFile) == 0x178 ? 1 : -1];

// @fnv 0x00afbfa0
void ArchiveFile::SetEndianSwap(bool doSwap)
{
    if (doSwap)
    {
        BSFile::SetEndianSwap(doSwap);
    }
    else
    {
        m_pfnRead = reinterpret_cast<void*>(0x00afbf80);
        m_pfnWrite = reinterpret_cast<void*>(0x00aff9f0);
    }
}

// Enables endian swap via BSFile when doSwap is set, otherwise assigns the read and write function pointers.
// @fnv 0x00afc620
void CompressedArchiveFile::SetEndianSwap(bool doSwap)
{
    if (doSwap)
    {
        BSFile::SetEndianSwap(doSwap);
    }
    else
    {
        m_pfnRead = reinterpret_cast<void*>(0x00afc660);
        m_pfnWrite = reinterpret_cast<void*>(0x00aff9f0);
    }
}

// @fnv 0x00afc080
void CompressedArchiveFile::Seek(int offset, int mode)
{
    ReadRawData(0, offset);
}

// @fnv 0x0043c030
unsigned int __fastcall FUN_0043c030(const char* pThis)
{
    return *(const unsigned int*)(pThis + 0x1c8);
}

class bhkCharacterController;

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
};

struct MobileObject
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual const NiPoint3& Slot125();

    bhkCharacterController* GetPhysicsCharacterController(void);
    float GetActorHeight(void) const;
    bool IsAtPoint(const NiPoint3& targetPos, float radius, bool addCharRadius, bool check3D);
};

int __fastcall FUN_005c0880(bhkCharacterController*);
float __fastcall GetSettingFloat(bhkCharacterController*);
float __cdecl FUN_004587d0(float);
bool __fastcall FUN_008a5170(void*);
int __cdecl FUN_004b5470(const NiPoint3&, float);

extern double gModifierZero;
extern double DAT_0101db88;

// @fnv 0x008b2f90
bool MobileObject::IsAtPoint(const NiPoint3& targetPos, float radius, bool addCharRadius, bool check3D)
{
    bhkCharacterController* charCtrl;
    {
        NiPoint3 selfPos = Slot125();
        charCtrl = GetPhysicsCharacterController();
        {
            NiPoint3 diff = selfPos - targetPos;
            if (!check3D && charCtrl && FUN_005c0880(charCtrl))
            {
                diff.z = 0.0f;
            }
            else
            {
                float height = GetActorHeight();
                if (height == gModifierZero)
                {
                    height = 128.0f;
                }
                {
                    float zMin = selfPos.z - DAT_0101db88;
                    {
                        float zMax = selfPos.z + height + DAT_0101db88;
                        if (targetPos.z > zMin && targetPos.z < zMax)
                        {
                            diff.z = 0.0f;
                        }
                    }
                }
            }
            if (addCharRadius)
            {
                float charRadius;
                if (charCtrl)
                {
                    charRadius = FUN_004587d0(GetSettingFloat(charCtrl));
                    if (FUN_008a5170((char*)charCtrl + 0x410))
                    {
                        charRadius *= 2.0f;
                    }
                    if (charRadius < 32.0)
                    {
                        charRadius = 32.0f;
                    }
                }
                else
                {
                    charRadius = 32.0f;
                }
                radius = radius + charRadius;
            }
            return FUN_004b5470(diff, radius) <= 0;
        }
    }
}

class NavMesh;
class Actor;
class TESPackage;
class NavMeshEdgeSegment;

template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    void SetSize(unsigned int, bool);
    unsigned int Find(T const&, unsigned int, bool(__cdecl*)(T const&, T const&));
    bool FUN_0076b610() const;
    unsigned int Add(T const&);
};

class TESObjectREFRHelper
{
  public:
    void SetTargetingState(bool);
};

class TESObjectREFR
{
  public:
    TESObjectREFR* GetLinkedRef();
};

class PatrolActorPackageData
{
  public:
    static TESObjectREFR* __cdecl GetPatrolReference(Actor*, TESPackage*);
    bool IsPatrolling();
};

bool __cdecl FUN_009a3830(NavMesh* const&, NavMesh* const&);

// @fnv 0x009f2da0
bool __fastcall BuildLinkedRefChain(char* _this)
{
    bool bLoop;
    TESObjectREFR* pRef =
        PatrolActorPackageData::GetPatrolReference(*(Actor**)(_this + 0x10), *(TESPackage**)(_this + 0x14));
    *(bool*)(_this + 0x2c) = false;
    ((BSSimpleArray<unsigned int, 1024>*)(_this + 0x1c))->SetSize(0, true);
    bLoop =
        *(PatrolActorPackageData**)(_this + 0x18) ? (*(PatrolActorPackageData**)(_this + 0x18))->IsPatrolling() : false;

    while (pRef != 0)
    {
        ((TESObjectREFRHelper*)pRef)->SetTargetingState(true);
        ((BSSimpleArray<void*, 1024>*)(_this + 0x1c))->Add(*(void**)&pRef);
        pRef = pRef->GetLinkedRef();
        if (pRef == 0)
            break;

        unsigned int idx = ((BSSimpleArray<NavMesh*, 1024>*)(_this + 0x1c))->Find(*(NavMesh**)&pRef, 0, FUN_009a3830);
        if (idx != (unsigned int)-1)
        {
            if (!bLoop)
            {
                ((BSSimpleArray<void*, 1024>*)(_this + 0x1c))->Add(*(void**)&pRef);
            }
            else
            {
                *(bool*)(_this + 0x2c) = true;
                *(unsigned int*)(_this + 0x30) = idx;
            }
            break;
        }
    }

    return !((BSSimpleArray<NavMeshEdgeSegment, 1024>*)(_this + 0x1c))->FUN_0076b610();
}

extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;

// @fnv 0x00af4470
void __cdecl FUN_00af4470(int aiDirString, int aiFileString, int aiFileOffset)
{
    DAT_011acdfc = aiDirString;
    DAT_011ace00 = aiFileString;
    DAT_011ace04 = aiFileOffset;
}

struct BSFileCache
{
    char pad[0x5c];
    int state;
    static BSFileCache& GetRandomGenerator();
};
struct Arc
{
    void LoadNames();
};
struct LNode
{
    Arc* item;
    LNode* next;
};
extern LNode* DAT_011f8160;
// If the global node list is non-empty, sets the cache state to 2 when it is 1, calls LoadNames on each node's Arc, then restores state 2 to 1.
// @fnv 0x00af59f0
void __cdecl ProcessArcList()
{
    bool b;
    LNode* pCurrentElementNext;
    if (DAT_011f8160)
    {
        BSFileCache* c1 = &BSFileCache::GetRandomGenerator();
        b = c1->state == 2 || c1->state == 3;
        if (!b)
        {
            BSFileCache* c2 = &BSFileCache::GetRandomGenerator();
            if (c2->state == 1)
                c2->state = 2;
        }
        pCurrentElementNext = DAT_011f8160;
        while (pCurrentElementNext)
        {
            Arc* a = pCurrentElementNext->item;
            a->LoadNames();
            pCurrentElementNext = pCurrentElementNext->next;
        }
        if (!b)
        {
            BSFileCache* c3 = &BSFileCache::GetRandomGenerator();
            if (c3->state == 2)
                c3->state = 1;
        }
    }
}

int __cdecl FindArchiveForFile(int a1, int a2);

// @fnv 0x00af6320
bool __cdecl FUN_00af6320(int a1, int a2)
{
    return FindArchiveForFile(a1, a2);
}

unsigned int __cdecl _strlen(const char*);
int __cdecl LookupExtensionType(const char*);

// Computes the string length, then passes a pointer to its last three characters to LookupExtensionType and returns that result.
// @fnv 0x00af7d80
int __cdecl FUN_00af7d80(const char* pcString)
{
    unsigned int len = _strlen(pcString);
    return LookupExtensionType(pcString + len - 3);
}

struct S_af9
{
    bool FindHashEntry(int, int*, int);
    bool FUN_00afa120(int, int, int, int, int);
    bool FUN_00af9bf0(int, int, int*, int, int);
};
// Returns true if FindHashEntry(a, c, e) succeeds and FUN_00afa120 then succeeds on *c with b, d, e and 0.
// @fnv 0x00af9bf0
bool S_af9::FUN_00af9bf0(int a, int b, int* c, int d, int e)
{
    if (FindHashEntry(a, c, e) && FUN_00afa120(*c, b, d, e, 0))
        return true;
    return false;
}

struct Owner25
{
    bool FindHashEntry(int a, int* out, int c);
    bool FUN_00afa120(int a, int b, int* out, int c, int d);
    int FUN_00afa6e0(int a, int b, int c);
};
// @fnv 0x00afa6e0
int Owner25::FUN_00afa6e0(int a, int b, int c)
{
    int index1;
    int index2;
    if (FindHashEntry(a, &index1, c) && FUN_00afa120(index1, b, &index2, c, 1))
    {
        return *(int*)(*(int*)((char*)this + 0x184) + index1 * 16 + 0xc) + index2 * 16;
    }
    return 0;
}

struct FUN_00afb170_Args
{
    bool param_1;
    int param_2;
};

// @fnv 0x00afb170
bool __fastcall FUN_00afb170(void* pThis, FUN_00afb170_Args args)
{
    if (args.param_2 == 1)
        return args.param_1;
    return args.param_2;
}

struct FUN_00afb670_shell : public ArchiveFile
{
    void FUN_00afb670(int, int);
};

// Adjusts the archive file position at offset 0x150 according to the seek mode, then advances m_uiPos by the delta and flushes if the buffer is exhausted.
// @fnv 0x00afb670
void FUN_00afb670_shell::FUN_00afb670(int aiByteCount, int aiSeekFlags)
{
    unsigned int ioldFilePos = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150);

    switch (aiSeekFlags)
    {
    case 1:
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) += aiByteCount;
        if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) >
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) =
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
        break;
    case 2:
        if (aiByteCount < 0)
            aiByteCount = -aiByteCount;
        if ((unsigned int)aiByteCount > *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
        {
            unsigned int tmp = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
            aiByteCount = tmp;
        }
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) =
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154) - aiByteCount;
        break;
    default:
        if ((unsigned int)aiByteCount > *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
        {
            unsigned int tmp = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
            aiByteCount = tmp;
        }
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) = aiByteCount;
        break;
    }

    m_uiPos += *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) - ioldFilePos;
    if (m_uiPos >= m_uiBufferReadSize)
        Flush();
}

struct S_afbb
{
    char pad[0x150];
    unsigned int pos;
    unsigned int size;
    int FUN_00b01800(void*, unsigned int);
    int FUN_00afbbf0(void*, unsigned int);
};
// Clamps count to the remaining bytes (size - pos), reads via FUN_00b01800, advances pos by the bytes read and returns that count.
// @fnv 0x00afbbf0
int S_afbb::FUN_00afbbf0(void* pBuffer, unsigned int count)
{
    int r;
    unsigned int sz = size;
    if (count + pos > sz)
    {
        unsigned int sz2 = size;
        count = sz2 - pos;
    }
    r = FUN_00b01800(pBuffer, count);
    pos += r;
    return r;
}

struct Dummy_00afbbf0
{
    int FUN_00afbbf0(int, int);
};

// @fnv 0x00afbf80
int __cdecl FUN_00afbf80(Dummy_00afbbf0* pTarget, int b, int c)
{
    return pTarget->FUN_00afbbf0(b, c);
}

struct ZlibStreamPeer;
struct ZlibStream
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned long m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned long m_ulTotalOutputBytes;
    char* msg;
    ZlibStreamPeer* state;
    int* m_pAllocateCallback;
    int* m_pFreeCallback;
    void* opaque;
    int data_type;
    unsigned long m_ulAdler32Checksum;
    unsigned long reserved;
};
typedef char _sizecheck_z_stream_s[sizeof(ZlibStream) == 56 ? 1 : -1];
struct FUN_00afbfe0_shell : public CompressedArchiveFile
{
    void DestroyCompressedArchiveFile();
};

class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
extern int DAT_010a464c;
int __cdecl _inflateEnd(ZlibStream* kReadStream);
void __fastcall FUN_00afb520(void* pThis);

// Sets the vtable, ends and frees the zlib stream at offset 0x160, frees the buffer at 0x164, then calls FUN_00afb520.
// @fnv 0x00afbfe0
void FUN_00afbfe0_shell::DestroyCompressedArchiveFile()
{
    ZlibStream* pzstream;
    *(int**)this = &DAT_010a464c;
    if (*(ZlibStream**)((char*)this + 0x160) != 0)
    {
        pzstream = *(ZlibStream**)((char*)this + 0x160);
        _inflateEnd(pzstream);
        void* p1 = pzstream;
        g_memoryManager._DeallocateAlias(p1);
    }
    if (*(void**)((char*)this + 0x164) != 0)
    {
        void* p2 = *(void**)((char*)this + 0x164);
        g_memoryManager._DeallocateAlias(p2);
    }
    FUN_00afb520(this);
}

struct FUN_00afc060_shell2 : public CompressedArchiveFile
{
    bool AttachFileStream(bool, bool);
    bool FUN_00afc060(bool a1, bool a2);
};

// @fnv 0x00afc060
bool FUN_00afc060_shell2::FUN_00afc060(bool a1, bool a2)
{
    return AttachFileStream(a1, a2);
}

struct S
{
    void __thiscall FUN_00afc0e0(int, int);
};

// @fnv 0x00afc660
void __cdecl FUN_00afc660(void* pObject, int b, int c)
{
    (*(S*)pObject).FUN_00afc0e0(b, c);
}

namespace fnv_00afc6c0 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

struct FUN_00afc6c0_shell2 : public CompressedArchiveFile
{
    void* FUN_00afc6c0(unsigned int flags);
};

// Calls DestroyCompressedArchiveFile on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00afc6c0
void* FUN_00afc6c0_shell2::FUN_00afc6c0(unsigned int flags)
{
    DestroyCompressedArchiveFile(this);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00afc6c0

namespace fnv_00afc6f0 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

struct FUN_00afc6f0_shell2 : public CompressedArchiveFile
{
    void* FUN_00afc6f0(unsigned int flags);
};

// @fnv 0x00afc6f0
void* FUN_00afc6f0_shell2::FUN_00afc6f0(unsigned int flags)
{
    DestroyCompressedArchiveFile(this);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00afc6f0

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObj
{
    virtual void v0();
    virtual void v1();
    long refs;
};
struct Pointee
{
    char pad[0x158];
    RefObj ro;
};
struct NP_afc
{
    Pointee* p;
    NP_afc* FUN_00afc770(NP_afc*);
};
// Assigns the pointee from a to this, releasing the old reference and incrementing the new one's refcount, then returns this.
// @fnv 0x00afc770
NP_afc* NP_afc::FUN_00afc770(NP_afc* apOther)
{
    if (p != apOther->p)
    {
        if (p)
        {
            RefObj* o = &p->ro;
            if (!InterlockedDecrement(&o->refs))
                o->v1();
        }
        p = apOther->p;
        if (p)
        {
            RefObj* o2 = &p->ro;
            InterlockedIncrement(&o2->refs);
        }
    }
    return this;
}

// Counts the high bits of bytes 0, 1 and 3 of pThis, weighted 2, 1 and 4 respectively, and returns their sum.
// @fnv 0x00afcfe0
int __fastcall FUN_00afcfe0(unsigned char* pucData)
{
    return ((pucData[3] & 0x80) >> 5) + ((pucData[0] & 0x80) >> 6) + ((pucData[1] & 0x80) >> 7);
}

namespace fnv_00afd1b0 {
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObj
{
    virtual void v0();
    virtual void v1();
    long refs;
};
struct Pointee
{
    char pad[0x158];
    RefObj ro;
};
struct NP_afd
{
    Pointee* p;
    NP_afd* FUN_00afd1b0(Pointee*);
};
// Replaces the stored Pointee pointer, releasing the old reference and incrementing the new one's refcount.
// @fnv 0x00afd1b0
NP_afd* NP_afd::FUN_00afd1b0(Pointee* pPointee)
{
    if (p != pPointee)
    {
        if (p)
        {
            RefObj* o = &p->ro;
            if (!InterlockedDecrement(&o->refs))
                o->v1();
        }
        p = pPointee;
        if (p)
        {
            RefObj* o2 = &p->ro;
            InterlockedIncrement(&o2->refs);
        }
    }
    return this;
}
}  // namespace fnv_00afd1b0

extern void(__stdcall* DAT_00fdf1c0)(int);

// @fnv 0x00afd230
void __fastcall FUN_00afd230(int* piValue)
{
    *piValue = 0;
    if (*piValue)
    {
        int v = *piValue + 0x158;
        DAT_00fdf1c0(v + 4);
    }
}

struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(char*, char*, FileNameHash*);

// Splits a path into drive, directory, file and extension, hashes the file name with its extension and the directory path into the two output hashes.
// @fnv 0x00afd270
void __cdecl HashPathComponents(const char* apString, FileNameHash* arDirHash, FileNameHash* arFileHash)
{
    char pfile[260];
    char pdrive[16];
    unsigned int ilength;
    char pdir[260];
    char pext[16];

    pdrive[0] = '\0';
    pdir[0] = '\0';
    pfile[0] = '\0';
    pext[0] = '\0';

    _splitpath_s(apString, pdrive, 16, pdir, 260, pfile, 260, pext, 16);
    ComputeNameHash(pfile, pext, arFileHash);

    strcpy_s(pfile, 260, pdrive);
    strcat_s(pfile, 260, pdir);

    if (pfile[0] == '\0')
    {
        pfile[0] = '.';
        pfile[1] = '\0';
    }

    ilength = strlen(pfile);
    if (pfile[ilength - 1] == '\\')
    {
        pfile[ilength - 1] = '\0';
    }

    ComputeNameHash(pfile, 0, arDirHash);
}

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(const char*, const char*, void*);

struct FUN_00afd390_class
{
    void* FUN_00afd390(const char* path, int mode);
};

// @fnv 0x00afd390
void* FUN_00afd390_class::FUN_00afd390(const char* path, int mode)
{
    const char* pExt = 0;
    if (mode != 2)
    {
        char ext[16];
        {
            char dir[260];
            {
                char drive[16];
                {
                    char fname[260];

                    drive[0] = '\0';
                    dir[0] = '\0';
                    fname[0] = '\0';
                    ext[0] = '\0';
                    _splitpath_s(path, drive, 16, dir, 260, fname, 260, ext, 16);
                    if (mode == 0)
                    {
                        pExt = ext;
                        path = fname;
                    }
                    else
                    {
                        strcpy_s(fname, 260, drive);
                        strcat_s(fname, 260, dir);
                        if (fname[0] == '\0')
                        {
                            fname[0] = '.';
                            fname[1] = '\0';
                        }
                        unsigned int len = strlen(fname);
                        if (fname[len - 1] == '\\')
                        {
                            fname[len - 1] = '\0';
                        }
                        path = fname;
                    }
                }
            }
        }
    }
    ComputeNameHash(path, pExt, this);
    return this;
}

extern bool DAT_011acdf9;
extern char* DAT_011f8158;
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
// Stores abInvalidate in DAT_011acdf9 and, when apInvalidationFile is non-null, allocates a copy of it into DAT_011f8158.
// @fnv 0x00af4490
void __cdecl FUN_00af4490(bool abInvalidate, const char* apInvalidationFile)
{
    DAT_011acdf9 = abInvalidate;
    if (apInvalidationFile)
    {
        unsigned int ilistSize = _strlen(apInvalidationFile) + 1;
        {
            char* pBuf = (char*)reinterpret_cast<MemoryManagerAllocHelper*>(&g_memoryManager)->Allocate(ilistSize);
            DAT_011f8158 = pBuf;
        }
        {
            char* pDst = DAT_011f8158;
            _strcpy_s(pDst, ilistSize, apInvalidationFile);
        }
    }
}

struct ArchiveFileEntryStand
{
    char pad[0xc];
    unsigned int uiSize;
};
struct ArchiveStand
{
    char pad[0x1b4];
    unsigned char m_ucEntryType;
    bool IsFileEntryValid(ArchiveFileEntryStand* apFile, bool abIgnore);
};
// Checks a file entry's size flag against the archive's compression bit unless ignored, and rejects entries with zero size.
// @fnv 0x00afb2a0
bool ArchiveStand::IsFileEntryValid(ArchiveFileEntryStand* apFile, bool abIgnore)
{
    if (!abIgnore)
    {
        bool bCompressed = (apFile->uiSize & 0x80000000) ? true : false;
        if (bCompressed != ((m_ucEntryType & 8) ? true : false))
            return false;
    }
    if (!(apFile->uiSize & 0x7fffffff))
        return false;
    return true;
}

namespace fnv_00afc430 {
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
int __cdecl _inflateInit_(void*, const char*, int);
int __cdecl _inflateEnd(void*);
extern int DAT_010a464c;
extern unsigned int DAT_011f8164;
struct S_afbb
{
    int FUN_00afbbf0(void*, unsigned int);
};
struct P03Z
{
    void* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    char pad08[0x14];
    void* state;
    void* m_pAllocateCallback;
    void* m_pFreeCallback;
    void* opaque;
};
struct P03CAF
{
    char pad[0x160];
    P03Z* pStream;
    void* pBuffer;
    unsigned int uiBufSize;
    unsigned int uiCap;
    int f170;
    int f174;
};
struct FUN_00afb300
{
    FUN_00afb300(int, int, int, int, int);
    ~FUN_00afb300();
};
struct FUN_00afc430 : public FUN_00afb300
{
    FUN_00afc430(int, int, int, int, int);
};
// @fnv 0x00afc430
FUN_00afc430::FUN_00afc430(int a, int b, int c, int d, int e) : FUN_00afb300(a, b, c, d, e)
{
    *(int**)this = &DAT_010a464c;
    ((CompressedArchiveFile*)this)->CompressedArchiveFile::SetEndianSwap(false);
    ((S_afbb*)this)->FUN_00afbbf0((char*)this + 0x168, 4);
    char* pStream;
    int pTmp;
    void* err = g_memoryManager.Allocate(0x1be0);
    pStream = (char*)err;
    ((P03CAF*)this)->pStream = (P03Z*)pStream;
    ((P03CAF*)this)->pStream->m_pAllocateCallback = 0;
    ((P03CAF*)this)->pStream->m_pFreeCallback = 0;
    ((P03CAF*)this)->pStream->opaque = 0;
    ((P03CAF*)this)->pStream->m_uiAvailableInputBytes = 0;
    ((P03CAF*)this)->pStream->m_pNextInputByte = 0;
    ((P03CAF*)this)->pStream->state = pStream + 0x38;
    pTmp = _inflateInit_(((P03CAF*)this)->pStream, "1.2.1", 0x38);
    if (pTmp)
    {
        _inflateEnd(((P03CAF*)this)->pStream);
        void* pFree = ((P03CAF*)this)->pStream;
        g_memoryManager._DeallocateAlias(pFree);
        ((P03CAF*)this)->pStream = 0;
    }
    else
    {
        ((P03CAF*)this)->uiCap = ((P03CAF*)this)->uiBufSize < DAT_011f8164 ? ((P03CAF*)this)->uiBufSize : DAT_011f8164;
        unsigned int pBuf = ((P03CAF*)this)->uiCap;
        void* uiSize = g_memoryManager.Allocate(pBuf);
        ((P03CAF*)this)->pBuffer = uiSize;
        ((P03CAF*)this)->f170 = 0;
        ((P03CAF*)this)->f174 = 0;
    }
}
}  // namespace fnv_00afc430

struct FUN_00afcde0_shell
{
    unsigned int* data;
    unsigned int size;
    unsigned int alloc;
    virtual void* v0();
    virtual unsigned int* v1(unsigned int);
    void InitArray(unsigned int, unsigned int);
};
// Initializes the array to empty, reserves aiReserveSize elements via v1, and sets size to aiInitialSize.
// @fnv 0x00afcde0
void FUN_00afcde0_shell::InitArray(unsigned int aiReserveSize, unsigned int aiInitialSize)
{
    data = 0;
    size = 0;
    alloc = 0;
    if (aiInitialSize > aiReserveSize)
        aiReserveSize = aiInitialSize;
    if (aiReserveSize > 0)
    {
        data = v1(aiReserveSize);
        alloc = aiReserveSize;
    }
    if (aiInitialSize > 0)
    {
        for (unsigned int i = 0; i < aiInitialSize; i++)
        {
            unsigned int* p = &data[i];
        }
        size = aiInitialSize;
    }
}

struct FUN_00afce90_S
{
    unsigned __int64 value;
    int FUN_00afce90(const unsigned __int64& other);
};
// Compares value with other and returns -1 if less, 1 if greater, or 0 if equal.
// @fnv 0x00afce90
int FUN_00afce90_S::FUN_00afce90(const unsigned __int64& aullValue)
{
    if (value < aullValue)
        return -1;
    else if (value > aullValue)
        return 1;
    return 0;
}

extern bool DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;
struct ArgPair
{
    char c0, c1, c2;
    bool b;
    int i;
};
struct ArchiveStandIn
{
    char pad[0x16c];
    unsigned int uiFlags;
    char pad170[0x10];
    unsigned short usTypes;
    bool FUN_00afb170(bool, int);
    bool FUN_00afd020();
};
// @fnv 0x00afd020
bool ArchiveStandIn::FUN_00afd020()
{
    ArgPair p[5];
    return (DAT_011acdf9 || DAT_011f8154 || (unsigned char)+((uiFlags & 0x80) != 0) ||
            (p[4].i = DAT_011acdfc, p[4].b = (uiFlags & 8) != 0, FUN_00afb170(p[4].b, p[4].i)) ||
            (p[3].i = DAT_011ace00, p[3].b = (uiFlags & 0x10) != 0, FUN_00afb170(p[3].b, p[3].i)) ||
            (p[2].i = DAT_011ace04, p[2].b = (uiFlags & 0x20) != 0, FUN_00afb170(p[2].b, p[2].i))) &&
           (!(unsigned short)(usTypes & 0x10) ||
            (p[1].i = DAT_011ace00, p[1].b = (uiFlags & 0x10) != 0, FUN_00afb170(p[1].b, p[1].i)) ||
            (p[0].i = DAT_011ace04, p[0].b = (uiFlags & 0x20) != 0, FUN_00afb170(p[0].b, p[0].i)));
}

class MemoryManager;
extern MemoryManager g_memoryManager;
struct P03MM
{
    void* Allocate(unsigned int);
};
unsigned int __cdecl _strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
extern bool DAT_011acdf8;
extern char DAT_011f8050[];
extern const char DAT_010a433a[];
extern char* DAT_011f815c;
extern unsigned int DAT_011f8164;
// Stores the archive flag, copies the archive list and master file path into globals, and sets the file buffer size.
// @fnv 0x00af43a0
void __cdecl FUN_00af43a0(bool abUseArchives, char* apMasterFilePath, char* apArchiveList,
                          unsigned int aiFileBufferSize)
{
    int ilistSize;
    char* pEmpty;
    char* pNew;
    DAT_011acdf8 = abUseArchives;
    if (apArchiveList)
    {
        ilistSize = _strlen(apArchiveList) + 1;
        pEmpty = (char*)((P03MM*)&g_memoryManager)->Allocate(ilistSize);
        DAT_011f815c = pEmpty;
        {
            {
                char* pDest = DAT_011f815c;
                _strcpy_s(pDest, ilistSize, apArchiveList);
            }
        }
    }
    else
    {
        pNew = (char*)((P03MM*)&g_memoryManager)->Allocate(0);
        DAT_011f815c = pNew;
        *DAT_011f815c = 0;
    }
    if (apMasterFilePath)
        _strcpy_s(DAT_011f8050, 0x104, apMasterFilePath);
    else
        _strcpy_s(DAT_011f8050, 0x104, DAT_010a433a);
    DAT_011f8164 = aiFileBufferSize;
}

namespace fnv_00af7db0 {
int __cdecl _stricmp(const char*, const char*);
struct ExtEntry_00af7db0
{
    char acExt[4];
    unsigned int uiType;
};
struct ExtType_00af7db0
{
    unsigned int uiType;
    char acPad[4];
};
extern ExtEntry_00af7db0 str_011ace08[];
extern ExtType_00af7db0 DAT_011ace0c[];
// @fnv 0x00af7db0
unsigned int __cdecl LookupExtensionType(const char* apExt)
{
    unsigned int iCmp = 0;
    unsigned int uiStep = 0x1a;
    unsigned int uiHigh = 0;
    unsigned int uiMid = 1;
    int uiLow = 0;
    if (*apExt == '.')
        apExt++;
    else if (apExt[1] == '.')
        apExt += 2;
    while (uiMid)
    {
        uiMid = (uiStep - iCmp) >> 1;
        uiHigh = iCmp + uiMid;
        uiLow = _stricmp(apExt, str_011ace08[uiHigh].acExt);
        if (uiLow > 0)
            iCmp = uiHigh;
        else if (uiLow < 0)
            uiStep = uiHigh;
        else
            break;
    }
    if (uiLow == 0)
        return DAT_011ace0c[uiHigh].uiType;
    return 0x100;
}
}  // namespace fnv_00af7db0

namespace fnv_00af6340 {
enum ARCHIVE_TYPE
{
    ARCHIVE_TYPE_DUMMY
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct BSFileEntry
{
    char pad[0xc];
    int flags;
};
struct ArchiveFile;
struct ArchiveRefCount
{
    virtual void Slot0();
    virtual void Destroy();
    long count;
    void AcquireReference()
    {
        InterlockedIncrement(&count);
    }
    void DecRef()
    {
        if (!InterlockedDecrement(&count))
            Destroy();
    }
};
struct Archive
{
    char pad[0x158];
    ArchiveRefCount rc;
    ArchiveFile* CreateArchiveFile(BSFileEntry*, unsigned int, unsigned int);
};
struct ArchiveManager
{
    static Archive* __cdecl FindArchiveForFileEntry(BSFileEntry*, ARCHIVE_TYPE);
};
struct ArchiveSmartPtr
{
    Archive* p;
    ArchiveSmartPtr(Archive* a) : p(a)
    {
        if (p)
            p->rc.AcquireReference();
    }
    Archive* operator->()
    {
        return p;
    }
    ~ArchiveSmartPtr()
    {
        if (p)
            p->rc.DecRef();
    }
};
// @fnv 0x00af6340
ArchiveFile* __cdecl FUN_00af6340(int aeArchiveTypeIndex, BSFileEntry* apFileEntry, unsigned int aiBufferSize,
                                  unsigned int apFileName)
{
    ArchiveFile* pfile = 0;
    bool binSecondaryArchive = (apFileEntry->flags & 0x80000000) == 0 ? false : true;
    ArchiveSmartPtr sparchive(ArchiveManager::FindArchiveForFileEntry(apFileEntry, (ARCHIVE_TYPE)0xffff));
    if (sparchive.p)
    {
        pfile = sparchive->CreateArchiveFile(apFileEntry, aiBufferSize, apFileName);
    }
    return pfile;
}
}  // namespace fnv_00af6340

extern bool DAT_011f8154;

// @fnv 0x00af4460
void FUN_00af4460(bool abCheckRuntimeCollisions)
{
    DAT_011f8154 = abCheckRuntimeCollisions;
}

namespace fnv_00af44f0 {
extern char* DAT_011f8158;
extern char* DAT_011f815c;
extern "C" void __cdecl _DeallocateAlias(void* ptr);
struct MemoryManager
{
    void __thiscall _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;

// @fnv 0x00af44f0
void FUN_00af44f0()
{
    char* ptr0;
    char* ptr1;
    if (DAT_011f8158)
    {
        ptr0 = DAT_011f8158;
        g_memoryManager._DeallocateAlias(ptr0);
    }
    if (DAT_011f815c)
    {
        ptr1 = DAT_011f815c;
        g_memoryManager._DeallocateAlias(ptr1);
    }
}
}  // namespace fnv_00af44f0

extern unsigned int DAT_011f8164;

// @fnv 0x00af4540
void FUN_00af4540()
{
    DAT_011f8164 = 0x20000;
}

namespace fnv_00af56d0 {
extern "C" int __cdecl RemoveArchiveFile(int);
extern "C" int DAT_011f8160;

// Returns false if DAT_011f8160 or arg is zero; otherwise calls RemoveArchiveFile with arg and returns true.
// @fnv 0x00af56d0
bool __cdecl FUN_00af56d0(int aiValue)
{
    if (DAT_011f8160 == 0 || aiValue == 0)
        return false;
    RemoveArchiveFile(aiValue);
    return true;
}
}  // namespace fnv_00af56d0

struct Entry16
{
    int a;
    int b;
    int c;
    unsigned int d;
};
struct FUN_00af9b60_shell
{
    char pad[0x184];
    Entry16* entries;
    unsigned int FUN_00af9b60(unsigned int index, unsigned int value);
};
// Computes the difference between value and the entry's d field at index, shifted right by 4.
// @fnv 0x00af9b60
unsigned int FUN_00af9b60_shell::FUN_00af9b60(unsigned int index, unsigned int value)
{
    unsigned int tmp;
    unsigned int start;
    unsigned int endPos;
    Entry16* pEntry;
    pEntry = entries + index;
    tmp = value;
    endPos = pEntry->d;
    start = endPos;
    return (tmp - start) >> 4;
}

struct FUN_00af9ba0_shell
{
    int FindEntryIndex(unsigned int key);
    unsigned int FUN_00af9b60(unsigned int index, unsigned int value);
    int FUN_00af96d0(int index, unsigned int value);
    int FUN_00af9ba0(unsigned int key);
};
// @fnv 0x00af9ba0
int FUN_00af9ba0_shell::FUN_00af9ba0(unsigned int key)
{
    int index = FindEntryIndex(key);
    if (index == -1)
        return 0;
    unsigned int result = FUN_00af9b60(index, key);
    return FUN_00af96d0(index, result);
}

namespace fnv_00afac20 {
struct FUN_00afac20_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct FUN_00afac20_group
{
    int a;
    int b;
    int c;
    FUN_00afac20_entry* entries;
};
struct S_af9
{
    bool FUN_00af9bf0(int, int, int*, int*, int);
    bool FUN_00afac20(int a, int b, int c);
};
// Looks up an entry via FUN_00af9bf0 and, if found, sets its size to 0 and returns true; otherwise returns false.
// @fnv 0x00afac20
bool S_af9::FUN_00afac20(int a, int b, int c)
{
    int iGroupIndex;
    int idx;
    if (FUN_00af9bf0(a, b, &iGroupIndex, &idx, 0))
    {
        FUN_00afac20_entry* e =
            (FUN_00afac20_entry*)((char*)((FUN_00afac20_group*)*(char**)((char*)this + 0x184) + iGroupIndex)->entries +
                                  idx * 16);
        e->SetSize(0);
        return true;
    }
    return false;
}
}  // namespace fnv_00afac20

namespace fnv_00afac90 {
struct FUN_00afac90_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct FUN_00afac90_group
{
    int a;
    int b;
    int c;
    FUN_00afac90_entry* entries;
};
struct S_af9
{
    bool FUN_00afa120(int, int, int*, int, int);
    bool FUN_00afac90(int a, int b, int c);
};
// @fnv 0x00afac90
bool S_af9::FUN_00afac90(int aiGroupIndex, int b, int aiUnused)
{
    int idx;
    if (FUN_00afa120(aiGroupIndex, b, &idx, 0, 0))
    {
        FUN_00afac90_entry* e =
            (FUN_00afac90_entry*)((char*)((FUN_00afac90_group*)*(char**)((char*)this + 0x184) + aiGroupIndex)->entries +
                                  idx * 16);
        e->SetSize(0);
        return true;
    }
    return false;
}
}  // namespace fnv_00afac90

struct FUN_00afbf50_shell
{
    unsigned int FUN_00afbf50(void* a, unsigned int b);
};
// @fnv 0x00afbf50
unsigned int FUN_00afbf50_shell::FUN_00afbf50(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc3e0_shell
{
    unsigned int FUN_00afc3e0(void* a, unsigned int b);
};
// @fnv 0x00afc3e0
unsigned int FUN_00afc3e0_shell::FUN_00afc3e0(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc3f0_shell
{
    unsigned int FUN_00afc3f0(void* a, unsigned int b);
};
// @fnv 0x00afc3f0
unsigned int FUN_00afc3f0_shell::FUN_00afc3f0(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc400_shell
{
    int FUN_00afc400(int a, int b);
};
// @fnv 0x00afc400
int FUN_00afc400_shell::FUN_00afc400(int a, int b)
{
    return 0;
}

extern "C" __declspec(dllimport) int __stdcall TryEnterCriticalSection(void* cs);
struct Inner
{
    virtual void Slot0();
    virtual void Slot1();
    int field;
};
struct Outer
{
    char pad[0x158];
    Inner inner;
};
struct FUN_00afc720_shell
{
    Outer* owner;
    void EnterInnerCriticalSection();
};
// If owner is set, tries to enter the critical section in owner->inner and calls Slot1 when that fails.
// @fnv 0x00afc720
void FUN_00afc720_shell::EnterInnerCriticalSection()
{
    if (owner)
    {
        Inner* p = &owner->inner;
        if (!TryEnterCriticalSection(&p->field))
            p->Slot1();
    }
}

namespace fnv_00afcd10 {
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;
struct FUN_00afcd10_shell
{
    void* FUN_00afcd10(unsigned int count);
};
// Allocates count << 2 bytes via g_memoryManager.Allocate and returns the resulting pointer.
// @fnv 0x00afcd10
void* FUN_00afcd10_shell::FUN_00afcd10(unsigned int count)
{
    void* result = g_memoryManager.Allocate(count << 2);
    return result;
}
}  // namespace fnv_00afcd10

namespace fnv_00afcd40 {
class MemoryManager
{
  public:
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
struct FUN_00afcd40_shell
{
    void FUN_00afcd40(void* ptr);
};
// @fnv 0x00afcd40
void FUN_00afcd40_shell::FUN_00afcd40(void* pMemory)
{
    g_memoryManager._DeallocateAlias(pMemory);
}
}  // namespace fnv_00afcd40

namespace fnv_00afcd60 {
class MemoryManager
{
  public:
    void* Reallocate(void* p, unsigned int size);
};
extern MemoryManager g_memoryManager;
struct FUN_00afcd60_shell
{
    void* FUN_00afcd60(void* p, unsigned int count);
};
// @fnv 0x00afcd60
void* FUN_00afcd60_shell::FUN_00afcd60(void* p, unsigned int count)
{
    return g_memoryManager.Reallocate(p, count << 2);
}
}  // namespace fnv_00afcd60

extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);

// Skips a leading backslash and, if the path starts with "Data\" or "data\", advances past that prefix; returns the resulting path pointer.
// @fnv 0x00b014b0
const char* __cdecl SkipDataPrefix(const char* path)
{
    if (*path == '\\')
        ++path;
    if (FUN_00ec8a19(path, "Data\\", 5) == 0 || FUN_00ec8a19(path, "data\\", 5) == 0)
        path += 5;
    return path;
}

namespace fnv_00af5700 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl _stricmp(const char*, const char*);
struct FileFinder
{
    int GetFileLocation(char* apFileName, char* apPath, unsigned int auiArchiveType, unsigned int auiFlags);
};
extern FileFinder* g_fileFinder;
struct ArchiveListNode
{
    BSFile* pArchive;
    ArchiveListNode* pNext;
};
extern ArchiveListNode* DAT_011f8160;
void __cdecl RemoveArchiveFile(BSFile* apArchive);

// @fnv 0x00af5700
bool __cdecl FUN_00af5700(char* apFileName)
{
    char acPath[260];
    if (!DAT_011f8160)
        return false;
    strcpy_s(acPath, 260, apFileName);
    if (!(g_fileFinder ? g_fileFinder->GetFileLocation(apFileName, acPath, 1, 0xffffffff) : 0))
        return false;
    ArchiveListNode* pnode = DAT_011f8160;
    while (pnode)
    {
        BSFile* parchive = pnode->pArchive;
        if (parchive)
        {
            const char* pArchiveName = parchive->FileName();
            if (!_stricmp(pArchiveName, acPath))
            {
                RemoveArchiveFile(parchive);
                return true;
            }
        }
        pnode = pnode->pNext;
    }
    return false;
}
}  // namespace fnv_00af5700

namespace fnv_00af5fa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
int __cdecl FUN_00af7d80(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};
struct S_af9
{
    bool FUN_00af9bf0(int arDirHash, int arFileHash, int* apFolderIndex, int apFileIndex, int apFileName);
};
struct Archive : public S_af9
{
    void* OpenFile(unsigned int auiFolderIndex, unsigned int auiFileIndex, unsigned int auiBufferSize,
                   const char* apFileName);
    unsigned short HasArchiveTypeFlags(unsigned int auiFlags)
    {
        return *(unsigned short*)((char*)this + 0x180) & auiFlags;
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
// @fnv 0x00af5fa0
void* LoadFileFromArchives(const char* apFileName, unsigned int auiBufferSize, unsigned int aeArchiveTypeFlags)
{
    unsigned int uiFolderIndex = 0;
    unsigned int uiFileIndex = 0;
    FileNameHash kFileNameHash;
    FileNameHash kDirectoryNameHash;
    apFileName = SkipDataPrefix(apFileName);
    if (aeArchiveTypeFlags == 0xffff)
        aeArchiveTypeFlags = FUN_00af7d80(apFileName);
    FileNameHash::CreateDirectoryAndFileHashes(apFileName, kDirectoryNameHash, kFileNameHash);
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        if (sparchive && sparchive->HasArchiveTypeFlags(aeArchiveTypeFlags) &&
            sparchive->FUN_00af9bf0((int)&kDirectoryNameHash, (int)&kFileNameHash, (int*)&uiFolderIndex,
                                    (int)&uiFileIndex, (int)apFileName))
        {
            return sparchive->OpenFile(uiFolderIndex, uiFileIndex, auiBufferSize, apFileName);
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    return 0;
}
}  // namespace fnv_00af5fa0

namespace fnv_00af6160 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* p);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
int __cdecl FUN_00af7d80(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};
struct S_af9
{
    bool FUN_00af9bf0(int arDirHash, int arFileHash, int* apFolderIndex, int apFileIndex, int apFileName);
};
struct Archive : public S_af9
{
    void* OpenFile(unsigned int auiFolderIndex, unsigned int auiFileIndex, unsigned int auiBufferSize,
                   const char* apFileName);
    unsigned short HasArchiveTypeFlags(unsigned int auiFlags)
    {
        return *(unsigned short*)((char*)this + 0x180) & auiFlags;
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
extern _RTL_CRITICAL_SECTION DAT_011f8170;
// @fnv 0x00af6160
Archive* FindArchiveForFile(const char* apFileName, unsigned int aeArchiveTypeFlags)
{
    if (!DAT_011f8160)
        return 0;
    unsigned int uiFolderIndex;
    unsigned int uiFileIndex;
    FileNameHash kFileNameHash;
    FileNameHash kDirectoryNameHash;
    apFileName = SkipDataPrefix(apFileName);
    if (aeArchiveTypeFlags == 0xffff)
        aeArchiveTypeFlags = FUN_00af7d80(apFileName);
    FileNameHash::CreateDirectoryAndFileHashes(apFileName, kDirectoryNameHash, kFileNameHash);
    EnterCriticalSection(&DAT_011f8170);
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        if (sparchive && sparchive->HasArchiveTypeFlags(aeArchiveTypeFlags) &&
            sparchive->FUN_00af9bf0((int)&kDirectoryNameHash, (int)&kFileNameHash, (int*)&uiFolderIndex,
                                    (int)&uiFileIndex, (int)apFileName))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return sparchive;
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}
}  // namespace fnv_00af6160

namespace fnv_00af7e80 {
struct FUN_00afd390_class
{
    void* v;
    void* __thiscall FUN_00afd390(const char*, int);
};

struct FUN_00afcf00_class
{
    int __thiscall FUN_00afcf00(void*);
};

struct Local28
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    FUN_00afd390_class obj;
    void* f;
};

// @fnv 0x00af7e80
bool __cdecl FUN_00af7e80(const char* path, FUN_00afcf00_class* obj)
{
    Local28 l;
    l.obj.FUN_00afd390(path, 0);
    if (obj->FUN_00afcf00(&l.obj) == 0)
        return true;
    return false;
}
}  // namespace fnv_00af7e80

namespace fnv_00afcce0 {
extern int DAT_010a469c;

struct FUN_00afcde0_shell
{
    void* vptr;
    void InitArray(unsigned int, unsigned int);
    void* FUN_00afcce0();
};

// Sets the vtable pointer to DAT_010a469c, calls InitArray with 0 and 0, and returns this.
// @fnv 0x00afcce0
void* FUN_00afcde0_shell::FUN_00afcce0()
{
    int a;
    int b;
    vptr = &DAT_010a469c;
    InitArray(0, 0);
    return this;
}
}  // namespace fnv_00afcce0

namespace fnv_00af8e60 {
extern long volatile DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct ArcBase
{
    virtual ~ArcBase();
    char data[0x154];
};
struct ArcRef
{
    virtual ~ArcRef()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
    long refs;
};
struct ArcLock
{
    char data[0x18];
    ~ArcLock()
    {
        DeleteCriticalSection(data);
    }
};
struct FUN_00af8e60 : ArcBase, ArcRef
{
    char pad[0x3c];
    ArcLock cs;
    virtual ~FUN_00af8e60();
    void ReleaseOwnedMemory();
    void FreeNames(int);
    void FreeEntries();
};
// Destructor that calls ReleaseOwnedMemory, FreeNames(0) and FreeEntries in sequence.
// @fnv 0x00af8e60
FUN_00af8e60::~FUN_00af8e60()
{
    ReleaseOwnedMemory();
    FreeNames(0);
    FreeEntries();
}
}  // namespace fnv_00af8e60

namespace fnv_00af9230 {
struct MemoryManager
{
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
struct S_af9
{
    char pad[0x1b4];
    unsigned char flags;
    char pad2[3];
    void* names;
    void* extra;
    inline bool IsStatic()
    {
        return flags & 4;
    }
    inline void SetOwned(bool b)
    {
        if (b)
            flags |= 0x10;
        else
            flags &= ~0x10;
    }
    void ReleaseOwnedMemory();
};
// If the object is not static, deallocates names and extra, nulls both pointers, then clears the owned flag.
// @fnv 0x00af9230
void S_af9::ReleaseOwnedMemory()
{
    if (!IsStatic())
    {
        if (names)
        {
            void* p = names;
            g_memoryManager._DeallocateAlias(p);
        }
        if (extra)
        {
            void* pExtra = extra;
            g_memoryManager._DeallocateAlias(pExtra);
        }
        names = 0;
        extra = 0;
    }
    SetOwned(0);
}
}  // namespace fnv_00af9230

namespace fnv_00af9410 {
struct MemoryManager
{
    void _DeallocateAlias(void* ptr);
};
extern MemoryManager g_memoryManager;
struct FUN_00af9410_entry
{
    int a;
    int b;
    int c;
    void* mem;
};
struct S_af9
{
    char pad[0x170];
    unsigned int count;
    char pad2[0x10];
    FUN_00af9410_entry* entries;
    char pad3[0x2c];
    unsigned char flags;
    inline unsigned int GetCount()
    {
        return count;
    }
    inline bool IsStatic()
    {
        return flags & 4;
    }
    void FreeEntries();
};
// If the object is not static, deallocates each entry's mem and the entries array, then clears entries.
// @fnv 0x00af9410
void S_af9::FreeEntries()
{
    if (!IsStatic())
    {
        if (entries)
        {
            void* i;
            unsigned int p;
            void* pEntries;
            for (p = 0; p < GetCount(); p++)
            {
                i = entries[p].mem;
                g_memoryManager._DeallocateAlias(i);
            }
            pEntries = entries;
            g_memoryManager._DeallocateAlias(pEntries);
        }
        entries = 0;
    }
}
}  // namespace fnv_00af9410

namespace fnv_00af9ad0 {
struct FUN_00af9ad0_entry
{
    int a;
    int b;
    unsigned int size;
    void* base;
    inline unsigned int GetSize()
    {
        return size;
    }
    inline void* GetBase()
    {
        return base;
    }
};
struct S_af9
{
    char pad[0x170];
    unsigned int count;
    char pad2[0x10];
    FUN_00af9ad0_entry* entries;
    inline unsigned int GetCount()
    {
        return count;
    }
    int FindEntryIndex(unsigned int addr);
};
// Scans the entries array and returns the index whose base..base+size<<4 range contains addr, or -1 if none does.
// @fnv 0x00af9ad0
int S_af9::FindEntryIndex(unsigned int uiAddress)
{
    for (unsigned int i = 0; i < GetCount(); i++)
    {
        FUN_00af9ad0_entry* a = entries + i;
        unsigned int base = uiAddress;
        unsigned int e = (unsigned int)a->GetBase();
        unsigned int size = a->GetSize() << 4;
        if (base >= e && base < e + size)
            return i;
    }
    return -1;
}
}  // namespace fnv_00af9ad0

extern int DAT_010a469c;

struct _BSAHelper
{
    void Clear(bool b);
};

struct FUN_00afcdc0_StandIn
{
    void* vptr;
    void FUN_00afcdc0();
};

// Sets the object's vtable pointer to DAT_010a469c and calls Clear(true) on it.
// @fnv 0x00afcdc0
void FUN_00afcdc0_StandIn::FUN_00afcdc0()
{
    int _t;
    *(void**)this = &DAT_010a469c;
    ((_BSAHelper*)this)->Clear(true);
}

namespace fnv_00af5320 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
int __stricmp(const char*, const char*);

class BSRefCountedSI
{
  public:
    virtual ~BSRefCountedSI();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
class Archive : public BSFile, public BSRefCountedSI
{
};
template <class T> class ArchivePtr
{
  public:
    ArchivePtr(const ArchivePtr& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
inline const char* GetArchiveName(const ArchivePtr<Archive>& m_pArchive)
{
    return m_pArchive->FileName();
}
struct ArchiveListNode
{
    ArchivePtr<Archive> spItem;
    ArchiveListNode* pNext;
};
extern ArchiveListNode* _DAT_011f8160;
extern _RTL_CRITICAL_SECTION DAT_011f8170;

// Searches the archive list under the critical section for an entry whose file name matches apName case-insensitively and returns it, else 0.
// @fnv 0x00af5320
Archive* __cdecl FindArchiveByName(const char* apName)
{
    if (!_DAT_011f8160)
        return 0;
    EnterCriticalSection(&DAT_011f8170);
    ArchiveListNode* pNode = _DAT_011f8160;
    while (pNode)
    {
        ArchivePtr<Archive> m_pArchive(pNode->spItem);
        if (m_pArchive && !__stricmp(GetArchiveName(m_pArchive), apName))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return m_pArchive;
        }
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}
}  // namespace fnv_00af5320

namespace fnv_00afa550 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int iNameHash;
    unsigned int iDirHash;
    unsigned int iSize;
    unsigned int iOffset;
    unsigned int GetSize() const
    {
        return iSize & 0x3fffffff;
    }
    bool IsCompressed() const
    {
        return iSize & 0x40000000;
    }
};
struct ArchiveFolderEntryStand
{
    unsigned int iHash;
    unsigned int iCount;
    unsigned int iOffset;
    ArchiveFileEntryStand* pFiles;
};
struct ArchiveStand;
struct FUN_00afb300 : public ArchiveFile
{
    FUN_00afb300(const char*, ArchiveStand*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
struct FUN_00afc430 : public CompressedArchiveFile
{
    FUN_00afc430(const char*, ArchiveStand*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
struct ArchiveStand
{
    char pad[0x16c];
    unsigned int iArchiveFlags;
    char pad2[0x184 - 0x170];
    ArchiveFolderEntryStand* pFolders;
    bool GetArchiveFlag(unsigned int uiFlag) const
    {
        return !!(iArchiveFlags & uiFlag);
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* OpenFile(int iFolder, int iFile, int iMode, const char* pName);
};

// @fnv 0x00afa550
ArchiveFile* ArchiveStand::OpenFile(int iFolder, int iFile, int iMode, const char* pName)
{
    ArchiveFile* pArchiveFile = 0;
    ArchiveFileEntryStand* pEntry = &pFolders[iFolder].pFiles[iFile];
    if (pEntry && IsFileEntryValid(pEntry, false))
    {
        unsigned int iOffset = pEntry->iOffset & 0x7fffffff;
        if (GetArchiveFlag(4) == pEntry->IsCompressed())
        {
            pArchiveFile = new FUN_00afb300(pName, this, iOffset, pEntry->GetSize(), iMode);
        }
        else
        {
            pArchiveFile = new FUN_00afc430(pName, this, iOffset, pEntry->GetSize(), iMode);
        }
    }
    return pArchiveFile;
}
}  // namespace fnv_00afa550

namespace fnv_00afa750 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int hash[2];
    unsigned int size;
    unsigned int offset;
    __forceinline bool IsCompressionToggled()
    {
        return size & 0x40000000;
    }
    __forceinline unsigned int GetSize()
    {
        return size & 0x3fffffff;
    }
    __forceinline unsigned int GetOffset()
    {
        return offset & 0x7fffffff;
    }
};
struct ArchiveStand;
struct FUN_00afb300 : ArchiveFile
{
    FUN_00afb300(unsigned int, ArchiveStand*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
struct FUN_00afc430 : CompressedArchiveFile
{
    FUN_00afc430(unsigned int, ArchiveStand*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
struct ArchiveStand
{
    char pad[0x16c];
    unsigned int flags;
    __forceinline bool IsCompressed()
    {
        return (flags & 4) != 0;
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* CreateArchiveFile(ArchiveFileEntryStand*, unsigned int, unsigned int);
};
// If entry is valid and passes IsFileEntryValid, allocates a compressed or uncompressed archive file matching the archive's compression state and returns it.
// @fnv 0x00afa750
ArchiveFile* ArchiveStand::CreateArchiveFile(ArchiveFileEntryStand* entry, unsigned int a, unsigned int auiUnk)
{
    ArchiveFile* file = 0;
    if (entry)
    {
        if (IsFileEntryValid(entry, false))
        {
            if (IsCompressed() == entry->IsCompressionToggled())
                file = new FUN_00afb300(auiUnk, this, entry->GetOffset(), entry->GetSize(), a);
            else
                file = new FUN_00afc430(auiUnk, this, entry->GetOffset(), entry->GetSize(), a);
        }
    }
    return file;
}
}  // namespace fnv_00afa750

namespace fnv_00afc7f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiRefObject
{
    virtual void _v00();
    virtual void DeleteThis();
    long m_uiRefCount;

    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    ~NiPointer()
    {
        if (m_pObject)
        {
            m_pObject->DecrementReferenceCount();
        }
    }
};

struct FUN_00afc7f0
{
    NiPointer<Archive> m_spArchive;

    ~FUN_00afc7f0();
    void FUN_00afcaf0();
};

// Destructor that calls FUN_00afcaf0 and releases the held Archive through the NiPointer member.
// @fnv 0x00afc7f0
FUN_00afc7f0::~FUN_00afc7f0()
{
    int l1, l2, l3, l4, l5, l6, l7, l8;
    FUN_00afcaf0();
}
}  // namespace fnv_00afc7f0

namespace fnv_00afc880 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncrementReferenceCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    NiPointer() : m_pObject(0)
    {}

    NiPointer(const NiPointer& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncrementReferenceCount();
        }
    }

    bool operator==(T* p) const
    {
        return m_pObject == p;
    }

    bool operator!=(T* p) const
    {
        return m_pObject != p;
    }
};

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

    NP_afc* FUN_00afc770(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void PushArchive(NP_afc*);
};

// @fnv 0x00afc880
void NP_afc::PushArchive(NP_afc* other)
{
    if (other->m_spArchive == 0)
        return;

    if (m_spArchive != 0)
    {
        NP_afc* pNode = new NP_afc(this);
        pNode->m_pkNext = m_pkNext;
        m_pkNext = pNode;
        FUN_00afc770(other);
    }
    else
    {
        FUN_00afc770(other);
    }
}
}  // namespace fnv_00afc880

namespace fnv_00afcc10 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncrementReferenceCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecrementReferenceCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveBase
{
    virtual void _v00();
    char pad[0x154];
};

struct Archive : public ArchiveBase, public NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;

    NiPointer() : m_pObject(0)
    {}

    NiPointer(const NiPointer& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncrementReferenceCount();
        }
    }

    bool operator==(T* p) const
    {
        return m_pObject == p;
    }

    bool operator!=(T* p) const
    {
        return m_pObject != p;
    }
};

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

    NP_afc* FUN_00afc770(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void AppendArchive(NP_afc*);
};

// Appends a copy of other's archive to the end of the list, or assigns it to the tail node if that node has no archive.
// @fnv 0x00afcc10
void NP_afc::AppendArchive(NP_afc* other)
{
    if (other->m_spArchive == 0)
        return;

    NP_afc* cur = this;
    while (cur->m_pkNext != 0)
    {
        cur = cur->m_pkNext;
    }

    if (cur->m_spArchive != 0)
    {
        cur->m_pkNext = new NP_afc(other);
    }
    else
    {
        cur->FUN_00afc770(other);
    }
}
}  // namespace fnv_00afcc10

namespace fnv_00af6540 {
struct Archive;
struct BSFileEntry;
struct FileNameHash;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
struct FileNameHash
{
    unsigned char cLast;
    unsigned int uiCRC;
};
struct Owner25
{
    int FUN_00afa6e0(int arDirectoryHash, int arFileNameHash, int apFileName);
};
struct Archive : public Owner25
{
    unsigned short HasArchiveType(int aeArchiveTypeIndex)
    {
        return *(unsigned short*)((char*)this + 0x180) & (1 << aeArchiveTypeIndex);
    }
};
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            ((NiRefObject*)((char*)m_pObject + 0x158))->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
// @fnv 0x00af6540
BSFileEntry* FindFileEntryInArchives(int aeArchiveTypeIndex, FileNameHash& arDirectoryHash,
                                     FileNameHash& arFileNameHash, const char* apFileName)
{
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        BSFileEntry* pReturn;
        if (sparchive && sparchive->HasArchiveType(aeArchiveTypeIndex))
        {
            pReturn =
                (BSFileEntry*)sparchive->FUN_00afa6e0((int)&arDirectoryHash, (int)&arFileNameHash, (int)apFileName);
            if (pReturn)
                return pReturn;
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    return 0;
}
}  // namespace fnv_00af6540

struct MemMgr_00affd80
{
    void* Allocate(unsigned int);
};
struct DeallocMM_00affd80
{
    void _DeallocateAlias(void*);
};
extern MemMgr_00affd80 _g_memoryManager;
extern int DAT_010a2480;
extern unsigned int DAT_011acff8;
extern __declspec(thread) int DAT_tls_memctx;
__forceinline void* operator new[](unsigned int auiSize)
{
    return _g_memoryManager.Allocate(auiSize);
}
__forceinline void operator delete[](void* apMem)
{
    ((DeallocMM_00affd80*)&_g_memoryManager)->_DeallocateAlias(apMem);
}
__forceinline int GetMemCtx_00affd80()
{
    return DAT_tls_memctx;
}
__forceinline void SetMemCtx_00affd80(int aiCtx)
{
    DAT_tls_memctx = aiCtx;
}
struct MemCtxScope_00affd80
{
    int iOld;
    __forceinline MemCtxScope_00affd80(int aiCtx)
    {
        iOld = GetMemCtx_00affd80();
        DAT_tls_memctx = aiCtx;
    }
    __forceinline ~MemCtxScope_00affd80()
    {
        SetMemCtx_00affd80(iOld);
    }
};
struct FUN_00affd80_t : public BSFile
{
    bool SetBufferSize(unsigned int auiSize);
};
// @fnv 0x00affd80
bool FUN_00affd80_t::SetBufferSize(unsigned int auiSize)
{
    bool bResult = true;
    unsigned int uiFileSize = GetSize();
    unsigned int uiMax2 = uiFileSize < 0x4000 ? 0x4000 : uiFileSize;
    if (auiSize > uiMax2)
        auiSize = uiMax2;
    if (auiSize == m_uiBufferAllocSize)
        return bResult;
    MemCtxScope_00affd80 kCtx3(0x17);
    NiFile::Seek(0, DAT_010a2480);
    Flush();
    delete[] m_pBuffer;
    m_uiBufferAllocSize = auiSize;
    m_pBuffer = new char[m_uiBufferAllocSize];
    if (!m_pBuffer)
    {
        m_uiBufferAllocSize = DAT_011acff8;
        m_pBuffer = new char[m_uiBufferAllocSize];
        bResult = false;
    }
    m_uiBufferSize = 0;
    return bResult;
}

namespace fnv_00af96d0 {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

struct MemMgrStand
{
    void* Allocate(unsigned int auiSize);
    void Deallocate(void* apMem);
};
extern MemMgrStand g_arcMemMgr;
extern int DAT_011ace04;
extern int DAT_010a2480;

inline void* operator new[](unsigned int auiSize)
{
    return g_arcMemMgr.Allocate(auiSize);
}
inline void operator delete[](void* apMem)
{
    g_arcMemMgr.Deallocate(apMem);
}

struct ArcFolderRec
{
    int unk00;
    int unk04;
    unsigned int uiFileCount;
    unsigned int unk0c;
};

struct ArcStream;
typedef unsigned int(__cdecl* ArcReadFn)(ArcStream*, void*, unsigned int, unsigned int*, unsigned int);

struct ArcStream
{
    virtual ~ArcStream();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int aiOffset, int aiWhence);
    unsigned int m_uiStreamFlags;
    ArcReadFn m_pfnRead;
    inline unsigned int BinaryRead(void* apBuffer, unsigned int auiBytes, unsigned int* apuiSizes, unsigned int auiNum)
    {
        unsigned int uiRead = m_pfnRead(this, apBuffer, auiBytes, apuiSizes, auiNum);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

inline unsigned int ArcLoadChars(ArcStream& arStream, char* apBuffer, unsigned int auiCount)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = arStream.BinaryRead(apBuffer, auiCount, &uiCompSize, 1);
    return uiRet;
}

struct ArcStand : public ArcStream
{
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    unsigned int uiFlags;
    int unk170;
    int unk174;
    int unk178;
    unsigned int uiNamesLength;
    int unk180;
    ArcFolderRec* pFolders;
    int unk188;
    int unk18c;
    unsigned int uiNamesOffset;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    unsigned char m_ucEntryType;
    char unk1b5;
    char unk1b6;
    char unk1b7;
    int unk1b8;
    int unk1bc;
    char* pNameBuffer;
    unsigned int** ppFileNameOffsets;
    bool FUN_00afb170(bool, int);
    inline bool HasNameTable()
    {
        return m_ucEntryType & 0x20;
    }
    inline bool HasFileNames()
    {
        return (uiFlags & 2) != 0;
    }
    inline bool HasFlag20()
    {
        return (uiFlags & 0x20) != 0;
    }
    inline bool CheckCache(bool abFlag, int aiVal)
    {
        return FUN_00afb170(abFlag, aiVal);
    }
    static inline int GetCacheVal()
    {
        return DAT_011ace04;
    }
    inline unsigned int GetFolderFileCount(unsigned int auiFolder)
    {
        return pFolders[auiFolder].uiFileCount;
    }
    inline void CopyName(char* apDest, const char* apSrc)
    {
        strcpy_s(apDest, 0x100, apSrc);
    }
    char* FUN_00af96d0(unsigned int auiFolder, unsigned int auiFile);
};

// @fnv 0x00af96d0
char* ArcStand::FUN_00af96d0(unsigned int auiFolder, unsigned int auiFile)
{
    if (HasNameTable())
    {
        return ppFileNameOffsets[auiFolder][auiFile] + pNameBuffer;
    }
    else if (HasFileNames())
    {
        if (pNameBuffer)
        {
            delete[] pNameBuffer;
            pNameBuffer = 0;
        }
        unsigned int uiPos = 0;
        pNameBuffer = new char[0x100];
        if (CheckCache(HasFlag20(), GetCacheVal()))
        {
            unsigned int uiNameOffset = uiNamesOffset + ppFileNameOffsets[auiFolder][auiFile];
            Seek(uiNameOffset, DAT_010a2480);
            ArcLoadChars(*this, pNameBuffer + uiPos, 1);
            while (pNameBuffer[uiPos++])
            {
                ArcLoadChars(*this, pNameBuffer + uiPos, 1);
            }
            return pNameBuffer;
        }
        else
        {
            char* pNamesBlock = new char[uiNamesLength + 1];
            Seek(uiNamesOffset, DAT_010a2480);
            ArcLoadChars(*this, pNamesBlock, uiNamesLength);
            pNamesBlock[uiNamesLength] = 0;
            char* pCurName = pNamesBlock;
            for (unsigned int i = 0; i < auiFolder; i++)
            {
                for (unsigned int j = 0; j < GetFolderFileCount(i); j++)
                {
                    pCurName += strlen(pCurName) + 1;
                    if (pCurName >= pNamesBlock + uiNamesLength)
                    {
                        *pNameBuffer = 0;
                        delete[] pNamesBlock;
                        return pNameBuffer;
                    }
                }
            }
            for (unsigned int k = 0; k < auiFile; k++)
            {
                pCurName += strlen(pCurName) + 1;
                if (pCurName >= pNamesBlock + uiNamesLength)
                {
                    *pNameBuffer = 0;
                    delete[] pNamesBlock;
                    return pNameBuffer;
                }
            }
            CopyName(pNameBuffer, pCurName);
            delete[] pNamesBlock;
            return pNameBuffer;
        }
    }
    return 0;
}
}  // namespace fnv_00af96d0

struct ArcCS
{
    int unk00;
};
struct ArcCS;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(ArcCS*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(ArcCS*);
struct ArchiveStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual unsigned int ReadRaw(void* apBuffer, unsigned int auiSize);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    ArcCS kCS;
    unsigned int GetTruePos()
    {
        return unk038 != -1 ? unk038 : unk150;
    }
    void Lock()
    {
        EnterCriticalSection(&kCS);
    }
    void Unlock()
    {
        LeaveCriticalSection(&kCS);
    }
};

struct FUN_00afbc70_shell : public ArchiveFile
{
    ArchiveStub* GetArchive()
    {
        return (ArchiveStub*)m_pArchive;
    }
    void LockArchive(char* apName)
    {
        if (GetArchive())
            GetArchive()->Lock();
    }
    unsigned int GetTruePos()
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
    unsigned int ReadFromArchive(void* apBuffer, unsigned int auiSize);
};

// @fnv 0x00afbc70
unsigned int FUN_00afbc70_shell::ReadFromArchive(void* apBuffer, unsigned int auiSize)
{
    unsigned int uiRead = 0;
    LockArchive(GetArchive()->FileName());
    unsigned int uiPos = m_uiFileIndex + GetTruePos();
    if (GetArchive()->GetTruePos() != uiPos)
        GetArchive()->Seek(uiPos, 0);
    uiRead = GetArchive()->ReadRaw(apBuffer, m_uiValueId);
    m_uiBufferSize += uiRead;
    if (GetArchive())
        GetArchive()->Unlock();
    return uiRead;
}

namespace fnv_00afbde0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

template <class T> class NiPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct ArcStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual unsigned int ReadArc(void* buf, unsigned int size);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_iBufferSize;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    int csLock;
    unsigned int GetPos() const
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
};

struct ArcFileX
{
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_iBufferSize;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
    NiPointer<ArcStream> m_pArchive;
    unsigned int m_uiFileIndex;
    unsigned int GetPos() const
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
    void LockArc(const char* apName)
    {
        if (m_pArchive)
            EnterCriticalSection(&m_pArchive->csLock);
    }
    unsigned int FUN_00afbde0(void* buf, unsigned int size);
};

// @fnv 0x00afbde0
unsigned int ArcFileX::FUN_00afbde0(void* apBuffer, unsigned int size)
{
    unsigned int uiRead = 0;
    LockArc(m_pArchive->FileName());
    unsigned int uiPos = m_uiFileIndex + GetPos();
    if (m_pArchive->GetPos() != uiPos)
        m_pArchive->Seek(uiPos, 0);
    uiRead = m_pArchive->ReadArc(apBuffer, m_uiValueId);
    m_uiBufferSize += uiRead;
    if (m_pArchive)
        LeaveCriticalSection(&m_pArchive->csLock);
    return uiRead;
}
}  // namespace fnv_00afbde0

struct ArchiveEntryBuf
{
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct ArchiveArray
{
    ArchiveEntryBuf** data;
    unsigned int size;
    unsigned int alloc;
    virtual ~ArchiveArray();
    unsigned int GetSize() const
    {
        return size;
    }
    ArchiveEntryBuf* GetAt(unsigned int idx) const
    {
        return data[idx];
    }
};

class ArchiveRefObject
{
  public:
    virtual ~ArchiveRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct ArchiveFileBase
{
    int unk000;
};

class ArchiveObj : public BSFile, public ArchiveRefObject
{
};

class ArchivePtr
{
  public:
    ArchiveObj* m_pObject;
    ArchivePtr(ArchiveObj* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ArchivePtr& operator=(const ArchivePtr& ptr);
    ArchivePtr& operator=(ArchiveObj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ArchiveList
{
    ArchivePtr m_item;
    ArchiveList* m_pkNext;
    ~ArchiveList();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            ArchiveList* pNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            ArchiveList* pDel = m_pkNext;
            delete pDel;
            m_pkNext = pNext;
        }
        m_item = ArchivePtr(0);
    }
};

extern ArchiveArray* DAT_011f8168;
extern ArchiveArray* DAT_011f816c;
extern ArchivePtr DAT_011f8190[2][9];
inline ArchivePtr& GetArchivePtr(int aiType, unsigned int auiIndex)
{
    return DAT_011f8190[aiType][auiIndex];
}

// Frees the archive list and both archive arrays, then clears the two rows of archive pointers.
// @fnv 0x00af5820
void __cdecl ClearArchiveTables()
{
    unsigned int i;
    unsigned int uiIndex2;
    unsigned int k;

    if (DAT_011f8160)
    {
        reinterpret_cast<ArchiveList*>(DAT_011f8160)->RemoveAll();
        delete reinterpret_cast<ArchiveList*>(DAT_011f8160);
        DAT_011f8160 = 0;
    }
    if (DAT_011f8168)
    {
        for (i = 0; i < DAT_011f8168->GetSize(); i++)
        {
            delete DAT_011f8168->GetAt(i);
        }
        delete DAT_011f8168;
    }
    if (DAT_011f816c)
    {
        for (uiIndex2 = 0; uiIndex2 < DAT_011f816c->GetSize(); uiIndex2++)
        {
            delete DAT_011f816c->GetAt(uiIndex2);
        }
        delete DAT_011f816c;
    }
    for (k = 0; k < 9; k++)
    {
        GetArchivePtr(0, k) = 0;
        GetArchivePtr(1, k) = 0;
    }
}

struct RefCounted_af5
{
    virtual ~RefCounted_af5();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct ArchiveRef_af5 : public BSFile, public RefCounted_af5
{
    bool HasFile(FileNameHash* apDirHash, FileNameHash* apFileHash, const char* apName);
};

template <class T> struct ArcPtr_af5
{
    T* m_pObject;
    ArcPtr_af5(T* const& p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArcPtr_af5()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct ArcNode_af5
{
    ArchiveRef_af5* item;
    ArcNode_af5* next;
};

// Normalizes apName, hashes it into directory and file hashes, then walks the archive list and returns true if any archive contains the file.
// @fnv 0x00af5e40
bool __cdecl HasFileInArchives(const char* apName)
{
    if (!DAT_011f8160)
        return false;
    apName = SkipDataPrefix(apName);
    FileNameHash kDirHash6;
    FileNameHash kFileHash;
    HashPathComponents(apName, &kDirHash6, &kFileHash);
    ArcNode_af5* pNode = (ArcNode_af5*)DAT_011f8160;
    while (pNode)
    {
        ArcPtr_af5<ArchiveRef_af5> spArchive3(pNode->item);
        if (spArchive3 && spArchive3->HasFile(&kDirHash6, &kFileHash, apName))
            return true;
        pNode = pNode->next;
    }
    return false;
}

namespace fnv_00af6690 {
struct BSRefCountedStub
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long refCount;

    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

struct ArchiveStub : public BSFile, public BSRefCountedStub
{
    int unk160;
    int unk164;
    int unk168;
    unsigned int uiFlags;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short usTypes;

    int FindEntry(int a, int b, int c);
    unsigned short HasType(unsigned int auiMask) const
    {
        return (unsigned short)(usTypes & auiMask);
    }
};

template <class T> struct ArchivePtr
{
    T* m_pObject;

    ArchivePtr(const ArchivePtr& rhs) : m_pObject(rhs.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArchivePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct ArchiveNode
{
    ArchivePtr<ArchiveStub> spItem;
    ArchiveNode* next;
};
extern ArchiveNode* g_pArchiveList;

// Walks the archive list and returns the first FindEntry result from an archive whose types match auiTypes, or 0.
// @fnv 0x00af6690
int __cdecl FindEntryInArchives(unsigned int auiTypes, int aiArg1, int aiArg2, int aiArg3)
{
    ArchiveNode* pNode = g_pArchiveList;
    while (pNode)
    {
        ArchivePtr<ArchiveStub> m_pArchive(pNode->spItem);
        if (m_pArchive && m_pArchive->HasType(auiTypes))
        {
            int iResult = m_pArchive->FindEntry(aiArg1, aiArg2, aiArg3);
            if (iResult)
                return iResult;
        }
        pNode = pNode->next;
    }
    return 0;
}
}  // namespace fnv_00af6690

extern ArcCS DAT_011f8170;
struct ArchiveDirectoryIndex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
    unsigned int count;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short types;
    bool FUN_00afdc00(const FileNameHash* key);
};
struct LookupArchive : BSFile
{
    RefObj reference;
    ArchiveDirectoryIndex index;
    unsigned int GetTypes() const
    {
        const LookupArchive* archive = this;
        return archive->index.types;
    }
    bool Contains(const FileNameHash* key)
    {
        return index.FUN_00afdc00(key);
    }
};
__forceinline void AddArchiveReference(RefObj* reference)
{
    InterlockedIncrement(&reference->refs);
}
__forceinline void ReleaseArchiveReference(RefObj* reference)
{
    if (!InterlockedDecrement(&reference->refs))
        reference->v1();
}
struct ScopedArchive
{
    LookupArchive* pointer;
    __forceinline ScopedArchive(Arc* const& value) : pointer((LookupArchive*)value)
    {
        if (pointer)
            AddArchiveReference(&pointer->reference);
    }
    __forceinline ~ScopedArchive()
    {
        if (pointer)
            ReleaseArchiveReference(&pointer->reference);
    }
};
// Searches the archive list under a critical section for an archive whose types match and that contains key, falling back to a type-mismatched match.
// @fnv 0x00af6910
LookupArchive* __cdecl FindArchiveByKey(const FileNameHash* key, unsigned int types)
{
    EnterCriticalSection(&DAT_011f8170);
    LNode* node = DAT_011f8160;
    while (node)
    {
        ScopedArchive archive(node->item);
        if (archive.pointer && ((unsigned short)(archive.pointer->GetTypes() & types) || types == 0xffff) &&
            archive.pointer->Contains(key))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return archive.pointer;
        }
        node = node->next;
    }
    if (types == 0xffff)
        return 0;
    node = DAT_011f8160;
    while (node)
    {
        ScopedArchive archive(node->item);
        if (archive.pointer && !(unsigned short)(archive.pointer->GetTypes() & types) && archive.pointer->Contains(key))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return archive.pointer;
        }
        node = node->next;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}

extern "C" char* __cdecl strrchr(const char*, int);
struct ArchiveRef : RefObj
{
    __forceinline void Retain()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void Release()
    {
        if (!InterlockedDecrement(&refs))
            v1();
    }
};
struct ArchiveView : BSFile
{
    ArchiveRef reference;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int flags;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned short types;
    __forceinline unsigned int GetTypes()
    {
        return types;
    }
};
struct ArchiveOwner
{
    ArchiveView* p;
    __forceinline ArchiveOwner(const ArchiveOwner& archive) : p(archive.p)
    {
        if (p)
            p->reference.Retain();
    }
    __forceinline ~ArchiveOwner()
    {
        if (p)
            p->reference.Release();
    }
    __forceinline operator ArchiveView*()
    {
        return p;
    }
    __forceinline ArchiveView* operator->()
    {
        return p;
    }
};
__forceinline unsigned int CountEntries(LNode* input)
{
    unsigned int node = 0;
    LNode* entry = input;
    while (entry)
    {
        if (entry->item)
            ++node;
        entry = entry->next;
    }
    return node;
}
void** __cdecl FUN_00af7060(ArchiveView*, unsigned int, void**, FileNameHash*, FileNameHash*, LNode*, const char*);
// @fnv 0x00af6ba0
void __cdecl FUN_00af6ba0(LNode* entries, const char* path, const char* directory, unsigned int types)
{
    if (!DAT_011f8160)
        return;
    path = SkipDataPrefix(path);
    char buffer[260];
    strcpy_s(buffer, 260, directory);
    char* last = strrchr(buffer, '\\');
    if (last)
        last[1] = 0;
    if (types == 0xffff)
        types = FUN_00af7d80(path);
    void** value = 0;
    FileNameHash bound, n;
    HashPathComponents(path, &bound, &n);
    unsigned int count_2 = CountEntries(entries);
    for (LNode* archive = DAT_011f8160; archive;)
    {
        ArchiveOwner owner(*(const ArchiveOwner*)&archive->item);
        if (owner && (unsigned short)(owner->GetTypes() & types))
            value = FUN_00af7060(owner, count_2, value, &bound, &n, entries, buffer);
        archive = archive->next;
    }
    if (value)
    {
        for (unsigned int i = 0; i < count_2; ++i)
        {
            delete[] (char*)value[i];
        }
        delete[] value;
    }
}

struct SortKey
{
    unsigned __int64 value;
};
__forceinline int CompareSortKeys(SortKey* current, SortKey* other)
{
    if (current->value < other->value)
        return -1;
    else if (current->value > other->value)
        return 1;
    return 0;
}

// Partitions entries around a pivot key and recurses to sort the range by SortKey value.
// @fnv 0x00af6e50
void __cdecl QuickSortSortKeys(SortKey** entries, int left, int right)
{
    int e = left;
    int l = right;
    int c = left;
    SortKey* j = entries[c];
    while (left < right)
    {
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[right], p = CompareSortKeys(pCurrent, j)) >= 0 && left < right)
                --right;
        }
        if (left != right)
        {
            entries[left] = entries[right];
            ++left;
        }
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[left], p = CompareSortKeys(pCurrent, j)) <= 0 && left < right)
                ++left;
        }
        if (left != right)
        {
            entries[right] = entries[left];
            --right;
        }
    }
    entries[left] = j;
    c = left;
    left = e;
    right = l;
    if (left < c)
        QuickSortSortKeys(entries, left, c - 1);
    if (right > c)
        QuickSortSortKeys(entries, c + 1, right);
}

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct BSIntrusiveRefCounted_af7
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long BackgroundTask;
    void IncRefCount()
    {
        InterlockedIncrement(&BackgroundTask);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&BackgroundTask) == 0)
            DeleteThis();
    }
};

struct Archive_af7
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    BSIntrusiveRefCounted_af7 kRefCounted;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short usFileTypes;

    unsigned short HasFileType(unsigned int auiType)
    {
        return usFileTypes & auiType;
    }
    void ProcessFiles_afac20(int a, int b, int c);
};

struct ArchivePtr_af7
{
    Archive_af7* pObject;
    ArchivePtr_af7(Archive_af7* const& p) : pObject(p)
    {
        if (pObject)
            pObject->kRefCounted.IncRefCount();
    }
    ~ArchivePtr_af7()
    {
        if (pObject)
            pObject->kRefCounted.DecRefCount();
    }
    Archive_af7* operator->() const
    {
        return pObject;
    }
};

struct ArchiveNode_af7
{
    Archive_af7* pItem;
    ArchiveNode_af7* pNext;
    bool IsEmpty() const
    {
        return !pNext && (bool)(int)(pItem == 0);
    }
};

extern ArchiveNode_af7* g_pArchiveList_af7;
extern long g_ArchiveListLock_af7;

// Locks the archive list, calls ProcessFiles_afac20 on every archive whose file types match auiType, then unlocks.
// @fnv 0x00af7c40
void __cdecl ProcessFilesByType(int aiArg1, int aiArg2, unsigned int auiType)
{
    EnterCriticalSection(&g_ArchiveListLock_af7);
    ArchiveNode_af7* pNode = g_pArchiveList_af7;
    while (pNode && !pNode->IsEmpty())
    {
        ArchivePtr_af7 m_pArchive(pNode->pItem);
        if (m_pArchive->HasFileType(auiType))
            m_pArchive->ProcessFiles_afac20(aiArg1, aiArg2, 0);
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&g_ArchiveListLock_af7);
}

struct ArchiveNames : BSFile
{
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int flags;
    unsigned int directoryCount;
    unsigned int fileCount;
    unsigned int unk178;
    unsigned int nameBytes;
    unsigned int unk180;
    Entry16* directories;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int namePosition;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned char nameFlags;
    unsigned int unk1b8;
    unsigned int unk1bc;
    char* names;
    unsigned int** offsets;
    __forceinline void SetNamesReady(bool ready)
    {
        if (ready)
            nameFlags |= 0x20;
        else
            nameFlags &= ~0x20;
    }
    __forceinline unsigned int GetFileCount()
    {
        return fileCount;
    }
    __forceinline unsigned int GetDirectoryCount()
    {
        return directoryCount;
    }
    __forceinline unsigned int GetNameBytes()
    {
        return nameBytes;
    }
    __forceinline bool HasNames()
    {
        return (flags & 2) != 0;
    }
    __forceinline unsigned int GetDirectoryFiles(unsigned int index)
    {
        return directories[index].c;
    }
    __forceinline unsigned int ReadNames(void* buffer, unsigned int size, unsigned int* unitSize)
    {
        unsigned int result = ((unsigned int(__cdecl*)(void*, void*, unsigned int, unsigned int*,
                                                       unsigned int))m_pfnRead)(this, buffer, size, unitSize, 1);
        m_uiStreamFlags += result;
        return result;
    }
    __forceinline unsigned int ReadBytes(void* buffer, unsigned int size)
    {
        unsigned int unitSize = 1;
        unsigned int bytesReturned = ReadNames(buffer, size, &unitSize);
        return bytesReturned;
    }
    __forceinline unsigned int NameLength(const char* name)
    {
        return strlen(name);
    }
    void LoadNames();
};
// @fnv 0x00af8f10
void ArchiveNames::LoadNames()
{
    if (!GetFileCount() || (names && offsets))
        return;
    SetNamesReady(false);
    if (offsets)
    {
        for (unsigned int i = 0; i < GetDirectoryCount(); i++)
            delete[] offsets[i];
        delete[] offsets;
    }
    delete[] names;
    names = new char[GetNameBytes()];
    offsets = new unsigned int*[GetDirectoryCount()];
    if (HasNames())
    {
        Seek(namePosition, DAT_010a2480);
        ReadBytes(names, GetNameBytes());
        unsigned int offset = 0;
        for (unsigned int directory = 0; directory < GetDirectoryCount(); directory++)
        {
            offsets[directory] = new unsigned int[GetDirectoryFiles(directory)];
            for (unsigned int file = 0; file < GetDirectoryFiles(directory); file++)
            {
                offsets[directory][file] = offset;
                offset += NameLength(names + offset) + 1;
            }
        }
    }
    SetNamesReady(true);
}

namespace fnv_00af92f0 {
inline void BSFreeMem(void* apMem)
{
    g_memoryManager._DeallocateAlias(apMem);
}

struct ArchiveNames
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    unsigned int uiDirectoryCount;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    unsigned char ucArchiveFlags;
    unsigned char unk1B5;
    unsigned char unk1B6;
    unsigned char unk1B7;
    int unk1B8;
    int unk1BC;
    char* pDirectoryStringsBuffer;
    char** pFileNameStrings;

    bool IsRetainingNames()
    {
        return (ucArchiveFlags & 4) ? true : false;
    }
    unsigned int GetDirectoryCount()
    {
        return uiDirectoryCount;
    }
    void SetNamesFreed(bool abSet)
    {
        if (abSet)
            ucArchiveFlags |= 0x20;
        else
            ucArchiveFlags &= ~0x20;
    }

    void FreeNames(bool abKeepFileNames);
};

// Frees the directory strings buffer and, unless names are retained or kept, the file name strings, then clears the names-freed flag.
// @fnv 0x00af92f0
void ArchiveNames::FreeNames(bool abKeepFileNames)
{
    unsigned int i;
    if (!IsRetainingNames())
    {
        if (pDirectoryStringsBuffer)
        {
            char* pBuf = pDirectoryStringsBuffer;
            g_memoryManager._DeallocateAlias(pBuf);
        }
        pDirectoryStringsBuffer = 0;
        if (pFileNameStrings && !abKeepFileNames)
        {
            for (i = 0; i < GetDirectoryCount(); i++)
            {
                char* pName = pFileNameStrings[i];
                g_memoryManager._DeallocateAlias(pName);
            }
            {
                char** ppNames = pFileNameStrings;
                g_memoryManager._DeallocateAlias(ppNames);
            }
            pFileNameStrings = 0;
        }
    }
    SetNamesFreed(false);
}
}  // namespace fnv_00af92f0

extern "C" void __cdecl FUN_00ecbc5b(char*, unsigned int);
extern int __cdecl _stricmp(const char*, const char*);
void __cdecl FNV_Warning(const char*, ...);
extern const char DAT_010a4518[];
struct MemoryManagerDealloc
{
    void Deallocate(void*);
};
struct ArchiveSearch : ArchiveStub
{
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0;
    unsigned char flags;
    bool Disabled()
    {
        return (flags & 1) ? true : false;
    }
    bool HasNames()
    {
        return (unk16c & 1) != 0;
    }
    unsigned int Count()
    {
        return unk170;
    }
    FileNameHash* GetHash(unsigned int i)
    {
        return (FileNameHash*)(((Entry16*)unk184) + i);
    }
    const char* GetString(unsigned int);
};
inline int FileNameHash::Compare(FileNameHash* rhs)
{
    if (*(unsigned __int64*)this < *(unsigned __int64*)rhs)
        return -1;
    else if (*(unsigned __int64*)this > *(unsigned __int64*)rhs)
        return 1;
    return 0;
}
inline unsigned int TextLength(const char* text)
{
    return _strlen(text);
}
inline void CopyText(char* dst, unsigned int size, const char* src)
{
    _strcpy_s(dst, size, src);
}
inline void LowerText(char* dst, unsigned int size)
{
    FUN_00ecbc5b(dst, size);
}
// @fnv 0x00af9c50
bool S_af9::FindHashEntry(int pKey, int* piIndex, int pPath)
{
    if (((ArchiveSearch*)this)->Disabled())
        return false;
    bool result = false;
    unsigned int index = ((ArchiveSearch*)this)->unk194;
    if (index < ((ArchiveSearch*)this)->Count())
    {
        if (((FileNameHash*)pKey)->Compare(((ArchiveSearch*)this)->GetHash(index)) == 0)
        {
            *piIndex = index;
            result = true;
        }
    }
    if (!result)
    {
        ((ArchiveSearch*)this)->unk198 = -1;
        if (((ArchiveSearch*)this)->Count())
        {
            unsigned int value = 0;
            unsigned int i = ((ArchiveSearch*)this)->Count();
            unsigned int x = 0;
            unsigned int f = 1;
            int s = 0;
            while (f)
            {
                f = (i - value) >> 1;
                x = value + f;
                s = ((FileNameHash*)pKey)->Compare(((ArchiveSearch*)this)->GetHash(x));
                if (s > 0)
                    value = x;
                else if (s < 0)
                    i = x;
                else
                    break;
            }
            if (s == 0)
            {
                *piIndex = x;
                ((ArchiveSearch*)this)->unk194 = x;
                result = true;
                if (pPath && DAT_011f8154 && ((ArchiveSearch*)this)->HasNames())
                {
                    char path[260];
                    _splitpath_s((const char*)pPath, 0, 0, path, 260, 0, 0, 0, 0);
                    const char* y = ((ArchiveSearch*)this)->GetString(x);
                    char* w = new char[TextLength(y) + 1];
                    char* v = new char[TextLength(path) + 1];
                    CopyText(w, _strlen(y) + 1, y);
                    CopyText(v, _strlen(path) + 1, path);
                    v[_strlen(v) - 1] = 0;
                    LowerText(w, _strlen(w) + 1);
                    LowerText(v, _strlen(v) + 1);
                    if (_stricmp(w, v))
                    {
                        FNV_Warning(DAT_010a4518, y, path);
                        result = false;
                    }
                    delete[] w;
                    delete[] v;
                }
            }
        }
    }
    return result;
}

namespace fnv_00afa120 {
struct Entry97
{
    unsigned int hash0, hash1;
    unsigned int size, offset;
};
struct Group97
{
    unsigned int hash0, hash1;
    unsigned int count;
    Entry97* entries;
    unsigned int Size() const
    {
        return count;
    }
};
struct Hash97
{
    int FUN_00afce90(const Entry97&);
};
struct MM97
{
    void* FUN_00aa3e40(unsigned int);
    void FUN_00aa4060(void*);
};
extern MM97 DAT_011f6238;
extern char DAT_010a454c[];
inline void Copy97(char* d, unsigned int n, const char* s)
{
    strcpy_s(d, n, s);
}
void __cdecl FUN_00ecbc5b(char*, unsigned int);
inline void Lower97(char* d, unsigned int n)
{
    FUN_00ecbc5b(d, n);
}
inline unsigned int Length97(const char* s)
{
    return strlen(s);
}
extern "C" char* __cdecl strtok_s(char*, const char*, char**);
extern "C" int __cdecl _stricmp(const char*, const char*);
void __cdecl FUN_005b5e40(const char*, ...);
struct Archive97
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    unsigned int flags;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    Group97* groups;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    unsigned int cached;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    unsigned char status;
    unsigned char unk1b5, unk1b6, unk1b7;
    bool IsFileEntryValid(Entry97*, bool);
    bool FUN_00afb190(Entry97*, const char*);
    const char* FUN_00af96d0(unsigned int, unsigned int);
    bool FUN_00afa120(unsigned int, Hash97*, unsigned int*, const char*, bool);
};
// Looks up an entry in a group by hash, checking the cached index first then binary-searching, and writes the found index to output.
// @fnv 0x00afa120
bool Archive97::FUN_00afa120(unsigned int group, Hash97* hash, unsigned int* puiOutput, const char* path, bool ignore)
{
    if ((status & 1) ? true : false)
        return false;
    bool found5 = false;
    Group97* files31 = &groups[group];
    unsigned int last9 = cached;
    if (last9 < files31->Size())
    {
        Entry97* entry = &files31->entries[last9];
        if (IsFileEntryValid(entry, ignore) && hash->FUN_00afce90(*entry) == 0)
        {
            if (!FUN_00afb190(entry, path))
            {
                *puiOutput = last9;
                found5 = true;
            }
            else
                return false;
        }
    }
    if (!found5 && files31->Size())
    {
        Entry97* candidate26 = 0;
        unsigned int low10 = 0;
        unsigned int high27 = files31->count;
        unsigned int middle91 = 0;
        unsigned int step13 = 1;
        int comparison20 = 0;
        while (step13)
        {
            step13 = (high27 - low10) >> 1;
            middle91 = low10 + step13;
            candidate26 = &files31->entries[middle91];
            comparison20 = hash->FUN_00afce90(*candidate26);
            if (comparison20 > 0)
                low10 = middle91;
            else if (comparison20 < 0)
                high27 = middle91;
            else
                break;
        }
        if (comparison20 == 0 && IsFileEntryValid(candidate26, ignore) && !FUN_00afb190(candidate26, path))
        {
            *puiOutput = middle91;
            cached = middle91;
            found5 = true;
            if (path && DAT_011f8154 && (unsigned char)((flags & 2) ? 1 : 0))
            {
                char filename4[260];
                _splitpath_s(path, 0, 0, 0, 0, filename4, 260, 0, 0);
                const char* original27 = FUN_00af96d0(group, middle91);
                char* left22 = new char[Length97(original27) + 1];
                char* right19 = new char[Length97(filename4) + 1];
                Copy97(left22, Length97(original27) + 1, original27);
                Copy97(right19, Length97(filename4) + 1, filename4);
                char* context20;
                strtok_s(left22, ".", &context20);
                strtok_s(right19, DAT_010a454c, &context20);
                Lower97(left22, Length97(left22) + 1);
                Lower97(right19, Length97(right19) + 1);
                if (_stricmp(left22, right19))
                {
                    FUN_005b5e40("DEFAULT: HashMap Collision between %s and %s", original27, filename4);
                    found5 = false;
                }
                delete[] left22;
                delete[] right19;
            }
        }
    }
    return found5;
}
}  // namespace fnv_00afa120

namespace fnv_00afad00 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
template <unsigned int N> inline int strcat_s(char (&dest)[N], const char* src)
{
    return strcat_s(dest, N, src);
}
int __cdecl FUN_00ecbf05(const char*, int);
extern const char DAT_010a4580[];
extern char DAT_011f8050[];
extern const char DAT_010a4346[];
struct BSHashA
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
inline unsigned int ZeroAD()
{
    return 0;
}
struct SubAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int pad8;
    unsigned int flags;
    void ClearLowAD()
    {
        flags = (ZeroAD() & 0x7fffffff) | (flags & 0x80000000);
    }
};
struct EntryAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int count;
    SubAD* subs;
    unsigned int GetCount() const
    {
        return count;
    }
    SubAD* GetSub(int idx)
    {
        return subs + idx;
    }
};
struct Hash64
{
    unsigned __int64 v;
};
inline int HashCompareAD(const Hash64& a, const Hash64& b)
{
    if (a.v < b.v)
        return -1;
    else if (a.v > b.v)
        return 1;
    return 0;
}
struct ListAD1
{
    int pad0;
    FUN_00afce90_S** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    FUN_00afce90_S** GetItems()
    {
        return items;
    }
    FUN_00afce90_S* GetItemAt(int idx)
    {
        return items[idx];
    }
};
struct ListAD2
{
    int pad0;
    Hash64** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    Hash64** GetItems()
    {
        return items;
    }
    Hash64* GetItemAt(int idx)
    {
        return items[idx];
    }
};
extern ListAD1* DAT_011f816c;
extern ListAD2* DAT_011f8168;
inline ListAD1* List1Ptr()
{
    return DAT_011f816c;
}
inline ListAD2* List2Ptr()
{
    return DAT_011f8168;
}
struct ThisAD
{
    char pad[0x16c];
    unsigned int uiFlags;
    unsigned int count170;
    unsigned int GetCount170() const
    {
        return count170;
    }
    bool CheckFlagAD(unsigned int bit) const
    {
        return (this->uiFlags & bit) != 0;
    }
    char pad174[0x10];
    EntryAD* entries;
    const char* GetString(int);
    void FUN_00b01510(BSHashA*);
    int FUN_00b01590(char*, const char*, BSHashA*);
    int ClearMatchedEntries();
};
// @fnv 0x00afad00
int ThisAD::ClearMatchedEntries()
{
    int count = 0;
    int i;
    EntryAD* entry;
    int handle;
    {
        char buf[260];
        if (DAT_011f816c == 0 && DAT_011f8168 == 0)
            return 0;
        if (this->CheckFlagAD(1) && this->CheckFlagAD(2))
        {
            for (i = 0; i < this->GetCount170(); i++)
            {
                entry = this->entries + i;
                if (DAT_011f816c != 0)
                {
                    bool found = false;
                    int j;
                    for (j = 0; j < List1Ptr()->GetCount(); j++)
                    {
                        FUN_00afce90_S* item = List1Ptr()->GetItemAt(j);
                        if (item->FUN_00afce90(*(unsigned __int64*)entry) == 0)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (found)
                    {
                        int k;
                        for (k = 0; k < entry->GetCount(); k++)
                        {
                            entry->GetSub(k)->ClearLowAD();
                        }
                        count += entry->GetCount();
                        continue;
                    }
                }
                strcpy_s(buf, 260, DAT_010a4580);
                strcat_s(buf, this->GetString(i));
                handle = FUN_00ecbf05(buf, 0);
                if (handle != -1)
                {
                    SubAD* sub;
                    int mm;
                    for (mm = 0; mm < entry->GetCount(); mm++)
                    {
                        bool found2;
                        sub = entry->subs + mm;
                        if (DAT_011f8168 != 0)
                        {
                            found2 = false;
                            int n;
                            for (n = 0; n < List2Ptr()->GetCount(); n++)
                            {
                                Hash64* item2 = List2Ptr()->GetItemAt(n);
                                if (HashCompareAD(*item2, *(Hash64*)sub) == 0)
                                {
                                    found2 = true;
                                    break;
                                }
                            }
                            if (found2)
                            {
                                sub->ClearLowAD();
                                count += 1;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            BSHashA hash;
            this->FUN_00b01510(&hash);
            count = this->FUN_00b01590(DAT_011f8050, DAT_010a4346, &hash);
        }
        return count;
    }
}
}  // namespace fnv_00afad00

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);

struct FUN_00afb520_base
{
    virtual void unk00();
    ~FUN_00afb520_base();
};

struct FUN_00afb520_mm
{
    void FUN_00aa4060(void* p);
};
extern FUN_00afb520_mm DAT_011f6238;

struct FUN_00afb520_sub
{
    virtual void Slot0();
    virtual void Slot1();
    int unk08;
};

class FUN_00afb520_cls : public FUN_00afb520_base
{
  public:
    virtual ~FUN_00afb520_cls();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pBuffer;
    int unk24;
    int unk28;
    unsigned char m_bGood;
    unsigned char unk2D;
    unsigned char unk2E;
    unsigned char unk2F;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int m_spArchive;
};

// @fnv 0x00afb520
FUN_00afb520_cls::~FUN_00afb520_cls()
{
    if (m_pBuffer != 0)
    {
        void* buf = m_pBuffer;
        DAT_011f6238.FUN_00aa4060(buf);
    }
    m_pBuffer = 0;
    m_bGood = 0;
    {
        FUN_00afb520_sub* sub;
        {
            int* pSp = &m_spArchive;
            if (*pSp != 0)
            {
                sub = (FUN_00afb520_sub*)((char*)(*pSp) + 0x158);
                if (TryEnterCriticalSection(&sub->unk08) == 0)
                {
                    sub->Slot1();
                }
            }
        }
    }
}

extern int DAT_010a2484;
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
__forceinline void RenderCopyData(void* dest, const void* source, unsigned int size)
{
    FUN_00ec44d0(dest, source, size);
}
struct ArchiveRead : ArchiveStub
{
    char* FUN_00aa1ac0();
    void FUN_00aa16d0(int, int);
    unsigned int FUN_00aa1570(void*, unsigned int);
    int GetCurrentPos()
    {
        int value = unk01c;
        return value;
    }
    int GetReadSize()
    {
        int value = unk014;
        return value;
    }
    unsigned int GetBufferSize()
    {
        unsigned int value = unk010;
        return value;
    }
    unsigned int GetLength()
    {
        unsigned int value = unk154;
        return value;
    }
    void SetPos(int pos)
    {
        unk018 = pos;
    }
    void SetReadSize(int size)
    {
        unk014 = size;
    }
    void SetTruePos(int pos)
    {
        unk150 = pos;
    }
};
struct Reader078 : ArchiveFile
{
    ArchiveRead* GetArchive()
    {
        return (ArchiveRead*)m_pArchive;
    }
    void LockArchive(char* name)
    {
        if (GetArchive())
            GetArchive()->Lock();
    }
    void UnlockArchive()
    {
        if (GetArchive())
            GetArchive()->Unlock();
    }
    unsigned int ReadAtOffset(char* output, unsigned int size, unsigned int offset);
};
// @fnv 0x00afb7a0
unsigned int Reader078::ReadAtOffset(char* output, unsigned int size, unsigned int offset)
{
    int end;
    int start = 0;
    int position = m_uiFileIndex + m_uiBufferSize + offset;
    LockArchive(GetArchive()->FileName());
    int difference = GetArchive()->GetCurrentPos();
    int read = difference - GetArchive()->GetReadSize();
    if (read <= position && difference > position)
    {
        int bufferOffset = position - read;
        int available = GetArchive()->GetReadSize() - bufferOffset;
        if (available > (int)size)
            available = size;
        RenderCopyData(output, GetArchive()->FUN_00aa1ac0() + bufferOffset, available);
        output += available;
        if (size == available)
        {
            UnlockArchive();
            return size;
        }
        size -= available;
        position += available;
        start = available;
    }
    GetArchive()->SetPos(0);
    GetArchive()->SetReadSize(0);
    if (end = position - difference)
    {
        GetArchive()->FUN_00aa16d0(end, DAT_010a2484);
        GetArchive()->SetTruePos(position);
    }
    if (m_uiBufferSize + size + offset > m_uiValueId)
        size = m_uiValueId - (m_uiBufferSize + offset);
    unsigned int copied = 0;
    unsigned int result = 0;
    if ((unsigned int)position < GetArchive()->GetLength())
    {
        if (size < GetArchive()->GetBufferSize())
        {
            result = GetArchive()->FUN_00aa1570(GetArchive()->FUN_00aa1ac0(), size);
            GetArchive()->SetPos(result);
            GetArchive()->SetReadSize(result);
            copied = result < size ? result : size;
            RenderCopyData(output, GetArchive()->FUN_00aa1ac0(), copied);
        }
        else
        {
            result = GetArchive()->FUN_00aa1570(output, size);
            copied = result;
        }
    }
    else
    {
        result = 0;
    }
    GetArchive()->SetTruePos(position + result);
    UnlockArchive();
    return copied + start;
}

struct ArcRefObject
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct ArcObj : public BSFile, public ArcRefObject
{
};
struct ArcPtr
{
    ArcObj* m_pObject;
    ArcPtr(ArcObj* pObject)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ArcPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ArcPtr& operator=(const ArcPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    ArcPtr& operator=(ArcObj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(ArcObj* pObject) const
    {
        return m_pObject == pObject;
    }
    bool operator!=(const ArcPtr& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }
};
struct BSSimpleList
{
    ArcPtr m_item;
    BSSimpleList* m_pkNext;
    ~BSSimpleList()
    {
        RemoveAll();
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            BSSimpleList* pkNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = pkNext;
        }
        m_item = ArcPtr(0);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager._DeallocateAlias(pvMem);
    }
    bool IsEmpty() const
    {
        return m_pkNext == 0 && m_item == 0;
    }
    void RemoveItem(const ArcPtr& item);
};

// Removes the node whose item equals the given ArcPtr from the list, unlinking it and deleting it, or clearing the head item if it is the only node.
// @fnv 0x00afc960
void BSSimpleList::RemoveItem(const ArcPtr& item)
{
    if (item == 0 || IsEmpty())
        return;
    BSSimpleList* pkCur = this;
    BSSimpleList* pkPrev = this;
    while (pkCur && pkCur->m_item != item)
    {
        pkPrev = pkCur;
        pkCur = pkCur->m_pkNext;
    }
    if (pkCur)
    {
        if (pkCur == this)
        {
            if (m_pkNext)
            {
                pkPrev = m_pkNext;
                m_pkNext = pkPrev->m_pkNext;
                m_item = pkPrev->m_item;
                pkPrev->m_pkNext = 0;
                delete pkPrev;
            }
            else
            {
                m_item = 0;
            }
        }
        else
        {
            pkPrev->m_pkNext = pkCur->m_pkNext;
            pkCur->m_pkNext = 0;
            delete pkCur;
        }
    }
}

struct ListItem
{
    unsigned int value;
    ListItem* next;
    ~ListItem();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct NullRef
{
    Pointee* object;
    NullRef(Pointee* p = 0) : object(p)
    {
        RefObj* pRef;
        if (object)
        {
            RefObj* ref = &object->ro;
            InterlockedIncrement(&ref->refs);
        }
    }
    ~NullRef()
    {
        if (object)
        {
            RefObj* ref = &object->ro;
            if (!InterlockedDecrement(&ref->refs))
                ref->v1();
        }
    }
};

struct OwnerList
{
    Pointee* object;
    ListItem* head;
    OwnerList* FUN_00afc770(const NullRef& rhs)
    {
        RefObj* r0 = 0;
        RefObj* r1 = 0;
        if (object != rhs.object)
        {
            if (object)
            {
                r0 = &object->ro;
                if (!InterlockedDecrement(&r0->refs))
                    r0->v1();
            }
            object = rhs.object;
            if (object)
            {
                r1 = &object->ro;
                InterlockedIncrement(&r1->refs);
            }
        }
        return this;
    }
    void FUN_00afcaf0();
};

// Deletes every node in the head list, resetting each node's next pointer, then releases the object reference via FUN_00afc770 with a null reference.
// @fnv 0x00afcaf0
void OwnerList::FUN_00afcaf0()
{
    while (head)
    {
        ListItem* next = head->next;
        head->next = 0;
        delete head;
        head = next;
    }
    FUN_00afc770(NullRef());
}

namespace fnv_00af5480 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plong);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plong);

struct RefBase_af5480
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct ObjBase_af5480
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
};

struct Obj_af5480 : ObjBase_af5480, RefBase_af5480
{
};

template <class T> struct NiPtr_af5480
{
    T* m_pObject;
    NiPtr_af5480(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPtr_af5480()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct MemoryManager_af5480
{
    void* Allocate(unsigned int uiSize);
};

extern MemoryManager_af5480 g_memoryManager_af5480;

struct NP_af5480
{
    NP_af5480* FUN_00afc770(NP_af5480* pkOther);
};

struct LNode_af5480
{
    Obj_af5480* m_pObject;
    LNode_af5480* m_pNext;
    void AddTail(NiPtr_af5480<Obj_af5480>& sp)
    {
        if (!sp.m_pObject)
            return;
        LNode_af5480* pNode = this;
        while (pNode->m_pNext)
            pNode = pNode->m_pNext;
        if (pNode->m_pObject)
        {
            LNode_af5480* pNew = (LNode_af5480*)g_memoryManager_af5480.Allocate(8);
            LNode_af5480* pInsert;
            if (pNew)
            {
                Obj_af5480* pkObject = sp.m_pObject;
                pNew->m_pObject = pkObject;
                if (pkObject)
                    pkObject->IncRefCount();
                pNew->m_pNext = 0;
                pInsert = pNew;
            }
            else
            {
                pInsert = 0;
            }
            pNode->m_pNext = pInsert;
        }
        else
        {
            NP_af5480* pOther = (NP_af5480*)pNode;
            NP_af5480* pSp = (NP_af5480*)&sp;
            pOther->FUN_00afc770(pSp);
        }
    }
};

extern LNode_af5480* g_pNode_11f8160;
extern char g_kCS_11f8170[];

// Locks g_kCS_11f8170, appends pkObj to the list at g_pNode_11f8160 via AddTail, then unlocks.
// @fnv 0x00af5480
void __cdecl AddObjectToList(Obj_af5480* pkObj)
{
    EnterCriticalSection(g_kCS_11f8170);
    if (g_pNode_11f8160)
    {
        NiPtr_af5480<Obj_af5480> sp(pkObj);
        g_pNode_11f8160->AddTail(sp);
    }
    LeaveCriticalSection(g_kCS_11f8170);
}
}  // namespace fnv_00af5480

namespace fnv_00af5550 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    volatile long m_uiRefCount;
};

class MyArchiveFile : public BSFile, public NiRefObject
{
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    NiPointer(T* pObject = (T*)0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    operator T*() const
    {
        return m_pObject;
    }

    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct LNode
{
    NiPointer<MyArchiveFile> item;
    LNode* next;

    void DeleteNode(LNode* n);
    LNode* FUN_00afc770(LNode* a2);

    void Remove(NiPointer<MyArchiveFile>& target)
    {
        LNode* head = (LNode*)0;
        LNode* tail = (LNode*)0;
        LNode* pNext = (LNode*)0;
        LNode* pPrev = (LNode*)0;
        if (!target.m_pObject)
            return;
        if (!next && !item.m_pObject)
            return;
        LNode* curr = this;
        LNode* prev = this;
        while (curr && curr->item.m_pObject != target.m_pObject)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
            return;
        if (curr == this)
        {
            if (next)
            {
                prev = next;
                next = prev->next;
                FUN_00afc770(prev);
                prev->next = (LNode*)0;
                DeleteNode(prev);
            }
            else
            {
                item = (MyArchiveFile*)0;
            }
        }
        else
        {
            prev->next = curr->next;
            curr->next = (LNode*)0;
            DeleteNode(curr);
        }
    }
};

extern LNode* g_pLNode;
struct _RTL_CRITICAL_SECTION;
extern _RTL_CRITICAL_SECTION g_cs;
extern NiPointer<MyArchiveFile> g_activeFile;
extern NiPointer<MyArchiveFile> g_files[2][9];

inline NiPointer<MyArchiveFile>& GetFile(int j, unsigned int i)
{
    return g_files[j][i];
}

// @fnv 0x00af5550
bool __cdecl RemoveArchiveFile(MyArchiveFile* apFile)
{
    if (!g_pLNode || !apFile)
        return false;

    EnterCriticalSection(&g_cs);

    unsigned int i;
    {
        NiPointer<MyArchiveFile> sp(apFile);
        g_pLNode->Remove(sp);
    }

    for (i = 0; i < 9; ++i)
    {
        if (GetFile(0, i) == apFile)
            GetFile(0, i) = (MyArchiveFile*)0;
        if (GetFile(1, i) == apFile)
            GetFile(1, i) = (MyArchiveFile*)0;
    }

    if ((bool)(int)(g_activeFile == apFile))
        g_activeFile = (MyArchiveFile*)0;

    LeaveCriticalSection(&g_cs);
    return true;
}
}  // namespace fnv_00af5550

namespace fnv_00af4550 {
extern const char DAT_010a4398[];
extern const char DAT_010a43a8[];
extern unsigned char DAT_011acdf8;
extern const char* DAT_011f8158;
extern const char* DAT_011f815c;
extern const char DAT_010a433a[];
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" int __cdecl _stricmp(const char*, const char*);
extern "C" int __cdecl fopen_s(_iobuf**, const char*, const char*);
extern "C" int __cdecl feof(_iobuf*);
extern "C" char* __cdecl fgets(char*, int, _iobuf*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" int __cdecl _access(const char*, int);
extern "C" char* __cdecl strtok_s(char*, const char*, char**);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct ArchiveRef
{
    virtual void slot0();
    virtual void Destroy();
    long count;
    inline void AcquireReference()
    {
        InterlockedIncrement(&count);
    }
    inline void DecRef()
    {
        if (!InterlockedDecrement(&count))
            Destroy();
    }
};
class Archive : public BSFile
{
  public:
    ArchiveRef refs;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned short types;
    inline unsigned short HasType(unsigned int i)
    {
        return (unsigned short)(types & (1 << i));
    }
    inline unsigned long BufferSize()
    {
        return m_uiBufferAllocSize;
    }
    bool SetBufferSize(unsigned int);
};
template <class T> struct ArchivePointer
{
    T* ptr;
    inline ArchivePointer(T* p) : ptr(p)
    {
        if (ptr)
            ptr->refs.AcquireReference();
    }
    inline ~ArchivePointer()
    {
        if (ptr)
            ptr->refs.DecRef();
    }
    inline operator T*() const
    {
        return ptr;
    }
    inline T* operator->() const
    {
        return ptr;
    }
    inline T* GetForAssignment() const
    {
        T* previous;
        unsigned long previousCount;
        return ptr;
    }
    void FUN_00afd1b0(T*);
};
struct ArchiveName
{
    char name[8];
};
extern ArchiveName DAT_011ace08[26];
inline unsigned int MainArchiveGroup()
{
    return 0;
}
extern ArchivePointer<Archive> DAT_011f8190[2][9];
extern unsigned int DAT_011aced8[9];
struct ArchiveMemory
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern ArchiveMemory DAT_011f6238;
void __cdecl FUN_00af5ab0(const char*);
void* __cdecl FUN_00af4be0(const char*, int, int);
inline char* AllocationResult(char* const& result)
{
    return result;
}
inline void ArchiveFree(void* const& data)
{
    DAT_011f6238.Deallocate(data);
}
inline int CopyPath(char* dest, unsigned int size, const char* source)
{
    return strcpy_s(dest, size, source);
}
inline int AppendPath(char* dest, unsigned int size, const char* source)
{
    return strcat_s(dest, size, source);
}
inline unsigned long TextLength(const char* text)
{
    return strlen(text);
}
// Builds a comma-separated list of .bsa files from Plugins.txt, loads each archive and registers it by type, returning false if any archive fails to load.
// @fnv 0x00af4550
bool __cdecl FUN_00af4550()
{
    _iobuf* flags;
    char extra[260];
    unsigned int kSound;
    char* time;
    char* pItem;
    {
        bool pForm = true;
        {
            char pInfo[260];
            {
                char pResponse[260];
                {
                    unsigned long zz;
                    {
                        char* zz2;
                        if (!DAT_011acdf8)
                            return pForm;
                        FUN_00af5ab0(DAT_011f8158);
                        for (unsigned int i = 0; i < 25; i++)
                        {
                            unsigned int minimum = i;
                            for (unsigned int j = i + 1; j < 26; j++)
                            {
                                if (_stricmp(DAT_011ace08[j].name, DAT_011ace08[minimum].name) < 0)
                                    minimum = j;
                            }
                            if (i != minimum)
                            {
                                ArchiveName temp = DAT_011ace08[i];
                                DAT_011ace08[i] = DAT_011ace08[minimum];
                                DAT_011ace08[minimum] = temp;
                            }
                        }
                        zz = GetTickCount();
                        kSound = 32768;
                        zz2 = AllocationResult((char*)DAT_011f6238.Allocate(kSound));
                        CopyPath(zz2, kSound, DAT_011f815c);
                        sprintf_s(pResponse, 260, "%sPlugins.txt", DAT_010a433a + 1);
                        flags = 0;
                        fopen_s(&flags, pResponse, "r");
                        if (flags)
                        {
                            while (!feof(flags))
                            {
                                fgets(extra, 260, flags);
                                if (extra[0] != '#' && extra[0] && extra[0] != '\n')
                                {
                                    char* ext = strstr(extra, ".esp");
                                    if (!ext)
                                        ext = strstr(extra, ".esm");
                                    if (ext)
                                    {
                                        strcpy_s(ext, 260 - (ext - extra), ".bsa");
                                        strcpy_s(pInfo, 260, DAT_010a4398);
                                        strcat_s(pInfo, 260, extra);
                                        if (_access(pInfo, 0) != -1)
                                        {
                                            if (zz2[TextLength(zz2) - 2] == '\n')
                                                zz2[TextLength(zz2) - 2] = 0;
                                            AppendPath(zz2, 260, ", ");
                                            AppendPath(zz2, 260, extra);
                                        }
                                    }
                                }
                            }
                        }
                        pItem = zz2;
                        time = zz2;
                        strtok_s(time, ",", &zz2);
                        while (*time)
                        {
                            while (*time == ' ' || *time == '\t' || *time == '\n')
                                time++;
                            ArchivePointer<Archive> archive = (Archive*)FUN_00af4be0(time, 0, 0);
                            if (archive)
                            {
                                for (unsigned int kind = 0; kind < 9; kind++)
                                {
                                    if (archive->HasType(kind))
                                    {
                                        if (!DAT_011f8190[MainArchiveGroup()][kind])
                                        {
                                            DAT_011f8190[MainArchiveGroup()][kind].FUN_00afd1b0(
                                                archive.GetForAssignment());
                                            if (DAT_011aced8[kind] > archive->BufferSize())
                                                archive->SetBufferSize(DAT_011aced8[kind]);
                                        }
                                    }
                                }
                            }
                            else
                                pForm = false;
                            time = zz2;
                            strtok_s(time, DAT_010a43a8, &zz2);
                        }
                        ArchiveFree((void*)pItem);
                        zz = GetTickCount() - zz;
                        return pForm;
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00af4550

// @fnv 0x00af59e0
void __cdecl FUN_00af59e0()
{}

namespace fnv_00afd4e0 {
struct FileNameHash
{
    unsigned char unk00, unk01, unk02, unk03;
    unsigned int unk04;
};
int __cdecl FUN_00ec67aa(int);
extern char DAT_011acfbc[6][10];
// Hashes a name (and optional extension) into out's bytes and hash field, using FUN_00ec67aa per character and matching the extension against DAT_011acfbc.
// @fnv 0x00afd4e0
void __cdecl ComputeNameHash(const unsigned char* name, const unsigned char* extension, FileNameHash* out)
{
    const unsigned char* p;
    unsigned int hash4;
    int c3;
    out->unk03 = (unsigned char)FUN_00ec67aa(name[0]);
    out->unk04 = 0;
    hash4 = 0;
    if (!out->unk03)
    {
        out->unk02 = 0;
        out->unk01 = 0;
        out->unk00 = 0;
        return;
    }
    p = name + 1;
    if (p[0] && p[1] && p[2] && p[3] && false)
    {
        unsigned int count8 = 5;
        const unsigned char* endVal = p + 4;
        out->unk03 = (unsigned char)FUN_00ec67aa(p[2]);
        while (*endVal)
        {
            c3 = FUN_00ec67aa(*p);
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++count8;
            ++p;
            ++endVal;
        }
        out->unk02 = (unsigned char)count8;
        out->unk04 = hash4;
        out->unk01 = (unsigned char)FUN_00ec67aa(p[0]);
        out->unk00 = (unsigned char)FUN_00ec67aa(p[1]);
    }
    else if (p[0] && p[1])
    {
        unsigned int count4 = 3;
        const unsigned char* aEnd2 = p + 2;
        while (*aEnd2)
        {
            c3 = FUN_00ec67aa(*p);
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++count4;
            ++p;
            ++aEnd2;
        }
        out->unk02 = (unsigned char)count4;
        out->unk04 = hash4;
        out->unk01 = (unsigned char)FUN_00ec67aa(p[0]);
        out->unk00 = (unsigned char)FUN_00ec67aa(p[1]);
    }
    else
    {
        if (p[0])
        {
            out->unk00 = (unsigned char)FUN_00ec67aa(p[0]);
            out->unk02 = 2;
        }
        else
        {
            out->unk02 = 1;
            out->unk00 = out->unk03;
        }
        out->unk01 = 0;
    }
    if (extension)
    {
        char ext[16];
        char* dest6 = ext;
        p = extension;
        hash4 = 0;
        while (*p)
        {
            c3 = FUN_00ec67aa(*p);
            *dest6 = (char)c3;
            ++dest6;
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++p;
        }
        *dest6 = 0;
        out->unk04 += hash4;
        unsigned int code7 = *(unsigned int*)ext;
        for (unsigned int i4 = 0; i4 < 6; ++i4)
        {
            unsigned int test3 = *(unsigned int*)DAT_011acfbc[i4];
            if (test3 == code7)
            {
                out->unk03 = out->unk03 + (unsigned char)((i4 << 5) & 0x80);
                out->unk00 = out->unk00 + (unsigned char)((i4 << 6) & 0x80);
                out->unk01 = out->unk01 + (unsigned char)((i4 << 7) & 0x80);
                break;
            }
        }
    }
}
}  // namespace fnv_00afd4e0

namespace fnv_00af4be0 {
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
extern MemoryManagerAllocHelper g_memoryManager;
struct LNode;
extern LNode* DAT_011f8160;
static const char emptyPathWarning[] = "Loading a user created or misnamed BSA";
extern const char DAT_010a4454[];
extern const char DAT_010a444c[];
extern const char DAT_010a4444[];
extern const char DAT_010a443c[];
extern const char DAT_010a4434[];
extern const char DAT_010a442c[];
extern bool DAT_011acdf8;
int __cdecl strcpy_s(char*, unsigned int, const char*);
unsigned int __cdecl strlen(const char*);
const char* __cdecl FUN_00ec7750(const char*, const char*);
void __cdecl FNV_Warning(const char*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct OpenRef
{
    virtual void v0();
    virtual void Destroy();
    long refs;
    void Inc()
    {
        InterlockedIncrement(&refs);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
struct PluginFile
{
    virtual ~PluginFile();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    bool good;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    char name[260];
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    OpenRef ref;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    unsigned short types;
    unsigned short unk182;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    unsigned char flags;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;

    static void* operator new(unsigned int);
    static void operator delete(void*);
    PluginFile(const char*, unsigned int, int, bool);
    bool IsGood()
    {
        return good;
    }
    bool IsBad()
    {
        return (flags & 1) != 0 ? true : false;
    }
    const char* Name()
    {
        return name;
    }
};
struct OpenPtr
{
    PluginFile* p;
    OpenPtr(PluginFile* a) throw() : p(a)
    {
        if (p)
            p->ref.Inc();
    }
    ~OpenPtr()
    {
        if (p)
            p->ref.Dec();
    }
    operator PluginFile*() const
    {
        return p;
    }
    OpenPtr& operator=(const OpenPtr&);
    OpenPtr(const OpenPtr& a) throw() : p(a.p)
    {
        if (p)
            p->ref.Inc();
    }
};

struct OpenNode
{
    OpenPtr item;
    OpenNode* next;
    static void* operator new(unsigned int size)
    {
        return ((MemoryManagerAllocHelper*)&g_memoryManager)->Allocate(size);
    }
    OpenNode() throw() : item(0), next(0)
    {}
    OpenNode(const OpenPtr& p) throw() : item(p), next(0)
    {}
    static OpenNode* Create(const OpenPtr& value)
    {
        OpenNode* result = new OpenNode(value);
        return result;
    }
    static OpenNode* CreateDirect(const OpenPtr& value)
    {
        return new OpenNode(value);
    }
    void InsertCurrent(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* insertedNode = CreateDirect(item);
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void PushArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* allocatedNode = Create(item);
            OpenNode* insertedNode = allocatedNode;
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void AppendArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        OpenNode* tail = this;
        while (tail->next)
            tail = tail->next;
        if (tail->item.p)
        {
            OpenNode* allocated = Create(value);
            OpenNode* created = allocated;
            tail->next = created;
        }
        else
            tail->item = value;
    }
};

struct OpenFinder
{
    int Find(const char*, char*, int, int);
};
extern OpenFinder* g_fileFinder;
struct OpenPaths
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Resolve(const char*, char*);
    bool Check(int);
};
OpenPaths* __cdecl GetOpenPaths();
__forceinline void SetOpenNode(OpenNode* const& p)
{
    DAT_011f8160 = (LNode*)p;
}
// Opens a BSA archive by path, determines its load rank, and inserts it into the global archive list at the correct priority position.
// @fnv 0x00af4be0
PluginFile* __cdecl FUN_00af4be0(const char* path, unsigned short types, bool option)
{
    if (!DAT_011acdf8)
        return 0;
    char found3[260];
    char resolved2[260];
    strcpy_s(found3, 260, path);
    if (!(g_fileFinder ? g_fileFinder->Find(path, found3, 1, -1) : 0))
        return 0;
    if (GetOpenPaths()->Check((int)found3))
        GetOpenPaths()->Resolve(found3, resolved2);
    else
        strcpy_s(resolved2, 260, found3);
    PluginFile* archive5 = new PluginFile(resolved2, 0x40000, 0, option);
    if (!archive5 || !archive5->IsGood() || archive5->IsBad())
    {
        delete archive5;
        return 0;
    }
    if (!DAT_011f8160)
        SetOpenNode(new OpenNode);
    int rank4 = 0;
    if (path && strlen(path) > 0)
    {
        if (FUN_00ec7750(path, "Fallo"))
            rank4 = 0;
        else if (FUN_00ec7750(path, "DeadM"))
            rank4 = 1;
        else if (FUN_00ec7750(path, "Hones"))
            rank4 = 2;
        else if (FUN_00ec7750(path, "Lones"))
            rank4 = 3;
        else if (FUN_00ec7750(path, "OldWo"))
            rank4 = 4;
        else if (FUN_00ec7750(path, "Updat"))
            rank4 = 5;
        else
        {
            FNV_Warning("Loading a user created or misnamed BSA");
            rank4 = 6;
        }
    }
    else
    {
        FNV_Warning(emptyPathWarning);
        rank4 = 6;
    }
    if (rank4 > 0)
    {
        OpenNode* node5 = (OpenNode*)DAT_011f8160;
        bool inserted7 = false;
        while (node5 && (PluginFile*)node5->item)
        {
            const char* existing3 = ((PluginFile*)node5->item)->Name();
            if (existing3 && strlen(existing3) > 0)
            {
                if (FUN_00ec7750(existing3, DAT_010a442c))
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4434))
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a443c) && rank4 > 1)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4444) && rank4 > 2)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a444c) && rank4 > 3)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4454) && rank4 > 3)
                    inserted7 = true;
            }
            if (inserted7)
            {
                node5->InsertCurrent(archive5);
                break;
            }
            node5 = node5->next;
        }
        if (!inserted7)
            ((OpenNode*)DAT_011f8160)->PushArchive(archive5);
    }
    else
        ((OpenNode*)DAT_011f8160)->AppendArchive(archive5);
    if (types)
        archive5->types = types;
    return archive5;
}
}  // namespace fnv_00af4be0

namespace fnv_00af67d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkCriticalSection);
extern "C" int __cdecl strcpy_s(char* pcDst, unsigned int uiSize, const char* pcSrc);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    long m_uiRefCount;
};
static __forceinline void AcquireReference(NiRefObject* o)
{
    o->IncRefCount();
}
template <class T> class NiPointer
{
  public:
    NiPointer(T* pObj = 0)
    {
        m_pObject = pObj;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct ArchiveFileEntry
{
    unsigned int uiNameHash;
    unsigned int uiDirHash;
    unsigned int uiReserved;
    unsigned int uiSize;
};
class Archive : public BSFile, public NiRefObject
{
  public:
    void Lock()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void Unlock()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
    const char* FUN_00af9ba0(ArchiveFileEntry* pkEntry);
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int m_kCriticalSection;
};
extern Archive* DAT_011f8190[2][9];

static __forceinline Archive* GetArc(bool c, unsigned int i)
{
    return DAT_011f8190[c ? 1 : 0][i];
}
// Looks up the file path for an archive entry by index and compressed flag, copying it into pcOutput and returning whether a path was found.
// @fnv 0x00af67d0
bool __cdecl FUN_00af67d0(unsigned int uiIndex, ArchiveFileEntry* pkEntry, char* pcOutput)
{
    bool bHasPath = false;
    bool bIsCompressed = (pkEntry->uiSize & 0x80000000);
    NiPointer<Archive> spCurrent = GetArc(bIsCompressed, uiIndex);
    if (spCurrent)
    {
        spCurrent->Lock();
        const char* pcSource = spCurrent->FUN_00af9ba0(pkEntry);
        if (pcSource)
        {
            strcpy_s(pcOutput, 260, pcSource);
            bHasPath = true;
        }
        spCurrent->Unlock();
    }
    return bHasPath;
}
}  // namespace fnv_00af67d0

namespace fnv_00af7060 {
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager _g_memoryManager;
inline void* __cdecl operator new[](unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct ArcCS
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};

struct HashKey
{
    unsigned int low, high;
    const unsigned __int64& Value() const
    {
        return *(const unsigned __int64*)this;
    }
    int Compare(const HashKey* rhs) const
    {
        if (Value() < rhs->Value())
            return -1;
        else if (Value() > rhs->Value())
            return 1;
        return 0;
    }
    int CompareTo(const HashKey* rhs) const
    {
        int order = Compare(rhs);
        return order;
    }
    HashKey(const char*, int);
    void* operator new(unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
};
inline unsigned int CombinedLength(const char* prefix, const char* name)
{
    unsigned int prefixLength = strlen(prefix);
    return prefixLength + strlen(name) + 1;
}
inline void CopyPath(char* dest, unsigned int size, const char* src)
{
    strcpy_s(dest, size, src);
}
inline void AppendPath(char* dest, unsigned int size, const char* src)
{
    strcat_s(dest, size, src);
}
void* __cdecl operator new(unsigned int);
struct PathNode
{
    const char* path;
    PathNode* next;
    PathNode(const PathNode*);
    void FUN_005ae3d0(char* const& value)
    {
        if (!value)
            return;
        if (path)
        {
            PathNode* node = new PathNode(this);
            node->next = next;
            next = node;
            path = value;
        }
        else
        {
            path = value;
        }
    }
};
struct FileRecord
{
    HashKey key;
    unsigned int size, offset;
};
struct DirectoryRecord
{
    unsigned int low, high, count;
    FileRecord* files;
    unsigned int Count()
    {
        return count;
    }
};
struct Filter
{
    int FUN_00afcf00(FileRecord*);
};
struct ArchiveSearch
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    DirectoryRecord* dirs;
    int unk188, unk18c, unk190, unk194, unk198;
    ArcCS lock;
    bool FindHashEntry(int, int*, int);
    bool IsFileEntryValid(FileRecord*, bool);
    const char* FUN_00af96d0(int, unsigned int);
};
void QuickSortSortKeys(HashKey**, unsigned int, unsigned int);
// @fnv 0x00af7060
HashKey** __cdecl FUN_00af7060(ArchiveSearch* archive, unsigned int count, HashKey** keys, int directory,
                               Filter* filter, PathNode* paths, const char* prefix)
{
    EnterCriticalSection(&archive->lock);
    int directoryIndex;
    DirectoryRecord* dir;
    if (archive->FindHashEntry(directory, &directoryIndex, 0))
    {
        if (keys == 0 && count > 0)
        {
            keys = new HashKey*[count];
            PathNode* node = paths;
            for (unsigned int keyIndex = 0; keyIndex < count; ++keyIndex)
            {
                const char* path = node->path;
                keys[keyIndex] = new HashKey(path, 0);
                node = node->next;
            }
            QuickSortSortKeys(keys, 0, count - 1);
        }
        dir = &archive->dirs[directoryIndex];
        for (unsigned int fileIndex = 0; fileIndex < dir->Count(); ++fileIndex)
        {
            FileRecord* file = &dir->files[fileIndex];
            if (archive->IsFileEntryValid(file, false))
            {
                int result = filter->FUN_00afcf00(file);
                if (result == 0)
                {
                    bool found = false;
                    if (count != 0)
                    {
                        unsigned int lower3 = 0;
                        unsigned int upper8 = count;
                        unsigned int middle7 = 0;
                        unsigned int step2 = 1;
                        int compare3 = 0;
                        while (step2 != 0)
                        {
                            step2 = (upper8 - lower3) >> 1;
                            middle7 = lower3 + step2;
                            compare3 = file->key.CompareTo(keys[middle7]);
                            if (compare3 > 0)
                                lower3 = middle7;
                            else if (compare3 < 0)
                                upper8 = middle7;
                            else
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found)
                    {
                        const char* name = archive->FUN_00af96d0(directoryIndex, fileIndex);
                        unsigned int length = CombinedLength(prefix, name);
                        char* full = new char[length];
                        CopyPath(full, length, prefix);
                        AppendPath(full, length, name);
                        paths->FUN_005ae3d0(full);
                    }
                }
                else if (result < 0)
                    break;
            }
        }
    }
    LeaveCriticalSection(&archive->lock);
    return keys;
}
}  // namespace fnv_00af7060

namespace fnv_00af7eb0 {
struct MemoryManager
{
    void* __thiscall Allocate(unsigned int);
    void __thiscall Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
inline void* __cdecl operator new[](unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
inline void* __cdecl operator new(unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
inline void __cdecl operator delete[](void* p)
{
    _g_memoryManager.Deallocate(p);
}
inline void __cdecl operator delete(void* p)
{
    _g_memoryManager.Deallocate(p);
}
extern unsigned int DAT_011f81d8;
extern volatile long DAT_011f4400;
extern unsigned char DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc, DAT_011ace00, DAT_011ace04;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern void(__stdcall* DAT_00fdf054)(void*);
struct Directory077;
struct Entry077
{
    unsigned int hashLow, hashHigh, size;
    Entry077* files;
    Entry077()
    {
        size = 0;
        files = 0;
    }
    void SetFiles(Entry077* p)
    {
        files = p;
    }
};
struct FUN_00afd8b0
{
    unsigned int magic, version, offset, flags, directories, files, dirNamesSize, fileNamesSize;
    unsigned short types, reserved;
    FUN_00afd8b0();
};
struct Header077 : FUN_00afd8b0
{
    Entry077* entries;
    Header077()
    {
        entries = 0;
    }
    unsigned int Count()
    {
        return directories;
    }
    unsigned int DirNamesSize()
    {
        return dirNamesSize;
    }
    unsigned int FileNamesSize()
    {
        return fileNamesSize;
    }
    unsigned int Version()
    {
        return version;
    }
    void SetFiles(unsigned int i, Entry077* p)
    {
        entries[i].SetFiles(p);
    }
    unsigned int FileCount(unsigned int i)
    {
        return entries[i].size;
    }
    bool Valid()
    {
        return magic == 0x415342;
    }
    bool VersionValid()
    {
        return version <= 0x68;
    }
    bool Has(unsigned int flag)
    {
        return (flags & flag) != 0;
    }
    static void SetFlag(unsigned int& field, unsigned int mask, bool value)
    {
        field = value ? field | mask : field & ~mask;
    }
    void SetVersionFlag()
    {
        SetFlag(flags, 0x100, false);
    }
};
struct NiRefObject077
{
    virtual ~NiRefObject077();
    long refs;
    NiRefObject077()
    {
        refs = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
};
struct FUN_00b00260 : BSFile
{
    FUN_00b00260(const char*, int, unsigned int, bool);
    bool FUN_00afb170(bool, int);
    static int CacheMode0()
    {
        return DAT_011acdfc;
    }
    static int CacheMode1()
    {
        return DAT_011ace00;
    }
    static int CacheMode2()
    {
        return DAT_011ace04;
    }
    bool NeedCache();
};
struct Critical077
{
    int debug, lock, recursion, owner, semaphore, spin;
    Critical077()
    {
        DAT_00fdf054(this);
    }
    ~Critical077();
};
struct FileStat077
{
    unsigned int dev;
    unsigned short inode, mode, links, uid, gid, alignment;
    unsigned int rdev, size;
    unsigned __int64 atime, mtime, ctime;
};
int __cdecl FUN_00ec923c(const char*, FileStat077*);
void __cdecl ProcessFilesByType(Entry077*, Entry077*, unsigned int);
struct ArcStream077;
typedef unsigned int(__cdecl* ArcReadFn077)(ArcStream077*, void*, unsigned int, unsigned int*, unsigned int);
struct ArcStream077
{
    virtual ~ArcStream077();
    unsigned int m_uiStreamFlags;
    ArcReadFn077 m_pfnRead;
    unsigned int BinaryRead(void* buffer, unsigned int length, unsigned int* sizes, unsigned int number)
    {
        unsigned int uiRead = m_pfnRead(this, buffer, length, sizes, number);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
inline unsigned int ArcLoadChars(BSFile& stream, void* buffer, unsigned int length)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = reinterpret_cast<ArcStream077&>(stream).BinaryRead(buffer, length, &uiCompSize, 1);
    return uiRet;
}
inline unsigned int ArcStringLength(const char* value)
{
    return strlen(value);
}
struct FUN_00af7eb0 : Header077, FUN_00b00260, NiRefObject077
{
    struct Time077
    {
        unsigned int low, high;
    } stamp;
    unsigned int namesOffset;
    unsigned int cacheIndex, cacheOffset;
    Critical077 critical;
    unsigned char status;
    unsigned char statusReserved;
    unsigned short statusReserved2;
    char* directoryNames;
    unsigned int* directoryOffsets;
    char* fileNames;
    unsigned int** fileOffsets;
    unsigned int id;
    FUN_00af7eb0(const char*, int, bool, bool);
    virtual ~FUN_00af7eb0();
    void ClearMatchedEntries();
    bool SetBufferSize(unsigned int);
    void ReadArray(Entry077* buffer, unsigned int count)
    {
        ArcLoadChars(*this, buffer, count * sizeof(Entry077));
    }
    bool Good()
    {
        return m_bGood;
    }
    template <int mask> void SetStatus(bool value)
    {
        if (value)
            status |= mask;
        else
            status &= ~mask;
    }
    bool HasStatus(int mask)
    {
        return (status & mask) ? true : false;
    }
    unsigned int TruePos()
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
};
inline bool FUN_00b00260::NeedCache()
{
    return (DAT_011acdf9 || DAT_011f8154 || static_cast<FUN_00af7eb0*>(this)->Has(0x80) ||
            FUN_00afb170(static_cast<FUN_00af7eb0*>(this)->Has(8), CacheMode0()) ||
            FUN_00afb170(static_cast<FUN_00af7eb0*>(this)->Has(0x10), CacheMode1()) ||
            FUN_00afb170(static_cast<FUN_00af7eb0*>(this)->Has(0x20), CacheMode2())) &&
           (!(static_cast<FUN_00af7eb0*>(this)->types & 0x10) ||
            FUN_00afb170(static_cast<FUN_00af7eb0*>(this)->Has(0x10), CacheMode1()) ||
            FUN_00afb170(static_cast<FUN_00af7eb0*>(this)->Has(0x20), CacheMode2()));
}
// Opens a BSA archive, reads its header and entries, optionally caches directory and file names, and prepares file lists by type.
// @fnv 0x00af7eb0
FUN_00af7eb0::FUN_00af7eb0(const char* path, int mode, bool headerOnly, bool prepare)
    : FUN_00b00260(path, 0, mode, false)
{
    id = DAT_011f81d8++;
    cacheIndex = -1;
    cacheOffset = -1;
    entries = 0;
    directoryNames = 0;
    directoryOffsets = 0;
    fileNames = 0;
    fileOffsets = 0;
    status = 0;
    namesOffset = 0;
    BSFile::Open(false, false);
    if (!Good())
        return;
    if (headerOnly)
        SetStatus<8>(true);
    BSFile::SetEndianSwap(false);
    Header077* header = this;
    ArcLoadChars(*this, header, 0x24);
    if (!Valid() || !VersionValid())
    {
        SetStatus<1>(true);
        return;
    }
    if (Version() < 0x68)
        SetVersionFlag();
    if (!HasStatus(8))
    {
        unsigned int elapsedTmp = GetTickCount();
        delete[] entries;
        entries = new Entry077[Count()];
        ReadArray(entries, Count());
        if (Has(1) && NeedCache())
        {
            SetStatus<0x10>(true);
            delete[] directoryNames;
            delete[] directoryOffsets;
            directoryNames = new char[DirNamesSize()];
            directoryOffsets = new unsigned int[Count()];
        }
        if (Has(2) && NeedCache())
        {
            SetStatus<0x20>(true);
            delete[] fileNames;
            if (fileOffsets)
            {
                for (unsigned int i = 0; i < Count(); ++i)
                    delete[] fileOffsets[i];
                delete[] fileOffsets;
            }
            fileNames = new char[FileNamesSize()];
            fileOffsets = new unsigned int*[Count()];
        }
        unsigned int dirOffset = 0;
        for (unsigned int i = 0; i < Count(); ++i)
        {
            if (Has(1))
            {
                unsigned char length;
                ArcLoadChars(*this, &length, 1);
                if (NeedCache())
                {
                    ArcLoadChars(*this, directoryNames + dirOffset, length);
                    directoryOffsets[i] = dirOffset;
                    dirOffset += length;
                }
                else
                {
                    char name[256];
                    ArcLoadChars(*this, name, length);
                }
            }
            Entry077* files = new Entry077[FileCount(i)];
            ReadArray(files, FileCount(i));
            SetFiles(i, files);
        }
        unsigned int fileOffset = 0;
        if (Has(2))
        {
            namesOffset = TruePos();
            if (NeedCache())
            {
                ArcLoadChars(*this, fileNames, FileNamesSize());
                for (unsigned int i = 0; i < Count(); ++i)
                {
                    fileOffsets[i] = new unsigned int[FileCount(i)];
                    for (unsigned int j = 0; j < FileCount(i); ++j)
                    {
                        fileOffsets[i][j] = fileOffset;
                        fileOffset += ArcStringLength(fileNames + fileOffset) + 1;
                    }
                }
            }
        }
        elapsedTmp = GetTickCount() - elapsedTmp;
    }
    FileStat077 stat;
    int statResultVal = FUN_00ec923c(pFileName, &stat);
    stamp = *(Time077*)&stat.mtime;
    if (!HasStatus(8))
    {
        if (DAT_011acdf9)
        {
            unsigned int uiElapsedTime = GetTickCount();
            ClearMatchedEntries();
            uiElapsedTime = GetTickCount() - uiElapsedTime;
        }
        if (prepare)
        {
            for (unsigned int i = 0; i < Count(); ++i)
            {
                for (unsigned int j = 0; j < FileCount(i); ++j)
                    ProcessFilesByType(entries + i, entries[i].files + j, types);
            }
        }
    }
    SetBufferSize(0x4000);
    ((BSFile*)this)->GetSize();
}
}  // namespace fnv_00af7eb0

namespace fnv_00af94c0 {
extern int DAT_010a2480;
extern int DAT_010a2484;
struct ArcMemMgr
{
    void FUN_00aa4060(void* p);
    void* FUN_00aa3e40(unsigned int uiSize);
};
extern ArcMemMgr DAT_011f6238;
inline void ArcFree(void* p)
{
    DAT_011f6238.FUN_00aa4060(p);
}
inline void* ArcAlloc(unsigned int uiSize)
{
    return DAT_011f6238.FUN_00aa3e40(uiSize);
}
struct ArcEntry
{
    unsigned int a;
    unsigned int b;
    unsigned int uiIndex;
    unsigned int c;
};
class ArcStream
{
  public:
    virtual ~ArcStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition();
    virtual void SetEndianSwap(bool bDoSwap);
    virtual void SeekTo(int iOffset, int iWhence);
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(ArcStream* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                              unsigned int uiNumComponents);
    void* m_pfnWrite;
    char pad10[0x16c - 0x10];
    unsigned int m_uiValue1;
    unsigned int m_uiCount;
    char pad174[0x184 - 0x174];
    ArcEntry* m_pkEntryArray;
    char pad188[0x1b4 - 0x188];
    unsigned char m_ucFlags;
    char pad1b5[3];
    char* m_pcData;
    unsigned int* m_puiOffsets;

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = 1;
        unsigned int uiBytesRead;
        unsigned int d;
        uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, &uiComponentSize, 1);
        m_uiStreamFlags += uiBytesRead;
        d = uiBytesRead;
        return d;
    }
    bool IsLoaded() const
    {
        return (m_ucFlags & 0x10) ? true : false;
    }
    bool HasStrings() const
    {
        return (m_uiValue1 & 1) != 0;
    }
    unsigned int LookupSequenceByKey(unsigned int i) const
    {
        return m_pkEntryArray[i].uiIndex;
    }
    char* GetString(unsigned int uiIndex);
};

// Returns the string at uiIndex, either from the loaded data block or by seeking and reading it from the stream.
// @fnv 0x00af94c0
char* ArcStream::GetString(unsigned int uiIndex)
{
    if (IsLoaded())
    {
        return m_pcData + m_puiOffsets[uiIndex];
    }
    else if (HasStrings())
    {
        unsigned char ucLen;
        unsigned int i;
        char* pcOld2;
        char* pcNew2;
        unsigned int ItemUpdateArray = m_uiCount;
        SeekTo(ItemUpdateArray * 16 + 0x24, DAT_010a2480);
        for (i = 0; i < uiIndex; i++)
        {
            Read(&ucLen, 1);
            SeekTo(ucLen + LookupSequenceByKey(i) * 16, DAT_010a2484);
        }
        Read(&ucLen, 1);
        if (m_pcData)
        {
            pcOld2 = m_pcData;
            DAT_011f6238.FUN_00aa4060(pcOld2);
            m_pcData = 0;
        }
        pcNew2 = (char*)ArcAlloc(ucLen);
        m_pcData = pcNew2;
        Read(m_pcData, ucLen);
        return m_pcData;
    }
    return 0;
}
}  // namespace fnv_00af94c0

namespace fnv_00afa8e0 {
struct PoolY
{
    void* FUN_00aa3e40(unsigned int uiSize);
    void FUN_00aa4060(void* p);
};
extern PoolY DAT_011f6238;
extern bool DAT_011f8154;
extern "C" int __cdecl FUN_00ec7f1e(const char* path, char* drive, unsigned int drvsz, char* dir, unsigned int dirsz,
                                    char* fname, unsigned int fnsz, char* ext, unsigned int extsz);
extern "C" unsigned int __cdecl FUN_00ec6130(const char* s);
extern "C" int __cdecl FUN_00ec65a6(char* dst, unsigned int sz, const char* src);
extern "C" int __cdecl FUN_00ecbc5b(char* s, unsigned int sz);
extern "C" char* __cdecl FUN_00ec68e4(const char* a, const char* b);
inline void* AllocNY(unsigned int n)
{
    return DAT_011f6238.FUN_00aa3e40(n + 1);
}
inline void CopyStrY(char* d, unsigned int n, const char* s)
{
    FUN_00ec65a6(d, n, s);
}
inline void LowerY(char* s, unsigned int n)
{
    FUN_00ecbc5b(s, n);
}
struct ArcY
{
    char pad[0x16c];
    unsigned int m_uiValue1;
    bool Flag1() const
    {
        return (m_uiValue1 & 1) != 0;
    }
    bool Flag2() const
    {
        return (m_uiValue1 & 2) != 0;
    }
    bool FUN_00af9bf0(int a, int b, int* pA, int* pB, int c);
    const char* GetString(int a);
    const char* FUN_00af96d0(int a, int b);
    const char* GetPathComponent(int a1, int a2, const char* pPath);
};
// Splits pPath into directory and file, resolves a1/a2 via FUN_00af9bf0, and returns the matching directory or file name after case-insensitive comparison.
// @fnv 0x00afa8e0
const char* ArcY::GetPathComponent(int a1, int a2, const char* pPath)
{
    if (DAT_011f8154 && Flag1() && Flag2())
    {
        char szDirX[0x104];
        char szFile7[0x104];
        FUN_00ec7f1e(pPath, 0, 0, szDirX, 0x104, szFile7, 0x104, 0, 0);
        int iA4, iB3;
        if (FUN_00af9bf0(a1, a2, &iA4, &iB3, 0))
        {
            char* pDirCopyX_lvyahv;
            char* pFileCopyTmp_lun;
            const char* pDirName_mcmb;
            const char* pFileName_zpqwby;
            char* t_elydin;
            char* t_szknnb;
            void* q_pddrt;
            void* q_cyqb;
            void* q_u;
            void* q_ewlv;
            pDirName_mcmb = GetString(iA4);
            pFileName_zpqwby = FUN_00af96d0(iA4, iB3);
            t_elydin = (char*)AllocNY(FUN_00ec6130(pDirName_mcmb));
            pDirCopyX_lvyahv = t_elydin;
            t_szknnb = (char*)AllocNY(FUN_00ec6130(pFileName_zpqwby));
            pFileCopyTmp_lun = t_szknnb;
            CopyStrY(pDirCopyX_lvyahv, FUN_00ec6130(pDirName_mcmb), pDirName_mcmb);
            CopyStrY(pFileCopyTmp_lun, FUN_00ec6130(pFileName_zpqwby), pFileName_zpqwby);
            LowerY(pDirCopyX_lvyahv, FUN_00ec6130(pDirCopyX_lvyahv));
            LowerY(pFileCopyTmp_lun, FUN_00ec6130(pFileCopyTmp_lun));
            LowerY(szDirX, FUN_00ec6130(szDirX));
            LowerY(szFile7, FUN_00ec6130(szFile7));
            if (FUN_00ec68e4(pDirCopyX_lvyahv, szDirX))
            {
                q_pddrt = pDirCopyX_lvyahv;
                DAT_011f6238.FUN_00aa4060(q_pddrt);
                q_cyqb = pFileCopyTmp_lun;
                DAT_011f6238.FUN_00aa4060(q_cyqb);
                return pDirName_mcmb;
            }
            if (FUN_00ec68e4(pFileCopyTmp_lun, szFile7))
            {
                q_u = pDirCopyX_lvyahv;
                DAT_011f6238.FUN_00aa4060(q_u);
                q_ewlv = pFileCopyTmp_lun;
                DAT_011f6238.FUN_00aa4060(q_ewlv);
                return pFileName_zpqwby;
            }
        }
    }
    return 0;
}
}  // namespace fnv_00afa8e0

namespace fnv_00afb300 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
void __cdecl FUN_00ec65a6(char* d, unsigned int n, const char* s);
void __cdecl FUN_00ec44d0(void* d, const void* s, unsigned int n);
extern unsigned int DAT_011f8164;
struct RefBase
{
    virtual ~RefBase();
    long m_iObjectReferenceCount;
    void AcquireReference()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
};
struct FileBase
{
    virtual ~FileBase();
    unsigned int m_04, m_08, m_0c;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int m_1c;
    char* m_pBuffer;
    char pad24[0x20];
    char pFileName[0x104];
    int iResult;
    unsigned int m_uiBufferPosition;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
};
struct Archive : FileBase, RefBase
{
    unsigned int m_160, m_164, m_168;
    unsigned int m_flags;
    bool IsFlag()
    {
        return (m_flags & 0x100) != 0;
    }
};
struct ArchivePtr
{
    Archive* m_p;
    ArchivePtr(Archive* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~ArchivePtr();
    ArchivePtr& FUN_00afd1b0(Archive* p);
    Archive* operator->()
    {
        return m_p;
    }
};
struct FUN_00aff180 : FileBase
{
    FUN_00aff180();
    void FUN_00afbfa0(int);
    void FUN_00afb5f0(int, int);
    unsigned int ReadAtOffset(char*, unsigned int, int);
    void DebugCheck()
    {
        const char* pName;
        const char* pBuffer;
    }  // compiled-out debug check (locals only)
    char* Cur()
    {
        char* r = m_pBuffer + m_uiPos + 1;
        return r;
    }
};
struct FUN_00afb300 : FUN_00aff180
{
    ArchivePtr m_pArchive;
    unsigned int m_uiFileIndex;
    virtual ~FUN_00afb300();
    FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode);
};
// Initializes the archive-backed object and buffer, then may read bytes and copy a length-prefixed name from the buffer.
// @fnv 0x00afb300
FUN_00afb300::FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode)
{
    DebugCheck();
    if (name)
        FUN_00ec65a6(pFileName, 0x104, name);
    m_pBuffer = 0;
    m_pArchive.FUN_00afd1b0(arch);
    m_uiFileIndex = off;
    m_uiValueId = size;
    FUN_00afbfa0(0);
    m_uiBufferAllocSize = (size > DAT_011f8164 && mode != -1) ? DAT_011f8164 : size;
    FUN_00afb5f0(0, 0);
    if (mode == -1 || m_pArchive->IsFlag())
    {
        int x = 0;
        m_uiBufferReadSize = ReadAtOffset(m_pBuffer, m_uiBufferAllocSize, x);
        if (m_pArchive->IsFlag())
        {
            unsigned char len = m_pBuffer[m_uiPos];
            FUN_00ec44d0(pFileName, Cur(), len);
            pFileName[len] = 0;
            m_uiPos = len + m_uiPos + 1;
            m_uiBufferSize = len + 1;
        }
    }
}
}  // namespace fnv_00afb300

namespace fnv_00af7400 {
struct CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

extern "C"
{
    __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
}

unsigned int __cdecl strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
const char* __cdecl _strrchr(const char*, int);

const char* __cdecl SkipDataPrefix(const char*);
int __cdecl FUN_00af7d80(const char*);

class FUN_00afd390_class
{
  public:
    int unk00;
    int unk04;
    void* FUN_00afd390(const char*, int);
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ArchiveEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    inline int GetNameID()
    {
        return unk08;
    }
};

class Archive : public BSFile, public NiRefObject
{
  public:
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    unsigned short m_usFlags;
    short unk182;
    ArchiveEntry* pEntries;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    CRITICAL_SECTION cs;
    unsigned char unk1B4;
    unsigned char unk1B5;
    short unk1B6;
    inline unsigned int GetFlags()
    {
        return m_usFlags;
    }
    inline ArchiveEntry* GetEntry(int index)
    {
        return &pEntries[index];
    }
    inline bool HasNameTable()
    {
        return unk1B4 & 0x20;
    }
    inline void Lock()
    {
        EnterCriticalSection(&cs);
    }
    inline void Unlock()
    {
        LeaveCriticalSection(&cs);
    }
};

class Owner25
{
  public:
    bool FindHashEntry(int, int*, int);
};

class FUN_00af9ba0_shell
{
  public:
    int FUN_00af96d0(int, unsigned int);
};

struct NP_afc
{
    Archive* m_pObject;

    NP_afc(Archive* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }
    NP_afc(const NP_afc& p)
    {
        m_pObject = p.m_pObject;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }
    ~NP_afc()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
    operator Archive*() const
    {
        return m_pObject;
    }
    NP_afc* FUN_00afc770(NP_afc* rhs)
    {
        if (m_pObject != rhs->m_pObject)
        {
            if (m_pObject)
            {
                m_pObject->DecRefCount();
            }
            m_pObject = rhs->m_pObject;
            if (m_pObject)
            {
                m_pObject->IncRefCount();
            }
        }
        return this;
    }
};

struct LNode
{
    NP_afc item;
    LNode* next;
};
extern LNode* DAT_011f8160;

class FUN_00aa5140
{
  public:
    FUN_00aa5140();
    const char* FUN_00aa5230(int);
};

__forceinline const char* ResolveNameInline(ArchiveEntry& entry, NP_afc& archive, int& index)
{
    int id = entry.unk08;
    static FUN_00aa5140 s_obj;
    const char* name = s_obj.FUN_00aa5230(id);
    return (const char*)((FUN_00af9ba0_shell*)(Archive*)archive)->FUN_00af96d0(index, (unsigned int)name);
}

// Resolves a data path to an archive entry name, copying the result into dest and returning success.
// @fnv 0x00af7400
bool __cdecl ResolveArchivePath(const char* path, char* dest, unsigned int flags)
{
    int index = 0;
    path = SkipDataPrefix(path);
    unsigned int len5 = strlen(path);
    if (flags == 0xffff && (signed char)path[len5 - 1] != '\\')
    {
        flags = FUN_00af7d80(path);
    }
    FUN_00afd390_class key;
    key.FUN_00afd390(path, 1);

    ArchiveEntry* spFoundArchive2 = 0;
    NP_afc pEntry = 0;

    if (!pEntry)
    {
        LNode* pNode = DAT_011f8160;
        while (pNode)
        {
            NP_afc spArchiveB = pNode->item;
            if (spArchiveB && (unsigned short)(((Archive*)spArchiveB)->GetFlags() & flags) &&
                ((Owner25*)(Archive*)spArchiveB)->FindHashEntry((int)&key, &index, 0))
            {
                pEntry.FUN_00afc770(&spArchiveB);
                spFoundArchive2 = ((Archive*)pEntry)->GetEntry(index);
                break;
            }
            pNode = pNode->next;
        }
    }

    if (pEntry && spFoundArchive2 && spFoundArchive2->GetNameID())
    {
        bool bLocked3 = true;
        if (((Archive*)pEntry)->HasNameTable())
        {
            bLocked3 = false;
        }
        if (bLocked3)
        {
            ((Archive*)pEntry)->Lock();
        }

        const char* resolvedName4 = ResolveNameInline(*spFoundArchive2, pEntry, index);

        _strcpy_s(dest, 260, path);
        char* pSlash_ = (char*)_strrchr(dest, '\\');
        if (pSlash_)
        {
            _strcpy_s(pSlash_ + 1, 260 - (pSlash_ - dest) - 1, resolvedName4);
        }
        else
        {
            return false;
        }

        if (bLocked3)
        {
            ((Archive*)pEntry)->Unlock();
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00af7400

void* __cdecl FUN_00ec7230(void* dst, const void* src, unsigned int size);

struct S_00afea20_Arr
{
    int unk00;
    unsigned int* m_pBuffer;
    unsigned int m_uiSize;

    void FUN_0042fb60(unsigned int* pDst, unsigned int* pSrc, unsigned int ItemUpdateArray)
    {
        if (ItemUpdateArray <= 0)
            return;
        if (pDst < pSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
        else if (pDst > pSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
    }

    void RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray);
};

// @fnv 0x00afea20
void S_00afea20_Arr::RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray)
{
    unsigned int uiMove;
    unsigned int uiTail = m_uiSize - uiIndex - ItemUpdateArray;
    uiMove = uiTail < ItemUpdateArray ? uiTail : ItemUpdateArray;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
    }
    FUN_0042fb60(m_pBuffer + uiIndex, m_pBuffer + m_uiSize - uiMove, uiMove);
    m_uiSize -= ItemUpdateArray;
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_00af8e60
{
    ~FUN_00af8e60();
};
struct FUN_00afc680 : FUN_00af8e60
{
    virtual ~FUN_00afc680();
    static void operator delete(void* p)
    {
        __Dummy_00b6fef0(p, 0x1d0);
    }
};
// The destructor body is empty; destruction proceeds to the base class destructor.
// @fnv 0x00afc680
FUN_00afc680::~FUN_00afc680()
{}

extern MemoryManager g_memoryManager;
struct FUN_00afcdc0
{
    ~FUN_00afcdc0();
};
struct FUN_00afcd90 : FUN_00afcdc0
{
    virtual ~FUN_00afcd90();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};
// Empty virtual destructor for FUN_00afcd90, allowing polymorphic deletion through its base class.
// @fnv 0x00afcd90
FUN_00afcd90::~FUN_00afcd90()
{}

struct ArchiveStreamBase : public BSFile
{
    virtual void* FUN_00afce80(unsigned int flags);
};
struct StreamSecondary
{
    virtual void* FUN_00afce80(unsigned int flags);
};
struct ArchiveStreamFile : public ArchiveStreamBase, public StreamSecondary
{
    ArchiveStreamFile();
// @fnv 0x00afce80
    virtual void* FUN_00afce80(unsigned int flags);
};
ArchiveStreamFile::ArchiveStreamFile()
{}

unsigned char __fastcall FUN_00afcfe0(void*);

struct FUN_00afcf00_t
{
    char pad_0[2];
    unsigned char field_2;
    unsigned char field_3;
    unsigned int field_4;

    int FUN_00afcf00(FUN_00afcf00_t* other);
};

// Compares two FUN_00afcf00_t objects by field_4, field_2, and FUN_00afcfe0 result, returning -1, 0, or 1.
// @fnv 0x00afcf00
int FUN_00afcf00_t::FUN_00afcf00(FUN_00afcf00_t* other)
{
    if ((unsigned char)(field_3 & 0x7f) == 0x2a)
    {
        if (FUN_00afcfe0(this) == FUN_00afcfe0(other))
        {
            return 0;
        }
        return 1;
    }

    unsigned int a;
    unsigned int b;
    a = field_4;
    b = other->field_4;
    if (a < b)
    {
        return -1;
    }
    else
    {
        unsigned int a;
        unsigned int b;
        a = field_4;
        b = other->field_4;
        if (a > b)
        {
            return 1;
        }
    }

    {
        unsigned char c2;
        unsigned char c1;
        c1 = field_2;
        c2 = other->field_2;
        if (c1 != c2)
        {
            return 1;
        }
    }

    if (FUN_00afcfe0(this) != FUN_00afcfe0(other))
    {
        return 1;
    }

    return 0;
}

namespace fnv_00af7800 {
struct RecursiveMutex
{
    unsigned debug, lockCount, recursionCount, owner, semaphore, spin;
};

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);

__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
int __cdecl FUN_00af7d80(const char*);
struct LNode;
extern LNode* DAT_011f8160;

struct ArchiveDirectoryKey
{
    unsigned low, high;
    ArchiveDirectoryKey(const char*, int);
};

struct ArchiveFileMeta
{
    unsigned hashLow, hashHigh;
    unsigned offset, size;
    unsigned Offset()
    {
        return offset & 0x3fffffff;
    }
};

struct ArchiveDirectory
{
    unsigned hashLow, hashHigh, count;
    ArchiveFileMeta* files;
    unsigned Count()
    {
        return count;
    }
    ArchiveFileMeta* File(unsigned i)
    {
        return files + i;
    }
};

struct ArchiveRefBlock
{
    virtual void Unknown();
    virtual void DeleteThis();
    volatile long count;
    void Acquire()
    {
        InterlockedIncrement(&count);
    }
    void Release()
    {
        if (!InterlockedDecrement(&count))
            DeleteThis();
    }
};

struct PathArchive
{

    unsigned unk000;

    unsigned unk004;

    unsigned unk008;

    unsigned unk00c;

    unsigned unk010;

    unsigned unk014;

    unsigned unk018;

    unsigned unk01c;

    unsigned unk020;

    unsigned unk024;

    unsigned unk028;

    unsigned unk02c;

    unsigned unk030;

    unsigned unk034;

    unsigned unk038;

    unsigned unk03c;

    unsigned unk040;

    unsigned unk044;

    unsigned unk048;

    unsigned unk04c;

    unsigned unk050;

    unsigned unk054;

    unsigned unk058;

    unsigned unk05c;

    unsigned unk060;

    unsigned unk064;

    unsigned unk068;

    unsigned unk06c;

    unsigned unk070;

    unsigned unk074;

    unsigned unk078;

    unsigned unk07c;

    unsigned unk080;

    unsigned unk084;

    unsigned unk088;

    unsigned unk08c;

    unsigned unk090;

    unsigned unk094;

    unsigned unk098;

    unsigned unk09c;

    unsigned unk0a0;

    unsigned unk0a4;

    unsigned unk0a8;

    unsigned unk0ac;

    unsigned unk0b0;

    unsigned unk0b4;

    unsigned unk0b8;

    unsigned unk0bc;

    unsigned unk0c0;

    unsigned unk0c4;

    unsigned unk0c8;

    unsigned unk0cc;

    unsigned unk0d0;

    unsigned unk0d4;

    unsigned unk0d8;

    unsigned unk0dc;

    unsigned unk0e0;

    unsigned unk0e4;

    unsigned unk0e8;

    unsigned unk0ec;

    unsigned unk0f0;

    unsigned unk0f4;

    unsigned unk0f8;

    unsigned unk0fc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    ArchiveRefBlock reference;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned short types, reserved182;
    ArchiveDirectory* directories;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    RecursiveMutex lock;

    unsigned char flags;

    ArchiveRefBlock* Ref()
    {
        return &reference;
    }

    unsigned Types()
    {
        return types;
    }

    bool FindHashEntry(ArchiveDirectoryKey*, unsigned*, bool);

    ArchiveDirectory* Directory(unsigned i)
    {
        return directories + i;
    }

    bool IsConcurrent()
    {
        return (flags & 32) ? true : false;
    }

    RecursiveMutex* Lock()
    {
        return &lock;
    }

    const char* FUN_00af96d0(unsigned, unsigned);
};

struct PathArchivePointer
{

    PathArchive* pointer;

    PathArchivePointer(const PathArchivePointer& p)
    {
        pointer = p.pointer;
        if (pointer)
            pointer->Ref()->Acquire();
    }

    PathArchivePointer(PathArchive* p)
    {
        pointer = p;
        if (pointer)
            pointer->Ref()->Acquire();
    }

    __forceinline ~PathArchivePointer()
    {
        if (pointer)
            pointer->Ref()->Release();
    }

    PathArchive* operator->() const
    {
        return pointer;
    }

    operator PathArchive*() const
    {
        return pointer;
    }

    PathArchivePointer& FUN_00afc770(const PathArchivePointer& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->Ref()->Release();
            pointer = other.pointer;
            if (pointer)
                pointer->Ref()->Acquire();
        }
        return *this;
    }
};

struct PathArchiveNode
{
    PathArchivePointer value;
    PathArchiveNode* next;
};

const char* SkipDataPrefix(const char*);

// Finds the archive entry matching path and mask, picks the lowest-offset file, and writes its resolved name into output.
// @fnv 0x00af7800
bool FUN_00af7800(const char* path, char* output, unsigned mask)
{

    unsigned directoryIndex = 0;

    path = SkipDataPrefix(path);

    unsigned length2 = strlen(path);

    if (mask == 65535 && path[length2 - 1] != '\\')
        mask = FUN_00af7d80(path);

    ArchiveDirectoryKey key(path, 1);

    ArchiveDirectory* directory4 = 0;

    PathArchivePointer archiveTmp(0);

    PathArchiveNode* node9;

    if (!archiveTmp)
    {

        for (node9 = (PathArchiveNode*)DAT_011f8160; node9;)
        {

            PathArchivePointer entry3(node9->value);

            if (entry3 && (unsigned short)(entry3->Types() & mask) &&
                entry3->FindHashEntry(&key, &directoryIndex, false))
            {

                archiveTmp.FUN_00afc770(entry3);

                directory4 = archiveTmp->Directory(directoryIndex);

                break;
            }

            node9 = node9->next;
        }
    }

    if (archiveTmp && directory4 && directory4->Count())
    {

        bool kLocked = true;

        if (archiveTmp->IsConcurrent())
            kLocked = false;

        if (kLocked)
            EnterCriticalSection(archiveTmp->Lock());

        unsigned aBestA = 0;

        unsigned minimum3 = ~0u;

        for (unsigned _i2 = 0; _i2 < directory4->Count(); ++_i2)
        {

            unsigned value7 = directory4->File(_i2)->Offset();

            if (value7 < minimum3)
            {
                minimum3 = value7;
                aBestA = _i2;
            }
        }

        const char* replacementVal = archiveTmp->FUN_00af96d0(directoryIndex, aBestA);

        strcpy_s(output, 260, path);

        char* slash3 = strrchr(output, '\\');

        if (slash3)
            strcpy_s(slash3 + 1, 260 - (slash3 - output) - 1, replacementVal);

        else
            return false;

        if (kLocked)
            LeaveCriticalSection(archiveTmp->Lock());

        return true;
    }

    return false;
}
}  // namespace fnv_00af7800

__if_not_exists(MemMgrStand)
{
    struct MemMgrStand
    {
        void* Allocate(unsigned int auiSize);
        void Deallocate(void* apMem);
    };
}
extern MemMgrStand g_arcMemMgr;
struct ArchiveArray;
inline void* operator new(unsigned int, void* memory)
{
    return memory;
}
extern const char DAT_010a445c[];
extern "C" char* __cdecl strstr(const char*, const char*);
BSFile* __cdecl FUN_00afdf00(const char*, int, unsigned int);
struct FUN_00afd390
{
    unsigned int low;
    unsigned int high;
    FUN_00afd390(const char*, int);
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
};
struct FUN_00afcce0
{
    virtual ~FUN_00afcce0();
    virtual FUN_00afd390** Allocate(unsigned int);
    FUN_00afd390** entries;
    unsigned int count;
    unsigned int capacity;
    FUN_00afcce0();
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
    void InitArray(unsigned int allocated, unsigned int size)
    {
        entries = 0;
        count = 0;
        capacity = 0;
        if (size > allocated)
            allocated = size;
        if (allocated > 0)
        {
            entries = Allocate(allocated);
            capacity = allocated;
        }
        if (size > 0)
        {
            for (unsigned int i = 0; i < size; ++i)
                new (&entries[i]) FUN_00afd390*;
            count = size;
        }
    }
    void FUN_00a0d0c0(unsigned int, unsigned int);
    unsigned int FUN_00a11ee0()
    {
        if (count == capacity)
        {
            if (capacity == 0)
            {
                unsigned int initialCapacity = 4;
                entries = Allocate(initialCapacity);
                capacity = initialCapacity;
            }
            else
            {
                unsigned int newCapacity = capacity > 1024 ? capacity + 1024 : capacity * 2;
                FUN_00a0d0c0(newCapacity, count);
                capacity = newCapacity;
            }
        }
        ++count;
        return count - 1;
    }
    unsigned int FUN_00a11d20(FUN_00afd390* const& value)
    {
        unsigned int index = FUN_00a11ee0();
        for (unsigned int i = 0; i < 1; ++i)
            new (&entries[index + i]) FUN_00afd390*;
        entries[index] = value;
        return index;
    }
};
extern ArchiveArray* DAT_011f816c;
extern ArchiveArray* DAT_011f8168;
struct ArchiveListStream : BSFile
{
    inline unsigned int Read(void* buffer, unsigned int bytes)
    {
        unsigned int componentSize = 1;
        unsigned int bytesRead = BinaryRead(buffer, bytes, &componentSize, 1);
        return bytesRead;
    }
    inline unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = ((unsigned int(__cdecl*)(NiBinaryStream*, void*, unsigned int, unsigned int*,
                                                       unsigned int))m_pfnRead)(this, buffer, bytes, sizes, count);
        m_uiStreamFlags += result;
        return result;
    }
};
// Opens an archive list file, reads each line, and adds entries to DAT_011f816c or DAT_011f8168 based on a substring check.
// @fnv 0x00af5ab0
void __cdecl FUN_00af5ab0(const char* path)
{
    ArchiveListStream* file;
    if (path)
    {
        file = (ArchiveListStream*)FUN_00afdf00(path, 0, 0x4000);
        if (!file || !file->Open(false, false))
        {
            delete file;
            return;
        }
        char lineBuffer[260];
        char separator;
        char* entryPath;
        while (file->GetLine(lineBuffer, 260, 13))
        {
            file->Read(&separator, 1);
            if (strstr(lineBuffer, DAT_010a445c))
            {
                if (!DAT_011f816c)
                    DAT_011f816c = reinterpret_cast<ArchiveArray*>(new FUN_00afcce0);
                entryPath = lineBuffer;
                if (lineBuffer[0] == '\\')
                    entryPath++;
                reinterpret_cast<FUN_00afcce0*>(DAT_011f816c)->FUN_00a11d20(new FUN_00afd390(entryPath, 1));
            }
            else
            {
                if (!DAT_011f8168)
                    DAT_011f8168 = reinterpret_cast<ArchiveArray*>(new FUN_00afcce0);
                reinterpret_cast<FUN_00afcce0*>(DAT_011f8168)->FUN_00a11d20(new FUN_00afd390(lineBuffer, 0));
            }
        }
        delete file;
    }
}

struct ArcInflateReadState
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned int m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
int __cdecl FUN_00b44000(ArcInflateReadState* state, int flush);
int __cdecl FUN_00b45db0(ArcInflateReadState* state);
struct DecompReadFile : public CompressedArchiveFile
{
    void FUN_00aa15a0();
    unsigned int ReadAtOffset(void* buffer, unsigned int size, int mode);
    unsigned int FUN_00afc0e0(char* buffer, unsigned int size);
};
// Reads up to size bytes of decompressed data into buffer, refilling the compressed input buffer as needed, and returns the number of bytes read.
// @fnv 0x00afc0e0
unsigned int DecompReadFile::FUN_00afc0e0(char* buffer, unsigned int size)
{
    unsigned int bytesToRead = size;
    unsigned int nRead = 0;
    ArcInflateReadState* state = (ArcInflateReadState*)m_pArchiveStream;
    unsigned int available = m_uiUncompressedPosition - m_uiCompressedPosition;

    if (bytesToRead > available)
    {
        if (available > 0)
        {
            if (buffer != 0)
            {
                char* copyFrom = m_pCompressedBuffer + m_uiCompressedPosition;
                memcpy(buffer, copyFrom, available);
                buffer += available;
            }
            bytesToRead -= available;
            nRead = available;
        }
        m_uiCompressedPosition = 0;
        m_uiUncompressedPosition = 0;

        int status;
        while (bytesToRead > 0)
        {
            state->m_uiAvailableOutputBytes = m_uiUncompressedSize;
            state->m_pNextOutputByte = (unsigned char*)m_pCompressedBuffer;

            while (state->m_uiAvailableOutputBytes != 0)
            {
                available = m_uiBufferReadSize - m_uiPos;
                state->m_uiAvailableInputBytes = available;
                state->m_pNextInputByte = (unsigned char*)(m_pBuffer + m_uiPos);

                if (available != 0)
                {
                    status = FUN_00b44000(state, 2);
                    if (status == -2 || status == 2 || status == -3 || status == -4)
                    {
                        FUN_00b45db0(state);
                        bytesToRead = 0;
                        break;
                    }
                    if (status == 1)
                        break;
                }
                m_uiPos += available - state->m_uiAvailableInputBytes;
                m_uiBufferSize += available - state->m_uiAvailableInputBytes;
                if (state->m_uiAvailableInputBytes == 0)
                {
                    FUN_00aa15a0();
                    m_uiBufferReadSize = ReadAtOffset(m_pBuffer, m_uiBufferAllocSize, 0);
                }
            }

            m_uiUncompressedPosition = m_uiUncompressedSize - state->m_uiAvailableOutputBytes;
            if (m_uiUncompressedPosition == 0)
            {
                break;
            }
            else
            {
                if (bytesToRead > m_uiUncompressedPosition)
                {
                    bytesToRead -= m_uiUncompressedPosition;
                    nRead += m_uiUncompressedPosition;
                    if (buffer != 0)
                    {
                        unsigned int amount = m_uiUncompressedPosition;
                        char* copyFrom = m_pCompressedBuffer;
                        memcpy(buffer, copyFrom, amount);
                        buffer += m_uiUncompressedPosition;
                    }
                }
                else
                {
                    if (buffer != 0)
                    {
                        char* copyFrom = m_pCompressedBuffer;
                        memcpy(buffer, copyFrom, bytesToRead);
                    }
                    m_uiCompressedPosition += bytesToRead;
                    nRead += bytesToRead;
                    bytesToRead = 0;
                }
            }
        }
    }
    else
    {
        if (buffer != 0)
        {
            char* copyFrom = m_pCompressedBuffer + m_uiCompressedPosition;
            memcpy(buffer, copyFrom, bytesToRead);
        }
        m_uiCompressedPosition += bytesToRead;
        nRead += bytesToRead;
    }
    return nRead;
}

namespace archive_master_lookup {
using fnv_00af6540::Owner25;
using fnv_00af6340::Archive;

class ArchiveHandle
{
  public:
    Archive* object;
    ArchiveHandle(Archive* value)
    {
        object = value;
        if (object)
            object->rc.AcquireReference();
    }
    ~ArchiveHandle()
    {
        if (object)
            object->rc.DecRef();
    }
    operator Archive*() const
    {
        return object;
    }
    Archive* operator->() const
    {
        return object;
    }
};
extern fnv_00af6540::NiPointer<fnv_00af6540::Archive> DAT_011f8190[9];
extern fnv_00af6540::NiPointer<fnv_00af6540::Archive> DAT_011f81b4[9];
inline Archive* SelectMaster(int index)
{
    return reinterpret_cast<Archive*>(
        static_cast<fnv_00af6540::Archive*>(DAT_011f8190[index] ? DAT_011f8190[index] : DAT_011f81b4[index]));
}
// Selects an archive using kind and calls its FUN_00afa6e0 method with directory, file, and name.
// @fnv 0x00af6430
int __cdecl FUN_00af6430(int aiMasterIndex, int directory, int file, int name)
{
    int result = 0;
    ArchiveHandle archive(SelectMaster(aiMasterIndex));
    if (archive)
        result = reinterpret_cast<Owner25*>(archive.operator->())->FUN_00afa6e0(directory, file, name);
    return result;
}
}

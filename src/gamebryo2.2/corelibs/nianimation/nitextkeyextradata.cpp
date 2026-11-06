
// src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_011f3f28;

// Returns the address of the global pointer g_011f3f28.
// @fnv 0x00a46b60
void* __cdecl FUN_00a46b60()
{
    return &g_011f3f28;
}

struct NiExtraData
{
    void __thiscall FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern void* DAT_0109827c;

// @fnv 0x00a46b70
void* __cdecl FUN_00a46b70()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        static_cast<NiExtraData*>(p)->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0109827c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0xc) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x10) = 0;
        return p;
    }
    return 0;
}

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

extern "C" void __cdecl DestroyKeyList(void);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

struct NiTextKeyExtraData : NiMemObject
{
    unsigned int m_uiNumKeys;
    void* m_pKeys;
    void* __thiscall FUN_00a46ed0(unsigned int flags);
};

// @fnv 0x00a46ed0
void* __thiscall NiTextKeyExtraData::FUN_00a46ed0(unsigned int flags)
{
    DestroyKeyList();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x14);
    return this;
}

struct NiStream;
struct FakeBase00
{
    bool __thiscall FUN_00a7b290(NiStream*);
};
struct FakeKey00
{
    void __thiscall FUN_00a57850(NiStream*);
};
// Calls the base loader on stream, then loads each of the 0xC-count keys at offset 0x10 from the stream, returning true on success.
// @fnv 0x00a46b10
bool __fastcall LoadFromStream(NiTextKeyExtraData* _this, void* _edx, NiStream* stream)
{
    if (!((FakeBase00*)_this)->FUN_00a7b290(stream))
        return false;
    unsigned int uiI;
    for (uiI = 0; uiI < *(unsigned int*)((char*)_this + 0xC); ++uiI)
        ((FakeKey00*)((char*)*(void**)((char*)_this + 0x10) + uiI * 8))->FUN_00a57850(stream);
    return true;
}

struct A46BB0Key
{
    float m_fTime;
    int m_iValue;
};

struct A46BB0Object
{
    int unk00;
    int unk04;
    int unk08;

    bool IsEqual(A46BB0Object* pkObject);
};

struct A46BB0KeyData : A46BB0Object
{
    unsigned int m_uiNumKeys;
    A46BB0Key* m_pKeyArray;

    bool FUN_00a46bb0(A46BB0Object* pkObject);
};

// Checks that pkObject is non-null, base-equal, has the same key count, and that every key's time and value match; returns true if so.
// @fnv 0x00a46bb0
bool A46BB0KeyData::FUN_00a46bb0(A46BB0Object* pkObject)
{
    if (!pkObject)
        return false;
    if (!A46BB0Object::IsEqual(pkObject))
        return false;
    A46BB0KeyData* pkOther = (A46BB0KeyData*)pkObject;
    if (m_uiNumKeys != pkOther->m_uiNumKeys)
        return false;
    for (unsigned int i = 0; i < m_uiNumKeys; i++)
    {
        if (m_pKeyArray[i].m_fTime != pkOther->m_pKeyArray[i].m_fTime ||
            m_pKeyArray[i].m_iValue != pkOther->m_pKeyArray[i].m_iValue)
            return false;
    }
    return true;
}

struct FUN_00a57870_Class
{
    void __thiscall ReleaseString();
};
struct MM
{
    void __thiscall Deallocate(void*);
};
extern MM g_memoryManager;
struct NiStringsExtraData
{
    void __thiscall FUN_00a7b300();
};
struct FUN_00a46d50_class
{
    void __thiscall DestroyKeyList();
};
// @fnv 0x00a46d50
void FUN_00a46d50_class::DestroyKeyList()
{
    *(void**)this = &DAT_0109827c;
    void* keys = *(void**)((char*)this + 0x10);
    if (keys)
    {
        int count = ((int*)keys)[-1];
        char* current = (char*)keys + count * 8;
        --count;
        if (count >= 0)
        {
            do
            {
                current -= 8;
                ((FUN_00a57870_Class*)current)->ReleaseString();
                --count;
            } while (count >= 0);
        }
        g_memoryManager.Deallocate((char*)keys - 4);
    }
    ((NiStringsExtraData*)this)->FUN_00a7b300();
}

extern int DAT_0109b220;

struct FUN_00a46b50_cls
{
    int unk00;
    int m_i04;

    FUN_00a46b50_cls* FUN_00a46b50();
};

// @fnv 0x00a46b50
FUN_00a46b50_cls* FUN_00a46b50_cls::FUN_00a46b50()
{
    m_i04 = DAT_0109b220;
    return this;
}

extern "C" unsigned int __cdecl strlen(const char*);
struct StrArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int AddInline(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
        return uiIndex;
    }
};

char* FUN_00a7d330(const char* s);
char* FUN_00a7d510(const char* s, unsigned int v);
char* FUN_00a7d550(const char* s, float v);
char* FUN_00a7d5e0(const char* s, const char* v);
void* NiMalloc(unsigned int size);
void NiFree(void* p);
int NiSprintf(char* buf, unsigned int size, const char* fmt, ...);

extern void* g_011f3f28;

struct TextKey
{
    float m_fTime;
    const char* m_kText;
    float GetTime() const
    {
        return m_fTime;
    }
    const char* GetText() const
    {
        return m_kText;
    }
};

struct ExtraDataBase
{
    void* m_vtbl;
    void* m_pcName;
    void* m_unk08;
    void FUN_00a7b580(StrArray* pkStrings);
};

struct TextKeyExtraData : ExtraDataBase
{
    unsigned int m_uiNumKeys;
    TextKey* m_pKeys;
    void WriteToStrings(StrArray* pkStrings);
};

// Appends the base strings, the key count, and one formatted "Time : Text" entry per text key to pkStrings.
// @fnv 0x00a46ef0
void TextKeyExtraData::WriteToStrings(StrArray* pkStrings)
{
    FUN_00a7b580(pkStrings);
    pkStrings->Add(FUN_00a7d330((const char*)g_011f3f28));
    pkStrings->Add(FUN_00a7d510("m_uiNumKeys", m_uiNumKeys));

    for (unsigned int i = 0; i < m_uiNumKeys; i++)
    {
        char* pcTimeString = FUN_00a7d550("Time", m_pKeys[i].GetTime());
        char* pcTextString = FUN_00a7d5e0("Text", m_pKeys[i].GetText());
        unsigned int uiBufferSize = strlen(pcTimeString) + strlen(pcTextString) + 4;
        char* pcString = (char*)NiMalloc(uiBufferSize);
        NiSprintf(pcString, uiBufferSize, "%s : %s", pcTimeString, pcTextString);
        char* pcEntryString = FUN_00a7d5e0("TextKey", pcString);
        pkStrings->AddInline(pcEntryString);
        NiFree(pcTimeString);
        NiFree(pcTextString);
        NiFree(pcString);
    }
}

class NiPSysBaseA46
{
  public:
    NiPSysBaseA46() throw();
    virtual ~NiPSysBaseA46();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08;
};

class NiPSysDerivedA46 : public NiPSysBaseA46
{
  public:
    NiPSysDerivedA46() throw()
    {
        m_pkFirst = 0;
        m_pkSecond = 0;
    }
    virtual ~NiPSysDerivedA46();

    void* m_pkFirst;
    void* m_pkSecond;
};

class NiPSysOwnerA46
{
  public:
    void CopyMemberData(NiPSysBaseA46* pkDest, void* pvProcess);
    NiPSysBaseA46* CreateClone(void* pvProcess);
};

// @fnv 0x00a46da0
NiPSysBaseA46* NiPSysOwnerA46::CreateClone(void* pvProcess)
{
    NiPSysDerivedA46* pkClone = new NiPSysDerivedA46;
    CopyMemberData(pkClone, pvProcess);
    return pkClone;
}

class S00a46cf0_BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int m_unk08;
    unsigned int(__cdecl* m_pfnRead)(S00a46cf0_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

template <class T> inline void NiBinaryStreamLoad(S00a46cf0_BinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

class S00a46cf0_Stream
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
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
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    S00a46cf0_BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void ReadBinaryValue(S00a46cf0_Stream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &value, 1);
}

class S00a46cf0_Entry
{
  public:
    void LoadBinary(S00a46cf0_Stream& kStream);  // ReadFromStream
    unsigned int unk00;
    unsigned int unk04;
};

class S00a46cf0_Base
{
  public:
    void LoadBinary(S00a46cf0_Stream& kStream);  // FUN_00a7b2c0
    void* m_ppVirtualMethodTable;
    unsigned int unk04;
    unsigned int unk08;
};

class S00a46cf0_Object : public S00a46cf0_Base
{
  public:
    void SaveBinary(S00a46cf0_Stream& kStream);  // LoadBinary
    unsigned int m_uiCount;
    S00a46cf0_Entry* m_pEntries;
};

// Calls the base LoadBinary, reads m_uiCount from kStream, then loads each of the m_uiCount entries via their LoadBinary method.
// @fnv 0x00a46cf0
void S00a46cf0_Object::SaveBinary(S00a46cf0_Stream& kStream)
{
    S00a46cf0_Base::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        m_pEntries[i].LoadBinary(kStream);
}

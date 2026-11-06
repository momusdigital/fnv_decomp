
// src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern void* g_011f3f28;
void* __cdecl FUN_00a46b60();
struct NiExtraData
{
    void __thiscall FUN_00a7b2e0();
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern void* DAT_0109827c;
void* __cdecl FUN_00a46b70();
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
struct NiStream;
struct FakeBase00
{
    bool __thiscall FUN_00a7b290(NiStream*);
};
struct FakeKey00
{
    void __thiscall FUN_00a57850(NiStream*);
};
bool __fastcall LoadFromStream(NiTextKeyExtraData* _this, void* _edx, NiStream* stream);
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
extern int DAT_0109b220;
struct FUN_00a46b50_cls
{
    int unk00;
    int m_i04;

    FUN_00a46b50_cls* FUN_00a46b50();
};
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

struct MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern MemoryManager _g_memoryManager;
struct CloningProcess;
struct NiRTTI;
extern void* g_011f3f28;

struct A46FixedString
{
    const char* m_kHandle;
    ~A46FixedString();
};

struct A46TextKey
{
    float m_fTime;
    A46FixedString m_kText;

    A46TextKey();
    ~A46TextKey()
    {}
    static void* operator new[](unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete[](void* p);
    const A46FixedString& GetText() const
    {
        return m_kText;
    }
    void SetText(const A46FixedString& kText);
};

struct A46ExtraData
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    void* m_pcName;
    void* m_unk08;
    void FUN_00a7b330(void* pkDest, CloningProcess* kCloning);
};

struct A46TextKeyExtraData : A46ExtraData
{
    unsigned int m_uiNumKeys;
    A46TextKey* m_pKeys;

    bool IsExactKindOf(const NiRTTI* pkRTTI) const
    {
        return GetRTTI() == pkRTTI;
    }
    void FUN_00a46c20(A46TextKeyExtraData* pkDest, CloningProcess* kCloning);
};

inline bool A46IsExactKindOf(const NiRTTI* pkRTTI, const A46ExtraData* pkObject)
{
    if (!pkObject)
        return false;
    return pkObject->GetRTTI() == pkRTTI;
}

// @fnv 0x00a46c20
void A46TextKeyExtraData::FUN_00a46c20(A46TextKeyExtraData* pkDest, CloningProcess* kCloning)
{
    A46ExtraData::FUN_00a7b330(pkDest, kCloning);
    pkDest->m_uiNumKeys = m_uiNumKeys;
    if (m_uiNumKeys > 0 && A46IsExactKindOf((const NiRTTI*)&g_011f3f28, this))
    {
        pkDest->m_pKeys = new A46TextKey[m_uiNumKeys];
        for (unsigned int i = 0; i < m_uiNumKeys; i++)
        {
            pkDest->m_pKeys[i].m_fTime = m_pKeys[i].m_fTime;
            pkDest->m_pKeys[i].SetText(m_pKeys[i].GetText());
        }
    }
    else
    {
        pkDest->m_pKeys = 0;
    }
}

struct NiStream;
struct BsStream;

struct DynamicMemoryAllocator
{
    void* __thiscall Allocate(unsigned int uiSize);
};

extern "C" DynamicMemoryAllocator g_allocator;

struct NiFixedString
{
    const char* m_pcString;
    ~NiFixedString();
};

struct TimedTextEntry
{
    float m_fTime;
    NiFixedString m_kText;
    TimedTextEntry() throw();
    static void* operator new[](unsigned int uiSize) throw()
    {
        return g_allocator.Allocate(uiSize);
    }
    void __thiscall FUN_00a578d0(NiStream& stream);
};

struct NiExtraDataBase
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void __thiscall LoadBinaryBase(NiStream& stream) throw();
};

struct NiTextKeyExtraDataStub : NiExtraDataBase
{
    unsigned int m_uiNumKeys;
    TimedTextEntry* m_pKeys;
    void __thiscall LoadBinary(NiStream& stream);
};

struct BsStream
{
    unsigned int unk00;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pfnRead)(BsStream* pSelf, unsigned int* pCount, unsigned int uiSize, unsigned int* pSize,
                                     unsigned int uiFlags);
};

struct NiStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk150;
    unsigned int unk154;
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
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BsStream* m_pDataStream;
};

// @fnv 0x00a46e00
void __thiscall NiTextKeyExtraDataStub::LoadBinary(NiStream& stream)
{
    LoadBinaryBase(stream);

    BsStream* pStream = stream.m_pDataStream;
    unsigned int uiNumKeys;
    {
        unsigned int uiSize = 4;
        pStream->m_uiPosition += pStream->m_pfnRead(pStream, &uiNumKeys, 4, &uiSize, 1);
    }

    if (uiNumKeys > 0)
    {
        TimedTextEntry* keys = new TimedTextEntry[uiNumKeys];
        for (unsigned int i = 0; i < uiNumKeys; i++)
        {
            keys[i].FUN_00a578d0(stream);
        }
        m_uiNumKeys = uiNumKeys;
        m_pKeys = keys;
    }
}

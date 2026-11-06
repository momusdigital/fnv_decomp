
// src/gamebryo2.2/corelibs/nimain/nistringsextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nistringsextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f5ebc;

// @fnv 0x00a94820
void* __cdecl FUN_00a94820()
{
    return &g_011f5ebc;
}

struct NiExtraData
{
    void __thiscall FUN_00a7b2e0(void);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_010a0134;

// @fnv 0x00a94930
void* __cdecl FUN_00a94930()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *static_cast<void**>(p) = &DAT_010a0134;
        *(static_cast<int*>(p) + 4) = 0;
        *(static_cast<int*>(p) + 3) = 0;
        return p;
    }
    return 0;
}

void __cdecl NiFreeAlias(void*);
struct NiStringsExtraData
{
    void* m_vtbl;
    void* m_data;
    void* m_auiShapeKeys;
    unsigned int m_uiItemCount;
    void** m_ppData;
    void __thiscall FreeStrings();
    void __thiscall FUN_00a7b300();
};
// @fnv 0x00a94830
void __thiscall NiStringsExtraData::FreeStrings()
{
    m_vtbl = &DAT_010a0134;
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
        NiFreeAlias(m_ppData[i]);
    NiFreeAlias(m_ppData);
    m_ppData = 0;
    FUN_00a7b300();
}

namespace fnv_00a94970 {
void* __cdecl FreeStrings();
void __cdecl operator delete(void*, unsigned int);
struct NiStringsExtraData : NiExtraData
{
    ~NiStringsExtraData();
    void* __thiscall FUN_00a94970(unsigned int flags);
};
// Calls FreeStrings, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00a94970
void* __thiscall NiStringsExtraData::FUN_00a94970(unsigned int flags)
{
    FreeStrings();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}
}  // namespace fnv_00a94970

struct FUN_00a94880_shell
{
    void* m_vtbl;
    void* m_data;
    void* m_auiShapeKeys;
    unsigned int m_uiSize;
    char** m_ppcValue;

    void __thiscall CopyStringsExtraData(NiStringsExtraData* pDest, void* pCloning);
};

struct NiExtraDataFUN_00a7b330_shell
{
    void __thiscall FUN_00a7b330(void*, void*);
};

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);

// @fnv 0x00a94880
void __thiscall FUN_00a94880_shell::CopyStringsExtraData(NiStringsExtraData* pDest, void* pCloning)
{
    unsigned int i;
    unsigned int uiLen;

    ((NiExtraDataFUN_00a7b330_shell*)this)->FUN_00a7b330(pDest, pCloning);

    if (m_ppcValue && m_uiSize > 0)
    {
        pDest->m_uiItemCount = m_uiSize;
        pDest->m_ppData = (void**)_NiMalloc(m_uiSize * 4);

        for (i = 0; i < m_uiSize; ++i)
        {
            if (m_ppcValue[i])
            {
                uiLen = strlen(m_ppcValue[i]) + 1;
                ((char**)pDest->m_ppData)[i] = (char*)_NiMalloc(uiLen);
                _strcpy_s(((char**)pDest->m_ppData)[i], uiLen, m_ppcValue[i]);
            }
            else
            {
                ((char**)pDest->m_ppData)[i] = 0;
            }
        }
    }
    else
    {
        pDest->m_ppData = 0;
        pDest->m_uiItemCount = 0;
    }
}

struct S_00a94a50_Bin
{
    int unk0;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(S_00a94a50_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* v, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        return m_pfnRead(this, v, bytes, sizes, n);
    }
};

struct S_00a94a50_Stream
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034,
        unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c,
        unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4,
        unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc,
        unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114,
        unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c,
        unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184,
        unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc,
        unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c,
        unk230, unk234, unk238, unk23c, unk240, unk244, unk248;
    S_00a94a50_Bin* m_pBin;
    void FUN_00a64ce0(void** str);
};

void* __cdecl FUN_00aa1070(unsigned int size);

static __forceinline void BinRead(S_00a94a50_Bin* b, void* v, unsigned int bytes, unsigned int n)
{
    unsigned int sz = 4;
    b->m_uiPos += b->Read(v, bytes, &sz, n);
}
static __forceinline void LoadU32(S_00a94a50_Stream* s, unsigned int* v, unsigned int n)
{
    BinRead(s->m_pBin, v, 4, n);
}

struct S_00a94a50 : NiStringsExtraData
{
    void FUN_00a7b4a0(S_00a94a50_Stream* s);
    void LoadStringArray(S_00a94a50_Stream* s);
};

// @fnv 0x00a94a50
void S_00a94a50::LoadStringArray(S_00a94a50_Stream* s)
{
    FUN_00a7b4a0(s);
    LoadU32(s, &m_uiItemCount, 1);
    if (m_uiItemCount > 0)
    {
        m_ppData = (void**)FUN_00aa1070(m_uiItemCount * 4);
        for (unsigned int i = 0; i < m_uiItemCount; i++)
        {
            m_ppData[i] = 0;
            s->FUN_00a64ce0(&m_ppData[i]);
        }
    }
    else
    {
        m_ppData = 0;
    }
}

extern "C" void* g_011f5ebc;

char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl ViewerStringStr(const char* pcPrefix, const char* pcValue);

struct ViewerStringArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);

    inline unsigned int Add(char* const& element)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            SetSize(m_usGrowBy + i);
        SetAt(i, element);
        return i;
    }
};

struct ExtraDataViewerBase
{
    void* m_vtbl;
    void* m_pcName;
    void* unk08;
    void GetViewerStrings(ViewerStringArray* apViewerStrings);
};

struct StringsExtraDataViewer : ExtraDataViewerBase
{
    unsigned int m_uiSize;
    char** m_ppcValue;
    void FUN_00a94ae0(ViewerStringArray* apViewerStrings);
};

// Appends the base viewer strings, the m_uiSize value and one formatted string per m_ppcValue entry to the viewer string array.
// @fnv 0x00a94ae0
void StringsExtraDataViewer::FUN_00a94ae0(ViewerStringArray* pViewerStrings)
{
    ExtraDataViewerBase::GetViewerStrings(pViewerStrings);
    pViewerStrings->Add(FUN_00a7d330((const char*)g_011f5ebc));
    pViewerStrings->Add(FUN_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        char* pcValue = ViewerStringStr("m_ppcValue[i]", m_ppcValue[i]);
        unsigned int uiIndex = pViewerStrings->m_usSize;
        if (uiIndex >= pViewerStrings->m_usMaxSize)
            pViewerStrings->SetSize(pViewerStrings->m_usGrowBy + uiIndex);
        if (uiIndex >= pViewerStrings->m_usSize)
        {
            pViewerStrings->m_usSize = (unsigned short)(uiIndex + 1);
            if (pcValue)
                pViewerStrings->m_usESize++;
        }
        else if (pcValue)
        {
            if (!pViewerStrings->m_pBase[uiIndex])
                pViewerStrings->m_usESize++;
        }
        else
        {
            if (pViewerStrings->m_pBase[uiIndex])
                pViewerStrings->m_usESize--;
        }
        pViewerStrings->m_pBase[uiIndex] = pcValue;
    }
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_010a0134;

struct CloneObject
{
    void* m_pVTable;
    void* m_data;
    void* m_auiShapeKeys;
    unsigned int m_uiItemCount;
    void** m_ppData;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    void FUN_00a7b2e0() throw();
    CloneObject() throw()
    {
        FUN_00a7b2e0();
        m_pVTable = (void*)&DAT_010a0134;
        m_ppData = 0;
        m_uiItemCount = 0;
    }
};

struct CloneSource
{
    void CopyStringsExtraData(CloneObject* pDest, void* pCloning);
    CloneObject* CreateClone(void* pCloning);
};

// @fnv 0x00a94990
CloneObject* CloneSource::CreateClone(void* pCloning)
{
    CloneObject* p = new CloneObject;
    CopyStringsExtraData(p, pCloning);
    return p;
}

class A949BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A949BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A949BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A949Object;

class NiStreamA949
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(A949Object* pkObject);

    void WriteStreamString(const char* pcString);
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
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
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    A949BinaryStream* m_pBackingStream;
};

template <class T> inline void A949BinaryStreamSave(A949BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A949SaveBinary(NiStreamA949& kStream, const T& value)
{
    A949BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class NiExtraDataA949
{
  public:
    void SaveBinary(NiStreamA949& kStream);

    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
};

class NiStringsExtraDataA949 : public NiExtraDataA949
{
  public:
    void FUN_00a949f0(NiStreamA949& kStream);

    unsigned int m_uiSize;
    char** m_ppcValue;
};

// @fnv 0x00a949f0
void NiStringsExtraDataA949::FUN_00a949f0(NiStreamA949& kStream)
{
    NiExtraDataA949::SaveBinary(kStream);
    A949SaveBinary(kStream, m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; i++)
        kStream.WriteStreamString(m_ppcValue[i]);
}

extern "C" int __cdecl strcmp(const char* pcA, const char* pcB);

class StrsExtraA947
{
  public:
    bool IsEqual(StrsExtraA947* pkObject);

    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    char** m_ppcValue;
};

// Compares two StrsExtraA947 objects for equality by checking m_uiSize and each m_ppcValue string via strcmp.
// @fnv 0x00a94760
bool StrsExtraA947::IsEqual(StrsExtraA947* pkObject)
{
    if (!pkObject)
        return false;

    StrsExtraA947* pkExtra = pkObject;

    if (m_uiSize != pkExtra->m_uiSize)
        return false;

    if ((m_ppcValue && !pkExtra->m_ppcValue) || (!m_ppcValue && pkExtra->m_ppcValue))
        return false;

    if (m_ppcValue)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcValue[i] && !pkExtra->m_ppcValue[i]) || (!m_ppcValue[i] && pkExtra->m_ppcValue[i]))
            {
                return false;
            }

            if (m_ppcValue[i] && strcmp(m_ppcValue[i], pkExtra->m_ppcValue[i]) != 0)
                return false;
        }
    }

    return true;
}


// src/gamebryo2.2/corelibs/nimain/nifloatsextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifloatsextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f5b60;

// @fnv 0x00a89120
void* __cdecl FUN_00a89120()
{
    return &g_011f5b60;
}

struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a89190
void* __cdecl FUN_00a89190()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p != 0)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *static_cast<void**>(p) = (void*)0x0109ec0c;
        *(int*)(static_cast<char*>(p) + 0x10) = 0;
        *(int*)(static_cast<char*>(p) + 0x0c) = 0;
        return p;
    }
    return 0;
}

struct NiFloatsExtraData
{
    char m_ucUnknownByte[12];
    unsigned int m_uiSize;
    float* m_pfValue;
    bool __thiscall SetValue(const unsigned int uiIndex, float fValue);
};

// @fnv 0x00a89000
bool __thiscall NiFloatsExtraData::SetValue(const unsigned int uiIndex, float fValue)
{
    if (uiIndex < m_uiSize)
    {
        m_pfValue[uiIndex] = fValue;
        return true;
    }
    return false;
}

void* __cdecl _NiMalloc(unsigned int);
struct CloningProcess
{
    char m_ucUnknownByte[12];
    char m_bExactType;
};
struct NiFloatsExtraData_shell : NiFloatsExtraData
{
    void __thiscall CopyFloatsExtraData(NiFloatsExtraData* pDest, CloningProcess* pCloning);
    void __thiscall FUN_00a7b330(NiFloatsExtraData*, CloningProcess*);
};

// Copies the base extra data, then allocates and copies the float array from this object into pDest, or clears pDest's array when empty.
// @fnv 0x00a89040
void __thiscall NiFloatsExtraData_shell::CopyFloatsExtraData(NiFloatsExtraData* pDest, CloningProcess* pCloning)
{
    FUN_00a7b330(pDest, pCloning);
    if (!m_pfValue || m_uiSize <= 0)
    {
        pDest->m_pfValue = 0;
        pDest->m_uiSize = 0;
    }
    else
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_pfValue = (float*)_NiMalloc(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_pfValue[i] = m_pfValue[i];
    }
}

void __cdecl _NiFreeAlias(void*);
struct FUN_00a7b300_shell
{
    void __thiscall _FUN_00a7b300();
};
extern int DAT_0109ec0c;
void __cdecl operator delete(void*, unsigned int);
struct FUN_00a891d0_shell
{
    void* __thiscall DestroyNiFloatsExtraData(unsigned int);
};
// Releases the float array, resets the vtable, runs base cleanup, and optionally frees the object when flags has bit 0 set.
// @fnv 0x00a891d0
void* __thiscall FUN_00a891d0_shell::DestroyNiFloatsExtraData(unsigned int flags)
{
    NiFloatsExtraData* p = (NiFloatsExtraData*)this;
    float* v = p->m_pfValue;
    *(void**)this = (void*)&DAT_0109ec0c;
    _NiFreeAlias(v);
    p->m_pfValue = 0;
    ((FUN_00a7b300_shell*)this)->_FUN_00a7b300();
    if (flags & 1)
        ::operator delete(this, 0x14);
    return this;
}

// NiFloatsExtraData float accessor: bounds-checked read of the value array.
struct FUN_00a89020_cls : NiFloatsExtraData
{
    float __thiscall GetValueAt(unsigned int uiIndex);
};

// @fnv 0x00a89020
float __thiscall FUN_00a89020_cls::GetValueAt(unsigned int uiIndex)
{
    if (uiIndex < m_uiSize)
        return m_pfValue[uiIndex];
    return 0.0f;
}

struct NiFloatsExtraData_compare : NiFloatsExtraData
{
    bool __thiscall IsEqual(const NiFloatsExtraData* pOther);
};
// Compares this NiFloatsExtraData with pOther: checks size, null-ness of the value array, and element-wise equality of the floats.
// @fnv 0x00a890b0
bool __thiscall NiFloatsExtraData_compare::IsEqual(const NiFloatsExtraData* pOther)
{
    if (!pOther)
        return false;
    if (m_uiSize != pOther->m_uiSize)
        return false;

    if ((m_pfValue != 0 && pOther->m_pfValue == 0) || (m_pfValue == 0 && pOther->m_pfValue != 0))
        return false;

    if (m_pfValue)
    {
        for (unsigned int i = 0; i < m_uiSize; ++i)
        {
            if (m_pfValue[i] != pOther->m_pfValue[i])
                return false;
        }
    }
    return true;
}

class A89210BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A89210BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A89210BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A89210Object;

class A89210Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(A89210Object* pkObject);

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
    A89210BinaryStream* m_pBackingStream;
};

template <class T>
inline void A89210BinaryStreamSave(A89210BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A89210SaveBinary(A89210Stream& kStream, const T& value)
{
    A89210BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A89210ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;

    void SaveBinary(A89210Stream& kStream);
};

class A89210IntsExtraData : public A89210ExtraData
{
  public:
    unsigned int m_uiSize;
    int* m_piValue;

    void FUN_00a89210(A89210Stream& kStream);
};

// SaveBinary
// Saves the base extra data, then writes m_uiSize and the m_uiSize ints from m_piValue to the stream.
// @fnv 0x00a89210
void A89210IntsExtraData::FUN_00a89210(A89210Stream& kStream)
{
    A89210ExtraData::SaveBinary(kStream);
    A89210SaveBinary(kStream, m_uiSize);
    A89210BinaryStreamSave(*kStream.m_pBackingStream, m_piValue, m_uiSize);
}

extern "C" void* g_011f5b60;
char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl FUN_00a7d550(const char* pcPrefix, float fValue);

template <class T> struct NiTMallocInterface
{
};

template <class T, class TAlloc> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element)
    {
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
    }
    unsigned int SetAtGrow(unsigned int uiIndex, T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(T element)
    {
        return SetAtGrow(m_usSize, element);
    }

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > NiViewerStringsArray;

struct NiExtraDataStub
{
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

struct NiFloatsExtraDataStub : NiExtraDataStub
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    float* m_pfValue;
    void FUN_00a89280(NiViewerStringsArray* pkStrings);
};

// Appends the base viewer strings, the m_uiSize entry and one entry per element of m_pfValue to pkStrings.
// @fnv 0x00a89280
void NiFloatsExtraDataStub::FUN_00a89280(NiViewerStringsArray* pkStrings)
{
    NiExtraDataStub::GetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330((const char*)g_011f5b60));
    pkStrings->Add(FUN_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(FUN_00a7d550("m_pfValue[i]", m_pfValue[i]));
}

class BA99A90BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA99A90BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BA99A90Stream
{
  public:
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
    unsigned int m_uiFileVersion;
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
    BA99A90BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void BA99A90BinaryStreamLoad(BA99A90BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA99A90LoadBinary(BA99A90Stream& kStream, T& value)
{
    BA99A90BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

void* __cdecl NiMalloc(unsigned int uiSize);

class BA99A90ExtraData
{
  public:
    virtual void LoadBinary(BA99A90Stream& kStream);

    int m_iRefCount;
    const char* m_kName;
};

class FUN_00a99a90_IntsExtraData : public BA99A90ExtraData
{
  public:
    virtual void LoadBinary(BA99A90Stream& kStream);

    unsigned int m_uiSize;
    int* m_piValue;
};

// Loads the base extra data, reads m_uiSize, then allocates and reads m_uiSize ints into m_piValue (or nulls it if size is 0).
// @fnv 0x00a99a90
void FUN_00a99a90_IntsExtraData::LoadBinary(BA99A90Stream& kStream)
{
    BA99A90ExtraData::LoadBinary(kStream);

    BA99A90LoadBinary(kStream, m_uiSize);
    if (m_uiSize > 0)
    {
        m_piValue = static_cast<int*>(NiMalloc(sizeof(int) * m_uiSize));
        BA99A90BinaryStreamLoad(*kStream.m_pUnderlyingStream, m_piValue, m_uiSize);
    }
    else
    {
        m_piValue = 0;
    }
}

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
struct A89130Layout
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    float* m_pfValue;
};
struct A89130Owner : NiFloatsExtraData_shell
{
    NiFloatsExtraData* CreateNiFloatsExtraData(CloningProcess* pCloning);
};
// @fnv 0x00a89130
NiFloatsExtraData* A89130Owner::CreateNiFloatsExtraData(CloningProcess* pCloning)
{
    NiFloatsExtraData* pExtraData = (NiFloatsExtraData*)FUN_00aa13e0(0x14);
    NiFloatsExtraData* ret =
        pExtraData
            ? (((NiExtraData*)pExtraData)->FUN_00a7b2e0(), ((A89130Layout*)pExtraData)->m_ppVirtualMethodTable = (void*)&DAT_0109ec0c,
               ((A89130Layout*)pExtraData)->m_pfValue = 0, ((A89130Layout*)pExtraData)->m_uiSize = 0, pExtraData)
            : 0;
    CopyFloatsExtraData(ret, pCloning);
    return ret;
}

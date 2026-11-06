
// src/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;

extern NiRTTI g_011f5eac;

// @fnv 0x00a93740
NiRTTI* __cdecl FUN_00a93740()
{
    return &g_011f5eac;
}

struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_0109ff64;

// @fnv 0x00a93870
void* __cdecl FUN_00a93870()
{
    void* p = BSFadeNode::operator new(0x18);
    if (p)
    {
        NiExtraData* pExtra = static_cast<NiExtraData*>(p);
        pExtra->FUN_00a7b2e0();
        *reinterpret_cast<int**>(p) = &DAT_0109ff64;
        reinterpret_cast<int*>(p)[4] = 0;
        reinterpret_cast<int*>(p)[3] = 0;
        reinterpret_cast<int*>(p)[5] = -1;
        return p;
    }
    return 0;
}

void __cdecl NiFreeAlias(void*);
void __cdecl FUN_00a7b300();
struct NiRTTI;
extern NiRTTI g_011f5eac;
struct NiFile;
struct FUN_00a93750_shell
{
    void* m_pData;
    NiRTTI* m_pRTTI;
    NiFile* m_pFile;
    unsigned int m_nCount;
    void** m_pEntryData;
    void FUN_00a93750();
};
// @fnv 0x00a93750
void FUN_00a93750_shell::FUN_00a93750()
{
    m_pData = &DAT_0109ff64;
    for (unsigned int i = 0; i < m_nCount; ++i)
        NiFreeAlias(m_pEntryData[i]);
    NiFreeAlias(m_pEntryData);
    m_pEntryData = 0;
    ((void(__thiscall*)(void*))FUN_00a7b300)(this);
}

void __cdecl _delete(void* p, unsigned int);

struct NiSwitchStringExtraData
{
    void* __thiscall FUN_00a938b0(unsigned int flags);
};

void __cdecl FUN_00a93750();

// Calls FUN_00a93750, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a938b0
void* __thiscall NiSwitchStringExtraData::FUN_00a938b0(unsigned int flags)
{
    FUN_00a93750();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_0109f9b4;
struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;
struct S_00a918e0
{
    void* f0;
    void* f4;
    void* __thiscall FUN_00a918e0(unsigned int);
};
// @fnv 0x00a918e0
void* __thiscall S_00a918e0::FUN_00a918e0(unsigned int auiFlags)
{
    void* v = f4;
    f0 = (void*)&DAT_0109f9b4;
    ReleaseObjectArray(v);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct StrArr
{
    void* m_pUnknown;
    char** m_pEntryData;
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short m_uiNonNullCount;
    unsigned short m_uiGrowSize;

    void __thiscall SetSize(unsigned int size);
    void __thiscall SetAt(unsigned int index, char*& value);
};

typedef StrArr A89C70StringArray;

struct A89C70Base
{
    void __thiscall GetViewerStrings(A89C70StringArray* strings);
};

char* __cdecl _FUN_00a7d330(void* object);
char* __cdecl FUN_00a7d510(char const* name, char const* value);
char* __cdecl FUN_00a7d5e0(char const* name, char const* value);
char* __cdecl FUN_00a7d4d0(char const* name, int value);

struct FUN_00a93a60_shell
{
    void* m_pUnknown0;
    void* m_pUnknown1;
    void* m_pUnknown2;
    unsigned int m_uiSize;
    char** m_ppcValue;
    int m_iIndex;

    void FUN_00a93a60(StrArr* apViewerStrings);
};

// Appends viewer strings for the base object, m_uiSize, each m_ppcValue[i] and m_iIndex to the given string array.
// @fnv 0x00a93a60
void FUN_00a93a60_shell::FUN_00a93a60(StrArr* apViewerStrings)
{
    reinterpret_cast<A89C70Base*>(this)->GetViewerStrings(apViewerStrings);

    {
        char* value = _FUN_00a7d330(*(void**)&g_011f5eac);
        unsigned int index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
        }
        apViewerStrings->SetAt(index, value);

        value = FUN_00a7d510("m_uiSize", reinterpret_cast<char const*>(m_uiSize));
        index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
        }
        apViewerStrings->SetAt(index, value);

        for (unsigned int i = 0; i < m_uiSize; ++i)
        {
            value = FUN_00a7d5e0("m_ppcValue[i]", m_ppcValue[i]);
            index = apViewerStrings->m_uiSize;
            if (index >= apViewerStrings->m_uiCapacity)
            {
                apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
            }

            if (index >= apViewerStrings->m_uiSize)
            {
                apViewerStrings->m_uiSize = static_cast<unsigned short>(index + 1);
                if (value)
                {
                    ++apViewerStrings->m_uiNonNullCount;
                }
            }
            else
            {
                if (value)
                {
                    if (!apViewerStrings->m_pEntryData[index])
                    {
                        ++apViewerStrings->m_uiNonNullCount;
                    }
                }
                else
                {
                    if (apViewerStrings->m_pEntryData[index])
                    {
                        apViewerStrings->m_uiNonNullCount += static_cast<unsigned short>(0xffff);
                    }
                }
            }
            apViewerStrings->m_pEntryData[index] = value;
        }
    }

    {
        char* value = FUN_00a7d4d0("m_iIndex", m_iIndex);
        unsigned int index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
        }

        if (index >= apViewerStrings->m_uiSize)
        {
            apViewerStrings->m_uiSize = static_cast<unsigned short>(index + 1);
            if (value)
            {
                ++apViewerStrings->m_uiNonNullCount;
            }
        }
        else
        {
            if (value)
            {
                if (!apViewerStrings->m_pEntryData[index])
                {
                    ++apViewerStrings->m_uiNonNullCount;
                }
            }
            else
            {
                if (apViewerStrings->m_pEntryData[index])
                {
                    apViewerStrings->m_uiNonNullCount += static_cast<unsigned short>(0xffff);
                }
            }
        }
        apViewerStrings->m_pEntryData[index] = value;
    }
}

extern "C" int __cdecl strcmp(const char*, const char*);

class A93680Strings
{
  public:
    bool Equals(A93680Strings* pkOther);

    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    char** m_ppcStrings;
    int m_iType;
};

// @fnv 0x00a93680
bool A93680Strings::Equals(A93680Strings* pkOther)
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (m_iType != pkOther->m_iType)
        return false;
    if ((m_ppcStrings && !pkOther->m_ppcStrings) || (!m_ppcStrings && pkOther->m_ppcStrings))
        return false;
    if (m_ppcStrings)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcStrings[i] && !pkOther->m_ppcStrings[i]) || (!m_ppcStrings[i] && pkOther->m_ppcStrings[i]))
                return false;
            if (m_ppcStrings[i] && strcmp(m_ppcStrings[i], pkOther->m_ppcStrings[i]) != 0)
                return false;
        }
    }
    return true;
}

struct StrListObj
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    unsigned int m_uiCount;
    char** m_ppStrings;
    int m_iIndex;

    void FUN_00a7b330(StrListObj* dst, void* arg2);
    void CopyStringList(StrListObj* dst, void* arg2);
};

void* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl FUN_00ec65a6(void* dst, unsigned int size, void* src);

// @fnv 0x00a937a0
void StrListObj::CopyStringList(StrListObj* dst, void* arg2)
{
    FUN_00a7b330(dst, arg2);
    if (m_ppStrings == 0 || m_uiCount <= 0)
    {
        dst->m_ppStrings = 0;
        dst->m_uiCount = 0;
        return;
    }
    dst->m_uiCount = m_uiCount;
    if (m_iIndex > -1 && m_iIndex < (int)m_uiCount)
    {
        dst->m_iIndex = m_iIndex;
    }
    else
    {
        dst->m_iIndex = -1;
    }
    dst->m_ppStrings = (char**)FUN_00aa1070(m_uiCount * 4);
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        if (m_ppStrings[i] != 0)
        {
            char* p = m_ppStrings[i];
            char* base = p + 1;
            char cChar;
            do
            {
                cChar = *p;
                p++;
            } while (cChar != 0);
            unsigned int uiLen = (unsigned int)(p - base);
            dst->m_ppStrings[i] = (char*)FUN_00aa1070(uiLen + 1);
            FUN_00ec65a6(dst->m_ppStrings[i], uiLen + 1, m_ppStrings[i]);
        }
        else
        {
            dst->m_ppStrings[i] = 0;
        }
    }
}

struct NiBinaryStreamView
{
    typedef unsigned int(__cdecl* READFN)(NiBinaryStreamView*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int m_uiBufferSize;
    READFN m_pfnRead;
    __forceinline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                          unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct NiStreamView
{
    __forceinline NiBinaryStreamView* Input()
    {
        return *reinterpret_cast<NiBinaryStreamView**>(reinterpret_cast<char*>(this) + 0x250);
    }
    void FUN_00a64160(unsigned int linkId);
};

struct NiExtraDataView
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    char* m_pcName;
    unsigned int m_uiNumEntries;
    unsigned int* m_pLinkIds;
    unsigned int m_uiNumLinkIds;
    void FUN_00a7b2c0(NiStreamView& kStream);
    void LoadFromStream(NiStreamView& kStream);
};

template <class T> __forceinline void NiBinaryStreamLoad(NiBinaryStreamView& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}
template <class T> __forceinline void ReadBinaryValue(NiStreamView& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.Input(), &value, 1);
}

// @fnv 0x00a939d0
void NiExtraDataView::LoadFromStream(NiStreamView& kStream)
{
    FUN_00a7b2c0(kStream);
    ReadBinaryValue(kStream, m_uiNumEntries);
    for (unsigned int i = 0; i < m_uiNumEntries; ++i)
        kStream.FUN_00a64160(m_pLinkIds[i]);
    ReadBinaryValue(kStream, m_uiNumLinkIds);
}

// Uses insights from unverified 2026-10-23 contributor attempt.
extern int DAT_0109ff64;
struct SSE_Node : NiExtraData
{
    void* m_vtbl;
    unsigned int unk04, unk08, unk0C, unk10;
    int unk14;
    static void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    SSE_Node() throw()
    {
        FUN_00a7b2e0();
        m_vtbl = &DAT_0109ff64;
        unk10 = 0;
        unk0C = 0;
        unk14 = -1;
    }
};
struct SSE_Owner : NiSwitchStringExtraData
{
    SSE_Node* CreateNode(unsigned int);
    void CopyStringList(SSE_Node*, unsigned int);
};
// @fnv 0x00a938d0
SSE_Node* SSE_Owner::CreateNode(unsigned int arg)
{
    SSE_Node* obj = new SSE_Node;
    CopyStringList(obj, arg);
    return obj;
}

void* __cdecl NiMalloc(unsigned int stSizeInBytes);

class NiBinaryStreamA939
{
  public:
    typedef unsigned int(__cdecl* READFN)(NiBinaryStreamA939* pkThis, void* pvBuffer, unsigned int uiBytes,
                                          unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    READFN m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA939* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

class NiObjectA939;

class NiStreamA939
{
  public:
    int unk000[0x24c / 4];
    NiBinaryStreamA939* m_pUnderlyingStream;

    void FUN_00a64ce0(NiObjectA939** ppkObject);
};

class NiExtraDataA939
{
  public:
    virtual void vfn_00();
    void FUN_00a7b4a0(NiStreamA939& kStream);
    unsigned int m_uiRefCount;
    char* m_pcName;
};

class LinkArrayExtraA939 : public NiExtraDataA939
{
  public:
    unsigned int m_uiCount;
    NiObjectA939** m_ppkObjects;
    unsigned int m_uiValue1;

    void LoadBinary(NiStreamA939& kStream);
};

// Reads m_uiCount, allocates m_ppkObjects and loads each object via kStream, then reads m_uiValue1 from the underlying stream.
// @fnv 0x00a93930
void LinkArrayExtraA939::LoadBinary(NiStreamA939& kStream)
{
    FUN_00a7b4a0(kStream);
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &m_uiCount, 1);
    if (m_uiCount > 0)
    {
        m_ppkObjects = (NiObjectA939**)NiMalloc(m_uiCount * sizeof(NiObjectA939*));
        for (unsigned int i = 0; i < m_uiCount; i++)
            kStream.FUN_00a64ce0(&m_ppkObjects[i]);
    }
    else
    {
        m_ppkObjects = 0;
    }
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &m_uiValue1, 1);
}

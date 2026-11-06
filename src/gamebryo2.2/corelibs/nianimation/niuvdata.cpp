
// src/gamebryo2.2/corelibs/nianimation/niuvdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niuvdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const void* g_011f3f10;

// @fnv 0x00a45010
const void* __cdecl FUN_00a45010()
{
    return &g_011f3f10;
}

struct NiUVData
{
    void Destructor();
    void* FUN_00a45200(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls Destructor, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a45200
void* NiUVData::FUN_00a45200(unsigned int flags)
{
    Destructor();
    if (flags & 1)
        _delete(this, 0x4C);
    return this;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
struct S45280
{
    void FUN_00a45280(void* keys, unsigned int count, int type);
};
// @fnv 0x00a45280
void S45280::FUN_00a45280(void* keys, unsigned int count, int type)
{
    void* oldKeys = *(void**)((char*)this + 0x18);
    if (oldKeys)
        DAT_011f38a0[*(int*)((char*)this + 0x1c)](oldKeys);
    if (keys && count)
    {
        *(unsigned int*)((char*)this + 0x14) = count;
        *(void**)((char*)this + 0x18) = keys;
        *(int*)((char*)this + 0x1c) = type;
        *(unsigned char*)((char*)this + 0x49) = DAT_011f3758[type];
    }
    else
    {
        *(unsigned int*)((char*)this + 0x14) = 0;
        *(void**)((char*)this + 0x18) = 0;
        *(int*)((char*)this + 0x1c) = 0;
        *(unsigned char*)((char*)this + 0x49) = 0;
    }
}

namespace fnv_00a45340 {
extern const unsigned char DAT_011f3758[];
extern void(__cdecl* DAT_011f38a0[10])(void*);

struct FUN_00a45340_shell
{
    char m_auiShapeKeys[0x2c];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    unsigned int m_eRequestType;
    char m_pAuxiliaryObject[0x13];
    unsigned char m_ucKeyDataSize;
    void FUN_00a45340(void* keys, unsigned int count, unsigned int type);
};

// Releases the previous key data, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a45340
void FUN_00a45340_shell::FUN_00a45340(void* keys, unsigned int count, unsigned int type)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && count)
    {
        m_uiNumKeys = count;
        m_pKeyArray = keys;
        m_eRequestType = type;
        m_ucKeyDataSize = DAT_011f3758[type];
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = 0;
        m_ucKeyDataSize = 0;
    }
}
}  // namespace fnv_00a45340

namespace fnv_00a45220 {
struct TimedAnimationKey;

extern unsigned char DAT_011f3758[];
extern void(__cdecl* DAT_011f38a0[])(TimedAnimationKey*);

struct FUN_00a45220_shell
{
    void* _pad0;
    void* _pad4;
    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pKeyArray;
    unsigned int m_eRequestType;
    char _pad[0x34];
    unsigned char m_ucKeyDataSize;
    void FUN_00a45220(TimedAnimationKey* keys, unsigned int numKeys, unsigned int type);
};

// Releases the current key array, then stores the new keys, count and type (or clears them when keys or numKeys is null/zero).
// @fnv 0x00a45220
void FUN_00a45220_shell::FUN_00a45220(TimedAnimationKey* keys, unsigned int numKeys, unsigned int type)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && numKeys)
    {
        m_uiNumKeys = numKeys;
        m_pKeyArray = keys;
        m_eRequestType = type;
        m_ucKeyDataSize = DAT_011f3758[type];
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = 0;
        m_ucKeyDataSize = 0;
    }
}
}  // namespace fnv_00a45220

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
struct FUN_00a452e0_shell
{
    unsigned char _pad0[0x20];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    unsigned int m_eRequestType;
    unsigned char _pad1[0x4A - 0x2C];
    unsigned char m_ucKeyDataSize;
    void FUN_00a452e0(void* keys, unsigned int count, unsigned int type);
};
// Releases the previous key array, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a452e0
void FUN_00a452e0_shell::FUN_00a452e0(void* keys, unsigned int count, unsigned int type)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && count)
    {
        m_uiNumKeys = count;
        m_pKeyArray = keys;
        m_eRequestType = type;
        m_ucKeyDataSize = DAT_011f3758[type];
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = 0;
        m_ucKeyDataSize = 0;
    }
}

extern int DAT_01097f84;
extern void(__cdecl* DAT_011f38a0[])(void*);

struct NiRefObject
{
    ~NiRefObject();
};

// Sets the vtable, releases the four pointer members via DAT_011f38a0 if non-null, then calls the NiRefObject destructor.
// @fnv 0x00a45020
void NiUVData::Destructor()
{
    *(void**)this = (void*)&DAT_01097f84;
    void* p;
    p = *(void**)((char*)this + 0xc);
    if (p)
        DAT_011f38a0[*(unsigned int*)((char*)this + 0x10)](p);
    p = *(void**)((char*)this + 0x18);
    if (p)
        DAT_011f38a0[*(unsigned int*)((char*)this + 0x1c)](p);
    p = *(void**)((char*)this + 0x24);
    if (p)
        DAT_011f38a0[*(unsigned int*)((char*)this + 0x28)](p);
    p = *(void**)((char*)this + 0x30);
    if (p)
        DAT_011f38a0[*(unsigned int*)((char*)this + 0x34)](p);
    ((NiRefObject*)this)->~NiRefObject();
}

struct StrArr
{
    unsigned char _pad0[8];
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned char _pad1[2];
    unsigned short m_uiGrowSize;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(char*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);

struct FUN_00a457d0_shell
{
    unsigned char _pad0[8];
    unsigned int m_uiNumUOffsetKeys;
    unsigned char _pad1[8];
    unsigned int m_uiNumVOffsetKeys;
    unsigned char _pad2[8];
    unsigned int m_uiNumUTilingKeys;
    unsigned char _pad3[8];
    unsigned int m_uiNumVTilingKeys;

    void AppendKeyNames(StrArr*);
};

// @fnv 0x00a457d0
void FUN_00a457d0_shell::AppendKeyNames(StrArr* apViewerStrings)
{
    char* pString;
    unsigned int nIndex;

    AppendCameraPathEntries(apViewerStrings);

    pString = _FUN_00a7d330(const_cast<char*>(static_cast<const char*>(g_011f3f10)));
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = FUN_00a7d510("m_uiNumUOffsetKeys", m_uiNumUOffsetKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = FUN_00a7d510("m_uiNumUTilingKeys", m_uiNumUTilingKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = FUN_00a7d510("m_uiNumVOffsetKeys", m_uiNumVOffsetKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = FUN_00a7d510("m_uiNumVTilingKeys", m_uiNumVTilingKeys);
    nIndex = apViewerStrings->m_uiSize;
    if (nIndex >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_uiGrowSize + nIndex);
    apViewerStrings->SetAt(nIndex, pString);
}

extern bool(__cdecl* DAT_011f3ae0[])(void*, void*);

struct NiObject
{
    bool IsEqual(NiObject* pkObject);
};

struct NiUVDataStandIn : public NiObject
{
    int unk00;
    int unk04;
    unsigned int m_uiNumUOffsetKeys;
    unsigned char* m_pUOffsetKeys;
    unsigned int m_uiUOffsetKeyStride;
    unsigned int m_uiNumVOffsetKeys;
    unsigned char* m_pVOffsetKeys;
    unsigned int m_uiVOffsetKeyStride;
    unsigned int m_uiNumUTilingKeys;
    unsigned char* m_pUTilingKeys;
    unsigned int m_uiUTilingKeyStride;
    unsigned int m_uiNumVTilingKeys;
    unsigned char* m_pVTilingKeys;
    unsigned int m_uiVTilingKeyStride;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    unsigned char m_ucByte48;
    unsigned char m_ucByte49;
    unsigned char m_ucByte4A;
    unsigned char m_ucByte4B;

    static unsigned char* GetKeyPointerByIndex(unsigned char* pk, unsigned int i, unsigned char uc)
    {
        return pk + i * uc;
    }
    bool FUN_00a45090(NiUVDataStandIn* pkOther);
};

// @fnv 0x00a45090
bool NiUVDataStandIn::FUN_00a45090(NiUVDataStandIn* pkOther)
{
    if (!NiObject::IsEqual(pkOther))
        return false;

    if (m_uiNumUOffsetKeys != pkOther->m_uiNumUOffsetKeys || m_uiUOffsetKeyStride != pkOther->m_uiUOffsetKeyStride ||
        m_uiNumVOffsetKeys != pkOther->m_uiNumVOffsetKeys || m_uiVOffsetKeyStride != pkOther->m_uiVOffsetKeyStride ||
        m_uiNumUTilingKeys != pkOther->m_uiNumUTilingKeys || m_uiUTilingKeyStride != pkOther->m_uiUTilingKeyStride ||
        m_uiNumVTilingKeys != pkOther->m_uiNumVTilingKeys || m_uiVTilingKeyStride != pkOther->m_uiVTilingKeyStride ||
        m_ucByte48 != pkOther->m_ucByte48 || m_ucByte49 != pkOther->m_ucByte49 || m_ucByte4A != pkOther->m_ucByte4A ||
        m_ucByte4B != pkOther->m_ucByte4B)
        return false;

    unsigned int i;
    bool(__cdecl * pfnKeyEqual)(void*, void*);

    pfnKeyEqual = DAT_011f3ae0[m_uiUOffsetKeyStride];
    for (i = 0; i < m_uiNumUOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pUOffsetKeys, i, m_ucByte48),
                         GetKeyPointerByIndex(pkOther->m_pUOffsetKeys, i, m_ucByte48)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiVOffsetKeyStride];
    for (i = 0; i < m_uiNumVOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pVOffsetKeys, i, m_ucByte49),
                         GetKeyPointerByIndex(pkOther->m_pVOffsetKeys, i, m_ucByte49)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiUTilingKeyStride];
    for (i = 0; i < m_uiNumUTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pUTilingKeys, i, m_ucByte4A),
                         GetKeyPointerByIndex(pkOther->m_pUTilingKeys, i, m_ucByte4A)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiVTilingKeyStride];
    for (i = 0; i < m_uiNumVTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pVTilingKeys, i, m_ucByte4B),
                         GetKeyPointerByIndex(pkOther->m_pVTilingKeys, i, m_ucByte4B)))
            return false;
    }

    return true;
}

class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiUVStream
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
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiUVStream& kStream, T& val)
{
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &val, 1);
}

template <class T> inline void ReadStreamValue(NiUVStream& kStream, T& eValue)
{
    unsigned int uiValue;
    ReadBinaryValue(kStream, uiValue);
    eValue = (T)uiValue;
}

enum NiUVKeyType
{
    NOINTERP,
    LINKEY,
    BEZKEY,
    TCBKEY,
    EULERKEY,
    STEPKEY,
    NUMKEYTYPES
};

class NiUVKey;
typedef NiUVKey*(__cdecl* NiUVKeyCreateFunction)(NiUVStream& kStream, unsigned int uiNumKeys);
typedef void(__cdecl* NiUVKeyFillFunction)(NiUVKey* pkKeys, unsigned int uiNumKeys, unsigned char ucSize);
extern unsigned char g_aucFloatKeySizes[];
extern NiUVKeyCreateFunction g_apfnFloatKeyCreate[];
extern NiUVKeyFillFunction g_apfnFloatKeyFill[];

class NiUVObject
{
  public:
    virtual ~NiUVObject();
    void LoadBinary(NiUVStream& kStream);
};

class NiUVDataLoader : public NiUVObject
{
  public:
    int m_uiRefCount;
    int unk08;
    unsigned int m_uiNumUOffsetKeys;
    NiUVKey* m_pUOffsetKeys;
    unsigned int m_uiUOffsetKeyStride;
    unsigned int m_uiNumVOffsetKeys;
    NiUVKey* m_pVOffsetKeys;
    unsigned int m_uiVOffsetKeyStride;
    unsigned int m_uiNumUTilingKeys;
    NiUVKey* m_pUTilingKeys;
    unsigned int m_uiUTilingKeyStride;
    unsigned int m_uiNumVTilingKeys;
    NiUVKey* m_pVTilingKeys;
    unsigned int m_uiVTilingKeyStride;
    int unk3C;
    int unk40;
    int unk44;
    unsigned char m_ucByte48;
    unsigned char m_ucByte49;
    unsigned char m_ucByte4A;
    unsigned char m_ucByte4B;

    void ReplaceUOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceUTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void FUN_00a453a0(NiUVStream& kStream);
};

// Loads the base object, then reads U/V offset and U/V tiling key blocks from the stream and replaces each key set.
// @fnv 0x00a453a0
void NiUVDataLoader::FUN_00a453a0(NiUVStream& kStream)
{
    NiUVObject::LoadBinary(kStream);

    unsigned int uiNumKeys;
    NiUVKeyType eType;

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte48 = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte48);
        ReplaceUOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte49 = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte49);
        ReplaceVOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte4A = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte4A);
        ReplaceUTilingKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte4B = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte4B);
        ReplaceVTilingKeys(pkKeys, uiNumKeys, eType);
    }
}

// NiUVData::LoadBinary: base LoadBinary, then for each of the four UV key groups read the key
// count and, if any, the key type and the keys through the per-type float-key loader table.
struct NiBinaryStreamX
{
    unsigned int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamX* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct NiStreamX
{
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
    NiBinaryStreamX* m_pUnderlyingStream;
};

template <class T> inline unsigned int ReadBinaryValue(NiBinaryStreamX& kBinstream, T& value)
{
    unsigned int uiSize = sizeof(T);
    return kBinstream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}
template <class T> inline unsigned int ReadBinaryValue(NiStreamX& kStream, T& value)
{
    return ReadBinaryValue(*kStream.m_pUnderlyingStream, value);
}

extern void(__cdecl* DAT_011f3a50[])(NiStreamX& kStream, void* pkKeys, unsigned int uiNumKeys);

struct NiObjectLB
{
    void* m_pVtbl;
    unsigned int m_uiRefCount;
    void LoadBinary(NiStreamX& kStream);
};

struct NiUVDataLB : NiObjectLB
{
    unsigned int m_uiNumUOffsetKeys;
    void* m_pUOffsetKeys;
    unsigned int m_uiUOffsetKeyStride;
    unsigned int m_uiNumVOffsetKeys;
    void* m_pVOffsetKeys;
    unsigned int m_uiVOffsetKeyStride;
    unsigned int m_uiNumUTilingKeys;
    void* m_pUTilingKeys;
    unsigned int m_uiUTilingKeyStride;
    unsigned int m_uiNumVTilingKeys;
    void* m_pVTilingKeys;
    unsigned int m_uiVTilingKeyStride;
    void SaveBinary(NiStreamX& kStream);
};

// Loads the base object, then reads the U/V offset and tiling key counts and, when nonzero, reads each key array via the key-type loader table.
// @fnv 0x00a45610
void NiUVDataLB::SaveBinary(NiStreamX& kStream)
{
    NiObjectLB::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_uiNumUOffsetKeys);
    if (m_uiNumUOffsetKeys > 0)
    {
        ReadBinaryValue(kStream, m_uiUOffsetKeyStride);
        DAT_011f3a50[m_uiUOffsetKeyStride](kStream, m_pUOffsetKeys, m_uiNumUOffsetKeys);
    }
    ReadBinaryValue(kStream, m_uiNumVOffsetKeys);
    if (m_uiNumVOffsetKeys > 0)
    {
        ReadBinaryValue(kStream, m_uiVOffsetKeyStride);
        DAT_011f3a50[m_uiVOffsetKeyStride](kStream, m_pVOffsetKeys, m_uiNumVOffsetKeys);
    }
    ReadBinaryValue(kStream, m_uiNumUTilingKeys);
    if (m_uiNumUTilingKeys > 0)
    {
        ReadBinaryValue(kStream, m_uiUTilingKeyStride);
        DAT_011f3a50[m_uiUTilingKeyStride](kStream, m_pUTilingKeys, m_uiNumUTilingKeys);
    }
    ReadBinaryValue(kStream, m_uiNumVTilingKeys);
    if (m_uiNumVTilingKeys > 0)
    {
        ReadBinaryValue(kStream, m_uiVTilingKeyStride);
        DAT_011f3a50[m_uiVTilingKeyStride](kStream, m_pVTilingKeys, m_uiNumVTilingKeys);
    }
}

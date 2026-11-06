
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlrdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterctlrdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202760;

// @fnv 0x00c2baa0
void* __cdecl FUN_00c2baa0()
{
    return &g_01202760;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
struct FUN_00c2bb70_shell
{
    char _0[8];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void FUN_00c2bb70(void* keys, unsigned int numKeys, int type);
};
// @fnv 0x00c2bb70
void FUN_00c2bb70_shell::FUN_00c2bb70(void* keys, unsigned int numKeys, int type)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && numKeys)
    {
        m_ucKeyDataSize = DAT_011f3758[type];
        m_pKeyArray = keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = 0;
        m_ucKeyDataSize = 0;
    }
}

struct AnimationKey;
extern int DAT_010bfd54;
extern void(__cdecl* DAT_011f38a0[])(void*);
extern void(__cdecl* DAT_011f3918[])(AnimationKey*);
struct NiRefObject
{
    ~NiRefObject();
};
void __cdecl _delete(void*, unsigned int);
struct NiPSysEmitterCtlrData
{
    void* Destroy(unsigned int);
};
// @fnv 0x00c2bc30
void* NiPSysEmitterCtlrData::Destroy(unsigned int flags)
{
    void* pkKeys = *(void**)((char*)this + 0xc);
    *(void**)this = (void*)&DAT_010bfd54;
    if (pkKeys)
        DAT_011f38a0[*(int*)((char*)this + 0x10)](pkKeys);
    pkKeys = *(void**)((char*)this + 0x1c);
    if (pkKeys)
        DAT_011f3918[*(int*)((char*)this + 0x20)]((AnimationKey*)pkKeys);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (flags & 1)
        _delete(this, 0x28);
    return this;
}

struct StrArr
{
    unsigned char _0[8];
    unsigned short m_usCapacity;
    unsigned short m_usSize;
    unsigned short _1;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

struct FUN_00c2bf00_shell
{
    unsigned char _0[8];
    unsigned int m_uiValueAtOffset8;
    unsigned int _1;
    int m_iBirthRateKeyIndex;
    unsigned int _2;
    unsigned int m_uiNumFloatKeys;

    void AppendBirthRateKeys(StrArr* pkStrings);
};

void __stdcall AppendCameraPathEntries(StrArr*);
void* __cdecl _FUN_00a7d330(void*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);
char* __cdecl FUN_00a7d5e0(char const*, char const*);

// @fnv 0x00c2bf00
void FUN_00c2bf00_shell::AppendBirthRateKeys(StrArr* pkStrings)
{
    unsigned int uiIndex;
    char* pcValue;
    char* pcKeyTypeName;

    AppendCameraPathEntries(pkStrings);

    pcValue = (char*)_FUN_00a7d330(g_01202760);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usCapacity)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    pcValue = FUN_00a7d510("Num Birth Rate Keys", m_uiValueAtOffset8);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usCapacity)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    switch (m_iBirthRateKeyIndex)
    {
    case 1:
        pcKeyTypeName = (char*)"LINKEY";
        break;
    case 2:
        pcKeyTypeName = (char*)"BEZKEY";
        break;
    case 3:
        pcKeyTypeName = (char*)"TCBKEY";
        break;
    default:
        pcKeyTypeName = (char*)"Unknown";
        break;
    }

    pcValue = FUN_00a7d5e0("Birth Rate Key Type", pcKeyTypeName);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usCapacity)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    pcValue = FUN_00a7d510("Num Emitter Active Keys", m_uiNumFloatKeys);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usCapacity)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);
}

struct S_00c2bab0
{
    int unk00;
    int unk04;
    unsigned int m_uiNumKeys;
    unsigned char* m_pKeyArray;
    unsigned int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char unk15;
    unsigned short unk16;
    unsigned int m_uiNumKeys2;
    unsigned char* m_pkKeys2;
    unsigned int unk20;
    unsigned char m_ucKeySize2;

    bool IsSameAs(S_00c2bab0* other);
    bool Equals(S_00c2bab0* other);
};

extern bool(__cdecl* DAT_011f3ae0[])(unsigned char*, unsigned char*);

// @fnv 0x00c2bab0
bool S_00c2bab0::Equals(S_00c2bab0* other)
{
    if (!IsSameAs(other))
        return false;

    if (other->m_uiNumKeys != m_uiNumKeys)
        return false;

    if (other->m_eRequestType != m_eRequestType)
        return false;

    if (other->m_uiNumKeys2 != m_uiNumKeys2)
        return false;

    if (other->m_ucKeyDataSize != m_ucKeyDataSize)
        return false;

    bool(__cdecl * pfnCompare)(unsigned char*, unsigned char*) = DAT_011f3ae0[m_eRequestType];

    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        unsigned char* key = m_pKeyArray + i * m_ucKeyDataSize;
        unsigned char* otherKey = other->m_pKeyArray + i * m_ucKeyDataSize;

        if (!pfnCompare(otherKey, key))
            return false;
    }

    for (unsigned int i = 0; i < m_uiNumKeys2; ++i)
    {
        unsigned char* key = m_pkKeys2 + i * m_ucKeySize2;
        unsigned char* otherKey = other->m_pkKeys2 + i * m_ucKeySize2;

        if (!pfnCompare(otherKey, key))
            return false;
    }

    return true;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
struct AnimationKeyTrack
{
    void* vtable;
    void* controller;
    void* animatedTarget;
    void* nextTrack;
    unsigned int startFrame;
    unsigned int endFrame;
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void FUN_00c2bbd0(void* keys, unsigned int numKeys, int type);
};
// @fnv 0x00c2bbd0
void AnimationKeyTrack::FUN_00c2bbd0(void* keys, unsigned int numKeys, int type)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && numKeys)
    {
        unsigned char size = DAT_011f3758[type + 30];
        m_ucKeyDataSize = size;
        m_pKeyArray = keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_ucKeyDataSize = 0;
    }
}

class NiBinaryStream
{
  public:
    typedef unsigned int (*ReadFn)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_pvVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class NiStream
{
  public:
    unsigned char m_aucData[0x250];
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &value, 1);
}

typedef void(__cdecl* KeyLoadFn)(NiStream& kStream, void* pkKeys, unsigned int uiNumKeys);
extern KeyLoadFn DAT_011f3a50[];
extern KeyLoadFn DAT_011f3ac8[];

class NiObjectStub
{
  public:
    virtual ~NiObjectStub();
    void LoadBinary(NiStream& kStream);
};

class NiPSysEmitterCtlrDataStub : public NiObjectStub
{
  public:
    int m_iRefCount;
    unsigned int m_uiValueAtOffset8;
    void* m_pFloatKeys;
    unsigned int m_iBirthRateKeyIndex;
    unsigned char m_ucFloatKeyType;
    unsigned int m_uiNumFloatKeys;
    void* m_pVisibilityKeys;
    unsigned int m_uiNumVisibilityKeys;

    void SaveBinary(NiStream& kStream);
};

// Loads the emitter controller data from kStream: key count and keys via DAT_011f3a50, then a loop reading values via DAT_011f3ac8.
// @fnv 0x00c2bdf0
void NiPSysEmitterCtlrDataStub::SaveBinary(NiStream& kStream)
{
    NiObjectStub::LoadBinary(kStream);

    ReadBinaryValue(kStream, m_uiValueAtOffset8);
    if (m_uiValueAtOffset8 > 0)
    {
        ReadBinaryValue(kStream, m_iBirthRateKeyIndex);
        DAT_011f3a50[m_iBirthRateKeyIndex](kStream, m_pFloatKeys, m_uiValueAtOffset8);
    }

    ReadBinaryValue(kStream, m_uiNumFloatKeys);
    for (unsigned int ui = 0; ui < m_uiNumFloatKeys; ui++)
    {
        if (m_uiNumFloatKeys > 0)
        {
            ReadBinaryValue(kStream, m_uiNumVisibilityKeys);
            DAT_011f3ac8[m_uiNumVisibilityKeys](kStream, m_pVisibilityKeys, m_uiNumFloatKeys);
        }
    }
}

struct NiBinStreamView
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinStreamView*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinStreamView& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct NiStreamView
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
    unsigned int m_uiFormatVersion;
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
    NiBinStreamView* m_pkIStream;
};

template <class T> inline void ReadBinaryValue(NiStreamView& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pkIStream, &value, 1);
}

template <class T> inline void ReadStreamValue(NiStreamView& kStream, T& value)
{
    unsigned int uiValue;
    ReadBinaryValue(kStream, uiValue);
    value = (T)uiValue;
}

enum KeyType
{
    NOINTERP,
    LINKEY,
    BEZKEY,
    TCBKEY,
    EULERKEY,
    STEPKEY,
    NUMKEYTYPES
};

struct AnimationKey;
struct TimedAnimationKey;

extern void*(__cdecl* DAT_011f3db0[])(NiStreamView&, unsigned int);
extern void(__cdecl* DAT_011f3780[])(void*, unsigned int, unsigned char);
extern unsigned char DAT_011f3758[];
extern void*(__cdecl* DAT_011f3e28[])(NiStreamView&, unsigned int);
extern void(__cdecl* DAT_011f37f8[])(void*, unsigned int, unsigned char);
extern unsigned char DAT_011f3776[];

typedef void*(__cdecl* CreateFunction)(NiStreamView&, unsigned int);
typedef void(__cdecl* FillDerivedValsFunction)(void*, unsigned int, unsigned char);
inline CreateFunction GetCreate1(KeyType e)
{
    return DAT_011f3db0[e];
}
inline FillDerivedValsFunction GetFill1(KeyType e)
{
    return DAT_011f3780[e];
}
inline unsigned char GetKeySize1(KeyType e)
{
    return DAT_011f3758[e];
}
inline CreateFunction GetCreate2(KeyType e)
{
    return DAT_011f3e28[e];
}
inline FillDerivedValsFunction GetFill2(KeyType e)
{
    return DAT_011f37f8[e];
}
inline unsigned char GetKeySize2(KeyType e)
{
    return DAT_011f3776[e];
}
void __stdcall ReadGroup(NiStreamView&);
struct FUN_00c2bc90_shell : FUN_00c2bb70_shell
{
    void FUN_00c2bbd0(void*, unsigned int, int);
    void FUN_00c2bc90(NiStreamView& kStream);
};

// Reads birth rate and emitter active key groups from the stream, creating and filling keys based on the key type and format version.
// @fnv 0x00c2bc90
void FUN_00c2bc90_shell::FUN_00c2bc90(NiStreamView& kStream)
{
    ReadGroup(kStream);

    unsigned int uiNumBirthRateKeys;
    ReadBinaryValue(kStream, uiNumBirthRateKeys);

    if (uiNumBirthRateKeys > 0)
    {
        KeyType eType;
        ReadStreamValue(kStream, eType);
        unsigned char ucSize = GetKeySize1(eType);
        CreateFunction cf = GetCreate1(eType);
        void* pkKeys = cf(kStream, uiNumBirthRateKeys);
        FillDerivedValsFunction pfnFill = GetFill1(eType);
        pfnFill(pkKeys, uiNumBirthRateKeys, ucSize);
        FUN_00c2bb70(pkKeys, uiNumBirthRateKeys, eType);
    }

    unsigned int uiNumEmitterActiveKeys;
    ReadBinaryValue(kStream, uiNumEmitterActiveKeys);

    if (uiNumEmitterActiveKeys > 0)
    {
        KeyType eType = STEPKEY;
        if (kStream.m_uiFormatVersion >= 0x0a010068)
        {
            ReadStreamValue(kStream, eType);
        }
        unsigned char ucSize = GetKeySize2(eType);
        CreateFunction cf = GetCreate2(eType);
        void* pkKeys = cf(kStream, uiNumEmitterActiveKeys);
        FillDerivedValsFunction pfnFill = GetFill2(eType);
        pfnFill(pkKeys, uiNumEmitterActiveKeys, ucSize);
        FUN_00c2bbd0(pkKeys, uiNumEmitterActiveKeys, eType);
    }
}

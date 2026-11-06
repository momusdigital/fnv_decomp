
// src/gamebryo2.2/corelibs/nianimation/nirotdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nirotdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;

extern const NiRTTI g_011f3f50;

// @fnv 0x00a48150
const NiRTTI* __cdecl FUN_00a48150()
{
    return &g_011f3f50;
}

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0
    };
};

class TimedRotationKey;

class NiRotData
{
  public:
    char m_Base[8];
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void FUN_00a48220(TimedRotationKey* pkKeys, unsigned int uiNumKeys, AnimationKey::KeyType eType);
};

extern unsigned char DAT_011f3764[];
extern void(__cdecl* DAT_011f38d0[])(TimedRotationKey*);

// Releases the current key array, then stores the new key pointer, count and interpolation type, or clears them when no keys are given.
// @fnv 0x00a48220
void NiRotData::FUN_00a48220(TimedRotationKey* pkKeys, unsigned int uiNumKeys, AnimationKey::KeyType eInterpType)
{
    if (m_pKeyArray)
        DAT_011f38d0[m_eRequestType](m_pKeyArray);
    if (pkKeys && uiNumKeys)
    {
        m_ucKeyDataSize = DAT_011f3764[eInterpType];
        m_pKeyArray = pkKeys;
        m_uiNumKeys = uiNumKeys;
        m_eRequestType = eInterpType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = AnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_0109844c;
struct MM00a47ba0
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM00a47ba0 g_memoryManager;
struct Struct00a47ba0
{
    int _0;
    void* _4;
    void* FUN_00a47ba0(unsigned int);
};
// @fnv 0x00a47ba0
void* Struct00a47ba0::FUN_00a47ba0(unsigned int auiFlags)
{
    void* p = _4;
    ((void**)this)[0] = (void*)&DAT_0109844c;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

extern int DAT_010984ec;
void __cdecl _delete(void*, unsigned int);
struct NiRefObject
{
    virtual ~NiRefObject();
};
struct StandIn
{
    int _00;
    int _04;
    unsigned int _08;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    int _14;
    void* FUN_00a481e0(unsigned int);
};
// @fnv 0x00a481e0
void* StandIn::FUN_00a481e0(unsigned int auiFlags)
{
    TimedRotationKey* pk = m_pKeyArray;
    *(void**)this = (void*)&DAT_010984ec;
    if (pk)
        DAT_011f38d0[m_eRequestType](pk);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x18);
    return this;
}

namespace fnv_00a49d00 {
struct TimedRotationKey
{
    int a;
    int b;
    int c;
    int d;
    int e;
    unsigned char f;
};

// Reads the rotation key data stored at offset 0x40 of the NiRotData and writes its key, count, key size and key array to the output pointers, or zeros if absent.
// @fnv 0x00a49d00
void __fastcall GetRotKeyData(NiRotData* pThis, int, TimedRotationKey** ppkKeysOut, int* piKeyOut, int* piCountOut,
                              unsigned char* pKeySize)
{
    TimedRotationKey* pkKey = *(TimedRotationKey**)((char*)pThis + 0x40);
    if (pkKey)
    {
        *piKeyOut = pkKey->c;
        *piCountOut = pkKey->e;
        *pKeySize = pkKey->f;
        *ppkKeysOut = (TimedRotationKey*)pkKey->d;
    }
    else
    {
        *piKeyOut = 0;
        *piCountOut = 0;
        *ppkKeysOut = 0;
        *pKeySize = 0;
    }
}
}  // namespace fnv_00a49d00

struct SelfStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(char*);
    void FUN_00b702b0(char*, void*);
    void FUN_00b665d0(char*, void*);
};
// Calls FUN_00b702b0 with the given arguments, then invokes v52 on the same char pointer.
// @fnv 0x00b665d0
void SelfStub::FUN_00b665d0(char* a, void* b)
{
    FUN_00b702b0(a, b);
    v52(a);
}

struct S00b66600
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(int);
};
void __fastcall FUN_00b70290(S00b66600*, int, int);
// Calls FUN_00b70290 with the two int arguments, then invokes the virtual method v52 on the object with the second argument.
// @fnv 0x00b66600
void __fastcall FUN_00b66600(S00b66600* p, int aiFirst, int aiSecond)
{
    FUN_00b70290(p, aiFirst, aiSecond);
    p->v52(aiSecond);
}

struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};
extern void* DAT_011f3b10[];

struct FUN_00a48160_shell
{
    char m_Base[8];
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    bool FUN_00a48160(void* pkObject);
};

// @fnv 0x00a48160
bool FUN_00a48160_shell::FUN_00a48160(void* pkObject)
{
    FUN_00a48160_shell* pkData = (FUN_00a48160_shell*)pkObject;
    if (!((A46BB0Object*)this)->IsEqual((A46BB0Object*)pkObject))
        return false;
    if (m_uiNumKeys != pkData->m_uiNumKeys)
        return false;
    if (m_eRequestType != pkData->m_eRequestType)
        return false;
    if (m_ucKeyDataSize != pkData->m_ucKeyDataSize)
        return false;
    void(__cdecl * pfnEqualFunc)(TimedRotationKey*) = (void(__cdecl*)(TimedRotationKey*))DAT_011f3b10[m_eRequestType];
    for (unsigned int ui = 0; ui < m_uiNumKeys; ++ui)
    {
        unsigned int uiKeyOffset = m_ucKeyDataSize * ui;
        TimedRotationKey* pkB = (TimedRotationKey*)((char*)pkData->m_pKeyArray + uiKeyOffset);
        TimedRotationKey* pkA = (TimedRotationKey*)((char*)m_pKeyArray + uiKeyOffset);
        if (!((bool(__cdecl*)(TimedRotationKey*, TimedRotationKey*))pfnEqualFunc)(pkA, pkB))
            return false;
    }
    return true;
}

struct StrArr
{
    unsigned char _00[8];
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned char _0C[2];
    unsigned short m_uiGrowSize;

    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, char*& rString);
};

struct NiRTTIAccess
{
    void* m_pIntegerData;
};

void* __cdecl _FUN_00a7d330(void* pObject);
char* __cdecl FUN_00a7d510(char const* pName, unsigned int uiValue);
void __stdcall AppendCameraPathEntries(StrArr* apViewerStrings);

struct FUN_00a484c0_shell
{
    void* _00[2];
    unsigned int m_uiNumKeys;

    void AppendNumKeysToStringArray(StrArr* apViewerStrings);
};

// @fnv 0x00a484c0
void FUN_00a484c0_shell::AppendNumKeysToStringArray(StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);

    char* pString =
        static_cast<char*>(_FUN_00a7d330(reinterpret_cast<const NiRTTIAccess*>(&g_011f3f50)->m_pIntegerData));

    unsigned int uiSize = apViewerStrings->m_uiSize;
    if (uiSize >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(uiSize + apViewerStrings->m_uiGrowSize);
    apViewerStrings->SetAt(uiSize, pString);

    pString = FUN_00a7d510("m_uiNumKeys", m_uiNumKeys);

    uiSize = apViewerStrings->m_uiSize;
    if (uiSize >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(uiSize + apViewerStrings->m_uiGrowSize);
    apViewerStrings->SetAt(uiSize, pString);
}

struct FUN_00b66620_cls
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
    int m_d8;
    void FUN_00b66620(int value);
};

// Stores 3 when the incoming value differs from 3, otherwise 0.
// @fnv 0x00b66620
void FUN_00b66620_cls::FUN_00b66620(int value)
{
    m_d8 = (value != 3) ? 3 : 0;
}

class NiStream;

class NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
};

class NiBinaryStream
{
  public:
    void* m_pkVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytesToRead = sizeof(T) * uiNumEls;
    is.BinaryRead(pValue, uiBytesToRead, &uiSize, 1);
}

template <class T> void ReadValueFromBinaryStream(NiBinaryStream& is, T* pValue)
{
    int iDummy;
    unsigned int uiBytesToRead = sizeof(int);
    is.BinaryRead(&iDummy, uiBytesToRead, &uiBytesToRead, 1);
    *pValue = (T)iDummy;
}

struct NiStream
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
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_pUnderlyingStream;

    NiBinaryStream& Istr()
    {
        return *m_pUnderlyingStream;
    }
};

template <class T> void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.Istr(), &value, 1);
}

template <class T> void ReadStreamValue(NiStream& kStream, T& value)
{
    ReadValueFromBinaryStream(kStream.Istr(), &value);
}

extern unsigned char DAT_011f3764[];
typedef TimedRotationKey*(__cdecl* CreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* FillDerivedValsFunction)(TimedRotationKey*, unsigned int, unsigned char);
extern CreateFunction g_apfnCreateKey[];
extern FillDerivedValsFunction g_apfnFillDerived[];

struct FUN_00a48380_cls : public NiObject
{
    unsigned int m_uiRefCount;
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void FUN_00a48380(NiStream& kStream);
};

// Loads the key count and key type from the stream, creates and fills the key array, then stores it via FUN_00a48220.
// @fnv 0x00a48380
void FUN_00a48380_cls::FUN_00a48380(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);

    unsigned int uiNumKeys;
    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        AnimationKey::KeyType eRotType;
        ReadStreamValue(kStream, eRotType);

        m_ucKeyDataSize = DAT_011f3764[eRotType];

        CreateFunction pfnCreateFunc = g_apfnCreateKey[eRotType];
        TimedRotationKey* pkRotKeys = pfnCreateFunc(kStream, uiNumKeys);

        FillDerivedValsFunction pfnFillDerivedFunc = g_apfnFillDerived[eRotType];
        pfnFillDerivedFunc(pkRotKeys, uiNumKeys, m_ucKeyDataSize);

        reinterpret_cast<NiRotData*>(this)->FUN_00a48220(pkRotKeys, uiNumKeys, eRotType);
    }
}

class NiBinaryStream2
{
  public:
    void* m_pkVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int m_uiUnk08;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream2*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> void NiBinaryStreamLoad2(NiBinaryStream2& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytesToRead = sizeof(T) * uiNumEls;
    is.BinaryRead(pValue, uiBytesToRead, &uiSize, 1);
}
struct NiStream2
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
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    NiBinaryStream2* m_pUnderlyingStream;
    NiBinaryStream2& Istr()
    {
        return *m_pUnderlyingStream;
    }
};
template <class T> void NiStreamLoadBinary2(NiStream2& kStream, T& value)
{
    NiBinaryStreamLoad2(kStream.Istr(), &value, 1);
}
typedef void(__cdecl* KeyLinkFunction)(NiStream2&, TimedRotationKey*, unsigned int);
extern KeyLinkFunction DAT_011f3a80[];

class NiObject2
{
  public:
    void* m_pkVtbl;
    unsigned int m_uiRefCount;
    void FUN_00a89af0(NiStream2& kStream);
};

struct RotDataLink_cls : public NiObject2
{
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void SaveBinary(NiStream2& kStream);
};

// Loads the object header, key count, request type, and key array from the stream using the key link function table.
// @fnv 0x00a48440
void RotDataLink_cls::SaveBinary(NiStream2& kStream)
{
    NiObject2::FUN_00a89af0(kStream);
    NiStreamLoadBinary2(kStream, m_uiNumKeys);
    if (m_uiNumKeys > 0)
    {
        NiStreamLoadBinary2(kStream, m_eRequestType);
        DAT_011f3a80[m_eRequestType](kStream, m_pKeyArray, m_uiNumKeys);
    }
}

struct A48280Obj;

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct A48280Obj
{
    virtual void v0();
    virtual void v1();

    long m_RefCount;
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void FUN_00a5d510(A48280Obj** pObject);
    void FUN_00a48220(TimedRotationKey* pkKeys, unsigned int uiNumKeys, AnimationKey::KeyType eType);
    void CopyTo(float fTime, float fDuration, A48280Obj** ppRival);
};

void __cdecl FUN_00a3d630(int a1, int a2, void* a3, unsigned int a4, float a5, float a6, TimedRotationKey** a7,
                          unsigned int* a8);

// Obtains an object, fills its keys using the current key data and time arguments, then assigns it to ppRival with reference counting.
// @fnv 0x00a48280
void A48280Obj::CopyTo(float fTime, float fDuration, A48280Obj** ppRival)
{
    A48280Obj* pNew = 0;

    FUN_00a5d510(&pNew);

    A48280Obj* pCopy = pNew;
    if (pCopy != 0)
        DAT_00fdf1c0(&pCopy->m_RefCount);

    if (m_uiNumKeys > 0)
    {
        TimedRotationKey* pKeys = 0;
        unsigned int uiNumKeys = 0;
        FUN_00a3d630(2, m_eRequestType, m_pKeyArray, m_uiNumKeys, fTime, fDuration, &pKeys, &uiNumKeys);
        pCopy->FUN_00a48220(pKeys, uiNumKeys, (AnimationKey::KeyType)m_eRequestType);
    }

    A48280Obj* pOld = *ppRival;
    int(__stdcall * releaseRef)(void*) = DAT_00fdf1c4;

    if (pOld != pCopy)
    {
        if (pOld != 0)
        {
            if (releaseRef(&pOld->m_RefCount) == 0)
                pOld->v1();
        }

        *ppRival = pCopy;

        if (pCopy != 0)
            DAT_00fdf1c0(&pCopy->m_RefCount);
    }

    if (pCopy != 0)
    {
        if (releaseRef(&pCopy->m_RefCount) == 0)
            pCopy->v1();
    }

    A48280Obj* pDestroy = pNew;
    if (pDestroy != 0)
    {
        if (releaseRef(&pDestroy->m_RefCount) == 0)
            pDestroy->v1();
    }
}


// src/gamebryo2.2/corelibs/nianimation/bslookiknote.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bslookiknote.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_011f3ee8_arg1;

// @fnv 0x00a43f70
char const* const* __cdecl FUN_00a43f70()
{
    return &g_011f3ee8_arg1;
}

extern int g_011f3ee8;

// @fnv 0x00a43f80
int* __cdecl FUN_00a43f80()
{
    return &g_011f3ee8;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);

struct BSLookIKNote
{
    void FUN_00a44830();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00a44830, then if flags has bit 0 set frees this with _delete, and returns this.
// @fnv 0x00a43f90
void* __thiscall BSLookIKNote::Destroy(unsigned int flags)
{
    FUN_00a44830();
    if (flags & 1)
        _delete(this, 0x18);
    return this;
}

namespace fnv_00a43fb0 {
extern int DAT_01097c8c;

struct BSLookIKNote
{
    void* m_vtbl;
    int m_i04;
    int m_i08;
    float m_f0c;
    float m_f10;
    void* m_p14;
    void* operator new(unsigned int size);
    BSLookIKNote();
    void FUN_00a43fa0();
};

// @fnv 0x00a43fb0
BSLookIKNote* __cdecl CreateLookIKNote()
{
    BSLookIKNote* pNote = static_cast<BSLookIKNote*>(BSLookIKNote::operator new(0x18));
    if (pNote)
    {
        pNote->FUN_00a43fa0();
        pNote->m_f0c = 0.0f;
        pNote->m_i08 = 2;
        pNote->m_f10 = 0.0f;
        pNote->m_vtbl = &DAT_01097c8c;
        pNote->m_p14 = 0;
        return pNote;
    }
    return 0;
}
}  // namespace fnv_00a43fb0

namespace fnv_00a43f30 {
struct NiObject;

struct BSLookIKNote
{
    char _pad_0[0x10];
    float m_fDistanceScale;
    int eState;
    bool IsEqual(NiObject* apObject);
};

struct FUN_00a43f30_shell : BSLookIKNote
{
    bool IsLookIKNoteEqual(NiObject* apObject);
};

// Returns true if IsEqual(apObject) passes and the float and eState fields match those of apObject cast to BSLookIKNote.
// @fnv 0x00a43f30
bool FUN_00a43f30_shell::IsLookIKNoteEqual(NiObject* apObject)
{
    if (IsEqual(apObject))
    {
        BSLookIKNote* pkDest = (BSLookIKNote*)apObject;
        if (m_fDistanceScale == pkDest->m_fDistanceScale && eState == pkDest->eState)
            return true;
    }
    return false;
}
}  // namespace fnv_00a43f30

struct S_00a44130_BinStream
{
    int unk0;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnWrite)(S_00a44130_BinStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};

template <class T>
inline unsigned int S_00a44130_BinaryStreamSave(S_00a44130_BinStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline unsigned int S_00a44130_StreamSaveBinary(S_00a44130_BinStream& binstream, const T& value)
{
    return S_00a44130_BinaryStreamSave(binstream, &value, 1);
}

struct S_00a44130_Stream
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00a44130_BinStream* m_pBackingStream;
};

struct S_00a44130_Base
{
    void ReadBinaryFields(S_00a44130_Stream& kStream);
};

struct S_00a44130_Note : S_00a44130_Base
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int m_10;
    int m_14;
    void LoadBinary(S_00a44130_Stream& kStream);
};

// Calls the base save, then writes m_10 and m_14 to the stream as binary values.
// @fnv 0x00a44130
void S_00a44130_Note::LoadBinary(S_00a44130_Stream& kStream)
{
    S_00a44130_Base::ReadBinaryFields(kStream);
    S_00a44130_StreamSaveBinary(*kStream.m_pBackingStream, m_10);
    S_00a44130_StreamSaveBinary(*kStream.m_pBackingStream, m_14);
}

struct S_00a44190_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00a44190_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_00a44190_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00a44190_Stream
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
    S_00a44190_BinStream* m_pBackingStream;
};
template <class T>
inline void S_00a44190_BinSave(S_00a44190_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void S_00a44190_SaveBinary(S_00a44190_Stream& kStream, const T& kValue)
{
    S_00a44190_BinSave(*kStream.m_pBackingStream, &kValue, 1);
}
struct S_00a44190_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00a44a90(S_00a44190_Stream& kStream);
};
struct S_00a44190 : S_00a44190_Base
{
    float unk10;
    float unk14;
    void SaveBinary(S_00a44190_Stream& kStream);
};
// Calls the base class save routine, then serializes the two float members unk10 and unk14 to the stream.
// @fnv 0x00a44190
void S_00a44190::SaveBinary(S_00a44190_Stream& kStream)
{
    S_00a44190_Base::FUN_00a44a90(kStream);
    S_00a44190_SaveBinary(kStream, unk10);
    S_00a44190_SaveBinary(kStream, unk14);
}

class A43FF0Object
{
  public:
    A43FF0Object() throw();
    virtual ~A43FF0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
};

class A43FF0Mid : public A43FF0Object
{
  public:
    A43FF0Mid() throw() : m_eRequestType(2), m_fStartValue(0.0f), m_fEnd(0.0f)
    {}
    virtual ~A43FF0Mid();

    int m_eRequestType;
    float m_fStartValue;
    float m_fEnd;
};

class A43FF0Interp : public A43FF0Mid
{
  public:
    A43FF0Interp() throw() : m_pUserData(0)
    {}
    virtual ~A43FF0Interp();

    void CopyMemberData(A43FF0Interp* pkDest, void* pvCloning);
    A43FF0Interp* CreateClone(void* pvCloning);

    void* m_pUserData;
};

// @fnv 0x00a43ff0
A43FF0Interp* A43FF0Interp::CreateClone(void* pvCloning)
{
    A43FF0Interp* pkClone = new A43FF0Interp;
    CopyMemberData(pkClone, pvCloning);
    pkClone->m_fEnd = m_fEnd;
    pkClone->m_pUserData = m_pUserData;
    return pkClone;
}

extern "C" int __cdecl strncmp(const char* s1, const char* s2, unsigned int n);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int n);

class NiFixedString
{
  public:
    operator const char*() const
    {
        return m_kHandle;
    }
    const char* m_kHandle;
};

class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
};

class TextKeyString
{
  public:
    TextKeyString(const char* pcString) throw();
    ~TextKeyString() throw();
    bool ParseFloatValue(float* pfValue) throw();

    char* m_pcString;
};

class TextKeyHandlerBase
{
  public:
    bool ParseKey(TimedTextEntry* pkKey) throw();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class LookIKKeyHandler : public TextKeyHandlerBase
{
  public:
    bool ParseLookIKKey(TimedTextEntry* pkKey);

    float m_fValue;
    int m_iMode;
};

// Parses a "LookIK" text key: reads a 4-char float value into m_fValue and sets m_iMode to 1 for Start or 2 for Stop.
// @fnv 0x00a44050
bool LookIKKeyHandler::ParseLookIKKey(TimedTextEntry* pkKey)
{
    bool bResult = ParseKey(pkKey);
    const char* pcText = pkKey->m_kText;

    if (strncmp(pcText, "LookIK", 6) == 0)
    {
        pcText += 6;
        if (!bResult || *pcText != ' ')
            return false;
        pcText++;

        char acValue[4];
        strncpy(acValue, pcText, 4);
        {
            TextKeyString kValue(acValue);
            if (!kValue.ParseFloatValue(&m_fValue))
                bResult = false;
            pcText += 4;
        }

        if (bResult && *pcText == ' ')
        {
            pcText++;
            if (strncmp(pcText, "Start", 5) == 0)
                m_iMode = 1;
            if (strncmp(pcText, "Stop", 4) != 0)
                return bResult;
            m_iMode = 2;
            return bResult;
        }
    }
    return bResult;
}

struct S_00a441f0_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, char* const& v);
};

extern const char str_01097d24[];
extern const char str_01044a7c[];
extern const char str_010477f4[];
extern const char str_010639ec[];
extern const char str_0102909c[];
char* __cdecl FUN_00a7d550(const char* fmt, float v);
char* __cdecl FUN_00a7d5e0(const char* fmt, const char* s);

struct S_00a441f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float m_10;
    int m_14;
    void FUN_00a44bf0(S_00a441f0_arg* p);
    void AppendFormattedFields(S_00a441f0_arg* p);
};

inline void S_Push(S_00a441f0_arg* p, char* s)
{
    unsigned int n = p->m_0a;
    if (n >= p->m_08)
    {
        p->FUN_0096ad30(n + p->m_0e);
    }
    p->FUN_0096ae90(n, s);
}

// @fnv 0x00a441f0
void S_00a441f0_cls::AppendFormattedFields(S_00a441f0_arg* p)
{
    FUN_00a44bf0(p);
    S_Push(p, FUN_00a7d550(str_01097d24, m_10));
    switch (m_14)
    {
    case 1:
        S_Push(p, FUN_00a7d5e0(str_01044a7c, str_010477f4));
    case 2:
        S_Push(p, FUN_00a7d5e0(str_01044a7c, str_010639ec));
    default:
        S_Push(p, FUN_00a7d5e0(str_01044a7c, str_0102909c));
    }
}

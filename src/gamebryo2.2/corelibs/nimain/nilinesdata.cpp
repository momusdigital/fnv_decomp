
// src/gamebryo2.2/corelibs/nimain/nilinesdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nilinesdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f5b88;

// @fnv 0x00a8a7b0
void* __cdecl FUN_00a8a7b0()
{
    return &g_011f5b88;
}

void* __cdecl NiFreeAlias(void*);

struct FUN_00a68800_shell
{
    void __thiscall DestroyGeometryData();
};

extern int DAT_0109f23c;

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00a8a7c0_shell : public FUN_00a68800_shell
{
    void* __thiscall FUN_00a8a7c0(unsigned int flags);
};

// @fnv 0x00a8a7c0
void* __thiscall FUN_00a8a7c0_shell::FUN_00a8a7c0(unsigned int flags)
{
    void* pkFlags = *(void**)((char*)this + 0x40);
    *(void**)this = (void*)&DAT_0109f23c;
    NiFreeAlias(pkFlags);
    DestroyGeometryData();
    if (flags & 1)
        operator delete(this, 0x44);
    return this;
}

struct NiLinesDataStandIn
{
    int unk00;
    int unk04;
    unsigned short m_nameLen08;
    unsigned short unk0a;
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
    char* m_pName40;
    bool FUN_00a67840(NiLinesDataStandIn* other);
    bool IsEqual(NiLinesDataStandIn* other);
};

// @fnv 0x00a8a730
bool NiLinesDataStandIn::IsEqual(NiLinesDataStandIn* other)
{
    if (!FUN_00a67840(other))
    {
        return false;
    }
    if (m_pName40 && !other->m_pName40)
    {
        return false;
    }
    if (!m_pName40 && other->m_pName40)
    {
        return false;
    }
    if (m_pName40)
    {
        for (unsigned short i = 0; i < m_nameLen08; ++i)
        {
            if (m_pName40[i] != other->m_pName40[i])
            {
                return false;
            }
        }
    }
    return true;
}

namespace fnv_00a8a850 {
// NiLinesData::SaveBinary  --  the save path of the "lines" data object.
//
// The object keeps a name buffer (m_pName40) and its length (m_nameLen08).
// Saving writes that buffer into the sub-stream that the target object holds
// at +0x250, using the write hook that the sub-stream carries at +0x0c.

struct NiStreamIOStandIn
{
    int unk00;
    int unk04;  // running byte count
    void* unk08;
    int(__cdecl* unk0c)(void* stream, const void* data, unsigned int size, int* out, int type);
};

struct NiStreamStandIn
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
    NiStreamIOStandIn* unk24c;
    NiStreamIOStandIn* unk250;
};

struct NiLinesDataStandIn
{
    int unk00;
    int unk04;
    unsigned short m_nameLen08;
    unsigned short unk0a;
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
    char* m_pName40;
    void FUN_00a68520(NiStreamStandIn& stream);
    void SaveBinary(NiStreamStandIn& stream);
};

// @fnv 0x00a8a850
void NiLinesDataStandIn::SaveBinary(NiStreamStandIn& stream)
{
    this->FUN_00a68520(stream);
    NiStreamIOStandIn* io = stream.unk250;
    char* buf = this->m_pName40;
    unsigned int len = this->m_nameLen08;
    {
        int out = 1;
        int written = io->unk0c(io, buf, len, &out, 1);
        io->unk04 += written;
    }
}
}  // namespace fnv_00a8a850

struct S_00a8a890_Arr
{
    int unk00;
    int unk04;
    unsigned short m_maxSize;
    unsigned short m_iElementCount;
    unsigned short unk0c;
    unsigned short m_growBy;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int i, const char** p);
    void Add(const char* s)
    {
        unsigned int i = m_iElementCount;
        const char* t = s;
        if (i >= m_maxSize)
            FUN_0096ad30(i + m_growBy);
        FUN_0096ae90(i, &t);
    }
};

extern int DAT_011f5b88;
void RegisterFields(S_00a8a890_Arr* arr);
const char* FUN_00a7d330(int g);
const char* FUN_00a7d5a0(const char* fmt, int v);

struct S_00a8a890_Obj
{
    int unk00[16];
    int unk40;
    void RegisterFields(S_00a8a890_Arr* arr);
    void GetViewerStrings(S_00a8a890_Arr* arr);
};

// @fnv 0x00a8a890
void S_00a8a890_Obj::GetViewerStrings(S_00a8a890_Arr* arr)
{
    RegisterFields(arr);
    arr->Add(FUN_00a7d330(DAT_011f5b88));
    arr->Add(FUN_00a7d5a0("m_pkFlags", unk40));
}

class NiBinaryStreamA8A8
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStreamA8A8* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA8A8();

    unsigned int m_uiStreamFlags;
    NIBINARYSTREAM_READFN m_pfnRead;
    void* m_pfnWrite;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiStreamA8A8
{
  public:
    virtual ~NiStreamA8A8();

    unsigned char m_auPad[0x248];
    NiBinaryStreamA8A8* m_pUnderlyingStream;
    NiBinaryStreamA8A8* m_pBackingStream;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA8A8& is, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, uiSize * uiNumEls, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStreamA8A8& kStream, T* pValue, unsigned int uiNumEls)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, pValue, uiNumEls);
}

void* NiMalloc(unsigned int stSize);

class FUN_00a67ea0_helper
{
  public:
    void ReadBinary(NiStreamA8A8& kStream);
};

class GeomDataA8A8 : public FUN_00a67ea0_helper
{
  public:
    int unk00[2];
    unsigned short m_usVertices;
    unsigned short unk0A;
    int unk0C[13];
    unsigned char* m_pucFlags;

    void LoadBinary(NiStreamA8A8& kStream);
};

// Calls ReadBinary, allocates m_pucFlags for m_usVertices bytes, and reads that data from kStream.
// @fnv 0x00a8a800
void GeomDataA8A8::LoadBinary(NiStreamA8A8& kStream)
{
    ReadBinary(kStream);
    m_pucFlags = (unsigned char*)NiMalloc(m_usVertices);
    ReadBinaryValue(kStream, m_pucFlags, m_usVertices);
}

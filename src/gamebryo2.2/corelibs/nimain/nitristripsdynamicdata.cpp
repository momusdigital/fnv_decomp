
// src/gamebryo2.2/corelibs/nimain/nitristripsdynamicdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nitristripsdynamicdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiTriStripsDynamicData
{
    void GetStripData(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                      const unsigned short*& pusTriList, unsigned int& uiStripLengthSum);
};

// @fnv 0x00a923c0
void NiTriStripsDynamicData::GetStripData(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                                          const unsigned short*& pusTriList, unsigned int& uiStripLengthSum)
{
    usStrips = 1;
    pusStripLengths = *(const unsigned short**)((const unsigned char*)this + 0x48);
    pusTriList = *(const unsigned short**)((const unsigned char*)this + 0x4c);
    uiStripLengthSum = *(unsigned short*)((const unsigned char*)this + 0x52) + 2;
}

namespace fnv_00a92430 {
struct NiObject;

struct NiTriStripsData
{
    char m_auiShapeKeys[0x50];
    bool IsEqual(NiTriStripsData* pkData);
};

struct NiTriStripsDynamicData : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    bool IsEqualDynamic(NiObject* pkObject);
};

// Compares this dynamic strips data with pkObject: true if IsEqual and both active vertex and triangle counts match.
// @fnv 0x00a92430
bool NiTriStripsDynamicData::IsEqualDynamic(NiObject* pkObject)
{
    NiTriStripsDynamicData* pkData = (NiTriStripsDynamicData*)pkObject;
    if (IsEqual(pkData))
    {
        if (m_usActiveVertices == pkData->m_usActiveVertices && m_usActiveTriangles == pkData->m_usActiveTriangles)
            return true;
    }
    return false;
}
}  // namespace fnv_00a92430

extern "C" void* g_011f5e8c;

// @fnv 0x00a92470
void* __cdecl FUN_00a92470()
{
    return &g_011f5e8c;
}

struct FUN_00a92480_shell
{
    void __thiscall SetActiveVertexCount(short value);
};

// @fnv 0x00a92480
void __thiscall FUN_00a92480_shell::SetActiveVertexCount(short value)
{
    *(short*)((char*)this + 0x50) = value;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a75e20_shell
{
    void __thiscall FUN_00a75e20();
};

extern int DAT_0109fc54;

// Allocates a 0x54-byte BSFadeNode, runs its constructor, zeroes the two ushort fields at offsets 0x50 and 0x52, sets the vtable, and returns the object or null.
// @fnv 0x00a923f0
void* __cdecl FUN_00a923f0()
{
    void* pNode = BSFadeNode::operator new(0x54);
    if (pNode)
    {
        char* pBytes = (char*)pNode;
        ((FUN_00a75e20_shell*)pBytes)->FUN_00a75e20();
        *(unsigned short*)(pBytes + 0x50) = 0;
        *(int*)pBytes = (int)&DAT_0109fc54;
        *(unsigned short*)(pBytes + 0x52) = 0;
        return pNode;
    }
    return 0;
}

struct FUN_00a92490_shell
{
    void __thiscall SetShortValue(short value);
};

// @fnv 0x00a92490
void __thiscall FUN_00a92490_shell::SetShortValue(short value)
{
    *(short*)((char*)this + 0x52) = value;
    if (*(short*)((char*)this + 0x44))
        *(short*)(*(unsigned int*)((char*)this + 0x48)) = value;
}

struct FUN_00a75dc0
{
    virtual void __thiscall Dummy();
    char _pad[76];
    FUN_00a75dc0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6,
                 unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10, unsigned int a11);
};
struct FUN_00a92340 : FUN_00a75dc0
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    FUN_00a92340(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6,
                 unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10, unsigned int a11,
                 unsigned short a12, unsigned short a13);
};
// Initializes the base class with the given arguments and stores the active vertex and triangle counts.
// @fnv 0x00a92340
FUN_00a92340::FUN_00a92340(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5,
                           unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10,
                           unsigned int a11, unsigned short ausActiveVertices, unsigned short ausActiveTriangles)
    : FUN_00a75dc0(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11), m_usActiveVertices(ausActiveVertices)
{
    m_usActiveTriangles = ausActiveTriangles;
}

struct Standin00a761a0
{
    void FUN_00a76040();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a76040, then frees this with _delete when arg has bit 1 set, and returns this.
// @fnv 0x00a924b0
void* __thiscall Standin00a761a0::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00a76040();
    if (auiFlags & 1)
        _delete(this, 0x54);
    return this;
}

class NiStream;

struct NiBinaryStreamStandIn
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(NiBinaryStreamStandIn* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int componentCount)
    {
        unsigned int bytesRead = read(this, buffer, totalBytes, componentSizes, componentCount);
        absolutePosition += bytesRead;
        return bytesRead;
    }
    template <class T> unsigned int Read(T* value)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(value, sizeof(T), &size, 1);
    }
};

class NiStream
{
  public:
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
    NiBinaryStreamStandIn* istr;
};

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.istr->Read(&value);
}

class NiTriStripsData
{
  public:
    char pad[0x50];
    void LoadBinary(NiStream& stream);
};

struct DynStripsData : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void FUN_00a924d0(NiStream& stream);
};

// Loads the base NiTriStripsData from the stream, then reads the active vertex and triangle counts.
// @fnv 0x00a924d0
void DynStripsData::FUN_00a924d0(NiStream& stream)
{
    NiTriStripsData::LoadBinary(stream);
    ReadBinaryValue(stream, m_usActiveVertices);
    ReadBinaryValue(stream, m_usActiveTriangles);
}

struct A92590RTTI
{
    const char* m_pcName;
    const A92590RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

struct A92590StringArray
{
    virtual ~A92590StringArray();

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);

    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

extern "C" char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d490(const char* pcPrefix, unsigned short usValue);

struct A92590Base
{
    void GetViewerStrings(A92590StringArray* pkStrings);
};

struct A92590TriShapeData : A92590Base
{
    static A92590RTTI ms_kRTTI;

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
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;

    void FUN_00a92590(A92590StringArray* pkStrings);
};

// Appends the RTTI name and the active vertex and triangle counts to the viewer string array.
// @fnv 0x00a92590
void A92590TriShapeData::FUN_00a92590(A92590StringArray* pkStrings)
{
    A92590Base::GetViewerStrings(pkStrings);
    char* pcString = FUN_00a7d330(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
    pcString = FUN_00a7d490("m_usActiveVertices", m_usActiveVertices);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d490("m_usActiveTriangles", m_usActiveTriangles);
    pkStrings->Add(pcString);
}

// Stand-in for the game's stream-buffer record reached through the stream
// pointer at +0x250.  unk04 is a running byte counter, unk0C is the
// writer callback:  cb(buffer, data, numBytes, &count, flag).
struct NiStreamBufferStandin
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* fn0C)(NiStreamBufferStandin*, void*, int, unsigned int*, int);
};

// Stand-in for NiTriStripsDynamicData (the pack's FUN_00a92340): the base
// subobject occupies 0x00-0x4F, the two active counts are the shorts at
// +0x50 and +0x52.  FUN_00a76340 is the base-class save routine (declared
// only, never defined, so the call target comes from the original bytes).
struct NiTriStripsStandin
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
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void __thiscall FUN_00a76340(unsigned int);
    void __thiscall SaveBinary(void*);
};

// @fnv 0x00a92530
void __thiscall NiTriStripsStandin::SaveBinary(void* stream)
{
    this->FUN_00a76340((unsigned int)stream);
    NiStreamBufferStandin* pBuffer = *(NiStreamBufferStandin**)((char*)stream + 0x250);
    int written;
    {
        // The by-value parameter's stack slot is dead here, so MSVC reuses it
        // for this address-taken local - that is where the original's
        // "mov dword ptr [esp+0x24], 2" lands.
        unsigned int count = 2;
        written = pBuffer->fn0C(pBuffer, (void*)&m_usActiveVertices, 2, &count, 1);
        pBuffer->unk04 += written;
    }
    pBuffer = *(NiStreamBufferStandin**)((char*)stream + 0x250);
    {
        unsigned int count = 2;
        written = pBuffer->fn0C(pBuffer, (void*)&m_usActiveTriangles, 2, &count, 1);
        pBuffer->unk04 += written;
    }
}

struct TriStrips_A923B0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    unsigned short GetActiveTriangleCount() const;
};
// @fnv 0x00a923b0
unsigned short TriStrips_A923B0::GetActiveTriangleCount() const
{
    return m_usActiveTriangles;
}

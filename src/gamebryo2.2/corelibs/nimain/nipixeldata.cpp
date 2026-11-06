// gamebryo2.2/corelibs/nimain/nipixeldata.cpp: NiPixelData, NiPixelDataSerialization, NiPixelDataLoad, NiPixelDataEq (13 functions)

#include "nipixeldata_decls.h"

__forceinline bool pixelCompressed(int f)
{
    if (f < 4)
        return false;
    if (f > 6)
        return false;
    return true;
}

// Initializes pixel format, mipmap levels, faces, per-level widths/heights/offsets, allocates data and copies the level tables.
// @fnv 0x00a7c190
NiPixelData::NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format,
                         unsigned int mipmapLevels, unsigned int faces) throw()
{
    m_bOwnsPixelData = false;
    m_kPixelFormat = format;

    if (mipmapLevels == 0)
        m_uiMipmapLevels = CalculateMipmapLevels(width, height);
    else
        m_uiMipmapLevels = mipmapLevels;
    m_uiFaces = faces;

    unsigned int offsets[16];
    unsigned int widths[16];
    unsigned int heights[16];
    offsets[0] = 0;

    if (!pixelCompressed(format.m_eFormat))
    {
        m_uiPixelStride = format.m_ucBitsPerPixel >> 3;
        if (m_uiPixelStride != 0)
        {
            for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
            {
                unsigned int levelWidth = width ? width : 1;
                widths[level] = levelWidth;
                unsigned int levelHeight = height ? height : 1;
                heights[level] = levelHeight;
                offsets[level + 1] = offsets[level] + levelWidth * levelHeight * m_uiPixelStride;
                width >>= 1;
                height >>= 1;
            }
        }
        else
        {
            for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
            {
                unsigned int levelWidth = width ? width : 1;
                widths[level] = levelWidth;
                unsigned int levelHeight = height ? height : 1;
                heights[level] = levelHeight;
                offsets[level + 1] = offsets[level] + ((levelWidth * levelHeight) >> 1);
                width >>= 1;
                height >>= 1;
            }
        }
    }
    else
    {
        m_uiPixelStride = 0;
        unsigned int blockSize = format.m_eFormat == 4 ? 8 : 16;
        for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
        {
            unsigned int levelWidth = width ? width : 1;
            widths[level] = levelWidth;
            unsigned int levelHeight = height ? height : 1;
            heights[level] = levelHeight;
            unsigned int blockWidth = (levelWidth + 3) & ~3u;
            unsigned int blockHeight = (levelHeight + 3) & ~3u;
            offsets[level + 1] = offsets[level] + ((blockWidth * blockHeight) >> 4) * blockSize;
            width >>= 1;
            height >>= 1;
        }
    }

    AllocateData(m_uiMipmapLevels, faces, offsets[m_uiMipmapLevels]);
    unsigned int uiTableBytes = m_uiMipmapLevels * sizeof(unsigned int);
    fnv_zlib_memcpy(m_puiWidth, widths, uiTableBytes);
    fnv_zlib_memcpy(m_puiHeight, heights, uiTableBytes);
    fnv_zlib_memcpy(m_puiOffsetInBytes, offsets, (m_uiMipmapLevels + 1) * sizeof(unsigned int));
    m_uiRevID = 1;
}

class NiMemObject
{
  public:
    static void __cdecl operator delete(void*, unsigned int);
};

void __fastcall ReleaseSpawnedRefs(void*);

// @fnv 0x00a7c450
void* __fastcall FUN_00a7c450(void* pThis, int, unsigned int flags)
{
    ReleaseSpawnedRefs(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x74);
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f4a90;
// @fnv 0x00a7c020
GlobalObjectO2_00a7b610* __cdecl FUN_00a7c020()
{
    return &g_011f4a90;
}

struct FUN_00a7bee0_target
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
    virtual void v21(unsigned int flags);
};

class FUN_00a7bee0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    FUN_00a7bee0_target* m_pFlagTarget;

    bool FUN_00a5d2f0(unsigned int flags);
    bool RegisterStreamables(unsigned int flags);
};

// @fnv 0x00a7bee0
bool FUN_00a7bee0_cls::RegisterStreamables(unsigned int flags)
{
    bool ok = FUN_00a5d2f0(flags);
    if (!ok)
    {
        return ok;
    }
    FUN_00a7bee0_target* target = m_pFlagTarget;
    if (target != 0)
    {
        target->v21(flags);
    }
    return true;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedPixelData : NiObject
{
    NiPixelFormat m_kPixelFormat;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned char unk70;
    unsigned char unk71;
    unsigned char unk72;
    unsigned char unk73;

    SpawnedPixelData()
    {
        unk4c = 0;
        unk50 = 0;
        unk54 = 0;
        unk58 = 0;
        unk5c = 0;
        unk60 = 0;
        unk6c = 0;
        unk64 = 0;
        unk68 = 1;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

// Allocates and constructs a new SpawnedPixelData object, returning it as a void pointer.
// @fnv 0x00a7c3f0
void* __cdecl CreateSpawnedPixelData()
{
    return new SpawnedPixelData();
}

struct NiStreamTransfer
{
    void* unk00;
    unsigned int bytesTransferred;
    void* unk08;
    unsigned int(__cdecl* transfer)(NiStreamTransfer*, const void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void TransferData(const void* bytes, unsigned int count, unsigned int initialCount)
    {
        unsigned int bytesTransferred = initialCount;
        this->bytesTransferred += transfer(this, bytes, count, &bytesTransferred, 1);
    }
};

struct NiStreamSerialization
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void SavePalette(void*) = 0;
};

struct NiObjectSerialization : NiObject
{
    void FUN_00a89af0(NiStreamSerialization*);
};

struct NiPixelFormatSerialization : NiPixelFormat
{
    void FUN_00a7d1a0(NiStreamSerialization*);
};

struct NiPixelDataSerialization : NiPixelData
{
    void SaveToStream(NiStreamSerialization*);
};

static __forceinline void TransferData(NiStreamSerialization* stream, const void* bytes, unsigned int count,
                                       unsigned int initialCount = 4)
{
    NiStreamTransfer* io = *reinterpret_cast<NiStreamTransfer**>(reinterpret_cast<char*>(stream) + 0x250);
    io->TransferData(bytes, count, initialCount);
}

// Serializes the pixel format, palette, mipmap level/stride/width/height/offset arrays, face count and pixel data through the stream.
// @fnv 0x00a7c670
void NiPixelDataSerialization::SaveToStream(NiStreamSerialization* stream)
{
    reinterpret_cast<NiObjectSerialization*>(this)->FUN_00a89af0(stream);
    reinterpret_cast<NiPixelFormatSerialization*>(&m_kPixelFormat)->FUN_00a7d1a0(stream);
    stream->SavePalette(m_spPalette.value);

    TransferData(stream, &m_uiMipmapLevels, sizeof(m_uiMipmapLevels));
    TransferData(stream, &m_uiPixelStride, sizeof(m_uiPixelStride));

    for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
    {
        TransferData(stream, &m_puiWidth[level], sizeof(unsigned int));
        TransferData(stream, &m_puiHeight[level], sizeof(unsigned int));
        TransferData(stream, &m_puiOffsetInBytes[level], sizeof(unsigned int));
    }

    TransferData(stream, &m_puiOffsetInBytes[m_uiMipmapLevels], sizeof(unsigned int));
    TransferData(stream, &m_uiFaces, sizeof(m_uiFaces));
    const void* pixels = m_pucPixels;
    unsigned int pixelBytes = m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces;
    TransferData(stream, pixels, pixelBytes, 1);
}

struct NiBinaryStreamLoad
{
    void* unk00;
    unsigned int bytesTransferred;
    unsigned int(__cdecl* transfer)(NiBinaryStreamLoad*, void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void Read(void* bytes, unsigned int count, unsigned int initialCount)
    {
        unsigned int done = initialCount;
        unsigned int transferred = transfer(this, bytes, count, &done, 1);
        bytesTransferred += transferred;
    }
};

struct NiStreamLoad
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
    unsigned int m_uiNifVersion;
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
    NiBinaryStreamLoad* m_pUnderlyingStream;

    void ReadLinkIDStub();
    __forceinline void Read(void* bytes, unsigned int count, unsigned int initialCount)
    {
        m_pUnderlyingStream->Read(bytes, count, initialCount);
    }
};

template <class T> static __forceinline void ReadBinaryValue(NiStreamLoad& stream, T& value)
{
    stream.Read(&value, sizeof(T), sizeof(T));
}

struct NiObjectLoad : NiObject
{
    void LoadBinaryBase(NiStreamLoad& stream);
};

struct NiPixelFormatLoad : NiPixelFormat
{
    void LoadBinaryFormat(NiStreamLoad& stream);
};

struct NiPixelDataLoad : NiPixelData
{
    void LoadBinary(NiStreamLoad& stream);
};

// Loads pixel format, mipmap levels, per-mipmap width/height/offset, faces and pixel data from the stream, then allocates and copies them.
// @fnv 0x00a7c470
void NiPixelDataLoad::LoadBinary(NiStreamLoad& stream)
{
    ((NiObjectLoad*)this)->LoadBinaryBase(stream);
    ((NiPixelFormatLoad*)&m_kPixelFormat)->LoadBinaryFormat(stream);
    stream.ReadLinkIDStub();

    unsigned int auiOffsetInBytes[16];
    unsigned int auiWidth[16];
    unsigned int auiHeight[16];

    ReadBinaryValue(stream, m_uiMipmapLevels);
    ReadBinaryValue(stream, m_uiPixelStride);
    unsigned int i;
    for (i = 0; i < m_uiMipmapLevels; i++)
    {
        ReadBinaryValue(stream, auiWidth[i]);
        ReadBinaryValue(stream, auiHeight[i]);
        ReadBinaryValue(stream, auiOffsetInBytes[i]);
    }
    ReadBinaryValue(stream, *(auiOffsetInBytes + m_uiMipmapLevels));

    if (stream.m_uiNifVersion < 0x0A030006)
        m_uiFaces = 1;
    else
        ReadBinaryValue(stream, m_uiFaces);

    AllocateData(m_uiMipmapLevels, m_uiFaces, auiOffsetInBytes[m_uiMipmapLevels]);

    unsigned int uiMipmapArrayBytes = m_uiMipmapLevels * sizeof(unsigned int);
    fnv_zlib_memcpy(m_puiWidth, auiWidth, uiMipmapArrayBytes);
    fnv_zlib_memcpy(m_puiHeight, auiHeight, uiMipmapArrayBytes);
    fnv_zlib_memcpy(m_puiOffsetInBytes, auiOffsetInBytes, (m_uiMipmapLevels + 1) * sizeof(unsigned int));

    unsigned char* pixels = m_pucPixels;
    stream.Read(pixels, m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces, 1);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4a90;
char* __cdecl FUN_00a7d330(char* pcText);
char* __cdecl FUN_00a7d510(const char* pcName, unsigned int uiValue);
struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};
struct Base00a5d6e0
{
    void AppendCameraPathEntries(StrArr* pkStrings);
};
inline unsigned int PixelFaceSize(const NiPixelData* p)
{
    return p->m_puiOffsetInBytes[p->m_uiMipmapLevels];
}
inline unsigned int PixelTotalSize(const NiPixelData* p)
{
    return p->m_puiOffsetInBytes[p->m_uiMipmapLevels] * p->m_uiFaces;
}
struct PixelView : NiPixelData
{
    unsigned int GetWidth(unsigned int uiMipmapLevel = 0, unsigned int uiFace = 0) const
    {
        return m_puiWidth[uiMipmapLevel];
    }
    unsigned int GetHeight(unsigned int uiMipmapLevel = 0, unsigned int uiFace = 0) const
    {
        return m_puiHeight[uiMipmapLevel];
    }
};
struct FUN_00a7c820_shell : NiPixelData
{
    void AppendPixelDataDebugStrings(StrArr* pkStrings);
};
// Appends the base debug strings plus Width, Height, mipmap level, face count, total and per-face byte sizes to pkStrings.
// @fnv 0x00a7c820
void FUN_00a7c820_shell::AppendPixelDataDebugStrings(StrArr* pkStrings)
{
    ((Base00a5d6e0*)this)->AppendCameraPathEntries(pkStrings);
    const PixelView* pkThis = (const PixelView*)this;
    char* pcString = FUN_00a7d330(*(char**)&g_011f4a90);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("Width", pkThis->GetWidth());
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("Height", pkThis->GetHeight());
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("m_uiMipmapLevels", m_uiMipmapLevels);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("m_uiFaces", m_uiFaces);
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("TotalSizeInBytes", PixelTotalSize(this));
    pkStrings->Add(pcString);
    pcString = FUN_00a7d510("FaceSizeInBytes", PixelFaceSize(this));
    pkStrings->Add(pcString);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct NiStream
{
    NiObject* FUN_00a63430();
};
struct RendererDataBase_s
{
    void LinkObject(NiStream& kStream);
};
inline void DecRefCount(NiObject* pkObject)
{
    if (InterlockedDecrement((long volatile*)&pkObject->m_uiRefCount) == 0)
        pkObject->DeleteThis();
}
template <class T> class NiPointerBE80
{
  public:
    NiPointerBE80& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                DecRefCount(m_pObject);
            m_pObject = pObject;
            if (m_pObject)
                InterlockedIncrement((long volatile*)&m_pObject->m_uiRefCount);
        }
        return *this;
    }
    T* m_pObject;
};
struct PixelDataBE80 : public RendererDataBase_s
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
    NiPointerBE80<NiObject> m_spPalette;
    void FUN_00a7be80(NiStream& kStream);
};

// Calls the base LinkObject on kStream, then loads m_spPalette from the stream via FUN_00a63430.
// @fnv 0x00a7be80
void PixelDataBE80::FUN_00a7be80(NiStream& kStream)
{
    RendererDataBase_s::LinkObject(kStream);
    m_spPalette = kStream.FUN_00a63430();
}

struct SpawnedRef
{
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

extern int DAT_0109dbb4;

struct FUN_00a7c390_cls
{
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    SpawnedRef* m_4c;

    void BaseCleanup();
    void BaseTeardown();
    void ReleaseSpawnedRefs();
};

// Decrements m_4c's reference count before and after BaseCleanup, deleting either object at zero, then calls BaseTeardown.
// @fnv 0x00a7c390
void FUN_00a7c390_cls::ReleaseSpawnedRefs()
{
    *(void* volatile*)&m_vptr = (void*)&DAT_0109dbb4;
    SpawnedRef* first = *(SpawnedRef* volatile*)&m_4c;
    if (first != 0)
    {
        if (InterlockedDecrement(&first->m_iObjectReferenceCount) == 0)
        {
            first->DeleteThis();
        }
        m_4c = 0;
    }
    BaseCleanup();
    SpawnedRef* second = m_4c;
    if (second != 0)
    {
        if (InterlockedDecrement(&second->m_iObjectReferenceCount) == 0)
        {
            second->DeleteThis();
        }
    }
    BaseTeardown();
}

static inline unsigned int Levels(unsigned int v)
{
    unsigned int l = 1;
    while (v >>= 1)
        ++l;
    return l;
}
// Returns the number of mip levels for a texture of the given width and height, or 0 if either dimension is zero.
// @fnv 0x00a7be30
unsigned int GetMipLevelCount(unsigned int width, unsigned int height)
{
    if (!width || !height)
        return 0;
    unsigned int iWidthLevels = 1;
    while (width >>= 1)
        ++iWidthLevels;
    unsigned int iHeightLevels = Levels(height);
    unsigned int r = iWidthLevels;
    if (iHeightLevels >= iWidthLevels)
        r = iHeightLevels;
    return r;
}

#include <string.h>
struct NiPaletteStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual bool IsEqual(void* pkObject);
};

struct NiPixelFormatCmp
{
    bool operator!=(const NiPixelFormatCmp& rhs) const;
};

class NiPixelDataEq : public NiPixelData
{
  public:
    bool ObjectIsEqual(NiObject* pkObject);
    bool FUN_00a7bf10(NiObject* pkObject);
};

// Compares pixel format, palette, mipmap dimensions, face count, and pixel data of two NiPixelData objects, returning true only if all match.
// @fnv 0x00a7bf10
bool NiPixelDataEq::FUN_00a7bf10(NiObject* pkObject)
{
    if (!ObjectIsEqual(pkObject))
        return false;

    NiPixelData* pkPD = (NiPixelData*)pkObject;

    if ((const NiPixelFormatCmp&)m_kPixelFormat != (const NiPixelFormatCmp&)pkPD->m_kPixelFormat)
        return false;

    NiPaletteStub* pkPalette = (NiPaletteStub*)m_spPalette.value;
    if (pkPalette)
    {
        void* pkOther = pkPD->m_spPalette.value;
        if (!pkPalette->IsEqual(pkOther))
            return false;
    }

    if (m_uiMipmapLevels != pkPD->m_uiMipmapLevels || m_uiPixelStride != pkPD->m_uiPixelStride)
        return false;

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        if (m_puiWidth[i] != pkPD->m_puiWidth[i] || m_puiHeight[i] != pkPD->m_puiHeight[i] ||
            m_puiOffsetInBytes[i] != pkPD->m_puiOffsetInBytes[i])
            return false;
    }

    if (m_puiOffsetInBytes[m_uiMipmapLevels] != pkPD->m_puiOffsetInBytes[m_uiMipmapLevels])
        return false;

    if (m_uiFaces != pkPD->m_uiFaces)
        return false;

    if (memcmp(m_pucPixels, pkPD->m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels]) != 0)
        return false;

    return true;
}

#include <windows.h>
class NiPalette : public NiObject
{
  public:
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    NiPalette(const NiPalette& src) throw();
    static void* __cdecl operator new(unsigned int size);
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiPalettePtr
{
  public:
    NiPalette* m_pObject;
    NiPalettePtr() throw() : m_pObject(0)
    {}
    NiPalette* operator->() const
    {
        return m_pObject;
    }
    NiPalette& operator*() const
    {
        return *m_pObject;
    }
    operator NiPalette*() const
    {
        return m_pObject;
    }
    NiPalettePtr& operator=(NiPalette* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class FUN_00a7c030 : public NiObject
{
  public:
    NiPixelFormat m_kPixelFormat;
    NiPalettePtr m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
    unsigned int m_uiFaces;
    bool m_bNoConvert;

    FUN_00a7c030(const FUN_00a7c030& kSrc) throw();
    virtual ~FUN_00a7c030();
    void AllocateData(unsigned int uiLevels, unsigned int uiFaces, unsigned int uiBytes);
};

// @fnv 0x00a7c030
FUN_00a7c030::FUN_00a7c030(const FUN_00a7c030& kSrc) throw()
{
    m_bNoConvert = false;
    m_kPixelFormat = kSrc.m_kPixelFormat;
    if (kSrc.m_spPalette)
        m_spPalette = new NiPalette(*kSrc.m_spPalette);

    m_uiMipmapLevels = kSrc.m_uiMipmapLevels;
    m_uiFaces = kSrc.m_uiFaces;
    m_uiPixelStride = kSrc.m_uiPixelStride;

    unsigned int auiWidth[16];
    unsigned int auiHeight[16];
    unsigned int auiOffsetInBytes[16];

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        auiWidth[i] = kSrc.m_puiWidth[i];
        auiHeight[i] = kSrc.m_puiHeight[i];
        auiOffsetInBytes[i] = kSrc.m_puiOffsetInBytes[i];
    }
    unsigned int uiTotalBytes = kSrc.m_puiOffsetInBytes[m_uiMipmapLevels];
    auiOffsetInBytes[m_uiMipmapLevels] = uiTotalBytes;

    AllocateData(m_uiMipmapLevels, m_uiFaces, uiTotalBytes);

    unsigned int uiDimBytes = sizeof(unsigned int) * m_uiMipmapLevels;
    memcpy(m_puiWidth, auiWidth, uiDimBytes);
    memcpy(m_puiHeight, auiHeight, uiDimBytes);
    memcpy(m_puiOffsetInBytes, auiOffsetInBytes, sizeof(unsigned int) * (m_uiMipmapLevels + 1));
    memcpy(m_pucPixels, kSrc.m_pucPixels, uiTotalBytes);
    m_uiRevID = 1;
}

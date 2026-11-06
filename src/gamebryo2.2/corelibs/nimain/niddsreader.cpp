// gamebryo2.2/corelibs/nimain/niddsreader.cpp: NiDDSReader, DDSReader, NiBMPReader, ClsReader and more (23 functions)

#include "niddsreader_decls.h"
// Initializes the NiBMPReader fields: zeroes height, width, unknown, x, y, sets format to DAT_011aa2e8 and clears b1 and b2.
// @fnv 0x00a8e410
NiBMPReader::NiBMPReader()
{
    height = 0;
    width = 0;
    format = DAT_011aa2e8;
    unknown = 0;
    x = 0;
    y = 0;
    b1 = false;
    b2 = false;
}

// For each of the count at thisPtr+0x10e, copies one source byte into three consecutive destination bytes.
// @fnv 0x00a8d4e0
void __fastcall ExpandGrayToRgb(void* thisPtr, int, unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < *(unsigned short*)((char*)thisPtr + 0x10e); ++i)
    {
        dst[0] = dst[1] = dst[2] = *src;
        dst += 3;
        src += 1;
    }
}

// Converts a count of 16-bit RGB565 pixels from pucSrc into 24-bit RGB888 bytes written to pucDest.
// @fnv 0x00a8d520
void __fastcall ConvertRgb565ToRgb888(char* pThis, int, unsigned char* pucSrc, unsigned char* pucDest)
{
    for (unsigned int i = 0; i < *(unsigned short*)(pThis + 0x10e); i++)
    {
        *(pucDest++) = (pucSrc[1] & 0x7c) << 1;
        *(pucDest++) = ((pucSrc[1] & 0x03) << 6) + ((pucSrc[0] & 0xe0) >> 2);
        *(pucDest++) = (pucSrc[0] & 0x1f) << 3;
        pucSrc += 2;
    }
}

// @fnv 0x00a8d590
void __fastcall FUN_00a8d590(char* this_ptr, int, unsigned char* pSrcIndices, unsigned char* pDst)
{
    for (unsigned int i = 0; i < *(unsigned short*)(this_ptr + 0x10e); i++)
    {
        unsigned int uiPaletteIndex =
            ((unsigned int)pSrcIndices[1] << 8) - *(unsigned short*)(this_ptr + 0x104) + pSrcIndices[0];
        unsigned char* pPaletteEntry = *(unsigned char**)(this_ptr + 0x16c) + uiPaletteIndex * 4;
        *pDst++ = pPaletteEntry[0];
        *pDst++ = pPaletteEntry[1];
        *pDst++ = pPaletteEntry[2];
        pSrcIndices += 2;
    }
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8c0e0
bool __stdcall CanReadFile(const char* extension)
{
    if (NiStricmp(extension, ".dds") != 0)
        return false;
    return true;
}

// @fnv 0x00a8c100
bool __stdcall IsValidBitDepth(int a, int b, int c, int d, unsigned int bits)
{
    if (bits == 16 || bits == 24 || bits == 32)
        return true;
    return false;
}

extern const NiPixelFormat gNiPoint3StartupSrc;
struct NiPixelFormatMaskView : NiPixelFormat
{
    unsigned int GetMask(int) const;
};
// Returns a canonical NiPixelFormat for 16-, 24- and 32-bit formats, otherwise returns fmt unchanged.
// @fnv 0x00a8c120
NiPixelFormat __stdcall NormalizePixelFormat(NiPixelFormat aFormat)
{
    switch (aFormat.bits)
    {
    case 16:
        if (static_cast<NiPixelFormatMaskView&>(aFormat).GetMask(3) != 0)
            return gNiPoint3StartupSrc;
        return DAT_011aa2e8;
    case 24:
        return DAT_011aa2e8;
    case 32:
        return gNiPoint3StartupSrc;
    }
    return aFormat;
}

extern NiPixelFormat DAT_011aa498;
struct FUN_00a8c190 : NiImageReader
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    NiPixelFormat m_kPixelFormat;
    FUN_00a8c190();
    virtual void vfn_x();
};
// @fnv 0x00a8c190
FUN_00a8c190::FUN_00a8c190()
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_kPixelFormat = DAT_011aa498;
}

// For each of the count at self+0x10e, reads a byte from src, subtracts the byte at self+0x104, and writes the result to dst.
// @fnv 0x00a8d4a0
void __fastcall FUN_00a8d4a0(char* self, int edx, const unsigned char* src, unsigned char* dst)
{
    unsigned int i;
    for (i = 0; i < *(unsigned short*)(self + 0x10e); i++)
    {
        unsigned char v = *src++;
        *dst++ = v - *(unsigned char*)(self + 0x104);
    }
}

// @fnv 0x00a8d600
void __fastcall FUN_00a8d600(char* self, int edx, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < *(unsigned short*)(self + 0x10e); ++i)
    {
        unsigned int idx = (src[1] << 8) - *(unsigned short*)(self + 0x104) + src[0];
        const unsigned char* pEntry = *(unsigned char**)(self + 0x16c) + idx * 4;
        *dst++ = pEntry[0];
        *dst++ = pEntry[1];
        *dst++ = pEntry[2];
        *dst++ = pEntry[3];
        src += 2;
    }
}

struct FUN_00a8d670_obj
{
    char pad[0x10e];
    unsigned short width;
};
// @fnv 0x00a8d670
void __fastcall FUN_00a8d670(FUN_00a8d670_obj* self, int unused, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < self->width; i++)
    {
        *dst++ = src[2];
        *dst++ = src[1];
        *dst++ = src[0];
        src += 3;
    }
}

struct FUN_00a8d6c0_obj
{
    char pad[0x10e];
    unsigned short width;
};
// @fnv 0x00a8d6c0
void __fastcall FUN_00a8d6c0(FUN_00a8d6c0_obj* self, int unused, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < self->width; i++)
    {
        *dst++ = src[2];
        *dst++ = src[1];
        *dst++ = src[0];
        *dst++ = src[3];
        src += 4;
    }
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8d710
bool __stdcall IsTgaExtension(const char* ext)
{
    if (NiStricmp(ext, ".tga") == 0 || NiStricmp(ext, ".targa") == 0)
        return true;
    return false;
}

struct FUN_00a8d750 : NiImageReader
{
    unsigned char b100, b101, b102;
    unsigned char pad103;
    unsigned short w104, w106;
    unsigned char b108;
    unsigned char pad109;
    unsigned short w10a, w10c, w10e, w110;
    unsigned char b112, b113, b114, b115, b116, b117, b118;
    unsigned char pad119[3];
    NiPixelFormat m_eFormat;
    unsigned int d160, d164, d168, d16c, d170, d174;
    unsigned char b178, b179, b17a, b17b, b17c;
    FUN_00a8d750();
    virtual void vfn_x();
};
// @fnv 0x00a8d750
FUN_00a8d750::FUN_00a8d750()
{
    b100 = 0;
    b101 = 0;
    b102 = 0;
    w104 = 0;
    w106 = 0;
    b108 = 0;
    w10a = 0;
    w10c = 0;
    w10e = 0;
    w110 = 0;
    b112 = 0;
    b113 = 0;
    b114 = 0;
    b115 = 0;
    b116 = 0;
    b117 = 0;
    b118 = 0;
    m_eFormat = DAT_011aa2e8;
    d160 = 0;
    d164 = 0;
    d168 = 0;
    d16c = 0;
    d170 = 0;
    d174 = 0;
    b178 = 0;
    b179 = 0;
    b17a = 0;
    b17b = 0;
    b17c = 0;
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8e3f0
bool __stdcall IsNotBmpExtension(const char* extension)
{
    if (NiStricmp(extension, ".bmp") != 0)
        return false;
    return true;
}

extern int DAT_0109f4b0;
extern int DAT_0109f3d0;
extern void(__stdcall* DAT_00fdf058)(void*);

void __cdecl FUN_00aa10f0(void* apMemory);

class FUN_00a8d850_pool
{
  public:
    void FUN_00aa4060(void* apMemory);
};
extern FUN_00a8d850_pool DAT_011f6238;

struct FUN_00a8d850_cls : NiImageReader
{
    unsigned int unk100, unk104, unk108, unk10c;
    unsigned int unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c;
    unsigned int unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c;
    unsigned int unk160;
    void* m_p164;
    unsigned int unk168;
    void* m_p16c;

    FUN_00a8d850_cls* DestroyImageReader(unsigned char acFlags);
};

// @fnv 0x00a8d850
FUN_00a8d850_cls* FUN_00a8d850_cls::DestroyImageReader(unsigned char acFlags)
{
    void* pFirst = m_p164;
    *(int*)this = (int)&DAT_0109f4b0;
    FUN_00aa10f0(pFirst);
    void* pSecond = m_p16c;
    DAT_011f6238.FUN_00aa4060(pSecond);
    *(int*)this = (int)&DAT_0109f3d0;
    DAT_00fdf058(lock);
    if (acFlags & 1)
    {
        DAT_011f6238.FUN_00aa4060(this);
    }
    return this;
}

struct ClsStream
{
    int s00;
    int m_pos;
    int(__cdecl* m_read)(ClsStream*, unsigned char*, int, int*, int);
};
struct ClsSub
{
    ClsSub* FUN_00a8b110(int b, int w, int d);
};
struct ClsImage
{
    int i00;
    int i04;
    NiPixelFormat m_fmt;
    int i4c;
    int m_50;
    unsigned int* m_p54;
    unsigned int* m_p58;
    unsigned int* m_p5c;
    int i60;
    int m_64;
    ClsImage* FUN_00a7c190(int w, int h, NiPixelFormat* fmt, int a, int b);
    void FUN_00a76a60(ClsSub* sub);
};
extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern void __cdecl FUN_00aa10f0(void* p);
extern void* __cdecl FUN_00aa1070(unsigned int size);
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

struct ClsReader : NiImageReader
{
    unsigned char b100;
    unsigned char b101;
    unsigned char b102;
    unsigned char f103;
    unsigned short w104;
    unsigned short w106;
    unsigned char b108;
    unsigned char f109;
    unsigned short w10a;
    unsigned short w10c;
    unsigned short w10e;
    unsigned short w110;
    unsigned char b112;
    unsigned char b113;
    unsigned char b114;
    unsigned char b115;
    unsigned char b116;
    unsigned char b117;
    unsigned char b118;
    unsigned char f119;
    unsigned char f11a;
    unsigned char f11b;
    NiPixelFormat m_eFormat;
    unsigned int m_pRayCursor;
    unsigned char* m_buffer;
    int d168;
    int d16c;
    void (ClsReader::*m_fn170)(unsigned char*, int);
    int d174;
    virtual void Slot1();
    virtual void Slot2();
    virtual bool Slot3(ClsStream* stream, int* o3, int* o2, NiPixelFormat* fmt, unsigned char* byteOut, int* o1);
    void ReadPixels(ClsStream* stream);
    void Decode(ClsStream* stream, unsigned char* buf, int cap);
    ClsImage* ReadImage(ClsStream* stream, ClsImage* image);
};

// Reads pixel data from the stream into an image, allocating or reusing the image and buffer, then writes each row via m_fn170.
// @fnv 0x00a8e120
ClsImage* ClsReader::ReadImage(ClsStream* stream, ClsImage* image)
{
    NiPixelFormat fmt;
    void* lockPtr = lock;
    DAT_00fdf05c(lockPtr);
    int out1;
    int out2;
    int out3;
    unsigned char byteOut;
    if (!Slot3(stream, &out3, &out2, &fmt, &byteOut, &out1))
    {
        DAT_00fdf100(lockPtr);
        return 0;
    }
    int count = (int)(unsigned char)b114 * (int)(unsigned short)w10e;
    if (b114 == 0)
    {
        if (b112 != 4)
        {
            DAT_00fdf100(lockPtr);
            return 0;
        }
        count = (int)(unsigned short)w10e >> 1;
    }
    if (b101 != 0)
    {
        if ((unsigned int)((int)(unsigned short)w106 + (int)(unsigned short)w104 + 1) >= 0x4000)
        {
            DAT_00fdf100(lockPtr);
            return 0;
        }
        ReadPixels(stream);
    }
    else if (b116 != 0)
    {
        DAT_00fdf100(lockPtr);
        return 0;
    }
    ClsImage* result;
    if (image != 0 && *image->m_p54 == (unsigned int)(unsigned short)w10e &&
        *image->m_p58 == (unsigned int)(unsigned short)w110 && image->m_fmt == m_eFormat)
    {
        result = image;
    }
    else
    {
        void* pImageMem = FUN_00aa13e0(0x74);
        if (pImageMem != 0)
        {
            result = ((ClsImage*)pImageMem)
                         ->FUN_00a7c190((int)(unsigned short)w10e, (int)(unsigned short)w110, &m_eFormat, 1, 1);
        }
        else
        {
            result = 0;
        }
        image = result;
    }
    if (b116 != 0)
    {
        void* pSubMem = FUN_00aa13e0(0x24);
        ClsSub* sub;
        if (pSubMem != 0)
        {
            sub = ((ClsSub*)pSubMem)->FUN_00a8b110((int)(unsigned char)b115, (int)(unsigned short)w106, d16c);
        }
        else
        {
            sub = 0;
        }
        image->FUN_00a76a60(sub);
    }
    if (m_pRayCursor < (unsigned int)count)
    {
        m_pRayCursor = count;
        FUN_00aa10f0(m_buffer);
        m_buffer = (unsigned char*)FUN_00aa1070(m_pRayCursor);
    }
    int iOffset = (int)*image->m_p5c + image->m_50;
    int step = image->m_64 * (int)*image->m_p54;
    if (step == 0)
    {
        step = (int)(*image->m_p54 >> 1);
    }
    if (b117 != 0)
    {
        iOffset += ((int)(unsigned short)w110 - 1) * step;
        step = -step;
    }
    int flag;
    if (b118 != 0)
    {
        for (unsigned int i = 0; i < (unsigned int)(unsigned short)w110; ++i)
        {
            Decode(stream, m_buffer, m_pRayCursor);
            (this->*m_fn170)(m_buffer, iOffset);
            iOffset += step;
        }
    }
    else
    {
        for (unsigned int i = 0; i < (unsigned int)(unsigned short)w110; ++i)
        {
            unsigned char* rowBuffer = m_buffer;
            flag = 1;
            stream->m_pos += stream->m_read(stream, rowBuffer, count, &flag, 1);
            (this->*m_fn170)(m_buffer, iOffset);
            iOffset += step;
        }
    }
    DAT_00fdf100(lockPtr);
    return result;
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;

class NiBinaryStream
{
  public:
    virtual ~NiBinaryStream();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void SetEndianSwap(bool bDoSwap);
    virtual void Seek(int iNumBytes, int iWhence);

    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (*m_pfnWrite)(NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return kStream.BinaryRead(pkValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

inline void ReadBinaryValue(NiBinaryStream& kStream, unsigned int& uiValue)
{
    NiBinaryStreamLoad(kStream, &uiValue, 1);
}

void __cdecl FUN_00a575b0(NiBinaryStream& kStream, unsigned int& uiValue);
NiPixelFormat __cdecl CreateFromMasks(unsigned int uiBitsPerPixel, unsigned int uiRedMask, unsigned int uiGreenMask,
                                      unsigned int uiBlueMask, unsigned int uiAlphaMask);

inline void NiSwap32(char* pcValue)
{
    char cTemp = pcValue[0];
    pcValue[0] = pcValue[3];
    pcValue[3] = cTemp;
    cTemp = pcValue[1];
    pcValue[1] = pcValue[2];
    pcValue[2] = cTemp;
}

extern NiPixelFormat DAT_011aa498;
extern NiPixelFormat DAT_011aa4e0;
extern NiPixelFormat DAT_011aa528;
extern NiPixelFormat DAT_011aa570;
extern NiPixelFormat DAT_011aa5b8;
extern NiPixelFormat DAT_011aa600;
extern NiPixelFormat DAT_011aa648;
extern NiPixelFormat DAT_011aa690;
extern NiPixelFormat DAT_011aa6d8;

class NiDDSReader : public NiImageReader
{
  public:
    unsigned int m_uiImageHeight;
    unsigned int m_uiImageWidth;
    unsigned int m_uiMipMapLevels;
    bool m_bCubeMap;
    NiPixelFormat m_eFormat;

    void Lock()
    {
        DAT_00fdf05c(lock);
    }
    void Unlock()
    {
        DAT_00fdf100(lock);
    }

    __declspec(noinline) bool IsValidBitDepth(unsigned int uiRedMask, unsigned int uiGreenMask, unsigned int uiBlueMask,
                                              unsigned int uiAlphaMask, unsigned int uiBitsPerPixel);
    NiPixelFormat NormalizePixelFormat(NiPixelFormat kFormat);
    bool FUN_00a8c1e0(NiBinaryStream& kIst, unsigned int& uiWidth, unsigned int& uiHeight, NiPixelFormat& kFormat,
                      bool& bMipmap, unsigned int& uiFaces);
};

__declspec(noinline) bool NiDDSReader::IsValidBitDepth(unsigned int uiRedMask, unsigned int uiGreenMask,
                                                       unsigned int uiBlueMask, unsigned int uiAlphaMask,
                                                       unsigned int uiBitsPerPixel)
{
    return uiBitsPerPixel == 16 || uiBitsPerPixel == 24 || uiBitsPerPixel == 32;
}

// Parses a DDS header from kIst, validating magic, size, and pixel format, then sets uiWidth, uiHeight, kFormat, bMipmap, and uiFaces.
// @fnv 0x00a8c1e0
bool NiDDSReader::FUN_00a8c1e0(NiBinaryStream& kIst, unsigned int& uiWidth, unsigned int& uiHeight,
                               NiPixelFormat& kFormat, bool& bMipmap, unsigned int& uiFaces)
{
    Lock();

    unsigned int uiMagic;
    ReadBinaryValue(kIst, uiMagic);
    if (uiMagic != 0x20534444)
    {
        unsigned int uiSwapped = uiMagic;
        NiSwap32((char*)&uiSwapped);
        if (uiSwapped != 0x20534444)
        {
            Unlock();
            return false;
        }
        kIst.SetEndianSwap(true);
    }

    unsigned int uiSize;
    ReadBinaryValue(kIst, uiSize);
    if (uiSize != 124)
    {
        Unlock();
        return false;
    }

    unsigned int uiFlags;
    ReadBinaryValue(kIst, uiFlags);
    if ((uiFlags & 0x1007) != 0x1007)
    {
        Unlock();
        return false;
    }

    ReadBinaryValue(kIst, m_uiImageHeight);
    ReadBinaryValue(kIst, m_uiImageWidth);

    unsigned int uiTemp;
    ReadBinaryValue(kIst, uiTemp);
    ReadBinaryValue(kIst, uiTemp);
    if ((uiFlags & 0x800000) && uiTemp != 0)
    {
        Unlock();
        return false;
    }

    unsigned int uiMipMapCount;
    ReadBinaryValue(kIst, uiMipMapCount);
    kIst.Seek(44, DAT_010a2484);

    ReadBinaryValue(kIst, uiTemp);
    unsigned int uiPFFlags;
    ReadBinaryValue(kIst, uiPFFlags);
    unsigned int uiFourCC;
    ReadBinaryValue(kIst, uiFourCC);

    m_bCubeMap = false;

    if (uiPFFlags & 0x4)
    {
        const NiPixelFormat* pkFormat;
        switch (uiFourCC)
        {
        case 0x31545844:
            pkFormat = &DAT_011aa498;
            break;
        case 0x33545844:
            pkFormat = &DAT_011aa4e0;
            break;
        case 0x35545844:
            pkFormat = &DAT_011aa528;
            break;
        case 0x6f:
            pkFormat = &DAT_011aa6d8;
            break;
        case 0x70:
            pkFormat = &DAT_011aa648;
            break;
        case 0x71:
            pkFormat = &DAT_011aa5b8;
            break;
        case 0x72:
            pkFormat = &DAT_011aa600;
            break;
        case 0x73:
            pkFormat = &DAT_011aa690;
            break;
        case 0x74:
            pkFormat = &DAT_011aa570;
            break;
        default:
            Unlock();
            return false;
        }
        m_eFormat = *pkFormat;
        kFormat = m_eFormat;
        kIst.Seek(20, DAT_010a2484);
    }
    else if (uiPFFlags & 0x40)
    {
        unsigned int uiRGBBitCount;
        unsigned int uiRBitMask;
        unsigned int uiGBitMask;
        unsigned int uiBBitMask;
        unsigned int uiABitMask;
        FUN_00a575b0(kIst, uiRGBBitCount);
        FUN_00a575b0(kIst, uiRBitMask);
        FUN_00a575b0(kIst, uiGBitMask);
        FUN_00a575b0(kIst, uiBBitMask);
        FUN_00a575b0(kIst, uiABitMask);
        if (!(uiPFFlags & 0x1))
            uiABitMask = 0;
        if (!IsValidBitDepth(uiRBitMask, uiGBitMask, uiBBitMask, uiABitMask, uiRGBBitCount))
        {
            Unlock();
            return false;
        }
        kFormat = CreateFromMasks(uiRGBBitCount, uiRBitMask, uiGBitMask, uiBBitMask, uiABitMask);
        m_eFormat = kFormat;
        kFormat = NormalizePixelFormat(kFormat);
    }
    else
    {
        Unlock();
        return false;
    }

    unsigned int uiCaps1;
    FUN_00a575b0(kIst, uiCaps1);
    if (!(uiCaps1 & 0x8) && !(uiCaps1 & 0x401000))
    {
        Unlock();
        return false;
    }

    unsigned int uiCaps2;
    FUN_00a575b0(kIst, uiCaps2);
    if (uiCaps2 & 0x200000)
    {
        Unlock();
        return false;
    }
    if (uiCaps2 & 0x200)
    {
        if (!(uiCaps2 & 0x400) || !(uiCaps2 & 0x800) || !(uiCaps2 & 0x1000) || !(uiCaps2 & 0x2000) ||
            !(uiCaps2 & 0x4000) || !(uiCaps2 & 0x8000))
        {
            Unlock();
            return false;
        }
    }
    uiFaces = (uiCaps2 & 0x200) ? 6 : 1;

    kIst.Seek(12, DAT_010a2484);

    uiWidth = m_uiImageWidth;
    uiHeight = m_uiImageHeight;

    if ((uiCaps1 & 0x8) && (uiCaps1 & 0x400000) && uiMipMapCount != 1)
    {
        bMipmap = true;
        m_uiMipMapLevels = uiMipMapCount;
    }
    else
    {
        bMipmap = false;
        m_uiMipMapLevels = 1;
    }

    Unlock();
    return true;
}

struct PixelDataView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned char* pixels;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int levels;
};
struct BinaryStreamView
{
    unsigned int unk00;
    unsigned int position;
    unsigned int(__cdecl* reader)(BinaryStreamView*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int count)
    {
        unsigned int size = 1;
        position += reader(this, data, count, &size, 1);
    }
};
struct MaskData
{
    unsigned int mask[4];
    unsigned char shift0, shift1, shift2, shift3;
    unsigned char gap0, gap1, gap2, gap3;
    void FUN_00a779b0(const NiPixelFormat&);
    unsigned char ExpandChannel0(unsigned int value) const
    {
        unsigned char g = gap0;
        unsigned int component = (value & mask[0]) >> shift0;
        unsigned int result = 0;
        unsigned char remaining = g;
        unsigned char bits = 8 - g;
        while (bits <= remaining)
        {
            result |= component;
            remaining -= bits;
            result <<= bits;
        }
        return (unsigned char)((component << g) | (result >> bits) | (component >> (8 - g - remaining)));
    }
    unsigned char ExpandChannel(unsigned int value, unsigned int ch) const
    {
        unsigned int component = (value & mask[ch]) >> (&shift0)[ch];
        unsigned int result = 0;
        unsigned char remaining = (&gap0)[ch];
        unsigned char bits = 8 - (&gap0)[ch];
        while (bits <= remaining)
        {
            result |= component;
            remaining -= bits;
            result <<= bits;
        }
        return (unsigned char)((component << (&gap0)[ch]) | (result >> bits) |
                               (component >> (8 - (&gap0)[ch] - remaining)));
    }
};
struct FormatCompare : NiPixelFormat
{
    bool FUN_00a765c0(const NiPixelFormat&) const;
};
struct Component
{
    unsigned int semantic;
    unsigned int representation;
    unsigned char bits;
    unsigned char flags;
    unsigned short unk0a;
};
struct FormatView
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Component components[4];
    unsigned char GetPixelBitData(unsigned int semantic) const
    {
        for (unsigned int i = 0; i < 4; ++i)
            if (components[i].semantic == semantic)
                return components[i].bits;
        return 0;
    }
};
// Reads one mip level from a stream and expands its packed pixels into RGBA bytes, forcing alpha to 255 when the source format has no alpha channel.
// @fnv 0x00a8c7a0
void __cdecl FUN_00a8c7a0(BinaryStreamView* stream, PixelDataView* data, NiPixelFormat source, NiPixelFormat dest,
                          unsigned int level, unsigned int face)
{
    unsigned char* __restrict pixels = data->pixels + data->offsets[level] + data->offsets[data->levels] * face;
    stream->Read(pixels, data->offsets[level + 1] - data->offsets[level]);
    MaskData masks;
    masks.FUN_00a779b0(source);
    unsigned int width = data->widths[level];
    unsigned int height = data->heights[level];
    if (((FormatCompare&)source).FUN_00a765c0(dest))
    {
        unsigned int* input = (unsigned int*)pixels;
        if (((FormatView&)source).GetPixelBitData(3) != 0)
        {
            for (unsigned int y = 0; y < height; y++)
            {
                for (unsigned int x = 0; x < width; x++)
                {
                    unsigned char r = masks.ExpandChannel0(*input);
                    unsigned char g = masks.ExpandChannel(*input, 1);
                    unsigned char b = masks.ExpandChannel(*input, 2);
                    unsigned char a = masks.ExpandChannel(*input, 3);
                    *pixels++ = r;
                    *pixels++ = g;
                    *pixels++ = b;
                    *pixels++ = a;
                    ++input;
                }
            }
        }
        else
        {
            for (unsigned int y = 0; y < height; y++)
            {
                for (unsigned int x = 0; x < width; x++)
                {
                    unsigned char r = masks.ExpandChannel0(*input);
                    unsigned char g = masks.ExpandChannel(*input, 1);
                    unsigned char b = masks.ExpandChannel(*input, 2);
                    *pixels++ = r;
                    *pixels++ = g;
                    *pixels++ = b;
                    *pixels++ = 255;
                    ++input;
                }
            }
        }
    }
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
struct ImageStream
{
    unsigned int unk00, position;
    unsigned int(__cdecl* read)(ImageStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct PixelData
{
    unsigned int unk00, unk04;
    NiPixelFormat format;
    unsigned int unk4c;
    unsigned char* pixels;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int levels, unk64, unk68, faces, unk70;
    static void* operator new(unsigned int) throw();
    PixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int) throw();
};
void __cdecl Convert32(ImageStream*, PixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
void __cdecl Convert24(ImageStream*, PixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
void __cdecl Convert16(ImageStream*, PixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
struct DDSReader
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool ReadHeader(ImageStream*, unsigned int*, unsigned int*, NiPixelFormat*, bool*, unsigned int*);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int height, width, levels;
    unsigned char swap, unk10d, unk10e, unk10f;
    NiPixelFormat format;
    PixelData* ReadPixelData(ImageStream*, PixelData*);
};
// Reads DDS pixel data for all faces and mip levels from stream into result, converting pixel format if it differs from the requested format.
// @fnv 0x00a8d0d0
PixelData* DDSReader::ReadPixelData(ImageStream* stream, PixelData* apPixelData)
{
    unsigned int uiWidth, uiHeight, faceCount;
    bool headerFlag;
    NiPixelFormat requested;
    DAT_00fdf05c(&unk080);
    if (!ReadHeader(stream, &uiWidth, &uiHeight, &requested, &headerFlag, &faceCount))
    {
        DAT_00fdf100(&unk080);
        return 0;
    }
    if (!apPixelData || apPixelData->widths[0] != width || apPixelData->heights[0] != height ||
        !(apPixelData->format == requested) || apPixelData->levels != levels || apPixelData->faces != faceCount)
        apPixelData = new PixelData(width, height, requested, levels, faceCount);
    unsigned int mipCount = apPixelData->levels;
    if (requested == format)
    {
        for (unsigned int face = 0; face < faceCount; ++face)
        {
            unsigned int faceIndex;
            switch (face - 1)
            {
            case 0:
                faceIndex = 1;
                break;
            case 1:
                faceIndex = 2;
                break;
            case 2:
                faceIndex = 3;
                break;
            case 3:
                faceIndex = 4;
                break;
            case 4:
                faceIndex = 5;
                break;
            default:
                faceIndex = 0;
                break;
            }
            for (unsigned int mip = 0; mip < mipCount; ++mip)
            {
                unsigned char* destination = apPixelData->pixels + apPixelData->offsets[mip] +
                                             apPixelData->offsets[apPixelData->levels] * faceIndex;
                unsigned int size = apPixelData->offsets[mip + 1] - apPixelData->offsets[mip];
                unsigned int count = 1;
                stream->position += stream->read(stream, destination, size, &count, 1);
            }
        }
    }
    else
    {
        for (unsigned int face = 0; face < faceCount; ++face)
        {
            unsigned int faceIndex;
            switch (face - 1)
            {
            case 0:
                faceIndex = 1;
                break;
            case 1:
                faceIndex = 2;
                break;
            case 2:
                faceIndex = 3;
                break;
            case 3:
                faceIndex = 4;
                break;
            case 4:
                faceIndex = 5;
                break;
            default:
                faceIndex = 0;
                break;
            }
            for (unsigned int mip = 0; mip < mipCount; ++mip)
            {
                switch (format.bits)
                {
                case 32:
                    Convert32(stream, apPixelData, format, requested, mip, faceIndex, swap);
                    break;
                case 24:
                    Convert24(stream, apPixelData, format, requested, mip, faceIndex, swap);
                    break;
                case 16:
                    Convert16(stream, apPixelData, format, requested, mip, faceIndex, swap);
                    break;
                }
            }
        }
    }
    DAT_00fdf100(&unk080);
    return apPixelData;
}

namespace fnv_00a8dce0 {
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;
extern const NiPixelFormat DAT_011aa180;
extern const NiPixelFormat DAT_011aa1c8;
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa258;
extern const NiPixelFormat DAT_011aa2a0;
void __fastcall DecodeBytes(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall FUN_00a8d4a0(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall ExpandGrayToRgb(void* thisPtr, int, unsigned char* src, unsigned char* dst);
void __fastcall ConvertRgb565ToRgb888(char* pThis, int, unsigned char* pucSrc, unsigned char* pucDest);
void __fastcall FUN_00a8d590(char* this_ptr, int, unsigned char* pSrc, unsigned char* pDst);
void __fastcall FUN_00a8d600(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall FUN_00a8d670(char*, int, unsigned char*, unsigned char*);
void __fastcall FUN_00a8d6c0(char*, int, unsigned char*, unsigned char*);
struct ReadStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Seek(int pos);
    virtual int SetByte(int b, int val);
    int pos;
    int(__cdecl* ReadFn)(ReadStream* self, void* dest, int size, int* pSize, int flag);
    __forceinline void ReadBytes(void* dest, int size)
    {
        pos += ReadFn(this, dest, size, &size, 1);
    }
};
struct DDSReader : NiImageReader
{
    unsigned char b100, b101, b102, unk103;
    unsigned short w104, w106;
    unsigned char b108, unk109;
    unsigned short w10a, w10c, w10e, w110;
    unsigned char b112, b113, b114, b115, b116, b117, b118;
    unsigned char unk119, unk11a, unk11b;
    NiPixelFormat m_eFormat;
    unsigned int d160, d164, d168, d16c;
    void(__fastcall* m_pfnPixelConverter)(char*, int, unsigned char*, unsigned char*);
    unsigned int d174;
    unsigned char b178, b179, b17a, b17b;
    bool FUN_00a8dce0(ReadStream* stream, int* pA, int* pB, NiPixelFormat* pFmt, unsigned char* pByte, int* pFlag);
};
// Seeks to the start, reads fields, selects m_eFormat and a converter, and writes values to pFlag, pA, pB, pFmt, and pByte.
// @fnv 0x00a8dce0
bool DDSReader::FUN_00a8dce0(ReadStream* stream, int* apWidth, int* apHeight, NiPixelFormat* apFormat,
                             unsigned char* pByte, int* pFlag)
{
    ReadStream& kReadStream = *stream;
    kReadStream.Seek(0);
    DAT_00fdf05c(lock);
    *pFlag = 1;
    kReadStream.ReadBytes(&b100, 1);
    kReadStream.ReadBytes(&b101, 1);
    kReadStream.ReadBytes(&b102, 1);
    kReadStream.ReadBytes(&w104, 2);
    kReadStream.ReadBytes(&w106, 2);
    kReadStream.ReadBytes(&b108, 1);
    kReadStream.ReadBytes(&w10a, 2);
    kReadStream.ReadBytes(&w10c, 2);
    kReadStream.ReadBytes(&w10e, 2);
    kReadStream.ReadBytes(&w110, 2);
    kReadStream.ReadBytes(&b112, 1);
    kReadStream.ReadBytes(&b113, 1);
    if (b100)
    {
        kReadStream.SetByte(b100, DAT_010a2484);
    }
    b117 = ~(b113 >> 5) & 1;
    switch (b102)
    {
    case 1:
        b116 = 1;
        b118 = 0;
        break;
    case 2:
        b118 = 0;
        b116 = 0;
        break;
    case 3:
        b118 = 0;
        b116 = 0;
        break;
    case 9:
        b116 = 1;
        b118 = 1;
        break;
    case 10:
        b118 = 1;
        b116 = 0;
        break;
    case 11:
        b118 = 1;
        b116 = 0;
        break;
    default:
        DAT_00fdf100(lock);
        return false;
    }
    unsigned char bHasPalette = b116;
    unsigned char bits = bHasPalette ? b108 : b112;
    bool bIs32Bit = bits == 0x20;
    b115 = bIs32Bit;
    if (bHasPalette)
    {
        if (w106 == 0x10)
            m_eFormat = bIs32Bit ? DAT_011aa1c8 : DAT_011aa180;
        else
            m_eFormat = bIs32Bit ? DAT_011aa258 : DAT_011aa210;
    }
    else
    {
        m_eFormat = bIs32Bit ? DAT_011aa2a0 : DAT_011aa2e8;
    }
    switch (b112)
    {
    case 4:
        b114 = 0;
        if (bHasPalette)
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))DecodeBytes;
        else
        {
            DAT_00fdf100(lock);
            return false;
        }
        break;
    case 8:
        b114 = 1;
        if (bHasPalette)
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))FUN_00a8d4a0;
        else
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))ExpandGrayToRgb;
        break;
    case 15:
    case 16:
        b114 = 2;
        if (bHasPalette)
        {
            if (bIs32Bit)
                m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))FUN_00a8d600;
            else
                m_pfnPixelConverter = FUN_00a8d590;
        }
        else
            m_pfnPixelConverter = ConvertRgb565ToRgb888;
        break;
    case 24:
        b114 = 3;
        m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))FUN_00a8d670;
        break;
    case 32:
        b114 = 4;
        m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))FUN_00a8d6c0;
        break;
    }
    b178 = 0;
    d174 = 0;
    *apWidth = w10e;
    *apHeight = w110;
    *apFormat = m_eFormat;
    *pByte = 0;
    DAT_00fdf100(lock);
    return true;
}
}  // namespace fnv_00a8dce0

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
__declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct FUN_00a8e480 : NiImageReader
{
    virtual ~FUN_00a8e480();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// @fnv 0x00a8e480
FUN_00a8e480::~FUN_00a8e480()
{
    DeleteCriticalSection((char*)this + 0x80);
}

namespace fnv_00a8cc40 {
extern const NiPixelFormat DAT_011aa2a0;
struct FormatAccess
{
    unsigned int GetMask(int) const;
    unsigned char FUN_00a62230(int) const;
};
struct ChannelInfo
{
    unsigned int mask[4];
    unsigned char shift0, shift1, shift2, shift3;
    unsigned char bits0, bits1, bits2, bits3;
    __declspec(noinline) ChannelInfo(const NiPixelFormat& f);
};
ChannelInfo::ChannelInfo(const NiPixelFormat& f)
{
    const FormatAccess& access = reinterpret_cast<const FormatAccess&>(f);
    mask[0] = access.GetMask(0);
    shift0 = access.FUN_00a62230(0);
    unsigned char b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 0)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits0 = 8 - b;
    mask[1] = access.GetMask(1);
    shift1 = access.FUN_00a62230(1);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 1)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits1 = 8 - b;
    mask[2] = access.GetMask(2);
    shift2 = access.FUN_00a62230(2);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 2)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits2 = 8 - b;
    mask[3] = access.GetMask(3);
    shift3 = access.FUN_00a62230(3);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 3)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits3 = 8 - b;
}
struct NiBinaryStream
{
    void* vtbl;
    unsigned int pos;
    unsigned int (*pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        pos += uiBytesRead;
        return uiBytesRead;
    }
    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        return BinaryRead(pvBuffer, uiBytes, &uiSize, 1);
    }
};
struct NiPixelData
{
    unsigned int unk00, unk04;
    NiPixelFormat format;
    unsigned int unk4c;
    unsigned char* pixels;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int levels;
};

template <int C> static inline unsigned char Expand(unsigned int raw, const ChannelInfo& ci)
{
    const unsigned char& bits = C == 0 ? ci.bits0 : C == 1 ? ci.bits1 : C == 2 ? ci.bits2 : ci.bits3;
    unsigned char shift = C == 0 ? ci.shift0 : C == 1 ? ci.shift1 : C == 2 ? ci.shift2 : ci.shift3;
    unsigned int v = (raw & ci.mask[C]) >> shift;
    unsigned int acc = 0;
    unsigned char rem = bits;
    unsigned char sh = 8 - bits;
    while (sh <= rem)
    {
        acc |= v;
        acc <<= sh;
        rem -= sh;
    }
    acc >>= sh;
    acc |= v >> ((8 - bits) - rem);
    v <<= bits;
    return (unsigned char)(v | acc);
}

// Reads packed pixel data from stream into buf, expands each channel via ChannelInfo, and writes RGBA or RGB bytes into data->pixels for the given mip and face.
// @fnv 0x00a8cc40
void __cdecl FUN_00a8cc40(NiBinaryStream* stream, NiPixelData* apPixelData, NiPixelFormat srcFmt, NiPixelFormat dstFmt,
                          unsigned int mip, unsigned int face)
{
    unsigned char* dst =
        apPixelData->pixels + apPixelData->offsets[mip] + apPixelData->offsets[apPixelData->levels] * face;
    unsigned int total = apPixelData->heights[mip] * apPixelData->widths[mip] * 2;
    ChannelInfo ci(srcFmt);
    unsigned short buf[256];
    for (unsigned int done = 0; done < total;)
    {
        unsigned int uiChunkBytes = 0x200;
        if (total - done < 0x200)
            uiChunkBytes = total - done;
        stream->Read(buf, uiChunkBytes);
        if (dstFmt == DAT_011aa2a0)
        {
            unsigned short* p = buf;
            for (unsigned int i = 0; i < (uiChunkBytes >> 1); i++)
            {
                *dst++ = Expand<0>(*p, ci);
                *dst++ = Expand<1>(*p, ci);
                *dst++ = Expand<2>(*p, ci);
                *dst++ = Expand<3>(*p, ci);
                p++;
            }
        }
        else if (dstFmt == DAT_011aa2e8)
        {
            unsigned short* p = buf;
            for (unsigned int i = 0; i < (uiChunkBytes >> 1); i++)
            {
                *dst++ = Expand<0>(*p, ci);
                *dst++ = Expand<1>(*p, ci);
                *dst++ = Expand<2>(*p, ci);
                p++;
            }
        }
        else
            return;
        done += uiChunkBytes;
    }
}
}  // namespace fnv_00a8cc40

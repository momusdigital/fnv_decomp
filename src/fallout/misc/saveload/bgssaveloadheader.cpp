// fallout/misc/saveload/bgssaveloadheader.cpp: free functions (4 functions)

#include "bgssaveloadheader_decls.h"

struct SaveContentDescriptor
{
    unsigned long DeviceID;
    unsigned long dwContentType;
    char szDisplayName[256];
    char szFileName[42];
    char _pad_132[2];
};
typedef char _sizecheck__XCONTENT_DATA[sizeof(SaveContentDescriptor) == 308 ? 1 : -1];
struct FUN_00850030_shell : public BGSSaveLoadManager
{
    SaveLoadFile* FUN_00850030(char*, bool, int, int);
};

__declspec(dllimport) int __stdcall DeleteFileA(const char*);

// @fnv 0x00850030
SaveLoadFile* FUN_00850030_shell::FUN_00850030(char* apFileName, bool abWrite, int aeBufferType, int aiDeviceID)
{
    unsigned int ibufferSize;
    SaveLoadFile* pfile;
    char pfullFileName[260];

    GetFullPath(apFileName, pfullFileName, abWrite);

    if (aeBufferType == 0)
        ibufferSize = 0x10000;
    else if (aeBufferType == 1)
        ibufferSize = 0x200000;
    else
        ibufferSize = 0x10000;

    if (abWrite)
    {
        if (FUN_00ecbf05(pfullFileName, 0) != -1)
            DeleteFileA(pfullFileName);
    }

    pfile = (SaveLoadFile*)FUN_00846520(pfullFileName, abWrite, ibufferSize);
    ((BGSLoadGameBuffer*)pfile)->FUN_008464f0((SaveLoadFile*)apFileName);
    ((BGSLoadGameBuffer*)pfile)->FUN_008463c0();

    return pfile;
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct LGB : public BGSLoadGameBuffer
{
    LGB();
    ~LGB();
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    unsigned int iVersion;
};

// @fnv 0x0084d8c0
int __cdecl ReadSaveHeader(SaveLoadFile* apFile)
{
    BGSLoadGameBuffer* apLoadGameBuffer;
    int iversion;
    unsigned int iresult;
    char pheaderString[260];
    pheaderString[0] = 0;
    _fnv_zlib_memset(&pheaderString[1], 0, sizeof(pheaderString) - 1);
    iresult = apFile->Read(pheaderString, strlen(DAT_011a2224));
    if (iresult == 0)
        return 0;
    if (FUN_00408b20(pheaderString, DAT_011a2224))
        return -1;

    LGB loadBuffer;
    loadBuffer.ReadAndVerifySize(apFile);
    apLoadGameBuffer = &loadBuffer;
    iversion = 0;
    apLoadGameBuffer->ReadDataBlock(&iversion, 4);
    if (iversion == 0x30)
    {
        char* pdata4 = apLoadGameBuffer->GetCombinedValue();
        if (pdata4[4] == '|')
        {
        }
        else
        {
            char lname[64];
            apLoadGameBuffer->ReadDataBlock(lname, 0x40);
        }
    }
    else
    {
        char lname[64];
        apLoadGameBuffer->ReadDataBlock(lname, 0x40);
    }
    unsigned int iscreenshotWidth2 = 0;
    unsigned int iscreenshotHeight = 0;
    apLoadGameBuffer->ReadDataBlock(&iscreenshotWidth2, 4);
    apLoadGameBuffer->ReadDataBlock(&iscreenshotHeight, 4);
    apFile->AdvancePosition(iscreenshotWidth2 * iscreenshotHeight * 3);
    return iversion;
}

struct HeaderFile
{
    void WriteToFile(const void*, unsigned int);
    const char* FUN_006815c0();
};
struct HeaderBuffer
{
    void* data;
    unsigned int unk04, unk08, unk0C, unk10;
    HeaderBuffer();
    ~HeaderBuffer();
    void FUN_00865e50(const void*, unsigned int, bool);
    void FUN_00865e70(const char*, bool);
    void FUN_00865c40(HeaderFile*);
};
struct HeaderManager
{
    unsigned int QCinfoSize();
    bool FUN_00424940();
    unsigned int FUN_0044ddc0();
    void CopyPlayerName(char*);
    void FormatPlayTime(char*, bool);
};
struct HeaderPlayer
{
    const char* FUN_0055d520();
    unsigned short FUN_0087f9f0();
};
struct HeaderSetting
{
    const char* FUN_00403df0();
    unsigned char* FUN_00408d60();
};
struct HeaderPixels
{
    virtual ~HeaderPixels();
    void* FUN_0064dac0(int, int);
};
extern HeaderManager* DAT_011de134;
extern HeaderPlayer* DAT_011dea3c;
extern HeaderSetting DAT_011c3cb4, DAT_011de2fc, DAT_011c3f74;
void* FUN_00403d30(void*, int, unsigned int);
void* FUN_00ec61c0(void*, int, unsigned int);
int FUN_00406d50(char*, unsigned int, const char*);
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_004dc200();
int FUN_004dc1f0();
HeaderPixels* FUN_00878f60(int*, int*, const char*);
const char* GetKarmicTitle(HeaderPlayer*);
// @fnv 0x0084d4b0
void FUN_0084d4b0(HeaderFile* file)
{
    file->WriteToFile(DAT_011a2224, strlen(DAT_011a2224));
    HeaderBuffer buffer_;
    HeaderBuffer* stream = &buffer_;
    unsigned int version = DAT_011de134->QCinfoSize();
    stream->FUN_00865e50(&version, 4, false);
    char playerName3[64];
    FUN_00403d30(playerName3, 0, 64);
    FUN_00406d50(playerName3, 64, DAT_011c3cb4.FUN_00403df0());
    stream->FUN_00865e50(playerName3, 64, false);
    bool wide6 = (double)FUN_004dc200() / FUN_004dc1f0() < 0.75;
    int height5 = wide6 ? 512 : 432;
    int width2 = wide6 ? 512 : 432;
    char screenshotPath_2[260];
    screenshotPath_2[0] = 0;
    FUN_00ec61c0(screenshotPath_2 + 1, 0, 259);
    if (*DAT_011de2fc.FUN_00408d60())
    {
        FUN_00406d30(screenshotPath_2, 260, DAT_011c3f74.FUN_00403df0());
        FUN_00406d50(screenshotPath_2, 260, file->FUN_006815c0());
        FUN_00406d50(screenshotPath_2, 260, ".bmp");
    }
    HeaderPixels* pixels = 0;
    if (!DAT_011de134->FUN_00424940())
        pixels = FUN_00878f60(&height5, &width2, screenshotPath_2);
    else
    {
        float aspect3 = (double)FUN_004dc200() / FUN_004dc1f0();
        width2 = (int)(width2 * aspect3);
    }
    stream->FUN_00865e50(&height5, 4, false);
    stream->FUN_00865e50(&width2, 4, false);
    unsigned int numberVal = DAT_011de134->FUN_0044ddc0();
    stream->FUN_00865e50(&numberVal, 4, false);
    stream->FUN_00865e70(DAT_011dea3c->FUN_0055d520(), false);
    stream->FUN_00865e70(GetKarmicTitle(DAT_011dea3c), false);
    unsigned int level2 = DAT_011dea3c->FUN_0087f9f0();
    stream->FUN_00865e50(&level2, 4, false);
    char location9[260];
    DAT_011de134->CopyPlayerName(location9);
    stream->FUN_00865e70(location9, false);
    char time[260];
    DAT_011de134->FormatPlayTime(time, true);
    stream->FUN_00865e70(time, false);
    buffer_.FUN_00865c40(file);
    if (!DAT_011de134->FUN_00424940())
        file->WriteToFile(pixels->FUN_0064dac0(0, 0), height5 * width2 * 3);
    else
        file->WriteToFile(0, height5 * width2 * 3);
    delete pixels;
}

class NiPixelFormat
{
  public:
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
};

extern const NiPixelFormat kScreenshotPixelFormat;

class ScreenshotPixelData : public NiMemObject
{
  public:
    ScreenshotPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int mipmapLevels,
                        unsigned int faces);
    void* GetPixels(int mipmap, int face);
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
};

struct ScreenshotTexFormat
{
    ScreenshotTexFormat();
    int iPixelLayout;
    int iAlphaFormat;
    int iMipMapped;
};

struct ScreenshotName
{
    ScreenshotName(const char* str);
    ~ScreenshotName();
    operator const char*() const;
    const char* pString;
};

NiTexture* __cdecl CreateScreenshotTexture(ScreenshotPixelData* pixelData, const char* name,
                                           ScreenshotTexFormat* format);

// Seeks to offset in file, reads width*height*3 bytes into a new ScreenshotPixelData, and creates a texture named BGSSaveLoadHeader_Screenshot.
// @fnv 0x0084dda0
NiTexture* __cdecl LoadScreenshotTexture(SaveLoadFile* file, unsigned int offset, unsigned int width,
                                         unsigned int height)
{
    file->SetFilePosition(offset);
    NiPixelFormat format = kScreenshotPixelFormat;
    ScreenshotPixelData* pixelData2 = new ScreenshotPixelData(width, height, format, 1, 1);
    file->Read(pixelData2->GetPixels(0, 0), width * height * 3);
    ScreenshotTexFormat aTexFormat;
    aTexFormat.iPixelLayout = 2;
    aTexFormat.iMipMapped = 0;
    aTexFormat.iAlphaFormat = 0;
    return CreateScreenshotTexture(pixelData2, ScreenshotName("BGSSaveLoadHeader_Screenshot"), &aTexFormat);
}

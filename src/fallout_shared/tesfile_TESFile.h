// Source layout: TESFile. PC corrections are in generate_headers.py.
#ifndef FNV_TESFILE_QUEUE081_PRIVATE_H
#define FNV_TESFILE_QUEUE081_PRIVATE_H

#include "../../include/layout_support.h"
#include "../../include/TESFileHeader.h"
#include "../../include/FormRecordHeader.h"
#include "../../include/_FILETIME.h"
#include "../../include/_WIN32_FIND_DATAA.h"
class TESFile
{
  public:
    TES_RETURN_CODE m_eReturnCode;                                // +0x0
    TESFile* m_pThreadSafeParent;                                 // +0x4
    NiTPointerMap<unsigned int, TESFile*>* m_pThreadSafeFileMap;  // +0x8
    BSFile* m_pSecondaryFile;                                     // +0xC
    BSFile* m_pFile;                                              // +0x10
    TESBitArrayFile* m_pBitArrayFile1;                            // +0x14
    TESBitArrayFile* m_pBitArrayFile2;                            // +0x18
    TESBitArrayFile* m_pBitArrayFile3;                            // +0x1C
    char m_acFilename[260];                                       // +0x20
    char m_acPath[260];                                           // +0x124
    char* m_pBuffer;                                              // +0x228
    unsigned int m_uiBufferAllocSize;                             // +0x22C
    unsigned int m_uiReadPosition;                                // +0x230
    unsigned int m_uiBufferSize;                                  // +0x234
    TESObjectCELL* m_pCurrentCell;                                // +0x238
    unsigned int m_uiFormCount;                                   // +0x23C
    FormRecordHeader m_kRecordInfo;                                           // +0x240
    CHUNK_ID m_eChunkID;                                          // +0x258
    unsigned int m_uiChunkSize;                                   // +0x25C
    unsigned int m_uiChunkOffset;                                 // +0x260
    unsigned int m_uiRecordSize;                                  // +0x264
    unsigned int m_uiRecordOffset;                                // +0x268
    unsigned int m_uiCurrentOffset;                               // +0x26C
    FormRecordHeader m_kChunkInfo;                                            // +0x270
    unsigned int m_uiChunkValue1;                                 // +0x288
    unsigned int m_uiChunkValue2;                                 // +0x28C
    BSSimpleList<TESFileGroup*> m_kRecordList;                      // +0x290
    bool m_bIsLoading;                                            // +0x298
    bool m_bIsSaving;                                             // +0x299
    bool m_bHasCurrentGroup;                                      // +0x29A
    unsigned char layoutPadding29B[1];
    _WIN32_FIND_DATAA m_kFindData;                   // +0x29C
    TESFileHeader m_kFileMetadata;                     // +0x3DC
    unsigned int m_uiFileCount;                      // +0x3E8
    BSSimpleList<char*> m_kFilenameList;             // +0x3EC
    BSSimpleList<_ULARGE_INTEGER*> m_kFileSizeList;  // +0x3F4
    unsigned int m_uiTESFileCount;                   // +0x3FC
    TESFile** m_ppTESFiles;                          // +0x400
    _FILETIME m_kLastWriteTime;                      // +0x404
    unsigned char m_ucCompileIndex;                  // +0x40C
    unsigned char layoutPadding40D[3];
    BSStringT<char> m_kCreator;       // +0x410
    BSStringT<char> m_kSummary;       // +0x418
    char* m_pDecompressedFormBuffer;  // +0x420
    unsigned int m_uiAuxBufferSize;   // +0x424
    bool m_bIsMaster;                 // +0x428
    bool m_bOptimizedFile;            // +0x429
    bool m_bIsDLC;                    // +0x42A
    unsigned char layoutPadding42B[1];
    TESFile* GetThreadSafeFile();
    TESFile* GetThreadSafeParent();
    TESFile* GetThreadSafeFileForThread(unsigned int threadID);
    bool IsEndianConversionRequired();
    bool IsCurrentFormCompressed();
    TESFile(const char* path, const char* filename, NiFile::OpenMode openMode);
    const char* GetFilename();
    const char* GetPath();
    bool IsMasterFile();
    void SetMasterFile(bool master);
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char index);
    bool GenIndexTable(BSSimpleList<TESFile*>* files, bool unknown);
    void SetThreadSafeParent(TESFile* parent);
    bool OpenTESFile(NiFile::OpenMode openMode, bool closeOverride);
    void InitializeComponent();
    bool SetOffset(unsigned int offset);
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* value);
    bool NextChunk();
    bool GetCached();
    unsigned int GetOffset();
    bool OpenTESFile(const char* path, const char* filename, NiFile::OpenMode openMode, bool closeOverride);
    bool GetOptimizedFile();
    bool GetIsChecked();
    void ClearCurrentChunk();
    bool GetHasGroups();
    void SetTempIDOwner(bool owner);
    bool GetTempIDOwner();
    unsigned int GetOffsetChunk();
    unsigned int GetFORMSize();
    bool HasNextForm();
    bool NextGroup();

  protected:
    BSSimpleList<_ULARGE_INTEGER*>* GetMasterDataList();
};
FNV_STATIC_ASSERT(sizeof(TESFile) == 0x42C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_eReturnCode) == 0x0);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pThreadSafeParent) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pThreadSafeFileMap) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pSecondaryFile) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pFile) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pBitArrayFile1) == 0x14);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pBitArrayFile2) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pBitArrayFile3) == 0x1C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_acFilename) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESFile, m_acPath) == 0x124);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pBuffer) == 0x228);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiBufferAllocSize) == 0x22C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiReadPosition) == 0x230);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiBufferSize) == 0x234);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pCurrentCell) == 0x238);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiFormCount) == 0x23C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kRecordInfo) == 0x240);
FNV_STATIC_ASSERT(offsetof(TESFile, m_eChunkID) == 0x258);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiChunkSize) == 0x25C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiChunkOffset) == 0x260);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiRecordSize) == 0x264);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiRecordOffset) == 0x268);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiCurrentOffset) == 0x26C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kChunkInfo) == 0x270);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiChunkValue1) == 0x288);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiChunkValue2) == 0x28C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kRecordList) == 0x290);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bIsLoading) == 0x298);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bIsSaving) == 0x299);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bHasCurrentGroup) == 0x29A);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kFindData) == 0x29C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kFileMetadata) == 0x3DC);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiFileCount) == 0x3E8);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kFilenameList) == 0x3EC);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kFileSizeList) == 0x3F4);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiTESFileCount) == 0x3FC);
FNV_STATIC_ASSERT(offsetof(TESFile, m_ppTESFiles) == 0x400);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kLastWriteTime) == 0x404);
FNV_STATIC_ASSERT(offsetof(TESFile, m_ucCompileIndex) == 0x40C);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kCreator) == 0x410);
FNV_STATIC_ASSERT(offsetof(TESFile, m_kSummary) == 0x418);
FNV_STATIC_ASSERT(offsetof(TESFile, m_pDecompressedFormBuffer) == 0x420);
FNV_STATIC_ASSERT(offsetof(TESFile, m_uiAuxBufferSize) == 0x424);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bIsMaster) == 0x428);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bOptimizedFile) == 0x429);
FNV_STATIC_ASSERT(offsetof(TESFile, m_bIsDLC) == 0x42A);
#endif

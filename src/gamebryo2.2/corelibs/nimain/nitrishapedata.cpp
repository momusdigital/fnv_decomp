// gamebryo2.2/corelibs/nimain/nitrishapedata.cpp: Obj, Blk, HolderA, HolderB and more (17 functions)

#include "nitrishapedata_decls.h"

void __fastcall FUN_00a7b8c0(void*);

class NiMemObject
{
  public:
    static void __cdecl operator delete(void*, unsigned int);
};

// Calls FUN_00a7b8c0 on pThis, then frees pThis with NiMemObject::operator delete when flags has bit 1 set, and returns pThis.
// @fnv 0x00a7b920
void* __fastcall FUN_00a7b920(void* pThis, int, unsigned int flags)
{
    FUN_00a7b8c0(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x58);
    return pThis;
}

void __cdecl _NiFreeAlias(void*);

struct FUN_00a7b6c0_T
{
    char pad[0x40];
    unsigned short a;
    unsigned int b;
    unsigned short* c;
};

// Frees the previous c buffer if it differs from the new one, stores a and c, and sets b to a times 3.
// @fnv 0x00a7b6c0
void __fastcall FUN_00a7b6c0(FUN_00a7b6c0_T* self, int, unsigned short ausValue, unsigned short* apusBuffer)
{
    if (apusBuffer != self->c && self->c)
        _NiFreeAlias(self->c);
    self->a = ausValue;
    self->c = apusBuffer;
    self->b = ausValue * 3;
}

struct FUN_00a7b700_T
{
    char pad[0x40];
    unsigned short a;
    unsigned int b;
    unsigned int c;
};

// @fnv 0x00a7b700
void __fastcall FUN_00a7b700(FUN_00a7b700_T* self, int, unsigned short ausValue, unsigned int auiValue)
{
    self->a = ausValue;
    self->b = ausValue * 3;
    self->c = auiValue;
}

struct FUN_00a7b720_T
{
    char pad[0x48];
    unsigned short* c;
};

// Reads three consecutive unsigned shorts from self->c at offset i*3 and writes them to the three output pointers.
// @fnv 0x00a7b720
void __fastcall GetTriangleIndices(FUN_00a7b720_T* self, int, unsigned short i, unsigned short* i0, unsigned short* i1,
                             unsigned short* i2)
{
    unsigned int j = i * 3;
    *i0 = self->c[j];
    *i1 = self->c[j + 1];
    *i2 = self->c[j + 2];
}

struct FUN_00a7b760_T
{
    char pad[0x40];
    unsigned short a;
    unsigned int b;
    unsigned short* c;
};

// @fnv 0x00a7b760
void __fastcall GetStripData(FUN_00a7b760_T* self, int, unsigned short* p1, unsigned int* p2, unsigned short** p3,
                             unsigned int* p4)
{
    *p1 = self->a;
    *p2 = 0;
    *p3 = self->c;
    *p4 = self->a * 3;
}

extern const char* const g_011f5af4_arg1;

// @fnv 0x00a7b860
const char* const* __fastcall GetRTTI(void* self, int)
{
    return &g_011f5af4_arg1;
}

struct FUN_00a7b870_T
{
    short a;
    int b;
};

// @fnv 0x00a7b870
FUN_00a7b870_T* __fastcall FUN_00a7b870(FUN_00a7b870_T* self, int)
{
    self->a = 0;
    self->b = 0;
    return self;
}

void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
struct MemoryManagerDealloc
{
    void Deallocate(void*);
};

struct Blk
{
    void* data;
    char pad[0xc];
    Blk* next;
    Blk* FreeBlock(unsigned int flags);
    static void operator delete(void* p)
    {
        reinterpret_cast<MemoryManagerDealloc&>(g_memoryManager).Deallocate(p);
    }
};

// Frees data, recursively frees the next block, and deletes this block when flags has bit 0 set; returns this.
// @fnv 0x00a7b880
Blk* Blk::FreeBlock(unsigned int flags)
{
    _NiFreeAlias(data);
    if (next)
        next->FreeBlock(1);
    if (flags & 1)
        delete this;
    return this;
}

namespace fnv_00a7b8c0 {
void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern void* DAT_0109dac4[];
struct MemoryManagerDealloc
{
    void Deallocate(void*);
};

struct Blk
{
    void* data;
    char pad[0xc];
    Blk* next;
    Blk* FreeBlock(unsigned int flags);
    ~Blk()
    {
        _NiFreeAlias(data);
        if (next)
            next->FreeBlock(1);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<MemoryManagerDealloc&>(g_memoryManager).Deallocate(p);
    }
};

struct FUN_00a8a990_S
{
    void FUN_00a8a990();
};

struct Obj : FUN_00a8a990_S
{
    void* vtbl;
    char pad[0x44];
    void* list;
    void* tail;
    unsigned int sz;
    Blk* shared;
    void FUN_00a7b8c0();
};

// Resets vtbl, frees list and shared, deallocates tail through the memory manager, then calls FUN_00a8a990.
// @fnv 0x00a7b8c0
void Obj::FUN_00a7b8c0()
{
    vtbl = DAT_0109dac4;
    if (list)
        _NiFreeAlias(list);
    if (shared)
        delete shared;
    reinterpret_cast<MemoryManagerDealloc&>(g_memoryManager).Deallocate(tail);
    FUN_00a8a990();
}
}  // namespace fnv_00a7b8c0

extern const char* const g_011f5af4_arg1;
char* __cdecl FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d510(const char*, unsigned int);
char* __cdecl FUN_00a7d5a0(const char*, void*);

struct StrArr
{
    char pad[8];
    unsigned short size;
    unsigned short count;
    unsigned short pad2;
    unsigned short growBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* e)
    {
        unsigned int i = count;
        if (i >= size)
            SetSize(i + growBy);
        SetAt(i, e);
    }
};

struct Base1
{
    void AppendTrianglesInfo(StrArr*);
};

struct Obj : Base1
{
    char pad[0x44];
    unsigned int len;
    void* list;
    void AppendTriListInfo(StrArr* a);
};

// Appends the base entry, a formatted m_uiTriListLength value and a formatted m_pusTriList pointer to the StrArr.
// @fnv 0x00a7bd60
void Obj::AppendTriListInfo(StrArr* pStrArr)
{
    AppendTrianglesInfo(pStrArr);
    pStrArr->Add(FUN_00a7d330(g_011f5af4_arg1));
    pStrArr->Add(FUN_00a7d510("m_uiTriListLength", len));
    pStrArr->Add(FUN_00a7d5a0("m_pusTriList", list));
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a7bbe0_shell : public NiTriShapeData
{
    void FUN_00a7bbe0(NiStream*);
};

struct BinStreamS
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(BinStreamS*, const void*, unsigned int, unsigned int*, unsigned int);
    void BinaryWriteN(const void* pvBuffer, unsigned int ItemUpdateArray, unsigned int uiComponentSize)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiComponentSize * ItemUpdateArray, &uiComponentSize, 1);
    }
    void BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int uiComponentSize)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiTotalBytes, &uiComponentSize, 1);
    }
};

template <class T> inline void SaveBinS(NiStream* pkStream, const T& value)
{
    BinStreamS* pkOstr = *(BinStreamS**)((char*)pkStream + 0x250);
    pkOstr->BinaryWrite(&value, sizeof(T), sizeof(T));
}

template <class T> inline void SaveBinArrS(NiStream* pkStream, const T* pValue, unsigned int ItemUpdateArray)
{
    unsigned int uiBytes = ItemUpdateArray * sizeof(T);
    BinStreamS* pkOstr = *(BinStreamS**)((char*)pkStream + 0x250);
    pkOstr->BinaryWrite(pValue, uiBytes, sizeof(T));
}

struct SharedNormalArrayS
{
    unsigned short m_usSize;
    unsigned short* m_pusArray;
};

// Saves the triangle list length, its presence flag and data, then the shared-normal array sizes and entries to the stream.
// @fnv 0x00a7bbe0
void FUN_00a7bbe0_shell::FUN_00a7bbe0(NiStream* kStream)
{
    char* p = (char*)this;
    NiTriBasedGeomData::SaveBinary(*kStream);
    unsigned int& uiTriListLength = *(unsigned int*)(p + 0x44);
    unsigned short*& pusTriList = *(unsigned short**)(p + 0x48);
    SharedNormalArrayS*& pkSharedNormals = *(SharedNormalArrayS**)(p + 0x4c);
    unsigned short& usSharedSize = *(unsigned short*)(p + 0x50);

    SaveBinS(kStream, uiTriListLength);
    unsigned char bHasList = (pusTriList != 0);
    SaveBinS(kStream, bHasList);
    if (bHasList)
        SaveBinArrS(kStream, pusTriList, uiTriListLength);
    SaveBinS(kStream, usSharedSize);
    for (unsigned short usI = 0; usI < usSharedSize; usI++)
    {
        unsigned short m_usPassCountLocal = pkSharedNormals[usI].m_usSize;
        SaveBinS(kStream, m_usPassCountLocal);
        if (m_usPassCountLocal)
            SaveBinArrS(kStream, pkSharedNormals[usI].m_pusArray, m_usPassCountLocal);
    }
}

namespace fnv_00a7b940 {
struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a7b940_shell : public NiTriShapeData
{
    void FUN_00a7b940(NiStream*);
};

void* NiMalloc(unsigned int) throw();
extern MemoryManager g_memoryManager;

struct NiBinaryStreamView
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamView*, void*, unsigned int, unsigned int*, unsigned int);
};

struct FUN_00a7b870
{
    unsigned short m_usElementCount;
    unsigned short* m_pusArray;
    FUN_00a7b870() throw();
    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    void SetArray(unsigned short m_usPassCountLocal, unsigned short* pusArray)
    {
        if (m_usPassCountLocal && pusArray)
        {
            m_usElementCount = m_usPassCountLocal;
            m_pusArray = pusArray;
        }
        else
        {
            m_usElementCount = 0;
            m_pusArray = 0;
        }
    }
};

struct IndexBufferBlock
{
    unsigned short* m_pIndices;
    unsigned short* m_pCurrentIndex;
    unsigned int m_uiIndexCapacity;
    unsigned int m_uiUsedIndexCount;
    IndexBufferBlock* m_pkNext;
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    IndexBufferBlock(unsigned int uiSize)
    {
        m_pIndices = (unsigned short*)NiMalloc(uiSize * 2);
        m_pCurrentIndex = m_pIndices;
        m_uiIndexCapacity = uiSize;
        m_uiUsedIndexCount = uiSize;
        m_pkNext = 0;
    }
};

static inline NiBinaryStreamView* GetIstr(NiStream* kStream)
{
    return *(NiBinaryStreamView**)((char*)kStream + 0x24c);
}

inline unsigned int BinaryRead(NiBinaryStreamView& kStream, void* pvBuffer, unsigned int uiTotalBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = kStream.m_pfnRead(&kStream, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    kStream.m_uiStreamFlags += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void ReadBinaryValue(NiBinaryStreamView& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    BinaryRead(kStream, &value, sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiBinaryStreamView& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    BinaryRead(kStream, pValue, uiNumEls * uiSize, &uiSize, 1);
}

// Loads triangle data from the stream: reads a count, an optional list flag, the index array, and per-element arrays allocated from a shared block pool.
// @fnv 0x00a7b940
void FUN_00a7b940_shell::FUN_00a7b940(NiStream* kStream)
{

    ((NiTriBasedGeomData*)this)->LoadBinary(*(::NiStream*)kStream);

    ReadBinaryValue(*GetIstr(kStream), (*(unsigned int*)((char*)this + 0x44)));

    unsigned char bHasList;
    if (*(unsigned int*)((char*)kStream + 0xd8) >= 0x0A000111)
        ReadBinaryValue(*GetIstr(kStream), bHasList);
    else
        bHasList = 1;

    if (bHasList && (*(unsigned int*)((char*)this + 0x44)) > 0)
    {
        (*(unsigned short**)((char*)this + 0x48)) =
            (unsigned short*)NiMalloc((*(unsigned int*)((char*)this + 0x44)) * 2);
        ReadBinaryValue(*GetIstr(kStream), (*(unsigned short**)((char*)this + 0x48)),
                        (*(unsigned int*)((char*)this + 0x44)));
    }

    ReadBinaryValue(*GetIstr(kStream), (*(unsigned short*)((char*)this + 0x50)));
    if ((*(unsigned short*)((char*)this + 0x50)))
    {
        (*(FUN_00a7b870**)((char*)this + 0x4c)) = new FUN_00a7b870[(*(unsigned short*)((char*)this + 0x50))];
        (*(IndexBufferBlock**)((char*)this + 0x54)) = new IndexBufferBlock((*(unsigned short*)((char*)this + 0x50)));

        for (unsigned short usI = 0; usI < (*(unsigned short*)((char*)this + 0x50)); usI++)
        {
            unsigned short m_usPassCountLocal;
            unsigned short* pusArray = 0;
            ReadBinaryValue(*GetIstr(kStream), m_usPassCountLocal);
            if (m_usPassCountLocal)
            {
                IndexBufferBlock* pkBlock = (*(IndexBufferBlock**)((char*)this + 0x54));
                while (pkBlock)
                {
                    if (m_usPassCountLocal <= pkBlock->m_uiUsedIndexCount)
                        break;
                    pkBlock = pkBlock->m_pkNext;
                }
                if (!pkBlock)
                {
                    pkBlock = new IndexBufferBlock((*(IndexBufferBlock**)((char*)this + 0x54))->m_uiIndexCapacity * 2);
                    pkBlock->m_pkNext = (*(IndexBufferBlock**)((char*)this + 0x54));
                    (*(IndexBufferBlock**)((char*)this + 0x54)) = pkBlock;
                }
                pusArray = pkBlock->m_pCurrentIndex;
                pkBlock->m_uiUsedIndexCount -= m_usPassCountLocal;
                pkBlock->m_pCurrentIndex += m_usPassCountLocal;
                ReadBinaryValue(*GetIstr(kStream), pusArray, m_usPassCountLocal);
            }
            (*(FUN_00a7b870**)((char*)this + 0x4c))[usI].SetArray(m_usPassCountLocal, pusArray);
        }
    }
}
}  // namespace fnv_00a7b940

// NiTriShapeData constructor: triangle-list length is three indices per triangle.

class A7B630Point2;
class A7B630Point3;
class A7B630ColorA;

class A7B630TriBasedGeomData
{
  public:
    A7B630TriBasedGeomData(unsigned short usVertices, A7B630Point3* pkVertex, A7B630Point3* pkNormal,
                           A7B630ColorA* pkColor, A7B630Point2* pkTexture, unsigned short usNumTextureSets,
                           int eNBTMethod, unsigned short usTriangles);
    virtual ~A7B630TriBasedGeomData();
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
    unsigned short m_usTriangles;
    unsigned short m_usActiveTriangles;
};

class FUN_00a7b630 : public A7B630TriBasedGeomData
{
  public:
    unsigned int m_uiTriListLength;
    unsigned short* m_pusTriList;
    void* m_pkSharedNormalArray;
    unsigned short m_usSharedNormalCount;
    void* m_pkSharedNormalArrayMemoryBlock;

    FUN_00a7b630(unsigned short usVertices, A7B630Point3* pkVertex, A7B630Point3* pkNormal, A7B630ColorA* pkColor,
                 A7B630Point2* pkTexture, unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles,
                 unsigned short* pusTriList);
    virtual ~FUN_00a7b630();
};

// Constructs the base geometry data, sets the triangle list length to 3*m_usTriangles, stores pusTriList and zeroes three members.
// @fnv 0x00a7b630
FUN_00a7b630::FUN_00a7b630(unsigned short usVertices, A7B630Point3* pkVertex, A7B630Point3* pkNormal,
                           A7B630ColorA* pkColor, A7B630Point2* pkTexture, unsigned short usNumTextureSets,
                           int eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList)
    : A7B630TriBasedGeomData(usVertices, pkVertex, pkNormal, pkColor, pkTexture, usNumTextureSets, eNBTMethod,
                             usTriangles)
{
    m_uiTriListLength = 3 * m_usTriangles;
    m_pusTriList = pusTriList;
    m_pkSharedNormalArray = 0;
    m_usSharedNormalCount = 0;
    m_pkSharedNormalArrayMemoryBlock = 0;
}

struct Base_a7b
{
    virtual void v00();
    int unk04[16];
    Base_a7b();
};

struct FUN_00a7b690 : Base_a7b
{
    void* m_p44;
    void* m_p48;
    void* m_p4c;
    unsigned short m_us50;
    void* m_p54;
    virtual void v00();
    FUN_00a7b690();
};

// Initializes the object's pointer fields and the unsigned short field to zero.
// @fnv 0x00a7b690
FUN_00a7b690::FUN_00a7b690() : m_p44(0), m_p48(0), m_p4c(0), m_us50(0), m_p54(0)
{}

struct BaseA7b7e0
{
    bool MatchesTriangleCount(const void* pkOther);
};
struct NameA7b7e0 : BaseA7b7e0
{
    char pad000[0x44];
    unsigned int m_uiNameHash;
    char* m_pReferencedObject;

    bool FUN_00a7b7e0(const NameA7b7e0* pkOther);
};

// @fnv 0x00a7b7e0
bool NameA7b7e0::FUN_00a7b7e0(const NameA7b7e0* pkOther)
{
    if (!BaseA7b7e0::MatchesTriangleCount(pkOther))
        return false;
    if (m_uiNameHash != pkOther->m_uiNameHash)
        return false;
    unsigned int uiBytes = m_uiNameHash * 2;
    unsigned int* pB = (unsigned int*)pkOther->m_pReferencedObject;
    unsigned int* pA = (unsigned int*)m_pReferencedObject;
    while (uiBytes >= 4)
    {
        if (*pA != *pB)
            return false;
        uiBytes -= 4;
        pB++;
        pA++;
    }
    if (uiBytes != 0)
    {
        char* cA = (char*)pA;
        char* pcB = (char*)pB;
        if (pcB[0] != cA[0])
            return false;
        if (uiBytes > 1)
        {
            if (pcB[1] != cA[1])
                return false;
            if (uiBytes > 2 && pcB[2] != cA[2])
                return false;
        }
    }
    return true;
}

namespace fnv_00ba3d30 {
extern "C" char DAT_010b7fe4;

void __cdecl FUN_00aa10f0(void*);

class MemoryManagerDealloc
{
  public:
    void __thiscall FUN_00aa4060(void* object);
};

extern "C" MemoryManagerDealloc DAT_011f6238;

class HolderA
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderA();
};

HolderA::~HolderA()
{
    void* memory = m_pData;
    FUN_00aa10f0(memory);
}

class HolderB
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderB();
};

HolderB::~HolderB()
{
    void* memory = m_pData;
    FUN_00aa10f0(memory);
}

class HolderC
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderC();
};

HolderC::~HolderC()
{
    void* memory = m_pData;
    FUN_00aa10f0(memory);
}

class HolderArray
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usElementCount;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    void __thiscall FUN_00ba3aa0(unsigned int index, void*& value);

    virtual ~HolderArray();
};

HolderArray::~HolderArray()
{
    void* memory = m_pData;
    FUN_00aa10f0(memory);
}

extern int DAT_010b9d24;
struct PlainHolder
{
    void* vtable;
    void* m_pData;
    unsigned short capacity, count, used, growth;
    void Release()
    {
        void* memory = m_pData;
        vtable = &DAT_010b9d24;
        FUN_00aa10f0(memory);
    }
};

class FUN_00ba3d30
{
  public:
    unsigned int unknown04;
    HolderA m_holder08;
    HolderB m_holder18;
    HolderC m_holder28;
    HolderArray m_holder38;
    PlainHolder m_holder48;

    virtual ~FUN_00ba3d30();
};

// Frees each non-null element of m_holder38 via DAT_011f6238, clears it, then releases m_holder48.
// @fnv 0x00ba3d30
FUN_00ba3d30::~FUN_00ba3d30()
{

    for (unsigned int index = 0; index < m_holder38.m_usElementCount; ++index)
    {
        if (((void**)m_holder38.m_pData)[index])
        {
            void* element = ((void**)m_holder38.m_pData)[index];
            DAT_011f6238.FUN_00aa4060(element);
            void* cleared = 0;
            m_holder38.FUN_00ba3aa0(index, cleared);
        }
    }
    m_holder48.Release();
}
}  // namespace fnv_00ba3d30

struct FnvCpu_FUN_00a7b850_CpuObject
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
    int value;
    int FUN_00a7b850();
};
// @fnv 0x00a7b850
int FnvCpu_FUN_00a7b850_CpuObject::FUN_00a7b850()
{
    return value;
}

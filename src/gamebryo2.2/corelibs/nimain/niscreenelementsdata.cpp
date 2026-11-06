// gamebryo2.2/corelibs/nimain/niscreenelementsdata.cpp: NiScreenElementsData, NiScreenElementsDataShell (10 functions)

#include "niscreenelementsdata_decls.h"

// @fnv 0x00a88020
bool NiScreenElementsData::SetRectangle(int iPolygon, float fLeft, float fTop, float afWidth, float afHeight)
{
    if (iPolygon < 0 || iPolygon >= m_usMaxPQuantity)
        return false;
    unsigned short usIndex = m_ausPIndexer[iPolygon];
    if (usIndex == 0xFFFF)
        return false;
    NiScreenElementsData__Polygon& kPolygon = m_akPolygon[usIndex];
    if (kPolygon.m_usVertexCount != 4)
        return false;
    unsigned int i = kPolygon.m_usVertexOffset;
    float fRight = fLeft + afWidth;
    float fBottom = fTop + afHeight;
    GetVertices()[i].x = fLeft;
    GetVertices()[i].y = fTop;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fLeft;
    GetVertices()[i].y = fBottom;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fRight;
    GetVertices()[i].y = fBottom;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fRight;
    GetVertices()[i].y = fTop;
    GetVertices()[i].z = 0.0f;
    SetDirtyFlags(1);
    m_bGeometryInitialized = true;
    return true;
}

// @fnv 0x00a88130
bool NiScreenElementsData::SetRectangleBounds(int iPolygonIndex, unsigned short usTextureSetIndex, float fLeft,
                                              float fTop, float fRight, float fBottom)
{
    if (m_pkTexture && iPolygonIndex >= 0 && iPolygonIndex < m_usMaxPQuantity)
    {
        unsigned short usIndex = m_ausPIndexer[iPolygonIndex];
        if (usIndex != 0xFFFF)
        {
            NiScreenElementsData__Polygon& kPolygon = m_akPolygon[usIndex];
            if (kPolygon.m_usVertexCount == 4 && usTextureSetIndex < (unsigned short)(m_usTrianglePoints & 1))
            {
                NiPoint2* pkTexture = FUN_00a66960(usTextureSetIndex) + kPolygon.m_usVertexOffset;
                pkTexture[0].x = fLeft;
                pkTexture[0].y = fTop;
                pkTexture[1].x = fLeft;
                pkTexture[1].y = fBottom;
                pkTexture[2].x = fRight;
                pkTexture[2].y = fBottom;
                pkTexture[3].x = fRight;
                pkTexture[3].y = fTop;
                SetDirtyFlags(8);
                return true;
            }
        }
    }
    return false;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b50;

// @fnv 0x00a87a90
GlobalObjectO2_00a7b610* __cdecl FUN_00a87a90()
{
    return &g_011f5b50;
}

void __fastcall FUN_00a7b8c0(void*);
void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109ea94;
struct Holder00a87aa0
{
    void* Destroy(unsigned int);
};
// Frees the two pointers at offsets 0x58 and 0x5c, calls FUN_00a7b8c0 on this, and deletes this (0x70 bytes) when f has bit 0 set.
// @fnv 0x00a87aa0
void* Holder00a87aa0::Destroy(unsigned int auiFlags)
{
    void* p = *(void**)((char*)this + 0x58);
    *(void**)this = (void*)&DAT_0109ea94;
    _NiFreeAlias(p);
    _NiFreeAlias(*(void**)((char*)this + 0x5c));
    FUN_00a7b8c0(this);
    if (auiFlags & 1)
        _delete(this, 0x70);
    return this;
}

struct FUN_00a886f0_shell : public NiScreenElementsData
{
    void AppendMemberDescriptions(void*);
};

struct StrArr
{
    void* m_pData;
    void* m_pAllocator;
    unsigned short m_usCapacity;
    unsigned short m_usSize;
    unsigned short m_usReserved;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

struct Obj
{
    void AppendTriListInfo(StrArr*);
};

char* __cdecl _FUN_00a7d330(void*);
char* __cdecl FUN_00a7d490(char const*, unsigned short);
char* __cdecl FUN_00a7d5a0(char const*, void*);

// Appends the object's member names and values to the string array, growing it as needed via SetSize and SetAt.
// @fnv 0x00a886f0
void FUN_00a886f0_shell::AppendMemberDescriptions(void* pkStrings)
{
    StrArr* strings = static_cast<StrArr*>(pkStrings);
    char* value;
    unsigned int index;

    reinterpret_cast<Obj*>(this)->AppendTriListInfo(strings);

    value = _FUN_00a7d330(*reinterpret_cast<void**>(&g_011f5b50));
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d5a0("m_akPolygon", this->m_akPolygon);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d5a0("m_ausPIndexer", this->m_ausPIndexer);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usMaxPQuantity", this->m_usMaxPQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usPGrowBy", this->m_usPGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usPQuantity", this->m_usPQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usMaxVQuantity", this->m_usMaxVQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usVGrowBy", this->m_usVGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usMaxIQuantity", this->m_usMaxIQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = FUN_00a7d490("m_usIGrowBy", this->m_usIGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usCapacity)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}

class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
};

extern void* __cdecl FUN_00aa1070(unsigned int);
extern void __cdecl FUN_00aa10f0(void*);
extern void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
extern void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct NiMemorySystem
{
    void* FUN_00aa3e40(unsigned int);
    void FUN_00aa4060(void*);
};
extern NiMemorySystem g_011f6238;

inline void* __cdecl operator new[](unsigned int n)
{
    return g_011f6238.FUN_00aa3e40(n);
}
inline void __cdecl operator delete[](void* p)
{
    g_011f6238.FUN_00aa4060(p);
}

extern const NiPoint3 DAT_011a9484;

struct NiScreenElementsDataShell : NiScreenElementsData
{
    unsigned int FUN_00a87ae0(unsigned short usVertices, unsigned short usTriangles, const unsigned short* pusTriList);
    void FUN_00a67090(unsigned int);
};

// @fnv 0x00a87ae0
unsigned int NiScreenElementsDataShell::FUN_00a87ae0(unsigned short usVertexCount, unsigned short usTriangleCount,
                                                     const unsigned short* pusTriangleList)
{
    if (usVertexCount < 3)
        return 0xffffffff;

    if (usTriangleCount > 0)
    {
        if (!pusTriangleList)
            return 0xffffffff;
    }
    if (usTriangleCount == 0)
    {
        usTriangleCount = usVertexCount - 2;
    }

    unsigned short usPolygonIndex;
    usPolygonIndex = m_usPQuantity++;
    if (m_usPQuantity > m_usMaxPQuantity)
    {
        unsigned short usNewMaxPolygons = m_usMaxPQuantity + m_usPGrowBy;
        NiScreenElementsData__Polygon* pkNewPolygons =
            (NiScreenElementsData__Polygon*)FUN_00aa1070(usNewMaxPolygons * sizeof(NiScreenElementsData__Polygon));
        FUN_00ec44d0(pkNewPolygons, m_akPolygon, m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon));
        FUN_00aa10f0(m_akPolygon);
        m_akPolygon = pkNewPolygons;

        unsigned short* pusNewIndexer = (unsigned short*)FUN_00aa1070(usNewMaxPolygons * sizeof(unsigned short));
        FUN_00ec44d0(pusNewIndexer, m_ausPIndexer, m_usMaxPQuantity * sizeof(unsigned short));
        FUN_00ec61c0(pusNewIndexer + m_usMaxPQuantity, 0xff,
                     (usNewMaxPolygons - m_usMaxPQuantity) * sizeof(unsigned short));
        FUN_00aa10f0(m_ausPIndexer);
        m_ausPIndexer = pusNewIndexer;
        m_usMaxPQuantity = usNewMaxPolygons;
    }

    NiScreenElementsData__Polygon* pkPolygon = &m_akPolygon[usPolygonIndex];
    pkPolygon->m_usVertexCount = usVertexCount;
    pkPolygon->m_usVertexOffset = m_usVertices;
    pkPolygon->m_usTriangleCount = usTriangleCount;
    pkPolygon->m_usTriangleIndexOffset = 3 * m_usTriangles;

    for (unsigned short i = 0; i < m_usPQuantity; i++)
    {
        if (m_ausPIndexer[i] == 0xffff)
        {
            m_ausPIndexer[i] = usPolygonIndex;
            usPolygonIndex = i;
            break;
        }
    }

    m_usVertices += pkPolygon->m_usVertexCount;
    int iVertexExcess = m_usVertices - m_usMaxVQuantity;
    if (iVertexExcess > 0)
    {
        float z;
        z = (float)iVertexExcess / (float)m_usVGrowBy;
        unsigned short usGrowCount = (unsigned short)(z + 0.5);
        unsigned short usNewMaxVertices = (usGrowCount + 1) * m_usVGrowBy + m_usMaxVQuantity;

        NiPoint3* akNewPolygon = new NiPoint3[usNewMaxVertices];
        unsigned int uiVertexBytes = m_usMaxVQuantity * sizeof(NiPoint3);
        FUN_00ec44d0(akNewPolygon, m_pkVertex, uiVertexBytes);
        delete[] m_pkVertex;
        m_pkVertex = akNewPolygon;

        if (m_pkNormal)
        {
            NiPoint3* y = new NiPoint3[usNewMaxVertices];
            FUN_00ec44d0(y, m_pkNormal, uiVertexBytes);
            delete[] m_pkNormal;
            m_pkNormal = y;
            for (unsigned short i = m_usMaxVQuantity; i < usNewMaxVertices; i++)
            {
                NiPoint3 a;
                a.x = -DAT_011a9484.x;
                a.y = -DAT_011a9484.y;
                a.z = -DAT_011a9484.z;
                m_pkNormal[i] = a;
            }
        }

        if (m_pkColor)
        {
            RgbaColor* pkNewColors;
            pkNewColors = new RgbaColor[usNewMaxVertices];
            FUN_00ec44d0(pkNewColors, m_pkColor, m_usMaxVQuantity * sizeof(RgbaColor));
            delete[] m_pkColor;
            m_pkColor = pkNewColors;
        }

        unsigned short usTextureSetCount = m_usTrianglePoints & 1;
        if (usTextureSetCount > 0)
        {
            NiPoint2* newTextures = new NiPoint2[usTextureSetCount * usNewMaxVertices];
            unsigned int uiTextureBytes = m_usMaxVQuantity * sizeof(NiPoint2);
            for (unsigned short i = 0; i < usTextureSetCount; i++)
            {
                FUN_00ec44d0(newTextures + i * m_usVertices, m_pkTexture + i * m_usVertices, uiTextureBytes);
            }
            delete[] m_pkTexture;
            m_pkTexture = newTextures;
        }

        m_usMaxVQuantity = usNewMaxVertices;
    }

    m_usTriangles += usTriangleCount;
    m_uiTriListLength += 3 * usTriangleCount;
    int idx;
    idx = 3 * m_usTriangles - m_usMaxIQuantity;
    if (idx > 0)
    {
        float fIndexGrowCount = (float)idx / (float)m_usIGrowBy;
        unsigned short usIndexGrowCount = (unsigned short)(fIndexGrowCount + 0.5);
        unsigned short usNewMaxIndices = (usIndexGrowCount + 1) * m_usIGrowBy + m_usMaxIQuantity;

        unsigned short* pusNewTriList = (unsigned short*)FUN_00aa1070(usNewMaxIndices * sizeof(unsigned short));
        FUN_00ec44d0(pusNewTriList, m_pusTriList, m_usMaxIQuantity * sizeof(unsigned short));
        FUN_00aa10f0(m_pusTriList);
        m_pusTriList = pusNewTriList;
        m_usMaxIQuantity = usNewMaxIndices;
    }

    unsigned short* pusTriListOut = &m_pusTriList[pkPolygon->m_usTriangleIndexOffset];
    if (pusTriangleList)
    {
        FUN_00ec44d0(pusTriListOut, pusTriangleList, 3 * (unsigned int)usTriangleCount * sizeof(unsigned short));
        for (unsigned int i = 0; i < 3 * (unsigned int)usTriangleCount; i++)
        {
            pusTriListOut[i] = pusTriangleList[i] + pkPolygon->m_usVertexOffset;
        }
    }
    else
    {
        for (unsigned short i = 0; i < usTriangleCount; i++)
        {
            *pusTriListOut++ = pkPolygon->m_usVertexOffset;
            *pusTriListOut++ = pkPolygon->m_usVertexOffset + i + 1;
            *pusTriListOut++ = i + pkPolygon->m_usVertexOffset + 2;
        }
    }

    FUN_00a67090(1);
    return usPolygonIndex;
}

struct FUN_00a881e0
{
    int* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    NiBound m_kBound;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    RgbaColor* m_pkColor;
    NiPoint2* m_pkTexture;
    void* m_spAdditionalGeomData;
    void* m_pkGeometryRendererData;
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
    bool m_bIsDynamic;
    bool m_bBoundDirty;
    bool m_bVerticesDirty;
    unsigned char unk3D;
    unsigned short unk3E;
    unsigned short m_usTriangles;
    unsigned int m_uiTriListLength;
    unsigned short* m_pusTriList;
    void* m_pkSharedNormalArray;
    unsigned short m_usSharedNormalCount;
    void* m_pkSharedNormalArrayMemoryBlock;
    NiScreenElementsData__Polygon* m_akPolygon;
    unsigned short* m_ausPIndexer;
    unsigned short m_usMaxPQuantity;
    unsigned short m_usPGrowBy;
    unsigned short m_usPQuantity;
    unsigned short m_usMaxVQuantity;
    unsigned short m_usVGrowBy;
    unsigned short m_usMaxIQuantity;
    unsigned short m_usIGrowBy;
    bool m_bGeometryInitialized;

    void FUN_00a7b690();
    FUN_00a881e0(bool bWantNormals, bool bWantColors, unsigned short usNumTextureSets, int iMaxPQuantity, int iPGrowBy,
                 int iMaxVQuantity, int iVGrowBy, int iMaxTQuantity, int iTGrowBy);
};
FNV_STATIC_ASSERT(offsetof(FUN_00a881e0, m_usTriangles) == 0x40);
FNV_STATIC_ASSERT(offsetof(FUN_00a881e0, m_akPolygon) == 0x58);
FNV_STATIC_ASSERT(offsetof(FUN_00a881e0, m_bGeometryInitialized) == 0x6e);

class NiPoint3Ctor : public NiPoint3
{
  public:
    NiPoint3Ctor()
    {}
};
class NiPoint2Ctor : public NiPoint2
{
  public:
    NiPoint2Ctor()
    {}
};

static inline NiPoint3 NegatePoint(const NiPoint3& p)
{
    NiPoint3 r;
    r.x = -p.x;
    r.y = -p.y;
    r.z = -p.z;
    return r;
}

// Initialises the screen-elements data: allocates polygon, indexer, vertex, normal, colour and texture arrays from the given capacities and clears the counts.
// @fnv 0x00a881e0
FUN_00a881e0::FUN_00a881e0(bool bWantNormals, bool bWantColors, unsigned short usNumTextureSets, int iMaxPQuantity,
                           int iPGrowBy, int iMaxVQuantity, int iVGrowBy, int iMaxTQuantity, int iTGrowBy)
{
    FUN_00a7b690();
    m_ppVirtualMethodTable = &DAT_0109ea94;

    m_usMaxPQuantity = (unsigned short)(iMaxPQuantity > 0 ? iMaxPQuantity : 1);
    m_usPGrowBy = (unsigned short)(iPGrowBy > 0 ? iPGrowBy : 1);
    m_usPQuantity = 0;
    m_akPolygon =
        (NiScreenElementsData__Polygon*)FUN_00aa1070(m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon));
    m_ausPIndexer = (unsigned short*)FUN_00aa1070(m_usMaxPQuantity * sizeof(unsigned short));
    FUN_00ec61c0(m_ausPIndexer, 0xff, m_usMaxPQuantity * sizeof(unsigned short));

    m_usMaxVQuantity = (unsigned short)(iMaxVQuantity > 0 ? iMaxVQuantity : 1);
    m_usVGrowBy = (unsigned short)(iVGrowBy > 0 ? iVGrowBy : 1);
    m_usVertices = 0;
    m_pkVertex = new NiPoint3Ctor[m_usMaxVQuantity];

    if (bWantNormals)
    {
        m_pkNormal = new NiPoint3Ctor[m_usMaxVQuantity];
        for (unsigned short i = 0; i < m_usMaxVQuantity; i++)
            m_pkNormal[i] = NegatePoint(DAT_011a9484);
    }
    else
    {
        m_pkNormal = 0;
    }

    m_pkColor = bWantColors ? new RgbaColor[m_usMaxVQuantity] : 0;

    if (usNumTextureSets > 0)
    {
        m_pkTexture = new NiPoint2Ctor[m_usMaxVQuantity * usNumTextureSets];
        m_usTrianglePoints = (m_usTrianglePoints & ~1) | (usNumTextureSets & 1);
    }
    else
    {
        m_pkTexture = 0;
    }

    m_usMaxIQuantity = (unsigned short)(iMaxTQuantity > 0 ? 3 * iMaxTQuantity : 3);
    m_usIGrowBy = (unsigned short)(iTGrowBy > 0 ? 3 * iTGrowBy : 3);
    m_usTriangles = 0;
    m_uiTriListLength = 0;
    m_pusTriList = (unsigned short*)FUN_00aa1070(m_usMaxIQuantity * sizeof(unsigned short));
    m_bGeometryInitialized = false;
}

struct NiBinaryStream485
{
    void* m_pContext;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream485* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void NiBinaryStreamLoad485(NiBinaryStream485* pkStream, T* pkValue, unsigned int ItemUpdateArray)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pkValue, ItemUpdateArray * uiSize, &uiSize, 1);
}
struct NiStream485
{
    NiBinaryStream485* GetIStr() const
    {
        return *reinterpret_cast<NiBinaryStream485* const*>(reinterpret_cast<const char*>(this) + 0x24c);
    }
};
template <class T> inline void NiStreamLoadBinary485(NiStream485& kStream, T& kValue)
{
    NiBinaryStreamLoad485(kStream.GetIStr(), &kValue, 1);
}
template <class T> inline void NiStreamLoadBinary485(NiStream485& kStream, T* pkValue, unsigned int ItemUpdateArray)
{
    NiBinaryStreamLoad485(kStream.GetIStr(), pkValue, ItemUpdateArray);
}
void* __cdecl FUN_00aa1070(unsigned int bytes);
struct FUN_00a88410_shell : NiScreenElementsData
{
    void FUN_00a7b940(NiStream485& kStream);
    void LoadScreenElementsData(NiStream485& kStream);
};
// @fnv 0x00a88410
void FUN_00a88410_shell::LoadScreenElementsData(NiStream485& kStream)
{
    FUN_00a7b940(kStream);
    NiStreamLoadBinary485(kStream, m_usMaxPQuantity);
    m_akPolygon = static_cast<NiScreenElementsData__Polygon*>(
        FUN_00aa1070(m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon)));
    m_ausPIndexer = static_cast<unsigned short*>(FUN_00aa1070(m_usMaxPQuantity * sizeof(unsigned short)));

    unsigned int uiPolygonCount = m_usMaxPQuantity;
    NiStreamLoadBinary485(kStream, m_akPolygon, uiPolygonCount);
    NiStreamLoadBinary485(kStream, m_ausPIndexer, uiPolygonCount);
    NiStreamLoadBinary485(kStream, m_usPGrowBy);
    NiStreamLoadBinary485(kStream, m_usPQuantity);
    NiStreamLoadBinary485(kStream, m_usMaxVQuantity);
    NiStreamLoadBinary485(kStream, m_usVGrowBy);
    NiStreamLoadBinary485(kStream, m_usMaxIQuantity);
    NiStreamLoadBinary485(kStream, m_usIGrowBy);
}

struct NiBinaryStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                       unsigned int uiNumComponents)
    {
        unsigned int uiWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};
class NiStream
{
  public:
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034,
        unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074,
        unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4,
        unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4,
        unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234,
        unk238, unk23c;
    int unk240, unk244, unk248, unk24c;
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T& kValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.m_pBackingStream, pValue, uiNumEls);
}
struct FUN_00a7bbe0_shell
{
    void FUN_00a7bbe0(NiStream* apStream);
};
struct FUN_00a88590_shell : public NiScreenElementsData
{
    void WriteToStream(NiStream& kStream);
};
// Writes the base screen elements data and the polygon, indexer and quantity fields to the binary stream.
// @fnv 0x00a88590
void FUN_00a88590_shell::WriteToStream(NiStream& kStream)
{
    ((FUN_00a7bbe0_shell*)this)->FUN_00a7bbe0(&kStream);
    SerializeValue(kStream, m_usMaxPQuantity);
    unsigned int uiPolygonCount = m_usMaxPQuantity;
    SerializeValue(kStream, m_akPolygon, uiPolygonCount);
    SerializeValue(kStream, m_ausPIndexer, uiPolygonCount);
    SerializeValue(kStream, m_usPGrowBy);
    SerializeValue(kStream, m_usPQuantity);
    SerializeValue(kStream, m_usMaxVQuantity);
    SerializeValue(kStream, m_usVGrowBy);
    SerializeValue(kStream, m_usMaxIQuantity);
    SerializeValue(kStream, m_usIGrowBy);
}

#include <string.h>
struct TriShapeDataEq : public NiTriShapeData
{
    bool IsEqualBase(const TriShapeDataEq*);
};

struct FUN_00a87980_shell : public NiScreenElementsData
{
    bool IsEqual(const FUN_00a87980_shell* pkOther);
};

// Compares this NiScreenElementsData with pkOther, checking base equality, quantity fields, polygon data, and polygon index arrays.
// @fnv 0x00a87980
bool FUN_00a87980_shell::IsEqual(const FUN_00a87980_shell* pkOther)
{
    if (!((TriShapeDataEq*)this)->IsEqualBase((const TriShapeDataEq*)pkOther))
        return false;

    if (m_usMaxPQuantity != pkOther->m_usMaxPQuantity || m_usPGrowBy != pkOther->m_usPGrowBy ||
        m_usPQuantity != pkOther->m_usPQuantity || m_usMaxVQuantity != pkOther->m_usMaxVQuantity ||
        m_usVGrowBy != pkOther->m_usVGrowBy || m_usMaxIQuantity != pkOther->m_usMaxIQuantity ||
        m_usIGrowBy != pkOther->m_usIGrowBy)
        return false;

    if (memcmp(m_akPolygon, pkOther->m_akPolygon, m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon)) != 0)
        return false;

    if (memcmp(m_ausPIndexer, pkOther->m_ausPIndexer, m_usMaxPQuantity * sizeof(unsigned short)) != 0)
        return false;

    return true;
}

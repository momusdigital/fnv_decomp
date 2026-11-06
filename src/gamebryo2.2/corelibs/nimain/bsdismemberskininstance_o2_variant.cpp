
// src/gamebryo2.2/corelibs/nimain/bsdismemberskininstance_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/bsdismemberskininstance.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "original_bsdismemberskininstance.h"
const NiRTTI BSDismemberSkinInstance::ms_kRTTI;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct _Call_a5d3a0
{
    _Call_a5d3a0();
};
extern int DAT_01069a84;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00a6c8a0
BSDismemberSkinInstance* FUN_00a6c8a0()
{
    BSDismemberSkinInstance* p = (BSDismemberSkinInstance*)BSFadeNode::operator new(0x40);
    if (p)
    {
        new (p) _Call_a5d3a0;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 12) = 0;
        *(int*)((char*)p + 16) = 0;
        *(int*)((char*)p + 20) = 0;
        *(int*)((char*)p + 28) = 0;
        *(int*)((char*)p + 32) = 0;
        *(int*)((char*)p + 36) = 0;
        *(int*)((char*)p + 40) = 0;
        *(int*)((char*)p + 48) = 0;
        *(int*)((char*)p + 52) = 0;
        *(int*)((char*)p + 56) = 0;
        *(int*)((char*)p + 24) = -1;
        *(void**)p = (void*)&DAT_01069a84;
        return p;
    }
    return 0;
}

struct P03MM
{
    void* Allocate(unsigned int);
};

extern P03MM _g_memoryManager;

struct BytePairWord
{
    unsigned char uc1;
    unsigned char uc2;
    unsigned short m_usTrailingValue;

    static void* operator new[](unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
};

struct S00a6c720
{
    char _pad[0x34];
    unsigned int m_uiNumEntries;
    BytePairWord* m_pEntries;
    bool m_bStateFlag;

    void CopyRefCountedPointers(S00a6c720* pkDest, void* kCloning);
    void FUN_00a6c720(S00a6c720* pkDest, void* kCloning);
};

// @fnv 0x00a6c720
void S00a6c720::FUN_00a6c720(S00a6c720* pkDest, void* kCloning)
{
    CopyRefCountedPointers(pkDest, kCloning);

    pkDest->m_uiNumEntries = m_uiNumEntries;
    if (m_uiNumEntries > 0)
    {
        pkDest->m_pEntries = new BytePairWord[m_uiNumEntries];
        for (unsigned int ui = 0; ui < m_uiNumEntries; ++ui)
        {
            pkDest->m_pEntries[ui].uc1 = m_pEntries[ui].uc1;
            pkDest->m_pEntries[ui].uc2 = m_pEntries[ui].uc2;
            pkDest->m_pEntries[ui].m_usTrailingValue = m_pEntries[ui].m_usTrailingValue;
        }
    }
    else
    {
        pkDest->m_pEntries = 0;
    }
    pkDest->m_bStateFlag = m_bStateFlag;
}

struct NiTStringPointerMap_00e93020
{
    bool GetAt(void*, void*&);
};

struct CloningProcess
{
    NiTStringPointerMap_00e93020* m_pCloneMap;
};

void* _NiMalloc(unsigned int);

struct SkinData
{
    char _pad[0x44];
    unsigned int m_uiBoneCount;
};

struct S00a6c7c0 : _Call_a5d3a0
{
    void* m_pvtable;              // +0x00
    void* m_pv4;                  // +0x04
    SkinData* m_pSkinData;        // +0x08
    void* m_pkSkinMeshPartition;  // +0x0c
    void* m_spRootParent;         // +0x10
    void** m_ppBones;             // +0x14
    int m_iIndex;                 // +0x18
    void* m_pv1c;                 // +0x1c
    void* m_pv20;                 // +0x20
    void* m_pv24;                 // +0x24
    void* m_pv28;                 // +0x28
    int m_i2c;                    // +0x2c
    void* m_pv30;                 // +0x30
    unsigned int m_uiNumEntries;  // +0x34
    void* m_pEntries;             // +0x38
    int m_i3c;                    // +0x3c

    S00a6c7c0() throw();

    static void* operator new(unsigned int size) throw()
    {
        return BSFadeNode::operator new(size);
    }

    void FUN_00a6c720(S00a6c7c0* pkDest, CloningProcess& kCloning);
    S00a6c7c0* CreateClone(CloningProcess& kCloning);
};

S00a6c7c0::S00a6c7c0() throw()
    : m_pSkinData(0), m_pkSkinMeshPartition(0), m_spRootParent(0), m_ppBones(0), m_iIndex(-1), m_pv1c(0), m_pv20(0),
      m_pv24(0), m_pv28(0), m_pv30(0)
{
    m_pvtable = &DAT_01069a84;
    m_uiNumEntries = 0;
    m_pEntries = 0;
}

// @fnv 0x00a6c7c0
S00a6c7c0* S00a6c7c0::CreateClone(CloningProcess& kCloning)
{
    S00a6c7c0* pkSkinInstance = new S00a6c7c0();
    FUN_00a6c720(pkSkinInstance, kCloning);

    void* pkClone = 0;
    pkSkinInstance->m_spRootParent = kCloning.m_pCloneMap->GetAt(m_spRootParent, pkClone) ? pkClone : m_spRootParent;

    unsigned int uiBoneCount = m_pSkinData->m_uiBoneCount;
    pkSkinInstance->m_ppBones = (void**)_NiMalloc(uiBoneCount * sizeof(void*));

    for (unsigned int i = 0; i < uiBoneCount; ++i)
    {
        pkSkinInstance->m_ppBones[i] = kCloning.m_pCloneMap->GetAt(m_ppBones[i], pkClone) ? pkClone : m_ppBones[i];
    }

    return pkSkinInstance;
}

class A6C900Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern A6C900Heap g_memoryManager;

struct A6C900BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(A6C900BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class A6C900Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    A6C900BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void A6C900BinaryStreamLoad(A6C900BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A6C900LoadBinary(A6C900Stream& kStream, T& value)
{
    A6C900BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct A6C900Partition
{
    unsigned char m_ucFlags;
    unsigned char m_ucBones;
    unsigned short m_usVertices;

    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
};

template <class T>
inline void A6C900BinaryStreamLoad(A6C900BinaryStream& kIstr, T* pValue, unsigned int uiNumEls,
                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    kIstr.BinaryRead(pValue, uiNumEls * sizeof(T), puiComponentSizes, uiNumComponents);
}

class A6C900SkinBase
{
  public:
    void LoadBinary(A6C900Stream& kStream);
};

class A6C900Skin : public A6C900SkinBase
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
    unsigned int m_uiPartitionCount;
    A6C900Partition* m_pPartitions;
    unsigned char m_ucFlags;

    void FUN_00a6c900(A6C900Stream& kStream);
};

// @fnv 0x00a6c900
void A6C900Skin::FUN_00a6c900(A6C900Stream& kStream)
{
    A6C900SkinBase::LoadBinary(kStream);
    A6C900LoadBinary(kStream, m_uiPartitionCount);
    m_pPartitions = new A6C900Partition[m_uiPartitionCount];
    unsigned int auiComponentSizes[3] = {1, 1, 2};
    A6C900BinaryStreamLoad(*kStream.m_pUnderlyingStream, m_pPartitions, m_uiPartitionCount, auiComponentSizes, 3);
    m_ucFlags = 0;
    for (unsigned int i = 0; i < m_uiPartitionCount; i++)
        m_ucFlags |= m_pPartitions[i].m_ucFlags;
}

int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
char* CreateDebugString(const char* pcName);
char* CreateDebugString(const char* pcName, unsigned int uiValue);
char* CreateDebugString(const char* pcName, bool bValue);

template <class T> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

template <class T> inline void NiTPrimitiveArray<T>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0)
            m_usESize++;
    }
    else
    {
        if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

extern NiRTTI g_kDismemberSkinRTTI;

struct BodyPartData
{
    unsigned char ucEnabled;
    unsigned char ucStartNetBoneSet;
    unsigned short usPartID;
};

struct NiSkinInstanceStub
{
    void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
};

struct BSDismemberSkinInstanceStub : NiSkinInstanceStub
{
    void* m_pvtable;
    void* m_pv04;
    void* m_pSkinData;
    void* m_pkSkinMeshPartition;
    void* m_pRootParent;
    void** m_ppBones;
    int m_iIndex;
    void* m_pv1c;
    void* m_pv20;
    void* m_pv24;
    void* m_pv28;
    int m_i2c;
    void* m_pv30;
    unsigned int m_uiNumEntries;
    BodyPartData* m_pEntries;
    bool m_bStateFlag;

    void FUN_00a6cac0(NiTPrimitiveArray<char*>* pkStrings);
};

// @fnv 0x00a6cac0
void BSDismemberSkinInstanceStub::FUN_00a6cac0(NiTPrimitiveArray<char*>* pkStrings)
{
    NiSkinInstanceStub::GetViewerStrings(pkStrings);

    pkStrings->Add(CreateDebugString(g_kDismemberSkinRTTI.m_pcName));
    pkStrings->Add(CreateDebugString("Num Partitions", m_uiNumEntries));
    pkStrings->Add(CreateDebugString("Visible", m_bStateFlag));

    for (unsigned int i = 0; i < m_uiNumEntries; i++)
    {
        BodyPartData& kData = m_pEntries[i];
        char acTemp[64];
        sprintf_s(acTemp, 64, "%d = BodyPart %d [%s%s]", i, kData.usPartID, kData.ucEnabled ? "Enabled" : "Disabled",
                  kData.ucStartNetBoneSet ? ", State Change" : "");
        pkStrings->Add(CreateDebugString(acTemp));
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
extern "C" void _ReadWriteBarrier();

struct OutputBinary
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    void* m_read;
    unsigned int(__cdecl* m_write)(OutputBinary*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(__cdecl* Writer)(OutputBinary*, void*, unsigned int, unsigned int*, unsigned int);
    void Write(void* data, unsigned int bytes)
    {

        unsigned int size = 4;
        m_uiStreamFlags += m_write(this, data, bytes, &size, 1);
    }
};
struct OutputStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m_bLittleEndian;
    unsigned char unk1E5;
    unsigned short unk1E6;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    OutputBinary* m_pRayCastOutput;
};

static inline void Swap16(unsigned short& value)
{
    value = _byteswap_ushort(value);
}
static inline void Swap32(BodyPartData& value)
{
    unsigned int* p = reinterpret_cast<unsigned int*>(&value);
    unsigned int in = *p;
    _ReadWriteBarrier();
    *p = _byteswap_ulong(in);
}
struct DismemberOutput : BSDismemberSkinInstanceStub
{
    void SaveSkinInstance(OutputStream&);
    void SaveBinary(OutputStream&);
};
// @fnv 0x00a6c9c0
void DismemberOutput::SaveBinary(OutputStream& stream)
{
    SaveSkinInstance(stream);
    {
        stream.m_pRayCastOutput->Write(&m_uiNumEntries, 4);
    }
    if (stream.m_bLittleEndian != 1)
    {
        for (unsigned int i = 0; i < m_uiNumEntries;)
        {
            unsigned int j = i;
            Swap16(m_pEntries[j].usPartID);
            ++i;
            Swap32(m_pEntries[j]);
        }
    }
    {
        stream.m_pRayCastOutput->Write(m_pEntries, m_uiNumEntries * 4);
    }
    if (stream.m_bLittleEndian != 1)
    {
        for (unsigned int i = 0; i < m_uiNumEntries; ++i)
        {
            Swap32(m_pEntries[i]);
            Swap16(m_pEntries[i].usPartID);
        }
    }
}

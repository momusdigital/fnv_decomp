
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Placeholder declarations
extern int DAT_010f1008;
extern int DAT_0126fa34;
void __cdecl FUN_00e98710();
void __cdecl _delete(void*, unsigned int);

struct NiUnsharedGeometryGroup
{
    void* m_ppVirtualMethodTable;
    virtual ~NiUnsharedGeometryGroup();
    void* __thiscall Destroy(unsigned int flags);
};

// Restores the vtable, clears the global pointer if it refers to this object, calls FUN_00e98710, and optionally deletes the object.
// @fnv 0x00e94d30
void* __thiscall NiUnsharedGeometryGroup::Destroy(unsigned int flags)
{
    NiUnsharedGeometryGroup* pThis = this;
    *(void**)pThis = &DAT_010f1008;
    if (pThis == *(void**)&DAT_0126fa34)
        *(void**)&DAT_0126fa34 = 0;
    FUN_00e98710();
    if (flags & 1)
        _delete(pThis, 0xc);
    return pThis;
}

struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int DAT_01400000;
struct NiGeometryBufferData
{
    NiGeometryBufferData();
};
__forceinline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct S
{
    void __thiscall CreateScreenTextureBufferData(NiScreenTexture* pkScreenTexture);
    void __thiscall FUN_00e98730(NiGeometryBufferData* pkBuffData);
};
// @fnv 0x00e94de0
void __thiscall S::CreateScreenTextureBufferData(NiScreenTexture* pkScreenTexture)
{
    if (*(int*)((char*)pkScreenTexture + 0x1c) == 0)
    {
        void* pMemory = g_memoryManager.Allocate(0x54);
        NiGeometryBufferData* pkBuffData = pMemory ? new (pMemory) NiGeometryBufferData() : 0;
        *(int*)((char*)pkBuffData + 0x3c) = 4;
        *(NiGeometryBufferData**)((char*)pkScreenTexture + 0x1c) = pkBuffData;
        *(int*)((char*)pkBuffData + 4) = (int)&DAT_01400000;
        FUN_00e98730(pkBuffData);
    }
}

struct FakeVB
{
    virtual void __stdcall F0();
    virtual void __stdcall F1();
    virtual unsigned long __stdcall Release();
};
// Releases the vertex buffer chip for the given stream index, clears its slot and deletes the chip.
// @fnv 0x00e94ee0
void __stdcall FUN_00e94ee0(NiGeometryBufferData* pkBuffData, unsigned int uiStreamIndex)
{
    NiVBChip* pkChip;
    if (uiStreamIndex < *(unsigned int*)((char*)pkBuffData + 0x20))
    {
        pkChip = ((NiVBChip**)*(void**)((char*)pkBuffData + 0x28))[uiStreamIndex];
        if (pkChip)
        {
            if (*(FakeVB**)((char*)pkChip + 8))
                ((FakeVB*)*(void**)((char*)pkChip + 8))->Release();
            if (uiStreamIndex < *(unsigned int*)((char*)pkBuffData + 0x20))
                ((NiVBChip**)*(void**)((char*)pkBuffData + 0x28))[uiStreamIndex] = 0;
            *(void**)((char*)pkChip + 8) = 0;
            _delete(pkChip, 0x20);
        }
    }
}

void* _fnv_zlib_memset(void*, int, unsigned int);
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e950f0(NiGeometryData* pkData);
};
struct Deleter
{
    virtual ~Deleter();
};
// Removes pkData's buffer data from the group, clears its buffer array, deletes it, and nulls the pointer.
// @fnv 0x00e950f0
void NiDynamicGeometryGroup::FUN_00e950f0(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x34);
    if (pkBuffData)
    {
        NiGeometryGroup::RemoveObject(pkBuffData);
        if (*(void**)((char*)pkBuffData + 0x28))
            _fnv_zlib_memset(*(void**)((char*)pkBuffData + 0x28), 0, *(unsigned int*)((char*)pkBuffData + 0x20) * 4);
        delete (Deleter*)pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x34) = 0;
    }
}

namespace fnv_00e95140 {
struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;

void* _fnv_zlib_memset(void*, int, unsigned int);
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiGeometryBufferData
{
    virtual ~NiGeometryBufferData();
    char _pad04[28];
    unsigned int m_uiRegisterStreamCount;
    unsigned int _pad24;
    NiVBChip** m_ppkVertexBuffers;
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e95140(NiGeometryData* pkData);
};
// Removes the geometry buffer data stored at offset 0x28 of pkData, clears its chip array, deletes it and nulls the pointer.
// @fnv 0x00e95140
void NiDynamicGeometryGroup::FUN_00e95140(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x28);
    if (pkBuffData)
    {
        NiGeometryGroup::RemoveObject(pkBuffData);
        if (pkBuffData->m_ppkVertexBuffers)
            _fnv_zlib_memset(pkBuffData->m_ppkVertexBuffers, 0, pkBuffData->m_uiRegisterStreamCount * 4);
        delete pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x28) = 0;
    }
}
}  // namespace fnv_00e95140

namespace fnv_00e95190 {
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e95190(NiGeometryData* pkData);
};
void* _fnv_zlib_memset(void*, int, unsigned int);
struct DeleteHelper
{
    virtual ~DeleteHelper();
};
// @fnv 0x00e95190
void NiDynamicGeometryGroup::FUN_00e95190(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x1c);
    if (pkBuffData)
    {
        RemoveObject(pkBuffData);
        void* p = *(void**)((char*)pkBuffData + 0x28);
        if (p)
            _fnv_zlib_memset(p, 0, *(unsigned int*)((char*)pkBuffData + 0x20) * 4);
        delete (DeleteHelper*)pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x1c) = 0;
    }
}
}  // namespace fnv_00e95190

extern int DAT_010f1008;
extern int DAT_0126fa34;
void __cdecl FUN_00e98710();
void __cdecl _delete(void*, unsigned int);
struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;
extern P03MM g_memoryManager;
extern int DAT_01400000;
void __stdcall FUN_00e94ee0(NiGeometryBufferData* pkBuffData, unsigned int uiStream);
void* _fnv_zlib_memset(void*, int, unsigned int);
struct BufEntry
{
    int unk00;
    int unk04;
    int unk08;
    FakeVB* unk0C;
    FakeVB* unk10;
    int unk14;
};
struct OwnerEntry
{
    int unk00;
    int unk04;
    int unk08;
};
template <class TVAL> struct MapItem
{
    MapItem* m_pkNext;
    const char* m_key;
    TVAL m_val;
};
template <class TVAL> struct StrMap
{
    typedef MapItem<TVAL> Item;
    virtual ~StrMap();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    unsigned int m_uiCount;

    bool RemoveAt(const char* key);

    Item* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(Item*& pos, const char*& key, TVAL& val) const
    {
        Item* item = pos;
        key = item->m_key;
        val = item->m_val;
        if (item->m_pkNext)
        {
            pos = item->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(item->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            Item* p = m_ppkHashTable[i];
            if (p)
            {
                pos = p;
                return;
            }
        }
        pos = 0;
    }
};
template <class T> struct PtrArray
{
    virtual ~PtrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned short GetAllocatedSize() const
    {
        return m_usMaxSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    T RemoveAt(unsigned int i)
    {
        if (i >= m_usSize)
            return 0;
        T e = m_pBase[i];
        m_pBase[i] = 0;
        if (e != 0)
            m_usESize--;
        if (i == (unsigned short)(m_usSize - 1))
            m_usSize--;
        return e;
    }
};
struct BufferManager
{
    int unk00;
    int unk04;
    int unk08;
    StrMap<BufEntry*> m_kBuffers;
    StrMap<OwnerEntry*> m_kOwners;
    PtrArray<BufEntry*> m_kBufArray;
    PtrArray<OwnerEntry*> m_kOwnerArray;

    void ClearBuffers();
};
// @fnv 0x00e94f30
void BufferManager::ClearBuffers()
{
    StrMap<BufEntry*>::Item* pos = m_kBuffers.GetFirstPos();
    while (pos)
    {
        const char* key;
        BufEntry* val;
        m_kBuffers.GetNext(pos, key, val);
        m_kBuffers.RemoveAt(key);
        if (val)
        {
            FakeVB* vb = val->unk10;
            if (vb)
                vb->Release();
            vb = val->unk0C;
            if (vb)
                vb->Release();
            _delete(val, sizeof(BufEntry));
        }
    }

    StrMap<OwnerEntry*>::Item* pOwnerPos = m_kOwners.GetFirstPos();
    while (pOwnerPos)
    {
        const char* key;
        OwnerEntry* val;
        m_kOwners.GetNext(pOwnerPos, key, val);
        val->unk08 = 0;
    }

    for (unsigned int i = 0; i < m_kBufArray.GetAllocatedSize(); i++)
    {
        BufEntry* p = m_kBufArray.RemoveAt(i);
        if (p)
        {
            FakeVB* vb = p->unk10;
            if (vb)
                vb->Release();
            vb = p->unk0C;
            if (vb)
                vb->Release();
            _delete(p, sizeof(BufEntry));
        }
        m_kOwnerArray.GetAt(i)->unk08 = 0;
    }
}

struct IDirect3DVertexBuffer9_E94;
struct IDirect3DDevice9_E94
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall TestCooperativeLevel();
    virtual unsigned int __stdcall GetAvailableTextureMem();
    virtual long __stdcall EvictManagedResources();
    virtual long __stdcall GetDirect3D(void**);
    virtual long __stdcall GetDeviceCaps(void*);
    virtual long __stdcall GetDisplayMode(unsigned int, void*);
    virtual long __stdcall GetCreationParameters(void*);
    virtual long __stdcall SetCursorProperties(unsigned int, unsigned int, void*);
    virtual void __stdcall SetCursorPosition(int, int, unsigned long);
    virtual int __stdcall ShowCursor(int);
    virtual long __stdcall CreateAdditionalSwapChain(void*, void**);
    virtual long __stdcall GetSwapChain(unsigned int, void**);
    virtual unsigned int __stdcall GetNumberOfSwapChains();
    virtual long __stdcall Reset(void*);
    virtual long __stdcall Present(const void*, const void*, void*, const void*);
    virtual long __stdcall GetBackBuffer(unsigned int, unsigned int, int, void**);
    virtual long __stdcall GetRasterStatus(unsigned int, void*);
    virtual long __stdcall SetDialogBoxMode(int);
    virtual void __stdcall SetGammaRamp(unsigned int, unsigned long, const void*);
    virtual void __stdcall GetGammaRamp(unsigned int, void*);
    virtual long __stdcall CreateTexture(unsigned int, unsigned int, unsigned int, unsigned long, int, int, void**,
                                         void**);
    virtual long __stdcall CreateVolumeTexture(unsigned int, unsigned int, unsigned int, unsigned int, unsigned long,
                                               int, int, void**, void**);
    virtual long __stdcall CreateCubeTexture(unsigned int, unsigned int, unsigned long, int, int, void**, void**);
    virtual long __stdcall CreateVertexBuffer(unsigned int Length, unsigned long Usage, unsigned long FVF, int Pool,
                                              IDirect3DVertexBuffer9_E94** ppVB, void** pSharedHandle);
};
extern bool DAT_0126f0d0;
class NiMemObject_E94
{
  public:
    static void* operator new(unsigned int uiSize);
};
class NiVBChipE94 : public NiMemObject_E94
{
  public:
    NiVBChipE94()
    {
        m_pkTreeBlock = 0;
        m_uiPosition = 0;
        m_pkOwningStream = 0;
        m_pkPrev = 0;
        m_uiSize = 0;
        m_pkNext = 0;
        m_uiValueBeforeCount = 0;
        m_pUserData = 0;
    }
    void* m_pkTreeBlock;
    unsigned int m_uiPosition;
    IDirect3DVertexBuffer9_E94* m_pkOwningStream;
    NiVBChipE94* m_pkPrev;
    NiVBChipE94* m_pkNext;
    unsigned int m_uiSize;
    unsigned int m_uiValueBeforeCount;
    void* m_pUserData;
};
struct NiBuffDataE94
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiGroupIndex;
    int unk10;
    bool m_bIsInitialized;
    int unk18;
    unsigned int m_uiVertexCount;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    unsigned int GetVertexStride(unsigned int uiStream) const
    {
        return uiStream < m_uiRegisterStreamCount ? m_puiVertexStrides[uiStream] : 0;
    }
};
class NiUnsharedGeometryGroupE94
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    IDirect3DDevice9_E94* m_pDirect3DDevice;
    NiVBChipE94* CreateChip(NiBuffDataE94* pkBuffData, unsigned int uiStream);
};

// Creates a D3D vertex buffer sized for the stream and returns a new NiVBChipE94 wrapping it with the given size and owning stream.
// @fnv 0x00e94e30
NiVBChipE94* NiUnsharedGeometryGroupE94::CreateChip(NiBuffDataE94* pkBuffData, unsigned int uiStream)
{
    unsigned int uiVertexCount = pkBuffData->m_uiVertexCount;
    unsigned int uiVBSize = pkBuffData->GetVertexStride(uiStream) * uiVertexCount;
    unsigned int uiUsage = 0x8;
    if (pkBuffData->m_bIsInitialized)
        uiUsage = 0x8 | 0x10;
    IDirect3DVertexBuffer9_E94* pkVB;
    m_pDirect3DDevice->CreateVertexBuffer(uiVBSize, uiUsage, pkBuffData->m_uiGroupIndex, DAT_0126f0d0 ? 0 : 1, &pkVB,
                                          0);
    IDirect3DVertexBuffer9_E94* pkNewVB = pkVB;
    NiVBChipE94* pkChip = new NiVBChipE94;
    if (pkChip)
    {
        pkChip->m_pkOwningStream = pkNewVB;
        pkChip->m_uiSize = uiVBSize;
        pkChip->m_pkTreeBlock = 0;
        pkChip->m_uiPosition = 0;
        pkChip->m_pkPrev = 0;
        pkChip->m_pkNext = 0;
    }
    return pkChip;
}

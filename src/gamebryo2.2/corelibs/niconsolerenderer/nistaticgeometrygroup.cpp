
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiGeometryBufferData
{
    virtual ~NiGeometryBufferData();
};
struct FUN_00e94740_Param
{
    char _pad[0x34];
    NiGeometryBufferData* buf;
};
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
    void RemoveAndDeleteBuffer(FUN_00e94740_Param*);
};
// If p->buf is set, removes it from the group, deletes it, and clears p->buf.
// @fnv 0x00e94740
void NiGeometryGroup::RemoveAndDeleteBuffer(FUN_00e94740_Param* p)
{
    NiGeometryBufferData* q = p->buf;
    if (q)
    {
        RemoveObject(q);
        delete q;
        p->buf = 0;
    }
}

namespace fnv_00e94770 {
struct FUN_00e94490_Holder
{
    void __thiscall FUN_00e94490(void* a, unsigned int b);
};
struct NiVBBlock
{
    FUN_00e94490_Holder* field0;
    void* field1;
};
struct NiVBChip
{
    unsigned int m_uiPosition;
    NiVBBlock* m_pkTreeBlock;
    void* m_pkOwningStream;
};
struct NiGeometryBufferData
{
    unsigned char _pad[0x20];
    unsigned int m_uiRegisterStreamCount;
    unsigned char _pad2[4];
    NiVBChip** m_ppkVertexBuffers;
};
// @fnv 0x00e94770
void __stdcall ReleaseChip(NiGeometryBufferData* pkBuffData, unsigned int uiStream)
{
    NiVBChip* pkChip;
    NiVBBlock* pkBlock;
    if (uiStream < pkBuffData->m_uiRegisterStreamCount)
    {
        pkChip = pkBuffData->m_ppkVertexBuffers[uiStream];
        if (pkChip)
        {
            if (pkChip->m_pkOwningStream)
            {
                pkBlock = pkChip->m_pkTreeBlock;
                pkBlock->field0->FUN_00e94490(pkBlock->field1, pkChip->m_uiPosition);
            }
            if (uiStream < pkBuffData->m_uiRegisterStreamCount)
                pkBuffData->m_ppkVertexBuffers[uiStream] = 0;
        }
    }
}
}  // namespace fnv_00e94770

struct NiTMapBaseStub
{
    void* vtbl;
    int unk4;
    void* unk8;
    void RemoveAll();
};
void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0f94;
extern int DAT_010f0fb4;
extern int DAT_010f0fd4;
struct NiStaticGeometryGroup
{
    void* vtbl;
    char _04[8];
    NiTMapBaseStub map;
    void Purge();
    void FUN_00e98710();
    void* Destroy(unsigned int);
};
// Resets vtables, clears the map at offset 12, frees its buffer, calls cleanup, and optionally deletes the object.
// @fnv 0x00e94890
void* NiStaticGeometryGroup::Destroy(unsigned int flag)
{
    vtbl = (void*)&DAT_010f0fd4;
    Purge();
    NiTMapBaseStub* pSets = (NiTMapBaseStub*)((char*)this + 12);
    pSets->vtbl = (void*)&DAT_010f0fb4;
    pSets->RemoveAll();
    pSets->vtbl = (void*)&DAT_010f0f94;
    pSets->RemoveAll();
    _NiFreeAlias(pSets->unk8);
    FUN_00e98710();
    if (flag & 1)
        _delete(this, 0x1c);
    return this;
}

struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
void __cdecl _NiFreeAlias(void*);
extern int DAT_010f0f84;
struct S
{
    void* f0;
    void* f4;
    void* FUN_00e94a80(unsigned int);
};
// Sets f0 to DAT_010f0f84, frees f4, and if flag bit 0 is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00e94a80
void* S::FUN_00e94a80(unsigned int flag)
{
    void* tmp = f4;
    f0 = &DAT_010f0f84;
    _NiFreeAlias(tmp);
    if (flag & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

namespace fnv_00e94d00 {
struct NiGeometryBufferData
{
    virtual ~NiGeometryBufferData();
};
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
    void FUN_00e94d00(void*);
};
// Frees the NiGeometryBufferData stored at offset 0x28 of pkObj, removes it from the group, and clears the pointer.
// @fnv 0x00e94d00
void NiGeometryGroup::FUN_00e94d00(void* pkObj)
{
    NiGeometryBufferData* pkData = *(NiGeometryBufferData**)((char*)pkObj + 0x28);
    if (pkData)
    {
        RemoveObject(pkData);
        delete pkData;
        *(NiGeometryBufferData**)((char*)pkObj + 0x28) = 0;
    }
}
}  // namespace fnv_00e94d00

namespace fnv_00e94db0 {
struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;

struct NiGeometryBufferData
{
    virtual ~NiGeometryBufferData();
};
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
    void FUN_00e94db0(NiGeometryData*);
};
// Frees the NiGeometryBufferData stored at offset 0x1c of pkData via RemoveObject and delete, then clears the pointer.
// @fnv 0x00e94db0
void NiGeometryGroup::FUN_00e94db0(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x1c);
    if (pkBuffData)
    {
        RemoveObject(pkBuffData);
        delete pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x1c) = 0;
    }
}
}  // namespace fnv_00e94db0

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl _fnv_zlib_memset(void* dest, int value, unsigned int size);

struct GeometryBase
{
    virtual void slot();
    unsigned int unk04;
    unsigned int unk08;
    GeometryBase();
};
struct GeometryMap
{
    int* table;
    unsigned int bucketCount;
    void* buckets;
    unsigned int itemCount;
    GeometryMap()
    {
        table = &DAT_010f0f94;
        bucketCount = 37;
        itemCount = 0;
        buckets = NiMalloc(148);
        _fnv_zlib_memset(buckets, 0, bucketCount * 4);
        table = &DAT_010f0fb4;
    }
};
struct FUN_00e94ab0 : GeometryBase
{
    virtual void slot();
    GeometryMap map;
    FUN_00e94ab0();
};
// Constructs the object, whose GeometryMap member allocates and zeroes its bucket array.
// @fnv 0x00e94ab0
FUN_00e94ab0::FUN_00e94ab0()
{}

namespace fnv_00e94c00 {
struct NiMemObject
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00e94ab0 : NiMemObject
{
    void* objectVtable;
    unsigned int unk04;
    unsigned int unk08;
    void* mapVtable;
    unsigned int mapCount;
    void* mapData;
    unsigned int unk18;
    FUN_00e94ab0();
};
__declspec(noinline) FUN_00e94ab0::FUN_00e94ab0()
{
    unk18 = 0;
}
// @fnv 0x00e94c00
FUN_00e94ab0* __cdecl FUN_00e94c00()
{
    return new FUN_00e94ab0;
}
}  // namespace fnv_00e94c00

struct GeomMapNode
{
    GeomMapNode* next;
    unsigned int key;
    NiGeometryBufferData* value;
};

struct GeomMap
{
    virtual void slot0();
    virtual unsigned int slot1(unsigned int key);
    unsigned int count;
    GeomMapNode** buckets;
    void FUN_00e91fd0(unsigned int key);
};

// @fnv 0x00e946b0
void NiStaticGeometryGroup::Purge()
{
    GeomMapNode* pFirstNode = 0;
    GeomMap* pMap = (GeomMap*)&map;
    unsigned int i = 0;
    unsigned int count = pMap->count;

    if (count > 0)
    {
        GeomMapNode** buckets = pMap->buckets;
        GeomMapNode** ppBucketCursor = buckets;
        do
        {
            if (*ppBucketCursor != 0)
            {
                goto found_head;
            }
            ppBucketCursor++;
            i++;
        } while (i < count);
    }
    pFirstNode = 0;
    goto have_head;
found_head:
    pFirstNode = pMap->buckets[i];
have_head:
    GeomMapNode* node = pFirstNode;
    if (node == 0)
    {
        return;
    }
    do
    {
        unsigned int key = node->key;
        NiGeometryBufferData* value = node->value;

        if (node->next != 0)
        {
            node = node->next;
        }
        else
        {
            i = pMap->slot1(key) + 1;
            if (i < pMap->count)
            {
                GeomMapNode** p = pMap->buckets + i;
                do
                {
                    node = *p;
                    if (node != 0)
                    {
                        goto scanned;
                    }
                    p++;
                    i++;
                } while (i < pMap->count);
            }
            node = 0;
        scanned:;
        }

        pMap->FUN_00e91fd0(key);
        if (value != 0)
        {
            value->NiGeometryBufferData::~NiGeometryBufferData();
            _delete(value, 0x34);
        }
    } while (node != 0);
}

struct S_00e948f0_Rtti
{
    int unk00;
    S_00e948f0_Rtti* m_base;
};

struct S_00e948f0_Pool
{
    void* FUN_00aa3e40(unsigned int n);
};
extern S_00e948f0_Pool DAT_011f6238;

struct FUN_00e947c0
{
    int unk00;
    unsigned int m_flags;
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
    int m_kind;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    FUN_00e947c0() throw();
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
    static void operator delete(void*)
    {}
};
typedef FUN_00e947c0 S_00e948f0_Data;

struct S_00e948f0_Obj
{
    virtual void v00();
    virtual void v04();
    virtual S_00e948f0_Rtti* GetRTTI();
    int unk04;
    int unk08;
    unsigned short m_0c;
    unsigned short unk0E;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_24;
    void* m_28;
    int unk2C;
    int unk30;
    S_00e948f0_Data* m_34;
};

struct S_00e948f0_Y
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short m_22;
    int unk24;
    S_00e948f0_Data* m_28;
};

extern S_00e948f0_Rtti DAT_011f4a88;
extern S_00e948f0_Rtti DAT_011f4a70;
extern unsigned int DAT_011bf558;
bool __cdecl FUN_0043b300(const S_00e948f0_Rtti* r, S_00e948f0_Obj* o);

struct S_00e948f0_Holder
{
    void FUN_00e98730(S_00e948f0_Data* d);
    void InitData(S_00e948f0_Obj* p1, int p2, S_00e948f0_Y* p3);
};

// @fnv 0x00e948f0
void S_00e948f0_Holder::InitData(S_00e948f0_Obj* apObj, int aiUnused, S_00e948f0_Y* apY)
{
    S_00e948f0_Data* d;
    if (apY)
    {
        if (apY->m_28)
        {
            return;
        }
        d = new S_00e948f0_Data;
        d->m_kind = (apY->m_22 != 0) + 4;
        apY->m_28 = d;
    }
    else
    {
        if (apObj->m_34)
        {
            return;
        }
        d = new S_00e948f0_Data;
        bool found = false;
        for (S_00e948f0_Rtti* r = apObj->GetRTTI(); r; r = r->m_base)
        {
            if (r == &DAT_011f4a88)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            d->m_kind = 4;
        }
        else if (FUN_0043b300(&DAT_011f4a70, apObj))
        {
            d->m_kind = 5;
        }
        apObj->m_34 = d;
    }
    bool hasA = apObj->m_28 != 0;
    bool hasB = apObj->m_24 != 0;
    bool hasC = hasB && (apObj->m_0c & 0xf000) != 0;
    unsigned int t = apObj->m_0c & 1;
    if (t > DAT_011bf558)
    {
        t = DAT_011bf558;
    }
    unsigned int flags = 0;
    if (hasA)
    {
        flags = 0x400000;
    }
    if (hasB)
    {
        flags |= 0x800000;
    }
    if (hasC)
    {
        flags |= 0x200000;
    }
    d->m_flags = (t << 24) | flags;
    FUN_00e98730(d);
}

extern int DAT_011c0ce0;
extern int DAT_011c0ce4;

struct S_00e94b00_Arr
{
    virtual void unk_vf00();
    unsigned int* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    S_00e94b00_Arr()
    {
        m_usMaxSize = 0;
        m_usGrowBy = 1;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
    }
    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; ++i)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct FUN_00e94b00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00e94b00_Arr arr;
    int unk2c;
    int unk30;
    FUN_00e94b00();
};

// @fnv 0x00e94b00
FUN_00e94b00::FUN_00e94b00()
{
    unk0c = DAT_011c0ce0;
    unk04 = 0;
    unk08 = 0;
    unk00 = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    arr.RemoveAll();
    unk2c = 0;
    unk30 = DAT_011c0ce4;
}

struct VbNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};

struct FUN_00a53c30_cls
{
    bool FUN_00a53c30(unsigned int key, void** out);
};
struct FUN_00b57ea0_cls
{
    void InsertOrUpdate(unsigned int key, void* value);
};
struct FUN_00e94650_cls
{
    VbNode* FUN_00e94650(unsigned int size, bool flag);
};
void* __cdecl FUN_00e94b80(unsigned int a, void* b, unsigned int key, unsigned int usage, unsigned int c);

struct VbDesc
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned char b14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int* m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_38;
    unsigned int GetKey() const
    {
        return m_0c;
    }
    unsigned int GetCount() const
    {
        return m_20;
    }
    unsigned int GetVertexCount() const
    {
        return m_1c;
    }
    unsigned int GetStride(unsigned int i) const
    {
        if (i < m_20)
            return m_24[i];
        return 0;
    }
    bool IsDynamic() const
    {
        return b14 != 0;
    }
    void SetBase(unsigned int base)
    {
        m_38 = base;
    }
};

struct FUN_00e94c20_cls
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;
    FUN_00a53c30_cls map;
    VbNode* GetOrCreateNode(VbDesc* d, unsigned int idx);
};

// Looks up or creates a VbNode, calls FUN_00e94650 with vertex-count times stride and count>1, then stores a quotient in d->m_38.
// @fnv 0x00e94c20
VbNode* FUN_00e94c20_cls::GetOrCreateNode(VbDesc* apDesc, unsigned int uiStrideIndex)
{
    VbNode* pNode = 0;
    VbNode* object;
    FUN_00e94c20_cls* owner = this;
    unsigned int key = apDesc->GetKey();
    unsigned int stride;
    stride = apDesc->GetStride(uiStrideIndex);
    if (key == 0)
    {
        key = stride | 0x80000000u;
    }
    unsigned int usage = 0;
    if (apDesc->IsDynamic())
    {
        key |= 0x40000000u;
        usage = 0x80000000u;
    }
    if (!((FUN_00a53c30_cls*)&owner->map)->FUN_00a53c30(key, (void**)&pNode) || !(object = pNode))
    {
        object = (VbNode*)FUN_00e94b80(0x10000, owner->m_08, key, usage, 0);
        ((FUN_00b57ea0_cls*)&owner->map)->InsertOrUpdate(key, object);
    }
    unsigned int count = apDesc->GetCount();
    VbNode* r = ((FUN_00e94650_cls*)object)->FUN_00e94650(apDesc->GetVertexCount() * stride, count > 1);
    apDesc->m_38 = r->m_0c / stride;
    return r;
}

void* __cdecl FUN_00aa13e0(unsigned int n);
void __cdecl FUN_00e941a0(void* object);
struct S00e94b80_Unknown
{
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct S00e94b80_Heap
{
};
static S00e94b80_Heap s00e94b80_heap;
inline void* operator new(unsigned int n, S00e94b80_Heap) throw()
{
    return FUN_00aa13e0(n);
}
// Allocates a FUN_00e94b00, assigns its fields, AddRefs b when nonnull, releases the prior stored pointer otherwise, and calls FUN_00e941a0.
// @fnv 0x00e94b80
void* __cdecl FUN_00e94b80(unsigned int a, void* apUnknown, unsigned int key, unsigned int usage, unsigned int c)
{
    FUN_00e94b00* object = new (s00e94b80_heap) FUN_00e94b00;
    if (object)
    {
        object->unk0c = a;
        S00e94b80_Unknown* pUnknown = (S00e94b80_Unknown*)apUnknown;
        if (pUnknown)
        {
            object->unk10 = (int)pUnknown;
            pUnknown->AddRef();
        }
        else
        {
            S00e94b80_Unknown* pOldUnknown = (S00e94b80_Unknown*)object->unk10;
            if (pOldUnknown)
                pOldUnknown->Release();
            object->unk10 = 0;
        }
        object->unk04 = key;
        object->unk08 = usage;
        object->unk00 = c;
        FUN_00e941a0(object);
    }
    return object;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern int DAT_01400000;
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct NiScreenTexture
{
    char _0[0x1c];
    void* m_pkGeometryRendererData;
};
struct B00e947c0
{
    B00e947c0();
    char _0[4];
    void* m_uiValue1;
    char _8[0x34];
    int m_eRequestType;
    char _40[0x14];
};
struct NiStaticGeometryGroup_00e94a30 : NiStaticGeometryGroup
{
    void FUN_00e98730(void*);
    void FUN_00e94a30(NiScreenTexture*);
};
// Allocates and initializes a B00e947c0 buffer when pkScreenTexture->m_pkGeometryRendererData is null, then calls FUN_00e98730.
// @fnv 0x00e94a30
void NiStaticGeometryGroup_00e94a30::FUN_00e94a30(NiScreenTexture* pkScreenTexture)
{
    if (!pkScreenTexture->m_pkGeometryRendererData)
    {
        void* p = reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x54);
        B00e947c0* pkBuffData;
        if (p)
            pkBuffData = new (p) B00e947c0;
        else
            pkBuffData = 0;
        pkBuffData->m_eRequestType = 4;
        pkBuffData->m_uiValue1 = &DAT_01400000;
        FUN_00e98730(pkBuffData);
    }
}

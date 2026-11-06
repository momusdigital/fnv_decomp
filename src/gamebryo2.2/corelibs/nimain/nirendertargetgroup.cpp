
// src/gamebryo2.2/corelibs/nimain/nirendertargetgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirendertargetgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;

extern NiRTTI g_012708ec;

// @fnv 0x00ee8530
NiRTTI* __cdecl FUN_00ee8530()
{
    return &g_012708ec;
}

struct NiPixelFormat;
struct NiRenderTargetGroup
{
    const NiPixelFormat* __thiscall GetPixelFormat() const;
};

// @fnv 0x00ee8600
const NiPixelFormat* __thiscall NiRenderTargetGroup::GetPixelFormat() const
{
    NiRenderTargetGroup* p = const_cast<NiRenderTargetGroup*>(this);
    NiPixelFormat* p1 = *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p) + 0x20);
    if (p1)
    {
        NiPixelFormat* p2 = *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p1) + 0x10);
        if (p2)
            return *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p2) + 0xc);
    }
    return 0;
}

struct RendererData
{
    virtual ~RendererData();
};
struct StandIn
{
    char _pad[0x24];
    RendererData* m_pTextureRendererData;
    void SetRendererData(RendererData* pkRendererData);
};
// @fnv 0x00ee8460
void StandIn::SetRendererData(RendererData* pkRendererData)
{
    if (m_pTextureRendererData)
    {
        delete m_pTextureRendererData;
        m_pTextureRendererData = pkRendererData;
    }
    else
    {
        m_pTextureRendererData = pkRendererData;
    }
}

namespace fnv_00ee84d0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiRenderTargetGroup
{
    char _pad_0[0x24];
    int GetDepthStencilWidth() const;
};

// @fnv 0x00ee84d0
int NiRenderTargetGroup::GetDepthStencilWidth() const
{
    const NiMemObject* p =
        *reinterpret_cast<const NiMemObject* const*>(reinterpret_cast<const unsigned char*>(this) + 0x20);
    if (p)
        return *reinterpret_cast<const int*>(reinterpret_cast<const unsigned char*>(p) + 8);
    return 0;
}
}  // namespace fnv_00ee84d0

namespace fnv_00ee84e0 {
struct NiRenderTargetGroup
{
    char _pad_0[0x20];
    void* m_depthStencil;
    int GetDepthStencilHeight() const;
};

// @fnv 0x00ee84e0
int NiRenderTargetGroup::GetDepthStencilHeight() const
{
    void* p =
        *reinterpret_cast<void**>(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(this)) + 0x20);
    if (p)
        return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0xc);
    return 0;
}
}  // namespace fnv_00ee84e0

namespace fnv_00ee84f0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiRenderTargetGroup
{
    char _pad_0[0x0c];
    NiMemObject* m_pBuffers[1];
    NiMemObject* __thiscall FUN_00ee84f0(unsigned int uiIndex) const;
};

// @fnv 0x00ee84f0
NiMemObject* __thiscall NiRenderTargetGroup::FUN_00ee84f0(unsigned int uiIndex) const
{
    return m_pBuffers[uiIndex];
}
}  // namespace fnv_00ee84f0

namespace fnv_00ee8550 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiRenderTargetGroup : NiMemObject
{
    char _pad_1[7];
    bool m_bNeedsResolve;
    void __thiscall SetByte08(bool abResolve);
};

// @fnv 0x00ee8550
void __thiscall NiRenderTargetGroup::SetByte08(bool abResolve)
{
    m_bNeedsResolve = abResolve;
}
}  // namespace fnv_00ee8550

namespace fnv_00ee86e0 {
struct NiRenderTargetGroup
{
    char _pad_0[12];
    void* m_pBufferRendererData[4];
    void* FUN_00ee86e0(unsigned int uiIndex) const;
};

// @fnv 0x00ee86e0
void* NiRenderTargetGroup::FUN_00ee86e0(unsigned int uiIndex) const
{
    void* p = m_pBufferRendererData[uiIndex];
    if (p)
        return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(p) + 0x10);
    return 0;
}
}  // namespace fnv_00ee86e0

namespace fnv_00ee87e0 {
extern "C" void __cdecl __Dummy_00b6fef0(void*, int);
void __cdecl FUN_00ee8560();

struct NiRenderTargetGroup
{
    char _pad_0[1];
    void* __thiscall FUN_00ee87e0(unsigned int flags);
};

// Calls FUN_00ee8560, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with 0x28, and returns this.
// @fnv 0x00ee87e0
void* __thiscall NiRenderTargetGroup::FUN_00ee87e0(unsigned int flags)
{
    NiRenderTargetGroup* p = this;
    FUN_00ee8560();
    if (flags & 1)
        __Dummy_00b6fef0(p, 0x28);
    return p;
}
}  // namespace fnv_00ee87e0

struct StrArr
{
    char _pad0[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    char _pad1[2];
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl FUN_00a7d330(const char*);
// @fnv 0x00ee8800
void __stdcall FUN_00ee8800(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pString = FUN_00a7d330(*(const char**)&g_012708ec);
    unsigned int size = pkStrings->m_usSize;
    unsigned int max = pkStrings->m_usMax;
    if (size >= max)
        pkStrings->SetSize(size + pkStrings->m_usGrow);
    pkStrings->SetAt(size, pString);
}

struct EE8490Stage
{
    int unk00;
    int unk04;
    void* m_pvTexture;
};

class EE8490Pass
{
  public:
    int unk00;
    int unk04;
    int unk08;
    EE8490Stage* m_apkStages[8];

    void* GetStageTexture(unsigned int uiStage);
};

// @fnv 0x00ee8490
void* EE8490Pass::GetStageTexture(unsigned int uiStage)
{
    EE8490Stage* pkStage = m_apkStages[uiStage];
    if (pkStage)
        return pkStage->m_pvTexture;
    return 0;
}

// Candidate for FUN_00ee84b0 (23 bytes).
//
// FUN_00ee84b0 is vftable slot 36 of the game's NiRenderTargetGroup
// (RTTI .?AVNiRenderTargetGroup@@, vftable at 0x011010ec).  Its constructor
// at 0x00ee8500 shows the layout: a vptr at +0x00, a byte flag at +0x08, an
// inline array of six pointers at +0x0c..+0x23 and a renderer-data pointer at
// +0x24.
//
// The function is a __thiscall member taking one 4-byte stack parameter (an
// index into that array).  It returns the pointer stored at entry+0x0c, or 0
// when the array slot is empty.
//
// The translation unit already declares NiRenderTargetGroup with only one of
// its members, so the class below is a stand-in that reproduces the offsets.

struct FNV_Entry84B0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
};

struct NiRenderTargetGroupStand
{
    void* unk00;                    // +0x00, vptr
    void* unk04;                    // +0x04, base member
    unsigned char unk08;            // +0x08, flag byte
    FNV_Entry84B0* m_ppEntries[6];  // +0x0c, inline array of six entries
    void* m_pTextureRendererData;   // +0x24
    void* FUN_00ee84b0(unsigned int index);
};

// @fnv 0x00ee84b0
void* NiRenderTargetGroupStand::FUN_00ee84b0(unsigned int index)
{
    FNV_Entry84B0* pEntry = m_ppEntries[index];
    if (pEntry)
    {
        return pEntry->unk0c;
    }
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RenderBuffer
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long m_uiRefCount;
};
struct RendererData;
struct FUN_00ee8560
{
    virtual ~FUN_00ee8560();
    int unk04;
    int unk08;
    RenderBuffer* m_apkBuffers[4];
    int unk1c;
    RenderBuffer* m_pkDepthBuffer;
    RendererData* m_pTextureRendererData;
    void __thiscall FUN_00a5d3d0();
};
// Releases the renderer data, the depth buffer and the four render buffers via refcount decrement, then calls FUN_00a5d3d0.
// @fnv 0x00ee8560
FUN_00ee8560::~FUN_00ee8560()
{
    delete m_pTextureRendererData;
    RenderBuffer* p = m_pkDepthBuffer;
    if (p && !InterlockedDecrement(&p->m_uiRefCount))
        p->Destroy();
    RenderBuffer** ppBufferSlot = m_apkBuffers + 4;
    for (int i = 3; i >= 0; --i)
    {
        RenderBuffer* pBuffer = *(--ppBufferSlot);
        if (pBuffer && !InterlockedDecrement(&pBuffer->m_uiRefCount))
            pBuffer->Destroy();
    }
    FUN_00a5d3d0();
}

struct FUN_00ee85e0_Node
{
    char unk00[0xc];
    void* m_p0c;
};

struct FUN_00ee85e0_Entry
{
    char unk00[0x10];
    FUN_00ee85e0_Node* m_p10;
};

class FUN_00ee85e0_cls
{
  public:
    char unk00[0xc];
    FUN_00ee85e0_Entry* m_entries[1];

    void* GetEntryValue(unsigned int index);
};

// @fnv 0x00ee85e0
void* FUN_00ee85e0_cls::GetEntryValue(unsigned int index)
{
    FUN_00ee85e0_Entry* pEntry = m_entries[index];
    if (pEntry != 0)
    {
        FUN_00ee85e0_Node* pNode = pEntry->m_p10;
        if (pNode != 0)
        {
            return pNode->m_p0c;
        }
    }
    return 0;
}

struct FUN_00ee8700_inner
{
    char _pad0[0x10];
    void* m_pDataFormat;
};

class FUN_00ee8700_cls
{
  public:
    char _pad0[0x20];
    FUN_00ee8700_inner* m_pInner;

    void* FUN_00ee8700();
};

// @fnv 0x00ee8700
void* FUN_00ee8700_cls::FUN_00ee8700()
{
    if (m_pInner != 0)
    {
        return m_pInner->m_pDataFormat;
    }
    return 0;
}

class RendererEE8
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual void unkv0D4();
    virtual unsigned int GetMaxLevel();
};

class ShaderLevelEE8
{
  public:
    ShaderLevelEE8() throw();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    unsigned int m_uiLevel;
    int unk20, unk24;
};

// @fnv 0x00ee8710
ShaderLevelEE8* __cdecl CreateShaderLevel(unsigned int uiTreeBlockIndex, RendererEE8* pkRenderer)
{
    if (!pkRenderer)
        return 0;
    if (pkRenderer->GetMaxLevel() < uiTreeBlockIndex)
        return 0;
    if (uiTreeBlockIndex > 4)
        return 0;
    ShaderLevelEE8* pkObject = new ShaderLevelEE8;
    pkObject->m_uiLevel = uiTreeBlockIndex;
    return pkObject;
}

struct SourceObject
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual unsigned int v54();
};
struct SpawnedObject
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42(void* a, int b);
    virtual void v43(void* a);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
};

void* __cdecl FUN_00aa13e0(unsigned int size);
SpawnedObject* __fastcall FUN_00ee8500(void* mem);

// @fnv 0x00ee8760
SpawnedObject* __cdecl FUN_00ee8760(void* a1, SourceObject* apSource, void* a3)
{
    if (apSource == 0)
    {
        return 0;
    }
    if (a1 == 0)
    {
        return 0;
    }
    if (apSource->v54() < 1)
    {
        return 0;
    }
    SpawnedObject* pSpawned;
    void* mem = FUN_00aa13e0(0x28);
    if (mem != 0)
    {
        pSpawned = FUN_00ee8500(mem);
    }
    else
    {
        pSpawned = 0;
    }
    pSpawned->m_1c = 1;
    pSpawned->v42(a1, 0);
    if (a3 != 0)
    {
        pSpawned->v43(a3);
    }
    return pSpawned;
}

class AA1AC0Class
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;

    virtual unsigned int FUN_00aa1ac0();
};

// @fnv 0x00aa1ac0
unsigned int AA1AC0Class::FUN_00aa1ac0()
{
    return unk20;
}

struct StandIn_00ee8540
{
    unsigned char __thiscall GetByte08() const;
};

// @fnv 0x00ee8540
unsigned char __thiscall StandIn_00ee8540::GetByte08() const
{
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 8);
}

#include <windows.h>
struct RefCountedObj
{
    virtual void unk00();
    virtual void Destroy();
    LONG m_lRefCount;
};

class FUN_00ee8620_cls
{
  public:
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(int);
    unsigned int unk04;
    unsigned int unk08;
    RefCountedObj* m_apItems[4];
    unsigned int m_uiCount;
    bool SetItem(RefCountedObj* pNew, unsigned int uiIndex);
};

// Replaces the item at uiIndex with pNew, decrementing the old item's ref count and incrementing the new one's.
// @fnv 0x00ee8620
bool FUN_00ee8620_cls::SetItem(RefCountedObj* apItem, unsigned int uiIndex)
{
    v49(0);
    if (uiIndex < m_uiCount)
    {
        RefCountedObj* pOldItem = m_apItems[uiIndex];
        if (pOldItem != apItem)
        {
            if (pOldItem != 0)
            {
                if (InterlockedDecrement(&pOldItem->m_lRefCount) == 0)
                {
                    pOldItem->Destroy();
                }
            }
            m_apItems[uiIndex] = apItem;
            if (apItem != 0)
            {
                InterlockedIncrement(&apItem->m_lRefCount);
            }
        }
        return true;
    }
    return false;
}

struct NiDepthStencilBuffer
{
    void* _vft;
    LONG m_lRef;
};
struct RTG_Host
{
    int _pad[8];
    NiDepthStencilBuffer* _ds;
    bool __thiscall SetDepthStencilBuffer(NiDepthStencilBuffer*);
};
// Replaces the host's depth-stencil buffer, releasing the old one and acquiring a reference to the new one.
// @fnv 0x00ee8690
bool __thiscall RTG_Host::SetDepthStencilBuffer(NiDepthStencilBuffer* pkDepthBuffer)
{
    ((void(__thiscall**)(void*, int))(*(void***)this))[49](this, 0);
    NiDepthStencilBuffer* pkOld = _ds;
    if (pkOld != pkDepthBuffer)
    {
        if (pkOld)
        {
            if (InterlockedDecrement(&pkOld->m_lRef) == 0)
                ((void(__thiscall**)(void*))(*(void***)pkOld))[1](pkOld);
        }
        _ds = pkDepthBuffer;
        if (pkDepthBuffer)
            InterlockedIncrement(&pkDepthBuffer->m_lRef);
    }
    return true;
}

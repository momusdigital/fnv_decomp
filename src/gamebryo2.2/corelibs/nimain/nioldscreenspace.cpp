// gamebryo2.2/corelibs/nimain/nioldscreenspace.cpp: NiScreenPolygon, NiScreenGeometry, Holder, HolderBase and more (45 functions)

extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)
#include "nioldscreenspace_decls.h"
// Zeroes the properties array, then assigns the contents of other into this object.
// @fnv 0x00a89810
NiScreenPolygon::NiScreenPolygon(const NiScreenPolygon& other)
{
    memset(properties, 0, sizeof(properties));
    *this = other;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5e5c;
// Returns the address of the global object g_011f5e5c.
// @fnv 0x00a8ff70
GlobalObjectO2_00a7b610* __cdecl FUN_00a8ff70()
{
    return &g_011f5e5c;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void __thiscall FUN_00a744a0();
};
extern void* DAT_0109f81c;

// @fnv 0x00a8ff80
void* __cdecl FUN_00a8ff80()
{
    void* p = BSFadeNode::operator new(0xc4);
    if (p)
    {
        ((BSFadeNode*)p)->FUN_00a744a0();
        *(void**)p = &DAT_0109f81c;
        return p;
    }
    return 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5e64;

// Returns the address of the global object g_011f5e64.
// @fnv 0x00a8ffb0
GlobalObjectO2_00a7b610* __cdecl FUN_00a8ffb0()
{
    return &g_011f5e64;
}

namespace fnv_00a8ffc0 {
struct _Call_a5d3a0
{
    void __thiscall FUN_a5d3a0();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_0109f914;

// @fnv 0x00a8ffc0
void* __cdecl FUN_00a8ffc0()
{
    void* p = BSFadeNode::operator new(0x1c);
    if (p)
    {
        reinterpret_cast<_Call_a5d3a0*>(p)->FUN_a5d3a0();
        unsigned short* pusField0c = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + 0xc);
        *pusField0c = 0;
        unsigned* puiField10 = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(p) + 0x10);
        *puiField10 = 0;
        puiField10[1] = 0;
        puiField10[2] = 0;
        *reinterpret_cast<unsigned*>(p) = reinterpret_cast<unsigned>(&DAT_0109f914);
        return p;
    }
    return 0;
}
}  // namespace fnv_00a8ffc0

namespace fnv_00a90040 {
void __fastcall FUN_00a89760(void*);
extern int DAT_0109f81c;
void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct NiScreenGeometry
{
    void* FUN_00a90040(unsigned int flags);
};

// @fnv 0x00a90040
void* __thiscall NiScreenGeometry::FUN_00a90040(unsigned int flags)
{
    *(int*)this = (int)&DAT_0109f81c;
    FUN_00a89760(this);
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xc4);
    return this;
}
}  // namespace fnv_00a90040

extern "C" void* g_011f5e54;

// @fnv 0x00a90ab0
void* __cdecl FUN_00a90ab0()
{
    return &g_011f5e54;
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5e6c;

// @fnv 0x00a91690
GlobalObjectO2_00a7b610* FUN_00a91690()
{
    return &g_011f5e6c;
}

struct ImageSpaceTexture
{
    void CreateRenderTargetTexture(unsigned int);
};
struct NiTPrimitiveArray_int___
{
    void SetAt(unsigned int, int&);
};
struct Holder
{
    void FUN_00ba4530(int);
};
// @fnv 0x00ba4530
void Holder::FUN_00ba4530(int)
{
    ImageSpaceTexture* p = (ImageSpaceTexture*)((char*)this + 0x58);
    p->CreateRenderTargetTexture(0x18);
    ((NiTPrimitiveArray_int___*)((char*)this + 0x28))->SetAt(2, (int&)p);
    p = (ImageSpaceTexture*)((char*)this + 0x68);
    p->CreateRenderTargetTexture(0x18);
    ((NiTPrimitiveArray_int___*)((char*)this + 0x28))->SetAt(3, (int&)p);
}

struct ElemBase
{
    virtual void f0();
    virtual void f1();
    long m_lRef;
};
struct HolderBase
{
    int _00;
    ElemBase** m_pData;
    unsigned short _08;
    unsigned short m_usSize;
    unsigned short m_usExtra;
    void __thiscall FUN_00a2e620();
};
// @fnv 0x00a2e620
void __thiscall HolderBase::FUN_00a2e620()
{
    for (unsigned short i = 0; i < m_usSize; ++i)
    {
        ElemBase* p = m_pData[i];
        ElemBase** pp = &m_pData[i];
        if (p)
        {
            if (InterlockedDecrement(&p->m_lRef) == 0)
                p->f1();
            *pp = 0;
        }
    }
    m_usSize = 0;
    m_usExtra = 0;
}

struct NiStream
{
};
struct NiObject
{
    virtual bool RegisterStreamables(NiStream&);
};
struct FakeProp
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual bool RegisterStreamables(NiStream&);
};
struct MyStand : NiObject
{
    bool FUN_00a900c0(NiStream&);
};
// Calls NiObject::RegisterStreamables, then registers streamables on 7 objects reached through the pointer at this+8, returning false if the base call fails.
// @fnv 0x00a900c0
bool MyStand::FUN_00a900c0(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream))
        return false;
    unsigned int i;
    for (i = 0; i < 28; i += 4)
        (*(FakeProp**)(*(char**)((char*)this + 8) + i))->RegisterStreamables(stream);
    return true;
}

void _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct S_e7f900
{
    void FUN_00e7f900(int);
};
struct V0
{
    virtual void f(int);
};
struct InnerA
{
    void* p0;
    int pad;
    void* p8;
};
struct HostA
{
    void* p0;
    int p4;
    int p8;
    InnerA* p12;
    void ReleaseResources();
};
// @fnv 0x00a90ac0
void HostA::ReleaseResources()
{
    InnerA* pInner = p12;
    p8 = 0;
    if (pInner)
    {
        void* ecxVal = pInner->p0;
        if (ecxVal)
        {
            if (*(int*)((char*)ecxVal - 4))
                ((V0*)ecxVal)->f(3);
            else
                g_memoryManager.Deallocate((char*)ecxVal - 4);
        }
        void* r = pInner->p8;
        if (r)
            ((S_e7f900*)r)->FUN_00e7f900(1);
        g_memoryManager.Deallocate(pInner);
    }
    _NiFreeAlias(p0);
}

struct StrArr
{
    void* m_pData;
    unsigned int m_04;
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrow;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    unsigned short GetAlloc() const
    {
        return m_usAlloc;
    }
    unsigned short GetGrow() const
    {
        return m_usGrow;
    }
};
struct Caller74690
{
    void __thiscall FUN_00a74690(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
struct Outer913a0 : Caller74690
{
    void __thiscall AppendGlobalString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f5e5c) to pkStrings, growing the array by its grow amount when full.
// @fnv 0x00a913a0
void __thiscall Outer913a0::AppendGlobalString(StrArr* pkStrings)
{
    FUN_00a74690(pkStrings);
    char* psz = _FUN_00a7d330(*(const char**)&g_011f5e5c);
    unsigned int uiSize = pkStrings->GetSize();
    unsigned int uiMax = pkStrings->GetAlloc();
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->GetGrow());
    pkStrings->SetAt(uiSize, psz);
}

namespace fnv_00a91890 {
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct BaseCam
{
    void __thiscall FUN_00a71920(StrArr*);
};
struct Cam : BaseCam
{
    void __thiscall GetViewerStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
// Calls the base implementation, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it if needed.
// @fnv 0x00a91890
void __thiscall Cam::GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a71920(pkStrings);
    char* tmp = _FUN_00a7d330(*(const char**)&g_011f5e6c);
    unsigned int sz = *(unsigned short*)((char*)pkStrings + 0xa);
    if (sz >= *(unsigned short*)((char*)pkStrings + 8))
    {
        pkStrings->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + sz);
    }
    pkStrings->SetAt(sz, tmp);
}
}  // namespace fnv_00a91890

void __cdecl _delete(void*, unsigned int);
struct NiScreenGeometryData
{
    void __thiscall FUN_00a911d0();
    void* __thiscall FUN_00a91910(unsigned int);
};
// Calls FUN_00a911d0, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a91910
void* __thiscall NiScreenGeometryData::FUN_00a91910(unsigned int flags)
{
    FUN_00a911d0();
    if (flags & 1)
        _delete(this, 0x70);
    return this;
}

namespace fnv_00a91e60 {
extern "C" void __cdecl _delete(void*, unsigned int);
struct NiScreenSpaceCamera
{
    void __thiscall FUN_00a915d0();
    void* __thiscall FUN_00a91e60(unsigned int flags);
};
// @fnv 0x00a91e60
void* __thiscall NiScreenSpaceCamera::FUN_00a91e60(unsigned int flags)
{
    FUN_00a915d0();
    if (flags & 1)
        _delete(this, 0x134);
    return this;
}
}  // namespace fnv_00a91e60

struct NiScreenSpaceCamera
{
    NiScreenSpaceCamera* __thiscall FUN_00a91d80();
};

// @fnv 0x00a91ee0
BSFadeNode* FUN_00a91ee0()
{
    void* p = BSFadeNode::operator new(0x134);
    if (p)
        return (BSFadeNode*)((NiScreenSpaceCamera*)p)->FUN_00a91d80();
    return 0;
}

namespace fnv_00a90560 {
struct NiRefObject
{
    virtual ~NiRefObject();
};
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_0109f914;
void __cdecl _delete(void*, unsigned int);
struct FUN_00a90560_host : NiRefObject
{
    char _pad[12];
    void* m1;
    void* m2;
    void* m3;
    void* __thiscall FUN_00a90560(unsigned int);
};
// @fnv 0x00a90560
void* __thiscall FUN_00a90560_host::FUN_00a90560(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109f914;
    g_memoryManager.Deallocate(m1);
    g_memoryManager.Deallocate(m2);
    g_memoryManager.Deallocate(m3);
    this->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x1c);
    return this;
}
}  // namespace fnv_00a90560

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;
struct NiBinaryStream
{
    void* vt;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pv, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pv, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
struct NiStreamLinkReader
{
    unsigned int ReadUnsignedInteger();
};
inline unsigned int NiStreamFileVersion(NiStream& kStream)
{
    return *(unsigned int*)((char*)&kStream + 0xd8);
}
inline NiBinaryStream* NiStreamInput(NiStream& kStream)
{
    return *(NiBinaryStream**)((char*)&kStream + 0x24c);
}
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(NiStreamInput(kStream), &val, 1);
}
struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    void LoadBinary(NiStream&);
    static void* operator new[](unsigned int s)
    {
        return _g_memoryManager.Allocate(s);
    }
};
struct NiPoint2
{
    float x, y;
    NiPoint2()
    {}
    void LoadBinary(NiStream&);
    static void* operator new[](unsigned int s)
    {
        return _g_memoryManager.Allocate(s);
    }
};
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    void LoadBinary(NiStream&);
    static void* operator new[](unsigned int s)
    {
        return _g_memoryManager.Allocate(s);
    }
};
struct NiObjLB
{
    void LoadBinary(NiStream&);
};
struct FUN_00a90d70_poly : NiObject
{
    unsigned int m_uiRefCount;
    void* m_pGeometryBuffer;
    unsigned short m_usVertices;
    NiColor* m_pkVertex;
    NiPoint2* m_pkTexture;
    RgbaColor* m_pkColor;
    void FUN_00a90d70(NiStream& kStream);
};
// Loads vertex count, vertex colors, and optional texture and color arrays from the stream, then reads the stream link.
// @fnv 0x00a90d70
void FUN_00a90d70_poly::FUN_00a90d70(NiStream& kStream)
{
    ((NiObjLB*)this)->LoadBinary(kStream);

    unsigned char bHasTexture;
    unsigned char bHasColor;
    unsigned short i;

    ReadBinaryValue(kStream, m_usVertices);
    m_pkVertex = new NiColor[m_usVertices];
    for (i = 0; i < m_usVertices; i++)
        m_pkVertex[i].LoadBinary(kStream);

    if (NiStreamFileVersion(kStream) < 0x4010000)
    {
        ReadBinaryValue(kStream, (unsigned int&)m_pkTexture);
        bHasTexture = m_pkTexture != 0;
    }
    else
    {
        ReadBinaryValue(kStream, bHasTexture);
    }
    if (bHasTexture)
    {
        m_pkTexture = new NiPoint2[m_usVertices];
        for (i = 0; i < m_usVertices; i++)
            m_pkTexture[i].LoadBinary(kStream);
    }

    if (NiStreamFileVersion(kStream) < 0x4010000)
    {
        ReadBinaryValue(kStream, (unsigned int&)m_pkColor);
        bHasColor = m_pkColor != 0;
    }
    else
    {
        ReadBinaryValue(kStream, bHasColor);
    }
    if (bHasColor)
    {
        m_pkColor = new RgbaColor[m_usVertices];
        for (i = 0; i < m_usVertices; i++)
            m_pkColor[i].LoadBinary(kStream);
    }

    ((NiStreamLinkReader&)kStream).ReadUnsignedInteger();
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a90a50_class
{
    void* __thiscall FUN_00a90a50();
};

// @fnv 0x00a90b20
void* __cdecl FUN_00a90b20()
{
    FUN_00a90a50_class* object = static_cast<FUN_00a90a50_class*>(A51BF0Base::operator new(0x70));

    if (object)
        return object->FUN_00a90a50();

    return 0;
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct BaseA8F260
{
    virtual ~BaseA8F260() throw();
    BaseA8F260() throw();
};

struct ObjA8F260 : BaseA8F260
{
    int unk04;
    int m_08;
    int m_0c;
    int m_10;

    ObjA8F260() throw()
    {
        *(volatile int*)&m_08 = 0;
        *(volatile int*)&m_0c = 0;
        *(volatile int*)&m_10 = 0;
    }

    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

// Allocates an ObjA8F260, stores the two arguments in m_08 and m_0c, and returns it.
// @fnv 0x00a8f260
void* __cdecl CreateObjA8F260(int aiValue08, int aiValue0c)
{
    ObjA8F260* p = new ObjA8F260();
    p->m_08 = aiValue08;
    p->m_0c = aiValue0c;
    return p;
}

struct S_00a90100_Stream
{
};
struct S_00a90100_Child
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
    virtual void Link(S_00a90100_Stream&);
};
struct S_00a90100_Array
{
    S_00a90100_Child** m_pData;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usGrow;
    unsigned short unk0a;
    int unk0c;
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    S_00a90100_Child* GetAt(unsigned int i) const
    {
        return m_pData[i];
    }
};
struct S_00a90100_Base
{
    void __thiscall FUN_00a59ec0(S_00a90100_Stream&);
};
struct S_00a90100 : S_00a90100_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    S_00a90100_Array m_kA;
    S_00a90100_Array m_kB;
    void __thiscall LinkChildren(S_00a90100_Stream& kStream);
};
// Calls the base FUN_00a59ec0, then links every non-null child in m_kA and m_kB to kStream.
// @fnv 0x00a90100
void __thiscall S_00a90100::LinkChildren(S_00a90100_Stream& kStream)
{
    FUN_00a59ec0(kStream);
    for (unsigned int i = 0; i < m_kA.GetSize(); i++)
    {
        S_00a90100_Child* p = m_kA.GetAt(i);
        if (p)
            p->Link(kStream);
    }
    for (unsigned int i = 0; i < m_kB.GetSize(); i++)
    {
        S_00a90100_Child* p = m_kB.GetAt(i);
        if (p)
            p->Link(kStream);
    }
}

extern int DAT_0109f814;

struct HeapAllocator
{
    void FUN_00aa4060(void* apMemory);
};
extern HeapAllocator g_011f6238;

struct FUN_00a902e0_cls
{
    int m_vptr00;
    int m_04;
    void* m_08;
    void* m_0c;
    void* m_10;

    FUN_00a902e0_cls* FUN_00a902e0(unsigned char acFlags);
};

// @fnv 0x00a902e0
FUN_00a902e0_cls* FUN_00a902e0_cls::FUN_00a902e0(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        FUN_00a902e0_cls* p = (FUN_00a902e0_cls*)((char*)this + i * 20);
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = (FUN_00a902e0_cls*)((char*)p - 20);
                void* a = p->m_08;
                p->m_vptr00 = (int)&DAT_0109f814;
                g_011f6238.FUN_00aa4060(a);
                g_011f6238.FUN_00aa4060(p->m_0c);
                g_011f6238.FUN_00aa4060(p->m_10);
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            g_011f6238.FUN_00aa4060(base);
        }
        return (FUN_00a902e0_cls*)base;
    }

    void* a = m_08;
    m_vptr00 = (int)&DAT_0109f814;
    g_011f6238.FUN_00aa4060(a);
    g_011f6238.FUN_00aa4060(m_0c);
    g_011f6238.FUN_00aa4060(m_10);
    if (acFlags & 1)
    {
        g_011f6238.FUN_00aa4060(this);
    }
    return this;
}

struct ScrPoint2
{
    float x, y;
    bool operator!=(const ScrPoint2& o) const;
};
struct ScrColorA
{
    float r, g, b, a;
    bool operator!=(const ScrColorA& o) const;
};
struct ScrElement
{
    int unk00;
    unsigned short m_usPolygons;
    unsigned short m_usVertices;
    ScrPoint2* m_pkVertex;
    ScrColorA* m_pkColor;
    ScrPoint2* m_pkTexture;
};
struct ScrGeomData
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
    bool m_b58;
    int unk5C;
    int unk60;
    ScrElement** m_ppkElements;
    unsigned short unk68;
    unsigned short m_us6A;
    unsigned short m_usElements;
    bool BaseIsEqual(const ScrGeomData* pkOther);
    bool IsEqual(const ScrGeomData* pkOther);
};

// Compares this geometry against pkOther: base fields, m_b58, element counts, then each element's polygon/vertex counts and vertex, color and texture arrays.
// @fnv 0x00a903a0
bool ScrGeomData::IsEqual(const ScrGeomData* pkOther)
{
    if (!BaseIsEqual(pkOther))
        return false;
    if (pkOther->m_b58 != m_b58)
        return false;
    unsigned int ItemUpdateArray = pkOther->m_usElements;
    if (ItemUpdateArray != m_usElements)
        return false;
    if (pkOther->m_us6A != m_us6A)
        return false;

    unsigned int i = 0;
    if (i < ItemUpdateArray)
    {
        ScrElement** ppkOtherElements = pkOther->m_ppkElements;
        ScrElement** ppkElements = m_ppkElements;
        for (; i < ItemUpdateArray; i++)
        {
            ScrElement* pkA = ppkOtherElements[i];
            ScrElement* pkB = ppkElements[i];
            if (pkA)
            {
                if (pkB == 0)
                    return false;
                unsigned int uiPolygons = pkA->m_usPolygons;
                unsigned int uiVertices = pkA->m_usVertices;
                if (uiPolygons != pkB->m_usPolygons)
                    return false;
                if (uiVertices != pkB->m_usVertices)
                    return false;
                ScrPoint2* pkVA = pkA->m_pkVertex;
                ScrPoint2* pkVB = pkB->m_pkVertex;
                ScrColorA* pkCA = pkA->m_pkColor;
                ScrColorA* pkCB = pkB->m_pkColor;
                ScrPoint2* pkTA = pkA->m_pkTexture;
                ScrPoint2* pkTB = pkB->m_pkTexture;
                for (unsigned int j = 0; j < uiPolygons; j++)
                {
                    if (pkVA[j] != pkVB[j])
                        return false;
                    if (pkCA[j] != pkCB[j])
                        return false;
                    for (unsigned int k = 0; k < uiVertices; k++)
                    {
                        if (pkTA[j * uiVertices + k] != pkTB[j * uiVertices + k])
                            return false;
                    }
                }
            }
            else if (pkB)
            {
                return false;
            }
        }
    }
    return true;
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_0109f914;

struct GlobalAlloc_a905c0
{
    void* FUN_00aa3e40(unsigned int size);
};
extern GlobalAlloc_a905c0 DAT_011f6238;

struct Sub_a905c0
{
    void* FUN_00a89810(void* arg);
};

struct SpawnedObj_a905c0
{
    void* m_pVTable;
    unsigned int unk04;
    void* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void FUN_00a5d3a0();
    SpawnedObj_a905c0() throw();
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

SpawnedObj_a905c0::SpawnedObj_a905c0() throw()
{
    FUN_00a5d3a0();
    m_pVTable = (void*)&DAT_0109f914;
    m_0c = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
}

struct OwnerCls_a905c0
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;

    void CreateVertexBufferSet(SpawnedObj_a905c0* p, unsigned int arg);
    SpawnedObj_a905c0* CreateSpawnedObj(unsigned int arg);
};

// Allocates a SpawnedObj_a905c0, initializes it with arg, then stores a sub-object created from m_08 into m_08 and returns it.
// @fnv 0x00a905c0
SpawnedObj_a905c0* OwnerCls_a905c0::CreateSpawnedObj(unsigned int arg)
{
    SpawnedObj_a905c0* p = new SpawnedObj_a905c0();
    CreateVertexBufferSet(p, arg);
    void* pAlloc = DAT_011f6238.FUN_00aa3e40(0x1c);
    p->m_08 = pAlloc ? ((Sub_a905c0*)pAlloc)->FUN_00a89810(m_08) : 0;
    return p;
}

struct PropRef
{
    virtual void f00();
    virtual void DeleteThis();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual int GetKind();
    volatile long references;
    void DecRef()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
    void AcquireReference()
    {
        InterlockedIncrement(&references);
    }
};

struct PropSrc
{
    PropRef* Next();
    unsigned int Count();
};

struct FUN_00a90640_cls
{
    int unk00;
    int unk04;
    PropRef** m_08;
    void FUN_00a89af0(PropSrc* src);
    void AddPropsFromSource(PropSrc* src);
};

// Calls FUN_00a89af0, then iterates src's items and stores each item with GetKind() <= 7 into m_08 by kind, releasing the previous entry.
// @fnv 0x00a90640
void FUN_00a90640_cls::AddPropsFromSource(PropSrc* pSource)
{
    FUN_00a89af0(pSource);
    unsigned int n = pSource->Count();
    if (n == 0)
        return;
    do
    {
        --n;
        PropRef* item = pSource->Next();
        PropRef** ppSlots = m_08;
        if (item != 0 && item->GetKind() <= 7)
        {
            PropRef** slot = &ppSlots[item->GetKind()];
            PropRef* old = *slot;
            if (old != item)
            {
                if (old != 0)
                    old->DecRef();
                *slot = item;
                item->AcquireReference();
            }
        }
    } while (n != 0);
}

extern "C" void* g_011f5e74;
extern "C" unsigned int g_011f5e78;
extern "C" void __cdecl FUN_00fdb140(void);
extern "C" int __cdecl FUN_00ec658f(void(__cdecl*)(void));

struct FUN_00a908b0_cls
{
    int _00;
    ElemBase** m_pData;
    unsigned short _08;
    unsigned short m_usSize;
    unsigned short m_usExtra;
    void AssignElement(unsigned int idx, ElemBase** ppElem);
};

// @fnv 0x00a908b0
void FUN_00a908b0_cls::AssignElement(unsigned int uiIndex, ElemBase** ppElem)
{
    if ((g_011f5e78 & 1) == 0)
    {
        g_011f5e78 |= 1;
        g_011f5e74 = 0;
        FUN_00ec658f(FUN_00fdb140);
    }
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (*ppElem != g_011f5e74)
            m_usExtra += 1;
    }
    else
    {
        if (*ppElem != g_011f5e74)
        {
            if (m_pData[uiIndex] == g_011f5e74)
                m_usExtra += 1;
        }
        else if (m_pData[uiIndex] != g_011f5e74)
        {
            m_usExtra -= 1;
        }
    }

    ElemBase** slot = &m_pData[uiIndex];
    ElemBase* cur = *slot;
    if (cur != *ppElem)
    {
        if (cur)
        {
            if (!InterlockedDecrement(&cur->m_lRef))
                cur->f1();
        }
        ElemBase* pNew = *ppElem;
        *slot = pNew;
        if (pNew)
            InterlockedIncrement(&pNew->m_lRef);
    }
}

struct NiRTTI
{
    const char* m_pcName;
};

struct NiProperty
{
    virtual void vf00();
    virtual void vf01();
    virtual const NiRTTI* GetRTTI() const;
};

struct ViewerStrings
{
    virtual void vf00();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (!m_pBase[uiIndex])
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex])
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};

void __stdcall AppendCameraPathEntries(ViewerStrings* apViewerStrings);
char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d490(const char* pcPrefix, unsigned short usValue);
char* __cdecl FUN_00a7d5a0(const char* pcPrefix, const void* pvValue);

extern NiRTTI ms_RTTI_ScreenPolygon;

struct PropertyState
{
    NiProperty* m_spProperties[7];
};

struct NiScreenPolygonOld
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    PropertyState* m_pGeometryBuffer;
    unsigned short m_usVertices;
    void* m_pkVertex;
    void* m_pkTexture;
    void* m_pkColor;

    void AppendToStrings(ViewerStrings* apViewerStrings);
};

// Appends the RTTI name, m_usVertices, m_pkVertex, m_pkTexture, m_pkColor and the seven property names/pointers to the ViewerStrings list.
// @fnv 0x00a913f0
void NiScreenPolygonOld::AppendToStrings(ViewerStrings* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);
    apViewerStrings->Add(FUN_00a7d330(ms_RTTI_ScreenPolygon.m_pcName));
    apViewerStrings->Add(FUN_00a7d490("m_usVertices", m_usVertices));
    apViewerStrings->Add(FUN_00a7d5a0("m_pkVertex", m_pkVertex));
    apViewerStrings->Add(FUN_00a7d5a0("m_pkTexture", m_pkTexture));
    apViewerStrings->Add(FUN_00a7d5a0("m_pkColor", m_pkColor));
    for (unsigned int i = 0; i < 7; i++)
    {
        NiProperty* pkProp = m_pGeometryBuffer->m_spProperties[i];
        const char* pcRTTIName = pkProp->GetRTTI()->m_pcName;
        apViewerStrings->Add(FUN_00a7d5a0(pcRTTIName, pkProp));
    }
}

void* FUN_00c1d790(unsigned int ItemUpdateArray) throw();

struct A91D80UpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bParallelUpdate;
    bool m_bFoundParticles;
    bool m_bFoundMorphController;
    bool m_bSceneGraphChange;

    A91D80UpdateData(float fTime = 0.0f, bool m_bUpdateEnabled = false, bool m_bRender = false,
                     bool m_bInterpolate = false, bool m_bTimeToDie = false, bool m_bVisible = false)
        : m_fTime(fTime), m_bUpdate(m_bUpdateEnabled), m_bParallelUpdate(m_bRender), m_bFoundParticles(m_bInterpolate),
          m_bFoundMorphController(m_bTimeToDie), m_bSceneGraphChange(m_bVisible)
    {}
};

template <class T> class A91D80Array
{
  public:
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    A91D80Array(unsigned short usMaxSize, unsigned short usGrowBy)
    {
        m_usMaxSize = usMaxSize;
        m_usGrowBy = usGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = (T*)FUN_00c1d790(m_usMaxSize);
    }
    virtual ~A91D80Array() throw();
};

template <class T> class A91D80PrimitiveArray : public A91D80Array<T>
{
  public:
    A91D80PrimitiveArray(unsigned short usMaxSize, unsigned short usGrowBy) : A91D80Array<T>(usMaxSize, usGrowBy)
    {}
    virtual ~A91D80PrimitiveArray() throw();
};

class A91D80Camera
{
  public:
    A91D80Camera();
    virtual ~A91D80Camera();

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
    bool m_bViewportDirty;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;

    void UpdateWorldData(A91D80UpdateData& kData) throw();
    void UpdateWorldBound() throw();
};

class FUN_00a91d80 : public A91D80Camera
{
  public:
    A91D80PrimitiveArray<void*> m_kObjectPointers;
    A91D80PrimitiveArray<float> m_kFloatValues;

    FUN_00a91d80();
    virtual ~FUN_00a91d80();
};

// Initializes the camera, marks the viewport dirty, and updates world data and world bound.
// @fnv 0x00a91d80
FUN_00a91d80::FUN_00a91d80() : m_kObjectPointers(5, 5), m_kFloatValues(5, 5)
{
    m_bViewportDirty = true;
    A91D80UpdateData kData;
    A91D80Camera::UpdateWorldData(kData);
    A91D80Camera::UpdateWorldBound();
}

struct NiScreenSpaceCameraNew : NiScreenSpaceCamera
{
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a91e90_cls
{
    void __thiscall FUN_00a916a0(NiScreenSpaceCamera* p, unsigned int a1);
    NiScreenSpaceCamera* __thiscall CreateScreenSpaceCamera(unsigned int a1);
};

// Allocates a NiScreenSpaceCameraNew, initialises it via FUN_00a91d80, passes it to FUN_00a916a0 with a1, and returns it (or 0 on allocation failure).
// @fnv 0x00a91e90
NiScreenSpaceCamera* __thiscall FUN_00a91e90_cls::CreateScreenSpaceCamera(unsigned int a1)
{
    NiScreenSpaceCamera* p = new NiScreenSpaceCameraNew;
    NiScreenSpaceCamera* r = p ? p->FUN_00a91d80() : 0;
    FUN_00a916a0(r, a1);
    return r;
}

struct ElemRef
{
    virtual void Free(int flags);
};

struct Sub18
{
    int unk00;
    void Put(unsigned int index, unsigned int* out);
};

struct Vec16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Vec16();
};

void __stdcall FUN_00ec5fce(void* p, unsigned int size, unsigned int count, void (*ctor)());
void FUN_00ba3a00();

struct NodeBase
{
    virtual void vfn_00();
    ~NodeBase();
};

struct FUN_00ba4480 : NodeBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Sub18 m_sub18;
    ElemRef** m_ents;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    Vec16 m_vec58[3];
    ~FUN_00ba4480();
};

// @fnv 0x00ba4480
FUN_00ba4480::~FUN_00ba4480()
{
    for (int i = 0; i < 11; ++i)
    {
        if (m_ents[i] != 0)
        {
            ElemRef* pEntry = m_ents[i];
            if (pEntry)
                pEntry->Free(1);
            unsigned int tmp = 0;
            m_sub18.Put((unsigned int)i, &tmp);
        }
    }
}

class NiPSysBaseA90
{
  public:
    NiPSysBaseA90() throw();
    virtual ~NiPSysBaseA90();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
};

class NiPSysDerivedA90 : public NiPSysBaseA90
{
  public:
    NiPSysDerivedA90() throw()
    {}
    virtual ~NiPSysDerivedA90();
};

class NiPSysOwnerA90
{
  public:
    void CopyMemberData(NiPSysBaseA90* pkDest, void* pvProcess);
    NiPSysBaseA90* CreateClone(void* pvProcess);
};

// @fnv 0x00a90070
NiPSysBaseA90* NiPSysOwnerA90::CreateClone(void* pvProcess)
{
    NiPSysDerivedA90* pkClone = new NiPSysDerivedA90;
    CopyMemberData(pkClone, pvProcess);
    return pkClone;
}

struct NiBinaryWriter
{
    void* vt;
    unsigned int m_uiStreamFlags;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryWriter*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(void* pv, unsigned int uiBytes)
    {
        unsigned int uiSize = uiBytes;
        unsigned int uiBytesWritten = m_pfnWrite(this, pv, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
struct SaveStream
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
    virtual void SaveLinkID(void* pkObject);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    NiBinaryWriter* m_pkOut;
};
inline void SaveRaw(SaveStream& s, void* pv, unsigned int uiBytes)
{
    s.m_pkOut->BinaryWrite(pv, uiBytes);
}
struct SvColor
{
    float r, g, b;
    void SaveBinary(SaveStream&);
};
struct SvPoint2
{
    float x, y;
    void WriteCoords(SaveStream&);
};
struct SvColorA
{
    float r, g, b, a;
    void SaveBinary(SaveStream&);
};
struct FUN_00a90f70_poly : NiObject
{
    unsigned int m_uiRefCount;
    void** m_pGeometryBuffer;
    unsigned short m_usVertices;
    SvColor* m_pkVertex;
    SvPoint2* m_pkTexture;
    SvColorA* m_pkColor;
    void LinkObject(SaveStream&);
    void FUN_00a90f70(SaveStream& kStream);
};
// Links the object then writes vertex count, vertex colors, optional texture and color arrays, and property link IDs to the stream.
// @fnv 0x00a90f70
void FUN_00a90f70_poly::FUN_00a90f70(SaveStream& kStream)
{
    LinkObject(kStream);
    SaveStream& s = kStream;
    SaveRaw(s, &m_usVertices, 2);
    for (unsigned short i = 0; i < m_usVertices; i++)
        m_pkVertex[i].SaveBinary(kStream);
    bool bTex = m_pkTexture != 0;
    SaveRaw(s, &bTex, 1);
    if (bTex)
        for (unsigned short i = 0; i < m_usVertices; i++)
            m_pkTexture[i].WriteCoords(kStream);
    bool bCol = m_pkColor != 0;
    SaveRaw(s, &bCol, 1);
    if (bCol)
        for (unsigned short i = 0; i < m_usVertices; i++)
            m_pkColor[i].SaveBinary(kStream);
    unsigned int uiProps = 7;
    SaveRaw(s, &uiProps, 4);
    if (uiProps > 0)
        for (unsigned short i = 0; i < uiProps; i++)
            s.SaveLinkID(m_pGeometryBuffer[i]);
}

struct ColorA90
{
    float r, g, b, a;
    void FUN_00a698a0(SaveStream&);
};
struct ElemA90
{
    int unk00;
    unsigned short m_usPolygons;
    unsigned short m_usVertices;
    SvPoint2* m_pkVertex;
    ColorA90* m_pkColor;
    SvPoint2* m_pkTexture;
};
struct HostA90
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
    bool m_b58;
    int unk5C;
    int unk60;
    ElemA90** m_ppkElements;
    unsigned short unk68;
    unsigned short m_us6A;
    unsigned short m_usElements;
    void FUN_00a7bbe0(SaveStream&);
    void FUN_00a90b40(SaveStream&);
};
// Serializes the host's flag, element count and each element's polygon/vertex/color/texture data to the save stream.
// @fnv 0x00a90b40
void HostA90::FUN_00a90b40(SaveStream& stream)
{
    FUN_00a7bbe0(stream);
    char cByte = m_b58;
    stream.m_pkOut->BinaryWrite(&cByte, 1);
    unsigned int ItemUpdateArray = m_us6A;
    stream.m_pkOut->BinaryWrite(&ItemUpdateArray, 4);
    unsigned int i = 0;
    if (i < ItemUpdateArray)
    {
        do
        {
            ElemA90* pElement = m_ppkElements[i];
            unsigned short usPolygonCount = pElement ? pElement->m_usPolygons : 0;
            stream.m_pkOut->BinaryWrite(&usPolygonCount, 2);
            if (usPolygonCount != 0)
            {
                ColorA90* pkColor = pElement->m_pkColor;
                SvPoint2* pkTexture = pElement->m_pkTexture;
                unsigned short usVertexCount = pElement->m_usVertices;
                SvPoint2* pkVertex = pElement->m_pkVertex;
                bool bHasVertex = pkVertex != 0;
                stream.m_pkOut->BinaryWrite(&bHasVertex, 1);
                if (bHasVertex)
                {
                    for (unsigned int j = 0; j < usPolygonCount; ++j)
                        pkVertex[j].WriteCoords(stream);
                }
                bool bHasColor = pkColor != 0;
                stream.m_pkOut->BinaryWrite(&bHasColor, 1);
                if (bHasColor)
                {
                    for (unsigned int j = 0; j < usPolygonCount; ++j)
                        pkColor[j].FUN_00a698a0(stream);
                }
                stream.m_pkOut->BinaryWrite(&usVertexCount, 2);
                if (usVertexCount != 0)
                {
                    unsigned int uiTextureCount = usPolygonCount * usVertexCount;
                    if (uiTextureCount > 0)
                    {
                        SvPoint2* pTextureCursor = pkTexture;
                        unsigned int k = uiTextureCount;
                        do
                        {
                            pTextureCursor->WriteCoords(stream);
                            ++pTextureCursor;
                            --k;
                        } while (k != 0);
                    }
                }
            }
            ++i;
        } while (i < ItemUpdateArray);
    }
}

struct Pool00a91290
{
    void ReleaseResources();
};
extern Pool00a91290* DAT_011f5e50;
inline void DestroyPool(Pool00a91290* p)
{
    if (p)
    {
        p->ReleaseResources();
        g_011f6238.FUN_00aa4060(p);
    }
}

// @fnv 0x00a91930
void __cdecl DestroyGlobalPool()
{
    DestroyPool(DAT_011f5e50);
}

void __cdecl FUN_00a71450();

// @fnv 0x00a90000
void __cdecl FUN_00a90000()
{
    FUN_00a71450();
}

void FUN_00a716c0();

// @fnv 0x00a90020
void FUN_00a90020()
{
    FUN_00a716c0();
}

extern "C" void __cdecl IsEqualTo();

// @fnv 0x00a90030
extern "C" void __cdecl FUN_00a90030()
{
    IsEqualTo();
}

class NiCameraA91F
{
  public:
    virtual void vf00();
    void FUN_00a711d0(NiStream& kStream);
    int unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030;
    int unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090;
    int unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0;
    int unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110;
};

class NiControllerSequence;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
};

template <class T> class NiTNewInterface
{
};

template <class T, class TAlloc> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    T& GetAt(unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
};

typedef NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > > SeqArrayA91F;

class ArrayAA91F : public SeqArrayA91F
{
  public:
    void AssignElement(unsigned int uiIndex, NiPointer<NiControllerSequence>& kElem);
    void FUN_00a2e620();

    void Add(NiPointer<NiControllerSequence>& kElem)
    {
        unsigned int uiSize = m_usSize;
        if (uiSize >= m_usMaxSize)
            SetSize(uiSize + m_usGrowBy);
        AssignElement(uiSize, kElem);
    }
};

class ArrayBA91F : public SeqArrayA91F
{
  public:
    void FUN_00a90980(unsigned int uiIndex, NiPointer<NiControllerSequence>& kElem);
    void FUN_00a2e620();

    void Add(NiPointer<NiControllerSequence>& kElem)
    {
        unsigned int uiSize = m_usSize;
        if (uiSize >= m_usMaxSize)
            SetSize(uiSize + m_usGrowBy);
        FUN_00a90980(uiSize, kElem);
    }
};

class CameraA91F : public NiCameraA91F
{
  public:
    ArrayAA91F m_kArrayA;
    ArrayBA91F m_kArrayB;

    void FUN_00a91f00(NiStream& kStream);
};

// Calls the base stream routine, re-adds the original elements of both arrays, then calls FUN_00a2e620 on each.
// @fnv 0x00a91f00
void CameraA91F::FUN_00a91f00(NiStream& kStream)
{
    FUN_00a711d0(kStream);
    unsigned int ItemUpdateArray = m_kArrayA.m_usSize;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        m_kArrayA.Add(m_kArrayA.GetAt(i));
    m_kArrayA.FUN_00a2e620();
    ItemUpdateArray = m_kArrayB.m_usSize;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        m_kArrayB.Add(m_kArrayB.GetAt(i));
    m_kArrayB.FUN_00a2e620();
}

extern "C" void* __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int uiSize);

class A72BB0_StreamBase
{
  public:
    virtual void Unk_00();
};

class A72BB0_DataStream : public A72BB0_StreamBase
{
  public:
    virtual void* Allocate(unsigned int uiSize);
    virtual void SetBuffer(void* pvData, int iUnk);
    virtual void Unk_03();
    virtual void ReleaseBuffer(int iUnk);

    unsigned int m_uiSize;
    void* m_pResource;
    bool m_bCopied;
    bool m_bSmallOwner;
};

class A72BB0_DataStreamArray
{
  public:
    void* m_pVTable;
    A72BB0_DataStream** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void __thiscall FUN_00a90180(unsigned int uiMaxSize);
    void __thiscall FUN_00ba3aa0(unsigned int uiIndex, A72BB0_DataStream* const& pkElement);
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, A72BB0_DataStream* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00a90180(uiIndex + m_usGrowBy);
        FUN_00ba3aa0(uiIndex, element);
        return uiIndex;
    }

    A72BB0_DataStream* GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};

class A72BB0_DataStreamOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual A72BB0_DataStream* CreateStream();

    int unk04;
    int unk08;
    unsigned short m_usVertexCount;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    A72BB0_DataStreamArray m_kStreams;

    bool __thiscall FUN_00a72bb0(unsigned int uiIndex, void* pvData, unsigned int uiSize, bool bCopy);
};

__declspec(noinline) void A72BB0_DataStreamArray::FUN_00ba3aa0(unsigned int index, A72BB0_DataStream* const& value)
{
    if (index < m_usSize)
    {
        if ((m_pBase[index] != 0) != (value != 0))
        {
            if (value)
                ++m_usESize;
            else
                --m_usESize;
        }
    }
    else
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    m_pBase[index] = value;
}

// Uses or creates the stream at uiIndex, optionally allocates a buffer and copies pvData, then stores the stream and bCopy flag.
// @fnv 0x00a72bb0
bool A72BB0_DataStreamOwner::FUN_00a72bb0(unsigned int uiIndex, void* pvData, unsigned int uiSize, bool bCopy)
{
    A72BB0_DataStream* pkStream = 0;
    if (uiIndex < m_kStreams.GetSize())
        pkStream = m_kStreams.GetAt(uiIndex);

    if (!pkStream)
    {
        pkStream = CreateStream();
        if (!pkStream)
            return false;
    }
    else if (pkStream->m_uiSize != uiSize)
    {
        pkStream->ReleaseBuffer(0);
        pkStream->m_pResource = 0;
    }

    if (!pkStream->m_pResource)
    {

        if (bCopy)
        {
            pkStream->m_bSmallOwner = m_usVertexCount < 0x40;
            void* pvBuffer = pkStream->Allocate(uiSize);
            if (pvData)
                FUN_00ec44d0(pvBuffer, pvData, uiSize);
            pkStream->SetBuffer(pvBuffer, 0);
            pvData = pvBuffer;
        }

        pkStream->m_uiSize = uiSize;
        pkStream->m_pResource = pvData;
    }

    m_kStreams.SetAtGrow(uiIndex, pkStream);
    pkStream->m_bCopied = bCopy;
    return true;
}

struct PolyPoint3
{
    float x, y, z;
    bool operator==(const PolyPoint3& pt) const
    {
        return x == pt.x && y == pt.y && z == pt.z;
    }
    bool operator!=(const PolyPoint3& pt) const
    {
        return !(*this == pt);
    }
};
struct PolyPoint2
{
    float x, y;
    bool operator==(const PolyPoint2& pt) const
    {
        return x == pt.x && y == pt.y;
    }
    bool operator!=(const PolyPoint2& pt) const
    {
        return !(*this == pt);
    }
};
struct PolyColorA
{
    float r, g, b, a;
    bool operator==(const PolyColorA& c) const
    {
        return r == c.r && g == c.g && b == c.b && a == c.a;
    }
    bool operator!=(const PolyColorA& c) const
    {
        return !(*this == c);
    }
};
struct PolyProperty;
struct PolyPropertyState
{
    PolyProperty* m_spProperties[7];
};
class PolyObject
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    bool IsSameAs(PolyObject* pObject);
};
class PolyScreenPolygon : public PolyObject
{
  public:
    PolyPropertyState* m_pGeometryBuffer;
    unsigned short m_usVertices;
    PolyPoint3* m_pkVertex;
    PolyPoint2* m_pkTexture;
    PolyColorA* m_pkColor;
    bool FUN_00a906e0(PolyObject* pObject);
};
// Returns true when IsSameAs succeeds and the vertex counts, vertex values, optional texture and color values, and seven property pointers match.
// @fnv 0x00a906e0
bool PolyScreenPolygon::FUN_00a906e0(PolyObject* pObject)
{
    if (!PolyObject::IsSameAs(pObject))
        return false;

    PolyScreenPolygon* pPolygon = (PolyScreenPolygon*)pObject;

    if (m_usVertices != pPolygon->m_usVertices)
        return false;

    unsigned short i;
    for (i = 0; i < m_usVertices; i++)
    {
        if (m_pkVertex[i] != pPolygon->m_pkVertex[i])
            return false;
    }

    if ((m_pkTexture && !pPolygon->m_pkTexture) || (!m_pkTexture && pPolygon->m_pkTexture))
    {
        return false;
    }

    if (m_pkTexture)
    {
        for (i = 0; i < m_usVertices; i++)
        {
            if (m_pkTexture[i] != pPolygon->m_pkTexture[i])
                return false;
        }
    }

    if ((m_pkColor && !pPolygon->m_pkColor) || (!m_pkColor && pPolygon->m_pkColor))
    {
        return false;
    }

    if (m_pkColor)
    {
        for (i = 0; i < m_usVertices; i++)
        {
            if (m_pkColor[i] != pPolygon->m_pkColor[i])
                return false;
        }
    }

    for (i = 0; i < 7; i++)
    {
        if (m_pGeometryBuffer->m_spProperties[i] != pPolygon->m_pGeometryBuffer->m_spProperties[i])
            return false;
    }

    return true;
}

struct PlainBase
{
    virtual ~PlainBase() throw();
};

void ReleaseObjectArray(void*) throw();

struct S00a915d0_ArrA
{
    virtual ~S00a915d0_ArrA() throw()
    {
        ReleaseObjectArray(m_pData);
    }
    void* m_pData;
    unsigned short unk08;
    unsigned short m_usElementCount;
    unsigned int unk0c;
    void FUN_00a2e620() throw();
    void AssignElement(unsigned int, unsigned int*) throw();
};

struct S00a915d0_ArrB
{
    virtual ~S00a915d0_ArrB() throw()
    {
        ReleaseObjectArray(m_pData);
    }
    void* m_pData;
    unsigned short unk08;
    unsigned short m_usElementCount;
    unsigned int unk0c;
    void FUN_00a2e620() throw();
    void FUN_00a90980(unsigned int, unsigned int*) throw();
};

struct FUN_00a915d0 : PlainBase
{
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    S00a915d0_ArrA m_arr1;
    S00a915d0_ArrB m_arr2;
    virtual ~FUN_00a915d0() throw();
};

// Destroys the object by clearing elements in m_arr1 and m_arr2, then calling FUN_00a2e620 on both arrays.
// @fnv 0x00a915d0
FUN_00a915d0::~FUN_00a915d0() throw()
{
    unsigned int i = 0;
    if (i < m_arr1.m_usElementCount)
    {
        unsigned int tmp = 0;
        do
        {
            m_arr1.AssignElement(i, &tmp);
            ++i;
        } while (i < m_arr1.m_usElementCount);
    }
    m_arr1.FUN_00a2e620();
    unsigned int j = 0;
    if (j < m_arr2.m_usElementCount)
    {
        unsigned int tmp = 0;
        do
        {
            m_arr2.FUN_00a90980(j, &tmp);
            ++j;
        } while (j < m_arr2.m_usElementCount);
    }
    m_arr2.FUN_00a2e620();
}

struct Stream91950
{
    void* m00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(Stream91950*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int components)
    {
        unsigned int read = m08(this, p, n, sizes, components);
        m04 += read;
        return read;
    }
};
struct LoadStream91950 : NiStream
{
    unsigned int unk000;
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
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Stream91950* input;
};
inline unsigned int Version91950(LoadStream91950& s)
{
    return s.version;
}
inline Stream91950* Input91950(LoadStream91950& s)
{
    return s.input;
}
template <class T> inline void Read91950(Stream91950* s, T* p, unsigned int n)
{
    unsigned int size = sizeof(T);
    unsigned int count = n * size;
    s->BinaryRead(p, count, &size, 1);
}
template <class T> inline void Load91950(LoadStream91950& s, T& p)
{
    Read91950(Input91950(s), &p, 1);
}
struct LoadBase91950
{
    void ReadBinary(NiStream&);
    void FUN_00a7b940(NiStream&);
};
struct Element91950;
struct Array91950
{
    unsigned int m_vt;
    Element91950** data;
    unsigned short capacity, size, filled, grow;

    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, Element91950*&);
    void Put(unsigned int i, Element91950* p)
    {
        FUN_00ba3aa0(i, p);
    }
};
struct Point91950
{
    float x, y;
    Point91950()
    {}
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
struct Color91950
{
    float r, g, b, a;
    Color91950() throw();
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
struct Element91950
{
    int m00;
    unsigned short m04, m06;
    Point91950* m08;
    Color91950* m0c;
    Point91950* m10;
};
struct Pool91950
{
    Element91950** m00;
    unsigned int m04, m08, m0c, m10;
    void AppendItems(unsigned int);
    Element91950* Get()
    {
        if (!m08)
        {
            AppendItems(m10);
            m10 *= 2;
        }
        Element91950* p = m00[0];
        m00[0] = m00[--m08];
        return p;
    }
};
struct Host91950 : LoadBase91950
{
    int m00, m04;
    unsigned short m08, m0a;
    int m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c;
    unsigned short m40, m42;
    unsigned int m44;
    unsigned short* m48;
    int m4c, m50, m54;
    bool m58;
    int m5c;
    Array91950 m60;
    void FUN_00a91950(LoadStream91950& stream);
};
void* __cdecl FUN_00aa1070(unsigned int);
// Reads host data from a load stream, dispatching on version, then loads a flag, legacy fields, and an array of vertex/color/texture elements into m60.
// @fnv 0x00a91950
void Host91950::FUN_00a91950(LoadStream91950& stream)
{
    if (Version91950(stream) < 0x0a00010f)
        this->ReadBinary(stream);
    else
        this->FUN_00a7b940(stream);
    unsigned char flag;
    Load91950(stream, flag);
    this->m58 = flag != 0;
    {
        unsigned short legacyCount;
        if (Version91950(stream) < 0x0a00010f)
        {
            Load91950(stream, legacyCount);
            this->m08 = legacyCount;
            Load91950(stream, this->m40);
        }
        if (Version91950(stream) < 0x0a00010f)
        {
            Load91950(stream, legacyCount);
            this->m44 = legacyCount;
            if (legacyCount > 0)
            {
                this->m48 = (unsigned short*)FUN_00aa1070(legacyCount * sizeof(unsigned short));
                Read91950(Input91950(stream), this->m48, legacyCount);
            }
        }
    }
    unsigned int count = 0;
    Load91950(stream, count);
    if (count)
    {
        this->m60.FUN_00a90180(count);
        for (unsigned int i = 0; i < count; ++i)
        {
            unsigned short vertices = 0;
            Load91950(stream, vertices);
            if (vertices)
            {
                Point91950* points = 0;
                Color91950* colors = 0;
                Point91950* textures = 0;
                unsigned short sets = 0;
                unsigned char hasPoints;
                Load91950(stream, hasPoints);
                if (hasPoints)
                {
                    points = new Point91950[vertices];
                    Read91950(Input91950(stream), points, vertices);
                }
                unsigned char hasColors;
                Load91950(stream, hasColors);
                if (hasColors)
                {
                    Color91950* pColors = new Color91950[vertices];
                    if (pColors)
                        colors = pColors;
                    else
                        colors = 0;
                    Read91950(Input91950(stream), colors, vertices);
                }
                Load91950(stream, sets);
                if (sets)
                {
                    unsigned int total = sets * vertices;
                    textures = new Point91950[total];
                    Read91950(Input91950(stream), textures, total);
                }
                Element91950* element = ((Pool91950*)DAT_011f5e50)->Get();
                g_011f6238.FUN_00aa4060(element->m08);
                element->m04 = vertices;
                element->m08 = points;
                g_011f6238.FUN_00aa4060(element->m0c);
                element->m0c = colors;
                g_011f6238.FUN_00aa4060(element->m10);
                element->m10 = textures;
                element->m06 = sets;
                this->m60.FUN_00ba3aa0(i, element);
            }
        }
    }
}

__declspec(noinline) void Array91950::FUN_00ba3aa0(unsigned int i, Element91950*& p)
{
    if (i >= size)
    {
        size = (unsigned short)(i + 1);
        if (p)
            ++filled;
    }
    else if (p)
    {
        if (!data[i])
            ++filled;
    }
    else if (data[i])
    {
        --filled;
    }
    data[i] = p;
}

struct SentinelHolder
{
    ElemBase* p;
    SentinelHolder() : p(0)
    {}
    ~SentinelHolder()
    {
        p = 0;
    }
};

struct FUN_00a90980_cls
{
    int _00;
    ElemBase** m_pData;
    unsigned short _08;
    unsigned short m_usSize;
    unsigned short m_usExtra;
    void FUN_00a90980(unsigned int idx, ElemBase** pp);
};

// Sets the element at idx, updating m_usExtra and reference counts on the old and new ElemBase pointers.
// @fnv 0x00a90980
void FUN_00a90980_cls::FUN_00a90980(unsigned int aiIndex, ElemBase** appElement)
{
    static SentinelHolder s_null;
    if (aiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(aiIndex + 1);
        if (*appElement != s_null.p)
            m_usExtra++;
    }
    else
    {
        ElemBase* pNull = s_null.p;
        if (*appElement != pNull)
        {
            if (m_pData[aiIndex] == pNull)
                m_usExtra++;
        }
        else
        {
            if (m_pData[aiIndex] != pNull)
                m_usExtra--;
        }
    }
    ElemBase** slot = &m_pData[aiIndex];
    ElemBase* old = *slot;
    if (old != *appElement)
    {
        if (old)
        {
            if (!InterlockedDecrement(&old->m_lRef))
                old->f1();
        }
        ElemBase* pNew = *appElement;
        *slot = pNew;
        if (pNew)
            InterlockedIncrement(&pNew->m_lRef);
    }
}

namespace fnv_00a916a0 {
struct CloningProcess;

class NiCloneable : public ScreenReference
{
  public:
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
    virtual void vf10();
    virtual void vf11();
    virtual NiCloneable* MakeClone(CloningProcess& kCloning);
};

class SequenceA : public NiCloneable
{
};
class SequenceB : public NiCloneable
{
};

template <class T> class NiPointer
{
  public:
    NiPointer(T* pObject = 0) throw() : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    NiPointer(const NiPointer& ptr) throw() : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    ~NiPointer() throw()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    NiPointer& operator=(const NiPointer& ptr) throw()
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRef();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->AcquireReference();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator==(T* pObject) const
    {
        return m_pObject == pObject;
    }
    bool operator!=(T* pObject) const
    {
        return m_pObject != pObject;
    }
    T* m_pObject;
};

template <class T> class NiTArray
{
  public:
    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    unsigned int GetGrowBy() const
    {
        return m_usGrowBy;
    }
    void SetGrowBy(unsigned int uiGrowBy)
    {
        m_usGrowBy = (unsigned short)uiGrowBy;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int uiIndex, const T& element) throw()
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else if (m_pBase[uiIndex] != 0)
        {
            m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
};

typedef NiPointer<SequenceA> SequenceAPtr;
typedef NiPointer<SequenceB> SequenceBPtr;

struct ClonerBase
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
    void CopyBaseMembers(ClonerBase* pkDest, CloningProcess& kCloning);
};

struct SequenceOwner : public ClonerBase
{
    NiTArray<SequenceAPtr> m_kSequencesA;
    NiTArray<SequenceBPtr> m_kSequencesB;
    void FUN_00a916a0(SequenceOwner* pkDest, CloningProcess& kCloning) throw();
};
// Copies base members and clones the m_kSequencesA and m_kSequencesB arrays into pkDest using kCloning.
// @fnv 0x00a916a0
void SequenceOwner::FUN_00a916a0(SequenceOwner* pkDest, CloningProcess& kCloning) throw()
{
    CopyBaseMembers(pkDest, kCloning);

    pkDest->m_kSequencesA.SetSize(m_kSequencesA.GetSize());
    pkDest->m_kSequencesA.SetGrowBy(m_kSequencesA.GetGrowBy());
    for (unsigned int ui = 0; ui < m_kSequencesA.GetSize(); ui++)
    {
        SequenceAPtr pListSequence = m_kSequencesA.GetAt(ui);
        if (pListSequence)
            pkDest->m_kSequencesA.SetAt(ui, (SequenceA*)pListSequence->MakeClone(kCloning));
        else
            pkDest->m_kSequencesA.SetAt(ui, 0);
    }

    pkDest->m_kSequencesB.SetSize(m_kSequencesB.GetSize());
    pkDest->m_kSequencesB.SetGrowBy(m_kSequencesB.GetGrowBy());
    for (unsigned int ui = 0; ui < m_kSequencesB.GetSize(); ui++)
    {
        SequenceBPtr pListSequence = m_kSequencesB.GetAt(ui);
        if (pListSequence)
            pkDest->m_kSequencesB.SetAt(ui, (SequenceB*)pListSequence->MakeClone(kCloning));
        else
            pkDest->m_kSequencesB.SetAt(ui, 0);
    }
}
}  // namespace fnv_00a916a0

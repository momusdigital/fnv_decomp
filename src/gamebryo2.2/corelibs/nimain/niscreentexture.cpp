
// src/gamebryo2.2/corelibs/nimain/niscreentexture.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niscreentexture.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const void* g_011f5ee0;

// @fnv 0x00a955f0
const void* __cdecl FUN_00a955f0()
{
    return &g_011f5ee0;
}

struct NiStream;
struct NiObject
{
    virtual bool RegisterStreamables(NiStream&);
};
struct NiTexturingProperty
{
    virtual void F00() = 0;
    virtual void F01() = 0;
    virtual void F02() = 0;
    virtual void F03() = 0;
    virtual void F04() = 0;
    virtual void F05() = 0;
    virtual void F06() = 0;
    virtual void F07() = 0;
    virtual void F08() = 0;
    virtual void F09() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18() = 0;
    virtual void F19() = 0;
    virtual void F20() = 0;
    virtual bool RegisterStreamables(NiStream&) = 0;
};
struct NiScreenTexture : NiObject
{
    char _pad[16];
    NiTexturingProperty* m_pTexturingProperty;
    bool FUN_00a954f0(NiStream&);
};
// Calls NiObject::RegisterStreamables on the stream, then registers the texturing property's streamables; returns false if the base call fails.
// @fnv 0x00a954f0
bool NiScreenTexture::FUN_00a954f0(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    m_pTexturingProperty->RegisterStreamables(kStream);
    return true;
}

extern int DAT_010a048c;
void __cdecl _NiFreeAlias(void*);
struct NiRefObject
{
    ~NiRefObject();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ShadowObj
{
    volatile long m_ref;
    virtual void f0();
    virtual void f1();
};
struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63(void*);
};
struct MyHost
{
    void* __vf;
    int __04;
    void* __08;
    int __0c;
    int __10;
    ShadowObj* __14;
    void FUN_00a95590();
};
// @fnv 0x00a95590
void MyHost::FUN_00a95590()
{
    __vf = (void*)&DAT_010a048c;
    NiRenderer* r = NiRenderer::ms_pRenderer;
    if (r)
        r->v63(this);
    ShadowObj* p = __14;
    if (p)
    {
        if (InterlockedDecrement(&p->m_ref) == 0)
            p->f1();
    }
    _NiFreeAlias(__08);
    ((NiRefObject*)this)->~NiRefObject();
}

namespace fnv_00a95740 {
struct NiScreenTexture
{
    void __thiscall FUN_00a95590();
    void* __thiscall FUN_00a95740(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a95590, then if flags has bit 1 set frees this with size 0x20, and returns this.
// @fnv 0x00a95740
void* __thiscall NiScreenTexture::FUN_00a95740(unsigned int flags)
{
    FUN_00a95590();
    if (flags & 1)
        _delete(this, 0x20);
    return this;
}
}  // namespace fnv_00a95740

struct NiBinaryStream
{
    void* __vf;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                       unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    binstream.Write(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
struct BSStreamHeader
{
    unsigned int m_uiFormatVersion;
    char m_acAuthor[64];
    char m_acProcessScript[64];
    char m_acExportScript[64];
};
struct NiStream
{
    virtual ~NiStream();
    virtual bool Load(NiBinaryStream* pkIstr);
    virtual bool Load(char* pcBuffer, int iBufferSize);
    virtual bool Load(const char* pcName);
    virtual bool Save(NiBinaryStream* pkOstr);
    virtual bool Save(char*& pcBuffer, int& iBufferSize);
    virtual bool Save(const char* pcName);
    virtual void vUnk07();
    virtual void vUnk08();
    virtual bool RegisterSaveObject(NiObject* pkObject);
    virtual void ChangeObject(NiObject* pkNewObject);
    virtual unsigned int GetLinkIDFromObject(const NiObject* pkObject) const;
    virtual void SaveLinkID(const void* pkObject);
    BSStreamHeader m_kHeader;
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
    unsigned int unk1E4;
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
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &value, 1);
}
struct RgbaColor
{
    float r, g, b, a;
    void SaveBinary(NiStream& kStream);
};
struct RendererDataBase_s
{
    void LinkObject(NiStream&);
};
struct RendererDataRecord
{
    short m_sFirstValue;
    short m_sSecondValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    unsigned short m_usThirdValue;
    unsigned short m_usFourthValue;
    RgbaColor m_kFogTint;
};
struct ScreenTex_shell
{
    void* __vf;
    unsigned int m_uiRefCount;
    RendererDataRecord* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    NiObject* m_pTexturingProperty;
    void FUN_00a95a90(NiStream& kStream);
};
// Links the object to the stream, writes the rect count, then serializes each rect's shorts and color, and saves the link ID.
// @fnv 0x00a95a90
void ScreenTex_shell::FUN_00a95a90(NiStream& kStream)
{
    ((RendererDataBase_s*)this)->LinkObject(kStream);
    unsigned int uiNumRects = m_uiAllocatedCapacity;
    SerializeValue(kStream, uiNumRects);
    for (unsigned int i = 0; i < uiNumRects; i++)
    {
        const RendererDataRecord* pDataToSerialize = &m_pBase[i];
        SerializeValue(kStream, pDataToSerialize->m_sFirstValue);
        SerializeValue(kStream, pDataToSerialize->m_sSecondValue);
        SerializeValue(kStream, pDataToSerialize->m_usFirstValue);
        SerializeValue(kStream, pDataToSerialize->m_usSecondValue);
        SerializeValue(kStream, pDataToSerialize->m_usThirdValue);
        SerializeValue(kStream, pDataToSerialize->m_usFourthValue);
        RgbaColor kColor = pDataToSerialize->m_kFogTint;
        kColor.SaveBinary(kStream);
    }
    kStream.SaveLinkID(m_pTexturingProperty);
}

void* __cdecl FUN_00aa1070(unsigned int bytes);
void __cdecl FUN_00aa10f0(void* memory);

struct ScreenRectArray
{
    RendererDataRecord* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void Resize(unsigned int uiNewAlloced);
};

// @fnv 0x00a95520
void ScreenRectArray::Resize(unsigned int uiNewCapacity)
{
    if (uiNewCapacity != m_uiElementCount)
    {
        RendererDataRecord* pNew;
        if (uiNewCapacity > 0)
        {
            pNew = static_cast<RendererDataRecord*>(FUN_00aa1070(uiNewCapacity * sizeof(RendererDataRecord)));
            for (unsigned int i = 0; i < m_uiAllocatedCapacity; ++i)
            {
                pNew[i] = m_pBase[i];
            }
        }
        else
        {
            pNew = 0;
        }
        FUN_00aa10f0(m_pBase);
        m_pBase = pNew;
        m_uiElementCount = uiNewCapacity;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct CopyBase
{
    void CreateVertexBufferSet(void*, void*);
};
struct RefProp
{
    virtual void f00();
    virtual void Destroy();
    volatile long refs;
};
struct RectCopy
{
    short top, left;
    unsigned short width, height, texTop, texLeft;
    RgbaColor color;
    RectCopy(const RectCopy& rhs)
        : top(rhs.top), left(rhs.left), width(rhs.width), height(rhs.height), texTop(rhs.texTop), texLeft(rhs.texLeft),
          color(rhs.color)
    {}
};
struct RectArray
{
    RectCopy* base;
    unsigned int capacity, used;
    void Resize(unsigned int);
    void Add(const RectCopy& rect)
    {
        if (used == capacity)
            Resize(capacity > 0 ? capacity * 2 : 1);
        base[used] = rect;
        ++used;
    }
};
struct ScreenCopy
{
    unsigned int unk00, unk04;
    RectArray rects;
    RefProp* prop;
    unsigned short flags;
    void CopyTo(ScreenCopy* dest, void* cloning);
};
// @fnv 0x00a95760
void ScreenCopy::CopyTo(ScreenCopy* dest, void* cloning)
{
    ((CopyBase*)this)->CreateVertexBufferSet(dest, cloning);
    for (unsigned int i = 0; i < rects.used; i++)
    {
        RectCopy rect(rects.base[i]);
        dest->rects.Add(rect);
    }
    if (dest->prop != prop)
    {
        RefProp* pOldProp = dest->prop;
        if (pOldProp && InterlockedDecrement(&pOldProp->refs) == 0)
            pOldProp->Destroy();
        dest->prop = prop;
        if (dest->prop)
            InterlockedIncrement(&dest->prop->refs);
    }
    dest->flags = flags;
}

extern int DAT_010a048c;
void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject
{
    void* m_pVTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned int unk1C;

    void FUN_00a5d3a0();
};

// @fnv 0x00a958b0
SpawnedObject* __cdecl FUN_00a958b0()
{
    SpawnedObject* p = (SpawnedObject*)FUN_00aa13e0(0x20);
    if (p != 0)
    {
        p->FUN_00a5d3a0();
        *(void* volatile*)&p->m_pVTable = (void*)&DAT_010a048c;
        *(volatile unsigned int*)&p->unk08 = 0;
        *(volatile unsigned int*)&p->unk0C = 0;
        *(volatile unsigned int*)&p->unk10 = 0;
        *(volatile unsigned int*)&p->unk14 = 0;
        *(volatile unsigned int*)&p->unk1C = 0;
        p->unk18 = 0;
    }
    else
    {
        p = 0;
    }
    return p;
}

namespace fnv_00a95600 {
struct NiStream;

struct NiObject
{
    virtual ~NiObject();
    virtual void DeleteThis();
    virtual void LinkObject(NiStream&);
    long refCount;
    char pad[4];

    inline void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
    inline void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
};

struct NiTexturingProperty : NiObject
{
};

struct NiPointer_TexProp
{
    NiTexturingProperty* m_pObject;
};

struct NiStream
{
    NiObject* GetLoadedObject();
};

struct NiScreenTexture : NiObject
{
    char pad[8];
    NiPointer_TexProp m_pTexturingProperty;
    void LinkTexturingProperty(NiStream&);
};

// Links the stream's NiTexturingProperty into the screen texture, releasing the old property and incrementing the new one's ref count.
// @fnv 0x00a95600
void NiScreenTexture::LinkTexturingProperty(NiStream& kStream)
{
    NiObject::LinkObject(kStream);

    NiTexturingProperty* pkProp = (NiTexturingProperty*)kStream.GetLoadedObject();
    if (m_pTexturingProperty.m_pObject != pkProp)
    {
        if (m_pTexturingProperty.m_pObject)
            m_pTexturingProperty.m_pObject->DecRefCount();
        m_pTexturingProperty.m_pObject = pkProp;
        if (m_pTexturingProperty.m_pObject)
            m_pTexturingProperty.m_pObject->IncRefCount();
    }
}
}  // namespace fnv_00a95600

struct ReadBinaryStream
{
    void* vtbl;
    unsigned int absolutePosition;
    unsigned int(__cdecl* m_pfnRead)(ReadBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(ReadBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int components)
    {
        unsigned int n = m_pfnRead(this, buffer, bytes, componentSizes, components);
        absolutePosition += n;
        return n;
    }
};

template <class T> inline void NiBinaryStreamLoad(ReadBinaryStream& binstream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    binstream.Read(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}

struct ReadNiStream
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
    unsigned int unk1E4;
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
    ReadBinaryStream* input;
    void FUN_00a645b0();
};

template <class T> inline void ReadBinaryValue(ReadNiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.input, &value, 1);
}

struct ReadNiColorA
{
    float r, g, b, a;
    void FUN_00a69800(ReadNiStream& stream);
};
struct ReadScreenRect
{
    short pixTop;
    short pixLeft;
    unsigned short pixWidth;
    unsigned short pixHeight;
    unsigned short texTop;
    unsigned short texLeft;
    ReadNiColorA color;
};
struct ReadScreenRectArray
{
    ReadScreenRect* buffer;
    unsigned int capacity;
    unsigned int used;
    void Resize(unsigned int size);
};
struct FUN_00a958f0_Class
{
    void* vtbl;
    unsigned int refCount;
    ReadScreenRectArray rects;
    void ReadGroup(ReadNiStream& stream);
    void ReadScreenRects(ReadNiStream& stream);
};
// Reads a count and that many screen rects from the stream, appending each to rects and growing the array as needed.
// @fnv 0x00a958f0
void FUN_00a958f0_Class::ReadScreenRects(ReadNiStream& stream)
{
    ReadGroup(stream);
    unsigned int count;
    ReadBinaryValue(stream, count);
    for (unsigned int i = 0; i < count; ++i)
    {
        ReadScreenRectArray& arr = rects;
        ReadScreenRect rect;
        rect.color.a = rect.color.b = rect.color.g = rect.color.r = 0.0f;
        ReadBinaryValue(stream, rect.pixTop);
        ReadBinaryValue(stream, rect.pixLeft);
        ReadBinaryValue(stream, rect.pixWidth);
        ReadBinaryValue(stream, rect.pixHeight);
        ReadBinaryValue(stream, rect.texTop);
        ReadBinaryValue(stream, rect.texLeft);
        rect.color.FUN_00a69800(stream);
        if (arr.used == arr.capacity)
        {
            unsigned int newSize = arr.capacity > 0 ? arr.capacity * 2 : 1;
            arr.Resize(newSize);
        }
        arr.buffer[arr.used] = rect;
        ++arr.used;
    }
    stream.FUN_00a645b0();
}

struct S_00a95660_Color
{
    float r, g, b, a;
    __declspec(noinline) bool FUN_004a4c90(const S_00a95660_Color* other);
};
struct S_00a95660_Prop
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
    virtual unsigned char Tail(S_00a95660_Prop* other);
};
struct S_00a95660_Rect
{
    short a, b;
    unsigned short c, d, e, f;
    S_00a95660_Color col;
};
struct S_00a95660_Foo
{
    void* vf;
    unsigned int rc;
    S_00a95660_Rect* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    S_00a95660_Prop* m_pTexturingProperty;
    bool IsSameAs(S_00a95660_Foo* o);
    bool Equals(S_00a95660_Foo* o);
};
// Checks base equality and capacity, examines rectangle fields and colors, then returns the texturing-property comparison.
// @fnv 0x00a95660
bool S_00a95660_Foo::Equals(S_00a95660_Foo* apOther)
{
    if (!IsSameAs(apOther))
        return false;
    unsigned int n = m_uiAllocatedCapacity;
    if (n != apOther->m_uiAllocatedCapacity)
        return false;
    for (unsigned int i = 0; i < n; i++)
    {
        S_00a95660_Rect& refSelf = m_pBase[i];
        S_00a95660_Rect& refOther = apOther->m_pBase[i];
        if (refSelf.a != refOther.a && refSelf.b != refOther.b && refSelf.c != refOther.c && refSelf.d != refOther.d &&
            refSelf.e != refOther.e && refSelf.f != refOther.f)
        {
            if (refSelf.col.FUN_004a4c90(&refOther.col))
                return false;
        }
    }
    S_00a95660_Prop* pSelfProp = m_pTexturingProperty;
    S_00a95660_Prop* pOtherProp = apOther->m_pTexturingProperty;
    return pSelfProp->Tail(pOtherProp);
}

bool S_00a95660_Color::FUN_004a4c90(const S_00a95660_Color* o)
{
    return !(r == o->r && g == o->g && b == o->b && a == o->a);
}

struct ScreenTextureBase : SpawnedObject
{
    ScreenTextureBase() throw()
    {
        FUN_00a5d3a0();
        m_pVTable = &DAT_010a048c;
    }
};

static inline void InitRectArray(unsigned int* p) throw()
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

static inline unsigned int* InitTexProp(unsigned int* p) throw()
{
    *p = 0;
    return p;
}

struct ScreenTextureClone : ScreenTextureBase
{
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    ScreenTextureClone() throw()
    {
        InitRectArray(&unk08);
        InitTexProp(&unk14);
        unk18 = 0;
        unk1C = 0;
    }
};

struct ScreenHost : ScreenCopy
{
    ScreenTextureClone* CreateClone(void* cloning);
};

// Allocates a ScreenTextureClone, copies the source ScreenCopy into it via CopyTo, and returns the new object.
// @fnv 0x00a95c10
ScreenTextureClone* ScreenHost::CreateClone(void* apSource)
{
    ScreenTextureClone* object = new ScreenTextureClone;
    CopyTo(reinterpret_cast<ScreenCopy*>(object), apSource);
    return object;
}

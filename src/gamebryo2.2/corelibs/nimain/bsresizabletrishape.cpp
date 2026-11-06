
// src/gamebryo2.2/corelibs/nimain/bsresizabletrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bsresizabletrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b34;

// @fnv 0x00a86d20
GlobalObjectO2_00a7b610* __cdecl FUN_00a86d20()
{
    return &g_011f5b34;
}

struct NiBound;
struct BSResizableTriShape
{
};

struct FUN_00a86d30_shell : BSResizableTriShape
{
    NiBound* FUN_00a86d30();
};

// @fnv 0x00a86d30
NiBound* __thiscall FUN_00a86d30_shell::FUN_00a86d30()
{
    return (NiBound*)((char*)this + 0xc8);
}

extern "C" void __cdecl _delete(void*, unsigned int);
void __fastcall FUN_00a89760(void*);
extern void* DAT_0109e704;

struct FUN_00a86da0_shell : BSResizableTriShape
{
    void* FUN_00a86da0(unsigned int flags);
};

// Sets the vtable pointer, calls FUN_00a89760 on this, and if flags bit 0 is set deletes this with size 0xd8, returning this.
// @fnv 0x00a86da0
void* FUN_00a86da0_shell::FUN_00a86da0(unsigned int flags)
{
    ((void**)(this))[0] = &DAT_0109e704;
    FUN_00a89760(this);
    if (flags & 1)
        _delete(this, 0xd8);
    return this;
}

struct NiRenderer;
struct NiBound
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    float m_w;
};
struct FUN_00a74600_shell
{
    void __thiscall FUN_00a74600(NiRenderer* apRenderer);
};

struct FUN_00a86e40_shell
{
    void __thiscall FUN_00a86e40(NiRenderer* apRenderer);
};

// Copies four dwords from offsets 0xc8-0xd4 into the NiBound at this+0x20, then calls FUN_00a74600 with the renderer.
// @fnv 0x00a86e40
void __thiscall FUN_00a86e40_shell::FUN_00a86e40(NiRenderer* apRenderer)
{
    float fW = *(float*)(this + 0xd4);
    NiBound* pkDest = *(NiBound**)(this + 0x20);
    pkDest->m_uiX = *(unsigned int*)(this + 0xc8);
    pkDest->m_uiY = *(unsigned int*)(this + 0xcc);
    pkDest->m_uiZ = *(unsigned int*)(this + 0xd0);
    pkDest->m_w = fW;
    ((FUN_00a74600_shell*)this)->FUN_00a74600(apRenderer);
}

struct FUN_00a74480_holder
{
    void __thiscall FUN_00a74480(unsigned int);
};
struct FUN_00a86dd0
{
    FUN_00a86dd0(unsigned int);
};
// Calls the base constructor with a, installs the vtable pointer, and zeroes the field at offset 0xC4.
// @fnv 0x00a86dd0
FUN_00a86dd0::FUN_00a86dd0(unsigned int a)
{
    ((FUN_00a74480_holder*)this)->FUN_00a74480(a);
    *(void**)this = (void*)&DAT_0109e704;
    *(unsigned int*)((char*)this + 0xC4) = 0;
}

struct NiObject;
struct CloningProcess;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void __thiscall FUN_00a744a0();
};
struct FUN_00a744c0_holder
{
    void __thiscall FUN_00a744c0(BSResizableTriShape* pkClone, CloningProcess& kCloning);
};
struct FUN_00a86e80_shell : BSResizableTriShape
{
    NiObject* __thiscall CreateClone(CloningProcess& kCloning);
};
// @fnv 0x00a86e80
NiObject* __thiscall FUN_00a86e80_shell::CreateClone(CloningProcess& kCloning)
{
    BSResizableTriShape* pkObject;
    pkObject = (BSResizableTriShape*)BSFadeNode::operator new(0xD8);
    if (pkObject)
    {
        ((BSFadeNode*)pkObject)->FUN_00a744a0();
        *(void**)pkObject = (void*)&DAT_0109e704;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a744c0_holder*)this)->FUN_00a744c0(pkObject, kCloning);
    *(unsigned int*)((char*)pkObject + 0xC4) = *(unsigned int*)((char*)this + 0xC4);
    return (NiObject*)pkObject;
}

struct NiBinaryStream
{
    int _00;
    int position;
    int _08;
    int(__cdecl* write)(NiBinaryStream*, void*, unsigned int, unsigned int*, int);
};
struct NiStream
{
    char _00[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct FUN_00a71d10_shell
{
    void __thiscall FUN_00a71d10(NiStream&);
};
struct FUN_00a86ed0_shell : BSResizableTriShape
{
    void __thiscall SaveBinary(NiStream&);
};
// @fnv 0x00a86ed0
void __thiscall FUN_00a86ed0_shell::SaveBinary(NiStream& stream)
{
    ((FUN_00a71d10_shell*)this)->FUN_00a71d10(stream);
    NiBinaryStream* __restrict input = stream.m_pBackingStream;
    unsigned int size = 4;
    input->position += input->write(input, (void*)((char*)this + 0xc4), 4, &size, 1);
}

namespace fnv_00a86f10 {
struct NiBinaryStream
{
    unsigned int _m0;
    unsigned int m_pos;
    int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
struct BaseX86f10
{
    void __thiscall FUN_00a98ea0(NiStream&);
};
struct FUN_00a86f10_shell : BaseX86f10
{
    char _pad[0xc4];
    unsigned int m_val;
    void __thiscall ReadValueFromStream(NiStream&);
};
// Calls FUN_00a98ea0, then reads 4 bytes from the stream's binary reader into m_val and advances the stream position.
// @fnv 0x00a86f10
void __thiscall FUN_00a86f10_shell::ReadValueFromStream(NiStream& stream)
{
    FUN_00a98ea0(stream);
    NiBinaryStream* __restrict input = stream.m_pUnderlyingStream;
    unsigned int size = 4;
    input->m_pos += input->m_pfnRead(input, &m_val, 4, &size, 1);
}
}  // namespace fnv_00a86f10

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern unsigned int _NiPoint3_ZERO;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;
struct NiTransformDummy
{
    char d[52];
};
struct NiBoundUpdateHelper
{
    void __thiscall Update(NiBound const&, NiTransformDummy const&);
};
struct WBHelper
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
    virtual void SetWorldBound(NiBound*);
};
struct FUN_00c1a4a0_Shape
{
    void __thiscall UpdateWorldBound();
};
// Allocates and initialises the world bound if absent, then updates it from the object's bound and transform.
// @fnv 0x00c1a4a0
void __thiscall FUN_00c1a4a0_Shape::UpdateWorldBound()
{
    NiBound* kBound;
    if (!*(NiBound**)((char*)this + 0x20))
    {
        kBound = (NiBound*)g_memoryManager.Allocate(16);
        ((WBHelper*)this)->SetWorldBound(kBound);
        kBound = *(NiBound**)((char*)this + 0x20);
        kBound->m_uiX = _NiPoint3_ZERO;
        kBound->m_uiY = *(unsigned int*)&DAT_011f4270;
        kBound->m_uiZ = *(unsigned int*)&DAT_011f4274;
        kBound->m_w = 0.0f;
    }
    ((NiBoundUpdateHelper*)*(NiBound**)((char*)this + 0x20))
        ->Update(*(NiBound*)((char*)this + 0xC8), *(NiTransformDummy*)((char*)this + 0x68));
}

struct StrArr
{
    unsigned char _00[8];
    unsigned short _08;
    unsigned short _0a;
    unsigned short _0c;
    unsigned short _0e;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct Caller74690
{
    void __thiscall FUN_00a74690(StrArr* strings);
};

char* __cdecl _FUN_00a7d330(char* value);
char* __cdecl FUN_00a7d510(char const* text, char const* value);

extern char str_0109e800[];

struct FUN_00a86f50_shell : Caller74690
{
    unsigned char _00[0xc3];
    char* _c4;

    void __thiscall GetViewerStrings(StrArr* strings);
};

// @fnv 0x00a86f50
void FUN_00a86f50_shell::GetViewerStrings(StrArr* strings)
{
    char* value;
    unsigned int index;
    unsigned int count;

    FUN_00a74690(strings);

    value = _FUN_00a7d330(*reinterpret_cast<char**>(&g_011f5b34));
    index = strings->_0a;
    count = strings->_08;

    if (index >= count)
        strings->SetSize(static_cast<unsigned int>(strings->_0e) + index);

    strings->SetAt(index, value);

    value = FUN_00a7d510(str_0109e800, _c4);
    index = strings->_0a;
    count = strings->_08;

    if (index >= count)
        strings->SetSize(static_cast<unsigned int>(strings->_0e) + index);

    strings->SetAt(index, value);
}

struct FUN_00a86e00_cls
{
    void* m_pVTable;
    unsigned int m_i04;
    unsigned int m_i08;
    unsigned int m_i0c;
    unsigned int m_i10;
    unsigned int m_i14;
    unsigned int m_i18;
    unsigned int m_i1c;
    NiBound* m_pBound;
    unsigned int m_i24;
    unsigned int m_i28;
    unsigned int m_i2c;
    unsigned int m_i30;
    unsigned int m_i34;
    unsigned int m_i38;
    unsigned int m_i3c;
    unsigned int m_i40;
    unsigned int m_i44;
    unsigned int m_i48;
    unsigned int m_i4c;
    unsigned int m_i50;
    unsigned int m_i54;
    unsigned int m_i58;
    unsigned int m_i5c;
    unsigned int m_i60;
    unsigned int m_i64;
    unsigned int m_i68;
    unsigned int m_i6c;
    unsigned int m_i70;
    unsigned int m_i74;
    unsigned int m_i78;
    unsigned int m_i7c;
    unsigned int m_i80;
    unsigned int m_i84;
    unsigned int m_i88;
    unsigned int m_i8c;
    unsigned int m_i90;
    unsigned int m_i94;
    unsigned int m_i98;
    unsigned int m_i9c;
    unsigned int m_ia0;
    unsigned int m_ia4;
    unsigned int m_ia8;
    unsigned int m_iac;
    unsigned int m_ib0;
    unsigned int m_ib4;
    unsigned int m_ib8;
    unsigned int m_ibc;
    unsigned int m_ic0;
    unsigned int m_ic4;
    NiBound m_bound;
    void FUN_00a745c0();
    void RenderImmediate();
};

// Copies m_bound into the object pointed to by m_pBound, then calls FUN_00a745c0.
// @fnv 0x00a86e00
void FUN_00a86e00_cls::RenderImmediate()
{
    NiBound* pBound = m_pBound;
    float w = m_bound.m_w;
    pBound->m_uiX = m_bound.m_uiX;
    pBound->m_uiY = m_bound.m_uiY;
    pBound->m_uiZ = m_bound.m_uiZ;
    pBound->m_w = w;
    FUN_00a745c0();
}

void __cdecl FUN_00a98eb0();
// @fnv 0x00a86d40
void __cdecl FUN_00a86d40()
{
    FUN_00a98eb0();
}

void __cdecl FUN_00a74510();

// @fnv 0x00a877f0
void __cdecl FUN_00a877f0()
{
    FUN_00a74510();
}

struct FUN_00a87190_shell : BSResizableTriShape
{
    void __thiscall FUN_00a74500(unsigned int value);
    void __thiscall FUN_00a87190(unsigned int value);
};

// @fnv 0x00a87190
void __thiscall FUN_00a87190_shell::FUN_00a87190(unsigned int value)
{
    FUN_00a74500(value);
}

struct S_00a86d50_Bound
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    float m_w;
};

struct S_00a86d50_WR
{
    float v;
};

struct S_00a86d50_V3
{
    int x;
    int y;
    int z;
};

struct S_00a86d50_Foo
{

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00a86d50_Bound* unk20;

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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;

    S_00a86d50_V3 unkC8;
    float unkD4;

    void __thiscall SetBounds(S_00a86d50_V3 p, S_00a86d50_WR rw);
};

// @fnv 0x00a86d50
void __thiscall S_00a86d50_Foo::SetBounds(S_00a86d50_V3 p, S_00a86d50_WR rw)
{
    this->unkD4 = rw.v;
    float t = rw.v;
    this->unkC8 = p;
    S_00a86d50_Bound* pBound = this->unk20;
    pBound->m_uiX = p.x;
    pBound->m_uiY = p.y;
    pBound->m_uiZ = p.z;
    pBound->m_w = t;
}

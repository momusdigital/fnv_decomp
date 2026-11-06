
// src/gamebryo2.2/corelibs/nimain/nivertexcolorproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nivertexcolorproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiProperty
{
    NiProperty();
};

struct BSFadeNode
{
    static void* operator new(unsigned int);
};

extern int DAT_0109b72c;

// Allocates a 0x1c-byte NiProperty, constructs it, sets a short field at offset 0x18 to 8 and installs the vtable, returning the object or null.
// @fnv 0x00a5f280
NiProperty* FUN_00a5f280()
{
    NiProperty* p = static_cast<NiProperty*>(BSFadeNode::operator new(0x1c));
    if (p)
    {
        p->NiProperty::NiProperty();
        *reinterpret_cast<short*>(reinterpret_cast<char*>(p) + 0x18) = 8;
        *reinterpret_cast<int*>(p) = reinterpret_cast<int>(&DAT_0109b72c);
        return p;
    }
    return 0;
}

struct NiObject
{
    char _x;
};
struct EqBase
{
    char _pad[0x18];
    bool FUN_00a62140(NiObject*);
};
struct NiVertexColorProperty : EqBase
{
    unsigned short m_uiObjectFlags;
    bool IsVertexColorPropertyEqual(NiObject*);
};
// @fnv 0x00a5f090
bool NiVertexColorProperty::IsVertexColorPropertyEqual(NiObject* pkObject)
{
    NiVertexColorProperty* pkVC;
    if (EqBase::FUN_00a62140(pkObject))
    {
        pkVC = (NiVertexColorProperty*)pkObject;
        if ((pkVC->m_uiObjectFlags & 0x30) == (m_uiObjectFlags & 0x30))
        {
            if ((pkVC->m_uiObjectFlags & 8) == (m_uiObjectFlags & 8))
                return true;
        }
    }
    return false;
}

struct StrArr
{
    char _pad[0x08];
    unsigned short _capacity;
    unsigned short _count;
    char _pad2[0x02];
    unsigned short _growBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct FUN_00a62a40_this
{
    void AppendString(StrArr* strings);
};

extern double* _g_011f4430;
char* __cdecl _FUN_00a7d330(double* value);
char* __cdecl BuildSourceString(const char* name, unsigned int value);
char* __cdecl BuildLightingEnumString(const char* name, unsigned int value);

struct FUN_00a5f3a0_shell : NiVertexColorProperty
{
    void AppendVertexColorProperties(StrArr* strings);
};

// @fnv 0x00a5f3a0
void FUN_00a5f3a0_shell::AppendVertexColorProperties(StrArr* strings)
{
    reinterpret_cast<FUN_00a62a40_this*>(this)->AppendString(strings);

    char* value = _FUN_00a7d330(_g_011f4430);
    unsigned int index = strings->_count;
    if (index >= strings->_capacity)
        strings->SetSize(index + strings->_growBy);
    strings->SetAt(index, value);

    unsigned int sourceMode = (m_uiObjectFlags >> 4) & 3;
    value = BuildSourceString("Source Mode", sourceMode);
    index = strings->_count;
    if (index >= strings->_capacity)
        strings->SetSize(index + strings->_growBy);
    strings->SetAt(index, value);

    unsigned int lightingMode = (m_uiObjectFlags >> 3) & 1;
    value = BuildLightingEnumString("Lighting Mode", lightingMode);
    index = strings->_count;
    if (index >= strings->_capacity)
        strings->SetSize(index + strings->_growBy);
    strings->SetAt(index, value);
}

void* __cdecl FUN_00aa13e0(unsigned int size);
void __stdcall CreateVertexBufferSet(void* self, unsigned int arg);

struct NodeBase_b9855
{
    virtual void unk00();
    unsigned int unk04[5];
    unsigned short m_18;
    unsigned short unk1a;
    NodeBase_b9855() throw();
};

struct NodeObj_b9855 : NodeBase_b9855
{
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
    virtual void unk00();
    NodeObj_b9855() throw()
    {
        m_18 = 8;
    }
};

struct FUN_00a5f210_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short m_18;

    void FUN_00a5d7a0(NodeBase_b9855* p, unsigned int arg);
    void* CreateClone(unsigned int a1);
};

// @fnv 0x00a5f210
void* FUN_00a5f210_cls::CreateClone(unsigned int a1)
{
    if (m_0c != 0)
    {
        NodeBase_b9855* p = new NodeObj_b9855();
        FUN_00a5d7a0(p, a1);
        p->m_18 = m_18;
        return p;
    }
    else
    {
        CreateVertexBufferSet(this, a1);
        return this;
    }
}

extern "C" unsigned int __cdecl strlen(const char* s);

void* __cdecl NiMalloc(unsigned int size);
int __cdecl FUN_00a305b0(char* buffer, unsigned int size, const char* format, ...);

// Allocates a buffer and formats name with a lighting enum value (LIGHTING_E, LIGHTING_E_A_D, or UNKNOWN) into it, returning the buffer.
// @fnv 0x00a5f160
char* __cdecl BuildLightingEnumString(const char* name, unsigned int value)
{
    unsigned int size = strlen(name) + 0x1a;
    char* buffer = (char*)NiMalloc(size);
    switch (value)
    {
    case 0:
        FUN_00a305b0(buffer, size, "%s = LIGHTING_E", name);
        break;
    case 1:
        FUN_00a305b0(buffer, size, "%s = LIGHTING_E_A_D", name);
        break;
    default:
        FUN_00a305b0(buffer, size, "%s = UNKNOWN!!!", name);
        break;
    }
    return buffer;
}

void* _NiMalloc(unsigned int);
int _NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string of uiLen + 0x1a bytes and formats pcPrefix with a source name selected by eMode into it, returning the string.
// @fnv 0x00a5f0d0
char* BuildSourceString(const char* pcPrefix, int eMode)
{
    char* pcString;
    unsigned int uiLen = strlen(pcPrefix);

    pcString = (char*)_NiMalloc(uiLen + 0x1a);

    switch (eMode)
    {
    case 0:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_IGNORE", pcPrefix);
        break;

    case 1:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_EMISSIVE", pcPrefix);
        break;

    case 2:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_AMB_DIFF", pcPrefix);
        break;

    default:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}

namespace f2b {
struct Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(Bin*, void*, unsigned int, unsigned int*, unsigned int);
};
struct Stream
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
    unsigned int m_uiFormatVersion;
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
    Bin* m_pkBin;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned short m_usFlags;
};
struct BinX : Bin
{
    unsigned int BinaryRead(void* p, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        unsigned int r = m_pfnRead(this, p, bytes, sizes, n);
        m_uiPos += r;
        return r;
    }
};
template <class T> static __forceinline void BinLoad(BinX* b, T* v, unsigned int n = 1)
{
    unsigned int sz = sizeof(T);
    b->BinaryRead(v, n * sizeof(T), &sz, n);
}
template <class T> static __forceinline void BinRead(Stream* s, T* v)
{
    BinLoad((BinX*)s->m_pkBin, v);
}
static __forceinline void SetBits(unsigned short& f, unsigned int v, unsigned int mask, unsigned int shift)
{
    f = (unsigned short)((f & ~mask) | (v << shift));
}
struct Prop
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short m_usFlags;
    void FUN_00a5d7f0(Stream* s);
    void ReadFromStream(Stream* s);
};
// @fnv 0x00a5f2b0
void Prop::ReadFromStream(Stream* apStream)
{
    FUN_00a5d7f0(apStream);
    if (apStream->m_uiFormatVersion < 0xa000102)
        m_usFlags = apStream->m_usFlags & 7;
    else
        BinRead(apStream, &m_usFlags);
    if (apStream->m_uiFormatVersion < 0x14010002)
    {
        {
            unsigned int uiFlags;
            BinRead(apStream, &uiFlags);
            SetBits(m_usFlags, uiFlags, 0x30, 4);
        }
        {
            unsigned int b;
            BinRead(apStream, &b);
            SetBits(m_usFlags, b, 0x08, 3);
        }
    }
}
}

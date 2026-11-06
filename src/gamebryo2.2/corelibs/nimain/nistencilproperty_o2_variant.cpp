
// src/gamebryo2.2/corelibs/nimain/nistencilproperty_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nistencilproperty.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

class NiRTTI;
class NiStencilProperty
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

class NiObject;
struct EqBase
{
    bool FUN_00a62140(NiObject*);
    bool FUN_00a6f070(NiObject*);
};
// @fnv 0x00a6f070
bool EqBase::FUN_00a6f070(NiObject* pkObject)
{
    NiStencilProperty* pkStencil = (NiStencilProperty*)pkObject;
    if (FUN_00a62140(pkObject) &&
        *(unsigned short*)((char*)pkStencil + 0x18) == *(unsigned short*)((char*)this + 0x18) &&
        *(unsigned int*)((char*)pkStencil + 0x1c) == *(unsigned int*)((char*)this + 0x1c) &&
        *(unsigned int*)((char*)pkStencil + 0x20) == *(unsigned int*)((char*)this + 0x20))
        return true;
    return false;
}

extern "C" unsigned int __cdecl strlen(const char*);
char* __cdecl NiSprintf(char* dst, unsigned int size, const char* fmt, ...);
void* __cdecl NiMalloc(unsigned int size);

// @fnv 0x00a6f2d0
char* FUN_00a6f2d0(const char* name, int stencil)
{
    unsigned int length = strlen(name) + 0x16;
    char* result = (char*)NiMalloc(length);
    switch (stencil)
    {
    case 0:
        NiSprintf(result, length, "%s = DRAW_CCW_OR_BOTH", name);
        break;
    case 1:
        NiSprintf(result, length, "%s = DRAW_CCW", name);
        break;
    case 2:
        NiSprintf(result, length, "%s = DRAW_CW", name);
        break;
    case 3:
        NiSprintf(result, length, "%s = DRAW_BOTH", name);
        break;
    default:
        NiSprintf(result, length, "%s = UNKNOWN!!!", name);
        break;
    }
    return result;
}

extern void* DAT_0101e07c;

struct NiProperty
{
    void NiPropertyCtor();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a6f410
void* __cdecl FUN_00a6f410()
{
    void* p = BSFadeNode::operator new(0x24);
    if (p)
    {
        ((NiProperty*)p)->NiPropertyCtor();
        *(unsigned short*)((char*)p + 0x18) = 0x4180;
        *(void**)p = &DAT_0101e07c;
        *(int*)((char*)p + 0x1c) = 0;
        *(int*)((char*)p + 0x20) = 0xffffffff;
        return p;
    }
    return 0;
}

struct S00a6f4d0
{
    virtual void f0();
    virtual void f1();
    long m_ref;
};
extern S00a6f4d0* DAT_011f4a14;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// @fnv 0x00a6f4d0
void FUN_00a6f4d0()
{
    if (DAT_011f4a14)
    {
        S00a6f4d0* p = DAT_011f4a14;
        if (InterlockedDecrement(&DAT_011f4a14->m_ref) == 0)
            p->f1();
        DAT_011f4a14 = 0;
    }
}

char* __cdecl NiSprintf(char* dst, unsigned int size, const char* fmt, ...);
void* __cdecl NiMalloc(unsigned int size);
// @fnv 0x00a6f1e0
char* FUN_00a6f1e0(const char* name, int stencil)
{
    unsigned int size = strlen(name) + 22;
    char* result = (char*)NiMalloc(size);
    switch (stencil)
    {
    case 0:
        NiSprintf(result, size, "%s = ACTION_KEEP", name);
        break;
    case 1:
        NiSprintf(result, size, "%s = ACTION_ZERO", name);
        break;
    case 2:
        NiSprintf(result, size, "%s = ACTION_REPLACE", name);
        break;
    case 3:
        NiSprintf(result, size, "%s = ACTION_INCREMENT", name);
        break;
    case 4:
        NiSprintf(result, size, "%s = ACTION_DECREMENT", name);
        break;
    case 5:
        NiSprintf(result, size, "%s = ACTION_INVERT", name);
        break;
    default:
        NiSprintf(result, size, "%s = UNKNOWN!!!", name);
        break;
    }
    return result;
}

namespace fnv_00a6f390 {
struct NiObject
{
    void CopyMembersStream(NiObject*, void*);
};
struct CloningProcess;
struct NiCullingProperty
{
    void FUN_00a5d7a0(void*, CloningProcess&);
};
struct NiPropertyCtorStub
{
    void NiPropertyCtor();
};
struct FUN_00a6f390 : NiProperty
{
    void* MakeClone(CloningProcess&);
};
// @fnv 0x00a6f390
void* FUN_00a6f390::MakeClone(CloningProcess& kCloning)
{
    if (*(unsigned int*)((char*)this + 0xc))
    {
        FUN_00a6f390* pkObject = (FUN_00a6f390*)BSFadeNode::operator new(0x24);
        if (pkObject)
        {
            ((NiPropertyCtorStub*)pkObject)->NiPropertyCtor();
            *(void**)((char*)pkObject + 0x00) = &DAT_0101e07c;
            *(unsigned int*)((char*)pkObject + 0x1c) = 0;
            *(unsigned int*)((char*)pkObject + 0x20) = 0xffffffff;
            *(unsigned short*)((char*)pkObject + 0x18) = 0x4180;
        }
        else
        {
            pkObject = 0;
        }
        ((NiCullingProperty*)this)->FUN_00a5d7a0(pkObject, kCloning);
        *(unsigned short*)((char*)pkObject + 0x18) = *(unsigned short*)((char*)this + 0x18);
        *(unsigned int*)((char*)pkObject + 0x1c) = *(unsigned int*)((char*)this + 0x1c);
        *(unsigned int*)((char*)pkObject + 0x20) = *(unsigned int*)((char*)this + 0x20);
        return pkObject;
    }
    else
    {
        ((NiObject*)this)->CopyMembersStream((NiObject*)this, &kCloning);
        return this;
    }
}
}  // namespace fnv_00a6f390

// @fnv 0x00a6f0b0
char* FUN_00a6f0b0(const char* name, int test)
{
    unsigned int size = strlen(name) + 22;
    char* result = (char*)NiMalloc(size);
    switch (test)
    {
    case 0:
        NiSprintf(result, size, "%s = TEST_NEVER", name);
        break;
    case 1:
        NiSprintf(result, size, "%s = TEST_LESS", name);
        break;
    case 2:
        NiSprintf(result, size, "%s = TEST_EQUAL", name);
        break;
    case 3:
        NiSprintf(result, size, "%s = TEST_LESSEQUAL", name);
        break;
    case 4:
        NiSprintf(result, size, "%s = TEST_GREATER", name);
        break;
    case 5:
        NiSprintf(result, size, "%s = TEST_NOTEQUAL", name);
        break;
    case 6:
        NiSprintf(result, size, "%s = TEST_GREATEREQUAL", name);
        break;
    case 7:
        NiSprintf(result, size, "%s = TEST_ALWAYS", name);
        break;
    default:
        NiSprintf(result, size, "%s = UNKNOWN!!!", name);
        break;
    }
    return result;
}

struct Writer;
struct Stream
{
    Writer* writer() const
    {
        return *reinterpret_cast<Writer* const*>(reinterpret_cast<const char*>(this) + 0x250);
    }
};
struct Writer
{
    void* handler0;
    unsigned int bytesWritten;
    void* handler8;
    unsigned int(__cdecl* write)(Writer*, const void*, unsigned int, unsigned int*, unsigned int);
};
struct Base
{
    void FUN_00a5d7b0(Stream*);
};
struct Property : Base
{
    void* unk00;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned short mode;
    unsigned int flags, mask;
    void SaveBinary(Stream*);
};
// @fnv 0x00a6f740
void Property::SaveBinary(Stream* stream)
{
    FUN_00a5d7b0(stream);
    unsigned int size = 2;
    Writer* __restrict w = stream->writer();
    w->bytesWritten += w->write(w, &mode, 2, &size, 1);
    size = 4;
    w = stream->writer();
    w->bytesWritten += w->write(w, &flags, 4, &size, 1);
    size = 4;
    w = stream->writer();
    w->bytesWritten += w->write(w, &mask, 4, &size, 1);
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, size, effectiveSize, growBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Append(char* text)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        SetAt(index, text);
    }
};
struct FUN_00a62a40_this
{
    void AppendString(StrArr*);
};
extern char* DAT_011f4a0c;
char* __cdecl FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d370(const char*, bool);
char* __cdecl FUN_00a7d510(const char*, unsigned int);
char* __cdecl FUN_00a6f0b0(const char*, int);
char* __cdecl FUN_00a6f1e0(const char*, int);
char* __cdecl FUN_00a6f2d0(const char*, int);
struct StencilDebugProperty : FUN_00a62a40_this
{
    void* vtable;
    unsigned int refCount, unk08, unk0c, unk10, unk14;
    unsigned short mode;
    unsigned int reference, mask;
    void GetViewerStrings(StrArr*);
};
// @fnv 0x00a6f7d0
void StencilDebugProperty::GetViewerStrings(StrArr* strings)
{
    AppendString(strings);
    strings->Append(FUN_00a7d330(DAT_011f4a0c));
    bool enabled = (mode & 1) != 0;
    strings->Append(FUN_00a7d370("Enabled", enabled));
    unsigned int ref = reference;
    strings->Append(FUN_00a7d510("m_uiRef", ref));
    unsigned int m = mask;
    strings->Append(FUN_00a7d510("m_uiMask", m));
    int testFunc = mode >> 12;
    strings->Append(FUN_00a6f0b0("Test Funtion", testFunc));
    int failAction = (mode >> 1) & 7;
    strings->Append(FUN_00a6f1e0("Test Fail Action", failAction));
    int depthFailAction = (mode >> 4) & 7;
    strings->Append(FUN_00a6f1e0("Depth Fail Action", depthFailAction));
    int passAction = (mode >> 7) & 7;
    strings->Append(FUN_00a6f1e0("Test Pass Action", passAction));
    int drawMode = (mode >> 10) & 3;
    strings->Append(FUN_00a6f2d0("Draw Mode", drawMode));
}

struct Reader
{
    void* handler;
    unsigned int bytesRead;
    unsigned int(__cdecl* read)(Reader*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int r = read(this, p, n, sizes, count);
        bytesRead += r;
        return r;
    }
    template <class T> unsigned int Read(T* p, unsigned int n)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(p, n * sizeof(T), &size, n);
    }
};
struct Input
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
    Reader* reader;
    template <class T> void Read(T& value)
    {
        reader->Read(&value, 1);
    }
};
enum Compare
{
    C0
};
enum Action
{
    A0
};
enum Draw
{
    D0
};
struct Stencil
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short mode;
    unsigned int flags, mask;
    void FUN_00a5d7f0(Input&);
    void LoadBinary(Input& stream);
};
// @fnv 0x00a6f500
void Stencil::LoadBinary(Input& stream)
{
    FUN_00a5d7f0(stream);
    if (stream.version < 0x14010002)
    {
        bool enabled;
        stream.Read(enabled);
        if (enabled)
            mode |= 1;
        else
            mode &= 0xfffe;
        {
            Compare compare;
            stream.Read(compare);
            mode = (mode & 0xfff) | (compare << 12);
        }
        stream.Read(flags);
        stream.Read(mask);
        {
            Action fail;
            stream.Read(fail);
            mode = (mode & 0xfff1) | (fail << 1);
        }
        {
            Action zfail;
            stream.Read(zfail);
            mode = (mode & 0xff8f) | (zfail << 4);
        }
        {
            Action pass;
            stream.Read(pass);
            mode = (mode & 0xfc7f) | (pass << 7);
        }
        {
            Draw draw;
            stream.Read(draw);
            mode = (mode & 0xf3ff) | (draw << 10);
        }
    }
    else
    {
        stream.Read(mode);
        stream.Read(flags);
        stream.Read(mask);
    }
}

#include <windows.h>
class StencilRefObj
{
  public:
    virtual void f0();
    virtual void f1();
    long m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_18;
    unsigned short unk1a;
    long m_1c;
    long m_20;
};

// @fnv 0x00a6f450
void FUN_00a6f450()
{
    StencilRefObj* obj = (StencilRefObj*)BSFadeNode::operator new(0x24);
    if (obj != 0)
    {
        reinterpret_cast<NiProperty*>(obj)->NiPropertyCtor();
        *(void**)obj = &DAT_0101e07c;
        obj->m_1c = 0;
        obj->m_20 = -1;
        obj->m_18 = 0x4180;
    }
    else
    {
        obj = 0;
    }

    if ((StencilRefObj*)DAT_011f4a14 != obj)
    {
        if (DAT_011f4a14 != 0)
        {
            StencilRefObj* p = (StencilRefObj*)DAT_011f4a14;
            if (InterlockedDecrement(&((StencilRefObj*)DAT_011f4a14)->m_04) == 0)
            {
                p->f1();
            }
        }
        DAT_011f4a14 = reinterpret_cast<S00a6f4d0*>(obj);
        if (obj != 0)
        {
            InterlockedIncrement(&obj->m_04);
        }
    }
}

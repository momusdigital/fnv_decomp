
// src/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00a893b0_shell
{
    void __thiscall SetValues(int a, int b, int c, int d);
};

// @fnv 0x00a893b0
void __thiscall FUN_00a893b0_shell::SetValues(int aiValue0, int aiValue1, int aiValue2, int aiValue3)
{
    *(int*)(this + 0xc) = aiValue0;
    *(int*)(this + 0x10) = aiValue1;
    *(int*)(this + 0x14) = aiValue2;
    *(int*)(this + 0x18) = aiValue3;
}

extern void* g_011f5b68;

// @fnv 0x00a893f0
void* __cdecl FUN_00a893f0()
{
    return &g_011f5b68;
}

extern "C" void __cdecl _FUN_00a7b300();
extern void __cdecl _delete(void*, unsigned int);
extern int DAT_0109eccc;

struct NiColorExtraData_shell
{
    NiColorExtraData_shell* __thiscall Destroy(unsigned int flags);
};

// @fnv 0x00a89560
NiColorExtraData_shell* __thiscall NiColorExtraData_shell::Destroy(unsigned int flags)
{
    *reinterpret_cast<int**>(this) = &DAT_0109eccc;
    _FUN_00a7b300();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct NiStream;

struct NiExtraData
{
    NiExtraData();
    virtual ~NiExtraData();
    void SaveBinary(NiStream& kStream);
};

struct RgbaColor
{
    RgbaColor();
    void SaveBinary(NiStream& kStream);
};

struct NiColorExtraData : NiExtraData
{
    unsigned char _pad[8];
    RgbaColor m_kPrimaryColor;
    void FUN_00a893d0(NiStream& kStream);
};

// @fnv 0x00a893d0
void NiColorExtraData::FUN_00a893d0(NiStream& kStream)
{
    NiExtraData::SaveBinary(kStream);
    m_kPrimaryColor.SaveBinary(kStream);
}

struct NiColor
{
    float r, g, b;
    void __thiscall LoadBinary(NiStream& kStream);
};

struct NiStream
{
    unsigned char _pad[0xd8];
    unsigned int m_uiNifVersion;
};

struct NiColorA_LoadBinary_helper
{
    void __thiscall LoadBinary(NiStream& kStream);
};

struct NiExtraData_LoadBinary_helper
{
    void __thiscall LoadBinary(NiStream& kStream);
};

struct FUN_00a894f0_shell : NiColorExtraData
{
    void FUN_00a894f0(NiStream& kStream);
};

// @fnv 0x00a894f0
void FUN_00a894f0_shell::FUN_00a894f0(NiStream& kStream)
{
    ((NiExtraData_LoadBinary_helper*)this)->LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x0500000e)
    {
        NiColor kTmpColor;
        kTmpColor.r = 0.0f;
        kTmpColor.g = 0.0f;
        kTmpColor.b = 0.0f;
        kTmpColor.LoadBinary(kStream);
        float* pColor = (float*)&m_kPrimaryColor;
        pColor[0] = kTmpColor.r;
        pColor[1] = kTmpColor.g;
        pColor[2] = kTmpColor.b;
        pColor[3] = 1.0f;
    }
    else
    {
        ((NiColorA_LoadBinary_helper*)&m_kPrimaryColor)->LoadBinary(kStream);
    }
}

class A89400CloningProcess;

class A89400ColorA
{
  public:
    float r;
    float g;
    float b;
    float a;

    A89400ColorA() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}

    static const A89400ColorA BLACK;
};

class A89400ExtraData
{
  public:
    A89400ExtraData() throw();
    virtual ~A89400ExtraData();
    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* pvMem);

    void CopyMemberData(A89400ExtraData* pkDest, A89400CloningProcess& kCloning);

    unsigned int m_uiRefCount;
    char* m_kName;
};

class A89400ColorExtraData : public A89400ExtraData
{
  public:
    __forceinline A89400ColorExtraData() throw()
    {
        m_kFogTint = A89400ColorA::BLACK;
    }
    virtual ~A89400ColorExtraData();

    void CopyMemberData(A89400ColorExtraData* pkDest, A89400CloningProcess& kCloning)
    {
        A89400ExtraData::CopyMemberData(pkDest, kCloning);
        pkDest->m_kFogTint = m_kFogTint;
    }
    A89400ColorExtraData* CreateClone(A89400CloningProcess& kCloning);

    A89400ColorA m_kFogTint;
};

// @fnv 0x00a89400
A89400ColorExtraData* A89400ColorExtraData::CreateClone(A89400CloningProcess& kCloning)
{
    A89400ColorExtraData* pkDest = new A89400ColorExtraData;
    CopyMemberData(pkDest, kCloning);
    return pkDest;
}

struct S_00a89590_Member
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_004a4c90(S_00a89590_Member* other);
};

struct S_00a89590
{
    int unk00;
    int unk04;
    int unk08;
    S_00a89590_Member m_unk0c;
    bool IsEqual(S_00a89590* other);
};

// @fnv 0x00a89590
bool S_00a89590::IsEqual(S_00a89590* other)
{
    if (!other)
        return false;
    if (m_unk0c.FUN_004a4c90(&other->m_unk0c))
        return false;
    return true;
}

extern void* g_011f5b68;

struct StreamShell
{
    unsigned char unk0[8];
    unsigned short m_usSize;
    unsigned short m_usPos;
    unsigned short m_usHold;
    unsigned short m_usAdd;

    void FUN_0096ad30(unsigned int uiNewEnd);
    void FUN_0096ae90(unsigned int uiPos, void* pvData);
};

void __stdcall FUN_00a7b580(void* pv);
void* __cdecl FUN_00a7d330(void* pv);

struct NameSink
{
    void* ToString(const char* pcText);
};

class ClaimCls
{
    unsigned char unk0[0xc];
    NameSink m_sink;

  public:
    void WriteColorToStream(StreamShell& kStream);
};

// Writes a pointer obtained from g_011f5b68 and the result of ToString("Color = ") into kStream, growing the stream when its position reaches its size.
// @fnv 0x00a895c0
void ClaimCls::WriteColorToStream(StreamShell& kStream)
{
    FUN_00a7b580(&kStream);
    void* p = FUN_00a7d330(g_011f5b68);
    unsigned int uiPos = kStream.m_usPos;
    unsigned int uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
    }
    kStream.FUN_0096ae90(uiPos, &p);
    p = m_sink.ToString("Color = ");
    uiPos = kStream.m_usPos;
    uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
    }
    kStream.FUN_0096ae90(uiPos, &p);
}

#include <stddef.h>
struct NiExtraData_StandIn
{
    virtual ~NiExtraData_StandIn();
    void FUN_00a7b2e0();
};

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_0109eccc;
extern int DAT_011a9bd0;
extern int DAT_011a9bd4;
extern int DAT_011a9bd8;
extern int DAT_011a9bdc;

// Obtains a 0x1c byte block, calls a method on it, writes a global pointer and four global values, and returns it.
// @fnv 0x00a89490
unsigned int* __cdecl FUN_00a89490()
{
    unsigned int* ptr = (unsigned int*)FUN_00aa13e0(0x1c);

    if (ptr != NULL)
    {
        ((NiExtraData_StandIn*)ptr)->FUN_00a7b2e0();

        ptr[0] = (unsigned int)&DAT_0109eccc;

        float f[4];
        f[0] = 0.0f;
        f[1] = 0.0f;
        f[2] = 0.0f;
        f[3] = 0.0f;

        volatile float* vf = (volatile float*)&ptr[3];
        vf[0] = f[0];
        vf[1] = f[1];
        vf[2] = f[2];
        vf[3] = f[3];

        ptr[3] = DAT_011a9bd0;
        ptr[4] = DAT_011a9bd4;
        ptr[5] = DAT_011a9bd8;
        ptr[6] = DAT_011a9bdc;

        return ptr;
    }

    return NULL;
}

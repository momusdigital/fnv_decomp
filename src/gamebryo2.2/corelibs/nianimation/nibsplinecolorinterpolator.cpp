
// src/gamebryo2.2/corelibs/nianimation/nibsplinecolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibsplinecolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiBSplineColorInterpolator
{
    unsigned int m_kColorACPHandle;
    unsigned int FUN_00a51a20(unsigned short usChannel);
};

// @fnv 0x00a51a20
unsigned int NiBSplineColorInterpolator::FUN_00a51a20(unsigned short usChannel)
{
    if (usChannel)
        return 0xffff;
    return *(unsigned int*)((char*)this + 0x2c);
}

extern char const* const g_011f4024_arg1;

// @fnv 0x00a51aa0
char const* const* __cdecl FUN_00a51aa0()
{
    return &g_011f4024_arg1;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct BaseHolder
{
    void __thiscall FUN_00a57f20(int, int);
};
extern int DAT_01099d3c;
struct Obj34
{
    volatile int vtable;
    char _pad[0x18];
    volatile float f1;
    volatile float f2;
    volatile float f3;
    volatile float f4;
    volatile int unk2c;
    char _tail[0x4];
};
// @fnv 0x00a51c60
void* FUN_00a51c60()
{
    Obj34* p = (Obj34*)BSFadeNode::operator new(52);
    if (p)
    {
        ((BaseHolder*)p)->FUN_00a57f20(0, 0);
        p->vtable = (int)&DAT_01099d3c;
        p->f4 = p->f3 = p->f2 = p->f1 = 0.0f;
        p->unk2c = 0xffff;
        return p;
    }
    return 0;
}

struct S_a50a40
{
    int GetChannelResult(unsigned short usChannel);
};
// @fnv 0x00a50a40
int S_a50a40::GetChannelResult(unsigned short usChannel)
{
    return 0 == usChannel ? 3 : 0;
}

typedef unsigned int A51BF0size_t;

struct A51BF0CloningProcess;

struct A51BF0ColorA
{
    float r;
    float g;
    float b;
    float a;

    A51BF0ColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}
};

struct A51BF0Base
{
    static void* operator new(A51BF0size_t stSize);

    __declspec(nothrow) A51BF0Base(int a, int b);
    virtual ~A51BF0Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    void CopyMemberData(A51BF0Base* pkDest, A51BF0CloningProcess& kCloning);
};

struct A51BF0Property : A51BF0Base
{
    A51BF0ColorA m_kFogTint;
    int m_iFlags;
    int unk30;

    A51BF0Property() : A51BF0Base(0, 0), m_kFogTint(0.0f, 0.0f, 0.0f, 0.0f), m_iFlags(0xffff)
    {}
    virtual ~A51BF0Property();

    void CopyMemberData(A51BF0Property* pkDest, A51BF0CloningProcess& kCloning)
    {
        A51BF0Base::CopyMemberData(pkDest, kCloning);
        pkDest->m_kFogTint = m_kFogTint;
        pkDest->m_iFlags = m_iFlags;
    }

    A51BF0Base* CreateClone(A51BF0CloningProcess& kCloning);
};

// @fnv 0x00a51bf0
A51BF0Base* A51BF0Property::CreateClone(A51BF0CloningProcess& kCloning)
{
    A51BF0Property* pkClone = new A51BF0Property;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

struct NiStream;
typedef int(__cdecl* FNVStreamWrite)(void*, const void*, unsigned int, unsigned int*, int);
struct FNVStreamBuffer
{
    int unk00;
    unsigned int position;
    int unk08;
    FNVStreamWrite write;
};
struct NiStream
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
    unsigned int unk24C;
    FNVStreamBuffer* buffer;
};
struct FUN_00a58160_shell
{
    void SaveToStream(NiStream*);
};
struct NiColorA_SaveHelper
{
    void SaveBinary(NiStream*);
};
// @fnv 0x00a51ca0
void __fastcall FUN_00a51ca0(Obj34* self, void* unused, NiStream* stream)
{
    ((FUN_00a58160_shell*)self)->SaveToStream(stream);
    ((NiColorA_SaveHelper*)&self->f1)->SaveBinary(stream);
    FNVStreamBuffer* writer = stream->buffer;
    {
        int stream = 4;
        writer->position += writer->write(writer, (const void*)&self->unk2c, 4, (unsigned int*)&stream, 1);
    }
}

extern char const* const g_011f4024_arg1;
char* __cdecl FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);
template <class T> struct NiTMallocInterface
{
};
template <class T, class I> struct NiTPrimitiveArray
{
    void* unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > StringArray;
struct Base
{
    void FUN_00a58200(StringArray*);
};
struct Owner : Base
{
    void* unk00;
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
    unsigned int value2c;
    void AppendColorACPHandleStrings(StringArray*);
};
// @fnv 0x00a51d80
void Owner::AppendColorACPHandleStrings(StringArray* array)
{
    FUN_00a58200(array);
    char* value = FUN_00a7d330(g_011f4024_arg1);
    unsigned int index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value);
    value = FUN_00a7d510("m_kColorACPHandle", value2c);
    index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value);
}

struct S_00a50610_Obj
{
    virtual int v0(int a);
    virtual int v1(int a);
    virtual int v2(int a);
    virtual int v3(int a);
    virtual int v4(int a);
    virtual int v5(int a);
    virtual int v6(int a);
    virtual int v7(int a);
    virtual int v8(int a);
    virtual int v9(int a);
    virtual int v10(int a);
    virtual int v11(int a);
    virtual int v12(int a);
    virtual int v13(int a);
    virtual int v14(int a);
    virtual int v15(int a);
    virtual int v16(int a);
    virtual int v17(int a);
    virtual int v18(int a);
    virtual int v19(int a);
    virtual int v20(int a);
    virtual int v21(int a);
    virtual int v22(int a);
    virtual int v23(int a);
    virtual int v24(int a);
    virtual int v25(int a);
    virtual int v26(int a);
    virtual int v27(int a);
    virtual int v28(int a);
    virtual int v29(int a);
    virtual int v30(int a);
    virtual int v31(int a);
    virtual int v32(int a);
    virtual int v33(int a);
    virtual int v34(int a);
    virtual int v35(int a);
    virtual int v36(int a);
    virtual int v37(int a);
    virtual int v38(int a);
    virtual int v39(int a);
    virtual int v40(int a);
    virtual int v41(int a);
    virtual int v42(int a);
    virtual int v43(int a);
    virtual int v44(int a);
    virtual int v45(int a);
    virtual int v46(int a);
    virtual int v47(int a);
    virtual int v48(int a);
    virtual int v49(int a);
    virtual int v50(int a);
    virtual int v51(int a);
    virtual int v52(int a);
    virtual int v53(int a);
    virtual int v54(int a);
    virtual int v55(int a);
    virtual unsigned int vfnE0(unsigned int a);
    bool FUN_00a50610(unsigned short flag);
};

// Returns true when flag is zero and the value returned by vfnE0(0) is not greater than zero; otherwise returns false.
// @fnv 0x00a50610
bool S_00a50610_Obj::FUN_00a50610(unsigned short flag)
{
    if (0 == flag)
    {
        unsigned int r = vfnE0(0);
        return !(0u < r);
    }
    return false;
}

extern "C++" unsigned char __stdcall LoadNiBSplineInterpolator(int value);

// @fnv 0x00a50b10
unsigned char __stdcall FUN_00a50b10(int value)
{
    return LoadNiBSplineInterpolator(value) != 0;
}

struct FUN_00a51a40_cls
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
    unsigned int m_2c;

    void SetValueIfFlagClear(unsigned int value, unsigned short flag);
};

// @fnv 0x00a51a40
void FUN_00a51a40_cls::SetValueIfFlagClear(unsigned int value, unsigned short flag)
{
    if (flag == 0)
    {
        m_2c = value;
    }
}

// The colour interpolator of a B-spline.
//
// The object keeps the two key times of the segment it interpolates, the
// curve that produces the channel values and the colour that was computed
// for the last time stamp.  Evaluating the same time stamp twice is a
// no-op: the colour that is already stored is handed back unchanged.

struct FnvSplineCurve
{
    // Evaluates the curve for the parameter `t` and writes the `n` channel
    // values into `out`.  `idx` is the knot the segment starts at and
    // `flags` selects the interpolation mode.
    void FnvEvalCurve(float t, float* out, int n, int idx, int flags);
};

struct FnvColor4
{
    float r;
    float g;
    float b;
    float a;
};

struct FnvBSplineColorInterpolator
{
    int vtable;
    int unk04;
    float m_fTime;              // +0x08  the time stamp of the last colour
    float m_fKey0;              // +0x0c  the time stamp of the first key
    float m_fKey1;              // +0x10  the time stamp of the second key
    FnvSplineCurve* m_pCurve;   // +0x14  the curve that holds the keys
    int m_nChannel;             // +0x18  the channel the curve is sampled in
    FnvColor4 m_kDiffuseColor;  // +0x1c  the colour of the last evaluation
    int m_iKey;                 // +0x2c  the knot of the segment, 0xffff = none
    bool EvaluateColorAtTime(float fTime, float fUnused, FnvColor4* pOut);
};

// @fnv 0x00a51b10
bool FnvBSplineColorInterpolator::EvaluateColorAtTime(float fTime, float fUnused, FnvColor4* pColorOut)
{
    // The colour is already the one of this time stamp.
    if (m_fTime == fTime)
    {
        *pColorOut = m_kDiffuseColor;
        return true;
    }

    // Only a segment that has a knot can be interpolated.
    if (m_iKey != 0xffff)
    {
        float fNormalizedTime = (fTime - m_fKey0) / (m_fKey1 - m_fKey0);
        float afCurveOut[4];
        m_pCurve->FnvEvalCurve(fNormalizedTime, afCurveOut, 4, m_nChannel, m_iKey);
        FnvColor4 colorResult;
        colorResult.r = afCurveOut[0];
        colorResult.g = afCurveOut[1];
        colorResult.b = afCurveOut[2];
        colorResult.a = afCurveOut[3];
        m_kDiffuseColor = colorResult;
    }

    *pColorOut = m_kDiffuseColor;
    m_fTime = fTime;
    return true;
}

struct FUN_00a51cf0_sub
{
    unsigned int unk00;
    bool FUN_004a4c90(FUN_00a51cf0_sub* other);
};

struct FUN_00a51cf0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FUN_00a51cf0_sub m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int m_2c;

    bool FUN_00a57e90(FUN_00a51cf0_cls* other);
    bool FUN_00a51cf0(FUN_00a51cf0_cls* other);
};
// @fnv 0x00a51cf0
bool FUN_00a51cf0_cls::FUN_00a51cf0(FUN_00a51cf0_cls* other)
{
    if (!FUN_00a57e90(other))
    {
        return false;
    }
    if (m_1c.FUN_004a4c90(&other->m_1c))
    {
        return false;
    }
    bool bEqual = other->m_2c == m_2c;
    return bEqual;
}

// @fnv 0x00a51a00
unsigned int __stdcall FUN_00a51a00(unsigned short usValue)
{
    return (0 == usValue) ? 4 : 0;
}

struct A51D30Input
{
    int unk00;
    int bytesRead;
    int(__cdecl* read)(void* input, void* destination, int size, int* componentSize, int componentCount);
};

struct A51D30BaseLoader
{
    void __thiscall FUN_00a58080(NiStream& stream);
};

struct A51D30ColorLoader
{
    void __thiscall FUN_00a69800(NiStream* stream);
};

struct A51D30Loader : FnvBSplineColorInterpolator
{
    void __thiscall LoadBinary(NiStream* stream);
};

// Loads spline data from a NiStream by calling base and color loader functions, then reading a key value into m_iKey.
// @fnv 0x00a51d30
void A51D30Loader::LoadBinary(NiStream* stream)
{
    reinterpret_cast<A51D30BaseLoader*>(this)->FUN_00a58080(*stream);
    reinterpret_cast<A51D30ColorLoader*>(&m_kDiffuseColor)->FUN_00a69800(stream);
    A51D30Input* input = reinterpret_cast<A51D30Input*>(stream->unk24C);
    {
        int componentSize = 4;
        input->bytesRead += input->read(input, &m_iKey, 4, &componentSize, 1);
    }
}

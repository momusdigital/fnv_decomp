// gamebryo2.2/corelibs/nianimation/nibsplinepoint3interpolator.cpp: NiBSplinePoint3Interpolator, NiBSplineTransformInterpolator (13 functions)

#include "nibsplinepoint3interpolator_decls.h"
// Loads the base interpolator, the point3 value, and the control point handle from the stream.
// @fnv 0x00a50910
void NiBSplinePoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    m_kPoint3Value.LoadBinary(stream);
    stream.input->ReadUInt(m_kPoint3CPHandle);
}

struct CloningProcess;
struct NiBSplineTransformInterpolator
{
    int m_fUnknown1C;
    int m_fUnknown20;
    int m_fUnknown24;
    int m_fUnknown28;
    void FUN_00a57fd0(NiBSplineTransformInterpolator*, CloningProcess&);
    void CopyUnknownFields(NiBSplineTransformInterpolator*, CloningProcess&);
};

// Calls FUN_00a57fd0, then copies the four int fields at offsets 0x1C-0x28 from this into dest.
// @fnv 0x00a50680
void NiBSplineTransformInterpolator::CopyUnknownFields(NiBSplineTransformInterpolator* dest, CloningProcess& process)
{
    NiBSplineTransformInterpolator::FUN_00a57fd0(dest, process);
    int* p = (int*)this;
    int* d = (int*)dest;
    d[7] = p[7];
    d[8] = p[8];
    d[9] = p[9];
    d[10] = p[10];
}

struct FUN_00a506b0_shell : public NiBSplinePoint3Interpolator
{
    void* GetRTTI();
};

extern char const* const g_011f4014_arg1;

// @fnv 0x00a506b0
void* FUN_00a506b0_shell::GetRTTI()
{
    return (void*)&g_011f4014_arg1;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl __Dummy_00b6fef0(void*, int);

struct FUN_00a506f0_shell
{
    void* FUN_00a506f0(unsigned char a2);
};

// @fnv 0x00a506f0
void* FUN_00a506f0_shell::FUN_00a506f0(unsigned char a2)
{
    FUN_00a57f80(this);
    if (a2 & 1)
        __Dummy_00b6fef0(this, 0x2c);
    return this;
}

struct FUN_00a50640_shell
{
    unsigned int GetChannelValue(unsigned short usChannel);
};

// @fnv 0x00a50640
unsigned int FUN_00a50640_shell::GetChannelValue(unsigned short usChannel)
{
    if (usChannel != 0)
        return 0xFFFF;
    return *(unsigned int*)((char*)this + 0x28);
}

struct FUN_00a50660_shell
{
    void SetPoint3ControlHandle(unsigned int kControlHandle, unsigned short usChannel);
};
// @fnv 0x00a50660
void __thiscall FUN_00a50660_shell::SetPoint3ControlHandle(unsigned int kControlHandle, unsigned short usChannel)
{
    if (!usChannel)
        ((NiBSplinePoint3Interpolator*)this)->m_kPoint3CPHandle = kControlHandle;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern int DAT_010996dc;
struct FUN_00a57f20_shell
{
    void __thiscall FUN_00a57f20(int, int);
};

// @fnv 0x00a50840
void* __cdecl FUN_00a50840()
{
    void* p = BSFadeNode::operator new(0x2c);
    if (p)
    {
        ((FUN_00a57f20_shell*)p)->FUN_00a57f20(0, 0);
        *(void**)p = &DAT_010996dc;
        *(int*)((char*)p + 0x28) = 0xffff;
    }
    else
    {
        p = 0;
    }
    return p;
}

struct FUN_00a506c0_shell
{
    void* FUN_00a506c0(int a1, int a2, int a3);
};
// @fnv 0x00a506c0
void* FUN_00a506c0_shell::FUN_00a506c0(int a1, int aiValue, int a3)
{
    ((FUN_00a57f20_shell*)this)->FUN_00a57f20(a1, a3);
    *(void**)this = (void*)&DAT_010996dc;
    *(int*)((char*)this + 0x28) = aiValue;
    return this;
}

struct NiObject;
struct FUN_00a50110_obj
{
    void __thiscall FUN_00a57fd0(FUN_00a50110_obj*, CloningProcess&);
};
struct FUN_00a507e0_obj
{
    char _0[0x1c];
    int _1c;
    int _20;
    int _24;
    int _28;
    NiObject* Clone(CloningProcess& kCloning);
};
// @fnv 0x00a507e0
NiObject* FUN_00a507e0_obj::Clone(CloningProcess& kCloning)
{
    FUN_00a507e0_obj* pkObject = (FUN_00a507e0_obj*)BSFadeNode::operator new(44);
    if (pkObject)
    {
        ((FUN_00a57f20_shell*)pkObject)->FUN_00a57f20(0, 0);
        *(int*)pkObject = (int)&DAT_010996dc;
        pkObject->_28 = 0xffff;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a50110_obj*)this)->FUN_00a57fd0((FUN_00a50110_obj*)pkObject, kCloning);
    pkObject->_1c = this->_1c;
    pkObject->_20 = this->_20;
    pkObject->_24 = this->_24;
    pkObject->_28 = this->_28;
    return (NiObject*)pkObject;
}

template <class T> struct NiTMallocInterface
{
};

template <class T, class A> struct NiTPrimitiveArray
{
};

struct Base
{
    void FUN_00a58200(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
};

struct StrArr
{
    unsigned char m_unknown00[8];
    unsigned short m_pRayCursor;
    unsigned short m_iElementCount;
    unsigned short m_unknown0c;
    unsigned short m_growSize;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

char* __cdecl _FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d510(char const*, unsigned int);

struct FUN_00a50960_shell
{
    unsigned char m_unknown[0x28];
    unsigned int m_kPoint3CPHandle;

    void FUN_00a50960(StrArr* pkStrings);
};

// @fnv 0x00a50960
void FUN_00a50960_shell::FUN_00a50960(StrArr* pkStrings)
{
    reinterpret_cast<Base*>(this)->FUN_00a58200(
        reinterpret_cast<NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*>(pkStrings));

    char* pcString = _FUN_00a7d330(g_011f4014_arg1);

    {
        unsigned int index = pkStrings->m_iElementCount;

        if (index >= pkStrings->m_pRayCursor)
            pkStrings->SetSize(index + pkStrings->m_growSize);

        pkStrings->SetAt(index, pcString);
    }

    pcString = FUN_00a7d510("m_kPoint3CPHandle", m_kPoint3CPHandle);

    {
        unsigned int index = pkStrings->m_iElementCount;

        if (index >= pkStrings->m_pRayCursor)
            pkStrings->SetSize(index + pkStrings->m_growSize);

        pkStrings->SetAt(index, pcString);
    }
}

struct Point3
{
    float x, y, z;
    Point3()
    {}
    Point3(float px, float py, float pz) : x(px), y(py), z(pz)
    {}
};
struct BSplineData
{
    void __thiscall FUN_00a52550(float time, float* output, int components, int offset, int handle);
};
struct FUN_00a50710_shell
{
    void* vtable;
    int unk04;
    float lastTime;
    float startTime;
    float endTime;
    BSplineData* data;
    int dataOffset;
    Point3 lastValue;
    unsigned int handle;
    bool __thiscall SampleBSpline(float time, int unk, Point3* output);
};
// @fnv 0x00a50710
bool FUN_00a50710_shell::SampleBSpline(float time, int aiUnused, Point3* output)
{
    if (lastTime == time)
    {
        *output = lastValue;
        return true;
    }
    if (handle != 0xffff)
    {
        float sample[3];
        data->FUN_00a52550((time - startTime) / (endTime - startTime), sample, 3, dataOffset, handle);
        Point3 value(sample[0], sample[1], sample[2]);
        lastValue = value;
    }
    *output = lastValue;
    lastTime = time;
    return true;
}

class A50880BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A50880BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A50880BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A50880Stream
{
  public:
    int unk000;
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
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    A50880BinaryStream* m_pBackingStream;
};

template <class T>
inline void A50880BinaryStreamSave(A50880BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A50880SaveBinary(A50880Stream& kStream, const T& value)
{
    A50880BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct A50880Color
{
    float r;
    float g;
    float b;

    void SaveBinary(A50880Stream& kStream);
};

class A50880Base
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;

    void SaveToStream(A50880Stream& kStream);
};

class A50880Light : public A50880Base
{
  public:
    A50880Color m_kFogTint;
    float m_fValue;

    void FUN_00a50880(A50880Stream& kStream);
};

// SaveBinary
// @fnv 0x00a50880
void A50880Light::FUN_00a50880(A50880Stream& kStream)
{
    SaveToStream(kStream);
    m_kFogTint.SaveBinary(kStream);
    A50880SaveBinary(kStream, m_fValue);
}

struct S_00a508d0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00439090(S_00a508d0_Sub* p);
};

struct S_00a508d0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00a508d0_Sub sub1c;
    int unk28;
    bool FUN_00a57e90(S_00a508d0_Obj* p);
    bool FUN_00a508d0(S_00a508d0_Obj* p);
};

// @fnv 0x00a508d0
bool S_00a508d0_Obj::FUN_00a508d0(S_00a508d0_Obj* pOther)
{
    if (!FUN_00a57e90(pOther))
        return false;
    if (sub1c.FUN_00439090(&pOther->sub1c))
        return false;
    bool r = pOther->unk28 == unk28;
    return r;
}

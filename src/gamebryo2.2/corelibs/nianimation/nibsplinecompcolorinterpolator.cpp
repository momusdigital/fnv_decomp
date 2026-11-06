
// src/gamebryo2.2/corelibs/nianimation/nibsplinecompcolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibsplinecompcolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

char __stdcall FUN_00a50b10(char);

// @fnv 0x00a51210
char __stdcall FUN_00a51210(char acValue)
{
    char r = FUN_00a50b10(acValue);
    return r != 0;
}

extern "C" void* g_011f4024;

// @fnv 0x00a51770
void* __cdecl FUN_00a51770()
{
    return &g_011f4024;
}

struct CloningProcess;
struct FUN_00a50110_obj
{
    void FUN_00a57fd0(FUN_00a50110_obj*, CloningProcess&);
};

struct NiBSplineColorInterpolator
{
    void CopyTo(FUN_00a50110_obj* source, CloningProcess& proc);
};

// @fnv 0x00a51a60
void NiBSplineColorInterpolator::CopyTo(FUN_00a50110_obj* apTarget, CloningProcess& proc)
{
    ((FUN_00a50110_obj*)this)->FUN_00a57fd0(apTarget, proc);
    *(int*)((char*)apTarget + 0x1c) = *(int*)((char*)this + 0x1c);
    *(int*)((char*)apTarget + 0x20) = *(int*)((char*)this + 0x20);
    *(int*)((char*)apTarget + 0x24) = *(int*)((char*)this + 0x24);
    *(int*)((char*)apTarget + 0x28) = *(int*)((char*)this + 0x28);
    *(int*)((char*)apTarget + 0x2c) = *(int*)((char*)this + 0x2c);
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
struct NiBSplineCompColorInterpolator
{
    void* Destroy(unsigned int);
};
// Calls FUN_00a57f80 on this, frees this with _delete when bit 0 of a is set, and returns this.
// @fnv 0x00a51780
void* NiBSplineCompColorInterpolator::Destroy(unsigned int auiFlags)
{
    FUN_00a57f80(this);
    if (auiFlags & 1)
        _delete(this, 0x3c);
    return this;
}

namespace fnv_00a51970 {
struct NiStream;
struct NiBinaryStream
{
    int _0;
    int m_iPos;
    int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    int(__cdecl* write)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Write(void* p, unsigned int n)
    {
        unsigned int size = 4;
        m_iPos += write(this, p, n, &size, 1);
    }
};
struct NiStream
{
    char _0[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct BaseCall
{
    void FUN_00a51ca0(NiStream&);
};
struct NiBSplineCompColorInterpolator
{
    char _0[0x34];
    int m_iFourthElementInteger[2];
    void SaveToStream(NiStream&);
};
// Calls the base save routine, then writes the two interpolator values (8 bytes) to the stream.
// @fnv 0x00a51970
void NiBSplineCompColorInterpolator::SaveToStream(NiStream& aStream)
{
    ((BaseCall*)this)->FUN_00a51ca0(aStream);
    aStream.m_pBackingStream->Write(m_iFourthElementInteger, 8);
}
}  // namespace fnv_00a51970

namespace fnv_00a51730 {
struct NiObject
{
};
struct FUN_00a51cf0_obj
{
    bool FUN_00a51cf0(NiObject*);
};
struct NiBSplineCompColorInterpolator
{
    char _pad[0x34];
    float m_afOffsetAndHalfRange[2];
    bool IsEqual(NiObject* pkObject);
};
// @fnv 0x00a51730
bool NiBSplineCompColorInterpolator::IsEqual(NiObject* pkObject)
{
    NiBSplineCompColorInterpolator* pkDest;
    unsigned int uiIndex;
    if (!((FUN_00a51cf0_obj*)this)->FUN_00a51cf0(pkObject))
        return false;
    pkDest = (NiBSplineCompColorInterpolator*)pkObject;
    for (uiIndex = 0; uiIndex < 2; uiIndex++)
    {
        if (m_afOffsetAndHalfRange[uiIndex] != pkDest->m_afOffsetAndHalfRange[uiIndex])
            return false;
    }
    return true;
}
}  // namespace fnv_00a51730

namespace fnv_00a51930 {
struct NiBinaryStream
{
    int _pad0;
    int position;
    int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
struct BaseHolder
{
    void LoadBinary(NiStream&);
};
struct NiBSplineCompColorInterpolator
{
    char _pad[0x34];
    float m_data[2];
    void LoadFromStream(NiStream&);
};
// Calls the base holder's stream loader, then reads 8 bytes into m_data through the stream's binary reader.
// @fnv 0x00a51930
void NiBSplineCompColorInterpolator::LoadFromStream(NiStream& stream)
{
    ((BaseHolder*)this)->LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.m_pUnderlyingStream;
    unsigned int size = 4;
    input->position += input->read(input, m_data, 8, &size, 1);
}
}  // namespace fnv_00a51930

namespace fnv_00a519b0 {
char* _FUN_00a7d330(const char*);
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
    void Add(T& v)
    {
        unsigned int s = m_usSize;
        if (s >= m_usMaxSize)
        {
            SetSize(s + m_usGrowBy);
        }
        SetAt(s, v);
    }
};
struct BaseDummy
{
    void AppendColorACPHandleStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
};
struct NiBSplineCompColorInterpolator : BaseDummy
{
    void GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
};
// @fnv 0x00a519b0
void NiBSplineCompColorInterpolator::GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* pkStrings)
{
    AppendColorACPHandleStrings(pkStrings);
    char* pcString = _FUN_00a7d330((const char*)g_011f4024);
    pkStrings->Add(pcString);
}
}  // namespace fnv_00a519b0

static const float DAT_01099c2c = 3.402823466e+38f;
struct NiMemObject
{
    static void* operator new(unsigned int);
};
struct FUN_00a51ab0 : NiMemObject
{
    FUN_00a51ab0(int, int, int) throw();
    virtual void v0()
    {}
    char pad[0x30];
};
struct NiBSplineCompColorInterpolator51 : FUN_00a51ab0
{
    float m_afScalars[2];
    NiBSplineCompColorInterpolator51() : FUN_00a51ab0(0, 0xffff, 0)
    {
        for (int i = 0; i < 2; i++)
            m_afScalars[i] = DAT_01099c2c;
    }
    virtual void v0()
    {}
};
// Allocates and returns a new NiBSplineCompColorInterpolator51 with default scalar values.
// @fnv 0x00a518f0
void* CreateSplineCompColorInterpolator()
{
    return new NiBSplineCompColorInterpolator51;
}

struct RgbaColor
{
    float r, g, b, a;
};
struct NiBSplineData
{
    void FUN_00a526b0(float ratio, RgbaColor* values, unsigned int components, void* controls, unsigned int index,
                      float offset, float scale);
};
struct CompColorInterpolator
{
    void* unk00;
    unsigned int unk04;
    float lastTime;
    float startTime;
    float endTime;
    NiBSplineData* spline;
    void* controlData;
    RgbaColor cached;
    unsigned int startIndex;
    unsigned int unk30;
    float bias;
    float multiplier;
    char EvaluateColor(float time, void* unused, RgbaColor* output);
};
// Samples the spline color at the normalized time when the index is valid, caches it, and writes the cached color to output.
// @fnv 0x00a517a0
char CompColorInterpolator::EvaluateColor(float time, void*, RgbaColor* output)
{
    if (lastTime == time)
    {
        *output = cached;
        return 1;
    }
    if (startIndex != 0xffff)
    {
        RgbaColor values;
        RgbaColor sampledColor;
        spline->FUN_00a526b0((time - startTime) / (endTime - startTime), &values, 4, controlData, startIndex, bias,
                             multiplier);
        sampledColor.r = values.r;
        sampledColor.g = values.g;
        sampledColor.b = values.b;
        sampledColor.a = values.a;
        cached = sampledColor;
    }
    *output = cached;
    lastTime = time;
    return 1;
}

extern void* __cdecl FUN_00aa13e0(unsigned int);
extern const float DAT_01099c2c;
extern int DAT_01099c34;
struct NiBSplineColorInterpolator_a51a60 : NiBSplineColorInterpolator
{
    void CopyTo(FUN_00a50110_obj*, CloningProcess&);
};
struct ColorInterpolatorLayout
{
    void* volatile m_ppVirtualMethodTable;
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
    volatile float m_fStartValue, m_fEndValue;
    void FUN_00a51ab0(int, unsigned int, int);
    ColorInterpolatorLayout* CreateClone(CloningProcess&);
};
// Allocates a new ColorInterpolatorLayout, initializes fields, calls FUN_00a51a60 with it, then copies this object's start and end values.
// @fnv 0x00a51890
ColorInterpolatorLayout* ColorInterpolatorLayout::CreateClone(CloningProcess& process)
{
    ColorInterpolatorLayout* __restrict result = (ColorInterpolatorLayout*)FUN_00aa13e0(0x3c);
    if (result)
    {
        result->FUN_00a51ab0(0, 0xffff, 0);
        result->m_ppVirtualMethodTable = &DAT_01099c34;
        result->m_fStartValue = DAT_01099c2c;
        result->m_fEndValue = DAT_01099c2c;
    }
    else
        result = 0;
    ((NiBSplineColorInterpolator_a51a60*)this)->CopyTo((FUN_00a50110_obj*)result, process);
    result->m_fStartValue = m_fStartValue;
    result->m_fEndValue = m_fEndValue;
    return result;
}

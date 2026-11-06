// gamebryo2.2/corelibs/nianimation/nibsplinecompfloatinterpolator.cpp: NiBSplineCompFloatInterpolator, FObj (10 functions)

#include "nibsplinecompfloatinterpolator_decls.h"
// Calls the base NiBSplineFloatInterpolator::LoadBinary and then reads a value from the stream input into a member.
// @fnv 0x00a51660
void NiBSplineCompFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineFloatInterpolator::LoadBinary(stream);
    stream.input->Read(m_afOffsetAndHalfRange);
}

extern int g_011f401c;

// @fnv 0x00a51520
int* __cdecl FUN_00a51520()
{
    return &g_011f401c;
}

struct FUN_00a52d20_shell
{
    int* m_p;
    int __thiscall FUN_00a52d20(int* b, int* c, char* d);
};

// @fnv 0x00a52d20
int __thiscall FUN_00a52d20_shell::FUN_00a52d20(int* b, int* c, char* d)
{
    int* p = *(int**)((char*)this + 0x10);
    if (p)
    {
        *b = *(int*)((char*)p + 8);
        *c = *(int*)((char*)p + 0x10);
        *d = *(char*)((char*)p + 0x14);
        return *(int*)((char*)p + 0xc);
    }
    *b = 0;
    *c = 0;
    *d = 0;
    return 0;
}

struct FUN_00a57f20_shell
{
    void __thiscall FUN_00a57f20(int a, int b);
};
extern int DAT_010997f4;
struct FUN_00a509f0_shell
{
    FUN_00a509f0_shell* __thiscall FUN_00a509f0(int a, int b, int c);
};
// Calls FUN_00a57f20 with a and c, sets the vtable pointer to DAT_010997f4, stores b at offset 0x20, and returns this.
// @fnv 0x00a509f0
FUN_00a509f0_shell* __thiscall FUN_00a509f0_shell::FUN_00a509f0(int aiArg1, int b, int aiArg2)
{
    ((FUN_00a57f20_shell*)this)->FUN_00a57f20(aiArg1, aiArg2);
    *(int*)this = (int)&DAT_010997f4;
    *(int*)((char*)this + 0x20) = b;
    return this;
}

char* __cdecl _FUN_00a7d330(const char*);
struct StrArr
{
    void* m_pData;
    int _unk4;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _unkC;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
struct BaseX
{
    void __thiscall SerializeToStrings(StrArr*);
};
struct FUN_00a516e0_shell : BaseX
{
    void __thiscall AppendString(StrArr*);
};
// Calls the base handler, gets a string from g_011f401c, grows pkStrings if full, and stores the string at the next free index.
// @fnv 0x00a516e0
void __thiscall FUN_00a516e0_shell::AppendString(StrArr* pkStrings)
{
    SerializeToStrings(pkStrings);
    char* pszString = _FUN_00a7d330((const char*)g_011f401c);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
    {
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uiSize, pszString);
}

struct FUN_00a50b30_shell
{
    bool __thiscall IsInterpEqual(void* pkObject);
};
struct FUN_00a514e0_shell
{
    unsigned char _pad[0x24];
    float m_afOffsetAndHalfRange[2];
    bool __thiscall Equals(void* pkObject);
};
// @fnv 0x00a514e0
bool __thiscall FUN_00a514e0_shell::Equals(void* pkObject)
{
    FUN_00a514e0_shell* pkDest;
    unsigned int iIndex;
    if (!((FUN_00a50b30_shell*)this)->IsInterpEqual(pkObject))
        return false;
    pkDest = (FUN_00a514e0_shell*)pkObject;
    for (iIndex = 0; iIndex < 2; iIndex++)
    {
        if (m_afOffsetAndHalfRange[iIndex] != pkDest->m_afOffsetAndHalfRange[iIndex])
            return false;
    }
    return true;
}

struct BaseShell
{
    void __thiscall LoadFloatInterpolator(void*);
};
struct BinaryOutputStream
{
    int _0;
    int m_pos;
    void* _8;
    int(__cdecl* m_write)(void*, void*, unsigned int, unsigned int*, unsigned int);
};
struct FUN_00a516a0_shell
{
    int _pad[9];
    int m_data[2];
    void __thiscall WriteToStream(void* kStream);
};
// @fnv 0x00a516a0
void __thiscall FUN_00a516a0_shell::WriteToStream(void* kStream)
{
    ((BaseShell*)this)->LoadFloatInterpolator(kStream);
    BinaryOutputStream* __restrict pkOstr = *(BinaryOutputStream**)((char*)kStream + 0x250);
    unsigned int size = 4;
    pkOstr->m_pos += pkOstr->m_write(pkOstr, m_data, 8, &size, 1);
}

struct NiBSplineEvalTarget2
{
    void FUN_00a526b0(float t, float* out, int one, unsigned int m18, unsigned int handle, float a, float b);
};

struct FUN_00a51530_cls
{
    unsigned int unk00;
    unsigned int unk04;
    float m08;
    float m0c;
    float m10;
    NiBSplineEvalTarget2* m14;
    unsigned int m18;
    float m1c;
    unsigned int m20;
    float m24;
    float m28;
    bool EvaluateAtTime(float v, unsigned int unused, float* out);
};

// @fnv 0x00a51530
bool FUN_00a51530_cls::EvaluateAtTime(float afTime, unsigned int unused, float* pfOut)
{
    float t;
    if (m08 == afTime)
    {
        *pfOut = m1c;
        return true;
    }
    unsigned int handle = m20;
    if (handle != 0xffff)
    {
        t = (afTime - m0c) / (m10 - m0c);
        m14->FUN_00a526b0(t, &m1c, 1, m18, handle, m24, m28);
    }
    *pfOut = m1c;
    m08 = afTime;
    return true;
}

void* __cdecl FUN_00aa13e0(unsigned int size);
inline void* operator new(unsigned int, void* q)
{
    return q;
}

static const float kMaxCompScalar = 3.402823466e+38F;

struct FBase
{
    virtual void LoadBinary(NiStream&);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FBase(int a, int b, int c);
};

struct FObj : FBase
{
    float m_afOffsetAndHalfRange[2];
    FObj() : FBase(0, 0xffff, 0)
    {
        float* pfScalars = m_afOffsetAndHalfRange;
        pfScalars[0] = kMaxCompScalar;
        pfScalars[1] = kMaxCompScalar;
    }
    virtual void LoadBinary(NiStream&);
    FObj* __thiscall CreateClone(int arg);
};

struct FUN_00a50aa0_shell
{
    void __thiscall FUN_00a50aa0(FObj* p, int arg);
};

// @fnv 0x00a515c0
FObj* __thiscall FObj::CreateClone(int arg)
{
    FObj* p = (FObj*)FUN_00aa13e0(0x2c);
    if (p)
    {
        new (p) FObj();
    }
    else
    {
        p = 0;
    }

    reinterpret_cast<FUN_00a50aa0_shell*>(this)->FUN_00a50aa0(p, arg);

    p->m_afOffsetAndHalfRange[0] = m_afOffsetAndHalfRange[0];
    p->m_afOffsetAndHalfRange[1] = m_afOffsetAndHalfRange[1];

    return p;
}

class Base51620
{
  public:
    Base51620(int iA, int iB, int iC) throw();
    virtual ~Base51620();
    static void* operator new(unsigned int uiSize);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct ScalarPair51620
{
    float first;
    float second;
    ScalarPair51620() throw() : first(kMaxCompScalar), second(kMaxCompScalar)
    {}
};
class Object51620 : public Base51620
{
  public:
    Object51620() throw() : Base51620(0, 0xffff, 0)
    {}
    ScalarPair51620 scalars;
};

// Allocates and returns a new Object51620 instance with default constructor values.
// @fnv 0x00a51620
Base51620* FUN_00a51620()
{
    return new Object51620;
}

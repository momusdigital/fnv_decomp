
// src/gamebryo2.2/corelibs/nianimation/nicolorextradatacontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicolorextradatacontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    extern void* g_011f3fdc;
}

// @fnv 0x00a4fb00
void* __cdecl FUN_00a4fb00()
{
    return &g_011f3fdc;
}

extern "C" void __cdecl FUN_00a572d0(void);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, int size);

struct FUN_00a4fb10_shell
{
    void* __thiscall FUN_00a4fb10(int p);
};

// @fnv 0x00a4fb10
void* __thiscall FUN_00a4fb10_shell::FUN_00a4fb10(int aiFlags)
{
    FUN_00a572d0();
    if (aiFlags & 1)
    {
        __Dummy_00b6fef0(this, 0x40);
    }
    return this;
}

extern "C" void __cdecl FUN_00a572d0(void);

struct BSFadeNode
{
    static void* operator new(unsigned int size);
};

int* __fastcall InitTimeController(int* p);

extern int DAT_0109947c;

// Allocates a 0x40-byte BSFadeNode, initialises it via InitTimeController, sets its vtable to DAT_0109947c, and returns it (or null on allocation failure).
// @fnv 0x00a4fac0
void* __cdecl FUN_00a4fac0()
{
    void* mem = BSFadeNode::operator new(0x40);
    if (mem)
    {
        int* p = InitTimeController((int*)mem);
        *(int**)(int*)mem = &DAT_0109947c;
        return mem;
    }
    return 0;
}

struct Holder_00a55f80
{
    void* __thiscall FUN_00a55f80(int, float, int);
};
// @fnv 0x00a4fa70
void* __stdcall CreateBlendInterpolator(int a1, int a2, int a3, float a4, int a5)
{
    void* p = BSFadeNode::operator new(0x44);
    if (p)
        return ((Holder_00a55f80*)p)->FUN_00a55f80(a2, a4, a5);
    return 0;
}

struct ColorA
{
    float r, g, b, a;
};
struct Holder9
{
    char _0[12];
    ColorA col;
};
struct Interp9
{
    void* __thiscall FUN_00a3bd80(ColorA c);
};
struct Ctrl9
{
    char _0[0x3c];
    Holder9* fld3c;
    void* __thiscall CreatePoseInterpolator(unsigned short);
};
// @fnv 0x00a4fb30
void* __thiscall Ctrl9::CreatePoseInterpolator(unsigned short usIndex)
{
    void* mem = BSFadeNode::operator new(0x24);
    if (mem)
    {
        Interp9* p = (Interp9*)mem;
        return p->FUN_00a3bd80(fld3c->col);
    }
    return 0;
}

struct RgbaColor
{
    float r, g, b, a;
};
class NiRTTI;
extern NiRTTI _g_011f3730;
class NiObject
{
  public:
    NiObject* DynamicCast(NiRTTI const*);
};
class NiInterpolator : public NiObject
{
};
class NiColorInterpolator : public NiObject
{
  public:
    void SetColorValue(RgbaColor);
};
struct NiColorExtraData
{
    char _0[12];
    RgbaColor m_kFogTint;
};
struct NiColorExtraDataController
{
    char _0[60];
    NiColorExtraData* m_pkExtra;
    void FUN_00a4fc90(NiInterpolator* pkInterp, unsigned short usIndex);
};
// @fnv 0x00a4fc90
void NiColorExtraDataController::FUN_00a4fc90(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiColorInterpolator* pkColorInterp;
    if (!pkInterp)
        pkColorInterp = 0;
    else
        pkColorInterp = (NiColorInterpolator*)pkInterp->DynamicCast(&_g_011f3730);
    pkColorInterp->SetColorValue(m_pkExtra->m_kFogTint);
}

struct StrArr
{
    char _pad0[8];
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrow;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
struct Base57420
{
    void __thiscall FUN_00a57420(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
struct FUN_00a4fd90_shell : Base57420
{
    void __thiscall AppendString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f3fdc) to pkStrings, growing the array if its size has reached its allocation.
// @fnv 0x00a4fd90
void __thiscall FUN_00a4fd90_shell::AppendString(StrArr* pkStrings)
{
    FUN_00a57420(pkStrings);
    char* pcString = _FUN_00a7d330((const char*)g_011f3fdc);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usAlloc)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrow);
    pkStrings->SetAt(uiIndex, pcString);
}

// Stand-in with the target virtual at vtable slot 0xB4/4 = 45
struct InterpVT_00a4faa0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual bool IsCorrectType();
};

// Calls IsCorrectType on the interpolator's vtable and returns the result, ignoring the index.
// @fnv 0x00a4faa0
bool __stdcall FUN_00a4faa0(NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    return reinterpret_cast<InterpVT_00a4faa0*>(pkInterpolator)->IsCorrectType();
}

void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_0109947c;

struct FUN_00a4fb80_obj
{
    void* m_pVTable;
    char unk04[0x3c];
};

struct FUN_00a4fb80_cls
{
    void FUN_00c312f0(FUN_00a4fb80_obj* p, unsigned int arg);
    FUN_00a4fb80_obj* CreateObject(unsigned int arg);
};

// Allocates a 0x40-byte object, initialises it with InitTimeController and a vtable, then calls FUN_00c312f0 with arg and returns it.
// @fnv 0x00a4fb80
FUN_00a4fb80_obj* FUN_00a4fb80_cls::CreateObject(unsigned int arg)
{
    FUN_00a4fb80_obj* p = (FUN_00a4fb80_obj*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        InitTimeController((int*)p);
        p->m_pVTable = (void*)&DAT_0109947c;
    }
    else
    {
        p = 0;
    }
    FUN_00c312f0(p, arg);
    return p;
}

class NiColorAA4F
{
  public:
    NiColorAA4F(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }

    float r;
    float g;
    float b;
    float a;
};

class NiObjectNETA4F;

class NiInterpolatorA4F
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual bool Update(float fTime, NiObjectNETA4F* pkInterpTarget, NiColorAA4F& kValue);
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual bool AlwaysUpdate() const;
};

class NiColorTargetA4F
{
  public:
    void SetColor(NiColorAA4F kColor);
};

extern const float INVALID_TIME_A4F;

class NiUpdateDataA4F
{
  public:
    float m_fTime;
};

class NiTimeControllerA4F
{
  public:
    enum
    {
        MANAGERCONTROLLED_MASK = 0x0020,
        MANAGERCONTROLLED_POS = 5
    };

    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return (bool)(GetField(MANAGERCONTROLLED_MASK, MANAGERCONTROLLED_POS) & 1);
    }
    bool AdvanceController(float fTime);

    int unk00;
    int unk04;
    unsigned short m_uiObjectFlags;
    short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    float m_fControllerTime;
    NiObjectNETA4F* m_pkTarget;
};

class NiColorControllerA4F : public NiTimeControllerA4F
{
  public:
    void UpdateColorController(NiUpdateDataA4F& kUpdateData);

    int unk30;
    NiInterpolatorA4F* m_spControllerInterpolator;
    int unk38;
    NiColorTargetA4F* m_pkColorTarget;
};

// @fnv 0x00a4fce0
void NiColorControllerA4F::UpdateColorController(NiUpdateDataA4F& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = INVALID_TIME_A4F;
    }
    else if (AdvanceController(kUpdateData.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        NiColorAA4F kColor;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, kColor))
        {
            if (m_pkColorTarget)
                m_pkColorTarget->SetColor(kColor);
        }
    }
}

extern "C" void __cdecl IsEquivalent();

// @fnv 0x00a4faf0
void __cdecl FUN_00a4faf0()
{
    IsEquivalent();
}

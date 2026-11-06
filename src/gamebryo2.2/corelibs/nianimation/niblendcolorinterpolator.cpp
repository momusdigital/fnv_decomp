
// src/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream;

struct RgbaColor
{
    void SaveBinary(NiStream& kStream);
};

struct FUN_00a37ec0_tgt
{
    void FUN_00a37ec0(NiStream& kStream);
};

struct NiBlendColorInterpolator
{
    char m_Base[0x30];
    RgbaColor m_kColorValue;
    void FUN_00a56040(NiStream& kStream);
};

// @fnv 0x00a56040
void NiBlendColorInterpolator::FUN_00a56040(NiStream& kStream)
{
    ((FUN_00a37ec0_tgt*)this)->FUN_00a37ec0(kStream);
    m_kColorValue.SaveBinary(kStream);
}

extern "C" void* g_011f4074;

// @fnv 0x00a56060
void* __cdecl FUN_00a56060()
{
    return &g_011f4074;
}

void __fastcall FUN_00a36890(void*);
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern RgbaColor const DAT_011a9430;
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;
extern int DAT_0109a58c;

// @fnv 0x00a55ff0
NiBlendColorInterpolator* __cdecl CreateBlendColorInterpolator()
{
    NiBlendColorInterpolator* pInterpolator = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pInterpolator)
    {
        FUN_00a36890(pInterpolator);
        *(int*)pInterpolator = (int)&DAT_0109a58c;
        *(int*)((char*)pInterpolator + 0x30) = *(int*)&DAT_011a9430;
        *(int*)((char*)pInterpolator + 0x34) = DAT_011a9434;
        *(int*)((char*)pInterpolator + 0x38) = DAT_011a9438;
        *(int*)((char*)pInterpolator + 0x3c) = DAT_011a943c;
        *(char*)((char*)pInterpolator + 0x40) = 0;
    }
    else
    {
        pInterpolator = 0;
    }
    return pInterpolator;
}

struct NiBlendInterpolator
{
    NiBlendInterpolator(bool, float, unsigned char);
    char _pad[0x30];
};
struct FUN_00a55f80 : NiBlendInterpolator
{
    char _c[0x10];
    bool m_kPointB;
    FUN_00a55f80(bool, float, unsigned char);
};
// Constructs the object: installs the vtable, copies four ints from DAT_011a9430 into offset 0x30, and clears the flag at the end.
// @fnv 0x00a55f80
FUN_00a55f80::FUN_00a55f80(bool a, float b, unsigned char c) : NiBlendInterpolator(a, b, c)
{
    *(void**)this = (void*)&DAT_0109a58c;
    ((int*)((char*)this + 0x30))[0] = ((int*)&DAT_011a9430)[0];
    ((int*)((char*)this + 0x30))[1] = ((int*)&DAT_011a9430)[1];
    ((int*)((char*)this + 0x30))[2] = ((int*)&DAT_011a9430)[2];
    ((int*)((char*)this + 0x30))[3] = ((int*)&DAT_011a9430)[3];
    m_kPointB = 0;
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl _delete(void*, unsigned int);
struct NiBlendColorInterpolator_shell : NiBlendColorInterpolator
{
    void* FUN_00a56070(unsigned int flags);
};
// @fnv 0x00a56070
void* NiBlendColorInterpolator_shell::FUN_00a56070(unsigned int flags)
{
    DestroyInterpolatorArray(this);
    if (flags & 1)
        _delete(this, 0x44);
    return this;
}

namespace fnv_00a56460 {
struct NiColorA_Helper
{
    void LoadBinary(NiStream&);
};
struct NiBlendInterpolator
{
    void LoadBinary(NiStream&);
};
struct NiColorA_Compare
{
    bool operator!=(RgbaColor const* other);
};

struct NiBlendColorInterpolator_shell : public NiBlendInterpolator
{
    void FUN_00a56460(NiStream& kStream);
};

// @fnv 0x00a56460
void NiBlendColorInterpolator_shell::FUN_00a56460(NiStream& kStream)
{
    ((NiBlendInterpolator*)this)->LoadBinary(kStream);
    ((NiColorA_Helper*)((char*)this + 0x30))->LoadBinary(kStream);
    if (((NiColorA_Compare*)((char*)this + 0x30))->operator!=(&DAT_011a9430))
        *(bool*)((char*)this + 0x40) = true;
}
}  // namespace fnv_00a56460

// ---- stand-in for NiInterpolator (not declared in unit prelude) ----
struct NiInterpolator
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
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
    virtual bool ControlsTransform();
};

// Calls the interpolator's virtual method at slot 44 and returns its boolean result.
// @fnv 0x00a55fd0
bool __stdcall FUN_00a55fd0(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->ControlsTransform();
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct CloneOwner
{
    void FUN_00a37510(void*, void*);
};
struct FUN_00a56090_shell : NiBlendColorInterpolator
{
    void* CreateClone(CloningProcess&);
};
// Allocates a NiBlendColorInterpolator, initialises it from DAT_011a9430, copies color fields from this, and returns the clone.
// @fnv 0x00a56090
void* FUN_00a56090_shell::CreateClone(CloningProcess& kCloning)
{
    NiBlendColorInterpolator* pkObject = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pkObject)
    {
        FUN_00a36890(pkObject);
        *(void**)pkObject = &DAT_0109a58c;
        *(int*)((char*)pkObject + 0x30) = *(int*)&DAT_011a9430;
        *(int*)((char*)pkObject + 0x34) = DAT_011a9434;
        *(int*)((char*)pkObject + 0x38) = DAT_011a9438;
        *(int*)((char*)pkObject + 0x3c) = DAT_011a943c;
        ((char*)pkObject)[0x40] = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((CloneOwner*)this)->FUN_00a37510(pkObject, &kCloning);
    {
        char* pDest = (char*)pkObject;
        char* pSrc = (char*)this;
        *(int*)(pDest + 0x30) = *(int*)(pSrc + 0x30);
        *(int*)(pDest + 0x34) = *(int*)(pSrc + 0x34);
        *(int*)(pDest + 0x38) = *(int*)(pSrc + 0x38);
        *(int*)(pDest + 0x3c) = *(int*)(pSrc + 0x3c);
        pDest[0x40] = pSrc[0x40];
    }
    return pkObject;
}

// ---- placeholder declarations ----
struct NiObjectNET;
struct NiBlendColorInterpolator;

struct FUN_00a56110_shell;
struct FUN_00a561c0_shell;

struct FUN_00a37260_shell
{
    void UpdateNormalizedWeights();
};

struct FUN_00a56400_shell : NiBlendColorInterpolator
{
    bool GetColorAtTime(float fTime, NiObjectNET* pkTarget, RgbaColor* kValue);
    bool UpdateBlend(float fTime, NiObjectNET* pkTarget, RgbaColor* kValue);
    bool InterpolateValue(float fTime, NiObjectNET* pkInterpTarget, RgbaColor& kValue);
};

// @fnv 0x00a56400
bool FUN_00a56400_shell::InterpolateValue(float fTime, NiObjectNET* pkInterpTarget, RgbaColor& kValue)
{
    bool bReturnValue = false;
    unsigned char ucInterpCount = *(unsigned char*)((char*)this + 0xe);
    if (ucInterpCount == 1)
    {
        bReturnValue = GetColorAtTime(fTime, pkInterpTarget, &kValue);
    }
    else if (ucInterpCount > 0)
    {
        ((FUN_00a37260_shell*)this)->UpdateNormalizedWeights();
        bReturnValue = UpdateBlend(fTime, pkInterpTarget, &kValue);
    }
    *(float*)((char*)this + 8) = fTime;
    return bReturnValue;
}

extern float DAT_0109696c;

struct FUN_00a56110_color
{
    int c00;
    int c04;
    int c08;
    int c0c;
};

struct FUN_00a56110_target
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual bool GetColor(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kValue);
};

struct FUN_00a56110_shell
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int unk10;
    int unk14;
    FUN_00a56110_target* pTarget;
    int unk1c;
    float fValue20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00a56110_color color30;
    bool GetColorAtTime(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kOut);
};

// @fnv 0x00a56110
bool FUN_00a56110_shell::GetColorAtTime(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kOut)
{
    if (flags0c & 1)
    {
        fTime = fValue20;
    }
    if (fTime == DAT_0109696c)
    {
        return false;
    }
    if (pTarget->GetColor(fTime, pkTarget, &color30))
    {
        *kOut = color30;
        return true;
    }
    const int* piDefaultColor = reinterpret_cast<const int*>(&DAT_011a9430);
    kOut->c00 = piDefaultColor[0];
    kOut->c04 = piDefaultColor[1];
    kOut->c08 = piDefaultColor[2];
    kOut->c0c = piDefaultColor[3];
    color30 = *kOut;
    return false;
}

bool __stdcall FUN_00a36fd0(void* pkObject);

struct NiColorA_shell : RgbaColor
{
    bool FUN_004a4c90(void* pkOther);
};

struct FUN_00a564a0_cls : NiBlendColorInterpolator
{
    bool IsEqual(void* pkOther);
};

// @fnv 0x00a564a0
bool FUN_00a564a0_cls::IsEqual(void* pkOther)
{
    if (!FUN_00a36fd0(pkOther))
    {
        return false;
    }
    void* pkSub = (char*)pkOther + 0x30;
    NiColorA_shell* pkColor = (NiColorA_shell*)&m_kColorValue;
    unsigned char bOk = pkColor->FUN_004a4c90(pkSub) == 0;
    return bOk;
}

extern "C" void* g_011f4074;
extern int DAT_01096f1c;
void* __cdecl FUN_00a7d330(void*);

struct ArraySource
{
    virtual ~ArraySource();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void** result);
};
struct AssignmentMember
{
    void* ToString(const int*);
};
struct FUN_00a564d0_shell
{
    void FUN_00a38080(ArraySource* source);
    void AppendTwoEntries(ArraySource* source);
};
// Calls FUN_00a38080, then appends the result of FUN_00a7d330 and a member lookup from offset 0x30 into the array source, growing it as needed.
// @fnv 0x00a564d0
void FUN_00a564d0_shell::AppendTwoEntries(ArraySource* pArraySource)
{
    FUN_00a38080(pArraySource);
    void* result = FUN_00a7d330(g_011f4074);
    unsigned int index = pArraySource->m_usSize;
    if (index >= pArraySource->m_usMaxSize)
        pArraySource->FUN_0096ad30(index + pArraySource->m_usGrowBy);
    pArraySource->FUN_0096ae90(index, &result);
    result = reinterpret_cast<AssignmentMember*>(reinterpret_cast<char*>(this) + 0x30)->ToString(&DAT_01096f1c);
    index = pArraySource->m_usSize;
    if (index >= pArraySource->m_usMaxSize)
        pArraySource->FUN_0096ad30(index + pArraySource->m_usGrowBy);
    pArraySource->FUN_0096ae90(index, &result);
}

struct CA61c0
{
    float r, g, b, a;
    CA61c0()
    {}
    CA61c0(float r0, float g0, float b0, float a0)
    {
        r = r0;
        g = g0;
        b = b0;
        a = a0;
    }
    CA61c0 operator*(float f) const
    {
        CA61c0 res = *this;
        res.r *= f;
        res.g *= f;
        res.b *= f;
        res.a *= f;
        return res;
    }
    CA61c0& operator+=(CA61c0 c)
    {
        CA61c0& t = *this;
        t.r += c.r;
        g += c.g;
        t.b += c.b;
        a += c.a;
        return *this;
    }
    CA61c0& operator/=(float f)
    {
        r /= f;
        g /= f;
        b /= f;
        a /= f;
        return *this;
    }
};
struct Interp61c0
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
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
    virtual bool Update(float fTime, NiObjectNET* pkTarget, CA61c0& kValue);
};
struct SP61c0
{
    Interp61c0* m_pObject;
    operator Interp61c0*() const
    {
        return m_pObject;
    }
    Interp61c0* operator->() const
    {
        return m_pObject;
    }
};
struct Item61c0
{
    SP61c0 m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
struct Blend61c0
{
    int pad0[3];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    char pad0e[6];
    Item61c0* m_pInterpArray;
    int pad18[6];
    CA61c0 m_kColorValue;
    bool m_bValueValid;
    bool GetUpdateTimeForItem(float& fTime, Item61c0& kItem)
    {
        Interp61c0* pkInterpolator = kItem.m_spControllerInterpolator;
        if (pkInterpolator && kItem.m_fNormalizedWeight != 0.0f)
        {
            if (m_uiObjectFlags & 1)
                fTime = kItem.m_fLastEvaluationTime;
            if (fTime == DAT_0109696c)
                return false;
            return true;
        }
        return false;
    }
    bool UpdateBlend(float fTime, NiObjectNET* pkInterpTarget, CA61c0& kValue);
};
// @fnv 0x00a561c0
bool Blend61c0::UpdateBlend(float fTime, NiObjectNET* pkInterpTarget, CA61c0& kValue)
{
    m_bValueValid = false;
    m_kColorValue = CA61c0(0.0f, 0.0f, 0.0f, 0.0f);
    float fTotalWeight = 1.0f;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        Item61c0& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && kItem.m_fNormalizedWeight > 0.0f)
        {
            CA61c0 kTempValue(0.0f, 0.0f, 0.0f, 0.0f);
            float fUpdateTime = fTime;
            Item61c0& kItem2 = m_pInterpArray[uc];
            if (!GetUpdateTimeForItem(fUpdateTime, kItem2))
            {
                fTotalWeight -= kItem.m_fNormalizedWeight;
                continue;
            }
            bool bSuccess = kItem.m_spControllerInterpolator->Update(fUpdateTime, pkInterpTarget, kTempValue);
            if (bSuccess)
            {
                m_kColorValue += kTempValue * m_pInterpArray[uc].m_fNormalizedWeight;
                m_bValueValid = true;
            }
            else
            {
                fTotalWeight -= m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!m_bValueValid)
    {
        m_kColorValue = *(const CA61c0*)&DAT_011a9430;
        kValue = m_kColorValue;
        return false;
    }
    m_kColorValue /= fTotalWeight;
    kValue = m_kColorValue;
    return true;
}

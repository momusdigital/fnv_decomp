
// src/gamebryo2.2/corelibs/nianimation/niboolinterpcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niboolinterpcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiBlendInterpolator;
NiBlendInterpolator* __fastcall ConstructBlendInterpolator(NiBlendInterpolator*, int, int, float, int);
// @fnv 0x00a57750
NiBlendInterpolator* __stdcall FUN_00a57750(int aiUnused, int aiArg, int aiUnused2, float a4, int a5)
{
    void* pMemory = BSFadeNode::operator new(0x34);
    if (pMemory)
        return ConstructBlendInterpolator((NiBlendInterpolator*)pMemory, aiArg, aiArg, a4, a5);
    return 0;
}

extern char const* const g_011f3f08_arg1;
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00a390a0(StrArr*);
char* __cdecl FUN_00a7d330(const char*);
// Appends the string returned by FUN_00a7d330(g_011f3f08_arg1) to the StrArr at index e, growing it by the value at offset 14 plus e when e >= c.
// @fnv 0x00a57800
void __stdcall FUN_00a57800(StrArr* apStrings)
{
    FUN_00a390a0(apStrings);
    char* pString = FUN_00a7d330(g_011f3f08_arg1);
    unsigned int e = *(unsigned short*)((char*)apStrings + 10);
    unsigned int c = *(unsigned short*)((char*)apStrings + 8);
    if (e >= c)
        apStrings->SetSize(*(unsigned short*)((char*)apStrings + 14) + e);
    apStrings->SetAt(e, pString);
}

class NiRTTI;
extern unsigned int DAT_011f404c;
class NiObject
{
  public:
    NiObject* DynamicCast(const NiRTTI*);
};
class NiInterpolator : public NiObject
{
};
class NiBoolInterpolator : public NiObject
{
  public:
    void SetBoolValue(bool);
};
class NiSingleInterpController
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void GetPoseValue(bool&);
};
class NiBoolInterpController : public NiSingleInterpController
{
  public:
    void SetBoolInterpolatorValue(NiInterpolator*, unsigned short);
};
// Casts pkInterp to a NiBoolInterpolator, reads the pose value and passes it to the interpolator's setter.
// @fnv 0x00a577c0
void NiBoolInterpController::SetBoolInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    bool bPoseValue;
    NiBoolInterpolator* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = (NiBoolInterpolator*)pkInterp->DynamicCast((const NiRTTI*)&DAT_011f404c);
    GetPoseValue(bPoseValue);
    pkBoolInterp->SetBoolValue(bPoseValue);
}

class S2
{
  public:
    void* FUN_00a532d0(int value);
};
class NiBoolInterpControllerShim : public NiBoolInterpController
{
  public:
    NiInterpolator* CreatePoseInterpolator(int unused);
};
// @fnv 0x00a57710
NiInterpolator* NiBoolInterpControllerShim::CreatePoseInterpolator(int unused)
{
    union BoolWord
    {
        bool flag;
        int word;
    } value;
    GetPoseValue(value.flag);
    S2* result = (S2*)BSFadeNode::operator new(0x18);
    if (result)
        return (NiInterpolator*)result->FUN_00a532d0(value.word);
    return 0;
}

struct FUN_00a57c10_This
{
    int unk34;
};

struct StandIn
{
    int __thiscall FUN_00a57c10(FUN_00a57c10_This* this_, int param_2);
    int __thiscall IsCompatibleWith(FUN_00a57c10_This* this_, int param_2);
};

// @fnv 0x00a57c10
int __thiscall StandIn::FUN_00a57c10(FUN_00a57c10_This* this_, int param_2)
{
    return IsCompatibleWith(this_, param_2);
}

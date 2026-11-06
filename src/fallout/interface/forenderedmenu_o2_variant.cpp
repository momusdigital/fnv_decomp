
// src/fallout/interface/forenderedmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/forenderedmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "forenderedmenu_decls.h"
const char kRenderedMenuBurstSound[] = "UIPipBoyStatic";
struct NP
{
    ~NP();
    void* p;
};
struct FUN_007fad10
{
    virtual ~FUN_007fad10();
    NP np04;
    NP np08;
    NP np0c;
    NP np10;
    NP np14;
    char pad18[4];
    NP np1c;
    char pad20[4];
    NP np24;
    char pad28[0x94];
    NP npbc;
    char pad_c0[0x14];
    NP npd4;
    void FUN_007fadf0();
};
struct FUN_007fc6f0_shell : public FORenderedMenu
{
    void FUN_007fc6f0();
};
struct Flt
{
    operator unsigned int() const;
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct ExtraDataList
{
    void Set3DObject(NiAVObject*);
};
struct LightNodeV
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void AttachLight(unsigned int);
};
extern char DAT_0118abb1;
void FUN_007f8160(char value);
struct FUN_007fadf0_shell : public FORenderedMenu
{
    void FUN_007fadf0();
};
unsigned char __fastcall GetByteAtOffsetB9(void* thisPtr);
extern char* DAT_011f35cc;
char* FUN_007fdf30();
struct FUN_0087d6c0_shell
{
    float __thiscall FUN_0087d6c0();
};
extern Flt g_011db63c;
float __fastcall GetFieldB4Float(char*);
struct FUN_00706060_shell
{
    float FUN_00706060();
};
void __cdecl _Deallocate(void*);
struct HOLDER
{
    void* __thiscall DestroyHolder(unsigned int);
};
struct MenuStub
{
    char _p00[0x1c];
    Flt unk1c;
    char _p1d[0x30];
    bool b4d;
    char _p4e[0x12];
    bool b60;
    char _p61[0x58];
    bool bB9;
    void ResetMenuState();
    void SetScreenTexture(int);
};
struct S007fb100
{
    char _0[0x95];
    unsigned char b95;
    char _96[2];
    float f98;
    float f9c;
    void FUN_007fb100();
};
struct FUN_007fb250_owner
{
    void FUN_007fb250(float afDuration, float afIntensity);
};
struct HackLight
{
    NiAVObject* FUN_007fc6f0();
};
struct MyMenu : public FORenderedMenu
{
    void FUN_007ffdb0();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);

struct SpawnedRef
{
    virtual void vfn00();
    virtual void Free();
    long m_iObjectReferenceCount;
};

struct SpawnedSubBase
{
    virtual void vfnBase();
    SpawnedSubBase(unsigned int a, unsigned int b);
};

struct SpawnedSub : SpawnedSubBase
{
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    unsigned int unk10;

    SpawnedSub(unsigned int a, unsigned int b) : SpawnedSubBase(a, b)
    {
        unk10 = 0;
    }
};

class FUN_00e98f20
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned char unk10;
    volatile unsigned char unk11;
    SpawnedRef* m_pReference;
    SpawnedSub m_sub;
    unsigned int unk2c;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;

    FUN_00e98f20(unsigned int a, unsigned int b);
};

// @fnv 0x00e98f20
FUN_00e98f20::FUN_00e98f20(unsigned int a, unsigned int b) : m_pReference(0), m_sub(a, b)
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 1;
    unk0c = 1;
    unk10 = 1;
    unk11 = 0;
    SpawnedRef* p = *(SpawnedRef* volatile*)&m_pReference;
    if (p != 0)
    {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
        {
            p->Free();
        }
        m_pReference = 0;
    }
    unk30 = 0;
    unk31 = 0;
    unk32 = 0;
    unk33 = 0;
    unk2c = 0;
}

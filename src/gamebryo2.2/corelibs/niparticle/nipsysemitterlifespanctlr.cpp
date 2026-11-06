
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202740;

// @fnv 0x00c2b650
void* __cdecl FUN_00c2b650()
{
    return &g_01202740;
}

struct NiPSysModifierFloatCtlr
{
    void* m_pUserData;
};

struct NiPSysEmitterLifeSpanCtlr : NiPSysModifierFloatCtlr
{
    void __thiscall FUN_00c2b660(float& fValue);
};

// @fnv 0x00c2b660
void __thiscall NiPSysEmitterLifeSpanCtlr::FUN_00c2b660(float& fValue)
{
    void* p = *(void**)((char*)this + 0x3c);
    fValue = *(float*)((char*)p + 0x48);
}

namespace fnv_00c2b670 {
struct NiPSysModifierFloatCtlr
{
    float m_fTargetValue;
};

struct NiPSysEmitterLifeSpanCtlr : NiPSysModifierFloatCtlr
{
    void* m_pSomething;
    void FUN_00c2b670(float fValue);
};

// @fnv 0x00c2b670
void NiPSysEmitterLifeSpanCtlr::FUN_00c2b670(float fValue)
{
    void* p = *(void**)((char*)this + 0x3c);
    float* f = (float*)((char*)p + 0x48);
    *f = fValue;
}
}  // namespace fnv_00c2b670

struct StrArr
{
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_01202740) to pkStrings, growing the array by its growth step when it is full.
// @fnv 0x00c2b6d0
void __stdcall FUN_00c2b6d0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pszStr = _FUN_00a7d330(g_01202740);
    unsigned int uSize = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int uCap = *(unsigned short*)((char*)pkStrings + 8);
    if (uSize >= uCap)
    {
        pkStrings->SetSize(uSize + *(unsigned short*)((char*)pkStrings + 14));
    }
    pkStrings->SetAt(uSize, pszStr);
}

class C2B680Base
{
  public:
    C2B680Base() throw();
    virtual ~C2B680Base();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

class C2B680Object : public C2B680Base
{
  public:
    C2B680Object() throw()
    {}
    virtual ~C2B680Object();

    void CopyMemberData(C2B680Object* pkDest, void* pvCloning);
    C2B680Object* CreateClone(void* pvCloning);
};

// @fnv 0x00c2b680
C2B680Object* C2B680Object::CreateClone(void* pvCloning)
{
    C2B680Object* pkClone = new C2B680Object;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}

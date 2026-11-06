// src/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglevarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglevarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202730;

// @fnv 0x00c2b460
void* __cdecl FUN_00c2b460()
{
    return &g_01202730;
}

struct NiPSysEmitterPlanarAngleVarCtlr
{
    void __thiscall FUN_00c2b470(float fValue);
};

// @fnv 0x00c2b470
void __thiscall NiPSysEmitterPlanarAngleVarCtlr::FUN_00c2b470(float fValue)
{
    *(float*)(*(int*)(this + 0x3c) + 0x2c) = fValue;
}

namespace fnv_00c2a8b0 {
struct NiPSysModifierFloatCtlr
{
    char _pad[0x2c];
    float m_fValue;  // +0x2c
};

struct NiPSysEmitterPlanarAngleVarCtlr
{
    char _pad[0x3c];
    NiPSysModifierFloatCtlr* m_pkFloatCtlr;  // +0x3c
    void FUN_00c2a8b0(float& rfValue);
};

// @fnv 0x00c2a8b0
void NiPSysEmitterPlanarAngleVarCtlr::FUN_00c2a8b0(float& rfValue)
{
    rfValue = m_pkFloatCtlr->m_fValue;
}
}  // namespace fnv_00c2a8b0

struct StrArr
{
    unsigned char _pad0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_01202730) to the end of pkStrings, growing the array if it is full.
// @fnv 0x00c2b4d0
void __stdcall FUN_00c2b4d0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pcString = _FUN_00a7d330(g_01202730);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

struct NiMemObject
{
    static void* __cdecl operator new(unsigned int);
};
struct CloneShell;
struct FUN_00c32d80
{
    virtual void base0();
    FUN_00c32d80();
    void FUN_00c32de0(CloneShell*, void*);
};
struct CloneShell : FUN_00c32d80
{
    virtual ~CloneShell() throw();
};
inline void* __cdecl operator new(unsigned int, void* memory)
{
    return memory;
}
struct C_00c2b480 : FUN_00c32d80
{
    CloneShell* CreateClone(void* volatile argument);
};
// Allocates a 0x40-byte CloneShell, constructs it, passes the argument to FUN_00c32de0, and returns the clone or null.
// @fnv 0x00c2b480
CloneShell* C_00c2b480::CreateClone(void* volatile argument)
{
    CloneShell* clone = (CloneShell*)NiMemObject::operator new(0x40);
    if (clone)
    {
        new ((void*)clone) CloneShell;
        FUN_00c32de0(clone, argument);
    }
    else
    {
        void* processCopy = argument;
        clone = 0;
        FUN_00c32de0(clone, processCopy);
    }
    return clone;
}

// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const void* g_01202710;

// @fnv 0x00c2b040
const void* __cdecl FUN_00c2b040()
{
    return &g_01202710;
}

struct NiPSysModifierFloatCtlr
{
};

struct NiPSysFieldMaxDistanceCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b050(float fValue);
};

// @fnv 0x00c2b050
void NiPSysFieldMaxDistanceCtlr::FUN_00c2b050(float fValue)
{
    float* p = (float*)(*((float**)(this + 0x3c)));
    p[0xA] = fValue;
    p[0xB] = fValue * fValue;
}

struct StrArr
{
    unsigned char _0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned char _c[2];
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// @fnv 0x00c2b0c0
void __stdcall FUN_00c2b0c0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* psz = _FUN_00a7d330((const char*)g_01202710);
    unsigned int uSize = pkStrings->m_usSize;
    if (uSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uSize, psz);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern char DAT_010bf354[];

struct CtorBase_cls
{
    void ctorBase();
};

struct FUN_00c2b070_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00c32de0(void* obj, unsigned int a1);
    void* CreateClone(unsigned int a1);
};

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it with a1 to FUN_00c32de0 and returns it.
// @fnv 0x00c2b070
void* FUN_00c2b070_cls::CreateClone(unsigned int a1)
{
    FUN_00c2b070_cls* p = (FUN_00c2b070_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        ((CtorBase_cls*)p)->ctorBase();
        p->m_vtbl = (void*)&DAT_010bf354;
    }
    else
    {
        p = 0;
    }
    this->FUN_00c32de0(p, a1);
    return p;
}

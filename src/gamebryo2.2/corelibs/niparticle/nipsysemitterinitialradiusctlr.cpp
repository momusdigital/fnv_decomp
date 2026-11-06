
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterinitialradiusctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterinitialradiusctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202748;

// @fnv 0x00c2b750
void* __cdecl FUN_00c2b750()
{
    return &g_01202748;
}

struct NiPSysModifierFloatCtlr
{
    float m_fValue;
    float m_fMinimum;
    float m_fMaximum;
    float m_fDefault;
    float m_fCurrent;
};

struct NiPSysEmitterInitialRadiusCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b760(float& fOut) const;
};

// @fnv 0x00c2b760
void NiPSysEmitterInitialRadiusCtlr::FUN_00c2b760(float& fOut) const
{
    fOut = *(float*)((const char*)*(void**)((const char*)this + 0x3c) + 0x40);
}

namespace fnv_00c2b770 {
struct NiPSysEmitterInitialRadiusCtlr
{
    void __thiscall FUN_00c2b770(float);
};

// @fnv 0x00c2b770
void __thiscall NiPSysEmitterInitialRadiusCtlr::FUN_00c2b770(float value)
{
    float* p = *(float**)((char*)this + 0x3c);
    p[0x10] = value;
}
}  // namespace fnv_00c2b770

struct StrArr
{
    unsigned char _0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _c;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_01202748) to pkStrings, growing it via SetSize when full and storing it with SetAt.
// @fnv 0x00c2b820
void __stdcall FUN_00c2b820(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* psz = _FUN_00a7d330((const char*)g_01202748);
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIdx + pkStrings->m_usGrow);
    pkStrings->SetAt(uiIdx, psz);
}

class NiPSysBaseC2B
{
  public:
    NiPSysBaseC2B() throw();
    virtual ~NiPSysBaseC2B();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};

class NiPSysDerivedC2B : public NiPSysBaseC2B
{
  public:
    NiPSysDerivedC2B() throw()
    {}
    virtual ~NiPSysDerivedC2B();
};

class NiPSysOwnerC2B
{
  public:
    void CopyMemberData(NiPSysBaseC2B* pkDest, void* pvProcess);
    NiPSysBaseC2B* CreateClone(void* pvProcess);
};

// @fnv 0x00c2b780
NiPSysBaseC2B* NiPSysOwnerC2B::CreateClone(void* pvProcess)
{
    NiPSysDerivedC2B* pkClone = new NiPSysDerivedC2B;
    CopyMemberData(pkClone, pvProcess);
    return pkClone;
}

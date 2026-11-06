// src/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202750;

// @fnv 0x00c2b8b0
void* __cdecl FUN_00c2b8b0()
{
    return &g_01202750;
}

struct NiPSysModifierFloatCtlr
{
    char _pad[0x24];
    float fTarget;
};

struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    char _pad2[0x14];
    NiPSysModifierFloatCtlr* m_pFloatCtlr;
    void FUN_00c2a0b0(float fValue);
};

// @fnv 0x00c2a0b0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2a0b0(float fValue)
{
    m_pFloatCtlr->fTarget = fValue;
}

namespace fnv_00c2b8c0 {
struct NiPSysModifierFloatCtlr
{
    char _pad[0x3c];
};
struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b8c0(float& fValue);
};

// @fnv 0x00c2b8c0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2b8c0(float& fValue)
{
    NiPSysModifierFloatCtlr* p = *(NiPSysModifierFloatCtlr**)((char*)this + 0x3c);
    fValue = *(float*)((char*)p + 0x24);
}
}  // namespace fnv_00c2b8c0

struct StrArr
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    inline unsigned int Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
void __stdcall FUN_00c32f60(StrArr* pArr);
char* FUN_00a7d330(char* s);

// @fnv 0x00c2b920
void __stdcall FUN_00c2b920(StrArr* pStringArray)
{
    FUN_00c32f60(pStringArray);
    char* s = FUN_00a7d330((char*)g_01202750);
    pStringArray->Add(s);
}

extern int DAT_010bfb54;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject
{
    void* m_vtbl;
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
    int unk34;
    int unk38;
    int unk3c;

    void FUN_00c32d80();
};

struct FUN_00c2b8d0_cls
{
    void FUN_00c32de0(SpawnedObject* obj, void* arg);

    SpawnedObject* CreateClone(void* arg);
};

// @fnv 0x00c2b8d0
SpawnedObject* FUN_00c2b8d0_cls::CreateClone(void* arg)
{
    SpawnedObject* obj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        obj->FUN_00c32d80();
        obj->m_vtbl = &DAT_010bfb54;
    }
    else
    {
        obj = 0;
    }
    this->FUN_00c32de0(obj, arg);
    return obj;
}

// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmagnitudectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPSysModifierFloatCtlr
{
};

struct NiPSysFieldMagnitudeCtlr : NiPSysModifierFloatCtlr
{
    void __thiscall FUN_00c29ea0(float& fValue);
};

// @fnv 0x00c29ea0
void __thiscall NiPSysFieldMagnitudeCtlr::FUN_00c29ea0(float& fValue)
{
    fValue = *(float*)(*(NiPSysModifierFloatCtlr**)((char*)this + 0x3C) + 0x1C);
}

extern "C" void* g_01202718;

// @fnv 0x00c2b140
void* __cdecl FUN_00c2b140()
{
    return &g_01202718;
}

struct NiPSysFieldMagnitudeCtlr_shell : NiPSysFieldMagnitudeCtlr
{
    void __thiscall FUN_00c2b150(float value);
};

// @fnv 0x00c2b150
void __thiscall NiPSysFieldMagnitudeCtlr_shell::FUN_00c2b150(float value)
{
    ((float*)*(int*)((char*)this + 0x3c))[7] = value;
}

struct StrArr
{
    void* m_pData;
    int _m04;
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short _m0C;
    unsigned short m_usGrow;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl FUN_00a7d330(const char*);
// @fnv 0x00c2b1b0
void __stdcall FUN_00c2b1b0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pcStr = FUN_00a7d330((const char*)g_01202718);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiCap = pkStrings->m_usAlloc;
    if (uiSize >= uiCap)
        pkStrings->SetSize(pkStrings->m_usGrow + uiSize);
    pkStrings->SetAt(uiSize, pcStr);
}

struct Base
{
    int unk04;
    Base() throw();
    virtual void vf();
};

struct Node : Base
{
    int unk08[14];
    static void* operator new(unsigned int size) throw();
    Node() throw()
    {}
    virtual void vf();
};

struct Owner
{
    void FUN_00c32de0(Node* node, int arg);
    Node* CreateClone(int arg);
};

// @fnv 0x00c2b160
Node* Owner::CreateClone(int arg)
{
    Node* node = new Node();
    FUN_00c32de0(node, arg);
    return node;
}

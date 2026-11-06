// gamebryo2.2/corelibs/nimain/nilight.cpp: NiLight, Standin (11 functions)

#include "nilight_decls.h"

// Loads the dimmer value and ambient, diffuse and specular colors from the stream after the base NiDynamicEffect data.
// @fnv 0x00a72080
void NiLight::LoadBinary(NiStream& stream)
{
    NiDynamicEffect::LoadBinary(stream);
    ReadBinaryValue(stream, m_fDimmer);
    m_kAmb.LoadBinary(stream);
    m_kDiff.LoadBinary(stream);
    m_kSpec.LoadBinary(stream);
}

// @fnv 0x00a68d40
void NiLight::CopyMemberData(NiLight* clone, CloningProcess& process)
{
    NiAVObject::FUN_00a5ac90(clone, process);
    clone->m_uiEffectPushCount = m_uiEffectPushCount;
    clone->m_uiRevID = m_uiRevID;
    clone->m_bEffectEnabled = m_bEffectEnabled;
}

struct FUN_00a72000_shell : public NiLight
{
    void* GetRTTI();
};

extern const char* const g_011f4a68_arg1;

// @fnv 0x00a72000
void* FUN_00a72000_shell::GetRTTI()
{
    return (void*)&g_011f4a68_arg1;
}

extern int DAT_0109ce4c;
struct NiDynamicEffect;
void __fastcall DestroyDynamicEffect(NiDynamicEffect*);
struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void UnkF8(void*);
};
struct Standin : public NiLight
{
    void* FUN_00a72040(unsigned int);
};

struct FUN_00a72010_owner
{
    void FUN_00a72010();
};
// @fnv 0x00a72010
void FUN_00a72010_owner::FUN_00a72010()
{
    typedef void(__thiscall * Fn_t)(NiRenderer*, void*);
    *(void**)this = (void*)&DAT_0109ce4c;
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkRenderer)
        ((Fn_t*)*(void**)pkRenderer)[62](pkRenderer, this);
    DestroyDynamicEffect((NiDynamicEffect*)(void*)this);
}

struct FUN_00a72160_shell : public NiLight
{
    bool FUN_00a72160(NiObject*);
};
struct Call_439090_tgt
{
    bool __thiscall Call_439090(const NiPoint3&);
};
struct FUN_00a68d80_shell
{
    bool __thiscall IsEqual(NiObject*);
};
// @fnv 0x00a72160
bool FUN_00a72160_shell::FUN_00a72160(NiObject* pObject)
{
    if (((FUN_00a68d80_shell*)this)->IsEqual(pObject) &&
        *(float*)((char*)this + 0xc4) == *(float*)((char*)pObject + 0xc4) &&
        !((Call_439090_tgt*)((char*)this + 0xc8))->Call_439090(*(const NiPoint3*)((char*)pObject + 0xc8)) &&
        !((Call_439090_tgt*)((char*)this + 0xd4))->Call_439090(*(const NiPoint3*)((char*)pObject + 0xd4)) &&
        !((Call_439090_tgt*)((char*)this + 0xe0))->Call_439090(*(const NiPoint3*)((char*)pObject + 0xe0)))
        return true;
    return false;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

struct Zx3Effect
{
    void GetViewerStrings(StrArr*);
};

struct FUN_00a696c0_shell
{
    char* GetFormattedString(const char*);
};

char* __cdecl _FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d550(const char*, float);

struct FUN_00a721e0_shell
{
    void AppendEffectProperties(StrArr*);
};

// Appends formatted strings for the dimmer, ambient, diffuse and specular properties to pArray, growing it when full.
// @fnv 0x00a721e0
void FUN_00a721e0_shell::AppendEffectProperties(StrArr* pArray)
{
    char* pString;

    reinterpret_cast<Zx3Effect*>(this)->GetViewerStrings(pArray);

    pString = _FUN_00a7d330(g_011f4a68_arg1);
    {
        unsigned int nIndex = *(unsigned short*)((unsigned char*)pArray + 0x0a);
        unsigned int nCapacity = *(unsigned short*)((unsigned char*)pArray + 0x08);
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = *(unsigned short*)((unsigned char*)pArray + 0x0e);
            pArray->SetSize(nGrow + nIndex);
        }
        pArray->SetAt(nIndex, pString);
    }

    pString = FUN_00a7d550("m_fDimmer", *(float*)((unsigned char*)this + 0xc4));
    {
        unsigned int nIndex = *(unsigned short*)((unsigned char*)pArray + 0x0a);
        unsigned int nCapacity = *(unsigned short*)((unsigned char*)pArray + 0x08);
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = *(unsigned short*)((unsigned char*)pArray + 0x0e);
            pArray->SetSize(nGrow + nIndex);
        }
        pArray->SetAt(nIndex, pString);
    }

    pString = reinterpret_cast<FUN_00a696c0_shell*>(reinterpret_cast<unsigned char*>(this) + 0xc8)
                  ->GetFormattedString("m_kAmb");
    {
        unsigned int nIndex = *(unsigned short*)((unsigned char*)pArray + 0x0a);
        unsigned int nCapacity = *(unsigned short*)((unsigned char*)pArray + 0x08);
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = *(unsigned short*)((unsigned char*)pArray + 0x0e);
            pArray->SetSize(nGrow + nIndex);
        }
        pArray->SetAt(nIndex, pString);
    }

    pString = reinterpret_cast<FUN_00a696c0_shell*>(reinterpret_cast<unsigned char*>(this) + 0xd4)
                  ->GetFormattedString("m_kDiff");
    {
        unsigned int nIndex = *(unsigned short*)((unsigned char*)pArray + 0x0a);
        unsigned int nCapacity = *(unsigned short*)((unsigned char*)pArray + 0x08);
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = *(unsigned short*)((unsigned char*)pArray + 0x0e);
            pArray->SetSize(nGrow + nIndex);
        }
        pArray->SetAt(nIndex, pString);
    }

    pString = reinterpret_cast<FUN_00a696c0_shell*>(reinterpret_cast<unsigned char*>(this) + 0xe0)
                  ->GetFormattedString("m_kSpec");
    {
        unsigned int nIndex = *(unsigned short*)((unsigned char*)pArray + 0x0a);
        unsigned int nCapacity = *(unsigned short*)((unsigned char*)pArray + 0x08);
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = *(unsigned short*)((unsigned char*)pArray + 0x0e);
            pArray->SetSize(nGrow + nIndex);
        }
        pArray->SetAt(nIndex, pString);
    }
}

extern int DAT_0109ce4c;
struct FUN_00a69320_base
{
    void Init();
};
struct FUN_00a71f60_cls : FUN_00a69320_base
{
    int m_vptr00;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    volatile float m_c4;
    volatile float m_c8;
    volatile float m_cc;
    volatile float m_d0;
    volatile float m_d4;
    volatile float m_d8;
    volatile float m_dc;
    volatile float m_e0;
    volatile float m_e4;
    volatile float m_e8;
    volatile int m_ec;

    FUN_00a71f60_cls();
};

// Calls Init, sets the vtable pointer, zeroes m_c8..m_e8 and m_ec, then sets m_c4..m_e8 to 1.0f.
// @fnv 0x00a71f60
FUN_00a71f60_cls::FUN_00a71f60_cls()
{
    Init();
    m_vptr00 = (int)&DAT_0109ce4c;
    m_c8 = 0.0f;
    m_cc = 0.0f;
    m_d0 = 0.0f;
    m_d4 = 0.0f;
    m_d8 = 0.0f;
    m_dc = 0.0f;
    m_e0 = 0.0f;
    m_e4 = 0.0f;
    m_e8 = 0.0f;
    m_ec = 0;
    m_c4 = 1.0f;
    m_c8 = 1.0f;
    m_cc = 1.0f;
    m_d0 = 1.0f;
    m_d4 = 1.0f;
    m_d8 = 1.0f;
    m_dc = 1.0f;
    m_e0 = 1.0f;
    m_e4 = 1.0f;
    m_e8 = 1.0f;
}

struct FUN_00a720f0_shell : public NiLight
{
    void FUN_00a720f0(NiStream& stream);
};
struct FUN_00a68f80_shell : public NiDynamicEffect
{
    void SaveToStream(NiStream&);
};
struct NiColorSaveHelper
{
    void SaveBinary(NiStream&);
};
struct NiBinaryStreamWriteShell : public NiBinaryStream
{
    unsigned int BinaryWrite(void* data, unsigned int size)
    {
        unsigned int componentSizes[1] = {size};
        unsigned int written = m_pfnWrite(this, data, size, componentSizes, 1);
        m_uiStreamFlags += written;
        return written;
    }
};
// @fnv 0x00a720f0
void FUN_00a720f0_shell::FUN_00a720f0(NiStream& stream)
{
    reinterpret_cast<FUN_00a68f80_shell*>(this)->SaveToStream(stream);
    reinterpret_cast<NiBinaryStreamWriteShell*>(stream.m_pBackingStream)->BinaryWrite(&m_fDimmer, 4);
    reinterpret_cast<NiColorSaveHelper*>(&m_kAmb)->SaveBinary(stream);
    reinterpret_cast<NiColorSaveHelper*>(&m_kDiff)->SaveBinary(stream);
    reinterpret_cast<NiColorSaveHelper*>(&m_kSpec)->SaveBinary(stream);
}

struct FUN_00a71f50_cls : public NiDynamicEffect
{
    void FUN_00a71f50(NiStream& stream);
};

// @fnv 0x00a71f50
void FUN_00a71f50_cls::FUN_00a71f50(NiStream& stream)
{
    NiDynamicEffect::LinkObject(stream);
}

void __cdecl FUN_00a6ff10();

// @fnv 0x00a90010
void __cdecl FUN_00a90010()
{
    FUN_00a6ff10();
}

void __fastcall DestroyDynamicEffect(NiDynamicEffect*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109ce4c;

// Sets the vtable, calls UnkF8 on the renderer when present, destroys the dynamic effect, and optionally frees memory when flag bit 0 is set.
// @fnv 0x00a72040
void* Standin::FUN_00a72040(unsigned int auiFlags)
{
    *(void**)this = &DAT_0109ce4c;
    if (NiRenderer::ms_pRenderer)
        NiRenderer::ms_pRenderer->UnkF8(this);
    DestroyDynamicEffect((NiDynamicEffect*)this);
    if (auiFlags & 1)
        _delete(this, 0xF0);
    return this;
}

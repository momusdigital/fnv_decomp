
// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_01202688_arg1;

// @fnv 0x00c320f0
char const* const* __cdecl FUN_00c320f0()
{
    return &g_01202688_arg1;
}

extern "C" void __cdecl operator delete(void*, unsigned int);

struct NiPSysFieldModifier
{
    void __thiscall FUN_00c31750();
    NiPSysFieldModifier* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_00c31750, then deletes this with size 48 if flags has bit 0 set, and returns this.
// @fnv 0x00c32100
NiPSysFieldModifier* __thiscall NiPSysFieldModifier::Destroy(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 48);
    return this;
}

struct C32060Object
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4C();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual bool IsEqual(C32060Object* pkObject);
};

struct C32060Modifier
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    bool IsEqual(C32060Object* pkObject);
};

struct C32060EmitterModifier : C32060Modifier
{
    C32060Object* m_pkEmitterObject;
    float m_fCoefficientA;
    float m_fB;
    bool m_bFlag;
    float m_fC;

    bool FUN_00c32060(C32060Object* pkObject);
};

// @fnv 0x00c32060
bool C32060EmitterModifier::FUN_00c32060(C32060Object* pkObject)
{
    if (!C32060Modifier::IsEqual(pkObject))
        return false;

    C32060EmitterModifier* pkDest = (C32060EmitterModifier*)pkObject;

    if ((m_pkEmitterObject && !pkDest->m_pkEmitterObject) || (!m_pkEmitterObject && pkDest->m_pkEmitterObject) ||
        (m_pkEmitterObject && pkDest->m_pkEmitterObject && !m_pkEmitterObject->IsEqual(pkDest->m_pkEmitterObject)))
    {
        return false;
    }

    if (pkDest->m_fCoefficientA != m_fCoefficientA || pkDest->m_fB != m_fB || pkDest->m_bFlag != m_bFlag ||
        pkDest->m_fC != m_fC)
        return false;

    return true;
}

typedef unsigned int(__cdecl* ReadFn)(void* ctx, void* buf, unsigned int size, unsigned int* pCount,
                                      unsigned int count);

struct StreamCtx
{
    unsigned int unk00;
    unsigned int m_04;
    ReadFn m_08;
};

struct StreamOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    StreamCtx* m_24c;
    void FUN_00a645b0();
};

class FUN_00c32120_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int m_20;
    bool m_24;
    float m_28;
    float m_2c;
    void FUN_00c318b0(StreamOwner* a1);
    void LoadFromStream(StreamOwner* a1);
};

// Calls the base loader, then reads m_1c, m_20, a byte flag into m_24, and m_28 from the stream, and sets m_2c to m_28 squared.
// @fnv 0x00c32120
void FUN_00c32120_cls::LoadFromStream(StreamOwner* apOwner)
{
    FUN_00c318b0(apOwner);
    apOwner->FUN_00a645b0();
    StreamCtx* s = apOwner->m_24c;
    {
        unsigned int n = 4;
        s->m_04 += s->m_08(s, &m_1c, 4, &n, 1);
    }
    s = apOwner->m_24c;
    {
        unsigned int n = 4;
        s->m_04 += s->m_08(s, &m_20, 4, &n, 1);
    }
    unsigned char flag;
    s = apOwner->m_24c;
    {
        unsigned int n = 1;
        s->m_04 += s->m_08(s, &flag, 1, &n, 1);
    }
    m_24 = (flag != 0);
    s = apOwner->m_24c;
    {
        unsigned int n = 4;
        s->m_04 += s->m_08(s, &m_28, 4, &n, 1);
    }
    m_2c = m_28 * m_28;
}

struct NiObject;
typedef unsigned int(__cdecl* NiWriteFn)(struct NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                         unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* unk08;
    NiWriteFn m_pfnWrite;

    void BinaryWrite(const void* pvBuffer, unsigned int uiBytes, unsigned int uiComponentSize)
    {
        unsigned int uiSize = uiComponentSize;
        unsigned int* puiSize = &uiSize;
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiSize, 1);
    }
};

struct NiStream
{
    virtual void Vfn00();
    virtual void Vfn01();
    virtual void Vfn02();
    virtual void Vfn03();
    virtual void Vfn04();
    virtual void Vfn05();
    virtual void Vfn06();
    virtual void Vfn07();
    virtual void Vfn08();
    virtual void Vfn09();
    virtual void Vfn10();
    virtual void Vfn11();
    virtual void SaveLinkID(NiObject* pkObject);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    NiBinaryStream* m_pBackingStream;
};

inline void SerializeValue(NiStream& kStream, const float& fValue)
{
    kStream.m_pBackingStream->BinaryWrite(&fValue, sizeof(float), sizeof(float));
}

inline void SerializeValue(NiStream& kStream, const unsigned char& ucValue)
{
    kStream.m_pBackingStream->BinaryWrite(&ucValue, sizeof(unsigned char), sizeof(unsigned char));
}

struct NiPSysFieldModifierImpl
{
    void* vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    NiObject* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;

    void __thiscall FUN_00c31950(NiStream& kStream);
    void __thiscall SaveBinary(NiStream& kStream);
};

// Calls FUN_00c31950, then writes the link ID and the float, float, bool and float fields to the stream.
// @fnv 0x00c321f0
void NiPSysFieldModifierImpl::SaveBinary(NiStream& kStream)
{
    FUN_00c31950(kStream);
    kStream.SaveLinkID(m_pkFieldObject);
    SerializeValue(kStream, m_fInfluence);
    SerializeValue(kStream, m_fFieldAttenuation);
    unsigned char ucUseMaxDistance = m_bEnableMaxDistance;
    SerializeValue(kStream, ucUseMaxDistance);
    SerializeValue(kStream, m_fDistanceLimit);
}

struct S_00c322b0_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
struct S_00c322b0_Named
{
    int unk00;
    int unk04;
    const char* name;
};
struct S_00c322b0_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void FUN_00c319e0(S_00c322b0_Arr* a);
};
extern const char* DAT_012027e0;
char* __cdecl FUN_00a7d330(const char* s);
char* __cdecl FUN_00a7d370(const char* fmt, ...);
char* __cdecl FUN_00a7d550(const char* name, float value);
char* __cdecl FUN_00a7d5e0(const char* name, const char* value);
struct S_00c322b0 : S_00c322b0_Base
{
    S_00c322b0_Named* m18;
    float m1c;
    float m20;
    unsigned char m24;
    float m28;
    void GetViewerStrings(S_00c322b0_Arr* a);
};
__forceinline void S_00c322b0_Add(S_00c322b0_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        a->FUN_0096ad30(i + a->growBy);
    a->FUN_0096ae90(i, s);
}
// @fnv 0x00c322b0
void S_00c322b0::GetViewerStrings(S_00c322b0_Arr* a)
{
    FUN_00c319e0(a);
    S_00c322b0_Add(a, FUN_00a7d330(DAT_012027e0));
    S_00c322b0_Add(a, FUN_00a7d5e0("Field Object", m18 ? m18->name : "None"));
    S_00c322b0_Add(a, FUN_00a7d550("Magnitude", m1c));
    S_00c322b0_Add(a, FUN_00a7d550("Attenuation", m20));
    S_00c322b0_Add(a, FUN_00a7d370("Use Max Distance", m24));
    S_00c322b0_Add(a, FUN_00a7d550("Max Distance", m28));
}

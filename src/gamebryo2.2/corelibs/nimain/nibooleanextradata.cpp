
// src/gamebryo2.2/corelibs/nimain/nibooleanextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibooleanextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI;

extern NiRTTI g_011f5f5c;

// @fnv 0x00a9af30
NiRTTI* __cdecl FUN_00a9af30()
{
    return &g_011f5f5c;
}

struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_010a112c;

// @fnv 0x00a9af90
void* __cdecl FUN_00a9af90()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_010a112c;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p) + 0xc) = 0;
    }
    else
    {
        return 0;
    }
    return p;
}

namespace fnv_00a9afc0 {
struct NiBooleanExtraData
{
    void* __thiscall FUN_00a9afc0(unsigned int flags);
};

extern void __cdecl _FUN_00a7b300();
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern void* DAT_010a112c;

// @fnv 0x00a9afc0
void* __thiscall NiBooleanExtraData::FUN_00a9afc0(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a112c;
    _FUN_00a7b300();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x10);
    return this;
}
}  // namespace fnv_00a9afc0

namespace fnv_00a9af10 {
struct NiObject
{
};
struct NiExtraData : NiObject
{
};
struct NiBooleanExtraData : NiExtraData
{
    char _pad_0[0x0c];
    bool m_bValue;
    bool IsEqualTo(NiObject* pObject);
};

// @fnv 0x00a9af10
bool NiBooleanExtraData::IsEqualTo(NiObject* pObject)
{
    NiBooleanExtraData* pExtra = static_cast<NiBooleanExtraData*>(pObject);
    if (!pExtra)
        return false;
    return m_bValue == pExtra->m_bValue ? true : false;
}
}  // namespace fnv_00a9af10

struct CloningProcess;

struct S_00a9af40 : NiExtraData
{
    int unk0;
    int unk4;
    int unk8;
    bool unkC;

    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    S_00a9af40() throw()
    {
        FUN_00a7b2e0();
        unk0 = (int)&DAT_010a112c;
        unkC = false;
    }
    void FUN_00a7b330(S_00a9af40* pkClone, CloningProcess* pkCloning);
    S_00a9af40* CreateClone(CloningProcess* pkCloning);
};

// @fnv 0x00a9af40
S_00a9af40* S_00a9af40::CreateClone(CloningProcess* pkCloning)
{
    S_00a9af40* pkClone = new S_00a9af40;
    FUN_00a7b330(pkClone, pkCloning);
    pkClone->unkC = unkC;
    return pkClone;
}

struct NiBinaryStream
{
    unsigned int unk00;
    unsigned int m_uiStreamFlags;
    int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes);
};

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes)
{
    unsigned int uiComponentSizes = 1;
    unsigned int uiRead = m_pfnRead(this, pvBuffer, uiTotalBytes, &uiComponentSizes, 1);
    m_uiStreamFlags += uiRead;
    return uiRead;
}

struct NiStream
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    NiBinaryStream* m_pkIStream;

    NiBinaryStream* GetBinaryStream()
    {
        return m_pkIStream;
    }
};

struct NiExtraDataBase_cls
{
    void FUN_00a7b4a0(NiStream* istr);
};

struct FUN_00a9aff0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    bool m_bValue;

    void ReadFromStream(NiStream* istr);
};

// Calls the base NiExtraDataBase read, then reads one byte from the stream and stores whether it is nonzero in m_bValue.
// @fnv 0x00a9aff0
void FUN_00a9aff0_cls::ReadFromStream(NiStream* istr)
{
    ((NiExtraDataBase_cls*)this)->FUN_00a7b4a0(istr);
    unsigned char ucValue;
    istr->GetBinaryStream()->BinaryRead(&ucValue, 1);
    m_bValue = (ucValue != 0);
}

struct FnVTarget
{
    int unk00;
    int unk04;
    int unk08;
    int (*fn)(FnVTarget*, unsigned char*, int, int*, int);
};

// The stream-like argument: the original reads a pointer at +0x250.
struct FnVArg
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    FnVTarget* unk250;
};

struct FnVNode
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    void helper_b2c0(FnVArg* a);
    void SaveBinary(FnVArg* s);
};

// @fnv 0x00a9b040
void FnVNode::SaveBinary(FnVArg* s)
{
    this->helper_b2c0(s);
    unsigned char ucValue = this->unk0c;
    FnVTarget* pTarget = s->unk250;
    {
        int one = 1;
        pTarget->unk04 += pTarget->fn(pTarget, &ucValue, 1, &one, 1);
    }
}

struct ObjArray
{
    void Grow(unsigned int newCount);
    void Insert(unsigned int index, void** value);
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0A;
    unsigned short m_0C;
    unsigned short m_0E;
};

extern void* DAT_011f5f5c;
extern const char str_010a11c0[];
void* __cdecl LookupRtti(void* rtti);
void* __cdecl LookupName(const char* name, unsigned char flag);

struct FUN_00a9b090_cls
{
    void Touch(ObjArray* arr);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char m_0C;
    void AppendRttiAndName(ObjArray* arr);
};

// Calls Touch, then appends the RTTI pointer for DAT_011f5f5c and the result of LookupName(str_010a11c0, m_0C) to the array, growing it when full.
// @fnv 0x00a9b090
void FUN_00a9b090_cls::AppendRttiAndName(ObjArray* pArray)
{
    this->Touch(pArray);
    void* v = LookupRtti(DAT_011f5f5c);
    unsigned int count = pArray->m_0A;
    unsigned int cap = pArray->m_08;
    if (count >= cap)
    {
        pArray->Grow(count + pArray->m_0E);
    }
    pArray->Insert(count, &v);

    v = LookupName(str_010a11c0, this->m_0C);
    count = pArray->m_0A;
    cap = pArray->m_08;
    if (count >= cap)
    {
        pArray->Grow(count + pArray->m_0E);
    }
    pArray->Insert(count, &v);
}

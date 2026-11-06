
// src/gamebryo2.2/corelibs/nianimation/nilookatcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilookatcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f98;

// @fnv 0x00a4cd30
void* __cdecl FUN_00a4cd30()
{
    return &g_011f3f98;
}

struct NiTimeController
{
    virtual ~NiTimeController();
};

struct NiLookAtController : NiTimeController
{
    virtual ~NiLookAtController();
    void* FUN_00a4cd40(unsigned int flags);
};

void __cdecl FUN_00a6d290();
extern "C" __declspec(noinline) void __cdecl _delete(void* p, unsigned int flags);

// Calls FUN_00a6d290, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a4cd40
void* __thiscall NiLookAtController::FUN_00a4cd40(unsigned int flags)
{
    FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x3c);
    return this;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct BaseStub
{
    void FUN_00a6d830(StrArr*);
};
char* _FUN_00a7d330(const char*);
struct Holder : NiLookAtController
{
    void AppendString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f3f98) to pkStrings, growing its size first if it is full.
// @fnv 0x00a4cef0
void Holder::AppendString(StrArr* pkStrings)
{
    ((BaseStub*)this)->FUN_00a6d830(pkStrings);
    char* s = _FUN_00a7d330((const char*)g_011f3f98);
    unsigned int sz = *(unsigned short*)((char*)pkStrings + 0xa);
    if (sz >= *(unsigned short*)((char*)pkStrings + 8))
    {
        unsigned int gr = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(gr + sz);
    }
    pkStrings->SetAt(sz, s);
}

namespace fnv_00a4c840 {
struct NiObject
{
};
struct NiAVObject : NiObject
{
};

struct NiStream
{
    NiObject* GetLoadedObject();
};

struct NiTimeController
{
    virtual void LinkObject(NiStream&);
};

struct NiLookAtController : NiTimeController
{
    char _pad[0x34];
    NiAVObject* m_pkLookAt;
    void FUN_00a4c840(NiStream&);
};

// @fnv 0x00a4c840
void NiLookAtController::FUN_00a4c840(NiStream& stream)
{
    NiTimeController::LinkObject(stream);
    m_pkLookAt = static_cast<NiAVObject*>(stream.GetLoadedObject());
}
}  // namespace fnv_00a4c840

struct NiStream
{
    char _d;
};
struct TCReg
{
    bool __thiscall FUN_00a6d0f0(NiStream&);
};
struct FakeAV
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
    virtual void v20();
    virtual bool v21(NiStream&);
};
struct S00a4c860
{
    char _p[0x38];
    FakeAV* m;
    bool __thiscall RegisterStreamables(NiStream&);
};
// @fnv 0x00a4c860
bool __thiscall S00a4c860::RegisterStreamables(NiStream& s)
{
    if (!((TCReg*)this)->FUN_00a6d0f0(s))
        return false;
    if (m)
        m->v21(s);
    return true;
}

struct BinaryInput
{
    unsigned int flags;
    unsigned int position;
    unsigned int(__cdecl* read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
};
struct StreamLayout
{
    unsigned int unk000;
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
    unsigned int version;
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
    BinaryInput* input;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned short unk284;
    unsigned short controllerFlags;
};
struct BaseLoad
{
    void FUN_00a6d5e0(NiStream&);
};
struct StreamFinish
{
    void FUN_00a645b0();
};
struct LookAt : BaseLoad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned short flags;
    void LoadBinary(NiStream& stream);
};
// @fnv 0x00a4ce20
void LookAt::LoadBinary(NiStream& stream)
{
    BaseLoad::FUN_00a6d5e0(stream);
    StreamLayout& streamLayout = reinterpret_cast<StreamLayout&>(stream);
    if (streamLayout.version < 0x0a000102)
    {
        flags = (streamLayout.controllerFlags >> 5) & 0xff;
    }
    else
    {
        BinaryInput* input = streamLayout.input;
        unsigned int(__cdecl * read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int) = input->read;
        unsigned int size = 2;
        input->position += read(input, &flags, 2, &size, 1);
    }
    reinterpret_cast<StreamFinish*>(&stream)->FUN_00a645b0();
}

class NiTStringPointerMap_00e93020
{
  public:
    bool GetAt(void* pKey, void*& rValue);
};

struct FUN_00a4ccd0_Item
{
    NiTStringPointerMap_00e93020* m_pMgr;
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
    FUN_00a4ccd0_Item* m_38;
};

class FUN_00a4ccd0_cls
{
  public:
    int unk00;
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
    FUN_00a4ccd0_Item* m_38;

    void FUN_00a6d0c0(void* pArg);
    void LookupAndLinkItem(void* pArg);
};

// Calls FUN_00a6d0c0, looks up this in the item's map, and if m_38 is set resolves it via GetAt and stores the result on the looked-up item.
// @fnv 0x00a4ccd0
void FUN_00a4ccd0_cls::LookupAndLinkItem(void* apItem)
{
    void* local;
    void* pItem;
    bool bFound;
    FUN_00a4ccd0_Item* pResolved;
    NiTStringPointerMap_00e93020* pMap;

    pItem = apItem;
    FUN_00a6d0c0(pItem);
    pMap = ((FUN_00a4ccd0_Item*)pItem)->m_pMgr;
    apItem = 0;
    pMap->GetAt(this, apItem);
    if (m_38 != 0)
    {
        bFound = ((FUN_00a4ccd0_Item*)pItem)->m_pMgr->GetAt(m_38, local);
        if (!bFound)
        {
            pResolved = m_38;
        }
        else
        {
            pResolved = (FUN_00a4ccd0_Item*)local;
        }
        ((FUN_00a4ccd0_Item*)apItem)->m_38 = pResolved;
    }
}

// The object the stream keeps at +0x250: a counter that is accumulated over
// the callback plus the callback slot itself.
struct Handler
{
    unsigned int unk000;
    int counter;
    unsigned int unk008;
    typedef int(__cdecl* FnType)(Handler* self, void* arg2, int arg3, int* arg4, int arg5);
    FnType fn;
};

// The stream the controller reads its data from.  Its virtual table entry 12
// (vtable offset 0x30) is the method the controller calls back into.
struct StreamObj
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
    virtual void v10();
    virtual void v11();
    virtual void v12(FakeAV* arg);
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
    Handler* m250;
};

// The base class that owns the shared stream handling.
struct Base44
{
    void FUN_00a6d730(StreamObj* stream);
};

// The look-at data that is handed to the callback.
struct LookAtData
{
    unsigned int unk000;
};

// The controller that owns SaveBinary: the look-at data object sits at
// +0x34 and the renderer data pointer at +0x38.
struct Ctl : Base44
{
    unsigned int unk000;
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
    LookAtData m34;
    FakeAV* m38;
    void SaveBinary(StreamObj* stream);
};

// @fnv 0x00a4cea0
void Ctl::SaveBinary(StreamObj* stream)
{
    Base44::FUN_00a6d730(stream);
    Handler* handler = stream->m250;
    {
        // The out-value is kept in an inner block on purpose: that way the
        // callback expression is a genuine call operand, so it is loaded into
        // the caller's register (EDX) and hoisted to the top of the block,
        // while the store into the out-value stays ordered after the load.
        int local = 2;
        handler->counter += handler->fn(handler, &m34, 2, &local, 1);
    }
    stream->v12(m38);
}

class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int uiSize);
};

struct FUN_00a6d220 : public BSFaceGenMorphData
{
    FUN_00a6d220() throw();
    virtual void v00();
    void FUN_00a6cfe0(FUN_00a6d220* pkDest, void* pkCloning);
    int unk;
    unsigned short m_usFlags;
    unsigned short unk0a;
    int unk0c;
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk1c;
    int uTmpnk;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
};

struct Clone_a4c : public FUN_00a6d220
{
    Clone_a4c()
    {
        m_38 = 0;
        m_34 = 0;
        m_usFlags &= ~0x40;
    }
    virtual void v00();
    void SetBit(bool bVal, unsigned short usMask)
    {
        if (bVal)
            m_34 |= usMask;
        else
            m_34 &= ~usMask;
    }
    bool GetBit(unsigned short usMask) const
    {
        return (m_34 & usMask) != 0;
    }
    void SetField(unsigned short us, unsigned short usMask, unsigned short usPos)
    {
        m_34 = (m_34 & ~usMask) | (us << usPos);
    }
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (m_34 & usMask) >> usPos;
    }
    Clone_a4c* CreateClone(void* pkCloning);
    union
    {
        unsigned short m_34;
        struct
        {
            unsigned short m_bFlag0 : 1;
            unsigned short m_uiMode : 2;
        };
    };
    int m_38;
};

// Allocates a Clone_a4c, copies the base data via FUN_00a6cfe0, then copies m_34, bit 1, field 6 and m_38, and returns the clone.
// @fnv 0x00a4cd60
Clone_a4c* Clone_a4c::CreateClone(void* pkCloning)
{
    Clone_a4c* pkClone = new Clone_a4c;
    FUN_00a6cfe0(pkClone, pkCloning);
    pkClone->m_34 = m_34;
    pkClone->SetBit(GetBit(1), 1);
    pkClone->SetField(GetField(6, 1), 6, 1);
    pkClone->m_38 = m_38;
    return pkClone;
}

extern int DAT_01098c14;
void __fastcall FUN_00a6d220(void*) throw();

struct Base4c : BSFaceGenMorphData
{
    void* vt;
    unsigned int u4;
    unsigned short m_flags;
    unsigned short ua;
    unsigned int pad[10];
    Base4c()
    {
        FUN_00a6d220(this);
    }
};
struct X4c : Base4c
{
    unsigned short m_34;
    unsigned short u36;
    void* m_38;
    X4c()
    {
        vt = &DAT_01098c14;
        m_38 = 0;
        m_34 = 0;
        m_flags &= ~0x40;
    }
};
// Allocates and constructs a new X4c (BSFaceGenMorphData-derived) object and returns it.
// @fnv 0x00a4cde0
void* __cdecl CreateMorphData()
{
    return new X4c;
}

struct EqAV4c
{
    virtual void w00();
    virtual void w01();
    virtual void w02();
    virtual void w03();
    virtual void w04();
    virtual void w05();
    virtual void w06();
    virtual void w07();
    virtual void w08();
    virtual void w09();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual bool IsEqual(EqAV4c* other);
};

struct Eq4c
{
    unsigned int unk[14];
    EqAV4c* m_spObj;

    bool FUN_00a6cc80(Eq4c* other);
    bool FUN_00a4c890(Eq4c* other);
};

// Compares this object with other via FUN_00a6cc80, checks m_spObj presence matches, and delegates to m_spObj->IsEqual.
// @fnv 0x00a4c890
bool Eq4c::FUN_00a4c890(Eq4c* other)
{
    if (!FUN_00a6cc80(other))
        return false;
    if ((m_spObj && !other->m_spObj) || (!m_spObj && other->m_spObj))
        return false;
    if (m_spObj && !m_spObj->IsEqual(other->m_spObj))
        return false;
    return true;
}

struct S00a4c8e0_Pt
{
    float x, y, z;
    S00a4c8e0_Pt()
    {}
    S00a4c8e0_Pt(float a, float b, float c) : x(a), y(b), z(c)
    {}
    S00a4c8e0_Pt operator-(const S00a4c8e0_Pt& b) const
    {
        return S00a4c8e0_Pt(x - b.x, y - b.y, z - b.z);
    }
    S00a4c8e0_Pt operator+(const S00a4c8e0_Pt& b) const
    {
        return S00a4c8e0_Pt(x + b.x, y + b.y, z + b.z);
    }
    S00a4c8e0_Pt operator*(float f) const
    {
        return S00a4c8e0_Pt(x * f, y * f, z * f);
    }
    S00a4c8e0_Pt operator-() const
    {
        return S00a4c8e0_Pt(-x, -y, -z);
    }
    S00a4c8e0_Pt& operator-=(const S00a4c8e0_Pt& p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    float Dot(const S00a4c8e0_Pt& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    S00a4c8e0_Pt Cross(const S00a4c8e0_Pt& p) const
    {
        return S00a4c8e0_Pt(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    __declspec(noalias) void FUN_004a0c10();
};
struct S00a4c8e0_Mat
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    S00a4c8e0_Pt FUN_004b4500(const S00a4c8e0_Pt&) const;
    S00a4c8e0_Mat FUN_00a588a0(const S00a4c8e0_Mat&) const;
    void Identity()
    {
        m00 = 1;
        m01 = 0;
        m02 = 0;
        m10 = 0;
        m11 = 1;
        m12 = 0;
        m20 = 0;
        m21 = 0;
        m22 = 1;
    }
    void Column0(const S00a4c8e0_Pt& p)
    {
        m00 = p.x;
        m10 = p.y;
        m20 = p.z;
    }
    void Column1(const S00a4c8e0_Pt& p)
    {
        m01 = p.x;
        m11 = p.y;
        m21 = p.z;
    }
    void Column2(const S00a4c8e0_Pt& p)
    {
        m02 = p.x;
        m12 = p.y;
        m22 = p.z;
    }
};
struct S00a4c8e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00a4c8e0_Node* parent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    S00a4c8e0_Mat rotation;
    S00a4c8e0_Pt translation;
    float scale;
    S00a4c8e0_Mat worldRotation;
    S00a4c8e0_Pt worldTranslation;
    float worldScale;
};
struct S00a4c8e0_Ctl
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short flags;
    unsigned short unk0a;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    S00a4c8e0_Node* object;
    unsigned int unk30;
    unsigned short options;
    unsigned short unk36;
    bool GetFlip() const
    {
        return (options & 1) != 0;
    }
    unsigned short GetAxis() const
    {
        return (options & 6) >> 1;
    }
    S00a4c8e0_Node* target;
    bool IsActive() const
    {
        return ((flags >> 3) & 1) != 0;
    }
    void Update(float);
};
extern S00a4c8e0_Mat DAT_011a9448;
extern S00a4c8e0_Pt DAT_011a9478;
extern S00a4c8e0_Pt DAT_011a9484;

// Rotates the controlled node to face the target node by building a look-at matrix from their world positions and applying the parent transform.
// @fnv 0x00a4c8e0
void S00a4c8e0_Ctl::Update(float time)
{
    if (!target || !IsActive())
        return;
    S00a4c8e0_Pt targetPos = target->worldTranslation;
    S00a4c8e0_Node* node = object;
    S00a4c8e0_Node* pParent = node->parent;
    S00a4c8e0_Mat parentRot;
    S00a4c8e0_Pt worldPos;
    if (pParent)
    {
        parentRot = pParent->worldRotation;
        float parentScale = pParent->worldScale;
        worldPos = pParent->worldTranslation + parentRot.FUN_004b4500(node->translation) * parentScale;
    }
    else
    {
        parentRot = DAT_011a9448;
        worldPos = node->translation;
    }
    S00a4c8e0_Pt at = targetPos - worldPos;
    S00a4c8e0_Mat rot;
    float fDistSq = at.Dot(at);
    if (fDistSq < 0.001f)
    {
        rot.Identity();
    }
    else
    {
        at.FUN_004a0c10();
        S00a4c8e0_Pt up;
        float d;
        if (at.z < 1.001f && at.z > 0.9990000128746033)
        {
            up = DAT_011a9478;
            d = at.y;
        }
        else
        {
            up = DAT_011a9484;
            d = at.z;
        }
        up -= at * d;
        up.FUN_004a0c10();
        if (!GetFlip())
            at = -at;
        S00a4c8e0_Pt right = up.Cross(at);
        switch (GetAxis())
        {
        case 0:
            rot.Column0(at);
            rot.Column1(up);
            rot.Column2(-right);
            break;
        case 1:
            rot.Column0(right);
            rot.Column1(at);
            rot.Column2(-up);
            break;
        case 2:
            rot.Column0(right);
            rot.Column1(up);
            rot.Column2(at);
            break;
        }
        rot = parentRot.FUN_00a588a0(rot);
    }
    node->rotation = rot;
}

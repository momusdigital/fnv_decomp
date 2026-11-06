
// src/gamebryo2.2/corelibs/nimain/nisortadjustnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisortadjustnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f5ed8;

// @fnv 0x00a95310
void* __cdecl FUN_00a95310()
{
    return &g_011f5ed8;
}

extern int DAT_010a0384;
void __fastcall FUN_00a5e930(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct NiSortAdjustNode
{
    void* m_vftable;
    void* __thiscall Destructor(unsigned int flags);
};

// @fnv 0x00a95320
void* __thiscall NiSortAdjustNode::Destructor(unsigned int flags)
{
    m_vftable = &DAT_010a0384;
    FUN_00a5e930(this);
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xb0);
    return this;
}

struct NiNode
{
    NiNode(unsigned short) throw();
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void __cdecl operator delete(void*, void*) throw()
{}
// @fnv 0x00a952a0
void* __cdecl FUN_00a952a0()
{
    void* p = BSFadeNode::operator new(0xB0);
    if (p)
    {
        new (p) NiNode(0);
        *(void**)p = (void*)&DAT_010a0384;
        *(int*)((char*)p + 0xAC) = 0;
        return p;
    }
    return 0;
}

namespace fnv_00a95410 {
class NiObject;
class NiStream
{
  public:
    unsigned char _pad[0xD8];
    unsigned int m_uiNifVersion;
    NiObject* __thiscall GetLoadedObject();
};
class NiNode
{
  public:
    void __thiscall ReadChildListFromStream(NiStream&);
};
struct TargetCls : public NiNode
{
    void __thiscall LinkObject(NiStream&);
};
// @fnv 0x00a95410
void __thiscall TargetCls::LinkObject(NiStream& stream)
{
    ReadChildListFromStream(stream);
    if (stream.m_uiNifVersion < 0x14000004)
        stream.GetLoadedObject();
}
}  // namespace fnv_00a95410

struct NiBinaryStream
{
    int _00;
    int _04;
    int _08;
    int(__cdecl* _0c)(NiBinaryStream*, void*, int, unsigned int*, int);
    void Write(void* buf);
};
inline void NiBinaryStream::Write(void* buf)
{
    unsigned int size = 4;
    _04 += _0c(this, buf, 4, &size, 1);
}
struct NiStream
{
    char _00[0x250];
    NiBinaryStream* _250;
};
struct MyBase
{
    void FUN_00a5e880(NiStream&);
};
struct MyNode
{
    char _00[0xac];
    int _ac;
    void WriteToStream(NiStream&);
};
// Calls the base class stream writer, then writes the int at offset 0xac to the NiBinaryStream.
// @fnv 0x00a954b0
void MyNode::WriteToStream(NiStream& stream)
{
    ((MyBase*)this)->FUN_00a5e880(stream);
    stream._250->Write(&_ac);
}

struct MyOther;
struct CompareBase
{
    bool FUN_00a5e600(MyOther* other);
};
struct MyOther : CompareBase
{
    unsigned char IsEqual(MyOther* other);
};
// Calls FUN_00a5e600(other); if that succeeds, returns whether the int at offset 0xac matches between this and other.
// @fnv 0x00a952e0
unsigned char MyOther::IsEqual(MyOther* other)
{
    unsigned char result = FUN_00a5e600(other);
    if (!result)
        return result;
    return (unsigned char)(*(int*)((char*)this + 0xac) == *(int*)((char*)other + 0xac));
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct S_00a953b0_Node
{
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    S_00a953b0_Node(unsigned short) throw();
    virtual void v0();
    void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    void operator delete(void*)
    {}
    void CopyMemberData(S_00a953b0_Node* dest, void* process);
};

struct S_00a953b0_Sort : S_00a953b0_Node
{
    int m_ac;
    S_00a953b0_Sort() : S_00a953b0_Node(0)
    {
        m_ac = 0;
    }
    virtual void v0();
    S_00a953b0_Node* CreateClone(void* process);
};

// @fnv 0x00a953b0
S_00a953b0_Node* S_00a953b0_Sort::CreateClone(void* process)
{
    S_00a953b0_Sort* p = new S_00a953b0_Sort;
    CopyMemberData(p, process);
    p->m_ac = m_ac;
    return p;
}

struct S_00a95440_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00a95440_BinStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = 4;
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, &uiComponentSize, 1);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

struct S_00a95440_Stream
{
    int unk00;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned int m_uiNifVersion;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00a95440_BinStream* m_pUnderlyingStream;
    void FUN_00a645b0();
};

struct S_00a95440_Node
{
    int unk00;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    void LoadBinary(S_00a95440_Stream& kStream);
};

struct S_00a95440_SortAdjustNode : S_00a95440_Node
{
    int m_iSortAdjust;
    void FUN_00a95440(S_00a95440_Stream& kStream);
};

// @fnv 0x00a95440
void S_00a95440_SortAdjustNode::FUN_00a95440(S_00a95440_Stream& kStream)
{
    S_00a95440_Node::LoadBinary(kStream);
    int eMode;
    kStream.m_pUnderlyingStream->BinaryRead(&eMode, 4);
    m_iSortAdjust = eMode;
    if (m_iSortAdjust >= 2)
        m_iSortAdjust = 0;
    if (kStream.m_uiNifVersion < 0x14000004)
        kStream.FUN_00a645b0();
}

struct FUN_00a95350_Object
{
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
    unsigned int m_uiObjectFlags;
};

struct FUN_00a95350_List
{
    FUN_00a95350_Object** m_ppItems;
    unsigned int m_uItemCount;
};

struct FUN_00a95350_Arg
{
    int unk00;
    int unk04;
    FUN_00a95350_List* m_pEntries;
};

class FUN_00a95350_cls
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
    int m_iAc;

    void FUN_00a5dbe0(FUN_00a95350_Arg* pArg);
    void UpdateItemFlags(FUN_00a95350_Arg* pArg);
};

// Calls FUN_00a5dbe0, then sets or clears bit 0x40 in the flags of each list item added during that call, depending on whether m_iAc equals 1.
// @fnv 0x00a95350
void FUN_00a95350_cls::UpdateItemFlags(FUN_00a95350_Arg* pArg)
{
    bool hide = (m_iAc != 1);
    unsigned int start = pArg->m_pEntries->m_uItemCount;
    FUN_00a5dbe0(pArg);

    FUN_00a95350_List* pList = pArg->m_pEntries;
    unsigned int end = pList->m_uItemCount;
    unsigned int uiIndex = start;
    if (uiIndex < end)
    {
        do
        {
            FUN_00a95350_Object* pItem = pList->m_ppItems[uiIndex];
            if (!hide)
                pItem->m_uiObjectFlags |= 0x40u;
            else
                pItem->m_uiObjectFlags &= 0xffffffbfu;
            uiIndex++;
        } while (uiIndex < end);
    }
}

void __cdecl FUN_00a5dce0();
// Calls FUN_00a5dce0.
// @fnv 0x00a95290
void __cdecl FUN_00a95290()
{
    FUN_00a5dce0();
}


// src/gamebryo2.2/corelibs/niparticle/niparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiParticleSystem
{
    unsigned int m_usDirtyFlags;
    void __thiscall SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid);
};

// @fnv 0x00c1b020
void __thiscall NiParticleSystem::SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                          bool& bRigid)
{
    bSelectiveUpdate = true;
    bRigid = false;
    unsigned int& flags = *(reinterpret_cast<unsigned int*>(this) + 12);
    if (bSelectiveUpdate)
        flags |= 2;
    else
        flags &= ~2;
    flags |= 0xc;
    if (bRigid)
        flags |= 0x10;
    else
        flags &= ~0x10;
}

namespace fnv_00c1b810 {
struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiTexture;
struct NiThread;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiStream
{
    unsigned int GetLinkID(void);
    NiObject* GetLoadedObject(void);
};

struct NiPSysModifier;

struct NiParticleSystem
{
    void __thiscall FUN_00a74780(NiStream* kStream);
    void __thiscall InsertSorted(NiPSysModifier* pkModifier);
    void __thiscall LoadModifiers(NiStream* kStream);
};

// Calls FUN_00a74780, reads a modifier count from the stream, then loads that many modifiers via InsertSorted.
// @fnv 0x00c1b810
void __thiscall NiParticleSystem::LoadModifiers(NiStream* kStream)
{
    FUN_00a74780(kStream);
    unsigned int uiNumModifiers = kStream->GetLinkID();
    if (uiNumModifiers > 0)
    {
        for (unsigned int uiRemaining = uiNumModifiers; uiRemaining > 0; --uiRemaining)
            InsertSorted((NiPSysModifier*)kStream->GetLoadedObject());
    }
}
}  // namespace fnv_00c1b810

extern char const* const g_01202538_arg1;

// @fnv 0x00c1b5b0
char const* const* __cdecl FUN_00c1b5b0()
{
    return &g_01202538_arg1;
}

struct NiTPointerListBase
{
    void __thiscall RemoveAll();
};
struct S_00a80580
{
    void __thiscall FUN_00a80580();
};
void __cdecl _delete(void*, unsigned int);
struct C_00c1b9b0
{
    void* __thiscall Destroy(unsigned int);
};
// Clears the list at offset 0xC8, calls FUN_00a80580, and if f has bit 0 set, deletes this with size 0x110; returns this.
// @fnv 0x00c1b9b0
void* __thiscall C_00c1b9b0::Destroy(unsigned int auiFlags)
{
    ((NiTPointerListBase*)((char*)this + 0xC8))->RemoveAll();
    ((S_00a80580*)this)->FUN_00a80580();
    if (auiFlags & 1)
        _delete(this, 0x110);
    return this;
}

struct S_00c1b060_Obj;
struct S_00c1b060_Cloning;
struct S_00c1b060_Map
{
    bool GetAt(S_00c1b060_Obj* key, S_00c1b060_Obj*& val);
};
struct S_00c1b060_Cloning
{
    S_00c1b060_Map* m_pCloneMap;
};
struct S_00c1b060_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void ProcessClone(S_00c1b060_Cloning* k);
};
struct S_00c1b060_Item
{
    S_00c1b060_Item* m_pkNext;
    S_00c1b060_Item* m_pkPrev;
    S_00c1b060_Obj* m_element;
};
struct S_00c1b060_Base
{
    void FUN_00a80a10(S_00c1b060_Cloning* k);
};
struct S_00c1b060_Sys : S_00c1b060_Base
{
    void* vtbl;
    int unk4;
    int unk8;
    int unkC;
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
    S_00c1b060_Obj* unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    S_00c1b060_Item* unkC8;
    void FUN_00c1b060(S_00c1b060_Cloning* k);
};
// Calls the base clone handler, looks up this object in the cloning map, then calls ProcessClone on each item in the unkC8 list and on unkB8.
// @fnv 0x00c1b060
void S_00c1b060_Sys::FUN_00c1b060(S_00c1b060_Cloning* pkCloning)
{
    FUN_00a80a10(pkCloning);
    S_00c1b060_Obj* pkClone;
    pkCloning->m_pCloneMap->GetAt((S_00c1b060_Obj*)this, pkClone);
    S_00c1b060_Item* pos = unkC8;
    while (pos)
    {
        S_00c1b060_Obj*& pkElement = pos->m_element;
        pos = pos->m_pkNext;
        pkElement->ProcessClone(pkCloning);
    }
    unkB8->ProcessClone(pkCloning);
}

struct S_00c1b120_RTTI
{
    const char* m_pcName;
    const S_00c1b120_RTTI* m_pBaseRTTI;
};
extern const S_00c1b120_RTTI DAT_012027c8;
static const float DAT_01015f5c = -3.402823466e+38F;

struct S_00c1b120_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual const S_00c1b120_RTTI* GetRTTI() const;
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(bool b);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    bool IsKindOfType(const S_00c1b120_RTTI* pkRTTI) const
    {
        const S_00c1b120_RTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->m_pBaseRTTI;
        }
        return false;
    }
    S_00c1b120_Obj* DynamicCast(const S_00c1b120_RTTI* pkRTTI) const
    {
        return IsKindOfType(pkRTTI) ? (S_00c1b120_Obj*)this : 0;
    }
};

inline bool S_00c1b120_IsKindOf(const S_00c1b120_RTTI* pkRTTI, const S_00c1b120_Obj* pkObject)
{
    if (!pkObject)
        return false;
    const S_00c1b120_RTTI* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->m_pBaseRTTI;
    }
    return false;
}
inline S_00c1b120_Obj* S_00c1b120_DynamicCast(const S_00c1b120_RTTI* pkRTTI, const S_00c1b120_Obj* pkObject)
{
    return S_00c1b120_IsKindOf(pkRTTI, pkObject) ? (S_00c1b120_Obj*)pkObject : 0;
}
inline S_00c1b120_Obj* S_00c1b120_DynamicCast2(const S_00c1b120_RTTI* pkRTTI, const S_00c1b120_Obj* pkObject)
{
    return (pkObject && pkObject->IsKindOfType(pkRTTI)) ? (S_00c1b120_Obj*)pkObject : 0;
}

struct S_00c1b120_Ctlr : S_00c1b120_Obj
{
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00c1b120_Ctlr* m_spNextController;
};

struct S_00c1b120_Data : S_00c1b120_Obj
{
    int unk4;
    int unk8;
    int unkC;
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
    unsigned short unk78;
    unsigned short unk7A;
};

struct S_00c1b120_ListItem
{
    S_00c1b120_ListItem* m_pkNext;
    S_00c1b120_ListItem* m_pkPrev;
    S_00c1b120_Obj* m_element;
};

struct S_00c1b120_List
{
    void* vtbl;
    S_00c1b120_ListItem* m_pkHead;
    S_00c1b120_Obj* const& GetNext(void*& kPos) const
    {
        S_00c1b120_Obj* const& element = ((S_00c1b120_ListItem*)kPos)->m_element;
        kPos = ((S_00c1b120_ListItem*)kPos)->m_pkNext;
        return element;
    }
};

struct S_00c1b120
{
    void* vtbl;
    int unk4;
    int unk8;
    S_00c1b120_Ctlr* m_pControllers;
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
    S_00c1b120_Data* unkB8;
    int unkBC;
    int unkC0;
    S_00c1b120_List m_kList;
    int unkCC;
    int unkD0;
    float unkD4;
    void FUN_00c1b120();
};

// @fnv 0x00c1b120
void S_00c1b120::FUN_00c1b120()
{
    S_00c1b120_Data* pkData = unkB8;
    pkData->vfn_8c(false);
    pkData->unk78 = 0;
    pkData->unk7A = 0;
    unkD4 = DAT_01015f5c;

    void* kPos = m_kList.m_pkHead;
    while (kPos)
    {
        S_00c1b120_Obj* pkMod = m_kList.GetNext(kPos);
        pkMod->vfn_94();
    }

    for (S_00c1b120_Ctlr* pkCtlr = m_pControllers; pkCtlr; pkCtlr = pkCtlr->m_spNextController)
    {
        S_00c1b120_Obj* pkCast = S_00c1b120_DynamicCast(&DAT_012027c8, pkCtlr);
        if (pkCast)
            pkCast->vfn_ec();
    }
}

struct Object
{
    Object* __thiscall FUN_00c1b5c0();
};
void* __cdecl FUN_00aa13e0(unsigned int);
// @fnv 0x00c1b7f0
Object* __cdecl FUN_00c1b7f0()
{
    Object* p = (Object*)FUN_00aa13e0(0x110);
    if (p)
        return p->FUN_00c1b5c0();
    return 0;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
    BSFadeNode* __thiscall FUN_00c1b5c0();
};
struct CloneSource
{
    void __thiscall FUN_00c1b6f0(BSFadeNode*, unsigned int);
    BSFadeNode* __thiscall CreateClone(unsigned int);
};
// @fnv 0x00c1b9e0
BSFadeNode* CloneSource::CreateClone(unsigned int flags)
{
    void* memory = BSFadeNode::operator new(0x110);
    BSFadeNode* node;
    if (memory)
        node = ((BSFadeNode*)memory)->FUN_00c1b5c0();
    else
        node = 0;
    FUN_00c1b6f0(node, flags);
    return node;
}

extern "C" int DAT_011f426c;
extern "C" int DAT_011f4270;
extern "C" int DAT_011f4274;

struct Block9
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
};

extern "C" const Block9 DAT_011a9448;

struct Block13
{
    Block9 head;
    int m_i24;
    int m_i28;
    int m_i2C;
    int unk30;
};

struct FUN_00c1add0_cls
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
    Block13 m_blockA;
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
    unsigned char m_bFlag;
    unsigned char unkC5;
    unsigned char unkC6;
    unsigned char unkC7;
    unsigned char unkC8;
    unsigned char unkC9;
    unsigned char unkCA;
    unsigned char unkCB;
    unsigned char unkCC;
    unsigned char unkCD;
    unsigned char unkCE;
    unsigned char unkCF;
    unsigned char unkD0;
    unsigned char unkD1;
    unsigned char unkD2;
    unsigned char unkD3;
    unsigned char unkD4;
    unsigned char unkD5;
    unsigned char unkD6;
    unsigned char unkD7;
    unsigned char unkD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    Block13 m_blockB;

    void FUN_00a68c60(void* apValue);
    void UpdateWorldData(void* apValue);
};

// Calls FUN_00a68c60, copies m_blockA into m_blockB, and when m_bFlag is set overwrites m_blockA's tail fields and head with the DAT globals.
// @fnv 0x00c1add0
void FUN_00c1add0_cls::UpdateWorldData(void* apValue)
{
    FUN_00a68c60(apValue);
    m_blockB = m_blockA;
    if (m_bFlag != 0)
    {
        m_blockA.m_i24 = DAT_011f426c;
        m_blockA.m_i28 = DAT_011f4270;
        m_blockA.m_i2C = DAT_011f4274;
        m_blockA.head = DAT_011a9448;
    }
}

struct ListNode;
struct ListItemBase
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36(void* a, unsigned int b)
    {}
};
struct ListNode
{
    ListNode* next;
    unsigned int unk04;
    ListItemBase* m_08;
};
struct FUN_00c1aee0_cls
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
    void* m_b8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    ListNode* m_c8;
    void __thiscall FUN_00c1aee0(unsigned int arg);
};
// Walks the linked list at m_c8 and calls v36 on each node's m_08 item, passing m_b8 and arg.
// @fnv 0x00c1aee0
void FUN_00c1aee0_cls::FUN_00c1aee0(unsigned int arg)
{
    void* first = m_b8;
    ListNode* node = m_c8;
    if (node != 0)
    {
        do
        {
            ListItemBase** pp = &node->m_08;
            node = node->next;
            (*pp)->v36(first, arg);
        } while (node != 0);
    }
}

struct Vec4Obj
{
    float x;
    float y;
    float z;
    float w;
    void __thiscall FUN_00a7fdd0(Vec4Obj const* src, void* p);
};

struct S_00a80710
{
    void __thiscall FUN_00a80710();
};

class NiTransform;

class NiBound
{
  public:
    void __thiscall Update(NiBound const& src, NiTransform const& xf);
};

struct Vec3Tmp
{
    float x;
    float y;
    float z;
};

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Vec4Obj m_vec10;
};

struct FUN_00c1af60_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Vec4Obj* m_pVec20;
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
    float m_fScale98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    Holder* m_pHolder;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned char m_bC4;
    unsigned char unkC5;
    unsigned char unkC6;
    unsigned char unkC7;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned char unkD8;
    unsigned char m_bD9;
    unsigned char unkDA;
    unsigned char unkDB;
    unsigned int m_unkDC;

    void __thiscall UpdateWorldBound();
};

// @fnv 0x00c1af60
void __thiscall FUN_00c1af60_cls::UpdateWorldBound()
{
    ((S_00a80710*)this)->FUN_00a80710();
    if (m_bC4 == 0)
    {
        return;
    }
    Vec4Obj* dst = m_pVec20;
    if (m_bD9 != 0)
    {
        Vec4Obj* src = &m_pHolder->m_vec10;
        unsigned int* d = (unsigned int*)dst;
        const unsigned int* q = (const unsigned int*)src;
        unsigned int xv = q[0];
        float w0 = src->w;
        d[0] = xv;
        unsigned int yv = q[1];
        d[1] = yv;
        unsigned int zv = q[2];
        dst->w = w0;
        d[2] = zv;
        float s = m_fScale98;
        Vec4Obj* p = m_pVec20;
        Vec3Tmp t;
        t.x = p->x * s;
        t.y = p->y * s;
        t.z = p->z * s;
        float w = p->w * m_fScale98;
        *(Vec3Tmp*)p = t;
        p->w = w;
        return;
    }
    NiTransform const& xf = *(NiTransform const*)((char const*)this + 0xdc);
    ((NiBound*)dst)->Update(*(NiBound const*)&m_pHolder->m_vec10, xf);
}

namespace fnv_00c1b0f0 {
struct ListItem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
struct ListNode
{
    ListNode* m_00;
    unsigned int unk04;
    ListItem* m_08;
};

inline ListItem* const& GetNext(ListNode*& pos)
{
    ListItem* const& element = pos->m_08;
    pos = pos->m_00;
    return element;
}
struct FUN_00c1b0f0_cls
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
    ListNode* m_c8;
    void* FUN_00c1b0f0(unsigned int* key);
};

// Walks the linked list at m_c8 and returns the first item whose m_08 equals *key, or null if none matches.
// @fnv 0x00c1b0f0
void* FUN_00c1b0f0_cls::FUN_00c1b0f0(unsigned int* puiKey)
{
    ListNode* pos = m_c8;
    while (pos != 0)
    {
        ListItem* item = GetNext(pos);
        if (item != 0 && item->m_08 == *puiKey)
        {
            return item;
        }
    }
    return 0;
}
}  // namespace fnv_00c1b0f0

struct S_00c1b260_Data
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_uiItemCount;
    void FUN_00a67090(int flags);
};

struct S_00c1b260_Mod
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void update(float fTime, S_00c1b260_Data* pkData);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual bool vA0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bModifierActive;
};

struct S_00c1b260_ModNode
{
    S_00c1b260_ModNode* m_pkNext;
    int unk04;
    S_00c1b260_Mod* m_element;
};

struct S_00c1b260_Parent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* v10();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00c1b260_Parent* m_pParentNode;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiObjectFlags;
};

extern double DAT_010241b0;

struct S_00c1b260_System : NiParticleSystem
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00c1b260_Parent* m_pParentNode;
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
    S_00c1b260_Data* m_pUserData;
    int unkBC;
    int unkC0;
    int unkC4;
    S_00c1b260_ModNode* m_pkModList;
    int unkCC;
    int unkD0;
    float m_fLastTime;
    bool m_bHasAccumulation;
    void FUN_00c1b120();
    void Do_UpdateSystem(float fTime);
};

// @fnv 0x00c1b260
void S_00c1b260_System::Do_UpdateSystem(float fTime)
{
    S_00c1b260_Data* pkData = m_pUserData;
    bool bWasEmpty = false;
    if (pkData->m_uiItemCount == 0)
        bWasEmpty = true;
    pkData->vAC();
    if (m_bHasAccumulation || m_fLastTime > fTime)
    {
        FUN_00c1b120();
        m_bHasAccumulation = false;
    }
    if (m_fLastTime == DAT_010241b0)
        m_fLastTime = fTime;

    S_00c1b260_Mod* pkLast = 0;
    S_00c1b260_ModNode* pkNode = m_pkModList;
    while (pkNode)
    {
        S_00c1b260_Mod*& pkE = pkNode->m_element;
        pkNode = pkNode->m_pkNext;
        S_00c1b260_Mod* pkMod = pkE;
        if (pkMod->vA0())
            pkLast = pkMod;
        else if (pkMod->m_bModifierActive)
            pkMod->update(fTime, pkData);
    }
    if (pkLast && pkLast->m_bModifierActive)
        pkLast->update(fTime, pkData);

    pkData->FUN_00a67090(7);
    m_fLastTime = fTime;
    if (bWasEmpty && pkData->m_uiItemCount != 0)
    {
        S_00c1b260_Parent* p = m_pParentNode;
        while (p)
        {
            if (p->v10())
            {
                p->m_uiObjectFlags |= 0x400000;
                break;
            }
            p = p->m_pParentNode;
        }
    }
}

// Stand-in model for the objects touched by LoadBinary.
// The "sub" object is the per-object callback holder; the callback at +8 is
// invoked with (self, &outFlag, 1, &outCount, 1) and returns a byte count.

struct Sub_c1b3a0
{
    int unk00;
    int m_04;
    int(__cdecl* m_08)(Sub_c1b3a0* self, void* pFlag, int nOne, void* pCount, int nTwo);
};

struct Obj_c1b3a0
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
    int unkd8;
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
    Sub_c1b3a0* m_24c;
    void __thiscall FUN_00a64670();
};

struct Nps_c1b3a0
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
    unsigned char m_c4;
    void __thiscall FUN_00a9b180(Obj_c1b3a0* pObj);
    void __thiscall LoadBinary(Obj_c1b3a0* pObj);
};

// @fnv 0x00c1b3a0
void Nps_c1b3a0::LoadBinary(Obj_c1b3a0* pObj)
{
    FUN_00a9b180(pObj);
    Sub_c1b3a0* pSub = pObj->m_24c;
    bool bFlag;
    int nResult;
    {
        int nCount = 1;
        nResult = pSub->m_08(pSub, &bFlag, 1, &nCount, 1);
    }
    pSub->m_04 += nResult;
    m_c4 = (bFlag != 0);
    pObj->FUN_00a64670();
}

struct FUN_00a59fd0_shell
{
    void __thiscall UpdateDownwardPassIfSelective(void*, unsigned int);
};
struct FUN_00c1af20_upd
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    bool flag05;
    bool flag06;
};
struct FUN_00c1af20_view
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8(void* p);
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
    unsigned int flags30;
};
struct FUN_00c1af20_shell : NiParticleSystem
{
    void __thiscall UpdateParticleSystem(FUN_00c1af20_upd& a, unsigned int b);
};
// If a.flag05 is set, marks a.flag06 and returns; otherwise, when bit 2 of flags30 is set, calls the virtual at offset 0xb8, then calls UpdateDownwardPassIfSelective with a and b.
// @fnv 0x00c1af20
void __thiscall FUN_00c1af20_shell::UpdateParticleSystem(FUN_00c1af20_upd& aUpd, unsigned int b)
{
    FUN_00c1af20_view* v = reinterpret_cast<FUN_00c1af20_view*>(this);
    if (aUpd.flag05)
    {
        aUpd.flag06 = true;
        return;
    }
    unsigned int flags = v->flags30;
    bool on = ((flags >> 2) & 1) != 0;
    if (on)
    {
        void** vt = *(void***)this;
        typedef void(__thiscall * VB8)(void*, void*);
        ((VB8)vt[0xb8 / 4])(this, &aUpd);
    }
    FUN_00a59fd0_shell* s = reinterpret_cast<FUN_00a59fd0_shell*>(this);
    s->UpdateDownwardPassIfSelective(&aUpd, b);
}

// IsEqual: base comparison, matching flags, and every bound in the list equals the bound with the same id in the other list.

class B1D0Bound
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual bool IsEqual(B1D0Bound* pkOther);

    int unk04;
    int m_iID;
};

struct B1D0Node
{
    B1D0Node* m_pkNext;
    B1D0Node* m_pkPrev;
    B1D0Bound* m_pkElement;
};

inline B1D0Bound* B1D0GetNext(B1D0Node*& rpkPos)
{
    B1D0Bound*& rpkElement = rpkPos->m_pkElement;
    rpkPos = rpkPos->m_pkNext;
    return rpkElement;
}

inline B1D0Bound* FindBound(B1D0Node* pkPos, B1D0Bound* pkBound)
{
    while (pkPos)
    {
        B1D0Bound* pkCandidate = B1D0GetNext(pkPos);
        if (pkCandidate && pkCandidate->m_iID == pkBound->m_iID)
            return pkCandidate;
    }
    return 0;
}

class B1D0Base
{
  public:
    bool IsEqual(B1D0Base* pkObject);
};

class B1D0Node3D : public B1D0Base
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    unsigned char m_ucType;
    unsigned char unkC5;
    unsigned char unkC6;
    unsigned char unkC7;
    B1D0Node* m_pkBounds;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned char unkD8;
    unsigned char m_ucMode;

    bool FUN_00c1b1d0(B1D0Node3D* pkOther);
};

// Compares base data, m_ucType and m_ucMode with pkOther, then checks each bound in m_pkBounds has an equal match in pkOther's bounds.
// @fnv 0x00c1b1d0
bool B1D0Node3D::FUN_00c1b1d0(B1D0Node3D* pkOther)
{
    if (!B1D0Base::IsEqual(pkOther))
        return false;
    if (m_ucType != pkOther->m_ucType)
        return false;
    if (m_ucMode != pkOther->m_ucMode)
        return false;

    B1D0Node* pkPos = m_pkBounds;
    while (pkPos)
    {
        B1D0Bound* pkBound = B1D0GetNext(pkPos);
        B1D0Bound* pkMatch = FindBound(pkOther->m_pkBounds, pkBound);
        if (!pkBound->IsEqual(pkMatch))
            return false;
    }
    return true;
}

class C1B400BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C1B400BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C1B400BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class C1B400Object;

class NiStreamC1B
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(C1B400Object* pkObject);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    C1B400BinaryStream* m_pBackingStream;
};

template <class T>
inline void C1B400BinaryStreamSave(C1B400BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C1B400SaveBinary(NiStreamC1B& kStream, const T& value)
{
    C1B400BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

template <class T> class NiTPointerListNodeC1B
{
  public:
    NiTPointerListNodeC1B* m_pkNext;
    NiTPointerListNodeC1B* m_pkPrev;
    T m_element;
};

template <class T> inline T& NiTListGetNextC1B(NiTPointerListNodeC1B<T>*& pkPos)
{
    T& element = pkPos->m_element;
    pkPos = pkPos->m_pkNext;
    return element;
}

class BaseC1B400
{
  public:
    void SaveBinary(NiStreamC1B& kStream);
};

class FUN_00c1b400_cls : public BaseC1B400
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    bool m_bFlag;
    NiTPointerListNodeC1B<C1B400Object*>* m_pkHead;
    int unkCC;
    enum Mode
    {
        MODE_0
    } m_eValue;

    void FUN_00c1b400(NiStreamC1B& kStream);
};

// Saves the base data, the m_bFlag byte, the m_eValue enum, and the link IDs of each node in the m_pkHead list to kStream.
// @fnv 0x00c1b400
void FUN_00c1b400_cls::FUN_00c1b400(NiStreamC1B& kStream)
{
    BaseC1B400::SaveBinary(kStream);
    unsigned char ucFlag = m_bFlag;
    C1B400SaveBinary(kStream, ucFlag);
    unsigned int uiValue = m_eValue;
    C1B400SaveBinary(kStream, uiValue);
    NiTPointerListNodeC1B<C1B400Object*>* pkPos = m_pkHead;
    while (pkPos)
    {
        kStream.SaveLinkID(NiTListGetNextC1B(pkPos));
    }
}

struct FUN_00c1b850_info
{
    unsigned int unk00;
    unsigned short m_04;
    unsigned short unk06;
    unsigned short m_08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
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
    unsigned short m_50;
    unsigned short unk52;
};
struct FUN_00c1b850_list
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
};
struct C_0096ad30
{
    void __thiscall FUN_0096ad30(unsigned int n);
};
struct C_0096ae90
{
    void __thiscall FUN_0096ae90(unsigned int idx, unsigned int* p);
};

extern unsigned int g_012024e0;
unsigned int __cdecl FUN_00a7d330(unsigned int v);
unsigned int __cdecl FUN_00a7d370(const char* s, unsigned int v);
unsigned int __cdecl FUN_00a7d510(const char* s, unsigned int v);
unsigned int __cdecl FUN_00a7d490(const char* s, unsigned int v);

struct FUN_00c1b850_cls
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
    FUN_00c1b850_info* m_b8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned char m_c4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int m_d0;
    unsigned int unkD4;
    void FUN_00a9b2e0(FUN_00c1b850_list* p);
    void WriteParticleSystemInfo(FUN_00c1b850_list* a1);
};

// Appends World Space, NumMods, NumParticles and MaxParticles entries to the list via FUN_00a9b2e0 and FUN_0096ae90, growing it when full.
// @fnv 0x00c1b850
void FUN_00c1b850_cls::WriteParticleSystemInfo(FUN_00c1b850_list* pList)
{
    FUN_00a9b2e0(pList);
    unsigned int v = FUN_00a7d330(g_012024e0);
    unsigned int uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    v = FUN_00a7d370("World Space", m_c4);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiNumMods = m_d0;
    v = FUN_00a7d510("NumMods", uiNumMods);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiNumParticles = m_b8->m_50;
    v = FUN_00a7d490("NumParticles", uiNumParticles);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiMaxParticles = m_b8->m_08;
    v = FUN_00a7d490("MaxParticles", uiMaxParticles);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct Bound
{
    virtual void v00();
    virtual void DeleteThis();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c(void* owner);
    long m_lRefCount;
    unsigned int unk08;
    unsigned int m_uiKey;
};

struct NiPointer
{
    Bound* m_object;
};

struct Node
{
    Node* m_next;
    Node* m_pSecondNode;
    Bound* m_data;
};

struct PointerList
{
    Node* m_pkHead;
    Node* m_pkTail;
    unsigned int m_uiCount;
    void __thiscall FUN_00c1b4a0(NiPointer const* ptr);
    void __thiscall FUN_00c1b520(Node* node, NiPointer const* ptr);
    void __thiscall FUN_00a5a310(NiPointer const* ptr);
};

struct C_00c1b610
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
    PointerList m_kList;

    void InsertSorted(Bound* pkBound);
};

// Inserts pkBound into m_kList ordered by m_uiKey, ref-counting it around the list insert, then calls v9c(this) on it.
// @fnv 0x00c1b610
void C_00c1b610::InsertSorted(Bound* pkBound)
{
    Bound* pBound = pkBound;
    PointerList* list = &m_kList;
    NiPointer temp;
    if (list->m_pkHead == 0)
    {
        temp.m_object = pBound;
        if (pBound != 0)
            InterlockedIncrement(&pBound->m_lRefCount);
        list->FUN_00c1b4a0(&temp);
        if (pBound != 0 && InterlockedDecrement(&pBound->m_lRefCount) == 0)
            pBound->DeleteThis();
    }
    else
    {
        unsigned int key = pBound->m_uiKey;
        Node* node = list->m_pkHead;
        bool bFound = false;
        while (node != 0)
        {
            if (node->m_data->m_uiKey > key)
            {
                temp.m_object = pBound;
                InterlockedIncrement(&pBound->m_lRefCount);
                list->FUN_00c1b520(node, &temp);
                if (InterlockedDecrement(&pBound->m_lRefCount) == 0)
                    pBound->DeleteThis();
                bFound = true;
                break;
            }
            node = node->m_next;
        }
        if (!bFound)
        {
            temp.m_object = pBound;
            InterlockedIncrement(&pBound->m_lRefCount);
            list->FUN_00a5a310(&temp);
            if (InterlockedDecrement(&pBound->m_lRefCount) == 0)
                pBound->DeleteThis();
        }
    }
    pBound->v9c(this);
}

namespace fnv_00c1b520 {
struct Obj
{
    virtual void slot0();
    virtual void slot1();
    long unk04;
    void AcquireReference()
    {
        InterlockedIncrement(&unk04);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&unk04) == 0)
            slot1();
    }
};

struct Ptr
{
    Obj* m;
    Ptr& operator=(const Ptr& rhs)
    {
        if (m != rhs.m)
        {
            if (m)
                m->DecRef();
            m = rhs.m;
            if (m)
                m->AcquireReference();
        }
        return *this;
    }
};

struct Node
{
    Node* unk00;
    Node* unk04;
    Ptr unk08;
};

struct Anchor
{
    Node* unk00;
    Node* unk04;
};

struct Pool
{
    int unk00;
    Node* __thiscall FUN_0043a010();
};

struct Self
{
    Node* unk00;
    int unk04;
    Pool unk08;
    Node* __thiscall FUN_00c1b520(Anchor* anchor, Ptr& ref);
};

// @fnv 0x00c1b520
Node* __thiscall Self::FUN_00c1b520(Anchor* anchor, Ptr& ref)
{
    Node* node = unk08.FUN_0043a010();
    node->unk08 = ref;
    node->unk00 = (Node*)anchor;
    node->unk04 = anchor->unk04;
    if (anchor->unk04)
        anchor->unk04->unk00 = node;
    else
        unk00 = node;
    anchor->unk04 = node;
    ++unk08.unk00;
    return node;
}
}  // namespace fnv_00c1b520

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern bool DAT_012024d8;
extern unsigned long DAT_012024dc;
extern unsigned char* DAT_011f5b04;
extern unsigned int DAT_011ae6e0;
struct Ref_00c258e0;
struct NiPSysUpdateTask
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void Release();
};
NiPSysUpdateTask* __cdecl PopNiPSysUpdateTask();
struct Host_00c258e0
{
    void AssignRefAndValue(Ref_00c258e0*, float);
};
struct TaskManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Queue(NiPSysUpdateTask*, unsigned int);
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
    volatile bool enabled;
};
struct BoundDataBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float time;
};
struct Ref_00c258e0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void Update(float);
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
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    BoundDataBlock* data;
    void UpdateSystem(float time);
};
// When the task manager is enabled, data time is positive, and the current thread matches the stored ID, it tries to queue a task; otherwise it calls Update.
// @fnv 0x00c1ae40
void Ref_00c258e0::UpdateSystem(float time)
{
    if (DAT_012024d8 && DAT_011f5b04 && ((TaskManager*)DAT_011f5b04)->enabled && data->time > 0.0f &&
        GetCurrentThreadId() == DAT_012024dc)
    {
        NiPSysUpdateTask* task = PopNiPSysUpdateTask();
        if (task)
        {
            ((Host_00c258e0*)task)->AssignRefAndValue(this, time);
            if (((TaskManager*)DAT_011f5b04)->Queue(task, DAT_011ae6e0))
                return;
            task->Release();
        }
    }
    Update(time);
}

struct S_00c1b0b0_Stream;

struct S_00c1b0b0_Obj
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
    virtual bool v21(S_00c1b0b0_Stream* kStream);
};

struct S_00c1b0b0_Item
{
    S_00c1b0b0_Item* m_pkNext;
    S_00c1b0b0_Item* m_pkPrev;
    S_00c1b0b0_Obj* m_element;
};

struct S_00c1b0b0_Base
{
    bool FUN_00a9b190(S_00c1b0b0_Stream* kStream);
};

struct FUN_00c1b0b0_cls : S_00c1b0b0_Base
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
    int unkC4;
    S_00c1b0b0_Item* unkC8;

    bool __thiscall RegisterStreamables(S_00c1b0b0_Stream* kStream);
};

// Calls the base routine, then invokes v21 on each linked element with kStream, and returns true if the base routine succeeds.
// @fnv 0x00c1b0b0
bool __thiscall FUN_00c1b0b0_cls::RegisterStreamables(S_00c1b0b0_Stream* kStream)
{
    if (!FUN_00a9b190(kStream))
        return false;

    for (S_00c1b0b0_Item* pkPos = unkC8; pkPos;)
    {
        S_00c1b0b0_Obj*& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        element->v21(kStream);
    }

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class CloningProcess;

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerC1B
{
  public:
    NiPointerC1B(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC1B()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerC1B& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class NiObject : public NiRefObject
{
  public:
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
    virtual NiObject* MakeClone(CloningProcess& kCloning);
};

class BSMultiBound : public NiObject
{
};

template <class T> class NiTListItemC1B
{
  public:
    NiTListItemC1B* m_pkNext;
    NiTListItemC1B* m_pkPrev;
    T m_element;
};

typedef void* NiTListIterator;

template <class T> class NiTPointerAllocator
{
  public:
    unsigned int m_uiCount;
};

template <class TheAllocator, class T> class NiTPointerListBaseC1B
{
  public:
    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    const T& GetNext(NiTListIterator& kPos) const
    {
        const T& element = ((NiTListItemC1B<T>*)kPos)->m_element;
        kPos = ((NiTListItemC1B<T>*)kPos)->m_pkNext;
        return element;
    }
    __declspec(noinline) void FUN_00a5a310(const T& element) throw()
    {
        NiTListItemC1B<T>* pkNode = new NiTListItemC1B<T>;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_kItemCount.m_uiCount++;
    }
    NiTListItemC1B<T>* m_pkHead;
    NiTListItemC1B<T>* m_pkTail;
    TheAllocator m_kItemCount;
};

class NiNodeC1B : public NiObject
{
  public:
    void FUN_00a9b140(NiNodeC1B* pDest, CloningProcess& kCloning);
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
};

class BSMultiBoundNode : public NiNodeC1B
{
  public:
    void FUN_00c1b6f0(BSMultiBoundNode* pDest, CloningProcess& kCloning);
    NiPointerC1B<BSMultiBound> m_spMultiBound;
    int unkBC;
    int unkC0;
    bool m_bC4;
    NiTPointerListBaseC1B<NiTPointerAllocator<unsigned int>, NiPointerC1B<BSMultiBound> > m_kBounds;
    float m_fD4;
    bool m_bD8;
    bool m_bD9;
};

// Clones the node's bounds list and multi-bound pointer into pDest via kCloning after calling the base NiNodeC1B clone routine.
// @fnv 0x00c1b6f0
void BSMultiBoundNode::FUN_00c1b6f0(BSMultiBoundNode* pDest, CloningProcess& kCloning)
{
    NiNodeC1B::FUN_00a9b140(pDest, kCloning);

    pDest->m_bC4 = m_bC4;

    NiTListIterator kPos = m_kBounds.GetHeadPos();
    while (kPos)
    {
        BSMultiBound* pkBound = m_kBounds.GetNext(kPos);
        pDest->m_kBounds.FUN_00a5a310((BSMultiBound*)pkBound->MakeClone(kCloning));
    }

    pDest->m_fD4 = m_fD4;
    pDest->m_bD9 = m_bD9;
    pDest->m_spMultiBound = (BSMultiBound*)m_spMultiBound->MakeClone(kCloning);
}

#include <windows.h>
namespace fnv_00c1b4a0 {
struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    LONG m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiRefObjectPtr
{
    NiRefObject* m_pObject;

    NiRefObjectPtr& operator=(const NiRefObjectPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ListNode
{
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    NiRefObjectPtr m_element;
};

struct NodePoolView
{
    unsigned int m_uiCount;
    void* AddHead();
};

struct RefObjectList
{
    ListNode* m_pkHead;
    ListNode* m_pkTail;
    NodePoolView m_kItemCount;

    void FUN_00c1b4a0(const NiRefObjectPtr& element);
};

// @fnv 0x00c1b4a0
void RefObjectList::FUN_00c1b4a0(const NiRefObjectPtr& element)
{
    ListNode* pkNode = (ListNode*)m_kItemCount.AddHead();
    pkNode->m_element = element;
    pkNode->m_pkPrev = 0;
    pkNode->m_pkNext = m_pkHead;
    if (m_pkHead)
        m_pkHead->m_pkPrev = pkNode;
    else
        m_pkTail = pkNode;
    m_kItemCount.m_uiCount++;
    m_pkHead = pkNode;
}
}  // namespace fnv_00c1b4a0

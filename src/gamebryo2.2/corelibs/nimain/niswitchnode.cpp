
// src/gamebryo2.2/corelibs/nimain/niswitchnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niswitchnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_011f5f1c_arg1;

// @fnv 0x00a943f0
char const* const* __cdecl FUN_00a943f0()
{
    return &g_011f5f1c_arg1;
}

struct NiObject
{
    void* m_000;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    void* m_03c;
    void* m_040;
    void* m_044;
    void* m_048;
    void* m_04c;
    void* m_050;
    void* m_054;
    void* m_058;
    void* m_05c;
    void* m_060;
    void* m_064;
    void* m_068;
    void* m_06c;
    void* m_070;
    void* m_074;
    void* m_078;
    void* m_07c;
    void* m_080;
    void* m_084;
    void* m_088;
    void* m_08c;
    void* m_090;
    void* m_094;
    void* m_098;
    void* m_09c;
    void* m_0a0;
    void* m_0a4;
    void* m_0a8;
    char m_0ac;
    char m_0ad;
    char m_0ae;
    char m_0af;
    void* m_0b0;
};
struct NiSwitchNode : public NiObject
{
    bool __thiscall FUN_00a5e600(NiObject*);
    bool __thiscall IsEqual(NiObject*);
};
// Calls FUN_00a5e600, then returns true only if m_0b0 matches and the low bit of m_0ac matches the other object's.
// @fnv 0x00a94000
bool __thiscall NiSwitchNode::IsEqual(NiObject* other)
{
    if (!FUN_00a5e600(other) || m_0b0 != other->m_0b0 || (m_0ac ^ other->m_0ac) & 1)
        return false;
    return true;
}

extern unsigned char DAT_011f4380;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct NiObjectNET
{
    void __thiscall DeleteExtraData(unsigned short);
    bool __thiscall FUN_00a5bf50(unsigned short);
};
// Locks DAT_011f4380, deletes the extra data at index a1 if it is below the count at offset 0x14, and returns whether it was removed.
// @fnv 0x00a5bf50
bool __thiscall NiObjectNET::FUN_00a5bf50(unsigned short ausIndex)
{
    EnterCriticalSection(&DAT_011f4380);
    if (ausIndex < *(unsigned short*)((char*)this + 0x14))
    {
        DeleteExtraData(ausIndex);
        LeaveCriticalSection(&DAT_011f4380);
        return true;
    }
    LeaveCriticalSection(&DAT_011f4380);
    return false;
}

struct CloningProcess
{
};
struct NiNode_Helper
{
    void __thiscall CopyMemberData(NiSwitchNode*, CloningProcess&);
};
struct FUN_00a93c00_shell : NiSwitchNode
{
    void __thiscall FUN_00a93c00(NiSwitchNode*, CloningProcess&);
};
// @fnv 0x00a93c00
void __thiscall FUN_00a93c00_shell::FUN_00a93c00(NiSwitchNode* pkDest, CloningProcess& kCloning)
{
    ((NiNode_Helper*)this)->CopyMemberData(pkDest, kCloning);
    *(unsigned short*)((char*)pkDest + 0xac) = *(unsigned short*)((char*)this + 0xac);
    pkDest->m_0b0 = m_0b0;
}

class NiUpdateData
{
  public:
    float fTime;
};
class NiAVObject
{
  public:
    void UpdateTimeControllers(NiUpdateData&, bool);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual void UpdateControllers(NiUpdateData&);
};
struct NiNodeHack
{
    void UpdateChildControllers(NiUpdateData&);
};
struct SwitchHack : public NiObject
{
    void FUN_00a94300(NiUpdateData&);
};
// @fnv 0x00a94300
void SwitchHack::FUN_00a94300(NiUpdateData& data)
{
    if (m_0ac & 1)
    {
        if (*(int*)&m_0b0 >= 0)
        {
            ((NiAVObject*)this)->UpdateTimeControllers(data, true);
            NiAVObject* pkChild = ((NiAVObject**)m_0a0)[*(int*)&m_0b0];
            if (pkChild)
                pkChild->UpdateControllers(data);
        }
    }
    else
    {
        ((NiNodeHack*)this)->UpdateChildControllers(data);
    }
}

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
struct Unk_00a5e930
{
    void __thiscall FUN_00a5e930();
};
struct FUN_00a94400_shell
{
    void* __thiscall DestroyWithFlags(unsigned int);
};
// Sets the string at offset 0xbc, frees the pointer at 0xc0, calls FUN_00a5e930, and deletes this with size 0xcc when flags has bit 0 set.
// @fnv 0x00a94400
void* __thiscall FUN_00a94400_shell::DestroyWithFlags(unsigned int flags)
{
    void* tmp = *(void**)((char*)this + 0xc0);
    *(char const**)((char*)this + 0xbc) = " HG";
    _NiFreeAlias(tmp);
    ((Unk_00a5e930*)this)->FUN_00a5e930();
    if (flags & 1)
        _delete(this, 0xcc);
    return this;
}

namespace fnv_00a94500 {
struct CloningProcess
{
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiNode_Helper
{
    void __thiscall CopyMemberData(void*, void*);
};
struct NiSwitchNode_Helper
{
    NiSwitchNode* __thiscall FUN_00a94360();
};
struct FUN_00a94500_Holder : NiSwitchNode
{
    NiObject* __thiscall CloneSwitchNode(CloningProcess&);
};
// @fnv 0x00a94500
NiObject* __thiscall FUN_00a94500_Holder::CloneSwitchNode(CloningProcess& kCloning)
{
    NiSwitchNode* pkObject;
    void* pMemory = BSFadeNode::operator new(0xCC);
    if (pMemory)
        pkObject = ((NiSwitchNode_Helper*)pMemory)->FUN_00a94360();
    else
        pkObject = 0;
    ((NiNode_Helper*)this)->CopyMemberData(pkObject, &kCloning);
    *(unsigned short*)((char*)pkObject + 0xAC) = *(unsigned short*)((char*)this + 0xAC);
    *(void**)((char*)pkObject + 0xB0) = *(void**)((char*)this + 0xB0);
    return pkObject;
}
}  // namespace fnv_00a94500

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct NiPointer
{
    NiAVObject* m_pObject;
};
struct FUN_00a5ee30_shell
{
    void __thiscall FUN_00a5ee30(unsigned int, NiAVObject*, NiPointer&);
};
struct FUN_00a944a0_shell : public NiSwitchNode
{
    void __thiscall SetChildAtIndex(unsigned int, NiAVObject*, NiPointer&);
};
// @fnv 0x00a944a0
void FUN_00a944a0_shell::SetChildAtIndex(unsigned int uiIndex, NiAVObject* pkChild, NiPointer& spobject)
{
    StrArr* arr = (StrArr*)((char*)this + 0xbc);
    *(unsigned int*)((char*)this + 0xb8) = 1;
    char* p = 0;
    if (uiIndex >= *(unsigned short*)((char*)arr + 8))
        arr->SetSize(*(unsigned short*)((char*)arr + 0xe) + uiIndex);
    arr->SetAt(uiIndex, p);
    ((FUN_00a5ee30_shell*)this)->FUN_00a5ee30(uiIndex, pkChild, spobject);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
struct RefObj
{
    virtual void f0();
    virtual void DeleteThis();
    long refs;
};
struct RefPtr
{
    RefObj* p;
    void Assign(const RefPtr& q)
    {
        RefObj* old = p;
        if (old != q.p)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->DeleteThis();
            p = q.p;
            if (p)
                InterlockedIncrement(&p->refs);
        }
    }
    void Release()
    {
        if (p)
        {
            RefObj* old = p;
            if (!InterlockedDecrement(&old->refs))
                old->DeleteThis();
        }
    }
};
struct S2
{
    void __thiscall FUN_00a5e780(RefObj*, RefPtr&);
};
struct Target : NiObject
{
    unsigned short unkB4, unkB6;
    unsigned int unkB8;
    unsigned int unkBC;
    RefObj** arr;
    unsigned short capacity, length, count;
    void __thiscall DetachChild(RefObj*, RefPtr&);
};
// @fnv 0x00a93ca0
void Target::DetachChild(RefObj* child, RefPtr& out)
{
    unkB8 = 1;
    unsigned int uiIndex = 0;
    while (uiIndex < *((unsigned short*)&m_0a4 + 1))
    {
        if (child == ((RefObj**)m_0a0)[uiIndex])
        {
            if (uiIndex < length)
            {
                RefObj* old = arr[uiIndex];
                arr[uiIndex] = 0;
                if (old)
                    --count;
                if (uiIndex == (unsigned int)(unsigned short)(length - 1))
                    --length;
            }
            break;
        }
        ++uiIndex;
    }
    RefPtr refTemp;
    refTemp.p = 0;
    ((S2*)this)->FUN_00a5e780(child, refTemp);
    int active = (int)m_0b0;
    if (active > -1 && (active >= (int)*((unsigned short*)&m_0a4 + 1) || !((RefObj**)m_0a0)[active]))
        m_0b0 = (void*)-1;
    out.Assign(refTemp);
    refTemp.Release();
}

namespace fnv_00a93dd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

class A93DD0AVObject
{
  public:
    virtual ~A93DD0AVObject();
    virtual void DeleteThis() throw();

    unsigned int m_uiRefCount;

    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

class A93DD0AVObjectPtr
{
  public:
    A93DD0AVObjectPtr() throw() : m_pObject(0)
    {}
    ~A93DD0AVObjectPtr() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    A93DD0AVObjectPtr& operator=(const A93DD0AVObjectPtr& kPtr) throw()
    {
        if (m_pObject != kPtr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kPtr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    A93DD0AVObject* m_pObject;
};

class A93DD0BlockArray
{
  public:
    void Remove(unsigned int uiIndex) throw();
};

class A93DD0Node
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
    A93DD0AVObject** m_ppkChildren;
    unsigned short unkA4;
    unsigned short m_usChildCount;
    int unkA8;
    int unkAC;
    int m_iLastChild;
    int unkB4;
    int m_bValueAt0C;
    A93DD0BlockArray m_kBlocks;

    void DetachChildInternal(unsigned int uiIndex, A93DD0AVObjectPtr& spChild) throw();
    void RemoveChild(unsigned int uiIndex, A93DD0AVObjectPtr& pChild);
};

// @fnv 0x00a93dd0
void A93DD0Node::RemoveChild(unsigned int uiIndex, A93DD0AVObjectPtr& spChildOut)
{
    m_bValueAt0C = 1;
    if (uiIndex < m_usChildCount)
        m_kBlocks.Remove(uiIndex);

    A93DD0AVObjectPtr spChild;
    DetachChildInternal(uiIndex, spChild);

    if (m_iLastChild > -1 && (m_iLastChild >= m_usChildCount || !m_ppkChildren[m_iLastChild]))
        m_iLastChild = -1;

    spChildOut = spChild;
}
}  // namespace fnv_00a93dd0

struct SwitchChildB10050
{
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
    virtual void f41(void* out, bool flag);
    void __thiscall FUN_00a59e00(unsigned int);
};

struct SwitchHolderB10050
{
    void __thiscall FUN_0096ae90(unsigned int, void*);
};

struct SwitchOutB10050
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};

struct FUN_00a93ef0_cls : public NiSwitchNode
{
    float m_0b4;
    void* m_0b8;
    SwitchHolderB10050 m_0bc;
    void** m_0c0;
    void __thiscall UpdateSwitchChild(unsigned int arg);
};

// @fnv 0x00a93ef0
void __thiscall FUN_00a93ef0_cls::UpdateSwitchChild(unsigned int arg)
{
    int idx = (int)m_0b0;
    if (idx >= 0)
    {
        SwitchChildB10050* child = (SwitchChildB10050*)((void**)m_0a0)[idx];
        if (child != 0)
        {
            SwitchOutB10050 block;
            if (m_0c0[idx] != m_0b8)
            {
                m_0bc.FUN_0096ae90((unsigned int)idx, &m_0b8);
                block.m_00 = m_0b4;
                block.m_04 = (unsigned char)(((unsigned char)m_0ac >> 1) & 1);
                block.m_05 = 0;
                block.m_06 = 0;
                block.m_07 = 0;
                block.m_08 = 0;
                child->f41(&block, false);
            }
            child->FUN_00a59e00(arg);
        }
    }
}

struct Vec4Like
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    float w;
};

extern Vec4Like g_default_011f4288;

struct FUN_00a93f90_cls : public NiSwitchNode
{
    void UpdateFromActiveChild();
    void UpdateWorldBoundFromChildren();
};

// If the switch flag is set, copies the active child's m_020 vector into m_020 (or zeroes w when there is no child); otherwise calls UpdateWorldBoundFromChildren.
// @fnv 0x00a93f90
void FUN_00a93f90_cls::UpdateFromActiveChild()
{
    if ((m_0ac & 1) != 0)
    {
        int idx = (int)m_0b0;
        NiObject* child = 0;
        if (idx >= 0)
            child = (NiObject*)((void**)m_0a0)[idx];
        if (child != 0)
        {
            void* p = child->m_020;
            Vec4Like* src = p != 0 ? (Vec4Like*)p : &g_default_011f4288;
            Vec4Like* dst = (Vec4Like*)m_020;
            float w = src->w;
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
            dst->w = w;
            return;
        }
        ((Vec4Like*)m_020)->w = 0.0f;
        return;
    }
    UpdateWorldBoundFromChildren();
}

struct FNV_UpdateFlags
{
    float time;
    unsigned char shouldActivate;
};
struct FNV_Color4
{
    unsigned int first, second, third;
    float fourth;
};
extern FNV_Color4 DAT_011f4288;
extern "C" void __stdcall FUN_004eff50(FNV_UpdateFlags*, unsigned int);
struct FNV_SwitchVirtual : NiAVObject
{
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
    virtual void NotifyUpdated(FNV_UpdateFlags*);
};
struct FNV_ChildVirtual : NiAVObject
{
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void NotifySelected(FNV_UpdateFlags*, unsigned int);
};
struct FNV_SwitchTracker
{
    void FUN_0096ae90(int, unsigned int*);
};
struct FUN_00a94040_shell : NiSwitchNode
{
    float m_uiCommandId;
    unsigned int m_revision;
    FNV_SwitchTracker m_pTracker;
    void FUN_00a5dd70(FNV_UpdateFlags*, unsigned int);
    void UpdateSwitchState(FNV_UpdateFlags*, unsigned int);
};
// Updates the switch node's active state and time, notifies the selected child, and copies its color, or delegates to FUN_00a5dd70 when inactive.
// @fnv 0x00a94040
void FUN_00a94040_shell::UpdateSwitchState(FNV_UpdateFlags* update, unsigned int flags)
{
    unsigned short& state = *reinterpret_cast<unsigned short*>(&m_0ac);
    if (update->shouldActivate)
        state |= 2;
    else
        state &= ~2u;
    m_uiCommandId = update->time;
    if (m_0ac & 1)
    {
        ++m_revision;
        unsigned int* count = &m_revision;
        if (update->shouldActivate)
            FUN_004eff50(update, 1);
        reinterpret_cast<FNV_SwitchVirtual*>(this)->NotifyUpdated(update);
        if ((int)m_0b0 >= 0)
        {
            FNV_ChildVirtual* child = reinterpret_cast<FNV_ChildVirtual**>(m_0a0)[(int)m_0b0];
            if (child)
            {
                child->NotifySelected(update, flags);
                m_pTracker.FUN_0096ae90((int)m_0b0, count);
                NiObject* raw = reinterpret_cast<NiObject*>(child);
                FNV_Color4* color = raw->m_020 ? reinterpret_cast<FNV_Color4*>(raw->m_020) : &DAT_011f4288;
                FNV_Color4* out = reinterpret_cast<FNV_Color4*>(m_020);
                float alpha = color->fourth;
                out->first = color->first;
                out->second = color->second;
                out->third = color->third;
                out->fourth = alpha;
            }
        }
    }
    else
    {
        FUN_00a5dd70(update, flags);
    }
}

namespace fnv_00a94130 {
struct SwitchValX
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    float m_0c;
};

class SwitchChildX
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual void f42(NiUpdateData& upd, bool flag);
    virtual void f43(NiUpdateData& upd, bool flag);

    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    SwitchValX* m_20;
    unsigned int unk24, unk28, unk2c;
    unsigned int m_30;
};

struct SwitchSubX
{
    unsigned int unk00;
    void FUN_0096ae90(int idx, int* counter);
};

void __stdcall FUN_004eff50(NiUpdateData* upd, int value);
extern unsigned char DAT_011f4288;

class FUN_00a94130_cls
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual void f46(NiUpdateData& upd);

    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    SwitchValX* m_20;
    unsigned int unk24, unk28, unk2c;
    unsigned int m_30;
    unsigned int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    unsigned int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    unsigned int unk88, unk8c, unk90, unk94, unk98, unk9c;
    SwitchChildX** m_a0;
    unsigned int unkA4, unkA8;
    unsigned char m_ac, unkAD, unkAE, unkAF;
    int m_b0;
    float m_b4;
    int m_b8;
    SwitchSubX m_bc;

    void FUN_00a5ded0(NiUpdateData& upd, bool flag);
    void UpdateSelectedDownwardPass(NiUpdateData& upd, bool flag);
};

// @fnv 0x00a94130
void FUN_00a94130_cls::UpdateSelectedDownwardPass(NiUpdateData& upd, bool flag)
{
    unsigned char* pUpdBytes = (unsigned char*)&upd;
    m_b4 = upd.fTime;
    if ((m_ac & 1) != 0)
    {
        unsigned int flags = m_30;
        m_b8++;
        unsigned char ucSavedFlag = pUpdBytes[4];
        pUpdBytes[4] = (unsigned char)((flags >> 3) & 1);
        FUN_004eff50(&upd, 1);
        pUpdBytes[4] = ucSavedFlag;
        f46(upd);
        if (m_b0 < 0)
        {
            return;
        }
        SwitchChildX* child = m_a0[m_b0];
        if (child == 0)
        {
            return;
        }
        unsigned int uiChildFlags = child->m_30;
        unsigned char ucChildBit1 = (unsigned char)(uiChildFlags >> 1);
        if ((ucChildBit1 & 1) != 0)
        {
            unsigned char ucChildBit4 = (unsigned char)(uiChildFlags >> 4);
            if ((ucChildBit4 & 1) != 0)
            {
                child->f43(upd, flag);
            }
            else
            {
                child->f42(upd, flag);
            }
        }
        m_bc.FUN_0096ae90(m_b0, &m_b8);
        SwitchValX* src = child->m_20;
        if (src == 0)
        {
            src = (SwitchValX*)&DAT_011f4288;
        }
        SwitchValX* dst = m_20;
        float fValue = src->m_0c;
        dst->m_00 = src->m_00;
        dst->m_04 = src->m_04;
        unsigned int c = src->m_08;
        dst->m_08 = c;
        dst->m_0c = fValue;
    }
    else
    {
        FUN_00a5ded0(upd, flag);
    }
}
}  // namespace fnv_00a94130

void* __cdecl NiMalloc(unsigned int uiSize) throw();

class A94360Node
{
  public:
    A94360Node(unsigned int uiChildren);
    virtual ~A94360Node();

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
};

template <class T> class A94360Array
{
  public:
    A94360Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = static_cast<T*>(NiMalloc(sizeof(T) * m_usMaxSize));
        else
            m_pBase = 0;
    }
    virtual ~A94360Array();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class A94360PrimitiveArray : public A94360Array<T>
{
  public:
    A94360PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : A94360Array<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~A94360PrimitiveArray();
};

class FUN_00a94360 : public A94360Node
{
  public:
    FUN_00a94360();
    virtual ~FUN_00a94360();

    unsigned short m_usFlags;
    unsigned short unkAE;
    int m_iIndex;
    float m_fValue;
    int m_iArrayLength;
    A94360PrimitiveArray<void*> m_kChildList;
};

// @fnv 0x00a94360
FUN_00a94360::FUN_00a94360()
    : A94360Node(0), m_usFlags(0), m_iIndex(-1), m_fValue(0.0f), m_iArrayLength(1), m_kChildList(1, 1)
{
    m_usFlags |= 3;
}

struct Arr_a94440
{
    void* vtable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, void*& pvItem);
    void Add(void* pvItem)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
        {
            SetSize(uiIndex + m_usGrowBy);
        }
        SetAt(uiIndex, pvItem);
    }
};

struct Node_a94440
{
    int unk[46];
    volatile int m_b8;
    Arr_a94440 m_kArrBC;
    void FUN_00a5ed10(void* a1, int a2);
    void AttachChild(void* a1, int a2);
};

// Calls FUN_00a5ed10 with the given arguments, sets m_b8 to 1, and appends a null entry to m_kArrBC.
// @fnv 0x00a94440
void Node_a94440::AttachChild(void* a1, int a2)
{
    FUN_00a5ed10(a1, a2);
    m_b8 = 1;
    m_kArrBC.Add(0);
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct SwitchNode_a94550
{
    SwitchNode_a94550* FUN_00a94360();
};

// @fnv 0x00a94550
SwitchNode_a94550* __cdecl CreateSwitchNode()
{
    SwitchNode_a94550* p = (SwitchNode_a94550*)FUN_00aa13e0(0xcc);
    if (p)
        return p->FUN_00a94360();
    return 0;
}

class BA94570BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA94570BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BA94570Stream
{
  public:
    int unk000;
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
    unsigned int m_uiFileVersion;
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
    BA94570BinaryStream* m_pUnderlyingStream;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    unsigned short m_usLegacyFlags;
};

template <class T> inline void BA94570BinaryStreamLoad(BA94570BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA94570LoadBinary(BA94570Stream& kStream, T& value)
{
    BA94570BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class BA94570Node
{
  public:
    void LoadBinary(BA94570Stream& kStream);
};

class FUN_00a94570_Node : public BA94570Node
{
  public:
    void FUN_00a94570(BA94570Stream& kStream);

    int unk000;
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
    unsigned short m_usFlags;
    unsigned short unkAE;
    unsigned int m_uiSwitchIndex;
};

// @fnv 0x00a94570
void FUN_00a94570_Node::FUN_00a94570(BA94570Stream& kStream)
{
    BA94570Node::LoadBinary(kStream);

    if (kStream.m_uiFileVersion < 0x0A000102)
        m_usFlags = (kStream.m_usLegacyFlags >> 6) & 0x1ff;
    else
        BA94570LoadBinary(kStream, m_usFlags);

    BA94570LoadBinary(kStream, m_uiSwitchIndex);
    m_usFlags |= 2;
}

extern char* DAT_011f5eb4;
char* __cdecl FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d4d0(char const*, int);
char* __cdecl FUN_00a7d370(char const*, bool);

struct FUN_00a5ea70_Obj
{
    void FUN_00a5ea70(StrArr* pkStrings);
};

struct StrArrView
{
    int unk00;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usAllocedSize;
    unsigned short unk0c;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*& pStr);
};

__forceinline void AddString(StrArr* pkStrings, char* pStr)
{
    StrArrView* pArr = reinterpret_cast<StrArrView*>(pkStrings);
    unsigned int index = pArr->m_usAllocedSize;
    if (index >= pArr->m_usMaxSize)
        pArr->SetSize(index + pArr->m_usGrowBy);
    pArr->SetAt(index, pStr);
}

struct FUN_00a94680_shell : public NiSwitchNode
{
    void AppendDebugStrings(StrArr* pkStrings);
};

// Appends the base class strings plus the node's index and update-only-active flag to pkStrings.
// @fnv 0x00a94680
void FUN_00a94680_shell::AppendDebugStrings(StrArr* pkStrings)
{
    reinterpret_cast<FUN_00a5ea70_Obj*>(this)->FUN_00a5ea70(pkStrings);
    AddString(pkStrings, FUN_00a7d330(DAT_011f5eb4));
    AddString(pkStrings, FUN_00a7d4d0("m_iIndex", reinterpret_cast<int>(m_0b0)));
    bool bUpdateOnlyActive = m_0ac & 1;
    AddString(pkStrings, FUN_00a7d370("m_bUpdateOnlyActive", bUpdateOnlyActive));
}

// FNV_UpdateFlags, FNV_Color4, DAT_011f4288 and FUN_004eff50 are declared by the translation unit.
class SwitchAVObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void UpdateDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags);  // +0xac
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void UpdateWorldData(FNV_UpdateFlags* apData);  // +0xb8
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FNV_Color4* m_pWorldBound;  // +0x20
    int unk24;
    int unk28;
    int unk2c;
    unsigned int m_bFlag0 : 1;  // +0x30 flags
    unsigned int m_bSelectiveUpdate : 1;
    unsigned int m_bFlag2 : 1;
    unsigned int m_bUpdate : 1;
    unsigned int m_uiOtherFlags : 28;

    bool GetSelectiveUpdate() const
    {
        return m_bSelectiveUpdate;
    }
};

class SwitchNodeBase : public SwitchAVObject
{
  public:
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
    SwitchAVObject** m_ppChildren;  // +0xa0
    int unka4;
    int unka8;
    void FUN_00a5e1f0(FNV_UpdateFlags* apData, unsigned int auiFlags);
};

class SwitchRevList
{
  public:
    void FUN_0096ae90(int aiIndex, unsigned int* apuiRevID);
};

class SwitchNodeUpdate : public SwitchNodeBase
{
  public:
    unsigned int m_uiSwitchFlags;  // +0xac
    int m_iIndex;                  // +0xb0
    float m_fSwitchValue;          // +0xb4
    unsigned int m_uiRevID;        // +0xb8
    SwitchRevList m_kRevList;      // +0xbc

    void UpdateRigidDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags);
};

// @fnv 0x00a94220
void SwitchNodeUpdate::UpdateRigidDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags)
{
    m_fSwitchValue = apData->time;
    if (m_uiSwitchFlags & 1)
    {
        ++m_uiRevID;
        unsigned char bSavedActivate = apData->shouldActivate;
        apData->shouldActivate = m_bUpdate;
        FUN_004eff50(apData, 1);
        apData->shouldActivate = bSavedActivate;
        UpdateWorldData(apData);
        if (m_iIndex >= 0)
        {
            SwitchAVObject* pkChild = m_ppChildren[m_iIndex];
            if (pkChild)
            {
                if (pkChild->GetSelectiveUpdate())
                    pkChild->UpdateDownwardPass(apData, auiFlags);
                m_kRevList.FUN_0096ae90(m_iIndex, &m_uiRevID);
                const FNV_Color4* pkBound = pkChild->m_pWorldBound ? pkChild->m_pWorldBound : &DAT_011f4288;
                float fFourth = pkBound->fourth;
                FNV_Color4* pkDest = m_pWorldBound;
                pkDest->first = pkBound->first;
                pkDest->second = pkBound->second;
                pkDest->third = pkBound->third;
                pkDest->fourth = fFourth;
            }
        }
    }
    else
    {
        FUN_00a5e1f0(apData, auiFlags);
    }
}

class A946BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A946BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A946BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A946Object;

class NiStreamA946
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
    virtual void SaveLinkID(A946Object* pkObject);
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
    A946BinaryStream* m_pBackingStream;
};

template <class T> inline void A946BinaryStreamSave(A946BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A946SaveBinary(NiStreamA946& kStream, const T& value)
{
    A946BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class NiNodeA946
{
  public:
    void SaveBinary(NiStreamA946& kStream);

    void* m_ppVirtualMethodTable;
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
};

class NiSwitchNodeA946 : public NiNodeA946
{
  public:
    void FUN_00a94610(NiStreamA946& kStream);

    unsigned short m_usFlags;
    unsigned short unkAE;
    int m_iIndex;
};

// Saves the base node, then writes m_usFlags and m_iIndex to the stream.
// @fnv 0x00a94610
void NiSwitchNodeA946::FUN_00a94610(NiStreamA946& kStream)
{
    NiNodeA946::SaveBinary(kStream);
    A946SaveBinary(kStream, m_usFlags);
    A946SaveBinary(kStream, m_iIndex);
}

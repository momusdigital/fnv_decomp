
// src/gamebryo2.2/corelibs/nimain/nilodnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nilodnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" const void* g_011f5f1c;

// @fnv 0x00a994c0
const void* __cdecl FUN_00a994c0()
{
    return &g_011f5f1c;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct NiSwitchNode
{
    void __thiscall FUN_00a94360();
};

extern int DAT_010a0b64;

// Allocates a 0xd4-byte BSFadeNode, runs its constructor, installs the vtable, zeroes two fields, sets a byte flag to 1 and returns the object.
// @fnv 0x00a99710
void* __cdecl FUN_00a99710()
{
    void* p = BSFadeNode::operator new(0xd4);
    if (p)
    {
        NiSwitchNode* n = (NiSwitchNode*)p;
        n->FUN_00a94360();
        *(void**)p = &DAT_010a0b64;
        *(int*)((char*)p + 0xcc) = 0;
        *(int*)((char*)p + 0xb0) = 0;
        *(char*)((char*)p + 0xd0) = 1;
        return p;
    }
    return 0;
}

struct NiStream;
struct NiLODNode : public NiSwitchNode
{
    bool __thiscall FUN_00a93c40(NiStream*);
    NiStream* m_pBinaryStream;
    bool __thiscall RegisterStreamables(NiStream* stream);
};
// @fnv 0x00a992e0
bool __thiscall NiLODNode::RegisterStreamables(NiStream* stream)
{
    if (!FUN_00a93c40(stream))
        return false;
    NiStream* node = *(NiStream**)((char*)this + 0xcc);
    if (node)
        ((void(__thiscall*)(NiStream*, NiStream*))(*(int**)node)[21])(node, stream);
    return true;
}

namespace fnv_00a99670 {
void __cdecl operator delete(void* p, unsigned int size);
struct NiLODNode : public NiSwitchNode
{
    void __thiscall FUN_00a99470();
    NiLODNode* __thiscall FUN_00a99670(unsigned int flags);
};
// Calls FUN_00a99470, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00a99670
NiLODNode* __thiscall NiLODNode::FUN_00a99670(unsigned int flags)
{
    FUN_00a99470();
    if (flags & 1)
        operator delete(this, 0xd4);
    return this;
}
}  // namespace fnv_00a99670

class NiUpdateData;
class NiAVObject
{
  public:
    void __thiscall UpdateWorldData(class NiUpdateData&);
};
struct Helper
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void __thiscall Sel(void*);
};
struct LODNodeStandIn
{
    void __thiscall FUN_00a99110(class NiUpdateData&);
};
// Updates this object's world data, then calls Sel on the helper stored at offset 0xCC if it is non-null.
// @fnv 0x00a99110
void __thiscall LODNodeStandIn::FUN_00a99110(class NiUpdateData& UpdateData)
{
    ((NiAVObject*)this)->UpdateWorldData(UpdateData);
    Helper* p = *(Helper**)((char*)this + 0xCC);
    if (p)
        p->Sel(this);
}

struct NiStream
{
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
    virtual void f12(int);
};
struct Unk94610
{
    void __thiscall FUN_00a94610(NiStream&);
};
struct NodeStandIn
{
    void __thiscall SaveBinary(NiStream&);
};
// @fnv 0x00a99310
void NodeStandIn::SaveBinary(NiStream& kStream)
{
    ((Unk94610*)this)->FUN_00a94610(kStream);
    kStream.f12(*(int*)((char*)this + 0xCC));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
struct Obj
{
    virtual void F0();
    virtual void F1();
    long m_lRef;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRef) == 0)
            F1();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRef);
    }
};
struct Holder
{
    char _pad[0xCC];
    Obj* m_sp;
    void AssignRefCounted(Obj* p);
};
// Replaces m_sp with p, releasing the old object and incrementing the new one's reference count when they differ.
// @fnv 0x00a99340
void Holder::AssignRefCounted(Obj* apObj)
{
    Obj* old = m_sp;
    if (old != apObj)
    {
        if (old)
            old->DecRefCount();
        m_sp = apObj;
        if (apObj)
            apObj->IncRefCount();
    }
}

struct StrArr
{
    void __thiscall SetAt(unsigned int index, char*& value);
};

struct FUN_00a991d0_UpdateData
{
    float fTime;
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;
};

struct FUN_00a991d0_AVObject
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void UpdateWorldData(FUN_00a991d0_UpdateData* data, int flag);
};

struct FUN_00a991d0_shell
{
    void __thiscall UpdateChildrenWorldData();
};

// @fnv 0x00a991d0
void FUN_00a991d0_shell::UpdateChildrenWorldData()
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);

    FUN_00a991d0_UpdateData UpdateData;
    UpdateData.fTime = *reinterpret_cast<float*>(base + 0xB4);
    UpdateData.flag0 = (static_cast<unsigned char>(*(base + 0xAC)) >> 1) & 1;
    UpdateData.flag1 = false;
    UpdateData.flag2 = false;
    UpdateData.flag3 = false;
    UpdateData.flag4 = false;

    for (int iIndex = 0; iIndex < *reinterpret_cast<unsigned short*>(base + 0xA6); ++iIndex)
    {
        FUN_00a991d0_AVObject* pkChild =
            reinterpret_cast<FUN_00a991d0_AVObject**>(*reinterpret_cast<void**>(base + 0xA0))[iIndex];

        if (pkChild)
        {
            char* name = reinterpret_cast<char**>(*reinterpret_cast<void**>(base + 0xC0))[iIndex];

            char*& currentName = *reinterpret_cast<char**>(base + 0xB8);

            if (name != currentName)
            {
                reinterpret_cast<StrArr*>(base + 0xBC)->SetAt(static_cast<unsigned int>(iIndex), currentName);

                pkChild->UpdateWorldData(&UpdateData, 0);
            }
        }
    }
}

struct CloningProcess;

struct FUN_00a93c00_shell
{
    void __thiscall FUN_00a93c00(NiSwitchNode* pkDest, CloningProcess& kCloning);
};

struct Helper2
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void* __thiscall Sel();
};

struct FUN_00a99390_shell : public NiSwitchNode
{
    void __thiscall FUN_00a99390(NiSwitchNode* pkDest, CloningProcess& kCloning);
};

// @fnv 0x00a99390
void FUN_00a99390_shell::FUN_00a99390(NiSwitchNode* pkDest, CloningProcess& kCloning)
{
    ((FUN_00a93c00_shell*)this)->FUN_00a93c00(pkDest, kCloning);

    Obj* pObj = *(Obj**)((char*)this + 0xcc);
    if (pObj)
    {
        void* p = ((Helper2*)pObj)->Sel();
        ((Holder*)pkDest)->AssignRefCounted((Obj*)p);
    }
    else
    {
        Obj* pOld = *(Obj**)((char*)pkDest + 0xcc);
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_lRef) == 0)
                pOld->F1();
            *(Obj**)((char*)pkDest + 0xcc) = 0;
        }
    }
}

extern int DAT_011abdf4;

struct Dispatch99
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual int v35(unsigned int a, void* self);
    virtual void v36();
    virtual void v37();
    virtual int v38(int a);
};

struct Arg99
{
    char unk00[0xc];
    unsigned int m_iThirdValue;
};

template <class T> struct NiTArr
{
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    T GetAt(int i) const
    {
        return i < m_usSize ? m_pBase[i] : 0;
    }
};

struct FUN_00a99140_cls
{
    char unk00[0xa0];
    NiTArr<void*> m_kArray;
    char unka8[8];
    int m_iIndex;
    char unkb4[0x18];
    Dispatch99* m_pkTarget;
    bool m_bModifierActive;

    void UpdateSwitchChild(Arg99* arg);
    void UpdateTargetIndex(Arg99* arg);
};

// If enabled and a target is set, recomputes m_iIndex via v35/v38 and walks it down to a valid array slot, then calls UpdateSwitchChild.
// @fnv 0x00a99140
void FUN_00a99140_cls::UpdateTargetIndex(Arg99* arg)
{
    if (m_bModifierActive && m_pkTarget)
    {
        unsigned int c = arg->m_iThirdValue;
        m_iIndex = m_pkTarget->v35(c, this);
        int iGlobalIndex = DAT_011abdf4;
        if (iGlobalIndex >= 0)
            m_iIndex = m_pkTarget->v38(iGlobalIndex);
        if (m_iIndex >= 0)
        {
            int n = m_kArray.m_usSize;
            while (m_iIndex >= 0 && (m_iIndex >= n || m_kArray.m_pBase[m_iIndex] == 0))
                m_iIndex--;
        }
    }
    UpdateSwitchChild(arg);
}

void __cdecl NiFree(void* pvMem);

class BA99470RefObject
{
  public:
    virtual ~BA99470RefObject();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

class BA99470RefPointer
{
  public:
    ~BA99470RefPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    BA99470RefObject* m_pObject;
};

class BA99470Buffer
{
  public:
    virtual ~BA99470Buffer()
    {
        NiFree(m_pResource);
    }

    void* m_pResource;
    int unk08;
    int unk0C;
};

class BA99470Base
{
  public:
    virtual ~BA99470Base();

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
};

class FUN_00a99470_cls : public BA99470Base
{
  public:
    FUN_00a99470_cls();
    virtual ~FUN_00a99470_cls() throw();

    BA99470Buffer m_kBuffer;
    BA99470RefPointer m_pReferencedObject;
};

// Destructor for the class; the body is empty, member cleanup is handled by the compiler-generated member destructors.
// @fnv 0x00a99470
FUN_00a99470_cls::~FUN_00a99470_cls() throw()
{}

struct FUN_00a94360_Base
{
    virtual void v00();
    FUN_00a94360_Base();
};
struct CloneLODNode : FUN_00a94360_Base
{
    virtual void v01();
    CloneLODNode()
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xcc) = 0;
    }
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct FUN_00a996a0_shell : FUN_00a99390_shell
{
    CloneLODNode* CreateCloneLODNode(CloningProcess& process);
};
// @fnv 0x00a996a0
CloneLODNode* FUN_00a996a0_shell::CreateCloneLODNode(CloningProcess& process)
{
    void* memory = BSFadeNode::operator new(0xd4);
    CloneLODNode* clone = memory ? new (memory) CloneLODNode() : 0;
    if (clone)
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(clone) + 0xb0) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(clone) + 0xd0) = 1;
    }
    FUN_00a99390(reinterpret_cast<NiSwitchNode*>(clone), process);
    return clone;
}

extern "C" const void* g_011f5f1c;
extern "C" char* __cdecl FUN_00a7d330(const void* pvName);

class A99760StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class A99760Data
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void GetViewerStrings(A99760StrArray* pkStrings);
};

class A99760Node
{
  public:
    void GetViewerStringsBase(A99760StrArray* pkStrings);
    void FUN_00a99760(A99760StrArray* pkStrings);

    void* m_ppVirtualMethodTable;
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
    A99760Data* m_pkLODData;
};

// @fnv 0x00a99760
void A99760Node::FUN_00a99760(A99760StrArray* pkStrings)
{
    GetViewerStringsBase(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_011f5f1c));
    A99760Data* pkLODData = m_pkLODData;
    if (pkLODData)
    {
        pkLODData->GetViewerStrings(pkStrings);
    }
    else
    {
        pkStrings->Add("NULL LOD Data");
    }
}

struct Stream_A99270
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
    unsigned int m_version;
    Obj* FUN_00a63430();
};
void __stdcall FUN_00a9a730(Stream_A99270* stream);
struct Owner_A99270
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
    Obj* m_ref;
    void LoadRefFromStream(Stream_A99270* stream);
};
// @fnv 0x00a99270
void Owner_A99270::LoadRefFromStream(Stream_A99270* stream)
{
    FUN_00a9a730(stream);
    if (stream->m_version >= 0x0a00010cu)
    {
        Obj* replacement = stream->FUN_00a63430();
        Obj* previous = m_ref;
        if (previous != replacement)
        {
            if (previous)
                previous->DecRefCount();
            m_ref = replacement;
            if (replacement)
                replacement->IncRefCount();
        }
    }
}

struct PropObj
{
    virtual void v00();
    virtual void v01();
    virtual int v02();
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
    virtual void v21();
    virtual void v22();
    virtual bool v23(void* other);
};
struct Cls : Holder
{
    bool IsEqual(Holder* other);
    bool FUN_00a99400(Holder* other);
};
// Calls IsEqual, checks m_sp nullness, then compares v02 results and calls v23 when they match.
// @fnv 0x00a99400
bool Cls::FUN_00a99400(Holder* other)
{
    if (!IsEqual(other))
        return false;
    PropObj* pOtherProp = (PropObj*)other->m_sp;
    if ((m_sp && !pOtherProp) || (!m_sp && pOtherProp))
        return false;
    if (m_sp && pOtherProp)
    {
        PropObj* a = (PropObj*)m_sp;
        if (a->v02() == pOtherProp->v02() && !((PropObj*)m_sp)->v23(pOtherProp))
            return false;
    }
    return true;
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned);

struct LODBinStream
{
    int vtable;
    unsigned m_uiStreamFlags;
    unsigned(__cdecl* m_pfnRead)(LODBinStream*, void*, unsigned, unsigned*, unsigned);
    unsigned BinaryRead(void* pvBuffer, unsigned uiTotalBytes, unsigned* puiComponentSizes, unsigned uiNumComponents)
    {
        unsigned uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
struct LODPoint
{
    float x, y, z;
    void __thiscall FUN_00a59be0(NiStream*);
};
struct LODStreamEx : NiStream
{
    LODBinStream* GetIstr()
    {
        return *(LODBinStream**)((char*)this + 0x24c);
    }
    unsigned GetFileVersion()
    {
        return *(unsigned*)((char*)this + 0xd8);
    }
    void __thiscall FUN_00a645b0();
};
template <class T> inline unsigned LODBinaryStreamLoad(LODBinStream& binstream, T* pValue, unsigned uiNumEls)
{
    unsigned uiSize = sizeof(T);
    return binstream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void LODStreamLoadBinary(LODStreamEx* s, T& v)
{
    LODBinaryStreamLoad(*s->GetIstr(), &v, 1);
}
struct NiRangeLODData : public Obj
{
    LODPoint m_kCenter;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned m_uiRangeCount;
    struct Range
    {
        float m_fNearPlane, m_fFarPlane;
        unsigned unusedA, unusedB;
    };
    Range* m_pRanges;
    NiRangeLODData* __thiscall InitializeRangeLODData();
    void __thiscall SetRangeCount(unsigned count);
    void SetGridPosition(const LODPoint& c)
    {
        m_kCenter = c;
    }
    void SetRange(unsigned i, float fNear, float fFar)
    {
        if (i >= m_uiRangeCount)
            SetRangeCount(i + 1);
        m_pRanges[i].m_fNearPlane = fNear;
        m_pRanges[i].m_fFarPlane = fFar;
    }
};
struct LODLoader : Holder
{
    void __thiscall FUN_00a94570(NiStream*);
    void __thiscall LoadBinary(NiStream*);
    void SetLODData(NiRangeLODData* data)
    {
        if (m_sp != data)
        {
            if (m_sp)
                m_sp->DecRefCount();
            m_sp = data;
            data->IncRefCount();
        }
    }
};
// @fnv 0x00a994d0
void __thiscall LODLoader::LoadBinary(NiStream* pStream)
{
    LODStreamEx* stream = (LODStreamEx*)pStream;
    FUN_00a94570(stream);
    if (stream->GetFileVersion() <= 0xa00010b)
    {
        void* memory = FUN_00aa13e0(sizeof(NiRangeLODData));
        NiRangeLODData* data;
        if (memory)
            data = ((NiRangeLODData*)memory)->InitializeRangeLODData();
        else
            data = 0;

        LODPoint kTargetCenter;
        kTargetCenter.FUN_00a59be0(stream);
        data->SetGridPosition(kTargetCenter);

        unsigned uiNumRanges;
        LODStreamLoadBinary(stream, uiNumRanges);
        if (uiNumRanges > 0)
        {
            data->SetRangeCount(uiNumRanges);
            for (unsigned i = 0; i < uiNumRanges; i++)
            {
                float fNear, fFar;
                LODStreamLoadBinary(stream, fNear);
                LODStreamLoadBinary(stream, fFar);
                data->SetRange(i, fNear, fFar);
            }
        }
        SetLODData(data);
    }
    else
    {
        stream->FUN_00a645b0();
    }
}

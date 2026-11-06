
// src/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nimeshpsysdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    extern void* g_012027c0;
}

// @fnv 0x00c30a80
void* __cdecl FUN_00c30a80()
{
    return &g_012027c0;
}

struct NiPSysData
{
    virtual ~NiPSysData();
};
struct NiMeshPSysData : NiPSysData
{
    void __thiscall FUN_00c309d0();
    void* __thiscall FUN_00c30bd0(unsigned int);
};

void __cdecl operator delete(void* p, unsigned int size);

// Calls FUN_00c309d0, then deletes this with size 0x98 when bit 0 of flags is set, and returns this.
// @fnv 0x00c30bd0
void* __thiscall NiMeshPSysData::FUN_00c30bd0(unsigned int flags)
{
    FUN_00c309d0();
    if (flags & 1)
        operator delete(this, 0x98);
    return this;
}

struct Mesh308
{
    virtual void __thiscall a00();
    virtual void __thiscall a01();
    virtual void __thiscall a02();
    virtual void __thiscall a03();
    virtual void __thiscall a04();
    virtual void __thiscall a05();
    virtual void __thiscall a06();
    virtual void __thiscall a07();
    virtual void __thiscall a08();
    virtual void __thiscall a09();
    virtual void __thiscall a10();
    virtual void __thiscall a11();
    virtual void __thiscall a12();
    virtual void __thiscall a13();
    virtual void __thiscall a14();
    virtual void __thiscall a15();
    virtual void __thiscall a16();
    virtual void __thiscall a17();
    virtual void __thiscall a18();
    virtual void __thiscall a19();
    virtual void __thiscall a20();
    virtual void __thiscall a21();
    virtual void __thiscall a22();
    virtual void __thiscall a23();
    virtual void __thiscall a24();
    virtual void __thiscall a25();
    virtual void __thiscall a26();
    virtual void __thiscall a27();
    virtual void __thiscall a28();
    virtual void __thiscall a29();
    virtual void __thiscall a30();
    virtual void __thiscall a31();
    virtual void __thiscall a32();
    virtual void __thiscall a33();
    virtual void __thiscall a34();
    virtual void __thiscall a35();
    virtual void __thiscall a36();
    virtual void __thiscall a37();
    virtual void __thiscall a38();
    virtual void __thiscall a39();
    virtual void __thiscall a40();
    virtual void __thiscall a41();
    virtual void __thiscall a42();
    virtual void __thiscall a43();
    virtual void __thiscall a44();
    virtual void __thiscall a45();
    virtual void __thiscall a46();
    virtual void __thiscall a47();
    virtual void __thiscall a48();
    virtual void __thiscall a49();
    virtual void __thiscall a50();
    virtual void __thiscall a51();
    virtual void __thiscall a52();
    virtual void __thiscall a53();
    virtual void __thiscall a54();
    virtual void __thiscall a55();
    virtual void __thiscall a56();
    virtual void __thiscall a57();
    virtual void __thiscall a58();
    virtual void __thiscall a59();
    virtual void __thiscall T(unsigned int);
};
struct This308
{
    char _00[8];
    unsigned short m08;
    char _0A[0x46];
    unsigned short m50;
    char _52[0x2A];
    Mesh308* m7c;
    void __thiscall SetActiveVertexCount(unsigned short);
};
// Calls T on m7c for each slot from usActive up to m50, then sets m50 to the smaller of usActive and m08.
// @fnv 0x00c308d0
void __thiscall This308::SetActiveVertexCount(unsigned short usStartIndex)
{
    unsigned short us;
    for (us = usStartIndex; us < m50; us++)
    {
        m7c->T(us);
    }
    if (usStartIndex <= m08)
        m50 = usStartIndex;
    else
        m50 = m08;
}

struct NiStream;
struct NiPSysData_Helper
{
    bool __thiscall RegisterStreamables(NiStream&);
};
struct NiNodeHelper
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
    virtual void __thiscall RegisterStreamables(NiStream&);
};
struct FUN_00c30940_shell
{
    bool __thiscall FUN_00c30940(NiStream&);
};
// Registers the streamables of this object and of the NiNodeHelper stored at offset 0x7c, returning false if the first registration fails.
// @fnv 0x00c30940
bool FUN_00c30940_shell::FUN_00c30940(NiStream& kStream)
{
    if (!((NiPSysData_Helper*)this)->RegisterStreamables(kStream))
        return false;
    ((NiNodeHelper*)*(void**)((char*)this + 0x7c))->RegisterStreamables(kStream);
    return true;
}

struct NiAVObject
{
    unsigned char _0[0x30];
    unsigned int m_uiObjectFlags;
};
struct FakeNode00c30a90
{
    unsigned char _pad[0xA0];
    NiAVObject** m_pData;
};
struct S_00c30a90
{
    char _0[0x78];
    unsigned short us78;
    unsigned short us7a;
    FakeNode00c30a90* sp;
    void __thiscall ResolveAddedParticles();
};
struct BaseCall00c30a90
{
    void __thiscall ResolveAddedParticles();
};
// @fnv 0x00c30a90
void __thiscall S_00c30a90::ResolveAddedParticles()
{
    unsigned short us;
    NiAVObject* pkMesh;
    for (us = us7a; us < us7a + us78; us++)
    {
        pkMesh = sp->m_pData[us];
        if (pkMesh)
            pkMesh->m_uiObjectFlags &= ~1;
    }
    ((BaseCall00c30a90*)this)->ResolveAddedParticles();
}

struct NiObject;
struct CloningProcess;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct Hc00
{
    NiMeshPSysData* __thiscall FUN_00c30c00();
};
struct Hae0
{
    void __thiscall CloneTo(NiMeshPSysData*, CloningProcess&);
};
struct Holder_00c30c50
{
    NiObject* __thiscall CreateClone(CloningProcess&);
};
// @fnv 0x00c30c50
NiObject* __thiscall Holder_00c30c50::CreateClone(CloningProcess& kCloning)
{
    NiMeshPSysData* pkObject;
    void* pMemory = BSFadeNode::operator new(0x98);
    if (pMemory)
        pkObject = ((Hc00*)pMemory)->FUN_00c30c00();
    else
        pkObject = 0;
    ((Hae0*)this)->CloneTo(pkObject, kCloning);
    return (NiObject*)pkObject;
}

struct StrArr
{
    char _pad[8];
    unsigned short m_usAlloc;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrow;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
void __stdcall GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// @fnv 0x00c31210
void __stdcall FUN_00c31210(StrArr* pkStrings)
{
    GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_012027c0);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiAlloc = pkStrings->m_usAlloc;
    if (uiSize >= uiAlloc)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, pszStr);
}

struct CloningProcess;

struct NiObject
{
    virtual void ProcessClone(CloningProcess& kCloning);
};

struct NiNode_00c30920
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
    virtual void ProcessClone(CloningProcess& kCloning);
};

struct NiMeshPSysData_00c30920 : NiObject
{
    char _pad[0x7c - 4];
    NiNode_00c30920* m_pMeshNode;
    void __thiscall FUN_00c30920(CloningProcess& kCloning);
};

// @fnv 0x00c30920
void NiMeshPSysData_00c30920::FUN_00c30920(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    m_pMeshNode->ProcessClone(kCloning);
}

struct FUN_00c309a0_shell
{
    void* vftable;
    void* data;

    void* __thiscall Destroy(unsigned char deallocate);
};

struct MemoryManager
{
    void __thiscall _DeallocateAlias(void* p);
};

extern MemoryManager _g_memoryManager;
extern int DAT_010c07e0;

void __cdecl _NiFree(void* p);

// @fnv 0x00c309a0
void* __thiscall FUN_00c309a0_shell::Destroy(unsigned char deallocate)
{
    void* p = data;
    vftable = reinterpret_cast<void*>(&DAT_010c07e0);
    _NiFree(p);

    if (deallocate & 1)
        _g_memoryManager._DeallocateAlias(this);

    return this;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

// @fnv 0x00c30ca0
NiMeshPSysData* __cdecl CreateNiMeshPSysData()
{
    void* object = A51BF0Base::operator new(0x98);
    if (object)
        return static_cast<Hc00*>(object)->FUN_00c30c00();
    return 0;
}

struct Mesh308Compat
{
    virtual void __thiscall a00();
    virtual void __thiscall a01();
    virtual void __thiscall a02();
    virtual void __thiscall a03();
    virtual void __thiscall a04();
    virtual void __thiscall a05();
    virtual void __thiscall a06();
    virtual void __thiscall a07();
    virtual void __thiscall a08();
    virtual void __thiscall a09();
    virtual void __thiscall a10();
    virtual void __thiscall a11();
    virtual void __thiscall a12();
    virtual void __thiscall a13();
    virtual void __thiscall a14();
    virtual void __thiscall a15();
    virtual void __thiscall a16();
    virtual void __thiscall a17();
    virtual void __thiscall a18();
    virtual void __thiscall a19();
    virtual void __thiscall a20();
    virtual void __thiscall a21();
    virtual void __thiscall a22();
    virtual char __thiscall a23(Mesh308*);
};
struct DerivedThis308 : This308
{
    char __thiscall IsEqual(This308*);
    char __thiscall FUN_00c30970(This308*);
};
// @fnv 0x00c30970
char __thiscall DerivedThis308::FUN_00c30970(This308* other)
{
    if (!IsEqual(other))
        return 0;
    Mesh308Compat* thisMesh = reinterpret_cast<Mesh308Compat*>(m7c);
    Mesh308* otherMesh = other->m7c;
    return thisMesh->a23(otherMesh) != 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

struct C30AE0CloningProcess;

class C30AE0Object
{
  public:
    virtual ~C30AE0Object();
    virtual void DeleteThis();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual C30AE0Object* MakeClone(C30AE0CloningProcess& kCloning);

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

class C30AE0ObjectPtr
{
  public:
    C30AE0ObjectPtr& operator=(C30AE0Object* pObject)
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

    C30AE0Object* m_pObject;
};

class C30AE0Base
{
  public:
    void CopyMemberData(C30AE0Base* pkDest, C30AE0CloningProcess& kCloning);

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
};

class C30AE0Modifier : public C30AE0Base
{
  public:
    C30AE0ObjectPtr m_spEmitter;
    bool m_bModifierActive;

    void CloneTo(C30AE0Modifier* pkDest, C30AE0CloningProcess& kCloning);
};

// @fnv 0x00c30ae0
void C30AE0Modifier::CloneTo(C30AE0Modifier* pkDest, C30AE0CloningProcess& kCloning)
{
    C30AE0Base::CopyMemberData(pkDest, kCloning);
    pkDest->m_spEmitter = m_spEmitter.m_pObject->MakeClone(kCloning);
    pkDest->m_bModifierActive = m_bModifierActive;
}

namespace fnv_00c30b70 {
struct NiObject
{
    unsigned int m_uiRefCount;
    virtual void v0();
    virtual void v1();
};
struct NiStreamStandIn
{
    NiObject* GetLoadedObject();
};
struct NiPSysDataLinkHelper
{
    void LinkObject(NiStream&);
};
struct NiMeshPSysData308
{
    char _0[0x7c];
    NiObject* m_pMeshNode;
    void __thiscall FUN_00c30b70(NiStream& kStream);
};
// @fnv 0x00c30b70
void __thiscall NiMeshPSysData308::FUN_00c30b70(NiStream& kStream)
{
    ((NiPSysDataLinkHelper*)this)->LinkObject(kStream);
    NiObject* pkNode = ((NiStreamStandIn*)&kStream)->GetLoadedObject();
    NiObject* pkOld = m_pMeshNode;
    if (pkOld != pkNode)
    {
        if (pkOld && InterlockedDecrement((volatile long*)&pkOld->m_uiRefCount) == 0)
            pkOld->v1();
        m_pMeshNode = pkNode;
        if (pkNode)
            InterlockedIncrement((volatile long*)&pkNode->m_uiRefCount);
    }
}
}  // namespace fnv_00c30b70

struct BinaryBuffer
{
    unsigned int unk00;
    unsigned int position;
    unsigned int unk08;
    unsigned int(__cdecl* write)(BinaryBuffer*, const void*, unsigned int, unsigned int*, bool);
    void Write(const void* data, unsigned int bytes)
    {
        unsigned int actual = bytes;
        position += write(this, data, bytes, &actual, true);
    }
};
struct SaveStream
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void SaveLink(void*);
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
    BinaryBuffer* buffer;
};
struct SavedElement
{
    unsigned int unk00, unk04;
    unsigned short id;
};
struct MeshSave
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
    void* particleMeshes;
    bool active;
    unsigned int value;
    unsigned int unk88;
    SavedElement** elements;
    unsigned short capacity, count, growth, unk96;
    void FUN_00c25560(SaveStream&);
    void WriteToStream(SaveStream&);
};
// Calls FUN_00c25560, then writes value, active, count and each element's id (or zero) to the stream, and saves a link to particleMeshes.
// @fnv 0x00c30cc0
void MeshSave::WriteToStream(SaveStream& stream)
{
    FUN_00c25560(stream);
    stream.buffer->Write(&value, 4);
    {
        bool bActive = active;
        stream.buffer->Write(&bActive, 1);
    }
    {
        unsigned int size = count;
        stream.buffer->Write(&size, 4);
    }
    for (unsigned int i = 0; i < count; ++i)
    {
        if (elements[i])
        {
            unsigned int id = elements[i]->id;
            stream.buffer->Write(&id, 4);
        }
        else
        {
            unsigned int zero = 0;
            stream.buffer->Write(&zero, 4);
        }
    }
    stream.SaveLink(particleMeshes);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

struct NiRefBase
{
    virtual void v0();
    virtual void v1();
    long m_04;
};

struct SlotEntry
{
    unsigned char _00[8];
    unsigned short m_08;
    unsigned short m_0a;
    void __thiscall FUN_004afc50(NiRefBase** pp);
};

struct FUN_00c30df0_cls
{
    unsigned char _00[0x8c];
    SlotEntry** m_8c;
    unsigned short m_90;
    unsigned short m_92;

    void __thiscall ReleaseSlotRef(unsigned int idx, NiRefBase* p);
};

// @fnv 0x00c30df0
void __thiscall FUN_00c30df0_cls::ReleaseSlotRef(unsigned int uiIndex, NiRefBase* pRef)
{
    if (uiIndex >= m_92)
    {
        if (pRef != 0)
        {
            NiRefBase* ref = pRef;
            if (InterlockedDecrement(&ref->m_04) == 0)
            {
                ref->v1();
            }
        }
        return;
    }
    if (m_8c[uiIndex] != 0)
    {
        if (m_8c[uiIndex]->m_0a < m_8c[uiIndex]->m_08)
        {
            m_8c[uiIndex]->FUN_004afc50(&pRef);
        }
    }
    if (pRef != 0)
    {
        NiRefBase* ref = pRef;
        if (InterlockedDecrement(&ref->m_04) == 0)
        {
            ref->v1();
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" void __cdecl _NiFreeC30(void* pvMem) throw();

class NiRefObjectC30
{
  public:
    virtual ~NiRefObjectC30() throw();
    virtual void DeleteThis() throw();

    void DecRefCount() throw()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerC30
{
  public:
    ~NiPointerC30() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

template <class T> class NiTPrimitiveArrayC30
{
  public:
    virtual ~NiTPrimitiveArrayC30() throw()
    {
        _NiFreeC30(m_pBase);
    }

    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T RemoveEnd() throw()
    {
        if (m_usSize == 0)
            return T(0);
        m_usSize--;
        T element = m_pBase[m_usSize];
        m_pBase[m_usSize] = T(0);
        if (element != T(0))
            m_usESize--;
        return element;
    }

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class ElementC30
{
  public:
    virtual ~ElementC30() throw();
};

class BaseC30
{
  public:
    virtual ~BaseC30() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78;
};

class FUN_00c309d0 : public BaseC30
{
  public:
    virtual ~FUN_00c309d0() throw();

    NiPointerC30<NiRefObjectC30> m_pReferencedObject;
    int unk80;
    int unk84;
    NiTPrimitiveArrayC30<ElementC30*> m_kElements;
};

// Destructor that repeatedly removes the last element from m_kElements and deletes it until the array is empty.
// @fnv 0x00c309d0
FUN_00c309d0::~FUN_00c309d0() throw()
{
    while (m_kElements.GetSize() > 0)
    {
        ElementC30* pkElement = m_kElements.RemoveEnd();
        delete pkElement;
    }
}

class BC30C00ChildArray
{
  public:
    __forceinline BC30C00ChildArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~BC30C00ChildArray();

    static void** Allocate(unsigned int ItemUpdateArray) throw();

    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class BC30C00ObjectArray : public BC30C00ChildArray
{
  public:
    __forceinline BC30C00ObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : BC30C00ChildArray(uiMaxSize, uiGrowBy)
    {}
    virtual ~BC30C00ObjectArray();
};

class BC30C00Base
{
  public:
    BC30C00Base() throw();
    virtual ~BC30C00Base();

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
};

class FUN_00c30c00_cls : public BC30C00Base
{
  public:
    FUN_00c30c00_cls() throw();
    virtual ~FUN_00c30c00_cls();

    void* m_pkTarget;
    int unk80;
    int unk84;
    BC30C00ObjectArray m_kArray;
};

// Initializes the object with m_pkTarget set to null.
// @fnv 0x00c30c00
FUN_00c30c00_cls::FUN_00c30c00_cls() throw() : m_pkTarget(0)
{}

__declspec(dllimport) long __stdcall InterlockedIncrement(long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long*);

struct NiAVObjectSI
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
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

// This Gamebryo code has no unwind tables: references are released explicitly.
template <class T> class NiPointerSI
{
  public:
    NiPointerSI(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointerSI(const NiPointerSI& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    void Release()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

typedef NiPointerSI<NiAVObjectSI> NiAVObjectPtrSI;

struct NiNodeSI
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void RemoveChildAt(unsigned int uiIndex, NiAVObjectPtrSI& pChild);
    virtual void v60();
    virtual void v61();
    virtual void SetAt(unsigned int uiIndex, NiAVObjectSI* pkChild);
};

struct NiParticleInfoSI
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_usFirstValue;
    unsigned short unk1A;
};

struct NiPSysData_StandIn
{
    void FUN_00c24cc0(unsigned short usParticle);
};

struct NiMeshPSysDataSI : NiPSysData_StandIn
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
    unsigned short m_usActive;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    NiParticleInfoSI* m_pkParticleInfo;
    int unk74;
    int unk78;
    NiNodeSI* m_pMeshNode;

    void ReleaseSlotRef(unsigned int uiGeneration, NiAVObjectPtrSI spParticle);
    void RemoveParticle(unsigned short usParticle);
};

// @fnv 0x00c30e80
void NiMeshPSysDataSI::RemoveParticle(unsigned short usParticleIndex)
{
    unsigned short usLastParticle = m_usActive - 1;
    unsigned short usParticleGeneration = m_pkParticleInfo[usParticleIndex].m_usFirstValue;

    FUN_00c24cc0(usParticleIndex);

    NiAVObjectPtrSI spParticle = 0;
    if (usParticleIndex == usLastParticle)
    {
        m_pMeshNode->RemoveChildAt(usLastParticle, spParticle);
    }
    else
    {
        NiAVObjectPtrSI spFinalParticle = 0;
        m_pMeshNode->RemoveChildAt(usLastParticle, spFinalParticle);
        m_pMeshNode->RemoveChildAt(usParticleIndex, spParticle);
        m_pMeshNode->SetAt(usParticleIndex, spFinalParticle);
        spFinalParticle.Release();
    }

    ReleaseSlotRef(usParticleGeneration, spParticle);
    spParticle.Release();
}

struct NiAVObject;
template <class T> struct NiPointer
{
    T* object;
};
struct Heap436
{
    void* FUN_00aa3e40(unsigned size);
};
extern int DAT_011f6238;
template <class T> struct NiTArray436
{
    virtual ~NiTArray436();
    T* data;
    unsigned short capacity, size, valid, grow;
    NiTArray436()
    {
        capacity = 0;
        grow = 1;
        size = 0;
        valid = 0;
        data = 0;
    }
};
template <class T> struct NiTObjectArray : NiTArray436<T>
{
    virtual ~NiTObjectArray();
    static void* operator new(unsigned size) throw()
    {
        return reinterpret_cast<Heap436*>(&DAT_011f6238)->FUN_00aa3e40(size);
    }
    void FUN_0060bef0(unsigned size);
};
typedef NiTObjectArray<NiPointer<NiAVObject> > Array436;
struct OuterArray436
{
    void* typeHeader;
    Array436** data;
    unsigned short capacity, size, valid, grow;
    Array436* RemoveEnd()
    {
        if (size == 0)
            return 0;
        Array436* result = data[--size];
        data[size] = 0;
        if (result)
            --valid;
        return result;
    }
    void FUN_00a90180(unsigned size);
    void FUN_00ba3aa0(unsigned index, Array436*& value);
};
struct Owner436
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned arraySize;
    OuterArray436 children;
    void ResizeChildren(unsigned count);
};
// Grows or shrinks the children array to count, deleting removed entries and allocating new Array436 entries sized to arraySize.
// @fnv 0x00c30f90
void Owner436::ResizeChildren(unsigned count)
{
    unsigned previous = children.size;
    if (count < previous)
    {
        while (children.size > count)
            delete children.RemoveEnd();
    }
    else if (count > previous)
    {
        children.FUN_00a90180(count);
        for (unsigned i = previous; i < count; ++i)
        {
            Array436* result = new Array436;
            result->FUN_0060bef0(arraySize);
            children.FUN_00ba3aa0(i, result);
        }
    }
}

struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryReadFn)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinaryStream
{
    void* m_pVtbl;
    unsigned int m_uiStreamFlags;
    NiBinaryReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct NiStream
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
    unsigned int m_uiNifVersion;
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
    NiBinaryStream* m_pUnderlyingStream;

    void ReadLinkIDStub();
};

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &val, 1);
}

struct MemMgrStub
{
    void* Allocate(unsigned int uiSize);
};
extern MemMgrStub g_kMemMgrStub;

struct NiMemObjectStub
{
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemMgrStub.Allocate(uiSize);
    }
    static void operator delete(void* p);
};

struct PoolArrayBase : NiMemObjectStub
{
    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    PoolArrayBase(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
    }
    virtual ~PoolArrayBase();
    void SetSize(unsigned int uiSize);
};

struct PoolArray : PoolArrayBase
{
    PoolArray(unsigned int uiMaxSize, unsigned int uiGrowBy) : PoolArrayBase(uiMaxSize, uiGrowBy)
    {}
    virtual ~PoolArray();
};
struct PoolArrayArray
{
    void* m_pVtbl;
    PoolArray** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, PoolArray*& pkElement);
};

struct PSysDataBase
{
    virtual void LoadBinary(NiStream& kStream);
    int unk04;
    unsigned short m_usVertices;
};

struct NiMeshPSysDataStub : PSysDataBase
{
    void FillPools(bool bFill);
    void FUN_00c31090(NiStream& kStream);
};

struct NiMeshPSysDataLayout : NiMeshPSysDataStub
{
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
    bool m_bUseDefaultPools;
    unsigned int m_uiDefaultPoolsSize;
    PoolArrayArray m_kPoolArrays;
};

inline void S00c31090_AddPool(PoolArrayArray& kPools, unsigned int uiIndex, PoolArray* pkPool, unsigned int uiPoolSize)
{
    pkPool->SetSize(uiPoolSize);
    kPools.SetAt(uiIndex, pkPool);
}

// Loads base particle data, fills pools for older versions, and otherwise reads pool sizes and creates a pool for each nonzero size.
// @fnv 0x00c31090
void NiMeshPSysDataStub::FUN_00c31090(NiStream& kStream)
{
    NiMeshPSysDataLayout* pkThis = (NiMeshPSysDataLayout*)this;
    unsigned int uiPoolSize;
    unsigned int uiNumGenerations;

    PSysDataBase::LoadBinary(kStream);

    if (kStream.m_uiNifVersion <= 0x0a010000)
    {
        pkThis->m_uiDefaultPoolsSize = m_usVertices;
        FillPools(true);
    }
    else
    {
        bool bFillPoolsOnLoad;
        ReadBinaryValue(kStream, pkThis->m_uiDefaultPoolsSize);
        ReadBinaryValue(kStream, bFillPoolsOnLoad);
        pkThis->m_bUseDefaultPools = (bFillPoolsOnLoad != 0);
        ReadBinaryValue(kStream, uiNumGenerations);
        pkThis->m_kPoolArrays.SetSize(uiNumGenerations);
        for (unsigned int i = 0; i < uiNumGenerations; i++)
        {
            ReadBinaryValue(kStream, uiPoolSize);
            if (uiPoolSize > 0)
            {
                S00c31090_AddPool(pkThis->m_kPoolArrays, i, new PoolArray(0, 1), uiPoolSize);
            }
        }
    }

    kStream.ReadLinkIDStub();
}

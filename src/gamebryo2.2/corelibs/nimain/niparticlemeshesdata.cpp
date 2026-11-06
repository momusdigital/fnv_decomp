
// src/gamebryo2.2/corelibs/nimain/niparticlemeshesdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niparticlemeshesdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5f0c;

// @fnv 0x00a98b00
GlobalObjectO2_00a7b610* __cdecl FUN_00a98b00()
{
    return &g_011f5f0c;
}

struct NiStream
{
    void ResetStreamState();
};
struct NiParticlesData
{
    virtual void LoadBinary(NiStream&);
};
struct NiParticleMeshesData : NiParticlesData
{
    void FUN_00a98a10(NiStream&);
};
// @fnv 0x00a98a10
void NiParticleMeshesData::FUN_00a98a10(NiStream& stream)
{
    NiParticlesData::LoadBinary(stream);
    stream.ResetStreamState();
}

struct Helper00a98a30
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
    virtual void Target(unsigned int);
};
struct FUN_00a98a30_This
{
    char _0[8];
    unsigned short m8;
    char _p1[0x46];
    unsigned short m50;
    char _p2[0x1E];
    Helper00a98a30* p70;
    void SetActiveVertexCount(unsigned short);
};
// Calls Target on p70 for each index from usActive up to m50, then clamps m50 to the smaller of usActive and m8.
// @fnv 0x00a98a30
void FUN_00a98a30_This::SetActiveVertexCount(unsigned short usActive)
{
    unsigned short i;
    for (i = usActive; i < m50; ++i)
        p70->Target(i);
    if (usActive <= m8)
        m50 = usActive;
    else
        m50 = m8;
}

struct NiLinesData
{
    bool RegisterStreamables(NiStream&);
};
struct FakeNode
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
    virtual bool RegisterStreamables(NiStream&);
};
struct FUN_00a98a80_Holder : NiLinesData
{
    bool FUN_00a98a80(NiStream&);
};
// Registers the base NiLinesData streamables, then registers the streamables of the node at offset 0x70; returns false if the base call fails.
// @fnv 0x00a98a80
bool FUN_00a98a80_Holder::FUN_00a98a80(NiStream& kStream)
{
    if (!NiLinesData::RegisterStreamables(kStream))
        return 0;
    (*(FakeNode**)((char*)this + 0x70))->RegisterStreamables(kStream);
    return 1;
}

struct NiNode;
struct FUN_00a97290_holder
{
    void FUN_00a97290(NiStream&);
};
struct FakeStream
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
    virtual void f12(NiNode*);
};
struct FUN_00a98ab0_shell : NiParticleMeshesData
{
    void SaveBinary(NiStream&);
};
// @fnv 0x00a98ab0
void FUN_00a98ab0_shell::SaveBinary(NiStream& kStream)
{
    NiNode* pkNode;
    ((FUN_00a97290_holder*)this)->FUN_00a97290(kStream);
    pkNode = *(NiNode**)((char*)this + 0x70);
    ((FakeStream*)&kStream)->f12(pkNode);
}

struct MeshNode
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
    virtual unsigned char IsEqual(MeshNode*);
};
struct HookBase
{
    bool FUN_00a96a30(void*);
};
struct Holder
{
    char _pad[0x70];
    MeshNode* m_pMeshNode;
    bool IsMeshNodeEqual(void* pkObject);
};
// Checks the base hook against pkObject, then compares this holder's mesh node with the other holder's mesh node via IsEqual.
// @fnv 0x00a98ad0
bool Holder::IsMeshNodeEqual(void* pkObject)
{
    Holder* pkPart = (Holder*)pkObject;
    if (!((HookBase*)this)->FUN_00a96a30(pkObject))
        return false;
    MeshNode* mine = m_pMeshNode;
    MeshNode* other = pkPart->m_pMeshNode;
    return mine->IsEqual(other);
}

namespace fnv_00a98d60 {
struct FakeObj543
{
    virtual void Unk00();
    virtual void DeleteThis();
    volatile long m_iObjectReferenceCount;
};
struct StreamHelper543
{
    FakeObj543* GetLoadedObject();
};
struct NiLinesData
{
    void LinkObject(NiStream&);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Holder00a98d60
{
    char _pad[0x70];
    FakeObj543* m_sp;
    void FUN_00a98d60(NiStream&);
};
// Links the object to kStream, then swaps m_sp to the stream's object, releasing the old one and retaining the new one.
// @fnv 0x00a98d60
void Holder00a98d60::FUN_00a98d60(NiStream& kStream)
{
    ((NiLinesData*)this)->LinkObject(kStream);
    FakeObj543* pkNew = ((StreamHelper543*)&kStream)->GetLoadedObject();
    FakeObj543* pkOld = m_sp;
    if (pkOld != pkNew)
    {
        if (pkOld && InterlockedDecrement(&pkOld->m_iObjectReferenceCount) == 0)
            pkOld->DeleteThis();
        m_sp = pkNew;
        if (pkNew)
            InterlockedIncrement(&pkNew->m_iObjectReferenceCount);
    }
}
}  // namespace fnv_00a98d60

struct Unk98b90
{
    void FUN_00a98b90();
};
void __cdecl _delete(void*, unsigned int);
struct Unk98dc0
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a98b90 on this, frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a98dc0
void* Unk98dc0::DestroyIfFlagged(unsigned int flags)
{
    ((Unk98b90*)this)->FUN_00a98b90();
    if (flags & 1)
        _delete(this, 0x78);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class A98B10Node
{
  public:
    A98B10Node(unsigned int uiChildren) throw();

    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* pvMem) throw();

    virtual void vfn00();
    virtual void DeleteThis() throw();

    long m_uiRefCount;
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

    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class A98B10NodePtr
{
  public:
    A98B10NodePtr(A98B10Node* pObject = 0) throw() : m_pObject(pObject)
    {}
    ~A98B10NodePtr() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    A98B10NodePtr& operator=(A98B10Node* pObject) throw()
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

    A98B10Node* m_pObject;
};

class A98B10Base
{
  public:
    A98B10Base() throw();
    virtual ~A98B10Base() throw();

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
};

class FUN_00a98b10 : public A98B10Base
{
  public:
    FUN_00a98b10() throw();
    virtual ~FUN_00a98b10() throw();

    A98B10NodePtr m_spRootNode;
    bool m_bModifierActive;
};

// Initializes the object by allocating a new A98B10Node with zero children and setting the flag to false.
// @fnv 0x00a98b10
FUN_00a98b10::FUN_00a98b10() throw()
{
    m_spRootNode = new A98B10Node(0);
    m_bModifierActive = false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend) throw();

struct A98BF0Object
{
    virtual void v00();
    virtual void DeleteThis() throw();

    long m_uiRefCount;

    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct A98BF0Node
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
    virtual void RemoveChildAt(unsigned int index) throw();
    virtual void RemoveChildAt(unsigned int index, A98BF0Object*& pkChild) throw();
    virtual void v61();
    virtual void SetAt(unsigned int index, A98BF0Object* pkChild) throw();
};

struct A98BF0ParticlesData
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
    unsigned short m_usActiveVertices;

    void RemoveParticle(unsigned short usParticle);
};

struct A98BF0ParticleMeshesData : A98BF0ParticlesData
{
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    A98BF0Node* m_pMeshNode;

    void RemoveParticleMesh(unsigned short usParticle);
};

// @fnv 0x00a98bf0
void A98BF0ParticleMeshesData::RemoveParticleMesh(unsigned short usParticle)
{
    unsigned short usFinalIndex = m_usActiveVertices - 1;
    if (usParticle == usFinalIndex)
    {
        m_pMeshNode->RemoveChildAt(usFinalIndex);
    }
    else
    {
        A98BF0Object* pkFinal = 0;
        m_pMeshNode->RemoveChildAt(usFinalIndex, pkFinal);
        m_pMeshNode->RemoveChildAt(usParticle);
        m_pMeshNode->SetAt(usParticle, pkFinal);
        if (pkFinal)
            pkFinal->DecRefCount();
    }
    RemoveParticle(usParticle);
}

extern "C" double __cdecl fabs(double);

struct NiPoint3_a98
{
    float x, y, z;
};
struct NiMatrix3_a98
{
    float m[3][3];
};
struct NiQuaternion_a98
{
    float w, x, y, z;
    void ToRotation(NiMatrix3_a98& kRot) const;
};

struct Mesh_a98
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    NiMatrix3_a98 m_kRotate;
    NiPoint3_a98 m_kTranslate;
    float m_fScale;
};

struct MeshNode_a98
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
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
    Mesh_a98** m_ppChildren;
};

inline float fabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float fabs(float _X)
{
    return (fabsf(_X));
}

struct FUN_00a98c90_shell
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1C;
    NiPoint3_a98* m_pkVertex;
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
    float* m_pfRadii;
    unsigned short m_usActiveVertices;
    float* m_pfSizes;
    NiQuaternion_a98* m_pkRotations;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    MeshNode_a98* m_pkParticleMeshes;

    void UpdateParticleMeshes();
};

// @fnv 0x00a98c90
void FUN_00a98c90_shell::UpdateParticleMeshes()
{
    for (unsigned int i = 0; i < m_usActiveVertices; i++)
    {
        Mesh_a98* pkMesh = m_pkParticleMeshes->m_ppChildren[i];
        if (pkMesh)
        {
            pkMesh->m_kTranslate = m_pkVertex[i];
            if (m_pkRotations)
                m_pkRotations[i].ToRotation(pkMesh->m_kRotate);
            pkMesh->m_fScale = fabs(m_pfSizes[i] * m_pfRadii[i]);
        }
    }
}

struct NiMemObject
{
    static void* __cdecl operator new(unsigned int size);
};
inline void* __cdecl operator new(unsigned int, void* where)
{
    return where;
}
// Allocates a 0x78-byte object, constructs it, sets the bool at offset 0x40 to true, and returns it.
// @fnv 0x00a98d30
FUN_00a98b10* __cdecl FUN_00a98d30()
{
    FUN_00a98b10* pObject = new (NiMemObject::operator new(0x78)) FUN_00a98b10();
    *(bool*)&pObject->unk40 = true;
    return pObject;
}

struct FUN_0096ad30_This
{
    int unk00;
    int unk04;
    unsigned short m_pRayCursor;
    unsigned short m_uiItemCount;
    unsigned short m_unk0C;
    unsigned short m_growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void*);
};
void __stdcall FUN_00a97420(void*);
void* __cdecl FUN_00a7d330(void*);
// Calls FUN_00a97420 on p, fetches an item via FUN_00a7d330, grows the container if count reaches capacity, then stores the item at index count.
// @fnv 0x00a98de0
void __stdcall GetViewerStrings(FUN_0096ad30_This* pContainer)
{
    FUN_00a97420(pContainer);
    void* item = FUN_00a7d330(*(void**)&g_011f5f0c);
    unsigned int count = pContainer->m_uiItemCount;
    unsigned int capacity = pContainer->m_pRayCursor;
    if (count >= capacity)
        pContainer->FUN_0096ad30((unsigned int)pContainer->m_growth + count);
    pContainer->FUN_0096ae90(count, &item);
}

#include <windows.h>
struct S_00a98b90_Ref
{
    virtual ~S_00a98b90_Ref() throw();
    virtual void DeleteThis() throw();
    volatile LONG m_uiRefCount;
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct S_00a98b90_Ptr
{
    S_00a98b90_Ref* m_p;
    ~S_00a98b90_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00a98b90_Ptr& operator=(S_00a98b90_Ref* p) throw()
    {
        if (m_p != p)
        {
            if (p)
                InterlockedIncrement(&p->m_uiRefCount);
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
        }
        return *this;
    }
};
struct S_00a98b90_Base
{
    S_00a98b90_Base() throw();
    virtual ~S_00a98b90_Base() throw();
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
};
struct FUN_00a98b90 : S_00a98b90_Base
{
    S_00a98b90_Ptr unk70;
    virtual ~FUN_00a98b90() throw();
};
// @fnv 0x00a98b90
FUN_00a98b90::~FUN_00a98b90() throw()
{
    unk70 = 0;
}
